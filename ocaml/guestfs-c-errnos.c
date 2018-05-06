/* libguestfs generated file
 * WARNING: THIS FILE IS GENERATED FROM THE FOLLOWING FILES:
 *          generator/ocaml.ml
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

#include <config.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include <caml/config.h>
#include <caml/alloc.h>
#include <caml/fail.h>
#include <caml/memory.h>
#include <caml/mlvalues.h>

#include "guestfs.h"

#include "guestfs-c.h"

/* These prototypes are solely to quiet gcc warnings. */
value guestfs_int_ocaml_get_EINVAL (value unitv);
value guestfs_int_ocaml_get_ENOTSUP (value unitv);
value guestfs_int_ocaml_get_EPERM (value unitv);
value guestfs_int_ocaml_get_ESRCH (value unitv);
value guestfs_int_ocaml_get_ENOENT (value unitv);
value guestfs_int_ocaml_get_EROFS (value unitv);

/* NB: "noalloc" function. */
value
guestfs_int_ocaml_get_EINVAL (value unitv)
{
  return Val_int (EINVAL);
}

/* NB: "noalloc" function. */
value
guestfs_int_ocaml_get_ENOTSUP (value unitv)
{
  return Val_int (ENOTSUP);
}

/* NB: "noalloc" function. */
value
guestfs_int_ocaml_get_EPERM (value unitv)
{
  return Val_int (EPERM);
}

/* NB: "noalloc" function. */
value
guestfs_int_ocaml_get_ESRCH (value unitv)
{
  return Val_int (ESRCH);
}

/* NB: "noalloc" function. */
value
guestfs_int_ocaml_get_ENOENT (value unitv)
{
  return Val_int (ENOENT);
}

/* NB: "noalloc" function. */
value
guestfs_int_ocaml_get_EROFS (value unitv)
{
  return Val_int (EROFS);
}
