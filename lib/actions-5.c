/* libguestfs generated file
 * WARNING: THIS FILE IS GENERATED FROM THE FOLLOWING FILES:
 *          generator/c.ml
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
#include <stdint.h>
#include <inttypes.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>

#include "guestfs.h"
#include "guestfs-internal.h"
#include "guestfs-internal-actions.h"
#include "guestfs_protocol.h"
#include "errnostring.h"
#include "structs-print.h"

GUESTFS_DLL_PUBLIC int
guestfs_add_drive_with_if (guestfs_h *g,
                           const char *filename,
                           const char *iface)
{
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int r;

  if (g->state != CONFIG) {
    error (g, "%s: this function can only be called in the config state",
              "add_drive_with_if");
    return -1;
  }
  guestfs_int_call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                      "add_drive_with_if", 17);
  if (filename == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "add_drive_with_if", "filename");
    return -1;
  }
  if (iface == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "add_drive_with_if", "iface");
    return -1;
  }

  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "add_drive_with_if");
    fprintf (trace_buffer.fp, " \"%s\"", filename);
    fprintf (trace_buffer.fp, " \"%s\"", iface);
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  r = guestfs_impl_add_drive_with_if (g, filename, iface);

  if (r != -1) {
    if (trace_flag) {
      guestfs_int_trace_open (&trace_buffer);
      fprintf (trace_buffer.fp, "%s = ", "add_drive_with_if");
      fprintf (trace_buffer.fp, "%d", r);
      guestfs_int_trace_send_line (g, &trace_buffer);
    }

  } else {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "add_drive_with_if", "-1");
  }

  return r;
}

GUESTFS_DLL_PUBLIC int64_t
guestfs_c_pointer (guestfs_h *g)
{
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int64_t r;

  guestfs_int_call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                      "c_pointer", 9);
  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "c_pointer");
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  r = guestfs_impl_c_pointer (g);

  if (r != -1) {
    if (trace_flag) {
      guestfs_int_trace_open (&trace_buffer);
      fprintf (trace_buffer.fp, "%s = ", "c_pointer");
      fprintf (trace_buffer.fp, "%" PRIi64, r);
      guestfs_int_trace_send_line (g, &trace_buffer);
    }

  } else {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "c_pointer", "-1");
  }

  return r;
}

GUESTFS_DLL_PUBLIC int64_t
guestfs_disk_virtual_size (guestfs_h *g,
                           const char *filename)
{
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int64_t r;

  guestfs_int_call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                      "disk_virtual_size", 17);
  if (filename == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "disk_virtual_size", "filename");
    return -1;
  }

  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "disk_virtual_size");
    fprintf (trace_buffer.fp, " \"%s\"", filename);
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  r = guestfs_impl_disk_virtual_size (g, filename);

  if (r != -1) {
    if (trace_flag) {
      guestfs_int_trace_open (&trace_buffer);
      fprintf (trace_buffer.fp, "%s = ", "disk_virtual_size");
      fprintf (trace_buffer.fp, "%" PRIi64, r);
      guestfs_int_trace_send_line (g, &trace_buffer);
    }

  } else {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "disk_virtual_size", "-1");
  }

  return r;
}

GUESTFS_DLL_PUBLIC int
guestfs_feature_available (guestfs_h *g,
                           char *const *groups)
{
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int r;

  guestfs_int_call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                      "feature_available", 17);
  if (groups == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "feature_available", "groups");
    return -1;
  }

  if (trace_flag) {
    size_t i;

    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "feature_available");
    fputc (' ', trace_buffer.fp);
    fputc ('"', trace_buffer.fp);
    for (i = 0; groups[i]; ++i) {
      if (i > 0) fputc (' ', trace_buffer.fp);
      fputs (groups[i], trace_buffer.fp);
    }
    fputc ('"', trace_buffer.fp);
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  r = guestfs_impl_feature_available (g, groups);

  if (r != -1) {
    if (trace_flag) {
      guestfs_int_trace_open (&trace_buffer);
      fprintf (trace_buffer.fp, "%s = ", "feature_available");
      fprintf (trace_buffer.fp, "%d", r);
      guestfs_int_trace_send_line (g, &trace_buffer);
    }

  } else {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "feature_available", "-1");
  }

  return r;
}

GUESTFS_DLL_PUBLIC const char *
guestfs_get_append (guestfs_h *g)
{
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  const char *r;

  guestfs_int_call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                      "get_append", 10);
  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "get_append");
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  r = guestfs_impl_get_append (g);

  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "get_append");
    fprintf (trace_buffer.fp, "\"%s\"", r != NULL ? r : "NULL");
    guestfs_int_trace_send_line (g, &trace_buffer);
  }


  return r;
}

GUESTFS_DLL_PUBLIC int
guestfs_get_memsize (guestfs_h *g)
{
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int r;

  guestfs_int_call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                      "get_memsize", 11);
  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "get_memsize");
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  r = guestfs_impl_get_memsize (g);

  if (r != -1) {
    if (trace_flag) {
      guestfs_int_trace_open (&trace_buffer);
      fprintf (trace_buffer.fp, "%s = ", "get_memsize");
      fprintf (trace_buffer.fp, "%d", r);
      guestfs_int_trace_send_line (g, &trace_buffer);
    }

  } else {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "get_memsize", "-1");
  }

  return r;
}

GUESTFS_DLL_PUBLIC const char *
guestfs_get_program (guestfs_h *g)
{
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  const char *r;

  guestfs_int_call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                      "get_program", 11);
  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "get_program");
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  r = guestfs_impl_get_program (g);

  if (r != NULL) {
    if (trace_flag) {
      guestfs_int_trace_open (&trace_buffer);
      fprintf (trace_buffer.fp, "%s = ", "get_program");
      fprintf (trace_buffer.fp, "\"%s\"", r);
      guestfs_int_trace_send_line (g, &trace_buffer);
    }

  } else {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "get_program", "NULL");
  }

  return r;
}

GUESTFS_DLL_PUBLIC int
guestfs_inspect_get_major_version (guestfs_h *g,
                                   const char *root)
{
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int r;

  guestfs_int_call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                      "inspect_get_major_version", 25);
  if (root == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "inspect_get_major_version", "root");
    return -1;
  }

  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "inspect_get_major_version");
    fprintf (trace_buffer.fp, " \"%s\"", root);
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  r = guestfs_impl_inspect_get_major_version (g, root);

  if (r != -1) {
    if (trace_flag) {
      guestfs_int_trace_open (&trace_buffer);
      fprintf (trace_buffer.fp, "%s = ", "inspect_get_major_version");
      fprintf (trace_buffer.fp, "%d", r);
      guestfs_int_trace_send_line (g, &trace_buffer);
    }

  } else {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "inspect_get_major_version", "-1");
  }

  return r;
}

GUESTFS_DLL_PUBLIC char **
guestfs_inspect_get_roots (guestfs_h *g)
{
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  char **r;

  guestfs_int_call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                      "inspect_get_roots", 17);
  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "inspect_get_roots");
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  r = guestfs_impl_inspect_get_roots (g);

  if (r != NULL) {
    if (trace_flag) {
      size_t i;

      guestfs_int_trace_open (&trace_buffer);
      fprintf (trace_buffer.fp, "%s = ", "inspect_get_roots");
      fputs ("[", trace_buffer.fp);
      for (i = 0; r[i]; ++i) {
        if (i > 0) fputs (", ", trace_buffer.fp);
        fputs ("\"", trace_buffer.fp);
        fputs (r[i], trace_buffer.fp);
        fputs ("\"", trace_buffer.fp);
      }
      fputs ("]", trace_buffer.fp);
      guestfs_int_trace_send_line (g, &trace_buffer);
    }

  } else {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "inspect_get_roots", "NULL");
  }

  return r;
}

GUESTFS_DLL_PUBLIC int
guestfs_internal_test_argv (guestfs_h *g,
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
  struct guestfs_internal_test_argv optargs_null;
  if (!optargs) {
    optargs_null.bitmask = 0;
    optargs = &optargs_null;
  }

  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int r;

  guestfs_int_call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                      "internal_test", 13);
  if (str == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "internal_test", "str");
    return -1;
  }
  if (strlist == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "internal_test", "strlist");
    return -1;
  }
  if (filein == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "internal_test", "filein");
    return -1;
  }
  if (fileout == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "internal_test", "fileout");
    return -1;
  }
  if (bufferin == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "internal_test", "bufferin");
    return -1;
  }
  if ((optargs->bitmask & GUESTFS_INTERNAL_TEST_OSTRING_BITMASK) &&
      optargs->ostring == NULL) {
    error (g, "%s: %s: optional parameter cannot be NULL",
           "internal_test", "ostring");
    return -1;
  }
  if ((optargs->bitmask & GUESTFS_INTERNAL_TEST_OSTRINGLIST_BITMASK) &&
      optargs->ostringlist == NULL) {
    error (g, "%s: %s: optional list cannot be NULL",
           "internal_test", "ostringlist");
    return -1;
  }

  if (optargs->bitmask & UINT64_C(0xffffffffffffffe0)) {
    error (g, "%s: unknown option in guestfs_%s_argv->bitmask (this can happen if a program is compiled against a newer version of libguestfs, then dynamically linked to an older version)",
           "internal_test", "internal_test");
    return -1;
  }

  if (trace_flag) {
    size_t i;

    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "internal_test");
    fprintf (trace_buffer.fp, " \"%s\"", str);
    if (optstr)
      fprintf (trace_buffer.fp, " \"%s\"", optstr);
    else
      fprintf (trace_buffer.fp, " null");
    fputc (' ', trace_buffer.fp);
    fputc ('"', trace_buffer.fp);
    for (i = 0; strlist[i]; ++i) {
      if (i > 0) fputc (' ', trace_buffer.fp);
      fputs (strlist[i], trace_buffer.fp);
    }
    fputc ('"', trace_buffer.fp);
    fputs (b ? " true" : " false", trace_buffer.fp);
    fprintf (trace_buffer.fp, " %d", integer);
    fprintf (trace_buffer.fp, " %" PRIi64, integer64);
    fprintf (trace_buffer.fp, " \"%s\"", filein);
    fprintf (trace_buffer.fp, " \"%s\"", fileout);
    fputc (' ', trace_buffer.fp);
    guestfs_int_print_BufferIn (trace_buffer.fp, bufferin, bufferin_size);
    if (optargs->bitmask & GUESTFS_INTERNAL_TEST_OBOOL_BITMASK) {
      fprintf (trace_buffer.fp, " \"%s:%s\"", "obool", optargs->obool ? "true" : "false");
    }
    if (optargs->bitmask & GUESTFS_INTERNAL_TEST_OINT_BITMASK) {
      fprintf (trace_buffer.fp, " \"%s:%d\"", "oint", optargs->oint);
    }
    if (optargs->bitmask & GUESTFS_INTERNAL_TEST_OINT64_BITMASK) {
      fprintf (trace_buffer.fp, " \"%s:%" PRIi64 "\"", "oint64", optargs->oint64);
    }
    if (optargs->bitmask & GUESTFS_INTERNAL_TEST_OSTRING_BITMASK) {
      fprintf (trace_buffer.fp, " \"%s:%s\"", "ostring", optargs->ostring);
    }
    if (optargs->bitmask & GUESTFS_INTERNAL_TEST_OSTRINGLIST_BITMASK) {
      fprintf (trace_buffer.fp, " \"%s:", "ostringlist");
      for (i = 0; optargs->ostringlist[i] != NULL; ++i) {
        if (i > 0) fputc (' ', trace_buffer.fp);
        fputs (optargs->ostringlist[i], trace_buffer.fp);
      }
      fputc ('\"', trace_buffer.fp);
    }
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  r = guestfs_impl_internal_test (g, str, optstr, strlist, b, integer, integer64, filein, fileout, bufferin, bufferin_size, optargs);

  if (r != -1) {
    if (trace_flag) {
      guestfs_int_trace_open (&trace_buffer);
      fprintf (trace_buffer.fp, "%s = ", "internal_test");
      fprintf (trace_buffer.fp, "%d", r);
      guestfs_int_trace_send_line (g, &trace_buffer);
    }

  } else {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "internal_test", "-1");
  }

  return r;
}

GUESTFS_DLL_PUBLIC int
guestfs_internal_test_63_optargs_argv (guestfs_h *g,
                                       const struct guestfs_internal_test_63_optargs_argv *optargs)
{
  struct guestfs_internal_test_63_optargs_argv optargs_null;
  if (!optargs) {
    optargs_null.bitmask = 0;
    optargs = &optargs_null;
  }

  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int r;

  guestfs_int_call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                      "internal_test_63_optargs", 24);
  if (optargs->bitmask & UINT64_C(0x8000000000000000)) {
    error (g, "%s: unknown option in guestfs_%s_argv->bitmask (this can happen if a program is compiled against a newer version of libguestfs, then dynamically linked to an older version)",
           "internal_test_63_optargs", "internal_test_63_optargs");
    return -1;
  }

  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "internal_test_63_optargs");
    if (optargs->bitmask & GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT1_BITMASK) {
      fprintf (trace_buffer.fp, " \"%s:%d\"", "opt1", optargs->opt1);
    }
    if (optargs->bitmask & GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT2_BITMASK) {
      fprintf (trace_buffer.fp, " \"%s:%d\"", "opt2", optargs->opt2);
    }
    if (optargs->bitmask & GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT3_BITMASK) {
      fprintf (trace_buffer.fp, " \"%s:%d\"", "opt3", optargs->opt3);
    }
    if (optargs->bitmask & GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT4_BITMASK) {
      fprintf (trace_buffer.fp, " \"%s:%d\"", "opt4", optargs->opt4);
    }
    if (optargs->bitmask & GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT5_BITMASK) {
      fprintf (trace_buffer.fp, " \"%s:%d\"", "opt5", optargs->opt5);
    }
    if (optargs->bitmask & GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT6_BITMASK) {
      fprintf (trace_buffer.fp, " \"%s:%d\"", "opt6", optargs->opt6);
    }
    if (optargs->bitmask & GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT7_BITMASK) {
      fprintf (trace_buffer.fp, " \"%s:%d\"", "opt7", optargs->opt7);
    }
    if (optargs->bitmask & GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT8_BITMASK) {
      fprintf (trace_buffer.fp, " \"%s:%d\"", "opt8", optargs->opt8);
    }
    if (optargs->bitmask & GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT9_BITMASK) {
      fprintf (trace_buffer.fp, " \"%s:%d\"", "opt9", optargs->opt9);
    }
    if (optargs->bitmask & GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT10_BITMASK) {
      fprintf (trace_buffer.fp, " \"%s:%d\"", "opt10", optargs->opt10);
    }
    if (optargs->bitmask & GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT11_BITMASK) {
      fprintf (trace_buffer.fp, " \"%s:%d\"", "opt11", optargs->opt11);
    }
    if (optargs->bitmask & GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT12_BITMASK) {
      fprintf (trace_buffer.fp, " \"%s:%d\"", "opt12", optargs->opt12);
    }
    if (optargs->bitmask & GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT13_BITMASK) {
      fprintf (trace_buffer.fp, " \"%s:%d\"", "opt13", optargs->opt13);
    }
    if (optargs->bitmask & GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT14_BITMASK) {
      fprintf (trace_buffer.fp, " \"%s:%d\"", "opt14", optargs->opt14);
    }
    if (optargs->bitmask & GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT15_BITMASK) {
      fprintf (trace_buffer.fp, " \"%s:%d\"", "opt15", optargs->opt15);
    }
    if (optargs->bitmask & GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT16_BITMASK) {
      fprintf (trace_buffer.fp, " \"%s:%d\"", "opt16", optargs->opt16);
    }
    if (optargs->bitmask & GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT17_BITMASK) {
      fprintf (trace_buffer.fp, " \"%s:%d\"", "opt17", optargs->opt17);
    }
    if (optargs->bitmask & GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT18_BITMASK) {
      fprintf (trace_buffer.fp, " \"%s:%d\"", "opt18", optargs->opt18);
    }
    if (optargs->bitmask & GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT19_BITMASK) {
      fprintf (trace_buffer.fp, " \"%s:%d\"", "opt19", optargs->opt19);
    }
    if (optargs->bitmask & GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT20_BITMASK) {
      fprintf (trace_buffer.fp, " \"%s:%d\"", "opt20", optargs->opt20);
    }
    if (optargs->bitmask & GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT21_BITMASK) {
      fprintf (trace_buffer.fp, " \"%s:%d\"", "opt21", optargs->opt21);
    }
    if (optargs->bitmask & GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT22_BITMASK) {
      fprintf (trace_buffer.fp, " \"%s:%d\"", "opt22", optargs->opt22);
    }
    if (optargs->bitmask & GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT23_BITMASK) {
      fprintf (trace_buffer.fp, " \"%s:%d\"", "opt23", optargs->opt23);
    }
    if (optargs->bitmask & GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT24_BITMASK) {
      fprintf (trace_buffer.fp, " \"%s:%d\"", "opt24", optargs->opt24);
    }
    if (optargs->bitmask & GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT25_BITMASK) {
      fprintf (trace_buffer.fp, " \"%s:%d\"", "opt25", optargs->opt25);
    }
    if (optargs->bitmask & GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT26_BITMASK) {
      fprintf (trace_buffer.fp, " \"%s:%d\"", "opt26", optargs->opt26);
    }
    if (optargs->bitmask & GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT27_BITMASK) {
      fprintf (trace_buffer.fp, " \"%s:%d\"", "opt27", optargs->opt27);
    }
    if (optargs->bitmask & GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT28_BITMASK) {
      fprintf (trace_buffer.fp, " \"%s:%d\"", "opt28", optargs->opt28);
    }
    if (optargs->bitmask & GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT29_BITMASK) {
      fprintf (trace_buffer.fp, " \"%s:%d\"", "opt29", optargs->opt29);
    }
    if (optargs->bitmask & GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT30_BITMASK) {
      fprintf (trace_buffer.fp, " \"%s:%d\"", "opt30", optargs->opt30);
    }
    if (optargs->bitmask & GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT31_BITMASK) {
      fprintf (trace_buffer.fp, " \"%s:%d\"", "opt31", optargs->opt31);
    }
    if (optargs->bitmask & GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT32_BITMASK) {
      fprintf (trace_buffer.fp, " \"%s:%d\"", "opt32", optargs->opt32);
    }
    if (optargs->bitmask & GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT33_BITMASK) {
      fprintf (trace_buffer.fp, " \"%s:%d\"", "opt33", optargs->opt33);
    }
    if (optargs->bitmask & GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT34_BITMASK) {
      fprintf (trace_buffer.fp, " \"%s:%d\"", "opt34", optargs->opt34);
    }
    if (optargs->bitmask & GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT35_BITMASK) {
      fprintf (trace_buffer.fp, " \"%s:%d\"", "opt35", optargs->opt35);
    }
    if (optargs->bitmask & GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT36_BITMASK) {
      fprintf (trace_buffer.fp, " \"%s:%d\"", "opt36", optargs->opt36);
    }
    if (optargs->bitmask & GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT37_BITMASK) {
      fprintf (trace_buffer.fp, " \"%s:%d\"", "opt37", optargs->opt37);
    }
    if (optargs->bitmask & GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT38_BITMASK) {
      fprintf (trace_buffer.fp, " \"%s:%d\"", "opt38", optargs->opt38);
    }
    if (optargs->bitmask & GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT39_BITMASK) {
      fprintf (trace_buffer.fp, " \"%s:%d\"", "opt39", optargs->opt39);
    }
    if (optargs->bitmask & GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT40_BITMASK) {
      fprintf (trace_buffer.fp, " \"%s:%d\"", "opt40", optargs->opt40);
    }
    if (optargs->bitmask & GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT41_BITMASK) {
      fprintf (trace_buffer.fp, " \"%s:%d\"", "opt41", optargs->opt41);
    }
    if (optargs->bitmask & GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT42_BITMASK) {
      fprintf (trace_buffer.fp, " \"%s:%d\"", "opt42", optargs->opt42);
    }
    if (optargs->bitmask & GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT43_BITMASK) {
      fprintf (trace_buffer.fp, " \"%s:%d\"", "opt43", optargs->opt43);
    }
    if (optargs->bitmask & GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT44_BITMASK) {
      fprintf (trace_buffer.fp, " \"%s:%d\"", "opt44", optargs->opt44);
    }
    if (optargs->bitmask & GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT45_BITMASK) {
      fprintf (trace_buffer.fp, " \"%s:%d\"", "opt45", optargs->opt45);
    }
    if (optargs->bitmask & GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT46_BITMASK) {
      fprintf (trace_buffer.fp, " \"%s:%d\"", "opt46", optargs->opt46);
    }
    if (optargs->bitmask & GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT47_BITMASK) {
      fprintf (trace_buffer.fp, " \"%s:%d\"", "opt47", optargs->opt47);
    }
    if (optargs->bitmask & GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT48_BITMASK) {
      fprintf (trace_buffer.fp, " \"%s:%d\"", "opt48", optargs->opt48);
    }
    if (optargs->bitmask & GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT49_BITMASK) {
      fprintf (trace_buffer.fp, " \"%s:%d\"", "opt49", optargs->opt49);
    }
    if (optargs->bitmask & GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT50_BITMASK) {
      fprintf (trace_buffer.fp, " \"%s:%d\"", "opt50", optargs->opt50);
    }
    if (optargs->bitmask & GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT51_BITMASK) {
      fprintf (trace_buffer.fp, " \"%s:%d\"", "opt51", optargs->opt51);
    }
    if (optargs->bitmask & GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT52_BITMASK) {
      fprintf (trace_buffer.fp, " \"%s:%d\"", "opt52", optargs->opt52);
    }
    if (optargs->bitmask & GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT53_BITMASK) {
      fprintf (trace_buffer.fp, " \"%s:%d\"", "opt53", optargs->opt53);
    }
    if (optargs->bitmask & GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT54_BITMASK) {
      fprintf (trace_buffer.fp, " \"%s:%d\"", "opt54", optargs->opt54);
    }
    if (optargs->bitmask & GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT55_BITMASK) {
      fprintf (trace_buffer.fp, " \"%s:%d\"", "opt55", optargs->opt55);
    }
    if (optargs->bitmask & GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT56_BITMASK) {
      fprintf (trace_buffer.fp, " \"%s:%d\"", "opt56", optargs->opt56);
    }
    if (optargs->bitmask & GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT57_BITMASK) {
      fprintf (trace_buffer.fp, " \"%s:%d\"", "opt57", optargs->opt57);
    }
    if (optargs->bitmask & GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT58_BITMASK) {
      fprintf (trace_buffer.fp, " \"%s:%d\"", "opt58", optargs->opt58);
    }
    if (optargs->bitmask & GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT59_BITMASK) {
      fprintf (trace_buffer.fp, " \"%s:%d\"", "opt59", optargs->opt59);
    }
    if (optargs->bitmask & GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT60_BITMASK) {
      fprintf (trace_buffer.fp, " \"%s:%d\"", "opt60", optargs->opt60);
    }
    if (optargs->bitmask & GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT61_BITMASK) {
      fprintf (trace_buffer.fp, " \"%s:%d\"", "opt61", optargs->opt61);
    }
    if (optargs->bitmask & GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT62_BITMASK) {
      fprintf (trace_buffer.fp, " \"%s:%d\"", "opt62", optargs->opt62);
    }
    if (optargs->bitmask & GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT63_BITMASK) {
      fprintf (trace_buffer.fp, " \"%s:%d\"", "opt63", optargs->opt63);
    }
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  r = guestfs_impl_internal_test_63_optargs (g, optargs);

  if (r != -1) {
    if (trace_flag) {
      guestfs_int_trace_open (&trace_buffer);
      fprintf (trace_buffer.fp, "%s = ", "internal_test_63_optargs");
      fprintf (trace_buffer.fp, "%d", r);
      guestfs_int_trace_send_line (g, &trace_buffer);
    }

  } else {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "internal_test_63_optargs", "-1");
  }

  return r;
}

GUESTFS_DLL_PUBLIC char **
guestfs_internal_test_rhashtableerr (guestfs_h *g)
{
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  char **r;

  guestfs_int_call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                      "internal_test_rhashtableerr", 27);
  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "internal_test_rhashtableerr");
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  r = guestfs_impl_internal_test_rhashtableerr (g);

  if (r != NULL) {
    if (trace_flag) {
      size_t i;

      guestfs_int_trace_open (&trace_buffer);
      fprintf (trace_buffer.fp, "%s = ", "internal_test_rhashtableerr");
      fputs ("[", trace_buffer.fp);
      for (i = 0; r[i]; ++i) {
        if (i > 0) fputs (", ", trace_buffer.fp);
        fputs ("\"", trace_buffer.fp);
        fputs (r[i], trace_buffer.fp);
        fputs ("\"", trace_buffer.fp);
      }
      fputs ("]", trace_buffer.fp);
      guestfs_int_trace_send_line (g, &trace_buffer);
    }

  } else {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "internal_test_rhashtableerr", "NULL");
  }

  return r;
}

GUESTFS_DLL_PUBLIC int
guestfs_is_config (guestfs_h *g)
{
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int r;

  guestfs_int_call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                      "is_config", 9);
  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "is_config");
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  r = guestfs_impl_is_config (g);

  if (r != -1) {
    if (trace_flag) {
      guestfs_int_trace_open (&trace_buffer);
      fprintf (trace_buffer.fp, "%s = ", "is_config");
      fprintf (trace_buffer.fp, "%d", r);
      guestfs_int_trace_send_line (g, &trace_buffer);
    }

  } else {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "is_config", "-1");
  }

  return r;
}

GUESTFS_DLL_PUBLIC int
guestfs_parse_environment_list (guestfs_h *g,
                                char *const *environment)
{
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int r;

  guestfs_int_call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                      "parse_environment_list", 22);
  if (environment == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "parse_environment_list", "environment");
    return -1;
  }

  if (trace_flag) {
    size_t i;

    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "parse_environment_list");
    fputc (' ', trace_buffer.fp);
    fputc ('"', trace_buffer.fp);
    for (i = 0; environment[i]; ++i) {
      if (i > 0) fputc (' ', trace_buffer.fp);
      fputs (environment[i], trace_buffer.fp);
    }
    fputc ('"', trace_buffer.fp);
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  r = guestfs_impl_parse_environment_list (g, environment);

  if (r != -1) {
    if (trace_flag) {
      guestfs_int_trace_open (&trace_buffer);
      fprintf (trace_buffer.fp, "%s = ", "parse_environment_list");
      fprintf (trace_buffer.fp, "%d", r);
      guestfs_int_trace_send_line (g, &trace_buffer);
    }

  } else {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "parse_environment_list", "-1");
  }

  return r;
}

GUESTFS_DLL_PUBLIC int
guestfs_set_attach_method (guestfs_h *g,
                           const char *backend)
{
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int r;

  if (g->state != CONFIG) {
    error (g, "%s: this function can only be called in the config state",
              "set_attach_method");
    return -1;
  }
  guestfs_int_call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                      "set_attach_method", 17);
  if (backend == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "set_attach_method", "backend");
    return -1;
  }

  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "set_attach_method");
    fprintf (trace_buffer.fp, " \"%s\"", backend);
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  r = guestfs_impl_set_attach_method (g, backend);

  if (r != -1) {
    if (trace_flag) {
      guestfs_int_trace_open (&trace_buffer);
      fprintf (trace_buffer.fp, "%s = ", "set_attach_method");
      fprintf (trace_buffer.fp, "%d", r);
      guestfs_int_trace_send_line (g, &trace_buffer);
    }

  } else {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "set_attach_method", "-1");
  }

  return r;
}

GUESTFS_DLL_PUBLIC int
guestfs_set_network (guestfs_h *g,
                     int network)
{
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int r;

  if (g->state != CONFIG) {
    error (g, "%s: this function can only be called in the config state",
              "set_network");
    return -1;
  }
  guestfs_int_call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                      "set_network", 11);
  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "set_network");
    fputs (network ? " true" : " false", trace_buffer.fp);
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  r = guestfs_impl_set_network (g, network);

  if (r != -1) {
    if (trace_flag) {
      guestfs_int_trace_open (&trace_buffer);
      fprintf (trace_buffer.fp, "%s = ", "set_network");
      fprintf (trace_buffer.fp, "%d", r);
      guestfs_int_trace_send_line (g, &trace_buffer);
    }

  } else {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "set_network", "-1");
  }

  return r;
}

GUESTFS_DLL_PUBLIC int
guestfs_set_smp (guestfs_h *g,
                 int smp)
{
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int r;

  if (g->state != CONFIG) {
    error (g, "%s: this function can only be called in the config state",
              "set_smp");
    return -1;
  }
  guestfs_int_call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                      "set_smp", 7);
  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "set_smp");
    fprintf (trace_buffer.fp, " %d", smp);
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  r = guestfs_impl_set_smp (g, smp);

  if (r != -1) {
    if (trace_flag) {
      guestfs_int_trace_open (&trace_buffer);
      fprintf (trace_buffer.fp, "%s = ", "set_smp");
      fprintf (trace_buffer.fp, "%d", r);
      guestfs_int_trace_send_line (g, &trace_buffer);
    }

  } else {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "set_smp", "-1");
  }

  return r;
}

GUESTFS_DLL_PUBLIC int
guestfs_set_tmpdir (guestfs_h *g,
                    const char *tmpdir)
{
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int r;

  if (g->state != CONFIG) {
    error (g, "%s: this function can only be called in the config state",
              "set_tmpdir");
    return -1;
  }
  guestfs_int_call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                      "set_tmpdir", 10);
  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "set_tmpdir");
    if (tmpdir)
      fprintf (trace_buffer.fp, " \"%s\"", tmpdir);
    else
      fprintf (trace_buffer.fp, " null");
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  r = guestfs_impl_set_tmpdir (g, tmpdir);

  if (r != -1) {
    if (trace_flag) {
      guestfs_int_trace_open (&trace_buffer);
      fprintf (trace_buffer.fp, "%s = ", "set_tmpdir");
      fprintf (trace_buffer.fp, "%d", r);
      guestfs_int_trace_send_line (g, &trace_buffer);
    }

  } else {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "set_tmpdir", "-1");
  }

  return r;
}

GUESTFS_DLL_PUBLIC int
guestfs_set_trace (guestfs_h *g,
                   int trace)
{
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int r;

  guestfs_int_call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                      "set_trace", 9);
  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "set_trace");
    fputs (trace ? " true" : " false", trace_buffer.fp);
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  r = guestfs_impl_set_trace (g, trace);

  if (r != -1) {
    if (trace_flag) {
      guestfs_int_trace_open (&trace_buffer);
      fprintf (trace_buffer.fp, "%s = ", "set_trace");
      fprintf (trace_buffer.fp, "%d", r);
      guestfs_int_trace_send_line (g, &trace_buffer);
    }

  } else {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "set_trace", "-1");
  }

  return r;
}

GUESTFS_DLL_PUBLIC struct guestfs_stat *
guestfs_stat (guestfs_h *g,
              const char *path)
{
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  struct guestfs_stat *r;

  guestfs_int_call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                      "stat", 4);
  if (path == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "stat", "path");
    return NULL;
  }

  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "stat");
    fprintf (trace_buffer.fp, " \"%s\"", path);
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  r = guestfs_impl_stat (g, path);

  if (r != NULL) {
    if (trace_flag) {
      guestfs_int_trace_open (&trace_buffer);
      fprintf (trace_buffer.fp, "%s = ", "stat");
      fprintf (trace_buffer.fp, "<struct guestfs_stat = ");
      guestfs_int_print_stat_indent (r, trace_buffer.fp, ", ", "");
      fprintf (trace_buffer.fp, ">");
      guestfs_int_trace_send_line (g, &trace_buffer);
    }

  } else {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "stat", "NULL");
  }

  return r;
}

GUESTFS_DLL_PUBLIC int
guestfs_acl_set_file (guestfs_h *g,
                      const char *path,
                      const char *acltype,
                      const char *acl)
{
  struct guestfs_acl_set_file_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs_int_call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                      "acl_set_file", 12);
  if (path == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "acl_set_file", "path");
    return -1;
  }
  if (acltype == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "acl_set_file", "acltype");
    return -1;
  }
  if (acl == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "acl_set_file", "acl");
    return -1;
  }

  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "acl_set_file");
    fprintf (trace_buffer.fp, " \"%s\"", path);
    fprintf (trace_buffer.fp, " \"%s\"", acltype);
    fprintf (trace_buffer.fp, " \"%s\"", acl);
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  if (guestfs_int_check_appliance_up (g, "acl_set_file") == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "acl_set_file", "-1");
    return -1;
  }

  args.path = (char *) path;
  args.acltype = (char *) acltype;
  args.acl = (char *) acl;
  serial = guestfs_int_send (g, GUESTFS_PROC_ACL_SET_FILE,
                             progress_hint, 0,
                             (xdrproc_t) xdr_guestfs_acl_set_file_args, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "acl_set_file", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs_int_recv (g, "acl_set_file", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "acl_set_file", "-1");
    return -1;
  }

  if (guestfs_int_check_reply_header (g, &hdr, GUESTFS_PROC_ACL_SET_FILE, serial) == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "acl_set_file", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "acl_set_file", "-1");
    if (err.errno_string[0] != '\0')
      errnum = guestfs_int_string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "acl_set_file", err.error_message);
    else
      guestfs_int_error_errno (g, errnum, "%s: %s", "acl_set_file",
                               err.error_message);
    free (err.error_message);
    free (err.errno_string);
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "acl_set_file");
    fprintf (trace_buffer.fp, "%d", ret_v);
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  return ret_v;
}

GUESTFS_DLL_PUBLIC int
guestfs_blockdev_flushbufs (guestfs_h *g,
                            const char *device)
{
  struct guestfs_blockdev_flushbufs_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs_int_call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                      "blockdev_flushbufs", 18);
  if (device == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "blockdev_flushbufs", "device");
    return -1;
  }

  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "blockdev_flushbufs");
    fprintf (trace_buffer.fp, " \"%s\"", device);
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  if (guestfs_int_check_appliance_up (g, "blockdev_flushbufs") == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "blockdev_flushbufs", "-1");
    return -1;
  }

  args.device = (char *) device;
  serial = guestfs_int_send (g, GUESTFS_PROC_BLOCKDEV_FLUSHBUFS,
                             progress_hint, 0,
                             (xdrproc_t) xdr_guestfs_blockdev_flushbufs_args, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "blockdev_flushbufs", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs_int_recv (g, "blockdev_flushbufs", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "blockdev_flushbufs", "-1");
    return -1;
  }

  if (guestfs_int_check_reply_header (g, &hdr, GUESTFS_PROC_BLOCKDEV_FLUSHBUFS, serial) == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "blockdev_flushbufs", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "blockdev_flushbufs", "-1");
    if (err.errno_string[0] != '\0')
      errnum = guestfs_int_string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "blockdev_flushbufs", err.error_message);
    else
      guestfs_int_error_errno (g, errnum, "%s: %s", "blockdev_flushbufs",
                               err.error_message);
    free (err.error_message);
    free (err.errno_string);
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "blockdev_flushbufs");
    fprintf (trace_buffer.fp, "%d", ret_v);
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  return ret_v;
}

GUESTFS_DLL_PUBLIC int
guestfs_blockdev_setrw (guestfs_h *g,
                        const char *device)
{
  struct guestfs_blockdev_setrw_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs_int_call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                      "blockdev_setrw", 14);
  if (device == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "blockdev_setrw", "device");
    return -1;
  }

  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "blockdev_setrw");
    fprintf (trace_buffer.fp, " \"%s\"", device);
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  if (guestfs_int_check_appliance_up (g, "blockdev_setrw") == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "blockdev_setrw", "-1");
    return -1;
  }

  args.device = (char *) device;
  serial = guestfs_int_send (g, GUESTFS_PROC_BLOCKDEV_SETRW,
                             progress_hint, 0,
                             (xdrproc_t) xdr_guestfs_blockdev_setrw_args, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "blockdev_setrw", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs_int_recv (g, "blockdev_setrw", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "blockdev_setrw", "-1");
    return -1;
  }

  if (guestfs_int_check_reply_header (g, &hdr, GUESTFS_PROC_BLOCKDEV_SETRW, serial) == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "blockdev_setrw", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "blockdev_setrw", "-1");
    if (err.errno_string[0] != '\0')
      errnum = guestfs_int_string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "blockdev_setrw", err.error_message);
    else
      guestfs_int_error_errno (g, errnum, "%s: %s", "blockdev_setrw",
                               err.error_message);
    free (err.error_message);
    free (err.errno_string);
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "blockdev_setrw");
    fprintf (trace_buffer.fp, "%d", ret_v);
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  return ret_v;
}

GUESTFS_DLL_PUBLIC int
guestfs_btrfs_balance_pause (guestfs_h *g,
                             const char *path)
{
  struct guestfs_btrfs_balance_pause_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs_int_call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                      "btrfs_balance_pause", 19);
  if (path == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "btrfs_balance_pause", "path");
    return -1;
  }

  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "btrfs_balance_pause");
    fprintf (trace_buffer.fp, " \"%s\"", path);
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  if (guestfs_int_check_appliance_up (g, "btrfs_balance_pause") == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "btrfs_balance_pause", "-1");
    return -1;
  }

  args.path = (char *) path;
  serial = guestfs_int_send (g, GUESTFS_PROC_BTRFS_BALANCE_PAUSE,
                             progress_hint, 0,
                             (xdrproc_t) xdr_guestfs_btrfs_balance_pause_args, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "btrfs_balance_pause", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs_int_recv (g, "btrfs_balance_pause", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "btrfs_balance_pause", "-1");
    return -1;
  }

  if (guestfs_int_check_reply_header (g, &hdr, GUESTFS_PROC_BTRFS_BALANCE_PAUSE, serial) == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "btrfs_balance_pause", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "btrfs_balance_pause", "-1");
    if (err.errno_string[0] != '\0')
      errnum = guestfs_int_string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "btrfs_balance_pause", err.error_message);
    else
      guestfs_int_error_errno (g, errnum, "%s: %s", "btrfs_balance_pause",
                               err.error_message);
    free (err.error_message);
    free (err.errno_string);
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "btrfs_balance_pause");
    fprintf (trace_buffer.fp, "%d", ret_v);
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  return ret_v;
}

GUESTFS_DLL_PUBLIC int
guestfs_btrfs_device_add (guestfs_h *g,
                          char *const *devices,
                          const char *fs)
{
  struct guestfs_btrfs_device_add_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs_int_call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                      "btrfs_device_add", 16);
  if (devices == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "btrfs_device_add", "devices");
    return -1;
  }
  if (fs == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "btrfs_device_add", "fs");
    return -1;
  }

  if (trace_flag) {
    size_t i;

    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "btrfs_device_add");
    fputc (' ', trace_buffer.fp);
    fputc ('"', trace_buffer.fp);
    for (i = 0; devices[i]; ++i) {
      if (i > 0) fputc (' ', trace_buffer.fp);
      fputs (devices[i], trace_buffer.fp);
    }
    fputc ('"', trace_buffer.fp);
    fprintf (trace_buffer.fp, " \"%s\"", fs);
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  if (guestfs_int_check_appliance_up (g, "btrfs_device_add") == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "btrfs_device_add", "-1");
    return -1;
  }

  args.devices.devices_val = (char **) devices;
  for (args.devices.devices_len = 0; devices[args.devices.devices_len]; args.devices.devices_len++) ;
  args.fs = (char *) fs;
  serial = guestfs_int_send (g, GUESTFS_PROC_BTRFS_DEVICE_ADD,
                             progress_hint, 0,
                             (xdrproc_t) xdr_guestfs_btrfs_device_add_args, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "btrfs_device_add", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs_int_recv (g, "btrfs_device_add", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "btrfs_device_add", "-1");
    return -1;
  }

  if (guestfs_int_check_reply_header (g, &hdr, GUESTFS_PROC_BTRFS_DEVICE_ADD, serial) == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "btrfs_device_add", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "btrfs_device_add", "-1");
    if (err.errno_string[0] != '\0')
      errnum = guestfs_int_string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "btrfs_device_add", err.error_message);
    else
      guestfs_int_error_errno (g, errnum, "%s: %s", "btrfs_device_add",
                               err.error_message);
    free (err.error_message);
    free (err.errno_string);
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "btrfs_device_add");
    fprintf (trace_buffer.fp, "%d", ret_v);
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  return ret_v;
}

GUESTFS_DLL_PUBLIC int
guestfs_btrfs_filesystem_balance (guestfs_h *g,
                                  const char *fs)
{
  struct guestfs_btrfs_filesystem_balance_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs_int_call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                      "btrfs_filesystem_balance", 24);
  if (fs == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "btrfs_filesystem_balance", "fs");
    return -1;
  }

  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "btrfs_filesystem_balance");
    fprintf (trace_buffer.fp, " \"%s\"", fs);
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  if (guestfs_int_check_appliance_up (g, "btrfs_filesystem_balance") == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "btrfs_filesystem_balance", "-1");
    return -1;
  }

  args.fs = (char *) fs;
  serial = guestfs_int_send (g, GUESTFS_PROC_BTRFS_FILESYSTEM_BALANCE,
                             progress_hint, 0,
                             (xdrproc_t) xdr_guestfs_btrfs_filesystem_balance_args, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "btrfs_filesystem_balance", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs_int_recv (g, "btrfs_filesystem_balance", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "btrfs_filesystem_balance", "-1");
    return -1;
  }

  if (guestfs_int_check_reply_header (g, &hdr, GUESTFS_PROC_BTRFS_FILESYSTEM_BALANCE, serial) == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "btrfs_filesystem_balance", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "btrfs_filesystem_balance", "-1");
    if (err.errno_string[0] != '\0')
      errnum = guestfs_int_string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "btrfs_filesystem_balance", err.error_message);
    else
      guestfs_int_error_errno (g, errnum, "%s: %s", "btrfs_filesystem_balance",
                               err.error_message);
    free (err.error_message);
    free (err.errno_string);
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "btrfs_filesystem_balance");
    fprintf (trace_buffer.fp, "%d", ret_v);
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  return ret_v;
}

GUESTFS_DLL_PUBLIC char **
guestfs_btrfs_filesystem_show (guestfs_h *g,
                               const char *device)
{
  struct guestfs_btrfs_filesystem_show_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  struct guestfs_btrfs_filesystem_show_ret ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  char **ret_v;
  const uint64_t progress_hint = 0;

  guestfs_int_call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                      "btrfs_filesystem_show", 21);
  if (device == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "btrfs_filesystem_show", "device");
    return NULL;
  }

  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "btrfs_filesystem_show");
    fprintf (trace_buffer.fp, " \"%s\"", device);
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  if (guestfs_int_check_appliance_up (g, "btrfs_filesystem_show") == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "btrfs_filesystem_show", "NULL");
    return NULL;
  }

  args.device = (char *) device;
  serial = guestfs_int_send (g, GUESTFS_PROC_BTRFS_FILESYSTEM_SHOW,
                             progress_hint, 0,
                             (xdrproc_t) xdr_guestfs_btrfs_filesystem_show_args, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "btrfs_filesystem_show", "NULL");
    return NULL;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs_int_recv (g, "btrfs_filesystem_show", &hdr, &err,
        (xdrproc_t) xdr_guestfs_btrfs_filesystem_show_ret, (char *) &ret);
  if (r == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "btrfs_filesystem_show", "NULL");
    return NULL;
  }

  if (guestfs_int_check_reply_header (g, &hdr, GUESTFS_PROC_BTRFS_FILESYSTEM_SHOW, serial) == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "btrfs_filesystem_show", "NULL");
    return NULL;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "btrfs_filesystem_show", "NULL");
    if (err.errno_string[0] != '\0')
      errnum = guestfs_int_string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "btrfs_filesystem_show", err.error_message);
    else
      guestfs_int_error_errno (g, errnum, "%s: %s", "btrfs_filesystem_show",
                               err.error_message);
    free (err.error_message);
    free (err.errno_string);
    return NULL;
  }

  /* caller will free this, but we need to add a NULL entry */
  ret.devices.devices_val =
    safe_realloc (g, ret.devices.devices_val,
                  sizeof (char *) * (ret.devices.devices_len + 1));
  ret.devices.devices_val[ret.devices.devices_len] = NULL;
  ret_v = ret.devices.devices_val;
  if (trace_flag) {
    size_t i;

    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "btrfs_filesystem_show");
    fputs ("[", trace_buffer.fp);
    for (i = 0; ret_v[i]; ++i) {
      if (i > 0) fputs (", ", trace_buffer.fp);
      fputs ("\"", trace_buffer.fp);
      fputs (ret_v[i], trace_buffer.fp);
      fputs ("\"", trace_buffer.fp);
    }
    fputs ("]", trace_buffer.fp);
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  return ret_v;
}

GUESTFS_DLL_PUBLIC int
guestfs_btrfs_qgroup_assign (guestfs_h *g,
                             const char *src,
                             const char *dst,
                             const char *path)
{
  struct guestfs_btrfs_qgroup_assign_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs_int_call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                      "btrfs_qgroup_assign", 19);
  if (src == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "btrfs_qgroup_assign", "src");
    return -1;
  }
  if (dst == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "btrfs_qgroup_assign", "dst");
    return -1;
  }
  if (path == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "btrfs_qgroup_assign", "path");
    return -1;
  }

  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "btrfs_qgroup_assign");
    fprintf (trace_buffer.fp, " \"%s\"", src);
    fprintf (trace_buffer.fp, " \"%s\"", dst);
    fprintf (trace_buffer.fp, " \"%s\"", path);
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  if (guestfs_int_check_appliance_up (g, "btrfs_qgroup_assign") == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "btrfs_qgroup_assign", "-1");
    return -1;
  }

  args.src = (char *) src;
  args.dst = (char *) dst;
  args.path = (char *) path;
  serial = guestfs_int_send (g, GUESTFS_PROC_BTRFS_QGROUP_ASSIGN,
                             progress_hint, 0,
                             (xdrproc_t) xdr_guestfs_btrfs_qgroup_assign_args, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "btrfs_qgroup_assign", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs_int_recv (g, "btrfs_qgroup_assign", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "btrfs_qgroup_assign", "-1");
    return -1;
  }

  if (guestfs_int_check_reply_header (g, &hdr, GUESTFS_PROC_BTRFS_QGROUP_ASSIGN, serial) == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "btrfs_qgroup_assign", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "btrfs_qgroup_assign", "-1");
    if (err.errno_string[0] != '\0')
      errnum = guestfs_int_string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "btrfs_qgroup_assign", err.error_message);
    else
      guestfs_int_error_errno (g, errnum, "%s: %s", "btrfs_qgroup_assign",
                               err.error_message);
    free (err.error_message);
    free (err.errno_string);
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "btrfs_qgroup_assign");
    fprintf (trace_buffer.fp, "%d", ret_v);
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  return ret_v;
}

GUESTFS_DLL_PUBLIC int
guestfs_btrfs_replace (guestfs_h *g,
                       const char *srcdev,
                       const char *targetdev,
                       const char *mntpoint)
{
  struct guestfs_btrfs_replace_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs_int_call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                      "btrfs_replace", 13);
  if (srcdev == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "btrfs_replace", "srcdev");
    return -1;
  }
  if (targetdev == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "btrfs_replace", "targetdev");
    return -1;
  }
  if (mntpoint == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "btrfs_replace", "mntpoint");
    return -1;
  }

  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "btrfs_replace");
    fprintf (trace_buffer.fp, " \"%s\"", srcdev);
    fprintf (trace_buffer.fp, " \"%s\"", targetdev);
    fprintf (trace_buffer.fp, " \"%s\"", mntpoint);
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  if (guestfs_int_check_appliance_up (g, "btrfs_replace") == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "btrfs_replace", "-1");
    return -1;
  }

  args.srcdev = (char *) srcdev;
  args.targetdev = (char *) targetdev;
  args.mntpoint = (char *) mntpoint;
  serial = guestfs_int_send (g, GUESTFS_PROC_BTRFS_REPLACE,
                             progress_hint, 0,
                             (xdrproc_t) xdr_guestfs_btrfs_replace_args, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "btrfs_replace", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs_int_recv (g, "btrfs_replace", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "btrfs_replace", "-1");
    return -1;
  }

  if (guestfs_int_check_reply_header (g, &hdr, GUESTFS_PROC_BTRFS_REPLACE, serial) == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "btrfs_replace", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "btrfs_replace", "-1");
    if (err.errno_string[0] != '\0')
      errnum = guestfs_int_string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "btrfs_replace", err.error_message);
    else
      guestfs_int_error_errno (g, errnum, "%s: %s", "btrfs_replace",
                               err.error_message);
    free (err.error_message);
    free (err.errno_string);
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "btrfs_replace");
    fprintf (trace_buffer.fp, "%d", ret_v);
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  return ret_v;
}

GUESTFS_DLL_PUBLIC int
guestfs_btrfs_scrub_cancel (guestfs_h *g,
                            const char *path)
{
  struct guestfs_btrfs_scrub_cancel_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs_int_call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                      "btrfs_scrub_cancel", 18);
  if (path == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "btrfs_scrub_cancel", "path");
    return -1;
  }

  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "btrfs_scrub_cancel");
    fprintf (trace_buffer.fp, " \"%s\"", path);
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  if (guestfs_int_check_appliance_up (g, "btrfs_scrub_cancel") == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "btrfs_scrub_cancel", "-1");
    return -1;
  }

  args.path = (char *) path;
  serial = guestfs_int_send (g, GUESTFS_PROC_BTRFS_SCRUB_CANCEL,
                             progress_hint, 0,
                             (xdrproc_t) xdr_guestfs_btrfs_scrub_cancel_args, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "btrfs_scrub_cancel", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs_int_recv (g, "btrfs_scrub_cancel", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "btrfs_scrub_cancel", "-1");
    return -1;
  }

  if (guestfs_int_check_reply_header (g, &hdr, GUESTFS_PROC_BTRFS_SCRUB_CANCEL, serial) == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "btrfs_scrub_cancel", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "btrfs_scrub_cancel", "-1");
    if (err.errno_string[0] != '\0')
      errnum = guestfs_int_string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "btrfs_scrub_cancel", err.error_message);
    else
      guestfs_int_error_errno (g, errnum, "%s: %s", "btrfs_scrub_cancel",
                               err.error_message);
    free (err.error_message);
    free (err.errno_string);
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "btrfs_scrub_cancel");
    fprintf (trace_buffer.fp, "%d", ret_v);
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  return ret_v;
}

GUESTFS_DLL_PUBLIC int64_t
guestfs_btrfs_subvolume_get_default (guestfs_h *g,
                                     const char *fs)
{
  struct guestfs_btrfs_subvolume_get_default_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  struct guestfs_btrfs_subvolume_get_default_ret ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int64_t ret_v;
  const uint64_t progress_hint = 0;

  guestfs_int_call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                      "btrfs_subvolume_get_default", 27);
  if (fs == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "btrfs_subvolume_get_default", "fs");
    return -1;
  }

  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "btrfs_subvolume_get_default");
    fprintf (trace_buffer.fp, " \"%s\"", fs);
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  if (guestfs_int_check_appliance_up (g, "btrfs_subvolume_get_default") == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "btrfs_subvolume_get_default", "-1");
    return -1;
  }

  args.fs = (char *) fs;
  serial = guestfs_int_send (g, GUESTFS_PROC_BTRFS_SUBVOLUME_GET_DEFAULT,
                             progress_hint, 0,
                             (xdrproc_t) xdr_guestfs_btrfs_subvolume_get_default_args, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "btrfs_subvolume_get_default", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs_int_recv (g, "btrfs_subvolume_get_default", &hdr, &err,
        (xdrproc_t) xdr_guestfs_btrfs_subvolume_get_default_ret, (char *) &ret);
  if (r == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "btrfs_subvolume_get_default", "-1");
    return -1;
  }

  if (guestfs_int_check_reply_header (g, &hdr, GUESTFS_PROC_BTRFS_SUBVOLUME_GET_DEFAULT, serial) == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "btrfs_subvolume_get_default", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "btrfs_subvolume_get_default", "-1");
    if (err.errno_string[0] != '\0')
      errnum = guestfs_int_string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "btrfs_subvolume_get_default", err.error_message);
    else
      guestfs_int_error_errno (g, errnum, "%s: %s", "btrfs_subvolume_get_default",
                               err.error_message);
    free (err.error_message);
    free (err.errno_string);
    return -1;
  }

  ret_v = ret.id;
  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "btrfs_subvolume_get_default");
    fprintf (trace_buffer.fp, "%" PRIi64, ret_v);
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  return ret_v;
}

GUESTFS_DLL_PUBLIC int
guestfs_btrfstune_seeding (guestfs_h *g,
                           const char *device,
                           int seeding)
{
  struct guestfs_btrfstune_seeding_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs_int_call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                      "btrfstune_seeding", 17);
  if (device == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "btrfstune_seeding", "device");
    return -1;
  }

  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "btrfstune_seeding");
    fprintf (trace_buffer.fp, " \"%s\"", device);
    fputs (seeding ? " true" : " false", trace_buffer.fp);
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  if (guestfs_int_check_appliance_up (g, "btrfstune_seeding") == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "btrfstune_seeding", "-1");
    return -1;
  }

  args.device = (char *) device;
  args.seeding = seeding;
  serial = guestfs_int_send (g, GUESTFS_PROC_BTRFSTUNE_SEEDING,
                             progress_hint, 0,
                             (xdrproc_t) xdr_guestfs_btrfstune_seeding_args, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "btrfstune_seeding", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs_int_recv (g, "btrfstune_seeding", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "btrfstune_seeding", "-1");
    return -1;
  }

  if (guestfs_int_check_reply_header (g, &hdr, GUESTFS_PROC_BTRFSTUNE_SEEDING, serial) == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "btrfstune_seeding", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "btrfstune_seeding", "-1");
    if (err.errno_string[0] != '\0')
      errnum = guestfs_int_string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "btrfstune_seeding", err.error_message);
    else
      guestfs_int_error_errno (g, errnum, "%s: %s", "btrfstune_seeding",
                               err.error_message);
    free (err.error_message);
    free (err.errno_string);
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "btrfstune_seeding");
    fprintf (trace_buffer.fp, "%d", ret_v);
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  return ret_v;
}

GUESTFS_DLL_PUBLIC int
guestfs_cap_set_file (guestfs_h *g,
                      const char *path,
                      const char *cap)
{
  struct guestfs_cap_set_file_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs_int_call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                      "cap_set_file", 12);
  if (path == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "cap_set_file", "path");
    return -1;
  }
  if (cap == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "cap_set_file", "cap");
    return -1;
  }

  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "cap_set_file");
    fprintf (trace_buffer.fp, " \"%s\"", path);
    fprintf (trace_buffer.fp, " \"%s\"", cap);
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  if (guestfs_int_check_appliance_up (g, "cap_set_file") == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "cap_set_file", "-1");
    return -1;
  }

  args.path = (char *) path;
  args.cap = (char *) cap;
  serial = guestfs_int_send (g, GUESTFS_PROC_CAP_SET_FILE,
                             progress_hint, 0,
                             (xdrproc_t) xdr_guestfs_cap_set_file_args, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "cap_set_file", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs_int_recv (g, "cap_set_file", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "cap_set_file", "-1");
    return -1;
  }

  if (guestfs_int_check_reply_header (g, &hdr, GUESTFS_PROC_CAP_SET_FILE, serial) == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "cap_set_file", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "cap_set_file", "-1");
    if (err.errno_string[0] != '\0')
      errnum = guestfs_int_string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "cap_set_file", err.error_message);
    else
      guestfs_int_error_errno (g, errnum, "%s: %s", "cap_set_file",
                               err.error_message);
    free (err.error_message);
    free (err.errno_string);
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "cap_set_file");
    fprintf (trace_buffer.fp, "%d", ret_v);
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  return ret_v;
}

GUESTFS_DLL_PUBLIC int
guestfs_copy_file_to_device_argv (guestfs_h *g,
                                  const char *src,
                                  const char *dest,
                                  const struct guestfs_copy_file_to_device_argv *optargs)
{
  struct guestfs_copy_file_to_device_argv optargs_null;
  if (!optargs) {
    optargs_null.bitmask = 0;
    optargs = &optargs_null;
  }

  struct guestfs_copy_file_to_device_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs_int_call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                      "copy_file_to_device", 19);
  if (src == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "copy_file_to_device", "src");
    return -1;
  }
  if (dest == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "copy_file_to_device", "dest");
    return -1;
  }

  if (optargs->bitmask & UINT64_C(0xffffffffffffffe0)) {
    error (g, "%s: unknown option in guestfs_%s_argv->bitmask (this can happen if a program is compiled against a newer version of libguestfs, then dynamically linked to an older version)",
           "copy_file_to_device", "copy_file_to_device");
    return -1;
  }

  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "copy_file_to_device");
    fprintf (trace_buffer.fp, " \"%s\"", src);
    fprintf (trace_buffer.fp, " \"%s\"", dest);
    if (optargs->bitmask & GUESTFS_COPY_FILE_TO_DEVICE_SRCOFFSET_BITMASK) {
      fprintf (trace_buffer.fp, " \"%s:%" PRIi64 "\"", "srcoffset", optargs->srcoffset);
    }
    if (optargs->bitmask & GUESTFS_COPY_FILE_TO_DEVICE_DESTOFFSET_BITMASK) {
      fprintf (trace_buffer.fp, " \"%s:%" PRIi64 "\"", "destoffset", optargs->destoffset);
    }
    if (optargs->bitmask & GUESTFS_COPY_FILE_TO_DEVICE_SIZE_BITMASK) {
      fprintf (trace_buffer.fp, " \"%s:%" PRIi64 "\"", "size", optargs->size);
    }
    if (optargs->bitmask & GUESTFS_COPY_FILE_TO_DEVICE_SPARSE_BITMASK) {
      fprintf (trace_buffer.fp, " \"%s:%s\"", "sparse", optargs->sparse ? "true" : "false");
    }
    if (optargs->bitmask & GUESTFS_COPY_FILE_TO_DEVICE_APPEND_BITMASK) {
      fprintf (trace_buffer.fp, " \"%s:%s\"", "append", optargs->append ? "true" : "false");
    }
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  if (guestfs_int_check_appliance_up (g, "copy_file_to_device") == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "copy_file_to_device", "-1");
    return -1;
  }

  args.src = (char *) src;
  args.dest = (char *) dest;
  if (optargs->bitmask & GUESTFS_COPY_FILE_TO_DEVICE_SRCOFFSET_BITMASK) {
    args.srcoffset = optargs->srcoffset;
  } else {
    args.srcoffset = 0;
  }
  if (optargs->bitmask & GUESTFS_COPY_FILE_TO_DEVICE_DESTOFFSET_BITMASK) {
    args.destoffset = optargs->destoffset;
  } else {
    args.destoffset = 0;
  }
  if (optargs->bitmask & GUESTFS_COPY_FILE_TO_DEVICE_SIZE_BITMASK) {
    args.size = optargs->size;
  } else {
    args.size = 0;
  }
  if (optargs->bitmask & GUESTFS_COPY_FILE_TO_DEVICE_SPARSE_BITMASK) {
    args.sparse = optargs->sparse;
  } else {
    args.sparse = 0;
  }
  if (optargs->bitmask & GUESTFS_COPY_FILE_TO_DEVICE_APPEND_BITMASK) {
    args.append = optargs->append;
  } else {
    args.append = 0;
  }
  serial = guestfs_int_send (g, GUESTFS_PROC_COPY_FILE_TO_DEVICE,
                             progress_hint, optargs->bitmask,
                             (xdrproc_t) xdr_guestfs_copy_file_to_device_args, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "copy_file_to_device", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs_int_recv (g, "copy_file_to_device", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "copy_file_to_device", "-1");
    return -1;
  }

  if (guestfs_int_check_reply_header (g, &hdr, GUESTFS_PROC_COPY_FILE_TO_DEVICE, serial) == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "copy_file_to_device", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "copy_file_to_device", "-1");
    if (err.errno_string[0] != '\0')
      errnum = guestfs_int_string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "copy_file_to_device", err.error_message);
    else
      guestfs_int_error_errno (g, errnum, "%s: %s", "copy_file_to_device",
                               err.error_message);
    free (err.error_message);
    free (err.errno_string);
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "copy_file_to_device");
    fprintf (trace_buffer.fp, "%d", ret_v);
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  return ret_v;
}

GUESTFS_DLL_PUBLIC int
guestfs_copy_file_to_file_argv (guestfs_h *g,
                                const char *src,
                                const char *dest,
                                const struct guestfs_copy_file_to_file_argv *optargs)
{
  struct guestfs_copy_file_to_file_argv optargs_null;
  if (!optargs) {
    optargs_null.bitmask = 0;
    optargs = &optargs_null;
  }

  struct guestfs_copy_file_to_file_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs_int_call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                      "copy_file_to_file", 17);
  if (src == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "copy_file_to_file", "src");
    return -1;
  }
  if (dest == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "copy_file_to_file", "dest");
    return -1;
  }

  if (optargs->bitmask & UINT64_C(0xffffffffffffffe0)) {
    error (g, "%s: unknown option in guestfs_%s_argv->bitmask (this can happen if a program is compiled against a newer version of libguestfs, then dynamically linked to an older version)",
           "copy_file_to_file", "copy_file_to_file");
    return -1;
  }

  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "copy_file_to_file");
    fprintf (trace_buffer.fp, " \"%s\"", src);
    fprintf (trace_buffer.fp, " \"%s\"", dest);
    if (optargs->bitmask & GUESTFS_COPY_FILE_TO_FILE_SRCOFFSET_BITMASK) {
      fprintf (trace_buffer.fp, " \"%s:%" PRIi64 "\"", "srcoffset", optargs->srcoffset);
    }
    if (optargs->bitmask & GUESTFS_COPY_FILE_TO_FILE_DESTOFFSET_BITMASK) {
      fprintf (trace_buffer.fp, " \"%s:%" PRIi64 "\"", "destoffset", optargs->destoffset);
    }
    if (optargs->bitmask & GUESTFS_COPY_FILE_TO_FILE_SIZE_BITMASK) {
      fprintf (trace_buffer.fp, " \"%s:%" PRIi64 "\"", "size", optargs->size);
    }
    if (optargs->bitmask & GUESTFS_COPY_FILE_TO_FILE_SPARSE_BITMASK) {
      fprintf (trace_buffer.fp, " \"%s:%s\"", "sparse", optargs->sparse ? "true" : "false");
    }
    if (optargs->bitmask & GUESTFS_COPY_FILE_TO_FILE_APPEND_BITMASK) {
      fprintf (trace_buffer.fp, " \"%s:%s\"", "append", optargs->append ? "true" : "false");
    }
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  if (guestfs_int_check_appliance_up (g, "copy_file_to_file") == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "copy_file_to_file", "-1");
    return -1;
  }

  args.src = (char *) src;
  args.dest = (char *) dest;
  if (optargs->bitmask & GUESTFS_COPY_FILE_TO_FILE_SRCOFFSET_BITMASK) {
    args.srcoffset = optargs->srcoffset;
  } else {
    args.srcoffset = 0;
  }
  if (optargs->bitmask & GUESTFS_COPY_FILE_TO_FILE_DESTOFFSET_BITMASK) {
    args.destoffset = optargs->destoffset;
  } else {
    args.destoffset = 0;
  }
  if (optargs->bitmask & GUESTFS_COPY_FILE_TO_FILE_SIZE_BITMASK) {
    args.size = optargs->size;
  } else {
    args.size = 0;
  }
  if (optargs->bitmask & GUESTFS_COPY_FILE_TO_FILE_SPARSE_BITMASK) {
    args.sparse = optargs->sparse;
  } else {
    args.sparse = 0;
  }
  if (optargs->bitmask & GUESTFS_COPY_FILE_TO_FILE_APPEND_BITMASK) {
    args.append = optargs->append;
  } else {
    args.append = 0;
  }
  serial = guestfs_int_send (g, GUESTFS_PROC_COPY_FILE_TO_FILE,
                             progress_hint, optargs->bitmask,
                             (xdrproc_t) xdr_guestfs_copy_file_to_file_args, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "copy_file_to_file", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs_int_recv (g, "copy_file_to_file", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "copy_file_to_file", "-1");
    return -1;
  }

  if (guestfs_int_check_reply_header (g, &hdr, GUESTFS_PROC_COPY_FILE_TO_FILE, serial) == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "copy_file_to_file", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "copy_file_to_file", "-1");
    if (err.errno_string[0] != '\0')
      errnum = guestfs_int_string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "copy_file_to_file", err.error_message);
    else
      guestfs_int_error_errno (g, errnum, "%s: %s", "copy_file_to_file",
                               err.error_message);
    free (err.error_message);
    free (err.errno_string);
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "copy_file_to_file");
    fprintf (trace_buffer.fp, "%d", ret_v);
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  return ret_v;
}

GUESTFS_DLL_PUBLIC int
guestfs_cpio_out_argv (guestfs_h *g,
                       const char *directory,
                       const char *cpiofile,
                       const struct guestfs_cpio_out_argv *optargs)
{
  struct guestfs_cpio_out_argv optargs_null;
  if (!optargs) {
    optargs_null.bitmask = 0;
    optargs = &optargs_null;
  }

  struct guestfs_cpio_out_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs_int_call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                      "cpio_out", 8);
  if (directory == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "cpio_out", "directory");
    return -1;
  }
  if (cpiofile == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "cpio_out", "cpiofile");
    return -1;
  }
  if ((optargs->bitmask & GUESTFS_CPIO_OUT_FORMAT_BITMASK) &&
      optargs->format == NULL) {
    error (g, "%s: %s: optional parameter cannot be NULL",
           "cpio_out", "format");
    return -1;
  }

  if (optargs->bitmask & UINT64_C(0xfffffffffffffffe)) {
    error (g, "%s: unknown option in guestfs_%s_argv->bitmask (this can happen if a program is compiled against a newer version of libguestfs, then dynamically linked to an older version)",
           "cpio_out", "cpio_out");
    return -1;
  }

  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "cpio_out");
    fprintf (trace_buffer.fp, " \"%s\"", directory);
    fprintf (trace_buffer.fp, " \"%s\"", cpiofile);
    if (optargs->bitmask & GUESTFS_CPIO_OUT_FORMAT_BITMASK) {
      fprintf (trace_buffer.fp, " \"%s:%s\"", "format", optargs->format);
    }
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  if (guestfs_int_check_appliance_up (g, "cpio_out") == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "cpio_out", "-1");
    return -1;
  }

  args.directory = (char *) directory;
  if (optargs->bitmask & GUESTFS_CPIO_OUT_FORMAT_BITMASK) {
    args.format = (char *) optargs->format;
  } else {
    args.format = (char *) "";
  }
  serial = guestfs_int_send (g, GUESTFS_PROC_CPIO_OUT,
                             progress_hint, optargs->bitmask,
                             (xdrproc_t) xdr_guestfs_cpio_out_args, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "cpio_out", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs_int_recv (g, "cpio_out", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "cpio_out", "-1");
    return -1;
  }

  if (guestfs_int_check_reply_header (g, &hdr, GUESTFS_PROC_CPIO_OUT, serial) == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "cpio_out", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "cpio_out", "-1");
    if (err.errno_string[0] != '\0')
      errnum = guestfs_int_string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "cpio_out", err.error_message);
    else
      guestfs_int_error_errno (g, errnum, "%s: %s", "cpio_out",
                               err.error_message);
    free (err.error_message);
    free (err.errno_string);
    return -1;
  }

  if (guestfs_int_recv_file (g, cpiofile) == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "cpio_out", "-1");
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "cpio_out");
    fprintf (trace_buffer.fp, "%d", ret_v);
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  return ret_v;
}

GUESTFS_DLL_PUBLIC int
guestfs_download (guestfs_h *g,
                  const char *remotefilename,
                  const char *filename)
{
  struct guestfs_download_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs_int_call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                      "download", 8);
  if (remotefilename == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "download", "remotefilename");
    return -1;
  }
  if (filename == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "download", "filename");
    return -1;
  }

  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "download");
    fprintf (trace_buffer.fp, " \"%s\"", remotefilename);
    fprintf (trace_buffer.fp, " \"%s\"", filename);
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  if (guestfs_int_check_appliance_up (g, "download") == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "download", "-1");
    return -1;
  }

  args.remotefilename = (char *) remotefilename;
  serial = guestfs_int_send (g, GUESTFS_PROC_DOWNLOAD,
                             progress_hint, 0,
                             (xdrproc_t) xdr_guestfs_download_args, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "download", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs_int_recv (g, "download", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "download", "-1");
    return -1;
  }

  if (guestfs_int_check_reply_header (g, &hdr, GUESTFS_PROC_DOWNLOAD, serial) == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "download", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "download", "-1");
    if (err.errno_string[0] != '\0')
      errnum = guestfs_int_string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "download", err.error_message);
    else
      guestfs_int_error_errno (g, errnum, "%s: %s", "download",
                               err.error_message);
    free (err.error_message);
    free (err.errno_string);
    return -1;
  }

  if (guestfs_int_recv_file (g, filename) == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "download", "-1");
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "download");
    fprintf (trace_buffer.fp, "%d", ret_v);
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  return ret_v;
}

GUESTFS_DLL_PUBLIC int
guestfs_fill_pattern (guestfs_h *g,
                      const char *pattern,
                      int len,
                      const char *path)
{
  struct guestfs_fill_pattern_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs_int_call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                      "fill_pattern", 12);
  if (pattern == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "fill_pattern", "pattern");
    return -1;
  }
  if (path == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "fill_pattern", "path");
    return -1;
  }

  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "fill_pattern");
    fprintf (trace_buffer.fp, " \"%s\"", pattern);
    fprintf (trace_buffer.fp, " %d", len);
    fprintf (trace_buffer.fp, " \"%s\"", path);
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  if (guestfs_int_check_appliance_up (g, "fill_pattern") == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "fill_pattern", "-1");
    return -1;
  }

  args.pattern = (char *) pattern;
  args.len = len;
  args.path = (char *) path;
  serial = guestfs_int_send (g, GUESTFS_PROC_FILL_PATTERN,
                             progress_hint, 0,
                             (xdrproc_t) xdr_guestfs_fill_pattern_args, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "fill_pattern", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs_int_recv (g, "fill_pattern", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "fill_pattern", "-1");
    return -1;
  }

  if (guestfs_int_check_reply_header (g, &hdr, GUESTFS_PROC_FILL_PATTERN, serial) == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "fill_pattern", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "fill_pattern", "-1");
    if (err.errno_string[0] != '\0')
      errnum = guestfs_int_string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "fill_pattern", err.error_message);
    else
      guestfs_int_error_errno (g, errnum, "%s: %s", "fill_pattern",
                               err.error_message);
    free (err.error_message);
    free (err.errno_string);
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "fill_pattern");
    fprintf (trace_buffer.fp, "%d", ret_v);
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  return ret_v;
}

GUESTFS_DLL_PUBLIC int
guestfs_find0 (guestfs_h *g,
               const char *directory,
               const char *files)
{
  struct guestfs_find0_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs_int_call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                      "find0", 5);
  if (directory == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "find0", "directory");
    return -1;
  }
  if (files == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "find0", "files");
    return -1;
  }

  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "find0");
    fprintf (trace_buffer.fp, " \"%s\"", directory);
    fprintf (trace_buffer.fp, " \"%s\"", files);
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  if (guestfs_int_check_appliance_up (g, "find0") == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "find0", "-1");
    return -1;
  }

  args.directory = (char *) directory;
  serial = guestfs_int_send (g, GUESTFS_PROC_FIND0,
                             progress_hint, 0,
                             (xdrproc_t) xdr_guestfs_find0_args, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "find0", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs_int_recv (g, "find0", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "find0", "-1");
    return -1;
  }

  if (guestfs_int_check_reply_header (g, &hdr, GUESTFS_PROC_FIND0, serial) == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "find0", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "find0", "-1");
    if (err.errno_string[0] != '\0')
      errnum = guestfs_int_string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "find0", err.error_message);
    else
      guestfs_int_error_errno (g, errnum, "%s: %s", "find0",
                               err.error_message);
    free (err.error_message);
    free (err.errno_string);
    return -1;
  }

  if (guestfs_int_recv_file (g, files) == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "find0", "-1");
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "find0");
    fprintf (trace_buffer.fp, "%d", ret_v);
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  return ret_v;
}

GUESTFS_DLL_PUBLIC char **
guestfs_head_n (guestfs_h *g,
                int nrlines,
                const char *path)
{
  struct guestfs_head_n_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  struct guestfs_head_n_ret ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  char **ret_v;
  const uint64_t progress_hint = 0;

  guestfs_int_call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                      "head_n", 6);
  if (path == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "head_n", "path");
    return NULL;
  }

  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "head_n");
    fprintf (trace_buffer.fp, " %d", nrlines);
    fprintf (trace_buffer.fp, " \"%s\"", path);
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  if (guestfs_int_check_appliance_up (g, "head_n") == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "head_n", "NULL");
    return NULL;
  }

  args.nrlines = nrlines;
  args.path = (char *) path;
  serial = guestfs_int_send (g, GUESTFS_PROC_HEAD_N,
                             progress_hint, 0,
                             (xdrproc_t) xdr_guestfs_head_n_args, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "head_n", "NULL");
    return NULL;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs_int_recv (g, "head_n", &hdr, &err,
        (xdrproc_t) xdr_guestfs_head_n_ret, (char *) &ret);
  if (r == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "head_n", "NULL");
    return NULL;
  }

  if (guestfs_int_check_reply_header (g, &hdr, GUESTFS_PROC_HEAD_N, serial) == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "head_n", "NULL");
    return NULL;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "head_n", "NULL");
    if (err.errno_string[0] != '\0')
      errnum = guestfs_int_string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "head_n", err.error_message);
    else
      guestfs_int_error_errno (g, errnum, "%s: %s", "head_n",
                               err.error_message);
    free (err.error_message);
    free (err.errno_string);
    return NULL;
  }

  /* caller will free this, but we need to add a NULL entry */
  ret.lines.lines_val =
    safe_realloc (g, ret.lines.lines_val,
                  sizeof (char *) * (ret.lines.lines_len + 1));
  ret.lines.lines_val[ret.lines.lines_len] = NULL;
  ret_v = ret.lines.lines_val;
  if (trace_flag) {
    size_t i;

    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "head_n");
    fputs ("[", trace_buffer.fp);
    for (i = 0; ret_v[i]; ++i) {
      if (i > 0) fputs (", ", trace_buffer.fp);
      fputs ("\"", trace_buffer.fp);
      fputs (ret_v[i], trace_buffer.fp);
      fputs ("\"", trace_buffer.fp);
    }
    fputs ("]", trace_buffer.fp);
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  return ret_v;
}

GUESTFS_DLL_PUBLIC int
guestfs_hivex_commit (guestfs_h *g,
                      const char *filename)
{
  struct guestfs_hivex_commit_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs_int_call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                      "hivex_commit", 12);
  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "hivex_commit");
    if (filename)
      fprintf (trace_buffer.fp, " \"%s\"", filename);
    else
      fprintf (trace_buffer.fp, " null");
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  if (guestfs_int_check_appliance_up (g, "hivex_commit") == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "hivex_commit", "-1");
    return -1;
  }

  args.filename = filename ? (char **) &filename : NULL;
  serial = guestfs_int_send (g, GUESTFS_PROC_HIVEX_COMMIT,
                             progress_hint, 0,
                             (xdrproc_t) xdr_guestfs_hivex_commit_args, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "hivex_commit", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs_int_recv (g, "hivex_commit", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "hivex_commit", "-1");
    return -1;
  }

  if (guestfs_int_check_reply_header (g, &hdr, GUESTFS_PROC_HIVEX_COMMIT, serial) == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "hivex_commit", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "hivex_commit", "-1");
    if (err.errno_string[0] != '\0')
      errnum = guestfs_int_string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "hivex_commit", err.error_message);
    else
      guestfs_int_error_errno (g, errnum, "%s: %s", "hivex_commit",
                               err.error_message);
    free (err.error_message);
    free (err.errno_string);
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "hivex_commit");
    fprintf (trace_buffer.fp, "%d", ret_v);
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  return ret_v;
}

GUESTFS_DLL_PUBLIC int
guestfs_hivex_node_delete_child (guestfs_h *g,
                                 int64_t nodeh)
{
  struct guestfs_hivex_node_delete_child_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs_int_call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                      "hivex_node_delete_child", 23);
  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "hivex_node_delete_child");
    fprintf (trace_buffer.fp, " %" PRIi64, nodeh);
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  if (guestfs_int_check_appliance_up (g, "hivex_node_delete_child") == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "hivex_node_delete_child", "-1");
    return -1;
  }

  args.nodeh = nodeh;
  serial = guestfs_int_send (g, GUESTFS_PROC_HIVEX_NODE_DELETE_CHILD,
                             progress_hint, 0,
                             (xdrproc_t) xdr_guestfs_hivex_node_delete_child_args, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "hivex_node_delete_child", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs_int_recv (g, "hivex_node_delete_child", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "hivex_node_delete_child", "-1");
    return -1;
  }

  if (guestfs_int_check_reply_header (g, &hdr, GUESTFS_PROC_HIVEX_NODE_DELETE_CHILD, serial) == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "hivex_node_delete_child", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "hivex_node_delete_child", "-1");
    if (err.errno_string[0] != '\0')
      errnum = guestfs_int_string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "hivex_node_delete_child", err.error_message);
    else
      guestfs_int_error_errno (g, errnum, "%s: %s", "hivex_node_delete_child",
                               err.error_message);
    free (err.error_message);
    free (err.errno_string);
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "hivex_node_delete_child");
    fprintf (trace_buffer.fp, "%d", ret_v);
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  return ret_v;
}

GUESTFS_DLL_PUBLIC char *
guestfs_initrd_cat (guestfs_h *g,
                    const char *initrdpath,
                    const char *filename,
                    size_t *size_r)
{
  struct guestfs_initrd_cat_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  struct guestfs_initrd_cat_ret ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  char *ret_v;
  const uint64_t progress_hint = 0;

  guestfs_int_call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                      "initrd_cat", 10);
  if (initrdpath == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "initrd_cat", "initrdpath");
    return NULL;
  }
  if (filename == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "initrd_cat", "filename");
    return NULL;
  }

  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "initrd_cat");
    fprintf (trace_buffer.fp, " \"%s\"", initrdpath);
    fprintf (trace_buffer.fp, " \"%s\"", filename);
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  if (guestfs_int_check_appliance_up (g, "initrd_cat") == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "initrd_cat", "NULL");
    return NULL;
  }

  args.initrdpath = (char *) initrdpath;
  args.filename = (char *) filename;
  serial = guestfs_int_send (g, GUESTFS_PROC_INITRD_CAT,
                             progress_hint, 0,
                             (xdrproc_t) xdr_guestfs_initrd_cat_args, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "initrd_cat", "NULL");
    return NULL;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs_int_recv (g, "initrd_cat", &hdr, &err,
        (xdrproc_t) xdr_guestfs_initrd_cat_ret, (char *) &ret);
  if (r == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "initrd_cat", "NULL");
    return NULL;
  }

  if (guestfs_int_check_reply_header (g, &hdr, GUESTFS_PROC_INITRD_CAT, serial) == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "initrd_cat", "NULL");
    return NULL;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "initrd_cat", "NULL");
    if (err.errno_string[0] != '\0')
      errnum = guestfs_int_string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "initrd_cat", err.error_message);
    else
      guestfs_int_error_errno (g, errnum, "%s: %s", "initrd_cat",
                               err.error_message);
    free (err.error_message);
    free (err.errno_string);
    return NULL;
  }

  /* RBufferOut is tricky: If the buffer is zero-length, then
   * _val might be NULL here.  To make the API saner for
   * callers, we turn this case into a unique pointer (using
   * malloc(1)).
   */
  if (ret.content.content_len > 0) {
    *size_r = ret.content.content_len;
    ret_v = ret.content.content_val; /* caller will free */
  } else {
    free (ret.content.content_val);
    char *p = safe_malloc (g, 1);
    *size_r = ret.content.content_len;
    ret_v = p;
  }
  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "initrd_cat");
    guestfs_int_print_BufferOut (trace_buffer.fp, ret_v, *size_r);
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  return ret_v;
}

GUESTFS_DLL_PUBLIC int
guestfs_inotify_close (guestfs_h *g)
{
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs_int_call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                      "inotify_close", 13);
  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "inotify_close");
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  if (guestfs_int_check_appliance_up (g, "inotify_close") == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "inotify_close", "-1");
    return -1;
  }

  serial = guestfs_int_send (g, GUESTFS_PROC_INOTIFY_CLOSE, progress_hint, 0,
                             NULL, NULL);
  if (serial == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "inotify_close", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs_int_recv (g, "inotify_close", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "inotify_close", "-1");
    return -1;
  }

  if (guestfs_int_check_reply_header (g, &hdr, GUESTFS_PROC_INOTIFY_CLOSE, serial) == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "inotify_close", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "inotify_close", "-1");
    if (err.errno_string[0] != '\0')
      errnum = guestfs_int_string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "inotify_close", err.error_message);
    else
      guestfs_int_error_errno (g, errnum, "%s: %s", "inotify_close",
                               err.error_message);
    free (err.error_message);
    free (err.errno_string);
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "inotify_close");
    fprintf (trace_buffer.fp, "%d", ret_v);
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  return ret_v;
}

GUESTFS_DLL_PUBLIC int
guestfs_internal_upload (guestfs_h *g,
                         const char *filename,
                         const char *tmpname,
                         int mode)
{
  struct guestfs_internal_upload_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int ret_v;
  uint64_t progress_hint = 0;
  struct stat progress_stat;

  guestfs_int_call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                      "internal_upload", 15);
  if (filename == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "internal_upload", "filename");
    return -1;
  }
  if (tmpname == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "internal_upload", "tmpname");
    return -1;
  }

  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "internal_upload");
    fprintf (trace_buffer.fp, " \"%s\"", filename);
    fprintf (trace_buffer.fp, " \"%s\"", tmpname);
    fprintf (trace_buffer.fp, " %d", mode);
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  if (stat (filename, &progress_stat) == 0 &&
      S_ISREG (progress_stat.st_mode))
    progress_hint += progress_stat.st_size;

  if (guestfs_int_check_appliance_up (g, "internal_upload") == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "internal_upload", "-1");
    return -1;
  }

  args.tmpname = (char *) tmpname;
  args.mode = mode;
  serial = guestfs_int_send (g, GUESTFS_PROC_INTERNAL_UPLOAD,
                             progress_hint, 0,
                             (xdrproc_t) xdr_guestfs_internal_upload_args, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "internal_upload", "-1");
    return -1;
  }

  r = guestfs_int_send_file (g, filename);
  if (r == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "internal_upload", "-1");
    /* daemon will send an error reply which we discard */
    guestfs_int_recv_discard (g, "internal_upload");
    return -1;
  }
  if (r == -2) /* daemon cancelled */
    goto read_reply;

 read_reply:
  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs_int_recv (g, "internal_upload", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "internal_upload", "-1");
    return -1;
  }

  if (guestfs_int_check_reply_header (g, &hdr, GUESTFS_PROC_INTERNAL_UPLOAD, serial) == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "internal_upload", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "internal_upload", "-1");
    if (err.errno_string[0] != '\0')
      errnum = guestfs_int_string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "internal_upload", err.error_message);
    else
      guestfs_int_error_errno (g, errnum, "%s: %s", "internal_upload",
                               err.error_message);
    free (err.error_message);
    free (err.errno_string);
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "internal_upload");
    fprintf (trace_buffer.fp, "%d", ret_v);
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  return ret_v;
}

GUESTFS_DLL_PUBLIC int
guestfs_internal_write (guestfs_h *g,
                        const char *path,
                        const char *content,
                        size_t content_size)
{
  struct guestfs_internal_write_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs_int_call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                      "internal_write", 14);
  if (path == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "internal_write", "path");
    return -1;
  }
  if (content == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "internal_write", "content");
    return -1;
  }

  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "internal_write");
    fprintf (trace_buffer.fp, " \"%s\"", path);
    fputc (' ', trace_buffer.fp);
    guestfs_int_print_BufferIn (trace_buffer.fp, content, content_size);
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  if (guestfs_int_check_appliance_up (g, "internal_write") == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "internal_write", "-1");
    return -1;
  }

  args.path = (char *) path;
  /* Just catch grossly large sizes. XDR encoding will make this precise. */
  if (content_size >= GUESTFS_MESSAGE_MAX) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "internal_write", "-1");
    error (g, "%s: size of input buffer too large", "internal_write");
    return -1;
  }
  args.content.content_val = (char *) content;
  args.content.content_len = content_size;
  serial = guestfs_int_send (g, GUESTFS_PROC_INTERNAL_WRITE,
                             progress_hint, 0,
                             (xdrproc_t) xdr_guestfs_internal_write_args, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "internal_write", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs_int_recv (g, "internal_write", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "internal_write", "-1");
    return -1;
  }

  if (guestfs_int_check_reply_header (g, &hdr, GUESTFS_PROC_INTERNAL_WRITE, serial) == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "internal_write", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "internal_write", "-1");
    if (err.errno_string[0] != '\0')
      errnum = guestfs_int_string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "internal_write", err.error_message);
    else
      guestfs_int_error_errno (g, errnum, "%s: %s", "internal_write",
                               err.error_message);
    free (err.error_message);
    free (err.errno_string);
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "internal_write");
    fprintf (trace_buffer.fp, "%d", ret_v);
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  return ret_v;
}

GUESTFS_DLL_PUBLIC int
guestfs_internal_write_append (guestfs_h *g,
                               const char *path,
                               const char *content,
                               size_t content_size)
{
  struct guestfs_internal_write_append_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs_int_call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                      "internal_write_append", 21);
  if (path == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "internal_write_append", "path");
    return -1;
  }
  if (content == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "internal_write_append", "content");
    return -1;
  }

  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "internal_write_append");
    fprintf (trace_buffer.fp, " \"%s\"", path);
    fputc (' ', trace_buffer.fp);
    guestfs_int_print_BufferIn (trace_buffer.fp, content, content_size);
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  if (guestfs_int_check_appliance_up (g, "internal_write_append") == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "internal_write_append", "-1");
    return -1;
  }

  args.path = (char *) path;
  /* Just catch grossly large sizes. XDR encoding will make this precise. */
  if (content_size >= GUESTFS_MESSAGE_MAX) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "internal_write_append", "-1");
    error (g, "%s: size of input buffer too large", "internal_write_append");
    return -1;
  }
  args.content.content_val = (char *) content;
  args.content.content_len = content_size;
  serial = guestfs_int_send (g, GUESTFS_PROC_INTERNAL_WRITE_APPEND,
                             progress_hint, 0,
                             (xdrproc_t) xdr_guestfs_internal_write_append_args, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "internal_write_append", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs_int_recv (g, "internal_write_append", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "internal_write_append", "-1");
    return -1;
  }

  if (guestfs_int_check_reply_header (g, &hdr, GUESTFS_PROC_INTERNAL_WRITE_APPEND, serial) == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "internal_write_append", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "internal_write_append", "-1");
    if (err.errno_string[0] != '\0')
      errnum = guestfs_int_string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "internal_write_append", err.error_message);
    else
      guestfs_int_error_errno (g, errnum, "%s: %s", "internal_write_append",
                               err.error_message);
    free (err.error_message);
    free (err.errno_string);
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "internal_write_append");
    fprintf (trace_buffer.fp, "%d", ret_v);
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  return ret_v;
}

GUESTFS_DLL_PUBLIC int
guestfs_is_blockdev_opts_argv (guestfs_h *g,
                               const char *path,
                               const struct guestfs_is_blockdev_opts_argv *optargs)
{
  struct guestfs_is_blockdev_opts_argv optargs_null;
  if (!optargs) {
    optargs_null.bitmask = 0;
    optargs = &optargs_null;
  }

  struct guestfs_is_blockdev_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  struct guestfs_is_blockdev_ret ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs_int_call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                      "is_blockdev", 11);
  if (path == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "is_blockdev_opts", "path");
    return -1;
  }

  if (optargs->bitmask & UINT64_C(0xfffffffffffffffe)) {
    error (g, "%s: unknown option in guestfs_%s_argv->bitmask (this can happen if a program is compiled against a newer version of libguestfs, then dynamically linked to an older version)",
           "is_blockdev_opts", "is_blockdev_opts");
    return -1;
  }

  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "is_blockdev");
    fprintf (trace_buffer.fp, " \"%s\"", path);
    if (optargs->bitmask & GUESTFS_IS_BLOCKDEV_OPTS_FOLLOWSYMLINKS_BITMASK) {
      fprintf (trace_buffer.fp, " \"%s:%s\"", "followsymlinks", optargs->followsymlinks ? "true" : "false");
    }
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  if (guestfs_int_check_appliance_up (g, "is_blockdev") == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "is_blockdev", "-1");
    return -1;
  }

  args.path = (char *) path;
  if (optargs->bitmask & GUESTFS_IS_BLOCKDEV_OPTS_FOLLOWSYMLINKS_BITMASK) {
    args.followsymlinks = optargs->followsymlinks;
  } else {
    args.followsymlinks = 0;
  }
  serial = guestfs_int_send (g, GUESTFS_PROC_IS_BLOCKDEV,
                             progress_hint, optargs->bitmask,
                             (xdrproc_t) xdr_guestfs_is_blockdev_args, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "is_blockdev", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs_int_recv (g, "is_blockdev", &hdr, &err,
        (xdrproc_t) xdr_guestfs_is_blockdev_ret, (char *) &ret);
  if (r == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "is_blockdev", "-1");
    return -1;
  }

  if (guestfs_int_check_reply_header (g, &hdr, GUESTFS_PROC_IS_BLOCKDEV, serial) == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "is_blockdev", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "is_blockdev", "-1");
    if (err.errno_string[0] != '\0')
      errnum = guestfs_int_string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "is_blockdev", err.error_message);
    else
      guestfs_int_error_errno (g, errnum, "%s: %s", "is_blockdev",
                               err.error_message);
    free (err.error_message);
    free (err.errno_string);
    return -1;
  }

  ret_v = ret.flag;
  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "is_blockdev");
    fprintf (trace_buffer.fp, "%d", ret_v);
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  return ret_v;
}

GUESTFS_DLL_PUBLIC int
guestfs_is_fifo_opts_argv (guestfs_h *g,
                           const char *path,
                           const struct guestfs_is_fifo_opts_argv *optargs)
{
  struct guestfs_is_fifo_opts_argv optargs_null;
  if (!optargs) {
    optargs_null.bitmask = 0;
    optargs = &optargs_null;
  }

  struct guestfs_is_fifo_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  struct guestfs_is_fifo_ret ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs_int_call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                      "is_fifo", 7);
  if (path == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "is_fifo_opts", "path");
    return -1;
  }

  if (optargs->bitmask & UINT64_C(0xfffffffffffffffe)) {
    error (g, "%s: unknown option in guestfs_%s_argv->bitmask (this can happen if a program is compiled against a newer version of libguestfs, then dynamically linked to an older version)",
           "is_fifo_opts", "is_fifo_opts");
    return -1;
  }

  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "is_fifo");
    fprintf (trace_buffer.fp, " \"%s\"", path);
    if (optargs->bitmask & GUESTFS_IS_FIFO_OPTS_FOLLOWSYMLINKS_BITMASK) {
      fprintf (trace_buffer.fp, " \"%s:%s\"", "followsymlinks", optargs->followsymlinks ? "true" : "false");
    }
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  if (guestfs_int_check_appliance_up (g, "is_fifo") == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "is_fifo", "-1");
    return -1;
  }

  args.path = (char *) path;
  if (optargs->bitmask & GUESTFS_IS_FIFO_OPTS_FOLLOWSYMLINKS_BITMASK) {
    args.followsymlinks = optargs->followsymlinks;
  } else {
    args.followsymlinks = 0;
  }
  serial = guestfs_int_send (g, GUESTFS_PROC_IS_FIFO,
                             progress_hint, optargs->bitmask,
                             (xdrproc_t) xdr_guestfs_is_fifo_args, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "is_fifo", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs_int_recv (g, "is_fifo", &hdr, &err,
        (xdrproc_t) xdr_guestfs_is_fifo_ret, (char *) &ret);
  if (r == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "is_fifo", "-1");
    return -1;
  }

  if (guestfs_int_check_reply_header (g, &hdr, GUESTFS_PROC_IS_FIFO, serial) == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "is_fifo", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "is_fifo", "-1");
    if (err.errno_string[0] != '\0')
      errnum = guestfs_int_string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "is_fifo", err.error_message);
    else
      guestfs_int_error_errno (g, errnum, "%s: %s", "is_fifo",
                               err.error_message);
    free (err.error_message);
    free (err.errno_string);
    return -1;
  }

  ret_v = ret.flag;
  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "is_fifo");
    fprintf (trace_buffer.fp, "%d", ret_v);
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  return ret_v;
}

GUESTFS_DLL_PUBLIC struct guestfs_isoinfo *
guestfs_isoinfo_device (guestfs_h *g,
                        const char *device)
{
  struct guestfs_isoinfo_device_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  struct guestfs_isoinfo_device_ret ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  struct guestfs_isoinfo *ret_v;
  const uint64_t progress_hint = 0;

  guestfs_int_call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                      "isoinfo_device", 14);
  if (device == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "isoinfo_device", "device");
    return NULL;
  }

  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "isoinfo_device");
    fprintf (trace_buffer.fp, " \"%s\"", device);
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  if (guestfs_int_check_appliance_up (g, "isoinfo_device") == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "isoinfo_device", "NULL");
    return NULL;
  }

  args.device = (char *) device;
  serial = guestfs_int_send (g, GUESTFS_PROC_ISOINFO_DEVICE,
                             progress_hint, 0,
                             (xdrproc_t) xdr_guestfs_isoinfo_device_args, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "isoinfo_device", "NULL");
    return NULL;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs_int_recv (g, "isoinfo_device", &hdr, &err,
        (xdrproc_t) xdr_guestfs_isoinfo_device_ret, (char *) &ret);
  if (r == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "isoinfo_device", "NULL");
    return NULL;
  }

  if (guestfs_int_check_reply_header (g, &hdr, GUESTFS_PROC_ISOINFO_DEVICE, serial) == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "isoinfo_device", "NULL");
    return NULL;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "isoinfo_device", "NULL");
    if (err.errno_string[0] != '\0')
      errnum = guestfs_int_string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "isoinfo_device", err.error_message);
    else
      guestfs_int_error_errno (g, errnum, "%s: %s", "isoinfo_device",
                               err.error_message);
    free (err.error_message);
    free (err.errno_string);
    return NULL;
  }

  /* caller will free this */
  ret_v = safe_memdup (g, &ret.isodata, sizeof (ret.isodata));
  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "isoinfo_device");
    fprintf (trace_buffer.fp, "<struct guestfs_isoinfo = ");
    guestfs_int_print_isoinfo_indent (ret_v, trace_buffer.fp, ", ", "");
    fprintf (trace_buffer.fp, ">");
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  return ret_v;
}

GUESTFS_DLL_PUBLIC int
guestfs_journal_next (guestfs_h *g)
{
  guestfs_message_header hdr;
  guestfs_message_error err;
  struct guestfs_journal_next_ret ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs_int_call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                      "journal_next", 12);
  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "journal_next");
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  if (guestfs_int_check_appliance_up (g, "journal_next") == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "journal_next", "-1");
    return -1;
  }

  serial = guestfs_int_send (g, GUESTFS_PROC_JOURNAL_NEXT, progress_hint, 0,
                             NULL, NULL);
  if (serial == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "journal_next", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs_int_recv (g, "journal_next", &hdr, &err,
        (xdrproc_t) xdr_guestfs_journal_next_ret, (char *) &ret);
  if (r == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "journal_next", "-1");
    return -1;
  }

  if (guestfs_int_check_reply_header (g, &hdr, GUESTFS_PROC_JOURNAL_NEXT, serial) == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "journal_next", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "journal_next", "-1");
    if (err.errno_string[0] != '\0')
      errnum = guestfs_int_string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "journal_next", err.error_message);
    else
      guestfs_int_error_errno (g, errnum, "%s: %s", "journal_next",
                               err.error_message);
    free (err.error_message);
    free (err.errno_string);
    return -1;
  }

  ret_v = ret.more;
  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "journal_next");
    fprintf (trace_buffer.fp, "%d", ret_v);
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  return ret_v;
}

GUESTFS_DLL_PUBLIC int64_t
guestfs_journal_skip (guestfs_h *g,
                      int64_t skip)
{
  struct guestfs_journal_skip_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  struct guestfs_journal_skip_ret ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int64_t ret_v;
  const uint64_t progress_hint = 0;

  guestfs_int_call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                      "journal_skip", 12);
  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "journal_skip");
    fprintf (trace_buffer.fp, " %" PRIi64, skip);
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  if (guestfs_int_check_appliance_up (g, "journal_skip") == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "journal_skip", "-1");
    return -1;
  }

  args.skip = skip;
  serial = guestfs_int_send (g, GUESTFS_PROC_JOURNAL_SKIP,
                             progress_hint, 0,
                             (xdrproc_t) xdr_guestfs_journal_skip_args, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "journal_skip", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs_int_recv (g, "journal_skip", &hdr, &err,
        (xdrproc_t) xdr_guestfs_journal_skip_ret, (char *) &ret);
  if (r == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "journal_skip", "-1");
    return -1;
  }

  if (guestfs_int_check_reply_header (g, &hdr, GUESTFS_PROC_JOURNAL_SKIP, serial) == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "journal_skip", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "journal_skip", "-1");
    if (err.errno_string[0] != '\0')
      errnum = guestfs_int_string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "journal_skip", err.error_message);
    else
      guestfs_int_error_errno (g, errnum, "%s: %s", "journal_skip",
                               err.error_message);
    free (err.error_message);
    free (err.errno_string);
    return -1;
  }

  ret_v = ret.rskip;
  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "journal_skip");
    fprintf (trace_buffer.fp, "%" PRIi64, ret_v);
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  return ret_v;
}

GUESTFS_DLL_PUBLIC char **
guestfs_ldmtool_volume_partitions (guestfs_h *g,
                                   const char *diskgroup,
                                   const char *volume)
{
  struct guestfs_ldmtool_volume_partitions_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  struct guestfs_ldmtool_volume_partitions_ret ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  char **ret_v;
  const uint64_t progress_hint = 0;

  guestfs_int_call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                      "ldmtool_volume_partitions", 25);
  if (diskgroup == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "ldmtool_volume_partitions", "diskgroup");
    return NULL;
  }
  if (volume == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "ldmtool_volume_partitions", "volume");
    return NULL;
  }

  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "ldmtool_volume_partitions");
    fprintf (trace_buffer.fp, " \"%s\"", diskgroup);
    fprintf (trace_buffer.fp, " \"%s\"", volume);
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  if (guestfs_int_check_appliance_up (g, "ldmtool_volume_partitions") == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "ldmtool_volume_partitions", "NULL");
    return NULL;
  }

  args.diskgroup = (char *) diskgroup;
  args.volume = (char *) volume;
  serial = guestfs_int_send (g, GUESTFS_PROC_LDMTOOL_VOLUME_PARTITIONS,
                             progress_hint, 0,
                             (xdrproc_t) xdr_guestfs_ldmtool_volume_partitions_args, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "ldmtool_volume_partitions", "NULL");
    return NULL;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs_int_recv (g, "ldmtool_volume_partitions", &hdr, &err,
        (xdrproc_t) xdr_guestfs_ldmtool_volume_partitions_ret, (char *) &ret);
  if (r == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "ldmtool_volume_partitions", "NULL");
    return NULL;
  }

  if (guestfs_int_check_reply_header (g, &hdr, GUESTFS_PROC_LDMTOOL_VOLUME_PARTITIONS, serial) == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "ldmtool_volume_partitions", "NULL");
    return NULL;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "ldmtool_volume_partitions", "NULL");
    if (err.errno_string[0] != '\0')
      errnum = guestfs_int_string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "ldmtool_volume_partitions", err.error_message);
    else
      guestfs_int_error_errno (g, errnum, "%s: %s", "ldmtool_volume_partitions",
                               err.error_message);
    free (err.error_message);
    free (err.errno_string);
    return NULL;
  }

  /* caller will free this, but we need to add a NULL entry */
  ret.partitions.partitions_val =
    safe_realloc (g, ret.partitions.partitions_val,
                  sizeof (char *) * (ret.partitions.partitions_len + 1));
  ret.partitions.partitions_val[ret.partitions.partitions_len] = NULL;
  ret_v = ret.partitions.partitions_val;
  if (trace_flag) {
    size_t i;

    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "ldmtool_volume_partitions");
    fputs ("[", trace_buffer.fp);
    for (i = 0; ret_v[i]; ++i) {
      if (i > 0) fputs (", ", trace_buffer.fp);
      fputs ("\"", trace_buffer.fp);
      fputs (ret_v[i], trace_buffer.fp);
      fputs ("\"", trace_buffer.fp);
    }
    fputs ("]", trace_buffer.fp);
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  return ret_v;
}

GUESTFS_DLL_PUBLIC char **
guestfs_list_disk_labels (guestfs_h *g)
{
  guestfs_message_header hdr;
  guestfs_message_error err;
  struct guestfs_list_disk_labels_ret ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  char **ret_v;
  const uint64_t progress_hint = 0;

  guestfs_int_call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                      "list_disk_labels", 16);
  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "list_disk_labels");
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  if (guestfs_int_check_appliance_up (g, "list_disk_labels") == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "list_disk_labels", "NULL");
    return NULL;
  }

  serial = guestfs_int_send (g, GUESTFS_PROC_LIST_DISK_LABELS, progress_hint, 0,
                             NULL, NULL);
  if (serial == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "list_disk_labels", "NULL");
    return NULL;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs_int_recv (g, "list_disk_labels", &hdr, &err,
        (xdrproc_t) xdr_guestfs_list_disk_labels_ret, (char *) &ret);
  if (r == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "list_disk_labels", "NULL");
    return NULL;
  }

  if (guestfs_int_check_reply_header (g, &hdr, GUESTFS_PROC_LIST_DISK_LABELS, serial) == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "list_disk_labels", "NULL");
    return NULL;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "list_disk_labels", "NULL");
    if (err.errno_string[0] != '\0')
      errnum = guestfs_int_string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "list_disk_labels", err.error_message);
    else
      guestfs_int_error_errno (g, errnum, "%s: %s", "list_disk_labels",
                               err.error_message);
    free (err.error_message);
    free (err.errno_string);
    return NULL;
  }

  /* caller will free this, but we need to add a NULL entry */
  ret.labels.labels_val =
    safe_realloc (g, ret.labels.labels_val,
                  sizeof (char *) * (ret.labels.labels_len + 1));
  ret.labels.labels_val[ret.labels.labels_len] = NULL;
  ret_v = ret.labels.labels_val;
  if (trace_flag) {
    size_t i;

    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "list_disk_labels");
    fputs ("[", trace_buffer.fp);
    for (i = 0; ret_v[i]; ++i) {
      if (i > 0) fputs (", ", trace_buffer.fp);
      fputs ("\"", trace_buffer.fp);
      fputs (ret_v[i], trace_buffer.fp);
      fputs ("\"", trace_buffer.fp);
    }
    fputs ("]", trace_buffer.fp);
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  return ret_v;
}

GUESTFS_DLL_PUBLIC char **
guestfs_list_md_devices (guestfs_h *g)
{
  guestfs_message_header hdr;
  guestfs_message_error err;
  struct guestfs_list_md_devices_ret ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  char **ret_v;
  const uint64_t progress_hint = 0;

  guestfs_int_call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                      "list_md_devices", 15);
  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "list_md_devices");
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  if (guestfs_int_check_appliance_up (g, "list_md_devices") == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "list_md_devices", "NULL");
    return NULL;
  }

  serial = guestfs_int_send (g, GUESTFS_PROC_LIST_MD_DEVICES, progress_hint, 0,
                             NULL, NULL);
  if (serial == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "list_md_devices", "NULL");
    return NULL;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs_int_recv (g, "list_md_devices", &hdr, &err,
        (xdrproc_t) xdr_guestfs_list_md_devices_ret, (char *) &ret);
  if (r == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "list_md_devices", "NULL");
    return NULL;
  }

  if (guestfs_int_check_reply_header (g, &hdr, GUESTFS_PROC_LIST_MD_DEVICES, serial) == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "list_md_devices", "NULL");
    return NULL;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "list_md_devices", "NULL");
    if (err.errno_string[0] != '\0')
      errnum = guestfs_int_string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "list_md_devices", err.error_message);
    else
      guestfs_int_error_errno (g, errnum, "%s: %s", "list_md_devices",
                               err.error_message);
    free (err.error_message);
    free (err.errno_string);
    return NULL;
  }

  /* caller will free this, but we need to add a NULL entry */
  ret.devices.devices_val =
    safe_realloc (g, ret.devices.devices_val,
                  sizeof (char *) * (ret.devices.devices_len + 1));
  ret.devices.devices_val[ret.devices.devices_len] = NULL;
  ret_v = ret.devices.devices_val;
  if (trace_flag) {
    size_t i;

    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "list_md_devices");
    fputs ("[", trace_buffer.fp);
    for (i = 0; ret_v[i]; ++i) {
      if (i > 0) fputs (", ", trace_buffer.fp);
      fputs ("\"", trace_buffer.fp);
      fputs (ret_v[i], trace_buffer.fp);
      fputs ("\"", trace_buffer.fp);
    }
    fputs ("]", trace_buffer.fp);
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  return ret_v;
}

GUESTFS_DLL_PUBLIC int
guestfs_ln (guestfs_h *g,
            const char *target,
            const char *linkname)
{
  struct guestfs_ln_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs_int_call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                      "ln", 2);
  if (target == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "ln", "target");
    return -1;
  }
  if (linkname == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "ln", "linkname");
    return -1;
  }

  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "ln");
    fprintf (trace_buffer.fp, " \"%s\"", target);
    fprintf (trace_buffer.fp, " \"%s\"", linkname);
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  if (guestfs_int_check_appliance_up (g, "ln") == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "ln", "-1");
    return -1;
  }

  args.target = (char *) target;
  args.linkname = (char *) linkname;
  serial = guestfs_int_send (g, GUESTFS_PROC_LN,
                             progress_hint, 0,
                             (xdrproc_t) xdr_guestfs_ln_args, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "ln", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs_int_recv (g, "ln", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "ln", "-1");
    return -1;
  }

  if (guestfs_int_check_reply_header (g, &hdr, GUESTFS_PROC_LN, serial) == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "ln", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "ln", "-1");
    if (err.errno_string[0] != '\0')
      errnum = guestfs_int_string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "ln", err.error_message);
    else
      guestfs_int_error_errno (g, errnum, "%s: %s", "ln",
                               err.error_message);
    free (err.error_message);
    free (err.errno_string);
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "ln");
    fprintf (trace_buffer.fp, "%d", ret_v);
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  return ret_v;
}

GUESTFS_DLL_PUBLIC int
guestfs_ln_sf (guestfs_h *g,
               const char *target,
               const char *linkname)
{
  struct guestfs_ln_sf_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs_int_call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                      "ln_sf", 5);
  if (target == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "ln_sf", "target");
    return -1;
  }
  if (linkname == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "ln_sf", "linkname");
    return -1;
  }

  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "ln_sf");
    fprintf (trace_buffer.fp, " \"%s\"", target);
    fprintf (trace_buffer.fp, " \"%s\"", linkname);
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  if (guestfs_int_check_appliance_up (g, "ln_sf") == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "ln_sf", "-1");
    return -1;
  }

  args.target = (char *) target;
  args.linkname = (char *) linkname;
  serial = guestfs_int_send (g, GUESTFS_PROC_LN_SF,
                             progress_hint, 0,
                             (xdrproc_t) xdr_guestfs_ln_sf_args, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "ln_sf", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs_int_recv (g, "ln_sf", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "ln_sf", "-1");
    return -1;
  }

  if (guestfs_int_check_reply_header (g, &hdr, GUESTFS_PROC_LN_SF, serial) == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "ln_sf", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "ln_sf", "-1");
    if (err.errno_string[0] != '\0')
      errnum = guestfs_int_string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "ln_sf", err.error_message);
    else
      guestfs_int_error_errno (g, errnum, "%s: %s", "ln_sf",
                               err.error_message);
    free (err.error_message);
    free (err.errno_string);
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "ln_sf");
    fprintf (trace_buffer.fp, "%d", ret_v);
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  return ret_v;
}

GUESTFS_DLL_PUBLIC int
guestfs_luks_add_key (guestfs_h *g,
                      const char *device,
                      const char *key,
                      const char *newkey,
                      int keyslot)
{
  struct guestfs_luks_add_key_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs_int_call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                      "luks_add_key", 12);
  if (device == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "luks_add_key", "device");
    return -1;
  }
  if (key == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "luks_add_key", "key");
    return -1;
  }
  if (newkey == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "luks_add_key", "newkey");
    return -1;
  }

  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "luks_add_key");
    fprintf (trace_buffer.fp, " \"%s\"", device);
    fprintf (trace_buffer.fp, " \"***\"");
    fprintf (trace_buffer.fp, " \"***\"");
    fprintf (trace_buffer.fp, " %d", keyslot);
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  if (guestfs_int_check_appliance_up (g, "luks_add_key") == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "luks_add_key", "-1");
    return -1;
  }

  args.device = (char *) device;
  args.key = (char *) key;
  args.newkey = (char *) newkey;
  args.keyslot = keyslot;
  serial = guestfs_int_send (g, GUESTFS_PROC_LUKS_ADD_KEY,
                             progress_hint, 0,
                             (xdrproc_t) xdr_guestfs_luks_add_key_args, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "luks_add_key", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs_int_recv (g, "luks_add_key", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "luks_add_key", "-1");
    return -1;
  }

  if (guestfs_int_check_reply_header (g, &hdr, GUESTFS_PROC_LUKS_ADD_KEY, serial) == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "luks_add_key", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "luks_add_key", "-1");
    if (err.errno_string[0] != '\0')
      errnum = guestfs_int_string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "luks_add_key", err.error_message);
    else
      guestfs_int_error_errno (g, errnum, "%s: %s", "luks_add_key",
                               err.error_message);
    free (err.error_message);
    free (err.errno_string);
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "luks_add_key");
    fprintf (trace_buffer.fp, "%d", ret_v);
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  return ret_v;
}

GUESTFS_DLL_PUBLIC int
guestfs_lvcreate (guestfs_h *g,
                  const char *logvol,
                  const char *volgroup,
                  int mbytes)
{
  struct guestfs_lvcreate_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs_int_call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                      "lvcreate", 8);
  if (logvol == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "lvcreate", "logvol");
    return -1;
  }
  if (volgroup == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "lvcreate", "volgroup");
    return -1;
  }

  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "lvcreate");
    fprintf (trace_buffer.fp, " \"%s\"", logvol);
    fprintf (trace_buffer.fp, " \"%s\"", volgroup);
    fprintf (trace_buffer.fp, " %d", mbytes);
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  if (guestfs_int_check_appliance_up (g, "lvcreate") == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "lvcreate", "-1");
    return -1;
  }

  args.logvol = (char *) logvol;
  args.volgroup = (char *) volgroup;
  args.mbytes = mbytes;
  serial = guestfs_int_send (g, GUESTFS_PROC_LVCREATE,
                             progress_hint, 0,
                             (xdrproc_t) xdr_guestfs_lvcreate_args, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "lvcreate", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs_int_recv (g, "lvcreate", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "lvcreate", "-1");
    return -1;
  }

  if (guestfs_int_check_reply_header (g, &hdr, GUESTFS_PROC_LVCREATE, serial) == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "lvcreate", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "lvcreate", "-1");
    if (err.errno_string[0] != '\0')
      errnum = guestfs_int_string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "lvcreate", err.error_message);
    else
      guestfs_int_error_errno (g, errnum, "%s: %s", "lvcreate",
                               err.error_message);
    free (err.error_message);
    free (err.errno_string);
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "lvcreate");
    fprintf (trace_buffer.fp, "%d", ret_v);
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  return ret_v;
}

GUESTFS_DLL_PUBLIC int
guestfs_lvcreate_free (guestfs_h *g,
                       const char *logvol,
                       const char *volgroup,
                       int percent)
{
  struct guestfs_lvcreate_free_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs_int_call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                      "lvcreate_free", 13);
  if (logvol == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "lvcreate_free", "logvol");
    return -1;
  }
  if (volgroup == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "lvcreate_free", "volgroup");
    return -1;
  }

  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "lvcreate_free");
    fprintf (trace_buffer.fp, " \"%s\"", logvol);
    fprintf (trace_buffer.fp, " \"%s\"", volgroup);
    fprintf (trace_buffer.fp, " %d", percent);
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  if (guestfs_int_check_appliance_up (g, "lvcreate_free") == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "lvcreate_free", "-1");
    return -1;
  }

  args.logvol = (char *) logvol;
  args.volgroup = (char *) volgroup;
  args.percent = percent;
  serial = guestfs_int_send (g, GUESTFS_PROC_LVCREATE_FREE,
                             progress_hint, 0,
                             (xdrproc_t) xdr_guestfs_lvcreate_free_args, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "lvcreate_free", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs_int_recv (g, "lvcreate_free", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "lvcreate_free", "-1");
    return -1;
  }

  if (guestfs_int_check_reply_header (g, &hdr, GUESTFS_PROC_LVCREATE_FREE, serial) == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "lvcreate_free", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "lvcreate_free", "-1");
    if (err.errno_string[0] != '\0')
      errnum = guestfs_int_string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "lvcreate_free", err.error_message);
    else
      guestfs_int_error_errno (g, errnum, "%s: %s", "lvcreate_free",
                               err.error_message);
    free (err.error_message);
    free (err.errno_string);
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "lvcreate_free");
    fprintf (trace_buffer.fp, "%d", ret_v);
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  return ret_v;
}

GUESTFS_DLL_PUBLIC int
guestfs_lvm_set_filter (guestfs_h *g,
                        char *const *devices)
{
  struct guestfs_lvm_set_filter_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs_int_call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                      "lvm_set_filter", 14);
  if (devices == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "lvm_set_filter", "devices");
    return -1;
  }

  if (trace_flag) {
    size_t i;

    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "lvm_set_filter");
    fputc (' ', trace_buffer.fp);
    fputc ('"', trace_buffer.fp);
    for (i = 0; devices[i]; ++i) {
      if (i > 0) fputc (' ', trace_buffer.fp);
      fputs (devices[i], trace_buffer.fp);
    }
    fputc ('"', trace_buffer.fp);
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  if (guestfs_int_check_appliance_up (g, "lvm_set_filter") == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "lvm_set_filter", "-1");
    return -1;
  }

  args.devices.devices_val = (char **) devices;
  for (args.devices.devices_len = 0; devices[args.devices.devices_len]; args.devices.devices_len++) ;
  serial = guestfs_int_send (g, GUESTFS_PROC_LVM_SET_FILTER,
                             progress_hint, 0,
                             (xdrproc_t) xdr_guestfs_lvm_set_filter_args, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "lvm_set_filter", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs_int_recv (g, "lvm_set_filter", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "lvm_set_filter", "-1");
    return -1;
  }

  if (guestfs_int_check_reply_header (g, &hdr, GUESTFS_PROC_LVM_SET_FILTER, serial) == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "lvm_set_filter", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "lvm_set_filter", "-1");
    if (err.errno_string[0] != '\0')
      errnum = guestfs_int_string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "lvm_set_filter", err.error_message);
    else
      guestfs_int_error_errno (g, errnum, "%s: %s", "lvm_set_filter",
                               err.error_message);
    free (err.error_message);
    free (err.errno_string);
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "lvm_set_filter");
    fprintf (trace_buffer.fp, "%d", ret_v);
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  return ret_v;
}

GUESTFS_DLL_PUBLIC struct guestfs_lvm_lv_list *
guestfs_lvs_full (guestfs_h *g)
{
  guestfs_message_header hdr;
  guestfs_message_error err;
  struct guestfs_lvs_full_ret ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  struct guestfs_lvm_lv_list *ret_v;
  const uint64_t progress_hint = 0;

  guestfs_int_call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                      "lvs_full", 8);
  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "lvs_full");
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  if (guestfs_int_check_appliance_up (g, "lvs_full") == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "lvs_full", "NULL");
    return NULL;
  }

  serial = guestfs_int_send (g, GUESTFS_PROC_LVS_FULL, progress_hint, 0,
                             NULL, NULL);
  if (serial == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "lvs_full", "NULL");
    return NULL;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs_int_recv (g, "lvs_full", &hdr, &err,
        (xdrproc_t) xdr_guestfs_lvs_full_ret, (char *) &ret);
  if (r == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "lvs_full", "NULL");
    return NULL;
  }

  if (guestfs_int_check_reply_header (g, &hdr, GUESTFS_PROC_LVS_FULL, serial) == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "lvs_full", "NULL");
    return NULL;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "lvs_full", "NULL");
    if (err.errno_string[0] != '\0')
      errnum = guestfs_int_string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "lvs_full", err.error_message);
    else
      guestfs_int_error_errno (g, errnum, "%s: %s", "lvs_full",
                               err.error_message);
    free (err.error_message);
    free (err.errno_string);
    return NULL;
  }

  /* caller will free this */
  ret_v = safe_memdup (g, &ret.logvols, sizeof (ret.logvols));
  if (trace_flag) {
    size_t i;

    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "lvs_full");
    fprintf (trace_buffer.fp, "<struct guestfs_lvm_lv_list(%u)", ret_v->len);
    if (ret_v->len > 0)
      fprintf (trace_buffer.fp, " = ");
    for (i = 0; i < ret_v->len; ++i) {
      if (i != 0)
        fprintf (trace_buffer.fp, " ");
      fprintf (trace_buffer.fp, "[%zu]{", i);
      guestfs_int_print_lvm_lv_indent (&ret_v->val[i], trace_buffer.fp, ", ", "");
      fprintf (trace_buffer.fp, "}");
    }
    fprintf (trace_buffer.fp, ">");
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  return ret_v;
}

GUESTFS_DLL_PUBLIC struct guestfs_mdstat_list *
guestfs_md_stat (guestfs_h *g,
                 const char *md)
{
  struct guestfs_md_stat_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  struct guestfs_md_stat_ret ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  struct guestfs_mdstat_list *ret_v;
  const uint64_t progress_hint = 0;

  guestfs_int_call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                      "md_stat", 7);
  if (md == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "md_stat", "md");
    return NULL;
  }

  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "md_stat");
    fprintf (trace_buffer.fp, " \"%s\"", md);
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  if (guestfs_int_check_appliance_up (g, "md_stat") == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "md_stat", "NULL");
    return NULL;
  }

  args.md = (char *) md;
  serial = guestfs_int_send (g, GUESTFS_PROC_MD_STAT,
                             progress_hint, 0,
                             (xdrproc_t) xdr_guestfs_md_stat_args, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "md_stat", "NULL");
    return NULL;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs_int_recv (g, "md_stat", &hdr, &err,
        (xdrproc_t) xdr_guestfs_md_stat_ret, (char *) &ret);
  if (r == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "md_stat", "NULL");
    return NULL;
  }

  if (guestfs_int_check_reply_header (g, &hdr, GUESTFS_PROC_MD_STAT, serial) == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "md_stat", "NULL");
    return NULL;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "md_stat", "NULL");
    if (err.errno_string[0] != '\0')
      errnum = guestfs_int_string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "md_stat", err.error_message);
    else
      guestfs_int_error_errno (g, errnum, "%s: %s", "md_stat",
                               err.error_message);
    free (err.error_message);
    free (err.errno_string);
    return NULL;
  }

  /* caller will free this */
  ret_v = safe_memdup (g, &ret.devices, sizeof (ret.devices));
  if (trace_flag) {
    size_t i;

    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "md_stat");
    fprintf (trace_buffer.fp, "<struct guestfs_mdstat_list(%u)", ret_v->len);
    if (ret_v->len > 0)
      fprintf (trace_buffer.fp, " = ");
    for (i = 0; i < ret_v->len; ++i) {
      if (i != 0)
        fprintf (trace_buffer.fp, " ");
      fprintf (trace_buffer.fp, "[%zu]{", i);
      guestfs_int_print_mdstat_indent (&ret_v->val[i], trace_buffer.fp, ", ", "");
      fprintf (trace_buffer.fp, "}");
    }
    fprintf (trace_buffer.fp, ">");
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  return ret_v;
}

GUESTFS_DLL_PUBLIC int
guestfs_mkfs_opts_argv (guestfs_h *g,
                        const char *fstype,
                        const char *device,
                        const struct guestfs_mkfs_opts_argv *optargs)
{
  struct guestfs_mkfs_opts_argv optargs_null;
  if (!optargs) {
    optargs_null.bitmask = 0;
    optargs = &optargs_null;
  }

  struct guestfs_mkfs_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs_int_call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                      "mkfs", 4);
  if (fstype == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "mkfs_opts", "fstype");
    return -1;
  }
  if (device == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "mkfs_opts", "device");
    return -1;
  }
  if ((optargs->bitmask & GUESTFS_MKFS_OPTS_FEATURES_BITMASK) &&
      optargs->features == NULL) {
    error (g, "%s: %s: optional parameter cannot be NULL",
           "mkfs_opts", "features");
    return -1;
  }
  if ((optargs->bitmask & GUESTFS_MKFS_OPTS_LABEL_BITMASK) &&
      optargs->label == NULL) {
    error (g, "%s: %s: optional parameter cannot be NULL",
           "mkfs_opts", "label");
    return -1;
  }

  if (optargs->bitmask & UINT64_C(0xffffffffffffffe0)) {
    error (g, "%s: unknown option in guestfs_%s_argv->bitmask (this can happen if a program is compiled against a newer version of libguestfs, then dynamically linked to an older version)",
           "mkfs_opts", "mkfs_opts");
    return -1;
  }

  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "mkfs");
    fprintf (trace_buffer.fp, " \"%s\"", fstype);
    fprintf (trace_buffer.fp, " \"%s\"", device);
    if (optargs->bitmask & GUESTFS_MKFS_OPTS_BLOCKSIZE_BITMASK) {
      fprintf (trace_buffer.fp, " \"%s:%d\"", "blocksize", optargs->blocksize);
    }
    if (optargs->bitmask & GUESTFS_MKFS_OPTS_FEATURES_BITMASK) {
      fprintf (trace_buffer.fp, " \"%s:%s\"", "features", optargs->features);
    }
    if (optargs->bitmask & GUESTFS_MKFS_OPTS_INODE_BITMASK) {
      fprintf (trace_buffer.fp, " \"%s:%d\"", "inode", optargs->inode);
    }
    if (optargs->bitmask & GUESTFS_MKFS_OPTS_SECTORSIZE_BITMASK) {
      fprintf (trace_buffer.fp, " \"%s:%d\"", "sectorsize", optargs->sectorsize);
    }
    if (optargs->bitmask & GUESTFS_MKFS_OPTS_LABEL_BITMASK) {
      fprintf (trace_buffer.fp, " \"%s:%s\"", "label", optargs->label);
    }
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  if (guestfs_int_check_appliance_up (g, "mkfs") == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "mkfs", "-1");
    return -1;
  }

  args.fstype = (char *) fstype;
  args.device = (char *) device;
  if (optargs->bitmask & GUESTFS_MKFS_OPTS_BLOCKSIZE_BITMASK) {
    args.blocksize = optargs->blocksize;
  } else {
    args.blocksize = 0;
  }
  if (optargs->bitmask & GUESTFS_MKFS_OPTS_FEATURES_BITMASK) {
    args.features = (char *) optargs->features;
  } else {
    args.features = (char *) "";
  }
  if (optargs->bitmask & GUESTFS_MKFS_OPTS_INODE_BITMASK) {
    args.inode = optargs->inode;
  } else {
    args.inode = 0;
  }
  if (optargs->bitmask & GUESTFS_MKFS_OPTS_SECTORSIZE_BITMASK) {
    args.sectorsize = optargs->sectorsize;
  } else {
    args.sectorsize = 0;
  }
  if (optargs->bitmask & GUESTFS_MKFS_OPTS_LABEL_BITMASK) {
    args.label = (char *) optargs->label;
  } else {
    args.label = (char *) "";
  }
  serial = guestfs_int_send (g, GUESTFS_PROC_MKFS,
                             progress_hint, optargs->bitmask,
                             (xdrproc_t) xdr_guestfs_mkfs_args, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "mkfs", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs_int_recv (g, "mkfs", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "mkfs", "-1");
    return -1;
  }

  if (guestfs_int_check_reply_header (g, &hdr, GUESTFS_PROC_MKFS, serial) == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "mkfs", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "mkfs", "-1");
    if (err.errno_string[0] != '\0')
      errnum = guestfs_int_string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "mkfs", err.error_message);
    else
      guestfs_int_error_errno (g, errnum, "%s: %s", "mkfs",
                               err.error_message);
    free (err.error_message);
    free (err.errno_string);
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "mkfs");
    fprintf (trace_buffer.fp, "%d", ret_v);
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  return ret_v;
}

GUESTFS_DLL_PUBLIC int
guestfs_mkfs_b (guestfs_h *g,
                const char *fstype,
                int blocksize,
                const char *device)
{
  struct guestfs_mkfs_b_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs_int_call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                      "mkfs_b", 6);
  if (fstype == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "mkfs_b", "fstype");
    return -1;
  }
  if (device == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "mkfs_b", "device");
    return -1;
  }

  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "mkfs_b");
    fprintf (trace_buffer.fp, " \"%s\"", fstype);
    fprintf (trace_buffer.fp, " %d", blocksize);
    fprintf (trace_buffer.fp, " \"%s\"", device);
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  if (guestfs_int_check_appliance_up (g, "mkfs_b") == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "mkfs_b", "-1");
    return -1;
  }

  args.fstype = (char *) fstype;
  args.blocksize = blocksize;
  args.device = (char *) device;
  serial = guestfs_int_send (g, GUESTFS_PROC_MKFS_B,
                             progress_hint, 0,
                             (xdrproc_t) xdr_guestfs_mkfs_b_args, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "mkfs_b", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs_int_recv (g, "mkfs_b", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "mkfs_b", "-1");
    return -1;
  }

  if (guestfs_int_check_reply_header (g, &hdr, GUESTFS_PROC_MKFS_B, serial) == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "mkfs_b", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "mkfs_b", "-1");
    if (err.errno_string[0] != '\0')
      errnum = guestfs_int_string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "mkfs_b", err.error_message);
    else
      guestfs_int_error_errno (g, errnum, "%s: %s", "mkfs_b",
                               err.error_message);
    free (err.error_message);
    free (err.errno_string);
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "mkfs_b");
    fprintf (trace_buffer.fp, "%d", ret_v);
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  return ret_v;
}

GUESTFS_DLL_PUBLIC int
guestfs_mkswap_U (guestfs_h *g,
                  const char *uuid,
                  const char *device)
{
  struct guestfs_mkswap_U_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs_int_call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                      "mkswap_U", 8);
  if (uuid == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "mkswap_U", "uuid");
    return -1;
  }
  if (device == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "mkswap_U", "device");
    return -1;
  }

  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "mkswap_U");
    fprintf (trace_buffer.fp, " \"%s\"", uuid);
    fprintf (trace_buffer.fp, " \"%s\"", device);
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  if (guestfs_int_check_appliance_up (g, "mkswap_U") == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "mkswap_U", "-1");
    return -1;
  }

  args.uuid = (char *) uuid;
  args.device = (char *) device;
  serial = guestfs_int_send (g, GUESTFS_PROC_MKSWAP_U,
                             progress_hint, 0,
                             (xdrproc_t) xdr_guestfs_mkswap_U_args, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "mkswap_U", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs_int_recv (g, "mkswap_U", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "mkswap_U", "-1");
    return -1;
  }

  if (guestfs_int_check_reply_header (g, &hdr, GUESTFS_PROC_MKSWAP_U, serial) == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "mkswap_U", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "mkswap_U", "-1");
    if (err.errno_string[0] != '\0')
      errnum = guestfs_int_string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "mkswap_U", err.error_message);
    else
      guestfs_int_error_errno (g, errnum, "%s: %s", "mkswap_U",
                               err.error_message);
    free (err.error_message);
    free (err.errno_string);
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "mkswap_U");
    fprintf (trace_buffer.fp, "%d", ret_v);
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  return ret_v;
}

GUESTFS_DLL_PUBLIC char **
guestfs_mountpoints (guestfs_h *g)
{
  guestfs_message_header hdr;
  guestfs_message_error err;
  struct guestfs_mountpoints_ret ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  char **ret_v;
  const uint64_t progress_hint = 0;

  guestfs_int_call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                      "mountpoints", 11);
  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "mountpoints");
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  if (guestfs_int_check_appliance_up (g, "mountpoints") == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "mountpoints", "NULL");
    return NULL;
  }

  serial = guestfs_int_send (g, GUESTFS_PROC_MOUNTPOINTS, progress_hint, 0,
                             NULL, NULL);
  if (serial == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "mountpoints", "NULL");
    return NULL;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs_int_recv (g, "mountpoints", &hdr, &err,
        (xdrproc_t) xdr_guestfs_mountpoints_ret, (char *) &ret);
  if (r == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "mountpoints", "NULL");
    return NULL;
  }

  if (guestfs_int_check_reply_header (g, &hdr, GUESTFS_PROC_MOUNTPOINTS, serial) == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "mountpoints", "NULL");
    return NULL;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "mountpoints", "NULL");
    if (err.errno_string[0] != '\0')
      errnum = guestfs_int_string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "mountpoints", err.error_message);
    else
      guestfs_int_error_errno (g, errnum, "%s: %s", "mountpoints",
                               err.error_message);
    free (err.error_message);
    free (err.errno_string);
    return NULL;
  }

  /* caller will free this, but we need to add a NULL entry */
  ret.mps.mps_val =
    safe_realloc (g, ret.mps.mps_val,
                  sizeof (char *) * (ret.mps.mps_len + 1));
  ret.mps.mps_val[ret.mps.mps_len] = NULL;
  ret_v = ret.mps.mps_val;
  if (trace_flag) {
    size_t i;

    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "mountpoints");
    fputs ("[", trace_buffer.fp);
    for (i = 0; ret_v[i]; ++i) {
      if (i > 0) fputs (", ", trace_buffer.fp);
      fputs ("\"", trace_buffer.fp);
      fputs (ret_v[i], trace_buffer.fp);
      fputs ("\"", trace_buffer.fp);
    }
    fputs ("]", trace_buffer.fp);
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  return ret_v;
}

GUESTFS_DLL_PUBLIC int
guestfs_nr_devices (guestfs_h *g)
{
  guestfs_message_header hdr;
  guestfs_message_error err;
  struct guestfs_nr_devices_ret ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs_int_call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                      "nr_devices", 10);
  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "nr_devices");
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  if (guestfs_int_check_appliance_up (g, "nr_devices") == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "nr_devices", "-1");
    return -1;
  }

  serial = guestfs_int_send (g, GUESTFS_PROC_NR_DEVICES, progress_hint, 0,
                             NULL, NULL);
  if (serial == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "nr_devices", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs_int_recv (g, "nr_devices", &hdr, &err,
        (xdrproc_t) xdr_guestfs_nr_devices_ret, (char *) &ret);
  if (r == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "nr_devices", "-1");
    return -1;
  }

  if (guestfs_int_check_reply_header (g, &hdr, GUESTFS_PROC_NR_DEVICES, serial) == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "nr_devices", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "nr_devices", "-1");
    if (err.errno_string[0] != '\0')
      errnum = guestfs_int_string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "nr_devices", err.error_message);
    else
      guestfs_int_error_errno (g, errnum, "%s: %s", "nr_devices",
                               err.error_message);
    free (err.error_message);
    free (err.errno_string);
    return -1;
  }

  ret_v = ret.nrdisks;
  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "nr_devices");
    fprintf (trace_buffer.fp, "%d", ret_v);
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  return ret_v;
}

GUESTFS_DLL_PUBLIC int
guestfs_ntfsclone_in (guestfs_h *g,
                      const char *backupfile,
                      const char *device)
{
  struct guestfs_ntfsclone_in_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int ret_v;
  uint64_t progress_hint = 0;
  struct stat progress_stat;

  guestfs_int_call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                      "ntfsclone_in", 12);
  if (backupfile == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "ntfsclone_in", "backupfile");
    return -1;
  }
  if (device == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "ntfsclone_in", "device");
    return -1;
  }

  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "ntfsclone_in");
    fprintf (trace_buffer.fp, " \"%s\"", backupfile);
    fprintf (trace_buffer.fp, " \"%s\"", device);
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  if (stat (backupfile, &progress_stat) == 0 &&
      S_ISREG (progress_stat.st_mode))
    progress_hint += progress_stat.st_size;

  if (guestfs_int_check_appliance_up (g, "ntfsclone_in") == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "ntfsclone_in", "-1");
    return -1;
  }

  args.device = (char *) device;
  serial = guestfs_int_send (g, GUESTFS_PROC_NTFSCLONE_IN,
                             progress_hint, 0,
                             (xdrproc_t) xdr_guestfs_ntfsclone_in_args, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "ntfsclone_in", "-1");
    return -1;
  }

  r = guestfs_int_send_file (g, backupfile);
  if (r == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "ntfsclone_in", "-1");
    /* daemon will send an error reply which we discard */
    guestfs_int_recv_discard (g, "ntfsclone_in");
    return -1;
  }
  if (r == -2) /* daemon cancelled */
    goto read_reply;

 read_reply:
  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs_int_recv (g, "ntfsclone_in", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "ntfsclone_in", "-1");
    return -1;
  }

  if (guestfs_int_check_reply_header (g, &hdr, GUESTFS_PROC_NTFSCLONE_IN, serial) == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "ntfsclone_in", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "ntfsclone_in", "-1");
    if (err.errno_string[0] != '\0')
      errnum = guestfs_int_string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "ntfsclone_in", err.error_message);
    else
      guestfs_int_error_errno (g, errnum, "%s: %s", "ntfsclone_in",
                               err.error_message);
    free (err.error_message);
    free (err.errno_string);
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "ntfsclone_in");
    fprintf (trace_buffer.fp, "%d", ret_v);
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  return ret_v;
}

GUESTFS_DLL_PUBLIC int
guestfs_part_get_bootable (guestfs_h *g,
                           const char *device,
                           int partnum)
{
  struct guestfs_part_get_bootable_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  struct guestfs_part_get_bootable_ret ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs_int_call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                      "part_get_bootable", 17);
  if (device == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "part_get_bootable", "device");
    return -1;
  }

  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "part_get_bootable");
    fprintf (trace_buffer.fp, " \"%s\"", device);
    fprintf (trace_buffer.fp, " %d", partnum);
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  if (guestfs_int_check_appliance_up (g, "part_get_bootable") == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "part_get_bootable", "-1");
    return -1;
  }

  args.device = (char *) device;
  args.partnum = partnum;
  serial = guestfs_int_send (g, GUESTFS_PROC_PART_GET_BOOTABLE,
                             progress_hint, 0,
                             (xdrproc_t) xdr_guestfs_part_get_bootable_args, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "part_get_bootable", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs_int_recv (g, "part_get_bootable", &hdr, &err,
        (xdrproc_t) xdr_guestfs_part_get_bootable_ret, (char *) &ret);
  if (r == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "part_get_bootable", "-1");
    return -1;
  }

  if (guestfs_int_check_reply_header (g, &hdr, GUESTFS_PROC_PART_GET_BOOTABLE, serial) == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "part_get_bootable", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "part_get_bootable", "-1");
    if (err.errno_string[0] != '\0')
      errnum = guestfs_int_string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "part_get_bootable", err.error_message);
    else
      guestfs_int_error_errno (g, errnum, "%s: %s", "part_get_bootable",
                               err.error_message);
    free (err.error_message);
    free (err.errno_string);
    return -1;
  }

  ret_v = ret.bootable;
  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "part_get_bootable");
    fprintf (trace_buffer.fp, "%d", ret_v);
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  return ret_v;
}

GUESTFS_DLL_PUBLIC int
guestfs_part_set_gpt_type (guestfs_h *g,
                           const char *device,
                           int partnum,
                           const char *guid)
{
  struct guestfs_part_set_gpt_type_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs_int_call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                      "part_set_gpt_type", 17);
  if (device == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "part_set_gpt_type", "device");
    return -1;
  }
  if (guid == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "part_set_gpt_type", "guid");
    return -1;
  }

  if (!guestfs_int_validate_guid (guid)) {
    error (g, "%s: %s: parameter is not a valid GUID",
           "part_set_gpt_type", "guid");
    return -1;
  }

  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "part_set_gpt_type");
    fprintf (trace_buffer.fp, " \"%s\"", device);
    fprintf (trace_buffer.fp, " %d", partnum);
    fprintf (trace_buffer.fp, " \"%s\"", guid);
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  if (guestfs_int_check_appliance_up (g, "part_set_gpt_type") == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "part_set_gpt_type", "-1");
    return -1;
  }

  args.device = (char *) device;
  args.partnum = partnum;
  args.guid = (char *) guid;
  serial = guestfs_int_send (g, GUESTFS_PROC_PART_SET_GPT_TYPE,
                             progress_hint, 0,
                             (xdrproc_t) xdr_guestfs_part_set_gpt_type_args, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "part_set_gpt_type", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs_int_recv (g, "part_set_gpt_type", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "part_set_gpt_type", "-1");
    return -1;
  }

  if (guestfs_int_check_reply_header (g, &hdr, GUESTFS_PROC_PART_SET_GPT_TYPE, serial) == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "part_set_gpt_type", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "part_set_gpt_type", "-1");
    if (err.errno_string[0] != '\0')
      errnum = guestfs_int_string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "part_set_gpt_type", err.error_message);
    else
      guestfs_int_error_errno (g, errnum, "%s: %s", "part_set_gpt_type",
                               err.error_message);
    free (err.error_message);
    free (err.errno_string);
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "part_set_gpt_type");
    fprintf (trace_buffer.fp, "%d", ret_v);
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  return ret_v;
}

GUESTFS_DLL_PUBLIC int
guestfs_part_set_name (guestfs_h *g,
                       const char *device,
                       int partnum,
                       const char *name)
{
  struct guestfs_part_set_name_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs_int_call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                      "part_set_name", 13);
  if (device == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "part_set_name", "device");
    return -1;
  }
  if (name == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "part_set_name", "name");
    return -1;
  }

  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "part_set_name");
    fprintf (trace_buffer.fp, " \"%s\"", device);
    fprintf (trace_buffer.fp, " %d", partnum);
    fprintf (trace_buffer.fp, " \"%s\"", name);
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  if (guestfs_int_check_appliance_up (g, "part_set_name") == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "part_set_name", "-1");
    return -1;
  }

  args.device = (char *) device;
  args.partnum = partnum;
  args.name = (char *) name;
  serial = guestfs_int_send (g, GUESTFS_PROC_PART_SET_NAME,
                             progress_hint, 0,
                             (xdrproc_t) xdr_guestfs_part_set_name_args, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "part_set_name", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs_int_recv (g, "part_set_name", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "part_set_name", "-1");
    return -1;
  }

  if (guestfs_int_check_reply_header (g, &hdr, GUESTFS_PROC_PART_SET_NAME, serial) == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "part_set_name", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "part_set_name", "-1");
    if (err.errno_string[0] != '\0')
      errnum = guestfs_int_string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "part_set_name", err.error_message);
    else
      guestfs_int_error_errno (g, errnum, "%s: %s", "part_set_name",
                               err.error_message);
    free (err.error_message);
    free (err.errno_string);
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "part_set_name");
    fprintf (trace_buffer.fp, "%d", ret_v);
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  return ret_v;
}

GUESTFS_DLL_PUBLIC int
guestfs_pvremove (guestfs_h *g,
                  const char *device)
{
  struct guestfs_pvremove_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs_int_call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                      "pvremove", 8);
  if (device == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "pvremove", "device");
    return -1;
  }

  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "pvremove");
    fprintf (trace_buffer.fp, " \"%s\"", device);
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  if (guestfs_int_check_appliance_up (g, "pvremove") == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "pvremove", "-1");
    return -1;
  }

  args.device = (char *) device;
  serial = guestfs_int_send (g, GUESTFS_PROC_PVREMOVE,
                             progress_hint, 0,
                             (xdrproc_t) xdr_guestfs_pvremove_args, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "pvremove", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs_int_recv (g, "pvremove", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "pvremove", "-1");
    return -1;
  }

  if (guestfs_int_check_reply_header (g, &hdr, GUESTFS_PROC_PVREMOVE, serial) == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "pvremove", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "pvremove", "-1");
    if (err.errno_string[0] != '\0')
      errnum = guestfs_int_string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "pvremove", err.error_message);
    else
      guestfs_int_error_errno (g, errnum, "%s: %s", "pvremove",
                               err.error_message);
    free (err.error_message);
    free (err.errno_string);
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "pvremove");
    fprintf (trace_buffer.fp, "%d", ret_v);
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  return ret_v;
}

GUESTFS_DLL_PUBLIC int
guestfs_scrub_freespace (guestfs_h *g,
                         const char *dir)
{
  struct guestfs_scrub_freespace_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs_int_call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                      "scrub_freespace", 15);
  if (dir == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "scrub_freespace", "dir");
    return -1;
  }

  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "scrub_freespace");
    fprintf (trace_buffer.fp, " \"%s\"", dir);
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  if (guestfs_int_check_appliance_up (g, "scrub_freespace") == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "scrub_freespace", "-1");
    return -1;
  }

  args.dir = (char *) dir;
  serial = guestfs_int_send (g, GUESTFS_PROC_SCRUB_FREESPACE,
                             progress_hint, 0,
                             (xdrproc_t) xdr_guestfs_scrub_freespace_args, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "scrub_freespace", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs_int_recv (g, "scrub_freespace", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "scrub_freespace", "-1");
    return -1;
  }

  if (guestfs_int_check_reply_header (g, &hdr, GUESTFS_PROC_SCRUB_FREESPACE, serial) == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "scrub_freespace", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "scrub_freespace", "-1");
    if (err.errno_string[0] != '\0')
      errnum = guestfs_int_string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "scrub_freespace", err.error_message);
    else
      guestfs_int_error_errno (g, errnum, "%s: %s", "scrub_freespace",
                               err.error_message);
    free (err.error_message);
    free (err.errno_string);
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "scrub_freespace");
    fprintf (trace_buffer.fp, "%d", ret_v);
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  return ret_v;
}

GUESTFS_DLL_PUBLIC int
guestfs_set_uuid_random (guestfs_h *g,
                         const char *device)
{
  struct guestfs_set_uuid_random_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs_int_call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                      "set_uuid_random", 15);
  if (device == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "set_uuid_random", "device");
    return -1;
  }

  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "set_uuid_random");
    fprintf (trace_buffer.fp, " \"%s\"", device);
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  if (guestfs_int_check_appliance_up (g, "set_uuid_random") == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "set_uuid_random", "-1");
    return -1;
  }

  args.device = (char *) device;
  serial = guestfs_int_send (g, GUESTFS_PROC_SET_UUID_RANDOM,
                             progress_hint, 0,
                             (xdrproc_t) xdr_guestfs_set_uuid_random_args, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "set_uuid_random", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs_int_recv (g, "set_uuid_random", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "set_uuid_random", "-1");
    return -1;
  }

  if (guestfs_int_check_reply_header (g, &hdr, GUESTFS_PROC_SET_UUID_RANDOM, serial) == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "set_uuid_random", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "set_uuid_random", "-1");
    if (err.errno_string[0] != '\0')
      errnum = guestfs_int_string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "set_uuid_random", err.error_message);
    else
      guestfs_int_error_errno (g, errnum, "%s: %s", "set_uuid_random",
                               err.error_message);
    free (err.error_message);
    free (err.errno_string);
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "set_uuid_random");
    fprintf (trace_buffer.fp, "%d", ret_v);
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  return ret_v;
}

GUESTFS_DLL_PUBLIC int
guestfs_sfdisk (guestfs_h *g,
                const char *device,
                int cyls,
                int heads,
                int sectors,
                char *const *lines)
{
  struct guestfs_sfdisk_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs_int_call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                      "sfdisk", 6);
  if (device == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "sfdisk", "device");
    return -1;
  }
  if (lines == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "sfdisk", "lines");
    return -1;
  }

  if (trace_flag) {
    size_t i;

    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "sfdisk");
    fprintf (trace_buffer.fp, " \"%s\"", device);
    fprintf (trace_buffer.fp, " %d", cyls);
    fprintf (trace_buffer.fp, " %d", heads);
    fprintf (trace_buffer.fp, " %d", sectors);
    fputc (' ', trace_buffer.fp);
    fputc ('"', trace_buffer.fp);
    for (i = 0; lines[i]; ++i) {
      if (i > 0) fputc (' ', trace_buffer.fp);
      fputs (lines[i], trace_buffer.fp);
    }
    fputc ('"', trace_buffer.fp);
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  if (guestfs_int_check_appliance_up (g, "sfdisk") == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "sfdisk", "-1");
    return -1;
  }

  args.device = (char *) device;
  args.cyls = cyls;
  args.heads = heads;
  args.sectors = sectors;
  args.lines.lines_val = (char **) lines;
  for (args.lines.lines_len = 0; lines[args.lines.lines_len]; args.lines.lines_len++) ;
  serial = guestfs_int_send (g, GUESTFS_PROC_SFDISK,
                             progress_hint, 0,
                             (xdrproc_t) xdr_guestfs_sfdisk_args, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "sfdisk", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs_int_recv (g, "sfdisk", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "sfdisk", "-1");
    return -1;
  }

  if (guestfs_int_check_reply_header (g, &hdr, GUESTFS_PROC_SFDISK, serial) == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "sfdisk", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "sfdisk", "-1");
    if (err.errno_string[0] != '\0')
      errnum = guestfs_int_string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "sfdisk", err.error_message);
    else
      guestfs_int_error_errno (g, errnum, "%s: %s", "sfdisk",
                               err.error_message);
    free (err.error_message);
    free (err.errno_string);
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "sfdisk");
    fprintf (trace_buffer.fp, "%d", ret_v);
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  return ret_v;
}

GUESTFS_DLL_PUBLIC int
guestfs_sfdiskM (guestfs_h *g,
                 const char *device,
                 char *const *lines)
{
  struct guestfs_sfdiskM_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs_int_call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                      "sfdiskM", 7);
  if (device == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "sfdiskM", "device");
    return -1;
  }
  if (lines == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "sfdiskM", "lines");
    return -1;
  }

  if (trace_flag) {
    size_t i;

    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "sfdiskM");
    fprintf (trace_buffer.fp, " \"%s\"", device);
    fputc (' ', trace_buffer.fp);
    fputc ('"', trace_buffer.fp);
    for (i = 0; lines[i]; ++i) {
      if (i > 0) fputc (' ', trace_buffer.fp);
      fputs (lines[i], trace_buffer.fp);
    }
    fputc ('"', trace_buffer.fp);
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  if (guestfs_int_check_appliance_up (g, "sfdiskM") == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "sfdiskM", "-1");
    return -1;
  }

  args.device = (char *) device;
  args.lines.lines_val = (char **) lines;
  for (args.lines.lines_len = 0; lines[args.lines.lines_len]; args.lines.lines_len++) ;
  serial = guestfs_int_send (g, GUESTFS_PROC_SFDISKM,
                             progress_hint, 0,
                             (xdrproc_t) xdr_guestfs_sfdiskM_args, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "sfdiskM", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs_int_recv (g, "sfdiskM", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "sfdiskM", "-1");
    return -1;
  }

  if (guestfs_int_check_reply_header (g, &hdr, GUESTFS_PROC_SFDISKM, serial) == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "sfdiskM", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "sfdiskM", "-1");
    if (err.errno_string[0] != '\0')
      errnum = guestfs_int_string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "sfdiskM", err.error_message);
    else
      guestfs_int_error_errno (g, errnum, "%s: %s", "sfdiskM",
                               err.error_message);
    free (err.error_message);
    free (err.errno_string);
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "sfdiskM");
    fprintf (trace_buffer.fp, "%d", ret_v);
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  return ret_v;
}

GUESTFS_DLL_PUBLIC int
guestfs_sfdisk_N (guestfs_h *g,
                  const char *device,
                  int partnum,
                  int cyls,
                  int heads,
                  int sectors,
                  const char *line)
{
  struct guestfs_sfdisk_N_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs_int_call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                      "sfdisk_N", 8);
  if (device == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "sfdisk_N", "device");
    return -1;
  }
  if (line == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "sfdisk_N", "line");
    return -1;
  }

  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "sfdisk_N");
    fprintf (trace_buffer.fp, " \"%s\"", device);
    fprintf (trace_buffer.fp, " %d", partnum);
    fprintf (trace_buffer.fp, " %d", cyls);
    fprintf (trace_buffer.fp, " %d", heads);
    fprintf (trace_buffer.fp, " %d", sectors);
    fprintf (trace_buffer.fp, " \"%s\"", line);
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  if (guestfs_int_check_appliance_up (g, "sfdisk_N") == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "sfdisk_N", "-1");
    return -1;
  }

  args.device = (char *) device;
  args.partnum = partnum;
  args.cyls = cyls;
  args.heads = heads;
  args.sectors = sectors;
  args.line = (char *) line;
  serial = guestfs_int_send (g, GUESTFS_PROC_SFDISK_N,
                             progress_hint, 0,
                             (xdrproc_t) xdr_guestfs_sfdisk_N_args, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "sfdisk_N", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs_int_recv (g, "sfdisk_N", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "sfdisk_N", "-1");
    return -1;
  }

  if (guestfs_int_check_reply_header (g, &hdr, GUESTFS_PROC_SFDISK_N, serial) == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "sfdisk_N", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "sfdisk_N", "-1");
    if (err.errno_string[0] != '\0')
      errnum = guestfs_int_string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "sfdisk_N", err.error_message);
    else
      guestfs_int_error_errno (g, errnum, "%s: %s", "sfdisk_N",
                               err.error_message);
    free (err.error_message);
    free (err.errno_string);
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "sfdisk_N");
    fprintf (trace_buffer.fp, "%d", ret_v);
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  return ret_v;
}

GUESTFS_DLL_PUBLIC int
guestfs_swapoff_device (guestfs_h *g,
                        const char *device)
{
  struct guestfs_swapoff_device_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs_int_call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                      "swapoff_device", 14);
  if (device == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "swapoff_device", "device");
    return -1;
  }

  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "swapoff_device");
    fprintf (trace_buffer.fp, " \"%s\"", device);
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  if (guestfs_int_check_appliance_up (g, "swapoff_device") == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "swapoff_device", "-1");
    return -1;
  }

  args.device = (char *) device;
  serial = guestfs_int_send (g, GUESTFS_PROC_SWAPOFF_DEVICE,
                             progress_hint, 0,
                             (xdrproc_t) xdr_guestfs_swapoff_device_args, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "swapoff_device", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs_int_recv (g, "swapoff_device", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "swapoff_device", "-1");
    return -1;
  }

  if (guestfs_int_check_reply_header (g, &hdr, GUESTFS_PROC_SWAPOFF_DEVICE, serial) == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "swapoff_device", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "swapoff_device", "-1");
    if (err.errno_string[0] != '\0')
      errnum = guestfs_int_string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "swapoff_device", err.error_message);
    else
      guestfs_int_error_errno (g, errnum, "%s: %s", "swapoff_device",
                               err.error_message);
    free (err.error_message);
    free (err.errno_string);
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "swapoff_device");
    fprintf (trace_buffer.fp, "%d", ret_v);
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  return ret_v;
}

GUESTFS_DLL_PUBLIC int
guestfs_swapon_device (guestfs_h *g,
                       const char *device)
{
  struct guestfs_swapon_device_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs_int_call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                      "swapon_device", 13);
  if (device == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "swapon_device", "device");
    return -1;
  }

  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "swapon_device");
    fprintf (trace_buffer.fp, " \"%s\"", device);
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  if (guestfs_int_check_appliance_up (g, "swapon_device") == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "swapon_device", "-1");
    return -1;
  }

  args.device = (char *) device;
  serial = guestfs_int_send (g, GUESTFS_PROC_SWAPON_DEVICE,
                             progress_hint, 0,
                             (xdrproc_t) xdr_guestfs_swapon_device_args, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "swapon_device", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs_int_recv (g, "swapon_device", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "swapon_device", "-1");
    return -1;
  }

  if (guestfs_int_check_reply_header (g, &hdr, GUESTFS_PROC_SWAPON_DEVICE, serial) == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "swapon_device", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "swapon_device", "-1");
    if (err.errno_string[0] != '\0')
      errnum = guestfs_int_string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "swapon_device", err.error_message);
    else
      guestfs_int_error_errno (g, errnum, "%s: %s", "swapon_device",
                               err.error_message);
    free (err.error_message);
    free (err.errno_string);
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "swapon_device");
    fprintf (trace_buffer.fp, "%d", ret_v);
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  return ret_v;
}

GUESTFS_DLL_PUBLIC int
guestfs_swapon_uuid (guestfs_h *g,
                     const char *uuid)
{
  struct guestfs_swapon_uuid_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs_int_call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                      "swapon_uuid", 11);
  if (uuid == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "swapon_uuid", "uuid");
    return -1;
  }

  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "swapon_uuid");
    fprintf (trace_buffer.fp, " \"%s\"", uuid);
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  if (guestfs_int_check_appliance_up (g, "swapon_uuid") == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "swapon_uuid", "-1");
    return -1;
  }

  args.uuid = (char *) uuid;
  serial = guestfs_int_send (g, GUESTFS_PROC_SWAPON_UUID,
                             progress_hint, 0,
                             (xdrproc_t) xdr_guestfs_swapon_uuid_args, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "swapon_uuid", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs_int_recv (g, "swapon_uuid", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "swapon_uuid", "-1");
    return -1;
  }

  if (guestfs_int_check_reply_header (g, &hdr, GUESTFS_PROC_SWAPON_UUID, serial) == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "swapon_uuid", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "swapon_uuid", "-1");
    if (err.errno_string[0] != '\0')
      errnum = guestfs_int_string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "swapon_uuid", err.error_message);
    else
      guestfs_int_error_errno (g, errnum, "%s: %s", "swapon_uuid",
                               err.error_message);
    free (err.error_message);
    free (err.errno_string);
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "swapon_uuid");
    fprintf (trace_buffer.fp, "%d", ret_v);
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  return ret_v;
}

GUESTFS_DLL_PUBLIC int
guestfs_tgz_in (guestfs_h *g,
                const char *tarball,
                const char *directory)
{
  struct guestfs_tgz_in_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int ret_v;
  uint64_t progress_hint = 0;
  struct stat progress_stat;

  guestfs_int_call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                      "tgz_in", 6);
  if (tarball == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "tgz_in", "tarball");
    return -1;
  }
  if (directory == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "tgz_in", "directory");
    return -1;
  }

  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "tgz_in");
    fprintf (trace_buffer.fp, " \"%s\"", tarball);
    fprintf (trace_buffer.fp, " \"%s\"", directory);
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  if (stat (tarball, &progress_stat) == 0 &&
      S_ISREG (progress_stat.st_mode))
    progress_hint += progress_stat.st_size;

  if (guestfs_int_check_appliance_up (g, "tgz_in") == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "tgz_in", "-1");
    return -1;
  }

  args.directory = (char *) directory;
  serial = guestfs_int_send (g, GUESTFS_PROC_TGZ_IN,
                             progress_hint, 0,
                             (xdrproc_t) xdr_guestfs_tgz_in_args, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "tgz_in", "-1");
    return -1;
  }

  r = guestfs_int_send_file (g, tarball);
  if (r == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "tgz_in", "-1");
    /* daemon will send an error reply which we discard */
    guestfs_int_recv_discard (g, "tgz_in");
    return -1;
  }
  if (r == -2) /* daemon cancelled */
    goto read_reply;

 read_reply:
  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs_int_recv (g, "tgz_in", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "tgz_in", "-1");
    return -1;
  }

  if (guestfs_int_check_reply_header (g, &hdr, GUESTFS_PROC_TGZ_IN, serial) == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "tgz_in", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "tgz_in", "-1");
    if (err.errno_string[0] != '\0')
      errnum = guestfs_int_string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "tgz_in", err.error_message);
    else
      guestfs_int_error_errno (g, errnum, "%s: %s", "tgz_in",
                               err.error_message);
    free (err.error_message);
    free (err.errno_string);
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "tgz_in");
    fprintf (trace_buffer.fp, "%d", ret_v);
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  return ret_v;
}

GUESTFS_DLL_PUBLIC int
guestfs_truncate_size (guestfs_h *g,
                       const char *path,
                       int64_t size)
{
  struct guestfs_truncate_size_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs_int_call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                      "truncate_size", 13);
  if (path == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "truncate_size", "path");
    return -1;
  }

  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "truncate_size");
    fprintf (trace_buffer.fp, " \"%s\"", path);
    fprintf (trace_buffer.fp, " %" PRIi64, size);
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  if (guestfs_int_check_appliance_up (g, "truncate_size") == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "truncate_size", "-1");
    return -1;
  }

  args.path = (char *) path;
  args.size = size;
  serial = guestfs_int_send (g, GUESTFS_PROC_TRUNCATE_SIZE,
                             progress_hint, 0,
                             (xdrproc_t) xdr_guestfs_truncate_size_args, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "truncate_size", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs_int_recv (g, "truncate_size", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "truncate_size", "-1");
    return -1;
  }

  if (guestfs_int_check_reply_header (g, &hdr, GUESTFS_PROC_TRUNCATE_SIZE, serial) == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "truncate_size", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "truncate_size", "-1");
    if (err.errno_string[0] != '\0')
      errnum = guestfs_int_string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "truncate_size", err.error_message);
    else
      guestfs_int_error_errno (g, errnum, "%s: %s", "truncate_size",
                               err.error_message);
    free (err.error_message);
    free (err.errno_string);
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "truncate_size");
    fprintf (trace_buffer.fp, "%d", ret_v);
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  return ret_v;
}

GUESTFS_DLL_PUBLIC int
guestfs_txz_in (guestfs_h *g,
                const char *tarball,
                const char *directory)
{
  struct guestfs_txz_in_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int ret_v;
  uint64_t progress_hint = 0;
  struct stat progress_stat;

  guestfs_int_call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                      "txz_in", 6);
  if (tarball == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "txz_in", "tarball");
    return -1;
  }
  if (directory == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "txz_in", "directory");
    return -1;
  }

  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "txz_in");
    fprintf (trace_buffer.fp, " \"%s\"", tarball);
    fprintf (trace_buffer.fp, " \"%s\"", directory);
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  if (stat (tarball, &progress_stat) == 0 &&
      S_ISREG (progress_stat.st_mode))
    progress_hint += progress_stat.st_size;

  if (guestfs_int_check_appliance_up (g, "txz_in") == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "txz_in", "-1");
    return -1;
  }

  args.directory = (char *) directory;
  serial = guestfs_int_send (g, GUESTFS_PROC_TXZ_IN,
                             progress_hint, 0,
                             (xdrproc_t) xdr_guestfs_txz_in_args, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "txz_in", "-1");
    return -1;
  }

  r = guestfs_int_send_file (g, tarball);
  if (r == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "txz_in", "-1");
    /* daemon will send an error reply which we discard */
    guestfs_int_recv_discard (g, "txz_in");
    return -1;
  }
  if (r == -2) /* daemon cancelled */
    goto read_reply;

 read_reply:
  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs_int_recv (g, "txz_in", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "txz_in", "-1");
    return -1;
  }

  if (guestfs_int_check_reply_header (g, &hdr, GUESTFS_PROC_TXZ_IN, serial) == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "txz_in", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "txz_in", "-1");
    if (err.errno_string[0] != '\0')
      errnum = guestfs_int_string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "txz_in", err.error_message);
    else
      guestfs_int_error_errno (g, errnum, "%s: %s", "txz_in",
                               err.error_message);
    free (err.error_message);
    free (err.errno_string);
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "txz_in");
    fprintf (trace_buffer.fp, "%d", ret_v);
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  return ret_v;
}

GUESTFS_DLL_PUBLIC int
guestfs_vgchange_uuid (guestfs_h *g,
                       const char *vg)
{
  struct guestfs_vgchange_uuid_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs_int_call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                      "vgchange_uuid", 13);
  if (vg == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "vgchange_uuid", "vg");
    return -1;
  }

  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "vgchange_uuid");
    fprintf (trace_buffer.fp, " \"%s\"", vg);
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  if (guestfs_int_check_appliance_up (g, "vgchange_uuid") == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "vgchange_uuid", "-1");
    return -1;
  }

  args.vg = (char *) vg;
  serial = guestfs_int_send (g, GUESTFS_PROC_VGCHANGE_UUID,
                             progress_hint, 0,
                             (xdrproc_t) xdr_guestfs_vgchange_uuid_args, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "vgchange_uuid", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs_int_recv (g, "vgchange_uuid", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "vgchange_uuid", "-1");
    return -1;
  }

  if (guestfs_int_check_reply_header (g, &hdr, GUESTFS_PROC_VGCHANGE_UUID, serial) == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "vgchange_uuid", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "vgchange_uuid", "-1");
    if (err.errno_string[0] != '\0')
      errnum = guestfs_int_string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "vgchange_uuid", err.error_message);
    else
      guestfs_int_error_errno (g, errnum, "%s: %s", "vgchange_uuid",
                               err.error_message);
    free (err.error_message);
    free (err.errno_string);
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "vgchange_uuid");
    fprintf (trace_buffer.fp, "%d", ret_v);
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  return ret_v;
}

GUESTFS_DLL_PUBLIC char **
guestfs_vglvuuids (guestfs_h *g,
                   const char *vgname)
{
  struct guestfs_vglvuuids_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  struct guestfs_vglvuuids_ret ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  char **ret_v;
  const uint64_t progress_hint = 0;

  guestfs_int_call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                      "vglvuuids", 9);
  if (vgname == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "vglvuuids", "vgname");
    return NULL;
  }

  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "vglvuuids");
    fprintf (trace_buffer.fp, " \"%s\"", vgname);
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  if (guestfs_int_check_appliance_up (g, "vglvuuids") == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "vglvuuids", "NULL");
    return NULL;
  }

  args.vgname = (char *) vgname;
  serial = guestfs_int_send (g, GUESTFS_PROC_VGLVUUIDS,
                             progress_hint, 0,
                             (xdrproc_t) xdr_guestfs_vglvuuids_args, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "vglvuuids", "NULL");
    return NULL;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs_int_recv (g, "vglvuuids", &hdr, &err,
        (xdrproc_t) xdr_guestfs_vglvuuids_ret, (char *) &ret);
  if (r == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "vglvuuids", "NULL");
    return NULL;
  }

  if (guestfs_int_check_reply_header (g, &hdr, GUESTFS_PROC_VGLVUUIDS, serial) == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "vglvuuids", "NULL");
    return NULL;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "vglvuuids", "NULL");
    if (err.errno_string[0] != '\0')
      errnum = guestfs_int_string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "vglvuuids", err.error_message);
    else
      guestfs_int_error_errno (g, errnum, "%s: %s", "vglvuuids",
                               err.error_message);
    free (err.error_message);
    free (err.errno_string);
    return NULL;
  }

  /* caller will free this, but we need to add a NULL entry */
  ret.uuids.uuids_val =
    safe_realloc (g, ret.uuids.uuids_val,
                  sizeof (char *) * (ret.uuids.uuids_len + 1));
  ret.uuids.uuids_val[ret.uuids.uuids_len] = NULL;
  ret_v = ret.uuids.uuids_val;
  if (trace_flag) {
    size_t i;

    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "vglvuuids");
    fputs ("[", trace_buffer.fp);
    for (i = 0; ret_v[i]; ++i) {
      if (i > 0) fputs (", ", trace_buffer.fp);
      fputs ("\"", trace_buffer.fp);
      fputs (ret_v[i], trace_buffer.fp);
      fputs ("\"", trace_buffer.fp);
    }
    fputs ("]", trace_buffer.fp);
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  return ret_v;
}

GUESTFS_DLL_PUBLIC int
guestfs_vgremove (guestfs_h *g,
                  const char *vgname)
{
  struct guestfs_vgremove_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs_int_call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                      "vgremove", 8);
  if (vgname == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "vgremove", "vgname");
    return -1;
  }

  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "vgremove");
    fprintf (trace_buffer.fp, " \"%s\"", vgname);
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  if (guestfs_int_check_appliance_up (g, "vgremove") == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "vgremove", "-1");
    return -1;
  }

  args.vgname = (char *) vgname;
  serial = guestfs_int_send (g, GUESTFS_PROC_VGREMOVE,
                             progress_hint, 0,
                             (xdrproc_t) xdr_guestfs_vgremove_args, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "vgremove", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs_int_recv (g, "vgremove", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "vgremove", "-1");
    return -1;
  }

  if (guestfs_int_check_reply_header (g, &hdr, GUESTFS_PROC_VGREMOVE, serial) == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "vgremove", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "vgremove", "-1");
    if (err.errno_string[0] != '\0')
      errnum = guestfs_int_string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "vgremove", err.error_message);
    else
      guestfs_int_error_errno (g, errnum, "%s: %s", "vgremove",
                               err.error_message);
    free (err.error_message);
    free (err.errno_string);
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "vgremove");
    fprintf (trace_buffer.fp, "%d", ret_v);
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  return ret_v;
}

GUESTFS_DLL_PUBLIC int
guestfs_wc_l (guestfs_h *g,
              const char *path)
{
  struct guestfs_wc_l_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  struct guestfs_wc_l_ret ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs_int_call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                      "wc_l", 4);
  if (path == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "wc_l", "path");
    return -1;
  }

  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "wc_l");
    fprintf (trace_buffer.fp, " \"%s\"", path);
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  if (guestfs_int_check_appliance_up (g, "wc_l") == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "wc_l", "-1");
    return -1;
  }

  args.path = (char *) path;
  serial = guestfs_int_send (g, GUESTFS_PROC_WC_L,
                             progress_hint, 0,
                             (xdrproc_t) xdr_guestfs_wc_l_args, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "wc_l", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs_int_recv (g, "wc_l", &hdr, &err,
        (xdrproc_t) xdr_guestfs_wc_l_ret, (char *) &ret);
  if (r == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "wc_l", "-1");
    return -1;
  }

  if (guestfs_int_check_reply_header (g, &hdr, GUESTFS_PROC_WC_L, serial) == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "wc_l", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "wc_l", "-1");
    if (err.errno_string[0] != '\0')
      errnum = guestfs_int_string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "wc_l", err.error_message);
    else
      guestfs_int_error_errno (g, errnum, "%s: %s", "wc_l",
                               err.error_message);
    free (err.error_message);
    free (err.errno_string);
    return -1;
  }

  ret_v = ret.lines;
  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "wc_l");
    fprintf (trace_buffer.fp, "%d", ret_v);
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  return ret_v;
}

GUESTFS_DLL_PUBLIC int
guestfs_xfs_growfs_argv (guestfs_h *g,
                         const char *path,
                         const struct guestfs_xfs_growfs_argv *optargs)
{
  struct guestfs_xfs_growfs_argv optargs_null;
  if (!optargs) {
    optargs_null.bitmask = 0;
    optargs = &optargs_null;
  }

  struct guestfs_xfs_growfs_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs_int_call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                      "xfs_growfs", 10);
  if (path == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "xfs_growfs", "path");
    return -1;
  }

  if (optargs->bitmask & UINT64_C(0xffffffffffffff00)) {
    error (g, "%s: unknown option in guestfs_%s_argv->bitmask (this can happen if a program is compiled against a newer version of libguestfs, then dynamically linked to an older version)",
           "xfs_growfs", "xfs_growfs");
    return -1;
  }

  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "xfs_growfs");
    fprintf (trace_buffer.fp, " \"%s\"", path);
    if (optargs->bitmask & GUESTFS_XFS_GROWFS_DATASEC_BITMASK) {
      fprintf (trace_buffer.fp, " \"%s:%s\"", "datasec", optargs->datasec ? "true" : "false");
    }
    if (optargs->bitmask & GUESTFS_XFS_GROWFS_LOGSEC_BITMASK) {
      fprintf (trace_buffer.fp, " \"%s:%s\"", "logsec", optargs->logsec ? "true" : "false");
    }
    if (optargs->bitmask & GUESTFS_XFS_GROWFS_RTSEC_BITMASK) {
      fprintf (trace_buffer.fp, " \"%s:%s\"", "rtsec", optargs->rtsec ? "true" : "false");
    }
    if (optargs->bitmask & GUESTFS_XFS_GROWFS_DATASIZE_BITMASK) {
      fprintf (trace_buffer.fp, " \"%s:%" PRIi64 "\"", "datasize", optargs->datasize);
    }
    if (optargs->bitmask & GUESTFS_XFS_GROWFS_LOGSIZE_BITMASK) {
      fprintf (trace_buffer.fp, " \"%s:%" PRIi64 "\"", "logsize", optargs->logsize);
    }
    if (optargs->bitmask & GUESTFS_XFS_GROWFS_RTSIZE_BITMASK) {
      fprintf (trace_buffer.fp, " \"%s:%" PRIi64 "\"", "rtsize", optargs->rtsize);
    }
    if (optargs->bitmask & GUESTFS_XFS_GROWFS_RTEXTSIZE_BITMASK) {
      fprintf (trace_buffer.fp, " \"%s:%" PRIi64 "\"", "rtextsize", optargs->rtextsize);
    }
    if (optargs->bitmask & GUESTFS_XFS_GROWFS_MAXPCT_BITMASK) {
      fprintf (trace_buffer.fp, " \"%s:%d\"", "maxpct", optargs->maxpct);
    }
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  if (guestfs_int_check_appliance_up (g, "xfs_growfs") == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "xfs_growfs", "-1");
    return -1;
  }

  args.path = (char *) path;
  if (optargs->bitmask & GUESTFS_XFS_GROWFS_DATASEC_BITMASK) {
    args.datasec = optargs->datasec;
  } else {
    args.datasec = 0;
  }
  if (optargs->bitmask & GUESTFS_XFS_GROWFS_LOGSEC_BITMASK) {
    args.logsec = optargs->logsec;
  } else {
    args.logsec = 0;
  }
  if (optargs->bitmask & GUESTFS_XFS_GROWFS_RTSEC_BITMASK) {
    args.rtsec = optargs->rtsec;
  } else {
    args.rtsec = 0;
  }
  if (optargs->bitmask & GUESTFS_XFS_GROWFS_DATASIZE_BITMASK) {
    args.datasize = optargs->datasize;
  } else {
    args.datasize = 0;
  }
  if (optargs->bitmask & GUESTFS_XFS_GROWFS_LOGSIZE_BITMASK) {
    args.logsize = optargs->logsize;
  } else {
    args.logsize = 0;
  }
  if (optargs->bitmask & GUESTFS_XFS_GROWFS_RTSIZE_BITMASK) {
    args.rtsize = optargs->rtsize;
  } else {
    args.rtsize = 0;
  }
  if (optargs->bitmask & GUESTFS_XFS_GROWFS_RTEXTSIZE_BITMASK) {
    args.rtextsize = optargs->rtextsize;
  } else {
    args.rtextsize = 0;
  }
  if (optargs->bitmask & GUESTFS_XFS_GROWFS_MAXPCT_BITMASK) {
    args.maxpct = optargs->maxpct;
  } else {
    args.maxpct = 0;
  }
  serial = guestfs_int_send (g, GUESTFS_PROC_XFS_GROWFS,
                             progress_hint, optargs->bitmask,
                             (xdrproc_t) xdr_guestfs_xfs_growfs_args, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "xfs_growfs", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs_int_recv (g, "xfs_growfs", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "xfs_growfs", "-1");
    return -1;
  }

  if (guestfs_int_check_reply_header (g, &hdr, GUESTFS_PROC_XFS_GROWFS, serial) == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "xfs_growfs", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "xfs_growfs", "-1");
    if (err.errno_string[0] != '\0')
      errnum = guestfs_int_string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "xfs_growfs", err.error_message);
    else
      guestfs_int_error_errno (g, errnum, "%s: %s", "xfs_growfs",
                               err.error_message);
    free (err.error_message);
    free (err.errno_string);
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "xfs_growfs");
    fprintf (trace_buffer.fp, "%d", ret_v);
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  return ret_v;
}

GUESTFS_DLL_PUBLIC struct guestfs_xfsinfo *
guestfs_xfs_info (guestfs_h *g,
                  const char *pathordevice)
{
  struct guestfs_xfs_info_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  struct guestfs_xfs_info_ret ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  struct guestfs_xfsinfo *ret_v;
  const uint64_t progress_hint = 0;

  guestfs_int_call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                      "xfs_info", 8);
  if (pathordevice == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "xfs_info", "pathordevice");
    return NULL;
  }

  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "xfs_info");
    fprintf (trace_buffer.fp, " \"%s\"", pathordevice);
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  if (guestfs_int_check_appliance_up (g, "xfs_info") == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "xfs_info", "NULL");
    return NULL;
  }

  args.pathordevice = (char *) pathordevice;
  serial = guestfs_int_send (g, GUESTFS_PROC_XFS_INFO,
                             progress_hint, 0,
                             (xdrproc_t) xdr_guestfs_xfs_info_args, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "xfs_info", "NULL");
    return NULL;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs_int_recv (g, "xfs_info", &hdr, &err,
        (xdrproc_t) xdr_guestfs_xfs_info_ret, (char *) &ret);
  if (r == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "xfs_info", "NULL");
    return NULL;
  }

  if (guestfs_int_check_reply_header (g, &hdr, GUESTFS_PROC_XFS_INFO, serial) == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "xfs_info", "NULL");
    return NULL;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "xfs_info", "NULL");
    if (err.errno_string[0] != '\0')
      errnum = guestfs_int_string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "xfs_info", err.error_message);
    else
      guestfs_int_error_errno (g, errnum, "%s: %s", "xfs_info",
                               err.error_message);
    free (err.error_message);
    free (err.errno_string);
    return NULL;
  }

  /* caller will free this */
  ret_v = safe_memdup (g, &ret.info, sizeof (ret.info));
  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "xfs_info");
    fprintf (trace_buffer.fp, "<struct guestfs_xfsinfo = ");
    guestfs_int_print_xfsinfo_indent (ret_v, trace_buffer.fp, ", ", "");
    fprintf (trace_buffer.fp, ">");
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  return ret_v;
}

GUESTFS_DLL_PUBLIC int
guestfs_xfs_repair_argv (guestfs_h *g,
                         const char *device,
                         const struct guestfs_xfs_repair_argv *optargs)
{
  struct guestfs_xfs_repair_argv optargs_null;
  if (!optargs) {
    optargs_null.bitmask = 0;
    optargs = &optargs_null;
  }

  struct guestfs_xfs_repair_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  struct guestfs_xfs_repair_ret ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs_int_call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                      "xfs_repair", 10);
  if (device == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "xfs_repair", "device");
    return -1;
  }
  if ((optargs->bitmask & GUESTFS_XFS_REPAIR_LOGDEV_BITMASK) &&
      optargs->logdev == NULL) {
    error (g, "%s: %s: optional parameter cannot be NULL",
           "xfs_repair", "logdev");
    return -1;
  }
  if ((optargs->bitmask & GUESTFS_XFS_REPAIR_RTDEV_BITMASK) &&
      optargs->rtdev == NULL) {
    error (g, "%s: %s: optional parameter cannot be NULL",
           "xfs_repair", "rtdev");
    return -1;
  }

  if (optargs->bitmask & UINT64_C(0xfffffffffffffc00)) {
    error (g, "%s: unknown option in guestfs_%s_argv->bitmask (this can happen if a program is compiled against a newer version of libguestfs, then dynamically linked to an older version)",
           "xfs_repair", "xfs_repair");
    return -1;
  }

  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "xfs_repair");
    fprintf (trace_buffer.fp, " \"%s\"", device);
    if (optargs->bitmask & GUESTFS_XFS_REPAIR_FORCELOGZERO_BITMASK) {
      fprintf (trace_buffer.fp, " \"%s:%s\"", "forcelogzero", optargs->forcelogzero ? "true" : "false");
    }
    if (optargs->bitmask & GUESTFS_XFS_REPAIR_NOMODIFY_BITMASK) {
      fprintf (trace_buffer.fp, " \"%s:%s\"", "nomodify", optargs->nomodify ? "true" : "false");
    }
    if (optargs->bitmask & GUESTFS_XFS_REPAIR_NOPREFETCH_BITMASK) {
      fprintf (trace_buffer.fp, " \"%s:%s\"", "noprefetch", optargs->noprefetch ? "true" : "false");
    }
    if (optargs->bitmask & GUESTFS_XFS_REPAIR_FORCEGEOMETRY_BITMASK) {
      fprintf (trace_buffer.fp, " \"%s:%s\"", "forcegeometry", optargs->forcegeometry ? "true" : "false");
    }
    if (optargs->bitmask & GUESTFS_XFS_REPAIR_MAXMEM_BITMASK) {
      fprintf (trace_buffer.fp, " \"%s:%" PRIi64 "\"", "maxmem", optargs->maxmem);
    }
    if (optargs->bitmask & GUESTFS_XFS_REPAIR_IHASHSIZE_BITMASK) {
      fprintf (trace_buffer.fp, " \"%s:%" PRIi64 "\"", "ihashsize", optargs->ihashsize);
    }
    if (optargs->bitmask & GUESTFS_XFS_REPAIR_BHASHSIZE_BITMASK) {
      fprintf (trace_buffer.fp, " \"%s:%" PRIi64 "\"", "bhashsize", optargs->bhashsize);
    }
    if (optargs->bitmask & GUESTFS_XFS_REPAIR_AGSTRIDE_BITMASK) {
      fprintf (trace_buffer.fp, " \"%s:%" PRIi64 "\"", "agstride", optargs->agstride);
    }
    if (optargs->bitmask & GUESTFS_XFS_REPAIR_LOGDEV_BITMASK) {
      fprintf (trace_buffer.fp, " \"%s:%s\"", "logdev", optargs->logdev);
    }
    if (optargs->bitmask & GUESTFS_XFS_REPAIR_RTDEV_BITMASK) {
      fprintf (trace_buffer.fp, " \"%s:%s\"", "rtdev", optargs->rtdev);
    }
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  if (guestfs_int_check_appliance_up (g, "xfs_repair") == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "xfs_repair", "-1");
    return -1;
  }

  args.device = (char *) device;
  if (optargs->bitmask & GUESTFS_XFS_REPAIR_FORCELOGZERO_BITMASK) {
    args.forcelogzero = optargs->forcelogzero;
  } else {
    args.forcelogzero = 0;
  }
  if (optargs->bitmask & GUESTFS_XFS_REPAIR_NOMODIFY_BITMASK) {
    args.nomodify = optargs->nomodify;
  } else {
    args.nomodify = 0;
  }
  if (optargs->bitmask & GUESTFS_XFS_REPAIR_NOPREFETCH_BITMASK) {
    args.noprefetch = optargs->noprefetch;
  } else {
    args.noprefetch = 0;
  }
  if (optargs->bitmask & GUESTFS_XFS_REPAIR_FORCEGEOMETRY_BITMASK) {
    args.forcegeometry = optargs->forcegeometry;
  } else {
    args.forcegeometry = 0;
  }
  if (optargs->bitmask & GUESTFS_XFS_REPAIR_MAXMEM_BITMASK) {
    args.maxmem = optargs->maxmem;
  } else {
    args.maxmem = 0;
  }
  if (optargs->bitmask & GUESTFS_XFS_REPAIR_IHASHSIZE_BITMASK) {
    args.ihashsize = optargs->ihashsize;
  } else {
    args.ihashsize = 0;
  }
  if (optargs->bitmask & GUESTFS_XFS_REPAIR_BHASHSIZE_BITMASK) {
    args.bhashsize = optargs->bhashsize;
  } else {
    args.bhashsize = 0;
  }
  if (optargs->bitmask & GUESTFS_XFS_REPAIR_AGSTRIDE_BITMASK) {
    args.agstride = optargs->agstride;
  } else {
    args.agstride = 0;
  }
  if (optargs->bitmask & GUESTFS_XFS_REPAIR_LOGDEV_BITMASK) {
    args.logdev = (char *) optargs->logdev;
  } else {
    args.logdev = (char *) "";
  }
  if (optargs->bitmask & GUESTFS_XFS_REPAIR_RTDEV_BITMASK) {
    args.rtdev = (char *) optargs->rtdev;
  } else {
    args.rtdev = (char *) "";
  }
  serial = guestfs_int_send (g, GUESTFS_PROC_XFS_REPAIR,
                             progress_hint, optargs->bitmask,
                             (xdrproc_t) xdr_guestfs_xfs_repair_args, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "xfs_repair", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs_int_recv (g, "xfs_repair", &hdr, &err,
        (xdrproc_t) xdr_guestfs_xfs_repair_ret, (char *) &ret);
  if (r == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "xfs_repair", "-1");
    return -1;
  }

  if (guestfs_int_check_reply_header (g, &hdr, GUESTFS_PROC_XFS_REPAIR, serial) == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "xfs_repair", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "xfs_repair", "-1");
    if (err.errno_string[0] != '\0')
      errnum = guestfs_int_string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "xfs_repair", err.error_message);
    else
      guestfs_int_error_errno (g, errnum, "%s: %s", "xfs_repair",
                               err.error_message);
    free (err.error_message);
    free (err.errno_string);
    return -1;
  }

  ret_v = ret.status;
  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "xfs_repair");
    fprintf (trace_buffer.fp, "%d", ret_v);
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  return ret_v;
}

GUESTFS_DLL_PUBLIC int
guestfs_zero_device (guestfs_h *g,
                     const char *device)
{
  struct guestfs_zero_device_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs_int_call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                      "zero_device", 11);
  if (device == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "zero_device", "device");
    return -1;
  }

  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "zero_device");
    fprintf (trace_buffer.fp, " \"%s\"", device);
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  if (guestfs_int_check_appliance_up (g, "zero_device") == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "zero_device", "-1");
    return -1;
  }

  args.device = (char *) device;
  serial = guestfs_int_send (g, GUESTFS_PROC_ZERO_DEVICE,
                             progress_hint, 0,
                             (xdrproc_t) xdr_guestfs_zero_device_args, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "zero_device", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs_int_recv (g, "zero_device", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "zero_device", "-1");
    return -1;
  }

  if (guestfs_int_check_reply_header (g, &hdr, GUESTFS_PROC_ZERO_DEVICE, serial) == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "zero_device", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "zero_device", "-1");
    if (err.errno_string[0] != '\0')
      errnum = guestfs_int_string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "zero_device", err.error_message);
    else
      guestfs_int_error_errno (g, errnum, "%s: %s", "zero_device",
                               err.error_message);
    free (err.error_message);
    free (err.errno_string);
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "zero_device");
    fprintf (trace_buffer.fp, "%d", ret_v);
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  return ret_v;
}

GUESTFS_DLL_PUBLIC int
guestfs_zero_free_space (guestfs_h *g,
                         const char *directory)
{
  struct guestfs_zero_free_space_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs_int_call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                      "zero_free_space", 15);
  if (directory == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "zero_free_space", "directory");
    return -1;
  }

  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "zero_free_space");
    fprintf (trace_buffer.fp, " \"%s\"", directory);
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  if (guestfs_int_check_appliance_up (g, "zero_free_space") == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "zero_free_space", "-1");
    return -1;
  }

  args.directory = (char *) directory;
  serial = guestfs_int_send (g, GUESTFS_PROC_ZERO_FREE_SPACE,
                             progress_hint, 0,
                             (xdrproc_t) xdr_guestfs_zero_free_space_args, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "zero_free_space", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs_int_recv (g, "zero_free_space", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "zero_free_space", "-1");
    return -1;
  }

  if (guestfs_int_check_reply_header (g, &hdr, GUESTFS_PROC_ZERO_FREE_SPACE, serial) == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "zero_free_space", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "zero_free_space", "-1");
    if (err.errno_string[0] != '\0')
      errnum = guestfs_int_string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "zero_free_space", err.error_message);
    else
      guestfs_int_error_errno (g, errnum, "%s: %s", "zero_free_space",
                               err.error_message);
    free (err.error_message);
    free (err.errno_string);
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "zero_free_space");
    fprintf (trace_buffer.fp, "%d", ret_v);
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  return ret_v;
}

