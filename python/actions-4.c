/* libguestfs generated file
 * WARNING: THIS FILE IS GENERATED FROM THE FOLLOWING FILES:
 *          generator/python.ml
 *          and from the code in the generator/ subdirectory.
 * ANY CHANGES YOU MAKE TO THIS FILE WILL BE LOST.
 *
 * Copyright (C) 2009-2019 Red Hat Inc.
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

#ifdef GUESTFS_HAVE_ADD_CDROM
PyObject *
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

#ifdef GUESTFS_HAVE_ADD_LIBVIRT_DOM
PyObject *
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
    optargs_s.iface = guestfs_int_py_asstring (py_iface);
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
    optargs_s.readonlydisk = guestfs_int_py_asstring (py_readonlydisk);
  }
#endif
#ifdef GUESTFS_ADD_LIBVIRT_DOM_CACHEMODE_BITMASK
  if (py_cachemode != Py_None) {
    optargs_s.bitmask |= GUESTFS_ADD_LIBVIRT_DOM_CACHEMODE_BITMASK;
    optargs_s.cachemode = guestfs_int_py_asstring (py_cachemode);
  }
#endif
#ifdef GUESTFS_ADD_LIBVIRT_DOM_DISCARD_BITMASK
  if (py_discard != Py_None) {
    optargs_s.bitmask |= GUESTFS_ADD_LIBVIRT_DOM_DISCARD_BITMASK;
    optargs_s.discard = guestfs_int_py_asstring (py_discard);
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

#ifdef GUESTFS_HAVE_AUG_INIT
PyObject *
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
PyObject *
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

#ifdef GUESTFS_HAVE_AUG_LOAD
PyObject *
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

#ifdef GUESTFS_HAVE_AUG_RM
PyObject *
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

#ifdef GUESTFS_HAVE_AUG_SET
PyObject *
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

#ifdef GUESTFS_HAVE_BLKID
PyObject *
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

  py_r = guestfs_int_py_put_table (r);
  guestfs_int_free_string_list (r);
  if (py_r == NULL) goto out;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_BLOCKDEV_SETRA
PyObject *
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

#ifdef GUESTFS_HAVE_BTRFS_SCRUB_START
PyObject *
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
PyObject *
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

  py_r = guestfs_int_py_put_btrfsscrub (r);
  guestfs_free_btrfsscrub (r);
  if (py_r == NULL) goto out;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_BTRFS_SUBVOLUME_CREATE_OPTS
PyObject *
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
    optargs_s.qgroupid = guestfs_int_py_asstring (py_qgroupid);
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

#ifdef GUESTFS_HAVE_BTRFS_SUBVOLUME_SET_DEFAULT
PyObject *
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

#ifdef GUESTFS_HAVE_BTRFS_SUBVOLUME_SNAPSHOT_OPTS
PyObject *
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
    optargs_s.qgroupid = guestfs_int_py_asstring (py_qgroupid);
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

#ifdef GUESTFS_HAVE_CANONICAL_DEVICE_NAME
PyObject *
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

  py_r = guestfs_int_py_fromstring (r);
  free (r);
  if (py_r == NULL) goto out;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_CASE_SENSITIVE_PATH
PyObject *
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

  py_r = guestfs_int_py_fromstring (r);
  free (r);
  if (py_r == NULL) goto out;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_COPY_SIZE
PyObject *
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

#ifdef GUESTFS_HAVE_DEBUG_UPLOAD
PyObject *
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

#ifdef GUESTFS_HAVE_DOWNLOAD_OFFSET
PyObject *
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

#ifdef GUESTFS_HAVE_FIND_INODE
PyObject *
guestfs_int_py_find_inode (PyObject *self, PyObject *args)
{
  PyThreadState *py_save = NULL;
  PyObject *py_g;
  guestfs_h *g;
  PyObject *py_r = NULL;
  struct guestfs_tsk_dirent_list *r;
  const char *device;
  long long inode;

  if (!PyArg_ParseTuple (args, (char *) "OsL:guestfs_find_inode",
                         &py_g, &device, &inode))
    goto out;
  g = get_handle (py_g);

  if (PyEval_ThreadsInitialized ())
    py_save = PyEval_SaveThread ();

  r = guestfs_find_inode (g, device, inode);

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

#ifdef GUESTFS_HAVE_FINDFS_UUID
PyObject *
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

  py_r = guestfs_int_py_fromstring (r);
  free (r);
  if (py_r == NULL) goto out;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_FSTRIM
PyObject *
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

#ifdef GUESTFS_HAVE_GET_AUTOSYNC
PyObject *
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

#ifdef GUESTFS_HAVE_GET_E2UUID
PyObject *
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

  py_r = guestfs_int_py_fromstring (r);
  free (r);
  if (py_r == NULL) goto out;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_GET_LIBVIRT_REQUESTED_CREDENTIAL_CHALLENGE
PyObject *
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

  py_r = guestfs_int_py_fromstring (r);
  free (r);
  if (py_r == NULL) goto out;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_GET_PID
PyObject *
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

#ifdef GUESTFS_HAVE_GET_SELINUX
PyObject *
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

#ifdef GUESTFS_HAVE_GREPI
PyObject *
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

  py_r = guestfs_int_py_put_string_list (r);
  guestfs_int_free_string_list (r);
  if (py_r == NULL) goto out;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_HEXDUMP
PyObject *
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

  py_r = guestfs_int_py_fromstring (r);
  free (r);
  if (py_r == NULL) goto out;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_HIVEX_NODE_CHILDREN
PyObject *
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

  py_r = guestfs_int_py_put_hivex_node_list (r);
  guestfs_free_hivex_node_list (r);
  if (py_r == NULL) goto out;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_INSPECT_GET_FORMAT
PyObject *
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

  py_r = guestfs_int_py_fromstring (r);
  free (r);
  if (py_r == NULL) goto out;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_INSPECT_GET_HOSTNAME
PyObject *
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

  py_r = guestfs_int_py_fromstring (r);
  free (r);
  if (py_r == NULL) goto out;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_INSPECT_IS_MULTIPART
PyObject *
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

#ifdef GUESTFS_HAVE_INTERNAL_TEST_RBOOL
PyObject *
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

#ifdef GUESTFS_HAVE_INTERNAL_TEST_RHASHTABLE
PyObject *
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

  py_r = guestfs_int_py_put_table (r);
  guestfs_int_free_string_list (r);
  if (py_r == NULL) goto out;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_INTERNAL_TEST_RSTRINGLIST
PyObject *
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

  py_r = guestfs_int_py_put_string_list (r);
  guestfs_int_free_string_list (r);
  if (py_r == NULL) goto out;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_INTERNAL_TEST_RSTRINGLISTERR
PyObject *
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

  py_r = guestfs_int_py_put_string_list (r);
  guestfs_int_free_string_list (r);
  if (py_r == NULL) goto out;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_IS_BUSY
PyObject *
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

#ifdef GUESTFS_HAVE_IS_READY
PyObject *
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

#ifdef GUESTFS_HAVE_LDMTOOL_SCAN
PyObject *
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

  py_r = guestfs_int_py_put_string_list (r);
  guestfs_int_free_string_list (r);
  if (py_r == NULL) goto out;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_LGETXATTRS
PyObject *
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

  py_r = guestfs_int_py_put_xattr_list (r);
  guestfs_free_xattr_list (r);
  if (py_r == NULL) goto out;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_LIST_DM_DEVICES
PyObject *
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

  py_r = guestfs_int_py_put_string_list (r);
  guestfs_int_free_string_list (r);
  if (py_r == NULL) goto out;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_LIST_LDM_VOLUMES
PyObject *
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

  py_r = guestfs_int_py_put_string_list (r);
  guestfs_int_free_string_list (r);
  if (py_r == NULL) goto out;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_LUKS_FORMAT
PyObject *
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

#ifdef GUESTFS_HAVE_LVM_CANONICAL_LV_NAME
PyObject *
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

  py_r = guestfs_int_py_fromstring (r);
  free (r);
  if (py_r == NULL) goto out;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_LVRENAME
PyObject *
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
PyObject *
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

#ifdef GUESTFS_HAVE_LVUUID
PyObject *
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

  py_r = guestfs_int_py_fromstring (r);
  free (r);
  if (py_r == NULL) goto out;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_MKE2FS_J
PyObject *
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

#ifdef GUESTFS_HAVE_MKE2JOURNAL_U
PyObject *
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

#ifdef GUESTFS_HAVE_MKNOD_C
PyObject *
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

#ifdef GUESTFS_HAVE_MOUNT_OPTIONS
PyObject *
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

#ifdef GUESTFS_HAVE_NTFSFIX
PyObject *
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

#ifdef GUESTFS_HAVE_PART_ADD
PyObject *
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

#ifdef GUESTFS_HAVE_PART_GET_GPT_GUID
PyObject *
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

  py_r = guestfs_int_py_fromstring (r);
  free (r);
  if (py_r == NULL) goto out;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_PART_GET_MBR_ID
PyObject *
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
PyObject *
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

  py_r = guestfs_int_py_fromstring (r);
  free (r);
  if (py_r == NULL) goto out;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_PART_GET_NAME
PyObject *
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

  py_r = guestfs_int_py_fromstring (r);
  free (r);
  if (py_r == NULL) goto out;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_PART_INIT
PyObject *
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

#ifdef GUESTFS_HAVE_PART_TO_PARTNUM
PyObject *
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

#ifdef GUESTFS_HAVE_PVUUID
PyObject *
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

  py_r = guestfs_int_py_fromstring (r);
  free (r);
  if (py_r == NULL) goto out;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_READLINKLIST
PyObject *
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
  names = guestfs_int_py_get_string_list (py_names);
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

  py_r = guestfs_int_py_put_string_list (r);
  guestfs_int_free_string_list (r);
  if (py_r == NULL) goto out;

  PyErr_Clear ();
 out:
  free (names);
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_RMMOUNTPOINT
PyObject *
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

#ifdef GUESTFS_HAVE_SCRUB_DEVICE
PyObject *
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

#ifdef GUESTFS_HAVE_SET_CACHEDIR
PyObject *
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

#ifdef GUESTFS_HAVE_SET_E2ATTRS
PyObject *
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

#ifdef GUESTFS_HAVE_SET_E2LABEL
PyObject *
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

#ifdef GUESTFS_HAVE_SH_LINES
PyObject *
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

  py_r = guestfs_int_py_put_string_list (r);
  guestfs_int_free_string_list (r);
  if (py_r == NULL) goto out;

  PyErr_Clear ();
 out:
  return py_r;
}
#endif

#ifdef GUESTFS_HAVE_SHUTDOWN
PyObject *
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

#ifdef GUESTFS_HAVE_SWAPON_FILE
PyObject *
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

#ifdef GUESTFS_HAVE_TGZ_OUT
PyObject *
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

#ifdef GUESTFS_HAVE_UMASK
PyObject *
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

#ifdef GUESTFS_HAVE_WIPEFS
PyObject *
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

