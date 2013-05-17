/* libguestfs generated file
 * WARNING: THIS FILE IS GENERATED FROM:
 *   generator/ *.ml
 * ANY CHANGES YOU MAKE TO THIS FILE WILL BE LOST.
 *
 * Copyright (C) 2009-2013 Red Hat Inc.
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

static PyObject *
put_hivex_node (struct guestfs_hivex_node *hivex_node)
{
  PyObject *dict;

  dict = PyDict_New ();
  PyDict_SetItemString (dict, "hivex_node_h",
                        PyLong_FromLongLong (hivex_node->hivex_node_h));
  return dict;
};

static PyObject *
put_hivex_value (struct guestfs_hivex_value *hivex_value)
{
  PyObject *dict;

  dict = PyDict_New ();
  PyDict_SetItemString (dict, "hivex_value_h",
                        PyLong_FromLongLong (hivex_value->hivex_value_h));
  return dict;
};

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

static PyObject *
py_guestfs_internal_test (PyObject *self, PyObject *args)
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

  if (py_obool != Py_None) {
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_OBOOL_BITMASK;
    optargs_s.obool = PyLong_AsLong (py_obool);
    if (PyErr_Occurred ()) goto out;
  }
  if (py_oint != Py_None) {
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_OINT_BITMASK;
    optargs_s.oint = PyLong_AsLong (py_oint);
    if (PyErr_Occurred ()) goto out;
  }
  if (py_oint64 != Py_None) {
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_OINT64_BITMASK;
    optargs_s.oint64 = PyLong_AsLongLong (py_oint64);
    if (PyErr_Occurred ()) goto out;
  }
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
  if (py_ostringlist != Py_None) {
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_OSTRINGLIST_BITMASK;
    optargs_s.ostringlist = get_string_list (py_ostringlist);
    if (!optargs_s.ostringlist) goto out;
  }

  r = guestfs_internal_test_argv (g, str, optstr, strlist, b, integer, integer64, filein, fileout, bufferin, bufferin_size, optargs);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

 out:
  free (strlist);
  if (py_ostringlist != Py_None)
    free ((char **) optargs_s.ostringlist);
  return py_r;
}

static PyObject *
py_guestfs_internal_test_only_optargs (PyObject *self, PyObject *args)
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

  if (py_test != Py_None) {
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_ONLY_OPTARGS_TEST_BITMASK;
    optargs_s.test = PyLong_AsLong (py_test);
    if (PyErr_Occurred ()) goto out;
  }

  r = guestfs_internal_test_only_optargs_argv (g, optargs);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

 out:
  return py_r;
}

static PyObject *
py_guestfs_internal_test_63_optargs (PyObject *self, PyObject *args)
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

  if (py_opt1 != Py_None) {
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT1_BITMASK;
    optargs_s.opt1 = PyLong_AsLong (py_opt1);
    if (PyErr_Occurred ()) goto out;
  }
  if (py_opt2 != Py_None) {
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT2_BITMASK;
    optargs_s.opt2 = PyLong_AsLong (py_opt2);
    if (PyErr_Occurred ()) goto out;
  }
  if (py_opt3 != Py_None) {
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT3_BITMASK;
    optargs_s.opt3 = PyLong_AsLong (py_opt3);
    if (PyErr_Occurred ()) goto out;
  }
  if (py_opt4 != Py_None) {
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT4_BITMASK;
    optargs_s.opt4 = PyLong_AsLong (py_opt4);
    if (PyErr_Occurred ()) goto out;
  }
  if (py_opt5 != Py_None) {
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT5_BITMASK;
    optargs_s.opt5 = PyLong_AsLong (py_opt5);
    if (PyErr_Occurred ()) goto out;
  }
  if (py_opt6 != Py_None) {
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT6_BITMASK;
    optargs_s.opt6 = PyLong_AsLong (py_opt6);
    if (PyErr_Occurred ()) goto out;
  }
  if (py_opt7 != Py_None) {
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT7_BITMASK;
    optargs_s.opt7 = PyLong_AsLong (py_opt7);
    if (PyErr_Occurred ()) goto out;
  }
  if (py_opt8 != Py_None) {
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT8_BITMASK;
    optargs_s.opt8 = PyLong_AsLong (py_opt8);
    if (PyErr_Occurred ()) goto out;
  }
  if (py_opt9 != Py_None) {
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT9_BITMASK;
    optargs_s.opt9 = PyLong_AsLong (py_opt9);
    if (PyErr_Occurred ()) goto out;
  }
  if (py_opt10 != Py_None) {
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT10_BITMASK;
    optargs_s.opt10 = PyLong_AsLong (py_opt10);
    if (PyErr_Occurred ()) goto out;
  }
  if (py_opt11 != Py_None) {
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT11_BITMASK;
    optargs_s.opt11 = PyLong_AsLong (py_opt11);
    if (PyErr_Occurred ()) goto out;
  }
  if (py_opt12 != Py_None) {
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT12_BITMASK;
    optargs_s.opt12 = PyLong_AsLong (py_opt12);
    if (PyErr_Occurred ()) goto out;
  }
  if (py_opt13 != Py_None) {
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT13_BITMASK;
    optargs_s.opt13 = PyLong_AsLong (py_opt13);
    if (PyErr_Occurred ()) goto out;
  }
  if (py_opt14 != Py_None) {
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT14_BITMASK;
    optargs_s.opt14 = PyLong_AsLong (py_opt14);
    if (PyErr_Occurred ()) goto out;
  }
  if (py_opt15 != Py_None) {
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT15_BITMASK;
    optargs_s.opt15 = PyLong_AsLong (py_opt15);
    if (PyErr_Occurred ()) goto out;
  }
  if (py_opt16 != Py_None) {
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT16_BITMASK;
    optargs_s.opt16 = PyLong_AsLong (py_opt16);
    if (PyErr_Occurred ()) goto out;
  }
  if (py_opt17 != Py_None) {
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT17_BITMASK;
    optargs_s.opt17 = PyLong_AsLong (py_opt17);
    if (PyErr_Occurred ()) goto out;
  }
  if (py_opt18 != Py_None) {
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT18_BITMASK;
    optargs_s.opt18 = PyLong_AsLong (py_opt18);
    if (PyErr_Occurred ()) goto out;
  }
  if (py_opt19 != Py_None) {
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT19_BITMASK;
    optargs_s.opt19 = PyLong_AsLong (py_opt19);
    if (PyErr_Occurred ()) goto out;
  }
  if (py_opt20 != Py_None) {
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT20_BITMASK;
    optargs_s.opt20 = PyLong_AsLong (py_opt20);
    if (PyErr_Occurred ()) goto out;
  }
  if (py_opt21 != Py_None) {
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT21_BITMASK;
    optargs_s.opt21 = PyLong_AsLong (py_opt21);
    if (PyErr_Occurred ()) goto out;
  }
  if (py_opt22 != Py_None) {
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT22_BITMASK;
    optargs_s.opt22 = PyLong_AsLong (py_opt22);
    if (PyErr_Occurred ()) goto out;
  }
  if (py_opt23 != Py_None) {
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT23_BITMASK;
    optargs_s.opt23 = PyLong_AsLong (py_opt23);
    if (PyErr_Occurred ()) goto out;
  }
  if (py_opt24 != Py_None) {
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT24_BITMASK;
    optargs_s.opt24 = PyLong_AsLong (py_opt24);
    if (PyErr_Occurred ()) goto out;
  }
  if (py_opt25 != Py_None) {
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT25_BITMASK;
    optargs_s.opt25 = PyLong_AsLong (py_opt25);
    if (PyErr_Occurred ()) goto out;
  }
  if (py_opt26 != Py_None) {
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT26_BITMASK;
    optargs_s.opt26 = PyLong_AsLong (py_opt26);
    if (PyErr_Occurred ()) goto out;
  }
  if (py_opt27 != Py_None) {
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT27_BITMASK;
    optargs_s.opt27 = PyLong_AsLong (py_opt27);
    if (PyErr_Occurred ()) goto out;
  }
  if (py_opt28 != Py_None) {
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT28_BITMASK;
    optargs_s.opt28 = PyLong_AsLong (py_opt28);
    if (PyErr_Occurred ()) goto out;
  }
  if (py_opt29 != Py_None) {
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT29_BITMASK;
    optargs_s.opt29 = PyLong_AsLong (py_opt29);
    if (PyErr_Occurred ()) goto out;
  }
  if (py_opt30 != Py_None) {
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT30_BITMASK;
    optargs_s.opt30 = PyLong_AsLong (py_opt30);
    if (PyErr_Occurred ()) goto out;
  }
  if (py_opt31 != Py_None) {
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT31_BITMASK;
    optargs_s.opt31 = PyLong_AsLong (py_opt31);
    if (PyErr_Occurred ()) goto out;
  }
  if (py_opt32 != Py_None) {
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT32_BITMASK;
    optargs_s.opt32 = PyLong_AsLong (py_opt32);
    if (PyErr_Occurred ()) goto out;
  }
  if (py_opt33 != Py_None) {
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT33_BITMASK;
    optargs_s.opt33 = PyLong_AsLong (py_opt33);
    if (PyErr_Occurred ()) goto out;
  }
  if (py_opt34 != Py_None) {
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT34_BITMASK;
    optargs_s.opt34 = PyLong_AsLong (py_opt34);
    if (PyErr_Occurred ()) goto out;
  }
  if (py_opt35 != Py_None) {
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT35_BITMASK;
    optargs_s.opt35 = PyLong_AsLong (py_opt35);
    if (PyErr_Occurred ()) goto out;
  }
  if (py_opt36 != Py_None) {
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT36_BITMASK;
    optargs_s.opt36 = PyLong_AsLong (py_opt36);
    if (PyErr_Occurred ()) goto out;
  }
  if (py_opt37 != Py_None) {
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT37_BITMASK;
    optargs_s.opt37 = PyLong_AsLong (py_opt37);
    if (PyErr_Occurred ()) goto out;
  }
  if (py_opt38 != Py_None) {
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT38_BITMASK;
    optargs_s.opt38 = PyLong_AsLong (py_opt38);
    if (PyErr_Occurred ()) goto out;
  }
  if (py_opt39 != Py_None) {
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT39_BITMASK;
    optargs_s.opt39 = PyLong_AsLong (py_opt39);
    if (PyErr_Occurred ()) goto out;
  }
  if (py_opt40 != Py_None) {
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT40_BITMASK;
    optargs_s.opt40 = PyLong_AsLong (py_opt40);
    if (PyErr_Occurred ()) goto out;
  }
  if (py_opt41 != Py_None) {
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT41_BITMASK;
    optargs_s.opt41 = PyLong_AsLong (py_opt41);
    if (PyErr_Occurred ()) goto out;
  }
  if (py_opt42 != Py_None) {
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT42_BITMASK;
    optargs_s.opt42 = PyLong_AsLong (py_opt42);
    if (PyErr_Occurred ()) goto out;
  }
  if (py_opt43 != Py_None) {
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT43_BITMASK;
    optargs_s.opt43 = PyLong_AsLong (py_opt43);
    if (PyErr_Occurred ()) goto out;
  }
  if (py_opt44 != Py_None) {
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT44_BITMASK;
    optargs_s.opt44 = PyLong_AsLong (py_opt44);
    if (PyErr_Occurred ()) goto out;
  }
  if (py_opt45 != Py_None) {
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT45_BITMASK;
    optargs_s.opt45 = PyLong_AsLong (py_opt45);
    if (PyErr_Occurred ()) goto out;
  }
  if (py_opt46 != Py_None) {
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT46_BITMASK;
    optargs_s.opt46 = PyLong_AsLong (py_opt46);
    if (PyErr_Occurred ()) goto out;
  }
  if (py_opt47 != Py_None) {
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT47_BITMASK;
    optargs_s.opt47 = PyLong_AsLong (py_opt47);
    if (PyErr_Occurred ()) goto out;
  }
  if (py_opt48 != Py_None) {
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT48_BITMASK;
    optargs_s.opt48 = PyLong_AsLong (py_opt48);
    if (PyErr_Occurred ()) goto out;
  }
  if (py_opt49 != Py_None) {
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT49_BITMASK;
    optargs_s.opt49 = PyLong_AsLong (py_opt49);
    if (PyErr_Occurred ()) goto out;
  }
  if (py_opt50 != Py_None) {
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT50_BITMASK;
    optargs_s.opt50 = PyLong_AsLong (py_opt50);
    if (PyErr_Occurred ()) goto out;
  }
  if (py_opt51 != Py_None) {
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT51_BITMASK;
    optargs_s.opt51 = PyLong_AsLong (py_opt51);
    if (PyErr_Occurred ()) goto out;
  }
  if (py_opt52 != Py_None) {
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT52_BITMASK;
    optargs_s.opt52 = PyLong_AsLong (py_opt52);
    if (PyErr_Occurred ()) goto out;
  }
  if (py_opt53 != Py_None) {
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT53_BITMASK;
    optargs_s.opt53 = PyLong_AsLong (py_opt53);
    if (PyErr_Occurred ()) goto out;
  }
  if (py_opt54 != Py_None) {
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT54_BITMASK;
    optargs_s.opt54 = PyLong_AsLong (py_opt54);
    if (PyErr_Occurred ()) goto out;
  }
  if (py_opt55 != Py_None) {
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT55_BITMASK;
    optargs_s.opt55 = PyLong_AsLong (py_opt55);
    if (PyErr_Occurred ()) goto out;
  }
  if (py_opt56 != Py_None) {
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT56_BITMASK;
    optargs_s.opt56 = PyLong_AsLong (py_opt56);
    if (PyErr_Occurred ()) goto out;
  }
  if (py_opt57 != Py_None) {
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT57_BITMASK;
    optargs_s.opt57 = PyLong_AsLong (py_opt57);
    if (PyErr_Occurred ()) goto out;
  }
  if (py_opt58 != Py_None) {
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT58_BITMASK;
    optargs_s.opt58 = PyLong_AsLong (py_opt58);
    if (PyErr_Occurred ()) goto out;
  }
  if (py_opt59 != Py_None) {
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT59_BITMASK;
    optargs_s.opt59 = PyLong_AsLong (py_opt59);
    if (PyErr_Occurred ()) goto out;
  }
  if (py_opt60 != Py_None) {
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT60_BITMASK;
    optargs_s.opt60 = PyLong_AsLong (py_opt60);
    if (PyErr_Occurred ()) goto out;
  }
  if (py_opt61 != Py_None) {
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT61_BITMASK;
    optargs_s.opt61 = PyLong_AsLong (py_opt61);
    if (PyErr_Occurred ()) goto out;
  }
  if (py_opt62 != Py_None) {
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT62_BITMASK;
    optargs_s.opt62 = PyLong_AsLong (py_opt62);
    if (PyErr_Occurred ()) goto out;
  }
  if (py_opt63 != Py_None) {
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT63_BITMASK;
    optargs_s.opt63 = PyLong_AsLong (py_opt63);
    if (PyErr_Occurred ()) goto out;
  }

  r = guestfs_internal_test_63_optargs_argv (g, optargs);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

 out:
  return py_r;
}

static PyObject *
py_guestfs_internal_test_rint (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_internal_test_rinterr (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_internal_test_rint64 (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_internal_test_rint64err (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_internal_test_rbool (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_internal_test_rboolerr (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_internal_test_rconststring (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_internal_test_rconststringerr (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_internal_test_rconstoptstring (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_internal_test_rconstoptstringerr (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_internal_test_rstring (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_internal_test_rstringerr (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_internal_test_rstringlist (PyObject *self, PyObject *args)
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
  guestfs___free_string_list (r);

 out:
  return py_r;
}

static PyObject *
py_guestfs_internal_test_rstringlisterr (PyObject *self, PyObject *args)
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
  guestfs___free_string_list (r);

 out:
  return py_r;
}

static PyObject *
py_guestfs_internal_test_rstruct (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_internal_test_rstructerr (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_internal_test_rstructlist (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_internal_test_rstructlisterr (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_internal_test_rhashtable (PyObject *self, PyObject *args)
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
  guestfs___free_string_list (r);

 out:
  return py_r;
}

static PyObject *
py_guestfs_internal_test_rhashtableerr (PyObject *self, PyObject *args)
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
  guestfs___free_string_list (r);

 out:
  return py_r;
}

static PyObject *
py_guestfs_internal_test_rbufferout (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_internal_test_rbufferouterr (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_internal_test_set_output (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_internal_test_close_output (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_launch (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_wait_ready (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_kill_subprocess (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_add_cdrom (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_add_drive_ro (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_config (PyObject *self, PyObject *args)
{
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  const char *qemuparam;
  const char *qemuvalue;

  if (!PyArg_ParseTuple (args, (char *) "Osz:guestfs_config",
                         &py_g, &qemuparam, &qemuvalue))
    goto out;
  g = get_handle (py_g);

  r = guestfs_config (g, qemuparam, qemuvalue);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

 out:
  return py_r;
}

static PyObject *
py_guestfs_set_qemu (PyObject *self, PyObject *args)
{
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  const char *qemu;

  if (!PyArg_ParseTuple (args, (char *) "Oz:guestfs_set_qemu",
                         &py_g, &qemu))
    goto out;
  g = get_handle (py_g);

  r = guestfs_set_qemu (g, qemu);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

 out:
  return py_r;
}

static PyObject *
py_guestfs_get_qemu (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_set_path (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_get_path (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_set_append (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_get_append (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_set_autosync (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_get_autosync (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_set_verbose (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_get_verbose (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_is_ready (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_is_config (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_is_launching (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_is_busy (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_get_state (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_set_memsize (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_get_memsize (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_get_pid (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_version (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_set_selinux (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_get_selinux (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_set_trace (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_get_trace (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_set_direct (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_get_direct (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_set_recovery_proc (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_get_recovery_proc (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_add_drive_with_if (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_add_drive_ro_with_if (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_file_architecture (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_inspect_os (PyObject *self, PyObject *args)
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
  guestfs___free_string_list (r);

 out:
  return py_r;
}

static PyObject *
py_guestfs_inspect_get_type (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_inspect_get_arch (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_inspect_get_distro (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_inspect_get_major_version (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_inspect_get_minor_version (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_inspect_get_product_name (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_inspect_get_mountpoints (PyObject *self, PyObject *args)
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
  guestfs___free_string_list (r);

 out:
  return py_r;
}

static PyObject *
py_guestfs_inspect_get_filesystems (PyObject *self, PyObject *args)
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
  guestfs___free_string_list (r);

 out:
  return py_r;
}

static PyObject *
py_guestfs_set_network (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_get_network (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_list_filesystems (PyObject *self, PyObject *args)
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
  guestfs___free_string_list (r);

 out:
  return py_r;
}

static PyObject *
py_guestfs_add_drive (PyObject *self, PyObject *args)
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

  optargs_s.bitmask = 0;

  if (!PyArg_ParseTuple (args, (char *) "OsOOOOOOOOO:guestfs_add_drive",
                         &py_g, &filename, &py_readonly, &py_format, &py_iface, &py_name, &py_label, &py_protocol, &py_server, &py_username, &py_secret))
    goto out;
  g = get_handle (py_g);

  if (py_readonly != Py_None) {
    optargs_s.bitmask |= GUESTFS_ADD_DRIVE_OPTS_READONLY_BITMASK;
    optargs_s.readonly = PyLong_AsLong (py_readonly);
    if (PyErr_Occurred ()) goto out;
  }
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
  if (py_server != Py_None) {
    optargs_s.bitmask |= GUESTFS_ADD_DRIVE_OPTS_SERVER_BITMASK;
    optargs_s.server = get_string_list (py_server);
    if (!optargs_s.server) goto out;
  }
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

  r = guestfs_add_drive_opts_argv (g, filename, optargs);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

 out:
  if (py_server != Py_None)
    free ((char **) optargs_s.server);
  return py_r;
}

static PyObject *
py_guestfs_inspect_get_windows_systemroot (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_inspect_get_roots (PyObject *self, PyObject *args)
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
  guestfs___free_string_list (r);

 out:
  return py_r;
}

static PyObject *
py_guestfs_debug_drives (PyObject *self, PyObject *args)
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
  guestfs___free_string_list (r);

 out:
  return py_r;
}

static PyObject *
py_guestfs_add_domain (PyObject *self, PyObject *args)
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

  optargs_s.bitmask = 0;

  if (!PyArg_ParseTuple (args, (char *) "OsOOOOOO:guestfs_add_domain",
                         &py_g, &dom, &py_libvirturi, &py_readonly, &py_iface, &py_live, &py_allowuuid, &py_readonlydisk))
    goto out;
  g = get_handle (py_g);

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
  if (py_readonly != Py_None) {
    optargs_s.bitmask |= GUESTFS_ADD_DOMAIN_READONLY_BITMASK;
    optargs_s.readonly = PyLong_AsLong (py_readonly);
    if (PyErr_Occurred ()) goto out;
  }
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
  if (py_live != Py_None) {
    optargs_s.bitmask |= GUESTFS_ADD_DOMAIN_LIVE_BITMASK;
    optargs_s.live = PyLong_AsLong (py_live);
    if (PyErr_Occurred ()) goto out;
  }
  if (py_allowuuid != Py_None) {
    optargs_s.bitmask |= GUESTFS_ADD_DOMAIN_ALLOWUUID_BITMASK;
    optargs_s.allowuuid = PyLong_AsLong (py_allowuuid);
    if (PyErr_Occurred ()) goto out;
  }
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_inspect_get_package_format (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_inspect_get_package_management (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_inspect_list_applications (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_inspect_list_applications2 (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_inspect_get_hostname (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_inspect_get_format (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_inspect_is_live (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_inspect_is_netinst (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_inspect_is_multipart (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_set_attach_method (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_get_attach_method (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_set_backend (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_get_backend (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_inspect_get_product_variant (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_inspect_get_windows_current_control_set (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_inspect_get_drive_mappings (PyObject *self, PyObject *args)
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
  guestfs___free_string_list (r);

 out:
  return py_r;
}

static PyObject *
py_guestfs_inspect_get_icon (PyObject *self, PyObject *args)
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

  if (py_favicon != Py_None) {
    optargs_s.bitmask |= GUESTFS_INSPECT_GET_ICON_FAVICON_BITMASK;
    optargs_s.favicon = PyLong_AsLong (py_favicon);
    if (PyErr_Occurred ()) goto out;
  }
  if (py_highquality != Py_None) {
    optargs_s.bitmask |= GUESTFS_INSPECT_GET_ICON_HIGHQUALITY_BITMASK;
    optargs_s.highquality = PyLong_AsLong (py_highquality);
    if (PyErr_Occurred ()) goto out;
  }

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

 out:
  return py_r;
}

static PyObject *
py_guestfs_set_pgroup (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_get_pgroup (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_set_smp (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_get_smp (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_mount_local (PyObject *self, PyObject *args)
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

  if (py_readonly != Py_None) {
    optargs_s.bitmask |= GUESTFS_MOUNT_LOCAL_READONLY_BITMASK;
    optargs_s.readonly = PyLong_AsLong (py_readonly);
    if (PyErr_Occurred ()) goto out;
  }
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
  if (py_cachetimeout != Py_None) {
    optargs_s.bitmask |= GUESTFS_MOUNT_LOCAL_CACHETIMEOUT_BITMASK;
    optargs_s.cachetimeout = PyLong_AsLong (py_cachetimeout);
    if (PyErr_Occurred ()) goto out;
  }
  if (py_debugcalls != Py_None) {
    optargs_s.bitmask |= GUESTFS_MOUNT_LOCAL_DEBUGCALLS_BITMASK;
    optargs_s.debugcalls = PyLong_AsLong (py_debugcalls);
    if (PyErr_Occurred ()) goto out;
  }

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

 out:
  return py_r;
}

static PyObject *
py_guestfs_mount_local_run (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_umount_local (PyObject *self, PyObject *args)
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

  if (py_retry != Py_None) {
    optargs_s.bitmask |= GUESTFS_UMOUNT_LOCAL_RETRY_BITMASK;
    optargs_s.retry = PyLong_AsLong (py_retry);
    if (PyErr_Occurred ()) goto out;
  }

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

 out:
  return py_r;
}

static PyObject *
py_guestfs_max_disks (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_canonical_device_name (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_shutdown (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_cat (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_find (PyObject *self, PyObject *args)
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
  guestfs___free_string_list (r);

 out:
  return py_r;
}

static PyObject *
py_guestfs_read_file (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_read_lines (PyObject *self, PyObject *args)
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
  guestfs___free_string_list (r);

 out:
  return py_r;
}

static PyObject *
py_guestfs_write (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_write_append (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_lstatlist (PyObject *self, PyObject *args)
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

 out:
  free (names);
  return py_r;
}

static PyObject *
py_guestfs_lxattrlist (PyObject *self, PyObject *args)
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

 out:
  free (names);
  return py_r;
}

static PyObject *
py_guestfs_readlinklist (PyObject *self, PyObject *args)
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
  guestfs___free_string_list (r);

 out:
  free (names);
  return py_r;
}

static PyObject *
py_guestfs_ls (PyObject *self, PyObject *args)
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
  guestfs___free_string_list (r);

 out:
  return py_r;
}

static PyObject *
py_guestfs_hivex_value_utf8 (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_disk_format (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_disk_virtual_size (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_disk_has_backing_file (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_remove_drive (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_set_libvirt_supported_credentials (PyObject *self, PyObject *args)
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

 out:
  free (creds);
  return py_r;
}

static PyObject *
py_guestfs_get_libvirt_requested_credentials (PyObject *self, PyObject *args)
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
  guestfs___free_string_list (r);

 out:
  return py_r;
}

static PyObject *
py_guestfs_get_libvirt_requested_credential_prompt (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_get_libvirt_requested_credential_challenge (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_get_libvirt_requested_credential_defresult (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_set_libvirt_requested_credential (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_parse_environment (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_parse_environment_list (PyObject *self, PyObject *args)
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

 out:
  free (environment);
  return py_r;
}

static PyObject *
py_guestfs_set_tmpdir (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_get_tmpdir (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_set_cachedir (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_get_cachedir (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_user_cancel (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_set_program (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_get_program (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_mount (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_sync (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_touch (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_ll (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_list_devices (PyObject *self, PyObject *args)
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
  guestfs___free_string_list (r);

 out:
  return py_r;
}

static PyObject *
py_guestfs_list_partitions (PyObject *self, PyObject *args)
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
  guestfs___free_string_list (r);

 out:
  return py_r;
}

static PyObject *
py_guestfs_pvs (PyObject *self, PyObject *args)
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
  guestfs___free_string_list (r);

 out:
  return py_r;
}

static PyObject *
py_guestfs_vgs (PyObject *self, PyObject *args)
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
  guestfs___free_string_list (r);

 out:
  return py_r;
}

static PyObject *
py_guestfs_lvs (PyObject *self, PyObject *args)
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
  guestfs___free_string_list (r);

 out:
  return py_r;
}

static PyObject *
py_guestfs_pvs_full (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_vgs_full (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_lvs_full (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_aug_init (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_aug_close (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_aug_defvar (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_aug_defnode (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_aug_get (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_aug_set (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_aug_insert (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_aug_rm (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_aug_mv (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_aug_match (PyObject *self, PyObject *args)
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
  guestfs___free_string_list (r);

 out:
  return py_r;
}

static PyObject *
py_guestfs_aug_save (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_aug_load (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_aug_ls (PyObject *self, PyObject *args)
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
  guestfs___free_string_list (r);

 out:
  return py_r;
}

static PyObject *
py_guestfs_rm (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_rmdir (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_rm_rf (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_mkdir (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_mkdir_p (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_chmod (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_chown (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_exists (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_is_file (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  const char *path;

  if (!PyArg_ParseTuple (args, (char *) "Os:guestfs_is_file",
                         &py_g, &path))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_is_file (g, path);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  py_r = PyLong_FromLong ((long) r);

 out:
  return py_r;
}

static PyObject *
py_guestfs_is_dir (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  const char *path;

  if (!PyArg_ParseTuple (args, (char *) "Os:guestfs_is_dir",
                         &py_g, &path))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_is_dir (g, path);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  py_r = PyLong_FromLong ((long) r);

 out:
  return py_r;
}

static PyObject *
py_guestfs_pvcreate (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_vgcreate (PyObject *self, PyObject *args)
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

 out:
  free (physvols);
  return py_r;
}

static PyObject *
py_guestfs_lvcreate (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_sfdisk (PyObject *self, PyObject *args)
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

 out:
  free (lines);
  return py_r;
}

static PyObject *
py_guestfs_write_file (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_umount (PyObject *self, PyObject *args)
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

  if (py_force != Py_None) {
    optargs_s.bitmask |= GUESTFS_UMOUNT_OPTS_FORCE_BITMASK;
    optargs_s.force = PyLong_AsLong (py_force);
    if (PyErr_Occurred ()) goto out;
  }
  if (py_lazyunmount != Py_None) {
    optargs_s.bitmask |= GUESTFS_UMOUNT_OPTS_LAZYUNMOUNT_BITMASK;
    optargs_s.lazyunmount = PyLong_AsLong (py_lazyunmount);
    if (PyErr_Occurred ()) goto out;
  }

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

 out:
  return py_r;
}

static PyObject *
py_guestfs_mounts (PyObject *self, PyObject *args)
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
  guestfs___free_string_list (r);

 out:
  return py_r;
}

static PyObject *
py_guestfs_umount_all (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_lvm_remove_all (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_file (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_command (PyObject *self, PyObject *args)
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

 out:
  free (arguments);
  return py_r;
}

static PyObject *
py_guestfs_command_lines (PyObject *self, PyObject *args)
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
  guestfs___free_string_list (r);

 out:
  free (arguments);
  return py_r;
}

static PyObject *
py_guestfs_stat (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_lstat (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_statvfs (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_tune2fs_l (PyObject *self, PyObject *args)
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
  guestfs___free_string_list (r);

 out:
  return py_r;
}

static PyObject *
py_guestfs_blockdev_setro (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_blockdev_setrw (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_blockdev_getro (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_blockdev_getss (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_blockdev_getbsz (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_blockdev_setbsz (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_blockdev_getsz (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_blockdev_getsize64 (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_blockdev_flushbufs (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_blockdev_rereadpt (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_upload (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_download (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_checksum (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_tar_in (PyObject *self, PyObject *args)
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

  optargs_s.bitmask = 0;

  if (!PyArg_ParseTuple (args, (char *) "OssO:guestfs_tar_in",
                         &py_g, &tarfile, &directory, &py_compress))
    goto out;
  g = get_handle (py_g);

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

 out:
  return py_r;
}

static PyObject *
py_guestfs_tar_out (PyObject *self, PyObject *args)
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

  optargs_s.bitmask = 0;

  if (!PyArg_ParseTuple (args, (char *) "OssOOO:guestfs_tar_out",
                         &py_g, &directory, &tarfile, &py_compress, &py_numericowner, &py_excludes))
    goto out;
  g = get_handle (py_g);

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
  if (py_numericowner != Py_None) {
    optargs_s.bitmask |= GUESTFS_TAR_OUT_OPTS_NUMERICOWNER_BITMASK;
    optargs_s.numericowner = PyLong_AsLong (py_numericowner);
    if (PyErr_Occurred ()) goto out;
  }
  if (py_excludes != Py_None) {
    optargs_s.bitmask |= GUESTFS_TAR_OUT_OPTS_EXCLUDES_BITMASK;
    optargs_s.excludes = get_string_list (py_excludes);
    if (!optargs_s.excludes) goto out;
  }

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

 out:
  if (py_excludes != Py_None)
    free ((char **) optargs_s.excludes);
  return py_r;
}

static PyObject *
py_guestfs_tgz_in (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_tgz_out (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_mount_ro (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_mount_options (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_mount_vfs (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_debug (PyObject *self, PyObject *args)
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

 out:
  free (extraargs);
  return py_r;
}

static PyObject *
py_guestfs_lvremove (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_vgremove (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_pvremove (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_set_e2label (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_get_e2label (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_set_e2uuid (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_get_e2uuid (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_fsck (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_zero (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_grub_install (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_cp (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_cp_a (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_mv (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_drop_caches (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_dmesg (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_ping_daemon (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_equal (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_strings (PyObject *self, PyObject *args)
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
  guestfs___free_string_list (r);

 out:
  return py_r;
}

static PyObject *
py_guestfs_strings_e (PyObject *self, PyObject *args)
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
  guestfs___free_string_list (r);

 out:
  return py_r;
}

static PyObject *
py_guestfs_hexdump (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_zerofree (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_pvresize (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_sfdisk_N (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_sfdisk_l (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_sfdisk_kernel_geometry (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_sfdisk_disk_geometry (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_vg_activate_all (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_vg_activate (PyObject *self, PyObject *args)
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

 out:
  free (volgroups);
  return py_r;
}

static PyObject *
py_guestfs_lvresize (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_resize2fs (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_e2fsck_f (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_sleep (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_ntfs_3g_probe (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_sh (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_sh_lines (PyObject *self, PyObject *args)
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
  guestfs___free_string_list (r);

 out:
  return py_r;
}

static PyObject *
py_guestfs_glob_expand (PyObject *self, PyObject *args)
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
  guestfs___free_string_list (r);

 out:
  return py_r;
}

static PyObject *
py_guestfs_scrub_device (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_scrub_file (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_scrub_freespace (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_mkdtemp (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_wc_l (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_wc_w (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_wc_c (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_head (PyObject *self, PyObject *args)
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
  guestfs___free_string_list (r);

 out:
  return py_r;
}

static PyObject *
py_guestfs_head_n (PyObject *self, PyObject *args)
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
  guestfs___free_string_list (r);

 out:
  return py_r;
}

static PyObject *
py_guestfs_tail (PyObject *self, PyObject *args)
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
  guestfs___free_string_list (r);

 out:
  return py_r;
}

static PyObject *
py_guestfs_tail_n (PyObject *self, PyObject *args)
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
  guestfs___free_string_list (r);

 out:
  return py_r;
}

static PyObject *
py_guestfs_df (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_df_h (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_du (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_initrd_list (PyObject *self, PyObject *args)
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
  guestfs___free_string_list (r);

 out:
  return py_r;
}

static PyObject *
py_guestfs_mount_loop (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_mkswap (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_mkswap_L (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_mkswap_U (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_mknod (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_mkfifo (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_mknod_b (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_mknod_c (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_umask (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_readdir (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_sfdiskM (PyObject *self, PyObject *args)
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

 out:
  free (lines);
  return py_r;
}

static PyObject *
py_guestfs_zfile (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_getxattrs (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_lgetxattrs (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_setxattr (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_lsetxattr (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_removexattr (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_lremovexattr (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_mountpoints (PyObject *self, PyObject *args)
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
  guestfs___free_string_list (r);

 out:
  return py_r;
}

static PyObject *
py_guestfs_mkmountpoint (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_rmmountpoint (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_grep (PyObject *self, PyObject *args)
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

  if (py_extended != Py_None) {
    optargs_s.bitmask |= GUESTFS_GREP_OPTS_EXTENDED_BITMASK;
    optargs_s.extended = PyLong_AsLong (py_extended);
    if (PyErr_Occurred ()) goto out;
  }
  if (py_fixed != Py_None) {
    optargs_s.bitmask |= GUESTFS_GREP_OPTS_FIXED_BITMASK;
    optargs_s.fixed = PyLong_AsLong (py_fixed);
    if (PyErr_Occurred ()) goto out;
  }
  if (py_insensitive != Py_None) {
    optargs_s.bitmask |= GUESTFS_GREP_OPTS_INSENSITIVE_BITMASK;
    optargs_s.insensitive = PyLong_AsLong (py_insensitive);
    if (PyErr_Occurred ()) goto out;
  }
  if (py_compressed != Py_None) {
    optargs_s.bitmask |= GUESTFS_GREP_OPTS_COMPRESSED_BITMASK;
    optargs_s.compressed = PyLong_AsLong (py_compressed);
    if (PyErr_Occurred ()) goto out;
  }

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
  guestfs___free_string_list (r);

 out:
  return py_r;
}

static PyObject *
py_guestfs_egrep (PyObject *self, PyObject *args)
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
  guestfs___free_string_list (r);

 out:
  return py_r;
}

static PyObject *
py_guestfs_fgrep (PyObject *self, PyObject *args)
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
  guestfs___free_string_list (r);

 out:
  return py_r;
}

static PyObject *
py_guestfs_grepi (PyObject *self, PyObject *args)
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
  guestfs___free_string_list (r);

 out:
  return py_r;
}

static PyObject *
py_guestfs_egrepi (PyObject *self, PyObject *args)
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
  guestfs___free_string_list (r);

 out:
  return py_r;
}

static PyObject *
py_guestfs_fgrepi (PyObject *self, PyObject *args)
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
  guestfs___free_string_list (r);

 out:
  return py_r;
}

static PyObject *
py_guestfs_zgrep (PyObject *self, PyObject *args)
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
  guestfs___free_string_list (r);

 out:
  return py_r;
}

static PyObject *
py_guestfs_zegrep (PyObject *self, PyObject *args)
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
  guestfs___free_string_list (r);

 out:
  return py_r;
}

static PyObject *
py_guestfs_zfgrep (PyObject *self, PyObject *args)
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
  guestfs___free_string_list (r);

 out:
  return py_r;
}

static PyObject *
py_guestfs_zgrepi (PyObject *self, PyObject *args)
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
  guestfs___free_string_list (r);

 out:
  return py_r;
}

static PyObject *
py_guestfs_zegrepi (PyObject *self, PyObject *args)
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
  guestfs___free_string_list (r);

 out:
  return py_r;
}

static PyObject *
py_guestfs_zfgrepi (PyObject *self, PyObject *args)
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
  guestfs___free_string_list (r);

 out:
  return py_r;
}

static PyObject *
py_guestfs_realpath (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_ln (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_ln_f (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_ln_s (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_ln_sf (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_readlink (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_fallocate (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_swapon_device (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_swapoff_device (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_swapon_file (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_swapoff_file (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_swapon_label (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_swapoff_label (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_swapon_uuid (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_swapoff_uuid (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_mkswap_file (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_inotify_init (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_inotify_add_watch (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_inotify_rm_watch (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_inotify_read (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_inotify_files (PyObject *self, PyObject *args)
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
  guestfs___free_string_list (r);

 out:
  return py_r;
}

static PyObject *
py_guestfs_inotify_close (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_setcon (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_getcon (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_mkfs_b (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_mke2journal (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_mke2journal_L (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_mke2journal_U (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_mke2fs_J (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_mke2fs_JL (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_mke2fs_JU (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_modprobe (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_echo_daemon (PyObject *self, PyObject *args)
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

 out:
  free (words);
  return py_r;
}

static PyObject *
py_guestfs_find0 (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_case_sensitive_path (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_vfs_type (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_truncate (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_truncate_size (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_utimens (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_mkdir_mode (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_lchown (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_pread (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_part_init (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_part_add (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_part_disk (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_part_set_bootable (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_part_set_name (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_part_list (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_part_get_parttype (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_fill (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_available (PyObject *self, PyObject *args)
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

 out:
  free (groups);
  return py_r;
}

static PyObject *
py_guestfs_dd (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_filesize (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_lvrename (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_vgrename (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_initrd_cat (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_pvuuid (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_vguuid (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_lvuuid (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_vgpvuuids (PyObject *self, PyObject *args)
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
  guestfs___free_string_list (r);

 out:
  return py_r;
}

static PyObject *
py_guestfs_vglvuuids (PyObject *self, PyObject *args)
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
  guestfs___free_string_list (r);

 out:
  return py_r;
}

static PyObject *
py_guestfs_copy_size (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_zero_device (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_txz_in (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_txz_out (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_vgscan (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_part_del (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_part_get_bootable (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_part_get_mbr_id (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_part_set_mbr_id (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_checksum_device (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_lvresize_free (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_aug_clear (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_get_umask (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_debug_upload (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_base64_in (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_base64_out (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_checksums_out (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_fill_pattern (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_pwrite (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_resize2fs_size (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_pvresize_size (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_ntfsresize_size (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_available_all_groups (PyObject *self, PyObject *args)
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
  guestfs___free_string_list (r);

 out:
  return py_r;
}

static PyObject *
py_guestfs_fallocate64 (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_vfs_label (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_vfs_uuid (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_lvm_set_filter (PyObject *self, PyObject *args)
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

 out:
  free (devices);
  return py_r;
}

static PyObject *
py_guestfs_lvm_clear_filter (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_luks_open (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_luks_open_ro (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_luks_close (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_luks_format (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_luks_format_cipher (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_luks_add_key (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_luks_kill_slot (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_is_lv (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_findfs_uuid (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_findfs_label (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_is_chardev (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  const char *path;

  if (!PyArg_ParseTuple (args, (char *) "Os:guestfs_is_chardev",
                         &py_g, &path))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_is_chardev (g, path);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  py_r = PyLong_FromLong ((long) r);

 out:
  return py_r;
}

static PyObject *
py_guestfs_is_blockdev (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  const char *path;

  if (!PyArg_ParseTuple (args, (char *) "Os:guestfs_is_blockdev",
                         &py_g, &path))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_is_blockdev (g, path);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  py_r = PyLong_FromLong ((long) r);

 out:
  return py_r;
}

static PyObject *
py_guestfs_is_fifo (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  const char *path;

  if (!PyArg_ParseTuple (args, (char *) "Os:guestfs_is_fifo",
                         &py_g, &path))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_is_fifo (g, path);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  py_r = PyLong_FromLong ((long) r);

 out:
  return py_r;
}

static PyObject *
py_guestfs_is_symlink (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_is_socket (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  const char *path;

  if (!PyArg_ParseTuple (args, (char *) "Os:guestfs_is_socket",
                         &py_g, &path))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_is_socket (g, path);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  py_r = PyLong_FromLong ((long) r);

 out:
  return py_r;
}

static PyObject *
py_guestfs_part_to_dev (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_upload_offset (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_download_offset (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_pwrite_device (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_pread_device (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_lvm_canonical_lv_name (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_mkfs (PyObject *self, PyObject *args)
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

  optargs_s.bitmask = 0;

  if (!PyArg_ParseTuple (args, (char *) "OssOOOO:guestfs_mkfs",
                         &py_g, &fstype, &device, &py_blocksize, &py_features, &py_inode, &py_sectorsize))
    goto out;
  g = get_handle (py_g);

  if (py_blocksize != Py_None) {
    optargs_s.bitmask |= GUESTFS_MKFS_OPTS_BLOCKSIZE_BITMASK;
    optargs_s.blocksize = PyLong_AsLong (py_blocksize);
    if (PyErr_Occurred ()) goto out;
  }
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
  if (py_inode != Py_None) {
    optargs_s.bitmask |= GUESTFS_MKFS_OPTS_INODE_BITMASK;
    optargs_s.inode = PyLong_AsLong (py_inode);
    if (PyErr_Occurred ()) goto out;
  }
  if (py_sectorsize != Py_None) {
    optargs_s.bitmask |= GUESTFS_MKFS_OPTS_SECTORSIZE_BITMASK;
    optargs_s.sectorsize = PyLong_AsLong (py_sectorsize);
    if (PyErr_Occurred ()) goto out;
  }

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

 out:
  return py_r;
}

static PyObject *
py_guestfs_getxattr (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_lgetxattr (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_resize2fs_M (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_is_zero (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_is_zero_device (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_list_9p (PyObject *self, PyObject *args)
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
  guestfs___free_string_list (r);

 out:
  return py_r;
}

static PyObject *
py_guestfs_mount_9p (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_list_dm_devices (PyObject *self, PyObject *args)
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
  guestfs___free_string_list (r);

 out:
  return py_r;
}

static PyObject *
py_guestfs_ntfsresize (PyObject *self, PyObject *args)
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

  if (py_size != Py_None) {
    optargs_s.bitmask |= GUESTFS_NTFSRESIZE_OPTS_SIZE_BITMASK;
    optargs_s.size = PyLong_AsLongLong (py_size);
    if (PyErr_Occurred ()) goto out;
  }
  if (py_force != Py_None) {
    optargs_s.bitmask |= GUESTFS_NTFSRESIZE_OPTS_FORCE_BITMASK;
    optargs_s.force = PyLong_AsLong (py_force);
    if (PyErr_Occurred ()) goto out;
  }

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

 out:
  return py_r;
}

static PyObject *
py_guestfs_btrfs_filesystem_resize (PyObject *self, PyObject *args)
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

  if (py_size != Py_None) {
    optargs_s.bitmask |= GUESTFS_BTRFS_FILESYSTEM_RESIZE_SIZE_BITMASK;
    optargs_s.size = PyLong_AsLongLong (py_size);
    if (PyErr_Occurred ()) goto out;
  }

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

 out:
  return py_r;
}

static PyObject *
py_guestfs_compress_out (PyObject *self, PyObject *args)
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

  if (py_level != Py_None) {
    optargs_s.bitmask |= GUESTFS_COMPRESS_OUT_LEVEL_BITMASK;
    optargs_s.level = PyLong_AsLong (py_level);
    if (PyErr_Occurred ()) goto out;
  }

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

 out:
  return py_r;
}

static PyObject *
py_guestfs_compress_device_out (PyObject *self, PyObject *args)
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

  if (py_level != Py_None) {
    optargs_s.bitmask |= GUESTFS_COMPRESS_DEVICE_OUT_LEVEL_BITMASK;
    optargs_s.level = PyLong_AsLong (py_level);
    if (PyErr_Occurred ()) goto out;
  }

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

 out:
  return py_r;
}

static PyObject *
py_guestfs_part_to_partnum (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_copy_device_to_device (PyObject *self, PyObject *args)
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

  optargs_s.bitmask = 0;

  if (!PyArg_ParseTuple (args, (char *) "OssOOOO:guestfs_copy_device_to_device",
                         &py_g, &src, &dest, &py_srcoffset, &py_destoffset, &py_size, &py_sparse))
    goto out;
  g = get_handle (py_g);

  if (py_srcoffset != Py_None) {
    optargs_s.bitmask |= GUESTFS_COPY_DEVICE_TO_DEVICE_SRCOFFSET_BITMASK;
    optargs_s.srcoffset = PyLong_AsLongLong (py_srcoffset);
    if (PyErr_Occurred ()) goto out;
  }
  if (py_destoffset != Py_None) {
    optargs_s.bitmask |= GUESTFS_COPY_DEVICE_TO_DEVICE_DESTOFFSET_BITMASK;
    optargs_s.destoffset = PyLong_AsLongLong (py_destoffset);
    if (PyErr_Occurred ()) goto out;
  }
  if (py_size != Py_None) {
    optargs_s.bitmask |= GUESTFS_COPY_DEVICE_TO_DEVICE_SIZE_BITMASK;
    optargs_s.size = PyLong_AsLongLong (py_size);
    if (PyErr_Occurred ()) goto out;
  }
  if (py_sparse != Py_None) {
    optargs_s.bitmask |= GUESTFS_COPY_DEVICE_TO_DEVICE_SPARSE_BITMASK;
    optargs_s.sparse = PyLong_AsLong (py_sparse);
    if (PyErr_Occurred ()) goto out;
  }

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

 out:
  return py_r;
}

static PyObject *
py_guestfs_copy_device_to_file (PyObject *self, PyObject *args)
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

  optargs_s.bitmask = 0;

  if (!PyArg_ParseTuple (args, (char *) "OssOOOO:guestfs_copy_device_to_file",
                         &py_g, &src, &dest, &py_srcoffset, &py_destoffset, &py_size, &py_sparse))
    goto out;
  g = get_handle (py_g);

  if (py_srcoffset != Py_None) {
    optargs_s.bitmask |= GUESTFS_COPY_DEVICE_TO_FILE_SRCOFFSET_BITMASK;
    optargs_s.srcoffset = PyLong_AsLongLong (py_srcoffset);
    if (PyErr_Occurred ()) goto out;
  }
  if (py_destoffset != Py_None) {
    optargs_s.bitmask |= GUESTFS_COPY_DEVICE_TO_FILE_DESTOFFSET_BITMASK;
    optargs_s.destoffset = PyLong_AsLongLong (py_destoffset);
    if (PyErr_Occurred ()) goto out;
  }
  if (py_size != Py_None) {
    optargs_s.bitmask |= GUESTFS_COPY_DEVICE_TO_FILE_SIZE_BITMASK;
    optargs_s.size = PyLong_AsLongLong (py_size);
    if (PyErr_Occurred ()) goto out;
  }
  if (py_sparse != Py_None) {
    optargs_s.bitmask |= GUESTFS_COPY_DEVICE_TO_FILE_SPARSE_BITMASK;
    optargs_s.sparse = PyLong_AsLong (py_sparse);
    if (PyErr_Occurred ()) goto out;
  }

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

 out:
  return py_r;
}

static PyObject *
py_guestfs_copy_file_to_device (PyObject *self, PyObject *args)
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

  optargs_s.bitmask = 0;

  if (!PyArg_ParseTuple (args, (char *) "OssOOOO:guestfs_copy_file_to_device",
                         &py_g, &src, &dest, &py_srcoffset, &py_destoffset, &py_size, &py_sparse))
    goto out;
  g = get_handle (py_g);

  if (py_srcoffset != Py_None) {
    optargs_s.bitmask |= GUESTFS_COPY_FILE_TO_DEVICE_SRCOFFSET_BITMASK;
    optargs_s.srcoffset = PyLong_AsLongLong (py_srcoffset);
    if (PyErr_Occurred ()) goto out;
  }
  if (py_destoffset != Py_None) {
    optargs_s.bitmask |= GUESTFS_COPY_FILE_TO_DEVICE_DESTOFFSET_BITMASK;
    optargs_s.destoffset = PyLong_AsLongLong (py_destoffset);
    if (PyErr_Occurred ()) goto out;
  }
  if (py_size != Py_None) {
    optargs_s.bitmask |= GUESTFS_COPY_FILE_TO_DEVICE_SIZE_BITMASK;
    optargs_s.size = PyLong_AsLongLong (py_size);
    if (PyErr_Occurred ()) goto out;
  }
  if (py_sparse != Py_None) {
    optargs_s.bitmask |= GUESTFS_COPY_FILE_TO_DEVICE_SPARSE_BITMASK;
    optargs_s.sparse = PyLong_AsLong (py_sparse);
    if (PyErr_Occurred ()) goto out;
  }

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

 out:
  return py_r;
}

static PyObject *
py_guestfs_copy_file_to_file (PyObject *self, PyObject *args)
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

  optargs_s.bitmask = 0;

  if (!PyArg_ParseTuple (args, (char *) "OssOOOO:guestfs_copy_file_to_file",
                         &py_g, &src, &dest, &py_srcoffset, &py_destoffset, &py_size, &py_sparse))
    goto out;
  g = get_handle (py_g);

  if (py_srcoffset != Py_None) {
    optargs_s.bitmask |= GUESTFS_COPY_FILE_TO_FILE_SRCOFFSET_BITMASK;
    optargs_s.srcoffset = PyLong_AsLongLong (py_srcoffset);
    if (PyErr_Occurred ()) goto out;
  }
  if (py_destoffset != Py_None) {
    optargs_s.bitmask |= GUESTFS_COPY_FILE_TO_FILE_DESTOFFSET_BITMASK;
    optargs_s.destoffset = PyLong_AsLongLong (py_destoffset);
    if (PyErr_Occurred ()) goto out;
  }
  if (py_size != Py_None) {
    optargs_s.bitmask |= GUESTFS_COPY_FILE_TO_FILE_SIZE_BITMASK;
    optargs_s.size = PyLong_AsLongLong (py_size);
    if (PyErr_Occurred ()) goto out;
  }
  if (py_sparse != Py_None) {
    optargs_s.bitmask |= GUESTFS_COPY_FILE_TO_FILE_SPARSE_BITMASK;
    optargs_s.sparse = PyLong_AsLong (py_sparse);
    if (PyErr_Occurred ()) goto out;
  }

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

 out:
  return py_r;
}

static PyObject *
py_guestfs_tune2fs (PyObject *self, PyObject *args)
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

  if (py_force != Py_None) {
    optargs_s.bitmask |= GUESTFS_TUNE2FS_FORCE_BITMASK;
    optargs_s.force = PyLong_AsLong (py_force);
    if (PyErr_Occurred ()) goto out;
  }
  if (py_maxmountcount != Py_None) {
    optargs_s.bitmask |= GUESTFS_TUNE2FS_MAXMOUNTCOUNT_BITMASK;
    optargs_s.maxmountcount = PyLong_AsLong (py_maxmountcount);
    if (PyErr_Occurred ()) goto out;
  }
  if (py_mountcount != Py_None) {
    optargs_s.bitmask |= GUESTFS_TUNE2FS_MOUNTCOUNT_BITMASK;
    optargs_s.mountcount = PyLong_AsLong (py_mountcount);
    if (PyErr_Occurred ()) goto out;
  }
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
  if (py_group != Py_None) {
    optargs_s.bitmask |= GUESTFS_TUNE2FS_GROUP_BITMASK;
    optargs_s.group = PyLong_AsLongLong (py_group);
    if (PyErr_Occurred ()) goto out;
  }
  if (py_intervalbetweenchecks != Py_None) {
    optargs_s.bitmask |= GUESTFS_TUNE2FS_INTERVALBETWEENCHECKS_BITMASK;
    optargs_s.intervalbetweenchecks = PyLong_AsLong (py_intervalbetweenchecks);
    if (PyErr_Occurred ()) goto out;
  }
  if (py_reservedblockspercentage != Py_None) {
    optargs_s.bitmask |= GUESTFS_TUNE2FS_RESERVEDBLOCKSPERCENTAGE_BITMASK;
    optargs_s.reservedblockspercentage = PyLong_AsLong (py_reservedblockspercentage);
    if (PyErr_Occurred ()) goto out;
  }
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
  if (py_reservedblockscount != Py_None) {
    optargs_s.bitmask |= GUESTFS_TUNE2FS_RESERVEDBLOCKSCOUNT_BITMASK;
    optargs_s.reservedblockscount = PyLong_AsLongLong (py_reservedblockscount);
    if (PyErr_Occurred ()) goto out;
  }
  if (py_user != Py_None) {
    optargs_s.bitmask |= GUESTFS_TUNE2FS_USER_BITMASK;
    optargs_s.user = PyLong_AsLongLong (py_user);
    if (PyErr_Occurred ()) goto out;
  }

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

 out:
  return py_r;
}

static PyObject *
py_guestfs_md_create (PyObject *self, PyObject *args)
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

  if (py_missingbitmap != Py_None) {
    optargs_s.bitmask |= GUESTFS_MD_CREATE_MISSINGBITMAP_BITMASK;
    optargs_s.missingbitmap = PyLong_AsLongLong (py_missingbitmap);
    if (PyErr_Occurred ()) goto out;
  }
  if (py_nrdevices != Py_None) {
    optargs_s.bitmask |= GUESTFS_MD_CREATE_NRDEVICES_BITMASK;
    optargs_s.nrdevices = PyLong_AsLong (py_nrdevices);
    if (PyErr_Occurred ()) goto out;
  }
  if (py_spare != Py_None) {
    optargs_s.bitmask |= GUESTFS_MD_CREATE_SPARE_BITMASK;
    optargs_s.spare = PyLong_AsLong (py_spare);
    if (PyErr_Occurred ()) goto out;
  }
  if (py_chunk != Py_None) {
    optargs_s.bitmask |= GUESTFS_MD_CREATE_CHUNK_BITMASK;
    optargs_s.chunk = PyLong_AsLongLong (py_chunk);
    if (PyErr_Occurred ()) goto out;
  }
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

 out:
  free (devices);
  return py_r;
}

static PyObject *
py_guestfs_list_md_devices (PyObject *self, PyObject *args)
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
  guestfs___free_string_list (r);

 out:
  return py_r;
}

static PyObject *
py_guestfs_md_detail (PyObject *self, PyObject *args)
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
  guestfs___free_string_list (r);

 out:
  return py_r;
}

static PyObject *
py_guestfs_md_stop (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_blkid (PyObject *self, PyObject *args)
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
  guestfs___free_string_list (r);

 out:
  return py_r;
}

static PyObject *
py_guestfs_e2fsck (PyObject *self, PyObject *args)
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

  if (py_correct != Py_None) {
    optargs_s.bitmask |= GUESTFS_E2FSCK_CORRECT_BITMASK;
    optargs_s.correct = PyLong_AsLong (py_correct);
    if (PyErr_Occurred ()) goto out;
  }
  if (py_forceall != Py_None) {
    optargs_s.bitmask |= GUESTFS_E2FSCK_FORCEALL_BITMASK;
    optargs_s.forceall = PyLong_AsLong (py_forceall);
    if (PyErr_Occurred ()) goto out;
  }

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

 out:
  return py_r;
}

static PyObject *
py_guestfs_llz (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_wipefs (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_ntfsfix (PyObject *self, PyObject *args)
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

  if (py_clearbadsectors != Py_None) {
    optargs_s.bitmask |= GUESTFS_NTFSFIX_CLEARBADSECTORS_BITMASK;
    optargs_s.clearbadsectors = PyLong_AsLong (py_clearbadsectors);
    if (PyErr_Occurred ()) goto out;
  }

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

 out:
  return py_r;
}

static PyObject *
py_guestfs_ntfsclone_out (PyObject *self, PyObject *args)
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

  if (py_metadataonly != Py_None) {
    optargs_s.bitmask |= GUESTFS_NTFSCLONE_OUT_METADATAONLY_BITMASK;
    optargs_s.metadataonly = PyLong_AsLong (py_metadataonly);
    if (PyErr_Occurred ()) goto out;
  }
  if (py_rescue != Py_None) {
    optargs_s.bitmask |= GUESTFS_NTFSCLONE_OUT_RESCUE_BITMASK;
    optargs_s.rescue = PyLong_AsLong (py_rescue);
    if (PyErr_Occurred ()) goto out;
  }
  if (py_ignorefscheck != Py_None) {
    optargs_s.bitmask |= GUESTFS_NTFSCLONE_OUT_IGNOREFSCHECK_BITMASK;
    optargs_s.ignorefscheck = PyLong_AsLong (py_ignorefscheck);
    if (PyErr_Occurred ()) goto out;
  }
  if (py_preservetimestamps != Py_None) {
    optargs_s.bitmask |= GUESTFS_NTFSCLONE_OUT_PRESERVETIMESTAMPS_BITMASK;
    optargs_s.preservetimestamps = PyLong_AsLong (py_preservetimestamps);
    if (PyErr_Occurred ()) goto out;
  }
  if (py_force != Py_None) {
    optargs_s.bitmask |= GUESTFS_NTFSCLONE_OUT_FORCE_BITMASK;
    optargs_s.force = PyLong_AsLong (py_force);
    if (PyErr_Occurred ()) goto out;
  }

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

 out:
  return py_r;
}

static PyObject *
py_guestfs_ntfsclone_in (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_set_label (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_zero_free_space (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_lvcreate_free (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_isoinfo_device (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_isoinfo (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_vgmeta (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_md_stat (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_mkfs_btrfs (PyObject *self, PyObject *args)
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

  if (py_allocstart != Py_None) {
    optargs_s.bitmask |= GUESTFS_MKFS_BTRFS_ALLOCSTART_BITMASK;
    optargs_s.allocstart = PyLong_AsLongLong (py_allocstart);
    if (PyErr_Occurred ()) goto out;
  }
  if (py_bytecount != Py_None) {
    optargs_s.bitmask |= GUESTFS_MKFS_BTRFS_BYTECOUNT_BITMASK;
    optargs_s.bytecount = PyLong_AsLongLong (py_bytecount);
    if (PyErr_Occurred ()) goto out;
  }
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
  if (py_leafsize != Py_None) {
    optargs_s.bitmask |= GUESTFS_MKFS_BTRFS_LEAFSIZE_BITMASK;
    optargs_s.leafsize = PyLong_AsLong (py_leafsize);
    if (PyErr_Occurred ()) goto out;
  }
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
  if (py_nodesize != Py_None) {
    optargs_s.bitmask |= GUESTFS_MKFS_BTRFS_NODESIZE_BITMASK;
    optargs_s.nodesize = PyLong_AsLong (py_nodesize);
    if (PyErr_Occurred ()) goto out;
  }
  if (py_sectorsize != Py_None) {
    optargs_s.bitmask |= GUESTFS_MKFS_BTRFS_SECTORSIZE_BITMASK;
    optargs_s.sectorsize = PyLong_AsLong (py_sectorsize);
    if (PyErr_Occurred ()) goto out;
  }

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

 out:
  free (devices);
  return py_r;
}

static PyObject *
py_guestfs_get_e2attrs (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_set_e2attrs (PyObject *self, PyObject *args)
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

  if (py_clear != Py_None) {
    optargs_s.bitmask |= GUESTFS_SET_E2ATTRS_CLEAR_BITMASK;
    optargs_s.clear = PyLong_AsLong (py_clear);
    if (PyErr_Occurred ()) goto out;
  }

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

 out:
  return py_r;
}

static PyObject *
py_guestfs_get_e2generation (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_set_e2generation (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_btrfs_subvolume_snapshot (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  const char *source;
  const char *dest;

  if (!PyArg_ParseTuple (args, (char *) "Oss:guestfs_btrfs_subvolume_snapshot",
                         &py_g, &source, &dest))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_btrfs_subvolume_snapshot (g, source, dest);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

 out:
  return py_r;
}

static PyObject *
py_guestfs_btrfs_subvolume_delete (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_btrfs_subvolume_create (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  const char *dest;

  if (!PyArg_ParseTuple (args, (char *) "Os:guestfs_btrfs_subvolume_create",
                         &py_g, &dest))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_btrfs_subvolume_create (g, dest);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

 out:
  return py_r;
}

static PyObject *
py_guestfs_btrfs_subvolume_list (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_btrfs_subvolume_set_default (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_btrfs_filesystem_sync (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_btrfs_filesystem_balance (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_btrfs_device_add (PyObject *self, PyObject *args)
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

 out:
  free (devices);
  return py_r;
}

static PyObject *
py_guestfs_btrfs_device_delete (PyObject *self, PyObject *args)
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

 out:
  free (devices);
  return py_r;
}

static PyObject *
py_guestfs_btrfs_set_seeding (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_btrfs_fsck (PyObject *self, PyObject *args)
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

  if (py_superblock != Py_None) {
    optargs_s.bitmask |= GUESTFS_BTRFS_FSCK_SUPERBLOCK_BITMASK;
    optargs_s.superblock = PyLong_AsLongLong (py_superblock);
    if (PyErr_Occurred ()) goto out;
  }
  if (py_repair != Py_None) {
    optargs_s.bitmask |= GUESTFS_BTRFS_FSCK_REPAIR_BITMASK;
    optargs_s.repair = PyLong_AsLong (py_repair);
    if (PyErr_Occurred ()) goto out;
  }

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

 out:
  return py_r;
}

static PyObject *
py_guestfs_filesystem_available (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_fstrim (PyObject *self, PyObject *args)
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

  if (py_offset != Py_None) {
    optargs_s.bitmask |= GUESTFS_FSTRIM_OFFSET_BITMASK;
    optargs_s.offset = PyLong_AsLongLong (py_offset);
    if (PyErr_Occurred ()) goto out;
  }
  if (py_length != Py_None) {
    optargs_s.bitmask |= GUESTFS_FSTRIM_LENGTH_BITMASK;
    optargs_s.length = PyLong_AsLongLong (py_length);
    if (PyErr_Occurred ()) goto out;
  }
  if (py_minimumfreeextent != Py_None) {
    optargs_s.bitmask |= GUESTFS_FSTRIM_MINIMUMFREEEXTENT_BITMASK;
    optargs_s.minimumfreeextent = PyLong_AsLongLong (py_minimumfreeextent);
    if (PyErr_Occurred ()) goto out;
  }

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

 out:
  return py_r;
}

static PyObject *
py_guestfs_device_index (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_nr_devices (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_xfs_info (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_pvchange_uuid (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_pvchange_uuid_all (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_vgchange_uuid (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_vgchange_uuid_all (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_utsname (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_xfs_growfs (PyObject *self, PyObject *args)
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

  if (py_datasec != Py_None) {
    optargs_s.bitmask |= GUESTFS_XFS_GROWFS_DATASEC_BITMASK;
    optargs_s.datasec = PyLong_AsLong (py_datasec);
    if (PyErr_Occurred ()) goto out;
  }
  if (py_logsec != Py_None) {
    optargs_s.bitmask |= GUESTFS_XFS_GROWFS_LOGSEC_BITMASK;
    optargs_s.logsec = PyLong_AsLong (py_logsec);
    if (PyErr_Occurred ()) goto out;
  }
  if (py_rtsec != Py_None) {
    optargs_s.bitmask |= GUESTFS_XFS_GROWFS_RTSEC_BITMASK;
    optargs_s.rtsec = PyLong_AsLong (py_rtsec);
    if (PyErr_Occurred ()) goto out;
  }
  if (py_datasize != Py_None) {
    optargs_s.bitmask |= GUESTFS_XFS_GROWFS_DATASIZE_BITMASK;
    optargs_s.datasize = PyLong_AsLongLong (py_datasize);
    if (PyErr_Occurred ()) goto out;
  }
  if (py_logsize != Py_None) {
    optargs_s.bitmask |= GUESTFS_XFS_GROWFS_LOGSIZE_BITMASK;
    optargs_s.logsize = PyLong_AsLongLong (py_logsize);
    if (PyErr_Occurred ()) goto out;
  }
  if (py_rtsize != Py_None) {
    optargs_s.bitmask |= GUESTFS_XFS_GROWFS_RTSIZE_BITMASK;
    optargs_s.rtsize = PyLong_AsLongLong (py_rtsize);
    if (PyErr_Occurred ()) goto out;
  }
  if (py_rtextsize != Py_None) {
    optargs_s.bitmask |= GUESTFS_XFS_GROWFS_RTEXTSIZE_BITMASK;
    optargs_s.rtextsize = PyLong_AsLongLong (py_rtextsize);
    if (PyErr_Occurred ()) goto out;
  }
  if (py_maxpct != Py_None) {
    optargs_s.bitmask |= GUESTFS_XFS_GROWFS_MAXPCT_BITMASK;
    optargs_s.maxpct = PyLong_AsLong (py_maxpct);
    if (PyErr_Occurred ()) goto out;
  }

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

 out:
  return py_r;
}

static PyObject *
py_guestfs_rsync (PyObject *self, PyObject *args)
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

  if (py_archive != Py_None) {
    optargs_s.bitmask |= GUESTFS_RSYNC_ARCHIVE_BITMASK;
    optargs_s.archive = PyLong_AsLong (py_archive);
    if (PyErr_Occurred ()) goto out;
  }
  if (py_deletedest != Py_None) {
    optargs_s.bitmask |= GUESTFS_RSYNC_DELETEDEST_BITMASK;
    optargs_s.deletedest = PyLong_AsLong (py_deletedest);
    if (PyErr_Occurred ()) goto out;
  }

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

 out:
  return py_r;
}

static PyObject *
py_guestfs_rsync_in (PyObject *self, PyObject *args)
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

  if (py_archive != Py_None) {
    optargs_s.bitmask |= GUESTFS_RSYNC_IN_ARCHIVE_BITMASK;
    optargs_s.archive = PyLong_AsLong (py_archive);
    if (PyErr_Occurred ()) goto out;
  }
  if (py_deletedest != Py_None) {
    optargs_s.bitmask |= GUESTFS_RSYNC_IN_DELETEDEST_BITMASK;
    optargs_s.deletedest = PyLong_AsLong (py_deletedest);
    if (PyErr_Occurred ()) goto out;
  }

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

 out:
  return py_r;
}

static PyObject *
py_guestfs_rsync_out (PyObject *self, PyObject *args)
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

  if (py_archive != Py_None) {
    optargs_s.bitmask |= GUESTFS_RSYNC_OUT_ARCHIVE_BITMASK;
    optargs_s.archive = PyLong_AsLong (py_archive);
    if (PyErr_Occurred ()) goto out;
  }
  if (py_deletedest != Py_None) {
    optargs_s.bitmask |= GUESTFS_RSYNC_OUT_DELETEDEST_BITMASK;
    optargs_s.deletedest = PyLong_AsLong (py_deletedest);
    if (PyErr_Occurred ()) goto out;
  }

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

 out:
  return py_r;
}

static PyObject *
py_guestfs_ls0 (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_fill_dir (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_xfs_admin (PyObject *self, PyObject *args)
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

  if (py_extunwritten != Py_None) {
    optargs_s.bitmask |= GUESTFS_XFS_ADMIN_EXTUNWRITTEN_BITMASK;
    optargs_s.extunwritten = PyLong_AsLong (py_extunwritten);
    if (PyErr_Occurred ()) goto out;
  }
  if (py_imgfile != Py_None) {
    optargs_s.bitmask |= GUESTFS_XFS_ADMIN_IMGFILE_BITMASK;
    optargs_s.imgfile = PyLong_AsLong (py_imgfile);
    if (PyErr_Occurred ()) goto out;
  }
  if (py_v2log != Py_None) {
    optargs_s.bitmask |= GUESTFS_XFS_ADMIN_V2LOG_BITMASK;
    optargs_s.v2log = PyLong_AsLong (py_v2log);
    if (PyErr_Occurred ()) goto out;
  }
  if (py_projid32bit != Py_None) {
    optargs_s.bitmask |= GUESTFS_XFS_ADMIN_PROJID32BIT_BITMASK;
    optargs_s.projid32bit = PyLong_AsLong (py_projid32bit);
    if (PyErr_Occurred ()) goto out;
  }
  if (py_lazycounter != Py_None) {
    optargs_s.bitmask |= GUESTFS_XFS_ADMIN_LAZYCOUNTER_BITMASK;
    optargs_s.lazycounter = PyLong_AsLong (py_lazycounter);
    if (PyErr_Occurred ()) goto out;
  }
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_hivex_open (PyObject *self, PyObject *args)
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

  if (py_verbose != Py_None) {
    optargs_s.bitmask |= GUESTFS_HIVEX_OPEN_VERBOSE_BITMASK;
    optargs_s.verbose = PyLong_AsLong (py_verbose);
    if (PyErr_Occurred ()) goto out;
  }
  if (py_debug != Py_None) {
    optargs_s.bitmask |= GUESTFS_HIVEX_OPEN_DEBUG_BITMASK;
    optargs_s.debug = PyLong_AsLong (py_debug);
    if (PyErr_Occurred ()) goto out;
  }
  if (py_write != Py_None) {
    optargs_s.bitmask |= GUESTFS_HIVEX_OPEN_WRITE_BITMASK;
    optargs_s.write = PyLong_AsLong (py_write);
    if (PyErr_Occurred ()) goto out;
  }

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

 out:
  return py_r;
}

static PyObject *
py_guestfs_hivex_close (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_hivex_root (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_hivex_node_name (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_hivex_node_children (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_hivex_node_get_child (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_hivex_node_parent (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_hivex_node_values (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_hivex_node_get_value (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_hivex_value_key (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_hivex_value_type (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_hivex_value_value (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_hivex_commit (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_hivex_node_add_child (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_hivex_node_delete_child (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_hivex_node_set_value (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_xfs_repair (PyObject *self, PyObject *args)
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

  if (py_forcelogzero != Py_None) {
    optargs_s.bitmask |= GUESTFS_XFS_REPAIR_FORCELOGZERO_BITMASK;
    optargs_s.forcelogzero = PyLong_AsLong (py_forcelogzero);
    if (PyErr_Occurred ()) goto out;
  }
  if (py_nomodify != Py_None) {
    optargs_s.bitmask |= GUESTFS_XFS_REPAIR_NOMODIFY_BITMASK;
    optargs_s.nomodify = PyLong_AsLong (py_nomodify);
    if (PyErr_Occurred ()) goto out;
  }
  if (py_noprefetch != Py_None) {
    optargs_s.bitmask |= GUESTFS_XFS_REPAIR_NOPREFETCH_BITMASK;
    optargs_s.noprefetch = PyLong_AsLong (py_noprefetch);
    if (PyErr_Occurred ()) goto out;
  }
  if (py_forcegeometry != Py_None) {
    optargs_s.bitmask |= GUESTFS_XFS_REPAIR_FORCEGEOMETRY_BITMASK;
    optargs_s.forcegeometry = PyLong_AsLong (py_forcegeometry);
    if (PyErr_Occurred ()) goto out;
  }
  if (py_maxmem != Py_None) {
    optargs_s.bitmask |= GUESTFS_XFS_REPAIR_MAXMEM_BITMASK;
    optargs_s.maxmem = PyLong_AsLongLong (py_maxmem);
    if (PyErr_Occurred ()) goto out;
  }
  if (py_ihashsize != Py_None) {
    optargs_s.bitmask |= GUESTFS_XFS_REPAIR_IHASHSIZE_BITMASK;
    optargs_s.ihashsize = PyLong_AsLongLong (py_ihashsize);
    if (PyErr_Occurred ()) goto out;
  }
  if (py_bhashsize != Py_None) {
    optargs_s.bitmask |= GUESTFS_XFS_REPAIR_BHASHSIZE_BITMASK;
    optargs_s.bhashsize = PyLong_AsLongLong (py_bhashsize);
    if (PyErr_Occurred ()) goto out;
  }
  if (py_agstride != Py_None) {
    optargs_s.bitmask |= GUESTFS_XFS_REPAIR_AGSTRIDE_BITMASK;
    optargs_s.agstride = PyLong_AsLongLong (py_agstride);
    if (PyErr_Occurred ()) goto out;
  }
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_rm_f (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_mke2fs (PyObject *self, PyObject *args)
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

  if (py_blockscount != Py_None) {
    optargs_s.bitmask |= GUESTFS_MKE2FS_BLOCKSCOUNT_BITMASK;
    optargs_s.blockscount = PyLong_AsLongLong (py_blockscount);
    if (PyErr_Occurred ()) goto out;
  }
  if (py_blocksize != Py_None) {
    optargs_s.bitmask |= GUESTFS_MKE2FS_BLOCKSIZE_BITMASK;
    optargs_s.blocksize = PyLong_AsLongLong (py_blocksize);
    if (PyErr_Occurred ()) goto out;
  }
  if (py_fragsize != Py_None) {
    optargs_s.bitmask |= GUESTFS_MKE2FS_FRAGSIZE_BITMASK;
    optargs_s.fragsize = PyLong_AsLongLong (py_fragsize);
    if (PyErr_Occurred ()) goto out;
  }
  if (py_blockspergroup != Py_None) {
    optargs_s.bitmask |= GUESTFS_MKE2FS_BLOCKSPERGROUP_BITMASK;
    optargs_s.blockspergroup = PyLong_AsLongLong (py_blockspergroup);
    if (PyErr_Occurred ()) goto out;
  }
  if (py_numberofgroups != Py_None) {
    optargs_s.bitmask |= GUESTFS_MKE2FS_NUMBEROFGROUPS_BITMASK;
    optargs_s.numberofgroups = PyLong_AsLongLong (py_numberofgroups);
    if (PyErr_Occurred ()) goto out;
  }
  if (py_bytesperinode != Py_None) {
    optargs_s.bitmask |= GUESTFS_MKE2FS_BYTESPERINODE_BITMASK;
    optargs_s.bytesperinode = PyLong_AsLongLong (py_bytesperinode);
    if (PyErr_Occurred ()) goto out;
  }
  if (py_inodesize != Py_None) {
    optargs_s.bitmask |= GUESTFS_MKE2FS_INODESIZE_BITMASK;
    optargs_s.inodesize = PyLong_AsLongLong (py_inodesize);
    if (PyErr_Occurred ()) goto out;
  }
  if (py_journalsize != Py_None) {
    optargs_s.bitmask |= GUESTFS_MKE2FS_JOURNALSIZE_BITMASK;
    optargs_s.journalsize = PyLong_AsLongLong (py_journalsize);
    if (PyErr_Occurred ()) goto out;
  }
  if (py_numberofinodes != Py_None) {
    optargs_s.bitmask |= GUESTFS_MKE2FS_NUMBEROFINODES_BITMASK;
    optargs_s.numberofinodes = PyLong_AsLongLong (py_numberofinodes);
    if (PyErr_Occurred ()) goto out;
  }
  if (py_stridesize != Py_None) {
    optargs_s.bitmask |= GUESTFS_MKE2FS_STRIDESIZE_BITMASK;
    optargs_s.stridesize = PyLong_AsLongLong (py_stridesize);
    if (PyErr_Occurred ()) goto out;
  }
  if (py_stripewidth != Py_None) {
    optargs_s.bitmask |= GUESTFS_MKE2FS_STRIPEWIDTH_BITMASK;
    optargs_s.stripewidth = PyLong_AsLongLong (py_stripewidth);
    if (PyErr_Occurred ()) goto out;
  }
  if (py_maxonlineresize != Py_None) {
    optargs_s.bitmask |= GUESTFS_MKE2FS_MAXONLINERESIZE_BITMASK;
    optargs_s.maxonlineresize = PyLong_AsLongLong (py_maxonlineresize);
    if (PyErr_Occurred ()) goto out;
  }
  if (py_reservedblockspercentage != Py_None) {
    optargs_s.bitmask |= GUESTFS_MKE2FS_RESERVEDBLOCKSPERCENTAGE_BITMASK;
    optargs_s.reservedblockspercentage = PyLong_AsLong (py_reservedblockspercentage);
    if (PyErr_Occurred ()) goto out;
  }
  if (py_mmpupdateinterval != Py_None) {
    optargs_s.bitmask |= GUESTFS_MKE2FS_MMPUPDATEINTERVAL_BITMASK;
    optargs_s.mmpupdateinterval = PyLong_AsLong (py_mmpupdateinterval);
    if (PyErr_Occurred ()) goto out;
  }
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
  if (py_forcecreate != Py_None) {
    optargs_s.bitmask |= GUESTFS_MKE2FS_FORCECREATE_BITMASK;
    optargs_s.forcecreate = PyLong_AsLong (py_forcecreate);
    if (PyErr_Occurred ()) goto out;
  }
  if (py_writesbandgrouponly != Py_None) {
    optargs_s.bitmask |= GUESTFS_MKE2FS_WRITESBANDGROUPONLY_BITMASK;
    optargs_s.writesbandgrouponly = PyLong_AsLong (py_writesbandgrouponly);
    if (PyErr_Occurred ()) goto out;
  }
  if (py_lazyitableinit != Py_None) {
    optargs_s.bitmask |= GUESTFS_MKE2FS_LAZYITABLEINIT_BITMASK;
    optargs_s.lazyitableinit = PyLong_AsLong (py_lazyitableinit);
    if (PyErr_Occurred ()) goto out;
  }
  if (py_lazyjournalinit != Py_None) {
    optargs_s.bitmask |= GUESTFS_MKE2FS_LAZYJOURNALINIT_BITMASK;
    optargs_s.lazyjournalinit = PyLong_AsLong (py_lazyjournalinit);
    if (PyErr_Occurred ()) goto out;
  }
  if (py_testfs != Py_None) {
    optargs_s.bitmask |= GUESTFS_MKE2FS_TESTFS_BITMASK;
    optargs_s.testfs = PyLong_AsLong (py_testfs);
    if (PyErr_Occurred ()) goto out;
  }
  if (py_discard != Py_None) {
    optargs_s.bitmask |= GUESTFS_MKE2FS_DISCARD_BITMASK;
    optargs_s.discard = PyLong_AsLong (py_discard);
    if (PyErr_Occurred ()) goto out;
  }
  if (py_quotatype != Py_None) {
    optargs_s.bitmask |= GUESTFS_MKE2FS_QUOTATYPE_BITMASK;
    optargs_s.quotatype = PyLong_AsLong (py_quotatype);
    if (PyErr_Occurred ()) goto out;
  }
  if (py_extent != Py_None) {
    optargs_s.bitmask |= GUESTFS_MKE2FS_EXTENT_BITMASK;
    optargs_s.extent = PyLong_AsLong (py_extent);
    if (PyErr_Occurred ()) goto out;
  }
  if (py_filetype != Py_None) {
    optargs_s.bitmask |= GUESTFS_MKE2FS_FILETYPE_BITMASK;
    optargs_s.filetype = PyLong_AsLong (py_filetype);
    if (PyErr_Occurred ()) goto out;
  }
  if (py_flexbg != Py_None) {
    optargs_s.bitmask |= GUESTFS_MKE2FS_FLEXBG_BITMASK;
    optargs_s.flexbg = PyLong_AsLong (py_flexbg);
    if (PyErr_Occurred ()) goto out;
  }
  if (py_hasjournal != Py_None) {
    optargs_s.bitmask |= GUESTFS_MKE2FS_HASJOURNAL_BITMASK;
    optargs_s.hasjournal = PyLong_AsLong (py_hasjournal);
    if (PyErr_Occurred ()) goto out;
  }
  if (py_journaldev != Py_None) {
    optargs_s.bitmask |= GUESTFS_MKE2FS_JOURNALDEV_BITMASK;
    optargs_s.journaldev = PyLong_AsLong (py_journaldev);
    if (PyErr_Occurred ()) goto out;
  }
  if (py_largefile != Py_None) {
    optargs_s.bitmask |= GUESTFS_MKE2FS_LARGEFILE_BITMASK;
    optargs_s.largefile = PyLong_AsLong (py_largefile);
    if (PyErr_Occurred ()) goto out;
  }
  if (py_quota != Py_None) {
    optargs_s.bitmask |= GUESTFS_MKE2FS_QUOTA_BITMASK;
    optargs_s.quota = PyLong_AsLong (py_quota);
    if (PyErr_Occurred ()) goto out;
  }
  if (py_resizeinode != Py_None) {
    optargs_s.bitmask |= GUESTFS_MKE2FS_RESIZEINODE_BITMASK;
    optargs_s.resizeinode = PyLong_AsLong (py_resizeinode);
    if (PyErr_Occurred ()) goto out;
  }
  if (py_sparsesuper != Py_None) {
    optargs_s.bitmask |= GUESTFS_MKE2FS_SPARSESUPER_BITMASK;
    optargs_s.sparsesuper = PyLong_AsLong (py_sparsesuper);
    if (PyErr_Occurred ()) goto out;
  }
  if (py_uninitbg != Py_None) {
    optargs_s.bitmask |= GUESTFS_MKE2FS_UNINITBG_BITMASK;
    optargs_s.uninitbg = PyLong_AsLong (py_uninitbg);
    if (PyErr_Occurred ()) goto out;
  }

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

 out:
  return py_r;
}

static PyObject *
py_guestfs_list_disk_labels (PyObject *self, PyObject *args)
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
  guestfs___free_string_list (r);

 out:
  return py_r;
}

static PyObject *
py_guestfs_mktemp (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_mklost_and_found (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_acl_get_file (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_acl_set_file (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_acl_delete_def_file (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_cap_get_file (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_cap_set_file (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_list_ldm_volumes (PyObject *self, PyObject *args)
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
  guestfs___free_string_list (r);

 out:
  return py_r;
}

static PyObject *
py_guestfs_list_ldm_partitions (PyObject *self, PyObject *args)
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
  guestfs___free_string_list (r);

 out:
  return py_r;
}

static PyObject *
py_guestfs_ldmtool_create_all (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_ldmtool_remove_all (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_ldmtool_scan (PyObject *self, PyObject *args)
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
  guestfs___free_string_list (r);

 out:
  return py_r;
}

static PyObject *
py_guestfs_ldmtool_scan_devices (PyObject *self, PyObject *args)
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
  guestfs___free_string_list (r);

 out:
  free (devices);
  return py_r;
}

static PyObject *
py_guestfs_ldmtool_diskgroup_name (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_ldmtool_diskgroup_volumes (PyObject *self, PyObject *args)
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
  guestfs___free_string_list (r);

 out:
  return py_r;
}

static PyObject *
py_guestfs_ldmtool_diskgroup_disks (PyObject *self, PyObject *args)
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
  guestfs___free_string_list (r);

 out:
  return py_r;
}

static PyObject *
py_guestfs_ldmtool_volume_type (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_ldmtool_volume_hint (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_ldmtool_volume_partitions (PyObject *self, PyObject *args)
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
  guestfs___free_string_list (r);

 out:
  return py_r;
}

static PyObject *
py_guestfs_part_set_gpt_type (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_part_get_gpt_type (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_rename (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_is_whole_device (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_feature_available (PyObject *self, PyObject *args)
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

 out:
  free (groups);
  return py_r;
}

static PyObject *
py_guestfs_syslinux (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_extlinux (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyObject *
py_guestfs_cp_r (PyObject *self, PyObject *args)
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

 out:
  return py_r;
}

static PyMethodDef methods[] = {
  { (char *) "create", py_guestfs_create, METH_VARARGS, NULL },
  { (char *) "close", py_guestfs_close, METH_VARARGS, NULL },
  { (char *) "set_event_callback",
    py_guestfs_set_event_callback, METH_VARARGS, NULL },
  { (char *) "delete_event_callback",
    py_guestfs_delete_event_callback, METH_VARARGS, NULL },
  { (char *) "event_to_string",
    py_guestfs_event_to_string, METH_VARARGS, NULL },
  { (char *) "internal_test", py_guestfs_internal_test, METH_VARARGS, NULL },
  { (char *) "internal_test_only_optargs", py_guestfs_internal_test_only_optargs, METH_VARARGS, NULL },
  { (char *) "internal_test_63_optargs", py_guestfs_internal_test_63_optargs, METH_VARARGS, NULL },
  { (char *) "internal_test_rint", py_guestfs_internal_test_rint, METH_VARARGS, NULL },
  { (char *) "internal_test_rinterr", py_guestfs_internal_test_rinterr, METH_VARARGS, NULL },
  { (char *) "internal_test_rint64", py_guestfs_internal_test_rint64, METH_VARARGS, NULL },
  { (char *) "internal_test_rint64err", py_guestfs_internal_test_rint64err, METH_VARARGS, NULL },
  { (char *) "internal_test_rbool", py_guestfs_internal_test_rbool, METH_VARARGS, NULL },
  { (char *) "internal_test_rboolerr", py_guestfs_internal_test_rboolerr, METH_VARARGS, NULL },
  { (char *) "internal_test_rconststring", py_guestfs_internal_test_rconststring, METH_VARARGS, NULL },
  { (char *) "internal_test_rconststringerr", py_guestfs_internal_test_rconststringerr, METH_VARARGS, NULL },
  { (char *) "internal_test_rconstoptstring", py_guestfs_internal_test_rconstoptstring, METH_VARARGS, NULL },
  { (char *) "internal_test_rconstoptstringerr", py_guestfs_internal_test_rconstoptstringerr, METH_VARARGS, NULL },
  { (char *) "internal_test_rstring", py_guestfs_internal_test_rstring, METH_VARARGS, NULL },
  { (char *) "internal_test_rstringerr", py_guestfs_internal_test_rstringerr, METH_VARARGS, NULL },
  { (char *) "internal_test_rstringlist", py_guestfs_internal_test_rstringlist, METH_VARARGS, NULL },
  { (char *) "internal_test_rstringlisterr", py_guestfs_internal_test_rstringlisterr, METH_VARARGS, NULL },
  { (char *) "internal_test_rstruct", py_guestfs_internal_test_rstruct, METH_VARARGS, NULL },
  { (char *) "internal_test_rstructerr", py_guestfs_internal_test_rstructerr, METH_VARARGS, NULL },
  { (char *) "internal_test_rstructlist", py_guestfs_internal_test_rstructlist, METH_VARARGS, NULL },
  { (char *) "internal_test_rstructlisterr", py_guestfs_internal_test_rstructlisterr, METH_VARARGS, NULL },
  { (char *) "internal_test_rhashtable", py_guestfs_internal_test_rhashtable, METH_VARARGS, NULL },
  { (char *) "internal_test_rhashtableerr", py_guestfs_internal_test_rhashtableerr, METH_VARARGS, NULL },
  { (char *) "internal_test_rbufferout", py_guestfs_internal_test_rbufferout, METH_VARARGS, NULL },
  { (char *) "internal_test_rbufferouterr", py_guestfs_internal_test_rbufferouterr, METH_VARARGS, NULL },
  { (char *) "internal_test_set_output", py_guestfs_internal_test_set_output, METH_VARARGS, NULL },
  { (char *) "internal_test_close_output", py_guestfs_internal_test_close_output, METH_VARARGS, NULL },
  { (char *) "launch", py_guestfs_launch, METH_VARARGS, NULL },
  { (char *) "wait_ready", py_guestfs_wait_ready, METH_VARARGS, NULL },
  { (char *) "kill_subprocess", py_guestfs_kill_subprocess, METH_VARARGS, NULL },
  { (char *) "add_cdrom", py_guestfs_add_cdrom, METH_VARARGS, NULL },
  { (char *) "add_drive_ro", py_guestfs_add_drive_ro, METH_VARARGS, NULL },
  { (char *) "config", py_guestfs_config, METH_VARARGS, NULL },
  { (char *) "set_qemu", py_guestfs_set_qemu, METH_VARARGS, NULL },
  { (char *) "get_qemu", py_guestfs_get_qemu, METH_VARARGS, NULL },
  { (char *) "set_path", py_guestfs_set_path, METH_VARARGS, NULL },
  { (char *) "get_path", py_guestfs_get_path, METH_VARARGS, NULL },
  { (char *) "set_append", py_guestfs_set_append, METH_VARARGS, NULL },
  { (char *) "get_append", py_guestfs_get_append, METH_VARARGS, NULL },
  { (char *) "set_autosync", py_guestfs_set_autosync, METH_VARARGS, NULL },
  { (char *) "get_autosync", py_guestfs_get_autosync, METH_VARARGS, NULL },
  { (char *) "set_verbose", py_guestfs_set_verbose, METH_VARARGS, NULL },
  { (char *) "get_verbose", py_guestfs_get_verbose, METH_VARARGS, NULL },
  { (char *) "is_ready", py_guestfs_is_ready, METH_VARARGS, NULL },
  { (char *) "is_config", py_guestfs_is_config, METH_VARARGS, NULL },
  { (char *) "is_launching", py_guestfs_is_launching, METH_VARARGS, NULL },
  { (char *) "is_busy", py_guestfs_is_busy, METH_VARARGS, NULL },
  { (char *) "get_state", py_guestfs_get_state, METH_VARARGS, NULL },
  { (char *) "set_memsize", py_guestfs_set_memsize, METH_VARARGS, NULL },
  { (char *) "get_memsize", py_guestfs_get_memsize, METH_VARARGS, NULL },
  { (char *) "get_pid", py_guestfs_get_pid, METH_VARARGS, NULL },
  { (char *) "version", py_guestfs_version, METH_VARARGS, NULL },
  { (char *) "set_selinux", py_guestfs_set_selinux, METH_VARARGS, NULL },
  { (char *) "get_selinux", py_guestfs_get_selinux, METH_VARARGS, NULL },
  { (char *) "set_trace", py_guestfs_set_trace, METH_VARARGS, NULL },
  { (char *) "get_trace", py_guestfs_get_trace, METH_VARARGS, NULL },
  { (char *) "set_direct", py_guestfs_set_direct, METH_VARARGS, NULL },
  { (char *) "get_direct", py_guestfs_get_direct, METH_VARARGS, NULL },
  { (char *) "set_recovery_proc", py_guestfs_set_recovery_proc, METH_VARARGS, NULL },
  { (char *) "get_recovery_proc", py_guestfs_get_recovery_proc, METH_VARARGS, NULL },
  { (char *) "add_drive_with_if", py_guestfs_add_drive_with_if, METH_VARARGS, NULL },
  { (char *) "add_drive_ro_with_if", py_guestfs_add_drive_ro_with_if, METH_VARARGS, NULL },
  { (char *) "file_architecture", py_guestfs_file_architecture, METH_VARARGS, NULL },
  { (char *) "inspect_os", py_guestfs_inspect_os, METH_VARARGS, NULL },
  { (char *) "inspect_get_type", py_guestfs_inspect_get_type, METH_VARARGS, NULL },
  { (char *) "inspect_get_arch", py_guestfs_inspect_get_arch, METH_VARARGS, NULL },
  { (char *) "inspect_get_distro", py_guestfs_inspect_get_distro, METH_VARARGS, NULL },
  { (char *) "inspect_get_major_version", py_guestfs_inspect_get_major_version, METH_VARARGS, NULL },
  { (char *) "inspect_get_minor_version", py_guestfs_inspect_get_minor_version, METH_VARARGS, NULL },
  { (char *) "inspect_get_product_name", py_guestfs_inspect_get_product_name, METH_VARARGS, NULL },
  { (char *) "inspect_get_mountpoints", py_guestfs_inspect_get_mountpoints, METH_VARARGS, NULL },
  { (char *) "inspect_get_filesystems", py_guestfs_inspect_get_filesystems, METH_VARARGS, NULL },
  { (char *) "set_network", py_guestfs_set_network, METH_VARARGS, NULL },
  { (char *) "get_network", py_guestfs_get_network, METH_VARARGS, NULL },
  { (char *) "list_filesystems", py_guestfs_list_filesystems, METH_VARARGS, NULL },
  { (char *) "add_drive", py_guestfs_add_drive, METH_VARARGS, NULL },
  { (char *) "inspect_get_windows_systemroot", py_guestfs_inspect_get_windows_systemroot, METH_VARARGS, NULL },
  { (char *) "inspect_get_roots", py_guestfs_inspect_get_roots, METH_VARARGS, NULL },
  { (char *) "debug_drives", py_guestfs_debug_drives, METH_VARARGS, NULL },
  { (char *) "add_domain", py_guestfs_add_domain, METH_VARARGS, NULL },
  { (char *) "inspect_get_package_format", py_guestfs_inspect_get_package_format, METH_VARARGS, NULL },
  { (char *) "inspect_get_package_management", py_guestfs_inspect_get_package_management, METH_VARARGS, NULL },
  { (char *) "inspect_list_applications", py_guestfs_inspect_list_applications, METH_VARARGS, NULL },
  { (char *) "inspect_list_applications2", py_guestfs_inspect_list_applications2, METH_VARARGS, NULL },
  { (char *) "inspect_get_hostname", py_guestfs_inspect_get_hostname, METH_VARARGS, NULL },
  { (char *) "inspect_get_format", py_guestfs_inspect_get_format, METH_VARARGS, NULL },
  { (char *) "inspect_is_live", py_guestfs_inspect_is_live, METH_VARARGS, NULL },
  { (char *) "inspect_is_netinst", py_guestfs_inspect_is_netinst, METH_VARARGS, NULL },
  { (char *) "inspect_is_multipart", py_guestfs_inspect_is_multipart, METH_VARARGS, NULL },
  { (char *) "set_attach_method", py_guestfs_set_attach_method, METH_VARARGS, NULL },
  { (char *) "get_attach_method", py_guestfs_get_attach_method, METH_VARARGS, NULL },
  { (char *) "set_backend", py_guestfs_set_backend, METH_VARARGS, NULL },
  { (char *) "get_backend", py_guestfs_get_backend, METH_VARARGS, NULL },
  { (char *) "inspect_get_product_variant", py_guestfs_inspect_get_product_variant, METH_VARARGS, NULL },
  { (char *) "inspect_get_windows_current_control_set", py_guestfs_inspect_get_windows_current_control_set, METH_VARARGS, NULL },
  { (char *) "inspect_get_drive_mappings", py_guestfs_inspect_get_drive_mappings, METH_VARARGS, NULL },
  { (char *) "inspect_get_icon", py_guestfs_inspect_get_icon, METH_VARARGS, NULL },
  { (char *) "set_pgroup", py_guestfs_set_pgroup, METH_VARARGS, NULL },
  { (char *) "get_pgroup", py_guestfs_get_pgroup, METH_VARARGS, NULL },
  { (char *) "set_smp", py_guestfs_set_smp, METH_VARARGS, NULL },
  { (char *) "get_smp", py_guestfs_get_smp, METH_VARARGS, NULL },
  { (char *) "mount_local", py_guestfs_mount_local, METH_VARARGS, NULL },
  { (char *) "mount_local_run", py_guestfs_mount_local_run, METH_VARARGS, NULL },
  { (char *) "umount_local", py_guestfs_umount_local, METH_VARARGS, NULL },
  { (char *) "max_disks", py_guestfs_max_disks, METH_VARARGS, NULL },
  { (char *) "canonical_device_name", py_guestfs_canonical_device_name, METH_VARARGS, NULL },
  { (char *) "shutdown", py_guestfs_shutdown, METH_VARARGS, NULL },
  { (char *) "cat", py_guestfs_cat, METH_VARARGS, NULL },
  { (char *) "find", py_guestfs_find, METH_VARARGS, NULL },
  { (char *) "read_file", py_guestfs_read_file, METH_VARARGS, NULL },
  { (char *) "read_lines", py_guestfs_read_lines, METH_VARARGS, NULL },
  { (char *) "write", py_guestfs_write, METH_VARARGS, NULL },
  { (char *) "write_append", py_guestfs_write_append, METH_VARARGS, NULL },
  { (char *) "lstatlist", py_guestfs_lstatlist, METH_VARARGS, NULL },
  { (char *) "lxattrlist", py_guestfs_lxattrlist, METH_VARARGS, NULL },
  { (char *) "readlinklist", py_guestfs_readlinklist, METH_VARARGS, NULL },
  { (char *) "ls", py_guestfs_ls, METH_VARARGS, NULL },
  { (char *) "hivex_value_utf8", py_guestfs_hivex_value_utf8, METH_VARARGS, NULL },
  { (char *) "disk_format", py_guestfs_disk_format, METH_VARARGS, NULL },
  { (char *) "disk_virtual_size", py_guestfs_disk_virtual_size, METH_VARARGS, NULL },
  { (char *) "disk_has_backing_file", py_guestfs_disk_has_backing_file, METH_VARARGS, NULL },
  { (char *) "remove_drive", py_guestfs_remove_drive, METH_VARARGS, NULL },
  { (char *) "set_libvirt_supported_credentials", py_guestfs_set_libvirt_supported_credentials, METH_VARARGS, NULL },
  { (char *) "get_libvirt_requested_credentials", py_guestfs_get_libvirt_requested_credentials, METH_VARARGS, NULL },
  { (char *) "get_libvirt_requested_credential_prompt", py_guestfs_get_libvirt_requested_credential_prompt, METH_VARARGS, NULL },
  { (char *) "get_libvirt_requested_credential_challenge", py_guestfs_get_libvirt_requested_credential_challenge, METH_VARARGS, NULL },
  { (char *) "get_libvirt_requested_credential_defresult", py_guestfs_get_libvirt_requested_credential_defresult, METH_VARARGS, NULL },
  { (char *) "set_libvirt_requested_credential", py_guestfs_set_libvirt_requested_credential, METH_VARARGS, NULL },
  { (char *) "parse_environment", py_guestfs_parse_environment, METH_VARARGS, NULL },
  { (char *) "parse_environment_list", py_guestfs_parse_environment_list, METH_VARARGS, NULL },
  { (char *) "set_tmpdir", py_guestfs_set_tmpdir, METH_VARARGS, NULL },
  { (char *) "get_tmpdir", py_guestfs_get_tmpdir, METH_VARARGS, NULL },
  { (char *) "set_cachedir", py_guestfs_set_cachedir, METH_VARARGS, NULL },
  { (char *) "get_cachedir", py_guestfs_get_cachedir, METH_VARARGS, NULL },
  { (char *) "user_cancel", py_guestfs_user_cancel, METH_VARARGS, NULL },
  { (char *) "set_program", py_guestfs_set_program, METH_VARARGS, NULL },
  { (char *) "get_program", py_guestfs_get_program, METH_VARARGS, NULL },
  { (char *) "mount", py_guestfs_mount, METH_VARARGS, NULL },
  { (char *) "sync", py_guestfs_sync, METH_VARARGS, NULL },
  { (char *) "touch", py_guestfs_touch, METH_VARARGS, NULL },
  { (char *) "ll", py_guestfs_ll, METH_VARARGS, NULL },
  { (char *) "list_devices", py_guestfs_list_devices, METH_VARARGS, NULL },
  { (char *) "list_partitions", py_guestfs_list_partitions, METH_VARARGS, NULL },
  { (char *) "pvs", py_guestfs_pvs, METH_VARARGS, NULL },
  { (char *) "vgs", py_guestfs_vgs, METH_VARARGS, NULL },
  { (char *) "lvs", py_guestfs_lvs, METH_VARARGS, NULL },
  { (char *) "pvs_full", py_guestfs_pvs_full, METH_VARARGS, NULL },
  { (char *) "vgs_full", py_guestfs_vgs_full, METH_VARARGS, NULL },
  { (char *) "lvs_full", py_guestfs_lvs_full, METH_VARARGS, NULL },
  { (char *) "aug_init", py_guestfs_aug_init, METH_VARARGS, NULL },
  { (char *) "aug_close", py_guestfs_aug_close, METH_VARARGS, NULL },
  { (char *) "aug_defvar", py_guestfs_aug_defvar, METH_VARARGS, NULL },
  { (char *) "aug_defnode", py_guestfs_aug_defnode, METH_VARARGS, NULL },
  { (char *) "aug_get", py_guestfs_aug_get, METH_VARARGS, NULL },
  { (char *) "aug_set", py_guestfs_aug_set, METH_VARARGS, NULL },
  { (char *) "aug_insert", py_guestfs_aug_insert, METH_VARARGS, NULL },
  { (char *) "aug_rm", py_guestfs_aug_rm, METH_VARARGS, NULL },
  { (char *) "aug_mv", py_guestfs_aug_mv, METH_VARARGS, NULL },
  { (char *) "aug_match", py_guestfs_aug_match, METH_VARARGS, NULL },
  { (char *) "aug_save", py_guestfs_aug_save, METH_VARARGS, NULL },
  { (char *) "aug_load", py_guestfs_aug_load, METH_VARARGS, NULL },
  { (char *) "aug_ls", py_guestfs_aug_ls, METH_VARARGS, NULL },
  { (char *) "rm", py_guestfs_rm, METH_VARARGS, NULL },
  { (char *) "rmdir", py_guestfs_rmdir, METH_VARARGS, NULL },
  { (char *) "rm_rf", py_guestfs_rm_rf, METH_VARARGS, NULL },
  { (char *) "mkdir", py_guestfs_mkdir, METH_VARARGS, NULL },
  { (char *) "mkdir_p", py_guestfs_mkdir_p, METH_VARARGS, NULL },
  { (char *) "chmod", py_guestfs_chmod, METH_VARARGS, NULL },
  { (char *) "chown", py_guestfs_chown, METH_VARARGS, NULL },
  { (char *) "exists", py_guestfs_exists, METH_VARARGS, NULL },
  { (char *) "is_file", py_guestfs_is_file, METH_VARARGS, NULL },
  { (char *) "is_dir", py_guestfs_is_dir, METH_VARARGS, NULL },
  { (char *) "pvcreate", py_guestfs_pvcreate, METH_VARARGS, NULL },
  { (char *) "vgcreate", py_guestfs_vgcreate, METH_VARARGS, NULL },
  { (char *) "lvcreate", py_guestfs_lvcreate, METH_VARARGS, NULL },
  { (char *) "sfdisk", py_guestfs_sfdisk, METH_VARARGS, NULL },
  { (char *) "write_file", py_guestfs_write_file, METH_VARARGS, NULL },
  { (char *) "umount", py_guestfs_umount, METH_VARARGS, NULL },
  { (char *) "mounts", py_guestfs_mounts, METH_VARARGS, NULL },
  { (char *) "umount_all", py_guestfs_umount_all, METH_VARARGS, NULL },
  { (char *) "lvm_remove_all", py_guestfs_lvm_remove_all, METH_VARARGS, NULL },
  { (char *) "file", py_guestfs_file, METH_VARARGS, NULL },
  { (char *) "command", py_guestfs_command, METH_VARARGS, NULL },
  { (char *) "command_lines", py_guestfs_command_lines, METH_VARARGS, NULL },
  { (char *) "stat", py_guestfs_stat, METH_VARARGS, NULL },
  { (char *) "lstat", py_guestfs_lstat, METH_VARARGS, NULL },
  { (char *) "statvfs", py_guestfs_statvfs, METH_VARARGS, NULL },
  { (char *) "tune2fs_l", py_guestfs_tune2fs_l, METH_VARARGS, NULL },
  { (char *) "blockdev_setro", py_guestfs_blockdev_setro, METH_VARARGS, NULL },
  { (char *) "blockdev_setrw", py_guestfs_blockdev_setrw, METH_VARARGS, NULL },
  { (char *) "blockdev_getro", py_guestfs_blockdev_getro, METH_VARARGS, NULL },
  { (char *) "blockdev_getss", py_guestfs_blockdev_getss, METH_VARARGS, NULL },
  { (char *) "blockdev_getbsz", py_guestfs_blockdev_getbsz, METH_VARARGS, NULL },
  { (char *) "blockdev_setbsz", py_guestfs_blockdev_setbsz, METH_VARARGS, NULL },
  { (char *) "blockdev_getsz", py_guestfs_blockdev_getsz, METH_VARARGS, NULL },
  { (char *) "blockdev_getsize64", py_guestfs_blockdev_getsize64, METH_VARARGS, NULL },
  { (char *) "blockdev_flushbufs", py_guestfs_blockdev_flushbufs, METH_VARARGS, NULL },
  { (char *) "blockdev_rereadpt", py_guestfs_blockdev_rereadpt, METH_VARARGS, NULL },
  { (char *) "upload", py_guestfs_upload, METH_VARARGS, NULL },
  { (char *) "download", py_guestfs_download, METH_VARARGS, NULL },
  { (char *) "checksum", py_guestfs_checksum, METH_VARARGS, NULL },
  { (char *) "tar_in", py_guestfs_tar_in, METH_VARARGS, NULL },
  { (char *) "tar_out", py_guestfs_tar_out, METH_VARARGS, NULL },
  { (char *) "tgz_in", py_guestfs_tgz_in, METH_VARARGS, NULL },
  { (char *) "tgz_out", py_guestfs_tgz_out, METH_VARARGS, NULL },
  { (char *) "mount_ro", py_guestfs_mount_ro, METH_VARARGS, NULL },
  { (char *) "mount_options", py_guestfs_mount_options, METH_VARARGS, NULL },
  { (char *) "mount_vfs", py_guestfs_mount_vfs, METH_VARARGS, NULL },
  { (char *) "debug", py_guestfs_debug, METH_VARARGS, NULL },
  { (char *) "lvremove", py_guestfs_lvremove, METH_VARARGS, NULL },
  { (char *) "vgremove", py_guestfs_vgremove, METH_VARARGS, NULL },
  { (char *) "pvremove", py_guestfs_pvremove, METH_VARARGS, NULL },
  { (char *) "set_e2label", py_guestfs_set_e2label, METH_VARARGS, NULL },
  { (char *) "get_e2label", py_guestfs_get_e2label, METH_VARARGS, NULL },
  { (char *) "set_e2uuid", py_guestfs_set_e2uuid, METH_VARARGS, NULL },
  { (char *) "get_e2uuid", py_guestfs_get_e2uuid, METH_VARARGS, NULL },
  { (char *) "fsck", py_guestfs_fsck, METH_VARARGS, NULL },
  { (char *) "zero", py_guestfs_zero, METH_VARARGS, NULL },
  { (char *) "grub_install", py_guestfs_grub_install, METH_VARARGS, NULL },
  { (char *) "cp", py_guestfs_cp, METH_VARARGS, NULL },
  { (char *) "cp_a", py_guestfs_cp_a, METH_VARARGS, NULL },
  { (char *) "mv", py_guestfs_mv, METH_VARARGS, NULL },
  { (char *) "drop_caches", py_guestfs_drop_caches, METH_VARARGS, NULL },
  { (char *) "dmesg", py_guestfs_dmesg, METH_VARARGS, NULL },
  { (char *) "ping_daemon", py_guestfs_ping_daemon, METH_VARARGS, NULL },
  { (char *) "equal", py_guestfs_equal, METH_VARARGS, NULL },
  { (char *) "strings", py_guestfs_strings, METH_VARARGS, NULL },
  { (char *) "strings_e", py_guestfs_strings_e, METH_VARARGS, NULL },
  { (char *) "hexdump", py_guestfs_hexdump, METH_VARARGS, NULL },
  { (char *) "zerofree", py_guestfs_zerofree, METH_VARARGS, NULL },
  { (char *) "pvresize", py_guestfs_pvresize, METH_VARARGS, NULL },
  { (char *) "sfdisk_N", py_guestfs_sfdisk_N, METH_VARARGS, NULL },
  { (char *) "sfdisk_l", py_guestfs_sfdisk_l, METH_VARARGS, NULL },
  { (char *) "sfdisk_kernel_geometry", py_guestfs_sfdisk_kernel_geometry, METH_VARARGS, NULL },
  { (char *) "sfdisk_disk_geometry", py_guestfs_sfdisk_disk_geometry, METH_VARARGS, NULL },
  { (char *) "vg_activate_all", py_guestfs_vg_activate_all, METH_VARARGS, NULL },
  { (char *) "vg_activate", py_guestfs_vg_activate, METH_VARARGS, NULL },
  { (char *) "lvresize", py_guestfs_lvresize, METH_VARARGS, NULL },
  { (char *) "resize2fs", py_guestfs_resize2fs, METH_VARARGS, NULL },
  { (char *) "e2fsck_f", py_guestfs_e2fsck_f, METH_VARARGS, NULL },
  { (char *) "sleep", py_guestfs_sleep, METH_VARARGS, NULL },
  { (char *) "ntfs_3g_probe", py_guestfs_ntfs_3g_probe, METH_VARARGS, NULL },
  { (char *) "sh", py_guestfs_sh, METH_VARARGS, NULL },
  { (char *) "sh_lines", py_guestfs_sh_lines, METH_VARARGS, NULL },
  { (char *) "glob_expand", py_guestfs_glob_expand, METH_VARARGS, NULL },
  { (char *) "scrub_device", py_guestfs_scrub_device, METH_VARARGS, NULL },
  { (char *) "scrub_file", py_guestfs_scrub_file, METH_VARARGS, NULL },
  { (char *) "scrub_freespace", py_guestfs_scrub_freespace, METH_VARARGS, NULL },
  { (char *) "mkdtemp", py_guestfs_mkdtemp, METH_VARARGS, NULL },
  { (char *) "wc_l", py_guestfs_wc_l, METH_VARARGS, NULL },
  { (char *) "wc_w", py_guestfs_wc_w, METH_VARARGS, NULL },
  { (char *) "wc_c", py_guestfs_wc_c, METH_VARARGS, NULL },
  { (char *) "head", py_guestfs_head, METH_VARARGS, NULL },
  { (char *) "head_n", py_guestfs_head_n, METH_VARARGS, NULL },
  { (char *) "tail", py_guestfs_tail, METH_VARARGS, NULL },
  { (char *) "tail_n", py_guestfs_tail_n, METH_VARARGS, NULL },
  { (char *) "df", py_guestfs_df, METH_VARARGS, NULL },
  { (char *) "df_h", py_guestfs_df_h, METH_VARARGS, NULL },
  { (char *) "du", py_guestfs_du, METH_VARARGS, NULL },
  { (char *) "initrd_list", py_guestfs_initrd_list, METH_VARARGS, NULL },
  { (char *) "mount_loop", py_guestfs_mount_loop, METH_VARARGS, NULL },
  { (char *) "mkswap", py_guestfs_mkswap, METH_VARARGS, NULL },
  { (char *) "mkswap_L", py_guestfs_mkswap_L, METH_VARARGS, NULL },
  { (char *) "mkswap_U", py_guestfs_mkswap_U, METH_VARARGS, NULL },
  { (char *) "mknod", py_guestfs_mknod, METH_VARARGS, NULL },
  { (char *) "mkfifo", py_guestfs_mkfifo, METH_VARARGS, NULL },
  { (char *) "mknod_b", py_guestfs_mknod_b, METH_VARARGS, NULL },
  { (char *) "mknod_c", py_guestfs_mknod_c, METH_VARARGS, NULL },
  { (char *) "umask", py_guestfs_umask, METH_VARARGS, NULL },
  { (char *) "readdir", py_guestfs_readdir, METH_VARARGS, NULL },
  { (char *) "sfdiskM", py_guestfs_sfdiskM, METH_VARARGS, NULL },
  { (char *) "zfile", py_guestfs_zfile, METH_VARARGS, NULL },
  { (char *) "getxattrs", py_guestfs_getxattrs, METH_VARARGS, NULL },
  { (char *) "lgetxattrs", py_guestfs_lgetxattrs, METH_VARARGS, NULL },
  { (char *) "setxattr", py_guestfs_setxattr, METH_VARARGS, NULL },
  { (char *) "lsetxattr", py_guestfs_lsetxattr, METH_VARARGS, NULL },
  { (char *) "removexattr", py_guestfs_removexattr, METH_VARARGS, NULL },
  { (char *) "lremovexattr", py_guestfs_lremovexattr, METH_VARARGS, NULL },
  { (char *) "mountpoints", py_guestfs_mountpoints, METH_VARARGS, NULL },
  { (char *) "mkmountpoint", py_guestfs_mkmountpoint, METH_VARARGS, NULL },
  { (char *) "rmmountpoint", py_guestfs_rmmountpoint, METH_VARARGS, NULL },
  { (char *) "grep", py_guestfs_grep, METH_VARARGS, NULL },
  { (char *) "egrep", py_guestfs_egrep, METH_VARARGS, NULL },
  { (char *) "fgrep", py_guestfs_fgrep, METH_VARARGS, NULL },
  { (char *) "grepi", py_guestfs_grepi, METH_VARARGS, NULL },
  { (char *) "egrepi", py_guestfs_egrepi, METH_VARARGS, NULL },
  { (char *) "fgrepi", py_guestfs_fgrepi, METH_VARARGS, NULL },
  { (char *) "zgrep", py_guestfs_zgrep, METH_VARARGS, NULL },
  { (char *) "zegrep", py_guestfs_zegrep, METH_VARARGS, NULL },
  { (char *) "zfgrep", py_guestfs_zfgrep, METH_VARARGS, NULL },
  { (char *) "zgrepi", py_guestfs_zgrepi, METH_VARARGS, NULL },
  { (char *) "zegrepi", py_guestfs_zegrepi, METH_VARARGS, NULL },
  { (char *) "zfgrepi", py_guestfs_zfgrepi, METH_VARARGS, NULL },
  { (char *) "realpath", py_guestfs_realpath, METH_VARARGS, NULL },
  { (char *) "ln", py_guestfs_ln, METH_VARARGS, NULL },
  { (char *) "ln_f", py_guestfs_ln_f, METH_VARARGS, NULL },
  { (char *) "ln_s", py_guestfs_ln_s, METH_VARARGS, NULL },
  { (char *) "ln_sf", py_guestfs_ln_sf, METH_VARARGS, NULL },
  { (char *) "readlink", py_guestfs_readlink, METH_VARARGS, NULL },
  { (char *) "fallocate", py_guestfs_fallocate, METH_VARARGS, NULL },
  { (char *) "swapon_device", py_guestfs_swapon_device, METH_VARARGS, NULL },
  { (char *) "swapoff_device", py_guestfs_swapoff_device, METH_VARARGS, NULL },
  { (char *) "swapon_file", py_guestfs_swapon_file, METH_VARARGS, NULL },
  { (char *) "swapoff_file", py_guestfs_swapoff_file, METH_VARARGS, NULL },
  { (char *) "swapon_label", py_guestfs_swapon_label, METH_VARARGS, NULL },
  { (char *) "swapoff_label", py_guestfs_swapoff_label, METH_VARARGS, NULL },
  { (char *) "swapon_uuid", py_guestfs_swapon_uuid, METH_VARARGS, NULL },
  { (char *) "swapoff_uuid", py_guestfs_swapoff_uuid, METH_VARARGS, NULL },
  { (char *) "mkswap_file", py_guestfs_mkswap_file, METH_VARARGS, NULL },
  { (char *) "inotify_init", py_guestfs_inotify_init, METH_VARARGS, NULL },
  { (char *) "inotify_add_watch", py_guestfs_inotify_add_watch, METH_VARARGS, NULL },
  { (char *) "inotify_rm_watch", py_guestfs_inotify_rm_watch, METH_VARARGS, NULL },
  { (char *) "inotify_read", py_guestfs_inotify_read, METH_VARARGS, NULL },
  { (char *) "inotify_files", py_guestfs_inotify_files, METH_VARARGS, NULL },
  { (char *) "inotify_close", py_guestfs_inotify_close, METH_VARARGS, NULL },
  { (char *) "setcon", py_guestfs_setcon, METH_VARARGS, NULL },
  { (char *) "getcon", py_guestfs_getcon, METH_VARARGS, NULL },
  { (char *) "mkfs_b", py_guestfs_mkfs_b, METH_VARARGS, NULL },
  { (char *) "mke2journal", py_guestfs_mke2journal, METH_VARARGS, NULL },
  { (char *) "mke2journal_L", py_guestfs_mke2journal_L, METH_VARARGS, NULL },
  { (char *) "mke2journal_U", py_guestfs_mke2journal_U, METH_VARARGS, NULL },
  { (char *) "mke2fs_J", py_guestfs_mke2fs_J, METH_VARARGS, NULL },
  { (char *) "mke2fs_JL", py_guestfs_mke2fs_JL, METH_VARARGS, NULL },
  { (char *) "mke2fs_JU", py_guestfs_mke2fs_JU, METH_VARARGS, NULL },
  { (char *) "modprobe", py_guestfs_modprobe, METH_VARARGS, NULL },
  { (char *) "echo_daemon", py_guestfs_echo_daemon, METH_VARARGS, NULL },
  { (char *) "find0", py_guestfs_find0, METH_VARARGS, NULL },
  { (char *) "case_sensitive_path", py_guestfs_case_sensitive_path, METH_VARARGS, NULL },
  { (char *) "vfs_type", py_guestfs_vfs_type, METH_VARARGS, NULL },
  { (char *) "truncate", py_guestfs_truncate, METH_VARARGS, NULL },
  { (char *) "truncate_size", py_guestfs_truncate_size, METH_VARARGS, NULL },
  { (char *) "utimens", py_guestfs_utimens, METH_VARARGS, NULL },
  { (char *) "mkdir_mode", py_guestfs_mkdir_mode, METH_VARARGS, NULL },
  { (char *) "lchown", py_guestfs_lchown, METH_VARARGS, NULL },
  { (char *) "pread", py_guestfs_pread, METH_VARARGS, NULL },
  { (char *) "part_init", py_guestfs_part_init, METH_VARARGS, NULL },
  { (char *) "part_add", py_guestfs_part_add, METH_VARARGS, NULL },
  { (char *) "part_disk", py_guestfs_part_disk, METH_VARARGS, NULL },
  { (char *) "part_set_bootable", py_guestfs_part_set_bootable, METH_VARARGS, NULL },
  { (char *) "part_set_name", py_guestfs_part_set_name, METH_VARARGS, NULL },
  { (char *) "part_list", py_guestfs_part_list, METH_VARARGS, NULL },
  { (char *) "part_get_parttype", py_guestfs_part_get_parttype, METH_VARARGS, NULL },
  { (char *) "fill", py_guestfs_fill, METH_VARARGS, NULL },
  { (char *) "available", py_guestfs_available, METH_VARARGS, NULL },
  { (char *) "dd", py_guestfs_dd, METH_VARARGS, NULL },
  { (char *) "filesize", py_guestfs_filesize, METH_VARARGS, NULL },
  { (char *) "lvrename", py_guestfs_lvrename, METH_VARARGS, NULL },
  { (char *) "vgrename", py_guestfs_vgrename, METH_VARARGS, NULL },
  { (char *) "initrd_cat", py_guestfs_initrd_cat, METH_VARARGS, NULL },
  { (char *) "pvuuid", py_guestfs_pvuuid, METH_VARARGS, NULL },
  { (char *) "vguuid", py_guestfs_vguuid, METH_VARARGS, NULL },
  { (char *) "lvuuid", py_guestfs_lvuuid, METH_VARARGS, NULL },
  { (char *) "vgpvuuids", py_guestfs_vgpvuuids, METH_VARARGS, NULL },
  { (char *) "vglvuuids", py_guestfs_vglvuuids, METH_VARARGS, NULL },
  { (char *) "copy_size", py_guestfs_copy_size, METH_VARARGS, NULL },
  { (char *) "zero_device", py_guestfs_zero_device, METH_VARARGS, NULL },
  { (char *) "txz_in", py_guestfs_txz_in, METH_VARARGS, NULL },
  { (char *) "txz_out", py_guestfs_txz_out, METH_VARARGS, NULL },
  { (char *) "vgscan", py_guestfs_vgscan, METH_VARARGS, NULL },
  { (char *) "part_del", py_guestfs_part_del, METH_VARARGS, NULL },
  { (char *) "part_get_bootable", py_guestfs_part_get_bootable, METH_VARARGS, NULL },
  { (char *) "part_get_mbr_id", py_guestfs_part_get_mbr_id, METH_VARARGS, NULL },
  { (char *) "part_set_mbr_id", py_guestfs_part_set_mbr_id, METH_VARARGS, NULL },
  { (char *) "checksum_device", py_guestfs_checksum_device, METH_VARARGS, NULL },
  { (char *) "lvresize_free", py_guestfs_lvresize_free, METH_VARARGS, NULL },
  { (char *) "aug_clear", py_guestfs_aug_clear, METH_VARARGS, NULL },
  { (char *) "get_umask", py_guestfs_get_umask, METH_VARARGS, NULL },
  { (char *) "debug_upload", py_guestfs_debug_upload, METH_VARARGS, NULL },
  { (char *) "base64_in", py_guestfs_base64_in, METH_VARARGS, NULL },
  { (char *) "base64_out", py_guestfs_base64_out, METH_VARARGS, NULL },
  { (char *) "checksums_out", py_guestfs_checksums_out, METH_VARARGS, NULL },
  { (char *) "fill_pattern", py_guestfs_fill_pattern, METH_VARARGS, NULL },
  { (char *) "pwrite", py_guestfs_pwrite, METH_VARARGS, NULL },
  { (char *) "resize2fs_size", py_guestfs_resize2fs_size, METH_VARARGS, NULL },
  { (char *) "pvresize_size", py_guestfs_pvresize_size, METH_VARARGS, NULL },
  { (char *) "ntfsresize_size", py_guestfs_ntfsresize_size, METH_VARARGS, NULL },
  { (char *) "available_all_groups", py_guestfs_available_all_groups, METH_VARARGS, NULL },
  { (char *) "fallocate64", py_guestfs_fallocate64, METH_VARARGS, NULL },
  { (char *) "vfs_label", py_guestfs_vfs_label, METH_VARARGS, NULL },
  { (char *) "vfs_uuid", py_guestfs_vfs_uuid, METH_VARARGS, NULL },
  { (char *) "lvm_set_filter", py_guestfs_lvm_set_filter, METH_VARARGS, NULL },
  { (char *) "lvm_clear_filter", py_guestfs_lvm_clear_filter, METH_VARARGS, NULL },
  { (char *) "luks_open", py_guestfs_luks_open, METH_VARARGS, NULL },
  { (char *) "luks_open_ro", py_guestfs_luks_open_ro, METH_VARARGS, NULL },
  { (char *) "luks_close", py_guestfs_luks_close, METH_VARARGS, NULL },
  { (char *) "luks_format", py_guestfs_luks_format, METH_VARARGS, NULL },
  { (char *) "luks_format_cipher", py_guestfs_luks_format_cipher, METH_VARARGS, NULL },
  { (char *) "luks_add_key", py_guestfs_luks_add_key, METH_VARARGS, NULL },
  { (char *) "luks_kill_slot", py_guestfs_luks_kill_slot, METH_VARARGS, NULL },
  { (char *) "is_lv", py_guestfs_is_lv, METH_VARARGS, NULL },
  { (char *) "findfs_uuid", py_guestfs_findfs_uuid, METH_VARARGS, NULL },
  { (char *) "findfs_label", py_guestfs_findfs_label, METH_VARARGS, NULL },
  { (char *) "is_chardev", py_guestfs_is_chardev, METH_VARARGS, NULL },
  { (char *) "is_blockdev", py_guestfs_is_blockdev, METH_VARARGS, NULL },
  { (char *) "is_fifo", py_guestfs_is_fifo, METH_VARARGS, NULL },
  { (char *) "is_symlink", py_guestfs_is_symlink, METH_VARARGS, NULL },
  { (char *) "is_socket", py_guestfs_is_socket, METH_VARARGS, NULL },
  { (char *) "part_to_dev", py_guestfs_part_to_dev, METH_VARARGS, NULL },
  { (char *) "upload_offset", py_guestfs_upload_offset, METH_VARARGS, NULL },
  { (char *) "download_offset", py_guestfs_download_offset, METH_VARARGS, NULL },
  { (char *) "pwrite_device", py_guestfs_pwrite_device, METH_VARARGS, NULL },
  { (char *) "pread_device", py_guestfs_pread_device, METH_VARARGS, NULL },
  { (char *) "lvm_canonical_lv_name", py_guestfs_lvm_canonical_lv_name, METH_VARARGS, NULL },
  { (char *) "mkfs", py_guestfs_mkfs, METH_VARARGS, NULL },
  { (char *) "getxattr", py_guestfs_getxattr, METH_VARARGS, NULL },
  { (char *) "lgetxattr", py_guestfs_lgetxattr, METH_VARARGS, NULL },
  { (char *) "resize2fs_M", py_guestfs_resize2fs_M, METH_VARARGS, NULL },
  { (char *) "is_zero", py_guestfs_is_zero, METH_VARARGS, NULL },
  { (char *) "is_zero_device", py_guestfs_is_zero_device, METH_VARARGS, NULL },
  { (char *) "list_9p", py_guestfs_list_9p, METH_VARARGS, NULL },
  { (char *) "mount_9p", py_guestfs_mount_9p, METH_VARARGS, NULL },
  { (char *) "list_dm_devices", py_guestfs_list_dm_devices, METH_VARARGS, NULL },
  { (char *) "ntfsresize", py_guestfs_ntfsresize, METH_VARARGS, NULL },
  { (char *) "btrfs_filesystem_resize", py_guestfs_btrfs_filesystem_resize, METH_VARARGS, NULL },
  { (char *) "compress_out", py_guestfs_compress_out, METH_VARARGS, NULL },
  { (char *) "compress_device_out", py_guestfs_compress_device_out, METH_VARARGS, NULL },
  { (char *) "part_to_partnum", py_guestfs_part_to_partnum, METH_VARARGS, NULL },
  { (char *) "copy_device_to_device", py_guestfs_copy_device_to_device, METH_VARARGS, NULL },
  { (char *) "copy_device_to_file", py_guestfs_copy_device_to_file, METH_VARARGS, NULL },
  { (char *) "copy_file_to_device", py_guestfs_copy_file_to_device, METH_VARARGS, NULL },
  { (char *) "copy_file_to_file", py_guestfs_copy_file_to_file, METH_VARARGS, NULL },
  { (char *) "tune2fs", py_guestfs_tune2fs, METH_VARARGS, NULL },
  { (char *) "md_create", py_guestfs_md_create, METH_VARARGS, NULL },
  { (char *) "list_md_devices", py_guestfs_list_md_devices, METH_VARARGS, NULL },
  { (char *) "md_detail", py_guestfs_md_detail, METH_VARARGS, NULL },
  { (char *) "md_stop", py_guestfs_md_stop, METH_VARARGS, NULL },
  { (char *) "blkid", py_guestfs_blkid, METH_VARARGS, NULL },
  { (char *) "e2fsck", py_guestfs_e2fsck, METH_VARARGS, NULL },
  { (char *) "llz", py_guestfs_llz, METH_VARARGS, NULL },
  { (char *) "wipefs", py_guestfs_wipefs, METH_VARARGS, NULL },
  { (char *) "ntfsfix", py_guestfs_ntfsfix, METH_VARARGS, NULL },
  { (char *) "ntfsclone_out", py_guestfs_ntfsclone_out, METH_VARARGS, NULL },
  { (char *) "ntfsclone_in", py_guestfs_ntfsclone_in, METH_VARARGS, NULL },
  { (char *) "set_label", py_guestfs_set_label, METH_VARARGS, NULL },
  { (char *) "zero_free_space", py_guestfs_zero_free_space, METH_VARARGS, NULL },
  { (char *) "lvcreate_free", py_guestfs_lvcreate_free, METH_VARARGS, NULL },
  { (char *) "isoinfo_device", py_guestfs_isoinfo_device, METH_VARARGS, NULL },
  { (char *) "isoinfo", py_guestfs_isoinfo, METH_VARARGS, NULL },
  { (char *) "vgmeta", py_guestfs_vgmeta, METH_VARARGS, NULL },
  { (char *) "md_stat", py_guestfs_md_stat, METH_VARARGS, NULL },
  { (char *) "mkfs_btrfs", py_guestfs_mkfs_btrfs, METH_VARARGS, NULL },
  { (char *) "get_e2attrs", py_guestfs_get_e2attrs, METH_VARARGS, NULL },
  { (char *) "set_e2attrs", py_guestfs_set_e2attrs, METH_VARARGS, NULL },
  { (char *) "get_e2generation", py_guestfs_get_e2generation, METH_VARARGS, NULL },
  { (char *) "set_e2generation", py_guestfs_set_e2generation, METH_VARARGS, NULL },
  { (char *) "btrfs_subvolume_snapshot", py_guestfs_btrfs_subvolume_snapshot, METH_VARARGS, NULL },
  { (char *) "btrfs_subvolume_delete", py_guestfs_btrfs_subvolume_delete, METH_VARARGS, NULL },
  { (char *) "btrfs_subvolume_create", py_guestfs_btrfs_subvolume_create, METH_VARARGS, NULL },
  { (char *) "btrfs_subvolume_list", py_guestfs_btrfs_subvolume_list, METH_VARARGS, NULL },
  { (char *) "btrfs_subvolume_set_default", py_guestfs_btrfs_subvolume_set_default, METH_VARARGS, NULL },
  { (char *) "btrfs_filesystem_sync", py_guestfs_btrfs_filesystem_sync, METH_VARARGS, NULL },
  { (char *) "btrfs_filesystem_balance", py_guestfs_btrfs_filesystem_balance, METH_VARARGS, NULL },
  { (char *) "btrfs_device_add", py_guestfs_btrfs_device_add, METH_VARARGS, NULL },
  { (char *) "btrfs_device_delete", py_guestfs_btrfs_device_delete, METH_VARARGS, NULL },
  { (char *) "btrfs_set_seeding", py_guestfs_btrfs_set_seeding, METH_VARARGS, NULL },
  { (char *) "btrfs_fsck", py_guestfs_btrfs_fsck, METH_VARARGS, NULL },
  { (char *) "filesystem_available", py_guestfs_filesystem_available, METH_VARARGS, NULL },
  { (char *) "fstrim", py_guestfs_fstrim, METH_VARARGS, NULL },
  { (char *) "device_index", py_guestfs_device_index, METH_VARARGS, NULL },
  { (char *) "nr_devices", py_guestfs_nr_devices, METH_VARARGS, NULL },
  { (char *) "xfs_info", py_guestfs_xfs_info, METH_VARARGS, NULL },
  { (char *) "pvchange_uuid", py_guestfs_pvchange_uuid, METH_VARARGS, NULL },
  { (char *) "pvchange_uuid_all", py_guestfs_pvchange_uuid_all, METH_VARARGS, NULL },
  { (char *) "vgchange_uuid", py_guestfs_vgchange_uuid, METH_VARARGS, NULL },
  { (char *) "vgchange_uuid_all", py_guestfs_vgchange_uuid_all, METH_VARARGS, NULL },
  { (char *) "utsname", py_guestfs_utsname, METH_VARARGS, NULL },
  { (char *) "xfs_growfs", py_guestfs_xfs_growfs, METH_VARARGS, NULL },
  { (char *) "rsync", py_guestfs_rsync, METH_VARARGS, NULL },
  { (char *) "rsync_in", py_guestfs_rsync_in, METH_VARARGS, NULL },
  { (char *) "rsync_out", py_guestfs_rsync_out, METH_VARARGS, NULL },
  { (char *) "ls0", py_guestfs_ls0, METH_VARARGS, NULL },
  { (char *) "fill_dir", py_guestfs_fill_dir, METH_VARARGS, NULL },
  { (char *) "xfs_admin", py_guestfs_xfs_admin, METH_VARARGS, NULL },
  { (char *) "hivex_open", py_guestfs_hivex_open, METH_VARARGS, NULL },
  { (char *) "hivex_close", py_guestfs_hivex_close, METH_VARARGS, NULL },
  { (char *) "hivex_root", py_guestfs_hivex_root, METH_VARARGS, NULL },
  { (char *) "hivex_node_name", py_guestfs_hivex_node_name, METH_VARARGS, NULL },
  { (char *) "hivex_node_children", py_guestfs_hivex_node_children, METH_VARARGS, NULL },
  { (char *) "hivex_node_get_child", py_guestfs_hivex_node_get_child, METH_VARARGS, NULL },
  { (char *) "hivex_node_parent", py_guestfs_hivex_node_parent, METH_VARARGS, NULL },
  { (char *) "hivex_node_values", py_guestfs_hivex_node_values, METH_VARARGS, NULL },
  { (char *) "hivex_node_get_value", py_guestfs_hivex_node_get_value, METH_VARARGS, NULL },
  { (char *) "hivex_value_key", py_guestfs_hivex_value_key, METH_VARARGS, NULL },
  { (char *) "hivex_value_type", py_guestfs_hivex_value_type, METH_VARARGS, NULL },
  { (char *) "hivex_value_value", py_guestfs_hivex_value_value, METH_VARARGS, NULL },
  { (char *) "hivex_commit", py_guestfs_hivex_commit, METH_VARARGS, NULL },
  { (char *) "hivex_node_add_child", py_guestfs_hivex_node_add_child, METH_VARARGS, NULL },
  { (char *) "hivex_node_delete_child", py_guestfs_hivex_node_delete_child, METH_VARARGS, NULL },
  { (char *) "hivex_node_set_value", py_guestfs_hivex_node_set_value, METH_VARARGS, NULL },
  { (char *) "xfs_repair", py_guestfs_xfs_repair, METH_VARARGS, NULL },
  { (char *) "rm_f", py_guestfs_rm_f, METH_VARARGS, NULL },
  { (char *) "mke2fs", py_guestfs_mke2fs, METH_VARARGS, NULL },
  { (char *) "list_disk_labels", py_guestfs_list_disk_labels, METH_VARARGS, NULL },
  { (char *) "mktemp", py_guestfs_mktemp, METH_VARARGS, NULL },
  { (char *) "mklost_and_found", py_guestfs_mklost_and_found, METH_VARARGS, NULL },
  { (char *) "acl_get_file", py_guestfs_acl_get_file, METH_VARARGS, NULL },
  { (char *) "acl_set_file", py_guestfs_acl_set_file, METH_VARARGS, NULL },
  { (char *) "acl_delete_def_file", py_guestfs_acl_delete_def_file, METH_VARARGS, NULL },
  { (char *) "cap_get_file", py_guestfs_cap_get_file, METH_VARARGS, NULL },
  { (char *) "cap_set_file", py_guestfs_cap_set_file, METH_VARARGS, NULL },
  { (char *) "list_ldm_volumes", py_guestfs_list_ldm_volumes, METH_VARARGS, NULL },
  { (char *) "list_ldm_partitions", py_guestfs_list_ldm_partitions, METH_VARARGS, NULL },
  { (char *) "ldmtool_create_all", py_guestfs_ldmtool_create_all, METH_VARARGS, NULL },
  { (char *) "ldmtool_remove_all", py_guestfs_ldmtool_remove_all, METH_VARARGS, NULL },
  { (char *) "ldmtool_scan", py_guestfs_ldmtool_scan, METH_VARARGS, NULL },
  { (char *) "ldmtool_scan_devices", py_guestfs_ldmtool_scan_devices, METH_VARARGS, NULL },
  { (char *) "ldmtool_diskgroup_name", py_guestfs_ldmtool_diskgroup_name, METH_VARARGS, NULL },
  { (char *) "ldmtool_diskgroup_volumes", py_guestfs_ldmtool_diskgroup_volumes, METH_VARARGS, NULL },
  { (char *) "ldmtool_diskgroup_disks", py_guestfs_ldmtool_diskgroup_disks, METH_VARARGS, NULL },
  { (char *) "ldmtool_volume_type", py_guestfs_ldmtool_volume_type, METH_VARARGS, NULL },
  { (char *) "ldmtool_volume_hint", py_guestfs_ldmtool_volume_hint, METH_VARARGS, NULL },
  { (char *) "ldmtool_volume_partitions", py_guestfs_ldmtool_volume_partitions, METH_VARARGS, NULL },
  { (char *) "part_set_gpt_type", py_guestfs_part_set_gpt_type, METH_VARARGS, NULL },
  { (char *) "part_get_gpt_type", py_guestfs_part_get_gpt_type, METH_VARARGS, NULL },
  { (char *) "rename", py_guestfs_rename, METH_VARARGS, NULL },
  { (char *) "is_whole_device", py_guestfs_is_whole_device, METH_VARARGS, NULL },
  { (char *) "feature_available", py_guestfs_feature_available, METH_VARARGS, NULL },
  { (char *) "syslinux", py_guestfs_syslinux, METH_VARARGS, NULL },
  { (char *) "extlinux", py_guestfs_extlinux, METH_VARARGS, NULL },
  { (char *) "cp_r", py_guestfs_cp_r, METH_VARARGS, NULL },
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
