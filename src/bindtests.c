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

#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <string.h>

#include "guestfs.h"
#include "guestfs-internal.h"
#include "guestfs-internal-actions.h"
#include "guestfs_protocol.h"

static void
print_strings (char *const *argv)
{
  size_t argc;

  printf ("[");
  for (argc = 0; argv[argc] != NULL; ++argc) {
    if (argc > 0) printf (", ");
    printf ("\"%s\"", argv[argc]);
  }
  printf ("]\n");
}

/* The test0 function prints its parameters to stdout. */
int
guestfs__test0 (guestfs_h *g,
                const char *str,
                const char *optstr,
                char *const *strlist,
                int b,
                int integer,
                int64_t integer64,
                const char *filein,
                const char *fileout,
                const char *bufferin,
                size_t bufferin_size,
                const struct guestfs_test0_argv *optargs)
{
  printf ("%s\n", str);
  printf ("%s\n", optstr ? optstr : "null");
  print_strings (strlist);
  printf ("%s\n", b ? "true" : "false");
  printf ("%d\n", integer);
  printf ("%" PRIi64 "\n", integer64);
  printf ("%s\n", filein);
  printf ("%s\n", fileout);
  {
    size_t i;
    for (i = 0; i < bufferin_size; ++i)
      printf ("<%02x>", bufferin[i]);
    printf ("\n");
  }
  printf ("obool: ");
  if (optargs->bitmask & GUESTFS_TEST0_OBOOL_BITMASK) {
    printf("%s\n", optargs->obool ? "true" : "false");
  } else {
    printf ("unset\n");
  }
  printf ("oint: ");
  if (optargs->bitmask & GUESTFS_TEST0_OINT_BITMASK) {
    printf("%i\n", optargs->oint);
  } else {
    printf ("unset\n");
  }
  printf ("oint64: ");
  if (optargs->bitmask & GUESTFS_TEST0_OINT64_BITMASK) {
    printf("%" PRIi64 "\n", optargs->oint64);
  } else {
    printf ("unset\n");
  }
  printf ("ostring: ");
  if (optargs->bitmask & GUESTFS_TEST0_OSTRING_BITMASK) {
    printf("%s\n", optargs->ostring);
  } else {
    printf ("unset\n");
  }
  /* Java changes stdout line buffering so we need this: */
  fflush (stdout);
  return 0;
}

/* Test normal return. */
int
guestfs__test0rint (guestfs_h *g,
                    const char *val)
{
  int r;
  if (sscanf (val, "%d", &r) != 1) {
    error (g, "%s: expecting int argument", "test0rint");
    return -1;
  }
  return r;
}

/* Test error return. */
int
guestfs__test0rinterr (guestfs_h *g)
{
  error (g, "error");
  return -1;
}

/* Test normal return. */
int64_t
guestfs__test0rint64 (guestfs_h *g,
                      const char *val)
{
  int64_t r;
  if (sscanf (val, "%" SCNi64, &r) != 1) {
    error (g, "%s: expecting int64 argument", "test0rint64");
    return -1;
  }
  return r;
}

/* Test error return. */
int64_t
guestfs__test0rint64err (guestfs_h *g)
{
  error (g, "error");
  return -1;
}

/* Test normal return. */
int
guestfs__test0rbool (guestfs_h *g,
                     const char *val)
{
  return STREQ (val, "true");
}

/* Test error return. */
int
guestfs__test0rboolerr (guestfs_h *g)
{
  error (g, "error");
  return -1;
}

/* Test normal return. */
const char *
guestfs__test0rconststring (guestfs_h *g,
                            const char *val)
{
  return "static string";
}

/* Test error return. */
const char *
guestfs__test0rconststringerr (guestfs_h *g)
{
  error (g, "error");
  return NULL;
}

/* Test normal return. */
const char *
guestfs__test0rconstoptstring (guestfs_h *g,
                               const char *val)
{
  return "static string";
}

/* Test error return. */
const char *
guestfs__test0rconstoptstringerr (guestfs_h *g)
{
  error (g, "error");
  return NULL;
}

/* Test normal return. */
char *
guestfs__test0rstring (guestfs_h *g,
                       const char *val)
{
  return strdup (val);
}

/* Test error return. */
char *
guestfs__test0rstringerr (guestfs_h *g)
{
  error (g, "error");
  return NULL;
}

/* Test normal return. */
char **
guestfs__test0rstringlist (guestfs_h *g,
                           const char *val)
{
  char **strs;
  int n, i;
  if (sscanf (val, "%d", &n) != 1) {
    error (g, "%s: expecting int argument", "test0rstringlist");
    return NULL;
  }
  strs = safe_malloc (g, (n+1) * sizeof (char *));
  for (i = 0; i < n; ++i) {
    strs[i] = safe_malloc (g, 16);
    snprintf (strs[i], 16, "%d", i);
  }
  strs[n] = NULL;
  return strs;
}

/* Test error return. */
char **
guestfs__test0rstringlisterr (guestfs_h *g)
{
  error (g, "error");
  return NULL;
}

/* Test normal return. */
struct guestfs_lvm_pv *
guestfs__test0rstruct (guestfs_h *g,
                       const char *val)
{
  struct guestfs_lvm_pv *r;
  r = safe_calloc (g, sizeof *r, 1);
  return r;
}

/* Test error return. */
struct guestfs_lvm_pv *
guestfs__test0rstructerr (guestfs_h *g)
{
  error (g, "error");
  return NULL;
}

/* Test normal return. */
struct guestfs_lvm_pv_list *
guestfs__test0rstructlist (guestfs_h *g,
                           const char *val)
{
  struct guestfs_lvm_pv_list *r;
  uint32_t len;
  if (sscanf (val, "%" SCNu32, &len) != 1) {
    error (g, "%s: expecting uint32 argument", "test0rstructlist");
    return NULL;
  }
  r = safe_calloc (g, sizeof *r, 1);
  r->len = len;
  r->val = safe_calloc (g, r->len, sizeof *r->val);
  for (size_t i = 0; i < r->len; i++) {
    r->val[i].pv_size = i;
  }
  return r;
}

/* Test error return. */
struct guestfs_lvm_pv_list *
guestfs__test0rstructlisterr (guestfs_h *g)
{
  error (g, "error");
  return NULL;
}

/* Test normal return. */
char **
guestfs__test0rhashtable (guestfs_h *g,
                          const char *val)
{
  char **strs;
  int n, i;
  if (sscanf (val, "%d", &n) != 1) {
    error (g, "%s: expecting int argument", "test0rhashtable");
    return NULL;
  }
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
char **
guestfs__test0rhashtableerr (guestfs_h *g)
{
  error (g, "error");
  return NULL;
}

/* Test normal return. */
char *
guestfs__test0rbufferout (guestfs_h *g,
                          const char *val,
                          size_t *size_r)
{
  *size_r = strlen (val);
  return strdup (val);
}

/* Test error return. */
char *
guestfs__test0rbufferouterr (guestfs_h *g,
                             size_t *size_r)
{
  error (g, "error");
  return NULL;
}

