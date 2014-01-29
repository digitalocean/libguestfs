/* libguestfs generated file
 * WARNING: THIS FILE IS GENERATED FROM:
 *   generator/ *.ml
 * ANY CHANGES YOU MAKE TO THIS FILE WILL BE LOST.
 *
 * Copyright (C) 2009-2014 Red Hat Inc.
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
#include <string.h>
#include <inttypes.h>
#include <errno.h>

#include "EXTERN.h"
#include "perl.h"
#include "XSUB.h"

/* perl CORE/config.h defines '_' to something completely bonkers. */
#ifdef _
#undef _
#endif

#include <guestfs.h>
#include "guestfs-internal-frontend.h"

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

/* Convert a 64 bit int on input.  To cope with the case of having
 * a 32 bit Perl interpreter, we allow the user to pass a string
 * here which is scanned as a 64 bit integer.
 */
static int64_t
my_SvIV64 (SV *sv)
{
#ifdef USE_64_BIT_ALL
  return SvIV (sv);
#else
  if (SvTYPE (sv) == SVt_PV) {
    const char *str = SvPV_nolen (sv);
    int64_t r;

    sscanf (str, "%" SCNi64, &r);
    return r;
  }
  else
    return SvIV (sv);
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
  r = guestfs___safe_malloc (g, sizeof (SV *) * (*len_rtn));

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
_create (flags)
      unsigned flags;
   CODE:
      RETVAL = guestfs_create_flags (flags);
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
event_to_string (event_bitmask)
      int event_bitmask;
PREINIT:
      char *str;
   CODE:
      str = guestfs_event_to_string (event_bitmask);
      if (str == NULL)
        croak ("%s", strerror (errno));
      RETVAL = newSVpv (str, 0);
      free (str);
 OUTPUT:
      RETVAL

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
internal_test (g, str, optstr, strlist, b, integer, integer64, filein, fileout, bufferin, ...)
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
      struct guestfs_internal_test_argv optargs_s = { .bitmask = 0 };
      struct guestfs_internal_test_argv *optargs = &optargs_s;
      size_t items_i;
 PPCODE:
      if (((items - 10) & 1) != 0)
        croak ("expecting an even number of extra parameters");
      for (items_i = 10; items_i < items; items_i += 2) {
        uint64_t this_mask;
        const char *this_arg;

        this_arg = SvPV_nolen (ST (items_i));
        if (STREQ (this_arg, "obool")) {
          optargs_s.obool = SvIV (ST (items_i+1));
          this_mask = GUESTFS_INTERNAL_TEST_OBOOL_BITMASK;
        }
        else if (STREQ (this_arg, "oint")) {
          optargs_s.oint = SvIV (ST (items_i+1));
          this_mask = GUESTFS_INTERNAL_TEST_OINT_BITMASK;
        }
        else if (STREQ (this_arg, "oint64")) {
          optargs_s.oint64 = my_SvIV64 (ST (items_i+1));
          this_mask = GUESTFS_INTERNAL_TEST_OINT64_BITMASK;
        }
        else if (STREQ (this_arg, "ostring")) {
          optargs_s.ostring = SvPV_nolen (ST (items_i+1));
          this_mask = GUESTFS_INTERNAL_TEST_OSTRING_BITMASK;
        }
        else if (STREQ (this_arg, "ostringlist")) {
          size_t i, len;
          char **r;
          SV *arg;
          AV *av;
          SV **svp;

          arg = ST (items_i+1);
          if (!SvROK (arg) || SvTYPE (SvRV (arg)) != SVt_PVAV)
            croak ("array reference expected for '%s' argument", "ostringlist");
          av = (AV *) SvRV (ST (items_i+1));

          /* Note av_len returns index of final element. */
          len = av_len (av) + 1;

          r = guestfs___safe_malloc (g, (len+1) * sizeof (char *));
          for (i = 0; i < len; ++i) {
            svp = av_fetch (av, i, 0);
            r[i] = SvPV_nolen (*svp);
          }
          r[i] = NULL;
          optargs_s.ostringlist = r;
          this_mask = GUESTFS_INTERNAL_TEST_OSTRINGLIST_BITMASK;
        }
        else croak ("unknown optional argument '%s'", this_arg);
        if (optargs_s.bitmask & this_mask)
          croak ("optional argument '%s' given twice",
                 this_arg);
        optargs_s.bitmask |= this_mask;
      }

      r = guestfs_internal_test_argv (g, str, optstr, strlist, b, integer, integer64, filein, fileout, bufferin, bufferin_size, optargs);
      free (strlist);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

void
internal_test_only_optargs (g, ...)
      guestfs_h *g;
PREINIT:
      int r;
      struct guestfs_internal_test_only_optargs_argv optargs_s = { .bitmask = 0 };
      struct guestfs_internal_test_only_optargs_argv *optargs = &optargs_s;
      size_t items_i;
 PPCODE:
      if (((items - 1) & 1) != 0)
        croak ("expecting an even number of extra parameters");
      for (items_i = 1; items_i < items; items_i += 2) {
        uint64_t this_mask;
        const char *this_arg;

        this_arg = SvPV_nolen (ST (items_i));
        if (STREQ (this_arg, "test")) {
          optargs_s.test = SvIV (ST (items_i+1));
          this_mask = GUESTFS_INTERNAL_TEST_ONLY_OPTARGS_TEST_BITMASK;
        }
        else croak ("unknown optional argument '%s'", this_arg);
        if (optargs_s.bitmask & this_mask)
          croak ("optional argument '%s' given twice",
                 this_arg);
        optargs_s.bitmask |= this_mask;
      }

      r = guestfs_internal_test_only_optargs_argv (g, optargs);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

void
internal_test_63_optargs (g, ...)
      guestfs_h *g;
PREINIT:
      int r;
      struct guestfs_internal_test_63_optargs_argv optargs_s = { .bitmask = 0 };
      struct guestfs_internal_test_63_optargs_argv *optargs = &optargs_s;
      size_t items_i;
 PPCODE:
      if (((items - 1) & 1) != 0)
        croak ("expecting an even number of extra parameters");
      for (items_i = 1; items_i < items; items_i += 2) {
        uint64_t this_mask;
        const char *this_arg;

        this_arg = SvPV_nolen (ST (items_i));
        if (STREQ (this_arg, "opt1")) {
          optargs_s.opt1 = SvIV (ST (items_i+1));
          this_mask = GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT1_BITMASK;
        }
        else if (STREQ (this_arg, "opt2")) {
          optargs_s.opt2 = SvIV (ST (items_i+1));
          this_mask = GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT2_BITMASK;
        }
        else if (STREQ (this_arg, "opt3")) {
          optargs_s.opt3 = SvIV (ST (items_i+1));
          this_mask = GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT3_BITMASK;
        }
        else if (STREQ (this_arg, "opt4")) {
          optargs_s.opt4 = SvIV (ST (items_i+1));
          this_mask = GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT4_BITMASK;
        }
        else if (STREQ (this_arg, "opt5")) {
          optargs_s.opt5 = SvIV (ST (items_i+1));
          this_mask = GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT5_BITMASK;
        }
        else if (STREQ (this_arg, "opt6")) {
          optargs_s.opt6 = SvIV (ST (items_i+1));
          this_mask = GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT6_BITMASK;
        }
        else if (STREQ (this_arg, "opt7")) {
          optargs_s.opt7 = SvIV (ST (items_i+1));
          this_mask = GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT7_BITMASK;
        }
        else if (STREQ (this_arg, "opt8")) {
          optargs_s.opt8 = SvIV (ST (items_i+1));
          this_mask = GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT8_BITMASK;
        }
        else if (STREQ (this_arg, "opt9")) {
          optargs_s.opt9 = SvIV (ST (items_i+1));
          this_mask = GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT9_BITMASK;
        }
        else if (STREQ (this_arg, "opt10")) {
          optargs_s.opt10 = SvIV (ST (items_i+1));
          this_mask = GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT10_BITMASK;
        }
        else if (STREQ (this_arg, "opt11")) {
          optargs_s.opt11 = SvIV (ST (items_i+1));
          this_mask = GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT11_BITMASK;
        }
        else if (STREQ (this_arg, "opt12")) {
          optargs_s.opt12 = SvIV (ST (items_i+1));
          this_mask = GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT12_BITMASK;
        }
        else if (STREQ (this_arg, "opt13")) {
          optargs_s.opt13 = SvIV (ST (items_i+1));
          this_mask = GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT13_BITMASK;
        }
        else if (STREQ (this_arg, "opt14")) {
          optargs_s.opt14 = SvIV (ST (items_i+1));
          this_mask = GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT14_BITMASK;
        }
        else if (STREQ (this_arg, "opt15")) {
          optargs_s.opt15 = SvIV (ST (items_i+1));
          this_mask = GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT15_BITMASK;
        }
        else if (STREQ (this_arg, "opt16")) {
          optargs_s.opt16 = SvIV (ST (items_i+1));
          this_mask = GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT16_BITMASK;
        }
        else if (STREQ (this_arg, "opt17")) {
          optargs_s.opt17 = SvIV (ST (items_i+1));
          this_mask = GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT17_BITMASK;
        }
        else if (STREQ (this_arg, "opt18")) {
          optargs_s.opt18 = SvIV (ST (items_i+1));
          this_mask = GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT18_BITMASK;
        }
        else if (STREQ (this_arg, "opt19")) {
          optargs_s.opt19 = SvIV (ST (items_i+1));
          this_mask = GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT19_BITMASK;
        }
        else if (STREQ (this_arg, "opt20")) {
          optargs_s.opt20 = SvIV (ST (items_i+1));
          this_mask = GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT20_BITMASK;
        }
        else if (STREQ (this_arg, "opt21")) {
          optargs_s.opt21 = SvIV (ST (items_i+1));
          this_mask = GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT21_BITMASK;
        }
        else if (STREQ (this_arg, "opt22")) {
          optargs_s.opt22 = SvIV (ST (items_i+1));
          this_mask = GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT22_BITMASK;
        }
        else if (STREQ (this_arg, "opt23")) {
          optargs_s.opt23 = SvIV (ST (items_i+1));
          this_mask = GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT23_BITMASK;
        }
        else if (STREQ (this_arg, "opt24")) {
          optargs_s.opt24 = SvIV (ST (items_i+1));
          this_mask = GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT24_BITMASK;
        }
        else if (STREQ (this_arg, "opt25")) {
          optargs_s.opt25 = SvIV (ST (items_i+1));
          this_mask = GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT25_BITMASK;
        }
        else if (STREQ (this_arg, "opt26")) {
          optargs_s.opt26 = SvIV (ST (items_i+1));
          this_mask = GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT26_BITMASK;
        }
        else if (STREQ (this_arg, "opt27")) {
          optargs_s.opt27 = SvIV (ST (items_i+1));
          this_mask = GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT27_BITMASK;
        }
        else if (STREQ (this_arg, "opt28")) {
          optargs_s.opt28 = SvIV (ST (items_i+1));
          this_mask = GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT28_BITMASK;
        }
        else if (STREQ (this_arg, "opt29")) {
          optargs_s.opt29 = SvIV (ST (items_i+1));
          this_mask = GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT29_BITMASK;
        }
        else if (STREQ (this_arg, "opt30")) {
          optargs_s.opt30 = SvIV (ST (items_i+1));
          this_mask = GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT30_BITMASK;
        }
        else if (STREQ (this_arg, "opt31")) {
          optargs_s.opt31 = SvIV (ST (items_i+1));
          this_mask = GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT31_BITMASK;
        }
        else if (STREQ (this_arg, "opt32")) {
          optargs_s.opt32 = SvIV (ST (items_i+1));
          this_mask = GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT32_BITMASK;
        }
        else if (STREQ (this_arg, "opt33")) {
          optargs_s.opt33 = SvIV (ST (items_i+1));
          this_mask = GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT33_BITMASK;
        }
        else if (STREQ (this_arg, "opt34")) {
          optargs_s.opt34 = SvIV (ST (items_i+1));
          this_mask = GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT34_BITMASK;
        }
        else if (STREQ (this_arg, "opt35")) {
          optargs_s.opt35 = SvIV (ST (items_i+1));
          this_mask = GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT35_BITMASK;
        }
        else if (STREQ (this_arg, "opt36")) {
          optargs_s.opt36 = SvIV (ST (items_i+1));
          this_mask = GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT36_BITMASK;
        }
        else if (STREQ (this_arg, "opt37")) {
          optargs_s.opt37 = SvIV (ST (items_i+1));
          this_mask = GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT37_BITMASK;
        }
        else if (STREQ (this_arg, "opt38")) {
          optargs_s.opt38 = SvIV (ST (items_i+1));
          this_mask = GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT38_BITMASK;
        }
        else if (STREQ (this_arg, "opt39")) {
          optargs_s.opt39 = SvIV (ST (items_i+1));
          this_mask = GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT39_BITMASK;
        }
        else if (STREQ (this_arg, "opt40")) {
          optargs_s.opt40 = SvIV (ST (items_i+1));
          this_mask = GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT40_BITMASK;
        }
        else if (STREQ (this_arg, "opt41")) {
          optargs_s.opt41 = SvIV (ST (items_i+1));
          this_mask = GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT41_BITMASK;
        }
        else if (STREQ (this_arg, "opt42")) {
          optargs_s.opt42 = SvIV (ST (items_i+1));
          this_mask = GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT42_BITMASK;
        }
        else if (STREQ (this_arg, "opt43")) {
          optargs_s.opt43 = SvIV (ST (items_i+1));
          this_mask = GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT43_BITMASK;
        }
        else if (STREQ (this_arg, "opt44")) {
          optargs_s.opt44 = SvIV (ST (items_i+1));
          this_mask = GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT44_BITMASK;
        }
        else if (STREQ (this_arg, "opt45")) {
          optargs_s.opt45 = SvIV (ST (items_i+1));
          this_mask = GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT45_BITMASK;
        }
        else if (STREQ (this_arg, "opt46")) {
          optargs_s.opt46 = SvIV (ST (items_i+1));
          this_mask = GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT46_BITMASK;
        }
        else if (STREQ (this_arg, "opt47")) {
          optargs_s.opt47 = SvIV (ST (items_i+1));
          this_mask = GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT47_BITMASK;
        }
        else if (STREQ (this_arg, "opt48")) {
          optargs_s.opt48 = SvIV (ST (items_i+1));
          this_mask = GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT48_BITMASK;
        }
        else if (STREQ (this_arg, "opt49")) {
          optargs_s.opt49 = SvIV (ST (items_i+1));
          this_mask = GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT49_BITMASK;
        }
        else if (STREQ (this_arg, "opt50")) {
          optargs_s.opt50 = SvIV (ST (items_i+1));
          this_mask = GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT50_BITMASK;
        }
        else if (STREQ (this_arg, "opt51")) {
          optargs_s.opt51 = SvIV (ST (items_i+1));
          this_mask = GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT51_BITMASK;
        }
        else if (STREQ (this_arg, "opt52")) {
          optargs_s.opt52 = SvIV (ST (items_i+1));
          this_mask = GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT52_BITMASK;
        }
        else if (STREQ (this_arg, "opt53")) {
          optargs_s.opt53 = SvIV (ST (items_i+1));
          this_mask = GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT53_BITMASK;
        }
        else if (STREQ (this_arg, "opt54")) {
          optargs_s.opt54 = SvIV (ST (items_i+1));
          this_mask = GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT54_BITMASK;
        }
        else if (STREQ (this_arg, "opt55")) {
          optargs_s.opt55 = SvIV (ST (items_i+1));
          this_mask = GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT55_BITMASK;
        }
        else if (STREQ (this_arg, "opt56")) {
          optargs_s.opt56 = SvIV (ST (items_i+1));
          this_mask = GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT56_BITMASK;
        }
        else if (STREQ (this_arg, "opt57")) {
          optargs_s.opt57 = SvIV (ST (items_i+1));
          this_mask = GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT57_BITMASK;
        }
        else if (STREQ (this_arg, "opt58")) {
          optargs_s.opt58 = SvIV (ST (items_i+1));
          this_mask = GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT58_BITMASK;
        }
        else if (STREQ (this_arg, "opt59")) {
          optargs_s.opt59 = SvIV (ST (items_i+1));
          this_mask = GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT59_BITMASK;
        }
        else if (STREQ (this_arg, "opt60")) {
          optargs_s.opt60 = SvIV (ST (items_i+1));
          this_mask = GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT60_BITMASK;
        }
        else if (STREQ (this_arg, "opt61")) {
          optargs_s.opt61 = SvIV (ST (items_i+1));
          this_mask = GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT61_BITMASK;
        }
        else if (STREQ (this_arg, "opt62")) {
          optargs_s.opt62 = SvIV (ST (items_i+1));
          this_mask = GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT62_BITMASK;
        }
        else if (STREQ (this_arg, "opt63")) {
          optargs_s.opt63 = SvIV (ST (items_i+1));
          this_mask = GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT63_BITMASK;
        }
        else croak ("unknown optional argument '%s'", this_arg);
        if (optargs_s.bitmask & this_mask)
          croak ("optional argument '%s' given twice",
                 this_arg);
        optargs_s.bitmask |= this_mask;
      }

      r = guestfs_internal_test_63_optargs_argv (g, optargs);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

SV *
internal_test_rint (g, val)
      guestfs_h *g;
      char *val;
PREINIT:
      int r;
   CODE:
      r = guestfs_internal_test_rint (g, val);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));
      RETVAL = newSViv (r);
 OUTPUT:
      RETVAL

SV *
internal_test_rinterr (g)
      guestfs_h *g;
PREINIT:
      int r;
   CODE:
      r = guestfs_internal_test_rinterr (g);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));
      RETVAL = newSViv (r);
 OUTPUT:
      RETVAL

SV *
internal_test_rint64 (g, val)
      guestfs_h *g;
      char *val;
PREINIT:
      int64_t r;
   CODE:
      r = guestfs_internal_test_rint64 (g, val);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));
      RETVAL = my_newSVll (r);
 OUTPUT:
      RETVAL

SV *
internal_test_rint64err (g)
      guestfs_h *g;
PREINIT:
      int64_t r;
   CODE:
      r = guestfs_internal_test_rint64err (g);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));
      RETVAL = my_newSVll (r);
 OUTPUT:
      RETVAL

SV *
internal_test_rbool (g, val)
      guestfs_h *g;
      char *val;
PREINIT:
      int r;
   CODE:
      r = guestfs_internal_test_rbool (g, val);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));
      RETVAL = newSViv (r);
 OUTPUT:
      RETVAL

SV *
internal_test_rboolerr (g)
      guestfs_h *g;
PREINIT:
      int r;
   CODE:
      r = guestfs_internal_test_rboolerr (g);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));
      RETVAL = newSViv (r);
 OUTPUT:
      RETVAL

SV *
internal_test_rconststring (g, val)
      guestfs_h *g;
      char *val;
PREINIT:
      const char *r;
   CODE:
      r = guestfs_internal_test_rconststring (g, val);
      if (r == NULL)
        croak ("%s", guestfs_last_error (g));
      RETVAL = newSVpv (r, 0);
 OUTPUT:
      RETVAL

SV *
internal_test_rconststringerr (g)
      guestfs_h *g;
PREINIT:
      const char *r;
   CODE:
      r = guestfs_internal_test_rconststringerr (g);
      if (r == NULL)
        croak ("%s", guestfs_last_error (g));
      RETVAL = newSVpv (r, 0);
 OUTPUT:
      RETVAL

SV *
internal_test_rconstoptstring (g, val)
      guestfs_h *g;
      char *val;
PREINIT:
      const char *r;
   CODE:
      r = guestfs_internal_test_rconstoptstring (g, val);
      if (r == NULL)
        RETVAL = &PL_sv_undef;
      else
        RETVAL = newSVpv (r, 0);
 OUTPUT:
      RETVAL

SV *
internal_test_rconstoptstringerr (g)
      guestfs_h *g;
PREINIT:
      const char *r;
   CODE:
      r = guestfs_internal_test_rconstoptstringerr (g);
      if (r == NULL)
        RETVAL = &PL_sv_undef;
      else
        RETVAL = newSVpv (r, 0);
 OUTPUT:
      RETVAL

SV *
internal_test_rstring (g, val)
      guestfs_h *g;
      char *val;
PREINIT:
      char *r;
   CODE:
      r = guestfs_internal_test_rstring (g, val);
      if (r == NULL)
        croak ("%s", guestfs_last_error (g));
      RETVAL = newSVpv (r, 0);
      free (r);
 OUTPUT:
      RETVAL

SV *
internal_test_rstringerr (g)
      guestfs_h *g;
PREINIT:
      char *r;
   CODE:
      r = guestfs_internal_test_rstringerr (g);
      if (r == NULL)
        croak ("%s", guestfs_last_error (g));
      RETVAL = newSVpv (r, 0);
      free (r);
 OUTPUT:
      RETVAL

void
internal_test_rstringlist (g, val)
      guestfs_h *g;
      char *val;
PREINIT:
      char **r;
      size_t i, n;
 PPCODE:
      r = guestfs_internal_test_rstringlist (g, val);
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
internal_test_rstringlisterr (g)
      guestfs_h *g;
PREINIT:
      char **r;
      size_t i, n;
 PPCODE:
      r = guestfs_internal_test_rstringlisterr (g);
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
internal_test_rstruct (g, val)
      guestfs_h *g;
      char *val;
PREINIT:
      struct guestfs_lvm_pv *r;
 PPCODE:
      r = guestfs_internal_test_rstruct (g, val);
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
internal_test_rstructerr (g)
      guestfs_h *g;
PREINIT:
      struct guestfs_lvm_pv *r;
 PPCODE:
      r = guestfs_internal_test_rstructerr (g);
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
internal_test_rstructlist (g, val)
      guestfs_h *g;
      char *val;
PREINIT:
      struct guestfs_lvm_pv_list *r;
      size_t i;
      HV *hv;
 PPCODE:
      r = guestfs_internal_test_rstructlist (g, val);
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
internal_test_rstructlisterr (g)
      guestfs_h *g;
PREINIT:
      struct guestfs_lvm_pv_list *r;
      size_t i;
      HV *hv;
 PPCODE:
      r = guestfs_internal_test_rstructlisterr (g);
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
internal_test_rhashtable (g, val)
      guestfs_h *g;
      char *val;
PREINIT:
      char **r;
      size_t i, n;
 PPCODE:
      r = guestfs_internal_test_rhashtable (g, val);
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
internal_test_rhashtableerr (g)
      guestfs_h *g;
PREINIT:
      char **r;
      size_t i, n;
 PPCODE:
      r = guestfs_internal_test_rhashtableerr (g);
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
internal_test_rbufferout (g, val)
      guestfs_h *g;
      char *val;
PREINIT:
      char *r;
      size_t size;
   CODE:
      r = guestfs_internal_test_rbufferout (g, val, &size);
      if (r == NULL)
        croak ("%s", guestfs_last_error (g));
      RETVAL = newSVpvn (r, size);
      free (r);
 OUTPUT:
      RETVAL

SV *
internal_test_rbufferouterr (g)
      guestfs_h *g;
PREINIT:
      char *r;
      size_t size;
   CODE:
      r = guestfs_internal_test_rbufferouterr (g, &size);
      if (r == NULL)
        croak ("%s", guestfs_last_error (g));
      RETVAL = newSVpvn (r, size);
      free (r);
 OUTPUT:
      RETVAL

void
internal_test_set_output (g, filename)
      guestfs_h *g;
      char *filename;
PREINIT:
      int r;
 PPCODE:
      r = guestfs_internal_test_set_output (g, filename);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

void
internal_test_close_output (g)
      guestfs_h *g;
PREINIT:
      int r;
 PPCODE:
      r = guestfs_internal_test_close_output (g);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

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
config (g, hvparam, hvvalue)
      guestfs_h *g;
      char *hvparam;
      char *hvvalue = SvOK(ST(2)) ? SvPV_nolen(ST(2)) : NULL;
PREINIT:
      int r;
 PPCODE:
      r = guestfs_config (g, hvparam, hvvalue);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

void
set_qemu (g, hv)
      guestfs_h *g;
      char *hv = SvOK(ST(1)) ? SvPV_nolen(ST(1)) : NULL;
PREINIT:
      int r;
 PPCODE:
      r = guestfs_set_qemu (g, hv);
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
set_hv (g, hv)
      guestfs_h *g;
      char *hv;
PREINIT:
      int r;
 PPCODE:
      r = guestfs_set_hv (g, hv);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

SV *
get_hv (g)
      guestfs_h *g;
PREINIT:
      char *r;
   CODE:
      r = guestfs_get_hv (g);
      if (r == NULL)
        croak ("%s", guestfs_last_error (g));
      RETVAL = newSVpv (r, 0);
      free (r);
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
add_drive (g, filename, ...)
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
        if (STREQ (this_arg, "readonly")) {
          optargs_s.readonly = SvIV (ST (items_i+1));
          this_mask = GUESTFS_ADD_DRIVE_OPTS_READONLY_BITMASK;
        }
        else if (STREQ (this_arg, "format")) {
          optargs_s.format = SvPV_nolen (ST (items_i+1));
          this_mask = GUESTFS_ADD_DRIVE_OPTS_FORMAT_BITMASK;
        }
        else if (STREQ (this_arg, "iface")) {
          optargs_s.iface = SvPV_nolen (ST (items_i+1));
          this_mask = GUESTFS_ADD_DRIVE_OPTS_IFACE_BITMASK;
        }
        else if (STREQ (this_arg, "name")) {
          optargs_s.name = SvPV_nolen (ST (items_i+1));
          this_mask = GUESTFS_ADD_DRIVE_OPTS_NAME_BITMASK;
        }
        else if (STREQ (this_arg, "label")) {
          optargs_s.label = SvPV_nolen (ST (items_i+1));
          this_mask = GUESTFS_ADD_DRIVE_OPTS_LABEL_BITMASK;
        }
        else if (STREQ (this_arg, "protocol")) {
          optargs_s.protocol = SvPV_nolen (ST (items_i+1));
          this_mask = GUESTFS_ADD_DRIVE_OPTS_PROTOCOL_BITMASK;
        }
        else if (STREQ (this_arg, "server")) {
          size_t i, len;
          char **r;
          SV *arg;
          AV *av;
          SV **svp;

          arg = ST (items_i+1);
          if (!SvROK (arg) || SvTYPE (SvRV (arg)) != SVt_PVAV)
            croak ("array reference expected for '%s' argument", "server");
          av = (AV *) SvRV (ST (items_i+1));

          /* Note av_len returns index of final element. */
          len = av_len (av) + 1;

          r = guestfs___safe_malloc (g, (len+1) * sizeof (char *));
          for (i = 0; i < len; ++i) {
            svp = av_fetch (av, i, 0);
            r[i] = SvPV_nolen (*svp);
          }
          r[i] = NULL;
          optargs_s.server = r;
          this_mask = GUESTFS_ADD_DRIVE_OPTS_SERVER_BITMASK;
        }
        else if (STREQ (this_arg, "username")) {
          optargs_s.username = SvPV_nolen (ST (items_i+1));
          this_mask = GUESTFS_ADD_DRIVE_OPTS_USERNAME_BITMASK;
        }
        else if (STREQ (this_arg, "secret")) {
          optargs_s.secret = SvPV_nolen (ST (items_i+1));
          this_mask = GUESTFS_ADD_DRIVE_OPTS_SECRET_BITMASK;
        }
        else if (STREQ (this_arg, "cachemode")) {
          optargs_s.cachemode = SvPV_nolen (ST (items_i+1));
          this_mask = GUESTFS_ADD_DRIVE_OPTS_CACHEMODE_BITMASK;
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
        if (STREQ (this_arg, "libvirturi")) {
          optargs_s.libvirturi = SvPV_nolen (ST (items_i+1));
          this_mask = GUESTFS_ADD_DOMAIN_LIBVIRTURI_BITMASK;
        }
        else if (STREQ (this_arg, "readonly")) {
          optargs_s.readonly = SvIV (ST (items_i+1));
          this_mask = GUESTFS_ADD_DOMAIN_READONLY_BITMASK;
        }
        else if (STREQ (this_arg, "iface")) {
          optargs_s.iface = SvPV_nolen (ST (items_i+1));
          this_mask = GUESTFS_ADD_DOMAIN_IFACE_BITMASK;
        }
        else if (STREQ (this_arg, "live")) {
          optargs_s.live = SvIV (ST (items_i+1));
          this_mask = GUESTFS_ADD_DOMAIN_LIVE_BITMASK;
        }
        else if (STREQ (this_arg, "allowuuid")) {
          optargs_s.allowuuid = SvIV (ST (items_i+1));
          this_mask = GUESTFS_ADD_DOMAIN_ALLOWUUID_BITMASK;
        }
        else if (STREQ (this_arg, "readonlydisk")) {
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

void
inspect_list_applications2 (g, root)
      guestfs_h *g;
      char *root;
PREINIT:
      struct guestfs_application2_list *r;
      size_t i;
      HV *hv;
 PPCODE:
      r = guestfs_inspect_list_applications2 (g, root);
      if (r == NULL)
        croak ("%s", guestfs_last_error (g));
      EXTEND (SP, r->len);
      for (i = 0; i < r->len; ++i) {
        hv = newHV ();
        (void) hv_store (hv, "app2_name", 9, newSVpv (r->val[i].app2_name, 0), 0);
        (void) hv_store (hv, "app2_display_name", 17, newSVpv (r->val[i].app2_display_name, 0), 0);
        (void) hv_store (hv, "app2_epoch", 10, newSVnv (r->val[i].app2_epoch), 0);
        (void) hv_store (hv, "app2_version", 12, newSVpv (r->val[i].app2_version, 0), 0);
        (void) hv_store (hv, "app2_release", 12, newSVpv (r->val[i].app2_release, 0), 0);
        (void) hv_store (hv, "app2_arch", 9, newSVpv (r->val[i].app2_arch, 0), 0);
        (void) hv_store (hv, "app2_install_path", 17, newSVpv (r->val[i].app2_install_path, 0), 0);
        (void) hv_store (hv, "app2_trans_path", 15, newSVpv (r->val[i].app2_trans_path, 0), 0);
        (void) hv_store (hv, "app2_publisher", 14, newSVpv (r->val[i].app2_publisher, 0), 0);
        (void) hv_store (hv, "app2_url", 8, newSVpv (r->val[i].app2_url, 0), 0);
        (void) hv_store (hv, "app2_source_package", 19, newSVpv (r->val[i].app2_source_package, 0), 0);
        (void) hv_store (hv, "app2_summary", 12, newSVpv (r->val[i].app2_summary, 0), 0);
        (void) hv_store (hv, "app2_description", 16, newSVpv (r->val[i].app2_description, 0), 0);
        (void) hv_store (hv, "app2_spare1", 11, newSVpv (r->val[i].app2_spare1, 0), 0);
        (void) hv_store (hv, "app2_spare2", 11, newSVpv (r->val[i].app2_spare2, 0), 0);
        (void) hv_store (hv, "app2_spare3", 11, newSVpv (r->val[i].app2_spare3, 0), 0);
        (void) hv_store (hv, "app2_spare4", 11, newSVpv (r->val[i].app2_spare4, 0), 0);
        PUSHs (sv_2mortal (newRV ((SV *) hv)));
      }
      guestfs_free_application2_list (r);

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
set_attach_method (g, backend)
      guestfs_h *g;
      char *backend;
PREINIT:
      int r;
 PPCODE:
      r = guestfs_set_attach_method (g, backend);
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

void
set_backend (g, backend)
      guestfs_h *g;
      char *backend;
PREINIT:
      int r;
 PPCODE:
      r = guestfs_set_backend (g, backend);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

SV *
get_backend (g)
      guestfs_h *g;
PREINIT:
      char *r;
   CODE:
      r = guestfs_get_backend (g);
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
        if (STREQ (this_arg, "favicon")) {
          optargs_s.favicon = SvIV (ST (items_i+1));
          this_mask = GUESTFS_INSPECT_GET_ICON_FAVICON_BITMASK;
        }
        else if (STREQ (this_arg, "highquality")) {
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
mount_local (g, localmountpoint, ...)
      guestfs_h *g;
      char *localmountpoint;
PREINIT:
      int r;
      struct guestfs_mount_local_argv optargs_s = { .bitmask = 0 };
      struct guestfs_mount_local_argv *optargs = &optargs_s;
      size_t items_i;
 PPCODE:
      if (((items - 2) & 1) != 0)
        croak ("expecting an even number of extra parameters");
      for (items_i = 2; items_i < items; items_i += 2) {
        uint64_t this_mask;
        const char *this_arg;

        this_arg = SvPV_nolen (ST (items_i));
        if (STREQ (this_arg, "readonly")) {
          optargs_s.readonly = SvIV (ST (items_i+1));
          this_mask = GUESTFS_MOUNT_LOCAL_READONLY_BITMASK;
        }
        else if (STREQ (this_arg, "options")) {
          optargs_s.options = SvPV_nolen (ST (items_i+1));
          this_mask = GUESTFS_MOUNT_LOCAL_OPTIONS_BITMASK;
        }
        else if (STREQ (this_arg, "cachetimeout")) {
          optargs_s.cachetimeout = SvIV (ST (items_i+1));
          this_mask = GUESTFS_MOUNT_LOCAL_CACHETIMEOUT_BITMASK;
        }
        else if (STREQ (this_arg, "debugcalls")) {
          optargs_s.debugcalls = SvIV (ST (items_i+1));
          this_mask = GUESTFS_MOUNT_LOCAL_DEBUGCALLS_BITMASK;
        }
        else croak ("unknown optional argument '%s'", this_arg);
        if (optargs_s.bitmask & this_mask)
          croak ("optional argument '%s' given twice",
                 this_arg);
        optargs_s.bitmask |= this_mask;
      }

      r = guestfs_mount_local_argv (g, localmountpoint, optargs);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

void
mount_local_run (g)
      guestfs_h *g;
PREINIT:
      int r;
 PPCODE:
      r = guestfs_mount_local_run (g);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

void
umount_local (g, ...)
      guestfs_h *g;
PREINIT:
      int r;
      struct guestfs_umount_local_argv optargs_s = { .bitmask = 0 };
      struct guestfs_umount_local_argv *optargs = &optargs_s;
      size_t items_i;
 PPCODE:
      if (((items - 1) & 1) != 0)
        croak ("expecting an even number of extra parameters");
      for (items_i = 1; items_i < items; items_i += 2) {
        uint64_t this_mask;
        const char *this_arg;

        this_arg = SvPV_nolen (ST (items_i));
        if (STREQ (this_arg, "retry")) {
          optargs_s.retry = SvIV (ST (items_i+1));
          this_mask = GUESTFS_UMOUNT_LOCAL_RETRY_BITMASK;
        }
        else croak ("unknown optional argument '%s'", this_arg);
        if (optargs_s.bitmask & this_mask)
          croak ("optional argument '%s' given twice",
                 this_arg);
        optargs_s.bitmask |= this_mask;
      }

      r = guestfs_umount_local_argv (g, optargs);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

SV *
max_disks (g)
      guestfs_h *g;
PREINIT:
      int r;
   CODE:
      r = guestfs_max_disks (g);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));
      RETVAL = newSViv (r);
 OUTPUT:
      RETVAL

SV *
canonical_device_name (g, device)
      guestfs_h *g;
      char *device;
PREINIT:
      char *r;
   CODE:
      r = guestfs_canonical_device_name (g, device);
      if (r == NULL)
        croak ("%s", guestfs_last_error (g));
      RETVAL = newSVpv (r, 0);
      free (r);
 OUTPUT:
      RETVAL

void
shutdown (g)
      guestfs_h *g;
PREINIT:
      int r;
 PPCODE:
      r = guestfs_shutdown (g);
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

SV *
hivex_value_utf8 (g, valueh)
      guestfs_h *g;
      int64_t valueh;
PREINIT:
      char *r;
   CODE:
      r = guestfs_hivex_value_utf8 (g, valueh);
      if (r == NULL)
        croak ("%s", guestfs_last_error (g));
      RETVAL = newSVpv (r, 0);
      free (r);
 OUTPUT:
      RETVAL

SV *
disk_format (g, filename)
      guestfs_h *g;
      char *filename;
PREINIT:
      char *r;
   CODE:
      r = guestfs_disk_format (g, filename);
      if (r == NULL)
        croak ("%s", guestfs_last_error (g));
      RETVAL = newSVpv (r, 0);
      free (r);
 OUTPUT:
      RETVAL

SV *
disk_virtual_size (g, filename)
      guestfs_h *g;
      char *filename;
PREINIT:
      int64_t r;
   CODE:
      r = guestfs_disk_virtual_size (g, filename);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));
      RETVAL = my_newSVll (r);
 OUTPUT:
      RETVAL

SV *
disk_has_backing_file (g, filename)
      guestfs_h *g;
      char *filename;
PREINIT:
      int r;
   CODE:
      r = guestfs_disk_has_backing_file (g, filename);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));
      RETVAL = newSViv (r);
 OUTPUT:
      RETVAL

void
remove_drive (g, label)
      guestfs_h *g;
      char *label;
PREINIT:
      int r;
 PPCODE:
      r = guestfs_remove_drive (g, label);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

void
set_libvirt_supported_credentials (g, creds)
      guestfs_h *g;
      char **creds;
PREINIT:
      int r;
 PPCODE:
      r = guestfs_set_libvirt_supported_credentials (g, creds);
      free (creds);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

void
get_libvirt_requested_credentials (g)
      guestfs_h *g;
PREINIT:
      char **r;
      size_t i, n;
 PPCODE:
      r = guestfs_get_libvirt_requested_credentials (g);
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
get_libvirt_requested_credential_prompt (g, index)
      guestfs_h *g;
      int index;
PREINIT:
      char *r;
   CODE:
      r = guestfs_get_libvirt_requested_credential_prompt (g, index);
      if (r == NULL)
        croak ("%s", guestfs_last_error (g));
      RETVAL = newSVpv (r, 0);
      free (r);
 OUTPUT:
      RETVAL

SV *
get_libvirt_requested_credential_challenge (g, index)
      guestfs_h *g;
      int index;
PREINIT:
      char *r;
   CODE:
      r = guestfs_get_libvirt_requested_credential_challenge (g, index);
      if (r == NULL)
        croak ("%s", guestfs_last_error (g));
      RETVAL = newSVpv (r, 0);
      free (r);
 OUTPUT:
      RETVAL

SV *
get_libvirt_requested_credential_defresult (g, index)
      guestfs_h *g;
      int index;
PREINIT:
      char *r;
   CODE:
      r = guestfs_get_libvirt_requested_credential_defresult (g, index);
      if (r == NULL)
        croak ("%s", guestfs_last_error (g));
      RETVAL = newSVpv (r, 0);
      free (r);
 OUTPUT:
      RETVAL

void
set_libvirt_requested_credential (g, index, cred)
      guestfs_h *g;
      int index;
      char *cred;
      size_t cred_size = SvCUR (ST(2));
PREINIT:
      int r;
 PPCODE:
      r = guestfs_set_libvirt_requested_credential (g, index, cred, cred_size);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

void
parse_environment (g)
      guestfs_h *g;
PREINIT:
      int r;
 PPCODE:
      r = guestfs_parse_environment (g);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

void
parse_environment_list (g, environment)
      guestfs_h *g;
      char **environment;
PREINIT:
      int r;
 PPCODE:
      r = guestfs_parse_environment_list (g, environment);
      free (environment);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

void
set_tmpdir (g, tmpdir)
      guestfs_h *g;
      char *tmpdir = SvOK(ST(1)) ? SvPV_nolen(ST(1)) : NULL;
PREINIT:
      int r;
 PPCODE:
      r = guestfs_set_tmpdir (g, tmpdir);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

SV *
get_tmpdir (g)
      guestfs_h *g;
PREINIT:
      char *r;
   CODE:
      r = guestfs_get_tmpdir (g);
      if (r == NULL)
        croak ("%s", guestfs_last_error (g));
      RETVAL = newSVpv (r, 0);
      free (r);
 OUTPUT:
      RETVAL

void
set_cachedir (g, cachedir)
      guestfs_h *g;
      char *cachedir = SvOK(ST(1)) ? SvPV_nolen(ST(1)) : NULL;
PREINIT:
      int r;
 PPCODE:
      r = guestfs_set_cachedir (g, cachedir);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

SV *
get_cachedir (g)
      guestfs_h *g;
PREINIT:
      char *r;
   CODE:
      r = guestfs_get_cachedir (g);
      if (r == NULL)
        croak ("%s", guestfs_last_error (g));
      RETVAL = newSVpv (r, 0);
      free (r);
 OUTPUT:
      RETVAL

void
user_cancel (g)
      guestfs_h *g;
PREINIT:
      int r;
 PPCODE:
      r = guestfs_user_cancel (g);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

void
set_program (g, program)
      guestfs_h *g;
      char *program;
PREINIT:
      int r;
 PPCODE:
      r = guestfs_set_program (g, program);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

SV *
get_program (g)
      guestfs_h *g;
PREINIT:
      const char *r;
   CODE:
      r = guestfs_get_program (g);
      if (r == NULL)
        croak ("%s", guestfs_last_error (g));
      RETVAL = newSVpv (r, 0);
 OUTPUT:
      RETVAL

void
add_drive_scratch (g, size, ...)
      guestfs_h *g;
      int64_t size;
PREINIT:
      int r;
      struct guestfs_add_drive_scratch_argv optargs_s = { .bitmask = 0 };
      struct guestfs_add_drive_scratch_argv *optargs = &optargs_s;
      size_t items_i;
 PPCODE:
      if (((items - 2) & 1) != 0)
        croak ("expecting an even number of extra parameters");
      for (items_i = 2; items_i < items; items_i += 2) {
        uint64_t this_mask;
        const char *this_arg;

        this_arg = SvPV_nolen (ST (items_i));
        if (STREQ (this_arg, "name")) {
          optargs_s.name = SvPV_nolen (ST (items_i+1));
          this_mask = GUESTFS_ADD_DRIVE_SCRATCH_NAME_BITMASK;
        }
        else if (STREQ (this_arg, "label")) {
          optargs_s.label = SvPV_nolen (ST (items_i+1));
          this_mask = GUESTFS_ADD_DRIVE_SCRATCH_LABEL_BITMASK;
        }
        else croak ("unknown optional argument '%s'", this_arg);
        if (optargs_s.bitmask & this_mask)
          croak ("optional argument '%s' given twice",
                 this_arg);
        optargs_s.bitmask |= this_mask;
      }

      r = guestfs_add_drive_scratch_argv (g, size, optargs);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

void
journal_get (g)
      guestfs_h *g;
PREINIT:
      struct guestfs_xattr_list *r;
      size_t i;
      HV *hv;
 PPCODE:
      r = guestfs_journal_get (g);
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
set_backend_settings (g, settings)
      guestfs_h *g;
      char **settings;
PREINIT:
      int r;
 PPCODE:
      r = guestfs_set_backend_settings (g, settings);
      free (settings);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

void
get_backend_settings (g)
      guestfs_h *g;
PREINIT:
      char **r;
      size_t i, n;
 PPCODE:
      r = guestfs_get_backend_settings (g);
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
disk_create (g, filename, format, size, ...)
      guestfs_h *g;
      char *filename;
      char *format;
      int64_t size;
PREINIT:
      int r;
      struct guestfs_disk_create_argv optargs_s = { .bitmask = 0 };
      struct guestfs_disk_create_argv *optargs = &optargs_s;
      size_t items_i;
 PPCODE:
      if (((items - 4) & 1) != 0)
        croak ("expecting an even number of extra parameters");
      for (items_i = 4; items_i < items; items_i += 2) {
        uint64_t this_mask;
        const char *this_arg;

        this_arg = SvPV_nolen (ST (items_i));
        if (STREQ (this_arg, "backingfile")) {
          optargs_s.backingfile = SvPV_nolen (ST (items_i+1));
          this_mask = GUESTFS_DISK_CREATE_BACKINGFILE_BITMASK;
        }
        else if (STREQ (this_arg, "backingformat")) {
          optargs_s.backingformat = SvPV_nolen (ST (items_i+1));
          this_mask = GUESTFS_DISK_CREATE_BACKINGFORMAT_BITMASK;
        }
        else if (STREQ (this_arg, "preallocation")) {
          optargs_s.preallocation = SvPV_nolen (ST (items_i+1));
          this_mask = GUESTFS_DISK_CREATE_PREALLOCATION_BITMASK;
        }
        else if (STREQ (this_arg, "compat")) {
          optargs_s.compat = SvPV_nolen (ST (items_i+1));
          this_mask = GUESTFS_DISK_CREATE_COMPAT_BITMASK;
        }
        else if (STREQ (this_arg, "clustersize")) {
          optargs_s.clustersize = SvIV (ST (items_i+1));
          this_mask = GUESTFS_DISK_CREATE_CLUSTERSIZE_BITMASK;
        }
        else croak ("unknown optional argument '%s'", this_arg);
        if (optargs_s.bitmask & this_mask)
          croak ("optional argument '%s' given twice",
                 this_arg);
        optargs_s.bitmask |= this_mask;
      }

      r = guestfs_disk_create_argv (g, filename, format, size, optargs);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

void
mount (g, mountable, mountpoint)
      guestfs_h *g;
      char *mountable;
      char *mountpoint;
PREINIT:
      int r;
 PPCODE:
      r = guestfs_mount (g, mountable, mountpoint);
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
is_file (g, path, ...)
      guestfs_h *g;
      char *path;
PREINIT:
      int r;
      struct guestfs_is_file_opts_argv optargs_s = { .bitmask = 0 };
      struct guestfs_is_file_opts_argv *optargs = &optargs_s;
      size_t items_i;
   CODE:
      if (((items - 2) & 1) != 0)
        croak ("expecting an even number of extra parameters");
      for (items_i = 2; items_i < items; items_i += 2) {
        uint64_t this_mask;
        const char *this_arg;

        this_arg = SvPV_nolen (ST (items_i));
        if (STREQ (this_arg, "followsymlinks")) {
          optargs_s.followsymlinks = SvIV (ST (items_i+1));
          this_mask = GUESTFS_IS_FILE_OPTS_FOLLOWSYMLINKS_BITMASK;
        }
        else croak ("unknown optional argument '%s'", this_arg);
        if (optargs_s.bitmask & this_mask)
          croak ("optional argument '%s' given twice",
                 this_arg);
        optargs_s.bitmask |= this_mask;
      }

      r = guestfs_is_file_opts_argv (g, path, optargs);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));
      RETVAL = newSViv (r);
 OUTPUT:
      RETVAL

SV *
is_dir (g, path, ...)
      guestfs_h *g;
      char *path;
PREINIT:
      int r;
      struct guestfs_is_dir_opts_argv optargs_s = { .bitmask = 0 };
      struct guestfs_is_dir_opts_argv *optargs = &optargs_s;
      size_t items_i;
   CODE:
      if (((items - 2) & 1) != 0)
        croak ("expecting an even number of extra parameters");
      for (items_i = 2; items_i < items; items_i += 2) {
        uint64_t this_mask;
        const char *this_arg;

        this_arg = SvPV_nolen (ST (items_i));
        if (STREQ (this_arg, "followsymlinks")) {
          optargs_s.followsymlinks = SvIV (ST (items_i+1));
          this_mask = GUESTFS_IS_DIR_OPTS_FOLLOWSYMLINKS_BITMASK;
        }
        else croak ("unknown optional argument '%s'", this_arg);
        if (optargs_s.bitmask & this_mask)
          croak ("optional argument '%s' given twice",
                 this_arg);
        optargs_s.bitmask |= this_mask;
      }

      r = guestfs_is_dir_opts_argv (g, path, optargs);
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
umount (g, pathordevice, ...)
      guestfs_h *g;
      char *pathordevice;
PREINIT:
      int r;
      struct guestfs_umount_opts_argv optargs_s = { .bitmask = 0 };
      struct guestfs_umount_opts_argv *optargs = &optargs_s;
      size_t items_i;
 PPCODE:
      if (((items - 2) & 1) != 0)
        croak ("expecting an even number of extra parameters");
      for (items_i = 2; items_i < items; items_i += 2) {
        uint64_t this_mask;
        const char *this_arg;

        this_arg = SvPV_nolen (ST (items_i));
        if (STREQ (this_arg, "force")) {
          optargs_s.force = SvIV (ST (items_i+1));
          this_mask = GUESTFS_UMOUNT_OPTS_FORCE_BITMASK;
        }
        else if (STREQ (this_arg, "lazyunmount")) {
          optargs_s.lazyunmount = SvIV (ST (items_i+1));
          this_mask = GUESTFS_UMOUNT_OPTS_LAZYUNMOUNT_BITMASK;
        }
        else croak ("unknown optional argument '%s'", this_arg);
        if (optargs_s.bitmask & this_mask)
          croak ("optional argument '%s' given twice",
                 this_arg);
        optargs_s.bitmask |= this_mask;
      }

      r = guestfs_umount_opts_argv (g, pathordevice, optargs);
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
tar_in (g, tarfile, directory, ...)
      guestfs_h *g;
      char *tarfile;
      char *directory;
PREINIT:
      int r;
      struct guestfs_tar_in_opts_argv optargs_s = { .bitmask = 0 };
      struct guestfs_tar_in_opts_argv *optargs = &optargs_s;
      size_t items_i;
 PPCODE:
      if (((items - 3) & 1) != 0)
        croak ("expecting an even number of extra parameters");
      for (items_i = 3; items_i < items; items_i += 2) {
        uint64_t this_mask;
        const char *this_arg;

        this_arg = SvPV_nolen (ST (items_i));
        if (STREQ (this_arg, "compress")) {
          optargs_s.compress = SvPV_nolen (ST (items_i+1));
          this_mask = GUESTFS_TAR_IN_OPTS_COMPRESS_BITMASK;
        }
        else croak ("unknown optional argument '%s'", this_arg);
        if (optargs_s.bitmask & this_mask)
          croak ("optional argument '%s' given twice",
                 this_arg);
        optargs_s.bitmask |= this_mask;
      }

      r = guestfs_tar_in_opts_argv (g, tarfile, directory, optargs);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

void
tar_out (g, directory, tarfile, ...)
      guestfs_h *g;
      char *directory;
      char *tarfile;
PREINIT:
      int r;
      struct guestfs_tar_out_opts_argv optargs_s = { .bitmask = 0 };
      struct guestfs_tar_out_opts_argv *optargs = &optargs_s;
      size_t items_i;
 PPCODE:
      if (((items - 3) & 1) != 0)
        croak ("expecting an even number of extra parameters");
      for (items_i = 3; items_i < items; items_i += 2) {
        uint64_t this_mask;
        const char *this_arg;

        this_arg = SvPV_nolen (ST (items_i));
        if (STREQ (this_arg, "compress")) {
          optargs_s.compress = SvPV_nolen (ST (items_i+1));
          this_mask = GUESTFS_TAR_OUT_OPTS_COMPRESS_BITMASK;
        }
        else if (STREQ (this_arg, "numericowner")) {
          optargs_s.numericowner = SvIV (ST (items_i+1));
          this_mask = GUESTFS_TAR_OUT_OPTS_NUMERICOWNER_BITMASK;
        }
        else if (STREQ (this_arg, "excludes")) {
          size_t i, len;
          char **r;
          SV *arg;
          AV *av;
          SV **svp;

          arg = ST (items_i+1);
          if (!SvROK (arg) || SvTYPE (SvRV (arg)) != SVt_PVAV)
            croak ("array reference expected for '%s' argument", "excludes");
          av = (AV *) SvRV (ST (items_i+1));

          /* Note av_len returns index of final element. */
          len = av_len (av) + 1;

          r = guestfs___safe_malloc (g, (len+1) * sizeof (char *));
          for (i = 0; i < len; ++i) {
            svp = av_fetch (av, i, 0);
            r[i] = SvPV_nolen (*svp);
          }
          r[i] = NULL;
          optargs_s.excludes = r;
          this_mask = GUESTFS_TAR_OUT_OPTS_EXCLUDES_BITMASK;
        }
        else croak ("unknown optional argument '%s'", this_arg);
        if (optargs_s.bitmask & this_mask)
          croak ("optional argument '%s' given twice",
                 this_arg);
        optargs_s.bitmask |= this_mask;
      }

      r = guestfs_tar_out_opts_argv (g, directory, tarfile, optargs);
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
mount_ro (g, mountable, mountpoint)
      guestfs_h *g;
      char *mountable;
      char *mountpoint;
PREINIT:
      int r;
 PPCODE:
      r = guestfs_mount_ro (g, mountable, mountpoint);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

void
mount_options (g, options, mountable, mountpoint)
      guestfs_h *g;
      char *options;
      char *mountable;
      char *mountpoint;
PREINIT:
      int r;
 PPCODE:
      r = guestfs_mount_options (g, options, mountable, mountpoint);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

void
mount_vfs (g, options, vfstype, mountable, mountpoint)
      guestfs_h *g;
      char *options;
      char *vfstype;
      char *mountable;
      char *mountpoint;
PREINIT:
      int r;
 PPCODE:
      r = guestfs_mount_vfs (g, options, vfstype, mountable, mountpoint);
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
mkdtemp (g, tmpl)
      guestfs_h *g;
      char *tmpl;
PREINIT:
      char *r;
   CODE:
      r = guestfs_mkdtemp (g, tmpl);
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
mkswap (g, device, ...)
      guestfs_h *g;
      char *device;
PREINIT:
      int r;
      struct guestfs_mkswap_opts_argv optargs_s = { .bitmask = 0 };
      struct guestfs_mkswap_opts_argv *optargs = &optargs_s;
      size_t items_i;
 PPCODE:
      if (((items - 2) & 1) != 0)
        croak ("expecting an even number of extra parameters");
      for (items_i = 2; items_i < items; items_i += 2) {
        uint64_t this_mask;
        const char *this_arg;

        this_arg = SvPV_nolen (ST (items_i));
        if (STREQ (this_arg, "label")) {
          optargs_s.label = SvPV_nolen (ST (items_i+1));
          this_mask = GUESTFS_MKSWAP_OPTS_LABEL_BITMASK;
        }
        else if (STREQ (this_arg, "uuid")) {
          optargs_s.uuid = SvPV_nolen (ST (items_i+1));
          this_mask = GUESTFS_MKSWAP_OPTS_UUID_BITMASK;
        }
        else croak ("unknown optional argument '%s'", this_arg);
        if (optargs_s.bitmask & this_mask)
          croak ("optional argument '%s' given twice",
                 this_arg);
        optargs_s.bitmask |= this_mask;
      }

      r = guestfs_mkswap_opts_argv (g, device, optargs);
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

void
grep (g, regex, path, ...)
      guestfs_h *g;
      char *regex;
      char *path;
PREINIT:
      char **r;
      size_t i, n;
      struct guestfs_grep_opts_argv optargs_s = { .bitmask = 0 };
      struct guestfs_grep_opts_argv *optargs = &optargs_s;
      size_t items_i;
 PPCODE:
      if (((items - 3) & 1) != 0)
        croak ("expecting an even number of extra parameters");
      for (items_i = 3; items_i < items; items_i += 2) {
        uint64_t this_mask;
        const char *this_arg;

        this_arg = SvPV_nolen (ST (items_i));
        if (STREQ (this_arg, "extended")) {
          optargs_s.extended = SvIV (ST (items_i+1));
          this_mask = GUESTFS_GREP_OPTS_EXTENDED_BITMASK;
        }
        else if (STREQ (this_arg, "fixed")) {
          optargs_s.fixed = SvIV (ST (items_i+1));
          this_mask = GUESTFS_GREP_OPTS_FIXED_BITMASK;
        }
        else if (STREQ (this_arg, "insensitive")) {
          optargs_s.insensitive = SvIV (ST (items_i+1));
          this_mask = GUESTFS_GREP_OPTS_INSENSITIVE_BITMASK;
        }
        else if (STREQ (this_arg, "compressed")) {
          optargs_s.compressed = SvIV (ST (items_i+1));
          this_mask = GUESTFS_GREP_OPTS_COMPRESSED_BITMASK;
        }
        else croak ("unknown optional argument '%s'", this_arg);
        if (optargs_s.bitmask & this_mask)
          croak ("optional argument '%s' given twice",
                 this_arg);
        optargs_s.bitmask |= this_mask;
      }

      r = guestfs_grep_opts_argv (g, regex, path, optargs);
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
vfs_type (g, mountable)
      guestfs_h *g;
      char *mountable;
PREINIT:
      char *r;
   CODE:
      r = guestfs_vfs_type (g, mountable);
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
vfs_label (g, mountable)
      guestfs_h *g;
      char *mountable;
PREINIT:
      char *r;
   CODE:
      r = guestfs_vfs_label (g, mountable);
      if (r == NULL)
        croak ("%s", guestfs_last_error (g));
      RETVAL = newSVpv (r, 0);
      free (r);
 OUTPUT:
      RETVAL

SV *
vfs_uuid (g, mountable)
      guestfs_h *g;
      char *mountable;
PREINIT:
      char *r;
   CODE:
      r = guestfs_vfs_uuid (g, mountable);
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
is_chardev (g, path, ...)
      guestfs_h *g;
      char *path;
PREINIT:
      int r;
      struct guestfs_is_chardev_opts_argv optargs_s = { .bitmask = 0 };
      struct guestfs_is_chardev_opts_argv *optargs = &optargs_s;
      size_t items_i;
   CODE:
      if (((items - 2) & 1) != 0)
        croak ("expecting an even number of extra parameters");
      for (items_i = 2; items_i < items; items_i += 2) {
        uint64_t this_mask;
        const char *this_arg;

        this_arg = SvPV_nolen (ST (items_i));
        if (STREQ (this_arg, "followsymlinks")) {
          optargs_s.followsymlinks = SvIV (ST (items_i+1));
          this_mask = GUESTFS_IS_CHARDEV_OPTS_FOLLOWSYMLINKS_BITMASK;
        }
        else croak ("unknown optional argument '%s'", this_arg);
        if (optargs_s.bitmask & this_mask)
          croak ("optional argument '%s' given twice",
                 this_arg);
        optargs_s.bitmask |= this_mask;
      }

      r = guestfs_is_chardev_opts_argv (g, path, optargs);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));
      RETVAL = newSViv (r);
 OUTPUT:
      RETVAL

SV *
is_blockdev (g, path, ...)
      guestfs_h *g;
      char *path;
PREINIT:
      int r;
      struct guestfs_is_blockdev_opts_argv optargs_s = { .bitmask = 0 };
      struct guestfs_is_blockdev_opts_argv *optargs = &optargs_s;
      size_t items_i;
   CODE:
      if (((items - 2) & 1) != 0)
        croak ("expecting an even number of extra parameters");
      for (items_i = 2; items_i < items; items_i += 2) {
        uint64_t this_mask;
        const char *this_arg;

        this_arg = SvPV_nolen (ST (items_i));
        if (STREQ (this_arg, "followsymlinks")) {
          optargs_s.followsymlinks = SvIV (ST (items_i+1));
          this_mask = GUESTFS_IS_BLOCKDEV_OPTS_FOLLOWSYMLINKS_BITMASK;
        }
        else croak ("unknown optional argument '%s'", this_arg);
        if (optargs_s.bitmask & this_mask)
          croak ("optional argument '%s' given twice",
                 this_arg);
        optargs_s.bitmask |= this_mask;
      }

      r = guestfs_is_blockdev_opts_argv (g, path, optargs);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));
      RETVAL = newSViv (r);
 OUTPUT:
      RETVAL

SV *
is_fifo (g, path, ...)
      guestfs_h *g;
      char *path;
PREINIT:
      int r;
      struct guestfs_is_fifo_opts_argv optargs_s = { .bitmask = 0 };
      struct guestfs_is_fifo_opts_argv *optargs = &optargs_s;
      size_t items_i;
   CODE:
      if (((items - 2) & 1) != 0)
        croak ("expecting an even number of extra parameters");
      for (items_i = 2; items_i < items; items_i += 2) {
        uint64_t this_mask;
        const char *this_arg;

        this_arg = SvPV_nolen (ST (items_i));
        if (STREQ (this_arg, "followsymlinks")) {
          optargs_s.followsymlinks = SvIV (ST (items_i+1));
          this_mask = GUESTFS_IS_FIFO_OPTS_FOLLOWSYMLINKS_BITMASK;
        }
        else croak ("unknown optional argument '%s'", this_arg);
        if (optargs_s.bitmask & this_mask)
          croak ("optional argument '%s' given twice",
                 this_arg);
        optargs_s.bitmask |= this_mask;
      }

      r = guestfs_is_fifo_opts_argv (g, path, optargs);
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
is_socket (g, path, ...)
      guestfs_h *g;
      char *path;
PREINIT:
      int r;
      struct guestfs_is_socket_opts_argv optargs_s = { .bitmask = 0 };
      struct guestfs_is_socket_opts_argv *optargs = &optargs_s;
      size_t items_i;
   CODE:
      if (((items - 2) & 1) != 0)
        croak ("expecting an even number of extra parameters");
      for (items_i = 2; items_i < items; items_i += 2) {
        uint64_t this_mask;
        const char *this_arg;

        this_arg = SvPV_nolen (ST (items_i));
        if (STREQ (this_arg, "followsymlinks")) {
          optargs_s.followsymlinks = SvIV (ST (items_i+1));
          this_mask = GUESTFS_IS_SOCKET_OPTS_FOLLOWSYMLINKS_BITMASK;
        }
        else croak ("unknown optional argument '%s'", this_arg);
        if (optargs_s.bitmask & this_mask)
          croak ("optional argument '%s' given twice",
                 this_arg);
        optargs_s.bitmask |= this_mask;
      }

      r = guestfs_is_socket_opts_argv (g, path, optargs);
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
mkfs (g, fstype, device, ...)
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
        if (STREQ (this_arg, "blocksize")) {
          optargs_s.blocksize = SvIV (ST (items_i+1));
          this_mask = GUESTFS_MKFS_OPTS_BLOCKSIZE_BITMASK;
        }
        else if (STREQ (this_arg, "features")) {
          optargs_s.features = SvPV_nolen (ST (items_i+1));
          this_mask = GUESTFS_MKFS_OPTS_FEATURES_BITMASK;
        }
        else if (STREQ (this_arg, "inode")) {
          optargs_s.inode = SvIV (ST (items_i+1));
          this_mask = GUESTFS_MKFS_OPTS_INODE_BITMASK;
        }
        else if (STREQ (this_arg, "sectorsize")) {
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
        if (STREQ (this_arg, "options")) {
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
ntfsresize (g, device, ...)
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
        if (STREQ (this_arg, "size")) {
          optargs_s.size = my_SvIV64 (ST (items_i+1));
          this_mask = GUESTFS_NTFSRESIZE_OPTS_SIZE_BITMASK;
        }
        else if (STREQ (this_arg, "force")) {
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
        if (STREQ (this_arg, "size")) {
          optargs_s.size = my_SvIV64 (ST (items_i+1));
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
        if (STREQ (this_arg, "level")) {
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
        if (STREQ (this_arg, "level")) {
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
        if (STREQ (this_arg, "srcoffset")) {
          optargs_s.srcoffset = my_SvIV64 (ST (items_i+1));
          this_mask = GUESTFS_COPY_DEVICE_TO_DEVICE_SRCOFFSET_BITMASK;
        }
        else if (STREQ (this_arg, "destoffset")) {
          optargs_s.destoffset = my_SvIV64 (ST (items_i+1));
          this_mask = GUESTFS_COPY_DEVICE_TO_DEVICE_DESTOFFSET_BITMASK;
        }
        else if (STREQ (this_arg, "size")) {
          optargs_s.size = my_SvIV64 (ST (items_i+1));
          this_mask = GUESTFS_COPY_DEVICE_TO_DEVICE_SIZE_BITMASK;
        }
        else if (STREQ (this_arg, "sparse")) {
          optargs_s.sparse = SvIV (ST (items_i+1));
          this_mask = GUESTFS_COPY_DEVICE_TO_DEVICE_SPARSE_BITMASK;
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
        if (STREQ (this_arg, "srcoffset")) {
          optargs_s.srcoffset = my_SvIV64 (ST (items_i+1));
          this_mask = GUESTFS_COPY_DEVICE_TO_FILE_SRCOFFSET_BITMASK;
        }
        else if (STREQ (this_arg, "destoffset")) {
          optargs_s.destoffset = my_SvIV64 (ST (items_i+1));
          this_mask = GUESTFS_COPY_DEVICE_TO_FILE_DESTOFFSET_BITMASK;
        }
        else if (STREQ (this_arg, "size")) {
          optargs_s.size = my_SvIV64 (ST (items_i+1));
          this_mask = GUESTFS_COPY_DEVICE_TO_FILE_SIZE_BITMASK;
        }
        else if (STREQ (this_arg, "sparse")) {
          optargs_s.sparse = SvIV (ST (items_i+1));
          this_mask = GUESTFS_COPY_DEVICE_TO_FILE_SPARSE_BITMASK;
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
        if (STREQ (this_arg, "srcoffset")) {
          optargs_s.srcoffset = my_SvIV64 (ST (items_i+1));
          this_mask = GUESTFS_COPY_FILE_TO_DEVICE_SRCOFFSET_BITMASK;
        }
        else if (STREQ (this_arg, "destoffset")) {
          optargs_s.destoffset = my_SvIV64 (ST (items_i+1));
          this_mask = GUESTFS_COPY_FILE_TO_DEVICE_DESTOFFSET_BITMASK;
        }
        else if (STREQ (this_arg, "size")) {
          optargs_s.size = my_SvIV64 (ST (items_i+1));
          this_mask = GUESTFS_COPY_FILE_TO_DEVICE_SIZE_BITMASK;
        }
        else if (STREQ (this_arg, "sparse")) {
          optargs_s.sparse = SvIV (ST (items_i+1));
          this_mask = GUESTFS_COPY_FILE_TO_DEVICE_SPARSE_BITMASK;
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
        if (STREQ (this_arg, "srcoffset")) {
          optargs_s.srcoffset = my_SvIV64 (ST (items_i+1));
          this_mask = GUESTFS_COPY_FILE_TO_FILE_SRCOFFSET_BITMASK;
        }
        else if (STREQ (this_arg, "destoffset")) {
          optargs_s.destoffset = my_SvIV64 (ST (items_i+1));
          this_mask = GUESTFS_COPY_FILE_TO_FILE_DESTOFFSET_BITMASK;
        }
        else if (STREQ (this_arg, "size")) {
          optargs_s.size = my_SvIV64 (ST (items_i+1));
          this_mask = GUESTFS_COPY_FILE_TO_FILE_SIZE_BITMASK;
        }
        else if (STREQ (this_arg, "sparse")) {
          optargs_s.sparse = SvIV (ST (items_i+1));
          this_mask = GUESTFS_COPY_FILE_TO_FILE_SPARSE_BITMASK;
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

void
tune2fs (g, device, ...)
      guestfs_h *g;
      char *device;
PREINIT:
      int r;
      struct guestfs_tune2fs_argv optargs_s = { .bitmask = 0 };
      struct guestfs_tune2fs_argv *optargs = &optargs_s;
      size_t items_i;
 PPCODE:
      if (((items - 2) & 1) != 0)
        croak ("expecting an even number of extra parameters");
      for (items_i = 2; items_i < items; items_i += 2) {
        uint64_t this_mask;
        const char *this_arg;

        this_arg = SvPV_nolen (ST (items_i));
        if (STREQ (this_arg, "force")) {
          optargs_s.force = SvIV (ST (items_i+1));
          this_mask = GUESTFS_TUNE2FS_FORCE_BITMASK;
        }
        else if (STREQ (this_arg, "maxmountcount")) {
          optargs_s.maxmountcount = SvIV (ST (items_i+1));
          this_mask = GUESTFS_TUNE2FS_MAXMOUNTCOUNT_BITMASK;
        }
        else if (STREQ (this_arg, "mountcount")) {
          optargs_s.mountcount = SvIV (ST (items_i+1));
          this_mask = GUESTFS_TUNE2FS_MOUNTCOUNT_BITMASK;
        }
        else if (STREQ (this_arg, "errorbehavior")) {
          optargs_s.errorbehavior = SvPV_nolen (ST (items_i+1));
          this_mask = GUESTFS_TUNE2FS_ERRORBEHAVIOR_BITMASK;
        }
        else if (STREQ (this_arg, "group")) {
          optargs_s.group = my_SvIV64 (ST (items_i+1));
          this_mask = GUESTFS_TUNE2FS_GROUP_BITMASK;
        }
        else if (STREQ (this_arg, "intervalbetweenchecks")) {
          optargs_s.intervalbetweenchecks = SvIV (ST (items_i+1));
          this_mask = GUESTFS_TUNE2FS_INTERVALBETWEENCHECKS_BITMASK;
        }
        else if (STREQ (this_arg, "reservedblockspercentage")) {
          optargs_s.reservedblockspercentage = SvIV (ST (items_i+1));
          this_mask = GUESTFS_TUNE2FS_RESERVEDBLOCKSPERCENTAGE_BITMASK;
        }
        else if (STREQ (this_arg, "lastmounteddirectory")) {
          optargs_s.lastmounteddirectory = SvPV_nolen (ST (items_i+1));
          this_mask = GUESTFS_TUNE2FS_LASTMOUNTEDDIRECTORY_BITMASK;
        }
        else if (STREQ (this_arg, "reservedblockscount")) {
          optargs_s.reservedblockscount = my_SvIV64 (ST (items_i+1));
          this_mask = GUESTFS_TUNE2FS_RESERVEDBLOCKSCOUNT_BITMASK;
        }
        else if (STREQ (this_arg, "user")) {
          optargs_s.user = my_SvIV64 (ST (items_i+1));
          this_mask = GUESTFS_TUNE2FS_USER_BITMASK;
        }
        else croak ("unknown optional argument '%s'", this_arg);
        if (optargs_s.bitmask & this_mask)
          croak ("optional argument '%s' given twice",
                 this_arg);
        optargs_s.bitmask |= this_mask;
      }

      r = guestfs_tune2fs_argv (g, device, optargs);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

void
md_create (g, name, devices, ...)
      guestfs_h *g;
      char *name;
      char **devices;
PREINIT:
      int r;
      struct guestfs_md_create_argv optargs_s = { .bitmask = 0 };
      struct guestfs_md_create_argv *optargs = &optargs_s;
      size_t items_i;
 PPCODE:
      if (((items - 3) & 1) != 0)
        croak ("expecting an even number of extra parameters");
      for (items_i = 3; items_i < items; items_i += 2) {
        uint64_t this_mask;
        const char *this_arg;

        this_arg = SvPV_nolen (ST (items_i));
        if (STREQ (this_arg, "missingbitmap")) {
          optargs_s.missingbitmap = my_SvIV64 (ST (items_i+1));
          this_mask = GUESTFS_MD_CREATE_MISSINGBITMAP_BITMASK;
        }
        else if (STREQ (this_arg, "nrdevices")) {
          optargs_s.nrdevices = SvIV (ST (items_i+1));
          this_mask = GUESTFS_MD_CREATE_NRDEVICES_BITMASK;
        }
        else if (STREQ (this_arg, "spare")) {
          optargs_s.spare = SvIV (ST (items_i+1));
          this_mask = GUESTFS_MD_CREATE_SPARE_BITMASK;
        }
        else if (STREQ (this_arg, "chunk")) {
          optargs_s.chunk = my_SvIV64 (ST (items_i+1));
          this_mask = GUESTFS_MD_CREATE_CHUNK_BITMASK;
        }
        else if (STREQ (this_arg, "level")) {
          optargs_s.level = SvPV_nolen (ST (items_i+1));
          this_mask = GUESTFS_MD_CREATE_LEVEL_BITMASK;
        }
        else croak ("unknown optional argument '%s'", this_arg);
        if (optargs_s.bitmask & this_mask)
          croak ("optional argument '%s' given twice",
                 this_arg);
        optargs_s.bitmask |= this_mask;
      }

      r = guestfs_md_create_argv (g, name, devices, optargs);
      free (devices);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

void
list_md_devices (g)
      guestfs_h *g;
PREINIT:
      char **r;
      size_t i, n;
 PPCODE:
      r = guestfs_list_md_devices (g);
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
md_detail (g, md)
      guestfs_h *g;
      char *md;
PREINIT:
      char **r;
      size_t i, n;
 PPCODE:
      r = guestfs_md_detail (g, md);
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
md_stop (g, md)
      guestfs_h *g;
      char *md;
PREINIT:
      int r;
 PPCODE:
      r = guestfs_md_stop (g, md);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

void
blkid (g, device)
      guestfs_h *g;
      char *device;
PREINIT:
      char **r;
      size_t i, n;
 PPCODE:
      r = guestfs_blkid (g, device);
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
e2fsck (g, device, ...)
      guestfs_h *g;
      char *device;
PREINIT:
      int r;
      struct guestfs_e2fsck_argv optargs_s = { .bitmask = 0 };
      struct guestfs_e2fsck_argv *optargs = &optargs_s;
      size_t items_i;
 PPCODE:
      if (((items - 2) & 1) != 0)
        croak ("expecting an even number of extra parameters");
      for (items_i = 2; items_i < items; items_i += 2) {
        uint64_t this_mask;
        const char *this_arg;

        this_arg = SvPV_nolen (ST (items_i));
        if (STREQ (this_arg, "correct")) {
          optargs_s.correct = SvIV (ST (items_i+1));
          this_mask = GUESTFS_E2FSCK_CORRECT_BITMASK;
        }
        else if (STREQ (this_arg, "forceall")) {
          optargs_s.forceall = SvIV (ST (items_i+1));
          this_mask = GUESTFS_E2FSCK_FORCEALL_BITMASK;
        }
        else croak ("unknown optional argument '%s'", this_arg);
        if (optargs_s.bitmask & this_mask)
          croak ("optional argument '%s' given twice",
                 this_arg);
        optargs_s.bitmask |= this_mask;
      }

      r = guestfs_e2fsck_argv (g, device, optargs);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

SV *
llz (g, directory)
      guestfs_h *g;
      char *directory;
PREINIT:
      char *r;
   CODE:
      r = guestfs_llz (g, directory);
      if (r == NULL)
        croak ("%s", guestfs_last_error (g));
      RETVAL = newSVpv (r, 0);
      free (r);
 OUTPUT:
      RETVAL

void
wipefs (g, device)
      guestfs_h *g;
      char *device;
PREINIT:
      int r;
 PPCODE:
      r = guestfs_wipefs (g, device);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

void
ntfsfix (g, device, ...)
      guestfs_h *g;
      char *device;
PREINIT:
      int r;
      struct guestfs_ntfsfix_argv optargs_s = { .bitmask = 0 };
      struct guestfs_ntfsfix_argv *optargs = &optargs_s;
      size_t items_i;
 PPCODE:
      if (((items - 2) & 1) != 0)
        croak ("expecting an even number of extra parameters");
      for (items_i = 2; items_i < items; items_i += 2) {
        uint64_t this_mask;
        const char *this_arg;

        this_arg = SvPV_nolen (ST (items_i));
        if (STREQ (this_arg, "clearbadsectors")) {
          optargs_s.clearbadsectors = SvIV (ST (items_i+1));
          this_mask = GUESTFS_NTFSFIX_CLEARBADSECTORS_BITMASK;
        }
        else croak ("unknown optional argument '%s'", this_arg);
        if (optargs_s.bitmask & this_mask)
          croak ("optional argument '%s' given twice",
                 this_arg);
        optargs_s.bitmask |= this_mask;
      }

      r = guestfs_ntfsfix_argv (g, device, optargs);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

void
ntfsclone_out (g, device, backupfile, ...)
      guestfs_h *g;
      char *device;
      char *backupfile;
PREINIT:
      int r;
      struct guestfs_ntfsclone_out_argv optargs_s = { .bitmask = 0 };
      struct guestfs_ntfsclone_out_argv *optargs = &optargs_s;
      size_t items_i;
 PPCODE:
      if (((items - 3) & 1) != 0)
        croak ("expecting an even number of extra parameters");
      for (items_i = 3; items_i < items; items_i += 2) {
        uint64_t this_mask;
        const char *this_arg;

        this_arg = SvPV_nolen (ST (items_i));
        if (STREQ (this_arg, "metadataonly")) {
          optargs_s.metadataonly = SvIV (ST (items_i+1));
          this_mask = GUESTFS_NTFSCLONE_OUT_METADATAONLY_BITMASK;
        }
        else if (STREQ (this_arg, "rescue")) {
          optargs_s.rescue = SvIV (ST (items_i+1));
          this_mask = GUESTFS_NTFSCLONE_OUT_RESCUE_BITMASK;
        }
        else if (STREQ (this_arg, "ignorefscheck")) {
          optargs_s.ignorefscheck = SvIV (ST (items_i+1));
          this_mask = GUESTFS_NTFSCLONE_OUT_IGNOREFSCHECK_BITMASK;
        }
        else if (STREQ (this_arg, "preservetimestamps")) {
          optargs_s.preservetimestamps = SvIV (ST (items_i+1));
          this_mask = GUESTFS_NTFSCLONE_OUT_PRESERVETIMESTAMPS_BITMASK;
        }
        else if (STREQ (this_arg, "force")) {
          optargs_s.force = SvIV (ST (items_i+1));
          this_mask = GUESTFS_NTFSCLONE_OUT_FORCE_BITMASK;
        }
        else croak ("unknown optional argument '%s'", this_arg);
        if (optargs_s.bitmask & this_mask)
          croak ("optional argument '%s' given twice",
                 this_arg);
        optargs_s.bitmask |= this_mask;
      }

      r = guestfs_ntfsclone_out_argv (g, device, backupfile, optargs);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

void
ntfsclone_in (g, backupfile, device)
      guestfs_h *g;
      char *backupfile;
      char *device;
PREINIT:
      int r;
 PPCODE:
      r = guestfs_ntfsclone_in (g, backupfile, device);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

void
set_label (g, mountable, label)
      guestfs_h *g;
      char *mountable;
      char *label;
PREINIT:
      int r;
 PPCODE:
      r = guestfs_set_label (g, mountable, label);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

void
zero_free_space (g, directory)
      guestfs_h *g;
      char *directory;
PREINIT:
      int r;
 PPCODE:
      r = guestfs_zero_free_space (g, directory);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

void
lvcreate_free (g, logvol, volgroup, percent)
      guestfs_h *g;
      char *logvol;
      char *volgroup;
      int percent;
PREINIT:
      int r;
 PPCODE:
      r = guestfs_lvcreate_free (g, logvol, volgroup, percent);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

void
isoinfo_device (g, device)
      guestfs_h *g;
      char *device;
PREINIT:
      struct guestfs_isoinfo *r;
 PPCODE:
      r = guestfs_isoinfo_device (g, device);
      if (r == NULL)
        croak ("%s", guestfs_last_error (g));
      EXTEND (SP, 2 * 17);
      PUSHs (sv_2mortal (newSVpv ("iso_system_id", 0)));
      PUSHs (sv_2mortal (newSVpv (r->iso_system_id, 0)));
      PUSHs (sv_2mortal (newSVpv ("iso_volume_id", 0)));
      PUSHs (sv_2mortal (newSVpv (r->iso_volume_id, 0)));
      PUSHs (sv_2mortal (newSVpv ("iso_volume_space_size", 0)));
      PUSHs (sv_2mortal (newSVnv (r->iso_volume_space_size)));
      PUSHs (sv_2mortal (newSVpv ("iso_volume_set_size", 0)));
      PUSHs (sv_2mortal (newSVnv (r->iso_volume_set_size)));
      PUSHs (sv_2mortal (newSVpv ("iso_volume_sequence_number", 0)));
      PUSHs (sv_2mortal (newSVnv (r->iso_volume_sequence_number)));
      PUSHs (sv_2mortal (newSVpv ("iso_logical_block_size", 0)));
      PUSHs (sv_2mortal (newSVnv (r->iso_logical_block_size)));
      PUSHs (sv_2mortal (newSVpv ("iso_volume_set_id", 0)));
      PUSHs (sv_2mortal (newSVpv (r->iso_volume_set_id, 0)));
      PUSHs (sv_2mortal (newSVpv ("iso_publisher_id", 0)));
      PUSHs (sv_2mortal (newSVpv (r->iso_publisher_id, 0)));
      PUSHs (sv_2mortal (newSVpv ("iso_data_preparer_id", 0)));
      PUSHs (sv_2mortal (newSVpv (r->iso_data_preparer_id, 0)));
      PUSHs (sv_2mortal (newSVpv ("iso_application_id", 0)));
      PUSHs (sv_2mortal (newSVpv (r->iso_application_id, 0)));
      PUSHs (sv_2mortal (newSVpv ("iso_copyright_file_id", 0)));
      PUSHs (sv_2mortal (newSVpv (r->iso_copyright_file_id, 0)));
      PUSHs (sv_2mortal (newSVpv ("iso_abstract_file_id", 0)));
      PUSHs (sv_2mortal (newSVpv (r->iso_abstract_file_id, 0)));
      PUSHs (sv_2mortal (newSVpv ("iso_bibliographic_file_id", 0)));
      PUSHs (sv_2mortal (newSVpv (r->iso_bibliographic_file_id, 0)));
      PUSHs (sv_2mortal (newSVpv ("iso_volume_creation_t", 0)));
      PUSHs (sv_2mortal (my_newSVll (r->iso_volume_creation_t)));
      PUSHs (sv_2mortal (newSVpv ("iso_volume_modification_t", 0)));
      PUSHs (sv_2mortal (my_newSVll (r->iso_volume_modification_t)));
      PUSHs (sv_2mortal (newSVpv ("iso_volume_expiration_t", 0)));
      PUSHs (sv_2mortal (my_newSVll (r->iso_volume_expiration_t)));
      PUSHs (sv_2mortal (newSVpv ("iso_volume_effective_t", 0)));
      PUSHs (sv_2mortal (my_newSVll (r->iso_volume_effective_t)));
      free (r);

void
isoinfo (g, isofile)
      guestfs_h *g;
      char *isofile;
PREINIT:
      struct guestfs_isoinfo *r;
 PPCODE:
      r = guestfs_isoinfo (g, isofile);
      if (r == NULL)
        croak ("%s", guestfs_last_error (g));
      EXTEND (SP, 2 * 17);
      PUSHs (sv_2mortal (newSVpv ("iso_system_id", 0)));
      PUSHs (sv_2mortal (newSVpv (r->iso_system_id, 0)));
      PUSHs (sv_2mortal (newSVpv ("iso_volume_id", 0)));
      PUSHs (sv_2mortal (newSVpv (r->iso_volume_id, 0)));
      PUSHs (sv_2mortal (newSVpv ("iso_volume_space_size", 0)));
      PUSHs (sv_2mortal (newSVnv (r->iso_volume_space_size)));
      PUSHs (sv_2mortal (newSVpv ("iso_volume_set_size", 0)));
      PUSHs (sv_2mortal (newSVnv (r->iso_volume_set_size)));
      PUSHs (sv_2mortal (newSVpv ("iso_volume_sequence_number", 0)));
      PUSHs (sv_2mortal (newSVnv (r->iso_volume_sequence_number)));
      PUSHs (sv_2mortal (newSVpv ("iso_logical_block_size", 0)));
      PUSHs (sv_2mortal (newSVnv (r->iso_logical_block_size)));
      PUSHs (sv_2mortal (newSVpv ("iso_volume_set_id", 0)));
      PUSHs (sv_2mortal (newSVpv (r->iso_volume_set_id, 0)));
      PUSHs (sv_2mortal (newSVpv ("iso_publisher_id", 0)));
      PUSHs (sv_2mortal (newSVpv (r->iso_publisher_id, 0)));
      PUSHs (sv_2mortal (newSVpv ("iso_data_preparer_id", 0)));
      PUSHs (sv_2mortal (newSVpv (r->iso_data_preparer_id, 0)));
      PUSHs (sv_2mortal (newSVpv ("iso_application_id", 0)));
      PUSHs (sv_2mortal (newSVpv (r->iso_application_id, 0)));
      PUSHs (sv_2mortal (newSVpv ("iso_copyright_file_id", 0)));
      PUSHs (sv_2mortal (newSVpv (r->iso_copyright_file_id, 0)));
      PUSHs (sv_2mortal (newSVpv ("iso_abstract_file_id", 0)));
      PUSHs (sv_2mortal (newSVpv (r->iso_abstract_file_id, 0)));
      PUSHs (sv_2mortal (newSVpv ("iso_bibliographic_file_id", 0)));
      PUSHs (sv_2mortal (newSVpv (r->iso_bibliographic_file_id, 0)));
      PUSHs (sv_2mortal (newSVpv ("iso_volume_creation_t", 0)));
      PUSHs (sv_2mortal (my_newSVll (r->iso_volume_creation_t)));
      PUSHs (sv_2mortal (newSVpv ("iso_volume_modification_t", 0)));
      PUSHs (sv_2mortal (my_newSVll (r->iso_volume_modification_t)));
      PUSHs (sv_2mortal (newSVpv ("iso_volume_expiration_t", 0)));
      PUSHs (sv_2mortal (my_newSVll (r->iso_volume_expiration_t)));
      PUSHs (sv_2mortal (newSVpv ("iso_volume_effective_t", 0)));
      PUSHs (sv_2mortal (my_newSVll (r->iso_volume_effective_t)));
      free (r);

SV *
vgmeta (g, vgname)
      guestfs_h *g;
      char *vgname;
PREINIT:
      char *r;
      size_t size;
   CODE:
      r = guestfs_vgmeta (g, vgname, &size);
      if (r == NULL)
        croak ("%s", guestfs_last_error (g));
      RETVAL = newSVpvn (r, size);
      free (r);
 OUTPUT:
      RETVAL

void
md_stat (g, md)
      guestfs_h *g;
      char *md;
PREINIT:
      struct guestfs_mdstat_list *r;
      size_t i;
      HV *hv;
 PPCODE:
      r = guestfs_md_stat (g, md);
      if (r == NULL)
        croak ("%s", guestfs_last_error (g));
      EXTEND (SP, r->len);
      for (i = 0; i < r->len; ++i) {
        hv = newHV ();
        (void) hv_store (hv, "mdstat_device", 13, newSVpv (r->val[i].mdstat_device, 0), 0);
        (void) hv_store (hv, "mdstat_index", 12, newSVnv (r->val[i].mdstat_index), 0);
        (void) hv_store (hv, "mdstat_flags", 12, newSVpv (r->val[i].mdstat_flags, 0), 0);
        PUSHs (sv_2mortal (newRV ((SV *) hv)));
      }
      guestfs_free_mdstat_list (r);

void
mkfs_btrfs (g, devices, ...)
      guestfs_h *g;
      char **devices;
PREINIT:
      int r;
      struct guestfs_mkfs_btrfs_argv optargs_s = { .bitmask = 0 };
      struct guestfs_mkfs_btrfs_argv *optargs = &optargs_s;
      size_t items_i;
 PPCODE:
      if (((items - 2) & 1) != 0)
        croak ("expecting an even number of extra parameters");
      for (items_i = 2; items_i < items; items_i += 2) {
        uint64_t this_mask;
        const char *this_arg;

        this_arg = SvPV_nolen (ST (items_i));
        if (STREQ (this_arg, "allocstart")) {
          optargs_s.allocstart = my_SvIV64 (ST (items_i+1));
          this_mask = GUESTFS_MKFS_BTRFS_ALLOCSTART_BITMASK;
        }
        else if (STREQ (this_arg, "bytecount")) {
          optargs_s.bytecount = my_SvIV64 (ST (items_i+1));
          this_mask = GUESTFS_MKFS_BTRFS_BYTECOUNT_BITMASK;
        }
        else if (STREQ (this_arg, "datatype")) {
          optargs_s.datatype = SvPV_nolen (ST (items_i+1));
          this_mask = GUESTFS_MKFS_BTRFS_DATATYPE_BITMASK;
        }
        else if (STREQ (this_arg, "leafsize")) {
          optargs_s.leafsize = SvIV (ST (items_i+1));
          this_mask = GUESTFS_MKFS_BTRFS_LEAFSIZE_BITMASK;
        }
        else if (STREQ (this_arg, "label")) {
          optargs_s.label = SvPV_nolen (ST (items_i+1));
          this_mask = GUESTFS_MKFS_BTRFS_LABEL_BITMASK;
        }
        else if (STREQ (this_arg, "metadata")) {
          optargs_s.metadata = SvPV_nolen (ST (items_i+1));
          this_mask = GUESTFS_MKFS_BTRFS_METADATA_BITMASK;
        }
        else if (STREQ (this_arg, "nodesize")) {
          optargs_s.nodesize = SvIV (ST (items_i+1));
          this_mask = GUESTFS_MKFS_BTRFS_NODESIZE_BITMASK;
        }
        else if (STREQ (this_arg, "sectorsize")) {
          optargs_s.sectorsize = SvIV (ST (items_i+1));
          this_mask = GUESTFS_MKFS_BTRFS_SECTORSIZE_BITMASK;
        }
        else croak ("unknown optional argument '%s'", this_arg);
        if (optargs_s.bitmask & this_mask)
          croak ("optional argument '%s' given twice",
                 this_arg);
        optargs_s.bitmask |= this_mask;
      }

      r = guestfs_mkfs_btrfs_argv (g, devices, optargs);
      free (devices);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

SV *
get_e2attrs (g, file)
      guestfs_h *g;
      char *file;
PREINIT:
      char *r;
   CODE:
      r = guestfs_get_e2attrs (g, file);
      if (r == NULL)
        croak ("%s", guestfs_last_error (g));
      RETVAL = newSVpv (r, 0);
      free (r);
 OUTPUT:
      RETVAL

void
set_e2attrs (g, file, attrs, ...)
      guestfs_h *g;
      char *file;
      char *attrs;
PREINIT:
      int r;
      struct guestfs_set_e2attrs_argv optargs_s = { .bitmask = 0 };
      struct guestfs_set_e2attrs_argv *optargs = &optargs_s;
      size_t items_i;
 PPCODE:
      if (((items - 3) & 1) != 0)
        croak ("expecting an even number of extra parameters");
      for (items_i = 3; items_i < items; items_i += 2) {
        uint64_t this_mask;
        const char *this_arg;

        this_arg = SvPV_nolen (ST (items_i));
        if (STREQ (this_arg, "clear")) {
          optargs_s.clear = SvIV (ST (items_i+1));
          this_mask = GUESTFS_SET_E2ATTRS_CLEAR_BITMASK;
        }
        else croak ("unknown optional argument '%s'", this_arg);
        if (optargs_s.bitmask & this_mask)
          croak ("optional argument '%s' given twice",
                 this_arg);
        optargs_s.bitmask |= this_mask;
      }

      r = guestfs_set_e2attrs_argv (g, file, attrs, optargs);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

SV *
get_e2generation (g, file)
      guestfs_h *g;
      char *file;
PREINIT:
      int64_t r;
   CODE:
      r = guestfs_get_e2generation (g, file);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));
      RETVAL = my_newSVll (r);
 OUTPUT:
      RETVAL

void
set_e2generation (g, file, generation)
      guestfs_h *g;
      char *file;
      int64_t generation;
PREINIT:
      int r;
 PPCODE:
      r = guestfs_set_e2generation (g, file, generation);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

void
btrfs_subvolume_snapshot (g, source, dest)
      guestfs_h *g;
      char *source;
      char *dest;
PREINIT:
      int r;
 PPCODE:
      r = guestfs_btrfs_subvolume_snapshot (g, source, dest);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

void
btrfs_subvolume_delete (g, subvolume)
      guestfs_h *g;
      char *subvolume;
PREINIT:
      int r;
 PPCODE:
      r = guestfs_btrfs_subvolume_delete (g, subvolume);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

void
btrfs_subvolume_create (g, dest)
      guestfs_h *g;
      char *dest;
PREINIT:
      int r;
 PPCODE:
      r = guestfs_btrfs_subvolume_create (g, dest);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

void
btrfs_subvolume_list (g, fs)
      guestfs_h *g;
      char *fs;
PREINIT:
      struct guestfs_btrfssubvolume_list *r;
      size_t i;
      HV *hv;
 PPCODE:
      r = guestfs_btrfs_subvolume_list (g, fs);
      if (r == NULL)
        croak ("%s", guestfs_last_error (g));
      EXTEND (SP, r->len);
      for (i = 0; i < r->len; ++i) {
        hv = newHV ();
        (void) hv_store (hv, "btrfssubvolume_id", 17, my_newSVull (r->val[i].btrfssubvolume_id), 0);
        (void) hv_store (hv, "btrfssubvolume_top_level_id", 27, my_newSVull (r->val[i].btrfssubvolume_top_level_id), 0);
        (void) hv_store (hv, "btrfssubvolume_path", 19, newSVpv (r->val[i].btrfssubvolume_path, 0), 0);
        PUSHs (sv_2mortal (newRV ((SV *) hv)));
      }
      guestfs_free_btrfssubvolume_list (r);

void
btrfs_subvolume_set_default (g, id, fs)
      guestfs_h *g;
      int64_t id;
      char *fs;
PREINIT:
      int r;
 PPCODE:
      r = guestfs_btrfs_subvolume_set_default (g, id, fs);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

void
btrfs_filesystem_sync (g, fs)
      guestfs_h *g;
      char *fs;
PREINIT:
      int r;
 PPCODE:
      r = guestfs_btrfs_filesystem_sync (g, fs);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

void
btrfs_filesystem_balance (g, fs)
      guestfs_h *g;
      char *fs;
PREINIT:
      int r;
 PPCODE:
      r = guestfs_btrfs_filesystem_balance (g, fs);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

void
btrfs_device_add (g, devices, fs)
      guestfs_h *g;
      char **devices;
      char *fs;
PREINIT:
      int r;
 PPCODE:
      r = guestfs_btrfs_device_add (g, devices, fs);
      free (devices);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

void
btrfs_device_delete (g, devices, fs)
      guestfs_h *g;
      char **devices;
      char *fs;
PREINIT:
      int r;
 PPCODE:
      r = guestfs_btrfs_device_delete (g, devices, fs);
      free (devices);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

void
btrfs_set_seeding (g, device, seeding)
      guestfs_h *g;
      char *device;
      int seeding;
PREINIT:
      int r;
 PPCODE:
      r = guestfs_btrfs_set_seeding (g, device, seeding);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

void
btrfs_fsck (g, device, ...)
      guestfs_h *g;
      char *device;
PREINIT:
      int r;
      struct guestfs_btrfs_fsck_argv optargs_s = { .bitmask = 0 };
      struct guestfs_btrfs_fsck_argv *optargs = &optargs_s;
      size_t items_i;
 PPCODE:
      if (((items - 2) & 1) != 0)
        croak ("expecting an even number of extra parameters");
      for (items_i = 2; items_i < items; items_i += 2) {
        uint64_t this_mask;
        const char *this_arg;

        this_arg = SvPV_nolen (ST (items_i));
        if (STREQ (this_arg, "superblock")) {
          optargs_s.superblock = my_SvIV64 (ST (items_i+1));
          this_mask = GUESTFS_BTRFS_FSCK_SUPERBLOCK_BITMASK;
        }
        else if (STREQ (this_arg, "repair")) {
          optargs_s.repair = SvIV (ST (items_i+1));
          this_mask = GUESTFS_BTRFS_FSCK_REPAIR_BITMASK;
        }
        else croak ("unknown optional argument '%s'", this_arg);
        if (optargs_s.bitmask & this_mask)
          croak ("optional argument '%s' given twice",
                 this_arg);
        optargs_s.bitmask |= this_mask;
      }

      r = guestfs_btrfs_fsck_argv (g, device, optargs);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

SV *
filesystem_available (g, filesystem)
      guestfs_h *g;
      char *filesystem;
PREINIT:
      int r;
   CODE:
      r = guestfs_filesystem_available (g, filesystem);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));
      RETVAL = newSViv (r);
 OUTPUT:
      RETVAL

void
fstrim (g, mountpoint, ...)
      guestfs_h *g;
      char *mountpoint;
PREINIT:
      int r;
      struct guestfs_fstrim_argv optargs_s = { .bitmask = 0 };
      struct guestfs_fstrim_argv *optargs = &optargs_s;
      size_t items_i;
 PPCODE:
      if (((items - 2) & 1) != 0)
        croak ("expecting an even number of extra parameters");
      for (items_i = 2; items_i < items; items_i += 2) {
        uint64_t this_mask;
        const char *this_arg;

        this_arg = SvPV_nolen (ST (items_i));
        if (STREQ (this_arg, "offset")) {
          optargs_s.offset = my_SvIV64 (ST (items_i+1));
          this_mask = GUESTFS_FSTRIM_OFFSET_BITMASK;
        }
        else if (STREQ (this_arg, "length")) {
          optargs_s.length = my_SvIV64 (ST (items_i+1));
          this_mask = GUESTFS_FSTRIM_LENGTH_BITMASK;
        }
        else if (STREQ (this_arg, "minimumfreeextent")) {
          optargs_s.minimumfreeextent = my_SvIV64 (ST (items_i+1));
          this_mask = GUESTFS_FSTRIM_MINIMUMFREEEXTENT_BITMASK;
        }
        else croak ("unknown optional argument '%s'", this_arg);
        if (optargs_s.bitmask & this_mask)
          croak ("optional argument '%s' given twice",
                 this_arg);
        optargs_s.bitmask |= this_mask;
      }

      r = guestfs_fstrim_argv (g, mountpoint, optargs);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

SV *
device_index (g, device)
      guestfs_h *g;
      char *device;
PREINIT:
      int r;
   CODE:
      r = guestfs_device_index (g, device);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));
      RETVAL = newSViv (r);
 OUTPUT:
      RETVAL

SV *
nr_devices (g)
      guestfs_h *g;
PREINIT:
      int r;
   CODE:
      r = guestfs_nr_devices (g);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));
      RETVAL = newSViv (r);
 OUTPUT:
      RETVAL

void
xfs_info (g, pathordevice)
      guestfs_h *g;
      char *pathordevice;
PREINIT:
      struct guestfs_xfsinfo *r;
 PPCODE:
      r = guestfs_xfs_info (g, pathordevice);
      if (r == NULL)
        croak ("%s", guestfs_last_error (g));
      EXTEND (SP, 2 * 25);
      PUSHs (sv_2mortal (newSVpv ("xfs_mntpoint", 0)));
      PUSHs (sv_2mortal (newSVpv (r->xfs_mntpoint, 0)));
      PUSHs (sv_2mortal (newSVpv ("xfs_inodesize", 0)));
      PUSHs (sv_2mortal (newSVnv (r->xfs_inodesize)));
      PUSHs (sv_2mortal (newSVpv ("xfs_agcount", 0)));
      PUSHs (sv_2mortal (newSVnv (r->xfs_agcount)));
      PUSHs (sv_2mortal (newSVpv ("xfs_agsize", 0)));
      PUSHs (sv_2mortal (newSVnv (r->xfs_agsize)));
      PUSHs (sv_2mortal (newSVpv ("xfs_sectsize", 0)));
      PUSHs (sv_2mortal (newSVnv (r->xfs_sectsize)));
      PUSHs (sv_2mortal (newSVpv ("xfs_attr", 0)));
      PUSHs (sv_2mortal (newSVnv (r->xfs_attr)));
      PUSHs (sv_2mortal (newSVpv ("xfs_blocksize", 0)));
      PUSHs (sv_2mortal (newSVnv (r->xfs_blocksize)));
      PUSHs (sv_2mortal (newSVpv ("xfs_datablocks", 0)));
      PUSHs (sv_2mortal (my_newSVull (r->xfs_datablocks)));
      PUSHs (sv_2mortal (newSVpv ("xfs_imaxpct", 0)));
      PUSHs (sv_2mortal (newSVnv (r->xfs_imaxpct)));
      PUSHs (sv_2mortal (newSVpv ("xfs_sunit", 0)));
      PUSHs (sv_2mortal (newSVnv (r->xfs_sunit)));
      PUSHs (sv_2mortal (newSVpv ("xfs_swidth", 0)));
      PUSHs (sv_2mortal (newSVnv (r->xfs_swidth)));
      PUSHs (sv_2mortal (newSVpv ("xfs_dirversion", 0)));
      PUSHs (sv_2mortal (newSVnv (r->xfs_dirversion)));
      PUSHs (sv_2mortal (newSVpv ("xfs_dirblocksize", 0)));
      PUSHs (sv_2mortal (newSVnv (r->xfs_dirblocksize)));
      PUSHs (sv_2mortal (newSVpv ("xfs_cimode", 0)));
      PUSHs (sv_2mortal (newSVnv (r->xfs_cimode)));
      PUSHs (sv_2mortal (newSVpv ("xfs_logname", 0)));
      PUSHs (sv_2mortal (newSVpv (r->xfs_logname, 0)));
      PUSHs (sv_2mortal (newSVpv ("xfs_logblocksize", 0)));
      PUSHs (sv_2mortal (newSVnv (r->xfs_logblocksize)));
      PUSHs (sv_2mortal (newSVpv ("xfs_logblocks", 0)));
      PUSHs (sv_2mortal (newSVnv (r->xfs_logblocks)));
      PUSHs (sv_2mortal (newSVpv ("xfs_logversion", 0)));
      PUSHs (sv_2mortal (newSVnv (r->xfs_logversion)));
      PUSHs (sv_2mortal (newSVpv ("xfs_logsectsize", 0)));
      PUSHs (sv_2mortal (newSVnv (r->xfs_logsectsize)));
      PUSHs (sv_2mortal (newSVpv ("xfs_logsunit", 0)));
      PUSHs (sv_2mortal (newSVnv (r->xfs_logsunit)));
      PUSHs (sv_2mortal (newSVpv ("xfs_lazycount", 0)));
      PUSHs (sv_2mortal (newSVnv (r->xfs_lazycount)));
      PUSHs (sv_2mortal (newSVpv ("xfs_rtname", 0)));
      PUSHs (sv_2mortal (newSVpv (r->xfs_rtname, 0)));
      PUSHs (sv_2mortal (newSVpv ("xfs_rtextsize", 0)));
      PUSHs (sv_2mortal (newSVnv (r->xfs_rtextsize)));
      PUSHs (sv_2mortal (newSVpv ("xfs_rtblocks", 0)));
      PUSHs (sv_2mortal (my_newSVull (r->xfs_rtblocks)));
      PUSHs (sv_2mortal (newSVpv ("xfs_rtextents", 0)));
      PUSHs (sv_2mortal (my_newSVull (r->xfs_rtextents)));
      free (r);

void
pvchange_uuid (g, device)
      guestfs_h *g;
      char *device;
PREINIT:
      int r;
 PPCODE:
      r = guestfs_pvchange_uuid (g, device);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

void
pvchange_uuid_all (g)
      guestfs_h *g;
PREINIT:
      int r;
 PPCODE:
      r = guestfs_pvchange_uuid_all (g);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

void
vgchange_uuid (g, vg)
      guestfs_h *g;
      char *vg;
PREINIT:
      int r;
 PPCODE:
      r = guestfs_vgchange_uuid (g, vg);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

void
vgchange_uuid_all (g)
      guestfs_h *g;
PREINIT:
      int r;
 PPCODE:
      r = guestfs_vgchange_uuid_all (g);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

void
utsname (g)
      guestfs_h *g;
PREINIT:
      struct guestfs_utsname *r;
 PPCODE:
      r = guestfs_utsname (g);
      if (r == NULL)
        croak ("%s", guestfs_last_error (g));
      EXTEND (SP, 2 * 4);
      PUSHs (sv_2mortal (newSVpv ("uts_sysname", 0)));
      PUSHs (sv_2mortal (newSVpv (r->uts_sysname, 0)));
      PUSHs (sv_2mortal (newSVpv ("uts_release", 0)));
      PUSHs (sv_2mortal (newSVpv (r->uts_release, 0)));
      PUSHs (sv_2mortal (newSVpv ("uts_version", 0)));
      PUSHs (sv_2mortal (newSVpv (r->uts_version, 0)));
      PUSHs (sv_2mortal (newSVpv ("uts_machine", 0)));
      PUSHs (sv_2mortal (newSVpv (r->uts_machine, 0)));
      free (r);

void
xfs_growfs (g, path, ...)
      guestfs_h *g;
      char *path;
PREINIT:
      int r;
      struct guestfs_xfs_growfs_argv optargs_s = { .bitmask = 0 };
      struct guestfs_xfs_growfs_argv *optargs = &optargs_s;
      size_t items_i;
 PPCODE:
      if (((items - 2) & 1) != 0)
        croak ("expecting an even number of extra parameters");
      for (items_i = 2; items_i < items; items_i += 2) {
        uint64_t this_mask;
        const char *this_arg;

        this_arg = SvPV_nolen (ST (items_i));
        if (STREQ (this_arg, "datasec")) {
          optargs_s.datasec = SvIV (ST (items_i+1));
          this_mask = GUESTFS_XFS_GROWFS_DATASEC_BITMASK;
        }
        else if (STREQ (this_arg, "logsec")) {
          optargs_s.logsec = SvIV (ST (items_i+1));
          this_mask = GUESTFS_XFS_GROWFS_LOGSEC_BITMASK;
        }
        else if (STREQ (this_arg, "rtsec")) {
          optargs_s.rtsec = SvIV (ST (items_i+1));
          this_mask = GUESTFS_XFS_GROWFS_RTSEC_BITMASK;
        }
        else if (STREQ (this_arg, "datasize")) {
          optargs_s.datasize = my_SvIV64 (ST (items_i+1));
          this_mask = GUESTFS_XFS_GROWFS_DATASIZE_BITMASK;
        }
        else if (STREQ (this_arg, "logsize")) {
          optargs_s.logsize = my_SvIV64 (ST (items_i+1));
          this_mask = GUESTFS_XFS_GROWFS_LOGSIZE_BITMASK;
        }
        else if (STREQ (this_arg, "rtsize")) {
          optargs_s.rtsize = my_SvIV64 (ST (items_i+1));
          this_mask = GUESTFS_XFS_GROWFS_RTSIZE_BITMASK;
        }
        else if (STREQ (this_arg, "rtextsize")) {
          optargs_s.rtextsize = my_SvIV64 (ST (items_i+1));
          this_mask = GUESTFS_XFS_GROWFS_RTEXTSIZE_BITMASK;
        }
        else if (STREQ (this_arg, "maxpct")) {
          optargs_s.maxpct = SvIV (ST (items_i+1));
          this_mask = GUESTFS_XFS_GROWFS_MAXPCT_BITMASK;
        }
        else croak ("unknown optional argument '%s'", this_arg);
        if (optargs_s.bitmask & this_mask)
          croak ("optional argument '%s' given twice",
                 this_arg);
        optargs_s.bitmask |= this_mask;
      }

      r = guestfs_xfs_growfs_argv (g, path, optargs);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

void
rsync (g, src, dest, ...)
      guestfs_h *g;
      char *src;
      char *dest;
PREINIT:
      int r;
      struct guestfs_rsync_argv optargs_s = { .bitmask = 0 };
      struct guestfs_rsync_argv *optargs = &optargs_s;
      size_t items_i;
 PPCODE:
      if (((items - 3) & 1) != 0)
        croak ("expecting an even number of extra parameters");
      for (items_i = 3; items_i < items; items_i += 2) {
        uint64_t this_mask;
        const char *this_arg;

        this_arg = SvPV_nolen (ST (items_i));
        if (STREQ (this_arg, "archive")) {
          optargs_s.archive = SvIV (ST (items_i+1));
          this_mask = GUESTFS_RSYNC_ARCHIVE_BITMASK;
        }
        else if (STREQ (this_arg, "deletedest")) {
          optargs_s.deletedest = SvIV (ST (items_i+1));
          this_mask = GUESTFS_RSYNC_DELETEDEST_BITMASK;
        }
        else croak ("unknown optional argument '%s'", this_arg);
        if (optargs_s.bitmask & this_mask)
          croak ("optional argument '%s' given twice",
                 this_arg);
        optargs_s.bitmask |= this_mask;
      }

      r = guestfs_rsync_argv (g, src, dest, optargs);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

void
rsync_in (g, remote, dest, ...)
      guestfs_h *g;
      char *remote;
      char *dest;
PREINIT:
      int r;
      struct guestfs_rsync_in_argv optargs_s = { .bitmask = 0 };
      struct guestfs_rsync_in_argv *optargs = &optargs_s;
      size_t items_i;
 PPCODE:
      if (((items - 3) & 1) != 0)
        croak ("expecting an even number of extra parameters");
      for (items_i = 3; items_i < items; items_i += 2) {
        uint64_t this_mask;
        const char *this_arg;

        this_arg = SvPV_nolen (ST (items_i));
        if (STREQ (this_arg, "archive")) {
          optargs_s.archive = SvIV (ST (items_i+1));
          this_mask = GUESTFS_RSYNC_IN_ARCHIVE_BITMASK;
        }
        else if (STREQ (this_arg, "deletedest")) {
          optargs_s.deletedest = SvIV (ST (items_i+1));
          this_mask = GUESTFS_RSYNC_IN_DELETEDEST_BITMASK;
        }
        else croak ("unknown optional argument '%s'", this_arg);
        if (optargs_s.bitmask & this_mask)
          croak ("optional argument '%s' given twice",
                 this_arg);
        optargs_s.bitmask |= this_mask;
      }

      r = guestfs_rsync_in_argv (g, remote, dest, optargs);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

void
rsync_out (g, src, remote, ...)
      guestfs_h *g;
      char *src;
      char *remote;
PREINIT:
      int r;
      struct guestfs_rsync_out_argv optargs_s = { .bitmask = 0 };
      struct guestfs_rsync_out_argv *optargs = &optargs_s;
      size_t items_i;
 PPCODE:
      if (((items - 3) & 1) != 0)
        croak ("expecting an even number of extra parameters");
      for (items_i = 3; items_i < items; items_i += 2) {
        uint64_t this_mask;
        const char *this_arg;

        this_arg = SvPV_nolen (ST (items_i));
        if (STREQ (this_arg, "archive")) {
          optargs_s.archive = SvIV (ST (items_i+1));
          this_mask = GUESTFS_RSYNC_OUT_ARCHIVE_BITMASK;
        }
        else if (STREQ (this_arg, "deletedest")) {
          optargs_s.deletedest = SvIV (ST (items_i+1));
          this_mask = GUESTFS_RSYNC_OUT_DELETEDEST_BITMASK;
        }
        else croak ("unknown optional argument '%s'", this_arg);
        if (optargs_s.bitmask & this_mask)
          croak ("optional argument '%s' given twice",
                 this_arg);
        optargs_s.bitmask |= this_mask;
      }

      r = guestfs_rsync_out_argv (g, src, remote, optargs);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

void
ls0 (g, dir, filenames)
      guestfs_h *g;
      char *dir;
      char *filenames;
PREINIT:
      int r;
 PPCODE:
      r = guestfs_ls0 (g, dir, filenames);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

void
fill_dir (g, dir, nr)
      guestfs_h *g;
      char *dir;
      int nr;
PREINIT:
      int r;
 PPCODE:
      r = guestfs_fill_dir (g, dir, nr);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

void
xfs_admin (g, device, ...)
      guestfs_h *g;
      char *device;
PREINIT:
      int r;
      struct guestfs_xfs_admin_argv optargs_s = { .bitmask = 0 };
      struct guestfs_xfs_admin_argv *optargs = &optargs_s;
      size_t items_i;
 PPCODE:
      if (((items - 2) & 1) != 0)
        croak ("expecting an even number of extra parameters");
      for (items_i = 2; items_i < items; items_i += 2) {
        uint64_t this_mask;
        const char *this_arg;

        this_arg = SvPV_nolen (ST (items_i));
        if (STREQ (this_arg, "extunwritten")) {
          optargs_s.extunwritten = SvIV (ST (items_i+1));
          this_mask = GUESTFS_XFS_ADMIN_EXTUNWRITTEN_BITMASK;
        }
        else if (STREQ (this_arg, "imgfile")) {
          optargs_s.imgfile = SvIV (ST (items_i+1));
          this_mask = GUESTFS_XFS_ADMIN_IMGFILE_BITMASK;
        }
        else if (STREQ (this_arg, "v2log")) {
          optargs_s.v2log = SvIV (ST (items_i+1));
          this_mask = GUESTFS_XFS_ADMIN_V2LOG_BITMASK;
        }
        else if (STREQ (this_arg, "projid32bit")) {
          optargs_s.projid32bit = SvIV (ST (items_i+1));
          this_mask = GUESTFS_XFS_ADMIN_PROJID32BIT_BITMASK;
        }
        else if (STREQ (this_arg, "lazycounter")) {
          optargs_s.lazycounter = SvIV (ST (items_i+1));
          this_mask = GUESTFS_XFS_ADMIN_LAZYCOUNTER_BITMASK;
        }
        else if (STREQ (this_arg, "label")) {
          optargs_s.label = SvPV_nolen (ST (items_i+1));
          this_mask = GUESTFS_XFS_ADMIN_LABEL_BITMASK;
        }
        else if (STREQ (this_arg, "uuid")) {
          optargs_s.uuid = SvPV_nolen (ST (items_i+1));
          this_mask = GUESTFS_XFS_ADMIN_UUID_BITMASK;
        }
        else croak ("unknown optional argument '%s'", this_arg);
        if (optargs_s.bitmask & this_mask)
          croak ("optional argument '%s' given twice",
                 this_arg);
        optargs_s.bitmask |= this_mask;
      }

      r = guestfs_xfs_admin_argv (g, device, optargs);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

void
hivex_open (g, filename, ...)
      guestfs_h *g;
      char *filename;
PREINIT:
      int r;
      struct guestfs_hivex_open_argv optargs_s = { .bitmask = 0 };
      struct guestfs_hivex_open_argv *optargs = &optargs_s;
      size_t items_i;
 PPCODE:
      if (((items - 2) & 1) != 0)
        croak ("expecting an even number of extra parameters");
      for (items_i = 2; items_i < items; items_i += 2) {
        uint64_t this_mask;
        const char *this_arg;

        this_arg = SvPV_nolen (ST (items_i));
        if (STREQ (this_arg, "verbose")) {
          optargs_s.verbose = SvIV (ST (items_i+1));
          this_mask = GUESTFS_HIVEX_OPEN_VERBOSE_BITMASK;
        }
        else if (STREQ (this_arg, "debug")) {
          optargs_s.debug = SvIV (ST (items_i+1));
          this_mask = GUESTFS_HIVEX_OPEN_DEBUG_BITMASK;
        }
        else if (STREQ (this_arg, "write")) {
          optargs_s.write = SvIV (ST (items_i+1));
          this_mask = GUESTFS_HIVEX_OPEN_WRITE_BITMASK;
        }
        else croak ("unknown optional argument '%s'", this_arg);
        if (optargs_s.bitmask & this_mask)
          croak ("optional argument '%s' given twice",
                 this_arg);
        optargs_s.bitmask |= this_mask;
      }

      r = guestfs_hivex_open_argv (g, filename, optargs);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

void
hivex_close (g)
      guestfs_h *g;
PREINIT:
      int r;
 PPCODE:
      r = guestfs_hivex_close (g);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

SV *
hivex_root (g)
      guestfs_h *g;
PREINIT:
      int64_t r;
   CODE:
      r = guestfs_hivex_root (g);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));
      RETVAL = my_newSVll (r);
 OUTPUT:
      RETVAL

SV *
hivex_node_name (g, nodeh)
      guestfs_h *g;
      int64_t nodeh;
PREINIT:
      char *r;
   CODE:
      r = guestfs_hivex_node_name (g, nodeh);
      if (r == NULL)
        croak ("%s", guestfs_last_error (g));
      RETVAL = newSVpv (r, 0);
      free (r);
 OUTPUT:
      RETVAL

void
hivex_node_children (g, nodeh)
      guestfs_h *g;
      int64_t nodeh;
PREINIT:
      struct guestfs_hivex_node_list *r;
      size_t i;
      HV *hv;
 PPCODE:
      r = guestfs_hivex_node_children (g, nodeh);
      if (r == NULL)
        croak ("%s", guestfs_last_error (g));
      EXTEND (SP, r->len);
      for (i = 0; i < r->len; ++i) {
        hv = newHV ();
        (void) hv_store (hv, "hivex_node_h", 12, my_newSVll (r->val[i].hivex_node_h), 0);
        PUSHs (sv_2mortal (newRV ((SV *) hv)));
      }
      guestfs_free_hivex_node_list (r);

SV *
hivex_node_get_child (g, nodeh, name)
      guestfs_h *g;
      int64_t nodeh;
      char *name;
PREINIT:
      int64_t r;
   CODE:
      r = guestfs_hivex_node_get_child (g, nodeh, name);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));
      RETVAL = my_newSVll (r);
 OUTPUT:
      RETVAL

SV *
hivex_node_parent (g, nodeh)
      guestfs_h *g;
      int64_t nodeh;
PREINIT:
      int64_t r;
   CODE:
      r = guestfs_hivex_node_parent (g, nodeh);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));
      RETVAL = my_newSVll (r);
 OUTPUT:
      RETVAL

void
hivex_node_values (g, nodeh)
      guestfs_h *g;
      int64_t nodeh;
PREINIT:
      struct guestfs_hivex_value_list *r;
      size_t i;
      HV *hv;
 PPCODE:
      r = guestfs_hivex_node_values (g, nodeh);
      if (r == NULL)
        croak ("%s", guestfs_last_error (g));
      EXTEND (SP, r->len);
      for (i = 0; i < r->len; ++i) {
        hv = newHV ();
        (void) hv_store (hv, "hivex_value_h", 13, my_newSVll (r->val[i].hivex_value_h), 0);
        PUSHs (sv_2mortal (newRV ((SV *) hv)));
      }
      guestfs_free_hivex_value_list (r);

SV *
hivex_node_get_value (g, nodeh, key)
      guestfs_h *g;
      int64_t nodeh;
      char *key;
PREINIT:
      int64_t r;
   CODE:
      r = guestfs_hivex_node_get_value (g, nodeh, key);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));
      RETVAL = my_newSVll (r);
 OUTPUT:
      RETVAL

SV *
hivex_value_key (g, valueh)
      guestfs_h *g;
      int64_t valueh;
PREINIT:
      char *r;
   CODE:
      r = guestfs_hivex_value_key (g, valueh);
      if (r == NULL)
        croak ("%s", guestfs_last_error (g));
      RETVAL = newSVpv (r, 0);
      free (r);
 OUTPUT:
      RETVAL

SV *
hivex_value_type (g, valueh)
      guestfs_h *g;
      int64_t valueh;
PREINIT:
      int64_t r;
   CODE:
      r = guestfs_hivex_value_type (g, valueh);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));
      RETVAL = my_newSVll (r);
 OUTPUT:
      RETVAL

SV *
hivex_value_value (g, valueh)
      guestfs_h *g;
      int64_t valueh;
PREINIT:
      char *r;
      size_t size;
   CODE:
      r = guestfs_hivex_value_value (g, valueh, &size);
      if (r == NULL)
        croak ("%s", guestfs_last_error (g));
      RETVAL = newSVpvn (r, size);
      free (r);
 OUTPUT:
      RETVAL

void
hivex_commit (g, filename)
      guestfs_h *g;
      char *filename = SvOK(ST(1)) ? SvPV_nolen(ST(1)) : NULL;
PREINIT:
      int r;
 PPCODE:
      r = guestfs_hivex_commit (g, filename);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

SV *
hivex_node_add_child (g, parent, name)
      guestfs_h *g;
      int64_t parent;
      char *name;
PREINIT:
      int64_t r;
   CODE:
      r = guestfs_hivex_node_add_child (g, parent, name);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));
      RETVAL = my_newSVll (r);
 OUTPUT:
      RETVAL

void
hivex_node_delete_child (g, nodeh)
      guestfs_h *g;
      int64_t nodeh;
PREINIT:
      int r;
 PPCODE:
      r = guestfs_hivex_node_delete_child (g, nodeh);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

void
hivex_node_set_value (g, nodeh, key, t, val)
      guestfs_h *g;
      int64_t nodeh;
      char *key;
      int64_t t;
      char *val;
      size_t val_size = SvCUR (ST(4));
PREINIT:
      int r;
 PPCODE:
      r = guestfs_hivex_node_set_value (g, nodeh, key, t, val, val_size);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

SV *
xfs_repair (g, device, ...)
      guestfs_h *g;
      char *device;
PREINIT:
      int r;
      struct guestfs_xfs_repair_argv optargs_s = { .bitmask = 0 };
      struct guestfs_xfs_repair_argv *optargs = &optargs_s;
      size_t items_i;
   CODE:
      if (((items - 2) & 1) != 0)
        croak ("expecting an even number of extra parameters");
      for (items_i = 2; items_i < items; items_i += 2) {
        uint64_t this_mask;
        const char *this_arg;

        this_arg = SvPV_nolen (ST (items_i));
        if (STREQ (this_arg, "forcelogzero")) {
          optargs_s.forcelogzero = SvIV (ST (items_i+1));
          this_mask = GUESTFS_XFS_REPAIR_FORCELOGZERO_BITMASK;
        }
        else if (STREQ (this_arg, "nomodify")) {
          optargs_s.nomodify = SvIV (ST (items_i+1));
          this_mask = GUESTFS_XFS_REPAIR_NOMODIFY_BITMASK;
        }
        else if (STREQ (this_arg, "noprefetch")) {
          optargs_s.noprefetch = SvIV (ST (items_i+1));
          this_mask = GUESTFS_XFS_REPAIR_NOPREFETCH_BITMASK;
        }
        else if (STREQ (this_arg, "forcegeometry")) {
          optargs_s.forcegeometry = SvIV (ST (items_i+1));
          this_mask = GUESTFS_XFS_REPAIR_FORCEGEOMETRY_BITMASK;
        }
        else if (STREQ (this_arg, "maxmem")) {
          optargs_s.maxmem = my_SvIV64 (ST (items_i+1));
          this_mask = GUESTFS_XFS_REPAIR_MAXMEM_BITMASK;
        }
        else if (STREQ (this_arg, "ihashsize")) {
          optargs_s.ihashsize = my_SvIV64 (ST (items_i+1));
          this_mask = GUESTFS_XFS_REPAIR_IHASHSIZE_BITMASK;
        }
        else if (STREQ (this_arg, "bhashsize")) {
          optargs_s.bhashsize = my_SvIV64 (ST (items_i+1));
          this_mask = GUESTFS_XFS_REPAIR_BHASHSIZE_BITMASK;
        }
        else if (STREQ (this_arg, "agstride")) {
          optargs_s.agstride = my_SvIV64 (ST (items_i+1));
          this_mask = GUESTFS_XFS_REPAIR_AGSTRIDE_BITMASK;
        }
        else if (STREQ (this_arg, "logdev")) {
          optargs_s.logdev = SvPV_nolen (ST (items_i+1));
          this_mask = GUESTFS_XFS_REPAIR_LOGDEV_BITMASK;
        }
        else if (STREQ (this_arg, "rtdev")) {
          optargs_s.rtdev = SvPV_nolen (ST (items_i+1));
          this_mask = GUESTFS_XFS_REPAIR_RTDEV_BITMASK;
        }
        else croak ("unknown optional argument '%s'", this_arg);
        if (optargs_s.bitmask & this_mask)
          croak ("optional argument '%s' given twice",
                 this_arg);
        optargs_s.bitmask |= this_mask;
      }

      r = guestfs_xfs_repair_argv (g, device, optargs);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));
      RETVAL = newSViv (r);
 OUTPUT:
      RETVAL

void
rm_f (g, path)
      guestfs_h *g;
      char *path;
PREINIT:
      int r;
 PPCODE:
      r = guestfs_rm_f (g, path);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

void
mke2fs (g, device, ...)
      guestfs_h *g;
      char *device;
PREINIT:
      int r;
      struct guestfs_mke2fs_argv optargs_s = { .bitmask = 0 };
      struct guestfs_mke2fs_argv *optargs = &optargs_s;
      size_t items_i;
 PPCODE:
      if (((items - 2) & 1) != 0)
        croak ("expecting an even number of extra parameters");
      for (items_i = 2; items_i < items; items_i += 2) {
        uint64_t this_mask;
        const char *this_arg;

        this_arg = SvPV_nolen (ST (items_i));
        if (STREQ (this_arg, "blockscount")) {
          optargs_s.blockscount = my_SvIV64 (ST (items_i+1));
          this_mask = GUESTFS_MKE2FS_BLOCKSCOUNT_BITMASK;
        }
        else if (STREQ (this_arg, "blocksize")) {
          optargs_s.blocksize = my_SvIV64 (ST (items_i+1));
          this_mask = GUESTFS_MKE2FS_BLOCKSIZE_BITMASK;
        }
        else if (STREQ (this_arg, "fragsize")) {
          optargs_s.fragsize = my_SvIV64 (ST (items_i+1));
          this_mask = GUESTFS_MKE2FS_FRAGSIZE_BITMASK;
        }
        else if (STREQ (this_arg, "blockspergroup")) {
          optargs_s.blockspergroup = my_SvIV64 (ST (items_i+1));
          this_mask = GUESTFS_MKE2FS_BLOCKSPERGROUP_BITMASK;
        }
        else if (STREQ (this_arg, "numberofgroups")) {
          optargs_s.numberofgroups = my_SvIV64 (ST (items_i+1));
          this_mask = GUESTFS_MKE2FS_NUMBEROFGROUPS_BITMASK;
        }
        else if (STREQ (this_arg, "bytesperinode")) {
          optargs_s.bytesperinode = my_SvIV64 (ST (items_i+1));
          this_mask = GUESTFS_MKE2FS_BYTESPERINODE_BITMASK;
        }
        else if (STREQ (this_arg, "inodesize")) {
          optargs_s.inodesize = my_SvIV64 (ST (items_i+1));
          this_mask = GUESTFS_MKE2FS_INODESIZE_BITMASK;
        }
        else if (STREQ (this_arg, "journalsize")) {
          optargs_s.journalsize = my_SvIV64 (ST (items_i+1));
          this_mask = GUESTFS_MKE2FS_JOURNALSIZE_BITMASK;
        }
        else if (STREQ (this_arg, "numberofinodes")) {
          optargs_s.numberofinodes = my_SvIV64 (ST (items_i+1));
          this_mask = GUESTFS_MKE2FS_NUMBEROFINODES_BITMASK;
        }
        else if (STREQ (this_arg, "stridesize")) {
          optargs_s.stridesize = my_SvIV64 (ST (items_i+1));
          this_mask = GUESTFS_MKE2FS_STRIDESIZE_BITMASK;
        }
        else if (STREQ (this_arg, "stripewidth")) {
          optargs_s.stripewidth = my_SvIV64 (ST (items_i+1));
          this_mask = GUESTFS_MKE2FS_STRIPEWIDTH_BITMASK;
        }
        else if (STREQ (this_arg, "maxonlineresize")) {
          optargs_s.maxonlineresize = my_SvIV64 (ST (items_i+1));
          this_mask = GUESTFS_MKE2FS_MAXONLINERESIZE_BITMASK;
        }
        else if (STREQ (this_arg, "reservedblockspercentage")) {
          optargs_s.reservedblockspercentage = SvIV (ST (items_i+1));
          this_mask = GUESTFS_MKE2FS_RESERVEDBLOCKSPERCENTAGE_BITMASK;
        }
        else if (STREQ (this_arg, "mmpupdateinterval")) {
          optargs_s.mmpupdateinterval = SvIV (ST (items_i+1));
          this_mask = GUESTFS_MKE2FS_MMPUPDATEINTERVAL_BITMASK;
        }
        else if (STREQ (this_arg, "journaldevice")) {
          optargs_s.journaldevice = SvPV_nolen (ST (items_i+1));
          this_mask = GUESTFS_MKE2FS_JOURNALDEVICE_BITMASK;
        }
        else if (STREQ (this_arg, "label")) {
          optargs_s.label = SvPV_nolen (ST (items_i+1));
          this_mask = GUESTFS_MKE2FS_LABEL_BITMASK;
        }
        else if (STREQ (this_arg, "lastmounteddir")) {
          optargs_s.lastmounteddir = SvPV_nolen (ST (items_i+1));
          this_mask = GUESTFS_MKE2FS_LASTMOUNTEDDIR_BITMASK;
        }
        else if (STREQ (this_arg, "creatoros")) {
          optargs_s.creatoros = SvPV_nolen (ST (items_i+1));
          this_mask = GUESTFS_MKE2FS_CREATOROS_BITMASK;
        }
        else if (STREQ (this_arg, "fstype")) {
          optargs_s.fstype = SvPV_nolen (ST (items_i+1));
          this_mask = GUESTFS_MKE2FS_FSTYPE_BITMASK;
        }
        else if (STREQ (this_arg, "usagetype")) {
          optargs_s.usagetype = SvPV_nolen (ST (items_i+1));
          this_mask = GUESTFS_MKE2FS_USAGETYPE_BITMASK;
        }
        else if (STREQ (this_arg, "uuid")) {
          optargs_s.uuid = SvPV_nolen (ST (items_i+1));
          this_mask = GUESTFS_MKE2FS_UUID_BITMASK;
        }
        else if (STREQ (this_arg, "forcecreate")) {
          optargs_s.forcecreate = SvIV (ST (items_i+1));
          this_mask = GUESTFS_MKE2FS_FORCECREATE_BITMASK;
        }
        else if (STREQ (this_arg, "writesbandgrouponly")) {
          optargs_s.writesbandgrouponly = SvIV (ST (items_i+1));
          this_mask = GUESTFS_MKE2FS_WRITESBANDGROUPONLY_BITMASK;
        }
        else if (STREQ (this_arg, "lazyitableinit")) {
          optargs_s.lazyitableinit = SvIV (ST (items_i+1));
          this_mask = GUESTFS_MKE2FS_LAZYITABLEINIT_BITMASK;
        }
        else if (STREQ (this_arg, "lazyjournalinit")) {
          optargs_s.lazyjournalinit = SvIV (ST (items_i+1));
          this_mask = GUESTFS_MKE2FS_LAZYJOURNALINIT_BITMASK;
        }
        else if (STREQ (this_arg, "testfs")) {
          optargs_s.testfs = SvIV (ST (items_i+1));
          this_mask = GUESTFS_MKE2FS_TESTFS_BITMASK;
        }
        else if (STREQ (this_arg, "discard")) {
          optargs_s.discard = SvIV (ST (items_i+1));
          this_mask = GUESTFS_MKE2FS_DISCARD_BITMASK;
        }
        else if (STREQ (this_arg, "quotatype")) {
          optargs_s.quotatype = SvIV (ST (items_i+1));
          this_mask = GUESTFS_MKE2FS_QUOTATYPE_BITMASK;
        }
        else if (STREQ (this_arg, "extent")) {
          optargs_s.extent = SvIV (ST (items_i+1));
          this_mask = GUESTFS_MKE2FS_EXTENT_BITMASK;
        }
        else if (STREQ (this_arg, "filetype")) {
          optargs_s.filetype = SvIV (ST (items_i+1));
          this_mask = GUESTFS_MKE2FS_FILETYPE_BITMASK;
        }
        else if (STREQ (this_arg, "flexbg")) {
          optargs_s.flexbg = SvIV (ST (items_i+1));
          this_mask = GUESTFS_MKE2FS_FLEXBG_BITMASK;
        }
        else if (STREQ (this_arg, "hasjournal")) {
          optargs_s.hasjournal = SvIV (ST (items_i+1));
          this_mask = GUESTFS_MKE2FS_HASJOURNAL_BITMASK;
        }
        else if (STREQ (this_arg, "journaldev")) {
          optargs_s.journaldev = SvIV (ST (items_i+1));
          this_mask = GUESTFS_MKE2FS_JOURNALDEV_BITMASK;
        }
        else if (STREQ (this_arg, "largefile")) {
          optargs_s.largefile = SvIV (ST (items_i+1));
          this_mask = GUESTFS_MKE2FS_LARGEFILE_BITMASK;
        }
        else if (STREQ (this_arg, "quota")) {
          optargs_s.quota = SvIV (ST (items_i+1));
          this_mask = GUESTFS_MKE2FS_QUOTA_BITMASK;
        }
        else if (STREQ (this_arg, "resizeinode")) {
          optargs_s.resizeinode = SvIV (ST (items_i+1));
          this_mask = GUESTFS_MKE2FS_RESIZEINODE_BITMASK;
        }
        else if (STREQ (this_arg, "sparsesuper")) {
          optargs_s.sparsesuper = SvIV (ST (items_i+1));
          this_mask = GUESTFS_MKE2FS_SPARSESUPER_BITMASK;
        }
        else if (STREQ (this_arg, "uninitbg")) {
          optargs_s.uninitbg = SvIV (ST (items_i+1));
          this_mask = GUESTFS_MKE2FS_UNINITBG_BITMASK;
        }
        else croak ("unknown optional argument '%s'", this_arg);
        if (optargs_s.bitmask & this_mask)
          croak ("optional argument '%s' given twice",
                 this_arg);
        optargs_s.bitmask |= this_mask;
      }

      r = guestfs_mke2fs_argv (g, device, optargs);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

void
list_disk_labels (g)
      guestfs_h *g;
PREINIT:
      char **r;
      size_t i, n;
 PPCODE:
      r = guestfs_list_disk_labels (g);
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
mktemp (g, tmpl, ...)
      guestfs_h *g;
      char *tmpl;
PREINIT:
      char *r;
      struct guestfs_mktemp_argv optargs_s = { .bitmask = 0 };
      struct guestfs_mktemp_argv *optargs = &optargs_s;
      size_t items_i;
   CODE:
      if (((items - 2) & 1) != 0)
        croak ("expecting an even number of extra parameters");
      for (items_i = 2; items_i < items; items_i += 2) {
        uint64_t this_mask;
        const char *this_arg;

        this_arg = SvPV_nolen (ST (items_i));
        if (STREQ (this_arg, "suffix")) {
          optargs_s.suffix = SvPV_nolen (ST (items_i+1));
          this_mask = GUESTFS_MKTEMP_SUFFIX_BITMASK;
        }
        else croak ("unknown optional argument '%s'", this_arg);
        if (optargs_s.bitmask & this_mask)
          croak ("optional argument '%s' given twice",
                 this_arg);
        optargs_s.bitmask |= this_mask;
      }

      r = guestfs_mktemp_argv (g, tmpl, optargs);
      if (r == NULL)
        croak ("%s", guestfs_last_error (g));
      RETVAL = newSVpv (r, 0);
      free (r);
 OUTPUT:
      RETVAL

void
mklost_and_found (g, mountpoint)
      guestfs_h *g;
      char *mountpoint;
PREINIT:
      int r;
 PPCODE:
      r = guestfs_mklost_and_found (g, mountpoint);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

SV *
acl_get_file (g, path, acltype)
      guestfs_h *g;
      char *path;
      char *acltype;
PREINIT:
      char *r;
   CODE:
      r = guestfs_acl_get_file (g, path, acltype);
      if (r == NULL)
        croak ("%s", guestfs_last_error (g));
      RETVAL = newSVpv (r, 0);
      free (r);
 OUTPUT:
      RETVAL

void
acl_set_file (g, path, acltype, acl)
      guestfs_h *g;
      char *path;
      char *acltype;
      char *acl;
PREINIT:
      int r;
 PPCODE:
      r = guestfs_acl_set_file (g, path, acltype, acl);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

void
acl_delete_def_file (g, dir)
      guestfs_h *g;
      char *dir;
PREINIT:
      int r;
 PPCODE:
      r = guestfs_acl_delete_def_file (g, dir);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

SV *
cap_get_file (g, path)
      guestfs_h *g;
      char *path;
PREINIT:
      char *r;
   CODE:
      r = guestfs_cap_get_file (g, path);
      if (r == NULL)
        croak ("%s", guestfs_last_error (g));
      RETVAL = newSVpv (r, 0);
      free (r);
 OUTPUT:
      RETVAL

void
cap_set_file (g, path, cap)
      guestfs_h *g;
      char *path;
      char *cap;
PREINIT:
      int r;
 PPCODE:
      r = guestfs_cap_set_file (g, path, cap);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

void
list_ldm_volumes (g)
      guestfs_h *g;
PREINIT:
      char **r;
      size_t i, n;
 PPCODE:
      r = guestfs_list_ldm_volumes (g);
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
list_ldm_partitions (g)
      guestfs_h *g;
PREINIT:
      char **r;
      size_t i, n;
 PPCODE:
      r = guestfs_list_ldm_partitions (g);
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
ldmtool_create_all (g)
      guestfs_h *g;
PREINIT:
      int r;
 PPCODE:
      r = guestfs_ldmtool_create_all (g);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

void
ldmtool_remove_all (g)
      guestfs_h *g;
PREINIT:
      int r;
 PPCODE:
      r = guestfs_ldmtool_remove_all (g);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

void
ldmtool_scan (g)
      guestfs_h *g;
PREINIT:
      char **r;
      size_t i, n;
 PPCODE:
      r = guestfs_ldmtool_scan (g);
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
ldmtool_scan_devices (g, devices)
      guestfs_h *g;
      char **devices;
PREINIT:
      char **r;
      size_t i, n;
 PPCODE:
      r = guestfs_ldmtool_scan_devices (g, devices);
      free (devices);
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
ldmtool_diskgroup_name (g, diskgroup)
      guestfs_h *g;
      char *diskgroup;
PREINIT:
      char *r;
   CODE:
      r = guestfs_ldmtool_diskgroup_name (g, diskgroup);
      if (r == NULL)
        croak ("%s", guestfs_last_error (g));
      RETVAL = newSVpv (r, 0);
      free (r);
 OUTPUT:
      RETVAL

void
ldmtool_diskgroup_volumes (g, diskgroup)
      guestfs_h *g;
      char *diskgroup;
PREINIT:
      char **r;
      size_t i, n;
 PPCODE:
      r = guestfs_ldmtool_diskgroup_volumes (g, diskgroup);
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
ldmtool_diskgroup_disks (g, diskgroup)
      guestfs_h *g;
      char *diskgroup;
PREINIT:
      char **r;
      size_t i, n;
 PPCODE:
      r = guestfs_ldmtool_diskgroup_disks (g, diskgroup);
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
ldmtool_volume_type (g, diskgroup, volume)
      guestfs_h *g;
      char *diskgroup;
      char *volume;
PREINIT:
      char *r;
   CODE:
      r = guestfs_ldmtool_volume_type (g, diskgroup, volume);
      if (r == NULL)
        croak ("%s", guestfs_last_error (g));
      RETVAL = newSVpv (r, 0);
      free (r);
 OUTPUT:
      RETVAL

SV *
ldmtool_volume_hint (g, diskgroup, volume)
      guestfs_h *g;
      char *diskgroup;
      char *volume;
PREINIT:
      char *r;
   CODE:
      r = guestfs_ldmtool_volume_hint (g, diskgroup, volume);
      if (r == NULL)
        croak ("%s", guestfs_last_error (g));
      RETVAL = newSVpv (r, 0);
      free (r);
 OUTPUT:
      RETVAL

void
ldmtool_volume_partitions (g, diskgroup, volume)
      guestfs_h *g;
      char *diskgroup;
      char *volume;
PREINIT:
      char **r;
      size_t i, n;
 PPCODE:
      r = guestfs_ldmtool_volume_partitions (g, diskgroup, volume);
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
part_set_gpt_type (g, device, partnum, guid)
      guestfs_h *g;
      char *device;
      int partnum;
      char *guid;
PREINIT:
      int r;
 PPCODE:
      r = guestfs_part_set_gpt_type (g, device, partnum, guid);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

SV *
part_get_gpt_type (g, device, partnum)
      guestfs_h *g;
      char *device;
      int partnum;
PREINIT:
      char *r;
   CODE:
      r = guestfs_part_get_gpt_type (g, device, partnum);
      if (r == NULL)
        croak ("%s", guestfs_last_error (g));
      RETVAL = newSVpv (r, 0);
      free (r);
 OUTPUT:
      RETVAL

void
rename (g, oldpath, newpath)
      guestfs_h *g;
      char *oldpath;
      char *newpath;
PREINIT:
      int r;
 PPCODE:
      r = guestfs_rename (g, oldpath, newpath);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

SV *
is_whole_device (g, device)
      guestfs_h *g;
      char *device;
PREINIT:
      int r;
   CODE:
      r = guestfs_is_whole_device (g, device);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));
      RETVAL = newSViv (r);
 OUTPUT:
      RETVAL

SV *
feature_available (g, groups)
      guestfs_h *g;
      char **groups;
PREINIT:
      int r;
   CODE:
      r = guestfs_feature_available (g, groups);
      free (groups);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));
      RETVAL = newSViv (r);
 OUTPUT:
      RETVAL

void
syslinux (g, device, ...)
      guestfs_h *g;
      char *device;
PREINIT:
      int r;
      struct guestfs_syslinux_argv optargs_s = { .bitmask = 0 };
      struct guestfs_syslinux_argv *optargs = &optargs_s;
      size_t items_i;
 PPCODE:
      if (((items - 2) & 1) != 0)
        croak ("expecting an even number of extra parameters");
      for (items_i = 2; items_i < items; items_i += 2) {
        uint64_t this_mask;
        const char *this_arg;

        this_arg = SvPV_nolen (ST (items_i));
        if (STREQ (this_arg, "directory")) {
          optargs_s.directory = SvPV_nolen (ST (items_i+1));
          this_mask = GUESTFS_SYSLINUX_DIRECTORY_BITMASK;
        }
        else croak ("unknown optional argument '%s'", this_arg);
        if (optargs_s.bitmask & this_mask)
          croak ("optional argument '%s' given twice",
                 this_arg);
        optargs_s.bitmask |= this_mask;
      }

      r = guestfs_syslinux_argv (g, device, optargs);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

void
extlinux (g, directory)
      guestfs_h *g;
      char *directory;
PREINIT:
      int r;
 PPCODE:
      r = guestfs_extlinux (g, directory);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

void
cp_r (g, src, dest)
      guestfs_h *g;
      char *src;
      char *dest;
PREINIT:
      int r;
 PPCODE:
      r = guestfs_cp_r (g, src, dest);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

void
remount (g, mountpoint, ...)
      guestfs_h *g;
      char *mountpoint;
PREINIT:
      int r;
      struct guestfs_remount_argv optargs_s = { .bitmask = 0 };
      struct guestfs_remount_argv *optargs = &optargs_s;
      size_t items_i;
 PPCODE:
      if (((items - 2) & 1) != 0)
        croak ("expecting an even number of extra parameters");
      for (items_i = 2; items_i < items; items_i += 2) {
        uint64_t this_mask;
        const char *this_arg;

        this_arg = SvPV_nolen (ST (items_i));
        if (STREQ (this_arg, "rw")) {
          optargs_s.rw = SvIV (ST (items_i+1));
          this_mask = GUESTFS_REMOUNT_RW_BITMASK;
        }
        else croak ("unknown optional argument '%s'", this_arg);
        if (optargs_s.bitmask & this_mask)
          croak ("optional argument '%s' given twice",
                 this_arg);
        optargs_s.bitmask |= this_mask;
      }

      r = guestfs_remount_argv (g, mountpoint, optargs);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

void
set_uuid (g, device, uuid)
      guestfs_h *g;
      char *device;
      char *uuid;
PREINIT:
      int r;
 PPCODE:
      r = guestfs_set_uuid (g, device, uuid);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

void
journal_open (g, directory)
      guestfs_h *g;
      char *directory;
PREINIT:
      int r;
 PPCODE:
      r = guestfs_journal_open (g, directory);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

void
journal_close (g)
      guestfs_h *g;
PREINIT:
      int r;
 PPCODE:
      r = guestfs_journal_close (g);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

SV *
journal_next (g)
      guestfs_h *g;
PREINIT:
      int r;
   CODE:
      r = guestfs_journal_next (g);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));
      RETVAL = newSViv (r);
 OUTPUT:
      RETVAL

SV *
journal_skip (g, skip)
      guestfs_h *g;
      int64_t skip;
PREINIT:
      int64_t r;
   CODE:
      r = guestfs_journal_skip (g, skip);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));
      RETVAL = my_newSVll (r);
 OUTPUT:
      RETVAL

SV *
journal_get_data_threshold (g)
      guestfs_h *g;
PREINIT:
      int64_t r;
   CODE:
      r = guestfs_journal_get_data_threshold (g);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));
      RETVAL = my_newSVll (r);
 OUTPUT:
      RETVAL

void
journal_set_data_threshold (g, threshold)
      guestfs_h *g;
      int64_t threshold;
PREINIT:
      int r;
 PPCODE:
      r = guestfs_journal_set_data_threshold (g, threshold);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

SV *
aug_setm (g, base, sub, val)
      guestfs_h *g;
      char *base;
      char *sub = SvOK(ST(2)) ? SvPV_nolen(ST(2)) : NULL;
      char *val;
PREINIT:
      int r;
   CODE:
      r = guestfs_aug_setm (g, base, sub, val);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));
      RETVAL = newSViv (r);
 OUTPUT:
      RETVAL

SV *
aug_label (g, augpath)
      guestfs_h *g;
      char *augpath;
PREINIT:
      char *r;
   CODE:
      r = guestfs_aug_label (g, augpath);
      if (r == NULL)
        croak ("%s", guestfs_last_error (g));
      RETVAL = newSVpv (r, 0);
      free (r);
 OUTPUT:
      RETVAL

void
copy_attributes (g, src, dest, ...)
      guestfs_h *g;
      char *src;
      char *dest;
PREINIT:
      int r;
      struct guestfs_copy_attributes_argv optargs_s = { .bitmask = 0 };
      struct guestfs_copy_attributes_argv *optargs = &optargs_s;
      size_t items_i;
 PPCODE:
      if (((items - 3) & 1) != 0)
        croak ("expecting an even number of extra parameters");
      for (items_i = 3; items_i < items; items_i += 2) {
        uint64_t this_mask;
        const char *this_arg;

        this_arg = SvPV_nolen (ST (items_i));
        if (STREQ (this_arg, "all")) {
          optargs_s.all = SvIV (ST (items_i+1));
          this_mask = GUESTFS_COPY_ATTRIBUTES_ALL_BITMASK;
        }
        else if (STREQ (this_arg, "mode")) {
          optargs_s.mode = SvIV (ST (items_i+1));
          this_mask = GUESTFS_COPY_ATTRIBUTES_MODE_BITMASK;
        }
        else if (STREQ (this_arg, "xattributes")) {
          optargs_s.xattributes = SvIV (ST (items_i+1));
          this_mask = GUESTFS_COPY_ATTRIBUTES_XATTRIBUTES_BITMASK;
        }
        else if (STREQ (this_arg, "ownership")) {
          optargs_s.ownership = SvIV (ST (items_i+1));
          this_mask = GUESTFS_COPY_ATTRIBUTES_OWNERSHIP_BITMASK;
        }
        else croak ("unknown optional argument '%s'", this_arg);
        if (optargs_s.bitmask & this_mask)
          croak ("optional argument '%s' given twice",
                 this_arg);
        optargs_s.bitmask |= this_mask;
      }

      r = guestfs_copy_attributes_argv (g, src, dest, optargs);
      if (r == -1)
        croak ("%s", guestfs_last_error (g));

