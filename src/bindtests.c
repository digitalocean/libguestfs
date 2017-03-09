/* libguestfs generated file
 * WARNING: THIS FILE IS GENERATED FROM THE FOLLOWING FILES:
 *          generator/bindtests.ml
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

#include <config.h>

#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <string.h>

#include "guestfs.h"
#include "guestfs-internal.h"
#include "guestfs-internal-actions.h"
#include "guestfs_protocol.h"

#include "intprops.h"

int
guestfs_impl_internal_test_set_output (guestfs_h *g, const char *filename)
{
  FILE *fp;

  fp = fopen (filename, "w");
  if (fp == NULL) {
    perrorf (g, "cannot open output file %s\n", filename);
    return -1;
  }

  if (guestfs_internal_test_close_output (g) == -1) {
    fclose (fp);
    return -1;
  }

  g->test_fp = fp;

  return 0;
}

int
guestfs_impl_internal_test_close_output (guestfs_h *g)
{
  if (g->test_fp != NULL) {
    if (fclose (g->test_fp) == EOF) {
      perrorf (g, "fclose");
      g->test_fp = NULL;
      return -1;
    }
    g->test_fp = NULL;
  }

  return 0;
}

static inline FILE *
get_fp (guestfs_h *g)
{
  if (g->test_fp)
    return g->test_fp;
  else
    return stdout;
}

static void
print_strings (guestfs_h *g, char *const *argv)
{
  FILE *fp = get_fp (g);
  size_t argc;

  fprintf (fp, "[");
  for (argc = 0; argv[argc] != NULL; ++argc) {
    if (argc > 0) fprintf (fp, ", ");
    fprintf (fp, "\"%s\"", argv[argc]);
  }
  fprintf (fp, "]\n");
}

/* Fill an lvm_pv struct with known data.  Used by
 * guestfs_internal_test_rstruct & guestfs_internal_test_rstructlist.
 */
static void
fill_lvm_pv (guestfs_h *g, struct guestfs_lvm_pv *pv, size_t i)
{
  pv->pv_name = safe_asprintf (g, "pv%zu", i);
  memcpy (pv->pv_uuid, "12345678901234567890123456789012", 32);
  pv->pv_fmt = safe_strdup (g, "unknown");
  pv->pv_size = i;
  pv->dev_size = i;
  pv->pv_free = i;
  pv->pv_used = i;
  pv->pv_attr = safe_asprintf (g, "attr%zu", i);
  pv->pv_pe_count = i;
  pv->pv_pe_alloc_count = i;
  pv->pv_tags = safe_asprintf (g, "tag%zu", i);
  pv->pe_start = i;
  pv->pv_mda_count = i;
  pv->pv_mda_free = i;
}

/* The internal_test function prints its parameters to stdout or the
 * file set by internal_test_set_output.
 */
int
guestfs_impl_internal_test (guestfs_h *g,
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
                            const struct guestfs_internal_test_argv *optargs)
{
  FILE *fp = get_fp (g);

  fprintf (fp, "%s\n", str);
  fprintf (fp, "%s\n", optstr ? optstr : "null");
  print_strings (g, strlist);
  fprintf (fp, "%s\n", b ? "true" : "false");
  fprintf (fp, "%d\n", integer);
  fprintf (fp, "%" PRIi64 "\n", integer64);
  fprintf (fp, "%s\n", filein);
  fprintf (fp, "%s\n", fileout);
  {
    size_t i;
    for (i = 0; i < bufferin_size; ++i)
      fprintf (fp, "<%02x>", (unsigned) bufferin[i]);
    fprintf (fp, "\n");
  }
  fprintf (fp, "obool: ");
  if (optargs->bitmask & GUESTFS_INTERNAL_TEST_OBOOL_BITMASK) {
    fprintf (fp, "%s\n", optargs->obool ? "true" : "false");
  } else {
    fprintf (fp, "unset\n");
  }
  fprintf (fp, "oint: ");
  if (optargs->bitmask & GUESTFS_INTERNAL_TEST_OINT_BITMASK) {
    fprintf (fp, "%i\n", optargs->oint);
  } else {
    fprintf (fp, "unset\n");
  }
  fprintf (fp, "oint64: ");
  if (optargs->bitmask & GUESTFS_INTERNAL_TEST_OINT64_BITMASK) {
    fprintf (fp, "%" PRIi64 "\n", optargs->oint64);
  } else {
    fprintf (fp, "unset\n");
  }
  fprintf (fp, "ostring: ");
  if (optargs->bitmask & GUESTFS_INTERNAL_TEST_OSTRING_BITMASK) {
    fprintf (fp, "%s\n", optargs->ostring);
  } else {
    fprintf (fp, "unset\n");
  }
  fprintf (fp, "ostringlist: ");
  if (optargs->bitmask & GUESTFS_INTERNAL_TEST_OSTRINGLIST_BITMASK) {
    print_strings (g, optargs->ostringlist);
  } else {
    fprintf (fp, "unset\n");
  }
  /* Java changes stdout line buffering so we need this: */
  fflush (fp);
  return 0;
}

/* The internal_test_only_optargs function prints its parameters to stdout or the
 * file set by internal_test_set_output.
 */
int
guestfs_impl_internal_test_only_optargs (guestfs_h *g,
                                         const struct guestfs_internal_test_only_optargs_argv *optargs)
{
  FILE *fp = get_fp (g);

  fprintf (fp, "test: ");
  if (optargs->bitmask & GUESTFS_INTERNAL_TEST_ONLY_OPTARGS_TEST_BITMASK) {
    fprintf (fp, "%i\n", optargs->test);
  } else {
    fprintf (fp, "unset\n");
  }
  /* Java changes stdout line buffering so we need this: */
  fflush (fp);
  return 0;
}

/* The internal_test_63_optargs function prints its parameters to stdout or the
 * file set by internal_test_set_output.
 */
int
guestfs_impl_internal_test_63_optargs (guestfs_h *g,
                                       const struct guestfs_internal_test_63_optargs_argv *optargs)
{
  FILE *fp = get_fp (g);

  fprintf (fp, "opt1: ");
  if (optargs->bitmask & GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT1_BITMASK) {
    fprintf (fp, "%i\n", optargs->opt1);
  } else {
    fprintf (fp, "unset\n");
  }
  fprintf (fp, "opt2: ");
  if (optargs->bitmask & GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT2_BITMASK) {
    fprintf (fp, "%i\n", optargs->opt2);
  } else {
    fprintf (fp, "unset\n");
  }
  fprintf (fp, "opt3: ");
  if (optargs->bitmask & GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT3_BITMASK) {
    fprintf (fp, "%i\n", optargs->opt3);
  } else {
    fprintf (fp, "unset\n");
  }
  fprintf (fp, "opt4: ");
  if (optargs->bitmask & GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT4_BITMASK) {
    fprintf (fp, "%i\n", optargs->opt4);
  } else {
    fprintf (fp, "unset\n");
  }
  fprintf (fp, "opt5: ");
  if (optargs->bitmask & GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT5_BITMASK) {
    fprintf (fp, "%i\n", optargs->opt5);
  } else {
    fprintf (fp, "unset\n");
  }
  fprintf (fp, "opt6: ");
  if (optargs->bitmask & GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT6_BITMASK) {
    fprintf (fp, "%i\n", optargs->opt6);
  } else {
    fprintf (fp, "unset\n");
  }
  fprintf (fp, "opt7: ");
  if (optargs->bitmask & GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT7_BITMASK) {
    fprintf (fp, "%i\n", optargs->opt7);
  } else {
    fprintf (fp, "unset\n");
  }
  fprintf (fp, "opt8: ");
  if (optargs->bitmask & GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT8_BITMASK) {
    fprintf (fp, "%i\n", optargs->opt8);
  } else {
    fprintf (fp, "unset\n");
  }
  fprintf (fp, "opt9: ");
  if (optargs->bitmask & GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT9_BITMASK) {
    fprintf (fp, "%i\n", optargs->opt9);
  } else {
    fprintf (fp, "unset\n");
  }
  fprintf (fp, "opt10: ");
  if (optargs->bitmask & GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT10_BITMASK) {
    fprintf (fp, "%i\n", optargs->opt10);
  } else {
    fprintf (fp, "unset\n");
  }
  fprintf (fp, "opt11: ");
  if (optargs->bitmask & GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT11_BITMASK) {
    fprintf (fp, "%i\n", optargs->opt11);
  } else {
    fprintf (fp, "unset\n");
  }
  fprintf (fp, "opt12: ");
  if (optargs->bitmask & GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT12_BITMASK) {
    fprintf (fp, "%i\n", optargs->opt12);
  } else {
    fprintf (fp, "unset\n");
  }
  fprintf (fp, "opt13: ");
  if (optargs->bitmask & GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT13_BITMASK) {
    fprintf (fp, "%i\n", optargs->opt13);
  } else {
    fprintf (fp, "unset\n");
  }
  fprintf (fp, "opt14: ");
  if (optargs->bitmask & GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT14_BITMASK) {
    fprintf (fp, "%i\n", optargs->opt14);
  } else {
    fprintf (fp, "unset\n");
  }
  fprintf (fp, "opt15: ");
  if (optargs->bitmask & GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT15_BITMASK) {
    fprintf (fp, "%i\n", optargs->opt15);
  } else {
    fprintf (fp, "unset\n");
  }
  fprintf (fp, "opt16: ");
  if (optargs->bitmask & GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT16_BITMASK) {
    fprintf (fp, "%i\n", optargs->opt16);
  } else {
    fprintf (fp, "unset\n");
  }
  fprintf (fp, "opt17: ");
  if (optargs->bitmask & GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT17_BITMASK) {
    fprintf (fp, "%i\n", optargs->opt17);
  } else {
    fprintf (fp, "unset\n");
  }
  fprintf (fp, "opt18: ");
  if (optargs->bitmask & GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT18_BITMASK) {
    fprintf (fp, "%i\n", optargs->opt18);
  } else {
    fprintf (fp, "unset\n");
  }
  fprintf (fp, "opt19: ");
  if (optargs->bitmask & GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT19_BITMASK) {
    fprintf (fp, "%i\n", optargs->opt19);
  } else {
    fprintf (fp, "unset\n");
  }
  fprintf (fp, "opt20: ");
  if (optargs->bitmask & GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT20_BITMASK) {
    fprintf (fp, "%i\n", optargs->opt20);
  } else {
    fprintf (fp, "unset\n");
  }
  fprintf (fp, "opt21: ");
  if (optargs->bitmask & GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT21_BITMASK) {
    fprintf (fp, "%i\n", optargs->opt21);
  } else {
    fprintf (fp, "unset\n");
  }
  fprintf (fp, "opt22: ");
  if (optargs->bitmask & GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT22_BITMASK) {
    fprintf (fp, "%i\n", optargs->opt22);
  } else {
    fprintf (fp, "unset\n");
  }
  fprintf (fp, "opt23: ");
  if (optargs->bitmask & GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT23_BITMASK) {
    fprintf (fp, "%i\n", optargs->opt23);
  } else {
    fprintf (fp, "unset\n");
  }
  fprintf (fp, "opt24: ");
  if (optargs->bitmask & GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT24_BITMASK) {
    fprintf (fp, "%i\n", optargs->opt24);
  } else {
    fprintf (fp, "unset\n");
  }
  fprintf (fp, "opt25: ");
  if (optargs->bitmask & GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT25_BITMASK) {
    fprintf (fp, "%i\n", optargs->opt25);
  } else {
    fprintf (fp, "unset\n");
  }
  fprintf (fp, "opt26: ");
  if (optargs->bitmask & GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT26_BITMASK) {
    fprintf (fp, "%i\n", optargs->opt26);
  } else {
    fprintf (fp, "unset\n");
  }
  fprintf (fp, "opt27: ");
  if (optargs->bitmask & GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT27_BITMASK) {
    fprintf (fp, "%i\n", optargs->opt27);
  } else {
    fprintf (fp, "unset\n");
  }
  fprintf (fp, "opt28: ");
  if (optargs->bitmask & GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT28_BITMASK) {
    fprintf (fp, "%i\n", optargs->opt28);
  } else {
    fprintf (fp, "unset\n");
  }
  fprintf (fp, "opt29: ");
  if (optargs->bitmask & GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT29_BITMASK) {
    fprintf (fp, "%i\n", optargs->opt29);
  } else {
    fprintf (fp, "unset\n");
  }
  fprintf (fp, "opt30: ");
  if (optargs->bitmask & GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT30_BITMASK) {
    fprintf (fp, "%i\n", optargs->opt30);
  } else {
    fprintf (fp, "unset\n");
  }
  fprintf (fp, "opt31: ");
  if (optargs->bitmask & GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT31_BITMASK) {
    fprintf (fp, "%i\n", optargs->opt31);
  } else {
    fprintf (fp, "unset\n");
  }
  fprintf (fp, "opt32: ");
  if (optargs->bitmask & GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT32_BITMASK) {
    fprintf (fp, "%i\n", optargs->opt32);
  } else {
    fprintf (fp, "unset\n");
  }
  fprintf (fp, "opt33: ");
  if (optargs->bitmask & GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT33_BITMASK) {
    fprintf (fp, "%i\n", optargs->opt33);
  } else {
    fprintf (fp, "unset\n");
  }
  fprintf (fp, "opt34: ");
  if (optargs->bitmask & GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT34_BITMASK) {
    fprintf (fp, "%i\n", optargs->opt34);
  } else {
    fprintf (fp, "unset\n");
  }
  fprintf (fp, "opt35: ");
  if (optargs->bitmask & GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT35_BITMASK) {
    fprintf (fp, "%i\n", optargs->opt35);
  } else {
    fprintf (fp, "unset\n");
  }
  fprintf (fp, "opt36: ");
  if (optargs->bitmask & GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT36_BITMASK) {
    fprintf (fp, "%i\n", optargs->opt36);
  } else {
    fprintf (fp, "unset\n");
  }
  fprintf (fp, "opt37: ");
  if (optargs->bitmask & GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT37_BITMASK) {
    fprintf (fp, "%i\n", optargs->opt37);
  } else {
    fprintf (fp, "unset\n");
  }
  fprintf (fp, "opt38: ");
  if (optargs->bitmask & GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT38_BITMASK) {
    fprintf (fp, "%i\n", optargs->opt38);
  } else {
    fprintf (fp, "unset\n");
  }
  fprintf (fp, "opt39: ");
  if (optargs->bitmask & GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT39_BITMASK) {
    fprintf (fp, "%i\n", optargs->opt39);
  } else {
    fprintf (fp, "unset\n");
  }
  fprintf (fp, "opt40: ");
  if (optargs->bitmask & GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT40_BITMASK) {
    fprintf (fp, "%i\n", optargs->opt40);
  } else {
    fprintf (fp, "unset\n");
  }
  fprintf (fp, "opt41: ");
  if (optargs->bitmask & GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT41_BITMASK) {
    fprintf (fp, "%i\n", optargs->opt41);
  } else {
    fprintf (fp, "unset\n");
  }
  fprintf (fp, "opt42: ");
  if (optargs->bitmask & GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT42_BITMASK) {
    fprintf (fp, "%i\n", optargs->opt42);
  } else {
    fprintf (fp, "unset\n");
  }
  fprintf (fp, "opt43: ");
  if (optargs->bitmask & GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT43_BITMASK) {
    fprintf (fp, "%i\n", optargs->opt43);
  } else {
    fprintf (fp, "unset\n");
  }
  fprintf (fp, "opt44: ");
  if (optargs->bitmask & GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT44_BITMASK) {
    fprintf (fp, "%i\n", optargs->opt44);
  } else {
    fprintf (fp, "unset\n");
  }
  fprintf (fp, "opt45: ");
  if (optargs->bitmask & GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT45_BITMASK) {
    fprintf (fp, "%i\n", optargs->opt45);
  } else {
    fprintf (fp, "unset\n");
  }
  fprintf (fp, "opt46: ");
  if (optargs->bitmask & GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT46_BITMASK) {
    fprintf (fp, "%i\n", optargs->opt46);
  } else {
    fprintf (fp, "unset\n");
  }
  fprintf (fp, "opt47: ");
  if (optargs->bitmask & GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT47_BITMASK) {
    fprintf (fp, "%i\n", optargs->opt47);
  } else {
    fprintf (fp, "unset\n");
  }
  fprintf (fp, "opt48: ");
  if (optargs->bitmask & GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT48_BITMASK) {
    fprintf (fp, "%i\n", optargs->opt48);
  } else {
    fprintf (fp, "unset\n");
  }
  fprintf (fp, "opt49: ");
  if (optargs->bitmask & GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT49_BITMASK) {
    fprintf (fp, "%i\n", optargs->opt49);
  } else {
    fprintf (fp, "unset\n");
  }
  fprintf (fp, "opt50: ");
  if (optargs->bitmask & GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT50_BITMASK) {
    fprintf (fp, "%i\n", optargs->opt50);
  } else {
    fprintf (fp, "unset\n");
  }
  fprintf (fp, "opt51: ");
  if (optargs->bitmask & GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT51_BITMASK) {
    fprintf (fp, "%i\n", optargs->opt51);
  } else {
    fprintf (fp, "unset\n");
  }
  fprintf (fp, "opt52: ");
  if (optargs->bitmask & GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT52_BITMASK) {
    fprintf (fp, "%i\n", optargs->opt52);
  } else {
    fprintf (fp, "unset\n");
  }
  fprintf (fp, "opt53: ");
  if (optargs->bitmask & GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT53_BITMASK) {
    fprintf (fp, "%i\n", optargs->opt53);
  } else {
    fprintf (fp, "unset\n");
  }
  fprintf (fp, "opt54: ");
  if (optargs->bitmask & GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT54_BITMASK) {
    fprintf (fp, "%i\n", optargs->opt54);
  } else {
    fprintf (fp, "unset\n");
  }
  fprintf (fp, "opt55: ");
  if (optargs->bitmask & GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT55_BITMASK) {
    fprintf (fp, "%i\n", optargs->opt55);
  } else {
    fprintf (fp, "unset\n");
  }
  fprintf (fp, "opt56: ");
  if (optargs->bitmask & GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT56_BITMASK) {
    fprintf (fp, "%i\n", optargs->opt56);
  } else {
    fprintf (fp, "unset\n");
  }
  fprintf (fp, "opt57: ");
  if (optargs->bitmask & GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT57_BITMASK) {
    fprintf (fp, "%i\n", optargs->opt57);
  } else {
    fprintf (fp, "unset\n");
  }
  fprintf (fp, "opt58: ");
  if (optargs->bitmask & GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT58_BITMASK) {
    fprintf (fp, "%i\n", optargs->opt58);
  } else {
    fprintf (fp, "unset\n");
  }
  fprintf (fp, "opt59: ");
  if (optargs->bitmask & GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT59_BITMASK) {
    fprintf (fp, "%i\n", optargs->opt59);
  } else {
    fprintf (fp, "unset\n");
  }
  fprintf (fp, "opt60: ");
  if (optargs->bitmask & GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT60_BITMASK) {
    fprintf (fp, "%i\n", optargs->opt60);
  } else {
    fprintf (fp, "unset\n");
  }
  fprintf (fp, "opt61: ");
  if (optargs->bitmask & GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT61_BITMASK) {
    fprintf (fp, "%i\n", optargs->opt61);
  } else {
    fprintf (fp, "unset\n");
  }
  fprintf (fp, "opt62: ");
  if (optargs->bitmask & GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT62_BITMASK) {
    fprintf (fp, "%i\n", optargs->opt62);
  } else {
    fprintf (fp, "unset\n");
  }
  fprintf (fp, "opt63: ");
  if (optargs->bitmask & GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT63_BITMASK) {
    fprintf (fp, "%i\n", optargs->opt63);
  } else {
    fprintf (fp, "unset\n");
  }
  /* Java changes stdout line buffering so we need this: */
  fflush (fp);
  return 0;
}

/* Test normal return. */
int
guestfs_impl_internal_test_rint (guestfs_h *g,
                                 const char *val)
{
  int r;
  if (sscanf (val, "%d", &r) != 1) {
    error (g, "%s: expecting int argument", "internal_test_rint");
    return -1;
  }
  return r;
}

/* Test error return. */
int
guestfs_impl_internal_test_rinterr (guestfs_h *g)
{
  error (g, "error");
  return -1;
}

/* Test normal return. */
int64_t
guestfs_impl_internal_test_rint64 (guestfs_h *g,
                                   const char *val)
{
  int64_t r;
  if (sscanf (val, "%" SCNi64, &r) != 1) {
    error (g, "%s: expecting int64 argument", "internal_test_rint64");
    return -1;
  }
  return r;
}

/* Test error return. */
int64_t
guestfs_impl_internal_test_rint64err (guestfs_h *g)
{
  error (g, "error");
  return -1;
}

/* Test normal return. */
int
guestfs_impl_internal_test_rbool (guestfs_h *g,
                                  const char *val)
{
  return STREQ (val, "true");
}

/* Test error return. */
int
guestfs_impl_internal_test_rboolerr (guestfs_h *g)
{
  error (g, "error");
  return -1;
}

/* Test normal return. */
const char *
guestfs_impl_internal_test_rconststring (guestfs_h *g,
                                         const char *val)
{
  return "static string";
}

/* Test error return. */
const char *
guestfs_impl_internal_test_rconststringerr (guestfs_h *g)
{
  error (g, "error");
  return NULL;
}

/* Test normal return. */
const char *
guestfs_impl_internal_test_rconstoptstring (guestfs_h *g,
                                            const char *val)
{
  return "static string";
}

/* Test error return. */
const char *
guestfs_impl_internal_test_rconstoptstringerr (guestfs_h *g)
{
  error (g, "error");
  return NULL;
}

/* Test normal return. */
char *
guestfs_impl_internal_test_rstring (guestfs_h *g,
                                    const char *val)
{
  return strdup (val);
}

/* Test error return. */
char *
guestfs_impl_internal_test_rstringerr (guestfs_h *g)
{
  error (g, "error");
  return NULL;
}

/* Test normal return. */
char **
guestfs_impl_internal_test_rstringlist (guestfs_h *g,
                                        const char *val)
{
  char **strs;
  size_t n, i;
  if (sscanf (val, "%zu", &n) != 1) {
    error (g, "%s: expecting int argument", "internal_test_rstringlist");
    return NULL;
  }
  strs = safe_malloc (g, (n+1) * sizeof (char *));
  for (i = 0; i < n; ++i) {
    strs[i] = safe_malloc (g, INT_BUFSIZE_BOUND (i));
    snprintf (strs[i], INT_BUFSIZE_BOUND (i), "%zu", i);
  }
  strs[n] = NULL;
  return strs;
}

/* Test error return. */
char **
guestfs_impl_internal_test_rstringlisterr (guestfs_h *g)
{
  error (g, "error");
  return NULL;
}

/* Test normal return. */
struct guestfs_lvm_pv *
guestfs_impl_internal_test_rstruct (guestfs_h *g,
                                    const char *val)
{
  struct guestfs_lvm_pv *r;
  r = safe_malloc (g, sizeof *r);
  fill_lvm_pv (g, r, 0);
  return r;
}

/* Test error return. */
struct guestfs_lvm_pv *
guestfs_impl_internal_test_rstructerr (guestfs_h *g)
{
  error (g, "error");
  return NULL;
}

/* Test normal return. */
struct guestfs_lvm_pv_list *
guestfs_impl_internal_test_rstructlist (guestfs_h *g,
                                        const char *val)
{
  struct guestfs_lvm_pv_list *r;
  uint32_t len;
  if (sscanf (val, "%" SCNu32, &len) != 1) {
    error (g, "%s: expecting uint32 argument", "internal_test_rstructlist");
    return NULL;
  }
  r = safe_malloc (g, sizeof *r);
  r->len = len;
  r->val = safe_malloc (g, r->len * sizeof (*r->val));
  for (size_t i = 0; i < r->len; i++)
    fill_lvm_pv (g, &r->val[i], i);
  return r;
}

/* Test error return. */
struct guestfs_lvm_pv_list *
guestfs_impl_internal_test_rstructlisterr (guestfs_h *g)
{
  error (g, "error");
  return NULL;
}

/* Test normal return. */
char **
guestfs_impl_internal_test_rhashtable (guestfs_h *g,
                                       const char *val)
{
  char **strs;
  size_t n, i;
  if (sscanf (val, "%zu", &n) != 1) {
    error (g, "%s: expecting int argument", "internal_test_rhashtable");
    return NULL;
  }
  strs = safe_malloc (g, (n*2+1) * sizeof (*strs));
  for (i = 0; i < n; ++i) {
    strs[i*2] = safe_malloc (g, INT_BUFSIZE_BOUND (i));
    strs[i*2+1] = safe_malloc (g, INT_BUFSIZE_BOUND (i));
    snprintf (strs[i*2], INT_BUFSIZE_BOUND (i), "%zu", i);
    snprintf (strs[i*2+1], INT_BUFSIZE_BOUND (i), "%zu", i);
  }
  strs[n*2] = NULL;
  return strs;
}

/* Test error return. */
char **
guestfs_impl_internal_test_rhashtableerr (guestfs_h *g)
{
  error (g, "error");
  return NULL;
}

/* Test normal return. */
char *
guestfs_impl_internal_test_rbufferout (guestfs_h *g,
                                       const char *val,
                                       size_t *size_r)
{
  *size_r = strlen (val);
  return strdup (val);
}

/* Test error return. */
char *
guestfs_impl_internal_test_rbufferouterr (guestfs_h *g,
                                          size_t *size_r)
{
  error (g, "error");
  return NULL;
}

