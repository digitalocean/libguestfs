/* libguestfs generated file
 * WARNING: THIS FILE IS GENERATED FROM THE FOLLOWING FILES:
 *          generator/python.ml
 *          and from the code in the generator/ subdirectory.
 * ANY CHANGES YOU MAKE TO THIS FILE WILL BE LOST.
 *
 * Copyright (C) 2009-2018 Red Hat Inc.
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

#ifdef GUESTFS_HAVE_AUG_CLEAR
PyObject *
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

#ifdef GUESTFS_HAVE_AUG_DEFVAR
PyObject *
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

#ifdef GUESTFS_HAVE_BASE64_IN
PyObject *
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
PyObject *
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

#ifdef GUESTFS_HAVE_BTRFS_BALANCE_RESUME
PyObject *
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

#ifdef GUESTFS_HAVE_BTRFS_FSCK
PyObject *
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

#ifdef GUESTFS_HAVE_BTRFS_QGROUP_SHOW
PyObject *
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

  py_r = guestfs_int_py_put_btrfsqgroup_list (r);
  guestfs_free_btrfsqgroup_list (r);
  if (py_r == NULL) goto out;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_BTRFS_RESCUE_CHUNK_RECOVER
PyObject *
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

#ifdef GUESTFS_HAVE_BTRFS_SCRUB_RESUME
PyObject *
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

#ifdef GUESTFS_HAVE_CAT
PyObject *
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

  py_r = guestfs_int_py_fromstring (r);
  free (r);
  if (py_r == NULL) goto out;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_CHECKSUM_DEVICE
PyObject *
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

  py_r = guestfs_int_py_fromstring (r);
  free (r);
  if (py_r == NULL) goto out;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_CLEAR_BACKEND_SETTING
PyObject *
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

#ifdef GUESTFS_HAVE_CONFIG
PyObject *
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
PyObject *
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
PyObject *
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

#ifdef GUESTFS_HAVE_DD
PyObject *
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

#ifdef GUESTFS_HAVE_DEBUG_DRIVES
PyObject *
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

  py_r = guestfs_int_py_put_string_list (r);
  guestfs_int_free_string_list (r);
  if (py_r == NULL) goto out;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_DEVICE_INDEX
PyObject *
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

#ifdef GUESTFS_HAVE_DOWNLOAD_INODE
PyObject *
guestfs_int_py_download_inode (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  const char *device;
  long long inode;
  const char *filename;

  if (!PyArg_ParseTuple (args, (char *) "OsLs:guestfs_download_inode",
                         &py_g, &device, &inode, &filename))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_download_inode (g, device, inode, filename);

  if (PyEval_ThreadsInitialized ())
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

#ifdef GUESTFS_HAVE_EXISTS
PyObject *
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

#ifdef GUESTFS_HAVE_FILESYSTEM_WALK
PyObject *
guestfs_int_py_filesystem_walk (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  struct guestfs_tsk_dirent_list *r;
  const char *device;

  if (!PyArg_ParseTuple (args, (char *) "Os:guestfs_filesystem_walk",
                         &py_g, &device))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_filesystem_walk (g, device);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == NULL) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  py_r = guestfs_int_py_put_tsk_dirent_list (r);
  guestfs_free_tsk_dirent_list (r);
  if (py_r == NULL) goto out;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_FILL_DIR
PyObject *
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

#ifdef GUESTFS_HAVE_FINDFS_LABEL
PyObject *
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

  py_r = guestfs_int_py_fromstring (r);
  free (r);
  if (py_r == NULL) goto out;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_GET_IDENTIFIER
PyObject *
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

  py_r = guestfs_int_py_fromstring (r);
  if (py_r == NULL) goto out;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_GET_LIBVIRT_REQUESTED_CREDENTIAL_PROMPT
PyObject *
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

  py_r = guestfs_int_py_fromstring (r);
  free (r);
  if (py_r == NULL) goto out;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_GET_NETWORK
PyObject *
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

#ifdef GUESTFS_HAVE_GET_QEMU
PyObject *
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

  py_r = guestfs_int_py_fromstring (r);
  if (py_r == NULL) goto out;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_GET_STATE
PyObject *
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

#ifdef GUESTFS_HAVE_GET_UMASK
PyObject *
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
PyObject *
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

#ifdef GUESTFS_HAVE_GETXATTRS
PyObject *
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

  py_r = guestfs_int_py_put_xattr_list (r);
  guestfs_free_xattr_list (r);
  if (py_r == NULL) goto out;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_GREP_OPTS
PyObject *
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

  py_r = guestfs_int_py_put_string_list (r);
  guestfs_int_free_string_list (r);
  if (py_r == NULL) goto out;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_HIVEX_NODE_PARENT
PyObject *
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

#ifdef GUESTFS_HAVE_HIVEX_ROOT
PyObject *
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

#ifdef GUESTFS_HAVE_HIVEX_VALUE_STRING
PyObject *
guestfs_int_py_hivex_value_string (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  char *r;
  long long valueh;

  if (!PyArg_ParseTuple (args, (char *) "OL:guestfs_hivex_value_string",
                         &py_g, &valueh))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_hivex_value_string (g, valueh);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == NULL) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  py_r = guestfs_int_py_fromstring (r);
  free (r);
  if (py_r == NULL) goto out;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_HIVEX_VALUE_VALUE
PyObject *
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

  py_r = guestfs_int_py_fromstringsize (r, size);
  free (r);
  if (py_r == NULL) goto out;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_INITRD_LIST
PyObject *
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

  py_r = guestfs_int_py_put_string_list (r);
  guestfs_int_free_string_list (r);
  if (py_r == NULL) goto out;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_INOTIFY_FILES
PyObject *
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

  py_r = guestfs_int_py_put_string_list (r);
  guestfs_int_free_string_list (r);
  if (py_r == NULL) goto out;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_INOTIFY_RM_WATCH
PyObject *
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

#ifdef GUESTFS_HAVE_INSPECT_GET_ICON
PyObject *
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

  py_r = guestfs_int_py_fromstringsize (r, size);
  free (r);
  if (py_r == NULL) goto out;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_INSPECT_GET_WINDOWS_SYSTEM_HIVE
PyObject *
guestfs_int_py_inspect_get_windows_system_hive (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  char *r;
  const char *root;

  if (!PyArg_ParseTuple (args, (char *) "Os:guestfs_inspect_get_windows_system_hive",
                         &py_g, &root))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_inspect_get_windows_system_hive (g, root);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == NULL) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  py_r = guestfs_int_py_fromstring (r);
  free (r);
  if (py_r == NULL) goto out;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_INSPECT_IS_NETINST
PyObject *
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

#ifdef GUESTFS_HAVE_INSPECT_LIST_APPLICATIONS2
PyObject *
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

  py_r = guestfs_int_py_put_application2_list (r);
  guestfs_free_application2_list (r);
  if (py_r == NULL) goto out;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_INTERNAL_TEST_RBUFFEROUTERR
PyObject *
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

  py_r = guestfs_int_py_fromstringsize (r, size);
  free (r);
  if (py_r == NULL) goto out;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_INTERNAL_TEST_RCONSTOPTSTRING
PyObject *
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
    py_r = guestfs_int_py_fromstring (r);
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

#ifdef GUESTFS_HAVE_INTERNAL_TEST_RINT64
PyObject *
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

#ifdef GUESTFS_HAVE_INTERNAL_TEST_RSTRINGERR
PyObject *
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

  py_r = guestfs_int_py_fromstring (r);
  free (r);
  if (py_r == NULL) goto out;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_INTERNAL_TEST_RSTRUCTLIST
PyObject *
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

  py_r = guestfs_int_py_put_lvm_pv_list (r);
  guestfs_free_lvm_pv_list (r);
  if (py_r == NULL) goto out;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_INTERNAL_TEST_RSTRUCTLISTERR
PyObject *
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

  py_r = guestfs_int_py_put_lvm_pv_list (r);
  guestfs_free_lvm_pv_list (r);
  if (py_r == NULL) goto out;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_IS_SYMLINK
PyObject *
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

#ifdef GUESTFS_HAVE_IS_ZERO
PyObject *
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

#ifdef GUESTFS_HAVE_LCHOWN
PyObject *
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
PyObject *
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
PyObject *
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

  py_r = guestfs_int_py_put_string_list (r);
  guestfs_int_free_string_list (r);
  if (py_r == NULL) goto out;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_LIST_PARTITIONS
PyObject *
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

  py_r = guestfs_int_py_put_string_list (r);
  guestfs_int_free_string_list (r);
  if (py_r == NULL) goto out;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_LLZ
PyObject *
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

  py_r = guestfs_int_py_fromstring (r);
  free (r);
  if (py_r == NULL) goto out;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_LSTAT
PyObject *
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

  py_r = guestfs_int_py_put_stat (r);
  guestfs_free_stat (r);
  if (py_r == NULL) goto out;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_LSTATLIST
PyObject *
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
  names = guestfs_int_py_get_string_list (py_names);
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

  py_r = guestfs_int_py_put_stat_list (r);
  guestfs_free_stat_list (r);
  if (py_r == NULL) goto out;

  PyErr_Clear ();
 out:
  free (names);
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_LUKS_OPEN
PyObject *
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
PyObject *
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

#ifdef GUESTFS_HAVE_LVM_REMOVE_ALL
PyObject *
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

#ifdef GUESTFS_HAVE_LVRESIZE_FREE
PyObject *
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

#ifdef GUESTFS_HAVE_MD_CREATE
PyObject *
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
  devices = guestfs_int_py_get_string_list (py_devices);
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
    optargs_s.level = guestfs_int_py_asstring (py_level);
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

#ifdef GUESTFS_HAVE_MKDTEMP
PyObject *
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

  py_r = guestfs_int_py_fromstring (r);
  free (r);
  if (py_r == NULL) goto out;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_MKNOD
PyObject *
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

#ifdef GUESTFS_HAVE_MOUNT
PyObject *
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

#ifdef GUESTFS_HAVE_MOUNT_LOCAL_RUN
PyObject *
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

#ifdef GUESTFS_HAVE_MOUNT_RO
PyObject *
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

#ifdef GUESTFS_HAVE_MOUNTABLE_SUBVOLUME
PyObject *
guestfs_int_py_mountable_subvolume (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  char *r;
  const char *mountable;

  if (!PyArg_ParseTuple (args, (char *) "Os:guestfs_mountable_subvolume",
                         &py_g, &mountable))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_mountable_subvolume (g, mountable);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == NULL) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  py_r = guestfs_int_py_fromstring (r);
  free (r);
  if (py_r == NULL) goto out;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_MOUNTS
PyObject *
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

  py_r = guestfs_int_py_put_string_list (r);
  guestfs_int_free_string_list (r);
  if (py_r == NULL) goto out;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_NTFS_3G_PROBE
PyObject *
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

#ifdef GUESTFS_HAVE_NTFSCLONE_OUT
PyObject *
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

#ifdef GUESTFS_HAVE_PART_RESIZE
PyObject *
guestfs_int_py_part_resize (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  const char *device;
  int partnum;
  long long endsect;

  if (!PyArg_ParseTuple (args, (char *) "OsiL:guestfs_part_resize",
                         &py_g, &device, &partnum, &endsect))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_part_resize (g, device, partnum, endsect);

  if (PyEval_ThreadsInitialized ())
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

#ifdef GUESTFS_HAVE_PART_SET_DISK_GUID
PyObject *
guestfs_int_py_part_set_disk_guid (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  const char *device;
  const char *guid;

  if (!PyArg_ParseTuple (args, (char *) "Oss:guestfs_part_set_disk_guid",
                         &py_g, &device, &guid))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_part_set_disk_guid (g, device, guid);

  if (PyEval_ThreadsInitialized ())
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

#ifdef GUESTFS_HAVE_PART_SET_DISK_GUID_RANDOM
PyObject *
guestfs_int_py_part_set_disk_guid_random (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  const char *device;

  if (!PyArg_ParseTuple (args, (char *) "Os:guestfs_part_set_disk_guid_random",
                         &py_g, &device))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_part_set_disk_guid_random (g, device);

  if (PyEval_ThreadsInitialized ())
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
PyObject *
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

  py_r = guestfs_int_py_fromstringsize (r, size);
  free (r);
  if (py_r == NULL) goto out;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_REALPATH
PyObject *
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

  py_r = guestfs_int_py_fromstring (r);
  free (r);
  if (py_r == NULL) goto out;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_SELINUX_RELABEL
PyObject *
guestfs_int_py_selinux_relabel (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  struct guestfs_selinux_relabel_argv optargs_s;
  struct guestfs_selinux_relabel_argv *optargs = &optargs_s;
  int r;
  const char *specfile;
  const char *path;
  PyObject *py_force;

  optargs_s.bitmask = 0;

  if (!PyArg_ParseTuple (args, (char *) "OssO:guestfs_selinux_relabel",
                         &py_g, &specfile, &path, &py_force))
    goto out;
  g = get_handle (py_g);

#ifdef GUESTFS_SELINUX_RELABEL_FORCE_BITMASK
  if (py_force != Py_None) {
    optargs_s.bitmask |= GUESTFS_SELINUX_RELABEL_FORCE_BITMASK;
    optargs_s.force = PyLong_AsLong (py_force);
    if (PyErr_Occurred ()) goto out;
  }
#endif

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_selinux_relabel_argv (g, specfile, path, optargs);

  if (PyEval_ThreadsInitialized ())
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

#ifdef GUESTFS_HAVE_SET_AUTOSYNC
PyObject *
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

#ifdef GUESTFS_HAVE_SET_BACKEND_SETTING
PyObject *
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

#ifdef GUESTFS_HAVE_SET_IDENTIFIER
PyObject *
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

#ifdef GUESTFS_HAVE_SET_VERBOSE
PyObject *
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

#ifdef GUESTFS_HAVE_SWAPOFF_FILE
PyObject *
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

#ifdef GUESTFS_HAVE_SYSLINUX
PyObject *
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
    optargs_s.directory = guestfs_int_py_asstring (py_directory);
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
PyObject *
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

  py_r = guestfs_int_py_put_string_list (r);
  guestfs_int_free_string_list (r);
  if (py_r == NULL) goto out;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_TOUCH
PyObject *
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

#ifdef GUESTFS_HAVE_TUNE2FS_L
PyObject *
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

  py_r = guestfs_int_py_put_table (r);
  guestfs_int_free_string_list (r);
  if (py_r == NULL) goto out;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_UMOUNT_OPTS
PyObject *
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

#ifdef GUESTFS_HAVE_VG_ACTIVATE
PyObject *
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
  volgroups = guestfs_int_py_get_string_list (py_volgroups);
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

#ifdef GUESTFS_HAVE_VGS_FULL
PyObject *
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

  py_r = guestfs_int_py_put_lvm_vg_list (r);
  guestfs_free_lvm_vg_list (r);
  if (py_r == NULL) goto out;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_VGSCAN
PyObject *
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

#ifdef GUESTFS_HAVE_XFS_ADMIN
PyObject *
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
    optargs_s.label = guestfs_int_py_asstring (py_label);
  }
#endif
#ifdef GUESTFS_XFS_ADMIN_UUID_BITMASK
  if (py_uuid != Py_None) {
    optargs_s.bitmask |= GUESTFS_XFS_ADMIN_UUID_BITMASK;
    optargs_s.uuid = guestfs_int_py_asstring (py_uuid);
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

#ifdef GUESTFS_HAVE_YARA_DESTROY
PyObject *
guestfs_int_py_yara_destroy (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;

  if (!PyArg_ParseTuple (args, (char *) "O:guestfs_yara_destroy",
                         &py_g))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_yara_destroy (g);

  if (PyEval_ThreadsInitialized ())
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

#ifdef GUESTFS_HAVE_ZEGREPI
PyObject *
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

  py_r = guestfs_int_py_put_string_list (r);
  guestfs_int_free_string_list (r);
  if (py_r == NULL) goto out;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_ZFGREP
PyObject *
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

  py_r = guestfs_int_py_put_string_list (r);
  guestfs_int_free_string_list (r);
  if (py_r == NULL) goto out;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_ZFILE
PyObject *
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

  py_r = guestfs_int_py_fromstring (r);
  free (r);
  if (py_r == NULL) goto out;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

