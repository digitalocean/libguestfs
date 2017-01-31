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

#ifdef GUESTFS_HAVE_ADD_DRIVE_OPTS
PyObject *
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
    optargs_s.server = guestfs_int_py_get_string_list (py_server);
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

#ifdef GUESTFS_HAVE_ADD_DRIVE_SCRATCH
PyObject *
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

#ifdef GUESTFS_HAVE_AUG_LABEL
PyObject *
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

#ifdef GUESTFS_HAVE_BLKDISCARDZEROES
PyObject *
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

#ifdef GUESTFS_HAVE_BLOCKDEV_GETSIZE64
PyObject *
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
PyObject *
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

#ifdef GUESTFS_HAVE_BLOCKDEV_REREADPT
PyObject *
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

#ifdef GUESTFS_HAVE_BTRFS_BALANCE_CANCEL
PyObject *
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

#ifdef GUESTFS_HAVE_BTRFS_QGROUP_LIMIT
PyObject *
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

#ifdef GUESTFS_HAVE_BTRFS_QUOTA_RESCAN
PyObject *
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

#ifdef GUESTFS_HAVE_BTRFS_SET_SEEDING
PyObject *
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

#ifdef GUESTFS_HAVE_BTRFS_SUBVOLUME_SHOW
PyObject *
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

  py_r = guestfs_int_py_put_table (r);
  guestfs_int_free_string_list (r);

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_CHOWN
PyObject *
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

#ifdef GUESTFS_HAVE_COMMAND
PyObject *
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
  arguments = guestfs_int_py_get_string_list (py_arguments);
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

#ifdef GUESTFS_HAVE_COPY_DEVICE_TO_FILE
PyObject *
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

#ifdef GUESTFS_HAVE_CP_R
PyObject *
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

#ifdef GUESTFS_HAVE_DEBUG
PyObject *
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
  extraargs = guestfs_int_py_get_string_list (py_extraargs);
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

#ifdef GUESTFS_HAVE_DROP_CACHES
PyObject *
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

#ifdef GUESTFS_HAVE_EGREP
PyObject *
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

  py_r = guestfs_int_py_put_string_list (r);
  guestfs_int_free_string_list (r);

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_FILE_ARCHITECTURE
PyObject *
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

#ifdef GUESTFS_HAVE_GET_BACKEND
PyObject *
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

#ifdef GUESTFS_HAVE_GET_E2ATTRS
PyObject *
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
PyObject *
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

#ifdef GUESTFS_HAVE_GLOB_EXPAND_OPTS
PyObject *
guestfs_int_py_glob_expand (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  struct guestfs_glob_expand_opts_argv optargs_s;
  struct guestfs_glob_expand_opts_argv *optargs = &optargs_s;
  char **r;
  const char *pattern;
  PyObject *py_directoryslash;

  optargs_s.bitmask = 0;

  if (!PyArg_ParseTuple (args, (char *) "OsO:guestfs_glob_expand",
                         &py_g, &pattern, &py_directoryslash))
    goto out;
  g = get_handle (py_g);

#ifdef GUESTFS_GLOB_EXPAND_OPTS_DIRECTORYSLASH_BITMASK
  if (py_directoryslash != Py_None) {
    optargs_s.bitmask |= GUESTFS_GLOB_EXPAND_OPTS_DIRECTORYSLASH_BITMASK;
    optargs_s.directoryslash = PyLong_AsLong (py_directoryslash);
    if (PyErr_Occurred ()) goto out;
  }
#endif

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_glob_expand_opts_argv (g, pattern, optargs);

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

#ifdef GUESTFS_HAVE_GRUB_INSTALL
PyObject *
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

#ifdef GUESTFS_HAVE_HIVEX_NODE_ADD_CHILD
PyObject *
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

#ifdef GUESTFS_HAVE_HIVEX_NODE_GET_VALUE
PyObject *
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

#ifdef GUESTFS_HAVE_INSPECT_GET_ARCH
PyObject *
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

#ifdef GUESTFS_HAVE_INSPECT_GET_DRIVE_MAPPINGS
PyObject *
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

  py_r = guestfs_int_py_put_table (r);
  guestfs_int_free_string_list (r);

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_INSPECT_GET_WINDOWS_CURRENT_CONTROL_SET
PyObject *
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
PyObject *
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

#ifdef GUESTFS_HAVE_INTERNAL_TEST_CLOSE_OUTPUT
PyObject *
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

#ifdef GUESTFS_HAVE_INTERNAL_TEST_RBUFFEROUT
PyObject *
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

#ifdef GUESTFS_HAVE_INTERNAL_TEST_RCONSTOPTSTRINGERR
PyObject *
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

#ifdef GUESTFS_HAVE_INTERNAL_TEST_RINTERR
PyObject *
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

#ifdef GUESTFS_HAVE_INTERNAL_TEST_SET_OUTPUT
PyObject *
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

#ifdef GUESTFS_HAVE_IS_CHARDEV_OPTS
PyObject *
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

#ifdef GUESTFS_HAVE_IS_LAUNCHING
PyObject *
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
PyObject *
guestfs_int_py_is_lv (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  const char *mountable;

  if (!PyArg_ParseTuple (args, (char *) "Os:guestfs_is_lv",
                         &py_g, &mountable))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_is_lv (g, mountable);

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

#ifdef GUESTFS_HAVE_IS_SOCKET_OPTS
PyObject *
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

#ifdef GUESTFS_HAVE_JOURNAL_OPEN
PyObject *
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

#ifdef GUESTFS_HAVE_KILL_SUBPROCESS
PyObject *
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

#ifdef GUESTFS_HAVE_LDMTOOL_SCAN_DEVICES
PyObject *
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
  devices = guestfs_int_py_get_string_list (py_devices);
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

  py_r = guestfs_int_py_put_string_list (r);
  guestfs_int_free_string_list (r);

  PyErr_Clear ();
 out:
  free (devices);
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_LSETXATTR
PyObject *
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

#ifdef GUESTFS_HAVE_LUKS_KILL_SLOT
PyObject *
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

#ifdef GUESTFS_HAVE_MKDIR
PyObject *
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

#ifdef GUESTFS_HAVE_MKFIFO
PyObject *
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

#ifdef GUESTFS_HAVE_MODPROBE
PyObject *
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

#ifdef GUESTFS_HAVE_NTFSCAT_I
PyObject *
guestfs_int_py_ntfscat_i (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  const char *device;
  long long inode;
  const char *filename;

  if (!PyArg_ParseTuple (args, (char *) "OsLs:guestfs_ntfscat_i",
                         &py_g, &device, &inode, &filename))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_ntfscat_i (g, device, inode, filename);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
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
PyObject *
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

#ifdef GUESTFS_HAVE_PART_GET_DISK_GUID
PyObject *
guestfs_int_py_part_get_disk_guid (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  char *r;
  const char *device;

  if (!PyArg_ParseTuple (args, (char *) "Os:guestfs_part_get_disk_guid",
                         &py_g, &device))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_part_get_disk_guid (g, device);

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

#ifdef GUESTFS_HAVE_PART_LIST
PyObject *
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

  py_r = guestfs_int_py_put_partition_list (r);
  guestfs_free_partition_list (r);

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_PART_SET_BOOTABLE
PyObject *
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
PyObject *
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

#ifdef GUESTFS_HAVE_PART_TO_DEV
PyObject *
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

#ifdef GUESTFS_HAVE_PVRESIZE
PyObject *
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

#ifdef GUESTFS_HAVE_PVS_FULL
PyObject *
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

  py_r = guestfs_int_py_put_lvm_pv_list (r);
  guestfs_free_lvm_pv_list (r);

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_PWRITE_DEVICE
PyObject *
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

#ifdef GUESTFS_HAVE_READDIR
PyObject *
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

  py_r = guestfs_int_py_put_dirent_list (r);
  guestfs_free_dirent_list (r);

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_READLINK
PyObject *
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

#ifdef GUESTFS_HAVE_RESIZE2FS
PyObject *
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

#ifdef GUESTFS_HAVE_RSYNC_IN
PyObject *
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

#ifdef GUESTFS_HAVE_SET_E2UUID
PyObject *
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

#ifdef GUESTFS_HAVE_SET_LIBVIRT_REQUESTED_CREDENTIAL
PyObject *
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
PyObject *
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
  creds = guestfs_int_py_get_string_list (py_creds);
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

#ifdef GUESTFS_HAVE_SET_PATH
PyObject *
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
PyObject *
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

#ifdef GUESTFS_HAVE_SFDISK_DISK_GEOMETRY
PyObject *
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

#ifdef GUESTFS_HAVE_SH
PyObject *
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

#ifdef GUESTFS_HAVE_STATNS
PyObject *
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

  py_r = guestfs_int_py_put_statns (r);
  guestfs_free_statns (r);

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_SWAPON_LABEL
PyObject *
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

#ifdef GUESTFS_HAVE_TXZ_OUT
PyObject *
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

#ifdef GUESTFS_HAVE_UMOUNT_ALL
PyObject *
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

#ifdef GUESTFS_HAVE_UPLOAD_OFFSET
PyObject *
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

#ifdef GUESTFS_HAVE_UTSNAME
PyObject *
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

  py_r = guestfs_int_py_put_utsname (r);
  guestfs_free_utsname (r);

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_VGPVUUIDS
PyObject *
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

  py_r = guestfs_int_py_put_string_list (r);
  guestfs_int_free_string_list (r);

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_WRITE_APPEND
PyObject *
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

#ifdef GUESTFS_HAVE_ZGREP
PyObject *
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

  py_r = guestfs_int_py_put_string_list (r);
  guestfs_int_free_string_list (r);

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

