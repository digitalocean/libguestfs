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

#ifdef GUESTFS_HAVE_ACL_SET_FILE
PyObject *
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

#ifdef GUESTFS_HAVE_ADD_DRIVE_WITH_IF
PyObject *
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

#ifdef GUESTFS_HAVE_BLOCKDEV_FLUSHBUFS
PyObject *
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

#ifdef GUESTFS_HAVE_BLOCKDEV_SETRW
PyObject *
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

#ifdef GUESTFS_HAVE_BTRFS_BALANCE_PAUSE
PyObject *
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

#ifdef GUESTFS_HAVE_BTRFS_DEVICE_ADD
PyObject *
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
  devices = guestfs_int_py_get_string_list (py_devices);
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

#ifdef GUESTFS_HAVE_BTRFS_FILESYSTEM_BALANCE
PyObject *
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

#ifdef GUESTFS_HAVE_BTRFS_FILESYSTEM_SHOW
PyObject *
guestfs_int_py_btrfs_filesystem_show (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  char **r;
  const char *device;

  if (!PyArg_ParseTuple (args, (char *) "Os:guestfs_btrfs_filesystem_show",
                         &py_g, &device))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_btrfs_filesystem_show (g, device);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == NULL) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  py_r = guestfs_int_py_put_string_list (r);
  guestfs_int_free_string_list (r);

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_BTRFS_QGROUP_ASSIGN
PyObject *
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

#ifdef GUESTFS_HAVE_BTRFS_REPLACE
PyObject *
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

#ifdef GUESTFS_HAVE_BTRFS_SCRUB_CANCEL
PyObject *
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

#ifdef GUESTFS_HAVE_BTRFS_SUBVOLUME_GET_DEFAULT
PyObject *
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

#ifdef GUESTFS_HAVE_BTRFSTUNE_SEEDING
PyObject *
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
PyObject *
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

#ifdef GUESTFS_HAVE_CAP_SET_FILE
PyObject *
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

#ifdef GUESTFS_HAVE_COPY_FILE_TO_DEVICE
PyObject *
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
PyObject *
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

#ifdef GUESTFS_HAVE_CPIO_OUT
PyObject *
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

#ifdef GUESTFS_HAVE_DISK_VIRTUAL_SIZE
PyObject *
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

#ifdef GUESTFS_HAVE_DOWNLOAD
PyObject *
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

#ifdef GUESTFS_HAVE_FEATURE_AVAILABLE
PyObject *
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
  groups = guestfs_int_py_get_string_list (py_groups);
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

#ifdef GUESTFS_HAVE_FILL_PATTERN
PyObject *
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

#ifdef GUESTFS_HAVE_FIND0
PyObject *
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

#ifdef GUESTFS_HAVE_GET_APPEND
PyObject *
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

#ifdef GUESTFS_HAVE_GET_MEMSIZE
PyObject *
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

#ifdef GUESTFS_HAVE_GET_PROGRAM
PyObject *
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

#ifdef GUESTFS_HAVE_HEAD_N
PyObject *
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

  py_r = guestfs_int_py_put_string_list (r);
  guestfs_int_free_string_list (r);

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_HIVEX_COMMIT
PyObject *
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

#ifdef GUESTFS_HAVE_HIVEX_NODE_DELETE_CHILD
PyObject *
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

#ifdef GUESTFS_HAVE_INITRD_CAT
PyObject *
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

#ifdef GUESTFS_HAVE_INOTIFY_CLOSE
PyObject *
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

#ifdef GUESTFS_HAVE_INSPECT_GET_MAJOR_VERSION
PyObject *
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

#ifdef GUESTFS_HAVE_INSPECT_GET_ROOTS
PyObject *
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

  py_r = guestfs_int_py_put_string_list (r);
  guestfs_int_free_string_list (r);

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_INTERNAL_TEST
PyObject *
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
  strlist = guestfs_int_py_get_string_list (py_strlist);
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
    optargs_s.ostringlist = guestfs_int_py_get_string_list (py_ostringlist);
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
PyObject *
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

#ifdef GUESTFS_HAVE_INTERNAL_TEST_RHASHTABLEERR
PyObject *
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

  py_r = guestfs_int_py_put_table (r);
  guestfs_int_free_string_list (r);

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_IS_BLOCKDEV_OPTS
PyObject *
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

#ifdef GUESTFS_HAVE_IS_CONFIG
PyObject *
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

#ifdef GUESTFS_HAVE_IS_FIFO_OPTS
PyObject *
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

#ifdef GUESTFS_HAVE_ISOINFO_DEVICE
PyObject *
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

  py_r = guestfs_int_py_put_isoinfo (r);
  guestfs_free_isoinfo (r);

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_JOURNAL_NEXT
PyObject *
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

#ifdef GUESTFS_HAVE_JOURNAL_SKIP
PyObject *
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

#ifdef GUESTFS_HAVE_LDMTOOL_VOLUME_PARTITIONS
PyObject *
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

  py_r = guestfs_int_py_put_string_list (r);
  guestfs_int_free_string_list (r);

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_LIST_DISK_LABELS
PyObject *
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

  py_r = guestfs_int_py_put_table (r);
  guestfs_int_free_string_list (r);

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_LIST_MD_DEVICES
PyObject *
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

  py_r = guestfs_int_py_put_string_list (r);
  guestfs_int_free_string_list (r);

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_LN
PyObject *
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

#ifdef GUESTFS_HAVE_LN_SF
PyObject *
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

#ifdef GUESTFS_HAVE_LUKS_ADD_KEY
PyObject *
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

#ifdef GUESTFS_HAVE_LVCREATE
PyObject *
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
PyObject *
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

#ifdef GUESTFS_HAVE_LVM_SET_FILTER
PyObject *
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
  devices = guestfs_int_py_get_string_list (py_devices);
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

#ifdef GUESTFS_HAVE_LVS_FULL
PyObject *
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

  py_r = guestfs_int_py_put_lvm_lv_list (r);
  guestfs_free_lvm_lv_list (r);

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_MD_STAT
PyObject *
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

  py_r = guestfs_int_py_put_mdstat_list (r);
  guestfs_free_mdstat_list (r);

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_MKFS_OPTS
PyObject *
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
PyObject *
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

#ifdef GUESTFS_HAVE_MKSWAP_U
PyObject *
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

#ifdef GUESTFS_HAVE_MOUNTPOINTS
PyObject *
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

  py_r = guestfs_int_py_put_table (r);
  guestfs_int_free_string_list (r);

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_NR_DEVICES
PyObject *
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

#ifdef GUESTFS_HAVE_NTFSCLONE_IN
PyObject *
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

#ifdef GUESTFS_HAVE_PARSE_ENVIRONMENT_LIST
PyObject *
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
  environment = guestfs_int_py_get_string_list (py_environment);
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

#ifdef GUESTFS_HAVE_PART_GET_BOOTABLE
PyObject *
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

#ifdef GUESTFS_HAVE_PART_SET_GPT_TYPE
PyObject *
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

#ifdef GUESTFS_HAVE_PART_SET_NAME
PyObject *
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

#ifdef GUESTFS_HAVE_PVREMOVE
PyObject *
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

#ifdef GUESTFS_HAVE_SCRUB_FREESPACE
PyObject *
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

#ifdef GUESTFS_HAVE_SET_ATTACH_METHOD
PyObject *
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

#ifdef GUESTFS_HAVE_SET_NETWORK
PyObject *
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

#ifdef GUESTFS_HAVE_SET_SMP
PyObject *
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
PyObject *
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
PyObject *
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

#ifdef GUESTFS_HAVE_SET_UUID_RANDOM
PyObject *
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

#ifdef GUESTFS_HAVE_SFDISK
PyObject *
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
  lines = guestfs_int_py_get_string_list (py_lines);
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
PyObject *
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
  lines = guestfs_int_py_get_string_list (py_lines);
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
PyObject *
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

#ifdef GUESTFS_HAVE_STAT
PyObject *
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

  py_r = guestfs_int_py_put_stat (r);
  guestfs_free_stat (r);

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_SWAPOFF_DEVICE
PyObject *
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

#ifdef GUESTFS_HAVE_SWAPON_DEVICE
PyObject *
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

#ifdef GUESTFS_HAVE_SWAPON_UUID
PyObject *
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

#ifdef GUESTFS_HAVE_TGZ_IN
PyObject *
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

#ifdef GUESTFS_HAVE_TRUNCATE_SIZE
PyObject *
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

#ifdef GUESTFS_HAVE_TXZ_IN
PyObject *
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

#ifdef GUESTFS_HAVE_USER_CANCEL
PyObject *
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

#ifdef GUESTFS_HAVE_VGCHANGE_UUID
PyObject *
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

#ifdef GUESTFS_HAVE_VGLVUUIDS
PyObject *
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

  py_r = guestfs_int_py_put_string_list (r);
  guestfs_int_free_string_list (r);

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_VGREMOVE
PyObject *
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

#ifdef GUESTFS_HAVE_WC_L
PyObject *
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

#ifdef GUESTFS_HAVE_XFS_GROWFS
PyObject *
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
PyObject *
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

  py_r = guestfs_int_py_put_xfsinfo (r);
  guestfs_free_xfsinfo (r);

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_XFS_REPAIR
PyObject *
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

#ifdef GUESTFS_HAVE_ZERO_DEVICE
PyObject *
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
PyObject *
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

