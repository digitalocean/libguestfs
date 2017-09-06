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

GUESTFS_DLL_PUBLIC char *
guestfs_cat (guestfs_h *g,
             const char *path)
{
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  char *r;

  guestfs_int_call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                      "cat", 3);
  if (path == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "cat", "path");
    return NULL;
  }

  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "cat");
    fprintf (trace_buffer.fp, " \"%s\"", path);
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  r = guestfs_impl_cat (g, path);

  if (r != NULL) {
    if (trace_flag) {
      guestfs_int_trace_open (&trace_buffer);
      fprintf (trace_buffer.fp, "%s = ", "cat");
      fprintf (trace_buffer.fp, "\"%s\"", r);
      guestfs_int_trace_send_line (g, &trace_buffer);
    }

  } else {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "cat", "NULL");
  }

  return r;
}

GUESTFS_DLL_PUBLIC int
guestfs_clear_backend_setting (guestfs_h *g,
                               const char *name)
{
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int r;

  if (g->state != CONFIG) {
    error (g, "%s: this function can only be called in the config state",
              "clear_backend_setting");
    return -1;
  }
  guestfs_int_call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                      "clear_backend_setting", 21);
  if (name == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "clear_backend_setting", "name");
    return -1;
  }

  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "clear_backend_setting");
    fprintf (trace_buffer.fp, " \"%s\"", name);
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  r = guestfs_impl_clear_backend_setting (g, name);

  if (r != -1) {
    if (trace_flag) {
      guestfs_int_trace_open (&trace_buffer);
      fprintf (trace_buffer.fp, "%s = ", "clear_backend_setting");
      fprintf (trace_buffer.fp, "%d", r);
      guestfs_int_trace_send_line (g, &trace_buffer);
    }

  } else {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "clear_backend_setting", "-1");
  }

  return r;
}

GUESTFS_DLL_PUBLIC int
guestfs_config (guestfs_h *g,
                const char *hvparam,
                const char *hvvalue)
{
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int r;

  if (g->state != CONFIG) {
    error (g, "%s: this function can only be called in the config state",
              "config");
    return -1;
  }
  guestfs_int_call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                      "config", 6);
  if (hvparam == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "config", "hvparam");
    return -1;
  }

  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "config");
    fprintf (trace_buffer.fp, " \"%s\"", hvparam);
    if (hvvalue)
      fprintf (trace_buffer.fp, " \"%s\"", hvvalue);
    else
      fprintf (trace_buffer.fp, " null");
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  r = guestfs_impl_config (g, hvparam, hvvalue);

  if (r != -1) {
    if (trace_flag) {
      guestfs_int_trace_open (&trace_buffer);
      fprintf (trace_buffer.fp, "%s = ", "config");
      fprintf (trace_buffer.fp, "%d", r);
      guestfs_int_trace_send_line (g, &trace_buffer);
    }

  } else {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "config", "-1");
  }

  return r;
}

GUESTFS_DLL_PUBLIC char **
guestfs_debug_drives (guestfs_h *g)
{
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  char **r;

  guestfs_int_call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                      "debug_drives", 12);
  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "debug_drives");
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  r = guestfs_impl_debug_drives (g);

  if (r != NULL) {
    if (trace_flag) {
      size_t i;

      guestfs_int_trace_open (&trace_buffer);
      fprintf (trace_buffer.fp, "%s = ", "debug_drives");
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
                         "debug_drives", "NULL");
  }

  return r;
}

GUESTFS_DLL_PUBLIC struct guestfs_tsk_dirent_list *
guestfs_filesystem_walk (guestfs_h *g,
                         const char *device)
{
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  struct guestfs_tsk_dirent_list *r;

  guestfs_int_call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                      "filesystem_walk", 15);
  if (device == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "filesystem_walk", "device");
    return NULL;
  }

  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "filesystem_walk");
    fprintf (trace_buffer.fp, " \"%s\"", device);
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  r = guestfs_impl_filesystem_walk (g, device);

  if (r != NULL) {
    if (trace_flag) {
      size_t i;

      guestfs_int_trace_open (&trace_buffer);
      fprintf (trace_buffer.fp, "%s = ", "filesystem_walk");
      fprintf (trace_buffer.fp, "<struct guestfs_tsk_dirent_list(%u)", r->len);
      if (r->len > 0)
        fprintf (trace_buffer.fp, " = ");
      for (i = 0; i < r->len; ++i) {
        if (i != 0)
          fprintf (trace_buffer.fp, " ");
        fprintf (trace_buffer.fp, "[%zu]{", i);
        guestfs_int_print_tsk_dirent_indent (&r->val[i], trace_buffer.fp, ", ", "");
        fprintf (trace_buffer.fp, "}");
      }
      fprintf (trace_buffer.fp, ">");
      guestfs_int_trace_send_line (g, &trace_buffer);
    }

  } else {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "filesystem_walk", "NULL");
  }

  return r;
}

GUESTFS_DLL_PUBLIC const char *
guestfs_get_identifier (guestfs_h *g)
{
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  const char *r;

  guestfs_int_call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                      "get_identifier", 14);
  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "get_identifier");
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  r = guestfs_impl_get_identifier (g);

  if (r != NULL) {
    if (trace_flag) {
      guestfs_int_trace_open (&trace_buffer);
      fprintf (trace_buffer.fp, "%s = ", "get_identifier");
      fprintf (trace_buffer.fp, "\"%s\"", r);
      guestfs_int_trace_send_line (g, &trace_buffer);
    }

  } else {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "get_identifier", "NULL");
  }

  return r;
}

GUESTFS_DLL_PUBLIC char *
guestfs_get_libvirt_requested_credential_prompt (guestfs_h *g,
                                                 int index)
{
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  char *r;

  guestfs_int_call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                      "get_libvirt_requested_credential_prompt", 39);
  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "get_libvirt_requested_credential_prompt");
    fprintf (trace_buffer.fp, " %d", index);
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  r = guestfs_impl_get_libvirt_requested_credential_prompt (g, index);

  if (r != NULL) {
    if (trace_flag) {
      guestfs_int_trace_open (&trace_buffer);
      fprintf (trace_buffer.fp, "%s = ", "get_libvirt_requested_credential_prompt");
      fprintf (trace_buffer.fp, "\"%s\"", r);
      guestfs_int_trace_send_line (g, &trace_buffer);
    }

  } else {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "get_libvirt_requested_credential_prompt", "NULL");
  }

  return r;
}

GUESTFS_DLL_PUBLIC int
guestfs_get_network (guestfs_h *g)
{
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int r;

  guestfs_int_call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                      "get_network", 11);
  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "get_network");
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  r = guestfs_impl_get_network (g);

  if (r != -1) {
    if (trace_flag) {
      guestfs_int_trace_open (&trace_buffer);
      fprintf (trace_buffer.fp, "%s = ", "get_network");
      fprintf (trace_buffer.fp, "%d", r);
      guestfs_int_trace_send_line (g, &trace_buffer);
    }

  } else {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "get_network", "-1");
  }

  return r;
}

GUESTFS_DLL_PUBLIC const char *
guestfs_get_qemu (guestfs_h *g)
{
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  const char *r;

  guestfs_int_call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                      "get_qemu", 8);
  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "get_qemu");
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  r = guestfs_impl_get_qemu (g);

  if (r != NULL) {
    if (trace_flag) {
      guestfs_int_trace_open (&trace_buffer);
      fprintf (trace_buffer.fp, "%s = ", "get_qemu");
      fprintf (trace_buffer.fp, "\"%s\"", r);
      guestfs_int_trace_send_line (g, &trace_buffer);
    }

  } else {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "get_qemu", "NULL");
  }

  return r;
}

GUESTFS_DLL_PUBLIC int
guestfs_get_state (guestfs_h *g)
{
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int r;

  guestfs_int_call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                      "get_state", 9);
  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "get_state");
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  r = guestfs_impl_get_state (g);

  if (r != -1) {
    if (trace_flag) {
      guestfs_int_trace_open (&trace_buffer);
      fprintf (trace_buffer.fp, "%s = ", "get_state");
      fprintf (trace_buffer.fp, "%d", r);
      guestfs_int_trace_send_line (g, &trace_buffer);
    }

  } else {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "get_state", "-1");
  }

  return r;
}

GUESTFS_DLL_PUBLIC int
guestfs_get_verbose (guestfs_h *g)
{
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int r;

  guestfs_int_call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                      "get_verbose", 11);
  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "get_verbose");
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  r = guestfs_impl_get_verbose (g);

  if (r != -1) {
    if (trace_flag) {
      guestfs_int_trace_open (&trace_buffer);
      fprintf (trace_buffer.fp, "%s = ", "get_verbose");
      fprintf (trace_buffer.fp, "%d", r);
      guestfs_int_trace_send_line (g, &trace_buffer);
    }

  } else {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "get_verbose", "-1");
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
  struct trace_buffer trace_buffer;
  char *r;

  guestfs_int_call_callbacks_message (g, GUESTFS_EVENT_ENTER,
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
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "inspect_get_icon");
    fprintf (trace_buffer.fp, " \"%s\"", root);
    if (optargs->bitmask & GUESTFS_INSPECT_GET_ICON_FAVICON_BITMASK) {
      fprintf (trace_buffer.fp, " \"%s:%s\"", "favicon", optargs->favicon ? "true" : "false");
    }
    if (optargs->bitmask & GUESTFS_INSPECT_GET_ICON_HIGHQUALITY_BITMASK) {
      fprintf (trace_buffer.fp, " \"%s:%s\"", "highquality", optargs->highquality ? "true" : "false");
    }
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  r = guestfs_impl_inspect_get_icon (g, root, size_r, optargs);

  if (r != NULL) {
    if (trace_flag) {
      guestfs_int_trace_open (&trace_buffer);
      fprintf (trace_buffer.fp, "%s = ", "inspect_get_icon");
      guestfs_int_print_BufferOut (trace_buffer.fp, r, *size_r);
      guestfs_int_trace_send_line (g, &trace_buffer);
    }

  } else {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "inspect_get_icon", "NULL");
  }

  return r;
}

GUESTFS_DLL_PUBLIC char *
guestfs_inspect_get_windows_system_hive (guestfs_h *g,
                                         const char *root)
{
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  char *r;

  guestfs_int_call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                      "inspect_get_windows_system_hive", 31);
  if (root == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "inspect_get_windows_system_hive", "root");
    return NULL;
  }

  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "inspect_get_windows_system_hive");
    fprintf (trace_buffer.fp, " \"%s\"", root);
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  r = guestfs_impl_inspect_get_windows_system_hive (g, root);

  if (r != NULL) {
    if (trace_flag) {
      guestfs_int_trace_open (&trace_buffer);
      fprintf (trace_buffer.fp, "%s = ", "inspect_get_windows_system_hive");
      fprintf (trace_buffer.fp, "\"%s\"", r);
      guestfs_int_trace_send_line (g, &trace_buffer);
    }

  } else {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "inspect_get_windows_system_hive", "NULL");
  }

  return r;
}

GUESTFS_DLL_PUBLIC int
guestfs_inspect_is_netinst (guestfs_h *g,
                            const char *root)
{
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int r;

  guestfs_int_call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                      "inspect_is_netinst", 18);
  if (root == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "inspect_is_netinst", "root");
    return -1;
  }

  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "inspect_is_netinst");
    fprintf (trace_buffer.fp, " \"%s\"", root);
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  r = guestfs_impl_inspect_is_netinst (g, root);

  if (r != -1) {
    if (trace_flag) {
      guestfs_int_trace_open (&trace_buffer);
      fprintf (trace_buffer.fp, "%s = ", "inspect_is_netinst");
      fprintf (trace_buffer.fp, "%d", r);
      guestfs_int_trace_send_line (g, &trace_buffer);
    }

  } else {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "inspect_is_netinst", "-1");
  }

  return r;
}

GUESTFS_DLL_PUBLIC struct guestfs_application2_list *
guestfs_inspect_list_applications2 (guestfs_h *g,
                                    const char *root)
{
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  struct guestfs_application2_list *r;

  guestfs_int_call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                      "inspect_list_applications2", 26);
  if (root == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "inspect_list_applications2", "root");
    return NULL;
  }

  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "inspect_list_applications2");
    fprintf (trace_buffer.fp, " \"%s\"", root);
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  r = guestfs_impl_inspect_list_applications2 (g, root);

  if (r != NULL) {
    if (trace_flag) {
      size_t i;

      guestfs_int_trace_open (&trace_buffer);
      fprintf (trace_buffer.fp, "%s = ", "inspect_list_applications2");
      fprintf (trace_buffer.fp, "<struct guestfs_application2_list(%u)", r->len);
      if (r->len > 0)
        fprintf (trace_buffer.fp, " = ");
      for (i = 0; i < r->len; ++i) {
        if (i != 0)
          fprintf (trace_buffer.fp, " ");
        fprintf (trace_buffer.fp, "[%zu]{", i);
        guestfs_int_print_application2_indent (&r->val[i], trace_buffer.fp, ", ", "");
        fprintf (trace_buffer.fp, "}");
      }
      fprintf (trace_buffer.fp, ">");
      guestfs_int_trace_send_line (g, &trace_buffer);
    }

  } else {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "inspect_list_applications2", "NULL");
  }

  return r;
}

GUESTFS_DLL_PUBLIC char *
guestfs_internal_test_rbufferouterr (guestfs_h *g,
                                     size_t *size_r)
{
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  char *r;

  guestfs_int_call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                      "internal_test_rbufferouterr", 27);
  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "internal_test_rbufferouterr");
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  r = guestfs_impl_internal_test_rbufferouterr (g, size_r);

  if (r != NULL) {
    if (trace_flag) {
      guestfs_int_trace_open (&trace_buffer);
      fprintf (trace_buffer.fp, "%s = ", "internal_test_rbufferouterr");
      guestfs_int_print_BufferOut (trace_buffer.fp, r, *size_r);
      guestfs_int_trace_send_line (g, &trace_buffer);
    }

  } else {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "internal_test_rbufferouterr", "NULL");
  }

  return r;
}

GUESTFS_DLL_PUBLIC const char *
guestfs_internal_test_rconstoptstring (guestfs_h *g,
                                       const char *val)
{
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  const char *r;

  guestfs_int_call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                      "internal_test_rconstoptstring", 29);
  if (val == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "internal_test_rconstoptstring", "val");
    return NULL;
  }

  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "internal_test_rconstoptstring");
    fprintf (trace_buffer.fp, " \"%s\"", val);
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  r = guestfs_impl_internal_test_rconstoptstring (g, val);

  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "internal_test_rconstoptstring");
    fprintf (trace_buffer.fp, "\"%s\"", r != NULL ? r : "NULL");
    guestfs_int_trace_send_line (g, &trace_buffer);
  }


  return r;
}

GUESTFS_DLL_PUBLIC int64_t
guestfs_internal_test_rint64 (guestfs_h *g,
                              const char *val)
{
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int64_t r;

  guestfs_int_call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                      "internal_test_rint64", 20);
  if (val == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "internal_test_rint64", "val");
    return -1;
  }

  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "internal_test_rint64");
    fprintf (trace_buffer.fp, " \"%s\"", val);
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  r = guestfs_impl_internal_test_rint64 (g, val);

  if (r != -1) {
    if (trace_flag) {
      guestfs_int_trace_open (&trace_buffer);
      fprintf (trace_buffer.fp, "%s = ", "internal_test_rint64");
      fprintf (trace_buffer.fp, "%" PRIi64, r);
      guestfs_int_trace_send_line (g, &trace_buffer);
    }

  } else {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "internal_test_rint64", "-1");
  }

  return r;
}

GUESTFS_DLL_PUBLIC char *
guestfs_internal_test_rstringerr (guestfs_h *g)
{
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  char *r;

  guestfs_int_call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                      "internal_test_rstringerr", 24);
  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "internal_test_rstringerr");
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  r = guestfs_impl_internal_test_rstringerr (g);

  if (r != NULL) {
    if (trace_flag) {
      guestfs_int_trace_open (&trace_buffer);
      fprintf (trace_buffer.fp, "%s = ", "internal_test_rstringerr");
      fprintf (trace_buffer.fp, "\"%s\"", r);
      guestfs_int_trace_send_line (g, &trace_buffer);
    }

  } else {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "internal_test_rstringerr", "NULL");
  }

  return r;
}

GUESTFS_DLL_PUBLIC struct guestfs_lvm_pv_list *
guestfs_internal_test_rstructlist (guestfs_h *g,
                                   const char *val)
{
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  struct guestfs_lvm_pv_list *r;

  guestfs_int_call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                      "internal_test_rstructlist", 25);
  if (val == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "internal_test_rstructlist", "val");
    return NULL;
  }

  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "internal_test_rstructlist");
    fprintf (trace_buffer.fp, " \"%s\"", val);
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  r = guestfs_impl_internal_test_rstructlist (g, val);

  if (r != NULL) {
    if (trace_flag) {
      size_t i;

      guestfs_int_trace_open (&trace_buffer);
      fprintf (trace_buffer.fp, "%s = ", "internal_test_rstructlist");
      fprintf (trace_buffer.fp, "<struct guestfs_lvm_pv_list(%u)", r->len);
      if (r->len > 0)
        fprintf (trace_buffer.fp, " = ");
      for (i = 0; i < r->len; ++i) {
        if (i != 0)
          fprintf (trace_buffer.fp, " ");
        fprintf (trace_buffer.fp, "[%zu]{", i);
        guestfs_int_print_lvm_pv_indent (&r->val[i], trace_buffer.fp, ", ", "");
        fprintf (trace_buffer.fp, "}");
      }
      fprintf (trace_buffer.fp, ">");
      guestfs_int_trace_send_line (g, &trace_buffer);
    }

  } else {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "internal_test_rstructlist", "NULL");
  }

  return r;
}

GUESTFS_DLL_PUBLIC struct guestfs_lvm_pv_list *
guestfs_internal_test_rstructlisterr (guestfs_h *g)
{
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  struct guestfs_lvm_pv_list *r;

  guestfs_int_call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                      "internal_test_rstructlisterr", 28);
  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "internal_test_rstructlisterr");
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  r = guestfs_impl_internal_test_rstructlisterr (g);

  if (r != NULL) {
    if (trace_flag) {
      size_t i;

      guestfs_int_trace_open (&trace_buffer);
      fprintf (trace_buffer.fp, "%s = ", "internal_test_rstructlisterr");
      fprintf (trace_buffer.fp, "<struct guestfs_lvm_pv_list(%u)", r->len);
      if (r->len > 0)
        fprintf (trace_buffer.fp, " = ");
      for (i = 0; i < r->len; ++i) {
        if (i != 0)
          fprintf (trace_buffer.fp, " ");
        fprintf (trace_buffer.fp, "[%zu]{", i);
        guestfs_int_print_lvm_pv_indent (&r->val[i], trace_buffer.fp, ", ", "");
        fprintf (trace_buffer.fp, "}");
      }
      fprintf (trace_buffer.fp, ">");
      guestfs_int_trace_send_line (g, &trace_buffer);
    }

  } else {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "internal_test_rstructlisterr", "NULL");
  }

  return r;
}

GUESTFS_DLL_PUBLIC struct guestfs_stat *
guestfs_lstat (guestfs_h *g,
               const char *path)
{
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  struct guestfs_stat *r;

  guestfs_int_call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                      "lstat", 5);
  if (path == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "lstat", "path");
    return NULL;
  }

  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "lstat");
    fprintf (trace_buffer.fp, " \"%s\"", path);
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  r = guestfs_impl_lstat (g, path);

  if (r != NULL) {
    if (trace_flag) {
      guestfs_int_trace_open (&trace_buffer);
      fprintf (trace_buffer.fp, "%s = ", "lstat");
      fprintf (trace_buffer.fp, "<struct guestfs_stat = ");
      guestfs_int_print_stat_indent (r, trace_buffer.fp, ", ", "");
      fprintf (trace_buffer.fp, ">");
      guestfs_int_trace_send_line (g, &trace_buffer);
    }

  } else {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "lstat", "NULL");
  }

  return r;
}

GUESTFS_DLL_PUBLIC struct guestfs_stat_list *
guestfs_lstatlist (guestfs_h *g,
                   const char *path,
                   char *const *names)
{
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  struct guestfs_stat_list *r;

  guestfs_int_call_callbacks_message (g, GUESTFS_EVENT_ENTER,
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

  {
    size_t i;
    for (i = 0; names[i] != NULL; ++i) {
      if (strchr (names[i], '/') != NULL) {
        error (g, "%s: %s: '%s' is not a file name",
               "lstatlist", "names", names[i]);
        return NULL;
      }
    }
  }

  if (trace_flag) {
    size_t i;

    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "lstatlist");
    fprintf (trace_buffer.fp, " \"%s\"", path);
    fputc (' ', trace_buffer.fp);
    fputc ('"', trace_buffer.fp);
    for (i = 0; names[i]; ++i) {
      if (i > 0) fputc (' ', trace_buffer.fp);
      fputs (names[i], trace_buffer.fp);
    }
    fputc ('"', trace_buffer.fp);
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  r = guestfs_impl_lstatlist (g, path, names);

  if (r != NULL) {
    if (trace_flag) {
      size_t i;

      guestfs_int_trace_open (&trace_buffer);
      fprintf (trace_buffer.fp, "%s = ", "lstatlist");
      fprintf (trace_buffer.fp, "<struct guestfs_stat_list(%u)", r->len);
      if (r->len > 0)
        fprintf (trace_buffer.fp, " = ");
      for (i = 0; i < r->len; ++i) {
        if (i != 0)
          fprintf (trace_buffer.fp, " ");
        fprintf (trace_buffer.fp, "[%zu]{", i);
        guestfs_int_print_stat_indent (&r->val[i], trace_buffer.fp, ", ", "");
        fprintf (trace_buffer.fp, "}");
      }
      fprintf (trace_buffer.fp, ">");
      guestfs_int_trace_send_line (g, &trace_buffer);
    }

  } else {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "lstatlist", "NULL");
  }

  return r;
}

GUESTFS_DLL_PUBLIC int
guestfs_mount_local_run (guestfs_h *g)
{
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int r;

  guestfs_int_call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                      "mount_local_run", 15);
  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "mount_local_run");
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  r = guestfs_impl_mount_local_run (g);

  if (r != -1) {
    if (trace_flag) {
      guestfs_int_trace_open (&trace_buffer);
      fprintf (trace_buffer.fp, "%s = ", "mount_local_run");
      fprintf (trace_buffer.fp, "%d", r);
      guestfs_int_trace_send_line (g, &trace_buffer);
    }

  } else {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "mount_local_run", "-1");
  }

  return r;
}

GUESTFS_DLL_PUBLIC char *
guestfs_mountable_subvolume (guestfs_h *g,
                             const char *mountable)
{
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  char *r;

  guestfs_int_call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                      "mountable_subvolume", 19);
  if (mountable == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "mountable_subvolume", "mountable");
    return NULL;
  }

  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "mountable_subvolume");
    fprintf (trace_buffer.fp, " \"%s\"", mountable);
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  r = guestfs_impl_mountable_subvolume (g, mountable);

  if (r != NULL) {
    if (trace_flag) {
      guestfs_int_trace_open (&trace_buffer);
      fprintf (trace_buffer.fp, "%s = ", "mountable_subvolume");
      fprintf (trace_buffer.fp, "\"%s\"", r);
      guestfs_int_trace_send_line (g, &trace_buffer);
    }

  } else {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "mountable_subvolume", "NULL");
  }

  return r;
}

GUESTFS_DLL_PUBLIC int
guestfs_set_autosync (guestfs_h *g,
                      int autosync)
{
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int r;

  guestfs_int_call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                      "set_autosync", 12);
  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "set_autosync");
    fputs (autosync ? " true" : " false", trace_buffer.fp);
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  r = guestfs_impl_set_autosync (g, autosync);

  if (r != -1) {
    if (trace_flag) {
      guestfs_int_trace_open (&trace_buffer);
      fprintf (trace_buffer.fp, "%s = ", "set_autosync");
      fprintf (trace_buffer.fp, "%d", r);
      guestfs_int_trace_send_line (g, &trace_buffer);
    }

  } else {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "set_autosync", "-1");
  }

  return r;
}

GUESTFS_DLL_PUBLIC int
guestfs_set_backend_setting (guestfs_h *g,
                             const char *name,
                             const char *val)
{
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int r;

  if (g->state != CONFIG) {
    error (g, "%s: this function can only be called in the config state",
              "set_backend_setting");
    return -1;
  }
  guestfs_int_call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                      "set_backend_setting", 19);
  if (name == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "set_backend_setting", "name");
    return -1;
  }
  if (val == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "set_backend_setting", "val");
    return -1;
  }

  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "set_backend_setting");
    fprintf (trace_buffer.fp, " \"%s\"", name);
    fprintf (trace_buffer.fp, " \"%s\"", val);
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  r = guestfs_impl_set_backend_setting (g, name, val);

  if (r != -1) {
    if (trace_flag) {
      guestfs_int_trace_open (&trace_buffer);
      fprintf (trace_buffer.fp, "%s = ", "set_backend_setting");
      fprintf (trace_buffer.fp, "%d", r);
      guestfs_int_trace_send_line (g, &trace_buffer);
    }

  } else {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "set_backend_setting", "-1");
  }

  return r;
}

GUESTFS_DLL_PUBLIC int
guestfs_set_identifier (guestfs_h *g,
                        const char *identifier)
{
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int r;

  guestfs_int_call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                      "set_identifier", 14);
  if (identifier == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "set_identifier", "identifier");
    return -1;
  }

  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "set_identifier");
    fprintf (trace_buffer.fp, " \"%s\"", identifier);
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  r = guestfs_impl_set_identifier (g, identifier);

  if (r != -1) {
    if (trace_flag) {
      guestfs_int_trace_open (&trace_buffer);
      fprintf (trace_buffer.fp, "%s = ", "set_identifier");
      fprintf (trace_buffer.fp, "%d", r);
      guestfs_int_trace_send_line (g, &trace_buffer);
    }

  } else {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "set_identifier", "-1");
  }

  return r;
}

GUESTFS_DLL_PUBLIC int
guestfs_set_verbose (guestfs_h *g,
                     int verbose)
{
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int r;

  guestfs_int_call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                      "set_verbose", 11);
  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "set_verbose");
    fputs (verbose ? " true" : " false", trace_buffer.fp);
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  r = guestfs_impl_set_verbose (g, verbose);

  if (r != -1) {
    if (trace_flag) {
      guestfs_int_trace_open (&trace_buffer);
      fprintf (trace_buffer.fp, "%s = ", "set_verbose");
      fprintf (trace_buffer.fp, "%d", r);
      guestfs_int_trace_send_line (g, &trace_buffer);
    }

  } else {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "set_verbose", "-1");
  }

  return r;
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
  struct trace_buffer trace_buffer;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs_int_call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                      "aug_clear", 9);
  if (augpath == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "aug_clear", "augpath");
    return -1;
  }

  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "aug_clear");
    fprintf (trace_buffer.fp, " \"%s\"", augpath);
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  if (guestfs_int_check_appliance_up (g, "aug_clear") == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "aug_clear", "-1");
    return -1;
  }

  args.augpath = (char *) augpath;
  serial = guestfs_int_send (g, GUESTFS_PROC_AUG_CLEAR,
                             progress_hint, 0,
                             (xdrproc_t) xdr_guestfs_aug_clear_args, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "aug_clear", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs_int_recv (g, "aug_clear", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "aug_clear", "-1");
    return -1;
  }

  if (guestfs_int_check_reply_header (g, &hdr, GUESTFS_PROC_AUG_CLEAR, serial) == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "aug_clear", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "aug_clear", "-1");
    if (err.errno_string[0] != '\0')
      errnum = guestfs_int_string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "aug_clear", err.error_message);
    else
      guestfs_int_error_errno (g, errnum, "%s: %s", "aug_clear",
                               err.error_message);
    free (err.error_message);
    free (err.errno_string);
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "aug_clear");
    fprintf (trace_buffer.fp, "%d", ret_v);
    guestfs_int_trace_send_line (g, &trace_buffer);
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
  struct trace_buffer trace_buffer;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs_int_call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                      "aug_defvar", 10);
  if (name == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "aug_defvar", "name");
    return -1;
  }

  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "aug_defvar");
    fprintf (trace_buffer.fp, " \"%s\"", name);
    if (expr)
      fprintf (trace_buffer.fp, " \"%s\"", expr);
    else
      fprintf (trace_buffer.fp, " null");
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  if (guestfs_int_check_appliance_up (g, "aug_defvar") == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "aug_defvar", "-1");
    return -1;
  }

  args.name = (char *) name;
  args.expr = expr ? (char **) &expr : NULL;
  serial = guestfs_int_send (g, GUESTFS_PROC_AUG_DEFVAR,
                             progress_hint, 0,
                             (xdrproc_t) xdr_guestfs_aug_defvar_args, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "aug_defvar", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs_int_recv (g, "aug_defvar", &hdr, &err,
        (xdrproc_t) xdr_guestfs_aug_defvar_ret, (char *) &ret);
  if (r == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "aug_defvar", "-1");
    return -1;
  }

  if (guestfs_int_check_reply_header (g, &hdr, GUESTFS_PROC_AUG_DEFVAR, serial) == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "aug_defvar", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "aug_defvar", "-1");
    if (err.errno_string[0] != '\0')
      errnum = guestfs_int_string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "aug_defvar", err.error_message);
    else
      guestfs_int_error_errno (g, errnum, "%s: %s", "aug_defvar",
                               err.error_message);
    free (err.error_message);
    free (err.errno_string);
    return -1;
  }

  ret_v = ret.nrnodes;
  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "aug_defvar");
    fprintf (trace_buffer.fp, "%d", ret_v);
    guestfs_int_trace_send_line (g, &trace_buffer);
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
  struct trace_buffer trace_buffer;
  int ret_v;
  uint64_t progress_hint = 0;
  struct stat progress_stat;

  guestfs_int_call_callbacks_message (g, GUESTFS_EVENT_ENTER,
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
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "base64_in");
    fprintf (trace_buffer.fp, " \"%s\"", base64file);
    fprintf (trace_buffer.fp, " \"%s\"", filename);
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  if (stat (base64file, &progress_stat) == 0 &&
      S_ISREG (progress_stat.st_mode))
    progress_hint += progress_stat.st_size;

  if (guestfs_int_check_appliance_up (g, "base64_in") == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "base64_in", "-1");
    return -1;
  }

  args.filename = (char *) filename;
  serial = guestfs_int_send (g, GUESTFS_PROC_BASE64_IN,
                             progress_hint, 0,
                             (xdrproc_t) xdr_guestfs_base64_in_args, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "base64_in", "-1");
    return -1;
  }

  r = guestfs_int_send_file (g, base64file);
  if (r == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "base64_in", "-1");
    /* daemon will send an error reply which we discard */
    guestfs_int_recv_discard (g, "base64_in");
    return -1;
  }
  if (r == -2) /* daemon cancelled */
    goto read_reply;

 read_reply:
  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs_int_recv (g, "base64_in", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "base64_in", "-1");
    return -1;
  }

  if (guestfs_int_check_reply_header (g, &hdr, GUESTFS_PROC_BASE64_IN, serial) == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "base64_in", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "base64_in", "-1");
    if (err.errno_string[0] != '\0')
      errnum = guestfs_int_string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "base64_in", err.error_message);
    else
      guestfs_int_error_errno (g, errnum, "%s: %s", "base64_in",
                               err.error_message);
    free (err.error_message);
    free (err.errno_string);
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "base64_in");
    fprintf (trace_buffer.fp, "%d", ret_v);
    guestfs_int_trace_send_line (g, &trace_buffer);
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
  struct trace_buffer trace_buffer;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs_int_call_callbacks_message (g, GUESTFS_EVENT_ENTER,
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
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "base64_out");
    fprintf (trace_buffer.fp, " \"%s\"", filename);
    fprintf (trace_buffer.fp, " \"%s\"", base64file);
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  if (guestfs_int_check_appliance_up (g, "base64_out") == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "base64_out", "-1");
    return -1;
  }

  args.filename = (char *) filename;
  serial = guestfs_int_send (g, GUESTFS_PROC_BASE64_OUT,
                             progress_hint, 0,
                             (xdrproc_t) xdr_guestfs_base64_out_args, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "base64_out", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs_int_recv (g, "base64_out", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "base64_out", "-1");
    return -1;
  }

  if (guestfs_int_check_reply_header (g, &hdr, GUESTFS_PROC_BASE64_OUT, serial) == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "base64_out", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "base64_out", "-1");
    if (err.errno_string[0] != '\0')
      errnum = guestfs_int_string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "base64_out", err.error_message);
    else
      guestfs_int_error_errno (g, errnum, "%s: %s", "base64_out",
                               err.error_message);
    free (err.error_message);
    free (err.errno_string);
    return -1;
  }

  if (guestfs_int_recv_file (g, base64file) == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "base64_out", "-1");
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "base64_out");
    fprintf (trace_buffer.fp, "%d", ret_v);
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  return ret_v;
}

GUESTFS_DLL_PUBLIC int
guestfs_btrfs_balance_resume (guestfs_h *g,
                              const char *path)
{
  struct guestfs_btrfs_balance_resume_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs_int_call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                      "btrfs_balance_resume", 20);
  if (path == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "btrfs_balance_resume", "path");
    return -1;
  }

  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "btrfs_balance_resume");
    fprintf (trace_buffer.fp, " \"%s\"", path);
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  if (guestfs_int_check_appliance_up (g, "btrfs_balance_resume") == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "btrfs_balance_resume", "-1");
    return -1;
  }

  args.path = (char *) path;
  serial = guestfs_int_send (g, GUESTFS_PROC_BTRFS_BALANCE_RESUME,
                             progress_hint, 0,
                             (xdrproc_t) xdr_guestfs_btrfs_balance_resume_args, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "btrfs_balance_resume", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs_int_recv (g, "btrfs_balance_resume", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "btrfs_balance_resume", "-1");
    return -1;
  }

  if (guestfs_int_check_reply_header (g, &hdr, GUESTFS_PROC_BTRFS_BALANCE_RESUME, serial) == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "btrfs_balance_resume", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "btrfs_balance_resume", "-1");
    if (err.errno_string[0] != '\0')
      errnum = guestfs_int_string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "btrfs_balance_resume", err.error_message);
    else
      guestfs_int_error_errno (g, errnum, "%s: %s", "btrfs_balance_resume",
                               err.error_message);
    free (err.error_message);
    free (err.errno_string);
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "btrfs_balance_resume");
    fprintf (trace_buffer.fp, "%d", ret_v);
    guestfs_int_trace_send_line (g, &trace_buffer);
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
  struct trace_buffer trace_buffer;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs_int_call_callbacks_message (g, GUESTFS_EVENT_ENTER,
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
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "btrfs_fsck");
    fprintf (trace_buffer.fp, " \"%s\"", device);
    if (optargs->bitmask & GUESTFS_BTRFS_FSCK_SUPERBLOCK_BITMASK) {
      fprintf (trace_buffer.fp, " \"%s:%" PRIi64 "\"", "superblock", optargs->superblock);
    }
    if (optargs->bitmask & GUESTFS_BTRFS_FSCK_REPAIR_BITMASK) {
      fprintf (trace_buffer.fp, " \"%s:%s\"", "repair", optargs->repair ? "true" : "false");
    }
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  if (guestfs_int_check_appliance_up (g, "btrfs_fsck") == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
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
  serial = guestfs_int_send (g, GUESTFS_PROC_BTRFS_FSCK,
                             progress_hint, optargs->bitmask,
                             (xdrproc_t) xdr_guestfs_btrfs_fsck_args, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "btrfs_fsck", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs_int_recv (g, "btrfs_fsck", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "btrfs_fsck", "-1");
    return -1;
  }

  if (guestfs_int_check_reply_header (g, &hdr, GUESTFS_PROC_BTRFS_FSCK, serial) == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "btrfs_fsck", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "btrfs_fsck", "-1");
    if (err.errno_string[0] != '\0')
      errnum = guestfs_int_string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "btrfs_fsck", err.error_message);
    else
      guestfs_int_error_errno (g, errnum, "%s: %s", "btrfs_fsck",
                               err.error_message);
    free (err.error_message);
    free (err.errno_string);
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "btrfs_fsck");
    fprintf (trace_buffer.fp, "%d", ret_v);
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  return ret_v;
}

GUESTFS_DLL_PUBLIC struct guestfs_btrfsqgroup_list *
guestfs_btrfs_qgroup_show (guestfs_h *g,
                           const char *path)
{
  struct guestfs_btrfs_qgroup_show_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  struct guestfs_btrfs_qgroup_show_ret ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  struct guestfs_btrfsqgroup_list *ret_v;
  const uint64_t progress_hint = 0;

  guestfs_int_call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                      "btrfs_qgroup_show", 17);
  if (path == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "btrfs_qgroup_show", "path");
    return NULL;
  }

  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "btrfs_qgroup_show");
    fprintf (trace_buffer.fp, " \"%s\"", path);
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  if (guestfs_int_check_appliance_up (g, "btrfs_qgroup_show") == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "btrfs_qgroup_show", "NULL");
    return NULL;
  }

  args.path = (char *) path;
  serial = guestfs_int_send (g, GUESTFS_PROC_BTRFS_QGROUP_SHOW,
                             progress_hint, 0,
                             (xdrproc_t) xdr_guestfs_btrfs_qgroup_show_args, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "btrfs_qgroup_show", "NULL");
    return NULL;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs_int_recv (g, "btrfs_qgroup_show", &hdr, &err,
        (xdrproc_t) xdr_guestfs_btrfs_qgroup_show_ret, (char *) &ret);
  if (r == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "btrfs_qgroup_show", "NULL");
    return NULL;
  }

  if (guestfs_int_check_reply_header (g, &hdr, GUESTFS_PROC_BTRFS_QGROUP_SHOW, serial) == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "btrfs_qgroup_show", "NULL");
    return NULL;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "btrfs_qgroup_show", "NULL");
    if (err.errno_string[0] != '\0')
      errnum = guestfs_int_string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "btrfs_qgroup_show", err.error_message);
    else
      guestfs_int_error_errno (g, errnum, "%s: %s", "btrfs_qgroup_show",
                               err.error_message);
    free (err.error_message);
    free (err.errno_string);
    return NULL;
  }

  /* caller will free this */
  ret_v = safe_memdup (g, &ret.qgroups, sizeof (ret.qgroups));
  if (trace_flag) {
    size_t i;

    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "btrfs_qgroup_show");
    fprintf (trace_buffer.fp, "<struct guestfs_btrfsqgroup_list(%u)", ret_v->len);
    if (ret_v->len > 0)
      fprintf (trace_buffer.fp, " = ");
    for (i = 0; i < ret_v->len; ++i) {
      if (i != 0)
        fprintf (trace_buffer.fp, " ");
      fprintf (trace_buffer.fp, "[%zu]{", i);
      guestfs_int_print_btrfsqgroup_indent (&ret_v->val[i], trace_buffer.fp, ", ", "");
      fprintf (trace_buffer.fp, "}");
    }
    fprintf (trace_buffer.fp, ">");
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  return ret_v;
}

GUESTFS_DLL_PUBLIC int
guestfs_btrfs_rescue_chunk_recover (guestfs_h *g,
                                    const char *device)
{
  struct guestfs_btrfs_rescue_chunk_recover_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs_int_call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                      "btrfs_rescue_chunk_recover", 26);
  if (device == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "btrfs_rescue_chunk_recover", "device");
    return -1;
  }

  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "btrfs_rescue_chunk_recover");
    fprintf (trace_buffer.fp, " \"%s\"", device);
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  if (guestfs_int_check_appliance_up (g, "btrfs_rescue_chunk_recover") == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "btrfs_rescue_chunk_recover", "-1");
    return -1;
  }

  args.device = (char *) device;
  serial = guestfs_int_send (g, GUESTFS_PROC_BTRFS_RESCUE_CHUNK_RECOVER,
                             progress_hint, 0,
                             (xdrproc_t) xdr_guestfs_btrfs_rescue_chunk_recover_args, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "btrfs_rescue_chunk_recover", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs_int_recv (g, "btrfs_rescue_chunk_recover", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "btrfs_rescue_chunk_recover", "-1");
    return -1;
  }

  if (guestfs_int_check_reply_header (g, &hdr, GUESTFS_PROC_BTRFS_RESCUE_CHUNK_RECOVER, serial) == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "btrfs_rescue_chunk_recover", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "btrfs_rescue_chunk_recover", "-1");
    if (err.errno_string[0] != '\0')
      errnum = guestfs_int_string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "btrfs_rescue_chunk_recover", err.error_message);
    else
      guestfs_int_error_errno (g, errnum, "%s: %s", "btrfs_rescue_chunk_recover",
                               err.error_message);
    free (err.error_message);
    free (err.errno_string);
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "btrfs_rescue_chunk_recover");
    fprintf (trace_buffer.fp, "%d", ret_v);
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  return ret_v;
}

GUESTFS_DLL_PUBLIC int
guestfs_btrfs_scrub_resume (guestfs_h *g,
                            const char *path)
{
  struct guestfs_btrfs_scrub_resume_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs_int_call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                      "btrfs_scrub_resume", 18);
  if (path == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "btrfs_scrub_resume", "path");
    return -1;
  }

  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "btrfs_scrub_resume");
    fprintf (trace_buffer.fp, " \"%s\"", path);
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  if (guestfs_int_check_appliance_up (g, "btrfs_scrub_resume") == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "btrfs_scrub_resume", "-1");
    return -1;
  }

  args.path = (char *) path;
  serial = guestfs_int_send (g, GUESTFS_PROC_BTRFS_SCRUB_RESUME,
                             progress_hint, 0,
                             (xdrproc_t) xdr_guestfs_btrfs_scrub_resume_args, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "btrfs_scrub_resume", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs_int_recv (g, "btrfs_scrub_resume", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "btrfs_scrub_resume", "-1");
    return -1;
  }

  if (guestfs_int_check_reply_header (g, &hdr, GUESTFS_PROC_BTRFS_SCRUB_RESUME, serial) == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "btrfs_scrub_resume", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "btrfs_scrub_resume", "-1");
    if (err.errno_string[0] != '\0')
      errnum = guestfs_int_string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "btrfs_scrub_resume", err.error_message);
    else
      guestfs_int_error_errno (g, errnum, "%s: %s", "btrfs_scrub_resume",
                               err.error_message);
    free (err.error_message);
    free (err.errno_string);
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "btrfs_scrub_resume");
    fprintf (trace_buffer.fp, "%d", ret_v);
    guestfs_int_trace_send_line (g, &trace_buffer);
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
  struct trace_buffer trace_buffer;
  char *ret_v;
  const uint64_t progress_hint = 0;

  guestfs_int_call_callbacks_message (g, GUESTFS_EVENT_ENTER,
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
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "checksum_device");
    fprintf (trace_buffer.fp, " \"%s\"", csumtype);
    fprintf (trace_buffer.fp, " \"%s\"", device);
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  if (guestfs_int_check_appliance_up (g, "checksum_device") == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "checksum_device", "NULL");
    return NULL;
  }

  args.csumtype = (char *) csumtype;
  args.device = (char *) device;
  serial = guestfs_int_send (g, GUESTFS_PROC_CHECKSUM_DEVICE,
                             progress_hint, 0,
                             (xdrproc_t) xdr_guestfs_checksum_device_args, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "checksum_device", "NULL");
    return NULL;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs_int_recv (g, "checksum_device", &hdr, &err,
        (xdrproc_t) xdr_guestfs_checksum_device_ret, (char *) &ret);
  if (r == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "checksum_device", "NULL");
    return NULL;
  }

  if (guestfs_int_check_reply_header (g, &hdr, GUESTFS_PROC_CHECKSUM_DEVICE, serial) == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "checksum_device", "NULL");
    return NULL;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "checksum_device", "NULL");
    if (err.errno_string[0] != '\0')
      errnum = guestfs_int_string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "checksum_device", err.error_message);
    else
      guestfs_int_error_errno (g, errnum, "%s: %s", "checksum_device",
                               err.error_message);
    free (err.error_message);
    free (err.errno_string);
    return NULL;
  }

  ret_v = ret.checksum; /* caller will free */
  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "checksum_device");
    fprintf (trace_buffer.fp, "\"%s\"", ret_v);
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  return ret_v;
}

GUESTFS_DLL_PUBLIC int
guestfs_copy_attributes_argv (guestfs_h *g,
                              const char *src,
                              const char *dest,
                              const struct guestfs_copy_attributes_argv *optargs)
{
  struct guestfs_copy_attributes_argv optargs_null;
  if (!optargs) {
    optargs_null.bitmask = 0;
    optargs = &optargs_null;
  }

  struct guestfs_copy_attributes_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs_int_call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                      "copy_attributes", 15);
  if (src == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "copy_attributes", "src");
    return -1;
  }
  if (dest == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "copy_attributes", "dest");
    return -1;
  }

  if (optargs->bitmask & UINT64_C(0xfffffffffffffff0)) {
    error (g, "%s: unknown option in guestfs_%s_argv->bitmask (this can happen if a program is compiled against a newer version of libguestfs, then dynamically linked to an older version)",
           "copy_attributes", "copy_attributes");
    return -1;
  }

  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "copy_attributes");
    fprintf (trace_buffer.fp, " \"%s\"", src);
    fprintf (trace_buffer.fp, " \"%s\"", dest);
    if (optargs->bitmask & GUESTFS_COPY_ATTRIBUTES_ALL_BITMASK) {
      fprintf (trace_buffer.fp, " \"%s:%s\"", "all", optargs->all ? "true" : "false");
    }
    if (optargs->bitmask & GUESTFS_COPY_ATTRIBUTES_MODE_BITMASK) {
      fprintf (trace_buffer.fp, " \"%s:%s\"", "mode", optargs->mode ? "true" : "false");
    }
    if (optargs->bitmask & GUESTFS_COPY_ATTRIBUTES_XATTRIBUTES_BITMASK) {
      fprintf (trace_buffer.fp, " \"%s:%s\"", "xattributes", optargs->xattributes ? "true" : "false");
    }
    if (optargs->bitmask & GUESTFS_COPY_ATTRIBUTES_OWNERSHIP_BITMASK) {
      fprintf (trace_buffer.fp, " \"%s:%s\"", "ownership", optargs->ownership ? "true" : "false");
    }
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  if (guestfs_int_check_appliance_up (g, "copy_attributes") == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "copy_attributes", "-1");
    return -1;
  }

  args.src = (char *) src;
  args.dest = (char *) dest;
  if (optargs->bitmask & GUESTFS_COPY_ATTRIBUTES_ALL_BITMASK) {
    args.all = optargs->all;
  } else {
    args.all = 0;
  }
  if (optargs->bitmask & GUESTFS_COPY_ATTRIBUTES_MODE_BITMASK) {
    args.mode = optargs->mode;
  } else {
    args.mode = 0;
  }
  if (optargs->bitmask & GUESTFS_COPY_ATTRIBUTES_XATTRIBUTES_BITMASK) {
    args.xattributes = optargs->xattributes;
  } else {
    args.xattributes = 0;
  }
  if (optargs->bitmask & GUESTFS_COPY_ATTRIBUTES_OWNERSHIP_BITMASK) {
    args.ownership = optargs->ownership;
  } else {
    args.ownership = 0;
  }
  serial = guestfs_int_send (g, GUESTFS_PROC_COPY_ATTRIBUTES,
                             progress_hint, optargs->bitmask,
                             (xdrproc_t) xdr_guestfs_copy_attributes_args, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "copy_attributes", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs_int_recv (g, "copy_attributes", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "copy_attributes", "-1");
    return -1;
  }

  if (guestfs_int_check_reply_header (g, &hdr, GUESTFS_PROC_COPY_ATTRIBUTES, serial) == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "copy_attributes", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "copy_attributes", "-1");
    if (err.errno_string[0] != '\0')
      errnum = guestfs_int_string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "copy_attributes", err.error_message);
    else
      guestfs_int_error_errno (g, errnum, "%s: %s", "copy_attributes",
                               err.error_message);
    free (err.error_message);
    free (err.errno_string);
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "copy_attributes");
    fprintf (trace_buffer.fp, "%d", ret_v);
    guestfs_int_trace_send_line (g, &trace_buffer);
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
  struct trace_buffer trace_buffer;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs_int_call_callbacks_message (g, GUESTFS_EVENT_ENTER,
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

  if (optargs->bitmask & UINT64_C(0xffffffffffffffe0)) {
    error (g, "%s: unknown option in guestfs_%s_argv->bitmask (this can happen if a program is compiled against a newer version of libguestfs, then dynamically linked to an older version)",
           "copy_device_to_device", "copy_device_to_device");
    return -1;
  }

  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "copy_device_to_device");
    fprintf (trace_buffer.fp, " \"%s\"", src);
    fprintf (trace_buffer.fp, " \"%s\"", dest);
    if (optargs->bitmask & GUESTFS_COPY_DEVICE_TO_DEVICE_SRCOFFSET_BITMASK) {
      fprintf (trace_buffer.fp, " \"%s:%" PRIi64 "\"", "srcoffset", optargs->srcoffset);
    }
    if (optargs->bitmask & GUESTFS_COPY_DEVICE_TO_DEVICE_DESTOFFSET_BITMASK) {
      fprintf (trace_buffer.fp, " \"%s:%" PRIi64 "\"", "destoffset", optargs->destoffset);
    }
    if (optargs->bitmask & GUESTFS_COPY_DEVICE_TO_DEVICE_SIZE_BITMASK) {
      fprintf (trace_buffer.fp, " \"%s:%" PRIi64 "\"", "size", optargs->size);
    }
    if (optargs->bitmask & GUESTFS_COPY_DEVICE_TO_DEVICE_SPARSE_BITMASK) {
      fprintf (trace_buffer.fp, " \"%s:%s\"", "sparse", optargs->sparse ? "true" : "false");
    }
    if (optargs->bitmask & GUESTFS_COPY_DEVICE_TO_DEVICE_APPEND_BITMASK) {
      fprintf (trace_buffer.fp, " \"%s:%s\"", "append", optargs->append ? "true" : "false");
    }
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  if (guestfs_int_check_appliance_up (g, "copy_device_to_device") == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
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
  if (optargs->bitmask & GUESTFS_COPY_DEVICE_TO_DEVICE_SPARSE_BITMASK) {
    args.sparse = optargs->sparse;
  } else {
    args.sparse = 0;
  }
  if (optargs->bitmask & GUESTFS_COPY_DEVICE_TO_DEVICE_APPEND_BITMASK) {
    args.append = optargs->append;
  } else {
    args.append = 0;
  }
  serial = guestfs_int_send (g, GUESTFS_PROC_COPY_DEVICE_TO_DEVICE,
                             progress_hint, optargs->bitmask,
                             (xdrproc_t) xdr_guestfs_copy_device_to_device_args, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "copy_device_to_device", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs_int_recv (g, "copy_device_to_device", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "copy_device_to_device", "-1");
    return -1;
  }

  if (guestfs_int_check_reply_header (g, &hdr, GUESTFS_PROC_COPY_DEVICE_TO_DEVICE, serial) == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "copy_device_to_device", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "copy_device_to_device", "-1");
    if (err.errno_string[0] != '\0')
      errnum = guestfs_int_string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "copy_device_to_device", err.error_message);
    else
      guestfs_int_error_errno (g, errnum, "%s: %s", "copy_device_to_device",
                               err.error_message);
    free (err.error_message);
    free (err.errno_string);
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "copy_device_to_device");
    fprintf (trace_buffer.fp, "%d", ret_v);
    guestfs_int_trace_send_line (g, &trace_buffer);
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
  struct trace_buffer trace_buffer;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs_int_call_callbacks_message (g, GUESTFS_EVENT_ENTER,
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
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "dd");
    fprintf (trace_buffer.fp, " \"%s\"", src);
    fprintf (trace_buffer.fp, " \"%s\"", dest);
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  if (guestfs_int_check_appliance_up (g, "dd") == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "dd", "-1");
    return -1;
  }

  args.src = (char *) src;
  args.dest = (char *) dest;
  serial = guestfs_int_send (g, GUESTFS_PROC_DD,
                             progress_hint, 0,
                             (xdrproc_t) xdr_guestfs_dd_args, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "dd", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs_int_recv (g, "dd", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "dd", "-1");
    return -1;
  }

  if (guestfs_int_check_reply_header (g, &hdr, GUESTFS_PROC_DD, serial) == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "dd", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "dd", "-1");
    if (err.errno_string[0] != '\0')
      errnum = guestfs_int_string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "dd", err.error_message);
    else
      guestfs_int_error_errno (g, errnum, "%s: %s", "dd",
                               err.error_message);
    free (err.error_message);
    free (err.errno_string);
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "dd");
    fprintf (trace_buffer.fp, "%d", ret_v);
    guestfs_int_trace_send_line (g, &trace_buffer);
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
  struct trace_buffer trace_buffer;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs_int_call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                      "device_index", 12);
  if (device == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "device_index", "device");
    return -1;
  }

  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "device_index");
    fprintf (trace_buffer.fp, " \"%s\"", device);
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  if (guestfs_int_check_appliance_up (g, "device_index") == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "device_index", "-1");
    return -1;
  }

  args.device = (char *) device;
  serial = guestfs_int_send (g, GUESTFS_PROC_DEVICE_INDEX,
                             progress_hint, 0,
                             (xdrproc_t) xdr_guestfs_device_index_args, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "device_index", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs_int_recv (g, "device_index", &hdr, &err,
        (xdrproc_t) xdr_guestfs_device_index_ret, (char *) &ret);
  if (r == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "device_index", "-1");
    return -1;
  }

  if (guestfs_int_check_reply_header (g, &hdr, GUESTFS_PROC_DEVICE_INDEX, serial) == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "device_index", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "device_index", "-1");
    if (err.errno_string[0] != '\0')
      errnum = guestfs_int_string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "device_index", err.error_message);
    else
      guestfs_int_error_errno (g, errnum, "%s: %s", "device_index",
                               err.error_message);
    free (err.error_message);
    free (err.errno_string);
    return -1;
  }

  ret_v = ret.index;
  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "device_index");
    fprintf (trace_buffer.fp, "%d", ret_v);
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  return ret_v;
}

GUESTFS_DLL_PUBLIC int
guestfs_download_inode (guestfs_h *g,
                        const char *device,
                        int64_t inode,
                        const char *filename)
{
  struct guestfs_download_inode_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs_int_call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                      "download_inode", 14);
  if (device == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "download_inode", "device");
    return -1;
  }
  if (filename == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "download_inode", "filename");
    return -1;
  }

  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "download_inode");
    fprintf (trace_buffer.fp, " \"%s\"", device);
    fprintf (trace_buffer.fp, " %" PRIi64, inode);
    fprintf (trace_buffer.fp, " \"%s\"", filename);
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  if (guestfs_int_check_appliance_up (g, "download_inode") == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "download_inode", "-1");
    return -1;
  }

  args.device = (char *) device;
  args.inode = inode;
  serial = guestfs_int_send (g, GUESTFS_PROC_DOWNLOAD_INODE,
                             progress_hint, 0,
                             (xdrproc_t) xdr_guestfs_download_inode_args, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "download_inode", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs_int_recv (g, "download_inode", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "download_inode", "-1");
    return -1;
  }

  if (guestfs_int_check_reply_header (g, &hdr, GUESTFS_PROC_DOWNLOAD_INODE, serial) == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "download_inode", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "download_inode", "-1");
    if (err.errno_string[0] != '\0')
      errnum = guestfs_int_string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "download_inode", err.error_message);
    else
      guestfs_int_error_errno (g, errnum, "%s: %s", "download_inode",
                               err.error_message);
    free (err.error_message);
    free (err.errno_string);
    return -1;
  }

  if (guestfs_int_recv_file (g, filename) == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "download_inode", "-1");
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "download_inode");
    fprintf (trace_buffer.fp, "%d", ret_v);
    guestfs_int_trace_send_line (g, &trace_buffer);
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
  struct trace_buffer trace_buffer;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs_int_call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                      "exists", 6);
  if (path == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "exists", "path");
    return -1;
  }

  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "exists");
    fprintf (trace_buffer.fp, " \"%s\"", path);
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  if (guestfs_int_check_appliance_up (g, "exists") == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "exists", "-1");
    return -1;
  }

  args.path = (char *) path;
  serial = guestfs_int_send (g, GUESTFS_PROC_EXISTS,
                             progress_hint, 0,
                             (xdrproc_t) xdr_guestfs_exists_args, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "exists", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs_int_recv (g, "exists", &hdr, &err,
        (xdrproc_t) xdr_guestfs_exists_ret, (char *) &ret);
  if (r == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "exists", "-1");
    return -1;
  }

  if (guestfs_int_check_reply_header (g, &hdr, GUESTFS_PROC_EXISTS, serial) == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "exists", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "exists", "-1");
    if (err.errno_string[0] != '\0')
      errnum = guestfs_int_string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "exists", err.error_message);
    else
      guestfs_int_error_errno (g, errnum, "%s: %s", "exists",
                               err.error_message);
    free (err.error_message);
    free (err.errno_string);
    return -1;
  }

  ret_v = ret.existsflag;
  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "exists");
    fprintf (trace_buffer.fp, "%d", ret_v);
    guestfs_int_trace_send_line (g, &trace_buffer);
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
  struct trace_buffer trace_buffer;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs_int_call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                      "fill_dir", 8);
  if (dir == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "fill_dir", "dir");
    return -1;
  }

  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "fill_dir");
    fprintf (trace_buffer.fp, " \"%s\"", dir);
    fprintf (trace_buffer.fp, " %d", nr);
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  if (guestfs_int_check_appliance_up (g, "fill_dir") == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "fill_dir", "-1");
    return -1;
  }

  args.dir = (char *) dir;
  args.nr = nr;
  serial = guestfs_int_send (g, GUESTFS_PROC_FILL_DIR,
                             progress_hint, 0,
                             (xdrproc_t) xdr_guestfs_fill_dir_args, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "fill_dir", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs_int_recv (g, "fill_dir", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "fill_dir", "-1");
    return -1;
  }

  if (guestfs_int_check_reply_header (g, &hdr, GUESTFS_PROC_FILL_DIR, serial) == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "fill_dir", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "fill_dir", "-1");
    if (err.errno_string[0] != '\0')
      errnum = guestfs_int_string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "fill_dir", err.error_message);
    else
      guestfs_int_error_errno (g, errnum, "%s: %s", "fill_dir",
                               err.error_message);
    free (err.error_message);
    free (err.errno_string);
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "fill_dir");
    fprintf (trace_buffer.fp, "%d", ret_v);
    guestfs_int_trace_send_line (g, &trace_buffer);
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
  struct trace_buffer trace_buffer;
  char *ret_v;
  const uint64_t progress_hint = 0;

  guestfs_int_call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                      "findfs_label", 12);
  if (label == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "findfs_label", "label");
    return NULL;
  }

  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "findfs_label");
    fprintf (trace_buffer.fp, " \"%s\"", label);
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  if (guestfs_int_check_appliance_up (g, "findfs_label") == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "findfs_label", "NULL");
    return NULL;
  }

  args.label = (char *) label;
  serial = guestfs_int_send (g, GUESTFS_PROC_FINDFS_LABEL,
                             progress_hint, 0,
                             (xdrproc_t) xdr_guestfs_findfs_label_args, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "findfs_label", "NULL");
    return NULL;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs_int_recv (g, "findfs_label", &hdr, &err,
        (xdrproc_t) xdr_guestfs_findfs_label_ret, (char *) &ret);
  if (r == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "findfs_label", "NULL");
    return NULL;
  }

  if (guestfs_int_check_reply_header (g, &hdr, GUESTFS_PROC_FINDFS_LABEL, serial) == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "findfs_label", "NULL");
    return NULL;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "findfs_label", "NULL");
    if (err.errno_string[0] != '\0')
      errnum = guestfs_int_string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "findfs_label", err.error_message);
    else
      guestfs_int_error_errno (g, errnum, "%s: %s", "findfs_label",
                               err.error_message);
    free (err.error_message);
    free (err.errno_string);
    return NULL;
  }

  ret_v = ret.device; /* caller will free */
  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "findfs_label");
    fprintf (trace_buffer.fp, "\"%s\"", ret_v);
    guestfs_int_trace_send_line (g, &trace_buffer);
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
  struct trace_buffer trace_buffer;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs_int_call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                      "get_umask", 9);
  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "get_umask");
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  if (guestfs_int_check_appliance_up (g, "get_umask") == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "get_umask", "-1");
    return -1;
  }

  serial = guestfs_int_send (g, GUESTFS_PROC_GET_UMASK, progress_hint, 0,
                             NULL, NULL);
  if (serial == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "get_umask", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs_int_recv (g, "get_umask", &hdr, &err,
        (xdrproc_t) xdr_guestfs_get_umask_ret, (char *) &ret);
  if (r == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "get_umask", "-1");
    return -1;
  }

  if (guestfs_int_check_reply_header (g, &hdr, GUESTFS_PROC_GET_UMASK, serial) == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "get_umask", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "get_umask", "-1");
    if (err.errno_string[0] != '\0')
      errnum = guestfs_int_string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "get_umask", err.error_message);
    else
      guestfs_int_error_errno (g, errnum, "%s: %s", "get_umask",
                               err.error_message);
    free (err.error_message);
    free (err.errno_string);
    return -1;
  }

  ret_v = ret.mask;
  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "get_umask");
    fprintf (trace_buffer.fp, "%d", ret_v);
    guestfs_int_trace_send_line (g, &trace_buffer);
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
  struct trace_buffer trace_buffer;
  struct guestfs_xattr_list *ret_v;
  const uint64_t progress_hint = 0;

  guestfs_int_call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                      "getxattrs", 9);
  if (path == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "getxattrs", "path");
    return NULL;
  }

  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "getxattrs");
    fprintf (trace_buffer.fp, " \"%s\"", path);
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  if (guestfs_int_check_appliance_up (g, "getxattrs") == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "getxattrs", "NULL");
    return NULL;
  }

  args.path = (char *) path;
  serial = guestfs_int_send (g, GUESTFS_PROC_GETXATTRS,
                             progress_hint, 0,
                             (xdrproc_t) xdr_guestfs_getxattrs_args, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "getxattrs", "NULL");
    return NULL;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs_int_recv (g, "getxattrs", &hdr, &err,
        (xdrproc_t) xdr_guestfs_getxattrs_ret, (char *) &ret);
  if (r == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "getxattrs", "NULL");
    return NULL;
  }

  if (guestfs_int_check_reply_header (g, &hdr, GUESTFS_PROC_GETXATTRS, serial) == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "getxattrs", "NULL");
    return NULL;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "getxattrs", "NULL");
    if (err.errno_string[0] != '\0')
      errnum = guestfs_int_string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "getxattrs", err.error_message);
    else
      guestfs_int_error_errno (g, errnum, "%s: %s", "getxattrs",
                               err.error_message);
    free (err.error_message);
    free (err.errno_string);
    return NULL;
  }

  /* caller will free this */
  ret_v = safe_memdup (g, &ret.xattrs, sizeof (ret.xattrs));
  if (trace_flag) {
    size_t i;

    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "getxattrs");
    fprintf (trace_buffer.fp, "<struct guestfs_xattr_list(%u)", ret_v->len);
    if (ret_v->len > 0)
      fprintf (trace_buffer.fp, " = ");
    for (i = 0; i < ret_v->len; ++i) {
      if (i != 0)
        fprintf (trace_buffer.fp, " ");
      fprintf (trace_buffer.fp, "[%zu]{", i);
      guestfs_int_print_xattr_indent (&ret_v->val[i], trace_buffer.fp, ", ", "");
      fprintf (trace_buffer.fp, "}");
    }
    fprintf (trace_buffer.fp, ">");
    guestfs_int_trace_send_line (g, &trace_buffer);
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
  struct trace_buffer trace_buffer;
  char **ret_v;
  const uint64_t progress_hint = 0;

  guestfs_int_call_callbacks_message (g, GUESTFS_EVENT_ENTER,
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
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "grep");
    fprintf (trace_buffer.fp, " \"%s\"", regex);
    fprintf (trace_buffer.fp, " \"%s\"", path);
    if (optargs->bitmask & GUESTFS_GREP_OPTS_EXTENDED_BITMASK) {
      fprintf (trace_buffer.fp, " \"%s:%s\"", "extended", optargs->extended ? "true" : "false");
    }
    if (optargs->bitmask & GUESTFS_GREP_OPTS_FIXED_BITMASK) {
      fprintf (trace_buffer.fp, " \"%s:%s\"", "fixed", optargs->fixed ? "true" : "false");
    }
    if (optargs->bitmask & GUESTFS_GREP_OPTS_INSENSITIVE_BITMASK) {
      fprintf (trace_buffer.fp, " \"%s:%s\"", "insensitive", optargs->insensitive ? "true" : "false");
    }
    if (optargs->bitmask & GUESTFS_GREP_OPTS_COMPRESSED_BITMASK) {
      fprintf (trace_buffer.fp, " \"%s:%s\"", "compressed", optargs->compressed ? "true" : "false");
    }
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  if (guestfs_int_check_appliance_up (g, "grep") == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
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
  serial = guestfs_int_send (g, GUESTFS_PROC_GREP,
                             progress_hint, optargs->bitmask,
                             (xdrproc_t) xdr_guestfs_grep_args, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "grep", "NULL");
    return NULL;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs_int_recv (g, "grep", &hdr, &err,
        (xdrproc_t) xdr_guestfs_grep_ret, (char *) &ret);
  if (r == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "grep", "NULL");
    return NULL;
  }

  if (guestfs_int_check_reply_header (g, &hdr, GUESTFS_PROC_GREP, serial) == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "grep", "NULL");
    return NULL;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "grep", "NULL");
    if (err.errno_string[0] != '\0')
      errnum = guestfs_int_string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "grep", err.error_message);
    else
      guestfs_int_error_errno (g, errnum, "%s: %s", "grep",
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
    fprintf (trace_buffer.fp, "%s = ", "grep");
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
  struct trace_buffer trace_buffer;
  int64_t ret_v;
  const uint64_t progress_hint = 0;

  guestfs_int_call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                      "hivex_node_parent", 17);
  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "hivex_node_parent");
    fprintf (trace_buffer.fp, " %" PRIi64, nodeh);
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  if (guestfs_int_check_appliance_up (g, "hivex_node_parent") == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "hivex_node_parent", "-1");
    return -1;
  }

  args.nodeh = nodeh;
  serial = guestfs_int_send (g, GUESTFS_PROC_HIVEX_NODE_PARENT,
                             progress_hint, 0,
                             (xdrproc_t) xdr_guestfs_hivex_node_parent_args, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "hivex_node_parent", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs_int_recv (g, "hivex_node_parent", &hdr, &err,
        (xdrproc_t) xdr_guestfs_hivex_node_parent_ret, (char *) &ret);
  if (r == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "hivex_node_parent", "-1");
    return -1;
  }

  if (guestfs_int_check_reply_header (g, &hdr, GUESTFS_PROC_HIVEX_NODE_PARENT, serial) == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "hivex_node_parent", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "hivex_node_parent", "-1");
    if (err.errno_string[0] != '\0')
      errnum = guestfs_int_string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "hivex_node_parent", err.error_message);
    else
      guestfs_int_error_errno (g, errnum, "%s: %s", "hivex_node_parent",
                               err.error_message);
    free (err.error_message);
    free (err.errno_string);
    return -1;
  }

  ret_v = ret.parent;
  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "hivex_node_parent");
    fprintf (trace_buffer.fp, "%" PRIi64, ret_v);
    guestfs_int_trace_send_line (g, &trace_buffer);
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
  struct trace_buffer trace_buffer;
  int64_t ret_v;
  const uint64_t progress_hint = 0;

  guestfs_int_call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                      "hivex_root", 10);
  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "hivex_root");
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  if (guestfs_int_check_appliance_up (g, "hivex_root") == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "hivex_root", "-1");
    return -1;
  }

  serial = guestfs_int_send (g, GUESTFS_PROC_HIVEX_ROOT, progress_hint, 0,
                             NULL, NULL);
  if (serial == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "hivex_root", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs_int_recv (g, "hivex_root", &hdr, &err,
        (xdrproc_t) xdr_guestfs_hivex_root_ret, (char *) &ret);
  if (r == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "hivex_root", "-1");
    return -1;
  }

  if (guestfs_int_check_reply_header (g, &hdr, GUESTFS_PROC_HIVEX_ROOT, serial) == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "hivex_root", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "hivex_root", "-1");
    if (err.errno_string[0] != '\0')
      errnum = guestfs_int_string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "hivex_root", err.error_message);
    else
      guestfs_int_error_errno (g, errnum, "%s: %s", "hivex_root",
                               err.error_message);
    free (err.error_message);
    free (err.errno_string);
    return -1;
  }

  ret_v = ret.nodeh;
  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "hivex_root");
    fprintf (trace_buffer.fp, "%" PRIi64, ret_v);
    guestfs_int_trace_send_line (g, &trace_buffer);
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
  struct trace_buffer trace_buffer;
  char *ret_v;
  const uint64_t progress_hint = 0;

  guestfs_int_call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                      "hivex_value_value", 17);
  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "hivex_value_value");
    fprintf (trace_buffer.fp, " %" PRIi64, valueh);
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  if (guestfs_int_check_appliance_up (g, "hivex_value_value") == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "hivex_value_value", "NULL");
    return NULL;
  }

  args.valueh = valueh;
  serial = guestfs_int_send (g, GUESTFS_PROC_HIVEX_VALUE_VALUE,
                             progress_hint, 0,
                             (xdrproc_t) xdr_guestfs_hivex_value_value_args, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "hivex_value_value", "NULL");
    return NULL;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs_int_recv (g, "hivex_value_value", &hdr, &err,
        (xdrproc_t) xdr_guestfs_hivex_value_value_ret, (char *) &ret);
  if (r == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "hivex_value_value", "NULL");
    return NULL;
  }

  if (guestfs_int_check_reply_header (g, &hdr, GUESTFS_PROC_HIVEX_VALUE_VALUE, serial) == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "hivex_value_value", "NULL");
    return NULL;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "hivex_value_value", "NULL");
    if (err.errno_string[0] != '\0')
      errnum = guestfs_int_string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "hivex_value_value", err.error_message);
    else
      guestfs_int_error_errno (g, errnum, "%s: %s", "hivex_value_value",
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
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "hivex_value_value");
    guestfs_int_print_BufferOut (trace_buffer.fp, ret_v, *size_r);
    guestfs_int_trace_send_line (g, &trace_buffer);
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
  struct trace_buffer trace_buffer;
  char **ret_v;
  const uint64_t progress_hint = 0;

  guestfs_int_call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                      "initrd_list", 11);
  if (path == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "initrd_list", "path");
    return NULL;
  }

  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "initrd_list");
    fprintf (trace_buffer.fp, " \"%s\"", path);
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  if (guestfs_int_check_appliance_up (g, "initrd_list") == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "initrd_list", "NULL");
    return NULL;
  }

  args.path = (char *) path;
  serial = guestfs_int_send (g, GUESTFS_PROC_INITRD_LIST,
                             progress_hint, 0,
                             (xdrproc_t) xdr_guestfs_initrd_list_args, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "initrd_list", "NULL");
    return NULL;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs_int_recv (g, "initrd_list", &hdr, &err,
        (xdrproc_t) xdr_guestfs_initrd_list_ret, (char *) &ret);
  if (r == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "initrd_list", "NULL");
    return NULL;
  }

  if (guestfs_int_check_reply_header (g, &hdr, GUESTFS_PROC_INITRD_LIST, serial) == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "initrd_list", "NULL");
    return NULL;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "initrd_list", "NULL");
    if (err.errno_string[0] != '\0')
      errnum = guestfs_int_string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "initrd_list", err.error_message);
    else
      guestfs_int_error_errno (g, errnum, "%s: %s", "initrd_list",
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

    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "initrd_list");
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
guestfs_inotify_files (guestfs_h *g)
{
  guestfs_message_header hdr;
  guestfs_message_error err;
  struct guestfs_inotify_files_ret ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  char **ret_v;
  const uint64_t progress_hint = 0;

  guestfs_int_call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                      "inotify_files", 13);
  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "inotify_files");
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  if (guestfs_int_check_appliance_up (g, "inotify_files") == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "inotify_files", "NULL");
    return NULL;
  }

  serial = guestfs_int_send (g, GUESTFS_PROC_INOTIFY_FILES, progress_hint, 0,
                             NULL, NULL);
  if (serial == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "inotify_files", "NULL");
    return NULL;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs_int_recv (g, "inotify_files", &hdr, &err,
        (xdrproc_t) xdr_guestfs_inotify_files_ret, (char *) &ret);
  if (r == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "inotify_files", "NULL");
    return NULL;
  }

  if (guestfs_int_check_reply_header (g, &hdr, GUESTFS_PROC_INOTIFY_FILES, serial) == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "inotify_files", "NULL");
    return NULL;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "inotify_files", "NULL");
    if (err.errno_string[0] != '\0')
      errnum = guestfs_int_string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "inotify_files", err.error_message);
    else
      guestfs_int_error_errno (g, errnum, "%s: %s", "inotify_files",
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

    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "inotify_files");
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
guestfs_inotify_rm_watch (guestfs_h *g,
                          int wd)
{
  struct guestfs_inotify_rm_watch_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs_int_call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                      "inotify_rm_watch", 16);
  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "inotify_rm_watch");
    fprintf (trace_buffer.fp, " %d", wd);
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  if (guestfs_int_check_appliance_up (g, "inotify_rm_watch") == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "inotify_rm_watch", "-1");
    return -1;
  }

  args.wd = wd;
  serial = guestfs_int_send (g, GUESTFS_PROC_INOTIFY_RM_WATCH,
                             progress_hint, 0,
                             (xdrproc_t) xdr_guestfs_inotify_rm_watch_args, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "inotify_rm_watch", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs_int_recv (g, "inotify_rm_watch", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "inotify_rm_watch", "-1");
    return -1;
  }

  if (guestfs_int_check_reply_header (g, &hdr, GUESTFS_PROC_INOTIFY_RM_WATCH, serial) == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "inotify_rm_watch", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "inotify_rm_watch", "-1");
    if (err.errno_string[0] != '\0')
      errnum = guestfs_int_string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "inotify_rm_watch", err.error_message);
    else
      guestfs_int_error_errno (g, errnum, "%s: %s", "inotify_rm_watch",
                               err.error_message);
    free (err.error_message);
    free (err.errno_string);
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "inotify_rm_watch");
    fprintf (trace_buffer.fp, "%d", ret_v);
    guestfs_int_trace_send_line (g, &trace_buffer);
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
  struct trace_buffer trace_buffer;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs_int_call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                      "is_symlink", 10);
  if (path == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "is_symlink", "path");
    return -1;
  }

  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "is_symlink");
    fprintf (trace_buffer.fp, " \"%s\"", path);
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  if (guestfs_int_check_appliance_up (g, "is_symlink") == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "is_symlink", "-1");
    return -1;
  }

  args.path = (char *) path;
  serial = guestfs_int_send (g, GUESTFS_PROC_IS_SYMLINK,
                             progress_hint, 0,
                             (xdrproc_t) xdr_guestfs_is_symlink_args, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "is_symlink", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs_int_recv (g, "is_symlink", &hdr, &err,
        (xdrproc_t) xdr_guestfs_is_symlink_ret, (char *) &ret);
  if (r == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "is_symlink", "-1");
    return -1;
  }

  if (guestfs_int_check_reply_header (g, &hdr, GUESTFS_PROC_IS_SYMLINK, serial) == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "is_symlink", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "is_symlink", "-1");
    if (err.errno_string[0] != '\0')
      errnum = guestfs_int_string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "is_symlink", err.error_message);
    else
      guestfs_int_error_errno (g, errnum, "%s: %s", "is_symlink",
                               err.error_message);
    free (err.error_message);
    free (err.errno_string);
    return -1;
  }

  ret_v = ret.flag;
  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "is_symlink");
    fprintf (trace_buffer.fp, "%d", ret_v);
    guestfs_int_trace_send_line (g, &trace_buffer);
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
  struct trace_buffer trace_buffer;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs_int_call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                      "is_zero", 7);
  if (path == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "is_zero", "path");
    return -1;
  }

  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "is_zero");
    fprintf (trace_buffer.fp, " \"%s\"", path);
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  if (guestfs_int_check_appliance_up (g, "is_zero") == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "is_zero", "-1");
    return -1;
  }

  args.path = (char *) path;
  serial = guestfs_int_send (g, GUESTFS_PROC_IS_ZERO,
                             progress_hint, 0,
                             (xdrproc_t) xdr_guestfs_is_zero_args, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "is_zero", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs_int_recv (g, "is_zero", &hdr, &err,
        (xdrproc_t) xdr_guestfs_is_zero_ret, (char *) &ret);
  if (r == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "is_zero", "-1");
    return -1;
  }

  if (guestfs_int_check_reply_header (g, &hdr, GUESTFS_PROC_IS_ZERO, serial) == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "is_zero", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "is_zero", "-1");
    if (err.errno_string[0] != '\0')
      errnum = guestfs_int_string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "is_zero", err.error_message);
    else
      guestfs_int_error_errno (g, errnum, "%s: %s", "is_zero",
                               err.error_message);
    free (err.error_message);
    free (err.errno_string);
    return -1;
  }

  ret_v = ret.zeroflag;
  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "is_zero");
    fprintf (trace_buffer.fp, "%d", ret_v);
    guestfs_int_trace_send_line (g, &trace_buffer);
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
  struct trace_buffer trace_buffer;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs_int_call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                      "lchown", 6);
  if (path == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "lchown", "path");
    return -1;
  }

  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "lchown");
    fprintf (trace_buffer.fp, " %d", owner);
    fprintf (trace_buffer.fp, " %d", group);
    fprintf (trace_buffer.fp, " \"%s\"", path);
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  if (guestfs_int_check_appliance_up (g, "lchown") == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "lchown", "-1");
    return -1;
  }

  args.owner = owner;
  args.group = group;
  args.path = (char *) path;
  serial = guestfs_int_send (g, GUESTFS_PROC_LCHOWN,
                             progress_hint, 0,
                             (xdrproc_t) xdr_guestfs_lchown_args, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "lchown", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs_int_recv (g, "lchown", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "lchown", "-1");
    return -1;
  }

  if (guestfs_int_check_reply_header (g, &hdr, GUESTFS_PROC_LCHOWN, serial) == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "lchown", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "lchown", "-1");
    if (err.errno_string[0] != '\0')
      errnum = guestfs_int_string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "lchown", err.error_message);
    else
      guestfs_int_error_errno (g, errnum, "%s: %s", "lchown",
                               err.error_message);
    free (err.error_message);
    free (err.errno_string);
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "lchown");
    fprintf (trace_buffer.fp, "%d", ret_v);
    guestfs_int_trace_send_line (g, &trace_buffer);
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
  struct trace_buffer trace_buffer;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs_int_call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                      "ldmtool_create_all", 18);
  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "ldmtool_create_all");
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  if (guestfs_int_check_appliance_up (g, "ldmtool_create_all") == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "ldmtool_create_all", "-1");
    return -1;
  }

  serial = guestfs_int_send (g, GUESTFS_PROC_LDMTOOL_CREATE_ALL, progress_hint, 0,
                             NULL, NULL);
  if (serial == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "ldmtool_create_all", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs_int_recv (g, "ldmtool_create_all", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "ldmtool_create_all", "-1");
    return -1;
  }

  if (guestfs_int_check_reply_header (g, &hdr, GUESTFS_PROC_LDMTOOL_CREATE_ALL, serial) == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "ldmtool_create_all", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "ldmtool_create_all", "-1");
    if (err.errno_string[0] != '\0')
      errnum = guestfs_int_string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "ldmtool_create_all", err.error_message);
    else
      guestfs_int_error_errno (g, errnum, "%s: %s", "ldmtool_create_all",
                               err.error_message);
    free (err.error_message);
    free (err.errno_string);
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "ldmtool_create_all");
    fprintf (trace_buffer.fp, "%d", ret_v);
    guestfs_int_trace_send_line (g, &trace_buffer);
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
  struct trace_buffer trace_buffer;
  char **ret_v;
  const uint64_t progress_hint = 0;

  guestfs_int_call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                      "ldmtool_diskgroup_disks", 23);
  if (diskgroup == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "ldmtool_diskgroup_disks", "diskgroup");
    return NULL;
  }

  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "ldmtool_diskgroup_disks");
    fprintf (trace_buffer.fp, " \"%s\"", diskgroup);
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  if (guestfs_int_check_appliance_up (g, "ldmtool_diskgroup_disks") == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "ldmtool_diskgroup_disks", "NULL");
    return NULL;
  }

  args.diskgroup = (char *) diskgroup;
  serial = guestfs_int_send (g, GUESTFS_PROC_LDMTOOL_DISKGROUP_DISKS,
                             progress_hint, 0,
                             (xdrproc_t) xdr_guestfs_ldmtool_diskgroup_disks_args, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "ldmtool_diskgroup_disks", "NULL");
    return NULL;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs_int_recv (g, "ldmtool_diskgroup_disks", &hdr, &err,
        (xdrproc_t) xdr_guestfs_ldmtool_diskgroup_disks_ret, (char *) &ret);
  if (r == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "ldmtool_diskgroup_disks", "NULL");
    return NULL;
  }

  if (guestfs_int_check_reply_header (g, &hdr, GUESTFS_PROC_LDMTOOL_DISKGROUP_DISKS, serial) == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "ldmtool_diskgroup_disks", "NULL");
    return NULL;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "ldmtool_diskgroup_disks", "NULL");
    if (err.errno_string[0] != '\0')
      errnum = guestfs_int_string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "ldmtool_diskgroup_disks", err.error_message);
    else
      guestfs_int_error_errno (g, errnum, "%s: %s", "ldmtool_diskgroup_disks",
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

    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "ldmtool_diskgroup_disks");
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
guestfs_list_partitions (guestfs_h *g)
{
  guestfs_message_header hdr;
  guestfs_message_error err;
  struct guestfs_list_partitions_ret ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  char **ret_v;
  const uint64_t progress_hint = 0;

  guestfs_int_call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                      "list_partitions", 15);
  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "list_partitions");
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  if (guestfs_int_check_appliance_up (g, "list_partitions") == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "list_partitions", "NULL");
    return NULL;
  }

  serial = guestfs_int_send (g, GUESTFS_PROC_LIST_PARTITIONS, progress_hint, 0,
                             NULL, NULL);
  if (serial == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "list_partitions", "NULL");
    return NULL;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs_int_recv (g, "list_partitions", &hdr, &err,
        (xdrproc_t) xdr_guestfs_list_partitions_ret, (char *) &ret);
  if (r == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "list_partitions", "NULL");
    return NULL;
  }

  if (guestfs_int_check_reply_header (g, &hdr, GUESTFS_PROC_LIST_PARTITIONS, serial) == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "list_partitions", "NULL");
    return NULL;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "list_partitions", "NULL");
    if (err.errno_string[0] != '\0')
      errnum = guestfs_int_string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "list_partitions", err.error_message);
    else
      guestfs_int_error_errno (g, errnum, "%s: %s", "list_partitions",
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
    fprintf (trace_buffer.fp, "%s = ", "list_partitions");
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
  struct trace_buffer trace_buffer;
  char *ret_v;
  const uint64_t progress_hint = 0;

  guestfs_int_call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                      "llz", 3);
  if (directory == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "llz", "directory");
    return NULL;
  }

  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "llz");
    fprintf (trace_buffer.fp, " \"%s\"", directory);
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  if (guestfs_int_check_appliance_up (g, "llz") == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "llz", "NULL");
    return NULL;
  }

  args.directory = (char *) directory;
  serial = guestfs_int_send (g, GUESTFS_PROC_LLZ,
                             progress_hint, 0,
                             (xdrproc_t) xdr_guestfs_llz_args, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "llz", "NULL");
    return NULL;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs_int_recv (g, "llz", &hdr, &err,
        (xdrproc_t) xdr_guestfs_llz_ret, (char *) &ret);
  if (r == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "llz", "NULL");
    return NULL;
  }

  if (guestfs_int_check_reply_header (g, &hdr, GUESTFS_PROC_LLZ, serial) == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "llz", "NULL");
    return NULL;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "llz", "NULL");
    if (err.errno_string[0] != '\0')
      errnum = guestfs_int_string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "llz", err.error_message);
    else
      guestfs_int_error_errno (g, errnum, "%s: %s", "llz",
                               err.error_message);
    free (err.error_message);
    free (err.errno_string);
    return NULL;
  }

  ret_v = ret.listing; /* caller will free */
  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "llz");
    fprintf (trace_buffer.fp, "\"%s\"", ret_v);
    guestfs_int_trace_send_line (g, &trace_buffer);
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
  struct trace_buffer trace_buffer;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs_int_call_callbacks_message (g, GUESTFS_EVENT_ENTER,
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
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "luks_open");
    fprintf (trace_buffer.fp, " \"%s\"", device);
    fprintf (trace_buffer.fp, " \"***\"");
    fprintf (trace_buffer.fp, " \"%s\"", mapname);
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  if (guestfs_int_check_appliance_up (g, "luks_open") == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "luks_open", "-1");
    return -1;
  }

  args.device = (char *) device;
  args.key = (char *) key;
  args.mapname = (char *) mapname;
  serial = guestfs_int_send (g, GUESTFS_PROC_LUKS_OPEN,
                             progress_hint, 0,
                             (xdrproc_t) xdr_guestfs_luks_open_args, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "luks_open", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs_int_recv (g, "luks_open", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "luks_open", "-1");
    return -1;
  }

  if (guestfs_int_check_reply_header (g, &hdr, GUESTFS_PROC_LUKS_OPEN, serial) == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "luks_open", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "luks_open", "-1");
    if (err.errno_string[0] != '\0')
      errnum = guestfs_int_string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "luks_open", err.error_message);
    else
      guestfs_int_error_errno (g, errnum, "%s: %s", "luks_open",
                               err.error_message);
    free (err.error_message);
    free (err.errno_string);
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "luks_open");
    fprintf (trace_buffer.fp, "%d", ret_v);
    guestfs_int_trace_send_line (g, &trace_buffer);
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
  struct trace_buffer trace_buffer;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs_int_call_callbacks_message (g, GUESTFS_EVENT_ENTER,
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
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "luks_open_ro");
    fprintf (trace_buffer.fp, " \"%s\"", device);
    fprintf (trace_buffer.fp, " \"***\"");
    fprintf (trace_buffer.fp, " \"%s\"", mapname);
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  if (guestfs_int_check_appliance_up (g, "luks_open_ro") == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "luks_open_ro", "-1");
    return -1;
  }

  args.device = (char *) device;
  args.key = (char *) key;
  args.mapname = (char *) mapname;
  serial = guestfs_int_send (g, GUESTFS_PROC_LUKS_OPEN_RO,
                             progress_hint, 0,
                             (xdrproc_t) xdr_guestfs_luks_open_ro_args, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "luks_open_ro", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs_int_recv (g, "luks_open_ro", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "luks_open_ro", "-1");
    return -1;
  }

  if (guestfs_int_check_reply_header (g, &hdr, GUESTFS_PROC_LUKS_OPEN_RO, serial) == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "luks_open_ro", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "luks_open_ro", "-1");
    if (err.errno_string[0] != '\0')
      errnum = guestfs_int_string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "luks_open_ro", err.error_message);
    else
      guestfs_int_error_errno (g, errnum, "%s: %s", "luks_open_ro",
                               err.error_message);
    free (err.error_message);
    free (err.errno_string);
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "luks_open_ro");
    fprintf (trace_buffer.fp, "%d", ret_v);
    guestfs_int_trace_send_line (g, &trace_buffer);
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
  struct trace_buffer trace_buffer;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs_int_call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                      "lvm_remove_all", 14);
  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "lvm_remove_all");
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  if (guestfs_int_check_appliance_up (g, "lvm_remove_all") == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "lvm_remove_all", "-1");
    return -1;
  }

  serial = guestfs_int_send (g, GUESTFS_PROC_LVM_REMOVE_ALL, progress_hint, 0,
                             NULL, NULL);
  if (serial == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "lvm_remove_all", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs_int_recv (g, "lvm_remove_all", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "lvm_remove_all", "-1");
    return -1;
  }

  if (guestfs_int_check_reply_header (g, &hdr, GUESTFS_PROC_LVM_REMOVE_ALL, serial) == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "lvm_remove_all", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "lvm_remove_all", "-1");
    if (err.errno_string[0] != '\0')
      errnum = guestfs_int_string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "lvm_remove_all", err.error_message);
    else
      guestfs_int_error_errno (g, errnum, "%s: %s", "lvm_remove_all",
                               err.error_message);
    free (err.error_message);
    free (err.errno_string);
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "lvm_remove_all");
    fprintf (trace_buffer.fp, "%d", ret_v);
    guestfs_int_trace_send_line (g, &trace_buffer);
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
  struct trace_buffer trace_buffer;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs_int_call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                      "lvresize_free", 13);
  if (lv == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "lvresize_free", "lv");
    return -1;
  }

  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "lvresize_free");
    fprintf (trace_buffer.fp, " \"%s\"", lv);
    fprintf (trace_buffer.fp, " %d", percent);
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  if (guestfs_int_check_appliance_up (g, "lvresize_free") == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "lvresize_free", "-1");
    return -1;
  }

  args.lv = (char *) lv;
  args.percent = percent;
  serial = guestfs_int_send (g, GUESTFS_PROC_LVRESIZE_FREE,
                             progress_hint, 0,
                             (xdrproc_t) xdr_guestfs_lvresize_free_args, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "lvresize_free", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs_int_recv (g, "lvresize_free", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "lvresize_free", "-1");
    return -1;
  }

  if (guestfs_int_check_reply_header (g, &hdr, GUESTFS_PROC_LVRESIZE_FREE, serial) == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "lvresize_free", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "lvresize_free", "-1");
    if (err.errno_string[0] != '\0')
      errnum = guestfs_int_string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "lvresize_free", err.error_message);
    else
      guestfs_int_error_errno (g, errnum, "%s: %s", "lvresize_free",
                               err.error_message);
    free (err.error_message);
    free (err.errno_string);
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "lvresize_free");
    fprintf (trace_buffer.fp, "%d", ret_v);
    guestfs_int_trace_send_line (g, &trace_buffer);
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
  struct trace_buffer trace_buffer;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs_int_call_callbacks_message (g, GUESTFS_EVENT_ENTER,
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

    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "md_create");
    fprintf (trace_buffer.fp, " \"%s\"", name);
    fputc (' ', trace_buffer.fp);
    fputc ('"', trace_buffer.fp);
    for (i = 0; devices[i]; ++i) {
      if (i > 0) fputc (' ', trace_buffer.fp);
      fputs (devices[i], trace_buffer.fp);
    }
    fputc ('"', trace_buffer.fp);
    if (optargs->bitmask & GUESTFS_MD_CREATE_MISSINGBITMAP_BITMASK) {
      fprintf (trace_buffer.fp, " \"%s:%" PRIi64 "\"", "missingbitmap", optargs->missingbitmap);
    }
    if (optargs->bitmask & GUESTFS_MD_CREATE_NRDEVICES_BITMASK) {
      fprintf (trace_buffer.fp, " \"%s:%d\"", "nrdevices", optargs->nrdevices);
    }
    if (optargs->bitmask & GUESTFS_MD_CREATE_SPARE_BITMASK) {
      fprintf (trace_buffer.fp, " \"%s:%d\"", "spare", optargs->spare);
    }
    if (optargs->bitmask & GUESTFS_MD_CREATE_CHUNK_BITMASK) {
      fprintf (trace_buffer.fp, " \"%s:%" PRIi64 "\"", "chunk", optargs->chunk);
    }
    if (optargs->bitmask & GUESTFS_MD_CREATE_LEVEL_BITMASK) {
      fprintf (trace_buffer.fp, " \"%s:%s\"", "level", optargs->level);
    }
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  if (guestfs_int_check_appliance_up (g, "md_create") == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
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
  serial = guestfs_int_send (g, GUESTFS_PROC_MD_CREATE,
                             progress_hint, optargs->bitmask,
                             (xdrproc_t) xdr_guestfs_md_create_args, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "md_create", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs_int_recv (g, "md_create", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "md_create", "-1");
    return -1;
  }

  if (guestfs_int_check_reply_header (g, &hdr, GUESTFS_PROC_MD_CREATE, serial) == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "md_create", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "md_create", "-1");
    if (err.errno_string[0] != '\0')
      errnum = guestfs_int_string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "md_create", err.error_message);
    else
      guestfs_int_error_errno (g, errnum, "%s: %s", "md_create",
                               err.error_message);
    free (err.error_message);
    free (err.errno_string);
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "md_create");
    fprintf (trace_buffer.fp, "%d", ret_v);
    guestfs_int_trace_send_line (g, &trace_buffer);
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
  struct trace_buffer trace_buffer;
  char *ret_v;
  const uint64_t progress_hint = 0;

  guestfs_int_call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                      "mkdtemp", 7);
  if (tmpl == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "mkdtemp", "tmpl");
    return NULL;
  }

  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "mkdtemp");
    fprintf (trace_buffer.fp, " \"%s\"", tmpl);
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  if (guestfs_int_check_appliance_up (g, "mkdtemp") == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "mkdtemp", "NULL");
    return NULL;
  }

  args.tmpl = (char *) tmpl;
  serial = guestfs_int_send (g, GUESTFS_PROC_MKDTEMP,
                             progress_hint, 0,
                             (xdrproc_t) xdr_guestfs_mkdtemp_args, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "mkdtemp", "NULL");
    return NULL;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs_int_recv (g, "mkdtemp", &hdr, &err,
        (xdrproc_t) xdr_guestfs_mkdtemp_ret, (char *) &ret);
  if (r == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "mkdtemp", "NULL");
    return NULL;
  }

  if (guestfs_int_check_reply_header (g, &hdr, GUESTFS_PROC_MKDTEMP, serial) == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "mkdtemp", "NULL");
    return NULL;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "mkdtemp", "NULL");
    if (err.errno_string[0] != '\0')
      errnum = guestfs_int_string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "mkdtemp", err.error_message);
    else
      guestfs_int_error_errno (g, errnum, "%s: %s", "mkdtemp",
                               err.error_message);
    free (err.error_message);
    free (err.errno_string);
    return NULL;
  }

  ret_v = ret.dir; /* caller will free */
  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "mkdtemp");
    fprintf (trace_buffer.fp, "\"%s\"", ret_v);
    guestfs_int_trace_send_line (g, &trace_buffer);
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
  struct trace_buffer trace_buffer;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs_int_call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                      "mknod", 5);
  if (path == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "mknod", "path");
    return -1;
  }

  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "mknod");
    fprintf (trace_buffer.fp, " %d", mode);
    fprintf (trace_buffer.fp, " %d", devmajor);
    fprintf (trace_buffer.fp, " %d", devminor);
    fprintf (trace_buffer.fp, " \"%s\"", path);
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  if (guestfs_int_check_appliance_up (g, "mknod") == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "mknod", "-1");
    return -1;
  }

  args.mode = mode;
  args.devmajor = devmajor;
  args.devminor = devminor;
  args.path = (char *) path;
  serial = guestfs_int_send (g, GUESTFS_PROC_MKNOD,
                             progress_hint, 0,
                             (xdrproc_t) xdr_guestfs_mknod_args, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "mknod", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs_int_recv (g, "mknod", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "mknod", "-1");
    return -1;
  }

  if (guestfs_int_check_reply_header (g, &hdr, GUESTFS_PROC_MKNOD, serial) == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "mknod", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "mknod", "-1");
    if (err.errno_string[0] != '\0')
      errnum = guestfs_int_string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "mknod", err.error_message);
    else
      guestfs_int_error_errno (g, errnum, "%s: %s", "mknod",
                               err.error_message);
    free (err.error_message);
    free (err.errno_string);
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "mknod");
    fprintf (trace_buffer.fp, "%d", ret_v);
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  return ret_v;
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
  struct trace_buffer trace_buffer;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs_int_call_callbacks_message (g, GUESTFS_EVENT_ENTER,
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
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "mount");
    fprintf (trace_buffer.fp, " \"%s\"", mountable);
    fprintf (trace_buffer.fp, " \"%s\"", mountpoint);
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  if (guestfs_int_check_appliance_up (g, "mount") == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "mount", "-1");
    return -1;
  }

  args.mountable = (char *) mountable;
  args.mountpoint = (char *) mountpoint;
  serial = guestfs_int_send (g, GUESTFS_PROC_MOUNT,
                             progress_hint, 0,
                             (xdrproc_t) xdr_guestfs_mount_args, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "mount", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs_int_recv (g, "mount", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "mount", "-1");
    return -1;
  }

  if (guestfs_int_check_reply_header (g, &hdr, GUESTFS_PROC_MOUNT, serial) == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "mount", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "mount", "-1");
    if (err.errno_string[0] != '\0')
      errnum = guestfs_int_string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "mount", err.error_message);
    else
      guestfs_int_error_errno (g, errnum, "%s: %s", "mount",
                               err.error_message);
    free (err.error_message);
    free (err.errno_string);
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "mount");
    fprintf (trace_buffer.fp, "%d", ret_v);
    guestfs_int_trace_send_line (g, &trace_buffer);
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
  struct trace_buffer trace_buffer;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs_int_call_callbacks_message (g, GUESTFS_EVENT_ENTER,
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
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "mount_ro");
    fprintf (trace_buffer.fp, " \"%s\"", mountable);
    fprintf (trace_buffer.fp, " \"%s\"", mountpoint);
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  if (guestfs_int_check_appliance_up (g, "mount_ro") == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "mount_ro", "-1");
    return -1;
  }

  args.mountable = (char *) mountable;
  args.mountpoint = (char *) mountpoint;
  serial = guestfs_int_send (g, GUESTFS_PROC_MOUNT_RO,
                             progress_hint, 0,
                             (xdrproc_t) xdr_guestfs_mount_ro_args, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "mount_ro", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs_int_recv (g, "mount_ro", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "mount_ro", "-1");
    return -1;
  }

  if (guestfs_int_check_reply_header (g, &hdr, GUESTFS_PROC_MOUNT_RO, serial) == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "mount_ro", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "mount_ro", "-1");
    if (err.errno_string[0] != '\0')
      errnum = guestfs_int_string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "mount_ro", err.error_message);
    else
      guestfs_int_error_errno (g, errnum, "%s: %s", "mount_ro",
                               err.error_message);
    free (err.error_message);
    free (err.errno_string);
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "mount_ro");
    fprintf (trace_buffer.fp, "%d", ret_v);
    guestfs_int_trace_send_line (g, &trace_buffer);
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
  struct trace_buffer trace_buffer;
  char **ret_v;
  const uint64_t progress_hint = 0;

  guestfs_int_call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                      "mounts", 6);
  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "mounts");
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  if (guestfs_int_check_appliance_up (g, "mounts") == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "mounts", "NULL");
    return NULL;
  }

  serial = guestfs_int_send (g, GUESTFS_PROC_MOUNTS, progress_hint, 0,
                             NULL, NULL);
  if (serial == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "mounts", "NULL");
    return NULL;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs_int_recv (g, "mounts", &hdr, &err,
        (xdrproc_t) xdr_guestfs_mounts_ret, (char *) &ret);
  if (r == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "mounts", "NULL");
    return NULL;
  }

  if (guestfs_int_check_reply_header (g, &hdr, GUESTFS_PROC_MOUNTS, serial) == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "mounts", "NULL");
    return NULL;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "mounts", "NULL");
    if (err.errno_string[0] != '\0')
      errnum = guestfs_int_string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "mounts", err.error_message);
    else
      guestfs_int_error_errno (g, errnum, "%s: %s", "mounts",
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
    fprintf (trace_buffer.fp, "%s = ", "mounts");
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
  struct trace_buffer trace_buffer;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs_int_call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                      "ntfs_3g_probe", 13);
  if (device == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "ntfs_3g_probe", "device");
    return -1;
  }

  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "ntfs_3g_probe");
    fputs (rw ? " true" : " false", trace_buffer.fp);
    fprintf (trace_buffer.fp, " \"%s\"", device);
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  if (guestfs_int_check_appliance_up (g, "ntfs_3g_probe") == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "ntfs_3g_probe", "-1");
    return -1;
  }

  args.rw = rw;
  args.device = (char *) device;
  serial = guestfs_int_send (g, GUESTFS_PROC_NTFS_3G_PROBE,
                             progress_hint, 0,
                             (xdrproc_t) xdr_guestfs_ntfs_3g_probe_args, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "ntfs_3g_probe", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs_int_recv (g, "ntfs_3g_probe", &hdr, &err,
        (xdrproc_t) xdr_guestfs_ntfs_3g_probe_ret, (char *) &ret);
  if (r == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "ntfs_3g_probe", "-1");
    return -1;
  }

  if (guestfs_int_check_reply_header (g, &hdr, GUESTFS_PROC_NTFS_3G_PROBE, serial) == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "ntfs_3g_probe", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "ntfs_3g_probe", "-1");
    if (err.errno_string[0] != '\0')
      errnum = guestfs_int_string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "ntfs_3g_probe", err.error_message);
    else
      guestfs_int_error_errno (g, errnum, "%s: %s", "ntfs_3g_probe",
                               err.error_message);
    free (err.error_message);
    free (err.errno_string);
    return -1;
  }

  ret_v = ret.status;
  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "ntfs_3g_probe");
    fprintf (trace_buffer.fp, "%d", ret_v);
    guestfs_int_trace_send_line (g, &trace_buffer);
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
  struct trace_buffer trace_buffer;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs_int_call_callbacks_message (g, GUESTFS_EVENT_ENTER,
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
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "ntfsclone_out");
    fprintf (trace_buffer.fp, " \"%s\"", device);
    fprintf (trace_buffer.fp, " \"%s\"", backupfile);
    if (optargs->bitmask & GUESTFS_NTFSCLONE_OUT_METADATAONLY_BITMASK) {
      fprintf (trace_buffer.fp, " \"%s:%s\"", "metadataonly", optargs->metadataonly ? "true" : "false");
    }
    if (optargs->bitmask & GUESTFS_NTFSCLONE_OUT_RESCUE_BITMASK) {
      fprintf (trace_buffer.fp, " \"%s:%s\"", "rescue", optargs->rescue ? "true" : "false");
    }
    if (optargs->bitmask & GUESTFS_NTFSCLONE_OUT_IGNOREFSCHECK_BITMASK) {
      fprintf (trace_buffer.fp, " \"%s:%s\"", "ignorefscheck", optargs->ignorefscheck ? "true" : "false");
    }
    if (optargs->bitmask & GUESTFS_NTFSCLONE_OUT_PRESERVETIMESTAMPS_BITMASK) {
      fprintf (trace_buffer.fp, " \"%s:%s\"", "preservetimestamps", optargs->preservetimestamps ? "true" : "false");
    }
    if (optargs->bitmask & GUESTFS_NTFSCLONE_OUT_FORCE_BITMASK) {
      fprintf (trace_buffer.fp, " \"%s:%s\"", "force", optargs->force ? "true" : "false");
    }
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  if (guestfs_int_check_appliance_up (g, "ntfsclone_out") == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
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
  serial = guestfs_int_send (g, GUESTFS_PROC_NTFSCLONE_OUT,
                             progress_hint, optargs->bitmask,
                             (xdrproc_t) xdr_guestfs_ntfsclone_out_args, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "ntfsclone_out", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs_int_recv (g, "ntfsclone_out", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "ntfsclone_out", "-1");
    return -1;
  }

  if (guestfs_int_check_reply_header (g, &hdr, GUESTFS_PROC_NTFSCLONE_OUT, serial) == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "ntfsclone_out", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "ntfsclone_out", "-1");
    if (err.errno_string[0] != '\0')
      errnum = guestfs_int_string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "ntfsclone_out", err.error_message);
    else
      guestfs_int_error_errno (g, errnum, "%s: %s", "ntfsclone_out",
                               err.error_message);
    free (err.error_message);
    free (err.errno_string);
    return -1;
  }

  if (guestfs_int_recv_file (g, backupfile) == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "ntfsclone_out", "-1");
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "ntfsclone_out");
    fprintf (trace_buffer.fp, "%d", ret_v);
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  return ret_v;
}

GUESTFS_DLL_PUBLIC int
guestfs_part_set_disk_guid (guestfs_h *g,
                            const char *device,
                            const char *guid)
{
  struct guestfs_part_set_disk_guid_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs_int_call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                      "part_set_disk_guid", 18);
  if (device == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "part_set_disk_guid", "device");
    return -1;
  }
  if (guid == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "part_set_disk_guid", "guid");
    return -1;
  }

  if (!guestfs_int_validate_guid (guid)) {
    error (g, "%s: %s: parameter is not a valid GUID",
           "part_set_disk_guid", "guid");
    return -1;
  }

  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "part_set_disk_guid");
    fprintf (trace_buffer.fp, " \"%s\"", device);
    fprintf (trace_buffer.fp, " \"%s\"", guid);
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  if (guestfs_int_check_appliance_up (g, "part_set_disk_guid") == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "part_set_disk_guid", "-1");
    return -1;
  }

  args.device = (char *) device;
  args.guid = (char *) guid;
  serial = guestfs_int_send (g, GUESTFS_PROC_PART_SET_DISK_GUID,
                             progress_hint, 0,
                             (xdrproc_t) xdr_guestfs_part_set_disk_guid_args, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "part_set_disk_guid", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs_int_recv (g, "part_set_disk_guid", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "part_set_disk_guid", "-1");
    return -1;
  }

  if (guestfs_int_check_reply_header (g, &hdr, GUESTFS_PROC_PART_SET_DISK_GUID, serial) == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "part_set_disk_guid", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "part_set_disk_guid", "-1");
    if (err.errno_string[0] != '\0')
      errnum = guestfs_int_string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "part_set_disk_guid", err.error_message);
    else
      guestfs_int_error_errno (g, errnum, "%s: %s", "part_set_disk_guid",
                               err.error_message);
    free (err.error_message);
    free (err.errno_string);
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "part_set_disk_guid");
    fprintf (trace_buffer.fp, "%d", ret_v);
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  return ret_v;
}

GUESTFS_DLL_PUBLIC int
guestfs_part_set_disk_guid_random (guestfs_h *g,
                                   const char *device)
{
  struct guestfs_part_set_disk_guid_random_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs_int_call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                      "part_set_disk_guid_random", 25);
  if (device == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "part_set_disk_guid_random", "device");
    return -1;
  }

  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "part_set_disk_guid_random");
    fprintf (trace_buffer.fp, " \"%s\"", device);
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  if (guestfs_int_check_appliance_up (g, "part_set_disk_guid_random") == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "part_set_disk_guid_random", "-1");
    return -1;
  }

  args.device = (char *) device;
  serial = guestfs_int_send (g, GUESTFS_PROC_PART_SET_DISK_GUID_RANDOM,
                             progress_hint, 0,
                             (xdrproc_t) xdr_guestfs_part_set_disk_guid_random_args, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "part_set_disk_guid_random", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs_int_recv (g, "part_set_disk_guid_random", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "part_set_disk_guid_random", "-1");
    return -1;
  }

  if (guestfs_int_check_reply_header (g, &hdr, GUESTFS_PROC_PART_SET_DISK_GUID_RANDOM, serial) == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "part_set_disk_guid_random", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "part_set_disk_guid_random", "-1");
    if (err.errno_string[0] != '\0')
      errnum = guestfs_int_string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "part_set_disk_guid_random", err.error_message);
    else
      guestfs_int_error_errno (g, errnum, "%s: %s", "part_set_disk_guid_random",
                               err.error_message);
    free (err.error_message);
    free (err.errno_string);
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "part_set_disk_guid_random");
    fprintf (trace_buffer.fp, "%d", ret_v);
    guestfs_int_trace_send_line (g, &trace_buffer);
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
  struct trace_buffer trace_buffer;
  char *ret_v;
  const uint64_t progress_hint = 0;

  guestfs_int_call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                      "pread", 5);
  if (path == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "pread", "path");
    return NULL;
  }

  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "pread");
    fprintf (trace_buffer.fp, " \"%s\"", path);
    fprintf (trace_buffer.fp, " %d", count);
    fprintf (trace_buffer.fp, " %" PRIi64, offset);
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  if (guestfs_int_check_appliance_up (g, "pread") == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "pread", "NULL");
    return NULL;
  }

  args.path = (char *) path;
  args.count = count;
  args.offset = offset;
  serial = guestfs_int_send (g, GUESTFS_PROC_PREAD,
                             progress_hint, 0,
                             (xdrproc_t) xdr_guestfs_pread_args, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "pread", "NULL");
    return NULL;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs_int_recv (g, "pread", &hdr, &err,
        (xdrproc_t) xdr_guestfs_pread_ret, (char *) &ret);
  if (r == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "pread", "NULL");
    return NULL;
  }

  if (guestfs_int_check_reply_header (g, &hdr, GUESTFS_PROC_PREAD, serial) == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "pread", "NULL");
    return NULL;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "pread", "NULL");
    if (err.errno_string[0] != '\0')
      errnum = guestfs_int_string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "pread", err.error_message);
    else
      guestfs_int_error_errno (g, errnum, "%s: %s", "pread",
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
    fprintf (trace_buffer.fp, "%s = ", "pread");
    guestfs_int_print_BufferOut (trace_buffer.fp, ret_v, *size_r);
    guestfs_int_trace_send_line (g, &trace_buffer);
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
  struct trace_buffer trace_buffer;
  char *ret_v;
  const uint64_t progress_hint = 0;

  guestfs_int_call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                      "realpath", 8);
  if (path == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "realpath", "path");
    return NULL;
  }

  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "realpath");
    fprintf (trace_buffer.fp, " \"%s\"", path);
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  if (guestfs_int_check_appliance_up (g, "realpath") == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "realpath", "NULL");
    return NULL;
  }

  args.path = (char *) path;
  serial = guestfs_int_send (g, GUESTFS_PROC_REALPATH,
                             progress_hint, 0,
                             (xdrproc_t) xdr_guestfs_realpath_args, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "realpath", "NULL");
    return NULL;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs_int_recv (g, "realpath", &hdr, &err,
        (xdrproc_t) xdr_guestfs_realpath_ret, (char *) &ret);
  if (r == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "realpath", "NULL");
    return NULL;
  }

  if (guestfs_int_check_reply_header (g, &hdr, GUESTFS_PROC_REALPATH, serial) == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "realpath", "NULL");
    return NULL;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "realpath", "NULL");
    if (err.errno_string[0] != '\0')
      errnum = guestfs_int_string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "realpath", err.error_message);
    else
      guestfs_int_error_errno (g, errnum, "%s: %s", "realpath",
                               err.error_message);
    free (err.error_message);
    free (err.errno_string);
    return NULL;
  }

  ret_v = ret.rpath; /* caller will free */
  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "realpath");
    fprintf (trace_buffer.fp, "\"%s\"", ret_v);
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  return ret_v;
}

GUESTFS_DLL_PUBLIC int
guestfs_selinux_relabel_argv (guestfs_h *g,
                              const char *specfile,
                              const char *path,
                              const struct guestfs_selinux_relabel_argv *optargs)
{
  struct guestfs_selinux_relabel_argv optargs_null;
  if (!optargs) {
    optargs_null.bitmask = 0;
    optargs = &optargs_null;
  }

  struct guestfs_selinux_relabel_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs_int_call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                      "selinux_relabel", 15);
  if (specfile == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "selinux_relabel", "specfile");
    return -1;
  }
  if (path == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "selinux_relabel", "path");
    return -1;
  }

  if (optargs->bitmask & UINT64_C(0xfffffffffffffffe)) {
    error (g, "%s: unknown option in guestfs_%s_argv->bitmask (this can happen if a program is compiled against a newer version of libguestfs, then dynamically linked to an older version)",
           "selinux_relabel", "selinux_relabel");
    return -1;
  }

  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "selinux_relabel");
    fprintf (trace_buffer.fp, " \"%s\"", specfile);
    fprintf (trace_buffer.fp, " \"%s\"", path);
    if (optargs->bitmask & GUESTFS_SELINUX_RELABEL_FORCE_BITMASK) {
      fprintf (trace_buffer.fp, " \"%s:%s\"", "force", optargs->force ? "true" : "false");
    }
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  if (guestfs_int_check_appliance_up (g, "selinux_relabel") == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "selinux_relabel", "-1");
    return -1;
  }

  args.specfile = (char *) specfile;
  args.path = (char *) path;
  if (optargs->bitmask & GUESTFS_SELINUX_RELABEL_FORCE_BITMASK) {
    args.force = optargs->force;
  } else {
    args.force = 0;
  }
  serial = guestfs_int_send (g, GUESTFS_PROC_SELINUX_RELABEL,
                             progress_hint, optargs->bitmask,
                             (xdrproc_t) xdr_guestfs_selinux_relabel_args, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "selinux_relabel", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs_int_recv (g, "selinux_relabel", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "selinux_relabel", "-1");
    return -1;
  }

  if (guestfs_int_check_reply_header (g, &hdr, GUESTFS_PROC_SELINUX_RELABEL, serial) == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "selinux_relabel", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "selinux_relabel", "-1");
    if (err.errno_string[0] != '\0')
      errnum = guestfs_int_string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "selinux_relabel", err.error_message);
    else
      guestfs_int_error_errno (g, errnum, "%s: %s", "selinux_relabel",
                               err.error_message);
    free (err.error_message);
    free (err.errno_string);
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "selinux_relabel");
    fprintf (trace_buffer.fp, "%d", ret_v);
    guestfs_int_trace_send_line (g, &trace_buffer);
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
  struct trace_buffer trace_buffer;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs_int_call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                      "swapoff_file", 12);
  if (file == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "swapoff_file", "file");
    return -1;
  }

  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "swapoff_file");
    fprintf (trace_buffer.fp, " \"%s\"", file);
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  if (guestfs_int_check_appliance_up (g, "swapoff_file") == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "swapoff_file", "-1");
    return -1;
  }

  args.file = (char *) file;
  serial = guestfs_int_send (g, GUESTFS_PROC_SWAPOFF_FILE,
                             progress_hint, 0,
                             (xdrproc_t) xdr_guestfs_swapoff_file_args, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "swapoff_file", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs_int_recv (g, "swapoff_file", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "swapoff_file", "-1");
    return -1;
  }

  if (guestfs_int_check_reply_header (g, &hdr, GUESTFS_PROC_SWAPOFF_FILE, serial) == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "swapoff_file", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "swapoff_file", "-1");
    if (err.errno_string[0] != '\0')
      errnum = guestfs_int_string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "swapoff_file", err.error_message);
    else
      guestfs_int_error_errno (g, errnum, "%s: %s", "swapoff_file",
                               err.error_message);
    free (err.error_message);
    free (err.errno_string);
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "swapoff_file");
    fprintf (trace_buffer.fp, "%d", ret_v);
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  return ret_v;
}

GUESTFS_DLL_PUBLIC int
guestfs_syslinux_argv (guestfs_h *g,
                       const char *device,
                       const struct guestfs_syslinux_argv *optargs)
{
  struct guestfs_syslinux_argv optargs_null;
  if (!optargs) {
    optargs_null.bitmask = 0;
    optargs = &optargs_null;
  }

  struct guestfs_syslinux_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs_int_call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                      "syslinux", 8);
  if (device == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "syslinux", "device");
    return -1;
  }
  if ((optargs->bitmask & GUESTFS_SYSLINUX_DIRECTORY_BITMASK) &&
      optargs->directory == NULL) {
    error (g, "%s: %s: optional parameter cannot be NULL",
           "syslinux", "directory");
    return -1;
  }

  if (optargs->bitmask & UINT64_C(0xfffffffffffffffe)) {
    error (g, "%s: unknown option in guestfs_%s_argv->bitmask (this can happen if a program is compiled against a newer version of libguestfs, then dynamically linked to an older version)",
           "syslinux", "syslinux");
    return -1;
  }

  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "syslinux");
    fprintf (trace_buffer.fp, " \"%s\"", device);
    if (optargs->bitmask & GUESTFS_SYSLINUX_DIRECTORY_BITMASK) {
      fprintf (trace_buffer.fp, " \"%s:%s\"", "directory", optargs->directory);
    }
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  if (guestfs_int_check_appliance_up (g, "syslinux") == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "syslinux", "-1");
    return -1;
  }

  args.device = (char *) device;
  if (optargs->bitmask & GUESTFS_SYSLINUX_DIRECTORY_BITMASK) {
    args.directory = (char *) optargs->directory;
  } else {
    args.directory = (char *) "";
  }
  serial = guestfs_int_send (g, GUESTFS_PROC_SYSLINUX,
                             progress_hint, optargs->bitmask,
                             (xdrproc_t) xdr_guestfs_syslinux_args, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "syslinux", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs_int_recv (g, "syslinux", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "syslinux", "-1");
    return -1;
  }

  if (guestfs_int_check_reply_header (g, &hdr, GUESTFS_PROC_SYSLINUX, serial) == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "syslinux", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "syslinux", "-1");
    if (err.errno_string[0] != '\0')
      errnum = guestfs_int_string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "syslinux", err.error_message);
    else
      guestfs_int_error_errno (g, errnum, "%s: %s", "syslinux",
                               err.error_message);
    free (err.error_message);
    free (err.errno_string);
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "syslinux");
    fprintf (trace_buffer.fp, "%d", ret_v);
    guestfs_int_trace_send_line (g, &trace_buffer);
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
  struct trace_buffer trace_buffer;
  char **ret_v;
  const uint64_t progress_hint = 0;

  guestfs_int_call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                      "tail", 4);
  if (path == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "tail", "path");
    return NULL;
  }

  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "tail");
    fprintf (trace_buffer.fp, " \"%s\"", path);
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  if (guestfs_int_check_appliance_up (g, "tail") == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "tail", "NULL");
    return NULL;
  }

  args.path = (char *) path;
  serial = guestfs_int_send (g, GUESTFS_PROC_TAIL,
                             progress_hint, 0,
                             (xdrproc_t) xdr_guestfs_tail_args, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "tail", "NULL");
    return NULL;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs_int_recv (g, "tail", &hdr, &err,
        (xdrproc_t) xdr_guestfs_tail_ret, (char *) &ret);
  if (r == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "tail", "NULL");
    return NULL;
  }

  if (guestfs_int_check_reply_header (g, &hdr, GUESTFS_PROC_TAIL, serial) == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "tail", "NULL");
    return NULL;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "tail", "NULL");
    if (err.errno_string[0] != '\0')
      errnum = guestfs_int_string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "tail", err.error_message);
    else
      guestfs_int_error_errno (g, errnum, "%s: %s", "tail",
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
    fprintf (trace_buffer.fp, "%s = ", "tail");
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
guestfs_touch (guestfs_h *g,
               const char *path)
{
  struct guestfs_touch_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;
  int trace_flag = g->trace;
  struct trace_buffer trace_buffer;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs_int_call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                      "touch", 5);
  if (path == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "touch", "path");
    return -1;
  }

  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "touch");
    fprintf (trace_buffer.fp, " \"%s\"", path);
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  if (guestfs_int_check_appliance_up (g, "touch") == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "touch", "-1");
    return -1;
  }

  args.path = (char *) path;
  serial = guestfs_int_send (g, GUESTFS_PROC_TOUCH,
                             progress_hint, 0,
                             (xdrproc_t) xdr_guestfs_touch_args, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "touch", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs_int_recv (g, "touch", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "touch", "-1");
    return -1;
  }

  if (guestfs_int_check_reply_header (g, &hdr, GUESTFS_PROC_TOUCH, serial) == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "touch", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "touch", "-1");
    if (err.errno_string[0] != '\0')
      errnum = guestfs_int_string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "touch", err.error_message);
    else
      guestfs_int_error_errno (g, errnum, "%s: %s", "touch",
                               err.error_message);
    free (err.error_message);
    free (err.errno_string);
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "touch");
    fprintf (trace_buffer.fp, "%d", ret_v);
    guestfs_int_trace_send_line (g, &trace_buffer);
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
  struct trace_buffer trace_buffer;
  char **ret_v;
  const uint64_t progress_hint = 0;

  guestfs_int_call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                      "tune2fs_l", 9);
  if (device == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "tune2fs_l", "device");
    return NULL;
  }

  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "tune2fs_l");
    fprintf (trace_buffer.fp, " \"%s\"", device);
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  if (guestfs_int_check_appliance_up (g, "tune2fs_l") == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "tune2fs_l", "NULL");
    return NULL;
  }

  args.device = (char *) device;
  serial = guestfs_int_send (g, GUESTFS_PROC_TUNE2FS_L,
                             progress_hint, 0,
                             (xdrproc_t) xdr_guestfs_tune2fs_l_args, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "tune2fs_l", "NULL");
    return NULL;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs_int_recv (g, "tune2fs_l", &hdr, &err,
        (xdrproc_t) xdr_guestfs_tune2fs_l_ret, (char *) &ret);
  if (r == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "tune2fs_l", "NULL");
    return NULL;
  }

  if (guestfs_int_check_reply_header (g, &hdr, GUESTFS_PROC_TUNE2FS_L, serial) == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "tune2fs_l", "NULL");
    return NULL;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "tune2fs_l", "NULL");
    if (err.errno_string[0] != '\0')
      errnum = guestfs_int_string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "tune2fs_l", err.error_message);
    else
      guestfs_int_error_errno (g, errnum, "%s: %s", "tune2fs_l",
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

    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "tune2fs_l");
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
  struct trace_buffer trace_buffer;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs_int_call_callbacks_message (g, GUESTFS_EVENT_ENTER,
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
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "umount");
    fprintf (trace_buffer.fp, " \"%s\"", pathordevice);
    if (optargs->bitmask & GUESTFS_UMOUNT_OPTS_FORCE_BITMASK) {
      fprintf (trace_buffer.fp, " \"%s:%s\"", "force", optargs->force ? "true" : "false");
    }
    if (optargs->bitmask & GUESTFS_UMOUNT_OPTS_LAZYUNMOUNT_BITMASK) {
      fprintf (trace_buffer.fp, " \"%s:%s\"", "lazyunmount", optargs->lazyunmount ? "true" : "false");
    }
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  if (guestfs_int_check_appliance_up (g, "umount") == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
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
  serial = guestfs_int_send (g, GUESTFS_PROC_UMOUNT,
                             progress_hint, optargs->bitmask,
                             (xdrproc_t) xdr_guestfs_umount_args, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "umount", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs_int_recv (g, "umount", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "umount", "-1");
    return -1;
  }

  if (guestfs_int_check_reply_header (g, &hdr, GUESTFS_PROC_UMOUNT, serial) == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "umount", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "umount", "-1");
    if (err.errno_string[0] != '\0')
      errnum = guestfs_int_string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "umount", err.error_message);
    else
      guestfs_int_error_errno (g, errnum, "%s: %s", "umount",
                               err.error_message);
    free (err.error_message);
    free (err.errno_string);
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "umount");
    fprintf (trace_buffer.fp, "%d", ret_v);
    guestfs_int_trace_send_line (g, &trace_buffer);
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
  struct trace_buffer trace_buffer;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs_int_call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                      "vg_activate", 11);
  if (volgroups == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "vg_activate", "volgroups");
    return -1;
  }

  if (trace_flag) {
    size_t i;

    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "vg_activate");
    fputs (activate ? " true" : " false", trace_buffer.fp);
    fputc (' ', trace_buffer.fp);
    fputc ('"', trace_buffer.fp);
    for (i = 0; volgroups[i]; ++i) {
      if (i > 0) fputc (' ', trace_buffer.fp);
      fputs (volgroups[i], trace_buffer.fp);
    }
    fputc ('"', trace_buffer.fp);
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  if (guestfs_int_check_appliance_up (g, "vg_activate") == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "vg_activate", "-1");
    return -1;
  }

  args.activate = activate;
  args.volgroups.volgroups_val = (char **) volgroups;
  for (args.volgroups.volgroups_len = 0; volgroups[args.volgroups.volgroups_len]; args.volgroups.volgroups_len++) ;
  serial = guestfs_int_send (g, GUESTFS_PROC_VG_ACTIVATE,
                             progress_hint, 0,
                             (xdrproc_t) xdr_guestfs_vg_activate_args, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "vg_activate", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs_int_recv (g, "vg_activate", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "vg_activate", "-1");
    return -1;
  }

  if (guestfs_int_check_reply_header (g, &hdr, GUESTFS_PROC_VG_ACTIVATE, serial) == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "vg_activate", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "vg_activate", "-1");
    if (err.errno_string[0] != '\0')
      errnum = guestfs_int_string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "vg_activate", err.error_message);
    else
      guestfs_int_error_errno (g, errnum, "%s: %s", "vg_activate",
                               err.error_message);
    free (err.error_message);
    free (err.errno_string);
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "vg_activate");
    fprintf (trace_buffer.fp, "%d", ret_v);
    guestfs_int_trace_send_line (g, &trace_buffer);
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
  struct trace_buffer trace_buffer;
  struct guestfs_lvm_vg_list *ret_v;
  const uint64_t progress_hint = 0;

  guestfs_int_call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                      "vgs_full", 8);
  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "vgs_full");
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  if (guestfs_int_check_appliance_up (g, "vgs_full") == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "vgs_full", "NULL");
    return NULL;
  }

  serial = guestfs_int_send (g, GUESTFS_PROC_VGS_FULL, progress_hint, 0,
                             NULL, NULL);
  if (serial == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "vgs_full", "NULL");
    return NULL;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs_int_recv (g, "vgs_full", &hdr, &err,
        (xdrproc_t) xdr_guestfs_vgs_full_ret, (char *) &ret);
  if (r == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "vgs_full", "NULL");
    return NULL;
  }

  if (guestfs_int_check_reply_header (g, &hdr, GUESTFS_PROC_VGS_FULL, serial) == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "vgs_full", "NULL");
    return NULL;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "vgs_full", "NULL");
    if (err.errno_string[0] != '\0')
      errnum = guestfs_int_string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "vgs_full", err.error_message);
    else
      guestfs_int_error_errno (g, errnum, "%s: %s", "vgs_full",
                               err.error_message);
    free (err.error_message);
    free (err.errno_string);
    return NULL;
  }

  /* caller will free this */
  ret_v = safe_memdup (g, &ret.volgroups, sizeof (ret.volgroups));
  if (trace_flag) {
    size_t i;

    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "vgs_full");
    fprintf (trace_buffer.fp, "<struct guestfs_lvm_vg_list(%u)", ret_v->len);
    if (ret_v->len > 0)
      fprintf (trace_buffer.fp, " = ");
    for (i = 0; i < ret_v->len; ++i) {
      if (i != 0)
        fprintf (trace_buffer.fp, " ");
      fprintf (trace_buffer.fp, "[%zu]{", i);
      guestfs_int_print_lvm_vg_indent (&ret_v->val[i], trace_buffer.fp, ", ", "");
      fprintf (trace_buffer.fp, "}");
    }
    fprintf (trace_buffer.fp, ">");
    guestfs_int_trace_send_line (g, &trace_buffer);
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
  struct trace_buffer trace_buffer;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs_int_call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                      "vgscan", 6);
  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "vgscan");
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  if (guestfs_int_check_appliance_up (g, "vgscan") == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "vgscan", "-1");
    return -1;
  }

  serial = guestfs_int_send (g, GUESTFS_PROC_VGSCAN, progress_hint, 0,
                             NULL, NULL);
  if (serial == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "vgscan", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs_int_recv (g, "vgscan", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "vgscan", "-1");
    return -1;
  }

  if (guestfs_int_check_reply_header (g, &hdr, GUESTFS_PROC_VGSCAN, serial) == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "vgscan", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "vgscan", "-1");
    if (err.errno_string[0] != '\0')
      errnum = guestfs_int_string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "vgscan", err.error_message);
    else
      guestfs_int_error_errno (g, errnum, "%s: %s", "vgscan",
                               err.error_message);
    free (err.error_message);
    free (err.errno_string);
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "vgscan");
    fprintf (trace_buffer.fp, "%d", ret_v);
    guestfs_int_trace_send_line (g, &trace_buffer);
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
  struct trace_buffer trace_buffer;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs_int_call_callbacks_message (g, GUESTFS_EVENT_ENTER,
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
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "xfs_admin");
    fprintf (trace_buffer.fp, " \"%s\"", device);
    if (optargs->bitmask & GUESTFS_XFS_ADMIN_EXTUNWRITTEN_BITMASK) {
      fprintf (trace_buffer.fp, " \"%s:%s\"", "extunwritten", optargs->extunwritten ? "true" : "false");
    }
    if (optargs->bitmask & GUESTFS_XFS_ADMIN_IMGFILE_BITMASK) {
      fprintf (trace_buffer.fp, " \"%s:%s\"", "imgfile", optargs->imgfile ? "true" : "false");
    }
    if (optargs->bitmask & GUESTFS_XFS_ADMIN_V2LOG_BITMASK) {
      fprintf (trace_buffer.fp, " \"%s:%s\"", "v2log", optargs->v2log ? "true" : "false");
    }
    if (optargs->bitmask & GUESTFS_XFS_ADMIN_PROJID32BIT_BITMASK) {
      fprintf (trace_buffer.fp, " \"%s:%s\"", "projid32bit", optargs->projid32bit ? "true" : "false");
    }
    if (optargs->bitmask & GUESTFS_XFS_ADMIN_LAZYCOUNTER_BITMASK) {
      fprintf (trace_buffer.fp, " \"%s:%s\"", "lazycounter", optargs->lazycounter ? "true" : "false");
    }
    if (optargs->bitmask & GUESTFS_XFS_ADMIN_LABEL_BITMASK) {
      fprintf (trace_buffer.fp, " \"%s:%s\"", "label", optargs->label);
    }
    if (optargs->bitmask & GUESTFS_XFS_ADMIN_UUID_BITMASK) {
      fprintf (trace_buffer.fp, " \"%s:%s\"", "uuid", optargs->uuid);
    }
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  if (guestfs_int_check_appliance_up (g, "xfs_admin") == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
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
  serial = guestfs_int_send (g, GUESTFS_PROC_XFS_ADMIN,
                             progress_hint, optargs->bitmask,
                             (xdrproc_t) xdr_guestfs_xfs_admin_args, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "xfs_admin", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs_int_recv (g, "xfs_admin", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "xfs_admin", "-1");
    return -1;
  }

  if (guestfs_int_check_reply_header (g, &hdr, GUESTFS_PROC_XFS_ADMIN, serial) == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "xfs_admin", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "xfs_admin", "-1");
    if (err.errno_string[0] != '\0')
      errnum = guestfs_int_string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "xfs_admin", err.error_message);
    else
      guestfs_int_error_errno (g, errnum, "%s: %s", "xfs_admin",
                               err.error_message);
    free (err.error_message);
    free (err.errno_string);
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "xfs_admin");
    fprintf (trace_buffer.fp, "%d", ret_v);
    guestfs_int_trace_send_line (g, &trace_buffer);
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
  struct trace_buffer trace_buffer;
  char **ret_v;
  const uint64_t progress_hint = 0;

  guestfs_int_call_callbacks_message (g, GUESTFS_EVENT_ENTER,
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
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "zegrepi");
    fprintf (trace_buffer.fp, " \"%s\"", regex);
    fprintf (trace_buffer.fp, " \"%s\"", path);
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  if (guestfs_int_check_appliance_up (g, "zegrepi") == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "zegrepi", "NULL");
    return NULL;
  }

  args.regex = (char *) regex;
  args.path = (char *) path;
  serial = guestfs_int_send (g, GUESTFS_PROC_ZEGREPI,
                             progress_hint, 0,
                             (xdrproc_t) xdr_guestfs_zegrepi_args, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "zegrepi", "NULL");
    return NULL;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs_int_recv (g, "zegrepi", &hdr, &err,
        (xdrproc_t) xdr_guestfs_zegrepi_ret, (char *) &ret);
  if (r == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "zegrepi", "NULL");
    return NULL;
  }

  if (guestfs_int_check_reply_header (g, &hdr, GUESTFS_PROC_ZEGREPI, serial) == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "zegrepi", "NULL");
    return NULL;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "zegrepi", "NULL");
    if (err.errno_string[0] != '\0')
      errnum = guestfs_int_string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "zegrepi", err.error_message);
    else
      guestfs_int_error_errno (g, errnum, "%s: %s", "zegrepi",
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
    fprintf (trace_buffer.fp, "%s = ", "zegrepi");
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
  struct trace_buffer trace_buffer;
  char **ret_v;
  const uint64_t progress_hint = 0;

  guestfs_int_call_callbacks_message (g, GUESTFS_EVENT_ENTER,
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
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "zfgrep");
    fprintf (trace_buffer.fp, " \"%s\"", pattern);
    fprintf (trace_buffer.fp, " \"%s\"", path);
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  if (guestfs_int_check_appliance_up (g, "zfgrep") == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "zfgrep", "NULL");
    return NULL;
  }

  args.pattern = (char *) pattern;
  args.path = (char *) path;
  serial = guestfs_int_send (g, GUESTFS_PROC_ZFGREP,
                             progress_hint, 0,
                             (xdrproc_t) xdr_guestfs_zfgrep_args, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "zfgrep", "NULL");
    return NULL;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs_int_recv (g, "zfgrep", &hdr, &err,
        (xdrproc_t) xdr_guestfs_zfgrep_ret, (char *) &ret);
  if (r == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "zfgrep", "NULL");
    return NULL;
  }

  if (guestfs_int_check_reply_header (g, &hdr, GUESTFS_PROC_ZFGREP, serial) == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "zfgrep", "NULL");
    return NULL;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "zfgrep", "NULL");
    if (err.errno_string[0] != '\0')
      errnum = guestfs_int_string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "zfgrep", err.error_message);
    else
      guestfs_int_error_errno (g, errnum, "%s: %s", "zfgrep",
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
    fprintf (trace_buffer.fp, "%s = ", "zfgrep");
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
  struct trace_buffer trace_buffer;
  char *ret_v;
  const uint64_t progress_hint = 0;

  guestfs_int_call_callbacks_message (g, GUESTFS_EVENT_ENTER,
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
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s", "zfile");
    fprintf (trace_buffer.fp, " \"%s\"", meth);
    fprintf (trace_buffer.fp, " \"%s\"", path);
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  if (guestfs_int_check_appliance_up (g, "zfile") == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "zfile", "NULL");
    return NULL;
  }

  args.meth = (char *) meth;
  args.path = (char *) path;
  serial = guestfs_int_send (g, GUESTFS_PROC_ZFILE,
                             progress_hint, 0,
                             (xdrproc_t) xdr_guestfs_zfile_args, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "zfile", "NULL");
    return NULL;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs_int_recv (g, "zfile", &hdr, &err,
        (xdrproc_t) xdr_guestfs_zfile_ret, (char *) &ret);
  if (r == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "zfile", "NULL");
    return NULL;
  }

  if (guestfs_int_check_reply_header (g, &hdr, GUESTFS_PROC_ZFILE, serial) == -1) {
    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "zfile", "NULL");
    return NULL;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    int errnum = 0;

    if (trace_flag)
      guestfs_int_trace (g, "%s = %s (error)",
                         "zfile", "NULL");
    if (err.errno_string[0] != '\0')
      errnum = guestfs_int_string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "zfile", err.error_message);
    else
      guestfs_int_error_errno (g, errnum, "%s: %s", "zfile",
                               err.error_message);
    free (err.error_message);
    free (err.errno_string);
    return NULL;
  }

  ret_v = ret.description; /* caller will free */
  if (trace_flag) {
    guestfs_int_trace_open (&trace_buffer);
    fprintf (trace_buffer.fp, "%s = ", "zfile");
    fprintf (trace_buffer.fp, "\"%s\"", ret_v);
    guestfs_int_trace_send_line (g, &trace_buffer);
  }

  return ret_v;
}

