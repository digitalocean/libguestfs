/* libguestfs generated file
 * WARNING: THIS FILE IS GENERATED BY 'src/generator.ml'.
 * ANY CHANGES YOU MAKE TO THIS FILE WILL BE LOST.
 *
 * Copyright (C) 2009 Red Hat Inc.
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

#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <string.h>

#include "guestfs.h"
#include "guestfs_protocol.h"

#define error guestfs_error
#define safe_calloc guestfs_safe_calloc
#define safe_malloc guestfs_safe_malloc

static void
print_strings (char * const* const argv)
{
  int argc;

  printf ("[");
  for (argc = 0; argv[argc] != NULL; ++argc) {
    if (argc > 0) printf (", ");
    printf ("\"%s\"", argv[argc]);
  }
  printf ("]\n");
}

/* The test0 function prints its parameters to stdout. */
int guestfs_test0 (guestfs_h *g,
		const char *str,
		const char *optstr,
		char * const* const strlist,
		int b,
		int integer,
		const char *filein,
		const char *fileout)
{
  printf ("%s\n", str);
  printf ("%s\n", optstr ? optstr : "null");
  print_strings (strlist);
  printf ("%s\n", b ? "true" : "false");
  printf ("%d\n", integer);
  printf ("%s\n", filein);
  printf ("%s\n", fileout);
  /* Java changes stdout line buffering so we need this: */
  fflush (stdout);
  return 0;
}

/* Test normal return. */
int guestfs_test0rint (guestfs_h *g,
		const char *val)
{
  int r;
  sscanf (val, "%d", &r);
  return r;
}

/* Test error return. */
int guestfs_test0rinterr (guestfs_h *g)
{
  error (g, "error");
  return -1;
}

/* Test normal return. */
int64_t guestfs_test0rint64 (guestfs_h *g,
		const char *val)
{
  int64_t r;
  sscanf (val, "%" SCNi64, &r);
  return r;
}

/* Test error return. */
int64_t guestfs_test0rint64err (guestfs_h *g)
{
  error (g, "error");
  return -1;
}

/* Test normal return. */
int guestfs_test0rbool (guestfs_h *g,
		const char *val)
{
  return strcmp (val, "true") == 0;
}

/* Test error return. */
int guestfs_test0rboolerr (guestfs_h *g)
{
  error (g, "error");
  return -1;
}

/* Test normal return. */
const char *guestfs_test0rconststring (guestfs_h *g,
		const char *val)
{
  return "static string";
}

/* Test error return. */
const char *guestfs_test0rconststringerr (guestfs_h *g)
{
  error (g, "error");
  return NULL;
}

/* Test normal return. */
char *guestfs_test0rstring (guestfs_h *g,
		const char *val)
{
  return strdup (val);
}

/* Test error return. */
char *guestfs_test0rstringerr (guestfs_h *g)
{
  error (g, "error");
  return NULL;
}

/* Test normal return. */
char **guestfs_test0rstringlist (guestfs_h *g,
		const char *val)
{
  char **strs;
  int n, i;
  sscanf (val, "%d", &n);
  strs = safe_malloc (g, (n+1) * sizeof (char *));
  for (i = 0; i < n; ++i) {
    strs[i] = safe_malloc (g, 16);
    snprintf (strs[i], 16, "%d", i);
  }
  strs[n] = NULL;
  return strs;
}

/* Test error return. */
char **guestfs_test0rstringlisterr (guestfs_h *g)
{
  error (g, "error");
  return NULL;
}

/* Test normal return. */
struct guestfs_lvm_pv *guestfs_test0rstruct (guestfs_h *g,
		const char *val)
{
  struct guestfs_lvm_pv *r;
  r = safe_calloc (g, sizeof *r, 1);
  return r;
}

/* Test error return. */
struct guestfs_lvm_pv *guestfs_test0rstructerr (guestfs_h *g)
{
  error (g, "error");
  return NULL;
}

/* Test normal return. */
struct guestfs_lvm_pv_list *guestfs_test0rstructlist (guestfs_h *g,
		const char *val)
{
  struct guestfs_lvm_pv_list *r;
  r = safe_calloc (g, sizeof *r, 1);
  sscanf (val, "%d", &r->len);
  r->val = safe_calloc (g, r->len, sizeof *r->val);
  return r;
}

/* Test error return. */
struct guestfs_lvm_pv_list *guestfs_test0rstructlisterr (guestfs_h *g)
{
  error (g, "error");
  return NULL;
}

/* Test normal return. */
char **guestfs_test0rhashtable (guestfs_h *g,
		const char *val)
{
  char **strs;
  int n, i;
  sscanf (val, "%d", &n);
  strs = safe_malloc (g, (n*2+1) * sizeof (*strs));
  for (i = 0; i < n; ++i) {
    strs[i*2] = safe_malloc (g, 16);
    strs[i*2+1] = safe_malloc (g, 16);
    snprintf (strs[i*2], 16, "%d", i);
    snprintf (strs[i*2+1], 16, "%d", i);
  }
  strs[n*2] = NULL;
  return strs;
}

/* Test error return. */
char **guestfs_test0rhashtableerr (guestfs_h *g)
{
  error (g, "error");
  return NULL;
}
