/* libguestfs
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

#ifndef GUESTFS_OCAML_C_H
#define GUESTFS_OCAML_C_H

#include "guestfs-internal-frontend.h"

#define Guestfs_val(v) (*((guestfs_h **)Data_custom_val(v)))
extern void guestfs_int_ocaml_raise_error (guestfs_h *g, const char *func)
  Noreturn;
extern void guestfs_int_ocaml_raise_closed (const char *func)
  Noreturn;
extern char **guestfs_int_ocaml_strings_val (guestfs_h *g, value sv);

#endif /* GUESTFS_OCAML_C_H */
