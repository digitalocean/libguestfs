/* libguestfs generated file
 * WARNING: THIS FILE IS GENERATED FROM:
 *   src/generator.ml
 * ANY CHANGES YOU MAKE TO THIS FILE WILL BE LOST.
 *
 * Copyright (C) 2009-2010 Red Hat Inc.
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

#include "EXTERN.h"
#include "perl.h"
#include "XSUB.h"

#include <guestfs.h>

#ifndef PRId64
#define PRId64 "lld"
#endif

static SV *
my_newSVll(long long val) {
#ifdef USE_64_BIT_ALL
  return newSViv(val);
#else
  char buf[100];
  int len;
  len = snprintf(buf, 100, "%" PRId64, val);
  return newSVpv(buf, len);
#endif
}

#ifndef PRIu64
#define PRIu64 "llu"
#endif

static SV *
my_newSVull(unsigned long long val) {
#ifdef USE_64_BIT_ALL
  return newSVuv(val);
#else
  char buf[100];
  int len;
  len = snprintf(buf, 100, "%" PRIu64, val);
  return newSVpv(buf, len);
#endif
}

/* http://www.perlmonks.org/?node_id=680842 */
static char **
XS_unpack_charPtrPtr (SV *arg) {
  char **ret;
  AV *av;
  I32 i;

  if (!arg || !SvOK (arg) || !SvROK (arg) || SvTYPE (SvRV (arg)) != SVt_PVAV)
    croak ("array reference expected");

  av = (AV *)SvRV (arg);
  ret = malloc ((av_len (av) + 1 + 1) * sizeof (char *));
  if (!ret)
    croak ("malloc failed");

  for (i = 0; i <= av_len (av); i++) {
    SV **elem = av_fetch (av, i, 0);

    if (!elem || !*elem)
      croak ("missing element in list");

    ret[i] = SvPV_nolen (*elem);
  }

  ret[i] = NULL;

  return ret;
}

MODULE = Sys::Guestfs  PACKAGE = Sys::Guestfs

PROTOTYPES: ENABLE

guestfs_h *
_create ()
   CODE:
      RETVAL = guestfs_create ();
      if (!RETVAL)
        croak ("could not create guestfs handle");
      guestfs_set_error_handler (RETVAL, NULL, NULL);
 OUTPUT:
      RETVAL

void
DESTROY (g)
      guestfs_h *g;
 PPCODE:
      guestfs_close (g);

void
test0 (g, str, optstr, strlist, b, integer, integer64, filein, fileout)
      guestfs_h *g;
      char *str;
      char *optstr = SvOK(ST(2)) ? SvPV_nolen(ST(2)) : NULL;
      char **strlist;
      int b;
      int integer;
      int64_t integer64;
      char *filein;
      char *fileout;
PREINIT:
      int r;
 PPCODE:
      r = guestfs_test0 (g, str, optstr, strlist, b, integer, integer64, filein, fileout);
      free (strlist);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

SV *
test0rint (g, val)
      guestfs_h *g;
      char *val;
PREINIT:
      int valout;
   CODE:
      valout = guestfs_test0rint (g, val);
      if (valout == -1)
        croak ("%s", guestfs_last_error (g));
      RETVAL = newSViv (valout);
 OUTPUT:
      RETVAL

SV *
test0rinterr (g)
      guestfs_h *g;
PREINIT:
      int valout;
   CODE:
      valout = guestfs_test0rinterr (g);
      if (valout == -1)
        croak ("%s", guestfs_last_error (g));
      RETVAL = newSViv (valout);
 OUTPUT:
      RETVAL

SV *
test0rint64 (g, val)
      guestfs_h *g;
      char *val;
PREINIT:
      int64_t valout;
   CODE:
      valout = guestfs_test0rint64 (g, val);
      if (valout == -1)
        croak ("%s", guestfs_last_error (g));
      RETVAL = my_newSVll (valout);
 OUTPUT:
      RETVAL

SV *
test0rint64err (g)
      guestfs_h *g;
PREINIT:
      int64_t valout;
   CODE:
      valout = guestfs_test0rint64err (g);
      if (valout == -1)
        croak ("%s", guestfs_last_error (g));
      RETVAL = my_newSVll (valout);
 OUTPUT:
      RETVAL

SV *
test0rbool (g, val)
      guestfs_h *g;
      char *val;
PREINIT:
      int valout;
   CODE:
      valout = guestfs_test0rbool (g, val);
      if (valout == -1)
        croak ("%s", guestfs_last_error (g));
      RETVAL = newSViv (valout);
 OUTPUT:
      RETVAL

SV *
test0rboolerr (g)
      guestfs_h *g;
PREINIT:
      int valout;
   CODE:
      valout = guestfs_test0rboolerr (g);
      if (valout == -1)
        croak ("%s", guestfs_last_error (g));
      RETVAL = newSViv (valout);
 OUTPUT:
      RETVAL

SV *
test0rconststring (g, val)
      guestfs_h *g;
      char *val;
PREINIT:
      const char *valout;
   CODE:
      valout = guestfs_test0rconststring (g, val);
      if (valout == NULL)
        croak ("%s", guestfs_last_error (g));
      RETVAL = newSVpv (valout, 0);
 OUTPUT:
      RETVAL

SV *
test0rconststringerr (g)
      guestfs_h *g;
PREINIT:
      const char *valout;
   CODE:
      valout = guestfs_test0rconststringerr (g);
      if (valout == NULL)
        croak ("%s", guestfs_last_error (g));
      RETVAL = newSVpv (valout, 0);
 OUTPUT:
      RETVAL

SV *
test0rconstoptstring (g, val)
      guestfs_h *g;
      char *val;
PREINIT:
      const char *valout;
   CODE:
      valout = guestfs_test0rconstoptstring (g, val);
      if (valout == NULL)
        RETVAL = &PL_sv_undef;
      else
        RETVAL = newSVpv (valout, 0);
 OUTPUT:
      RETVAL

SV *
test0rconstoptstringerr (g)
      guestfs_h *g;
PREINIT:
      const char *valout;
   CODE:
      valout = guestfs_test0rconstoptstringerr (g);
      if (valout == NULL)
        RETVAL = &PL_sv_undef;
      else
        RETVAL = newSVpv (valout, 0);
 OUTPUT:
      RETVAL

SV *
test0rstring (g, val)
      guestfs_h *g;
      char *val;
PREINIT:
      char *valout;
   CODE:
      valout = guestfs_test0rstring (g, val);
      if (valout == NULL)
        croak ("%s", guestfs_last_error (g));
      RETVAL = newSVpv (valout, 0);
      free (valout);
 OUTPUT:
      RETVAL

SV *
test0rstringerr (g)
      guestfs_h *g;
PREINIT:
      char *valout;
   CODE:
      valout = guestfs_test0rstringerr (g);
      if (valout == NULL)
        croak ("%s", guestfs_last_error (g));
      RETVAL = newSVpv (valout, 0);
      free (valout);
 OUTPUT:
      RETVAL

void
test0rstringlist (g, val)
      guestfs_h *g;
      char *val;
PREINIT:
      char **valout;
      int i, n;
 PPCODE:
      valout = guestfs_test0rstringlist (g, val);
      if (valout == NULL)
        croak ("%s", guestfs_last_error (g));
      for (n = 0; valout[n] != NULL; ++n) /**/;
      EXTEND (SP, n);
      for (i = 0; i < n; ++i) {
        PUSHs (sv_2mortal (newSVpv (valout[i], 0)));
        free (valout[i]);
      }
      free (valout);

void
test0rstringlisterr (g)
      guestfs_h *g;
PREINIT:
      char **valout;
      int i, n;
 PPCODE:
      valout = guestfs_test0rstringlisterr (g);
      if (valout == NULL)
        croak ("%s", guestfs_last_error (g));
      for (n = 0; valout[n] != NULL; ++n) /**/;
      EXTEND (SP, n);
      for (i = 0; i < n; ++i) {
        PUSHs (sv_2mortal (newSVpv (valout[i], 0)));
        free (valout[i]);
      }
      free (valout);

void
test0rstruct (g, val)
      guestfs_h *g;
      char *val;
PREINIT:
      struct guestfs_lvm_pv *valout;
 PPCODE:
      valout = guestfs_test0rstruct (g, val);
      if (valout == NULL)
        croak ("%s", guestfs_last_error (g));
      EXTEND (SP, 2 * 14);
      PUSHs (sv_2mortal (newSVpv ("pv_name", 0)));
      PUSHs (sv_2mortal (newSVpv (valout->pv_name, 0)));
      PUSHs (sv_2mortal (newSVpv ("pv_uuid", 0)));
      PUSHs (sv_2mortal (newSVpv (valout->pv_uuid, 32)));
      PUSHs (sv_2mortal (newSVpv ("pv_fmt", 0)));
      PUSHs (sv_2mortal (newSVpv (valout->pv_fmt, 0)));
      PUSHs (sv_2mortal (newSVpv ("pv_size", 0)));
      PUSHs (sv_2mortal (my_newSVull (valout->pv_size)));
      PUSHs (sv_2mortal (newSVpv ("dev_size", 0)));
      PUSHs (sv_2mortal (my_newSVull (valout->dev_size)));
      PUSHs (sv_2mortal (newSVpv ("pv_free", 0)));
      PUSHs (sv_2mortal (my_newSVull (valout->pv_free)));
      PUSHs (sv_2mortal (newSVpv ("pv_used", 0)));
      PUSHs (sv_2mortal (my_newSVull (valout->pv_used)));
      PUSHs (sv_2mortal (newSVpv ("pv_attr", 0)));
      PUSHs (sv_2mortal (newSVpv (valout->pv_attr, 0)));
      PUSHs (sv_2mortal (newSVpv ("pv_pe_count", 0)));
      PUSHs (sv_2mortal (my_newSVll (valout->pv_pe_count)));
      PUSHs (sv_2mortal (newSVpv ("pv_pe_alloc_count", 0)));
      PUSHs (sv_2mortal (my_newSVll (valout->pv_pe_alloc_count)));
      PUSHs (sv_2mortal (newSVpv ("pv_tags", 0)));
      PUSHs (sv_2mortal (newSVpv (valout->pv_tags, 0)));
      PUSHs (sv_2mortal (newSVpv ("pe_start", 0)));
      PUSHs (sv_2mortal (my_newSVull (valout->pe_start)));
      PUSHs (sv_2mortal (newSVpv ("pv_mda_count", 0)));
      PUSHs (sv_2mortal (my_newSVll (valout->pv_mda_count)));
      PUSHs (sv_2mortal (newSVpv ("pv_mda_free", 0)));
      PUSHs (sv_2mortal (my_newSVull (valout->pv_mda_free)));
      free (valout);

void
test0rstructerr (g)
      guestfs_h *g;
PREINIT:
      struct guestfs_lvm_pv *valout;
 PPCODE:
      valout = guestfs_test0rstructerr (g);
      if (valout == NULL)
        croak ("%s", guestfs_last_error (g));
      EXTEND (SP, 2 * 14);
      PUSHs (sv_2mortal (newSVpv ("pv_name", 0)));
      PUSHs (sv_2mortal (newSVpv (valout->pv_name, 0)));
      PUSHs (sv_2mortal (newSVpv ("pv_uuid", 0)));
      PUSHs (sv_2mortal (newSVpv (valout->pv_uuid, 32)));
      PUSHs (sv_2mortal (newSVpv ("pv_fmt", 0)));
      PUSHs (sv_2mortal (newSVpv (valout->pv_fmt, 0)));
      PUSHs (sv_2mortal (newSVpv ("pv_size", 0)));
      PUSHs (sv_2mortal (my_newSVull (valout->pv_size)));
      PUSHs (sv_2mortal (newSVpv ("dev_size", 0)));
      PUSHs (sv_2mortal (my_newSVull (valout->dev_size)));
      PUSHs (sv_2mortal (newSVpv ("pv_free", 0)));
      PUSHs (sv_2mortal (my_newSVull (valout->pv_free)));
      PUSHs (sv_2mortal (newSVpv ("pv_used", 0)));
      PUSHs (sv_2mortal (my_newSVull (valout->pv_used)));
      PUSHs (sv_2mortal (newSVpv ("pv_attr", 0)));
      PUSHs (sv_2mortal (newSVpv (valout->pv_attr, 0)));
      PUSHs (sv_2mortal (newSVpv ("pv_pe_count", 0)));
      PUSHs (sv_2mortal (my_newSVll (valout->pv_pe_count)));
      PUSHs (sv_2mortal (newSVpv ("pv_pe_alloc_count", 0)));
      PUSHs (sv_2mortal (my_newSVll (valout->pv_pe_alloc_count)));
      PUSHs (sv_2mortal (newSVpv ("pv_tags", 0)));
      PUSHs (sv_2mortal (newSVpv (valout->pv_tags, 0)));
      PUSHs (sv_2mortal (newSVpv ("pe_start", 0)));
      PUSHs (sv_2mortal (my_newSVull (valout->pe_start)));
      PUSHs (sv_2mortal (newSVpv ("pv_mda_count", 0)));
      PUSHs (sv_2mortal (my_newSVll (valout->pv_mda_count)));
      PUSHs (sv_2mortal (newSVpv ("pv_mda_free", 0)));
      PUSHs (sv_2mortal (my_newSVull (valout->pv_mda_free)));
      free (valout);

void
test0rstructlist (g, val)
      guestfs_h *g;
      char *val;
PREINIT:
      struct guestfs_lvm_pv_list *valout;
      int i;
      HV *hv;
 PPCODE:
      valout = guestfs_test0rstructlist (g, val);
      if (valout == NULL)
        croak ("%s", guestfs_last_error (g));
      EXTEND (SP, valout->len);
      for (i = 0; i < valout->len; ++i) {
        hv = newHV ();
        (void) hv_store (hv, "pv_name", 7, newSVpv (valout->val[i].pv_name, 0), 0);
        (void) hv_store (hv, "pv_uuid", 7, newSVpv (valout->val[i].pv_uuid, 32), 0);
        (void) hv_store (hv, "pv_fmt", 6, newSVpv (valout->val[i].pv_fmt, 0), 0);
        (void) hv_store (hv, "pv_size", 7, my_newSVull (valout->val[i].pv_size), 0);
        (void) hv_store (hv, "dev_size", 8, my_newSVull (valout->val[i].dev_size), 0);
        (void) hv_store (hv, "pv_free", 7, my_newSVull (valout->val[i].pv_free), 0);
        (void) hv_store (hv, "pv_used", 7, my_newSVull (valout->val[i].pv_used), 0);
        (void) hv_store (hv, "pv_attr", 7, newSVpv (valout->val[i].pv_attr, 0), 0);
        (void) hv_store (hv, "pv_pe_count", 11, my_newSVll (valout->val[i].pv_pe_count), 0);
        (void) hv_store (hv, "pv_pe_alloc_count", 17, my_newSVll (valout->val[i].pv_pe_alloc_count), 0);
        (void) hv_store (hv, "pv_tags", 7, newSVpv (valout->val[i].pv_tags, 0), 0);
        (void) hv_store (hv, "pe_start", 8, my_newSVull (valout->val[i].pe_start), 0);
        (void) hv_store (hv, "pv_mda_count", 12, my_newSVll (valout->val[i].pv_mda_count), 0);
        (void) hv_store (hv, "pv_mda_free", 11, my_newSVull (valout->val[i].pv_mda_free), 0);
        PUSHs (sv_2mortal (newRV ((SV *) hv)));
      }
      guestfs_free_lvm_pv_list (valout);

void
test0rstructlisterr (g)
      guestfs_h *g;
PREINIT:
      struct guestfs_lvm_pv_list *valout;
      int i;
      HV *hv;
 PPCODE:
      valout = guestfs_test0rstructlisterr (g);
      if (valout == NULL)
        croak ("%s", guestfs_last_error (g));
      EXTEND (SP, valout->len);
      for (i = 0; i < valout->len; ++i) {
        hv = newHV ();
        (void) hv_store (hv, "pv_name", 7, newSVpv (valout->val[i].pv_name, 0), 0);
        (void) hv_store (hv, "pv_uuid", 7, newSVpv (valout->val[i].pv_uuid, 32), 0);
        (void) hv_store (hv, "pv_fmt", 6, newSVpv (valout->val[i].pv_fmt, 0), 0);
        (void) hv_store (hv, "pv_size", 7, my_newSVull (valout->val[i].pv_size), 0);
        (void) hv_store (hv, "dev_size", 8, my_newSVull (valout->val[i].dev_size), 0);
        (void) hv_store (hv, "pv_free", 7, my_newSVull (valout->val[i].pv_free), 0);
        (void) hv_store (hv, "pv_used", 7, my_newSVull (valout->val[i].pv_used), 0);
        (void) hv_store (hv, "pv_attr", 7, newSVpv (valout->val[i].pv_attr, 0), 0);
        (void) hv_store (hv, "pv_pe_count", 11, my_newSVll (valout->val[i].pv_pe_count), 0);
        (void) hv_store (hv, "pv_pe_alloc_count", 17, my_newSVll (valout->val[i].pv_pe_alloc_count), 0);
        (void) hv_store (hv, "pv_tags", 7, newSVpv (valout->val[i].pv_tags, 0), 0);
        (void) hv_store (hv, "pe_start", 8, my_newSVull (valout->val[i].pe_start), 0);
        (void) hv_store (hv, "pv_mda_count", 12, my_newSVll (valout->val[i].pv_mda_count), 0);
        (void) hv_store (hv, "pv_mda_free", 11, my_newSVull (valout->val[i].pv_mda_free), 0);
        PUSHs (sv_2mortal (newRV ((SV *) hv)));
      }
      guestfs_free_lvm_pv_list (valout);

void
test0rhashtable (g, val)
      guestfs_h *g;
      char *val;
PREINIT:
      char **valout;
      int i, n;
 PPCODE:
      valout = guestfs_test0rhashtable (g, val);
      if (valout == NULL)
        croak ("%s", guestfs_last_error (g));
      for (n = 0; valout[n] != NULL; ++n) /**/;
      EXTEND (SP, n);
      for (i = 0; i < n; ++i) {
        PUSHs (sv_2mortal (newSVpv (valout[i], 0)));
        free (valout[i]);
      }
      free (valout);

void
test0rhashtableerr (g)
      guestfs_h *g;
PREINIT:
      char **valout;
      int i, n;
 PPCODE:
      valout = guestfs_test0rhashtableerr (g);
      if (valout == NULL)
        croak ("%s", guestfs_last_error (g));
      for (n = 0; valout[n] != NULL; ++n) /**/;
      EXTEND (SP, n);
      for (i = 0; i < n; ++i) {
        PUSHs (sv_2mortal (newSVpv (valout[i], 0)));
        free (valout[i]);
      }
      free (valout);

void
launch (g)
      guestfs_h *g;
PREINIT:
      int r;
 PPCODE:
      r = guestfs_launch (g);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

void
wait_ready (g)
      guestfs_h *g;
PREINIT:
      int r;
 PPCODE:
      r = guestfs_wait_ready (g);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

void
kill_subprocess (g)
      guestfs_h *g;
PREINIT:
      int r;
 PPCODE:
      r = guestfs_kill_subprocess (g);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

void
add_drive (g, filename)
      guestfs_h *g;
      char *filename;
PREINIT:
      int r;
 PPCODE:
      r = guestfs_add_drive (g, filename);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

void
add_cdrom (g, filename)
      guestfs_h *g;
      char *filename;
PREINIT:
      int r;
 PPCODE:
      r = guestfs_add_cdrom (g, filename);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

void
add_drive_ro (g, filename)
      guestfs_h *g;
      char *filename;
PREINIT:
      int r;
 PPCODE:
      r = guestfs_add_drive_ro (g, filename);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

void
config (g, qemuparam, qemuvalue)
      guestfs_h *g;
      char *qemuparam;
      char *qemuvalue = SvOK(ST(2)) ? SvPV_nolen(ST(2)) : NULL;
PREINIT:
      int r;
 PPCODE:
      r = guestfs_config (g, qemuparam, qemuvalue);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

void
set_qemu (g, qemu)
      guestfs_h *g;
      char *qemu;
PREINIT:
      int r;
 PPCODE:
      r = guestfs_set_qemu (g, qemu);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

SV *
get_qemu (g)
      guestfs_h *g;
PREINIT:
      const char *qemu;
   CODE:
      qemu = guestfs_get_qemu (g);
      if (qemu == NULL)
        croak ("%s", guestfs_last_error (g));
      RETVAL = newSVpv (qemu, 0);
 OUTPUT:
      RETVAL

void
set_path (g, searchpath)
      guestfs_h *g;
      char *searchpath;
PREINIT:
      int r;
 PPCODE:
      r = guestfs_set_path (g, searchpath);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

SV *
get_path (g)
      guestfs_h *g;
PREINIT:
      const char *path;
   CODE:
      path = guestfs_get_path (g);
      if (path == NULL)
        croak ("%s", guestfs_last_error (g));
      RETVAL = newSVpv (path, 0);
 OUTPUT:
      RETVAL

void
set_append (g, append)
      guestfs_h *g;
      char *append = SvOK(ST(1)) ? SvPV_nolen(ST(1)) : NULL;
PREINIT:
      int r;
 PPCODE:
      r = guestfs_set_append (g, append);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

SV *
get_append (g)
      guestfs_h *g;
PREINIT:
      const char *append;
   CODE:
      append = guestfs_get_append (g);
      if (append == NULL)
        RETVAL = &PL_sv_undef;
      else
        RETVAL = newSVpv (append, 0);
 OUTPUT:
      RETVAL

void
set_autosync (g, autosync)
      guestfs_h *g;
      int autosync;
PREINIT:
      int r;
 PPCODE:
      r = guestfs_set_autosync (g, autosync);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

SV *
get_autosync (g)
      guestfs_h *g;
PREINIT:
      int autosync;
   CODE:
      autosync = guestfs_get_autosync (g);
      if (autosync == -1)
        croak ("%s", guestfs_last_error (g));
      RETVAL = newSViv (autosync);
 OUTPUT:
      RETVAL

void
set_verbose (g, verbose)
      guestfs_h *g;
      int verbose;
PREINIT:
      int r;
 PPCODE:
      r = guestfs_set_verbose (g, verbose);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

SV *
get_verbose (g)
      guestfs_h *g;
PREINIT:
      int verbose;
   CODE:
      verbose = guestfs_get_verbose (g);
      if (verbose == -1)
        croak ("%s", guestfs_last_error (g));
      RETVAL = newSViv (verbose);
 OUTPUT:
      RETVAL

SV *
is_ready (g)
      guestfs_h *g;
PREINIT:
      int ready;
   CODE:
      ready = guestfs_is_ready (g);
      if (ready == -1)
        croak ("%s", guestfs_last_error (g));
      RETVAL = newSViv (ready);
 OUTPUT:
      RETVAL

SV *
is_config (g)
      guestfs_h *g;
PREINIT:
      int config;
   CODE:
      config = guestfs_is_config (g);
      if (config == -1)
        croak ("%s", guestfs_last_error (g));
      RETVAL = newSViv (config);
 OUTPUT:
      RETVAL

SV *
is_launching (g)
      guestfs_h *g;
PREINIT:
      int launching;
   CODE:
      launching = guestfs_is_launching (g);
      if (launching == -1)
        croak ("%s", guestfs_last_error (g));
      RETVAL = newSViv (launching);
 OUTPUT:
      RETVAL

SV *
is_busy (g)
      guestfs_h *g;
PREINIT:
      int busy;
   CODE:
      busy = guestfs_is_busy (g);
      if (busy == -1)
        croak ("%s", guestfs_last_error (g));
      RETVAL = newSViv (busy);
 OUTPUT:
      RETVAL

SV *
get_state (g)
      guestfs_h *g;
PREINIT:
      int state;
   CODE:
      state = guestfs_get_state (g);
      if (state == -1)
        croak ("%s", guestfs_last_error (g));
      RETVAL = newSViv (state);
 OUTPUT:
      RETVAL

void
set_memsize (g, memsize)
      guestfs_h *g;
      int memsize;
PREINIT:
      int r;
 PPCODE:
      r = guestfs_set_memsize (g, memsize);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

SV *
get_memsize (g)
      guestfs_h *g;
PREINIT:
      int memsize;
   CODE:
      memsize = guestfs_get_memsize (g);
      if (memsize == -1)
        croak ("%s", guestfs_last_error (g));
      RETVAL = newSViv (memsize);
 OUTPUT:
      RETVAL

SV *
get_pid (g)
      guestfs_h *g;
PREINIT:
      int pid;
   CODE:
      pid = guestfs_get_pid (g);
      if (pid == -1)
        croak ("%s", guestfs_last_error (g));
      RETVAL = newSViv (pid);
 OUTPUT:
      RETVAL

void
version (g)
      guestfs_h *g;
PREINIT:
      struct guestfs_version *version;
 PPCODE:
      version = guestfs_version (g);
      if (version == NULL)
        croak ("%s", guestfs_last_error (g));
      EXTEND (SP, 2 * 4);
      PUSHs (sv_2mortal (newSVpv ("major", 0)));
      PUSHs (sv_2mortal (my_newSVll (version->major)));
      PUSHs (sv_2mortal (newSVpv ("minor", 0)));
      PUSHs (sv_2mortal (my_newSVll (version->minor)));
      PUSHs (sv_2mortal (newSVpv ("release", 0)));
      PUSHs (sv_2mortal (my_newSVll (version->release)));
      PUSHs (sv_2mortal (newSVpv ("extra", 0)));
      PUSHs (sv_2mortal (newSVpv (version->extra, 0)));
      free (version);

void
set_selinux (g, selinux)
      guestfs_h *g;
      int selinux;
PREINIT:
      int r;
 PPCODE:
      r = guestfs_set_selinux (g, selinux);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

SV *
get_selinux (g)
      guestfs_h *g;
PREINIT:
      int selinux;
   CODE:
      selinux = guestfs_get_selinux (g);
      if (selinux == -1)
        croak ("%s", guestfs_last_error (g));
      RETVAL = newSViv (selinux);
 OUTPUT:
      RETVAL

void
set_trace (g, trace)
      guestfs_h *g;
      int trace;
PREINIT:
      int r;
 PPCODE:
      r = guestfs_set_trace (g, trace);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

SV *
get_trace (g)
      guestfs_h *g;
PREINIT:
      int trace;
   CODE:
      trace = guestfs_get_trace (g);
      if (trace == -1)
        croak ("%s", guestfs_last_error (g));
      RETVAL = newSViv (trace);
 OUTPUT:
      RETVAL

void
set_direct (g, direct)
      guestfs_h *g;
      int direct;
PREINIT:
      int r;
 PPCODE:
      r = guestfs_set_direct (g, direct);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

SV *
get_direct (g)
      guestfs_h *g;
PREINIT:
      int direct;
   CODE:
      direct = guestfs_get_direct (g);
      if (direct == -1)
        croak ("%s", guestfs_last_error (g));
      RETVAL = newSViv (direct);
 OUTPUT:
      RETVAL

void
set_recovery_proc (g, recoveryproc)
      guestfs_h *g;
      int recoveryproc;
PREINIT:
      int r;
 PPCODE:
      r = guestfs_set_recovery_proc (g, recoveryproc);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

SV *
get_recovery_proc (g)
      guestfs_h *g;
PREINIT:
      int recoveryproc;
   CODE:
      recoveryproc = guestfs_get_recovery_proc (g);
      if (recoveryproc == -1)
        croak ("%s", guestfs_last_error (g));
      RETVAL = newSViv (recoveryproc);
 OUTPUT:
      RETVAL

void
add_drive_with_if (g, filename, iface)
      guestfs_h *g;
      char *filename;
      char *iface;
PREINIT:
      int r;
 PPCODE:
      r = guestfs_add_drive_with_if (g, filename, iface);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

void
add_drive_ro_with_if (g, filename, iface)
      guestfs_h *g;
      char *filename;
      char *iface;
PREINIT:
      int r;
 PPCODE:
      r = guestfs_add_drive_ro_with_if (g, filename, iface);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

void
mount (g, device, mountpoint)
      guestfs_h *g;
      char *device;
      char *mountpoint;
PREINIT:
      int r;
 PPCODE:
      r = guestfs_mount (g, device, mountpoint);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

void
sync (g)
      guestfs_h *g;
PREINIT:
      int r;
 PPCODE:
      r = guestfs_sync (g);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

void
touch (g, path)
      guestfs_h *g;
      char *path;
PREINIT:
      int r;
 PPCODE:
      r = guestfs_touch (g, path);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

SV *
cat (g, path)
      guestfs_h *g;
      char *path;
PREINIT:
      char *content;
   CODE:
      content = guestfs_cat (g, path);
      if (content == NULL)
        croak ("%s", guestfs_last_error (g));
      RETVAL = newSVpv (content, 0);
      free (content);
 OUTPUT:
      RETVAL

SV *
ll (g, directory)
      guestfs_h *g;
      char *directory;
PREINIT:
      char *listing;
   CODE:
      listing = guestfs_ll (g, directory);
      if (listing == NULL)
        croak ("%s", guestfs_last_error (g));
      RETVAL = newSVpv (listing, 0);
      free (listing);
 OUTPUT:
      RETVAL

void
ls (g, directory)
      guestfs_h *g;
      char *directory;
PREINIT:
      char **listing;
      int i, n;
 PPCODE:
      listing = guestfs_ls (g, directory);
      if (listing == NULL)
        croak ("%s", guestfs_last_error (g));
      for (n = 0; listing[n] != NULL; ++n) /**/;
      EXTEND (SP, n);
      for (i = 0; i < n; ++i) {
        PUSHs (sv_2mortal (newSVpv (listing[i], 0)));
        free (listing[i]);
      }
      free (listing);

void
list_devices (g)
      guestfs_h *g;
PREINIT:
      char **devices;
      int i, n;
 PPCODE:
      devices = guestfs_list_devices (g);
      if (devices == NULL)
        croak ("%s", guestfs_last_error (g));
      for (n = 0; devices[n] != NULL; ++n) /**/;
      EXTEND (SP, n);
      for (i = 0; i < n; ++i) {
        PUSHs (sv_2mortal (newSVpv (devices[i], 0)));
        free (devices[i]);
      }
      free (devices);

void
list_partitions (g)
      guestfs_h *g;
PREINIT:
      char **partitions;
      int i, n;
 PPCODE:
      partitions = guestfs_list_partitions (g);
      if (partitions == NULL)
        croak ("%s", guestfs_last_error (g));
      for (n = 0; partitions[n] != NULL; ++n) /**/;
      EXTEND (SP, n);
      for (i = 0; i < n; ++i) {
        PUSHs (sv_2mortal (newSVpv (partitions[i], 0)));
        free (partitions[i]);
      }
      free (partitions);

void
pvs (g)
      guestfs_h *g;
PREINIT:
      char **physvols;
      int i, n;
 PPCODE:
      physvols = guestfs_pvs (g);
      if (physvols == NULL)
        croak ("%s", guestfs_last_error (g));
      for (n = 0; physvols[n] != NULL; ++n) /**/;
      EXTEND (SP, n);
      for (i = 0; i < n; ++i) {
        PUSHs (sv_2mortal (newSVpv (physvols[i], 0)));
        free (physvols[i]);
      }
      free (physvols);

void
vgs (g)
      guestfs_h *g;
PREINIT:
      char **volgroups;
      int i, n;
 PPCODE:
      volgroups = guestfs_vgs (g);
      if (volgroups == NULL)
        croak ("%s", guestfs_last_error (g));
      for (n = 0; volgroups[n] != NULL; ++n) /**/;
      EXTEND (SP, n);
      for (i = 0; i < n; ++i) {
        PUSHs (sv_2mortal (newSVpv (volgroups[i], 0)));
        free (volgroups[i]);
      }
      free (volgroups);

void
lvs (g)
      guestfs_h *g;
PREINIT:
      char **logvols;
      int i, n;
 PPCODE:
      logvols = guestfs_lvs (g);
      if (logvols == NULL)
        croak ("%s", guestfs_last_error (g));
      for (n = 0; logvols[n] != NULL; ++n) /**/;
      EXTEND (SP, n);
      for (i = 0; i < n; ++i) {
        PUSHs (sv_2mortal (newSVpv (logvols[i], 0)));
        free (logvols[i]);
      }
      free (logvols);

void
pvs_full (g)
      guestfs_h *g;
PREINIT:
      struct guestfs_lvm_pv_list *physvols;
      int i;
      HV *hv;
 PPCODE:
      physvols = guestfs_pvs_full (g);
      if (physvols == NULL)
        croak ("%s", guestfs_last_error (g));
      EXTEND (SP, physvols->len);
      for (i = 0; i < physvols->len; ++i) {
        hv = newHV ();
        (void) hv_store (hv, "pv_name", 7, newSVpv (physvols->val[i].pv_name, 0), 0);
        (void) hv_store (hv, "pv_uuid", 7, newSVpv (physvols->val[i].pv_uuid, 32), 0);
        (void) hv_store (hv, "pv_fmt", 6, newSVpv (physvols->val[i].pv_fmt, 0), 0);
        (void) hv_store (hv, "pv_size", 7, my_newSVull (physvols->val[i].pv_size), 0);
        (void) hv_store (hv, "dev_size", 8, my_newSVull (physvols->val[i].dev_size), 0);
        (void) hv_store (hv, "pv_free", 7, my_newSVull (physvols->val[i].pv_free), 0);
        (void) hv_store (hv, "pv_used", 7, my_newSVull (physvols->val[i].pv_used), 0);
        (void) hv_store (hv, "pv_attr", 7, newSVpv (physvols->val[i].pv_attr, 0), 0);
        (void) hv_store (hv, "pv_pe_count", 11, my_newSVll (physvols->val[i].pv_pe_count), 0);
        (void) hv_store (hv, "pv_pe_alloc_count", 17, my_newSVll (physvols->val[i].pv_pe_alloc_count), 0);
        (void) hv_store (hv, "pv_tags", 7, newSVpv (physvols->val[i].pv_tags, 0), 0);
        (void) hv_store (hv, "pe_start", 8, my_newSVull (physvols->val[i].pe_start), 0);
        (void) hv_store (hv, "pv_mda_count", 12, my_newSVll (physvols->val[i].pv_mda_count), 0);
        (void) hv_store (hv, "pv_mda_free", 11, my_newSVull (physvols->val[i].pv_mda_free), 0);
        PUSHs (sv_2mortal (newRV ((SV *) hv)));
      }
      guestfs_free_lvm_pv_list (physvols);

void
vgs_full (g)
      guestfs_h *g;
PREINIT:
      struct guestfs_lvm_vg_list *volgroups;
      int i;
      HV *hv;
 PPCODE:
      volgroups = guestfs_vgs_full (g);
      if (volgroups == NULL)
        croak ("%s", guestfs_last_error (g));
      EXTEND (SP, volgroups->len);
      for (i = 0; i < volgroups->len; ++i) {
        hv = newHV ();
        (void) hv_store (hv, "vg_name", 7, newSVpv (volgroups->val[i].vg_name, 0), 0);
        (void) hv_store (hv, "vg_uuid", 7, newSVpv (volgroups->val[i].vg_uuid, 32), 0);
        (void) hv_store (hv, "vg_fmt", 6, newSVpv (volgroups->val[i].vg_fmt, 0), 0);
        (void) hv_store (hv, "vg_attr", 7, newSVpv (volgroups->val[i].vg_attr, 0), 0);
        (void) hv_store (hv, "vg_size", 7, my_newSVull (volgroups->val[i].vg_size), 0);
        (void) hv_store (hv, "vg_free", 7, my_newSVull (volgroups->val[i].vg_free), 0);
        (void) hv_store (hv, "vg_sysid", 8, newSVpv (volgroups->val[i].vg_sysid, 0), 0);
        (void) hv_store (hv, "vg_extent_size", 14, my_newSVull (volgroups->val[i].vg_extent_size), 0);
        (void) hv_store (hv, "vg_extent_count", 15, my_newSVll (volgroups->val[i].vg_extent_count), 0);
        (void) hv_store (hv, "vg_free_count", 13, my_newSVll (volgroups->val[i].vg_free_count), 0);
        (void) hv_store (hv, "max_lv", 6, my_newSVll (volgroups->val[i].max_lv), 0);
        (void) hv_store (hv, "max_pv", 6, my_newSVll (volgroups->val[i].max_pv), 0);
        (void) hv_store (hv, "pv_count", 8, my_newSVll (volgroups->val[i].pv_count), 0);
        (void) hv_store (hv, "lv_count", 8, my_newSVll (volgroups->val[i].lv_count), 0);
        (void) hv_store (hv, "snap_count", 10, my_newSVll (volgroups->val[i].snap_count), 0);
        (void) hv_store (hv, "vg_seqno", 8, my_newSVll (volgroups->val[i].vg_seqno), 0);
        (void) hv_store (hv, "vg_tags", 7, newSVpv (volgroups->val[i].vg_tags, 0), 0);
        (void) hv_store (hv, "vg_mda_count", 12, my_newSVll (volgroups->val[i].vg_mda_count), 0);
        (void) hv_store (hv, "vg_mda_free", 11, my_newSVull (volgroups->val[i].vg_mda_free), 0);
        PUSHs (sv_2mortal (newRV ((SV *) hv)));
      }
      guestfs_free_lvm_vg_list (volgroups);

void
lvs_full (g)
      guestfs_h *g;
PREINIT:
      struct guestfs_lvm_lv_list *logvols;
      int i;
      HV *hv;
 PPCODE:
      logvols = guestfs_lvs_full (g);
      if (logvols == NULL)
        croak ("%s", guestfs_last_error (g));
      EXTEND (SP, logvols->len);
      for (i = 0; i < logvols->len; ++i) {
        hv = newHV ();
        (void) hv_store (hv, "lv_name", 7, newSVpv (logvols->val[i].lv_name, 0), 0);
        (void) hv_store (hv, "lv_uuid", 7, newSVpv (logvols->val[i].lv_uuid, 32), 0);
        (void) hv_store (hv, "lv_attr", 7, newSVpv (logvols->val[i].lv_attr, 0), 0);
        (void) hv_store (hv, "lv_major", 8, my_newSVll (logvols->val[i].lv_major), 0);
        (void) hv_store (hv, "lv_minor", 8, my_newSVll (logvols->val[i].lv_minor), 0);
        (void) hv_store (hv, "lv_kernel_major", 15, my_newSVll (logvols->val[i].lv_kernel_major), 0);
        (void) hv_store (hv, "lv_kernel_minor", 15, my_newSVll (logvols->val[i].lv_kernel_minor), 0);
        (void) hv_store (hv, "lv_size", 7, my_newSVull (logvols->val[i].lv_size), 0);
        (void) hv_store (hv, "seg_count", 9, my_newSVll (logvols->val[i].seg_count), 0);
        (void) hv_store (hv, "origin", 6, newSVpv (logvols->val[i].origin, 0), 0);
        (void) hv_store (hv, "snap_percent", 12, newSVnv (logvols->val[i].snap_percent), 0);
        (void) hv_store (hv, "copy_percent", 12, newSVnv (logvols->val[i].copy_percent), 0);
        (void) hv_store (hv, "move_pv", 7, newSVpv (logvols->val[i].move_pv, 0), 0);
        (void) hv_store (hv, "lv_tags", 7, newSVpv (logvols->val[i].lv_tags, 0), 0);
        (void) hv_store (hv, "mirror_log", 10, newSVpv (logvols->val[i].mirror_log, 0), 0);
        (void) hv_store (hv, "modules", 7, newSVpv (logvols->val[i].modules, 0), 0);
        PUSHs (sv_2mortal (newRV ((SV *) hv)));
      }
      guestfs_free_lvm_lv_list (logvols);

void
read_lines (g, path)
      guestfs_h *g;
      char *path;
PREINIT:
      char **lines;
      int i, n;
 PPCODE:
      lines = guestfs_read_lines (g, path);
      if (lines == NULL)
        croak ("%s", guestfs_last_error (g));
      for (n = 0; lines[n] != NULL; ++n) /**/;
      EXTEND (SP, n);
      for (i = 0; i < n; ++i) {
        PUSHs (sv_2mortal (newSVpv (lines[i], 0)));
        free (lines[i]);
      }
      free (lines);

void
aug_init (g, root, flags)
      guestfs_h *g;
      char *root;
      int flags;
PREINIT:
      int r;
 PPCODE:
      r = guestfs_aug_init (g, root, flags);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

void
aug_close (g)
      guestfs_h *g;
PREINIT:
      int r;
 PPCODE:
      r = guestfs_aug_close (g);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

SV *
aug_defvar (g, name, expr)
      guestfs_h *g;
      char *name;
      char *expr = SvOK(ST(2)) ? SvPV_nolen(ST(2)) : NULL;
PREINIT:
      int nrnodes;
   CODE:
      nrnodes = guestfs_aug_defvar (g, name, expr);
      if (nrnodes == -1)
        croak ("%s", guestfs_last_error (g));
      RETVAL = newSViv (nrnodes);
 OUTPUT:
      RETVAL

void
aug_defnode (g, name, expr, val)
      guestfs_h *g;
      char *name;
      char *expr;
      char *val;
PREINIT:
      struct guestfs_int_bool *nrnodescreated;
 PPCODE:
      nrnodescreated = guestfs_aug_defnode (g, name, expr, val);
      if (nrnodescreated == NULL)
        croak ("%s", guestfs_last_error (g));
      EXTEND (SP, 2 * 2);
      PUSHs (sv_2mortal (newSVpv ("i", 0)));
      PUSHs (sv_2mortal (newSVnv (nrnodescreated->i)));
      PUSHs (sv_2mortal (newSVpv ("b", 0)));
      PUSHs (sv_2mortal (newSVnv (nrnodescreated->b)));
      free (nrnodescreated);

SV *
aug_get (g, augpath)
      guestfs_h *g;
      char *augpath;
PREINIT:
      char *val;
   CODE:
      val = guestfs_aug_get (g, augpath);
      if (val == NULL)
        croak ("%s", guestfs_last_error (g));
      RETVAL = newSVpv (val, 0);
      free (val);
 OUTPUT:
      RETVAL

void
aug_set (g, augpath, val)
      guestfs_h *g;
      char *augpath;
      char *val;
PREINIT:
      int r;
 PPCODE:
      r = guestfs_aug_set (g, augpath, val);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

void
aug_insert (g, augpath, label, before)
      guestfs_h *g;
      char *augpath;
      char *label;
      int before;
PREINIT:
      int r;
 PPCODE:
      r = guestfs_aug_insert (g, augpath, label, before);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

SV *
aug_rm (g, augpath)
      guestfs_h *g;
      char *augpath;
PREINIT:
      int nrnodes;
   CODE:
      nrnodes = guestfs_aug_rm (g, augpath);
      if (nrnodes == -1)
        croak ("%s", guestfs_last_error (g));
      RETVAL = newSViv (nrnodes);
 OUTPUT:
      RETVAL

void
aug_mv (g, src, dest)
      guestfs_h *g;
      char *src;
      char *dest;
PREINIT:
      int r;
 PPCODE:
      r = guestfs_aug_mv (g, src, dest);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

void
aug_match (g, augpath)
      guestfs_h *g;
      char *augpath;
PREINIT:
      char **matches;
      int i, n;
 PPCODE:
      matches = guestfs_aug_match (g, augpath);
      if (matches == NULL)
        croak ("%s", guestfs_last_error (g));
      for (n = 0; matches[n] != NULL; ++n) /**/;
      EXTEND (SP, n);
      for (i = 0; i < n; ++i) {
        PUSHs (sv_2mortal (newSVpv (matches[i], 0)));
        free (matches[i]);
      }
      free (matches);

void
aug_save (g)
      guestfs_h *g;
PREINIT:
      int r;
 PPCODE:
      r = guestfs_aug_save (g);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

void
aug_load (g)
      guestfs_h *g;
PREINIT:
      int r;
 PPCODE:
      r = guestfs_aug_load (g);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

void
aug_ls (g, augpath)
      guestfs_h *g;
      char *augpath;
PREINIT:
      char **matches;
      int i, n;
 PPCODE:
      matches = guestfs_aug_ls (g, augpath);
      if (matches == NULL)
        croak ("%s", guestfs_last_error (g));
      for (n = 0; matches[n] != NULL; ++n) /**/;
      EXTEND (SP, n);
      for (i = 0; i < n; ++i) {
        PUSHs (sv_2mortal (newSVpv (matches[i], 0)));
        free (matches[i]);
      }
      free (matches);

void
rm (g, path)
      guestfs_h *g;
      char *path;
PREINIT:
      int r;
 PPCODE:
      r = guestfs_rm (g, path);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

void
rmdir (g, path)
      guestfs_h *g;
      char *path;
PREINIT:
      int r;
 PPCODE:
      r = guestfs_rmdir (g, path);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

void
rm_rf (g, path)
      guestfs_h *g;
      char *path;
PREINIT:
      int r;
 PPCODE:
      r = guestfs_rm_rf (g, path);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

void
mkdir (g, path)
      guestfs_h *g;
      char *path;
PREINIT:
      int r;
 PPCODE:
      r = guestfs_mkdir (g, path);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

void
mkdir_p (g, path)
      guestfs_h *g;
      char *path;
PREINIT:
      int r;
 PPCODE:
      r = guestfs_mkdir_p (g, path);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

void
chmod (g, mode, path)
      guestfs_h *g;
      int mode;
      char *path;
PREINIT:
      int r;
 PPCODE:
      r = guestfs_chmod (g, mode, path);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

void
chown (g, owner, group, path)
      guestfs_h *g;
      int owner;
      int group;
      char *path;
PREINIT:
      int r;
 PPCODE:
      r = guestfs_chown (g, owner, group, path);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

SV *
exists (g, path)
      guestfs_h *g;
      char *path;
PREINIT:
      int existsflag;
   CODE:
      existsflag = guestfs_exists (g, path);
      if (existsflag == -1)
        croak ("%s", guestfs_last_error (g));
      RETVAL = newSViv (existsflag);
 OUTPUT:
      RETVAL

SV *
is_file (g, path)
      guestfs_h *g;
      char *path;
PREINIT:
      int fileflag;
   CODE:
      fileflag = guestfs_is_file (g, path);
      if (fileflag == -1)
        croak ("%s", guestfs_last_error (g));
      RETVAL = newSViv (fileflag);
 OUTPUT:
      RETVAL

SV *
is_dir (g, path)
      guestfs_h *g;
      char *path;
PREINIT:
      int dirflag;
   CODE:
      dirflag = guestfs_is_dir (g, path);
      if (dirflag == -1)
        croak ("%s", guestfs_last_error (g));
      RETVAL = newSViv (dirflag);
 OUTPUT:
      RETVAL

void
pvcreate (g, device)
      guestfs_h *g;
      char *device;
PREINIT:
      int r;
 PPCODE:
      r = guestfs_pvcreate (g, device);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

void
vgcreate (g, volgroup, physvols)
      guestfs_h *g;
      char *volgroup;
      char **physvols;
PREINIT:
      int r;
 PPCODE:
      r = guestfs_vgcreate (g, volgroup, physvols);
      free (physvols);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

void
lvcreate (g, logvol, volgroup, mbytes)
      guestfs_h *g;
      char *logvol;
      char *volgroup;
      int mbytes;
PREINIT:
      int r;
 PPCODE:
      r = guestfs_lvcreate (g, logvol, volgroup, mbytes);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

void
mkfs (g, fstype, device)
      guestfs_h *g;
      char *fstype;
      char *device;
PREINIT:
      int r;
 PPCODE:
      r = guestfs_mkfs (g, fstype, device);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

void
sfdisk (g, device, cyls, heads, sectors, lines)
      guestfs_h *g;
      char *device;
      int cyls;
      int heads;
      int sectors;
      char **lines;
PREINIT:
      int r;
 PPCODE:
      r = guestfs_sfdisk (g, device, cyls, heads, sectors, lines);
      free (lines);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

void
write_file (g, path, content, size)
      guestfs_h *g;
      char *path;
      char *content;
      int size;
PREINIT:
      int r;
 PPCODE:
      r = guestfs_write_file (g, path, content, size);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

void
umount (g, pathordevice)
      guestfs_h *g;
      char *pathordevice;
PREINIT:
      int r;
 PPCODE:
      r = guestfs_umount (g, pathordevice);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

void
mounts (g)
      guestfs_h *g;
PREINIT:
      char **devices;
      int i, n;
 PPCODE:
      devices = guestfs_mounts (g);
      if (devices == NULL)
        croak ("%s", guestfs_last_error (g));
      for (n = 0; devices[n] != NULL; ++n) /**/;
      EXTEND (SP, n);
      for (i = 0; i < n; ++i) {
        PUSHs (sv_2mortal (newSVpv (devices[i], 0)));
        free (devices[i]);
      }
      free (devices);

void
umount_all (g)
      guestfs_h *g;
PREINIT:
      int r;
 PPCODE:
      r = guestfs_umount_all (g);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

void
lvm_remove_all (g)
      guestfs_h *g;
PREINIT:
      int r;
 PPCODE:
      r = guestfs_lvm_remove_all (g);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

SV *
file (g, path)
      guestfs_h *g;
      char *path;
PREINIT:
      char *description;
   CODE:
      description = guestfs_file (g, path);
      if (description == NULL)
        croak ("%s", guestfs_last_error (g));
      RETVAL = newSVpv (description, 0);
      free (description);
 OUTPUT:
      RETVAL

SV *
command (g, arguments)
      guestfs_h *g;
      char **arguments;
PREINIT:
      char *output;
   CODE:
      output = guestfs_command (g, arguments);
      free (arguments);
      if (output == NULL)
        croak ("%s", guestfs_last_error (g));
      RETVAL = newSVpv (output, 0);
      free (output);
 OUTPUT:
      RETVAL

void
command_lines (g, arguments)
      guestfs_h *g;
      char **arguments;
PREINIT:
      char **lines;
      int i, n;
 PPCODE:
      lines = guestfs_command_lines (g, arguments);
      free (arguments);
      if (lines == NULL)
        croak ("%s", guestfs_last_error (g));
      for (n = 0; lines[n] != NULL; ++n) /**/;
      EXTEND (SP, n);
      for (i = 0; i < n; ++i) {
        PUSHs (sv_2mortal (newSVpv (lines[i], 0)));
        free (lines[i]);
      }
      free (lines);

void
stat (g, path)
      guestfs_h *g;
      char *path;
PREINIT:
      struct guestfs_stat *statbuf;
 PPCODE:
      statbuf = guestfs_stat (g, path);
      if (statbuf == NULL)
        croak ("%s", guestfs_last_error (g));
      EXTEND (SP, 2 * 13);
      PUSHs (sv_2mortal (newSVpv ("dev", 0)));
      PUSHs (sv_2mortal (my_newSVll (statbuf->dev)));
      PUSHs (sv_2mortal (newSVpv ("ino", 0)));
      PUSHs (sv_2mortal (my_newSVll (statbuf->ino)));
      PUSHs (sv_2mortal (newSVpv ("mode", 0)));
      PUSHs (sv_2mortal (my_newSVll (statbuf->mode)));
      PUSHs (sv_2mortal (newSVpv ("nlink", 0)));
      PUSHs (sv_2mortal (my_newSVll (statbuf->nlink)));
      PUSHs (sv_2mortal (newSVpv ("uid", 0)));
      PUSHs (sv_2mortal (my_newSVll (statbuf->uid)));
      PUSHs (sv_2mortal (newSVpv ("gid", 0)));
      PUSHs (sv_2mortal (my_newSVll (statbuf->gid)));
      PUSHs (sv_2mortal (newSVpv ("rdev", 0)));
      PUSHs (sv_2mortal (my_newSVll (statbuf->rdev)));
      PUSHs (sv_2mortal (newSVpv ("size", 0)));
      PUSHs (sv_2mortal (my_newSVll (statbuf->size)));
      PUSHs (sv_2mortal (newSVpv ("blksize", 0)));
      PUSHs (sv_2mortal (my_newSVll (statbuf->blksize)));
      PUSHs (sv_2mortal (newSVpv ("blocks", 0)));
      PUSHs (sv_2mortal (my_newSVll (statbuf->blocks)));
      PUSHs (sv_2mortal (newSVpv ("atime", 0)));
      PUSHs (sv_2mortal (my_newSVll (statbuf->atime)));
      PUSHs (sv_2mortal (newSVpv ("mtime", 0)));
      PUSHs (sv_2mortal (my_newSVll (statbuf->mtime)));
      PUSHs (sv_2mortal (newSVpv ("ctime", 0)));
      PUSHs (sv_2mortal (my_newSVll (statbuf->ctime)));
      free (statbuf);

void
lstat (g, path)
      guestfs_h *g;
      char *path;
PREINIT:
      struct guestfs_stat *statbuf;
 PPCODE:
      statbuf = guestfs_lstat (g, path);
      if (statbuf == NULL)
        croak ("%s", guestfs_last_error (g));
      EXTEND (SP, 2 * 13);
      PUSHs (sv_2mortal (newSVpv ("dev", 0)));
      PUSHs (sv_2mortal (my_newSVll (statbuf->dev)));
      PUSHs (sv_2mortal (newSVpv ("ino", 0)));
      PUSHs (sv_2mortal (my_newSVll (statbuf->ino)));
      PUSHs (sv_2mortal (newSVpv ("mode", 0)));
      PUSHs (sv_2mortal (my_newSVll (statbuf->mode)));
      PUSHs (sv_2mortal (newSVpv ("nlink", 0)));
      PUSHs (sv_2mortal (my_newSVll (statbuf->nlink)));
      PUSHs (sv_2mortal (newSVpv ("uid", 0)));
      PUSHs (sv_2mortal (my_newSVll (statbuf->uid)));
      PUSHs (sv_2mortal (newSVpv ("gid", 0)));
      PUSHs (sv_2mortal (my_newSVll (statbuf->gid)));
      PUSHs (sv_2mortal (newSVpv ("rdev", 0)));
      PUSHs (sv_2mortal (my_newSVll (statbuf->rdev)));
      PUSHs (sv_2mortal (newSVpv ("size", 0)));
      PUSHs (sv_2mortal (my_newSVll (statbuf->size)));
      PUSHs (sv_2mortal (newSVpv ("blksize", 0)));
      PUSHs (sv_2mortal (my_newSVll (statbuf->blksize)));
      PUSHs (sv_2mortal (newSVpv ("blocks", 0)));
      PUSHs (sv_2mortal (my_newSVll (statbuf->blocks)));
      PUSHs (sv_2mortal (newSVpv ("atime", 0)));
      PUSHs (sv_2mortal (my_newSVll (statbuf->atime)));
      PUSHs (sv_2mortal (newSVpv ("mtime", 0)));
      PUSHs (sv_2mortal (my_newSVll (statbuf->mtime)));
      PUSHs (sv_2mortal (newSVpv ("ctime", 0)));
      PUSHs (sv_2mortal (my_newSVll (statbuf->ctime)));
      free (statbuf);

void
statvfs (g, path)
      guestfs_h *g;
      char *path;
PREINIT:
      struct guestfs_statvfs *statbuf;
 PPCODE:
      statbuf = guestfs_statvfs (g, path);
      if (statbuf == NULL)
        croak ("%s", guestfs_last_error (g));
      EXTEND (SP, 2 * 11);
      PUSHs (sv_2mortal (newSVpv ("bsize", 0)));
      PUSHs (sv_2mortal (my_newSVll (statbuf->bsize)));
      PUSHs (sv_2mortal (newSVpv ("frsize", 0)));
      PUSHs (sv_2mortal (my_newSVll (statbuf->frsize)));
      PUSHs (sv_2mortal (newSVpv ("blocks", 0)));
      PUSHs (sv_2mortal (my_newSVll (statbuf->blocks)));
      PUSHs (sv_2mortal (newSVpv ("bfree", 0)));
      PUSHs (sv_2mortal (my_newSVll (statbuf->bfree)));
      PUSHs (sv_2mortal (newSVpv ("bavail", 0)));
      PUSHs (sv_2mortal (my_newSVll (statbuf->bavail)));
      PUSHs (sv_2mortal (newSVpv ("files", 0)));
      PUSHs (sv_2mortal (my_newSVll (statbuf->files)));
      PUSHs (sv_2mortal (newSVpv ("ffree", 0)));
      PUSHs (sv_2mortal (my_newSVll (statbuf->ffree)));
      PUSHs (sv_2mortal (newSVpv ("favail", 0)));
      PUSHs (sv_2mortal (my_newSVll (statbuf->favail)));
      PUSHs (sv_2mortal (newSVpv ("fsid", 0)));
      PUSHs (sv_2mortal (my_newSVll (statbuf->fsid)));
      PUSHs (sv_2mortal (newSVpv ("flag", 0)));
      PUSHs (sv_2mortal (my_newSVll (statbuf->flag)));
      PUSHs (sv_2mortal (newSVpv ("namemax", 0)));
      PUSHs (sv_2mortal (my_newSVll (statbuf->namemax)));
      free (statbuf);

void
tune2fs_l (g, device)
      guestfs_h *g;
      char *device;
PREINIT:
      char **superblock;
      int i, n;
 PPCODE:
      superblock = guestfs_tune2fs_l (g, device);
      if (superblock == NULL)
        croak ("%s", guestfs_last_error (g));
      for (n = 0; superblock[n] != NULL; ++n) /**/;
      EXTEND (SP, n);
      for (i = 0; i < n; ++i) {
        PUSHs (sv_2mortal (newSVpv (superblock[i], 0)));
        free (superblock[i]);
      }
      free (superblock);

void
blockdev_setro (g, device)
      guestfs_h *g;
      char *device;
PREINIT:
      int r;
 PPCODE:
      r = guestfs_blockdev_setro (g, device);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

void
blockdev_setrw (g, device)
      guestfs_h *g;
      char *device;
PREINIT:
      int r;
 PPCODE:
      r = guestfs_blockdev_setrw (g, device);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

SV *
blockdev_getro (g, device)
      guestfs_h *g;
      char *device;
PREINIT:
      int ro;
   CODE:
      ro = guestfs_blockdev_getro (g, device);
      if (ro == -1)
        croak ("%s", guestfs_last_error (g));
      RETVAL = newSViv (ro);
 OUTPUT:
      RETVAL

SV *
blockdev_getss (g, device)
      guestfs_h *g;
      char *device;
PREINIT:
      int sectorsize;
   CODE:
      sectorsize = guestfs_blockdev_getss (g, device);
      if (sectorsize == -1)
        croak ("%s", guestfs_last_error (g));
      RETVAL = newSViv (sectorsize);
 OUTPUT:
      RETVAL

SV *
blockdev_getbsz (g, device)
      guestfs_h *g;
      char *device;
PREINIT:
      int blocksize;
   CODE:
      blocksize = guestfs_blockdev_getbsz (g, device);
      if (blocksize == -1)
        croak ("%s", guestfs_last_error (g));
      RETVAL = newSViv (blocksize);
 OUTPUT:
      RETVAL

void
blockdev_setbsz (g, device, blocksize)
      guestfs_h *g;
      char *device;
      int blocksize;
PREINIT:
      int r;
 PPCODE:
      r = guestfs_blockdev_setbsz (g, device, blocksize);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

SV *
blockdev_getsz (g, device)
      guestfs_h *g;
      char *device;
PREINIT:
      int64_t sizeinsectors;
   CODE:
      sizeinsectors = guestfs_blockdev_getsz (g, device);
      if (sizeinsectors == -1)
        croak ("%s", guestfs_last_error (g));
      RETVAL = my_newSVll (sizeinsectors);
 OUTPUT:
      RETVAL

SV *
blockdev_getsize64 (g, device)
      guestfs_h *g;
      char *device;
PREINIT:
      int64_t sizeinbytes;
   CODE:
      sizeinbytes = guestfs_blockdev_getsize64 (g, device);
      if (sizeinbytes == -1)
        croak ("%s", guestfs_last_error (g));
      RETVAL = my_newSVll (sizeinbytes);
 OUTPUT:
      RETVAL

void
blockdev_flushbufs (g, device)
      guestfs_h *g;
      char *device;
PREINIT:
      int r;
 PPCODE:
      r = guestfs_blockdev_flushbufs (g, device);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

void
blockdev_rereadpt (g, device)
      guestfs_h *g;
      char *device;
PREINIT:
      int r;
 PPCODE:
      r = guestfs_blockdev_rereadpt (g, device);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

void
upload (g, filename, remotefilename)
      guestfs_h *g;
      char *filename;
      char *remotefilename;
PREINIT:
      int r;
 PPCODE:
      r = guestfs_upload (g, filename, remotefilename);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

void
download (g, remotefilename, filename)
      guestfs_h *g;
      char *remotefilename;
      char *filename;
PREINIT:
      int r;
 PPCODE:
      r = guestfs_download (g, remotefilename, filename);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

SV *
checksum (g, csumtype, path)
      guestfs_h *g;
      char *csumtype;
      char *path;
PREINIT:
      char *checksum;
   CODE:
      checksum = guestfs_checksum (g, csumtype, path);
      if (checksum == NULL)
        croak ("%s", guestfs_last_error (g));
      RETVAL = newSVpv (checksum, 0);
      free (checksum);
 OUTPUT:
      RETVAL

void
tar_in (g, tarfile, directory)
      guestfs_h *g;
      char *tarfile;
      char *directory;
PREINIT:
      int r;
 PPCODE:
      r = guestfs_tar_in (g, tarfile, directory);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

void
tar_out (g, directory, tarfile)
      guestfs_h *g;
      char *directory;
      char *tarfile;
PREINIT:
      int r;
 PPCODE:
      r = guestfs_tar_out (g, directory, tarfile);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

void
tgz_in (g, tarball, directory)
      guestfs_h *g;
      char *tarball;
      char *directory;
PREINIT:
      int r;
 PPCODE:
      r = guestfs_tgz_in (g, tarball, directory);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

void
tgz_out (g, directory, tarball)
      guestfs_h *g;
      char *directory;
      char *tarball;
PREINIT:
      int r;
 PPCODE:
      r = guestfs_tgz_out (g, directory, tarball);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

void
mount_ro (g, device, mountpoint)
      guestfs_h *g;
      char *device;
      char *mountpoint;
PREINIT:
      int r;
 PPCODE:
      r = guestfs_mount_ro (g, device, mountpoint);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

void
mount_options (g, options, device, mountpoint)
      guestfs_h *g;
      char *options;
      char *device;
      char *mountpoint;
PREINIT:
      int r;
 PPCODE:
      r = guestfs_mount_options (g, options, device, mountpoint);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

void
mount_vfs (g, options, vfstype, device, mountpoint)
      guestfs_h *g;
      char *options;
      char *vfstype;
      char *device;
      char *mountpoint;
PREINIT:
      int r;
 PPCODE:
      r = guestfs_mount_vfs (g, options, vfstype, device, mountpoint);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

SV *
debug (g, subcmd, extraargs)
      guestfs_h *g;
      char *subcmd;
      char **extraargs;
PREINIT:
      char *result;
   CODE:
      result = guestfs_debug (g, subcmd, extraargs);
      free (extraargs);
      if (result == NULL)
        croak ("%s", guestfs_last_error (g));
      RETVAL = newSVpv (result, 0);
      free (result);
 OUTPUT:
      RETVAL

void
lvremove (g, device)
      guestfs_h *g;
      char *device;
PREINIT:
      int r;
 PPCODE:
      r = guestfs_lvremove (g, device);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

void
vgremove (g, vgname)
      guestfs_h *g;
      char *vgname;
PREINIT:
      int r;
 PPCODE:
      r = guestfs_vgremove (g, vgname);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

void
pvremove (g, device)
      guestfs_h *g;
      char *device;
PREINIT:
      int r;
 PPCODE:
      r = guestfs_pvremove (g, device);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

void
set_e2label (g, device, label)
      guestfs_h *g;
      char *device;
      char *label;
PREINIT:
      int r;
 PPCODE:
      r = guestfs_set_e2label (g, device, label);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

SV *
get_e2label (g, device)
      guestfs_h *g;
      char *device;
PREINIT:
      char *label;
   CODE:
      label = guestfs_get_e2label (g, device);
      if (label == NULL)
        croak ("%s", guestfs_last_error (g));
      RETVAL = newSVpv (label, 0);
      free (label);
 OUTPUT:
      RETVAL

void
set_e2uuid (g, device, uuid)
      guestfs_h *g;
      char *device;
      char *uuid;
PREINIT:
      int r;
 PPCODE:
      r = guestfs_set_e2uuid (g, device, uuid);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

SV *
get_e2uuid (g, device)
      guestfs_h *g;
      char *device;
PREINIT:
      char *uuid;
   CODE:
      uuid = guestfs_get_e2uuid (g, device);
      if (uuid == NULL)
        croak ("%s", guestfs_last_error (g));
      RETVAL = newSVpv (uuid, 0);
      free (uuid);
 OUTPUT:
      RETVAL

SV *
fsck (g, fstype, device)
      guestfs_h *g;
      char *fstype;
      char *device;
PREINIT:
      int status;
   CODE:
      status = guestfs_fsck (g, fstype, device);
      if (status == -1)
        croak ("%s", guestfs_last_error (g));
      RETVAL = newSViv (status);
 OUTPUT:
      RETVAL

void
zero (g, device)
      guestfs_h *g;
      char *device;
PREINIT:
      int r;
 PPCODE:
      r = guestfs_zero (g, device);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

void
grub_install (g, root, device)
      guestfs_h *g;
      char *root;
      char *device;
PREINIT:
      int r;
 PPCODE:
      r = guestfs_grub_install (g, root, device);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

void
cp (g, src, dest)
      guestfs_h *g;
      char *src;
      char *dest;
PREINIT:
      int r;
 PPCODE:
      r = guestfs_cp (g, src, dest);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

void
cp_a (g, src, dest)
      guestfs_h *g;
      char *src;
      char *dest;
PREINIT:
      int r;
 PPCODE:
      r = guestfs_cp_a (g, src, dest);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

void
mv (g, src, dest)
      guestfs_h *g;
      char *src;
      char *dest;
PREINIT:
      int r;
 PPCODE:
      r = guestfs_mv (g, src, dest);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

void
drop_caches (g, whattodrop)
      guestfs_h *g;
      int whattodrop;
PREINIT:
      int r;
 PPCODE:
      r = guestfs_drop_caches (g, whattodrop);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

SV *
dmesg (g)
      guestfs_h *g;
PREINIT:
      char *kmsgs;
   CODE:
      kmsgs = guestfs_dmesg (g);
      if (kmsgs == NULL)
        croak ("%s", guestfs_last_error (g));
      RETVAL = newSVpv (kmsgs, 0);
      free (kmsgs);
 OUTPUT:
      RETVAL

void
ping_daemon (g)
      guestfs_h *g;
PREINIT:
      int r;
 PPCODE:
      r = guestfs_ping_daemon (g);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

SV *
equal (g, file1, file2)
      guestfs_h *g;
      char *file1;
      char *file2;
PREINIT:
      int equality;
   CODE:
      equality = guestfs_equal (g, file1, file2);
      if (equality == -1)
        croak ("%s", guestfs_last_error (g));
      RETVAL = newSViv (equality);
 OUTPUT:
      RETVAL

void
strings (g, path)
      guestfs_h *g;
      char *path;
PREINIT:
      char **stringsout;
      int i, n;
 PPCODE:
      stringsout = guestfs_strings (g, path);
      if (stringsout == NULL)
        croak ("%s", guestfs_last_error (g));
      for (n = 0; stringsout[n] != NULL; ++n) /**/;
      EXTEND (SP, n);
      for (i = 0; i < n; ++i) {
        PUSHs (sv_2mortal (newSVpv (stringsout[i], 0)));
        free (stringsout[i]);
      }
      free (stringsout);

void
strings_e (g, encoding, path)
      guestfs_h *g;
      char *encoding;
      char *path;
PREINIT:
      char **stringsout;
      int i, n;
 PPCODE:
      stringsout = guestfs_strings_e (g, encoding, path);
      if (stringsout == NULL)
        croak ("%s", guestfs_last_error (g));
      for (n = 0; stringsout[n] != NULL; ++n) /**/;
      EXTEND (SP, n);
      for (i = 0; i < n; ++i) {
        PUSHs (sv_2mortal (newSVpv (stringsout[i], 0)));
        free (stringsout[i]);
      }
      free (stringsout);

SV *
hexdump (g, path)
      guestfs_h *g;
      char *path;
PREINIT:
      char *dump;
   CODE:
      dump = guestfs_hexdump (g, path);
      if (dump == NULL)
        croak ("%s", guestfs_last_error (g));
      RETVAL = newSVpv (dump, 0);
      free (dump);
 OUTPUT:
      RETVAL

void
zerofree (g, device)
      guestfs_h *g;
      char *device;
PREINIT:
      int r;
 PPCODE:
      r = guestfs_zerofree (g, device);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

void
pvresize (g, device)
      guestfs_h *g;
      char *device;
PREINIT:
      int r;
 PPCODE:
      r = guestfs_pvresize (g, device);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

void
sfdisk_N (g, device, partnum, cyls, heads, sectors, line)
      guestfs_h *g;
      char *device;
      int partnum;
      int cyls;
      int heads;
      int sectors;
      char *line;
PREINIT:
      int r;
 PPCODE:
      r = guestfs_sfdisk_N (g, device, partnum, cyls, heads, sectors, line);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

SV *
sfdisk_l (g, device)
      guestfs_h *g;
      char *device;
PREINIT:
      char *partitions;
   CODE:
      partitions = guestfs_sfdisk_l (g, device);
      if (partitions == NULL)
        croak ("%s", guestfs_last_error (g));
      RETVAL = newSVpv (partitions, 0);
      free (partitions);
 OUTPUT:
      RETVAL

SV *
sfdisk_kernel_geometry (g, device)
      guestfs_h *g;
      char *device;
PREINIT:
      char *partitions;
   CODE:
      partitions = guestfs_sfdisk_kernel_geometry (g, device);
      if (partitions == NULL)
        croak ("%s", guestfs_last_error (g));
      RETVAL = newSVpv (partitions, 0);
      free (partitions);
 OUTPUT:
      RETVAL

SV *
sfdisk_disk_geometry (g, device)
      guestfs_h *g;
      char *device;
PREINIT:
      char *partitions;
   CODE:
      partitions = guestfs_sfdisk_disk_geometry (g, device);
      if (partitions == NULL)
        croak ("%s", guestfs_last_error (g));
      RETVAL = newSVpv (partitions, 0);
      free (partitions);
 OUTPUT:
      RETVAL

void
vg_activate_all (g, activate)
      guestfs_h *g;
      int activate;
PREINIT:
      int r;
 PPCODE:
      r = guestfs_vg_activate_all (g, activate);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

void
vg_activate (g, activate, volgroups)
      guestfs_h *g;
      int activate;
      char **volgroups;
PREINIT:
      int r;
 PPCODE:
      r = guestfs_vg_activate (g, activate, volgroups);
      free (volgroups);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

void
lvresize (g, device, mbytes)
      guestfs_h *g;
      char *device;
      int mbytes;
PREINIT:
      int r;
 PPCODE:
      r = guestfs_lvresize (g, device, mbytes);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

void
resize2fs (g, device)
      guestfs_h *g;
      char *device;
PREINIT:
      int r;
 PPCODE:
      r = guestfs_resize2fs (g, device);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

void
find (g, directory)
      guestfs_h *g;
      char *directory;
PREINIT:
      char **names;
      int i, n;
 PPCODE:
      names = guestfs_find (g, directory);
      if (names == NULL)
        croak ("%s", guestfs_last_error (g));
      for (n = 0; names[n] != NULL; ++n) /**/;
      EXTEND (SP, n);
      for (i = 0; i < n; ++i) {
        PUSHs (sv_2mortal (newSVpv (names[i], 0)));
        free (names[i]);
      }
      free (names);

void
e2fsck_f (g, device)
      guestfs_h *g;
      char *device;
PREINIT:
      int r;
 PPCODE:
      r = guestfs_e2fsck_f (g, device);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

void
sleep (g, secs)
      guestfs_h *g;
      int secs;
PREINIT:
      int r;
 PPCODE:
      r = guestfs_sleep (g, secs);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

SV *
ntfs_3g_probe (g, rw, device)
      guestfs_h *g;
      int rw;
      char *device;
PREINIT:
      int status;
   CODE:
      status = guestfs_ntfs_3g_probe (g, rw, device);
      if (status == -1)
        croak ("%s", guestfs_last_error (g));
      RETVAL = newSViv (status);
 OUTPUT:
      RETVAL

SV *
sh (g, command)
      guestfs_h *g;
      char *command;
PREINIT:
      char *output;
   CODE:
      output = guestfs_sh (g, command);
      if (output == NULL)
        croak ("%s", guestfs_last_error (g));
      RETVAL = newSVpv (output, 0);
      free (output);
 OUTPUT:
      RETVAL

void
sh_lines (g, command)
      guestfs_h *g;
      char *command;
PREINIT:
      char **lines;
      int i, n;
 PPCODE:
      lines = guestfs_sh_lines (g, command);
      if (lines == NULL)
        croak ("%s", guestfs_last_error (g));
      for (n = 0; lines[n] != NULL; ++n) /**/;
      EXTEND (SP, n);
      for (i = 0; i < n; ++i) {
        PUSHs (sv_2mortal (newSVpv (lines[i], 0)));
        free (lines[i]);
      }
      free (lines);

void
glob_expand (g, pattern)
      guestfs_h *g;
      char *pattern;
PREINIT:
      char **paths;
      int i, n;
 PPCODE:
      paths = guestfs_glob_expand (g, pattern);
      if (paths == NULL)
        croak ("%s", guestfs_last_error (g));
      for (n = 0; paths[n] != NULL; ++n) /**/;
      EXTEND (SP, n);
      for (i = 0; i < n; ++i) {
        PUSHs (sv_2mortal (newSVpv (paths[i], 0)));
        free (paths[i]);
      }
      free (paths);

void
scrub_device (g, device)
      guestfs_h *g;
      char *device;
PREINIT:
      int r;
 PPCODE:
      r = guestfs_scrub_device (g, device);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

void
scrub_file (g, file)
      guestfs_h *g;
      char *file;
PREINIT:
      int r;
 PPCODE:
      r = guestfs_scrub_file (g, file);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

void
scrub_freespace (g, dir)
      guestfs_h *g;
      char *dir;
PREINIT:
      int r;
 PPCODE:
      r = guestfs_scrub_freespace (g, dir);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

SV *
mkdtemp (g, template)
      guestfs_h *g;
      char *template;
PREINIT:
      char *dir;
   CODE:
      dir = guestfs_mkdtemp (g, template);
      if (dir == NULL)
        croak ("%s", guestfs_last_error (g));
      RETVAL = newSVpv (dir, 0);
      free (dir);
 OUTPUT:
      RETVAL

SV *
wc_l (g, path)
      guestfs_h *g;
      char *path;
PREINIT:
      int lines;
   CODE:
      lines = guestfs_wc_l (g, path);
      if (lines == -1)
        croak ("%s", guestfs_last_error (g));
      RETVAL = newSViv (lines);
 OUTPUT:
      RETVAL

SV *
wc_w (g, path)
      guestfs_h *g;
      char *path;
PREINIT:
      int words;
   CODE:
      words = guestfs_wc_w (g, path);
      if (words == -1)
        croak ("%s", guestfs_last_error (g));
      RETVAL = newSViv (words);
 OUTPUT:
      RETVAL

SV *
wc_c (g, path)
      guestfs_h *g;
      char *path;
PREINIT:
      int chars;
   CODE:
      chars = guestfs_wc_c (g, path);
      if (chars == -1)
        croak ("%s", guestfs_last_error (g));
      RETVAL = newSViv (chars);
 OUTPUT:
      RETVAL

void
head (g, path)
      guestfs_h *g;
      char *path;
PREINIT:
      char **lines;
      int i, n;
 PPCODE:
      lines = guestfs_head (g, path);
      if (lines == NULL)
        croak ("%s", guestfs_last_error (g));
      for (n = 0; lines[n] != NULL; ++n) /**/;
      EXTEND (SP, n);
      for (i = 0; i < n; ++i) {
        PUSHs (sv_2mortal (newSVpv (lines[i], 0)));
        free (lines[i]);
      }
      free (lines);

void
head_n (g, nrlines, path)
      guestfs_h *g;
      int nrlines;
      char *path;
PREINIT:
      char **lines;
      int i, n;
 PPCODE:
      lines = guestfs_head_n (g, nrlines, path);
      if (lines == NULL)
        croak ("%s", guestfs_last_error (g));
      for (n = 0; lines[n] != NULL; ++n) /**/;
      EXTEND (SP, n);
      for (i = 0; i < n; ++i) {
        PUSHs (sv_2mortal (newSVpv (lines[i], 0)));
        free (lines[i]);
      }
      free (lines);

void
tail (g, path)
      guestfs_h *g;
      char *path;
PREINIT:
      char **lines;
      int i, n;
 PPCODE:
      lines = guestfs_tail (g, path);
      if (lines == NULL)
        croak ("%s", guestfs_last_error (g));
      for (n = 0; lines[n] != NULL; ++n) /**/;
      EXTEND (SP, n);
      for (i = 0; i < n; ++i) {
        PUSHs (sv_2mortal (newSVpv (lines[i], 0)));
        free (lines[i]);
      }
      free (lines);

void
tail_n (g, nrlines, path)
      guestfs_h *g;
      int nrlines;
      char *path;
PREINIT:
      char **lines;
      int i, n;
 PPCODE:
      lines = guestfs_tail_n (g, nrlines, path);
      if (lines == NULL)
        croak ("%s", guestfs_last_error (g));
      for (n = 0; lines[n] != NULL; ++n) /**/;
      EXTEND (SP, n);
      for (i = 0; i < n; ++i) {
        PUSHs (sv_2mortal (newSVpv (lines[i], 0)));
        free (lines[i]);
      }
      free (lines);

SV *
df (g)
      guestfs_h *g;
PREINIT:
      char *output;
   CODE:
      output = guestfs_df (g);
      if (output == NULL)
        croak ("%s", guestfs_last_error (g));
      RETVAL = newSVpv (output, 0);
      free (output);
 OUTPUT:
      RETVAL

SV *
df_h (g)
      guestfs_h *g;
PREINIT:
      char *output;
   CODE:
      output = guestfs_df_h (g);
      if (output == NULL)
        croak ("%s", guestfs_last_error (g));
      RETVAL = newSVpv (output, 0);
      free (output);
 OUTPUT:
      RETVAL

SV *
du (g, path)
      guestfs_h *g;
      char *path;
PREINIT:
      int64_t sizekb;
   CODE:
      sizekb = guestfs_du (g, path);
      if (sizekb == -1)
        croak ("%s", guestfs_last_error (g));
      RETVAL = my_newSVll (sizekb);
 OUTPUT:
      RETVAL

void
initrd_list (g, path)
      guestfs_h *g;
      char *path;
PREINIT:
      char **filenames;
      int i, n;
 PPCODE:
      filenames = guestfs_initrd_list (g, path);
      if (filenames == NULL)
        croak ("%s", guestfs_last_error (g));
      for (n = 0; filenames[n] != NULL; ++n) /**/;
      EXTEND (SP, n);
      for (i = 0; i < n; ++i) {
        PUSHs (sv_2mortal (newSVpv (filenames[i], 0)));
        free (filenames[i]);
      }
      free (filenames);

void
mount_loop (g, file, mountpoint)
      guestfs_h *g;
      char *file;
      char *mountpoint;
PREINIT:
      int r;
 PPCODE:
      r = guestfs_mount_loop (g, file, mountpoint);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

void
mkswap (g, device)
      guestfs_h *g;
      char *device;
PREINIT:
      int r;
 PPCODE:
      r = guestfs_mkswap (g, device);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

void
mkswap_L (g, label, device)
      guestfs_h *g;
      char *label;
      char *device;
PREINIT:
      int r;
 PPCODE:
      r = guestfs_mkswap_L (g, label, device);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

void
mkswap_U (g, uuid, device)
      guestfs_h *g;
      char *uuid;
      char *device;
PREINIT:
      int r;
 PPCODE:
      r = guestfs_mkswap_U (g, uuid, device);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

void
mknod (g, mode, devmajor, devminor, path)
      guestfs_h *g;
      int mode;
      int devmajor;
      int devminor;
      char *path;
PREINIT:
      int r;
 PPCODE:
      r = guestfs_mknod (g, mode, devmajor, devminor, path);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

void
mkfifo (g, mode, path)
      guestfs_h *g;
      int mode;
      char *path;
PREINIT:
      int r;
 PPCODE:
      r = guestfs_mkfifo (g, mode, path);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

void
mknod_b (g, mode, devmajor, devminor, path)
      guestfs_h *g;
      int mode;
      int devmajor;
      int devminor;
      char *path;
PREINIT:
      int r;
 PPCODE:
      r = guestfs_mknod_b (g, mode, devmajor, devminor, path);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

void
mknod_c (g, mode, devmajor, devminor, path)
      guestfs_h *g;
      int mode;
      int devmajor;
      int devminor;
      char *path;
PREINIT:
      int r;
 PPCODE:
      r = guestfs_mknod_c (g, mode, devmajor, devminor, path);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

SV *
umask (g, mask)
      guestfs_h *g;
      int mask;
PREINIT:
      int oldmask;
   CODE:
      oldmask = guestfs_umask (g, mask);
      if (oldmask == -1)
        croak ("%s", guestfs_last_error (g));
      RETVAL = newSViv (oldmask);
 OUTPUT:
      RETVAL

void
readdir (g, dir)
      guestfs_h *g;
      char *dir;
PREINIT:
      struct guestfs_dirent_list *entries;
      int i;
      HV *hv;
 PPCODE:
      entries = guestfs_readdir (g, dir);
      if (entries == NULL)
        croak ("%s", guestfs_last_error (g));
      EXTEND (SP, entries->len);
      for (i = 0; i < entries->len; ++i) {
        hv = newHV ();
        (void) hv_store (hv, "ino", 3, my_newSVll (entries->val[i].ino), 0);
        (void) hv_store (hv, "ftyp", 4, newSVpv (&entries->val[i].ftyp, 1), 0);
        (void) hv_store (hv, "name", 4, newSVpv (entries->val[i].name, 0), 0);
        PUSHs (sv_2mortal (newRV ((SV *) hv)));
      }
      guestfs_free_dirent_list (entries);

void
sfdiskM (g, device, lines)
      guestfs_h *g;
      char *device;
      char **lines;
PREINIT:
      int r;
 PPCODE:
      r = guestfs_sfdiskM (g, device, lines);
      free (lines);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

SV *
zfile (g, meth, path)
      guestfs_h *g;
      char *meth;
      char *path;
PREINIT:
      char *description;
   CODE:
      description = guestfs_zfile (g, meth, path);
      if (description == NULL)
        croak ("%s", guestfs_last_error (g));
      RETVAL = newSVpv (description, 0);
      free (description);
 OUTPUT:
      RETVAL

void
getxattrs (g, path)
      guestfs_h *g;
      char *path;
PREINIT:
      struct guestfs_xattr_list *xattrs;
      int i;
      HV *hv;
 PPCODE:
      xattrs = guestfs_getxattrs (g, path);
      if (xattrs == NULL)
        croak ("%s", guestfs_last_error (g));
      EXTEND (SP, xattrs->len);
      for (i = 0; i < xattrs->len; ++i) {
        hv = newHV ();
        (void) hv_store (hv, "attrname", 8, newSVpv (xattrs->val[i].attrname, 0), 0);
        (void) hv_store (hv, "attrval", 7, newSVpv (xattrs->val[i].attrval, xattrs->val[i].attrval_len), 0);
        PUSHs (sv_2mortal (newRV ((SV *) hv)));
      }
      guestfs_free_xattr_list (xattrs);

void
lgetxattrs (g, path)
      guestfs_h *g;
      char *path;
PREINIT:
      struct guestfs_xattr_list *xattrs;
      int i;
      HV *hv;
 PPCODE:
      xattrs = guestfs_lgetxattrs (g, path);
      if (xattrs == NULL)
        croak ("%s", guestfs_last_error (g));
      EXTEND (SP, xattrs->len);
      for (i = 0; i < xattrs->len; ++i) {
        hv = newHV ();
        (void) hv_store (hv, "attrname", 8, newSVpv (xattrs->val[i].attrname, 0), 0);
        (void) hv_store (hv, "attrval", 7, newSVpv (xattrs->val[i].attrval, xattrs->val[i].attrval_len), 0);
        PUSHs (sv_2mortal (newRV ((SV *) hv)));
      }
      guestfs_free_xattr_list (xattrs);

void
setxattr (g, xattr, val, vallen, path)
      guestfs_h *g;
      char *xattr;
      char *val;
      int vallen;
      char *path;
PREINIT:
      int r;
 PPCODE:
      r = guestfs_setxattr (g, xattr, val, vallen, path);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

void
lsetxattr (g, xattr, val, vallen, path)
      guestfs_h *g;
      char *xattr;
      char *val;
      int vallen;
      char *path;
PREINIT:
      int r;
 PPCODE:
      r = guestfs_lsetxattr (g, xattr, val, vallen, path);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

void
removexattr (g, xattr, path)
      guestfs_h *g;
      char *xattr;
      char *path;
PREINIT:
      int r;
 PPCODE:
      r = guestfs_removexattr (g, xattr, path);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

void
lremovexattr (g, xattr, path)
      guestfs_h *g;
      char *xattr;
      char *path;
PREINIT:
      int r;
 PPCODE:
      r = guestfs_lremovexattr (g, xattr, path);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

void
mountpoints (g)
      guestfs_h *g;
PREINIT:
      char **mps;
      int i, n;
 PPCODE:
      mps = guestfs_mountpoints (g);
      if (mps == NULL)
        croak ("%s", guestfs_last_error (g));
      for (n = 0; mps[n] != NULL; ++n) /**/;
      EXTEND (SP, n);
      for (i = 0; i < n; ++i) {
        PUSHs (sv_2mortal (newSVpv (mps[i], 0)));
        free (mps[i]);
      }
      free (mps);

void
mkmountpoint (g, exemptpath)
      guestfs_h *g;
      char *exemptpath;
PREINIT:
      int r;
 PPCODE:
      r = guestfs_mkmountpoint (g, exemptpath);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

void
rmmountpoint (g, exemptpath)
      guestfs_h *g;
      char *exemptpath;
PREINIT:
      int r;
 PPCODE:
      r = guestfs_rmmountpoint (g, exemptpath);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

SV *
read_file (g, path)
      guestfs_h *g;
      char *path;
PREINIT:
      char *content;
      size_t size;
   CODE:
      content = guestfs_read_file (g, path, &size);
      if (content == NULL)
        croak ("%s", guestfs_last_error (g));
      RETVAL = newSVpv (content, size);
      free (content);
 OUTPUT:
      RETVAL

void
grep (g, regex, path)
      guestfs_h *g;
      char *regex;
      char *path;
PREINIT:
      char **lines;
      int i, n;
 PPCODE:
      lines = guestfs_grep (g, regex, path);
      if (lines == NULL)
        croak ("%s", guestfs_last_error (g));
      for (n = 0; lines[n] != NULL; ++n) /**/;
      EXTEND (SP, n);
      for (i = 0; i < n; ++i) {
        PUSHs (sv_2mortal (newSVpv (lines[i], 0)));
        free (lines[i]);
      }
      free (lines);

void
egrep (g, regex, path)
      guestfs_h *g;
      char *regex;
      char *path;
PREINIT:
      char **lines;
      int i, n;
 PPCODE:
      lines = guestfs_egrep (g, regex, path);
      if (lines == NULL)
        croak ("%s", guestfs_last_error (g));
      for (n = 0; lines[n] != NULL; ++n) /**/;
      EXTEND (SP, n);
      for (i = 0; i < n; ++i) {
        PUSHs (sv_2mortal (newSVpv (lines[i], 0)));
        free (lines[i]);
      }
      free (lines);

void
fgrep (g, pattern, path)
      guestfs_h *g;
      char *pattern;
      char *path;
PREINIT:
      char **lines;
      int i, n;
 PPCODE:
      lines = guestfs_fgrep (g, pattern, path);
      if (lines == NULL)
        croak ("%s", guestfs_last_error (g));
      for (n = 0; lines[n] != NULL; ++n) /**/;
      EXTEND (SP, n);
      for (i = 0; i < n; ++i) {
        PUSHs (sv_2mortal (newSVpv (lines[i], 0)));
        free (lines[i]);
      }
      free (lines);

void
grepi (g, regex, path)
      guestfs_h *g;
      char *regex;
      char *path;
PREINIT:
      char **lines;
      int i, n;
 PPCODE:
      lines = guestfs_grepi (g, regex, path);
      if (lines == NULL)
        croak ("%s", guestfs_last_error (g));
      for (n = 0; lines[n] != NULL; ++n) /**/;
      EXTEND (SP, n);
      for (i = 0; i < n; ++i) {
        PUSHs (sv_2mortal (newSVpv (lines[i], 0)));
        free (lines[i]);
      }
      free (lines);

void
egrepi (g, regex, path)
      guestfs_h *g;
      char *regex;
      char *path;
PREINIT:
      char **lines;
      int i, n;
 PPCODE:
      lines = guestfs_egrepi (g, regex, path);
      if (lines == NULL)
        croak ("%s", guestfs_last_error (g));
      for (n = 0; lines[n] != NULL; ++n) /**/;
      EXTEND (SP, n);
      for (i = 0; i < n; ++i) {
        PUSHs (sv_2mortal (newSVpv (lines[i], 0)));
        free (lines[i]);
      }
      free (lines);

void
fgrepi (g, pattern, path)
      guestfs_h *g;
      char *pattern;
      char *path;
PREINIT:
      char **lines;
      int i, n;
 PPCODE:
      lines = guestfs_fgrepi (g, pattern, path);
      if (lines == NULL)
        croak ("%s", guestfs_last_error (g));
      for (n = 0; lines[n] != NULL; ++n) /**/;
      EXTEND (SP, n);
      for (i = 0; i < n; ++i) {
        PUSHs (sv_2mortal (newSVpv (lines[i], 0)));
        free (lines[i]);
      }
      free (lines);

void
zgrep (g, regex, path)
      guestfs_h *g;
      char *regex;
      char *path;
PREINIT:
      char **lines;
      int i, n;
 PPCODE:
      lines = guestfs_zgrep (g, regex, path);
      if (lines == NULL)
        croak ("%s", guestfs_last_error (g));
      for (n = 0; lines[n] != NULL; ++n) /**/;
      EXTEND (SP, n);
      for (i = 0; i < n; ++i) {
        PUSHs (sv_2mortal (newSVpv (lines[i], 0)));
        free (lines[i]);
      }
      free (lines);

void
zegrep (g, regex, path)
      guestfs_h *g;
      char *regex;
      char *path;
PREINIT:
      char **lines;
      int i, n;
 PPCODE:
      lines = guestfs_zegrep (g, regex, path);
      if (lines == NULL)
        croak ("%s", guestfs_last_error (g));
      for (n = 0; lines[n] != NULL; ++n) /**/;
      EXTEND (SP, n);
      for (i = 0; i < n; ++i) {
        PUSHs (sv_2mortal (newSVpv (lines[i], 0)));
        free (lines[i]);
      }
      free (lines);

void
zfgrep (g, pattern, path)
      guestfs_h *g;
      char *pattern;
      char *path;
PREINIT:
      char **lines;
      int i, n;
 PPCODE:
      lines = guestfs_zfgrep (g, pattern, path);
      if (lines == NULL)
        croak ("%s", guestfs_last_error (g));
      for (n = 0; lines[n] != NULL; ++n) /**/;
      EXTEND (SP, n);
      for (i = 0; i < n; ++i) {
        PUSHs (sv_2mortal (newSVpv (lines[i], 0)));
        free (lines[i]);
      }
      free (lines);

void
zgrepi (g, regex, path)
      guestfs_h *g;
      char *regex;
      char *path;
PREINIT:
      char **lines;
      int i, n;
 PPCODE:
      lines = guestfs_zgrepi (g, regex, path);
      if (lines == NULL)
        croak ("%s", guestfs_last_error (g));
      for (n = 0; lines[n] != NULL; ++n) /**/;
      EXTEND (SP, n);
      for (i = 0; i < n; ++i) {
        PUSHs (sv_2mortal (newSVpv (lines[i], 0)));
        free (lines[i]);
      }
      free (lines);

void
zegrepi (g, regex, path)
      guestfs_h *g;
      char *regex;
      char *path;
PREINIT:
      char **lines;
      int i, n;
 PPCODE:
      lines = guestfs_zegrepi (g, regex, path);
      if (lines == NULL)
        croak ("%s", guestfs_last_error (g));
      for (n = 0; lines[n] != NULL; ++n) /**/;
      EXTEND (SP, n);
      for (i = 0; i < n; ++i) {
        PUSHs (sv_2mortal (newSVpv (lines[i], 0)));
        free (lines[i]);
      }
      free (lines);

void
zfgrepi (g, pattern, path)
      guestfs_h *g;
      char *pattern;
      char *path;
PREINIT:
      char **lines;
      int i, n;
 PPCODE:
      lines = guestfs_zfgrepi (g, pattern, path);
      if (lines == NULL)
        croak ("%s", guestfs_last_error (g));
      for (n = 0; lines[n] != NULL; ++n) /**/;
      EXTEND (SP, n);
      for (i = 0; i < n; ++i) {
        PUSHs (sv_2mortal (newSVpv (lines[i], 0)));
        free (lines[i]);
      }
      free (lines);

SV *
realpath (g, path)
      guestfs_h *g;
      char *path;
PREINIT:
      char *rpath;
   CODE:
      rpath = guestfs_realpath (g, path);
      if (rpath == NULL)
        croak ("%s", guestfs_last_error (g));
      RETVAL = newSVpv (rpath, 0);
      free (rpath);
 OUTPUT:
      RETVAL

void
ln (g, target, linkname)
      guestfs_h *g;
      char *target;
      char *linkname;
PREINIT:
      int r;
 PPCODE:
      r = guestfs_ln (g, target, linkname);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

void
ln_f (g, target, linkname)
      guestfs_h *g;
      char *target;
      char *linkname;
PREINIT:
      int r;
 PPCODE:
      r = guestfs_ln_f (g, target, linkname);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

void
ln_s (g, target, linkname)
      guestfs_h *g;
      char *target;
      char *linkname;
PREINIT:
      int r;
 PPCODE:
      r = guestfs_ln_s (g, target, linkname);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

void
ln_sf (g, target, linkname)
      guestfs_h *g;
      char *target;
      char *linkname;
PREINIT:
      int r;
 PPCODE:
      r = guestfs_ln_sf (g, target, linkname);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

SV *
readlink (g, path)
      guestfs_h *g;
      char *path;
PREINIT:
      char *link;
   CODE:
      link = guestfs_readlink (g, path);
      if (link == NULL)
        croak ("%s", guestfs_last_error (g));
      RETVAL = newSVpv (link, 0);
      free (link);
 OUTPUT:
      RETVAL

void
fallocate (g, path, len)
      guestfs_h *g;
      char *path;
      int len;
PREINIT:
      int r;
 PPCODE:
      r = guestfs_fallocate (g, path, len);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

void
swapon_device (g, device)
      guestfs_h *g;
      char *device;
PREINIT:
      int r;
 PPCODE:
      r = guestfs_swapon_device (g, device);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

void
swapoff_device (g, device)
      guestfs_h *g;
      char *device;
PREINIT:
      int r;
 PPCODE:
      r = guestfs_swapoff_device (g, device);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

void
swapon_file (g, file)
      guestfs_h *g;
      char *file;
PREINIT:
      int r;
 PPCODE:
      r = guestfs_swapon_file (g, file);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

void
swapoff_file (g, file)
      guestfs_h *g;
      char *file;
PREINIT:
      int r;
 PPCODE:
      r = guestfs_swapoff_file (g, file);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

void
swapon_label (g, label)
      guestfs_h *g;
      char *label;
PREINIT:
      int r;
 PPCODE:
      r = guestfs_swapon_label (g, label);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

void
swapoff_label (g, label)
      guestfs_h *g;
      char *label;
PREINIT:
      int r;
 PPCODE:
      r = guestfs_swapoff_label (g, label);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

void
swapon_uuid (g, uuid)
      guestfs_h *g;
      char *uuid;
PREINIT:
      int r;
 PPCODE:
      r = guestfs_swapon_uuid (g, uuid);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

void
swapoff_uuid (g, uuid)
      guestfs_h *g;
      char *uuid;
PREINIT:
      int r;
 PPCODE:
      r = guestfs_swapoff_uuid (g, uuid);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

void
mkswap_file (g, path)
      guestfs_h *g;
      char *path;
PREINIT:
      int r;
 PPCODE:
      r = guestfs_mkswap_file (g, path);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

void
inotify_init (g, maxevents)
      guestfs_h *g;
      int maxevents;
PREINIT:
      int r;
 PPCODE:
      r = guestfs_inotify_init (g, maxevents);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

SV *
inotify_add_watch (g, path, mask)
      guestfs_h *g;
      char *path;
      int mask;
PREINIT:
      int64_t wd;
   CODE:
      wd = guestfs_inotify_add_watch (g, path, mask);
      if (wd == -1)
        croak ("%s", guestfs_last_error (g));
      RETVAL = my_newSVll (wd);
 OUTPUT:
      RETVAL

void
inotify_rm_watch (g, wd)
      guestfs_h *g;
      int wd;
PREINIT:
      int r;
 PPCODE:
      r = guestfs_inotify_rm_watch (g, wd);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

void
inotify_read (g)
      guestfs_h *g;
PREINIT:
      struct guestfs_inotify_event_list *events;
      int i;
      HV *hv;
 PPCODE:
      events = guestfs_inotify_read (g);
      if (events == NULL)
        croak ("%s", guestfs_last_error (g));
      EXTEND (SP, events->len);
      for (i = 0; i < events->len; ++i) {
        hv = newHV ();
        (void) hv_store (hv, "in_wd", 5, my_newSVll (events->val[i].in_wd), 0);
        (void) hv_store (hv, "in_mask", 7, newSVnv (events->val[i].in_mask), 0);
        (void) hv_store (hv, "in_cookie", 9, newSVnv (events->val[i].in_cookie), 0);
        (void) hv_store (hv, "in_name", 7, newSVpv (events->val[i].in_name, 0), 0);
        PUSHs (sv_2mortal (newRV ((SV *) hv)));
      }
      guestfs_free_inotify_event_list (events);

void
inotify_files (g)
      guestfs_h *g;
PREINIT:
      char **paths;
      int i, n;
 PPCODE:
      paths = guestfs_inotify_files (g);
      if (paths == NULL)
        croak ("%s", guestfs_last_error (g));
      for (n = 0; paths[n] != NULL; ++n) /**/;
      EXTEND (SP, n);
      for (i = 0; i < n; ++i) {
        PUSHs (sv_2mortal (newSVpv (paths[i], 0)));
        free (paths[i]);
      }
      free (paths);

void
inotify_close (g)
      guestfs_h *g;
PREINIT:
      int r;
 PPCODE:
      r = guestfs_inotify_close (g);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

void
setcon (g, context)
      guestfs_h *g;
      char *context;
PREINIT:
      int r;
 PPCODE:
      r = guestfs_setcon (g, context);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

SV *
getcon (g)
      guestfs_h *g;
PREINIT:
      char *context;
   CODE:
      context = guestfs_getcon (g);
      if (context == NULL)
        croak ("%s", guestfs_last_error (g));
      RETVAL = newSVpv (context, 0);
      free (context);
 OUTPUT:
      RETVAL

void
mkfs_b (g, fstype, blocksize, device)
      guestfs_h *g;
      char *fstype;
      int blocksize;
      char *device;
PREINIT:
      int r;
 PPCODE:
      r = guestfs_mkfs_b (g, fstype, blocksize, device);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

void
mke2journal (g, blocksize, device)
      guestfs_h *g;
      int blocksize;
      char *device;
PREINIT:
      int r;
 PPCODE:
      r = guestfs_mke2journal (g, blocksize, device);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

void
mke2journal_L (g, blocksize, label, device)
      guestfs_h *g;
      int blocksize;
      char *label;
      char *device;
PREINIT:
      int r;
 PPCODE:
      r = guestfs_mke2journal_L (g, blocksize, label, device);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

void
mke2journal_U (g, blocksize, uuid, device)
      guestfs_h *g;
      int blocksize;
      char *uuid;
      char *device;
PREINIT:
      int r;
 PPCODE:
      r = guestfs_mke2journal_U (g, blocksize, uuid, device);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

void
mke2fs_J (g, fstype, blocksize, device, journal)
      guestfs_h *g;
      char *fstype;
      int blocksize;
      char *device;
      char *journal;
PREINIT:
      int r;
 PPCODE:
      r = guestfs_mke2fs_J (g, fstype, blocksize, device, journal);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

void
mke2fs_JL (g, fstype, blocksize, device, label)
      guestfs_h *g;
      char *fstype;
      int blocksize;
      char *device;
      char *label;
PREINIT:
      int r;
 PPCODE:
      r = guestfs_mke2fs_JL (g, fstype, blocksize, device, label);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

void
mke2fs_JU (g, fstype, blocksize, device, uuid)
      guestfs_h *g;
      char *fstype;
      int blocksize;
      char *device;
      char *uuid;
PREINIT:
      int r;
 PPCODE:
      r = guestfs_mke2fs_JU (g, fstype, blocksize, device, uuid);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

void
modprobe (g, modulename)
      guestfs_h *g;
      char *modulename;
PREINIT:
      int r;
 PPCODE:
      r = guestfs_modprobe (g, modulename);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

SV *
echo_daemon (g, words)
      guestfs_h *g;
      char **words;
PREINIT:
      char *output;
   CODE:
      output = guestfs_echo_daemon (g, words);
      free (words);
      if (output == NULL)
        croak ("%s", guestfs_last_error (g));
      RETVAL = newSVpv (output, 0);
      free (output);
 OUTPUT:
      RETVAL

void
find0 (g, directory, files)
      guestfs_h *g;
      char *directory;
      char *files;
PREINIT:
      int r;
 PPCODE:
      r = guestfs_find0 (g, directory, files);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

SV *
case_sensitive_path (g, path)
      guestfs_h *g;
      char *path;
PREINIT:
      char *rpath;
   CODE:
      rpath = guestfs_case_sensitive_path (g, path);
      if (rpath == NULL)
        croak ("%s", guestfs_last_error (g));
      RETVAL = newSVpv (rpath, 0);
      free (rpath);
 OUTPUT:
      RETVAL

SV *
vfs_type (g, device)
      guestfs_h *g;
      char *device;
PREINIT:
      char *fstype;
   CODE:
      fstype = guestfs_vfs_type (g, device);
      if (fstype == NULL)
        croak ("%s", guestfs_last_error (g));
      RETVAL = newSVpv (fstype, 0);
      free (fstype);
 OUTPUT:
      RETVAL

void
truncate (g, path)
      guestfs_h *g;
      char *path;
PREINIT:
      int r;
 PPCODE:
      r = guestfs_truncate (g, path);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

void
truncate_size (g, path, size)
      guestfs_h *g;
      char *path;
      int64_t size;
PREINIT:
      int r;
 PPCODE:
      r = guestfs_truncate_size (g, path, size);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

void
utimens (g, path, atsecs, atnsecs, mtsecs, mtnsecs)
      guestfs_h *g;
      char *path;
      int64_t atsecs;
      int64_t atnsecs;
      int64_t mtsecs;
      int64_t mtnsecs;
PREINIT:
      int r;
 PPCODE:
      r = guestfs_utimens (g, path, atsecs, atnsecs, mtsecs, mtnsecs);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

void
mkdir_mode (g, path, mode)
      guestfs_h *g;
      char *path;
      int mode;
PREINIT:
      int r;
 PPCODE:
      r = guestfs_mkdir_mode (g, path, mode);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

void
lchown (g, owner, group, path)
      guestfs_h *g;
      int owner;
      int group;
      char *path;
PREINIT:
      int r;
 PPCODE:
      r = guestfs_lchown (g, owner, group, path);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

void
lstatlist (g, path, names)
      guestfs_h *g;
      char *path;
      char **names;
PREINIT:
      struct guestfs_stat_list *statbufs;
      int i;
      HV *hv;
 PPCODE:
      statbufs = guestfs_lstatlist (g, path, names);
      free (names);
      if (statbufs == NULL)
        croak ("%s", guestfs_last_error (g));
      EXTEND (SP, statbufs->len);
      for (i = 0; i < statbufs->len; ++i) {
        hv = newHV ();
        (void) hv_store (hv, "dev", 3, my_newSVll (statbufs->val[i].dev), 0);
        (void) hv_store (hv, "ino", 3, my_newSVll (statbufs->val[i].ino), 0);
        (void) hv_store (hv, "mode", 4, my_newSVll (statbufs->val[i].mode), 0);
        (void) hv_store (hv, "nlink", 5, my_newSVll (statbufs->val[i].nlink), 0);
        (void) hv_store (hv, "uid", 3, my_newSVll (statbufs->val[i].uid), 0);
        (void) hv_store (hv, "gid", 3, my_newSVll (statbufs->val[i].gid), 0);
        (void) hv_store (hv, "rdev", 4, my_newSVll (statbufs->val[i].rdev), 0);
        (void) hv_store (hv, "size", 4, my_newSVll (statbufs->val[i].size), 0);
        (void) hv_store (hv, "blksize", 7, my_newSVll (statbufs->val[i].blksize), 0);
        (void) hv_store (hv, "blocks", 6, my_newSVll (statbufs->val[i].blocks), 0);
        (void) hv_store (hv, "atime", 5, my_newSVll (statbufs->val[i].atime), 0);
        (void) hv_store (hv, "mtime", 5, my_newSVll (statbufs->val[i].mtime), 0);
        (void) hv_store (hv, "ctime", 5, my_newSVll (statbufs->val[i].ctime), 0);
        PUSHs (sv_2mortal (newRV ((SV *) hv)));
      }
      guestfs_free_stat_list (statbufs);

void
lxattrlist (g, path, names)
      guestfs_h *g;
      char *path;
      char **names;
PREINIT:
      struct guestfs_xattr_list *xattrs;
      int i;
      HV *hv;
 PPCODE:
      xattrs = guestfs_lxattrlist (g, path, names);
      free (names);
      if (xattrs == NULL)
        croak ("%s", guestfs_last_error (g));
      EXTEND (SP, xattrs->len);
      for (i = 0; i < xattrs->len; ++i) {
        hv = newHV ();
        (void) hv_store (hv, "attrname", 8, newSVpv (xattrs->val[i].attrname, 0), 0);
        (void) hv_store (hv, "attrval", 7, newSVpv (xattrs->val[i].attrval, xattrs->val[i].attrval_len), 0);
        PUSHs (sv_2mortal (newRV ((SV *) hv)));
      }
      guestfs_free_xattr_list (xattrs);

void
readlinklist (g, path, names)
      guestfs_h *g;
      char *path;
      char **names;
PREINIT:
      char **links;
      int i, n;
 PPCODE:
      links = guestfs_readlinklist (g, path, names);
      free (names);
      if (links == NULL)
        croak ("%s", guestfs_last_error (g));
      for (n = 0; links[n] != NULL; ++n) /**/;
      EXTEND (SP, n);
      for (i = 0; i < n; ++i) {
        PUSHs (sv_2mortal (newSVpv (links[i], 0)));
        free (links[i]);
      }
      free (links);

SV *
pread (g, path, count, offset)
      guestfs_h *g;
      char *path;
      int count;
      int64_t offset;
PREINIT:
      char *content;
      size_t size;
   CODE:
      content = guestfs_pread (g, path, count, offset, &size);
      if (content == NULL)
        croak ("%s", guestfs_last_error (g));
      RETVAL = newSVpv (content, size);
      free (content);
 OUTPUT:
      RETVAL

void
part_init (g, device, parttype)
      guestfs_h *g;
      char *device;
      char *parttype;
PREINIT:
      int r;
 PPCODE:
      r = guestfs_part_init (g, device, parttype);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

void
part_add (g, device, prlogex, startsect, endsect)
      guestfs_h *g;
      char *device;
      char *prlogex;
      int64_t startsect;
      int64_t endsect;
PREINIT:
      int r;
 PPCODE:
      r = guestfs_part_add (g, device, prlogex, startsect, endsect);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

void
part_disk (g, device, parttype)
      guestfs_h *g;
      char *device;
      char *parttype;
PREINIT:
      int r;
 PPCODE:
      r = guestfs_part_disk (g, device, parttype);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

void
part_set_bootable (g, device, partnum, bootable)
      guestfs_h *g;
      char *device;
      int partnum;
      int bootable;
PREINIT:
      int r;
 PPCODE:
      r = guestfs_part_set_bootable (g, device, partnum, bootable);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

void
part_set_name (g, device, partnum, name)
      guestfs_h *g;
      char *device;
      int partnum;
      char *name;
PREINIT:
      int r;
 PPCODE:
      r = guestfs_part_set_name (g, device, partnum, name);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

void
part_list (g, device)
      guestfs_h *g;
      char *device;
PREINIT:
      struct guestfs_partition_list *partitions;
      int i;
      HV *hv;
 PPCODE:
      partitions = guestfs_part_list (g, device);
      if (partitions == NULL)
        croak ("%s", guestfs_last_error (g));
      EXTEND (SP, partitions->len);
      for (i = 0; i < partitions->len; ++i) {
        hv = newHV ();
        (void) hv_store (hv, "part_num", 8, newSVnv (partitions->val[i].part_num), 0);
        (void) hv_store (hv, "part_start", 10, my_newSVull (partitions->val[i].part_start), 0);
        (void) hv_store (hv, "part_end", 8, my_newSVull (partitions->val[i].part_end), 0);
        (void) hv_store (hv, "part_size", 9, my_newSVull (partitions->val[i].part_size), 0);
        PUSHs (sv_2mortal (newRV ((SV *) hv)));
      }
      guestfs_free_partition_list (partitions);

SV *
part_get_parttype (g, device)
      guestfs_h *g;
      char *device;
PREINIT:
      char *parttype;
   CODE:
      parttype = guestfs_part_get_parttype (g, device);
      if (parttype == NULL)
        croak ("%s", guestfs_last_error (g));
      RETVAL = newSVpv (parttype, 0);
      free (parttype);
 OUTPUT:
      RETVAL

void
fill (g, c, len, path)
      guestfs_h *g;
      int c;
      int len;
      char *path;
PREINIT:
      int r;
 PPCODE:
      r = guestfs_fill (g, c, len, path);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

void
available (g, groups)
      guestfs_h *g;
      char **groups;
PREINIT:
      int r;
 PPCODE:
      r = guestfs_available (g, groups);
      free (groups);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

void
dd (g, src, dest)
      guestfs_h *g;
      char *src;
      char *dest;
PREINIT:
      int r;
 PPCODE:
      r = guestfs_dd (g, src, dest);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

SV *
filesize (g, file)
      guestfs_h *g;
      char *file;
PREINIT:
      int64_t size;
   CODE:
      size = guestfs_filesize (g, file);
      if (size == -1)
        croak ("%s", guestfs_last_error (g));
      RETVAL = my_newSVll (size);
 OUTPUT:
      RETVAL

void
lvrename (g, logvol, newlogvol)
      guestfs_h *g;
      char *logvol;
      char *newlogvol;
PREINIT:
      int r;
 PPCODE:
      r = guestfs_lvrename (g, logvol, newlogvol);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

void
vgrename (g, volgroup, newvolgroup)
      guestfs_h *g;
      char *volgroup;
      char *newvolgroup;
PREINIT:
      int r;
 PPCODE:
      r = guestfs_vgrename (g, volgroup, newvolgroup);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

SV *
initrd_cat (g, initrdpath, filename)
      guestfs_h *g;
      char *initrdpath;
      char *filename;
PREINIT:
      char *content;
      size_t size;
   CODE:
      content = guestfs_initrd_cat (g, initrdpath, filename, &size);
      if (content == NULL)
        croak ("%s", guestfs_last_error (g));
      RETVAL = newSVpv (content, size);
      free (content);
 OUTPUT:
      RETVAL

