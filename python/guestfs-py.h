/* libguestfs python bindings
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

#ifndef guestfs_py_h
#define guestfs_py_h

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

#endif /* guestfs_py_h */
