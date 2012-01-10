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

/* http://www.perlmonks.org/?node=338857 */
static void
_event_callback_wrapper (guestfs_h *g,
                         void *cb,
                         uint64_t event,
                         int event_handle,
                         int flags,
                         const char *buf, size_t buf_len,
                         const uint64_t *array, size_t array_len)
{
  dSP;
  ENTER;
  SAVETMPS;
  PUSHMARK (SP);
  XPUSHs (sv_2mortal (my_newSVull (event)));
  XPUSHs (sv_2mortal (newSViv (event_handle)));
  XPUSHs (sv_2mortal (newSVpvn (buf ? buf : "", buf_len)));
  AV *av = newAV ();
  size_t i;
  for (i = 0; i < array_len; ++i)
    av_push (av, my_newSVull (array[i]));
  XPUSHs (sv_2mortal (newRV ((SV *) av)));
  PUTBACK;
  call_sv ((SV *) cb, G_VOID | G_DISCARD | G_EVAL);
  FREETMPS;
  LEAVE;
}

static SV **
get_all_event_callbacks (guestfs_h *g, size_t *len_rtn)
{
  SV **r;
  size_t i;
  const char *key;
  SV *cb;

  /* Count the length of the array that will be needed. */
  *len_rtn = 0;
  cb = guestfs_first_private (g, &key);
  while (cb != NULL) {
    if (strncmp (key, "_perl_event_", strlen ("_perl_event_")) == 0)
      (*len_rtn)++;
    cb = guestfs_next_private (g, &key);
  }

  /* Copy them into the return array. */
  r = guestfs_safe_malloc (g, sizeof (SV *) * (*len_rtn));

  i = 0;
  cb = guestfs_first_private (g, &key);
  while (cb != NULL) {
    if (strncmp (key, "_perl_event_", strlen ("_perl_event_")) == 0) {
      r[i] = cb;
      i++;
    }
    cb = guestfs_next_private (g, &key);
  }

  return r;
}

static void
_close_handle (guestfs_h *g)
{
  size_t i, len;
  SV **cbs;

  assert (g != NULL);

  /* As in the OCaml bindings, there is a hard to solve case where the
   * caller can delete a callback from within the callback, resulting
   * in a double-free here.  XXX
   */
  cbs = get_all_event_callbacks (g, &len);

  guestfs_close (g);

  for (i = 0; i < len; ++i)
    SvREFCNT_dec (cbs[i]);
  free (cbs);
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
DESTROY (sv)
      SV *sv;
 PPCODE:
      /* For the 'g' argument above we do the conversion explicitly and
       * don't rely on the typemap, because if the handle has been
       * explicitly closed we don't want the typemap conversion to
       * display an error.
       */
      HV *hv = (HV *) SvRV (sv);
      SV **svp = hv_fetch (hv, "_g", 2, 0);
      if (svp != NULL) {
        guestfs_h *g = (guestfs_h *) SvIV (*svp);
        _close_handle (g);
      }

void
close (g)
      guestfs_h *g;
 PPCODE:
      _close_handle (g);
      /* Avoid double-free in DESTROY method. */
      HV *hv = (HV *) SvRV (ST(0));
      (void) hv_delete (hv, "_g", 2, G_DISCARD);

SV *
set_event_callback (g, cb, event_bitmask)
      guestfs_h *g;
      SV *cb;
      int event_bitmask;
PREINIT:
      int eh;
      char key[64];
   CODE:
      eh = guestfs_set_event_callback (g, _event_callback_wrapper,
                                       event_bitmask, 0, cb);
      if (eh == -1)
        croak ("%s", guestfs_last_error (g));

      /* Increase the refcount for this callback, since we are storing
       * it in the opaque C libguestfs handle.  We need to remember that
       * we did this, so we can decrease the refcount for all undeleted
       * callbacks left around at close time (see _close_handle).
       */
      SvREFCNT_inc (cb);

      snprintf (key, sizeof key, "_perl_event_%d", eh);
      guestfs_set_private (g, key, cb);

      RETVAL = newSViv (eh);
 OUTPUT:
      RETVAL

void
delete_event_callback (g, event_handle)
      guestfs_h *g;
      int event_handle;
PREINIT:
      char key[64];
      SV *cb;
   CODE:
      snprintf (key, sizeof key, "_perl_event_%d", event_handle);
      cb = guestfs_get_private (g, key);
      if (cb) {
        SvREFCNT_dec (cb);
        guestfs_set_private (g, key, NULL);
        guestfs_delete_event_callback (g, event_handle);
      }

SV *
last_errno (g)
      guestfs_h *g;
PREINIT:
      int errnum;
   CODE:
      errnum = guestfs_last_errno (g);
      RETVAL = newSViv (errnum);
 OUTPUT:
      RETVAL

void
user_cancel (g)
      guestfs_h *g;
 PPCODE:
      guestfs_user_cancel (g);

void
test0 (g, str, optstr, strlist, b, integer, integer64, filein, fileout, bufferin)
      guestfs_h *g;
      char *str;
      char *optstr = SvOK(ST(2)) ? SvPV_nolen(ST(2)) : NULL;
      char **strlist;
      int b;
      int integer;
      int64_t integer64;
      char *filein;
      char *fileout;
      char *bufferin;
      size_t bufferin_size = SvCUR (ST(9));
PREINIT:
      int r;
 PPCODE:
      r = guestfs_test0 (g, str, optstr, strlist, b, integer, integer64, filein, fileout, bufferin, bufferin_size);
      free (strlist);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

SV *
test0rint (g, val)
      guestfs_h *g;
      char *val;
PREINIT:
      int r;
   CODE:
      r = guestfs_test0rint (g, val);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));
      RETVAL = newSViv (r);
 OUTPUT:
      RETVAL

SV *
test0rinterr (g)
      guestfs_h *g;
PREINIT:
      int r;
   CODE:
      r = guestfs_test0rinterr (g);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));
      RETVAL = newSViv (r);
 OUTPUT:
      RETVAL

SV *
test0rint64 (g, val)
      guestfs_h *g;
      char *val;
PREINIT:
      int64_t r;
   CODE:
      r = guestfs_test0rint64 (g, val);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));
      RETVAL = my_newSVll (r);
 OUTPUT:
      RETVAL

SV *
test0rint64err (g)
      guestfs_h *g;
PREINIT:
      int64_t r;
   CODE:
      r = guestfs_test0rint64err (g);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));
      RETVAL = my_newSVll (r);
 OUTPUT:
      RETVAL

SV *
test0rbool (g, val)
      guestfs_h *g;
      char *val;
PREINIT:
      int r;
   CODE:
      r = guestfs_test0rbool (g, val);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));
      RETVAL = newSViv (r);
 OUTPUT:
      RETVAL

SV *
test0rboolerr (g)
      guestfs_h *g;
PREINIT:
      int r;
   CODE:
      r = guestfs_test0rboolerr (g);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));
      RETVAL = newSViv (r);
 OUTPUT:
      RETVAL

SV *
test0rconststring (g, val)
      guestfs_h *g;
      char *val;
PREINIT:
      const char *r;
   CODE:
      r = guestfs_test0rconststring (g, val);
      if (r == NULL)
        croak ("%s", guestfs_last_error (g));
      RETVAL = newSVpv (r, 0);
 OUTPUT:
      RETVAL

SV *
test0rconststringerr (g)
      guestfs_h *g;
PREINIT:
      const char *r;
   CODE:
      r = guestfs_test0rconststringerr (g);
      if (r == NULL)
        croak ("%s", guestfs_last_error (g));
      RETVAL = newSVpv (r, 0);
 OUTPUT:
      RETVAL

SV *
test0rconstoptstring (g, val)
      guestfs_h *g;
      char *val;
PREINIT:
      const char *r;
   CODE:
      r = guestfs_test0rconstoptstring (g, val);
      if (r == NULL)
        RETVAL = &PL_sv_undef;
      else
        RETVAL = newSVpv (r, 0);
 OUTPUT:
      RETVAL

SV *
test0rconstoptstringerr (g)
      guestfs_h *g;
PREINIT:
      const char *r;
   CODE:
      r = guestfs_test0rconstoptstringerr (g);
      if (r == NULL)
        RETVAL = &PL_sv_undef;
      else
        RETVAL = newSVpv (r, 0);
 OUTPUT:
      RETVAL

SV *
test0rstring (g, val)
      guestfs_h *g;
      char *val;
PREINIT:
      char *r;
   CODE:
      r = guestfs_test0rstring (g, val);
      if (r == NULL)
        croak ("%s", guestfs_last_error (g));
      RETVAL = newSVpv (r, 0);
      free (r);
 OUTPUT:
      RETVAL

SV *
test0rstringerr (g)
      guestfs_h *g;
PREINIT:
      char *r;
   CODE:
      r = guestfs_test0rstringerr (g);
      if (r == NULL)
        croak ("%s", guestfs_last_error (g));
      RETVAL = newSVpv (r, 0);
      free (r);
 OUTPUT:
      RETVAL

void
test0rstringlist (g, val)
      guestfs_h *g;
      char *val;
PREINIT:
      char **r;
      size_t i, n;
 PPCODE:
      r = guestfs_test0rstringlist (g, val);
      if (r == NULL)
        croak ("%s", guestfs_last_error (g));
      for (n = 0; r[n] != NULL; ++n) /**/;
      EXTEND (SP, n);
      for (i = 0; i < n; ++i) {
        PUSHs (sv_2mortal (newSVpv (r[i], 0)));
        free (r[i]);
      }
      free (r);

void
test0rstringlisterr (g)
      guestfs_h *g;
PREINIT:
      char **r;
      size_t i, n;
 PPCODE:
      r = guestfs_test0rstringlisterr (g);
      if (r == NULL)
        croak ("%s", guestfs_last_error (g));
      for (n = 0; r[n] != NULL; ++n) /**/;
      EXTEND (SP, n);
      for (i = 0; i < n; ++i) {
        PUSHs (sv_2mortal (newSVpv (r[i], 0)));
        free (r[i]);
      }
      free (r);

void
test0rstruct (g, val)
      guestfs_h *g;
      char *val;
PREINIT:
      struct guestfs_lvm_pv *r;
 PPCODE:
      r = guestfs_test0rstruct (g, val);
      if (r == NULL)
        croak ("%s", guestfs_last_error (g));
      EXTEND (SP, 2 * 14);
      PUSHs (sv_2mortal (newSVpv ("pv_name", 0)));
      PUSHs (sv_2mortal (newSVpv (r->pv_name, 0)));
      PUSHs (sv_2mortal (newSVpv ("pv_uuid", 0)));
      PUSHs (sv_2mortal (newSVpv (r->pv_uuid, 32)));
      PUSHs (sv_2mortal (newSVpv ("pv_fmt", 0)));
      PUSHs (sv_2mortal (newSVpv (r->pv_fmt, 0)));
      PUSHs (sv_2mortal (newSVpv ("pv_size", 0)));
      PUSHs (sv_2mortal (my_newSVull (r->pv_size)));
      PUSHs (sv_2mortal (newSVpv ("dev_size", 0)));
      PUSHs (sv_2mortal (my_newSVull (r->dev_size)));
      PUSHs (sv_2mortal (newSVpv ("pv_free", 0)));
      PUSHs (sv_2mortal (my_newSVull (r->pv_free)));
      PUSHs (sv_2mortal (newSVpv ("pv_used", 0)));
      PUSHs (sv_2mortal (my_newSVull (r->pv_used)));
      PUSHs (sv_2mortal (newSVpv ("pv_attr", 0)));
      PUSHs (sv_2mortal (newSVpv (r->pv_attr, 0)));
      PUSHs (sv_2mortal (newSVpv ("pv_pe_count", 0)));
      PUSHs (sv_2mortal (my_newSVll (r->pv_pe_count)));
      PUSHs (sv_2mortal (newSVpv ("pv_pe_alloc_count", 0)));
      PUSHs (sv_2mortal (my_newSVll (r->pv_pe_alloc_count)));
      PUSHs (sv_2mortal (newSVpv ("pv_tags", 0)));
      PUSHs (sv_2mortal (newSVpv (r->pv_tags, 0)));
      PUSHs (sv_2mortal (newSVpv ("pe_start", 0)));
      PUSHs (sv_2mortal (my_newSVull (r->pe_start)));
      PUSHs (sv_2mortal (newSVpv ("pv_mda_count", 0)));
      PUSHs (sv_2mortal (my_newSVll (r->pv_mda_count)));
      PUSHs (sv_2mortal (newSVpv ("pv_mda_free", 0)));
      PUSHs (sv_2mortal (my_newSVull (r->pv_mda_free)));
      free (r);

void
test0rstructerr (g)
      guestfs_h *g;
PREINIT:
      struct guestfs_lvm_pv *r;
 PPCODE:
      r = guestfs_test0rstructerr (g);
      if (r == NULL)
        croak ("%s", guestfs_last_error (g));
      EXTEND (SP, 2 * 14);
      PUSHs (sv_2mortal (newSVpv ("pv_name", 0)));
      PUSHs (sv_2mortal (newSVpv (r->pv_name, 0)));
      PUSHs (sv_2mortal (newSVpv ("pv_uuid", 0)));
      PUSHs (sv_2mortal (newSVpv (r->pv_uuid, 32)));
      PUSHs (sv_2mortal (newSVpv ("pv_fmt", 0)));
      PUSHs (sv_2mortal (newSVpv (r->pv_fmt, 0)));
      PUSHs (sv_2mortal (newSVpv ("pv_size", 0)));
      PUSHs (sv_2mortal (my_newSVull (r->pv_size)));
      PUSHs (sv_2mortal (newSVpv ("dev_size", 0)));
      PUSHs (sv_2mortal (my_newSVull (r->dev_size)));
      PUSHs (sv_2mortal (newSVpv ("pv_free", 0)));
      PUSHs (sv_2mortal (my_newSVull (r->pv_free)));
      PUSHs (sv_2mortal (newSVpv ("pv_used", 0)));
      PUSHs (sv_2mortal (my_newSVull (r->pv_used)));
      PUSHs (sv_2mortal (newSVpv ("pv_attr", 0)));
      PUSHs (sv_2mortal (newSVpv (r->pv_attr, 0)));
      PUSHs (sv_2mortal (newSVpv ("pv_pe_count", 0)));
      PUSHs (sv_2mortal (my_newSVll (r->pv_pe_count)));
      PUSHs (sv_2mortal (newSVpv ("pv_pe_alloc_count", 0)));
      PUSHs (sv_2mortal (my_newSVll (r->pv_pe_alloc_count)));
      PUSHs (sv_2mortal (newSVpv ("pv_tags", 0)));
      PUSHs (sv_2mortal (newSVpv (r->pv_tags, 0)));
      PUSHs (sv_2mortal (newSVpv ("pe_start", 0)));
      PUSHs (sv_2mortal (my_newSVull (r->pe_start)));
      PUSHs (sv_2mortal (newSVpv ("pv_mda_count", 0)));
      PUSHs (sv_2mortal (my_newSVll (r->pv_mda_count)));
      PUSHs (sv_2mortal (newSVpv ("pv_mda_free", 0)));
      PUSHs (sv_2mortal (my_newSVull (r->pv_mda_free)));
      free (r);

void
test0rstructlist (g, val)
      guestfs_h *g;
      char *val;
PREINIT:
      struct guestfs_lvm_pv_list *r;
      size_t i;
      HV *hv;
 PPCODE:
      r = guestfs_test0rstructlist (g, val);
      if (r == NULL)
        croak ("%s", guestfs_last_error (g));
      EXTEND (SP, r->len);
      for (i = 0; i < r->len; ++i) {
        hv = newHV ();
        (void) hv_store (hv, "pv_name", 7, newSVpv (r->val[i].pv_name, 0), 0);
        (void) hv_store (hv, "pv_uuid", 7, newSVpv (r->val[i].pv_uuid, 32), 0);
        (void) hv_store (hv, "pv_fmt", 6, newSVpv (r->val[i].pv_fmt, 0), 0);
        (void) hv_store (hv, "pv_size", 7, my_newSVull (r->val[i].pv_size), 0);
        (void) hv_store (hv, "dev_size", 8, my_newSVull (r->val[i].dev_size), 0);
        (void) hv_store (hv, "pv_free", 7, my_newSVull (r->val[i].pv_free), 0);
        (void) hv_store (hv, "pv_used", 7, my_newSVull (r->val[i].pv_used), 0);
        (void) hv_store (hv, "pv_attr", 7, newSVpv (r->val[i].pv_attr, 0), 0);
        (void) hv_store (hv, "pv_pe_count", 11, my_newSVll (r->val[i].pv_pe_count), 0);
        (void) hv_store (hv, "pv_pe_alloc_count", 17, my_newSVll (r->val[i].pv_pe_alloc_count), 0);
        (void) hv_store (hv, "pv_tags", 7, newSVpv (r->val[i].pv_tags, 0), 0);
        (void) hv_store (hv, "pe_start", 8, my_newSVull (r->val[i].pe_start), 0);
        (void) hv_store (hv, "pv_mda_count", 12, my_newSVll (r->val[i].pv_mda_count), 0);
        (void) hv_store (hv, "pv_mda_free", 11, my_newSVull (r->val[i].pv_mda_free), 0);
        PUSHs (sv_2mortal (newRV ((SV *) hv)));
      }
      guestfs_free_lvm_pv_list (r);

void
test0rstructlisterr (g)
      guestfs_h *g;
PREINIT:
      struct guestfs_lvm_pv_list *r;
      size_t i;
      HV *hv;
 PPCODE:
      r = guestfs_test0rstructlisterr (g);
      if (r == NULL)
        croak ("%s", guestfs_last_error (g));
      EXTEND (SP, r->len);
      for (i = 0; i < r->len; ++i) {
        hv = newHV ();
        (void) hv_store (hv, "pv_name", 7, newSVpv (r->val[i].pv_name, 0), 0);
        (void) hv_store (hv, "pv_uuid", 7, newSVpv (r->val[i].pv_uuid, 32), 0);
        (void) hv_store (hv, "pv_fmt", 6, newSVpv (r->val[i].pv_fmt, 0), 0);
        (void) hv_store (hv, "pv_size", 7, my_newSVull (r->val[i].pv_size), 0);
        (void) hv_store (hv, "dev_size", 8, my_newSVull (r->val[i].dev_size), 0);
        (void) hv_store (hv, "pv_free", 7, my_newSVull (r->val[i].pv_free), 0);
        (void) hv_store (hv, "pv_used", 7, my_newSVull (r->val[i].pv_used), 0);
        (void) hv_store (hv, "pv_attr", 7, newSVpv (r->val[i].pv_attr, 0), 0);
        (void) hv_store (hv, "pv_pe_count", 11, my_newSVll (r->val[i].pv_pe_count), 0);
        (void) hv_store (hv, "pv_pe_alloc_count", 17, my_newSVll (r->val[i].pv_pe_alloc_count), 0);
        (void) hv_store (hv, "pv_tags", 7, newSVpv (r->val[i].pv_tags, 0), 0);
        (void) hv_store (hv, "pe_start", 8, my_newSVull (r->val[i].pe_start), 0);
        (void) hv_store (hv, "pv_mda_count", 12, my_newSVll (r->val[i].pv_mda_count), 0);
        (void) hv_store (hv, "pv_mda_free", 11, my_newSVull (r->val[i].pv_mda_free), 0);
        PUSHs (sv_2mortal (newRV ((SV *) hv)));
      }
      guestfs_free_lvm_pv_list (r);

void
test0rhashtable (g, val)
      guestfs_h *g;
      char *val;
PREINIT:
      char **r;
      size_t i, n;
 PPCODE:
      r = guestfs_test0rhashtable (g, val);
      if (r == NULL)
        croak ("%s", guestfs_last_error (g));
      for (n = 0; r[n] != NULL; ++n) /**/;
      EXTEND (SP, n);
      for (i = 0; i < n; ++i) {
        PUSHs (sv_2mortal (newSVpv (r[i], 0)));
        free (r[i]);
      }
      free (r);

void
test0rhashtableerr (g)
      guestfs_h *g;
PREINIT:
      char **r;
      size_t i, n;
 PPCODE:
      r = guestfs_test0rhashtableerr (g);
      if (r == NULL)
        croak ("%s", guestfs_last_error (g));
      for (n = 0; r[n] != NULL; ++n) /**/;
      EXTEND (SP, n);
      for (i = 0; i < n; ++i) {
        PUSHs (sv_2mortal (newSVpv (r[i], 0)));
        free (r[i]);
      }
      free (r);

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
      char *qemu = SvOK(ST(1)) ? SvPV_nolen(ST(1)) : NULL;
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
      const char *r;
   CODE:
      r = guestfs_get_qemu (g);
      if (r == NULL)
        croak ("%s", guestfs_last_error (g));
      RETVAL = newSVpv (r, 0);
 OUTPUT:
      RETVAL

void
set_path (g, searchpath)
      guestfs_h *g;
      char *searchpath = SvOK(ST(1)) ? SvPV_nolen(ST(1)) : NULL;
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
      const char *r;
   CODE:
      r = guestfs_get_path (g);
      if (r == NULL)
        croak ("%s", guestfs_last_error (g));
      RETVAL = newSVpv (r, 0);
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
      const char *r;
   CODE:
      r = guestfs_get_append (g);
      if (r == NULL)
        RETVAL = &PL_sv_undef;
      else
        RETVAL = newSVpv (r, 0);
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
      int r;
   CODE:
      r = guestfs_get_autosync (g);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));
      RETVAL = newSViv (r);
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
      int r;
   CODE:
      r = guestfs_get_verbose (g);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));
      RETVAL = newSViv (r);
 OUTPUT:
      RETVAL

SV *
is_ready (g)
      guestfs_h *g;
PREINIT:
      int r;
   CODE:
      r = guestfs_is_ready (g);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));
      RETVAL = newSViv (r);
 OUTPUT:
      RETVAL

SV *
is_config (g)
      guestfs_h *g;
PREINIT:
      int r;
   CODE:
      r = guestfs_is_config (g);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));
      RETVAL = newSViv (r);
 OUTPUT:
      RETVAL

SV *
is_launching (g)
      guestfs_h *g;
PREINIT:
      int r;
   CODE:
      r = guestfs_is_launching (g);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));
      RETVAL = newSViv (r);
 OUTPUT:
      RETVAL

SV *
is_busy (g)
      guestfs_h *g;
PREINIT:
      int r;
   CODE:
      r = guestfs_is_busy (g);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));
      RETVAL = newSViv (r);
 OUTPUT:
      RETVAL

SV *
get_state (g)
      guestfs_h *g;
PREINIT:
      int r;
   CODE:
      r = guestfs_get_state (g);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));
      RETVAL = newSViv (r);
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
      int r;
   CODE:
      r = guestfs_get_memsize (g);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));
      RETVAL = newSViv (r);
 OUTPUT:
      RETVAL

SV *
get_pid (g)
      guestfs_h *g;
PREINIT:
      int r;
   CODE:
      r = guestfs_get_pid (g);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));
      RETVAL = newSViv (r);
 OUTPUT:
      RETVAL

void
version (g)
      guestfs_h *g;
PREINIT:
      struct guestfs_version *r;
 PPCODE:
      r = guestfs_version (g);
      if (r == NULL)
        croak ("%s", guestfs_last_error (g));
      EXTEND (SP, 2 * 4);
      PUSHs (sv_2mortal (newSVpv ("major", 0)));
      PUSHs (sv_2mortal (my_newSVll (r->major)));
      PUSHs (sv_2mortal (newSVpv ("minor", 0)));
      PUSHs (sv_2mortal (my_newSVll (r->minor)));
      PUSHs (sv_2mortal (newSVpv ("release", 0)));
      PUSHs (sv_2mortal (my_newSVll (r->release)));
      PUSHs (sv_2mortal (newSVpv ("extra", 0)));
      PUSHs (sv_2mortal (newSVpv (r->extra, 0)));
      free (r);

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
      int r;
   CODE:
      r = guestfs_get_selinux (g);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));
      RETVAL = newSViv (r);
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
      int r;
   CODE:
      r = guestfs_get_trace (g);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));
      RETVAL = newSViv (r);
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
      int r;
   CODE:
      r = guestfs_get_direct (g);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));
      RETVAL = newSViv (r);
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
      int r;
   CODE:
      r = guestfs_get_recovery_proc (g);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));
      RETVAL = newSViv (r);
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

SV *
file_architecture (g, filename)
      guestfs_h *g;
      char *filename;
PREINIT:
      char *r;
   CODE:
      r = guestfs_file_architecture (g, filename);
      if (r == NULL)
        croak ("%s", guestfs_last_error (g));
      RETVAL = newSVpv (r, 0);
      free (r);
 OUTPUT:
      RETVAL

void
inspect_os (g)
      guestfs_h *g;
PREINIT:
      char **r;
      size_t i, n;
 PPCODE:
      r = guestfs_inspect_os (g);
      if (r == NULL)
        croak ("%s", guestfs_last_error (g));
      for (n = 0; r[n] != NULL; ++n) /**/;
      EXTEND (SP, n);
      for (i = 0; i < n; ++i) {
        PUSHs (sv_2mortal (newSVpv (r[i], 0)));
        free (r[i]);
      }
      free (r);

SV *
inspect_get_type (g, root)
      guestfs_h *g;
      char *root;
PREINIT:
      char *r;
   CODE:
      r = guestfs_inspect_get_type (g, root);
      if (r == NULL)
        croak ("%s", guestfs_last_error (g));
      RETVAL = newSVpv (r, 0);
      free (r);
 OUTPUT:
      RETVAL

SV *
inspect_get_arch (g, root)
      guestfs_h *g;
      char *root;
PREINIT:
      char *r;
   CODE:
      r = guestfs_inspect_get_arch (g, root);
      if (r == NULL)
        croak ("%s", guestfs_last_error (g));
      RETVAL = newSVpv (r, 0);
      free (r);
 OUTPUT:
      RETVAL

SV *
inspect_get_distro (g, root)
      guestfs_h *g;
      char *root;
PREINIT:
      char *r;
   CODE:
      r = guestfs_inspect_get_distro (g, root);
      if (r == NULL)
        croak ("%s", guestfs_last_error (g));
      RETVAL = newSVpv (r, 0);
      free (r);
 OUTPUT:
      RETVAL

SV *
inspect_get_major_version (g, root)
      guestfs_h *g;
      char *root;
PREINIT:
      int r;
   CODE:
      r = guestfs_inspect_get_major_version (g, root);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));
      RETVAL = newSViv (r);
 OUTPUT:
      RETVAL

SV *
inspect_get_minor_version (g, root)
      guestfs_h *g;
      char *root;
PREINIT:
      int r;
   CODE:
      r = guestfs_inspect_get_minor_version (g, root);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));
      RETVAL = newSViv (r);
 OUTPUT:
      RETVAL

SV *
inspect_get_product_name (g, root)
      guestfs_h *g;
      char *root;
PREINIT:
      char *r;
   CODE:
      r = guestfs_inspect_get_product_name (g, root);
      if (r == NULL)
        croak ("%s", guestfs_last_error (g));
      RETVAL = newSVpv (r, 0);
      free (r);
 OUTPUT:
      RETVAL

void
inspect_get_mountpoints (g, root)
      guestfs_h *g;
      char *root;
PREINIT:
      char **r;
      size_t i, n;
 PPCODE:
      r = guestfs_inspect_get_mountpoints (g, root);
      if (r == NULL)
        croak ("%s", guestfs_last_error (g));
      for (n = 0; r[n] != NULL; ++n) /**/;
      EXTEND (SP, n);
      for (i = 0; i < n; ++i) {
        PUSHs (sv_2mortal (newSVpv (r[i], 0)));
        free (r[i]);
      }
      free (r);

void
inspect_get_filesystems (g, root)
      guestfs_h *g;
      char *root;
PREINIT:
      char **r;
      size_t i, n;
 PPCODE:
      r = guestfs_inspect_get_filesystems (g, root);
      if (r == NULL)
        croak ("%s", guestfs_last_error (g));
      for (n = 0; r[n] != NULL; ++n) /**/;
      EXTEND (SP, n);
      for (i = 0; i < n; ++i) {
        PUSHs (sv_2mortal (newSVpv (r[i], 0)));
        free (r[i]);
      }
      free (r);

void
set_network (g, network)
      guestfs_h *g;
      int network;
PREINIT:
      int r;
 PPCODE:
      r = guestfs_set_network (g, network);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

SV *
get_network (g)
      guestfs_h *g;
PREINIT:
      int r;
   CODE:
      r = guestfs_get_network (g);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));
      RETVAL = newSViv (r);
 OUTPUT:
      RETVAL

void
list_filesystems (g)
      guestfs_h *g;
PREINIT:
      char **r;
      size_t i, n;
 PPCODE:
      r = guestfs_list_filesystems (g);
      if (r == NULL)
        croak ("%s", guestfs_last_error (g));
      for (n = 0; r[n] != NULL; ++n) /**/;
      EXTEND (SP, n);
      for (i = 0; i < n; ++i) {
        PUSHs (sv_2mortal (newSVpv (r[i], 0)));
        free (r[i]);
      }
      free (r);

void
add_drive_opts (g, filename, ...)
      guestfs_h *g;
      char *filename;
PREINIT:
      int r;
      struct guestfs_add_drive_opts_argv optargs_s = { .bitmask = 0 };
      struct guestfs_add_drive_opts_argv *optargs = &optargs_s;
      size_t items_i;
 PPCODE:
      if (((items - 2) & 1) != 0)
        croak ("expecting an even number of extra parameters");
      for (items_i = 2; items_i < items; items_i += 2) {
        uint64_t this_mask;
        const char *this_arg;

        this_arg = SvPV_nolen (ST (items_i));
        if (strcmp (this_arg, "readonly") == 0) {
          optargs_s.readonly = SvIV (ST (items_i+1));
          this_mask = GUESTFS_ADD_DRIVE_OPTS_READONLY_BITMASK;
        }
        else if (strcmp (this_arg, "format") == 0) {
          optargs_s.format = SvPV_nolen (ST (items_i+1));
          this_mask = GUESTFS_ADD_DRIVE_OPTS_FORMAT_BITMASK;
        }
        else if (strcmp (this_arg, "iface") == 0) {
          optargs_s.iface = SvPV_nolen (ST (items_i+1));
          this_mask = GUESTFS_ADD_DRIVE_OPTS_IFACE_BITMASK;
        }
        else if (strcmp (this_arg, "name") == 0) {
          optargs_s.name = SvPV_nolen (ST (items_i+1));
          this_mask = GUESTFS_ADD_DRIVE_OPTS_NAME_BITMASK;
        }
        else croak ("unknown optional argument '%s'", this_arg);
        if (optargs_s.bitmask & this_mask)
          croak ("optional argument '%s' given twice",
                 this_arg);
        optargs_s.bitmask |= this_mask;
      }

      r = guestfs_add_drive_opts_argv (g, filename, optargs);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

SV *
inspect_get_windows_systemroot (g, root)
      guestfs_h *g;
      char *root;
PREINIT:
      char *r;
   CODE:
      r = guestfs_inspect_get_windows_systemroot (g, root);
      if (r == NULL)
        croak ("%s", guestfs_last_error (g));
      RETVAL = newSVpv (r, 0);
      free (r);
 OUTPUT:
      RETVAL

void
inspect_get_roots (g)
      guestfs_h *g;
PREINIT:
      char **r;
      size_t i, n;
 PPCODE:
      r = guestfs_inspect_get_roots (g);
      if (r == NULL)
        croak ("%s", guestfs_last_error (g));
      for (n = 0; r[n] != NULL; ++n) /**/;
      EXTEND (SP, n);
      for (i = 0; i < n; ++i) {
        PUSHs (sv_2mortal (newSVpv (r[i], 0)));
        free (r[i]);
      }
      free (r);

void
debug_cmdline (g)
      guestfs_h *g;
PREINIT:
      char **r;
      size_t i, n;
 PPCODE:
      r = guestfs_debug_cmdline (g);
      if (r == NULL)
        croak ("%s", guestfs_last_error (g));
      for (n = 0; r[n] != NULL; ++n) /**/;
      EXTEND (SP, n);
      for (i = 0; i < n; ++i) {
        PUSHs (sv_2mortal (newSVpv (r[i], 0)));
        free (r[i]);
      }
      free (r);

void
debug_drives (g)
      guestfs_h *g;
PREINIT:
      char **r;
      size_t i, n;
 PPCODE:
      r = guestfs_debug_drives (g);
      if (r == NULL)
        croak ("%s", guestfs_last_error (g));
      for (n = 0; r[n] != NULL; ++n) /**/;
      EXTEND (SP, n);
      for (i = 0; i < n; ++i) {
        PUSHs (sv_2mortal (newSVpv (r[i], 0)));
        free (r[i]);
      }
      free (r);

SV *
add_domain (g, dom, ...)
      guestfs_h *g;
      char *dom;
PREINIT:
      int r;
      struct guestfs_add_domain_argv optargs_s = { .bitmask = 0 };
      struct guestfs_add_domain_argv *optargs = &optargs_s;
      size_t items_i;
   CODE:
      if (((items - 2) & 1) != 0)
        croak ("expecting an even number of extra parameters");
      for (items_i = 2; items_i < items; items_i += 2) {
        uint64_t this_mask;
        const char *this_arg;

        this_arg = SvPV_nolen (ST (items_i));
        if (strcmp (this_arg, "libvirturi") == 0) {
          optargs_s.libvirturi = SvPV_nolen (ST (items_i+1));
          this_mask = GUESTFS_ADD_DOMAIN_LIBVIRTURI_BITMASK;
        }
        else if (strcmp (this_arg, "readonly") == 0) {
          optargs_s.readonly = SvIV (ST (items_i+1));
          this_mask = GUESTFS_ADD_DOMAIN_READONLY_BITMASK;
        }
        else if (strcmp (this_arg, "iface") == 0) {
          optargs_s.iface = SvPV_nolen (ST (items_i+1));
          this_mask = GUESTFS_ADD_DOMAIN_IFACE_BITMASK;
        }
        else if (strcmp (this_arg, "live") == 0) {
          optargs_s.live = SvIV (ST (items_i+1));
          this_mask = GUESTFS_ADD_DOMAIN_LIVE_BITMASK;
        }
        else if (strcmp (this_arg, "allowuuid") == 0) {
          optargs_s.allowuuid = SvIV (ST (items_i+1));
          this_mask = GUESTFS_ADD_DOMAIN_ALLOWUUID_BITMASK;
        }
        else if (strcmp (this_arg, "readonlydisk") == 0) {
          optargs_s.readonlydisk = SvPV_nolen (ST (items_i+1));
          this_mask = GUESTFS_ADD_DOMAIN_READONLYDISK_BITMASK;
        }
        else croak ("unknown optional argument '%s'", this_arg);
        if (optargs_s.bitmask & this_mask)
          croak ("optional argument '%s' given twice",
                 this_arg);
        optargs_s.bitmask |= this_mask;
      }

      r = guestfs_add_domain_argv (g, dom, optargs);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));
      RETVAL = newSViv (r);
 OUTPUT:
      RETVAL

SV *
inspect_get_package_format (g, root)
      guestfs_h *g;
      char *root;
PREINIT:
      char *r;
   CODE:
      r = guestfs_inspect_get_package_format (g, root);
      if (r == NULL)
        croak ("%s", guestfs_last_error (g));
      RETVAL = newSVpv (r, 0);
      free (r);
 OUTPUT:
      RETVAL

SV *
inspect_get_package_management (g, root)
      guestfs_h *g;
      char *root;
PREINIT:
      char *r;
   CODE:
      r = guestfs_inspect_get_package_management (g, root);
      if (r == NULL)
        croak ("%s", guestfs_last_error (g));
      RETVAL = newSVpv (r, 0);
      free (r);
 OUTPUT:
      RETVAL

void
inspect_list_applications (g, root)
      guestfs_h *g;
      char *root;
PREINIT:
      struct guestfs_application_list *r;
      size_t i;
      HV *hv;
 PPCODE:
      r = guestfs_inspect_list_applications (g, root);
      if (r == NULL)
        croak ("%s", guestfs_last_error (g));
      EXTEND (SP, r->len);
      for (i = 0; i < r->len; ++i) {
        hv = newHV ();
        (void) hv_store (hv, "app_name", 8, newSVpv (r->val[i].app_name, 0), 0);
        (void) hv_store (hv, "app_display_name", 16, newSVpv (r->val[i].app_display_name, 0), 0);
        (void) hv_store (hv, "app_epoch", 9, newSVnv (r->val[i].app_epoch), 0);
        (void) hv_store (hv, "app_version", 11, newSVpv (r->val[i].app_version, 0), 0);
        (void) hv_store (hv, "app_release", 11, newSVpv (r->val[i].app_release, 0), 0);
        (void) hv_store (hv, "app_install_path", 16, newSVpv (r->val[i].app_install_path, 0), 0);
        (void) hv_store (hv, "app_trans_path", 14, newSVpv (r->val[i].app_trans_path, 0), 0);
        (void) hv_store (hv, "app_publisher", 13, newSVpv (r->val[i].app_publisher, 0), 0);
        (void) hv_store (hv, "app_url", 7, newSVpv (r->val[i].app_url, 0), 0);
        (void) hv_store (hv, "app_source_package", 18, newSVpv (r->val[i].app_source_package, 0), 0);
        (void) hv_store (hv, "app_summary", 11, newSVpv (r->val[i].app_summary, 0), 0);
        (void) hv_store (hv, "app_description", 15, newSVpv (r->val[i].app_description, 0), 0);
        PUSHs (sv_2mortal (newRV ((SV *) hv)));
      }
      guestfs_free_application_list (r);

SV *
inspect_get_hostname (g, root)
      guestfs_h *g;
      char *root;
PREINIT:
      char *r;
   CODE:
      r = guestfs_inspect_get_hostname (g, root);
      if (r == NULL)
        croak ("%s", guestfs_last_error (g));
      RETVAL = newSVpv (r, 0);
      free (r);
 OUTPUT:
      RETVAL

SV *
inspect_get_format (g, root)
      guestfs_h *g;
      char *root;
PREINIT:
      char *r;
   CODE:
      r = guestfs_inspect_get_format (g, root);
      if (r == NULL)
        croak ("%s", guestfs_last_error (g));
      RETVAL = newSVpv (r, 0);
      free (r);
 OUTPUT:
      RETVAL

SV *
inspect_is_live (g, root)
      guestfs_h *g;
      char *root;
PREINIT:
      int r;
   CODE:
      r = guestfs_inspect_is_live (g, root);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));
      RETVAL = newSViv (r);
 OUTPUT:
      RETVAL

SV *
inspect_is_netinst (g, root)
      guestfs_h *g;
      char *root;
PREINIT:
      int r;
   CODE:
      r = guestfs_inspect_is_netinst (g, root);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));
      RETVAL = newSViv (r);
 OUTPUT:
      RETVAL

SV *
inspect_is_multipart (g, root)
      guestfs_h *g;
      char *root;
PREINIT:
      int r;
   CODE:
      r = guestfs_inspect_is_multipart (g, root);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));
      RETVAL = newSViv (r);
 OUTPUT:
      RETVAL

void
set_attach_method (g, attachmethod)
      guestfs_h *g;
      char *attachmethod;
PREINIT:
      int r;
 PPCODE:
      r = guestfs_set_attach_method (g, attachmethod);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

SV *
get_attach_method (g)
      guestfs_h *g;
PREINIT:
      char *r;
   CODE:
      r = guestfs_get_attach_method (g);
      if (r == NULL)
        croak ("%s", guestfs_last_error (g));
      RETVAL = newSVpv (r, 0);
      free (r);
 OUTPUT:
      RETVAL

SV *
inspect_get_product_variant (g, root)
      guestfs_h *g;
      char *root;
PREINIT:
      char *r;
   CODE:
      r = guestfs_inspect_get_product_variant (g, root);
      if (r == NULL)
        croak ("%s", guestfs_last_error (g));
      RETVAL = newSVpv (r, 0);
      free (r);
 OUTPUT:
      RETVAL

SV *
inspect_get_windows_current_control_set (g, root)
      guestfs_h *g;
      char *root;
PREINIT:
      char *r;
   CODE:
      r = guestfs_inspect_get_windows_current_control_set (g, root);
      if (r == NULL)
        croak ("%s", guestfs_last_error (g));
      RETVAL = newSVpv (r, 0);
      free (r);
 OUTPUT:
      RETVAL

void
inspect_get_drive_mappings (g, root)
      guestfs_h *g;
      char *root;
PREINIT:
      char **r;
      size_t i, n;
 PPCODE:
      r = guestfs_inspect_get_drive_mappings (g, root);
      if (r == NULL)
        croak ("%s", guestfs_last_error (g));
      for (n = 0; r[n] != NULL; ++n) /**/;
      EXTEND (SP, n);
      for (i = 0; i < n; ++i) {
        PUSHs (sv_2mortal (newSVpv (r[i], 0)));
        free (r[i]);
      }
      free (r);

SV *
inspect_get_icon (g, root, ...)
      guestfs_h *g;
      char *root;
PREINIT:
      char *r;
      size_t size;
      struct guestfs_inspect_get_icon_argv optargs_s = { .bitmask = 0 };
      struct guestfs_inspect_get_icon_argv *optargs = &optargs_s;
      size_t items_i;
   CODE:
      if (((items - 2) & 1) != 0)
        croak ("expecting an even number of extra parameters");
      for (items_i = 2; items_i < items; items_i += 2) {
        uint64_t this_mask;
        const char *this_arg;

        this_arg = SvPV_nolen (ST (items_i));
        if (strcmp (this_arg, "favicon") == 0) {
          optargs_s.favicon = SvIV (ST (items_i+1));
          this_mask = GUESTFS_INSPECT_GET_ICON_FAVICON_BITMASK;
        }
        else if (strcmp (this_arg, "highquality") == 0) {
          optargs_s.highquality = SvIV (ST (items_i+1));
          this_mask = GUESTFS_INSPECT_GET_ICON_HIGHQUALITY_BITMASK;
        }
        else croak ("unknown optional argument '%s'", this_arg);
        if (optargs_s.bitmask & this_mask)
          croak ("optional argument '%s' given twice",
                 this_arg);
        optargs_s.bitmask |= this_mask;
      }

      r = guestfs_inspect_get_icon_argv (g, root, &size, optargs);
      if (r == NULL)
        croak ("%s", guestfs_last_error (g));
      RETVAL = newSVpvn (r, size);
      free (r);
 OUTPUT:
      RETVAL

void
set_pgroup (g, pgroup)
      guestfs_h *g;
      int pgroup;
PREINIT:
      int r;
 PPCODE:
      r = guestfs_set_pgroup (g, pgroup);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

SV *
get_pgroup (g)
      guestfs_h *g;
PREINIT:
      int r;
   CODE:
      r = guestfs_get_pgroup (g);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));
      RETVAL = newSViv (r);
 OUTPUT:
      RETVAL

void
set_smp (g, smp)
      guestfs_h *g;
      int smp;
PREINIT:
      int r;
 PPCODE:
      r = guestfs_set_smp (g, smp);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

SV *
get_smp (g)
      guestfs_h *g;
PREINIT:
      int r;
   CODE:
      r = guestfs_get_smp (g);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));
      RETVAL = newSViv (r);
 OUTPUT:
      RETVAL

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
      char *r;
   CODE:
      r = guestfs_cat (g, path);
      if (r == NULL)
        croak ("%s", guestfs_last_error (g));
      RETVAL = newSVpv (r, 0);
      free (r);
 OUTPUT:
      RETVAL

SV *
ll (g, directory)
      guestfs_h *g;
      char *directory;
PREINIT:
      char *r;
   CODE:
      r = guestfs_ll (g, directory);
      if (r == NULL)
        croak ("%s", guestfs_last_error (g));
      RETVAL = newSVpv (r, 0);
      free (r);
 OUTPUT:
      RETVAL

void
ls (g, directory)
      guestfs_h *g;
      char *directory;
PREINIT:
      char **r;
      size_t i, n;
 PPCODE:
      r = guestfs_ls (g, directory);
      if (r == NULL)
        croak ("%s", guestfs_last_error (g));
      for (n = 0; r[n] != NULL; ++n) /**/;
      EXTEND (SP, n);
      for (i = 0; i < n; ++i) {
        PUSHs (sv_2mortal (newSVpv (r[i], 0)));
        free (r[i]);
      }
      free (r);

void
list_devices (g)
      guestfs_h *g;
PREINIT:
      char **r;
      size_t i, n;
 PPCODE:
      r = guestfs_list_devices (g);
      if (r == NULL)
        croak ("%s", guestfs_last_error (g));
      for (n = 0; r[n] != NULL; ++n) /**/;
      EXTEND (SP, n);
      for (i = 0; i < n; ++i) {
        PUSHs (sv_2mortal (newSVpv (r[i], 0)));
        free (r[i]);
      }
      free (r);

void
list_partitions (g)
      guestfs_h *g;
PREINIT:
      char **r;
      size_t i, n;
 PPCODE:
      r = guestfs_list_partitions (g);
      if (r == NULL)
        croak ("%s", guestfs_last_error (g));
      for (n = 0; r[n] != NULL; ++n) /**/;
      EXTEND (SP, n);
      for (i = 0; i < n; ++i) {
        PUSHs (sv_2mortal (newSVpv (r[i], 0)));
        free (r[i]);
      }
      free (r);

void
pvs (g)
      guestfs_h *g;
PREINIT:
      char **r;
      size_t i, n;
 PPCODE:
      r = guestfs_pvs (g);
      if (r == NULL)
        croak ("%s", guestfs_last_error (g));
      for (n = 0; r[n] != NULL; ++n) /**/;
      EXTEND (SP, n);
      for (i = 0; i < n; ++i) {
        PUSHs (sv_2mortal (newSVpv (r[i], 0)));
        free (r[i]);
      }
      free (r);

void
vgs (g)
      guestfs_h *g;
PREINIT:
      char **r;
      size_t i, n;
 PPCODE:
      r = guestfs_vgs (g);
      if (r == NULL)
        croak ("%s", guestfs_last_error (g));
      for (n = 0; r[n] != NULL; ++n) /**/;
      EXTEND (SP, n);
      for (i = 0; i < n; ++i) {
        PUSHs (sv_2mortal (newSVpv (r[i], 0)));
        free (r[i]);
      }
      free (r);

void
lvs (g)
      guestfs_h *g;
PREINIT:
      char **r;
      size_t i, n;
 PPCODE:
      r = guestfs_lvs (g);
      if (r == NULL)
        croak ("%s", guestfs_last_error (g));
      for (n = 0; r[n] != NULL; ++n) /**/;
      EXTEND (SP, n);
      for (i = 0; i < n; ++i) {
        PUSHs (sv_2mortal (newSVpv (r[i], 0)));
        free (r[i]);
      }
      free (r);

void
pvs_full (g)
      guestfs_h *g;
PREINIT:
      struct guestfs_lvm_pv_list *r;
      size_t i;
      HV *hv;
 PPCODE:
      r = guestfs_pvs_full (g);
      if (r == NULL)
        croak ("%s", guestfs_last_error (g));
      EXTEND (SP, r->len);
      for (i = 0; i < r->len; ++i) {
        hv = newHV ();
        (void) hv_store (hv, "pv_name", 7, newSVpv (r->val[i].pv_name, 0), 0);
        (void) hv_store (hv, "pv_uuid", 7, newSVpv (r->val[i].pv_uuid, 32), 0);
        (void) hv_store (hv, "pv_fmt", 6, newSVpv (r->val[i].pv_fmt, 0), 0);
        (void) hv_store (hv, "pv_size", 7, my_newSVull (r->val[i].pv_size), 0);
        (void) hv_store (hv, "dev_size", 8, my_newSVull (r->val[i].dev_size), 0);
        (void) hv_store (hv, "pv_free", 7, my_newSVull (r->val[i].pv_free), 0);
        (void) hv_store (hv, "pv_used", 7, my_newSVull (r->val[i].pv_used), 0);
        (void) hv_store (hv, "pv_attr", 7, newSVpv (r->val[i].pv_attr, 0), 0);
        (void) hv_store (hv, "pv_pe_count", 11, my_newSVll (r->val[i].pv_pe_count), 0);
        (void) hv_store (hv, "pv_pe_alloc_count", 17, my_newSVll (r->val[i].pv_pe_alloc_count), 0);
        (void) hv_store (hv, "pv_tags", 7, newSVpv (r->val[i].pv_tags, 0), 0);
        (void) hv_store (hv, "pe_start", 8, my_newSVull (r->val[i].pe_start), 0);
        (void) hv_store (hv, "pv_mda_count", 12, my_newSVll (r->val[i].pv_mda_count), 0);
        (void) hv_store (hv, "pv_mda_free", 11, my_newSVull (r->val[i].pv_mda_free), 0);
        PUSHs (sv_2mortal (newRV ((SV *) hv)));
      }
      guestfs_free_lvm_pv_list (r);

void
vgs_full (g)
      guestfs_h *g;
PREINIT:
      struct guestfs_lvm_vg_list *r;
      size_t i;
      HV *hv;
 PPCODE:
      r = guestfs_vgs_full (g);
      if (r == NULL)
        croak ("%s", guestfs_last_error (g));
      EXTEND (SP, r->len);
      for (i = 0; i < r->len; ++i) {
        hv = newHV ();
        (void) hv_store (hv, "vg_name", 7, newSVpv (r->val[i].vg_name, 0), 0);
        (void) hv_store (hv, "vg_uuid", 7, newSVpv (r->val[i].vg_uuid, 32), 0);
        (void) hv_store (hv, "vg_fmt", 6, newSVpv (r->val[i].vg_fmt, 0), 0);
        (void) hv_store (hv, "vg_attr", 7, newSVpv (r->val[i].vg_attr, 0), 0);
        (void) hv_store (hv, "vg_size", 7, my_newSVull (r->val[i].vg_size), 0);
        (void) hv_store (hv, "vg_free", 7, my_newSVull (r->val[i].vg_free), 0);
        (void) hv_store (hv, "vg_sysid", 8, newSVpv (r->val[i].vg_sysid, 0), 0);
        (void) hv_store (hv, "vg_extent_size", 14, my_newSVull (r->val[i].vg_extent_size), 0);
        (void) hv_store (hv, "vg_extent_count", 15, my_newSVll (r->val[i].vg_extent_count), 0);
        (void) hv_store (hv, "vg_free_count", 13, my_newSVll (r->val[i].vg_free_count), 0);
        (void) hv_store (hv, "max_lv", 6, my_newSVll (r->val[i].max_lv), 0);
        (void) hv_store (hv, "max_pv", 6, my_newSVll (r->val[i].max_pv), 0);
        (void) hv_store (hv, "pv_count", 8, my_newSVll (r->val[i].pv_count), 0);
        (void) hv_store (hv, "lv_count", 8, my_newSVll (r->val[i].lv_count), 0);
        (void) hv_store (hv, "snap_count", 10, my_newSVll (r->val[i].snap_count), 0);
        (void) hv_store (hv, "vg_seqno", 8, my_newSVll (r->val[i].vg_seqno), 0);
        (void) hv_store (hv, "vg_tags", 7, newSVpv (r->val[i].vg_tags, 0), 0);
        (void) hv_store (hv, "vg_mda_count", 12, my_newSVll (r->val[i].vg_mda_count), 0);
        (void) hv_store (hv, "vg_mda_free", 11, my_newSVull (r->val[i].vg_mda_free), 0);
        PUSHs (sv_2mortal (newRV ((SV *) hv)));
      }
      guestfs_free_lvm_vg_list (r);

void
lvs_full (g)
      guestfs_h *g;
PREINIT:
      struct guestfs_lvm_lv_list *r;
      size_t i;
      HV *hv;
 PPCODE:
      r = guestfs_lvs_full (g);
      if (r == NULL)
        croak ("%s", guestfs_last_error (g));
      EXTEND (SP, r->len);
      for (i = 0; i < r->len; ++i) {
        hv = newHV ();
        (void) hv_store (hv, "lv_name", 7, newSVpv (r->val[i].lv_name, 0), 0);
        (void) hv_store (hv, "lv_uuid", 7, newSVpv (r->val[i].lv_uuid, 32), 0);
        (void) hv_store (hv, "lv_attr", 7, newSVpv (r->val[i].lv_attr, 0), 0);
        (void) hv_store (hv, "lv_major", 8, my_newSVll (r->val[i].lv_major), 0);
        (void) hv_store (hv, "lv_minor", 8, my_newSVll (r->val[i].lv_minor), 0);
        (void) hv_store (hv, "lv_kernel_major", 15, my_newSVll (r->val[i].lv_kernel_major), 0);
        (void) hv_store (hv, "lv_kernel_minor", 15, my_newSVll (r->val[i].lv_kernel_minor), 0);
        (void) hv_store (hv, "lv_size", 7, my_newSVull (r->val[i].lv_size), 0);
        (void) hv_store (hv, "seg_count", 9, my_newSVll (r->val[i].seg_count), 0);
        (void) hv_store (hv, "origin", 6, newSVpv (r->val[i].origin, 0), 0);
        (void) hv_store (hv, "snap_percent", 12, newSVnv (r->val[i].snap_percent), 0);
        (void) hv_store (hv, "copy_percent", 12, newSVnv (r->val[i].copy_percent), 0);
        (void) hv_store (hv, "move_pv", 7, newSVpv (r->val[i].move_pv, 0), 0);
        (void) hv_store (hv, "lv_tags", 7, newSVpv (r->val[i].lv_tags, 0), 0);
        (void) hv_store (hv, "mirror_log", 10, newSVpv (r->val[i].mirror_log, 0), 0);
        (void) hv_store (hv, "modules", 7, newSVpv (r->val[i].modules, 0), 0);
        PUSHs (sv_2mortal (newRV ((SV *) hv)));
      }
      guestfs_free_lvm_lv_list (r);

void
read_lines (g, path)
      guestfs_h *g;
      char *path;
PREINIT:
      char **r;
      size_t i, n;
 PPCODE:
      r = guestfs_read_lines (g, path);
      if (r == NULL)
        croak ("%s", guestfs_last_error (g));
      for (n = 0; r[n] != NULL; ++n) /**/;
      EXTEND (SP, n);
      for (i = 0; i < n; ++i) {
        PUSHs (sv_2mortal (newSVpv (r[i], 0)));
        free (r[i]);
      }
      free (r);

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
      int r;
   CODE:
      r = guestfs_aug_defvar (g, name, expr);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));
      RETVAL = newSViv (r);
 OUTPUT:
      RETVAL

void
aug_defnode (g, name, expr, val)
      guestfs_h *g;
      char *name;
      char *expr;
      char *val;
PREINIT:
      struct guestfs_int_bool *r;
 PPCODE:
      r = guestfs_aug_defnode (g, name, expr, val);
      if (r == NULL)
        croak ("%s", guestfs_last_error (g));
      EXTEND (SP, 2 * 2);
      PUSHs (sv_2mortal (newSVpv ("i", 0)));
      PUSHs (sv_2mortal (newSVnv (r->i)));
      PUSHs (sv_2mortal (newSVpv ("b", 0)));
      PUSHs (sv_2mortal (newSVnv (r->b)));
      free (r);

SV *
aug_get (g, augpath)
      guestfs_h *g;
      char *augpath;
PREINIT:
      char *r;
   CODE:
      r = guestfs_aug_get (g, augpath);
      if (r == NULL)
        croak ("%s", guestfs_last_error (g));
      RETVAL = newSVpv (r, 0);
      free (r);
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
      int r;
   CODE:
      r = guestfs_aug_rm (g, augpath);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));
      RETVAL = newSViv (r);
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
      char **r;
      size_t i, n;
 PPCODE:
      r = guestfs_aug_match (g, augpath);
      if (r == NULL)
        croak ("%s", guestfs_last_error (g));
      for (n = 0; r[n] != NULL; ++n) /**/;
      EXTEND (SP, n);
      for (i = 0; i < n; ++i) {
        PUSHs (sv_2mortal (newSVpv (r[i], 0)));
        free (r[i]);
      }
      free (r);

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
      char **r;
      size_t i, n;
 PPCODE:
      r = guestfs_aug_ls (g, augpath);
      if (r == NULL)
        croak ("%s", guestfs_last_error (g));
      for (n = 0; r[n] != NULL; ++n) /**/;
      EXTEND (SP, n);
      for (i = 0; i < n; ++i) {
        PUSHs (sv_2mortal (newSVpv (r[i], 0)));
        free (r[i]);
      }
      free (r);

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
      int r;
   CODE:
      r = guestfs_exists (g, path);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));
      RETVAL = newSViv (r);
 OUTPUT:
      RETVAL

SV *
is_file (g, path)
      guestfs_h *g;
      char *path;
PREINIT:
      int r;
   CODE:
      r = guestfs_is_file (g, path);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));
      RETVAL = newSViv (r);
 OUTPUT:
      RETVAL

SV *
is_dir (g, path)
      guestfs_h *g;
      char *path;
PREINIT:
      int r;
   CODE:
      r = guestfs_is_dir (g, path);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));
      RETVAL = newSViv (r);
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
      char **r;
      size_t i, n;
 PPCODE:
      r = guestfs_mounts (g);
      if (r == NULL)
        croak ("%s", guestfs_last_error (g));
      for (n = 0; r[n] != NULL; ++n) /**/;
      EXTEND (SP, n);
      for (i = 0; i < n; ++i) {
        PUSHs (sv_2mortal (newSVpv (r[i], 0)));
        free (r[i]);
      }
      free (r);

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
      char *r;
   CODE:
      r = guestfs_file (g, path);
      if (r == NULL)
        croak ("%s", guestfs_last_error (g));
      RETVAL = newSVpv (r, 0);
      free (r);
 OUTPUT:
      RETVAL

SV *
command (g, arguments)
      guestfs_h *g;
      char **arguments;
PREINIT:
      char *r;
   CODE:
      r = guestfs_command (g, arguments);
      free (arguments);
      if (r == NULL)
        croak ("%s", guestfs_last_error (g));
      RETVAL = newSVpv (r, 0);
      free (r);
 OUTPUT:
      RETVAL

void
command_lines (g, arguments)
      guestfs_h *g;
      char **arguments;
PREINIT:
      char **r;
      size_t i, n;
 PPCODE:
      r = guestfs_command_lines (g, arguments);
      free (arguments);
      if (r == NULL)
        croak ("%s", guestfs_last_error (g));
      for (n = 0; r[n] != NULL; ++n) /**/;
      EXTEND (SP, n);
      for (i = 0; i < n; ++i) {
        PUSHs (sv_2mortal (newSVpv (r[i], 0)));
        free (r[i]);
      }
      free (r);

void
stat (g, path)
      guestfs_h *g;
      char *path;
PREINIT:
      struct guestfs_stat *r;
 PPCODE:
      r = guestfs_stat (g, path);
      if (r == NULL)
        croak ("%s", guestfs_last_error (g));
      EXTEND (SP, 2 * 13);
      PUSHs (sv_2mortal (newSVpv ("dev", 0)));
      PUSHs (sv_2mortal (my_newSVll (r->dev)));
      PUSHs (sv_2mortal (newSVpv ("ino", 0)));
      PUSHs (sv_2mortal (my_newSVll (r->ino)));
      PUSHs (sv_2mortal (newSVpv ("mode", 0)));
      PUSHs (sv_2mortal (my_newSVll (r->mode)));
      PUSHs (sv_2mortal (newSVpv ("nlink", 0)));
      PUSHs (sv_2mortal (my_newSVll (r->nlink)));
      PUSHs (sv_2mortal (newSVpv ("uid", 0)));
      PUSHs (sv_2mortal (my_newSVll (r->uid)));
      PUSHs (sv_2mortal (newSVpv ("gid", 0)));
      PUSHs (sv_2mortal (my_newSVll (r->gid)));
      PUSHs (sv_2mortal (newSVpv ("rdev", 0)));
      PUSHs (sv_2mortal (my_newSVll (r->rdev)));
      PUSHs (sv_2mortal (newSVpv ("size", 0)));
      PUSHs (sv_2mortal (my_newSVll (r->size)));
      PUSHs (sv_2mortal (newSVpv ("blksize", 0)));
      PUSHs (sv_2mortal (my_newSVll (r->blksize)));
      PUSHs (sv_2mortal (newSVpv ("blocks", 0)));
      PUSHs (sv_2mortal (my_newSVll (r->blocks)));
      PUSHs (sv_2mortal (newSVpv ("atime", 0)));
      PUSHs (sv_2mortal (my_newSVll (r->atime)));
      PUSHs (sv_2mortal (newSVpv ("mtime", 0)));
      PUSHs (sv_2mortal (my_newSVll (r->mtime)));
      PUSHs (sv_2mortal (newSVpv ("ctime", 0)));
      PUSHs (sv_2mortal (my_newSVll (r->ctime)));
      free (r);

void
lstat (g, path)
      guestfs_h *g;
      char *path;
PREINIT:
      struct guestfs_stat *r;
 PPCODE:
      r = guestfs_lstat (g, path);
      if (r == NULL)
        croak ("%s", guestfs_last_error (g));
      EXTEND (SP, 2 * 13);
      PUSHs (sv_2mortal (newSVpv ("dev", 0)));
      PUSHs (sv_2mortal (my_newSVll (r->dev)));
      PUSHs (sv_2mortal (newSVpv ("ino", 0)));
      PUSHs (sv_2mortal (my_newSVll (r->ino)));
      PUSHs (sv_2mortal (newSVpv ("mode", 0)));
      PUSHs (sv_2mortal (my_newSVll (r->mode)));
      PUSHs (sv_2mortal (newSVpv ("nlink", 0)));
      PUSHs (sv_2mortal (my_newSVll (r->nlink)));
      PUSHs (sv_2mortal (newSVpv ("uid", 0)));
      PUSHs (sv_2mortal (my_newSVll (r->uid)));
      PUSHs (sv_2mortal (newSVpv ("gid", 0)));
      PUSHs (sv_2mortal (my_newSVll (r->gid)));
      PUSHs (sv_2mortal (newSVpv ("rdev", 0)));
      PUSHs (sv_2mortal (my_newSVll (r->rdev)));
      PUSHs (sv_2mortal (newSVpv ("size", 0)));
      PUSHs (sv_2mortal (my_newSVll (r->size)));
      PUSHs (sv_2mortal (newSVpv ("blksize", 0)));
      PUSHs (sv_2mortal (my_newSVll (r->blksize)));
      PUSHs (sv_2mortal (newSVpv ("blocks", 0)));
      PUSHs (sv_2mortal (my_newSVll (r->blocks)));
      PUSHs (sv_2mortal (newSVpv ("atime", 0)));
      PUSHs (sv_2mortal (my_newSVll (r->atime)));
      PUSHs (sv_2mortal (newSVpv ("mtime", 0)));
      PUSHs (sv_2mortal (my_newSVll (r->mtime)));
      PUSHs (sv_2mortal (newSVpv ("ctime", 0)));
      PUSHs (sv_2mortal (my_newSVll (r->ctime)));
      free (r);

void
statvfs (g, path)
      guestfs_h *g;
      char *path;
PREINIT:
      struct guestfs_statvfs *r;
 PPCODE:
      r = guestfs_statvfs (g, path);
      if (r == NULL)
        croak ("%s", guestfs_last_error (g));
      EXTEND (SP, 2 * 11);
      PUSHs (sv_2mortal (newSVpv ("bsize", 0)));
      PUSHs (sv_2mortal (my_newSVll (r->bsize)));
      PUSHs (sv_2mortal (newSVpv ("frsize", 0)));
      PUSHs (sv_2mortal (my_newSVll (r->frsize)));
      PUSHs (sv_2mortal (newSVpv ("blocks", 0)));
      PUSHs (sv_2mortal (my_newSVll (r->blocks)));
      PUSHs (sv_2mortal (newSVpv ("bfree", 0)));
      PUSHs (sv_2mortal (my_newSVll (r->bfree)));
      PUSHs (sv_2mortal (newSVpv ("bavail", 0)));
      PUSHs (sv_2mortal (my_newSVll (r->bavail)));
      PUSHs (sv_2mortal (newSVpv ("files", 0)));
      PUSHs (sv_2mortal (my_newSVll (r->files)));
      PUSHs (sv_2mortal (newSVpv ("ffree", 0)));
      PUSHs (sv_2mortal (my_newSVll (r->ffree)));
      PUSHs (sv_2mortal (newSVpv ("favail", 0)));
      PUSHs (sv_2mortal (my_newSVll (r->favail)));
      PUSHs (sv_2mortal (newSVpv ("fsid", 0)));
      PUSHs (sv_2mortal (my_newSVll (r->fsid)));
      PUSHs (sv_2mortal (newSVpv ("flag", 0)));
      PUSHs (sv_2mortal (my_newSVll (r->flag)));
      PUSHs (sv_2mortal (newSVpv ("namemax", 0)));
      PUSHs (sv_2mortal (my_newSVll (r->namemax)));
      free (r);

void
tune2fs_l (g, device)
      guestfs_h *g;
      char *device;
PREINIT:
      char **r;
      size_t i, n;
 PPCODE:
      r = guestfs_tune2fs_l (g, device);
      if (r == NULL)
        croak ("%s", guestfs_last_error (g));
      for (n = 0; r[n] != NULL; ++n) /**/;
      EXTEND (SP, n);
      for (i = 0; i < n; ++i) {
        PUSHs (sv_2mortal (newSVpv (r[i], 0)));
        free (r[i]);
      }
      free (r);

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
      int r;
   CODE:
      r = guestfs_blockdev_getro (g, device);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));
      RETVAL = newSViv (r);
 OUTPUT:
      RETVAL

SV *
blockdev_getss (g, device)
      guestfs_h *g;
      char *device;
PREINIT:
      int r;
   CODE:
      r = guestfs_blockdev_getss (g, device);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));
      RETVAL = newSViv (r);
 OUTPUT:
      RETVAL

SV *
blockdev_getbsz (g, device)
      guestfs_h *g;
      char *device;
PREINIT:
      int r;
   CODE:
      r = guestfs_blockdev_getbsz (g, device);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));
      RETVAL = newSViv (r);
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
      int64_t r;
   CODE:
      r = guestfs_blockdev_getsz (g, device);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));
      RETVAL = my_newSVll (r);
 OUTPUT:
      RETVAL

SV *
blockdev_getsize64 (g, device)
      guestfs_h *g;
      char *device;
PREINIT:
      int64_t r;
   CODE:
      r = guestfs_blockdev_getsize64 (g, device);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));
      RETVAL = my_newSVll (r);
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
      char *r;
   CODE:
      r = guestfs_checksum (g, csumtype, path);
      if (r == NULL)
        croak ("%s", guestfs_last_error (g));
      RETVAL = newSVpv (r, 0);
      free (r);
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
      char *r;
   CODE:
      r = guestfs_debug (g, subcmd, extraargs);
      free (extraargs);
      if (r == NULL)
        croak ("%s", guestfs_last_error (g));
      RETVAL = newSVpv (r, 0);
      free (r);
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
      char *r;
   CODE:
      r = guestfs_get_e2label (g, device);
      if (r == NULL)
        croak ("%s", guestfs_last_error (g));
      RETVAL = newSVpv (r, 0);
      free (r);
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
      char *r;
   CODE:
      r = guestfs_get_e2uuid (g, device);
      if (r == NULL)
        croak ("%s", guestfs_last_error (g));
      RETVAL = newSVpv (r, 0);
      free (r);
 OUTPUT:
      RETVAL

SV *
fsck (g, fstype, device)
      guestfs_h *g;
      char *fstype;
      char *device;
PREINIT:
      int r;
   CODE:
      r = guestfs_fsck (g, fstype, device);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));
      RETVAL = newSViv (r);
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
      char *r;
   CODE:
      r = guestfs_dmesg (g);
      if (r == NULL)
        croak ("%s", guestfs_last_error (g));
      RETVAL = newSVpv (r, 0);
      free (r);
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
      int r;
   CODE:
      r = guestfs_equal (g, file1, file2);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));
      RETVAL = newSViv (r);
 OUTPUT:
      RETVAL

void
strings (g, path)
      guestfs_h *g;
      char *path;
PREINIT:
      char **r;
      size_t i, n;
 PPCODE:
      r = guestfs_strings (g, path);
      if (r == NULL)
        croak ("%s", guestfs_last_error (g));
      for (n = 0; r[n] != NULL; ++n) /**/;
      EXTEND (SP, n);
      for (i = 0; i < n; ++i) {
        PUSHs (sv_2mortal (newSVpv (r[i], 0)));
        free (r[i]);
      }
      free (r);

void
strings_e (g, encoding, path)
      guestfs_h *g;
      char *encoding;
      char *path;
PREINIT:
      char **r;
      size_t i, n;
 PPCODE:
      r = guestfs_strings_e (g, encoding, path);
      if (r == NULL)
        croak ("%s", guestfs_last_error (g));
      for (n = 0; r[n] != NULL; ++n) /**/;
      EXTEND (SP, n);
      for (i = 0; i < n; ++i) {
        PUSHs (sv_2mortal (newSVpv (r[i], 0)));
        free (r[i]);
      }
      free (r);

SV *
hexdump (g, path)
      guestfs_h *g;
      char *path;
PREINIT:
      char *r;
   CODE:
      r = guestfs_hexdump (g, path);
      if (r == NULL)
        croak ("%s", guestfs_last_error (g));
      RETVAL = newSVpv (r, 0);
      free (r);
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
      char *r;
   CODE:
      r = guestfs_sfdisk_l (g, device);
      if (r == NULL)
        croak ("%s", guestfs_last_error (g));
      RETVAL = newSVpv (r, 0);
      free (r);
 OUTPUT:
      RETVAL

SV *
sfdisk_kernel_geometry (g, device)
      guestfs_h *g;
      char *device;
PREINIT:
      char *r;
   CODE:
      r = guestfs_sfdisk_kernel_geometry (g, device);
      if (r == NULL)
        croak ("%s", guestfs_last_error (g));
      RETVAL = newSVpv (r, 0);
      free (r);
 OUTPUT:
      RETVAL

SV *
sfdisk_disk_geometry (g, device)
      guestfs_h *g;
      char *device;
PREINIT:
      char *r;
   CODE:
      r = guestfs_sfdisk_disk_geometry (g, device);
      if (r == NULL)
        croak ("%s", guestfs_last_error (g));
      RETVAL = newSVpv (r, 0);
      free (r);
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
      char **r;
      size_t i, n;
 PPCODE:
      r = guestfs_find (g, directory);
      if (r == NULL)
        croak ("%s", guestfs_last_error (g));
      for (n = 0; r[n] != NULL; ++n) /**/;
      EXTEND (SP, n);
      for (i = 0; i < n; ++i) {
        PUSHs (sv_2mortal (newSVpv (r[i], 0)));
        free (r[i]);
      }
      free (r);

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
      int r;
   CODE:
      r = guestfs_ntfs_3g_probe (g, rw, device);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));
      RETVAL = newSViv (r);
 OUTPUT:
      RETVAL

SV *
sh (g, command)
      guestfs_h *g;
      char *command;
PREINIT:
      char *r;
   CODE:
      r = guestfs_sh (g, command);
      if (r == NULL)
        croak ("%s", guestfs_last_error (g));
      RETVAL = newSVpv (r, 0);
      free (r);
 OUTPUT:
      RETVAL

void
sh_lines (g, command)
      guestfs_h *g;
      char *command;
PREINIT:
      char **r;
      size_t i, n;
 PPCODE:
      r = guestfs_sh_lines (g, command);
      if (r == NULL)
        croak ("%s", guestfs_last_error (g));
      for (n = 0; r[n] != NULL; ++n) /**/;
      EXTEND (SP, n);
      for (i = 0; i < n; ++i) {
        PUSHs (sv_2mortal (newSVpv (r[i], 0)));
        free (r[i]);
      }
      free (r);

void
glob_expand (g, pattern)
      guestfs_h *g;
      char *pattern;
PREINIT:
      char **r;
      size_t i, n;
 PPCODE:
      r = guestfs_glob_expand (g, pattern);
      if (r == NULL)
        croak ("%s", guestfs_last_error (g));
      for (n = 0; r[n] != NULL; ++n) /**/;
      EXTEND (SP, n);
      for (i = 0; i < n; ++i) {
        PUSHs (sv_2mortal (newSVpv (r[i], 0)));
        free (r[i]);
      }
      free (r);

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
      char *r;
   CODE:
      r = guestfs_mkdtemp (g, template);
      if (r == NULL)
        croak ("%s", guestfs_last_error (g));
      RETVAL = newSVpv (r, 0);
      free (r);
 OUTPUT:
      RETVAL

SV *
wc_l (g, path)
      guestfs_h *g;
      char *path;
PREINIT:
      int r;
   CODE:
      r = guestfs_wc_l (g, path);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));
      RETVAL = newSViv (r);
 OUTPUT:
      RETVAL

SV *
wc_w (g, path)
      guestfs_h *g;
      char *path;
PREINIT:
      int r;
   CODE:
      r = guestfs_wc_w (g, path);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));
      RETVAL = newSViv (r);
 OUTPUT:
      RETVAL

SV *
wc_c (g, path)
      guestfs_h *g;
      char *path;
PREINIT:
      int r;
   CODE:
      r = guestfs_wc_c (g, path);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));
      RETVAL = newSViv (r);
 OUTPUT:
      RETVAL

void
head (g, path)
      guestfs_h *g;
      char *path;
PREINIT:
      char **r;
      size_t i, n;
 PPCODE:
      r = guestfs_head (g, path);
      if (r == NULL)
        croak ("%s", guestfs_last_error (g));
      for (n = 0; r[n] != NULL; ++n) /**/;
      EXTEND (SP, n);
      for (i = 0; i < n; ++i) {
        PUSHs (sv_2mortal (newSVpv (r[i], 0)));
        free (r[i]);
      }
      free (r);

void
head_n (g, nrlines, path)
      guestfs_h *g;
      int nrlines;
      char *path;
PREINIT:
      char **r;
      size_t i, n;
 PPCODE:
      r = guestfs_head_n (g, nrlines, path);
      if (r == NULL)
        croak ("%s", guestfs_last_error (g));
      for (n = 0; r[n] != NULL; ++n) /**/;
      EXTEND (SP, n);
      for (i = 0; i < n; ++i) {
        PUSHs (sv_2mortal (newSVpv (r[i], 0)));
        free (r[i]);
      }
      free (r);

void
tail (g, path)
      guestfs_h *g;
      char *path;
PREINIT:
      char **r;
      size_t i, n;
 PPCODE:
      r = guestfs_tail (g, path);
      if (r == NULL)
        croak ("%s", guestfs_last_error (g));
      for (n = 0; r[n] != NULL; ++n) /**/;
      EXTEND (SP, n);
      for (i = 0; i < n; ++i) {
        PUSHs (sv_2mortal (newSVpv (r[i], 0)));
        free (r[i]);
      }
      free (r);

void
tail_n (g, nrlines, path)
      guestfs_h *g;
      int nrlines;
      char *path;
PREINIT:
      char **r;
      size_t i, n;
 PPCODE:
      r = guestfs_tail_n (g, nrlines, path);
      if (r == NULL)
        croak ("%s", guestfs_last_error (g));
      for (n = 0; r[n] != NULL; ++n) /**/;
      EXTEND (SP, n);
      for (i = 0; i < n; ++i) {
        PUSHs (sv_2mortal (newSVpv (r[i], 0)));
        free (r[i]);
      }
      free (r);

SV *
df (g)
      guestfs_h *g;
PREINIT:
      char *r;
   CODE:
      r = guestfs_df (g);
      if (r == NULL)
        croak ("%s", guestfs_last_error (g));
      RETVAL = newSVpv (r, 0);
      free (r);
 OUTPUT:
      RETVAL

SV *
df_h (g)
      guestfs_h *g;
PREINIT:
      char *r;
   CODE:
      r = guestfs_df_h (g);
      if (r == NULL)
        croak ("%s", guestfs_last_error (g));
      RETVAL = newSVpv (r, 0);
      free (r);
 OUTPUT:
      RETVAL

SV *
du (g, path)
      guestfs_h *g;
      char *path;
PREINIT:
      int64_t r;
   CODE:
      r = guestfs_du (g, path);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));
      RETVAL = my_newSVll (r);
 OUTPUT:
      RETVAL

void
initrd_list (g, path)
      guestfs_h *g;
      char *path;
PREINIT:
      char **r;
      size_t i, n;
 PPCODE:
      r = guestfs_initrd_list (g, path);
      if (r == NULL)
        croak ("%s", guestfs_last_error (g));
      for (n = 0; r[n] != NULL; ++n) /**/;
      EXTEND (SP, n);
      for (i = 0; i < n; ++i) {
        PUSHs (sv_2mortal (newSVpv (r[i], 0)));
        free (r[i]);
      }
      free (r);

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
      int r;
   CODE:
      r = guestfs_umask (g, mask);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));
      RETVAL = newSViv (r);
 OUTPUT:
      RETVAL

void
readdir (g, dir)
      guestfs_h *g;
      char *dir;
PREINIT:
      struct guestfs_dirent_list *r;
      size_t i;
      HV *hv;
 PPCODE:
      r = guestfs_readdir (g, dir);
      if (r == NULL)
        croak ("%s", guestfs_last_error (g));
      EXTEND (SP, r->len);
      for (i = 0; i < r->len; ++i) {
        hv = newHV ();
        (void) hv_store (hv, "ino", 3, my_newSVll (r->val[i].ino), 0);
        (void) hv_store (hv, "ftyp", 4, newSVpv (&r->val[i].ftyp, 1), 0);
        (void) hv_store (hv, "name", 4, newSVpv (r->val[i].name, 0), 0);
        PUSHs (sv_2mortal (newRV ((SV *) hv)));
      }
      guestfs_free_dirent_list (r);

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
      char *r;
   CODE:
      r = guestfs_zfile (g, meth, path);
      if (r == NULL)
        croak ("%s", guestfs_last_error (g));
      RETVAL = newSVpv (r, 0);
      free (r);
 OUTPUT:
      RETVAL

void
getxattrs (g, path)
      guestfs_h *g;
      char *path;
PREINIT:
      struct guestfs_xattr_list *r;
      size_t i;
      HV *hv;
 PPCODE:
      r = guestfs_getxattrs (g, path);
      if (r == NULL)
        croak ("%s", guestfs_last_error (g));
      EXTEND (SP, r->len);
      for (i = 0; i < r->len; ++i) {
        hv = newHV ();
        (void) hv_store (hv, "attrname", 8, newSVpv (r->val[i].attrname, 0), 0);
        (void) hv_store (hv, "attrval", 7, newSVpvn (r->val[i].attrval, r->val[i].attrval_len), 0);
        PUSHs (sv_2mortal (newRV ((SV *) hv)));
      }
      guestfs_free_xattr_list (r);

void
lgetxattrs (g, path)
      guestfs_h *g;
      char *path;
PREINIT:
      struct guestfs_xattr_list *r;
      size_t i;
      HV *hv;
 PPCODE:
      r = guestfs_lgetxattrs (g, path);
      if (r == NULL)
        croak ("%s", guestfs_last_error (g));
      EXTEND (SP, r->len);
      for (i = 0; i < r->len; ++i) {
        hv = newHV ();
        (void) hv_store (hv, "attrname", 8, newSVpv (r->val[i].attrname, 0), 0);
        (void) hv_store (hv, "attrval", 7, newSVpvn (r->val[i].attrval, r->val[i].attrval_len), 0);
        PUSHs (sv_2mortal (newRV ((SV *) hv)));
      }
      guestfs_free_xattr_list (r);

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
      char **r;
      size_t i, n;
 PPCODE:
      r = guestfs_mountpoints (g);
      if (r == NULL)
        croak ("%s", guestfs_last_error (g));
      for (n = 0; r[n] != NULL; ++n) /**/;
      EXTEND (SP, n);
      for (i = 0; i < n; ++i) {
        PUSHs (sv_2mortal (newSVpv (r[i], 0)));
        free (r[i]);
      }
      free (r);

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
      char *r;
      size_t size;
   CODE:
      r = guestfs_read_file (g, path, &size);
      if (r == NULL)
        croak ("%s", guestfs_last_error (g));
      RETVAL = newSVpvn (r, size);
      free (r);
 OUTPUT:
      RETVAL

void
grep (g, regex, path)
      guestfs_h *g;
      char *regex;
      char *path;
PREINIT:
      char **r;
      size_t i, n;
 PPCODE:
      r = guestfs_grep (g, regex, path);
      if (r == NULL)
        croak ("%s", guestfs_last_error (g));
      for (n = 0; r[n] != NULL; ++n) /**/;
      EXTEND (SP, n);
      for (i = 0; i < n; ++i) {
        PUSHs (sv_2mortal (newSVpv (r[i], 0)));
        free (r[i]);
      }
      free (r);

void
egrep (g, regex, path)
      guestfs_h *g;
      char *regex;
      char *path;
PREINIT:
      char **r;
      size_t i, n;
 PPCODE:
      r = guestfs_egrep (g, regex, path);
      if (r == NULL)
        croak ("%s", guestfs_last_error (g));
      for (n = 0; r[n] != NULL; ++n) /**/;
      EXTEND (SP, n);
      for (i = 0; i < n; ++i) {
        PUSHs (sv_2mortal (newSVpv (r[i], 0)));
        free (r[i]);
      }
      free (r);

void
fgrep (g, pattern, path)
      guestfs_h *g;
      char *pattern;
      char *path;
PREINIT:
      char **r;
      size_t i, n;
 PPCODE:
      r = guestfs_fgrep (g, pattern, path);
      if (r == NULL)
        croak ("%s", guestfs_last_error (g));
      for (n = 0; r[n] != NULL; ++n) /**/;
      EXTEND (SP, n);
      for (i = 0; i < n; ++i) {
        PUSHs (sv_2mortal (newSVpv (r[i], 0)));
        free (r[i]);
      }
      free (r);

void
grepi (g, regex, path)
      guestfs_h *g;
      char *regex;
      char *path;
PREINIT:
      char **r;
      size_t i, n;
 PPCODE:
      r = guestfs_grepi (g, regex, path);
      if (r == NULL)
        croak ("%s", guestfs_last_error (g));
      for (n = 0; r[n] != NULL; ++n) /**/;
      EXTEND (SP, n);
      for (i = 0; i < n; ++i) {
        PUSHs (sv_2mortal (newSVpv (r[i], 0)));
        free (r[i]);
      }
      free (r);

void
egrepi (g, regex, path)
      guestfs_h *g;
      char *regex;
      char *path;
PREINIT:
      char **r;
      size_t i, n;
 PPCODE:
      r = guestfs_egrepi (g, regex, path);
      if (r == NULL)
        croak ("%s", guestfs_last_error (g));
      for (n = 0; r[n] != NULL; ++n) /**/;
      EXTEND (SP, n);
      for (i = 0; i < n; ++i) {
        PUSHs (sv_2mortal (newSVpv (r[i], 0)));
        free (r[i]);
      }
      free (r);

void
fgrepi (g, pattern, path)
      guestfs_h *g;
      char *pattern;
      char *path;
PREINIT:
      char **r;
      size_t i, n;
 PPCODE:
      r = guestfs_fgrepi (g, pattern, path);
      if (r == NULL)
        croak ("%s", guestfs_last_error (g));
      for (n = 0; r[n] != NULL; ++n) /**/;
      EXTEND (SP, n);
      for (i = 0; i < n; ++i) {
        PUSHs (sv_2mortal (newSVpv (r[i], 0)));
        free (r[i]);
      }
      free (r);

void
zgrep (g, regex, path)
      guestfs_h *g;
      char *regex;
      char *path;
PREINIT:
      char **r;
      size_t i, n;
 PPCODE:
      r = guestfs_zgrep (g, regex, path);
      if (r == NULL)
        croak ("%s", guestfs_last_error (g));
      for (n = 0; r[n] != NULL; ++n) /**/;
      EXTEND (SP, n);
      for (i = 0; i < n; ++i) {
        PUSHs (sv_2mortal (newSVpv (r[i], 0)));
        free (r[i]);
      }
      free (r);

void
zegrep (g, regex, path)
      guestfs_h *g;
      char *regex;
      char *path;
PREINIT:
      char **r;
      size_t i, n;
 PPCODE:
      r = guestfs_zegrep (g, regex, path);
      if (r == NULL)
        croak ("%s", guestfs_last_error (g));
      for (n = 0; r[n] != NULL; ++n) /**/;
      EXTEND (SP, n);
      for (i = 0; i < n; ++i) {
        PUSHs (sv_2mortal (newSVpv (r[i], 0)));
        free (r[i]);
      }
      free (r);

void
zfgrep (g, pattern, path)
      guestfs_h *g;
      char *pattern;
      char *path;
PREINIT:
      char **r;
      size_t i, n;
 PPCODE:
      r = guestfs_zfgrep (g, pattern, path);
      if (r == NULL)
        croak ("%s", guestfs_last_error (g));
      for (n = 0; r[n] != NULL; ++n) /**/;
      EXTEND (SP, n);
      for (i = 0; i < n; ++i) {
        PUSHs (sv_2mortal (newSVpv (r[i], 0)));
        free (r[i]);
      }
      free (r);

void
zgrepi (g, regex, path)
      guestfs_h *g;
      char *regex;
      char *path;
PREINIT:
      char **r;
      size_t i, n;
 PPCODE:
      r = guestfs_zgrepi (g, regex, path);
      if (r == NULL)
        croak ("%s", guestfs_last_error (g));
      for (n = 0; r[n] != NULL; ++n) /**/;
      EXTEND (SP, n);
      for (i = 0; i < n; ++i) {
        PUSHs (sv_2mortal (newSVpv (r[i], 0)));
        free (r[i]);
      }
      free (r);

void
zegrepi (g, regex, path)
      guestfs_h *g;
      char *regex;
      char *path;
PREINIT:
      char **r;
      size_t i, n;
 PPCODE:
      r = guestfs_zegrepi (g, regex, path);
      if (r == NULL)
        croak ("%s", guestfs_last_error (g));
      for (n = 0; r[n] != NULL; ++n) /**/;
      EXTEND (SP, n);
      for (i = 0; i < n; ++i) {
        PUSHs (sv_2mortal (newSVpv (r[i], 0)));
        free (r[i]);
      }
      free (r);

void
zfgrepi (g, pattern, path)
      guestfs_h *g;
      char *pattern;
      char *path;
PREINIT:
      char **r;
      size_t i, n;
 PPCODE:
      r = guestfs_zfgrepi (g, pattern, path);
      if (r == NULL)
        croak ("%s", guestfs_last_error (g));
      for (n = 0; r[n] != NULL; ++n) /**/;
      EXTEND (SP, n);
      for (i = 0; i < n; ++i) {
        PUSHs (sv_2mortal (newSVpv (r[i], 0)));
        free (r[i]);
      }
      free (r);

SV *
realpath (g, path)
      guestfs_h *g;
      char *path;
PREINIT:
      char *r;
   CODE:
      r = guestfs_realpath (g, path);
      if (r == NULL)
        croak ("%s", guestfs_last_error (g));
      RETVAL = newSVpv (r, 0);
      free (r);
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
      char *r;
   CODE:
      r = guestfs_readlink (g, path);
      if (r == NULL)
        croak ("%s", guestfs_last_error (g));
      RETVAL = newSVpv (r, 0);
      free (r);
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
      int64_t r;
   CODE:
      r = guestfs_inotify_add_watch (g, path, mask);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));
      RETVAL = my_newSVll (r);
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
      struct guestfs_inotify_event_list *r;
      size_t i;
      HV *hv;
 PPCODE:
      r = guestfs_inotify_read (g);
      if (r == NULL)
        croak ("%s", guestfs_last_error (g));
      EXTEND (SP, r->len);
      for (i = 0; i < r->len; ++i) {
        hv = newHV ();
        (void) hv_store (hv, "in_wd", 5, my_newSVll (r->val[i].in_wd), 0);
        (void) hv_store (hv, "in_mask", 7, newSVnv (r->val[i].in_mask), 0);
        (void) hv_store (hv, "in_cookie", 9, newSVnv (r->val[i].in_cookie), 0);
        (void) hv_store (hv, "in_name", 7, newSVpv (r->val[i].in_name, 0), 0);
        PUSHs (sv_2mortal (newRV ((SV *) hv)));
      }
      guestfs_free_inotify_event_list (r);

void
inotify_files (g)
      guestfs_h *g;
PREINIT:
      char **r;
      size_t i, n;
 PPCODE:
      r = guestfs_inotify_files (g);
      if (r == NULL)
        croak ("%s", guestfs_last_error (g));
      for (n = 0; r[n] != NULL; ++n) /**/;
      EXTEND (SP, n);
      for (i = 0; i < n; ++i) {
        PUSHs (sv_2mortal (newSVpv (r[i], 0)));
        free (r[i]);
      }
      free (r);

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
      char *r;
   CODE:
      r = guestfs_getcon (g);
      if (r == NULL)
        croak ("%s", guestfs_last_error (g));
      RETVAL = newSVpv (r, 0);
      free (r);
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
      char *r;
   CODE:
      r = guestfs_echo_daemon (g, words);
      free (words);
      if (r == NULL)
        croak ("%s", guestfs_last_error (g));
      RETVAL = newSVpv (r, 0);
      free (r);
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
      char *r;
   CODE:
      r = guestfs_case_sensitive_path (g, path);
      if (r == NULL)
        croak ("%s", guestfs_last_error (g));
      RETVAL = newSVpv (r, 0);
      free (r);
 OUTPUT:
      RETVAL

SV *
vfs_type (g, device)
      guestfs_h *g;
      char *device;
PREINIT:
      char *r;
   CODE:
      r = guestfs_vfs_type (g, device);
      if (r == NULL)
        croak ("%s", guestfs_last_error (g));
      RETVAL = newSVpv (r, 0);
      free (r);
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
      struct guestfs_stat_list *r;
      size_t i;
      HV *hv;
 PPCODE:
      r = guestfs_lstatlist (g, path, names);
      free (names);
      if (r == NULL)
        croak ("%s", guestfs_last_error (g));
      EXTEND (SP, r->len);
      for (i = 0; i < r->len; ++i) {
        hv = newHV ();
        (void) hv_store (hv, "dev", 3, my_newSVll (r->val[i].dev), 0);
        (void) hv_store (hv, "ino", 3, my_newSVll (r->val[i].ino), 0);
        (void) hv_store (hv, "mode", 4, my_newSVll (r->val[i].mode), 0);
        (void) hv_store (hv, "nlink", 5, my_newSVll (r->val[i].nlink), 0);
        (void) hv_store (hv, "uid", 3, my_newSVll (r->val[i].uid), 0);
        (void) hv_store (hv, "gid", 3, my_newSVll (r->val[i].gid), 0);
        (void) hv_store (hv, "rdev", 4, my_newSVll (r->val[i].rdev), 0);
        (void) hv_store (hv, "size", 4, my_newSVll (r->val[i].size), 0);
        (void) hv_store (hv, "blksize", 7, my_newSVll (r->val[i].blksize), 0);
        (void) hv_store (hv, "blocks", 6, my_newSVll (r->val[i].blocks), 0);
        (void) hv_store (hv, "atime", 5, my_newSVll (r->val[i].atime), 0);
        (void) hv_store (hv, "mtime", 5, my_newSVll (r->val[i].mtime), 0);
        (void) hv_store (hv, "ctime", 5, my_newSVll (r->val[i].ctime), 0);
        PUSHs (sv_2mortal (newRV ((SV *) hv)));
      }
      guestfs_free_stat_list (r);

void
lxattrlist (g, path, names)
      guestfs_h *g;
      char *path;
      char **names;
PREINIT:
      struct guestfs_xattr_list *r;
      size_t i;
      HV *hv;
 PPCODE:
      r = guestfs_lxattrlist (g, path, names);
      free (names);
      if (r == NULL)
        croak ("%s", guestfs_last_error (g));
      EXTEND (SP, r->len);
      for (i = 0; i < r->len; ++i) {
        hv = newHV ();
        (void) hv_store (hv, "attrname", 8, newSVpv (r->val[i].attrname, 0), 0);
        (void) hv_store (hv, "attrval", 7, newSVpvn (r->val[i].attrval, r->val[i].attrval_len), 0);
        PUSHs (sv_2mortal (newRV ((SV *) hv)));
      }
      guestfs_free_xattr_list (r);

void
readlinklist (g, path, names)
      guestfs_h *g;
      char *path;
      char **names;
PREINIT:
      char **r;
      size_t i, n;
 PPCODE:
      r = guestfs_readlinklist (g, path, names);
      free (names);
      if (r == NULL)
        croak ("%s", guestfs_last_error (g));
      for (n = 0; r[n] != NULL; ++n) /**/;
      EXTEND (SP, n);
      for (i = 0; i < n; ++i) {
        PUSHs (sv_2mortal (newSVpv (r[i], 0)));
        free (r[i]);
      }
      free (r);

SV *
pread (g, path, count, offset)
      guestfs_h *g;
      char *path;
      int count;
      int64_t offset;
PREINIT:
      char *r;
      size_t size;
   CODE:
      r = guestfs_pread (g, path, count, offset, &size);
      if (r == NULL)
        croak ("%s", guestfs_last_error (g));
      RETVAL = newSVpvn (r, size);
      free (r);
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
      struct guestfs_partition_list *r;
      size_t i;
      HV *hv;
 PPCODE:
      r = guestfs_part_list (g, device);
      if (r == NULL)
        croak ("%s", guestfs_last_error (g));
      EXTEND (SP, r->len);
      for (i = 0; i < r->len; ++i) {
        hv = newHV ();
        (void) hv_store (hv, "part_num", 8, newSVnv (r->val[i].part_num), 0);
        (void) hv_store (hv, "part_start", 10, my_newSVull (r->val[i].part_start), 0);
        (void) hv_store (hv, "part_end", 8, my_newSVull (r->val[i].part_end), 0);
        (void) hv_store (hv, "part_size", 9, my_newSVull (r->val[i].part_size), 0);
        PUSHs (sv_2mortal (newRV ((SV *) hv)));
      }
      guestfs_free_partition_list (r);

SV *
part_get_parttype (g, device)
      guestfs_h *g;
      char *device;
PREINIT:
      char *r;
   CODE:
      r = guestfs_part_get_parttype (g, device);
      if (r == NULL)
        croak ("%s", guestfs_last_error (g));
      RETVAL = newSVpv (r, 0);
      free (r);
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
      int64_t r;
   CODE:
      r = guestfs_filesize (g, file);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));
      RETVAL = my_newSVll (r);
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
      char *r;
      size_t size;
   CODE:
      r = guestfs_initrd_cat (g, initrdpath, filename, &size);
      if (r == NULL)
        croak ("%s", guestfs_last_error (g));
      RETVAL = newSVpvn (r, size);
      free (r);
 OUTPUT:
      RETVAL

SV *
pvuuid (g, device)
      guestfs_h *g;
      char *device;
PREINIT:
      char *r;
   CODE:
      r = guestfs_pvuuid (g, device);
      if (r == NULL)
        croak ("%s", guestfs_last_error (g));
      RETVAL = newSVpv (r, 0);
      free (r);
 OUTPUT:
      RETVAL

SV *
vguuid (g, vgname)
      guestfs_h *g;
      char *vgname;
PREINIT:
      char *r;
   CODE:
      r = guestfs_vguuid (g, vgname);
      if (r == NULL)
        croak ("%s", guestfs_last_error (g));
      RETVAL = newSVpv (r, 0);
      free (r);
 OUTPUT:
      RETVAL

SV *
lvuuid (g, device)
      guestfs_h *g;
      char *device;
PREINIT:
      char *r;
   CODE:
      r = guestfs_lvuuid (g, device);
      if (r == NULL)
        croak ("%s", guestfs_last_error (g));
      RETVAL = newSVpv (r, 0);
      free (r);
 OUTPUT:
      RETVAL

void
vgpvuuids (g, vgname)
      guestfs_h *g;
      char *vgname;
PREINIT:
      char **r;
      size_t i, n;
 PPCODE:
      r = guestfs_vgpvuuids (g, vgname);
      if (r == NULL)
        croak ("%s", guestfs_last_error (g));
      for (n = 0; r[n] != NULL; ++n) /**/;
      EXTEND (SP, n);
      for (i = 0; i < n; ++i) {
        PUSHs (sv_2mortal (newSVpv (r[i], 0)));
        free (r[i]);
      }
      free (r);

void
vglvuuids (g, vgname)
      guestfs_h *g;
      char *vgname;
PREINIT:
      char **r;
      size_t i, n;
 PPCODE:
      r = guestfs_vglvuuids (g, vgname);
      if (r == NULL)
        croak ("%s", guestfs_last_error (g));
      for (n = 0; r[n] != NULL; ++n) /**/;
      EXTEND (SP, n);
      for (i = 0; i < n; ++i) {
        PUSHs (sv_2mortal (newSVpv (r[i], 0)));
        free (r[i]);
      }
      free (r);

void
copy_size (g, src, dest, size)
      guestfs_h *g;
      char *src;
      char *dest;
      int64_t size;
PREINIT:
      int r;
 PPCODE:
      r = guestfs_copy_size (g, src, dest, size);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

void
zero_device (g, device)
      guestfs_h *g;
      char *device;
PREINIT:
      int r;
 PPCODE:
      r = guestfs_zero_device (g, device);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

void
txz_in (g, tarball, directory)
      guestfs_h *g;
      char *tarball;
      char *directory;
PREINIT:
      int r;
 PPCODE:
      r = guestfs_txz_in (g, tarball, directory);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

void
txz_out (g, directory, tarball)
      guestfs_h *g;
      char *directory;
      char *tarball;
PREINIT:
      int r;
 PPCODE:
      r = guestfs_txz_out (g, directory, tarball);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

void
ntfsresize (g, device)
      guestfs_h *g;
      char *device;
PREINIT:
      int r;
 PPCODE:
      r = guestfs_ntfsresize (g, device);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

void
vgscan (g)
      guestfs_h *g;
PREINIT:
      int r;
 PPCODE:
      r = guestfs_vgscan (g);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

void
part_del (g, device, partnum)
      guestfs_h *g;
      char *device;
      int partnum;
PREINIT:
      int r;
 PPCODE:
      r = guestfs_part_del (g, device, partnum);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

SV *
part_get_bootable (g, device, partnum)
      guestfs_h *g;
      char *device;
      int partnum;
PREINIT:
      int r;
   CODE:
      r = guestfs_part_get_bootable (g, device, partnum);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));
      RETVAL = newSViv (r);
 OUTPUT:
      RETVAL

SV *
part_get_mbr_id (g, device, partnum)
      guestfs_h *g;
      char *device;
      int partnum;
PREINIT:
      int r;
   CODE:
      r = guestfs_part_get_mbr_id (g, device, partnum);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));
      RETVAL = newSViv (r);
 OUTPUT:
      RETVAL

void
part_set_mbr_id (g, device, partnum, idbyte)
      guestfs_h *g;
      char *device;
      int partnum;
      int idbyte;
PREINIT:
      int r;
 PPCODE:
      r = guestfs_part_set_mbr_id (g, device, partnum, idbyte);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

SV *
checksum_device (g, csumtype, device)
      guestfs_h *g;
      char *csumtype;
      char *device;
PREINIT:
      char *r;
   CODE:
      r = guestfs_checksum_device (g, csumtype, device);
      if (r == NULL)
        croak ("%s", guestfs_last_error (g));
      RETVAL = newSVpv (r, 0);
      free (r);
 OUTPUT:
      RETVAL

void
lvresize_free (g, lv, percent)
      guestfs_h *g;
      char *lv;
      int percent;
PREINIT:
      int r;
 PPCODE:
      r = guestfs_lvresize_free (g, lv, percent);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

void
aug_clear (g, augpath)
      guestfs_h *g;
      char *augpath;
PREINIT:
      int r;
 PPCODE:
      r = guestfs_aug_clear (g, augpath);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

SV *
get_umask (g)
      guestfs_h *g;
PREINIT:
      int r;
   CODE:
      r = guestfs_get_umask (g);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));
      RETVAL = newSViv (r);
 OUTPUT:
      RETVAL

void
debug_upload (g, filename, tmpname, mode)
      guestfs_h *g;
      char *filename;
      char *tmpname;
      int mode;
PREINIT:
      int r;
 PPCODE:
      r = guestfs_debug_upload (g, filename, tmpname, mode);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

void
base64_in (g, base64file, filename)
      guestfs_h *g;
      char *base64file;
      char *filename;
PREINIT:
      int r;
 PPCODE:
      r = guestfs_base64_in (g, base64file, filename);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

void
base64_out (g, filename, base64file)
      guestfs_h *g;
      char *filename;
      char *base64file;
PREINIT:
      int r;
 PPCODE:
      r = guestfs_base64_out (g, filename, base64file);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

void
checksums_out (g, csumtype, directory, sumsfile)
      guestfs_h *g;
      char *csumtype;
      char *directory;
      char *sumsfile;
PREINIT:
      int r;
 PPCODE:
      r = guestfs_checksums_out (g, csumtype, directory, sumsfile);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

void
fill_pattern (g, pattern, len, path)
      guestfs_h *g;
      char *pattern;
      int len;
      char *path;
PREINIT:
      int r;
 PPCODE:
      r = guestfs_fill_pattern (g, pattern, len, path);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

void
write (g, path, content)
      guestfs_h *g;
      char *path;
      char *content;
      size_t content_size = SvCUR (ST(2));
PREINIT:
      int r;
 PPCODE:
      r = guestfs_write (g, path, content, content_size);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

SV *
pwrite (g, path, content, offset)
      guestfs_h *g;
      char *path;
      char *content;
      size_t content_size = SvCUR (ST(2));
      int64_t offset;
PREINIT:
      int r;
   CODE:
      r = guestfs_pwrite (g, path, content, content_size, offset);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));
      RETVAL = newSViv (r);
 OUTPUT:
      RETVAL

void
resize2fs_size (g, device, size)
      guestfs_h *g;
      char *device;
      int64_t size;
PREINIT:
      int r;
 PPCODE:
      r = guestfs_resize2fs_size (g, device, size);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

void
pvresize_size (g, device, size)
      guestfs_h *g;
      char *device;
      int64_t size;
PREINIT:
      int r;
 PPCODE:
      r = guestfs_pvresize_size (g, device, size);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

void
ntfsresize_size (g, device, size)
      guestfs_h *g;
      char *device;
      int64_t size;
PREINIT:
      int r;
 PPCODE:
      r = guestfs_ntfsresize_size (g, device, size);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

void
available_all_groups (g)
      guestfs_h *g;
PREINIT:
      char **r;
      size_t i, n;
 PPCODE:
      r = guestfs_available_all_groups (g);
      if (r == NULL)
        croak ("%s", guestfs_last_error (g));
      for (n = 0; r[n] != NULL; ++n) /**/;
      EXTEND (SP, n);
      for (i = 0; i < n; ++i) {
        PUSHs (sv_2mortal (newSVpv (r[i], 0)));
        free (r[i]);
      }
      free (r);

void
fallocate64 (g, path, len)
      guestfs_h *g;
      char *path;
      int64_t len;
PREINIT:
      int r;
 PPCODE:
      r = guestfs_fallocate64 (g, path, len);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

SV *
vfs_label (g, device)
      guestfs_h *g;
      char *device;
PREINIT:
      char *r;
   CODE:
      r = guestfs_vfs_label (g, device);
      if (r == NULL)
        croak ("%s", guestfs_last_error (g));
      RETVAL = newSVpv (r, 0);
      free (r);
 OUTPUT:
      RETVAL

SV *
vfs_uuid (g, device)
      guestfs_h *g;
      char *device;
PREINIT:
      char *r;
   CODE:
      r = guestfs_vfs_uuid (g, device);
      if (r == NULL)
        croak ("%s", guestfs_last_error (g));
      RETVAL = newSVpv (r, 0);
      free (r);
 OUTPUT:
      RETVAL

void
lvm_set_filter (g, devices)
      guestfs_h *g;
      char **devices;
PREINIT:
      int r;
 PPCODE:
      r = guestfs_lvm_set_filter (g, devices);
      free (devices);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

void
lvm_clear_filter (g)
      guestfs_h *g;
PREINIT:
      int r;
 PPCODE:
      r = guestfs_lvm_clear_filter (g);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

void
luks_open (g, device, key, mapname)
      guestfs_h *g;
      char *device;
      char *key;
      char *mapname;
PREINIT:
      int r;
 PPCODE:
      r = guestfs_luks_open (g, device, key, mapname);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

void
luks_open_ro (g, device, key, mapname)
      guestfs_h *g;
      char *device;
      char *key;
      char *mapname;
PREINIT:
      int r;
 PPCODE:
      r = guestfs_luks_open_ro (g, device, key, mapname);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

void
luks_close (g, device)
      guestfs_h *g;
      char *device;
PREINIT:
      int r;
 PPCODE:
      r = guestfs_luks_close (g, device);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

void
luks_format (g, device, key, keyslot)
      guestfs_h *g;
      char *device;
      char *key;
      int keyslot;
PREINIT:
      int r;
 PPCODE:
      r = guestfs_luks_format (g, device, key, keyslot);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

void
luks_format_cipher (g, device, key, keyslot, cipher)
      guestfs_h *g;
      char *device;
      char *key;
      int keyslot;
      char *cipher;
PREINIT:
      int r;
 PPCODE:
      r = guestfs_luks_format_cipher (g, device, key, keyslot, cipher);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

void
luks_add_key (g, device, key, newkey, keyslot)
      guestfs_h *g;
      char *device;
      char *key;
      char *newkey;
      int keyslot;
PREINIT:
      int r;
 PPCODE:
      r = guestfs_luks_add_key (g, device, key, newkey, keyslot);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

void
luks_kill_slot (g, device, key, keyslot)
      guestfs_h *g;
      char *device;
      char *key;
      int keyslot;
PREINIT:
      int r;
 PPCODE:
      r = guestfs_luks_kill_slot (g, device, key, keyslot);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

SV *
is_lv (g, device)
      guestfs_h *g;
      char *device;
PREINIT:
      int r;
   CODE:
      r = guestfs_is_lv (g, device);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));
      RETVAL = newSViv (r);
 OUTPUT:
      RETVAL

SV *
findfs_uuid (g, uuid)
      guestfs_h *g;
      char *uuid;
PREINIT:
      char *r;
   CODE:
      r = guestfs_findfs_uuid (g, uuid);
      if (r == NULL)
        croak ("%s", guestfs_last_error (g));
      RETVAL = newSVpv (r, 0);
      free (r);
 OUTPUT:
      RETVAL

SV *
findfs_label (g, label)
      guestfs_h *g;
      char *label;
PREINIT:
      char *r;
   CODE:
      r = guestfs_findfs_label (g, label);
      if (r == NULL)
        croak ("%s", guestfs_last_error (g));
      RETVAL = newSVpv (r, 0);
      free (r);
 OUTPUT:
      RETVAL

SV *
is_chardev (g, path)
      guestfs_h *g;
      char *path;
PREINIT:
      int r;
   CODE:
      r = guestfs_is_chardev (g, path);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));
      RETVAL = newSViv (r);
 OUTPUT:
      RETVAL

SV *
is_blockdev (g, path)
      guestfs_h *g;
      char *path;
PREINIT:
      int r;
   CODE:
      r = guestfs_is_blockdev (g, path);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));
      RETVAL = newSViv (r);
 OUTPUT:
      RETVAL

SV *
is_fifo (g, path)
      guestfs_h *g;
      char *path;
PREINIT:
      int r;
   CODE:
      r = guestfs_is_fifo (g, path);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));
      RETVAL = newSViv (r);
 OUTPUT:
      RETVAL

SV *
is_symlink (g, path)
      guestfs_h *g;
      char *path;
PREINIT:
      int r;
   CODE:
      r = guestfs_is_symlink (g, path);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));
      RETVAL = newSViv (r);
 OUTPUT:
      RETVAL

SV *
is_socket (g, path)
      guestfs_h *g;
      char *path;
PREINIT:
      int r;
   CODE:
      r = guestfs_is_socket (g, path);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));
      RETVAL = newSViv (r);
 OUTPUT:
      RETVAL

SV *
part_to_dev (g, partition)
      guestfs_h *g;
      char *partition;
PREINIT:
      char *r;
   CODE:
      r = guestfs_part_to_dev (g, partition);
      if (r == NULL)
        croak ("%s", guestfs_last_error (g));
      RETVAL = newSVpv (r, 0);
      free (r);
 OUTPUT:
      RETVAL

void
upload_offset (g, filename, remotefilename, offset)
      guestfs_h *g;
      char *filename;
      char *remotefilename;
      int64_t offset;
PREINIT:
      int r;
 PPCODE:
      r = guestfs_upload_offset (g, filename, remotefilename, offset);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

void
download_offset (g, remotefilename, filename, offset, size)
      guestfs_h *g;
      char *remotefilename;
      char *filename;
      int64_t offset;
      int64_t size;
PREINIT:
      int r;
 PPCODE:
      r = guestfs_download_offset (g, remotefilename, filename, offset, size);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

SV *
pwrite_device (g, device, content, offset)
      guestfs_h *g;
      char *device;
      char *content;
      size_t content_size = SvCUR (ST(2));
      int64_t offset;
PREINIT:
      int r;
   CODE:
      r = guestfs_pwrite_device (g, device, content, content_size, offset);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));
      RETVAL = newSViv (r);
 OUTPUT:
      RETVAL

SV *
pread_device (g, device, count, offset)
      guestfs_h *g;
      char *device;
      int count;
      int64_t offset;
PREINIT:
      char *r;
      size_t size;
   CODE:
      r = guestfs_pread_device (g, device, count, offset, &size);
      if (r == NULL)
        croak ("%s", guestfs_last_error (g));
      RETVAL = newSVpvn (r, size);
      free (r);
 OUTPUT:
      RETVAL

SV *
lvm_canonical_lv_name (g, lvname)
      guestfs_h *g;
      char *lvname;
PREINIT:
      char *r;
   CODE:
      r = guestfs_lvm_canonical_lv_name (g, lvname);
      if (r == NULL)
        croak ("%s", guestfs_last_error (g));
      RETVAL = newSVpv (r, 0);
      free (r);
 OUTPUT:
      RETVAL

void
mkfs_opts (g, fstype, device, ...)
      guestfs_h *g;
      char *fstype;
      char *device;
PREINIT:
      int r;
      struct guestfs_mkfs_opts_argv optargs_s = { .bitmask = 0 };
      struct guestfs_mkfs_opts_argv *optargs = &optargs_s;
      size_t items_i;
 PPCODE:
      if (((items - 3) & 1) != 0)
        croak ("expecting an even number of extra parameters");
      for (items_i = 3; items_i < items; items_i += 2) {
        uint64_t this_mask;
        const char *this_arg;

        this_arg = SvPV_nolen (ST (items_i));
        if (strcmp (this_arg, "blocksize") == 0) {
          optargs_s.blocksize = SvIV (ST (items_i+1));
          this_mask = GUESTFS_MKFS_OPTS_BLOCKSIZE_BITMASK;
        }
        else if (strcmp (this_arg, "features") == 0) {
          optargs_s.features = SvPV_nolen (ST (items_i+1));
          this_mask = GUESTFS_MKFS_OPTS_FEATURES_BITMASK;
        }
        else if (strcmp (this_arg, "inode") == 0) {
          optargs_s.inode = SvIV (ST (items_i+1));
          this_mask = GUESTFS_MKFS_OPTS_INODE_BITMASK;
        }
        else if (strcmp (this_arg, "sectorsize") == 0) {
          optargs_s.sectorsize = SvIV (ST (items_i+1));
          this_mask = GUESTFS_MKFS_OPTS_SECTORSIZE_BITMASK;
        }
        else croak ("unknown optional argument '%s'", this_arg);
        if (optargs_s.bitmask & this_mask)
          croak ("optional argument '%s' given twice",
                 this_arg);
        optargs_s.bitmask |= this_mask;
      }

      r = guestfs_mkfs_opts_argv (g, fstype, device, optargs);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

SV *
getxattr (g, path, name)
      guestfs_h *g;
      char *path;
      char *name;
PREINIT:
      char *r;
      size_t size;
   CODE:
      r = guestfs_getxattr (g, path, name, &size);
      if (r == NULL)
        croak ("%s", guestfs_last_error (g));
      RETVAL = newSVpvn (r, size);
      free (r);
 OUTPUT:
      RETVAL

SV *
lgetxattr (g, path, name)
      guestfs_h *g;
      char *path;
      char *name;
PREINIT:
      char *r;
      size_t size;
   CODE:
      r = guestfs_lgetxattr (g, path, name, &size);
      if (r == NULL)
        croak ("%s", guestfs_last_error (g));
      RETVAL = newSVpvn (r, size);
      free (r);
 OUTPUT:
      RETVAL

void
resize2fs_M (g, device)
      guestfs_h *g;
      char *device;
PREINIT:
      int r;
 PPCODE:
      r = guestfs_resize2fs_M (g, device);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

void
internal_autosync (g)
      guestfs_h *g;
PREINIT:
      int r;
 PPCODE:
      r = guestfs_internal_autosync (g);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

SV *
is_zero (g, path)
      guestfs_h *g;
      char *path;
PREINIT:
      int r;
   CODE:
      r = guestfs_is_zero (g, path);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));
      RETVAL = newSViv (r);
 OUTPUT:
      RETVAL

SV *
is_zero_device (g, device)
      guestfs_h *g;
      char *device;
PREINIT:
      int r;
   CODE:
      r = guestfs_is_zero_device (g, device);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));
      RETVAL = newSViv (r);
 OUTPUT:
      RETVAL

void
list_9p (g)
      guestfs_h *g;
PREINIT:
      char **r;
      size_t i, n;
 PPCODE:
      r = guestfs_list_9p (g);
      if (r == NULL)
        croak ("%s", guestfs_last_error (g));
      for (n = 0; r[n] != NULL; ++n) /**/;
      EXTEND (SP, n);
      for (i = 0; i < n; ++i) {
        PUSHs (sv_2mortal (newSVpv (r[i], 0)));
        free (r[i]);
      }
      free (r);

void
mount_9p (g, mounttag, mountpoint, ...)
      guestfs_h *g;
      char *mounttag;
      char *mountpoint;
PREINIT:
      int r;
      struct guestfs_mount_9p_argv optargs_s = { .bitmask = 0 };
      struct guestfs_mount_9p_argv *optargs = &optargs_s;
      size_t items_i;
 PPCODE:
      if (((items - 3) & 1) != 0)
        croak ("expecting an even number of extra parameters");
      for (items_i = 3; items_i < items; items_i += 2) {
        uint64_t this_mask;
        const char *this_arg;

        this_arg = SvPV_nolen (ST (items_i));
        if (strcmp (this_arg, "options") == 0) {
          optargs_s.options = SvPV_nolen (ST (items_i+1));
          this_mask = GUESTFS_MOUNT_9P_OPTIONS_BITMASK;
        }
        else croak ("unknown optional argument '%s'", this_arg);
        if (optargs_s.bitmask & this_mask)
          croak ("optional argument '%s' given twice",
                 this_arg);
        optargs_s.bitmask |= this_mask;
      }

      r = guestfs_mount_9p_argv (g, mounttag, mountpoint, optargs);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

void
list_dm_devices (g)
      guestfs_h *g;
PREINIT:
      char **r;
      size_t i, n;
 PPCODE:
      r = guestfs_list_dm_devices (g);
      if (r == NULL)
        croak ("%s", guestfs_last_error (g));
      for (n = 0; r[n] != NULL; ++n) /**/;
      EXTEND (SP, n);
      for (i = 0; i < n; ++i) {
        PUSHs (sv_2mortal (newSVpv (r[i], 0)));
        free (r[i]);
      }
      free (r);

void
ntfsresize_opts (g, device, ...)
      guestfs_h *g;
      char *device;
PREINIT:
      int r;
      struct guestfs_ntfsresize_opts_argv optargs_s = { .bitmask = 0 };
      struct guestfs_ntfsresize_opts_argv *optargs = &optargs_s;
      size_t items_i;
 PPCODE:
      if (((items - 2) & 1) != 0)
        croak ("expecting an even number of extra parameters");
      for (items_i = 2; items_i < items; items_i += 2) {
        uint64_t this_mask;
        const char *this_arg;

        this_arg = SvPV_nolen (ST (items_i));
        if (strcmp (this_arg, "size") == 0) {
          optargs_s.size = SvIV (ST (items_i+1));
          this_mask = GUESTFS_NTFSRESIZE_OPTS_SIZE_BITMASK;
        }
        else if (strcmp (this_arg, "force") == 0) {
          optargs_s.force = SvIV (ST (items_i+1));
          this_mask = GUESTFS_NTFSRESIZE_OPTS_FORCE_BITMASK;
        }
        else croak ("unknown optional argument '%s'", this_arg);
        if (optargs_s.bitmask & this_mask)
          croak ("optional argument '%s' given twice",
                 this_arg);
        optargs_s.bitmask |= this_mask;
      }

      r = guestfs_ntfsresize_opts_argv (g, device, optargs);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

void
btrfs_filesystem_resize (g, mountpoint, ...)
      guestfs_h *g;
      char *mountpoint;
PREINIT:
      int r;
      struct guestfs_btrfs_filesystem_resize_argv optargs_s = { .bitmask = 0 };
      struct guestfs_btrfs_filesystem_resize_argv *optargs = &optargs_s;
      size_t items_i;
 PPCODE:
      if (((items - 2) & 1) != 0)
        croak ("expecting an even number of extra parameters");
      for (items_i = 2; items_i < items; items_i += 2) {
        uint64_t this_mask;
        const char *this_arg;

        this_arg = SvPV_nolen (ST (items_i));
        if (strcmp (this_arg, "size") == 0) {
          optargs_s.size = SvIV (ST (items_i+1));
          this_mask = GUESTFS_BTRFS_FILESYSTEM_RESIZE_SIZE_BITMASK;
        }
        else croak ("unknown optional argument '%s'", this_arg);
        if (optargs_s.bitmask & this_mask)
          croak ("optional argument '%s' given twice",
                 this_arg);
        optargs_s.bitmask |= this_mask;
      }

      r = guestfs_btrfs_filesystem_resize_argv (g, mountpoint, optargs);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

void
write_append (g, path, content)
      guestfs_h *g;
      char *path;
      char *content;
      size_t content_size = SvCUR (ST(2));
PREINIT:
      int r;
 PPCODE:
      r = guestfs_write_append (g, path, content, content_size);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

void
compress_out (g, ctype, file, zfile, ...)
      guestfs_h *g;
      char *ctype;
      char *file;
      char *zfile;
PREINIT:
      int r;
      struct guestfs_compress_out_argv optargs_s = { .bitmask = 0 };
      struct guestfs_compress_out_argv *optargs = &optargs_s;
      size_t items_i;
 PPCODE:
      if (((items - 4) & 1) != 0)
        croak ("expecting an even number of extra parameters");
      for (items_i = 4; items_i < items; items_i += 2) {
        uint64_t this_mask;
        const char *this_arg;

        this_arg = SvPV_nolen (ST (items_i));
        if (strcmp (this_arg, "level") == 0) {
          optargs_s.level = SvIV (ST (items_i+1));
          this_mask = GUESTFS_COMPRESS_OUT_LEVEL_BITMASK;
        }
        else croak ("unknown optional argument '%s'", this_arg);
        if (optargs_s.bitmask & this_mask)
          croak ("optional argument '%s' given twice",
                 this_arg);
        optargs_s.bitmask |= this_mask;
      }

      r = guestfs_compress_out_argv (g, ctype, file, zfile, optargs);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

void
compress_device_out (g, ctype, device, zdevice, ...)
      guestfs_h *g;
      char *ctype;
      char *device;
      char *zdevice;
PREINIT:
      int r;
      struct guestfs_compress_device_out_argv optargs_s = { .bitmask = 0 };
      struct guestfs_compress_device_out_argv *optargs = &optargs_s;
      size_t items_i;
 PPCODE:
      if (((items - 4) & 1) != 0)
        croak ("expecting an even number of extra parameters");
      for (items_i = 4; items_i < items; items_i += 2) {
        uint64_t this_mask;
        const char *this_arg;

        this_arg = SvPV_nolen (ST (items_i));
        if (strcmp (this_arg, "level") == 0) {
          optargs_s.level = SvIV (ST (items_i+1));
          this_mask = GUESTFS_COMPRESS_DEVICE_OUT_LEVEL_BITMASK;
        }
        else croak ("unknown optional argument '%s'", this_arg);
        if (optargs_s.bitmask & this_mask)
          croak ("optional argument '%s' given twice",
                 this_arg);
        optargs_s.bitmask |= this_mask;
      }

      r = guestfs_compress_device_out_argv (g, ctype, device, zdevice, optargs);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

SV *
part_to_partnum (g, partition)
      guestfs_h *g;
      char *partition;
PREINIT:
      int r;
   CODE:
      r = guestfs_part_to_partnum (g, partition);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));
      RETVAL = newSViv (r);
 OUTPUT:
      RETVAL

void
copy_device_to_device (g, src, dest, ...)
      guestfs_h *g;
      char *src;
      char *dest;
PREINIT:
      int r;
      struct guestfs_copy_device_to_device_argv optargs_s = { .bitmask = 0 };
      struct guestfs_copy_device_to_device_argv *optargs = &optargs_s;
      size_t items_i;
 PPCODE:
      if (((items - 3) & 1) != 0)
        croak ("expecting an even number of extra parameters");
      for (items_i = 3; items_i < items; items_i += 2) {
        uint64_t this_mask;
        const char *this_arg;

        this_arg = SvPV_nolen (ST (items_i));
        if (strcmp (this_arg, "srcoffset") == 0) {
          optargs_s.srcoffset = SvIV (ST (items_i+1));
          this_mask = GUESTFS_COPY_DEVICE_TO_DEVICE_SRCOFFSET_BITMASK;
        }
        else if (strcmp (this_arg, "destoffset") == 0) {
          optargs_s.destoffset = SvIV (ST (items_i+1));
          this_mask = GUESTFS_COPY_DEVICE_TO_DEVICE_DESTOFFSET_BITMASK;
        }
        else if (strcmp (this_arg, "size") == 0) {
          optargs_s.size = SvIV (ST (items_i+1));
          this_mask = GUESTFS_COPY_DEVICE_TO_DEVICE_SIZE_BITMASK;
        }
        else croak ("unknown optional argument '%s'", this_arg);
        if (optargs_s.bitmask & this_mask)
          croak ("optional argument '%s' given twice",
                 this_arg);
        optargs_s.bitmask |= this_mask;
      }

      r = guestfs_copy_device_to_device_argv (g, src, dest, optargs);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

void
copy_device_to_file (g, src, dest, ...)
      guestfs_h *g;
      char *src;
      char *dest;
PREINIT:
      int r;
      struct guestfs_copy_device_to_file_argv optargs_s = { .bitmask = 0 };
      struct guestfs_copy_device_to_file_argv *optargs = &optargs_s;
      size_t items_i;
 PPCODE:
      if (((items - 3) & 1) != 0)
        croak ("expecting an even number of extra parameters");
      for (items_i = 3; items_i < items; items_i += 2) {
        uint64_t this_mask;
        const char *this_arg;

        this_arg = SvPV_nolen (ST (items_i));
        if (strcmp (this_arg, "srcoffset") == 0) {
          optargs_s.srcoffset = SvIV (ST (items_i+1));
          this_mask = GUESTFS_COPY_DEVICE_TO_FILE_SRCOFFSET_BITMASK;
        }
        else if (strcmp (this_arg, "destoffset") == 0) {
          optargs_s.destoffset = SvIV (ST (items_i+1));
          this_mask = GUESTFS_COPY_DEVICE_TO_FILE_DESTOFFSET_BITMASK;
        }
        else if (strcmp (this_arg, "size") == 0) {
          optargs_s.size = SvIV (ST (items_i+1));
          this_mask = GUESTFS_COPY_DEVICE_TO_FILE_SIZE_BITMASK;
        }
        else croak ("unknown optional argument '%s'", this_arg);
        if (optargs_s.bitmask & this_mask)
          croak ("optional argument '%s' given twice",
                 this_arg);
        optargs_s.bitmask |= this_mask;
      }

      r = guestfs_copy_device_to_file_argv (g, src, dest, optargs);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

void
copy_file_to_device (g, src, dest, ...)
      guestfs_h *g;
      char *src;
      char *dest;
PREINIT:
      int r;
      struct guestfs_copy_file_to_device_argv optargs_s = { .bitmask = 0 };
      struct guestfs_copy_file_to_device_argv *optargs = &optargs_s;
      size_t items_i;
 PPCODE:
      if (((items - 3) & 1) != 0)
        croak ("expecting an even number of extra parameters");
      for (items_i = 3; items_i < items; items_i += 2) {
        uint64_t this_mask;
        const char *this_arg;

        this_arg = SvPV_nolen (ST (items_i));
        if (strcmp (this_arg, "srcoffset") == 0) {
          optargs_s.srcoffset = SvIV (ST (items_i+1));
          this_mask = GUESTFS_COPY_FILE_TO_DEVICE_SRCOFFSET_BITMASK;
        }
        else if (strcmp (this_arg, "destoffset") == 0) {
          optargs_s.destoffset = SvIV (ST (items_i+1));
          this_mask = GUESTFS_COPY_FILE_TO_DEVICE_DESTOFFSET_BITMASK;
        }
        else if (strcmp (this_arg, "size") == 0) {
          optargs_s.size = SvIV (ST (items_i+1));
          this_mask = GUESTFS_COPY_FILE_TO_DEVICE_SIZE_BITMASK;
        }
        else croak ("unknown optional argument '%s'", this_arg);
        if (optargs_s.bitmask & this_mask)
          croak ("optional argument '%s' given twice",
                 this_arg);
        optargs_s.bitmask |= this_mask;
      }

      r = guestfs_copy_file_to_device_argv (g, src, dest, optargs);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

void
copy_file_to_file (g, src, dest, ...)
      guestfs_h *g;
      char *src;
      char *dest;
PREINIT:
      int r;
      struct guestfs_copy_file_to_file_argv optargs_s = { .bitmask = 0 };
      struct guestfs_copy_file_to_file_argv *optargs = &optargs_s;
      size_t items_i;
 PPCODE:
      if (((items - 3) & 1) != 0)
        croak ("expecting an even number of extra parameters");
      for (items_i = 3; items_i < items; items_i += 2) {
        uint64_t this_mask;
        const char *this_arg;

        this_arg = SvPV_nolen (ST (items_i));
        if (strcmp (this_arg, "srcoffset") == 0) {
          optargs_s.srcoffset = SvIV (ST (items_i+1));
          this_mask = GUESTFS_COPY_FILE_TO_FILE_SRCOFFSET_BITMASK;
        }
        else if (strcmp (this_arg, "destoffset") == 0) {
          optargs_s.destoffset = SvIV (ST (items_i+1));
          this_mask = GUESTFS_COPY_FILE_TO_FILE_DESTOFFSET_BITMASK;
        }
        else if (strcmp (this_arg, "size") == 0) {
          optargs_s.size = SvIV (ST (items_i+1));
          this_mask = GUESTFS_COPY_FILE_TO_FILE_SIZE_BITMASK;
        }
        else croak ("unknown optional argument '%s'", this_arg);
        if (optargs_s.bitmask & this_mask)
          croak ("optional argument '%s' given twice",
                 this_arg);
        optargs_s.bitmask |= this_mask;
      }

      r = guestfs_copy_file_to_file_argv (g, src, dest, optargs);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

