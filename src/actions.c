/* libguestfs generated file
 * WARNING: THIS FILE IS GENERATED FROM:
 *   generator/generator_*.ml
 * ANY CHANGES YOU MAKE TO THIS FILE WILL BE LOST.
 *
 * Copyright (C) 2009-2011 Red Hat Inc.
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
#include <stdint.h>
#include <string.h>
#include <inttypes.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <assert.h>

#include "guestfs.h"
#include "guestfs-internal.h"
#include "guestfs-internal-actions.h"
#include "guestfs_protocol.h"
#include "errnostring.h"

/* Check the return message from a call for validity. */
static int
check_reply_header (guestfs_h *g,
                    const struct guestfs_message_header *hdr,
                    unsigned int proc_nr, unsigned int serial)
{
  if (hdr->prog != GUESTFS_PROGRAM) {
    error (g, "wrong program (%d/%d)", hdr->prog, GUESTFS_PROGRAM);
    return -1;
  }
  if (hdr->vers != GUESTFS_PROTOCOL_VERSION) {
    error (g, "wrong protocol version (%d/%d)",
           hdr->vers, GUESTFS_PROTOCOL_VERSION);
    return -1;
  }
  if (hdr->direction != GUESTFS_DIRECTION_REPLY) {
    error (g, "unexpected message direction (%d/%d)",
           hdr->direction, GUESTFS_DIRECTION_REPLY);
    return -1;
  }
  if (hdr->proc != proc_nr) {
    error (g, "unexpected procedure number (%d/%d)", hdr->proc, proc_nr);
    return -1;
  }
  if (hdr->serial != serial) {
    error (g, "unexpected serial (%d/%d)", hdr->serial, serial);
    return -1;
  }

  return 0;
}

/* Check we are in the right state to run a high-level action. */
static int
check_state (guestfs_h *g, const char *caller)
{
  if (!guestfs__is_ready (g)) {
    if (guestfs__is_config (g) || guestfs__is_launching (g))
      error (g, "%s: call launch before using this function\n(in guestfish, don't forget to use the 'run' command)",
        caller);
    else
      error (g, "%s called from the wrong state, %d != READY",
        caller, guestfs__get_state (g));
    return -1;
  }
  return 0;
}

/* Convenience wrapper for tracing. */
static FILE *
trace_open (guestfs_h *g)
{
  assert (g->trace_fp == NULL);
  g->trace_buf = NULL;
  g->trace_len = 0;
  g->trace_fp = open_memstream (&g->trace_buf, &g->trace_len);
  if (g->trace_fp)
    return g->trace_fp;
  else
    return stderr;
}

static void
trace_send_line (guestfs_h *g)
{
  char *buf;
  size_t len;

  if (g->trace_fp) {
    fclose (g->trace_fp);
    g->trace_fp = NULL;

    /* The callback might invoke other libguestfs calls, so keep
     * a copy of the pointer to the buffer and length.
     */
    buf = g->trace_buf;
    len = g->trace_len;
    g->trace_buf = NULL;
    guestfs___call_callbacks_message (g, GUESTFS_EVENT_TRACE, buf, len);

    free (buf);
  }
}

int
guestfs_test0 (guestfs_h *g,
               const char *str,
               const char *optstr,
               char *const *strlist,
               int b,
               int integer,
               int64_t integer64,
               const char *filein,
               const char *fileout,
               const char *bufferin,
               size_t bufferin_size)
{
  int trace_flag = g->trace;
  FILE *trace_fp;
  int r;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "test0", 5);
  if (str == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "test0", "str");
    return -1;
  }
  if (strlist == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "test0", "strlist");
    return -1;
  }
  if (filein == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "test0", "filein");
    return -1;
  }
  if (fileout == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "test0", "fileout");
    return -1;
  }
  if (bufferin == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "test0", "bufferin");
    return -1;
  }

  if (trace_flag) {
    size_t i;

    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "test0");
    fprintf (trace_fp, " \"%s\"", str);
    if (optstr) fprintf (trace_fp, " \"%s\"", optstr);
    else fprintf (trace_fp, " null");
    fputc (' ', trace_fp);
    fputc ('"', trace_fp);
    for (i = 0; strlist[i]; ++i) {
      if (i > 0) fputc (' ', trace_fp);
      fputs (strlist[i], trace_fp);
    }
    fputc ('"', trace_fp);
    fputs (b ? " true" : " false", trace_fp);
    fprintf (trace_fp, " %d", integer);
    fprintf (trace_fp, " %" PRIi64, integer64);
    fprintf (trace_fp, " \"%s\"", filein);
    fprintf (trace_fp, " \"%s\"", fileout);
    fputc (' ', trace_fp);
    guestfs___print_BufferIn (trace_fp, bufferin, bufferin_size);
    trace_send_line (g);
  }

  r = guestfs__test0 (g, str, optstr, strlist, b, integer, integer64, filein, fileout, bufferin, bufferin_size);

  if (r != -1) {
    if (trace_flag) {
      trace_fp = trace_open (g);
      fprintf (trace_fp, "%s = ", "test0");
      fprintf (trace_fp, "%d", r);
      trace_send_line (g);
    }

  } else {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "test0", "-1");
  }

  return r;
}

int
guestfs_test0rint (guestfs_h *g,
                   const char *val)
{
  int trace_flag = g->trace;
  FILE *trace_fp;
  int r;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "test0rint", 9);
  if (val == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "test0rint", "val");
    return -1;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "test0rint");
    fprintf (trace_fp, " \"%s\"", val);
    trace_send_line (g);
  }

  r = guestfs__test0rint (g, val);

  if (r != -1) {
    if (trace_flag) {
      trace_fp = trace_open (g);
      fprintf (trace_fp, "%s = ", "test0rint");
      fprintf (trace_fp, "%d", r);
      trace_send_line (g);
    }

  } else {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "test0rint", "-1");
  }

  return r;
}

int
guestfs_test0rinterr (guestfs_h *g)
{
  int trace_flag = g->trace;
  FILE *trace_fp;
  int r;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "test0rinterr", 12);
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "test0rinterr");
    trace_send_line (g);
  }

  r = guestfs__test0rinterr (g);

  if (r != -1) {
    if (trace_flag) {
      trace_fp = trace_open (g);
      fprintf (trace_fp, "%s = ", "test0rinterr");
      fprintf (trace_fp, "%d", r);
      trace_send_line (g);
    }

  } else {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "test0rinterr", "-1");
  }

  return r;
}

int64_t
guestfs_test0rint64 (guestfs_h *g,
                     const char *val)
{
  int trace_flag = g->trace;
  FILE *trace_fp;
  int64_t r;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "test0rint64", 11);
  if (val == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "test0rint64", "val");
    return -1;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "test0rint64");
    fprintf (trace_fp, " \"%s\"", val);
    trace_send_line (g);
  }

  r = guestfs__test0rint64 (g, val);

  if (r != -1) {
    if (trace_flag) {
      trace_fp = trace_open (g);
      fprintf (trace_fp, "%s = ", "test0rint64");
      fprintf (trace_fp, "%" PRIi64, r);
      trace_send_line (g);
    }

  } else {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "test0rint64", "-1");
  }

  return r;
}

int64_t
guestfs_test0rint64err (guestfs_h *g)
{
  int trace_flag = g->trace;
  FILE *trace_fp;
  int64_t r;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "test0rint64err", 14);
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "test0rint64err");
    trace_send_line (g);
  }

  r = guestfs__test0rint64err (g);

  if (r != -1) {
    if (trace_flag) {
      trace_fp = trace_open (g);
      fprintf (trace_fp, "%s = ", "test0rint64err");
      fprintf (trace_fp, "%" PRIi64, r);
      trace_send_line (g);
    }

  } else {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "test0rint64err", "-1");
  }

  return r;
}

int
guestfs_test0rbool (guestfs_h *g,
                    const char *val)
{
  int trace_flag = g->trace;
  FILE *trace_fp;
  int r;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "test0rbool", 10);
  if (val == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "test0rbool", "val");
    return -1;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "test0rbool");
    fprintf (trace_fp, " \"%s\"", val);
    trace_send_line (g);
  }

  r = guestfs__test0rbool (g, val);

  if (r != -1) {
    if (trace_flag) {
      trace_fp = trace_open (g);
      fprintf (trace_fp, "%s = ", "test0rbool");
      fprintf (trace_fp, "%d", r);
      trace_send_line (g);
    }

  } else {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "test0rbool", "-1");
  }

  return r;
}

int
guestfs_test0rboolerr (guestfs_h *g)
{
  int trace_flag = g->trace;
  FILE *trace_fp;
  int r;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "test0rboolerr", 13);
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "test0rboolerr");
    trace_send_line (g);
  }

  r = guestfs__test0rboolerr (g);

  if (r != -1) {
    if (trace_flag) {
      trace_fp = trace_open (g);
      fprintf (trace_fp, "%s = ", "test0rboolerr");
      fprintf (trace_fp, "%d", r);
      trace_send_line (g);
    }

  } else {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "test0rboolerr", "-1");
  }

  return r;
}

const char *
guestfs_test0rconststring (guestfs_h *g,
                           const char *val)
{
  int trace_flag = g->trace;
  FILE *trace_fp;
  const char *r;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "test0rconststring", 17);
  if (val == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "test0rconststring", "val");
    return NULL;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "test0rconststring");
    fprintf (trace_fp, " \"%s\"", val);
    trace_send_line (g);
  }

  r = guestfs__test0rconststring (g, val);

  if (r != NULL) {
    if (trace_flag) {
      trace_fp = trace_open (g);
      fprintf (trace_fp, "%s = ", "test0rconststring");
      fprintf (trace_fp, "\"%s\"", r);
      trace_send_line (g);
    }

  } else {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "test0rconststring", "NULL");
  }

  return r;
}

const char *
guestfs_test0rconststringerr (guestfs_h *g)
{
  int trace_flag = g->trace;
  FILE *trace_fp;
  const char *r;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "test0rconststringerr", 20);
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "test0rconststringerr");
    trace_send_line (g);
  }

  r = guestfs__test0rconststringerr (g);

  if (r != NULL) {
    if (trace_flag) {
      trace_fp = trace_open (g);
      fprintf (trace_fp, "%s = ", "test0rconststringerr");
      fprintf (trace_fp, "\"%s\"", r);
      trace_send_line (g);
    }

  } else {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "test0rconststringerr", "NULL");
  }

  return r;
}

const char *
guestfs_test0rconstoptstring (guestfs_h *g,
                              const char *val)
{
  int trace_flag = g->trace;
  FILE *trace_fp;
  const char *r;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "test0rconstoptstring", 20);
  if (val == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "test0rconstoptstring", "val");
    return NULL;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "test0rconstoptstring");
    fprintf (trace_fp, " \"%s\"", val);
    trace_send_line (g);
  }

  r = guestfs__test0rconstoptstring (g, val);

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "test0rconstoptstring");
    fprintf (trace_fp, "\"%s\"", r != NULL ? r : "NULL");
    trace_send_line (g);
  }


  return r;
}

const char *
guestfs_test0rconstoptstringerr (guestfs_h *g)
{
  int trace_flag = g->trace;
  FILE *trace_fp;
  const char *r;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "test0rconstoptstringerr", 23);
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "test0rconstoptstringerr");
    trace_send_line (g);
  }

  r = guestfs__test0rconstoptstringerr (g);

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "test0rconstoptstringerr");
    fprintf (trace_fp, "\"%s\"", r != NULL ? r : "NULL");
    trace_send_line (g);
  }


  return r;
}

char *
guestfs_test0rstring (guestfs_h *g,
                      const char *val)
{
  int trace_flag = g->trace;
  FILE *trace_fp;
  char *r;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "test0rstring", 12);
  if (val == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "test0rstring", "val");
    return NULL;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "test0rstring");
    fprintf (trace_fp, " \"%s\"", val);
    trace_send_line (g);
  }

  r = guestfs__test0rstring (g, val);

  if (r != NULL) {
    if (trace_flag) {
      trace_fp = trace_open (g);
      fprintf (trace_fp, "%s = ", "test0rstring");
      fprintf (trace_fp, "\"%s\"", r);
      trace_send_line (g);
    }

  } else {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "test0rstring", "NULL");
  }

  return r;
}

char *
guestfs_test0rstringerr (guestfs_h *g)
{
  int trace_flag = g->trace;
  FILE *trace_fp;
  char *r;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "test0rstringerr", 15);
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "test0rstringerr");
    trace_send_line (g);
  }

  r = guestfs__test0rstringerr (g);

  if (r != NULL) {
    if (trace_flag) {
      trace_fp = trace_open (g);
      fprintf (trace_fp, "%s = ", "test0rstringerr");
      fprintf (trace_fp, "\"%s\"", r);
      trace_send_line (g);
    }

  } else {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "test0rstringerr", "NULL");
  }

  return r;
}

char **
guestfs_test0rstringlist (guestfs_h *g,
                          const char *val)
{
  int trace_flag = g->trace;
  FILE *trace_fp;
  char **r;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "test0rstringlist", 16);
  if (val == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "test0rstringlist", "val");
    return NULL;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "test0rstringlist");
    fprintf (trace_fp, " \"%s\"", val);
    trace_send_line (g);
  }

  r = guestfs__test0rstringlist (g, val);

  if (r != NULL) {
    if (trace_flag) {
      size_t i;

      trace_fp = trace_open (g);
      fprintf (trace_fp, "%s = ", "test0rstringlist");
      fputs ("[", trace_fp);
      for (i = 0; r[i]; ++i) {
        if (i > 0) fputs (", ", trace_fp);
        fputs ("\"", trace_fp);
        fputs (r[i], trace_fp);
        fputs ("\"", trace_fp);
      }
      fputs ("]", trace_fp);
      trace_send_line (g);
    }

  } else {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "test0rstringlist", "NULL");
  }

  return r;
}

char **
guestfs_test0rstringlisterr (guestfs_h *g)
{
  int trace_flag = g->trace;
  FILE *trace_fp;
  char **r;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "test0rstringlisterr", 19);
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "test0rstringlisterr");
    trace_send_line (g);
  }

  r = guestfs__test0rstringlisterr (g);

  if (r != NULL) {
    if (trace_flag) {
      size_t i;

      trace_fp = trace_open (g);
      fprintf (trace_fp, "%s = ", "test0rstringlisterr");
      fputs ("[", trace_fp);
      for (i = 0; r[i]; ++i) {
        if (i > 0) fputs (", ", trace_fp);
        fputs ("\"", trace_fp);
        fputs (r[i], trace_fp);
        fputs ("\"", trace_fp);
      }
      fputs ("]", trace_fp);
      trace_send_line (g);
    }

  } else {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "test0rstringlisterr", "NULL");
  }

  return r;
}

struct guestfs_lvm_pv *
guestfs_test0rstruct (guestfs_h *g,
                      const char *val)
{
  int trace_flag = g->trace;
  FILE *trace_fp;
  struct guestfs_lvm_pv *r;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "test0rstruct", 12);
  if (val == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "test0rstruct", "val");
    return NULL;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "test0rstruct");
    fprintf (trace_fp, " \"%s\"", val);
    trace_send_line (g);
  }

  r = guestfs__test0rstruct (g, val);

  if (r != NULL) {
    if (trace_flag) {
      trace_fp = trace_open (g);
      fprintf (trace_fp, "%s = ", "test0rstruct");
      fprintf (trace_fp, "<struct guestfs_lvm_pv *>");
      trace_send_line (g);
    }

  } else {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "test0rstruct", "NULL");
  }

  return r;
}

struct guestfs_lvm_pv *
guestfs_test0rstructerr (guestfs_h *g)
{
  int trace_flag = g->trace;
  FILE *trace_fp;
  struct guestfs_lvm_pv *r;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "test0rstructerr", 15);
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "test0rstructerr");
    trace_send_line (g);
  }

  r = guestfs__test0rstructerr (g);

  if (r != NULL) {
    if (trace_flag) {
      trace_fp = trace_open (g);
      fprintf (trace_fp, "%s = ", "test0rstructerr");
      fprintf (trace_fp, "<struct guestfs_lvm_pv *>");
      trace_send_line (g);
    }

  } else {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "test0rstructerr", "NULL");
  }

  return r;
}

struct guestfs_lvm_pv_list *
guestfs_test0rstructlist (guestfs_h *g,
                          const char *val)
{
  int trace_flag = g->trace;
  FILE *trace_fp;
  struct guestfs_lvm_pv_list *r;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "test0rstructlist", 16);
  if (val == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "test0rstructlist", "val");
    return NULL;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "test0rstructlist");
    fprintf (trace_fp, " \"%s\"", val);
    trace_send_line (g);
  }

  r = guestfs__test0rstructlist (g, val);

  if (r != NULL) {
    if (trace_flag) {
      trace_fp = trace_open (g);
      fprintf (trace_fp, "%s = ", "test0rstructlist");
      fprintf (trace_fp, "<struct guestfs_lvm_pv_list *>");
      trace_send_line (g);
    }

  } else {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "test0rstructlist", "NULL");
  }

  return r;
}

struct guestfs_lvm_pv_list *
guestfs_test0rstructlisterr (guestfs_h *g)
{
  int trace_flag = g->trace;
  FILE *trace_fp;
  struct guestfs_lvm_pv_list *r;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "test0rstructlisterr", 19);
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "test0rstructlisterr");
    trace_send_line (g);
  }

  r = guestfs__test0rstructlisterr (g);

  if (r != NULL) {
    if (trace_flag) {
      trace_fp = trace_open (g);
      fprintf (trace_fp, "%s = ", "test0rstructlisterr");
      fprintf (trace_fp, "<struct guestfs_lvm_pv_list *>");
      trace_send_line (g);
    }

  } else {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "test0rstructlisterr", "NULL");
  }

  return r;
}

char **
guestfs_test0rhashtable (guestfs_h *g,
                         const char *val)
{
  int trace_flag = g->trace;
  FILE *trace_fp;
  char **r;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "test0rhashtable", 15);
  if (val == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "test0rhashtable", "val");
    return NULL;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "test0rhashtable");
    fprintf (trace_fp, " \"%s\"", val);
    trace_send_line (g);
  }

  r = guestfs__test0rhashtable (g, val);

  if (r != NULL) {
    if (trace_flag) {
      size_t i;

      trace_fp = trace_open (g);
      fprintf (trace_fp, "%s = ", "test0rhashtable");
      fputs ("[", trace_fp);
      for (i = 0; r[i]; ++i) {
        if (i > 0) fputs (", ", trace_fp);
        fputs ("\"", trace_fp);
        fputs (r[i], trace_fp);
        fputs ("\"", trace_fp);
      }
      fputs ("]", trace_fp);
      trace_send_line (g);
    }

  } else {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "test0rhashtable", "NULL");
  }

  return r;
}

char **
guestfs_test0rhashtableerr (guestfs_h *g)
{
  int trace_flag = g->trace;
  FILE *trace_fp;
  char **r;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "test0rhashtableerr", 18);
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "test0rhashtableerr");
    trace_send_line (g);
  }

  r = guestfs__test0rhashtableerr (g);

  if (r != NULL) {
    if (trace_flag) {
      size_t i;

      trace_fp = trace_open (g);
      fprintf (trace_fp, "%s = ", "test0rhashtableerr");
      fputs ("[", trace_fp);
      for (i = 0; r[i]; ++i) {
        if (i > 0) fputs (", ", trace_fp);
        fputs ("\"", trace_fp);
        fputs (r[i], trace_fp);
        fputs ("\"", trace_fp);
      }
      fputs ("]", trace_fp);
      trace_send_line (g);
    }

  } else {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "test0rhashtableerr", "NULL");
  }

  return r;
}

int
guestfs_launch (guestfs_h *g)
{
  int trace_flag = g->trace;
  FILE *trace_fp;
  int r;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "launch", 6);
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "launch");
    trace_send_line (g);
  }

  r = guestfs__launch (g);

  if (r != -1) {
    if (trace_flag) {
      trace_fp = trace_open (g);
      fprintf (trace_fp, "%s = ", "launch");
      fprintf (trace_fp, "%d", r);
      trace_send_line (g);
    }

  } else {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "launch", "-1");
  }

  return r;
}

int
guestfs_wait_ready (guestfs_h *g)
{
  int trace_flag = g->trace;
  FILE *trace_fp;
  int r;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "wait_ready", 10);
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "wait_ready");
    trace_send_line (g);
  }

  r = guestfs__wait_ready (g);

  if (r != -1) {
    if (trace_flag) {
      trace_fp = trace_open (g);
      fprintf (trace_fp, "%s = ", "wait_ready");
      fprintf (trace_fp, "%d", r);
      trace_send_line (g);
    }

  } else {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "wait_ready", "-1");
  }

  return r;
}

int
guestfs_kill_subprocess (guestfs_h *g)
{
  int trace_flag = g->trace;
  FILE *trace_fp;
  int r;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "kill_subprocess", 15);
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "kill_subprocess");
    trace_send_line (g);
  }

  r = guestfs__kill_subprocess (g);

  if (r != -1) {
    if (trace_flag) {
      trace_fp = trace_open (g);
      fprintf (trace_fp, "%s = ", "kill_subprocess");
      fprintf (trace_fp, "%d", r);
      trace_send_line (g);
    }

  } else {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "kill_subprocess", "-1");
  }

  return r;
}

int
guestfs_add_drive (guestfs_h *g,
                   const char *filename)
{
  int trace_flag = g->trace;
  FILE *trace_fp;
  int r;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "add_drive", 9);
  if (filename == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "add_drive", "filename");
    return -1;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "add_drive");
    fprintf (trace_fp, " \"%s\"", filename);
    trace_send_line (g);
  }

  r = guestfs__add_drive (g, filename);

  if (r != -1) {
    if (trace_flag) {
      trace_fp = trace_open (g);
      fprintf (trace_fp, "%s = ", "add_drive");
      fprintf (trace_fp, "%d", r);
      trace_send_line (g);
    }

  } else {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "add_drive", "-1");
  }

  return r;
}

int
guestfs_add_cdrom (guestfs_h *g,
                   const char *filename)
{
  int trace_flag = g->trace;
  FILE *trace_fp;
  int r;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "add_cdrom", 9);
  if (filename == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "add_cdrom", "filename");
    return -1;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "add_cdrom");
    fprintf (trace_fp, " \"%s\"", filename);
    trace_send_line (g);
  }

  r = guestfs__add_cdrom (g, filename);

  if (r != -1) {
    if (trace_flag) {
      trace_fp = trace_open (g);
      fprintf (trace_fp, "%s = ", "add_cdrom");
      fprintf (trace_fp, "%d", r);
      trace_send_line (g);
    }

  } else {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "add_cdrom", "-1");
  }

  return r;
}

int
guestfs_add_drive_ro (guestfs_h *g,
                      const char *filename)
{
  int trace_flag = g->trace;
  FILE *trace_fp;
  int r;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "add_drive_ro", 12);
  if (filename == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "add_drive_ro", "filename");
    return -1;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "add_drive_ro");
    fprintf (trace_fp, " \"%s\"", filename);
    trace_send_line (g);
  }

  r = guestfs__add_drive_ro (g, filename);

  if (r != -1) {
    if (trace_flag) {
      trace_fp = trace_open (g);
      fprintf (trace_fp, "%s = ", "add_drive_ro");
      fprintf (trace_fp, "%d", r);
      trace_send_line (g);
    }

  } else {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "add_drive_ro", "-1");
  }

  return r;
}

int
guestfs_config (guestfs_h *g,
                const char *qemuparam,
                const char *qemuvalue)
{
  int trace_flag = g->trace;
  FILE *trace_fp;
  int r;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "config", 6);
  if (qemuparam == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "config", "qemuparam");
    return -1;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "config");
    fprintf (trace_fp, " \"%s\"", qemuparam);
    if (qemuvalue) fprintf (trace_fp, " \"%s\"", qemuvalue);
    else fprintf (trace_fp, " null");
    trace_send_line (g);
  }

  r = guestfs__config (g, qemuparam, qemuvalue);

  if (r != -1) {
    if (trace_flag) {
      trace_fp = trace_open (g);
      fprintf (trace_fp, "%s = ", "config");
      fprintf (trace_fp, "%d", r);
      trace_send_line (g);
    }

  } else {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "config", "-1");
  }

  return r;
}

int
guestfs_set_qemu (guestfs_h *g,
                  const char *qemu)
{
  int trace_flag = g->trace;
  FILE *trace_fp;
  int r;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "set_qemu", 8);
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "set_qemu");
    if (qemu) fprintf (trace_fp, " \"%s\"", qemu);
    else fprintf (trace_fp, " null");
    trace_send_line (g);
  }

  r = guestfs__set_qemu (g, qemu);

  if (r != -1) {
    if (trace_flag) {
      trace_fp = trace_open (g);
      fprintf (trace_fp, "%s = ", "set_qemu");
      fprintf (trace_fp, "%d", r);
      trace_send_line (g);
    }

  } else {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "set_qemu", "-1");
  }

  return r;
}

const char *
guestfs_get_qemu (guestfs_h *g)
{
  int trace_flag = g->trace;
  FILE *trace_fp;
  const char *r;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "get_qemu", 8);
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "get_qemu");
    trace_send_line (g);
  }

  r = guestfs__get_qemu (g);

  if (r != NULL) {
    if (trace_flag) {
      trace_fp = trace_open (g);
      fprintf (trace_fp, "%s = ", "get_qemu");
      fprintf (trace_fp, "\"%s\"", r);
      trace_send_line (g);
    }

  } else {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "get_qemu", "NULL");
  }

  return r;
}

int
guestfs_set_path (guestfs_h *g,
                  const char *searchpath)
{
  int trace_flag = g->trace;
  FILE *trace_fp;
  int r;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "set_path", 8);
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "set_path");
    if (searchpath) fprintf (trace_fp, " \"%s\"", searchpath);
    else fprintf (trace_fp, " null");
    trace_send_line (g);
  }

  r = guestfs__set_path (g, searchpath);

  if (r != -1) {
    if (trace_flag) {
      trace_fp = trace_open (g);
      fprintf (trace_fp, "%s = ", "set_path");
      fprintf (trace_fp, "%d", r);
      trace_send_line (g);
    }

  } else {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "set_path", "-1");
  }

  return r;
}

const char *
guestfs_get_path (guestfs_h *g)
{
  int trace_flag = g->trace;
  FILE *trace_fp;
  const char *r;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "get_path", 8);
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "get_path");
    trace_send_line (g);
  }

  r = guestfs__get_path (g);

  if (r != NULL) {
    if (trace_flag) {
      trace_fp = trace_open (g);
      fprintf (trace_fp, "%s = ", "get_path");
      fprintf (trace_fp, "\"%s\"", r);
      trace_send_line (g);
    }

  } else {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "get_path", "NULL");
  }

  return r;
}

int
guestfs_set_append (guestfs_h *g,
                    const char *append)
{
  int trace_flag = g->trace;
  FILE *trace_fp;
  int r;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "set_append", 10);
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "set_append");
    if (append) fprintf (trace_fp, " \"%s\"", append);
    else fprintf (trace_fp, " null");
    trace_send_line (g);
  }

  r = guestfs__set_append (g, append);

  if (r != -1) {
    if (trace_flag) {
      trace_fp = trace_open (g);
      fprintf (trace_fp, "%s = ", "set_append");
      fprintf (trace_fp, "%d", r);
      trace_send_line (g);
    }

  } else {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "set_append", "-1");
  }

  return r;
}

const char *
guestfs_get_append (guestfs_h *g)
{
  int trace_flag = g->trace;
  FILE *trace_fp;
  const char *r;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "get_append", 10);
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "get_append");
    trace_send_line (g);
  }

  r = guestfs__get_append (g);

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "get_append");
    fprintf (trace_fp, "\"%s\"", r != NULL ? r : "NULL");
    trace_send_line (g);
  }


  return r;
}

int
guestfs_set_autosync (guestfs_h *g,
                      int autosync)
{
  int trace_flag = g->trace;
  FILE *trace_fp;
  int r;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "set_autosync", 12);
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "set_autosync");
    fputs (autosync ? " true" : " false", trace_fp);
    trace_send_line (g);
  }

  r = guestfs__set_autosync (g, autosync);

  if (r != -1) {
    if (trace_flag) {
      trace_fp = trace_open (g);
      fprintf (trace_fp, "%s = ", "set_autosync");
      fprintf (trace_fp, "%d", r);
      trace_send_line (g);
    }

  } else {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "set_autosync", "-1");
  }

  return r;
}

int
guestfs_get_autosync (guestfs_h *g)
{
  int trace_flag = g->trace;
  FILE *trace_fp;
  int r;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "get_autosync", 12);
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "get_autosync");
    trace_send_line (g);
  }

  r = guestfs__get_autosync (g);

  if (r != -1) {
    if (trace_flag) {
      trace_fp = trace_open (g);
      fprintf (trace_fp, "%s = ", "get_autosync");
      fprintf (trace_fp, "%d", r);
      trace_send_line (g);
    }

  } else {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "get_autosync", "-1");
  }

  return r;
}

int
guestfs_set_verbose (guestfs_h *g,
                     int verbose)
{
  int trace_flag = g->trace;
  FILE *trace_fp;
  int r;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "set_verbose", 11);
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "set_verbose");
    fputs (verbose ? " true" : " false", trace_fp);
    trace_send_line (g);
  }

  r = guestfs__set_verbose (g, verbose);

  if (r != -1) {
    if (trace_flag) {
      trace_fp = trace_open (g);
      fprintf (trace_fp, "%s = ", "set_verbose");
      fprintf (trace_fp, "%d", r);
      trace_send_line (g);
    }

  } else {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "set_verbose", "-1");
  }

  return r;
}

int
guestfs_get_verbose (guestfs_h *g)
{
  int trace_flag = g->trace;
  FILE *trace_fp;
  int r;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "get_verbose", 11);
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "get_verbose");
    trace_send_line (g);
  }

  r = guestfs__get_verbose (g);

  if (r != -1) {
    if (trace_flag) {
      trace_fp = trace_open (g);
      fprintf (trace_fp, "%s = ", "get_verbose");
      fprintf (trace_fp, "%d", r);
      trace_send_line (g);
    }

  } else {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "get_verbose", "-1");
  }

  return r;
}

int
guestfs_is_ready (guestfs_h *g)
{
  int trace_flag = g->trace;
  FILE *trace_fp;
  int r;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "is_ready", 8);
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "is_ready");
    trace_send_line (g);
  }

  r = guestfs__is_ready (g);

  if (r != -1) {
    if (trace_flag) {
      trace_fp = trace_open (g);
      fprintf (trace_fp, "%s = ", "is_ready");
      fprintf (trace_fp, "%d", r);
      trace_send_line (g);
    }

  } else {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "is_ready", "-1");
  }

  return r;
}

int
guestfs_is_config (guestfs_h *g)
{
  int trace_flag = g->trace;
  FILE *trace_fp;
  int r;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "is_config", 9);
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "is_config");
    trace_send_line (g);
  }

  r = guestfs__is_config (g);

  if (r != -1) {
    if (trace_flag) {
      trace_fp = trace_open (g);
      fprintf (trace_fp, "%s = ", "is_config");
      fprintf (trace_fp, "%d", r);
      trace_send_line (g);
    }

  } else {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "is_config", "-1");
  }

  return r;
}

int
guestfs_is_launching (guestfs_h *g)
{
  int trace_flag = g->trace;
  FILE *trace_fp;
  int r;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "is_launching", 12);
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "is_launching");
    trace_send_line (g);
  }

  r = guestfs__is_launching (g);

  if (r != -1) {
    if (trace_flag) {
      trace_fp = trace_open (g);
      fprintf (trace_fp, "%s = ", "is_launching");
      fprintf (trace_fp, "%d", r);
      trace_send_line (g);
    }

  } else {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "is_launching", "-1");
  }

  return r;
}

int
guestfs_is_busy (guestfs_h *g)
{
  int trace_flag = g->trace;
  FILE *trace_fp;
  int r;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "is_busy", 7);
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "is_busy");
    trace_send_line (g);
  }

  r = guestfs__is_busy (g);

  if (r != -1) {
    if (trace_flag) {
      trace_fp = trace_open (g);
      fprintf (trace_fp, "%s = ", "is_busy");
      fprintf (trace_fp, "%d", r);
      trace_send_line (g);
    }

  } else {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "is_busy", "-1");
  }

  return r;
}

int
guestfs_get_state (guestfs_h *g)
{
  int trace_flag = g->trace;
  FILE *trace_fp;
  int r;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "get_state", 9);
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "get_state");
    trace_send_line (g);
  }

  r = guestfs__get_state (g);

  if (r != -1) {
    if (trace_flag) {
      trace_fp = trace_open (g);
      fprintf (trace_fp, "%s = ", "get_state");
      fprintf (trace_fp, "%d", r);
      trace_send_line (g);
    }

  } else {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "get_state", "-1");
  }

  return r;
}

int
guestfs_set_memsize (guestfs_h *g,
                     int memsize)
{
  int trace_flag = g->trace;
  FILE *trace_fp;
  int r;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "set_memsize", 11);
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "set_memsize");
    fprintf (trace_fp, " %d", memsize);
    trace_send_line (g);
  }

  r = guestfs__set_memsize (g, memsize);

  if (r != -1) {
    if (trace_flag) {
      trace_fp = trace_open (g);
      fprintf (trace_fp, "%s = ", "set_memsize");
      fprintf (trace_fp, "%d", r);
      trace_send_line (g);
    }

  } else {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "set_memsize", "-1");
  }

  return r;
}

int
guestfs_get_memsize (guestfs_h *g)
{
  int trace_flag = g->trace;
  FILE *trace_fp;
  int r;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "get_memsize", 11);
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "get_memsize");
    trace_send_line (g);
  }

  r = guestfs__get_memsize (g);

  if (r != -1) {
    if (trace_flag) {
      trace_fp = trace_open (g);
      fprintf (trace_fp, "%s = ", "get_memsize");
      fprintf (trace_fp, "%d", r);
      trace_send_line (g);
    }

  } else {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "get_memsize", "-1");
  }

  return r;
}

int
guestfs_get_pid (guestfs_h *g)
{
  int trace_flag = g->trace;
  FILE *trace_fp;
  int r;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "get_pid", 7);
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "get_pid");
    trace_send_line (g);
  }

  r = guestfs__get_pid (g);

  if (r != -1) {
    if (trace_flag) {
      trace_fp = trace_open (g);
      fprintf (trace_fp, "%s = ", "get_pid");
      fprintf (trace_fp, "%d", r);
      trace_send_line (g);
    }

  } else {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "get_pid", "-1");
  }

  return r;
}

struct guestfs_version *
guestfs_version (guestfs_h *g)
{
  int trace_flag = g->trace;
  FILE *trace_fp;
  struct guestfs_version *r;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "version", 7);
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "version");
    trace_send_line (g);
  }

  r = guestfs__version (g);

  if (r != NULL) {
    if (trace_flag) {
      trace_fp = trace_open (g);
      fprintf (trace_fp, "%s = ", "version");
      fprintf (trace_fp, "<struct guestfs_version *>");
      trace_send_line (g);
    }

  } else {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "version", "NULL");
  }

  return r;
}

int
guestfs_set_selinux (guestfs_h *g,
                     int selinux)
{
  int trace_flag = g->trace;
  FILE *trace_fp;
  int r;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "set_selinux", 11);
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "set_selinux");
    fputs (selinux ? " true" : " false", trace_fp);
    trace_send_line (g);
  }

  r = guestfs__set_selinux (g, selinux);

  if (r != -1) {
    if (trace_flag) {
      trace_fp = trace_open (g);
      fprintf (trace_fp, "%s = ", "set_selinux");
      fprintf (trace_fp, "%d", r);
      trace_send_line (g);
    }

  } else {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "set_selinux", "-1");
  }

  return r;
}

int
guestfs_get_selinux (guestfs_h *g)
{
  int trace_flag = g->trace;
  FILE *trace_fp;
  int r;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "get_selinux", 11);
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "get_selinux");
    trace_send_line (g);
  }

  r = guestfs__get_selinux (g);

  if (r != -1) {
    if (trace_flag) {
      trace_fp = trace_open (g);
      fprintf (trace_fp, "%s = ", "get_selinux");
      fprintf (trace_fp, "%d", r);
      trace_send_line (g);
    }

  } else {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "get_selinux", "-1");
  }

  return r;
}

int
guestfs_set_trace (guestfs_h *g,
                   int trace)
{
  int trace_flag = g->trace;
  FILE *trace_fp;
  int r;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "set_trace", 9);
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "set_trace");
    fputs (trace ? " true" : " false", trace_fp);
    trace_send_line (g);
  }

  r = guestfs__set_trace (g, trace);

  if (r != -1) {
    if (trace_flag) {
      trace_fp = trace_open (g);
      fprintf (trace_fp, "%s = ", "set_trace");
      fprintf (trace_fp, "%d", r);
      trace_send_line (g);
    }

  } else {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "set_trace", "-1");
  }

  return r;
}

int
guestfs_get_trace (guestfs_h *g)
{
  int trace_flag = g->trace;
  FILE *trace_fp;
  int r;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "get_trace", 9);
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "get_trace");
    trace_send_line (g);
  }

  r = guestfs__get_trace (g);

  if (r != -1) {
    if (trace_flag) {
      trace_fp = trace_open (g);
      fprintf (trace_fp, "%s = ", "get_trace");
      fprintf (trace_fp, "%d", r);
      trace_send_line (g);
    }

  } else {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "get_trace", "-1");
  }

  return r;
}

int
guestfs_set_direct (guestfs_h *g,
                    int direct)
{
  int trace_flag = g->trace;
  FILE *trace_fp;
  int r;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "set_direct", 10);
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "set_direct");
    fputs (direct ? " true" : " false", trace_fp);
    trace_send_line (g);
  }

  r = guestfs__set_direct (g, direct);

  if (r != -1) {
    if (trace_flag) {
      trace_fp = trace_open (g);
      fprintf (trace_fp, "%s = ", "set_direct");
      fprintf (trace_fp, "%d", r);
      trace_send_line (g);
    }

  } else {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "set_direct", "-1");
  }

  return r;
}

int
guestfs_get_direct (guestfs_h *g)
{
  int trace_flag = g->trace;
  FILE *trace_fp;
  int r;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "get_direct", 10);
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "get_direct");
    trace_send_line (g);
  }

  r = guestfs__get_direct (g);

  if (r != -1) {
    if (trace_flag) {
      trace_fp = trace_open (g);
      fprintf (trace_fp, "%s = ", "get_direct");
      fprintf (trace_fp, "%d", r);
      trace_send_line (g);
    }

  } else {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "get_direct", "-1");
  }

  return r;
}

int
guestfs_set_recovery_proc (guestfs_h *g,
                           int recoveryproc)
{
  int trace_flag = g->trace;
  FILE *trace_fp;
  int r;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "set_recovery_proc", 17);
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "set_recovery_proc");
    fputs (recoveryproc ? " true" : " false", trace_fp);
    trace_send_line (g);
  }

  r = guestfs__set_recovery_proc (g, recoveryproc);

  if (r != -1) {
    if (trace_flag) {
      trace_fp = trace_open (g);
      fprintf (trace_fp, "%s = ", "set_recovery_proc");
      fprintf (trace_fp, "%d", r);
      trace_send_line (g);
    }

  } else {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "set_recovery_proc", "-1");
  }

  return r;
}

int
guestfs_get_recovery_proc (guestfs_h *g)
{
  int trace_flag = g->trace;
  FILE *trace_fp;
  int r;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "get_recovery_proc", 17);
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "get_recovery_proc");
    trace_send_line (g);
  }

  r = guestfs__get_recovery_proc (g);

  if (r != -1) {
    if (trace_flag) {
      trace_fp = trace_open (g);
      fprintf (trace_fp, "%s = ", "get_recovery_proc");
      fprintf (trace_fp, "%d", r);
      trace_send_line (g);
    }

  } else {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "get_recovery_proc", "-1");
  }

  return r;
}

int
guestfs_add_drive_with_if (guestfs_h *g,
                           const char *filename,
                           const char *iface)
{
  int trace_flag = g->trace;
  FILE *trace_fp;
  int r;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
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
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "add_drive_with_if");
    fprintf (trace_fp, " \"%s\"", filename);
    fprintf (trace_fp, " \"%s\"", iface);
    trace_send_line (g);
  }

  r = guestfs__add_drive_with_if (g, filename, iface);

  if (r != -1) {
    if (trace_flag) {
      trace_fp = trace_open (g);
      fprintf (trace_fp, "%s = ", "add_drive_with_if");
      fprintf (trace_fp, "%d", r);
      trace_send_line (g);
    }

  } else {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "add_drive_with_if", "-1");
  }

  return r;
}

int
guestfs_add_drive_ro_with_if (guestfs_h *g,
                              const char *filename,
                              const char *iface)
{
  int trace_flag = g->trace;
  FILE *trace_fp;
  int r;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "add_drive_ro_with_if", 20);
  if (filename == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "add_drive_ro_with_if", "filename");
    return -1;
  }
  if (iface == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "add_drive_ro_with_if", "iface");
    return -1;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "add_drive_ro_with_if");
    fprintf (trace_fp, " \"%s\"", filename);
    fprintf (trace_fp, " \"%s\"", iface);
    trace_send_line (g);
  }

  r = guestfs__add_drive_ro_with_if (g, filename, iface);

  if (r != -1) {
    if (trace_flag) {
      trace_fp = trace_open (g);
      fprintf (trace_fp, "%s = ", "add_drive_ro_with_if");
      fprintf (trace_fp, "%d", r);
      trace_send_line (g);
    }

  } else {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "add_drive_ro_with_if", "-1");
  }

  return r;
}

char *
guestfs_file_architecture (guestfs_h *g,
                           const char *filename)
{
  int trace_flag = g->trace;
  FILE *trace_fp;
  char *r;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "file_architecture", 17);
  if (filename == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "file_architecture", "filename");
    return NULL;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "file_architecture");
    fprintf (trace_fp, " \"%s\"", filename);
    trace_send_line (g);
  }

  r = guestfs__file_architecture (g, filename);

  if (r != NULL) {
    if (trace_flag) {
      trace_fp = trace_open (g);
      fprintf (trace_fp, "%s = ", "file_architecture");
      fprintf (trace_fp, "\"%s\"", r);
      trace_send_line (g);
    }

  } else {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "file_architecture", "NULL");
  }

  return r;
}

char **
guestfs_inspect_os (guestfs_h *g)
{
  int trace_flag = g->trace;
  FILE *trace_fp;
  char **r;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "inspect_os", 10);
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "inspect_os");
    trace_send_line (g);
  }

  r = guestfs__inspect_os (g);

  if (r != NULL) {
    if (trace_flag) {
      size_t i;

      trace_fp = trace_open (g);
      fprintf (trace_fp, "%s = ", "inspect_os");
      fputs ("[", trace_fp);
      for (i = 0; r[i]; ++i) {
        if (i > 0) fputs (", ", trace_fp);
        fputs ("\"", trace_fp);
        fputs (r[i], trace_fp);
        fputs ("\"", trace_fp);
      }
      fputs ("]", trace_fp);
      trace_send_line (g);
    }

  } else {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "inspect_os", "NULL");
  }

  return r;
}

char *
guestfs_inspect_get_type (guestfs_h *g,
                          const char *root)
{
  int trace_flag = g->trace;
  FILE *trace_fp;
  char *r;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "inspect_get_type", 16);
  if (root == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "inspect_get_type", "root");
    return NULL;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "inspect_get_type");
    fprintf (trace_fp, " \"%s\"", root);
    trace_send_line (g);
  }

  r = guestfs__inspect_get_type (g, root);

  if (r != NULL) {
    if (trace_flag) {
      trace_fp = trace_open (g);
      fprintf (trace_fp, "%s = ", "inspect_get_type");
      fprintf (trace_fp, "\"%s\"", r);
      trace_send_line (g);
    }

  } else {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "inspect_get_type", "NULL");
  }

  return r;
}

char *
guestfs_inspect_get_arch (guestfs_h *g,
                          const char *root)
{
  int trace_flag = g->trace;
  FILE *trace_fp;
  char *r;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "inspect_get_arch", 16);
  if (root == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "inspect_get_arch", "root");
    return NULL;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "inspect_get_arch");
    fprintf (trace_fp, " \"%s\"", root);
    trace_send_line (g);
  }

  r = guestfs__inspect_get_arch (g, root);

  if (r != NULL) {
    if (trace_flag) {
      trace_fp = trace_open (g);
      fprintf (trace_fp, "%s = ", "inspect_get_arch");
      fprintf (trace_fp, "\"%s\"", r);
      trace_send_line (g);
    }

  } else {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "inspect_get_arch", "NULL");
  }

  return r;
}

char *
guestfs_inspect_get_distro (guestfs_h *g,
                            const char *root)
{
  int trace_flag = g->trace;
  FILE *trace_fp;
  char *r;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "inspect_get_distro", 18);
  if (root == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "inspect_get_distro", "root");
    return NULL;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "inspect_get_distro");
    fprintf (trace_fp, " \"%s\"", root);
    trace_send_line (g);
  }

  r = guestfs__inspect_get_distro (g, root);

  if (r != NULL) {
    if (trace_flag) {
      trace_fp = trace_open (g);
      fprintf (trace_fp, "%s = ", "inspect_get_distro");
      fprintf (trace_fp, "\"%s\"", r);
      trace_send_line (g);
    }

  } else {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "inspect_get_distro", "NULL");
  }

  return r;
}

int
guestfs_inspect_get_major_version (guestfs_h *g,
                                   const char *root)
{
  int trace_flag = g->trace;
  FILE *trace_fp;
  int r;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "inspect_get_major_version", 25);
  if (root == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "inspect_get_major_version", "root");
    return -1;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "inspect_get_major_version");
    fprintf (trace_fp, " \"%s\"", root);
    trace_send_line (g);
  }

  r = guestfs__inspect_get_major_version (g, root);

  if (r != -1) {
    if (trace_flag) {
      trace_fp = trace_open (g);
      fprintf (trace_fp, "%s = ", "inspect_get_major_version");
      fprintf (trace_fp, "%d", r);
      trace_send_line (g);
    }

  } else {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "inspect_get_major_version", "-1");
  }

  return r;
}

int
guestfs_inspect_get_minor_version (guestfs_h *g,
                                   const char *root)
{
  int trace_flag = g->trace;
  FILE *trace_fp;
  int r;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "inspect_get_minor_version", 25);
  if (root == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "inspect_get_minor_version", "root");
    return -1;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "inspect_get_minor_version");
    fprintf (trace_fp, " \"%s\"", root);
    trace_send_line (g);
  }

  r = guestfs__inspect_get_minor_version (g, root);

  if (r != -1) {
    if (trace_flag) {
      trace_fp = trace_open (g);
      fprintf (trace_fp, "%s = ", "inspect_get_minor_version");
      fprintf (trace_fp, "%d", r);
      trace_send_line (g);
    }

  } else {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "inspect_get_minor_version", "-1");
  }

  return r;
}

char *
guestfs_inspect_get_product_name (guestfs_h *g,
                                  const char *root)
{
  int trace_flag = g->trace;
  FILE *trace_fp;
  char *r;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "inspect_get_product_name", 24);
  if (root == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "inspect_get_product_name", "root");
    return NULL;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "inspect_get_product_name");
    fprintf (trace_fp, " \"%s\"", root);
    trace_send_line (g);
  }

  r = guestfs__inspect_get_product_name (g, root);

  if (r != NULL) {
    if (trace_flag) {
      trace_fp = trace_open (g);
      fprintf (trace_fp, "%s = ", "inspect_get_product_name");
      fprintf (trace_fp, "\"%s\"", r);
      trace_send_line (g);
    }

  } else {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "inspect_get_product_name", "NULL");
  }

  return r;
}

char **
guestfs_inspect_get_mountpoints (guestfs_h *g,
                                 const char *root)
{
  int trace_flag = g->trace;
  FILE *trace_fp;
  char **r;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "inspect_get_mountpoints", 23);
  if (root == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "inspect_get_mountpoints", "root");
    return NULL;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "inspect_get_mountpoints");
    fprintf (trace_fp, " \"%s\"", root);
    trace_send_line (g);
  }

  r = guestfs__inspect_get_mountpoints (g, root);

  if (r != NULL) {
    if (trace_flag) {
      size_t i;

      trace_fp = trace_open (g);
      fprintf (trace_fp, "%s = ", "inspect_get_mountpoints");
      fputs ("[", trace_fp);
      for (i = 0; r[i]; ++i) {
        if (i > 0) fputs (", ", trace_fp);
        fputs ("\"", trace_fp);
        fputs (r[i], trace_fp);
        fputs ("\"", trace_fp);
      }
      fputs ("]", trace_fp);
      trace_send_line (g);
    }

  } else {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "inspect_get_mountpoints", "NULL");
  }

  return r;
}

char **
guestfs_inspect_get_filesystems (guestfs_h *g,
                                 const char *root)
{
  int trace_flag = g->trace;
  FILE *trace_fp;
  char **r;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "inspect_get_filesystems", 23);
  if (root == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "inspect_get_filesystems", "root");
    return NULL;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "inspect_get_filesystems");
    fprintf (trace_fp, " \"%s\"", root);
    trace_send_line (g);
  }

  r = guestfs__inspect_get_filesystems (g, root);

  if (r != NULL) {
    if (trace_flag) {
      size_t i;

      trace_fp = trace_open (g);
      fprintf (trace_fp, "%s = ", "inspect_get_filesystems");
      fputs ("[", trace_fp);
      for (i = 0; r[i]; ++i) {
        if (i > 0) fputs (", ", trace_fp);
        fputs ("\"", trace_fp);
        fputs (r[i], trace_fp);
        fputs ("\"", trace_fp);
      }
      fputs ("]", trace_fp);
      trace_send_line (g);
    }

  } else {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "inspect_get_filesystems", "NULL");
  }

  return r;
}

int
guestfs_set_network (guestfs_h *g,
                     int network)
{
  int trace_flag = g->trace;
  FILE *trace_fp;
  int r;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "set_network", 11);
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "set_network");
    fputs (network ? " true" : " false", trace_fp);
    trace_send_line (g);
  }

  r = guestfs__set_network (g, network);

  if (r != -1) {
    if (trace_flag) {
      trace_fp = trace_open (g);
      fprintf (trace_fp, "%s = ", "set_network");
      fprintf (trace_fp, "%d", r);
      trace_send_line (g);
    }

  } else {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "set_network", "-1");
  }

  return r;
}

int
guestfs_get_network (guestfs_h *g)
{
  int trace_flag = g->trace;
  FILE *trace_fp;
  int r;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "get_network", 11);
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "get_network");
    trace_send_line (g);
  }

  r = guestfs__get_network (g);

  if (r != -1) {
    if (trace_flag) {
      trace_fp = trace_open (g);
      fprintf (trace_fp, "%s = ", "get_network");
      fprintf (trace_fp, "%d", r);
      trace_send_line (g);
    }

  } else {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "get_network", "-1");
  }

  return r;
}

char **
guestfs_list_filesystems (guestfs_h *g)
{
  int trace_flag = g->trace;
  FILE *trace_fp;
  char **r;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "list_filesystems", 16);
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "list_filesystems");
    trace_send_line (g);
  }

  r = guestfs__list_filesystems (g);

  if (r != NULL) {
    if (trace_flag) {
      size_t i;

      trace_fp = trace_open (g);
      fprintf (trace_fp, "%s = ", "list_filesystems");
      fputs ("[", trace_fp);
      for (i = 0; r[i]; ++i) {
        if (i > 0) fputs (", ", trace_fp);
        fputs ("\"", trace_fp);
        fputs (r[i], trace_fp);
        fputs ("\"", trace_fp);
      }
      fputs ("]", trace_fp);
      trace_send_line (g);
    }

  } else {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "list_filesystems", "NULL");
  }

  return r;
}

int
guestfs_add_drive_opts_argv (guestfs_h *g,
                             const char *filename,
                             const struct guestfs_add_drive_opts_argv *optargs)
{
  int trace_flag = g->trace;
  FILE *trace_fp;
  int r;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "add_drive_opts", 14);
  if (filename == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "add_drive_opts", "filename");
    return -1;
  }
  if ((optargs->bitmask & GUESTFS_ADD_DRIVE_OPTS_FORMAT_BITMASK) &&
      optargs->format == NULL) {
    error (g, "%s: %s: optional parameter cannot be NULL",
           "add_drive_opts", "format");
    return -1;
  }
  if ((optargs->bitmask & GUESTFS_ADD_DRIVE_OPTS_IFACE_BITMASK) &&
      optargs->iface == NULL) {
    error (g, "%s: %s: optional parameter cannot be NULL",
           "add_drive_opts", "iface");
    return -1;
  }
  if ((optargs->bitmask & GUESTFS_ADD_DRIVE_OPTS_NAME_BITMASK) &&
      optargs->name == NULL) {
    error (g, "%s: %s: optional parameter cannot be NULL",
           "add_drive_opts", "name");
    return -1;
  }

  if (optargs->bitmask & UINT64_C(0xfffffffffffffff0)) {
    error (g, "%s: unknown option in guestfs_%s_argv->bitmask (this can happen if a program is compiled against a newer version of libguestfs, then dynamically linked to an older version)",
           "add_drive_opts", "add_drive_opts");
    return -1;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "add_drive_opts");
    fprintf (trace_fp, " \"%s\"", filename);
    if (optargs->bitmask & GUESTFS_ADD_DRIVE_OPTS_READONLY_BITMASK)
      fprintf (trace_fp, " \"%s:%s\"", "readonly", optargs->readonly ? "true" : "false");
    if (optargs->bitmask & GUESTFS_ADD_DRIVE_OPTS_FORMAT_BITMASK)
      fprintf (trace_fp, " \"%s:%s\"", "format", optargs->format);
    if (optargs->bitmask & GUESTFS_ADD_DRIVE_OPTS_IFACE_BITMASK)
      fprintf (trace_fp, " \"%s:%s\"", "iface", optargs->iface);
    if (optargs->bitmask & GUESTFS_ADD_DRIVE_OPTS_NAME_BITMASK)
      fprintf (trace_fp, " \"%s:%s\"", "name", optargs->name);
    trace_send_line (g);
  }

  r = guestfs__add_drive_opts (g, filename, optargs);

  if (r != -1) {
    if (trace_flag) {
      trace_fp = trace_open (g);
      fprintf (trace_fp, "%s = ", "add_drive_opts");
      fprintf (trace_fp, "%d", r);
      trace_send_line (g);
    }

  } else {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "add_drive_opts", "-1");
  }

  return r;
}

char *
guestfs_inspect_get_windows_systemroot (guestfs_h *g,
                                        const char *root)
{
  int trace_flag = g->trace;
  FILE *trace_fp;
  char *r;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "inspect_get_windows_systemroot", 30);
  if (root == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "inspect_get_windows_systemroot", "root");
    return NULL;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "inspect_get_windows_systemroot");
    fprintf (trace_fp, " \"%s\"", root);
    trace_send_line (g);
  }

  r = guestfs__inspect_get_windows_systemroot (g, root);

  if (r != NULL) {
    if (trace_flag) {
      trace_fp = trace_open (g);
      fprintf (trace_fp, "%s = ", "inspect_get_windows_systemroot");
      fprintf (trace_fp, "\"%s\"", r);
      trace_send_line (g);
    }

  } else {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "inspect_get_windows_systemroot", "NULL");
  }

  return r;
}

char **
guestfs_inspect_get_roots (guestfs_h *g)
{
  int trace_flag = g->trace;
  FILE *trace_fp;
  char **r;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "inspect_get_roots", 17);
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "inspect_get_roots");
    trace_send_line (g);
  }

  r = guestfs__inspect_get_roots (g);

  if (r != NULL) {
    if (trace_flag) {
      size_t i;

      trace_fp = trace_open (g);
      fprintf (trace_fp, "%s = ", "inspect_get_roots");
      fputs ("[", trace_fp);
      for (i = 0; r[i]; ++i) {
        if (i > 0) fputs (", ", trace_fp);
        fputs ("\"", trace_fp);
        fputs (r[i], trace_fp);
        fputs ("\"", trace_fp);
      }
      fputs ("]", trace_fp);
      trace_send_line (g);
    }

  } else {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "inspect_get_roots", "NULL");
  }

  return r;
}

char **
guestfs_debug_cmdline (guestfs_h *g)
{
  int trace_flag = g->trace;
  FILE *trace_fp;
  char **r;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "debug_cmdline", 13);
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "debug_cmdline");
    trace_send_line (g);
  }

  r = guestfs__debug_cmdline (g);

  if (r != NULL) {
    if (trace_flag) {
      size_t i;

      trace_fp = trace_open (g);
      fprintf (trace_fp, "%s = ", "debug_cmdline");
      fputs ("[", trace_fp);
      for (i = 0; r[i]; ++i) {
        if (i > 0) fputs (", ", trace_fp);
        fputs ("\"", trace_fp);
        fputs (r[i], trace_fp);
        fputs ("\"", trace_fp);
      }
      fputs ("]", trace_fp);
      trace_send_line (g);
    }

  } else {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "debug_cmdline", "NULL");
  }

  return r;
}

char **
guestfs_debug_drives (guestfs_h *g)
{
  int trace_flag = g->trace;
  FILE *trace_fp;
  char **r;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "debug_drives", 12);
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "debug_drives");
    trace_send_line (g);
  }

  r = guestfs__debug_drives (g);

  if (r != NULL) {
    if (trace_flag) {
      size_t i;

      trace_fp = trace_open (g);
      fprintf (trace_fp, "%s = ", "debug_drives");
      fputs ("[", trace_fp);
      for (i = 0; r[i]; ++i) {
        if (i > 0) fputs (", ", trace_fp);
        fputs ("\"", trace_fp);
        fputs (r[i], trace_fp);
        fputs ("\"", trace_fp);
      }
      fputs ("]", trace_fp);
      trace_send_line (g);
    }

  } else {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "debug_drives", "NULL");
  }

  return r;
}

int
guestfs_add_domain_argv (guestfs_h *g,
                         const char *dom,
                         const struct guestfs_add_domain_argv *optargs)
{
  int trace_flag = g->trace;
  FILE *trace_fp;
  int r;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "add_domain", 10);
  if (dom == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "add_domain", "dom");
    return -1;
  }
  if ((optargs->bitmask & GUESTFS_ADD_DOMAIN_LIBVIRTURI_BITMASK) &&
      optargs->libvirturi == NULL) {
    error (g, "%s: %s: optional parameter cannot be NULL",
           "add_domain", "libvirturi");
    return -1;
  }
  if ((optargs->bitmask & GUESTFS_ADD_DOMAIN_IFACE_BITMASK) &&
      optargs->iface == NULL) {
    error (g, "%s: %s: optional parameter cannot be NULL",
           "add_domain", "iface");
    return -1;
  }
  if ((optargs->bitmask & GUESTFS_ADD_DOMAIN_READONLYDISK_BITMASK) &&
      optargs->readonlydisk == NULL) {
    error (g, "%s: %s: optional parameter cannot be NULL",
           "add_domain", "readonlydisk");
    return -1;
  }

  if (optargs->bitmask & UINT64_C(0xffffffffffffffc0)) {
    error (g, "%s: unknown option in guestfs_%s_argv->bitmask (this can happen if a program is compiled against a newer version of libguestfs, then dynamically linked to an older version)",
           "add_domain", "add_domain");
    return -1;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "add_domain");
    fprintf (trace_fp, " \"%s\"", dom);
    if (optargs->bitmask & GUESTFS_ADD_DOMAIN_LIBVIRTURI_BITMASK)
      fprintf (trace_fp, " \"%s:%s\"", "libvirturi", optargs->libvirturi);
    if (optargs->bitmask & GUESTFS_ADD_DOMAIN_READONLY_BITMASK)
      fprintf (trace_fp, " \"%s:%s\"", "readonly", optargs->readonly ? "true" : "false");
    if (optargs->bitmask & GUESTFS_ADD_DOMAIN_IFACE_BITMASK)
      fprintf (trace_fp, " \"%s:%s\"", "iface", optargs->iface);
    if (optargs->bitmask & GUESTFS_ADD_DOMAIN_LIVE_BITMASK)
      fprintf (trace_fp, " \"%s:%s\"", "live", optargs->live ? "true" : "false");
    if (optargs->bitmask & GUESTFS_ADD_DOMAIN_ALLOWUUID_BITMASK)
      fprintf (trace_fp, " \"%s:%s\"", "allowuuid", optargs->allowuuid ? "true" : "false");
    if (optargs->bitmask & GUESTFS_ADD_DOMAIN_READONLYDISK_BITMASK)
      fprintf (trace_fp, " \"%s:%s\"", "readonlydisk", optargs->readonlydisk);
    trace_send_line (g);
  }

  r = guestfs__add_domain (g, dom, optargs);

  if (r != -1) {
    if (trace_flag) {
      trace_fp = trace_open (g);
      fprintf (trace_fp, "%s = ", "add_domain");
      fprintf (trace_fp, "%d", r);
      trace_send_line (g);
    }

  } else {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "add_domain", "-1");
  }

  return r;
}

char *
guestfs_inspect_get_package_format (guestfs_h *g,
                                    const char *root)
{
  int trace_flag = g->trace;
  FILE *trace_fp;
  char *r;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "inspect_get_package_format", 26);
  if (root == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "inspect_get_package_format", "root");
    return NULL;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "inspect_get_package_format");
    fprintf (trace_fp, " \"%s\"", root);
    trace_send_line (g);
  }

  r = guestfs__inspect_get_package_format (g, root);

  if (r != NULL) {
    if (trace_flag) {
      trace_fp = trace_open (g);
      fprintf (trace_fp, "%s = ", "inspect_get_package_format");
      fprintf (trace_fp, "\"%s\"", r);
      trace_send_line (g);
    }

  } else {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "inspect_get_package_format", "NULL");
  }

  return r;
}

char *
guestfs_inspect_get_package_management (guestfs_h *g,
                                        const char *root)
{
  int trace_flag = g->trace;
  FILE *trace_fp;
  char *r;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "inspect_get_package_management", 30);
  if (root == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "inspect_get_package_management", "root");
    return NULL;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "inspect_get_package_management");
    fprintf (trace_fp, " \"%s\"", root);
    trace_send_line (g);
  }

  r = guestfs__inspect_get_package_management (g, root);

  if (r != NULL) {
    if (trace_flag) {
      trace_fp = trace_open (g);
      fprintf (trace_fp, "%s = ", "inspect_get_package_management");
      fprintf (trace_fp, "\"%s\"", r);
      trace_send_line (g);
    }

  } else {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "inspect_get_package_management", "NULL");
  }

  return r;
}

struct guestfs_application_list *
guestfs_inspect_list_applications (guestfs_h *g,
                                   const char *root)
{
  int trace_flag = g->trace;
  FILE *trace_fp;
  struct guestfs_application_list *r;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "inspect_list_applications", 25);
  if (root == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "inspect_list_applications", "root");
    return NULL;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "inspect_list_applications");
    fprintf (trace_fp, " \"%s\"", root);
    trace_send_line (g);
  }

  r = guestfs__inspect_list_applications (g, root);

  if (r != NULL) {
    if (trace_flag) {
      trace_fp = trace_open (g);
      fprintf (trace_fp, "%s = ", "inspect_list_applications");
      fprintf (trace_fp, "<struct guestfs_application_list *>");
      trace_send_line (g);
    }

  } else {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "inspect_list_applications", "NULL");
  }

  return r;
}

char *
guestfs_inspect_get_hostname (guestfs_h *g,
                              const char *root)
{
  int trace_flag = g->trace;
  FILE *trace_fp;
  char *r;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "inspect_get_hostname", 20);
  if (root == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "inspect_get_hostname", "root");
    return NULL;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "inspect_get_hostname");
    fprintf (trace_fp, " \"%s\"", root);
    trace_send_line (g);
  }

  r = guestfs__inspect_get_hostname (g, root);

  if (r != NULL) {
    if (trace_flag) {
      trace_fp = trace_open (g);
      fprintf (trace_fp, "%s = ", "inspect_get_hostname");
      fprintf (trace_fp, "\"%s\"", r);
      trace_send_line (g);
    }

  } else {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "inspect_get_hostname", "NULL");
  }

  return r;
}

char *
guestfs_inspect_get_format (guestfs_h *g,
                            const char *root)
{
  int trace_flag = g->trace;
  FILE *trace_fp;
  char *r;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "inspect_get_format", 18);
  if (root == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "inspect_get_format", "root");
    return NULL;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "inspect_get_format");
    fprintf (trace_fp, " \"%s\"", root);
    trace_send_line (g);
  }

  r = guestfs__inspect_get_format (g, root);

  if (r != NULL) {
    if (trace_flag) {
      trace_fp = trace_open (g);
      fprintf (trace_fp, "%s = ", "inspect_get_format");
      fprintf (trace_fp, "\"%s\"", r);
      trace_send_line (g);
    }

  } else {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "inspect_get_format", "NULL");
  }

  return r;
}

int
guestfs_inspect_is_live (guestfs_h *g,
                         const char *root)
{
  int trace_flag = g->trace;
  FILE *trace_fp;
  int r;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "inspect_is_live", 15);
  if (root == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "inspect_is_live", "root");
    return -1;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "inspect_is_live");
    fprintf (trace_fp, " \"%s\"", root);
    trace_send_line (g);
  }

  r = guestfs__inspect_is_live (g, root);

  if (r != -1) {
    if (trace_flag) {
      trace_fp = trace_open (g);
      fprintf (trace_fp, "%s = ", "inspect_is_live");
      fprintf (trace_fp, "%d", r);
      trace_send_line (g);
    }

  } else {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "inspect_is_live", "-1");
  }

  return r;
}

int
guestfs_inspect_is_netinst (guestfs_h *g,
                            const char *root)
{
  int trace_flag = g->trace;
  FILE *trace_fp;
  int r;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "inspect_is_netinst", 18);
  if (root == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "inspect_is_netinst", "root");
    return -1;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "inspect_is_netinst");
    fprintf (trace_fp, " \"%s\"", root);
    trace_send_line (g);
  }

  r = guestfs__inspect_is_netinst (g, root);

  if (r != -1) {
    if (trace_flag) {
      trace_fp = trace_open (g);
      fprintf (trace_fp, "%s = ", "inspect_is_netinst");
      fprintf (trace_fp, "%d", r);
      trace_send_line (g);
    }

  } else {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "inspect_is_netinst", "-1");
  }

  return r;
}

int
guestfs_inspect_is_multipart (guestfs_h *g,
                              const char *root)
{
  int trace_flag = g->trace;
  FILE *trace_fp;
  int r;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "inspect_is_multipart", 20);
  if (root == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "inspect_is_multipart", "root");
    return -1;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "inspect_is_multipart");
    fprintf (trace_fp, " \"%s\"", root);
    trace_send_line (g);
  }

  r = guestfs__inspect_is_multipart (g, root);

  if (r != -1) {
    if (trace_flag) {
      trace_fp = trace_open (g);
      fprintf (trace_fp, "%s = ", "inspect_is_multipart");
      fprintf (trace_fp, "%d", r);
      trace_send_line (g);
    }

  } else {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "inspect_is_multipart", "-1");
  }

  return r;
}

int
guestfs_set_attach_method (guestfs_h *g,
                           const char *attachmethod)
{
  int trace_flag = g->trace;
  FILE *trace_fp;
  int r;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "set_attach_method", 17);
  if (attachmethod == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "set_attach_method", "attachmethod");
    return -1;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "set_attach_method");
    fprintf (trace_fp, " \"%s\"", attachmethod);
    trace_send_line (g);
  }

  r = guestfs__set_attach_method (g, attachmethod);

  if (r != -1) {
    if (trace_flag) {
      trace_fp = trace_open (g);
      fprintf (trace_fp, "%s = ", "set_attach_method");
      fprintf (trace_fp, "%d", r);
      trace_send_line (g);
    }

  } else {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "set_attach_method", "-1");
  }

  return r;
}

char *
guestfs_get_attach_method (guestfs_h *g)
{
  int trace_flag = g->trace;
  FILE *trace_fp;
  char *r;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "get_attach_method", 17);
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "get_attach_method");
    trace_send_line (g);
  }

  r = guestfs__get_attach_method (g);

  if (r != NULL) {
    if (trace_flag) {
      trace_fp = trace_open (g);
      fprintf (trace_fp, "%s = ", "get_attach_method");
      fprintf (trace_fp, "\"%s\"", r);
      trace_send_line (g);
    }

  } else {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "get_attach_method", "NULL");
  }

  return r;
}

char *
guestfs_inspect_get_product_variant (guestfs_h *g,
                                     const char *root)
{
  int trace_flag = g->trace;
  FILE *trace_fp;
  char *r;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "inspect_get_product_variant", 27);
  if (root == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "inspect_get_product_variant", "root");
    return NULL;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "inspect_get_product_variant");
    fprintf (trace_fp, " \"%s\"", root);
    trace_send_line (g);
  }

  r = guestfs__inspect_get_product_variant (g, root);

  if (r != NULL) {
    if (trace_flag) {
      trace_fp = trace_open (g);
      fprintf (trace_fp, "%s = ", "inspect_get_product_variant");
      fprintf (trace_fp, "\"%s\"", r);
      trace_send_line (g);
    }

  } else {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "inspect_get_product_variant", "NULL");
  }

  return r;
}

char *
guestfs_inspect_get_windows_current_control_set (guestfs_h *g,
                                                 const char *root)
{
  int trace_flag = g->trace;
  FILE *trace_fp;
  char *r;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "inspect_get_windows_current_control_set", 39);
  if (root == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "inspect_get_windows_current_control_set", "root");
    return NULL;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "inspect_get_windows_current_control_set");
    fprintf (trace_fp, " \"%s\"", root);
    trace_send_line (g);
  }

  r = guestfs__inspect_get_windows_current_control_set (g, root);

  if (r != NULL) {
    if (trace_flag) {
      trace_fp = trace_open (g);
      fprintf (trace_fp, "%s = ", "inspect_get_windows_current_control_set");
      fprintf (trace_fp, "\"%s\"", r);
      trace_send_line (g);
    }

  } else {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "inspect_get_windows_current_control_set", "NULL");
  }

  return r;
}

char **
guestfs_inspect_get_drive_mappings (guestfs_h *g,
                                    const char *root)
{
  int trace_flag = g->trace;
  FILE *trace_fp;
  char **r;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "inspect_get_drive_mappings", 26);
  if (root == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "inspect_get_drive_mappings", "root");
    return NULL;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "inspect_get_drive_mappings");
    fprintf (trace_fp, " \"%s\"", root);
    trace_send_line (g);
  }

  r = guestfs__inspect_get_drive_mappings (g, root);

  if (r != NULL) {
    if (trace_flag) {
      size_t i;

      trace_fp = trace_open (g);
      fprintf (trace_fp, "%s = ", "inspect_get_drive_mappings");
      fputs ("[", trace_fp);
      for (i = 0; r[i]; ++i) {
        if (i > 0) fputs (", ", trace_fp);
        fputs ("\"", trace_fp);
        fputs (r[i], trace_fp);
        fputs ("\"", trace_fp);
      }
      fputs ("]", trace_fp);
      trace_send_line (g);
    }

  } else {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "inspect_get_drive_mappings", "NULL");
  }

  return r;
}

char *
guestfs_inspect_get_icon_argv (guestfs_h *g,
                               const char *root,
                               size_t *size_r,
                               const struct guestfs_inspect_get_icon_argv *optargs)
{
  int trace_flag = g->trace;
  FILE *trace_fp;
  char *r;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "inspect_get_icon", 16);
  if (root == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "inspect_get_icon", "root");
    return NULL;
  }

  if (optargs->bitmask & UINT64_C(0xfffffffffffffffc)) {
    error (g, "%s: unknown option in guestfs_%s_argv->bitmask (this can happen if a program is compiled against a newer version of libguestfs, then dynamically linked to an older version)",
           "inspect_get_icon", "inspect_get_icon");
    return NULL;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "inspect_get_icon");
    fprintf (trace_fp, " \"%s\"", root);
    if (optargs->bitmask & GUESTFS_INSPECT_GET_ICON_FAVICON_BITMASK)
      fprintf (trace_fp, " \"%s:%s\"", "favicon", optargs->favicon ? "true" : "false");
    if (optargs->bitmask & GUESTFS_INSPECT_GET_ICON_HIGHQUALITY_BITMASK)
      fprintf (trace_fp, " \"%s:%s\"", "highquality", optargs->highquality ? "true" : "false");
    trace_send_line (g);
  }

  r = guestfs__inspect_get_icon (g, root, size_r, optargs);

  if (r != NULL) {
    if (trace_flag) {
      trace_fp = trace_open (g);
      fprintf (trace_fp, "%s = ", "inspect_get_icon");
      guestfs___print_BufferOut (trace_fp, r, *size_r);
      trace_send_line (g);
    }

  } else {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "inspect_get_icon", "NULL");
  }

  return r;
}

int
guestfs_set_pgroup (guestfs_h *g,
                    int pgroup)
{
  int trace_flag = g->trace;
  FILE *trace_fp;
  int r;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "set_pgroup", 10);
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "set_pgroup");
    fputs (pgroup ? " true" : " false", trace_fp);
    trace_send_line (g);
  }

  r = guestfs__set_pgroup (g, pgroup);

  if (r != -1) {
    if (trace_flag) {
      trace_fp = trace_open (g);
      fprintf (trace_fp, "%s = ", "set_pgroup");
      fprintf (trace_fp, "%d", r);
      trace_send_line (g);
    }

  } else {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "set_pgroup", "-1");
  }

  return r;
}

int
guestfs_get_pgroup (guestfs_h *g)
{
  int trace_flag = g->trace;
  FILE *trace_fp;
  int r;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "get_pgroup", 10);
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "get_pgroup");
    trace_send_line (g);
  }

  r = guestfs__get_pgroup (g);

  if (r != -1) {
    if (trace_flag) {
      trace_fp = trace_open (g);
      fprintf (trace_fp, "%s = ", "get_pgroup");
      fprintf (trace_fp, "%d", r);
      trace_send_line (g);
    }

  } else {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "get_pgroup", "-1");
  }

  return r;
}

int
guestfs_set_smp (guestfs_h *g,
                 int smp)
{
  int trace_flag = g->trace;
  FILE *trace_fp;
  int r;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "set_smp", 7);
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "set_smp");
    fprintf (trace_fp, " %d", smp);
    trace_send_line (g);
  }

  r = guestfs__set_smp (g, smp);

  if (r != -1) {
    if (trace_flag) {
      trace_fp = trace_open (g);
      fprintf (trace_fp, "%s = ", "set_smp");
      fprintf (trace_fp, "%d", r);
      trace_send_line (g);
    }

  } else {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "set_smp", "-1");
  }

  return r;
}

int
guestfs_get_smp (guestfs_h *g)
{
  int trace_flag = g->trace;
  FILE *trace_fp;
  int r;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "get_smp", 7);
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "get_smp");
    trace_send_line (g);
  }

  r = guestfs__get_smp (g);

  if (r != -1) {
    if (trace_flag) {
      trace_fp = trace_open (g);
      fprintf (trace_fp, "%s = ", "get_smp");
      fprintf (trace_fp, "%d", r);
      trace_send_line (g);
    }

  } else {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "get_smp", "-1");
  }

  return r;
}

int
guestfs_mount (guestfs_h *g,
               const char *device,
               const char *mountpoint)
{
  struct guestfs_mount_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "mount", 5);
  if (device == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "mount", "device");
    return -1;
  }
  if (mountpoint == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "mount", "mountpoint");
    return -1;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "mount");
    fprintf (trace_fp, " \"%s\"", device);
    fprintf (trace_fp, " \"%s\"", mountpoint);
    trace_send_line (g);
  }

  if (check_state (g, "mount") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mount", "-1");
    return -1;
  }
  guestfs___set_busy (g);

  args.device = (char *) device;
  args.mountpoint = (char *) mountpoint;
  serial = guestfs___send (g, GUESTFS_PROC_MOUNT,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_mount_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mount", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "mount", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mount", "-1");
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_MOUNT, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mount", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mount", "-1");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "mount", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "mount",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  ret_v = 0;
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "mount");
    fprintf (trace_fp, "%d", ret_v);
    trace_send_line (g);
  }

  return ret_v;
}

int
guestfs_sync (guestfs_h *g)
{
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "sync", 4);
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "sync");
    trace_send_line (g);
  }

  if (check_state (g, "sync") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "sync", "-1");
    return -1;
  }
  guestfs___set_busy (g);

  serial = guestfs___send (g, GUESTFS_PROC_SYNC, progress_hint, 0,
                           NULL, NULL);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "sync", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "sync", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "sync", "-1");
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_SYNC, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "sync", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "sync", "-1");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "sync", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "sync",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  ret_v = 0;
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "sync");
    fprintf (trace_fp, "%d", ret_v);
    trace_send_line (g);
  }

  return ret_v;
}

int
guestfs_touch (guestfs_h *g,
               const char *path)
{
  struct guestfs_touch_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "touch", 5);
  if (path == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "touch", "path");
    return -1;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "touch");
    fprintf (trace_fp, " \"%s\"", path);
    trace_send_line (g);
  }

  if (check_state (g, "touch") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "touch", "-1");
    return -1;
  }
  guestfs___set_busy (g);

  args.path = (char *) path;
  serial = guestfs___send (g, GUESTFS_PROC_TOUCH,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_touch_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "touch", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "touch", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "touch", "-1");
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_TOUCH, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "touch", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "touch", "-1");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "touch", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "touch",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  ret_v = 0;
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "touch");
    fprintf (trace_fp, "%d", ret_v);
    trace_send_line (g);
  }

  return ret_v;
}

char *
guestfs_cat (guestfs_h *g,
             const char *path)
{
  struct guestfs_cat_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  struct guestfs_cat_ret ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  char *ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "cat", 3);
  if (path == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "cat", "path");
    return NULL;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "cat");
    fprintf (trace_fp, " \"%s\"", path);
    trace_send_line (g);
  }

  if (check_state (g, "cat") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "cat", "NULL");
    return NULL;
  }
  guestfs___set_busy (g);

  args.path = (char *) path;
  serial = guestfs___send (g, GUESTFS_PROC_CAT,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_cat_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "cat", "NULL");
    return NULL;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs___recv (g, "cat", &hdr, &err,
        (xdrproc_t) xdr_guestfs_cat_ret, (char *) &ret);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "cat", "NULL");
    return NULL;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_CAT, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "cat", "NULL");
    return NULL;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "cat", "NULL");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "cat", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "cat",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return NULL;
  }

  guestfs___end_busy (g);
  ret_v = ret.content; /* caller will free */
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "cat");
    fprintf (trace_fp, "\"%s\"", ret_v);
    trace_send_line (g);
  }

  return ret_v;
}

char *
guestfs_ll (guestfs_h *g,
            const char *directory)
{
  struct guestfs_ll_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  struct guestfs_ll_ret ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  char *ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "ll", 2);
  if (directory == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "ll", "directory");
    return NULL;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "ll");
    fprintf (trace_fp, " \"%s\"", directory);
    trace_send_line (g);
  }

  if (check_state (g, "ll") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "ll", "NULL");
    return NULL;
  }
  guestfs___set_busy (g);

  args.directory = (char *) directory;
  serial = guestfs___send (g, GUESTFS_PROC_LL,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_ll_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "ll", "NULL");
    return NULL;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs___recv (g, "ll", &hdr, &err,
        (xdrproc_t) xdr_guestfs_ll_ret, (char *) &ret);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "ll", "NULL");
    return NULL;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_LL, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "ll", "NULL");
    return NULL;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "ll", "NULL");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "ll", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "ll",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return NULL;
  }

  guestfs___end_busy (g);
  ret_v = ret.listing; /* caller will free */
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "ll");
    fprintf (trace_fp, "\"%s\"", ret_v);
    trace_send_line (g);
  }

  return ret_v;
}

char **
guestfs_ls (guestfs_h *g,
            const char *directory)
{
  struct guestfs_ls_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  struct guestfs_ls_ret ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  char **ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "ls", 2);
  if (directory == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "ls", "directory");
    return NULL;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "ls");
    fprintf (trace_fp, " \"%s\"", directory);
    trace_send_line (g);
  }

  if (check_state (g, "ls") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "ls", "NULL");
    return NULL;
  }
  guestfs___set_busy (g);

  args.directory = (char *) directory;
  serial = guestfs___send (g, GUESTFS_PROC_LS,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_ls_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "ls", "NULL");
    return NULL;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs___recv (g, "ls", &hdr, &err,
        (xdrproc_t) xdr_guestfs_ls_ret, (char *) &ret);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "ls", "NULL");
    return NULL;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_LS, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "ls", "NULL");
    return NULL;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "ls", "NULL");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "ls", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "ls",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return NULL;
  }

  guestfs___end_busy (g);
  /* caller will free this, but we need to add a NULL entry */
  ret.listing.listing_val =
    safe_realloc (g, ret.listing.listing_val,
                  sizeof (char *) * (ret.listing.listing_len + 1));
  ret.listing.listing_val[ret.listing.listing_len] = NULL;
  ret_v = ret.listing.listing_val;
  if (trace_flag) {
    size_t i;

    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "ls");
    fputs ("[", trace_fp);
    for (i = 0; ret_v[i]; ++i) {
      if (i > 0) fputs (", ", trace_fp);
      fputs ("\"", trace_fp);
      fputs (ret_v[i], trace_fp);
      fputs ("\"", trace_fp);
    }
    fputs ("]", trace_fp);
    trace_send_line (g);
  }

  return ret_v;
}

char **
guestfs_list_devices (guestfs_h *g)
{
  guestfs_message_header hdr;
  guestfs_message_error err;
  struct guestfs_list_devices_ret ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  char **ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "list_devices", 12);
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "list_devices");
    trace_send_line (g);
  }

  if (check_state (g, "list_devices") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "list_devices", "NULL");
    return NULL;
  }
  guestfs___set_busy (g);

  serial = guestfs___send (g, GUESTFS_PROC_LIST_DEVICES, progress_hint, 0,
                           NULL, NULL);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "list_devices", "NULL");
    return NULL;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs___recv (g, "list_devices", &hdr, &err,
        (xdrproc_t) xdr_guestfs_list_devices_ret, (char *) &ret);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "list_devices", "NULL");
    return NULL;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_LIST_DEVICES, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "list_devices", "NULL");
    return NULL;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "list_devices", "NULL");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "list_devices", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "list_devices",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return NULL;
  }

  guestfs___end_busy (g);
  /* caller will free this, but we need to add a NULL entry */
  ret.devices.devices_val =
    safe_realloc (g, ret.devices.devices_val,
                  sizeof (char *) * (ret.devices.devices_len + 1));
  ret.devices.devices_val[ret.devices.devices_len] = NULL;
  ret_v = ret.devices.devices_val;
  if (trace_flag) {
    size_t i;

    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "list_devices");
    fputs ("[", trace_fp);
    for (i = 0; ret_v[i]; ++i) {
      if (i > 0) fputs (", ", trace_fp);
      fputs ("\"", trace_fp);
      fputs (ret_v[i], trace_fp);
      fputs ("\"", trace_fp);
    }
    fputs ("]", trace_fp);
    trace_send_line (g);
  }

  return ret_v;
}

char **
guestfs_list_partitions (guestfs_h *g)
{
  guestfs_message_header hdr;
  guestfs_message_error err;
  struct guestfs_list_partitions_ret ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  char **ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "list_partitions", 15);
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "list_partitions");
    trace_send_line (g);
  }

  if (check_state (g, "list_partitions") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "list_partitions", "NULL");
    return NULL;
  }
  guestfs___set_busy (g);

  serial = guestfs___send (g, GUESTFS_PROC_LIST_PARTITIONS, progress_hint, 0,
                           NULL, NULL);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "list_partitions", "NULL");
    return NULL;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs___recv (g, "list_partitions", &hdr, &err,
        (xdrproc_t) xdr_guestfs_list_partitions_ret, (char *) &ret);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "list_partitions", "NULL");
    return NULL;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_LIST_PARTITIONS, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "list_partitions", "NULL");
    return NULL;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "list_partitions", "NULL");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "list_partitions", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "list_partitions",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return NULL;
  }

  guestfs___end_busy (g);
  /* caller will free this, but we need to add a NULL entry */
  ret.partitions.partitions_val =
    safe_realloc (g, ret.partitions.partitions_val,
                  sizeof (char *) * (ret.partitions.partitions_len + 1));
  ret.partitions.partitions_val[ret.partitions.partitions_len] = NULL;
  ret_v = ret.partitions.partitions_val;
  if (trace_flag) {
    size_t i;

    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "list_partitions");
    fputs ("[", trace_fp);
    for (i = 0; ret_v[i]; ++i) {
      if (i > 0) fputs (", ", trace_fp);
      fputs ("\"", trace_fp);
      fputs (ret_v[i], trace_fp);
      fputs ("\"", trace_fp);
    }
    fputs ("]", trace_fp);
    trace_send_line (g);
  }

  return ret_v;
}

char **
guestfs_pvs (guestfs_h *g)
{
  guestfs_message_header hdr;
  guestfs_message_error err;
  struct guestfs_pvs_ret ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  char **ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "pvs", 3);
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "pvs");
    trace_send_line (g);
  }

  if (check_state (g, "pvs") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "pvs", "NULL");
    return NULL;
  }
  guestfs___set_busy (g);

  serial = guestfs___send (g, GUESTFS_PROC_PVS, progress_hint, 0,
                           NULL, NULL);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "pvs", "NULL");
    return NULL;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs___recv (g, "pvs", &hdr, &err,
        (xdrproc_t) xdr_guestfs_pvs_ret, (char *) &ret);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "pvs", "NULL");
    return NULL;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_PVS, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "pvs", "NULL");
    return NULL;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "pvs", "NULL");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "pvs", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "pvs",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return NULL;
  }

  guestfs___end_busy (g);
  /* caller will free this, but we need to add a NULL entry */
  ret.physvols.physvols_val =
    safe_realloc (g, ret.physvols.physvols_val,
                  sizeof (char *) * (ret.physvols.physvols_len + 1));
  ret.physvols.physvols_val[ret.physvols.physvols_len] = NULL;
  ret_v = ret.physvols.physvols_val;
  if (trace_flag) {
    size_t i;

    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "pvs");
    fputs ("[", trace_fp);
    for (i = 0; ret_v[i]; ++i) {
      if (i > 0) fputs (", ", trace_fp);
      fputs ("\"", trace_fp);
      fputs (ret_v[i], trace_fp);
      fputs ("\"", trace_fp);
    }
    fputs ("]", trace_fp);
    trace_send_line (g);
  }

  return ret_v;
}

char **
guestfs_vgs (guestfs_h *g)
{
  guestfs_message_header hdr;
  guestfs_message_error err;
  struct guestfs_vgs_ret ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  char **ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "vgs", 3);
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "vgs");
    trace_send_line (g);
  }

  if (check_state (g, "vgs") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "vgs", "NULL");
    return NULL;
  }
  guestfs___set_busy (g);

  serial = guestfs___send (g, GUESTFS_PROC_VGS, progress_hint, 0,
                           NULL, NULL);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "vgs", "NULL");
    return NULL;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs___recv (g, "vgs", &hdr, &err,
        (xdrproc_t) xdr_guestfs_vgs_ret, (char *) &ret);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "vgs", "NULL");
    return NULL;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_VGS, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "vgs", "NULL");
    return NULL;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "vgs", "NULL");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "vgs", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "vgs",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return NULL;
  }

  guestfs___end_busy (g);
  /* caller will free this, but we need to add a NULL entry */
  ret.volgroups.volgroups_val =
    safe_realloc (g, ret.volgroups.volgroups_val,
                  sizeof (char *) * (ret.volgroups.volgroups_len + 1));
  ret.volgroups.volgroups_val[ret.volgroups.volgroups_len] = NULL;
  ret_v = ret.volgroups.volgroups_val;
  if (trace_flag) {
    size_t i;

    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "vgs");
    fputs ("[", trace_fp);
    for (i = 0; ret_v[i]; ++i) {
      if (i > 0) fputs (", ", trace_fp);
      fputs ("\"", trace_fp);
      fputs (ret_v[i], trace_fp);
      fputs ("\"", trace_fp);
    }
    fputs ("]", trace_fp);
    trace_send_line (g);
  }

  return ret_v;
}

char **
guestfs_lvs (guestfs_h *g)
{
  guestfs_message_header hdr;
  guestfs_message_error err;
  struct guestfs_lvs_ret ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  char **ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "lvs", 3);
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "lvs");
    trace_send_line (g);
  }

  if (check_state (g, "lvs") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "lvs", "NULL");
    return NULL;
  }
  guestfs___set_busy (g);

  serial = guestfs___send (g, GUESTFS_PROC_LVS, progress_hint, 0,
                           NULL, NULL);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "lvs", "NULL");
    return NULL;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs___recv (g, "lvs", &hdr, &err,
        (xdrproc_t) xdr_guestfs_lvs_ret, (char *) &ret);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "lvs", "NULL");
    return NULL;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_LVS, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "lvs", "NULL");
    return NULL;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "lvs", "NULL");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "lvs", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "lvs",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return NULL;
  }

  guestfs___end_busy (g);
  /* caller will free this, but we need to add a NULL entry */
  ret.logvols.logvols_val =
    safe_realloc (g, ret.logvols.logvols_val,
                  sizeof (char *) * (ret.logvols.logvols_len + 1));
  ret.logvols.logvols_val[ret.logvols.logvols_len] = NULL;
  ret_v = ret.logvols.logvols_val;
  if (trace_flag) {
    size_t i;

    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "lvs");
    fputs ("[", trace_fp);
    for (i = 0; ret_v[i]; ++i) {
      if (i > 0) fputs (", ", trace_fp);
      fputs ("\"", trace_fp);
      fputs (ret_v[i], trace_fp);
      fputs ("\"", trace_fp);
    }
    fputs ("]", trace_fp);
    trace_send_line (g);
  }

  return ret_v;
}

struct guestfs_lvm_pv_list *
guestfs_pvs_full (guestfs_h *g)
{
  guestfs_message_header hdr;
  guestfs_message_error err;
  struct guestfs_pvs_full_ret ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  struct guestfs_lvm_pv_list *ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "pvs_full", 8);
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "pvs_full");
    trace_send_line (g);
  }

  if (check_state (g, "pvs_full") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "pvs_full", "NULL");
    return NULL;
  }
  guestfs___set_busy (g);

  serial = guestfs___send (g, GUESTFS_PROC_PVS_FULL, progress_hint, 0,
                           NULL, NULL);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "pvs_full", "NULL");
    return NULL;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs___recv (g, "pvs_full", &hdr, &err,
        (xdrproc_t) xdr_guestfs_pvs_full_ret, (char *) &ret);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "pvs_full", "NULL");
    return NULL;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_PVS_FULL, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "pvs_full", "NULL");
    return NULL;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "pvs_full", "NULL");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "pvs_full", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "pvs_full",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return NULL;
  }

  guestfs___end_busy (g);
  /* caller will free this */
  ret_v = safe_memdup (g, &ret.physvols, sizeof (ret.physvols));
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "pvs_full");
    fprintf (trace_fp, "<struct guestfs_lvm_pv_list *>");
    trace_send_line (g);
  }

  return ret_v;
}

struct guestfs_lvm_vg_list *
guestfs_vgs_full (guestfs_h *g)
{
  guestfs_message_header hdr;
  guestfs_message_error err;
  struct guestfs_vgs_full_ret ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  struct guestfs_lvm_vg_list *ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "vgs_full", 8);
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "vgs_full");
    trace_send_line (g);
  }

  if (check_state (g, "vgs_full") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "vgs_full", "NULL");
    return NULL;
  }
  guestfs___set_busy (g);

  serial = guestfs___send (g, GUESTFS_PROC_VGS_FULL, progress_hint, 0,
                           NULL, NULL);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "vgs_full", "NULL");
    return NULL;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs___recv (g, "vgs_full", &hdr, &err,
        (xdrproc_t) xdr_guestfs_vgs_full_ret, (char *) &ret);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "vgs_full", "NULL");
    return NULL;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_VGS_FULL, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "vgs_full", "NULL");
    return NULL;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "vgs_full", "NULL");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "vgs_full", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "vgs_full",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return NULL;
  }

  guestfs___end_busy (g);
  /* caller will free this */
  ret_v = safe_memdup (g, &ret.volgroups, sizeof (ret.volgroups));
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "vgs_full");
    fprintf (trace_fp, "<struct guestfs_lvm_vg_list *>");
    trace_send_line (g);
  }

  return ret_v;
}

struct guestfs_lvm_lv_list *
guestfs_lvs_full (guestfs_h *g)
{
  guestfs_message_header hdr;
  guestfs_message_error err;
  struct guestfs_lvs_full_ret ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  struct guestfs_lvm_lv_list *ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "lvs_full", 8);
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "lvs_full");
    trace_send_line (g);
  }

  if (check_state (g, "lvs_full") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "lvs_full", "NULL");
    return NULL;
  }
  guestfs___set_busy (g);

  serial = guestfs___send (g, GUESTFS_PROC_LVS_FULL, progress_hint, 0,
                           NULL, NULL);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "lvs_full", "NULL");
    return NULL;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs___recv (g, "lvs_full", &hdr, &err,
        (xdrproc_t) xdr_guestfs_lvs_full_ret, (char *) &ret);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "lvs_full", "NULL");
    return NULL;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_LVS_FULL, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "lvs_full", "NULL");
    return NULL;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "lvs_full", "NULL");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "lvs_full", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "lvs_full",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return NULL;
  }

  guestfs___end_busy (g);
  /* caller will free this */
  ret_v = safe_memdup (g, &ret.logvols, sizeof (ret.logvols));
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "lvs_full");
    fprintf (trace_fp, "<struct guestfs_lvm_lv_list *>");
    trace_send_line (g);
  }

  return ret_v;
}

char **
guestfs_read_lines (guestfs_h *g,
                    const char *path)
{
  struct guestfs_read_lines_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  struct guestfs_read_lines_ret ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  char **ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "read_lines", 10);
  if (path == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "read_lines", "path");
    return NULL;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "read_lines");
    fprintf (trace_fp, " \"%s\"", path);
    trace_send_line (g);
  }

  if (check_state (g, "read_lines") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "read_lines", "NULL");
    return NULL;
  }
  guestfs___set_busy (g);

  args.path = (char *) path;
  serial = guestfs___send (g, GUESTFS_PROC_READ_LINES,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_read_lines_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "read_lines", "NULL");
    return NULL;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs___recv (g, "read_lines", &hdr, &err,
        (xdrproc_t) xdr_guestfs_read_lines_ret, (char *) &ret);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "read_lines", "NULL");
    return NULL;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_READ_LINES, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "read_lines", "NULL");
    return NULL;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "read_lines", "NULL");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "read_lines", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "read_lines",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return NULL;
  }

  guestfs___end_busy (g);
  /* caller will free this, but we need to add a NULL entry */
  ret.lines.lines_val =
    safe_realloc (g, ret.lines.lines_val,
                  sizeof (char *) * (ret.lines.lines_len + 1));
  ret.lines.lines_val[ret.lines.lines_len] = NULL;
  ret_v = ret.lines.lines_val;
  if (trace_flag) {
    size_t i;

    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "read_lines");
    fputs ("[", trace_fp);
    for (i = 0; ret_v[i]; ++i) {
      if (i > 0) fputs (", ", trace_fp);
      fputs ("\"", trace_fp);
      fputs (ret_v[i], trace_fp);
      fputs ("\"", trace_fp);
    }
    fputs ("]", trace_fp);
    trace_send_line (g);
  }

  return ret_v;
}

int
guestfs_aug_init (guestfs_h *g,
                  const char *root,
                  int flags)
{
  struct guestfs_aug_init_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "aug_init", 8);
  if (root == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "aug_init", "root");
    return -1;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "aug_init");
    fprintf (trace_fp, " \"%s\"", root);
    fprintf (trace_fp, " %d", flags);
    trace_send_line (g);
  }

  if (check_state (g, "aug_init") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "aug_init", "-1");
    return -1;
  }
  guestfs___set_busy (g);

  args.root = (char *) root;
  args.flags = flags;
  serial = guestfs___send (g, GUESTFS_PROC_AUG_INIT,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_aug_init_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "aug_init", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "aug_init", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "aug_init", "-1");
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_AUG_INIT, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "aug_init", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "aug_init", "-1");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "aug_init", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "aug_init",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  ret_v = 0;
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "aug_init");
    fprintf (trace_fp, "%d", ret_v);
    trace_send_line (g);
  }

  return ret_v;
}

int
guestfs_aug_close (guestfs_h *g)
{
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "aug_close", 9);
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "aug_close");
    trace_send_line (g);
  }

  if (check_state (g, "aug_close") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "aug_close", "-1");
    return -1;
  }
  guestfs___set_busy (g);

  serial = guestfs___send (g, GUESTFS_PROC_AUG_CLOSE, progress_hint, 0,
                           NULL, NULL);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "aug_close", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "aug_close", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "aug_close", "-1");
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_AUG_CLOSE, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "aug_close", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "aug_close", "-1");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "aug_close", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "aug_close",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  ret_v = 0;
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "aug_close");
    fprintf (trace_fp, "%d", ret_v);
    trace_send_line (g);
  }

  return ret_v;
}

int
guestfs_aug_defvar (guestfs_h *g,
                    const char *name,
                    const char *expr)
{
  struct guestfs_aug_defvar_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  struct guestfs_aug_defvar_ret ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "aug_defvar", 10);
  if (name == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "aug_defvar", "name");
    return -1;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "aug_defvar");
    fprintf (trace_fp, " \"%s\"", name);
    if (expr) fprintf (trace_fp, " \"%s\"", expr);
    else fprintf (trace_fp, " null");
    trace_send_line (g);
  }

  if (check_state (g, "aug_defvar") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "aug_defvar", "-1");
    return -1;
  }
  guestfs___set_busy (g);

  args.name = (char *) name;
  args.expr = expr ? (char **) &expr : NULL;
  serial = guestfs___send (g, GUESTFS_PROC_AUG_DEFVAR,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_aug_defvar_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "aug_defvar", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs___recv (g, "aug_defvar", &hdr, &err,
        (xdrproc_t) xdr_guestfs_aug_defvar_ret, (char *) &ret);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "aug_defvar", "-1");
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_AUG_DEFVAR, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "aug_defvar", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "aug_defvar", "-1");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "aug_defvar", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "aug_defvar",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  ret_v = ret.nrnodes;
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "aug_defvar");
    fprintf (trace_fp, "%d", ret_v);
    trace_send_line (g);
  }

  return ret_v;
}

struct guestfs_int_bool *
guestfs_aug_defnode (guestfs_h *g,
                     const char *name,
                     const char *expr,
                     const char *val)
{
  struct guestfs_aug_defnode_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  struct guestfs_aug_defnode_ret ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  struct guestfs_int_bool *ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "aug_defnode", 11);
  if (name == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "aug_defnode", "name");
    return NULL;
  }
  if (expr == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "aug_defnode", "expr");
    return NULL;
  }
  if (val == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "aug_defnode", "val");
    return NULL;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "aug_defnode");
    fprintf (trace_fp, " \"%s\"", name);
    fprintf (trace_fp, " \"%s\"", expr);
    fprintf (trace_fp, " \"%s\"", val);
    trace_send_line (g);
  }

  if (check_state (g, "aug_defnode") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "aug_defnode", "NULL");
    return NULL;
  }
  guestfs___set_busy (g);

  args.name = (char *) name;
  args.expr = (char *) expr;
  args.val = (char *) val;
  serial = guestfs___send (g, GUESTFS_PROC_AUG_DEFNODE,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_aug_defnode_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "aug_defnode", "NULL");
    return NULL;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs___recv (g, "aug_defnode", &hdr, &err,
        (xdrproc_t) xdr_guestfs_aug_defnode_ret, (char *) &ret);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "aug_defnode", "NULL");
    return NULL;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_AUG_DEFNODE, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "aug_defnode", "NULL");
    return NULL;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "aug_defnode", "NULL");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "aug_defnode", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "aug_defnode",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return NULL;
  }

  guestfs___end_busy (g);
  /* caller will free this */
  ret_v = safe_memdup (g, &ret.nrnodescreated, sizeof (ret.nrnodescreated));
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "aug_defnode");
    fprintf (trace_fp, "<struct guestfs_int_bool *>");
    trace_send_line (g);
  }

  return ret_v;
}

char *
guestfs_aug_get (guestfs_h *g,
                 const char *augpath)
{
  struct guestfs_aug_get_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  struct guestfs_aug_get_ret ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  char *ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "aug_get", 7);
  if (augpath == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "aug_get", "augpath");
    return NULL;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "aug_get");
    fprintf (trace_fp, " \"%s\"", augpath);
    trace_send_line (g);
  }

  if (check_state (g, "aug_get") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "aug_get", "NULL");
    return NULL;
  }
  guestfs___set_busy (g);

  args.augpath = (char *) augpath;
  serial = guestfs___send (g, GUESTFS_PROC_AUG_GET,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_aug_get_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "aug_get", "NULL");
    return NULL;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs___recv (g, "aug_get", &hdr, &err,
        (xdrproc_t) xdr_guestfs_aug_get_ret, (char *) &ret);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "aug_get", "NULL");
    return NULL;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_AUG_GET, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "aug_get", "NULL");
    return NULL;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "aug_get", "NULL");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "aug_get", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "aug_get",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return NULL;
  }

  guestfs___end_busy (g);
  ret_v = ret.val; /* caller will free */
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "aug_get");
    fprintf (trace_fp, "\"%s\"", ret_v);
    trace_send_line (g);
  }

  return ret_v;
}

int
guestfs_aug_set (guestfs_h *g,
                 const char *augpath,
                 const char *val)
{
  struct guestfs_aug_set_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "aug_set", 7);
  if (augpath == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "aug_set", "augpath");
    return -1;
  }
  if (val == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "aug_set", "val");
    return -1;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "aug_set");
    fprintf (trace_fp, " \"%s\"", augpath);
    fprintf (trace_fp, " \"%s\"", val);
    trace_send_line (g);
  }

  if (check_state (g, "aug_set") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "aug_set", "-1");
    return -1;
  }
  guestfs___set_busy (g);

  args.augpath = (char *) augpath;
  args.val = (char *) val;
  serial = guestfs___send (g, GUESTFS_PROC_AUG_SET,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_aug_set_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "aug_set", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "aug_set", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "aug_set", "-1");
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_AUG_SET, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "aug_set", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "aug_set", "-1");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "aug_set", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "aug_set",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  ret_v = 0;
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "aug_set");
    fprintf (trace_fp, "%d", ret_v);
    trace_send_line (g);
  }

  return ret_v;
}

int
guestfs_aug_insert (guestfs_h *g,
                    const char *augpath,
                    const char *label,
                    int before)
{
  struct guestfs_aug_insert_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "aug_insert", 10);
  if (augpath == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "aug_insert", "augpath");
    return -1;
  }
  if (label == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "aug_insert", "label");
    return -1;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "aug_insert");
    fprintf (trace_fp, " \"%s\"", augpath);
    fprintf (trace_fp, " \"%s\"", label);
    fputs (before ? " true" : " false", trace_fp);
    trace_send_line (g);
  }

  if (check_state (g, "aug_insert") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "aug_insert", "-1");
    return -1;
  }
  guestfs___set_busy (g);

  args.augpath = (char *) augpath;
  args.label = (char *) label;
  args.before = before;
  serial = guestfs___send (g, GUESTFS_PROC_AUG_INSERT,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_aug_insert_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "aug_insert", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "aug_insert", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "aug_insert", "-1");
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_AUG_INSERT, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "aug_insert", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "aug_insert", "-1");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "aug_insert", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "aug_insert",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  ret_v = 0;
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "aug_insert");
    fprintf (trace_fp, "%d", ret_v);
    trace_send_line (g);
  }

  return ret_v;
}

int
guestfs_aug_rm (guestfs_h *g,
                const char *augpath)
{
  struct guestfs_aug_rm_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  struct guestfs_aug_rm_ret ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "aug_rm", 6);
  if (augpath == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "aug_rm", "augpath");
    return -1;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "aug_rm");
    fprintf (trace_fp, " \"%s\"", augpath);
    trace_send_line (g);
  }

  if (check_state (g, "aug_rm") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "aug_rm", "-1");
    return -1;
  }
  guestfs___set_busy (g);

  args.augpath = (char *) augpath;
  serial = guestfs___send (g, GUESTFS_PROC_AUG_RM,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_aug_rm_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "aug_rm", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs___recv (g, "aug_rm", &hdr, &err,
        (xdrproc_t) xdr_guestfs_aug_rm_ret, (char *) &ret);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "aug_rm", "-1");
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_AUG_RM, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "aug_rm", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "aug_rm", "-1");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "aug_rm", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "aug_rm",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  ret_v = ret.nrnodes;
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "aug_rm");
    fprintf (trace_fp, "%d", ret_v);
    trace_send_line (g);
  }

  return ret_v;
}

int
guestfs_aug_mv (guestfs_h *g,
                const char *src,
                const char *dest)
{
  struct guestfs_aug_mv_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "aug_mv", 6);
  if (src == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "aug_mv", "src");
    return -1;
  }
  if (dest == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "aug_mv", "dest");
    return -1;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "aug_mv");
    fprintf (trace_fp, " \"%s\"", src);
    fprintf (trace_fp, " \"%s\"", dest);
    trace_send_line (g);
  }

  if (check_state (g, "aug_mv") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "aug_mv", "-1");
    return -1;
  }
  guestfs___set_busy (g);

  args.src = (char *) src;
  args.dest = (char *) dest;
  serial = guestfs___send (g, GUESTFS_PROC_AUG_MV,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_aug_mv_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "aug_mv", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "aug_mv", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "aug_mv", "-1");
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_AUG_MV, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "aug_mv", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "aug_mv", "-1");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "aug_mv", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "aug_mv",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  ret_v = 0;
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "aug_mv");
    fprintf (trace_fp, "%d", ret_v);
    trace_send_line (g);
  }

  return ret_v;
}

char **
guestfs_aug_match (guestfs_h *g,
                   const char *augpath)
{
  struct guestfs_aug_match_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  struct guestfs_aug_match_ret ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  char **ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "aug_match", 9);
  if (augpath == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "aug_match", "augpath");
    return NULL;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "aug_match");
    fprintf (trace_fp, " \"%s\"", augpath);
    trace_send_line (g);
  }

  if (check_state (g, "aug_match") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "aug_match", "NULL");
    return NULL;
  }
  guestfs___set_busy (g);

  args.augpath = (char *) augpath;
  serial = guestfs___send (g, GUESTFS_PROC_AUG_MATCH,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_aug_match_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "aug_match", "NULL");
    return NULL;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs___recv (g, "aug_match", &hdr, &err,
        (xdrproc_t) xdr_guestfs_aug_match_ret, (char *) &ret);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "aug_match", "NULL");
    return NULL;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_AUG_MATCH, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "aug_match", "NULL");
    return NULL;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "aug_match", "NULL");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "aug_match", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "aug_match",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return NULL;
  }

  guestfs___end_busy (g);
  /* caller will free this, but we need to add a NULL entry */
  ret.matches.matches_val =
    safe_realloc (g, ret.matches.matches_val,
                  sizeof (char *) * (ret.matches.matches_len + 1));
  ret.matches.matches_val[ret.matches.matches_len] = NULL;
  ret_v = ret.matches.matches_val;
  if (trace_flag) {
    size_t i;

    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "aug_match");
    fputs ("[", trace_fp);
    for (i = 0; ret_v[i]; ++i) {
      if (i > 0) fputs (", ", trace_fp);
      fputs ("\"", trace_fp);
      fputs (ret_v[i], trace_fp);
      fputs ("\"", trace_fp);
    }
    fputs ("]", trace_fp);
    trace_send_line (g);
  }

  return ret_v;
}

int
guestfs_aug_save (guestfs_h *g)
{
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "aug_save", 8);
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "aug_save");
    trace_send_line (g);
  }

  if (check_state (g, "aug_save") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "aug_save", "-1");
    return -1;
  }
  guestfs___set_busy (g);

  serial = guestfs___send (g, GUESTFS_PROC_AUG_SAVE, progress_hint, 0,
                           NULL, NULL);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "aug_save", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "aug_save", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "aug_save", "-1");
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_AUG_SAVE, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "aug_save", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "aug_save", "-1");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "aug_save", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "aug_save",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  ret_v = 0;
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "aug_save");
    fprintf (trace_fp, "%d", ret_v);
    trace_send_line (g);
  }

  return ret_v;
}

int
guestfs_aug_load (guestfs_h *g)
{
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "aug_load", 8);
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "aug_load");
    trace_send_line (g);
  }

  if (check_state (g, "aug_load") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "aug_load", "-1");
    return -1;
  }
  guestfs___set_busy (g);

  serial = guestfs___send (g, GUESTFS_PROC_AUG_LOAD, progress_hint, 0,
                           NULL, NULL);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "aug_load", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "aug_load", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "aug_load", "-1");
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_AUG_LOAD, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "aug_load", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "aug_load", "-1");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "aug_load", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "aug_load",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  ret_v = 0;
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "aug_load");
    fprintf (trace_fp, "%d", ret_v);
    trace_send_line (g);
  }

  return ret_v;
}

char **
guestfs_aug_ls (guestfs_h *g,
                const char *augpath)
{
  struct guestfs_aug_ls_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  struct guestfs_aug_ls_ret ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  char **ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "aug_ls", 6);
  if (augpath == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "aug_ls", "augpath");
    return NULL;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "aug_ls");
    fprintf (trace_fp, " \"%s\"", augpath);
    trace_send_line (g);
  }

  if (check_state (g, "aug_ls") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "aug_ls", "NULL");
    return NULL;
  }
  guestfs___set_busy (g);

  args.augpath = (char *) augpath;
  serial = guestfs___send (g, GUESTFS_PROC_AUG_LS,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_aug_ls_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "aug_ls", "NULL");
    return NULL;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs___recv (g, "aug_ls", &hdr, &err,
        (xdrproc_t) xdr_guestfs_aug_ls_ret, (char *) &ret);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "aug_ls", "NULL");
    return NULL;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_AUG_LS, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "aug_ls", "NULL");
    return NULL;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "aug_ls", "NULL");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "aug_ls", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "aug_ls",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return NULL;
  }

  guestfs___end_busy (g);
  /* caller will free this, but we need to add a NULL entry */
  ret.matches.matches_val =
    safe_realloc (g, ret.matches.matches_val,
                  sizeof (char *) * (ret.matches.matches_len + 1));
  ret.matches.matches_val[ret.matches.matches_len] = NULL;
  ret_v = ret.matches.matches_val;
  if (trace_flag) {
    size_t i;

    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "aug_ls");
    fputs ("[", trace_fp);
    for (i = 0; ret_v[i]; ++i) {
      if (i > 0) fputs (", ", trace_fp);
      fputs ("\"", trace_fp);
      fputs (ret_v[i], trace_fp);
      fputs ("\"", trace_fp);
    }
    fputs ("]", trace_fp);
    trace_send_line (g);
  }

  return ret_v;
}

int
guestfs_rm (guestfs_h *g,
            const char *path)
{
  struct guestfs_rm_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "rm", 2);
  if (path == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "rm", "path");
    return -1;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "rm");
    fprintf (trace_fp, " \"%s\"", path);
    trace_send_line (g);
  }

  if (check_state (g, "rm") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "rm", "-1");
    return -1;
  }
  guestfs___set_busy (g);

  args.path = (char *) path;
  serial = guestfs___send (g, GUESTFS_PROC_RM,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_rm_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "rm", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "rm", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "rm", "-1");
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_RM, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "rm", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "rm", "-1");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "rm", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "rm",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  ret_v = 0;
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "rm");
    fprintf (trace_fp, "%d", ret_v);
    trace_send_line (g);
  }

  return ret_v;
}

int
guestfs_rmdir (guestfs_h *g,
               const char *path)
{
  struct guestfs_rmdir_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "rmdir", 5);
  if (path == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "rmdir", "path");
    return -1;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "rmdir");
    fprintf (trace_fp, " \"%s\"", path);
    trace_send_line (g);
  }

  if (check_state (g, "rmdir") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "rmdir", "-1");
    return -1;
  }
  guestfs___set_busy (g);

  args.path = (char *) path;
  serial = guestfs___send (g, GUESTFS_PROC_RMDIR,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_rmdir_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "rmdir", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "rmdir", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "rmdir", "-1");
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_RMDIR, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "rmdir", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "rmdir", "-1");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "rmdir", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "rmdir",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  ret_v = 0;
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "rmdir");
    fprintf (trace_fp, "%d", ret_v);
    trace_send_line (g);
  }

  return ret_v;
}

int
guestfs_rm_rf (guestfs_h *g,
               const char *path)
{
  struct guestfs_rm_rf_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "rm_rf", 5);
  if (path == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "rm_rf", "path");
    return -1;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "rm_rf");
    fprintf (trace_fp, " \"%s\"", path);
    trace_send_line (g);
  }

  if (check_state (g, "rm_rf") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "rm_rf", "-1");
    return -1;
  }
  guestfs___set_busy (g);

  args.path = (char *) path;
  serial = guestfs___send (g, GUESTFS_PROC_RM_RF,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_rm_rf_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "rm_rf", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "rm_rf", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "rm_rf", "-1");
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_RM_RF, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "rm_rf", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "rm_rf", "-1");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "rm_rf", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "rm_rf",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  ret_v = 0;
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "rm_rf");
    fprintf (trace_fp, "%d", ret_v);
    trace_send_line (g);
  }

  return ret_v;
}

int
guestfs_mkdir (guestfs_h *g,
               const char *path)
{
  struct guestfs_mkdir_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "mkdir", 5);
  if (path == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "mkdir", "path");
    return -1;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "mkdir");
    fprintf (trace_fp, " \"%s\"", path);
    trace_send_line (g);
  }

  if (check_state (g, "mkdir") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mkdir", "-1");
    return -1;
  }
  guestfs___set_busy (g);

  args.path = (char *) path;
  serial = guestfs___send (g, GUESTFS_PROC_MKDIR,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_mkdir_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mkdir", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "mkdir", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mkdir", "-1");
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_MKDIR, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mkdir", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mkdir", "-1");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "mkdir", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "mkdir",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  ret_v = 0;
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "mkdir");
    fprintf (trace_fp, "%d", ret_v);
    trace_send_line (g);
  }

  return ret_v;
}

int
guestfs_mkdir_p (guestfs_h *g,
                 const char *path)
{
  struct guestfs_mkdir_p_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "mkdir_p", 7);
  if (path == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "mkdir_p", "path");
    return -1;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "mkdir_p");
    fprintf (trace_fp, " \"%s\"", path);
    trace_send_line (g);
  }

  if (check_state (g, "mkdir_p") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mkdir_p", "-1");
    return -1;
  }
  guestfs___set_busy (g);

  args.path = (char *) path;
  serial = guestfs___send (g, GUESTFS_PROC_MKDIR_P,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_mkdir_p_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mkdir_p", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "mkdir_p", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mkdir_p", "-1");
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_MKDIR_P, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mkdir_p", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mkdir_p", "-1");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "mkdir_p", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "mkdir_p",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  ret_v = 0;
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "mkdir_p");
    fprintf (trace_fp, "%d", ret_v);
    trace_send_line (g);
  }

  return ret_v;
}

int
guestfs_chmod (guestfs_h *g,
               int mode,
               const char *path)
{
  struct guestfs_chmod_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "chmod", 5);
  if (path == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "chmod", "path");
    return -1;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "chmod");
    fprintf (trace_fp, " %d", mode);
    fprintf (trace_fp, " \"%s\"", path);
    trace_send_line (g);
  }

  if (check_state (g, "chmod") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "chmod", "-1");
    return -1;
  }
  guestfs___set_busy (g);

  args.mode = mode;
  args.path = (char *) path;
  serial = guestfs___send (g, GUESTFS_PROC_CHMOD,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_chmod_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "chmod", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "chmod", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "chmod", "-1");
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_CHMOD, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "chmod", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "chmod", "-1");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "chmod", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "chmod",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  ret_v = 0;
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "chmod");
    fprintf (trace_fp, "%d", ret_v);
    trace_send_line (g);
  }

  return ret_v;
}

int
guestfs_chown (guestfs_h *g,
               int owner,
               int group,
               const char *path)
{
  struct guestfs_chown_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "chown", 5);
  if (path == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "chown", "path");
    return -1;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "chown");
    fprintf (trace_fp, " %d", owner);
    fprintf (trace_fp, " %d", group);
    fprintf (trace_fp, " \"%s\"", path);
    trace_send_line (g);
  }

  if (check_state (g, "chown") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "chown", "-1");
    return -1;
  }
  guestfs___set_busy (g);

  args.owner = owner;
  args.group = group;
  args.path = (char *) path;
  serial = guestfs___send (g, GUESTFS_PROC_CHOWN,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_chown_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "chown", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "chown", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "chown", "-1");
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_CHOWN, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "chown", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "chown", "-1");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "chown", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "chown",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  ret_v = 0;
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "chown");
    fprintf (trace_fp, "%d", ret_v);
    trace_send_line (g);
  }

  return ret_v;
}

int
guestfs_exists (guestfs_h *g,
                const char *path)
{
  struct guestfs_exists_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  struct guestfs_exists_ret ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "exists", 6);
  if (path == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "exists", "path");
    return -1;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "exists");
    fprintf (trace_fp, " \"%s\"", path);
    trace_send_line (g);
  }

  if (check_state (g, "exists") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "exists", "-1");
    return -1;
  }
  guestfs___set_busy (g);

  args.path = (char *) path;
  serial = guestfs___send (g, GUESTFS_PROC_EXISTS,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_exists_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "exists", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs___recv (g, "exists", &hdr, &err,
        (xdrproc_t) xdr_guestfs_exists_ret, (char *) &ret);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "exists", "-1");
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_EXISTS, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "exists", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "exists", "-1");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "exists", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "exists",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  ret_v = ret.existsflag;
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "exists");
    fprintf (trace_fp, "%d", ret_v);
    trace_send_line (g);
  }

  return ret_v;
}

int
guestfs_is_file (guestfs_h *g,
                 const char *path)
{
  struct guestfs_is_file_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  struct guestfs_is_file_ret ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "is_file", 7);
  if (path == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "is_file", "path");
    return -1;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "is_file");
    fprintf (trace_fp, " \"%s\"", path);
    trace_send_line (g);
  }

  if (check_state (g, "is_file") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "is_file", "-1");
    return -1;
  }
  guestfs___set_busy (g);

  args.path = (char *) path;
  serial = guestfs___send (g, GUESTFS_PROC_IS_FILE,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_is_file_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "is_file", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs___recv (g, "is_file", &hdr, &err,
        (xdrproc_t) xdr_guestfs_is_file_ret, (char *) &ret);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "is_file", "-1");
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_IS_FILE, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "is_file", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "is_file", "-1");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "is_file", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "is_file",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  ret_v = ret.fileflag;
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "is_file");
    fprintf (trace_fp, "%d", ret_v);
    trace_send_line (g);
  }

  return ret_v;
}

int
guestfs_is_dir (guestfs_h *g,
                const char *path)
{
  struct guestfs_is_dir_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  struct guestfs_is_dir_ret ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "is_dir", 6);
  if (path == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "is_dir", "path");
    return -1;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "is_dir");
    fprintf (trace_fp, " \"%s\"", path);
    trace_send_line (g);
  }

  if (check_state (g, "is_dir") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "is_dir", "-1");
    return -1;
  }
  guestfs___set_busy (g);

  args.path = (char *) path;
  serial = guestfs___send (g, GUESTFS_PROC_IS_DIR,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_is_dir_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "is_dir", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs___recv (g, "is_dir", &hdr, &err,
        (xdrproc_t) xdr_guestfs_is_dir_ret, (char *) &ret);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "is_dir", "-1");
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_IS_DIR, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "is_dir", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "is_dir", "-1");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "is_dir", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "is_dir",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  ret_v = ret.dirflag;
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "is_dir");
    fprintf (trace_fp, "%d", ret_v);
    trace_send_line (g);
  }

  return ret_v;
}

int
guestfs_pvcreate (guestfs_h *g,
                  const char *device)
{
  struct guestfs_pvcreate_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "pvcreate", 8);
  if (device == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "pvcreate", "device");
    return -1;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "pvcreate");
    fprintf (trace_fp, " \"%s\"", device);
    trace_send_line (g);
  }

  if (check_state (g, "pvcreate") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "pvcreate", "-1");
    return -1;
  }
  guestfs___set_busy (g);

  args.device = (char *) device;
  serial = guestfs___send (g, GUESTFS_PROC_PVCREATE,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_pvcreate_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "pvcreate", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "pvcreate", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "pvcreate", "-1");
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_PVCREATE, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "pvcreate", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "pvcreate", "-1");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "pvcreate", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "pvcreate",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  ret_v = 0;
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "pvcreate");
    fprintf (trace_fp, "%d", ret_v);
    trace_send_line (g);
  }

  return ret_v;
}

int
guestfs_vgcreate (guestfs_h *g,
                  const char *volgroup,
                  char *const *physvols)
{
  struct guestfs_vgcreate_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "vgcreate", 8);
  if (volgroup == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "vgcreate", "volgroup");
    return -1;
  }
  if (physvols == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "vgcreate", "physvols");
    return -1;
  }

  if (trace_flag) {
    size_t i;

    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "vgcreate");
    fprintf (trace_fp, " \"%s\"", volgroup);
    fputc (' ', trace_fp);
    fputc ('"', trace_fp);
    for (i = 0; physvols[i]; ++i) {
      if (i > 0) fputc (' ', trace_fp);
      fputs (physvols[i], trace_fp);
    }
    fputc ('"', trace_fp);
    trace_send_line (g);
  }

  if (check_state (g, "vgcreate") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "vgcreate", "-1");
    return -1;
  }
  guestfs___set_busy (g);

  args.volgroup = (char *) volgroup;
  args.physvols.physvols_val = (char **) physvols;
  for (args.physvols.physvols_len = 0; physvols[args.physvols.physvols_len]; args.physvols.physvols_len++) ;
  serial = guestfs___send (g, GUESTFS_PROC_VGCREATE,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_vgcreate_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "vgcreate", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "vgcreate", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "vgcreate", "-1");
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_VGCREATE, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "vgcreate", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "vgcreate", "-1");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "vgcreate", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "vgcreate",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  ret_v = 0;
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "vgcreate");
    fprintf (trace_fp, "%d", ret_v);
    trace_send_line (g);
  }

  return ret_v;
}

int
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
  FILE *trace_fp;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
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
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "lvcreate");
    fprintf (trace_fp, " \"%s\"", logvol);
    fprintf (trace_fp, " \"%s\"", volgroup);
    fprintf (trace_fp, " %d", mbytes);
    trace_send_line (g);
  }

  if (check_state (g, "lvcreate") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "lvcreate", "-1");
    return -1;
  }
  guestfs___set_busy (g);

  args.logvol = (char *) logvol;
  args.volgroup = (char *) volgroup;
  args.mbytes = mbytes;
  serial = guestfs___send (g, GUESTFS_PROC_LVCREATE,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_lvcreate_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "lvcreate", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "lvcreate", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "lvcreate", "-1");
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_LVCREATE, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "lvcreate", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "lvcreate", "-1");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "lvcreate", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "lvcreate",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  ret_v = 0;
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "lvcreate");
    fprintf (trace_fp, "%d", ret_v);
    trace_send_line (g);
  }

  return ret_v;
}

int
guestfs_mkfs (guestfs_h *g,
              const char *fstype,
              const char *device)
{
  struct guestfs_mkfs_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "mkfs", 4);
  if (fstype == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "mkfs", "fstype");
    return -1;
  }
  if (device == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "mkfs", "device");
    return -1;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "mkfs");
    fprintf (trace_fp, " \"%s\"", fstype);
    fprintf (trace_fp, " \"%s\"", device);
    trace_send_line (g);
  }

  if (check_state (g, "mkfs") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mkfs", "-1");
    return -1;
  }
  guestfs___set_busy (g);

  args.fstype = (char *) fstype;
  args.device = (char *) device;
  serial = guestfs___send (g, GUESTFS_PROC_MKFS,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_mkfs_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mkfs", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "mkfs", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mkfs", "-1");
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_MKFS, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mkfs", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mkfs", "-1");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "mkfs", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "mkfs",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  ret_v = 0;
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "mkfs");
    fprintf (trace_fp, "%d", ret_v);
    trace_send_line (g);
  }

  return ret_v;
}

int
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
  FILE *trace_fp;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
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

    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "sfdisk");
    fprintf (trace_fp, " \"%s\"", device);
    fprintf (trace_fp, " %d", cyls);
    fprintf (trace_fp, " %d", heads);
    fprintf (trace_fp, " %d", sectors);
    fputc (' ', trace_fp);
    fputc ('"', trace_fp);
    for (i = 0; lines[i]; ++i) {
      if (i > 0) fputc (' ', trace_fp);
      fputs (lines[i], trace_fp);
    }
    fputc ('"', trace_fp);
    trace_send_line (g);
  }

  if (check_state (g, "sfdisk") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "sfdisk", "-1");
    return -1;
  }
  guestfs___set_busy (g);

  args.device = (char *) device;
  args.cyls = cyls;
  args.heads = heads;
  args.sectors = sectors;
  args.lines.lines_val = (char **) lines;
  for (args.lines.lines_len = 0; lines[args.lines.lines_len]; args.lines.lines_len++) ;
  serial = guestfs___send (g, GUESTFS_PROC_SFDISK,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_sfdisk_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "sfdisk", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "sfdisk", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "sfdisk", "-1");
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_SFDISK, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "sfdisk", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "sfdisk", "-1");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "sfdisk", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "sfdisk",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  ret_v = 0;
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "sfdisk");
    fprintf (trace_fp, "%d", ret_v);
    trace_send_line (g);
  }

  return ret_v;
}

int
guestfs_write_file (guestfs_h *g,
                    const char *path,
                    const char *content,
                    int size)
{
  struct guestfs_write_file_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "write_file", 10);
  if (path == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "write_file", "path");
    return -1;
  }
  if (content == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "write_file", "content");
    return -1;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "write_file");
    fprintf (trace_fp, " \"%s\"", path);
    fprintf (trace_fp, " \"%s\"", content);
    fprintf (trace_fp, " %d", size);
    trace_send_line (g);
  }

  if (check_state (g, "write_file") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "write_file", "-1");
    return -1;
  }
  guestfs___set_busy (g);

  args.path = (char *) path;
  args.content = (char *) content;
  args.size = size;
  serial = guestfs___send (g, GUESTFS_PROC_WRITE_FILE,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_write_file_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "write_file", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "write_file", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "write_file", "-1");
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_WRITE_FILE, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "write_file", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "write_file", "-1");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "write_file", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "write_file",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  ret_v = 0;
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "write_file");
    fprintf (trace_fp, "%d", ret_v);
    trace_send_line (g);
  }

  return ret_v;
}

int
guestfs_umount (guestfs_h *g,
                const char *pathordevice)
{
  struct guestfs_umount_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "umount", 6);
  if (pathordevice == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "umount", "pathordevice");
    return -1;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "umount");
    fprintf (trace_fp, " \"%s\"", pathordevice);
    trace_send_line (g);
  }

  if (check_state (g, "umount") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "umount", "-1");
    return -1;
  }
  guestfs___set_busy (g);

  args.pathordevice = (char *) pathordevice;
  serial = guestfs___send (g, GUESTFS_PROC_UMOUNT,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_umount_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "umount", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "umount", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "umount", "-1");
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_UMOUNT, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "umount", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "umount", "-1");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "umount", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "umount",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  ret_v = 0;
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "umount");
    fprintf (trace_fp, "%d", ret_v);
    trace_send_line (g);
  }

  return ret_v;
}

char **
guestfs_mounts (guestfs_h *g)
{
  guestfs_message_header hdr;
  guestfs_message_error err;
  struct guestfs_mounts_ret ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  char **ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "mounts", 6);
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "mounts");
    trace_send_line (g);
  }

  if (check_state (g, "mounts") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mounts", "NULL");
    return NULL;
  }
  guestfs___set_busy (g);

  serial = guestfs___send (g, GUESTFS_PROC_MOUNTS, progress_hint, 0,
                           NULL, NULL);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mounts", "NULL");
    return NULL;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs___recv (g, "mounts", &hdr, &err,
        (xdrproc_t) xdr_guestfs_mounts_ret, (char *) &ret);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mounts", "NULL");
    return NULL;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_MOUNTS, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mounts", "NULL");
    return NULL;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mounts", "NULL");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "mounts", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "mounts",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return NULL;
  }

  guestfs___end_busy (g);
  /* caller will free this, but we need to add a NULL entry */
  ret.devices.devices_val =
    safe_realloc (g, ret.devices.devices_val,
                  sizeof (char *) * (ret.devices.devices_len + 1));
  ret.devices.devices_val[ret.devices.devices_len] = NULL;
  ret_v = ret.devices.devices_val;
  if (trace_flag) {
    size_t i;

    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "mounts");
    fputs ("[", trace_fp);
    for (i = 0; ret_v[i]; ++i) {
      if (i > 0) fputs (", ", trace_fp);
      fputs ("\"", trace_fp);
      fputs (ret_v[i], trace_fp);
      fputs ("\"", trace_fp);
    }
    fputs ("]", trace_fp);
    trace_send_line (g);
  }

  return ret_v;
}

int
guestfs_umount_all (guestfs_h *g)
{
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "umount_all", 10);
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "umount_all");
    trace_send_line (g);
  }

  if (check_state (g, "umount_all") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "umount_all", "-1");
    return -1;
  }
  guestfs___set_busy (g);

  serial = guestfs___send (g, GUESTFS_PROC_UMOUNT_ALL, progress_hint, 0,
                           NULL, NULL);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "umount_all", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "umount_all", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "umount_all", "-1");
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_UMOUNT_ALL, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "umount_all", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "umount_all", "-1");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "umount_all", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "umount_all",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  ret_v = 0;
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "umount_all");
    fprintf (trace_fp, "%d", ret_v);
    trace_send_line (g);
  }

  return ret_v;
}

int
guestfs_lvm_remove_all (guestfs_h *g)
{
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "lvm_remove_all", 14);
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "lvm_remove_all");
    trace_send_line (g);
  }

  if (check_state (g, "lvm_remove_all") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "lvm_remove_all", "-1");
    return -1;
  }
  guestfs___set_busy (g);

  serial = guestfs___send (g, GUESTFS_PROC_LVM_REMOVE_ALL, progress_hint, 0,
                           NULL, NULL);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "lvm_remove_all", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "lvm_remove_all", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "lvm_remove_all", "-1");
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_LVM_REMOVE_ALL, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "lvm_remove_all", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "lvm_remove_all", "-1");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "lvm_remove_all", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "lvm_remove_all",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  ret_v = 0;
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "lvm_remove_all");
    fprintf (trace_fp, "%d", ret_v);
    trace_send_line (g);
  }

  return ret_v;
}

char *
guestfs_file (guestfs_h *g,
              const char *path)
{
  struct guestfs_file_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  struct guestfs_file_ret ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  char *ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "file", 4);
  if (path == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "file", "path");
    return NULL;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "file");
    fprintf (trace_fp, " \"%s\"", path);
    trace_send_line (g);
  }

  if (check_state (g, "file") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "file", "NULL");
    return NULL;
  }
  guestfs___set_busy (g);

  args.path = (char *) path;
  serial = guestfs___send (g, GUESTFS_PROC_FILE,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_file_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "file", "NULL");
    return NULL;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs___recv (g, "file", &hdr, &err,
        (xdrproc_t) xdr_guestfs_file_ret, (char *) &ret);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "file", "NULL");
    return NULL;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_FILE, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "file", "NULL");
    return NULL;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "file", "NULL");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "file", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "file",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return NULL;
  }

  guestfs___end_busy (g);
  ret_v = ret.description; /* caller will free */
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "file");
    fprintf (trace_fp, "\"%s\"", ret_v);
    trace_send_line (g);
  }

  return ret_v;
}

char *
guestfs_command (guestfs_h *g,
                 char *const *arguments)
{
  struct guestfs_command_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  struct guestfs_command_ret ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  char *ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "command", 7);
  if (arguments == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "command", "arguments");
    return NULL;
  }

  if (trace_flag) {
    size_t i;

    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "command");
    fputc (' ', trace_fp);
    fputc ('"', trace_fp);
    for (i = 0; arguments[i]; ++i) {
      if (i > 0) fputc (' ', trace_fp);
      fputs (arguments[i], trace_fp);
    }
    fputc ('"', trace_fp);
    trace_send_line (g);
  }

  if (check_state (g, "command") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "command", "NULL");
    return NULL;
  }
  guestfs___set_busy (g);

  args.arguments.arguments_val = (char **) arguments;
  for (args.arguments.arguments_len = 0; arguments[args.arguments.arguments_len]; args.arguments.arguments_len++) ;
  serial = guestfs___send (g, GUESTFS_PROC_COMMAND,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_command_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "command", "NULL");
    return NULL;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs___recv (g, "command", &hdr, &err,
        (xdrproc_t) xdr_guestfs_command_ret, (char *) &ret);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "command", "NULL");
    return NULL;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_COMMAND, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "command", "NULL");
    return NULL;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "command", "NULL");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "command", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "command",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return NULL;
  }

  guestfs___end_busy (g);
  ret_v = ret.output; /* caller will free */
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "command");
    fprintf (trace_fp, "\"%s\"", ret_v);
    trace_send_line (g);
  }

  return ret_v;
}

char **
guestfs_command_lines (guestfs_h *g,
                       char *const *arguments)
{
  struct guestfs_command_lines_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  struct guestfs_command_lines_ret ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  char **ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "command_lines", 13);
  if (arguments == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "command_lines", "arguments");
    return NULL;
  }

  if (trace_flag) {
    size_t i;

    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "command_lines");
    fputc (' ', trace_fp);
    fputc ('"', trace_fp);
    for (i = 0; arguments[i]; ++i) {
      if (i > 0) fputc (' ', trace_fp);
      fputs (arguments[i], trace_fp);
    }
    fputc ('"', trace_fp);
    trace_send_line (g);
  }

  if (check_state (g, "command_lines") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "command_lines", "NULL");
    return NULL;
  }
  guestfs___set_busy (g);

  args.arguments.arguments_val = (char **) arguments;
  for (args.arguments.arguments_len = 0; arguments[args.arguments.arguments_len]; args.arguments.arguments_len++) ;
  serial = guestfs___send (g, GUESTFS_PROC_COMMAND_LINES,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_command_lines_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "command_lines", "NULL");
    return NULL;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs___recv (g, "command_lines", &hdr, &err,
        (xdrproc_t) xdr_guestfs_command_lines_ret, (char *) &ret);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "command_lines", "NULL");
    return NULL;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_COMMAND_LINES, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "command_lines", "NULL");
    return NULL;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "command_lines", "NULL");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "command_lines", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "command_lines",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return NULL;
  }

  guestfs___end_busy (g);
  /* caller will free this, but we need to add a NULL entry */
  ret.lines.lines_val =
    safe_realloc (g, ret.lines.lines_val,
                  sizeof (char *) * (ret.lines.lines_len + 1));
  ret.lines.lines_val[ret.lines.lines_len] = NULL;
  ret_v = ret.lines.lines_val;
  if (trace_flag) {
    size_t i;

    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "command_lines");
    fputs ("[", trace_fp);
    for (i = 0; ret_v[i]; ++i) {
      if (i > 0) fputs (", ", trace_fp);
      fputs ("\"", trace_fp);
      fputs (ret_v[i], trace_fp);
      fputs ("\"", trace_fp);
    }
    fputs ("]", trace_fp);
    trace_send_line (g);
  }

  return ret_v;
}

struct guestfs_stat *
guestfs_stat (guestfs_h *g,
              const char *path)
{
  struct guestfs_stat_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  struct guestfs_stat_ret ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  struct guestfs_stat *ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "stat", 4);
  if (path == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "stat", "path");
    return NULL;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "stat");
    fprintf (trace_fp, " \"%s\"", path);
    trace_send_line (g);
  }

  if (check_state (g, "stat") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "stat", "NULL");
    return NULL;
  }
  guestfs___set_busy (g);

  args.path = (char *) path;
  serial = guestfs___send (g, GUESTFS_PROC_STAT,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_stat_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "stat", "NULL");
    return NULL;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs___recv (g, "stat", &hdr, &err,
        (xdrproc_t) xdr_guestfs_stat_ret, (char *) &ret);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "stat", "NULL");
    return NULL;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_STAT, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "stat", "NULL");
    return NULL;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "stat", "NULL");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "stat", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "stat",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return NULL;
  }

  guestfs___end_busy (g);
  /* caller will free this */
  ret_v = safe_memdup (g, &ret.statbuf, sizeof (ret.statbuf));
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "stat");
    fprintf (trace_fp, "<struct guestfs_stat *>");
    trace_send_line (g);
  }

  return ret_v;
}

struct guestfs_stat *
guestfs_lstat (guestfs_h *g,
               const char *path)
{
  struct guestfs_lstat_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  struct guestfs_lstat_ret ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  struct guestfs_stat *ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "lstat", 5);
  if (path == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "lstat", "path");
    return NULL;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "lstat");
    fprintf (trace_fp, " \"%s\"", path);
    trace_send_line (g);
  }

  if (check_state (g, "lstat") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "lstat", "NULL");
    return NULL;
  }
  guestfs___set_busy (g);

  args.path = (char *) path;
  serial = guestfs___send (g, GUESTFS_PROC_LSTAT,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_lstat_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "lstat", "NULL");
    return NULL;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs___recv (g, "lstat", &hdr, &err,
        (xdrproc_t) xdr_guestfs_lstat_ret, (char *) &ret);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "lstat", "NULL");
    return NULL;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_LSTAT, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "lstat", "NULL");
    return NULL;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "lstat", "NULL");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "lstat", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "lstat",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return NULL;
  }

  guestfs___end_busy (g);
  /* caller will free this */
  ret_v = safe_memdup (g, &ret.statbuf, sizeof (ret.statbuf));
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "lstat");
    fprintf (trace_fp, "<struct guestfs_stat *>");
    trace_send_line (g);
  }

  return ret_v;
}

struct guestfs_statvfs *
guestfs_statvfs (guestfs_h *g,
                 const char *path)
{
  struct guestfs_statvfs_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  struct guestfs_statvfs_ret ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  struct guestfs_statvfs *ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "statvfs", 7);
  if (path == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "statvfs", "path");
    return NULL;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "statvfs");
    fprintf (trace_fp, " \"%s\"", path);
    trace_send_line (g);
  }

  if (check_state (g, "statvfs") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "statvfs", "NULL");
    return NULL;
  }
  guestfs___set_busy (g);

  args.path = (char *) path;
  serial = guestfs___send (g, GUESTFS_PROC_STATVFS,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_statvfs_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "statvfs", "NULL");
    return NULL;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs___recv (g, "statvfs", &hdr, &err,
        (xdrproc_t) xdr_guestfs_statvfs_ret, (char *) &ret);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "statvfs", "NULL");
    return NULL;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_STATVFS, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "statvfs", "NULL");
    return NULL;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "statvfs", "NULL");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "statvfs", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "statvfs",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return NULL;
  }

  guestfs___end_busy (g);
  /* caller will free this */
  ret_v = safe_memdup (g, &ret.statbuf, sizeof (ret.statbuf));
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "statvfs");
    fprintf (trace_fp, "<struct guestfs_statvfs *>");
    trace_send_line (g);
  }

  return ret_v;
}

char **
guestfs_tune2fs_l (guestfs_h *g,
                   const char *device)
{
  struct guestfs_tune2fs_l_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  struct guestfs_tune2fs_l_ret ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  char **ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "tune2fs_l", 9);
  if (device == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "tune2fs_l", "device");
    return NULL;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "tune2fs_l");
    fprintf (trace_fp, " \"%s\"", device);
    trace_send_line (g);
  }

  if (check_state (g, "tune2fs_l") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "tune2fs_l", "NULL");
    return NULL;
  }
  guestfs___set_busy (g);

  args.device = (char *) device;
  serial = guestfs___send (g, GUESTFS_PROC_TUNE2FS_L,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_tune2fs_l_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "tune2fs_l", "NULL");
    return NULL;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs___recv (g, "tune2fs_l", &hdr, &err,
        (xdrproc_t) xdr_guestfs_tune2fs_l_ret, (char *) &ret);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "tune2fs_l", "NULL");
    return NULL;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_TUNE2FS_L, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "tune2fs_l", "NULL");
    return NULL;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "tune2fs_l", "NULL");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "tune2fs_l", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "tune2fs_l",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return NULL;
  }

  guestfs___end_busy (g);
  /* caller will free this, but we need to add a NULL entry */
  ret.superblock.superblock_val =
    safe_realloc (g, ret.superblock.superblock_val,
                  sizeof (char *) * (ret.superblock.superblock_len + 1));
  ret.superblock.superblock_val[ret.superblock.superblock_len] = NULL;
  ret_v = ret.superblock.superblock_val;
  if (trace_flag) {
    size_t i;

    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "tune2fs_l");
    fputs ("[", trace_fp);
    for (i = 0; ret_v[i]; ++i) {
      if (i > 0) fputs (", ", trace_fp);
      fputs ("\"", trace_fp);
      fputs (ret_v[i], trace_fp);
      fputs ("\"", trace_fp);
    }
    fputs ("]", trace_fp);
    trace_send_line (g);
  }

  return ret_v;
}

int
guestfs_blockdev_setro (guestfs_h *g,
                        const char *device)
{
  struct guestfs_blockdev_setro_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "blockdev_setro", 14);
  if (device == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "blockdev_setro", "device");
    return -1;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "blockdev_setro");
    fprintf (trace_fp, " \"%s\"", device);
    trace_send_line (g);
  }

  if (check_state (g, "blockdev_setro") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "blockdev_setro", "-1");
    return -1;
  }
  guestfs___set_busy (g);

  args.device = (char *) device;
  serial = guestfs___send (g, GUESTFS_PROC_BLOCKDEV_SETRO,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_blockdev_setro_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "blockdev_setro", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "blockdev_setro", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "blockdev_setro", "-1");
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_BLOCKDEV_SETRO, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "blockdev_setro", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "blockdev_setro", "-1");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "blockdev_setro", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "blockdev_setro",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  ret_v = 0;
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "blockdev_setro");
    fprintf (trace_fp, "%d", ret_v);
    trace_send_line (g);
  }

  return ret_v;
}

int
guestfs_blockdev_setrw (guestfs_h *g,
                        const char *device)
{
  struct guestfs_blockdev_setrw_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "blockdev_setrw", 14);
  if (device == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "blockdev_setrw", "device");
    return -1;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "blockdev_setrw");
    fprintf (trace_fp, " \"%s\"", device);
    trace_send_line (g);
  }

  if (check_state (g, "blockdev_setrw") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "blockdev_setrw", "-1");
    return -1;
  }
  guestfs___set_busy (g);

  args.device = (char *) device;
  serial = guestfs___send (g, GUESTFS_PROC_BLOCKDEV_SETRW,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_blockdev_setrw_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "blockdev_setrw", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "blockdev_setrw", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "blockdev_setrw", "-1");
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_BLOCKDEV_SETRW, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "blockdev_setrw", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "blockdev_setrw", "-1");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "blockdev_setrw", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "blockdev_setrw",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  ret_v = 0;
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "blockdev_setrw");
    fprintf (trace_fp, "%d", ret_v);
    trace_send_line (g);
  }

  return ret_v;
}

int
guestfs_blockdev_getro (guestfs_h *g,
                        const char *device)
{
  struct guestfs_blockdev_getro_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  struct guestfs_blockdev_getro_ret ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "blockdev_getro", 14);
  if (device == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "blockdev_getro", "device");
    return -1;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "blockdev_getro");
    fprintf (trace_fp, " \"%s\"", device);
    trace_send_line (g);
  }

  if (check_state (g, "blockdev_getro") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "blockdev_getro", "-1");
    return -1;
  }
  guestfs___set_busy (g);

  args.device = (char *) device;
  serial = guestfs___send (g, GUESTFS_PROC_BLOCKDEV_GETRO,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_blockdev_getro_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "blockdev_getro", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs___recv (g, "blockdev_getro", &hdr, &err,
        (xdrproc_t) xdr_guestfs_blockdev_getro_ret, (char *) &ret);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "blockdev_getro", "-1");
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_BLOCKDEV_GETRO, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "blockdev_getro", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "blockdev_getro", "-1");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "blockdev_getro", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "blockdev_getro",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  ret_v = ret.ro;
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "blockdev_getro");
    fprintf (trace_fp, "%d", ret_v);
    trace_send_line (g);
  }

  return ret_v;
}

int
guestfs_blockdev_getss (guestfs_h *g,
                        const char *device)
{
  struct guestfs_blockdev_getss_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  struct guestfs_blockdev_getss_ret ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "blockdev_getss", 14);
  if (device == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "blockdev_getss", "device");
    return -1;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "blockdev_getss");
    fprintf (trace_fp, " \"%s\"", device);
    trace_send_line (g);
  }

  if (check_state (g, "blockdev_getss") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "blockdev_getss", "-1");
    return -1;
  }
  guestfs___set_busy (g);

  args.device = (char *) device;
  serial = guestfs___send (g, GUESTFS_PROC_BLOCKDEV_GETSS,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_blockdev_getss_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "blockdev_getss", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs___recv (g, "blockdev_getss", &hdr, &err,
        (xdrproc_t) xdr_guestfs_blockdev_getss_ret, (char *) &ret);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "blockdev_getss", "-1");
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_BLOCKDEV_GETSS, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "blockdev_getss", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "blockdev_getss", "-1");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "blockdev_getss", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "blockdev_getss",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  ret_v = ret.sectorsize;
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "blockdev_getss");
    fprintf (trace_fp, "%d", ret_v);
    trace_send_line (g);
  }

  return ret_v;
}

int
guestfs_blockdev_getbsz (guestfs_h *g,
                         const char *device)
{
  struct guestfs_blockdev_getbsz_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  struct guestfs_blockdev_getbsz_ret ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "blockdev_getbsz", 15);
  if (device == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "blockdev_getbsz", "device");
    return -1;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "blockdev_getbsz");
    fprintf (trace_fp, " \"%s\"", device);
    trace_send_line (g);
  }

  if (check_state (g, "blockdev_getbsz") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "blockdev_getbsz", "-1");
    return -1;
  }
  guestfs___set_busy (g);

  args.device = (char *) device;
  serial = guestfs___send (g, GUESTFS_PROC_BLOCKDEV_GETBSZ,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_blockdev_getbsz_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "blockdev_getbsz", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs___recv (g, "blockdev_getbsz", &hdr, &err,
        (xdrproc_t) xdr_guestfs_blockdev_getbsz_ret, (char *) &ret);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "blockdev_getbsz", "-1");
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_BLOCKDEV_GETBSZ, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "blockdev_getbsz", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "blockdev_getbsz", "-1");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "blockdev_getbsz", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "blockdev_getbsz",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  ret_v = ret.blocksize;
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "blockdev_getbsz");
    fprintf (trace_fp, "%d", ret_v);
    trace_send_line (g);
  }

  return ret_v;
}

int
guestfs_blockdev_setbsz (guestfs_h *g,
                         const char *device,
                         int blocksize)
{
  struct guestfs_blockdev_setbsz_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "blockdev_setbsz", 15);
  if (device == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "blockdev_setbsz", "device");
    return -1;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "blockdev_setbsz");
    fprintf (trace_fp, " \"%s\"", device);
    fprintf (trace_fp, " %d", blocksize);
    trace_send_line (g);
  }

  if (check_state (g, "blockdev_setbsz") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "blockdev_setbsz", "-1");
    return -1;
  }
  guestfs___set_busy (g);

  args.device = (char *) device;
  args.blocksize = blocksize;
  serial = guestfs___send (g, GUESTFS_PROC_BLOCKDEV_SETBSZ,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_blockdev_setbsz_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "blockdev_setbsz", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "blockdev_setbsz", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "blockdev_setbsz", "-1");
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_BLOCKDEV_SETBSZ, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "blockdev_setbsz", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "blockdev_setbsz", "-1");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "blockdev_setbsz", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "blockdev_setbsz",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  ret_v = 0;
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "blockdev_setbsz");
    fprintf (trace_fp, "%d", ret_v);
    trace_send_line (g);
  }

  return ret_v;
}

int64_t
guestfs_blockdev_getsz (guestfs_h *g,
                        const char *device)
{
  struct guestfs_blockdev_getsz_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  struct guestfs_blockdev_getsz_ret ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  int64_t ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "blockdev_getsz", 14);
  if (device == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "blockdev_getsz", "device");
    return -1;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "blockdev_getsz");
    fprintf (trace_fp, " \"%s\"", device);
    trace_send_line (g);
  }

  if (check_state (g, "blockdev_getsz") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "blockdev_getsz", "-1");
    return -1;
  }
  guestfs___set_busy (g);

  args.device = (char *) device;
  serial = guestfs___send (g, GUESTFS_PROC_BLOCKDEV_GETSZ,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_blockdev_getsz_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "blockdev_getsz", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs___recv (g, "blockdev_getsz", &hdr, &err,
        (xdrproc_t) xdr_guestfs_blockdev_getsz_ret, (char *) &ret);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "blockdev_getsz", "-1");
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_BLOCKDEV_GETSZ, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "blockdev_getsz", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "blockdev_getsz", "-1");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "blockdev_getsz", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "blockdev_getsz",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  ret_v = ret.sizeinsectors;
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "blockdev_getsz");
    fprintf (trace_fp, "%" PRIi64, ret_v);
    trace_send_line (g);
  }

  return ret_v;
}

int64_t
guestfs_blockdev_getsize64 (guestfs_h *g,
                            const char *device)
{
  struct guestfs_blockdev_getsize64_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  struct guestfs_blockdev_getsize64_ret ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  int64_t ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "blockdev_getsize64", 18);
  if (device == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "blockdev_getsize64", "device");
    return -1;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "blockdev_getsize64");
    fprintf (trace_fp, " \"%s\"", device);
    trace_send_line (g);
  }

  if (check_state (g, "blockdev_getsize64") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "blockdev_getsize64", "-1");
    return -1;
  }
  guestfs___set_busy (g);

  args.device = (char *) device;
  serial = guestfs___send (g, GUESTFS_PROC_BLOCKDEV_GETSIZE64,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_blockdev_getsize64_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "blockdev_getsize64", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs___recv (g, "blockdev_getsize64", &hdr, &err,
        (xdrproc_t) xdr_guestfs_blockdev_getsize64_ret, (char *) &ret);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "blockdev_getsize64", "-1");
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_BLOCKDEV_GETSIZE64, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "blockdev_getsize64", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "blockdev_getsize64", "-1");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "blockdev_getsize64", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "blockdev_getsize64",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  ret_v = ret.sizeinbytes;
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "blockdev_getsize64");
    fprintf (trace_fp, "%" PRIi64, ret_v);
    trace_send_line (g);
  }

  return ret_v;
}

int
guestfs_blockdev_flushbufs (guestfs_h *g,
                            const char *device)
{
  struct guestfs_blockdev_flushbufs_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "blockdev_flushbufs", 18);
  if (device == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "blockdev_flushbufs", "device");
    return -1;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "blockdev_flushbufs");
    fprintf (trace_fp, " \"%s\"", device);
    trace_send_line (g);
  }

  if (check_state (g, "blockdev_flushbufs") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "blockdev_flushbufs", "-1");
    return -1;
  }
  guestfs___set_busy (g);

  args.device = (char *) device;
  serial = guestfs___send (g, GUESTFS_PROC_BLOCKDEV_FLUSHBUFS,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_blockdev_flushbufs_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "blockdev_flushbufs", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "blockdev_flushbufs", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "blockdev_flushbufs", "-1");
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_BLOCKDEV_FLUSHBUFS, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "blockdev_flushbufs", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "blockdev_flushbufs", "-1");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "blockdev_flushbufs", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "blockdev_flushbufs",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  ret_v = 0;
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "blockdev_flushbufs");
    fprintf (trace_fp, "%d", ret_v);
    trace_send_line (g);
  }

  return ret_v;
}

int
guestfs_blockdev_rereadpt (guestfs_h *g,
                           const char *device)
{
  struct guestfs_blockdev_rereadpt_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "blockdev_rereadpt", 17);
  if (device == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "blockdev_rereadpt", "device");
    return -1;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "blockdev_rereadpt");
    fprintf (trace_fp, " \"%s\"", device);
    trace_send_line (g);
  }

  if (check_state (g, "blockdev_rereadpt") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "blockdev_rereadpt", "-1");
    return -1;
  }
  guestfs___set_busy (g);

  args.device = (char *) device;
  serial = guestfs___send (g, GUESTFS_PROC_BLOCKDEV_REREADPT,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_blockdev_rereadpt_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "blockdev_rereadpt", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "blockdev_rereadpt", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "blockdev_rereadpt", "-1");
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_BLOCKDEV_REREADPT, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "blockdev_rereadpt", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "blockdev_rereadpt", "-1");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "blockdev_rereadpt", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "blockdev_rereadpt",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  ret_v = 0;
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "blockdev_rereadpt");
    fprintf (trace_fp, "%d", ret_v);
    trace_send_line (g);
  }

  return ret_v;
}

int
guestfs_upload (guestfs_h *g,
                const char *filename,
                const char *remotefilename)
{
  struct guestfs_upload_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  int ret_v;
  uint64_t progress_hint = 0;
  struct stat progress_stat;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "upload", 6);
  if (filename == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "upload", "filename");
    return -1;
  }
  if (remotefilename == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "upload", "remotefilename");
    return -1;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "upload");
    fprintf (trace_fp, " \"%s\"", filename);
    fprintf (trace_fp, " \"%s\"", remotefilename);
    trace_send_line (g);
  }

  if (stat (filename, &progress_stat) == 0 &&
      S_ISREG (progress_stat.st_mode))
    progress_hint += progress_stat.st_size;

  if (check_state (g, "upload") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "upload", "-1");
    return -1;
  }
  guestfs___set_busy (g);

  args.remotefilename = (char *) remotefilename;
  serial = guestfs___send (g, GUESTFS_PROC_UPLOAD,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_upload_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "upload", "-1");
    return -1;
  }

  r = guestfs___send_file (g, filename);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "upload", "-1");
    /* daemon will send an error reply which we discard */
    guestfs___recv_discard (g, "upload");
    return -1;
  }
  if (r == -2) /* daemon cancelled */
    goto read_reply;

 read_reply:
  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "upload", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "upload", "-1");
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_UPLOAD, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "upload", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "upload", "-1");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "upload", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "upload",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  ret_v = 0;
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "upload");
    fprintf (trace_fp, "%d", ret_v);
    trace_send_line (g);
  }

  return ret_v;
}

int
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
  FILE *trace_fp;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
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
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "download");
    fprintf (trace_fp, " \"%s\"", remotefilename);
    fprintf (trace_fp, " \"%s\"", filename);
    trace_send_line (g);
  }

  if (check_state (g, "download") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "download", "-1");
    return -1;
  }
  guestfs___set_busy (g);

  args.remotefilename = (char *) remotefilename;
  serial = guestfs___send (g, GUESTFS_PROC_DOWNLOAD,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_download_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "download", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "download", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "download", "-1");
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_DOWNLOAD, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "download", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "download", "-1");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "download", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "download",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return -1;
  }

  if (guestfs___recv_file (g, filename) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "download", "-1");
    return -1;
  }

  guestfs___end_busy (g);
  ret_v = 0;
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "download");
    fprintf (trace_fp, "%d", ret_v);
    trace_send_line (g);
  }

  return ret_v;
}

char *
guestfs_checksum (guestfs_h *g,
                  const char *csumtype,
                  const char *path)
{
  struct guestfs_checksum_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  struct guestfs_checksum_ret ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  char *ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "checksum", 8);
  if (csumtype == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "checksum", "csumtype");
    return NULL;
  }
  if (path == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "checksum", "path");
    return NULL;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "checksum");
    fprintf (trace_fp, " \"%s\"", csumtype);
    fprintf (trace_fp, " \"%s\"", path);
    trace_send_line (g);
  }

  if (check_state (g, "checksum") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "checksum", "NULL");
    return NULL;
  }
  guestfs___set_busy (g);

  args.csumtype = (char *) csumtype;
  args.path = (char *) path;
  serial = guestfs___send (g, GUESTFS_PROC_CHECKSUM,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_checksum_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "checksum", "NULL");
    return NULL;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs___recv (g, "checksum", &hdr, &err,
        (xdrproc_t) xdr_guestfs_checksum_ret, (char *) &ret);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "checksum", "NULL");
    return NULL;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_CHECKSUM, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "checksum", "NULL");
    return NULL;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "checksum", "NULL");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "checksum", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "checksum",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return NULL;
  }

  guestfs___end_busy (g);
  ret_v = ret.checksum; /* caller will free */
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "checksum");
    fprintf (trace_fp, "\"%s\"", ret_v);
    trace_send_line (g);
  }

  return ret_v;
}

int
guestfs_tar_in (guestfs_h *g,
                const char *tarfile,
                const char *directory)
{
  struct guestfs_tar_in_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  int ret_v;
  uint64_t progress_hint = 0;
  struct stat progress_stat;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "tar_in", 6);
  if (tarfile == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "tar_in", "tarfile");
    return -1;
  }
  if (directory == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "tar_in", "directory");
    return -1;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "tar_in");
    fprintf (trace_fp, " \"%s\"", tarfile);
    fprintf (trace_fp, " \"%s\"", directory);
    trace_send_line (g);
  }

  if (stat (tarfile, &progress_stat) == 0 &&
      S_ISREG (progress_stat.st_mode))
    progress_hint += progress_stat.st_size;

  if (check_state (g, "tar_in") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "tar_in", "-1");
    return -1;
  }
  guestfs___set_busy (g);

  args.directory = (char *) directory;
  serial = guestfs___send (g, GUESTFS_PROC_TAR_IN,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_tar_in_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "tar_in", "-1");
    return -1;
  }

  r = guestfs___send_file (g, tarfile);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "tar_in", "-1");
    /* daemon will send an error reply which we discard */
    guestfs___recv_discard (g, "tar_in");
    return -1;
  }
  if (r == -2) /* daemon cancelled */
    goto read_reply;

 read_reply:
  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "tar_in", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "tar_in", "-1");
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_TAR_IN, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "tar_in", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "tar_in", "-1");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "tar_in", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "tar_in",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  ret_v = 0;
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "tar_in");
    fprintf (trace_fp, "%d", ret_v);
    trace_send_line (g);
  }

  return ret_v;
}

int
guestfs_tar_out (guestfs_h *g,
                 const char *directory,
                 const char *tarfile)
{
  struct guestfs_tar_out_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "tar_out", 7);
  if (directory == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "tar_out", "directory");
    return -1;
  }
  if (tarfile == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "tar_out", "tarfile");
    return -1;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "tar_out");
    fprintf (trace_fp, " \"%s\"", directory);
    fprintf (trace_fp, " \"%s\"", tarfile);
    trace_send_line (g);
  }

  if (check_state (g, "tar_out") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "tar_out", "-1");
    return -1;
  }
  guestfs___set_busy (g);

  args.directory = (char *) directory;
  serial = guestfs___send (g, GUESTFS_PROC_TAR_OUT,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_tar_out_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "tar_out", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "tar_out", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "tar_out", "-1");
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_TAR_OUT, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "tar_out", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "tar_out", "-1");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "tar_out", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "tar_out",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return -1;
  }

  if (guestfs___recv_file (g, tarfile) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "tar_out", "-1");
    return -1;
  }

  guestfs___end_busy (g);
  ret_v = 0;
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "tar_out");
    fprintf (trace_fp, "%d", ret_v);
    trace_send_line (g);
  }

  return ret_v;
}

int
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
  FILE *trace_fp;
  int ret_v;
  uint64_t progress_hint = 0;
  struct stat progress_stat;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
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
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "tgz_in");
    fprintf (trace_fp, " \"%s\"", tarball);
    fprintf (trace_fp, " \"%s\"", directory);
    trace_send_line (g);
  }

  if (stat (tarball, &progress_stat) == 0 &&
      S_ISREG (progress_stat.st_mode))
    progress_hint += progress_stat.st_size;

  if (check_state (g, "tgz_in") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "tgz_in", "-1");
    return -1;
  }
  guestfs___set_busy (g);

  args.directory = (char *) directory;
  serial = guestfs___send (g, GUESTFS_PROC_TGZ_IN,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_tgz_in_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "tgz_in", "-1");
    return -1;
  }

  r = guestfs___send_file (g, tarball);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "tgz_in", "-1");
    /* daemon will send an error reply which we discard */
    guestfs___recv_discard (g, "tgz_in");
    return -1;
  }
  if (r == -2) /* daemon cancelled */
    goto read_reply;

 read_reply:
  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "tgz_in", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "tgz_in", "-1");
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_TGZ_IN, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "tgz_in", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "tgz_in", "-1");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "tgz_in", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "tgz_in",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  ret_v = 0;
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "tgz_in");
    fprintf (trace_fp, "%d", ret_v);
    trace_send_line (g);
  }

  return ret_v;
}

int
guestfs_tgz_out (guestfs_h *g,
                 const char *directory,
                 const char *tarball)
{
  struct guestfs_tgz_out_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "tgz_out", 7);
  if (directory == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "tgz_out", "directory");
    return -1;
  }
  if (tarball == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "tgz_out", "tarball");
    return -1;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "tgz_out");
    fprintf (trace_fp, " \"%s\"", directory);
    fprintf (trace_fp, " \"%s\"", tarball);
    trace_send_line (g);
  }

  if (check_state (g, "tgz_out") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "tgz_out", "-1");
    return -1;
  }
  guestfs___set_busy (g);

  args.directory = (char *) directory;
  serial = guestfs___send (g, GUESTFS_PROC_TGZ_OUT,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_tgz_out_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "tgz_out", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "tgz_out", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "tgz_out", "-1");
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_TGZ_OUT, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "tgz_out", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "tgz_out", "-1");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "tgz_out", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "tgz_out",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return -1;
  }

  if (guestfs___recv_file (g, tarball) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "tgz_out", "-1");
    return -1;
  }

  guestfs___end_busy (g);
  ret_v = 0;
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "tgz_out");
    fprintf (trace_fp, "%d", ret_v);
    trace_send_line (g);
  }

  return ret_v;
}

int
guestfs_mount_ro (guestfs_h *g,
                  const char *device,
                  const char *mountpoint)
{
  struct guestfs_mount_ro_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "mount_ro", 8);
  if (device == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "mount_ro", "device");
    return -1;
  }
  if (mountpoint == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "mount_ro", "mountpoint");
    return -1;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "mount_ro");
    fprintf (trace_fp, " \"%s\"", device);
    fprintf (trace_fp, " \"%s\"", mountpoint);
    trace_send_line (g);
  }

  if (check_state (g, "mount_ro") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mount_ro", "-1");
    return -1;
  }
  guestfs___set_busy (g);

  args.device = (char *) device;
  args.mountpoint = (char *) mountpoint;
  serial = guestfs___send (g, GUESTFS_PROC_MOUNT_RO,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_mount_ro_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mount_ro", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "mount_ro", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mount_ro", "-1");
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_MOUNT_RO, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mount_ro", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mount_ro", "-1");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "mount_ro", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "mount_ro",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  ret_v = 0;
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "mount_ro");
    fprintf (trace_fp, "%d", ret_v);
    trace_send_line (g);
  }

  return ret_v;
}

int
guestfs_mount_options (guestfs_h *g,
                       const char *options,
                       const char *device,
                       const char *mountpoint)
{
  struct guestfs_mount_options_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "mount_options", 13);
  if (options == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "mount_options", "options");
    return -1;
  }
  if (device == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "mount_options", "device");
    return -1;
  }
  if (mountpoint == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "mount_options", "mountpoint");
    return -1;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "mount_options");
    fprintf (trace_fp, " \"%s\"", options);
    fprintf (trace_fp, " \"%s\"", device);
    fprintf (trace_fp, " \"%s\"", mountpoint);
    trace_send_line (g);
  }

  if (check_state (g, "mount_options") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mount_options", "-1");
    return -1;
  }
  guestfs___set_busy (g);

  args.options = (char *) options;
  args.device = (char *) device;
  args.mountpoint = (char *) mountpoint;
  serial = guestfs___send (g, GUESTFS_PROC_MOUNT_OPTIONS,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_mount_options_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mount_options", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "mount_options", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mount_options", "-1");
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_MOUNT_OPTIONS, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mount_options", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mount_options", "-1");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "mount_options", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "mount_options",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  ret_v = 0;
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "mount_options");
    fprintf (trace_fp, "%d", ret_v);
    trace_send_line (g);
  }

  return ret_v;
}

int
guestfs_mount_vfs (guestfs_h *g,
                   const char *options,
                   const char *vfstype,
                   const char *device,
                   const char *mountpoint)
{
  struct guestfs_mount_vfs_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "mount_vfs", 9);
  if (options == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "mount_vfs", "options");
    return -1;
  }
  if (vfstype == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "mount_vfs", "vfstype");
    return -1;
  }
  if (device == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "mount_vfs", "device");
    return -1;
  }
  if (mountpoint == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "mount_vfs", "mountpoint");
    return -1;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "mount_vfs");
    fprintf (trace_fp, " \"%s\"", options);
    fprintf (trace_fp, " \"%s\"", vfstype);
    fprintf (trace_fp, " \"%s\"", device);
    fprintf (trace_fp, " \"%s\"", mountpoint);
    trace_send_line (g);
  }

  if (check_state (g, "mount_vfs") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mount_vfs", "-1");
    return -1;
  }
  guestfs___set_busy (g);

  args.options = (char *) options;
  args.vfstype = (char *) vfstype;
  args.device = (char *) device;
  args.mountpoint = (char *) mountpoint;
  serial = guestfs___send (g, GUESTFS_PROC_MOUNT_VFS,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_mount_vfs_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mount_vfs", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "mount_vfs", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mount_vfs", "-1");
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_MOUNT_VFS, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mount_vfs", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mount_vfs", "-1");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "mount_vfs", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "mount_vfs",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  ret_v = 0;
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "mount_vfs");
    fprintf (trace_fp, "%d", ret_v);
    trace_send_line (g);
  }

  return ret_v;
}

char *
guestfs_debug (guestfs_h *g,
               const char *subcmd,
               char *const *extraargs)
{
  struct guestfs_debug_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  struct guestfs_debug_ret ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  char *ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "debug", 5);
  if (subcmd == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "debug", "subcmd");
    return NULL;
  }
  if (extraargs == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "debug", "extraargs");
    return NULL;
  }

  if (trace_flag) {
    size_t i;

    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "debug");
    fprintf (trace_fp, " \"%s\"", subcmd);
    fputc (' ', trace_fp);
    fputc ('"', trace_fp);
    for (i = 0; extraargs[i]; ++i) {
      if (i > 0) fputc (' ', trace_fp);
      fputs (extraargs[i], trace_fp);
    }
    fputc ('"', trace_fp);
    trace_send_line (g);
  }

  if (check_state (g, "debug") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "debug", "NULL");
    return NULL;
  }
  guestfs___set_busy (g);

  args.subcmd = (char *) subcmd;
  args.extraargs.extraargs_val = (char **) extraargs;
  for (args.extraargs.extraargs_len = 0; extraargs[args.extraargs.extraargs_len]; args.extraargs.extraargs_len++) ;
  serial = guestfs___send (g, GUESTFS_PROC_DEBUG,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_debug_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "debug", "NULL");
    return NULL;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs___recv (g, "debug", &hdr, &err,
        (xdrproc_t) xdr_guestfs_debug_ret, (char *) &ret);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "debug", "NULL");
    return NULL;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_DEBUG, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "debug", "NULL");
    return NULL;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "debug", "NULL");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "debug", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "debug",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return NULL;
  }

  guestfs___end_busy (g);
  ret_v = ret.result; /* caller will free */
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "debug");
    fprintf (trace_fp, "\"%s\"", ret_v);
    trace_send_line (g);
  }

  return ret_v;
}

int
guestfs_lvremove (guestfs_h *g,
                  const char *device)
{
  struct guestfs_lvremove_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "lvremove", 8);
  if (device == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "lvremove", "device");
    return -1;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "lvremove");
    fprintf (trace_fp, " \"%s\"", device);
    trace_send_line (g);
  }

  if (check_state (g, "lvremove") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "lvremove", "-1");
    return -1;
  }
  guestfs___set_busy (g);

  args.device = (char *) device;
  serial = guestfs___send (g, GUESTFS_PROC_LVREMOVE,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_lvremove_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "lvremove", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "lvremove", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "lvremove", "-1");
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_LVREMOVE, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "lvremove", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "lvremove", "-1");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "lvremove", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "lvremove",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  ret_v = 0;
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "lvremove");
    fprintf (trace_fp, "%d", ret_v);
    trace_send_line (g);
  }

  return ret_v;
}

int
guestfs_vgremove (guestfs_h *g,
                  const char *vgname)
{
  struct guestfs_vgremove_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "vgremove", 8);
  if (vgname == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "vgremove", "vgname");
    return -1;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "vgremove");
    fprintf (trace_fp, " \"%s\"", vgname);
    trace_send_line (g);
  }

  if (check_state (g, "vgremove") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "vgremove", "-1");
    return -1;
  }
  guestfs___set_busy (g);

  args.vgname = (char *) vgname;
  serial = guestfs___send (g, GUESTFS_PROC_VGREMOVE,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_vgremove_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "vgremove", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "vgremove", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "vgremove", "-1");
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_VGREMOVE, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "vgremove", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "vgremove", "-1");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "vgremove", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "vgremove",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  ret_v = 0;
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "vgremove");
    fprintf (trace_fp, "%d", ret_v);
    trace_send_line (g);
  }

  return ret_v;
}

int
guestfs_pvremove (guestfs_h *g,
                  const char *device)
{
  struct guestfs_pvremove_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "pvremove", 8);
  if (device == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "pvremove", "device");
    return -1;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "pvremove");
    fprintf (trace_fp, " \"%s\"", device);
    trace_send_line (g);
  }

  if (check_state (g, "pvremove") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "pvremove", "-1");
    return -1;
  }
  guestfs___set_busy (g);

  args.device = (char *) device;
  serial = guestfs___send (g, GUESTFS_PROC_PVREMOVE,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_pvremove_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "pvremove", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "pvremove", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "pvremove", "-1");
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_PVREMOVE, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "pvremove", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "pvremove", "-1");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "pvremove", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "pvremove",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  ret_v = 0;
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "pvremove");
    fprintf (trace_fp, "%d", ret_v);
    trace_send_line (g);
  }

  return ret_v;
}

int
guestfs_set_e2label (guestfs_h *g,
                     const char *device,
                     const char *label)
{
  struct guestfs_set_e2label_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "set_e2label", 11);
  if (device == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "set_e2label", "device");
    return -1;
  }
  if (label == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "set_e2label", "label");
    return -1;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "set_e2label");
    fprintf (trace_fp, " \"%s\"", device);
    fprintf (trace_fp, " \"%s\"", label);
    trace_send_line (g);
  }

  if (check_state (g, "set_e2label") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "set_e2label", "-1");
    return -1;
  }
  guestfs___set_busy (g);

  args.device = (char *) device;
  args.label = (char *) label;
  serial = guestfs___send (g, GUESTFS_PROC_SET_E2LABEL,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_set_e2label_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "set_e2label", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "set_e2label", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "set_e2label", "-1");
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_SET_E2LABEL, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "set_e2label", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "set_e2label", "-1");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "set_e2label", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "set_e2label",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  ret_v = 0;
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "set_e2label");
    fprintf (trace_fp, "%d", ret_v);
    trace_send_line (g);
  }

  return ret_v;
}

char *
guestfs_get_e2label (guestfs_h *g,
                     const char *device)
{
  struct guestfs_get_e2label_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  struct guestfs_get_e2label_ret ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  char *ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "get_e2label", 11);
  if (device == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "get_e2label", "device");
    return NULL;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "get_e2label");
    fprintf (trace_fp, " \"%s\"", device);
    trace_send_line (g);
  }

  if (check_state (g, "get_e2label") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "get_e2label", "NULL");
    return NULL;
  }
  guestfs___set_busy (g);

  args.device = (char *) device;
  serial = guestfs___send (g, GUESTFS_PROC_GET_E2LABEL,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_get_e2label_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "get_e2label", "NULL");
    return NULL;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs___recv (g, "get_e2label", &hdr, &err,
        (xdrproc_t) xdr_guestfs_get_e2label_ret, (char *) &ret);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "get_e2label", "NULL");
    return NULL;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_GET_E2LABEL, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "get_e2label", "NULL");
    return NULL;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "get_e2label", "NULL");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "get_e2label", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "get_e2label",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return NULL;
  }

  guestfs___end_busy (g);
  ret_v = ret.label; /* caller will free */
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "get_e2label");
    fprintf (trace_fp, "\"%s\"", ret_v);
    trace_send_line (g);
  }

  return ret_v;
}

int
guestfs_set_e2uuid (guestfs_h *g,
                    const char *device,
                    const char *uuid)
{
  struct guestfs_set_e2uuid_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "set_e2uuid", 10);
  if (device == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "set_e2uuid", "device");
    return -1;
  }
  if (uuid == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "set_e2uuid", "uuid");
    return -1;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "set_e2uuid");
    fprintf (trace_fp, " \"%s\"", device);
    fprintf (trace_fp, " \"%s\"", uuid);
    trace_send_line (g);
  }

  if (check_state (g, "set_e2uuid") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "set_e2uuid", "-1");
    return -1;
  }
  guestfs___set_busy (g);

  args.device = (char *) device;
  args.uuid = (char *) uuid;
  serial = guestfs___send (g, GUESTFS_PROC_SET_E2UUID,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_set_e2uuid_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "set_e2uuid", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "set_e2uuid", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "set_e2uuid", "-1");
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_SET_E2UUID, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "set_e2uuid", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "set_e2uuid", "-1");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "set_e2uuid", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "set_e2uuid",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  ret_v = 0;
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "set_e2uuid");
    fprintf (trace_fp, "%d", ret_v);
    trace_send_line (g);
  }

  return ret_v;
}

char *
guestfs_get_e2uuid (guestfs_h *g,
                    const char *device)
{
  struct guestfs_get_e2uuid_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  struct guestfs_get_e2uuid_ret ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  char *ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "get_e2uuid", 10);
  if (device == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "get_e2uuid", "device");
    return NULL;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "get_e2uuid");
    fprintf (trace_fp, " \"%s\"", device);
    trace_send_line (g);
  }

  if (check_state (g, "get_e2uuid") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "get_e2uuid", "NULL");
    return NULL;
  }
  guestfs___set_busy (g);

  args.device = (char *) device;
  serial = guestfs___send (g, GUESTFS_PROC_GET_E2UUID,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_get_e2uuid_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "get_e2uuid", "NULL");
    return NULL;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs___recv (g, "get_e2uuid", &hdr, &err,
        (xdrproc_t) xdr_guestfs_get_e2uuid_ret, (char *) &ret);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "get_e2uuid", "NULL");
    return NULL;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_GET_E2UUID, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "get_e2uuid", "NULL");
    return NULL;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "get_e2uuid", "NULL");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "get_e2uuid", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "get_e2uuid",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return NULL;
  }

  guestfs___end_busy (g);
  ret_v = ret.uuid; /* caller will free */
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "get_e2uuid");
    fprintf (trace_fp, "\"%s\"", ret_v);
    trace_send_line (g);
  }

  return ret_v;
}

int
guestfs_fsck (guestfs_h *g,
              const char *fstype,
              const char *device)
{
  struct guestfs_fsck_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  struct guestfs_fsck_ret ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "fsck", 4);
  if (fstype == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "fsck", "fstype");
    return -1;
  }
  if (device == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "fsck", "device");
    return -1;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "fsck");
    fprintf (trace_fp, " \"%s\"", fstype);
    fprintf (trace_fp, " \"%s\"", device);
    trace_send_line (g);
  }

  if (check_state (g, "fsck") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "fsck", "-1");
    return -1;
  }
  guestfs___set_busy (g);

  args.fstype = (char *) fstype;
  args.device = (char *) device;
  serial = guestfs___send (g, GUESTFS_PROC_FSCK,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_fsck_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "fsck", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs___recv (g, "fsck", &hdr, &err,
        (xdrproc_t) xdr_guestfs_fsck_ret, (char *) &ret);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "fsck", "-1");
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_FSCK, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "fsck", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "fsck", "-1");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "fsck", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "fsck",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  ret_v = ret.status;
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "fsck");
    fprintf (trace_fp, "%d", ret_v);
    trace_send_line (g);
  }

  return ret_v;
}

int
guestfs_zero (guestfs_h *g,
              const char *device)
{
  struct guestfs_zero_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "zero", 4);
  if (device == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "zero", "device");
    return -1;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "zero");
    fprintf (trace_fp, " \"%s\"", device);
    trace_send_line (g);
  }

  if (check_state (g, "zero") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "zero", "-1");
    return -1;
  }
  guestfs___set_busy (g);

  args.device = (char *) device;
  serial = guestfs___send (g, GUESTFS_PROC_ZERO,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_zero_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "zero", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "zero", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "zero", "-1");
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_ZERO, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "zero", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "zero", "-1");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "zero", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "zero",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  ret_v = 0;
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "zero");
    fprintf (trace_fp, "%d", ret_v);
    trace_send_line (g);
  }

  return ret_v;
}

int
guestfs_grub_install (guestfs_h *g,
                      const char *root,
                      const char *device)
{
  struct guestfs_grub_install_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "grub_install", 12);
  if (root == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "grub_install", "root");
    return -1;
  }
  if (device == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "grub_install", "device");
    return -1;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "grub_install");
    fprintf (trace_fp, " \"%s\"", root);
    fprintf (trace_fp, " \"%s\"", device);
    trace_send_line (g);
  }

  if (check_state (g, "grub_install") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "grub_install", "-1");
    return -1;
  }
  guestfs___set_busy (g);

  args.root = (char *) root;
  args.device = (char *) device;
  serial = guestfs___send (g, GUESTFS_PROC_GRUB_INSTALL,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_grub_install_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "grub_install", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "grub_install", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "grub_install", "-1");
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_GRUB_INSTALL, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "grub_install", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "grub_install", "-1");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "grub_install", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "grub_install",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  ret_v = 0;
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "grub_install");
    fprintf (trace_fp, "%d", ret_v);
    trace_send_line (g);
  }

  return ret_v;
}

int
guestfs_cp (guestfs_h *g,
            const char *src,
            const char *dest)
{
  struct guestfs_cp_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "cp", 2);
  if (src == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "cp", "src");
    return -1;
  }
  if (dest == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "cp", "dest");
    return -1;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "cp");
    fprintf (trace_fp, " \"%s\"", src);
    fprintf (trace_fp, " \"%s\"", dest);
    trace_send_line (g);
  }

  if (check_state (g, "cp") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "cp", "-1");
    return -1;
  }
  guestfs___set_busy (g);

  args.src = (char *) src;
  args.dest = (char *) dest;
  serial = guestfs___send (g, GUESTFS_PROC_CP,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_cp_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "cp", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "cp", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "cp", "-1");
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_CP, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "cp", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "cp", "-1");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "cp", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "cp",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  ret_v = 0;
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "cp");
    fprintf (trace_fp, "%d", ret_v);
    trace_send_line (g);
  }

  return ret_v;
}

int
guestfs_cp_a (guestfs_h *g,
              const char *src,
              const char *dest)
{
  struct guestfs_cp_a_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "cp_a", 4);
  if (src == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "cp_a", "src");
    return -1;
  }
  if (dest == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "cp_a", "dest");
    return -1;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "cp_a");
    fprintf (trace_fp, " \"%s\"", src);
    fprintf (trace_fp, " \"%s\"", dest);
    trace_send_line (g);
  }

  if (check_state (g, "cp_a") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "cp_a", "-1");
    return -1;
  }
  guestfs___set_busy (g);

  args.src = (char *) src;
  args.dest = (char *) dest;
  serial = guestfs___send (g, GUESTFS_PROC_CP_A,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_cp_a_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "cp_a", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "cp_a", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "cp_a", "-1");
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_CP_A, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "cp_a", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "cp_a", "-1");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "cp_a", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "cp_a",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  ret_v = 0;
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "cp_a");
    fprintf (trace_fp, "%d", ret_v);
    trace_send_line (g);
  }

  return ret_v;
}

int
guestfs_mv (guestfs_h *g,
            const char *src,
            const char *dest)
{
  struct guestfs_mv_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "mv", 2);
  if (src == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "mv", "src");
    return -1;
  }
  if (dest == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "mv", "dest");
    return -1;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "mv");
    fprintf (trace_fp, " \"%s\"", src);
    fprintf (trace_fp, " \"%s\"", dest);
    trace_send_line (g);
  }

  if (check_state (g, "mv") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mv", "-1");
    return -1;
  }
  guestfs___set_busy (g);

  args.src = (char *) src;
  args.dest = (char *) dest;
  serial = guestfs___send (g, GUESTFS_PROC_MV,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_mv_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mv", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "mv", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mv", "-1");
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_MV, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mv", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mv", "-1");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "mv", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "mv",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  ret_v = 0;
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "mv");
    fprintf (trace_fp, "%d", ret_v);
    trace_send_line (g);
  }

  return ret_v;
}

int
guestfs_drop_caches (guestfs_h *g,
                     int whattodrop)
{
  struct guestfs_drop_caches_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "drop_caches", 11);
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "drop_caches");
    fprintf (trace_fp, " %d", whattodrop);
    trace_send_line (g);
  }

  if (check_state (g, "drop_caches") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "drop_caches", "-1");
    return -1;
  }
  guestfs___set_busy (g);

  args.whattodrop = whattodrop;
  serial = guestfs___send (g, GUESTFS_PROC_DROP_CACHES,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_drop_caches_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "drop_caches", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "drop_caches", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "drop_caches", "-1");
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_DROP_CACHES, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "drop_caches", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "drop_caches", "-1");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "drop_caches", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "drop_caches",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  ret_v = 0;
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "drop_caches");
    fprintf (trace_fp, "%d", ret_v);
    trace_send_line (g);
  }

  return ret_v;
}

char *
guestfs_dmesg (guestfs_h *g)
{
  guestfs_message_header hdr;
  guestfs_message_error err;
  struct guestfs_dmesg_ret ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  char *ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "dmesg", 5);
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "dmesg");
    trace_send_line (g);
  }

  if (check_state (g, "dmesg") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "dmesg", "NULL");
    return NULL;
  }
  guestfs___set_busy (g);

  serial = guestfs___send (g, GUESTFS_PROC_DMESG, progress_hint, 0,
                           NULL, NULL);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "dmesg", "NULL");
    return NULL;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs___recv (g, "dmesg", &hdr, &err,
        (xdrproc_t) xdr_guestfs_dmesg_ret, (char *) &ret);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "dmesg", "NULL");
    return NULL;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_DMESG, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "dmesg", "NULL");
    return NULL;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "dmesg", "NULL");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "dmesg", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "dmesg",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return NULL;
  }

  guestfs___end_busy (g);
  ret_v = ret.kmsgs; /* caller will free */
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "dmesg");
    fprintf (trace_fp, "\"%s\"", ret_v);
    trace_send_line (g);
  }

  return ret_v;
}

int
guestfs_ping_daemon (guestfs_h *g)
{
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "ping_daemon", 11);
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "ping_daemon");
    trace_send_line (g);
  }

  if (check_state (g, "ping_daemon") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "ping_daemon", "-1");
    return -1;
  }
  guestfs___set_busy (g);

  serial = guestfs___send (g, GUESTFS_PROC_PING_DAEMON, progress_hint, 0,
                           NULL, NULL);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "ping_daemon", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "ping_daemon", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "ping_daemon", "-1");
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_PING_DAEMON, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "ping_daemon", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "ping_daemon", "-1");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "ping_daemon", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "ping_daemon",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  ret_v = 0;
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "ping_daemon");
    fprintf (trace_fp, "%d", ret_v);
    trace_send_line (g);
  }

  return ret_v;
}

int
guestfs_equal (guestfs_h *g,
               const char *file1,
               const char *file2)
{
  struct guestfs_equal_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  struct guestfs_equal_ret ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "equal", 5);
  if (file1 == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "equal", "file1");
    return -1;
  }
  if (file2 == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "equal", "file2");
    return -1;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "equal");
    fprintf (trace_fp, " \"%s\"", file1);
    fprintf (trace_fp, " \"%s\"", file2);
    trace_send_line (g);
  }

  if (check_state (g, "equal") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "equal", "-1");
    return -1;
  }
  guestfs___set_busy (g);

  args.file1 = (char *) file1;
  args.file2 = (char *) file2;
  serial = guestfs___send (g, GUESTFS_PROC_EQUAL,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_equal_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "equal", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs___recv (g, "equal", &hdr, &err,
        (xdrproc_t) xdr_guestfs_equal_ret, (char *) &ret);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "equal", "-1");
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_EQUAL, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "equal", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "equal", "-1");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "equal", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "equal",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  ret_v = ret.equality;
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "equal");
    fprintf (trace_fp, "%d", ret_v);
    trace_send_line (g);
  }

  return ret_v;
}

char **
guestfs_strings (guestfs_h *g,
                 const char *path)
{
  struct guestfs_strings_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  struct guestfs_strings_ret ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  char **ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "strings", 7);
  if (path == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "strings", "path");
    return NULL;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "strings");
    fprintf (trace_fp, " \"%s\"", path);
    trace_send_line (g);
  }

  if (check_state (g, "strings") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "strings", "NULL");
    return NULL;
  }
  guestfs___set_busy (g);

  args.path = (char *) path;
  serial = guestfs___send (g, GUESTFS_PROC_STRINGS,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_strings_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "strings", "NULL");
    return NULL;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs___recv (g, "strings", &hdr, &err,
        (xdrproc_t) xdr_guestfs_strings_ret, (char *) &ret);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "strings", "NULL");
    return NULL;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_STRINGS, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "strings", "NULL");
    return NULL;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "strings", "NULL");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "strings", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "strings",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return NULL;
  }

  guestfs___end_busy (g);
  /* caller will free this, but we need to add a NULL entry */
  ret.stringsout.stringsout_val =
    safe_realloc (g, ret.stringsout.stringsout_val,
                  sizeof (char *) * (ret.stringsout.stringsout_len + 1));
  ret.stringsout.stringsout_val[ret.stringsout.stringsout_len] = NULL;
  ret_v = ret.stringsout.stringsout_val;
  if (trace_flag) {
    size_t i;

    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "strings");
    fputs ("[", trace_fp);
    for (i = 0; ret_v[i]; ++i) {
      if (i > 0) fputs (", ", trace_fp);
      fputs ("\"", trace_fp);
      fputs (ret_v[i], trace_fp);
      fputs ("\"", trace_fp);
    }
    fputs ("]", trace_fp);
    trace_send_line (g);
  }

  return ret_v;
}

char **
guestfs_strings_e (guestfs_h *g,
                   const char *encoding,
                   const char *path)
{
  struct guestfs_strings_e_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  struct guestfs_strings_e_ret ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  char **ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "strings_e", 9);
  if (encoding == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "strings_e", "encoding");
    return NULL;
  }
  if (path == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "strings_e", "path");
    return NULL;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "strings_e");
    fprintf (trace_fp, " \"%s\"", encoding);
    fprintf (trace_fp, " \"%s\"", path);
    trace_send_line (g);
  }

  if (check_state (g, "strings_e") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "strings_e", "NULL");
    return NULL;
  }
  guestfs___set_busy (g);

  args.encoding = (char *) encoding;
  args.path = (char *) path;
  serial = guestfs___send (g, GUESTFS_PROC_STRINGS_E,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_strings_e_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "strings_e", "NULL");
    return NULL;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs___recv (g, "strings_e", &hdr, &err,
        (xdrproc_t) xdr_guestfs_strings_e_ret, (char *) &ret);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "strings_e", "NULL");
    return NULL;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_STRINGS_E, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "strings_e", "NULL");
    return NULL;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "strings_e", "NULL");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "strings_e", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "strings_e",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return NULL;
  }

  guestfs___end_busy (g);
  /* caller will free this, but we need to add a NULL entry */
  ret.stringsout.stringsout_val =
    safe_realloc (g, ret.stringsout.stringsout_val,
                  sizeof (char *) * (ret.stringsout.stringsout_len + 1));
  ret.stringsout.stringsout_val[ret.stringsout.stringsout_len] = NULL;
  ret_v = ret.stringsout.stringsout_val;
  if (trace_flag) {
    size_t i;

    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "strings_e");
    fputs ("[", trace_fp);
    for (i = 0; ret_v[i]; ++i) {
      if (i > 0) fputs (", ", trace_fp);
      fputs ("\"", trace_fp);
      fputs (ret_v[i], trace_fp);
      fputs ("\"", trace_fp);
    }
    fputs ("]", trace_fp);
    trace_send_line (g);
  }

  return ret_v;
}

char *
guestfs_hexdump (guestfs_h *g,
                 const char *path)
{
  struct guestfs_hexdump_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  struct guestfs_hexdump_ret ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  char *ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "hexdump", 7);
  if (path == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "hexdump", "path");
    return NULL;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "hexdump");
    fprintf (trace_fp, " \"%s\"", path);
    trace_send_line (g);
  }

  if (check_state (g, "hexdump") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "hexdump", "NULL");
    return NULL;
  }
  guestfs___set_busy (g);

  args.path = (char *) path;
  serial = guestfs___send (g, GUESTFS_PROC_HEXDUMP,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_hexdump_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "hexdump", "NULL");
    return NULL;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs___recv (g, "hexdump", &hdr, &err,
        (xdrproc_t) xdr_guestfs_hexdump_ret, (char *) &ret);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "hexdump", "NULL");
    return NULL;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_HEXDUMP, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "hexdump", "NULL");
    return NULL;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "hexdump", "NULL");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "hexdump", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "hexdump",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return NULL;
  }

  guestfs___end_busy (g);
  ret_v = ret.dump; /* caller will free */
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "hexdump");
    fprintf (trace_fp, "\"%s\"", ret_v);
    trace_send_line (g);
  }

  return ret_v;
}

int
guestfs_zerofree (guestfs_h *g,
                  const char *device)
{
  struct guestfs_zerofree_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "zerofree", 8);
  if (device == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "zerofree", "device");
    return -1;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "zerofree");
    fprintf (trace_fp, " \"%s\"", device);
    trace_send_line (g);
  }

  if (check_state (g, "zerofree") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "zerofree", "-1");
    return -1;
  }
  guestfs___set_busy (g);

  args.device = (char *) device;
  serial = guestfs___send (g, GUESTFS_PROC_ZEROFREE,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_zerofree_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "zerofree", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "zerofree", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "zerofree", "-1");
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_ZEROFREE, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "zerofree", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "zerofree", "-1");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "zerofree", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "zerofree",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  ret_v = 0;
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "zerofree");
    fprintf (trace_fp, "%d", ret_v);
    trace_send_line (g);
  }

  return ret_v;
}

int
guestfs_pvresize (guestfs_h *g,
                  const char *device)
{
  struct guestfs_pvresize_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "pvresize", 8);
  if (device == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "pvresize", "device");
    return -1;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "pvresize");
    fprintf (trace_fp, " \"%s\"", device);
    trace_send_line (g);
  }

  if (check_state (g, "pvresize") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "pvresize", "-1");
    return -1;
  }
  guestfs___set_busy (g);

  args.device = (char *) device;
  serial = guestfs___send (g, GUESTFS_PROC_PVRESIZE,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_pvresize_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "pvresize", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "pvresize", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "pvresize", "-1");
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_PVRESIZE, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "pvresize", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "pvresize", "-1");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "pvresize", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "pvresize",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  ret_v = 0;
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "pvresize");
    fprintf (trace_fp, "%d", ret_v);
    trace_send_line (g);
  }

  return ret_v;
}

int
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
  FILE *trace_fp;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
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
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "sfdisk_N");
    fprintf (trace_fp, " \"%s\"", device);
    fprintf (trace_fp, " %d", partnum);
    fprintf (trace_fp, " %d", cyls);
    fprintf (trace_fp, " %d", heads);
    fprintf (trace_fp, " %d", sectors);
    fprintf (trace_fp, " \"%s\"", line);
    trace_send_line (g);
  }

  if (check_state (g, "sfdisk_N") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "sfdisk_N", "-1");
    return -1;
  }
  guestfs___set_busy (g);

  args.device = (char *) device;
  args.partnum = partnum;
  args.cyls = cyls;
  args.heads = heads;
  args.sectors = sectors;
  args.line = (char *) line;
  serial = guestfs___send (g, GUESTFS_PROC_SFDISK_N,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_sfdisk_N_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "sfdisk_N", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "sfdisk_N", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "sfdisk_N", "-1");
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_SFDISK_N, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "sfdisk_N", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "sfdisk_N", "-1");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "sfdisk_N", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "sfdisk_N",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  ret_v = 0;
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "sfdisk_N");
    fprintf (trace_fp, "%d", ret_v);
    trace_send_line (g);
  }

  return ret_v;
}

char *
guestfs_sfdisk_l (guestfs_h *g,
                  const char *device)
{
  struct guestfs_sfdisk_l_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  struct guestfs_sfdisk_l_ret ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  char *ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "sfdisk_l", 8);
  if (device == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "sfdisk_l", "device");
    return NULL;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "sfdisk_l");
    fprintf (trace_fp, " \"%s\"", device);
    trace_send_line (g);
  }

  if (check_state (g, "sfdisk_l") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "sfdisk_l", "NULL");
    return NULL;
  }
  guestfs___set_busy (g);

  args.device = (char *) device;
  serial = guestfs___send (g, GUESTFS_PROC_SFDISK_L,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_sfdisk_l_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "sfdisk_l", "NULL");
    return NULL;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs___recv (g, "sfdisk_l", &hdr, &err,
        (xdrproc_t) xdr_guestfs_sfdisk_l_ret, (char *) &ret);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "sfdisk_l", "NULL");
    return NULL;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_SFDISK_L, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "sfdisk_l", "NULL");
    return NULL;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "sfdisk_l", "NULL");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "sfdisk_l", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "sfdisk_l",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return NULL;
  }

  guestfs___end_busy (g);
  ret_v = ret.partitions; /* caller will free */
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "sfdisk_l");
    fprintf (trace_fp, "\"%s\"", ret_v);
    trace_send_line (g);
  }

  return ret_v;
}

char *
guestfs_sfdisk_kernel_geometry (guestfs_h *g,
                                const char *device)
{
  struct guestfs_sfdisk_kernel_geometry_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  struct guestfs_sfdisk_kernel_geometry_ret ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  char *ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "sfdisk_kernel_geometry", 22);
  if (device == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "sfdisk_kernel_geometry", "device");
    return NULL;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "sfdisk_kernel_geometry");
    fprintf (trace_fp, " \"%s\"", device);
    trace_send_line (g);
  }

  if (check_state (g, "sfdisk_kernel_geometry") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "sfdisk_kernel_geometry", "NULL");
    return NULL;
  }
  guestfs___set_busy (g);

  args.device = (char *) device;
  serial = guestfs___send (g, GUESTFS_PROC_SFDISK_KERNEL_GEOMETRY,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_sfdisk_kernel_geometry_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "sfdisk_kernel_geometry", "NULL");
    return NULL;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs___recv (g, "sfdisk_kernel_geometry", &hdr, &err,
        (xdrproc_t) xdr_guestfs_sfdisk_kernel_geometry_ret, (char *) &ret);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "sfdisk_kernel_geometry", "NULL");
    return NULL;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_SFDISK_KERNEL_GEOMETRY, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "sfdisk_kernel_geometry", "NULL");
    return NULL;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "sfdisk_kernel_geometry", "NULL");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "sfdisk_kernel_geometry", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "sfdisk_kernel_geometry",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return NULL;
  }

  guestfs___end_busy (g);
  ret_v = ret.partitions; /* caller will free */
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "sfdisk_kernel_geometry");
    fprintf (trace_fp, "\"%s\"", ret_v);
    trace_send_line (g);
  }

  return ret_v;
}

char *
guestfs_sfdisk_disk_geometry (guestfs_h *g,
                              const char *device)
{
  struct guestfs_sfdisk_disk_geometry_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  struct guestfs_sfdisk_disk_geometry_ret ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  char *ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "sfdisk_disk_geometry", 20);
  if (device == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "sfdisk_disk_geometry", "device");
    return NULL;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "sfdisk_disk_geometry");
    fprintf (trace_fp, " \"%s\"", device);
    trace_send_line (g);
  }

  if (check_state (g, "sfdisk_disk_geometry") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "sfdisk_disk_geometry", "NULL");
    return NULL;
  }
  guestfs___set_busy (g);

  args.device = (char *) device;
  serial = guestfs___send (g, GUESTFS_PROC_SFDISK_DISK_GEOMETRY,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_sfdisk_disk_geometry_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "sfdisk_disk_geometry", "NULL");
    return NULL;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs___recv (g, "sfdisk_disk_geometry", &hdr, &err,
        (xdrproc_t) xdr_guestfs_sfdisk_disk_geometry_ret, (char *) &ret);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "sfdisk_disk_geometry", "NULL");
    return NULL;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_SFDISK_DISK_GEOMETRY, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "sfdisk_disk_geometry", "NULL");
    return NULL;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "sfdisk_disk_geometry", "NULL");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "sfdisk_disk_geometry", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "sfdisk_disk_geometry",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return NULL;
  }

  guestfs___end_busy (g);
  ret_v = ret.partitions; /* caller will free */
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "sfdisk_disk_geometry");
    fprintf (trace_fp, "\"%s\"", ret_v);
    trace_send_line (g);
  }

  return ret_v;
}

int
guestfs_vg_activate_all (guestfs_h *g,
                         int activate)
{
  struct guestfs_vg_activate_all_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "vg_activate_all", 15);
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "vg_activate_all");
    fputs (activate ? " true" : " false", trace_fp);
    trace_send_line (g);
  }

  if (check_state (g, "vg_activate_all") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "vg_activate_all", "-1");
    return -1;
  }
  guestfs___set_busy (g);

  args.activate = activate;
  serial = guestfs___send (g, GUESTFS_PROC_VG_ACTIVATE_ALL,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_vg_activate_all_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "vg_activate_all", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "vg_activate_all", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "vg_activate_all", "-1");
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_VG_ACTIVATE_ALL, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "vg_activate_all", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "vg_activate_all", "-1");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "vg_activate_all", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "vg_activate_all",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  ret_v = 0;
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "vg_activate_all");
    fprintf (trace_fp, "%d", ret_v);
    trace_send_line (g);
  }

  return ret_v;
}

int
guestfs_vg_activate (guestfs_h *g,
                     int activate,
                     char *const *volgroups)
{
  struct guestfs_vg_activate_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "vg_activate", 11);
  if (volgroups == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "vg_activate", "volgroups");
    return -1;
  }

  if (trace_flag) {
    size_t i;

    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "vg_activate");
    fputs (activate ? " true" : " false", trace_fp);
    fputc (' ', trace_fp);
    fputc ('"', trace_fp);
    for (i = 0; volgroups[i]; ++i) {
      if (i > 0) fputc (' ', trace_fp);
      fputs (volgroups[i], trace_fp);
    }
    fputc ('"', trace_fp);
    trace_send_line (g);
  }

  if (check_state (g, "vg_activate") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "vg_activate", "-1");
    return -1;
  }
  guestfs___set_busy (g);

  args.activate = activate;
  args.volgroups.volgroups_val = (char **) volgroups;
  for (args.volgroups.volgroups_len = 0; volgroups[args.volgroups.volgroups_len]; args.volgroups.volgroups_len++) ;
  serial = guestfs___send (g, GUESTFS_PROC_VG_ACTIVATE,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_vg_activate_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "vg_activate", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "vg_activate", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "vg_activate", "-1");
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_VG_ACTIVATE, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "vg_activate", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "vg_activate", "-1");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "vg_activate", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "vg_activate",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  ret_v = 0;
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "vg_activate");
    fprintf (trace_fp, "%d", ret_v);
    trace_send_line (g);
  }

  return ret_v;
}

int
guestfs_lvresize (guestfs_h *g,
                  const char *device,
                  int mbytes)
{
  struct guestfs_lvresize_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "lvresize", 8);
  if (device == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "lvresize", "device");
    return -1;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "lvresize");
    fprintf (trace_fp, " \"%s\"", device);
    fprintf (trace_fp, " %d", mbytes);
    trace_send_line (g);
  }

  if (check_state (g, "lvresize") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "lvresize", "-1");
    return -1;
  }
  guestfs___set_busy (g);

  args.device = (char *) device;
  args.mbytes = mbytes;
  serial = guestfs___send (g, GUESTFS_PROC_LVRESIZE,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_lvresize_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "lvresize", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "lvresize", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "lvresize", "-1");
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_LVRESIZE, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "lvresize", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "lvresize", "-1");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "lvresize", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "lvresize",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  ret_v = 0;
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "lvresize");
    fprintf (trace_fp, "%d", ret_v);
    trace_send_line (g);
  }

  return ret_v;
}

int
guestfs_resize2fs (guestfs_h *g,
                   const char *device)
{
  struct guestfs_resize2fs_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "resize2fs", 9);
  if (device == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "resize2fs", "device");
    return -1;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "resize2fs");
    fprintf (trace_fp, " \"%s\"", device);
    trace_send_line (g);
  }

  if (check_state (g, "resize2fs") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "resize2fs", "-1");
    return -1;
  }
  guestfs___set_busy (g);

  args.device = (char *) device;
  serial = guestfs___send (g, GUESTFS_PROC_RESIZE2FS,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_resize2fs_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "resize2fs", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "resize2fs", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "resize2fs", "-1");
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_RESIZE2FS, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "resize2fs", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "resize2fs", "-1");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "resize2fs", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "resize2fs",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  ret_v = 0;
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "resize2fs");
    fprintf (trace_fp, "%d", ret_v);
    trace_send_line (g);
  }

  return ret_v;
}

char **
guestfs_find (guestfs_h *g,
              const char *directory)
{
  struct guestfs_find_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  struct guestfs_find_ret ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  char **ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "find", 4);
  if (directory == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "find", "directory");
    return NULL;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "find");
    fprintf (trace_fp, " \"%s\"", directory);
    trace_send_line (g);
  }

  if (check_state (g, "find") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "find", "NULL");
    return NULL;
  }
  guestfs___set_busy (g);

  args.directory = (char *) directory;
  serial = guestfs___send (g, GUESTFS_PROC_FIND,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_find_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "find", "NULL");
    return NULL;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs___recv (g, "find", &hdr, &err,
        (xdrproc_t) xdr_guestfs_find_ret, (char *) &ret);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "find", "NULL");
    return NULL;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_FIND, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "find", "NULL");
    return NULL;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "find", "NULL");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "find", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "find",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return NULL;
  }

  guestfs___end_busy (g);
  /* caller will free this, but we need to add a NULL entry */
  ret.names.names_val =
    safe_realloc (g, ret.names.names_val,
                  sizeof (char *) * (ret.names.names_len + 1));
  ret.names.names_val[ret.names.names_len] = NULL;
  ret_v = ret.names.names_val;
  if (trace_flag) {
    size_t i;

    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "find");
    fputs ("[", trace_fp);
    for (i = 0; ret_v[i]; ++i) {
      if (i > 0) fputs (", ", trace_fp);
      fputs ("\"", trace_fp);
      fputs (ret_v[i], trace_fp);
      fputs ("\"", trace_fp);
    }
    fputs ("]", trace_fp);
    trace_send_line (g);
  }

  return ret_v;
}

int
guestfs_e2fsck_f (guestfs_h *g,
                  const char *device)
{
  struct guestfs_e2fsck_f_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "e2fsck_f", 8);
  if (device == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "e2fsck_f", "device");
    return -1;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "e2fsck_f");
    fprintf (trace_fp, " \"%s\"", device);
    trace_send_line (g);
  }

  if (check_state (g, "e2fsck_f") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "e2fsck_f", "-1");
    return -1;
  }
  guestfs___set_busy (g);

  args.device = (char *) device;
  serial = guestfs___send (g, GUESTFS_PROC_E2FSCK_F,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_e2fsck_f_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "e2fsck_f", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "e2fsck_f", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "e2fsck_f", "-1");
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_E2FSCK_F, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "e2fsck_f", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "e2fsck_f", "-1");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "e2fsck_f", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "e2fsck_f",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  ret_v = 0;
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "e2fsck_f");
    fprintf (trace_fp, "%d", ret_v);
    trace_send_line (g);
  }

  return ret_v;
}

int
guestfs_sleep (guestfs_h *g,
               int secs)
{
  struct guestfs_sleep_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "sleep", 5);
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "sleep");
    fprintf (trace_fp, " %d", secs);
    trace_send_line (g);
  }

  if (check_state (g, "sleep") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "sleep", "-1");
    return -1;
  }
  guestfs___set_busy (g);

  args.secs = secs;
  serial = guestfs___send (g, GUESTFS_PROC_SLEEP,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_sleep_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "sleep", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "sleep", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "sleep", "-1");
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_SLEEP, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "sleep", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "sleep", "-1");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "sleep", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "sleep",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  ret_v = 0;
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "sleep");
    fprintf (trace_fp, "%d", ret_v);
    trace_send_line (g);
  }

  return ret_v;
}

int
guestfs_ntfs_3g_probe (guestfs_h *g,
                       int rw,
                       const char *device)
{
  struct guestfs_ntfs_3g_probe_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  struct guestfs_ntfs_3g_probe_ret ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "ntfs_3g_probe", 13);
  if (device == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "ntfs_3g_probe", "device");
    return -1;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "ntfs_3g_probe");
    fputs (rw ? " true" : " false", trace_fp);
    fprintf (trace_fp, " \"%s\"", device);
    trace_send_line (g);
  }

  if (check_state (g, "ntfs_3g_probe") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "ntfs_3g_probe", "-1");
    return -1;
  }
  guestfs___set_busy (g);

  args.rw = rw;
  args.device = (char *) device;
  serial = guestfs___send (g, GUESTFS_PROC_NTFS_3G_PROBE,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_ntfs_3g_probe_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "ntfs_3g_probe", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs___recv (g, "ntfs_3g_probe", &hdr, &err,
        (xdrproc_t) xdr_guestfs_ntfs_3g_probe_ret, (char *) &ret);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "ntfs_3g_probe", "-1");
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_NTFS_3G_PROBE, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "ntfs_3g_probe", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "ntfs_3g_probe", "-1");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "ntfs_3g_probe", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "ntfs_3g_probe",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  ret_v = ret.status;
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "ntfs_3g_probe");
    fprintf (trace_fp, "%d", ret_v);
    trace_send_line (g);
  }

  return ret_v;
}

char *
guestfs_sh (guestfs_h *g,
            const char *command)
{
  struct guestfs_sh_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  struct guestfs_sh_ret ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  char *ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "sh", 2);
  if (command == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "sh", "command");
    return NULL;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "sh");
    fprintf (trace_fp, " \"%s\"", command);
    trace_send_line (g);
  }

  if (check_state (g, "sh") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "sh", "NULL");
    return NULL;
  }
  guestfs___set_busy (g);

  args.command = (char *) command;
  serial = guestfs___send (g, GUESTFS_PROC_SH,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_sh_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "sh", "NULL");
    return NULL;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs___recv (g, "sh", &hdr, &err,
        (xdrproc_t) xdr_guestfs_sh_ret, (char *) &ret);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "sh", "NULL");
    return NULL;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_SH, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "sh", "NULL");
    return NULL;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "sh", "NULL");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "sh", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "sh",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return NULL;
  }

  guestfs___end_busy (g);
  ret_v = ret.output; /* caller will free */
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "sh");
    fprintf (trace_fp, "\"%s\"", ret_v);
    trace_send_line (g);
  }

  return ret_v;
}

char **
guestfs_sh_lines (guestfs_h *g,
                  const char *command)
{
  struct guestfs_sh_lines_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  struct guestfs_sh_lines_ret ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  char **ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "sh_lines", 8);
  if (command == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "sh_lines", "command");
    return NULL;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "sh_lines");
    fprintf (trace_fp, " \"%s\"", command);
    trace_send_line (g);
  }

  if (check_state (g, "sh_lines") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "sh_lines", "NULL");
    return NULL;
  }
  guestfs___set_busy (g);

  args.command = (char *) command;
  serial = guestfs___send (g, GUESTFS_PROC_SH_LINES,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_sh_lines_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "sh_lines", "NULL");
    return NULL;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs___recv (g, "sh_lines", &hdr, &err,
        (xdrproc_t) xdr_guestfs_sh_lines_ret, (char *) &ret);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "sh_lines", "NULL");
    return NULL;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_SH_LINES, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "sh_lines", "NULL");
    return NULL;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "sh_lines", "NULL");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "sh_lines", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "sh_lines",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return NULL;
  }

  guestfs___end_busy (g);
  /* caller will free this, but we need to add a NULL entry */
  ret.lines.lines_val =
    safe_realloc (g, ret.lines.lines_val,
                  sizeof (char *) * (ret.lines.lines_len + 1));
  ret.lines.lines_val[ret.lines.lines_len] = NULL;
  ret_v = ret.lines.lines_val;
  if (trace_flag) {
    size_t i;

    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "sh_lines");
    fputs ("[", trace_fp);
    for (i = 0; ret_v[i]; ++i) {
      if (i > 0) fputs (", ", trace_fp);
      fputs ("\"", trace_fp);
      fputs (ret_v[i], trace_fp);
      fputs ("\"", trace_fp);
    }
    fputs ("]", trace_fp);
    trace_send_line (g);
  }

  return ret_v;
}

char **
guestfs_glob_expand (guestfs_h *g,
                     const char *pattern)
{
  struct guestfs_glob_expand_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  struct guestfs_glob_expand_ret ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  char **ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "glob_expand", 11);
  if (pattern == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "glob_expand", "pattern");
    return NULL;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "glob_expand");
    fprintf (trace_fp, " \"%s\"", pattern);
    trace_send_line (g);
  }

  if (check_state (g, "glob_expand") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "glob_expand", "NULL");
    return NULL;
  }
  guestfs___set_busy (g);

  args.pattern = (char *) pattern;
  serial = guestfs___send (g, GUESTFS_PROC_GLOB_EXPAND,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_glob_expand_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "glob_expand", "NULL");
    return NULL;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs___recv (g, "glob_expand", &hdr, &err,
        (xdrproc_t) xdr_guestfs_glob_expand_ret, (char *) &ret);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "glob_expand", "NULL");
    return NULL;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_GLOB_EXPAND, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "glob_expand", "NULL");
    return NULL;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "glob_expand", "NULL");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "glob_expand", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "glob_expand",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return NULL;
  }

  guestfs___end_busy (g);
  /* caller will free this, but we need to add a NULL entry */
  ret.paths.paths_val =
    safe_realloc (g, ret.paths.paths_val,
                  sizeof (char *) * (ret.paths.paths_len + 1));
  ret.paths.paths_val[ret.paths.paths_len] = NULL;
  ret_v = ret.paths.paths_val;
  if (trace_flag) {
    size_t i;

    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "glob_expand");
    fputs ("[", trace_fp);
    for (i = 0; ret_v[i]; ++i) {
      if (i > 0) fputs (", ", trace_fp);
      fputs ("\"", trace_fp);
      fputs (ret_v[i], trace_fp);
      fputs ("\"", trace_fp);
    }
    fputs ("]", trace_fp);
    trace_send_line (g);
  }

  return ret_v;
}

int
guestfs_scrub_device (guestfs_h *g,
                      const char *device)
{
  struct guestfs_scrub_device_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "scrub_device", 12);
  if (device == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "scrub_device", "device");
    return -1;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "scrub_device");
    fprintf (trace_fp, " \"%s\"", device);
    trace_send_line (g);
  }

  if (check_state (g, "scrub_device") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "scrub_device", "-1");
    return -1;
  }
  guestfs___set_busy (g);

  args.device = (char *) device;
  serial = guestfs___send (g, GUESTFS_PROC_SCRUB_DEVICE,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_scrub_device_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "scrub_device", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "scrub_device", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "scrub_device", "-1");
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_SCRUB_DEVICE, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "scrub_device", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "scrub_device", "-1");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "scrub_device", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "scrub_device",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  ret_v = 0;
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "scrub_device");
    fprintf (trace_fp, "%d", ret_v);
    trace_send_line (g);
  }

  return ret_v;
}

int
guestfs_scrub_file (guestfs_h *g,
                    const char *file)
{
  struct guestfs_scrub_file_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "scrub_file", 10);
  if (file == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "scrub_file", "file");
    return -1;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "scrub_file");
    fprintf (trace_fp, " \"%s\"", file);
    trace_send_line (g);
  }

  if (check_state (g, "scrub_file") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "scrub_file", "-1");
    return -1;
  }
  guestfs___set_busy (g);

  args.file = (char *) file;
  serial = guestfs___send (g, GUESTFS_PROC_SCRUB_FILE,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_scrub_file_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "scrub_file", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "scrub_file", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "scrub_file", "-1");
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_SCRUB_FILE, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "scrub_file", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "scrub_file", "-1");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "scrub_file", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "scrub_file",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  ret_v = 0;
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "scrub_file");
    fprintf (trace_fp, "%d", ret_v);
    trace_send_line (g);
  }

  return ret_v;
}

int
guestfs_scrub_freespace (guestfs_h *g,
                         const char *dir)
{
  struct guestfs_scrub_freespace_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "scrub_freespace", 15);
  if (dir == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "scrub_freespace", "dir");
    return -1;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "scrub_freespace");
    fprintf (trace_fp, " \"%s\"", dir);
    trace_send_line (g);
  }

  if (check_state (g, "scrub_freespace") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "scrub_freespace", "-1");
    return -1;
  }
  guestfs___set_busy (g);

  args.dir = (char *) dir;
  serial = guestfs___send (g, GUESTFS_PROC_SCRUB_FREESPACE,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_scrub_freespace_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "scrub_freespace", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "scrub_freespace", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "scrub_freespace", "-1");
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_SCRUB_FREESPACE, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "scrub_freespace", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "scrub_freespace", "-1");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "scrub_freespace", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "scrub_freespace",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  ret_v = 0;
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "scrub_freespace");
    fprintf (trace_fp, "%d", ret_v);
    trace_send_line (g);
  }

  return ret_v;
}

char *
guestfs_mkdtemp (guestfs_h *g,
                 const char *template)
{
  struct guestfs_mkdtemp_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  struct guestfs_mkdtemp_ret ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  char *ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "mkdtemp", 7);
  if (template == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "mkdtemp", "template");
    return NULL;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "mkdtemp");
    fprintf (trace_fp, " \"%s\"", template);
    trace_send_line (g);
  }

  if (check_state (g, "mkdtemp") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mkdtemp", "NULL");
    return NULL;
  }
  guestfs___set_busy (g);

  args.template = (char *) template;
  serial = guestfs___send (g, GUESTFS_PROC_MKDTEMP,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_mkdtemp_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mkdtemp", "NULL");
    return NULL;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs___recv (g, "mkdtemp", &hdr, &err,
        (xdrproc_t) xdr_guestfs_mkdtemp_ret, (char *) &ret);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mkdtemp", "NULL");
    return NULL;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_MKDTEMP, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mkdtemp", "NULL");
    return NULL;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mkdtemp", "NULL");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "mkdtemp", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "mkdtemp",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return NULL;
  }

  guestfs___end_busy (g);
  ret_v = ret.dir; /* caller will free */
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "mkdtemp");
    fprintf (trace_fp, "\"%s\"", ret_v);
    trace_send_line (g);
  }

  return ret_v;
}

int
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
  FILE *trace_fp;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "wc_l", 4);
  if (path == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "wc_l", "path");
    return -1;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "wc_l");
    fprintf (trace_fp, " \"%s\"", path);
    trace_send_line (g);
  }

  if (check_state (g, "wc_l") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "wc_l", "-1");
    return -1;
  }
  guestfs___set_busy (g);

  args.path = (char *) path;
  serial = guestfs___send (g, GUESTFS_PROC_WC_L,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_wc_l_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "wc_l", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs___recv (g, "wc_l", &hdr, &err,
        (xdrproc_t) xdr_guestfs_wc_l_ret, (char *) &ret);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "wc_l", "-1");
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_WC_L, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "wc_l", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "wc_l", "-1");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "wc_l", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "wc_l",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  ret_v = ret.lines;
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "wc_l");
    fprintf (trace_fp, "%d", ret_v);
    trace_send_line (g);
  }

  return ret_v;
}

int
guestfs_wc_w (guestfs_h *g,
              const char *path)
{
  struct guestfs_wc_w_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  struct guestfs_wc_w_ret ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "wc_w", 4);
  if (path == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "wc_w", "path");
    return -1;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "wc_w");
    fprintf (trace_fp, " \"%s\"", path);
    trace_send_line (g);
  }

  if (check_state (g, "wc_w") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "wc_w", "-1");
    return -1;
  }
  guestfs___set_busy (g);

  args.path = (char *) path;
  serial = guestfs___send (g, GUESTFS_PROC_WC_W,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_wc_w_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "wc_w", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs___recv (g, "wc_w", &hdr, &err,
        (xdrproc_t) xdr_guestfs_wc_w_ret, (char *) &ret);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "wc_w", "-1");
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_WC_W, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "wc_w", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "wc_w", "-1");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "wc_w", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "wc_w",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  ret_v = ret.words;
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "wc_w");
    fprintf (trace_fp, "%d", ret_v);
    trace_send_line (g);
  }

  return ret_v;
}

int
guestfs_wc_c (guestfs_h *g,
              const char *path)
{
  struct guestfs_wc_c_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  struct guestfs_wc_c_ret ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "wc_c", 4);
  if (path == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "wc_c", "path");
    return -1;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "wc_c");
    fprintf (trace_fp, " \"%s\"", path);
    trace_send_line (g);
  }

  if (check_state (g, "wc_c") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "wc_c", "-1");
    return -1;
  }
  guestfs___set_busy (g);

  args.path = (char *) path;
  serial = guestfs___send (g, GUESTFS_PROC_WC_C,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_wc_c_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "wc_c", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs___recv (g, "wc_c", &hdr, &err,
        (xdrproc_t) xdr_guestfs_wc_c_ret, (char *) &ret);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "wc_c", "-1");
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_WC_C, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "wc_c", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "wc_c", "-1");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "wc_c", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "wc_c",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  ret_v = ret.chars;
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "wc_c");
    fprintf (trace_fp, "%d", ret_v);
    trace_send_line (g);
  }

  return ret_v;
}

char **
guestfs_head (guestfs_h *g,
              const char *path)
{
  struct guestfs_head_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  struct guestfs_head_ret ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  char **ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "head", 4);
  if (path == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "head", "path");
    return NULL;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "head");
    fprintf (trace_fp, " \"%s\"", path);
    trace_send_line (g);
  }

  if (check_state (g, "head") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "head", "NULL");
    return NULL;
  }
  guestfs___set_busy (g);

  args.path = (char *) path;
  serial = guestfs___send (g, GUESTFS_PROC_HEAD,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_head_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "head", "NULL");
    return NULL;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs___recv (g, "head", &hdr, &err,
        (xdrproc_t) xdr_guestfs_head_ret, (char *) &ret);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "head", "NULL");
    return NULL;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_HEAD, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "head", "NULL");
    return NULL;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "head", "NULL");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "head", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "head",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return NULL;
  }

  guestfs___end_busy (g);
  /* caller will free this, but we need to add a NULL entry */
  ret.lines.lines_val =
    safe_realloc (g, ret.lines.lines_val,
                  sizeof (char *) * (ret.lines.lines_len + 1));
  ret.lines.lines_val[ret.lines.lines_len] = NULL;
  ret_v = ret.lines.lines_val;
  if (trace_flag) {
    size_t i;

    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "head");
    fputs ("[", trace_fp);
    for (i = 0; ret_v[i]; ++i) {
      if (i > 0) fputs (", ", trace_fp);
      fputs ("\"", trace_fp);
      fputs (ret_v[i], trace_fp);
      fputs ("\"", trace_fp);
    }
    fputs ("]", trace_fp);
    trace_send_line (g);
  }

  return ret_v;
}

char **
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
  FILE *trace_fp;
  char **ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "head_n", 6);
  if (path == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "head_n", "path");
    return NULL;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "head_n");
    fprintf (trace_fp, " %d", nrlines);
    fprintf (trace_fp, " \"%s\"", path);
    trace_send_line (g);
  }

  if (check_state (g, "head_n") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "head_n", "NULL");
    return NULL;
  }
  guestfs___set_busy (g);

  args.nrlines = nrlines;
  args.path = (char *) path;
  serial = guestfs___send (g, GUESTFS_PROC_HEAD_N,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_head_n_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "head_n", "NULL");
    return NULL;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs___recv (g, "head_n", &hdr, &err,
        (xdrproc_t) xdr_guestfs_head_n_ret, (char *) &ret);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "head_n", "NULL");
    return NULL;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_HEAD_N, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "head_n", "NULL");
    return NULL;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "head_n", "NULL");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "head_n", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "head_n",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return NULL;
  }

  guestfs___end_busy (g);
  /* caller will free this, but we need to add a NULL entry */
  ret.lines.lines_val =
    safe_realloc (g, ret.lines.lines_val,
                  sizeof (char *) * (ret.lines.lines_len + 1));
  ret.lines.lines_val[ret.lines.lines_len] = NULL;
  ret_v = ret.lines.lines_val;
  if (trace_flag) {
    size_t i;

    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "head_n");
    fputs ("[", trace_fp);
    for (i = 0; ret_v[i]; ++i) {
      if (i > 0) fputs (", ", trace_fp);
      fputs ("\"", trace_fp);
      fputs (ret_v[i], trace_fp);
      fputs ("\"", trace_fp);
    }
    fputs ("]", trace_fp);
    trace_send_line (g);
  }

  return ret_v;
}

char **
guestfs_tail (guestfs_h *g,
              const char *path)
{
  struct guestfs_tail_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  struct guestfs_tail_ret ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  char **ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "tail", 4);
  if (path == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "tail", "path");
    return NULL;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "tail");
    fprintf (trace_fp, " \"%s\"", path);
    trace_send_line (g);
  }

  if (check_state (g, "tail") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "tail", "NULL");
    return NULL;
  }
  guestfs___set_busy (g);

  args.path = (char *) path;
  serial = guestfs___send (g, GUESTFS_PROC_TAIL,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_tail_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "tail", "NULL");
    return NULL;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs___recv (g, "tail", &hdr, &err,
        (xdrproc_t) xdr_guestfs_tail_ret, (char *) &ret);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "tail", "NULL");
    return NULL;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_TAIL, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "tail", "NULL");
    return NULL;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "tail", "NULL");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "tail", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "tail",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return NULL;
  }

  guestfs___end_busy (g);
  /* caller will free this, but we need to add a NULL entry */
  ret.lines.lines_val =
    safe_realloc (g, ret.lines.lines_val,
                  sizeof (char *) * (ret.lines.lines_len + 1));
  ret.lines.lines_val[ret.lines.lines_len] = NULL;
  ret_v = ret.lines.lines_val;
  if (trace_flag) {
    size_t i;

    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "tail");
    fputs ("[", trace_fp);
    for (i = 0; ret_v[i]; ++i) {
      if (i > 0) fputs (", ", trace_fp);
      fputs ("\"", trace_fp);
      fputs (ret_v[i], trace_fp);
      fputs ("\"", trace_fp);
    }
    fputs ("]", trace_fp);
    trace_send_line (g);
  }

  return ret_v;
}

char **
guestfs_tail_n (guestfs_h *g,
                int nrlines,
                const char *path)
{
  struct guestfs_tail_n_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  struct guestfs_tail_n_ret ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  char **ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "tail_n", 6);
  if (path == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "tail_n", "path");
    return NULL;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "tail_n");
    fprintf (trace_fp, " %d", nrlines);
    fprintf (trace_fp, " \"%s\"", path);
    trace_send_line (g);
  }

  if (check_state (g, "tail_n") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "tail_n", "NULL");
    return NULL;
  }
  guestfs___set_busy (g);

  args.nrlines = nrlines;
  args.path = (char *) path;
  serial = guestfs___send (g, GUESTFS_PROC_TAIL_N,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_tail_n_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "tail_n", "NULL");
    return NULL;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs___recv (g, "tail_n", &hdr, &err,
        (xdrproc_t) xdr_guestfs_tail_n_ret, (char *) &ret);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "tail_n", "NULL");
    return NULL;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_TAIL_N, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "tail_n", "NULL");
    return NULL;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "tail_n", "NULL");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "tail_n", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "tail_n",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return NULL;
  }

  guestfs___end_busy (g);
  /* caller will free this, but we need to add a NULL entry */
  ret.lines.lines_val =
    safe_realloc (g, ret.lines.lines_val,
                  sizeof (char *) * (ret.lines.lines_len + 1));
  ret.lines.lines_val[ret.lines.lines_len] = NULL;
  ret_v = ret.lines.lines_val;
  if (trace_flag) {
    size_t i;

    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "tail_n");
    fputs ("[", trace_fp);
    for (i = 0; ret_v[i]; ++i) {
      if (i > 0) fputs (", ", trace_fp);
      fputs ("\"", trace_fp);
      fputs (ret_v[i], trace_fp);
      fputs ("\"", trace_fp);
    }
    fputs ("]", trace_fp);
    trace_send_line (g);
  }

  return ret_v;
}

char *
guestfs_df (guestfs_h *g)
{
  guestfs_message_header hdr;
  guestfs_message_error err;
  struct guestfs_df_ret ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  char *ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "df", 2);
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "df");
    trace_send_line (g);
  }

  if (check_state (g, "df") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "df", "NULL");
    return NULL;
  }
  guestfs___set_busy (g);

  serial = guestfs___send (g, GUESTFS_PROC_DF, progress_hint, 0,
                           NULL, NULL);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "df", "NULL");
    return NULL;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs___recv (g, "df", &hdr, &err,
        (xdrproc_t) xdr_guestfs_df_ret, (char *) &ret);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "df", "NULL");
    return NULL;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_DF, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "df", "NULL");
    return NULL;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "df", "NULL");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "df", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "df",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return NULL;
  }

  guestfs___end_busy (g);
  ret_v = ret.output; /* caller will free */
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "df");
    fprintf (trace_fp, "\"%s\"", ret_v);
    trace_send_line (g);
  }

  return ret_v;
}

char *
guestfs_df_h (guestfs_h *g)
{
  guestfs_message_header hdr;
  guestfs_message_error err;
  struct guestfs_df_h_ret ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  char *ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "df_h", 4);
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "df_h");
    trace_send_line (g);
  }

  if (check_state (g, "df_h") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "df_h", "NULL");
    return NULL;
  }
  guestfs___set_busy (g);

  serial = guestfs___send (g, GUESTFS_PROC_DF_H, progress_hint, 0,
                           NULL, NULL);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "df_h", "NULL");
    return NULL;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs___recv (g, "df_h", &hdr, &err,
        (xdrproc_t) xdr_guestfs_df_h_ret, (char *) &ret);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "df_h", "NULL");
    return NULL;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_DF_H, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "df_h", "NULL");
    return NULL;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "df_h", "NULL");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "df_h", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "df_h",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return NULL;
  }

  guestfs___end_busy (g);
  ret_v = ret.output; /* caller will free */
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "df_h");
    fprintf (trace_fp, "\"%s\"", ret_v);
    trace_send_line (g);
  }

  return ret_v;
}

int64_t
guestfs_du (guestfs_h *g,
            const char *path)
{
  struct guestfs_du_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  struct guestfs_du_ret ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  int64_t ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "du", 2);
  if (path == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "du", "path");
    return -1;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "du");
    fprintf (trace_fp, " \"%s\"", path);
    trace_send_line (g);
  }

  if (check_state (g, "du") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "du", "-1");
    return -1;
  }
  guestfs___set_busy (g);

  args.path = (char *) path;
  serial = guestfs___send (g, GUESTFS_PROC_DU,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_du_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "du", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs___recv (g, "du", &hdr, &err,
        (xdrproc_t) xdr_guestfs_du_ret, (char *) &ret);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "du", "-1");
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_DU, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "du", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "du", "-1");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "du", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "du",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  ret_v = ret.sizekb;
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "du");
    fprintf (trace_fp, "%" PRIi64, ret_v);
    trace_send_line (g);
  }

  return ret_v;
}

char **
guestfs_initrd_list (guestfs_h *g,
                     const char *path)
{
  struct guestfs_initrd_list_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  struct guestfs_initrd_list_ret ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  char **ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "initrd_list", 11);
  if (path == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "initrd_list", "path");
    return NULL;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "initrd_list");
    fprintf (trace_fp, " \"%s\"", path);
    trace_send_line (g);
  }

  if (check_state (g, "initrd_list") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "initrd_list", "NULL");
    return NULL;
  }
  guestfs___set_busy (g);

  args.path = (char *) path;
  serial = guestfs___send (g, GUESTFS_PROC_INITRD_LIST,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_initrd_list_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "initrd_list", "NULL");
    return NULL;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs___recv (g, "initrd_list", &hdr, &err,
        (xdrproc_t) xdr_guestfs_initrd_list_ret, (char *) &ret);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "initrd_list", "NULL");
    return NULL;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_INITRD_LIST, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "initrd_list", "NULL");
    return NULL;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "initrd_list", "NULL");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "initrd_list", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "initrd_list",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return NULL;
  }

  guestfs___end_busy (g);
  /* caller will free this, but we need to add a NULL entry */
  ret.filenames.filenames_val =
    safe_realloc (g, ret.filenames.filenames_val,
                  sizeof (char *) * (ret.filenames.filenames_len + 1));
  ret.filenames.filenames_val[ret.filenames.filenames_len] = NULL;
  ret_v = ret.filenames.filenames_val;
  if (trace_flag) {
    size_t i;

    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "initrd_list");
    fputs ("[", trace_fp);
    for (i = 0; ret_v[i]; ++i) {
      if (i > 0) fputs (", ", trace_fp);
      fputs ("\"", trace_fp);
      fputs (ret_v[i], trace_fp);
      fputs ("\"", trace_fp);
    }
    fputs ("]", trace_fp);
    trace_send_line (g);
  }

  return ret_v;
}

int
guestfs_mount_loop (guestfs_h *g,
                    const char *file,
                    const char *mountpoint)
{
  struct guestfs_mount_loop_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "mount_loop", 10);
  if (file == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "mount_loop", "file");
    return -1;
  }
  if (mountpoint == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "mount_loop", "mountpoint");
    return -1;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "mount_loop");
    fprintf (trace_fp, " \"%s\"", file);
    fprintf (trace_fp, " \"%s\"", mountpoint);
    trace_send_line (g);
  }

  if (check_state (g, "mount_loop") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mount_loop", "-1");
    return -1;
  }
  guestfs___set_busy (g);

  args.file = (char *) file;
  args.mountpoint = (char *) mountpoint;
  serial = guestfs___send (g, GUESTFS_PROC_MOUNT_LOOP,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_mount_loop_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mount_loop", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "mount_loop", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mount_loop", "-1");
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_MOUNT_LOOP, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mount_loop", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mount_loop", "-1");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "mount_loop", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "mount_loop",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  ret_v = 0;
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "mount_loop");
    fprintf (trace_fp, "%d", ret_v);
    trace_send_line (g);
  }

  return ret_v;
}

int
guestfs_mkswap (guestfs_h *g,
                const char *device)
{
  struct guestfs_mkswap_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "mkswap", 6);
  if (device == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "mkswap", "device");
    return -1;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "mkswap");
    fprintf (trace_fp, " \"%s\"", device);
    trace_send_line (g);
  }

  if (check_state (g, "mkswap") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mkswap", "-1");
    return -1;
  }
  guestfs___set_busy (g);

  args.device = (char *) device;
  serial = guestfs___send (g, GUESTFS_PROC_MKSWAP,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_mkswap_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mkswap", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "mkswap", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mkswap", "-1");
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_MKSWAP, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mkswap", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mkswap", "-1");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "mkswap", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "mkswap",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  ret_v = 0;
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "mkswap");
    fprintf (trace_fp, "%d", ret_v);
    trace_send_line (g);
  }

  return ret_v;
}

int
guestfs_mkswap_L (guestfs_h *g,
                  const char *label,
                  const char *device)
{
  struct guestfs_mkswap_L_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "mkswap_L", 8);
  if (label == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "mkswap_L", "label");
    return -1;
  }
  if (device == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "mkswap_L", "device");
    return -1;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "mkswap_L");
    fprintf (trace_fp, " \"%s\"", label);
    fprintf (trace_fp, " \"%s\"", device);
    trace_send_line (g);
  }

  if (check_state (g, "mkswap_L") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mkswap_L", "-1");
    return -1;
  }
  guestfs___set_busy (g);

  args.label = (char *) label;
  args.device = (char *) device;
  serial = guestfs___send (g, GUESTFS_PROC_MKSWAP_L,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_mkswap_L_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mkswap_L", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "mkswap_L", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mkswap_L", "-1");
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_MKSWAP_L, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mkswap_L", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mkswap_L", "-1");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "mkswap_L", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "mkswap_L",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  ret_v = 0;
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "mkswap_L");
    fprintf (trace_fp, "%d", ret_v);
    trace_send_line (g);
  }

  return ret_v;
}

int
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
  FILE *trace_fp;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
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
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "mkswap_U");
    fprintf (trace_fp, " \"%s\"", uuid);
    fprintf (trace_fp, " \"%s\"", device);
    trace_send_line (g);
  }

  if (check_state (g, "mkswap_U") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mkswap_U", "-1");
    return -1;
  }
  guestfs___set_busy (g);

  args.uuid = (char *) uuid;
  args.device = (char *) device;
  serial = guestfs___send (g, GUESTFS_PROC_MKSWAP_U,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_mkswap_U_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mkswap_U", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "mkswap_U", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mkswap_U", "-1");
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_MKSWAP_U, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mkswap_U", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mkswap_U", "-1");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "mkswap_U", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "mkswap_U",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  ret_v = 0;
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "mkswap_U");
    fprintf (trace_fp, "%d", ret_v);
    trace_send_line (g);
  }

  return ret_v;
}

int
guestfs_mknod (guestfs_h *g,
               int mode,
               int devmajor,
               int devminor,
               const char *path)
{
  struct guestfs_mknod_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "mknod", 5);
  if (path == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "mknod", "path");
    return -1;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "mknod");
    fprintf (trace_fp, " %d", mode);
    fprintf (trace_fp, " %d", devmajor);
    fprintf (trace_fp, " %d", devminor);
    fprintf (trace_fp, " \"%s\"", path);
    trace_send_line (g);
  }

  if (check_state (g, "mknod") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mknod", "-1");
    return -1;
  }
  guestfs___set_busy (g);

  args.mode = mode;
  args.devmajor = devmajor;
  args.devminor = devminor;
  args.path = (char *) path;
  serial = guestfs___send (g, GUESTFS_PROC_MKNOD,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_mknod_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mknod", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "mknod", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mknod", "-1");
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_MKNOD, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mknod", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mknod", "-1");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "mknod", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "mknod",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  ret_v = 0;
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "mknod");
    fprintf (trace_fp, "%d", ret_v);
    trace_send_line (g);
  }

  return ret_v;
}

int
guestfs_mkfifo (guestfs_h *g,
                int mode,
                const char *path)
{
  struct guestfs_mkfifo_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "mkfifo", 6);
  if (path == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "mkfifo", "path");
    return -1;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "mkfifo");
    fprintf (trace_fp, " %d", mode);
    fprintf (trace_fp, " \"%s\"", path);
    trace_send_line (g);
  }

  if (check_state (g, "mkfifo") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mkfifo", "-1");
    return -1;
  }
  guestfs___set_busy (g);

  args.mode = mode;
  args.path = (char *) path;
  serial = guestfs___send (g, GUESTFS_PROC_MKFIFO,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_mkfifo_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mkfifo", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "mkfifo", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mkfifo", "-1");
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_MKFIFO, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mkfifo", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mkfifo", "-1");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "mkfifo", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "mkfifo",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  ret_v = 0;
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "mkfifo");
    fprintf (trace_fp, "%d", ret_v);
    trace_send_line (g);
  }

  return ret_v;
}

int
guestfs_mknod_b (guestfs_h *g,
                 int mode,
                 int devmajor,
                 int devminor,
                 const char *path)
{
  struct guestfs_mknod_b_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "mknod_b", 7);
  if (path == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "mknod_b", "path");
    return -1;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "mknod_b");
    fprintf (trace_fp, " %d", mode);
    fprintf (trace_fp, " %d", devmajor);
    fprintf (trace_fp, " %d", devminor);
    fprintf (trace_fp, " \"%s\"", path);
    trace_send_line (g);
  }

  if (check_state (g, "mknod_b") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mknod_b", "-1");
    return -1;
  }
  guestfs___set_busy (g);

  args.mode = mode;
  args.devmajor = devmajor;
  args.devminor = devminor;
  args.path = (char *) path;
  serial = guestfs___send (g, GUESTFS_PROC_MKNOD_B,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_mknod_b_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mknod_b", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "mknod_b", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mknod_b", "-1");
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_MKNOD_B, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mknod_b", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mknod_b", "-1");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "mknod_b", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "mknod_b",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  ret_v = 0;
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "mknod_b");
    fprintf (trace_fp, "%d", ret_v);
    trace_send_line (g);
  }

  return ret_v;
}

int
guestfs_mknod_c (guestfs_h *g,
                 int mode,
                 int devmajor,
                 int devminor,
                 const char *path)
{
  struct guestfs_mknod_c_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "mknod_c", 7);
  if (path == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "mknod_c", "path");
    return -1;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "mknod_c");
    fprintf (trace_fp, " %d", mode);
    fprintf (trace_fp, " %d", devmajor);
    fprintf (trace_fp, " %d", devminor);
    fprintf (trace_fp, " \"%s\"", path);
    trace_send_line (g);
  }

  if (check_state (g, "mknod_c") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mknod_c", "-1");
    return -1;
  }
  guestfs___set_busy (g);

  args.mode = mode;
  args.devmajor = devmajor;
  args.devminor = devminor;
  args.path = (char *) path;
  serial = guestfs___send (g, GUESTFS_PROC_MKNOD_C,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_mknod_c_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mknod_c", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "mknod_c", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mknod_c", "-1");
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_MKNOD_C, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mknod_c", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mknod_c", "-1");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "mknod_c", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "mknod_c",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  ret_v = 0;
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "mknod_c");
    fprintf (trace_fp, "%d", ret_v);
    trace_send_line (g);
  }

  return ret_v;
}

int
guestfs_umask (guestfs_h *g,
               int mask)
{
  struct guestfs_umask_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  struct guestfs_umask_ret ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "umask", 5);
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "umask");
    fprintf (trace_fp, " %d", mask);
    trace_send_line (g);
  }

  if (check_state (g, "umask") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "umask", "-1");
    return -1;
  }
  guestfs___set_busy (g);

  args.mask = mask;
  serial = guestfs___send (g, GUESTFS_PROC_UMASK,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_umask_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "umask", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs___recv (g, "umask", &hdr, &err,
        (xdrproc_t) xdr_guestfs_umask_ret, (char *) &ret);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "umask", "-1");
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_UMASK, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "umask", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "umask", "-1");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "umask", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "umask",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  ret_v = ret.oldmask;
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "umask");
    fprintf (trace_fp, "%d", ret_v);
    trace_send_line (g);
  }

  return ret_v;
}

struct guestfs_dirent_list *
guestfs_readdir (guestfs_h *g,
                 const char *dir)
{
  struct guestfs_readdir_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  struct guestfs_readdir_ret ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  struct guestfs_dirent_list *ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "readdir", 7);
  if (dir == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "readdir", "dir");
    return NULL;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "readdir");
    fprintf (trace_fp, " \"%s\"", dir);
    trace_send_line (g);
  }

  if (check_state (g, "readdir") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "readdir", "NULL");
    return NULL;
  }
  guestfs___set_busy (g);

  args.dir = (char *) dir;
  serial = guestfs___send (g, GUESTFS_PROC_READDIR,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_readdir_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "readdir", "NULL");
    return NULL;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs___recv (g, "readdir", &hdr, &err,
        (xdrproc_t) xdr_guestfs_readdir_ret, (char *) &ret);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "readdir", "NULL");
    return NULL;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_READDIR, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "readdir", "NULL");
    return NULL;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "readdir", "NULL");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "readdir", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "readdir",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return NULL;
  }

  guestfs___end_busy (g);
  /* caller will free this */
  ret_v = safe_memdup (g, &ret.entries, sizeof (ret.entries));
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "readdir");
    fprintf (trace_fp, "<struct guestfs_dirent_list *>");
    trace_send_line (g);
  }

  return ret_v;
}

int
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
  FILE *trace_fp;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
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

    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "sfdiskM");
    fprintf (trace_fp, " \"%s\"", device);
    fputc (' ', trace_fp);
    fputc ('"', trace_fp);
    for (i = 0; lines[i]; ++i) {
      if (i > 0) fputc (' ', trace_fp);
      fputs (lines[i], trace_fp);
    }
    fputc ('"', trace_fp);
    trace_send_line (g);
  }

  if (check_state (g, "sfdiskM") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "sfdiskM", "-1");
    return -1;
  }
  guestfs___set_busy (g);

  args.device = (char *) device;
  args.lines.lines_val = (char **) lines;
  for (args.lines.lines_len = 0; lines[args.lines.lines_len]; args.lines.lines_len++) ;
  serial = guestfs___send (g, GUESTFS_PROC_SFDISKM,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_sfdiskM_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "sfdiskM", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "sfdiskM", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "sfdiskM", "-1");
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_SFDISKM, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "sfdiskM", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "sfdiskM", "-1");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "sfdiskM", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "sfdiskM",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  ret_v = 0;
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "sfdiskM");
    fprintf (trace_fp, "%d", ret_v);
    trace_send_line (g);
  }

  return ret_v;
}

char *
guestfs_zfile (guestfs_h *g,
               const char *meth,
               const char *path)
{
  struct guestfs_zfile_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  struct guestfs_zfile_ret ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  char *ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "zfile", 5);
  if (meth == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "zfile", "meth");
    return NULL;
  }
  if (path == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "zfile", "path");
    return NULL;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "zfile");
    fprintf (trace_fp, " \"%s\"", meth);
    fprintf (trace_fp, " \"%s\"", path);
    trace_send_line (g);
  }

  if (check_state (g, "zfile") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "zfile", "NULL");
    return NULL;
  }
  guestfs___set_busy (g);

  args.meth = (char *) meth;
  args.path = (char *) path;
  serial = guestfs___send (g, GUESTFS_PROC_ZFILE,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_zfile_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "zfile", "NULL");
    return NULL;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs___recv (g, "zfile", &hdr, &err,
        (xdrproc_t) xdr_guestfs_zfile_ret, (char *) &ret);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "zfile", "NULL");
    return NULL;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_ZFILE, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "zfile", "NULL");
    return NULL;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "zfile", "NULL");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "zfile", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "zfile",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return NULL;
  }

  guestfs___end_busy (g);
  ret_v = ret.description; /* caller will free */
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "zfile");
    fprintf (trace_fp, "\"%s\"", ret_v);
    trace_send_line (g);
  }

  return ret_v;
}

struct guestfs_xattr_list *
guestfs_getxattrs (guestfs_h *g,
                   const char *path)
{
  struct guestfs_getxattrs_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  struct guestfs_getxattrs_ret ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  struct guestfs_xattr_list *ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "getxattrs", 9);
  if (path == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "getxattrs", "path");
    return NULL;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "getxattrs");
    fprintf (trace_fp, " \"%s\"", path);
    trace_send_line (g);
  }

  if (check_state (g, "getxattrs") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "getxattrs", "NULL");
    return NULL;
  }
  guestfs___set_busy (g);

  args.path = (char *) path;
  serial = guestfs___send (g, GUESTFS_PROC_GETXATTRS,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_getxattrs_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "getxattrs", "NULL");
    return NULL;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs___recv (g, "getxattrs", &hdr, &err,
        (xdrproc_t) xdr_guestfs_getxattrs_ret, (char *) &ret);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "getxattrs", "NULL");
    return NULL;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_GETXATTRS, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "getxattrs", "NULL");
    return NULL;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "getxattrs", "NULL");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "getxattrs", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "getxattrs",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return NULL;
  }

  guestfs___end_busy (g);
  /* caller will free this */
  ret_v = safe_memdup (g, &ret.xattrs, sizeof (ret.xattrs));
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "getxattrs");
    fprintf (trace_fp, "<struct guestfs_xattr_list *>");
    trace_send_line (g);
  }

  return ret_v;
}

struct guestfs_xattr_list *
guestfs_lgetxattrs (guestfs_h *g,
                    const char *path)
{
  struct guestfs_lgetxattrs_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  struct guestfs_lgetxattrs_ret ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  struct guestfs_xattr_list *ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "lgetxattrs", 10);
  if (path == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "lgetxattrs", "path");
    return NULL;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "lgetxattrs");
    fprintf (trace_fp, " \"%s\"", path);
    trace_send_line (g);
  }

  if (check_state (g, "lgetxattrs") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "lgetxattrs", "NULL");
    return NULL;
  }
  guestfs___set_busy (g);

  args.path = (char *) path;
  serial = guestfs___send (g, GUESTFS_PROC_LGETXATTRS,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_lgetxattrs_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "lgetxattrs", "NULL");
    return NULL;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs___recv (g, "lgetxattrs", &hdr, &err,
        (xdrproc_t) xdr_guestfs_lgetxattrs_ret, (char *) &ret);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "lgetxattrs", "NULL");
    return NULL;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_LGETXATTRS, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "lgetxattrs", "NULL");
    return NULL;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "lgetxattrs", "NULL");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "lgetxattrs", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "lgetxattrs",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return NULL;
  }

  guestfs___end_busy (g);
  /* caller will free this */
  ret_v = safe_memdup (g, &ret.xattrs, sizeof (ret.xattrs));
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "lgetxattrs");
    fprintf (trace_fp, "<struct guestfs_xattr_list *>");
    trace_send_line (g);
  }

  return ret_v;
}

int
guestfs_setxattr (guestfs_h *g,
                  const char *xattr,
                  const char *val,
                  int vallen,
                  const char *path)
{
  struct guestfs_setxattr_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "setxattr", 8);
  if (xattr == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "setxattr", "xattr");
    return -1;
  }
  if (val == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "setxattr", "val");
    return -1;
  }
  if (path == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "setxattr", "path");
    return -1;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "setxattr");
    fprintf (trace_fp, " \"%s\"", xattr);
    fprintf (trace_fp, " \"%s\"", val);
    fprintf (trace_fp, " %d", vallen);
    fprintf (trace_fp, " \"%s\"", path);
    trace_send_line (g);
  }

  if (check_state (g, "setxattr") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "setxattr", "-1");
    return -1;
  }
  guestfs___set_busy (g);

  args.xattr = (char *) xattr;
  args.val = (char *) val;
  args.vallen = vallen;
  args.path = (char *) path;
  serial = guestfs___send (g, GUESTFS_PROC_SETXATTR,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_setxattr_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "setxattr", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "setxattr", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "setxattr", "-1");
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_SETXATTR, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "setxattr", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "setxattr", "-1");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "setxattr", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "setxattr",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  ret_v = 0;
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "setxattr");
    fprintf (trace_fp, "%d", ret_v);
    trace_send_line (g);
  }

  return ret_v;
}

int
guestfs_lsetxattr (guestfs_h *g,
                   const char *xattr,
                   const char *val,
                   int vallen,
                   const char *path)
{
  struct guestfs_lsetxattr_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "lsetxattr", 9);
  if (xattr == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "lsetxattr", "xattr");
    return -1;
  }
  if (val == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "lsetxattr", "val");
    return -1;
  }
  if (path == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "lsetxattr", "path");
    return -1;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "lsetxattr");
    fprintf (trace_fp, " \"%s\"", xattr);
    fprintf (trace_fp, " \"%s\"", val);
    fprintf (trace_fp, " %d", vallen);
    fprintf (trace_fp, " \"%s\"", path);
    trace_send_line (g);
  }

  if (check_state (g, "lsetxattr") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "lsetxattr", "-1");
    return -1;
  }
  guestfs___set_busy (g);

  args.xattr = (char *) xattr;
  args.val = (char *) val;
  args.vallen = vallen;
  args.path = (char *) path;
  serial = guestfs___send (g, GUESTFS_PROC_LSETXATTR,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_lsetxattr_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "lsetxattr", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "lsetxattr", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "lsetxattr", "-1");
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_LSETXATTR, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "lsetxattr", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "lsetxattr", "-1");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "lsetxattr", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "lsetxattr",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  ret_v = 0;
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "lsetxattr");
    fprintf (trace_fp, "%d", ret_v);
    trace_send_line (g);
  }

  return ret_v;
}

int
guestfs_removexattr (guestfs_h *g,
                     const char *xattr,
                     const char *path)
{
  struct guestfs_removexattr_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "removexattr", 11);
  if (xattr == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "removexattr", "xattr");
    return -1;
  }
  if (path == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "removexattr", "path");
    return -1;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "removexattr");
    fprintf (trace_fp, " \"%s\"", xattr);
    fprintf (trace_fp, " \"%s\"", path);
    trace_send_line (g);
  }

  if (check_state (g, "removexattr") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "removexattr", "-1");
    return -1;
  }
  guestfs___set_busy (g);

  args.xattr = (char *) xattr;
  args.path = (char *) path;
  serial = guestfs___send (g, GUESTFS_PROC_REMOVEXATTR,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_removexattr_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "removexattr", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "removexattr", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "removexattr", "-1");
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_REMOVEXATTR, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "removexattr", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "removexattr", "-1");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "removexattr", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "removexattr",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  ret_v = 0;
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "removexattr");
    fprintf (trace_fp, "%d", ret_v);
    trace_send_line (g);
  }

  return ret_v;
}

int
guestfs_lremovexattr (guestfs_h *g,
                      const char *xattr,
                      const char *path)
{
  struct guestfs_lremovexattr_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "lremovexattr", 12);
  if (xattr == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "lremovexattr", "xattr");
    return -1;
  }
  if (path == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "lremovexattr", "path");
    return -1;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "lremovexattr");
    fprintf (trace_fp, " \"%s\"", xattr);
    fprintf (trace_fp, " \"%s\"", path);
    trace_send_line (g);
  }

  if (check_state (g, "lremovexattr") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "lremovexattr", "-1");
    return -1;
  }
  guestfs___set_busy (g);

  args.xattr = (char *) xattr;
  args.path = (char *) path;
  serial = guestfs___send (g, GUESTFS_PROC_LREMOVEXATTR,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_lremovexattr_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "lremovexattr", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "lremovexattr", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "lremovexattr", "-1");
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_LREMOVEXATTR, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "lremovexattr", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "lremovexattr", "-1");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "lremovexattr", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "lremovexattr",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  ret_v = 0;
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "lremovexattr");
    fprintf (trace_fp, "%d", ret_v);
    trace_send_line (g);
  }

  return ret_v;
}

char **
guestfs_mountpoints (guestfs_h *g)
{
  guestfs_message_header hdr;
  guestfs_message_error err;
  struct guestfs_mountpoints_ret ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  char **ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "mountpoints", 11);
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "mountpoints");
    trace_send_line (g);
  }

  if (check_state (g, "mountpoints") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mountpoints", "NULL");
    return NULL;
  }
  guestfs___set_busy (g);

  serial = guestfs___send (g, GUESTFS_PROC_MOUNTPOINTS, progress_hint, 0,
                           NULL, NULL);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mountpoints", "NULL");
    return NULL;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs___recv (g, "mountpoints", &hdr, &err,
        (xdrproc_t) xdr_guestfs_mountpoints_ret, (char *) &ret);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mountpoints", "NULL");
    return NULL;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_MOUNTPOINTS, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mountpoints", "NULL");
    return NULL;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mountpoints", "NULL");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "mountpoints", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "mountpoints",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return NULL;
  }

  guestfs___end_busy (g);
  /* caller will free this, but we need to add a NULL entry */
  ret.mps.mps_val =
    safe_realloc (g, ret.mps.mps_val,
                  sizeof (char *) * (ret.mps.mps_len + 1));
  ret.mps.mps_val[ret.mps.mps_len] = NULL;
  ret_v = ret.mps.mps_val;
  if (trace_flag) {
    size_t i;

    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "mountpoints");
    fputs ("[", trace_fp);
    for (i = 0; ret_v[i]; ++i) {
      if (i > 0) fputs (", ", trace_fp);
      fputs ("\"", trace_fp);
      fputs (ret_v[i], trace_fp);
      fputs ("\"", trace_fp);
    }
    fputs ("]", trace_fp);
    trace_send_line (g);
  }

  return ret_v;
}

int
guestfs_mkmountpoint (guestfs_h *g,
                      const char *exemptpath)
{
  struct guestfs_mkmountpoint_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "mkmountpoint", 12);
  if (exemptpath == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "mkmountpoint", "exemptpath");
    return -1;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "mkmountpoint");
    fprintf (trace_fp, " \"%s\"", exemptpath);
    trace_send_line (g);
  }

  if (check_state (g, "mkmountpoint") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mkmountpoint", "-1");
    return -1;
  }
  guestfs___set_busy (g);

  args.exemptpath = (char *) exemptpath;
  serial = guestfs___send (g, GUESTFS_PROC_MKMOUNTPOINT,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_mkmountpoint_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mkmountpoint", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "mkmountpoint", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mkmountpoint", "-1");
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_MKMOUNTPOINT, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mkmountpoint", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mkmountpoint", "-1");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "mkmountpoint", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "mkmountpoint",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  ret_v = 0;
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "mkmountpoint");
    fprintf (trace_fp, "%d", ret_v);
    trace_send_line (g);
  }

  return ret_v;
}

int
guestfs_rmmountpoint (guestfs_h *g,
                      const char *exemptpath)
{
  struct guestfs_rmmountpoint_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "rmmountpoint", 12);
  if (exemptpath == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "rmmountpoint", "exemptpath");
    return -1;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "rmmountpoint");
    fprintf (trace_fp, " \"%s\"", exemptpath);
    trace_send_line (g);
  }

  if (check_state (g, "rmmountpoint") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "rmmountpoint", "-1");
    return -1;
  }
  guestfs___set_busy (g);

  args.exemptpath = (char *) exemptpath;
  serial = guestfs___send (g, GUESTFS_PROC_RMMOUNTPOINT,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_rmmountpoint_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "rmmountpoint", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "rmmountpoint", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "rmmountpoint", "-1");
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_RMMOUNTPOINT, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "rmmountpoint", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "rmmountpoint", "-1");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "rmmountpoint", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "rmmountpoint",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  ret_v = 0;
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "rmmountpoint");
    fprintf (trace_fp, "%d", ret_v);
    trace_send_line (g);
  }

  return ret_v;
}

char *
guestfs_read_file (guestfs_h *g,
                   const char *path,
                   size_t *size_r)
{
  struct guestfs_read_file_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  struct guestfs_read_file_ret ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  char *ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "read_file", 9);
  if (path == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "read_file", "path");
    return NULL;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "read_file");
    fprintf (trace_fp, " \"%s\"", path);
    trace_send_line (g);
  }

  if (check_state (g, "read_file") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "read_file", "NULL");
    return NULL;
  }
  guestfs___set_busy (g);

  args.path = (char *) path;
  serial = guestfs___send (g, GUESTFS_PROC_READ_FILE,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_read_file_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "read_file", "NULL");
    return NULL;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs___recv (g, "read_file", &hdr, &err,
        (xdrproc_t) xdr_guestfs_read_file_ret, (char *) &ret);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "read_file", "NULL");
    return NULL;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_READ_FILE, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "read_file", "NULL");
    return NULL;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "read_file", "NULL");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "read_file", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "read_file",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return NULL;
  }

  guestfs___end_busy (g);
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
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "read_file");
    guestfs___print_BufferOut (trace_fp, ret_v, *size_r);
    trace_send_line (g);
  }

  return ret_v;
}

char **
guestfs_grep (guestfs_h *g,
              const char *regex,
              const char *path)
{
  struct guestfs_grep_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  struct guestfs_grep_ret ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  char **ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "grep", 4);
  if (regex == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "grep", "regex");
    return NULL;
  }
  if (path == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "grep", "path");
    return NULL;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "grep");
    fprintf (trace_fp, " \"%s\"", regex);
    fprintf (trace_fp, " \"%s\"", path);
    trace_send_line (g);
  }

  if (check_state (g, "grep") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "grep", "NULL");
    return NULL;
  }
  guestfs___set_busy (g);

  args.regex = (char *) regex;
  args.path = (char *) path;
  serial = guestfs___send (g, GUESTFS_PROC_GREP,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_grep_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "grep", "NULL");
    return NULL;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs___recv (g, "grep", &hdr, &err,
        (xdrproc_t) xdr_guestfs_grep_ret, (char *) &ret);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "grep", "NULL");
    return NULL;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_GREP, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "grep", "NULL");
    return NULL;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "grep", "NULL");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "grep", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "grep",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return NULL;
  }

  guestfs___end_busy (g);
  /* caller will free this, but we need to add a NULL entry */
  ret.lines.lines_val =
    safe_realloc (g, ret.lines.lines_val,
                  sizeof (char *) * (ret.lines.lines_len + 1));
  ret.lines.lines_val[ret.lines.lines_len] = NULL;
  ret_v = ret.lines.lines_val;
  if (trace_flag) {
    size_t i;

    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "grep");
    fputs ("[", trace_fp);
    for (i = 0; ret_v[i]; ++i) {
      if (i > 0) fputs (", ", trace_fp);
      fputs ("\"", trace_fp);
      fputs (ret_v[i], trace_fp);
      fputs ("\"", trace_fp);
    }
    fputs ("]", trace_fp);
    trace_send_line (g);
  }

  return ret_v;
}

char **
guestfs_egrep (guestfs_h *g,
               const char *regex,
               const char *path)
{
  struct guestfs_egrep_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  struct guestfs_egrep_ret ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  char **ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "egrep", 5);
  if (regex == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "egrep", "regex");
    return NULL;
  }
  if (path == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "egrep", "path");
    return NULL;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "egrep");
    fprintf (trace_fp, " \"%s\"", regex);
    fprintf (trace_fp, " \"%s\"", path);
    trace_send_line (g);
  }

  if (check_state (g, "egrep") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "egrep", "NULL");
    return NULL;
  }
  guestfs___set_busy (g);

  args.regex = (char *) regex;
  args.path = (char *) path;
  serial = guestfs___send (g, GUESTFS_PROC_EGREP,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_egrep_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "egrep", "NULL");
    return NULL;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs___recv (g, "egrep", &hdr, &err,
        (xdrproc_t) xdr_guestfs_egrep_ret, (char *) &ret);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "egrep", "NULL");
    return NULL;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_EGREP, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "egrep", "NULL");
    return NULL;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "egrep", "NULL");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "egrep", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "egrep",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return NULL;
  }

  guestfs___end_busy (g);
  /* caller will free this, but we need to add a NULL entry */
  ret.lines.lines_val =
    safe_realloc (g, ret.lines.lines_val,
                  sizeof (char *) * (ret.lines.lines_len + 1));
  ret.lines.lines_val[ret.lines.lines_len] = NULL;
  ret_v = ret.lines.lines_val;
  if (trace_flag) {
    size_t i;

    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "egrep");
    fputs ("[", trace_fp);
    for (i = 0; ret_v[i]; ++i) {
      if (i > 0) fputs (", ", trace_fp);
      fputs ("\"", trace_fp);
      fputs (ret_v[i], trace_fp);
      fputs ("\"", trace_fp);
    }
    fputs ("]", trace_fp);
    trace_send_line (g);
  }

  return ret_v;
}

char **
guestfs_fgrep (guestfs_h *g,
               const char *pattern,
               const char *path)
{
  struct guestfs_fgrep_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  struct guestfs_fgrep_ret ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  char **ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "fgrep", 5);
  if (pattern == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "fgrep", "pattern");
    return NULL;
  }
  if (path == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "fgrep", "path");
    return NULL;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "fgrep");
    fprintf (trace_fp, " \"%s\"", pattern);
    fprintf (trace_fp, " \"%s\"", path);
    trace_send_line (g);
  }

  if (check_state (g, "fgrep") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "fgrep", "NULL");
    return NULL;
  }
  guestfs___set_busy (g);

  args.pattern = (char *) pattern;
  args.path = (char *) path;
  serial = guestfs___send (g, GUESTFS_PROC_FGREP,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_fgrep_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "fgrep", "NULL");
    return NULL;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs___recv (g, "fgrep", &hdr, &err,
        (xdrproc_t) xdr_guestfs_fgrep_ret, (char *) &ret);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "fgrep", "NULL");
    return NULL;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_FGREP, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "fgrep", "NULL");
    return NULL;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "fgrep", "NULL");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "fgrep", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "fgrep",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return NULL;
  }

  guestfs___end_busy (g);
  /* caller will free this, but we need to add a NULL entry */
  ret.lines.lines_val =
    safe_realloc (g, ret.lines.lines_val,
                  sizeof (char *) * (ret.lines.lines_len + 1));
  ret.lines.lines_val[ret.lines.lines_len] = NULL;
  ret_v = ret.lines.lines_val;
  if (trace_flag) {
    size_t i;

    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "fgrep");
    fputs ("[", trace_fp);
    for (i = 0; ret_v[i]; ++i) {
      if (i > 0) fputs (", ", trace_fp);
      fputs ("\"", trace_fp);
      fputs (ret_v[i], trace_fp);
      fputs ("\"", trace_fp);
    }
    fputs ("]", trace_fp);
    trace_send_line (g);
  }

  return ret_v;
}

char **
guestfs_grepi (guestfs_h *g,
               const char *regex,
               const char *path)
{
  struct guestfs_grepi_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  struct guestfs_grepi_ret ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  char **ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "grepi", 5);
  if (regex == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "grepi", "regex");
    return NULL;
  }
  if (path == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "grepi", "path");
    return NULL;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "grepi");
    fprintf (trace_fp, " \"%s\"", regex);
    fprintf (trace_fp, " \"%s\"", path);
    trace_send_line (g);
  }

  if (check_state (g, "grepi") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "grepi", "NULL");
    return NULL;
  }
  guestfs___set_busy (g);

  args.regex = (char *) regex;
  args.path = (char *) path;
  serial = guestfs___send (g, GUESTFS_PROC_GREPI,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_grepi_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "grepi", "NULL");
    return NULL;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs___recv (g, "grepi", &hdr, &err,
        (xdrproc_t) xdr_guestfs_grepi_ret, (char *) &ret);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "grepi", "NULL");
    return NULL;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_GREPI, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "grepi", "NULL");
    return NULL;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "grepi", "NULL");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "grepi", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "grepi",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return NULL;
  }

  guestfs___end_busy (g);
  /* caller will free this, but we need to add a NULL entry */
  ret.lines.lines_val =
    safe_realloc (g, ret.lines.lines_val,
                  sizeof (char *) * (ret.lines.lines_len + 1));
  ret.lines.lines_val[ret.lines.lines_len] = NULL;
  ret_v = ret.lines.lines_val;
  if (trace_flag) {
    size_t i;

    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "grepi");
    fputs ("[", trace_fp);
    for (i = 0; ret_v[i]; ++i) {
      if (i > 0) fputs (", ", trace_fp);
      fputs ("\"", trace_fp);
      fputs (ret_v[i], trace_fp);
      fputs ("\"", trace_fp);
    }
    fputs ("]", trace_fp);
    trace_send_line (g);
  }

  return ret_v;
}

char **
guestfs_egrepi (guestfs_h *g,
                const char *regex,
                const char *path)
{
  struct guestfs_egrepi_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  struct guestfs_egrepi_ret ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  char **ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "egrepi", 6);
  if (regex == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "egrepi", "regex");
    return NULL;
  }
  if (path == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "egrepi", "path");
    return NULL;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "egrepi");
    fprintf (trace_fp, " \"%s\"", regex);
    fprintf (trace_fp, " \"%s\"", path);
    trace_send_line (g);
  }

  if (check_state (g, "egrepi") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "egrepi", "NULL");
    return NULL;
  }
  guestfs___set_busy (g);

  args.regex = (char *) regex;
  args.path = (char *) path;
  serial = guestfs___send (g, GUESTFS_PROC_EGREPI,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_egrepi_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "egrepi", "NULL");
    return NULL;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs___recv (g, "egrepi", &hdr, &err,
        (xdrproc_t) xdr_guestfs_egrepi_ret, (char *) &ret);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "egrepi", "NULL");
    return NULL;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_EGREPI, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "egrepi", "NULL");
    return NULL;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "egrepi", "NULL");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "egrepi", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "egrepi",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return NULL;
  }

  guestfs___end_busy (g);
  /* caller will free this, but we need to add a NULL entry */
  ret.lines.lines_val =
    safe_realloc (g, ret.lines.lines_val,
                  sizeof (char *) * (ret.lines.lines_len + 1));
  ret.lines.lines_val[ret.lines.lines_len] = NULL;
  ret_v = ret.lines.lines_val;
  if (trace_flag) {
    size_t i;

    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "egrepi");
    fputs ("[", trace_fp);
    for (i = 0; ret_v[i]; ++i) {
      if (i > 0) fputs (", ", trace_fp);
      fputs ("\"", trace_fp);
      fputs (ret_v[i], trace_fp);
      fputs ("\"", trace_fp);
    }
    fputs ("]", trace_fp);
    trace_send_line (g);
  }

  return ret_v;
}

char **
guestfs_fgrepi (guestfs_h *g,
                const char *pattern,
                const char *path)
{
  struct guestfs_fgrepi_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  struct guestfs_fgrepi_ret ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  char **ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "fgrepi", 6);
  if (pattern == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "fgrepi", "pattern");
    return NULL;
  }
  if (path == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "fgrepi", "path");
    return NULL;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "fgrepi");
    fprintf (trace_fp, " \"%s\"", pattern);
    fprintf (trace_fp, " \"%s\"", path);
    trace_send_line (g);
  }

  if (check_state (g, "fgrepi") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "fgrepi", "NULL");
    return NULL;
  }
  guestfs___set_busy (g);

  args.pattern = (char *) pattern;
  args.path = (char *) path;
  serial = guestfs___send (g, GUESTFS_PROC_FGREPI,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_fgrepi_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "fgrepi", "NULL");
    return NULL;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs___recv (g, "fgrepi", &hdr, &err,
        (xdrproc_t) xdr_guestfs_fgrepi_ret, (char *) &ret);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "fgrepi", "NULL");
    return NULL;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_FGREPI, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "fgrepi", "NULL");
    return NULL;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "fgrepi", "NULL");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "fgrepi", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "fgrepi",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return NULL;
  }

  guestfs___end_busy (g);
  /* caller will free this, but we need to add a NULL entry */
  ret.lines.lines_val =
    safe_realloc (g, ret.lines.lines_val,
                  sizeof (char *) * (ret.lines.lines_len + 1));
  ret.lines.lines_val[ret.lines.lines_len] = NULL;
  ret_v = ret.lines.lines_val;
  if (trace_flag) {
    size_t i;

    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "fgrepi");
    fputs ("[", trace_fp);
    for (i = 0; ret_v[i]; ++i) {
      if (i > 0) fputs (", ", trace_fp);
      fputs ("\"", trace_fp);
      fputs (ret_v[i], trace_fp);
      fputs ("\"", trace_fp);
    }
    fputs ("]", trace_fp);
    trace_send_line (g);
  }

  return ret_v;
}

char **
guestfs_zgrep (guestfs_h *g,
               const char *regex,
               const char *path)
{
  struct guestfs_zgrep_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  struct guestfs_zgrep_ret ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  char **ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "zgrep", 5);
  if (regex == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "zgrep", "regex");
    return NULL;
  }
  if (path == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "zgrep", "path");
    return NULL;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "zgrep");
    fprintf (trace_fp, " \"%s\"", regex);
    fprintf (trace_fp, " \"%s\"", path);
    trace_send_line (g);
  }

  if (check_state (g, "zgrep") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "zgrep", "NULL");
    return NULL;
  }
  guestfs___set_busy (g);

  args.regex = (char *) regex;
  args.path = (char *) path;
  serial = guestfs___send (g, GUESTFS_PROC_ZGREP,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_zgrep_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "zgrep", "NULL");
    return NULL;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs___recv (g, "zgrep", &hdr, &err,
        (xdrproc_t) xdr_guestfs_zgrep_ret, (char *) &ret);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "zgrep", "NULL");
    return NULL;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_ZGREP, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "zgrep", "NULL");
    return NULL;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "zgrep", "NULL");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "zgrep", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "zgrep",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return NULL;
  }

  guestfs___end_busy (g);
  /* caller will free this, but we need to add a NULL entry */
  ret.lines.lines_val =
    safe_realloc (g, ret.lines.lines_val,
                  sizeof (char *) * (ret.lines.lines_len + 1));
  ret.lines.lines_val[ret.lines.lines_len] = NULL;
  ret_v = ret.lines.lines_val;
  if (trace_flag) {
    size_t i;

    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "zgrep");
    fputs ("[", trace_fp);
    for (i = 0; ret_v[i]; ++i) {
      if (i > 0) fputs (", ", trace_fp);
      fputs ("\"", trace_fp);
      fputs (ret_v[i], trace_fp);
      fputs ("\"", trace_fp);
    }
    fputs ("]", trace_fp);
    trace_send_line (g);
  }

  return ret_v;
}

char **
guestfs_zegrep (guestfs_h *g,
                const char *regex,
                const char *path)
{
  struct guestfs_zegrep_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  struct guestfs_zegrep_ret ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  char **ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "zegrep", 6);
  if (regex == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "zegrep", "regex");
    return NULL;
  }
  if (path == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "zegrep", "path");
    return NULL;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "zegrep");
    fprintf (trace_fp, " \"%s\"", regex);
    fprintf (trace_fp, " \"%s\"", path);
    trace_send_line (g);
  }

  if (check_state (g, "zegrep") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "zegrep", "NULL");
    return NULL;
  }
  guestfs___set_busy (g);

  args.regex = (char *) regex;
  args.path = (char *) path;
  serial = guestfs___send (g, GUESTFS_PROC_ZEGREP,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_zegrep_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "zegrep", "NULL");
    return NULL;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs___recv (g, "zegrep", &hdr, &err,
        (xdrproc_t) xdr_guestfs_zegrep_ret, (char *) &ret);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "zegrep", "NULL");
    return NULL;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_ZEGREP, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "zegrep", "NULL");
    return NULL;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "zegrep", "NULL");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "zegrep", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "zegrep",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return NULL;
  }

  guestfs___end_busy (g);
  /* caller will free this, but we need to add a NULL entry */
  ret.lines.lines_val =
    safe_realloc (g, ret.lines.lines_val,
                  sizeof (char *) * (ret.lines.lines_len + 1));
  ret.lines.lines_val[ret.lines.lines_len] = NULL;
  ret_v = ret.lines.lines_val;
  if (trace_flag) {
    size_t i;

    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "zegrep");
    fputs ("[", trace_fp);
    for (i = 0; ret_v[i]; ++i) {
      if (i > 0) fputs (", ", trace_fp);
      fputs ("\"", trace_fp);
      fputs (ret_v[i], trace_fp);
      fputs ("\"", trace_fp);
    }
    fputs ("]", trace_fp);
    trace_send_line (g);
  }

  return ret_v;
}

char **
guestfs_zfgrep (guestfs_h *g,
                const char *pattern,
                const char *path)
{
  struct guestfs_zfgrep_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  struct guestfs_zfgrep_ret ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  char **ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "zfgrep", 6);
  if (pattern == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "zfgrep", "pattern");
    return NULL;
  }
  if (path == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "zfgrep", "path");
    return NULL;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "zfgrep");
    fprintf (trace_fp, " \"%s\"", pattern);
    fprintf (trace_fp, " \"%s\"", path);
    trace_send_line (g);
  }

  if (check_state (g, "zfgrep") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "zfgrep", "NULL");
    return NULL;
  }
  guestfs___set_busy (g);

  args.pattern = (char *) pattern;
  args.path = (char *) path;
  serial = guestfs___send (g, GUESTFS_PROC_ZFGREP,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_zfgrep_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "zfgrep", "NULL");
    return NULL;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs___recv (g, "zfgrep", &hdr, &err,
        (xdrproc_t) xdr_guestfs_zfgrep_ret, (char *) &ret);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "zfgrep", "NULL");
    return NULL;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_ZFGREP, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "zfgrep", "NULL");
    return NULL;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "zfgrep", "NULL");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "zfgrep", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "zfgrep",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return NULL;
  }

  guestfs___end_busy (g);
  /* caller will free this, but we need to add a NULL entry */
  ret.lines.lines_val =
    safe_realloc (g, ret.lines.lines_val,
                  sizeof (char *) * (ret.lines.lines_len + 1));
  ret.lines.lines_val[ret.lines.lines_len] = NULL;
  ret_v = ret.lines.lines_val;
  if (trace_flag) {
    size_t i;

    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "zfgrep");
    fputs ("[", trace_fp);
    for (i = 0; ret_v[i]; ++i) {
      if (i > 0) fputs (", ", trace_fp);
      fputs ("\"", trace_fp);
      fputs (ret_v[i], trace_fp);
      fputs ("\"", trace_fp);
    }
    fputs ("]", trace_fp);
    trace_send_line (g);
  }

  return ret_v;
}

char **
guestfs_zgrepi (guestfs_h *g,
                const char *regex,
                const char *path)
{
  struct guestfs_zgrepi_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  struct guestfs_zgrepi_ret ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  char **ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "zgrepi", 6);
  if (regex == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "zgrepi", "regex");
    return NULL;
  }
  if (path == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "zgrepi", "path");
    return NULL;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "zgrepi");
    fprintf (trace_fp, " \"%s\"", regex);
    fprintf (trace_fp, " \"%s\"", path);
    trace_send_line (g);
  }

  if (check_state (g, "zgrepi") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "zgrepi", "NULL");
    return NULL;
  }
  guestfs___set_busy (g);

  args.regex = (char *) regex;
  args.path = (char *) path;
  serial = guestfs___send (g, GUESTFS_PROC_ZGREPI,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_zgrepi_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "zgrepi", "NULL");
    return NULL;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs___recv (g, "zgrepi", &hdr, &err,
        (xdrproc_t) xdr_guestfs_zgrepi_ret, (char *) &ret);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "zgrepi", "NULL");
    return NULL;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_ZGREPI, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "zgrepi", "NULL");
    return NULL;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "zgrepi", "NULL");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "zgrepi", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "zgrepi",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return NULL;
  }

  guestfs___end_busy (g);
  /* caller will free this, but we need to add a NULL entry */
  ret.lines.lines_val =
    safe_realloc (g, ret.lines.lines_val,
                  sizeof (char *) * (ret.lines.lines_len + 1));
  ret.lines.lines_val[ret.lines.lines_len] = NULL;
  ret_v = ret.lines.lines_val;
  if (trace_flag) {
    size_t i;

    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "zgrepi");
    fputs ("[", trace_fp);
    for (i = 0; ret_v[i]; ++i) {
      if (i > 0) fputs (", ", trace_fp);
      fputs ("\"", trace_fp);
      fputs (ret_v[i], trace_fp);
      fputs ("\"", trace_fp);
    }
    fputs ("]", trace_fp);
    trace_send_line (g);
  }

  return ret_v;
}

char **
guestfs_zegrepi (guestfs_h *g,
                 const char *regex,
                 const char *path)
{
  struct guestfs_zegrepi_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  struct guestfs_zegrepi_ret ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  char **ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "zegrepi", 7);
  if (regex == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "zegrepi", "regex");
    return NULL;
  }
  if (path == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "zegrepi", "path");
    return NULL;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "zegrepi");
    fprintf (trace_fp, " \"%s\"", regex);
    fprintf (trace_fp, " \"%s\"", path);
    trace_send_line (g);
  }

  if (check_state (g, "zegrepi") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "zegrepi", "NULL");
    return NULL;
  }
  guestfs___set_busy (g);

  args.regex = (char *) regex;
  args.path = (char *) path;
  serial = guestfs___send (g, GUESTFS_PROC_ZEGREPI,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_zegrepi_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "zegrepi", "NULL");
    return NULL;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs___recv (g, "zegrepi", &hdr, &err,
        (xdrproc_t) xdr_guestfs_zegrepi_ret, (char *) &ret);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "zegrepi", "NULL");
    return NULL;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_ZEGREPI, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "zegrepi", "NULL");
    return NULL;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "zegrepi", "NULL");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "zegrepi", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "zegrepi",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return NULL;
  }

  guestfs___end_busy (g);
  /* caller will free this, but we need to add a NULL entry */
  ret.lines.lines_val =
    safe_realloc (g, ret.lines.lines_val,
                  sizeof (char *) * (ret.lines.lines_len + 1));
  ret.lines.lines_val[ret.lines.lines_len] = NULL;
  ret_v = ret.lines.lines_val;
  if (trace_flag) {
    size_t i;

    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "zegrepi");
    fputs ("[", trace_fp);
    for (i = 0; ret_v[i]; ++i) {
      if (i > 0) fputs (", ", trace_fp);
      fputs ("\"", trace_fp);
      fputs (ret_v[i], trace_fp);
      fputs ("\"", trace_fp);
    }
    fputs ("]", trace_fp);
    trace_send_line (g);
  }

  return ret_v;
}

char **
guestfs_zfgrepi (guestfs_h *g,
                 const char *pattern,
                 const char *path)
{
  struct guestfs_zfgrepi_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  struct guestfs_zfgrepi_ret ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  char **ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "zfgrepi", 7);
  if (pattern == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "zfgrepi", "pattern");
    return NULL;
  }
  if (path == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "zfgrepi", "path");
    return NULL;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "zfgrepi");
    fprintf (trace_fp, " \"%s\"", pattern);
    fprintf (trace_fp, " \"%s\"", path);
    trace_send_line (g);
  }

  if (check_state (g, "zfgrepi") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "zfgrepi", "NULL");
    return NULL;
  }
  guestfs___set_busy (g);

  args.pattern = (char *) pattern;
  args.path = (char *) path;
  serial = guestfs___send (g, GUESTFS_PROC_ZFGREPI,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_zfgrepi_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "zfgrepi", "NULL");
    return NULL;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs___recv (g, "zfgrepi", &hdr, &err,
        (xdrproc_t) xdr_guestfs_zfgrepi_ret, (char *) &ret);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "zfgrepi", "NULL");
    return NULL;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_ZFGREPI, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "zfgrepi", "NULL");
    return NULL;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "zfgrepi", "NULL");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "zfgrepi", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "zfgrepi",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return NULL;
  }

  guestfs___end_busy (g);
  /* caller will free this, but we need to add a NULL entry */
  ret.lines.lines_val =
    safe_realloc (g, ret.lines.lines_val,
                  sizeof (char *) * (ret.lines.lines_len + 1));
  ret.lines.lines_val[ret.lines.lines_len] = NULL;
  ret_v = ret.lines.lines_val;
  if (trace_flag) {
    size_t i;

    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "zfgrepi");
    fputs ("[", trace_fp);
    for (i = 0; ret_v[i]; ++i) {
      if (i > 0) fputs (", ", trace_fp);
      fputs ("\"", trace_fp);
      fputs (ret_v[i], trace_fp);
      fputs ("\"", trace_fp);
    }
    fputs ("]", trace_fp);
    trace_send_line (g);
  }

  return ret_v;
}

char *
guestfs_realpath (guestfs_h *g,
                  const char *path)
{
  struct guestfs_realpath_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  struct guestfs_realpath_ret ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  char *ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "realpath", 8);
  if (path == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "realpath", "path");
    return NULL;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "realpath");
    fprintf (trace_fp, " \"%s\"", path);
    trace_send_line (g);
  }

  if (check_state (g, "realpath") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "realpath", "NULL");
    return NULL;
  }
  guestfs___set_busy (g);

  args.path = (char *) path;
  serial = guestfs___send (g, GUESTFS_PROC_REALPATH,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_realpath_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "realpath", "NULL");
    return NULL;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs___recv (g, "realpath", &hdr, &err,
        (xdrproc_t) xdr_guestfs_realpath_ret, (char *) &ret);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "realpath", "NULL");
    return NULL;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_REALPATH, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "realpath", "NULL");
    return NULL;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "realpath", "NULL");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "realpath", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "realpath",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return NULL;
  }

  guestfs___end_busy (g);
  ret_v = ret.rpath; /* caller will free */
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "realpath");
    fprintf (trace_fp, "\"%s\"", ret_v);
    trace_send_line (g);
  }

  return ret_v;
}

int
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
  FILE *trace_fp;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
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
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "ln");
    fprintf (trace_fp, " \"%s\"", target);
    fprintf (trace_fp, " \"%s\"", linkname);
    trace_send_line (g);
  }

  if (check_state (g, "ln") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "ln", "-1");
    return -1;
  }
  guestfs___set_busy (g);

  args.target = (char *) target;
  args.linkname = (char *) linkname;
  serial = guestfs___send (g, GUESTFS_PROC_LN,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_ln_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "ln", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "ln", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "ln", "-1");
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_LN, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "ln", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "ln", "-1");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "ln", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "ln",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  ret_v = 0;
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "ln");
    fprintf (trace_fp, "%d", ret_v);
    trace_send_line (g);
  }

  return ret_v;
}

int
guestfs_ln_f (guestfs_h *g,
              const char *target,
              const char *linkname)
{
  struct guestfs_ln_f_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "ln_f", 4);
  if (target == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "ln_f", "target");
    return -1;
  }
  if (linkname == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "ln_f", "linkname");
    return -1;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "ln_f");
    fprintf (trace_fp, " \"%s\"", target);
    fprintf (trace_fp, " \"%s\"", linkname);
    trace_send_line (g);
  }

  if (check_state (g, "ln_f") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "ln_f", "-1");
    return -1;
  }
  guestfs___set_busy (g);

  args.target = (char *) target;
  args.linkname = (char *) linkname;
  serial = guestfs___send (g, GUESTFS_PROC_LN_F,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_ln_f_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "ln_f", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "ln_f", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "ln_f", "-1");
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_LN_F, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "ln_f", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "ln_f", "-1");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "ln_f", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "ln_f",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  ret_v = 0;
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "ln_f");
    fprintf (trace_fp, "%d", ret_v);
    trace_send_line (g);
  }

  return ret_v;
}

int
guestfs_ln_s (guestfs_h *g,
              const char *target,
              const char *linkname)
{
  struct guestfs_ln_s_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "ln_s", 4);
  if (target == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "ln_s", "target");
    return -1;
  }
  if (linkname == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "ln_s", "linkname");
    return -1;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "ln_s");
    fprintf (trace_fp, " \"%s\"", target);
    fprintf (trace_fp, " \"%s\"", linkname);
    trace_send_line (g);
  }

  if (check_state (g, "ln_s") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "ln_s", "-1");
    return -1;
  }
  guestfs___set_busy (g);

  args.target = (char *) target;
  args.linkname = (char *) linkname;
  serial = guestfs___send (g, GUESTFS_PROC_LN_S,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_ln_s_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "ln_s", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "ln_s", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "ln_s", "-1");
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_LN_S, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "ln_s", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "ln_s", "-1");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "ln_s", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "ln_s",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  ret_v = 0;
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "ln_s");
    fprintf (trace_fp, "%d", ret_v);
    trace_send_line (g);
  }

  return ret_v;
}

int
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
  FILE *trace_fp;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
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
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "ln_sf");
    fprintf (trace_fp, " \"%s\"", target);
    fprintf (trace_fp, " \"%s\"", linkname);
    trace_send_line (g);
  }

  if (check_state (g, "ln_sf") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "ln_sf", "-1");
    return -1;
  }
  guestfs___set_busy (g);

  args.target = (char *) target;
  args.linkname = (char *) linkname;
  serial = guestfs___send (g, GUESTFS_PROC_LN_SF,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_ln_sf_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "ln_sf", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "ln_sf", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "ln_sf", "-1");
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_LN_SF, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "ln_sf", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "ln_sf", "-1");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "ln_sf", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "ln_sf",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  ret_v = 0;
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "ln_sf");
    fprintf (trace_fp, "%d", ret_v);
    trace_send_line (g);
  }

  return ret_v;
}

char *
guestfs_readlink (guestfs_h *g,
                  const char *path)
{
  struct guestfs_readlink_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  struct guestfs_readlink_ret ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  char *ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "readlink", 8);
  if (path == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "readlink", "path");
    return NULL;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "readlink");
    fprintf (trace_fp, " \"%s\"", path);
    trace_send_line (g);
  }

  if (check_state (g, "readlink") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "readlink", "NULL");
    return NULL;
  }
  guestfs___set_busy (g);

  args.path = (char *) path;
  serial = guestfs___send (g, GUESTFS_PROC_READLINK,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_readlink_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "readlink", "NULL");
    return NULL;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs___recv (g, "readlink", &hdr, &err,
        (xdrproc_t) xdr_guestfs_readlink_ret, (char *) &ret);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "readlink", "NULL");
    return NULL;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_READLINK, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "readlink", "NULL");
    return NULL;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "readlink", "NULL");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "readlink", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "readlink",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return NULL;
  }

  guestfs___end_busy (g);
  ret_v = ret.link; /* caller will free */
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "readlink");
    fprintf (trace_fp, "\"%s\"", ret_v);
    trace_send_line (g);
  }

  return ret_v;
}

int
guestfs_fallocate (guestfs_h *g,
                   const char *path,
                   int len)
{
  struct guestfs_fallocate_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "fallocate", 9);
  if (path == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "fallocate", "path");
    return -1;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "fallocate");
    fprintf (trace_fp, " \"%s\"", path);
    fprintf (trace_fp, " %d", len);
    trace_send_line (g);
  }

  if (check_state (g, "fallocate") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "fallocate", "-1");
    return -1;
  }
  guestfs___set_busy (g);

  args.path = (char *) path;
  args.len = len;
  serial = guestfs___send (g, GUESTFS_PROC_FALLOCATE,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_fallocate_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "fallocate", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "fallocate", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "fallocate", "-1");
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_FALLOCATE, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "fallocate", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "fallocate", "-1");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "fallocate", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "fallocate",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  ret_v = 0;
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "fallocate");
    fprintf (trace_fp, "%d", ret_v);
    trace_send_line (g);
  }

  return ret_v;
}

int
guestfs_swapon_device (guestfs_h *g,
                       const char *device)
{
  struct guestfs_swapon_device_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "swapon_device", 13);
  if (device == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "swapon_device", "device");
    return -1;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "swapon_device");
    fprintf (trace_fp, " \"%s\"", device);
    trace_send_line (g);
  }

  if (check_state (g, "swapon_device") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "swapon_device", "-1");
    return -1;
  }
  guestfs___set_busy (g);

  args.device = (char *) device;
  serial = guestfs___send (g, GUESTFS_PROC_SWAPON_DEVICE,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_swapon_device_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "swapon_device", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "swapon_device", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "swapon_device", "-1");
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_SWAPON_DEVICE, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "swapon_device", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "swapon_device", "-1");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "swapon_device", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "swapon_device",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  ret_v = 0;
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "swapon_device");
    fprintf (trace_fp, "%d", ret_v);
    trace_send_line (g);
  }

  return ret_v;
}

int
guestfs_swapoff_device (guestfs_h *g,
                        const char *device)
{
  struct guestfs_swapoff_device_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "swapoff_device", 14);
  if (device == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "swapoff_device", "device");
    return -1;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "swapoff_device");
    fprintf (trace_fp, " \"%s\"", device);
    trace_send_line (g);
  }

  if (check_state (g, "swapoff_device") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "swapoff_device", "-1");
    return -1;
  }
  guestfs___set_busy (g);

  args.device = (char *) device;
  serial = guestfs___send (g, GUESTFS_PROC_SWAPOFF_DEVICE,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_swapoff_device_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "swapoff_device", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "swapoff_device", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "swapoff_device", "-1");
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_SWAPOFF_DEVICE, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "swapoff_device", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "swapoff_device", "-1");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "swapoff_device", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "swapoff_device",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  ret_v = 0;
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "swapoff_device");
    fprintf (trace_fp, "%d", ret_v);
    trace_send_line (g);
  }

  return ret_v;
}

int
guestfs_swapon_file (guestfs_h *g,
                     const char *file)
{
  struct guestfs_swapon_file_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "swapon_file", 11);
  if (file == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "swapon_file", "file");
    return -1;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "swapon_file");
    fprintf (trace_fp, " \"%s\"", file);
    trace_send_line (g);
  }

  if (check_state (g, "swapon_file") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "swapon_file", "-1");
    return -1;
  }
  guestfs___set_busy (g);

  args.file = (char *) file;
  serial = guestfs___send (g, GUESTFS_PROC_SWAPON_FILE,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_swapon_file_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "swapon_file", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "swapon_file", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "swapon_file", "-1");
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_SWAPON_FILE, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "swapon_file", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "swapon_file", "-1");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "swapon_file", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "swapon_file",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  ret_v = 0;
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "swapon_file");
    fprintf (trace_fp, "%d", ret_v);
    trace_send_line (g);
  }

  return ret_v;
}

int
guestfs_swapoff_file (guestfs_h *g,
                      const char *file)
{
  struct guestfs_swapoff_file_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "swapoff_file", 12);
  if (file == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "swapoff_file", "file");
    return -1;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "swapoff_file");
    fprintf (trace_fp, " \"%s\"", file);
    trace_send_line (g);
  }

  if (check_state (g, "swapoff_file") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "swapoff_file", "-1");
    return -1;
  }
  guestfs___set_busy (g);

  args.file = (char *) file;
  serial = guestfs___send (g, GUESTFS_PROC_SWAPOFF_FILE,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_swapoff_file_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "swapoff_file", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "swapoff_file", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "swapoff_file", "-1");
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_SWAPOFF_FILE, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "swapoff_file", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "swapoff_file", "-1");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "swapoff_file", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "swapoff_file",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  ret_v = 0;
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "swapoff_file");
    fprintf (trace_fp, "%d", ret_v);
    trace_send_line (g);
  }

  return ret_v;
}

int
guestfs_swapon_label (guestfs_h *g,
                      const char *label)
{
  struct guestfs_swapon_label_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "swapon_label", 12);
  if (label == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "swapon_label", "label");
    return -1;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "swapon_label");
    fprintf (trace_fp, " \"%s\"", label);
    trace_send_line (g);
  }

  if (check_state (g, "swapon_label") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "swapon_label", "-1");
    return -1;
  }
  guestfs___set_busy (g);

  args.label = (char *) label;
  serial = guestfs___send (g, GUESTFS_PROC_SWAPON_LABEL,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_swapon_label_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "swapon_label", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "swapon_label", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "swapon_label", "-1");
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_SWAPON_LABEL, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "swapon_label", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "swapon_label", "-1");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "swapon_label", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "swapon_label",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  ret_v = 0;
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "swapon_label");
    fprintf (trace_fp, "%d", ret_v);
    trace_send_line (g);
  }

  return ret_v;
}

int
guestfs_swapoff_label (guestfs_h *g,
                       const char *label)
{
  struct guestfs_swapoff_label_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "swapoff_label", 13);
  if (label == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "swapoff_label", "label");
    return -1;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "swapoff_label");
    fprintf (trace_fp, " \"%s\"", label);
    trace_send_line (g);
  }

  if (check_state (g, "swapoff_label") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "swapoff_label", "-1");
    return -1;
  }
  guestfs___set_busy (g);

  args.label = (char *) label;
  serial = guestfs___send (g, GUESTFS_PROC_SWAPOFF_LABEL,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_swapoff_label_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "swapoff_label", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "swapoff_label", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "swapoff_label", "-1");
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_SWAPOFF_LABEL, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "swapoff_label", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "swapoff_label", "-1");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "swapoff_label", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "swapoff_label",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  ret_v = 0;
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "swapoff_label");
    fprintf (trace_fp, "%d", ret_v);
    trace_send_line (g);
  }

  return ret_v;
}

int
guestfs_swapon_uuid (guestfs_h *g,
                     const char *uuid)
{
  struct guestfs_swapon_uuid_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "swapon_uuid", 11);
  if (uuid == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "swapon_uuid", "uuid");
    return -1;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "swapon_uuid");
    fprintf (trace_fp, " \"%s\"", uuid);
    trace_send_line (g);
  }

  if (check_state (g, "swapon_uuid") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "swapon_uuid", "-1");
    return -1;
  }
  guestfs___set_busy (g);

  args.uuid = (char *) uuid;
  serial = guestfs___send (g, GUESTFS_PROC_SWAPON_UUID,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_swapon_uuid_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "swapon_uuid", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "swapon_uuid", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "swapon_uuid", "-1");
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_SWAPON_UUID, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "swapon_uuid", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "swapon_uuid", "-1");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "swapon_uuid", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "swapon_uuid",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  ret_v = 0;
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "swapon_uuid");
    fprintf (trace_fp, "%d", ret_v);
    trace_send_line (g);
  }

  return ret_v;
}

int
guestfs_swapoff_uuid (guestfs_h *g,
                      const char *uuid)
{
  struct guestfs_swapoff_uuid_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "swapoff_uuid", 12);
  if (uuid == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "swapoff_uuid", "uuid");
    return -1;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "swapoff_uuid");
    fprintf (trace_fp, " \"%s\"", uuid);
    trace_send_line (g);
  }

  if (check_state (g, "swapoff_uuid") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "swapoff_uuid", "-1");
    return -1;
  }
  guestfs___set_busy (g);

  args.uuid = (char *) uuid;
  serial = guestfs___send (g, GUESTFS_PROC_SWAPOFF_UUID,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_swapoff_uuid_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "swapoff_uuid", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "swapoff_uuid", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "swapoff_uuid", "-1");
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_SWAPOFF_UUID, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "swapoff_uuid", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "swapoff_uuid", "-1");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "swapoff_uuid", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "swapoff_uuid",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  ret_v = 0;
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "swapoff_uuid");
    fprintf (trace_fp, "%d", ret_v);
    trace_send_line (g);
  }

  return ret_v;
}

int
guestfs_mkswap_file (guestfs_h *g,
                     const char *path)
{
  struct guestfs_mkswap_file_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "mkswap_file", 11);
  if (path == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "mkswap_file", "path");
    return -1;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "mkswap_file");
    fprintf (trace_fp, " \"%s\"", path);
    trace_send_line (g);
  }

  if (check_state (g, "mkswap_file") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mkswap_file", "-1");
    return -1;
  }
  guestfs___set_busy (g);

  args.path = (char *) path;
  serial = guestfs___send (g, GUESTFS_PROC_MKSWAP_FILE,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_mkswap_file_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mkswap_file", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "mkswap_file", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mkswap_file", "-1");
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_MKSWAP_FILE, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mkswap_file", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mkswap_file", "-1");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "mkswap_file", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "mkswap_file",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  ret_v = 0;
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "mkswap_file");
    fprintf (trace_fp, "%d", ret_v);
    trace_send_line (g);
  }

  return ret_v;
}

int
guestfs_inotify_init (guestfs_h *g,
                      int maxevents)
{
  struct guestfs_inotify_init_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "inotify_init", 12);
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "inotify_init");
    fprintf (trace_fp, " %d", maxevents);
    trace_send_line (g);
  }

  if (check_state (g, "inotify_init") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "inotify_init", "-1");
    return -1;
  }
  guestfs___set_busy (g);

  args.maxevents = maxevents;
  serial = guestfs___send (g, GUESTFS_PROC_INOTIFY_INIT,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_inotify_init_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "inotify_init", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "inotify_init", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "inotify_init", "-1");
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_INOTIFY_INIT, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "inotify_init", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "inotify_init", "-1");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "inotify_init", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "inotify_init",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  ret_v = 0;
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "inotify_init");
    fprintf (trace_fp, "%d", ret_v);
    trace_send_line (g);
  }

  return ret_v;
}

int64_t
guestfs_inotify_add_watch (guestfs_h *g,
                           const char *path,
                           int mask)
{
  struct guestfs_inotify_add_watch_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  struct guestfs_inotify_add_watch_ret ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  int64_t ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "inotify_add_watch", 17);
  if (path == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "inotify_add_watch", "path");
    return -1;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "inotify_add_watch");
    fprintf (trace_fp, " \"%s\"", path);
    fprintf (trace_fp, " %d", mask);
    trace_send_line (g);
  }

  if (check_state (g, "inotify_add_watch") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "inotify_add_watch", "-1");
    return -1;
  }
  guestfs___set_busy (g);

  args.path = (char *) path;
  args.mask = mask;
  serial = guestfs___send (g, GUESTFS_PROC_INOTIFY_ADD_WATCH,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_inotify_add_watch_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "inotify_add_watch", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs___recv (g, "inotify_add_watch", &hdr, &err,
        (xdrproc_t) xdr_guestfs_inotify_add_watch_ret, (char *) &ret);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "inotify_add_watch", "-1");
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_INOTIFY_ADD_WATCH, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "inotify_add_watch", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "inotify_add_watch", "-1");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "inotify_add_watch", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "inotify_add_watch",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  ret_v = ret.wd;
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "inotify_add_watch");
    fprintf (trace_fp, "%" PRIi64, ret_v);
    trace_send_line (g);
  }

  return ret_v;
}

int
guestfs_inotify_rm_watch (guestfs_h *g,
                          int wd)
{
  struct guestfs_inotify_rm_watch_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "inotify_rm_watch", 16);
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "inotify_rm_watch");
    fprintf (trace_fp, " %d", wd);
    trace_send_line (g);
  }

  if (check_state (g, "inotify_rm_watch") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "inotify_rm_watch", "-1");
    return -1;
  }
  guestfs___set_busy (g);

  args.wd = wd;
  serial = guestfs___send (g, GUESTFS_PROC_INOTIFY_RM_WATCH,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_inotify_rm_watch_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "inotify_rm_watch", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "inotify_rm_watch", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "inotify_rm_watch", "-1");
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_INOTIFY_RM_WATCH, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "inotify_rm_watch", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "inotify_rm_watch", "-1");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "inotify_rm_watch", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "inotify_rm_watch",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  ret_v = 0;
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "inotify_rm_watch");
    fprintf (trace_fp, "%d", ret_v);
    trace_send_line (g);
  }

  return ret_v;
}

struct guestfs_inotify_event_list *
guestfs_inotify_read (guestfs_h *g)
{
  guestfs_message_header hdr;
  guestfs_message_error err;
  struct guestfs_inotify_read_ret ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  struct guestfs_inotify_event_list *ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "inotify_read", 12);
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "inotify_read");
    trace_send_line (g);
  }

  if (check_state (g, "inotify_read") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "inotify_read", "NULL");
    return NULL;
  }
  guestfs___set_busy (g);

  serial = guestfs___send (g, GUESTFS_PROC_INOTIFY_READ, progress_hint, 0,
                           NULL, NULL);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "inotify_read", "NULL");
    return NULL;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs___recv (g, "inotify_read", &hdr, &err,
        (xdrproc_t) xdr_guestfs_inotify_read_ret, (char *) &ret);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "inotify_read", "NULL");
    return NULL;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_INOTIFY_READ, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "inotify_read", "NULL");
    return NULL;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "inotify_read", "NULL");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "inotify_read", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "inotify_read",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return NULL;
  }

  guestfs___end_busy (g);
  /* caller will free this */
  ret_v = safe_memdup (g, &ret.events, sizeof (ret.events));
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "inotify_read");
    fprintf (trace_fp, "<struct guestfs_inotify_event_list *>");
    trace_send_line (g);
  }

  return ret_v;
}

char **
guestfs_inotify_files (guestfs_h *g)
{
  guestfs_message_header hdr;
  guestfs_message_error err;
  struct guestfs_inotify_files_ret ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  char **ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "inotify_files", 13);
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "inotify_files");
    trace_send_line (g);
  }

  if (check_state (g, "inotify_files") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "inotify_files", "NULL");
    return NULL;
  }
  guestfs___set_busy (g);

  serial = guestfs___send (g, GUESTFS_PROC_INOTIFY_FILES, progress_hint, 0,
                           NULL, NULL);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "inotify_files", "NULL");
    return NULL;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs___recv (g, "inotify_files", &hdr, &err,
        (xdrproc_t) xdr_guestfs_inotify_files_ret, (char *) &ret);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "inotify_files", "NULL");
    return NULL;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_INOTIFY_FILES, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "inotify_files", "NULL");
    return NULL;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "inotify_files", "NULL");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "inotify_files", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "inotify_files",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return NULL;
  }

  guestfs___end_busy (g);
  /* caller will free this, but we need to add a NULL entry */
  ret.paths.paths_val =
    safe_realloc (g, ret.paths.paths_val,
                  sizeof (char *) * (ret.paths.paths_len + 1));
  ret.paths.paths_val[ret.paths.paths_len] = NULL;
  ret_v = ret.paths.paths_val;
  if (trace_flag) {
    size_t i;

    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "inotify_files");
    fputs ("[", trace_fp);
    for (i = 0; ret_v[i]; ++i) {
      if (i > 0) fputs (", ", trace_fp);
      fputs ("\"", trace_fp);
      fputs (ret_v[i], trace_fp);
      fputs ("\"", trace_fp);
    }
    fputs ("]", trace_fp);
    trace_send_line (g);
  }

  return ret_v;
}

int
guestfs_inotify_close (guestfs_h *g)
{
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "inotify_close", 13);
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "inotify_close");
    trace_send_line (g);
  }

  if (check_state (g, "inotify_close") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "inotify_close", "-1");
    return -1;
  }
  guestfs___set_busy (g);

  serial = guestfs___send (g, GUESTFS_PROC_INOTIFY_CLOSE, progress_hint, 0,
                           NULL, NULL);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "inotify_close", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "inotify_close", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "inotify_close", "-1");
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_INOTIFY_CLOSE, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "inotify_close", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "inotify_close", "-1");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "inotify_close", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "inotify_close",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  ret_v = 0;
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "inotify_close");
    fprintf (trace_fp, "%d", ret_v);
    trace_send_line (g);
  }

  return ret_v;
}

int
guestfs_setcon (guestfs_h *g,
                const char *context)
{
  struct guestfs_setcon_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "setcon", 6);
  if (context == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "setcon", "context");
    return -1;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "setcon");
    fprintf (trace_fp, " \"%s\"", context);
    trace_send_line (g);
  }

  if (check_state (g, "setcon") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "setcon", "-1");
    return -1;
  }
  guestfs___set_busy (g);

  args.context = (char *) context;
  serial = guestfs___send (g, GUESTFS_PROC_SETCON,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_setcon_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "setcon", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "setcon", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "setcon", "-1");
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_SETCON, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "setcon", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "setcon", "-1");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "setcon", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "setcon",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  ret_v = 0;
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "setcon");
    fprintf (trace_fp, "%d", ret_v);
    trace_send_line (g);
  }

  return ret_v;
}

char *
guestfs_getcon (guestfs_h *g)
{
  guestfs_message_header hdr;
  guestfs_message_error err;
  struct guestfs_getcon_ret ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  char *ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "getcon", 6);
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "getcon");
    trace_send_line (g);
  }

  if (check_state (g, "getcon") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "getcon", "NULL");
    return NULL;
  }
  guestfs___set_busy (g);

  serial = guestfs___send (g, GUESTFS_PROC_GETCON, progress_hint, 0,
                           NULL, NULL);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "getcon", "NULL");
    return NULL;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs___recv (g, "getcon", &hdr, &err,
        (xdrproc_t) xdr_guestfs_getcon_ret, (char *) &ret);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "getcon", "NULL");
    return NULL;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_GETCON, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "getcon", "NULL");
    return NULL;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "getcon", "NULL");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "getcon", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "getcon",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return NULL;
  }

  guestfs___end_busy (g);
  ret_v = ret.context; /* caller will free */
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "getcon");
    fprintf (trace_fp, "\"%s\"", ret_v);
    trace_send_line (g);
  }

  return ret_v;
}

int
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
  FILE *trace_fp;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
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
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "mkfs_b");
    fprintf (trace_fp, " \"%s\"", fstype);
    fprintf (trace_fp, " %d", blocksize);
    fprintf (trace_fp, " \"%s\"", device);
    trace_send_line (g);
  }

  if (check_state (g, "mkfs_b") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mkfs_b", "-1");
    return -1;
  }
  guestfs___set_busy (g);

  args.fstype = (char *) fstype;
  args.blocksize = blocksize;
  args.device = (char *) device;
  serial = guestfs___send (g, GUESTFS_PROC_MKFS_B,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_mkfs_b_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mkfs_b", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "mkfs_b", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mkfs_b", "-1");
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_MKFS_B, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mkfs_b", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mkfs_b", "-1");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "mkfs_b", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "mkfs_b",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  ret_v = 0;
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "mkfs_b");
    fprintf (trace_fp, "%d", ret_v);
    trace_send_line (g);
  }

  return ret_v;
}

int
guestfs_mke2journal (guestfs_h *g,
                     int blocksize,
                     const char *device)
{
  struct guestfs_mke2journal_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "mke2journal", 11);
  if (device == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "mke2journal", "device");
    return -1;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "mke2journal");
    fprintf (trace_fp, " %d", blocksize);
    fprintf (trace_fp, " \"%s\"", device);
    trace_send_line (g);
  }

  if (check_state (g, "mke2journal") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mke2journal", "-1");
    return -1;
  }
  guestfs___set_busy (g);

  args.blocksize = blocksize;
  args.device = (char *) device;
  serial = guestfs___send (g, GUESTFS_PROC_MKE2JOURNAL,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_mke2journal_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mke2journal", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "mke2journal", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mke2journal", "-1");
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_MKE2JOURNAL, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mke2journal", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mke2journal", "-1");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "mke2journal", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "mke2journal",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  ret_v = 0;
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "mke2journal");
    fprintf (trace_fp, "%d", ret_v);
    trace_send_line (g);
  }

  return ret_v;
}

int
guestfs_mke2journal_L (guestfs_h *g,
                       int blocksize,
                       const char *label,
                       const char *device)
{
  struct guestfs_mke2journal_L_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "mke2journal_L", 13);
  if (label == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "mke2journal_L", "label");
    return -1;
  }
  if (device == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "mke2journal_L", "device");
    return -1;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "mke2journal_L");
    fprintf (trace_fp, " %d", blocksize);
    fprintf (trace_fp, " \"%s\"", label);
    fprintf (trace_fp, " \"%s\"", device);
    trace_send_line (g);
  }

  if (check_state (g, "mke2journal_L") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mke2journal_L", "-1");
    return -1;
  }
  guestfs___set_busy (g);

  args.blocksize = blocksize;
  args.label = (char *) label;
  args.device = (char *) device;
  serial = guestfs___send (g, GUESTFS_PROC_MKE2JOURNAL_L,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_mke2journal_L_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mke2journal_L", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "mke2journal_L", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mke2journal_L", "-1");
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_MKE2JOURNAL_L, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mke2journal_L", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mke2journal_L", "-1");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "mke2journal_L", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "mke2journal_L",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  ret_v = 0;
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "mke2journal_L");
    fprintf (trace_fp, "%d", ret_v);
    trace_send_line (g);
  }

  return ret_v;
}

int
guestfs_mke2journal_U (guestfs_h *g,
                       int blocksize,
                       const char *uuid,
                       const char *device)
{
  struct guestfs_mke2journal_U_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "mke2journal_U", 13);
  if (uuid == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "mke2journal_U", "uuid");
    return -1;
  }
  if (device == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "mke2journal_U", "device");
    return -1;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "mke2journal_U");
    fprintf (trace_fp, " %d", blocksize);
    fprintf (trace_fp, " \"%s\"", uuid);
    fprintf (trace_fp, " \"%s\"", device);
    trace_send_line (g);
  }

  if (check_state (g, "mke2journal_U") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mke2journal_U", "-1");
    return -1;
  }
  guestfs___set_busy (g);

  args.blocksize = blocksize;
  args.uuid = (char *) uuid;
  args.device = (char *) device;
  serial = guestfs___send (g, GUESTFS_PROC_MKE2JOURNAL_U,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_mke2journal_U_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mke2journal_U", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "mke2journal_U", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mke2journal_U", "-1");
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_MKE2JOURNAL_U, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mke2journal_U", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mke2journal_U", "-1");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "mke2journal_U", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "mke2journal_U",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  ret_v = 0;
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "mke2journal_U");
    fprintf (trace_fp, "%d", ret_v);
    trace_send_line (g);
  }

  return ret_v;
}

int
guestfs_mke2fs_J (guestfs_h *g,
                  const char *fstype,
                  int blocksize,
                  const char *device,
                  const char *journal)
{
  struct guestfs_mke2fs_J_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "mke2fs_J", 8);
  if (fstype == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "mke2fs_J", "fstype");
    return -1;
  }
  if (device == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "mke2fs_J", "device");
    return -1;
  }
  if (journal == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "mke2fs_J", "journal");
    return -1;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "mke2fs_J");
    fprintf (trace_fp, " \"%s\"", fstype);
    fprintf (trace_fp, " %d", blocksize);
    fprintf (trace_fp, " \"%s\"", device);
    fprintf (trace_fp, " \"%s\"", journal);
    trace_send_line (g);
  }

  if (check_state (g, "mke2fs_J") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mke2fs_J", "-1");
    return -1;
  }
  guestfs___set_busy (g);

  args.fstype = (char *) fstype;
  args.blocksize = blocksize;
  args.device = (char *) device;
  args.journal = (char *) journal;
  serial = guestfs___send (g, GUESTFS_PROC_MKE2FS_J,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_mke2fs_J_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mke2fs_J", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "mke2fs_J", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mke2fs_J", "-1");
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_MKE2FS_J, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mke2fs_J", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mke2fs_J", "-1");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "mke2fs_J", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "mke2fs_J",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  ret_v = 0;
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "mke2fs_J");
    fprintf (trace_fp, "%d", ret_v);
    trace_send_line (g);
  }

  return ret_v;
}

int
guestfs_mke2fs_JL (guestfs_h *g,
                   const char *fstype,
                   int blocksize,
                   const char *device,
                   const char *label)
{
  struct guestfs_mke2fs_JL_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "mke2fs_JL", 9);
  if (fstype == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "mke2fs_JL", "fstype");
    return -1;
  }
  if (device == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "mke2fs_JL", "device");
    return -1;
  }
  if (label == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "mke2fs_JL", "label");
    return -1;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "mke2fs_JL");
    fprintf (trace_fp, " \"%s\"", fstype);
    fprintf (trace_fp, " %d", blocksize);
    fprintf (trace_fp, " \"%s\"", device);
    fprintf (trace_fp, " \"%s\"", label);
    trace_send_line (g);
  }

  if (check_state (g, "mke2fs_JL") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mke2fs_JL", "-1");
    return -1;
  }
  guestfs___set_busy (g);

  args.fstype = (char *) fstype;
  args.blocksize = blocksize;
  args.device = (char *) device;
  args.label = (char *) label;
  serial = guestfs___send (g, GUESTFS_PROC_MKE2FS_JL,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_mke2fs_JL_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mke2fs_JL", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "mke2fs_JL", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mke2fs_JL", "-1");
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_MKE2FS_JL, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mke2fs_JL", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mke2fs_JL", "-1");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "mke2fs_JL", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "mke2fs_JL",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  ret_v = 0;
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "mke2fs_JL");
    fprintf (trace_fp, "%d", ret_v);
    trace_send_line (g);
  }

  return ret_v;
}

int
guestfs_mke2fs_JU (guestfs_h *g,
                   const char *fstype,
                   int blocksize,
                   const char *device,
                   const char *uuid)
{
  struct guestfs_mke2fs_JU_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "mke2fs_JU", 9);
  if (fstype == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "mke2fs_JU", "fstype");
    return -1;
  }
  if (device == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "mke2fs_JU", "device");
    return -1;
  }
  if (uuid == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "mke2fs_JU", "uuid");
    return -1;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "mke2fs_JU");
    fprintf (trace_fp, " \"%s\"", fstype);
    fprintf (trace_fp, " %d", blocksize);
    fprintf (trace_fp, " \"%s\"", device);
    fprintf (trace_fp, " \"%s\"", uuid);
    trace_send_line (g);
  }

  if (check_state (g, "mke2fs_JU") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mke2fs_JU", "-1");
    return -1;
  }
  guestfs___set_busy (g);

  args.fstype = (char *) fstype;
  args.blocksize = blocksize;
  args.device = (char *) device;
  args.uuid = (char *) uuid;
  serial = guestfs___send (g, GUESTFS_PROC_MKE2FS_JU,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_mke2fs_JU_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mke2fs_JU", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "mke2fs_JU", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mke2fs_JU", "-1");
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_MKE2FS_JU, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mke2fs_JU", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mke2fs_JU", "-1");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "mke2fs_JU", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "mke2fs_JU",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  ret_v = 0;
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "mke2fs_JU");
    fprintf (trace_fp, "%d", ret_v);
    trace_send_line (g);
  }

  return ret_v;
}

int
guestfs_modprobe (guestfs_h *g,
                  const char *modulename)
{
  struct guestfs_modprobe_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "modprobe", 8);
  if (modulename == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "modprobe", "modulename");
    return -1;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "modprobe");
    fprintf (trace_fp, " \"%s\"", modulename);
    trace_send_line (g);
  }

  if (check_state (g, "modprobe") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "modprobe", "-1");
    return -1;
  }
  guestfs___set_busy (g);

  args.modulename = (char *) modulename;
  serial = guestfs___send (g, GUESTFS_PROC_MODPROBE,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_modprobe_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "modprobe", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "modprobe", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "modprobe", "-1");
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_MODPROBE, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "modprobe", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "modprobe", "-1");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "modprobe", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "modprobe",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  ret_v = 0;
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "modprobe");
    fprintf (trace_fp, "%d", ret_v);
    trace_send_line (g);
  }

  return ret_v;
}

char *
guestfs_echo_daemon (guestfs_h *g,
                     char *const *words)
{
  struct guestfs_echo_daemon_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  struct guestfs_echo_daemon_ret ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  char *ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "echo_daemon", 11);
  if (words == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "echo_daemon", "words");
    return NULL;
  }

  if (trace_flag) {
    size_t i;

    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "echo_daemon");
    fputc (' ', trace_fp);
    fputc ('"', trace_fp);
    for (i = 0; words[i]; ++i) {
      if (i > 0) fputc (' ', trace_fp);
      fputs (words[i], trace_fp);
    }
    fputc ('"', trace_fp);
    trace_send_line (g);
  }

  if (check_state (g, "echo_daemon") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "echo_daemon", "NULL");
    return NULL;
  }
  guestfs___set_busy (g);

  args.words.words_val = (char **) words;
  for (args.words.words_len = 0; words[args.words.words_len]; args.words.words_len++) ;
  serial = guestfs___send (g, GUESTFS_PROC_ECHO_DAEMON,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_echo_daemon_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "echo_daemon", "NULL");
    return NULL;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs___recv (g, "echo_daemon", &hdr, &err,
        (xdrproc_t) xdr_guestfs_echo_daemon_ret, (char *) &ret);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "echo_daemon", "NULL");
    return NULL;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_ECHO_DAEMON, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "echo_daemon", "NULL");
    return NULL;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "echo_daemon", "NULL");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "echo_daemon", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "echo_daemon",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return NULL;
  }

  guestfs___end_busy (g);
  ret_v = ret.output; /* caller will free */
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "echo_daemon");
    fprintf (trace_fp, "\"%s\"", ret_v);
    trace_send_line (g);
  }

  return ret_v;
}

int
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
  FILE *trace_fp;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
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
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "find0");
    fprintf (trace_fp, " \"%s\"", directory);
    fprintf (trace_fp, " \"%s\"", files);
    trace_send_line (g);
  }

  if (check_state (g, "find0") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "find0", "-1");
    return -1;
  }
  guestfs___set_busy (g);

  args.directory = (char *) directory;
  serial = guestfs___send (g, GUESTFS_PROC_FIND0,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_find0_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "find0", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "find0", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "find0", "-1");
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_FIND0, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "find0", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "find0", "-1");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "find0", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "find0",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return -1;
  }

  if (guestfs___recv_file (g, files) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "find0", "-1");
    return -1;
  }

  guestfs___end_busy (g);
  ret_v = 0;
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "find0");
    fprintf (trace_fp, "%d", ret_v);
    trace_send_line (g);
  }

  return ret_v;
}

char *
guestfs_case_sensitive_path (guestfs_h *g,
                             const char *path)
{
  struct guestfs_case_sensitive_path_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  struct guestfs_case_sensitive_path_ret ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  char *ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "case_sensitive_path", 19);
  if (path == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "case_sensitive_path", "path");
    return NULL;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "case_sensitive_path");
    fprintf (trace_fp, " \"%s\"", path);
    trace_send_line (g);
  }

  if (check_state (g, "case_sensitive_path") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "case_sensitive_path", "NULL");
    return NULL;
  }
  guestfs___set_busy (g);

  args.path = (char *) path;
  serial = guestfs___send (g, GUESTFS_PROC_CASE_SENSITIVE_PATH,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_case_sensitive_path_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "case_sensitive_path", "NULL");
    return NULL;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs___recv (g, "case_sensitive_path", &hdr, &err,
        (xdrproc_t) xdr_guestfs_case_sensitive_path_ret, (char *) &ret);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "case_sensitive_path", "NULL");
    return NULL;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_CASE_SENSITIVE_PATH, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "case_sensitive_path", "NULL");
    return NULL;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "case_sensitive_path", "NULL");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "case_sensitive_path", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "case_sensitive_path",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return NULL;
  }

  guestfs___end_busy (g);
  ret_v = ret.rpath; /* caller will free */
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "case_sensitive_path");
    fprintf (trace_fp, "\"%s\"", ret_v);
    trace_send_line (g);
  }

  return ret_v;
}

char *
guestfs_vfs_type (guestfs_h *g,
                  const char *device)
{
  struct guestfs_vfs_type_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  struct guestfs_vfs_type_ret ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  char *ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "vfs_type", 8);
  if (device == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "vfs_type", "device");
    return NULL;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "vfs_type");
    fprintf (trace_fp, " \"%s\"", device);
    trace_send_line (g);
  }

  if (check_state (g, "vfs_type") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "vfs_type", "NULL");
    return NULL;
  }
  guestfs___set_busy (g);

  args.device = (char *) device;
  serial = guestfs___send (g, GUESTFS_PROC_VFS_TYPE,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_vfs_type_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "vfs_type", "NULL");
    return NULL;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs___recv (g, "vfs_type", &hdr, &err,
        (xdrproc_t) xdr_guestfs_vfs_type_ret, (char *) &ret);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "vfs_type", "NULL");
    return NULL;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_VFS_TYPE, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "vfs_type", "NULL");
    return NULL;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "vfs_type", "NULL");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "vfs_type", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "vfs_type",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return NULL;
  }

  guestfs___end_busy (g);
  ret_v = ret.fstype; /* caller will free */
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "vfs_type");
    fprintf (trace_fp, "\"%s\"", ret_v);
    trace_send_line (g);
  }

  return ret_v;
}

int
guestfs_truncate (guestfs_h *g,
                  const char *path)
{
  struct guestfs_truncate_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "truncate", 8);
  if (path == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "truncate", "path");
    return -1;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "truncate");
    fprintf (trace_fp, " \"%s\"", path);
    trace_send_line (g);
  }

  if (check_state (g, "truncate") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "truncate", "-1");
    return -1;
  }
  guestfs___set_busy (g);

  args.path = (char *) path;
  serial = guestfs___send (g, GUESTFS_PROC_TRUNCATE,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_truncate_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "truncate", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "truncate", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "truncate", "-1");
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_TRUNCATE, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "truncate", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "truncate", "-1");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "truncate", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "truncate",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  ret_v = 0;
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "truncate");
    fprintf (trace_fp, "%d", ret_v);
    trace_send_line (g);
  }

  return ret_v;
}

int
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
  FILE *trace_fp;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "truncate_size", 13);
  if (path == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "truncate_size", "path");
    return -1;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "truncate_size");
    fprintf (trace_fp, " \"%s\"", path);
    fprintf (trace_fp, " %" PRIi64, size);
    trace_send_line (g);
  }

  if (check_state (g, "truncate_size") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "truncate_size", "-1");
    return -1;
  }
  guestfs___set_busy (g);

  args.path = (char *) path;
  args.size = size;
  serial = guestfs___send (g, GUESTFS_PROC_TRUNCATE_SIZE,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_truncate_size_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "truncate_size", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "truncate_size", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "truncate_size", "-1");
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_TRUNCATE_SIZE, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "truncate_size", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "truncate_size", "-1");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "truncate_size", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "truncate_size",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  ret_v = 0;
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "truncate_size");
    fprintf (trace_fp, "%d", ret_v);
    trace_send_line (g);
  }

  return ret_v;
}

int
guestfs_utimens (guestfs_h *g,
                 const char *path,
                 int64_t atsecs,
                 int64_t atnsecs,
                 int64_t mtsecs,
                 int64_t mtnsecs)
{
  struct guestfs_utimens_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "utimens", 7);
  if (path == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "utimens", "path");
    return -1;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "utimens");
    fprintf (trace_fp, " \"%s\"", path);
    fprintf (trace_fp, " %" PRIi64, atsecs);
    fprintf (trace_fp, " %" PRIi64, atnsecs);
    fprintf (trace_fp, " %" PRIi64, mtsecs);
    fprintf (trace_fp, " %" PRIi64, mtnsecs);
    trace_send_line (g);
  }

  if (check_state (g, "utimens") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "utimens", "-1");
    return -1;
  }
  guestfs___set_busy (g);

  args.path = (char *) path;
  args.atsecs = atsecs;
  args.atnsecs = atnsecs;
  args.mtsecs = mtsecs;
  args.mtnsecs = mtnsecs;
  serial = guestfs___send (g, GUESTFS_PROC_UTIMENS,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_utimens_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "utimens", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "utimens", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "utimens", "-1");
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_UTIMENS, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "utimens", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "utimens", "-1");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "utimens", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "utimens",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  ret_v = 0;
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "utimens");
    fprintf (trace_fp, "%d", ret_v);
    trace_send_line (g);
  }

  return ret_v;
}

int
guestfs_mkdir_mode (guestfs_h *g,
                    const char *path,
                    int mode)
{
  struct guestfs_mkdir_mode_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "mkdir_mode", 10);
  if (path == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "mkdir_mode", "path");
    return -1;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "mkdir_mode");
    fprintf (trace_fp, " \"%s\"", path);
    fprintf (trace_fp, " %d", mode);
    trace_send_line (g);
  }

  if (check_state (g, "mkdir_mode") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mkdir_mode", "-1");
    return -1;
  }
  guestfs___set_busy (g);

  args.path = (char *) path;
  args.mode = mode;
  serial = guestfs___send (g, GUESTFS_PROC_MKDIR_MODE,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_mkdir_mode_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mkdir_mode", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "mkdir_mode", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mkdir_mode", "-1");
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_MKDIR_MODE, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mkdir_mode", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mkdir_mode", "-1");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "mkdir_mode", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "mkdir_mode",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  ret_v = 0;
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "mkdir_mode");
    fprintf (trace_fp, "%d", ret_v);
    trace_send_line (g);
  }

  return ret_v;
}

int
guestfs_lchown (guestfs_h *g,
                int owner,
                int group,
                const char *path)
{
  struct guestfs_lchown_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "lchown", 6);
  if (path == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "lchown", "path");
    return -1;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "lchown");
    fprintf (trace_fp, " %d", owner);
    fprintf (trace_fp, " %d", group);
    fprintf (trace_fp, " \"%s\"", path);
    trace_send_line (g);
  }

  if (check_state (g, "lchown") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "lchown", "-1");
    return -1;
  }
  guestfs___set_busy (g);

  args.owner = owner;
  args.group = group;
  args.path = (char *) path;
  serial = guestfs___send (g, GUESTFS_PROC_LCHOWN,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_lchown_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "lchown", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "lchown", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "lchown", "-1");
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_LCHOWN, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "lchown", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "lchown", "-1");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "lchown", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "lchown",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  ret_v = 0;
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "lchown");
    fprintf (trace_fp, "%d", ret_v);
    trace_send_line (g);
  }

  return ret_v;
}

struct guestfs_stat_list *
guestfs_lstatlist (guestfs_h *g,
                   const char *path,
                   char *const *names)
{
  struct guestfs_lstatlist_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  struct guestfs_lstatlist_ret ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  struct guestfs_stat_list *ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "lstatlist", 9);
  if (path == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "lstatlist", "path");
    return NULL;
  }
  if (names == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "lstatlist", "names");
    return NULL;
  }

  if (trace_flag) {
    size_t i;

    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "lstatlist");
    fprintf (trace_fp, " \"%s\"", path);
    fputc (' ', trace_fp);
    fputc ('"', trace_fp);
    for (i = 0; names[i]; ++i) {
      if (i > 0) fputc (' ', trace_fp);
      fputs (names[i], trace_fp);
    }
    fputc ('"', trace_fp);
    trace_send_line (g);
  }

  if (check_state (g, "lstatlist") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "lstatlist", "NULL");
    return NULL;
  }
  guestfs___set_busy (g);

  args.path = (char *) path;
  args.names.names_val = (char **) names;
  for (args.names.names_len = 0; names[args.names.names_len]; args.names.names_len++) ;
  serial = guestfs___send (g, GUESTFS_PROC_LSTATLIST,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_lstatlist_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "lstatlist", "NULL");
    return NULL;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs___recv (g, "lstatlist", &hdr, &err,
        (xdrproc_t) xdr_guestfs_lstatlist_ret, (char *) &ret);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "lstatlist", "NULL");
    return NULL;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_LSTATLIST, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "lstatlist", "NULL");
    return NULL;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "lstatlist", "NULL");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "lstatlist", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "lstatlist",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return NULL;
  }

  guestfs___end_busy (g);
  /* caller will free this */
  ret_v = safe_memdup (g, &ret.statbufs, sizeof (ret.statbufs));
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "lstatlist");
    fprintf (trace_fp, "<struct guestfs_stat_list *>");
    trace_send_line (g);
  }

  return ret_v;
}

struct guestfs_xattr_list *
guestfs_lxattrlist (guestfs_h *g,
                    const char *path,
                    char *const *names)
{
  struct guestfs_lxattrlist_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  struct guestfs_lxattrlist_ret ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  struct guestfs_xattr_list *ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "lxattrlist", 10);
  if (path == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "lxattrlist", "path");
    return NULL;
  }
  if (names == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "lxattrlist", "names");
    return NULL;
  }

  if (trace_flag) {
    size_t i;

    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "lxattrlist");
    fprintf (trace_fp, " \"%s\"", path);
    fputc (' ', trace_fp);
    fputc ('"', trace_fp);
    for (i = 0; names[i]; ++i) {
      if (i > 0) fputc (' ', trace_fp);
      fputs (names[i], trace_fp);
    }
    fputc ('"', trace_fp);
    trace_send_line (g);
  }

  if (check_state (g, "lxattrlist") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "lxattrlist", "NULL");
    return NULL;
  }
  guestfs___set_busy (g);

  args.path = (char *) path;
  args.names.names_val = (char **) names;
  for (args.names.names_len = 0; names[args.names.names_len]; args.names.names_len++) ;
  serial = guestfs___send (g, GUESTFS_PROC_LXATTRLIST,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_lxattrlist_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "lxattrlist", "NULL");
    return NULL;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs___recv (g, "lxattrlist", &hdr, &err,
        (xdrproc_t) xdr_guestfs_lxattrlist_ret, (char *) &ret);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "lxattrlist", "NULL");
    return NULL;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_LXATTRLIST, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "lxattrlist", "NULL");
    return NULL;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "lxattrlist", "NULL");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "lxattrlist", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "lxattrlist",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return NULL;
  }

  guestfs___end_busy (g);
  /* caller will free this */
  ret_v = safe_memdup (g, &ret.xattrs, sizeof (ret.xattrs));
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "lxattrlist");
    fprintf (trace_fp, "<struct guestfs_xattr_list *>");
    trace_send_line (g);
  }

  return ret_v;
}

char **
guestfs_readlinklist (guestfs_h *g,
                      const char *path,
                      char *const *names)
{
  struct guestfs_readlinklist_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  struct guestfs_readlinklist_ret ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  char **ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "readlinklist", 12);
  if (path == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "readlinklist", "path");
    return NULL;
  }
  if (names == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "readlinklist", "names");
    return NULL;
  }

  if (trace_flag) {
    size_t i;

    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "readlinklist");
    fprintf (trace_fp, " \"%s\"", path);
    fputc (' ', trace_fp);
    fputc ('"', trace_fp);
    for (i = 0; names[i]; ++i) {
      if (i > 0) fputc (' ', trace_fp);
      fputs (names[i], trace_fp);
    }
    fputc ('"', trace_fp);
    trace_send_line (g);
  }

  if (check_state (g, "readlinklist") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "readlinklist", "NULL");
    return NULL;
  }
  guestfs___set_busy (g);

  args.path = (char *) path;
  args.names.names_val = (char **) names;
  for (args.names.names_len = 0; names[args.names.names_len]; args.names.names_len++) ;
  serial = guestfs___send (g, GUESTFS_PROC_READLINKLIST,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_readlinklist_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "readlinklist", "NULL");
    return NULL;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs___recv (g, "readlinklist", &hdr, &err,
        (xdrproc_t) xdr_guestfs_readlinklist_ret, (char *) &ret);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "readlinklist", "NULL");
    return NULL;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_READLINKLIST, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "readlinklist", "NULL");
    return NULL;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "readlinklist", "NULL");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "readlinklist", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "readlinklist",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return NULL;
  }

  guestfs___end_busy (g);
  /* caller will free this, but we need to add a NULL entry */
  ret.links.links_val =
    safe_realloc (g, ret.links.links_val,
                  sizeof (char *) * (ret.links.links_len + 1));
  ret.links.links_val[ret.links.links_len] = NULL;
  ret_v = ret.links.links_val;
  if (trace_flag) {
    size_t i;

    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "readlinklist");
    fputs ("[", trace_fp);
    for (i = 0; ret_v[i]; ++i) {
      if (i > 0) fputs (", ", trace_fp);
      fputs ("\"", trace_fp);
      fputs (ret_v[i], trace_fp);
      fputs ("\"", trace_fp);
    }
    fputs ("]", trace_fp);
    trace_send_line (g);
  }

  return ret_v;
}

char *
guestfs_pread (guestfs_h *g,
               const char *path,
               int count,
               int64_t offset,
               size_t *size_r)
{
  struct guestfs_pread_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  struct guestfs_pread_ret ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  char *ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "pread", 5);
  if (path == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "pread", "path");
    return NULL;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "pread");
    fprintf (trace_fp, " \"%s\"", path);
    fprintf (trace_fp, " %d", count);
    fprintf (trace_fp, " %" PRIi64, offset);
    trace_send_line (g);
  }

  if (check_state (g, "pread") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "pread", "NULL");
    return NULL;
  }
  guestfs___set_busy (g);

  args.path = (char *) path;
  args.count = count;
  args.offset = offset;
  serial = guestfs___send (g, GUESTFS_PROC_PREAD,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_pread_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "pread", "NULL");
    return NULL;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs___recv (g, "pread", &hdr, &err,
        (xdrproc_t) xdr_guestfs_pread_ret, (char *) &ret);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "pread", "NULL");
    return NULL;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_PREAD, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "pread", "NULL");
    return NULL;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "pread", "NULL");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "pread", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "pread",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return NULL;
  }

  guestfs___end_busy (g);
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
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "pread");
    guestfs___print_BufferOut (trace_fp, ret_v, *size_r);
    trace_send_line (g);
  }

  return ret_v;
}

int
guestfs_part_init (guestfs_h *g,
                   const char *device,
                   const char *parttype)
{
  struct guestfs_part_init_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "part_init", 9);
  if (device == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "part_init", "device");
    return -1;
  }
  if (parttype == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "part_init", "parttype");
    return -1;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "part_init");
    fprintf (trace_fp, " \"%s\"", device);
    fprintf (trace_fp, " \"%s\"", parttype);
    trace_send_line (g);
  }

  if (check_state (g, "part_init") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "part_init", "-1");
    return -1;
  }
  guestfs___set_busy (g);

  args.device = (char *) device;
  args.parttype = (char *) parttype;
  serial = guestfs___send (g, GUESTFS_PROC_PART_INIT,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_part_init_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "part_init", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "part_init", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "part_init", "-1");
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_PART_INIT, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "part_init", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "part_init", "-1");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "part_init", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "part_init",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  ret_v = 0;
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "part_init");
    fprintf (trace_fp, "%d", ret_v);
    trace_send_line (g);
  }

  return ret_v;
}

int
guestfs_part_add (guestfs_h *g,
                  const char *device,
                  const char *prlogex,
                  int64_t startsect,
                  int64_t endsect)
{
  struct guestfs_part_add_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "part_add", 8);
  if (device == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "part_add", "device");
    return -1;
  }
  if (prlogex == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "part_add", "prlogex");
    return -1;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "part_add");
    fprintf (trace_fp, " \"%s\"", device);
    fprintf (trace_fp, " \"%s\"", prlogex);
    fprintf (trace_fp, " %" PRIi64, startsect);
    fprintf (trace_fp, " %" PRIi64, endsect);
    trace_send_line (g);
  }

  if (check_state (g, "part_add") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "part_add", "-1");
    return -1;
  }
  guestfs___set_busy (g);

  args.device = (char *) device;
  args.prlogex = (char *) prlogex;
  args.startsect = startsect;
  args.endsect = endsect;
  serial = guestfs___send (g, GUESTFS_PROC_PART_ADD,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_part_add_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "part_add", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "part_add", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "part_add", "-1");
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_PART_ADD, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "part_add", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "part_add", "-1");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "part_add", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "part_add",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  ret_v = 0;
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "part_add");
    fprintf (trace_fp, "%d", ret_v);
    trace_send_line (g);
  }

  return ret_v;
}

int
guestfs_part_disk (guestfs_h *g,
                   const char *device,
                   const char *parttype)
{
  struct guestfs_part_disk_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "part_disk", 9);
  if (device == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "part_disk", "device");
    return -1;
  }
  if (parttype == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "part_disk", "parttype");
    return -1;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "part_disk");
    fprintf (trace_fp, " \"%s\"", device);
    fprintf (trace_fp, " \"%s\"", parttype);
    trace_send_line (g);
  }

  if (check_state (g, "part_disk") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "part_disk", "-1");
    return -1;
  }
  guestfs___set_busy (g);

  args.device = (char *) device;
  args.parttype = (char *) parttype;
  serial = guestfs___send (g, GUESTFS_PROC_PART_DISK,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_part_disk_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "part_disk", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "part_disk", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "part_disk", "-1");
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_PART_DISK, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "part_disk", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "part_disk", "-1");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "part_disk", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "part_disk",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  ret_v = 0;
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "part_disk");
    fprintf (trace_fp, "%d", ret_v);
    trace_send_line (g);
  }

  return ret_v;
}

int
guestfs_part_set_bootable (guestfs_h *g,
                           const char *device,
                           int partnum,
                           int bootable)
{
  struct guestfs_part_set_bootable_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "part_set_bootable", 17);
  if (device == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "part_set_bootable", "device");
    return -1;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "part_set_bootable");
    fprintf (trace_fp, " \"%s\"", device);
    fprintf (trace_fp, " %d", partnum);
    fputs (bootable ? " true" : " false", trace_fp);
    trace_send_line (g);
  }

  if (check_state (g, "part_set_bootable") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "part_set_bootable", "-1");
    return -1;
  }
  guestfs___set_busy (g);

  args.device = (char *) device;
  args.partnum = partnum;
  args.bootable = bootable;
  serial = guestfs___send (g, GUESTFS_PROC_PART_SET_BOOTABLE,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_part_set_bootable_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "part_set_bootable", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "part_set_bootable", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "part_set_bootable", "-1");
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_PART_SET_BOOTABLE, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "part_set_bootable", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "part_set_bootable", "-1");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "part_set_bootable", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "part_set_bootable",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  ret_v = 0;
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "part_set_bootable");
    fprintf (trace_fp, "%d", ret_v);
    trace_send_line (g);
  }

  return ret_v;
}

int
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
  FILE *trace_fp;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
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
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "part_set_name");
    fprintf (trace_fp, " \"%s\"", device);
    fprintf (trace_fp, " %d", partnum);
    fprintf (trace_fp, " \"%s\"", name);
    trace_send_line (g);
  }

  if (check_state (g, "part_set_name") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "part_set_name", "-1");
    return -1;
  }
  guestfs___set_busy (g);

  args.device = (char *) device;
  args.partnum = partnum;
  args.name = (char *) name;
  serial = guestfs___send (g, GUESTFS_PROC_PART_SET_NAME,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_part_set_name_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "part_set_name", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "part_set_name", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "part_set_name", "-1");
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_PART_SET_NAME, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "part_set_name", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "part_set_name", "-1");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "part_set_name", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "part_set_name",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  ret_v = 0;
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "part_set_name");
    fprintf (trace_fp, "%d", ret_v);
    trace_send_line (g);
  }

  return ret_v;
}

struct guestfs_partition_list *
guestfs_part_list (guestfs_h *g,
                   const char *device)
{
  struct guestfs_part_list_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  struct guestfs_part_list_ret ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  struct guestfs_partition_list *ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "part_list", 9);
  if (device == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "part_list", "device");
    return NULL;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "part_list");
    fprintf (trace_fp, " \"%s\"", device);
    trace_send_line (g);
  }

  if (check_state (g, "part_list") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "part_list", "NULL");
    return NULL;
  }
  guestfs___set_busy (g);

  args.device = (char *) device;
  serial = guestfs___send (g, GUESTFS_PROC_PART_LIST,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_part_list_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "part_list", "NULL");
    return NULL;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs___recv (g, "part_list", &hdr, &err,
        (xdrproc_t) xdr_guestfs_part_list_ret, (char *) &ret);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "part_list", "NULL");
    return NULL;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_PART_LIST, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "part_list", "NULL");
    return NULL;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "part_list", "NULL");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "part_list", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "part_list",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return NULL;
  }

  guestfs___end_busy (g);
  /* caller will free this */
  ret_v = safe_memdup (g, &ret.partitions, sizeof (ret.partitions));
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "part_list");
    fprintf (trace_fp, "<struct guestfs_partition_list *>");
    trace_send_line (g);
  }

  return ret_v;
}

char *
guestfs_part_get_parttype (guestfs_h *g,
                           const char *device)
{
  struct guestfs_part_get_parttype_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  struct guestfs_part_get_parttype_ret ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  char *ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "part_get_parttype", 17);
  if (device == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "part_get_parttype", "device");
    return NULL;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "part_get_parttype");
    fprintf (trace_fp, " \"%s\"", device);
    trace_send_line (g);
  }

  if (check_state (g, "part_get_parttype") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "part_get_parttype", "NULL");
    return NULL;
  }
  guestfs___set_busy (g);

  args.device = (char *) device;
  serial = guestfs___send (g, GUESTFS_PROC_PART_GET_PARTTYPE,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_part_get_parttype_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "part_get_parttype", "NULL");
    return NULL;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs___recv (g, "part_get_parttype", &hdr, &err,
        (xdrproc_t) xdr_guestfs_part_get_parttype_ret, (char *) &ret);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "part_get_parttype", "NULL");
    return NULL;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_PART_GET_PARTTYPE, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "part_get_parttype", "NULL");
    return NULL;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "part_get_parttype", "NULL");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "part_get_parttype", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "part_get_parttype",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return NULL;
  }

  guestfs___end_busy (g);
  ret_v = ret.parttype; /* caller will free */
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "part_get_parttype");
    fprintf (trace_fp, "\"%s\"", ret_v);
    trace_send_line (g);
  }

  return ret_v;
}

int
guestfs_fill (guestfs_h *g,
              int c,
              int len,
              const char *path)
{
  struct guestfs_fill_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "fill", 4);
  if (path == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "fill", "path");
    return -1;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "fill");
    fprintf (trace_fp, " %d", c);
    fprintf (trace_fp, " %d", len);
    fprintf (trace_fp, " \"%s\"", path);
    trace_send_line (g);
  }

  if (check_state (g, "fill") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "fill", "-1");
    return -1;
  }
  guestfs___set_busy (g);

  args.c = c;
  args.len = len;
  args.path = (char *) path;
  serial = guestfs___send (g, GUESTFS_PROC_FILL,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_fill_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "fill", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "fill", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "fill", "-1");
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_FILL, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "fill", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "fill", "-1");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "fill", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "fill",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  ret_v = 0;
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "fill");
    fprintf (trace_fp, "%d", ret_v);
    trace_send_line (g);
  }

  return ret_v;
}

int
guestfs_available (guestfs_h *g,
                   char *const *groups)
{
  struct guestfs_available_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "available", 9);
  if (groups == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "available", "groups");
    return -1;
  }

  if (trace_flag) {
    size_t i;

    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "available");
    fputc (' ', trace_fp);
    fputc ('"', trace_fp);
    for (i = 0; groups[i]; ++i) {
      if (i > 0) fputc (' ', trace_fp);
      fputs (groups[i], trace_fp);
    }
    fputc ('"', trace_fp);
    trace_send_line (g);
  }

  if (check_state (g, "available") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "available", "-1");
    return -1;
  }
  guestfs___set_busy (g);

  args.groups.groups_val = (char **) groups;
  for (args.groups.groups_len = 0; groups[args.groups.groups_len]; args.groups.groups_len++) ;
  serial = guestfs___send (g, GUESTFS_PROC_AVAILABLE,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_available_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "available", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "available", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "available", "-1");
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_AVAILABLE, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "available", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "available", "-1");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "available", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "available",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  ret_v = 0;
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "available");
    fprintf (trace_fp, "%d", ret_v);
    trace_send_line (g);
  }

  return ret_v;
}

int
guestfs_dd (guestfs_h *g,
            const char *src,
            const char *dest)
{
  struct guestfs_dd_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "dd", 2);
  if (src == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "dd", "src");
    return -1;
  }
  if (dest == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "dd", "dest");
    return -1;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "dd");
    fprintf (trace_fp, " \"%s\"", src);
    fprintf (trace_fp, " \"%s\"", dest);
    trace_send_line (g);
  }

  if (check_state (g, "dd") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "dd", "-1");
    return -1;
  }
  guestfs___set_busy (g);

  args.src = (char *) src;
  args.dest = (char *) dest;
  serial = guestfs___send (g, GUESTFS_PROC_DD,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_dd_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "dd", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "dd", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "dd", "-1");
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_DD, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "dd", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "dd", "-1");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "dd", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "dd",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  ret_v = 0;
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "dd");
    fprintf (trace_fp, "%d", ret_v);
    trace_send_line (g);
  }

  return ret_v;
}

int64_t
guestfs_filesize (guestfs_h *g,
                  const char *file)
{
  struct guestfs_filesize_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  struct guestfs_filesize_ret ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  int64_t ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "filesize", 8);
  if (file == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "filesize", "file");
    return -1;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "filesize");
    fprintf (trace_fp, " \"%s\"", file);
    trace_send_line (g);
  }

  if (check_state (g, "filesize") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "filesize", "-1");
    return -1;
  }
  guestfs___set_busy (g);

  args.file = (char *) file;
  serial = guestfs___send (g, GUESTFS_PROC_FILESIZE,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_filesize_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "filesize", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs___recv (g, "filesize", &hdr, &err,
        (xdrproc_t) xdr_guestfs_filesize_ret, (char *) &ret);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "filesize", "-1");
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_FILESIZE, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "filesize", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "filesize", "-1");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "filesize", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "filesize",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  ret_v = ret.size;
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "filesize");
    fprintf (trace_fp, "%" PRIi64, ret_v);
    trace_send_line (g);
  }

  return ret_v;
}

int
guestfs_lvrename (guestfs_h *g,
                  const char *logvol,
                  const char *newlogvol)
{
  struct guestfs_lvrename_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "lvrename", 8);
  if (logvol == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "lvrename", "logvol");
    return -1;
  }
  if (newlogvol == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "lvrename", "newlogvol");
    return -1;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "lvrename");
    fprintf (trace_fp, " \"%s\"", logvol);
    fprintf (trace_fp, " \"%s\"", newlogvol);
    trace_send_line (g);
  }

  if (check_state (g, "lvrename") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "lvrename", "-1");
    return -1;
  }
  guestfs___set_busy (g);

  args.logvol = (char *) logvol;
  args.newlogvol = (char *) newlogvol;
  serial = guestfs___send (g, GUESTFS_PROC_LVRENAME,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_lvrename_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "lvrename", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "lvrename", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "lvrename", "-1");
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_LVRENAME, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "lvrename", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "lvrename", "-1");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "lvrename", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "lvrename",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  ret_v = 0;
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "lvrename");
    fprintf (trace_fp, "%d", ret_v);
    trace_send_line (g);
  }

  return ret_v;
}

int
guestfs_vgrename (guestfs_h *g,
                  const char *volgroup,
                  const char *newvolgroup)
{
  struct guestfs_vgrename_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "vgrename", 8);
  if (volgroup == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "vgrename", "volgroup");
    return -1;
  }
  if (newvolgroup == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "vgrename", "newvolgroup");
    return -1;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "vgrename");
    fprintf (trace_fp, " \"%s\"", volgroup);
    fprintf (trace_fp, " \"%s\"", newvolgroup);
    trace_send_line (g);
  }

  if (check_state (g, "vgrename") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "vgrename", "-1");
    return -1;
  }
  guestfs___set_busy (g);

  args.volgroup = (char *) volgroup;
  args.newvolgroup = (char *) newvolgroup;
  serial = guestfs___send (g, GUESTFS_PROC_VGRENAME,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_vgrename_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "vgrename", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "vgrename", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "vgrename", "-1");
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_VGRENAME, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "vgrename", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "vgrename", "-1");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "vgrename", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "vgrename",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  ret_v = 0;
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "vgrename");
    fprintf (trace_fp, "%d", ret_v);
    trace_send_line (g);
  }

  return ret_v;
}

char *
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
  FILE *trace_fp;
  char *ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
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
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "initrd_cat");
    fprintf (trace_fp, " \"%s\"", initrdpath);
    fprintf (trace_fp, " \"%s\"", filename);
    trace_send_line (g);
  }

  if (check_state (g, "initrd_cat") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "initrd_cat", "NULL");
    return NULL;
  }
  guestfs___set_busy (g);

  args.initrdpath = (char *) initrdpath;
  args.filename = (char *) filename;
  serial = guestfs___send (g, GUESTFS_PROC_INITRD_CAT,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_initrd_cat_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "initrd_cat", "NULL");
    return NULL;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs___recv (g, "initrd_cat", &hdr, &err,
        (xdrproc_t) xdr_guestfs_initrd_cat_ret, (char *) &ret);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "initrd_cat", "NULL");
    return NULL;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_INITRD_CAT, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "initrd_cat", "NULL");
    return NULL;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "initrd_cat", "NULL");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "initrd_cat", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "initrd_cat",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return NULL;
  }

  guestfs___end_busy (g);
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
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "initrd_cat");
    guestfs___print_BufferOut (trace_fp, ret_v, *size_r);
    trace_send_line (g);
  }

  return ret_v;
}

char *
guestfs_pvuuid (guestfs_h *g,
                const char *device)
{
  struct guestfs_pvuuid_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  struct guestfs_pvuuid_ret ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  char *ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "pvuuid", 6);
  if (device == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "pvuuid", "device");
    return NULL;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "pvuuid");
    fprintf (trace_fp, " \"%s\"", device);
    trace_send_line (g);
  }

  if (check_state (g, "pvuuid") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "pvuuid", "NULL");
    return NULL;
  }
  guestfs___set_busy (g);

  args.device = (char *) device;
  serial = guestfs___send (g, GUESTFS_PROC_PVUUID,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_pvuuid_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "pvuuid", "NULL");
    return NULL;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs___recv (g, "pvuuid", &hdr, &err,
        (xdrproc_t) xdr_guestfs_pvuuid_ret, (char *) &ret);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "pvuuid", "NULL");
    return NULL;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_PVUUID, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "pvuuid", "NULL");
    return NULL;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "pvuuid", "NULL");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "pvuuid", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "pvuuid",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return NULL;
  }

  guestfs___end_busy (g);
  ret_v = ret.uuid; /* caller will free */
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "pvuuid");
    fprintf (trace_fp, "\"%s\"", ret_v);
    trace_send_line (g);
  }

  return ret_v;
}

char *
guestfs_vguuid (guestfs_h *g,
                const char *vgname)
{
  struct guestfs_vguuid_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  struct guestfs_vguuid_ret ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  char *ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "vguuid", 6);
  if (vgname == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "vguuid", "vgname");
    return NULL;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "vguuid");
    fprintf (trace_fp, " \"%s\"", vgname);
    trace_send_line (g);
  }

  if (check_state (g, "vguuid") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "vguuid", "NULL");
    return NULL;
  }
  guestfs___set_busy (g);

  args.vgname = (char *) vgname;
  serial = guestfs___send (g, GUESTFS_PROC_VGUUID,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_vguuid_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "vguuid", "NULL");
    return NULL;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs___recv (g, "vguuid", &hdr, &err,
        (xdrproc_t) xdr_guestfs_vguuid_ret, (char *) &ret);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "vguuid", "NULL");
    return NULL;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_VGUUID, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "vguuid", "NULL");
    return NULL;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "vguuid", "NULL");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "vguuid", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "vguuid",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return NULL;
  }

  guestfs___end_busy (g);
  ret_v = ret.uuid; /* caller will free */
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "vguuid");
    fprintf (trace_fp, "\"%s\"", ret_v);
    trace_send_line (g);
  }

  return ret_v;
}

char *
guestfs_lvuuid (guestfs_h *g,
                const char *device)
{
  struct guestfs_lvuuid_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  struct guestfs_lvuuid_ret ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  char *ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "lvuuid", 6);
  if (device == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "lvuuid", "device");
    return NULL;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "lvuuid");
    fprintf (trace_fp, " \"%s\"", device);
    trace_send_line (g);
  }

  if (check_state (g, "lvuuid") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "lvuuid", "NULL");
    return NULL;
  }
  guestfs___set_busy (g);

  args.device = (char *) device;
  serial = guestfs___send (g, GUESTFS_PROC_LVUUID,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_lvuuid_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "lvuuid", "NULL");
    return NULL;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs___recv (g, "lvuuid", &hdr, &err,
        (xdrproc_t) xdr_guestfs_lvuuid_ret, (char *) &ret);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "lvuuid", "NULL");
    return NULL;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_LVUUID, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "lvuuid", "NULL");
    return NULL;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "lvuuid", "NULL");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "lvuuid", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "lvuuid",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return NULL;
  }

  guestfs___end_busy (g);
  ret_v = ret.uuid; /* caller will free */
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "lvuuid");
    fprintf (trace_fp, "\"%s\"", ret_v);
    trace_send_line (g);
  }

  return ret_v;
}

char **
guestfs_vgpvuuids (guestfs_h *g,
                   const char *vgname)
{
  struct guestfs_vgpvuuids_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  struct guestfs_vgpvuuids_ret ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  char **ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "vgpvuuids", 9);
  if (vgname == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "vgpvuuids", "vgname");
    return NULL;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "vgpvuuids");
    fprintf (trace_fp, " \"%s\"", vgname);
    trace_send_line (g);
  }

  if (check_state (g, "vgpvuuids") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "vgpvuuids", "NULL");
    return NULL;
  }
  guestfs___set_busy (g);

  args.vgname = (char *) vgname;
  serial = guestfs___send (g, GUESTFS_PROC_VGPVUUIDS,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_vgpvuuids_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "vgpvuuids", "NULL");
    return NULL;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs___recv (g, "vgpvuuids", &hdr, &err,
        (xdrproc_t) xdr_guestfs_vgpvuuids_ret, (char *) &ret);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "vgpvuuids", "NULL");
    return NULL;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_VGPVUUIDS, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "vgpvuuids", "NULL");
    return NULL;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "vgpvuuids", "NULL");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "vgpvuuids", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "vgpvuuids",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return NULL;
  }

  guestfs___end_busy (g);
  /* caller will free this, but we need to add a NULL entry */
  ret.uuids.uuids_val =
    safe_realloc (g, ret.uuids.uuids_val,
                  sizeof (char *) * (ret.uuids.uuids_len + 1));
  ret.uuids.uuids_val[ret.uuids.uuids_len] = NULL;
  ret_v = ret.uuids.uuids_val;
  if (trace_flag) {
    size_t i;

    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "vgpvuuids");
    fputs ("[", trace_fp);
    for (i = 0; ret_v[i]; ++i) {
      if (i > 0) fputs (", ", trace_fp);
      fputs ("\"", trace_fp);
      fputs (ret_v[i], trace_fp);
      fputs ("\"", trace_fp);
    }
    fputs ("]", trace_fp);
    trace_send_line (g);
  }

  return ret_v;
}

char **
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
  FILE *trace_fp;
  char **ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "vglvuuids", 9);
  if (vgname == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "vglvuuids", "vgname");
    return NULL;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "vglvuuids");
    fprintf (trace_fp, " \"%s\"", vgname);
    trace_send_line (g);
  }

  if (check_state (g, "vglvuuids") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "vglvuuids", "NULL");
    return NULL;
  }
  guestfs___set_busy (g);

  args.vgname = (char *) vgname;
  serial = guestfs___send (g, GUESTFS_PROC_VGLVUUIDS,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_vglvuuids_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "vglvuuids", "NULL");
    return NULL;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs___recv (g, "vglvuuids", &hdr, &err,
        (xdrproc_t) xdr_guestfs_vglvuuids_ret, (char *) &ret);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "vglvuuids", "NULL");
    return NULL;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_VGLVUUIDS, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "vglvuuids", "NULL");
    return NULL;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "vglvuuids", "NULL");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "vglvuuids", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "vglvuuids",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return NULL;
  }

  guestfs___end_busy (g);
  /* caller will free this, but we need to add a NULL entry */
  ret.uuids.uuids_val =
    safe_realloc (g, ret.uuids.uuids_val,
                  sizeof (char *) * (ret.uuids.uuids_len + 1));
  ret.uuids.uuids_val[ret.uuids.uuids_len] = NULL;
  ret_v = ret.uuids.uuids_val;
  if (trace_flag) {
    size_t i;

    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "vglvuuids");
    fputs ("[", trace_fp);
    for (i = 0; ret_v[i]; ++i) {
      if (i > 0) fputs (", ", trace_fp);
      fputs ("\"", trace_fp);
      fputs (ret_v[i], trace_fp);
      fputs ("\"", trace_fp);
    }
    fputs ("]", trace_fp);
    trace_send_line (g);
  }

  return ret_v;
}

int
guestfs_copy_size (guestfs_h *g,
                   const char *src,
                   const char *dest,
                   int64_t size)
{
  struct guestfs_copy_size_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "copy_size", 9);
  if (src == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "copy_size", "src");
    return -1;
  }
  if (dest == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "copy_size", "dest");
    return -1;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "copy_size");
    fprintf (trace_fp, " \"%s\"", src);
    fprintf (trace_fp, " \"%s\"", dest);
    fprintf (trace_fp, " %" PRIi64, size);
    trace_send_line (g);
  }

  if (check_state (g, "copy_size") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "copy_size", "-1");
    return -1;
  }
  guestfs___set_busy (g);

  args.src = (char *) src;
  args.dest = (char *) dest;
  args.size = size;
  serial = guestfs___send (g, GUESTFS_PROC_COPY_SIZE,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_copy_size_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "copy_size", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "copy_size", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "copy_size", "-1");
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_COPY_SIZE, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "copy_size", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "copy_size", "-1");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "copy_size", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "copy_size",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  ret_v = 0;
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "copy_size");
    fprintf (trace_fp, "%d", ret_v);
    trace_send_line (g);
  }

  return ret_v;
}

int
guestfs_zero_device (guestfs_h *g,
                     const char *device)
{
  struct guestfs_zero_device_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "zero_device", 11);
  if (device == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "zero_device", "device");
    return -1;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "zero_device");
    fprintf (trace_fp, " \"%s\"", device);
    trace_send_line (g);
  }

  if (check_state (g, "zero_device") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "zero_device", "-1");
    return -1;
  }
  guestfs___set_busy (g);

  args.device = (char *) device;
  serial = guestfs___send (g, GUESTFS_PROC_ZERO_DEVICE,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_zero_device_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "zero_device", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "zero_device", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "zero_device", "-1");
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_ZERO_DEVICE, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "zero_device", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "zero_device", "-1");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "zero_device", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "zero_device",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  ret_v = 0;
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "zero_device");
    fprintf (trace_fp, "%d", ret_v);
    trace_send_line (g);
  }

  return ret_v;
}

int
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
  FILE *trace_fp;
  int ret_v;
  uint64_t progress_hint = 0;
  struct stat progress_stat;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
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
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "txz_in");
    fprintf (trace_fp, " \"%s\"", tarball);
    fprintf (trace_fp, " \"%s\"", directory);
    trace_send_line (g);
  }

  if (stat (tarball, &progress_stat) == 0 &&
      S_ISREG (progress_stat.st_mode))
    progress_hint += progress_stat.st_size;

  if (check_state (g, "txz_in") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "txz_in", "-1");
    return -1;
  }
  guestfs___set_busy (g);

  args.directory = (char *) directory;
  serial = guestfs___send (g, GUESTFS_PROC_TXZ_IN,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_txz_in_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "txz_in", "-1");
    return -1;
  }

  r = guestfs___send_file (g, tarball);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "txz_in", "-1");
    /* daemon will send an error reply which we discard */
    guestfs___recv_discard (g, "txz_in");
    return -1;
  }
  if (r == -2) /* daemon cancelled */
    goto read_reply;

 read_reply:
  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "txz_in", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "txz_in", "-1");
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_TXZ_IN, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "txz_in", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "txz_in", "-1");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "txz_in", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "txz_in",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  ret_v = 0;
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "txz_in");
    fprintf (trace_fp, "%d", ret_v);
    trace_send_line (g);
  }

  return ret_v;
}

int
guestfs_txz_out (guestfs_h *g,
                 const char *directory,
                 const char *tarball)
{
  struct guestfs_txz_out_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "txz_out", 7);
  if (directory == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "txz_out", "directory");
    return -1;
  }
  if (tarball == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "txz_out", "tarball");
    return -1;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "txz_out");
    fprintf (trace_fp, " \"%s\"", directory);
    fprintf (trace_fp, " \"%s\"", tarball);
    trace_send_line (g);
  }

  if (check_state (g, "txz_out") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "txz_out", "-1");
    return -1;
  }
  guestfs___set_busy (g);

  args.directory = (char *) directory;
  serial = guestfs___send (g, GUESTFS_PROC_TXZ_OUT,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_txz_out_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "txz_out", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "txz_out", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "txz_out", "-1");
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_TXZ_OUT, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "txz_out", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "txz_out", "-1");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "txz_out", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "txz_out",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return -1;
  }

  if (guestfs___recv_file (g, tarball) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "txz_out", "-1");
    return -1;
  }

  guestfs___end_busy (g);
  ret_v = 0;
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "txz_out");
    fprintf (trace_fp, "%d", ret_v);
    trace_send_line (g);
  }

  return ret_v;
}

int
guestfs_ntfsresize (guestfs_h *g,
                    const char *device)
{
  struct guestfs_ntfsresize_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "ntfsresize", 10);
  if (device == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "ntfsresize", "device");
    return -1;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "ntfsresize");
    fprintf (trace_fp, " \"%s\"", device);
    trace_send_line (g);
  }

  if (check_state (g, "ntfsresize") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "ntfsresize", "-1");
    return -1;
  }
  guestfs___set_busy (g);

  args.device = (char *) device;
  serial = guestfs___send (g, GUESTFS_PROC_NTFSRESIZE,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_ntfsresize_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "ntfsresize", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "ntfsresize", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "ntfsresize", "-1");
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_NTFSRESIZE, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "ntfsresize", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "ntfsresize", "-1");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "ntfsresize", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "ntfsresize",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  ret_v = 0;
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "ntfsresize");
    fprintf (trace_fp, "%d", ret_v);
    trace_send_line (g);
  }

  return ret_v;
}

int
guestfs_vgscan (guestfs_h *g)
{
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "vgscan", 6);
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "vgscan");
    trace_send_line (g);
  }

  if (check_state (g, "vgscan") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "vgscan", "-1");
    return -1;
  }
  guestfs___set_busy (g);

  serial = guestfs___send (g, GUESTFS_PROC_VGSCAN, progress_hint, 0,
                           NULL, NULL);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "vgscan", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "vgscan", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "vgscan", "-1");
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_VGSCAN, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "vgscan", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "vgscan", "-1");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "vgscan", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "vgscan",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  ret_v = 0;
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "vgscan");
    fprintf (trace_fp, "%d", ret_v);
    trace_send_line (g);
  }

  return ret_v;
}

int
guestfs_part_del (guestfs_h *g,
                  const char *device,
                  int partnum)
{
  struct guestfs_part_del_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "part_del", 8);
  if (device == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "part_del", "device");
    return -1;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "part_del");
    fprintf (trace_fp, " \"%s\"", device);
    fprintf (trace_fp, " %d", partnum);
    trace_send_line (g);
  }

  if (check_state (g, "part_del") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "part_del", "-1");
    return -1;
  }
  guestfs___set_busy (g);

  args.device = (char *) device;
  args.partnum = partnum;
  serial = guestfs___send (g, GUESTFS_PROC_PART_DEL,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_part_del_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "part_del", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "part_del", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "part_del", "-1");
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_PART_DEL, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "part_del", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "part_del", "-1");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "part_del", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "part_del",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  ret_v = 0;
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "part_del");
    fprintf (trace_fp, "%d", ret_v);
    trace_send_line (g);
  }

  return ret_v;
}

int
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
  FILE *trace_fp;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "part_get_bootable", 17);
  if (device == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "part_get_bootable", "device");
    return -1;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "part_get_bootable");
    fprintf (trace_fp, " \"%s\"", device);
    fprintf (trace_fp, " %d", partnum);
    trace_send_line (g);
  }

  if (check_state (g, "part_get_bootable") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "part_get_bootable", "-1");
    return -1;
  }
  guestfs___set_busy (g);

  args.device = (char *) device;
  args.partnum = partnum;
  serial = guestfs___send (g, GUESTFS_PROC_PART_GET_BOOTABLE,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_part_get_bootable_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "part_get_bootable", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs___recv (g, "part_get_bootable", &hdr, &err,
        (xdrproc_t) xdr_guestfs_part_get_bootable_ret, (char *) &ret);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "part_get_bootable", "-1");
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_PART_GET_BOOTABLE, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "part_get_bootable", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "part_get_bootable", "-1");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "part_get_bootable", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "part_get_bootable",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  ret_v = ret.bootable;
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "part_get_bootable");
    fprintf (trace_fp, "%d", ret_v);
    trace_send_line (g);
  }

  return ret_v;
}

int
guestfs_part_get_mbr_id (guestfs_h *g,
                         const char *device,
                         int partnum)
{
  struct guestfs_part_get_mbr_id_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  struct guestfs_part_get_mbr_id_ret ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "part_get_mbr_id", 15);
  if (device == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "part_get_mbr_id", "device");
    return -1;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "part_get_mbr_id");
    fprintf (trace_fp, " \"%s\"", device);
    fprintf (trace_fp, " %d", partnum);
    trace_send_line (g);
  }

  if (check_state (g, "part_get_mbr_id") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "part_get_mbr_id", "-1");
    return -1;
  }
  guestfs___set_busy (g);

  args.device = (char *) device;
  args.partnum = partnum;
  serial = guestfs___send (g, GUESTFS_PROC_PART_GET_MBR_ID,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_part_get_mbr_id_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "part_get_mbr_id", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs___recv (g, "part_get_mbr_id", &hdr, &err,
        (xdrproc_t) xdr_guestfs_part_get_mbr_id_ret, (char *) &ret);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "part_get_mbr_id", "-1");
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_PART_GET_MBR_ID, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "part_get_mbr_id", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "part_get_mbr_id", "-1");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "part_get_mbr_id", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "part_get_mbr_id",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  ret_v = ret.idbyte;
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "part_get_mbr_id");
    fprintf (trace_fp, "%d", ret_v);
    trace_send_line (g);
  }

  return ret_v;
}

int
guestfs_part_set_mbr_id (guestfs_h *g,
                         const char *device,
                         int partnum,
                         int idbyte)
{
  struct guestfs_part_set_mbr_id_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "part_set_mbr_id", 15);
  if (device == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "part_set_mbr_id", "device");
    return -1;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "part_set_mbr_id");
    fprintf (trace_fp, " \"%s\"", device);
    fprintf (trace_fp, " %d", partnum);
    fprintf (trace_fp, " %d", idbyte);
    trace_send_line (g);
  }

  if (check_state (g, "part_set_mbr_id") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "part_set_mbr_id", "-1");
    return -1;
  }
  guestfs___set_busy (g);

  args.device = (char *) device;
  args.partnum = partnum;
  args.idbyte = idbyte;
  serial = guestfs___send (g, GUESTFS_PROC_PART_SET_MBR_ID,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_part_set_mbr_id_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "part_set_mbr_id", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "part_set_mbr_id", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "part_set_mbr_id", "-1");
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_PART_SET_MBR_ID, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "part_set_mbr_id", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "part_set_mbr_id", "-1");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "part_set_mbr_id", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "part_set_mbr_id",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  ret_v = 0;
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "part_set_mbr_id");
    fprintf (trace_fp, "%d", ret_v);
    trace_send_line (g);
  }

  return ret_v;
}

char *
guestfs_checksum_device (guestfs_h *g,
                         const char *csumtype,
                         const char *device)
{
  struct guestfs_checksum_device_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  struct guestfs_checksum_device_ret ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  char *ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "checksum_device", 15);
  if (csumtype == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "checksum_device", "csumtype");
    return NULL;
  }
  if (device == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "checksum_device", "device");
    return NULL;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "checksum_device");
    fprintf (trace_fp, " \"%s\"", csumtype);
    fprintf (trace_fp, " \"%s\"", device);
    trace_send_line (g);
  }

  if (check_state (g, "checksum_device") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "checksum_device", "NULL");
    return NULL;
  }
  guestfs___set_busy (g);

  args.csumtype = (char *) csumtype;
  args.device = (char *) device;
  serial = guestfs___send (g, GUESTFS_PROC_CHECKSUM_DEVICE,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_checksum_device_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "checksum_device", "NULL");
    return NULL;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs___recv (g, "checksum_device", &hdr, &err,
        (xdrproc_t) xdr_guestfs_checksum_device_ret, (char *) &ret);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "checksum_device", "NULL");
    return NULL;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_CHECKSUM_DEVICE, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "checksum_device", "NULL");
    return NULL;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "checksum_device", "NULL");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "checksum_device", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "checksum_device",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return NULL;
  }

  guestfs___end_busy (g);
  ret_v = ret.checksum; /* caller will free */
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "checksum_device");
    fprintf (trace_fp, "\"%s\"", ret_v);
    trace_send_line (g);
  }

  return ret_v;
}

int
guestfs_lvresize_free (guestfs_h *g,
                       const char *lv,
                       int percent)
{
  struct guestfs_lvresize_free_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "lvresize_free", 13);
  if (lv == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "lvresize_free", "lv");
    return -1;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "lvresize_free");
    fprintf (trace_fp, " \"%s\"", lv);
    fprintf (trace_fp, " %d", percent);
    trace_send_line (g);
  }

  if (check_state (g, "lvresize_free") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "lvresize_free", "-1");
    return -1;
  }
  guestfs___set_busy (g);

  args.lv = (char *) lv;
  args.percent = percent;
  serial = guestfs___send (g, GUESTFS_PROC_LVRESIZE_FREE,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_lvresize_free_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "lvresize_free", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "lvresize_free", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "lvresize_free", "-1");
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_LVRESIZE_FREE, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "lvresize_free", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "lvresize_free", "-1");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "lvresize_free", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "lvresize_free",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  ret_v = 0;
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "lvresize_free");
    fprintf (trace_fp, "%d", ret_v);
    trace_send_line (g);
  }

  return ret_v;
}

int
guestfs_aug_clear (guestfs_h *g,
                   const char *augpath)
{
  struct guestfs_aug_clear_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "aug_clear", 9);
  if (augpath == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "aug_clear", "augpath");
    return -1;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "aug_clear");
    fprintf (trace_fp, " \"%s\"", augpath);
    trace_send_line (g);
  }

  if (check_state (g, "aug_clear") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "aug_clear", "-1");
    return -1;
  }
  guestfs___set_busy (g);

  args.augpath = (char *) augpath;
  serial = guestfs___send (g, GUESTFS_PROC_AUG_CLEAR,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_aug_clear_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "aug_clear", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "aug_clear", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "aug_clear", "-1");
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_AUG_CLEAR, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "aug_clear", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "aug_clear", "-1");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "aug_clear", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "aug_clear",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  ret_v = 0;
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "aug_clear");
    fprintf (trace_fp, "%d", ret_v);
    trace_send_line (g);
  }

  return ret_v;
}

int
guestfs_get_umask (guestfs_h *g)
{
  guestfs_message_header hdr;
  guestfs_message_error err;
  struct guestfs_get_umask_ret ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "get_umask", 9);
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "get_umask");
    trace_send_line (g);
  }

  if (check_state (g, "get_umask") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "get_umask", "-1");
    return -1;
  }
  guestfs___set_busy (g);

  serial = guestfs___send (g, GUESTFS_PROC_GET_UMASK, progress_hint, 0,
                           NULL, NULL);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "get_umask", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs___recv (g, "get_umask", &hdr, &err,
        (xdrproc_t) xdr_guestfs_get_umask_ret, (char *) &ret);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "get_umask", "-1");
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_GET_UMASK, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "get_umask", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "get_umask", "-1");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "get_umask", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "get_umask",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  ret_v = ret.mask;
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "get_umask");
    fprintf (trace_fp, "%d", ret_v);
    trace_send_line (g);
  }

  return ret_v;
}

int
guestfs_debug_upload (guestfs_h *g,
                      const char *filename,
                      const char *tmpname,
                      int mode)
{
  struct guestfs_debug_upload_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  int ret_v;
  uint64_t progress_hint = 0;
  struct stat progress_stat;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "debug_upload", 12);
  if (filename == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "debug_upload", "filename");
    return -1;
  }
  if (tmpname == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "debug_upload", "tmpname");
    return -1;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "debug_upload");
    fprintf (trace_fp, " \"%s\"", filename);
    fprintf (trace_fp, " \"%s\"", tmpname);
    fprintf (trace_fp, " %d", mode);
    trace_send_line (g);
  }

  if (stat (filename, &progress_stat) == 0 &&
      S_ISREG (progress_stat.st_mode))
    progress_hint += progress_stat.st_size;

  if (check_state (g, "debug_upload") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "debug_upload", "-1");
    return -1;
  }
  guestfs___set_busy (g);

  args.tmpname = (char *) tmpname;
  args.mode = mode;
  serial = guestfs___send (g, GUESTFS_PROC_DEBUG_UPLOAD,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_debug_upload_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "debug_upload", "-1");
    return -1;
  }

  r = guestfs___send_file (g, filename);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "debug_upload", "-1");
    /* daemon will send an error reply which we discard */
    guestfs___recv_discard (g, "debug_upload");
    return -1;
  }
  if (r == -2) /* daemon cancelled */
    goto read_reply;

 read_reply:
  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "debug_upload", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "debug_upload", "-1");
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_DEBUG_UPLOAD, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "debug_upload", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "debug_upload", "-1");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "debug_upload", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "debug_upload",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  ret_v = 0;
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "debug_upload");
    fprintf (trace_fp, "%d", ret_v);
    trace_send_line (g);
  }

  return ret_v;
}

int
guestfs_base64_in (guestfs_h *g,
                   const char *base64file,
                   const char *filename)
{
  struct guestfs_base64_in_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  int ret_v;
  uint64_t progress_hint = 0;
  struct stat progress_stat;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "base64_in", 9);
  if (base64file == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "base64_in", "base64file");
    return -1;
  }
  if (filename == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "base64_in", "filename");
    return -1;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "base64_in");
    fprintf (trace_fp, " \"%s\"", base64file);
    fprintf (trace_fp, " \"%s\"", filename);
    trace_send_line (g);
  }

  if (stat (base64file, &progress_stat) == 0 &&
      S_ISREG (progress_stat.st_mode))
    progress_hint += progress_stat.st_size;

  if (check_state (g, "base64_in") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "base64_in", "-1");
    return -1;
  }
  guestfs___set_busy (g);

  args.filename = (char *) filename;
  serial = guestfs___send (g, GUESTFS_PROC_BASE64_IN,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_base64_in_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "base64_in", "-1");
    return -1;
  }

  r = guestfs___send_file (g, base64file);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "base64_in", "-1");
    /* daemon will send an error reply which we discard */
    guestfs___recv_discard (g, "base64_in");
    return -1;
  }
  if (r == -2) /* daemon cancelled */
    goto read_reply;

 read_reply:
  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "base64_in", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "base64_in", "-1");
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_BASE64_IN, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "base64_in", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "base64_in", "-1");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "base64_in", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "base64_in",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  ret_v = 0;
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "base64_in");
    fprintf (trace_fp, "%d", ret_v);
    trace_send_line (g);
  }

  return ret_v;
}

int
guestfs_base64_out (guestfs_h *g,
                    const char *filename,
                    const char *base64file)
{
  struct guestfs_base64_out_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "base64_out", 10);
  if (filename == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "base64_out", "filename");
    return -1;
  }
  if (base64file == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "base64_out", "base64file");
    return -1;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "base64_out");
    fprintf (trace_fp, " \"%s\"", filename);
    fprintf (trace_fp, " \"%s\"", base64file);
    trace_send_line (g);
  }

  if (check_state (g, "base64_out") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "base64_out", "-1");
    return -1;
  }
  guestfs___set_busy (g);

  args.filename = (char *) filename;
  serial = guestfs___send (g, GUESTFS_PROC_BASE64_OUT,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_base64_out_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "base64_out", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "base64_out", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "base64_out", "-1");
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_BASE64_OUT, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "base64_out", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "base64_out", "-1");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "base64_out", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "base64_out",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return -1;
  }

  if (guestfs___recv_file (g, base64file) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "base64_out", "-1");
    return -1;
  }

  guestfs___end_busy (g);
  ret_v = 0;
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "base64_out");
    fprintf (trace_fp, "%d", ret_v);
    trace_send_line (g);
  }

  return ret_v;
}

int
guestfs_checksums_out (guestfs_h *g,
                       const char *csumtype,
                       const char *directory,
                       const char *sumsfile)
{
  struct guestfs_checksums_out_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "checksums_out", 13);
  if (csumtype == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "checksums_out", "csumtype");
    return -1;
  }
  if (directory == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "checksums_out", "directory");
    return -1;
  }
  if (sumsfile == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "checksums_out", "sumsfile");
    return -1;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "checksums_out");
    fprintf (trace_fp, " \"%s\"", csumtype);
    fprintf (trace_fp, " \"%s\"", directory);
    fprintf (trace_fp, " \"%s\"", sumsfile);
    trace_send_line (g);
  }

  if (check_state (g, "checksums_out") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "checksums_out", "-1");
    return -1;
  }
  guestfs___set_busy (g);

  args.csumtype = (char *) csumtype;
  args.directory = (char *) directory;
  serial = guestfs___send (g, GUESTFS_PROC_CHECKSUMS_OUT,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_checksums_out_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "checksums_out", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "checksums_out", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "checksums_out", "-1");
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_CHECKSUMS_OUT, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "checksums_out", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "checksums_out", "-1");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "checksums_out", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "checksums_out",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return -1;
  }

  if (guestfs___recv_file (g, sumsfile) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "checksums_out", "-1");
    return -1;
  }

  guestfs___end_busy (g);
  ret_v = 0;
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "checksums_out");
    fprintf (trace_fp, "%d", ret_v);
    trace_send_line (g);
  }

  return ret_v;
}

int
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
  FILE *trace_fp;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
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
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "fill_pattern");
    fprintf (trace_fp, " \"%s\"", pattern);
    fprintf (trace_fp, " %d", len);
    fprintf (trace_fp, " \"%s\"", path);
    trace_send_line (g);
  }

  if (check_state (g, "fill_pattern") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "fill_pattern", "-1");
    return -1;
  }
  guestfs___set_busy (g);

  args.pattern = (char *) pattern;
  args.len = len;
  args.path = (char *) path;
  serial = guestfs___send (g, GUESTFS_PROC_FILL_PATTERN,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_fill_pattern_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "fill_pattern", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "fill_pattern", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "fill_pattern", "-1");
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_FILL_PATTERN, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "fill_pattern", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "fill_pattern", "-1");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "fill_pattern", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "fill_pattern",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  ret_v = 0;
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "fill_pattern");
    fprintf (trace_fp, "%d", ret_v);
    trace_send_line (g);
  }

  return ret_v;
}

int
guestfs_write (guestfs_h *g,
               const char *path,
               const char *content,
               size_t content_size)
{
  struct guestfs_write_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "write", 5);
  if (path == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "write", "path");
    return -1;
  }
  if (content == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "write", "content");
    return -1;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "write");
    fprintf (trace_fp, " \"%s\"", path);
    fputc (' ', trace_fp);
    guestfs___print_BufferIn (trace_fp, content, content_size);
    trace_send_line (g);
  }

  if (check_state (g, "write") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "write", "-1");
    return -1;
  }
  guestfs___set_busy (g);

  args.path = (char *) path;
  /* Just catch grossly large sizes. XDR encoding will make this precise. */
  if (content_size >= GUESTFS_MESSAGE_MAX) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "write", "-1");
    error (g, "%s: size of input buffer too large", "write");
    guestfs___end_busy (g);
    return -1;
  }
  args.content.content_val = (char *) content;
  args.content.content_len = content_size;
  serial = guestfs___send (g, GUESTFS_PROC_WRITE,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_write_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "write", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "write", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "write", "-1");
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_WRITE, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "write", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "write", "-1");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "write", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "write",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  ret_v = 0;
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "write");
    fprintf (trace_fp, "%d", ret_v);
    trace_send_line (g);
  }

  return ret_v;
}

int
guestfs_pwrite (guestfs_h *g,
                const char *path,
                const char *content,
                size_t content_size,
                int64_t offset)
{
  struct guestfs_pwrite_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  struct guestfs_pwrite_ret ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "pwrite", 6);
  if (path == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "pwrite", "path");
    return -1;
  }
  if (content == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "pwrite", "content");
    return -1;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "pwrite");
    fprintf (trace_fp, " \"%s\"", path);
    fputc (' ', trace_fp);
    guestfs___print_BufferIn (trace_fp, content, content_size);
    fprintf (trace_fp, " %" PRIi64, offset);
    trace_send_line (g);
  }

  if (check_state (g, "pwrite") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "pwrite", "-1");
    return -1;
  }
  guestfs___set_busy (g);

  args.path = (char *) path;
  /* Just catch grossly large sizes. XDR encoding will make this precise. */
  if (content_size >= GUESTFS_MESSAGE_MAX) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "pwrite", "-1");
    error (g, "%s: size of input buffer too large", "pwrite");
    guestfs___end_busy (g);
    return -1;
  }
  args.content.content_val = (char *) content;
  args.content.content_len = content_size;
  args.offset = offset;
  serial = guestfs___send (g, GUESTFS_PROC_PWRITE,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_pwrite_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "pwrite", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs___recv (g, "pwrite", &hdr, &err,
        (xdrproc_t) xdr_guestfs_pwrite_ret, (char *) &ret);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "pwrite", "-1");
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_PWRITE, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "pwrite", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "pwrite", "-1");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "pwrite", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "pwrite",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  ret_v = ret.nbytes;
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "pwrite");
    fprintf (trace_fp, "%d", ret_v);
    trace_send_line (g);
  }

  return ret_v;
}

int
guestfs_resize2fs_size (guestfs_h *g,
                        const char *device,
                        int64_t size)
{
  struct guestfs_resize2fs_size_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "resize2fs_size", 14);
  if (device == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "resize2fs_size", "device");
    return -1;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "resize2fs_size");
    fprintf (trace_fp, " \"%s\"", device);
    fprintf (trace_fp, " %" PRIi64, size);
    trace_send_line (g);
  }

  if (check_state (g, "resize2fs_size") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "resize2fs_size", "-1");
    return -1;
  }
  guestfs___set_busy (g);

  args.device = (char *) device;
  args.size = size;
  serial = guestfs___send (g, GUESTFS_PROC_RESIZE2FS_SIZE,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_resize2fs_size_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "resize2fs_size", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "resize2fs_size", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "resize2fs_size", "-1");
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_RESIZE2FS_SIZE, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "resize2fs_size", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "resize2fs_size", "-1");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "resize2fs_size", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "resize2fs_size",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  ret_v = 0;
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "resize2fs_size");
    fprintf (trace_fp, "%d", ret_v);
    trace_send_line (g);
  }

  return ret_v;
}

int
guestfs_pvresize_size (guestfs_h *g,
                       const char *device,
                       int64_t size)
{
  struct guestfs_pvresize_size_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "pvresize_size", 13);
  if (device == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "pvresize_size", "device");
    return -1;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "pvresize_size");
    fprintf (trace_fp, " \"%s\"", device);
    fprintf (trace_fp, " %" PRIi64, size);
    trace_send_line (g);
  }

  if (check_state (g, "pvresize_size") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "pvresize_size", "-1");
    return -1;
  }
  guestfs___set_busy (g);

  args.device = (char *) device;
  args.size = size;
  serial = guestfs___send (g, GUESTFS_PROC_PVRESIZE_SIZE,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_pvresize_size_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "pvresize_size", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "pvresize_size", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "pvresize_size", "-1");
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_PVRESIZE_SIZE, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "pvresize_size", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "pvresize_size", "-1");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "pvresize_size", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "pvresize_size",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  ret_v = 0;
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "pvresize_size");
    fprintf (trace_fp, "%d", ret_v);
    trace_send_line (g);
  }

  return ret_v;
}

int
guestfs_ntfsresize_size (guestfs_h *g,
                         const char *device,
                         int64_t size)
{
  struct guestfs_ntfsresize_size_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "ntfsresize_size", 15);
  if (device == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "ntfsresize_size", "device");
    return -1;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "ntfsresize_size");
    fprintf (trace_fp, " \"%s\"", device);
    fprintf (trace_fp, " %" PRIi64, size);
    trace_send_line (g);
  }

  if (check_state (g, "ntfsresize_size") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "ntfsresize_size", "-1");
    return -1;
  }
  guestfs___set_busy (g);

  args.device = (char *) device;
  args.size = size;
  serial = guestfs___send (g, GUESTFS_PROC_NTFSRESIZE_SIZE,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_ntfsresize_size_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "ntfsresize_size", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "ntfsresize_size", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "ntfsresize_size", "-1");
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_NTFSRESIZE_SIZE, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "ntfsresize_size", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "ntfsresize_size", "-1");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "ntfsresize_size", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "ntfsresize_size",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  ret_v = 0;
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "ntfsresize_size");
    fprintf (trace_fp, "%d", ret_v);
    trace_send_line (g);
  }

  return ret_v;
}

char **
guestfs_available_all_groups (guestfs_h *g)
{
  guestfs_message_header hdr;
  guestfs_message_error err;
  struct guestfs_available_all_groups_ret ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  char **ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "available_all_groups", 20);
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "available_all_groups");
    trace_send_line (g);
  }

  if (check_state (g, "available_all_groups") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "available_all_groups", "NULL");
    return NULL;
  }
  guestfs___set_busy (g);

  serial = guestfs___send (g, GUESTFS_PROC_AVAILABLE_ALL_GROUPS, progress_hint, 0,
                           NULL, NULL);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "available_all_groups", "NULL");
    return NULL;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs___recv (g, "available_all_groups", &hdr, &err,
        (xdrproc_t) xdr_guestfs_available_all_groups_ret, (char *) &ret);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "available_all_groups", "NULL");
    return NULL;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_AVAILABLE_ALL_GROUPS, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "available_all_groups", "NULL");
    return NULL;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "available_all_groups", "NULL");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "available_all_groups", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "available_all_groups",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return NULL;
  }

  guestfs___end_busy (g);
  /* caller will free this, but we need to add a NULL entry */
  ret.groups.groups_val =
    safe_realloc (g, ret.groups.groups_val,
                  sizeof (char *) * (ret.groups.groups_len + 1));
  ret.groups.groups_val[ret.groups.groups_len] = NULL;
  ret_v = ret.groups.groups_val;
  if (trace_flag) {
    size_t i;

    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "available_all_groups");
    fputs ("[", trace_fp);
    for (i = 0; ret_v[i]; ++i) {
      if (i > 0) fputs (", ", trace_fp);
      fputs ("\"", trace_fp);
      fputs (ret_v[i], trace_fp);
      fputs ("\"", trace_fp);
    }
    fputs ("]", trace_fp);
    trace_send_line (g);
  }

  return ret_v;
}

int
guestfs_fallocate64 (guestfs_h *g,
                     const char *path,
                     int64_t len)
{
  struct guestfs_fallocate64_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "fallocate64", 11);
  if (path == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "fallocate64", "path");
    return -1;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "fallocate64");
    fprintf (trace_fp, " \"%s\"", path);
    fprintf (trace_fp, " %" PRIi64, len);
    trace_send_line (g);
  }

  if (check_state (g, "fallocate64") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "fallocate64", "-1");
    return -1;
  }
  guestfs___set_busy (g);

  args.path = (char *) path;
  args.len = len;
  serial = guestfs___send (g, GUESTFS_PROC_FALLOCATE64,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_fallocate64_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "fallocate64", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "fallocate64", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "fallocate64", "-1");
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_FALLOCATE64, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "fallocate64", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "fallocate64", "-1");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "fallocate64", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "fallocate64",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  ret_v = 0;
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "fallocate64");
    fprintf (trace_fp, "%d", ret_v);
    trace_send_line (g);
  }

  return ret_v;
}

char *
guestfs_vfs_label (guestfs_h *g,
                   const char *device)
{
  struct guestfs_vfs_label_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  struct guestfs_vfs_label_ret ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  char *ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "vfs_label", 9);
  if (device == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "vfs_label", "device");
    return NULL;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "vfs_label");
    fprintf (trace_fp, " \"%s\"", device);
    trace_send_line (g);
  }

  if (check_state (g, "vfs_label") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "vfs_label", "NULL");
    return NULL;
  }
  guestfs___set_busy (g);

  args.device = (char *) device;
  serial = guestfs___send (g, GUESTFS_PROC_VFS_LABEL,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_vfs_label_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "vfs_label", "NULL");
    return NULL;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs___recv (g, "vfs_label", &hdr, &err,
        (xdrproc_t) xdr_guestfs_vfs_label_ret, (char *) &ret);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "vfs_label", "NULL");
    return NULL;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_VFS_LABEL, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "vfs_label", "NULL");
    return NULL;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "vfs_label", "NULL");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "vfs_label", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "vfs_label",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return NULL;
  }

  guestfs___end_busy (g);
  ret_v = ret.label; /* caller will free */
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "vfs_label");
    fprintf (trace_fp, "\"%s\"", ret_v);
    trace_send_line (g);
  }

  return ret_v;
}

char *
guestfs_vfs_uuid (guestfs_h *g,
                  const char *device)
{
  struct guestfs_vfs_uuid_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  struct guestfs_vfs_uuid_ret ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  char *ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "vfs_uuid", 8);
  if (device == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "vfs_uuid", "device");
    return NULL;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "vfs_uuid");
    fprintf (trace_fp, " \"%s\"", device);
    trace_send_line (g);
  }

  if (check_state (g, "vfs_uuid") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "vfs_uuid", "NULL");
    return NULL;
  }
  guestfs___set_busy (g);

  args.device = (char *) device;
  serial = guestfs___send (g, GUESTFS_PROC_VFS_UUID,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_vfs_uuid_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "vfs_uuid", "NULL");
    return NULL;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs___recv (g, "vfs_uuid", &hdr, &err,
        (xdrproc_t) xdr_guestfs_vfs_uuid_ret, (char *) &ret);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "vfs_uuid", "NULL");
    return NULL;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_VFS_UUID, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "vfs_uuid", "NULL");
    return NULL;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "vfs_uuid", "NULL");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "vfs_uuid", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "vfs_uuid",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return NULL;
  }

  guestfs___end_busy (g);
  ret_v = ret.uuid; /* caller will free */
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "vfs_uuid");
    fprintf (trace_fp, "\"%s\"", ret_v);
    trace_send_line (g);
  }

  return ret_v;
}

int
guestfs_lvm_set_filter (guestfs_h *g,
                        char *const *devices)
{
  struct guestfs_lvm_set_filter_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "lvm_set_filter", 14);
  if (devices == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "lvm_set_filter", "devices");
    return -1;
  }

  if (trace_flag) {
    size_t i;

    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "lvm_set_filter");
    fputc (' ', trace_fp);
    fputc ('"', trace_fp);
    for (i = 0; devices[i]; ++i) {
      if (i > 0) fputc (' ', trace_fp);
      fputs (devices[i], trace_fp);
    }
    fputc ('"', trace_fp);
    trace_send_line (g);
  }

  if (check_state (g, "lvm_set_filter") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "lvm_set_filter", "-1");
    return -1;
  }
  guestfs___set_busy (g);

  args.devices.devices_val = (char **) devices;
  for (args.devices.devices_len = 0; devices[args.devices.devices_len]; args.devices.devices_len++) ;
  serial = guestfs___send (g, GUESTFS_PROC_LVM_SET_FILTER,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_lvm_set_filter_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "lvm_set_filter", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "lvm_set_filter", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "lvm_set_filter", "-1");
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_LVM_SET_FILTER, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "lvm_set_filter", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "lvm_set_filter", "-1");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "lvm_set_filter", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "lvm_set_filter",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  ret_v = 0;
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "lvm_set_filter");
    fprintf (trace_fp, "%d", ret_v);
    trace_send_line (g);
  }

  return ret_v;
}

int
guestfs_lvm_clear_filter (guestfs_h *g)
{
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "lvm_clear_filter", 16);
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "lvm_clear_filter");
    trace_send_line (g);
  }

  if (check_state (g, "lvm_clear_filter") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "lvm_clear_filter", "-1");
    return -1;
  }
  guestfs___set_busy (g);

  serial = guestfs___send (g, GUESTFS_PROC_LVM_CLEAR_FILTER, progress_hint, 0,
                           NULL, NULL);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "lvm_clear_filter", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "lvm_clear_filter", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "lvm_clear_filter", "-1");
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_LVM_CLEAR_FILTER, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "lvm_clear_filter", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "lvm_clear_filter", "-1");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "lvm_clear_filter", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "lvm_clear_filter",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  ret_v = 0;
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "lvm_clear_filter");
    fprintf (trace_fp, "%d", ret_v);
    trace_send_line (g);
  }

  return ret_v;
}

int
guestfs_luks_open (guestfs_h *g,
                   const char *device,
                   const char *key,
                   const char *mapname)
{
  struct guestfs_luks_open_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "luks_open", 9);
  if (device == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "luks_open", "device");
    return -1;
  }
  if (key == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "luks_open", "key");
    return -1;
  }
  if (mapname == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "luks_open", "mapname");
    return -1;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "luks_open");
    fprintf (trace_fp, " \"%s\"", device);
    fprintf (trace_fp, " \"***\"");
    fprintf (trace_fp, " \"%s\"", mapname);
    trace_send_line (g);
  }

  if (check_state (g, "luks_open") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "luks_open", "-1");
    return -1;
  }
  guestfs___set_busy (g);

  args.device = (char *) device;
  args.key = (char *) key;
  args.mapname = (char *) mapname;
  serial = guestfs___send (g, GUESTFS_PROC_LUKS_OPEN,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_luks_open_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "luks_open", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "luks_open", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "luks_open", "-1");
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_LUKS_OPEN, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "luks_open", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "luks_open", "-1");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "luks_open", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "luks_open",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  ret_v = 0;
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "luks_open");
    fprintf (trace_fp, "%d", ret_v);
    trace_send_line (g);
  }

  return ret_v;
}

int
guestfs_luks_open_ro (guestfs_h *g,
                      const char *device,
                      const char *key,
                      const char *mapname)
{
  struct guestfs_luks_open_ro_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "luks_open_ro", 12);
  if (device == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "luks_open_ro", "device");
    return -1;
  }
  if (key == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "luks_open_ro", "key");
    return -1;
  }
  if (mapname == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "luks_open_ro", "mapname");
    return -1;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "luks_open_ro");
    fprintf (trace_fp, " \"%s\"", device);
    fprintf (trace_fp, " \"***\"");
    fprintf (trace_fp, " \"%s\"", mapname);
    trace_send_line (g);
  }

  if (check_state (g, "luks_open_ro") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "luks_open_ro", "-1");
    return -1;
  }
  guestfs___set_busy (g);

  args.device = (char *) device;
  args.key = (char *) key;
  args.mapname = (char *) mapname;
  serial = guestfs___send (g, GUESTFS_PROC_LUKS_OPEN_RO,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_luks_open_ro_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "luks_open_ro", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "luks_open_ro", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "luks_open_ro", "-1");
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_LUKS_OPEN_RO, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "luks_open_ro", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "luks_open_ro", "-1");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "luks_open_ro", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "luks_open_ro",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  ret_v = 0;
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "luks_open_ro");
    fprintf (trace_fp, "%d", ret_v);
    trace_send_line (g);
  }

  return ret_v;
}

int
guestfs_luks_close (guestfs_h *g,
                    const char *device)
{
  struct guestfs_luks_close_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "luks_close", 10);
  if (device == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "luks_close", "device");
    return -1;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "luks_close");
    fprintf (trace_fp, " \"%s\"", device);
    trace_send_line (g);
  }

  if (check_state (g, "luks_close") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "luks_close", "-1");
    return -1;
  }
  guestfs___set_busy (g);

  args.device = (char *) device;
  serial = guestfs___send (g, GUESTFS_PROC_LUKS_CLOSE,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_luks_close_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "luks_close", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "luks_close", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "luks_close", "-1");
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_LUKS_CLOSE, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "luks_close", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "luks_close", "-1");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "luks_close", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "luks_close",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  ret_v = 0;
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "luks_close");
    fprintf (trace_fp, "%d", ret_v);
    trace_send_line (g);
  }

  return ret_v;
}

int
guestfs_luks_format (guestfs_h *g,
                     const char *device,
                     const char *key,
                     int keyslot)
{
  struct guestfs_luks_format_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "luks_format", 11);
  if (device == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "luks_format", "device");
    return -1;
  }
  if (key == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "luks_format", "key");
    return -1;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "luks_format");
    fprintf (trace_fp, " \"%s\"", device);
    fprintf (trace_fp, " \"***\"");
    fprintf (trace_fp, " %d", keyslot);
    trace_send_line (g);
  }

  if (check_state (g, "luks_format") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "luks_format", "-1");
    return -1;
  }
  guestfs___set_busy (g);

  args.device = (char *) device;
  args.key = (char *) key;
  args.keyslot = keyslot;
  serial = guestfs___send (g, GUESTFS_PROC_LUKS_FORMAT,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_luks_format_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "luks_format", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "luks_format", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "luks_format", "-1");
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_LUKS_FORMAT, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "luks_format", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "luks_format", "-1");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "luks_format", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "luks_format",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  ret_v = 0;
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "luks_format");
    fprintf (trace_fp, "%d", ret_v);
    trace_send_line (g);
  }

  return ret_v;
}

int
guestfs_luks_format_cipher (guestfs_h *g,
                            const char *device,
                            const char *key,
                            int keyslot,
                            const char *cipher)
{
  struct guestfs_luks_format_cipher_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "luks_format_cipher", 18);
  if (device == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "luks_format_cipher", "device");
    return -1;
  }
  if (key == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "luks_format_cipher", "key");
    return -1;
  }
  if (cipher == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "luks_format_cipher", "cipher");
    return -1;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "luks_format_cipher");
    fprintf (trace_fp, " \"%s\"", device);
    fprintf (trace_fp, " \"***\"");
    fprintf (trace_fp, " %d", keyslot);
    fprintf (trace_fp, " \"%s\"", cipher);
    trace_send_line (g);
  }

  if (check_state (g, "luks_format_cipher") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "luks_format_cipher", "-1");
    return -1;
  }
  guestfs___set_busy (g);

  args.device = (char *) device;
  args.key = (char *) key;
  args.keyslot = keyslot;
  args.cipher = (char *) cipher;
  serial = guestfs___send (g, GUESTFS_PROC_LUKS_FORMAT_CIPHER,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_luks_format_cipher_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "luks_format_cipher", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "luks_format_cipher", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "luks_format_cipher", "-1");
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_LUKS_FORMAT_CIPHER, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "luks_format_cipher", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "luks_format_cipher", "-1");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "luks_format_cipher", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "luks_format_cipher",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  ret_v = 0;
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "luks_format_cipher");
    fprintf (trace_fp, "%d", ret_v);
    trace_send_line (g);
  }

  return ret_v;
}

int
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
  FILE *trace_fp;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
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
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "luks_add_key");
    fprintf (trace_fp, " \"%s\"", device);
    fprintf (trace_fp, " \"***\"");
    fprintf (trace_fp, " \"***\"");
    fprintf (trace_fp, " %d", keyslot);
    trace_send_line (g);
  }

  if (check_state (g, "luks_add_key") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "luks_add_key", "-1");
    return -1;
  }
  guestfs___set_busy (g);

  args.device = (char *) device;
  args.key = (char *) key;
  args.newkey = (char *) newkey;
  args.keyslot = keyslot;
  serial = guestfs___send (g, GUESTFS_PROC_LUKS_ADD_KEY,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_luks_add_key_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "luks_add_key", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "luks_add_key", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "luks_add_key", "-1");
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_LUKS_ADD_KEY, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "luks_add_key", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "luks_add_key", "-1");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "luks_add_key", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "luks_add_key",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  ret_v = 0;
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "luks_add_key");
    fprintf (trace_fp, "%d", ret_v);
    trace_send_line (g);
  }

  return ret_v;
}

int
guestfs_luks_kill_slot (guestfs_h *g,
                        const char *device,
                        const char *key,
                        int keyslot)
{
  struct guestfs_luks_kill_slot_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "luks_kill_slot", 14);
  if (device == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "luks_kill_slot", "device");
    return -1;
  }
  if (key == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "luks_kill_slot", "key");
    return -1;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "luks_kill_slot");
    fprintf (trace_fp, " \"%s\"", device);
    fprintf (trace_fp, " \"***\"");
    fprintf (trace_fp, " %d", keyslot);
    trace_send_line (g);
  }

  if (check_state (g, "luks_kill_slot") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "luks_kill_slot", "-1");
    return -1;
  }
  guestfs___set_busy (g);

  args.device = (char *) device;
  args.key = (char *) key;
  args.keyslot = keyslot;
  serial = guestfs___send (g, GUESTFS_PROC_LUKS_KILL_SLOT,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_luks_kill_slot_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "luks_kill_slot", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "luks_kill_slot", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "luks_kill_slot", "-1");
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_LUKS_KILL_SLOT, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "luks_kill_slot", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "luks_kill_slot", "-1");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "luks_kill_slot", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "luks_kill_slot",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  ret_v = 0;
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "luks_kill_slot");
    fprintf (trace_fp, "%d", ret_v);
    trace_send_line (g);
  }

  return ret_v;
}

int
guestfs_is_lv (guestfs_h *g,
               const char *device)
{
  struct guestfs_is_lv_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  struct guestfs_is_lv_ret ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "is_lv", 5);
  if (device == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "is_lv", "device");
    return -1;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "is_lv");
    fprintf (trace_fp, " \"%s\"", device);
    trace_send_line (g);
  }

  if (check_state (g, "is_lv") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "is_lv", "-1");
    return -1;
  }
  guestfs___set_busy (g);

  args.device = (char *) device;
  serial = guestfs___send (g, GUESTFS_PROC_IS_LV,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_is_lv_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "is_lv", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs___recv (g, "is_lv", &hdr, &err,
        (xdrproc_t) xdr_guestfs_is_lv_ret, (char *) &ret);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "is_lv", "-1");
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_IS_LV, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "is_lv", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "is_lv", "-1");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "is_lv", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "is_lv",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  ret_v = ret.lvflag;
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "is_lv");
    fprintf (trace_fp, "%d", ret_v);
    trace_send_line (g);
  }

  return ret_v;
}

char *
guestfs_findfs_uuid (guestfs_h *g,
                     const char *uuid)
{
  struct guestfs_findfs_uuid_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  struct guestfs_findfs_uuid_ret ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  char *ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "findfs_uuid", 11);
  if (uuid == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "findfs_uuid", "uuid");
    return NULL;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "findfs_uuid");
    fprintf (trace_fp, " \"%s\"", uuid);
    trace_send_line (g);
  }

  if (check_state (g, "findfs_uuid") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "findfs_uuid", "NULL");
    return NULL;
  }
  guestfs___set_busy (g);

  args.uuid = (char *) uuid;
  serial = guestfs___send (g, GUESTFS_PROC_FINDFS_UUID,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_findfs_uuid_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "findfs_uuid", "NULL");
    return NULL;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs___recv (g, "findfs_uuid", &hdr, &err,
        (xdrproc_t) xdr_guestfs_findfs_uuid_ret, (char *) &ret);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "findfs_uuid", "NULL");
    return NULL;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_FINDFS_UUID, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "findfs_uuid", "NULL");
    return NULL;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "findfs_uuid", "NULL");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "findfs_uuid", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "findfs_uuid",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return NULL;
  }

  guestfs___end_busy (g);
  ret_v = ret.device; /* caller will free */
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "findfs_uuid");
    fprintf (trace_fp, "\"%s\"", ret_v);
    trace_send_line (g);
  }

  return ret_v;
}

char *
guestfs_findfs_label (guestfs_h *g,
                      const char *label)
{
  struct guestfs_findfs_label_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  struct guestfs_findfs_label_ret ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  char *ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "findfs_label", 12);
  if (label == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "findfs_label", "label");
    return NULL;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "findfs_label");
    fprintf (trace_fp, " \"%s\"", label);
    trace_send_line (g);
  }

  if (check_state (g, "findfs_label") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "findfs_label", "NULL");
    return NULL;
  }
  guestfs___set_busy (g);

  args.label = (char *) label;
  serial = guestfs___send (g, GUESTFS_PROC_FINDFS_LABEL,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_findfs_label_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "findfs_label", "NULL");
    return NULL;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs___recv (g, "findfs_label", &hdr, &err,
        (xdrproc_t) xdr_guestfs_findfs_label_ret, (char *) &ret);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "findfs_label", "NULL");
    return NULL;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_FINDFS_LABEL, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "findfs_label", "NULL");
    return NULL;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "findfs_label", "NULL");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "findfs_label", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "findfs_label",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return NULL;
  }

  guestfs___end_busy (g);
  ret_v = ret.device; /* caller will free */
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "findfs_label");
    fprintf (trace_fp, "\"%s\"", ret_v);
    trace_send_line (g);
  }

  return ret_v;
}

int
guestfs_is_chardev (guestfs_h *g,
                    const char *path)
{
  struct guestfs_is_chardev_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  struct guestfs_is_chardev_ret ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "is_chardev", 10);
  if (path == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "is_chardev", "path");
    return -1;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "is_chardev");
    fprintf (trace_fp, " \"%s\"", path);
    trace_send_line (g);
  }

  if (check_state (g, "is_chardev") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "is_chardev", "-1");
    return -1;
  }
  guestfs___set_busy (g);

  args.path = (char *) path;
  serial = guestfs___send (g, GUESTFS_PROC_IS_CHARDEV,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_is_chardev_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "is_chardev", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs___recv (g, "is_chardev", &hdr, &err,
        (xdrproc_t) xdr_guestfs_is_chardev_ret, (char *) &ret);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "is_chardev", "-1");
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_IS_CHARDEV, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "is_chardev", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "is_chardev", "-1");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "is_chardev", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "is_chardev",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  ret_v = ret.flag;
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "is_chardev");
    fprintf (trace_fp, "%d", ret_v);
    trace_send_line (g);
  }

  return ret_v;
}

int
guestfs_is_blockdev (guestfs_h *g,
                     const char *path)
{
  struct guestfs_is_blockdev_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  struct guestfs_is_blockdev_ret ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "is_blockdev", 11);
  if (path == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "is_blockdev", "path");
    return -1;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "is_blockdev");
    fprintf (trace_fp, " \"%s\"", path);
    trace_send_line (g);
  }

  if (check_state (g, "is_blockdev") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "is_blockdev", "-1");
    return -1;
  }
  guestfs___set_busy (g);

  args.path = (char *) path;
  serial = guestfs___send (g, GUESTFS_PROC_IS_BLOCKDEV,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_is_blockdev_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "is_blockdev", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs___recv (g, "is_blockdev", &hdr, &err,
        (xdrproc_t) xdr_guestfs_is_blockdev_ret, (char *) &ret);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "is_blockdev", "-1");
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_IS_BLOCKDEV, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "is_blockdev", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "is_blockdev", "-1");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "is_blockdev", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "is_blockdev",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  ret_v = ret.flag;
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "is_blockdev");
    fprintf (trace_fp, "%d", ret_v);
    trace_send_line (g);
  }

  return ret_v;
}

int
guestfs_is_fifo (guestfs_h *g,
                 const char *path)
{
  struct guestfs_is_fifo_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  struct guestfs_is_fifo_ret ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "is_fifo", 7);
  if (path == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "is_fifo", "path");
    return -1;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "is_fifo");
    fprintf (trace_fp, " \"%s\"", path);
    trace_send_line (g);
  }

  if (check_state (g, "is_fifo") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "is_fifo", "-1");
    return -1;
  }
  guestfs___set_busy (g);

  args.path = (char *) path;
  serial = guestfs___send (g, GUESTFS_PROC_IS_FIFO,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_is_fifo_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "is_fifo", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs___recv (g, "is_fifo", &hdr, &err,
        (xdrproc_t) xdr_guestfs_is_fifo_ret, (char *) &ret);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "is_fifo", "-1");
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_IS_FIFO, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "is_fifo", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "is_fifo", "-1");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "is_fifo", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "is_fifo",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  ret_v = ret.flag;
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "is_fifo");
    fprintf (trace_fp, "%d", ret_v);
    trace_send_line (g);
  }

  return ret_v;
}

int
guestfs_is_symlink (guestfs_h *g,
                    const char *path)
{
  struct guestfs_is_symlink_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  struct guestfs_is_symlink_ret ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "is_symlink", 10);
  if (path == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "is_symlink", "path");
    return -1;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "is_symlink");
    fprintf (trace_fp, " \"%s\"", path);
    trace_send_line (g);
  }

  if (check_state (g, "is_symlink") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "is_symlink", "-1");
    return -1;
  }
  guestfs___set_busy (g);

  args.path = (char *) path;
  serial = guestfs___send (g, GUESTFS_PROC_IS_SYMLINK,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_is_symlink_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "is_symlink", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs___recv (g, "is_symlink", &hdr, &err,
        (xdrproc_t) xdr_guestfs_is_symlink_ret, (char *) &ret);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "is_symlink", "-1");
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_IS_SYMLINK, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "is_symlink", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "is_symlink", "-1");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "is_symlink", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "is_symlink",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  ret_v = ret.flag;
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "is_symlink");
    fprintf (trace_fp, "%d", ret_v);
    trace_send_line (g);
  }

  return ret_v;
}

int
guestfs_is_socket (guestfs_h *g,
                   const char *path)
{
  struct guestfs_is_socket_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  struct guestfs_is_socket_ret ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "is_socket", 9);
  if (path == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "is_socket", "path");
    return -1;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "is_socket");
    fprintf (trace_fp, " \"%s\"", path);
    trace_send_line (g);
  }

  if (check_state (g, "is_socket") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "is_socket", "-1");
    return -1;
  }
  guestfs___set_busy (g);

  args.path = (char *) path;
  serial = guestfs___send (g, GUESTFS_PROC_IS_SOCKET,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_is_socket_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "is_socket", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs___recv (g, "is_socket", &hdr, &err,
        (xdrproc_t) xdr_guestfs_is_socket_ret, (char *) &ret);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "is_socket", "-1");
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_IS_SOCKET, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "is_socket", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "is_socket", "-1");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "is_socket", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "is_socket",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  ret_v = ret.flag;
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "is_socket");
    fprintf (trace_fp, "%d", ret_v);
    trace_send_line (g);
  }

  return ret_v;
}

char *
guestfs_part_to_dev (guestfs_h *g,
                     const char *partition)
{
  struct guestfs_part_to_dev_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  struct guestfs_part_to_dev_ret ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  char *ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "part_to_dev", 11);
  if (partition == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "part_to_dev", "partition");
    return NULL;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "part_to_dev");
    fprintf (trace_fp, " \"%s\"", partition);
    trace_send_line (g);
  }

  if (check_state (g, "part_to_dev") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "part_to_dev", "NULL");
    return NULL;
  }
  guestfs___set_busy (g);

  args.partition = (char *) partition;
  serial = guestfs___send (g, GUESTFS_PROC_PART_TO_DEV,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_part_to_dev_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "part_to_dev", "NULL");
    return NULL;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs___recv (g, "part_to_dev", &hdr, &err,
        (xdrproc_t) xdr_guestfs_part_to_dev_ret, (char *) &ret);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "part_to_dev", "NULL");
    return NULL;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_PART_TO_DEV, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "part_to_dev", "NULL");
    return NULL;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "part_to_dev", "NULL");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "part_to_dev", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "part_to_dev",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return NULL;
  }

  guestfs___end_busy (g);
  ret_v = ret.device; /* caller will free */
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "part_to_dev");
    fprintf (trace_fp, "\"%s\"", ret_v);
    trace_send_line (g);
  }

  return ret_v;
}

int
guestfs_upload_offset (guestfs_h *g,
                       const char *filename,
                       const char *remotefilename,
                       int64_t offset)
{
  struct guestfs_upload_offset_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  int ret_v;
  uint64_t progress_hint = 0;
  struct stat progress_stat;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "upload_offset", 13);
  if (filename == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "upload_offset", "filename");
    return -1;
  }
  if (remotefilename == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "upload_offset", "remotefilename");
    return -1;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "upload_offset");
    fprintf (trace_fp, " \"%s\"", filename);
    fprintf (trace_fp, " \"%s\"", remotefilename);
    fprintf (trace_fp, " %" PRIi64, offset);
    trace_send_line (g);
  }

  if (stat (filename, &progress_stat) == 0 &&
      S_ISREG (progress_stat.st_mode))
    progress_hint += progress_stat.st_size;

  if (check_state (g, "upload_offset") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "upload_offset", "-1");
    return -1;
  }
  guestfs___set_busy (g);

  args.remotefilename = (char *) remotefilename;
  args.offset = offset;
  serial = guestfs___send (g, GUESTFS_PROC_UPLOAD_OFFSET,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_upload_offset_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "upload_offset", "-1");
    return -1;
  }

  r = guestfs___send_file (g, filename);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "upload_offset", "-1");
    /* daemon will send an error reply which we discard */
    guestfs___recv_discard (g, "upload_offset");
    return -1;
  }
  if (r == -2) /* daemon cancelled */
    goto read_reply;

 read_reply:
  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "upload_offset", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "upload_offset", "-1");
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_UPLOAD_OFFSET, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "upload_offset", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "upload_offset", "-1");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "upload_offset", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "upload_offset",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  ret_v = 0;
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "upload_offset");
    fprintf (trace_fp, "%d", ret_v);
    trace_send_line (g);
  }

  return ret_v;
}

int
guestfs_download_offset (guestfs_h *g,
                         const char *remotefilename,
                         const char *filename,
                         int64_t offset,
                         int64_t size)
{
  struct guestfs_download_offset_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "download_offset", 15);
  if (remotefilename == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "download_offset", "remotefilename");
    return -1;
  }
  if (filename == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "download_offset", "filename");
    return -1;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "download_offset");
    fprintf (trace_fp, " \"%s\"", remotefilename);
    fprintf (trace_fp, " \"%s\"", filename);
    fprintf (trace_fp, " %" PRIi64, offset);
    fprintf (trace_fp, " %" PRIi64, size);
    trace_send_line (g);
  }

  if (check_state (g, "download_offset") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "download_offset", "-1");
    return -1;
  }
  guestfs___set_busy (g);

  args.remotefilename = (char *) remotefilename;
  args.offset = offset;
  args.size = size;
  serial = guestfs___send (g, GUESTFS_PROC_DOWNLOAD_OFFSET,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_download_offset_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "download_offset", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "download_offset", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "download_offset", "-1");
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_DOWNLOAD_OFFSET, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "download_offset", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "download_offset", "-1");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "download_offset", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "download_offset",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return -1;
  }

  if (guestfs___recv_file (g, filename) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "download_offset", "-1");
    return -1;
  }

  guestfs___end_busy (g);
  ret_v = 0;
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "download_offset");
    fprintf (trace_fp, "%d", ret_v);
    trace_send_line (g);
  }

  return ret_v;
}

int
guestfs_pwrite_device (guestfs_h *g,
                       const char *device,
                       const char *content,
                       size_t content_size,
                       int64_t offset)
{
  struct guestfs_pwrite_device_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  struct guestfs_pwrite_device_ret ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "pwrite_device", 13);
  if (device == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "pwrite_device", "device");
    return -1;
  }
  if (content == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "pwrite_device", "content");
    return -1;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "pwrite_device");
    fprintf (trace_fp, " \"%s\"", device);
    fputc (' ', trace_fp);
    guestfs___print_BufferIn (trace_fp, content, content_size);
    fprintf (trace_fp, " %" PRIi64, offset);
    trace_send_line (g);
  }

  if (check_state (g, "pwrite_device") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "pwrite_device", "-1");
    return -1;
  }
  guestfs___set_busy (g);

  args.device = (char *) device;
  /* Just catch grossly large sizes. XDR encoding will make this precise. */
  if (content_size >= GUESTFS_MESSAGE_MAX) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "pwrite_device", "-1");
    error (g, "%s: size of input buffer too large", "pwrite_device");
    guestfs___end_busy (g);
    return -1;
  }
  args.content.content_val = (char *) content;
  args.content.content_len = content_size;
  args.offset = offset;
  serial = guestfs___send (g, GUESTFS_PROC_PWRITE_DEVICE,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_pwrite_device_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "pwrite_device", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs___recv (g, "pwrite_device", &hdr, &err,
        (xdrproc_t) xdr_guestfs_pwrite_device_ret, (char *) &ret);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "pwrite_device", "-1");
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_PWRITE_DEVICE, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "pwrite_device", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "pwrite_device", "-1");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "pwrite_device", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "pwrite_device",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  ret_v = ret.nbytes;
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "pwrite_device");
    fprintf (trace_fp, "%d", ret_v);
    trace_send_line (g);
  }

  return ret_v;
}

char *
guestfs_pread_device (guestfs_h *g,
                      const char *device,
                      int count,
                      int64_t offset,
                      size_t *size_r)
{
  struct guestfs_pread_device_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  struct guestfs_pread_device_ret ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  char *ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "pread_device", 12);
  if (device == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "pread_device", "device");
    return NULL;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "pread_device");
    fprintf (trace_fp, " \"%s\"", device);
    fprintf (trace_fp, " %d", count);
    fprintf (trace_fp, " %" PRIi64, offset);
    trace_send_line (g);
  }

  if (check_state (g, "pread_device") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "pread_device", "NULL");
    return NULL;
  }
  guestfs___set_busy (g);

  args.device = (char *) device;
  args.count = count;
  args.offset = offset;
  serial = guestfs___send (g, GUESTFS_PROC_PREAD_DEVICE,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_pread_device_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "pread_device", "NULL");
    return NULL;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs___recv (g, "pread_device", &hdr, &err,
        (xdrproc_t) xdr_guestfs_pread_device_ret, (char *) &ret);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "pread_device", "NULL");
    return NULL;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_PREAD_DEVICE, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "pread_device", "NULL");
    return NULL;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "pread_device", "NULL");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "pread_device", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "pread_device",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return NULL;
  }

  guestfs___end_busy (g);
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
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "pread_device");
    guestfs___print_BufferOut (trace_fp, ret_v, *size_r);
    trace_send_line (g);
  }

  return ret_v;
}

char *
guestfs_lvm_canonical_lv_name (guestfs_h *g,
                               const char *lvname)
{
  struct guestfs_lvm_canonical_lv_name_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  struct guestfs_lvm_canonical_lv_name_ret ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  char *ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "lvm_canonical_lv_name", 21);
  if (lvname == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "lvm_canonical_lv_name", "lvname");
    return NULL;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "lvm_canonical_lv_name");
    fprintf (trace_fp, " \"%s\"", lvname);
    trace_send_line (g);
  }

  if (check_state (g, "lvm_canonical_lv_name") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "lvm_canonical_lv_name", "NULL");
    return NULL;
  }
  guestfs___set_busy (g);

  args.lvname = (char *) lvname;
  serial = guestfs___send (g, GUESTFS_PROC_LVM_CANONICAL_LV_NAME,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_lvm_canonical_lv_name_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "lvm_canonical_lv_name", "NULL");
    return NULL;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs___recv (g, "lvm_canonical_lv_name", &hdr, &err,
        (xdrproc_t) xdr_guestfs_lvm_canonical_lv_name_ret, (char *) &ret);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "lvm_canonical_lv_name", "NULL");
    return NULL;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_LVM_CANONICAL_LV_NAME, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "lvm_canonical_lv_name", "NULL");
    return NULL;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "lvm_canonical_lv_name", "NULL");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "lvm_canonical_lv_name", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "lvm_canonical_lv_name",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return NULL;
  }

  guestfs___end_busy (g);
  ret_v = ret.lv; /* caller will free */
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "lvm_canonical_lv_name");
    fprintf (trace_fp, "\"%s\"", ret_v);
    trace_send_line (g);
  }

  return ret_v;
}

int
guestfs_mkfs_opts_argv (guestfs_h *g,
                        const char *fstype,
                        const char *device,
                        const struct guestfs_mkfs_opts_argv *optargs)
{
  struct guestfs_mkfs_opts_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "mkfs_opts", 9);
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

  if (optargs->bitmask & UINT64_C(0xfffffffffffffff0)) {
    error (g, "%s: unknown option in guestfs_%s_argv->bitmask (this can happen if a program is compiled against a newer version of libguestfs, then dynamically linked to an older version)",
           "mkfs_opts", "mkfs_opts");
    return -1;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "mkfs_opts");
    fprintf (trace_fp, " \"%s\"", fstype);
    fprintf (trace_fp, " \"%s\"", device);
    if (optargs->bitmask & GUESTFS_MKFS_OPTS_BLOCKSIZE_BITMASK)
      fprintf (trace_fp, " \"%s:%d\"", "blocksize", optargs->blocksize);
    if (optargs->bitmask & GUESTFS_MKFS_OPTS_FEATURES_BITMASK)
      fprintf (trace_fp, " \"%s:%s\"", "features", optargs->features);
    if (optargs->bitmask & GUESTFS_MKFS_OPTS_INODE_BITMASK)
      fprintf (trace_fp, " \"%s:%d\"", "inode", optargs->inode);
    if (optargs->bitmask & GUESTFS_MKFS_OPTS_SECTORSIZE_BITMASK)
      fprintf (trace_fp, " \"%s:%d\"", "sectorsize", optargs->sectorsize);
    trace_send_line (g);
  }

  if (check_state (g, "mkfs_opts") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mkfs_opts", "-1");
    return -1;
  }
  guestfs___set_busy (g);

  args.fstype = (char *) fstype;
  args.device = (char *) device;
  if ((optargs->bitmask & GUESTFS_MKFS_OPTS_BLOCKSIZE_BITMASK))
    args.blocksize = optargs->blocksize;
  else
    args.blocksize = 0;
  if ((optargs->bitmask & GUESTFS_MKFS_OPTS_FEATURES_BITMASK))
    args.features = (char *) optargs->features;
  else
    args.features = (char *) "";
  if ((optargs->bitmask & GUESTFS_MKFS_OPTS_INODE_BITMASK))
    args.inode = optargs->inode;
  else
    args.inode = 0;
  if ((optargs->bitmask & GUESTFS_MKFS_OPTS_SECTORSIZE_BITMASK))
    args.sectorsize = optargs->sectorsize;
  else
    args.sectorsize = 0;
  serial = guestfs___send (g, GUESTFS_PROC_MKFS_OPTS,
                           progress_hint, optargs->bitmask,
                           (xdrproc_t) xdr_guestfs_mkfs_opts_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mkfs_opts", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "mkfs_opts", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mkfs_opts", "-1");
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_MKFS_OPTS, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mkfs_opts", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mkfs_opts", "-1");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "mkfs_opts", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "mkfs_opts",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  ret_v = 0;
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "mkfs_opts");
    fprintf (trace_fp, "%d", ret_v);
    trace_send_line (g);
  }

  return ret_v;
}

char *
guestfs_getxattr (guestfs_h *g,
                  const char *path,
                  const char *name,
                  size_t *size_r)
{
  struct guestfs_getxattr_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  struct guestfs_getxattr_ret ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  char *ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "getxattr", 8);
  if (path == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "getxattr", "path");
    return NULL;
  }
  if (name == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "getxattr", "name");
    return NULL;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "getxattr");
    fprintf (trace_fp, " \"%s\"", path);
    fprintf (trace_fp, " \"%s\"", name);
    trace_send_line (g);
  }

  if (check_state (g, "getxattr") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "getxattr", "NULL");
    return NULL;
  }
  guestfs___set_busy (g);

  args.path = (char *) path;
  args.name = (char *) name;
  serial = guestfs___send (g, GUESTFS_PROC_GETXATTR,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_getxattr_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "getxattr", "NULL");
    return NULL;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs___recv (g, "getxattr", &hdr, &err,
        (xdrproc_t) xdr_guestfs_getxattr_ret, (char *) &ret);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "getxattr", "NULL");
    return NULL;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_GETXATTR, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "getxattr", "NULL");
    return NULL;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "getxattr", "NULL");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "getxattr", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "getxattr",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return NULL;
  }

  guestfs___end_busy (g);
  /* RBufferOut is tricky: If the buffer is zero-length, then
   * _val might be NULL here.  To make the API saner for
   * callers, we turn this case into a unique pointer (using
   * malloc(1)).
   */
  if (ret.xattr.xattr_len > 0) {
    *size_r = ret.xattr.xattr_len;
    ret_v = ret.xattr.xattr_val; /* caller will free */
  } else {
    free (ret.xattr.xattr_val);
    char *p = safe_malloc (g, 1);
    *size_r = ret.xattr.xattr_len;
    ret_v = p;
  }
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "getxattr");
    guestfs___print_BufferOut (trace_fp, ret_v, *size_r);
    trace_send_line (g);
  }

  return ret_v;
}

char *
guestfs_lgetxattr (guestfs_h *g,
                   const char *path,
                   const char *name,
                   size_t *size_r)
{
  struct guestfs_lgetxattr_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  struct guestfs_lgetxattr_ret ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  char *ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "lgetxattr", 9);
  if (path == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "lgetxattr", "path");
    return NULL;
  }
  if (name == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "lgetxattr", "name");
    return NULL;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "lgetxattr");
    fprintf (trace_fp, " \"%s\"", path);
    fprintf (trace_fp, " \"%s\"", name);
    trace_send_line (g);
  }

  if (check_state (g, "lgetxattr") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "lgetxattr", "NULL");
    return NULL;
  }
  guestfs___set_busy (g);

  args.path = (char *) path;
  args.name = (char *) name;
  serial = guestfs___send (g, GUESTFS_PROC_LGETXATTR,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_lgetxattr_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "lgetxattr", "NULL");
    return NULL;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs___recv (g, "lgetxattr", &hdr, &err,
        (xdrproc_t) xdr_guestfs_lgetxattr_ret, (char *) &ret);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "lgetxattr", "NULL");
    return NULL;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_LGETXATTR, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "lgetxattr", "NULL");
    return NULL;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "lgetxattr", "NULL");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "lgetxattr", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "lgetxattr",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return NULL;
  }

  guestfs___end_busy (g);
  /* RBufferOut is tricky: If the buffer is zero-length, then
   * _val might be NULL here.  To make the API saner for
   * callers, we turn this case into a unique pointer (using
   * malloc(1)).
   */
  if (ret.xattr.xattr_len > 0) {
    *size_r = ret.xattr.xattr_len;
    ret_v = ret.xattr.xattr_val; /* caller will free */
  } else {
    free (ret.xattr.xattr_val);
    char *p = safe_malloc (g, 1);
    *size_r = ret.xattr.xattr_len;
    ret_v = p;
  }
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "lgetxattr");
    guestfs___print_BufferOut (trace_fp, ret_v, *size_r);
    trace_send_line (g);
  }

  return ret_v;
}

int
guestfs_resize2fs_M (guestfs_h *g,
                     const char *device)
{
  struct guestfs_resize2fs_M_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "resize2fs_M", 11);
  if (device == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "resize2fs_M", "device");
    return -1;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "resize2fs_M");
    fprintf (trace_fp, " \"%s\"", device);
    trace_send_line (g);
  }

  if (check_state (g, "resize2fs_M") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "resize2fs_M", "-1");
    return -1;
  }
  guestfs___set_busy (g);

  args.device = (char *) device;
  serial = guestfs___send (g, GUESTFS_PROC_RESIZE2FS_M,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_resize2fs_M_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "resize2fs_M", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "resize2fs_M", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "resize2fs_M", "-1");
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_RESIZE2FS_M, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "resize2fs_M", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "resize2fs_M", "-1");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "resize2fs_M", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "resize2fs_M",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  ret_v = 0;
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "resize2fs_M");
    fprintf (trace_fp, "%d", ret_v);
    trace_send_line (g);
  }

  return ret_v;
}

int
guestfs_internal_autosync (guestfs_h *g)
{
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "internal_autosync", 17);
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "internal_autosync");
    trace_send_line (g);
  }

  if (check_state (g, "internal_autosync") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "internal_autosync", "-1");
    return -1;
  }
  guestfs___set_busy (g);

  serial = guestfs___send (g, GUESTFS_PROC_INTERNAL_AUTOSYNC, progress_hint, 0,
                           NULL, NULL);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "internal_autosync", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "internal_autosync", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "internal_autosync", "-1");
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_INTERNAL_AUTOSYNC, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "internal_autosync", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "internal_autosync", "-1");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "internal_autosync", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "internal_autosync",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  ret_v = 0;
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "internal_autosync");
    fprintf (trace_fp, "%d", ret_v);
    trace_send_line (g);
  }

  return ret_v;
}

int
guestfs_is_zero (guestfs_h *g,
                 const char *path)
{
  struct guestfs_is_zero_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  struct guestfs_is_zero_ret ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "is_zero", 7);
  if (path == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "is_zero", "path");
    return -1;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "is_zero");
    fprintf (trace_fp, " \"%s\"", path);
    trace_send_line (g);
  }

  if (check_state (g, "is_zero") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "is_zero", "-1");
    return -1;
  }
  guestfs___set_busy (g);

  args.path = (char *) path;
  serial = guestfs___send (g, GUESTFS_PROC_IS_ZERO,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_is_zero_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "is_zero", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs___recv (g, "is_zero", &hdr, &err,
        (xdrproc_t) xdr_guestfs_is_zero_ret, (char *) &ret);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "is_zero", "-1");
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_IS_ZERO, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "is_zero", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "is_zero", "-1");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "is_zero", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "is_zero",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  ret_v = ret.zeroflag;
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "is_zero");
    fprintf (trace_fp, "%d", ret_v);
    trace_send_line (g);
  }

  return ret_v;
}

int
guestfs_is_zero_device (guestfs_h *g,
                        const char *device)
{
  struct guestfs_is_zero_device_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  struct guestfs_is_zero_device_ret ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "is_zero_device", 14);
  if (device == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "is_zero_device", "device");
    return -1;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "is_zero_device");
    fprintf (trace_fp, " \"%s\"", device);
    trace_send_line (g);
  }

  if (check_state (g, "is_zero_device") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "is_zero_device", "-1");
    return -1;
  }
  guestfs___set_busy (g);

  args.device = (char *) device;
  serial = guestfs___send (g, GUESTFS_PROC_IS_ZERO_DEVICE,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_is_zero_device_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "is_zero_device", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs___recv (g, "is_zero_device", &hdr, &err,
        (xdrproc_t) xdr_guestfs_is_zero_device_ret, (char *) &ret);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "is_zero_device", "-1");
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_IS_ZERO_DEVICE, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "is_zero_device", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "is_zero_device", "-1");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "is_zero_device", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "is_zero_device",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  ret_v = ret.zeroflag;
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "is_zero_device");
    fprintf (trace_fp, "%d", ret_v);
    trace_send_line (g);
  }

  return ret_v;
}

char **
guestfs_list_9p (guestfs_h *g)
{
  guestfs_message_header hdr;
  guestfs_message_error err;
  struct guestfs_list_9p_ret ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  char **ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "list_9p", 7);
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "list_9p");
    trace_send_line (g);
  }

  if (check_state (g, "list_9p") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "list_9p", "NULL");
    return NULL;
  }
  guestfs___set_busy (g);

  serial = guestfs___send (g, GUESTFS_PROC_LIST_9P, progress_hint, 0,
                           NULL, NULL);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "list_9p", "NULL");
    return NULL;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs___recv (g, "list_9p", &hdr, &err,
        (xdrproc_t) xdr_guestfs_list_9p_ret, (char *) &ret);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "list_9p", "NULL");
    return NULL;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_LIST_9P, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "list_9p", "NULL");
    return NULL;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "list_9p", "NULL");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "list_9p", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "list_9p",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return NULL;
  }

  guestfs___end_busy (g);
  /* caller will free this, but we need to add a NULL entry */
  ret.mounttags.mounttags_val =
    safe_realloc (g, ret.mounttags.mounttags_val,
                  sizeof (char *) * (ret.mounttags.mounttags_len + 1));
  ret.mounttags.mounttags_val[ret.mounttags.mounttags_len] = NULL;
  ret_v = ret.mounttags.mounttags_val;
  if (trace_flag) {
    size_t i;

    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "list_9p");
    fputs ("[", trace_fp);
    for (i = 0; ret_v[i]; ++i) {
      if (i > 0) fputs (", ", trace_fp);
      fputs ("\"", trace_fp);
      fputs (ret_v[i], trace_fp);
      fputs ("\"", trace_fp);
    }
    fputs ("]", trace_fp);
    trace_send_line (g);
  }

  return ret_v;
}

int
guestfs_mount_9p_argv (guestfs_h *g,
                       const char *mounttag,
                       const char *mountpoint,
                       const struct guestfs_mount_9p_argv *optargs)
{
  struct guestfs_mount_9p_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "mount_9p", 8);
  if (mounttag == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "mount_9p", "mounttag");
    return -1;
  }
  if (mountpoint == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "mount_9p", "mountpoint");
    return -1;
  }
  if ((optargs->bitmask & GUESTFS_MOUNT_9P_OPTIONS_BITMASK) &&
      optargs->options == NULL) {
    error (g, "%s: %s: optional parameter cannot be NULL",
           "mount_9p", "options");
    return -1;
  }

  if (optargs->bitmask & UINT64_C(0xfffffffffffffffe)) {
    error (g, "%s: unknown option in guestfs_%s_argv->bitmask (this can happen if a program is compiled against a newer version of libguestfs, then dynamically linked to an older version)",
           "mount_9p", "mount_9p");
    return -1;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "mount_9p");
    fprintf (trace_fp, " \"%s\"", mounttag);
    fprintf (trace_fp, " \"%s\"", mountpoint);
    if (optargs->bitmask & GUESTFS_MOUNT_9P_OPTIONS_BITMASK)
      fprintf (trace_fp, " \"%s:%s\"", "options", optargs->options);
    trace_send_line (g);
  }

  if (check_state (g, "mount_9p") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mount_9p", "-1");
    return -1;
  }
  guestfs___set_busy (g);

  args.mounttag = (char *) mounttag;
  args.mountpoint = (char *) mountpoint;
  if ((optargs->bitmask & GUESTFS_MOUNT_9P_OPTIONS_BITMASK))
    args.options = (char *) optargs->options;
  else
    args.options = (char *) "";
  serial = guestfs___send (g, GUESTFS_PROC_MOUNT_9P,
                           progress_hint, optargs->bitmask,
                           (xdrproc_t) xdr_guestfs_mount_9p_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mount_9p", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "mount_9p", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mount_9p", "-1");
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_MOUNT_9P, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mount_9p", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mount_9p", "-1");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "mount_9p", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "mount_9p",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  ret_v = 0;
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "mount_9p");
    fprintf (trace_fp, "%d", ret_v);
    trace_send_line (g);
  }

  return ret_v;
}

char **
guestfs_list_dm_devices (guestfs_h *g)
{
  guestfs_message_header hdr;
  guestfs_message_error err;
  struct guestfs_list_dm_devices_ret ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  char **ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "list_dm_devices", 15);
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "list_dm_devices");
    trace_send_line (g);
  }

  if (check_state (g, "list_dm_devices") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "list_dm_devices", "NULL");
    return NULL;
  }
  guestfs___set_busy (g);

  serial = guestfs___send (g, GUESTFS_PROC_LIST_DM_DEVICES, progress_hint, 0,
                           NULL, NULL);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "list_dm_devices", "NULL");
    return NULL;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs___recv (g, "list_dm_devices", &hdr, &err,
        (xdrproc_t) xdr_guestfs_list_dm_devices_ret, (char *) &ret);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "list_dm_devices", "NULL");
    return NULL;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_LIST_DM_DEVICES, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "list_dm_devices", "NULL");
    return NULL;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "list_dm_devices", "NULL");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "list_dm_devices", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "list_dm_devices",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return NULL;
  }

  guestfs___end_busy (g);
  /* caller will free this, but we need to add a NULL entry */
  ret.devices.devices_val =
    safe_realloc (g, ret.devices.devices_val,
                  sizeof (char *) * (ret.devices.devices_len + 1));
  ret.devices.devices_val[ret.devices.devices_len] = NULL;
  ret_v = ret.devices.devices_val;
  if (trace_flag) {
    size_t i;

    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "list_dm_devices");
    fputs ("[", trace_fp);
    for (i = 0; ret_v[i]; ++i) {
      if (i > 0) fputs (", ", trace_fp);
      fputs ("\"", trace_fp);
      fputs (ret_v[i], trace_fp);
      fputs ("\"", trace_fp);
    }
    fputs ("]", trace_fp);
    trace_send_line (g);
  }

  return ret_v;
}

int
guestfs_ntfsresize_opts_argv (guestfs_h *g,
                              const char *device,
                              const struct guestfs_ntfsresize_opts_argv *optargs)
{
  struct guestfs_ntfsresize_opts_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "ntfsresize_opts", 15);
  if (device == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "ntfsresize_opts", "device");
    return -1;
  }

  if (optargs->bitmask & UINT64_C(0xfffffffffffffffc)) {
    error (g, "%s: unknown option in guestfs_%s_argv->bitmask (this can happen if a program is compiled against a newer version of libguestfs, then dynamically linked to an older version)",
           "ntfsresize_opts", "ntfsresize_opts");
    return -1;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "ntfsresize_opts");
    fprintf (trace_fp, " \"%s\"", device);
    if (optargs->bitmask & GUESTFS_NTFSRESIZE_OPTS_SIZE_BITMASK)
      fprintf (trace_fp, " \"%s:%" PRIi64 "\"", "size", optargs->size);
    if (optargs->bitmask & GUESTFS_NTFSRESIZE_OPTS_FORCE_BITMASK)
      fprintf (trace_fp, " \"%s:%s\"", "force", optargs->force ? "true" : "false");
    trace_send_line (g);
  }

  if (check_state (g, "ntfsresize_opts") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "ntfsresize_opts", "-1");
    return -1;
  }
  guestfs___set_busy (g);

  args.device = (char *) device;
  if ((optargs->bitmask & GUESTFS_NTFSRESIZE_OPTS_SIZE_BITMASK))
    args.size = optargs->size;
  else
    args.size = 0;
  if ((optargs->bitmask & GUESTFS_NTFSRESIZE_OPTS_FORCE_BITMASK))
    args.force = optargs->force;
  else
    args.force = 0;
  serial = guestfs___send (g, GUESTFS_PROC_NTFSRESIZE_OPTS,
                           progress_hint, optargs->bitmask,
                           (xdrproc_t) xdr_guestfs_ntfsresize_opts_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "ntfsresize_opts", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "ntfsresize_opts", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "ntfsresize_opts", "-1");
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_NTFSRESIZE_OPTS, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "ntfsresize_opts", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "ntfsresize_opts", "-1");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "ntfsresize_opts", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "ntfsresize_opts",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  ret_v = 0;
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "ntfsresize_opts");
    fprintf (trace_fp, "%d", ret_v);
    trace_send_line (g);
  }

  return ret_v;
}

int
guestfs_btrfs_filesystem_resize_argv (guestfs_h *g,
                                      const char *mountpoint,
                                      const struct guestfs_btrfs_filesystem_resize_argv *optargs)
{
  struct guestfs_btrfs_filesystem_resize_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "btrfs_filesystem_resize", 23);
  if (mountpoint == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "btrfs_filesystem_resize", "mountpoint");
    return -1;
  }

  if (optargs->bitmask & UINT64_C(0xfffffffffffffffe)) {
    error (g, "%s: unknown option in guestfs_%s_argv->bitmask (this can happen if a program is compiled against a newer version of libguestfs, then dynamically linked to an older version)",
           "btrfs_filesystem_resize", "btrfs_filesystem_resize");
    return -1;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "btrfs_filesystem_resize");
    fprintf (trace_fp, " \"%s\"", mountpoint);
    if (optargs->bitmask & GUESTFS_BTRFS_FILESYSTEM_RESIZE_SIZE_BITMASK)
      fprintf (trace_fp, " \"%s:%" PRIi64 "\"", "size", optargs->size);
    trace_send_line (g);
  }

  if (check_state (g, "btrfs_filesystem_resize") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "btrfs_filesystem_resize", "-1");
    return -1;
  }
  guestfs___set_busy (g);

  args.mountpoint = (char *) mountpoint;
  if ((optargs->bitmask & GUESTFS_BTRFS_FILESYSTEM_RESIZE_SIZE_BITMASK))
    args.size = optargs->size;
  else
    args.size = 0;
  serial = guestfs___send (g, GUESTFS_PROC_BTRFS_FILESYSTEM_RESIZE,
                           progress_hint, optargs->bitmask,
                           (xdrproc_t) xdr_guestfs_btrfs_filesystem_resize_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "btrfs_filesystem_resize", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "btrfs_filesystem_resize", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "btrfs_filesystem_resize", "-1");
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_BTRFS_FILESYSTEM_RESIZE, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "btrfs_filesystem_resize", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "btrfs_filesystem_resize", "-1");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "btrfs_filesystem_resize", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "btrfs_filesystem_resize",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  ret_v = 0;
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "btrfs_filesystem_resize");
    fprintf (trace_fp, "%d", ret_v);
    trace_send_line (g);
  }

  return ret_v;
}

int
guestfs_write_append (guestfs_h *g,
                      const char *path,
                      const char *content,
                      size_t content_size)
{
  struct guestfs_write_append_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "write_append", 12);
  if (path == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "write_append", "path");
    return -1;
  }
  if (content == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "write_append", "content");
    return -1;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "write_append");
    fprintf (trace_fp, " \"%s\"", path);
    fputc (' ', trace_fp);
    guestfs___print_BufferIn (trace_fp, content, content_size);
    trace_send_line (g);
  }

  if (check_state (g, "write_append") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "write_append", "-1");
    return -1;
  }
  guestfs___set_busy (g);

  args.path = (char *) path;
  /* Just catch grossly large sizes. XDR encoding will make this precise. */
  if (content_size >= GUESTFS_MESSAGE_MAX) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "write_append", "-1");
    error (g, "%s: size of input buffer too large", "write_append");
    guestfs___end_busy (g);
    return -1;
  }
  args.content.content_val = (char *) content;
  args.content.content_len = content_size;
  serial = guestfs___send (g, GUESTFS_PROC_WRITE_APPEND,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_write_append_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "write_append", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "write_append", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "write_append", "-1");
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_WRITE_APPEND, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "write_append", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "write_append", "-1");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "write_append", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "write_append",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  ret_v = 0;
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "write_append");
    fprintf (trace_fp, "%d", ret_v);
    trace_send_line (g);
  }

  return ret_v;
}

int
guestfs_compress_out_argv (guestfs_h *g,
                           const char *ctype,
                           const char *file,
                           const char *zfile,
                           const struct guestfs_compress_out_argv *optargs)
{
  struct guestfs_compress_out_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "compress_out", 12);
  if (ctype == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "compress_out", "ctype");
    return -1;
  }
  if (file == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "compress_out", "file");
    return -1;
  }
  if (zfile == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "compress_out", "zfile");
    return -1;
  }

  if (optargs->bitmask & UINT64_C(0xfffffffffffffffe)) {
    error (g, "%s: unknown option in guestfs_%s_argv->bitmask (this can happen if a program is compiled against a newer version of libguestfs, then dynamically linked to an older version)",
           "compress_out", "compress_out");
    return -1;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "compress_out");
    fprintf (trace_fp, " \"%s\"", ctype);
    fprintf (trace_fp, " \"%s\"", file);
    fprintf (trace_fp, " \"%s\"", zfile);
    if (optargs->bitmask & GUESTFS_COMPRESS_OUT_LEVEL_BITMASK)
      fprintf (trace_fp, " \"%s:%d\"", "level", optargs->level);
    trace_send_line (g);
  }

  if (check_state (g, "compress_out") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "compress_out", "-1");
    return -1;
  }
  guestfs___set_busy (g);

  args.ctype = (char *) ctype;
  args.file = (char *) file;
  if ((optargs->bitmask & GUESTFS_COMPRESS_OUT_LEVEL_BITMASK))
    args.level = optargs->level;
  else
    args.level = 0;
  serial = guestfs___send (g, GUESTFS_PROC_COMPRESS_OUT,
                           progress_hint, optargs->bitmask,
                           (xdrproc_t) xdr_guestfs_compress_out_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "compress_out", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "compress_out", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "compress_out", "-1");
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_COMPRESS_OUT, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "compress_out", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "compress_out", "-1");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "compress_out", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "compress_out",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return -1;
  }

  if (guestfs___recv_file (g, zfile) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "compress_out", "-1");
    return -1;
  }

  guestfs___end_busy (g);
  ret_v = 0;
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "compress_out");
    fprintf (trace_fp, "%d", ret_v);
    trace_send_line (g);
  }

  return ret_v;
}

int
guestfs_compress_device_out_argv (guestfs_h *g,
                                  const char *ctype,
                                  const char *device,
                                  const char *zdevice,
                                  const struct guestfs_compress_device_out_argv *optargs)
{
  struct guestfs_compress_device_out_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "compress_device_out", 19);
  if (ctype == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "compress_device_out", "ctype");
    return -1;
  }
  if (device == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "compress_device_out", "device");
    return -1;
  }
  if (zdevice == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "compress_device_out", "zdevice");
    return -1;
  }

  if (optargs->bitmask & UINT64_C(0xfffffffffffffffe)) {
    error (g, "%s: unknown option in guestfs_%s_argv->bitmask (this can happen if a program is compiled against a newer version of libguestfs, then dynamically linked to an older version)",
           "compress_device_out", "compress_device_out");
    return -1;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "compress_device_out");
    fprintf (trace_fp, " \"%s\"", ctype);
    fprintf (trace_fp, " \"%s\"", device);
    fprintf (trace_fp, " \"%s\"", zdevice);
    if (optargs->bitmask & GUESTFS_COMPRESS_DEVICE_OUT_LEVEL_BITMASK)
      fprintf (trace_fp, " \"%s:%d\"", "level", optargs->level);
    trace_send_line (g);
  }

  if (check_state (g, "compress_device_out") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "compress_device_out", "-1");
    return -1;
  }
  guestfs___set_busy (g);

  args.ctype = (char *) ctype;
  args.device = (char *) device;
  if ((optargs->bitmask & GUESTFS_COMPRESS_DEVICE_OUT_LEVEL_BITMASK))
    args.level = optargs->level;
  else
    args.level = 0;
  serial = guestfs___send (g, GUESTFS_PROC_COMPRESS_DEVICE_OUT,
                           progress_hint, optargs->bitmask,
                           (xdrproc_t) xdr_guestfs_compress_device_out_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "compress_device_out", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "compress_device_out", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "compress_device_out", "-1");
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_COMPRESS_DEVICE_OUT, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "compress_device_out", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "compress_device_out", "-1");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "compress_device_out", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "compress_device_out",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return -1;
  }

  if (guestfs___recv_file (g, zdevice) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "compress_device_out", "-1");
    return -1;
  }

  guestfs___end_busy (g);
  ret_v = 0;
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "compress_device_out");
    fprintf (trace_fp, "%d", ret_v);
    trace_send_line (g);
  }

  return ret_v;
}

int
guestfs_part_to_partnum (guestfs_h *g,
                         const char *partition)
{
  struct guestfs_part_to_partnum_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  struct guestfs_part_to_partnum_ret ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "part_to_partnum", 15);
  if (partition == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "part_to_partnum", "partition");
    return -1;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "part_to_partnum");
    fprintf (trace_fp, " \"%s\"", partition);
    trace_send_line (g);
  }

  if (check_state (g, "part_to_partnum") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "part_to_partnum", "-1");
    return -1;
  }
  guestfs___set_busy (g);

  args.partition = (char *) partition;
  serial = guestfs___send (g, GUESTFS_PROC_PART_TO_PARTNUM,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_part_to_partnum_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "part_to_partnum", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs___recv (g, "part_to_partnum", &hdr, &err,
        (xdrproc_t) xdr_guestfs_part_to_partnum_ret, (char *) &ret);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "part_to_partnum", "-1");
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_PART_TO_PARTNUM, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "part_to_partnum", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "part_to_partnum", "-1");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "part_to_partnum", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "part_to_partnum",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  ret_v = ret.partnum;
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "part_to_partnum");
    fprintf (trace_fp, "%d", ret_v);
    trace_send_line (g);
  }

  return ret_v;
}

int
guestfs_copy_device_to_device_argv (guestfs_h *g,
                                    const char *src,
                                    const char *dest,
                                    const struct guestfs_copy_device_to_device_argv *optargs)
{
  struct guestfs_copy_device_to_device_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "copy_device_to_device", 21);
  if (src == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "copy_device_to_device", "src");
    return -1;
  }
  if (dest == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "copy_device_to_device", "dest");
    return -1;
  }

  if (optargs->bitmask & UINT64_C(0xfffffffffffffff8)) {
    error (g, "%s: unknown option in guestfs_%s_argv->bitmask (this can happen if a program is compiled against a newer version of libguestfs, then dynamically linked to an older version)",
           "copy_device_to_device", "copy_device_to_device");
    return -1;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "copy_device_to_device");
    fprintf (trace_fp, " \"%s\"", src);
    fprintf (trace_fp, " \"%s\"", dest);
    if (optargs->bitmask & GUESTFS_COPY_DEVICE_TO_DEVICE_SRCOFFSET_BITMASK)
      fprintf (trace_fp, " \"%s:%" PRIi64 "\"", "srcoffset", optargs->srcoffset);
    if (optargs->bitmask & GUESTFS_COPY_DEVICE_TO_DEVICE_DESTOFFSET_BITMASK)
      fprintf (trace_fp, " \"%s:%" PRIi64 "\"", "destoffset", optargs->destoffset);
    if (optargs->bitmask & GUESTFS_COPY_DEVICE_TO_DEVICE_SIZE_BITMASK)
      fprintf (trace_fp, " \"%s:%" PRIi64 "\"", "size", optargs->size);
    trace_send_line (g);
  }

  if (check_state (g, "copy_device_to_device") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "copy_device_to_device", "-1");
    return -1;
  }
  guestfs___set_busy (g);

  args.src = (char *) src;
  args.dest = (char *) dest;
  if ((optargs->bitmask & GUESTFS_COPY_DEVICE_TO_DEVICE_SRCOFFSET_BITMASK))
    args.srcoffset = optargs->srcoffset;
  else
    args.srcoffset = 0;
  if ((optargs->bitmask & GUESTFS_COPY_DEVICE_TO_DEVICE_DESTOFFSET_BITMASK))
    args.destoffset = optargs->destoffset;
  else
    args.destoffset = 0;
  if ((optargs->bitmask & GUESTFS_COPY_DEVICE_TO_DEVICE_SIZE_BITMASK))
    args.size = optargs->size;
  else
    args.size = 0;
  serial = guestfs___send (g, GUESTFS_PROC_COPY_DEVICE_TO_DEVICE,
                           progress_hint, optargs->bitmask,
                           (xdrproc_t) xdr_guestfs_copy_device_to_device_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "copy_device_to_device", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "copy_device_to_device", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "copy_device_to_device", "-1");
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_COPY_DEVICE_TO_DEVICE, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "copy_device_to_device", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "copy_device_to_device", "-1");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "copy_device_to_device", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "copy_device_to_device",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  ret_v = 0;
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "copy_device_to_device");
    fprintf (trace_fp, "%d", ret_v);
    trace_send_line (g);
  }

  return ret_v;
}

int
guestfs_copy_device_to_file_argv (guestfs_h *g,
                                  const char *src,
                                  const char *dest,
                                  const struct guestfs_copy_device_to_file_argv *optargs)
{
  struct guestfs_copy_device_to_file_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "copy_device_to_file", 19);
  if (src == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "copy_device_to_file", "src");
    return -1;
  }
  if (dest == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "copy_device_to_file", "dest");
    return -1;
  }

  if (optargs->bitmask & UINT64_C(0xfffffffffffffff8)) {
    error (g, "%s: unknown option in guestfs_%s_argv->bitmask (this can happen if a program is compiled against a newer version of libguestfs, then dynamically linked to an older version)",
           "copy_device_to_file", "copy_device_to_file");
    return -1;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "copy_device_to_file");
    fprintf (trace_fp, " \"%s\"", src);
    fprintf (trace_fp, " \"%s\"", dest);
    if (optargs->bitmask & GUESTFS_COPY_DEVICE_TO_FILE_SRCOFFSET_BITMASK)
      fprintf (trace_fp, " \"%s:%" PRIi64 "\"", "srcoffset", optargs->srcoffset);
    if (optargs->bitmask & GUESTFS_COPY_DEVICE_TO_FILE_DESTOFFSET_BITMASK)
      fprintf (trace_fp, " \"%s:%" PRIi64 "\"", "destoffset", optargs->destoffset);
    if (optargs->bitmask & GUESTFS_COPY_DEVICE_TO_FILE_SIZE_BITMASK)
      fprintf (trace_fp, " \"%s:%" PRIi64 "\"", "size", optargs->size);
    trace_send_line (g);
  }

  if (check_state (g, "copy_device_to_file") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "copy_device_to_file", "-1");
    return -1;
  }
  guestfs___set_busy (g);

  args.src = (char *) src;
  args.dest = (char *) dest;
  if ((optargs->bitmask & GUESTFS_COPY_DEVICE_TO_FILE_SRCOFFSET_BITMASK))
    args.srcoffset = optargs->srcoffset;
  else
    args.srcoffset = 0;
  if ((optargs->bitmask & GUESTFS_COPY_DEVICE_TO_FILE_DESTOFFSET_BITMASK))
    args.destoffset = optargs->destoffset;
  else
    args.destoffset = 0;
  if ((optargs->bitmask & GUESTFS_COPY_DEVICE_TO_FILE_SIZE_BITMASK))
    args.size = optargs->size;
  else
    args.size = 0;
  serial = guestfs___send (g, GUESTFS_PROC_COPY_DEVICE_TO_FILE,
                           progress_hint, optargs->bitmask,
                           (xdrproc_t) xdr_guestfs_copy_device_to_file_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "copy_device_to_file", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "copy_device_to_file", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "copy_device_to_file", "-1");
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_COPY_DEVICE_TO_FILE, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "copy_device_to_file", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "copy_device_to_file", "-1");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "copy_device_to_file", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "copy_device_to_file",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  ret_v = 0;
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "copy_device_to_file");
    fprintf (trace_fp, "%d", ret_v);
    trace_send_line (g);
  }

  return ret_v;
}

int
guestfs_copy_file_to_device_argv (guestfs_h *g,
                                  const char *src,
                                  const char *dest,
                                  const struct guestfs_copy_file_to_device_argv *optargs)
{
  struct guestfs_copy_file_to_device_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
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

  if (optargs->bitmask & UINT64_C(0xfffffffffffffff8)) {
    error (g, "%s: unknown option in guestfs_%s_argv->bitmask (this can happen if a program is compiled against a newer version of libguestfs, then dynamically linked to an older version)",
           "copy_file_to_device", "copy_file_to_device");
    return -1;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "copy_file_to_device");
    fprintf (trace_fp, " \"%s\"", src);
    fprintf (trace_fp, " \"%s\"", dest);
    if (optargs->bitmask & GUESTFS_COPY_FILE_TO_DEVICE_SRCOFFSET_BITMASK)
      fprintf (trace_fp, " \"%s:%" PRIi64 "\"", "srcoffset", optargs->srcoffset);
    if (optargs->bitmask & GUESTFS_COPY_FILE_TO_DEVICE_DESTOFFSET_BITMASK)
      fprintf (trace_fp, " \"%s:%" PRIi64 "\"", "destoffset", optargs->destoffset);
    if (optargs->bitmask & GUESTFS_COPY_FILE_TO_DEVICE_SIZE_BITMASK)
      fprintf (trace_fp, " \"%s:%" PRIi64 "\"", "size", optargs->size);
    trace_send_line (g);
  }

  if (check_state (g, "copy_file_to_device") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "copy_file_to_device", "-1");
    return -1;
  }
  guestfs___set_busy (g);

  args.src = (char *) src;
  args.dest = (char *) dest;
  if ((optargs->bitmask & GUESTFS_COPY_FILE_TO_DEVICE_SRCOFFSET_BITMASK))
    args.srcoffset = optargs->srcoffset;
  else
    args.srcoffset = 0;
  if ((optargs->bitmask & GUESTFS_COPY_FILE_TO_DEVICE_DESTOFFSET_BITMASK))
    args.destoffset = optargs->destoffset;
  else
    args.destoffset = 0;
  if ((optargs->bitmask & GUESTFS_COPY_FILE_TO_DEVICE_SIZE_BITMASK))
    args.size = optargs->size;
  else
    args.size = 0;
  serial = guestfs___send (g, GUESTFS_PROC_COPY_FILE_TO_DEVICE,
                           progress_hint, optargs->bitmask,
                           (xdrproc_t) xdr_guestfs_copy_file_to_device_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "copy_file_to_device", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "copy_file_to_device", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "copy_file_to_device", "-1");
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_COPY_FILE_TO_DEVICE, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "copy_file_to_device", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "copy_file_to_device", "-1");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "copy_file_to_device", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "copy_file_to_device",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  ret_v = 0;
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "copy_file_to_device");
    fprintf (trace_fp, "%d", ret_v);
    trace_send_line (g);
  }

  return ret_v;
}

int
guestfs_copy_file_to_file_argv (guestfs_h *g,
                                const char *src,
                                const char *dest,
                                const struct guestfs_copy_file_to_file_argv *optargs)
{
  struct guestfs_copy_file_to_file_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
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

  if (optargs->bitmask & UINT64_C(0xfffffffffffffff8)) {
    error (g, "%s: unknown option in guestfs_%s_argv->bitmask (this can happen if a program is compiled against a newer version of libguestfs, then dynamically linked to an older version)",
           "copy_file_to_file", "copy_file_to_file");
    return -1;
  }

  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s", "copy_file_to_file");
    fprintf (trace_fp, " \"%s\"", src);
    fprintf (trace_fp, " \"%s\"", dest);
    if (optargs->bitmask & GUESTFS_COPY_FILE_TO_FILE_SRCOFFSET_BITMASK)
      fprintf (trace_fp, " \"%s:%" PRIi64 "\"", "srcoffset", optargs->srcoffset);
    if (optargs->bitmask & GUESTFS_COPY_FILE_TO_FILE_DESTOFFSET_BITMASK)
      fprintf (trace_fp, " \"%s:%" PRIi64 "\"", "destoffset", optargs->destoffset);
    if (optargs->bitmask & GUESTFS_COPY_FILE_TO_FILE_SIZE_BITMASK)
      fprintf (trace_fp, " \"%s:%" PRIi64 "\"", "size", optargs->size);
    trace_send_line (g);
  }

  if (check_state (g, "copy_file_to_file") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "copy_file_to_file", "-1");
    return -1;
  }
  guestfs___set_busy (g);

  args.src = (char *) src;
  args.dest = (char *) dest;
  if ((optargs->bitmask & GUESTFS_COPY_FILE_TO_FILE_SRCOFFSET_BITMASK))
    args.srcoffset = optargs->srcoffset;
  else
    args.srcoffset = 0;
  if ((optargs->bitmask & GUESTFS_COPY_FILE_TO_FILE_DESTOFFSET_BITMASK))
    args.destoffset = optargs->destoffset;
  else
    args.destoffset = 0;
  if ((optargs->bitmask & GUESTFS_COPY_FILE_TO_FILE_SIZE_BITMASK))
    args.size = optargs->size;
  else
    args.size = 0;
  serial = guestfs___send (g, GUESTFS_PROC_COPY_FILE_TO_FILE,
                           progress_hint, optargs->bitmask,
                           (xdrproc_t) xdr_guestfs_copy_file_to_file_args, (char *) &args);
  if (serial == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "copy_file_to_file", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "copy_file_to_file", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "copy_file_to_file", "-1");
    return -1;
  }

  if (check_reply_header (g, &hdr, GUESTFS_PROC_COPY_FILE_TO_FILE, serial) == -1) {
    guestfs___end_busy (g);
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "copy_file_to_file", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "copy_file_to_file", "-1");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "copy_file_to_file", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "copy_file_to_file",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    guestfs___end_busy (g);
    return -1;
  }

  guestfs___end_busy (g);
  ret_v = 0;
  if (trace_flag) {
    trace_fp = trace_open (g);
    fprintf (trace_fp, "%s = ", "copy_file_to_file");
    fprintf (trace_fp, "%d", ret_v);
    trace_send_line (g);
  }

  return ret_v;
}

/* Structure-freeing functions.  These rely on the fact that the
 * structure format is identical to the XDR format.  See note in
 * generator.ml.
 */

void
guestfs_free_int_bool (struct guestfs_int_bool *x)
{
  xdr_free ((xdrproc_t) xdr_guestfs_int_int_bool, (char *) x);
  free (x);
}

void
guestfs_free_int_bool_list (struct guestfs_int_bool_list *x)
{
  xdr_free ((xdrproc_t) xdr_guestfs_int_int_bool_list, (char *) x);
  free (x);
}

void
guestfs_free_lvm_pv (struct guestfs_lvm_pv *x)
{
  xdr_free ((xdrproc_t) xdr_guestfs_int_lvm_pv, (char *) x);
  free (x);
}

void
guestfs_free_lvm_pv_list (struct guestfs_lvm_pv_list *x)
{
  xdr_free ((xdrproc_t) xdr_guestfs_int_lvm_pv_list, (char *) x);
  free (x);
}

void
guestfs_free_lvm_vg (struct guestfs_lvm_vg *x)
{
  xdr_free ((xdrproc_t) xdr_guestfs_int_lvm_vg, (char *) x);
  free (x);
}

void
guestfs_free_lvm_vg_list (struct guestfs_lvm_vg_list *x)
{
  xdr_free ((xdrproc_t) xdr_guestfs_int_lvm_vg_list, (char *) x);
  free (x);
}

void
guestfs_free_lvm_lv (struct guestfs_lvm_lv *x)
{
  xdr_free ((xdrproc_t) xdr_guestfs_int_lvm_lv, (char *) x);
  free (x);
}

void
guestfs_free_lvm_lv_list (struct guestfs_lvm_lv_list *x)
{
  xdr_free ((xdrproc_t) xdr_guestfs_int_lvm_lv_list, (char *) x);
  free (x);
}

void
guestfs_free_stat (struct guestfs_stat *x)
{
  xdr_free ((xdrproc_t) xdr_guestfs_int_stat, (char *) x);
  free (x);
}

void
guestfs_free_stat_list (struct guestfs_stat_list *x)
{
  xdr_free ((xdrproc_t) xdr_guestfs_int_stat_list, (char *) x);
  free (x);
}

void
guestfs_free_statvfs (struct guestfs_statvfs *x)
{
  xdr_free ((xdrproc_t) xdr_guestfs_int_statvfs, (char *) x);
  free (x);
}

void
guestfs_free_statvfs_list (struct guestfs_statvfs_list *x)
{
  xdr_free ((xdrproc_t) xdr_guestfs_int_statvfs_list, (char *) x);
  free (x);
}

void
guestfs_free_dirent (struct guestfs_dirent *x)
{
  xdr_free ((xdrproc_t) xdr_guestfs_int_dirent, (char *) x);
  free (x);
}

void
guestfs_free_dirent_list (struct guestfs_dirent_list *x)
{
  xdr_free ((xdrproc_t) xdr_guestfs_int_dirent_list, (char *) x);
  free (x);
}

void
guestfs_free_version (struct guestfs_version *x)
{
  xdr_free ((xdrproc_t) xdr_guestfs_int_version, (char *) x);
  free (x);
}

void
guestfs_free_version_list (struct guestfs_version_list *x)
{
  xdr_free ((xdrproc_t) xdr_guestfs_int_version_list, (char *) x);
  free (x);
}

void
guestfs_free_xattr (struct guestfs_xattr *x)
{
  xdr_free ((xdrproc_t) xdr_guestfs_int_xattr, (char *) x);
  free (x);
}

void
guestfs_free_xattr_list (struct guestfs_xattr_list *x)
{
  xdr_free ((xdrproc_t) xdr_guestfs_int_xattr_list, (char *) x);
  free (x);
}

void
guestfs_free_inotify_event (struct guestfs_inotify_event *x)
{
  xdr_free ((xdrproc_t) xdr_guestfs_int_inotify_event, (char *) x);
  free (x);
}

void
guestfs_free_inotify_event_list (struct guestfs_inotify_event_list *x)
{
  xdr_free ((xdrproc_t) xdr_guestfs_int_inotify_event_list, (char *) x);
  free (x);
}

void
guestfs_free_partition (struct guestfs_partition *x)
{
  xdr_free ((xdrproc_t) xdr_guestfs_int_partition, (char *) x);
  free (x);
}

void
guestfs_free_partition_list (struct guestfs_partition_list *x)
{
  xdr_free ((xdrproc_t) xdr_guestfs_int_partition_list, (char *) x);
  free (x);
}

void
guestfs_free_application (struct guestfs_application *x)
{
  xdr_free ((xdrproc_t) xdr_guestfs_int_application, (char *) x);
  free (x);
}

void
guestfs_free_application_list (struct guestfs_application_list *x)
{
  xdr_free ((xdrproc_t) xdr_guestfs_int_application_list, (char *) x);
  free (x);
}

int
guestfs_add_domain (guestfs_h *g,
                    const char *dom,
                    ...)
{
  va_list optargs;

  va_start (optargs, dom);
  int r = guestfs_add_domain_va (g, dom, optargs);
  va_end (optargs);

  return r;
}

int
guestfs_add_domain_va (guestfs_h *g,
                       const char *dom,
                       va_list args)
{
  struct guestfs_add_domain_argv optargs_s;
  struct guestfs_add_domain_argv *optargs = &optargs_s;
  int i;

  optargs_s.bitmask = 0;

  while ((i = va_arg (args, int)) >= 0) {
    switch (i) {
    case GUESTFS_ADD_DOMAIN_LIBVIRTURI:
      optargs_s.libvirturi = va_arg (args, const char *);
      break;
    case GUESTFS_ADD_DOMAIN_READONLY:
      optargs_s.readonly = va_arg (args, int);
      break;
    case GUESTFS_ADD_DOMAIN_IFACE:
      optargs_s.iface = va_arg (args, const char *);
      break;
    case GUESTFS_ADD_DOMAIN_LIVE:
      optargs_s.live = va_arg (args, int);
      break;
    case GUESTFS_ADD_DOMAIN_ALLOWUUID:
      optargs_s.allowuuid = va_arg (args, int);
      break;
    case GUESTFS_ADD_DOMAIN_READONLYDISK:
      optargs_s.readonlydisk = va_arg (args, const char *);
      break;
    default:
      error (g, "%s: unknown option %d (this can happen if a program is compiled against a newer version of libguestfs, then dynamically linked to an older version)",
             "add_domain", i);
      return -1;
    }

    uint64_t i_mask = UINT64_C(1) << i;
    if (optargs_s.bitmask & i_mask) {
      error (g, "%s: same optional argument specified more than once",
             "add_domain");
      return -1;
    }
    optargs_s.bitmask |= i_mask;
  }

  return guestfs_add_domain_argv (g, dom, optargs);
}

int
guestfs_add_drive_opts (guestfs_h *g,
                        const char *filename,
                        ...)
{
  va_list optargs;

  va_start (optargs, filename);
  int r = guestfs_add_drive_opts_va (g, filename, optargs);
  va_end (optargs);

  return r;
}

int
guestfs_add_drive_opts_va (guestfs_h *g,
                           const char *filename,
                           va_list args)
{
  struct guestfs_add_drive_opts_argv optargs_s;
  struct guestfs_add_drive_opts_argv *optargs = &optargs_s;
  int i;

  optargs_s.bitmask = 0;

  while ((i = va_arg (args, int)) >= 0) {
    switch (i) {
    case GUESTFS_ADD_DRIVE_OPTS_READONLY:
      optargs_s.readonly = va_arg (args, int);
      break;
    case GUESTFS_ADD_DRIVE_OPTS_FORMAT:
      optargs_s.format = va_arg (args, const char *);
      break;
    case GUESTFS_ADD_DRIVE_OPTS_IFACE:
      optargs_s.iface = va_arg (args, const char *);
      break;
    case GUESTFS_ADD_DRIVE_OPTS_NAME:
      optargs_s.name = va_arg (args, const char *);
      break;
    default:
      error (g, "%s: unknown option %d (this can happen if a program is compiled against a newer version of libguestfs, then dynamically linked to an older version)",
             "add_drive_opts", i);
      return -1;
    }

    uint64_t i_mask = UINT64_C(1) << i;
    if (optargs_s.bitmask & i_mask) {
      error (g, "%s: same optional argument specified more than once",
             "add_drive_opts");
      return -1;
    }
    optargs_s.bitmask |= i_mask;
  }

  return guestfs_add_drive_opts_argv (g, filename, optargs);
}

int
guestfs_btrfs_filesystem_resize (guestfs_h *g,
                                 const char *mountpoint,
                                 ...)
{
  va_list optargs;

  va_start (optargs, mountpoint);
  int r = guestfs_btrfs_filesystem_resize_va (g, mountpoint, optargs);
  va_end (optargs);

  return r;
}

int
guestfs_btrfs_filesystem_resize_va (guestfs_h *g,
                                    const char *mountpoint,
                                    va_list args)
{
  struct guestfs_btrfs_filesystem_resize_argv optargs_s;
  struct guestfs_btrfs_filesystem_resize_argv *optargs = &optargs_s;
  int i;

  optargs_s.bitmask = 0;

  while ((i = va_arg (args, int)) >= 0) {
    switch (i) {
    case GUESTFS_BTRFS_FILESYSTEM_RESIZE_SIZE:
      optargs_s.size = va_arg (args, int64_t);
      break;
    default:
      error (g, "%s: unknown option %d (this can happen if a program is compiled against a newer version of libguestfs, then dynamically linked to an older version)",
             "btrfs_filesystem_resize", i);
      return -1;
    }

    uint64_t i_mask = UINT64_C(1) << i;
    if (optargs_s.bitmask & i_mask) {
      error (g, "%s: same optional argument specified more than once",
             "btrfs_filesystem_resize");
      return -1;
    }
    optargs_s.bitmask |= i_mask;
  }

  return guestfs_btrfs_filesystem_resize_argv (g, mountpoint, optargs);
}

int
guestfs_compress_device_out (guestfs_h *g,
                             const char *ctype,
                             const char *device,
                             const char *zdevice,
                             ...)
{
  va_list optargs;

  va_start (optargs, zdevice);
  int r = guestfs_compress_device_out_va (g, ctype, device, zdevice, optargs);
  va_end (optargs);

  return r;
}

int
guestfs_compress_device_out_va (guestfs_h *g,
                                const char *ctype,
                                const char *device,
                                const char *zdevice,
                                va_list args)
{
  struct guestfs_compress_device_out_argv optargs_s;
  struct guestfs_compress_device_out_argv *optargs = &optargs_s;
  int i;

  optargs_s.bitmask = 0;

  while ((i = va_arg (args, int)) >= 0) {
    switch (i) {
    case GUESTFS_COMPRESS_DEVICE_OUT_LEVEL:
      optargs_s.level = va_arg (args, int);
      break;
    default:
      error (g, "%s: unknown option %d (this can happen if a program is compiled against a newer version of libguestfs, then dynamically linked to an older version)",
             "compress_device_out", i);
      return -1;
    }

    uint64_t i_mask = UINT64_C(1) << i;
    if (optargs_s.bitmask & i_mask) {
      error (g, "%s: same optional argument specified more than once",
             "compress_device_out");
      return -1;
    }
    optargs_s.bitmask |= i_mask;
  }

  return guestfs_compress_device_out_argv (g, ctype, device, zdevice, optargs);
}

int
guestfs_compress_out (guestfs_h *g,
                      const char *ctype,
                      const char *file,
                      const char *zfile,
                      ...)
{
  va_list optargs;

  va_start (optargs, zfile);
  int r = guestfs_compress_out_va (g, ctype, file, zfile, optargs);
  va_end (optargs);

  return r;
}

int
guestfs_compress_out_va (guestfs_h *g,
                         const char *ctype,
                         const char *file,
                         const char *zfile,
                         va_list args)
{
  struct guestfs_compress_out_argv optargs_s;
  struct guestfs_compress_out_argv *optargs = &optargs_s;
  int i;

  optargs_s.bitmask = 0;

  while ((i = va_arg (args, int)) >= 0) {
    switch (i) {
    case GUESTFS_COMPRESS_OUT_LEVEL:
      optargs_s.level = va_arg (args, int);
      break;
    default:
      error (g, "%s: unknown option %d (this can happen if a program is compiled against a newer version of libguestfs, then dynamically linked to an older version)",
             "compress_out", i);
      return -1;
    }

    uint64_t i_mask = UINT64_C(1) << i;
    if (optargs_s.bitmask & i_mask) {
      error (g, "%s: same optional argument specified more than once",
             "compress_out");
      return -1;
    }
    optargs_s.bitmask |= i_mask;
  }

  return guestfs_compress_out_argv (g, ctype, file, zfile, optargs);
}

int
guestfs_copy_device_to_device (guestfs_h *g,
                               const char *src,
                               const char *dest,
                               ...)
{
  va_list optargs;

  va_start (optargs, dest);
  int r = guestfs_copy_device_to_device_va (g, src, dest, optargs);
  va_end (optargs);

  return r;
}

int
guestfs_copy_device_to_device_va (guestfs_h *g,
                                  const char *src,
                                  const char *dest,
                                  va_list args)
{
  struct guestfs_copy_device_to_device_argv optargs_s;
  struct guestfs_copy_device_to_device_argv *optargs = &optargs_s;
  int i;

  optargs_s.bitmask = 0;

  while ((i = va_arg (args, int)) >= 0) {
    switch (i) {
    case GUESTFS_COPY_DEVICE_TO_DEVICE_SRCOFFSET:
      optargs_s.srcoffset = va_arg (args, int64_t);
      break;
    case GUESTFS_COPY_DEVICE_TO_DEVICE_DESTOFFSET:
      optargs_s.destoffset = va_arg (args, int64_t);
      break;
    case GUESTFS_COPY_DEVICE_TO_DEVICE_SIZE:
      optargs_s.size = va_arg (args, int64_t);
      break;
    default:
      error (g, "%s: unknown option %d (this can happen if a program is compiled against a newer version of libguestfs, then dynamically linked to an older version)",
             "copy_device_to_device", i);
      return -1;
    }

    uint64_t i_mask = UINT64_C(1) << i;
    if (optargs_s.bitmask & i_mask) {
      error (g, "%s: same optional argument specified more than once",
             "copy_device_to_device");
      return -1;
    }
    optargs_s.bitmask |= i_mask;
  }

  return guestfs_copy_device_to_device_argv (g, src, dest, optargs);
}

int
guestfs_copy_device_to_file (guestfs_h *g,
                             const char *src,
                             const char *dest,
                             ...)
{
  va_list optargs;

  va_start (optargs, dest);
  int r = guestfs_copy_device_to_file_va (g, src, dest, optargs);
  va_end (optargs);

  return r;
}

int
guestfs_copy_device_to_file_va (guestfs_h *g,
                                const char *src,
                                const char *dest,
                                va_list args)
{
  struct guestfs_copy_device_to_file_argv optargs_s;
  struct guestfs_copy_device_to_file_argv *optargs = &optargs_s;
  int i;

  optargs_s.bitmask = 0;

  while ((i = va_arg (args, int)) >= 0) {
    switch (i) {
    case GUESTFS_COPY_DEVICE_TO_FILE_SRCOFFSET:
      optargs_s.srcoffset = va_arg (args, int64_t);
      break;
    case GUESTFS_COPY_DEVICE_TO_FILE_DESTOFFSET:
      optargs_s.destoffset = va_arg (args, int64_t);
      break;
    case GUESTFS_COPY_DEVICE_TO_FILE_SIZE:
      optargs_s.size = va_arg (args, int64_t);
      break;
    default:
      error (g, "%s: unknown option %d (this can happen if a program is compiled against a newer version of libguestfs, then dynamically linked to an older version)",
             "copy_device_to_file", i);
      return -1;
    }

    uint64_t i_mask = UINT64_C(1) << i;
    if (optargs_s.bitmask & i_mask) {
      error (g, "%s: same optional argument specified more than once",
             "copy_device_to_file");
      return -1;
    }
    optargs_s.bitmask |= i_mask;
  }

  return guestfs_copy_device_to_file_argv (g, src, dest, optargs);
}

int
guestfs_copy_file_to_device (guestfs_h *g,
                             const char *src,
                             const char *dest,
                             ...)
{
  va_list optargs;

  va_start (optargs, dest);
  int r = guestfs_copy_file_to_device_va (g, src, dest, optargs);
  va_end (optargs);

  return r;
}

int
guestfs_copy_file_to_device_va (guestfs_h *g,
                                const char *src,
                                const char *dest,
                                va_list args)
{
  struct guestfs_copy_file_to_device_argv optargs_s;
  struct guestfs_copy_file_to_device_argv *optargs = &optargs_s;
  int i;

  optargs_s.bitmask = 0;

  while ((i = va_arg (args, int)) >= 0) {
    switch (i) {
    case GUESTFS_COPY_FILE_TO_DEVICE_SRCOFFSET:
      optargs_s.srcoffset = va_arg (args, int64_t);
      break;
    case GUESTFS_COPY_FILE_TO_DEVICE_DESTOFFSET:
      optargs_s.destoffset = va_arg (args, int64_t);
      break;
    case GUESTFS_COPY_FILE_TO_DEVICE_SIZE:
      optargs_s.size = va_arg (args, int64_t);
      break;
    default:
      error (g, "%s: unknown option %d (this can happen if a program is compiled against a newer version of libguestfs, then dynamically linked to an older version)",
             "copy_file_to_device", i);
      return -1;
    }

    uint64_t i_mask = UINT64_C(1) << i;
    if (optargs_s.bitmask & i_mask) {
      error (g, "%s: same optional argument specified more than once",
             "copy_file_to_device");
      return -1;
    }
    optargs_s.bitmask |= i_mask;
  }

  return guestfs_copy_file_to_device_argv (g, src, dest, optargs);
}

int
guestfs_copy_file_to_file (guestfs_h *g,
                           const char *src,
                           const char *dest,
                           ...)
{
  va_list optargs;

  va_start (optargs, dest);
  int r = guestfs_copy_file_to_file_va (g, src, dest, optargs);
  va_end (optargs);

  return r;
}

int
guestfs_copy_file_to_file_va (guestfs_h *g,
                              const char *src,
                              const char *dest,
                              va_list args)
{
  struct guestfs_copy_file_to_file_argv optargs_s;
  struct guestfs_copy_file_to_file_argv *optargs = &optargs_s;
  int i;

  optargs_s.bitmask = 0;

  while ((i = va_arg (args, int)) >= 0) {
    switch (i) {
    case GUESTFS_COPY_FILE_TO_FILE_SRCOFFSET:
      optargs_s.srcoffset = va_arg (args, int64_t);
      break;
    case GUESTFS_COPY_FILE_TO_FILE_DESTOFFSET:
      optargs_s.destoffset = va_arg (args, int64_t);
      break;
    case GUESTFS_COPY_FILE_TO_FILE_SIZE:
      optargs_s.size = va_arg (args, int64_t);
      break;
    default:
      error (g, "%s: unknown option %d (this can happen if a program is compiled against a newer version of libguestfs, then dynamically linked to an older version)",
             "copy_file_to_file", i);
      return -1;
    }

    uint64_t i_mask = UINT64_C(1) << i;
    if (optargs_s.bitmask & i_mask) {
      error (g, "%s: same optional argument specified more than once",
             "copy_file_to_file");
      return -1;
    }
    optargs_s.bitmask |= i_mask;
  }

  return guestfs_copy_file_to_file_argv (g, src, dest, optargs);
}

char *
guestfs_inspect_get_icon (guestfs_h *g,
                          const char *root,
                          size_t *size_r,
                          ...)
{
  va_list optargs;

  va_start (optargs, size_r);
  char *r = guestfs_inspect_get_icon_va (g, root, size_r, optargs);
  va_end (optargs);

  return r;
}

char *
guestfs_inspect_get_icon_va (guestfs_h *g,
                             const char *root,
                             size_t *size_r,
                             va_list args)
{
  struct guestfs_inspect_get_icon_argv optargs_s;
  struct guestfs_inspect_get_icon_argv *optargs = &optargs_s;
  int i;

  optargs_s.bitmask = 0;

  while ((i = va_arg (args, int)) >= 0) {
    switch (i) {
    case GUESTFS_INSPECT_GET_ICON_FAVICON:
      optargs_s.favicon = va_arg (args, int);
      break;
    case GUESTFS_INSPECT_GET_ICON_HIGHQUALITY:
      optargs_s.highquality = va_arg (args, int);
      break;
    default:
      error (g, "%s: unknown option %d (this can happen if a program is compiled against a newer version of libguestfs, then dynamically linked to an older version)",
             "inspect_get_icon", i);
      return NULL;
    }

    uint64_t i_mask = UINT64_C(1) << i;
    if (optargs_s.bitmask & i_mask) {
      error (g, "%s: same optional argument specified more than once",
             "inspect_get_icon");
      return NULL;
    }
    optargs_s.bitmask |= i_mask;
  }

  return guestfs_inspect_get_icon_argv (g, root, size_r, optargs);
}

int
guestfs_mkfs_opts (guestfs_h *g,
                   const char *fstype,
                   const char *device,
                   ...)
{
  va_list optargs;

  va_start (optargs, device);
  int r = guestfs_mkfs_opts_va (g, fstype, device, optargs);
  va_end (optargs);

  return r;
}

int
guestfs_mkfs_opts_va (guestfs_h *g,
                      const char *fstype,
                      const char *device,
                      va_list args)
{
  struct guestfs_mkfs_opts_argv optargs_s;
  struct guestfs_mkfs_opts_argv *optargs = &optargs_s;
  int i;

  optargs_s.bitmask = 0;

  while ((i = va_arg (args, int)) >= 0) {
    switch (i) {
    case GUESTFS_MKFS_OPTS_BLOCKSIZE:
      optargs_s.blocksize = va_arg (args, int);
      break;
    case GUESTFS_MKFS_OPTS_FEATURES:
      optargs_s.features = va_arg (args, const char *);
      break;
    case GUESTFS_MKFS_OPTS_INODE:
      optargs_s.inode = va_arg (args, int);
      break;
    case GUESTFS_MKFS_OPTS_SECTORSIZE:
      optargs_s.sectorsize = va_arg (args, int);
      break;
    default:
      error (g, "%s: unknown option %d (this can happen if a program is compiled against a newer version of libguestfs, then dynamically linked to an older version)",
             "mkfs_opts", i);
      return -1;
    }

    uint64_t i_mask = UINT64_C(1) << i;
    if (optargs_s.bitmask & i_mask) {
      error (g, "%s: same optional argument specified more than once",
             "mkfs_opts");
      return -1;
    }
    optargs_s.bitmask |= i_mask;
  }

  return guestfs_mkfs_opts_argv (g, fstype, device, optargs);
}

int
guestfs_mount_9p (guestfs_h *g,
                  const char *mounttag,
                  const char *mountpoint,
                  ...)
{
  va_list optargs;

  va_start (optargs, mountpoint);
  int r = guestfs_mount_9p_va (g, mounttag, mountpoint, optargs);
  va_end (optargs);

  return r;
}

int
guestfs_mount_9p_va (guestfs_h *g,
                     const char *mounttag,
                     const char *mountpoint,
                     va_list args)
{
  struct guestfs_mount_9p_argv optargs_s;
  struct guestfs_mount_9p_argv *optargs = &optargs_s;
  int i;

  optargs_s.bitmask = 0;

  while ((i = va_arg (args, int)) >= 0) {
    switch (i) {
    case GUESTFS_MOUNT_9P_OPTIONS:
      optargs_s.options = va_arg (args, const char *);
      break;
    default:
      error (g, "%s: unknown option %d (this can happen if a program is compiled against a newer version of libguestfs, then dynamically linked to an older version)",
             "mount_9p", i);
      return -1;
    }

    uint64_t i_mask = UINT64_C(1) << i;
    if (optargs_s.bitmask & i_mask) {
      error (g, "%s: same optional argument specified more than once",
             "mount_9p");
      return -1;
    }
    optargs_s.bitmask |= i_mask;
  }

  return guestfs_mount_9p_argv (g, mounttag, mountpoint, optargs);
}

int
guestfs_ntfsresize_opts (guestfs_h *g,
                         const char *device,
                         ...)
{
  va_list optargs;

  va_start (optargs, device);
  int r = guestfs_ntfsresize_opts_va (g, device, optargs);
  va_end (optargs);

  return r;
}

int
guestfs_ntfsresize_opts_va (guestfs_h *g,
                            const char *device,
                            va_list args)
{
  struct guestfs_ntfsresize_opts_argv optargs_s;
  struct guestfs_ntfsresize_opts_argv *optargs = &optargs_s;
  int i;

  optargs_s.bitmask = 0;

  while ((i = va_arg (args, int)) >= 0) {
    switch (i) {
    case GUESTFS_NTFSRESIZE_OPTS_SIZE:
      optargs_s.size = va_arg (args, int64_t);
      break;
    case GUESTFS_NTFSRESIZE_OPTS_FORCE:
      optargs_s.force = va_arg (args, int);
      break;
    default:
      error (g, "%s: unknown option %d (this can happen if a program is compiled against a newer version of libguestfs, then dynamically linked to an older version)",
             "ntfsresize_opts", i);
      return -1;
    }

    uint64_t i_mask = UINT64_C(1) << i;
    if (optargs_s.bitmask & i_mask) {
      error (g, "%s: same optional argument specified more than once",
             "ntfsresize_opts");
      return -1;
    }
    optargs_s.bitmask |= i_mask;
  }

  return guestfs_ntfsresize_opts_argv (g, device, optargs);
}

