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

#include <stdio.h>
#include <stdlib.h>

#include <ruby.h>

#include "guestfs.h"

#include "extconf.h"

/* For Ruby < 1.9 */
#ifndef RARRAY_LEN
#define RARRAY_LEN(r) (RARRAY((r))->len)
#endif

static VALUE m_guestfs;			/* guestfs module */
static VALUE c_guestfs;			/* guestfs_h handle */
static VALUE e_Error;			/* used for all errors */

static void ruby_guestfs_free (void *p)
{
  if (!p) return;
  guestfs_close ((guestfs_h *) p);
}

static VALUE ruby_guestfs_create (VALUE m)
{
  guestfs_h *g;

  g = guestfs_create ();
  if (!g)
    rb_raise (e_Error, "failed to create guestfs handle");

  /* Don't print error messages to stderr by default. */
  guestfs_set_error_handler (g, NULL, NULL);

  /* Wrap it, and make sure the close function is called when the
   * handle goes away.
   */
  return Data_Wrap_Struct (c_guestfs, NULL, ruby_guestfs_free, g);
}

static VALUE ruby_guestfs_close (VALUE gv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);

  ruby_guestfs_free (g);
  DATA_PTR (gv) = NULL;

  return Qnil;
}

static VALUE ruby_guestfs_test0 (VALUE gv, VALUE strv, VALUE optstrv, VALUE strlistv, VALUE bv, VALUE integerv, VALUE integer64v, VALUE fileinv, VALUE fileoutv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "test0");

  Check_Type (strv, T_STRING);
  const char *str = StringValueCStr (strv);
  if (!str)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "str", "test0");
  const char *optstr = !NIL_P (optstrv) ? StringValueCStr (optstrv) : NULL;
  char **strlist;
  Check_Type (strlistv, T_ARRAY);
  {
    int i, len;
    len = RARRAY_LEN (strlistv);
    strlist = guestfs_safe_malloc (g, sizeof (char *) * (len+1));
    for (i = 0; i < len; ++i) {
      VALUE v = rb_ary_entry (strlistv, i);
      strlist[i] = StringValueCStr (v);
    }
    strlist[len] = NULL;
  }
  int b = RTEST (bv);
  int integer = NUM2INT (integerv);
  long long integer64 = NUM2LL (integer64v);
  Check_Type (fileinv, T_STRING);
  const char *filein = StringValueCStr (fileinv);
  if (!filein)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "filein", "test0");
  Check_Type (fileoutv, T_STRING);
  const char *fileout = StringValueCStr (fileoutv);
  if (!fileout)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "fileout", "test0");

  int r;

  r = guestfs_test0 (g, str, optstr, strlist, b, integer, integer64, filein, fileout);
  free (strlist);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

static VALUE ruby_guestfs_test0rint (VALUE gv, VALUE valv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "test0rint");

  Check_Type (valv, T_STRING);
  const char *val = StringValueCStr (valv);
  if (!val)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "val", "test0rint");

  int r;

  r = guestfs_test0rint (g, val);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return INT2NUM (r);
}

static VALUE ruby_guestfs_test0rinterr (VALUE gv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "test0rinterr");


  int r;

  r = guestfs_test0rinterr (g);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return INT2NUM (r);
}

static VALUE ruby_guestfs_test0rint64 (VALUE gv, VALUE valv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "test0rint64");

  Check_Type (valv, T_STRING);
  const char *val = StringValueCStr (valv);
  if (!val)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "val", "test0rint64");

  int64_t r;

  r = guestfs_test0rint64 (g, val);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return ULL2NUM (r);
}

static VALUE ruby_guestfs_test0rint64err (VALUE gv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "test0rint64err");


  int64_t r;

  r = guestfs_test0rint64err (g);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return ULL2NUM (r);
}

static VALUE ruby_guestfs_test0rbool (VALUE gv, VALUE valv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "test0rbool");

  Check_Type (valv, T_STRING);
  const char *val = StringValueCStr (valv);
  if (!val)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "val", "test0rbool");

  int r;

  r = guestfs_test0rbool (g, val);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return INT2NUM (r);
}

static VALUE ruby_guestfs_test0rboolerr (VALUE gv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "test0rboolerr");


  int r;

  r = guestfs_test0rboolerr (g);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return INT2NUM (r);
}

static VALUE ruby_guestfs_test0rconststring (VALUE gv, VALUE valv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "test0rconststring");

  Check_Type (valv, T_STRING);
  const char *val = StringValueCStr (valv);
  if (!val)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "val", "test0rconststring");

  const char *r;

  r = guestfs_test0rconststring (g, val);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return rb_str_new2 (r);
}

static VALUE ruby_guestfs_test0rconststringerr (VALUE gv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "test0rconststringerr");


  const char *r;

  r = guestfs_test0rconststringerr (g);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return rb_str_new2 (r);
}

static VALUE ruby_guestfs_test0rconstoptstring (VALUE gv, VALUE valv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "test0rconstoptstring");

  Check_Type (valv, T_STRING);
  const char *val = StringValueCStr (valv);
  if (!val)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "val", "test0rconstoptstring");

  const char *r;

  r = guestfs_test0rconstoptstring (g, val);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  if (r)
    return rb_str_new2 (r);
  else
    return Qnil;
}

static VALUE ruby_guestfs_test0rconstoptstringerr (VALUE gv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "test0rconstoptstringerr");


  const char *r;

  r = guestfs_test0rconstoptstringerr (g);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  if (r)
    return rb_str_new2 (r);
  else
    return Qnil;
}

static VALUE ruby_guestfs_test0rstring (VALUE gv, VALUE valv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "test0rstring");

  Check_Type (valv, T_STRING);
  const char *val = StringValueCStr (valv);
  if (!val)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "val", "test0rstring");

  char *r;

  r = guestfs_test0rstring (g, val);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  VALUE rv = rb_str_new2 (r);
  free (r);
  return rv;
}

static VALUE ruby_guestfs_test0rstringerr (VALUE gv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "test0rstringerr");


  char *r;

  r = guestfs_test0rstringerr (g);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  VALUE rv = rb_str_new2 (r);
  free (r);
  return rv;
}

static VALUE ruby_guestfs_test0rstringlist (VALUE gv, VALUE valv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "test0rstringlist");

  Check_Type (valv, T_STRING);
  const char *val = StringValueCStr (valv);
  if (!val)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "val", "test0rstringlist");

  char **r;

  r = guestfs_test0rstringlist (g, val);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  int i, len = 0;
  for (i = 0; r[i] != NULL; ++i) len++;
  VALUE rv = rb_ary_new2 (len);
  for (i = 0; r[i] != NULL; ++i) {
    rb_ary_push (rv, rb_str_new2 (r[i]));
    free (r[i]);
  }
  free (r);
  return rv;
}

static VALUE ruby_guestfs_test0rstringlisterr (VALUE gv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "test0rstringlisterr");


  char **r;

  r = guestfs_test0rstringlisterr (g);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  int i, len = 0;
  for (i = 0; r[i] != NULL; ++i) len++;
  VALUE rv = rb_ary_new2 (len);
  for (i = 0; r[i] != NULL; ++i) {
    rb_ary_push (rv, rb_str_new2 (r[i]));
    free (r[i]);
  }
  free (r);
  return rv;
}

static VALUE ruby_guestfs_test0rstruct (VALUE gv, VALUE valv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "test0rstruct");

  Check_Type (valv, T_STRING);
  const char *val = StringValueCStr (valv);
  if (!val)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "val", "test0rstruct");

  struct guestfs_lvm_pv *r;

  r = guestfs_test0rstruct (g, val);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  VALUE rv = rb_hash_new ();
  rb_hash_aset (rv, rb_str_new2 ("pv_name"), rb_str_new2 (r->pv_name));
  rb_hash_aset (rv, rb_str_new2 ("pv_uuid"), rb_str_new (r->pv_uuid, 32));
  rb_hash_aset (rv, rb_str_new2 ("pv_fmt"), rb_str_new2 (r->pv_fmt));
  rb_hash_aset (rv, rb_str_new2 ("pv_size"), ULL2NUM (r->pv_size));
  rb_hash_aset (rv, rb_str_new2 ("dev_size"), ULL2NUM (r->dev_size));
  rb_hash_aset (rv, rb_str_new2 ("pv_free"), ULL2NUM (r->pv_free));
  rb_hash_aset (rv, rb_str_new2 ("pv_used"), ULL2NUM (r->pv_used));
  rb_hash_aset (rv, rb_str_new2 ("pv_attr"), rb_str_new2 (r->pv_attr));
  rb_hash_aset (rv, rb_str_new2 ("pv_pe_count"), LL2NUM (r->pv_pe_count));
  rb_hash_aset (rv, rb_str_new2 ("pv_pe_alloc_count"), LL2NUM (r->pv_pe_alloc_count));
  rb_hash_aset (rv, rb_str_new2 ("pv_tags"), rb_str_new2 (r->pv_tags));
  rb_hash_aset (rv, rb_str_new2 ("pe_start"), ULL2NUM (r->pe_start));
  rb_hash_aset (rv, rb_str_new2 ("pv_mda_count"), LL2NUM (r->pv_mda_count));
  rb_hash_aset (rv, rb_str_new2 ("pv_mda_free"), ULL2NUM (r->pv_mda_free));
  guestfs_free_lvm_pv (r);
  return rv;
}

static VALUE ruby_guestfs_test0rstructerr (VALUE gv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "test0rstructerr");


  struct guestfs_lvm_pv *r;

  r = guestfs_test0rstructerr (g);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  VALUE rv = rb_hash_new ();
  rb_hash_aset (rv, rb_str_new2 ("pv_name"), rb_str_new2 (r->pv_name));
  rb_hash_aset (rv, rb_str_new2 ("pv_uuid"), rb_str_new (r->pv_uuid, 32));
  rb_hash_aset (rv, rb_str_new2 ("pv_fmt"), rb_str_new2 (r->pv_fmt));
  rb_hash_aset (rv, rb_str_new2 ("pv_size"), ULL2NUM (r->pv_size));
  rb_hash_aset (rv, rb_str_new2 ("dev_size"), ULL2NUM (r->dev_size));
  rb_hash_aset (rv, rb_str_new2 ("pv_free"), ULL2NUM (r->pv_free));
  rb_hash_aset (rv, rb_str_new2 ("pv_used"), ULL2NUM (r->pv_used));
  rb_hash_aset (rv, rb_str_new2 ("pv_attr"), rb_str_new2 (r->pv_attr));
  rb_hash_aset (rv, rb_str_new2 ("pv_pe_count"), LL2NUM (r->pv_pe_count));
  rb_hash_aset (rv, rb_str_new2 ("pv_pe_alloc_count"), LL2NUM (r->pv_pe_alloc_count));
  rb_hash_aset (rv, rb_str_new2 ("pv_tags"), rb_str_new2 (r->pv_tags));
  rb_hash_aset (rv, rb_str_new2 ("pe_start"), ULL2NUM (r->pe_start));
  rb_hash_aset (rv, rb_str_new2 ("pv_mda_count"), LL2NUM (r->pv_mda_count));
  rb_hash_aset (rv, rb_str_new2 ("pv_mda_free"), ULL2NUM (r->pv_mda_free));
  guestfs_free_lvm_pv (r);
  return rv;
}

static VALUE ruby_guestfs_test0rstructlist (VALUE gv, VALUE valv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "test0rstructlist");

  Check_Type (valv, T_STRING);
  const char *val = StringValueCStr (valv);
  if (!val)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "val", "test0rstructlist");

  struct guestfs_lvm_pv_list *r;

  r = guestfs_test0rstructlist (g, val);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  VALUE rv = rb_ary_new2 (r->len);
  int i;
  for (i = 0; i < r->len; ++i) {
    VALUE hv = rb_hash_new ();
    rb_hash_aset (hv, rb_str_new2 ("pv_name"), rb_str_new2 (r->val[i].pv_name));
    rb_hash_aset (hv, rb_str_new2 ("pv_uuid"), rb_str_new (r->val[i].pv_uuid, 32));
    rb_hash_aset (hv, rb_str_new2 ("pv_fmt"), rb_str_new2 (r->val[i].pv_fmt));
    rb_hash_aset (hv, rb_str_new2 ("pv_size"), ULL2NUM (r->val[i].pv_size));
    rb_hash_aset (hv, rb_str_new2 ("dev_size"), ULL2NUM (r->val[i].dev_size));
    rb_hash_aset (hv, rb_str_new2 ("pv_free"), ULL2NUM (r->val[i].pv_free));
    rb_hash_aset (hv, rb_str_new2 ("pv_used"), ULL2NUM (r->val[i].pv_used));
    rb_hash_aset (hv, rb_str_new2 ("pv_attr"), rb_str_new2 (r->val[i].pv_attr));
    rb_hash_aset (hv, rb_str_new2 ("pv_pe_count"), LL2NUM (r->val[i].pv_pe_count));
    rb_hash_aset (hv, rb_str_new2 ("pv_pe_alloc_count"), LL2NUM (r->val[i].pv_pe_alloc_count));
    rb_hash_aset (hv, rb_str_new2 ("pv_tags"), rb_str_new2 (r->val[i].pv_tags));
    rb_hash_aset (hv, rb_str_new2 ("pe_start"), ULL2NUM (r->val[i].pe_start));
    rb_hash_aset (hv, rb_str_new2 ("pv_mda_count"), LL2NUM (r->val[i].pv_mda_count));
    rb_hash_aset (hv, rb_str_new2 ("pv_mda_free"), ULL2NUM (r->val[i].pv_mda_free));
    rb_ary_push (rv, hv);
  }
  guestfs_free_lvm_pv_list (r);
  return rv;
}

static VALUE ruby_guestfs_test0rstructlisterr (VALUE gv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "test0rstructlisterr");


  struct guestfs_lvm_pv_list *r;

  r = guestfs_test0rstructlisterr (g);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  VALUE rv = rb_ary_new2 (r->len);
  int i;
  for (i = 0; i < r->len; ++i) {
    VALUE hv = rb_hash_new ();
    rb_hash_aset (hv, rb_str_new2 ("pv_name"), rb_str_new2 (r->val[i].pv_name));
    rb_hash_aset (hv, rb_str_new2 ("pv_uuid"), rb_str_new (r->val[i].pv_uuid, 32));
    rb_hash_aset (hv, rb_str_new2 ("pv_fmt"), rb_str_new2 (r->val[i].pv_fmt));
    rb_hash_aset (hv, rb_str_new2 ("pv_size"), ULL2NUM (r->val[i].pv_size));
    rb_hash_aset (hv, rb_str_new2 ("dev_size"), ULL2NUM (r->val[i].dev_size));
    rb_hash_aset (hv, rb_str_new2 ("pv_free"), ULL2NUM (r->val[i].pv_free));
    rb_hash_aset (hv, rb_str_new2 ("pv_used"), ULL2NUM (r->val[i].pv_used));
    rb_hash_aset (hv, rb_str_new2 ("pv_attr"), rb_str_new2 (r->val[i].pv_attr));
    rb_hash_aset (hv, rb_str_new2 ("pv_pe_count"), LL2NUM (r->val[i].pv_pe_count));
    rb_hash_aset (hv, rb_str_new2 ("pv_pe_alloc_count"), LL2NUM (r->val[i].pv_pe_alloc_count));
    rb_hash_aset (hv, rb_str_new2 ("pv_tags"), rb_str_new2 (r->val[i].pv_tags));
    rb_hash_aset (hv, rb_str_new2 ("pe_start"), ULL2NUM (r->val[i].pe_start));
    rb_hash_aset (hv, rb_str_new2 ("pv_mda_count"), LL2NUM (r->val[i].pv_mda_count));
    rb_hash_aset (hv, rb_str_new2 ("pv_mda_free"), ULL2NUM (r->val[i].pv_mda_free));
    rb_ary_push (rv, hv);
  }
  guestfs_free_lvm_pv_list (r);
  return rv;
}

static VALUE ruby_guestfs_test0rhashtable (VALUE gv, VALUE valv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "test0rhashtable");

  Check_Type (valv, T_STRING);
  const char *val = StringValueCStr (valv);
  if (!val)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "val", "test0rhashtable");

  char **r;

  r = guestfs_test0rhashtable (g, val);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  VALUE rv = rb_hash_new ();
  int i;
  for (i = 0; r[i] != NULL; i+=2) {
    rb_hash_aset (rv, rb_str_new2 (r[i]), rb_str_new2 (r[i+1]));
    free (r[i]);
    free (r[i+1]);
  }
  free (r);
  return rv;
}

static VALUE ruby_guestfs_test0rhashtableerr (VALUE gv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "test0rhashtableerr");


  char **r;

  r = guestfs_test0rhashtableerr (g);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  VALUE rv = rb_hash_new ();
  int i;
  for (i = 0; r[i] != NULL; i+=2) {
    rb_hash_aset (rv, rb_str_new2 (r[i]), rb_str_new2 (r[i+1]));
    free (r[i]);
    free (r[i+1]);
  }
  free (r);
  return rv;
}

static VALUE ruby_guestfs_launch (VALUE gv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "launch");


  int r;

  r = guestfs_launch (g);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

static VALUE ruby_guestfs_wait_ready (VALUE gv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "wait_ready");


  int r;

  r = guestfs_wait_ready (g);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

static VALUE ruby_guestfs_kill_subprocess (VALUE gv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "kill_subprocess");


  int r;

  r = guestfs_kill_subprocess (g);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

static VALUE ruby_guestfs_add_drive (VALUE gv, VALUE filenamev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "add_drive");

  Check_Type (filenamev, T_STRING);
  const char *filename = StringValueCStr (filenamev);
  if (!filename)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "filename", "add_drive");

  int r;

  r = guestfs_add_drive (g, filename);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

static VALUE ruby_guestfs_add_cdrom (VALUE gv, VALUE filenamev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "add_cdrom");

  Check_Type (filenamev, T_STRING);
  const char *filename = StringValueCStr (filenamev);
  if (!filename)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "filename", "add_cdrom");

  int r;

  r = guestfs_add_cdrom (g, filename);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

static VALUE ruby_guestfs_add_drive_ro (VALUE gv, VALUE filenamev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "add_drive_ro");

  Check_Type (filenamev, T_STRING);
  const char *filename = StringValueCStr (filenamev);
  if (!filename)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "filename", "add_drive_ro");

  int r;

  r = guestfs_add_drive_ro (g, filename);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

static VALUE ruby_guestfs_config (VALUE gv, VALUE qemuparamv, VALUE qemuvaluev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "config");

  Check_Type (qemuparamv, T_STRING);
  const char *qemuparam = StringValueCStr (qemuparamv);
  if (!qemuparam)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "qemuparam", "config");
  const char *qemuvalue = !NIL_P (qemuvaluev) ? StringValueCStr (qemuvaluev) : NULL;

  int r;

  r = guestfs_config (g, qemuparam, qemuvalue);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

static VALUE ruby_guestfs_set_qemu (VALUE gv, VALUE qemuv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "set_qemu");

  Check_Type (qemuv, T_STRING);
  const char *qemu = StringValueCStr (qemuv);
  if (!qemu)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "qemu", "set_qemu");

  int r;

  r = guestfs_set_qemu (g, qemu);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

static VALUE ruby_guestfs_get_qemu (VALUE gv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "get_qemu");


  const char *r;

  r = guestfs_get_qemu (g);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return rb_str_new2 (r);
}

static VALUE ruby_guestfs_set_path (VALUE gv, VALUE searchpathv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "set_path");

  Check_Type (searchpathv, T_STRING);
  const char *searchpath = StringValueCStr (searchpathv);
  if (!searchpath)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "searchpath", "set_path");

  int r;

  r = guestfs_set_path (g, searchpath);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

static VALUE ruby_guestfs_get_path (VALUE gv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "get_path");


  const char *r;

  r = guestfs_get_path (g);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return rb_str_new2 (r);
}

static VALUE ruby_guestfs_set_append (VALUE gv, VALUE appendv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "set_append");

  const char *append = !NIL_P (appendv) ? StringValueCStr (appendv) : NULL;

  int r;

  r = guestfs_set_append (g, append);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

static VALUE ruby_guestfs_get_append (VALUE gv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "get_append");


  const char *r;

  r = guestfs_get_append (g);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  if (r)
    return rb_str_new2 (r);
  else
    return Qnil;
}

static VALUE ruby_guestfs_set_autosync (VALUE gv, VALUE autosyncv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "set_autosync");

  int autosync = RTEST (autosyncv);

  int r;

  r = guestfs_set_autosync (g, autosync);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

static VALUE ruby_guestfs_get_autosync (VALUE gv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "get_autosync");


  int r;

  r = guestfs_get_autosync (g);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return INT2NUM (r);
}

static VALUE ruby_guestfs_set_verbose (VALUE gv, VALUE verbosev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "set_verbose");

  int verbose = RTEST (verbosev);

  int r;

  r = guestfs_set_verbose (g, verbose);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

static VALUE ruby_guestfs_get_verbose (VALUE gv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "get_verbose");


  int r;

  r = guestfs_get_verbose (g);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return INT2NUM (r);
}

static VALUE ruby_guestfs_is_ready (VALUE gv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "is_ready");


  int r;

  r = guestfs_is_ready (g);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return INT2NUM (r);
}

static VALUE ruby_guestfs_is_config (VALUE gv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "is_config");


  int r;

  r = guestfs_is_config (g);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return INT2NUM (r);
}

static VALUE ruby_guestfs_is_launching (VALUE gv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "is_launching");


  int r;

  r = guestfs_is_launching (g);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return INT2NUM (r);
}

static VALUE ruby_guestfs_is_busy (VALUE gv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "is_busy");


  int r;

  r = guestfs_is_busy (g);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return INT2NUM (r);
}

static VALUE ruby_guestfs_get_state (VALUE gv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "get_state");


  int r;

  r = guestfs_get_state (g);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return INT2NUM (r);
}

static VALUE ruby_guestfs_set_memsize (VALUE gv, VALUE memsizev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "set_memsize");

  int memsize = NUM2INT (memsizev);

  int r;

  r = guestfs_set_memsize (g, memsize);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

static VALUE ruby_guestfs_get_memsize (VALUE gv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "get_memsize");


  int r;

  r = guestfs_get_memsize (g);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return INT2NUM (r);
}

static VALUE ruby_guestfs_get_pid (VALUE gv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "get_pid");


  int r;

  r = guestfs_get_pid (g);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return INT2NUM (r);
}

static VALUE ruby_guestfs_version (VALUE gv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "version");


  struct guestfs_version *r;

  r = guestfs_version (g);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  VALUE rv = rb_hash_new ();
  rb_hash_aset (rv, rb_str_new2 ("major"), LL2NUM (r->major));
  rb_hash_aset (rv, rb_str_new2 ("minor"), LL2NUM (r->minor));
  rb_hash_aset (rv, rb_str_new2 ("release"), LL2NUM (r->release));
  rb_hash_aset (rv, rb_str_new2 ("extra"), rb_str_new2 (r->extra));
  guestfs_free_version (r);
  return rv;
}

static VALUE ruby_guestfs_set_selinux (VALUE gv, VALUE selinuxv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "set_selinux");

  int selinux = RTEST (selinuxv);

  int r;

  r = guestfs_set_selinux (g, selinux);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

static VALUE ruby_guestfs_get_selinux (VALUE gv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "get_selinux");


  int r;

  r = guestfs_get_selinux (g);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return INT2NUM (r);
}

static VALUE ruby_guestfs_set_trace (VALUE gv, VALUE tracev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "set_trace");

  int trace = RTEST (tracev);

  int r;

  r = guestfs_set_trace (g, trace);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

static VALUE ruby_guestfs_get_trace (VALUE gv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "get_trace");


  int r;

  r = guestfs_get_trace (g);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return INT2NUM (r);
}

static VALUE ruby_guestfs_set_direct (VALUE gv, VALUE directv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "set_direct");

  int direct = RTEST (directv);

  int r;

  r = guestfs_set_direct (g, direct);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

static VALUE ruby_guestfs_get_direct (VALUE gv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "get_direct");


  int r;

  r = guestfs_get_direct (g);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return INT2NUM (r);
}

static VALUE ruby_guestfs_set_recovery_proc (VALUE gv, VALUE recoveryprocv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "set_recovery_proc");

  int recoveryproc = RTEST (recoveryprocv);

  int r;

  r = guestfs_set_recovery_proc (g, recoveryproc);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

static VALUE ruby_guestfs_get_recovery_proc (VALUE gv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "get_recovery_proc");


  int r;

  r = guestfs_get_recovery_proc (g);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return INT2NUM (r);
}

static VALUE ruby_guestfs_add_drive_with_if (VALUE gv, VALUE filenamev, VALUE ifacev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "add_drive_with_if");

  Check_Type (filenamev, T_STRING);
  const char *filename = StringValueCStr (filenamev);
  if (!filename)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "filename", "add_drive_with_if");
  Check_Type (ifacev, T_STRING);
  const char *iface = StringValueCStr (ifacev);
  if (!iface)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "iface", "add_drive_with_if");

  int r;

  r = guestfs_add_drive_with_if (g, filename, iface);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

static VALUE ruby_guestfs_add_drive_ro_with_if (VALUE gv, VALUE filenamev, VALUE ifacev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "add_drive_ro_with_if");

  Check_Type (filenamev, T_STRING);
  const char *filename = StringValueCStr (filenamev);
  if (!filename)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "filename", "add_drive_ro_with_if");
  Check_Type (ifacev, T_STRING);
  const char *iface = StringValueCStr (ifacev);
  if (!iface)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "iface", "add_drive_ro_with_if");

  int r;

  r = guestfs_add_drive_ro_with_if (g, filename, iface);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

static VALUE ruby_guestfs_mount (VALUE gv, VALUE devicev, VALUE mountpointv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "mount");

  Check_Type (devicev, T_STRING);
  const char *device = StringValueCStr (devicev);
  if (!device)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "device", "mount");
  Check_Type (mountpointv, T_STRING);
  const char *mountpoint = StringValueCStr (mountpointv);
  if (!mountpoint)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "mountpoint", "mount");

  int r;

  r = guestfs_mount (g, device, mountpoint);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

static VALUE ruby_guestfs_sync (VALUE gv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "sync");


  int r;

  r = guestfs_sync (g);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

static VALUE ruby_guestfs_touch (VALUE gv, VALUE pathv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "touch");

  Check_Type (pathv, T_STRING);
  const char *path = StringValueCStr (pathv);
  if (!path)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "path", "touch");

  int r;

  r = guestfs_touch (g, path);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

static VALUE ruby_guestfs_cat (VALUE gv, VALUE pathv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "cat");

  Check_Type (pathv, T_STRING);
  const char *path = StringValueCStr (pathv);
  if (!path)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "path", "cat");

  char *r;

  r = guestfs_cat (g, path);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  VALUE rv = rb_str_new2 (r);
  free (r);
  return rv;
}

static VALUE ruby_guestfs_ll (VALUE gv, VALUE directoryv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "ll");

  Check_Type (directoryv, T_STRING);
  const char *directory = StringValueCStr (directoryv);
  if (!directory)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "directory", "ll");

  char *r;

  r = guestfs_ll (g, directory);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  VALUE rv = rb_str_new2 (r);
  free (r);
  return rv;
}

static VALUE ruby_guestfs_ls (VALUE gv, VALUE directoryv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "ls");

  Check_Type (directoryv, T_STRING);
  const char *directory = StringValueCStr (directoryv);
  if (!directory)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "directory", "ls");

  char **r;

  r = guestfs_ls (g, directory);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  int i, len = 0;
  for (i = 0; r[i] != NULL; ++i) len++;
  VALUE rv = rb_ary_new2 (len);
  for (i = 0; r[i] != NULL; ++i) {
    rb_ary_push (rv, rb_str_new2 (r[i]));
    free (r[i]);
  }
  free (r);
  return rv;
}

static VALUE ruby_guestfs_list_devices (VALUE gv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "list_devices");


  char **r;

  r = guestfs_list_devices (g);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  int i, len = 0;
  for (i = 0; r[i] != NULL; ++i) len++;
  VALUE rv = rb_ary_new2 (len);
  for (i = 0; r[i] != NULL; ++i) {
    rb_ary_push (rv, rb_str_new2 (r[i]));
    free (r[i]);
  }
  free (r);
  return rv;
}

static VALUE ruby_guestfs_list_partitions (VALUE gv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "list_partitions");


  char **r;

  r = guestfs_list_partitions (g);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  int i, len = 0;
  for (i = 0; r[i] != NULL; ++i) len++;
  VALUE rv = rb_ary_new2 (len);
  for (i = 0; r[i] != NULL; ++i) {
    rb_ary_push (rv, rb_str_new2 (r[i]));
    free (r[i]);
  }
  free (r);
  return rv;
}

static VALUE ruby_guestfs_pvs (VALUE gv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "pvs");


  char **r;

  r = guestfs_pvs (g);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  int i, len = 0;
  for (i = 0; r[i] != NULL; ++i) len++;
  VALUE rv = rb_ary_new2 (len);
  for (i = 0; r[i] != NULL; ++i) {
    rb_ary_push (rv, rb_str_new2 (r[i]));
    free (r[i]);
  }
  free (r);
  return rv;
}

static VALUE ruby_guestfs_vgs (VALUE gv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "vgs");


  char **r;

  r = guestfs_vgs (g);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  int i, len = 0;
  for (i = 0; r[i] != NULL; ++i) len++;
  VALUE rv = rb_ary_new2 (len);
  for (i = 0; r[i] != NULL; ++i) {
    rb_ary_push (rv, rb_str_new2 (r[i]));
    free (r[i]);
  }
  free (r);
  return rv;
}

static VALUE ruby_guestfs_lvs (VALUE gv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "lvs");


  char **r;

  r = guestfs_lvs (g);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  int i, len = 0;
  for (i = 0; r[i] != NULL; ++i) len++;
  VALUE rv = rb_ary_new2 (len);
  for (i = 0; r[i] != NULL; ++i) {
    rb_ary_push (rv, rb_str_new2 (r[i]));
    free (r[i]);
  }
  free (r);
  return rv;
}

static VALUE ruby_guestfs_pvs_full (VALUE gv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "pvs_full");


  struct guestfs_lvm_pv_list *r;

  r = guestfs_pvs_full (g);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  VALUE rv = rb_ary_new2 (r->len);
  int i;
  for (i = 0; i < r->len; ++i) {
    VALUE hv = rb_hash_new ();
    rb_hash_aset (hv, rb_str_new2 ("pv_name"), rb_str_new2 (r->val[i].pv_name));
    rb_hash_aset (hv, rb_str_new2 ("pv_uuid"), rb_str_new (r->val[i].pv_uuid, 32));
    rb_hash_aset (hv, rb_str_new2 ("pv_fmt"), rb_str_new2 (r->val[i].pv_fmt));
    rb_hash_aset (hv, rb_str_new2 ("pv_size"), ULL2NUM (r->val[i].pv_size));
    rb_hash_aset (hv, rb_str_new2 ("dev_size"), ULL2NUM (r->val[i].dev_size));
    rb_hash_aset (hv, rb_str_new2 ("pv_free"), ULL2NUM (r->val[i].pv_free));
    rb_hash_aset (hv, rb_str_new2 ("pv_used"), ULL2NUM (r->val[i].pv_used));
    rb_hash_aset (hv, rb_str_new2 ("pv_attr"), rb_str_new2 (r->val[i].pv_attr));
    rb_hash_aset (hv, rb_str_new2 ("pv_pe_count"), LL2NUM (r->val[i].pv_pe_count));
    rb_hash_aset (hv, rb_str_new2 ("pv_pe_alloc_count"), LL2NUM (r->val[i].pv_pe_alloc_count));
    rb_hash_aset (hv, rb_str_new2 ("pv_tags"), rb_str_new2 (r->val[i].pv_tags));
    rb_hash_aset (hv, rb_str_new2 ("pe_start"), ULL2NUM (r->val[i].pe_start));
    rb_hash_aset (hv, rb_str_new2 ("pv_mda_count"), LL2NUM (r->val[i].pv_mda_count));
    rb_hash_aset (hv, rb_str_new2 ("pv_mda_free"), ULL2NUM (r->val[i].pv_mda_free));
    rb_ary_push (rv, hv);
  }
  guestfs_free_lvm_pv_list (r);
  return rv;
}

static VALUE ruby_guestfs_vgs_full (VALUE gv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "vgs_full");


  struct guestfs_lvm_vg_list *r;

  r = guestfs_vgs_full (g);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  VALUE rv = rb_ary_new2 (r->len);
  int i;
  for (i = 0; i < r->len; ++i) {
    VALUE hv = rb_hash_new ();
    rb_hash_aset (hv, rb_str_new2 ("vg_name"), rb_str_new2 (r->val[i].vg_name));
    rb_hash_aset (hv, rb_str_new2 ("vg_uuid"), rb_str_new (r->val[i].vg_uuid, 32));
    rb_hash_aset (hv, rb_str_new2 ("vg_fmt"), rb_str_new2 (r->val[i].vg_fmt));
    rb_hash_aset (hv, rb_str_new2 ("vg_attr"), rb_str_new2 (r->val[i].vg_attr));
    rb_hash_aset (hv, rb_str_new2 ("vg_size"), ULL2NUM (r->val[i].vg_size));
    rb_hash_aset (hv, rb_str_new2 ("vg_free"), ULL2NUM (r->val[i].vg_free));
    rb_hash_aset (hv, rb_str_new2 ("vg_sysid"), rb_str_new2 (r->val[i].vg_sysid));
    rb_hash_aset (hv, rb_str_new2 ("vg_extent_size"), ULL2NUM (r->val[i].vg_extent_size));
    rb_hash_aset (hv, rb_str_new2 ("vg_extent_count"), LL2NUM (r->val[i].vg_extent_count));
    rb_hash_aset (hv, rb_str_new2 ("vg_free_count"), LL2NUM (r->val[i].vg_free_count));
    rb_hash_aset (hv, rb_str_new2 ("max_lv"), LL2NUM (r->val[i].max_lv));
    rb_hash_aset (hv, rb_str_new2 ("max_pv"), LL2NUM (r->val[i].max_pv));
    rb_hash_aset (hv, rb_str_new2 ("pv_count"), LL2NUM (r->val[i].pv_count));
    rb_hash_aset (hv, rb_str_new2 ("lv_count"), LL2NUM (r->val[i].lv_count));
    rb_hash_aset (hv, rb_str_new2 ("snap_count"), LL2NUM (r->val[i].snap_count));
    rb_hash_aset (hv, rb_str_new2 ("vg_seqno"), LL2NUM (r->val[i].vg_seqno));
    rb_hash_aset (hv, rb_str_new2 ("vg_tags"), rb_str_new2 (r->val[i].vg_tags));
    rb_hash_aset (hv, rb_str_new2 ("vg_mda_count"), LL2NUM (r->val[i].vg_mda_count));
    rb_hash_aset (hv, rb_str_new2 ("vg_mda_free"), ULL2NUM (r->val[i].vg_mda_free));
    rb_ary_push (rv, hv);
  }
  guestfs_free_lvm_vg_list (r);
  return rv;
}

static VALUE ruby_guestfs_lvs_full (VALUE gv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "lvs_full");


  struct guestfs_lvm_lv_list *r;

  r = guestfs_lvs_full (g);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  VALUE rv = rb_ary_new2 (r->len);
  int i;
  for (i = 0; i < r->len; ++i) {
    VALUE hv = rb_hash_new ();
    rb_hash_aset (hv, rb_str_new2 ("lv_name"), rb_str_new2 (r->val[i].lv_name));
    rb_hash_aset (hv, rb_str_new2 ("lv_uuid"), rb_str_new (r->val[i].lv_uuid, 32));
    rb_hash_aset (hv, rb_str_new2 ("lv_attr"), rb_str_new2 (r->val[i].lv_attr));
    rb_hash_aset (hv, rb_str_new2 ("lv_major"), LL2NUM (r->val[i].lv_major));
    rb_hash_aset (hv, rb_str_new2 ("lv_minor"), LL2NUM (r->val[i].lv_minor));
    rb_hash_aset (hv, rb_str_new2 ("lv_kernel_major"), LL2NUM (r->val[i].lv_kernel_major));
    rb_hash_aset (hv, rb_str_new2 ("lv_kernel_minor"), LL2NUM (r->val[i].lv_kernel_minor));
    rb_hash_aset (hv, rb_str_new2 ("lv_size"), ULL2NUM (r->val[i].lv_size));
    rb_hash_aset (hv, rb_str_new2 ("seg_count"), LL2NUM (r->val[i].seg_count));
    rb_hash_aset (hv, rb_str_new2 ("origin"), rb_str_new2 (r->val[i].origin));
    rb_hash_aset (hv, rb_str_new2 ("snap_percent"), rb_dbl2big (r->val[i].snap_percent));
    rb_hash_aset (hv, rb_str_new2 ("copy_percent"), rb_dbl2big (r->val[i].copy_percent));
    rb_hash_aset (hv, rb_str_new2 ("move_pv"), rb_str_new2 (r->val[i].move_pv));
    rb_hash_aset (hv, rb_str_new2 ("lv_tags"), rb_str_new2 (r->val[i].lv_tags));
    rb_hash_aset (hv, rb_str_new2 ("mirror_log"), rb_str_new2 (r->val[i].mirror_log));
    rb_hash_aset (hv, rb_str_new2 ("modules"), rb_str_new2 (r->val[i].modules));
    rb_ary_push (rv, hv);
  }
  guestfs_free_lvm_lv_list (r);
  return rv;
}

static VALUE ruby_guestfs_read_lines (VALUE gv, VALUE pathv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "read_lines");

  Check_Type (pathv, T_STRING);
  const char *path = StringValueCStr (pathv);
  if (!path)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "path", "read_lines");

  char **r;

  r = guestfs_read_lines (g, path);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  int i, len = 0;
  for (i = 0; r[i] != NULL; ++i) len++;
  VALUE rv = rb_ary_new2 (len);
  for (i = 0; r[i] != NULL; ++i) {
    rb_ary_push (rv, rb_str_new2 (r[i]));
    free (r[i]);
  }
  free (r);
  return rv;
}

static VALUE ruby_guestfs_aug_init (VALUE gv, VALUE rootv, VALUE flagsv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "aug_init");

  Check_Type (rootv, T_STRING);
  const char *root = StringValueCStr (rootv);
  if (!root)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "root", "aug_init");
  int flags = NUM2INT (flagsv);

  int r;

  r = guestfs_aug_init (g, root, flags);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

static VALUE ruby_guestfs_aug_close (VALUE gv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "aug_close");


  int r;

  r = guestfs_aug_close (g);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

static VALUE ruby_guestfs_aug_defvar (VALUE gv, VALUE namev, VALUE exprv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "aug_defvar");

  Check_Type (namev, T_STRING);
  const char *name = StringValueCStr (namev);
  if (!name)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "name", "aug_defvar");
  const char *expr = !NIL_P (exprv) ? StringValueCStr (exprv) : NULL;

  int r;

  r = guestfs_aug_defvar (g, name, expr);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return INT2NUM (r);
}

static VALUE ruby_guestfs_aug_defnode (VALUE gv, VALUE namev, VALUE exprv, VALUE valv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "aug_defnode");

  Check_Type (namev, T_STRING);
  const char *name = StringValueCStr (namev);
  if (!name)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "name", "aug_defnode");
  Check_Type (exprv, T_STRING);
  const char *expr = StringValueCStr (exprv);
  if (!expr)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "expr", "aug_defnode");
  Check_Type (valv, T_STRING);
  const char *val = StringValueCStr (valv);
  if (!val)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "val", "aug_defnode");

  struct guestfs_int_bool *r;

  r = guestfs_aug_defnode (g, name, expr, val);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  VALUE rv = rb_hash_new ();
  rb_hash_aset (rv, rb_str_new2 ("i"), INT2NUM (r->i));
  rb_hash_aset (rv, rb_str_new2 ("b"), INT2NUM (r->b));
  guestfs_free_int_bool (r);
  return rv;
}

static VALUE ruby_guestfs_aug_get (VALUE gv, VALUE augpathv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "aug_get");

  Check_Type (augpathv, T_STRING);
  const char *augpath = StringValueCStr (augpathv);
  if (!augpath)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "augpath", "aug_get");

  char *r;

  r = guestfs_aug_get (g, augpath);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  VALUE rv = rb_str_new2 (r);
  free (r);
  return rv;
}

static VALUE ruby_guestfs_aug_set (VALUE gv, VALUE augpathv, VALUE valv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "aug_set");

  Check_Type (augpathv, T_STRING);
  const char *augpath = StringValueCStr (augpathv);
  if (!augpath)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "augpath", "aug_set");
  Check_Type (valv, T_STRING);
  const char *val = StringValueCStr (valv);
  if (!val)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "val", "aug_set");

  int r;

  r = guestfs_aug_set (g, augpath, val);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

static VALUE ruby_guestfs_aug_insert (VALUE gv, VALUE augpathv, VALUE labelv, VALUE beforev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "aug_insert");

  Check_Type (augpathv, T_STRING);
  const char *augpath = StringValueCStr (augpathv);
  if (!augpath)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "augpath", "aug_insert");
  Check_Type (labelv, T_STRING);
  const char *label = StringValueCStr (labelv);
  if (!label)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "label", "aug_insert");
  int before = RTEST (beforev);

  int r;

  r = guestfs_aug_insert (g, augpath, label, before);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

static VALUE ruby_guestfs_aug_rm (VALUE gv, VALUE augpathv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "aug_rm");

  Check_Type (augpathv, T_STRING);
  const char *augpath = StringValueCStr (augpathv);
  if (!augpath)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "augpath", "aug_rm");

  int r;

  r = guestfs_aug_rm (g, augpath);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return INT2NUM (r);
}

static VALUE ruby_guestfs_aug_mv (VALUE gv, VALUE srcv, VALUE destv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "aug_mv");

  Check_Type (srcv, T_STRING);
  const char *src = StringValueCStr (srcv);
  if (!src)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "src", "aug_mv");
  Check_Type (destv, T_STRING);
  const char *dest = StringValueCStr (destv);
  if (!dest)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "dest", "aug_mv");

  int r;

  r = guestfs_aug_mv (g, src, dest);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

static VALUE ruby_guestfs_aug_match (VALUE gv, VALUE augpathv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "aug_match");

  Check_Type (augpathv, T_STRING);
  const char *augpath = StringValueCStr (augpathv);
  if (!augpath)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "augpath", "aug_match");

  char **r;

  r = guestfs_aug_match (g, augpath);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  int i, len = 0;
  for (i = 0; r[i] != NULL; ++i) len++;
  VALUE rv = rb_ary_new2 (len);
  for (i = 0; r[i] != NULL; ++i) {
    rb_ary_push (rv, rb_str_new2 (r[i]));
    free (r[i]);
  }
  free (r);
  return rv;
}

static VALUE ruby_guestfs_aug_save (VALUE gv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "aug_save");


  int r;

  r = guestfs_aug_save (g);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

static VALUE ruby_guestfs_aug_load (VALUE gv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "aug_load");


  int r;

  r = guestfs_aug_load (g);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

static VALUE ruby_guestfs_aug_ls (VALUE gv, VALUE augpathv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "aug_ls");

  Check_Type (augpathv, T_STRING);
  const char *augpath = StringValueCStr (augpathv);
  if (!augpath)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "augpath", "aug_ls");

  char **r;

  r = guestfs_aug_ls (g, augpath);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  int i, len = 0;
  for (i = 0; r[i] != NULL; ++i) len++;
  VALUE rv = rb_ary_new2 (len);
  for (i = 0; r[i] != NULL; ++i) {
    rb_ary_push (rv, rb_str_new2 (r[i]));
    free (r[i]);
  }
  free (r);
  return rv;
}

static VALUE ruby_guestfs_rm (VALUE gv, VALUE pathv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "rm");

  Check_Type (pathv, T_STRING);
  const char *path = StringValueCStr (pathv);
  if (!path)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "path", "rm");

  int r;

  r = guestfs_rm (g, path);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

static VALUE ruby_guestfs_rmdir (VALUE gv, VALUE pathv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "rmdir");

  Check_Type (pathv, T_STRING);
  const char *path = StringValueCStr (pathv);
  if (!path)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "path", "rmdir");

  int r;

  r = guestfs_rmdir (g, path);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

static VALUE ruby_guestfs_rm_rf (VALUE gv, VALUE pathv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "rm_rf");

  Check_Type (pathv, T_STRING);
  const char *path = StringValueCStr (pathv);
  if (!path)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "path", "rm_rf");

  int r;

  r = guestfs_rm_rf (g, path);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

static VALUE ruby_guestfs_mkdir (VALUE gv, VALUE pathv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "mkdir");

  Check_Type (pathv, T_STRING);
  const char *path = StringValueCStr (pathv);
  if (!path)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "path", "mkdir");

  int r;

  r = guestfs_mkdir (g, path);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

static VALUE ruby_guestfs_mkdir_p (VALUE gv, VALUE pathv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "mkdir_p");

  Check_Type (pathv, T_STRING);
  const char *path = StringValueCStr (pathv);
  if (!path)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "path", "mkdir_p");

  int r;

  r = guestfs_mkdir_p (g, path);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

static VALUE ruby_guestfs_chmod (VALUE gv, VALUE modev, VALUE pathv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "chmod");

  int mode = NUM2INT (modev);
  Check_Type (pathv, T_STRING);
  const char *path = StringValueCStr (pathv);
  if (!path)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "path", "chmod");

  int r;

  r = guestfs_chmod (g, mode, path);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

static VALUE ruby_guestfs_chown (VALUE gv, VALUE ownerv, VALUE groupv, VALUE pathv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "chown");

  int owner = NUM2INT (ownerv);
  int group = NUM2INT (groupv);
  Check_Type (pathv, T_STRING);
  const char *path = StringValueCStr (pathv);
  if (!path)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "path", "chown");

  int r;

  r = guestfs_chown (g, owner, group, path);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

static VALUE ruby_guestfs_exists (VALUE gv, VALUE pathv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "exists");

  Check_Type (pathv, T_STRING);
  const char *path = StringValueCStr (pathv);
  if (!path)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "path", "exists");

  int r;

  r = guestfs_exists (g, path);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return INT2NUM (r);
}

static VALUE ruby_guestfs_is_file (VALUE gv, VALUE pathv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "is_file");

  Check_Type (pathv, T_STRING);
  const char *path = StringValueCStr (pathv);
  if (!path)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "path", "is_file");

  int r;

  r = guestfs_is_file (g, path);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return INT2NUM (r);
}

static VALUE ruby_guestfs_is_dir (VALUE gv, VALUE pathv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "is_dir");

  Check_Type (pathv, T_STRING);
  const char *path = StringValueCStr (pathv);
  if (!path)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "path", "is_dir");

  int r;

  r = guestfs_is_dir (g, path);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return INT2NUM (r);
}

static VALUE ruby_guestfs_pvcreate (VALUE gv, VALUE devicev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "pvcreate");

  Check_Type (devicev, T_STRING);
  const char *device = StringValueCStr (devicev);
  if (!device)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "device", "pvcreate");

  int r;

  r = guestfs_pvcreate (g, device);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

static VALUE ruby_guestfs_vgcreate (VALUE gv, VALUE volgroupv, VALUE physvolsv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "vgcreate");

  Check_Type (volgroupv, T_STRING);
  const char *volgroup = StringValueCStr (volgroupv);
  if (!volgroup)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "volgroup", "vgcreate");
  char **physvols;
  Check_Type (physvolsv, T_ARRAY);
  {
    int i, len;
    len = RARRAY_LEN (physvolsv);
    physvols = guestfs_safe_malloc (g, sizeof (char *) * (len+1));
    for (i = 0; i < len; ++i) {
      VALUE v = rb_ary_entry (physvolsv, i);
      physvols[i] = StringValueCStr (v);
    }
    physvols[len] = NULL;
  }

  int r;

  r = guestfs_vgcreate (g, volgroup, physvols);
  free (physvols);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

static VALUE ruby_guestfs_lvcreate (VALUE gv, VALUE logvolv, VALUE volgroupv, VALUE mbytesv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "lvcreate");

  Check_Type (logvolv, T_STRING);
  const char *logvol = StringValueCStr (logvolv);
  if (!logvol)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "logvol", "lvcreate");
  Check_Type (volgroupv, T_STRING);
  const char *volgroup = StringValueCStr (volgroupv);
  if (!volgroup)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "volgroup", "lvcreate");
  int mbytes = NUM2INT (mbytesv);

  int r;

  r = guestfs_lvcreate (g, logvol, volgroup, mbytes);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

static VALUE ruby_guestfs_mkfs (VALUE gv, VALUE fstypev, VALUE devicev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "mkfs");

  Check_Type (fstypev, T_STRING);
  const char *fstype = StringValueCStr (fstypev);
  if (!fstype)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "fstype", "mkfs");
  Check_Type (devicev, T_STRING);
  const char *device = StringValueCStr (devicev);
  if (!device)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "device", "mkfs");

  int r;

  r = guestfs_mkfs (g, fstype, device);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

static VALUE ruby_guestfs_sfdisk (VALUE gv, VALUE devicev, VALUE cylsv, VALUE headsv, VALUE sectorsv, VALUE linesv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "sfdisk");

  Check_Type (devicev, T_STRING);
  const char *device = StringValueCStr (devicev);
  if (!device)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "device", "sfdisk");
  int cyls = NUM2INT (cylsv);
  int heads = NUM2INT (headsv);
  int sectors = NUM2INT (sectorsv);
  char **lines;
  Check_Type (linesv, T_ARRAY);
  {
    int i, len;
    len = RARRAY_LEN (linesv);
    lines = guestfs_safe_malloc (g, sizeof (char *) * (len+1));
    for (i = 0; i < len; ++i) {
      VALUE v = rb_ary_entry (linesv, i);
      lines[i] = StringValueCStr (v);
    }
    lines[len] = NULL;
  }

  int r;

  r = guestfs_sfdisk (g, device, cyls, heads, sectors, lines);
  free (lines);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

static VALUE ruby_guestfs_write_file (VALUE gv, VALUE pathv, VALUE contentv, VALUE sizev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "write_file");

  Check_Type (pathv, T_STRING);
  const char *path = StringValueCStr (pathv);
  if (!path)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "path", "write_file");
  Check_Type (contentv, T_STRING);
  const char *content = StringValueCStr (contentv);
  if (!content)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "content", "write_file");
  int size = NUM2INT (sizev);

  int r;

  r = guestfs_write_file (g, path, content, size);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

static VALUE ruby_guestfs_umount (VALUE gv, VALUE pathordevicev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "umount");

  Check_Type (pathordevicev, T_STRING);
  const char *pathordevice = StringValueCStr (pathordevicev);
  if (!pathordevice)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "pathordevice", "umount");

  int r;

  r = guestfs_umount (g, pathordevice);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

static VALUE ruby_guestfs_mounts (VALUE gv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "mounts");


  char **r;

  r = guestfs_mounts (g);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  int i, len = 0;
  for (i = 0; r[i] != NULL; ++i) len++;
  VALUE rv = rb_ary_new2 (len);
  for (i = 0; r[i] != NULL; ++i) {
    rb_ary_push (rv, rb_str_new2 (r[i]));
    free (r[i]);
  }
  free (r);
  return rv;
}

static VALUE ruby_guestfs_umount_all (VALUE gv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "umount_all");


  int r;

  r = guestfs_umount_all (g);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

static VALUE ruby_guestfs_lvm_remove_all (VALUE gv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "lvm_remove_all");


  int r;

  r = guestfs_lvm_remove_all (g);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

static VALUE ruby_guestfs_file (VALUE gv, VALUE pathv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "file");

  Check_Type (pathv, T_STRING);
  const char *path = StringValueCStr (pathv);
  if (!path)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "path", "file");

  char *r;

  r = guestfs_file (g, path);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  VALUE rv = rb_str_new2 (r);
  free (r);
  return rv;
}

static VALUE ruby_guestfs_command (VALUE gv, VALUE argumentsv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "command");

  char **arguments;
  Check_Type (argumentsv, T_ARRAY);
  {
    int i, len;
    len = RARRAY_LEN (argumentsv);
    arguments = guestfs_safe_malloc (g, sizeof (char *) * (len+1));
    for (i = 0; i < len; ++i) {
      VALUE v = rb_ary_entry (argumentsv, i);
      arguments[i] = StringValueCStr (v);
    }
    arguments[len] = NULL;
  }

  char *r;

  r = guestfs_command (g, arguments);
  free (arguments);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  VALUE rv = rb_str_new2 (r);
  free (r);
  return rv;
}

static VALUE ruby_guestfs_command_lines (VALUE gv, VALUE argumentsv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "command_lines");

  char **arguments;
  Check_Type (argumentsv, T_ARRAY);
  {
    int i, len;
    len = RARRAY_LEN (argumentsv);
    arguments = guestfs_safe_malloc (g, sizeof (char *) * (len+1));
    for (i = 0; i < len; ++i) {
      VALUE v = rb_ary_entry (argumentsv, i);
      arguments[i] = StringValueCStr (v);
    }
    arguments[len] = NULL;
  }

  char **r;

  r = guestfs_command_lines (g, arguments);
  free (arguments);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  int i, len = 0;
  for (i = 0; r[i] != NULL; ++i) len++;
  VALUE rv = rb_ary_new2 (len);
  for (i = 0; r[i] != NULL; ++i) {
    rb_ary_push (rv, rb_str_new2 (r[i]));
    free (r[i]);
  }
  free (r);
  return rv;
}

static VALUE ruby_guestfs_stat (VALUE gv, VALUE pathv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "stat");

  Check_Type (pathv, T_STRING);
  const char *path = StringValueCStr (pathv);
  if (!path)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "path", "stat");

  struct guestfs_stat *r;

  r = guestfs_stat (g, path);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  VALUE rv = rb_hash_new ();
  rb_hash_aset (rv, rb_str_new2 ("dev"), LL2NUM (r->dev));
  rb_hash_aset (rv, rb_str_new2 ("ino"), LL2NUM (r->ino));
  rb_hash_aset (rv, rb_str_new2 ("mode"), LL2NUM (r->mode));
  rb_hash_aset (rv, rb_str_new2 ("nlink"), LL2NUM (r->nlink));
  rb_hash_aset (rv, rb_str_new2 ("uid"), LL2NUM (r->uid));
  rb_hash_aset (rv, rb_str_new2 ("gid"), LL2NUM (r->gid));
  rb_hash_aset (rv, rb_str_new2 ("rdev"), LL2NUM (r->rdev));
  rb_hash_aset (rv, rb_str_new2 ("size"), LL2NUM (r->size));
  rb_hash_aset (rv, rb_str_new2 ("blksize"), LL2NUM (r->blksize));
  rb_hash_aset (rv, rb_str_new2 ("blocks"), LL2NUM (r->blocks));
  rb_hash_aset (rv, rb_str_new2 ("atime"), LL2NUM (r->atime));
  rb_hash_aset (rv, rb_str_new2 ("mtime"), LL2NUM (r->mtime));
  rb_hash_aset (rv, rb_str_new2 ("ctime"), LL2NUM (r->ctime));
  guestfs_free_stat (r);
  return rv;
}

static VALUE ruby_guestfs_lstat (VALUE gv, VALUE pathv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "lstat");

  Check_Type (pathv, T_STRING);
  const char *path = StringValueCStr (pathv);
  if (!path)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "path", "lstat");

  struct guestfs_stat *r;

  r = guestfs_lstat (g, path);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  VALUE rv = rb_hash_new ();
  rb_hash_aset (rv, rb_str_new2 ("dev"), LL2NUM (r->dev));
  rb_hash_aset (rv, rb_str_new2 ("ino"), LL2NUM (r->ino));
  rb_hash_aset (rv, rb_str_new2 ("mode"), LL2NUM (r->mode));
  rb_hash_aset (rv, rb_str_new2 ("nlink"), LL2NUM (r->nlink));
  rb_hash_aset (rv, rb_str_new2 ("uid"), LL2NUM (r->uid));
  rb_hash_aset (rv, rb_str_new2 ("gid"), LL2NUM (r->gid));
  rb_hash_aset (rv, rb_str_new2 ("rdev"), LL2NUM (r->rdev));
  rb_hash_aset (rv, rb_str_new2 ("size"), LL2NUM (r->size));
  rb_hash_aset (rv, rb_str_new2 ("blksize"), LL2NUM (r->blksize));
  rb_hash_aset (rv, rb_str_new2 ("blocks"), LL2NUM (r->blocks));
  rb_hash_aset (rv, rb_str_new2 ("atime"), LL2NUM (r->atime));
  rb_hash_aset (rv, rb_str_new2 ("mtime"), LL2NUM (r->mtime));
  rb_hash_aset (rv, rb_str_new2 ("ctime"), LL2NUM (r->ctime));
  guestfs_free_stat (r);
  return rv;
}

static VALUE ruby_guestfs_statvfs (VALUE gv, VALUE pathv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "statvfs");

  Check_Type (pathv, T_STRING);
  const char *path = StringValueCStr (pathv);
  if (!path)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "path", "statvfs");

  struct guestfs_statvfs *r;

  r = guestfs_statvfs (g, path);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  VALUE rv = rb_hash_new ();
  rb_hash_aset (rv, rb_str_new2 ("bsize"), LL2NUM (r->bsize));
  rb_hash_aset (rv, rb_str_new2 ("frsize"), LL2NUM (r->frsize));
  rb_hash_aset (rv, rb_str_new2 ("blocks"), LL2NUM (r->blocks));
  rb_hash_aset (rv, rb_str_new2 ("bfree"), LL2NUM (r->bfree));
  rb_hash_aset (rv, rb_str_new2 ("bavail"), LL2NUM (r->bavail));
  rb_hash_aset (rv, rb_str_new2 ("files"), LL2NUM (r->files));
  rb_hash_aset (rv, rb_str_new2 ("ffree"), LL2NUM (r->ffree));
  rb_hash_aset (rv, rb_str_new2 ("favail"), LL2NUM (r->favail));
  rb_hash_aset (rv, rb_str_new2 ("fsid"), LL2NUM (r->fsid));
  rb_hash_aset (rv, rb_str_new2 ("flag"), LL2NUM (r->flag));
  rb_hash_aset (rv, rb_str_new2 ("namemax"), LL2NUM (r->namemax));
  guestfs_free_statvfs (r);
  return rv;
}

static VALUE ruby_guestfs_tune2fs_l (VALUE gv, VALUE devicev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "tune2fs_l");

  Check_Type (devicev, T_STRING);
  const char *device = StringValueCStr (devicev);
  if (!device)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "device", "tune2fs_l");

  char **r;

  r = guestfs_tune2fs_l (g, device);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  VALUE rv = rb_hash_new ();
  int i;
  for (i = 0; r[i] != NULL; i+=2) {
    rb_hash_aset (rv, rb_str_new2 (r[i]), rb_str_new2 (r[i+1]));
    free (r[i]);
    free (r[i+1]);
  }
  free (r);
  return rv;
}

static VALUE ruby_guestfs_blockdev_setro (VALUE gv, VALUE devicev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "blockdev_setro");

  Check_Type (devicev, T_STRING);
  const char *device = StringValueCStr (devicev);
  if (!device)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "device", "blockdev_setro");

  int r;

  r = guestfs_blockdev_setro (g, device);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

static VALUE ruby_guestfs_blockdev_setrw (VALUE gv, VALUE devicev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "blockdev_setrw");

  Check_Type (devicev, T_STRING);
  const char *device = StringValueCStr (devicev);
  if (!device)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "device", "blockdev_setrw");

  int r;

  r = guestfs_blockdev_setrw (g, device);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

static VALUE ruby_guestfs_blockdev_getro (VALUE gv, VALUE devicev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "blockdev_getro");

  Check_Type (devicev, T_STRING);
  const char *device = StringValueCStr (devicev);
  if (!device)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "device", "blockdev_getro");

  int r;

  r = guestfs_blockdev_getro (g, device);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return INT2NUM (r);
}

static VALUE ruby_guestfs_blockdev_getss (VALUE gv, VALUE devicev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "blockdev_getss");

  Check_Type (devicev, T_STRING);
  const char *device = StringValueCStr (devicev);
  if (!device)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "device", "blockdev_getss");

  int r;

  r = guestfs_blockdev_getss (g, device);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return INT2NUM (r);
}

static VALUE ruby_guestfs_blockdev_getbsz (VALUE gv, VALUE devicev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "blockdev_getbsz");

  Check_Type (devicev, T_STRING);
  const char *device = StringValueCStr (devicev);
  if (!device)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "device", "blockdev_getbsz");

  int r;

  r = guestfs_blockdev_getbsz (g, device);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return INT2NUM (r);
}

static VALUE ruby_guestfs_blockdev_setbsz (VALUE gv, VALUE devicev, VALUE blocksizev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "blockdev_setbsz");

  Check_Type (devicev, T_STRING);
  const char *device = StringValueCStr (devicev);
  if (!device)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "device", "blockdev_setbsz");
  int blocksize = NUM2INT (blocksizev);

  int r;

  r = guestfs_blockdev_setbsz (g, device, blocksize);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

static VALUE ruby_guestfs_blockdev_getsz (VALUE gv, VALUE devicev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "blockdev_getsz");

  Check_Type (devicev, T_STRING);
  const char *device = StringValueCStr (devicev);
  if (!device)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "device", "blockdev_getsz");

  int64_t r;

  r = guestfs_blockdev_getsz (g, device);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return ULL2NUM (r);
}

static VALUE ruby_guestfs_blockdev_getsize64 (VALUE gv, VALUE devicev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "blockdev_getsize64");

  Check_Type (devicev, T_STRING);
  const char *device = StringValueCStr (devicev);
  if (!device)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "device", "blockdev_getsize64");

  int64_t r;

  r = guestfs_blockdev_getsize64 (g, device);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return ULL2NUM (r);
}

static VALUE ruby_guestfs_blockdev_flushbufs (VALUE gv, VALUE devicev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "blockdev_flushbufs");

  Check_Type (devicev, T_STRING);
  const char *device = StringValueCStr (devicev);
  if (!device)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "device", "blockdev_flushbufs");

  int r;

  r = guestfs_blockdev_flushbufs (g, device);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

static VALUE ruby_guestfs_blockdev_rereadpt (VALUE gv, VALUE devicev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "blockdev_rereadpt");

  Check_Type (devicev, T_STRING);
  const char *device = StringValueCStr (devicev);
  if (!device)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "device", "blockdev_rereadpt");

  int r;

  r = guestfs_blockdev_rereadpt (g, device);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

static VALUE ruby_guestfs_upload (VALUE gv, VALUE filenamev, VALUE remotefilenamev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "upload");

  Check_Type (filenamev, T_STRING);
  const char *filename = StringValueCStr (filenamev);
  if (!filename)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "filename", "upload");
  Check_Type (remotefilenamev, T_STRING);
  const char *remotefilename = StringValueCStr (remotefilenamev);
  if (!remotefilename)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "remotefilename", "upload");

  int r;

  r = guestfs_upload (g, filename, remotefilename);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

static VALUE ruby_guestfs_download (VALUE gv, VALUE remotefilenamev, VALUE filenamev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "download");

  Check_Type (remotefilenamev, T_STRING);
  const char *remotefilename = StringValueCStr (remotefilenamev);
  if (!remotefilename)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "remotefilename", "download");
  Check_Type (filenamev, T_STRING);
  const char *filename = StringValueCStr (filenamev);
  if (!filename)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "filename", "download");

  int r;

  r = guestfs_download (g, remotefilename, filename);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

static VALUE ruby_guestfs_checksum (VALUE gv, VALUE csumtypev, VALUE pathv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "checksum");

  Check_Type (csumtypev, T_STRING);
  const char *csumtype = StringValueCStr (csumtypev);
  if (!csumtype)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "csumtype", "checksum");
  Check_Type (pathv, T_STRING);
  const char *path = StringValueCStr (pathv);
  if (!path)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "path", "checksum");

  char *r;

  r = guestfs_checksum (g, csumtype, path);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  VALUE rv = rb_str_new2 (r);
  free (r);
  return rv;
}

static VALUE ruby_guestfs_tar_in (VALUE gv, VALUE tarfilev, VALUE directoryv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "tar_in");

  Check_Type (tarfilev, T_STRING);
  const char *tarfile = StringValueCStr (tarfilev);
  if (!tarfile)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "tarfile", "tar_in");
  Check_Type (directoryv, T_STRING);
  const char *directory = StringValueCStr (directoryv);
  if (!directory)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "directory", "tar_in");

  int r;

  r = guestfs_tar_in (g, tarfile, directory);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

static VALUE ruby_guestfs_tar_out (VALUE gv, VALUE directoryv, VALUE tarfilev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "tar_out");

  Check_Type (directoryv, T_STRING);
  const char *directory = StringValueCStr (directoryv);
  if (!directory)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "directory", "tar_out");
  Check_Type (tarfilev, T_STRING);
  const char *tarfile = StringValueCStr (tarfilev);
  if (!tarfile)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "tarfile", "tar_out");

  int r;

  r = guestfs_tar_out (g, directory, tarfile);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

static VALUE ruby_guestfs_tgz_in (VALUE gv, VALUE tarballv, VALUE directoryv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "tgz_in");

  Check_Type (tarballv, T_STRING);
  const char *tarball = StringValueCStr (tarballv);
  if (!tarball)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "tarball", "tgz_in");
  Check_Type (directoryv, T_STRING);
  const char *directory = StringValueCStr (directoryv);
  if (!directory)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "directory", "tgz_in");

  int r;

  r = guestfs_tgz_in (g, tarball, directory);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

static VALUE ruby_guestfs_tgz_out (VALUE gv, VALUE directoryv, VALUE tarballv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "tgz_out");

  Check_Type (directoryv, T_STRING);
  const char *directory = StringValueCStr (directoryv);
  if (!directory)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "directory", "tgz_out");
  Check_Type (tarballv, T_STRING);
  const char *tarball = StringValueCStr (tarballv);
  if (!tarball)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "tarball", "tgz_out");

  int r;

  r = guestfs_tgz_out (g, directory, tarball);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

static VALUE ruby_guestfs_mount_ro (VALUE gv, VALUE devicev, VALUE mountpointv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "mount_ro");

  Check_Type (devicev, T_STRING);
  const char *device = StringValueCStr (devicev);
  if (!device)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "device", "mount_ro");
  Check_Type (mountpointv, T_STRING);
  const char *mountpoint = StringValueCStr (mountpointv);
  if (!mountpoint)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "mountpoint", "mount_ro");

  int r;

  r = guestfs_mount_ro (g, device, mountpoint);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

static VALUE ruby_guestfs_mount_options (VALUE gv, VALUE optionsv, VALUE devicev, VALUE mountpointv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "mount_options");

  Check_Type (optionsv, T_STRING);
  const char *options = StringValueCStr (optionsv);
  if (!options)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "options", "mount_options");
  Check_Type (devicev, T_STRING);
  const char *device = StringValueCStr (devicev);
  if (!device)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "device", "mount_options");
  Check_Type (mountpointv, T_STRING);
  const char *mountpoint = StringValueCStr (mountpointv);
  if (!mountpoint)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "mountpoint", "mount_options");

  int r;

  r = guestfs_mount_options (g, options, device, mountpoint);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

static VALUE ruby_guestfs_mount_vfs (VALUE gv, VALUE optionsv, VALUE vfstypev, VALUE devicev, VALUE mountpointv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "mount_vfs");

  Check_Type (optionsv, T_STRING);
  const char *options = StringValueCStr (optionsv);
  if (!options)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "options", "mount_vfs");
  Check_Type (vfstypev, T_STRING);
  const char *vfstype = StringValueCStr (vfstypev);
  if (!vfstype)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "vfstype", "mount_vfs");
  Check_Type (devicev, T_STRING);
  const char *device = StringValueCStr (devicev);
  if (!device)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "device", "mount_vfs");
  Check_Type (mountpointv, T_STRING);
  const char *mountpoint = StringValueCStr (mountpointv);
  if (!mountpoint)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "mountpoint", "mount_vfs");

  int r;

  r = guestfs_mount_vfs (g, options, vfstype, device, mountpoint);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

static VALUE ruby_guestfs_debug (VALUE gv, VALUE subcmdv, VALUE extraargsv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "debug");

  Check_Type (subcmdv, T_STRING);
  const char *subcmd = StringValueCStr (subcmdv);
  if (!subcmd)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "subcmd", "debug");
  char **extraargs;
  Check_Type (extraargsv, T_ARRAY);
  {
    int i, len;
    len = RARRAY_LEN (extraargsv);
    extraargs = guestfs_safe_malloc (g, sizeof (char *) * (len+1));
    for (i = 0; i < len; ++i) {
      VALUE v = rb_ary_entry (extraargsv, i);
      extraargs[i] = StringValueCStr (v);
    }
    extraargs[len] = NULL;
  }

  char *r;

  r = guestfs_debug (g, subcmd, extraargs);
  free (extraargs);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  VALUE rv = rb_str_new2 (r);
  free (r);
  return rv;
}

static VALUE ruby_guestfs_lvremove (VALUE gv, VALUE devicev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "lvremove");

  Check_Type (devicev, T_STRING);
  const char *device = StringValueCStr (devicev);
  if (!device)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "device", "lvremove");

  int r;

  r = guestfs_lvremove (g, device);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

static VALUE ruby_guestfs_vgremove (VALUE gv, VALUE vgnamev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "vgremove");

  Check_Type (vgnamev, T_STRING);
  const char *vgname = StringValueCStr (vgnamev);
  if (!vgname)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "vgname", "vgremove");

  int r;

  r = guestfs_vgremove (g, vgname);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

static VALUE ruby_guestfs_pvremove (VALUE gv, VALUE devicev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "pvremove");

  Check_Type (devicev, T_STRING);
  const char *device = StringValueCStr (devicev);
  if (!device)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "device", "pvremove");

  int r;

  r = guestfs_pvremove (g, device);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

static VALUE ruby_guestfs_set_e2label (VALUE gv, VALUE devicev, VALUE labelv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "set_e2label");

  Check_Type (devicev, T_STRING);
  const char *device = StringValueCStr (devicev);
  if (!device)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "device", "set_e2label");
  Check_Type (labelv, T_STRING);
  const char *label = StringValueCStr (labelv);
  if (!label)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "label", "set_e2label");

  int r;

  r = guestfs_set_e2label (g, device, label);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

static VALUE ruby_guestfs_get_e2label (VALUE gv, VALUE devicev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "get_e2label");

  Check_Type (devicev, T_STRING);
  const char *device = StringValueCStr (devicev);
  if (!device)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "device", "get_e2label");

  char *r;

  r = guestfs_get_e2label (g, device);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  VALUE rv = rb_str_new2 (r);
  free (r);
  return rv;
}

static VALUE ruby_guestfs_set_e2uuid (VALUE gv, VALUE devicev, VALUE uuidv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "set_e2uuid");

  Check_Type (devicev, T_STRING);
  const char *device = StringValueCStr (devicev);
  if (!device)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "device", "set_e2uuid");
  Check_Type (uuidv, T_STRING);
  const char *uuid = StringValueCStr (uuidv);
  if (!uuid)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "uuid", "set_e2uuid");

  int r;

  r = guestfs_set_e2uuid (g, device, uuid);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

static VALUE ruby_guestfs_get_e2uuid (VALUE gv, VALUE devicev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "get_e2uuid");

  Check_Type (devicev, T_STRING);
  const char *device = StringValueCStr (devicev);
  if (!device)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "device", "get_e2uuid");

  char *r;

  r = guestfs_get_e2uuid (g, device);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  VALUE rv = rb_str_new2 (r);
  free (r);
  return rv;
}

static VALUE ruby_guestfs_fsck (VALUE gv, VALUE fstypev, VALUE devicev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "fsck");

  Check_Type (fstypev, T_STRING);
  const char *fstype = StringValueCStr (fstypev);
  if (!fstype)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "fstype", "fsck");
  Check_Type (devicev, T_STRING);
  const char *device = StringValueCStr (devicev);
  if (!device)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "device", "fsck");

  int r;

  r = guestfs_fsck (g, fstype, device);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return INT2NUM (r);
}

static VALUE ruby_guestfs_zero (VALUE gv, VALUE devicev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "zero");

  Check_Type (devicev, T_STRING);
  const char *device = StringValueCStr (devicev);
  if (!device)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "device", "zero");

  int r;

  r = guestfs_zero (g, device);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

static VALUE ruby_guestfs_grub_install (VALUE gv, VALUE rootv, VALUE devicev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "grub_install");

  Check_Type (rootv, T_STRING);
  const char *root = StringValueCStr (rootv);
  if (!root)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "root", "grub_install");
  Check_Type (devicev, T_STRING);
  const char *device = StringValueCStr (devicev);
  if (!device)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "device", "grub_install");

  int r;

  r = guestfs_grub_install (g, root, device);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

static VALUE ruby_guestfs_cp (VALUE gv, VALUE srcv, VALUE destv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "cp");

  Check_Type (srcv, T_STRING);
  const char *src = StringValueCStr (srcv);
  if (!src)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "src", "cp");
  Check_Type (destv, T_STRING);
  const char *dest = StringValueCStr (destv);
  if (!dest)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "dest", "cp");

  int r;

  r = guestfs_cp (g, src, dest);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

static VALUE ruby_guestfs_cp_a (VALUE gv, VALUE srcv, VALUE destv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "cp_a");

  Check_Type (srcv, T_STRING);
  const char *src = StringValueCStr (srcv);
  if (!src)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "src", "cp_a");
  Check_Type (destv, T_STRING);
  const char *dest = StringValueCStr (destv);
  if (!dest)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "dest", "cp_a");

  int r;

  r = guestfs_cp_a (g, src, dest);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

static VALUE ruby_guestfs_mv (VALUE gv, VALUE srcv, VALUE destv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "mv");

  Check_Type (srcv, T_STRING);
  const char *src = StringValueCStr (srcv);
  if (!src)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "src", "mv");
  Check_Type (destv, T_STRING);
  const char *dest = StringValueCStr (destv);
  if (!dest)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "dest", "mv");

  int r;

  r = guestfs_mv (g, src, dest);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

static VALUE ruby_guestfs_drop_caches (VALUE gv, VALUE whattodropv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "drop_caches");

  int whattodrop = NUM2INT (whattodropv);

  int r;

  r = guestfs_drop_caches (g, whattodrop);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

static VALUE ruby_guestfs_dmesg (VALUE gv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "dmesg");


  char *r;

  r = guestfs_dmesg (g);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  VALUE rv = rb_str_new2 (r);
  free (r);
  return rv;
}

static VALUE ruby_guestfs_ping_daemon (VALUE gv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "ping_daemon");


  int r;

  r = guestfs_ping_daemon (g);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

static VALUE ruby_guestfs_equal (VALUE gv, VALUE file1v, VALUE file2v)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "equal");

  Check_Type (file1v, T_STRING);
  const char *file1 = StringValueCStr (file1v);
  if (!file1)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "file1", "equal");
  Check_Type (file2v, T_STRING);
  const char *file2 = StringValueCStr (file2v);
  if (!file2)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "file2", "equal");

  int r;

  r = guestfs_equal (g, file1, file2);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return INT2NUM (r);
}

static VALUE ruby_guestfs_strings (VALUE gv, VALUE pathv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "strings");

  Check_Type (pathv, T_STRING);
  const char *path = StringValueCStr (pathv);
  if (!path)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "path", "strings");

  char **r;

  r = guestfs_strings (g, path);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  int i, len = 0;
  for (i = 0; r[i] != NULL; ++i) len++;
  VALUE rv = rb_ary_new2 (len);
  for (i = 0; r[i] != NULL; ++i) {
    rb_ary_push (rv, rb_str_new2 (r[i]));
    free (r[i]);
  }
  free (r);
  return rv;
}

static VALUE ruby_guestfs_strings_e (VALUE gv, VALUE encodingv, VALUE pathv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "strings_e");

  Check_Type (encodingv, T_STRING);
  const char *encoding = StringValueCStr (encodingv);
  if (!encoding)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "encoding", "strings_e");
  Check_Type (pathv, T_STRING);
  const char *path = StringValueCStr (pathv);
  if (!path)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "path", "strings_e");

  char **r;

  r = guestfs_strings_e (g, encoding, path);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  int i, len = 0;
  for (i = 0; r[i] != NULL; ++i) len++;
  VALUE rv = rb_ary_new2 (len);
  for (i = 0; r[i] != NULL; ++i) {
    rb_ary_push (rv, rb_str_new2 (r[i]));
    free (r[i]);
  }
  free (r);
  return rv;
}

static VALUE ruby_guestfs_hexdump (VALUE gv, VALUE pathv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "hexdump");

  Check_Type (pathv, T_STRING);
  const char *path = StringValueCStr (pathv);
  if (!path)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "path", "hexdump");

  char *r;

  r = guestfs_hexdump (g, path);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  VALUE rv = rb_str_new2 (r);
  free (r);
  return rv;
}

static VALUE ruby_guestfs_zerofree (VALUE gv, VALUE devicev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "zerofree");

  Check_Type (devicev, T_STRING);
  const char *device = StringValueCStr (devicev);
  if (!device)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "device", "zerofree");

  int r;

  r = guestfs_zerofree (g, device);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

static VALUE ruby_guestfs_pvresize (VALUE gv, VALUE devicev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "pvresize");

  Check_Type (devicev, T_STRING);
  const char *device = StringValueCStr (devicev);
  if (!device)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "device", "pvresize");

  int r;

  r = guestfs_pvresize (g, device);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

static VALUE ruby_guestfs_sfdisk_N (VALUE gv, VALUE devicev, VALUE partnumv, VALUE cylsv, VALUE headsv, VALUE sectorsv, VALUE linev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "sfdisk_N");

  Check_Type (devicev, T_STRING);
  const char *device = StringValueCStr (devicev);
  if (!device)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "device", "sfdisk_N");
  int partnum = NUM2INT (partnumv);
  int cyls = NUM2INT (cylsv);
  int heads = NUM2INT (headsv);
  int sectors = NUM2INT (sectorsv);
  Check_Type (linev, T_STRING);
  const char *line = StringValueCStr (linev);
  if (!line)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "line", "sfdisk_N");

  int r;

  r = guestfs_sfdisk_N (g, device, partnum, cyls, heads, sectors, line);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

static VALUE ruby_guestfs_sfdisk_l (VALUE gv, VALUE devicev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "sfdisk_l");

  Check_Type (devicev, T_STRING);
  const char *device = StringValueCStr (devicev);
  if (!device)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "device", "sfdisk_l");

  char *r;

  r = guestfs_sfdisk_l (g, device);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  VALUE rv = rb_str_new2 (r);
  free (r);
  return rv;
}

static VALUE ruby_guestfs_sfdisk_kernel_geometry (VALUE gv, VALUE devicev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "sfdisk_kernel_geometry");

  Check_Type (devicev, T_STRING);
  const char *device = StringValueCStr (devicev);
  if (!device)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "device", "sfdisk_kernel_geometry");

  char *r;

  r = guestfs_sfdisk_kernel_geometry (g, device);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  VALUE rv = rb_str_new2 (r);
  free (r);
  return rv;
}

static VALUE ruby_guestfs_sfdisk_disk_geometry (VALUE gv, VALUE devicev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "sfdisk_disk_geometry");

  Check_Type (devicev, T_STRING);
  const char *device = StringValueCStr (devicev);
  if (!device)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "device", "sfdisk_disk_geometry");

  char *r;

  r = guestfs_sfdisk_disk_geometry (g, device);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  VALUE rv = rb_str_new2 (r);
  free (r);
  return rv;
}

static VALUE ruby_guestfs_vg_activate_all (VALUE gv, VALUE activatev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "vg_activate_all");

  int activate = RTEST (activatev);

  int r;

  r = guestfs_vg_activate_all (g, activate);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

static VALUE ruby_guestfs_vg_activate (VALUE gv, VALUE activatev, VALUE volgroupsv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "vg_activate");

  int activate = RTEST (activatev);
  char **volgroups;
  Check_Type (volgroupsv, T_ARRAY);
  {
    int i, len;
    len = RARRAY_LEN (volgroupsv);
    volgroups = guestfs_safe_malloc (g, sizeof (char *) * (len+1));
    for (i = 0; i < len; ++i) {
      VALUE v = rb_ary_entry (volgroupsv, i);
      volgroups[i] = StringValueCStr (v);
    }
    volgroups[len] = NULL;
  }

  int r;

  r = guestfs_vg_activate (g, activate, volgroups);
  free (volgroups);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

static VALUE ruby_guestfs_lvresize (VALUE gv, VALUE devicev, VALUE mbytesv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "lvresize");

  Check_Type (devicev, T_STRING);
  const char *device = StringValueCStr (devicev);
  if (!device)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "device", "lvresize");
  int mbytes = NUM2INT (mbytesv);

  int r;

  r = guestfs_lvresize (g, device, mbytes);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

static VALUE ruby_guestfs_resize2fs (VALUE gv, VALUE devicev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "resize2fs");

  Check_Type (devicev, T_STRING);
  const char *device = StringValueCStr (devicev);
  if (!device)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "device", "resize2fs");

  int r;

  r = guestfs_resize2fs (g, device);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

static VALUE ruby_guestfs_find (VALUE gv, VALUE directoryv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "find");

  Check_Type (directoryv, T_STRING);
  const char *directory = StringValueCStr (directoryv);
  if (!directory)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "directory", "find");

  char **r;

  r = guestfs_find (g, directory);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  int i, len = 0;
  for (i = 0; r[i] != NULL; ++i) len++;
  VALUE rv = rb_ary_new2 (len);
  for (i = 0; r[i] != NULL; ++i) {
    rb_ary_push (rv, rb_str_new2 (r[i]));
    free (r[i]);
  }
  free (r);
  return rv;
}

static VALUE ruby_guestfs_e2fsck_f (VALUE gv, VALUE devicev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "e2fsck_f");

  Check_Type (devicev, T_STRING);
  const char *device = StringValueCStr (devicev);
  if (!device)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "device", "e2fsck_f");

  int r;

  r = guestfs_e2fsck_f (g, device);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

static VALUE ruby_guestfs_sleep (VALUE gv, VALUE secsv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "sleep");

  int secs = NUM2INT (secsv);

  int r;

  r = guestfs_sleep (g, secs);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

static VALUE ruby_guestfs_ntfs_3g_probe (VALUE gv, VALUE rwv, VALUE devicev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "ntfs_3g_probe");

  int rw = RTEST (rwv);
  Check_Type (devicev, T_STRING);
  const char *device = StringValueCStr (devicev);
  if (!device)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "device", "ntfs_3g_probe");

  int r;

  r = guestfs_ntfs_3g_probe (g, rw, device);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return INT2NUM (r);
}

static VALUE ruby_guestfs_sh (VALUE gv, VALUE commandv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "sh");

  Check_Type (commandv, T_STRING);
  const char *command = StringValueCStr (commandv);
  if (!command)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "command", "sh");

  char *r;

  r = guestfs_sh (g, command);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  VALUE rv = rb_str_new2 (r);
  free (r);
  return rv;
}

static VALUE ruby_guestfs_sh_lines (VALUE gv, VALUE commandv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "sh_lines");

  Check_Type (commandv, T_STRING);
  const char *command = StringValueCStr (commandv);
  if (!command)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "command", "sh_lines");

  char **r;

  r = guestfs_sh_lines (g, command);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  int i, len = 0;
  for (i = 0; r[i] != NULL; ++i) len++;
  VALUE rv = rb_ary_new2 (len);
  for (i = 0; r[i] != NULL; ++i) {
    rb_ary_push (rv, rb_str_new2 (r[i]));
    free (r[i]);
  }
  free (r);
  return rv;
}

static VALUE ruby_guestfs_glob_expand (VALUE gv, VALUE patternv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "glob_expand");

  Check_Type (patternv, T_STRING);
  const char *pattern = StringValueCStr (patternv);
  if (!pattern)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "pattern", "glob_expand");

  char **r;

  r = guestfs_glob_expand (g, pattern);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  int i, len = 0;
  for (i = 0; r[i] != NULL; ++i) len++;
  VALUE rv = rb_ary_new2 (len);
  for (i = 0; r[i] != NULL; ++i) {
    rb_ary_push (rv, rb_str_new2 (r[i]));
    free (r[i]);
  }
  free (r);
  return rv;
}

static VALUE ruby_guestfs_scrub_device (VALUE gv, VALUE devicev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "scrub_device");

  Check_Type (devicev, T_STRING);
  const char *device = StringValueCStr (devicev);
  if (!device)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "device", "scrub_device");

  int r;

  r = guestfs_scrub_device (g, device);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

static VALUE ruby_guestfs_scrub_file (VALUE gv, VALUE filev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "scrub_file");

  Check_Type (filev, T_STRING);
  const char *file = StringValueCStr (filev);
  if (!file)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "file", "scrub_file");

  int r;

  r = guestfs_scrub_file (g, file);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

static VALUE ruby_guestfs_scrub_freespace (VALUE gv, VALUE dirv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "scrub_freespace");

  Check_Type (dirv, T_STRING);
  const char *dir = StringValueCStr (dirv);
  if (!dir)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "dir", "scrub_freespace");

  int r;

  r = guestfs_scrub_freespace (g, dir);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

static VALUE ruby_guestfs_mkdtemp (VALUE gv, VALUE templatev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "mkdtemp");

  Check_Type (templatev, T_STRING);
  const char *template = StringValueCStr (templatev);
  if (!template)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "template", "mkdtemp");

  char *r;

  r = guestfs_mkdtemp (g, template);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  VALUE rv = rb_str_new2 (r);
  free (r);
  return rv;
}

static VALUE ruby_guestfs_wc_l (VALUE gv, VALUE pathv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "wc_l");

  Check_Type (pathv, T_STRING);
  const char *path = StringValueCStr (pathv);
  if (!path)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "path", "wc_l");

  int r;

  r = guestfs_wc_l (g, path);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return INT2NUM (r);
}

static VALUE ruby_guestfs_wc_w (VALUE gv, VALUE pathv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "wc_w");

  Check_Type (pathv, T_STRING);
  const char *path = StringValueCStr (pathv);
  if (!path)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "path", "wc_w");

  int r;

  r = guestfs_wc_w (g, path);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return INT2NUM (r);
}

static VALUE ruby_guestfs_wc_c (VALUE gv, VALUE pathv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "wc_c");

  Check_Type (pathv, T_STRING);
  const char *path = StringValueCStr (pathv);
  if (!path)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "path", "wc_c");

  int r;

  r = guestfs_wc_c (g, path);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return INT2NUM (r);
}

static VALUE ruby_guestfs_head (VALUE gv, VALUE pathv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "head");

  Check_Type (pathv, T_STRING);
  const char *path = StringValueCStr (pathv);
  if (!path)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "path", "head");

  char **r;

  r = guestfs_head (g, path);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  int i, len = 0;
  for (i = 0; r[i] != NULL; ++i) len++;
  VALUE rv = rb_ary_new2 (len);
  for (i = 0; r[i] != NULL; ++i) {
    rb_ary_push (rv, rb_str_new2 (r[i]));
    free (r[i]);
  }
  free (r);
  return rv;
}

static VALUE ruby_guestfs_head_n (VALUE gv, VALUE nrlinesv, VALUE pathv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "head_n");

  int nrlines = NUM2INT (nrlinesv);
  Check_Type (pathv, T_STRING);
  const char *path = StringValueCStr (pathv);
  if (!path)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "path", "head_n");

  char **r;

  r = guestfs_head_n (g, nrlines, path);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  int i, len = 0;
  for (i = 0; r[i] != NULL; ++i) len++;
  VALUE rv = rb_ary_new2 (len);
  for (i = 0; r[i] != NULL; ++i) {
    rb_ary_push (rv, rb_str_new2 (r[i]));
    free (r[i]);
  }
  free (r);
  return rv;
}

static VALUE ruby_guestfs_tail (VALUE gv, VALUE pathv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "tail");

  Check_Type (pathv, T_STRING);
  const char *path = StringValueCStr (pathv);
  if (!path)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "path", "tail");

  char **r;

  r = guestfs_tail (g, path);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  int i, len = 0;
  for (i = 0; r[i] != NULL; ++i) len++;
  VALUE rv = rb_ary_new2 (len);
  for (i = 0; r[i] != NULL; ++i) {
    rb_ary_push (rv, rb_str_new2 (r[i]));
    free (r[i]);
  }
  free (r);
  return rv;
}

static VALUE ruby_guestfs_tail_n (VALUE gv, VALUE nrlinesv, VALUE pathv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "tail_n");

  int nrlines = NUM2INT (nrlinesv);
  Check_Type (pathv, T_STRING);
  const char *path = StringValueCStr (pathv);
  if (!path)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "path", "tail_n");

  char **r;

  r = guestfs_tail_n (g, nrlines, path);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  int i, len = 0;
  for (i = 0; r[i] != NULL; ++i) len++;
  VALUE rv = rb_ary_new2 (len);
  for (i = 0; r[i] != NULL; ++i) {
    rb_ary_push (rv, rb_str_new2 (r[i]));
    free (r[i]);
  }
  free (r);
  return rv;
}

static VALUE ruby_guestfs_df (VALUE gv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "df");


  char *r;

  r = guestfs_df (g);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  VALUE rv = rb_str_new2 (r);
  free (r);
  return rv;
}

static VALUE ruby_guestfs_df_h (VALUE gv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "df_h");


  char *r;

  r = guestfs_df_h (g);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  VALUE rv = rb_str_new2 (r);
  free (r);
  return rv;
}

static VALUE ruby_guestfs_du (VALUE gv, VALUE pathv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "du");

  Check_Type (pathv, T_STRING);
  const char *path = StringValueCStr (pathv);
  if (!path)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "path", "du");

  int64_t r;

  r = guestfs_du (g, path);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return ULL2NUM (r);
}

static VALUE ruby_guestfs_initrd_list (VALUE gv, VALUE pathv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "initrd_list");

  Check_Type (pathv, T_STRING);
  const char *path = StringValueCStr (pathv);
  if (!path)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "path", "initrd_list");

  char **r;

  r = guestfs_initrd_list (g, path);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  int i, len = 0;
  for (i = 0; r[i] != NULL; ++i) len++;
  VALUE rv = rb_ary_new2 (len);
  for (i = 0; r[i] != NULL; ++i) {
    rb_ary_push (rv, rb_str_new2 (r[i]));
    free (r[i]);
  }
  free (r);
  return rv;
}

static VALUE ruby_guestfs_mount_loop (VALUE gv, VALUE filev, VALUE mountpointv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "mount_loop");

  Check_Type (filev, T_STRING);
  const char *file = StringValueCStr (filev);
  if (!file)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "file", "mount_loop");
  Check_Type (mountpointv, T_STRING);
  const char *mountpoint = StringValueCStr (mountpointv);
  if (!mountpoint)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "mountpoint", "mount_loop");

  int r;

  r = guestfs_mount_loop (g, file, mountpoint);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

static VALUE ruby_guestfs_mkswap (VALUE gv, VALUE devicev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "mkswap");

  Check_Type (devicev, T_STRING);
  const char *device = StringValueCStr (devicev);
  if (!device)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "device", "mkswap");

  int r;

  r = guestfs_mkswap (g, device);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

static VALUE ruby_guestfs_mkswap_L (VALUE gv, VALUE labelv, VALUE devicev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "mkswap_L");

  Check_Type (labelv, T_STRING);
  const char *label = StringValueCStr (labelv);
  if (!label)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "label", "mkswap_L");
  Check_Type (devicev, T_STRING);
  const char *device = StringValueCStr (devicev);
  if (!device)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "device", "mkswap_L");

  int r;

  r = guestfs_mkswap_L (g, label, device);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

static VALUE ruby_guestfs_mkswap_U (VALUE gv, VALUE uuidv, VALUE devicev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "mkswap_U");

  Check_Type (uuidv, T_STRING);
  const char *uuid = StringValueCStr (uuidv);
  if (!uuid)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "uuid", "mkswap_U");
  Check_Type (devicev, T_STRING);
  const char *device = StringValueCStr (devicev);
  if (!device)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "device", "mkswap_U");

  int r;

  r = guestfs_mkswap_U (g, uuid, device);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

static VALUE ruby_guestfs_mknod (VALUE gv, VALUE modev, VALUE devmajorv, VALUE devminorv, VALUE pathv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "mknod");

  int mode = NUM2INT (modev);
  int devmajor = NUM2INT (devmajorv);
  int devminor = NUM2INT (devminorv);
  Check_Type (pathv, T_STRING);
  const char *path = StringValueCStr (pathv);
  if (!path)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "path", "mknod");

  int r;

  r = guestfs_mknod (g, mode, devmajor, devminor, path);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

static VALUE ruby_guestfs_mkfifo (VALUE gv, VALUE modev, VALUE pathv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "mkfifo");

  int mode = NUM2INT (modev);
  Check_Type (pathv, T_STRING);
  const char *path = StringValueCStr (pathv);
  if (!path)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "path", "mkfifo");

  int r;

  r = guestfs_mkfifo (g, mode, path);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

static VALUE ruby_guestfs_mknod_b (VALUE gv, VALUE modev, VALUE devmajorv, VALUE devminorv, VALUE pathv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "mknod_b");

  int mode = NUM2INT (modev);
  int devmajor = NUM2INT (devmajorv);
  int devminor = NUM2INT (devminorv);
  Check_Type (pathv, T_STRING);
  const char *path = StringValueCStr (pathv);
  if (!path)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "path", "mknod_b");

  int r;

  r = guestfs_mknod_b (g, mode, devmajor, devminor, path);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

static VALUE ruby_guestfs_mknod_c (VALUE gv, VALUE modev, VALUE devmajorv, VALUE devminorv, VALUE pathv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "mknod_c");

  int mode = NUM2INT (modev);
  int devmajor = NUM2INT (devmajorv);
  int devminor = NUM2INT (devminorv);
  Check_Type (pathv, T_STRING);
  const char *path = StringValueCStr (pathv);
  if (!path)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "path", "mknod_c");

  int r;

  r = guestfs_mknod_c (g, mode, devmajor, devminor, path);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

static VALUE ruby_guestfs_umask (VALUE gv, VALUE maskv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "umask");

  int mask = NUM2INT (maskv);

  int r;

  r = guestfs_umask (g, mask);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return INT2NUM (r);
}

static VALUE ruby_guestfs_readdir (VALUE gv, VALUE dirv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "readdir");

  Check_Type (dirv, T_STRING);
  const char *dir = StringValueCStr (dirv);
  if (!dir)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "dir", "readdir");

  struct guestfs_dirent_list *r;

  r = guestfs_readdir (g, dir);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  VALUE rv = rb_ary_new2 (r->len);
  int i;
  for (i = 0; i < r->len; ++i) {
    VALUE hv = rb_hash_new ();
    rb_hash_aset (hv, rb_str_new2 ("ino"), LL2NUM (r->val[i].ino));
    rb_hash_aset (hv, rb_str_new2 ("ftyp"), ULL2NUM (r->val[i].ftyp));
    rb_hash_aset (hv, rb_str_new2 ("name"), rb_str_new2 (r->val[i].name));
    rb_ary_push (rv, hv);
  }
  guestfs_free_dirent_list (r);
  return rv;
}

static VALUE ruby_guestfs_sfdiskM (VALUE gv, VALUE devicev, VALUE linesv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "sfdiskM");

  Check_Type (devicev, T_STRING);
  const char *device = StringValueCStr (devicev);
  if (!device)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "device", "sfdiskM");
  char **lines;
  Check_Type (linesv, T_ARRAY);
  {
    int i, len;
    len = RARRAY_LEN (linesv);
    lines = guestfs_safe_malloc (g, sizeof (char *) * (len+1));
    for (i = 0; i < len; ++i) {
      VALUE v = rb_ary_entry (linesv, i);
      lines[i] = StringValueCStr (v);
    }
    lines[len] = NULL;
  }

  int r;

  r = guestfs_sfdiskM (g, device, lines);
  free (lines);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

static VALUE ruby_guestfs_zfile (VALUE gv, VALUE methv, VALUE pathv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "zfile");

  Check_Type (methv, T_STRING);
  const char *meth = StringValueCStr (methv);
  if (!meth)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "meth", "zfile");
  Check_Type (pathv, T_STRING);
  const char *path = StringValueCStr (pathv);
  if (!path)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "path", "zfile");

  char *r;

  r = guestfs_zfile (g, meth, path);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  VALUE rv = rb_str_new2 (r);
  free (r);
  return rv;
}

static VALUE ruby_guestfs_getxattrs (VALUE gv, VALUE pathv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "getxattrs");

  Check_Type (pathv, T_STRING);
  const char *path = StringValueCStr (pathv);
  if (!path)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "path", "getxattrs");

  struct guestfs_xattr_list *r;

  r = guestfs_getxattrs (g, path);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  VALUE rv = rb_ary_new2 (r->len);
  int i;
  for (i = 0; i < r->len; ++i) {
    VALUE hv = rb_hash_new ();
    rb_hash_aset (hv, rb_str_new2 ("attrname"), rb_str_new2 (r->val[i].attrname));
    rb_hash_aset (hv, rb_str_new2 ("attrval"), rb_str_new (r->val[i].attrval, r->val[i].attrval_len));
    rb_ary_push (rv, hv);
  }
  guestfs_free_xattr_list (r);
  return rv;
}

static VALUE ruby_guestfs_lgetxattrs (VALUE gv, VALUE pathv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "lgetxattrs");

  Check_Type (pathv, T_STRING);
  const char *path = StringValueCStr (pathv);
  if (!path)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "path", "lgetxattrs");

  struct guestfs_xattr_list *r;

  r = guestfs_lgetxattrs (g, path);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  VALUE rv = rb_ary_new2 (r->len);
  int i;
  for (i = 0; i < r->len; ++i) {
    VALUE hv = rb_hash_new ();
    rb_hash_aset (hv, rb_str_new2 ("attrname"), rb_str_new2 (r->val[i].attrname));
    rb_hash_aset (hv, rb_str_new2 ("attrval"), rb_str_new (r->val[i].attrval, r->val[i].attrval_len));
    rb_ary_push (rv, hv);
  }
  guestfs_free_xattr_list (r);
  return rv;
}

static VALUE ruby_guestfs_setxattr (VALUE gv, VALUE xattrv, VALUE valv, VALUE vallenv, VALUE pathv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "setxattr");

  Check_Type (xattrv, T_STRING);
  const char *xattr = StringValueCStr (xattrv);
  if (!xattr)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "xattr", "setxattr");
  Check_Type (valv, T_STRING);
  const char *val = StringValueCStr (valv);
  if (!val)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "val", "setxattr");
  int vallen = NUM2INT (vallenv);
  Check_Type (pathv, T_STRING);
  const char *path = StringValueCStr (pathv);
  if (!path)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "path", "setxattr");

  int r;

  r = guestfs_setxattr (g, xattr, val, vallen, path);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

static VALUE ruby_guestfs_lsetxattr (VALUE gv, VALUE xattrv, VALUE valv, VALUE vallenv, VALUE pathv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "lsetxattr");

  Check_Type (xattrv, T_STRING);
  const char *xattr = StringValueCStr (xattrv);
  if (!xattr)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "xattr", "lsetxattr");
  Check_Type (valv, T_STRING);
  const char *val = StringValueCStr (valv);
  if (!val)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "val", "lsetxattr");
  int vallen = NUM2INT (vallenv);
  Check_Type (pathv, T_STRING);
  const char *path = StringValueCStr (pathv);
  if (!path)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "path", "lsetxattr");

  int r;

  r = guestfs_lsetxattr (g, xattr, val, vallen, path);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

static VALUE ruby_guestfs_removexattr (VALUE gv, VALUE xattrv, VALUE pathv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "removexattr");

  Check_Type (xattrv, T_STRING);
  const char *xattr = StringValueCStr (xattrv);
  if (!xattr)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "xattr", "removexattr");
  Check_Type (pathv, T_STRING);
  const char *path = StringValueCStr (pathv);
  if (!path)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "path", "removexattr");

  int r;

  r = guestfs_removexattr (g, xattr, path);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

static VALUE ruby_guestfs_lremovexattr (VALUE gv, VALUE xattrv, VALUE pathv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "lremovexattr");

  Check_Type (xattrv, T_STRING);
  const char *xattr = StringValueCStr (xattrv);
  if (!xattr)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "xattr", "lremovexattr");
  Check_Type (pathv, T_STRING);
  const char *path = StringValueCStr (pathv);
  if (!path)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "path", "lremovexattr");

  int r;

  r = guestfs_lremovexattr (g, xattr, path);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

static VALUE ruby_guestfs_mountpoints (VALUE gv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "mountpoints");


  char **r;

  r = guestfs_mountpoints (g);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  VALUE rv = rb_hash_new ();
  int i;
  for (i = 0; r[i] != NULL; i+=2) {
    rb_hash_aset (rv, rb_str_new2 (r[i]), rb_str_new2 (r[i+1]));
    free (r[i]);
    free (r[i+1]);
  }
  free (r);
  return rv;
}

static VALUE ruby_guestfs_mkmountpoint (VALUE gv, VALUE exemptpathv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "mkmountpoint");

  Check_Type (exemptpathv, T_STRING);
  const char *exemptpath = StringValueCStr (exemptpathv);
  if (!exemptpath)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "exemptpath", "mkmountpoint");

  int r;

  r = guestfs_mkmountpoint (g, exemptpath);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

static VALUE ruby_guestfs_rmmountpoint (VALUE gv, VALUE exemptpathv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "rmmountpoint");

  Check_Type (exemptpathv, T_STRING);
  const char *exemptpath = StringValueCStr (exemptpathv);
  if (!exemptpath)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "exemptpath", "rmmountpoint");

  int r;

  r = guestfs_rmmountpoint (g, exemptpath);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

static VALUE ruby_guestfs_read_file (VALUE gv, VALUE pathv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "read_file");

  Check_Type (pathv, T_STRING);
  const char *path = StringValueCStr (pathv);
  if (!path)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "path", "read_file");

  char *r;
  size_t size;

  r = guestfs_read_file (g, path, &size);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  VALUE rv = rb_str_new (r, size);
  free (r);
  return rv;
}

static VALUE ruby_guestfs_grep (VALUE gv, VALUE regexv, VALUE pathv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "grep");

  Check_Type (regexv, T_STRING);
  const char *regex = StringValueCStr (regexv);
  if (!regex)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "regex", "grep");
  Check_Type (pathv, T_STRING);
  const char *path = StringValueCStr (pathv);
  if (!path)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "path", "grep");

  char **r;

  r = guestfs_grep (g, regex, path);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  int i, len = 0;
  for (i = 0; r[i] != NULL; ++i) len++;
  VALUE rv = rb_ary_new2 (len);
  for (i = 0; r[i] != NULL; ++i) {
    rb_ary_push (rv, rb_str_new2 (r[i]));
    free (r[i]);
  }
  free (r);
  return rv;
}

static VALUE ruby_guestfs_egrep (VALUE gv, VALUE regexv, VALUE pathv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "egrep");

  Check_Type (regexv, T_STRING);
  const char *regex = StringValueCStr (regexv);
  if (!regex)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "regex", "egrep");
  Check_Type (pathv, T_STRING);
  const char *path = StringValueCStr (pathv);
  if (!path)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "path", "egrep");

  char **r;

  r = guestfs_egrep (g, regex, path);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  int i, len = 0;
  for (i = 0; r[i] != NULL; ++i) len++;
  VALUE rv = rb_ary_new2 (len);
  for (i = 0; r[i] != NULL; ++i) {
    rb_ary_push (rv, rb_str_new2 (r[i]));
    free (r[i]);
  }
  free (r);
  return rv;
}

static VALUE ruby_guestfs_fgrep (VALUE gv, VALUE patternv, VALUE pathv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "fgrep");

  Check_Type (patternv, T_STRING);
  const char *pattern = StringValueCStr (patternv);
  if (!pattern)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "pattern", "fgrep");
  Check_Type (pathv, T_STRING);
  const char *path = StringValueCStr (pathv);
  if (!path)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "path", "fgrep");

  char **r;

  r = guestfs_fgrep (g, pattern, path);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  int i, len = 0;
  for (i = 0; r[i] != NULL; ++i) len++;
  VALUE rv = rb_ary_new2 (len);
  for (i = 0; r[i] != NULL; ++i) {
    rb_ary_push (rv, rb_str_new2 (r[i]));
    free (r[i]);
  }
  free (r);
  return rv;
}

static VALUE ruby_guestfs_grepi (VALUE gv, VALUE regexv, VALUE pathv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "grepi");

  Check_Type (regexv, T_STRING);
  const char *regex = StringValueCStr (regexv);
  if (!regex)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "regex", "grepi");
  Check_Type (pathv, T_STRING);
  const char *path = StringValueCStr (pathv);
  if (!path)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "path", "grepi");

  char **r;

  r = guestfs_grepi (g, regex, path);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  int i, len = 0;
  for (i = 0; r[i] != NULL; ++i) len++;
  VALUE rv = rb_ary_new2 (len);
  for (i = 0; r[i] != NULL; ++i) {
    rb_ary_push (rv, rb_str_new2 (r[i]));
    free (r[i]);
  }
  free (r);
  return rv;
}

static VALUE ruby_guestfs_egrepi (VALUE gv, VALUE regexv, VALUE pathv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "egrepi");

  Check_Type (regexv, T_STRING);
  const char *regex = StringValueCStr (regexv);
  if (!regex)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "regex", "egrepi");
  Check_Type (pathv, T_STRING);
  const char *path = StringValueCStr (pathv);
  if (!path)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "path", "egrepi");

  char **r;

  r = guestfs_egrepi (g, regex, path);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  int i, len = 0;
  for (i = 0; r[i] != NULL; ++i) len++;
  VALUE rv = rb_ary_new2 (len);
  for (i = 0; r[i] != NULL; ++i) {
    rb_ary_push (rv, rb_str_new2 (r[i]));
    free (r[i]);
  }
  free (r);
  return rv;
}

static VALUE ruby_guestfs_fgrepi (VALUE gv, VALUE patternv, VALUE pathv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "fgrepi");

  Check_Type (patternv, T_STRING);
  const char *pattern = StringValueCStr (patternv);
  if (!pattern)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "pattern", "fgrepi");
  Check_Type (pathv, T_STRING);
  const char *path = StringValueCStr (pathv);
  if (!path)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "path", "fgrepi");

  char **r;

  r = guestfs_fgrepi (g, pattern, path);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  int i, len = 0;
  for (i = 0; r[i] != NULL; ++i) len++;
  VALUE rv = rb_ary_new2 (len);
  for (i = 0; r[i] != NULL; ++i) {
    rb_ary_push (rv, rb_str_new2 (r[i]));
    free (r[i]);
  }
  free (r);
  return rv;
}

static VALUE ruby_guestfs_zgrep (VALUE gv, VALUE regexv, VALUE pathv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "zgrep");

  Check_Type (regexv, T_STRING);
  const char *regex = StringValueCStr (regexv);
  if (!regex)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "regex", "zgrep");
  Check_Type (pathv, T_STRING);
  const char *path = StringValueCStr (pathv);
  if (!path)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "path", "zgrep");

  char **r;

  r = guestfs_zgrep (g, regex, path);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  int i, len = 0;
  for (i = 0; r[i] != NULL; ++i) len++;
  VALUE rv = rb_ary_new2 (len);
  for (i = 0; r[i] != NULL; ++i) {
    rb_ary_push (rv, rb_str_new2 (r[i]));
    free (r[i]);
  }
  free (r);
  return rv;
}

static VALUE ruby_guestfs_zegrep (VALUE gv, VALUE regexv, VALUE pathv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "zegrep");

  Check_Type (regexv, T_STRING);
  const char *regex = StringValueCStr (regexv);
  if (!regex)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "regex", "zegrep");
  Check_Type (pathv, T_STRING);
  const char *path = StringValueCStr (pathv);
  if (!path)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "path", "zegrep");

  char **r;

  r = guestfs_zegrep (g, regex, path);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  int i, len = 0;
  for (i = 0; r[i] != NULL; ++i) len++;
  VALUE rv = rb_ary_new2 (len);
  for (i = 0; r[i] != NULL; ++i) {
    rb_ary_push (rv, rb_str_new2 (r[i]));
    free (r[i]);
  }
  free (r);
  return rv;
}

static VALUE ruby_guestfs_zfgrep (VALUE gv, VALUE patternv, VALUE pathv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "zfgrep");

  Check_Type (patternv, T_STRING);
  const char *pattern = StringValueCStr (patternv);
  if (!pattern)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "pattern", "zfgrep");
  Check_Type (pathv, T_STRING);
  const char *path = StringValueCStr (pathv);
  if (!path)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "path", "zfgrep");

  char **r;

  r = guestfs_zfgrep (g, pattern, path);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  int i, len = 0;
  for (i = 0; r[i] != NULL; ++i) len++;
  VALUE rv = rb_ary_new2 (len);
  for (i = 0; r[i] != NULL; ++i) {
    rb_ary_push (rv, rb_str_new2 (r[i]));
    free (r[i]);
  }
  free (r);
  return rv;
}

static VALUE ruby_guestfs_zgrepi (VALUE gv, VALUE regexv, VALUE pathv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "zgrepi");

  Check_Type (regexv, T_STRING);
  const char *regex = StringValueCStr (regexv);
  if (!regex)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "regex", "zgrepi");
  Check_Type (pathv, T_STRING);
  const char *path = StringValueCStr (pathv);
  if (!path)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "path", "zgrepi");

  char **r;

  r = guestfs_zgrepi (g, regex, path);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  int i, len = 0;
  for (i = 0; r[i] != NULL; ++i) len++;
  VALUE rv = rb_ary_new2 (len);
  for (i = 0; r[i] != NULL; ++i) {
    rb_ary_push (rv, rb_str_new2 (r[i]));
    free (r[i]);
  }
  free (r);
  return rv;
}

static VALUE ruby_guestfs_zegrepi (VALUE gv, VALUE regexv, VALUE pathv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "zegrepi");

  Check_Type (regexv, T_STRING);
  const char *regex = StringValueCStr (regexv);
  if (!regex)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "regex", "zegrepi");
  Check_Type (pathv, T_STRING);
  const char *path = StringValueCStr (pathv);
  if (!path)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "path", "zegrepi");

  char **r;

  r = guestfs_zegrepi (g, regex, path);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  int i, len = 0;
  for (i = 0; r[i] != NULL; ++i) len++;
  VALUE rv = rb_ary_new2 (len);
  for (i = 0; r[i] != NULL; ++i) {
    rb_ary_push (rv, rb_str_new2 (r[i]));
    free (r[i]);
  }
  free (r);
  return rv;
}

static VALUE ruby_guestfs_zfgrepi (VALUE gv, VALUE patternv, VALUE pathv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "zfgrepi");

  Check_Type (patternv, T_STRING);
  const char *pattern = StringValueCStr (patternv);
  if (!pattern)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "pattern", "zfgrepi");
  Check_Type (pathv, T_STRING);
  const char *path = StringValueCStr (pathv);
  if (!path)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "path", "zfgrepi");

  char **r;

  r = guestfs_zfgrepi (g, pattern, path);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  int i, len = 0;
  for (i = 0; r[i] != NULL; ++i) len++;
  VALUE rv = rb_ary_new2 (len);
  for (i = 0; r[i] != NULL; ++i) {
    rb_ary_push (rv, rb_str_new2 (r[i]));
    free (r[i]);
  }
  free (r);
  return rv;
}

static VALUE ruby_guestfs_realpath (VALUE gv, VALUE pathv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "realpath");

  Check_Type (pathv, T_STRING);
  const char *path = StringValueCStr (pathv);
  if (!path)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "path", "realpath");

  char *r;

  r = guestfs_realpath (g, path);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  VALUE rv = rb_str_new2 (r);
  free (r);
  return rv;
}

static VALUE ruby_guestfs_ln (VALUE gv, VALUE targetv, VALUE linknamev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "ln");

  Check_Type (targetv, T_STRING);
  const char *target = StringValueCStr (targetv);
  if (!target)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "target", "ln");
  Check_Type (linknamev, T_STRING);
  const char *linkname = StringValueCStr (linknamev);
  if (!linkname)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "linkname", "ln");

  int r;

  r = guestfs_ln (g, target, linkname);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

static VALUE ruby_guestfs_ln_f (VALUE gv, VALUE targetv, VALUE linknamev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "ln_f");

  Check_Type (targetv, T_STRING);
  const char *target = StringValueCStr (targetv);
  if (!target)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "target", "ln_f");
  Check_Type (linknamev, T_STRING);
  const char *linkname = StringValueCStr (linknamev);
  if (!linkname)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "linkname", "ln_f");

  int r;

  r = guestfs_ln_f (g, target, linkname);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

static VALUE ruby_guestfs_ln_s (VALUE gv, VALUE targetv, VALUE linknamev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "ln_s");

  Check_Type (targetv, T_STRING);
  const char *target = StringValueCStr (targetv);
  if (!target)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "target", "ln_s");
  Check_Type (linknamev, T_STRING);
  const char *linkname = StringValueCStr (linknamev);
  if (!linkname)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "linkname", "ln_s");

  int r;

  r = guestfs_ln_s (g, target, linkname);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

static VALUE ruby_guestfs_ln_sf (VALUE gv, VALUE targetv, VALUE linknamev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "ln_sf");

  Check_Type (targetv, T_STRING);
  const char *target = StringValueCStr (targetv);
  if (!target)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "target", "ln_sf");
  Check_Type (linknamev, T_STRING);
  const char *linkname = StringValueCStr (linknamev);
  if (!linkname)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "linkname", "ln_sf");

  int r;

  r = guestfs_ln_sf (g, target, linkname);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

static VALUE ruby_guestfs_readlink (VALUE gv, VALUE pathv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "readlink");

  Check_Type (pathv, T_STRING);
  const char *path = StringValueCStr (pathv);
  if (!path)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "path", "readlink");

  char *r;

  r = guestfs_readlink (g, path);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  VALUE rv = rb_str_new2 (r);
  free (r);
  return rv;
}

static VALUE ruby_guestfs_fallocate (VALUE gv, VALUE pathv, VALUE lenv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "fallocate");

  Check_Type (pathv, T_STRING);
  const char *path = StringValueCStr (pathv);
  if (!path)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "path", "fallocate");
  int len = NUM2INT (lenv);

  int r;

  r = guestfs_fallocate (g, path, len);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

static VALUE ruby_guestfs_swapon_device (VALUE gv, VALUE devicev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "swapon_device");

  Check_Type (devicev, T_STRING);
  const char *device = StringValueCStr (devicev);
  if (!device)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "device", "swapon_device");

  int r;

  r = guestfs_swapon_device (g, device);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

static VALUE ruby_guestfs_swapoff_device (VALUE gv, VALUE devicev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "swapoff_device");

  Check_Type (devicev, T_STRING);
  const char *device = StringValueCStr (devicev);
  if (!device)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "device", "swapoff_device");

  int r;

  r = guestfs_swapoff_device (g, device);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

static VALUE ruby_guestfs_swapon_file (VALUE gv, VALUE filev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "swapon_file");

  Check_Type (filev, T_STRING);
  const char *file = StringValueCStr (filev);
  if (!file)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "file", "swapon_file");

  int r;

  r = guestfs_swapon_file (g, file);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

static VALUE ruby_guestfs_swapoff_file (VALUE gv, VALUE filev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "swapoff_file");

  Check_Type (filev, T_STRING);
  const char *file = StringValueCStr (filev);
  if (!file)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "file", "swapoff_file");

  int r;

  r = guestfs_swapoff_file (g, file);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

static VALUE ruby_guestfs_swapon_label (VALUE gv, VALUE labelv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "swapon_label");

  Check_Type (labelv, T_STRING);
  const char *label = StringValueCStr (labelv);
  if (!label)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "label", "swapon_label");

  int r;

  r = guestfs_swapon_label (g, label);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

static VALUE ruby_guestfs_swapoff_label (VALUE gv, VALUE labelv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "swapoff_label");

  Check_Type (labelv, T_STRING);
  const char *label = StringValueCStr (labelv);
  if (!label)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "label", "swapoff_label");

  int r;

  r = guestfs_swapoff_label (g, label);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

static VALUE ruby_guestfs_swapon_uuid (VALUE gv, VALUE uuidv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "swapon_uuid");

  Check_Type (uuidv, T_STRING);
  const char *uuid = StringValueCStr (uuidv);
  if (!uuid)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "uuid", "swapon_uuid");

  int r;

  r = guestfs_swapon_uuid (g, uuid);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

static VALUE ruby_guestfs_swapoff_uuid (VALUE gv, VALUE uuidv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "swapoff_uuid");

  Check_Type (uuidv, T_STRING);
  const char *uuid = StringValueCStr (uuidv);
  if (!uuid)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "uuid", "swapoff_uuid");

  int r;

  r = guestfs_swapoff_uuid (g, uuid);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

static VALUE ruby_guestfs_mkswap_file (VALUE gv, VALUE pathv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "mkswap_file");

  Check_Type (pathv, T_STRING);
  const char *path = StringValueCStr (pathv);
  if (!path)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "path", "mkswap_file");

  int r;

  r = guestfs_mkswap_file (g, path);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

static VALUE ruby_guestfs_inotify_init (VALUE gv, VALUE maxeventsv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "inotify_init");

  int maxevents = NUM2INT (maxeventsv);

  int r;

  r = guestfs_inotify_init (g, maxevents);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

static VALUE ruby_guestfs_inotify_add_watch (VALUE gv, VALUE pathv, VALUE maskv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "inotify_add_watch");

  Check_Type (pathv, T_STRING);
  const char *path = StringValueCStr (pathv);
  if (!path)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "path", "inotify_add_watch");
  int mask = NUM2INT (maskv);

  int64_t r;

  r = guestfs_inotify_add_watch (g, path, mask);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return ULL2NUM (r);
}

static VALUE ruby_guestfs_inotify_rm_watch (VALUE gv, VALUE wdv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "inotify_rm_watch");

  int wd = NUM2INT (wdv);

  int r;

  r = guestfs_inotify_rm_watch (g, wd);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

static VALUE ruby_guestfs_inotify_read (VALUE gv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "inotify_read");


  struct guestfs_inotify_event_list *r;

  r = guestfs_inotify_read (g);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  VALUE rv = rb_ary_new2 (r->len);
  int i;
  for (i = 0; i < r->len; ++i) {
    VALUE hv = rb_hash_new ();
    rb_hash_aset (hv, rb_str_new2 ("in_wd"), LL2NUM (r->val[i].in_wd));
    rb_hash_aset (hv, rb_str_new2 ("in_mask"), UINT2NUM (r->val[i].in_mask));
    rb_hash_aset (hv, rb_str_new2 ("in_cookie"), UINT2NUM (r->val[i].in_cookie));
    rb_hash_aset (hv, rb_str_new2 ("in_name"), rb_str_new2 (r->val[i].in_name));
    rb_ary_push (rv, hv);
  }
  guestfs_free_inotify_event_list (r);
  return rv;
}

static VALUE ruby_guestfs_inotify_files (VALUE gv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "inotify_files");


  char **r;

  r = guestfs_inotify_files (g);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  int i, len = 0;
  for (i = 0; r[i] != NULL; ++i) len++;
  VALUE rv = rb_ary_new2 (len);
  for (i = 0; r[i] != NULL; ++i) {
    rb_ary_push (rv, rb_str_new2 (r[i]));
    free (r[i]);
  }
  free (r);
  return rv;
}

static VALUE ruby_guestfs_inotify_close (VALUE gv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "inotify_close");


  int r;

  r = guestfs_inotify_close (g);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

static VALUE ruby_guestfs_setcon (VALUE gv, VALUE contextv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "setcon");

  Check_Type (contextv, T_STRING);
  const char *context = StringValueCStr (contextv);
  if (!context)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "context", "setcon");

  int r;

  r = guestfs_setcon (g, context);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

static VALUE ruby_guestfs_getcon (VALUE gv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "getcon");


  char *r;

  r = guestfs_getcon (g);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  VALUE rv = rb_str_new2 (r);
  free (r);
  return rv;
}

static VALUE ruby_guestfs_mkfs_b (VALUE gv, VALUE fstypev, VALUE blocksizev, VALUE devicev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "mkfs_b");

  Check_Type (fstypev, T_STRING);
  const char *fstype = StringValueCStr (fstypev);
  if (!fstype)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "fstype", "mkfs_b");
  int blocksize = NUM2INT (blocksizev);
  Check_Type (devicev, T_STRING);
  const char *device = StringValueCStr (devicev);
  if (!device)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "device", "mkfs_b");

  int r;

  r = guestfs_mkfs_b (g, fstype, blocksize, device);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

static VALUE ruby_guestfs_mke2journal (VALUE gv, VALUE blocksizev, VALUE devicev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "mke2journal");

  int blocksize = NUM2INT (blocksizev);
  Check_Type (devicev, T_STRING);
  const char *device = StringValueCStr (devicev);
  if (!device)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "device", "mke2journal");

  int r;

  r = guestfs_mke2journal (g, blocksize, device);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

static VALUE ruby_guestfs_mke2journal_L (VALUE gv, VALUE blocksizev, VALUE labelv, VALUE devicev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "mke2journal_L");

  int blocksize = NUM2INT (blocksizev);
  Check_Type (labelv, T_STRING);
  const char *label = StringValueCStr (labelv);
  if (!label)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "label", "mke2journal_L");
  Check_Type (devicev, T_STRING);
  const char *device = StringValueCStr (devicev);
  if (!device)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "device", "mke2journal_L");

  int r;

  r = guestfs_mke2journal_L (g, blocksize, label, device);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

static VALUE ruby_guestfs_mke2journal_U (VALUE gv, VALUE blocksizev, VALUE uuidv, VALUE devicev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "mke2journal_U");

  int blocksize = NUM2INT (blocksizev);
  Check_Type (uuidv, T_STRING);
  const char *uuid = StringValueCStr (uuidv);
  if (!uuid)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "uuid", "mke2journal_U");
  Check_Type (devicev, T_STRING);
  const char *device = StringValueCStr (devicev);
  if (!device)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "device", "mke2journal_U");

  int r;

  r = guestfs_mke2journal_U (g, blocksize, uuid, device);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

static VALUE ruby_guestfs_mke2fs_J (VALUE gv, VALUE fstypev, VALUE blocksizev, VALUE devicev, VALUE journalv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "mke2fs_J");

  Check_Type (fstypev, T_STRING);
  const char *fstype = StringValueCStr (fstypev);
  if (!fstype)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "fstype", "mke2fs_J");
  int blocksize = NUM2INT (blocksizev);
  Check_Type (devicev, T_STRING);
  const char *device = StringValueCStr (devicev);
  if (!device)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "device", "mke2fs_J");
  Check_Type (journalv, T_STRING);
  const char *journal = StringValueCStr (journalv);
  if (!journal)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "journal", "mke2fs_J");

  int r;

  r = guestfs_mke2fs_J (g, fstype, blocksize, device, journal);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

static VALUE ruby_guestfs_mke2fs_JL (VALUE gv, VALUE fstypev, VALUE blocksizev, VALUE devicev, VALUE labelv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "mke2fs_JL");

  Check_Type (fstypev, T_STRING);
  const char *fstype = StringValueCStr (fstypev);
  if (!fstype)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "fstype", "mke2fs_JL");
  int blocksize = NUM2INT (blocksizev);
  Check_Type (devicev, T_STRING);
  const char *device = StringValueCStr (devicev);
  if (!device)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "device", "mke2fs_JL");
  Check_Type (labelv, T_STRING);
  const char *label = StringValueCStr (labelv);
  if (!label)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "label", "mke2fs_JL");

  int r;

  r = guestfs_mke2fs_JL (g, fstype, blocksize, device, label);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

static VALUE ruby_guestfs_mke2fs_JU (VALUE gv, VALUE fstypev, VALUE blocksizev, VALUE devicev, VALUE uuidv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "mke2fs_JU");

  Check_Type (fstypev, T_STRING);
  const char *fstype = StringValueCStr (fstypev);
  if (!fstype)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "fstype", "mke2fs_JU");
  int blocksize = NUM2INT (blocksizev);
  Check_Type (devicev, T_STRING);
  const char *device = StringValueCStr (devicev);
  if (!device)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "device", "mke2fs_JU");
  Check_Type (uuidv, T_STRING);
  const char *uuid = StringValueCStr (uuidv);
  if (!uuid)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "uuid", "mke2fs_JU");

  int r;

  r = guestfs_mke2fs_JU (g, fstype, blocksize, device, uuid);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

static VALUE ruby_guestfs_modprobe (VALUE gv, VALUE modulenamev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "modprobe");

  Check_Type (modulenamev, T_STRING);
  const char *modulename = StringValueCStr (modulenamev);
  if (!modulename)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "modulename", "modprobe");

  int r;

  r = guestfs_modprobe (g, modulename);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

static VALUE ruby_guestfs_echo_daemon (VALUE gv, VALUE wordsv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "echo_daemon");

  char **words;
  Check_Type (wordsv, T_ARRAY);
  {
    int i, len;
    len = RARRAY_LEN (wordsv);
    words = guestfs_safe_malloc (g, sizeof (char *) * (len+1));
    for (i = 0; i < len; ++i) {
      VALUE v = rb_ary_entry (wordsv, i);
      words[i] = StringValueCStr (v);
    }
    words[len] = NULL;
  }

  char *r;

  r = guestfs_echo_daemon (g, words);
  free (words);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  VALUE rv = rb_str_new2 (r);
  free (r);
  return rv;
}

static VALUE ruby_guestfs_find0 (VALUE gv, VALUE directoryv, VALUE filesv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "find0");

  Check_Type (directoryv, T_STRING);
  const char *directory = StringValueCStr (directoryv);
  if (!directory)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "directory", "find0");
  Check_Type (filesv, T_STRING);
  const char *files = StringValueCStr (filesv);
  if (!files)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "files", "find0");

  int r;

  r = guestfs_find0 (g, directory, files);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

static VALUE ruby_guestfs_case_sensitive_path (VALUE gv, VALUE pathv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "case_sensitive_path");

  Check_Type (pathv, T_STRING);
  const char *path = StringValueCStr (pathv);
  if (!path)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "path", "case_sensitive_path");

  char *r;

  r = guestfs_case_sensitive_path (g, path);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  VALUE rv = rb_str_new2 (r);
  free (r);
  return rv;
}

static VALUE ruby_guestfs_vfs_type (VALUE gv, VALUE devicev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "vfs_type");

  Check_Type (devicev, T_STRING);
  const char *device = StringValueCStr (devicev);
  if (!device)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "device", "vfs_type");

  char *r;

  r = guestfs_vfs_type (g, device);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  VALUE rv = rb_str_new2 (r);
  free (r);
  return rv;
}

static VALUE ruby_guestfs_truncate (VALUE gv, VALUE pathv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "truncate");

  Check_Type (pathv, T_STRING);
  const char *path = StringValueCStr (pathv);
  if (!path)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "path", "truncate");

  int r;

  r = guestfs_truncate (g, path);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

static VALUE ruby_guestfs_truncate_size (VALUE gv, VALUE pathv, VALUE sizev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "truncate_size");

  Check_Type (pathv, T_STRING);
  const char *path = StringValueCStr (pathv);
  if (!path)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "path", "truncate_size");
  long long size = NUM2LL (sizev);

  int r;

  r = guestfs_truncate_size (g, path, size);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

static VALUE ruby_guestfs_utimens (VALUE gv, VALUE pathv, VALUE atsecsv, VALUE atnsecsv, VALUE mtsecsv, VALUE mtnsecsv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "utimens");

  Check_Type (pathv, T_STRING);
  const char *path = StringValueCStr (pathv);
  if (!path)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "path", "utimens");
  long long atsecs = NUM2LL (atsecsv);
  long long atnsecs = NUM2LL (atnsecsv);
  long long mtsecs = NUM2LL (mtsecsv);
  long long mtnsecs = NUM2LL (mtnsecsv);

  int r;

  r = guestfs_utimens (g, path, atsecs, atnsecs, mtsecs, mtnsecs);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

static VALUE ruby_guestfs_mkdir_mode (VALUE gv, VALUE pathv, VALUE modev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "mkdir_mode");

  Check_Type (pathv, T_STRING);
  const char *path = StringValueCStr (pathv);
  if (!path)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "path", "mkdir_mode");
  int mode = NUM2INT (modev);

  int r;

  r = guestfs_mkdir_mode (g, path, mode);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

static VALUE ruby_guestfs_lchown (VALUE gv, VALUE ownerv, VALUE groupv, VALUE pathv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "lchown");

  int owner = NUM2INT (ownerv);
  int group = NUM2INT (groupv);
  Check_Type (pathv, T_STRING);
  const char *path = StringValueCStr (pathv);
  if (!path)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "path", "lchown");

  int r;

  r = guestfs_lchown (g, owner, group, path);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

static VALUE ruby_guestfs_lstatlist (VALUE gv, VALUE pathv, VALUE namesv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "lstatlist");

  Check_Type (pathv, T_STRING);
  const char *path = StringValueCStr (pathv);
  if (!path)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "path", "lstatlist");
  char **names;
  Check_Type (namesv, T_ARRAY);
  {
    int i, len;
    len = RARRAY_LEN (namesv);
    names = guestfs_safe_malloc (g, sizeof (char *) * (len+1));
    for (i = 0; i < len; ++i) {
      VALUE v = rb_ary_entry (namesv, i);
      names[i] = StringValueCStr (v);
    }
    names[len] = NULL;
  }

  struct guestfs_stat_list *r;

  r = guestfs_lstatlist (g, path, names);
  free (names);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  VALUE rv = rb_ary_new2 (r->len);
  int i;
  for (i = 0; i < r->len; ++i) {
    VALUE hv = rb_hash_new ();
    rb_hash_aset (hv, rb_str_new2 ("dev"), LL2NUM (r->val[i].dev));
    rb_hash_aset (hv, rb_str_new2 ("ino"), LL2NUM (r->val[i].ino));
    rb_hash_aset (hv, rb_str_new2 ("mode"), LL2NUM (r->val[i].mode));
    rb_hash_aset (hv, rb_str_new2 ("nlink"), LL2NUM (r->val[i].nlink));
    rb_hash_aset (hv, rb_str_new2 ("uid"), LL2NUM (r->val[i].uid));
    rb_hash_aset (hv, rb_str_new2 ("gid"), LL2NUM (r->val[i].gid));
    rb_hash_aset (hv, rb_str_new2 ("rdev"), LL2NUM (r->val[i].rdev));
    rb_hash_aset (hv, rb_str_new2 ("size"), LL2NUM (r->val[i].size));
    rb_hash_aset (hv, rb_str_new2 ("blksize"), LL2NUM (r->val[i].blksize));
    rb_hash_aset (hv, rb_str_new2 ("blocks"), LL2NUM (r->val[i].blocks));
    rb_hash_aset (hv, rb_str_new2 ("atime"), LL2NUM (r->val[i].atime));
    rb_hash_aset (hv, rb_str_new2 ("mtime"), LL2NUM (r->val[i].mtime));
    rb_hash_aset (hv, rb_str_new2 ("ctime"), LL2NUM (r->val[i].ctime));
    rb_ary_push (rv, hv);
  }
  guestfs_free_stat_list (r);
  return rv;
}

static VALUE ruby_guestfs_lxattrlist (VALUE gv, VALUE pathv, VALUE namesv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "lxattrlist");

  Check_Type (pathv, T_STRING);
  const char *path = StringValueCStr (pathv);
  if (!path)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "path", "lxattrlist");
  char **names;
  Check_Type (namesv, T_ARRAY);
  {
    int i, len;
    len = RARRAY_LEN (namesv);
    names = guestfs_safe_malloc (g, sizeof (char *) * (len+1));
    for (i = 0; i < len; ++i) {
      VALUE v = rb_ary_entry (namesv, i);
      names[i] = StringValueCStr (v);
    }
    names[len] = NULL;
  }

  struct guestfs_xattr_list *r;

  r = guestfs_lxattrlist (g, path, names);
  free (names);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  VALUE rv = rb_ary_new2 (r->len);
  int i;
  for (i = 0; i < r->len; ++i) {
    VALUE hv = rb_hash_new ();
    rb_hash_aset (hv, rb_str_new2 ("attrname"), rb_str_new2 (r->val[i].attrname));
    rb_hash_aset (hv, rb_str_new2 ("attrval"), rb_str_new (r->val[i].attrval, r->val[i].attrval_len));
    rb_ary_push (rv, hv);
  }
  guestfs_free_xattr_list (r);
  return rv;
}

static VALUE ruby_guestfs_readlinklist (VALUE gv, VALUE pathv, VALUE namesv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "readlinklist");

  Check_Type (pathv, T_STRING);
  const char *path = StringValueCStr (pathv);
  if (!path)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "path", "readlinklist");
  char **names;
  Check_Type (namesv, T_ARRAY);
  {
    int i, len;
    len = RARRAY_LEN (namesv);
    names = guestfs_safe_malloc (g, sizeof (char *) * (len+1));
    for (i = 0; i < len; ++i) {
      VALUE v = rb_ary_entry (namesv, i);
      names[i] = StringValueCStr (v);
    }
    names[len] = NULL;
  }

  char **r;

  r = guestfs_readlinklist (g, path, names);
  free (names);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  int i, len = 0;
  for (i = 0; r[i] != NULL; ++i) len++;
  VALUE rv = rb_ary_new2 (len);
  for (i = 0; r[i] != NULL; ++i) {
    rb_ary_push (rv, rb_str_new2 (r[i]));
    free (r[i]);
  }
  free (r);
  return rv;
}

static VALUE ruby_guestfs_pread (VALUE gv, VALUE pathv, VALUE countv, VALUE offsetv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "pread");

  Check_Type (pathv, T_STRING);
  const char *path = StringValueCStr (pathv);
  if (!path)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "path", "pread");
  int count = NUM2INT (countv);
  long long offset = NUM2LL (offsetv);

  char *r;
  size_t size;

  r = guestfs_pread (g, path, count, offset, &size);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  VALUE rv = rb_str_new (r, size);
  free (r);
  return rv;
}

static VALUE ruby_guestfs_part_init (VALUE gv, VALUE devicev, VALUE parttypev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "part_init");

  Check_Type (devicev, T_STRING);
  const char *device = StringValueCStr (devicev);
  if (!device)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "device", "part_init");
  Check_Type (parttypev, T_STRING);
  const char *parttype = StringValueCStr (parttypev);
  if (!parttype)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "parttype", "part_init");

  int r;

  r = guestfs_part_init (g, device, parttype);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

static VALUE ruby_guestfs_part_add (VALUE gv, VALUE devicev, VALUE prlogexv, VALUE startsectv, VALUE endsectv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "part_add");

  Check_Type (devicev, T_STRING);
  const char *device = StringValueCStr (devicev);
  if (!device)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "device", "part_add");
  Check_Type (prlogexv, T_STRING);
  const char *prlogex = StringValueCStr (prlogexv);
  if (!prlogex)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "prlogex", "part_add");
  long long startsect = NUM2LL (startsectv);
  long long endsect = NUM2LL (endsectv);

  int r;

  r = guestfs_part_add (g, device, prlogex, startsect, endsect);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

static VALUE ruby_guestfs_part_disk (VALUE gv, VALUE devicev, VALUE parttypev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "part_disk");

  Check_Type (devicev, T_STRING);
  const char *device = StringValueCStr (devicev);
  if (!device)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "device", "part_disk");
  Check_Type (parttypev, T_STRING);
  const char *parttype = StringValueCStr (parttypev);
  if (!parttype)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "parttype", "part_disk");

  int r;

  r = guestfs_part_disk (g, device, parttype);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

static VALUE ruby_guestfs_part_set_bootable (VALUE gv, VALUE devicev, VALUE partnumv, VALUE bootablev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "part_set_bootable");

  Check_Type (devicev, T_STRING);
  const char *device = StringValueCStr (devicev);
  if (!device)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "device", "part_set_bootable");
  int partnum = NUM2INT (partnumv);
  int bootable = RTEST (bootablev);

  int r;

  r = guestfs_part_set_bootable (g, device, partnum, bootable);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

static VALUE ruby_guestfs_part_set_name (VALUE gv, VALUE devicev, VALUE partnumv, VALUE namev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "part_set_name");

  Check_Type (devicev, T_STRING);
  const char *device = StringValueCStr (devicev);
  if (!device)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "device", "part_set_name");
  int partnum = NUM2INT (partnumv);
  Check_Type (namev, T_STRING);
  const char *name = StringValueCStr (namev);
  if (!name)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "name", "part_set_name");

  int r;

  r = guestfs_part_set_name (g, device, partnum, name);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

static VALUE ruby_guestfs_part_list (VALUE gv, VALUE devicev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "part_list");

  Check_Type (devicev, T_STRING);
  const char *device = StringValueCStr (devicev);
  if (!device)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "device", "part_list");

  struct guestfs_partition_list *r;

  r = guestfs_part_list (g, device);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  VALUE rv = rb_ary_new2 (r->len);
  int i;
  for (i = 0; i < r->len; ++i) {
    VALUE hv = rb_hash_new ();
    rb_hash_aset (hv, rb_str_new2 ("part_num"), INT2NUM (r->val[i].part_num));
    rb_hash_aset (hv, rb_str_new2 ("part_start"), ULL2NUM (r->val[i].part_start));
    rb_hash_aset (hv, rb_str_new2 ("part_end"), ULL2NUM (r->val[i].part_end));
    rb_hash_aset (hv, rb_str_new2 ("part_size"), ULL2NUM (r->val[i].part_size));
    rb_ary_push (rv, hv);
  }
  guestfs_free_partition_list (r);
  return rv;
}

static VALUE ruby_guestfs_part_get_parttype (VALUE gv, VALUE devicev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "part_get_parttype");

  Check_Type (devicev, T_STRING);
  const char *device = StringValueCStr (devicev);
  if (!device)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "device", "part_get_parttype");

  char *r;

  r = guestfs_part_get_parttype (g, device);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  VALUE rv = rb_str_new2 (r);
  free (r);
  return rv;
}

static VALUE ruby_guestfs_fill (VALUE gv, VALUE cv, VALUE lenv, VALUE pathv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "fill");

  int c = NUM2INT (cv);
  int len = NUM2INT (lenv);
  Check_Type (pathv, T_STRING);
  const char *path = StringValueCStr (pathv);
  if (!path)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "path", "fill");

  int r;

  r = guestfs_fill (g, c, len, path);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

static VALUE ruby_guestfs_available (VALUE gv, VALUE groupsv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "available");

  char **groups;
  Check_Type (groupsv, T_ARRAY);
  {
    int i, len;
    len = RARRAY_LEN (groupsv);
    groups = guestfs_safe_malloc (g, sizeof (char *) * (len+1));
    for (i = 0; i < len; ++i) {
      VALUE v = rb_ary_entry (groupsv, i);
      groups[i] = StringValueCStr (v);
    }
    groups[len] = NULL;
  }

  int r;

  r = guestfs_available (g, groups);
  free (groups);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

static VALUE ruby_guestfs_dd (VALUE gv, VALUE srcv, VALUE destv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "dd");

  Check_Type (srcv, T_STRING);
  const char *src = StringValueCStr (srcv);
  if (!src)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "src", "dd");
  Check_Type (destv, T_STRING);
  const char *dest = StringValueCStr (destv);
  if (!dest)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "dest", "dd");

  int r;

  r = guestfs_dd (g, src, dest);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

static VALUE ruby_guestfs_filesize (VALUE gv, VALUE filev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "filesize");

  Check_Type (filev, T_STRING);
  const char *file = StringValueCStr (filev);
  if (!file)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "file", "filesize");

  int64_t r;

  r = guestfs_filesize (g, file);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return ULL2NUM (r);
}

static VALUE ruby_guestfs_lvrename (VALUE gv, VALUE logvolv, VALUE newlogvolv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "lvrename");

  Check_Type (logvolv, T_STRING);
  const char *logvol = StringValueCStr (logvolv);
  if (!logvol)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "logvol", "lvrename");
  Check_Type (newlogvolv, T_STRING);
  const char *newlogvol = StringValueCStr (newlogvolv);
  if (!newlogvol)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "newlogvol", "lvrename");

  int r;

  r = guestfs_lvrename (g, logvol, newlogvol);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

static VALUE ruby_guestfs_vgrename (VALUE gv, VALUE volgroupv, VALUE newvolgroupv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "vgrename");

  Check_Type (volgroupv, T_STRING);
  const char *volgroup = StringValueCStr (volgroupv);
  if (!volgroup)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "volgroup", "vgrename");
  Check_Type (newvolgroupv, T_STRING);
  const char *newvolgroup = StringValueCStr (newvolgroupv);
  if (!newvolgroup)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "newvolgroup", "vgrename");

  int r;

  r = guestfs_vgrename (g, volgroup, newvolgroup);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

static VALUE ruby_guestfs_initrd_cat (VALUE gv, VALUE initrdpathv, VALUE filenamev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "initrd_cat");

  Check_Type (initrdpathv, T_STRING);
  const char *initrdpath = StringValueCStr (initrdpathv);
  if (!initrdpath)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "initrdpath", "initrd_cat");
  Check_Type (filenamev, T_STRING);
  const char *filename = StringValueCStr (filenamev);
  if (!filename)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "filename", "initrd_cat");

  char *r;
  size_t size;

  r = guestfs_initrd_cat (g, initrdpath, filename, &size);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  VALUE rv = rb_str_new (r, size);
  free (r);
  return rv;
}

/* Initialize the module. */
void Init__guestfs ()
{
  m_guestfs = rb_define_module ("Guestfs");
  c_guestfs = rb_define_class_under (m_guestfs, "Guestfs", rb_cObject);
  e_Error = rb_define_class_under (m_guestfs, "Error", rb_eStandardError);

  rb_define_module_function (m_guestfs, "create", ruby_guestfs_create, 0);
  rb_define_method (c_guestfs, "close", ruby_guestfs_close, 0);

  rb_define_method (c_guestfs, "test0",
        ruby_guestfs_test0, 8);
  rb_define_method (c_guestfs, "test0rint",
        ruby_guestfs_test0rint, 1);
  rb_define_method (c_guestfs, "test0rinterr",
        ruby_guestfs_test0rinterr, 0);
  rb_define_method (c_guestfs, "test0rint64",
        ruby_guestfs_test0rint64, 1);
  rb_define_method (c_guestfs, "test0rint64err",
        ruby_guestfs_test0rint64err, 0);
  rb_define_method (c_guestfs, "test0rbool",
        ruby_guestfs_test0rbool, 1);
  rb_define_method (c_guestfs, "test0rboolerr",
        ruby_guestfs_test0rboolerr, 0);
  rb_define_method (c_guestfs, "test0rconststring",
        ruby_guestfs_test0rconststring, 1);
  rb_define_method (c_guestfs, "test0rconststringerr",
        ruby_guestfs_test0rconststringerr, 0);
  rb_define_method (c_guestfs, "test0rconstoptstring",
        ruby_guestfs_test0rconstoptstring, 1);
  rb_define_method (c_guestfs, "test0rconstoptstringerr",
        ruby_guestfs_test0rconstoptstringerr, 0);
  rb_define_method (c_guestfs, "test0rstring",
        ruby_guestfs_test0rstring, 1);
  rb_define_method (c_guestfs, "test0rstringerr",
        ruby_guestfs_test0rstringerr, 0);
  rb_define_method (c_guestfs, "test0rstringlist",
        ruby_guestfs_test0rstringlist, 1);
  rb_define_method (c_guestfs, "test0rstringlisterr",
        ruby_guestfs_test0rstringlisterr, 0);
  rb_define_method (c_guestfs, "test0rstruct",
        ruby_guestfs_test0rstruct, 1);
  rb_define_method (c_guestfs, "test0rstructerr",
        ruby_guestfs_test0rstructerr, 0);
  rb_define_method (c_guestfs, "test0rstructlist",
        ruby_guestfs_test0rstructlist, 1);
  rb_define_method (c_guestfs, "test0rstructlisterr",
        ruby_guestfs_test0rstructlisterr, 0);
  rb_define_method (c_guestfs, "test0rhashtable",
        ruby_guestfs_test0rhashtable, 1);
  rb_define_method (c_guestfs, "test0rhashtableerr",
        ruby_guestfs_test0rhashtableerr, 0);
  rb_define_method (c_guestfs, "launch",
        ruby_guestfs_launch, 0);
  rb_define_method (c_guestfs, "wait_ready",
        ruby_guestfs_wait_ready, 0);
  rb_define_method (c_guestfs, "kill_subprocess",
        ruby_guestfs_kill_subprocess, 0);
  rb_define_method (c_guestfs, "add_drive",
        ruby_guestfs_add_drive, 1);
  rb_define_method (c_guestfs, "add_cdrom",
        ruby_guestfs_add_cdrom, 1);
  rb_define_method (c_guestfs, "add_drive_ro",
        ruby_guestfs_add_drive_ro, 1);
  rb_define_method (c_guestfs, "config",
        ruby_guestfs_config, 2);
  rb_define_method (c_guestfs, "set_qemu",
        ruby_guestfs_set_qemu, 1);
  rb_define_method (c_guestfs, "get_qemu",
        ruby_guestfs_get_qemu, 0);
  rb_define_method (c_guestfs, "set_path",
        ruby_guestfs_set_path, 1);
  rb_define_method (c_guestfs, "get_path",
        ruby_guestfs_get_path, 0);
  rb_define_method (c_guestfs, "set_append",
        ruby_guestfs_set_append, 1);
  rb_define_method (c_guestfs, "get_append",
        ruby_guestfs_get_append, 0);
  rb_define_method (c_guestfs, "set_autosync",
        ruby_guestfs_set_autosync, 1);
  rb_define_method (c_guestfs, "get_autosync",
        ruby_guestfs_get_autosync, 0);
  rb_define_method (c_guestfs, "set_verbose",
        ruby_guestfs_set_verbose, 1);
  rb_define_method (c_guestfs, "get_verbose",
        ruby_guestfs_get_verbose, 0);
  rb_define_method (c_guestfs, "is_ready",
        ruby_guestfs_is_ready, 0);
  rb_define_method (c_guestfs, "is_config",
        ruby_guestfs_is_config, 0);
  rb_define_method (c_guestfs, "is_launching",
        ruby_guestfs_is_launching, 0);
  rb_define_method (c_guestfs, "is_busy",
        ruby_guestfs_is_busy, 0);
  rb_define_method (c_guestfs, "get_state",
        ruby_guestfs_get_state, 0);
  rb_define_method (c_guestfs, "set_memsize",
        ruby_guestfs_set_memsize, 1);
  rb_define_method (c_guestfs, "get_memsize",
        ruby_guestfs_get_memsize, 0);
  rb_define_method (c_guestfs, "get_pid",
        ruby_guestfs_get_pid, 0);
  rb_define_method (c_guestfs, "version",
        ruby_guestfs_version, 0);
  rb_define_method (c_guestfs, "set_selinux",
        ruby_guestfs_set_selinux, 1);
  rb_define_method (c_guestfs, "get_selinux",
        ruby_guestfs_get_selinux, 0);
  rb_define_method (c_guestfs, "set_trace",
        ruby_guestfs_set_trace, 1);
  rb_define_method (c_guestfs, "get_trace",
        ruby_guestfs_get_trace, 0);
  rb_define_method (c_guestfs, "set_direct",
        ruby_guestfs_set_direct, 1);
  rb_define_method (c_guestfs, "get_direct",
        ruby_guestfs_get_direct, 0);
  rb_define_method (c_guestfs, "set_recovery_proc",
        ruby_guestfs_set_recovery_proc, 1);
  rb_define_method (c_guestfs, "get_recovery_proc",
        ruby_guestfs_get_recovery_proc, 0);
  rb_define_method (c_guestfs, "add_drive_with_if",
        ruby_guestfs_add_drive_with_if, 2);
  rb_define_method (c_guestfs, "add_drive_ro_with_if",
        ruby_guestfs_add_drive_ro_with_if, 2);
  rb_define_method (c_guestfs, "mount",
        ruby_guestfs_mount, 2);
  rb_define_method (c_guestfs, "sync",
        ruby_guestfs_sync, 0);
  rb_define_method (c_guestfs, "touch",
        ruby_guestfs_touch, 1);
  rb_define_method (c_guestfs, "cat",
        ruby_guestfs_cat, 1);
  rb_define_method (c_guestfs, "ll",
        ruby_guestfs_ll, 1);
  rb_define_method (c_guestfs, "ls",
        ruby_guestfs_ls, 1);
  rb_define_method (c_guestfs, "list_devices",
        ruby_guestfs_list_devices, 0);
  rb_define_method (c_guestfs, "list_partitions",
        ruby_guestfs_list_partitions, 0);
  rb_define_method (c_guestfs, "pvs",
        ruby_guestfs_pvs, 0);
  rb_define_method (c_guestfs, "vgs",
        ruby_guestfs_vgs, 0);
  rb_define_method (c_guestfs, "lvs",
        ruby_guestfs_lvs, 0);
  rb_define_method (c_guestfs, "pvs_full",
        ruby_guestfs_pvs_full, 0);
  rb_define_method (c_guestfs, "vgs_full",
        ruby_guestfs_vgs_full, 0);
  rb_define_method (c_guestfs, "lvs_full",
        ruby_guestfs_lvs_full, 0);
  rb_define_method (c_guestfs, "read_lines",
        ruby_guestfs_read_lines, 1);
  rb_define_method (c_guestfs, "aug_init",
        ruby_guestfs_aug_init, 2);
  rb_define_method (c_guestfs, "aug_close",
        ruby_guestfs_aug_close, 0);
  rb_define_method (c_guestfs, "aug_defvar",
        ruby_guestfs_aug_defvar, 2);
  rb_define_method (c_guestfs, "aug_defnode",
        ruby_guestfs_aug_defnode, 3);
  rb_define_method (c_guestfs, "aug_get",
        ruby_guestfs_aug_get, 1);
  rb_define_method (c_guestfs, "aug_set",
        ruby_guestfs_aug_set, 2);
  rb_define_method (c_guestfs, "aug_insert",
        ruby_guestfs_aug_insert, 3);
  rb_define_method (c_guestfs, "aug_rm",
        ruby_guestfs_aug_rm, 1);
  rb_define_method (c_guestfs, "aug_mv",
        ruby_guestfs_aug_mv, 2);
  rb_define_method (c_guestfs, "aug_match",
        ruby_guestfs_aug_match, 1);
  rb_define_method (c_guestfs, "aug_save",
        ruby_guestfs_aug_save, 0);
  rb_define_method (c_guestfs, "aug_load",
        ruby_guestfs_aug_load, 0);
  rb_define_method (c_guestfs, "aug_ls",
        ruby_guestfs_aug_ls, 1);
  rb_define_method (c_guestfs, "rm",
        ruby_guestfs_rm, 1);
  rb_define_method (c_guestfs, "rmdir",
        ruby_guestfs_rmdir, 1);
  rb_define_method (c_guestfs, "rm_rf",
        ruby_guestfs_rm_rf, 1);
  rb_define_method (c_guestfs, "mkdir",
        ruby_guestfs_mkdir, 1);
  rb_define_method (c_guestfs, "mkdir_p",
        ruby_guestfs_mkdir_p, 1);
  rb_define_method (c_guestfs, "chmod",
        ruby_guestfs_chmod, 2);
  rb_define_method (c_guestfs, "chown",
        ruby_guestfs_chown, 3);
  rb_define_method (c_guestfs, "exists",
        ruby_guestfs_exists, 1);
  rb_define_method (c_guestfs, "is_file",
        ruby_guestfs_is_file, 1);
  rb_define_method (c_guestfs, "is_dir",
        ruby_guestfs_is_dir, 1);
  rb_define_method (c_guestfs, "pvcreate",
        ruby_guestfs_pvcreate, 1);
  rb_define_method (c_guestfs, "vgcreate",
        ruby_guestfs_vgcreate, 2);
  rb_define_method (c_guestfs, "lvcreate",
        ruby_guestfs_lvcreate, 3);
  rb_define_method (c_guestfs, "mkfs",
        ruby_guestfs_mkfs, 2);
  rb_define_method (c_guestfs, "sfdisk",
        ruby_guestfs_sfdisk, 5);
  rb_define_method (c_guestfs, "write_file",
        ruby_guestfs_write_file, 3);
  rb_define_method (c_guestfs, "umount",
        ruby_guestfs_umount, 1);
  rb_define_method (c_guestfs, "mounts",
        ruby_guestfs_mounts, 0);
  rb_define_method (c_guestfs, "umount_all",
        ruby_guestfs_umount_all, 0);
  rb_define_method (c_guestfs, "lvm_remove_all",
        ruby_guestfs_lvm_remove_all, 0);
  rb_define_method (c_guestfs, "file",
        ruby_guestfs_file, 1);
  rb_define_method (c_guestfs, "command",
        ruby_guestfs_command, 1);
  rb_define_method (c_guestfs, "command_lines",
        ruby_guestfs_command_lines, 1);
  rb_define_method (c_guestfs, "stat",
        ruby_guestfs_stat, 1);
  rb_define_method (c_guestfs, "lstat",
        ruby_guestfs_lstat, 1);
  rb_define_method (c_guestfs, "statvfs",
        ruby_guestfs_statvfs, 1);
  rb_define_method (c_guestfs, "tune2fs_l",
        ruby_guestfs_tune2fs_l, 1);
  rb_define_method (c_guestfs, "blockdev_setro",
        ruby_guestfs_blockdev_setro, 1);
  rb_define_method (c_guestfs, "blockdev_setrw",
        ruby_guestfs_blockdev_setrw, 1);
  rb_define_method (c_guestfs, "blockdev_getro",
        ruby_guestfs_blockdev_getro, 1);
  rb_define_method (c_guestfs, "blockdev_getss",
        ruby_guestfs_blockdev_getss, 1);
  rb_define_method (c_guestfs, "blockdev_getbsz",
        ruby_guestfs_blockdev_getbsz, 1);
  rb_define_method (c_guestfs, "blockdev_setbsz",
        ruby_guestfs_blockdev_setbsz, 2);
  rb_define_method (c_guestfs, "blockdev_getsz",
        ruby_guestfs_blockdev_getsz, 1);
  rb_define_method (c_guestfs, "blockdev_getsize64",
        ruby_guestfs_blockdev_getsize64, 1);
  rb_define_method (c_guestfs, "blockdev_flushbufs",
        ruby_guestfs_blockdev_flushbufs, 1);
  rb_define_method (c_guestfs, "blockdev_rereadpt",
        ruby_guestfs_blockdev_rereadpt, 1);
  rb_define_method (c_guestfs, "upload",
        ruby_guestfs_upload, 2);
  rb_define_method (c_guestfs, "download",
        ruby_guestfs_download, 2);
  rb_define_method (c_guestfs, "checksum",
        ruby_guestfs_checksum, 2);
  rb_define_method (c_guestfs, "tar_in",
        ruby_guestfs_tar_in, 2);
  rb_define_method (c_guestfs, "tar_out",
        ruby_guestfs_tar_out, 2);
  rb_define_method (c_guestfs, "tgz_in",
        ruby_guestfs_tgz_in, 2);
  rb_define_method (c_guestfs, "tgz_out",
        ruby_guestfs_tgz_out, 2);
  rb_define_method (c_guestfs, "mount_ro",
        ruby_guestfs_mount_ro, 2);
  rb_define_method (c_guestfs, "mount_options",
        ruby_guestfs_mount_options, 3);
  rb_define_method (c_guestfs, "mount_vfs",
        ruby_guestfs_mount_vfs, 4);
  rb_define_method (c_guestfs, "debug",
        ruby_guestfs_debug, 2);
  rb_define_method (c_guestfs, "lvremove",
        ruby_guestfs_lvremove, 1);
  rb_define_method (c_guestfs, "vgremove",
        ruby_guestfs_vgremove, 1);
  rb_define_method (c_guestfs, "pvremove",
        ruby_guestfs_pvremove, 1);
  rb_define_method (c_guestfs, "set_e2label",
        ruby_guestfs_set_e2label, 2);
  rb_define_method (c_guestfs, "get_e2label",
        ruby_guestfs_get_e2label, 1);
  rb_define_method (c_guestfs, "set_e2uuid",
        ruby_guestfs_set_e2uuid, 2);
  rb_define_method (c_guestfs, "get_e2uuid",
        ruby_guestfs_get_e2uuid, 1);
  rb_define_method (c_guestfs, "fsck",
        ruby_guestfs_fsck, 2);
  rb_define_method (c_guestfs, "zero",
        ruby_guestfs_zero, 1);
  rb_define_method (c_guestfs, "grub_install",
        ruby_guestfs_grub_install, 2);
  rb_define_method (c_guestfs, "cp",
        ruby_guestfs_cp, 2);
  rb_define_method (c_guestfs, "cp_a",
        ruby_guestfs_cp_a, 2);
  rb_define_method (c_guestfs, "mv",
        ruby_guestfs_mv, 2);
  rb_define_method (c_guestfs, "drop_caches",
        ruby_guestfs_drop_caches, 1);
  rb_define_method (c_guestfs, "dmesg",
        ruby_guestfs_dmesg, 0);
  rb_define_method (c_guestfs, "ping_daemon",
        ruby_guestfs_ping_daemon, 0);
  rb_define_method (c_guestfs, "equal",
        ruby_guestfs_equal, 2);
  rb_define_method (c_guestfs, "strings",
        ruby_guestfs_strings, 1);
  rb_define_method (c_guestfs, "strings_e",
        ruby_guestfs_strings_e, 2);
  rb_define_method (c_guestfs, "hexdump",
        ruby_guestfs_hexdump, 1);
  rb_define_method (c_guestfs, "zerofree",
        ruby_guestfs_zerofree, 1);
  rb_define_method (c_guestfs, "pvresize",
        ruby_guestfs_pvresize, 1);
  rb_define_method (c_guestfs, "sfdisk_N",
        ruby_guestfs_sfdisk_N, 6);
  rb_define_method (c_guestfs, "sfdisk_l",
        ruby_guestfs_sfdisk_l, 1);
  rb_define_method (c_guestfs, "sfdisk_kernel_geometry",
        ruby_guestfs_sfdisk_kernel_geometry, 1);
  rb_define_method (c_guestfs, "sfdisk_disk_geometry",
        ruby_guestfs_sfdisk_disk_geometry, 1);
  rb_define_method (c_guestfs, "vg_activate_all",
        ruby_guestfs_vg_activate_all, 1);
  rb_define_method (c_guestfs, "vg_activate",
        ruby_guestfs_vg_activate, 2);
  rb_define_method (c_guestfs, "lvresize",
        ruby_guestfs_lvresize, 2);
  rb_define_method (c_guestfs, "resize2fs",
        ruby_guestfs_resize2fs, 1);
  rb_define_method (c_guestfs, "find",
        ruby_guestfs_find, 1);
  rb_define_method (c_guestfs, "e2fsck_f",
        ruby_guestfs_e2fsck_f, 1);
  rb_define_method (c_guestfs, "sleep",
        ruby_guestfs_sleep, 1);
  rb_define_method (c_guestfs, "ntfs_3g_probe",
        ruby_guestfs_ntfs_3g_probe, 2);
  rb_define_method (c_guestfs, "sh",
        ruby_guestfs_sh, 1);
  rb_define_method (c_guestfs, "sh_lines",
        ruby_guestfs_sh_lines, 1);
  rb_define_method (c_guestfs, "glob_expand",
        ruby_guestfs_glob_expand, 1);
  rb_define_method (c_guestfs, "scrub_device",
        ruby_guestfs_scrub_device, 1);
  rb_define_method (c_guestfs, "scrub_file",
        ruby_guestfs_scrub_file, 1);
  rb_define_method (c_guestfs, "scrub_freespace",
        ruby_guestfs_scrub_freespace, 1);
  rb_define_method (c_guestfs, "mkdtemp",
        ruby_guestfs_mkdtemp, 1);
  rb_define_method (c_guestfs, "wc_l",
        ruby_guestfs_wc_l, 1);
  rb_define_method (c_guestfs, "wc_w",
        ruby_guestfs_wc_w, 1);
  rb_define_method (c_guestfs, "wc_c",
        ruby_guestfs_wc_c, 1);
  rb_define_method (c_guestfs, "head",
        ruby_guestfs_head, 1);
  rb_define_method (c_guestfs, "head_n",
        ruby_guestfs_head_n, 2);
  rb_define_method (c_guestfs, "tail",
        ruby_guestfs_tail, 1);
  rb_define_method (c_guestfs, "tail_n",
        ruby_guestfs_tail_n, 2);
  rb_define_method (c_guestfs, "df",
        ruby_guestfs_df, 0);
  rb_define_method (c_guestfs, "df_h",
        ruby_guestfs_df_h, 0);
  rb_define_method (c_guestfs, "du",
        ruby_guestfs_du, 1);
  rb_define_method (c_guestfs, "initrd_list",
        ruby_guestfs_initrd_list, 1);
  rb_define_method (c_guestfs, "mount_loop",
        ruby_guestfs_mount_loop, 2);
  rb_define_method (c_guestfs, "mkswap",
        ruby_guestfs_mkswap, 1);
  rb_define_method (c_guestfs, "mkswap_L",
        ruby_guestfs_mkswap_L, 2);
  rb_define_method (c_guestfs, "mkswap_U",
        ruby_guestfs_mkswap_U, 2);
  rb_define_method (c_guestfs, "mknod",
        ruby_guestfs_mknod, 4);
  rb_define_method (c_guestfs, "mkfifo",
        ruby_guestfs_mkfifo, 2);
  rb_define_method (c_guestfs, "mknod_b",
        ruby_guestfs_mknod_b, 4);
  rb_define_method (c_guestfs, "mknod_c",
        ruby_guestfs_mknod_c, 4);
  rb_define_method (c_guestfs, "umask",
        ruby_guestfs_umask, 1);
  rb_define_method (c_guestfs, "readdir",
        ruby_guestfs_readdir, 1);
  rb_define_method (c_guestfs, "sfdiskM",
        ruby_guestfs_sfdiskM, 2);
  rb_define_method (c_guestfs, "zfile",
        ruby_guestfs_zfile, 2);
  rb_define_method (c_guestfs, "getxattrs",
        ruby_guestfs_getxattrs, 1);
  rb_define_method (c_guestfs, "lgetxattrs",
        ruby_guestfs_lgetxattrs, 1);
  rb_define_method (c_guestfs, "setxattr",
        ruby_guestfs_setxattr, 4);
  rb_define_method (c_guestfs, "lsetxattr",
        ruby_guestfs_lsetxattr, 4);
  rb_define_method (c_guestfs, "removexattr",
        ruby_guestfs_removexattr, 2);
  rb_define_method (c_guestfs, "lremovexattr",
        ruby_guestfs_lremovexattr, 2);
  rb_define_method (c_guestfs, "mountpoints",
        ruby_guestfs_mountpoints, 0);
  rb_define_method (c_guestfs, "mkmountpoint",
        ruby_guestfs_mkmountpoint, 1);
  rb_define_method (c_guestfs, "rmmountpoint",
        ruby_guestfs_rmmountpoint, 1);
  rb_define_method (c_guestfs, "read_file",
        ruby_guestfs_read_file, 1);
  rb_define_method (c_guestfs, "grep",
        ruby_guestfs_grep, 2);
  rb_define_method (c_guestfs, "egrep",
        ruby_guestfs_egrep, 2);
  rb_define_method (c_guestfs, "fgrep",
        ruby_guestfs_fgrep, 2);
  rb_define_method (c_guestfs, "grepi",
        ruby_guestfs_grepi, 2);
  rb_define_method (c_guestfs, "egrepi",
        ruby_guestfs_egrepi, 2);
  rb_define_method (c_guestfs, "fgrepi",
        ruby_guestfs_fgrepi, 2);
  rb_define_method (c_guestfs, "zgrep",
        ruby_guestfs_zgrep, 2);
  rb_define_method (c_guestfs, "zegrep",
        ruby_guestfs_zegrep, 2);
  rb_define_method (c_guestfs, "zfgrep",
        ruby_guestfs_zfgrep, 2);
  rb_define_method (c_guestfs, "zgrepi",
        ruby_guestfs_zgrepi, 2);
  rb_define_method (c_guestfs, "zegrepi",
        ruby_guestfs_zegrepi, 2);
  rb_define_method (c_guestfs, "zfgrepi",
        ruby_guestfs_zfgrepi, 2);
  rb_define_method (c_guestfs, "realpath",
        ruby_guestfs_realpath, 1);
  rb_define_method (c_guestfs, "ln",
        ruby_guestfs_ln, 2);
  rb_define_method (c_guestfs, "ln_f",
        ruby_guestfs_ln_f, 2);
  rb_define_method (c_guestfs, "ln_s",
        ruby_guestfs_ln_s, 2);
  rb_define_method (c_guestfs, "ln_sf",
        ruby_guestfs_ln_sf, 2);
  rb_define_method (c_guestfs, "readlink",
        ruby_guestfs_readlink, 1);
  rb_define_method (c_guestfs, "fallocate",
        ruby_guestfs_fallocate, 2);
  rb_define_method (c_guestfs, "swapon_device",
        ruby_guestfs_swapon_device, 1);
  rb_define_method (c_guestfs, "swapoff_device",
        ruby_guestfs_swapoff_device, 1);
  rb_define_method (c_guestfs, "swapon_file",
        ruby_guestfs_swapon_file, 1);
  rb_define_method (c_guestfs, "swapoff_file",
        ruby_guestfs_swapoff_file, 1);
  rb_define_method (c_guestfs, "swapon_label",
        ruby_guestfs_swapon_label, 1);
  rb_define_method (c_guestfs, "swapoff_label",
        ruby_guestfs_swapoff_label, 1);
  rb_define_method (c_guestfs, "swapon_uuid",
        ruby_guestfs_swapon_uuid, 1);
  rb_define_method (c_guestfs, "swapoff_uuid",
        ruby_guestfs_swapoff_uuid, 1);
  rb_define_method (c_guestfs, "mkswap_file",
        ruby_guestfs_mkswap_file, 1);
  rb_define_method (c_guestfs, "inotify_init",
        ruby_guestfs_inotify_init, 1);
  rb_define_method (c_guestfs, "inotify_add_watch",
        ruby_guestfs_inotify_add_watch, 2);
  rb_define_method (c_guestfs, "inotify_rm_watch",
        ruby_guestfs_inotify_rm_watch, 1);
  rb_define_method (c_guestfs, "inotify_read",
        ruby_guestfs_inotify_read, 0);
  rb_define_method (c_guestfs, "inotify_files",
        ruby_guestfs_inotify_files, 0);
  rb_define_method (c_guestfs, "inotify_close",
        ruby_guestfs_inotify_close, 0);
  rb_define_method (c_guestfs, "setcon",
        ruby_guestfs_setcon, 1);
  rb_define_method (c_guestfs, "getcon",
        ruby_guestfs_getcon, 0);
  rb_define_method (c_guestfs, "mkfs_b",
        ruby_guestfs_mkfs_b, 3);
  rb_define_method (c_guestfs, "mke2journal",
        ruby_guestfs_mke2journal, 2);
  rb_define_method (c_guestfs, "mke2journal_L",
        ruby_guestfs_mke2journal_L, 3);
  rb_define_method (c_guestfs, "mke2journal_U",
        ruby_guestfs_mke2journal_U, 3);
  rb_define_method (c_guestfs, "mke2fs_J",
        ruby_guestfs_mke2fs_J, 4);
  rb_define_method (c_guestfs, "mke2fs_JL",
        ruby_guestfs_mke2fs_JL, 4);
  rb_define_method (c_guestfs, "mke2fs_JU",
        ruby_guestfs_mke2fs_JU, 4);
  rb_define_method (c_guestfs, "modprobe",
        ruby_guestfs_modprobe, 1);
  rb_define_method (c_guestfs, "echo_daemon",
        ruby_guestfs_echo_daemon, 1);
  rb_define_method (c_guestfs, "find0",
        ruby_guestfs_find0, 2);
  rb_define_method (c_guestfs, "case_sensitive_path",
        ruby_guestfs_case_sensitive_path, 1);
  rb_define_method (c_guestfs, "vfs_type",
        ruby_guestfs_vfs_type, 1);
  rb_define_method (c_guestfs, "truncate",
        ruby_guestfs_truncate, 1);
  rb_define_method (c_guestfs, "truncate_size",
        ruby_guestfs_truncate_size, 2);
  rb_define_method (c_guestfs, "utimens",
        ruby_guestfs_utimens, 5);
  rb_define_method (c_guestfs, "mkdir_mode",
        ruby_guestfs_mkdir_mode, 2);
  rb_define_method (c_guestfs, "lchown",
        ruby_guestfs_lchown, 3);
  rb_define_method (c_guestfs, "lstatlist",
        ruby_guestfs_lstatlist, 2);
  rb_define_method (c_guestfs, "lxattrlist",
        ruby_guestfs_lxattrlist, 2);
  rb_define_method (c_guestfs, "readlinklist",
        ruby_guestfs_readlinklist, 2);
  rb_define_method (c_guestfs, "pread",
        ruby_guestfs_pread, 3);
  rb_define_method (c_guestfs, "part_init",
        ruby_guestfs_part_init, 2);
  rb_define_method (c_guestfs, "part_add",
        ruby_guestfs_part_add, 4);
  rb_define_method (c_guestfs, "part_disk",
        ruby_guestfs_part_disk, 2);
  rb_define_method (c_guestfs, "part_set_bootable",
        ruby_guestfs_part_set_bootable, 3);
  rb_define_method (c_guestfs, "part_set_name",
        ruby_guestfs_part_set_name, 3);
  rb_define_method (c_guestfs, "part_list",
        ruby_guestfs_part_list, 1);
  rb_define_method (c_guestfs, "part_get_parttype",
        ruby_guestfs_part_get_parttype, 1);
  rb_define_method (c_guestfs, "fill",
        ruby_guestfs_fill, 3);
  rb_define_method (c_guestfs, "available",
        ruby_guestfs_available, 1);
  rb_define_method (c_guestfs, "dd",
        ruby_guestfs_dd, 2);
  rb_define_method (c_guestfs, "filesize",
        ruby_guestfs_filesize, 1);
  rb_define_method (c_guestfs, "lvrename",
        ruby_guestfs_lvrename, 2);
  rb_define_method (c_guestfs, "vgrename",
        ruby_guestfs_vgrename, 2);
  rb_define_method (c_guestfs, "initrd_cat",
        ruby_guestfs_initrd_cat, 2);
}
