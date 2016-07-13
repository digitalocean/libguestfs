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

#include "guestfs-py.h"

/* This list should be freed (but not the strings) after use. */
static char **
get_string_list (PyObject *obj)
{
  size_t i, len;
  char **r;
#ifndef HAVE_PYSTRING_ASSTRING
  PyObject *bytes;
#endif

  assert (obj);

  if (!PyList_Check (obj)) {
    PyErr_SetString (PyExc_RuntimeError, "expecting a list parameter");
    return NULL;
  }

  Py_ssize_t slen = PyList_Size (obj);
  if (slen == -1) {
    PyErr_SetString (PyExc_RuntimeError, "get_string_list: PyList_Size failure");
    return NULL;
  }
  len = (size_t) slen;
  r = malloc (sizeof (char *) * (len+1));
  if (r == NULL) {
    PyErr_SetString (PyExc_RuntimeError, "get_string_list: out of memory");
    return NULL;
  }

  for (i = 0; i < len; ++i) {
#ifdef HAVE_PYSTRING_ASSTRING
    r[i] = PyString_AsString (PyList_GetItem (obj, i));
#else
    bytes = PyUnicode_AsUTF8String (PyList_GetItem (obj, i));
    r[i] = PyBytes_AS_STRING (bytes);
#endif
  }
  r[len] = NULL;

  return r;
}

static PyObject *
put_string_list (char * const * const argv)
{
  PyObject *list;
  size_t argc, i;

  for (argc = 0; argv[argc] != NULL; ++argc)
    ;

  list = PyList_New (argc);
  for (i = 0; i < argc; ++i) {
#ifdef HAVE_PYSTRING_ASSTRING
    PyList_SetItem (list, i, PyString_FromString (argv[i]));
#else
    PyList_SetItem (list, i, PyUnicode_FromString (argv[i]));
#endif
  }

  return list;
}

static PyObject *
put_table (char * const * const argv)
{
  PyObject *list, *item;
  size_t argc, i;

  for (argc = 0; argv[argc] != NULL; ++argc)
    ;

  list = PyList_New (argc >> 1);
  for (i = 0; i < argc; i += 2) {
    item = PyTuple_New (2);
#ifdef HAVE_PYSTRING_ASSTRING
    PyTuple_SetItem (item, 0, PyString_FromString (argv[i]));
    PyTuple_SetItem (item, 1, PyString_FromString (argv[i+1]));
#else
    PyTuple_SetItem (item, 0, PyUnicode_FromString (argv[i]));
    PyTuple_SetItem (item, 1, PyUnicode_FromString (argv[i+1]));
#endif
    PyList_SetItem (list, i >> 1, item);
  }

  return list;
}

#ifdef GUESTFS_HAVE_STRUCT_APPLICATION
static PyObject *
put_application (struct guestfs_application *application)
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
static PyObject *
put_application2 (struct guestfs_application2 *application2)
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
static PyObject *
put_btrfsbalance (struct guestfs_btrfsbalance *btrfsbalance)
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
static PyObject *
put_btrfsqgroup (struct guestfs_btrfsqgroup *btrfsqgroup)
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
static PyObject *
put_btrfsscrub (struct guestfs_btrfsscrub *btrfsscrub)
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
static PyObject *
put_btrfssubvolume (struct guestfs_btrfssubvolume *btrfssubvolume)
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
static PyObject *
put_dirent (struct guestfs_dirent *dirent)
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
static PyObject *
put_hivex_node (struct guestfs_hivex_node *hivex_node)
{
  PyObject *dict;

  dict = PyDict_New ();
  PyDict_SetItemString (dict, "hivex_node_h",
                        PyLong_FromLongLong (hivex_node->hivex_node_h));
  return dict;
};
#endif

#ifdef GUESTFS_HAVE_STRUCT_HIVEX_VALUE
static PyObject *
put_hivex_value (struct guestfs_hivex_value *hivex_value)
{
  PyObject *dict;

  dict = PyDict_New ();
  PyDict_SetItemString (dict, "hivex_value_h",
                        PyLong_FromLongLong (hivex_value->hivex_value_h));
  return dict;
};
#endif

#ifdef GUESTFS_HAVE_STRUCT_INOTIFY_EVENT
static PyObject *
put_inotify_event (struct guestfs_inotify_event *inotify_event)
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
static PyObject *
put_int_bool (struct guestfs_int_bool *int_bool)
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
static PyObject *
put_isoinfo (struct guestfs_isoinfo *isoinfo)
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
static PyObject *
put_lvm_lv (struct guestfs_lvm_lv *lvm_lv)
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
static PyObject *
put_lvm_pv (struct guestfs_lvm_pv *lvm_pv)
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
static PyObject *
put_lvm_vg (struct guestfs_lvm_vg *lvm_vg)
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
static PyObject *
put_mdstat (struct guestfs_mdstat *mdstat)
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
static PyObject *
put_partition (struct guestfs_partition *partition)
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
static PyObject *
put_stat (struct guestfs_stat *stat)
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
static PyObject *
put_statns (struct guestfs_statns *statns)
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
static PyObject *
put_statvfs (struct guestfs_statvfs *statvfs)
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

#ifdef GUESTFS_HAVE_STRUCT_UTSNAME
static PyObject *
put_utsname (struct guestfs_utsname *utsname)
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
static PyObject *
put_version (struct guestfs_version *version)
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
static PyObject *
put_xattr (struct guestfs_xattr *xattr)
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
static PyObject *
put_xfsinfo (struct guestfs_xfsinfo *xfsinfo)
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
static PyObject *
put_lvm_lv_list (struct guestfs_lvm_lv_list *lvm_lvs)
{
  PyObject *list;
  size_t i;

  list = PyList_New (lvm_lvs->len);
  for (i = 0; i < lvm_lvs->len; ++i)
    PyList_SetItem (list, i, put_lvm_lv (&lvm_lvs->val[i]));
  return list;
};
#endif

#ifdef GUESTFS_HAVE_STRUCT_DIRENT
static PyObject *
put_dirent_list (struct guestfs_dirent_list *dirents)
{
  PyObject *list;
  size_t i;

  list = PyList_New (dirents->len);
  for (i = 0; i < dirents->len; ++i)
    PyList_SetItem (list, i, put_dirent (&dirents->val[i]));
  return list;
};
#endif

#ifdef GUESTFS_HAVE_STRUCT_BTRFSQGROUP
static PyObject *
put_btrfsqgroup_list (struct guestfs_btrfsqgroup_list *btrfsqgroups)
{
  PyObject *list;
  size_t i;

  list = PyList_New (btrfsqgroups->len);
  for (i = 0; i < btrfsqgroups->len; ++i)
    PyList_SetItem (list, i, put_btrfsqgroup (&btrfsqgroups->val[i]));
  return list;
};
#endif

#ifdef GUESTFS_HAVE_STRUCT_PARTITION
static PyObject *
put_partition_list (struct guestfs_partition_list *partitions)
{
  PyObject *list;
  size_t i;

  list = PyList_New (partitions->len);
  for (i = 0; i < partitions->len; ++i)
    PyList_SetItem (list, i, put_partition (&partitions->val[i]));
  return list;
};
#endif

#ifdef GUESTFS_HAVE_STRUCT_STATNS
static PyObject *
put_statns_list (struct guestfs_statns_list *statnss)
{
  PyObject *list;
  size_t i;

  list = PyList_New (statnss->len);
  for (i = 0; i < statnss->len; ++i)
    PyList_SetItem (list, i, put_statns (&statnss->val[i]));
  return list;
};
#endif

#ifdef GUESTFS_HAVE_STRUCT_APPLICATION2
static PyObject *
put_application2_list (struct guestfs_application2_list *application2s)
{
  PyObject *list;
  size_t i;

  list = PyList_New (application2s->len);
  for (i = 0; i < application2s->len; ++i)
    PyList_SetItem (list, i, put_application2 (&application2s->val[i]));
  return list;
};
#endif

#ifdef GUESTFS_HAVE_STRUCT_INOTIFY_EVENT
static PyObject *
put_inotify_event_list (struct guestfs_inotify_event_list *inotify_events)
{
  PyObject *list;
  size_t i;

  list = PyList_New (inotify_events->len);
  for (i = 0; i < inotify_events->len; ++i)
    PyList_SetItem (list, i, put_inotify_event (&inotify_events->val[i]));
  return list;
};
#endif

#ifdef GUESTFS_HAVE_STRUCT_APPLICATION
static PyObject *
put_application_list (struct guestfs_application_list *applications)
{
  PyObject *list;
  size_t i;

  list = PyList_New (applications->len);
  for (i = 0; i < applications->len; ++i)
    PyList_SetItem (list, i, put_application (&applications->val[i]));
  return list;
};
#endif

#ifdef GUESTFS_HAVE_STRUCT_HIVEX_VALUE
static PyObject *
put_hivex_value_list (struct guestfs_hivex_value_list *hivex_values)
{
  PyObject *list;
  size_t i;

  list = PyList_New (hivex_values->len);
  for (i = 0; i < hivex_values->len; ++i)
    PyList_SetItem (list, i, put_hivex_value (&hivex_values->val[i]));
  return list;
};
#endif

#ifdef GUESTFS_HAVE_STRUCT_XATTR
static PyObject *
put_xattr_list (struct guestfs_xattr_list *xattrs)
{
  PyObject *list;
  size_t i;

  list = PyList_New (xattrs->len);
  for (i = 0; i < xattrs->len; ++i)
    PyList_SetItem (list, i, put_xattr (&xattrs->val[i]));
  return list;
};
#endif

#ifdef GUESTFS_HAVE_STRUCT_LVM_PV
static PyObject *
put_lvm_pv_list (struct guestfs_lvm_pv_list *lvm_pvs)
{
  PyObject *list;
  size_t i;

  list = PyList_New (lvm_pvs->len);
  for (i = 0; i < lvm_pvs->len; ++i)
    PyList_SetItem (list, i, put_lvm_pv (&lvm_pvs->val[i]));
  return list;
};
#endif

#ifdef GUESTFS_HAVE_STRUCT_LVM_VG
static PyObject *
put_lvm_vg_list (struct guestfs_lvm_vg_list *lvm_vgs)
{
  PyObject *list;
  size_t i;

  list = PyList_New (lvm_vgs->len);
  for (i = 0; i < lvm_vgs->len; ++i)
    PyList_SetItem (list, i, put_lvm_vg (&lvm_vgs->val[i]));
  return list;
};
#endif

#ifdef GUESTFS_HAVE_STRUCT_BTRFSSUBVOLUME
static PyObject *
put_btrfssubvolume_list (struct guestfs_btrfssubvolume_list *btrfssubvolumes)
{
  PyObject *list;
  size_t i;

  list = PyList_New (btrfssubvolumes->len);
  for (i = 0; i < btrfssubvolumes->len; ++i)
    PyList_SetItem (list, i, put_btrfssubvolume (&btrfssubvolumes->val[i]));
  return list;
};
#endif

#ifdef GUESTFS_HAVE_STRUCT_MDSTAT
static PyObject *
put_mdstat_list (struct guestfs_mdstat_list *mdstats)
{
  PyObject *list;
  size_t i;

  list = PyList_New (mdstats->len);
  for (i = 0; i < mdstats->len; ++i)
    PyList_SetItem (list, i, put_mdstat (&mdstats->val[i]));
  return list;
};
#endif

#ifdef GUESTFS_HAVE_STRUCT_HIVEX_NODE
static PyObject *
put_hivex_node_list (struct guestfs_hivex_node_list *hivex_nodes)
{
  PyObject *list;
  size_t i;

  list = PyList_New (hivex_nodes->len);
  for (i = 0; i < hivex_nodes->len; ++i)
    PyList_SetItem (list, i, put_hivex_node (&hivex_nodes->val[i]));
  return list;
};
#endif

#ifdef GUESTFS_HAVE_STRUCT_STAT
static PyObject *
put_stat_list (struct guestfs_stat_list *stats)
{
  PyObject *list;
  size_t i;

  list = PyList_New (stats->len);
  for (i = 0; i < stats->len; ++i)
    PyList_SetItem (list, i, put_stat (&stats->val[i]));
  return list;
};
#endif

#ifdef GUESTFS_HAVE_ACL_DELETE_DEF_FILE
static PyObject *
guestfs_int_py_acl_delete_def_file (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  const char *dir;

  if (!PyArg_ParseTuple (args, (char *) "Os:guestfs_acl_delete_def_file",
                         &py_g, &dir))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_acl_delete_def_file (g, dir);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_ACL_GET_FILE
static PyObject *
guestfs_int_py_acl_get_file (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  char *r;
  const char *path;
  const char *acltype;

  if (!PyArg_ParseTuple (args, (char *) "Oss:guestfs_acl_get_file",
                         &py_g, &path, &acltype))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_acl_get_file (g, path, acltype);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == NULL) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

#ifdef HAVE_PYSTRING_ASSTRING
  py_r = PyString_FromString (r);
#else
  py_r = PyUnicode_FromString (r);
#endif
  free (r);
  if (py_r == NULL) goto out;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_ACL_SET_FILE
static PyObject *
guestfs_int_py_acl_set_file (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  const char *path;
  const char *acltype;
  const char *acl;

  if (!PyArg_ParseTuple (args, (char *) "Osss:guestfs_acl_set_file",
                         &py_g, &path, &acltype, &acl))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_acl_set_file (g, path, acltype, acl);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_ADD_CDROM
static PyObject *
guestfs_int_py_add_cdrom (PyObject *self, PyObject *args)
{
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  const char *filename;

  if (!PyArg_ParseTuple (args, (char *) "Os:guestfs_add_cdrom",
                         &py_g, &filename))
    goto out;
  g = get_handle (py_g);

  r = guestfs_add_cdrom (g, filename);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_ADD_DOMAIN
static PyObject *
guestfs_int_py_add_domain (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  struct guestfs_add_domain_argv optargs_s;
  struct guestfs_add_domain_argv *optargs = &optargs_s;
  int r;
  const char *dom;
  PyObject *py_libvirturi;
  PyObject *py_readonly;
  PyObject *py_iface;
  PyObject *py_live;
  PyObject *py_allowuuid;
  PyObject *py_readonlydisk;
  PyObject *py_cachemode;
  PyObject *py_discard;
  PyObject *py_copyonread;

  optargs_s.bitmask = 0;

  if (!PyArg_ParseTuple (args, (char *) "OsOOOOOOOOO:guestfs_add_domain",
                         &py_g, &dom, &py_libvirturi, &py_readonly, &py_iface, &py_live, &py_allowuuid, &py_readonlydisk, &py_cachemode, &py_discard, &py_copyonread))
    goto out;
  g = get_handle (py_g);

#ifdef GUESTFS_ADD_DOMAIN_LIBVIRTURI_BITMASK
  if (py_libvirturi != Py_None) {
    optargs_s.bitmask |= GUESTFS_ADD_DOMAIN_LIBVIRTURI_BITMASK;
#ifdef HAVE_PYSTRING_ASSTRING
    optargs_s.libvirturi = PyString_AsString (py_libvirturi);
#else
    PyObject *bytes;
    bytes = PyUnicode_AsUTF8String (py_libvirturi);
    optargs_s.libvirturi = PyBytes_AS_STRING (bytes);
#endif
  }
#endif
#ifdef GUESTFS_ADD_DOMAIN_READONLY_BITMASK
  if (py_readonly != Py_None) {
    optargs_s.bitmask |= GUESTFS_ADD_DOMAIN_READONLY_BITMASK;
    optargs_s.readonly = PyLong_AsLong (py_readonly);
    if (PyErr_Occurred ()) goto out;
  }
#endif
#ifdef GUESTFS_ADD_DOMAIN_IFACE_BITMASK
  if (py_iface != Py_None) {
    optargs_s.bitmask |= GUESTFS_ADD_DOMAIN_IFACE_BITMASK;
#ifdef HAVE_PYSTRING_ASSTRING
    optargs_s.iface = PyString_AsString (py_iface);
#else
    PyObject *bytes;
    bytes = PyUnicode_AsUTF8String (py_iface);
    optargs_s.iface = PyBytes_AS_STRING (bytes);
#endif
  }
#endif
#ifdef GUESTFS_ADD_DOMAIN_LIVE_BITMASK
  if (py_live != Py_None) {
    optargs_s.bitmask |= GUESTFS_ADD_DOMAIN_LIVE_BITMASK;
    optargs_s.live = PyLong_AsLong (py_live);
    if (PyErr_Occurred ()) goto out;
  }
#endif
#ifdef GUESTFS_ADD_DOMAIN_ALLOWUUID_BITMASK
  if (py_allowuuid != Py_None) {
    optargs_s.bitmask |= GUESTFS_ADD_DOMAIN_ALLOWUUID_BITMASK;
    optargs_s.allowuuid = PyLong_AsLong (py_allowuuid);
    if (PyErr_Occurred ()) goto out;
  }
#endif
#ifdef GUESTFS_ADD_DOMAIN_READONLYDISK_BITMASK
  if (py_readonlydisk != Py_None) {
    optargs_s.bitmask |= GUESTFS_ADD_DOMAIN_READONLYDISK_BITMASK;
#ifdef HAVE_PYSTRING_ASSTRING
    optargs_s.readonlydisk = PyString_AsString (py_readonlydisk);
#else
    PyObject *bytes;
    bytes = PyUnicode_AsUTF8String (py_readonlydisk);
    optargs_s.readonlydisk = PyBytes_AS_STRING (bytes);
#endif
  }
#endif
#ifdef GUESTFS_ADD_DOMAIN_CACHEMODE_BITMASK
  if (py_cachemode != Py_None) {
    optargs_s.bitmask |= GUESTFS_ADD_DOMAIN_CACHEMODE_BITMASK;
#ifdef HAVE_PYSTRING_ASSTRING
    optargs_s.cachemode = PyString_AsString (py_cachemode);
#else
    PyObject *bytes;
    bytes = PyUnicode_AsUTF8String (py_cachemode);
    optargs_s.cachemode = PyBytes_AS_STRING (bytes);
#endif
  }
#endif
#ifdef GUESTFS_ADD_DOMAIN_DISCARD_BITMASK
  if (py_discard != Py_None) {
    optargs_s.bitmask |= GUESTFS_ADD_DOMAIN_DISCARD_BITMASK;
#ifdef HAVE_PYSTRING_ASSTRING
    optargs_s.discard = PyString_AsString (py_discard);
#else
    PyObject *bytes;
    bytes = PyUnicode_AsUTF8String (py_discard);
    optargs_s.discard = PyBytes_AS_STRING (bytes);
#endif
  }
#endif
#ifdef GUESTFS_ADD_DOMAIN_COPYONREAD_BITMASK
  if (py_copyonread != Py_None) {
    optargs_s.bitmask |= GUESTFS_ADD_DOMAIN_COPYONREAD_BITMASK;
    optargs_s.copyonread = PyLong_AsLong (py_copyonread);
    if (PyErr_Occurred ()) goto out;
  }
#endif

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_add_domain_argv (g, dom, optargs);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  py_r = PyLong_FromLong ((long) r);

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_ADD_DRIVE_OPTS
static PyObject *
guestfs_int_py_add_drive (PyObject *self, PyObject *args)
{
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  struct guestfs_add_drive_opts_argv optargs_s;
  struct guestfs_add_drive_opts_argv *optargs = &optargs_s;
  int r;
  const char *filename;
  PyObject *py_readonly;
  PyObject *py_format;
  PyObject *py_iface;
  PyObject *py_name;
  PyObject *py_label;
  PyObject *py_protocol;
  PyObject *py_server;
  PyObject *py_username;
  PyObject *py_secret;
  PyObject *py_cachemode;
  PyObject *py_discard;
  PyObject *py_copyonread;

  optargs_s.bitmask = 0;

  if (!PyArg_ParseTuple (args, (char *) "OsOOOOOOOOOOOO:guestfs_add_drive",
                         &py_g, &filename, &py_readonly, &py_format, &py_iface, &py_name, &py_label, &py_protocol, &py_server, &py_username, &py_secret, &py_cachemode, &py_discard, &py_copyonread))
    goto out;
  g = get_handle (py_g);

#ifdef GUESTFS_ADD_DRIVE_OPTS_READONLY_BITMASK
  if (py_readonly != Py_None) {
    optargs_s.bitmask |= GUESTFS_ADD_DRIVE_OPTS_READONLY_BITMASK;
    optargs_s.readonly = PyLong_AsLong (py_readonly);
    if (PyErr_Occurred ()) goto out;
  }
#endif
#ifdef GUESTFS_ADD_DRIVE_OPTS_FORMAT_BITMASK
  if (py_format != Py_None) {
    optargs_s.bitmask |= GUESTFS_ADD_DRIVE_OPTS_FORMAT_BITMASK;
#ifdef HAVE_PYSTRING_ASSTRING
    optargs_s.format = PyString_AsString (py_format);
#else
    PyObject *bytes;
    bytes = PyUnicode_AsUTF8String (py_format);
    optargs_s.format = PyBytes_AS_STRING (bytes);
#endif
  }
#endif
#ifdef GUESTFS_ADD_DRIVE_OPTS_IFACE_BITMASK
  if (py_iface != Py_None) {
    optargs_s.bitmask |= GUESTFS_ADD_DRIVE_OPTS_IFACE_BITMASK;
#ifdef HAVE_PYSTRING_ASSTRING
    optargs_s.iface = PyString_AsString (py_iface);
#else
    PyObject *bytes;
    bytes = PyUnicode_AsUTF8String (py_iface);
    optargs_s.iface = PyBytes_AS_STRING (bytes);
#endif
  }
#endif
#ifdef GUESTFS_ADD_DRIVE_OPTS_NAME_BITMASK
  if (py_name != Py_None) {
    optargs_s.bitmask |= GUESTFS_ADD_DRIVE_OPTS_NAME_BITMASK;
#ifdef HAVE_PYSTRING_ASSTRING
    optargs_s.name = PyString_AsString (py_name);
#else
    PyObject *bytes;
    bytes = PyUnicode_AsUTF8String (py_name);
    optargs_s.name = PyBytes_AS_STRING (bytes);
#endif
  }
#endif
#ifdef GUESTFS_ADD_DRIVE_OPTS_LABEL_BITMASK
  if (py_label != Py_None) {
    optargs_s.bitmask |= GUESTFS_ADD_DRIVE_OPTS_LABEL_BITMASK;
#ifdef HAVE_PYSTRING_ASSTRING
    optargs_s.label = PyString_AsString (py_label);
#else
    PyObject *bytes;
    bytes = PyUnicode_AsUTF8String (py_label);
    optargs_s.label = PyBytes_AS_STRING (bytes);
#endif
  }
#endif
#ifdef GUESTFS_ADD_DRIVE_OPTS_PROTOCOL_BITMASK
  if (py_protocol != Py_None) {
    optargs_s.bitmask |= GUESTFS_ADD_DRIVE_OPTS_PROTOCOL_BITMASK;
#ifdef HAVE_PYSTRING_ASSTRING
    optargs_s.protocol = PyString_AsString (py_protocol);
#else
    PyObject *bytes;
    bytes = PyUnicode_AsUTF8String (py_protocol);
    optargs_s.protocol = PyBytes_AS_STRING (bytes);
#endif
  }
#endif
#ifdef GUESTFS_ADD_DRIVE_OPTS_SERVER_BITMASK
  if (py_server != Py_None) {
    optargs_s.bitmask |= GUESTFS_ADD_DRIVE_OPTS_SERVER_BITMASK;
    optargs_s.server = get_string_list (py_server);
    if (!optargs_s.server) goto out;
  }
#endif
#ifdef GUESTFS_ADD_DRIVE_OPTS_USERNAME_BITMASK
  if (py_username != Py_None) {
    optargs_s.bitmask |= GUESTFS_ADD_DRIVE_OPTS_USERNAME_BITMASK;
#ifdef HAVE_PYSTRING_ASSTRING
    optargs_s.username = PyString_AsString (py_username);
#else
    PyObject *bytes;
    bytes = PyUnicode_AsUTF8String (py_username);
    optargs_s.username = PyBytes_AS_STRING (bytes);
#endif
  }
#endif
#ifdef GUESTFS_ADD_DRIVE_OPTS_SECRET_BITMASK
  if (py_secret != Py_None) {
    optargs_s.bitmask |= GUESTFS_ADD_DRIVE_OPTS_SECRET_BITMASK;
#ifdef HAVE_PYSTRING_ASSTRING
    optargs_s.secret = PyString_AsString (py_secret);
#else
    PyObject *bytes;
    bytes = PyUnicode_AsUTF8String (py_secret);
    optargs_s.secret = PyBytes_AS_STRING (bytes);
#endif
  }
#endif
#ifdef GUESTFS_ADD_DRIVE_OPTS_CACHEMODE_BITMASK
  if (py_cachemode != Py_None) {
    optargs_s.bitmask |= GUESTFS_ADD_DRIVE_OPTS_CACHEMODE_BITMASK;
#ifdef HAVE_PYSTRING_ASSTRING
    optargs_s.cachemode = PyString_AsString (py_cachemode);
#else
    PyObject *bytes;
    bytes = PyUnicode_AsUTF8String (py_cachemode);
    optargs_s.cachemode = PyBytes_AS_STRING (bytes);
#endif
  }
#endif
#ifdef GUESTFS_ADD_DRIVE_OPTS_DISCARD_BITMASK
  if (py_discard != Py_None) {
    optargs_s.bitmask |= GUESTFS_ADD_DRIVE_OPTS_DISCARD_BITMASK;
#ifdef HAVE_PYSTRING_ASSTRING
    optargs_s.discard = PyString_AsString (py_discard);
#else
    PyObject *bytes;
    bytes = PyUnicode_AsUTF8String (py_discard);
    optargs_s.discard = PyBytes_AS_STRING (bytes);
#endif
  }
#endif
#ifdef GUESTFS_ADD_DRIVE_OPTS_COPYONREAD_BITMASK
  if (py_copyonread != Py_None) {
    optargs_s.bitmask |= GUESTFS_ADD_DRIVE_OPTS_COPYONREAD_BITMASK;
    optargs_s.copyonread = PyLong_AsLong (py_copyonread);
    if (PyErr_Occurred ()) goto out;
  }
#endif

  r = guestfs_add_drive_opts_argv (g, filename, optargs);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
#ifdef GUESTFS_ADD_DRIVE_OPTS_SERVER_BITMASK
  if (py_server != Py_None && (optargs_s.bitmask & GUESTFS_ADD_DRIVE_OPTS_SERVER_BITMASK) != 0)
    free ((char **) optargs_s.server);
#endif
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_ADD_DRIVE_RO
static PyObject *
guestfs_int_py_add_drive_ro (PyObject *self, PyObject *args)
{
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  const char *filename;

  if (!PyArg_ParseTuple (args, (char *) "Os:guestfs_add_drive_ro",
                         &py_g, &filename))
    goto out;
  g = get_handle (py_g);

  r = guestfs_add_drive_ro (g, filename);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_ADD_DRIVE_RO_WITH_IF
static PyObject *
guestfs_int_py_add_drive_ro_with_if (PyObject *self, PyObject *args)
{
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  const char *filename;
  const char *iface;

  if (!PyArg_ParseTuple (args, (char *) "Oss:guestfs_add_drive_ro_with_if",
                         &py_g, &filename, &iface))
    goto out;
  g = get_handle (py_g);

  r = guestfs_add_drive_ro_with_if (g, filename, iface);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_ADD_DRIVE_SCRATCH
static PyObject *
guestfs_int_py_add_drive_scratch (PyObject *self, PyObject *args)
{
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  struct guestfs_add_drive_scratch_argv optargs_s;
  struct guestfs_add_drive_scratch_argv *optargs = &optargs_s;
  int r;
  long long size;
  PyObject *py_name;
  PyObject *py_label;

  optargs_s.bitmask = 0;

  if (!PyArg_ParseTuple (args, (char *) "OLOO:guestfs_add_drive_scratch",
                         &py_g, &size, &py_name, &py_label))
    goto out;
  g = get_handle (py_g);

#ifdef GUESTFS_ADD_DRIVE_SCRATCH_NAME_BITMASK
  if (py_name != Py_None) {
    optargs_s.bitmask |= GUESTFS_ADD_DRIVE_SCRATCH_NAME_BITMASK;
#ifdef HAVE_PYSTRING_ASSTRING
    optargs_s.name = PyString_AsString (py_name);
#else
    PyObject *bytes;
    bytes = PyUnicode_AsUTF8String (py_name);
    optargs_s.name = PyBytes_AS_STRING (bytes);
#endif
  }
#endif
#ifdef GUESTFS_ADD_DRIVE_SCRATCH_LABEL_BITMASK
  if (py_label != Py_None) {
    optargs_s.bitmask |= GUESTFS_ADD_DRIVE_SCRATCH_LABEL_BITMASK;
#ifdef HAVE_PYSTRING_ASSTRING
    optargs_s.label = PyString_AsString (py_label);
#else
    PyObject *bytes;
    bytes = PyUnicode_AsUTF8String (py_label);
    optargs_s.label = PyBytes_AS_STRING (bytes);
#endif
  }
#endif

  r = guestfs_add_drive_scratch_argv (g, size, optargs);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_ADD_DRIVE_WITH_IF
static PyObject *
guestfs_int_py_add_drive_with_if (PyObject *self, PyObject *args)
{
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  const char *filename;
  const char *iface;

  if (!PyArg_ParseTuple (args, (char *) "Oss:guestfs_add_drive_with_if",
                         &py_g, &filename, &iface))
    goto out;
  g = get_handle (py_g);

  r = guestfs_add_drive_with_if (g, filename, iface);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_ADD_LIBVIRT_DOM
static PyObject *
guestfs_int_py_add_libvirt_dom (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  struct guestfs_add_libvirt_dom_argv optargs_s;
  struct guestfs_add_libvirt_dom_argv *optargs = &optargs_s;
  int r;
  void * /* virDomainPtr */ dom;
  PyObject *dom_long;
  PyObject *py_readonly;
  PyObject *py_iface;
  PyObject *py_live;
  PyObject *py_readonlydisk;
  PyObject *py_cachemode;
  PyObject *py_discard;
  PyObject *py_copyonread;

  optargs_s.bitmask = 0;

  if (!PyArg_ParseTuple (args, (char *) "OOOOOOOOO:guestfs_add_libvirt_dom",
                         &py_g, &dom_long, &py_readonly, &py_iface, &py_live, &py_readonlydisk, &py_cachemode, &py_discard, &py_copyonread))
    goto out;
  g = get_handle (py_g);
  dom = PyLong_AsVoidPtr (dom_long);

#ifdef GUESTFS_ADD_LIBVIRT_DOM_READONLY_BITMASK
  if (py_readonly != Py_None) {
    optargs_s.bitmask |= GUESTFS_ADD_LIBVIRT_DOM_READONLY_BITMASK;
    optargs_s.readonly = PyLong_AsLong (py_readonly);
    if (PyErr_Occurred ()) goto out;
  }
#endif
#ifdef GUESTFS_ADD_LIBVIRT_DOM_IFACE_BITMASK
  if (py_iface != Py_None) {
    optargs_s.bitmask |= GUESTFS_ADD_LIBVIRT_DOM_IFACE_BITMASK;
#ifdef HAVE_PYSTRING_ASSTRING
    optargs_s.iface = PyString_AsString (py_iface);
#else
    PyObject *bytes;
    bytes = PyUnicode_AsUTF8String (py_iface);
    optargs_s.iface = PyBytes_AS_STRING (bytes);
#endif
  }
#endif
#ifdef GUESTFS_ADD_LIBVIRT_DOM_LIVE_BITMASK
  if (py_live != Py_None) {
    optargs_s.bitmask |= GUESTFS_ADD_LIBVIRT_DOM_LIVE_BITMASK;
    optargs_s.live = PyLong_AsLong (py_live);
    if (PyErr_Occurred ()) goto out;
  }
#endif
#ifdef GUESTFS_ADD_LIBVIRT_DOM_READONLYDISK_BITMASK
  if (py_readonlydisk != Py_None) {
    optargs_s.bitmask |= GUESTFS_ADD_LIBVIRT_DOM_READONLYDISK_BITMASK;
#ifdef HAVE_PYSTRING_ASSTRING
    optargs_s.readonlydisk = PyString_AsString (py_readonlydisk);
#else
    PyObject *bytes;
    bytes = PyUnicode_AsUTF8String (py_readonlydisk);
    optargs_s.readonlydisk = PyBytes_AS_STRING (bytes);
#endif
  }
#endif
#ifdef GUESTFS_ADD_LIBVIRT_DOM_CACHEMODE_BITMASK
  if (py_cachemode != Py_None) {
    optargs_s.bitmask |= GUESTFS_ADD_LIBVIRT_DOM_CACHEMODE_BITMASK;
#ifdef HAVE_PYSTRING_ASSTRING
    optargs_s.cachemode = PyString_AsString (py_cachemode);
#else
    PyObject *bytes;
    bytes = PyUnicode_AsUTF8String (py_cachemode);
    optargs_s.cachemode = PyBytes_AS_STRING (bytes);
#endif
  }
#endif
#ifdef GUESTFS_ADD_LIBVIRT_DOM_DISCARD_BITMASK
  if (py_discard != Py_None) {
    optargs_s.bitmask |= GUESTFS_ADD_LIBVIRT_DOM_DISCARD_BITMASK;
#ifdef HAVE_PYSTRING_ASSTRING
    optargs_s.discard = PyString_AsString (py_discard);
#else
    PyObject *bytes;
    bytes = PyUnicode_AsUTF8String (py_discard);
    optargs_s.discard = PyBytes_AS_STRING (bytes);
#endif
  }
#endif
#ifdef GUESTFS_ADD_LIBVIRT_DOM_COPYONREAD_BITMASK
  if (py_copyonread != Py_None) {
    optargs_s.bitmask |= GUESTFS_ADD_LIBVIRT_DOM_COPYONREAD_BITMASK;
    optargs_s.copyonread = PyLong_AsLong (py_copyonread);
    if (PyErr_Occurred ()) goto out;
  }
#endif

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_add_libvirt_dom_argv (g, dom, optargs);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  py_r = PyLong_FromLong ((long) r);

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_AUG_CLEAR
static PyObject *
guestfs_int_py_aug_clear (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  const char *augpath;

  if (!PyArg_ParseTuple (args, (char *) "Os:guestfs_aug_clear",
                         &py_g, &augpath))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_aug_clear (g, augpath);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_AUG_CLOSE
static PyObject *
guestfs_int_py_aug_close (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;

  if (!PyArg_ParseTuple (args, (char *) "O:guestfs_aug_close",
                         &py_g))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_aug_close (g);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_AUG_DEFNODE
static PyObject *
guestfs_int_py_aug_defnode (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  struct guestfs_int_bool *r;
  const char *name;
  const char *expr;
  const char *val;

  if (!PyArg_ParseTuple (args, (char *) "Osss:guestfs_aug_defnode",
                         &py_g, &name, &expr, &val))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_aug_defnode (g, name, expr, val);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == NULL) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  py_r = put_int_bool (r);
  guestfs_free_int_bool (r);

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_AUG_DEFVAR
static PyObject *
guestfs_int_py_aug_defvar (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  const char *name;
  const char *expr;

  if (!PyArg_ParseTuple (args, (char *) "Osz:guestfs_aug_defvar",
                         &py_g, &name, &expr))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_aug_defvar (g, name, expr);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  py_r = PyLong_FromLong ((long) r);

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_AUG_GET
static PyObject *
guestfs_int_py_aug_get (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  char *r;
  const char *augpath;

  if (!PyArg_ParseTuple (args, (char *) "Os:guestfs_aug_get",
                         &py_g, &augpath))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_aug_get (g, augpath);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == NULL) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

#ifdef HAVE_PYSTRING_ASSTRING
  py_r = PyString_FromString (r);
#else
  py_r = PyUnicode_FromString (r);
#endif
  free (r);
  if (py_r == NULL) goto out;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_AUG_INIT
static PyObject *
guestfs_int_py_aug_init (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  const char *root;
  int flags;

  if (!PyArg_ParseTuple (args, (char *) "Osi:guestfs_aug_init",
                         &py_g, &root, &flags))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_aug_init (g, root, flags);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_AUG_INSERT
static PyObject *
guestfs_int_py_aug_insert (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  const char *augpath;
  const char *label;
  int before;

  if (!PyArg_ParseTuple (args, (char *) "Ossi:guestfs_aug_insert",
                         &py_g, &augpath, &label, &before))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_aug_insert (g, augpath, label, before);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_AUG_LABEL
static PyObject *
guestfs_int_py_aug_label (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  char *r;
  const char *augpath;

  if (!PyArg_ParseTuple (args, (char *) "Os:guestfs_aug_label",
                         &py_g, &augpath))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_aug_label (g, augpath);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == NULL) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

#ifdef HAVE_PYSTRING_ASSTRING
  py_r = PyString_FromString (r);
#else
  py_r = PyUnicode_FromString (r);
#endif
  free (r);
  if (py_r == NULL) goto out;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_AUG_LOAD
static PyObject *
guestfs_int_py_aug_load (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;

  if (!PyArg_ParseTuple (args, (char *) "O:guestfs_aug_load",
                         &py_g))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_aug_load (g);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_AUG_LS
static PyObject *
guestfs_int_py_aug_ls (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  char **r;
  const char *augpath;

  if (!PyArg_ParseTuple (args, (char *) "Os:guestfs_aug_ls",
                         &py_g, &augpath))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_aug_ls (g, augpath);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == NULL) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  py_r = put_string_list (r);
  guestfs_int_free_string_list (r);

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_AUG_MATCH
static PyObject *
guestfs_int_py_aug_match (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  char **r;
  const char *augpath;

  if (!PyArg_ParseTuple (args, (char *) "Os:guestfs_aug_match",
                         &py_g, &augpath))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_aug_match (g, augpath);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == NULL) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  py_r = put_string_list (r);
  guestfs_int_free_string_list (r);

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_AUG_MV
static PyObject *
guestfs_int_py_aug_mv (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  const char *src;
  const char *dest;

  if (!PyArg_ParseTuple (args, (char *) "Oss:guestfs_aug_mv",
                         &py_g, &src, &dest))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_aug_mv (g, src, dest);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_AUG_RM
static PyObject *
guestfs_int_py_aug_rm (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  const char *augpath;

  if (!PyArg_ParseTuple (args, (char *) "Os:guestfs_aug_rm",
                         &py_g, &augpath))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_aug_rm (g, augpath);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  py_r = PyLong_FromLong ((long) r);

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_AUG_SAVE
static PyObject *
guestfs_int_py_aug_save (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;

  if (!PyArg_ParseTuple (args, (char *) "O:guestfs_aug_save",
                         &py_g))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_aug_save (g);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_AUG_SET
static PyObject *
guestfs_int_py_aug_set (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  const char *augpath;
  const char *val;

  if (!PyArg_ParseTuple (args, (char *) "Oss:guestfs_aug_set",
                         &py_g, &augpath, &val))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_aug_set (g, augpath, val);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_AUG_SETM
static PyObject *
guestfs_int_py_aug_setm (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  const char *base;
  const char *sub;
  const char *val;

  if (!PyArg_ParseTuple (args, (char *) "Oszs:guestfs_aug_setm",
                         &py_g, &base, &sub, &val))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_aug_setm (g, base, sub, val);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  py_r = PyLong_FromLong ((long) r);

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_AVAILABLE
static PyObject *
guestfs_int_py_available (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  PyObject *py_groups;
  char **groups = NULL;

  if (!PyArg_ParseTuple (args, (char *) "OO:guestfs_available",
                         &py_g, &py_groups))
    goto out;
  g = get_handle (py_g);
  groups = get_string_list (py_groups);
  if (!groups) goto out;

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_available (g, groups);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  free (groups);
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_AVAILABLE_ALL_GROUPS
static PyObject *
guestfs_int_py_available_all_groups (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  char **r;

  if (!PyArg_ParseTuple (args, (char *) "O:guestfs_available_all_groups",
                         &py_g))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_available_all_groups (g);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == NULL) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  py_r = put_string_list (r);
  guestfs_int_free_string_list (r);

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_BASE64_IN
static PyObject *
guestfs_int_py_base64_in (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  const char *base64file;
  const char *filename;

  if (!PyArg_ParseTuple (args, (char *) "Oss:guestfs_base64_in",
                         &py_g, &base64file, &filename))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_base64_in (g, base64file, filename);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_BASE64_OUT
static PyObject *
guestfs_int_py_base64_out (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  const char *filename;
  const char *base64file;

  if (!PyArg_ParseTuple (args, (char *) "Oss:guestfs_base64_out",
                         &py_g, &filename, &base64file))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_base64_out (g, filename, base64file);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_BLKDISCARD
static PyObject *
guestfs_int_py_blkdiscard (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  const char *device;

  if (!PyArg_ParseTuple (args, (char *) "Os:guestfs_blkdiscard",
                         &py_g, &device))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_blkdiscard (g, device);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_BLKDISCARDZEROES
static PyObject *
guestfs_int_py_blkdiscardzeroes (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  const char *device;

  if (!PyArg_ParseTuple (args, (char *) "Os:guestfs_blkdiscardzeroes",
                         &py_g, &device))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_blkdiscardzeroes (g, device);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  py_r = PyLong_FromLong ((long) r);

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_BLKID
static PyObject *
guestfs_int_py_blkid (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  char **r;
  const char *device;

  if (!PyArg_ParseTuple (args, (char *) "Os:guestfs_blkid",
                         &py_g, &device))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_blkid (g, device);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == NULL) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  py_r = put_table (r);
  guestfs_int_free_string_list (r);

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_BLOCKDEV_FLUSHBUFS
static PyObject *
guestfs_int_py_blockdev_flushbufs (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  const char *device;

  if (!PyArg_ParseTuple (args, (char *) "Os:guestfs_blockdev_flushbufs",
                         &py_g, &device))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_blockdev_flushbufs (g, device);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_BLOCKDEV_GETBSZ
static PyObject *
guestfs_int_py_blockdev_getbsz (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  const char *device;

  if (!PyArg_ParseTuple (args, (char *) "Os:guestfs_blockdev_getbsz",
                         &py_g, &device))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_blockdev_getbsz (g, device);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  py_r = PyLong_FromLong ((long) r);

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_BLOCKDEV_GETRO
static PyObject *
guestfs_int_py_blockdev_getro (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  const char *device;

  if (!PyArg_ParseTuple (args, (char *) "Os:guestfs_blockdev_getro",
                         &py_g, &device))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_blockdev_getro (g, device);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  py_r = PyLong_FromLong ((long) r);

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_BLOCKDEV_GETSIZE64
static PyObject *
guestfs_int_py_blockdev_getsize64 (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int64_t r;
  const char *device;

  if (!PyArg_ParseTuple (args, (char *) "Os:guestfs_blockdev_getsize64",
                         &py_g, &device))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_blockdev_getsize64 (g, device);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  py_r = PyLong_FromLongLong (r);

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_BLOCKDEV_GETSS
static PyObject *
guestfs_int_py_blockdev_getss (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  const char *device;

  if (!PyArg_ParseTuple (args, (char *) "Os:guestfs_blockdev_getss",
                         &py_g, &device))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_blockdev_getss (g, device);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  py_r = PyLong_FromLong ((long) r);

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_BLOCKDEV_GETSZ
static PyObject *
guestfs_int_py_blockdev_getsz (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int64_t r;
  const char *device;

  if (!PyArg_ParseTuple (args, (char *) "Os:guestfs_blockdev_getsz",
                         &py_g, &device))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_blockdev_getsz (g, device);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  py_r = PyLong_FromLongLong (r);

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_BLOCKDEV_REREADPT
static PyObject *
guestfs_int_py_blockdev_rereadpt (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  const char *device;

  if (!PyArg_ParseTuple (args, (char *) "Os:guestfs_blockdev_rereadpt",
                         &py_g, &device))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_blockdev_rereadpt (g, device);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_BLOCKDEV_SETBSZ
static PyObject *
guestfs_int_py_blockdev_setbsz (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  const char *device;
  int blocksize;

  if (!PyArg_ParseTuple (args, (char *) "Osi:guestfs_blockdev_setbsz",
                         &py_g, &device, &blocksize))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_blockdev_setbsz (g, device, blocksize);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_BLOCKDEV_SETRA
static PyObject *
guestfs_int_py_blockdev_setra (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  const char *device;
  int sectors;

  if (!PyArg_ParseTuple (args, (char *) "Osi:guestfs_blockdev_setra",
                         &py_g, &device, &sectors))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_blockdev_setra (g, device, sectors);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_BLOCKDEV_SETRO
static PyObject *
guestfs_int_py_blockdev_setro (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  const char *device;

  if (!PyArg_ParseTuple (args, (char *) "Os:guestfs_blockdev_setro",
                         &py_g, &device))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_blockdev_setro (g, device);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_BLOCKDEV_SETRW
static PyObject *
guestfs_int_py_blockdev_setrw (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  const char *device;

  if (!PyArg_ParseTuple (args, (char *) "Os:guestfs_blockdev_setrw",
                         &py_g, &device))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_blockdev_setrw (g, device);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_BTRFS_BALANCE_CANCEL
static PyObject *
guestfs_int_py_btrfs_balance_cancel (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  const char *path;

  if (!PyArg_ParseTuple (args, (char *) "Os:guestfs_btrfs_balance_cancel",
                         &py_g, &path))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_btrfs_balance_cancel (g, path);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_BTRFS_BALANCE_PAUSE
static PyObject *
guestfs_int_py_btrfs_balance_pause (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  const char *path;

  if (!PyArg_ParseTuple (args, (char *) "Os:guestfs_btrfs_balance_pause",
                         &py_g, &path))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_btrfs_balance_pause (g, path);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_BTRFS_BALANCE_RESUME
static PyObject *
guestfs_int_py_btrfs_balance_resume (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  const char *path;

  if (!PyArg_ParseTuple (args, (char *) "Os:guestfs_btrfs_balance_resume",
                         &py_g, &path))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_btrfs_balance_resume (g, path);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_BTRFS_BALANCE_STATUS
static PyObject *
guestfs_int_py_btrfs_balance_status (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  struct guestfs_btrfsbalance *r;
  const char *path;

  if (!PyArg_ParseTuple (args, (char *) "Os:guestfs_btrfs_balance_status",
                         &py_g, &path))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_btrfs_balance_status (g, path);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == NULL) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  py_r = put_btrfsbalance (r);
  guestfs_free_btrfsbalance (r);

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_BTRFS_DEVICE_ADD
static PyObject *
guestfs_int_py_btrfs_device_add (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  PyObject *py_devices;
  char **devices = NULL;
  const char *fs;

  if (!PyArg_ParseTuple (args, (char *) "OOs:guestfs_btrfs_device_add",
                         &py_g, &py_devices, &fs))
    goto out;
  g = get_handle (py_g);
  devices = get_string_list (py_devices);
  if (!devices) goto out;

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_btrfs_device_add (g, devices, fs);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  free (devices);
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_BTRFS_DEVICE_DELETE
static PyObject *
guestfs_int_py_btrfs_device_delete (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  PyObject *py_devices;
  char **devices = NULL;
  const char *fs;

  if (!PyArg_ParseTuple (args, (char *) "OOs:guestfs_btrfs_device_delete",
                         &py_g, &py_devices, &fs))
    goto out;
  g = get_handle (py_g);
  devices = get_string_list (py_devices);
  if (!devices) goto out;

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_btrfs_device_delete (g, devices, fs);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  free (devices);
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_BTRFS_FILESYSTEM_BALANCE
static PyObject *
guestfs_int_py_btrfs_filesystem_balance (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  const char *fs;

  if (!PyArg_ParseTuple (args, (char *) "Os:guestfs_btrfs_filesystem_balance",
                         &py_g, &fs))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_btrfs_filesystem_balance (g, fs);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_BTRFS_FILESYSTEM_DEFRAGMENT
static PyObject *
guestfs_int_py_btrfs_filesystem_defragment (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  struct guestfs_btrfs_filesystem_defragment_argv optargs_s;
  struct guestfs_btrfs_filesystem_defragment_argv *optargs = &optargs_s;
  int r;
  const char *path;
  PyObject *py_flush;
  PyObject *py_compress;

  optargs_s.bitmask = 0;

  if (!PyArg_ParseTuple (args, (char *) "OsOO:guestfs_btrfs_filesystem_defragment",
                         &py_g, &path, &py_flush, &py_compress))
    goto out;
  g = get_handle (py_g);

#ifdef GUESTFS_BTRFS_FILESYSTEM_DEFRAGMENT_FLUSH_BITMASK
  if (py_flush != Py_None) {
    optargs_s.bitmask |= GUESTFS_BTRFS_FILESYSTEM_DEFRAGMENT_FLUSH_BITMASK;
    optargs_s.flush = PyLong_AsLong (py_flush);
    if (PyErr_Occurred ()) goto out;
  }
#endif
#ifdef GUESTFS_BTRFS_FILESYSTEM_DEFRAGMENT_COMPRESS_BITMASK
  if (py_compress != Py_None) {
    optargs_s.bitmask |= GUESTFS_BTRFS_FILESYSTEM_DEFRAGMENT_COMPRESS_BITMASK;
#ifdef HAVE_PYSTRING_ASSTRING
    optargs_s.compress = PyString_AsString (py_compress);
#else
    PyObject *bytes;
    bytes = PyUnicode_AsUTF8String (py_compress);
    optargs_s.compress = PyBytes_AS_STRING (bytes);
#endif
  }
#endif

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_btrfs_filesystem_defragment_argv (g, path, optargs);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_BTRFS_FILESYSTEM_RESIZE
static PyObject *
guestfs_int_py_btrfs_filesystem_resize (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  struct guestfs_btrfs_filesystem_resize_argv optargs_s;
  struct guestfs_btrfs_filesystem_resize_argv *optargs = &optargs_s;
  int r;
  const char *mountpoint;
  PyObject *py_size;

  optargs_s.bitmask = 0;

  if (!PyArg_ParseTuple (args, (char *) "OsO:guestfs_btrfs_filesystem_resize",
                         &py_g, &mountpoint, &py_size))
    goto out;
  g = get_handle (py_g);

#ifdef GUESTFS_BTRFS_FILESYSTEM_RESIZE_SIZE_BITMASK
  if (py_size != Py_None) {
    optargs_s.bitmask |= GUESTFS_BTRFS_FILESYSTEM_RESIZE_SIZE_BITMASK;
    optargs_s.size = PyLong_AsLongLong (py_size);
    if (PyErr_Occurred ()) goto out;
  }
#endif

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_btrfs_filesystem_resize_argv (g, mountpoint, optargs);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_BTRFS_FILESYSTEM_SYNC
static PyObject *
guestfs_int_py_btrfs_filesystem_sync (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  const char *fs;

  if (!PyArg_ParseTuple (args, (char *) "Os:guestfs_btrfs_filesystem_sync",
                         &py_g, &fs))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_btrfs_filesystem_sync (g, fs);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_BTRFS_FSCK
static PyObject *
guestfs_int_py_btrfs_fsck (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  struct guestfs_btrfs_fsck_argv optargs_s;
  struct guestfs_btrfs_fsck_argv *optargs = &optargs_s;
  int r;
  const char *device;
  PyObject *py_superblock;
  PyObject *py_repair;

  optargs_s.bitmask = 0;

  if (!PyArg_ParseTuple (args, (char *) "OsOO:guestfs_btrfs_fsck",
                         &py_g, &device, &py_superblock, &py_repair))
    goto out;
  g = get_handle (py_g);

#ifdef GUESTFS_BTRFS_FSCK_SUPERBLOCK_BITMASK
  if (py_superblock != Py_None) {
    optargs_s.bitmask |= GUESTFS_BTRFS_FSCK_SUPERBLOCK_BITMASK;
    optargs_s.superblock = PyLong_AsLongLong (py_superblock);
    if (PyErr_Occurred ()) goto out;
  }
#endif
#ifdef GUESTFS_BTRFS_FSCK_REPAIR_BITMASK
  if (py_repair != Py_None) {
    optargs_s.bitmask |= GUESTFS_BTRFS_FSCK_REPAIR_BITMASK;
    optargs_s.repair = PyLong_AsLong (py_repair);
    if (PyErr_Occurred ()) goto out;
  }
#endif

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_btrfs_fsck_argv (g, device, optargs);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_BTRFS_IMAGE
static PyObject *
guestfs_int_py_btrfs_image (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  struct guestfs_btrfs_image_argv optargs_s;
  struct guestfs_btrfs_image_argv *optargs = &optargs_s;
  int r;
  PyObject *py_source;
  char **source = NULL;
  const char *image;
  PyObject *py_compresslevel;

  optargs_s.bitmask = 0;

  if (!PyArg_ParseTuple (args, (char *) "OOsO:guestfs_btrfs_image",
                         &py_g, &py_source, &image, &py_compresslevel))
    goto out;
  g = get_handle (py_g);
  source = get_string_list (py_source);
  if (!source) goto out;

#ifdef GUESTFS_BTRFS_IMAGE_COMPRESSLEVEL_BITMASK
  if (py_compresslevel != Py_None) {
    optargs_s.bitmask |= GUESTFS_BTRFS_IMAGE_COMPRESSLEVEL_BITMASK;
    optargs_s.compresslevel = PyLong_AsLong (py_compresslevel);
    if (PyErr_Occurred ()) goto out;
  }
#endif

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_btrfs_image_argv (g, source, image, optargs);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  free (source);
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_BTRFS_QGROUP_ASSIGN
static PyObject *
guestfs_int_py_btrfs_qgroup_assign (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  const char *src;
  const char *dst;
  const char *path;

  if (!PyArg_ParseTuple (args, (char *) "Osss:guestfs_btrfs_qgroup_assign",
                         &py_g, &src, &dst, &path))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_btrfs_qgroup_assign (g, src, dst, path);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_BTRFS_QGROUP_CREATE
static PyObject *
guestfs_int_py_btrfs_qgroup_create (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  const char *qgroupid;
  const char *subvolume;

  if (!PyArg_ParseTuple (args, (char *) "Oss:guestfs_btrfs_qgroup_create",
                         &py_g, &qgroupid, &subvolume))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_btrfs_qgroup_create (g, qgroupid, subvolume);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_BTRFS_QGROUP_DESTROY
static PyObject *
guestfs_int_py_btrfs_qgroup_destroy (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  const char *qgroupid;
  const char *subvolume;

  if (!PyArg_ParseTuple (args, (char *) "Oss:guestfs_btrfs_qgroup_destroy",
                         &py_g, &qgroupid, &subvolume))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_btrfs_qgroup_destroy (g, qgroupid, subvolume);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_BTRFS_QGROUP_LIMIT
static PyObject *
guestfs_int_py_btrfs_qgroup_limit (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  const char *subvolume;
  long long size;

  if (!PyArg_ParseTuple (args, (char *) "OsL:guestfs_btrfs_qgroup_limit",
                         &py_g, &subvolume, &size))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_btrfs_qgroup_limit (g, subvolume, size);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_BTRFS_QGROUP_REMOVE
static PyObject *
guestfs_int_py_btrfs_qgroup_remove (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  const char *src;
  const char *dst;
  const char *path;

  if (!PyArg_ParseTuple (args, (char *) "Osss:guestfs_btrfs_qgroup_remove",
                         &py_g, &src, &dst, &path))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_btrfs_qgroup_remove (g, src, dst, path);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_BTRFS_QGROUP_SHOW
static PyObject *
guestfs_int_py_btrfs_qgroup_show (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  struct guestfs_btrfsqgroup_list *r;
  const char *path;

  if (!PyArg_ParseTuple (args, (char *) "Os:guestfs_btrfs_qgroup_show",
                         &py_g, &path))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_btrfs_qgroup_show (g, path);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == NULL) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  py_r = put_btrfsqgroup_list (r);
  guestfs_free_btrfsqgroup_list (r);

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_BTRFS_QUOTA_ENABLE
static PyObject *
guestfs_int_py_btrfs_quota_enable (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  const char *fs;
  int enable;

  if (!PyArg_ParseTuple (args, (char *) "Osi:guestfs_btrfs_quota_enable",
                         &py_g, &fs, &enable))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_btrfs_quota_enable (g, fs, enable);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_BTRFS_QUOTA_RESCAN
static PyObject *
guestfs_int_py_btrfs_quota_rescan (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  const char *fs;

  if (!PyArg_ParseTuple (args, (char *) "Os:guestfs_btrfs_quota_rescan",
                         &py_g, &fs))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_btrfs_quota_rescan (g, fs);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_BTRFS_REPLACE
static PyObject *
guestfs_int_py_btrfs_replace (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  const char *srcdev;
  const char *targetdev;
  const char *mntpoint;

  if (!PyArg_ParseTuple (args, (char *) "Osss:guestfs_btrfs_replace",
                         &py_g, &srcdev, &targetdev, &mntpoint))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_btrfs_replace (g, srcdev, targetdev, mntpoint);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_BTRFS_RESCUE_CHUNK_RECOVER
static PyObject *
guestfs_int_py_btrfs_rescue_chunk_recover (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  const char *device;

  if (!PyArg_ParseTuple (args, (char *) "Os:guestfs_btrfs_rescue_chunk_recover",
                         &py_g, &device))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_btrfs_rescue_chunk_recover (g, device);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_BTRFS_RESCUE_SUPER_RECOVER
static PyObject *
guestfs_int_py_btrfs_rescue_super_recover (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  const char *device;

  if (!PyArg_ParseTuple (args, (char *) "Os:guestfs_btrfs_rescue_super_recover",
                         &py_g, &device))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_btrfs_rescue_super_recover (g, device);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_BTRFS_SCRUB_CANCEL
static PyObject *
guestfs_int_py_btrfs_scrub_cancel (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  const char *path;

  if (!PyArg_ParseTuple (args, (char *) "Os:guestfs_btrfs_scrub_cancel",
                         &py_g, &path))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_btrfs_scrub_cancel (g, path);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_BTRFS_SCRUB_RESUME
static PyObject *
guestfs_int_py_btrfs_scrub_resume (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  const char *path;

  if (!PyArg_ParseTuple (args, (char *) "Os:guestfs_btrfs_scrub_resume",
                         &py_g, &path))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_btrfs_scrub_resume (g, path);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_BTRFS_SCRUB_START
static PyObject *
guestfs_int_py_btrfs_scrub_start (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  const char *path;

  if (!PyArg_ParseTuple (args, (char *) "Os:guestfs_btrfs_scrub_start",
                         &py_g, &path))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_btrfs_scrub_start (g, path);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_BTRFS_SCRUB_STATUS
static PyObject *
guestfs_int_py_btrfs_scrub_status (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  struct guestfs_btrfsscrub *r;
  const char *path;

  if (!PyArg_ParseTuple (args, (char *) "Os:guestfs_btrfs_scrub_status",
                         &py_g, &path))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_btrfs_scrub_status (g, path);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == NULL) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  py_r = put_btrfsscrub (r);
  guestfs_free_btrfsscrub (r);

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_BTRFS_SET_SEEDING
static PyObject *
guestfs_int_py_btrfs_set_seeding (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  const char *device;
  int seeding;

  if (!PyArg_ParseTuple (args, (char *) "Osi:guestfs_btrfs_set_seeding",
                         &py_g, &device, &seeding))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_btrfs_set_seeding (g, device, seeding);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_BTRFS_SUBVOLUME_CREATE_OPTS
static PyObject *
guestfs_int_py_btrfs_subvolume_create (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  struct guestfs_btrfs_subvolume_create_opts_argv optargs_s;
  struct guestfs_btrfs_subvolume_create_opts_argv *optargs = &optargs_s;
  int r;
  const char *dest;
  PyObject *py_qgroupid;

  optargs_s.bitmask = 0;

  if (!PyArg_ParseTuple (args, (char *) "OsO:guestfs_btrfs_subvolume_create",
                         &py_g, &dest, &py_qgroupid))
    goto out;
  g = get_handle (py_g);

#ifdef GUESTFS_BTRFS_SUBVOLUME_CREATE_OPTS_QGROUPID_BITMASK
  if (py_qgroupid != Py_None) {
    optargs_s.bitmask |= GUESTFS_BTRFS_SUBVOLUME_CREATE_OPTS_QGROUPID_BITMASK;
#ifdef HAVE_PYSTRING_ASSTRING
    optargs_s.qgroupid = PyString_AsString (py_qgroupid);
#else
    PyObject *bytes;
    bytes = PyUnicode_AsUTF8String (py_qgroupid);
    optargs_s.qgroupid = PyBytes_AS_STRING (bytes);
#endif
  }
#endif

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_btrfs_subvolume_create_opts_argv (g, dest, optargs);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_BTRFS_SUBVOLUME_DELETE
static PyObject *
guestfs_int_py_btrfs_subvolume_delete (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  const char *subvolume;

  if (!PyArg_ParseTuple (args, (char *) "Os:guestfs_btrfs_subvolume_delete",
                         &py_g, &subvolume))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_btrfs_subvolume_delete (g, subvolume);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_BTRFS_SUBVOLUME_GET_DEFAULT
static PyObject *
guestfs_int_py_btrfs_subvolume_get_default (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int64_t r;
  const char *fs;

  if (!PyArg_ParseTuple (args, (char *) "Os:guestfs_btrfs_subvolume_get_default",
                         &py_g, &fs))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_btrfs_subvolume_get_default (g, fs);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  py_r = PyLong_FromLongLong (r);

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_BTRFS_SUBVOLUME_LIST
static PyObject *
guestfs_int_py_btrfs_subvolume_list (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  struct guestfs_btrfssubvolume_list *r;
  const char *fs;

  if (!PyArg_ParseTuple (args, (char *) "Os:guestfs_btrfs_subvolume_list",
                         &py_g, &fs))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_btrfs_subvolume_list (g, fs);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == NULL) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  py_r = put_btrfssubvolume_list (r);
  guestfs_free_btrfssubvolume_list (r);

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_BTRFS_SUBVOLUME_SET_DEFAULT
static PyObject *
guestfs_int_py_btrfs_subvolume_set_default (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  long long id;
  const char *fs;

  if (!PyArg_ParseTuple (args, (char *) "OLs:guestfs_btrfs_subvolume_set_default",
                         &py_g, &id, &fs))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_btrfs_subvolume_set_default (g, id, fs);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_BTRFS_SUBVOLUME_SHOW
static PyObject *
guestfs_int_py_btrfs_subvolume_show (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  char **r;
  const char *subvolume;

  if (!PyArg_ParseTuple (args, (char *) "Os:guestfs_btrfs_subvolume_show",
                         &py_g, &subvolume))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_btrfs_subvolume_show (g, subvolume);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == NULL) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  py_r = put_table (r);
  guestfs_int_free_string_list (r);

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_BTRFS_SUBVOLUME_SNAPSHOT_OPTS
static PyObject *
guestfs_int_py_btrfs_subvolume_snapshot (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  struct guestfs_btrfs_subvolume_snapshot_opts_argv optargs_s;
  struct guestfs_btrfs_subvolume_snapshot_opts_argv *optargs = &optargs_s;
  int r;
  const char *source;
  const char *dest;
  PyObject *py_ro;
  PyObject *py_qgroupid;

  optargs_s.bitmask = 0;

  if (!PyArg_ParseTuple (args, (char *) "OssOO:guestfs_btrfs_subvolume_snapshot",
                         &py_g, &source, &dest, &py_ro, &py_qgroupid))
    goto out;
  g = get_handle (py_g);

#ifdef GUESTFS_BTRFS_SUBVOLUME_SNAPSHOT_OPTS_RO_BITMASK
  if (py_ro != Py_None) {
    optargs_s.bitmask |= GUESTFS_BTRFS_SUBVOLUME_SNAPSHOT_OPTS_RO_BITMASK;
    optargs_s.ro = PyLong_AsLong (py_ro);
    if (PyErr_Occurred ()) goto out;
  }
#endif
#ifdef GUESTFS_BTRFS_SUBVOLUME_SNAPSHOT_OPTS_QGROUPID_BITMASK
  if (py_qgroupid != Py_None) {
    optargs_s.bitmask |= GUESTFS_BTRFS_SUBVOLUME_SNAPSHOT_OPTS_QGROUPID_BITMASK;
#ifdef HAVE_PYSTRING_ASSTRING
    optargs_s.qgroupid = PyString_AsString (py_qgroupid);
#else
    PyObject *bytes;
    bytes = PyUnicode_AsUTF8String (py_qgroupid);
    optargs_s.qgroupid = PyBytes_AS_STRING (bytes);
#endif
  }
#endif

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_btrfs_subvolume_snapshot_opts_argv (g, source, dest, optargs);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_BTRFSTUNE_ENABLE_EXTENDED_INODE_REFS
static PyObject *
guestfs_int_py_btrfstune_enable_extended_inode_refs (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  const char *device;

  if (!PyArg_ParseTuple (args, (char *) "Os:guestfs_btrfstune_enable_extended_inode_refs",
                         &py_g, &device))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_btrfstune_enable_extended_inode_refs (g, device);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_BTRFSTUNE_ENABLE_SKINNY_METADATA_EXTENT_REFS
static PyObject *
guestfs_int_py_btrfstune_enable_skinny_metadata_extent_refs (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  const char *device;

  if (!PyArg_ParseTuple (args, (char *) "Os:guestfs_btrfstune_enable_skinny_metadata_extent_refs",
                         &py_g, &device))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_btrfstune_enable_skinny_metadata_extent_refs (g, device);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_BTRFSTUNE_SEEDING
static PyObject *
guestfs_int_py_btrfstune_seeding (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  const char *device;
  int seeding;

  if (!PyArg_ParseTuple (args, (char *) "Osi:guestfs_btrfstune_seeding",
                         &py_g, &device, &seeding))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_btrfstune_seeding (g, device, seeding);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_C_POINTER
static PyObject *
guestfs_int_py_c_pointer (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int64_t r;

  if (!PyArg_ParseTuple (args, (char *) "O:guestfs_c_pointer",
                         &py_g))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_c_pointer (g);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  py_r = PyLong_FromLongLong (r);

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_CANONICAL_DEVICE_NAME
static PyObject *
guestfs_int_py_canonical_device_name (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  char *r;
  const char *device;

  if (!PyArg_ParseTuple (args, (char *) "Os:guestfs_canonical_device_name",
                         &py_g, &device))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_canonical_device_name (g, device);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == NULL) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

#ifdef HAVE_PYSTRING_ASSTRING
  py_r = PyString_FromString (r);
#else
  py_r = PyUnicode_FromString (r);
#endif
  free (r);
  if (py_r == NULL) goto out;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_CAP_GET_FILE
static PyObject *
guestfs_int_py_cap_get_file (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  char *r;
  const char *path;

  if (!PyArg_ParseTuple (args, (char *) "Os:guestfs_cap_get_file",
                         &py_g, &path))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_cap_get_file (g, path);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == NULL) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

#ifdef HAVE_PYSTRING_ASSTRING
  py_r = PyString_FromString (r);
#else
  py_r = PyUnicode_FromString (r);
#endif
  free (r);
  if (py_r == NULL) goto out;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_CAP_SET_FILE
static PyObject *
guestfs_int_py_cap_set_file (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  const char *path;
  const char *cap;

  if (!PyArg_ParseTuple (args, (char *) "Oss:guestfs_cap_set_file",
                         &py_g, &path, &cap))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_cap_set_file (g, path, cap);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_CASE_SENSITIVE_PATH
static PyObject *
guestfs_int_py_case_sensitive_path (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  char *r;
  const char *path;

  if (!PyArg_ParseTuple (args, (char *) "Os:guestfs_case_sensitive_path",
                         &py_g, &path))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_case_sensitive_path (g, path);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == NULL) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

#ifdef HAVE_PYSTRING_ASSTRING
  py_r = PyString_FromString (r);
#else
  py_r = PyUnicode_FromString (r);
#endif
  free (r);
  if (py_r == NULL) goto out;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_CAT
static PyObject *
guestfs_int_py_cat (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  char *r;
  const char *path;

  if (!PyArg_ParseTuple (args, (char *) "Os:guestfs_cat",
                         &py_g, &path))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_cat (g, path);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == NULL) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

#ifdef HAVE_PYSTRING_ASSTRING
  py_r = PyString_FromString (r);
#else
  py_r = PyUnicode_FromString (r);
#endif
  free (r);
  if (py_r == NULL) goto out;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_CHECKSUM
static PyObject *
guestfs_int_py_checksum (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  char *r;
  const char *csumtype;
  const char *path;

  if (!PyArg_ParseTuple (args, (char *) "Oss:guestfs_checksum",
                         &py_g, &csumtype, &path))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_checksum (g, csumtype, path);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == NULL) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

#ifdef HAVE_PYSTRING_ASSTRING
  py_r = PyString_FromString (r);
#else
  py_r = PyUnicode_FromString (r);
#endif
  free (r);
  if (py_r == NULL) goto out;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_CHECKSUM_DEVICE
static PyObject *
guestfs_int_py_checksum_device (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  char *r;
  const char *csumtype;
  const char *device;

  if (!PyArg_ParseTuple (args, (char *) "Oss:guestfs_checksum_device",
                         &py_g, &csumtype, &device))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_checksum_device (g, csumtype, device);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == NULL) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

#ifdef HAVE_PYSTRING_ASSTRING
  py_r = PyString_FromString (r);
#else
  py_r = PyUnicode_FromString (r);
#endif
  free (r);
  if (py_r == NULL) goto out;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_CHECKSUMS_OUT
static PyObject *
guestfs_int_py_checksums_out (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  const char *csumtype;
  const char *directory;
  const char *sumsfile;

  if (!PyArg_ParseTuple (args, (char *) "Osss:guestfs_checksums_out",
                         &py_g, &csumtype, &directory, &sumsfile))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_checksums_out (g, csumtype, directory, sumsfile);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_CHMOD
static PyObject *
guestfs_int_py_chmod (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  int mode;
  const char *path;

  if (!PyArg_ParseTuple (args, (char *) "Ois:guestfs_chmod",
                         &py_g, &mode, &path))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_chmod (g, mode, path);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_CHOWN
static PyObject *
guestfs_int_py_chown (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  int owner;
  int group;
  const char *path;

  if (!PyArg_ParseTuple (args, (char *) "Oiis:guestfs_chown",
                         &py_g, &owner, &group, &path))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_chown (g, owner, group, path);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_CLEAR_BACKEND_SETTING
static PyObject *
guestfs_int_py_clear_backend_setting (PyObject *self, PyObject *args)
{
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  const char *name;

  if (!PyArg_ParseTuple (args, (char *) "Os:guestfs_clear_backend_setting",
                         &py_g, &name))
    goto out;
  g = get_handle (py_g);

  r = guestfs_clear_backend_setting (g, name);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  py_r = PyLong_FromLong ((long) r);

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_COMMAND
static PyObject *
guestfs_int_py_command (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  char *r;
  PyObject *py_arguments;
  char **arguments = NULL;

  if (!PyArg_ParseTuple (args, (char *) "OO:guestfs_command",
                         &py_g, &py_arguments))
    goto out;
  g = get_handle (py_g);
  arguments = get_string_list (py_arguments);
  if (!arguments) goto out;

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_command (g, arguments);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == NULL) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

#ifdef HAVE_PYSTRING_ASSTRING
  py_r = PyString_FromString (r);
#else
  py_r = PyUnicode_FromString (r);
#endif
  free (r);
  if (py_r == NULL) goto out;

  PyErr_Clear ();
 out:
  free (arguments);
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_COMMAND_LINES
static PyObject *
guestfs_int_py_command_lines (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  char **r;
  PyObject *py_arguments;
  char **arguments = NULL;

  if (!PyArg_ParseTuple (args, (char *) "OO:guestfs_command_lines",
                         &py_g, &py_arguments))
    goto out;
  g = get_handle (py_g);
  arguments = get_string_list (py_arguments);
  if (!arguments) goto out;

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_command_lines (g, arguments);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == NULL) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  py_r = put_string_list (r);
  guestfs_int_free_string_list (r);

  PyErr_Clear ();
 out:
  free (arguments);
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_COMPRESS_DEVICE_OUT
static PyObject *
guestfs_int_py_compress_device_out (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  struct guestfs_compress_device_out_argv optargs_s;
  struct guestfs_compress_device_out_argv *optargs = &optargs_s;
  int r;
  const char *ctype;
  const char *device;
  const char *zdevice;
  PyObject *py_level;

  optargs_s.bitmask = 0;

  if (!PyArg_ParseTuple (args, (char *) "OsssO:guestfs_compress_device_out",
                         &py_g, &ctype, &device, &zdevice, &py_level))
    goto out;
  g = get_handle (py_g);

#ifdef GUESTFS_COMPRESS_DEVICE_OUT_LEVEL_BITMASK
  if (py_level != Py_None) {
    optargs_s.bitmask |= GUESTFS_COMPRESS_DEVICE_OUT_LEVEL_BITMASK;
    optargs_s.level = PyLong_AsLong (py_level);
    if (PyErr_Occurred ()) goto out;
  }
#endif

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_compress_device_out_argv (g, ctype, device, zdevice, optargs);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_COMPRESS_OUT
static PyObject *
guestfs_int_py_compress_out (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  struct guestfs_compress_out_argv optargs_s;
  struct guestfs_compress_out_argv *optargs = &optargs_s;
  int r;
  const char *ctype;
  const char *file;
  const char *zfile;
  PyObject *py_level;

  optargs_s.bitmask = 0;

  if (!PyArg_ParseTuple (args, (char *) "OsssO:guestfs_compress_out",
                         &py_g, &ctype, &file, &zfile, &py_level))
    goto out;
  g = get_handle (py_g);

#ifdef GUESTFS_COMPRESS_OUT_LEVEL_BITMASK
  if (py_level != Py_None) {
    optargs_s.bitmask |= GUESTFS_COMPRESS_OUT_LEVEL_BITMASK;
    optargs_s.level = PyLong_AsLong (py_level);
    if (PyErr_Occurred ()) goto out;
  }
#endif

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_compress_out_argv (g, ctype, file, zfile, optargs);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_CONFIG
static PyObject *
guestfs_int_py_config (PyObject *self, PyObject *args)
{
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  const char *hvparam;
  const char *hvvalue;

  if (!PyArg_ParseTuple (args, (char *) "Osz:guestfs_config",
                         &py_g, &hvparam, &hvvalue))
    goto out;
  g = get_handle (py_g);

  r = guestfs_config (g, hvparam, hvvalue);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_COPY_ATTRIBUTES
static PyObject *
guestfs_int_py_copy_attributes (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  struct guestfs_copy_attributes_argv optargs_s;
  struct guestfs_copy_attributes_argv *optargs = &optargs_s;
  int r;
  const char *src;
  const char *dest;
  PyObject *py_all;
  PyObject *py_mode;
  PyObject *py_xattributes;
  PyObject *py_ownership;

  optargs_s.bitmask = 0;

  if (!PyArg_ParseTuple (args, (char *) "OssOOOO:guestfs_copy_attributes",
                         &py_g, &src, &dest, &py_all, &py_mode, &py_xattributes, &py_ownership))
    goto out;
  g = get_handle (py_g);

#ifdef GUESTFS_COPY_ATTRIBUTES_ALL_BITMASK
  if (py_all != Py_None) {
    optargs_s.bitmask |= GUESTFS_COPY_ATTRIBUTES_ALL_BITMASK;
    optargs_s.all = PyLong_AsLong (py_all);
    if (PyErr_Occurred ()) goto out;
  }
#endif
#ifdef GUESTFS_COPY_ATTRIBUTES_MODE_BITMASK
  if (py_mode != Py_None) {
    optargs_s.bitmask |= GUESTFS_COPY_ATTRIBUTES_MODE_BITMASK;
    optargs_s.mode = PyLong_AsLong (py_mode);
    if (PyErr_Occurred ()) goto out;
  }
#endif
#ifdef GUESTFS_COPY_ATTRIBUTES_XATTRIBUTES_BITMASK
  if (py_xattributes != Py_None) {
    optargs_s.bitmask |= GUESTFS_COPY_ATTRIBUTES_XATTRIBUTES_BITMASK;
    optargs_s.xattributes = PyLong_AsLong (py_xattributes);
    if (PyErr_Occurred ()) goto out;
  }
#endif
#ifdef GUESTFS_COPY_ATTRIBUTES_OWNERSHIP_BITMASK
  if (py_ownership != Py_None) {
    optargs_s.bitmask |= GUESTFS_COPY_ATTRIBUTES_OWNERSHIP_BITMASK;
    optargs_s.ownership = PyLong_AsLong (py_ownership);
    if (PyErr_Occurred ()) goto out;
  }
#endif

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_copy_attributes_argv (g, src, dest, optargs);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_COPY_DEVICE_TO_DEVICE
static PyObject *
guestfs_int_py_copy_device_to_device (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  struct guestfs_copy_device_to_device_argv optargs_s;
  struct guestfs_copy_device_to_device_argv *optargs = &optargs_s;
  int r;
  const char *src;
  const char *dest;
  PyObject *py_srcoffset;
  PyObject *py_destoffset;
  PyObject *py_size;
  PyObject *py_sparse;
  PyObject *py_append;

  optargs_s.bitmask = 0;

  if (!PyArg_ParseTuple (args, (char *) "OssOOOOO:guestfs_copy_device_to_device",
                         &py_g, &src, &dest, &py_srcoffset, &py_destoffset, &py_size, &py_sparse, &py_append))
    goto out;
  g = get_handle (py_g);

#ifdef GUESTFS_COPY_DEVICE_TO_DEVICE_SRCOFFSET_BITMASK
  if (py_srcoffset != Py_None) {
    optargs_s.bitmask |= GUESTFS_COPY_DEVICE_TO_DEVICE_SRCOFFSET_BITMASK;
    optargs_s.srcoffset = PyLong_AsLongLong (py_srcoffset);
    if (PyErr_Occurred ()) goto out;
  }
#endif
#ifdef GUESTFS_COPY_DEVICE_TO_DEVICE_DESTOFFSET_BITMASK
  if (py_destoffset != Py_None) {
    optargs_s.bitmask |= GUESTFS_COPY_DEVICE_TO_DEVICE_DESTOFFSET_BITMASK;
    optargs_s.destoffset = PyLong_AsLongLong (py_destoffset);
    if (PyErr_Occurred ()) goto out;
  }
#endif
#ifdef GUESTFS_COPY_DEVICE_TO_DEVICE_SIZE_BITMASK
  if (py_size != Py_None) {
    optargs_s.bitmask |= GUESTFS_COPY_DEVICE_TO_DEVICE_SIZE_BITMASK;
    optargs_s.size = PyLong_AsLongLong (py_size);
    if (PyErr_Occurred ()) goto out;
  }
#endif
#ifdef GUESTFS_COPY_DEVICE_TO_DEVICE_SPARSE_BITMASK
  if (py_sparse != Py_None) {
    optargs_s.bitmask |= GUESTFS_COPY_DEVICE_TO_DEVICE_SPARSE_BITMASK;
    optargs_s.sparse = PyLong_AsLong (py_sparse);
    if (PyErr_Occurred ()) goto out;
  }
#endif
#ifdef GUESTFS_COPY_DEVICE_TO_DEVICE_APPEND_BITMASK
  if (py_append != Py_None) {
    optargs_s.bitmask |= GUESTFS_COPY_DEVICE_TO_DEVICE_APPEND_BITMASK;
    optargs_s.append = PyLong_AsLong (py_append);
    if (PyErr_Occurred ()) goto out;
  }
#endif

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_copy_device_to_device_argv (g, src, dest, optargs);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_COPY_DEVICE_TO_FILE
static PyObject *
guestfs_int_py_copy_device_to_file (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  struct guestfs_copy_device_to_file_argv optargs_s;
  struct guestfs_copy_device_to_file_argv *optargs = &optargs_s;
  int r;
  const char *src;
  const char *dest;
  PyObject *py_srcoffset;
  PyObject *py_destoffset;
  PyObject *py_size;
  PyObject *py_sparse;
  PyObject *py_append;

  optargs_s.bitmask = 0;

  if (!PyArg_ParseTuple (args, (char *) "OssOOOOO:guestfs_copy_device_to_file",
                         &py_g, &src, &dest, &py_srcoffset, &py_destoffset, &py_size, &py_sparse, &py_append))
    goto out;
  g = get_handle (py_g);

#ifdef GUESTFS_COPY_DEVICE_TO_FILE_SRCOFFSET_BITMASK
  if (py_srcoffset != Py_None) {
    optargs_s.bitmask |= GUESTFS_COPY_DEVICE_TO_FILE_SRCOFFSET_BITMASK;
    optargs_s.srcoffset = PyLong_AsLongLong (py_srcoffset);
    if (PyErr_Occurred ()) goto out;
  }
#endif
#ifdef GUESTFS_COPY_DEVICE_TO_FILE_DESTOFFSET_BITMASK
  if (py_destoffset != Py_None) {
    optargs_s.bitmask |= GUESTFS_COPY_DEVICE_TO_FILE_DESTOFFSET_BITMASK;
    optargs_s.destoffset = PyLong_AsLongLong (py_destoffset);
    if (PyErr_Occurred ()) goto out;
  }
#endif
#ifdef GUESTFS_COPY_DEVICE_TO_FILE_SIZE_BITMASK
  if (py_size != Py_None) {
    optargs_s.bitmask |= GUESTFS_COPY_DEVICE_TO_FILE_SIZE_BITMASK;
    optargs_s.size = PyLong_AsLongLong (py_size);
    if (PyErr_Occurred ()) goto out;
  }
#endif
#ifdef GUESTFS_COPY_DEVICE_TO_FILE_SPARSE_BITMASK
  if (py_sparse != Py_None) {
    optargs_s.bitmask |= GUESTFS_COPY_DEVICE_TO_FILE_SPARSE_BITMASK;
    optargs_s.sparse = PyLong_AsLong (py_sparse);
    if (PyErr_Occurred ()) goto out;
  }
#endif
#ifdef GUESTFS_COPY_DEVICE_TO_FILE_APPEND_BITMASK
  if (py_append != Py_None) {
    optargs_s.bitmask |= GUESTFS_COPY_DEVICE_TO_FILE_APPEND_BITMASK;
    optargs_s.append = PyLong_AsLong (py_append);
    if (PyErr_Occurred ()) goto out;
  }
#endif

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_copy_device_to_file_argv (g, src, dest, optargs);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_COPY_FILE_TO_DEVICE
static PyObject *
guestfs_int_py_copy_file_to_device (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  struct guestfs_copy_file_to_device_argv optargs_s;
  struct guestfs_copy_file_to_device_argv *optargs = &optargs_s;
  int r;
  const char *src;
  const char *dest;
  PyObject *py_srcoffset;
  PyObject *py_destoffset;
  PyObject *py_size;
  PyObject *py_sparse;
  PyObject *py_append;

  optargs_s.bitmask = 0;

  if (!PyArg_ParseTuple (args, (char *) "OssOOOOO:guestfs_copy_file_to_device",
                         &py_g, &src, &dest, &py_srcoffset, &py_destoffset, &py_size, &py_sparse, &py_append))
    goto out;
  g = get_handle (py_g);

#ifdef GUESTFS_COPY_FILE_TO_DEVICE_SRCOFFSET_BITMASK
  if (py_srcoffset != Py_None) {
    optargs_s.bitmask |= GUESTFS_COPY_FILE_TO_DEVICE_SRCOFFSET_BITMASK;
    optargs_s.srcoffset = PyLong_AsLongLong (py_srcoffset);
    if (PyErr_Occurred ()) goto out;
  }
#endif
#ifdef GUESTFS_COPY_FILE_TO_DEVICE_DESTOFFSET_BITMASK
  if (py_destoffset != Py_None) {
    optargs_s.bitmask |= GUESTFS_COPY_FILE_TO_DEVICE_DESTOFFSET_BITMASK;
    optargs_s.destoffset = PyLong_AsLongLong (py_destoffset);
    if (PyErr_Occurred ()) goto out;
  }
#endif
#ifdef GUESTFS_COPY_FILE_TO_DEVICE_SIZE_BITMASK
  if (py_size != Py_None) {
    optargs_s.bitmask |= GUESTFS_COPY_FILE_TO_DEVICE_SIZE_BITMASK;
    optargs_s.size = PyLong_AsLongLong (py_size);
    if (PyErr_Occurred ()) goto out;
  }
#endif
#ifdef GUESTFS_COPY_FILE_TO_DEVICE_SPARSE_BITMASK
  if (py_sparse != Py_None) {
    optargs_s.bitmask |= GUESTFS_COPY_FILE_TO_DEVICE_SPARSE_BITMASK;
    optargs_s.sparse = PyLong_AsLong (py_sparse);
    if (PyErr_Occurred ()) goto out;
  }
#endif
#ifdef GUESTFS_COPY_FILE_TO_DEVICE_APPEND_BITMASK
  if (py_append != Py_None) {
    optargs_s.bitmask |= GUESTFS_COPY_FILE_TO_DEVICE_APPEND_BITMASK;
    optargs_s.append = PyLong_AsLong (py_append);
    if (PyErr_Occurred ()) goto out;
  }
#endif

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_copy_file_to_device_argv (g, src, dest, optargs);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_COPY_FILE_TO_FILE
static PyObject *
guestfs_int_py_copy_file_to_file (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  struct guestfs_copy_file_to_file_argv optargs_s;
  struct guestfs_copy_file_to_file_argv *optargs = &optargs_s;
  int r;
  const char *src;
  const char *dest;
  PyObject *py_srcoffset;
  PyObject *py_destoffset;
  PyObject *py_size;
  PyObject *py_sparse;
  PyObject *py_append;

  optargs_s.bitmask = 0;

  if (!PyArg_ParseTuple (args, (char *) "OssOOOOO:guestfs_copy_file_to_file",
                         &py_g, &src, &dest, &py_srcoffset, &py_destoffset, &py_size, &py_sparse, &py_append))
    goto out;
  g = get_handle (py_g);

#ifdef GUESTFS_COPY_FILE_TO_FILE_SRCOFFSET_BITMASK
  if (py_srcoffset != Py_None) {
    optargs_s.bitmask |= GUESTFS_COPY_FILE_TO_FILE_SRCOFFSET_BITMASK;
    optargs_s.srcoffset = PyLong_AsLongLong (py_srcoffset);
    if (PyErr_Occurred ()) goto out;
  }
#endif
#ifdef GUESTFS_COPY_FILE_TO_FILE_DESTOFFSET_BITMASK
  if (py_destoffset != Py_None) {
    optargs_s.bitmask |= GUESTFS_COPY_FILE_TO_FILE_DESTOFFSET_BITMASK;
    optargs_s.destoffset = PyLong_AsLongLong (py_destoffset);
    if (PyErr_Occurred ()) goto out;
  }
#endif
#ifdef GUESTFS_COPY_FILE_TO_FILE_SIZE_BITMASK
  if (py_size != Py_None) {
    optargs_s.bitmask |= GUESTFS_COPY_FILE_TO_FILE_SIZE_BITMASK;
    optargs_s.size = PyLong_AsLongLong (py_size);
    if (PyErr_Occurred ()) goto out;
  }
#endif
#ifdef GUESTFS_COPY_FILE_TO_FILE_SPARSE_BITMASK
  if (py_sparse != Py_None) {
    optargs_s.bitmask |= GUESTFS_COPY_FILE_TO_FILE_SPARSE_BITMASK;
    optargs_s.sparse = PyLong_AsLong (py_sparse);
    if (PyErr_Occurred ()) goto out;
  }
#endif
#ifdef GUESTFS_COPY_FILE_TO_FILE_APPEND_BITMASK
  if (py_append != Py_None) {
    optargs_s.bitmask |= GUESTFS_COPY_FILE_TO_FILE_APPEND_BITMASK;
    optargs_s.append = PyLong_AsLong (py_append);
    if (PyErr_Occurred ()) goto out;
  }
#endif

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_copy_file_to_file_argv (g, src, dest, optargs);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_COPY_IN
static PyObject *
guestfs_int_py_copy_in (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  const char *localpath;
  const char *remotedir;

  if (!PyArg_ParseTuple (args, (char *) "Oss:guestfs_copy_in",
                         &py_g, &localpath, &remotedir))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_copy_in (g, localpath, remotedir);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_COPY_OUT
static PyObject *
guestfs_int_py_copy_out (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  const char *remotepath;
  const char *localdir;

  if (!PyArg_ParseTuple (args, (char *) "Oss:guestfs_copy_out",
                         &py_g, &remotepath, &localdir))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_copy_out (g, remotepath, localdir);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_COPY_SIZE
static PyObject *
guestfs_int_py_copy_size (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  const char *src;
  const char *dest;
  long long size;

  if (!PyArg_ParseTuple (args, (char *) "OssL:guestfs_copy_size",
                         &py_g, &src, &dest, &size))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_copy_size (g, src, dest, size);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_CP
static PyObject *
guestfs_int_py_cp (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  const char *src;
  const char *dest;

  if (!PyArg_ParseTuple (args, (char *) "Oss:guestfs_cp",
                         &py_g, &src, &dest))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_cp (g, src, dest);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_CP_A
static PyObject *
guestfs_int_py_cp_a (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  const char *src;
  const char *dest;

  if (!PyArg_ParseTuple (args, (char *) "Oss:guestfs_cp_a",
                         &py_g, &src, &dest))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_cp_a (g, src, dest);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_CP_R
static PyObject *
guestfs_int_py_cp_r (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  const char *src;
  const char *dest;

  if (!PyArg_ParseTuple (args, (char *) "Oss:guestfs_cp_r",
                         &py_g, &src, &dest))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_cp_r (g, src, dest);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_CPIO_OUT
static PyObject *
guestfs_int_py_cpio_out (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  struct guestfs_cpio_out_argv optargs_s;
  struct guestfs_cpio_out_argv *optargs = &optargs_s;
  int r;
  const char *directory;
  const char *cpiofile;
  PyObject *py_format;

  optargs_s.bitmask = 0;

  if (!PyArg_ParseTuple (args, (char *) "OssO:guestfs_cpio_out",
                         &py_g, &directory, &cpiofile, &py_format))
    goto out;
  g = get_handle (py_g);

#ifdef GUESTFS_CPIO_OUT_FORMAT_BITMASK
  if (py_format != Py_None) {
    optargs_s.bitmask |= GUESTFS_CPIO_OUT_FORMAT_BITMASK;
#ifdef HAVE_PYSTRING_ASSTRING
    optargs_s.format = PyString_AsString (py_format);
#else
    PyObject *bytes;
    bytes = PyUnicode_AsUTF8String (py_format);
    optargs_s.format = PyBytes_AS_STRING (bytes);
#endif
  }
#endif

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_cpio_out_argv (g, directory, cpiofile, optargs);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_DD
static PyObject *
guestfs_int_py_dd (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  const char *src;
  const char *dest;

  if (!PyArg_ParseTuple (args, (char *) "Oss:guestfs_dd",
                         &py_g, &src, &dest))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_dd (g, src, dest);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_DEBUG
static PyObject *
guestfs_int_py_debug (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  char *r;
  const char *subcmd;
  PyObject *py_extraargs;
  char **extraargs = NULL;

  if (!PyArg_ParseTuple (args, (char *) "OsO:guestfs_debug",
                         &py_g, &subcmd, &py_extraargs))
    goto out;
  g = get_handle (py_g);
  extraargs = get_string_list (py_extraargs);
  if (!extraargs) goto out;

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_debug (g, subcmd, extraargs);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == NULL) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

#ifdef HAVE_PYSTRING_ASSTRING
  py_r = PyString_FromString (r);
#else
  py_r = PyUnicode_FromString (r);
#endif
  free (r);
  if (py_r == NULL) goto out;

  PyErr_Clear ();
 out:
  free (extraargs);
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_DEBUG_DRIVES
static PyObject *
guestfs_int_py_debug_drives (PyObject *self, PyObject *args)
{
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  char **r;

  if (!PyArg_ParseTuple (args, (char *) "O:guestfs_debug_drives",
                         &py_g))
    goto out;
  g = get_handle (py_g);

  r = guestfs_debug_drives (g);

  if (r == NULL) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  py_r = put_string_list (r);
  guestfs_int_free_string_list (r);

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_DEBUG_UPLOAD
static PyObject *
guestfs_int_py_debug_upload (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  const char *filename;
  const char *tmpname;
  int mode;

  if (!PyArg_ParseTuple (args, (char *) "Ossi:guestfs_debug_upload",
                         &py_g, &filename, &tmpname, &mode))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_debug_upload (g, filename, tmpname, mode);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_DEVICE_INDEX
static PyObject *
guestfs_int_py_device_index (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  const char *device;

  if (!PyArg_ParseTuple (args, (char *) "Os:guestfs_device_index",
                         &py_g, &device))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_device_index (g, device);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  py_r = PyLong_FromLong ((long) r);

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_DF
static PyObject *
guestfs_int_py_df (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  char *r;

  if (!PyArg_ParseTuple (args, (char *) "O:guestfs_df",
                         &py_g))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_df (g);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == NULL) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

#ifdef HAVE_PYSTRING_ASSTRING
  py_r = PyString_FromString (r);
#else
  py_r = PyUnicode_FromString (r);
#endif
  free (r);
  if (py_r == NULL) goto out;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_DF_H
static PyObject *
guestfs_int_py_df_h (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  char *r;

  if (!PyArg_ParseTuple (args, (char *) "O:guestfs_df_h",
                         &py_g))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_df_h (g);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == NULL) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

#ifdef HAVE_PYSTRING_ASSTRING
  py_r = PyString_FromString (r);
#else
  py_r = PyUnicode_FromString (r);
#endif
  free (r);
  if (py_r == NULL) goto out;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_DISK_CREATE
static PyObject *
guestfs_int_py_disk_create (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  struct guestfs_disk_create_argv optargs_s;
  struct guestfs_disk_create_argv *optargs = &optargs_s;
  int r;
  const char *filename;
  const char *format;
  long long size;
  PyObject *py_backingfile;
  PyObject *py_backingformat;
  PyObject *py_preallocation;
  PyObject *py_compat;
  PyObject *py_clustersize;

  optargs_s.bitmask = 0;

  if (!PyArg_ParseTuple (args, (char *) "OssLOOOOO:guestfs_disk_create",
                         &py_g, &filename, &format, &size, &py_backingfile, &py_backingformat, &py_preallocation, &py_compat, &py_clustersize))
    goto out;
  g = get_handle (py_g);

#ifdef GUESTFS_DISK_CREATE_BACKINGFILE_BITMASK
  if (py_backingfile != Py_None) {
    optargs_s.bitmask |= GUESTFS_DISK_CREATE_BACKINGFILE_BITMASK;
#ifdef HAVE_PYSTRING_ASSTRING
    optargs_s.backingfile = PyString_AsString (py_backingfile);
#else
    PyObject *bytes;
    bytes = PyUnicode_AsUTF8String (py_backingfile);
    optargs_s.backingfile = PyBytes_AS_STRING (bytes);
#endif
  }
#endif
#ifdef GUESTFS_DISK_CREATE_BACKINGFORMAT_BITMASK
  if (py_backingformat != Py_None) {
    optargs_s.bitmask |= GUESTFS_DISK_CREATE_BACKINGFORMAT_BITMASK;
#ifdef HAVE_PYSTRING_ASSTRING
    optargs_s.backingformat = PyString_AsString (py_backingformat);
#else
    PyObject *bytes;
    bytes = PyUnicode_AsUTF8String (py_backingformat);
    optargs_s.backingformat = PyBytes_AS_STRING (bytes);
#endif
  }
#endif
#ifdef GUESTFS_DISK_CREATE_PREALLOCATION_BITMASK
  if (py_preallocation != Py_None) {
    optargs_s.bitmask |= GUESTFS_DISK_CREATE_PREALLOCATION_BITMASK;
#ifdef HAVE_PYSTRING_ASSTRING
    optargs_s.preallocation = PyString_AsString (py_preallocation);
#else
    PyObject *bytes;
    bytes = PyUnicode_AsUTF8String (py_preallocation);
    optargs_s.preallocation = PyBytes_AS_STRING (bytes);
#endif
  }
#endif
#ifdef GUESTFS_DISK_CREATE_COMPAT_BITMASK
  if (py_compat != Py_None) {
    optargs_s.bitmask |= GUESTFS_DISK_CREATE_COMPAT_BITMASK;
#ifdef HAVE_PYSTRING_ASSTRING
    optargs_s.compat = PyString_AsString (py_compat);
#else
    PyObject *bytes;
    bytes = PyUnicode_AsUTF8String (py_compat);
    optargs_s.compat = PyBytes_AS_STRING (bytes);
#endif
  }
#endif
#ifdef GUESTFS_DISK_CREATE_CLUSTERSIZE_BITMASK
  if (py_clustersize != Py_None) {
    optargs_s.bitmask |= GUESTFS_DISK_CREATE_CLUSTERSIZE_BITMASK;
    optargs_s.clustersize = PyLong_AsLong (py_clustersize);
    if (PyErr_Occurred ()) goto out;
  }
#endif

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_disk_create_argv (g, filename, format, size, optargs);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_DISK_FORMAT
static PyObject *
guestfs_int_py_disk_format (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  char *r;
  const char *filename;

  if (!PyArg_ParseTuple (args, (char *) "Os:guestfs_disk_format",
                         &py_g, &filename))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_disk_format (g, filename);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == NULL) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

#ifdef HAVE_PYSTRING_ASSTRING
  py_r = PyString_FromString (r);
#else
  py_r = PyUnicode_FromString (r);
#endif
  free (r);
  if (py_r == NULL) goto out;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_DISK_HAS_BACKING_FILE
static PyObject *
guestfs_int_py_disk_has_backing_file (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  const char *filename;

  if (!PyArg_ParseTuple (args, (char *) "Os:guestfs_disk_has_backing_file",
                         &py_g, &filename))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_disk_has_backing_file (g, filename);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  py_r = PyLong_FromLong ((long) r);

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_DISK_VIRTUAL_SIZE
static PyObject *
guestfs_int_py_disk_virtual_size (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int64_t r;
  const char *filename;

  if (!PyArg_ParseTuple (args, (char *) "Os:guestfs_disk_virtual_size",
                         &py_g, &filename))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_disk_virtual_size (g, filename);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  py_r = PyLong_FromLongLong (r);

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_DMESG
static PyObject *
guestfs_int_py_dmesg (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  char *r;

  if (!PyArg_ParseTuple (args, (char *) "O:guestfs_dmesg",
                         &py_g))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_dmesg (g);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == NULL) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

#ifdef HAVE_PYSTRING_ASSTRING
  py_r = PyString_FromString (r);
#else
  py_r = PyUnicode_FromString (r);
#endif
  free (r);
  if (py_r == NULL) goto out;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_DOWNLOAD
static PyObject *
guestfs_int_py_download (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  const char *remotefilename;
  const char *filename;

  if (!PyArg_ParseTuple (args, (char *) "Oss:guestfs_download",
                         &py_g, &remotefilename, &filename))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_download (g, remotefilename, filename);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_DOWNLOAD_OFFSET
static PyObject *
guestfs_int_py_download_offset (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  const char *remotefilename;
  const char *filename;
  long long offset;
  long long size;

  if (!PyArg_ParseTuple (args, (char *) "OssLL:guestfs_download_offset",
                         &py_g, &remotefilename, &filename, &offset, &size))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_download_offset (g, remotefilename, filename, offset, size);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_DROP_CACHES
static PyObject *
guestfs_int_py_drop_caches (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  int whattodrop;

  if (!PyArg_ParseTuple (args, (char *) "Oi:guestfs_drop_caches",
                         &py_g, &whattodrop))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_drop_caches (g, whattodrop);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_DU
static PyObject *
guestfs_int_py_du (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int64_t r;
  const char *path;

  if (!PyArg_ParseTuple (args, (char *) "Os:guestfs_du",
                         &py_g, &path))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_du (g, path);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  py_r = PyLong_FromLongLong (r);

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_E2FSCK
static PyObject *
guestfs_int_py_e2fsck (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  struct guestfs_e2fsck_argv optargs_s;
  struct guestfs_e2fsck_argv *optargs = &optargs_s;
  int r;
  const char *device;
  PyObject *py_correct;
  PyObject *py_forceall;

  optargs_s.bitmask = 0;

  if (!PyArg_ParseTuple (args, (char *) "OsOO:guestfs_e2fsck",
                         &py_g, &device, &py_correct, &py_forceall))
    goto out;
  g = get_handle (py_g);

#ifdef GUESTFS_E2FSCK_CORRECT_BITMASK
  if (py_correct != Py_None) {
    optargs_s.bitmask |= GUESTFS_E2FSCK_CORRECT_BITMASK;
    optargs_s.correct = PyLong_AsLong (py_correct);
    if (PyErr_Occurred ()) goto out;
  }
#endif
#ifdef GUESTFS_E2FSCK_FORCEALL_BITMASK
  if (py_forceall != Py_None) {
    optargs_s.bitmask |= GUESTFS_E2FSCK_FORCEALL_BITMASK;
    optargs_s.forceall = PyLong_AsLong (py_forceall);
    if (PyErr_Occurred ()) goto out;
  }
#endif

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_e2fsck_argv (g, device, optargs);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_E2FSCK_F
static PyObject *
guestfs_int_py_e2fsck_f (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  const char *device;

  if (!PyArg_ParseTuple (args, (char *) "Os:guestfs_e2fsck_f",
                         &py_g, &device))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_e2fsck_f (g, device);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_ECHO_DAEMON
static PyObject *
guestfs_int_py_echo_daemon (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  char *r;
  PyObject *py_words;
  char **words = NULL;

  if (!PyArg_ParseTuple (args, (char *) "OO:guestfs_echo_daemon",
                         &py_g, &py_words))
    goto out;
  g = get_handle (py_g);
  words = get_string_list (py_words);
  if (!words) goto out;

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_echo_daemon (g, words);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == NULL) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

#ifdef HAVE_PYSTRING_ASSTRING
  py_r = PyString_FromString (r);
#else
  py_r = PyUnicode_FromString (r);
#endif
  free (r);
  if (py_r == NULL) goto out;

  PyErr_Clear ();
 out:
  free (words);
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_EGREP
static PyObject *
guestfs_int_py_egrep (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  char **r;
  const char *regex;
  const char *path;

  if (!PyArg_ParseTuple (args, (char *) "Oss:guestfs_egrep",
                         &py_g, &regex, &path))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_egrep (g, regex, path);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == NULL) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  py_r = put_string_list (r);
  guestfs_int_free_string_list (r);

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_EGREPI
static PyObject *
guestfs_int_py_egrepi (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  char **r;
  const char *regex;
  const char *path;

  if (!PyArg_ParseTuple (args, (char *) "Oss:guestfs_egrepi",
                         &py_g, &regex, &path))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_egrepi (g, regex, path);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == NULL) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  py_r = put_string_list (r);
  guestfs_int_free_string_list (r);

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_EQUAL
static PyObject *
guestfs_int_py_equal (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  const char *file1;
  const char *file2;

  if (!PyArg_ParseTuple (args, (char *) "Oss:guestfs_equal",
                         &py_g, &file1, &file2))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_equal (g, file1, file2);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  py_r = PyLong_FromLong ((long) r);

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_EXISTS
static PyObject *
guestfs_int_py_exists (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  const char *path;

  if (!PyArg_ParseTuple (args, (char *) "Os:guestfs_exists",
                         &py_g, &path))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_exists (g, path);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  py_r = PyLong_FromLong ((long) r);

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_EXTLINUX
static PyObject *
guestfs_int_py_extlinux (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  const char *directory;

  if (!PyArg_ParseTuple (args, (char *) "Os:guestfs_extlinux",
                         &py_g, &directory))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_extlinux (g, directory);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_FALLOCATE
static PyObject *
guestfs_int_py_fallocate (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  const char *path;
  int len;

  if (!PyArg_ParseTuple (args, (char *) "Osi:guestfs_fallocate",
                         &py_g, &path, &len))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_fallocate (g, path, len);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_FALLOCATE64
static PyObject *
guestfs_int_py_fallocate64 (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  const char *path;
  long long len;

  if (!PyArg_ParseTuple (args, (char *) "OsL:guestfs_fallocate64",
                         &py_g, &path, &len))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_fallocate64 (g, path, len);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_FEATURE_AVAILABLE
static PyObject *
guestfs_int_py_feature_available (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  PyObject *py_groups;
  char **groups = NULL;

  if (!PyArg_ParseTuple (args, (char *) "OO:guestfs_feature_available",
                         &py_g, &py_groups))
    goto out;
  g = get_handle (py_g);
  groups = get_string_list (py_groups);
  if (!groups) goto out;

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_feature_available (g, groups);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  py_r = PyLong_FromLong ((long) r);

  PyErr_Clear ();
 out:
  free (groups);
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_FGREP
static PyObject *
guestfs_int_py_fgrep (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  char **r;
  const char *pattern;
  const char *path;

  if (!PyArg_ParseTuple (args, (char *) "Oss:guestfs_fgrep",
                         &py_g, &pattern, &path))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_fgrep (g, pattern, path);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == NULL) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  py_r = put_string_list (r);
  guestfs_int_free_string_list (r);

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_FGREPI
static PyObject *
guestfs_int_py_fgrepi (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  char **r;
  const char *pattern;
  const char *path;

  if (!PyArg_ParseTuple (args, (char *) "Oss:guestfs_fgrepi",
                         &py_g, &pattern, &path))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_fgrepi (g, pattern, path);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == NULL) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  py_r = put_string_list (r);
  guestfs_int_free_string_list (r);

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_FILE
static PyObject *
guestfs_int_py_file (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  char *r;
  const char *path;

  if (!PyArg_ParseTuple (args, (char *) "Os:guestfs_file",
                         &py_g, &path))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_file (g, path);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == NULL) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

#ifdef HAVE_PYSTRING_ASSTRING
  py_r = PyString_FromString (r);
#else
  py_r = PyUnicode_FromString (r);
#endif
  free (r);
  if (py_r == NULL) goto out;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_FILE_ARCHITECTURE
static PyObject *
guestfs_int_py_file_architecture (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  char *r;
  const char *filename;

  if (!PyArg_ParseTuple (args, (char *) "Os:guestfs_file_architecture",
                         &py_g, &filename))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_file_architecture (g, filename);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == NULL) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

#ifdef HAVE_PYSTRING_ASSTRING
  py_r = PyString_FromString (r);
#else
  py_r = PyUnicode_FromString (r);
#endif
  free (r);
  if (py_r == NULL) goto out;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_FILESIZE
static PyObject *
guestfs_int_py_filesize (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int64_t r;
  const char *file;

  if (!PyArg_ParseTuple (args, (char *) "Os:guestfs_filesize",
                         &py_g, &file))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_filesize (g, file);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  py_r = PyLong_FromLongLong (r);

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_FILESYSTEM_AVAILABLE
static PyObject *
guestfs_int_py_filesystem_available (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  const char *filesystem;

  if (!PyArg_ParseTuple (args, (char *) "Os:guestfs_filesystem_available",
                         &py_g, &filesystem))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_filesystem_available (g, filesystem);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  py_r = PyLong_FromLong ((long) r);

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_FILL
static PyObject *
guestfs_int_py_fill (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  int c;
  int len;
  const char *path;

  if (!PyArg_ParseTuple (args, (char *) "Oiis:guestfs_fill",
                         &py_g, &c, &len, &path))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_fill (g, c, len, path);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_FILL_DIR
static PyObject *
guestfs_int_py_fill_dir (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  const char *dir;
  int nr;

  if (!PyArg_ParseTuple (args, (char *) "Osi:guestfs_fill_dir",
                         &py_g, &dir, &nr))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_fill_dir (g, dir, nr);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_FILL_PATTERN
static PyObject *
guestfs_int_py_fill_pattern (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  const char *pattern;
  int len;
  const char *path;

  if (!PyArg_ParseTuple (args, (char *) "Osis:guestfs_fill_pattern",
                         &py_g, &pattern, &len, &path))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_fill_pattern (g, pattern, len, path);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_FIND
static PyObject *
guestfs_int_py_find (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  char **r;
  const char *directory;

  if (!PyArg_ParseTuple (args, (char *) "Os:guestfs_find",
                         &py_g, &directory))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_find (g, directory);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == NULL) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  py_r = put_string_list (r);
  guestfs_int_free_string_list (r);

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_FIND0
static PyObject *
guestfs_int_py_find0 (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  const char *directory;
  const char *files;

  if (!PyArg_ParseTuple (args, (char *) "Oss:guestfs_find0",
                         &py_g, &directory, &files))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_find0 (g, directory, files);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_FINDFS_LABEL
static PyObject *
guestfs_int_py_findfs_label (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  char *r;
  const char *label;

  if (!PyArg_ParseTuple (args, (char *) "Os:guestfs_findfs_label",
                         &py_g, &label))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_findfs_label (g, label);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == NULL) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

#ifdef HAVE_PYSTRING_ASSTRING
  py_r = PyString_FromString (r);
#else
  py_r = PyUnicode_FromString (r);
#endif
  free (r);
  if (py_r == NULL) goto out;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_FINDFS_UUID
static PyObject *
guestfs_int_py_findfs_uuid (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  char *r;
  const char *uuid;

  if (!PyArg_ParseTuple (args, (char *) "Os:guestfs_findfs_uuid",
                         &py_g, &uuid))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_findfs_uuid (g, uuid);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == NULL) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

#ifdef HAVE_PYSTRING_ASSTRING
  py_r = PyString_FromString (r);
#else
  py_r = PyUnicode_FromString (r);
#endif
  free (r);
  if (py_r == NULL) goto out;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_FSCK
static PyObject *
guestfs_int_py_fsck (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  const char *fstype;
  const char *device;

  if (!PyArg_ParseTuple (args, (char *) "Oss:guestfs_fsck",
                         &py_g, &fstype, &device))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_fsck (g, fstype, device);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  py_r = PyLong_FromLong ((long) r);

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_FSTRIM
static PyObject *
guestfs_int_py_fstrim (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  struct guestfs_fstrim_argv optargs_s;
  struct guestfs_fstrim_argv *optargs = &optargs_s;
  int r;
  const char *mountpoint;
  PyObject *py_offset;
  PyObject *py_length;
  PyObject *py_minimumfreeextent;

  optargs_s.bitmask = 0;

  if (!PyArg_ParseTuple (args, (char *) "OsOOO:guestfs_fstrim",
                         &py_g, &mountpoint, &py_offset, &py_length, &py_minimumfreeextent))
    goto out;
  g = get_handle (py_g);

#ifdef GUESTFS_FSTRIM_OFFSET_BITMASK
  if (py_offset != Py_None) {
    optargs_s.bitmask |= GUESTFS_FSTRIM_OFFSET_BITMASK;
    optargs_s.offset = PyLong_AsLongLong (py_offset);
    if (PyErr_Occurred ()) goto out;
  }
#endif
#ifdef GUESTFS_FSTRIM_LENGTH_BITMASK
  if (py_length != Py_None) {
    optargs_s.bitmask |= GUESTFS_FSTRIM_LENGTH_BITMASK;
    optargs_s.length = PyLong_AsLongLong (py_length);
    if (PyErr_Occurred ()) goto out;
  }
#endif
#ifdef GUESTFS_FSTRIM_MINIMUMFREEEXTENT_BITMASK
  if (py_minimumfreeextent != Py_None) {
    optargs_s.bitmask |= GUESTFS_FSTRIM_MINIMUMFREEEXTENT_BITMASK;
    optargs_s.minimumfreeextent = PyLong_AsLongLong (py_minimumfreeextent);
    if (PyErr_Occurred ()) goto out;
  }
#endif

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_fstrim_argv (g, mountpoint, optargs);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_GET_APPEND
static PyObject *
guestfs_int_py_get_append (PyObject *self, PyObject *args)
{
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  const char *r;

  if (!PyArg_ParseTuple (args, (char *) "O:guestfs_get_append",
                         &py_g))
    goto out;
  g = get_handle (py_g);

  r = guestfs_get_append (g);


  if (r) {
#ifdef HAVE_PYSTRING_ASSTRING
    py_r = PyString_FromString (r);
#else
    py_r = PyUnicode_FromString (r);
#endif
  } else {
    Py_INCREF (Py_None);
    py_r = Py_None;
  }
  if (py_r == NULL) goto out;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_GET_ATTACH_METHOD
static PyObject *
guestfs_int_py_get_attach_method (PyObject *self, PyObject *args)
{
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  char *r;

  if (!PyArg_ParseTuple (args, (char *) "O:guestfs_get_attach_method",
                         &py_g))
    goto out;
  g = get_handle (py_g);

  r = guestfs_get_attach_method (g);

  if (r == NULL) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

#ifdef HAVE_PYSTRING_ASSTRING
  py_r = PyString_FromString (r);
#else
  py_r = PyUnicode_FromString (r);
#endif
  free (r);
  if (py_r == NULL) goto out;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_GET_AUTOSYNC
static PyObject *
guestfs_int_py_get_autosync (PyObject *self, PyObject *args)
{
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;

  if (!PyArg_ParseTuple (args, (char *) "O:guestfs_get_autosync",
                         &py_g))
    goto out;
  g = get_handle (py_g);

  r = guestfs_get_autosync (g);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  py_r = PyLong_FromLong ((long) r);

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_GET_BACKEND
static PyObject *
guestfs_int_py_get_backend (PyObject *self, PyObject *args)
{
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  char *r;

  if (!PyArg_ParseTuple (args, (char *) "O:guestfs_get_backend",
                         &py_g))
    goto out;
  g = get_handle (py_g);

  r = guestfs_get_backend (g);

  if (r == NULL) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

#ifdef HAVE_PYSTRING_ASSTRING
  py_r = PyString_FromString (r);
#else
  py_r = PyUnicode_FromString (r);
#endif
  free (r);
  if (py_r == NULL) goto out;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_GET_BACKEND_SETTING
static PyObject *
guestfs_int_py_get_backend_setting (PyObject *self, PyObject *args)
{
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  char *r;
  const char *name;

  if (!PyArg_ParseTuple (args, (char *) "Os:guestfs_get_backend_setting",
                         &py_g, &name))
    goto out;
  g = get_handle (py_g);

  r = guestfs_get_backend_setting (g, name);

  if (r == NULL) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

#ifdef HAVE_PYSTRING_ASSTRING
  py_r = PyString_FromString (r);
#else
  py_r = PyUnicode_FromString (r);
#endif
  free (r);
  if (py_r == NULL) goto out;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_GET_BACKEND_SETTINGS
static PyObject *
guestfs_int_py_get_backend_settings (PyObject *self, PyObject *args)
{
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  char **r;

  if (!PyArg_ParseTuple (args, (char *) "O:guestfs_get_backend_settings",
                         &py_g))
    goto out;
  g = get_handle (py_g);

  r = guestfs_get_backend_settings (g);

  if (r == NULL) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  py_r = put_string_list (r);
  guestfs_int_free_string_list (r);

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_GET_CACHEDIR
static PyObject *
guestfs_int_py_get_cachedir (PyObject *self, PyObject *args)
{
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  char *r;

  if (!PyArg_ParseTuple (args, (char *) "O:guestfs_get_cachedir",
                         &py_g))
    goto out;
  g = get_handle (py_g);

  r = guestfs_get_cachedir (g);

  if (r == NULL) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

#ifdef HAVE_PYSTRING_ASSTRING
  py_r = PyString_FromString (r);
#else
  py_r = PyUnicode_FromString (r);
#endif
  free (r);
  if (py_r == NULL) goto out;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_GET_DIRECT
static PyObject *
guestfs_int_py_get_direct (PyObject *self, PyObject *args)
{
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;

  if (!PyArg_ParseTuple (args, (char *) "O:guestfs_get_direct",
                         &py_g))
    goto out;
  g = get_handle (py_g);

  r = guestfs_get_direct (g);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  py_r = PyLong_FromLong ((long) r);

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_GET_E2ATTRS
static PyObject *
guestfs_int_py_get_e2attrs (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  char *r;
  const char *file;

  if (!PyArg_ParseTuple (args, (char *) "Os:guestfs_get_e2attrs",
                         &py_g, &file))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_get_e2attrs (g, file);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == NULL) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

#ifdef HAVE_PYSTRING_ASSTRING
  py_r = PyString_FromString (r);
#else
  py_r = PyUnicode_FromString (r);
#endif
  free (r);
  if (py_r == NULL) goto out;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_GET_E2GENERATION
static PyObject *
guestfs_int_py_get_e2generation (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int64_t r;
  const char *file;

  if (!PyArg_ParseTuple (args, (char *) "Os:guestfs_get_e2generation",
                         &py_g, &file))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_get_e2generation (g, file);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  py_r = PyLong_FromLongLong (r);

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_GET_E2LABEL
static PyObject *
guestfs_int_py_get_e2label (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  char *r;
  const char *device;

  if (!PyArg_ParseTuple (args, (char *) "Os:guestfs_get_e2label",
                         &py_g, &device))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_get_e2label (g, device);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == NULL) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

#ifdef HAVE_PYSTRING_ASSTRING
  py_r = PyString_FromString (r);
#else
  py_r = PyUnicode_FromString (r);
#endif
  free (r);
  if (py_r == NULL) goto out;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_GET_E2UUID
static PyObject *
guestfs_int_py_get_e2uuid (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  char *r;
  const char *device;

  if (!PyArg_ParseTuple (args, (char *) "Os:guestfs_get_e2uuid",
                         &py_g, &device))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_get_e2uuid (g, device);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == NULL) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

#ifdef HAVE_PYSTRING_ASSTRING
  py_r = PyString_FromString (r);
#else
  py_r = PyUnicode_FromString (r);
#endif
  free (r);
  if (py_r == NULL) goto out;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_GET_HV
static PyObject *
guestfs_int_py_get_hv (PyObject *self, PyObject *args)
{
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  char *r;

  if (!PyArg_ParseTuple (args, (char *) "O:guestfs_get_hv",
                         &py_g))
    goto out;
  g = get_handle (py_g);

  r = guestfs_get_hv (g);

  if (r == NULL) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

#ifdef HAVE_PYSTRING_ASSTRING
  py_r = PyString_FromString (r);
#else
  py_r = PyUnicode_FromString (r);
#endif
  free (r);
  if (py_r == NULL) goto out;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_GET_IDENTIFIER
static PyObject *
guestfs_int_py_get_identifier (PyObject *self, PyObject *args)
{
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  const char *r;

  if (!PyArg_ParseTuple (args, (char *) "O:guestfs_get_identifier",
                         &py_g))
    goto out;
  g = get_handle (py_g);

  r = guestfs_get_identifier (g);

  if (r == NULL) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

#ifdef HAVE_PYSTRING_ASSTRING
  py_r = PyString_FromString (r);
#else
  py_r = PyUnicode_FromString (r);
#endif
  if (py_r == NULL) goto out;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_GET_LIBVIRT_REQUESTED_CREDENTIAL_CHALLENGE
static PyObject *
guestfs_int_py_get_libvirt_requested_credential_challenge (PyObject *self, PyObject *args)
{
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  char *r;
  int index;

  if (!PyArg_ParseTuple (args, (char *) "Oi:guestfs_get_libvirt_requested_credential_challenge",
                         &py_g, &index))
    goto out;
  g = get_handle (py_g);

  r = guestfs_get_libvirt_requested_credential_challenge (g, index);

  if (r == NULL) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

#ifdef HAVE_PYSTRING_ASSTRING
  py_r = PyString_FromString (r);
#else
  py_r = PyUnicode_FromString (r);
#endif
  free (r);
  if (py_r == NULL) goto out;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_GET_LIBVIRT_REQUESTED_CREDENTIAL_DEFRESULT
static PyObject *
guestfs_int_py_get_libvirt_requested_credential_defresult (PyObject *self, PyObject *args)
{
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  char *r;
  int index;

  if (!PyArg_ParseTuple (args, (char *) "Oi:guestfs_get_libvirt_requested_credential_defresult",
                         &py_g, &index))
    goto out;
  g = get_handle (py_g);

  r = guestfs_get_libvirt_requested_credential_defresult (g, index);

  if (r == NULL) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

#ifdef HAVE_PYSTRING_ASSTRING
  py_r = PyString_FromString (r);
#else
  py_r = PyUnicode_FromString (r);
#endif
  free (r);
  if (py_r == NULL) goto out;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_GET_LIBVIRT_REQUESTED_CREDENTIAL_PROMPT
static PyObject *
guestfs_int_py_get_libvirt_requested_credential_prompt (PyObject *self, PyObject *args)
{
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  char *r;
  int index;

  if (!PyArg_ParseTuple (args, (char *) "Oi:guestfs_get_libvirt_requested_credential_prompt",
                         &py_g, &index))
    goto out;
  g = get_handle (py_g);

  r = guestfs_get_libvirt_requested_credential_prompt (g, index);

  if (r == NULL) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

#ifdef HAVE_PYSTRING_ASSTRING
  py_r = PyString_FromString (r);
#else
  py_r = PyUnicode_FromString (r);
#endif
  free (r);
  if (py_r == NULL) goto out;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_GET_LIBVIRT_REQUESTED_CREDENTIALS
static PyObject *
guestfs_int_py_get_libvirt_requested_credentials (PyObject *self, PyObject *args)
{
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  char **r;

  if (!PyArg_ParseTuple (args, (char *) "O:guestfs_get_libvirt_requested_credentials",
                         &py_g))
    goto out;
  g = get_handle (py_g);

  r = guestfs_get_libvirt_requested_credentials (g);

  if (r == NULL) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  py_r = put_string_list (r);
  guestfs_int_free_string_list (r);

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_GET_MEMSIZE
static PyObject *
guestfs_int_py_get_memsize (PyObject *self, PyObject *args)
{
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;

  if (!PyArg_ParseTuple (args, (char *) "O:guestfs_get_memsize",
                         &py_g))
    goto out;
  g = get_handle (py_g);

  r = guestfs_get_memsize (g);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  py_r = PyLong_FromLong ((long) r);

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_GET_NETWORK
static PyObject *
guestfs_int_py_get_network (PyObject *self, PyObject *args)
{
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;

  if (!PyArg_ParseTuple (args, (char *) "O:guestfs_get_network",
                         &py_g))
    goto out;
  g = get_handle (py_g);

  r = guestfs_get_network (g);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  py_r = PyLong_FromLong ((long) r);

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_GET_PATH
static PyObject *
guestfs_int_py_get_path (PyObject *self, PyObject *args)
{
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  const char *r;

  if (!PyArg_ParseTuple (args, (char *) "O:guestfs_get_path",
                         &py_g))
    goto out;
  g = get_handle (py_g);

  r = guestfs_get_path (g);

  if (r == NULL) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

#ifdef HAVE_PYSTRING_ASSTRING
  py_r = PyString_FromString (r);
#else
  py_r = PyUnicode_FromString (r);
#endif
  if (py_r == NULL) goto out;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_GET_PGROUP
static PyObject *
guestfs_int_py_get_pgroup (PyObject *self, PyObject *args)
{
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;

  if (!PyArg_ParseTuple (args, (char *) "O:guestfs_get_pgroup",
                         &py_g))
    goto out;
  g = get_handle (py_g);

  r = guestfs_get_pgroup (g);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  py_r = PyLong_FromLong ((long) r);

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_GET_PID
static PyObject *
guestfs_int_py_get_pid (PyObject *self, PyObject *args)
{
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;

  if (!PyArg_ParseTuple (args, (char *) "O:guestfs_get_pid",
                         &py_g))
    goto out;
  g = get_handle (py_g);

  r = guestfs_get_pid (g);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  py_r = PyLong_FromLong ((long) r);

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_GET_PROGRAM
static PyObject *
guestfs_int_py_get_program (PyObject *self, PyObject *args)
{
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  const char *r;

  if (!PyArg_ParseTuple (args, (char *) "O:guestfs_get_program",
                         &py_g))
    goto out;
  g = get_handle (py_g);

  r = guestfs_get_program (g);

  if (r == NULL) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

#ifdef HAVE_PYSTRING_ASSTRING
  py_r = PyString_FromString (r);
#else
  py_r = PyUnicode_FromString (r);
#endif
  if (py_r == NULL) goto out;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_GET_QEMU
static PyObject *
guestfs_int_py_get_qemu (PyObject *self, PyObject *args)
{
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  const char *r;

  if (!PyArg_ParseTuple (args, (char *) "O:guestfs_get_qemu",
                         &py_g))
    goto out;
  g = get_handle (py_g);

  r = guestfs_get_qemu (g);

  if (r == NULL) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

#ifdef HAVE_PYSTRING_ASSTRING
  py_r = PyString_FromString (r);
#else
  py_r = PyUnicode_FromString (r);
#endif
  if (py_r == NULL) goto out;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_GET_RECOVERY_PROC
static PyObject *
guestfs_int_py_get_recovery_proc (PyObject *self, PyObject *args)
{
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;

  if (!PyArg_ParseTuple (args, (char *) "O:guestfs_get_recovery_proc",
                         &py_g))
    goto out;
  g = get_handle (py_g);

  r = guestfs_get_recovery_proc (g);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  py_r = PyLong_FromLong ((long) r);

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_GET_SELINUX
static PyObject *
guestfs_int_py_get_selinux (PyObject *self, PyObject *args)
{
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;

  if (!PyArg_ParseTuple (args, (char *) "O:guestfs_get_selinux",
                         &py_g))
    goto out;
  g = get_handle (py_g);

  r = guestfs_get_selinux (g);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  py_r = PyLong_FromLong ((long) r);

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_GET_SMP
static PyObject *
guestfs_int_py_get_smp (PyObject *self, PyObject *args)
{
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;

  if (!PyArg_ParseTuple (args, (char *) "O:guestfs_get_smp",
                         &py_g))
    goto out;
  g = get_handle (py_g);

  r = guestfs_get_smp (g);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  py_r = PyLong_FromLong ((long) r);

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_GET_STATE
static PyObject *
guestfs_int_py_get_state (PyObject *self, PyObject *args)
{
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;

  if (!PyArg_ParseTuple (args, (char *) "O:guestfs_get_state",
                         &py_g))
    goto out;
  g = get_handle (py_g);

  r = guestfs_get_state (g);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  py_r = PyLong_FromLong ((long) r);

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_GET_TMPDIR
static PyObject *
guestfs_int_py_get_tmpdir (PyObject *self, PyObject *args)
{
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  char *r;

  if (!PyArg_ParseTuple (args, (char *) "O:guestfs_get_tmpdir",
                         &py_g))
    goto out;
  g = get_handle (py_g);

  r = guestfs_get_tmpdir (g);

  if (r == NULL) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

#ifdef HAVE_PYSTRING_ASSTRING
  py_r = PyString_FromString (r);
#else
  py_r = PyUnicode_FromString (r);
#endif
  free (r);
  if (py_r == NULL) goto out;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_GET_TRACE
static PyObject *
guestfs_int_py_get_trace (PyObject *self, PyObject *args)
{
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;

  if (!PyArg_ParseTuple (args, (char *) "O:guestfs_get_trace",
                         &py_g))
    goto out;
  g = get_handle (py_g);

  r = guestfs_get_trace (g);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  py_r = PyLong_FromLong ((long) r);

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_GET_UMASK
static PyObject *
guestfs_int_py_get_umask (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;

  if (!PyArg_ParseTuple (args, (char *) "O:guestfs_get_umask",
                         &py_g))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_get_umask (g);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  py_r = PyLong_FromLong ((long) r);

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_GET_VERBOSE
static PyObject *
guestfs_int_py_get_verbose (PyObject *self, PyObject *args)
{
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;

  if (!PyArg_ParseTuple (args, (char *) "O:guestfs_get_verbose",
                         &py_g))
    goto out;
  g = get_handle (py_g);

  r = guestfs_get_verbose (g);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  py_r = PyLong_FromLong ((long) r);

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_GETCON
static PyObject *
guestfs_int_py_getcon (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  char *r;

  if (!PyArg_ParseTuple (args, (char *) "O:guestfs_getcon",
                         &py_g))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_getcon (g);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == NULL) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

#ifdef HAVE_PYSTRING_ASSTRING
  py_r = PyString_FromString (r);
#else
  py_r = PyUnicode_FromString (r);
#endif
  free (r);
  if (py_r == NULL) goto out;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_GETXATTR
static PyObject *
guestfs_int_py_getxattr (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  char *r;
  size_t size;
  const char *path;
  const char *name;

  if (!PyArg_ParseTuple (args, (char *) "Oss:guestfs_getxattr",
                         &py_g, &path, &name))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_getxattr (g, path, name, &size);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == NULL) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

#ifdef HAVE_PYSTRING_ASSTRING
  py_r = PyString_FromStringAndSize (r, size);
#else
  py_r = PyBytes_FromStringAndSize (r, size);
#endif
  free (r);
  if (py_r == NULL) goto out;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_GETXATTRS
static PyObject *
guestfs_int_py_getxattrs (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  struct guestfs_xattr_list *r;
  const char *path;

  if (!PyArg_ParseTuple (args, (char *) "Os:guestfs_getxattrs",
                         &py_g, &path))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_getxattrs (g, path);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == NULL) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  py_r = put_xattr_list (r);
  guestfs_free_xattr_list (r);

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_GLOB_EXPAND
static PyObject *
guestfs_int_py_glob_expand (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  char **r;
  const char *pattern;

  if (!PyArg_ParseTuple (args, (char *) "Os:guestfs_glob_expand",
                         &py_g, &pattern))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_glob_expand (g, pattern);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == NULL) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  py_r = put_string_list (r);
  guestfs_int_free_string_list (r);

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_GREP_OPTS
static PyObject *
guestfs_int_py_grep (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  struct guestfs_grep_opts_argv optargs_s;
  struct guestfs_grep_opts_argv *optargs = &optargs_s;
  char **r;
  const char *regex;
  const char *path;
  PyObject *py_extended;
  PyObject *py_fixed;
  PyObject *py_insensitive;
  PyObject *py_compressed;

  optargs_s.bitmask = 0;

  if (!PyArg_ParseTuple (args, (char *) "OssOOOO:guestfs_grep",
                         &py_g, &regex, &path, &py_extended, &py_fixed, &py_insensitive, &py_compressed))
    goto out;
  g = get_handle (py_g);

#ifdef GUESTFS_GREP_OPTS_EXTENDED_BITMASK
  if (py_extended != Py_None) {
    optargs_s.bitmask |= GUESTFS_GREP_OPTS_EXTENDED_BITMASK;
    optargs_s.extended = PyLong_AsLong (py_extended);
    if (PyErr_Occurred ()) goto out;
  }
#endif
#ifdef GUESTFS_GREP_OPTS_FIXED_BITMASK
  if (py_fixed != Py_None) {
    optargs_s.bitmask |= GUESTFS_GREP_OPTS_FIXED_BITMASK;
    optargs_s.fixed = PyLong_AsLong (py_fixed);
    if (PyErr_Occurred ()) goto out;
  }
#endif
#ifdef GUESTFS_GREP_OPTS_INSENSITIVE_BITMASK
  if (py_insensitive != Py_None) {
    optargs_s.bitmask |= GUESTFS_GREP_OPTS_INSENSITIVE_BITMASK;
    optargs_s.insensitive = PyLong_AsLong (py_insensitive);
    if (PyErr_Occurred ()) goto out;
  }
#endif
#ifdef GUESTFS_GREP_OPTS_COMPRESSED_BITMASK
  if (py_compressed != Py_None) {
    optargs_s.bitmask |= GUESTFS_GREP_OPTS_COMPRESSED_BITMASK;
    optargs_s.compressed = PyLong_AsLong (py_compressed);
    if (PyErr_Occurred ()) goto out;
  }
#endif

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_grep_opts_argv (g, regex, path, optargs);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == NULL) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  py_r = put_string_list (r);
  guestfs_int_free_string_list (r);

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_GREPI
static PyObject *
guestfs_int_py_grepi (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  char **r;
  const char *regex;
  const char *path;

  if (!PyArg_ParseTuple (args, (char *) "Oss:guestfs_grepi",
                         &py_g, &regex, &path))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_grepi (g, regex, path);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == NULL) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  py_r = put_string_list (r);
  guestfs_int_free_string_list (r);

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_GRUB_INSTALL
static PyObject *
guestfs_int_py_grub_install (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  const char *root;
  const char *device;

  if (!PyArg_ParseTuple (args, (char *) "Oss:guestfs_grub_install",
                         &py_g, &root, &device))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_grub_install (g, root, device);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_HEAD
static PyObject *
guestfs_int_py_head (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  char **r;
  const char *path;

  if (!PyArg_ParseTuple (args, (char *) "Os:guestfs_head",
                         &py_g, &path))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_head (g, path);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == NULL) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  py_r = put_string_list (r);
  guestfs_int_free_string_list (r);

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_HEAD_N
static PyObject *
guestfs_int_py_head_n (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  char **r;
  int nrlines;
  const char *path;

  if (!PyArg_ParseTuple (args, (char *) "Ois:guestfs_head_n",
                         &py_g, &nrlines, &path))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_head_n (g, nrlines, path);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == NULL) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  py_r = put_string_list (r);
  guestfs_int_free_string_list (r);

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_HEXDUMP
static PyObject *
guestfs_int_py_hexdump (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  char *r;
  const char *path;

  if (!PyArg_ParseTuple (args, (char *) "Os:guestfs_hexdump",
                         &py_g, &path))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_hexdump (g, path);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == NULL) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

#ifdef HAVE_PYSTRING_ASSTRING
  py_r = PyString_FromString (r);
#else
  py_r = PyUnicode_FromString (r);
#endif
  free (r);
  if (py_r == NULL) goto out;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_HIVEX_CLOSE
static PyObject *
guestfs_int_py_hivex_close (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;

  if (!PyArg_ParseTuple (args, (char *) "O:guestfs_hivex_close",
                         &py_g))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_hivex_close (g);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_HIVEX_COMMIT
static PyObject *
guestfs_int_py_hivex_commit (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  const char *filename;

  if (!PyArg_ParseTuple (args, (char *) "Oz:guestfs_hivex_commit",
                         &py_g, &filename))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_hivex_commit (g, filename);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_HIVEX_NODE_ADD_CHILD
static PyObject *
guestfs_int_py_hivex_node_add_child (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int64_t r;
  long long parent;
  const char *name;

  if (!PyArg_ParseTuple (args, (char *) "OLs:guestfs_hivex_node_add_child",
                         &py_g, &parent, &name))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_hivex_node_add_child (g, parent, name);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  py_r = PyLong_FromLongLong (r);

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_HIVEX_NODE_CHILDREN
static PyObject *
guestfs_int_py_hivex_node_children (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  struct guestfs_hivex_node_list *r;
  long long nodeh;

  if (!PyArg_ParseTuple (args, (char *) "OL:guestfs_hivex_node_children",
                         &py_g, &nodeh))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_hivex_node_children (g, nodeh);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == NULL) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  py_r = put_hivex_node_list (r);
  guestfs_free_hivex_node_list (r);

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_HIVEX_NODE_DELETE_CHILD
static PyObject *
guestfs_int_py_hivex_node_delete_child (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  long long nodeh;

  if (!PyArg_ParseTuple (args, (char *) "OL:guestfs_hivex_node_delete_child",
                         &py_g, &nodeh))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_hivex_node_delete_child (g, nodeh);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_HIVEX_NODE_GET_CHILD
static PyObject *
guestfs_int_py_hivex_node_get_child (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int64_t r;
  long long nodeh;
  const char *name;

  if (!PyArg_ParseTuple (args, (char *) "OLs:guestfs_hivex_node_get_child",
                         &py_g, &nodeh, &name))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_hivex_node_get_child (g, nodeh, name);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  py_r = PyLong_FromLongLong (r);

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_HIVEX_NODE_GET_VALUE
static PyObject *
guestfs_int_py_hivex_node_get_value (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int64_t r;
  long long nodeh;
  const char *key;

  if (!PyArg_ParseTuple (args, (char *) "OLs:guestfs_hivex_node_get_value",
                         &py_g, &nodeh, &key))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_hivex_node_get_value (g, nodeh, key);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  py_r = PyLong_FromLongLong (r);

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_HIVEX_NODE_NAME
static PyObject *
guestfs_int_py_hivex_node_name (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  char *r;
  long long nodeh;

  if (!PyArg_ParseTuple (args, (char *) "OL:guestfs_hivex_node_name",
                         &py_g, &nodeh))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_hivex_node_name (g, nodeh);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == NULL) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

#ifdef HAVE_PYSTRING_ASSTRING
  py_r = PyString_FromString (r);
#else
  py_r = PyUnicode_FromString (r);
#endif
  free (r);
  if (py_r == NULL) goto out;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_HIVEX_NODE_PARENT
static PyObject *
guestfs_int_py_hivex_node_parent (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int64_t r;
  long long nodeh;

  if (!PyArg_ParseTuple (args, (char *) "OL:guestfs_hivex_node_parent",
                         &py_g, &nodeh))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_hivex_node_parent (g, nodeh);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  py_r = PyLong_FromLongLong (r);

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_HIVEX_NODE_SET_VALUE
static PyObject *
guestfs_int_py_hivex_node_set_value (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  long long nodeh;
  const char *key;
  long long t;
  const char *val;
  Py_ssize_t val_size;

  if (!PyArg_ParseTuple (args, (char *) "OLsLs#:guestfs_hivex_node_set_value",
                         &py_g, &nodeh, &key, &t, &val, &val_size))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_hivex_node_set_value (g, nodeh, key, t, val, val_size);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_HIVEX_NODE_VALUES
static PyObject *
guestfs_int_py_hivex_node_values (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  struct guestfs_hivex_value_list *r;
  long long nodeh;

  if (!PyArg_ParseTuple (args, (char *) "OL:guestfs_hivex_node_values",
                         &py_g, &nodeh))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_hivex_node_values (g, nodeh);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == NULL) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  py_r = put_hivex_value_list (r);
  guestfs_free_hivex_value_list (r);

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_HIVEX_OPEN
static PyObject *
guestfs_int_py_hivex_open (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  struct guestfs_hivex_open_argv optargs_s;
  struct guestfs_hivex_open_argv *optargs = &optargs_s;
  int r;
  const char *filename;
  PyObject *py_verbose;
  PyObject *py_debug;
  PyObject *py_write;

  optargs_s.bitmask = 0;

  if (!PyArg_ParseTuple (args, (char *) "OsOOO:guestfs_hivex_open",
                         &py_g, &filename, &py_verbose, &py_debug, &py_write))
    goto out;
  g = get_handle (py_g);

#ifdef GUESTFS_HIVEX_OPEN_VERBOSE_BITMASK
  if (py_verbose != Py_None) {
    optargs_s.bitmask |= GUESTFS_HIVEX_OPEN_VERBOSE_BITMASK;
    optargs_s.verbose = PyLong_AsLong (py_verbose);
    if (PyErr_Occurred ()) goto out;
  }
#endif
#ifdef GUESTFS_HIVEX_OPEN_DEBUG_BITMASK
  if (py_debug != Py_None) {
    optargs_s.bitmask |= GUESTFS_HIVEX_OPEN_DEBUG_BITMASK;
    optargs_s.debug = PyLong_AsLong (py_debug);
    if (PyErr_Occurred ()) goto out;
  }
#endif
#ifdef GUESTFS_HIVEX_OPEN_WRITE_BITMASK
  if (py_write != Py_None) {
    optargs_s.bitmask |= GUESTFS_HIVEX_OPEN_WRITE_BITMASK;
    optargs_s.write = PyLong_AsLong (py_write);
    if (PyErr_Occurred ()) goto out;
  }
#endif

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_hivex_open_argv (g, filename, optargs);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_HIVEX_ROOT
static PyObject *
guestfs_int_py_hivex_root (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int64_t r;

  if (!PyArg_ParseTuple (args, (char *) "O:guestfs_hivex_root",
                         &py_g))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_hivex_root (g);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  py_r = PyLong_FromLongLong (r);

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_HIVEX_VALUE_KEY
static PyObject *
guestfs_int_py_hivex_value_key (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  char *r;
  long long valueh;

  if (!PyArg_ParseTuple (args, (char *) "OL:guestfs_hivex_value_key",
                         &py_g, &valueh))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_hivex_value_key (g, valueh);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == NULL) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

#ifdef HAVE_PYSTRING_ASSTRING
  py_r = PyString_FromString (r);
#else
  py_r = PyUnicode_FromString (r);
#endif
  free (r);
  if (py_r == NULL) goto out;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_HIVEX_VALUE_TYPE
static PyObject *
guestfs_int_py_hivex_value_type (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int64_t r;
  long long valueh;

  if (!PyArg_ParseTuple (args, (char *) "OL:guestfs_hivex_value_type",
                         &py_g, &valueh))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_hivex_value_type (g, valueh);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  py_r = PyLong_FromLongLong (r);

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_HIVEX_VALUE_UTF8
static PyObject *
guestfs_int_py_hivex_value_utf8 (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  char *r;
  long long valueh;

  if (!PyArg_ParseTuple (args, (char *) "OL:guestfs_hivex_value_utf8",
                         &py_g, &valueh))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_hivex_value_utf8 (g, valueh);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == NULL) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

#ifdef HAVE_PYSTRING_ASSTRING
  py_r = PyString_FromString (r);
#else
  py_r = PyUnicode_FromString (r);
#endif
  free (r);
  if (py_r == NULL) goto out;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_HIVEX_VALUE_VALUE
static PyObject *
guestfs_int_py_hivex_value_value (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  char *r;
  size_t size;
  long long valueh;

  if (!PyArg_ParseTuple (args, (char *) "OL:guestfs_hivex_value_value",
                         &py_g, &valueh))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_hivex_value_value (g, valueh, &size);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == NULL) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

#ifdef HAVE_PYSTRING_ASSTRING
  py_r = PyString_FromStringAndSize (r, size);
#else
  py_r = PyBytes_FromStringAndSize (r, size);
#endif
  free (r);
  if (py_r == NULL) goto out;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_INITRD_CAT
static PyObject *
guestfs_int_py_initrd_cat (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  char *r;
  size_t size;
  const char *initrdpath;
  const char *filename;

  if (!PyArg_ParseTuple (args, (char *) "Oss:guestfs_initrd_cat",
                         &py_g, &initrdpath, &filename))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_initrd_cat (g, initrdpath, filename, &size);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == NULL) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

#ifdef HAVE_PYSTRING_ASSTRING
  py_r = PyString_FromStringAndSize (r, size);
#else
  py_r = PyBytes_FromStringAndSize (r, size);
#endif
  free (r);
  if (py_r == NULL) goto out;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_INITRD_LIST
static PyObject *
guestfs_int_py_initrd_list (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  char **r;
  const char *path;

  if (!PyArg_ParseTuple (args, (char *) "Os:guestfs_initrd_list",
                         &py_g, &path))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_initrd_list (g, path);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == NULL) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  py_r = put_string_list (r);
  guestfs_int_free_string_list (r);

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_INOTIFY_ADD_WATCH
static PyObject *
guestfs_int_py_inotify_add_watch (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int64_t r;
  const char *path;
  int mask;

  if (!PyArg_ParseTuple (args, (char *) "Osi:guestfs_inotify_add_watch",
                         &py_g, &path, &mask))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_inotify_add_watch (g, path, mask);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  py_r = PyLong_FromLongLong (r);

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_INOTIFY_CLOSE
static PyObject *
guestfs_int_py_inotify_close (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;

  if (!PyArg_ParseTuple (args, (char *) "O:guestfs_inotify_close",
                         &py_g))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_inotify_close (g);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_INOTIFY_FILES
static PyObject *
guestfs_int_py_inotify_files (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  char **r;

  if (!PyArg_ParseTuple (args, (char *) "O:guestfs_inotify_files",
                         &py_g))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_inotify_files (g);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == NULL) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  py_r = put_string_list (r);
  guestfs_int_free_string_list (r);

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_INOTIFY_INIT
static PyObject *
guestfs_int_py_inotify_init (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  int maxevents;

  if (!PyArg_ParseTuple (args, (char *) "Oi:guestfs_inotify_init",
                         &py_g, &maxevents))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_inotify_init (g, maxevents);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_INOTIFY_READ
static PyObject *
guestfs_int_py_inotify_read (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  struct guestfs_inotify_event_list *r;

  if (!PyArg_ParseTuple (args, (char *) "O:guestfs_inotify_read",
                         &py_g))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_inotify_read (g);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == NULL) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  py_r = put_inotify_event_list (r);
  guestfs_free_inotify_event_list (r);

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_INOTIFY_RM_WATCH
static PyObject *
guestfs_int_py_inotify_rm_watch (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  int wd;

  if (!PyArg_ParseTuple (args, (char *) "Oi:guestfs_inotify_rm_watch",
                         &py_g, &wd))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_inotify_rm_watch (g, wd);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_INSPECT_GET_ARCH
static PyObject *
guestfs_int_py_inspect_get_arch (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  char *r;
  const char *root;

  if (!PyArg_ParseTuple (args, (char *) "Os:guestfs_inspect_get_arch",
                         &py_g, &root))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_inspect_get_arch (g, root);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == NULL) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

#ifdef HAVE_PYSTRING_ASSTRING
  py_r = PyString_FromString (r);
#else
  py_r = PyUnicode_FromString (r);
#endif
  free (r);
  if (py_r == NULL) goto out;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_INSPECT_GET_DISTRO
static PyObject *
guestfs_int_py_inspect_get_distro (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  char *r;
  const char *root;

  if (!PyArg_ParseTuple (args, (char *) "Os:guestfs_inspect_get_distro",
                         &py_g, &root))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_inspect_get_distro (g, root);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == NULL) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

#ifdef HAVE_PYSTRING_ASSTRING
  py_r = PyString_FromString (r);
#else
  py_r = PyUnicode_FromString (r);
#endif
  free (r);
  if (py_r == NULL) goto out;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_INSPECT_GET_DRIVE_MAPPINGS
static PyObject *
guestfs_int_py_inspect_get_drive_mappings (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  char **r;
  const char *root;

  if (!PyArg_ParseTuple (args, (char *) "Os:guestfs_inspect_get_drive_mappings",
                         &py_g, &root))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_inspect_get_drive_mappings (g, root);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == NULL) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  py_r = put_table (r);
  guestfs_int_free_string_list (r);

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_INSPECT_GET_FILESYSTEMS
static PyObject *
guestfs_int_py_inspect_get_filesystems (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  char **r;
  const char *root;

  if (!PyArg_ParseTuple (args, (char *) "Os:guestfs_inspect_get_filesystems",
                         &py_g, &root))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_inspect_get_filesystems (g, root);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == NULL) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  py_r = put_string_list (r);
  guestfs_int_free_string_list (r);

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_INSPECT_GET_FORMAT
static PyObject *
guestfs_int_py_inspect_get_format (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  char *r;
  const char *root;

  if (!PyArg_ParseTuple (args, (char *) "Os:guestfs_inspect_get_format",
                         &py_g, &root))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_inspect_get_format (g, root);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == NULL) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

#ifdef HAVE_PYSTRING_ASSTRING
  py_r = PyString_FromString (r);
#else
  py_r = PyUnicode_FromString (r);
#endif
  free (r);
  if (py_r == NULL) goto out;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_INSPECT_GET_HOSTNAME
static PyObject *
guestfs_int_py_inspect_get_hostname (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  char *r;
  const char *root;

  if (!PyArg_ParseTuple (args, (char *) "Os:guestfs_inspect_get_hostname",
                         &py_g, &root))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_inspect_get_hostname (g, root);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == NULL) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

#ifdef HAVE_PYSTRING_ASSTRING
  py_r = PyString_FromString (r);
#else
  py_r = PyUnicode_FromString (r);
#endif
  free (r);
  if (py_r == NULL) goto out;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_INSPECT_GET_ICON
static PyObject *
guestfs_int_py_inspect_get_icon (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  struct guestfs_inspect_get_icon_argv optargs_s;
  struct guestfs_inspect_get_icon_argv *optargs = &optargs_s;
  char *r;
  size_t size;
  const char *root;
  PyObject *py_favicon;
  PyObject *py_highquality;

  optargs_s.bitmask = 0;

  if (!PyArg_ParseTuple (args, (char *) "OsOO:guestfs_inspect_get_icon",
                         &py_g, &root, &py_favicon, &py_highquality))
    goto out;
  g = get_handle (py_g);

#ifdef GUESTFS_INSPECT_GET_ICON_FAVICON_BITMASK
  if (py_favicon != Py_None) {
    optargs_s.bitmask |= GUESTFS_INSPECT_GET_ICON_FAVICON_BITMASK;
    optargs_s.favicon = PyLong_AsLong (py_favicon);
    if (PyErr_Occurred ()) goto out;
  }
#endif
#ifdef GUESTFS_INSPECT_GET_ICON_HIGHQUALITY_BITMASK
  if (py_highquality != Py_None) {
    optargs_s.bitmask |= GUESTFS_INSPECT_GET_ICON_HIGHQUALITY_BITMASK;
    optargs_s.highquality = PyLong_AsLong (py_highquality);
    if (PyErr_Occurred ()) goto out;
  }
#endif

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_inspect_get_icon_argv (g, root, &size, optargs);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == NULL) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

#ifdef HAVE_PYSTRING_ASSTRING
  py_r = PyString_FromStringAndSize (r, size);
#else
  py_r = PyBytes_FromStringAndSize (r, size);
#endif
  free (r);
  if (py_r == NULL) goto out;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_INSPECT_GET_MAJOR_VERSION
static PyObject *
guestfs_int_py_inspect_get_major_version (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  const char *root;

  if (!PyArg_ParseTuple (args, (char *) "Os:guestfs_inspect_get_major_version",
                         &py_g, &root))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_inspect_get_major_version (g, root);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  py_r = PyLong_FromLong ((long) r);

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_INSPECT_GET_MINOR_VERSION
static PyObject *
guestfs_int_py_inspect_get_minor_version (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  const char *root;

  if (!PyArg_ParseTuple (args, (char *) "Os:guestfs_inspect_get_minor_version",
                         &py_g, &root))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_inspect_get_minor_version (g, root);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  py_r = PyLong_FromLong ((long) r);

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_INSPECT_GET_MOUNTPOINTS
static PyObject *
guestfs_int_py_inspect_get_mountpoints (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  char **r;
  const char *root;

  if (!PyArg_ParseTuple (args, (char *) "Os:guestfs_inspect_get_mountpoints",
                         &py_g, &root))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_inspect_get_mountpoints (g, root);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == NULL) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  py_r = put_table (r);
  guestfs_int_free_string_list (r);

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_INSPECT_GET_PACKAGE_FORMAT
static PyObject *
guestfs_int_py_inspect_get_package_format (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  char *r;
  const char *root;

  if (!PyArg_ParseTuple (args, (char *) "Os:guestfs_inspect_get_package_format",
                         &py_g, &root))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_inspect_get_package_format (g, root);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == NULL) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

#ifdef HAVE_PYSTRING_ASSTRING
  py_r = PyString_FromString (r);
#else
  py_r = PyUnicode_FromString (r);
#endif
  free (r);
  if (py_r == NULL) goto out;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_INSPECT_GET_PACKAGE_MANAGEMENT
static PyObject *
guestfs_int_py_inspect_get_package_management (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  char *r;
  const char *root;

  if (!PyArg_ParseTuple (args, (char *) "Os:guestfs_inspect_get_package_management",
                         &py_g, &root))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_inspect_get_package_management (g, root);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == NULL) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

#ifdef HAVE_PYSTRING_ASSTRING
  py_r = PyString_FromString (r);
#else
  py_r = PyUnicode_FromString (r);
#endif
  free (r);
  if (py_r == NULL) goto out;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_INSPECT_GET_PRODUCT_NAME
static PyObject *
guestfs_int_py_inspect_get_product_name (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  char *r;
  const char *root;

  if (!PyArg_ParseTuple (args, (char *) "Os:guestfs_inspect_get_product_name",
                         &py_g, &root))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_inspect_get_product_name (g, root);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == NULL) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

#ifdef HAVE_PYSTRING_ASSTRING
  py_r = PyString_FromString (r);
#else
  py_r = PyUnicode_FromString (r);
#endif
  free (r);
  if (py_r == NULL) goto out;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_INSPECT_GET_PRODUCT_VARIANT
static PyObject *
guestfs_int_py_inspect_get_product_variant (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  char *r;
  const char *root;

  if (!PyArg_ParseTuple (args, (char *) "Os:guestfs_inspect_get_product_variant",
                         &py_g, &root))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_inspect_get_product_variant (g, root);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == NULL) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

#ifdef HAVE_PYSTRING_ASSTRING
  py_r = PyString_FromString (r);
#else
  py_r = PyUnicode_FromString (r);
#endif
  free (r);
  if (py_r == NULL) goto out;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_INSPECT_GET_ROOTS
static PyObject *
guestfs_int_py_inspect_get_roots (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  char **r;

  if (!PyArg_ParseTuple (args, (char *) "O:guestfs_inspect_get_roots",
                         &py_g))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_inspect_get_roots (g);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == NULL) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  py_r = put_string_list (r);
  guestfs_int_free_string_list (r);

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_INSPECT_GET_TYPE
static PyObject *
guestfs_int_py_inspect_get_type (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  char *r;
  const char *root;

  if (!PyArg_ParseTuple (args, (char *) "Os:guestfs_inspect_get_type",
                         &py_g, &root))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_inspect_get_type (g, root);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == NULL) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

#ifdef HAVE_PYSTRING_ASSTRING
  py_r = PyString_FromString (r);
#else
  py_r = PyUnicode_FromString (r);
#endif
  free (r);
  if (py_r == NULL) goto out;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_INSPECT_GET_WINDOWS_CURRENT_CONTROL_SET
static PyObject *
guestfs_int_py_inspect_get_windows_current_control_set (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  char *r;
  const char *root;

  if (!PyArg_ParseTuple (args, (char *) "Os:guestfs_inspect_get_windows_current_control_set",
                         &py_g, &root))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_inspect_get_windows_current_control_set (g, root);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == NULL) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

#ifdef HAVE_PYSTRING_ASSTRING
  py_r = PyString_FromString (r);
#else
  py_r = PyUnicode_FromString (r);
#endif
  free (r);
  if (py_r == NULL) goto out;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_INSPECT_GET_WINDOWS_SYSTEMROOT
static PyObject *
guestfs_int_py_inspect_get_windows_systemroot (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  char *r;
  const char *root;

  if (!PyArg_ParseTuple (args, (char *) "Os:guestfs_inspect_get_windows_systemroot",
                         &py_g, &root))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_inspect_get_windows_systemroot (g, root);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == NULL) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

#ifdef HAVE_PYSTRING_ASSTRING
  py_r = PyString_FromString (r);
#else
  py_r = PyUnicode_FromString (r);
#endif
  free (r);
  if (py_r == NULL) goto out;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_INSPECT_IS_LIVE
static PyObject *
guestfs_int_py_inspect_is_live (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  const char *root;

  if (!PyArg_ParseTuple (args, (char *) "Os:guestfs_inspect_is_live",
                         &py_g, &root))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_inspect_is_live (g, root);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  py_r = PyLong_FromLong ((long) r);

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_INSPECT_IS_MULTIPART
static PyObject *
guestfs_int_py_inspect_is_multipart (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  const char *root;

  if (!PyArg_ParseTuple (args, (char *) "Os:guestfs_inspect_is_multipart",
                         &py_g, &root))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_inspect_is_multipart (g, root);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  py_r = PyLong_FromLong ((long) r);

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_INSPECT_IS_NETINST
static PyObject *
guestfs_int_py_inspect_is_netinst (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  const char *root;

  if (!PyArg_ParseTuple (args, (char *) "Os:guestfs_inspect_is_netinst",
                         &py_g, &root))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_inspect_is_netinst (g, root);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  py_r = PyLong_FromLong ((long) r);

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_INSPECT_LIST_APPLICATIONS
static PyObject *
guestfs_int_py_inspect_list_applications (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  struct guestfs_application_list *r;
  const char *root;

  if (!PyArg_ParseTuple (args, (char *) "Os:guestfs_inspect_list_applications",
                         &py_g, &root))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_inspect_list_applications (g, root);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == NULL) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  py_r = put_application_list (r);
  guestfs_free_application_list (r);

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_INSPECT_LIST_APPLICATIONS2
static PyObject *
guestfs_int_py_inspect_list_applications2 (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  struct guestfs_application2_list *r;
  const char *root;

  if (!PyArg_ParseTuple (args, (char *) "Os:guestfs_inspect_list_applications2",
                         &py_g, &root))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_inspect_list_applications2 (g, root);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == NULL) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  py_r = put_application2_list (r);
  guestfs_free_application2_list (r);

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_INSPECT_OS
static PyObject *
guestfs_int_py_inspect_os (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  char **r;

  if (!PyArg_ParseTuple (args, (char *) "O:guestfs_inspect_os",
                         &py_g))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_inspect_os (g);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == NULL) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  py_r = put_string_list (r);
  guestfs_int_free_string_list (r);

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_INTERNAL_EXIT
static PyObject *
guestfs_int_py_internal_exit (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;

  if (!PyArg_ParseTuple (args, (char *) "O:guestfs_internal_exit",
                         &py_g))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_internal_exit (g);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_INTERNAL_TEST
static PyObject *
guestfs_int_py_internal_test (PyObject *self, PyObject *args)
{
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  struct guestfs_internal_test_argv optargs_s;
  struct guestfs_internal_test_argv *optargs = &optargs_s;
  int r;
  const char *str;
  const char *optstr;
  PyObject *py_strlist;
  char **strlist = NULL;
  int b;
  int integer;
  long long integer64;
  const char *filein;
  const char *fileout;
  const char *bufferin;
  Py_ssize_t bufferin_size;
  PyObject *py_obool;
  PyObject *py_oint;
  PyObject *py_oint64;
  PyObject *py_ostring;
  PyObject *py_ostringlist;

  optargs_s.bitmask = 0;

  if (!PyArg_ParseTuple (args, (char *) "OszOiiLsss#OOOOO:guestfs_internal_test",
                         &py_g, &str, &optstr, &py_strlist, &b, &integer, &integer64, &filein, &fileout, &bufferin, &bufferin_size, &py_obool, &py_oint, &py_oint64, &py_ostring, &py_ostringlist))
    goto out;
  g = get_handle (py_g);
  strlist = get_string_list (py_strlist);
  if (!strlist) goto out;

#ifdef GUESTFS_INTERNAL_TEST_OBOOL_BITMASK
  if (py_obool != Py_None) {
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_OBOOL_BITMASK;
    optargs_s.obool = PyLong_AsLong (py_obool);
    if (PyErr_Occurred ()) goto out;
  }
#endif
#ifdef GUESTFS_INTERNAL_TEST_OINT_BITMASK
  if (py_oint != Py_None) {
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_OINT_BITMASK;
    optargs_s.oint = PyLong_AsLong (py_oint);
    if (PyErr_Occurred ()) goto out;
  }
#endif
#ifdef GUESTFS_INTERNAL_TEST_OINT64_BITMASK
  if (py_oint64 != Py_None) {
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_OINT64_BITMASK;
    optargs_s.oint64 = PyLong_AsLongLong (py_oint64);
    if (PyErr_Occurred ()) goto out;
  }
#endif
#ifdef GUESTFS_INTERNAL_TEST_OSTRING_BITMASK
  if (py_ostring != Py_None) {
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_OSTRING_BITMASK;
#ifdef HAVE_PYSTRING_ASSTRING
    optargs_s.ostring = PyString_AsString (py_ostring);
#else
    PyObject *bytes;
    bytes = PyUnicode_AsUTF8String (py_ostring);
    optargs_s.ostring = PyBytes_AS_STRING (bytes);
#endif
  }
#endif
#ifdef GUESTFS_INTERNAL_TEST_OSTRINGLIST_BITMASK
  if (py_ostringlist != Py_None) {
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_OSTRINGLIST_BITMASK;
    optargs_s.ostringlist = get_string_list (py_ostringlist);
    if (!optargs_s.ostringlist) goto out;
  }
#endif

  r = guestfs_internal_test_argv (g, str, optstr, strlist, b, integer, integer64, filein, fileout, bufferin, bufferin_size, optargs);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  free (strlist);
#ifdef GUESTFS_INTERNAL_TEST_OSTRINGLIST_BITMASK
  if (py_ostringlist != Py_None && (optargs_s.bitmask & GUESTFS_INTERNAL_TEST_OSTRINGLIST_BITMASK) != 0)
    free ((char **) optargs_s.ostringlist);
#endif
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_INTERNAL_TEST_63_OPTARGS
static PyObject *
guestfs_int_py_internal_test_63_optargs (PyObject *self, PyObject *args)
{
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  struct guestfs_internal_test_63_optargs_argv optargs_s;
  struct guestfs_internal_test_63_optargs_argv *optargs = &optargs_s;
  int r;
  PyObject *py_opt1;
  PyObject *py_opt2;
  PyObject *py_opt3;
  PyObject *py_opt4;
  PyObject *py_opt5;
  PyObject *py_opt6;
  PyObject *py_opt7;
  PyObject *py_opt8;
  PyObject *py_opt9;
  PyObject *py_opt10;
  PyObject *py_opt11;
  PyObject *py_opt12;
  PyObject *py_opt13;
  PyObject *py_opt14;
  PyObject *py_opt15;
  PyObject *py_opt16;
  PyObject *py_opt17;
  PyObject *py_opt18;
  PyObject *py_opt19;
  PyObject *py_opt20;
  PyObject *py_opt21;
  PyObject *py_opt22;
  PyObject *py_opt23;
  PyObject *py_opt24;
  PyObject *py_opt25;
  PyObject *py_opt26;
  PyObject *py_opt27;
  PyObject *py_opt28;
  PyObject *py_opt29;
  PyObject *py_opt30;
  PyObject *py_opt31;
  PyObject *py_opt32;
  PyObject *py_opt33;
  PyObject *py_opt34;
  PyObject *py_opt35;
  PyObject *py_opt36;
  PyObject *py_opt37;
  PyObject *py_opt38;
  PyObject *py_opt39;
  PyObject *py_opt40;
  PyObject *py_opt41;
  PyObject *py_opt42;
  PyObject *py_opt43;
  PyObject *py_opt44;
  PyObject *py_opt45;
  PyObject *py_opt46;
  PyObject *py_opt47;
  PyObject *py_opt48;
  PyObject *py_opt49;
  PyObject *py_opt50;
  PyObject *py_opt51;
  PyObject *py_opt52;
  PyObject *py_opt53;
  PyObject *py_opt54;
  PyObject *py_opt55;
  PyObject *py_opt56;
  PyObject *py_opt57;
  PyObject *py_opt58;
  PyObject *py_opt59;
  PyObject *py_opt60;
  PyObject *py_opt61;
  PyObject *py_opt62;
  PyObject *py_opt63;

  optargs_s.bitmask = 0;

  if (!PyArg_ParseTuple (args, (char *) "OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO:guestfs_internal_test_63_optargs",
                         &py_g, &py_opt1, &py_opt2, &py_opt3, &py_opt4, &py_opt5, &py_opt6, &py_opt7, &py_opt8, &py_opt9, &py_opt10, &py_opt11, &py_opt12, &py_opt13, &py_opt14, &py_opt15, &py_opt16, &py_opt17, &py_opt18, &py_opt19, &py_opt20, &py_opt21, &py_opt22, &py_opt23, &py_opt24, &py_opt25, &py_opt26, &py_opt27, &py_opt28, &py_opt29, &py_opt30, &py_opt31, &py_opt32, &py_opt33, &py_opt34, &py_opt35, &py_opt36, &py_opt37, &py_opt38, &py_opt39, &py_opt40, &py_opt41, &py_opt42, &py_opt43, &py_opt44, &py_opt45, &py_opt46, &py_opt47, &py_opt48, &py_opt49, &py_opt50, &py_opt51, &py_opt52, &py_opt53, &py_opt54, &py_opt55, &py_opt56, &py_opt57, &py_opt58, &py_opt59, &py_opt60, &py_opt61, &py_opt62, &py_opt63))
    goto out;
  g = get_handle (py_g);

#ifdef GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT1_BITMASK
  if (py_opt1 != Py_None) {
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT1_BITMASK;
    optargs_s.opt1 = PyLong_AsLong (py_opt1);
    if (PyErr_Occurred ()) goto out;
  }
#endif
#ifdef GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT2_BITMASK
  if (py_opt2 != Py_None) {
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT2_BITMASK;
    optargs_s.opt2 = PyLong_AsLong (py_opt2);
    if (PyErr_Occurred ()) goto out;
  }
#endif
#ifdef GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT3_BITMASK
  if (py_opt3 != Py_None) {
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT3_BITMASK;
    optargs_s.opt3 = PyLong_AsLong (py_opt3);
    if (PyErr_Occurred ()) goto out;
  }
#endif
#ifdef GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT4_BITMASK
  if (py_opt4 != Py_None) {
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT4_BITMASK;
    optargs_s.opt4 = PyLong_AsLong (py_opt4);
    if (PyErr_Occurred ()) goto out;
  }
#endif
#ifdef GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT5_BITMASK
  if (py_opt5 != Py_None) {
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT5_BITMASK;
    optargs_s.opt5 = PyLong_AsLong (py_opt5);
    if (PyErr_Occurred ()) goto out;
  }
#endif
#ifdef GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT6_BITMASK
  if (py_opt6 != Py_None) {
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT6_BITMASK;
    optargs_s.opt6 = PyLong_AsLong (py_opt6);
    if (PyErr_Occurred ()) goto out;
  }
#endif
#ifdef GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT7_BITMASK
  if (py_opt7 != Py_None) {
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT7_BITMASK;
    optargs_s.opt7 = PyLong_AsLong (py_opt7);
    if (PyErr_Occurred ()) goto out;
  }
#endif
#ifdef GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT8_BITMASK
  if (py_opt8 != Py_None) {
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT8_BITMASK;
    optargs_s.opt8 = PyLong_AsLong (py_opt8);
    if (PyErr_Occurred ()) goto out;
  }
#endif
#ifdef GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT9_BITMASK
  if (py_opt9 != Py_None) {
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT9_BITMASK;
    optargs_s.opt9 = PyLong_AsLong (py_opt9);
    if (PyErr_Occurred ()) goto out;
  }
#endif
#ifdef GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT10_BITMASK
  if (py_opt10 != Py_None) {
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT10_BITMASK;
    optargs_s.opt10 = PyLong_AsLong (py_opt10);
    if (PyErr_Occurred ()) goto out;
  }
#endif
#ifdef GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT11_BITMASK
  if (py_opt11 != Py_None) {
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT11_BITMASK;
    optargs_s.opt11 = PyLong_AsLong (py_opt11);
    if (PyErr_Occurred ()) goto out;
  }
#endif
#ifdef GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT12_BITMASK
  if (py_opt12 != Py_None) {
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT12_BITMASK;
    optargs_s.opt12 = PyLong_AsLong (py_opt12);
    if (PyErr_Occurred ()) goto out;
  }
#endif
#ifdef GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT13_BITMASK
  if (py_opt13 != Py_None) {
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT13_BITMASK;
    optargs_s.opt13 = PyLong_AsLong (py_opt13);
    if (PyErr_Occurred ()) goto out;
  }
#endif
#ifdef GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT14_BITMASK
  if (py_opt14 != Py_None) {
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT14_BITMASK;
    optargs_s.opt14 = PyLong_AsLong (py_opt14);
    if (PyErr_Occurred ()) goto out;
  }
#endif
#ifdef GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT15_BITMASK
  if (py_opt15 != Py_None) {
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT15_BITMASK;
    optargs_s.opt15 = PyLong_AsLong (py_opt15);
    if (PyErr_Occurred ()) goto out;
  }
#endif
#ifdef GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT16_BITMASK
  if (py_opt16 != Py_None) {
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT16_BITMASK;
    optargs_s.opt16 = PyLong_AsLong (py_opt16);
    if (PyErr_Occurred ()) goto out;
  }
#endif
#ifdef GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT17_BITMASK
  if (py_opt17 != Py_None) {
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT17_BITMASK;
    optargs_s.opt17 = PyLong_AsLong (py_opt17);
    if (PyErr_Occurred ()) goto out;
  }
#endif
#ifdef GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT18_BITMASK
  if (py_opt18 != Py_None) {
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT18_BITMASK;
    optargs_s.opt18 = PyLong_AsLong (py_opt18);
    if (PyErr_Occurred ()) goto out;
  }
#endif
#ifdef GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT19_BITMASK
  if (py_opt19 != Py_None) {
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT19_BITMASK;
    optargs_s.opt19 = PyLong_AsLong (py_opt19);
    if (PyErr_Occurred ()) goto out;
  }
#endif
#ifdef GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT20_BITMASK
  if (py_opt20 != Py_None) {
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT20_BITMASK;
    optargs_s.opt20 = PyLong_AsLong (py_opt20);
    if (PyErr_Occurred ()) goto out;
  }
#endif
#ifdef GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT21_BITMASK
  if (py_opt21 != Py_None) {
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT21_BITMASK;
    optargs_s.opt21 = PyLong_AsLong (py_opt21);
    if (PyErr_Occurred ()) goto out;
  }
#endif
#ifdef GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT22_BITMASK
  if (py_opt22 != Py_None) {
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT22_BITMASK;
    optargs_s.opt22 = PyLong_AsLong (py_opt22);
    if (PyErr_Occurred ()) goto out;
  }
#endif
#ifdef GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT23_BITMASK
  if (py_opt23 != Py_None) {
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT23_BITMASK;
    optargs_s.opt23 = PyLong_AsLong (py_opt23);
    if (PyErr_Occurred ()) goto out;
  }
#endif
#ifdef GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT24_BITMASK
  if (py_opt24 != Py_None) {
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT24_BITMASK;
    optargs_s.opt24 = PyLong_AsLong (py_opt24);
    if (PyErr_Occurred ()) goto out;
  }
#endif
#ifdef GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT25_BITMASK
  if (py_opt25 != Py_None) {
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT25_BITMASK;
    optargs_s.opt25 = PyLong_AsLong (py_opt25);
    if (PyErr_Occurred ()) goto out;
  }
#endif
#ifdef GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT26_BITMASK
  if (py_opt26 != Py_None) {
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT26_BITMASK;
    optargs_s.opt26 = PyLong_AsLong (py_opt26);
    if (PyErr_Occurred ()) goto out;
  }
#endif
#ifdef GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT27_BITMASK
  if (py_opt27 != Py_None) {
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT27_BITMASK;
    optargs_s.opt27 = PyLong_AsLong (py_opt27);
    if (PyErr_Occurred ()) goto out;
  }
#endif
#ifdef GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT28_BITMASK
  if (py_opt28 != Py_None) {
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT28_BITMASK;
    optargs_s.opt28 = PyLong_AsLong (py_opt28);
    if (PyErr_Occurred ()) goto out;
  }
#endif
#ifdef GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT29_BITMASK
  if (py_opt29 != Py_None) {
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT29_BITMASK;
    optargs_s.opt29 = PyLong_AsLong (py_opt29);
    if (PyErr_Occurred ()) goto out;
  }
#endif
#ifdef GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT30_BITMASK
  if (py_opt30 != Py_None) {
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT30_BITMASK;
    optargs_s.opt30 = PyLong_AsLong (py_opt30);
    if (PyErr_Occurred ()) goto out;
  }
#endif
#ifdef GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT31_BITMASK
  if (py_opt31 != Py_None) {
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT31_BITMASK;
    optargs_s.opt31 = PyLong_AsLong (py_opt31);
    if (PyErr_Occurred ()) goto out;
  }
#endif
#ifdef GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT32_BITMASK
  if (py_opt32 != Py_None) {
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT32_BITMASK;
    optargs_s.opt32 = PyLong_AsLong (py_opt32);
    if (PyErr_Occurred ()) goto out;
  }
#endif
#ifdef GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT33_BITMASK
  if (py_opt33 != Py_None) {
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT33_BITMASK;
    optargs_s.opt33 = PyLong_AsLong (py_opt33);
    if (PyErr_Occurred ()) goto out;
  }
#endif
#ifdef GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT34_BITMASK
  if (py_opt34 != Py_None) {
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT34_BITMASK;
    optargs_s.opt34 = PyLong_AsLong (py_opt34);
    if (PyErr_Occurred ()) goto out;
  }
#endif
#ifdef GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT35_BITMASK
  if (py_opt35 != Py_None) {
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT35_BITMASK;
    optargs_s.opt35 = PyLong_AsLong (py_opt35);
    if (PyErr_Occurred ()) goto out;
  }
#endif
#ifdef GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT36_BITMASK
  if (py_opt36 != Py_None) {
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT36_BITMASK;
    optargs_s.opt36 = PyLong_AsLong (py_opt36);
    if (PyErr_Occurred ()) goto out;
  }
#endif
#ifdef GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT37_BITMASK
  if (py_opt37 != Py_None) {
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT37_BITMASK;
    optargs_s.opt37 = PyLong_AsLong (py_opt37);
    if (PyErr_Occurred ()) goto out;
  }
#endif
#ifdef GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT38_BITMASK
  if (py_opt38 != Py_None) {
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT38_BITMASK;
    optargs_s.opt38 = PyLong_AsLong (py_opt38);
    if (PyErr_Occurred ()) goto out;
  }
#endif
#ifdef GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT39_BITMASK
  if (py_opt39 != Py_None) {
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT39_BITMASK;
    optargs_s.opt39 = PyLong_AsLong (py_opt39);
    if (PyErr_Occurred ()) goto out;
  }
#endif
#ifdef GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT40_BITMASK
  if (py_opt40 != Py_None) {
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT40_BITMASK;
    optargs_s.opt40 = PyLong_AsLong (py_opt40);
    if (PyErr_Occurred ()) goto out;
  }
#endif
#ifdef GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT41_BITMASK
  if (py_opt41 != Py_None) {
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT41_BITMASK;
    optargs_s.opt41 = PyLong_AsLong (py_opt41);
    if (PyErr_Occurred ()) goto out;
  }
#endif
#ifdef GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT42_BITMASK
  if (py_opt42 != Py_None) {
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT42_BITMASK;
    optargs_s.opt42 = PyLong_AsLong (py_opt42);
    if (PyErr_Occurred ()) goto out;
  }
#endif
#ifdef GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT43_BITMASK
  if (py_opt43 != Py_None) {
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT43_BITMASK;
    optargs_s.opt43 = PyLong_AsLong (py_opt43);
    if (PyErr_Occurred ()) goto out;
  }
#endif
#ifdef GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT44_BITMASK
  if (py_opt44 != Py_None) {
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT44_BITMASK;
    optargs_s.opt44 = PyLong_AsLong (py_opt44);
    if (PyErr_Occurred ()) goto out;
  }
#endif
#ifdef GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT45_BITMASK
  if (py_opt45 != Py_None) {
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT45_BITMASK;
    optargs_s.opt45 = PyLong_AsLong (py_opt45);
    if (PyErr_Occurred ()) goto out;
  }
#endif
#ifdef GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT46_BITMASK
  if (py_opt46 != Py_None) {
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT46_BITMASK;
    optargs_s.opt46 = PyLong_AsLong (py_opt46);
    if (PyErr_Occurred ()) goto out;
  }
#endif
#ifdef GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT47_BITMASK
  if (py_opt47 != Py_None) {
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT47_BITMASK;
    optargs_s.opt47 = PyLong_AsLong (py_opt47);
    if (PyErr_Occurred ()) goto out;
  }
#endif
#ifdef GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT48_BITMASK
  if (py_opt48 != Py_None) {
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT48_BITMASK;
    optargs_s.opt48 = PyLong_AsLong (py_opt48);
    if (PyErr_Occurred ()) goto out;
  }
#endif
#ifdef GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT49_BITMASK
  if (py_opt49 != Py_None) {
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT49_BITMASK;
    optargs_s.opt49 = PyLong_AsLong (py_opt49);
    if (PyErr_Occurred ()) goto out;
  }
#endif
#ifdef GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT50_BITMASK
  if (py_opt50 != Py_None) {
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT50_BITMASK;
    optargs_s.opt50 = PyLong_AsLong (py_opt50);
    if (PyErr_Occurred ()) goto out;
  }
#endif
#ifdef GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT51_BITMASK
  if (py_opt51 != Py_None) {
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT51_BITMASK;
    optargs_s.opt51 = PyLong_AsLong (py_opt51);
    if (PyErr_Occurred ()) goto out;
  }
#endif
#ifdef GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT52_BITMASK
  if (py_opt52 != Py_None) {
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT52_BITMASK;
    optargs_s.opt52 = PyLong_AsLong (py_opt52);
    if (PyErr_Occurred ()) goto out;
  }
#endif
#ifdef GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT53_BITMASK
  if (py_opt53 != Py_None) {
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT53_BITMASK;
    optargs_s.opt53 = PyLong_AsLong (py_opt53);
    if (PyErr_Occurred ()) goto out;
  }
#endif
#ifdef GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT54_BITMASK
  if (py_opt54 != Py_None) {
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT54_BITMASK;
    optargs_s.opt54 = PyLong_AsLong (py_opt54);
    if (PyErr_Occurred ()) goto out;
  }
#endif
#ifdef GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT55_BITMASK
  if (py_opt55 != Py_None) {
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT55_BITMASK;
    optargs_s.opt55 = PyLong_AsLong (py_opt55);
    if (PyErr_Occurred ()) goto out;
  }
#endif
#ifdef GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT56_BITMASK
  if (py_opt56 != Py_None) {
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT56_BITMASK;
    optargs_s.opt56 = PyLong_AsLong (py_opt56);
    if (PyErr_Occurred ()) goto out;
  }
#endif
#ifdef GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT57_BITMASK
  if (py_opt57 != Py_None) {
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT57_BITMASK;
    optargs_s.opt57 = PyLong_AsLong (py_opt57);
    if (PyErr_Occurred ()) goto out;
  }
#endif
#ifdef GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT58_BITMASK
  if (py_opt58 != Py_None) {
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT58_BITMASK;
    optargs_s.opt58 = PyLong_AsLong (py_opt58);
    if (PyErr_Occurred ()) goto out;
  }
#endif
#ifdef GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT59_BITMASK
  if (py_opt59 != Py_None) {
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT59_BITMASK;
    optargs_s.opt59 = PyLong_AsLong (py_opt59);
    if (PyErr_Occurred ()) goto out;
  }
#endif
#ifdef GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT60_BITMASK
  if (py_opt60 != Py_None) {
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT60_BITMASK;
    optargs_s.opt60 = PyLong_AsLong (py_opt60);
    if (PyErr_Occurred ()) goto out;
  }
#endif
#ifdef GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT61_BITMASK
  if (py_opt61 != Py_None) {
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT61_BITMASK;
    optargs_s.opt61 = PyLong_AsLong (py_opt61);
    if (PyErr_Occurred ()) goto out;
  }
#endif
#ifdef GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT62_BITMASK
  if (py_opt62 != Py_None) {
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT62_BITMASK;
    optargs_s.opt62 = PyLong_AsLong (py_opt62);
    if (PyErr_Occurred ()) goto out;
  }
#endif
#ifdef GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT63_BITMASK
  if (py_opt63 != Py_None) {
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT63_BITMASK;
    optargs_s.opt63 = PyLong_AsLong (py_opt63);
    if (PyErr_Occurred ()) goto out;
  }
#endif

  r = guestfs_internal_test_63_optargs_argv (g, optargs);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_INTERNAL_TEST_CLOSE_OUTPUT
static PyObject *
guestfs_int_py_internal_test_close_output (PyObject *self, PyObject *args)
{
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;

  if (!PyArg_ParseTuple (args, (char *) "O:guestfs_internal_test_close_output",
                         &py_g))
    goto out;
  g = get_handle (py_g);

  r = guestfs_internal_test_close_output (g);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_INTERNAL_TEST_ONLY_OPTARGS
static PyObject *
guestfs_int_py_internal_test_only_optargs (PyObject *self, PyObject *args)
{
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  struct guestfs_internal_test_only_optargs_argv optargs_s;
  struct guestfs_internal_test_only_optargs_argv *optargs = &optargs_s;
  int r;
  PyObject *py_test;

  optargs_s.bitmask = 0;

  if (!PyArg_ParseTuple (args, (char *) "OO:guestfs_internal_test_only_optargs",
                         &py_g, &py_test))
    goto out;
  g = get_handle (py_g);

#ifdef GUESTFS_INTERNAL_TEST_ONLY_OPTARGS_TEST_BITMASK
  if (py_test != Py_None) {
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_ONLY_OPTARGS_TEST_BITMASK;
    optargs_s.test = PyLong_AsLong (py_test);
    if (PyErr_Occurred ()) goto out;
  }
#endif

  r = guestfs_internal_test_only_optargs_argv (g, optargs);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_INTERNAL_TEST_RBOOL
static PyObject *
guestfs_int_py_internal_test_rbool (PyObject *self, PyObject *args)
{
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  const char *val;

  if (!PyArg_ParseTuple (args, (char *) "Os:guestfs_internal_test_rbool",
                         &py_g, &val))
    goto out;
  g = get_handle (py_g);

  r = guestfs_internal_test_rbool (g, val);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  py_r = PyLong_FromLong ((long) r);

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_INTERNAL_TEST_RBOOLERR
static PyObject *
guestfs_int_py_internal_test_rboolerr (PyObject *self, PyObject *args)
{
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;

  if (!PyArg_ParseTuple (args, (char *) "O:guestfs_internal_test_rboolerr",
                         &py_g))
    goto out;
  g = get_handle (py_g);

  r = guestfs_internal_test_rboolerr (g);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  py_r = PyLong_FromLong ((long) r);

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_INTERNAL_TEST_RBUFFEROUT
static PyObject *
guestfs_int_py_internal_test_rbufferout (PyObject *self, PyObject *args)
{
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  char *r;
  size_t size;
  const char *val;

  if (!PyArg_ParseTuple (args, (char *) "Os:guestfs_internal_test_rbufferout",
                         &py_g, &val))
    goto out;
  g = get_handle (py_g);

  r = guestfs_internal_test_rbufferout (g, val, &size);

  if (r == NULL) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

#ifdef HAVE_PYSTRING_ASSTRING
  py_r = PyString_FromStringAndSize (r, size);
#else
  py_r = PyBytes_FromStringAndSize (r, size);
#endif
  free (r);
  if (py_r == NULL) goto out;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_INTERNAL_TEST_RBUFFEROUTERR
static PyObject *
guestfs_int_py_internal_test_rbufferouterr (PyObject *self, PyObject *args)
{
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  char *r;
  size_t size;

  if (!PyArg_ParseTuple (args, (char *) "O:guestfs_internal_test_rbufferouterr",
                         &py_g))
    goto out;
  g = get_handle (py_g);

  r = guestfs_internal_test_rbufferouterr (g, &size);

  if (r == NULL) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

#ifdef HAVE_PYSTRING_ASSTRING
  py_r = PyString_FromStringAndSize (r, size);
#else
  py_r = PyBytes_FromStringAndSize (r, size);
#endif
  free (r);
  if (py_r == NULL) goto out;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_INTERNAL_TEST_RCONSTOPTSTRING
static PyObject *
guestfs_int_py_internal_test_rconstoptstring (PyObject *self, PyObject *args)
{
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  const char *r;
  const char *val;

  if (!PyArg_ParseTuple (args, (char *) "Os:guestfs_internal_test_rconstoptstring",
                         &py_g, &val))
    goto out;
  g = get_handle (py_g);

  r = guestfs_internal_test_rconstoptstring (g, val);


  if (r) {
#ifdef HAVE_PYSTRING_ASSTRING
    py_r = PyString_FromString (r);
#else
    py_r = PyUnicode_FromString (r);
#endif
  } else {
    Py_INCREF (Py_None);
    py_r = Py_None;
  }
  if (py_r == NULL) goto out;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_INTERNAL_TEST_RCONSTOPTSTRINGERR
static PyObject *
guestfs_int_py_internal_test_rconstoptstringerr (PyObject *self, PyObject *args)
{
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  const char *r;

  if (!PyArg_ParseTuple (args, (char *) "O:guestfs_internal_test_rconstoptstringerr",
                         &py_g))
    goto out;
  g = get_handle (py_g);

  r = guestfs_internal_test_rconstoptstringerr (g);


  if (r) {
#ifdef HAVE_PYSTRING_ASSTRING
    py_r = PyString_FromString (r);
#else
    py_r = PyUnicode_FromString (r);
#endif
  } else {
    Py_INCREF (Py_None);
    py_r = Py_None;
  }
  if (py_r == NULL) goto out;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_INTERNAL_TEST_RCONSTSTRING
static PyObject *
guestfs_int_py_internal_test_rconststring (PyObject *self, PyObject *args)
{
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  const char *r;
  const char *val;

  if (!PyArg_ParseTuple (args, (char *) "Os:guestfs_internal_test_rconststring",
                         &py_g, &val))
    goto out;
  g = get_handle (py_g);

  r = guestfs_internal_test_rconststring (g, val);

  if (r == NULL) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

#ifdef HAVE_PYSTRING_ASSTRING
  py_r = PyString_FromString (r);
#else
  py_r = PyUnicode_FromString (r);
#endif
  if (py_r == NULL) goto out;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_INTERNAL_TEST_RCONSTSTRINGERR
static PyObject *
guestfs_int_py_internal_test_rconststringerr (PyObject *self, PyObject *args)
{
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  const char *r;

  if (!PyArg_ParseTuple (args, (char *) "O:guestfs_internal_test_rconststringerr",
                         &py_g))
    goto out;
  g = get_handle (py_g);

  r = guestfs_internal_test_rconststringerr (g);

  if (r == NULL) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

#ifdef HAVE_PYSTRING_ASSTRING
  py_r = PyString_FromString (r);
#else
  py_r = PyUnicode_FromString (r);
#endif
  if (py_r == NULL) goto out;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_INTERNAL_TEST_RHASHTABLE
static PyObject *
guestfs_int_py_internal_test_rhashtable (PyObject *self, PyObject *args)
{
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  char **r;
  const char *val;

  if (!PyArg_ParseTuple (args, (char *) "Os:guestfs_internal_test_rhashtable",
                         &py_g, &val))
    goto out;
  g = get_handle (py_g);

  r = guestfs_internal_test_rhashtable (g, val);

  if (r == NULL) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  py_r = put_table (r);
  guestfs_int_free_string_list (r);

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_INTERNAL_TEST_RHASHTABLEERR
static PyObject *
guestfs_int_py_internal_test_rhashtableerr (PyObject *self, PyObject *args)
{
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  char **r;

  if (!PyArg_ParseTuple (args, (char *) "O:guestfs_internal_test_rhashtableerr",
                         &py_g))
    goto out;
  g = get_handle (py_g);

  r = guestfs_internal_test_rhashtableerr (g);

  if (r == NULL) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  py_r = put_table (r);
  guestfs_int_free_string_list (r);

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_INTERNAL_TEST_RINT
static PyObject *
guestfs_int_py_internal_test_rint (PyObject *self, PyObject *args)
{
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  const char *val;

  if (!PyArg_ParseTuple (args, (char *) "Os:guestfs_internal_test_rint",
                         &py_g, &val))
    goto out;
  g = get_handle (py_g);

  r = guestfs_internal_test_rint (g, val);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  py_r = PyLong_FromLong ((long) r);

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_INTERNAL_TEST_RINT64
static PyObject *
guestfs_int_py_internal_test_rint64 (PyObject *self, PyObject *args)
{
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int64_t r;
  const char *val;

  if (!PyArg_ParseTuple (args, (char *) "Os:guestfs_internal_test_rint64",
                         &py_g, &val))
    goto out;
  g = get_handle (py_g);

  r = guestfs_internal_test_rint64 (g, val);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  py_r = PyLong_FromLongLong (r);

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_INTERNAL_TEST_RINT64ERR
static PyObject *
guestfs_int_py_internal_test_rint64err (PyObject *self, PyObject *args)
{
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int64_t r;

  if (!PyArg_ParseTuple (args, (char *) "O:guestfs_internal_test_rint64err",
                         &py_g))
    goto out;
  g = get_handle (py_g);

  r = guestfs_internal_test_rint64err (g);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  py_r = PyLong_FromLongLong (r);

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_INTERNAL_TEST_RINTERR
static PyObject *
guestfs_int_py_internal_test_rinterr (PyObject *self, PyObject *args)
{
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;

  if (!PyArg_ParseTuple (args, (char *) "O:guestfs_internal_test_rinterr",
                         &py_g))
    goto out;
  g = get_handle (py_g);

  r = guestfs_internal_test_rinterr (g);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  py_r = PyLong_FromLong ((long) r);

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_INTERNAL_TEST_RSTRING
static PyObject *
guestfs_int_py_internal_test_rstring (PyObject *self, PyObject *args)
{
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  char *r;
  const char *val;

  if (!PyArg_ParseTuple (args, (char *) "Os:guestfs_internal_test_rstring",
                         &py_g, &val))
    goto out;
  g = get_handle (py_g);

  r = guestfs_internal_test_rstring (g, val);

  if (r == NULL) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

#ifdef HAVE_PYSTRING_ASSTRING
  py_r = PyString_FromString (r);
#else
  py_r = PyUnicode_FromString (r);
#endif
  free (r);
  if (py_r == NULL) goto out;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_INTERNAL_TEST_RSTRINGERR
static PyObject *
guestfs_int_py_internal_test_rstringerr (PyObject *self, PyObject *args)
{
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  char *r;

  if (!PyArg_ParseTuple (args, (char *) "O:guestfs_internal_test_rstringerr",
                         &py_g))
    goto out;
  g = get_handle (py_g);

  r = guestfs_internal_test_rstringerr (g);

  if (r == NULL) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

#ifdef HAVE_PYSTRING_ASSTRING
  py_r = PyString_FromString (r);
#else
  py_r = PyUnicode_FromString (r);
#endif
  free (r);
  if (py_r == NULL) goto out;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_INTERNAL_TEST_RSTRINGLIST
static PyObject *
guestfs_int_py_internal_test_rstringlist (PyObject *self, PyObject *args)
{
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  char **r;
  const char *val;

  if (!PyArg_ParseTuple (args, (char *) "Os:guestfs_internal_test_rstringlist",
                         &py_g, &val))
    goto out;
  g = get_handle (py_g);

  r = guestfs_internal_test_rstringlist (g, val);

  if (r == NULL) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  py_r = put_string_list (r);
  guestfs_int_free_string_list (r);

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_INTERNAL_TEST_RSTRINGLISTERR
static PyObject *
guestfs_int_py_internal_test_rstringlisterr (PyObject *self, PyObject *args)
{
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  char **r;

  if (!PyArg_ParseTuple (args, (char *) "O:guestfs_internal_test_rstringlisterr",
                         &py_g))
    goto out;
  g = get_handle (py_g);

  r = guestfs_internal_test_rstringlisterr (g);

  if (r == NULL) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  py_r = put_string_list (r);
  guestfs_int_free_string_list (r);

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_INTERNAL_TEST_RSTRUCT
static PyObject *
guestfs_int_py_internal_test_rstruct (PyObject *self, PyObject *args)
{
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  struct guestfs_lvm_pv *r;
  const char *val;

  if (!PyArg_ParseTuple (args, (char *) "Os:guestfs_internal_test_rstruct",
                         &py_g, &val))
    goto out;
  g = get_handle (py_g);

  r = guestfs_internal_test_rstruct (g, val);

  if (r == NULL) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  py_r = put_lvm_pv (r);
  guestfs_free_lvm_pv (r);

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_INTERNAL_TEST_RSTRUCTERR
static PyObject *
guestfs_int_py_internal_test_rstructerr (PyObject *self, PyObject *args)
{
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  struct guestfs_lvm_pv *r;

  if (!PyArg_ParseTuple (args, (char *) "O:guestfs_internal_test_rstructerr",
                         &py_g))
    goto out;
  g = get_handle (py_g);

  r = guestfs_internal_test_rstructerr (g);

  if (r == NULL) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  py_r = put_lvm_pv (r);
  guestfs_free_lvm_pv (r);

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_INTERNAL_TEST_RSTRUCTLIST
static PyObject *
guestfs_int_py_internal_test_rstructlist (PyObject *self, PyObject *args)
{
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  struct guestfs_lvm_pv_list *r;
  const char *val;

  if (!PyArg_ParseTuple (args, (char *) "Os:guestfs_internal_test_rstructlist",
                         &py_g, &val))
    goto out;
  g = get_handle (py_g);

  r = guestfs_internal_test_rstructlist (g, val);

  if (r == NULL) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  py_r = put_lvm_pv_list (r);
  guestfs_free_lvm_pv_list (r);

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_INTERNAL_TEST_RSTRUCTLISTERR
static PyObject *
guestfs_int_py_internal_test_rstructlisterr (PyObject *self, PyObject *args)
{
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  struct guestfs_lvm_pv_list *r;

  if (!PyArg_ParseTuple (args, (char *) "O:guestfs_internal_test_rstructlisterr",
                         &py_g))
    goto out;
  g = get_handle (py_g);

  r = guestfs_internal_test_rstructlisterr (g);

  if (r == NULL) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  py_r = put_lvm_pv_list (r);
  guestfs_free_lvm_pv_list (r);

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_INTERNAL_TEST_SET_OUTPUT
static PyObject *
guestfs_int_py_internal_test_set_output (PyObject *self, PyObject *args)
{
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  const char *filename;

  if (!PyArg_ParseTuple (args, (char *) "Os:guestfs_internal_test_set_output",
                         &py_g, &filename))
    goto out;
  g = get_handle (py_g);

  r = guestfs_internal_test_set_output (g, filename);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_IS_BLOCKDEV_OPTS
static PyObject *
guestfs_int_py_is_blockdev (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  struct guestfs_is_blockdev_opts_argv optargs_s;
  struct guestfs_is_blockdev_opts_argv *optargs = &optargs_s;
  int r;
  const char *path;
  PyObject *py_followsymlinks;

  optargs_s.bitmask = 0;

  if (!PyArg_ParseTuple (args, (char *) "OsO:guestfs_is_blockdev",
                         &py_g, &path, &py_followsymlinks))
    goto out;
  g = get_handle (py_g);

#ifdef GUESTFS_IS_BLOCKDEV_OPTS_FOLLOWSYMLINKS_BITMASK
  if (py_followsymlinks != Py_None) {
    optargs_s.bitmask |= GUESTFS_IS_BLOCKDEV_OPTS_FOLLOWSYMLINKS_BITMASK;
    optargs_s.followsymlinks = PyLong_AsLong (py_followsymlinks);
    if (PyErr_Occurred ()) goto out;
  }
#endif

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_is_blockdev_opts_argv (g, path, optargs);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  py_r = PyLong_FromLong ((long) r);

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_IS_BUSY
static PyObject *
guestfs_int_py_is_busy (PyObject *self, PyObject *args)
{
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;

  if (!PyArg_ParseTuple (args, (char *) "O:guestfs_is_busy",
                         &py_g))
    goto out;
  g = get_handle (py_g);

  r = guestfs_is_busy (g);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  py_r = PyLong_FromLong ((long) r);

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_IS_CHARDEV_OPTS
static PyObject *
guestfs_int_py_is_chardev (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  struct guestfs_is_chardev_opts_argv optargs_s;
  struct guestfs_is_chardev_opts_argv *optargs = &optargs_s;
  int r;
  const char *path;
  PyObject *py_followsymlinks;

  optargs_s.bitmask = 0;

  if (!PyArg_ParseTuple (args, (char *) "OsO:guestfs_is_chardev",
                         &py_g, &path, &py_followsymlinks))
    goto out;
  g = get_handle (py_g);

#ifdef GUESTFS_IS_CHARDEV_OPTS_FOLLOWSYMLINKS_BITMASK
  if (py_followsymlinks != Py_None) {
    optargs_s.bitmask |= GUESTFS_IS_CHARDEV_OPTS_FOLLOWSYMLINKS_BITMASK;
    optargs_s.followsymlinks = PyLong_AsLong (py_followsymlinks);
    if (PyErr_Occurred ()) goto out;
  }
#endif

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_is_chardev_opts_argv (g, path, optargs);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  py_r = PyLong_FromLong ((long) r);

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_IS_CONFIG
static PyObject *
guestfs_int_py_is_config (PyObject *self, PyObject *args)
{
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;

  if (!PyArg_ParseTuple (args, (char *) "O:guestfs_is_config",
                         &py_g))
    goto out;
  g = get_handle (py_g);

  r = guestfs_is_config (g);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  py_r = PyLong_FromLong ((long) r);

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_IS_DIR_OPTS
static PyObject *
guestfs_int_py_is_dir (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  struct guestfs_is_dir_opts_argv optargs_s;
  struct guestfs_is_dir_opts_argv *optargs = &optargs_s;
  int r;
  const char *path;
  PyObject *py_followsymlinks;

  optargs_s.bitmask = 0;

  if (!PyArg_ParseTuple (args, (char *) "OsO:guestfs_is_dir",
                         &py_g, &path, &py_followsymlinks))
    goto out;
  g = get_handle (py_g);

#ifdef GUESTFS_IS_DIR_OPTS_FOLLOWSYMLINKS_BITMASK
  if (py_followsymlinks != Py_None) {
    optargs_s.bitmask |= GUESTFS_IS_DIR_OPTS_FOLLOWSYMLINKS_BITMASK;
    optargs_s.followsymlinks = PyLong_AsLong (py_followsymlinks);
    if (PyErr_Occurred ()) goto out;
  }
#endif

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_is_dir_opts_argv (g, path, optargs);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  py_r = PyLong_FromLong ((long) r);

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_IS_FIFO_OPTS
static PyObject *
guestfs_int_py_is_fifo (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  struct guestfs_is_fifo_opts_argv optargs_s;
  struct guestfs_is_fifo_opts_argv *optargs = &optargs_s;
  int r;
  const char *path;
  PyObject *py_followsymlinks;

  optargs_s.bitmask = 0;

  if (!PyArg_ParseTuple (args, (char *) "OsO:guestfs_is_fifo",
                         &py_g, &path, &py_followsymlinks))
    goto out;
  g = get_handle (py_g);

#ifdef GUESTFS_IS_FIFO_OPTS_FOLLOWSYMLINKS_BITMASK
  if (py_followsymlinks != Py_None) {
    optargs_s.bitmask |= GUESTFS_IS_FIFO_OPTS_FOLLOWSYMLINKS_BITMASK;
    optargs_s.followsymlinks = PyLong_AsLong (py_followsymlinks);
    if (PyErr_Occurred ()) goto out;
  }
#endif

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_is_fifo_opts_argv (g, path, optargs);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  py_r = PyLong_FromLong ((long) r);

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_IS_FILE_OPTS
static PyObject *
guestfs_int_py_is_file (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  struct guestfs_is_file_opts_argv optargs_s;
  struct guestfs_is_file_opts_argv *optargs = &optargs_s;
  int r;
  const char *path;
  PyObject *py_followsymlinks;

  optargs_s.bitmask = 0;

  if (!PyArg_ParseTuple (args, (char *) "OsO:guestfs_is_file",
                         &py_g, &path, &py_followsymlinks))
    goto out;
  g = get_handle (py_g);

#ifdef GUESTFS_IS_FILE_OPTS_FOLLOWSYMLINKS_BITMASK
  if (py_followsymlinks != Py_None) {
    optargs_s.bitmask |= GUESTFS_IS_FILE_OPTS_FOLLOWSYMLINKS_BITMASK;
    optargs_s.followsymlinks = PyLong_AsLong (py_followsymlinks);
    if (PyErr_Occurred ()) goto out;
  }
#endif

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_is_file_opts_argv (g, path, optargs);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  py_r = PyLong_FromLong ((long) r);

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_IS_LAUNCHING
static PyObject *
guestfs_int_py_is_launching (PyObject *self, PyObject *args)
{
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;

  if (!PyArg_ParseTuple (args, (char *) "O:guestfs_is_launching",
                         &py_g))
    goto out;
  g = get_handle (py_g);

  r = guestfs_is_launching (g);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  py_r = PyLong_FromLong ((long) r);

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_IS_LV
static PyObject *
guestfs_int_py_is_lv (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  const char *device;

  if (!PyArg_ParseTuple (args, (char *) "Os:guestfs_is_lv",
                         &py_g, &device))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_is_lv (g, device);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  py_r = PyLong_FromLong ((long) r);

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_IS_READY
static PyObject *
guestfs_int_py_is_ready (PyObject *self, PyObject *args)
{
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;

  if (!PyArg_ParseTuple (args, (char *) "O:guestfs_is_ready",
                         &py_g))
    goto out;
  g = get_handle (py_g);

  r = guestfs_is_ready (g);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  py_r = PyLong_FromLong ((long) r);

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_IS_SOCKET_OPTS
static PyObject *
guestfs_int_py_is_socket (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  struct guestfs_is_socket_opts_argv optargs_s;
  struct guestfs_is_socket_opts_argv *optargs = &optargs_s;
  int r;
  const char *path;
  PyObject *py_followsymlinks;

  optargs_s.bitmask = 0;

  if (!PyArg_ParseTuple (args, (char *) "OsO:guestfs_is_socket",
                         &py_g, &path, &py_followsymlinks))
    goto out;
  g = get_handle (py_g);

#ifdef GUESTFS_IS_SOCKET_OPTS_FOLLOWSYMLINKS_BITMASK
  if (py_followsymlinks != Py_None) {
    optargs_s.bitmask |= GUESTFS_IS_SOCKET_OPTS_FOLLOWSYMLINKS_BITMASK;
    optargs_s.followsymlinks = PyLong_AsLong (py_followsymlinks);
    if (PyErr_Occurred ()) goto out;
  }
#endif

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_is_socket_opts_argv (g, path, optargs);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  py_r = PyLong_FromLong ((long) r);

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_IS_SYMLINK
static PyObject *
guestfs_int_py_is_symlink (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  const char *path;

  if (!PyArg_ParseTuple (args, (char *) "Os:guestfs_is_symlink",
                         &py_g, &path))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_is_symlink (g, path);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  py_r = PyLong_FromLong ((long) r);

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_IS_WHOLE_DEVICE
static PyObject *
guestfs_int_py_is_whole_device (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  const char *device;

  if (!PyArg_ParseTuple (args, (char *) "Os:guestfs_is_whole_device",
                         &py_g, &device))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_is_whole_device (g, device);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  py_r = PyLong_FromLong ((long) r);

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_IS_ZERO
static PyObject *
guestfs_int_py_is_zero (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  const char *path;

  if (!PyArg_ParseTuple (args, (char *) "Os:guestfs_is_zero",
                         &py_g, &path))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_is_zero (g, path);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  py_r = PyLong_FromLong ((long) r);

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_IS_ZERO_DEVICE
static PyObject *
guestfs_int_py_is_zero_device (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  const char *device;

  if (!PyArg_ParseTuple (args, (char *) "Os:guestfs_is_zero_device",
                         &py_g, &device))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_is_zero_device (g, device);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  py_r = PyLong_FromLong ((long) r);

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_ISOINFO
static PyObject *
guestfs_int_py_isoinfo (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  struct guestfs_isoinfo *r;
  const char *isofile;

  if (!PyArg_ParseTuple (args, (char *) "Os:guestfs_isoinfo",
                         &py_g, &isofile))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_isoinfo (g, isofile);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == NULL) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  py_r = put_isoinfo (r);
  guestfs_free_isoinfo (r);

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_ISOINFO_DEVICE
static PyObject *
guestfs_int_py_isoinfo_device (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  struct guestfs_isoinfo *r;
  const char *device;

  if (!PyArg_ParseTuple (args, (char *) "Os:guestfs_isoinfo_device",
                         &py_g, &device))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_isoinfo_device (g, device);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == NULL) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  py_r = put_isoinfo (r);
  guestfs_free_isoinfo (r);

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_JOURNAL_CLOSE
static PyObject *
guestfs_int_py_journal_close (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;

  if (!PyArg_ParseTuple (args, (char *) "O:guestfs_journal_close",
                         &py_g))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_journal_close (g);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_JOURNAL_GET
static PyObject *
guestfs_int_py_journal_get (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  struct guestfs_xattr_list *r;

  if (!PyArg_ParseTuple (args, (char *) "O:guestfs_journal_get",
                         &py_g))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_journal_get (g);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == NULL) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  py_r = put_xattr_list (r);
  guestfs_free_xattr_list (r);

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_JOURNAL_GET_DATA_THRESHOLD
static PyObject *
guestfs_int_py_journal_get_data_threshold (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int64_t r;

  if (!PyArg_ParseTuple (args, (char *) "O:guestfs_journal_get_data_threshold",
                         &py_g))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_journal_get_data_threshold (g);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  py_r = PyLong_FromLongLong (r);

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_JOURNAL_GET_REALTIME_USEC
static PyObject *
guestfs_int_py_journal_get_realtime_usec (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int64_t r;

  if (!PyArg_ParseTuple (args, (char *) "O:guestfs_journal_get_realtime_usec",
                         &py_g))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_journal_get_realtime_usec (g);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  py_r = PyLong_FromLongLong (r);

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_JOURNAL_NEXT
static PyObject *
guestfs_int_py_journal_next (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;

  if (!PyArg_ParseTuple (args, (char *) "O:guestfs_journal_next",
                         &py_g))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_journal_next (g);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  py_r = PyLong_FromLong ((long) r);

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_JOURNAL_OPEN
static PyObject *
guestfs_int_py_journal_open (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  const char *directory;

  if (!PyArg_ParseTuple (args, (char *) "Os:guestfs_journal_open",
                         &py_g, &directory))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_journal_open (g, directory);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_JOURNAL_SET_DATA_THRESHOLD
static PyObject *
guestfs_int_py_journal_set_data_threshold (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  long long threshold;

  if (!PyArg_ParseTuple (args, (char *) "OL:guestfs_journal_set_data_threshold",
                         &py_g, &threshold))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_journal_set_data_threshold (g, threshold);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_JOURNAL_SKIP
static PyObject *
guestfs_int_py_journal_skip (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int64_t r;
  long long skip;

  if (!PyArg_ParseTuple (args, (char *) "OL:guestfs_journal_skip",
                         &py_g, &skip))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_journal_skip (g, skip);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  py_r = PyLong_FromLongLong (r);

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_KILL_SUBPROCESS
static PyObject *
guestfs_int_py_kill_subprocess (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;

  if (!PyArg_ParseTuple (args, (char *) "O:guestfs_kill_subprocess",
                         &py_g))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_kill_subprocess (g);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_LAUNCH
static PyObject *
guestfs_int_py_launch (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;

  if (!PyArg_ParseTuple (args, (char *) "O:guestfs_launch",
                         &py_g))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_launch (g);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_LCHOWN
static PyObject *
guestfs_int_py_lchown (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  int owner;
  int group;
  const char *path;

  if (!PyArg_ParseTuple (args, (char *) "Oiis:guestfs_lchown",
                         &py_g, &owner, &group, &path))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_lchown (g, owner, group, path);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_LDMTOOL_CREATE_ALL
static PyObject *
guestfs_int_py_ldmtool_create_all (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;

  if (!PyArg_ParseTuple (args, (char *) "O:guestfs_ldmtool_create_all",
                         &py_g))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_ldmtool_create_all (g);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_LDMTOOL_DISKGROUP_DISKS
static PyObject *
guestfs_int_py_ldmtool_diskgroup_disks (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  char **r;
  const char *diskgroup;

  if (!PyArg_ParseTuple (args, (char *) "Os:guestfs_ldmtool_diskgroup_disks",
                         &py_g, &diskgroup))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_ldmtool_diskgroup_disks (g, diskgroup);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == NULL) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  py_r = put_string_list (r);
  guestfs_int_free_string_list (r);

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_LDMTOOL_DISKGROUP_NAME
static PyObject *
guestfs_int_py_ldmtool_diskgroup_name (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  char *r;
  const char *diskgroup;

  if (!PyArg_ParseTuple (args, (char *) "Os:guestfs_ldmtool_diskgroup_name",
                         &py_g, &diskgroup))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_ldmtool_diskgroup_name (g, diskgroup);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == NULL) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

#ifdef HAVE_PYSTRING_ASSTRING
  py_r = PyString_FromString (r);
#else
  py_r = PyUnicode_FromString (r);
#endif
  free (r);
  if (py_r == NULL) goto out;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_LDMTOOL_DISKGROUP_VOLUMES
static PyObject *
guestfs_int_py_ldmtool_diskgroup_volumes (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  char **r;
  const char *diskgroup;

  if (!PyArg_ParseTuple (args, (char *) "Os:guestfs_ldmtool_diskgroup_volumes",
                         &py_g, &diskgroup))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_ldmtool_diskgroup_volumes (g, diskgroup);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == NULL) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  py_r = put_string_list (r);
  guestfs_int_free_string_list (r);

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_LDMTOOL_REMOVE_ALL
static PyObject *
guestfs_int_py_ldmtool_remove_all (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;

  if (!PyArg_ParseTuple (args, (char *) "O:guestfs_ldmtool_remove_all",
                         &py_g))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_ldmtool_remove_all (g);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_LDMTOOL_SCAN
static PyObject *
guestfs_int_py_ldmtool_scan (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  char **r;

  if (!PyArg_ParseTuple (args, (char *) "O:guestfs_ldmtool_scan",
                         &py_g))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_ldmtool_scan (g);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == NULL) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  py_r = put_string_list (r);
  guestfs_int_free_string_list (r);

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_LDMTOOL_SCAN_DEVICES
static PyObject *
guestfs_int_py_ldmtool_scan_devices (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  char **r;
  PyObject *py_devices;
  char **devices = NULL;

  if (!PyArg_ParseTuple (args, (char *) "OO:guestfs_ldmtool_scan_devices",
                         &py_g, &py_devices))
    goto out;
  g = get_handle (py_g);
  devices = get_string_list (py_devices);
  if (!devices) goto out;

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_ldmtool_scan_devices (g, devices);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == NULL) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  py_r = put_string_list (r);
  guestfs_int_free_string_list (r);

  PyErr_Clear ();
 out:
  free (devices);
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_LDMTOOL_VOLUME_HINT
static PyObject *
guestfs_int_py_ldmtool_volume_hint (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  char *r;
  const char *diskgroup;
  const char *volume;

  if (!PyArg_ParseTuple (args, (char *) "Oss:guestfs_ldmtool_volume_hint",
                         &py_g, &diskgroup, &volume))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_ldmtool_volume_hint (g, diskgroup, volume);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == NULL) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

#ifdef HAVE_PYSTRING_ASSTRING
  py_r = PyString_FromString (r);
#else
  py_r = PyUnicode_FromString (r);
#endif
  free (r);
  if (py_r == NULL) goto out;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_LDMTOOL_VOLUME_PARTITIONS
static PyObject *
guestfs_int_py_ldmtool_volume_partitions (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  char **r;
  const char *diskgroup;
  const char *volume;

  if (!PyArg_ParseTuple (args, (char *) "Oss:guestfs_ldmtool_volume_partitions",
                         &py_g, &diskgroup, &volume))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_ldmtool_volume_partitions (g, diskgroup, volume);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == NULL) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  py_r = put_string_list (r);
  guestfs_int_free_string_list (r);

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_LDMTOOL_VOLUME_TYPE
static PyObject *
guestfs_int_py_ldmtool_volume_type (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  char *r;
  const char *diskgroup;
  const char *volume;

  if (!PyArg_ParseTuple (args, (char *) "Oss:guestfs_ldmtool_volume_type",
                         &py_g, &diskgroup, &volume))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_ldmtool_volume_type (g, diskgroup, volume);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == NULL) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

#ifdef HAVE_PYSTRING_ASSTRING
  py_r = PyString_FromString (r);
#else
  py_r = PyUnicode_FromString (r);
#endif
  free (r);
  if (py_r == NULL) goto out;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_LGETXATTR
static PyObject *
guestfs_int_py_lgetxattr (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  char *r;
  size_t size;
  const char *path;
  const char *name;

  if (!PyArg_ParseTuple (args, (char *) "Oss:guestfs_lgetxattr",
                         &py_g, &path, &name))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_lgetxattr (g, path, name, &size);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == NULL) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

#ifdef HAVE_PYSTRING_ASSTRING
  py_r = PyString_FromStringAndSize (r, size);
#else
  py_r = PyBytes_FromStringAndSize (r, size);
#endif
  free (r);
  if (py_r == NULL) goto out;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_LGETXATTRS
static PyObject *
guestfs_int_py_lgetxattrs (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  struct guestfs_xattr_list *r;
  const char *path;

  if (!PyArg_ParseTuple (args, (char *) "Os:guestfs_lgetxattrs",
                         &py_g, &path))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_lgetxattrs (g, path);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == NULL) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  py_r = put_xattr_list (r);
  guestfs_free_xattr_list (r);

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_LIST_9P
static PyObject *
guestfs_int_py_list_9p (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  char **r;

  if (!PyArg_ParseTuple (args, (char *) "O:guestfs_list_9p",
                         &py_g))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_list_9p (g);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == NULL) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  py_r = put_string_list (r);
  guestfs_int_free_string_list (r);

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_LIST_DEVICES
static PyObject *
guestfs_int_py_list_devices (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  char **r;

  if (!PyArg_ParseTuple (args, (char *) "O:guestfs_list_devices",
                         &py_g))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_list_devices (g);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == NULL) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  py_r = put_string_list (r);
  guestfs_int_free_string_list (r);

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_LIST_DISK_LABELS
static PyObject *
guestfs_int_py_list_disk_labels (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  char **r;

  if (!PyArg_ParseTuple (args, (char *) "O:guestfs_list_disk_labels",
                         &py_g))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_list_disk_labels (g);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == NULL) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  py_r = put_table (r);
  guestfs_int_free_string_list (r);

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_LIST_DM_DEVICES
static PyObject *
guestfs_int_py_list_dm_devices (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  char **r;

  if (!PyArg_ParseTuple (args, (char *) "O:guestfs_list_dm_devices",
                         &py_g))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_list_dm_devices (g);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == NULL) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  py_r = put_string_list (r);
  guestfs_int_free_string_list (r);

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_LIST_FILESYSTEMS
static PyObject *
guestfs_int_py_list_filesystems (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  char **r;

  if (!PyArg_ParseTuple (args, (char *) "O:guestfs_list_filesystems",
                         &py_g))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_list_filesystems (g);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == NULL) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  py_r = put_table (r);
  guestfs_int_free_string_list (r);

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_LIST_LDM_PARTITIONS
static PyObject *
guestfs_int_py_list_ldm_partitions (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  char **r;

  if (!PyArg_ParseTuple (args, (char *) "O:guestfs_list_ldm_partitions",
                         &py_g))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_list_ldm_partitions (g);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == NULL) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  py_r = put_string_list (r);
  guestfs_int_free_string_list (r);

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_LIST_LDM_VOLUMES
static PyObject *
guestfs_int_py_list_ldm_volumes (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  char **r;

  if (!PyArg_ParseTuple (args, (char *) "O:guestfs_list_ldm_volumes",
                         &py_g))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_list_ldm_volumes (g);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == NULL) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  py_r = put_string_list (r);
  guestfs_int_free_string_list (r);

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_LIST_MD_DEVICES
static PyObject *
guestfs_int_py_list_md_devices (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  char **r;

  if (!PyArg_ParseTuple (args, (char *) "O:guestfs_list_md_devices",
                         &py_g))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_list_md_devices (g);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == NULL) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  py_r = put_string_list (r);
  guestfs_int_free_string_list (r);

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_LIST_PARTITIONS
static PyObject *
guestfs_int_py_list_partitions (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  char **r;

  if (!PyArg_ParseTuple (args, (char *) "O:guestfs_list_partitions",
                         &py_g))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_list_partitions (g);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == NULL) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  py_r = put_string_list (r);
  guestfs_int_free_string_list (r);

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_LL
static PyObject *
guestfs_int_py_ll (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  char *r;
  const char *directory;

  if (!PyArg_ParseTuple (args, (char *) "Os:guestfs_ll",
                         &py_g, &directory))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_ll (g, directory);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == NULL) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

#ifdef HAVE_PYSTRING_ASSTRING
  py_r = PyString_FromString (r);
#else
  py_r = PyUnicode_FromString (r);
#endif
  free (r);
  if (py_r == NULL) goto out;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_LLZ
static PyObject *
guestfs_int_py_llz (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  char *r;
  const char *directory;

  if (!PyArg_ParseTuple (args, (char *) "Os:guestfs_llz",
                         &py_g, &directory))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_llz (g, directory);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == NULL) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

#ifdef HAVE_PYSTRING_ASSTRING
  py_r = PyString_FromString (r);
#else
  py_r = PyUnicode_FromString (r);
#endif
  free (r);
  if (py_r == NULL) goto out;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_LN
static PyObject *
guestfs_int_py_ln (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  const char *target;
  const char *linkname;

  if (!PyArg_ParseTuple (args, (char *) "Oss:guestfs_ln",
                         &py_g, &target, &linkname))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_ln (g, target, linkname);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_LN_F
static PyObject *
guestfs_int_py_ln_f (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  const char *target;
  const char *linkname;

  if (!PyArg_ParseTuple (args, (char *) "Oss:guestfs_ln_f",
                         &py_g, &target, &linkname))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_ln_f (g, target, linkname);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_LN_S
static PyObject *
guestfs_int_py_ln_s (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  const char *target;
  const char *linkname;

  if (!PyArg_ParseTuple (args, (char *) "Oss:guestfs_ln_s",
                         &py_g, &target, &linkname))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_ln_s (g, target, linkname);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_LN_SF
static PyObject *
guestfs_int_py_ln_sf (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  const char *target;
  const char *linkname;

  if (!PyArg_ParseTuple (args, (char *) "Oss:guestfs_ln_sf",
                         &py_g, &target, &linkname))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_ln_sf (g, target, linkname);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_LREMOVEXATTR
static PyObject *
guestfs_int_py_lremovexattr (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  const char *xattr;
  const char *path;

  if (!PyArg_ParseTuple (args, (char *) "Oss:guestfs_lremovexattr",
                         &py_g, &xattr, &path))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_lremovexattr (g, xattr, path);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_LS
static PyObject *
guestfs_int_py_ls (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  char **r;
  const char *directory;

  if (!PyArg_ParseTuple (args, (char *) "Os:guestfs_ls",
                         &py_g, &directory))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_ls (g, directory);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == NULL) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  py_r = put_string_list (r);
  guestfs_int_free_string_list (r);

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_LS0
static PyObject *
guestfs_int_py_ls0 (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  const char *dir;
  const char *filenames;

  if (!PyArg_ParseTuple (args, (char *) "Oss:guestfs_ls0",
                         &py_g, &dir, &filenames))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_ls0 (g, dir, filenames);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_LSETXATTR
static PyObject *
guestfs_int_py_lsetxattr (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  const char *xattr;
  const char *val;
  int vallen;
  const char *path;

  if (!PyArg_ParseTuple (args, (char *) "Ossis:guestfs_lsetxattr",
                         &py_g, &xattr, &val, &vallen, &path))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_lsetxattr (g, xattr, val, vallen, path);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_LSTAT
static PyObject *
guestfs_int_py_lstat (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  struct guestfs_stat *r;
  const char *path;

  if (!PyArg_ParseTuple (args, (char *) "Os:guestfs_lstat",
                         &py_g, &path))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_lstat (g, path);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == NULL) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  py_r = put_stat (r);
  guestfs_free_stat (r);

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_LSTATLIST
static PyObject *
guestfs_int_py_lstatlist (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  struct guestfs_stat_list *r;
  const char *path;
  PyObject *py_names;
  char **names = NULL;

  if (!PyArg_ParseTuple (args, (char *) "OsO:guestfs_lstatlist",
                         &py_g, &path, &py_names))
    goto out;
  g = get_handle (py_g);
  names = get_string_list (py_names);
  if (!names) goto out;

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_lstatlist (g, path, names);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == NULL) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  py_r = put_stat_list (r);
  guestfs_free_stat_list (r);

  PyErr_Clear ();
 out:
  free (names);
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_LSTATNS
static PyObject *
guestfs_int_py_lstatns (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  struct guestfs_statns *r;
  const char *path;

  if (!PyArg_ParseTuple (args, (char *) "Os:guestfs_lstatns",
                         &py_g, &path))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_lstatns (g, path);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == NULL) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  py_r = put_statns (r);
  guestfs_free_statns (r);

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_LSTATNSLIST
static PyObject *
guestfs_int_py_lstatnslist (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  struct guestfs_statns_list *r;
  const char *path;
  PyObject *py_names;
  char **names = NULL;

  if (!PyArg_ParseTuple (args, (char *) "OsO:guestfs_lstatnslist",
                         &py_g, &path, &py_names))
    goto out;
  g = get_handle (py_g);
  names = get_string_list (py_names);
  if (!names) goto out;

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_lstatnslist (g, path, names);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == NULL) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  py_r = put_statns_list (r);
  guestfs_free_statns_list (r);

  PyErr_Clear ();
 out:
  free (names);
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_LUKS_ADD_KEY
static PyObject *
guestfs_int_py_luks_add_key (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  const char *device;
  const char *key;
  const char *newkey;
  int keyslot;

  if (!PyArg_ParseTuple (args, (char *) "Osssi:guestfs_luks_add_key",
                         &py_g, &device, &key, &newkey, &keyslot))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_luks_add_key (g, device, key, newkey, keyslot);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_LUKS_CLOSE
static PyObject *
guestfs_int_py_luks_close (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  const char *device;

  if (!PyArg_ParseTuple (args, (char *) "Os:guestfs_luks_close",
                         &py_g, &device))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_luks_close (g, device);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_LUKS_FORMAT
static PyObject *
guestfs_int_py_luks_format (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  const char *device;
  const char *key;
  int keyslot;

  if (!PyArg_ParseTuple (args, (char *) "Ossi:guestfs_luks_format",
                         &py_g, &device, &key, &keyslot))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_luks_format (g, device, key, keyslot);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_LUKS_FORMAT_CIPHER
static PyObject *
guestfs_int_py_luks_format_cipher (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  const char *device;
  const char *key;
  int keyslot;
  const char *cipher;

  if (!PyArg_ParseTuple (args, (char *) "Ossis:guestfs_luks_format_cipher",
                         &py_g, &device, &key, &keyslot, &cipher))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_luks_format_cipher (g, device, key, keyslot, cipher);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_LUKS_KILL_SLOT
static PyObject *
guestfs_int_py_luks_kill_slot (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  const char *device;
  const char *key;
  int keyslot;

  if (!PyArg_ParseTuple (args, (char *) "Ossi:guestfs_luks_kill_slot",
                         &py_g, &device, &key, &keyslot))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_luks_kill_slot (g, device, key, keyslot);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_LUKS_OPEN
static PyObject *
guestfs_int_py_luks_open (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  const char *device;
  const char *key;
  const char *mapname;

  if (!PyArg_ParseTuple (args, (char *) "Osss:guestfs_luks_open",
                         &py_g, &device, &key, &mapname))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_luks_open (g, device, key, mapname);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_LUKS_OPEN_RO
static PyObject *
guestfs_int_py_luks_open_ro (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  const char *device;
  const char *key;
  const char *mapname;

  if (!PyArg_ParseTuple (args, (char *) "Osss:guestfs_luks_open_ro",
                         &py_g, &device, &key, &mapname))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_luks_open_ro (g, device, key, mapname);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_LVCREATE
static PyObject *
guestfs_int_py_lvcreate (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  const char *logvol;
  const char *volgroup;
  int mbytes;

  if (!PyArg_ParseTuple (args, (char *) "Ossi:guestfs_lvcreate",
                         &py_g, &logvol, &volgroup, &mbytes))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_lvcreate (g, logvol, volgroup, mbytes);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_LVCREATE_FREE
static PyObject *
guestfs_int_py_lvcreate_free (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  const char *logvol;
  const char *volgroup;
  int percent;

  if (!PyArg_ParseTuple (args, (char *) "Ossi:guestfs_lvcreate_free",
                         &py_g, &logvol, &volgroup, &percent))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_lvcreate_free (g, logvol, volgroup, percent);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_LVM_CANONICAL_LV_NAME
static PyObject *
guestfs_int_py_lvm_canonical_lv_name (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  char *r;
  const char *lvname;

  if (!PyArg_ParseTuple (args, (char *) "Os:guestfs_lvm_canonical_lv_name",
                         &py_g, &lvname))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_lvm_canonical_lv_name (g, lvname);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == NULL) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

#ifdef HAVE_PYSTRING_ASSTRING
  py_r = PyString_FromString (r);
#else
  py_r = PyUnicode_FromString (r);
#endif
  free (r);
  if (py_r == NULL) goto out;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_LVM_CLEAR_FILTER
static PyObject *
guestfs_int_py_lvm_clear_filter (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;

  if (!PyArg_ParseTuple (args, (char *) "O:guestfs_lvm_clear_filter",
                         &py_g))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_lvm_clear_filter (g);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_LVM_REMOVE_ALL
static PyObject *
guestfs_int_py_lvm_remove_all (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;

  if (!PyArg_ParseTuple (args, (char *) "O:guestfs_lvm_remove_all",
                         &py_g))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_lvm_remove_all (g);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_LVM_SET_FILTER
static PyObject *
guestfs_int_py_lvm_set_filter (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  PyObject *py_devices;
  char **devices = NULL;

  if (!PyArg_ParseTuple (args, (char *) "OO:guestfs_lvm_set_filter",
                         &py_g, &py_devices))
    goto out;
  g = get_handle (py_g);
  devices = get_string_list (py_devices);
  if (!devices) goto out;

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_lvm_set_filter (g, devices);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  free (devices);
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_LVREMOVE
static PyObject *
guestfs_int_py_lvremove (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  const char *device;

  if (!PyArg_ParseTuple (args, (char *) "Os:guestfs_lvremove",
                         &py_g, &device))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_lvremove (g, device);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_LVRENAME
static PyObject *
guestfs_int_py_lvrename (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  const char *logvol;
  const char *newlogvol;

  if (!PyArg_ParseTuple (args, (char *) "Oss:guestfs_lvrename",
                         &py_g, &logvol, &newlogvol))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_lvrename (g, logvol, newlogvol);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_LVRESIZE
static PyObject *
guestfs_int_py_lvresize (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  const char *device;
  int mbytes;

  if (!PyArg_ParseTuple (args, (char *) "Osi:guestfs_lvresize",
                         &py_g, &device, &mbytes))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_lvresize (g, device, mbytes);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_LVRESIZE_FREE
static PyObject *
guestfs_int_py_lvresize_free (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  const char *lv;
  int percent;

  if (!PyArg_ParseTuple (args, (char *) "Osi:guestfs_lvresize_free",
                         &py_g, &lv, &percent))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_lvresize_free (g, lv, percent);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_LVS
static PyObject *
guestfs_int_py_lvs (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  char **r;

  if (!PyArg_ParseTuple (args, (char *) "O:guestfs_lvs",
                         &py_g))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_lvs (g);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == NULL) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  py_r = put_string_list (r);
  guestfs_int_free_string_list (r);

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_LVS_FULL
static PyObject *
guestfs_int_py_lvs_full (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  struct guestfs_lvm_lv_list *r;

  if (!PyArg_ParseTuple (args, (char *) "O:guestfs_lvs_full",
                         &py_g))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_lvs_full (g);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == NULL) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  py_r = put_lvm_lv_list (r);
  guestfs_free_lvm_lv_list (r);

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_LVUUID
static PyObject *
guestfs_int_py_lvuuid (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  char *r;
  const char *device;

  if (!PyArg_ParseTuple (args, (char *) "Os:guestfs_lvuuid",
                         &py_g, &device))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_lvuuid (g, device);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == NULL) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

#ifdef HAVE_PYSTRING_ASSTRING
  py_r = PyString_FromString (r);
#else
  py_r = PyUnicode_FromString (r);
#endif
  free (r);
  if (py_r == NULL) goto out;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_LXATTRLIST
static PyObject *
guestfs_int_py_lxattrlist (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  struct guestfs_xattr_list *r;
  const char *path;
  PyObject *py_names;
  char **names = NULL;

  if (!PyArg_ParseTuple (args, (char *) "OsO:guestfs_lxattrlist",
                         &py_g, &path, &py_names))
    goto out;
  g = get_handle (py_g);
  names = get_string_list (py_names);
  if (!names) goto out;

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_lxattrlist (g, path, names);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == NULL) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  py_r = put_xattr_list (r);
  guestfs_free_xattr_list (r);

  PyErr_Clear ();
 out:
  free (names);
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_MAX_DISKS
static PyObject *
guestfs_int_py_max_disks (PyObject *self, PyObject *args)
{
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;

  if (!PyArg_ParseTuple (args, (char *) "O:guestfs_max_disks",
                         &py_g))
    goto out;
  g = get_handle (py_g);

  r = guestfs_max_disks (g);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  py_r = PyLong_FromLong ((long) r);

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_MD_CREATE
static PyObject *
guestfs_int_py_md_create (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  struct guestfs_md_create_argv optargs_s;
  struct guestfs_md_create_argv *optargs = &optargs_s;
  int r;
  const char *name;
  PyObject *py_devices;
  char **devices = NULL;
  PyObject *py_missingbitmap;
  PyObject *py_nrdevices;
  PyObject *py_spare;
  PyObject *py_chunk;
  PyObject *py_level;

  optargs_s.bitmask = 0;

  if (!PyArg_ParseTuple (args, (char *) "OsOOOOOO:guestfs_md_create",
                         &py_g, &name, &py_devices, &py_missingbitmap, &py_nrdevices, &py_spare, &py_chunk, &py_level))
    goto out;
  g = get_handle (py_g);
  devices = get_string_list (py_devices);
  if (!devices) goto out;

#ifdef GUESTFS_MD_CREATE_MISSINGBITMAP_BITMASK
  if (py_missingbitmap != Py_None) {
    optargs_s.bitmask |= GUESTFS_MD_CREATE_MISSINGBITMAP_BITMASK;
    optargs_s.missingbitmap = PyLong_AsLongLong (py_missingbitmap);
    if (PyErr_Occurred ()) goto out;
  }
#endif
#ifdef GUESTFS_MD_CREATE_NRDEVICES_BITMASK
  if (py_nrdevices != Py_None) {
    optargs_s.bitmask |= GUESTFS_MD_CREATE_NRDEVICES_BITMASK;
    optargs_s.nrdevices = PyLong_AsLong (py_nrdevices);
    if (PyErr_Occurred ()) goto out;
  }
#endif
#ifdef GUESTFS_MD_CREATE_SPARE_BITMASK
  if (py_spare != Py_None) {
    optargs_s.bitmask |= GUESTFS_MD_CREATE_SPARE_BITMASK;
    optargs_s.spare = PyLong_AsLong (py_spare);
    if (PyErr_Occurred ()) goto out;
  }
#endif
#ifdef GUESTFS_MD_CREATE_CHUNK_BITMASK
  if (py_chunk != Py_None) {
    optargs_s.bitmask |= GUESTFS_MD_CREATE_CHUNK_BITMASK;
    optargs_s.chunk = PyLong_AsLongLong (py_chunk);
    if (PyErr_Occurred ()) goto out;
  }
#endif
#ifdef GUESTFS_MD_CREATE_LEVEL_BITMASK
  if (py_level != Py_None) {
    optargs_s.bitmask |= GUESTFS_MD_CREATE_LEVEL_BITMASK;
#ifdef HAVE_PYSTRING_ASSTRING
    optargs_s.level = PyString_AsString (py_level);
#else
    PyObject *bytes;
    bytes = PyUnicode_AsUTF8String (py_level);
    optargs_s.level = PyBytes_AS_STRING (bytes);
#endif
  }
#endif

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_md_create_argv (g, name, devices, optargs);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  free (devices);
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_MD_DETAIL
static PyObject *
guestfs_int_py_md_detail (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  char **r;
  const char *md;

  if (!PyArg_ParseTuple (args, (char *) "Os:guestfs_md_detail",
                         &py_g, &md))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_md_detail (g, md);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == NULL) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  py_r = put_table (r);
  guestfs_int_free_string_list (r);

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_MD_STAT
static PyObject *
guestfs_int_py_md_stat (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  struct guestfs_mdstat_list *r;
  const char *md;

  if (!PyArg_ParseTuple (args, (char *) "Os:guestfs_md_stat",
                         &py_g, &md))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_md_stat (g, md);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == NULL) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  py_r = put_mdstat_list (r);
  guestfs_free_mdstat_list (r);

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_MD_STOP
static PyObject *
guestfs_int_py_md_stop (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  const char *md;

  if (!PyArg_ParseTuple (args, (char *) "Os:guestfs_md_stop",
                         &py_g, &md))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_md_stop (g, md);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_MKDIR
static PyObject *
guestfs_int_py_mkdir (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  const char *path;

  if (!PyArg_ParseTuple (args, (char *) "Os:guestfs_mkdir",
                         &py_g, &path))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_mkdir (g, path);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_MKDIR_MODE
static PyObject *
guestfs_int_py_mkdir_mode (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  const char *path;
  int mode;

  if (!PyArg_ParseTuple (args, (char *) "Osi:guestfs_mkdir_mode",
                         &py_g, &path, &mode))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_mkdir_mode (g, path, mode);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_MKDIR_P
static PyObject *
guestfs_int_py_mkdir_p (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  const char *path;

  if (!PyArg_ParseTuple (args, (char *) "Os:guestfs_mkdir_p",
                         &py_g, &path))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_mkdir_p (g, path);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_MKDTEMP
static PyObject *
guestfs_int_py_mkdtemp (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  char *r;
  const char *tmpl;

  if (!PyArg_ParseTuple (args, (char *) "Os:guestfs_mkdtemp",
                         &py_g, &tmpl))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_mkdtemp (g, tmpl);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == NULL) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

#ifdef HAVE_PYSTRING_ASSTRING
  py_r = PyString_FromString (r);
#else
  py_r = PyUnicode_FromString (r);
#endif
  free (r);
  if (py_r == NULL) goto out;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_MKE2FS
static PyObject *
guestfs_int_py_mke2fs (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  struct guestfs_mke2fs_argv optargs_s;
  struct guestfs_mke2fs_argv *optargs = &optargs_s;
  int r;
  const char *device;
  PyObject *py_blockscount;
  PyObject *py_blocksize;
  PyObject *py_fragsize;
  PyObject *py_blockspergroup;
  PyObject *py_numberofgroups;
  PyObject *py_bytesperinode;
  PyObject *py_inodesize;
  PyObject *py_journalsize;
  PyObject *py_numberofinodes;
  PyObject *py_stridesize;
  PyObject *py_stripewidth;
  PyObject *py_maxonlineresize;
  PyObject *py_reservedblockspercentage;
  PyObject *py_mmpupdateinterval;
  PyObject *py_journaldevice;
  PyObject *py_label;
  PyObject *py_lastmounteddir;
  PyObject *py_creatoros;
  PyObject *py_fstype;
  PyObject *py_usagetype;
  PyObject *py_uuid;
  PyObject *py_forcecreate;
  PyObject *py_writesbandgrouponly;
  PyObject *py_lazyitableinit;
  PyObject *py_lazyjournalinit;
  PyObject *py_testfs;
  PyObject *py_discard;
  PyObject *py_quotatype;
  PyObject *py_extent;
  PyObject *py_filetype;
  PyObject *py_flexbg;
  PyObject *py_hasjournal;
  PyObject *py_journaldev;
  PyObject *py_largefile;
  PyObject *py_quota;
  PyObject *py_resizeinode;
  PyObject *py_sparsesuper;
  PyObject *py_uninitbg;

  optargs_s.bitmask = 0;

  if (!PyArg_ParseTuple (args, (char *) "OsOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO:guestfs_mke2fs",
                         &py_g, &device, &py_blockscount, &py_blocksize, &py_fragsize, &py_blockspergroup, &py_numberofgroups, &py_bytesperinode, &py_inodesize, &py_journalsize, &py_numberofinodes, &py_stridesize, &py_stripewidth, &py_maxonlineresize, &py_reservedblockspercentage, &py_mmpupdateinterval, &py_journaldevice, &py_label, &py_lastmounteddir, &py_creatoros, &py_fstype, &py_usagetype, &py_uuid, &py_forcecreate, &py_writesbandgrouponly, &py_lazyitableinit, &py_lazyjournalinit, &py_testfs, &py_discard, &py_quotatype, &py_extent, &py_filetype, &py_flexbg, &py_hasjournal, &py_journaldev, &py_largefile, &py_quota, &py_resizeinode, &py_sparsesuper, &py_uninitbg))
    goto out;
  g = get_handle (py_g);

#ifdef GUESTFS_MKE2FS_BLOCKSCOUNT_BITMASK
  if (py_blockscount != Py_None) {
    optargs_s.bitmask |= GUESTFS_MKE2FS_BLOCKSCOUNT_BITMASK;
    optargs_s.blockscount = PyLong_AsLongLong (py_blockscount);
    if (PyErr_Occurred ()) goto out;
  }
#endif
#ifdef GUESTFS_MKE2FS_BLOCKSIZE_BITMASK
  if (py_blocksize != Py_None) {
    optargs_s.bitmask |= GUESTFS_MKE2FS_BLOCKSIZE_BITMASK;
    optargs_s.blocksize = PyLong_AsLongLong (py_blocksize);
    if (PyErr_Occurred ()) goto out;
  }
#endif
#ifdef GUESTFS_MKE2FS_FRAGSIZE_BITMASK
  if (py_fragsize != Py_None) {
    optargs_s.bitmask |= GUESTFS_MKE2FS_FRAGSIZE_BITMASK;
    optargs_s.fragsize = PyLong_AsLongLong (py_fragsize);
    if (PyErr_Occurred ()) goto out;
  }
#endif
#ifdef GUESTFS_MKE2FS_BLOCKSPERGROUP_BITMASK
  if (py_blockspergroup != Py_None) {
    optargs_s.bitmask |= GUESTFS_MKE2FS_BLOCKSPERGROUP_BITMASK;
    optargs_s.blockspergroup = PyLong_AsLongLong (py_blockspergroup);
    if (PyErr_Occurred ()) goto out;
  }
#endif
#ifdef GUESTFS_MKE2FS_NUMBEROFGROUPS_BITMASK
  if (py_numberofgroups != Py_None) {
    optargs_s.bitmask |= GUESTFS_MKE2FS_NUMBEROFGROUPS_BITMASK;
    optargs_s.numberofgroups = PyLong_AsLongLong (py_numberofgroups);
    if (PyErr_Occurred ()) goto out;
  }
#endif
#ifdef GUESTFS_MKE2FS_BYTESPERINODE_BITMASK
  if (py_bytesperinode != Py_None) {
    optargs_s.bitmask |= GUESTFS_MKE2FS_BYTESPERINODE_BITMASK;
    optargs_s.bytesperinode = PyLong_AsLongLong (py_bytesperinode);
    if (PyErr_Occurred ()) goto out;
  }
#endif
#ifdef GUESTFS_MKE2FS_INODESIZE_BITMASK
  if (py_inodesize != Py_None) {
    optargs_s.bitmask |= GUESTFS_MKE2FS_INODESIZE_BITMASK;
    optargs_s.inodesize = PyLong_AsLongLong (py_inodesize);
    if (PyErr_Occurred ()) goto out;
  }
#endif
#ifdef GUESTFS_MKE2FS_JOURNALSIZE_BITMASK
  if (py_journalsize != Py_None) {
    optargs_s.bitmask |= GUESTFS_MKE2FS_JOURNALSIZE_BITMASK;
    optargs_s.journalsize = PyLong_AsLongLong (py_journalsize);
    if (PyErr_Occurred ()) goto out;
  }
#endif
#ifdef GUESTFS_MKE2FS_NUMBEROFINODES_BITMASK
  if (py_numberofinodes != Py_None) {
    optargs_s.bitmask |= GUESTFS_MKE2FS_NUMBEROFINODES_BITMASK;
    optargs_s.numberofinodes = PyLong_AsLongLong (py_numberofinodes);
    if (PyErr_Occurred ()) goto out;
  }
#endif
#ifdef GUESTFS_MKE2FS_STRIDESIZE_BITMASK
  if (py_stridesize != Py_None) {
    optargs_s.bitmask |= GUESTFS_MKE2FS_STRIDESIZE_BITMASK;
    optargs_s.stridesize = PyLong_AsLongLong (py_stridesize);
    if (PyErr_Occurred ()) goto out;
  }
#endif
#ifdef GUESTFS_MKE2FS_STRIPEWIDTH_BITMASK
  if (py_stripewidth != Py_None) {
    optargs_s.bitmask |= GUESTFS_MKE2FS_STRIPEWIDTH_BITMASK;
    optargs_s.stripewidth = PyLong_AsLongLong (py_stripewidth);
    if (PyErr_Occurred ()) goto out;
  }
#endif
#ifdef GUESTFS_MKE2FS_MAXONLINERESIZE_BITMASK
  if (py_maxonlineresize != Py_None) {
    optargs_s.bitmask |= GUESTFS_MKE2FS_MAXONLINERESIZE_BITMASK;
    optargs_s.maxonlineresize = PyLong_AsLongLong (py_maxonlineresize);
    if (PyErr_Occurred ()) goto out;
  }
#endif
#ifdef GUESTFS_MKE2FS_RESERVEDBLOCKSPERCENTAGE_BITMASK
  if (py_reservedblockspercentage != Py_None) {
    optargs_s.bitmask |= GUESTFS_MKE2FS_RESERVEDBLOCKSPERCENTAGE_BITMASK;
    optargs_s.reservedblockspercentage = PyLong_AsLong (py_reservedblockspercentage);
    if (PyErr_Occurred ()) goto out;
  }
#endif
#ifdef GUESTFS_MKE2FS_MMPUPDATEINTERVAL_BITMASK
  if (py_mmpupdateinterval != Py_None) {
    optargs_s.bitmask |= GUESTFS_MKE2FS_MMPUPDATEINTERVAL_BITMASK;
    optargs_s.mmpupdateinterval = PyLong_AsLong (py_mmpupdateinterval);
    if (PyErr_Occurred ()) goto out;
  }
#endif
#ifdef GUESTFS_MKE2FS_JOURNALDEVICE_BITMASK
  if (py_journaldevice != Py_None) {
    optargs_s.bitmask |= GUESTFS_MKE2FS_JOURNALDEVICE_BITMASK;
#ifdef HAVE_PYSTRING_ASSTRING
    optargs_s.journaldevice = PyString_AsString (py_journaldevice);
#else
    PyObject *bytes;
    bytes = PyUnicode_AsUTF8String (py_journaldevice);
    optargs_s.journaldevice = PyBytes_AS_STRING (bytes);
#endif
  }
#endif
#ifdef GUESTFS_MKE2FS_LABEL_BITMASK
  if (py_label != Py_None) {
    optargs_s.bitmask |= GUESTFS_MKE2FS_LABEL_BITMASK;
#ifdef HAVE_PYSTRING_ASSTRING
    optargs_s.label = PyString_AsString (py_label);
#else
    PyObject *bytes;
    bytes = PyUnicode_AsUTF8String (py_label);
    optargs_s.label = PyBytes_AS_STRING (bytes);
#endif
  }
#endif
#ifdef GUESTFS_MKE2FS_LASTMOUNTEDDIR_BITMASK
  if (py_lastmounteddir != Py_None) {
    optargs_s.bitmask |= GUESTFS_MKE2FS_LASTMOUNTEDDIR_BITMASK;
#ifdef HAVE_PYSTRING_ASSTRING
    optargs_s.lastmounteddir = PyString_AsString (py_lastmounteddir);
#else
    PyObject *bytes;
    bytes = PyUnicode_AsUTF8String (py_lastmounteddir);
    optargs_s.lastmounteddir = PyBytes_AS_STRING (bytes);
#endif
  }
#endif
#ifdef GUESTFS_MKE2FS_CREATOROS_BITMASK
  if (py_creatoros != Py_None) {
    optargs_s.bitmask |= GUESTFS_MKE2FS_CREATOROS_BITMASK;
#ifdef HAVE_PYSTRING_ASSTRING
    optargs_s.creatoros = PyString_AsString (py_creatoros);
#else
    PyObject *bytes;
    bytes = PyUnicode_AsUTF8String (py_creatoros);
    optargs_s.creatoros = PyBytes_AS_STRING (bytes);
#endif
  }
#endif
#ifdef GUESTFS_MKE2FS_FSTYPE_BITMASK
  if (py_fstype != Py_None) {
    optargs_s.bitmask |= GUESTFS_MKE2FS_FSTYPE_BITMASK;
#ifdef HAVE_PYSTRING_ASSTRING
    optargs_s.fstype = PyString_AsString (py_fstype);
#else
    PyObject *bytes;
    bytes = PyUnicode_AsUTF8String (py_fstype);
    optargs_s.fstype = PyBytes_AS_STRING (bytes);
#endif
  }
#endif
#ifdef GUESTFS_MKE2FS_USAGETYPE_BITMASK
  if (py_usagetype != Py_None) {
    optargs_s.bitmask |= GUESTFS_MKE2FS_USAGETYPE_BITMASK;
#ifdef HAVE_PYSTRING_ASSTRING
    optargs_s.usagetype = PyString_AsString (py_usagetype);
#else
    PyObject *bytes;
    bytes = PyUnicode_AsUTF8String (py_usagetype);
    optargs_s.usagetype = PyBytes_AS_STRING (bytes);
#endif
  }
#endif
#ifdef GUESTFS_MKE2FS_UUID_BITMASK
  if (py_uuid != Py_None) {
    optargs_s.bitmask |= GUESTFS_MKE2FS_UUID_BITMASK;
#ifdef HAVE_PYSTRING_ASSTRING
    optargs_s.uuid = PyString_AsString (py_uuid);
#else
    PyObject *bytes;
    bytes = PyUnicode_AsUTF8String (py_uuid);
    optargs_s.uuid = PyBytes_AS_STRING (bytes);
#endif
  }
#endif
#ifdef GUESTFS_MKE2FS_FORCECREATE_BITMASK
  if (py_forcecreate != Py_None) {
    optargs_s.bitmask |= GUESTFS_MKE2FS_FORCECREATE_BITMASK;
    optargs_s.forcecreate = PyLong_AsLong (py_forcecreate);
    if (PyErr_Occurred ()) goto out;
  }
#endif
#ifdef GUESTFS_MKE2FS_WRITESBANDGROUPONLY_BITMASK
  if (py_writesbandgrouponly != Py_None) {
    optargs_s.bitmask |= GUESTFS_MKE2FS_WRITESBANDGROUPONLY_BITMASK;
    optargs_s.writesbandgrouponly = PyLong_AsLong (py_writesbandgrouponly);
    if (PyErr_Occurred ()) goto out;
  }
#endif
#ifdef GUESTFS_MKE2FS_LAZYITABLEINIT_BITMASK
  if (py_lazyitableinit != Py_None) {
    optargs_s.bitmask |= GUESTFS_MKE2FS_LAZYITABLEINIT_BITMASK;
    optargs_s.lazyitableinit = PyLong_AsLong (py_lazyitableinit);
    if (PyErr_Occurred ()) goto out;
  }
#endif
#ifdef GUESTFS_MKE2FS_LAZYJOURNALINIT_BITMASK
  if (py_lazyjournalinit != Py_None) {
    optargs_s.bitmask |= GUESTFS_MKE2FS_LAZYJOURNALINIT_BITMASK;
    optargs_s.lazyjournalinit = PyLong_AsLong (py_lazyjournalinit);
    if (PyErr_Occurred ()) goto out;
  }
#endif
#ifdef GUESTFS_MKE2FS_TESTFS_BITMASK
  if (py_testfs != Py_None) {
    optargs_s.bitmask |= GUESTFS_MKE2FS_TESTFS_BITMASK;
    optargs_s.testfs = PyLong_AsLong (py_testfs);
    if (PyErr_Occurred ()) goto out;
  }
#endif
#ifdef GUESTFS_MKE2FS_DISCARD_BITMASK
  if (py_discard != Py_None) {
    optargs_s.bitmask |= GUESTFS_MKE2FS_DISCARD_BITMASK;
    optargs_s.discard = PyLong_AsLong (py_discard);
    if (PyErr_Occurred ()) goto out;
  }
#endif
#ifdef GUESTFS_MKE2FS_QUOTATYPE_BITMASK
  if (py_quotatype != Py_None) {
    optargs_s.bitmask |= GUESTFS_MKE2FS_QUOTATYPE_BITMASK;
    optargs_s.quotatype = PyLong_AsLong (py_quotatype);
    if (PyErr_Occurred ()) goto out;
  }
#endif
#ifdef GUESTFS_MKE2FS_EXTENT_BITMASK
  if (py_extent != Py_None) {
    optargs_s.bitmask |= GUESTFS_MKE2FS_EXTENT_BITMASK;
    optargs_s.extent = PyLong_AsLong (py_extent);
    if (PyErr_Occurred ()) goto out;
  }
#endif
#ifdef GUESTFS_MKE2FS_FILETYPE_BITMASK
  if (py_filetype != Py_None) {
    optargs_s.bitmask |= GUESTFS_MKE2FS_FILETYPE_BITMASK;
    optargs_s.filetype = PyLong_AsLong (py_filetype);
    if (PyErr_Occurred ()) goto out;
  }
#endif
#ifdef GUESTFS_MKE2FS_FLEXBG_BITMASK
  if (py_flexbg != Py_None) {
    optargs_s.bitmask |= GUESTFS_MKE2FS_FLEXBG_BITMASK;
    optargs_s.flexbg = PyLong_AsLong (py_flexbg);
    if (PyErr_Occurred ()) goto out;
  }
#endif
#ifdef GUESTFS_MKE2FS_HASJOURNAL_BITMASK
  if (py_hasjournal != Py_None) {
    optargs_s.bitmask |= GUESTFS_MKE2FS_HASJOURNAL_BITMASK;
    optargs_s.hasjournal = PyLong_AsLong (py_hasjournal);
    if (PyErr_Occurred ()) goto out;
  }
#endif
#ifdef GUESTFS_MKE2FS_JOURNALDEV_BITMASK
  if (py_journaldev != Py_None) {
    optargs_s.bitmask |= GUESTFS_MKE2FS_JOURNALDEV_BITMASK;
    optargs_s.journaldev = PyLong_AsLong (py_journaldev);
    if (PyErr_Occurred ()) goto out;
  }
#endif
#ifdef GUESTFS_MKE2FS_LARGEFILE_BITMASK
  if (py_largefile != Py_None) {
    optargs_s.bitmask |= GUESTFS_MKE2FS_LARGEFILE_BITMASK;
    optargs_s.largefile = PyLong_AsLong (py_largefile);
    if (PyErr_Occurred ()) goto out;
  }
#endif
#ifdef GUESTFS_MKE2FS_QUOTA_BITMASK
  if (py_quota != Py_None) {
    optargs_s.bitmask |= GUESTFS_MKE2FS_QUOTA_BITMASK;
    optargs_s.quota = PyLong_AsLong (py_quota);
    if (PyErr_Occurred ()) goto out;
  }
#endif
#ifdef GUESTFS_MKE2FS_RESIZEINODE_BITMASK
  if (py_resizeinode != Py_None) {
    optargs_s.bitmask |= GUESTFS_MKE2FS_RESIZEINODE_BITMASK;
    optargs_s.resizeinode = PyLong_AsLong (py_resizeinode);
    if (PyErr_Occurred ()) goto out;
  }
#endif
#ifdef GUESTFS_MKE2FS_SPARSESUPER_BITMASK
  if (py_sparsesuper != Py_None) {
    optargs_s.bitmask |= GUESTFS_MKE2FS_SPARSESUPER_BITMASK;
    optargs_s.sparsesuper = PyLong_AsLong (py_sparsesuper);
    if (PyErr_Occurred ()) goto out;
  }
#endif
#ifdef GUESTFS_MKE2FS_UNINITBG_BITMASK
  if (py_uninitbg != Py_None) {
    optargs_s.bitmask |= GUESTFS_MKE2FS_UNINITBG_BITMASK;
    optargs_s.uninitbg = PyLong_AsLong (py_uninitbg);
    if (PyErr_Occurred ()) goto out;
  }
#endif

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_mke2fs_argv (g, device, optargs);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_MKE2FS_J
static PyObject *
guestfs_int_py_mke2fs_J (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  const char *fstype;
  int blocksize;
  const char *device;
  const char *journal;

  if (!PyArg_ParseTuple (args, (char *) "Osiss:guestfs_mke2fs_J",
                         &py_g, &fstype, &blocksize, &device, &journal))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_mke2fs_J (g, fstype, blocksize, device, journal);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_MKE2FS_JL
static PyObject *
guestfs_int_py_mke2fs_JL (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  const char *fstype;
  int blocksize;
  const char *device;
  const char *label;

  if (!PyArg_ParseTuple (args, (char *) "Osiss:guestfs_mke2fs_JL",
                         &py_g, &fstype, &blocksize, &device, &label))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_mke2fs_JL (g, fstype, blocksize, device, label);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_MKE2FS_JU
static PyObject *
guestfs_int_py_mke2fs_JU (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  const char *fstype;
  int blocksize;
  const char *device;
  const char *uuid;

  if (!PyArg_ParseTuple (args, (char *) "Osiss:guestfs_mke2fs_JU",
                         &py_g, &fstype, &blocksize, &device, &uuid))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_mke2fs_JU (g, fstype, blocksize, device, uuid);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_MKE2JOURNAL
static PyObject *
guestfs_int_py_mke2journal (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  int blocksize;
  const char *device;

  if (!PyArg_ParseTuple (args, (char *) "Ois:guestfs_mke2journal",
                         &py_g, &blocksize, &device))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_mke2journal (g, blocksize, device);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_MKE2JOURNAL_L
static PyObject *
guestfs_int_py_mke2journal_L (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  int blocksize;
  const char *label;
  const char *device;

  if (!PyArg_ParseTuple (args, (char *) "Oiss:guestfs_mke2journal_L",
                         &py_g, &blocksize, &label, &device))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_mke2journal_L (g, blocksize, label, device);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_MKE2JOURNAL_U
static PyObject *
guestfs_int_py_mke2journal_U (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  int blocksize;
  const char *uuid;
  const char *device;

  if (!PyArg_ParseTuple (args, (char *) "Oiss:guestfs_mke2journal_U",
                         &py_g, &blocksize, &uuid, &device))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_mke2journal_U (g, blocksize, uuid, device);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_MKFIFO
static PyObject *
guestfs_int_py_mkfifo (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  int mode;
  const char *path;

  if (!PyArg_ParseTuple (args, (char *) "Ois:guestfs_mkfifo",
                         &py_g, &mode, &path))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_mkfifo (g, mode, path);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_MKFS_OPTS
static PyObject *
guestfs_int_py_mkfs (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  struct guestfs_mkfs_opts_argv optargs_s;
  struct guestfs_mkfs_opts_argv *optargs = &optargs_s;
  int r;
  const char *fstype;
  const char *device;
  PyObject *py_blocksize;
  PyObject *py_features;
  PyObject *py_inode;
  PyObject *py_sectorsize;
  PyObject *py_label;

  optargs_s.bitmask = 0;

  if (!PyArg_ParseTuple (args, (char *) "OssOOOOO:guestfs_mkfs",
                         &py_g, &fstype, &device, &py_blocksize, &py_features, &py_inode, &py_sectorsize, &py_label))
    goto out;
  g = get_handle (py_g);

#ifdef GUESTFS_MKFS_OPTS_BLOCKSIZE_BITMASK
  if (py_blocksize != Py_None) {
    optargs_s.bitmask |= GUESTFS_MKFS_OPTS_BLOCKSIZE_BITMASK;
    optargs_s.blocksize = PyLong_AsLong (py_blocksize);
    if (PyErr_Occurred ()) goto out;
  }
#endif
#ifdef GUESTFS_MKFS_OPTS_FEATURES_BITMASK
  if (py_features != Py_None) {
    optargs_s.bitmask |= GUESTFS_MKFS_OPTS_FEATURES_BITMASK;
#ifdef HAVE_PYSTRING_ASSTRING
    optargs_s.features = PyString_AsString (py_features);
#else
    PyObject *bytes;
    bytes = PyUnicode_AsUTF8String (py_features);
    optargs_s.features = PyBytes_AS_STRING (bytes);
#endif
  }
#endif
#ifdef GUESTFS_MKFS_OPTS_INODE_BITMASK
  if (py_inode != Py_None) {
    optargs_s.bitmask |= GUESTFS_MKFS_OPTS_INODE_BITMASK;
    optargs_s.inode = PyLong_AsLong (py_inode);
    if (PyErr_Occurred ()) goto out;
  }
#endif
#ifdef GUESTFS_MKFS_OPTS_SECTORSIZE_BITMASK
  if (py_sectorsize != Py_None) {
    optargs_s.bitmask |= GUESTFS_MKFS_OPTS_SECTORSIZE_BITMASK;
    optargs_s.sectorsize = PyLong_AsLong (py_sectorsize);
    if (PyErr_Occurred ()) goto out;
  }
#endif
#ifdef GUESTFS_MKFS_OPTS_LABEL_BITMASK
  if (py_label != Py_None) {
    optargs_s.bitmask |= GUESTFS_MKFS_OPTS_LABEL_BITMASK;
#ifdef HAVE_PYSTRING_ASSTRING
    optargs_s.label = PyString_AsString (py_label);
#else
    PyObject *bytes;
    bytes = PyUnicode_AsUTF8String (py_label);
    optargs_s.label = PyBytes_AS_STRING (bytes);
#endif
  }
#endif

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_mkfs_opts_argv (g, fstype, device, optargs);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_MKFS_B
static PyObject *
guestfs_int_py_mkfs_b (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  const char *fstype;
  int blocksize;
  const char *device;

  if (!PyArg_ParseTuple (args, (char *) "Osis:guestfs_mkfs_b",
                         &py_g, &fstype, &blocksize, &device))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_mkfs_b (g, fstype, blocksize, device);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_MKFS_BTRFS
static PyObject *
guestfs_int_py_mkfs_btrfs (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  struct guestfs_mkfs_btrfs_argv optargs_s;
  struct guestfs_mkfs_btrfs_argv *optargs = &optargs_s;
  int r;
  PyObject *py_devices;
  char **devices = NULL;
  PyObject *py_allocstart;
  PyObject *py_bytecount;
  PyObject *py_datatype;
  PyObject *py_leafsize;
  PyObject *py_label;
  PyObject *py_metadata;
  PyObject *py_nodesize;
  PyObject *py_sectorsize;

  optargs_s.bitmask = 0;

  if (!PyArg_ParseTuple (args, (char *) "OOOOOOOOOO:guestfs_mkfs_btrfs",
                         &py_g, &py_devices, &py_allocstart, &py_bytecount, &py_datatype, &py_leafsize, &py_label, &py_metadata, &py_nodesize, &py_sectorsize))
    goto out;
  g = get_handle (py_g);
  devices = get_string_list (py_devices);
  if (!devices) goto out;

#ifdef GUESTFS_MKFS_BTRFS_ALLOCSTART_BITMASK
  if (py_allocstart != Py_None) {
    optargs_s.bitmask |= GUESTFS_MKFS_BTRFS_ALLOCSTART_BITMASK;
    optargs_s.allocstart = PyLong_AsLongLong (py_allocstart);
    if (PyErr_Occurred ()) goto out;
  }
#endif
#ifdef GUESTFS_MKFS_BTRFS_BYTECOUNT_BITMASK
  if (py_bytecount != Py_None) {
    optargs_s.bitmask |= GUESTFS_MKFS_BTRFS_BYTECOUNT_BITMASK;
    optargs_s.bytecount = PyLong_AsLongLong (py_bytecount);
    if (PyErr_Occurred ()) goto out;
  }
#endif
#ifdef GUESTFS_MKFS_BTRFS_DATATYPE_BITMASK
  if (py_datatype != Py_None) {
    optargs_s.bitmask |= GUESTFS_MKFS_BTRFS_DATATYPE_BITMASK;
#ifdef HAVE_PYSTRING_ASSTRING
    optargs_s.datatype = PyString_AsString (py_datatype);
#else
    PyObject *bytes;
    bytes = PyUnicode_AsUTF8String (py_datatype);
    optargs_s.datatype = PyBytes_AS_STRING (bytes);
#endif
  }
#endif
#ifdef GUESTFS_MKFS_BTRFS_LEAFSIZE_BITMASK
  if (py_leafsize != Py_None) {
    optargs_s.bitmask |= GUESTFS_MKFS_BTRFS_LEAFSIZE_BITMASK;
    optargs_s.leafsize = PyLong_AsLong (py_leafsize);
    if (PyErr_Occurred ()) goto out;
  }
#endif
#ifdef GUESTFS_MKFS_BTRFS_LABEL_BITMASK
  if (py_label != Py_None) {
    optargs_s.bitmask |= GUESTFS_MKFS_BTRFS_LABEL_BITMASK;
#ifdef HAVE_PYSTRING_ASSTRING
    optargs_s.label = PyString_AsString (py_label);
#else
    PyObject *bytes;
    bytes = PyUnicode_AsUTF8String (py_label);
    optargs_s.label = PyBytes_AS_STRING (bytes);
#endif
  }
#endif
#ifdef GUESTFS_MKFS_BTRFS_METADATA_BITMASK
  if (py_metadata != Py_None) {
    optargs_s.bitmask |= GUESTFS_MKFS_BTRFS_METADATA_BITMASK;
#ifdef HAVE_PYSTRING_ASSTRING
    optargs_s.metadata = PyString_AsString (py_metadata);
#else
    PyObject *bytes;
    bytes = PyUnicode_AsUTF8String (py_metadata);
    optargs_s.metadata = PyBytes_AS_STRING (bytes);
#endif
  }
#endif
#ifdef GUESTFS_MKFS_BTRFS_NODESIZE_BITMASK
  if (py_nodesize != Py_None) {
    optargs_s.bitmask |= GUESTFS_MKFS_BTRFS_NODESIZE_BITMASK;
    optargs_s.nodesize = PyLong_AsLong (py_nodesize);
    if (PyErr_Occurred ()) goto out;
  }
#endif
#ifdef GUESTFS_MKFS_BTRFS_SECTORSIZE_BITMASK
  if (py_sectorsize != Py_None) {
    optargs_s.bitmask |= GUESTFS_MKFS_BTRFS_SECTORSIZE_BITMASK;
    optargs_s.sectorsize = PyLong_AsLong (py_sectorsize);
    if (PyErr_Occurred ()) goto out;
  }
#endif

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_mkfs_btrfs_argv (g, devices, optargs);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  free (devices);
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_MKLOST_AND_FOUND
static PyObject *
guestfs_int_py_mklost_and_found (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  const char *mountpoint;

  if (!PyArg_ParseTuple (args, (char *) "Os:guestfs_mklost_and_found",
                         &py_g, &mountpoint))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_mklost_and_found (g, mountpoint);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_MKMOUNTPOINT
static PyObject *
guestfs_int_py_mkmountpoint (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  const char *exemptpath;

  if (!PyArg_ParseTuple (args, (char *) "Os:guestfs_mkmountpoint",
                         &py_g, &exemptpath))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_mkmountpoint (g, exemptpath);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_MKNOD
static PyObject *
guestfs_int_py_mknod (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  int mode;
  int devmajor;
  int devminor;
  const char *path;

  if (!PyArg_ParseTuple (args, (char *) "Oiiis:guestfs_mknod",
                         &py_g, &mode, &devmajor, &devminor, &path))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_mknod (g, mode, devmajor, devminor, path);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_MKNOD_B
static PyObject *
guestfs_int_py_mknod_b (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  int mode;
  int devmajor;
  int devminor;
  const char *path;

  if (!PyArg_ParseTuple (args, (char *) "Oiiis:guestfs_mknod_b",
                         &py_g, &mode, &devmajor, &devminor, &path))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_mknod_b (g, mode, devmajor, devminor, path);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_MKNOD_C
static PyObject *
guestfs_int_py_mknod_c (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  int mode;
  int devmajor;
  int devminor;
  const char *path;

  if (!PyArg_ParseTuple (args, (char *) "Oiiis:guestfs_mknod_c",
                         &py_g, &mode, &devmajor, &devminor, &path))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_mknod_c (g, mode, devmajor, devminor, path);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_MKSWAP_OPTS
static PyObject *
guestfs_int_py_mkswap (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  struct guestfs_mkswap_opts_argv optargs_s;
  struct guestfs_mkswap_opts_argv *optargs = &optargs_s;
  int r;
  const char *device;
  PyObject *py_label;
  PyObject *py_uuid;

  optargs_s.bitmask = 0;

  if (!PyArg_ParseTuple (args, (char *) "OsOO:guestfs_mkswap",
                         &py_g, &device, &py_label, &py_uuid))
    goto out;
  g = get_handle (py_g);

#ifdef GUESTFS_MKSWAP_OPTS_LABEL_BITMASK
  if (py_label != Py_None) {
    optargs_s.bitmask |= GUESTFS_MKSWAP_OPTS_LABEL_BITMASK;
#ifdef HAVE_PYSTRING_ASSTRING
    optargs_s.label = PyString_AsString (py_label);
#else
    PyObject *bytes;
    bytes = PyUnicode_AsUTF8String (py_label);
    optargs_s.label = PyBytes_AS_STRING (bytes);
#endif
  }
#endif
#ifdef GUESTFS_MKSWAP_OPTS_UUID_BITMASK
  if (py_uuid != Py_None) {
    optargs_s.bitmask |= GUESTFS_MKSWAP_OPTS_UUID_BITMASK;
#ifdef HAVE_PYSTRING_ASSTRING
    optargs_s.uuid = PyString_AsString (py_uuid);
#else
    PyObject *bytes;
    bytes = PyUnicode_AsUTF8String (py_uuid);
    optargs_s.uuid = PyBytes_AS_STRING (bytes);
#endif
  }
#endif

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_mkswap_opts_argv (g, device, optargs);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_MKSWAP_L
static PyObject *
guestfs_int_py_mkswap_L (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  const char *label;
  const char *device;

  if (!PyArg_ParseTuple (args, (char *) "Oss:guestfs_mkswap_L",
                         &py_g, &label, &device))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_mkswap_L (g, label, device);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_MKSWAP_U
static PyObject *
guestfs_int_py_mkswap_U (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  const char *uuid;
  const char *device;

  if (!PyArg_ParseTuple (args, (char *) "Oss:guestfs_mkswap_U",
                         &py_g, &uuid, &device))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_mkswap_U (g, uuid, device);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_MKSWAP_FILE
static PyObject *
guestfs_int_py_mkswap_file (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  const char *path;

  if (!PyArg_ParseTuple (args, (char *) "Os:guestfs_mkswap_file",
                         &py_g, &path))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_mkswap_file (g, path);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_MKTEMP
static PyObject *
guestfs_int_py_mktemp (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  struct guestfs_mktemp_argv optargs_s;
  struct guestfs_mktemp_argv *optargs = &optargs_s;
  char *r;
  const char *tmpl;
  PyObject *py_suffix;

  optargs_s.bitmask = 0;

  if (!PyArg_ParseTuple (args, (char *) "OsO:guestfs_mktemp",
                         &py_g, &tmpl, &py_suffix))
    goto out;
  g = get_handle (py_g);

#ifdef GUESTFS_MKTEMP_SUFFIX_BITMASK
  if (py_suffix != Py_None) {
    optargs_s.bitmask |= GUESTFS_MKTEMP_SUFFIX_BITMASK;
#ifdef HAVE_PYSTRING_ASSTRING
    optargs_s.suffix = PyString_AsString (py_suffix);
#else
    PyObject *bytes;
    bytes = PyUnicode_AsUTF8String (py_suffix);
    optargs_s.suffix = PyBytes_AS_STRING (bytes);
#endif
  }
#endif

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_mktemp_argv (g, tmpl, optargs);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == NULL) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

#ifdef HAVE_PYSTRING_ASSTRING
  py_r = PyString_FromString (r);
#else
  py_r = PyUnicode_FromString (r);
#endif
  free (r);
  if (py_r == NULL) goto out;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_MODPROBE
static PyObject *
guestfs_int_py_modprobe (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  const char *modulename;

  if (!PyArg_ParseTuple (args, (char *) "Os:guestfs_modprobe",
                         &py_g, &modulename))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_modprobe (g, modulename);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_MOUNT
static PyObject *
guestfs_int_py_mount (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  const char *mountable;
  const char *mountpoint;

  if (!PyArg_ParseTuple (args, (char *) "Oss:guestfs_mount",
                         &py_g, &mountable, &mountpoint))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_mount (g, mountable, mountpoint);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_MOUNT_9P
static PyObject *
guestfs_int_py_mount_9p (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  struct guestfs_mount_9p_argv optargs_s;
  struct guestfs_mount_9p_argv *optargs = &optargs_s;
  int r;
  const char *mounttag;
  const char *mountpoint;
  PyObject *py_options;

  optargs_s.bitmask = 0;

  if (!PyArg_ParseTuple (args, (char *) "OssO:guestfs_mount_9p",
                         &py_g, &mounttag, &mountpoint, &py_options))
    goto out;
  g = get_handle (py_g);

#ifdef GUESTFS_MOUNT_9P_OPTIONS_BITMASK
  if (py_options != Py_None) {
    optargs_s.bitmask |= GUESTFS_MOUNT_9P_OPTIONS_BITMASK;
#ifdef HAVE_PYSTRING_ASSTRING
    optargs_s.options = PyString_AsString (py_options);
#else
    PyObject *bytes;
    bytes = PyUnicode_AsUTF8String (py_options);
    optargs_s.options = PyBytes_AS_STRING (bytes);
#endif
  }
#endif

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_mount_9p_argv (g, mounttag, mountpoint, optargs);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_MOUNT_LOCAL
static PyObject *
guestfs_int_py_mount_local (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  struct guestfs_mount_local_argv optargs_s;
  struct guestfs_mount_local_argv *optargs = &optargs_s;
  int r;
  const char *localmountpoint;
  PyObject *py_readonly;
  PyObject *py_options;
  PyObject *py_cachetimeout;
  PyObject *py_debugcalls;

  optargs_s.bitmask = 0;

  if (!PyArg_ParseTuple (args, (char *) "OsOOOO:guestfs_mount_local",
                         &py_g, &localmountpoint, &py_readonly, &py_options, &py_cachetimeout, &py_debugcalls))
    goto out;
  g = get_handle (py_g);

#ifdef GUESTFS_MOUNT_LOCAL_READONLY_BITMASK
  if (py_readonly != Py_None) {
    optargs_s.bitmask |= GUESTFS_MOUNT_LOCAL_READONLY_BITMASK;
    optargs_s.readonly = PyLong_AsLong (py_readonly);
    if (PyErr_Occurred ()) goto out;
  }
#endif
#ifdef GUESTFS_MOUNT_LOCAL_OPTIONS_BITMASK
  if (py_options != Py_None) {
    optargs_s.bitmask |= GUESTFS_MOUNT_LOCAL_OPTIONS_BITMASK;
#ifdef HAVE_PYSTRING_ASSTRING
    optargs_s.options = PyString_AsString (py_options);
#else
    PyObject *bytes;
    bytes = PyUnicode_AsUTF8String (py_options);
    optargs_s.options = PyBytes_AS_STRING (bytes);
#endif
  }
#endif
#ifdef GUESTFS_MOUNT_LOCAL_CACHETIMEOUT_BITMASK
  if (py_cachetimeout != Py_None) {
    optargs_s.bitmask |= GUESTFS_MOUNT_LOCAL_CACHETIMEOUT_BITMASK;
    optargs_s.cachetimeout = PyLong_AsLong (py_cachetimeout);
    if (PyErr_Occurred ()) goto out;
  }
#endif
#ifdef GUESTFS_MOUNT_LOCAL_DEBUGCALLS_BITMASK
  if (py_debugcalls != Py_None) {
    optargs_s.bitmask |= GUESTFS_MOUNT_LOCAL_DEBUGCALLS_BITMASK;
    optargs_s.debugcalls = PyLong_AsLong (py_debugcalls);
    if (PyErr_Occurred ()) goto out;
  }
#endif

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_mount_local_argv (g, localmountpoint, optargs);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_MOUNT_LOCAL_RUN
static PyObject *
guestfs_int_py_mount_local_run (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;

  if (!PyArg_ParseTuple (args, (char *) "O:guestfs_mount_local_run",
                         &py_g))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_mount_local_run (g);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_MOUNT_LOOP
static PyObject *
guestfs_int_py_mount_loop (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  const char *file;
  const char *mountpoint;

  if (!PyArg_ParseTuple (args, (char *) "Oss:guestfs_mount_loop",
                         &py_g, &file, &mountpoint))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_mount_loop (g, file, mountpoint);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_MOUNT_OPTIONS
static PyObject *
guestfs_int_py_mount_options (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  const char *options;
  const char *mountable;
  const char *mountpoint;

  if (!PyArg_ParseTuple (args, (char *) "Osss:guestfs_mount_options",
                         &py_g, &options, &mountable, &mountpoint))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_mount_options (g, options, mountable, mountpoint);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_MOUNT_RO
static PyObject *
guestfs_int_py_mount_ro (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  const char *mountable;
  const char *mountpoint;

  if (!PyArg_ParseTuple (args, (char *) "Oss:guestfs_mount_ro",
                         &py_g, &mountable, &mountpoint))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_mount_ro (g, mountable, mountpoint);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_MOUNT_VFS
static PyObject *
guestfs_int_py_mount_vfs (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  const char *options;
  const char *vfstype;
  const char *mountable;
  const char *mountpoint;

  if (!PyArg_ParseTuple (args, (char *) "Ossss:guestfs_mount_vfs",
                         &py_g, &options, &vfstype, &mountable, &mountpoint))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_mount_vfs (g, options, vfstype, mountable, mountpoint);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_MOUNTPOINTS
static PyObject *
guestfs_int_py_mountpoints (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  char **r;

  if (!PyArg_ParseTuple (args, (char *) "O:guestfs_mountpoints",
                         &py_g))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_mountpoints (g);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == NULL) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  py_r = put_table (r);
  guestfs_int_free_string_list (r);

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_MOUNTS
static PyObject *
guestfs_int_py_mounts (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  char **r;

  if (!PyArg_ParseTuple (args, (char *) "O:guestfs_mounts",
                         &py_g))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_mounts (g);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == NULL) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  py_r = put_string_list (r);
  guestfs_int_free_string_list (r);

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_MV
static PyObject *
guestfs_int_py_mv (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  const char *src;
  const char *dest;

  if (!PyArg_ParseTuple (args, (char *) "Oss:guestfs_mv",
                         &py_g, &src, &dest))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_mv (g, src, dest);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_NR_DEVICES
static PyObject *
guestfs_int_py_nr_devices (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;

  if (!PyArg_ParseTuple (args, (char *) "O:guestfs_nr_devices",
                         &py_g))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_nr_devices (g);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  py_r = PyLong_FromLong ((long) r);

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_NTFS_3G_PROBE
static PyObject *
guestfs_int_py_ntfs_3g_probe (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  int rw;
  const char *device;

  if (!PyArg_ParseTuple (args, (char *) "Ois:guestfs_ntfs_3g_probe",
                         &py_g, &rw, &device))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_ntfs_3g_probe (g, rw, device);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  py_r = PyLong_FromLong ((long) r);

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_NTFSCLONE_IN
static PyObject *
guestfs_int_py_ntfsclone_in (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  const char *backupfile;
  const char *device;

  if (!PyArg_ParseTuple (args, (char *) "Oss:guestfs_ntfsclone_in",
                         &py_g, &backupfile, &device))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_ntfsclone_in (g, backupfile, device);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_NTFSCLONE_OUT
static PyObject *
guestfs_int_py_ntfsclone_out (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  struct guestfs_ntfsclone_out_argv optargs_s;
  struct guestfs_ntfsclone_out_argv *optargs = &optargs_s;
  int r;
  const char *device;
  const char *backupfile;
  PyObject *py_metadataonly;
  PyObject *py_rescue;
  PyObject *py_ignorefscheck;
  PyObject *py_preservetimestamps;
  PyObject *py_force;

  optargs_s.bitmask = 0;

  if (!PyArg_ParseTuple (args, (char *) "OssOOOOO:guestfs_ntfsclone_out",
                         &py_g, &device, &backupfile, &py_metadataonly, &py_rescue, &py_ignorefscheck, &py_preservetimestamps, &py_force))
    goto out;
  g = get_handle (py_g);

#ifdef GUESTFS_NTFSCLONE_OUT_METADATAONLY_BITMASK
  if (py_metadataonly != Py_None) {
    optargs_s.bitmask |= GUESTFS_NTFSCLONE_OUT_METADATAONLY_BITMASK;
    optargs_s.metadataonly = PyLong_AsLong (py_metadataonly);
    if (PyErr_Occurred ()) goto out;
  }
#endif
#ifdef GUESTFS_NTFSCLONE_OUT_RESCUE_BITMASK
  if (py_rescue != Py_None) {
    optargs_s.bitmask |= GUESTFS_NTFSCLONE_OUT_RESCUE_BITMASK;
    optargs_s.rescue = PyLong_AsLong (py_rescue);
    if (PyErr_Occurred ()) goto out;
  }
#endif
#ifdef GUESTFS_NTFSCLONE_OUT_IGNOREFSCHECK_BITMASK
  if (py_ignorefscheck != Py_None) {
    optargs_s.bitmask |= GUESTFS_NTFSCLONE_OUT_IGNOREFSCHECK_BITMASK;
    optargs_s.ignorefscheck = PyLong_AsLong (py_ignorefscheck);
    if (PyErr_Occurred ()) goto out;
  }
#endif
#ifdef GUESTFS_NTFSCLONE_OUT_PRESERVETIMESTAMPS_BITMASK
  if (py_preservetimestamps != Py_None) {
    optargs_s.bitmask |= GUESTFS_NTFSCLONE_OUT_PRESERVETIMESTAMPS_BITMASK;
    optargs_s.preservetimestamps = PyLong_AsLong (py_preservetimestamps);
    if (PyErr_Occurred ()) goto out;
  }
#endif
#ifdef GUESTFS_NTFSCLONE_OUT_FORCE_BITMASK
  if (py_force != Py_None) {
    optargs_s.bitmask |= GUESTFS_NTFSCLONE_OUT_FORCE_BITMASK;
    optargs_s.force = PyLong_AsLong (py_force);
    if (PyErr_Occurred ()) goto out;
  }
#endif

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_ntfsclone_out_argv (g, device, backupfile, optargs);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_NTFSFIX
static PyObject *
guestfs_int_py_ntfsfix (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  struct guestfs_ntfsfix_argv optargs_s;
  struct guestfs_ntfsfix_argv *optargs = &optargs_s;
  int r;
  const char *device;
  PyObject *py_clearbadsectors;

  optargs_s.bitmask = 0;

  if (!PyArg_ParseTuple (args, (char *) "OsO:guestfs_ntfsfix",
                         &py_g, &device, &py_clearbadsectors))
    goto out;
  g = get_handle (py_g);

#ifdef GUESTFS_NTFSFIX_CLEARBADSECTORS_BITMASK
  if (py_clearbadsectors != Py_None) {
    optargs_s.bitmask |= GUESTFS_NTFSFIX_CLEARBADSECTORS_BITMASK;
    optargs_s.clearbadsectors = PyLong_AsLong (py_clearbadsectors);
    if (PyErr_Occurred ()) goto out;
  }
#endif

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_ntfsfix_argv (g, device, optargs);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_NTFSRESIZE_OPTS
static PyObject *
guestfs_int_py_ntfsresize (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  struct guestfs_ntfsresize_opts_argv optargs_s;
  struct guestfs_ntfsresize_opts_argv *optargs = &optargs_s;
  int r;
  const char *device;
  PyObject *py_size;
  PyObject *py_force;

  optargs_s.bitmask = 0;

  if (!PyArg_ParseTuple (args, (char *) "OsOO:guestfs_ntfsresize",
                         &py_g, &device, &py_size, &py_force))
    goto out;
  g = get_handle (py_g);

#ifdef GUESTFS_NTFSRESIZE_OPTS_SIZE_BITMASK
  if (py_size != Py_None) {
    optargs_s.bitmask |= GUESTFS_NTFSRESIZE_OPTS_SIZE_BITMASK;
    optargs_s.size = PyLong_AsLongLong (py_size);
    if (PyErr_Occurred ()) goto out;
  }
#endif
#ifdef GUESTFS_NTFSRESIZE_OPTS_FORCE_BITMASK
  if (py_force != Py_None) {
    optargs_s.bitmask |= GUESTFS_NTFSRESIZE_OPTS_FORCE_BITMASK;
    optargs_s.force = PyLong_AsLong (py_force);
    if (PyErr_Occurred ()) goto out;
  }
#endif

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_ntfsresize_opts_argv (g, device, optargs);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_NTFSRESIZE_SIZE
static PyObject *
guestfs_int_py_ntfsresize_size (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  const char *device;
  long long size;

  if (!PyArg_ParseTuple (args, (char *) "OsL:guestfs_ntfsresize_size",
                         &py_g, &device, &size))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_ntfsresize_size (g, device, size);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_PARSE_ENVIRONMENT
static PyObject *
guestfs_int_py_parse_environment (PyObject *self, PyObject *args)
{
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;

  if (!PyArg_ParseTuple (args, (char *) "O:guestfs_parse_environment",
                         &py_g))
    goto out;
  g = get_handle (py_g);

  r = guestfs_parse_environment (g);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_PARSE_ENVIRONMENT_LIST
static PyObject *
guestfs_int_py_parse_environment_list (PyObject *self, PyObject *args)
{
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  PyObject *py_environment;
  char **environment = NULL;

  if (!PyArg_ParseTuple (args, (char *) "OO:guestfs_parse_environment_list",
                         &py_g, &py_environment))
    goto out;
  g = get_handle (py_g);
  environment = get_string_list (py_environment);
  if (!environment) goto out;

  r = guestfs_parse_environment_list (g, environment);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  free (environment);
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_PART_ADD
static PyObject *
guestfs_int_py_part_add (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  const char *device;
  const char *prlogex;
  long long startsect;
  long long endsect;

  if (!PyArg_ParseTuple (args, (char *) "OssLL:guestfs_part_add",
                         &py_g, &device, &prlogex, &startsect, &endsect))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_part_add (g, device, prlogex, startsect, endsect);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_PART_DEL
static PyObject *
guestfs_int_py_part_del (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  const char *device;
  int partnum;

  if (!PyArg_ParseTuple (args, (char *) "Osi:guestfs_part_del",
                         &py_g, &device, &partnum))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_part_del (g, device, partnum);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_PART_DISK
static PyObject *
guestfs_int_py_part_disk (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  const char *device;
  const char *parttype;

  if (!PyArg_ParseTuple (args, (char *) "Oss:guestfs_part_disk",
                         &py_g, &device, &parttype))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_part_disk (g, device, parttype);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_PART_GET_BOOTABLE
static PyObject *
guestfs_int_py_part_get_bootable (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  const char *device;
  int partnum;

  if (!PyArg_ParseTuple (args, (char *) "Osi:guestfs_part_get_bootable",
                         &py_g, &device, &partnum))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_part_get_bootable (g, device, partnum);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  py_r = PyLong_FromLong ((long) r);

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_PART_GET_GPT_GUID
static PyObject *
guestfs_int_py_part_get_gpt_guid (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  char *r;
  const char *device;
  int partnum;

  if (!PyArg_ParseTuple (args, (char *) "Osi:guestfs_part_get_gpt_guid",
                         &py_g, &device, &partnum))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_part_get_gpt_guid (g, device, partnum);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == NULL) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

#ifdef HAVE_PYSTRING_ASSTRING
  py_r = PyString_FromString (r);
#else
  py_r = PyUnicode_FromString (r);
#endif
  free (r);
  if (py_r == NULL) goto out;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_PART_GET_GPT_TYPE
static PyObject *
guestfs_int_py_part_get_gpt_type (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  char *r;
  const char *device;
  int partnum;

  if (!PyArg_ParseTuple (args, (char *) "Osi:guestfs_part_get_gpt_type",
                         &py_g, &device, &partnum))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_part_get_gpt_type (g, device, partnum);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == NULL) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

#ifdef HAVE_PYSTRING_ASSTRING
  py_r = PyString_FromString (r);
#else
  py_r = PyUnicode_FromString (r);
#endif
  free (r);
  if (py_r == NULL) goto out;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_PART_GET_MBR_ID
static PyObject *
guestfs_int_py_part_get_mbr_id (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  const char *device;
  int partnum;

  if (!PyArg_ParseTuple (args, (char *) "Osi:guestfs_part_get_mbr_id",
                         &py_g, &device, &partnum))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_part_get_mbr_id (g, device, partnum);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  py_r = PyLong_FromLong ((long) r);

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_PART_GET_MBR_PART_TYPE
static PyObject *
guestfs_int_py_part_get_mbr_part_type (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  char *r;
  const char *device;
  int partnum;

  if (!PyArg_ParseTuple (args, (char *) "Osi:guestfs_part_get_mbr_part_type",
                         &py_g, &device, &partnum))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_part_get_mbr_part_type (g, device, partnum);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == NULL) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

#ifdef HAVE_PYSTRING_ASSTRING
  py_r = PyString_FromString (r);
#else
  py_r = PyUnicode_FromString (r);
#endif
  free (r);
  if (py_r == NULL) goto out;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_PART_GET_NAME
static PyObject *
guestfs_int_py_part_get_name (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  char *r;
  const char *device;
  int partnum;

  if (!PyArg_ParseTuple (args, (char *) "Osi:guestfs_part_get_name",
                         &py_g, &device, &partnum))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_part_get_name (g, device, partnum);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == NULL) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

#ifdef HAVE_PYSTRING_ASSTRING
  py_r = PyString_FromString (r);
#else
  py_r = PyUnicode_FromString (r);
#endif
  free (r);
  if (py_r == NULL) goto out;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_PART_GET_PARTTYPE
static PyObject *
guestfs_int_py_part_get_parttype (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  char *r;
  const char *device;

  if (!PyArg_ParseTuple (args, (char *) "Os:guestfs_part_get_parttype",
                         &py_g, &device))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_part_get_parttype (g, device);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == NULL) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

#ifdef HAVE_PYSTRING_ASSTRING
  py_r = PyString_FromString (r);
#else
  py_r = PyUnicode_FromString (r);
#endif
  free (r);
  if (py_r == NULL) goto out;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_PART_INIT
static PyObject *
guestfs_int_py_part_init (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  const char *device;
  const char *parttype;

  if (!PyArg_ParseTuple (args, (char *) "Oss:guestfs_part_init",
                         &py_g, &device, &parttype))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_part_init (g, device, parttype);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_PART_LIST
static PyObject *
guestfs_int_py_part_list (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  struct guestfs_partition_list *r;
  const char *device;

  if (!PyArg_ParseTuple (args, (char *) "Os:guestfs_part_list",
                         &py_g, &device))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_part_list (g, device);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == NULL) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  py_r = put_partition_list (r);
  guestfs_free_partition_list (r);

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_PART_SET_BOOTABLE
static PyObject *
guestfs_int_py_part_set_bootable (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  const char *device;
  int partnum;
  int bootable;

  if (!PyArg_ParseTuple (args, (char *) "Osii:guestfs_part_set_bootable",
                         &py_g, &device, &partnum, &bootable))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_part_set_bootable (g, device, partnum, bootable);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_PART_SET_GPT_GUID
static PyObject *
guestfs_int_py_part_set_gpt_guid (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  const char *device;
  int partnum;
  const char *guid;

  if (!PyArg_ParseTuple (args, (char *) "Osis:guestfs_part_set_gpt_guid",
                         &py_g, &device, &partnum, &guid))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_part_set_gpt_guid (g, device, partnum, guid);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_PART_SET_GPT_TYPE
static PyObject *
guestfs_int_py_part_set_gpt_type (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  const char *device;
  int partnum;
  const char *guid;

  if (!PyArg_ParseTuple (args, (char *) "Osis:guestfs_part_set_gpt_type",
                         &py_g, &device, &partnum, &guid))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_part_set_gpt_type (g, device, partnum, guid);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_PART_SET_MBR_ID
static PyObject *
guestfs_int_py_part_set_mbr_id (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  const char *device;
  int partnum;
  int idbyte;

  if (!PyArg_ParseTuple (args, (char *) "Osii:guestfs_part_set_mbr_id",
                         &py_g, &device, &partnum, &idbyte))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_part_set_mbr_id (g, device, partnum, idbyte);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_PART_SET_NAME
static PyObject *
guestfs_int_py_part_set_name (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  const char *device;
  int partnum;
  const char *name;

  if (!PyArg_ParseTuple (args, (char *) "Osis:guestfs_part_set_name",
                         &py_g, &device, &partnum, &name))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_part_set_name (g, device, partnum, name);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_PART_TO_DEV
static PyObject *
guestfs_int_py_part_to_dev (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  char *r;
  const char *partition;

  if (!PyArg_ParseTuple (args, (char *) "Os:guestfs_part_to_dev",
                         &py_g, &partition))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_part_to_dev (g, partition);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == NULL) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

#ifdef HAVE_PYSTRING_ASSTRING
  py_r = PyString_FromString (r);
#else
  py_r = PyUnicode_FromString (r);
#endif
  free (r);
  if (py_r == NULL) goto out;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_PART_TO_PARTNUM
static PyObject *
guestfs_int_py_part_to_partnum (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  const char *partition;

  if (!PyArg_ParseTuple (args, (char *) "Os:guestfs_part_to_partnum",
                         &py_g, &partition))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_part_to_partnum (g, partition);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  py_r = PyLong_FromLong ((long) r);

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_PING_DAEMON
static PyObject *
guestfs_int_py_ping_daemon (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;

  if (!PyArg_ParseTuple (args, (char *) "O:guestfs_ping_daemon",
                         &py_g))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_ping_daemon (g);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_PREAD
static PyObject *
guestfs_int_py_pread (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  char *r;
  size_t size;
  const char *path;
  int count;
  long long offset;

  if (!PyArg_ParseTuple (args, (char *) "OsiL:guestfs_pread",
                         &py_g, &path, &count, &offset))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_pread (g, path, count, offset, &size);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == NULL) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

#ifdef HAVE_PYSTRING_ASSTRING
  py_r = PyString_FromStringAndSize (r, size);
#else
  py_r = PyBytes_FromStringAndSize (r, size);
#endif
  free (r);
  if (py_r == NULL) goto out;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_PREAD_DEVICE
static PyObject *
guestfs_int_py_pread_device (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  char *r;
  size_t size;
  const char *device;
  int count;
  long long offset;

  if (!PyArg_ParseTuple (args, (char *) "OsiL:guestfs_pread_device",
                         &py_g, &device, &count, &offset))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_pread_device (g, device, count, offset, &size);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == NULL) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

#ifdef HAVE_PYSTRING_ASSTRING
  py_r = PyString_FromStringAndSize (r, size);
#else
  py_r = PyBytes_FromStringAndSize (r, size);
#endif
  free (r);
  if (py_r == NULL) goto out;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_PVCHANGE_UUID
static PyObject *
guestfs_int_py_pvchange_uuid (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  const char *device;

  if (!PyArg_ParseTuple (args, (char *) "Os:guestfs_pvchange_uuid",
                         &py_g, &device))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_pvchange_uuid (g, device);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_PVCHANGE_UUID_ALL
static PyObject *
guestfs_int_py_pvchange_uuid_all (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;

  if (!PyArg_ParseTuple (args, (char *) "O:guestfs_pvchange_uuid_all",
                         &py_g))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_pvchange_uuid_all (g);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_PVCREATE
static PyObject *
guestfs_int_py_pvcreate (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  const char *device;

  if (!PyArg_ParseTuple (args, (char *) "Os:guestfs_pvcreate",
                         &py_g, &device))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_pvcreate (g, device);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_PVREMOVE
static PyObject *
guestfs_int_py_pvremove (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  const char *device;

  if (!PyArg_ParseTuple (args, (char *) "Os:guestfs_pvremove",
                         &py_g, &device))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_pvremove (g, device);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_PVRESIZE
static PyObject *
guestfs_int_py_pvresize (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  const char *device;

  if (!PyArg_ParseTuple (args, (char *) "Os:guestfs_pvresize",
                         &py_g, &device))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_pvresize (g, device);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_PVRESIZE_SIZE
static PyObject *
guestfs_int_py_pvresize_size (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  const char *device;
  long long size;

  if (!PyArg_ParseTuple (args, (char *) "OsL:guestfs_pvresize_size",
                         &py_g, &device, &size))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_pvresize_size (g, device, size);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_PVS
static PyObject *
guestfs_int_py_pvs (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  char **r;

  if (!PyArg_ParseTuple (args, (char *) "O:guestfs_pvs",
                         &py_g))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_pvs (g);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == NULL) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  py_r = put_string_list (r);
  guestfs_int_free_string_list (r);

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_PVS_FULL
static PyObject *
guestfs_int_py_pvs_full (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  struct guestfs_lvm_pv_list *r;

  if (!PyArg_ParseTuple (args, (char *) "O:guestfs_pvs_full",
                         &py_g))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_pvs_full (g);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == NULL) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  py_r = put_lvm_pv_list (r);
  guestfs_free_lvm_pv_list (r);

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_PVUUID
static PyObject *
guestfs_int_py_pvuuid (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  char *r;
  const char *device;

  if (!PyArg_ParseTuple (args, (char *) "Os:guestfs_pvuuid",
                         &py_g, &device))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_pvuuid (g, device);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == NULL) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

#ifdef HAVE_PYSTRING_ASSTRING
  py_r = PyString_FromString (r);
#else
  py_r = PyUnicode_FromString (r);
#endif
  free (r);
  if (py_r == NULL) goto out;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_PWRITE
static PyObject *
guestfs_int_py_pwrite (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  const char *path;
  const char *content;
  Py_ssize_t content_size;
  long long offset;

  if (!PyArg_ParseTuple (args, (char *) "Oss#L:guestfs_pwrite",
                         &py_g, &path, &content, &content_size, &offset))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_pwrite (g, path, content, content_size, offset);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  py_r = PyLong_FromLong ((long) r);

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_PWRITE_DEVICE
static PyObject *
guestfs_int_py_pwrite_device (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  const char *device;
  const char *content;
  Py_ssize_t content_size;
  long long offset;

  if (!PyArg_ParseTuple (args, (char *) "Oss#L:guestfs_pwrite_device",
                         &py_g, &device, &content, &content_size, &offset))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_pwrite_device (g, device, content, content_size, offset);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  py_r = PyLong_FromLong ((long) r);

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_READ_FILE
static PyObject *
guestfs_int_py_read_file (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  char *r;
  size_t size;
  const char *path;

  if (!PyArg_ParseTuple (args, (char *) "Os:guestfs_read_file",
                         &py_g, &path))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_read_file (g, path, &size);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == NULL) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

#ifdef HAVE_PYSTRING_ASSTRING
  py_r = PyString_FromStringAndSize (r, size);
#else
  py_r = PyBytes_FromStringAndSize (r, size);
#endif
  free (r);
  if (py_r == NULL) goto out;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_READ_LINES
static PyObject *
guestfs_int_py_read_lines (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  char **r;
  const char *path;

  if (!PyArg_ParseTuple (args, (char *) "Os:guestfs_read_lines",
                         &py_g, &path))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_read_lines (g, path);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == NULL) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  py_r = put_string_list (r);
  guestfs_int_free_string_list (r);

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_READDIR
static PyObject *
guestfs_int_py_readdir (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  struct guestfs_dirent_list *r;
  const char *dir;

  if (!PyArg_ParseTuple (args, (char *) "Os:guestfs_readdir",
                         &py_g, &dir))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_readdir (g, dir);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == NULL) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  py_r = put_dirent_list (r);
  guestfs_free_dirent_list (r);

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_READLINK
static PyObject *
guestfs_int_py_readlink (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  char *r;
  const char *path;

  if (!PyArg_ParseTuple (args, (char *) "Os:guestfs_readlink",
                         &py_g, &path))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_readlink (g, path);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == NULL) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

#ifdef HAVE_PYSTRING_ASSTRING
  py_r = PyString_FromString (r);
#else
  py_r = PyUnicode_FromString (r);
#endif
  free (r);
  if (py_r == NULL) goto out;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_READLINKLIST
static PyObject *
guestfs_int_py_readlinklist (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  char **r;
  const char *path;
  PyObject *py_names;
  char **names = NULL;

  if (!PyArg_ParseTuple (args, (char *) "OsO:guestfs_readlinklist",
                         &py_g, &path, &py_names))
    goto out;
  g = get_handle (py_g);
  names = get_string_list (py_names);
  if (!names) goto out;

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_readlinklist (g, path, names);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == NULL) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  py_r = put_string_list (r);
  guestfs_int_free_string_list (r);

  PyErr_Clear ();
 out:
  free (names);
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_REALPATH
static PyObject *
guestfs_int_py_realpath (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  char *r;
  const char *path;

  if (!PyArg_ParseTuple (args, (char *) "Os:guestfs_realpath",
                         &py_g, &path))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_realpath (g, path);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == NULL) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

#ifdef HAVE_PYSTRING_ASSTRING
  py_r = PyString_FromString (r);
#else
  py_r = PyUnicode_FromString (r);
#endif
  free (r);
  if (py_r == NULL) goto out;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_REMOUNT
static PyObject *
guestfs_int_py_remount (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  struct guestfs_remount_argv optargs_s;
  struct guestfs_remount_argv *optargs = &optargs_s;
  int r;
  const char *mountpoint;
  PyObject *py_rw;

  optargs_s.bitmask = 0;

  if (!PyArg_ParseTuple (args, (char *) "OsO:guestfs_remount",
                         &py_g, &mountpoint, &py_rw))
    goto out;
  g = get_handle (py_g);

#ifdef GUESTFS_REMOUNT_RW_BITMASK
  if (py_rw != Py_None) {
    optargs_s.bitmask |= GUESTFS_REMOUNT_RW_BITMASK;
    optargs_s.rw = PyLong_AsLong (py_rw);
    if (PyErr_Occurred ()) goto out;
  }
#endif

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_remount_argv (g, mountpoint, optargs);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_REMOVE_DRIVE
static PyObject *
guestfs_int_py_remove_drive (PyObject *self, PyObject *args)
{
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  const char *label;

  if (!PyArg_ParseTuple (args, (char *) "Os:guestfs_remove_drive",
                         &py_g, &label))
    goto out;
  g = get_handle (py_g);

  r = guestfs_remove_drive (g, label);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_REMOVEXATTR
static PyObject *
guestfs_int_py_removexattr (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  const char *xattr;
  const char *path;

  if (!PyArg_ParseTuple (args, (char *) "Oss:guestfs_removexattr",
                         &py_g, &xattr, &path))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_removexattr (g, xattr, path);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_RENAME
static PyObject *
guestfs_int_py_rename (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  const char *oldpath;
  const char *newpath;

  if (!PyArg_ParseTuple (args, (char *) "Oss:guestfs_rename",
                         &py_g, &oldpath, &newpath))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_rename (g, oldpath, newpath);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_RESIZE2FS
static PyObject *
guestfs_int_py_resize2fs (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  const char *device;

  if (!PyArg_ParseTuple (args, (char *) "Os:guestfs_resize2fs",
                         &py_g, &device))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_resize2fs (g, device);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_RESIZE2FS_M
static PyObject *
guestfs_int_py_resize2fs_M (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  const char *device;

  if (!PyArg_ParseTuple (args, (char *) "Os:guestfs_resize2fs_M",
                         &py_g, &device))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_resize2fs_M (g, device);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_RESIZE2FS_SIZE
static PyObject *
guestfs_int_py_resize2fs_size (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  const char *device;
  long long size;

  if (!PyArg_ParseTuple (args, (char *) "OsL:guestfs_resize2fs_size",
                         &py_g, &device, &size))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_resize2fs_size (g, device, size);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_RM
static PyObject *
guestfs_int_py_rm (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  const char *path;

  if (!PyArg_ParseTuple (args, (char *) "Os:guestfs_rm",
                         &py_g, &path))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_rm (g, path);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_RM_F
static PyObject *
guestfs_int_py_rm_f (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  const char *path;

  if (!PyArg_ParseTuple (args, (char *) "Os:guestfs_rm_f",
                         &py_g, &path))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_rm_f (g, path);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_RM_RF
static PyObject *
guestfs_int_py_rm_rf (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  const char *path;

  if (!PyArg_ParseTuple (args, (char *) "Os:guestfs_rm_rf",
                         &py_g, &path))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_rm_rf (g, path);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_RMDIR
static PyObject *
guestfs_int_py_rmdir (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  const char *path;

  if (!PyArg_ParseTuple (args, (char *) "Os:guestfs_rmdir",
                         &py_g, &path))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_rmdir (g, path);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_RMMOUNTPOINT
static PyObject *
guestfs_int_py_rmmountpoint (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  const char *exemptpath;

  if (!PyArg_ParseTuple (args, (char *) "Os:guestfs_rmmountpoint",
                         &py_g, &exemptpath))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_rmmountpoint (g, exemptpath);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_RSYNC
static PyObject *
guestfs_int_py_rsync (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  struct guestfs_rsync_argv optargs_s;
  struct guestfs_rsync_argv *optargs = &optargs_s;
  int r;
  const char *src;
  const char *dest;
  PyObject *py_archive;
  PyObject *py_deletedest;

  optargs_s.bitmask = 0;

  if (!PyArg_ParseTuple (args, (char *) "OssOO:guestfs_rsync",
                         &py_g, &src, &dest, &py_archive, &py_deletedest))
    goto out;
  g = get_handle (py_g);

#ifdef GUESTFS_RSYNC_ARCHIVE_BITMASK
  if (py_archive != Py_None) {
    optargs_s.bitmask |= GUESTFS_RSYNC_ARCHIVE_BITMASK;
    optargs_s.archive = PyLong_AsLong (py_archive);
    if (PyErr_Occurred ()) goto out;
  }
#endif
#ifdef GUESTFS_RSYNC_DELETEDEST_BITMASK
  if (py_deletedest != Py_None) {
    optargs_s.bitmask |= GUESTFS_RSYNC_DELETEDEST_BITMASK;
    optargs_s.deletedest = PyLong_AsLong (py_deletedest);
    if (PyErr_Occurred ()) goto out;
  }
#endif

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_rsync_argv (g, src, dest, optargs);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_RSYNC_IN
static PyObject *
guestfs_int_py_rsync_in (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  struct guestfs_rsync_in_argv optargs_s;
  struct guestfs_rsync_in_argv *optargs = &optargs_s;
  int r;
  const char *remote;
  const char *dest;
  PyObject *py_archive;
  PyObject *py_deletedest;

  optargs_s.bitmask = 0;

  if (!PyArg_ParseTuple (args, (char *) "OssOO:guestfs_rsync_in",
                         &py_g, &remote, &dest, &py_archive, &py_deletedest))
    goto out;
  g = get_handle (py_g);

#ifdef GUESTFS_RSYNC_IN_ARCHIVE_BITMASK
  if (py_archive != Py_None) {
    optargs_s.bitmask |= GUESTFS_RSYNC_IN_ARCHIVE_BITMASK;
    optargs_s.archive = PyLong_AsLong (py_archive);
    if (PyErr_Occurred ()) goto out;
  }
#endif
#ifdef GUESTFS_RSYNC_IN_DELETEDEST_BITMASK
  if (py_deletedest != Py_None) {
    optargs_s.bitmask |= GUESTFS_RSYNC_IN_DELETEDEST_BITMASK;
    optargs_s.deletedest = PyLong_AsLong (py_deletedest);
    if (PyErr_Occurred ()) goto out;
  }
#endif

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_rsync_in_argv (g, remote, dest, optargs);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_RSYNC_OUT
static PyObject *
guestfs_int_py_rsync_out (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  struct guestfs_rsync_out_argv optargs_s;
  struct guestfs_rsync_out_argv *optargs = &optargs_s;
  int r;
  const char *src;
  const char *remote;
  PyObject *py_archive;
  PyObject *py_deletedest;

  optargs_s.bitmask = 0;

  if (!PyArg_ParseTuple (args, (char *) "OssOO:guestfs_rsync_out",
                         &py_g, &src, &remote, &py_archive, &py_deletedest))
    goto out;
  g = get_handle (py_g);

#ifdef GUESTFS_RSYNC_OUT_ARCHIVE_BITMASK
  if (py_archive != Py_None) {
    optargs_s.bitmask |= GUESTFS_RSYNC_OUT_ARCHIVE_BITMASK;
    optargs_s.archive = PyLong_AsLong (py_archive);
    if (PyErr_Occurred ()) goto out;
  }
#endif
#ifdef GUESTFS_RSYNC_OUT_DELETEDEST_BITMASK
  if (py_deletedest != Py_None) {
    optargs_s.bitmask |= GUESTFS_RSYNC_OUT_DELETEDEST_BITMASK;
    optargs_s.deletedest = PyLong_AsLong (py_deletedest);
    if (PyErr_Occurred ()) goto out;
  }
#endif

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_rsync_out_argv (g, src, remote, optargs);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_SCRUB_DEVICE
static PyObject *
guestfs_int_py_scrub_device (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  const char *device;

  if (!PyArg_ParseTuple (args, (char *) "Os:guestfs_scrub_device",
                         &py_g, &device))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_scrub_device (g, device);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_SCRUB_FILE
static PyObject *
guestfs_int_py_scrub_file (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  const char *file;

  if (!PyArg_ParseTuple (args, (char *) "Os:guestfs_scrub_file",
                         &py_g, &file))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_scrub_file (g, file);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_SCRUB_FREESPACE
static PyObject *
guestfs_int_py_scrub_freespace (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  const char *dir;

  if (!PyArg_ParseTuple (args, (char *) "Os:guestfs_scrub_freespace",
                         &py_g, &dir))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_scrub_freespace (g, dir);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_SET_APPEND
static PyObject *
guestfs_int_py_set_append (PyObject *self, PyObject *args)
{
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  const char *append;

  if (!PyArg_ParseTuple (args, (char *) "Oz:guestfs_set_append",
                         &py_g, &append))
    goto out;
  g = get_handle (py_g);

  r = guestfs_set_append (g, append);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_SET_ATTACH_METHOD
static PyObject *
guestfs_int_py_set_attach_method (PyObject *self, PyObject *args)
{
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  const char *backend;

  if (!PyArg_ParseTuple (args, (char *) "Os:guestfs_set_attach_method",
                         &py_g, &backend))
    goto out;
  g = get_handle (py_g);

  r = guestfs_set_attach_method (g, backend);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_SET_AUTOSYNC
static PyObject *
guestfs_int_py_set_autosync (PyObject *self, PyObject *args)
{
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  int autosync;

  if (!PyArg_ParseTuple (args, (char *) "Oi:guestfs_set_autosync",
                         &py_g, &autosync))
    goto out;
  g = get_handle (py_g);

  r = guestfs_set_autosync (g, autosync);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_SET_BACKEND
static PyObject *
guestfs_int_py_set_backend (PyObject *self, PyObject *args)
{
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  const char *backend;

  if (!PyArg_ParseTuple (args, (char *) "Os:guestfs_set_backend",
                         &py_g, &backend))
    goto out;
  g = get_handle (py_g);

  r = guestfs_set_backend (g, backend);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_SET_BACKEND_SETTING
static PyObject *
guestfs_int_py_set_backend_setting (PyObject *self, PyObject *args)
{
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  const char *name;
  const char *val;

  if (!PyArg_ParseTuple (args, (char *) "Oss:guestfs_set_backend_setting",
                         &py_g, &name, &val))
    goto out;
  g = get_handle (py_g);

  r = guestfs_set_backend_setting (g, name, val);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_SET_BACKEND_SETTINGS
static PyObject *
guestfs_int_py_set_backend_settings (PyObject *self, PyObject *args)
{
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  PyObject *py_settings;
  char **settings = NULL;

  if (!PyArg_ParseTuple (args, (char *) "OO:guestfs_set_backend_settings",
                         &py_g, &py_settings))
    goto out;
  g = get_handle (py_g);
  settings = get_string_list (py_settings);
  if (!settings) goto out;

  r = guestfs_set_backend_settings (g, settings);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  free (settings);
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_SET_CACHEDIR
static PyObject *
guestfs_int_py_set_cachedir (PyObject *self, PyObject *args)
{
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  const char *cachedir;

  if (!PyArg_ParseTuple (args, (char *) "Oz:guestfs_set_cachedir",
                         &py_g, &cachedir))
    goto out;
  g = get_handle (py_g);

  r = guestfs_set_cachedir (g, cachedir);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_SET_DIRECT
static PyObject *
guestfs_int_py_set_direct (PyObject *self, PyObject *args)
{
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  int direct;

  if (!PyArg_ParseTuple (args, (char *) "Oi:guestfs_set_direct",
                         &py_g, &direct))
    goto out;
  g = get_handle (py_g);

  r = guestfs_set_direct (g, direct);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_SET_E2ATTRS
static PyObject *
guestfs_int_py_set_e2attrs (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  struct guestfs_set_e2attrs_argv optargs_s;
  struct guestfs_set_e2attrs_argv *optargs = &optargs_s;
  int r;
  const char *file;
  const char *attrs;
  PyObject *py_clear;

  optargs_s.bitmask = 0;

  if (!PyArg_ParseTuple (args, (char *) "OssO:guestfs_set_e2attrs",
                         &py_g, &file, &attrs, &py_clear))
    goto out;
  g = get_handle (py_g);

#ifdef GUESTFS_SET_E2ATTRS_CLEAR_BITMASK
  if (py_clear != Py_None) {
    optargs_s.bitmask |= GUESTFS_SET_E2ATTRS_CLEAR_BITMASK;
    optargs_s.clear = PyLong_AsLong (py_clear);
    if (PyErr_Occurred ()) goto out;
  }
#endif

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_set_e2attrs_argv (g, file, attrs, optargs);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_SET_E2GENERATION
static PyObject *
guestfs_int_py_set_e2generation (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  const char *file;
  long long generation;

  if (!PyArg_ParseTuple (args, (char *) "OsL:guestfs_set_e2generation",
                         &py_g, &file, &generation))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_set_e2generation (g, file, generation);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_SET_E2LABEL
static PyObject *
guestfs_int_py_set_e2label (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  const char *device;
  const char *label;

  if (!PyArg_ParseTuple (args, (char *) "Oss:guestfs_set_e2label",
                         &py_g, &device, &label))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_set_e2label (g, device, label);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_SET_E2UUID
static PyObject *
guestfs_int_py_set_e2uuid (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  const char *device;
  const char *uuid;

  if (!PyArg_ParseTuple (args, (char *) "Oss:guestfs_set_e2uuid",
                         &py_g, &device, &uuid))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_set_e2uuid (g, device, uuid);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_SET_HV
static PyObject *
guestfs_int_py_set_hv (PyObject *self, PyObject *args)
{
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  const char *hv;

  if (!PyArg_ParseTuple (args, (char *) "Os:guestfs_set_hv",
                         &py_g, &hv))
    goto out;
  g = get_handle (py_g);

  r = guestfs_set_hv (g, hv);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_SET_IDENTIFIER
static PyObject *
guestfs_int_py_set_identifier (PyObject *self, PyObject *args)
{
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  const char *identifier;

  if (!PyArg_ParseTuple (args, (char *) "Os:guestfs_set_identifier",
                         &py_g, &identifier))
    goto out;
  g = get_handle (py_g);

  r = guestfs_set_identifier (g, identifier);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_SET_LABEL
static PyObject *
guestfs_int_py_set_label (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  const char *mountable;
  const char *label;

  if (!PyArg_ParseTuple (args, (char *) "Oss:guestfs_set_label",
                         &py_g, &mountable, &label))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_set_label (g, mountable, label);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_SET_LIBVIRT_REQUESTED_CREDENTIAL
static PyObject *
guestfs_int_py_set_libvirt_requested_credential (PyObject *self, PyObject *args)
{
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  int index;
  const char *cred;
  Py_ssize_t cred_size;

  if (!PyArg_ParseTuple (args, (char *) "Ois#:guestfs_set_libvirt_requested_credential",
                         &py_g, &index, &cred, &cred_size))
    goto out;
  g = get_handle (py_g);

  r = guestfs_set_libvirt_requested_credential (g, index, cred, cred_size);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_SET_LIBVIRT_SUPPORTED_CREDENTIALS
static PyObject *
guestfs_int_py_set_libvirt_supported_credentials (PyObject *self, PyObject *args)
{
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  PyObject *py_creds;
  char **creds = NULL;

  if (!PyArg_ParseTuple (args, (char *) "OO:guestfs_set_libvirt_supported_credentials",
                         &py_g, &py_creds))
    goto out;
  g = get_handle (py_g);
  creds = get_string_list (py_creds);
  if (!creds) goto out;

  r = guestfs_set_libvirt_supported_credentials (g, creds);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  free (creds);
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_SET_MEMSIZE
static PyObject *
guestfs_int_py_set_memsize (PyObject *self, PyObject *args)
{
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  int memsize;

  if (!PyArg_ParseTuple (args, (char *) "Oi:guestfs_set_memsize",
                         &py_g, &memsize))
    goto out;
  g = get_handle (py_g);

  r = guestfs_set_memsize (g, memsize);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_SET_NETWORK
static PyObject *
guestfs_int_py_set_network (PyObject *self, PyObject *args)
{
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  int network;

  if (!PyArg_ParseTuple (args, (char *) "Oi:guestfs_set_network",
                         &py_g, &network))
    goto out;
  g = get_handle (py_g);

  r = guestfs_set_network (g, network);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_SET_PATH
static PyObject *
guestfs_int_py_set_path (PyObject *self, PyObject *args)
{
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  const char *searchpath;

  if (!PyArg_ParseTuple (args, (char *) "Oz:guestfs_set_path",
                         &py_g, &searchpath))
    goto out;
  g = get_handle (py_g);

  r = guestfs_set_path (g, searchpath);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_SET_PGROUP
static PyObject *
guestfs_int_py_set_pgroup (PyObject *self, PyObject *args)
{
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  int pgroup;

  if (!PyArg_ParseTuple (args, (char *) "Oi:guestfs_set_pgroup",
                         &py_g, &pgroup))
    goto out;
  g = get_handle (py_g);

  r = guestfs_set_pgroup (g, pgroup);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_SET_PROGRAM
static PyObject *
guestfs_int_py_set_program (PyObject *self, PyObject *args)
{
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  const char *program;

  if (!PyArg_ParseTuple (args, (char *) "Os:guestfs_set_program",
                         &py_g, &program))
    goto out;
  g = get_handle (py_g);

  r = guestfs_set_program (g, program);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_SET_QEMU
static PyObject *
guestfs_int_py_set_qemu (PyObject *self, PyObject *args)
{
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  const char *hv;

  if (!PyArg_ParseTuple (args, (char *) "Oz:guestfs_set_qemu",
                         &py_g, &hv))
    goto out;
  g = get_handle (py_g);

  r = guestfs_set_qemu (g, hv);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_SET_RECOVERY_PROC
static PyObject *
guestfs_int_py_set_recovery_proc (PyObject *self, PyObject *args)
{
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  int recoveryproc;

  if (!PyArg_ParseTuple (args, (char *) "Oi:guestfs_set_recovery_proc",
                         &py_g, &recoveryproc))
    goto out;
  g = get_handle (py_g);

  r = guestfs_set_recovery_proc (g, recoveryproc);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_SET_SELINUX
static PyObject *
guestfs_int_py_set_selinux (PyObject *self, PyObject *args)
{
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  int selinux;

  if (!PyArg_ParseTuple (args, (char *) "Oi:guestfs_set_selinux",
                         &py_g, &selinux))
    goto out;
  g = get_handle (py_g);

  r = guestfs_set_selinux (g, selinux);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_SET_SMP
static PyObject *
guestfs_int_py_set_smp (PyObject *self, PyObject *args)
{
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  int smp;

  if (!PyArg_ParseTuple (args, (char *) "Oi:guestfs_set_smp",
                         &py_g, &smp))
    goto out;
  g = get_handle (py_g);

  r = guestfs_set_smp (g, smp);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_SET_TMPDIR
static PyObject *
guestfs_int_py_set_tmpdir (PyObject *self, PyObject *args)
{
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  const char *tmpdir;

  if (!PyArg_ParseTuple (args, (char *) "Oz:guestfs_set_tmpdir",
                         &py_g, &tmpdir))
    goto out;
  g = get_handle (py_g);

  r = guestfs_set_tmpdir (g, tmpdir);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_SET_TRACE
static PyObject *
guestfs_int_py_set_trace (PyObject *self, PyObject *args)
{
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  int trace;

  if (!PyArg_ParseTuple (args, (char *) "Oi:guestfs_set_trace",
                         &py_g, &trace))
    goto out;
  g = get_handle (py_g);

  r = guestfs_set_trace (g, trace);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_SET_UUID
static PyObject *
guestfs_int_py_set_uuid (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  const char *device;
  const char *uuid;

  if (!PyArg_ParseTuple (args, (char *) "Oss:guestfs_set_uuid",
                         &py_g, &device, &uuid))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_set_uuid (g, device, uuid);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_SET_UUID_RANDOM
static PyObject *
guestfs_int_py_set_uuid_random (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  const char *device;

  if (!PyArg_ParseTuple (args, (char *) "Os:guestfs_set_uuid_random",
                         &py_g, &device))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_set_uuid_random (g, device);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_SET_VERBOSE
static PyObject *
guestfs_int_py_set_verbose (PyObject *self, PyObject *args)
{
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  int verbose;

  if (!PyArg_ParseTuple (args, (char *) "Oi:guestfs_set_verbose",
                         &py_g, &verbose))
    goto out;
  g = get_handle (py_g);

  r = guestfs_set_verbose (g, verbose);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_SETCON
static PyObject *
guestfs_int_py_setcon (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  const char *context;

  if (!PyArg_ParseTuple (args, (char *) "Os:guestfs_setcon",
                         &py_g, &context))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_setcon (g, context);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_SETXATTR
static PyObject *
guestfs_int_py_setxattr (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  const char *xattr;
  const char *val;
  int vallen;
  const char *path;

  if (!PyArg_ParseTuple (args, (char *) "Ossis:guestfs_setxattr",
                         &py_g, &xattr, &val, &vallen, &path))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_setxattr (g, xattr, val, vallen, path);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_SFDISK
static PyObject *
guestfs_int_py_sfdisk (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  const char *device;
  int cyls;
  int heads;
  int sectors;
  PyObject *py_lines;
  char **lines = NULL;

  if (!PyArg_ParseTuple (args, (char *) "OsiiiO:guestfs_sfdisk",
                         &py_g, &device, &cyls, &heads, &sectors, &py_lines))
    goto out;
  g = get_handle (py_g);
  lines = get_string_list (py_lines);
  if (!lines) goto out;

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_sfdisk (g, device, cyls, heads, sectors, lines);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  free (lines);
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_SFDISKM
static PyObject *
guestfs_int_py_sfdiskM (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  const char *device;
  PyObject *py_lines;
  char **lines = NULL;

  if (!PyArg_ParseTuple (args, (char *) "OsO:guestfs_sfdiskM",
                         &py_g, &device, &py_lines))
    goto out;
  g = get_handle (py_g);
  lines = get_string_list (py_lines);
  if (!lines) goto out;

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_sfdiskM (g, device, lines);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  free (lines);
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_SFDISK_N
static PyObject *
guestfs_int_py_sfdisk_N (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  const char *device;
  int partnum;
  int cyls;
  int heads;
  int sectors;
  const char *line;

  if (!PyArg_ParseTuple (args, (char *) "Osiiiis:guestfs_sfdisk_N",
                         &py_g, &device, &partnum, &cyls, &heads, &sectors, &line))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_sfdisk_N (g, device, partnum, cyls, heads, sectors, line);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_SFDISK_DISK_GEOMETRY
static PyObject *
guestfs_int_py_sfdisk_disk_geometry (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  char *r;
  const char *device;

  if (!PyArg_ParseTuple (args, (char *) "Os:guestfs_sfdisk_disk_geometry",
                         &py_g, &device))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_sfdisk_disk_geometry (g, device);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == NULL) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

#ifdef HAVE_PYSTRING_ASSTRING
  py_r = PyString_FromString (r);
#else
  py_r = PyUnicode_FromString (r);
#endif
  free (r);
  if (py_r == NULL) goto out;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_SFDISK_KERNEL_GEOMETRY
static PyObject *
guestfs_int_py_sfdisk_kernel_geometry (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  char *r;
  const char *device;

  if (!PyArg_ParseTuple (args, (char *) "Os:guestfs_sfdisk_kernel_geometry",
                         &py_g, &device))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_sfdisk_kernel_geometry (g, device);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == NULL) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

#ifdef HAVE_PYSTRING_ASSTRING
  py_r = PyString_FromString (r);
#else
  py_r = PyUnicode_FromString (r);
#endif
  free (r);
  if (py_r == NULL) goto out;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_SFDISK_L
static PyObject *
guestfs_int_py_sfdisk_l (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  char *r;
  const char *device;

  if (!PyArg_ParseTuple (args, (char *) "Os:guestfs_sfdisk_l",
                         &py_g, &device))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_sfdisk_l (g, device);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == NULL) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

#ifdef HAVE_PYSTRING_ASSTRING
  py_r = PyString_FromString (r);
#else
  py_r = PyUnicode_FromString (r);
#endif
  free (r);
  if (py_r == NULL) goto out;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_SH
static PyObject *
guestfs_int_py_sh (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  char *r;
  const char *command;

  if (!PyArg_ParseTuple (args, (char *) "Os:guestfs_sh",
                         &py_g, &command))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_sh (g, command);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == NULL) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

#ifdef HAVE_PYSTRING_ASSTRING
  py_r = PyString_FromString (r);
#else
  py_r = PyUnicode_FromString (r);
#endif
  free (r);
  if (py_r == NULL) goto out;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_SH_LINES
static PyObject *
guestfs_int_py_sh_lines (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  char **r;
  const char *command;

  if (!PyArg_ParseTuple (args, (char *) "Os:guestfs_sh_lines",
                         &py_g, &command))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_sh_lines (g, command);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == NULL) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  py_r = put_string_list (r);
  guestfs_int_free_string_list (r);

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_SHUTDOWN
static PyObject *
guestfs_int_py_shutdown (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;

  if (!PyArg_ParseTuple (args, (char *) "O:guestfs_shutdown",
                         &py_g))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_shutdown (g);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_SLEEP
static PyObject *
guestfs_int_py_sleep (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  int secs;

  if (!PyArg_ParseTuple (args, (char *) "Oi:guestfs_sleep",
                         &py_g, &secs))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_sleep (g, secs);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_STAT
static PyObject *
guestfs_int_py_stat (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  struct guestfs_stat *r;
  const char *path;

  if (!PyArg_ParseTuple (args, (char *) "Os:guestfs_stat",
                         &py_g, &path))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_stat (g, path);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == NULL) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  py_r = put_stat (r);
  guestfs_free_stat (r);

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_STATNS
static PyObject *
guestfs_int_py_statns (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  struct guestfs_statns *r;
  const char *path;

  if (!PyArg_ParseTuple (args, (char *) "Os:guestfs_statns",
                         &py_g, &path))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_statns (g, path);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == NULL) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  py_r = put_statns (r);
  guestfs_free_statns (r);

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_STATVFS
static PyObject *
guestfs_int_py_statvfs (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  struct guestfs_statvfs *r;
  const char *path;

  if (!PyArg_ParseTuple (args, (char *) "Os:guestfs_statvfs",
                         &py_g, &path))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_statvfs (g, path);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == NULL) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  py_r = put_statvfs (r);
  guestfs_free_statvfs (r);

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_STRINGS
static PyObject *
guestfs_int_py_strings (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  char **r;
  const char *path;

  if (!PyArg_ParseTuple (args, (char *) "Os:guestfs_strings",
                         &py_g, &path))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_strings (g, path);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == NULL) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  py_r = put_string_list (r);
  guestfs_int_free_string_list (r);

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_STRINGS_E
static PyObject *
guestfs_int_py_strings_e (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  char **r;
  const char *encoding;
  const char *path;

  if (!PyArg_ParseTuple (args, (char *) "Oss:guestfs_strings_e",
                         &py_g, &encoding, &path))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_strings_e (g, encoding, path);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == NULL) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  py_r = put_string_list (r);
  guestfs_int_free_string_list (r);

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_SWAPOFF_DEVICE
static PyObject *
guestfs_int_py_swapoff_device (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  const char *device;

  if (!PyArg_ParseTuple (args, (char *) "Os:guestfs_swapoff_device",
                         &py_g, &device))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_swapoff_device (g, device);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_SWAPOFF_FILE
static PyObject *
guestfs_int_py_swapoff_file (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  const char *file;

  if (!PyArg_ParseTuple (args, (char *) "Os:guestfs_swapoff_file",
                         &py_g, &file))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_swapoff_file (g, file);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_SWAPOFF_LABEL
static PyObject *
guestfs_int_py_swapoff_label (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  const char *label;

  if (!PyArg_ParseTuple (args, (char *) "Os:guestfs_swapoff_label",
                         &py_g, &label))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_swapoff_label (g, label);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_SWAPOFF_UUID
static PyObject *
guestfs_int_py_swapoff_uuid (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  const char *uuid;

  if (!PyArg_ParseTuple (args, (char *) "Os:guestfs_swapoff_uuid",
                         &py_g, &uuid))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_swapoff_uuid (g, uuid);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_SWAPON_DEVICE
static PyObject *
guestfs_int_py_swapon_device (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  const char *device;

  if (!PyArg_ParseTuple (args, (char *) "Os:guestfs_swapon_device",
                         &py_g, &device))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_swapon_device (g, device);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_SWAPON_FILE
static PyObject *
guestfs_int_py_swapon_file (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  const char *file;

  if (!PyArg_ParseTuple (args, (char *) "Os:guestfs_swapon_file",
                         &py_g, &file))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_swapon_file (g, file);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_SWAPON_LABEL
static PyObject *
guestfs_int_py_swapon_label (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  const char *label;

  if (!PyArg_ParseTuple (args, (char *) "Os:guestfs_swapon_label",
                         &py_g, &label))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_swapon_label (g, label);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_SWAPON_UUID
static PyObject *
guestfs_int_py_swapon_uuid (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  const char *uuid;

  if (!PyArg_ParseTuple (args, (char *) "Os:guestfs_swapon_uuid",
                         &py_g, &uuid))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_swapon_uuid (g, uuid);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_SYNC
static PyObject *
guestfs_int_py_sync (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;

  if (!PyArg_ParseTuple (args, (char *) "O:guestfs_sync",
                         &py_g))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_sync (g);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_SYSLINUX
static PyObject *
guestfs_int_py_syslinux (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  struct guestfs_syslinux_argv optargs_s;
  struct guestfs_syslinux_argv *optargs = &optargs_s;
  int r;
  const char *device;
  PyObject *py_directory;

  optargs_s.bitmask = 0;

  if (!PyArg_ParseTuple (args, (char *) "OsO:guestfs_syslinux",
                         &py_g, &device, &py_directory))
    goto out;
  g = get_handle (py_g);

#ifdef GUESTFS_SYSLINUX_DIRECTORY_BITMASK
  if (py_directory != Py_None) {
    optargs_s.bitmask |= GUESTFS_SYSLINUX_DIRECTORY_BITMASK;
#ifdef HAVE_PYSTRING_ASSTRING
    optargs_s.directory = PyString_AsString (py_directory);
#else
    PyObject *bytes;
    bytes = PyUnicode_AsUTF8String (py_directory);
    optargs_s.directory = PyBytes_AS_STRING (bytes);
#endif
  }
#endif

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_syslinux_argv (g, device, optargs);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_TAIL
static PyObject *
guestfs_int_py_tail (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  char **r;
  const char *path;

  if (!PyArg_ParseTuple (args, (char *) "Os:guestfs_tail",
                         &py_g, &path))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_tail (g, path);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == NULL) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  py_r = put_string_list (r);
  guestfs_int_free_string_list (r);

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_TAIL_N
static PyObject *
guestfs_int_py_tail_n (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  char **r;
  int nrlines;
  const char *path;

  if (!PyArg_ParseTuple (args, (char *) "Ois:guestfs_tail_n",
                         &py_g, &nrlines, &path))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_tail_n (g, nrlines, path);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == NULL) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  py_r = put_string_list (r);
  guestfs_int_free_string_list (r);

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_TAR_IN_OPTS
static PyObject *
guestfs_int_py_tar_in (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  struct guestfs_tar_in_opts_argv optargs_s;
  struct guestfs_tar_in_opts_argv *optargs = &optargs_s;
  int r;
  const char *tarfile;
  const char *directory;
  PyObject *py_compress;
  PyObject *py_xattrs;
  PyObject *py_selinux;
  PyObject *py_acls;

  optargs_s.bitmask = 0;

  if (!PyArg_ParseTuple (args, (char *) "OssOOOO:guestfs_tar_in",
                         &py_g, &tarfile, &directory, &py_compress, &py_xattrs, &py_selinux, &py_acls))
    goto out;
  g = get_handle (py_g);

#ifdef GUESTFS_TAR_IN_OPTS_COMPRESS_BITMASK
  if (py_compress != Py_None) {
    optargs_s.bitmask |= GUESTFS_TAR_IN_OPTS_COMPRESS_BITMASK;
#ifdef HAVE_PYSTRING_ASSTRING
    optargs_s.compress = PyString_AsString (py_compress);
#else
    PyObject *bytes;
    bytes = PyUnicode_AsUTF8String (py_compress);
    optargs_s.compress = PyBytes_AS_STRING (bytes);
#endif
  }
#endif
#ifdef GUESTFS_TAR_IN_OPTS_XATTRS_BITMASK
  if (py_xattrs != Py_None) {
    optargs_s.bitmask |= GUESTFS_TAR_IN_OPTS_XATTRS_BITMASK;
    optargs_s.xattrs = PyLong_AsLong (py_xattrs);
    if (PyErr_Occurred ()) goto out;
  }
#endif
#ifdef GUESTFS_TAR_IN_OPTS_SELINUX_BITMASK
  if (py_selinux != Py_None) {
    optargs_s.bitmask |= GUESTFS_TAR_IN_OPTS_SELINUX_BITMASK;
    optargs_s.selinux = PyLong_AsLong (py_selinux);
    if (PyErr_Occurred ()) goto out;
  }
#endif
#ifdef GUESTFS_TAR_IN_OPTS_ACLS_BITMASK
  if (py_acls != Py_None) {
    optargs_s.bitmask |= GUESTFS_TAR_IN_OPTS_ACLS_BITMASK;
    optargs_s.acls = PyLong_AsLong (py_acls);
    if (PyErr_Occurred ()) goto out;
  }
#endif

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_tar_in_opts_argv (g, tarfile, directory, optargs);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_TAR_OUT_OPTS
static PyObject *
guestfs_int_py_tar_out (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  struct guestfs_tar_out_opts_argv optargs_s;
  struct guestfs_tar_out_opts_argv *optargs = &optargs_s;
  int r;
  const char *directory;
  const char *tarfile;
  PyObject *py_compress;
  PyObject *py_numericowner;
  PyObject *py_excludes;
  PyObject *py_xattrs;
  PyObject *py_selinux;
  PyObject *py_acls;

  optargs_s.bitmask = 0;

  if (!PyArg_ParseTuple (args, (char *) "OssOOOOOO:guestfs_tar_out",
                         &py_g, &directory, &tarfile, &py_compress, &py_numericowner, &py_excludes, &py_xattrs, &py_selinux, &py_acls))
    goto out;
  g = get_handle (py_g);

#ifdef GUESTFS_TAR_OUT_OPTS_COMPRESS_BITMASK
  if (py_compress != Py_None) {
    optargs_s.bitmask |= GUESTFS_TAR_OUT_OPTS_COMPRESS_BITMASK;
#ifdef HAVE_PYSTRING_ASSTRING
    optargs_s.compress = PyString_AsString (py_compress);
#else
    PyObject *bytes;
    bytes = PyUnicode_AsUTF8String (py_compress);
    optargs_s.compress = PyBytes_AS_STRING (bytes);
#endif
  }
#endif
#ifdef GUESTFS_TAR_OUT_OPTS_NUMERICOWNER_BITMASK
  if (py_numericowner != Py_None) {
    optargs_s.bitmask |= GUESTFS_TAR_OUT_OPTS_NUMERICOWNER_BITMASK;
    optargs_s.numericowner = PyLong_AsLong (py_numericowner);
    if (PyErr_Occurred ()) goto out;
  }
#endif
#ifdef GUESTFS_TAR_OUT_OPTS_EXCLUDES_BITMASK
  if (py_excludes != Py_None) {
    optargs_s.bitmask |= GUESTFS_TAR_OUT_OPTS_EXCLUDES_BITMASK;
    optargs_s.excludes = get_string_list (py_excludes);
    if (!optargs_s.excludes) goto out;
  }
#endif
#ifdef GUESTFS_TAR_OUT_OPTS_XATTRS_BITMASK
  if (py_xattrs != Py_None) {
    optargs_s.bitmask |= GUESTFS_TAR_OUT_OPTS_XATTRS_BITMASK;
    optargs_s.xattrs = PyLong_AsLong (py_xattrs);
    if (PyErr_Occurred ()) goto out;
  }
#endif
#ifdef GUESTFS_TAR_OUT_OPTS_SELINUX_BITMASK
  if (py_selinux != Py_None) {
    optargs_s.bitmask |= GUESTFS_TAR_OUT_OPTS_SELINUX_BITMASK;
    optargs_s.selinux = PyLong_AsLong (py_selinux);
    if (PyErr_Occurred ()) goto out;
  }
#endif
#ifdef GUESTFS_TAR_OUT_OPTS_ACLS_BITMASK
  if (py_acls != Py_None) {
    optargs_s.bitmask |= GUESTFS_TAR_OUT_OPTS_ACLS_BITMASK;
    optargs_s.acls = PyLong_AsLong (py_acls);
    if (PyErr_Occurred ()) goto out;
  }
#endif

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_tar_out_opts_argv (g, directory, tarfile, optargs);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
#ifdef GUESTFS_TAR_OUT_OPTS_EXCLUDES_BITMASK
  if (py_excludes != Py_None && (optargs_s.bitmask & GUESTFS_TAR_OUT_OPTS_EXCLUDES_BITMASK) != 0)
    free ((char **) optargs_s.excludes);
#endif
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_TGZ_IN
static PyObject *
guestfs_int_py_tgz_in (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  const char *tarball;
  const char *directory;

  if (!PyArg_ParseTuple (args, (char *) "Oss:guestfs_tgz_in",
                         &py_g, &tarball, &directory))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_tgz_in (g, tarball, directory);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_TGZ_OUT
static PyObject *
guestfs_int_py_tgz_out (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  const char *directory;
  const char *tarball;

  if (!PyArg_ParseTuple (args, (char *) "Oss:guestfs_tgz_out",
                         &py_g, &directory, &tarball))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_tgz_out (g, directory, tarball);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_TOUCH
static PyObject *
guestfs_int_py_touch (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  const char *path;

  if (!PyArg_ParseTuple (args, (char *) "Os:guestfs_touch",
                         &py_g, &path))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_touch (g, path);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_TRUNCATE
static PyObject *
guestfs_int_py_truncate (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  const char *path;

  if (!PyArg_ParseTuple (args, (char *) "Os:guestfs_truncate",
                         &py_g, &path))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_truncate (g, path);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_TRUNCATE_SIZE
static PyObject *
guestfs_int_py_truncate_size (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  const char *path;
  long long size;

  if (!PyArg_ParseTuple (args, (char *) "OsL:guestfs_truncate_size",
                         &py_g, &path, &size))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_truncate_size (g, path, size);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_TUNE2FS
static PyObject *
guestfs_int_py_tune2fs (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  struct guestfs_tune2fs_argv optargs_s;
  struct guestfs_tune2fs_argv *optargs = &optargs_s;
  int r;
  const char *device;
  PyObject *py_force;
  PyObject *py_maxmountcount;
  PyObject *py_mountcount;
  PyObject *py_errorbehavior;
  PyObject *py_group;
  PyObject *py_intervalbetweenchecks;
  PyObject *py_reservedblockspercentage;
  PyObject *py_lastmounteddirectory;
  PyObject *py_reservedblockscount;
  PyObject *py_user;

  optargs_s.bitmask = 0;

  if (!PyArg_ParseTuple (args, (char *) "OsOOOOOOOOOO:guestfs_tune2fs",
                         &py_g, &device, &py_force, &py_maxmountcount, &py_mountcount, &py_errorbehavior, &py_group, &py_intervalbetweenchecks, &py_reservedblockspercentage, &py_lastmounteddirectory, &py_reservedblockscount, &py_user))
    goto out;
  g = get_handle (py_g);

#ifdef GUESTFS_TUNE2FS_FORCE_BITMASK
  if (py_force != Py_None) {
    optargs_s.bitmask |= GUESTFS_TUNE2FS_FORCE_BITMASK;
    optargs_s.force = PyLong_AsLong (py_force);
    if (PyErr_Occurred ()) goto out;
  }
#endif
#ifdef GUESTFS_TUNE2FS_MAXMOUNTCOUNT_BITMASK
  if (py_maxmountcount != Py_None) {
    optargs_s.bitmask |= GUESTFS_TUNE2FS_MAXMOUNTCOUNT_BITMASK;
    optargs_s.maxmountcount = PyLong_AsLong (py_maxmountcount);
    if (PyErr_Occurred ()) goto out;
  }
#endif
#ifdef GUESTFS_TUNE2FS_MOUNTCOUNT_BITMASK
  if (py_mountcount != Py_None) {
    optargs_s.bitmask |= GUESTFS_TUNE2FS_MOUNTCOUNT_BITMASK;
    optargs_s.mountcount = PyLong_AsLong (py_mountcount);
    if (PyErr_Occurred ()) goto out;
  }
#endif
#ifdef GUESTFS_TUNE2FS_ERRORBEHAVIOR_BITMASK
  if (py_errorbehavior != Py_None) {
    optargs_s.bitmask |= GUESTFS_TUNE2FS_ERRORBEHAVIOR_BITMASK;
#ifdef HAVE_PYSTRING_ASSTRING
    optargs_s.errorbehavior = PyString_AsString (py_errorbehavior);
#else
    PyObject *bytes;
    bytes = PyUnicode_AsUTF8String (py_errorbehavior);
    optargs_s.errorbehavior = PyBytes_AS_STRING (bytes);
#endif
  }
#endif
#ifdef GUESTFS_TUNE2FS_GROUP_BITMASK
  if (py_group != Py_None) {
    optargs_s.bitmask |= GUESTFS_TUNE2FS_GROUP_BITMASK;
    optargs_s.group = PyLong_AsLongLong (py_group);
    if (PyErr_Occurred ()) goto out;
  }
#endif
#ifdef GUESTFS_TUNE2FS_INTERVALBETWEENCHECKS_BITMASK
  if (py_intervalbetweenchecks != Py_None) {
    optargs_s.bitmask |= GUESTFS_TUNE2FS_INTERVALBETWEENCHECKS_BITMASK;
    optargs_s.intervalbetweenchecks = PyLong_AsLong (py_intervalbetweenchecks);
    if (PyErr_Occurred ()) goto out;
  }
#endif
#ifdef GUESTFS_TUNE2FS_RESERVEDBLOCKSPERCENTAGE_BITMASK
  if (py_reservedblockspercentage != Py_None) {
    optargs_s.bitmask |= GUESTFS_TUNE2FS_RESERVEDBLOCKSPERCENTAGE_BITMASK;
    optargs_s.reservedblockspercentage = PyLong_AsLong (py_reservedblockspercentage);
    if (PyErr_Occurred ()) goto out;
  }
#endif
#ifdef GUESTFS_TUNE2FS_LASTMOUNTEDDIRECTORY_BITMASK
  if (py_lastmounteddirectory != Py_None) {
    optargs_s.bitmask |= GUESTFS_TUNE2FS_LASTMOUNTEDDIRECTORY_BITMASK;
#ifdef HAVE_PYSTRING_ASSTRING
    optargs_s.lastmounteddirectory = PyString_AsString (py_lastmounteddirectory);
#else
    PyObject *bytes;
    bytes = PyUnicode_AsUTF8String (py_lastmounteddirectory);
    optargs_s.lastmounteddirectory = PyBytes_AS_STRING (bytes);
#endif
  }
#endif
#ifdef GUESTFS_TUNE2FS_RESERVEDBLOCKSCOUNT_BITMASK
  if (py_reservedblockscount != Py_None) {
    optargs_s.bitmask |= GUESTFS_TUNE2FS_RESERVEDBLOCKSCOUNT_BITMASK;
    optargs_s.reservedblockscount = PyLong_AsLongLong (py_reservedblockscount);
    if (PyErr_Occurred ()) goto out;
  }
#endif
#ifdef GUESTFS_TUNE2FS_USER_BITMASK
  if (py_user != Py_None) {
    optargs_s.bitmask |= GUESTFS_TUNE2FS_USER_BITMASK;
    optargs_s.user = PyLong_AsLongLong (py_user);
    if (PyErr_Occurred ()) goto out;
  }
#endif

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_tune2fs_argv (g, device, optargs);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_TUNE2FS_L
static PyObject *
guestfs_int_py_tune2fs_l (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  char **r;
  const char *device;

  if (!PyArg_ParseTuple (args, (char *) "Os:guestfs_tune2fs_l",
                         &py_g, &device))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_tune2fs_l (g, device);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == NULL) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  py_r = put_table (r);
  guestfs_int_free_string_list (r);

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_TXZ_IN
static PyObject *
guestfs_int_py_txz_in (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  const char *tarball;
  const char *directory;

  if (!PyArg_ParseTuple (args, (char *) "Oss:guestfs_txz_in",
                         &py_g, &tarball, &directory))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_txz_in (g, tarball, directory);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_TXZ_OUT
static PyObject *
guestfs_int_py_txz_out (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  const char *directory;
  const char *tarball;

  if (!PyArg_ParseTuple (args, (char *) "Oss:guestfs_txz_out",
                         &py_g, &directory, &tarball))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_txz_out (g, directory, tarball);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_UMASK
static PyObject *
guestfs_int_py_umask (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  int mask;

  if (!PyArg_ParseTuple (args, (char *) "Oi:guestfs_umask",
                         &py_g, &mask))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_umask (g, mask);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  py_r = PyLong_FromLong ((long) r);

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_UMOUNT_OPTS
static PyObject *
guestfs_int_py_umount (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  struct guestfs_umount_opts_argv optargs_s;
  struct guestfs_umount_opts_argv *optargs = &optargs_s;
  int r;
  const char *pathordevice;
  PyObject *py_force;
  PyObject *py_lazyunmount;

  optargs_s.bitmask = 0;

  if (!PyArg_ParseTuple (args, (char *) "OsOO:guestfs_umount",
                         &py_g, &pathordevice, &py_force, &py_lazyunmount))
    goto out;
  g = get_handle (py_g);

#ifdef GUESTFS_UMOUNT_OPTS_FORCE_BITMASK
  if (py_force != Py_None) {
    optargs_s.bitmask |= GUESTFS_UMOUNT_OPTS_FORCE_BITMASK;
    optargs_s.force = PyLong_AsLong (py_force);
    if (PyErr_Occurred ()) goto out;
  }
#endif
#ifdef GUESTFS_UMOUNT_OPTS_LAZYUNMOUNT_BITMASK
  if (py_lazyunmount != Py_None) {
    optargs_s.bitmask |= GUESTFS_UMOUNT_OPTS_LAZYUNMOUNT_BITMASK;
    optargs_s.lazyunmount = PyLong_AsLong (py_lazyunmount);
    if (PyErr_Occurred ()) goto out;
  }
#endif

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_umount_opts_argv (g, pathordevice, optargs);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_UMOUNT_ALL
static PyObject *
guestfs_int_py_umount_all (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;

  if (!PyArg_ParseTuple (args, (char *) "O:guestfs_umount_all",
                         &py_g))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_umount_all (g);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_UMOUNT_LOCAL
static PyObject *
guestfs_int_py_umount_local (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  struct guestfs_umount_local_argv optargs_s;
  struct guestfs_umount_local_argv *optargs = &optargs_s;
  int r;
  PyObject *py_retry;

  optargs_s.bitmask = 0;

  if (!PyArg_ParseTuple (args, (char *) "OO:guestfs_umount_local",
                         &py_g, &py_retry))
    goto out;
  g = get_handle (py_g);

#ifdef GUESTFS_UMOUNT_LOCAL_RETRY_BITMASK
  if (py_retry != Py_None) {
    optargs_s.bitmask |= GUESTFS_UMOUNT_LOCAL_RETRY_BITMASK;
    optargs_s.retry = PyLong_AsLong (py_retry);
    if (PyErr_Occurred ()) goto out;
  }
#endif

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_umount_local_argv (g, optargs);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_UPLOAD
static PyObject *
guestfs_int_py_upload (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  const char *filename;
  const char *remotefilename;

  if (!PyArg_ParseTuple (args, (char *) "Oss:guestfs_upload",
                         &py_g, &filename, &remotefilename))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_upload (g, filename, remotefilename);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_UPLOAD_OFFSET
static PyObject *
guestfs_int_py_upload_offset (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  const char *filename;
  const char *remotefilename;
  long long offset;

  if (!PyArg_ParseTuple (args, (char *) "OssL:guestfs_upload_offset",
                         &py_g, &filename, &remotefilename, &offset))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_upload_offset (g, filename, remotefilename, offset);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_USER_CANCEL
static PyObject *
guestfs_int_py_user_cancel (PyObject *self, PyObject *args)
{
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;

  if (!PyArg_ParseTuple (args, (char *) "O:guestfs_user_cancel",
                         &py_g))
    goto out;
  g = get_handle (py_g);

  r = guestfs_user_cancel (g);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_UTIMENS
static PyObject *
guestfs_int_py_utimens (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  const char *path;
  long long atsecs;
  long long atnsecs;
  long long mtsecs;
  long long mtnsecs;

  if (!PyArg_ParseTuple (args, (char *) "OsLLLL:guestfs_utimens",
                         &py_g, &path, &atsecs, &atnsecs, &mtsecs, &mtnsecs))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_utimens (g, path, atsecs, atnsecs, mtsecs, mtnsecs);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_UTSNAME
static PyObject *
guestfs_int_py_utsname (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  struct guestfs_utsname *r;

  if (!PyArg_ParseTuple (args, (char *) "O:guestfs_utsname",
                         &py_g))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_utsname (g);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == NULL) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  py_r = put_utsname (r);
  guestfs_free_utsname (r);

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_VERSION
static PyObject *
guestfs_int_py_version (PyObject *self, PyObject *args)
{
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  struct guestfs_version *r;

  if (!PyArg_ParseTuple (args, (char *) "O:guestfs_version",
                         &py_g))
    goto out;
  g = get_handle (py_g);

  r = guestfs_version (g);

  if (r == NULL) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  py_r = put_version (r);
  guestfs_free_version (r);

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_VFS_LABEL
static PyObject *
guestfs_int_py_vfs_label (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  char *r;
  const char *mountable;

  if (!PyArg_ParseTuple (args, (char *) "Os:guestfs_vfs_label",
                         &py_g, &mountable))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_vfs_label (g, mountable);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == NULL) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

#ifdef HAVE_PYSTRING_ASSTRING
  py_r = PyString_FromString (r);
#else
  py_r = PyUnicode_FromString (r);
#endif
  free (r);
  if (py_r == NULL) goto out;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_VFS_MINIMUM_SIZE
static PyObject *
guestfs_int_py_vfs_minimum_size (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int64_t r;
  const char *mountable;

  if (!PyArg_ParseTuple (args, (char *) "Os:guestfs_vfs_minimum_size",
                         &py_g, &mountable))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_vfs_minimum_size (g, mountable);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  py_r = PyLong_FromLongLong (r);

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_VFS_TYPE
static PyObject *
guestfs_int_py_vfs_type (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  char *r;
  const char *mountable;

  if (!PyArg_ParseTuple (args, (char *) "Os:guestfs_vfs_type",
                         &py_g, &mountable))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_vfs_type (g, mountable);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == NULL) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

#ifdef HAVE_PYSTRING_ASSTRING
  py_r = PyString_FromString (r);
#else
  py_r = PyUnicode_FromString (r);
#endif
  free (r);
  if (py_r == NULL) goto out;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_VFS_UUID
static PyObject *
guestfs_int_py_vfs_uuid (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  char *r;
  const char *mountable;

  if (!PyArg_ParseTuple (args, (char *) "Os:guestfs_vfs_uuid",
                         &py_g, &mountable))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_vfs_uuid (g, mountable);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == NULL) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

#ifdef HAVE_PYSTRING_ASSTRING
  py_r = PyString_FromString (r);
#else
  py_r = PyUnicode_FromString (r);
#endif
  free (r);
  if (py_r == NULL) goto out;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_VG_ACTIVATE
static PyObject *
guestfs_int_py_vg_activate (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  int activate;
  PyObject *py_volgroups;
  char **volgroups = NULL;

  if (!PyArg_ParseTuple (args, (char *) "OiO:guestfs_vg_activate",
                         &py_g, &activate, &py_volgroups))
    goto out;
  g = get_handle (py_g);
  volgroups = get_string_list (py_volgroups);
  if (!volgroups) goto out;

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_vg_activate (g, activate, volgroups);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  free (volgroups);
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_VG_ACTIVATE_ALL
static PyObject *
guestfs_int_py_vg_activate_all (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  int activate;

  if (!PyArg_ParseTuple (args, (char *) "Oi:guestfs_vg_activate_all",
                         &py_g, &activate))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_vg_activate_all (g, activate);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_VGCHANGE_UUID
static PyObject *
guestfs_int_py_vgchange_uuid (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  const char *vg;

  if (!PyArg_ParseTuple (args, (char *) "Os:guestfs_vgchange_uuid",
                         &py_g, &vg))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_vgchange_uuid (g, vg);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_VGCHANGE_UUID_ALL
static PyObject *
guestfs_int_py_vgchange_uuid_all (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;

  if (!PyArg_ParseTuple (args, (char *) "O:guestfs_vgchange_uuid_all",
                         &py_g))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_vgchange_uuid_all (g);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_VGCREATE
static PyObject *
guestfs_int_py_vgcreate (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  const char *volgroup;
  PyObject *py_physvols;
  char **physvols = NULL;

  if (!PyArg_ParseTuple (args, (char *) "OsO:guestfs_vgcreate",
                         &py_g, &volgroup, &py_physvols))
    goto out;
  g = get_handle (py_g);
  physvols = get_string_list (py_physvols);
  if (!physvols) goto out;

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_vgcreate (g, volgroup, physvols);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  free (physvols);
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_VGLVUUIDS
static PyObject *
guestfs_int_py_vglvuuids (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  char **r;
  const char *vgname;

  if (!PyArg_ParseTuple (args, (char *) "Os:guestfs_vglvuuids",
                         &py_g, &vgname))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_vglvuuids (g, vgname);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == NULL) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  py_r = put_string_list (r);
  guestfs_int_free_string_list (r);

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_VGMETA
static PyObject *
guestfs_int_py_vgmeta (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  char *r;
  size_t size;
  const char *vgname;

  if (!PyArg_ParseTuple (args, (char *) "Os:guestfs_vgmeta",
                         &py_g, &vgname))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_vgmeta (g, vgname, &size);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == NULL) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

#ifdef HAVE_PYSTRING_ASSTRING
  py_r = PyString_FromStringAndSize (r, size);
#else
  py_r = PyBytes_FromStringAndSize (r, size);
#endif
  free (r);
  if (py_r == NULL) goto out;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_VGPVUUIDS
static PyObject *
guestfs_int_py_vgpvuuids (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  char **r;
  const char *vgname;

  if (!PyArg_ParseTuple (args, (char *) "Os:guestfs_vgpvuuids",
                         &py_g, &vgname))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_vgpvuuids (g, vgname);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == NULL) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  py_r = put_string_list (r);
  guestfs_int_free_string_list (r);

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_VGREMOVE
static PyObject *
guestfs_int_py_vgremove (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  const char *vgname;

  if (!PyArg_ParseTuple (args, (char *) "Os:guestfs_vgremove",
                         &py_g, &vgname))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_vgremove (g, vgname);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_VGRENAME
static PyObject *
guestfs_int_py_vgrename (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  const char *volgroup;
  const char *newvolgroup;

  if (!PyArg_ParseTuple (args, (char *) "Oss:guestfs_vgrename",
                         &py_g, &volgroup, &newvolgroup))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_vgrename (g, volgroup, newvolgroup);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_VGS
static PyObject *
guestfs_int_py_vgs (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  char **r;

  if (!PyArg_ParseTuple (args, (char *) "O:guestfs_vgs",
                         &py_g))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_vgs (g);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == NULL) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  py_r = put_string_list (r);
  guestfs_int_free_string_list (r);

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_VGS_FULL
static PyObject *
guestfs_int_py_vgs_full (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  struct guestfs_lvm_vg_list *r;

  if (!PyArg_ParseTuple (args, (char *) "O:guestfs_vgs_full",
                         &py_g))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_vgs_full (g);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == NULL) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  py_r = put_lvm_vg_list (r);
  guestfs_free_lvm_vg_list (r);

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_VGSCAN
static PyObject *
guestfs_int_py_vgscan (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;

  if (!PyArg_ParseTuple (args, (char *) "O:guestfs_vgscan",
                         &py_g))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_vgscan (g);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_VGUUID
static PyObject *
guestfs_int_py_vguuid (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  char *r;
  const char *vgname;

  if (!PyArg_ParseTuple (args, (char *) "Os:guestfs_vguuid",
                         &py_g, &vgname))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_vguuid (g, vgname);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == NULL) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

#ifdef HAVE_PYSTRING_ASSTRING
  py_r = PyString_FromString (r);
#else
  py_r = PyUnicode_FromString (r);
#endif
  free (r);
  if (py_r == NULL) goto out;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_WAIT_READY
static PyObject *
guestfs_int_py_wait_ready (PyObject *self, PyObject *args)
{
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;

  if (!PyArg_ParseTuple (args, (char *) "O:guestfs_wait_ready",
                         &py_g))
    goto out;
  g = get_handle (py_g);

  r = guestfs_wait_ready (g);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_WC_C
static PyObject *
guestfs_int_py_wc_c (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  const char *path;

  if (!PyArg_ParseTuple (args, (char *) "Os:guestfs_wc_c",
                         &py_g, &path))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_wc_c (g, path);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  py_r = PyLong_FromLong ((long) r);

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_WC_L
static PyObject *
guestfs_int_py_wc_l (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  const char *path;

  if (!PyArg_ParseTuple (args, (char *) "Os:guestfs_wc_l",
                         &py_g, &path))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_wc_l (g, path);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  py_r = PyLong_FromLong ((long) r);

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_WC_W
static PyObject *
guestfs_int_py_wc_w (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  const char *path;

  if (!PyArg_ParseTuple (args, (char *) "Os:guestfs_wc_w",
                         &py_g, &path))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_wc_w (g, path);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  py_r = PyLong_FromLong ((long) r);

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_WIPEFS
static PyObject *
guestfs_int_py_wipefs (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  const char *device;

  if (!PyArg_ParseTuple (args, (char *) "Os:guestfs_wipefs",
                         &py_g, &device))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_wipefs (g, device);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_WRITE
static PyObject *
guestfs_int_py_write (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  const char *path;
  const char *content;
  Py_ssize_t content_size;

  if (!PyArg_ParseTuple (args, (char *) "Oss#:guestfs_write",
                         &py_g, &path, &content, &content_size))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_write (g, path, content, content_size);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_WRITE_APPEND
static PyObject *
guestfs_int_py_write_append (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  const char *path;
  const char *content;
  Py_ssize_t content_size;

  if (!PyArg_ParseTuple (args, (char *) "Oss#:guestfs_write_append",
                         &py_g, &path, &content, &content_size))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_write_append (g, path, content, content_size);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_WRITE_FILE
static PyObject *
guestfs_int_py_write_file (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  const char *path;
  const char *content;
  int size;

  if (!PyArg_ParseTuple (args, (char *) "Ossi:guestfs_write_file",
                         &py_g, &path, &content, &size))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_write_file (g, path, content, size);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_XFS_ADMIN
static PyObject *
guestfs_int_py_xfs_admin (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  struct guestfs_xfs_admin_argv optargs_s;
  struct guestfs_xfs_admin_argv *optargs = &optargs_s;
  int r;
  const char *device;
  PyObject *py_extunwritten;
  PyObject *py_imgfile;
  PyObject *py_v2log;
  PyObject *py_projid32bit;
  PyObject *py_lazycounter;
  PyObject *py_label;
  PyObject *py_uuid;

  optargs_s.bitmask = 0;

  if (!PyArg_ParseTuple (args, (char *) "OsOOOOOOO:guestfs_xfs_admin",
                         &py_g, &device, &py_extunwritten, &py_imgfile, &py_v2log, &py_projid32bit, &py_lazycounter, &py_label, &py_uuid))
    goto out;
  g = get_handle (py_g);

#ifdef GUESTFS_XFS_ADMIN_EXTUNWRITTEN_BITMASK
  if (py_extunwritten != Py_None) {
    optargs_s.bitmask |= GUESTFS_XFS_ADMIN_EXTUNWRITTEN_BITMASK;
    optargs_s.extunwritten = PyLong_AsLong (py_extunwritten);
    if (PyErr_Occurred ()) goto out;
  }
#endif
#ifdef GUESTFS_XFS_ADMIN_IMGFILE_BITMASK
  if (py_imgfile != Py_None) {
    optargs_s.bitmask |= GUESTFS_XFS_ADMIN_IMGFILE_BITMASK;
    optargs_s.imgfile = PyLong_AsLong (py_imgfile);
    if (PyErr_Occurred ()) goto out;
  }
#endif
#ifdef GUESTFS_XFS_ADMIN_V2LOG_BITMASK
  if (py_v2log != Py_None) {
    optargs_s.bitmask |= GUESTFS_XFS_ADMIN_V2LOG_BITMASK;
    optargs_s.v2log = PyLong_AsLong (py_v2log);
    if (PyErr_Occurred ()) goto out;
  }
#endif
#ifdef GUESTFS_XFS_ADMIN_PROJID32BIT_BITMASK
  if (py_projid32bit != Py_None) {
    optargs_s.bitmask |= GUESTFS_XFS_ADMIN_PROJID32BIT_BITMASK;
    optargs_s.projid32bit = PyLong_AsLong (py_projid32bit);
    if (PyErr_Occurred ()) goto out;
  }
#endif
#ifdef GUESTFS_XFS_ADMIN_LAZYCOUNTER_BITMASK
  if (py_lazycounter != Py_None) {
    optargs_s.bitmask |= GUESTFS_XFS_ADMIN_LAZYCOUNTER_BITMASK;
    optargs_s.lazycounter = PyLong_AsLong (py_lazycounter);
    if (PyErr_Occurred ()) goto out;
  }
#endif
#ifdef GUESTFS_XFS_ADMIN_LABEL_BITMASK
  if (py_label != Py_None) {
    optargs_s.bitmask |= GUESTFS_XFS_ADMIN_LABEL_BITMASK;
#ifdef HAVE_PYSTRING_ASSTRING
    optargs_s.label = PyString_AsString (py_label);
#else
    PyObject *bytes;
    bytes = PyUnicode_AsUTF8String (py_label);
    optargs_s.label = PyBytes_AS_STRING (bytes);
#endif
  }
#endif
#ifdef GUESTFS_XFS_ADMIN_UUID_BITMASK
  if (py_uuid != Py_None) {
    optargs_s.bitmask |= GUESTFS_XFS_ADMIN_UUID_BITMASK;
#ifdef HAVE_PYSTRING_ASSTRING
    optargs_s.uuid = PyString_AsString (py_uuid);
#else
    PyObject *bytes;
    bytes = PyUnicode_AsUTF8String (py_uuid);
    optargs_s.uuid = PyBytes_AS_STRING (bytes);
#endif
  }
#endif

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_xfs_admin_argv (g, device, optargs);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_XFS_GROWFS
static PyObject *
guestfs_int_py_xfs_growfs (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  struct guestfs_xfs_growfs_argv optargs_s;
  struct guestfs_xfs_growfs_argv *optargs = &optargs_s;
  int r;
  const char *path;
  PyObject *py_datasec;
  PyObject *py_logsec;
  PyObject *py_rtsec;
  PyObject *py_datasize;
  PyObject *py_logsize;
  PyObject *py_rtsize;
  PyObject *py_rtextsize;
  PyObject *py_maxpct;

  optargs_s.bitmask = 0;

  if (!PyArg_ParseTuple (args, (char *) "OsOOOOOOOO:guestfs_xfs_growfs",
                         &py_g, &path, &py_datasec, &py_logsec, &py_rtsec, &py_datasize, &py_logsize, &py_rtsize, &py_rtextsize, &py_maxpct))
    goto out;
  g = get_handle (py_g);

#ifdef GUESTFS_XFS_GROWFS_DATASEC_BITMASK
  if (py_datasec != Py_None) {
    optargs_s.bitmask |= GUESTFS_XFS_GROWFS_DATASEC_BITMASK;
    optargs_s.datasec = PyLong_AsLong (py_datasec);
    if (PyErr_Occurred ()) goto out;
  }
#endif
#ifdef GUESTFS_XFS_GROWFS_LOGSEC_BITMASK
  if (py_logsec != Py_None) {
    optargs_s.bitmask |= GUESTFS_XFS_GROWFS_LOGSEC_BITMASK;
    optargs_s.logsec = PyLong_AsLong (py_logsec);
    if (PyErr_Occurred ()) goto out;
  }
#endif
#ifdef GUESTFS_XFS_GROWFS_RTSEC_BITMASK
  if (py_rtsec != Py_None) {
    optargs_s.bitmask |= GUESTFS_XFS_GROWFS_RTSEC_BITMASK;
    optargs_s.rtsec = PyLong_AsLong (py_rtsec);
    if (PyErr_Occurred ()) goto out;
  }
#endif
#ifdef GUESTFS_XFS_GROWFS_DATASIZE_BITMASK
  if (py_datasize != Py_None) {
    optargs_s.bitmask |= GUESTFS_XFS_GROWFS_DATASIZE_BITMASK;
    optargs_s.datasize = PyLong_AsLongLong (py_datasize);
    if (PyErr_Occurred ()) goto out;
  }
#endif
#ifdef GUESTFS_XFS_GROWFS_LOGSIZE_BITMASK
  if (py_logsize != Py_None) {
    optargs_s.bitmask |= GUESTFS_XFS_GROWFS_LOGSIZE_BITMASK;
    optargs_s.logsize = PyLong_AsLongLong (py_logsize);
    if (PyErr_Occurred ()) goto out;
  }
#endif
#ifdef GUESTFS_XFS_GROWFS_RTSIZE_BITMASK
  if (py_rtsize != Py_None) {
    optargs_s.bitmask |= GUESTFS_XFS_GROWFS_RTSIZE_BITMASK;
    optargs_s.rtsize = PyLong_AsLongLong (py_rtsize);
    if (PyErr_Occurred ()) goto out;
  }
#endif
#ifdef GUESTFS_XFS_GROWFS_RTEXTSIZE_BITMASK
  if (py_rtextsize != Py_None) {
    optargs_s.bitmask |= GUESTFS_XFS_GROWFS_RTEXTSIZE_BITMASK;
    optargs_s.rtextsize = PyLong_AsLongLong (py_rtextsize);
    if (PyErr_Occurred ()) goto out;
  }
#endif
#ifdef GUESTFS_XFS_GROWFS_MAXPCT_BITMASK
  if (py_maxpct != Py_None) {
    optargs_s.bitmask |= GUESTFS_XFS_GROWFS_MAXPCT_BITMASK;
    optargs_s.maxpct = PyLong_AsLong (py_maxpct);
    if (PyErr_Occurred ()) goto out;
  }
#endif

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_xfs_growfs_argv (g, path, optargs);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_XFS_INFO
static PyObject *
guestfs_int_py_xfs_info (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  struct guestfs_xfsinfo *r;
  const char *pathordevice;

  if (!PyArg_ParseTuple (args, (char *) "Os:guestfs_xfs_info",
                         &py_g, &pathordevice))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_xfs_info (g, pathordevice);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == NULL) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  py_r = put_xfsinfo (r);
  guestfs_free_xfsinfo (r);

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_XFS_REPAIR
static PyObject *
guestfs_int_py_xfs_repair (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  struct guestfs_xfs_repair_argv optargs_s;
  struct guestfs_xfs_repair_argv *optargs = &optargs_s;
  int r;
  const char *device;
  PyObject *py_forcelogzero;
  PyObject *py_nomodify;
  PyObject *py_noprefetch;
  PyObject *py_forcegeometry;
  PyObject *py_maxmem;
  PyObject *py_ihashsize;
  PyObject *py_bhashsize;
  PyObject *py_agstride;
  PyObject *py_logdev;
  PyObject *py_rtdev;

  optargs_s.bitmask = 0;

  if (!PyArg_ParseTuple (args, (char *) "OsOOOOOOOOOO:guestfs_xfs_repair",
                         &py_g, &device, &py_forcelogzero, &py_nomodify, &py_noprefetch, &py_forcegeometry, &py_maxmem, &py_ihashsize, &py_bhashsize, &py_agstride, &py_logdev, &py_rtdev))
    goto out;
  g = get_handle (py_g);

#ifdef GUESTFS_XFS_REPAIR_FORCELOGZERO_BITMASK
  if (py_forcelogzero != Py_None) {
    optargs_s.bitmask |= GUESTFS_XFS_REPAIR_FORCELOGZERO_BITMASK;
    optargs_s.forcelogzero = PyLong_AsLong (py_forcelogzero);
    if (PyErr_Occurred ()) goto out;
  }
#endif
#ifdef GUESTFS_XFS_REPAIR_NOMODIFY_BITMASK
  if (py_nomodify != Py_None) {
    optargs_s.bitmask |= GUESTFS_XFS_REPAIR_NOMODIFY_BITMASK;
    optargs_s.nomodify = PyLong_AsLong (py_nomodify);
    if (PyErr_Occurred ()) goto out;
  }
#endif
#ifdef GUESTFS_XFS_REPAIR_NOPREFETCH_BITMASK
  if (py_noprefetch != Py_None) {
    optargs_s.bitmask |= GUESTFS_XFS_REPAIR_NOPREFETCH_BITMASK;
    optargs_s.noprefetch = PyLong_AsLong (py_noprefetch);
    if (PyErr_Occurred ()) goto out;
  }
#endif
#ifdef GUESTFS_XFS_REPAIR_FORCEGEOMETRY_BITMASK
  if (py_forcegeometry != Py_None) {
    optargs_s.bitmask |= GUESTFS_XFS_REPAIR_FORCEGEOMETRY_BITMASK;
    optargs_s.forcegeometry = PyLong_AsLong (py_forcegeometry);
    if (PyErr_Occurred ()) goto out;
  }
#endif
#ifdef GUESTFS_XFS_REPAIR_MAXMEM_BITMASK
  if (py_maxmem != Py_None) {
    optargs_s.bitmask |= GUESTFS_XFS_REPAIR_MAXMEM_BITMASK;
    optargs_s.maxmem = PyLong_AsLongLong (py_maxmem);
    if (PyErr_Occurred ()) goto out;
  }
#endif
#ifdef GUESTFS_XFS_REPAIR_IHASHSIZE_BITMASK
  if (py_ihashsize != Py_None) {
    optargs_s.bitmask |= GUESTFS_XFS_REPAIR_IHASHSIZE_BITMASK;
    optargs_s.ihashsize = PyLong_AsLongLong (py_ihashsize);
    if (PyErr_Occurred ()) goto out;
  }
#endif
#ifdef GUESTFS_XFS_REPAIR_BHASHSIZE_BITMASK
  if (py_bhashsize != Py_None) {
    optargs_s.bitmask |= GUESTFS_XFS_REPAIR_BHASHSIZE_BITMASK;
    optargs_s.bhashsize = PyLong_AsLongLong (py_bhashsize);
    if (PyErr_Occurred ()) goto out;
  }
#endif
#ifdef GUESTFS_XFS_REPAIR_AGSTRIDE_BITMASK
  if (py_agstride != Py_None) {
    optargs_s.bitmask |= GUESTFS_XFS_REPAIR_AGSTRIDE_BITMASK;
    optargs_s.agstride = PyLong_AsLongLong (py_agstride);
    if (PyErr_Occurred ()) goto out;
  }
#endif
#ifdef GUESTFS_XFS_REPAIR_LOGDEV_BITMASK
  if (py_logdev != Py_None) {
    optargs_s.bitmask |= GUESTFS_XFS_REPAIR_LOGDEV_BITMASK;
#ifdef HAVE_PYSTRING_ASSTRING
    optargs_s.logdev = PyString_AsString (py_logdev);
#else
    PyObject *bytes;
    bytes = PyUnicode_AsUTF8String (py_logdev);
    optargs_s.logdev = PyBytes_AS_STRING (bytes);
#endif
  }
#endif
#ifdef GUESTFS_XFS_REPAIR_RTDEV_BITMASK
  if (py_rtdev != Py_None) {
    optargs_s.bitmask |= GUESTFS_XFS_REPAIR_RTDEV_BITMASK;
#ifdef HAVE_PYSTRING_ASSTRING
    optargs_s.rtdev = PyString_AsString (py_rtdev);
#else
    PyObject *bytes;
    bytes = PyUnicode_AsUTF8String (py_rtdev);
    optargs_s.rtdev = PyBytes_AS_STRING (bytes);
#endif
  }
#endif

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_xfs_repair_argv (g, device, optargs);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  py_r = PyLong_FromLong ((long) r);

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_ZEGREP
static PyObject *
guestfs_int_py_zegrep (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  char **r;
  const char *regex;
  const char *path;

  if (!PyArg_ParseTuple (args, (char *) "Oss:guestfs_zegrep",
                         &py_g, &regex, &path))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_zegrep (g, regex, path);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == NULL) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  py_r = put_string_list (r);
  guestfs_int_free_string_list (r);

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_ZEGREPI
static PyObject *
guestfs_int_py_zegrepi (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  char **r;
  const char *regex;
  const char *path;

  if (!PyArg_ParseTuple (args, (char *) "Oss:guestfs_zegrepi",
                         &py_g, &regex, &path))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_zegrepi (g, regex, path);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == NULL) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  py_r = put_string_list (r);
  guestfs_int_free_string_list (r);

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_ZERO
static PyObject *
guestfs_int_py_zero (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  const char *device;

  if (!PyArg_ParseTuple (args, (char *) "Os:guestfs_zero",
                         &py_g, &device))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_zero (g, device);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_ZERO_DEVICE
static PyObject *
guestfs_int_py_zero_device (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  const char *device;

  if (!PyArg_ParseTuple (args, (char *) "Os:guestfs_zero_device",
                         &py_g, &device))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_zero_device (g, device);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_ZERO_FREE_SPACE
static PyObject *
guestfs_int_py_zero_free_space (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  const char *directory;

  if (!PyArg_ParseTuple (args, (char *) "Os:guestfs_zero_free_space",
                         &py_g, &directory))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_zero_free_space (g, directory);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_ZEROFREE
static PyObject *
guestfs_int_py_zerofree (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  const char *device;

  if (!PyArg_ParseTuple (args, (char *) "Os:guestfs_zerofree",
                         &py_g, &device))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_zerofree (g, device);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_ZFGREP
static PyObject *
guestfs_int_py_zfgrep (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  char **r;
  const char *pattern;
  const char *path;

  if (!PyArg_ParseTuple (args, (char *) "Oss:guestfs_zfgrep",
                         &py_g, &pattern, &path))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_zfgrep (g, pattern, path);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == NULL) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  py_r = put_string_list (r);
  guestfs_int_free_string_list (r);

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_ZFGREPI
static PyObject *
guestfs_int_py_zfgrepi (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  char **r;
  const char *pattern;
  const char *path;

  if (!PyArg_ParseTuple (args, (char *) "Oss:guestfs_zfgrepi",
                         &py_g, &pattern, &path))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_zfgrepi (g, pattern, path);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == NULL) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  py_r = put_string_list (r);
  guestfs_int_free_string_list (r);

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_ZFILE
static PyObject *
guestfs_int_py_zfile (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  char *r;
  const char *meth;
  const char *path;

  if (!PyArg_ParseTuple (args, (char *) "Oss:guestfs_zfile",
                         &py_g, &meth, &path))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_zfile (g, meth, path);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == NULL) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

#ifdef HAVE_PYSTRING_ASSTRING
  py_r = PyString_FromString (r);
#else
  py_r = PyUnicode_FromString (r);
#endif
  free (r);
  if (py_r == NULL) goto out;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_ZGREP
static PyObject *
guestfs_int_py_zgrep (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  char **r;
  const char *regex;
  const char *path;

  if (!PyArg_ParseTuple (args, (char *) "Oss:guestfs_zgrep",
                         &py_g, &regex, &path))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_zgrep (g, regex, path);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == NULL) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  py_r = put_string_list (r);
  guestfs_int_free_string_list (r);

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_ZGREPI
static PyObject *
guestfs_int_py_zgrepi (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  char **r;
  const char *regex;
  const char *path;

  if (!PyArg_ParseTuple (args, (char *) "Oss:guestfs_zgrepi",
                         &py_g, &regex, &path))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_zgrepi (g, regex, path);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == NULL) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  py_r = put_string_list (r);
  guestfs_int_free_string_list (r);

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

static PyMethodDef methods[] = {
  { (char *) "create", guestfs_int_py_create, METH_VARARGS, NULL },
  { (char *) "close", guestfs_int_py_close, METH_VARARGS, NULL },
  { (char *) "set_event_callback",
    guestfs_int_py_set_event_callback, METH_VARARGS, NULL },
  { (char *) "delete_event_callback",
    guestfs_int_py_delete_event_callback, METH_VARARGS, NULL },
  { (char *) "event_to_string",
    guestfs_int_py_event_to_string, METH_VARARGS, NULL },
#ifdef GUESTFS_HAVE_ACL_DELETE_DEF_FILE
  { (char *) "acl_delete_def_file", guestfs_int_py_acl_delete_def_file, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_ACL_GET_FILE
  { (char *) "acl_get_file", guestfs_int_py_acl_get_file, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_ACL_SET_FILE
  { (char *) "acl_set_file", guestfs_int_py_acl_set_file, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_ADD_CDROM
  { (char *) "add_cdrom", guestfs_int_py_add_cdrom, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_ADD_DOMAIN
  { (char *) "add_domain", guestfs_int_py_add_domain, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_ADD_DRIVE_OPTS
  { (char *) "add_drive", guestfs_int_py_add_drive, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_ADD_DRIVE_RO
  { (char *) "add_drive_ro", guestfs_int_py_add_drive_ro, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_ADD_DRIVE_RO_WITH_IF
  { (char *) "add_drive_ro_with_if", guestfs_int_py_add_drive_ro_with_if, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_ADD_DRIVE_SCRATCH
  { (char *) "add_drive_scratch", guestfs_int_py_add_drive_scratch, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_ADD_DRIVE_WITH_IF
  { (char *) "add_drive_with_if", guestfs_int_py_add_drive_with_if, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_ADD_LIBVIRT_DOM
  { (char *) "add_libvirt_dom", guestfs_int_py_add_libvirt_dom, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_AUG_CLEAR
  { (char *) "aug_clear", guestfs_int_py_aug_clear, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_AUG_CLOSE
  { (char *) "aug_close", guestfs_int_py_aug_close, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_AUG_DEFNODE
  { (char *) "aug_defnode", guestfs_int_py_aug_defnode, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_AUG_DEFVAR
  { (char *) "aug_defvar", guestfs_int_py_aug_defvar, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_AUG_GET
  { (char *) "aug_get", guestfs_int_py_aug_get, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_AUG_INIT
  { (char *) "aug_init", guestfs_int_py_aug_init, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_AUG_INSERT
  { (char *) "aug_insert", guestfs_int_py_aug_insert, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_AUG_LABEL
  { (char *) "aug_label", guestfs_int_py_aug_label, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_AUG_LOAD
  { (char *) "aug_load", guestfs_int_py_aug_load, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_AUG_LS
  { (char *) "aug_ls", guestfs_int_py_aug_ls, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_AUG_MATCH
  { (char *) "aug_match", guestfs_int_py_aug_match, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_AUG_MV
  { (char *) "aug_mv", guestfs_int_py_aug_mv, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_AUG_RM
  { (char *) "aug_rm", guestfs_int_py_aug_rm, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_AUG_SAVE
  { (char *) "aug_save", guestfs_int_py_aug_save, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_AUG_SET
  { (char *) "aug_set", guestfs_int_py_aug_set, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_AUG_SETM
  { (char *) "aug_setm", guestfs_int_py_aug_setm, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_AVAILABLE
  { (char *) "available", guestfs_int_py_available, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_AVAILABLE_ALL_GROUPS
  { (char *) "available_all_groups", guestfs_int_py_available_all_groups, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_BASE64_IN
  { (char *) "base64_in", guestfs_int_py_base64_in, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_BASE64_OUT
  { (char *) "base64_out", guestfs_int_py_base64_out, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_BLKDISCARD
  { (char *) "blkdiscard", guestfs_int_py_blkdiscard, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_BLKDISCARDZEROES
  { (char *) "blkdiscardzeroes", guestfs_int_py_blkdiscardzeroes, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_BLKID
  { (char *) "blkid", guestfs_int_py_blkid, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_BLOCKDEV_FLUSHBUFS
  { (char *) "blockdev_flushbufs", guestfs_int_py_blockdev_flushbufs, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_BLOCKDEV_GETBSZ
  { (char *) "blockdev_getbsz", guestfs_int_py_blockdev_getbsz, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_BLOCKDEV_GETRO
  { (char *) "blockdev_getro", guestfs_int_py_blockdev_getro, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_BLOCKDEV_GETSIZE64
  { (char *) "blockdev_getsize64", guestfs_int_py_blockdev_getsize64, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_BLOCKDEV_GETSS
  { (char *) "blockdev_getss", guestfs_int_py_blockdev_getss, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_BLOCKDEV_GETSZ
  { (char *) "blockdev_getsz", guestfs_int_py_blockdev_getsz, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_BLOCKDEV_REREADPT
  { (char *) "blockdev_rereadpt", guestfs_int_py_blockdev_rereadpt, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_BLOCKDEV_SETBSZ
  { (char *) "blockdev_setbsz", guestfs_int_py_blockdev_setbsz, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_BLOCKDEV_SETRA
  { (char *) "blockdev_setra", guestfs_int_py_blockdev_setra, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_BLOCKDEV_SETRO
  { (char *) "blockdev_setro", guestfs_int_py_blockdev_setro, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_BLOCKDEV_SETRW
  { (char *) "blockdev_setrw", guestfs_int_py_blockdev_setrw, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_BTRFS_BALANCE_CANCEL
  { (char *) "btrfs_balance_cancel", guestfs_int_py_btrfs_balance_cancel, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_BTRFS_BALANCE_PAUSE
  { (char *) "btrfs_balance_pause", guestfs_int_py_btrfs_balance_pause, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_BTRFS_BALANCE_RESUME
  { (char *) "btrfs_balance_resume", guestfs_int_py_btrfs_balance_resume, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_BTRFS_BALANCE_STATUS
  { (char *) "btrfs_balance_status", guestfs_int_py_btrfs_balance_status, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_BTRFS_DEVICE_ADD
  { (char *) "btrfs_device_add", guestfs_int_py_btrfs_device_add, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_BTRFS_DEVICE_DELETE
  { (char *) "btrfs_device_delete", guestfs_int_py_btrfs_device_delete, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_BTRFS_FILESYSTEM_BALANCE
  { (char *) "btrfs_filesystem_balance", guestfs_int_py_btrfs_filesystem_balance, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_BTRFS_FILESYSTEM_DEFRAGMENT
  { (char *) "btrfs_filesystem_defragment", guestfs_int_py_btrfs_filesystem_defragment, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_BTRFS_FILESYSTEM_RESIZE
  { (char *) "btrfs_filesystem_resize", guestfs_int_py_btrfs_filesystem_resize, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_BTRFS_FILESYSTEM_SYNC
  { (char *) "btrfs_filesystem_sync", guestfs_int_py_btrfs_filesystem_sync, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_BTRFS_FSCK
  { (char *) "btrfs_fsck", guestfs_int_py_btrfs_fsck, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_BTRFS_IMAGE
  { (char *) "btrfs_image", guestfs_int_py_btrfs_image, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_BTRFS_QGROUP_ASSIGN
  { (char *) "btrfs_qgroup_assign", guestfs_int_py_btrfs_qgroup_assign, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_BTRFS_QGROUP_CREATE
  { (char *) "btrfs_qgroup_create", guestfs_int_py_btrfs_qgroup_create, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_BTRFS_QGROUP_DESTROY
  { (char *) "btrfs_qgroup_destroy", guestfs_int_py_btrfs_qgroup_destroy, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_BTRFS_QGROUP_LIMIT
  { (char *) "btrfs_qgroup_limit", guestfs_int_py_btrfs_qgroup_limit, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_BTRFS_QGROUP_REMOVE
  { (char *) "btrfs_qgroup_remove", guestfs_int_py_btrfs_qgroup_remove, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_BTRFS_QGROUP_SHOW
  { (char *) "btrfs_qgroup_show", guestfs_int_py_btrfs_qgroup_show, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_BTRFS_QUOTA_ENABLE
  { (char *) "btrfs_quota_enable", guestfs_int_py_btrfs_quota_enable, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_BTRFS_QUOTA_RESCAN
  { (char *) "btrfs_quota_rescan", guestfs_int_py_btrfs_quota_rescan, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_BTRFS_REPLACE
  { (char *) "btrfs_replace", guestfs_int_py_btrfs_replace, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_BTRFS_RESCUE_CHUNK_RECOVER
  { (char *) "btrfs_rescue_chunk_recover", guestfs_int_py_btrfs_rescue_chunk_recover, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_BTRFS_RESCUE_SUPER_RECOVER
  { (char *) "btrfs_rescue_super_recover", guestfs_int_py_btrfs_rescue_super_recover, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_BTRFS_SCRUB_CANCEL
  { (char *) "btrfs_scrub_cancel", guestfs_int_py_btrfs_scrub_cancel, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_BTRFS_SCRUB_RESUME
  { (char *) "btrfs_scrub_resume", guestfs_int_py_btrfs_scrub_resume, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_BTRFS_SCRUB_START
  { (char *) "btrfs_scrub_start", guestfs_int_py_btrfs_scrub_start, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_BTRFS_SCRUB_STATUS
  { (char *) "btrfs_scrub_status", guestfs_int_py_btrfs_scrub_status, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_BTRFS_SET_SEEDING
  { (char *) "btrfs_set_seeding", guestfs_int_py_btrfs_set_seeding, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_BTRFS_SUBVOLUME_CREATE_OPTS
  { (char *) "btrfs_subvolume_create", guestfs_int_py_btrfs_subvolume_create, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_BTRFS_SUBVOLUME_DELETE
  { (char *) "btrfs_subvolume_delete", guestfs_int_py_btrfs_subvolume_delete, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_BTRFS_SUBVOLUME_GET_DEFAULT
  { (char *) "btrfs_subvolume_get_default", guestfs_int_py_btrfs_subvolume_get_default, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_BTRFS_SUBVOLUME_LIST
  { (char *) "btrfs_subvolume_list", guestfs_int_py_btrfs_subvolume_list, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_BTRFS_SUBVOLUME_SET_DEFAULT
  { (char *) "btrfs_subvolume_set_default", guestfs_int_py_btrfs_subvolume_set_default, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_BTRFS_SUBVOLUME_SHOW
  { (char *) "btrfs_subvolume_show", guestfs_int_py_btrfs_subvolume_show, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_BTRFS_SUBVOLUME_SNAPSHOT_OPTS
  { (char *) "btrfs_subvolume_snapshot", guestfs_int_py_btrfs_subvolume_snapshot, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_BTRFSTUNE_ENABLE_EXTENDED_INODE_REFS
  { (char *) "btrfstune_enable_extended_inode_refs", guestfs_int_py_btrfstune_enable_extended_inode_refs, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_BTRFSTUNE_ENABLE_SKINNY_METADATA_EXTENT_REFS
  { (char *) "btrfstune_enable_skinny_metadata_extent_refs", guestfs_int_py_btrfstune_enable_skinny_metadata_extent_refs, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_BTRFSTUNE_SEEDING
  { (char *) "btrfstune_seeding", guestfs_int_py_btrfstune_seeding, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_C_POINTER
  { (char *) "c_pointer", guestfs_int_py_c_pointer, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_CANONICAL_DEVICE_NAME
  { (char *) "canonical_device_name", guestfs_int_py_canonical_device_name, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_CAP_GET_FILE
  { (char *) "cap_get_file", guestfs_int_py_cap_get_file, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_CAP_SET_FILE
  { (char *) "cap_set_file", guestfs_int_py_cap_set_file, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_CASE_SENSITIVE_PATH
  { (char *) "case_sensitive_path", guestfs_int_py_case_sensitive_path, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_CAT
  { (char *) "cat", guestfs_int_py_cat, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_CHECKSUM
  { (char *) "checksum", guestfs_int_py_checksum, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_CHECKSUM_DEVICE
  { (char *) "checksum_device", guestfs_int_py_checksum_device, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_CHECKSUMS_OUT
  { (char *) "checksums_out", guestfs_int_py_checksums_out, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_CHMOD
  { (char *) "chmod", guestfs_int_py_chmod, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_CHOWN
  { (char *) "chown", guestfs_int_py_chown, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_CLEAR_BACKEND_SETTING
  { (char *) "clear_backend_setting", guestfs_int_py_clear_backend_setting, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_COMMAND
  { (char *) "command", guestfs_int_py_command, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_COMMAND_LINES
  { (char *) "command_lines", guestfs_int_py_command_lines, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_COMPRESS_DEVICE_OUT
  { (char *) "compress_device_out", guestfs_int_py_compress_device_out, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_COMPRESS_OUT
  { (char *) "compress_out", guestfs_int_py_compress_out, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_CONFIG
  { (char *) "config", guestfs_int_py_config, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_COPY_ATTRIBUTES
  { (char *) "copy_attributes", guestfs_int_py_copy_attributes, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_COPY_DEVICE_TO_DEVICE
  { (char *) "copy_device_to_device", guestfs_int_py_copy_device_to_device, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_COPY_DEVICE_TO_FILE
  { (char *) "copy_device_to_file", guestfs_int_py_copy_device_to_file, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_COPY_FILE_TO_DEVICE
  { (char *) "copy_file_to_device", guestfs_int_py_copy_file_to_device, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_COPY_FILE_TO_FILE
  { (char *) "copy_file_to_file", guestfs_int_py_copy_file_to_file, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_COPY_IN
  { (char *) "copy_in", guestfs_int_py_copy_in, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_COPY_OUT
  { (char *) "copy_out", guestfs_int_py_copy_out, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_COPY_SIZE
  { (char *) "copy_size", guestfs_int_py_copy_size, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_CP
  { (char *) "cp", guestfs_int_py_cp, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_CP_A
  { (char *) "cp_a", guestfs_int_py_cp_a, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_CP_R
  { (char *) "cp_r", guestfs_int_py_cp_r, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_CPIO_OUT
  { (char *) "cpio_out", guestfs_int_py_cpio_out, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_DD
  { (char *) "dd", guestfs_int_py_dd, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_DEBUG
  { (char *) "debug", guestfs_int_py_debug, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_DEBUG_DRIVES
  { (char *) "debug_drives", guestfs_int_py_debug_drives, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_DEBUG_UPLOAD
  { (char *) "debug_upload", guestfs_int_py_debug_upload, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_DEVICE_INDEX
  { (char *) "device_index", guestfs_int_py_device_index, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_DF
  { (char *) "df", guestfs_int_py_df, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_DF_H
  { (char *) "df_h", guestfs_int_py_df_h, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_DISK_CREATE
  { (char *) "disk_create", guestfs_int_py_disk_create, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_DISK_FORMAT
  { (char *) "disk_format", guestfs_int_py_disk_format, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_DISK_HAS_BACKING_FILE
  { (char *) "disk_has_backing_file", guestfs_int_py_disk_has_backing_file, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_DISK_VIRTUAL_SIZE
  { (char *) "disk_virtual_size", guestfs_int_py_disk_virtual_size, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_DMESG
  { (char *) "dmesg", guestfs_int_py_dmesg, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_DOWNLOAD
  { (char *) "download", guestfs_int_py_download, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_DOWNLOAD_OFFSET
  { (char *) "download_offset", guestfs_int_py_download_offset, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_DROP_CACHES
  { (char *) "drop_caches", guestfs_int_py_drop_caches, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_DU
  { (char *) "du", guestfs_int_py_du, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_E2FSCK
  { (char *) "e2fsck", guestfs_int_py_e2fsck, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_E2FSCK_F
  { (char *) "e2fsck_f", guestfs_int_py_e2fsck_f, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_ECHO_DAEMON
  { (char *) "echo_daemon", guestfs_int_py_echo_daemon, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_EGREP
  { (char *) "egrep", guestfs_int_py_egrep, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_EGREPI
  { (char *) "egrepi", guestfs_int_py_egrepi, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_EQUAL
  { (char *) "equal", guestfs_int_py_equal, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_EXISTS
  { (char *) "exists", guestfs_int_py_exists, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_EXTLINUX
  { (char *) "extlinux", guestfs_int_py_extlinux, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_FALLOCATE
  { (char *) "fallocate", guestfs_int_py_fallocate, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_FALLOCATE64
  { (char *) "fallocate64", guestfs_int_py_fallocate64, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_FEATURE_AVAILABLE
  { (char *) "feature_available", guestfs_int_py_feature_available, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_FGREP
  { (char *) "fgrep", guestfs_int_py_fgrep, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_FGREPI
  { (char *) "fgrepi", guestfs_int_py_fgrepi, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_FILE
  { (char *) "file", guestfs_int_py_file, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_FILE_ARCHITECTURE
  { (char *) "file_architecture", guestfs_int_py_file_architecture, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_FILESIZE
  { (char *) "filesize", guestfs_int_py_filesize, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_FILESYSTEM_AVAILABLE
  { (char *) "filesystem_available", guestfs_int_py_filesystem_available, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_FILL
  { (char *) "fill", guestfs_int_py_fill, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_FILL_DIR
  { (char *) "fill_dir", guestfs_int_py_fill_dir, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_FILL_PATTERN
  { (char *) "fill_pattern", guestfs_int_py_fill_pattern, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_FIND
  { (char *) "find", guestfs_int_py_find, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_FIND0
  { (char *) "find0", guestfs_int_py_find0, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_FINDFS_LABEL
  { (char *) "findfs_label", guestfs_int_py_findfs_label, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_FINDFS_UUID
  { (char *) "findfs_uuid", guestfs_int_py_findfs_uuid, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_FSCK
  { (char *) "fsck", guestfs_int_py_fsck, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_FSTRIM
  { (char *) "fstrim", guestfs_int_py_fstrim, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_GET_APPEND
  { (char *) "get_append", guestfs_int_py_get_append, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_GET_ATTACH_METHOD
  { (char *) "get_attach_method", guestfs_int_py_get_attach_method, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_GET_AUTOSYNC
  { (char *) "get_autosync", guestfs_int_py_get_autosync, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_GET_BACKEND
  { (char *) "get_backend", guestfs_int_py_get_backend, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_GET_BACKEND_SETTING
  { (char *) "get_backend_setting", guestfs_int_py_get_backend_setting, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_GET_BACKEND_SETTINGS
  { (char *) "get_backend_settings", guestfs_int_py_get_backend_settings, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_GET_CACHEDIR
  { (char *) "get_cachedir", guestfs_int_py_get_cachedir, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_GET_DIRECT
  { (char *) "get_direct", guestfs_int_py_get_direct, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_GET_E2ATTRS
  { (char *) "get_e2attrs", guestfs_int_py_get_e2attrs, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_GET_E2GENERATION
  { (char *) "get_e2generation", guestfs_int_py_get_e2generation, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_GET_E2LABEL
  { (char *) "get_e2label", guestfs_int_py_get_e2label, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_GET_E2UUID
  { (char *) "get_e2uuid", guestfs_int_py_get_e2uuid, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_GET_HV
  { (char *) "get_hv", guestfs_int_py_get_hv, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_GET_IDENTIFIER
  { (char *) "get_identifier", guestfs_int_py_get_identifier, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_GET_LIBVIRT_REQUESTED_CREDENTIAL_CHALLENGE
  { (char *) "get_libvirt_requested_credential_challenge", guestfs_int_py_get_libvirt_requested_credential_challenge, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_GET_LIBVIRT_REQUESTED_CREDENTIAL_DEFRESULT
  { (char *) "get_libvirt_requested_credential_defresult", guestfs_int_py_get_libvirt_requested_credential_defresult, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_GET_LIBVIRT_REQUESTED_CREDENTIAL_PROMPT
  { (char *) "get_libvirt_requested_credential_prompt", guestfs_int_py_get_libvirt_requested_credential_prompt, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_GET_LIBVIRT_REQUESTED_CREDENTIALS
  { (char *) "get_libvirt_requested_credentials", guestfs_int_py_get_libvirt_requested_credentials, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_GET_MEMSIZE
  { (char *) "get_memsize", guestfs_int_py_get_memsize, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_GET_NETWORK
  { (char *) "get_network", guestfs_int_py_get_network, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_GET_PATH
  { (char *) "get_path", guestfs_int_py_get_path, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_GET_PGROUP
  { (char *) "get_pgroup", guestfs_int_py_get_pgroup, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_GET_PID
  { (char *) "get_pid", guestfs_int_py_get_pid, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_GET_PROGRAM
  { (char *) "get_program", guestfs_int_py_get_program, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_GET_QEMU
  { (char *) "get_qemu", guestfs_int_py_get_qemu, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_GET_RECOVERY_PROC
  { (char *) "get_recovery_proc", guestfs_int_py_get_recovery_proc, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_GET_SELINUX
  { (char *) "get_selinux", guestfs_int_py_get_selinux, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_GET_SMP
  { (char *) "get_smp", guestfs_int_py_get_smp, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_GET_STATE
  { (char *) "get_state", guestfs_int_py_get_state, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_GET_TMPDIR
  { (char *) "get_tmpdir", guestfs_int_py_get_tmpdir, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_GET_TRACE
  { (char *) "get_trace", guestfs_int_py_get_trace, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_GET_UMASK
  { (char *) "get_umask", guestfs_int_py_get_umask, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_GET_VERBOSE
  { (char *) "get_verbose", guestfs_int_py_get_verbose, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_GETCON
  { (char *) "getcon", guestfs_int_py_getcon, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_GETXATTR
  { (char *) "getxattr", guestfs_int_py_getxattr, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_GETXATTRS
  { (char *) "getxattrs", guestfs_int_py_getxattrs, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_GLOB_EXPAND
  { (char *) "glob_expand", guestfs_int_py_glob_expand, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_GREP_OPTS
  { (char *) "grep", guestfs_int_py_grep, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_GREPI
  { (char *) "grepi", guestfs_int_py_grepi, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_GRUB_INSTALL
  { (char *) "grub_install", guestfs_int_py_grub_install, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_HEAD
  { (char *) "head", guestfs_int_py_head, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_HEAD_N
  { (char *) "head_n", guestfs_int_py_head_n, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_HEXDUMP
  { (char *) "hexdump", guestfs_int_py_hexdump, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_HIVEX_CLOSE
  { (char *) "hivex_close", guestfs_int_py_hivex_close, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_HIVEX_COMMIT
  { (char *) "hivex_commit", guestfs_int_py_hivex_commit, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_HIVEX_NODE_ADD_CHILD
  { (char *) "hivex_node_add_child", guestfs_int_py_hivex_node_add_child, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_HIVEX_NODE_CHILDREN
  { (char *) "hivex_node_children", guestfs_int_py_hivex_node_children, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_HIVEX_NODE_DELETE_CHILD
  { (char *) "hivex_node_delete_child", guestfs_int_py_hivex_node_delete_child, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_HIVEX_NODE_GET_CHILD
  { (char *) "hivex_node_get_child", guestfs_int_py_hivex_node_get_child, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_HIVEX_NODE_GET_VALUE
  { (char *) "hivex_node_get_value", guestfs_int_py_hivex_node_get_value, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_HIVEX_NODE_NAME
  { (char *) "hivex_node_name", guestfs_int_py_hivex_node_name, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_HIVEX_NODE_PARENT
  { (char *) "hivex_node_parent", guestfs_int_py_hivex_node_parent, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_HIVEX_NODE_SET_VALUE
  { (char *) "hivex_node_set_value", guestfs_int_py_hivex_node_set_value, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_HIVEX_NODE_VALUES
  { (char *) "hivex_node_values", guestfs_int_py_hivex_node_values, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_HIVEX_OPEN
  { (char *) "hivex_open", guestfs_int_py_hivex_open, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_HIVEX_ROOT
  { (char *) "hivex_root", guestfs_int_py_hivex_root, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_HIVEX_VALUE_KEY
  { (char *) "hivex_value_key", guestfs_int_py_hivex_value_key, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_HIVEX_VALUE_TYPE
  { (char *) "hivex_value_type", guestfs_int_py_hivex_value_type, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_HIVEX_VALUE_UTF8
  { (char *) "hivex_value_utf8", guestfs_int_py_hivex_value_utf8, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_HIVEX_VALUE_VALUE
  { (char *) "hivex_value_value", guestfs_int_py_hivex_value_value, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_INITRD_CAT
  { (char *) "initrd_cat", guestfs_int_py_initrd_cat, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_INITRD_LIST
  { (char *) "initrd_list", guestfs_int_py_initrd_list, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_INOTIFY_ADD_WATCH
  { (char *) "inotify_add_watch", guestfs_int_py_inotify_add_watch, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_INOTIFY_CLOSE
  { (char *) "inotify_close", guestfs_int_py_inotify_close, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_INOTIFY_FILES
  { (char *) "inotify_files", guestfs_int_py_inotify_files, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_INOTIFY_INIT
  { (char *) "inotify_init", guestfs_int_py_inotify_init, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_INOTIFY_READ
  { (char *) "inotify_read", guestfs_int_py_inotify_read, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_INOTIFY_RM_WATCH
  { (char *) "inotify_rm_watch", guestfs_int_py_inotify_rm_watch, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_INSPECT_GET_ARCH
  { (char *) "inspect_get_arch", guestfs_int_py_inspect_get_arch, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_INSPECT_GET_DISTRO
  { (char *) "inspect_get_distro", guestfs_int_py_inspect_get_distro, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_INSPECT_GET_DRIVE_MAPPINGS
  { (char *) "inspect_get_drive_mappings", guestfs_int_py_inspect_get_drive_mappings, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_INSPECT_GET_FILESYSTEMS
  { (char *) "inspect_get_filesystems", guestfs_int_py_inspect_get_filesystems, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_INSPECT_GET_FORMAT
  { (char *) "inspect_get_format", guestfs_int_py_inspect_get_format, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_INSPECT_GET_HOSTNAME
  { (char *) "inspect_get_hostname", guestfs_int_py_inspect_get_hostname, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_INSPECT_GET_ICON
  { (char *) "inspect_get_icon", guestfs_int_py_inspect_get_icon, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_INSPECT_GET_MAJOR_VERSION
  { (char *) "inspect_get_major_version", guestfs_int_py_inspect_get_major_version, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_INSPECT_GET_MINOR_VERSION
  { (char *) "inspect_get_minor_version", guestfs_int_py_inspect_get_minor_version, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_INSPECT_GET_MOUNTPOINTS
  { (char *) "inspect_get_mountpoints", guestfs_int_py_inspect_get_mountpoints, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_INSPECT_GET_PACKAGE_FORMAT
  { (char *) "inspect_get_package_format", guestfs_int_py_inspect_get_package_format, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_INSPECT_GET_PACKAGE_MANAGEMENT
  { (char *) "inspect_get_package_management", guestfs_int_py_inspect_get_package_management, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_INSPECT_GET_PRODUCT_NAME
  { (char *) "inspect_get_product_name", guestfs_int_py_inspect_get_product_name, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_INSPECT_GET_PRODUCT_VARIANT
  { (char *) "inspect_get_product_variant", guestfs_int_py_inspect_get_product_variant, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_INSPECT_GET_ROOTS
  { (char *) "inspect_get_roots", guestfs_int_py_inspect_get_roots, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_INSPECT_GET_TYPE
  { (char *) "inspect_get_type", guestfs_int_py_inspect_get_type, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_INSPECT_GET_WINDOWS_CURRENT_CONTROL_SET
  { (char *) "inspect_get_windows_current_control_set", guestfs_int_py_inspect_get_windows_current_control_set, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_INSPECT_GET_WINDOWS_SYSTEMROOT
  { (char *) "inspect_get_windows_systemroot", guestfs_int_py_inspect_get_windows_systemroot, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_INSPECT_IS_LIVE
  { (char *) "inspect_is_live", guestfs_int_py_inspect_is_live, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_INSPECT_IS_MULTIPART
  { (char *) "inspect_is_multipart", guestfs_int_py_inspect_is_multipart, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_INSPECT_IS_NETINST
  { (char *) "inspect_is_netinst", guestfs_int_py_inspect_is_netinst, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_INSPECT_LIST_APPLICATIONS
  { (char *) "inspect_list_applications", guestfs_int_py_inspect_list_applications, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_INSPECT_LIST_APPLICATIONS2
  { (char *) "inspect_list_applications2", guestfs_int_py_inspect_list_applications2, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_INSPECT_OS
  { (char *) "inspect_os", guestfs_int_py_inspect_os, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_INTERNAL_EXIT
  { (char *) "internal_exit", guestfs_int_py_internal_exit, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_INTERNAL_TEST
  { (char *) "internal_test", guestfs_int_py_internal_test, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_INTERNAL_TEST_63_OPTARGS
  { (char *) "internal_test_63_optargs", guestfs_int_py_internal_test_63_optargs, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_INTERNAL_TEST_CLOSE_OUTPUT
  { (char *) "internal_test_close_output", guestfs_int_py_internal_test_close_output, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_INTERNAL_TEST_ONLY_OPTARGS
  { (char *) "internal_test_only_optargs", guestfs_int_py_internal_test_only_optargs, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_INTERNAL_TEST_RBOOL
  { (char *) "internal_test_rbool", guestfs_int_py_internal_test_rbool, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_INTERNAL_TEST_RBOOLERR
  { (char *) "internal_test_rboolerr", guestfs_int_py_internal_test_rboolerr, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_INTERNAL_TEST_RBUFFEROUT
  { (char *) "internal_test_rbufferout", guestfs_int_py_internal_test_rbufferout, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_INTERNAL_TEST_RBUFFEROUTERR
  { (char *) "internal_test_rbufferouterr", guestfs_int_py_internal_test_rbufferouterr, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_INTERNAL_TEST_RCONSTOPTSTRING
  { (char *) "internal_test_rconstoptstring", guestfs_int_py_internal_test_rconstoptstring, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_INTERNAL_TEST_RCONSTOPTSTRINGERR
  { (char *) "internal_test_rconstoptstringerr", guestfs_int_py_internal_test_rconstoptstringerr, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_INTERNAL_TEST_RCONSTSTRING
  { (char *) "internal_test_rconststring", guestfs_int_py_internal_test_rconststring, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_INTERNAL_TEST_RCONSTSTRINGERR
  { (char *) "internal_test_rconststringerr", guestfs_int_py_internal_test_rconststringerr, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_INTERNAL_TEST_RHASHTABLE
  { (char *) "internal_test_rhashtable", guestfs_int_py_internal_test_rhashtable, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_INTERNAL_TEST_RHASHTABLEERR
  { (char *) "internal_test_rhashtableerr", guestfs_int_py_internal_test_rhashtableerr, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_INTERNAL_TEST_RINT
  { (char *) "internal_test_rint", guestfs_int_py_internal_test_rint, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_INTERNAL_TEST_RINT64
  { (char *) "internal_test_rint64", guestfs_int_py_internal_test_rint64, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_INTERNAL_TEST_RINT64ERR
  { (char *) "internal_test_rint64err", guestfs_int_py_internal_test_rint64err, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_INTERNAL_TEST_RINTERR
  { (char *) "internal_test_rinterr", guestfs_int_py_internal_test_rinterr, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_INTERNAL_TEST_RSTRING
  { (char *) "internal_test_rstring", guestfs_int_py_internal_test_rstring, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_INTERNAL_TEST_RSTRINGERR
  { (char *) "internal_test_rstringerr", guestfs_int_py_internal_test_rstringerr, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_INTERNAL_TEST_RSTRINGLIST
  { (char *) "internal_test_rstringlist", guestfs_int_py_internal_test_rstringlist, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_INTERNAL_TEST_RSTRINGLISTERR
  { (char *) "internal_test_rstringlisterr", guestfs_int_py_internal_test_rstringlisterr, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_INTERNAL_TEST_RSTRUCT
  { (char *) "internal_test_rstruct", guestfs_int_py_internal_test_rstruct, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_INTERNAL_TEST_RSTRUCTERR
  { (char *) "internal_test_rstructerr", guestfs_int_py_internal_test_rstructerr, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_INTERNAL_TEST_RSTRUCTLIST
  { (char *) "internal_test_rstructlist", guestfs_int_py_internal_test_rstructlist, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_INTERNAL_TEST_RSTRUCTLISTERR
  { (char *) "internal_test_rstructlisterr", guestfs_int_py_internal_test_rstructlisterr, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_INTERNAL_TEST_SET_OUTPUT
  { (char *) "internal_test_set_output", guestfs_int_py_internal_test_set_output, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_IS_BLOCKDEV_OPTS
  { (char *) "is_blockdev", guestfs_int_py_is_blockdev, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_IS_BUSY
  { (char *) "is_busy", guestfs_int_py_is_busy, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_IS_CHARDEV_OPTS
  { (char *) "is_chardev", guestfs_int_py_is_chardev, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_IS_CONFIG
  { (char *) "is_config", guestfs_int_py_is_config, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_IS_DIR_OPTS
  { (char *) "is_dir", guestfs_int_py_is_dir, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_IS_FIFO_OPTS
  { (char *) "is_fifo", guestfs_int_py_is_fifo, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_IS_FILE_OPTS
  { (char *) "is_file", guestfs_int_py_is_file, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_IS_LAUNCHING
  { (char *) "is_launching", guestfs_int_py_is_launching, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_IS_LV
  { (char *) "is_lv", guestfs_int_py_is_lv, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_IS_READY
  { (char *) "is_ready", guestfs_int_py_is_ready, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_IS_SOCKET_OPTS
  { (char *) "is_socket", guestfs_int_py_is_socket, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_IS_SYMLINK
  { (char *) "is_symlink", guestfs_int_py_is_symlink, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_IS_WHOLE_DEVICE
  { (char *) "is_whole_device", guestfs_int_py_is_whole_device, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_IS_ZERO
  { (char *) "is_zero", guestfs_int_py_is_zero, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_IS_ZERO_DEVICE
  { (char *) "is_zero_device", guestfs_int_py_is_zero_device, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_ISOINFO
  { (char *) "isoinfo", guestfs_int_py_isoinfo, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_ISOINFO_DEVICE
  { (char *) "isoinfo_device", guestfs_int_py_isoinfo_device, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_JOURNAL_CLOSE
  { (char *) "journal_close", guestfs_int_py_journal_close, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_JOURNAL_GET
  { (char *) "journal_get", guestfs_int_py_journal_get, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_JOURNAL_GET_DATA_THRESHOLD
  { (char *) "journal_get_data_threshold", guestfs_int_py_journal_get_data_threshold, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_JOURNAL_GET_REALTIME_USEC
  { (char *) "journal_get_realtime_usec", guestfs_int_py_journal_get_realtime_usec, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_JOURNAL_NEXT
  { (char *) "journal_next", guestfs_int_py_journal_next, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_JOURNAL_OPEN
  { (char *) "journal_open", guestfs_int_py_journal_open, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_JOURNAL_SET_DATA_THRESHOLD
  { (char *) "journal_set_data_threshold", guestfs_int_py_journal_set_data_threshold, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_JOURNAL_SKIP
  { (char *) "journal_skip", guestfs_int_py_journal_skip, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_KILL_SUBPROCESS
  { (char *) "kill_subprocess", guestfs_int_py_kill_subprocess, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_LAUNCH
  { (char *) "launch", guestfs_int_py_launch, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_LCHOWN
  { (char *) "lchown", guestfs_int_py_lchown, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_LDMTOOL_CREATE_ALL
  { (char *) "ldmtool_create_all", guestfs_int_py_ldmtool_create_all, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_LDMTOOL_DISKGROUP_DISKS
  { (char *) "ldmtool_diskgroup_disks", guestfs_int_py_ldmtool_diskgroup_disks, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_LDMTOOL_DISKGROUP_NAME
  { (char *) "ldmtool_diskgroup_name", guestfs_int_py_ldmtool_diskgroup_name, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_LDMTOOL_DISKGROUP_VOLUMES
  { (char *) "ldmtool_diskgroup_volumes", guestfs_int_py_ldmtool_diskgroup_volumes, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_LDMTOOL_REMOVE_ALL
  { (char *) "ldmtool_remove_all", guestfs_int_py_ldmtool_remove_all, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_LDMTOOL_SCAN
  { (char *) "ldmtool_scan", guestfs_int_py_ldmtool_scan, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_LDMTOOL_SCAN_DEVICES
  { (char *) "ldmtool_scan_devices", guestfs_int_py_ldmtool_scan_devices, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_LDMTOOL_VOLUME_HINT
  { (char *) "ldmtool_volume_hint", guestfs_int_py_ldmtool_volume_hint, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_LDMTOOL_VOLUME_PARTITIONS
  { (char *) "ldmtool_volume_partitions", guestfs_int_py_ldmtool_volume_partitions, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_LDMTOOL_VOLUME_TYPE
  { (char *) "ldmtool_volume_type", guestfs_int_py_ldmtool_volume_type, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_LGETXATTR
  { (char *) "lgetxattr", guestfs_int_py_lgetxattr, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_LGETXATTRS
  { (char *) "lgetxattrs", guestfs_int_py_lgetxattrs, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_LIST_9P
  { (char *) "list_9p", guestfs_int_py_list_9p, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_LIST_DEVICES
  { (char *) "list_devices", guestfs_int_py_list_devices, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_LIST_DISK_LABELS
  { (char *) "list_disk_labels", guestfs_int_py_list_disk_labels, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_LIST_DM_DEVICES
  { (char *) "list_dm_devices", guestfs_int_py_list_dm_devices, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_LIST_FILESYSTEMS
  { (char *) "list_filesystems", guestfs_int_py_list_filesystems, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_LIST_LDM_PARTITIONS
  { (char *) "list_ldm_partitions", guestfs_int_py_list_ldm_partitions, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_LIST_LDM_VOLUMES
  { (char *) "list_ldm_volumes", guestfs_int_py_list_ldm_volumes, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_LIST_MD_DEVICES
  { (char *) "list_md_devices", guestfs_int_py_list_md_devices, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_LIST_PARTITIONS
  { (char *) "list_partitions", guestfs_int_py_list_partitions, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_LL
  { (char *) "ll", guestfs_int_py_ll, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_LLZ
  { (char *) "llz", guestfs_int_py_llz, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_LN
  { (char *) "ln", guestfs_int_py_ln, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_LN_F
  { (char *) "ln_f", guestfs_int_py_ln_f, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_LN_S
  { (char *) "ln_s", guestfs_int_py_ln_s, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_LN_SF
  { (char *) "ln_sf", guestfs_int_py_ln_sf, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_LREMOVEXATTR
  { (char *) "lremovexattr", guestfs_int_py_lremovexattr, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_LS
  { (char *) "ls", guestfs_int_py_ls, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_LS0
  { (char *) "ls0", guestfs_int_py_ls0, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_LSETXATTR
  { (char *) "lsetxattr", guestfs_int_py_lsetxattr, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_LSTAT
  { (char *) "lstat", guestfs_int_py_lstat, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_LSTATLIST
  { (char *) "lstatlist", guestfs_int_py_lstatlist, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_LSTATNS
  { (char *) "lstatns", guestfs_int_py_lstatns, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_LSTATNSLIST
  { (char *) "lstatnslist", guestfs_int_py_lstatnslist, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_LUKS_ADD_KEY
  { (char *) "luks_add_key", guestfs_int_py_luks_add_key, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_LUKS_CLOSE
  { (char *) "luks_close", guestfs_int_py_luks_close, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_LUKS_FORMAT
  { (char *) "luks_format", guestfs_int_py_luks_format, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_LUKS_FORMAT_CIPHER
  { (char *) "luks_format_cipher", guestfs_int_py_luks_format_cipher, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_LUKS_KILL_SLOT
  { (char *) "luks_kill_slot", guestfs_int_py_luks_kill_slot, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_LUKS_OPEN
  { (char *) "luks_open", guestfs_int_py_luks_open, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_LUKS_OPEN_RO
  { (char *) "luks_open_ro", guestfs_int_py_luks_open_ro, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_LVCREATE
  { (char *) "lvcreate", guestfs_int_py_lvcreate, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_LVCREATE_FREE
  { (char *) "lvcreate_free", guestfs_int_py_lvcreate_free, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_LVM_CANONICAL_LV_NAME
  { (char *) "lvm_canonical_lv_name", guestfs_int_py_lvm_canonical_lv_name, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_LVM_CLEAR_FILTER
  { (char *) "lvm_clear_filter", guestfs_int_py_lvm_clear_filter, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_LVM_REMOVE_ALL
  { (char *) "lvm_remove_all", guestfs_int_py_lvm_remove_all, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_LVM_SET_FILTER
  { (char *) "lvm_set_filter", guestfs_int_py_lvm_set_filter, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_LVREMOVE
  { (char *) "lvremove", guestfs_int_py_lvremove, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_LVRENAME
  { (char *) "lvrename", guestfs_int_py_lvrename, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_LVRESIZE
  { (char *) "lvresize", guestfs_int_py_lvresize, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_LVRESIZE_FREE
  { (char *) "lvresize_free", guestfs_int_py_lvresize_free, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_LVS
  { (char *) "lvs", guestfs_int_py_lvs, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_LVS_FULL
  { (char *) "lvs_full", guestfs_int_py_lvs_full, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_LVUUID
  { (char *) "lvuuid", guestfs_int_py_lvuuid, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_LXATTRLIST
  { (char *) "lxattrlist", guestfs_int_py_lxattrlist, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_MAX_DISKS
  { (char *) "max_disks", guestfs_int_py_max_disks, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_MD_CREATE
  { (char *) "md_create", guestfs_int_py_md_create, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_MD_DETAIL
  { (char *) "md_detail", guestfs_int_py_md_detail, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_MD_STAT
  { (char *) "md_stat", guestfs_int_py_md_stat, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_MD_STOP
  { (char *) "md_stop", guestfs_int_py_md_stop, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_MKDIR
  { (char *) "mkdir", guestfs_int_py_mkdir, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_MKDIR_MODE
  { (char *) "mkdir_mode", guestfs_int_py_mkdir_mode, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_MKDIR_P
  { (char *) "mkdir_p", guestfs_int_py_mkdir_p, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_MKDTEMP
  { (char *) "mkdtemp", guestfs_int_py_mkdtemp, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_MKE2FS
  { (char *) "mke2fs", guestfs_int_py_mke2fs, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_MKE2FS_J
  { (char *) "mke2fs_J", guestfs_int_py_mke2fs_J, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_MKE2FS_JL
  { (char *) "mke2fs_JL", guestfs_int_py_mke2fs_JL, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_MKE2FS_JU
  { (char *) "mke2fs_JU", guestfs_int_py_mke2fs_JU, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_MKE2JOURNAL
  { (char *) "mke2journal", guestfs_int_py_mke2journal, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_MKE2JOURNAL_L
  { (char *) "mke2journal_L", guestfs_int_py_mke2journal_L, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_MKE2JOURNAL_U
  { (char *) "mke2journal_U", guestfs_int_py_mke2journal_U, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_MKFIFO
  { (char *) "mkfifo", guestfs_int_py_mkfifo, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_MKFS_OPTS
  { (char *) "mkfs", guestfs_int_py_mkfs, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_MKFS_B
  { (char *) "mkfs_b", guestfs_int_py_mkfs_b, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_MKFS_BTRFS
  { (char *) "mkfs_btrfs", guestfs_int_py_mkfs_btrfs, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_MKLOST_AND_FOUND
  { (char *) "mklost_and_found", guestfs_int_py_mklost_and_found, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_MKMOUNTPOINT
  { (char *) "mkmountpoint", guestfs_int_py_mkmountpoint, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_MKNOD
  { (char *) "mknod", guestfs_int_py_mknod, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_MKNOD_B
  { (char *) "mknod_b", guestfs_int_py_mknod_b, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_MKNOD_C
  { (char *) "mknod_c", guestfs_int_py_mknod_c, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_MKSWAP_OPTS
  { (char *) "mkswap", guestfs_int_py_mkswap, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_MKSWAP_L
  { (char *) "mkswap_L", guestfs_int_py_mkswap_L, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_MKSWAP_U
  { (char *) "mkswap_U", guestfs_int_py_mkswap_U, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_MKSWAP_FILE
  { (char *) "mkswap_file", guestfs_int_py_mkswap_file, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_MKTEMP
  { (char *) "mktemp", guestfs_int_py_mktemp, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_MODPROBE
  { (char *) "modprobe", guestfs_int_py_modprobe, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_MOUNT
  { (char *) "mount", guestfs_int_py_mount, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_MOUNT_9P
  { (char *) "mount_9p", guestfs_int_py_mount_9p, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_MOUNT_LOCAL
  { (char *) "mount_local", guestfs_int_py_mount_local, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_MOUNT_LOCAL_RUN
  { (char *) "mount_local_run", guestfs_int_py_mount_local_run, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_MOUNT_LOOP
  { (char *) "mount_loop", guestfs_int_py_mount_loop, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_MOUNT_OPTIONS
  { (char *) "mount_options", guestfs_int_py_mount_options, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_MOUNT_RO
  { (char *) "mount_ro", guestfs_int_py_mount_ro, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_MOUNT_VFS
  { (char *) "mount_vfs", guestfs_int_py_mount_vfs, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_MOUNTPOINTS
  { (char *) "mountpoints", guestfs_int_py_mountpoints, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_MOUNTS
  { (char *) "mounts", guestfs_int_py_mounts, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_MV
  { (char *) "mv", guestfs_int_py_mv, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_NR_DEVICES
  { (char *) "nr_devices", guestfs_int_py_nr_devices, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_NTFS_3G_PROBE
  { (char *) "ntfs_3g_probe", guestfs_int_py_ntfs_3g_probe, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_NTFSCLONE_IN
  { (char *) "ntfsclone_in", guestfs_int_py_ntfsclone_in, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_NTFSCLONE_OUT
  { (char *) "ntfsclone_out", guestfs_int_py_ntfsclone_out, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_NTFSFIX
  { (char *) "ntfsfix", guestfs_int_py_ntfsfix, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_NTFSRESIZE_OPTS
  { (char *) "ntfsresize", guestfs_int_py_ntfsresize, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_NTFSRESIZE_SIZE
  { (char *) "ntfsresize_size", guestfs_int_py_ntfsresize_size, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_PARSE_ENVIRONMENT
  { (char *) "parse_environment", guestfs_int_py_parse_environment, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_PARSE_ENVIRONMENT_LIST
  { (char *) "parse_environment_list", guestfs_int_py_parse_environment_list, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_PART_ADD
  { (char *) "part_add", guestfs_int_py_part_add, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_PART_DEL
  { (char *) "part_del", guestfs_int_py_part_del, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_PART_DISK
  { (char *) "part_disk", guestfs_int_py_part_disk, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_PART_GET_BOOTABLE
  { (char *) "part_get_bootable", guestfs_int_py_part_get_bootable, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_PART_GET_GPT_GUID
  { (char *) "part_get_gpt_guid", guestfs_int_py_part_get_gpt_guid, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_PART_GET_GPT_TYPE
  { (char *) "part_get_gpt_type", guestfs_int_py_part_get_gpt_type, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_PART_GET_MBR_ID
  { (char *) "part_get_mbr_id", guestfs_int_py_part_get_mbr_id, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_PART_GET_MBR_PART_TYPE
  { (char *) "part_get_mbr_part_type", guestfs_int_py_part_get_mbr_part_type, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_PART_GET_NAME
  { (char *) "part_get_name", guestfs_int_py_part_get_name, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_PART_GET_PARTTYPE
  { (char *) "part_get_parttype", guestfs_int_py_part_get_parttype, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_PART_INIT
  { (char *) "part_init", guestfs_int_py_part_init, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_PART_LIST
  { (char *) "part_list", guestfs_int_py_part_list, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_PART_SET_BOOTABLE
  { (char *) "part_set_bootable", guestfs_int_py_part_set_bootable, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_PART_SET_GPT_GUID
  { (char *) "part_set_gpt_guid", guestfs_int_py_part_set_gpt_guid, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_PART_SET_GPT_TYPE
  { (char *) "part_set_gpt_type", guestfs_int_py_part_set_gpt_type, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_PART_SET_MBR_ID
  { (char *) "part_set_mbr_id", guestfs_int_py_part_set_mbr_id, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_PART_SET_NAME
  { (char *) "part_set_name", guestfs_int_py_part_set_name, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_PART_TO_DEV
  { (char *) "part_to_dev", guestfs_int_py_part_to_dev, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_PART_TO_PARTNUM
  { (char *) "part_to_partnum", guestfs_int_py_part_to_partnum, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_PING_DAEMON
  { (char *) "ping_daemon", guestfs_int_py_ping_daemon, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_PREAD
  { (char *) "pread", guestfs_int_py_pread, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_PREAD_DEVICE
  { (char *) "pread_device", guestfs_int_py_pread_device, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_PVCHANGE_UUID
  { (char *) "pvchange_uuid", guestfs_int_py_pvchange_uuid, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_PVCHANGE_UUID_ALL
  { (char *) "pvchange_uuid_all", guestfs_int_py_pvchange_uuid_all, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_PVCREATE
  { (char *) "pvcreate", guestfs_int_py_pvcreate, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_PVREMOVE
  { (char *) "pvremove", guestfs_int_py_pvremove, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_PVRESIZE
  { (char *) "pvresize", guestfs_int_py_pvresize, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_PVRESIZE_SIZE
  { (char *) "pvresize_size", guestfs_int_py_pvresize_size, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_PVS
  { (char *) "pvs", guestfs_int_py_pvs, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_PVS_FULL
  { (char *) "pvs_full", guestfs_int_py_pvs_full, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_PVUUID
  { (char *) "pvuuid", guestfs_int_py_pvuuid, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_PWRITE
  { (char *) "pwrite", guestfs_int_py_pwrite, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_PWRITE_DEVICE
  { (char *) "pwrite_device", guestfs_int_py_pwrite_device, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_READ_FILE
  { (char *) "read_file", guestfs_int_py_read_file, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_READ_LINES
  { (char *) "read_lines", guestfs_int_py_read_lines, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_READDIR
  { (char *) "readdir", guestfs_int_py_readdir, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_READLINK
  { (char *) "readlink", guestfs_int_py_readlink, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_READLINKLIST
  { (char *) "readlinklist", guestfs_int_py_readlinklist, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_REALPATH
  { (char *) "realpath", guestfs_int_py_realpath, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_REMOUNT
  { (char *) "remount", guestfs_int_py_remount, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_REMOVE_DRIVE
  { (char *) "remove_drive", guestfs_int_py_remove_drive, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_REMOVEXATTR
  { (char *) "removexattr", guestfs_int_py_removexattr, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_RENAME
  { (char *) "rename", guestfs_int_py_rename, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_RESIZE2FS
  { (char *) "resize2fs", guestfs_int_py_resize2fs, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_RESIZE2FS_M
  { (char *) "resize2fs_M", guestfs_int_py_resize2fs_M, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_RESIZE2FS_SIZE
  { (char *) "resize2fs_size", guestfs_int_py_resize2fs_size, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_RM
  { (char *) "rm", guestfs_int_py_rm, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_RM_F
  { (char *) "rm_f", guestfs_int_py_rm_f, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_RM_RF
  { (char *) "rm_rf", guestfs_int_py_rm_rf, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_RMDIR
  { (char *) "rmdir", guestfs_int_py_rmdir, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_RMMOUNTPOINT
  { (char *) "rmmountpoint", guestfs_int_py_rmmountpoint, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_RSYNC
  { (char *) "rsync", guestfs_int_py_rsync, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_RSYNC_IN
  { (char *) "rsync_in", guestfs_int_py_rsync_in, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_RSYNC_OUT
  { (char *) "rsync_out", guestfs_int_py_rsync_out, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_SCRUB_DEVICE
  { (char *) "scrub_device", guestfs_int_py_scrub_device, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_SCRUB_FILE
  { (char *) "scrub_file", guestfs_int_py_scrub_file, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_SCRUB_FREESPACE
  { (char *) "scrub_freespace", guestfs_int_py_scrub_freespace, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_SET_APPEND
  { (char *) "set_append", guestfs_int_py_set_append, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_SET_ATTACH_METHOD
  { (char *) "set_attach_method", guestfs_int_py_set_attach_method, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_SET_AUTOSYNC
  { (char *) "set_autosync", guestfs_int_py_set_autosync, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_SET_BACKEND
  { (char *) "set_backend", guestfs_int_py_set_backend, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_SET_BACKEND_SETTING
  { (char *) "set_backend_setting", guestfs_int_py_set_backend_setting, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_SET_BACKEND_SETTINGS
  { (char *) "set_backend_settings", guestfs_int_py_set_backend_settings, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_SET_CACHEDIR
  { (char *) "set_cachedir", guestfs_int_py_set_cachedir, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_SET_DIRECT
  { (char *) "set_direct", guestfs_int_py_set_direct, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_SET_E2ATTRS
  { (char *) "set_e2attrs", guestfs_int_py_set_e2attrs, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_SET_E2GENERATION
  { (char *) "set_e2generation", guestfs_int_py_set_e2generation, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_SET_E2LABEL
  { (char *) "set_e2label", guestfs_int_py_set_e2label, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_SET_E2UUID
  { (char *) "set_e2uuid", guestfs_int_py_set_e2uuid, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_SET_HV
  { (char *) "set_hv", guestfs_int_py_set_hv, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_SET_IDENTIFIER
  { (char *) "set_identifier", guestfs_int_py_set_identifier, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_SET_LABEL
  { (char *) "set_label", guestfs_int_py_set_label, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_SET_LIBVIRT_REQUESTED_CREDENTIAL
  { (char *) "set_libvirt_requested_credential", guestfs_int_py_set_libvirt_requested_credential, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_SET_LIBVIRT_SUPPORTED_CREDENTIALS
  { (char *) "set_libvirt_supported_credentials", guestfs_int_py_set_libvirt_supported_credentials, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_SET_MEMSIZE
  { (char *) "set_memsize", guestfs_int_py_set_memsize, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_SET_NETWORK
  { (char *) "set_network", guestfs_int_py_set_network, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_SET_PATH
  { (char *) "set_path", guestfs_int_py_set_path, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_SET_PGROUP
  { (char *) "set_pgroup", guestfs_int_py_set_pgroup, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_SET_PROGRAM
  { (char *) "set_program", guestfs_int_py_set_program, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_SET_QEMU
  { (char *) "set_qemu", guestfs_int_py_set_qemu, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_SET_RECOVERY_PROC
  { (char *) "set_recovery_proc", guestfs_int_py_set_recovery_proc, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_SET_SELINUX
  { (char *) "set_selinux", guestfs_int_py_set_selinux, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_SET_SMP
  { (char *) "set_smp", guestfs_int_py_set_smp, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_SET_TMPDIR
  { (char *) "set_tmpdir", guestfs_int_py_set_tmpdir, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_SET_TRACE
  { (char *) "set_trace", guestfs_int_py_set_trace, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_SET_UUID
  { (char *) "set_uuid", guestfs_int_py_set_uuid, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_SET_UUID_RANDOM
  { (char *) "set_uuid_random", guestfs_int_py_set_uuid_random, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_SET_VERBOSE
  { (char *) "set_verbose", guestfs_int_py_set_verbose, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_SETCON
  { (char *) "setcon", guestfs_int_py_setcon, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_SETXATTR
  { (char *) "setxattr", guestfs_int_py_setxattr, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_SFDISK
  { (char *) "sfdisk", guestfs_int_py_sfdisk, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_SFDISKM
  { (char *) "sfdiskM", guestfs_int_py_sfdiskM, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_SFDISK_N
  { (char *) "sfdisk_N", guestfs_int_py_sfdisk_N, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_SFDISK_DISK_GEOMETRY
  { (char *) "sfdisk_disk_geometry", guestfs_int_py_sfdisk_disk_geometry, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_SFDISK_KERNEL_GEOMETRY
  { (char *) "sfdisk_kernel_geometry", guestfs_int_py_sfdisk_kernel_geometry, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_SFDISK_L
  { (char *) "sfdisk_l", guestfs_int_py_sfdisk_l, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_SH
  { (char *) "sh", guestfs_int_py_sh, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_SH_LINES
  { (char *) "sh_lines", guestfs_int_py_sh_lines, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_SHUTDOWN
  { (char *) "shutdown", guestfs_int_py_shutdown, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_SLEEP
  { (char *) "sleep", guestfs_int_py_sleep, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_STAT
  { (char *) "stat", guestfs_int_py_stat, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_STATNS
  { (char *) "statns", guestfs_int_py_statns, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_STATVFS
  { (char *) "statvfs", guestfs_int_py_statvfs, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_STRINGS
  { (char *) "strings", guestfs_int_py_strings, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_STRINGS_E
  { (char *) "strings_e", guestfs_int_py_strings_e, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_SWAPOFF_DEVICE
  { (char *) "swapoff_device", guestfs_int_py_swapoff_device, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_SWAPOFF_FILE
  { (char *) "swapoff_file", guestfs_int_py_swapoff_file, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_SWAPOFF_LABEL
  { (char *) "swapoff_label", guestfs_int_py_swapoff_label, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_SWAPOFF_UUID
  { (char *) "swapoff_uuid", guestfs_int_py_swapoff_uuid, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_SWAPON_DEVICE
  { (char *) "swapon_device", guestfs_int_py_swapon_device, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_SWAPON_FILE
  { (char *) "swapon_file", guestfs_int_py_swapon_file, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_SWAPON_LABEL
  { (char *) "swapon_label", guestfs_int_py_swapon_label, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_SWAPON_UUID
  { (char *) "swapon_uuid", guestfs_int_py_swapon_uuid, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_SYNC
  { (char *) "sync", guestfs_int_py_sync, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_SYSLINUX
  { (char *) "syslinux", guestfs_int_py_syslinux, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_TAIL
  { (char *) "tail", guestfs_int_py_tail, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_TAIL_N
  { (char *) "tail_n", guestfs_int_py_tail_n, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_TAR_IN_OPTS
  { (char *) "tar_in", guestfs_int_py_tar_in, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_TAR_OUT_OPTS
  { (char *) "tar_out", guestfs_int_py_tar_out, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_TGZ_IN
  { (char *) "tgz_in", guestfs_int_py_tgz_in, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_TGZ_OUT
  { (char *) "tgz_out", guestfs_int_py_tgz_out, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_TOUCH
  { (char *) "touch", guestfs_int_py_touch, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_TRUNCATE
  { (char *) "truncate", guestfs_int_py_truncate, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_TRUNCATE_SIZE
  { (char *) "truncate_size", guestfs_int_py_truncate_size, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_TUNE2FS
  { (char *) "tune2fs", guestfs_int_py_tune2fs, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_TUNE2FS_L
  { (char *) "tune2fs_l", guestfs_int_py_tune2fs_l, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_TXZ_IN
  { (char *) "txz_in", guestfs_int_py_txz_in, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_TXZ_OUT
  { (char *) "txz_out", guestfs_int_py_txz_out, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_UMASK
  { (char *) "umask", guestfs_int_py_umask, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_UMOUNT_OPTS
  { (char *) "umount", guestfs_int_py_umount, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_UMOUNT_ALL
  { (char *) "umount_all", guestfs_int_py_umount_all, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_UMOUNT_LOCAL
  { (char *) "umount_local", guestfs_int_py_umount_local, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_UPLOAD
  { (char *) "upload", guestfs_int_py_upload, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_UPLOAD_OFFSET
  { (char *) "upload_offset", guestfs_int_py_upload_offset, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_USER_CANCEL
  { (char *) "user_cancel", guestfs_int_py_user_cancel, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_UTIMENS
  { (char *) "utimens", guestfs_int_py_utimens, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_UTSNAME
  { (char *) "utsname", guestfs_int_py_utsname, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_VERSION
  { (char *) "version", guestfs_int_py_version, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_VFS_LABEL
  { (char *) "vfs_label", guestfs_int_py_vfs_label, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_VFS_MINIMUM_SIZE
  { (char *) "vfs_minimum_size", guestfs_int_py_vfs_minimum_size, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_VFS_TYPE
  { (char *) "vfs_type", guestfs_int_py_vfs_type, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_VFS_UUID
  { (char *) "vfs_uuid", guestfs_int_py_vfs_uuid, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_VG_ACTIVATE
  { (char *) "vg_activate", guestfs_int_py_vg_activate, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_VG_ACTIVATE_ALL
  { (char *) "vg_activate_all", guestfs_int_py_vg_activate_all, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_VGCHANGE_UUID
  { (char *) "vgchange_uuid", guestfs_int_py_vgchange_uuid, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_VGCHANGE_UUID_ALL
  { (char *) "vgchange_uuid_all", guestfs_int_py_vgchange_uuid_all, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_VGCREATE
  { (char *) "vgcreate", guestfs_int_py_vgcreate, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_VGLVUUIDS
  { (char *) "vglvuuids", guestfs_int_py_vglvuuids, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_VGMETA
  { (char *) "vgmeta", guestfs_int_py_vgmeta, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_VGPVUUIDS
  { (char *) "vgpvuuids", guestfs_int_py_vgpvuuids, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_VGREMOVE
  { (char *) "vgremove", guestfs_int_py_vgremove, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_VGRENAME
  { (char *) "vgrename", guestfs_int_py_vgrename, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_VGS
  { (char *) "vgs", guestfs_int_py_vgs, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_VGS_FULL
  { (char *) "vgs_full", guestfs_int_py_vgs_full, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_VGSCAN
  { (char *) "vgscan", guestfs_int_py_vgscan, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_VGUUID
  { (char *) "vguuid", guestfs_int_py_vguuid, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_WAIT_READY
  { (char *) "wait_ready", guestfs_int_py_wait_ready, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_WC_C
  { (char *) "wc_c", guestfs_int_py_wc_c, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_WC_L
  { (char *) "wc_l", guestfs_int_py_wc_l, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_WC_W
  { (char *) "wc_w", guestfs_int_py_wc_w, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_WIPEFS
  { (char *) "wipefs", guestfs_int_py_wipefs, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_WRITE
  { (char *) "write", guestfs_int_py_write, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_WRITE_APPEND
  { (char *) "write_append", guestfs_int_py_write_append, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_WRITE_FILE
  { (char *) "write_file", guestfs_int_py_write_file, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_XFS_ADMIN
  { (char *) "xfs_admin", guestfs_int_py_xfs_admin, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_XFS_GROWFS
  { (char *) "xfs_growfs", guestfs_int_py_xfs_growfs, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_XFS_INFO
  { (char *) "xfs_info", guestfs_int_py_xfs_info, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_XFS_REPAIR
  { (char *) "xfs_repair", guestfs_int_py_xfs_repair, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_ZEGREP
  { (char *) "zegrep", guestfs_int_py_zegrep, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_ZEGREPI
  { (char *) "zegrepi", guestfs_int_py_zegrepi, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_ZERO
  { (char *) "zero", guestfs_int_py_zero, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_ZERO_DEVICE
  { (char *) "zero_device", guestfs_int_py_zero_device, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_ZERO_FREE_SPACE
  { (char *) "zero_free_space", guestfs_int_py_zero_free_space, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_ZEROFREE
  { (char *) "zerofree", guestfs_int_py_zerofree, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_ZFGREP
  { (char *) "zfgrep", guestfs_int_py_zfgrep, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_ZFGREPI
  { (char *) "zfgrepi", guestfs_int_py_zfgrepi, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_ZFILE
  { (char *) "zfile", guestfs_int_py_zfile, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_ZGREP
  { (char *) "zgrep", guestfs_int_py_zgrep, METH_VARARGS, NULL },
#endif
#ifdef GUESTFS_HAVE_ZGREPI
  { (char *) "zgrepi", guestfs_int_py_zgrepi, METH_VARARGS, NULL },
#endif
  { NULL, NULL, 0, NULL }
};

#if PY_MAJOR_VERSION >= 3
static struct PyModuleDef moduledef = {
  PyModuleDef_HEAD_INIT,
  "libguestfsmod",     /* m_name */
  "libguestfs module",   /* m_doc */
  -1,                    /* m_size */
  methods,               /* m_methods */
  NULL,                  /* m_reload */
  NULL,                  /* m_traverse */
  NULL,                  /* m_clear */
  NULL,                  /* m_free */
};
#endif

static PyObject *
moduleinit (void)
{
  PyObject *m;

#if PY_MAJOR_VERSION >= 3
  m = PyModule_Create (&moduledef);
#else
  m = Py_InitModule ((char *) "libguestfsmod", methods);
#endif

  if (m != NULL)
    guestfs_int_py_extend_module (m);

  return m; /* m might be NULL if module init failed */
}

#if PY_MAJOR_VERSION >= 3
extern PyMODINIT_FUNC PyInit_libguestfsmod (void);

PyMODINIT_FUNC
PyInit_libguestfsmod (void)
{
  return moduleinit ();
}
#else
extern void initlibguestfsmod (void);

void
initlibguestfsmod (void)
{
  (void) moduleinit ();
}
#endif
