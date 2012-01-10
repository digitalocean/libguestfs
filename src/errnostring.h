/* libguestfs generated file
 * WARNING: THIS FILE IS GENERATED FROM:
 *   generator/generator_*.ml
 * ANY CHANGES YOU MAKE TO THIS FILE WILL BE LOST.
 *
 * Copyright (C) 2009-2012 Red Hat Inc.
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


#ifndef GUESTFS_ERRNOSTRING_H_
#define GUESTFS_ERRNOSTRING_H_

/* Convert errno (eg. EIO) to its string representation ("EIO").
 * This only works for a set of errors that are listed in the generator
 * AND are supported on the local operating system.  For other errors
 * the string ("EINVAL") is returned.
 *
 * NOTE: It is an error to call this function with errnum == 0.
 */
extern const char *guestfs___errno_to_string (int errnum);

/* Convert string representation of an error (eg. "EIO") to the errno
 * value (EIO).  As for the function above, this only works for a
 * subset of errors.  For errors not supported by the local operating
 * system, EINVAL is returned (all POSIX-conforming systems must
 * support EINVAL).
 */
extern int guestfs___string_to_errno (const char *errnostr);

/* Private structure and function used by the perfect hash implementation. */
struct errnostring_entry { char *name; int errnum; };
extern const struct errnostring_entry *guestfs___string_to_errno_lookup (register const char *str, register unsigned int len);

#endif /* GUESTFS_ERRNOSTRING_H_ */
