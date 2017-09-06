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

#ifdef GUESTFS_HAVE_ACL_GET_FILE
PyObject *
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

#ifdef GUESTFS_HAVE_AUG_CLOSE
PyObject *
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
PyObject *
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

  py_r = guestfs_int_py_put_int_bool (r);
  guestfs_free_int_bool (r);

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_AUG_GET
PyObject *
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

#ifdef GUESTFS_HAVE_AUG_SAVE
PyObject *
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

#ifdef GUESTFS_HAVE_AUG_SETM
PyObject *
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
PyObject *
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
  groups = guestfs_int_py_get_string_list (py_groups);
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

#ifdef GUESTFS_HAVE_BLKDISCARD
PyObject *
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

#ifdef GUESTFS_HAVE_BLOCKDEV_GETSZ
PyObject *
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

#ifdef GUESTFS_HAVE_BLOCKDEV_SETRO
PyObject *
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

#ifdef GUESTFS_HAVE_BTRFS_BALANCE_STATUS
PyObject *
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

  py_r = guestfs_int_py_put_btrfsbalance (r);
  guestfs_free_btrfsbalance (r);

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_BTRFS_DEVICE_DELETE
PyObject *
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
  devices = guestfs_int_py_get_string_list (py_devices);
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

#ifdef GUESTFS_HAVE_BTRFS_FILESYSTEM_DEFRAGMENT
PyObject *
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
PyObject *
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
PyObject *
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

#ifdef GUESTFS_HAVE_BTRFS_IMAGE
PyObject *
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
  source = guestfs_int_py_get_string_list (py_source);
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

#ifdef GUESTFS_HAVE_BTRFS_QGROUP_DESTROY
PyObject *
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

#ifdef GUESTFS_HAVE_BTRFS_SUBVOLUME_DELETE
PyObject *
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

#ifdef GUESTFS_HAVE_BTRFS_SUBVOLUME_LIST
PyObject *
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

  py_r = guestfs_int_py_put_btrfssubvolume_list (r);
  guestfs_free_btrfssubvolume_list (r);

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_BTRFSTUNE_ENABLE_SKINNY_METADATA_EXTENT_REFS
PyObject *
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

#ifdef GUESTFS_HAVE_CAP_GET_FILE
PyObject *
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

#ifdef GUESTFS_HAVE_CHECKSUM
PyObject *
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

#ifdef GUESTFS_HAVE_CHMOD
PyObject *
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

#ifdef GUESTFS_HAVE_COPY_OUT
PyObject *
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

#ifdef GUESTFS_HAVE_DISK_CREATE
PyObject *
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

#ifdef GUESTFS_HAVE_DMESG
PyObject *
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

#ifdef GUESTFS_HAVE_DOWNLOAD_BLOCKS
PyObject *
guestfs_int_py_download_blocks (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  struct guestfs_download_blocks_argv optargs_s;
  struct guestfs_download_blocks_argv *optargs = &optargs_s;
  int r;
  const char *device;
  long long start;
  long long stop;
  const char *filename;
  PyObject *py_unallocated;

  optargs_s.bitmask = 0;

  if (!PyArg_ParseTuple (args, (char *) "OsLLsO:guestfs_download_blocks",
                         &py_g, &device, &start, &stop, &filename, &py_unallocated))
    goto out;
  g = get_handle (py_g);

#ifdef GUESTFS_DOWNLOAD_BLOCKS_UNALLOCATED_BITMASK
  if (py_unallocated != Py_None) {
    optargs_s.bitmask |= GUESTFS_DOWNLOAD_BLOCKS_UNALLOCATED_BITMASK;
    optargs_s.unallocated = PyLong_AsLong (py_unallocated);
    if (PyErr_Occurred ()) goto out;
  }
#endif

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_download_blocks_argv (g, device, start, stop, filename, optargs);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
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
PyObject *
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

#ifdef GUESTFS_HAVE_E2FSCK_F
PyObject *
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
PyObject *
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
  words = guestfs_int_py_get_string_list (py_words);
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

#ifdef GUESTFS_HAVE_EQUAL
PyObject *
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

#ifdef GUESTFS_HAVE_FGREPI
PyObject *
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

  py_r = guestfs_int_py_put_string_list (r);
  guestfs_int_free_string_list (r);

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_GET_BACKEND_SETTING
PyObject *
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
PyObject *
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

  py_r = guestfs_int_py_put_string_list (r);
  guestfs_int_free_string_list (r);

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_GET_E2LABEL
PyObject *
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

#ifdef GUESTFS_HAVE_GET_RECOVERY_PROC
PyObject *
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

#ifdef GUESTFS_HAVE_GET_TMPDIR
PyObject *
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

#ifdef GUESTFS_HAVE_GETCON
PyObject *
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
PyObject *
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

#ifdef GUESTFS_HAVE_HIVEX_CLOSE
PyObject *
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

#ifdef GUESTFS_HAVE_HIVEX_OPEN
PyObject *
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
  PyObject *py_unsafe;

  optargs_s.bitmask = 0;

  if (!PyArg_ParseTuple (args, (char *) "OsOOOO:guestfs_hivex_open",
                         &py_g, &filename, &py_verbose, &py_debug, &py_write, &py_unsafe))
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
#ifdef GUESTFS_HIVEX_OPEN_UNSAFE_BITMASK
  if (py_unsafe != Py_None) {
    optargs_s.bitmask |= GUESTFS_HIVEX_OPEN_UNSAFE_BITMASK;
    optargs_s.unsafe = PyLong_AsLong (py_unsafe);
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

#ifdef GUESTFS_HAVE_HIVEX_VALUE_UTF8
PyObject *
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

#ifdef GUESTFS_HAVE_INOTIFY_ADD_WATCH
PyObject *
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

#ifdef GUESTFS_HAVE_INOTIFY_INIT
PyObject *
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

#ifdef GUESTFS_HAVE_INSPECT_GET_TYPE
PyObject *
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

#ifdef GUESTFS_HAVE_INSPECT_IS_LIVE
PyObject *
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

#ifdef GUESTFS_HAVE_INTERNAL_EXIT
PyObject *
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

#ifdef GUESTFS_HAVE_INTERNAL_TEST_ONLY_OPTARGS
PyObject *
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

#ifdef GUESTFS_HAVE_INTERNAL_TEST_RCONSTSTRINGERR
PyObject *
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

#ifdef GUESTFS_HAVE_IS_DIR_OPTS
PyObject *
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

#ifdef GUESTFS_HAVE_IS_FILE_OPTS
PyObject *
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

#ifdef GUESTFS_HAVE_IS_WHOLE_DEVICE
PyObject *
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

#ifdef GUESTFS_HAVE_IS_ZERO_DEVICE
PyObject *
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

#ifdef GUESTFS_HAVE_JOURNAL_GET_REALTIME_USEC
PyObject *
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

#ifdef GUESTFS_HAVE_JOURNAL_SET_DATA_THRESHOLD
PyObject *
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

#ifdef GUESTFS_HAVE_LAUNCH
PyObject *
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

#ifdef GUESTFS_HAVE_LDMTOOL_REMOVE_ALL
PyObject *
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

#ifdef GUESTFS_HAVE_LDMTOOL_VOLUME_HINT
PyObject *
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

#ifdef GUESTFS_HAVE_LDMTOOL_VOLUME_TYPE
PyObject *
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

#ifdef GUESTFS_HAVE_LIST_DEVICES
PyObject *
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

  py_r = guestfs_int_py_put_string_list (r);
  guestfs_int_free_string_list (r);

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_LIST_FILESYSTEMS
PyObject *
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

  py_r = guestfs_int_py_put_table (r);
  guestfs_int_free_string_list (r);

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_LS
PyObject *
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

  py_r = guestfs_int_py_put_string_list (r);
  guestfs_int_free_string_list (r);

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_LS0
PyObject *
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

#ifdef GUESTFS_HAVE_LSTATNS
PyObject *
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

  py_r = guestfs_int_py_put_statns (r);
  guestfs_free_statns (r);

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_LXATTRLIST
PyObject *
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
  names = guestfs_int_py_get_string_list (py_names);
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

  py_r = guestfs_int_py_put_xattr_list (r);
  guestfs_free_xattr_list (r);

  PyErr_Clear ();
 out:
  free (names);
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_MKDIR_MODE
PyObject *
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
PyObject *
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

#ifdef GUESTFS_HAVE_MKE2FS
PyObject *
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

#ifdef GUESTFS_HAVE_MKE2FS_JL
PyObject *
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
PyObject *
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
PyObject *
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

#ifdef GUESTFS_HAVE_MKNOD_B
PyObject *
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

#ifdef GUESTFS_HAVE_MOUNT_LOCAL
PyObject *
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

#ifdef GUESTFS_HAVE_NTFSRESIZE_SIZE
PyObject *
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

#ifdef GUESTFS_HAVE_PART_DEL
PyObject *
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

#ifdef GUESTFS_HAVE_PART_GET_GPT_TYPE
PyObject *
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

#ifdef GUESTFS_HAVE_PING_DAEMON
PyObject *
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

#ifdef GUESTFS_HAVE_REMOVE_DRIVE
PyObject *
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

#ifdef GUESTFS_HAVE_RM
PyObject *
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

#ifdef GUESTFS_HAVE_RMDIR
PyObject *
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

#ifdef GUESTFS_HAVE_RSYNC
PyObject *
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

#ifdef GUESTFS_HAVE_SET_BACKEND_SETTINGS
PyObject *
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
  settings = guestfs_int_py_get_string_list (py_settings);
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

#ifdef GUESTFS_HAVE_SET_HV
PyObject *
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

#ifdef GUESTFS_HAVE_SET_QEMU
PyObject *
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
PyObject *
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

#ifdef GUESTFS_HAVE_SET_UUID
PyObject *
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

#ifdef GUESTFS_HAVE_SETCON
PyObject *
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

#ifdef GUESTFS_HAVE_STATVFS
PyObject *
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

  py_r = guestfs_int_py_put_statvfs (r);
  guestfs_free_statvfs (r);

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_STRINGS
PyObject *
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

  py_r = guestfs_int_py_put_string_list (r);
  guestfs_int_free_string_list (r);

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_SWAPOFF_LABEL
PyObject *
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
PyObject *
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

#ifdef GUESTFS_HAVE_TAR_IN_OPTS
PyObject *
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

#ifdef GUESTFS_HAVE_TRUNCATE
PyObject *
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

#ifdef GUESTFS_HAVE_TUNE2FS
PyObject *
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

#ifdef GUESTFS_HAVE_UPLOAD
PyObject *
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

#ifdef GUESTFS_HAVE_UTIMENS
PyObject *
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

#ifdef GUESTFS_HAVE_VERSION
PyObject *
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

  py_r = guestfs_int_py_put_version (r);
  guestfs_free_version (r);

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_VFS_MINIMUM_SIZE
PyObject *
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

#ifdef GUESTFS_HAVE_VFS_UUID
PyObject *
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

#ifdef GUESTFS_HAVE_VGS
PyObject *
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

  py_r = guestfs_int_py_put_string_list (r);
  guestfs_int_free_string_list (r);

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_WRITE_FILE
PyObject *
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

#ifdef GUESTFS_HAVE_ZERO
PyObject *
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

#ifdef GUESTFS_HAVE_ZEROFREE
PyObject *
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

#ifdef GUESTFS_HAVE_ZGREPI
PyObject *
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

  py_r = guestfs_int_py_put_string_list (r);
  guestfs_int_free_string_list (r);

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

