/* libguestfs generated file
 * WARNING: THIS FILE IS GENERATED FROM:
 *   generator/ *.ml
 * ANY CHANGES YOU MAKE TO THIS FILE WILL BE LOST.
 *
 * Copyright (C) 2009-2013 Red Hat Inc.
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

#include "guestfs.h"
#include "guestfs-internal.h"
#include "guestfs-internal-actions.h"
#include "guestfs_protocol.h"
#include "errnostring.h"

GUESTFS_DLL_PUBLIC int64_t
guestfs_internal_test_rint64 (guestfs_h *g,
                              const char *val)
{
  int trace_flag = g->trace;
  FILE *trace_fp;
  int64_t r;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "internal_test_rint64", 20);
  if (val == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "internal_test_rint64", "val");
    return -1;
  }

  if (trace_flag) {
    trace_fp = guestfs___trace_open (g);
    fprintf (trace_fp, "%s", "internal_test_rint64");
    fprintf (trace_fp, " \"%s\"", val);
    guestfs___trace_send_line (g);
  }

  r = guestfs__internal_test_rint64 (g, val);

  if (r != -1) {
    if (trace_flag) {
      trace_fp = guestfs___trace_open (g);
      fprintf (trace_fp, "%s = ", "internal_test_rint64");
      fprintf (trace_fp, "%" PRIi64, r);
      guestfs___trace_send_line (g);
    }

  } else {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "internal_test_rint64", "-1");
  }

  return r;
}

GUESTFS_DLL_PUBLIC const char *
guestfs_internal_test_rconstoptstring (guestfs_h *g,
                                       const char *val)
{
  int trace_flag = g->trace;
  FILE *trace_fp;
  const char *r;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "internal_test_rconstoptstring", 29);
  if (val == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "internal_test_rconstoptstring", "val");
    return NULL;
  }

  if (trace_flag) {
    trace_fp = guestfs___trace_open (g);
    fprintf (trace_fp, "%s", "internal_test_rconstoptstring");
    fprintf (trace_fp, " \"%s\"", val);
    guestfs___trace_send_line (g);
  }

  r = guestfs__internal_test_rconstoptstring (g, val);

  if (trace_flag) {
    trace_fp = guestfs___trace_open (g);
    fprintf (trace_fp, "%s = ", "internal_test_rconstoptstring");
    fprintf (trace_fp, "\"%s\"", r != NULL ? r : "NULL");
    guestfs___trace_send_line (g);
  }


  return r;
}

GUESTFS_DLL_PUBLIC char *
guestfs_internal_test_rstringerr (guestfs_h *g)
{
  int trace_flag = g->trace;
  FILE *trace_fp;
  char *r;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "internal_test_rstringerr", 24);
  if (trace_flag) {
    trace_fp = guestfs___trace_open (g);
    fprintf (trace_fp, "%s", "internal_test_rstringerr");
    guestfs___trace_send_line (g);
  }

  r = guestfs__internal_test_rstringerr (g);

  if (r != NULL) {
    if (trace_flag) {
      trace_fp = guestfs___trace_open (g);
      fprintf (trace_fp, "%s = ", "internal_test_rstringerr");
      fprintf (trace_fp, "\"%s\"", r);
      guestfs___trace_send_line (g);
    }

  } else {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "internal_test_rstringerr", "NULL");
  }

  return r;
}

GUESTFS_DLL_PUBLIC struct guestfs_lvm_pv_list *
guestfs_internal_test_rstructlist (guestfs_h *g,
                                   const char *val)
{
  int trace_flag = g->trace;
  FILE *trace_fp;
  struct guestfs_lvm_pv_list *r;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "internal_test_rstructlist", 25);
  if (val == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "internal_test_rstructlist", "val");
    return NULL;
  }

  if (trace_flag) {
    trace_fp = guestfs___trace_open (g);
    fprintf (trace_fp, "%s", "internal_test_rstructlist");
    fprintf (trace_fp, " \"%s\"", val);
    guestfs___trace_send_line (g);
  }

  r = guestfs__internal_test_rstructlist (g, val);

  if (r != NULL) {
    if (trace_flag) {
      trace_fp = guestfs___trace_open (g);
      fprintf (trace_fp, "%s = ", "internal_test_rstructlist");
      fprintf (trace_fp, "<struct guestfs_lvm_pv_list *>");
      guestfs___trace_send_line (g);
    }

  } else {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "internal_test_rstructlist", "NULL");
  }

  return r;
}

GUESTFS_DLL_PUBLIC struct guestfs_lvm_pv_list *
guestfs_internal_test_rstructlisterr (guestfs_h *g)
{
  int trace_flag = g->trace;
  FILE *trace_fp;
  struct guestfs_lvm_pv_list *r;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "internal_test_rstructlisterr", 28);
  if (trace_flag) {
    trace_fp = guestfs___trace_open (g);
    fprintf (trace_fp, "%s", "internal_test_rstructlisterr");
    guestfs___trace_send_line (g);
  }

  r = guestfs__internal_test_rstructlisterr (g);

  if (r != NULL) {
    if (trace_flag) {
      trace_fp = guestfs___trace_open (g);
      fprintf (trace_fp, "%s = ", "internal_test_rstructlisterr");
      fprintf (trace_fp, "<struct guestfs_lvm_pv_list *>");
      guestfs___trace_send_line (g);
    }

  } else {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "internal_test_rstructlisterr", "NULL");
  }

  return r;
}

GUESTFS_DLL_PUBLIC char *
guestfs_internal_test_rbufferouterr (guestfs_h *g,
                                     size_t *size_r)
{
  int trace_flag = g->trace;
  FILE *trace_fp;
  char *r;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "internal_test_rbufferouterr", 27);
  if (trace_flag) {
    trace_fp = guestfs___trace_open (g);
    fprintf (trace_fp, "%s", "internal_test_rbufferouterr");
    guestfs___trace_send_line (g);
  }

  r = guestfs__internal_test_rbufferouterr (g, size_r);

  if (r != NULL) {
    if (trace_flag) {
      trace_fp = guestfs___trace_open (g);
      fprintf (trace_fp, "%s = ", "internal_test_rbufferouterr");
      guestfs___print_BufferOut (trace_fp, r, *size_r);
      guestfs___trace_send_line (g);
    }

  } else {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "internal_test_rbufferouterr", "NULL");
  }

  return r;
}

GUESTFS_DLL_PUBLIC int
guestfs_config (guestfs_h *g,
                const char *qemuparam,
                const char *qemuvalue)
{
  int trace_flag = g->trace;
  FILE *trace_fp;
  int r;

  if (g->state != CONFIG) {
    error (g, "%s: this function can only be called in the config state",
              "config");
    return -1;
  }
  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "config", 6);
  if (qemuparam == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "config", "qemuparam");
    return -1;
  }

  if (trace_flag) {
    trace_fp = guestfs___trace_open (g);
    fprintf (trace_fp, "%s", "config");
    fprintf (trace_fp, " \"%s\"", qemuparam);
    if (qemuvalue) fprintf (trace_fp, " \"%s\"", qemuvalue);
    else fprintf (trace_fp, " null");
    guestfs___trace_send_line (g);
  }

  r = guestfs__config (g, qemuparam, qemuvalue);

  if (r != -1) {
    if (trace_flag) {
      trace_fp = guestfs___trace_open (g);
      fprintf (trace_fp, "%s = ", "config");
      fprintf (trace_fp, "%d", r);
      guestfs___trace_send_line (g);
    }

  } else {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "config", "-1");
  }

  return r;
}

GUESTFS_DLL_PUBLIC const char *
guestfs_get_qemu (guestfs_h *g)
{
  int trace_flag = g->trace;
  FILE *trace_fp;
  const char *r;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "get_qemu", 8);
  if (trace_flag) {
    trace_fp = guestfs___trace_open (g);
    fprintf (trace_fp, "%s", "get_qemu");
    guestfs___trace_send_line (g);
  }

  r = guestfs__get_qemu (g);

  if (r != NULL) {
    if (trace_flag) {
      trace_fp = guestfs___trace_open (g);
      fprintf (trace_fp, "%s = ", "get_qemu");
      fprintf (trace_fp, "\"%s\"", r);
      guestfs___trace_send_line (g);
    }

  } else {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "get_qemu", "NULL");
  }

  return r;
}

GUESTFS_DLL_PUBLIC int
guestfs_set_autosync (guestfs_h *g,
                      int autosync)
{
  int trace_flag = g->trace;
  FILE *trace_fp;
  int r;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "set_autosync", 12);
  if (trace_flag) {
    trace_fp = guestfs___trace_open (g);
    fprintf (trace_fp, "%s", "set_autosync");
    fputs (autosync ? " true" : " false", trace_fp);
    guestfs___trace_send_line (g);
  }

  r = guestfs__set_autosync (g, autosync);

  if (r != -1) {
    if (trace_flag) {
      trace_fp = guestfs___trace_open (g);
      fprintf (trace_fp, "%s = ", "set_autosync");
      fprintf (trace_fp, "%d", r);
      guestfs___trace_send_line (g);
    }

  } else {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "set_autosync", "-1");
  }

  return r;
}

GUESTFS_DLL_PUBLIC int
guestfs_set_verbose (guestfs_h *g,
                     int verbose)
{
  int trace_flag = g->trace;
  FILE *trace_fp;
  int r;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "set_verbose", 11);
  if (trace_flag) {
    trace_fp = guestfs___trace_open (g);
    fprintf (trace_fp, "%s", "set_verbose");
    fputs (verbose ? " true" : " false", trace_fp);
    guestfs___trace_send_line (g);
  }

  r = guestfs__set_verbose (g, verbose);

  if (r != -1) {
    if (trace_flag) {
      trace_fp = guestfs___trace_open (g);
      fprintf (trace_fp, "%s = ", "set_verbose");
      fprintf (trace_fp, "%d", r);
      guestfs___trace_send_line (g);
    }

  } else {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "set_verbose", "-1");
  }

  return r;
}

GUESTFS_DLL_PUBLIC int
guestfs_get_verbose (guestfs_h *g)
{
  int trace_flag = g->trace;
  FILE *trace_fp;
  int r;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "get_verbose", 11);
  if (trace_flag) {
    trace_fp = guestfs___trace_open (g);
    fprintf (trace_fp, "%s", "get_verbose");
    guestfs___trace_send_line (g);
  }

  r = guestfs__get_verbose (g);

  if (r != -1) {
    if (trace_flag) {
      trace_fp = guestfs___trace_open (g);
      fprintf (trace_fp, "%s = ", "get_verbose");
      fprintf (trace_fp, "%d", r);
      guestfs___trace_send_line (g);
    }

  } else {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "get_verbose", "-1");
  }

  return r;
}

GUESTFS_DLL_PUBLIC int
guestfs_get_state (guestfs_h *g)
{
  int trace_flag = g->trace;
  FILE *trace_fp;
  int r;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "get_state", 9);
  if (trace_flag) {
    trace_fp = guestfs___trace_open (g);
    fprintf (trace_fp, "%s", "get_state");
    guestfs___trace_send_line (g);
  }

  r = guestfs__get_state (g);

  if (r != -1) {
    if (trace_flag) {
      trace_fp = guestfs___trace_open (g);
      fprintf (trace_fp, "%s = ", "get_state");
      fprintf (trace_fp, "%d", r);
      guestfs___trace_send_line (g);
    }

  } else {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "get_state", "-1");
  }

  return r;
}

GUESTFS_DLL_PUBLIC int
guestfs_get_network (guestfs_h *g)
{
  int trace_flag = g->trace;
  FILE *trace_fp;
  int r;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "get_network", 11);
  if (trace_flag) {
    trace_fp = guestfs___trace_open (g);
    fprintf (trace_fp, "%s", "get_network");
    guestfs___trace_send_line (g);
  }

  r = guestfs__get_network (g);

  if (r != -1) {
    if (trace_flag) {
      trace_fp = guestfs___trace_open (g);
      fprintf (trace_fp, "%s = ", "get_network");
      fprintf (trace_fp, "%d", r);
      guestfs___trace_send_line (g);
    }

  } else {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "get_network", "-1");
  }

  return r;
}

GUESTFS_DLL_PUBLIC char **
guestfs_debug_drives (guestfs_h *g)
{
  int trace_flag = g->trace;
  FILE *trace_fp;
  char **r;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "debug_drives", 12);
  if (trace_flag) {
    trace_fp = guestfs___trace_open (g);
    fprintf (trace_fp, "%s", "debug_drives");
    guestfs___trace_send_line (g);
  }

  r = guestfs__debug_drives (g);

  if (r != NULL) {
    if (trace_flag) {
      size_t i;

      trace_fp = guestfs___trace_open (g);
      fprintf (trace_fp, "%s = ", "debug_drives");
      fputs ("[", trace_fp);
      for (i = 0; r[i]; ++i) {
        if (i > 0) fputs (", ", trace_fp);
        fputs ("\"", trace_fp);
        fputs (r[i], trace_fp);
        fputs ("\"", trace_fp);
      }
      fputs ("]", trace_fp);
      guestfs___trace_send_line (g);
    }

  } else {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "debug_drives", "NULL");
  }

  return r;
}

GUESTFS_DLL_PUBLIC struct guestfs_application2_list *
guestfs_inspect_list_applications2 (guestfs_h *g,
                                    const char *root)
{
  int trace_flag = g->trace;
  FILE *trace_fp;
  struct guestfs_application2_list *r;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "inspect_list_applications2", 26);
  if (root == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "inspect_list_applications2", "root");
    return NULL;
  }

  if (trace_flag) {
    trace_fp = guestfs___trace_open (g);
    fprintf (trace_fp, "%s", "inspect_list_applications2");
    fprintf (trace_fp, " \"%s\"", root);
    guestfs___trace_send_line (g);
  }

  r = guestfs__inspect_list_applications2 (g, root);

  if (r != NULL) {
    if (trace_flag) {
      trace_fp = guestfs___trace_open (g);
      fprintf (trace_fp, "%s = ", "inspect_list_applications2");
      fprintf (trace_fp, "<struct guestfs_application2_list *>");
      guestfs___trace_send_line (g);
    }

  } else {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "inspect_list_applications2", "NULL");
  }

  return r;
}

GUESTFS_DLL_PUBLIC int
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
    trace_fp = guestfs___trace_open (g);
    fprintf (trace_fp, "%s", "inspect_is_netinst");
    fprintf (trace_fp, " \"%s\"", root);
    guestfs___trace_send_line (g);
  }

  r = guestfs__inspect_is_netinst (g, root);

  if (r != -1) {
    if (trace_flag) {
      trace_fp = guestfs___trace_open (g);
      fprintf (trace_fp, "%s = ", "inspect_is_netinst");
      fprintf (trace_fp, "%d", r);
      guestfs___trace_send_line (g);
    }

  } else {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "inspect_is_netinst", "-1");
  }

  return r;
}

GUESTFS_DLL_PUBLIC char *
guestfs_inspect_get_icon_argv (guestfs_h *g,
                               const char *root,
                               size_t *size_r,
                               const struct guestfs_inspect_get_icon_argv *optargs)
{
  struct guestfs_inspect_get_icon_argv optargs_null;
  if (!optargs) {
    optargs_null.bitmask = 0;
    optargs = &optargs_null;
  }

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
    trace_fp = guestfs___trace_open (g);
    fprintf (trace_fp, "%s", "inspect_get_icon");
    fprintf (trace_fp, " \"%s\"", root);
    if (optargs->bitmask & GUESTFS_INSPECT_GET_ICON_FAVICON_BITMASK) {
      fprintf (trace_fp, " \"%s:%s\"", "favicon", optargs->favicon ? "true" : "false");
    }
    if (optargs->bitmask & GUESTFS_INSPECT_GET_ICON_HIGHQUALITY_BITMASK) {
      fprintf (trace_fp, " \"%s:%s\"", "highquality", optargs->highquality ? "true" : "false");
    }
    guestfs___trace_send_line (g);
  }

  r = guestfs__inspect_get_icon (g, root, size_r, optargs);

  if (r != NULL) {
    if (trace_flag) {
      trace_fp = guestfs___trace_open (g);
      fprintf (trace_fp, "%s = ", "inspect_get_icon");
      guestfs___print_BufferOut (trace_fp, r, *size_r);
      guestfs___trace_send_line (g);
    }

  } else {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "inspect_get_icon", "NULL");
  }

  return r;
}

GUESTFS_DLL_PUBLIC int
guestfs_mount_local_run (guestfs_h *g)
{
  int trace_flag = g->trace;
  FILE *trace_fp;
  int r;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "mount_local_run", 15);
  if (trace_flag) {
    trace_fp = guestfs___trace_open (g);
    fprintf (trace_fp, "%s", "mount_local_run");
    guestfs___trace_send_line (g);
  }

  r = guestfs__mount_local_run (g);

  if (r != -1) {
    if (trace_flag) {
      trace_fp = guestfs___trace_open (g);
      fprintf (trace_fp, "%s = ", "mount_local_run");
      fprintf (trace_fp, "%d", r);
      guestfs___trace_send_line (g);
    }

  } else {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mount_local_run", "-1");
  }

  return r;
}

GUESTFS_DLL_PUBLIC char *
guestfs_cat (guestfs_h *g,
             const char *path)
{
  int trace_flag = g->trace;
  FILE *trace_fp;
  char *r;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "cat", 3);
  if (path == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "cat", "path");
    return NULL;
  }

  if (trace_flag) {
    trace_fp = guestfs___trace_open (g);
    fprintf (trace_fp, "%s", "cat");
    fprintf (trace_fp, " \"%s\"", path);
    guestfs___trace_send_line (g);
  }

  r = guestfs__cat (g, path);

  if (r != NULL) {
    if (trace_flag) {
      trace_fp = guestfs___trace_open (g);
      fprintf (trace_fp, "%s = ", "cat");
      fprintf (trace_fp, "\"%s\"", r);
      guestfs___trace_send_line (g);
    }

  } else {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "cat", "NULL");
  }

  return r;
}

GUESTFS_DLL_PUBLIC struct guestfs_stat_list *
guestfs_lstatlist (guestfs_h *g,
                   const char *path,
                   char *const *names)
{
  int trace_flag = g->trace;
  FILE *trace_fp;
  struct guestfs_stat_list *r;

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

    trace_fp = guestfs___trace_open (g);
    fprintf (trace_fp, "%s", "lstatlist");
    fprintf (trace_fp, " \"%s\"", path);
    fputc (' ', trace_fp);
    fputc ('"', trace_fp);
    for (i = 0; names[i]; ++i) {
      if (i > 0) fputc (' ', trace_fp);
      fputs (names[i], trace_fp);
    }
    fputc ('"', trace_fp);
    guestfs___trace_send_line (g);
  }

  r = guestfs__lstatlist (g, path, names);

  if (r != NULL) {
    if (trace_flag) {
      trace_fp = guestfs___trace_open (g);
      fprintf (trace_fp, "%s = ", "lstatlist");
      fprintf (trace_fp, "<struct guestfs_stat_list *>");
      guestfs___trace_send_line (g);
    }

  } else {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "lstatlist", "NULL");
  }

  return r;
}

GUESTFS_DLL_PUBLIC char *
guestfs_get_libvirt_requested_credential_prompt (guestfs_h *g,
                                                 int index)
{
  int trace_flag = g->trace;
  FILE *trace_fp;
  char *r;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "get_libvirt_requested_credential_prompt", 39);
  if (trace_flag) {
    trace_fp = guestfs___trace_open (g);
    fprintf (trace_fp, "%s", "get_libvirt_requested_credential_prompt");
    fprintf (trace_fp, " %d", index);
    guestfs___trace_send_line (g);
  }

  r = guestfs__get_libvirt_requested_credential_prompt (g, index);

  if (r != NULL) {
    if (trace_flag) {
      trace_fp = guestfs___trace_open (g);
      fprintf (trace_fp, "%s = ", "get_libvirt_requested_credential_prompt");
      fprintf (trace_fp, "\"%s\"", r);
      guestfs___trace_send_line (g);
    }

  } else {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "get_libvirt_requested_credential_prompt", "NULL");
  }

  return r;
}

GUESTFS_DLL_PUBLIC int
guestfs_mount (guestfs_h *g,
               const char *mountable,
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
  if (mountable == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "mount", "mountable");
    return -1;
  }
  if (mountpoint == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "mount", "mountpoint");
    return -1;
  }

  if (trace_flag) {
    trace_fp = guestfs___trace_open (g);
    fprintf (trace_fp, "%s", "mount");
    fprintf (trace_fp, " \"%s\"", mountable);
    fprintf (trace_fp, " \"%s\"", mountpoint);
    guestfs___trace_send_line (g);
  }

  if (guestfs___check_appliance_up (g, "mount") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mount", "-1");
    return -1;
  }

  args.mountable = (char *) mountable;
  args.mountpoint = (char *) mountpoint;
  serial = guestfs___send (g, GUESTFS_PROC_MOUNT,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_mount_args, (char *) &args);
  if (serial == -1) {
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
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mount", "-1");
    return -1;
  }

  if (guestfs___check_reply_header (g, &hdr, GUESTFS_PROC_MOUNT, serial) == -1) {
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
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    trace_fp = guestfs___trace_open (g);
    fprintf (trace_fp, "%s = ", "mount");
    fprintf (trace_fp, "%d", ret_v);
    guestfs___trace_send_line (g);
  }

  return ret_v;
}

GUESTFS_DLL_PUBLIC int
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
    trace_fp = guestfs___trace_open (g);
    fprintf (trace_fp, "%s", "touch");
    fprintf (trace_fp, " \"%s\"", path);
    guestfs___trace_send_line (g);
  }

  if (guestfs___check_appliance_up (g, "touch") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "touch", "-1");
    return -1;
  }

  args.path = (char *) path;
  serial = guestfs___send (g, GUESTFS_PROC_TOUCH,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_touch_args, (char *) &args);
  if (serial == -1) {
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
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "touch", "-1");
    return -1;
  }

  if (guestfs___check_reply_header (g, &hdr, GUESTFS_PROC_TOUCH, serial) == -1) {
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
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    trace_fp = guestfs___trace_open (g);
    fprintf (trace_fp, "%s = ", "touch");
    fprintf (trace_fp, "%d", ret_v);
    guestfs___trace_send_line (g);
  }

  return ret_v;
}

GUESTFS_DLL_PUBLIC char **
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
    trace_fp = guestfs___trace_open (g);
    fprintf (trace_fp, "%s", "list_partitions");
    guestfs___trace_send_line (g);
  }

  if (guestfs___check_appliance_up (g, "list_partitions") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "list_partitions", "NULL");
    return NULL;
  }

  serial = guestfs___send (g, GUESTFS_PROC_LIST_PARTITIONS, progress_hint, 0,
                           NULL, NULL);
  if (serial == -1) {
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
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "list_partitions", "NULL");
    return NULL;
  }

  if (guestfs___check_reply_header (g, &hdr, GUESTFS_PROC_LIST_PARTITIONS, serial) == -1) {
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

    trace_fp = guestfs___trace_open (g);
    fprintf (trace_fp, "%s = ", "list_partitions");
    fputs ("[", trace_fp);
    for (i = 0; ret_v[i]; ++i) {
      if (i > 0) fputs (", ", trace_fp);
      fputs ("\"", trace_fp);
      fputs (ret_v[i], trace_fp);
      fputs ("\"", trace_fp);
    }
    fputs ("]", trace_fp);
    guestfs___trace_send_line (g);
  }

  return ret_v;
}

GUESTFS_DLL_PUBLIC struct guestfs_lvm_vg_list *
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
    trace_fp = guestfs___trace_open (g);
    fprintf (trace_fp, "%s", "vgs_full");
    guestfs___trace_send_line (g);
  }

  if (guestfs___check_appliance_up (g, "vgs_full") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "vgs_full", "NULL");
    return NULL;
  }

  serial = guestfs___send (g, GUESTFS_PROC_VGS_FULL, progress_hint, 0,
                           NULL, NULL);
  if (serial == -1) {
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
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "vgs_full", "NULL");
    return NULL;
  }

  if (guestfs___check_reply_header (g, &hdr, GUESTFS_PROC_VGS_FULL, serial) == -1) {
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
    return NULL;
  }

  /* caller will free this */
  ret_v = safe_memdup (g, &ret.volgroups, sizeof (ret.volgroups));
  if (trace_flag) {
    trace_fp = guestfs___trace_open (g);
    fprintf (trace_fp, "%s = ", "vgs_full");
    fprintf (trace_fp, "<struct guestfs_lvm_vg_list *>");
    guestfs___trace_send_line (g);
  }

  return ret_v;
}

GUESTFS_DLL_PUBLIC int
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
    trace_fp = guestfs___trace_open (g);
    fprintf (trace_fp, "%s", "aug_defvar");
    fprintf (trace_fp, " \"%s\"", name);
    if (expr) fprintf (trace_fp, " \"%s\"", expr);
    else fprintf (trace_fp, " null");
    guestfs___trace_send_line (g);
  }

  if (guestfs___check_appliance_up (g, "aug_defvar") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "aug_defvar", "-1");
    return -1;
  }

  args.name = (char *) name;
  args.expr = expr ? (char **) &expr : NULL;
  serial = guestfs___send (g, GUESTFS_PROC_AUG_DEFVAR,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_aug_defvar_args, (char *) &args);
  if (serial == -1) {
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
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "aug_defvar", "-1");
    return -1;
  }

  if (guestfs___check_reply_header (g, &hdr, GUESTFS_PROC_AUG_DEFVAR, serial) == -1) {
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
    return -1;
  }

  ret_v = ret.nrnodes;
  if (trace_flag) {
    trace_fp = guestfs___trace_open (g);
    fprintf (trace_fp, "%s = ", "aug_defvar");
    fprintf (trace_fp, "%d", ret_v);
    guestfs___trace_send_line (g);
  }

  return ret_v;
}

GUESTFS_DLL_PUBLIC int
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
    trace_fp = guestfs___trace_open (g);
    fprintf (trace_fp, "%s", "exists");
    fprintf (trace_fp, " \"%s\"", path);
    guestfs___trace_send_line (g);
  }

  if (guestfs___check_appliance_up (g, "exists") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "exists", "-1");
    return -1;
  }

  args.path = (char *) path;
  serial = guestfs___send (g, GUESTFS_PROC_EXISTS,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_exists_args, (char *) &args);
  if (serial == -1) {
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
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "exists", "-1");
    return -1;
  }

  if (guestfs___check_reply_header (g, &hdr, GUESTFS_PROC_EXISTS, serial) == -1) {
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
    return -1;
  }

  ret_v = ret.existsflag;
  if (trace_flag) {
    trace_fp = guestfs___trace_open (g);
    fprintf (trace_fp, "%s = ", "exists");
    fprintf (trace_fp, "%d", ret_v);
    guestfs___trace_send_line (g);
  }

  return ret_v;
}

GUESTFS_DLL_PUBLIC int
guestfs_umount_opts_argv (guestfs_h *g,
                          const char *pathordevice,
                          const struct guestfs_umount_opts_argv *optargs)
{
  struct guestfs_umount_opts_argv optargs_null;
  if (!optargs) {
    optargs_null.bitmask = 0;
    optargs = &optargs_null;
  }

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
           "umount_opts", "pathordevice");
    return -1;
  }

  if (optargs->bitmask & UINT64_C(0xfffffffffffffffc)) {
    error (g, "%s: unknown option in guestfs_%s_argv->bitmask (this can happen if a program is compiled against a newer version of libguestfs, then dynamically linked to an older version)",
           "umount_opts", "umount_opts");
    return -1;
  }

  if (trace_flag) {
    trace_fp = guestfs___trace_open (g);
    fprintf (trace_fp, "%s", "umount");
    fprintf (trace_fp, " \"%s\"", pathordevice);
    if (optargs->bitmask & GUESTFS_UMOUNT_OPTS_FORCE_BITMASK) {
      fprintf (trace_fp, " \"%s:%s\"", "force", optargs->force ? "true" : "false");
    }
    if (optargs->bitmask & GUESTFS_UMOUNT_OPTS_LAZYUNMOUNT_BITMASK) {
      fprintf (trace_fp, " \"%s:%s\"", "lazyunmount", optargs->lazyunmount ? "true" : "false");
    }
    guestfs___trace_send_line (g);
  }

  if (guestfs___check_appliance_up (g, "umount") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "umount", "-1");
    return -1;
  }

  args.pathordevice = (char *) pathordevice;
  if (optargs->bitmask & GUESTFS_UMOUNT_OPTS_FORCE_BITMASK) {
    args.force = optargs->force;
  } else {
    args.force = 0;
  }
  if (optargs->bitmask & GUESTFS_UMOUNT_OPTS_LAZYUNMOUNT_BITMASK) {
    args.lazyunmount = optargs->lazyunmount;
  } else {
    args.lazyunmount = 0;
  }
  serial = guestfs___send (g, GUESTFS_PROC_UMOUNT,
                           progress_hint, optargs->bitmask,
                           (xdrproc_t) xdr_guestfs_umount_args, (char *) &args);
  if (serial == -1) {
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
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "umount", "-1");
    return -1;
  }

  if (guestfs___check_reply_header (g, &hdr, GUESTFS_PROC_UMOUNT, serial) == -1) {
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
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    trace_fp = guestfs___trace_open (g);
    fprintf (trace_fp, "%s = ", "umount");
    fprintf (trace_fp, "%d", ret_v);
    guestfs___trace_send_line (g);
  }

  return ret_v;
}

GUESTFS_DLL_PUBLIC char **
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
    trace_fp = guestfs___trace_open (g);
    fprintf (trace_fp, "%s", "mounts");
    guestfs___trace_send_line (g);
  }

  if (guestfs___check_appliance_up (g, "mounts") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mounts", "NULL");
    return NULL;
  }

  serial = guestfs___send (g, GUESTFS_PROC_MOUNTS, progress_hint, 0,
                           NULL, NULL);
  if (serial == -1) {
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
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mounts", "NULL");
    return NULL;
  }

  if (guestfs___check_reply_header (g, &hdr, GUESTFS_PROC_MOUNTS, serial) == -1) {
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

    trace_fp = guestfs___trace_open (g);
    fprintf (trace_fp, "%s = ", "mounts");
    fputs ("[", trace_fp);
    for (i = 0; ret_v[i]; ++i) {
      if (i > 0) fputs (", ", trace_fp);
      fputs ("\"", trace_fp);
      fputs (ret_v[i], trace_fp);
      fputs ("\"", trace_fp);
    }
    fputs ("]", trace_fp);
    guestfs___trace_send_line (g);
  }

  return ret_v;
}

GUESTFS_DLL_PUBLIC int
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
    trace_fp = guestfs___trace_open (g);
    fprintf (trace_fp, "%s", "lvm_remove_all");
    guestfs___trace_send_line (g);
  }

  if (guestfs___check_appliance_up (g, "lvm_remove_all") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "lvm_remove_all", "-1");
    return -1;
  }

  serial = guestfs___send (g, GUESTFS_PROC_LVM_REMOVE_ALL, progress_hint, 0,
                           NULL, NULL);
  if (serial == -1) {
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
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "lvm_remove_all", "-1");
    return -1;
  }

  if (guestfs___check_reply_header (g, &hdr, GUESTFS_PROC_LVM_REMOVE_ALL, serial) == -1) {
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
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    trace_fp = guestfs___trace_open (g);
    fprintf (trace_fp, "%s = ", "lvm_remove_all");
    fprintf (trace_fp, "%d", ret_v);
    guestfs___trace_send_line (g);
  }

  return ret_v;
}

GUESTFS_DLL_PUBLIC struct guestfs_stat *
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
    trace_fp = guestfs___trace_open (g);
    fprintf (trace_fp, "%s", "lstat");
    fprintf (trace_fp, " \"%s\"", path);
    guestfs___trace_send_line (g);
  }

  if (guestfs___check_appliance_up (g, "lstat") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "lstat", "NULL");
    return NULL;
  }

  args.path = (char *) path;
  serial = guestfs___send (g, GUESTFS_PROC_LSTAT,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_lstat_args, (char *) &args);
  if (serial == -1) {
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
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "lstat", "NULL");
    return NULL;
  }

  if (guestfs___check_reply_header (g, &hdr, GUESTFS_PROC_LSTAT, serial) == -1) {
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
    return NULL;
  }

  /* caller will free this */
  ret_v = safe_memdup (g, &ret.statbuf, sizeof (ret.statbuf));
  if (trace_flag) {
    trace_fp = guestfs___trace_open (g);
    fprintf (trace_fp, "%s = ", "lstat");
    fprintf (trace_fp, "<struct guestfs_stat *>");
    guestfs___trace_send_line (g);
  }

  return ret_v;
}

GUESTFS_DLL_PUBLIC char **
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
    trace_fp = guestfs___trace_open (g);
    fprintf (trace_fp, "%s", "tune2fs_l");
    fprintf (trace_fp, " \"%s\"", device);
    guestfs___trace_send_line (g);
  }

  if (guestfs___check_appliance_up (g, "tune2fs_l") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "tune2fs_l", "NULL");
    return NULL;
  }

  args.device = (char *) device;
  serial = guestfs___send (g, GUESTFS_PROC_TUNE2FS_L,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_tune2fs_l_args, (char *) &args);
  if (serial == -1) {
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
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "tune2fs_l", "NULL");
    return NULL;
  }

  if (guestfs___check_reply_header (g, &hdr, GUESTFS_PROC_TUNE2FS_L, serial) == -1) {
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
    return NULL;
  }

  /* caller will free this, but we need to add a NULL entry */
  ret.superblock.superblock_val =
    safe_realloc (g, ret.superblock.superblock_val,
                  sizeof (char *) * (ret.superblock.superblock_len + 1));
  ret.superblock.superblock_val[ret.superblock.superblock_len] = NULL;
  ret_v = ret.superblock.superblock_val;
  if (trace_flag) {
    size_t i;

    trace_fp = guestfs___trace_open (g);
    fprintf (trace_fp, "%s = ", "tune2fs_l");
    fputs ("[", trace_fp);
    for (i = 0; ret_v[i]; ++i) {
      if (i > 0) fputs (", ", trace_fp);
      fputs ("\"", trace_fp);
      fputs (ret_v[i], trace_fp);
      fputs ("\"", trace_fp);
    }
    fputs ("]", trace_fp);
    guestfs___trace_send_line (g);
  }

  return ret_v;
}

GUESTFS_DLL_PUBLIC int
guestfs_mount_ro (guestfs_h *g,
                  const char *mountable,
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
  if (mountable == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "mount_ro", "mountable");
    return -1;
  }
  if (mountpoint == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "mount_ro", "mountpoint");
    return -1;
  }

  if (trace_flag) {
    trace_fp = guestfs___trace_open (g);
    fprintf (trace_fp, "%s", "mount_ro");
    fprintf (trace_fp, " \"%s\"", mountable);
    fprintf (trace_fp, " \"%s\"", mountpoint);
    guestfs___trace_send_line (g);
  }

  if (guestfs___check_appliance_up (g, "mount_ro") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mount_ro", "-1");
    return -1;
  }

  args.mountable = (char *) mountable;
  args.mountpoint = (char *) mountpoint;
  serial = guestfs___send (g, GUESTFS_PROC_MOUNT_RO,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_mount_ro_args, (char *) &args);
  if (serial == -1) {
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
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mount_ro", "-1");
    return -1;
  }

  if (guestfs___check_reply_header (g, &hdr, GUESTFS_PROC_MOUNT_RO, serial) == -1) {
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
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    trace_fp = guestfs___trace_open (g);
    fprintf (trace_fp, "%s = ", "mount_ro");
    fprintf (trace_fp, "%d", ret_v);
    guestfs___trace_send_line (g);
  }

  return ret_v;
}

GUESTFS_DLL_PUBLIC int
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

    trace_fp = guestfs___trace_open (g);
    fprintf (trace_fp, "%s", "vg_activate");
    fputs (activate ? " true" : " false", trace_fp);
    fputc (' ', trace_fp);
    fputc ('"', trace_fp);
    for (i = 0; volgroups[i]; ++i) {
      if (i > 0) fputc (' ', trace_fp);
      fputs (volgroups[i], trace_fp);
    }
    fputc ('"', trace_fp);
    guestfs___trace_send_line (g);
  }

  if (guestfs___check_appliance_up (g, "vg_activate") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "vg_activate", "-1");
    return -1;
  }

  args.activate = activate;
  args.volgroups.volgroups_val = (char **) volgroups;
  for (args.volgroups.volgroups_len = 0; volgroups[args.volgroups.volgroups_len]; args.volgroups.volgroups_len++) ;
  serial = guestfs___send (g, GUESTFS_PROC_VG_ACTIVATE,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_vg_activate_args, (char *) &args);
  if (serial == -1) {
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
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "vg_activate", "-1");
    return -1;
  }

  if (guestfs___check_reply_header (g, &hdr, GUESTFS_PROC_VG_ACTIVATE, serial) == -1) {
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
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    trace_fp = guestfs___trace_open (g);
    fprintf (trace_fp, "%s = ", "vg_activate");
    fprintf (trace_fp, "%d", ret_v);
    guestfs___trace_send_line (g);
  }

  return ret_v;
}

GUESTFS_DLL_PUBLIC int
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
    trace_fp = guestfs___trace_open (g);
    fprintf (trace_fp, "%s", "ntfs_3g_probe");
    fputs (rw ? " true" : " false", trace_fp);
    fprintf (trace_fp, " \"%s\"", device);
    guestfs___trace_send_line (g);
  }

  if (guestfs___check_appliance_up (g, "ntfs_3g_probe") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "ntfs_3g_probe", "-1");
    return -1;
  }

  args.rw = rw;
  args.device = (char *) device;
  serial = guestfs___send (g, GUESTFS_PROC_NTFS_3G_PROBE,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_ntfs_3g_probe_args, (char *) &args);
  if (serial == -1) {
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
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "ntfs_3g_probe", "-1");
    return -1;
  }

  if (guestfs___check_reply_header (g, &hdr, GUESTFS_PROC_NTFS_3G_PROBE, serial) == -1) {
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
    return -1;
  }

  ret_v = ret.status;
  if (trace_flag) {
    trace_fp = guestfs___trace_open (g);
    fprintf (trace_fp, "%s = ", "ntfs_3g_probe");
    fprintf (trace_fp, "%d", ret_v);
    guestfs___trace_send_line (g);
  }

  return ret_v;
}

GUESTFS_DLL_PUBLIC char *
guestfs_mkdtemp (guestfs_h *g,
                 const char *tmpl)
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
  if (tmpl == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "mkdtemp", "tmpl");
    return NULL;
  }

  if (trace_flag) {
    trace_fp = guestfs___trace_open (g);
    fprintf (trace_fp, "%s", "mkdtemp");
    fprintf (trace_fp, " \"%s\"", tmpl);
    guestfs___trace_send_line (g);
  }

  if (guestfs___check_appliance_up (g, "mkdtemp") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mkdtemp", "NULL");
    return NULL;
  }

  args.tmpl = (char *) tmpl;
  serial = guestfs___send (g, GUESTFS_PROC_MKDTEMP,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_mkdtemp_args, (char *) &args);
  if (serial == -1) {
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
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mkdtemp", "NULL");
    return NULL;
  }

  if (guestfs___check_reply_header (g, &hdr, GUESTFS_PROC_MKDTEMP, serial) == -1) {
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
    return NULL;
  }

  ret_v = ret.dir; /* caller will free */
  if (trace_flag) {
    trace_fp = guestfs___trace_open (g);
    fprintf (trace_fp, "%s = ", "mkdtemp");
    fprintf (trace_fp, "\"%s\"", ret_v);
    guestfs___trace_send_line (g);
  }

  return ret_v;
}

GUESTFS_DLL_PUBLIC char **
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
    trace_fp = guestfs___trace_open (g);
    fprintf (trace_fp, "%s", "tail");
    fprintf (trace_fp, " \"%s\"", path);
    guestfs___trace_send_line (g);
  }

  if (guestfs___check_appliance_up (g, "tail") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "tail", "NULL");
    return NULL;
  }

  args.path = (char *) path;
  serial = guestfs___send (g, GUESTFS_PROC_TAIL,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_tail_args, (char *) &args);
  if (serial == -1) {
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
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "tail", "NULL");
    return NULL;
  }

  if (guestfs___check_reply_header (g, &hdr, GUESTFS_PROC_TAIL, serial) == -1) {
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

    trace_fp = guestfs___trace_open (g);
    fprintf (trace_fp, "%s = ", "tail");
    fputs ("[", trace_fp);
    for (i = 0; ret_v[i]; ++i) {
      if (i > 0) fputs (", ", trace_fp);
      fputs ("\"", trace_fp);
      fputs (ret_v[i], trace_fp);
      fputs ("\"", trace_fp);
    }
    fputs ("]", trace_fp);
    guestfs___trace_send_line (g);
  }

  return ret_v;
}

GUESTFS_DLL_PUBLIC char **
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
    trace_fp = guestfs___trace_open (g);
    fprintf (trace_fp, "%s", "initrd_list");
    fprintf (trace_fp, " \"%s\"", path);
    guestfs___trace_send_line (g);
  }

  if (guestfs___check_appliance_up (g, "initrd_list") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "initrd_list", "NULL");
    return NULL;
  }

  args.path = (char *) path;
  serial = guestfs___send (g, GUESTFS_PROC_INITRD_LIST,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_initrd_list_args, (char *) &args);
  if (serial == -1) {
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
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "initrd_list", "NULL");
    return NULL;
  }

  if (guestfs___check_reply_header (g, &hdr, GUESTFS_PROC_INITRD_LIST, serial) == -1) {
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
    return NULL;
  }

  /* caller will free this, but we need to add a NULL entry */
  ret.filenames.filenames_val =
    safe_realloc (g, ret.filenames.filenames_val,
                  sizeof (char *) * (ret.filenames.filenames_len + 1));
  ret.filenames.filenames_val[ret.filenames.filenames_len] = NULL;
  ret_v = ret.filenames.filenames_val;
  if (trace_flag) {
    size_t i;

    trace_fp = guestfs___trace_open (g);
    fprintf (trace_fp, "%s = ", "initrd_list");
    fputs ("[", trace_fp);
    for (i = 0; ret_v[i]; ++i) {
      if (i > 0) fputs (", ", trace_fp);
      fputs ("\"", trace_fp);
      fputs (ret_v[i], trace_fp);
      fputs ("\"", trace_fp);
    }
    fputs ("]", trace_fp);
    guestfs___trace_send_line (g);
  }

  return ret_v;
}

GUESTFS_DLL_PUBLIC int
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
    trace_fp = guestfs___trace_open (g);
    fprintf (trace_fp, "%s", "mknod");
    fprintf (trace_fp, " %d", mode);
    fprintf (trace_fp, " %d", devmajor);
    fprintf (trace_fp, " %d", devminor);
    fprintf (trace_fp, " \"%s\"", path);
    guestfs___trace_send_line (g);
  }

  if (guestfs___check_appliance_up (g, "mknod") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mknod", "-1");
    return -1;
  }

  args.mode = mode;
  args.devmajor = devmajor;
  args.devminor = devminor;
  args.path = (char *) path;
  serial = guestfs___send (g, GUESTFS_PROC_MKNOD,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_mknod_args, (char *) &args);
  if (serial == -1) {
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
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mknod", "-1");
    return -1;
  }

  if (guestfs___check_reply_header (g, &hdr, GUESTFS_PROC_MKNOD, serial) == -1) {
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
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    trace_fp = guestfs___trace_open (g);
    fprintf (trace_fp, "%s = ", "mknod");
    fprintf (trace_fp, "%d", ret_v);
    guestfs___trace_send_line (g);
  }

  return ret_v;
}

GUESTFS_DLL_PUBLIC char *
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
    trace_fp = guestfs___trace_open (g);
    fprintf (trace_fp, "%s", "zfile");
    fprintf (trace_fp, " \"%s\"", meth);
    fprintf (trace_fp, " \"%s\"", path);
    guestfs___trace_send_line (g);
  }

  if (guestfs___check_appliance_up (g, "zfile") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "zfile", "NULL");
    return NULL;
  }

  args.meth = (char *) meth;
  args.path = (char *) path;
  serial = guestfs___send (g, GUESTFS_PROC_ZFILE,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_zfile_args, (char *) &args);
  if (serial == -1) {
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
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "zfile", "NULL");
    return NULL;
  }

  if (guestfs___check_reply_header (g, &hdr, GUESTFS_PROC_ZFILE, serial) == -1) {
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
    return NULL;
  }

  ret_v = ret.description; /* caller will free */
  if (trace_flag) {
    trace_fp = guestfs___trace_open (g);
    fprintf (trace_fp, "%s = ", "zfile");
    fprintf (trace_fp, "\"%s\"", ret_v);
    guestfs___trace_send_line (g);
  }

  return ret_v;
}

GUESTFS_DLL_PUBLIC struct guestfs_xattr_list *
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
    trace_fp = guestfs___trace_open (g);
    fprintf (trace_fp, "%s", "getxattrs");
    fprintf (trace_fp, " \"%s\"", path);
    guestfs___trace_send_line (g);
  }

  if (guestfs___check_appliance_up (g, "getxattrs") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "getxattrs", "NULL");
    return NULL;
  }

  args.path = (char *) path;
  serial = guestfs___send (g, GUESTFS_PROC_GETXATTRS,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_getxattrs_args, (char *) &args);
  if (serial == -1) {
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
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "getxattrs", "NULL");
    return NULL;
  }

  if (guestfs___check_reply_header (g, &hdr, GUESTFS_PROC_GETXATTRS, serial) == -1) {
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
    return NULL;
  }

  /* caller will free this */
  ret_v = safe_memdup (g, &ret.xattrs, sizeof (ret.xattrs));
  if (trace_flag) {
    trace_fp = guestfs___trace_open (g);
    fprintf (trace_fp, "%s = ", "getxattrs");
    fprintf (trace_fp, "<struct guestfs_xattr_list *>");
    guestfs___trace_send_line (g);
  }

  return ret_v;
}

GUESTFS_DLL_PUBLIC char **
guestfs_grep_opts_argv (guestfs_h *g,
                        const char *regex,
                        const char *path,
                        const struct guestfs_grep_opts_argv *optargs)
{
  struct guestfs_grep_opts_argv optargs_null;
  if (!optargs) {
    optargs_null.bitmask = 0;
    optargs = &optargs_null;
  }

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
           "grep_opts", "regex");
    return NULL;
  }
  if (path == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "grep_opts", "path");
    return NULL;
  }

  if (optargs->bitmask & UINT64_C(0xfffffffffffffff0)) {
    error (g, "%s: unknown option in guestfs_%s_argv->bitmask (this can happen if a program is compiled against a newer version of libguestfs, then dynamically linked to an older version)",
           "grep_opts", "grep_opts");
    return NULL;
  }

  if (trace_flag) {
    trace_fp = guestfs___trace_open (g);
    fprintf (trace_fp, "%s", "grep");
    fprintf (trace_fp, " \"%s\"", regex);
    fprintf (trace_fp, " \"%s\"", path);
    if (optargs->bitmask & GUESTFS_GREP_OPTS_EXTENDED_BITMASK) {
      fprintf (trace_fp, " \"%s:%s\"", "extended", optargs->extended ? "true" : "false");
    }
    if (optargs->bitmask & GUESTFS_GREP_OPTS_FIXED_BITMASK) {
      fprintf (trace_fp, " \"%s:%s\"", "fixed", optargs->fixed ? "true" : "false");
    }
    if (optargs->bitmask & GUESTFS_GREP_OPTS_INSENSITIVE_BITMASK) {
      fprintf (trace_fp, " \"%s:%s\"", "insensitive", optargs->insensitive ? "true" : "false");
    }
    if (optargs->bitmask & GUESTFS_GREP_OPTS_COMPRESSED_BITMASK) {
      fprintf (trace_fp, " \"%s:%s\"", "compressed", optargs->compressed ? "true" : "false");
    }
    guestfs___trace_send_line (g);
  }

  if (guestfs___check_appliance_up (g, "grep") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "grep", "NULL");
    return NULL;
  }

  args.regex = (char *) regex;
  args.path = (char *) path;
  if (optargs->bitmask & GUESTFS_GREP_OPTS_EXTENDED_BITMASK) {
    args.extended = optargs->extended;
  } else {
    args.extended = 0;
  }
  if (optargs->bitmask & GUESTFS_GREP_OPTS_FIXED_BITMASK) {
    args.fixed = optargs->fixed;
  } else {
    args.fixed = 0;
  }
  if (optargs->bitmask & GUESTFS_GREP_OPTS_INSENSITIVE_BITMASK) {
    args.insensitive = optargs->insensitive;
  } else {
    args.insensitive = 0;
  }
  if (optargs->bitmask & GUESTFS_GREP_OPTS_COMPRESSED_BITMASK) {
    args.compressed = optargs->compressed;
  } else {
    args.compressed = 0;
  }
  serial = guestfs___send (g, GUESTFS_PROC_GREP,
                           progress_hint, optargs->bitmask,
                           (xdrproc_t) xdr_guestfs_grep_args, (char *) &args);
  if (serial == -1) {
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
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "grep", "NULL");
    return NULL;
  }

  if (guestfs___check_reply_header (g, &hdr, GUESTFS_PROC_GREP, serial) == -1) {
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

    trace_fp = guestfs___trace_open (g);
    fprintf (trace_fp, "%s = ", "grep");
    fputs ("[", trace_fp);
    for (i = 0; ret_v[i]; ++i) {
      if (i > 0) fputs (", ", trace_fp);
      fputs ("\"", trace_fp);
      fputs (ret_v[i], trace_fp);
      fputs ("\"", trace_fp);
    }
    fputs ("]", trace_fp);
    guestfs___trace_send_line (g);
  }

  return ret_v;
}

GUESTFS_DLL_PUBLIC char **
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
    trace_fp = guestfs___trace_open (g);
    fprintf (trace_fp, "%s", "zfgrep");
    fprintf (trace_fp, " \"%s\"", pattern);
    fprintf (trace_fp, " \"%s\"", path);
    guestfs___trace_send_line (g);
  }

  if (guestfs___check_appliance_up (g, "zfgrep") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "zfgrep", "NULL");
    return NULL;
  }

  args.pattern = (char *) pattern;
  args.path = (char *) path;
  serial = guestfs___send (g, GUESTFS_PROC_ZFGREP,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_zfgrep_args, (char *) &args);
  if (serial == -1) {
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
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "zfgrep", "NULL");
    return NULL;
  }

  if (guestfs___check_reply_header (g, &hdr, GUESTFS_PROC_ZFGREP, serial) == -1) {
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

    trace_fp = guestfs___trace_open (g);
    fprintf (trace_fp, "%s = ", "zfgrep");
    fputs ("[", trace_fp);
    for (i = 0; ret_v[i]; ++i) {
      if (i > 0) fputs (", ", trace_fp);
      fputs ("\"", trace_fp);
      fputs (ret_v[i], trace_fp);
      fputs ("\"", trace_fp);
    }
    fputs ("]", trace_fp);
    guestfs___trace_send_line (g);
  }

  return ret_v;
}

GUESTFS_DLL_PUBLIC char **
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
    trace_fp = guestfs___trace_open (g);
    fprintf (trace_fp, "%s", "zegrepi");
    fprintf (trace_fp, " \"%s\"", regex);
    fprintf (trace_fp, " \"%s\"", path);
    guestfs___trace_send_line (g);
  }

  if (guestfs___check_appliance_up (g, "zegrepi") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "zegrepi", "NULL");
    return NULL;
  }

  args.regex = (char *) regex;
  args.path = (char *) path;
  serial = guestfs___send (g, GUESTFS_PROC_ZEGREPI,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_zegrepi_args, (char *) &args);
  if (serial == -1) {
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
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "zegrepi", "NULL");
    return NULL;
  }

  if (guestfs___check_reply_header (g, &hdr, GUESTFS_PROC_ZEGREPI, serial) == -1) {
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

    trace_fp = guestfs___trace_open (g);
    fprintf (trace_fp, "%s = ", "zegrepi");
    fputs ("[", trace_fp);
    for (i = 0; ret_v[i]; ++i) {
      if (i > 0) fputs (", ", trace_fp);
      fputs ("\"", trace_fp);
      fputs (ret_v[i], trace_fp);
      fputs ("\"", trace_fp);
    }
    fputs ("]", trace_fp);
    guestfs___trace_send_line (g);
  }

  return ret_v;
}

GUESTFS_DLL_PUBLIC char *
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
    trace_fp = guestfs___trace_open (g);
    fprintf (trace_fp, "%s", "realpath");
    fprintf (trace_fp, " \"%s\"", path);
    guestfs___trace_send_line (g);
  }

  if (guestfs___check_appliance_up (g, "realpath") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "realpath", "NULL");
    return NULL;
  }

  args.path = (char *) path;
  serial = guestfs___send (g, GUESTFS_PROC_REALPATH,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_realpath_args, (char *) &args);
  if (serial == -1) {
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
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "realpath", "NULL");
    return NULL;
  }

  if (guestfs___check_reply_header (g, &hdr, GUESTFS_PROC_REALPATH, serial) == -1) {
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
    return NULL;
  }

  ret_v = ret.rpath; /* caller will free */
  if (trace_flag) {
    trace_fp = guestfs___trace_open (g);
    fprintf (trace_fp, "%s = ", "realpath");
    fprintf (trace_fp, "\"%s\"", ret_v);
    guestfs___trace_send_line (g);
  }

  return ret_v;
}

GUESTFS_DLL_PUBLIC int
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
    trace_fp = guestfs___trace_open (g);
    fprintf (trace_fp, "%s", "swapoff_file");
    fprintf (trace_fp, " \"%s\"", file);
    guestfs___trace_send_line (g);
  }

  if (guestfs___check_appliance_up (g, "swapoff_file") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "swapoff_file", "-1");
    return -1;
  }

  args.file = (char *) file;
  serial = guestfs___send (g, GUESTFS_PROC_SWAPOFF_FILE,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_swapoff_file_args, (char *) &args);
  if (serial == -1) {
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
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "swapoff_file", "-1");
    return -1;
  }

  if (guestfs___check_reply_header (g, &hdr, GUESTFS_PROC_SWAPOFF_FILE, serial) == -1) {
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
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    trace_fp = guestfs___trace_open (g);
    fprintf (trace_fp, "%s = ", "swapoff_file");
    fprintf (trace_fp, "%d", ret_v);
    guestfs___trace_send_line (g);
  }

  return ret_v;
}

GUESTFS_DLL_PUBLIC int
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
    trace_fp = guestfs___trace_open (g);
    fprintf (trace_fp, "%s", "inotify_rm_watch");
    fprintf (trace_fp, " %d", wd);
    guestfs___trace_send_line (g);
  }

  if (guestfs___check_appliance_up (g, "inotify_rm_watch") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "inotify_rm_watch", "-1");
    return -1;
  }

  args.wd = wd;
  serial = guestfs___send (g, GUESTFS_PROC_INOTIFY_RM_WATCH,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_inotify_rm_watch_args, (char *) &args);
  if (serial == -1) {
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
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "inotify_rm_watch", "-1");
    return -1;
  }

  if (guestfs___check_reply_header (g, &hdr, GUESTFS_PROC_INOTIFY_RM_WATCH, serial) == -1) {
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
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    trace_fp = guestfs___trace_open (g);
    fprintf (trace_fp, "%s = ", "inotify_rm_watch");
    fprintf (trace_fp, "%d", ret_v);
    guestfs___trace_send_line (g);
  }

  return ret_v;
}

GUESTFS_DLL_PUBLIC char **
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
    trace_fp = guestfs___trace_open (g);
    fprintf (trace_fp, "%s", "inotify_files");
    guestfs___trace_send_line (g);
  }

  if (guestfs___check_appliance_up (g, "inotify_files") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "inotify_files", "NULL");
    return NULL;
  }

  serial = guestfs___send (g, GUESTFS_PROC_INOTIFY_FILES, progress_hint, 0,
                           NULL, NULL);
  if (serial == -1) {
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
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "inotify_files", "NULL");
    return NULL;
  }

  if (guestfs___check_reply_header (g, &hdr, GUESTFS_PROC_INOTIFY_FILES, serial) == -1) {
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
    return NULL;
  }

  /* caller will free this, but we need to add a NULL entry */
  ret.paths.paths_val =
    safe_realloc (g, ret.paths.paths_val,
                  sizeof (char *) * (ret.paths.paths_len + 1));
  ret.paths.paths_val[ret.paths.paths_len] = NULL;
  ret_v = ret.paths.paths_val;
  if (trace_flag) {
    size_t i;

    trace_fp = guestfs___trace_open (g);
    fprintf (trace_fp, "%s = ", "inotify_files");
    fputs ("[", trace_fp);
    for (i = 0; ret_v[i]; ++i) {
      if (i > 0) fputs (", ", trace_fp);
      fputs ("\"", trace_fp);
      fputs (ret_v[i], trace_fp);
      fputs ("\"", trace_fp);
    }
    fputs ("]", trace_fp);
    guestfs___trace_send_line (g);
  }

  return ret_v;
}

GUESTFS_DLL_PUBLIC int
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
    trace_fp = guestfs___trace_open (g);
    fprintf (trace_fp, "%s", "lchown");
    fprintf (trace_fp, " %d", owner);
    fprintf (trace_fp, " %d", group);
    fprintf (trace_fp, " \"%s\"", path);
    guestfs___trace_send_line (g);
  }

  if (guestfs___check_appliance_up (g, "lchown") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "lchown", "-1");
    return -1;
  }

  args.owner = owner;
  args.group = group;
  args.path = (char *) path;
  serial = guestfs___send (g, GUESTFS_PROC_LCHOWN,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_lchown_args, (char *) &args);
  if (serial == -1) {
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
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "lchown", "-1");
    return -1;
  }

  if (guestfs___check_reply_header (g, &hdr, GUESTFS_PROC_LCHOWN, serial) == -1) {
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
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    trace_fp = guestfs___trace_open (g);
    fprintf (trace_fp, "%s = ", "lchown");
    fprintf (trace_fp, "%d", ret_v);
    guestfs___trace_send_line (g);
  }

  return ret_v;
}

GUESTFS_DLL_PUBLIC char *
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
    trace_fp = guestfs___trace_open (g);
    fprintf (trace_fp, "%s", "pread");
    fprintf (trace_fp, " \"%s\"", path);
    fprintf (trace_fp, " %d", count);
    fprintf (trace_fp, " %" PRIi64, offset);
    guestfs___trace_send_line (g);
  }

  if (guestfs___check_appliance_up (g, "pread") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "pread", "NULL");
    return NULL;
  }

  args.path = (char *) path;
  args.count = count;
  args.offset = offset;
  serial = guestfs___send (g, GUESTFS_PROC_PREAD,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_pread_args, (char *) &args);
  if (serial == -1) {
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
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "pread", "NULL");
    return NULL;
  }

  if (guestfs___check_reply_header (g, &hdr, GUESTFS_PROC_PREAD, serial) == -1) {
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
    trace_fp = guestfs___trace_open (g);
    fprintf (trace_fp, "%s = ", "pread");
    guestfs___print_BufferOut (trace_fp, ret_v, *size_r);
    guestfs___trace_send_line (g);
  }

  return ret_v;
}

GUESTFS_DLL_PUBLIC int
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
    trace_fp = guestfs___trace_open (g);
    fprintf (trace_fp, "%s", "dd");
    fprintf (trace_fp, " \"%s\"", src);
    fprintf (trace_fp, " \"%s\"", dest);
    guestfs___trace_send_line (g);
  }

  if (guestfs___check_appliance_up (g, "dd") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "dd", "-1");
    return -1;
  }

  args.src = (char *) src;
  args.dest = (char *) dest;
  serial = guestfs___send (g, GUESTFS_PROC_DD,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_dd_args, (char *) &args);
  if (serial == -1) {
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
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "dd", "-1");
    return -1;
  }

  if (guestfs___check_reply_header (g, &hdr, GUESTFS_PROC_DD, serial) == -1) {
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
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    trace_fp = guestfs___trace_open (g);
    fprintf (trace_fp, "%s = ", "dd");
    fprintf (trace_fp, "%d", ret_v);
    guestfs___trace_send_line (g);
  }

  return ret_v;
}

GUESTFS_DLL_PUBLIC int
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
    trace_fp = guestfs___trace_open (g);
    fprintf (trace_fp, "%s", "vgscan");
    guestfs___trace_send_line (g);
  }

  if (guestfs___check_appliance_up (g, "vgscan") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "vgscan", "-1");
    return -1;
  }

  serial = guestfs___send (g, GUESTFS_PROC_VGSCAN, progress_hint, 0,
                           NULL, NULL);
  if (serial == -1) {
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
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "vgscan", "-1");
    return -1;
  }

  if (guestfs___check_reply_header (g, &hdr, GUESTFS_PROC_VGSCAN, serial) == -1) {
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
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    trace_fp = guestfs___trace_open (g);
    fprintf (trace_fp, "%s = ", "vgscan");
    fprintf (trace_fp, "%d", ret_v);
    guestfs___trace_send_line (g);
  }

  return ret_v;
}

GUESTFS_DLL_PUBLIC char *
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
    trace_fp = guestfs___trace_open (g);
    fprintf (trace_fp, "%s", "checksum_device");
    fprintf (trace_fp, " \"%s\"", csumtype);
    fprintf (trace_fp, " \"%s\"", device);
    guestfs___trace_send_line (g);
  }

  if (guestfs___check_appliance_up (g, "checksum_device") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "checksum_device", "NULL");
    return NULL;
  }

  args.csumtype = (char *) csumtype;
  args.device = (char *) device;
  serial = guestfs___send (g, GUESTFS_PROC_CHECKSUM_DEVICE,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_checksum_device_args, (char *) &args);
  if (serial == -1) {
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
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "checksum_device", "NULL");
    return NULL;
  }

  if (guestfs___check_reply_header (g, &hdr, GUESTFS_PROC_CHECKSUM_DEVICE, serial) == -1) {
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
    return NULL;
  }

  ret_v = ret.checksum; /* caller will free */
  if (trace_flag) {
    trace_fp = guestfs___trace_open (g);
    fprintf (trace_fp, "%s = ", "checksum_device");
    fprintf (trace_fp, "\"%s\"", ret_v);
    guestfs___trace_send_line (g);
  }

  return ret_v;
}

GUESTFS_DLL_PUBLIC int
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
    trace_fp = guestfs___trace_open (g);
    fprintf (trace_fp, "%s", "lvresize_free");
    fprintf (trace_fp, " \"%s\"", lv);
    fprintf (trace_fp, " %d", percent);
    guestfs___trace_send_line (g);
  }

  if (guestfs___check_appliance_up (g, "lvresize_free") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "lvresize_free", "-1");
    return -1;
  }

  args.lv = (char *) lv;
  args.percent = percent;
  serial = guestfs___send (g, GUESTFS_PROC_LVRESIZE_FREE,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_lvresize_free_args, (char *) &args);
  if (serial == -1) {
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
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "lvresize_free", "-1");
    return -1;
  }

  if (guestfs___check_reply_header (g, &hdr, GUESTFS_PROC_LVRESIZE_FREE, serial) == -1) {
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
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    trace_fp = guestfs___trace_open (g);
    fprintf (trace_fp, "%s = ", "lvresize_free");
    fprintf (trace_fp, "%d", ret_v);
    guestfs___trace_send_line (g);
  }

  return ret_v;
}

GUESTFS_DLL_PUBLIC int
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
    trace_fp = guestfs___trace_open (g);
    fprintf (trace_fp, "%s", "aug_clear");
    fprintf (trace_fp, " \"%s\"", augpath);
    guestfs___trace_send_line (g);
  }

  if (guestfs___check_appliance_up (g, "aug_clear") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "aug_clear", "-1");
    return -1;
  }

  args.augpath = (char *) augpath;
  serial = guestfs___send (g, GUESTFS_PROC_AUG_CLEAR,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_aug_clear_args, (char *) &args);
  if (serial == -1) {
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
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "aug_clear", "-1");
    return -1;
  }

  if (guestfs___check_reply_header (g, &hdr, GUESTFS_PROC_AUG_CLEAR, serial) == -1) {
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
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    trace_fp = guestfs___trace_open (g);
    fprintf (trace_fp, "%s = ", "aug_clear");
    fprintf (trace_fp, "%d", ret_v);
    guestfs___trace_send_line (g);
  }

  return ret_v;
}

GUESTFS_DLL_PUBLIC int
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
    trace_fp = guestfs___trace_open (g);
    fprintf (trace_fp, "%s", "get_umask");
    guestfs___trace_send_line (g);
  }

  if (guestfs___check_appliance_up (g, "get_umask") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "get_umask", "-1");
    return -1;
  }

  serial = guestfs___send (g, GUESTFS_PROC_GET_UMASK, progress_hint, 0,
                           NULL, NULL);
  if (serial == -1) {
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
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "get_umask", "-1");
    return -1;
  }

  if (guestfs___check_reply_header (g, &hdr, GUESTFS_PROC_GET_UMASK, serial) == -1) {
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
    return -1;
  }

  ret_v = ret.mask;
  if (trace_flag) {
    trace_fp = guestfs___trace_open (g);
    fprintf (trace_fp, "%s = ", "get_umask");
    fprintf (trace_fp, "%d", ret_v);
    guestfs___trace_send_line (g);
  }

  return ret_v;
}

GUESTFS_DLL_PUBLIC int
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
    trace_fp = guestfs___trace_open (g);
    fprintf (trace_fp, "%s", "base64_in");
    fprintf (trace_fp, " \"%s\"", base64file);
    fprintf (trace_fp, " \"%s\"", filename);
    guestfs___trace_send_line (g);
  }

  if (stat (base64file, &progress_stat) == 0 &&
      S_ISREG (progress_stat.st_mode))
    progress_hint += progress_stat.st_size;

  if (guestfs___check_appliance_up (g, "base64_in") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "base64_in", "-1");
    return -1;
  }

  args.filename = (char *) filename;
  serial = guestfs___send (g, GUESTFS_PROC_BASE64_IN,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_base64_in_args, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "base64_in", "-1");
    return -1;
  }

  r = guestfs___send_file (g, base64file);
  if (r == -1) {
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
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "base64_in", "-1");
    return -1;
  }

  if (guestfs___check_reply_header (g, &hdr, GUESTFS_PROC_BASE64_IN, serial) == -1) {
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
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    trace_fp = guestfs___trace_open (g);
    fprintf (trace_fp, "%s = ", "base64_in");
    fprintf (trace_fp, "%d", ret_v);
    guestfs___trace_send_line (g);
  }

  return ret_v;
}

GUESTFS_DLL_PUBLIC int
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
    trace_fp = guestfs___trace_open (g);
    fprintf (trace_fp, "%s", "base64_out");
    fprintf (trace_fp, " \"%s\"", filename);
    fprintf (trace_fp, " \"%s\"", base64file);
    guestfs___trace_send_line (g);
  }

  if (guestfs___check_appliance_up (g, "base64_out") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "base64_out", "-1");
    return -1;
  }

  args.filename = (char *) filename;
  serial = guestfs___send (g, GUESTFS_PROC_BASE64_OUT,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_base64_out_args, (char *) &args);
  if (serial == -1) {
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
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "base64_out", "-1");
    return -1;
  }

  if (guestfs___check_reply_header (g, &hdr, GUESTFS_PROC_BASE64_OUT, serial) == -1) {
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
    return -1;
  }

  if (guestfs___recv_file (g, base64file) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "base64_out", "-1");
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    trace_fp = guestfs___trace_open (g);
    fprintf (trace_fp, "%s = ", "base64_out");
    fprintf (trace_fp, "%d", ret_v);
    guestfs___trace_send_line (g);
  }

  return ret_v;
}

GUESTFS_DLL_PUBLIC int
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
    trace_fp = guestfs___trace_open (g);
    fprintf (trace_fp, "%s", "luks_open");
    fprintf (trace_fp, " \"%s\"", device);
    fprintf (trace_fp, " \"***\"");
    fprintf (trace_fp, " \"%s\"", mapname);
    guestfs___trace_send_line (g);
  }

  if (guestfs___check_appliance_up (g, "luks_open") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "luks_open", "-1");
    return -1;
  }

  args.device = (char *) device;
  args.key = (char *) key;
  args.mapname = (char *) mapname;
  serial = guestfs___send (g, GUESTFS_PROC_LUKS_OPEN,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_luks_open_args, (char *) &args);
  if (serial == -1) {
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
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "luks_open", "-1");
    return -1;
  }

  if (guestfs___check_reply_header (g, &hdr, GUESTFS_PROC_LUKS_OPEN, serial) == -1) {
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
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    trace_fp = guestfs___trace_open (g);
    fprintf (trace_fp, "%s = ", "luks_open");
    fprintf (trace_fp, "%d", ret_v);
    guestfs___trace_send_line (g);
  }

  return ret_v;
}

GUESTFS_DLL_PUBLIC int
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
    trace_fp = guestfs___trace_open (g);
    fprintf (trace_fp, "%s", "luks_open_ro");
    fprintf (trace_fp, " \"%s\"", device);
    fprintf (trace_fp, " \"***\"");
    fprintf (trace_fp, " \"%s\"", mapname);
    guestfs___trace_send_line (g);
  }

  if (guestfs___check_appliance_up (g, "luks_open_ro") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "luks_open_ro", "-1");
    return -1;
  }

  args.device = (char *) device;
  args.key = (char *) key;
  args.mapname = (char *) mapname;
  serial = guestfs___send (g, GUESTFS_PROC_LUKS_OPEN_RO,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_luks_open_ro_args, (char *) &args);
  if (serial == -1) {
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
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "luks_open_ro", "-1");
    return -1;
  }

  if (guestfs___check_reply_header (g, &hdr, GUESTFS_PROC_LUKS_OPEN_RO, serial) == -1) {
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
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    trace_fp = guestfs___trace_open (g);
    fprintf (trace_fp, "%s = ", "luks_open_ro");
    fprintf (trace_fp, "%d", ret_v);
    guestfs___trace_send_line (g);
  }

  return ret_v;
}

GUESTFS_DLL_PUBLIC char *
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
    trace_fp = guestfs___trace_open (g);
    fprintf (trace_fp, "%s", "findfs_label");
    fprintf (trace_fp, " \"%s\"", label);
    guestfs___trace_send_line (g);
  }

  if (guestfs___check_appliance_up (g, "findfs_label") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "findfs_label", "NULL");
    return NULL;
  }

  args.label = (char *) label;
  serial = guestfs___send (g, GUESTFS_PROC_FINDFS_LABEL,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_findfs_label_args, (char *) &args);
  if (serial == -1) {
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
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "findfs_label", "NULL");
    return NULL;
  }

  if (guestfs___check_reply_header (g, &hdr, GUESTFS_PROC_FINDFS_LABEL, serial) == -1) {
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
    return NULL;
  }

  ret_v = ret.device; /* caller will free */
  if (trace_flag) {
    trace_fp = guestfs___trace_open (g);
    fprintf (trace_fp, "%s = ", "findfs_label");
    fprintf (trace_fp, "\"%s\"", ret_v);
    guestfs___trace_send_line (g);
  }

  return ret_v;
}

GUESTFS_DLL_PUBLIC int
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
    trace_fp = guestfs___trace_open (g);
    fprintf (trace_fp, "%s", "is_symlink");
    fprintf (trace_fp, " \"%s\"", path);
    guestfs___trace_send_line (g);
  }

  if (guestfs___check_appliance_up (g, "is_symlink") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "is_symlink", "-1");
    return -1;
  }

  args.path = (char *) path;
  serial = guestfs___send (g, GUESTFS_PROC_IS_SYMLINK,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_is_symlink_args, (char *) &args);
  if (serial == -1) {
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
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "is_symlink", "-1");
    return -1;
  }

  if (guestfs___check_reply_header (g, &hdr, GUESTFS_PROC_IS_SYMLINK, serial) == -1) {
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
    return -1;
  }

  ret_v = ret.flag;
  if (trace_flag) {
    trace_fp = guestfs___trace_open (g);
    fprintf (trace_fp, "%s = ", "is_symlink");
    fprintf (trace_fp, "%d", ret_v);
    guestfs___trace_send_line (g);
  }

  return ret_v;
}

GUESTFS_DLL_PUBLIC int
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
    trace_fp = guestfs___trace_open (g);
    fprintf (trace_fp, "%s", "is_zero");
    fprintf (trace_fp, " \"%s\"", path);
    guestfs___trace_send_line (g);
  }

  if (guestfs___check_appliance_up (g, "is_zero") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "is_zero", "-1");
    return -1;
  }

  args.path = (char *) path;
  serial = guestfs___send (g, GUESTFS_PROC_IS_ZERO,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_is_zero_args, (char *) &args);
  if (serial == -1) {
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
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "is_zero", "-1");
    return -1;
  }

  if (guestfs___check_reply_header (g, &hdr, GUESTFS_PROC_IS_ZERO, serial) == -1) {
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
    return -1;
  }

  ret_v = ret.zeroflag;
  if (trace_flag) {
    trace_fp = guestfs___trace_open (g);
    fprintf (trace_fp, "%s = ", "is_zero");
    fprintf (trace_fp, "%d", ret_v);
    guestfs___trace_send_line (g);
  }

  return ret_v;
}

GUESTFS_DLL_PUBLIC int
guestfs_copy_device_to_device_argv (guestfs_h *g,
                                    const char *src,
                                    const char *dest,
                                    const struct guestfs_copy_device_to_device_argv *optargs)
{
  struct guestfs_copy_device_to_device_argv optargs_null;
  if (!optargs) {
    optargs_null.bitmask = 0;
    optargs = &optargs_null;
  }

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
    trace_fp = guestfs___trace_open (g);
    fprintf (trace_fp, "%s", "copy_device_to_device");
    fprintf (trace_fp, " \"%s\"", src);
    fprintf (trace_fp, " \"%s\"", dest);
    if (optargs->bitmask & GUESTFS_COPY_DEVICE_TO_DEVICE_SRCOFFSET_BITMASK) {
      fprintf (trace_fp, " \"%s:%" PRIi64 "\"", "srcoffset", optargs->srcoffset);
    }
    if (optargs->bitmask & GUESTFS_COPY_DEVICE_TO_DEVICE_DESTOFFSET_BITMASK) {
      fprintf (trace_fp, " \"%s:%" PRIi64 "\"", "destoffset", optargs->destoffset);
    }
    if (optargs->bitmask & GUESTFS_COPY_DEVICE_TO_DEVICE_SIZE_BITMASK) {
      fprintf (trace_fp, " \"%s:%" PRIi64 "\"", "size", optargs->size);
    }
    guestfs___trace_send_line (g);
  }

  if (guestfs___check_appliance_up (g, "copy_device_to_device") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "copy_device_to_device", "-1");
    return -1;
  }

  args.src = (char *) src;
  args.dest = (char *) dest;
  if (optargs->bitmask & GUESTFS_COPY_DEVICE_TO_DEVICE_SRCOFFSET_BITMASK) {
    args.srcoffset = optargs->srcoffset;
  } else {
    args.srcoffset = 0;
  }
  if (optargs->bitmask & GUESTFS_COPY_DEVICE_TO_DEVICE_DESTOFFSET_BITMASK) {
    args.destoffset = optargs->destoffset;
  } else {
    args.destoffset = 0;
  }
  if (optargs->bitmask & GUESTFS_COPY_DEVICE_TO_DEVICE_SIZE_BITMASK) {
    args.size = optargs->size;
  } else {
    args.size = 0;
  }
  serial = guestfs___send (g, GUESTFS_PROC_COPY_DEVICE_TO_DEVICE,
                           progress_hint, optargs->bitmask,
                           (xdrproc_t) xdr_guestfs_copy_device_to_device_args, (char *) &args);
  if (serial == -1) {
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
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "copy_device_to_device", "-1");
    return -1;
  }

  if (guestfs___check_reply_header (g, &hdr, GUESTFS_PROC_COPY_DEVICE_TO_DEVICE, serial) == -1) {
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
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    trace_fp = guestfs___trace_open (g);
    fprintf (trace_fp, "%s = ", "copy_device_to_device");
    fprintf (trace_fp, "%d", ret_v);
    guestfs___trace_send_line (g);
  }

  return ret_v;
}

GUESTFS_DLL_PUBLIC int
guestfs_md_create_argv (guestfs_h *g,
                        const char *name,
                        char *const *devices,
                        const struct guestfs_md_create_argv *optargs)
{
  struct guestfs_md_create_argv optargs_null;
  if (!optargs) {
    optargs_null.bitmask = 0;
    optargs = &optargs_null;
  }

  struct guestfs_md_create_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "md_create", 9);
  if (name == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "md_create", "name");
    return -1;
  }
  if (devices == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "md_create", "devices");
    return -1;
  }
  if ((optargs->bitmask & GUESTFS_MD_CREATE_LEVEL_BITMASK) &&
      optargs->level == NULL) {
    error (g, "%s: %s: optional parameter cannot be NULL",
           "md_create", "level");
    return -1;
  }

  if (optargs->bitmask & UINT64_C(0xffffffffffffffe0)) {
    error (g, "%s: unknown option in guestfs_%s_argv->bitmask (this can happen if a program is compiled against a newer version of libguestfs, then dynamically linked to an older version)",
           "md_create", "md_create");
    return -1;
  }

  if (trace_flag) {
    size_t i;

    trace_fp = guestfs___trace_open (g);
    fprintf (trace_fp, "%s", "md_create");
    fprintf (trace_fp, " \"%s\"", name);
    fputc (' ', trace_fp);
    fputc ('"', trace_fp);
    for (i = 0; devices[i]; ++i) {
      if (i > 0) fputc (' ', trace_fp);
      fputs (devices[i], trace_fp);
    }
    fputc ('"', trace_fp);
    if (optargs->bitmask & GUESTFS_MD_CREATE_MISSINGBITMAP_BITMASK) {
      fprintf (trace_fp, " \"%s:%" PRIi64 "\"", "missingbitmap", optargs->missingbitmap);
    }
    if (optargs->bitmask & GUESTFS_MD_CREATE_NRDEVICES_BITMASK) {
      fprintf (trace_fp, " \"%s:%d\"", "nrdevices", optargs->nrdevices);
    }
    if (optargs->bitmask & GUESTFS_MD_CREATE_SPARE_BITMASK) {
      fprintf (trace_fp, " \"%s:%d\"", "spare", optargs->spare);
    }
    if (optargs->bitmask & GUESTFS_MD_CREATE_CHUNK_BITMASK) {
      fprintf (trace_fp, " \"%s:%" PRIi64 "\"", "chunk", optargs->chunk);
    }
    if (optargs->bitmask & GUESTFS_MD_CREATE_LEVEL_BITMASK) {
      fprintf (trace_fp, " \"%s:%s\"", "level", optargs->level);
    }
    guestfs___trace_send_line (g);
  }

  if (guestfs___check_appliance_up (g, "md_create") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "md_create", "-1");
    return -1;
  }

  args.name = (char *) name;
  args.devices.devices_val = (char **) devices;
  for (args.devices.devices_len = 0; devices[args.devices.devices_len]; args.devices.devices_len++) ;
  if (optargs->bitmask & GUESTFS_MD_CREATE_MISSINGBITMAP_BITMASK) {
    args.missingbitmap = optargs->missingbitmap;
  } else {
    args.missingbitmap = 0;
  }
  if (optargs->bitmask & GUESTFS_MD_CREATE_NRDEVICES_BITMASK) {
    args.nrdevices = optargs->nrdevices;
  } else {
    args.nrdevices = 0;
  }
  if (optargs->bitmask & GUESTFS_MD_CREATE_SPARE_BITMASK) {
    args.spare = optargs->spare;
  } else {
    args.spare = 0;
  }
  if (optargs->bitmask & GUESTFS_MD_CREATE_CHUNK_BITMASK) {
    args.chunk = optargs->chunk;
  } else {
    args.chunk = 0;
  }
  if (optargs->bitmask & GUESTFS_MD_CREATE_LEVEL_BITMASK) {
    args.level = (char *) optargs->level;
  } else {
    args.level = (char *) "";
  }
  serial = guestfs___send (g, GUESTFS_PROC_MD_CREATE,
                           progress_hint, optargs->bitmask,
                           (xdrproc_t) xdr_guestfs_md_create_args, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "md_create", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "md_create", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "md_create", "-1");
    return -1;
  }

  if (guestfs___check_reply_header (g, &hdr, GUESTFS_PROC_MD_CREATE, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "md_create", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "md_create", "-1");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "md_create", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "md_create",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    trace_fp = guestfs___trace_open (g);
    fprintf (trace_fp, "%s = ", "md_create");
    fprintf (trace_fp, "%d", ret_v);
    guestfs___trace_send_line (g);
  }

  return ret_v;
}

GUESTFS_DLL_PUBLIC char *
guestfs_llz (guestfs_h *g,
             const char *directory)
{
  struct guestfs_llz_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  struct guestfs_llz_ret ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  char *ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "llz", 3);
  if (directory == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "llz", "directory");
    return NULL;
  }

  if (trace_flag) {
    trace_fp = guestfs___trace_open (g);
    fprintf (trace_fp, "%s", "llz");
    fprintf (trace_fp, " \"%s\"", directory);
    guestfs___trace_send_line (g);
  }

  if (guestfs___check_appliance_up (g, "llz") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "llz", "NULL");
    return NULL;
  }

  args.directory = (char *) directory;
  serial = guestfs___send (g, GUESTFS_PROC_LLZ,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_llz_args, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "llz", "NULL");
    return NULL;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs___recv (g, "llz", &hdr, &err,
        (xdrproc_t) xdr_guestfs_llz_ret, (char *) &ret);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "llz", "NULL");
    return NULL;
  }

  if (guestfs___check_reply_header (g, &hdr, GUESTFS_PROC_LLZ, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "llz", "NULL");
    return NULL;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "llz", "NULL");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "llz", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "llz",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    return NULL;
  }

  ret_v = ret.listing; /* caller will free */
  if (trace_flag) {
    trace_fp = guestfs___trace_open (g);
    fprintf (trace_fp, "%s = ", "llz");
    fprintf (trace_fp, "\"%s\"", ret_v);
    guestfs___trace_send_line (g);
  }

  return ret_v;
}

GUESTFS_DLL_PUBLIC int
guestfs_ntfsclone_out_argv (guestfs_h *g,
                            const char *device,
                            const char *backupfile,
                            const struct guestfs_ntfsclone_out_argv *optargs)
{
  struct guestfs_ntfsclone_out_argv optargs_null;
  if (!optargs) {
    optargs_null.bitmask = 0;
    optargs = &optargs_null;
  }

  struct guestfs_ntfsclone_out_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "ntfsclone_out", 13);
  if (device == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "ntfsclone_out", "device");
    return -1;
  }
  if (backupfile == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "ntfsclone_out", "backupfile");
    return -1;
  }

  if (optargs->bitmask & UINT64_C(0xffffffffffffffe0)) {
    error (g, "%s: unknown option in guestfs_%s_argv->bitmask (this can happen if a program is compiled against a newer version of libguestfs, then dynamically linked to an older version)",
           "ntfsclone_out", "ntfsclone_out");
    return -1;
  }

  if (trace_flag) {
    trace_fp = guestfs___trace_open (g);
    fprintf (trace_fp, "%s", "ntfsclone_out");
    fprintf (trace_fp, " \"%s\"", device);
    fprintf (trace_fp, " \"%s\"", backupfile);
    if (optargs->bitmask & GUESTFS_NTFSCLONE_OUT_METADATAONLY_BITMASK) {
      fprintf (trace_fp, " \"%s:%s\"", "metadataonly", optargs->metadataonly ? "true" : "false");
    }
    if (optargs->bitmask & GUESTFS_NTFSCLONE_OUT_RESCUE_BITMASK) {
      fprintf (trace_fp, " \"%s:%s\"", "rescue", optargs->rescue ? "true" : "false");
    }
    if (optargs->bitmask & GUESTFS_NTFSCLONE_OUT_IGNOREFSCHECK_BITMASK) {
      fprintf (trace_fp, " \"%s:%s\"", "ignorefscheck", optargs->ignorefscheck ? "true" : "false");
    }
    if (optargs->bitmask & GUESTFS_NTFSCLONE_OUT_PRESERVETIMESTAMPS_BITMASK) {
      fprintf (trace_fp, " \"%s:%s\"", "preservetimestamps", optargs->preservetimestamps ? "true" : "false");
    }
    if (optargs->bitmask & GUESTFS_NTFSCLONE_OUT_FORCE_BITMASK) {
      fprintf (trace_fp, " \"%s:%s\"", "force", optargs->force ? "true" : "false");
    }
    guestfs___trace_send_line (g);
  }

  if (guestfs___check_appliance_up (g, "ntfsclone_out") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "ntfsclone_out", "-1");
    return -1;
  }

  args.device = (char *) device;
  if (optargs->bitmask & GUESTFS_NTFSCLONE_OUT_METADATAONLY_BITMASK) {
    args.metadataonly = optargs->metadataonly;
  } else {
    args.metadataonly = 0;
  }
  if (optargs->bitmask & GUESTFS_NTFSCLONE_OUT_RESCUE_BITMASK) {
    args.rescue = optargs->rescue;
  } else {
    args.rescue = 0;
  }
  if (optargs->bitmask & GUESTFS_NTFSCLONE_OUT_IGNOREFSCHECK_BITMASK) {
    args.ignorefscheck = optargs->ignorefscheck;
  } else {
    args.ignorefscheck = 0;
  }
  if (optargs->bitmask & GUESTFS_NTFSCLONE_OUT_PRESERVETIMESTAMPS_BITMASK) {
    args.preservetimestamps = optargs->preservetimestamps;
  } else {
    args.preservetimestamps = 0;
  }
  if (optargs->bitmask & GUESTFS_NTFSCLONE_OUT_FORCE_BITMASK) {
    args.force = optargs->force;
  } else {
    args.force = 0;
  }
  serial = guestfs___send (g, GUESTFS_PROC_NTFSCLONE_OUT,
                           progress_hint, optargs->bitmask,
                           (xdrproc_t) xdr_guestfs_ntfsclone_out_args, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "ntfsclone_out", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "ntfsclone_out", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "ntfsclone_out", "-1");
    return -1;
  }

  if (guestfs___check_reply_header (g, &hdr, GUESTFS_PROC_NTFSCLONE_OUT, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "ntfsclone_out", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "ntfsclone_out", "-1");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "ntfsclone_out", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "ntfsclone_out",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    return -1;
  }

  if (guestfs___recv_file (g, backupfile) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "ntfsclone_out", "-1");
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    trace_fp = guestfs___trace_open (g);
    fprintf (trace_fp, "%s = ", "ntfsclone_out");
    fprintf (trace_fp, "%d", ret_v);
    guestfs___trace_send_line (g);
  }

  return ret_v;
}

GUESTFS_DLL_PUBLIC int
guestfs_btrfs_fsck_argv (guestfs_h *g,
                         const char *device,
                         const struct guestfs_btrfs_fsck_argv *optargs)
{
  struct guestfs_btrfs_fsck_argv optargs_null;
  if (!optargs) {
    optargs_null.bitmask = 0;
    optargs = &optargs_null;
  }

  struct guestfs_btrfs_fsck_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "btrfs_fsck", 10);
  if (device == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "btrfs_fsck", "device");
    return -1;
  }

  if (optargs->bitmask & UINT64_C(0xfffffffffffffffc)) {
    error (g, "%s: unknown option in guestfs_%s_argv->bitmask (this can happen if a program is compiled against a newer version of libguestfs, then dynamically linked to an older version)",
           "btrfs_fsck", "btrfs_fsck");
    return -1;
  }

  if (trace_flag) {
    trace_fp = guestfs___trace_open (g);
    fprintf (trace_fp, "%s", "btrfs_fsck");
    fprintf (trace_fp, " \"%s\"", device);
    if (optargs->bitmask & GUESTFS_BTRFS_FSCK_SUPERBLOCK_BITMASK) {
      fprintf (trace_fp, " \"%s:%" PRIi64 "\"", "superblock", optargs->superblock);
    }
    if (optargs->bitmask & GUESTFS_BTRFS_FSCK_REPAIR_BITMASK) {
      fprintf (trace_fp, " \"%s:%s\"", "repair", optargs->repair ? "true" : "false");
    }
    guestfs___trace_send_line (g);
  }

  if (guestfs___check_appliance_up (g, "btrfs_fsck") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "btrfs_fsck", "-1");
    return -1;
  }

  args.device = (char *) device;
  if (optargs->bitmask & GUESTFS_BTRFS_FSCK_SUPERBLOCK_BITMASK) {
    args.superblock = optargs->superblock;
  } else {
    args.superblock = 0;
  }
  if (optargs->bitmask & GUESTFS_BTRFS_FSCK_REPAIR_BITMASK) {
    args.repair = optargs->repair;
  } else {
    args.repair = 0;
  }
  serial = guestfs___send (g, GUESTFS_PROC_BTRFS_FSCK,
                           progress_hint, optargs->bitmask,
                           (xdrproc_t) xdr_guestfs_btrfs_fsck_args, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "btrfs_fsck", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "btrfs_fsck", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "btrfs_fsck", "-1");
    return -1;
  }

  if (guestfs___check_reply_header (g, &hdr, GUESTFS_PROC_BTRFS_FSCK, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "btrfs_fsck", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "btrfs_fsck", "-1");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "btrfs_fsck", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "btrfs_fsck",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    trace_fp = guestfs___trace_open (g);
    fprintf (trace_fp, "%s = ", "btrfs_fsck");
    fprintf (trace_fp, "%d", ret_v);
    guestfs___trace_send_line (g);
  }

  return ret_v;
}

GUESTFS_DLL_PUBLIC int
guestfs_device_index (guestfs_h *g,
                      const char *device)
{
  struct guestfs_device_index_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  struct guestfs_device_index_ret ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "device_index", 12);
  if (device == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "device_index", "device");
    return -1;
  }

  if (trace_flag) {
    trace_fp = guestfs___trace_open (g);
    fprintf (trace_fp, "%s", "device_index");
    fprintf (trace_fp, " \"%s\"", device);
    guestfs___trace_send_line (g);
  }

  if (guestfs___check_appliance_up (g, "device_index") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "device_index", "-1");
    return -1;
  }

  args.device = (char *) device;
  serial = guestfs___send (g, GUESTFS_PROC_DEVICE_INDEX,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_device_index_args, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "device_index", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs___recv (g, "device_index", &hdr, &err,
        (xdrproc_t) xdr_guestfs_device_index_ret, (char *) &ret);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "device_index", "-1");
    return -1;
  }

  if (guestfs___check_reply_header (g, &hdr, GUESTFS_PROC_DEVICE_INDEX, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "device_index", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "device_index", "-1");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "device_index", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "device_index",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    return -1;
  }

  ret_v = ret.index;
  if (trace_flag) {
    trace_fp = guestfs___trace_open (g);
    fprintf (trace_fp, "%s = ", "device_index");
    fprintf (trace_fp, "%d", ret_v);
    guestfs___trace_send_line (g);
  }

  return ret_v;
}

GUESTFS_DLL_PUBLIC int
guestfs_fill_dir (guestfs_h *g,
                  const char *dir,
                  int nr)
{
  struct guestfs_fill_dir_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "fill_dir", 8);
  if (dir == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "fill_dir", "dir");
    return -1;
  }

  if (trace_flag) {
    trace_fp = guestfs___trace_open (g);
    fprintf (trace_fp, "%s", "fill_dir");
    fprintf (trace_fp, " \"%s\"", dir);
    fprintf (trace_fp, " %d", nr);
    guestfs___trace_send_line (g);
  }

  if (guestfs___check_appliance_up (g, "fill_dir") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "fill_dir", "-1");
    return -1;
  }

  args.dir = (char *) dir;
  args.nr = nr;
  serial = guestfs___send (g, GUESTFS_PROC_FILL_DIR,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_fill_dir_args, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "fill_dir", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "fill_dir", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "fill_dir", "-1");
    return -1;
  }

  if (guestfs___check_reply_header (g, &hdr, GUESTFS_PROC_FILL_DIR, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "fill_dir", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "fill_dir", "-1");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "fill_dir", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "fill_dir",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    trace_fp = guestfs___trace_open (g);
    fprintf (trace_fp, "%s = ", "fill_dir");
    fprintf (trace_fp, "%d", ret_v);
    guestfs___trace_send_line (g);
  }

  return ret_v;
}

GUESTFS_DLL_PUBLIC int
guestfs_xfs_admin_argv (guestfs_h *g,
                        const char *device,
                        const struct guestfs_xfs_admin_argv *optargs)
{
  struct guestfs_xfs_admin_argv optargs_null;
  if (!optargs) {
    optargs_null.bitmask = 0;
    optargs = &optargs_null;
  }

  struct guestfs_xfs_admin_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "xfs_admin", 9);
  if (device == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "xfs_admin", "device");
    return -1;
  }
  if ((optargs->bitmask & GUESTFS_XFS_ADMIN_LABEL_BITMASK) &&
      optargs->label == NULL) {
    error (g, "%s: %s: optional parameter cannot be NULL",
           "xfs_admin", "label");
    return -1;
  }
  if ((optargs->bitmask & GUESTFS_XFS_ADMIN_UUID_BITMASK) &&
      optargs->uuid == NULL) {
    error (g, "%s: %s: optional parameter cannot be NULL",
           "xfs_admin", "uuid");
    return -1;
  }

  if (optargs->bitmask & UINT64_C(0xffffffffffffff80)) {
    error (g, "%s: unknown option in guestfs_%s_argv->bitmask (this can happen if a program is compiled against a newer version of libguestfs, then dynamically linked to an older version)",
           "xfs_admin", "xfs_admin");
    return -1;
  }

  if (trace_flag) {
    trace_fp = guestfs___trace_open (g);
    fprintf (trace_fp, "%s", "xfs_admin");
    fprintf (trace_fp, " \"%s\"", device);
    if (optargs->bitmask & GUESTFS_XFS_ADMIN_EXTUNWRITTEN_BITMASK) {
      fprintf (trace_fp, " \"%s:%s\"", "extunwritten", optargs->extunwritten ? "true" : "false");
    }
    if (optargs->bitmask & GUESTFS_XFS_ADMIN_IMGFILE_BITMASK) {
      fprintf (trace_fp, " \"%s:%s\"", "imgfile", optargs->imgfile ? "true" : "false");
    }
    if (optargs->bitmask & GUESTFS_XFS_ADMIN_V2LOG_BITMASK) {
      fprintf (trace_fp, " \"%s:%s\"", "v2log", optargs->v2log ? "true" : "false");
    }
    if (optargs->bitmask & GUESTFS_XFS_ADMIN_PROJID32BIT_BITMASK) {
      fprintf (trace_fp, " \"%s:%s\"", "projid32bit", optargs->projid32bit ? "true" : "false");
    }
    if (optargs->bitmask & GUESTFS_XFS_ADMIN_LAZYCOUNTER_BITMASK) {
      fprintf (trace_fp, " \"%s:%s\"", "lazycounter", optargs->lazycounter ? "true" : "false");
    }
    if (optargs->bitmask & GUESTFS_XFS_ADMIN_LABEL_BITMASK) {
      fprintf (trace_fp, " \"%s:%s\"", "label", optargs->label);
    }
    if (optargs->bitmask & GUESTFS_XFS_ADMIN_UUID_BITMASK) {
      fprintf (trace_fp, " \"%s:%s\"", "uuid", optargs->uuid);
    }
    guestfs___trace_send_line (g);
  }

  if (guestfs___check_appliance_up (g, "xfs_admin") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "xfs_admin", "-1");
    return -1;
  }

  args.device = (char *) device;
  if (optargs->bitmask & GUESTFS_XFS_ADMIN_EXTUNWRITTEN_BITMASK) {
    args.extunwritten = optargs->extunwritten;
  } else {
    args.extunwritten = 0;
  }
  if (optargs->bitmask & GUESTFS_XFS_ADMIN_IMGFILE_BITMASK) {
    args.imgfile = optargs->imgfile;
  } else {
    args.imgfile = 0;
  }
  if (optargs->bitmask & GUESTFS_XFS_ADMIN_V2LOG_BITMASK) {
    args.v2log = optargs->v2log;
  } else {
    args.v2log = 0;
  }
  if (optargs->bitmask & GUESTFS_XFS_ADMIN_PROJID32BIT_BITMASK) {
    args.projid32bit = optargs->projid32bit;
  } else {
    args.projid32bit = 0;
  }
  if (optargs->bitmask & GUESTFS_XFS_ADMIN_LAZYCOUNTER_BITMASK) {
    args.lazycounter = optargs->lazycounter;
  } else {
    args.lazycounter = 0;
  }
  if (optargs->bitmask & GUESTFS_XFS_ADMIN_LABEL_BITMASK) {
    args.label = (char *) optargs->label;
  } else {
    args.label = (char *) "";
  }
  if (optargs->bitmask & GUESTFS_XFS_ADMIN_UUID_BITMASK) {
    args.uuid = (char *) optargs->uuid;
  } else {
    args.uuid = (char *) "";
  }
  serial = guestfs___send (g, GUESTFS_PROC_XFS_ADMIN,
                           progress_hint, optargs->bitmask,
                           (xdrproc_t) xdr_guestfs_xfs_admin_args, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "xfs_admin", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "xfs_admin", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "xfs_admin", "-1");
    return -1;
  }

  if (guestfs___check_reply_header (g, &hdr, GUESTFS_PROC_XFS_ADMIN, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "xfs_admin", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "xfs_admin", "-1");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "xfs_admin", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "xfs_admin",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    trace_fp = guestfs___trace_open (g);
    fprintf (trace_fp, "%s = ", "xfs_admin");
    fprintf (trace_fp, "%d", ret_v);
    guestfs___trace_send_line (g);
  }

  return ret_v;
}

GUESTFS_DLL_PUBLIC int64_t
guestfs_hivex_root (guestfs_h *g)
{
  guestfs_message_header hdr;
  guestfs_message_error err;
  struct guestfs_hivex_root_ret ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  int64_t ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "hivex_root", 10);
  if (trace_flag) {
    trace_fp = guestfs___trace_open (g);
    fprintf (trace_fp, "%s", "hivex_root");
    guestfs___trace_send_line (g);
  }

  if (guestfs___check_appliance_up (g, "hivex_root") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "hivex_root", "-1");
    return -1;
  }

  serial = guestfs___send (g, GUESTFS_PROC_HIVEX_ROOT, progress_hint, 0,
                           NULL, NULL);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "hivex_root", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs___recv (g, "hivex_root", &hdr, &err,
        (xdrproc_t) xdr_guestfs_hivex_root_ret, (char *) &ret);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "hivex_root", "-1");
    return -1;
  }

  if (guestfs___check_reply_header (g, &hdr, GUESTFS_PROC_HIVEX_ROOT, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "hivex_root", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "hivex_root", "-1");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "hivex_root", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "hivex_root",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    return -1;
  }

  ret_v = ret.nodeh;
  if (trace_flag) {
    trace_fp = guestfs___trace_open (g);
    fprintf (trace_fp, "%s = ", "hivex_root");
    fprintf (trace_fp, "%" PRIi64, ret_v);
    guestfs___trace_send_line (g);
  }

  return ret_v;
}

GUESTFS_DLL_PUBLIC int64_t
guestfs_hivex_node_parent (guestfs_h *g,
                           int64_t nodeh)
{
  struct guestfs_hivex_node_parent_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  struct guestfs_hivex_node_parent_ret ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  int64_t ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "hivex_node_parent", 17);
  if (trace_flag) {
    trace_fp = guestfs___trace_open (g);
    fprintf (trace_fp, "%s", "hivex_node_parent");
    fprintf (trace_fp, " %" PRIi64, nodeh);
    guestfs___trace_send_line (g);
  }

  if (guestfs___check_appliance_up (g, "hivex_node_parent") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "hivex_node_parent", "-1");
    return -1;
  }

  args.nodeh = nodeh;
  serial = guestfs___send (g, GUESTFS_PROC_HIVEX_NODE_PARENT,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_hivex_node_parent_args, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "hivex_node_parent", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs___recv (g, "hivex_node_parent", &hdr, &err,
        (xdrproc_t) xdr_guestfs_hivex_node_parent_ret, (char *) &ret);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "hivex_node_parent", "-1");
    return -1;
  }

  if (guestfs___check_reply_header (g, &hdr, GUESTFS_PROC_HIVEX_NODE_PARENT, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "hivex_node_parent", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "hivex_node_parent", "-1");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "hivex_node_parent", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "hivex_node_parent",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    return -1;
  }

  ret_v = ret.parent;
  if (trace_flag) {
    trace_fp = guestfs___trace_open (g);
    fprintf (trace_fp, "%s = ", "hivex_node_parent");
    fprintf (trace_fp, "%" PRIi64, ret_v);
    guestfs___trace_send_line (g);
  }

  return ret_v;
}

GUESTFS_DLL_PUBLIC char *
guestfs_hivex_value_value (guestfs_h *g,
                           int64_t valueh,
                           size_t *size_r)
{
  struct guestfs_hivex_value_value_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  struct guestfs_hivex_value_value_ret ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  char *ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "hivex_value_value", 17);
  if (trace_flag) {
    trace_fp = guestfs___trace_open (g);
    fprintf (trace_fp, "%s", "hivex_value_value");
    fprintf (trace_fp, " %" PRIi64, valueh);
    guestfs___trace_send_line (g);
  }

  if (guestfs___check_appliance_up (g, "hivex_value_value") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "hivex_value_value", "NULL");
    return NULL;
  }

  args.valueh = valueh;
  serial = guestfs___send (g, GUESTFS_PROC_HIVEX_VALUE_VALUE,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_hivex_value_value_args, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "hivex_value_value", "NULL");
    return NULL;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs___recv (g, "hivex_value_value", &hdr, &err,
        (xdrproc_t) xdr_guestfs_hivex_value_value_ret, (char *) &ret);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "hivex_value_value", "NULL");
    return NULL;
  }

  if (guestfs___check_reply_header (g, &hdr, GUESTFS_PROC_HIVEX_VALUE_VALUE, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "hivex_value_value", "NULL");
    return NULL;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "hivex_value_value", "NULL");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "hivex_value_value", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "hivex_value_value",
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
  if (ret.databuf.databuf_len > 0) {
    *size_r = ret.databuf.databuf_len;
    ret_v = ret.databuf.databuf_val; /* caller will free */
  } else {
    free (ret.databuf.databuf_val);
    char *p = safe_malloc (g, 1);
    *size_r = ret.databuf.databuf_len;
    ret_v = p;
  }
  if (trace_flag) {
    trace_fp = guestfs___trace_open (g);
    fprintf (trace_fp, "%s = ", "hivex_value_value");
    guestfs___print_BufferOut (trace_fp, ret_v, *size_r);
    guestfs___trace_send_line (g);
  }

  return ret_v;
}

GUESTFS_DLL_PUBLIC int
guestfs_ldmtool_create_all (guestfs_h *g)
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
                                    "ldmtool_create_all", 18);
  if (trace_flag) {
    trace_fp = guestfs___trace_open (g);
    fprintf (trace_fp, "%s", "ldmtool_create_all");
    guestfs___trace_send_line (g);
  }

  if (guestfs___check_appliance_up (g, "ldmtool_create_all") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "ldmtool_create_all", "-1");
    return -1;
  }

  serial = guestfs___send (g, GUESTFS_PROC_LDMTOOL_CREATE_ALL, progress_hint, 0,
                           NULL, NULL);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "ldmtool_create_all", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "ldmtool_create_all", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "ldmtool_create_all", "-1");
    return -1;
  }

  if (guestfs___check_reply_header (g, &hdr, GUESTFS_PROC_LDMTOOL_CREATE_ALL, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "ldmtool_create_all", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "ldmtool_create_all", "-1");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "ldmtool_create_all", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "ldmtool_create_all",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    trace_fp = guestfs___trace_open (g);
    fprintf (trace_fp, "%s = ", "ldmtool_create_all");
    fprintf (trace_fp, "%d", ret_v);
    guestfs___trace_send_line (g);
  }

  return ret_v;
}

GUESTFS_DLL_PUBLIC char **
guestfs_ldmtool_diskgroup_disks (guestfs_h *g,
                                 const char *diskgroup)
{
  struct guestfs_ldmtool_diskgroup_disks_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  struct guestfs_ldmtool_diskgroup_disks_ret ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  char **ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "ldmtool_diskgroup_disks", 23);
  if (diskgroup == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "ldmtool_diskgroup_disks", "diskgroup");
    return NULL;
  }

  if (trace_flag) {
    trace_fp = guestfs___trace_open (g);
    fprintf (trace_fp, "%s", "ldmtool_diskgroup_disks");
    fprintf (trace_fp, " \"%s\"", diskgroup);
    guestfs___trace_send_line (g);
  }

  if (guestfs___check_appliance_up (g, "ldmtool_diskgroup_disks") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "ldmtool_diskgroup_disks", "NULL");
    return NULL;
  }

  args.diskgroup = (char *) diskgroup;
  serial = guestfs___send (g, GUESTFS_PROC_LDMTOOL_DISKGROUP_DISKS,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_ldmtool_diskgroup_disks_args, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "ldmtool_diskgroup_disks", "NULL");
    return NULL;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs___recv (g, "ldmtool_diskgroup_disks", &hdr, &err,
        (xdrproc_t) xdr_guestfs_ldmtool_diskgroup_disks_ret, (char *) &ret);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "ldmtool_diskgroup_disks", "NULL");
    return NULL;
  }

  if (guestfs___check_reply_header (g, &hdr, GUESTFS_PROC_LDMTOOL_DISKGROUP_DISKS, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "ldmtool_diskgroup_disks", "NULL");
    return NULL;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "ldmtool_diskgroup_disks", "NULL");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "ldmtool_diskgroup_disks", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "ldmtool_diskgroup_disks",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    return NULL;
  }

  /* caller will free this, but we need to add a NULL entry */
  ret.disks.disks_val =
    safe_realloc (g, ret.disks.disks_val,
                  sizeof (char *) * (ret.disks.disks_len + 1));
  ret.disks.disks_val[ret.disks.disks_len] = NULL;
  ret_v = ret.disks.disks_val;
  if (trace_flag) {
    size_t i;

    trace_fp = guestfs___trace_open (g);
    fprintf (trace_fp, "%s = ", "ldmtool_diskgroup_disks");
    fputs ("[", trace_fp);
    for (i = 0; ret_v[i]; ++i) {
      if (i > 0) fputs (", ", trace_fp);
      fputs ("\"", trace_fp);
      fputs (ret_v[i], trace_fp);
      fputs ("\"", trace_fp);
    }
    fputs ("]", trace_fp);
    guestfs___trace_send_line (g);
  }

  return ret_v;
}

