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

GUESTFS_DLL_PUBLIC int
guestfs_internal_test_rboolerr (guestfs_h *g)
{
  int trace_flag = g->trace;
  FILE *trace_fp;
  int r;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "internal_test_rboolerr", 22);
  if (trace_flag) {
    trace_fp = guestfs___trace_open (g);
    fprintf (trace_fp, "%s", "internal_test_rboolerr");
    guestfs___trace_send_line (g);
  }

  r = guestfs__internal_test_rboolerr (g);

  if (r != -1) {
    if (trace_flag) {
      trace_fp = guestfs___trace_open (g);
      fprintf (trace_fp, "%s = ", "internal_test_rboolerr");
      fprintf (trace_fp, "%d", r);
      guestfs___trace_send_line (g);
    }

  } else {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "internal_test_rboolerr", "-1");
  }

  return r;
}

GUESTFS_DLL_PUBLIC char *
guestfs_internal_test_rstring (guestfs_h *g,
                               const char *val)
{
  int trace_flag = g->trace;
  FILE *trace_fp;
  char *r;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "internal_test_rstring", 21);
  if (val == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "internal_test_rstring", "val");
    return NULL;
  }

  if (trace_flag) {
    trace_fp = guestfs___trace_open (g);
    fprintf (trace_fp, "%s", "internal_test_rstring");
    fprintf (trace_fp, " \"%s\"", val);
    guestfs___trace_send_line (g);
  }

  r = guestfs__internal_test_rstring (g, val);

  if (r != NULL) {
    if (trace_flag) {
      trace_fp = guestfs___trace_open (g);
      fprintf (trace_fp, "%s = ", "internal_test_rstring");
      fprintf (trace_fp, "\"%s\"", r);
      guestfs___trace_send_line (g);
    }

  } else {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "internal_test_rstring", "NULL");
  }

  return r;
}

GUESTFS_DLL_PUBLIC struct guestfs_lvm_pv *
guestfs_internal_test_rstructerr (guestfs_h *g)
{
  int trace_flag = g->trace;
  FILE *trace_fp;
  struct guestfs_lvm_pv *r;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "internal_test_rstructerr", 24);
  if (trace_flag) {
    trace_fp = guestfs___trace_open (g);
    fprintf (trace_fp, "%s", "internal_test_rstructerr");
    guestfs___trace_send_line (g);
  }

  r = guestfs__internal_test_rstructerr (g);

  if (r != NULL) {
    if (trace_flag) {
      trace_fp = guestfs___trace_open (g);
      fprintf (trace_fp, "%s = ", "internal_test_rstructerr");
      fprintf (trace_fp, "<struct guestfs_lvm_pv *>");
      guestfs___trace_send_line (g);
    }

  } else {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "internal_test_rstructerr", "NULL");
  }

  return r;
}

GUESTFS_DLL_PUBLIC int
guestfs_add_drive_ro (guestfs_h *g,
                      const char *filename)
{
  int trace_flag = g->trace;
  FILE *trace_fp;
  int r;

  if (g->state != CONFIG) {
    error (g, "%s: this function can only be called in the config state",
              "add_drive_ro");
    return -1;
  }
  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "add_drive_ro", 12);
  if (filename == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "add_drive_ro", "filename");
    return -1;
  }

  if (trace_flag) {
    trace_fp = guestfs___trace_open (g);
    fprintf (trace_fp, "%s", "add_drive_ro");
    fprintf (trace_fp, " \"%s\"", filename);
    guestfs___trace_send_line (g);
  }

  r = guestfs__add_drive_ro (g, filename);

  if (r != -1) {
    if (trace_flag) {
      trace_fp = guestfs___trace_open (g);
      fprintf (trace_fp, "%s = ", "add_drive_ro");
      fprintf (trace_fp, "%d", r);
      guestfs___trace_send_line (g);
    }

  } else {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "add_drive_ro", "-1");
  }

  return r;
}

GUESTFS_DLL_PUBLIC const char *
guestfs_get_path (guestfs_h *g)
{
  int trace_flag = g->trace;
  FILE *trace_fp;
  const char *r;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "get_path", 8);
  if (trace_flag) {
    trace_fp = guestfs___trace_open (g);
    fprintf (trace_fp, "%s", "get_path");
    guestfs___trace_send_line (g);
  }

  r = guestfs__get_path (g);

  if (r != NULL) {
    if (trace_flag) {
      trace_fp = guestfs___trace_open (g);
      fprintf (trace_fp, "%s = ", "get_path");
      fprintf (trace_fp, "\"%s\"", r);
      guestfs___trace_send_line (g);
    }

  } else {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "get_path", "NULL");
  }

  return r;
}

GUESTFS_DLL_PUBLIC int
guestfs_set_append (guestfs_h *g,
                    const char *append)
{
  int trace_flag = g->trace;
  FILE *trace_fp;
  int r;

  if (g->state != CONFIG) {
    error (g, "%s: this function can only be called in the config state",
              "set_append");
    return -1;
  }
  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "set_append", 10);
  if (trace_flag) {
    trace_fp = guestfs___trace_open (g);
    fprintf (trace_fp, "%s", "set_append");
    if (append) fprintf (trace_fp, " \"%s\"", append);
    else fprintf (trace_fp, " null");
    guestfs___trace_send_line (g);
  }

  r = guestfs__set_append (g, append);

  if (r != -1) {
    if (trace_flag) {
      trace_fp = guestfs___trace_open (g);
      fprintf (trace_fp, "%s = ", "set_append");
      fprintf (trace_fp, "%d", r);
      guestfs___trace_send_line (g);
    }

  } else {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "set_append", "-1");
  }

  return r;
}

GUESTFS_DLL_PUBLIC int
guestfs_set_memsize (guestfs_h *g,
                     int memsize)
{
  int trace_flag = g->trace;
  FILE *trace_fp;
  int r;

  if (g->state != CONFIG) {
    error (g, "%s: this function can only be called in the config state",
              "set_memsize");
    return -1;
  }
  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "set_memsize", 11);
  if (trace_flag) {
    trace_fp = guestfs___trace_open (g);
    fprintf (trace_fp, "%s", "set_memsize");
    fprintf (trace_fp, " %d", memsize);
    guestfs___trace_send_line (g);
  }

  r = guestfs__set_memsize (g, memsize);

  if (r != -1) {
    if (trace_flag) {
      trace_fp = guestfs___trace_open (g);
      fprintf (trace_fp, "%s = ", "set_memsize");
      fprintf (trace_fp, "%d", r);
      guestfs___trace_send_line (g);
    }

  } else {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "set_memsize", "-1");
  }

  return r;
}

GUESTFS_DLL_PUBLIC int
guestfs_set_selinux (guestfs_h *g,
                     int selinux)
{
  int trace_flag = g->trace;
  FILE *trace_fp;
  int r;

  if (g->state != CONFIG) {
    error (g, "%s: this function can only be called in the config state",
              "set_selinux");
    return -1;
  }
  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "set_selinux", 11);
  if (trace_flag) {
    trace_fp = guestfs___trace_open (g);
    fprintf (trace_fp, "%s", "set_selinux");
    fputs (selinux ? " true" : " false", trace_fp);
    guestfs___trace_send_line (g);
  }

  r = guestfs__set_selinux (g, selinux);

  if (r != -1) {
    if (trace_flag) {
      trace_fp = guestfs___trace_open (g);
      fprintf (trace_fp, "%s = ", "set_selinux");
      fprintf (trace_fp, "%d", r);
      guestfs___trace_send_line (g);
    }

  } else {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "set_selinux", "-1");
  }

  return r;
}

GUESTFS_DLL_PUBLIC int
guestfs_get_trace (guestfs_h *g)
{
  int trace_flag = g->trace;
  FILE *trace_fp;
  int r;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "get_trace", 9);
  if (trace_flag) {
    trace_fp = guestfs___trace_open (g);
    fprintf (trace_fp, "%s", "get_trace");
    guestfs___trace_send_line (g);
  }

  r = guestfs__get_trace (g);

  if (r != -1) {
    if (trace_flag) {
      trace_fp = guestfs___trace_open (g);
      fprintf (trace_fp, "%s = ", "get_trace");
      fprintf (trace_fp, "%d", r);
      guestfs___trace_send_line (g);
    }

  } else {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "get_trace", "-1");
  }

  return r;
}

GUESTFS_DLL_PUBLIC int
guestfs_set_direct (guestfs_h *g,
                    int direct)
{
  int trace_flag = g->trace;
  FILE *trace_fp;
  int r;

  if (g->state != CONFIG) {
    error (g, "%s: this function can only be called in the config state",
              "set_direct");
    return -1;
  }
  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "set_direct", 10);
  if (trace_flag) {
    trace_fp = guestfs___trace_open (g);
    fprintf (trace_fp, "%s", "set_direct");
    fputs (direct ? " true" : " false", trace_fp);
    guestfs___trace_send_line (g);
  }

  r = guestfs__set_direct (g, direct);

  if (r != -1) {
    if (trace_flag) {
      trace_fp = guestfs___trace_open (g);
      fprintf (trace_fp, "%s = ", "set_direct");
      fprintf (trace_fp, "%d", r);
      guestfs___trace_send_line (g);
    }

  } else {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "set_direct", "-1");
  }

  return r;
}

GUESTFS_DLL_PUBLIC int
guestfs_add_drive_ro_with_if (guestfs_h *g,
                              const char *filename,
                              const char *iface)
{
  int trace_flag = g->trace;
  FILE *trace_fp;
  int r;

  if (g->state != CONFIG) {
    error (g, "%s: this function can only be called in the config state",
              "add_drive_ro_with_if");
    return -1;
  }
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
    trace_fp = guestfs___trace_open (g);
    fprintf (trace_fp, "%s", "add_drive_ro_with_if");
    fprintf (trace_fp, " \"%s\"", filename);
    fprintf (trace_fp, " \"%s\"", iface);
    guestfs___trace_send_line (g);
  }

  r = guestfs__add_drive_ro_with_if (g, filename, iface);

  if (r != -1) {
    if (trace_flag) {
      trace_fp = guestfs___trace_open (g);
      fprintf (trace_fp, "%s = ", "add_drive_ro_with_if");
      fprintf (trace_fp, "%d", r);
      guestfs___trace_send_line (g);
    }

  } else {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "add_drive_ro_with_if", "-1");
  }

  return r;
}

GUESTFS_DLL_PUBLIC char **
guestfs_inspect_os (guestfs_h *g)
{
  int trace_flag = g->trace;
  FILE *trace_fp;
  char **r;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "inspect_os", 10);
  if (trace_flag) {
    trace_fp = guestfs___trace_open (g);
    fprintf (trace_fp, "%s", "inspect_os");
    guestfs___trace_send_line (g);
  }

  r = guestfs__inspect_os (g);

  if (r != NULL) {
    if (trace_flag) {
      size_t i;

      trace_fp = guestfs___trace_open (g);
      fprintf (trace_fp, "%s = ", "inspect_os");
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
                       "inspect_os", "NULL");
  }

  return r;
}

GUESTFS_DLL_PUBLIC char *
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
    trace_fp = guestfs___trace_open (g);
    fprintf (trace_fp, "%s", "inspect_get_distro");
    fprintf (trace_fp, " \"%s\"", root);
    guestfs___trace_send_line (g);
  }

  r = guestfs__inspect_get_distro (g, root);

  if (r != NULL) {
    if (trace_flag) {
      trace_fp = guestfs___trace_open (g);
      fprintf (trace_fp, "%s = ", "inspect_get_distro");
      fprintf (trace_fp, "\"%s\"", r);
      guestfs___trace_send_line (g);
    }

  } else {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "inspect_get_distro", "NULL");
  }

  return r;
}

GUESTFS_DLL_PUBLIC int
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
    trace_fp = guestfs___trace_open (g);
    fprintf (trace_fp, "%s", "inspect_get_minor_version");
    fprintf (trace_fp, " \"%s\"", root);
    guestfs___trace_send_line (g);
  }

  r = guestfs__inspect_get_minor_version (g, root);

  if (r != -1) {
    if (trace_flag) {
      trace_fp = guestfs___trace_open (g);
      fprintf (trace_fp, "%s = ", "inspect_get_minor_version");
      fprintf (trace_fp, "%d", r);
      guestfs___trace_send_line (g);
    }

  } else {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "inspect_get_minor_version", "-1");
  }

  return r;
}

GUESTFS_DLL_PUBLIC char **
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
    trace_fp = guestfs___trace_open (g);
    fprintf (trace_fp, "%s", "inspect_get_filesystems");
    fprintf (trace_fp, " \"%s\"", root);
    guestfs___trace_send_line (g);
  }

  r = guestfs__inspect_get_filesystems (g, root);

  if (r != NULL) {
    if (trace_flag) {
      size_t i;

      trace_fp = guestfs___trace_open (g);
      fprintf (trace_fp, "%s = ", "inspect_get_filesystems");
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
                       "inspect_get_filesystems", "NULL");
  }

  return r;
}

GUESTFS_DLL_PUBLIC int
guestfs_add_domain_argv (guestfs_h *g,
                         const char *dom,
                         const struct guestfs_add_domain_argv *optargs)
{
  struct guestfs_add_domain_argv optargs_null;
  if (!optargs) {
    optargs_null.bitmask = 0;
    optargs = &optargs_null;
  }

  int trace_flag = g->trace;
  FILE *trace_fp;
  int r;

  if (g->state != CONFIG) {
    error (g, "%s: this function can only be called in the config state",
              "add_domain");
    return -1;
  }
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
    trace_fp = guestfs___trace_open (g);
    fprintf (trace_fp, "%s", "add_domain");
    fprintf (trace_fp, " \"%s\"", dom);
    if (optargs->bitmask & GUESTFS_ADD_DOMAIN_LIBVIRTURI_BITMASK) {
      fprintf (trace_fp, " \"%s:%s\"", "libvirturi", optargs->libvirturi);
    }
    if (optargs->bitmask & GUESTFS_ADD_DOMAIN_READONLY_BITMASK) {
      fprintf (trace_fp, " \"%s:%s\"", "readonly", optargs->readonly ? "true" : "false");
    }
    if (optargs->bitmask & GUESTFS_ADD_DOMAIN_IFACE_BITMASK) {
      fprintf (trace_fp, " \"%s:%s\"", "iface", optargs->iface);
    }
    if (optargs->bitmask & GUESTFS_ADD_DOMAIN_LIVE_BITMASK) {
      fprintf (trace_fp, " \"%s:%s\"", "live", optargs->live ? "true" : "false");
    }
    if (optargs->bitmask & GUESTFS_ADD_DOMAIN_ALLOWUUID_BITMASK) {
      fprintf (trace_fp, " \"%s:%s\"", "allowuuid", optargs->allowuuid ? "true" : "false");
    }
    if (optargs->bitmask & GUESTFS_ADD_DOMAIN_READONLYDISK_BITMASK) {
      fprintf (trace_fp, " \"%s:%s\"", "readonlydisk", optargs->readonlydisk);
    }
    guestfs___trace_send_line (g);
  }

  r = guestfs__add_domain (g, dom, optargs);

  if (r != -1) {
    if (trace_flag) {
      trace_fp = guestfs___trace_open (g);
      fprintf (trace_fp, "%s = ", "add_domain");
      fprintf (trace_fp, "%d", r);
      guestfs___trace_send_line (g);
    }

  } else {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "add_domain", "-1");
  }

  return r;
}

GUESTFS_DLL_PUBLIC char *
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
    trace_fp = guestfs___trace_open (g);
    fprintf (trace_fp, "%s", "inspect_get_package_format");
    fprintf (trace_fp, " \"%s\"", root);
    guestfs___trace_send_line (g);
  }

  r = guestfs__inspect_get_package_format (g, root);

  if (r != NULL) {
    if (trace_flag) {
      trace_fp = guestfs___trace_open (g);
      fprintf (trace_fp, "%s = ", "inspect_get_package_format");
      fprintf (trace_fp, "\"%s\"", r);
      guestfs___trace_send_line (g);
    }

  } else {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "inspect_get_package_format", "NULL");
  }

  return r;
}

GUESTFS_DLL_PUBLIC struct guestfs_application_list *
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
    trace_fp = guestfs___trace_open (g);
    fprintf (trace_fp, "%s", "inspect_list_applications");
    fprintf (trace_fp, " \"%s\"", root);
    guestfs___trace_send_line (g);
  }

  r = guestfs__inspect_list_applications (g, root);

  if (r != NULL) {
    if (trace_flag) {
      trace_fp = guestfs___trace_open (g);
      fprintf (trace_fp, "%s = ", "inspect_list_applications");
      fprintf (trace_fp, "<struct guestfs_application_list *>");
      guestfs___trace_send_line (g);
    }

  } else {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "inspect_list_applications", "NULL");
  }

  return r;
}

GUESTFS_DLL_PUBLIC char *
guestfs_get_attach_method (guestfs_h *g)
{
  int trace_flag = g->trace;
  FILE *trace_fp;
  char *r;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "get_attach_method", 17);
  if (trace_flag) {
    trace_fp = guestfs___trace_open (g);
    fprintf (trace_fp, "%s", "get_attach_method");
    guestfs___trace_send_line (g);
  }

  r = guestfs__get_attach_method (g);

  if (r != NULL) {
    if (trace_flag) {
      trace_fp = guestfs___trace_open (g);
      fprintf (trace_fp, "%s = ", "get_attach_method");
      fprintf (trace_fp, "\"%s\"", r);
      guestfs___trace_send_line (g);
    }

  } else {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "get_attach_method", "NULL");
  }

  return r;
}

GUESTFS_DLL_PUBLIC char *
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
    trace_fp = guestfs___trace_open (g);
    fprintf (trace_fp, "%s", "inspect_get_product_variant");
    fprintf (trace_fp, " \"%s\"", root);
    guestfs___trace_send_line (g);
  }

  r = guestfs__inspect_get_product_variant (g, root);

  if (r != NULL) {
    if (trace_flag) {
      trace_fp = guestfs___trace_open (g);
      fprintf (trace_fp, "%s = ", "inspect_get_product_variant");
      fprintf (trace_fp, "\"%s\"", r);
      guestfs___trace_send_line (g);
    }

  } else {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "inspect_get_product_variant", "NULL");
  }

  return r;
}

GUESTFS_DLL_PUBLIC int
guestfs_get_pgroup (guestfs_h *g)
{
  int trace_flag = g->trace;
  FILE *trace_fp;
  int r;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "get_pgroup", 10);
  if (trace_flag) {
    trace_fp = guestfs___trace_open (g);
    fprintf (trace_fp, "%s", "get_pgroup");
    guestfs___trace_send_line (g);
  }

  r = guestfs__get_pgroup (g);

  if (r != -1) {
    if (trace_flag) {
      trace_fp = guestfs___trace_open (g);
      fprintf (trace_fp, "%s = ", "get_pgroup");
      fprintf (trace_fp, "%d", r);
      guestfs___trace_send_line (g);
    }

  } else {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "get_pgroup", "-1");
  }

  return r;
}

GUESTFS_DLL_PUBLIC int
guestfs_get_smp (guestfs_h *g)
{
  int trace_flag = g->trace;
  FILE *trace_fp;
  int r;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "get_smp", 7);
  if (trace_flag) {
    trace_fp = guestfs___trace_open (g);
    fprintf (trace_fp, "%s", "get_smp");
    guestfs___trace_send_line (g);
  }

  r = guestfs__get_smp (g);

  if (r != -1) {
    if (trace_flag) {
      trace_fp = guestfs___trace_open (g);
      fprintf (trace_fp, "%s = ", "get_smp");
      fprintf (trace_fp, "%d", r);
      guestfs___trace_send_line (g);
    }

  } else {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "get_smp", "-1");
  }

  return r;
}

GUESTFS_DLL_PUBLIC int
guestfs_umount_local_argv (guestfs_h *g,
                           const struct guestfs_umount_local_argv *optargs)
{
  struct guestfs_umount_local_argv optargs_null;
  if (!optargs) {
    optargs_null.bitmask = 0;
    optargs = &optargs_null;
  }

  int trace_flag = g->trace;
  FILE *trace_fp;
  int r;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "umount_local", 12);
  if (optargs->bitmask & UINT64_C(0xfffffffffffffffe)) {
    error (g, "%s: unknown option in guestfs_%s_argv->bitmask (this can happen if a program is compiled against a newer version of libguestfs, then dynamically linked to an older version)",
           "umount_local", "umount_local");
    return -1;
  }

  if (trace_flag) {
    trace_fp = guestfs___trace_open (g);
    fprintf (trace_fp, "%s", "umount_local");
    if (optargs->bitmask & GUESTFS_UMOUNT_LOCAL_RETRY_BITMASK) {
      fprintf (trace_fp, " \"%s:%s\"", "retry", optargs->retry ? "true" : "false");
    }
    guestfs___trace_send_line (g);
  }

  r = guestfs__umount_local (g, optargs);

  if (r != -1) {
    if (trace_flag) {
      trace_fp = guestfs___trace_open (g);
      fprintf (trace_fp, "%s = ", "umount_local");
      fprintf (trace_fp, "%d", r);
      guestfs___trace_send_line (g);
    }

  } else {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "umount_local", "-1");
  }

  return r;
}

GUESTFS_DLL_PUBLIC char *
guestfs_read_file (guestfs_h *g,
                   const char *path,
                   size_t *size_r)
{
  int trace_flag = g->trace;
  FILE *trace_fp;
  char *r;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "read_file", 9);
  if (path == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "read_file", "path");
    return NULL;
  }

  if (trace_flag) {
    trace_fp = guestfs___trace_open (g);
    fprintf (trace_fp, "%s", "read_file");
    fprintf (trace_fp, " \"%s\"", path);
    guestfs___trace_send_line (g);
  }

  r = guestfs__read_file (g, path, size_r);

  if (r != NULL) {
    if (trace_flag) {
      trace_fp = guestfs___trace_open (g);
      fprintf (trace_fp, "%s = ", "read_file");
      guestfs___print_BufferOut (trace_fp, r, *size_r);
      guestfs___trace_send_line (g);
    }

  } else {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "read_file", "NULL");
  }

  return r;
}

GUESTFS_DLL_PUBLIC int
guestfs_write (guestfs_h *g,
               const char *path,
               const char *content,
               size_t content_size)
{
  int trace_flag = g->trace;
  FILE *trace_fp;
  int r;

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
    trace_fp = guestfs___trace_open (g);
    fprintf (trace_fp, "%s", "write");
    fprintf (trace_fp, " \"%s\"", path);
    fputc (' ', trace_fp);
    guestfs___print_BufferIn (trace_fp, content, content_size);
    guestfs___trace_send_line (g);
  }

  r = guestfs__write (g, path, content, content_size);

  if (r != -1) {
    if (trace_flag) {
      trace_fp = guestfs___trace_open (g);
      fprintf (trace_fp, "%s = ", "write");
      fprintf (trace_fp, "%d", r);
      guestfs___trace_send_line (g);
    }

  } else {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "write", "-1");
  }

  return r;
}

GUESTFS_DLL_PUBLIC int
guestfs_disk_has_backing_file (guestfs_h *g,
                               const char *filename)
{
  int trace_flag = g->trace;
  FILE *trace_fp;
  int r;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "disk_has_backing_file", 21);
  if (filename == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "disk_has_backing_file", "filename");
    return -1;
  }

  if (trace_flag) {
    trace_fp = guestfs___trace_open (g);
    fprintf (trace_fp, "%s", "disk_has_backing_file");
    fprintf (trace_fp, " \"%s\"", filename);
    guestfs___trace_send_line (g);
  }

  r = guestfs__disk_has_backing_file (g, filename);

  if (r != -1) {
    if (trace_flag) {
      trace_fp = guestfs___trace_open (g);
      fprintf (trace_fp, "%s = ", "disk_has_backing_file");
      fprintf (trace_fp, "%d", r);
      guestfs___trace_send_line (g);
    }

  } else {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "disk_has_backing_file", "-1");
  }

  return r;
}

GUESTFS_DLL_PUBLIC char *
guestfs_get_libvirt_requested_credential_defresult (guestfs_h *g,
                                                    int index)
{
  int trace_flag = g->trace;
  FILE *trace_fp;
  char *r;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "get_libvirt_requested_credential_defresult", 42);
  if (trace_flag) {
    trace_fp = guestfs___trace_open (g);
    fprintf (trace_fp, "%s", "get_libvirt_requested_credential_defresult");
    fprintf (trace_fp, " %d", index);
    guestfs___trace_send_line (g);
  }

  r = guestfs__get_libvirt_requested_credential_defresult (g, index);

  if (r != NULL) {
    if (trace_flag) {
      trace_fp = guestfs___trace_open (g);
      fprintf (trace_fp, "%s = ", "get_libvirt_requested_credential_defresult");
      fprintf (trace_fp, "\"%s\"", r);
      guestfs___trace_send_line (g);
    }

  } else {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "get_libvirt_requested_credential_defresult", "NULL");
  }

  return r;
}

GUESTFS_DLL_PUBLIC char *
guestfs_get_cachedir (guestfs_h *g)
{
  int trace_flag = g->trace;
  FILE *trace_fp;
  char *r;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "get_cachedir", 12);
  if (trace_flag) {
    trace_fp = guestfs___trace_open (g);
    fprintf (trace_fp, "%s", "get_cachedir");
    guestfs___trace_send_line (g);
  }

  r = guestfs__get_cachedir (g);

  if (r != NULL) {
    if (trace_flag) {
      trace_fp = guestfs___trace_open (g);
      fprintf (trace_fp, "%s = ", "get_cachedir");
      fprintf (trace_fp, "\"%s\"", r);
      guestfs___trace_send_line (g);
    }

  } else {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "get_cachedir", "NULL");
  }

  return r;
}

GUESTFS_DLL_PUBLIC char *
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
    trace_fp = guestfs___trace_open (g);
    fprintf (trace_fp, "%s", "ll");
    fprintf (trace_fp, " \"%s\"", directory);
    guestfs___trace_send_line (g);
  }

  if (guestfs___check_appliance_up (g, "ll") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "ll", "NULL");
    return NULL;
  }

  args.directory = (char *) directory;
  serial = guestfs___send (g, GUESTFS_PROC_LL,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_ll_args, (char *) &args);
  if (serial == -1) {
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
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "ll", "NULL");
    return NULL;
  }

  if (guestfs___check_reply_header (g, &hdr, GUESTFS_PROC_LL, serial) == -1) {
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
    return NULL;
  }

  ret_v = ret.listing; /* caller will free */
  if (trace_flag) {
    trace_fp = guestfs___trace_open (g);
    fprintf (trace_fp, "%s = ", "ll");
    fprintf (trace_fp, "\"%s\"", ret_v);
    guestfs___trace_send_line (g);
  }

  return ret_v;
}

GUESTFS_DLL_PUBLIC char **
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
    trace_fp = guestfs___trace_open (g);
    fprintf (trace_fp, "%s", "pvs");
    guestfs___trace_send_line (g);
  }

  if (guestfs___check_appliance_up (g, "pvs") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "pvs", "NULL");
    return NULL;
  }

  serial = guestfs___send (g, GUESTFS_PROC_PVS, progress_hint, 0,
                           NULL, NULL);
  if (serial == -1) {
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
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "pvs", "NULL");
    return NULL;
  }

  if (guestfs___check_reply_header (g, &hdr, GUESTFS_PROC_PVS, serial) == -1) {
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
    return NULL;
  }

  /* caller will free this, but we need to add a NULL entry */
  ret.physvols.physvols_val =
    safe_realloc (g, ret.physvols.physvols_val,
                  sizeof (char *) * (ret.physvols.physvols_len + 1));
  ret.physvols.physvols_val[ret.physvols.physvols_len] = NULL;
  ret_v = ret.physvols.physvols_val;
  if (trace_flag) {
    size_t i;

    trace_fp = guestfs___trace_open (g);
    fprintf (trace_fp, "%s = ", "pvs");
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
    trace_fp = guestfs___trace_open (g);
    fprintf (trace_fp, "%s", "aug_match");
    fprintf (trace_fp, " \"%s\"", augpath);
    guestfs___trace_send_line (g);
  }

  if (guestfs___check_appliance_up (g, "aug_match") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "aug_match", "NULL");
    return NULL;
  }

  args.augpath = (char *) augpath;
  serial = guestfs___send (g, GUESTFS_PROC_AUG_MATCH,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_aug_match_args, (char *) &args);
  if (serial == -1) {
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
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "aug_match", "NULL");
    return NULL;
  }

  if (guestfs___check_reply_header (g, &hdr, GUESTFS_PROC_AUG_MATCH, serial) == -1) {
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
    return NULL;
  }

  /* caller will free this, but we need to add a NULL entry */
  ret.matches.matches_val =
    safe_realloc (g, ret.matches.matches_val,
                  sizeof (char *) * (ret.matches.matches_len + 1));
  ret.matches.matches_val[ret.matches.matches_len] = NULL;
  ret_v = ret.matches.matches_val;
  if (trace_flag) {
    size_t i;

    trace_fp = guestfs___trace_open (g);
    fprintf (trace_fp, "%s = ", "aug_match");
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
    trace_fp = guestfs___trace_open (g);
    fprintf (trace_fp, "%s", "aug_ls");
    fprintf (trace_fp, " \"%s\"", augpath);
    guestfs___trace_send_line (g);
  }

  if (guestfs___check_appliance_up (g, "aug_ls") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "aug_ls", "NULL");
    return NULL;
  }

  args.augpath = (char *) augpath;
  serial = guestfs___send (g, GUESTFS_PROC_AUG_LS,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_aug_ls_args, (char *) &args);
  if (serial == -1) {
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
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "aug_ls", "NULL");
    return NULL;
  }

  if (guestfs___check_reply_header (g, &hdr, GUESTFS_PROC_AUG_LS, serial) == -1) {
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
    return NULL;
  }

  /* caller will free this, but we need to add a NULL entry */
  ret.matches.matches_val =
    safe_realloc (g, ret.matches.matches_val,
                  sizeof (char *) * (ret.matches.matches_len + 1));
  ret.matches.matches_val[ret.matches.matches_len] = NULL;
  ret_v = ret.matches.matches_val;
  if (trace_flag) {
    size_t i;

    trace_fp = guestfs___trace_open (g);
    fprintf (trace_fp, "%s = ", "aug_ls");
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
    trace_fp = guestfs___trace_open (g);
    fprintf (trace_fp, "%s", "rm_rf");
    fprintf (trace_fp, " \"%s\"", path);
    guestfs___trace_send_line (g);
  }

  if (guestfs___check_appliance_up (g, "rm_rf") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "rm_rf", "-1");
    return -1;
  }

  args.path = (char *) path;
  serial = guestfs___send (g, GUESTFS_PROC_RM_RF,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_rm_rf_args, (char *) &args);
  if (serial == -1) {
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
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "rm_rf", "-1");
    return -1;
  }

  if (guestfs___check_reply_header (g, &hdr, GUESTFS_PROC_RM_RF, serial) == -1) {
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
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    trace_fp = guestfs___trace_open (g);
    fprintf (trace_fp, "%s = ", "rm_rf");
    fprintf (trace_fp, "%d", ret_v);
    guestfs___trace_send_line (g);
  }

  return ret_v;
}

GUESTFS_DLL_PUBLIC int
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
    trace_fp = guestfs___trace_open (g);
    fprintf (trace_fp, "%s", "pvcreate");
    fprintf (trace_fp, " \"%s\"", device);
    guestfs___trace_send_line (g);
  }

  if (guestfs___check_appliance_up (g, "pvcreate") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "pvcreate", "-1");
    return -1;
  }

  args.device = (char *) device;
  serial = guestfs___send (g, GUESTFS_PROC_PVCREATE,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_pvcreate_args, (char *) &args);
  if (serial == -1) {
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
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "pvcreate", "-1");
    return -1;
  }

  if (guestfs___check_reply_header (g, &hdr, GUESTFS_PROC_PVCREATE, serial) == -1) {
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
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    trace_fp = guestfs___trace_open (g);
    fprintf (trace_fp, "%s = ", "pvcreate");
    fprintf (trace_fp, "%d", ret_v);
    guestfs___trace_send_line (g);
  }

  return ret_v;
}

GUESTFS_DLL_PUBLIC char **
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

    trace_fp = guestfs___trace_open (g);
    fprintf (trace_fp, "%s", "command_lines");
    fputc (' ', trace_fp);
    fputc ('"', trace_fp);
    for (i = 0; arguments[i]; ++i) {
      if (i > 0) fputc (' ', trace_fp);
      fputs (arguments[i], trace_fp);
    }
    fputc ('"', trace_fp);
    guestfs___trace_send_line (g);
  }

  if (guestfs___check_appliance_up (g, "command_lines") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "command_lines", "NULL");
    return NULL;
  }

  args.arguments.arguments_val = (char **) arguments;
  for (args.arguments.arguments_len = 0; arguments[args.arguments.arguments_len]; args.arguments.arguments_len++) ;
  serial = guestfs___send (g, GUESTFS_PROC_COMMAND_LINES,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_command_lines_args, (char *) &args);
  if (serial == -1) {
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
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "command_lines", "NULL");
    return NULL;
  }

  if (guestfs___check_reply_header (g, &hdr, GUESTFS_PROC_COMMAND_LINES, serial) == -1) {
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
    fprintf (trace_fp, "%s = ", "command_lines");
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
    trace_fp = guestfs___trace_open (g);
    fprintf (trace_fp, "%s", "lvremove");
    fprintf (trace_fp, " \"%s\"", device);
    guestfs___trace_send_line (g);
  }

  if (guestfs___check_appliance_up (g, "lvremove") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "lvremove", "-1");
    return -1;
  }

  args.device = (char *) device;
  serial = guestfs___send (g, GUESTFS_PROC_LVREMOVE,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_lvremove_args, (char *) &args);
  if (serial == -1) {
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
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "lvremove", "-1");
    return -1;
  }

  if (guestfs___check_reply_header (g, &hdr, GUESTFS_PROC_LVREMOVE, serial) == -1) {
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
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    trace_fp = guestfs___trace_open (g);
    fprintf (trace_fp, "%s = ", "lvremove");
    fprintf (trace_fp, "%d", ret_v);
    guestfs___trace_send_line (g);
  }

  return ret_v;
}

GUESTFS_DLL_PUBLIC int
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
    trace_fp = guestfs___trace_open (g);
    fprintf (trace_fp, "%s", "fsck");
    fprintf (trace_fp, " \"%s\"", fstype);
    fprintf (trace_fp, " \"%s\"", device);
    guestfs___trace_send_line (g);
  }

  if (guestfs___check_appliance_up (g, "fsck") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "fsck", "-1");
    return -1;
  }

  args.fstype = (char *) fstype;
  args.device = (char *) device;
  serial = guestfs___send (g, GUESTFS_PROC_FSCK,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_fsck_args, (char *) &args);
  if (serial == -1) {
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
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "fsck", "-1");
    return -1;
  }

  if (guestfs___check_reply_header (g, &hdr, GUESTFS_PROC_FSCK, serial) == -1) {
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
    return -1;
  }

  ret_v = ret.status;
  if (trace_flag) {
    trace_fp = guestfs___trace_open (g);
    fprintf (trace_fp, "%s = ", "fsck");
    fprintf (trace_fp, "%d", ret_v);
    guestfs___trace_send_line (g);
  }

  return ret_v;
}

GUESTFS_DLL_PUBLIC int
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
    trace_fp = guestfs___trace_open (g);
    fprintf (trace_fp, "%s", "cp");
    fprintf (trace_fp, " \"%s\"", src);
    fprintf (trace_fp, " \"%s\"", dest);
    guestfs___trace_send_line (g);
  }

  if (guestfs___check_appliance_up (g, "cp") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "cp", "-1");
    return -1;
  }

  args.src = (char *) src;
  args.dest = (char *) dest;
  serial = guestfs___send (g, GUESTFS_PROC_CP,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_cp_args, (char *) &args);
  if (serial == -1) {
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
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "cp", "-1");
    return -1;
  }

  if (guestfs___check_reply_header (g, &hdr, GUESTFS_PROC_CP, serial) == -1) {
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
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    trace_fp = guestfs___trace_open (g);
    fprintf (trace_fp, "%s = ", "cp");
    fprintf (trace_fp, "%d", ret_v);
    guestfs___trace_send_line (g);
  }

  return ret_v;
}

GUESTFS_DLL_PUBLIC int
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
    trace_fp = guestfs___trace_open (g);
    fprintf (trace_fp, "%s", "mv");
    fprintf (trace_fp, " \"%s\"", src);
    fprintf (trace_fp, " \"%s\"", dest);
    guestfs___trace_send_line (g);
  }

  if (guestfs___check_appliance_up (g, "mv") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mv", "-1");
    return -1;
  }

  args.src = (char *) src;
  args.dest = (char *) dest;
  serial = guestfs___send (g, GUESTFS_PROC_MV,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_mv_args, (char *) &args);
  if (serial == -1) {
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
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mv", "-1");
    return -1;
  }

  if (guestfs___check_reply_header (g, &hdr, GUESTFS_PROC_MV, serial) == -1) {
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
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    trace_fp = guestfs___trace_open (g);
    fprintf (trace_fp, "%s = ", "mv");
    fprintf (trace_fp, "%d", ret_v);
    guestfs___trace_send_line (g);
  }

  return ret_v;
}

GUESTFS_DLL_PUBLIC char *
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
    trace_fp = guestfs___trace_open (g);
    fprintf (trace_fp, "%s", "sfdisk_l");
    fprintf (trace_fp, " \"%s\"", device);
    guestfs___trace_send_line (g);
  }

  if (guestfs___check_appliance_up (g, "sfdisk_l") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "sfdisk_l", "NULL");
    return NULL;
  }

  args.device = (char *) device;
  serial = guestfs___send (g, GUESTFS_PROC_SFDISK_L,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_sfdisk_l_args, (char *) &args);
  if (serial == -1) {
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
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "sfdisk_l", "NULL");
    return NULL;
  }

  if (guestfs___check_reply_header (g, &hdr, GUESTFS_PROC_SFDISK_L, serial) == -1) {
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
    return NULL;
  }

  ret_v = ret.partitions; /* caller will free */
  if (trace_flag) {
    trace_fp = guestfs___trace_open (g);
    fprintf (trace_fp, "%s = ", "sfdisk_l");
    fprintf (trace_fp, "\"%s\"", ret_v);
    guestfs___trace_send_line (g);
  }

  return ret_v;
}

GUESTFS_DLL_PUBLIC int
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
    trace_fp = guestfs___trace_open (g);
    fprintf (trace_fp, "%s", "vg_activate_all");
    fputs (activate ? " true" : " false", trace_fp);
    guestfs___trace_send_line (g);
  }

  if (guestfs___check_appliance_up (g, "vg_activate_all") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "vg_activate_all", "-1");
    return -1;
  }

  args.activate = activate;
  serial = guestfs___send (g, GUESTFS_PROC_VG_ACTIVATE_ALL,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_vg_activate_all_args, (char *) &args);
  if (serial == -1) {
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
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "vg_activate_all", "-1");
    return -1;
  }

  if (guestfs___check_reply_header (g, &hdr, GUESTFS_PROC_VG_ACTIVATE_ALL, serial) == -1) {
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
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    trace_fp = guestfs___trace_open (g);
    fprintf (trace_fp, "%s = ", "vg_activate_all");
    fprintf (trace_fp, "%d", ret_v);
    guestfs___trace_send_line (g);
  }

  return ret_v;
}

GUESTFS_DLL_PUBLIC int
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
    trace_fp = guestfs___trace_open (g);
    fprintf (trace_fp, "%s", "scrub_file");
    fprintf (trace_fp, " \"%s\"", file);
    guestfs___trace_send_line (g);
  }

  if (guestfs___check_appliance_up (g, "scrub_file") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "scrub_file", "-1");
    return -1;
  }

  args.file = (char *) file;
  serial = guestfs___send (g, GUESTFS_PROC_SCRUB_FILE,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_scrub_file_args, (char *) &args);
  if (serial == -1) {
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
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "scrub_file", "-1");
    return -1;
  }

  if (guestfs___check_reply_header (g, &hdr, GUESTFS_PROC_SCRUB_FILE, serial) == -1) {
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
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    trace_fp = guestfs___trace_open (g);
    fprintf (trace_fp, "%s = ", "scrub_file");
    fprintf (trace_fp, "%d", ret_v);
    guestfs___trace_send_line (g);
  }

  return ret_v;
}

GUESTFS_DLL_PUBLIC int
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
    trace_fp = guestfs___trace_open (g);
    fprintf (trace_fp, "%s", "wc_w");
    fprintf (trace_fp, " \"%s\"", path);
    guestfs___trace_send_line (g);
  }

  if (guestfs___check_appliance_up (g, "wc_w") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "wc_w", "-1");
    return -1;
  }

  args.path = (char *) path;
  serial = guestfs___send (g, GUESTFS_PROC_WC_W,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_wc_w_args, (char *) &args);
  if (serial == -1) {
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
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "wc_w", "-1");
    return -1;
  }

  if (guestfs___check_reply_header (g, &hdr, GUESTFS_PROC_WC_W, serial) == -1) {
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
    return -1;
  }

  ret_v = ret.words;
  if (trace_flag) {
    trace_fp = guestfs___trace_open (g);
    fprintf (trace_fp, "%s = ", "wc_w");
    fprintf (trace_fp, "%d", ret_v);
    guestfs___trace_send_line (g);
  }

  return ret_v;
}

GUESTFS_DLL_PUBLIC char *
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
    trace_fp = guestfs___trace_open (g);
    fprintf (trace_fp, "%s", "df_h");
    guestfs___trace_send_line (g);
  }

  if (guestfs___check_appliance_up (g, "df_h") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "df_h", "NULL");
    return NULL;
  }

  serial = guestfs___send (g, GUESTFS_PROC_DF_H, progress_hint, 0,
                           NULL, NULL);
  if (serial == -1) {
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
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "df_h", "NULL");
    return NULL;
  }

  if (guestfs___check_reply_header (g, &hdr, GUESTFS_PROC_DF_H, serial) == -1) {
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
    return NULL;
  }

  ret_v = ret.output; /* caller will free */
  if (trace_flag) {
    trace_fp = guestfs___trace_open (g);
    fprintf (trace_fp, "%s = ", "df_h");
    fprintf (trace_fp, "\"%s\"", ret_v);
    guestfs___trace_send_line (g);
  }

  return ret_v;
}

GUESTFS_DLL_PUBLIC int
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
    trace_fp = guestfs___trace_open (g);
    fprintf (trace_fp, "%s", "setxattr");
    fprintf (trace_fp, " \"%s\"", xattr);
    fprintf (trace_fp, " \"%s\"", val);
    fprintf (trace_fp, " %d", vallen);
    fprintf (trace_fp, " \"%s\"", path);
    guestfs___trace_send_line (g);
  }

  if (guestfs___check_appliance_up (g, "setxattr") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "setxattr", "-1");
    return -1;
  }

  args.xattr = (char *) xattr;
  args.val = (char *) val;
  args.vallen = vallen;
  args.path = (char *) path;
  serial = guestfs___send (g, GUESTFS_PROC_SETXATTR,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_setxattr_args, (char *) &args);
  if (serial == -1) {
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
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "setxattr", "-1");
    return -1;
  }

  if (guestfs___check_reply_header (g, &hdr, GUESTFS_PROC_SETXATTR, serial) == -1) {
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
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    trace_fp = guestfs___trace_open (g);
    fprintf (trace_fp, "%s = ", "setxattr");
    fprintf (trace_fp, "%d", ret_v);
    guestfs___trace_send_line (g);
  }

  return ret_v;
}

GUESTFS_DLL_PUBLIC int
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
    trace_fp = guestfs___trace_open (g);
    fprintf (trace_fp, "%s", "lremovexattr");
    fprintf (trace_fp, " \"%s\"", xattr);
    fprintf (trace_fp, " \"%s\"", path);
    guestfs___trace_send_line (g);
  }

  if (guestfs___check_appliance_up (g, "lremovexattr") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "lremovexattr", "-1");
    return -1;
  }

  args.xattr = (char *) xattr;
  args.path = (char *) path;
  serial = guestfs___send (g, GUESTFS_PROC_LREMOVEXATTR,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_lremovexattr_args, (char *) &args);
  if (serial == -1) {
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
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "lremovexattr", "-1");
    return -1;
  }

  if (guestfs___check_reply_header (g, &hdr, GUESTFS_PROC_LREMOVEXATTR, serial) == -1) {
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
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    trace_fp = guestfs___trace_open (g);
    fprintf (trace_fp, "%s = ", "lremovexattr");
    fprintf (trace_fp, "%d", ret_v);
    guestfs___trace_send_line (g);
  }

  return ret_v;
}

GUESTFS_DLL_PUBLIC int
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
    trace_fp = guestfs___trace_open (g);
    fprintf (trace_fp, "%s", "mkmountpoint");
    fprintf (trace_fp, " \"%s\"", exemptpath);
    guestfs___trace_send_line (g);
  }

  if (guestfs___check_appliance_up (g, "mkmountpoint") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mkmountpoint", "-1");
    return -1;
  }

  args.exemptpath = (char *) exemptpath;
  serial = guestfs___send (g, GUESTFS_PROC_MKMOUNTPOINT,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_mkmountpoint_args, (char *) &args);
  if (serial == -1) {
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
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mkmountpoint", "-1");
    return -1;
  }

  if (guestfs___check_reply_header (g, &hdr, GUESTFS_PROC_MKMOUNTPOINT, serial) == -1) {
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
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    trace_fp = guestfs___trace_open (g);
    fprintf (trace_fp, "%s = ", "mkmountpoint");
    fprintf (trace_fp, "%d", ret_v);
    guestfs___trace_send_line (g);
  }

  return ret_v;
}

GUESTFS_DLL_PUBLIC char **
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
    trace_fp = guestfs___trace_open (g);
    fprintf (trace_fp, "%s", "zfgrepi");
    fprintf (trace_fp, " \"%s\"", pattern);
    fprintf (trace_fp, " \"%s\"", path);
    guestfs___trace_send_line (g);
  }

  if (guestfs___check_appliance_up (g, "zfgrepi") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "zfgrepi", "NULL");
    return NULL;
  }

  args.pattern = (char *) pattern;
  args.path = (char *) path;
  serial = guestfs___send (g, GUESTFS_PROC_ZFGREPI,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_zfgrepi_args, (char *) &args);
  if (serial == -1) {
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
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "zfgrepi", "NULL");
    return NULL;
  }

  if (guestfs___check_reply_header (g, &hdr, GUESTFS_PROC_ZFGREPI, serial) == -1) {
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
    fprintf (trace_fp, "%s = ", "zfgrepi");
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
    trace_fp = guestfs___trace_open (g);
    fprintf (trace_fp, "%s", "ln_f");
    fprintf (trace_fp, " \"%s\"", target);
    fprintf (trace_fp, " \"%s\"", linkname);
    guestfs___trace_send_line (g);
  }

  if (guestfs___check_appliance_up (g, "ln_f") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "ln_f", "-1");
    return -1;
  }

  args.target = (char *) target;
  args.linkname = (char *) linkname;
  serial = guestfs___send (g, GUESTFS_PROC_LN_F,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_ln_f_args, (char *) &args);
  if (serial == -1) {
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
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "ln_f", "-1");
    return -1;
  }

  if (guestfs___check_reply_header (g, &hdr, GUESTFS_PROC_LN_F, serial) == -1) {
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
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    trace_fp = guestfs___trace_open (g);
    fprintf (trace_fp, "%s = ", "ln_f");
    fprintf (trace_fp, "%d", ret_v);
    guestfs___trace_send_line (g);
  }

  return ret_v;
}

GUESTFS_DLL_PUBLIC int
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
    trace_fp = guestfs___trace_open (g);
    fprintf (trace_fp, "%s", "ln_s");
    fprintf (trace_fp, " \"%s\"", target);
    fprintf (trace_fp, " \"%s\"", linkname);
    guestfs___trace_send_line (g);
  }

  if (guestfs___check_appliance_up (g, "ln_s") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "ln_s", "-1");
    return -1;
  }

  args.target = (char *) target;
  args.linkname = (char *) linkname;
  serial = guestfs___send (g, GUESTFS_PROC_LN_S,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_ln_s_args, (char *) &args);
  if (serial == -1) {
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
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "ln_s", "-1");
    return -1;
  }

  if (guestfs___check_reply_header (g, &hdr, GUESTFS_PROC_LN_S, serial) == -1) {
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
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    trace_fp = guestfs___trace_open (g);
    fprintf (trace_fp, "%s = ", "ln_s");
    fprintf (trace_fp, "%d", ret_v);
    guestfs___trace_send_line (g);
  }

  return ret_v;
}

GUESTFS_DLL_PUBLIC int
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
    trace_fp = guestfs___trace_open (g);
    fprintf (trace_fp, "%s", "mkswap_file");
    fprintf (trace_fp, " \"%s\"", path);
    guestfs___trace_send_line (g);
  }

  if (guestfs___check_appliance_up (g, "mkswap_file") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mkswap_file", "-1");
    return -1;
  }

  args.path = (char *) path;
  serial = guestfs___send (g, GUESTFS_PROC_MKSWAP_FILE,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_mkswap_file_args, (char *) &args);
  if (serial == -1) {
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
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mkswap_file", "-1");
    return -1;
  }

  if (guestfs___check_reply_header (g, &hdr, GUESTFS_PROC_MKSWAP_FILE, serial) == -1) {
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
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    trace_fp = guestfs___trace_open (g);
    fprintf (trace_fp, "%s = ", "mkswap_file");
    fprintf (trace_fp, "%d", ret_v);
    guestfs___trace_send_line (g);
  }

  return ret_v;
}

GUESTFS_DLL_PUBLIC int
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
    trace_fp = guestfs___trace_open (g);
    fprintf (trace_fp, "%s", "part_disk");
    fprintf (trace_fp, " \"%s\"", device);
    fprintf (trace_fp, " \"%s\"", parttype);
    guestfs___trace_send_line (g);
  }

  if (guestfs___check_appliance_up (g, "part_disk") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "part_disk", "-1");
    return -1;
  }

  args.device = (char *) device;
  args.parttype = (char *) parttype;
  serial = guestfs___send (g, GUESTFS_PROC_PART_DISK,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_part_disk_args, (char *) &args);
  if (serial == -1) {
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
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "part_disk", "-1");
    return -1;
  }

  if (guestfs___check_reply_header (g, &hdr, GUESTFS_PROC_PART_DISK, serial) == -1) {
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
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    trace_fp = guestfs___trace_open (g);
    fprintf (trace_fp, "%s = ", "part_disk");
    fprintf (trace_fp, "%d", ret_v);
    guestfs___trace_send_line (g);
  }

  return ret_v;
}

GUESTFS_DLL_PUBLIC char *
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
    trace_fp = guestfs___trace_open (g);
    fprintf (trace_fp, "%s", "part_get_parttype");
    fprintf (trace_fp, " \"%s\"", device);
    guestfs___trace_send_line (g);
  }

  if (guestfs___check_appliance_up (g, "part_get_parttype") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "part_get_parttype", "NULL");
    return NULL;
  }

  args.device = (char *) device;
  serial = guestfs___send (g, GUESTFS_PROC_PART_GET_PARTTYPE,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_part_get_parttype_args, (char *) &args);
  if (serial == -1) {
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
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "part_get_parttype", "NULL");
    return NULL;
  }

  if (guestfs___check_reply_header (g, &hdr, GUESTFS_PROC_PART_GET_PARTTYPE, serial) == -1) {
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
    return NULL;
  }

  ret_v = ret.parttype; /* caller will free */
  if (trace_flag) {
    trace_fp = guestfs___trace_open (g);
    fprintf (trace_fp, "%s = ", "part_get_parttype");
    fprintf (trace_fp, "\"%s\"", ret_v);
    guestfs___trace_send_line (g);
  }

  return ret_v;
}

GUESTFS_DLL_PUBLIC int
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
    trace_fp = guestfs___trace_open (g);
    fprintf (trace_fp, "%s", "vgrename");
    fprintf (trace_fp, " \"%s\"", volgroup);
    fprintf (trace_fp, " \"%s\"", newvolgroup);
    guestfs___trace_send_line (g);
  }

  if (guestfs___check_appliance_up (g, "vgrename") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "vgrename", "-1");
    return -1;
  }

  args.volgroup = (char *) volgroup;
  args.newvolgroup = (char *) newvolgroup;
  serial = guestfs___send (g, GUESTFS_PROC_VGRENAME,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_vgrename_args, (char *) &args);
  if (serial == -1) {
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
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "vgrename", "-1");
    return -1;
  }

  if (guestfs___check_reply_header (g, &hdr, GUESTFS_PROC_VGRENAME, serial) == -1) {
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
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    trace_fp = guestfs___trace_open (g);
    fprintf (trace_fp, "%s = ", "vgrename");
    fprintf (trace_fp, "%d", ret_v);
    guestfs___trace_send_line (g);
  }

  return ret_v;
}

GUESTFS_DLL_PUBLIC char *
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
    trace_fp = guestfs___trace_open (g);
    fprintf (trace_fp, "%s", "vguuid");
    fprintf (trace_fp, " \"%s\"", vgname);
    guestfs___trace_send_line (g);
  }

  if (guestfs___check_appliance_up (g, "vguuid") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "vguuid", "NULL");
    return NULL;
  }

  args.vgname = (char *) vgname;
  serial = guestfs___send (g, GUESTFS_PROC_VGUUID,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_vguuid_args, (char *) &args);
  if (serial == -1) {
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
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "vguuid", "NULL");
    return NULL;
  }

  if (guestfs___check_reply_header (g, &hdr, GUESTFS_PROC_VGUUID, serial) == -1) {
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
    return NULL;
  }

  ret_v = ret.uuid; /* caller will free */
  if (trace_flag) {
    trace_fp = guestfs___trace_open (g);
    fprintf (trace_fp, "%s = ", "vguuid");
    fprintf (trace_fp, "\"%s\"", ret_v);
    guestfs___trace_send_line (g);
  }

  return ret_v;
}

GUESTFS_DLL_PUBLIC int
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
    trace_fp = guestfs___trace_open (g);
    fprintf (trace_fp, "%s", "pwrite");
    fprintf (trace_fp, " \"%s\"", path);
    fputc (' ', trace_fp);
    guestfs___print_BufferIn (trace_fp, content, content_size);
    fprintf (trace_fp, " %" PRIi64, offset);
    guestfs___trace_send_line (g);
  }

  if (guestfs___check_appliance_up (g, "pwrite") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "pwrite", "-1");
    return -1;
  }

  args.path = (char *) path;
  /* Just catch grossly large sizes. XDR encoding will make this precise. */
  if (content_size >= GUESTFS_MESSAGE_MAX) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "pwrite", "-1");
    error (g, "%s: size of input buffer too large", "pwrite");
    return -1;
  }
  args.content.content_val = (char *) content;
  args.content.content_len = content_size;
  args.offset = offset;
  serial = guestfs___send (g, GUESTFS_PROC_PWRITE,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_pwrite_args, (char *) &args);
  if (serial == -1) {
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
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "pwrite", "-1");
    return -1;
  }

  if (guestfs___check_reply_header (g, &hdr, GUESTFS_PROC_PWRITE, serial) == -1) {
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
    return -1;
  }

  ret_v = ret.nbytes;
  if (trace_flag) {
    trace_fp = guestfs___trace_open (g);
    fprintf (trace_fp, "%s = ", "pwrite");
    fprintf (trace_fp, "%d", ret_v);
    guestfs___trace_send_line (g);
  }

  return ret_v;
}

GUESTFS_DLL_PUBLIC char *
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
    trace_fp = guestfs___trace_open (g);
    fprintf (trace_fp, "%s", "vfs_label");
    fprintf (trace_fp, " \"%s\"", device);
    guestfs___trace_send_line (g);
  }

  if (guestfs___check_appliance_up (g, "vfs_label") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "vfs_label", "NULL");
    return NULL;
  }

  args.device = (char *) device;
  serial = guestfs___send (g, GUESTFS_PROC_VFS_LABEL,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_vfs_label_args, (char *) &args);
  if (serial == -1) {
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
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "vfs_label", "NULL");
    return NULL;
  }

  if (guestfs___check_reply_header (g, &hdr, GUESTFS_PROC_VFS_LABEL, serial) == -1) {
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
    return NULL;
  }

  ret_v = ret.label; /* caller will free */
  if (trace_flag) {
    trace_fp = guestfs___trace_open (g);
    fprintf (trace_fp, "%s = ", "vfs_label");
    fprintf (trace_fp, "\"%s\"", ret_v);
    guestfs___trace_send_line (g);
  }

  return ret_v;
}

GUESTFS_DLL_PUBLIC int
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
    trace_fp = guestfs___trace_open (g);
    fprintf (trace_fp, "%s", "luks_close");
    fprintf (trace_fp, " \"%s\"", device);
    guestfs___trace_send_line (g);
  }

  if (guestfs___check_appliance_up (g, "luks_close") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "luks_close", "-1");
    return -1;
  }

  args.device = (char *) device;
  serial = guestfs___send (g, GUESTFS_PROC_LUKS_CLOSE,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_luks_close_args, (char *) &args);
  if (serial == -1) {
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
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "luks_close", "-1");
    return -1;
  }

  if (guestfs___check_reply_header (g, &hdr, GUESTFS_PROC_LUKS_CLOSE, serial) == -1) {
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
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    trace_fp = guestfs___trace_open (g);
    fprintf (trace_fp, "%s = ", "luks_close");
    fprintf (trace_fp, "%d", ret_v);
    guestfs___trace_send_line (g);
  }

  return ret_v;
}

GUESTFS_DLL_PUBLIC int
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
    trace_fp = guestfs___trace_open (g);
    fprintf (trace_fp, "%s", "resize2fs_M");
    fprintf (trace_fp, " \"%s\"", device);
    guestfs___trace_send_line (g);
  }

  if (guestfs___check_appliance_up (g, "resize2fs_M") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "resize2fs_M", "-1");
    return -1;
  }

  args.device = (char *) device;
  serial = guestfs___send (g, GUESTFS_PROC_RESIZE2FS_M,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_resize2fs_M_args, (char *) &args);
  if (serial == -1) {
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
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "resize2fs_M", "-1");
    return -1;
  }

  if (guestfs___check_reply_header (g, &hdr, GUESTFS_PROC_RESIZE2FS_M, serial) == -1) {
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
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    trace_fp = guestfs___trace_open (g);
    fprintf (trace_fp, "%s = ", "resize2fs_M");
    fprintf (trace_fp, "%d", ret_v);
    guestfs___trace_send_line (g);
  }

  return ret_v;
}

GUESTFS_DLL_PUBLIC int
guestfs_mount_9p_argv (guestfs_h *g,
                       const char *mounttag,
                       const char *mountpoint,
                       const struct guestfs_mount_9p_argv *optargs)
{
  struct guestfs_mount_9p_argv optargs_null;
  if (!optargs) {
    optargs_null.bitmask = 0;
    optargs = &optargs_null;
  }

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
    trace_fp = guestfs___trace_open (g);
    fprintf (trace_fp, "%s", "mount_9p");
    fprintf (trace_fp, " \"%s\"", mounttag);
    fprintf (trace_fp, " \"%s\"", mountpoint);
    if (optargs->bitmask & GUESTFS_MOUNT_9P_OPTIONS_BITMASK) {
      fprintf (trace_fp, " \"%s:%s\"", "options", optargs->options);
    }
    guestfs___trace_send_line (g);
  }

  if (guestfs___check_appliance_up (g, "mount_9p") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mount_9p", "-1");
    return -1;
  }

  args.mounttag = (char *) mounttag;
  args.mountpoint = (char *) mountpoint;
  if (optargs->bitmask & GUESTFS_MOUNT_9P_OPTIONS_BITMASK) {
    args.options = (char *) optargs->options;
  } else {
    args.options = (char *) "";
  }
  serial = guestfs___send (g, GUESTFS_PROC_MOUNT_9P,
                           progress_hint, optargs->bitmask,
                           (xdrproc_t) xdr_guestfs_mount_9p_args, (char *) &args);
  if (serial == -1) {
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
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mount_9p", "-1");
    return -1;
  }

  if (guestfs___check_reply_header (g, &hdr, GUESTFS_PROC_MOUNT_9P, serial) == -1) {
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
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    trace_fp = guestfs___trace_open (g);
    fprintf (trace_fp, "%s = ", "mount_9p");
    fprintf (trace_fp, "%d", ret_v);
    guestfs___trace_send_line (g);
  }

  return ret_v;
}

GUESTFS_DLL_PUBLIC int
guestfs_ntfsresize_opts_argv (guestfs_h *g,
                              const char *device,
                              const struct guestfs_ntfsresize_opts_argv *optargs)
{
  struct guestfs_ntfsresize_opts_argv optargs_null;
  if (!optargs) {
    optargs_null.bitmask = 0;
    optargs = &optargs_null;
  }

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
           "ntfsresize_opts", "device");
    return -1;
  }

  if (optargs->bitmask & UINT64_C(0xfffffffffffffffc)) {
    error (g, "%s: unknown option in guestfs_%s_argv->bitmask (this can happen if a program is compiled against a newer version of libguestfs, then dynamically linked to an older version)",
           "ntfsresize_opts", "ntfsresize_opts");
    return -1;
  }

  if (trace_flag) {
    trace_fp = guestfs___trace_open (g);
    fprintf (trace_fp, "%s", "ntfsresize");
    fprintf (trace_fp, " \"%s\"", device);
    if (optargs->bitmask & GUESTFS_NTFSRESIZE_OPTS_SIZE_BITMASK) {
      fprintf (trace_fp, " \"%s:%" PRIi64 "\"", "size", optargs->size);
    }
    if (optargs->bitmask & GUESTFS_NTFSRESIZE_OPTS_FORCE_BITMASK) {
      fprintf (trace_fp, " \"%s:%s\"", "force", optargs->force ? "true" : "false");
    }
    guestfs___trace_send_line (g);
  }

  if (guestfs___check_appliance_up (g, "ntfsresize") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "ntfsresize", "-1");
    return -1;
  }

  args.device = (char *) device;
  if (optargs->bitmask & GUESTFS_NTFSRESIZE_OPTS_SIZE_BITMASK) {
    args.size = optargs->size;
  } else {
    args.size = 0;
  }
  if (optargs->bitmask & GUESTFS_NTFSRESIZE_OPTS_FORCE_BITMASK) {
    args.force = optargs->force;
  } else {
    args.force = 0;
  }
  serial = guestfs___send (g, GUESTFS_PROC_NTFSRESIZE,
                           progress_hint, optargs->bitmask,
                           (xdrproc_t) xdr_guestfs_ntfsresize_args, (char *) &args);
  if (serial == -1) {
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
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "ntfsresize", "-1");
    return -1;
  }

  if (guestfs___check_reply_header (g, &hdr, GUESTFS_PROC_NTFSRESIZE, serial) == -1) {
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
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    trace_fp = guestfs___trace_open (g);
    fprintf (trace_fp, "%s = ", "ntfsresize");
    fprintf (trace_fp, "%d", ret_v);
    guestfs___trace_send_line (g);
  }

  return ret_v;
}

GUESTFS_DLL_PUBLIC int
guestfs_compress_out_argv (guestfs_h *g,
                           const char *ctype,
                           const char *file,
                           const char *zfile,
                           const struct guestfs_compress_out_argv *optargs)
{
  struct guestfs_compress_out_argv optargs_null;
  if (!optargs) {
    optargs_null.bitmask = 0;
    optargs = &optargs_null;
  }

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
    trace_fp = guestfs___trace_open (g);
    fprintf (trace_fp, "%s", "compress_out");
    fprintf (trace_fp, " \"%s\"", ctype);
    fprintf (trace_fp, " \"%s\"", file);
    fprintf (trace_fp, " \"%s\"", zfile);
    if (optargs->bitmask & GUESTFS_COMPRESS_OUT_LEVEL_BITMASK) {
      fprintf (trace_fp, " \"%s:%d\"", "level", optargs->level);
    }
    guestfs___trace_send_line (g);
  }

  if (guestfs___check_appliance_up (g, "compress_out") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "compress_out", "-1");
    return -1;
  }

  args.ctype = (char *) ctype;
  args.file = (char *) file;
  if (optargs->bitmask & GUESTFS_COMPRESS_OUT_LEVEL_BITMASK) {
    args.level = optargs->level;
  } else {
    args.level = 0;
  }
  serial = guestfs___send (g, GUESTFS_PROC_COMPRESS_OUT,
                           progress_hint, optargs->bitmask,
                           (xdrproc_t) xdr_guestfs_compress_out_args, (char *) &args);
  if (serial == -1) {
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
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "compress_out", "-1");
    return -1;
  }

  if (guestfs___check_reply_header (g, &hdr, GUESTFS_PROC_COMPRESS_OUT, serial) == -1) {
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
    return -1;
  }

  if (guestfs___recv_file (g, zfile) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "compress_out", "-1");
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    trace_fp = guestfs___trace_open (g);
    fprintf (trace_fp, "%s = ", "compress_out");
    fprintf (trace_fp, "%d", ret_v);
    guestfs___trace_send_line (g);
  }

  return ret_v;
}

GUESTFS_DLL_PUBLIC int
guestfs_compress_device_out_argv (guestfs_h *g,
                                  const char *ctype,
                                  const char *device,
                                  const char *zdevice,
                                  const struct guestfs_compress_device_out_argv *optargs)
{
  struct guestfs_compress_device_out_argv optargs_null;
  if (!optargs) {
    optargs_null.bitmask = 0;
    optargs = &optargs_null;
  }

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
    trace_fp = guestfs___trace_open (g);
    fprintf (trace_fp, "%s", "compress_device_out");
    fprintf (trace_fp, " \"%s\"", ctype);
    fprintf (trace_fp, " \"%s\"", device);
    fprintf (trace_fp, " \"%s\"", zdevice);
    if (optargs->bitmask & GUESTFS_COMPRESS_DEVICE_OUT_LEVEL_BITMASK) {
      fprintf (trace_fp, " \"%s:%d\"", "level", optargs->level);
    }
    guestfs___trace_send_line (g);
  }

  if (guestfs___check_appliance_up (g, "compress_device_out") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "compress_device_out", "-1");
    return -1;
  }

  args.ctype = (char *) ctype;
  args.device = (char *) device;
  if (optargs->bitmask & GUESTFS_COMPRESS_DEVICE_OUT_LEVEL_BITMASK) {
    args.level = optargs->level;
  } else {
    args.level = 0;
  }
  serial = guestfs___send (g, GUESTFS_PROC_COMPRESS_DEVICE_OUT,
                           progress_hint, optargs->bitmask,
                           (xdrproc_t) xdr_guestfs_compress_device_out_args, (char *) &args);
  if (serial == -1) {
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
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "compress_device_out", "-1");
    return -1;
  }

  if (guestfs___check_reply_header (g, &hdr, GUESTFS_PROC_COMPRESS_DEVICE_OUT, serial) == -1) {
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
    return -1;
  }

  if (guestfs___recv_file (g, zdevice) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "compress_device_out", "-1");
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    trace_fp = guestfs___trace_open (g);
    fprintf (trace_fp, "%s = ", "compress_device_out");
    fprintf (trace_fp, "%d", ret_v);
    guestfs___trace_send_line (g);
  }

  return ret_v;
}

GUESTFS_DLL_PUBLIC int
guestfs_md_stop (guestfs_h *g,
                 const char *md)
{
  struct guestfs_md_stop_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "md_stop", 7);
  if (md == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "md_stop", "md");
    return -1;
  }

  if (trace_flag) {
    trace_fp = guestfs___trace_open (g);
    fprintf (trace_fp, "%s", "md_stop");
    fprintf (trace_fp, " \"%s\"", md);
    guestfs___trace_send_line (g);
  }

  if (guestfs___check_appliance_up (g, "md_stop") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "md_stop", "-1");
    return -1;
  }

  args.md = (char *) md;
  serial = guestfs___send (g, GUESTFS_PROC_MD_STOP,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_md_stop_args, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "md_stop", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "md_stop", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "md_stop", "-1");
    return -1;
  }

  if (guestfs___check_reply_header (g, &hdr, GUESTFS_PROC_MD_STOP, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "md_stop", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "md_stop", "-1");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "md_stop", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "md_stop",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    trace_fp = guestfs___trace_open (g);
    fprintf (trace_fp, "%s = ", "md_stop");
    fprintf (trace_fp, "%d", ret_v);
    guestfs___trace_send_line (g);
  }

  return ret_v;
}

GUESTFS_DLL_PUBLIC int
guestfs_e2fsck_argv (guestfs_h *g,
                     const char *device,
                     const struct guestfs_e2fsck_argv *optargs)
{
  struct guestfs_e2fsck_argv optargs_null;
  if (!optargs) {
    optargs_null.bitmask = 0;
    optargs = &optargs_null;
  }

  struct guestfs_e2fsck_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "e2fsck", 6);
  if (device == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "e2fsck", "device");
    return -1;
  }

  if (optargs->bitmask & UINT64_C(0xfffffffffffffffc)) {
    error (g, "%s: unknown option in guestfs_%s_argv->bitmask (this can happen if a program is compiled against a newer version of libguestfs, then dynamically linked to an older version)",
           "e2fsck", "e2fsck");
    return -1;
  }

  if (trace_flag) {
    trace_fp = guestfs___trace_open (g);
    fprintf (trace_fp, "%s", "e2fsck");
    fprintf (trace_fp, " \"%s\"", device);
    if (optargs->bitmask & GUESTFS_E2FSCK_CORRECT_BITMASK) {
      fprintf (trace_fp, " \"%s:%s\"", "correct", optargs->correct ? "true" : "false");
    }
    if (optargs->bitmask & GUESTFS_E2FSCK_FORCEALL_BITMASK) {
      fprintf (trace_fp, " \"%s:%s\"", "forceall", optargs->forceall ? "true" : "false");
    }
    guestfs___trace_send_line (g);
  }

  if (guestfs___check_appliance_up (g, "e2fsck") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "e2fsck", "-1");
    return -1;
  }

  args.device = (char *) device;
  if (optargs->bitmask & GUESTFS_E2FSCK_CORRECT_BITMASK) {
    args.correct = optargs->correct;
  } else {
    args.correct = 0;
  }
  if (optargs->bitmask & GUESTFS_E2FSCK_FORCEALL_BITMASK) {
    args.forceall = optargs->forceall;
  } else {
    args.forceall = 0;
  }
  serial = guestfs___send (g, GUESTFS_PROC_E2FSCK,
                           progress_hint, optargs->bitmask,
                           (xdrproc_t) xdr_guestfs_e2fsck_args, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "e2fsck", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "e2fsck", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "e2fsck", "-1");
    return -1;
  }

  if (guestfs___check_reply_header (g, &hdr, GUESTFS_PROC_E2FSCK, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "e2fsck", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "e2fsck", "-1");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "e2fsck", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "e2fsck",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    trace_fp = guestfs___trace_open (g);
    fprintf (trace_fp, "%s = ", "e2fsck");
    fprintf (trace_fp, "%d", ret_v);
    guestfs___trace_send_line (g);
  }

  return ret_v;
}

GUESTFS_DLL_PUBLIC char *
guestfs_vgmeta (guestfs_h *g,
                const char *vgname,
                size_t *size_r)
{
  struct guestfs_vgmeta_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  struct guestfs_vgmeta_ret ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  char *ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "vgmeta", 6);
  if (vgname == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "vgmeta", "vgname");
    return NULL;
  }

  if (trace_flag) {
    trace_fp = guestfs___trace_open (g);
    fprintf (trace_fp, "%s", "vgmeta");
    fprintf (trace_fp, " \"%s\"", vgname);
    guestfs___trace_send_line (g);
  }

  if (guestfs___check_appliance_up (g, "vgmeta") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "vgmeta", "NULL");
    return NULL;
  }

  args.vgname = (char *) vgname;
  serial = guestfs___send (g, GUESTFS_PROC_VGMETA,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_vgmeta_args, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "vgmeta", "NULL");
    return NULL;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs___recv (g, "vgmeta", &hdr, &err,
        (xdrproc_t) xdr_guestfs_vgmeta_ret, (char *) &ret);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "vgmeta", "NULL");
    return NULL;
  }

  if (guestfs___check_reply_header (g, &hdr, GUESTFS_PROC_VGMETA, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "vgmeta", "NULL");
    return NULL;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "vgmeta", "NULL");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "vgmeta", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "vgmeta",
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
  if (ret.metadata.metadata_len > 0) {
    *size_r = ret.metadata.metadata_len;
    ret_v = ret.metadata.metadata_val; /* caller will free */
  } else {
    free (ret.metadata.metadata_val);
    char *p = safe_malloc (g, 1);
    *size_r = ret.metadata.metadata_len;
    ret_v = p;
  }
  if (trace_flag) {
    trace_fp = guestfs___trace_open (g);
    fprintf (trace_fp, "%s = ", "vgmeta");
    guestfs___print_BufferOut (trace_fp, ret_v, *size_r);
    guestfs___trace_send_line (g);
  }

  return ret_v;
}

GUESTFS_DLL_PUBLIC int
guestfs_mkfs_btrfs_argv (guestfs_h *g,
                         char *const *devices,
                         const struct guestfs_mkfs_btrfs_argv *optargs)
{
  struct guestfs_mkfs_btrfs_argv optargs_null;
  if (!optargs) {
    optargs_null.bitmask = 0;
    optargs = &optargs_null;
  }

  struct guestfs_mkfs_btrfs_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "mkfs_btrfs", 10);
  if (devices == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "mkfs_btrfs", "devices");
    return -1;
  }
  if ((optargs->bitmask & GUESTFS_MKFS_BTRFS_DATATYPE_BITMASK) &&
      optargs->datatype == NULL) {
    error (g, "%s: %s: optional parameter cannot be NULL",
           "mkfs_btrfs", "datatype");
    return -1;
  }
  if ((optargs->bitmask & GUESTFS_MKFS_BTRFS_LABEL_BITMASK) &&
      optargs->label == NULL) {
    error (g, "%s: %s: optional parameter cannot be NULL",
           "mkfs_btrfs", "label");
    return -1;
  }
  if ((optargs->bitmask & GUESTFS_MKFS_BTRFS_METADATA_BITMASK) &&
      optargs->metadata == NULL) {
    error (g, "%s: %s: optional parameter cannot be NULL",
           "mkfs_btrfs", "metadata");
    return -1;
  }

  if (optargs->bitmask & UINT64_C(0xffffffffffffff00)) {
    error (g, "%s: unknown option in guestfs_%s_argv->bitmask (this can happen if a program is compiled against a newer version of libguestfs, then dynamically linked to an older version)",
           "mkfs_btrfs", "mkfs_btrfs");
    return -1;
  }

  if (trace_flag) {
    size_t i;

    trace_fp = guestfs___trace_open (g);
    fprintf (trace_fp, "%s", "mkfs_btrfs");
    fputc (' ', trace_fp);
    fputc ('"', trace_fp);
    for (i = 0; devices[i]; ++i) {
      if (i > 0) fputc (' ', trace_fp);
      fputs (devices[i], trace_fp);
    }
    fputc ('"', trace_fp);
    if (optargs->bitmask & GUESTFS_MKFS_BTRFS_ALLOCSTART_BITMASK) {
      fprintf (trace_fp, " \"%s:%" PRIi64 "\"", "allocstart", optargs->allocstart);
    }
    if (optargs->bitmask & GUESTFS_MKFS_BTRFS_BYTECOUNT_BITMASK) {
      fprintf (trace_fp, " \"%s:%" PRIi64 "\"", "bytecount", optargs->bytecount);
    }
    if (optargs->bitmask & GUESTFS_MKFS_BTRFS_DATATYPE_BITMASK) {
      fprintf (trace_fp, " \"%s:%s\"", "datatype", optargs->datatype);
    }
    if (optargs->bitmask & GUESTFS_MKFS_BTRFS_LEAFSIZE_BITMASK) {
      fprintf (trace_fp, " \"%s:%d\"", "leafsize", optargs->leafsize);
    }
    if (optargs->bitmask & GUESTFS_MKFS_BTRFS_LABEL_BITMASK) {
      fprintf (trace_fp, " \"%s:%s\"", "label", optargs->label);
    }
    if (optargs->bitmask & GUESTFS_MKFS_BTRFS_METADATA_BITMASK) {
      fprintf (trace_fp, " \"%s:%s\"", "metadata", optargs->metadata);
    }
    if (optargs->bitmask & GUESTFS_MKFS_BTRFS_NODESIZE_BITMASK) {
      fprintf (trace_fp, " \"%s:%d\"", "nodesize", optargs->nodesize);
    }
    if (optargs->bitmask & GUESTFS_MKFS_BTRFS_SECTORSIZE_BITMASK) {
      fprintf (trace_fp, " \"%s:%d\"", "sectorsize", optargs->sectorsize);
    }
    guestfs___trace_send_line (g);
  }

  if (guestfs___check_appliance_up (g, "mkfs_btrfs") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mkfs_btrfs", "-1");
    return -1;
  }

  args.devices.devices_val = (char **) devices;
  for (args.devices.devices_len = 0; devices[args.devices.devices_len]; args.devices.devices_len++) ;
  if (optargs->bitmask & GUESTFS_MKFS_BTRFS_ALLOCSTART_BITMASK) {
    args.allocstart = optargs->allocstart;
  } else {
    args.allocstart = 0;
  }
  if (optargs->bitmask & GUESTFS_MKFS_BTRFS_BYTECOUNT_BITMASK) {
    args.bytecount = optargs->bytecount;
  } else {
    args.bytecount = 0;
  }
  if (optargs->bitmask & GUESTFS_MKFS_BTRFS_DATATYPE_BITMASK) {
    args.datatype = (char *) optargs->datatype;
  } else {
    args.datatype = (char *) "";
  }
  if (optargs->bitmask & GUESTFS_MKFS_BTRFS_LEAFSIZE_BITMASK) {
    args.leafsize = optargs->leafsize;
  } else {
    args.leafsize = 0;
  }
  if (optargs->bitmask & GUESTFS_MKFS_BTRFS_LABEL_BITMASK) {
    args.label = (char *) optargs->label;
  } else {
    args.label = (char *) "";
  }
  if (optargs->bitmask & GUESTFS_MKFS_BTRFS_METADATA_BITMASK) {
    args.metadata = (char *) optargs->metadata;
  } else {
    args.metadata = (char *) "";
  }
  if (optargs->bitmask & GUESTFS_MKFS_BTRFS_NODESIZE_BITMASK) {
    args.nodesize = optargs->nodesize;
  } else {
    args.nodesize = 0;
  }
  if (optargs->bitmask & GUESTFS_MKFS_BTRFS_SECTORSIZE_BITMASK) {
    args.sectorsize = optargs->sectorsize;
  } else {
    args.sectorsize = 0;
  }
  serial = guestfs___send (g, GUESTFS_PROC_MKFS_BTRFS,
                           progress_hint, optargs->bitmask,
                           (xdrproc_t) xdr_guestfs_mkfs_btrfs_args, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mkfs_btrfs", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "mkfs_btrfs", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mkfs_btrfs", "-1");
    return -1;
  }

  if (guestfs___check_reply_header (g, &hdr, GUESTFS_PROC_MKFS_BTRFS, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mkfs_btrfs", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mkfs_btrfs", "-1");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "mkfs_btrfs", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "mkfs_btrfs",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    trace_fp = guestfs___trace_open (g);
    fprintf (trace_fp, "%s = ", "mkfs_btrfs");
    fprintf (trace_fp, "%d", ret_v);
    guestfs___trace_send_line (g);
  }

  return ret_v;
}

GUESTFS_DLL_PUBLIC int
guestfs_vgchange_uuid_all (guestfs_h *g)
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
                                    "vgchange_uuid_all", 17);
  if (trace_flag) {
    trace_fp = guestfs___trace_open (g);
    fprintf (trace_fp, "%s", "vgchange_uuid_all");
    guestfs___trace_send_line (g);
  }

  if (guestfs___check_appliance_up (g, "vgchange_uuid_all") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "vgchange_uuid_all", "-1");
    return -1;
  }

  serial = guestfs___send (g, GUESTFS_PROC_VGCHANGE_UUID_ALL, progress_hint, 0,
                           NULL, NULL);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "vgchange_uuid_all", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "vgchange_uuid_all", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "vgchange_uuid_all", "-1");
    return -1;
  }

  if (guestfs___check_reply_header (g, &hdr, GUESTFS_PROC_VGCHANGE_UUID_ALL, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "vgchange_uuid_all", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "vgchange_uuid_all", "-1");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "vgchange_uuid_all", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "vgchange_uuid_all",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    trace_fp = guestfs___trace_open (g);
    fprintf (trace_fp, "%s = ", "vgchange_uuid_all");
    fprintf (trace_fp, "%d", ret_v);
    guestfs___trace_send_line (g);
  }

  return ret_v;
}

GUESTFS_DLL_PUBLIC int64_t
guestfs_hivex_node_get_child (guestfs_h *g,
                              int64_t nodeh,
                              const char *name)
{
  struct guestfs_hivex_node_get_child_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  struct guestfs_hivex_node_get_child_ret ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  int64_t ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "hivex_node_get_child", 20);
  if (name == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "hivex_node_get_child", "name");
    return -1;
  }

  if (trace_flag) {
    trace_fp = guestfs___trace_open (g);
    fprintf (trace_fp, "%s", "hivex_node_get_child");
    fprintf (trace_fp, " %" PRIi64, nodeh);
    fprintf (trace_fp, " \"%s\"", name);
    guestfs___trace_send_line (g);
  }

  if (guestfs___check_appliance_up (g, "hivex_node_get_child") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "hivex_node_get_child", "-1");
    return -1;
  }

  args.nodeh = nodeh;
  args.name = (char *) name;
  serial = guestfs___send (g, GUESTFS_PROC_HIVEX_NODE_GET_CHILD,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_hivex_node_get_child_args, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "hivex_node_get_child", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs___recv (g, "hivex_node_get_child", &hdr, &err,
        (xdrproc_t) xdr_guestfs_hivex_node_get_child_ret, (char *) &ret);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "hivex_node_get_child", "-1");
    return -1;
  }

  if (guestfs___check_reply_header (g, &hdr, GUESTFS_PROC_HIVEX_NODE_GET_CHILD, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "hivex_node_get_child", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "hivex_node_get_child", "-1");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "hivex_node_get_child", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "hivex_node_get_child",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    return -1;
  }

  ret_v = ret.child;
  if (trace_flag) {
    trace_fp = guestfs___trace_open (g);
    fprintf (trace_fp, "%s = ", "hivex_node_get_child");
    fprintf (trace_fp, "%" PRIi64, ret_v);
    guestfs___trace_send_line (g);
  }

  return ret_v;
}

GUESTFS_DLL_PUBLIC char *
guestfs_hivex_value_key (guestfs_h *g,
                         int64_t valueh)
{
  struct guestfs_hivex_value_key_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  struct guestfs_hivex_value_key_ret ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  char *ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "hivex_value_key", 15);
  if (trace_flag) {
    trace_fp = guestfs___trace_open (g);
    fprintf (trace_fp, "%s", "hivex_value_key");
    fprintf (trace_fp, " %" PRIi64, valueh);
    guestfs___trace_send_line (g);
  }

  if (guestfs___check_appliance_up (g, "hivex_value_key") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "hivex_value_key", "NULL");
    return NULL;
  }

  args.valueh = valueh;
  serial = guestfs___send (g, GUESTFS_PROC_HIVEX_VALUE_KEY,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_hivex_value_key_args, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "hivex_value_key", "NULL");
    return NULL;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs___recv (g, "hivex_value_key", &hdr, &err,
        (xdrproc_t) xdr_guestfs_hivex_value_key_ret, (char *) &ret);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "hivex_value_key", "NULL");
    return NULL;
  }

  if (guestfs___check_reply_header (g, &hdr, GUESTFS_PROC_HIVEX_VALUE_KEY, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "hivex_value_key", "NULL");
    return NULL;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "hivex_value_key", "NULL");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "hivex_value_key", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "hivex_value_key",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    return NULL;
  }

  ret_v = ret.key; /* caller will free */
  if (trace_flag) {
    trace_fp = guestfs___trace_open (g);
    fprintf (trace_fp, "%s = ", "hivex_value_key");
    fprintf (trace_fp, "\"%s\"", ret_v);
    guestfs___trace_send_line (g);
  }

  return ret_v;
}

GUESTFS_DLL_PUBLIC int64_t
guestfs_hivex_value_type (guestfs_h *g,
                          int64_t valueh)
{
  struct guestfs_hivex_value_type_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  struct guestfs_hivex_value_type_ret ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  int64_t ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "hivex_value_type", 16);
  if (trace_flag) {
    trace_fp = guestfs___trace_open (g);
    fprintf (trace_fp, "%s", "hivex_value_type");
    fprintf (trace_fp, " %" PRIi64, valueh);
    guestfs___trace_send_line (g);
  }

  if (guestfs___check_appliance_up (g, "hivex_value_type") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "hivex_value_type", "-1");
    return -1;
  }

  args.valueh = valueh;
  serial = guestfs___send (g, GUESTFS_PROC_HIVEX_VALUE_TYPE,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_hivex_value_type_args, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "hivex_value_type", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs___recv (g, "hivex_value_type", &hdr, &err,
        (xdrproc_t) xdr_guestfs_hivex_value_type_ret, (char *) &ret);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "hivex_value_type", "-1");
    return -1;
  }

  if (guestfs___check_reply_header (g, &hdr, GUESTFS_PROC_HIVEX_VALUE_TYPE, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "hivex_value_type", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "hivex_value_type", "-1");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "hivex_value_type", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "hivex_value_type",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    return -1;
  }

  ret_v = ret.datatype;
  if (trace_flag) {
    trace_fp = guestfs___trace_open (g);
    fprintf (trace_fp, "%s = ", "hivex_value_type");
    fprintf (trace_fp, "%" PRIi64, ret_v);
    guestfs___trace_send_line (g);
  }

  return ret_v;
}

GUESTFS_DLL_PUBLIC int
guestfs_hivex_node_set_value (guestfs_h *g,
                              int64_t nodeh,
                              const char *key,
                              int64_t t,
                              const char *val,
                              size_t val_size)
{
  struct guestfs_hivex_node_set_value_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "hivex_node_set_value", 20);
  if (key == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "hivex_node_set_value", "key");
    return -1;
  }
  if (val == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "hivex_node_set_value", "val");
    return -1;
  }

  if (trace_flag) {
    trace_fp = guestfs___trace_open (g);
    fprintf (trace_fp, "%s", "hivex_node_set_value");
    fprintf (trace_fp, " %" PRIi64, nodeh);
    fprintf (trace_fp, " \"%s\"", key);
    fprintf (trace_fp, " %" PRIi64, t);
    fputc (' ', trace_fp);
    guestfs___print_BufferIn (trace_fp, val, val_size);
    guestfs___trace_send_line (g);
  }

  if (guestfs___check_appliance_up (g, "hivex_node_set_value") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "hivex_node_set_value", "-1");
    return -1;
  }

  args.nodeh = nodeh;
  args.key = (char *) key;
  args.t = t;
  /* Just catch grossly large sizes. XDR encoding will make this precise. */
  if (val_size >= GUESTFS_MESSAGE_MAX) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "hivex_node_set_value", "-1");
    error (g, "%s: size of input buffer too large", "hivex_node_set_value");
    return -1;
  }
  args.val.val_val = (char *) val;
  args.val.val_len = val_size;
  serial = guestfs___send (g, GUESTFS_PROC_HIVEX_NODE_SET_VALUE,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_hivex_node_set_value_args, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "hivex_node_set_value", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "hivex_node_set_value", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "hivex_node_set_value", "-1");
    return -1;
  }

  if (guestfs___check_reply_header (g, &hdr, GUESTFS_PROC_HIVEX_NODE_SET_VALUE, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "hivex_node_set_value", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "hivex_node_set_value", "-1");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "hivex_node_set_value", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "hivex_node_set_value",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    trace_fp = guestfs___trace_open (g);
    fprintf (trace_fp, "%s = ", "hivex_node_set_value");
    fprintf (trace_fp, "%d", ret_v);
    guestfs___trace_send_line (g);
  }

  return ret_v;
}

GUESTFS_DLL_PUBLIC int
guestfs_internal_hot_add_drive (guestfs_h *g,
                                const char *label)
{
  struct guestfs_internal_hot_add_drive_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "internal_hot_add_drive", 22);
  if (label == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "internal_hot_add_drive", "label");
    return -1;
  }

  if (trace_flag) {
    trace_fp = guestfs___trace_open (g);
    fprintf (trace_fp, "%s", "internal_hot_add_drive");
    fprintf (trace_fp, " \"%s\"", label);
    guestfs___trace_send_line (g);
  }

  if (guestfs___check_appliance_up (g, "internal_hot_add_drive") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "internal_hot_add_drive", "-1");
    return -1;
  }

  args.label = (char *) label;
  serial = guestfs___send (g, GUESTFS_PROC_INTERNAL_HOT_ADD_DRIVE,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_internal_hot_add_drive_args, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "internal_hot_add_drive", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "internal_hot_add_drive", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "internal_hot_add_drive", "-1");
    return -1;
  }

  if (guestfs___check_reply_header (g, &hdr, GUESTFS_PROC_INTERNAL_HOT_ADD_DRIVE, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "internal_hot_add_drive", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "internal_hot_add_drive", "-1");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "internal_hot_add_drive", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "internal_hot_add_drive",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    trace_fp = guestfs___trace_open (g);
    fprintf (trace_fp, "%s = ", "internal_hot_add_drive");
    fprintf (trace_fp, "%d", ret_v);
    guestfs___trace_send_line (g);
  }

  return ret_v;
}

GUESTFS_DLL_PUBLIC int
guestfs_internal_hot_remove_drive_precheck (guestfs_h *g,
                                            const char *label)
{
  struct guestfs_internal_hot_remove_drive_precheck_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "internal_hot_remove_drive_precheck", 34);
  if (label == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "internal_hot_remove_drive_precheck", "label");
    return -1;
  }

  if (trace_flag) {
    trace_fp = guestfs___trace_open (g);
    fprintf (trace_fp, "%s", "internal_hot_remove_drive_precheck");
    fprintf (trace_fp, " \"%s\"", label);
    guestfs___trace_send_line (g);
  }

  if (guestfs___check_appliance_up (g, "internal_hot_remove_drive_precheck") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "internal_hot_remove_drive_precheck", "-1");
    return -1;
  }

  args.label = (char *) label;
  serial = guestfs___send (g, GUESTFS_PROC_INTERNAL_HOT_REMOVE_DRIVE_PRECHECK,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_internal_hot_remove_drive_precheck_args, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "internal_hot_remove_drive_precheck", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "internal_hot_remove_drive_precheck", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "internal_hot_remove_drive_precheck", "-1");
    return -1;
  }

  if (guestfs___check_reply_header (g, &hdr, GUESTFS_PROC_INTERNAL_HOT_REMOVE_DRIVE_PRECHECK, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "internal_hot_remove_drive_precheck", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "internal_hot_remove_drive_precheck", "-1");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "internal_hot_remove_drive_precheck", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "internal_hot_remove_drive_precheck",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    trace_fp = guestfs___trace_open (g);
    fprintf (trace_fp, "%s = ", "internal_hot_remove_drive_precheck");
    fprintf (trace_fp, "%d", ret_v);
    guestfs___trace_send_line (g);
  }

  return ret_v;
}

GUESTFS_DLL_PUBLIC int
guestfs_mklost_and_found (guestfs_h *g,
                          const char *mountpoint)
{
  struct guestfs_mklost_and_found_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "mklost_and_found", 16);
  if (mountpoint == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "mklost_and_found", "mountpoint");
    return -1;
  }

  if (trace_flag) {
    trace_fp = guestfs___trace_open (g);
    fprintf (trace_fp, "%s", "mklost_and_found");
    fprintf (trace_fp, " \"%s\"", mountpoint);
    guestfs___trace_send_line (g);
  }

  if (guestfs___check_appliance_up (g, "mklost_and_found") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mklost_and_found", "-1");
    return -1;
  }

  args.mountpoint = (char *) mountpoint;
  serial = guestfs___send (g, GUESTFS_PROC_MKLOST_AND_FOUND,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_mklost_and_found_args, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mklost_and_found", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "mklost_and_found", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mklost_and_found", "-1");
    return -1;
  }

  if (guestfs___check_reply_header (g, &hdr, GUESTFS_PROC_MKLOST_AND_FOUND, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mklost_and_found", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "mklost_and_found", "-1");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "mklost_and_found", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "mklost_and_found",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    trace_fp = guestfs___trace_open (g);
    fprintf (trace_fp, "%s = ", "mklost_and_found");
    fprintf (trace_fp, "%d", ret_v);
    guestfs___trace_send_line (g);
  }

  return ret_v;
}

GUESTFS_DLL_PUBLIC int
guestfs_acl_delete_def_file (guestfs_h *g,
                             const char *dir)
{
  struct guestfs_acl_delete_def_file_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "acl_delete_def_file", 19);
  if (dir == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "acl_delete_def_file", "dir");
    return -1;
  }

  if (trace_flag) {
    trace_fp = guestfs___trace_open (g);
    fprintf (trace_fp, "%s", "acl_delete_def_file");
    fprintf (trace_fp, " \"%s\"", dir);
    guestfs___trace_send_line (g);
  }

  if (guestfs___check_appliance_up (g, "acl_delete_def_file") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "acl_delete_def_file", "-1");
    return -1;
  }

  args.dir = (char *) dir;
  serial = guestfs___send (g, GUESTFS_PROC_ACL_DELETE_DEF_FILE,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_acl_delete_def_file_args, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "acl_delete_def_file", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "acl_delete_def_file", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "acl_delete_def_file", "-1");
    return -1;
  }

  if (guestfs___check_reply_header (g, &hdr, GUESTFS_PROC_ACL_DELETE_DEF_FILE, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "acl_delete_def_file", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "acl_delete_def_file", "-1");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "acl_delete_def_file", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "acl_delete_def_file",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    trace_fp = guestfs___trace_open (g);
    fprintf (trace_fp, "%s = ", "acl_delete_def_file");
    fprintf (trace_fp, "%d", ret_v);
    guestfs___trace_send_line (g);
  }

  return ret_v;
}

GUESTFS_DLL_PUBLIC char *
guestfs_ldmtool_diskgroup_name (guestfs_h *g,
                                const char *diskgroup)
{
  struct guestfs_ldmtool_diskgroup_name_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  struct guestfs_ldmtool_diskgroup_name_ret ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  char *ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "ldmtool_diskgroup_name", 22);
  if (diskgroup == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "ldmtool_diskgroup_name", "diskgroup");
    return NULL;
  }

  if (trace_flag) {
    trace_fp = guestfs___trace_open (g);
    fprintf (trace_fp, "%s", "ldmtool_diskgroup_name");
    fprintf (trace_fp, " \"%s\"", diskgroup);
    guestfs___trace_send_line (g);
  }

  if (guestfs___check_appliance_up (g, "ldmtool_diskgroup_name") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "ldmtool_diskgroup_name", "NULL");
    return NULL;
  }

  args.diskgroup = (char *) diskgroup;
  serial = guestfs___send (g, GUESTFS_PROC_LDMTOOL_DISKGROUP_NAME,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_ldmtool_diskgroup_name_args, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "ldmtool_diskgroup_name", "NULL");
    return NULL;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs___recv (g, "ldmtool_diskgroup_name", &hdr, &err,
        (xdrproc_t) xdr_guestfs_ldmtool_diskgroup_name_ret, (char *) &ret);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "ldmtool_diskgroup_name", "NULL");
    return NULL;
  }

  if (guestfs___check_reply_header (g, &hdr, GUESTFS_PROC_LDMTOOL_DISKGROUP_NAME, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "ldmtool_diskgroup_name", "NULL");
    return NULL;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "ldmtool_diskgroup_name", "NULL");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "ldmtool_diskgroup_name", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "ldmtool_diskgroup_name",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    return NULL;
  }

  ret_v = ret.name; /* caller will free */
  if (trace_flag) {
    trace_fp = guestfs___trace_open (g);
    fprintf (trace_fp, "%s = ", "ldmtool_diskgroup_name");
    fprintf (trace_fp, "\"%s\"", ret_v);
    guestfs___trace_send_line (g);
  }

  return ret_v;
}

GUESTFS_DLL_PUBLIC char **
guestfs_ldmtool_diskgroup_volumes (guestfs_h *g,
                                   const char *diskgroup)
{
  struct guestfs_ldmtool_diskgroup_volumes_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  struct guestfs_ldmtool_diskgroup_volumes_ret ret;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  char **ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "ldmtool_diskgroup_volumes", 25);
  if (diskgroup == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "ldmtool_diskgroup_volumes", "diskgroup");
    return NULL;
  }

  if (trace_flag) {
    trace_fp = guestfs___trace_open (g);
    fprintf (trace_fp, "%s", "ldmtool_diskgroup_volumes");
    fprintf (trace_fp, " \"%s\"", diskgroup);
    guestfs___trace_send_line (g);
  }

  if (guestfs___check_appliance_up (g, "ldmtool_diskgroup_volumes") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "ldmtool_diskgroup_volumes", "NULL");
    return NULL;
  }

  args.diskgroup = (char *) diskgroup;
  serial = guestfs___send (g, GUESTFS_PROC_LDMTOOL_DISKGROUP_VOLUMES,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_ldmtool_diskgroup_volumes_args, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "ldmtool_diskgroup_volumes", "NULL");
    return NULL;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);
  memset (&ret, 0, sizeof ret);

  r = guestfs___recv (g, "ldmtool_diskgroup_volumes", &hdr, &err,
        (xdrproc_t) xdr_guestfs_ldmtool_diskgroup_volumes_ret, (char *) &ret);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "ldmtool_diskgroup_volumes", "NULL");
    return NULL;
  }

  if (guestfs___check_reply_header (g, &hdr, GUESTFS_PROC_LDMTOOL_DISKGROUP_VOLUMES, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "ldmtool_diskgroup_volumes", "NULL");
    return NULL;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "ldmtool_diskgroup_volumes", "NULL");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "ldmtool_diskgroup_volumes", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "ldmtool_diskgroup_volumes",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    return NULL;
  }

  /* caller will free this, but we need to add a NULL entry */
  ret.volumes.volumes_val =
    safe_realloc (g, ret.volumes.volumes_val,
                  sizeof (char *) * (ret.volumes.volumes_len + 1));
  ret.volumes.volumes_val[ret.volumes.volumes_len] = NULL;
  ret_v = ret.volumes.volumes_val;
  if (trace_flag) {
    size_t i;

    trace_fp = guestfs___trace_open (g);
    fprintf (trace_fp, "%s = ", "ldmtool_diskgroup_volumes");
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
guestfs_rename (guestfs_h *g,
                const char *oldpath,
                const char *newpath)
{
  struct guestfs_rename_args args;
  guestfs_message_header hdr;
  guestfs_message_error err;
  int serial;
  int r;
  int trace_flag = g->trace;
  FILE *trace_fp;
  int ret_v;
  const uint64_t progress_hint = 0;

  guestfs___call_callbacks_message (g, GUESTFS_EVENT_ENTER,
                                    "rename", 6);
  if (oldpath == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "rename", "oldpath");
    return -1;
  }
  if (newpath == NULL) {
    error (g, "%s: %s: parameter cannot be NULL",
           "rename", "newpath");
    return -1;
  }

  if (trace_flag) {
    trace_fp = guestfs___trace_open (g);
    fprintf (trace_fp, "%s", "rename");
    fprintf (trace_fp, " \"%s\"", oldpath);
    fprintf (trace_fp, " \"%s\"", newpath);
    guestfs___trace_send_line (g);
  }

  if (guestfs___check_appliance_up (g, "rename") == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "rename", "-1");
    return -1;
  }

  args.oldpath = (char *) oldpath;
  args.newpath = (char *) newpath;
  serial = guestfs___send (g, GUESTFS_PROC_RENAME,
                           progress_hint, 0,
                           (xdrproc_t) xdr_guestfs_rename_args, (char *) &args);
  if (serial == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "rename", "-1");
    return -1;
  }

  memset (&hdr, 0, sizeof hdr);
  memset (&err, 0, sizeof err);

  r = guestfs___recv (g, "rename", &hdr, &err,
        NULL, NULL);
  if (r == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "rename", "-1");
    return -1;
  }

  if (guestfs___check_reply_header (g, &hdr, GUESTFS_PROC_RENAME, serial) == -1) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "rename", "-1");
    return -1;
  }

  if (hdr.status == GUESTFS_STATUS_ERROR) {
    if (trace_flag)
      guestfs___trace (g, "%s = %s (error)",
                       "rename", "-1");
    int errnum = 0;
    if (err.errno_string[0] != '\0')
      errnum = guestfs___string_to_errno (err.errno_string);
    if (errnum <= 0)
      error (g, "%s: %s", "rename", err.error_message);
    else
      guestfs_error_errno (g, errnum, "%s: %s", "rename",
                           err.error_message);
    free (err.error_message);
    free (err.errno_string);
    return -1;
  }

  ret_v = 0;
  if (trace_flag) {
    trace_fp = guestfs___trace_open (g);
    fprintf (trace_fp, "%s = ", "rename");
    fprintf (trace_fp, "%d", ret_v);
    guestfs___trace_send_line (g);
  }

  return ret_v;
}

