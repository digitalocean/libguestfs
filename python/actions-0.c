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

#ifdef GUESTFS_HAVE_ACL_DELETE_DEF_FILE
PyObject *
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

#ifdef GUESTFS_HAVE_ADD_DOMAIN
PyObject *
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

#ifdef GUESTFS_HAVE_ADD_DRIVE_RO
PyObject *
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
PyObject *
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

#ifdef GUESTFS_HAVE_AUG_LS
PyObject *
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

  py_r = guestfs_int_py_put_string_list (r);
  guestfs_int_free_string_list (r);

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_AUG_MATCH
PyObject *
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

  py_r = guestfs_int_py_put_string_list (r);
  guestfs_int_free_string_list (r);

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_BTRFS_QGROUP_CREATE
PyObject *
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

#ifdef GUESTFS_HAVE_BTRFS_RESCUE_SUPER_RECOVER
PyObject *
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

#ifdef GUESTFS_HAVE_BTRFSTUNE_ENABLE_EXTENDED_INODE_REFS
PyObject *
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

#ifdef GUESTFS_HAVE_COMMAND_LINES
PyObject *
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
  arguments = guestfs_int_py_get_string_list (py_arguments);
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

  py_r = guestfs_int_py_put_string_list (r);
  guestfs_int_free_string_list (r);

  PyErr_Clear ();
 out:
  free (arguments);
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_COMPRESS_DEVICE_OUT
PyObject *
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
PyObject *
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

#ifdef GUESTFS_HAVE_COPY_IN
PyObject *
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

#ifdef GUESTFS_HAVE_CP
PyObject *
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

#ifdef GUESTFS_HAVE_DF_H
PyObject *
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

#ifdef GUESTFS_HAVE_DISK_HAS_BACKING_FILE
PyObject *
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

#ifdef GUESTFS_HAVE_E2FSCK
PyObject *
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

#ifdef GUESTFS_HAVE_EXTLINUX
PyObject *
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

#ifdef GUESTFS_HAVE_FSCK
PyObject *
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

#ifdef GUESTFS_HAVE_GET_ATTACH_METHOD
PyObject *
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

#ifdef GUESTFS_HAVE_GET_CACHEDIR
PyObject *
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

#ifdef GUESTFS_HAVE_GET_LIBVIRT_REQUESTED_CREDENTIAL_DEFRESULT
PyObject *
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

#ifdef GUESTFS_HAVE_GET_PATH
PyObject *
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
PyObject *
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

#ifdef GUESTFS_HAVE_GET_SMP
PyObject *
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

#ifdef GUESTFS_HAVE_GET_SOCKDIR
PyObject *
guestfs_int_py_get_sockdir (PyObject *self, PyObject *args)
{
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  char *r;

  if (!PyArg_ParseTuple (args, (char *) "O:guestfs_get_sockdir",
                         &py_g))
    goto out;
  g = get_handle (py_g);

  r = guestfs_get_sockdir (g);

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
PyObject *
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

#ifdef GUESTFS_HAVE_HIVEX_NODE_GET_CHILD
PyObject *
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

#ifdef GUESTFS_HAVE_HIVEX_NODE_SET_VALUE
PyObject *
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

#ifdef GUESTFS_HAVE_HIVEX_VALUE_KEY
PyObject *
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
PyObject *
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

#ifdef GUESTFS_HAVE_INSPECT_GET_DISTRO
PyObject *
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

#ifdef GUESTFS_HAVE_INSPECT_GET_FILESYSTEMS
PyObject *
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

  py_r = guestfs_int_py_put_string_list (r);
  guestfs_int_free_string_list (r);

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_INSPECT_GET_MINOR_VERSION
PyObject *
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

#ifdef GUESTFS_HAVE_INSPECT_GET_PACKAGE_FORMAT
PyObject *
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

#ifdef GUESTFS_HAVE_INSPECT_GET_PRODUCT_VARIANT
PyObject *
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

#ifdef GUESTFS_HAVE_INSPECT_LIST_APPLICATIONS
PyObject *
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

  py_r = guestfs_int_py_put_application_list (r);
  guestfs_free_application_list (r);

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_INSPECT_OS
PyObject *
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

  py_r = guestfs_int_py_put_string_list (r);
  guestfs_int_free_string_list (r);

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_INTERNAL_TEST_RBOOLERR
PyObject *
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

#ifdef GUESTFS_HAVE_INTERNAL_TEST_RSTRING
PyObject *
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

#ifdef GUESTFS_HAVE_INTERNAL_TEST_RSTRUCTERR
PyObject *
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

  py_r = guestfs_int_py_put_lvm_pv (r);
  guestfs_free_lvm_pv (r);

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_JOURNAL_GET
PyObject *
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

  py_r = guestfs_int_py_put_xattr_list (r);
  guestfs_free_xattr_list (r);

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_JOURNAL_GET_DATA_THRESHOLD
PyObject *
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

#ifdef GUESTFS_HAVE_LDMTOOL_DISKGROUP_NAME
PyObject *
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
PyObject *
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

  py_r = guestfs_int_py_put_string_list (r);
  guestfs_int_free_string_list (r);

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_LL
PyObject *
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

#ifdef GUESTFS_HAVE_LN_F
PyObject *
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
PyObject *
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

#ifdef GUESTFS_HAVE_LREMOVEXATTR
PyObject *
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

#ifdef GUESTFS_HAVE_LSTATNSLIST
PyObject *
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
  names = guestfs_int_py_get_string_list (py_names);
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

  py_r = guestfs_int_py_put_statns_list (r);
  guestfs_free_statns_list (r);

  PyErr_Clear ();
 out:
  free (names);
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_LUKS_CLOSE
PyObject *
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

#ifdef GUESTFS_HAVE_LVREMOVE
PyObject *
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

#ifdef GUESTFS_HAVE_MD_STOP
PyObject *
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

#ifdef GUESTFS_HAVE_MKFS_BTRFS
PyObject *
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
  devices = guestfs_int_py_get_string_list (py_devices);
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
PyObject *
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
PyObject *
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

#ifdef GUESTFS_HAVE_MKSWAP_FILE
PyObject *
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

#ifdef GUESTFS_HAVE_MOUNT_9P
PyObject *
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

#ifdef GUESTFS_HAVE_MOUNTABLE_DEVICE
PyObject *
guestfs_int_py_mountable_device (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  char *r;
  const char *mountable;

  if (!PyArg_ParseTuple (args, (char *) "Os:guestfs_mountable_device",
                         &py_g, &mountable))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_mountable_device (g, mountable);

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

#ifdef GUESTFS_HAVE_MV
PyObject *
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

#ifdef GUESTFS_HAVE_NTFSRESIZE_OPTS
PyObject *
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

#ifdef GUESTFS_HAVE_PART_DISK
PyObject *
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

#ifdef GUESTFS_HAVE_PART_EXPAND_GPT
PyObject *
guestfs_int_py_part_expand_gpt (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  int r;
  const char *device;

  if (!PyArg_ParseTuple (args, (char *) "Os:guestfs_part_expand_gpt",
                         &py_g, &device))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_part_expand_gpt (g, device);

  if (PyEval_ThreadsInitialized ())
    PyEval_RestoreThread (py_save);

  if (r == -1) {
    PyErr_SetString (PyExc_RuntimeError, guestfs_last_error (g));
    goto out;
  }

  Py_INCREF (Py_None);
  py_r = Py_None;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_PART_GET_PARTTYPE
PyObject *
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

#ifdef GUESTFS_HAVE_PVCREATE
PyObject *
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

#ifdef GUESTFS_HAVE_PVS
PyObject *
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

  py_r = guestfs_int_py_put_string_list (r);
  guestfs_int_free_string_list (r);

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_PWRITE
PyObject *
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

#ifdef GUESTFS_HAVE_READ_FILE
PyObject *
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

#ifdef GUESTFS_HAVE_RENAME
PyObject *
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

#ifdef GUESTFS_HAVE_RESIZE2FS_M
PyObject *
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

#ifdef GUESTFS_HAVE_RM_RF
PyObject *
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

#ifdef GUESTFS_HAVE_SCRUB_FILE
PyObject *
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

#ifdef GUESTFS_HAVE_SET_APPEND
PyObject *
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

#ifdef GUESTFS_HAVE_SET_BACKEND
PyObject *
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

#ifdef GUESTFS_HAVE_SET_DIRECT
PyObject *
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

#ifdef GUESTFS_HAVE_SET_MEMSIZE
PyObject *
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

#ifdef GUESTFS_HAVE_SET_PROGRAM
PyObject *
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

#ifdef GUESTFS_HAVE_SET_SELINUX
PyObject *
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

#ifdef GUESTFS_HAVE_SETXATTR
PyObject *
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

#ifdef GUESTFS_HAVE_SFDISK_L
PyObject *
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

#ifdef GUESTFS_HAVE_UMOUNT_LOCAL
PyObject *
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

#ifdef GUESTFS_HAVE_VFS_LABEL
PyObject *
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

#ifdef GUESTFS_HAVE_VG_ACTIVATE_ALL
PyObject *
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

#ifdef GUESTFS_HAVE_VGCHANGE_UUID_ALL
PyObject *
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

#ifdef GUESTFS_HAVE_VGMETA
PyObject *
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

#ifdef GUESTFS_HAVE_VGRENAME
PyObject *
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

#ifdef GUESTFS_HAVE_VGUUID
PyObject *
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

#ifdef GUESTFS_HAVE_WC_W
PyObject *
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

#ifdef GUESTFS_HAVE_WRITE
PyObject *
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

#ifdef GUESTFS_HAVE_ZFGREPI
PyObject *
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

  py_r = guestfs_int_py_put_string_list (r);
  guestfs_int_free_string_list (r);

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

