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

static void ruby_event_callback_wrapper (guestfs_h *g, void *data, uint64_t event, int event_handle, int flags, const char *buf, size_t buf_len, const uint64_t *array, size_t array_len);
static VALUE ruby_event_callback_wrapper_wrapper (VALUE argv);
static VALUE ruby_event_callback_handle_exception (VALUE not_used, VALUE exn);
static VALUE **get_all_event_callbacks (guestfs_h *g, size_t *len_rtn);

static void
ruby_guestfs_free (void *gvp)
{
  guestfs_h *g = gvp;

  if (g) {
    /* As in the OCaml binding, there is a nasty, difficult to
     * solve case here where the user deletes events in one of
     * the callbacks that we are about to invoke, resulting in
     * a double-free.  XXX
     */
    size_t len, i;
    VALUE **roots = get_all_event_callbacks (g, &len);

    /* Close the handle: this could invoke callbacks from the list
     * above, which is why we don't want to delete them before
     * closing the handle.
     */
    guestfs_close (g);

    /* Now unregister the global roots. */
    for (i = 0; i < len; ++i) {
      rb_gc_unregister_address (roots[i]);
      free (roots[i]);
    }
    free (roots);
  }
}

/*
 * call-seq:
 *   Guestfs::Guestfs.new() -> Guestfs::Guestfs
 *
 * Call
 * +guestfs_create+[http://libguestfs.org/guestfs.3.html#guestfs_create]
 * to create a new libguestfs handle.  The handle is represented in
 * Ruby as an instance of the Guestfs::Guestfs class.
 */
static VALUE
ruby_guestfs_create (VALUE m)
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

/*
 * call-seq:
 *   g.close() -> nil
 *
 * Call
 * +guestfs_close+[http://libguestfs.org/guestfs.3.html#guestfs_close]
 * to close the libguestfs handle.
 */
static VALUE
ruby_guestfs_close (VALUE gv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);

  ruby_guestfs_free (g);
  DATA_PTR (gv) = NULL;

  return Qnil;
}

/*
 * call-seq:
 *   g.set_event_callback(cb, event_bitmask) -> event_handle
 *
 * Call
 * +guestfs_set_event_callback+[http://libguestfs.org/guestfs.3.html#guestfs_set_event_callback]
 * to register an event callback.  This returns an event handle.
 */
static VALUE
ruby_set_event_callback (VALUE gv, VALUE cbv, VALUE event_bitmaskv)
{
  guestfs_h *g;
  uint64_t event_bitmask;
  int eh;
  VALUE *root;
  char key[64];

  Data_Get_Struct (gv, guestfs_h, g);

  event_bitmask = NUM2ULL (event_bitmaskv);

  root = guestfs_safe_malloc (g, sizeof *root);
  *root = cbv;

  eh = guestfs_set_event_callback (g, ruby_event_callback_wrapper,
                                   event_bitmask, 0, root);
  if (eh == -1) {
    free (root);
    rb_raise (e_Error, "%s", guestfs_last_error (g));
  }

  rb_gc_register_address (root);

  snprintf (key, sizeof key, "_ruby_event_%d", eh);
  guestfs_set_private (g, key, root);

  return INT2NUM (eh);
}

/*
 * call-seq:
 *   g.delete_event_callback(event_handle) -> nil
 *
 * Call
 * +guestfs_delete_event_callback+[http://libguestfs.org/guestfs.3.html#guestfs_delete_event_callback]
 * to delete an event callback.
 */
static VALUE
ruby_delete_event_callback (VALUE gv, VALUE event_handlev)
{
  guestfs_h *g;
  char key[64];
  int eh = NUM2INT (event_handlev);
  VALUE *root;

  Data_Get_Struct (gv, guestfs_h, g);

  snprintf (key, sizeof key, "_ruby_event_%d", eh);

  root = guestfs_get_private (g, key);
  if (root) {
    rb_gc_unregister_address (root);
    free (root);
    guestfs_set_private (g, key, NULL);
    guestfs_delete_event_callback (g, eh);
  }

  return Qnil;
}

static void
ruby_event_callback_wrapper (guestfs_h *g,
                             void *data,
                             uint64_t event,
                             int event_handle,
                             int flags,
                             const char *buf, size_t buf_len,
                             const uint64_t *array, size_t array_len)
{
  size_t i;
  VALUE eventv, event_handlev, bufv, arrayv;
  VALUE argv[5];

  eventv = ULL2NUM (event);
  event_handlev = INT2NUM (event_handle);

  bufv = rb_str_new (buf, buf_len);

  arrayv = rb_ary_new2 (array_len);
  for (i = 0; i < array_len; ++i)
    rb_ary_push (arrayv, ULL2NUM (array[i]));

  /* This is a crap limitation of rb_rescue.
   * http://blade.nagaokaut.ac.jp/cgi-bin/scat.rb/~poffice/mail/ruby-talk/65698
   */
  argv[0] = * (VALUE *) data; /* function */
  argv[1] = eventv;
  argv[2] = event_handlev;
  argv[3] = bufv;
  argv[4] = arrayv;

  rb_rescue (ruby_event_callback_wrapper_wrapper, (VALUE) argv,
             ruby_event_callback_handle_exception, Qnil);
}

static VALUE
ruby_event_callback_wrapper_wrapper (VALUE argvv)
{
  VALUE *argv = (VALUE *) argvv;
  VALUE fn, eventv, event_handlev, bufv, arrayv;

  fn = argv[0];

  /* Check the Ruby callback still exists.  For reasons which are not
   * fully understood, even though we registered this as a global root,
   * it is still possible for the callback to go away (fn value remains
   * but its type changes from T_DATA to T_NONE).  (RHBZ#733297)
   */
  if (rb_type (fn) != T_NONE) {
    eventv = argv[1];
    event_handlev = argv[2];
    bufv = argv[3];
    arrayv = argv[4];

    rb_funcall (fn, rb_intern ("call"), 4,
                eventv, event_handlev, bufv, arrayv);
  }

  return Qnil;
}

static VALUE
ruby_event_callback_handle_exception (VALUE not_used, VALUE exn)
{
  /* Callbacks aren't supposed to throw exceptions.  The best we
   * can do is to print the error.
   */
  fprintf (stderr, "libguestfs: exception in callback: %s\n",
           StringValueCStr (exn));

  return Qnil;
}

static VALUE **
get_all_event_callbacks (guestfs_h *g, size_t *len_rtn)
{
  VALUE **r;
  size_t i;
  const char *key;
  VALUE *root;

  /* Count the length of the array that will be needed. */
  *len_rtn = 0;
  root = guestfs_first_private (g, &key);
  while (root != NULL) {
    if (strncmp (key, "_ruby_event_", strlen ("_ruby_event_")) == 0)
      (*len_rtn)++;
    root = guestfs_next_private (g, &key);
  }

  /* Copy them into the return array. */
  r = guestfs_safe_malloc (g, sizeof (VALUE *) * (*len_rtn));

  i = 0;
  root = guestfs_first_private (g, &key);
  while (root != NULL) {
    if (strncmp (key, "_ruby_event_", strlen ("_ruby_event_")) == 0) {
      r[i] = root;
      i++;
    }
    root = guestfs_next_private (g, &key);
  }

  return r;
}

/*
 * call-seq:
 *   g.user_cancel() -> nil
 *
 * Call
 * +guestfs_user_cancel+[http://libguestfs.org/guestfs.3.html#guestfs_user_cancel]
 * to cancel the current transfer.  This is safe to call from Ruby
 * signal handlers and threads.
 */
static VALUE
ruby_user_cancel (VALUE gv)
{
  guestfs_h *g;

  Data_Get_Struct (gv, guestfs_h, g);
  if (g)
    guestfs_user_cancel (g);
  return Qnil;
}

static VALUE
ruby_guestfs_test0 (VALUE gv, VALUE strv, VALUE optstrv, VALUE strlistv, VALUE bv, VALUE integerv, VALUE integer64v, VALUE fileinv, VALUE fileoutv, VALUE bufferinv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "test0");

  const char *str = StringValueCStr (strv);
  const char *optstr = !NIL_P (optstrv) ? StringValueCStr (optstrv) : NULL;
  char **strlist;
  Check_Type (strlistv, T_ARRAY);
  {
    size_t i, len;
    len = RARRAY_LEN (strlistv);
    strlist = ALLOC_N (char *, len+1);
    for (i = 0; i < len; ++i) {
      VALUE v = rb_ary_entry (strlistv, i);
      strlist[i] = StringValueCStr (v);
    }
    strlist[len] = NULL;
  }
  int b = RTEST (bv);
  int integer = NUM2INT (integerv);
  long long integer64 = NUM2LL (integer64v);
  const char *filein = StringValueCStr (fileinv);
  const char *fileout = StringValueCStr (fileoutv);
  Check_Type (bufferinv, T_STRING);
  const char *bufferin = RSTRING (bufferinv)->ptr;
  if (!bufferin)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "bufferin", "test0");
  size_t bufferin_size = RSTRING (bufferinv)->len;

  int r;

  r = guestfs_test0 (g, str, optstr, strlist, b, integer, integer64, filein, fileout, bufferin, bufferin_size);
  free (strlist);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

static VALUE
ruby_guestfs_test0rint (VALUE gv, VALUE valv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "test0rint");

  const char *val = StringValueCStr (valv);

  int r;

  r = guestfs_test0rint (g, val);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return INT2NUM (r);
}

static VALUE
ruby_guestfs_test0rinterr (VALUE gv)
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

static VALUE
ruby_guestfs_test0rint64 (VALUE gv, VALUE valv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "test0rint64");

  const char *val = StringValueCStr (valv);

  int64_t r;

  r = guestfs_test0rint64 (g, val);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return ULL2NUM (r);
}

static VALUE
ruby_guestfs_test0rint64err (VALUE gv)
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

static VALUE
ruby_guestfs_test0rbool (VALUE gv, VALUE valv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "test0rbool");

  const char *val = StringValueCStr (valv);

  int r;

  r = guestfs_test0rbool (g, val);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return INT2NUM (r);
}

static VALUE
ruby_guestfs_test0rboolerr (VALUE gv)
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

static VALUE
ruby_guestfs_test0rconststring (VALUE gv, VALUE valv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "test0rconststring");

  const char *val = StringValueCStr (valv);

  const char *r;

  r = guestfs_test0rconststring (g, val);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return rb_str_new2 (r);
}

static VALUE
ruby_guestfs_test0rconststringerr (VALUE gv)
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

static VALUE
ruby_guestfs_test0rconstoptstring (VALUE gv, VALUE valv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "test0rconstoptstring");

  const char *val = StringValueCStr (valv);

  const char *r;

  r = guestfs_test0rconstoptstring (g, val);

  if (r)
    return rb_str_new2 (r);
  else
    return Qnil;
}

static VALUE
ruby_guestfs_test0rconstoptstringerr (VALUE gv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "test0rconstoptstringerr");


  const char *r;

  r = guestfs_test0rconstoptstringerr (g);

  if (r)
    return rb_str_new2 (r);
  else
    return Qnil;
}

static VALUE
ruby_guestfs_test0rstring (VALUE gv, VALUE valv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "test0rstring");

  const char *val = StringValueCStr (valv);

  char *r;

  r = guestfs_test0rstring (g, val);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  VALUE rv = rb_str_new2 (r);
  free (r);
  return rv;
}

static VALUE
ruby_guestfs_test0rstringerr (VALUE gv)
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

static VALUE
ruby_guestfs_test0rstringlist (VALUE gv, VALUE valv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "test0rstringlist");

  const char *val = StringValueCStr (valv);

  char **r;

  r = guestfs_test0rstringlist (g, val);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  size_t i, len = 0;
  for (i = 0; r[i] != NULL; ++i) len++;
  VALUE rv = rb_ary_new2 (len);
  for (i = 0; r[i] != NULL; ++i) {
    rb_ary_push (rv, rb_str_new2 (r[i]));
    free (r[i]);
  }
  free (r);
  return rv;
}

static VALUE
ruby_guestfs_test0rstringlisterr (VALUE gv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "test0rstringlisterr");


  char **r;

  r = guestfs_test0rstringlisterr (g);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  size_t i, len = 0;
  for (i = 0; r[i] != NULL; ++i) len++;
  VALUE rv = rb_ary_new2 (len);
  for (i = 0; r[i] != NULL; ++i) {
    rb_ary_push (rv, rb_str_new2 (r[i]));
    free (r[i]);
  }
  free (r);
  return rv;
}

static VALUE
ruby_guestfs_test0rstruct (VALUE gv, VALUE valv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "test0rstruct");

  const char *val = StringValueCStr (valv);

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

static VALUE
ruby_guestfs_test0rstructerr (VALUE gv)
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

static VALUE
ruby_guestfs_test0rstructlist (VALUE gv, VALUE valv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "test0rstructlist");

  const char *val = StringValueCStr (valv);

  struct guestfs_lvm_pv_list *r;

  r = guestfs_test0rstructlist (g, val);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  VALUE rv = rb_ary_new2 (r->len);
  size_t i;
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

static VALUE
ruby_guestfs_test0rstructlisterr (VALUE gv)
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
  size_t i;
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

static VALUE
ruby_guestfs_test0rhashtable (VALUE gv, VALUE valv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "test0rhashtable");

  const char *val = StringValueCStr (valv);

  char **r;

  r = guestfs_test0rhashtable (g, val);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  VALUE rv = rb_hash_new ();
  size_t i;
  for (i = 0; r[i] != NULL; i+=2) {
    rb_hash_aset (rv, rb_str_new2 (r[i]), rb_str_new2 (r[i+1]));
    free (r[i]);
    free (r[i+1]);
  }
  free (r);
  return rv;
}

static VALUE
ruby_guestfs_test0rhashtableerr (VALUE gv)
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
  size_t i;
  for (i = 0; r[i] != NULL; i+=2) {
    rb_hash_aset (rv, rb_str_new2 (r[i]), rb_str_new2 (r[i+1]));
    free (r[i]);
    free (r[i+1]);
  }
  free (r);
  return rv;
}

/*
 * call-seq:
 *   g.launch() -> nil
 *
 * launch the qemu subprocess
 *
 * Internally libguestfs is implemented by running a
 * virtual machine using qemu(1).
 * 
 * You should call this after configuring the handle (eg.
 * adding drives) but before performing any actions.
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_launch+[http://libguestfs.org/guestfs.3.html#guestfs_launch]).
 */
static VALUE
ruby_guestfs_launch (VALUE gv)
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

/*
 * call-seq:
 *   g.wait_ready() -> nil
 *
 * wait until the qemu subprocess launches (no op)
 *
 * This function is a no op.
 * 
 * In versions of the API < 1.0.71 you had to call this
 * function just after calling "g.launch" to wait for the
 * launch to complete. However this is no longer necessary
 * because "g.launch" now does the waiting.
 * 
 * If you see any calls to this function in code then you
 * can just remove them, unless you want to retain
 * compatibility with older versions of the API.
 * 
 * *This function is deprecated.* In new code, use the
 * "launch" call instead.
 * 
 * Deprecated functions will not be removed from the API,
 * but the fact that they are deprecated indicates that
 * there are problems with correct use of these functions.
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_wait_ready+[http://libguestfs.org/guestfs.3.html#guestfs_wait_ready]).
 */
static VALUE
ruby_guestfs_wait_ready (VALUE gv)
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

/*
 * call-seq:
 *   g.kill_subprocess() -> nil
 *
 * kill the qemu subprocess
 *
 * This kills the qemu subprocess. You should never need to
 * call this.
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_kill_subprocess+[http://libguestfs.org/guestfs.3.html#guestfs_kill_subprocess]).
 */
static VALUE
ruby_guestfs_kill_subprocess (VALUE gv)
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

/*
 * call-seq:
 *   g.add_drive(filename) -> nil
 *
 * add an image to examine or modify
 *
 * This function is the equivalent of calling
 * "g.add_drive_opts" with no optional parameters, so the
 * disk is added writable, with the format being detected
 * automatically.
 * 
 * Automatic detection of the format opens you up to a
 * potential security hole when dealing with untrusted
 * raw-format images. See CVE-2010-3851 and RHBZ#642934.
 * Specifying the format closes this security hole.
 * Therefore you should think about replacing calls to this
 * function with calls to "g.add_drive_opts", and
 * specifying the format.
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_add_drive+[http://libguestfs.org/guestfs.3.html#guestfs_add_drive]).
 */
static VALUE
ruby_guestfs_add_drive (VALUE gv, VALUE filenamev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "add_drive");

  const char *filename = StringValueCStr (filenamev);

  int r;

  r = guestfs_add_drive (g, filename);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.add_cdrom(filename) -> nil
 *
 * add a CD-ROM disk image to examine
 *
 * This function adds a virtual CD-ROM disk image to the
 * guest.
 * 
 * This is equivalent to the qemu parameter *-cdrom
 * filename*.
 * 
 * Notes:
 * 
 * *   This call checks for the existence of "filename".
 * This stops you from specifying other types of drive
 * which are supported by qemu such as "nbd:" and
 * "http:" URLs. To specify those, use the general
 * "g.config" call instead.
 * 
 * *   If you just want to add an ISO file (often you use
 * this as an efficient way to transfer large files
 * into the guest), then you should probably use
 * "g.add_drive_ro" instead.
 * 
 * *This function is deprecated.* In new code, use the
 * "add_drive_opts" call instead.
 * 
 * Deprecated functions will not be removed from the API,
 * but the fact that they are deprecated indicates that
 * there are problems with correct use of these functions.
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_add_cdrom+[http://libguestfs.org/guestfs.3.html#guestfs_add_cdrom]).
 */
static VALUE
ruby_guestfs_add_cdrom (VALUE gv, VALUE filenamev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "add_cdrom");

  const char *filename = StringValueCStr (filenamev);

  int r;

  r = guestfs_add_cdrom (g, filename);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.add_drive_ro(filename) -> nil
 *
 * add a drive in snapshot mode (read-only)
 *
 * This function is the equivalent of calling
 * "g.add_drive_opts" with the optional parameter
 * "GUESTFS_ADD_DRIVE_OPTS_READONLY" set to 1, so the disk
 * is added read-only, with the format being detected
 * automatically.
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_add_drive_ro+[http://libguestfs.org/guestfs.3.html#guestfs_add_drive_ro]).
 */
static VALUE
ruby_guestfs_add_drive_ro (VALUE gv, VALUE filenamev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "add_drive_ro");

  const char *filename = StringValueCStr (filenamev);

  int r;

  r = guestfs_add_drive_ro (g, filename);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.config(qemuparam, qemuvalue) -> nil
 *
 * add qemu parameters
 *
 * This can be used to add arbitrary qemu command line
 * parameters of the form *-param value*. Actually it's not
 * quite arbitrary - we prevent you from setting some
 * parameters which would interfere with parameters that we
 * use.
 * 
 * The first character of "param" string must be a "-"
 * (dash).
 * 
 * "value" can be NULL.
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_config+[http://libguestfs.org/guestfs.3.html#guestfs_config]).
 */
static VALUE
ruby_guestfs_config (VALUE gv, VALUE qemuparamv, VALUE qemuvaluev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "config");

  const char *qemuparam = StringValueCStr (qemuparamv);
  const char *qemuvalue = !NIL_P (qemuvaluev) ? StringValueCStr (qemuvaluev) : NULL;

  int r;

  r = guestfs_config (g, qemuparam, qemuvalue);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.set_qemu(qemu) -> nil
 *
 * set the qemu binary
 *
 * Set the qemu binary that we will use.
 * 
 * The default is chosen when the library was compiled by
 * the configure script.
 * 
 * You can also override this by setting the
 * "LIBGUESTFS_QEMU" environment variable.
 * 
 * Setting "qemu" to "NULL" restores the default qemu
 * binary.
 * 
 * Note that you should call this function as early as
 * possible after creating the handle. This is because some
 * pre-launch operations depend on testing qemu features
 * (by running "qemu -help"). If the qemu binary changes,
 * we don't retest features, and so you might see
 * inconsistent results. Using the environment variable
 * "LIBGUESTFS_QEMU" is safest of all since that picks the
 * qemu binary at the same time as the handle is created.
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_set_qemu+[http://libguestfs.org/guestfs.3.html#guestfs_set_qemu]).
 */
static VALUE
ruby_guestfs_set_qemu (VALUE gv, VALUE qemuv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "set_qemu");

  const char *qemu = !NIL_P (qemuv) ? StringValueCStr (qemuv) : NULL;

  int r;

  r = guestfs_set_qemu (g, qemu);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.get_qemu() -> string
 *
 * get the qemu binary
 *
 * Return the current qemu binary.
 * 
 * This is always non-NULL. If it wasn't set already, then
 * this will return the default qemu binary name.
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_get_qemu+[http://libguestfs.org/guestfs.3.html#guestfs_get_qemu]).
 */
static VALUE
ruby_guestfs_get_qemu (VALUE gv)
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

/*
 * call-seq:
 *   g.set_path(searchpath) -> nil
 *
 * set the search path
 *
 * Set the path that libguestfs searches for kernel and
 * initrd.img.
 * 
 * The default is "$libdir/guestfs" unless overridden by
 * setting "LIBGUESTFS_PATH" environment variable.
 * 
 * Setting "path" to "NULL" restores the default path.
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_set_path+[http://libguestfs.org/guestfs.3.html#guestfs_set_path]).
 */
static VALUE
ruby_guestfs_set_path (VALUE gv, VALUE searchpathv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "set_path");

  const char *searchpath = !NIL_P (searchpathv) ? StringValueCStr (searchpathv) : NULL;

  int r;

  r = guestfs_set_path (g, searchpath);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.get_path() -> string
 *
 * get the search path
 *
 * Return the current search path.
 * 
 * This is always non-NULL. If it wasn't set already, then
 * this will return the default path.
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_get_path+[http://libguestfs.org/guestfs.3.html#guestfs_get_path]).
 */
static VALUE
ruby_guestfs_get_path (VALUE gv)
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

/*
 * call-seq:
 *   g.set_append(append) -> nil
 *
 * add options to kernel command line
 *
 * This function is used to add additional options to the
 * guest kernel command line.
 * 
 * The default is "NULL" unless overridden by setting
 * "LIBGUESTFS_APPEND" environment variable.
 * 
 * Setting "append" to "NULL" means *no* additional options
 * are passed (libguestfs always adds a few of its own).
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_set_append+[http://libguestfs.org/guestfs.3.html#guestfs_set_append]).
 */
static VALUE
ruby_guestfs_set_append (VALUE gv, VALUE appendv)
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

/*
 * call-seq:
 *   g.get_append() -> string
 *
 * get the additional kernel options
 *
 * Return the additional kernel options which are added to
 * the guest kernel command line.
 * 
 * If "NULL" then no options are added.
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_get_append+[http://libguestfs.org/guestfs.3.html#guestfs_get_append]).
 */
static VALUE
ruby_guestfs_get_append (VALUE gv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "get_append");


  const char *r;

  r = guestfs_get_append (g);

  if (r)
    return rb_str_new2 (r);
  else
    return Qnil;
}

/*
 * call-seq:
 *   g.set_autosync(autosync) -> nil
 *
 * set autosync mode
 *
 * If "autosync" is true, this enables autosync. Libguestfs
 * will make a best effort attempt to make filesystems
 * consistent and synchronized when the handle is closed
 * (also if the program exits without closing handles).
 * 
 * This is enabled by default (since libguestfs 1.5.24,
 * previously it was disabled by default).
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_set_autosync+[http://libguestfs.org/guestfs.3.html#guestfs_set_autosync]).
 */
static VALUE
ruby_guestfs_set_autosync (VALUE gv, VALUE autosyncv)
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

/*
 * call-seq:
 *   g.get_autosync() -> [True|False]
 *
 * get autosync mode
 *
 * Get the autosync flag.
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_get_autosync+[http://libguestfs.org/guestfs.3.html#guestfs_get_autosync]).
 */
static VALUE
ruby_guestfs_get_autosync (VALUE gv)
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

/*
 * call-seq:
 *   g.set_verbose(verbose) -> nil
 *
 * set verbose mode
 *
 * If "verbose" is true, this turns on verbose messages.
 * 
 * Verbose messages are disabled unless the environment
 * variable "LIBGUESTFS_DEBUG" is defined and set to 1.
 * 
 * Verbose messages are normally sent to "stderr", unless
 * you register a callback to send them somewhere else (see
 * "g.set_event_callback").
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_set_verbose+[http://libguestfs.org/guestfs.3.html#guestfs_set_verbose]).
 */
static VALUE
ruby_guestfs_set_verbose (VALUE gv, VALUE verbosev)
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

/*
 * call-seq:
 *   g.get_verbose() -> [True|False]
 *
 * get verbose mode
 *
 * This returns the verbose messages flag.
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_get_verbose+[http://libguestfs.org/guestfs.3.html#guestfs_get_verbose]).
 */
static VALUE
ruby_guestfs_get_verbose (VALUE gv)
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

/*
 * call-seq:
 *   g.is_ready() -> [True|False]
 *
 * is ready to accept commands
 *
 * This returns true iff this handle is ready to accept
 * commands (in the "READY" state).
 * 
 * For more information on states, see guestfs(3).
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_is_ready+[http://libguestfs.org/guestfs.3.html#guestfs_is_ready]).
 */
static VALUE
ruby_guestfs_is_ready (VALUE gv)
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

/*
 * call-seq:
 *   g.is_config() -> [True|False]
 *
 * is in configuration state
 *
 * This returns true iff this handle is being configured
 * (in the "CONFIG" state).
 * 
 * For more information on states, see guestfs(3).
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_is_config+[http://libguestfs.org/guestfs.3.html#guestfs_is_config]).
 */
static VALUE
ruby_guestfs_is_config (VALUE gv)
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

/*
 * call-seq:
 *   g.is_launching() -> [True|False]
 *
 * is launching subprocess
 *
 * This returns true iff this handle is launching the
 * subprocess (in the "LAUNCHING" state).
 * 
 * For more information on states, see guestfs(3).
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_is_launching+[http://libguestfs.org/guestfs.3.html#guestfs_is_launching]).
 */
static VALUE
ruby_guestfs_is_launching (VALUE gv)
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

/*
 * call-seq:
 *   g.is_busy() -> [True|False]
 *
 * is busy processing a command
 *
 * This returns true iff this handle is busy processing a
 * command (in the "BUSY" state).
 * 
 * For more information on states, see guestfs(3).
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_is_busy+[http://libguestfs.org/guestfs.3.html#guestfs_is_busy]).
 */
static VALUE
ruby_guestfs_is_busy (VALUE gv)
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

/*
 * call-seq:
 *   g.get_state() -> fixnum
 *
 * get the current state
 *
 * This returns the current state as an opaque integer.
 * This is only useful for printing debug and internal
 * error messages.
 * 
 * For more information on states, see guestfs(3).
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_get_state+[http://libguestfs.org/guestfs.3.html#guestfs_get_state]).
 */
static VALUE
ruby_guestfs_get_state (VALUE gv)
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

/*
 * call-seq:
 *   g.set_memsize(memsize) -> nil
 *
 * set memory allocated to the qemu subprocess
 *
 * This sets the memory size in megabytes allocated to the
 * qemu subprocess. This only has any effect if called
 * before "g.launch".
 * 
 * You can also change this by setting the environment
 * variable "LIBGUESTFS_MEMSIZE" before the handle is
 * created.
 * 
 * For more information on the architecture of libguestfs,
 * see guestfs(3).
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_set_memsize+[http://libguestfs.org/guestfs.3.html#guestfs_set_memsize]).
 */
static VALUE
ruby_guestfs_set_memsize (VALUE gv, VALUE memsizev)
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

/*
 * call-seq:
 *   g.get_memsize() -> fixnum
 *
 * get memory allocated to the qemu subprocess
 *
 * This gets the memory size in megabytes allocated to the
 * qemu subprocess.
 * 
 * If "g.set_memsize" was not called on this handle, and if
 * "LIBGUESTFS_MEMSIZE" was not set, then this returns the
 * compiled-in default value for memsize.
 * 
 * For more information on the architecture of libguestfs,
 * see guestfs(3).
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_get_memsize+[http://libguestfs.org/guestfs.3.html#guestfs_get_memsize]).
 */
static VALUE
ruby_guestfs_get_memsize (VALUE gv)
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

/*
 * call-seq:
 *   g.get_pid() -> fixnum
 *
 * get PID of qemu subprocess
 *
 * Return the process ID of the qemu subprocess. If there
 * is no qemu subprocess, then this will return an error.
 * 
 * This is an internal call used for debugging and testing.
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_get_pid+[http://libguestfs.org/guestfs.3.html#guestfs_get_pid]).
 */
static VALUE
ruby_guestfs_get_pid (VALUE gv)
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

/*
 * call-seq:
 *   g.version() -> hash
 *
 * get the library version number
 *
 * Return the libguestfs version number that the program is
 * linked against.
 * 
 * Note that because of dynamic linking this is not
 * necessarily the version of libguestfs that you compiled
 * against. You can compile the program, and then at
 * runtime dynamically link against a completely different
 * "libguestfs.so" library.
 * 
 * This call was added in version 1.0.58. In previous
 * versions of libguestfs there was no way to get the
 * version number. From C code you can use dynamic linker
 * functions to find out if this symbol exists (if it
 * doesn't, then it's an earlier version).
 * 
 * The call returns a structure with four elements. The
 * first three ("major", "minor" and "release") are numbers
 * and correspond to the usual version triplet. The fourth
 * element ("extra") is a string and is normally empty, but
 * may be used for distro-specific information.
 * 
 * To construct the original version string:
 * "$major.$minor.$release$extra"
 * 
 * See also: "LIBGUESTFS VERSION NUMBERS" in guestfs(3).
 * 
 * *Note:* Don't use this call to test for availability of
 * features. In enterprise distributions we backport
 * features from later versions into earlier versions,
 * making this an unreliable way to test for features. Use
 * "g.available" instead.
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_version+[http://libguestfs.org/guestfs.3.html#guestfs_version]).
 */
static VALUE
ruby_guestfs_version (VALUE gv)
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

/*
 * call-seq:
 *   g.set_selinux(selinux) -> nil
 *
 * set SELinux enabled or disabled at appliance boot
 *
 * This sets the selinux flag that is passed to the
 * appliance at boot time. The default is "selinux=0"
 * (disabled).
 * 
 * Note that if SELinux is enabled, it is always in
 * Permissive mode ("enforcing=0").
 * 
 * For more information on the architecture of libguestfs,
 * see guestfs(3).
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_set_selinux+[http://libguestfs.org/guestfs.3.html#guestfs_set_selinux]).
 */
static VALUE
ruby_guestfs_set_selinux (VALUE gv, VALUE selinuxv)
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

/*
 * call-seq:
 *   g.get_selinux() -> [True|False]
 *
 * get SELinux enabled flag
 *
 * This returns the current setting of the selinux flag
 * which is passed to the appliance at boot time. See
 * "g.set_selinux".
 * 
 * For more information on the architecture of libguestfs,
 * see guestfs(3).
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_get_selinux+[http://libguestfs.org/guestfs.3.html#guestfs_get_selinux]).
 */
static VALUE
ruby_guestfs_get_selinux (VALUE gv)
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

/*
 * call-seq:
 *   g.set_trace(trace) -> nil
 *
 * enable or disable command traces
 *
 * If the command trace flag is set to 1, then libguestfs
 * calls, parameters and return values are traced.
 * 
 * If you want to trace C API calls into libguestfs (and
 * other libraries) then possibly a better way is to use
 * the external ltrace(1) command.
 * 
 * Command traces are disabled unless the environment
 * variable "LIBGUESTFS_TRACE" is defined and set to 1.
 * 
 * Trace messages are normally sent to "stderr", unless you
 * register a callback to send them somewhere else (see
 * "g.set_event_callback").
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_set_trace+[http://libguestfs.org/guestfs.3.html#guestfs_set_trace]).
 */
static VALUE
ruby_guestfs_set_trace (VALUE gv, VALUE tracev)
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

/*
 * call-seq:
 *   g.get_trace() -> [True|False]
 *
 * get command trace enabled flag
 *
 * Return the command trace flag.
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_get_trace+[http://libguestfs.org/guestfs.3.html#guestfs_get_trace]).
 */
static VALUE
ruby_guestfs_get_trace (VALUE gv)
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

/*
 * call-seq:
 *   g.set_direct(direct) -> nil
 *
 * enable or disable direct appliance mode
 *
 * If the direct appliance mode flag is enabled, then stdin
 * and stdout are passed directly through to the appliance
 * once it is launched.
 * 
 * One consequence of this is that log messages aren't
 * caught by the library and handled by
 * "g.set_log_message_callback", but go straight to stdout.
 * 
 * You probably don't want to use this unless you know what
 * you are doing.
 * 
 * The default is disabled.
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_set_direct+[http://libguestfs.org/guestfs.3.html#guestfs_set_direct]).
 */
static VALUE
ruby_guestfs_set_direct (VALUE gv, VALUE directv)
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

/*
 * call-seq:
 *   g.get_direct() -> [True|False]
 *
 * get direct appliance mode flag
 *
 * Return the direct appliance mode flag.
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_get_direct+[http://libguestfs.org/guestfs.3.html#guestfs_get_direct]).
 */
static VALUE
ruby_guestfs_get_direct (VALUE gv)
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

/*
 * call-seq:
 *   g.set_recovery_proc(recoveryproc) -> nil
 *
 * enable or disable the recovery process
 *
 * If this is called with the parameter "false" then
 * "g.launch" does not create a recovery process. The
 * purpose of the recovery process is to stop runaway qemu
 * processes in the case where the main program aborts
 * abruptly.
 * 
 * This only has any effect if called before "g.launch",
 * and the default is true.
 * 
 * About the only time when you would want to disable this
 * is if the main process will fork itself into the
 * background ("daemonize" itself). In this case the
 * recovery process thinks that the main program has
 * disappeared and so kills qemu, which is not very
 * helpful.
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_set_recovery_proc+[http://libguestfs.org/guestfs.3.html#guestfs_set_recovery_proc]).
 */
static VALUE
ruby_guestfs_set_recovery_proc (VALUE gv, VALUE recoveryprocv)
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

/*
 * call-seq:
 *   g.get_recovery_proc() -> [True|False]
 *
 * get recovery process enabled flag
 *
 * Return the recovery process enabled flag.
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_get_recovery_proc+[http://libguestfs.org/guestfs.3.html#guestfs_get_recovery_proc]).
 */
static VALUE
ruby_guestfs_get_recovery_proc (VALUE gv)
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

/*
 * call-seq:
 *   g.add_drive_with_if(filename, iface) -> nil
 *
 * add a drive specifying the QEMU block emulation to use
 *
 * This is the same as "g.add_drive" but it allows you to
 * specify the QEMU interface emulation to use at run time.
 * 
 * *This function is deprecated.* In new code, use the
 * "add_drive_opts" call instead.
 * 
 * Deprecated functions will not be removed from the API,
 * but the fact that they are deprecated indicates that
 * there are problems with correct use of these functions.
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_add_drive_with_if+[http://libguestfs.org/guestfs.3.html#guestfs_add_drive_with_if]).
 */
static VALUE
ruby_guestfs_add_drive_with_if (VALUE gv, VALUE filenamev, VALUE ifacev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "add_drive_with_if");

  const char *filename = StringValueCStr (filenamev);
  const char *iface = StringValueCStr (ifacev);

  int r;

  r = guestfs_add_drive_with_if (g, filename, iface);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.add_drive_ro_with_if(filename, iface) -> nil
 *
 * add a drive read-only specifying the QEMU block emulation to use
 *
 * This is the same as "g.add_drive_ro" but it allows you
 * to specify the QEMU interface emulation to use at run
 * time.
 * 
 * *This function is deprecated.* In new code, use the
 * "add_drive_opts" call instead.
 * 
 * Deprecated functions will not be removed from the API,
 * but the fact that they are deprecated indicates that
 * there are problems with correct use of these functions.
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_add_drive_ro_with_if+[http://libguestfs.org/guestfs.3.html#guestfs_add_drive_ro_with_if]).
 */
static VALUE
ruby_guestfs_add_drive_ro_with_if (VALUE gv, VALUE filenamev, VALUE ifacev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "add_drive_ro_with_if");

  const char *filename = StringValueCStr (filenamev);
  const char *iface = StringValueCStr (ifacev);

  int r;

  r = guestfs_add_drive_ro_with_if (g, filename, iface);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.file_architecture(filename) -> string
 *
 * detect the architecture of a binary file
 *
 * This detects the architecture of the binary "filename",
 * and returns it if known.
 * 
 * Currently defined architectures are:
 * 
 * "i386"
 * This string is returned for all 32 bit i386, i486,
 * i586, i686 binaries irrespective of the precise
 * processor requirements of the binary.
 * 
 * "x86_64"
 * 64 bit x86-64.
 * 
 * "sparc"
 * 32 bit SPARC.
 * 
 * "sparc64"
 * 64 bit SPARC V9 and above.
 * 
 * "ia64"
 * Intel Itanium.
 * 
 * "ppc"
 * 32 bit Power PC.
 * 
 * "ppc64"
 * 64 bit Power PC.
 * 
 * Libguestfs may return other architecture strings in
 * future.
 * 
 * The function works on at least the following types of
 * files:
 * 
 * *   many types of Un*x and Linux binary
 * 
 * *   many types of Un*x and Linux shared library
 * 
 * *   Windows Win32 and Win64 binaries
 * 
 * *   Windows Win32 and Win64 DLLs
 * 
 * Win32 binaries and DLLs return "i386".
 * 
 * Win64 binaries and DLLs return "x86_64".
 * 
 * *   Linux kernel modules
 * 
 * *   Linux new-style initrd images
 * 
 * *   some non-x86 Linux vmlinuz kernels
 * 
 * What it can't do currently:
 * 
 * *   static libraries (libfoo.a)
 * 
 * *   Linux old-style initrd as compressed ext2 filesystem
 * (RHEL 3)
 * 
 * *   x86 Linux vmlinuz kernels
 * 
 * x86 vmlinuz images (bzImage format) consist of a mix
 * of 16-, 32- and compressed code, and are horribly
 * hard to unpack. If you want to find the architecture
 * of a kernel, use the architecture of the associated
 * initrd or kernel module(s) instead.
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_file_architecture+[http://libguestfs.org/guestfs.3.html#guestfs_file_architecture]).
 */
static VALUE
ruby_guestfs_file_architecture (VALUE gv, VALUE filenamev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "file_architecture");

  const char *filename = StringValueCStr (filenamev);

  char *r;

  r = guestfs_file_architecture (g, filename);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  VALUE rv = rb_str_new2 (r);
  free (r);
  return rv;
}

/*
 * call-seq:
 *   g.inspect_os() -> list
 *
 * inspect disk and return list of operating systems found
 *
 * This function uses other libguestfs functions and
 * certain heuristics to inspect the disk(s) (usually disks
 * belonging to a virtual machine), looking for operating
 * systems.
 * 
 * The list returned is empty if no operating systems were
 * found.
 * 
 * If one operating system was found, then this returns a
 * list with a single element, which is the name of the
 * root filesystem of this operating system. It is also
 * possible for this function to return a list containing
 * more than one element, indicating a dual-boot or
 * multi-boot virtual machine, with each element being the
 * root filesystem of one of the operating systems.
 * 
 * You can pass the root string(s) returned to other
 * "g.inspect_get_*" functions in order to query further
 * information about each operating system, such as the
 * name and version.
 * 
 * This function uses other libguestfs features such as
 * "g.mount_ro" and "g.umount_all" in order to mount and
 * unmount filesystems and look at the contents. This
 * should be called with no disks currently mounted. The
 * function may also use Augeas, so any existing Augeas
 * handle will be closed.
 * 
 * This function cannot decrypt encrypted disks. The caller
 * must do that first (supplying the necessary keys) if the
 * disk is encrypted.
 * 
 * Please read "INSPECTION" in guestfs(3) for more details.
 * 
 * See also "g.list_filesystems".
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_inspect_os+[http://libguestfs.org/guestfs.3.html#guestfs_inspect_os]).
 */
static VALUE
ruby_guestfs_inspect_os (VALUE gv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "inspect_os");


  char **r;

  r = guestfs_inspect_os (g);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  size_t i, len = 0;
  for (i = 0; r[i] != NULL; ++i) len++;
  VALUE rv = rb_ary_new2 (len);
  for (i = 0; r[i] != NULL; ++i) {
    rb_ary_push (rv, rb_str_new2 (r[i]));
    free (r[i]);
  }
  free (r);
  return rv;
}

/*
 * call-seq:
 *   g.inspect_get_type(root) -> string
 *
 * get type of inspected operating system
 *
 * This returns the type of the inspected operating system.
 * Currently defined types are:
 * 
 * "linux"
 * Any Linux-based operating system.
 * 
 * "windows"
 * Any Microsoft Windows operating system.
 * 
 * "freebsd"
 * FreeBSD.
 * 
 * "netbsd"
 * NetBSD.
 * 
 * "unknown"
 * The operating system type could not be determined.
 * 
 * Future versions of libguestfs may return other strings
 * here. The caller should be prepared to handle any
 * string.
 * 
 * Please read "INSPECTION" in guestfs(3) for more details.
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_inspect_get_type+[http://libguestfs.org/guestfs.3.html#guestfs_inspect_get_type]).
 */
static VALUE
ruby_guestfs_inspect_get_type (VALUE gv, VALUE rootv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "inspect_get_type");

  const char *root = StringValueCStr (rootv);

  char *r;

  r = guestfs_inspect_get_type (g, root);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  VALUE rv = rb_str_new2 (r);
  free (r);
  return rv;
}

/*
 * call-seq:
 *   g.inspect_get_arch(root) -> string
 *
 * get architecture of inspected operating system
 *
 * This returns the architecture of the inspected operating
 * system. The possible return values are listed under
 * "g.file_architecture".
 * 
 * If the architecture could not be determined, then the
 * string "unknown" is returned.
 * 
 * Please read "INSPECTION" in guestfs(3) for more details.
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_inspect_get_arch+[http://libguestfs.org/guestfs.3.html#guestfs_inspect_get_arch]).
 */
static VALUE
ruby_guestfs_inspect_get_arch (VALUE gv, VALUE rootv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "inspect_get_arch");

  const char *root = StringValueCStr (rootv);

  char *r;

  r = guestfs_inspect_get_arch (g, root);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  VALUE rv = rb_str_new2 (r);
  free (r);
  return rv;
}

/*
 * call-seq:
 *   g.inspect_get_distro(root) -> string
 *
 * get distro of inspected operating system
 *
 * This returns the distro (distribution) of the inspected
 * operating system.
 * 
 * Currently defined distros are:
 * 
 * "archlinux"
 * Arch Linux.
 * 
 * "centos"
 * CentOS.
 * 
 * "debian"
 * Debian.
 * 
 * "fedora"
 * Fedora.
 * 
 * "gentoo"
 * Gentoo.
 * 
 * "linuxmint"
 * Linux Mint.
 * 
 * "mageia"
 * Mageia.
 * 
 * "mandriva"
 * Mandriva.
 * 
 * "meego"
 * MeeGo.
 * 
 * "opensuse"
 * OpenSUSE.
 * 
 * "pardus"
 * Pardus.
 * 
 * "redhat-based"
 * Some Red Hat-derived distro.
 * 
 * "rhel"
 * Red Hat Enterprise Linux.
 * 
 * "scientificlinux"
 * Scientific Linux.
 * 
 * "slackware"
 * Slackware.
 * 
 * "ttylinux"
 * ttylinux.
 * 
 * "ubuntu"
 * Ubuntu.
 * 
 * "unknown"
 * The distro could not be determined.
 * 
 * "windows"
 * Windows does not have distributions. This string is
 * returned if the OS type is Windows.
 * 
 * Future versions of libguestfs may return other strings
 * here. The caller should be prepared to handle any
 * string.
 * 
 * Please read "INSPECTION" in guestfs(3) for more details.
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_inspect_get_distro+[http://libguestfs.org/guestfs.3.html#guestfs_inspect_get_distro]).
 */
static VALUE
ruby_guestfs_inspect_get_distro (VALUE gv, VALUE rootv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "inspect_get_distro");

  const char *root = StringValueCStr (rootv);

  char *r;

  r = guestfs_inspect_get_distro (g, root);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  VALUE rv = rb_str_new2 (r);
  free (r);
  return rv;
}

/*
 * call-seq:
 *   g.inspect_get_major_version(root) -> fixnum
 *
 * get major version of inspected operating system
 *
 * This returns the major version number of the inspected
 * operating system.
 * 
 * Windows uses a consistent versioning scheme which is
 * *not* reflected in the popular public names used by the
 * operating system. Notably the operating system known as
 * "Windows 7" is really version 6.1 (ie. major = 6, minor
 * = 1). You can find out the real versions corresponding
 * to releases of Windows by consulting Wikipedia or MSDN.
 * 
 * If the version could not be determined, then 0 is
 * returned.
 * 
 * Please read "INSPECTION" in guestfs(3) for more details.
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_inspect_get_major_version+[http://libguestfs.org/guestfs.3.html#guestfs_inspect_get_major_version]).
 */
static VALUE
ruby_guestfs_inspect_get_major_version (VALUE gv, VALUE rootv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "inspect_get_major_version");

  const char *root = StringValueCStr (rootv);

  int r;

  r = guestfs_inspect_get_major_version (g, root);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return INT2NUM (r);
}

/*
 * call-seq:
 *   g.inspect_get_minor_version(root) -> fixnum
 *
 * get minor version of inspected operating system
 *
 * This returns the minor version number of the inspected
 * operating system.
 * 
 * If the version could not be determined, then 0 is
 * returned.
 * 
 * Please read "INSPECTION" in guestfs(3) for more details.
 * See also "g.inspect_get_major_version".
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_inspect_get_minor_version+[http://libguestfs.org/guestfs.3.html#guestfs_inspect_get_minor_version]).
 */
static VALUE
ruby_guestfs_inspect_get_minor_version (VALUE gv, VALUE rootv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "inspect_get_minor_version");

  const char *root = StringValueCStr (rootv);

  int r;

  r = guestfs_inspect_get_minor_version (g, root);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return INT2NUM (r);
}

/*
 * call-seq:
 *   g.inspect_get_product_name(root) -> string
 *
 * get product name of inspected operating system
 *
 * This returns the product name of the inspected operating
 * system. The product name is generally some freeform
 * string which can be displayed to the user, but should
 * not be parsed by programs.
 * 
 * If the product name could not be determined, then the
 * string "unknown" is returned.
 * 
 * Please read "INSPECTION" in guestfs(3) for more details.
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_inspect_get_product_name+[http://libguestfs.org/guestfs.3.html#guestfs_inspect_get_product_name]).
 */
static VALUE
ruby_guestfs_inspect_get_product_name (VALUE gv, VALUE rootv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "inspect_get_product_name");

  const char *root = StringValueCStr (rootv);

  char *r;

  r = guestfs_inspect_get_product_name (g, root);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  VALUE rv = rb_str_new2 (r);
  free (r);
  return rv;
}

/*
 * call-seq:
 *   g.inspect_get_mountpoints(root) -> hash
 *
 * get mountpoints of inspected operating system
 *
 * This returns a hash of where we think the filesystems
 * associated with this operating system should be mounted.
 * Callers should note that this is at best an educated
 * guess made by reading configuration files such as
 * "/etc/fstab". *In particular note* that this may return
 * filesystems which are non-existent or not mountable and
 * callers should be prepared to handle or ignore failures
 * if they try to mount them.
 * 
 * Each element in the returned hashtable has a key which
 * is the path of the mountpoint (eg. "/boot") and a value
 * which is the filesystem that would be mounted there (eg.
 * "/dev/sda1").
 * 
 * Non-mounted devices such as swap devices are *not*
 * returned in this list.
 * 
 * For operating systems like Windows which still use drive
 * letters, this call will only return an entry for the
 * first drive "mounted on" "/". For information about the
 * mapping of drive letters to partitions, see
 * "g.inspect_get_drive_mappings".
 * 
 * Please read "INSPECTION" in guestfs(3) for more details.
 * See also "g.inspect_get_filesystems".
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_inspect_get_mountpoints+[http://libguestfs.org/guestfs.3.html#guestfs_inspect_get_mountpoints]).
 */
static VALUE
ruby_guestfs_inspect_get_mountpoints (VALUE gv, VALUE rootv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "inspect_get_mountpoints");

  const char *root = StringValueCStr (rootv);

  char **r;

  r = guestfs_inspect_get_mountpoints (g, root);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  VALUE rv = rb_hash_new ();
  size_t i;
  for (i = 0; r[i] != NULL; i+=2) {
    rb_hash_aset (rv, rb_str_new2 (r[i]), rb_str_new2 (r[i+1]));
    free (r[i]);
    free (r[i+1]);
  }
  free (r);
  return rv;
}

/*
 * call-seq:
 *   g.inspect_get_filesystems(root) -> list
 *
 * get filesystems associated with inspected operating system
 *
 * This returns a list of all the filesystems that we think
 * are associated with this operating system. This includes
 * the root filesystem, other ordinary filesystems, and
 * non-mounted devices like swap partitions.
 * 
 * In the case of a multi-boot virtual machine, it is
 * possible for a filesystem to be shared between operating
 * systems.
 * 
 * Please read "INSPECTION" in guestfs(3) for more details.
 * See also "g.inspect_get_mountpoints".
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_inspect_get_filesystems+[http://libguestfs.org/guestfs.3.html#guestfs_inspect_get_filesystems]).
 */
static VALUE
ruby_guestfs_inspect_get_filesystems (VALUE gv, VALUE rootv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "inspect_get_filesystems");

  const char *root = StringValueCStr (rootv);

  char **r;

  r = guestfs_inspect_get_filesystems (g, root);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  size_t i, len = 0;
  for (i = 0; r[i] != NULL; ++i) len++;
  VALUE rv = rb_ary_new2 (len);
  for (i = 0; r[i] != NULL; ++i) {
    rb_ary_push (rv, rb_str_new2 (r[i]));
    free (r[i]);
  }
  free (r);
  return rv;
}

/*
 * call-seq:
 *   g.set_network(network) -> nil
 *
 * set enable network flag
 *
 * If "network" is true, then the network is enabled in the
 * libguestfs appliance. The default is false.
 * 
 * This affects whether commands are able to access the
 * network (see "RUNNING COMMANDS" in guestfs(3)).
 * 
 * You must call this before calling "g.launch", otherwise
 * it has no effect.
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_set_network+[http://libguestfs.org/guestfs.3.html#guestfs_set_network]).
 */
static VALUE
ruby_guestfs_set_network (VALUE gv, VALUE networkv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "set_network");

  int network = RTEST (networkv);

  int r;

  r = guestfs_set_network (g, network);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.get_network() -> [True|False]
 *
 * get enable network flag
 *
 * This returns the enable network flag.
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_get_network+[http://libguestfs.org/guestfs.3.html#guestfs_get_network]).
 */
static VALUE
ruby_guestfs_get_network (VALUE gv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "get_network");


  int r;

  r = guestfs_get_network (g);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return INT2NUM (r);
}

/*
 * call-seq:
 *   g.list_filesystems() -> hash
 *
 * list filesystems
 *
 * This inspection command looks for filesystems on
 * partitions, block devices and logical volumes, returning
 * a list of devices containing filesystems and their type.
 * 
 * The return value is a hash, where the keys are the
 * devices containing filesystems, and the values are the
 * filesystem types. For example:
 * 
 * "/dev/sda1" => "ntfs"
 * "/dev/sda2" => "ext2"
 * "/dev/vg_guest/lv_root" => "ext4"
 * "/dev/vg_guest/lv_swap" => "swap"
 * 
 * The value can have the special value "unknown", meaning
 * the content of the device is undetermined or empty.
 * "swap" means a Linux swap partition.
 * 
 * This command runs other libguestfs commands, which might
 * include "g.mount" and "g.umount", and therefore you
 * should use this soon after launch and only when nothing
 * is mounted.
 * 
 * Not all of the filesystems returned will be mountable.
 * In particular, swap partitions are returned in the list.
 * Also this command does not check that each filesystem
 * found is valid and mountable, and some filesystems might
 * be mountable but require special options. Filesystems
 * may not all belong to a single logical operating system
 * (use "g.inspect_os" to look for OSes).
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_list_filesystems+[http://libguestfs.org/guestfs.3.html#guestfs_list_filesystems]).
 */
static VALUE
ruby_guestfs_list_filesystems (VALUE gv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "list_filesystems");


  char **r;

  r = guestfs_list_filesystems (g);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  VALUE rv = rb_hash_new ();
  size_t i;
  for (i = 0; r[i] != NULL; i+=2) {
    rb_hash_aset (rv, rb_str_new2 (r[i]), rb_str_new2 (r[i+1]));
    free (r[i]);
    free (r[i+1]);
  }
  free (r);
  return rv;
}

/*
 * call-seq:
 *   g.add_drive_opts(filename, {optargs...}) -> nil
 *
 * add an image to examine or modify
 *
 * This function adds a virtual machine disk image
 * "filename" to libguestfs. The first time you call this
 * function, the disk appears as "/dev/sda", the second
 * time as "/dev/sdb", and so on.
 * 
 * You don't necessarily need to be root when using
 * libguestfs. However you obviously do need sufficient
 * permissions to access the filename for whatever
 * operations you want to perform (ie. read access if you
 * just want to read the image or write access if you want
 * to modify the image).
 * 
 * This call checks that "filename" exists.
 * 
 * The optional arguments are:
 * 
 * "readonly"
 * If true then the image is treated as read-only.
 * Writes are still allowed, but they are stored in a
 * temporary snapshot overlay which is discarded at the
 * end. The disk that you add is not modified.
 * 
 * "format"
 * This forces the image format. If you omit this (or
 * use "g.add_drive" or "g.add_drive_ro") then the
 * format is automatically detected. Possible formats
 * include "raw" and "qcow2".
 * 
 * Automatic detection of the format opens you up to a
 * potential security hole when dealing with untrusted
 * raw-format images. See CVE-2010-3851 and
 * RHBZ#642934. Specifying the format closes this
 * security hole.
 * 
 * "iface"
 * This rarely-used option lets you emulate the
 * behaviour of the deprecated "g.add_drive_with_if"
 * call (q.v.)
 * 
 * "name"
 * The name the drive had in the original guest, e.g.
 * /dev/sdb. This is used as a hint to the guest
 * inspection process if it is available.
 * 
 * Optional arguments are supplied in the final hash
 * parameter, which is a hash of the argument name to its
 * value. Pass an empty {} for no optional arguments.
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_add_drive_opts+[http://libguestfs.org/guestfs.3.html#guestfs_add_drive_opts]).
 */
static VALUE
ruby_guestfs_add_drive_opts (VALUE gv, VALUE filenamev, VALUE optargsv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "add_drive_opts");

  const char *filename = StringValueCStr (filenamev);

  Check_Type (optargsv, T_HASH);
  struct guestfs_add_drive_opts_argv optargs_s = { .bitmask = 0 };
  struct guestfs_add_drive_opts_argv *optargs = &optargs_s;
  VALUE v;
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("readonly")));
  if (v != Qnil) {
    optargs_s.readonly = RTEST (v);
    optargs_s.bitmask |= GUESTFS_ADD_DRIVE_OPTS_READONLY_BITMASK;
  }
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("format")));
  if (v != Qnil) {
    optargs_s.format = StringValueCStr (v);
    optargs_s.bitmask |= GUESTFS_ADD_DRIVE_OPTS_FORMAT_BITMASK;
  }
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("iface")));
  if (v != Qnil) {
    optargs_s.iface = StringValueCStr (v);
    optargs_s.bitmask |= GUESTFS_ADD_DRIVE_OPTS_IFACE_BITMASK;
  }
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("name")));
  if (v != Qnil) {
    optargs_s.name = StringValueCStr (v);
    optargs_s.bitmask |= GUESTFS_ADD_DRIVE_OPTS_NAME_BITMASK;
  }

  int r;

  r = guestfs_add_drive_opts_argv (g, filename, optargs);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.inspect_get_windows_systemroot(root) -> string
 *
 * get Windows systemroot of inspected operating system
 *
 * This returns the Windows systemroot of the inspected
 * guest. The systemroot is a directory path such as
 * "/WINDOWS".
 * 
 * This call assumes that the guest is Windows and that the
 * systemroot could be determined by inspection. If this is
 * not the case then an error is returned.
 * 
 * Please read "INSPECTION" in guestfs(3) for more details.
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_inspect_get_windows_systemroot+[http://libguestfs.org/guestfs.3.html#guestfs_inspect_get_windows_systemroot]).
 */
static VALUE
ruby_guestfs_inspect_get_windows_systemroot (VALUE gv, VALUE rootv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "inspect_get_windows_systemroot");

  const char *root = StringValueCStr (rootv);

  char *r;

  r = guestfs_inspect_get_windows_systemroot (g, root);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  VALUE rv = rb_str_new2 (r);
  free (r);
  return rv;
}

/*
 * call-seq:
 *   g.inspect_get_roots() -> list
 *
 * return list of operating systems found by last inspection
 *
 * This function is a convenient way to get the list of
 * root devices, as returned from a previous call to
 * "g.inspect_os", but without redoing the whole inspection
 * process.
 * 
 * This returns an empty list if either no root devices
 * were found or the caller has not called "g.inspect_os".
 * 
 * Please read "INSPECTION" in guestfs(3) for more details.
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_inspect_get_roots+[http://libguestfs.org/guestfs.3.html#guestfs_inspect_get_roots]).
 */
static VALUE
ruby_guestfs_inspect_get_roots (VALUE gv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "inspect_get_roots");


  char **r;

  r = guestfs_inspect_get_roots (g);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  size_t i, len = 0;
  for (i = 0; r[i] != NULL; ++i) len++;
  VALUE rv = rb_ary_new2 (len);
  for (i = 0; r[i] != NULL; ++i) {
    rb_ary_push (rv, rb_str_new2 (r[i]));
    free (r[i]);
  }
  free (r);
  return rv;
}

static VALUE
ruby_guestfs_debug_cmdline (VALUE gv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "debug_cmdline");


  char **r;

  r = guestfs_debug_cmdline (g);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  size_t i, len = 0;
  for (i = 0; r[i] != NULL; ++i) len++;
  VALUE rv = rb_ary_new2 (len);
  for (i = 0; r[i] != NULL; ++i) {
    rb_ary_push (rv, rb_str_new2 (r[i]));
    free (r[i]);
  }
  free (r);
  return rv;
}

static VALUE
ruby_guestfs_debug_drives (VALUE gv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "debug_drives");


  char **r;

  r = guestfs_debug_drives (g);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  size_t i, len = 0;
  for (i = 0; r[i] != NULL; ++i) len++;
  VALUE rv = rb_ary_new2 (len);
  for (i = 0; r[i] != NULL; ++i) {
    rb_ary_push (rv, rb_str_new2 (r[i]));
    free (r[i]);
  }
  free (r);
  return rv;
}

/*
 * call-seq:
 *   g.add_domain(dom, {optargs...}) -> fixnum
 *
 * add the disk(s) from a named libvirt domain
 *
 * This function adds the disk(s) attached to the named
 * libvirt domain "dom". It works by connecting to libvirt,
 * requesting the domain and domain XML from libvirt,
 * parsing it for disks, and calling "g.add_drive_opts" on
 * each one.
 * 
 * The number of disks added is returned. This operation is
 * atomic: if an error is returned, then no disks are
 * added.
 * 
 * This function does some minimal checks to make sure the
 * libvirt domain is not running (unless "readonly" is
 * true). In a future version we will try to acquire the
 * libvirt lock on each disk.
 * 
 * Disks must be accessible locally. This often means that
 * adding disks from a remote libvirt connection (see
 * <http://libvirt.org/remote.html>) will fail unless those
 * disks are accessible via the same device path locally
 * too.
 * 
 * The optional "libvirturi" parameter sets the libvirt URI
 * (see <http://libvirt.org/uri.html>). If this is not set
 * then we connect to the default libvirt URI (or one set
 * through an environment variable, see the libvirt
 * documentation for full details).
 * 
 * The optional "live" flag controls whether this call will
 * try to connect to a running virtual machine "guestfsd"
 * process if it sees a suitable <channel> element in the
 * libvirt XML definition. The default (if the flag is
 * omitted) is never to try. See "ATTACHING TO RUNNING
 * DAEMONS" in guestfs(3) for more information.
 * 
 * If the "allowuuid" flag is true (default is false) then
 * a UUID *may* be passed instead of the domain name. The
 * "dom" string is treated as a UUID first and looked up,
 * and if that lookup fails then we treat "dom" as a name
 * as usual.
 * 
 * The optional "readonlydisk" parameter controls what we
 * do for disks which are marked <readonly/> in the libvirt
 * XML. Possible values are:
 * 
 * readonlydisk = "error"
 * If "readonly" is false:
 * 
 * The whole call is aborted with an error if any disk
 * with the <readonly/> flag is found.
 * 
 * If "readonly" is true:
 * 
 * Disks with the <readonly/> flag are added read-only.
 * 
 * readonlydisk = "read"
 * If "readonly" is false:
 * 
 * Disks with the <readonly/> flag are added read-only.
 * Other disks are added read/write.
 * 
 * If "readonly" is true:
 * 
 * Disks with the <readonly/> flag are added read-only.
 * 
 * readonlydisk = "write" (default)
 * If "readonly" is false:
 * 
 * Disks with the <readonly/> flag are added
 * read/write.
 * 
 * If "readonly" is true:
 * 
 * Disks with the <readonly/> flag are added read-only.
 * 
 * readonlydisk = "ignore"
 * If "readonly" is true or false:
 * 
 * Disks with the <readonly/> flag are skipped.
 * 
 * The other optional parameters are passed directly
 * through to "g.add_drive_opts".
 * 
 * Optional arguments are supplied in the final hash
 * parameter, which is a hash of the argument name to its
 * value. Pass an empty {} for no optional arguments.
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_add_domain+[http://libguestfs.org/guestfs.3.html#guestfs_add_domain]).
 */
static VALUE
ruby_guestfs_add_domain (VALUE gv, VALUE domv, VALUE optargsv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "add_domain");

  const char *dom = StringValueCStr (domv);

  Check_Type (optargsv, T_HASH);
  struct guestfs_add_domain_argv optargs_s = { .bitmask = 0 };
  struct guestfs_add_domain_argv *optargs = &optargs_s;
  VALUE v;
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("libvirturi")));
  if (v != Qnil) {
    optargs_s.libvirturi = StringValueCStr (v);
    optargs_s.bitmask |= GUESTFS_ADD_DOMAIN_LIBVIRTURI_BITMASK;
  }
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("readonly")));
  if (v != Qnil) {
    optargs_s.readonly = RTEST (v);
    optargs_s.bitmask |= GUESTFS_ADD_DOMAIN_READONLY_BITMASK;
  }
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("iface")));
  if (v != Qnil) {
    optargs_s.iface = StringValueCStr (v);
    optargs_s.bitmask |= GUESTFS_ADD_DOMAIN_IFACE_BITMASK;
  }
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("live")));
  if (v != Qnil) {
    optargs_s.live = RTEST (v);
    optargs_s.bitmask |= GUESTFS_ADD_DOMAIN_LIVE_BITMASK;
  }
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("allowuuid")));
  if (v != Qnil) {
    optargs_s.allowuuid = RTEST (v);
    optargs_s.bitmask |= GUESTFS_ADD_DOMAIN_ALLOWUUID_BITMASK;
  }
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("readonlydisk")));
  if (v != Qnil) {
    optargs_s.readonlydisk = StringValueCStr (v);
    optargs_s.bitmask |= GUESTFS_ADD_DOMAIN_READONLYDISK_BITMASK;
  }

  int r;

  r = guestfs_add_domain_argv (g, dom, optargs);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return INT2NUM (r);
}

/*
 * call-seq:
 *   g.inspect_get_package_format(root) -> string
 *
 * get package format used by the operating system
 *
 * This function and "g.inspect_get_package_management"
 * return the package format and package management tool
 * used by the inspected operating system. For example for
 * Fedora these functions would return "rpm" (package
 * format) and "yum" (package management).
 * 
 * This returns the string "unknown" if we could not
 * determine the package format *or* if the operating
 * system does not have a real packaging system (eg.
 * Windows).
 * 
 * Possible strings include: "rpm", "deb", "ebuild",
 * "pisi", "pacman", "pkgsrc". Future versions of
 * libguestfs may return other strings.
 * 
 * Please read "INSPECTION" in guestfs(3) for more details.
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_inspect_get_package_format+[http://libguestfs.org/guestfs.3.html#guestfs_inspect_get_package_format]).
 */
static VALUE
ruby_guestfs_inspect_get_package_format (VALUE gv, VALUE rootv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "inspect_get_package_format");

  const char *root = StringValueCStr (rootv);

  char *r;

  r = guestfs_inspect_get_package_format (g, root);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  VALUE rv = rb_str_new2 (r);
  free (r);
  return rv;
}

/*
 * call-seq:
 *   g.inspect_get_package_management(root) -> string
 *
 * get package management tool used by the operating system
 *
 * "g.inspect_get_package_format" and this function return
 * the package format and package management tool used by
 * the inspected operating system. For example for Fedora
 * these functions would return "rpm" (package format) and
 * "yum" (package management).
 * 
 * This returns the string "unknown" if we could not
 * determine the package management tool *or* if the
 * operating system does not have a real packaging system
 * (eg. Windows).
 * 
 * Possible strings include: "yum", "up2date", "apt" (for
 * all Debian derivatives), "portage", "pisi", "pacman",
 * "urpmi", "zypper". Future versions of libguestfs may
 * return other strings.
 * 
 * Please read "INSPECTION" in guestfs(3) for more details.
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_inspect_get_package_management+[http://libguestfs.org/guestfs.3.html#guestfs_inspect_get_package_management]).
 */
static VALUE
ruby_guestfs_inspect_get_package_management (VALUE gv, VALUE rootv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "inspect_get_package_management");

  const char *root = StringValueCStr (rootv);

  char *r;

  r = guestfs_inspect_get_package_management (g, root);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  VALUE rv = rb_str_new2 (r);
  free (r);
  return rv;
}

/*
 * call-seq:
 *   g.inspect_list_applications(root) -> list
 *
 * get list of applications installed in the operating system
 *
 * Return the list of applications installed in the
 * operating system.
 * 
 * *Note:* This call works differently from other parts of
 * the inspection API. You have to call "g.inspect_os",
 * then "g.inspect_get_mountpoints", then mount up the
 * disks, before calling this. Listing applications is a
 * significantly more difficult operation which requires
 * access to the full filesystem. Also note that unlike the
 * other "g.inspect_get_*" calls which are just returning
 * data cached in the libguestfs handle, this call actually
 * reads parts of the mounted filesystems during the call.
 * 
 * This returns an empty list if the inspection code was
 * not able to determine the list of applications.
 * 
 * The application structure contains the following fields:
 * 
 * "app_name"
 * The name of the application. For Red Hat-derived and
 * Debian-derived Linux guests, this is the package
 * name.
 * 
 * "app_display_name"
 * The display name of the application, sometimes
 * localized to the install language of the guest
 * operating system.
 * 
 * If unavailable this is returned as an empty string
 * "". Callers needing to display something can use
 * "app_name" instead.
 * 
 * "app_epoch"
 * For package managers which use epochs, this contains
 * the epoch of the package (an integer). If
 * unavailable, this is returned as 0.
 * 
 * "app_version"
 * The version string of the application or package. If
 * unavailable this is returned as an empty string "".
 * 
 * "app_release"
 * The release string of the application or package,
 * for package managers that use this. If unavailable
 * this is returned as an empty string "".
 * 
 * "app_install_path"
 * The installation path of the application (on
 * operating systems such as Windows which use
 * installation paths). This path is in the format used
 * by the guest operating system, it is not a
 * libguestfs path.
 * 
 * If unavailable this is returned as an empty string
 * "".
 * 
 * "app_trans_path"
 * The install path translated into a libguestfs path.
 * If unavailable this is returned as an empty string
 * "".
 * 
 * "app_publisher"
 * The name of the publisher of the application, for
 * package managers that use this. If unavailable this
 * is returned as an empty string "".
 * 
 * "app_url"
 * The URL (eg. upstream URL) of the application. If
 * unavailable this is returned as an empty string "".
 * 
 * "app_source_package"
 * For packaging systems which support this, the name
 * of the source package. If unavailable this is
 * returned as an empty string "".
 * 
 * "app_summary"
 * A short (usually one line) description of the
 * application or package. If unavailable this is
 * returned as an empty string "".
 * 
 * "app_description"
 * A longer description of the application or package.
 * If unavailable this is returned as an empty string
 * "".
 * 
 * Please read "INSPECTION" in guestfs(3) for more details.
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_inspect_list_applications+[http://libguestfs.org/guestfs.3.html#guestfs_inspect_list_applications]).
 */
static VALUE
ruby_guestfs_inspect_list_applications (VALUE gv, VALUE rootv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "inspect_list_applications");

  const char *root = StringValueCStr (rootv);

  struct guestfs_application_list *r;

  r = guestfs_inspect_list_applications (g, root);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  VALUE rv = rb_ary_new2 (r->len);
  size_t i;
  for (i = 0; i < r->len; ++i) {
    VALUE hv = rb_hash_new ();
    rb_hash_aset (hv, rb_str_new2 ("app_name"), rb_str_new2 (r->val[i].app_name));
    rb_hash_aset (hv, rb_str_new2 ("app_display_name"), rb_str_new2 (r->val[i].app_display_name));
    rb_hash_aset (hv, rb_str_new2 ("app_epoch"), INT2NUM (r->val[i].app_epoch));
    rb_hash_aset (hv, rb_str_new2 ("app_version"), rb_str_new2 (r->val[i].app_version));
    rb_hash_aset (hv, rb_str_new2 ("app_release"), rb_str_new2 (r->val[i].app_release));
    rb_hash_aset (hv, rb_str_new2 ("app_install_path"), rb_str_new2 (r->val[i].app_install_path));
    rb_hash_aset (hv, rb_str_new2 ("app_trans_path"), rb_str_new2 (r->val[i].app_trans_path));
    rb_hash_aset (hv, rb_str_new2 ("app_publisher"), rb_str_new2 (r->val[i].app_publisher));
    rb_hash_aset (hv, rb_str_new2 ("app_url"), rb_str_new2 (r->val[i].app_url));
    rb_hash_aset (hv, rb_str_new2 ("app_source_package"), rb_str_new2 (r->val[i].app_source_package));
    rb_hash_aset (hv, rb_str_new2 ("app_summary"), rb_str_new2 (r->val[i].app_summary));
    rb_hash_aset (hv, rb_str_new2 ("app_description"), rb_str_new2 (r->val[i].app_description));
    rb_ary_push (rv, hv);
  }
  guestfs_free_application_list (r);
  return rv;
}

/*
 * call-seq:
 *   g.inspect_get_hostname(root) -> string
 *
 * get hostname of the operating system
 *
 * This function returns the hostname of the operating
 * system as found by inspection of the guest's
 * configuration files.
 * 
 * If the hostname could not be determined, then the string
 * "unknown" is returned.
 * 
 * Please read "INSPECTION" in guestfs(3) for more details.
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_inspect_get_hostname+[http://libguestfs.org/guestfs.3.html#guestfs_inspect_get_hostname]).
 */
static VALUE
ruby_guestfs_inspect_get_hostname (VALUE gv, VALUE rootv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "inspect_get_hostname");

  const char *root = StringValueCStr (rootv);

  char *r;

  r = guestfs_inspect_get_hostname (g, root);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  VALUE rv = rb_str_new2 (r);
  free (r);
  return rv;
}

/*
 * call-seq:
 *   g.inspect_get_format(root) -> string
 *
 * get format of inspected operating system
 *
 * This returns the format of the inspected operating
 * system. You can use it to detect install images, live
 * CDs and similar.
 * 
 * Currently defined formats are:
 * 
 * "installed"
 * This is an installed operating system.
 * 
 * "installer"
 * The disk image being inspected is not an installed
 * operating system, but a *bootable* install disk,
 * live CD, or similar.
 * 
 * "unknown"
 * The format of this disk image is not known.
 * 
 * Future versions of libguestfs may return other strings
 * here. The caller should be prepared to handle any
 * string.
 * 
 * Please read "INSPECTION" in guestfs(3) for more details.
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_inspect_get_format+[http://libguestfs.org/guestfs.3.html#guestfs_inspect_get_format]).
 */
static VALUE
ruby_guestfs_inspect_get_format (VALUE gv, VALUE rootv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "inspect_get_format");

  const char *root = StringValueCStr (rootv);

  char *r;

  r = guestfs_inspect_get_format (g, root);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  VALUE rv = rb_str_new2 (r);
  free (r);
  return rv;
}

/*
 * call-seq:
 *   g.inspect_is_live(root) -> [True|False]
 *
 * get live flag for install disk
 *
 * If "g.inspect_get_format" returns "installer" (this is
 * an install disk), then this returns true if a live image
 * was detected on the disk.
 * 
 * Please read "INSPECTION" in guestfs(3) for more details.
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_inspect_is_live+[http://libguestfs.org/guestfs.3.html#guestfs_inspect_is_live]).
 */
static VALUE
ruby_guestfs_inspect_is_live (VALUE gv, VALUE rootv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "inspect_is_live");

  const char *root = StringValueCStr (rootv);

  int r;

  r = guestfs_inspect_is_live (g, root);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return INT2NUM (r);
}

/*
 * call-seq:
 *   g.inspect_is_netinst(root) -> [True|False]
 *
 * get netinst (network installer) flag for install disk
 *
 * If "g.inspect_get_format" returns "installer" (this is
 * an install disk), then this returns true if the disk is
 * a network installer, ie. not a self-contained install CD
 * but one which is likely to require network access to
 * complete the install.
 * 
 * Please read "INSPECTION" in guestfs(3) for more details.
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_inspect_is_netinst+[http://libguestfs.org/guestfs.3.html#guestfs_inspect_is_netinst]).
 */
static VALUE
ruby_guestfs_inspect_is_netinst (VALUE gv, VALUE rootv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "inspect_is_netinst");

  const char *root = StringValueCStr (rootv);

  int r;

  r = guestfs_inspect_is_netinst (g, root);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return INT2NUM (r);
}

/*
 * call-seq:
 *   g.inspect_is_multipart(root) -> [True|False]
 *
 * get multipart flag for install disk
 *
 * If "g.inspect_get_format" returns "installer" (this is
 * an install disk), then this returns true if the disk is
 * part of a set.
 * 
 * Please read "INSPECTION" in guestfs(3) for more details.
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_inspect_is_multipart+[http://libguestfs.org/guestfs.3.html#guestfs_inspect_is_multipart]).
 */
static VALUE
ruby_guestfs_inspect_is_multipart (VALUE gv, VALUE rootv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "inspect_is_multipart");

  const char *root = StringValueCStr (rootv);

  int r;

  r = guestfs_inspect_is_multipart (g, root);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return INT2NUM (r);
}

/*
 * call-seq:
 *   g.set_attach_method(attachmethod) -> nil
 *
 * set the attach method
 *
 * Set the method that libguestfs uses to connect to the
 * back end guestfsd daemon. Possible methods are:
 * 
 * "appliance"
 * Launch an appliance and connect to it. This is the
 * ordinary method and the default.
 * 
 * "unix:*path*"
 * Connect to the Unix domain socket *path*.
 * 
 * This method lets you connect to an existing daemon
 * or (using virtio-serial) to a live guest. For more
 * information, see "ATTACHING TO RUNNING DAEMONS" in
 * guestfs(3).
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_set_attach_method+[http://libguestfs.org/guestfs.3.html#guestfs_set_attach_method]).
 */
static VALUE
ruby_guestfs_set_attach_method (VALUE gv, VALUE attachmethodv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "set_attach_method");

  const char *attachmethod = StringValueCStr (attachmethodv);

  int r;

  r = guestfs_set_attach_method (g, attachmethod);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.get_attach_method() -> string
 *
 * get the attach method
 *
 * Return the current attach method. See
 * "g.set_attach_method".
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_get_attach_method+[http://libguestfs.org/guestfs.3.html#guestfs_get_attach_method]).
 */
static VALUE
ruby_guestfs_get_attach_method (VALUE gv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "get_attach_method");


  char *r;

  r = guestfs_get_attach_method (g);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  VALUE rv = rb_str_new2 (r);
  free (r);
  return rv;
}

/*
 * call-seq:
 *   g.inspect_get_product_variant(root) -> string
 *
 * get product variant of inspected operating system
 *
 * This returns the product variant of the inspected
 * operating system.
 * 
 * For Windows guests, this returns the contents of the
 * Registry key "HKLM\Software\Microsoft\Windows
 * NT\CurrentVersion" "InstallationType" which is usually a
 * string such as "Client" or "Server" (other values are
 * possible). This can be used to distinguish consumer and
 * enterprise versions of Windows that have the same
 * version number (for example, Windows 7 and Windows 2008
 * Server are both version 6.1, but the former is "Client"
 * and the latter is "Server").
 * 
 * For enterprise Linux guests, in future we intend this to
 * return the product variant such as "Desktop", "Server"
 * and so on. But this is not implemented at present.
 * 
 * If the product variant could not be determined, then the
 * string "unknown" is returned.
 * 
 * Please read "INSPECTION" in guestfs(3) for more details.
 * See also "g.inspect_get_product_name",
 * "g.inspect_get_major_version".
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_inspect_get_product_variant+[http://libguestfs.org/guestfs.3.html#guestfs_inspect_get_product_variant]).
 */
static VALUE
ruby_guestfs_inspect_get_product_variant (VALUE gv, VALUE rootv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "inspect_get_product_variant");

  const char *root = StringValueCStr (rootv);

  char *r;

  r = guestfs_inspect_get_product_variant (g, root);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  VALUE rv = rb_str_new2 (r);
  free (r);
  return rv;
}

/*
 * call-seq:
 *   g.inspect_get_windows_current_control_set(root) -> string
 *
 * get Windows CurrentControlSet of inspected operating system
 *
 * This returns the Windows CurrentControlSet of the
 * inspected guest. The CurrentControlSet is a registry key
 * name such as "ControlSet001".
 * 
 * This call assumes that the guest is Windows and that the
 * Registry could be examined by inspection. If this is not
 * the case then an error is returned.
 * 
 * Please read "INSPECTION" in guestfs(3) for more details.
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_inspect_get_windows_current_control_set+[http://libguestfs.org/guestfs.3.html#guestfs_inspect_get_windows_current_control_set]).
 */
static VALUE
ruby_guestfs_inspect_get_windows_current_control_set (VALUE gv, VALUE rootv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "inspect_get_windows_current_control_set");

  const char *root = StringValueCStr (rootv);

  char *r;

  r = guestfs_inspect_get_windows_current_control_set (g, root);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  VALUE rv = rb_str_new2 (r);
  free (r);
  return rv;
}

/*
 * call-seq:
 *   g.inspect_get_drive_mappings(root) -> hash
 *
 * get drive letter mappings
 *
 * This call is useful for Windows which uses a primitive
 * system of assigning drive letters (like "C:") to
 * partitions. This inspection API examines the Windows
 * Registry to find out how disks/partitions are mapped to
 * drive letters, and returns a hash table as in the
 * example below:
 * 
 * C      =>     /dev/vda2
 * E      =>     /dev/vdb1
 * F      =>     /dev/vdc1
 * 
 * Note that keys are drive letters. For Windows, the key
 * is case insensitive and just contains the drive letter,
 * without the customary colon separator character.
 * 
 * In future we may support other operating systems that
 * also used drive letters, but the keys for those might
 * not be case insensitive and might be longer than 1
 * character. For example in OS-9, hard drives were named
 * "h0", "h1" etc.
 * 
 * For Windows guests, currently only hard drive mappings
 * are returned. Removable disks (eg. DVD-ROMs) are
 * ignored.
 * 
 * For guests that do not use drive mappings, or if the
 * drive mappings could not be determined, this returns an
 * empty hash table.
 * 
 * Please read "INSPECTION" in guestfs(3) for more details.
 * See also "g.inspect_get_mountpoints",
 * "g.inspect_get_filesystems".
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_inspect_get_drive_mappings+[http://libguestfs.org/guestfs.3.html#guestfs_inspect_get_drive_mappings]).
 */
static VALUE
ruby_guestfs_inspect_get_drive_mappings (VALUE gv, VALUE rootv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "inspect_get_drive_mappings");

  const char *root = StringValueCStr (rootv);

  char **r;

  r = guestfs_inspect_get_drive_mappings (g, root);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  VALUE rv = rb_hash_new ();
  size_t i;
  for (i = 0; r[i] != NULL; i+=2) {
    rb_hash_aset (rv, rb_str_new2 (r[i]), rb_str_new2 (r[i+1]));
    free (r[i]);
    free (r[i+1]);
  }
  free (r);
  return rv;
}

/*
 * call-seq:
 *   g.inspect_get_icon(root, {optargs...}) -> string
 *
 * get the icon corresponding to this operating system
 *
 * This function returns an icon corresponding to the
 * inspected operating system. The icon is returned as a
 * buffer containing a PNG image (re-encoded to PNG if
 * necessary).
 * 
 * If it was not possible to get an icon this function
 * returns a zero-length (non-NULL) buffer. *Callers must
 * check for this case*.
 * 
 * Libguestfs will start by looking for a file called
 * "/etc/favicon.png" or "C:\etc\favicon.png" and if it has
 * the correct format, the contents of this file will be
 * returned. You can disable favicons by passing the
 * optional "favicon" boolean as false (default is true).
 * 
 * If finding the favicon fails, then we look in other
 * places in the guest for a suitable icon.
 * 
 * If the optional "highquality" boolean is true then only
 * high quality icons are returned, which means only icons
 * of high resolution with an alpha channel. The default
 * (false) is to return any icon we can, even if it is of
 * substandard quality.
 * 
 * Notes:
 * 
 * *   Unlike most other inspection API calls, the guest's
 * disks must be mounted up before you call this, since
 * it needs to read information from the guest
 * filesystem during the call.
 * 
 * *   Security: The icon data comes from the untrusted
 * guest, and should be treated with caution. PNG files
 * have been known to contain exploits. Ensure that
 * libpng (or other relevant libraries) are fully up to
 * date before trying to process or display the icon.
 * 
 * *   The PNG image returned can be any size. It might not
 * be square. Libguestfs tries to return the largest,
 * highest quality icon available. The application must
 * scale the icon to the required size.
 * 
 * *   Extracting icons from Windows guests requires the
 * external "wrestool" program from the "icoutils"
 * package, and several programs ("bmptopnm",
 * "pnmtopng", "pamcut") from the "netpbm" package.
 * These must be installed separately.
 * 
 * *   Operating system icons are usually trademarks. Seek
 * legal advice before using trademarks in
 * applications.
 * 
 * Optional arguments are supplied in the final hash
 * parameter, which is a hash of the argument name to its
 * value. Pass an empty {} for no optional arguments.
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_inspect_get_icon+[http://libguestfs.org/guestfs.3.html#guestfs_inspect_get_icon]).
 */
static VALUE
ruby_guestfs_inspect_get_icon (VALUE gv, VALUE rootv, VALUE optargsv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "inspect_get_icon");

  const char *root = StringValueCStr (rootv);

  Check_Type (optargsv, T_HASH);
  struct guestfs_inspect_get_icon_argv optargs_s = { .bitmask = 0 };
  struct guestfs_inspect_get_icon_argv *optargs = &optargs_s;
  VALUE v;
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("favicon")));
  if (v != Qnil) {
    optargs_s.favicon = RTEST (v);
    optargs_s.bitmask |= GUESTFS_INSPECT_GET_ICON_FAVICON_BITMASK;
  }
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("highquality")));
  if (v != Qnil) {
    optargs_s.highquality = RTEST (v);
    optargs_s.bitmask |= GUESTFS_INSPECT_GET_ICON_HIGHQUALITY_BITMASK;
  }

  char *r;
  size_t size;

  r = guestfs_inspect_get_icon_argv (g, root, &size, optargs);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  VALUE rv = rb_str_new (r, size);
  free (r);
  return rv;
}

/*
 * call-seq:
 *   g.set_pgroup(pgroup) -> nil
 *
 * set process group flag
 *
 * If "pgroup" is true, child processes are placed into
 * their own process group.
 * 
 * The practical upshot of this is that signals like
 * "SIGINT" (from users pressing "^C") won't be received by
 * the child process.
 * 
 * The default for this flag is false, because usually you
 * want "^C" to kill the subprocess.
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_set_pgroup+[http://libguestfs.org/guestfs.3.html#guestfs_set_pgroup]).
 */
static VALUE
ruby_guestfs_set_pgroup (VALUE gv, VALUE pgroupv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "set_pgroup");

  int pgroup = RTEST (pgroupv);

  int r;

  r = guestfs_set_pgroup (g, pgroup);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.get_pgroup() -> [True|False]
 *
 * get process group flag
 *
 * This returns the process group flag.
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_get_pgroup+[http://libguestfs.org/guestfs.3.html#guestfs_get_pgroup]).
 */
static VALUE
ruby_guestfs_get_pgroup (VALUE gv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "get_pgroup");


  int r;

  r = guestfs_get_pgroup (g);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return INT2NUM (r);
}

/*
 * call-seq:
 *   g.set_smp(smp) -> nil
 *
 * set number of virtual CPUs in appliance
 *
 * Change the number of virtual CPUs assigned to the
 * appliance. The default is 1. Increasing this may improve
 * performance, though often it has no effect.
 * 
 * This function must be called before "g.launch".
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_set_smp+[http://libguestfs.org/guestfs.3.html#guestfs_set_smp]).
 */
static VALUE
ruby_guestfs_set_smp (VALUE gv, VALUE smpv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "set_smp");

  int smp = NUM2INT (smpv);

  int r;

  r = guestfs_set_smp (g, smp);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.get_smp() -> fixnum
 *
 * get number of virtual CPUs in appliance
 *
 * This returns the number of virtual CPUs assigned to the
 * appliance.
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_get_smp+[http://libguestfs.org/guestfs.3.html#guestfs_get_smp]).
 */
static VALUE
ruby_guestfs_get_smp (VALUE gv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "get_smp");


  int r;

  r = guestfs_get_smp (g);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return INT2NUM (r);
}

/*
 * call-seq:
 *   g.mount(device, mountpoint) -> nil
 *
 * mount a guest disk at a position in the filesystem
 *
 * Mount a guest disk at a position in the filesystem.
 * Block devices are named "/dev/sda", "/dev/sdb" and so
 * on, as they were added to the guest. If those block
 * devices contain partitions, they will have the usual
 * names (eg. "/dev/sda1"). Also LVM "/dev/VG/LV"-style
 * names can be used.
 * 
 * The rules are the same as for mount(2): A filesystem
 * must first be mounted on "/" before others can be
 * mounted. Other filesystems can only be mounted on
 * directories which already exist.
 * 
 * The mounted filesystem is writable, if we have
 * sufficient permissions on the underlying device.
 * 
 * Before libguestfs 1.13.16, this call implicitly added
 * the options "sync" and "noatime". The "sync" option
 * greatly slowed writes and caused many problems for
 * users. If your program might need to work with older
 * versions of libguestfs, use "g.mount_options" instead
 * (using an empty string for the first parameter if you
 * don't want any options).
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_mount+[http://libguestfs.org/guestfs.3.html#guestfs_mount]).
 */
static VALUE
ruby_guestfs_mount (VALUE gv, VALUE devicev, VALUE mountpointv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "mount");

  const char *device = StringValueCStr (devicev);
  const char *mountpoint = StringValueCStr (mountpointv);

  int r;

  r = guestfs_mount (g, device, mountpoint);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.sync() -> nil
 *
 * sync disks, writes are flushed through to the disk image
 *
 * This syncs the disk, so that any writes are flushed
 * through to the underlying disk image.
 * 
 * You should always call this if you have modified a disk
 * image, before closing the handle.
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_sync+[http://libguestfs.org/guestfs.3.html#guestfs_sync]).
 */
static VALUE
ruby_guestfs_sync (VALUE gv)
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

/*
 * call-seq:
 *   g.touch(path) -> nil
 *
 * update file timestamps or create a new file
 *
 * Touch acts like the touch(1) command. It can be used to
 * update the timestamps on a file, or, if the file does
 * not exist, to create a new zero-length file.
 * 
 * This command only works on regular files, and will fail
 * on other file types such as directories, symbolic links,
 * block special etc.
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_touch+[http://libguestfs.org/guestfs.3.html#guestfs_touch]).
 */
static VALUE
ruby_guestfs_touch (VALUE gv, VALUE pathv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "touch");

  const char *path = StringValueCStr (pathv);

  int r;

  r = guestfs_touch (g, path);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.cat(path) -> string
 *
 * list the contents of a file
 *
 * Return the contents of the file named "path".
 * 
 * Note that this function cannot correctly handle binary
 * files (specifically, files containing "\0" character
 * which is treated as end of string). For those you need
 * to use the "g.read_file" or "g.download" functions which
 * have a more complex interface.
 * 
 * Because of the message protocol, there is a transfer
 * limit of somewhere between 2MB and 4MB. See "PROTOCOL
 * LIMITS" in guestfs(3).
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_cat+[http://libguestfs.org/guestfs.3.html#guestfs_cat]).
 */
static VALUE
ruby_guestfs_cat (VALUE gv, VALUE pathv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "cat");

  const char *path = StringValueCStr (pathv);

  char *r;

  r = guestfs_cat (g, path);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  VALUE rv = rb_str_new2 (r);
  free (r);
  return rv;
}

/*
 * call-seq:
 *   g.ll(directory) -> string
 *
 * list the files in a directory (long format)
 *
 * List the files in "directory" (relative to the root
 * directory, there is no cwd) in the format of 'ls -la'.
 * 
 * This command is mostly useful for interactive sessions.
 * It is *not* intended that you try to parse the output
 * string.
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_ll+[http://libguestfs.org/guestfs.3.html#guestfs_ll]).
 */
static VALUE
ruby_guestfs_ll (VALUE gv, VALUE directoryv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "ll");

  const char *directory = StringValueCStr (directoryv);

  char *r;

  r = guestfs_ll (g, directory);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  VALUE rv = rb_str_new2 (r);
  free (r);
  return rv;
}

/*
 * call-seq:
 *   g.ls(directory) -> list
 *
 * list the files in a directory
 *
 * List the files in "directory" (relative to the root
 * directory, there is no cwd). The '.' and '..' entries
 * are not returned, but hidden files are shown.
 * 
 * This command is mostly useful for interactive sessions.
 * Programs should probably use "g.readdir" instead.
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_ls+[http://libguestfs.org/guestfs.3.html#guestfs_ls]).
 */
static VALUE
ruby_guestfs_ls (VALUE gv, VALUE directoryv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "ls");

  const char *directory = StringValueCStr (directoryv);

  char **r;

  r = guestfs_ls (g, directory);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  size_t i, len = 0;
  for (i = 0; r[i] != NULL; ++i) len++;
  VALUE rv = rb_ary_new2 (len);
  for (i = 0; r[i] != NULL; ++i) {
    rb_ary_push (rv, rb_str_new2 (r[i]));
    free (r[i]);
  }
  free (r);
  return rv;
}

/*
 * call-seq:
 *   g.list_devices() -> list
 *
 * list the block devices
 *
 * List all the block devices.
 * 
 * The full block device names are returned, eg.
 * "/dev/sda".
 * 
 * See also "g.list_filesystems".
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_list_devices+[http://libguestfs.org/guestfs.3.html#guestfs_list_devices]).
 */
static VALUE
ruby_guestfs_list_devices (VALUE gv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "list_devices");


  char **r;

  r = guestfs_list_devices (g);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  size_t i, len = 0;
  for (i = 0; r[i] != NULL; ++i) len++;
  VALUE rv = rb_ary_new2 (len);
  for (i = 0; r[i] != NULL; ++i) {
    rb_ary_push (rv, rb_str_new2 (r[i]));
    free (r[i]);
  }
  free (r);
  return rv;
}

/*
 * call-seq:
 *   g.list_partitions() -> list
 *
 * list the partitions
 *
 * List all the partitions detected on all block devices.
 * 
 * The full partition device names are returned, eg.
 * "/dev/sda1"
 * 
 * This does not return logical volumes. For that you will
 * need to call "g.lvs".
 * 
 * See also "g.list_filesystems".
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_list_partitions+[http://libguestfs.org/guestfs.3.html#guestfs_list_partitions]).
 */
static VALUE
ruby_guestfs_list_partitions (VALUE gv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "list_partitions");


  char **r;

  r = guestfs_list_partitions (g);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  size_t i, len = 0;
  for (i = 0; r[i] != NULL; ++i) len++;
  VALUE rv = rb_ary_new2 (len);
  for (i = 0; r[i] != NULL; ++i) {
    rb_ary_push (rv, rb_str_new2 (r[i]));
    free (r[i]);
  }
  free (r);
  return rv;
}

/*
 * call-seq:
 *   g.pvs() -> list
 *
 * list the LVM physical volumes (PVs)
 *
 * List all the physical volumes detected. This is the
 * equivalent of the pvs(8) command.
 * 
 * This returns a list of just the device names that
 * contain PVs (eg. "/dev/sda2").
 * 
 * See also "g.pvs_full".
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_pvs+[http://libguestfs.org/guestfs.3.html#guestfs_pvs]).
 */
static VALUE
ruby_guestfs_pvs (VALUE gv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "pvs");


  char **r;

  r = guestfs_pvs (g);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  size_t i, len = 0;
  for (i = 0; r[i] != NULL; ++i) len++;
  VALUE rv = rb_ary_new2 (len);
  for (i = 0; r[i] != NULL; ++i) {
    rb_ary_push (rv, rb_str_new2 (r[i]));
    free (r[i]);
  }
  free (r);
  return rv;
}

/*
 * call-seq:
 *   g.vgs() -> list
 *
 * list the LVM volume groups (VGs)
 *
 * List all the volumes groups detected. This is the
 * equivalent of the vgs(8) command.
 * 
 * This returns a list of just the volume group names that
 * were detected (eg. "VolGroup00").
 * 
 * See also "g.vgs_full".
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_vgs+[http://libguestfs.org/guestfs.3.html#guestfs_vgs]).
 */
static VALUE
ruby_guestfs_vgs (VALUE gv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "vgs");


  char **r;

  r = guestfs_vgs (g);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  size_t i, len = 0;
  for (i = 0; r[i] != NULL; ++i) len++;
  VALUE rv = rb_ary_new2 (len);
  for (i = 0; r[i] != NULL; ++i) {
    rb_ary_push (rv, rb_str_new2 (r[i]));
    free (r[i]);
  }
  free (r);
  return rv;
}

/*
 * call-seq:
 *   g.lvs() -> list
 *
 * list the LVM logical volumes (LVs)
 *
 * List all the logical volumes detected. This is the
 * equivalent of the lvs(8) command.
 * 
 * This returns a list of the logical volume device names
 * (eg. "/dev/VolGroup00/LogVol00").
 * 
 * See also "g.lvs_full", "g.list_filesystems".
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_lvs+[http://libguestfs.org/guestfs.3.html#guestfs_lvs]).
 */
static VALUE
ruby_guestfs_lvs (VALUE gv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "lvs");


  char **r;

  r = guestfs_lvs (g);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  size_t i, len = 0;
  for (i = 0; r[i] != NULL; ++i) len++;
  VALUE rv = rb_ary_new2 (len);
  for (i = 0; r[i] != NULL; ++i) {
    rb_ary_push (rv, rb_str_new2 (r[i]));
    free (r[i]);
  }
  free (r);
  return rv;
}

/*
 * call-seq:
 *   g.pvs_full() -> list
 *
 * list the LVM physical volumes (PVs)
 *
 * List all the physical volumes detected. This is the
 * equivalent of the pvs(8) command. The "full" version
 * includes all fields.
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_pvs_full+[http://libguestfs.org/guestfs.3.html#guestfs_pvs_full]).
 */
static VALUE
ruby_guestfs_pvs_full (VALUE gv)
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
  size_t i;
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

/*
 * call-seq:
 *   g.vgs_full() -> list
 *
 * list the LVM volume groups (VGs)
 *
 * List all the volumes groups detected. This is the
 * equivalent of the vgs(8) command. The "full" version
 * includes all fields.
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_vgs_full+[http://libguestfs.org/guestfs.3.html#guestfs_vgs_full]).
 */
static VALUE
ruby_guestfs_vgs_full (VALUE gv)
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
  size_t i;
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

/*
 * call-seq:
 *   g.lvs_full() -> list
 *
 * list the LVM logical volumes (LVs)
 *
 * List all the logical volumes detected. This is the
 * equivalent of the lvs(8) command. The "full" version
 * includes all fields.
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_lvs_full+[http://libguestfs.org/guestfs.3.html#guestfs_lvs_full]).
 */
static VALUE
ruby_guestfs_lvs_full (VALUE gv)
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
  size_t i;
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

/*
 * call-seq:
 *   g.read_lines(path) -> list
 *
 * read file as lines
 *
 * Return the contents of the file named "path".
 * 
 * The file contents are returned as a list of lines.
 * Trailing "LF" and "CRLF" character sequences are *not*
 * returned.
 * 
 * Note that this function cannot correctly handle binary
 * files (specifically, files containing "\0" character
 * which is treated as end of line). For those you need to
 * use the "g.read_file" function which has a more complex
 * interface.
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_read_lines+[http://libguestfs.org/guestfs.3.html#guestfs_read_lines]).
 */
static VALUE
ruby_guestfs_read_lines (VALUE gv, VALUE pathv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "read_lines");

  const char *path = StringValueCStr (pathv);

  char **r;

  r = guestfs_read_lines (g, path);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  size_t i, len = 0;
  for (i = 0; r[i] != NULL; ++i) len++;
  VALUE rv = rb_ary_new2 (len);
  for (i = 0; r[i] != NULL; ++i) {
    rb_ary_push (rv, rb_str_new2 (r[i]));
    free (r[i]);
  }
  free (r);
  return rv;
}

/*
 * call-seq:
 *   g.aug_init(root, flags) -> nil
 *
 * create a new Augeas handle
 *
 * Create a new Augeas handle for editing configuration
 * files. If there was any previous Augeas handle
 * associated with this guestfs session, then it is closed.
 * 
 * You must call this before using any other "g.aug_*"
 * commands.
 * 
 * "root" is the filesystem root. "root" must not be NULL,
 * use "/" instead.
 * 
 * The flags are the same as the flags defined in
 * <augeas.h>, the logical *or* of the following integers:
 * 
 * "AUG_SAVE_BACKUP" = 1
 * Keep the original file with a ".augsave" extension.
 * 
 * "AUG_SAVE_NEWFILE" = 2
 * Save changes into a file with extension ".augnew",
 * and do not overwrite original. Overrides
 * "AUG_SAVE_BACKUP".
 * 
 * "AUG_TYPE_CHECK" = 4
 * Typecheck lenses.
 * 
 * This option is only useful when debugging Augeas
 * lenses. Use of this option may require additional
 * memory for the libguestfs appliance. You may need to
 * set the "LIBGUESTFS_MEMSIZE" environment variable or
 * call "g.set_memsize".
 * 
 * "AUG_NO_STDINC" = 8
 * Do not use standard load path for modules.
 * 
 * "AUG_SAVE_NOOP" = 16
 * Make save a no-op, just record what would have been
 * changed.
 * 
 * "AUG_NO_LOAD" = 32
 * Do not load the tree in "g.aug_init".
 * 
 * To close the handle, you can call "g.aug_close".
 * 
 * To find out more about Augeas, see <http://augeas.net/>.
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_aug_init+[http://libguestfs.org/guestfs.3.html#guestfs_aug_init]).
 */
static VALUE
ruby_guestfs_aug_init (VALUE gv, VALUE rootv, VALUE flagsv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "aug_init");

  const char *root = StringValueCStr (rootv);
  int flags = NUM2INT (flagsv);

  int r;

  r = guestfs_aug_init (g, root, flags);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.aug_close() -> nil
 *
 * close the current Augeas handle
 *
 * Close the current Augeas handle and free up any
 * resources used by it. After calling this, you have to
 * call "g.aug_init" again before you can use any other
 * Augeas functions.
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_aug_close+[http://libguestfs.org/guestfs.3.html#guestfs_aug_close]).
 */
static VALUE
ruby_guestfs_aug_close (VALUE gv)
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

/*
 * call-seq:
 *   g.aug_defvar(name, expr) -> fixnum
 *
 * define an Augeas variable
 *
 * Defines an Augeas variable "name" whose value is the
 * result of evaluating "expr". If "expr" is NULL, then
 * "name" is undefined.
 * 
 * On success this returns the number of nodes in "expr",
 * or 0 if "expr" evaluates to something which is not a
 * nodeset.
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_aug_defvar+[http://libguestfs.org/guestfs.3.html#guestfs_aug_defvar]).
 */
static VALUE
ruby_guestfs_aug_defvar (VALUE gv, VALUE namev, VALUE exprv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "aug_defvar");

  const char *name = StringValueCStr (namev);
  const char *expr = !NIL_P (exprv) ? StringValueCStr (exprv) : NULL;

  int r;

  r = guestfs_aug_defvar (g, name, expr);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return INT2NUM (r);
}

/*
 * call-seq:
 *   g.aug_defnode(name, expr, val) -> hash
 *
 * define an Augeas node
 *
 * Defines a variable "name" whose value is the result of
 * evaluating "expr".
 * 
 * If "expr" evaluates to an empty nodeset, a node is
 * created, equivalent to calling "g.aug_set" "expr",
 * "value". "name" will be the nodeset containing that
 * single node.
 * 
 * On success this returns a pair containing the number of
 * nodes in the nodeset, and a boolean flag if a node was
 * created.
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_aug_defnode+[http://libguestfs.org/guestfs.3.html#guestfs_aug_defnode]).
 */
static VALUE
ruby_guestfs_aug_defnode (VALUE gv, VALUE namev, VALUE exprv, VALUE valv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "aug_defnode");

  const char *name = StringValueCStr (namev);
  const char *expr = StringValueCStr (exprv);
  const char *val = StringValueCStr (valv);

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

/*
 * call-seq:
 *   g.aug_get(augpath) -> string
 *
 * look up the value of an Augeas path
 *
 * Look up the value associated with "path". If "path"
 * matches exactly one node, the "value" is returned.
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_aug_get+[http://libguestfs.org/guestfs.3.html#guestfs_aug_get]).
 */
static VALUE
ruby_guestfs_aug_get (VALUE gv, VALUE augpathv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "aug_get");

  const char *augpath = StringValueCStr (augpathv);

  char *r;

  r = guestfs_aug_get (g, augpath);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  VALUE rv = rb_str_new2 (r);
  free (r);
  return rv;
}

/*
 * call-seq:
 *   g.aug_set(augpath, val) -> nil
 *
 * set Augeas path to value
 *
 * Set the value associated with "path" to "val".
 * 
 * In the Augeas API, it is possible to clear a node by
 * setting the value to NULL. Due to an oversight in the
 * libguestfs API you cannot do that with this call.
 * Instead you must use the "g.aug_clear" call.
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_aug_set+[http://libguestfs.org/guestfs.3.html#guestfs_aug_set]).
 */
static VALUE
ruby_guestfs_aug_set (VALUE gv, VALUE augpathv, VALUE valv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "aug_set");

  const char *augpath = StringValueCStr (augpathv);
  const char *val = StringValueCStr (valv);

  int r;

  r = guestfs_aug_set (g, augpath, val);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.aug_insert(augpath, label, before) -> nil
 *
 * insert a sibling Augeas node
 *
 * Create a new sibling "label" for "path", inserting it
 * into the tree before or after "path" (depending on the
 * boolean flag "before").
 * 
 * "path" must match exactly one existing node in the tree,
 * and "label" must be a label, ie. not contain "/", "*" or
 * end with a bracketed index "[N]".
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_aug_insert+[http://libguestfs.org/guestfs.3.html#guestfs_aug_insert]).
 */
static VALUE
ruby_guestfs_aug_insert (VALUE gv, VALUE augpathv, VALUE labelv, VALUE beforev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "aug_insert");

  const char *augpath = StringValueCStr (augpathv);
  const char *label = StringValueCStr (labelv);
  int before = RTEST (beforev);

  int r;

  r = guestfs_aug_insert (g, augpath, label, before);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.aug_rm(augpath) -> fixnum
 *
 * remove an Augeas path
 *
 * Remove "path" and all of its children.
 * 
 * On success this returns the number of entries which were
 * removed.
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_aug_rm+[http://libguestfs.org/guestfs.3.html#guestfs_aug_rm]).
 */
static VALUE
ruby_guestfs_aug_rm (VALUE gv, VALUE augpathv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "aug_rm");

  const char *augpath = StringValueCStr (augpathv);

  int r;

  r = guestfs_aug_rm (g, augpath);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return INT2NUM (r);
}

/*
 * call-seq:
 *   g.aug_mv(src, dest) -> nil
 *
 * move Augeas node
 *
 * Move the node "src" to "dest". "src" must match exactly
 * one node. "dest" is overwritten if it exists.
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_aug_mv+[http://libguestfs.org/guestfs.3.html#guestfs_aug_mv]).
 */
static VALUE
ruby_guestfs_aug_mv (VALUE gv, VALUE srcv, VALUE destv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "aug_mv");

  const char *src = StringValueCStr (srcv);
  const char *dest = StringValueCStr (destv);

  int r;

  r = guestfs_aug_mv (g, src, dest);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.aug_match(augpath) -> list
 *
 * return Augeas nodes which match augpath
 *
 * Returns a list of paths which match the path expression
 * "path". The returned paths are sufficiently qualified so
 * that they match exactly one node in the current tree.
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_aug_match+[http://libguestfs.org/guestfs.3.html#guestfs_aug_match]).
 */
static VALUE
ruby_guestfs_aug_match (VALUE gv, VALUE augpathv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "aug_match");

  const char *augpath = StringValueCStr (augpathv);

  char **r;

  r = guestfs_aug_match (g, augpath);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  size_t i, len = 0;
  for (i = 0; r[i] != NULL; ++i) len++;
  VALUE rv = rb_ary_new2 (len);
  for (i = 0; r[i] != NULL; ++i) {
    rb_ary_push (rv, rb_str_new2 (r[i]));
    free (r[i]);
  }
  free (r);
  return rv;
}

/*
 * call-seq:
 *   g.aug_save() -> nil
 *
 * write all pending Augeas changes to disk
 *
 * This writes all pending changes to disk.
 * 
 * The flags which were passed to "g.aug_init" affect
 * exactly how files are saved.
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_aug_save+[http://libguestfs.org/guestfs.3.html#guestfs_aug_save]).
 */
static VALUE
ruby_guestfs_aug_save (VALUE gv)
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

/*
 * call-seq:
 *   g.aug_load() -> nil
 *
 * load files into the tree
 *
 * Load files into the tree.
 * 
 * See "aug_load" in the Augeas documentation for the full
 * gory details.
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_aug_load+[http://libguestfs.org/guestfs.3.html#guestfs_aug_load]).
 */
static VALUE
ruby_guestfs_aug_load (VALUE gv)
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

/*
 * call-seq:
 *   g.aug_ls(augpath) -> list
 *
 * list Augeas nodes under augpath
 *
 * This is just a shortcut for listing "g.aug_match"
 * "path/*" and sorting the resulting nodes into
 * alphabetical order.
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_aug_ls+[http://libguestfs.org/guestfs.3.html#guestfs_aug_ls]).
 */
static VALUE
ruby_guestfs_aug_ls (VALUE gv, VALUE augpathv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "aug_ls");

  const char *augpath = StringValueCStr (augpathv);

  char **r;

  r = guestfs_aug_ls (g, augpath);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  size_t i, len = 0;
  for (i = 0; r[i] != NULL; ++i) len++;
  VALUE rv = rb_ary_new2 (len);
  for (i = 0; r[i] != NULL; ++i) {
    rb_ary_push (rv, rb_str_new2 (r[i]));
    free (r[i]);
  }
  free (r);
  return rv;
}

/*
 * call-seq:
 *   g.rm(path) -> nil
 *
 * remove a file
 *
 * Remove the single file "path".
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_rm+[http://libguestfs.org/guestfs.3.html#guestfs_rm]).
 */
static VALUE
ruby_guestfs_rm (VALUE gv, VALUE pathv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "rm");

  const char *path = StringValueCStr (pathv);

  int r;

  r = guestfs_rm (g, path);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.rmdir(path) -> nil
 *
 * remove a directory
 *
 * Remove the single directory "path".
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_rmdir+[http://libguestfs.org/guestfs.3.html#guestfs_rmdir]).
 */
static VALUE
ruby_guestfs_rmdir (VALUE gv, VALUE pathv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "rmdir");

  const char *path = StringValueCStr (pathv);

  int r;

  r = guestfs_rmdir (g, path);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.rm_rf(path) -> nil
 *
 * remove a file or directory recursively
 *
 * Remove the file or directory "path", recursively
 * removing the contents if its a directory. This is like
 * the "rm -rf" shell command.
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_rm_rf+[http://libguestfs.org/guestfs.3.html#guestfs_rm_rf]).
 */
static VALUE
ruby_guestfs_rm_rf (VALUE gv, VALUE pathv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "rm_rf");

  const char *path = StringValueCStr (pathv);

  int r;

  r = guestfs_rm_rf (g, path);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.mkdir(path) -> nil
 *
 * create a directory
 *
 * Create a directory named "path".
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_mkdir+[http://libguestfs.org/guestfs.3.html#guestfs_mkdir]).
 */
static VALUE
ruby_guestfs_mkdir (VALUE gv, VALUE pathv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "mkdir");

  const char *path = StringValueCStr (pathv);

  int r;

  r = guestfs_mkdir (g, path);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.mkdir_p(path) -> nil
 *
 * create a directory and parents
 *
 * Create a directory named "path", creating any parent
 * directories as necessary. This is like the "mkdir -p"
 * shell command.
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_mkdir_p+[http://libguestfs.org/guestfs.3.html#guestfs_mkdir_p]).
 */
static VALUE
ruby_guestfs_mkdir_p (VALUE gv, VALUE pathv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "mkdir_p");

  const char *path = StringValueCStr (pathv);

  int r;

  r = guestfs_mkdir_p (g, path);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.chmod(mode, path) -> nil
 *
 * change file mode
 *
 * Change the mode (permissions) of "path" to "mode". Only
 * numeric modes are supported.
 * 
 * *Note*: When using this command from guestfish, "mode"
 * by default would be decimal, unless you prefix it with 0
 * to get octal, ie. use 0700 not 700.
 * 
 * The mode actually set is affected by the umask.
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_chmod+[http://libguestfs.org/guestfs.3.html#guestfs_chmod]).
 */
static VALUE
ruby_guestfs_chmod (VALUE gv, VALUE modev, VALUE pathv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "chmod");

  int mode = NUM2INT (modev);
  const char *path = StringValueCStr (pathv);

  int r;

  r = guestfs_chmod (g, mode, path);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.chown(owner, group, path) -> nil
 *
 * change file owner and group
 *
 * Change the file owner to "owner" and group to "group".
 * 
 * Only numeric uid and gid are supported. If you want to
 * use names, you will need to locate and parse the
 * password file yourself (Augeas support makes this
 * relatively easy).
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_chown+[http://libguestfs.org/guestfs.3.html#guestfs_chown]).
 */
static VALUE
ruby_guestfs_chown (VALUE gv, VALUE ownerv, VALUE groupv, VALUE pathv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "chown");

  int owner = NUM2INT (ownerv);
  int group = NUM2INT (groupv);
  const char *path = StringValueCStr (pathv);

  int r;

  r = guestfs_chown (g, owner, group, path);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.exists(path) -> [True|False]
 *
 * test if file or directory exists
 *
 * This returns "true" if and only if there is a file,
 * directory (or anything) with the given "path" name.
 * 
 * See also "g.is_file", "g.is_dir", "g.stat".
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_exists+[http://libguestfs.org/guestfs.3.html#guestfs_exists]).
 */
static VALUE
ruby_guestfs_exists (VALUE gv, VALUE pathv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "exists");

  const char *path = StringValueCStr (pathv);

  int r;

  r = guestfs_exists (g, path);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return INT2NUM (r);
}

/*
 * call-seq:
 *   g.is_file(path) -> [True|False]
 *
 * test if a regular file
 *
 * This returns "true" if and only if there is a regular
 * file with the given "path" name. Note that it returns
 * false for other objects like directories.
 * 
 * See also "g.stat".
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_is_file+[http://libguestfs.org/guestfs.3.html#guestfs_is_file]).
 */
static VALUE
ruby_guestfs_is_file (VALUE gv, VALUE pathv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "is_file");

  const char *path = StringValueCStr (pathv);

  int r;

  r = guestfs_is_file (g, path);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return INT2NUM (r);
}

/*
 * call-seq:
 *   g.is_dir(path) -> [True|False]
 *
 * test if a directory
 *
 * This returns "true" if and only if there is a directory
 * with the given "path" name. Note that it returns false
 * for other objects like files.
 * 
 * See also "g.stat".
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_is_dir+[http://libguestfs.org/guestfs.3.html#guestfs_is_dir]).
 */
static VALUE
ruby_guestfs_is_dir (VALUE gv, VALUE pathv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "is_dir");

  const char *path = StringValueCStr (pathv);

  int r;

  r = guestfs_is_dir (g, path);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return INT2NUM (r);
}

/*
 * call-seq:
 *   g.pvcreate(device) -> nil
 *
 * create an LVM physical volume
 *
 * This creates an LVM physical volume on the named
 * "device", where "device" should usually be a partition
 * name such as "/dev/sda1".
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_pvcreate+[http://libguestfs.org/guestfs.3.html#guestfs_pvcreate]).
 */
static VALUE
ruby_guestfs_pvcreate (VALUE gv, VALUE devicev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "pvcreate");

  const char *device = StringValueCStr (devicev);

  int r;

  r = guestfs_pvcreate (g, device);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.vgcreate(volgroup, physvols) -> nil
 *
 * create an LVM volume group
 *
 * This creates an LVM volume group called "volgroup" from
 * the non-empty list of physical volumes "physvols".
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_vgcreate+[http://libguestfs.org/guestfs.3.html#guestfs_vgcreate]).
 */
static VALUE
ruby_guestfs_vgcreate (VALUE gv, VALUE volgroupv, VALUE physvolsv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "vgcreate");

  const char *volgroup = StringValueCStr (volgroupv);
  char **physvols;
  Check_Type (physvolsv, T_ARRAY);
  {
    size_t i, len;
    len = RARRAY_LEN (physvolsv);
    physvols = ALLOC_N (char *, len+1);
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

/*
 * call-seq:
 *   g.lvcreate(logvol, volgroup, mbytes) -> nil
 *
 * create an LVM logical volume
 *
 * This creates an LVM logical volume called "logvol" on
 * the volume group "volgroup", with "size" megabytes.
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_lvcreate+[http://libguestfs.org/guestfs.3.html#guestfs_lvcreate]).
 */
static VALUE
ruby_guestfs_lvcreate (VALUE gv, VALUE logvolv, VALUE volgroupv, VALUE mbytesv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "lvcreate");

  const char *logvol = StringValueCStr (logvolv);
  const char *volgroup = StringValueCStr (volgroupv);
  int mbytes = NUM2INT (mbytesv);

  int r;

  r = guestfs_lvcreate (g, logvol, volgroup, mbytes);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.mkfs(fstype, device) -> nil
 *
 * make a filesystem
 *
 * This creates a filesystem on "device" (usually a
 * partition or LVM logical volume). The filesystem type is
 * "fstype", for example "ext3".
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_mkfs+[http://libguestfs.org/guestfs.3.html#guestfs_mkfs]).
 */
static VALUE
ruby_guestfs_mkfs (VALUE gv, VALUE fstypev, VALUE devicev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "mkfs");

  const char *fstype = StringValueCStr (fstypev);
  const char *device = StringValueCStr (devicev);

  int r;

  r = guestfs_mkfs (g, fstype, device);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.sfdisk(device, cyls, heads, sectors, lines) -> nil
 *
 * create partitions on a block device
 *
 * This is a direct interface to the sfdisk(8) program for
 * creating partitions on block devices.
 * 
 * "device" should be a block device, for example
 * "/dev/sda".
 * 
 * "cyls", "heads" and "sectors" are the number of
 * cylinders, heads and sectors on the device, which are
 * passed directly to sfdisk as the *-C*, *-H* and *-S*
 * parameters. If you pass 0 for any of these, then the
 * corresponding parameter is omitted. Usually for 'large'
 * disks, you can just pass 0 for these, but for small
 * (floppy-sized) disks, sfdisk (or rather, the kernel)
 * cannot work out the right geometry and you will need to
 * tell it.
 * 
 * "lines" is a list of lines that we feed to "sfdisk". For
 * more information refer to the sfdisk(8) manpage.
 * 
 * To create a single partition occupying the whole disk,
 * you would pass "lines" as a single element list, when
 * the single element being the string "," (comma).
 * 
 * See also: "g.sfdisk_l", "g.sfdisk_N", "g.part_init"
 * 
 * *This function is deprecated.* In new code, use the
 * "part_add" call instead.
 * 
 * Deprecated functions will not be removed from the API,
 * but the fact that they are deprecated indicates that
 * there are problems with correct use of these functions.
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_sfdisk+[http://libguestfs.org/guestfs.3.html#guestfs_sfdisk]).
 */
static VALUE
ruby_guestfs_sfdisk (VALUE gv, VALUE devicev, VALUE cylsv, VALUE headsv, VALUE sectorsv, VALUE linesv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "sfdisk");

  const char *device = StringValueCStr (devicev);
  int cyls = NUM2INT (cylsv);
  int heads = NUM2INT (headsv);
  int sectors = NUM2INT (sectorsv);
  char **lines;
  Check_Type (linesv, T_ARRAY);
  {
    size_t i, len;
    len = RARRAY_LEN (linesv);
    lines = ALLOC_N (char *, len+1);
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

/*
 * call-seq:
 *   g.write_file(path, content, size) -> nil
 *
 * create a file
 *
 * This call creates a file called "path". The contents of
 * the file is the string "content" (which can contain any
 * 8 bit data), with length "size".
 * 
 * As a special case, if "size" is 0 then the length is
 * calculated using "strlen" (so in this case the content
 * cannot contain embedded ASCII NULs).
 * 
 * *NB.* Owing to a bug, writing content containing ASCII
 * NUL characters does *not* work, even if the length is
 * specified.
 * 
 * Because of the message protocol, there is a transfer
 * limit of somewhere between 2MB and 4MB. See "PROTOCOL
 * LIMITS" in guestfs(3).
 * 
 * *This function is deprecated.* In new code, use the
 * "write" call instead.
 * 
 * Deprecated functions will not be removed from the API,
 * but the fact that they are deprecated indicates that
 * there are problems with correct use of these functions.
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_write_file+[http://libguestfs.org/guestfs.3.html#guestfs_write_file]).
 */
static VALUE
ruby_guestfs_write_file (VALUE gv, VALUE pathv, VALUE contentv, VALUE sizev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "write_file");

  const char *path = StringValueCStr (pathv);
  const char *content = StringValueCStr (contentv);
  int size = NUM2INT (sizev);

  int r;

  r = guestfs_write_file (g, path, content, size);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.umount(pathordevice) -> nil
 *
 * unmount a filesystem
 *
 * This unmounts the given filesystem. The filesystem may
 * be specified either by its mountpoint (path) or the
 * device which contains the filesystem.
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_umount+[http://libguestfs.org/guestfs.3.html#guestfs_umount]).
 */
static VALUE
ruby_guestfs_umount (VALUE gv, VALUE pathordevicev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "umount");

  const char *pathordevice = StringValueCStr (pathordevicev);

  int r;

  r = guestfs_umount (g, pathordevice);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.mounts() -> list
 *
 * show mounted filesystems
 *
 * This returns the list of currently mounted filesystems.
 * It returns the list of devices (eg. "/dev/sda1",
 * "/dev/VG/LV").
 * 
 * Some internal mounts are not shown.
 * 
 * See also: "g.mountpoints"
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_mounts+[http://libguestfs.org/guestfs.3.html#guestfs_mounts]).
 */
static VALUE
ruby_guestfs_mounts (VALUE gv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "mounts");


  char **r;

  r = guestfs_mounts (g);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  size_t i, len = 0;
  for (i = 0; r[i] != NULL; ++i) len++;
  VALUE rv = rb_ary_new2 (len);
  for (i = 0; r[i] != NULL; ++i) {
    rb_ary_push (rv, rb_str_new2 (r[i]));
    free (r[i]);
  }
  free (r);
  return rv;
}

/*
 * call-seq:
 *   g.umount_all() -> nil
 *
 * unmount all filesystems
 *
 * This unmounts all mounted filesystems.
 * 
 * Some internal mounts are not unmounted by this call.
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_umount_all+[http://libguestfs.org/guestfs.3.html#guestfs_umount_all]).
 */
static VALUE
ruby_guestfs_umount_all (VALUE gv)
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

/*
 * call-seq:
 *   g.lvm_remove_all() -> nil
 *
 * remove all LVM LVs, VGs and PVs
 *
 * This command removes all LVM logical volumes, volume
 * groups and physical volumes.
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_lvm_remove_all+[http://libguestfs.org/guestfs.3.html#guestfs_lvm_remove_all]).
 */
static VALUE
ruby_guestfs_lvm_remove_all (VALUE gv)
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

/*
 * call-seq:
 *   g.file(path) -> string
 *
 * determine file type
 *
 * This call uses the standard file(1) command to determine
 * the type or contents of the file.
 * 
 * This call will also transparently look inside various
 * types of compressed file.
 * 
 * The exact command which runs is "file -zb path". Note in
 * particular that the filename is not prepended to the
 * output (the *-b* option).
 * 
 * The output depends on the output of the underlying
 * file(1) command and it can change in future in ways
 * beyond our control. In other words, the output is not
 * guaranteed by the ABI.
 * 
 * See also: file(1), "g.vfs_type", "g.lstat", "g.is_file",
 * "g.is_blockdev" (etc), "g.is_zero".
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_file+[http://libguestfs.org/guestfs.3.html#guestfs_file]).
 */
static VALUE
ruby_guestfs_file (VALUE gv, VALUE pathv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "file");

  const char *path = StringValueCStr (pathv);

  char *r;

  r = guestfs_file (g, path);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  VALUE rv = rb_str_new2 (r);
  free (r);
  return rv;
}

/*
 * call-seq:
 *   g.command(arguments) -> string
 *
 * run a command from the guest filesystem
 *
 * This call runs a command from the guest filesystem. The
 * filesystem must be mounted, and must contain a
 * compatible operating system (ie. something Linux, with
 * the same or compatible processor architecture).
 * 
 * The single parameter is an argv-style list of arguments.
 * The first element is the name of the program to run.
 * Subsequent elements are parameters. The list must be
 * non-empty (ie. must contain a program name). Note that
 * the command runs directly, and is *not* invoked via the
 * shell (see "g.sh").
 * 
 * The return value is anything printed to *stdout* by the
 * command.
 * 
 * If the command returns a non-zero exit status, then this
 * function returns an error message. The error message
 * string is the content of *stderr* from the command.
 * 
 * The $PATH environment variable will contain at least
 * "/usr/bin" and "/bin". If you require a program from
 * another location, you should provide the full path in
 * the first parameter.
 * 
 * Shared libraries and data files required by the program
 * must be available on filesystems which are mounted in
 * the correct places. It is the caller's responsibility to
 * ensure all filesystems that are needed are mounted at
 * the right locations.
 * 
 * Because of the message protocol, there is a transfer
 * limit of somewhere between 2MB and 4MB. See "PROTOCOL
 * LIMITS" in guestfs(3).
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_command+[http://libguestfs.org/guestfs.3.html#guestfs_command]).
 */
static VALUE
ruby_guestfs_command (VALUE gv, VALUE argumentsv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "command");

  char **arguments;
  Check_Type (argumentsv, T_ARRAY);
  {
    size_t i, len;
    len = RARRAY_LEN (argumentsv);
    arguments = ALLOC_N (char *, len+1);
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

/*
 * call-seq:
 *   g.command_lines(arguments) -> list
 *
 * run a command, returning lines
 *
 * This is the same as "g.command", but splits the result
 * into a list of lines.
 * 
 * See also: "g.sh_lines"
 * 
 * Because of the message protocol, there is a transfer
 * limit of somewhere between 2MB and 4MB. See "PROTOCOL
 * LIMITS" in guestfs(3).
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_command_lines+[http://libguestfs.org/guestfs.3.html#guestfs_command_lines]).
 */
static VALUE
ruby_guestfs_command_lines (VALUE gv, VALUE argumentsv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "command_lines");

  char **arguments;
  Check_Type (argumentsv, T_ARRAY);
  {
    size_t i, len;
    len = RARRAY_LEN (argumentsv);
    arguments = ALLOC_N (char *, len+1);
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

  size_t i, len = 0;
  for (i = 0; r[i] != NULL; ++i) len++;
  VALUE rv = rb_ary_new2 (len);
  for (i = 0; r[i] != NULL; ++i) {
    rb_ary_push (rv, rb_str_new2 (r[i]));
    free (r[i]);
  }
  free (r);
  return rv;
}

/*
 * call-seq:
 *   g.stat(path) -> hash
 *
 * get file information
 *
 * Returns file information for the given "path".
 * 
 * This is the same as the stat(2) system call.
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_stat+[http://libguestfs.org/guestfs.3.html#guestfs_stat]).
 */
static VALUE
ruby_guestfs_stat (VALUE gv, VALUE pathv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "stat");

  const char *path = StringValueCStr (pathv);

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

/*
 * call-seq:
 *   g.lstat(path) -> hash
 *
 * get file information for a symbolic link
 *
 * Returns file information for the given "path".
 * 
 * This is the same as "g.stat" except that if "path" is a
 * symbolic link, then the link is stat-ed, not the file it
 * refers to.
 * 
 * This is the same as the lstat(2) system call.
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_lstat+[http://libguestfs.org/guestfs.3.html#guestfs_lstat]).
 */
static VALUE
ruby_guestfs_lstat (VALUE gv, VALUE pathv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "lstat");

  const char *path = StringValueCStr (pathv);

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

/*
 * call-seq:
 *   g.statvfs(path) -> hash
 *
 * get file system statistics
 *
 * Returns file system statistics for any mounted file
 * system. "path" should be a file or directory in the
 * mounted file system (typically it is the mount point
 * itself, but it doesn't need to be).
 * 
 * This is the same as the statvfs(2) system call.
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_statvfs+[http://libguestfs.org/guestfs.3.html#guestfs_statvfs]).
 */
static VALUE
ruby_guestfs_statvfs (VALUE gv, VALUE pathv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "statvfs");

  const char *path = StringValueCStr (pathv);

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

/*
 * call-seq:
 *   g.tune2fs_l(device) -> hash
 *
 * get ext2/ext3/ext4 superblock details
 *
 * This returns the contents of the ext2, ext3 or ext4
 * filesystem superblock on "device".
 * 
 * It is the same as running "tune2fs -l device". See
 * tune2fs(8) manpage for more details. The list of fields
 * returned isn't clearly defined, and depends on both the
 * version of "tune2fs" that libguestfs was built against,
 * and the filesystem itself.
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_tune2fs_l+[http://libguestfs.org/guestfs.3.html#guestfs_tune2fs_l]).
 */
static VALUE
ruby_guestfs_tune2fs_l (VALUE gv, VALUE devicev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "tune2fs_l");

  const char *device = StringValueCStr (devicev);

  char **r;

  r = guestfs_tune2fs_l (g, device);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  VALUE rv = rb_hash_new ();
  size_t i;
  for (i = 0; r[i] != NULL; i+=2) {
    rb_hash_aset (rv, rb_str_new2 (r[i]), rb_str_new2 (r[i+1]));
    free (r[i]);
    free (r[i+1]);
  }
  free (r);
  return rv;
}

/*
 * call-seq:
 *   g.blockdev_setro(device) -> nil
 *
 * set block device to read-only
 *
 * Sets the block device named "device" to read-only.
 * 
 * This uses the blockdev(8) command.
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_blockdev_setro+[http://libguestfs.org/guestfs.3.html#guestfs_blockdev_setro]).
 */
static VALUE
ruby_guestfs_blockdev_setro (VALUE gv, VALUE devicev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "blockdev_setro");

  const char *device = StringValueCStr (devicev);

  int r;

  r = guestfs_blockdev_setro (g, device);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.blockdev_setrw(device) -> nil
 *
 * set block device to read-write
 *
 * Sets the block device named "device" to read-write.
 * 
 * This uses the blockdev(8) command.
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_blockdev_setrw+[http://libguestfs.org/guestfs.3.html#guestfs_blockdev_setrw]).
 */
static VALUE
ruby_guestfs_blockdev_setrw (VALUE gv, VALUE devicev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "blockdev_setrw");

  const char *device = StringValueCStr (devicev);

  int r;

  r = guestfs_blockdev_setrw (g, device);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.blockdev_getro(device) -> [True|False]
 *
 * is block device set to read-only
 *
 * Returns a boolean indicating if the block device is
 * read-only (true if read-only, false if not).
 * 
 * This uses the blockdev(8) command.
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_blockdev_getro+[http://libguestfs.org/guestfs.3.html#guestfs_blockdev_getro]).
 */
static VALUE
ruby_guestfs_blockdev_getro (VALUE gv, VALUE devicev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "blockdev_getro");

  const char *device = StringValueCStr (devicev);

  int r;

  r = guestfs_blockdev_getro (g, device);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return INT2NUM (r);
}

/*
 * call-seq:
 *   g.blockdev_getss(device) -> fixnum
 *
 * get sectorsize of block device
 *
 * This returns the size of sectors on a block device.
 * Usually 512, but can be larger for modern devices.
 * 
 * (Note, this is not the size in sectors, use
 * "g.blockdev_getsz" for that).
 * 
 * This uses the blockdev(8) command.
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_blockdev_getss+[http://libguestfs.org/guestfs.3.html#guestfs_blockdev_getss]).
 */
static VALUE
ruby_guestfs_blockdev_getss (VALUE gv, VALUE devicev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "blockdev_getss");

  const char *device = StringValueCStr (devicev);

  int r;

  r = guestfs_blockdev_getss (g, device);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return INT2NUM (r);
}

/*
 * call-seq:
 *   g.blockdev_getbsz(device) -> fixnum
 *
 * get blocksize of block device
 *
 * This returns the block size of a device.
 * 
 * (Note this is different from both *size in blocks* and
 * *filesystem block size*).
 * 
 * This uses the blockdev(8) command.
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_blockdev_getbsz+[http://libguestfs.org/guestfs.3.html#guestfs_blockdev_getbsz]).
 */
static VALUE
ruby_guestfs_blockdev_getbsz (VALUE gv, VALUE devicev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "blockdev_getbsz");

  const char *device = StringValueCStr (devicev);

  int r;

  r = guestfs_blockdev_getbsz (g, device);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return INT2NUM (r);
}

/*
 * call-seq:
 *   g.blockdev_setbsz(device, blocksize) -> nil
 *
 * set blocksize of block device
 *
 * This sets the block size of a device.
 * 
 * (Note this is different from both *size in blocks* and
 * *filesystem block size*).
 * 
 * This uses the blockdev(8) command.
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_blockdev_setbsz+[http://libguestfs.org/guestfs.3.html#guestfs_blockdev_setbsz]).
 */
static VALUE
ruby_guestfs_blockdev_setbsz (VALUE gv, VALUE devicev, VALUE blocksizev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "blockdev_setbsz");

  const char *device = StringValueCStr (devicev);
  int blocksize = NUM2INT (blocksizev);

  int r;

  r = guestfs_blockdev_setbsz (g, device, blocksize);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.blockdev_getsz(device) -> fixnum
 *
 * get total size of device in 512-byte sectors
 *
 * This returns the size of the device in units of 512-byte
 * sectors (even if the sectorsize isn't 512 bytes ...
 * weird).
 * 
 * See also "g.blockdev_getss" for the real sector size of
 * the device, and "g.blockdev_getsize64" for the more
 * useful *size in bytes*.
 * 
 * This uses the blockdev(8) command.
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_blockdev_getsz+[http://libguestfs.org/guestfs.3.html#guestfs_blockdev_getsz]).
 */
static VALUE
ruby_guestfs_blockdev_getsz (VALUE gv, VALUE devicev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "blockdev_getsz");

  const char *device = StringValueCStr (devicev);

  int64_t r;

  r = guestfs_blockdev_getsz (g, device);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return ULL2NUM (r);
}

/*
 * call-seq:
 *   g.blockdev_getsize64(device) -> fixnum
 *
 * get total size of device in bytes
 *
 * This returns the size of the device in bytes.
 * 
 * See also "g.blockdev_getsz".
 * 
 * This uses the blockdev(8) command.
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_blockdev_getsize64+[http://libguestfs.org/guestfs.3.html#guestfs_blockdev_getsize64]).
 */
static VALUE
ruby_guestfs_blockdev_getsize64 (VALUE gv, VALUE devicev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "blockdev_getsize64");

  const char *device = StringValueCStr (devicev);

  int64_t r;

  r = guestfs_blockdev_getsize64 (g, device);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return ULL2NUM (r);
}

/*
 * call-seq:
 *   g.blockdev_flushbufs(device) -> nil
 *
 * flush device buffers
 *
 * This tells the kernel to flush internal buffers
 * associated with "device".
 * 
 * This uses the blockdev(8) command.
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_blockdev_flushbufs+[http://libguestfs.org/guestfs.3.html#guestfs_blockdev_flushbufs]).
 */
static VALUE
ruby_guestfs_blockdev_flushbufs (VALUE gv, VALUE devicev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "blockdev_flushbufs");

  const char *device = StringValueCStr (devicev);

  int r;

  r = guestfs_blockdev_flushbufs (g, device);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.blockdev_rereadpt(device) -> nil
 *
 * reread partition table
 *
 * Reread the partition table on "device".
 * 
 * This uses the blockdev(8) command.
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_blockdev_rereadpt+[http://libguestfs.org/guestfs.3.html#guestfs_blockdev_rereadpt]).
 */
static VALUE
ruby_guestfs_blockdev_rereadpt (VALUE gv, VALUE devicev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "blockdev_rereadpt");

  const char *device = StringValueCStr (devicev);

  int r;

  r = guestfs_blockdev_rereadpt (g, device);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.upload(filename, remotefilename) -> nil
 *
 * upload a file from the local machine
 *
 * Upload local file "filename" to "remotefilename" on the
 * filesystem.
 * 
 * "filename" can also be a named pipe.
 * 
 * See also "g.download".
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_upload+[http://libguestfs.org/guestfs.3.html#guestfs_upload]).
 */
static VALUE
ruby_guestfs_upload (VALUE gv, VALUE filenamev, VALUE remotefilenamev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "upload");

  const char *filename = StringValueCStr (filenamev);
  const char *remotefilename = StringValueCStr (remotefilenamev);

  int r;

  r = guestfs_upload (g, filename, remotefilename);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.download(remotefilename, filename) -> nil
 *
 * download a file to the local machine
 *
 * Download file "remotefilename" and save it as "filename"
 * on the local machine.
 * 
 * "filename" can also be a named pipe.
 * 
 * See also "g.upload", "g.cat".
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_download+[http://libguestfs.org/guestfs.3.html#guestfs_download]).
 */
static VALUE
ruby_guestfs_download (VALUE gv, VALUE remotefilenamev, VALUE filenamev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "download");

  const char *remotefilename = StringValueCStr (remotefilenamev);
  const char *filename = StringValueCStr (filenamev);

  int r;

  r = guestfs_download (g, remotefilename, filename);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.checksum(csumtype, path) -> string
 *
 * compute MD5, SHAx or CRC checksum of file
 *
 * This call computes the MD5, SHAx or CRC checksum of the
 * file named "path".
 * 
 * The type of checksum to compute is given by the
 * "csumtype" parameter which must have one of the
 * following values:
 * 
 * "crc"
 * Compute the cyclic redundancy check (CRC) specified
 * by POSIX for the "cksum" command.
 * 
 * "md5"
 * Compute the MD5 hash (using the "md5sum" program).
 * 
 * "sha1"
 * Compute the SHA1 hash (using the "sha1sum" program).
 * 
 * "sha224"
 * Compute the SHA224 hash (using the "sha224sum"
 * program).
 * 
 * "sha256"
 * Compute the SHA256 hash (using the "sha256sum"
 * program).
 * 
 * "sha384"
 * Compute the SHA384 hash (using the "sha384sum"
 * program).
 * 
 * "sha512"
 * Compute the SHA512 hash (using the "sha512sum"
 * program).
 * 
 * The checksum is returned as a printable string.
 * 
 * To get the checksum for a device, use
 * "g.checksum_device".
 * 
 * To get the checksums for many files, use
 * "g.checksums_out".
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_checksum+[http://libguestfs.org/guestfs.3.html#guestfs_checksum]).
 */
static VALUE
ruby_guestfs_checksum (VALUE gv, VALUE csumtypev, VALUE pathv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "checksum");

  const char *csumtype = StringValueCStr (csumtypev);
  const char *path = StringValueCStr (pathv);

  char *r;

  r = guestfs_checksum (g, csumtype, path);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  VALUE rv = rb_str_new2 (r);
  free (r);
  return rv;
}

/*
 * call-seq:
 *   g.tar_in(tarfile, directory) -> nil
 *
 * unpack tarfile to directory
 *
 * This command uploads and unpacks local file "tarfile"
 * (an *uncompressed* tar file) into "directory".
 * 
 * To upload a compressed tarball, use "g.tgz_in" or
 * "g.txz_in".
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_tar_in+[http://libguestfs.org/guestfs.3.html#guestfs_tar_in]).
 */
static VALUE
ruby_guestfs_tar_in (VALUE gv, VALUE tarfilev, VALUE directoryv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "tar_in");

  const char *tarfile = StringValueCStr (tarfilev);
  const char *directory = StringValueCStr (directoryv);

  int r;

  r = guestfs_tar_in (g, tarfile, directory);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.tar_out(directory, tarfile) -> nil
 *
 * pack directory into tarfile
 *
 * This command packs the contents of "directory" and
 * downloads it to local file "tarfile".
 * 
 * To download a compressed tarball, use "g.tgz_out" or
 * "g.txz_out".
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_tar_out+[http://libguestfs.org/guestfs.3.html#guestfs_tar_out]).
 */
static VALUE
ruby_guestfs_tar_out (VALUE gv, VALUE directoryv, VALUE tarfilev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "tar_out");

  const char *directory = StringValueCStr (directoryv);
  const char *tarfile = StringValueCStr (tarfilev);

  int r;

  r = guestfs_tar_out (g, directory, tarfile);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.tgz_in(tarball, directory) -> nil
 *
 * unpack compressed tarball to directory
 *
 * This command uploads and unpacks local file "tarball" (a
 * *gzip compressed* tar file) into "directory".
 * 
 * To upload an uncompressed tarball, use "g.tar_in".
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_tgz_in+[http://libguestfs.org/guestfs.3.html#guestfs_tgz_in]).
 */
static VALUE
ruby_guestfs_tgz_in (VALUE gv, VALUE tarballv, VALUE directoryv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "tgz_in");

  const char *tarball = StringValueCStr (tarballv);
  const char *directory = StringValueCStr (directoryv);

  int r;

  r = guestfs_tgz_in (g, tarball, directory);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.tgz_out(directory, tarball) -> nil
 *
 * pack directory into compressed tarball
 *
 * This command packs the contents of "directory" and
 * downloads it to local file "tarball".
 * 
 * To download an uncompressed tarball, use "g.tar_out".
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_tgz_out+[http://libguestfs.org/guestfs.3.html#guestfs_tgz_out]).
 */
static VALUE
ruby_guestfs_tgz_out (VALUE gv, VALUE directoryv, VALUE tarballv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "tgz_out");

  const char *directory = StringValueCStr (directoryv);
  const char *tarball = StringValueCStr (tarballv);

  int r;

  r = guestfs_tgz_out (g, directory, tarball);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.mount_ro(device, mountpoint) -> nil
 *
 * mount a guest disk, read-only
 *
 * This is the same as the "g.mount" command, but it mounts
 * the filesystem with the read-only (*-o ro*) flag.
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_mount_ro+[http://libguestfs.org/guestfs.3.html#guestfs_mount_ro]).
 */
static VALUE
ruby_guestfs_mount_ro (VALUE gv, VALUE devicev, VALUE mountpointv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "mount_ro");

  const char *device = StringValueCStr (devicev);
  const char *mountpoint = StringValueCStr (mountpointv);

  int r;

  r = guestfs_mount_ro (g, device, mountpoint);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.mount_options(options, device, mountpoint) -> nil
 *
 * mount a guest disk with mount options
 *
 * This is the same as the "g.mount" command, but it allows
 * you to set the mount options as for the mount(8) *-o*
 * flag.
 * 
 * If the "options" parameter is an empty string, then no
 * options are passed (all options default to whatever the
 * filesystem uses).
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_mount_options+[http://libguestfs.org/guestfs.3.html#guestfs_mount_options]).
 */
static VALUE
ruby_guestfs_mount_options (VALUE gv, VALUE optionsv, VALUE devicev, VALUE mountpointv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "mount_options");

  const char *options = StringValueCStr (optionsv);
  const char *device = StringValueCStr (devicev);
  const char *mountpoint = StringValueCStr (mountpointv);

  int r;

  r = guestfs_mount_options (g, options, device, mountpoint);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.mount_vfs(options, vfstype, device, mountpoint) -> nil
 *
 * mount a guest disk with mount options and vfstype
 *
 * This is the same as the "g.mount" command, but it allows
 * you to set both the mount options and the vfstype as for
 * the mount(8) *-o* and *-t* flags.
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_mount_vfs+[http://libguestfs.org/guestfs.3.html#guestfs_mount_vfs]).
 */
static VALUE
ruby_guestfs_mount_vfs (VALUE gv, VALUE optionsv, VALUE vfstypev, VALUE devicev, VALUE mountpointv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "mount_vfs");

  const char *options = StringValueCStr (optionsv);
  const char *vfstype = StringValueCStr (vfstypev);
  const char *device = StringValueCStr (devicev);
  const char *mountpoint = StringValueCStr (mountpointv);

  int r;

  r = guestfs_mount_vfs (g, options, vfstype, device, mountpoint);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

static VALUE
ruby_guestfs_debug (VALUE gv, VALUE subcmdv, VALUE extraargsv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "debug");

  const char *subcmd = StringValueCStr (subcmdv);
  char **extraargs;
  Check_Type (extraargsv, T_ARRAY);
  {
    size_t i, len;
    len = RARRAY_LEN (extraargsv);
    extraargs = ALLOC_N (char *, len+1);
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

/*
 * call-seq:
 *   g.lvremove(device) -> nil
 *
 * remove an LVM logical volume
 *
 * Remove an LVM logical volume "device", where "device" is
 * the path to the LV, such as "/dev/VG/LV".
 * 
 * You can also remove all LVs in a volume group by
 * specifying the VG name, "/dev/VG".
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_lvremove+[http://libguestfs.org/guestfs.3.html#guestfs_lvremove]).
 */
static VALUE
ruby_guestfs_lvremove (VALUE gv, VALUE devicev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "lvremove");

  const char *device = StringValueCStr (devicev);

  int r;

  r = guestfs_lvremove (g, device);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.vgremove(vgname) -> nil
 *
 * remove an LVM volume group
 *
 * Remove an LVM volume group "vgname", (for example "VG").
 * 
 * This also forcibly removes all logical volumes in the
 * volume group (if any).
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_vgremove+[http://libguestfs.org/guestfs.3.html#guestfs_vgremove]).
 */
static VALUE
ruby_guestfs_vgremove (VALUE gv, VALUE vgnamev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "vgremove");

  const char *vgname = StringValueCStr (vgnamev);

  int r;

  r = guestfs_vgremove (g, vgname);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.pvremove(device) -> nil
 *
 * remove an LVM physical volume
 *
 * This wipes a physical volume "device" so that LVM will
 * no longer recognise it.
 * 
 * The implementation uses the "pvremove" command which
 * refuses to wipe physical volumes that contain any volume
 * groups, so you have to remove those first.
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_pvremove+[http://libguestfs.org/guestfs.3.html#guestfs_pvremove]).
 */
static VALUE
ruby_guestfs_pvremove (VALUE gv, VALUE devicev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "pvremove");

  const char *device = StringValueCStr (devicev);

  int r;

  r = guestfs_pvremove (g, device);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.set_e2label(device, label) -> nil
 *
 * set the ext2/3/4 filesystem label
 *
 * This sets the ext2/3/4 filesystem label of the
 * filesystem on "device" to "label". Filesystem labels are
 * limited to 16 characters.
 * 
 * You can use either "g.tune2fs_l" or "g.get_e2label" to
 * return the existing label on a filesystem.
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_set_e2label+[http://libguestfs.org/guestfs.3.html#guestfs_set_e2label]).
 */
static VALUE
ruby_guestfs_set_e2label (VALUE gv, VALUE devicev, VALUE labelv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "set_e2label");

  const char *device = StringValueCStr (devicev);
  const char *label = StringValueCStr (labelv);

  int r;

  r = guestfs_set_e2label (g, device, label);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.get_e2label(device) -> string
 *
 * get the ext2/3/4 filesystem label
 *
 * This returns the ext2/3/4 filesystem label of the
 * filesystem on "device".
 * 
 * *This function is deprecated.* In new code, use the
 * "vfs_label" call instead.
 * 
 * Deprecated functions will not be removed from the API,
 * but the fact that they are deprecated indicates that
 * there are problems with correct use of these functions.
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_get_e2label+[http://libguestfs.org/guestfs.3.html#guestfs_get_e2label]).
 */
static VALUE
ruby_guestfs_get_e2label (VALUE gv, VALUE devicev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "get_e2label");

  const char *device = StringValueCStr (devicev);

  char *r;

  r = guestfs_get_e2label (g, device);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  VALUE rv = rb_str_new2 (r);
  free (r);
  return rv;
}

/*
 * call-seq:
 *   g.set_e2uuid(device, uuid) -> nil
 *
 * set the ext2/3/4 filesystem UUID
 *
 * This sets the ext2/3/4 filesystem UUID of the filesystem
 * on "device" to "uuid". The format of the UUID and
 * alternatives such as "clear", "random" and "time" are
 * described in the tune2fs(8) manpage.
 * 
 * You can use either "g.tune2fs_l" or "g.get_e2uuid" to
 * return the existing UUID of a filesystem.
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_set_e2uuid+[http://libguestfs.org/guestfs.3.html#guestfs_set_e2uuid]).
 */
static VALUE
ruby_guestfs_set_e2uuid (VALUE gv, VALUE devicev, VALUE uuidv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "set_e2uuid");

  const char *device = StringValueCStr (devicev);
  const char *uuid = StringValueCStr (uuidv);

  int r;

  r = guestfs_set_e2uuid (g, device, uuid);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.get_e2uuid(device) -> string
 *
 * get the ext2/3/4 filesystem UUID
 *
 * This returns the ext2/3/4 filesystem UUID of the
 * filesystem on "device".
 * 
 * *This function is deprecated.* In new code, use the
 * "vfs_uuid" call instead.
 * 
 * Deprecated functions will not be removed from the API,
 * but the fact that they are deprecated indicates that
 * there are problems with correct use of these functions.
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_get_e2uuid+[http://libguestfs.org/guestfs.3.html#guestfs_get_e2uuid]).
 */
static VALUE
ruby_guestfs_get_e2uuid (VALUE gv, VALUE devicev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "get_e2uuid");

  const char *device = StringValueCStr (devicev);

  char *r;

  r = guestfs_get_e2uuid (g, device);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  VALUE rv = rb_str_new2 (r);
  free (r);
  return rv;
}

/*
 * call-seq:
 *   g.fsck(fstype, device) -> fixnum
 *
 * run the filesystem checker
 *
 * This runs the filesystem checker (fsck) on "device"
 * which should have filesystem type "fstype".
 * 
 * The returned integer is the status. See fsck(8) for the
 * list of status codes from "fsck".
 * 
 * Notes:
 * 
 * *   Multiple status codes can be summed together.
 * 
 * *   A non-zero return code can mean "success", for
 * example if errors have been corrected on the
 * filesystem.
 * 
 * *   Checking or repairing NTFS volumes is not supported
 * (by linux-ntfs).
 * 
 * This command is entirely equivalent to running "fsck -a
 * -t fstype device".
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_fsck+[http://libguestfs.org/guestfs.3.html#guestfs_fsck]).
 */
static VALUE
ruby_guestfs_fsck (VALUE gv, VALUE fstypev, VALUE devicev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "fsck");

  const char *fstype = StringValueCStr (fstypev);
  const char *device = StringValueCStr (devicev);

  int r;

  r = guestfs_fsck (g, fstype, device);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return INT2NUM (r);
}

/*
 * call-seq:
 *   g.zero(device) -> nil
 *
 * write zeroes to the device
 *
 * This command writes zeroes over the first few blocks of
 * "device".
 * 
 * How many blocks are zeroed isn't specified (but it's
 * *not* enough to securely wipe the device). It should be
 * sufficient to remove any partition tables, filesystem
 * superblocks and so on.
 * 
 * If blocks are already zero, then this command avoids
 * writing zeroes. This prevents the underlying device from
 * becoming non-sparse or growing unnecessarily.
 * 
 * See also: "g.zero_device", "g.scrub_device",
 * "g.is_zero_device"
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_zero+[http://libguestfs.org/guestfs.3.html#guestfs_zero]).
 */
static VALUE
ruby_guestfs_zero (VALUE gv, VALUE devicev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "zero");

  const char *device = StringValueCStr (devicev);

  int r;

  r = guestfs_zero (g, device);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.grub_install(root, device) -> nil
 *
 * install GRUB 1
 *
 * This command installs GRUB 1 (the Grand Unified
 * Bootloader) on "device", with the root directory being
 * "root".
 * 
 * Notes:
 * 
 * *   There is currently no way in the API to install
 * grub2, which is used by most modern Linux guests. It
 * is possible to run the grub2 command from the guest,
 * although see the caveats in "RUNNING COMMANDS" in
 * guestfs(3).
 * 
 * *   This uses "grub-install" from the host.
 * Unfortunately grub is not always compatible with
 * itself, so this only works in rather narrow
 * circumstances. Careful testing with each guest
 * version is advisable.
 * 
 * *   If grub-install reports the error "No suitable drive
 * was found in the generated device map." it may be
 * that you need to create a "/boot/grub/device.map"
 * file first that contains the mapping between grub
 * device names and Linux device names. It is usually
 * sufficient to create a file containing:
 * 
 * (hd0) /dev/vda
 * 
 * replacing "/dev/vda" with the name of the
 * installation device.
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_grub_install+[http://libguestfs.org/guestfs.3.html#guestfs_grub_install]).
 */
static VALUE
ruby_guestfs_grub_install (VALUE gv, VALUE rootv, VALUE devicev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "grub_install");

  const char *root = StringValueCStr (rootv);
  const char *device = StringValueCStr (devicev);

  int r;

  r = guestfs_grub_install (g, root, device);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.cp(src, dest) -> nil
 *
 * copy a file
 *
 * This copies a file from "src" to "dest" where "dest" is
 * either a destination filename or destination directory.
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_cp+[http://libguestfs.org/guestfs.3.html#guestfs_cp]).
 */
static VALUE
ruby_guestfs_cp (VALUE gv, VALUE srcv, VALUE destv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "cp");

  const char *src = StringValueCStr (srcv);
  const char *dest = StringValueCStr (destv);

  int r;

  r = guestfs_cp (g, src, dest);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.cp_a(src, dest) -> nil
 *
 * copy a file or directory recursively
 *
 * This copies a file or directory from "src" to "dest"
 * recursively using the "cp -a" command.
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_cp_a+[http://libguestfs.org/guestfs.3.html#guestfs_cp_a]).
 */
static VALUE
ruby_guestfs_cp_a (VALUE gv, VALUE srcv, VALUE destv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "cp_a");

  const char *src = StringValueCStr (srcv);
  const char *dest = StringValueCStr (destv);

  int r;

  r = guestfs_cp_a (g, src, dest);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.mv(src, dest) -> nil
 *
 * move a file
 *
 * This moves a file from "src" to "dest" where "dest" is
 * either a destination filename or destination directory.
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_mv+[http://libguestfs.org/guestfs.3.html#guestfs_mv]).
 */
static VALUE
ruby_guestfs_mv (VALUE gv, VALUE srcv, VALUE destv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "mv");

  const char *src = StringValueCStr (srcv);
  const char *dest = StringValueCStr (destv);

  int r;

  r = guestfs_mv (g, src, dest);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.drop_caches(whattodrop) -> nil
 *
 * drop kernel page cache, dentries and inodes
 *
 * This instructs the guest kernel to drop its page cache,
 * and/or dentries and inode caches. The parameter
 * "whattodrop" tells the kernel what precisely to drop,
 * see <http://linux-mm.org/Drop_Caches>
 * 
 * Setting "whattodrop" to 3 should drop everything.
 * 
 * This automatically calls sync(2) before the operation,
 * so that the maximum guest memory is freed.
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_drop_caches+[http://libguestfs.org/guestfs.3.html#guestfs_drop_caches]).
 */
static VALUE
ruby_guestfs_drop_caches (VALUE gv, VALUE whattodropv)
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

/*
 * call-seq:
 *   g.dmesg() -> string
 *
 * return kernel messages
 *
 * This returns the kernel messages ("dmesg" output) from
 * the guest kernel. This is sometimes useful for extended
 * debugging of problems.
 * 
 * Another way to get the same information is to enable
 * verbose messages with "g.set_verbose" or by setting the
 * environment variable "LIBGUESTFS_DEBUG=1" before running
 * the program.
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_dmesg+[http://libguestfs.org/guestfs.3.html#guestfs_dmesg]).
 */
static VALUE
ruby_guestfs_dmesg (VALUE gv)
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

/*
 * call-seq:
 *   g.ping_daemon() -> nil
 *
 * ping the guest daemon
 *
 * This is a test probe into the guestfs daemon running
 * inside the qemu subprocess. Calling this function checks
 * that the daemon responds to the ping message, without
 * affecting the daemon or attached block device(s) in any
 * other way.
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_ping_daemon+[http://libguestfs.org/guestfs.3.html#guestfs_ping_daemon]).
 */
static VALUE
ruby_guestfs_ping_daemon (VALUE gv)
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

/*
 * call-seq:
 *   g.equal(file1, file2) -> [True|False]
 *
 * test if two files have equal contents
 *
 * This compares the two files "file1" and "file2" and
 * returns true if their content is exactly equal, or false
 * otherwise.
 * 
 * The external cmp(1) program is used for the comparison.
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_equal+[http://libguestfs.org/guestfs.3.html#guestfs_equal]).
 */
static VALUE
ruby_guestfs_equal (VALUE gv, VALUE file1v, VALUE file2v)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "equal");

  const char *file1 = StringValueCStr (file1v);
  const char *file2 = StringValueCStr (file2v);

  int r;

  r = guestfs_equal (g, file1, file2);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return INT2NUM (r);
}

/*
 * call-seq:
 *   g.strings(path) -> list
 *
 * print the printable strings in a file
 *
 * This runs the strings(1) command on a file and returns
 * the list of printable strings found.
 * 
 * Because of the message protocol, there is a transfer
 * limit of somewhere between 2MB and 4MB. See "PROTOCOL
 * LIMITS" in guestfs(3).
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_strings+[http://libguestfs.org/guestfs.3.html#guestfs_strings]).
 */
static VALUE
ruby_guestfs_strings (VALUE gv, VALUE pathv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "strings");

  const char *path = StringValueCStr (pathv);

  char **r;

  r = guestfs_strings (g, path);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  size_t i, len = 0;
  for (i = 0; r[i] != NULL; ++i) len++;
  VALUE rv = rb_ary_new2 (len);
  for (i = 0; r[i] != NULL; ++i) {
    rb_ary_push (rv, rb_str_new2 (r[i]));
    free (r[i]);
  }
  free (r);
  return rv;
}

/*
 * call-seq:
 *   g.strings_e(encoding, path) -> list
 *
 * print the printable strings in a file
 *
 * This is like the "g.strings" command, but allows you to
 * specify the encoding of strings that are looked for in
 * the source file "path".
 * 
 * Allowed encodings are:
 * 
 * s   Single 7-bit-byte characters like ASCII and the
 * ASCII-compatible parts of ISO-8859-X (this is what
 * "g.strings" uses).
 * 
 * S   Single 8-bit-byte characters.
 * 
 * b   16-bit big endian strings such as those encoded in
 * UTF-16BE or UCS-2BE.
 * 
 * l (lower case letter L)
 * 16-bit little endian such as UTF-16LE and UCS-2LE.
 * This is useful for examining binaries in Windows
 * guests.
 * 
 * B   32-bit big endian such as UCS-4BE.
 * 
 * L   32-bit little endian such as UCS-4LE.
 * 
 * The returned strings are transcoded to UTF-8.
 * 
 * Because of the message protocol, there is a transfer
 * limit of somewhere between 2MB and 4MB. See "PROTOCOL
 * LIMITS" in guestfs(3).
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_strings_e+[http://libguestfs.org/guestfs.3.html#guestfs_strings_e]).
 */
static VALUE
ruby_guestfs_strings_e (VALUE gv, VALUE encodingv, VALUE pathv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "strings_e");

  const char *encoding = StringValueCStr (encodingv);
  const char *path = StringValueCStr (pathv);

  char **r;

  r = guestfs_strings_e (g, encoding, path);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  size_t i, len = 0;
  for (i = 0; r[i] != NULL; ++i) len++;
  VALUE rv = rb_ary_new2 (len);
  for (i = 0; r[i] != NULL; ++i) {
    rb_ary_push (rv, rb_str_new2 (r[i]));
    free (r[i]);
  }
  free (r);
  return rv;
}

/*
 * call-seq:
 *   g.hexdump(path) -> string
 *
 * dump a file in hexadecimal
 *
 * This runs "hexdump -C" on the given "path". The result
 * is the human-readable, canonical hex dump of the file.
 * 
 * Because of the message protocol, there is a transfer
 * limit of somewhere between 2MB and 4MB. See "PROTOCOL
 * LIMITS" in guestfs(3).
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_hexdump+[http://libguestfs.org/guestfs.3.html#guestfs_hexdump]).
 */
static VALUE
ruby_guestfs_hexdump (VALUE gv, VALUE pathv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "hexdump");

  const char *path = StringValueCStr (pathv);

  char *r;

  r = guestfs_hexdump (g, path);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  VALUE rv = rb_str_new2 (r);
  free (r);
  return rv;
}

/*
 * call-seq:
 *   g.zerofree(device) -> nil
 *
 * zero unused inodes and disk blocks on ext2/3 filesystem
 *
 * This runs the *zerofree* program on "device". This
 * program claims to zero unused inodes and disk blocks on
 * an ext2/3 filesystem, thus making it possible to
 * compress the filesystem more effectively.
 * 
 * You should not run this program if the filesystem is
 * mounted.
 * 
 * It is possible that using this program can damage the
 * filesystem or data on the filesystem.
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_zerofree+[http://libguestfs.org/guestfs.3.html#guestfs_zerofree]).
 */
static VALUE
ruby_guestfs_zerofree (VALUE gv, VALUE devicev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "zerofree");

  const char *device = StringValueCStr (devicev);

  int r;

  r = guestfs_zerofree (g, device);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.pvresize(device) -> nil
 *
 * resize an LVM physical volume
 *
 * This resizes (expands or shrinks) an existing LVM
 * physical volume to match the new size of the underlying
 * device.
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_pvresize+[http://libguestfs.org/guestfs.3.html#guestfs_pvresize]).
 */
static VALUE
ruby_guestfs_pvresize (VALUE gv, VALUE devicev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "pvresize");

  const char *device = StringValueCStr (devicev);

  int r;

  r = guestfs_pvresize (g, device);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.sfdisk_N(device, partnum, cyls, heads, sectors, line) -> nil
 *
 * modify a single partition on a block device
 *
 * This runs sfdisk(8) option to modify just the single
 * partition "n" (note: "n" counts from 1).
 * 
 * For other parameters, see "g.sfdisk". You should usually
 * pass 0 for the cyls/heads/sectors parameters.
 * 
 * See also: "g.part_add"
 * 
 * *This function is deprecated.* In new code, use the
 * "part_add" call instead.
 * 
 * Deprecated functions will not be removed from the API,
 * but the fact that they are deprecated indicates that
 * there are problems with correct use of these functions.
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_sfdisk_N+[http://libguestfs.org/guestfs.3.html#guestfs_sfdisk_N]).
 */
static VALUE
ruby_guestfs_sfdisk_N (VALUE gv, VALUE devicev, VALUE partnumv, VALUE cylsv, VALUE headsv, VALUE sectorsv, VALUE linev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "sfdisk_N");

  const char *device = StringValueCStr (devicev);
  int partnum = NUM2INT (partnumv);
  int cyls = NUM2INT (cylsv);
  int heads = NUM2INT (headsv);
  int sectors = NUM2INT (sectorsv);
  const char *line = StringValueCStr (linev);

  int r;

  r = guestfs_sfdisk_N (g, device, partnum, cyls, heads, sectors, line);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.sfdisk_l(device) -> string
 *
 * display the partition table
 *
 * This displays the partition table on "device", in the
 * human-readable output of the sfdisk(8) command. It is
 * not intended to be parsed.
 * 
 * See also: "g.part_list"
 * 
 * *This function is deprecated.* In new code, use the
 * "part_list" call instead.
 * 
 * Deprecated functions will not be removed from the API,
 * but the fact that they are deprecated indicates that
 * there are problems with correct use of these functions.
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_sfdisk_l+[http://libguestfs.org/guestfs.3.html#guestfs_sfdisk_l]).
 */
static VALUE
ruby_guestfs_sfdisk_l (VALUE gv, VALUE devicev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "sfdisk_l");

  const char *device = StringValueCStr (devicev);

  char *r;

  r = guestfs_sfdisk_l (g, device);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  VALUE rv = rb_str_new2 (r);
  free (r);
  return rv;
}

/*
 * call-seq:
 *   g.sfdisk_kernel_geometry(device) -> string
 *
 * display the kernel geometry
 *
 * This displays the kernel's idea of the geometry of
 * "device".
 * 
 * The result is in human-readable format, and not designed
 * to be parsed.
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_sfdisk_kernel_geometry+[http://libguestfs.org/guestfs.3.html#guestfs_sfdisk_kernel_geometry]).
 */
static VALUE
ruby_guestfs_sfdisk_kernel_geometry (VALUE gv, VALUE devicev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "sfdisk_kernel_geometry");

  const char *device = StringValueCStr (devicev);

  char *r;

  r = guestfs_sfdisk_kernel_geometry (g, device);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  VALUE rv = rb_str_new2 (r);
  free (r);
  return rv;
}

/*
 * call-seq:
 *   g.sfdisk_disk_geometry(device) -> string
 *
 * display the disk geometry from the partition table
 *
 * This displays the disk geometry of "device" read from
 * the partition table. Especially in the case where the
 * underlying block device has been resized, this can be
 * different from the kernel's idea of the geometry (see
 * "g.sfdisk_kernel_geometry").
 * 
 * The result is in human-readable format, and not designed
 * to be parsed.
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_sfdisk_disk_geometry+[http://libguestfs.org/guestfs.3.html#guestfs_sfdisk_disk_geometry]).
 */
static VALUE
ruby_guestfs_sfdisk_disk_geometry (VALUE gv, VALUE devicev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "sfdisk_disk_geometry");

  const char *device = StringValueCStr (devicev);

  char *r;

  r = guestfs_sfdisk_disk_geometry (g, device);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  VALUE rv = rb_str_new2 (r);
  free (r);
  return rv;
}

/*
 * call-seq:
 *   g.vg_activate_all(activate) -> nil
 *
 * activate or deactivate all volume groups
 *
 * This command activates or (if "activate" is false)
 * deactivates all logical volumes in all volume groups.
 * 
 * This command is the same as running "vgchange -a y|n"
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_vg_activate_all+[http://libguestfs.org/guestfs.3.html#guestfs_vg_activate_all]).
 */
static VALUE
ruby_guestfs_vg_activate_all (VALUE gv, VALUE activatev)
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

/*
 * call-seq:
 *   g.vg_activate(activate, volgroups) -> nil
 *
 * activate or deactivate some volume groups
 *
 * This command activates or (if "activate" is false)
 * deactivates all logical volumes in the listed volume
 * groups "volgroups".
 * 
 * This command is the same as running "vgchange -a y|n
 * volgroups..."
 * 
 * Note that if "volgroups" is an empty list then all
 * volume groups are activated or deactivated.
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_vg_activate+[http://libguestfs.org/guestfs.3.html#guestfs_vg_activate]).
 */
static VALUE
ruby_guestfs_vg_activate (VALUE gv, VALUE activatev, VALUE volgroupsv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "vg_activate");

  int activate = RTEST (activatev);
  char **volgroups;
  Check_Type (volgroupsv, T_ARRAY);
  {
    size_t i, len;
    len = RARRAY_LEN (volgroupsv);
    volgroups = ALLOC_N (char *, len+1);
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

/*
 * call-seq:
 *   g.lvresize(device, mbytes) -> nil
 *
 * resize an LVM logical volume
 *
 * This resizes (expands or shrinks) an existing LVM
 * logical volume to "mbytes". When reducing, data in the
 * reduced part is lost.
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_lvresize+[http://libguestfs.org/guestfs.3.html#guestfs_lvresize]).
 */
static VALUE
ruby_guestfs_lvresize (VALUE gv, VALUE devicev, VALUE mbytesv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "lvresize");

  const char *device = StringValueCStr (devicev);
  int mbytes = NUM2INT (mbytesv);

  int r;

  r = guestfs_lvresize (g, device, mbytes);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.resize2fs(device) -> nil
 *
 * resize an ext2, ext3 or ext4 filesystem
 *
 * This resizes an ext2, ext3 or ext4 filesystem to match
 * the size of the underlying device.
 * 
 * *Note:* It is sometimes required that you run
 * "g.e2fsck_f" on the "device" before calling this
 * command. For unknown reasons "resize2fs" sometimes gives
 * an error about this and sometimes not. In any case, it
 * is always safe to call "g.e2fsck_f" before calling this
 * function.
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_resize2fs+[http://libguestfs.org/guestfs.3.html#guestfs_resize2fs]).
 */
static VALUE
ruby_guestfs_resize2fs (VALUE gv, VALUE devicev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "resize2fs");

  const char *device = StringValueCStr (devicev);

  int r;

  r = guestfs_resize2fs (g, device);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.find(directory) -> list
 *
 * find all files and directories
 *
 * This command lists out all files and directories,
 * recursively, starting at "directory". It is essentially
 * equivalent to running the shell command "find directory
 * -print" but some post-processing happens on the output,
 * described below.
 * 
 * This returns a list of strings *without any prefix*.
 * Thus if the directory structure was:
 * 
 * /tmp/a
 * /tmp/b
 * /tmp/c/d
 * 
 * then the returned list from "g.find" "/tmp" would be 4
 * elements:
 * 
 * a
 * b
 * c
 * c/d
 * 
 * If "directory" is not a directory, then this command
 * returns an error.
 * 
 * The returned list is sorted.
 * 
 * See also "g.find0".
 * 
 * Because of the message protocol, there is a transfer
 * limit of somewhere between 2MB and 4MB. See "PROTOCOL
 * LIMITS" in guestfs(3).
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_find+[http://libguestfs.org/guestfs.3.html#guestfs_find]).
 */
static VALUE
ruby_guestfs_find (VALUE gv, VALUE directoryv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "find");

  const char *directory = StringValueCStr (directoryv);

  char **r;

  r = guestfs_find (g, directory);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  size_t i, len = 0;
  for (i = 0; r[i] != NULL; ++i) len++;
  VALUE rv = rb_ary_new2 (len);
  for (i = 0; r[i] != NULL; ++i) {
    rb_ary_push (rv, rb_str_new2 (r[i]));
    free (r[i]);
  }
  free (r);
  return rv;
}

/*
 * call-seq:
 *   g.e2fsck_f(device) -> nil
 *
 * check an ext2/ext3 filesystem
 *
 * This runs "e2fsck -p -f device", ie. runs the ext2/ext3
 * filesystem checker on "device", noninteractively (*-p*),
 * even if the filesystem appears to be clean (*-f*).
 * 
 * This command is only needed because of "g.resize2fs"
 * (q.v.). Normally you should use "g.fsck".
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_e2fsck_f+[http://libguestfs.org/guestfs.3.html#guestfs_e2fsck_f]).
 */
static VALUE
ruby_guestfs_e2fsck_f (VALUE gv, VALUE devicev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "e2fsck_f");

  const char *device = StringValueCStr (devicev);

  int r;

  r = guestfs_e2fsck_f (g, device);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.sleep(secs) -> nil
 *
 * sleep for some seconds
 *
 * Sleep for "secs" seconds.
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_sleep+[http://libguestfs.org/guestfs.3.html#guestfs_sleep]).
 */
static VALUE
ruby_guestfs_sleep (VALUE gv, VALUE secsv)
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

/*
 * call-seq:
 *   g.ntfs_3g_probe(rw, device) -> fixnum
 *
 * probe NTFS volume
 *
 * This command runs the ntfs-3g.probe(8) command which
 * probes an NTFS "device" for mountability. (Not all NTFS
 * volumes can be mounted read-write, and some cannot be
 * mounted at all).
 * 
 * "rw" is a boolean flag. Set it to true if you want to
 * test if the volume can be mounted read-write. Set it to
 * false if you want to test if the volume can be mounted
 * read-only.
 * 
 * The return value is an integer which 0 if the operation
 * would succeed, or some non-zero value documented in the
 * ntfs-3g.probe(8) manual page.
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_ntfs_3g_probe+[http://libguestfs.org/guestfs.3.html#guestfs_ntfs_3g_probe]).
 */
static VALUE
ruby_guestfs_ntfs_3g_probe (VALUE gv, VALUE rwv, VALUE devicev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "ntfs_3g_probe");

  int rw = RTEST (rwv);
  const char *device = StringValueCStr (devicev);

  int r;

  r = guestfs_ntfs_3g_probe (g, rw, device);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return INT2NUM (r);
}

/*
 * call-seq:
 *   g.sh(command) -> string
 *
 * run a command via the shell
 *
 * This call runs a command from the guest filesystem via
 * the guest's "/bin/sh".
 * 
 * This is like "g.command", but passes the command to:
 * 
 * /bin/sh -c "command"
 * 
 * Depending on the guest's shell, this usually results in
 * wildcards being expanded, shell expressions being
 * interpolated and so on.
 * 
 * All the provisos about "g.command" apply to this call.
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_sh+[http://libguestfs.org/guestfs.3.html#guestfs_sh]).
 */
static VALUE
ruby_guestfs_sh (VALUE gv, VALUE commandv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "sh");

  const char *command = StringValueCStr (commandv);

  char *r;

  r = guestfs_sh (g, command);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  VALUE rv = rb_str_new2 (r);
  free (r);
  return rv;
}

/*
 * call-seq:
 *   g.sh_lines(command) -> list
 *
 * run a command via the shell returning lines
 *
 * This is the same as "g.sh", but splits the result into a
 * list of lines.
 * 
 * See also: "g.command_lines"
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_sh_lines+[http://libguestfs.org/guestfs.3.html#guestfs_sh_lines]).
 */
static VALUE
ruby_guestfs_sh_lines (VALUE gv, VALUE commandv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "sh_lines");

  const char *command = StringValueCStr (commandv);

  char **r;

  r = guestfs_sh_lines (g, command);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  size_t i, len = 0;
  for (i = 0; r[i] != NULL; ++i) len++;
  VALUE rv = rb_ary_new2 (len);
  for (i = 0; r[i] != NULL; ++i) {
    rb_ary_push (rv, rb_str_new2 (r[i]));
    free (r[i]);
  }
  free (r);
  return rv;
}

/*
 * call-seq:
 *   g.glob_expand(pattern) -> list
 *
 * expand a wildcard path
 *
 * This command searches for all the pathnames matching
 * "pattern" according to the wildcard expansion rules used
 * by the shell.
 * 
 * If no paths match, then this returns an empty list
 * (note: not an error).
 * 
 * It is just a wrapper around the C glob(3) function with
 * flags "GLOB_MARK|GLOB_BRACE". See that manual page for
 * more details.
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_glob_expand+[http://libguestfs.org/guestfs.3.html#guestfs_glob_expand]).
 */
static VALUE
ruby_guestfs_glob_expand (VALUE gv, VALUE patternv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "glob_expand");

  const char *pattern = StringValueCStr (patternv);

  char **r;

  r = guestfs_glob_expand (g, pattern);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  size_t i, len = 0;
  for (i = 0; r[i] != NULL; ++i) len++;
  VALUE rv = rb_ary_new2 (len);
  for (i = 0; r[i] != NULL; ++i) {
    rb_ary_push (rv, rb_str_new2 (r[i]));
    free (r[i]);
  }
  free (r);
  return rv;
}

/*
 * call-seq:
 *   g.scrub_device(device) -> nil
 *
 * scrub (securely wipe) a device
 *
 * This command writes patterns over "device" to make data
 * retrieval more difficult.
 * 
 * It is an interface to the scrub(1) program. See that
 * manual page for more details.
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_scrub_device+[http://libguestfs.org/guestfs.3.html#guestfs_scrub_device]).
 */
static VALUE
ruby_guestfs_scrub_device (VALUE gv, VALUE devicev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "scrub_device");

  const char *device = StringValueCStr (devicev);

  int r;

  r = guestfs_scrub_device (g, device);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.scrub_file(file) -> nil
 *
 * scrub (securely wipe) a file
 *
 * This command writes patterns over a file to make data
 * retrieval more difficult.
 * 
 * The file is *removed* after scrubbing.
 * 
 * It is an interface to the scrub(1) program. See that
 * manual page for more details.
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_scrub_file+[http://libguestfs.org/guestfs.3.html#guestfs_scrub_file]).
 */
static VALUE
ruby_guestfs_scrub_file (VALUE gv, VALUE filev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "scrub_file");

  const char *file = StringValueCStr (filev);

  int r;

  r = guestfs_scrub_file (g, file);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.scrub_freespace(dir) -> nil
 *
 * scrub (securely wipe) free space
 *
 * This command creates the directory "dir" and then fills
 * it with files until the filesystem is full, and scrubs
 * the files as for "g.scrub_file", and deletes them. The
 * intention is to scrub any free space on the partition
 * containing "dir".
 * 
 * It is an interface to the scrub(1) program. See that
 * manual page for more details.
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_scrub_freespace+[http://libguestfs.org/guestfs.3.html#guestfs_scrub_freespace]).
 */
static VALUE
ruby_guestfs_scrub_freespace (VALUE gv, VALUE dirv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "scrub_freespace");

  const char *dir = StringValueCStr (dirv);

  int r;

  r = guestfs_scrub_freespace (g, dir);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.mkdtemp(template) -> string
 *
 * create a temporary directory
 *
 * This command creates a temporary directory. The
 * "template" parameter should be a full pathname for the
 * temporary directory name with the final six characters
 * being "XXXXXX".
 * 
 * For example: "/tmp/myprogXXXXXX" or
 * "/Temp/myprogXXXXXX", the second one being suitable for
 * Windows filesystems.
 * 
 * The name of the temporary directory that was created is
 * returned.
 * 
 * The temporary directory is created with mode 0700 and is
 * owned by root.
 * 
 * The caller is responsible for deleting the temporary
 * directory and its contents after use.
 * 
 * See also: mkdtemp(3)
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_mkdtemp+[http://libguestfs.org/guestfs.3.html#guestfs_mkdtemp]).
 */
static VALUE
ruby_guestfs_mkdtemp (VALUE gv, VALUE templatev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "mkdtemp");

  const char *template = StringValueCStr (templatev);

  char *r;

  r = guestfs_mkdtemp (g, template);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  VALUE rv = rb_str_new2 (r);
  free (r);
  return rv;
}

/*
 * call-seq:
 *   g.wc_l(path) -> fixnum
 *
 * count lines in a file
 *
 * This command counts the lines in a file, using the "wc
 * -l" external command.
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_wc_l+[http://libguestfs.org/guestfs.3.html#guestfs_wc_l]).
 */
static VALUE
ruby_guestfs_wc_l (VALUE gv, VALUE pathv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "wc_l");

  const char *path = StringValueCStr (pathv);

  int r;

  r = guestfs_wc_l (g, path);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return INT2NUM (r);
}

/*
 * call-seq:
 *   g.wc_w(path) -> fixnum
 *
 * count words in a file
 *
 * This command counts the words in a file, using the "wc
 * -w" external command.
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_wc_w+[http://libguestfs.org/guestfs.3.html#guestfs_wc_w]).
 */
static VALUE
ruby_guestfs_wc_w (VALUE gv, VALUE pathv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "wc_w");

  const char *path = StringValueCStr (pathv);

  int r;

  r = guestfs_wc_w (g, path);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return INT2NUM (r);
}

/*
 * call-seq:
 *   g.wc_c(path) -> fixnum
 *
 * count characters in a file
 *
 * This command counts the characters in a file, using the
 * "wc -c" external command.
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_wc_c+[http://libguestfs.org/guestfs.3.html#guestfs_wc_c]).
 */
static VALUE
ruby_guestfs_wc_c (VALUE gv, VALUE pathv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "wc_c");

  const char *path = StringValueCStr (pathv);

  int r;

  r = guestfs_wc_c (g, path);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return INT2NUM (r);
}

/*
 * call-seq:
 *   g.head(path) -> list
 *
 * return first 10 lines of a file
 *
 * This command returns up to the first 10 lines of a file
 * as a list of strings.
 * 
 * Because of the message protocol, there is a transfer
 * limit of somewhere between 2MB and 4MB. See "PROTOCOL
 * LIMITS" in guestfs(3).
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_head+[http://libguestfs.org/guestfs.3.html#guestfs_head]).
 */
static VALUE
ruby_guestfs_head (VALUE gv, VALUE pathv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "head");

  const char *path = StringValueCStr (pathv);

  char **r;

  r = guestfs_head (g, path);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  size_t i, len = 0;
  for (i = 0; r[i] != NULL; ++i) len++;
  VALUE rv = rb_ary_new2 (len);
  for (i = 0; r[i] != NULL; ++i) {
    rb_ary_push (rv, rb_str_new2 (r[i]));
    free (r[i]);
  }
  free (r);
  return rv;
}

/*
 * call-seq:
 *   g.head_n(nrlines, path) -> list
 *
 * return first N lines of a file
 *
 * If the parameter "nrlines" is a positive number, this
 * returns the first "nrlines" lines of the file "path".
 * 
 * If the parameter "nrlines" is a negative number, this
 * returns lines from the file "path", excluding the last
 * "nrlines" lines.
 * 
 * If the parameter "nrlines" is zero, this returns an
 * empty list.
 * 
 * Because of the message protocol, there is a transfer
 * limit of somewhere between 2MB and 4MB. See "PROTOCOL
 * LIMITS" in guestfs(3).
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_head_n+[http://libguestfs.org/guestfs.3.html#guestfs_head_n]).
 */
static VALUE
ruby_guestfs_head_n (VALUE gv, VALUE nrlinesv, VALUE pathv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "head_n");

  int nrlines = NUM2INT (nrlinesv);
  const char *path = StringValueCStr (pathv);

  char **r;

  r = guestfs_head_n (g, nrlines, path);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  size_t i, len = 0;
  for (i = 0; r[i] != NULL; ++i) len++;
  VALUE rv = rb_ary_new2 (len);
  for (i = 0; r[i] != NULL; ++i) {
    rb_ary_push (rv, rb_str_new2 (r[i]));
    free (r[i]);
  }
  free (r);
  return rv;
}

/*
 * call-seq:
 *   g.tail(path) -> list
 *
 * return last 10 lines of a file
 *
 * This command returns up to the last 10 lines of a file
 * as a list of strings.
 * 
 * Because of the message protocol, there is a transfer
 * limit of somewhere between 2MB and 4MB. See "PROTOCOL
 * LIMITS" in guestfs(3).
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_tail+[http://libguestfs.org/guestfs.3.html#guestfs_tail]).
 */
static VALUE
ruby_guestfs_tail (VALUE gv, VALUE pathv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "tail");

  const char *path = StringValueCStr (pathv);

  char **r;

  r = guestfs_tail (g, path);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  size_t i, len = 0;
  for (i = 0; r[i] != NULL; ++i) len++;
  VALUE rv = rb_ary_new2 (len);
  for (i = 0; r[i] != NULL; ++i) {
    rb_ary_push (rv, rb_str_new2 (r[i]));
    free (r[i]);
  }
  free (r);
  return rv;
}

/*
 * call-seq:
 *   g.tail_n(nrlines, path) -> list
 *
 * return last N lines of a file
 *
 * If the parameter "nrlines" is a positive number, this
 * returns the last "nrlines" lines of the file "path".
 * 
 * If the parameter "nrlines" is a negative number, this
 * returns lines from the file "path", starting with the
 * "-nrlines"th line.
 * 
 * If the parameter "nrlines" is zero, this returns an
 * empty list.
 * 
 * Because of the message protocol, there is a transfer
 * limit of somewhere between 2MB and 4MB. See "PROTOCOL
 * LIMITS" in guestfs(3).
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_tail_n+[http://libguestfs.org/guestfs.3.html#guestfs_tail_n]).
 */
static VALUE
ruby_guestfs_tail_n (VALUE gv, VALUE nrlinesv, VALUE pathv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "tail_n");

  int nrlines = NUM2INT (nrlinesv);
  const char *path = StringValueCStr (pathv);

  char **r;

  r = guestfs_tail_n (g, nrlines, path);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  size_t i, len = 0;
  for (i = 0; r[i] != NULL; ++i) len++;
  VALUE rv = rb_ary_new2 (len);
  for (i = 0; r[i] != NULL; ++i) {
    rb_ary_push (rv, rb_str_new2 (r[i]));
    free (r[i]);
  }
  free (r);
  return rv;
}

/*
 * call-seq:
 *   g.df() -> string
 *
 * report file system disk space usage
 *
 * This command runs the "df" command to report disk space
 * used.
 * 
 * This command is mostly useful for interactive sessions.
 * It is *not* intended that you try to parse the output
 * string. Use "g.statvfs" from programs.
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_df+[http://libguestfs.org/guestfs.3.html#guestfs_df]).
 */
static VALUE
ruby_guestfs_df (VALUE gv)
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

/*
 * call-seq:
 *   g.df_h() -> string
 *
 * report file system disk space usage (human readable)
 *
 * This command runs the "df -h" command to report disk
 * space used in human-readable format.
 * 
 * This command is mostly useful for interactive sessions.
 * It is *not* intended that you try to parse the output
 * string. Use "g.statvfs" from programs.
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_df_h+[http://libguestfs.org/guestfs.3.html#guestfs_df_h]).
 */
static VALUE
ruby_guestfs_df_h (VALUE gv)
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

/*
 * call-seq:
 *   g.du(path) -> fixnum
 *
 * estimate file space usage
 *
 * This command runs the "du -s" command to estimate file
 * space usage for "path".
 * 
 * "path" can be a file or a directory. If "path" is a
 * directory then the estimate includes the contents of the
 * directory and all subdirectories (recursively).
 * 
 * The result is the estimated size in *kilobytes* (ie.
 * units of 1024 bytes).
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_du+[http://libguestfs.org/guestfs.3.html#guestfs_du]).
 */
static VALUE
ruby_guestfs_du (VALUE gv, VALUE pathv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "du");

  const char *path = StringValueCStr (pathv);

  int64_t r;

  r = guestfs_du (g, path);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return ULL2NUM (r);
}

/*
 * call-seq:
 *   g.initrd_list(path) -> list
 *
 * list files in an initrd
 *
 * This command lists out files contained in an initrd.
 * 
 * The files are listed without any initial "/" character.
 * The files are listed in the order they appear (not
 * necessarily alphabetical). Directory names are listed as
 * separate items.
 * 
 * Old Linux kernels (2.4 and earlier) used a compressed
 * ext2 filesystem as initrd. We *only* support the newer
 * initramfs format (compressed cpio files).
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_initrd_list+[http://libguestfs.org/guestfs.3.html#guestfs_initrd_list]).
 */
static VALUE
ruby_guestfs_initrd_list (VALUE gv, VALUE pathv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "initrd_list");

  const char *path = StringValueCStr (pathv);

  char **r;

  r = guestfs_initrd_list (g, path);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  size_t i, len = 0;
  for (i = 0; r[i] != NULL; ++i) len++;
  VALUE rv = rb_ary_new2 (len);
  for (i = 0; r[i] != NULL; ++i) {
    rb_ary_push (rv, rb_str_new2 (r[i]));
    free (r[i]);
  }
  free (r);
  return rv;
}

/*
 * call-seq:
 *   g.mount_loop(file, mountpoint) -> nil
 *
 * mount a file using the loop device
 *
 * This command lets you mount "file" (a filesystem image
 * in a file) on a mount point. It is entirely equivalent
 * to the command "mount -o loop file mountpoint".
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_mount_loop+[http://libguestfs.org/guestfs.3.html#guestfs_mount_loop]).
 */
static VALUE
ruby_guestfs_mount_loop (VALUE gv, VALUE filev, VALUE mountpointv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "mount_loop");

  const char *file = StringValueCStr (filev);
  const char *mountpoint = StringValueCStr (mountpointv);

  int r;

  r = guestfs_mount_loop (g, file, mountpoint);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.mkswap(device) -> nil
 *
 * create a swap partition
 *
 * Create a swap partition on "device".
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_mkswap+[http://libguestfs.org/guestfs.3.html#guestfs_mkswap]).
 */
static VALUE
ruby_guestfs_mkswap (VALUE gv, VALUE devicev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "mkswap");

  const char *device = StringValueCStr (devicev);

  int r;

  r = guestfs_mkswap (g, device);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.mkswap_L(label, device) -> nil
 *
 * create a swap partition with a label
 *
 * Create a swap partition on "device" with label "label".
 * 
 * Note that you cannot attach a swap label to a block
 * device (eg. "/dev/sda"), just to a partition. This
 * appears to be a limitation of the kernel or swap tools.
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_mkswap_L+[http://libguestfs.org/guestfs.3.html#guestfs_mkswap_L]).
 */
static VALUE
ruby_guestfs_mkswap_L (VALUE gv, VALUE labelv, VALUE devicev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "mkswap_L");

  const char *label = StringValueCStr (labelv);
  const char *device = StringValueCStr (devicev);

  int r;

  r = guestfs_mkswap_L (g, label, device);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.mkswap_U(uuid, device) -> nil
 *
 * create a swap partition with an explicit UUID
 *
 * Create a swap partition on "device" with UUID "uuid".
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_mkswap_U+[http://libguestfs.org/guestfs.3.html#guestfs_mkswap_U]).
 */
static VALUE
ruby_guestfs_mkswap_U (VALUE gv, VALUE uuidv, VALUE devicev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "mkswap_U");

  const char *uuid = StringValueCStr (uuidv);
  const char *device = StringValueCStr (devicev);

  int r;

  r = guestfs_mkswap_U (g, uuid, device);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.mknod(mode, devmajor, devminor, path) -> nil
 *
 * make block, character or FIFO devices
 *
 * This call creates block or character special devices, or
 * named pipes (FIFOs).
 * 
 * The "mode" parameter should be the mode, using the
 * standard constants. "devmajor" and "devminor" are the
 * device major and minor numbers, only used when creating
 * block and character special devices.
 * 
 * Note that, just like mknod(2), the mode must be bitwise
 * OR'd with S_IFBLK, S_IFCHR, S_IFIFO or S_IFSOCK
 * (otherwise this call just creates a regular file). These
 * constants are available in the standard Linux header
 * files, or you can use "g.mknod_b", "g.mknod_c" or
 * "g.mkfifo" which are wrappers around this command which
 * bitwise OR in the appropriate constant for you.
 * 
 * The mode actually set is affected by the umask.
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_mknod+[http://libguestfs.org/guestfs.3.html#guestfs_mknod]).
 */
static VALUE
ruby_guestfs_mknod (VALUE gv, VALUE modev, VALUE devmajorv, VALUE devminorv, VALUE pathv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "mknod");

  int mode = NUM2INT (modev);
  int devmajor = NUM2INT (devmajorv);
  int devminor = NUM2INT (devminorv);
  const char *path = StringValueCStr (pathv);

  int r;

  r = guestfs_mknod (g, mode, devmajor, devminor, path);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.mkfifo(mode, path) -> nil
 *
 * make FIFO (named pipe)
 *
 * This call creates a FIFO (named pipe) called "path" with
 * mode "mode". It is just a convenient wrapper around
 * "g.mknod".
 * 
 * The mode actually set is affected by the umask.
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_mkfifo+[http://libguestfs.org/guestfs.3.html#guestfs_mkfifo]).
 */
static VALUE
ruby_guestfs_mkfifo (VALUE gv, VALUE modev, VALUE pathv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "mkfifo");

  int mode = NUM2INT (modev);
  const char *path = StringValueCStr (pathv);

  int r;

  r = guestfs_mkfifo (g, mode, path);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.mknod_b(mode, devmajor, devminor, path) -> nil
 *
 * make block device node
 *
 * This call creates a block device node called "path" with
 * mode "mode" and device major/minor "devmajor" and
 * "devminor". It is just a convenient wrapper around
 * "g.mknod".
 * 
 * The mode actually set is affected by the umask.
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_mknod_b+[http://libguestfs.org/guestfs.3.html#guestfs_mknod_b]).
 */
static VALUE
ruby_guestfs_mknod_b (VALUE gv, VALUE modev, VALUE devmajorv, VALUE devminorv, VALUE pathv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "mknod_b");

  int mode = NUM2INT (modev);
  int devmajor = NUM2INT (devmajorv);
  int devminor = NUM2INT (devminorv);
  const char *path = StringValueCStr (pathv);

  int r;

  r = guestfs_mknod_b (g, mode, devmajor, devminor, path);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.mknod_c(mode, devmajor, devminor, path) -> nil
 *
 * make char device node
 *
 * This call creates a char device node called "path" with
 * mode "mode" and device major/minor "devmajor" and
 * "devminor". It is just a convenient wrapper around
 * "g.mknod".
 * 
 * The mode actually set is affected by the umask.
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_mknod_c+[http://libguestfs.org/guestfs.3.html#guestfs_mknod_c]).
 */
static VALUE
ruby_guestfs_mknod_c (VALUE gv, VALUE modev, VALUE devmajorv, VALUE devminorv, VALUE pathv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "mknod_c");

  int mode = NUM2INT (modev);
  int devmajor = NUM2INT (devmajorv);
  int devminor = NUM2INT (devminorv);
  const char *path = StringValueCStr (pathv);

  int r;

  r = guestfs_mknod_c (g, mode, devmajor, devminor, path);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.umask(mask) -> fixnum
 *
 * set file mode creation mask (umask)
 *
 * This function sets the mask used for creating new files
 * and device nodes to "mask & 0777".
 * 
 * Typical umask values would be 022 which creates new
 * files with permissions like "-rw-r--r--" or
 * "-rwxr-xr-x", and 002 which creates new files with
 * permissions like "-rw-rw-r--" or "-rwxrwxr-x".
 * 
 * The default umask is 022. This is important because it
 * means that directories and device nodes will be created
 * with 0644 or 0755 mode even if you specify 0777.
 * 
 * See also "g.get_umask", umask(2), "g.mknod", "g.mkdir".
 * 
 * This call returns the previous umask.
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_umask+[http://libguestfs.org/guestfs.3.html#guestfs_umask]).
 */
static VALUE
ruby_guestfs_umask (VALUE gv, VALUE maskv)
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

/*
 * call-seq:
 *   g.readdir(dir) -> list
 *
 * read directories entries
 *
 * This returns the list of directory entries in directory
 * "dir".
 * 
 * All entries in the directory are returned, including "."
 * and "..". The entries are *not* sorted, but returned in
 * the same order as the underlying filesystem.
 * 
 * Also this call returns basic file type information about
 * each file. The "ftyp" field will contain one of the
 * following characters:
 * 
 * 'b' Block special
 * 
 * 'c' Char special
 * 
 * 'd' Directory
 * 
 * 'f' FIFO (named pipe)
 * 
 * 'l' Symbolic link
 * 
 * 'r' Regular file
 * 
 * 's' Socket
 * 
 * 'u' Unknown file type
 * 
 * '?' The readdir(3) call returned a "d_type" field with
 * an unexpected value
 * 
 * This function is primarily intended for use by programs.
 * To get a simple list of names, use "g.ls". To get a
 * printable directory for human consumption, use "g.ll".
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_readdir+[http://libguestfs.org/guestfs.3.html#guestfs_readdir]).
 */
static VALUE
ruby_guestfs_readdir (VALUE gv, VALUE dirv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "readdir");

  const char *dir = StringValueCStr (dirv);

  struct guestfs_dirent_list *r;

  r = guestfs_readdir (g, dir);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  VALUE rv = rb_ary_new2 (r->len);
  size_t i;
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

/*
 * call-seq:
 *   g.sfdiskM(device, lines) -> nil
 *
 * create partitions on a block device
 *
 * This is a simplified interface to the "g.sfdisk"
 * command, where partition sizes are specified in
 * megabytes only (rounded to the nearest cylinder) and you
 * don't need to specify the cyls, heads and sectors
 * parameters which were rarely if ever used anyway.
 * 
 * See also: "g.sfdisk", the sfdisk(8) manpage and
 * "g.part_disk"
 * 
 * *This function is deprecated.* In new code, use the
 * "part_add" call instead.
 * 
 * Deprecated functions will not be removed from the API,
 * but the fact that they are deprecated indicates that
 * there are problems with correct use of these functions.
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_sfdiskM+[http://libguestfs.org/guestfs.3.html#guestfs_sfdiskM]).
 */
static VALUE
ruby_guestfs_sfdiskM (VALUE gv, VALUE devicev, VALUE linesv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "sfdiskM");

  const char *device = StringValueCStr (devicev);
  char **lines;
  Check_Type (linesv, T_ARRAY);
  {
    size_t i, len;
    len = RARRAY_LEN (linesv);
    lines = ALLOC_N (char *, len+1);
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

/*
 * call-seq:
 *   g.zfile(meth, path) -> string
 *
 * determine file type inside a compressed file
 *
 * This command runs "file" after first decompressing
 * "path" using "method".
 * 
 * "method" must be one of "gzip", "compress" or "bzip2".
 * 
 * Since 1.0.63, use "g.file" instead which can now process
 * compressed files.
 * 
 * *This function is deprecated.* In new code, use the
 * "file" call instead.
 * 
 * Deprecated functions will not be removed from the API,
 * but the fact that they are deprecated indicates that
 * there are problems with correct use of these functions.
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_zfile+[http://libguestfs.org/guestfs.3.html#guestfs_zfile]).
 */
static VALUE
ruby_guestfs_zfile (VALUE gv, VALUE methv, VALUE pathv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "zfile");

  const char *meth = StringValueCStr (methv);
  const char *path = StringValueCStr (pathv);

  char *r;

  r = guestfs_zfile (g, meth, path);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  VALUE rv = rb_str_new2 (r);
  free (r);
  return rv;
}

/*
 * call-seq:
 *   g.getxattrs(path) -> list
 *
 * list extended attributes of a file or directory
 *
 * This call lists the extended attributes of the file or
 * directory "path".
 * 
 * At the system call level, this is a combination of the
 * listxattr(2) and getxattr(2) calls.
 * 
 * See also: "g.lgetxattrs", attr(5).
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_getxattrs+[http://libguestfs.org/guestfs.3.html#guestfs_getxattrs]).
 */
static VALUE
ruby_guestfs_getxattrs (VALUE gv, VALUE pathv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "getxattrs");

  const char *path = StringValueCStr (pathv);

  struct guestfs_xattr_list *r;

  r = guestfs_getxattrs (g, path);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  VALUE rv = rb_ary_new2 (r->len);
  size_t i;
  for (i = 0; i < r->len; ++i) {
    VALUE hv = rb_hash_new ();
    rb_hash_aset (hv, rb_str_new2 ("attrname"), rb_str_new2 (r->val[i].attrname));
    rb_hash_aset (hv, rb_str_new2 ("attrval"), rb_str_new (r->val[i].attrval, r->val[i].attrval_len));
    rb_ary_push (rv, hv);
  }
  guestfs_free_xattr_list (r);
  return rv;
}

/*
 * call-seq:
 *   g.lgetxattrs(path) -> list
 *
 * list extended attributes of a file or directory
 *
 * This is the same as "g.getxattrs", but if "path" is a
 * symbolic link, then it returns the extended attributes
 * of the link itself.
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_lgetxattrs+[http://libguestfs.org/guestfs.3.html#guestfs_lgetxattrs]).
 */
static VALUE
ruby_guestfs_lgetxattrs (VALUE gv, VALUE pathv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "lgetxattrs");

  const char *path = StringValueCStr (pathv);

  struct guestfs_xattr_list *r;

  r = guestfs_lgetxattrs (g, path);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  VALUE rv = rb_ary_new2 (r->len);
  size_t i;
  for (i = 0; i < r->len; ++i) {
    VALUE hv = rb_hash_new ();
    rb_hash_aset (hv, rb_str_new2 ("attrname"), rb_str_new2 (r->val[i].attrname));
    rb_hash_aset (hv, rb_str_new2 ("attrval"), rb_str_new (r->val[i].attrval, r->val[i].attrval_len));
    rb_ary_push (rv, hv);
  }
  guestfs_free_xattr_list (r);
  return rv;
}

/*
 * call-seq:
 *   g.setxattr(xattr, val, vallen, path) -> nil
 *
 * set extended attribute of a file or directory
 *
 * This call sets the extended attribute named "xattr" of
 * the file "path" to the value "val" (of length "vallen").
 * The value is arbitrary 8 bit data.
 * 
 * See also: "g.lsetxattr", attr(5).
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_setxattr+[http://libguestfs.org/guestfs.3.html#guestfs_setxattr]).
 */
static VALUE
ruby_guestfs_setxattr (VALUE gv, VALUE xattrv, VALUE valv, VALUE vallenv, VALUE pathv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "setxattr");

  const char *xattr = StringValueCStr (xattrv);
  const char *val = StringValueCStr (valv);
  int vallen = NUM2INT (vallenv);
  const char *path = StringValueCStr (pathv);

  int r;

  r = guestfs_setxattr (g, xattr, val, vallen, path);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.lsetxattr(xattr, val, vallen, path) -> nil
 *
 * set extended attribute of a file or directory
 *
 * This is the same as "g.setxattr", but if "path" is a
 * symbolic link, then it sets an extended attribute of the
 * link itself.
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_lsetxattr+[http://libguestfs.org/guestfs.3.html#guestfs_lsetxattr]).
 */
static VALUE
ruby_guestfs_lsetxattr (VALUE gv, VALUE xattrv, VALUE valv, VALUE vallenv, VALUE pathv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "lsetxattr");

  const char *xattr = StringValueCStr (xattrv);
  const char *val = StringValueCStr (valv);
  int vallen = NUM2INT (vallenv);
  const char *path = StringValueCStr (pathv);

  int r;

  r = guestfs_lsetxattr (g, xattr, val, vallen, path);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.removexattr(xattr, path) -> nil
 *
 * remove extended attribute of a file or directory
 *
 * This call removes the extended attribute named "xattr"
 * of the file "path".
 * 
 * See also: "g.lremovexattr", attr(5).
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_removexattr+[http://libguestfs.org/guestfs.3.html#guestfs_removexattr]).
 */
static VALUE
ruby_guestfs_removexattr (VALUE gv, VALUE xattrv, VALUE pathv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "removexattr");

  const char *xattr = StringValueCStr (xattrv);
  const char *path = StringValueCStr (pathv);

  int r;

  r = guestfs_removexattr (g, xattr, path);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.lremovexattr(xattr, path) -> nil
 *
 * remove extended attribute of a file or directory
 *
 * This is the same as "g.removexattr", but if "path" is a
 * symbolic link, then it removes an extended attribute of
 * the link itself.
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_lremovexattr+[http://libguestfs.org/guestfs.3.html#guestfs_lremovexattr]).
 */
static VALUE
ruby_guestfs_lremovexattr (VALUE gv, VALUE xattrv, VALUE pathv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "lremovexattr");

  const char *xattr = StringValueCStr (xattrv);
  const char *path = StringValueCStr (pathv);

  int r;

  r = guestfs_lremovexattr (g, xattr, path);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.mountpoints() -> hash
 *
 * show mountpoints
 *
 * This call is similar to "g.mounts". That call returns a
 * list of devices. This one returns a hash table (map) of
 * device name to directory where the device is mounted.
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_mountpoints+[http://libguestfs.org/guestfs.3.html#guestfs_mountpoints]).
 */
static VALUE
ruby_guestfs_mountpoints (VALUE gv)
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
  size_t i;
  for (i = 0; r[i] != NULL; i+=2) {
    rb_hash_aset (rv, rb_str_new2 (r[i]), rb_str_new2 (r[i+1]));
    free (r[i]);
    free (r[i+1]);
  }
  free (r);
  return rv;
}

/*
 * call-seq:
 *   g.mkmountpoint(exemptpath) -> nil
 *
 * create a mountpoint
 *
 * "g.mkmountpoint" and "g.rmmountpoint" are specialized
 * calls that can be used to create extra mountpoints
 * before mounting the first filesystem.
 * 
 * These calls are *only* necessary in some very limited
 * circumstances, mainly the case where you want to mount a
 * mix of unrelated and/or read-only filesystems together.
 * 
 * For example, live CDs often contain a "Russian doll"
 * nest of filesystems, an ISO outer layer, with a squashfs
 * image inside, with an ext2/3 image inside that. You can
 * unpack this as follows in guestfish:
 * 
 * add-ro Fedora-11-i686-Live.iso
 * run
 * mkmountpoint /cd
 * mkmountpoint /sqsh
 * mkmountpoint /ext3fs
 * mount /dev/sda /cd
 * mount-loop /cd/LiveOS/squashfs.img /sqsh
 * mount-loop /sqsh/LiveOS/ext3fs.img /ext3fs
 * 
 * The inner filesystem is now unpacked under the /ext3fs
 * mountpoint.
 * 
 * "g.mkmountpoint" is not compatible with "g.umount_all".
 * You may get unexpected errors if you try to mix these
 * calls. It is safest to manually unmount filesystems and
 * remove mountpoints after use.
 * 
 * "g.umount_all" unmounts filesystems by sorting the paths
 * longest first, so for this to work for manual
 * mountpoints, you must ensure that the innermost
 * mountpoints have the longest pathnames, as in the
 * example code above.
 * 
 * For more details see
 * <https://bugzilla.redhat.com/show_bug.cgi?id=599503>
 * 
 * Autosync [see "g.set_autosync", this is set by default
 * on handles] can cause "g.umount_all" to be called when
 * the handle is closed which can also trigger these
 * issues.
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_mkmountpoint+[http://libguestfs.org/guestfs.3.html#guestfs_mkmountpoint]).
 */
static VALUE
ruby_guestfs_mkmountpoint (VALUE gv, VALUE exemptpathv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "mkmountpoint");

  const char *exemptpath = StringValueCStr (exemptpathv);

  int r;

  r = guestfs_mkmountpoint (g, exemptpath);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.rmmountpoint(exemptpath) -> nil
 *
 * remove a mountpoint
 *
 * This calls removes a mountpoint that was previously
 * created with "g.mkmountpoint". See "g.mkmountpoint" for
 * full details.
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_rmmountpoint+[http://libguestfs.org/guestfs.3.html#guestfs_rmmountpoint]).
 */
static VALUE
ruby_guestfs_rmmountpoint (VALUE gv, VALUE exemptpathv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "rmmountpoint");

  const char *exemptpath = StringValueCStr (exemptpathv);

  int r;

  r = guestfs_rmmountpoint (g, exemptpath);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.read_file(path) -> string
 *
 * read a file
 *
 * This calls returns the contents of the file "path" as a
 * buffer.
 * 
 * Unlike "g.cat", this function can correctly handle files
 * that contain embedded ASCII NUL characters. However
 * unlike "g.download", this function is limited in the
 * total size of file that can be handled.
 * 
 * Because of the message protocol, there is a transfer
 * limit of somewhere between 2MB and 4MB. See "PROTOCOL
 * LIMITS" in guestfs(3).
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_read_file+[http://libguestfs.org/guestfs.3.html#guestfs_read_file]).
 */
static VALUE
ruby_guestfs_read_file (VALUE gv, VALUE pathv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "read_file");

  const char *path = StringValueCStr (pathv);

  char *r;
  size_t size;

  r = guestfs_read_file (g, path, &size);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  VALUE rv = rb_str_new (r, size);
  free (r);
  return rv;
}

/*
 * call-seq:
 *   g.grep(regex, path) -> list
 *
 * return lines matching a pattern
 *
 * This calls the external "grep" program and returns the
 * matching lines.
 * 
 * Because of the message protocol, there is a transfer
 * limit of somewhere between 2MB and 4MB. See "PROTOCOL
 * LIMITS" in guestfs(3).
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_grep+[http://libguestfs.org/guestfs.3.html#guestfs_grep]).
 */
static VALUE
ruby_guestfs_grep (VALUE gv, VALUE regexv, VALUE pathv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "grep");

  const char *regex = StringValueCStr (regexv);
  const char *path = StringValueCStr (pathv);

  char **r;

  r = guestfs_grep (g, regex, path);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  size_t i, len = 0;
  for (i = 0; r[i] != NULL; ++i) len++;
  VALUE rv = rb_ary_new2 (len);
  for (i = 0; r[i] != NULL; ++i) {
    rb_ary_push (rv, rb_str_new2 (r[i]));
    free (r[i]);
  }
  free (r);
  return rv;
}

/*
 * call-seq:
 *   g.egrep(regex, path) -> list
 *
 * return lines matching a pattern
 *
 * This calls the external "egrep" program and returns the
 * matching lines.
 * 
 * Because of the message protocol, there is a transfer
 * limit of somewhere between 2MB and 4MB. See "PROTOCOL
 * LIMITS" in guestfs(3).
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_egrep+[http://libguestfs.org/guestfs.3.html#guestfs_egrep]).
 */
static VALUE
ruby_guestfs_egrep (VALUE gv, VALUE regexv, VALUE pathv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "egrep");

  const char *regex = StringValueCStr (regexv);
  const char *path = StringValueCStr (pathv);

  char **r;

  r = guestfs_egrep (g, regex, path);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  size_t i, len = 0;
  for (i = 0; r[i] != NULL; ++i) len++;
  VALUE rv = rb_ary_new2 (len);
  for (i = 0; r[i] != NULL; ++i) {
    rb_ary_push (rv, rb_str_new2 (r[i]));
    free (r[i]);
  }
  free (r);
  return rv;
}

/*
 * call-seq:
 *   g.fgrep(pattern, path) -> list
 *
 * return lines matching a pattern
 *
 * This calls the external "fgrep" program and returns the
 * matching lines.
 * 
 * Because of the message protocol, there is a transfer
 * limit of somewhere between 2MB and 4MB. See "PROTOCOL
 * LIMITS" in guestfs(3).
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_fgrep+[http://libguestfs.org/guestfs.3.html#guestfs_fgrep]).
 */
static VALUE
ruby_guestfs_fgrep (VALUE gv, VALUE patternv, VALUE pathv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "fgrep");

  const char *pattern = StringValueCStr (patternv);
  const char *path = StringValueCStr (pathv);

  char **r;

  r = guestfs_fgrep (g, pattern, path);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  size_t i, len = 0;
  for (i = 0; r[i] != NULL; ++i) len++;
  VALUE rv = rb_ary_new2 (len);
  for (i = 0; r[i] != NULL; ++i) {
    rb_ary_push (rv, rb_str_new2 (r[i]));
    free (r[i]);
  }
  free (r);
  return rv;
}

/*
 * call-seq:
 *   g.grepi(regex, path) -> list
 *
 * return lines matching a pattern
 *
 * This calls the external "grep -i" program and returns
 * the matching lines.
 * 
 * Because of the message protocol, there is a transfer
 * limit of somewhere between 2MB and 4MB. See "PROTOCOL
 * LIMITS" in guestfs(3).
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_grepi+[http://libguestfs.org/guestfs.3.html#guestfs_grepi]).
 */
static VALUE
ruby_guestfs_grepi (VALUE gv, VALUE regexv, VALUE pathv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "grepi");

  const char *regex = StringValueCStr (regexv);
  const char *path = StringValueCStr (pathv);

  char **r;

  r = guestfs_grepi (g, regex, path);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  size_t i, len = 0;
  for (i = 0; r[i] != NULL; ++i) len++;
  VALUE rv = rb_ary_new2 (len);
  for (i = 0; r[i] != NULL; ++i) {
    rb_ary_push (rv, rb_str_new2 (r[i]));
    free (r[i]);
  }
  free (r);
  return rv;
}

/*
 * call-seq:
 *   g.egrepi(regex, path) -> list
 *
 * return lines matching a pattern
 *
 * This calls the external "egrep -i" program and returns
 * the matching lines.
 * 
 * Because of the message protocol, there is a transfer
 * limit of somewhere between 2MB and 4MB. See "PROTOCOL
 * LIMITS" in guestfs(3).
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_egrepi+[http://libguestfs.org/guestfs.3.html#guestfs_egrepi]).
 */
static VALUE
ruby_guestfs_egrepi (VALUE gv, VALUE regexv, VALUE pathv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "egrepi");

  const char *regex = StringValueCStr (regexv);
  const char *path = StringValueCStr (pathv);

  char **r;

  r = guestfs_egrepi (g, regex, path);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  size_t i, len = 0;
  for (i = 0; r[i] != NULL; ++i) len++;
  VALUE rv = rb_ary_new2 (len);
  for (i = 0; r[i] != NULL; ++i) {
    rb_ary_push (rv, rb_str_new2 (r[i]));
    free (r[i]);
  }
  free (r);
  return rv;
}

/*
 * call-seq:
 *   g.fgrepi(pattern, path) -> list
 *
 * return lines matching a pattern
 *
 * This calls the external "fgrep -i" program and returns
 * the matching lines.
 * 
 * Because of the message protocol, there is a transfer
 * limit of somewhere between 2MB and 4MB. See "PROTOCOL
 * LIMITS" in guestfs(3).
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_fgrepi+[http://libguestfs.org/guestfs.3.html#guestfs_fgrepi]).
 */
static VALUE
ruby_guestfs_fgrepi (VALUE gv, VALUE patternv, VALUE pathv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "fgrepi");

  const char *pattern = StringValueCStr (patternv);
  const char *path = StringValueCStr (pathv);

  char **r;

  r = guestfs_fgrepi (g, pattern, path);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  size_t i, len = 0;
  for (i = 0; r[i] != NULL; ++i) len++;
  VALUE rv = rb_ary_new2 (len);
  for (i = 0; r[i] != NULL; ++i) {
    rb_ary_push (rv, rb_str_new2 (r[i]));
    free (r[i]);
  }
  free (r);
  return rv;
}

/*
 * call-seq:
 *   g.zgrep(regex, path) -> list
 *
 * return lines matching a pattern
 *
 * This calls the external "zgrep" program and returns the
 * matching lines.
 * 
 * Because of the message protocol, there is a transfer
 * limit of somewhere between 2MB and 4MB. See "PROTOCOL
 * LIMITS" in guestfs(3).
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_zgrep+[http://libguestfs.org/guestfs.3.html#guestfs_zgrep]).
 */
static VALUE
ruby_guestfs_zgrep (VALUE gv, VALUE regexv, VALUE pathv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "zgrep");

  const char *regex = StringValueCStr (regexv);
  const char *path = StringValueCStr (pathv);

  char **r;

  r = guestfs_zgrep (g, regex, path);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  size_t i, len = 0;
  for (i = 0; r[i] != NULL; ++i) len++;
  VALUE rv = rb_ary_new2 (len);
  for (i = 0; r[i] != NULL; ++i) {
    rb_ary_push (rv, rb_str_new2 (r[i]));
    free (r[i]);
  }
  free (r);
  return rv;
}

/*
 * call-seq:
 *   g.zegrep(regex, path) -> list
 *
 * return lines matching a pattern
 *
 * This calls the external "zegrep" program and returns the
 * matching lines.
 * 
 * Because of the message protocol, there is a transfer
 * limit of somewhere between 2MB and 4MB. See "PROTOCOL
 * LIMITS" in guestfs(3).
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_zegrep+[http://libguestfs.org/guestfs.3.html#guestfs_zegrep]).
 */
static VALUE
ruby_guestfs_zegrep (VALUE gv, VALUE regexv, VALUE pathv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "zegrep");

  const char *regex = StringValueCStr (regexv);
  const char *path = StringValueCStr (pathv);

  char **r;

  r = guestfs_zegrep (g, regex, path);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  size_t i, len = 0;
  for (i = 0; r[i] != NULL; ++i) len++;
  VALUE rv = rb_ary_new2 (len);
  for (i = 0; r[i] != NULL; ++i) {
    rb_ary_push (rv, rb_str_new2 (r[i]));
    free (r[i]);
  }
  free (r);
  return rv;
}

/*
 * call-seq:
 *   g.zfgrep(pattern, path) -> list
 *
 * return lines matching a pattern
 *
 * This calls the external "zfgrep" program and returns the
 * matching lines.
 * 
 * Because of the message protocol, there is a transfer
 * limit of somewhere between 2MB and 4MB. See "PROTOCOL
 * LIMITS" in guestfs(3).
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_zfgrep+[http://libguestfs.org/guestfs.3.html#guestfs_zfgrep]).
 */
static VALUE
ruby_guestfs_zfgrep (VALUE gv, VALUE patternv, VALUE pathv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "zfgrep");

  const char *pattern = StringValueCStr (patternv);
  const char *path = StringValueCStr (pathv);

  char **r;

  r = guestfs_zfgrep (g, pattern, path);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  size_t i, len = 0;
  for (i = 0; r[i] != NULL; ++i) len++;
  VALUE rv = rb_ary_new2 (len);
  for (i = 0; r[i] != NULL; ++i) {
    rb_ary_push (rv, rb_str_new2 (r[i]));
    free (r[i]);
  }
  free (r);
  return rv;
}

/*
 * call-seq:
 *   g.zgrepi(regex, path) -> list
 *
 * return lines matching a pattern
 *
 * This calls the external "zgrep -i" program and returns
 * the matching lines.
 * 
 * Because of the message protocol, there is a transfer
 * limit of somewhere between 2MB and 4MB. See "PROTOCOL
 * LIMITS" in guestfs(3).
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_zgrepi+[http://libguestfs.org/guestfs.3.html#guestfs_zgrepi]).
 */
static VALUE
ruby_guestfs_zgrepi (VALUE gv, VALUE regexv, VALUE pathv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "zgrepi");

  const char *regex = StringValueCStr (regexv);
  const char *path = StringValueCStr (pathv);

  char **r;

  r = guestfs_zgrepi (g, regex, path);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  size_t i, len = 0;
  for (i = 0; r[i] != NULL; ++i) len++;
  VALUE rv = rb_ary_new2 (len);
  for (i = 0; r[i] != NULL; ++i) {
    rb_ary_push (rv, rb_str_new2 (r[i]));
    free (r[i]);
  }
  free (r);
  return rv;
}

/*
 * call-seq:
 *   g.zegrepi(regex, path) -> list
 *
 * return lines matching a pattern
 *
 * This calls the external "zegrep -i" program and returns
 * the matching lines.
 * 
 * Because of the message protocol, there is a transfer
 * limit of somewhere between 2MB and 4MB. See "PROTOCOL
 * LIMITS" in guestfs(3).
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_zegrepi+[http://libguestfs.org/guestfs.3.html#guestfs_zegrepi]).
 */
static VALUE
ruby_guestfs_zegrepi (VALUE gv, VALUE regexv, VALUE pathv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "zegrepi");

  const char *regex = StringValueCStr (regexv);
  const char *path = StringValueCStr (pathv);

  char **r;

  r = guestfs_zegrepi (g, regex, path);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  size_t i, len = 0;
  for (i = 0; r[i] != NULL; ++i) len++;
  VALUE rv = rb_ary_new2 (len);
  for (i = 0; r[i] != NULL; ++i) {
    rb_ary_push (rv, rb_str_new2 (r[i]));
    free (r[i]);
  }
  free (r);
  return rv;
}

/*
 * call-seq:
 *   g.zfgrepi(pattern, path) -> list
 *
 * return lines matching a pattern
 *
 * This calls the external "zfgrep -i" program and returns
 * the matching lines.
 * 
 * Because of the message protocol, there is a transfer
 * limit of somewhere between 2MB and 4MB. See "PROTOCOL
 * LIMITS" in guestfs(3).
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_zfgrepi+[http://libguestfs.org/guestfs.3.html#guestfs_zfgrepi]).
 */
static VALUE
ruby_guestfs_zfgrepi (VALUE gv, VALUE patternv, VALUE pathv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "zfgrepi");

  const char *pattern = StringValueCStr (patternv);
  const char *path = StringValueCStr (pathv);

  char **r;

  r = guestfs_zfgrepi (g, pattern, path);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  size_t i, len = 0;
  for (i = 0; r[i] != NULL; ++i) len++;
  VALUE rv = rb_ary_new2 (len);
  for (i = 0; r[i] != NULL; ++i) {
    rb_ary_push (rv, rb_str_new2 (r[i]));
    free (r[i]);
  }
  free (r);
  return rv;
}

/*
 * call-seq:
 *   g.realpath(path) -> string
 *
 * canonicalized absolute pathname
 *
 * Return the canonicalized absolute pathname of "path".
 * The returned path has no ".", ".." or symbolic link path
 * elements.
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_realpath+[http://libguestfs.org/guestfs.3.html#guestfs_realpath]).
 */
static VALUE
ruby_guestfs_realpath (VALUE gv, VALUE pathv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "realpath");

  const char *path = StringValueCStr (pathv);

  char *r;

  r = guestfs_realpath (g, path);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  VALUE rv = rb_str_new2 (r);
  free (r);
  return rv;
}

/*
 * call-seq:
 *   g.ln(target, linkname) -> nil
 *
 * create a hard link
 *
 * This command creates a hard link using the "ln" command.
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_ln+[http://libguestfs.org/guestfs.3.html#guestfs_ln]).
 */
static VALUE
ruby_guestfs_ln (VALUE gv, VALUE targetv, VALUE linknamev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "ln");

  const char *target = StringValueCStr (targetv);
  const char *linkname = StringValueCStr (linknamev);

  int r;

  r = guestfs_ln (g, target, linkname);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.ln_f(target, linkname) -> nil
 *
 * create a hard link
 *
 * This command creates a hard link using the "ln -f"
 * command. The *-f* option removes the link ("linkname")
 * if it exists already.
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_ln_f+[http://libguestfs.org/guestfs.3.html#guestfs_ln_f]).
 */
static VALUE
ruby_guestfs_ln_f (VALUE gv, VALUE targetv, VALUE linknamev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "ln_f");

  const char *target = StringValueCStr (targetv);
  const char *linkname = StringValueCStr (linknamev);

  int r;

  r = guestfs_ln_f (g, target, linkname);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.ln_s(target, linkname) -> nil
 *
 * create a symbolic link
 *
 * This command creates a symbolic link using the "ln -s"
 * command.
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_ln_s+[http://libguestfs.org/guestfs.3.html#guestfs_ln_s]).
 */
static VALUE
ruby_guestfs_ln_s (VALUE gv, VALUE targetv, VALUE linknamev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "ln_s");

  const char *target = StringValueCStr (targetv);
  const char *linkname = StringValueCStr (linknamev);

  int r;

  r = guestfs_ln_s (g, target, linkname);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.ln_sf(target, linkname) -> nil
 *
 * create a symbolic link
 *
 * This command creates a symbolic link using the "ln -sf"
 * command, The *-f* option removes the link ("linkname")
 * if it exists already.
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_ln_sf+[http://libguestfs.org/guestfs.3.html#guestfs_ln_sf]).
 */
static VALUE
ruby_guestfs_ln_sf (VALUE gv, VALUE targetv, VALUE linknamev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "ln_sf");

  const char *target = StringValueCStr (targetv);
  const char *linkname = StringValueCStr (linknamev);

  int r;

  r = guestfs_ln_sf (g, target, linkname);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.readlink(path) -> string
 *
 * read the target of a symbolic link
 *
 * This command reads the target of a symbolic link.
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_readlink+[http://libguestfs.org/guestfs.3.html#guestfs_readlink]).
 */
static VALUE
ruby_guestfs_readlink (VALUE gv, VALUE pathv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "readlink");

  const char *path = StringValueCStr (pathv);

  char *r;

  r = guestfs_readlink (g, path);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  VALUE rv = rb_str_new2 (r);
  free (r);
  return rv;
}

/*
 * call-seq:
 *   g.fallocate(path, len) -> nil
 *
 * preallocate a file in the guest filesystem
 *
 * This command preallocates a file (containing zero bytes)
 * named "path" of size "len" bytes. If the file exists
 * already, it is overwritten.
 * 
 * Do not confuse this with the guestfish-specific "alloc"
 * command which allocates a file in the host and attaches
 * it as a device.
 * 
 * *This function is deprecated.* In new code, use the
 * "fallocate64" call instead.
 * 
 * Deprecated functions will not be removed from the API,
 * but the fact that they are deprecated indicates that
 * there are problems with correct use of these functions.
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_fallocate+[http://libguestfs.org/guestfs.3.html#guestfs_fallocate]).
 */
static VALUE
ruby_guestfs_fallocate (VALUE gv, VALUE pathv, VALUE lenv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "fallocate");

  const char *path = StringValueCStr (pathv);
  int len = NUM2INT (lenv);

  int r;

  r = guestfs_fallocate (g, path, len);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.swapon_device(device) -> nil
 *
 * enable swap on device
 *
 * This command enables the libguestfs appliance to use the
 * swap device or partition named "device". The increased
 * memory is made available for all commands, for example
 * those run using "g.command" or "g.sh".
 * 
 * Note that you should not swap to existing guest swap
 * partitions unless you know what you are doing. They may
 * contain hibernation information, or other information
 * that the guest doesn't want you to trash. You also risk
 * leaking information about the host to the guest this
 * way. Instead, attach a new host device to the guest and
 * swap on that.
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_swapon_device+[http://libguestfs.org/guestfs.3.html#guestfs_swapon_device]).
 */
static VALUE
ruby_guestfs_swapon_device (VALUE gv, VALUE devicev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "swapon_device");

  const char *device = StringValueCStr (devicev);

  int r;

  r = guestfs_swapon_device (g, device);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.swapoff_device(device) -> nil
 *
 * disable swap on device
 *
 * This command disables the libguestfs appliance swap
 * device or partition named "device". See
 * "g.swapon_device".
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_swapoff_device+[http://libguestfs.org/guestfs.3.html#guestfs_swapoff_device]).
 */
static VALUE
ruby_guestfs_swapoff_device (VALUE gv, VALUE devicev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "swapoff_device");

  const char *device = StringValueCStr (devicev);

  int r;

  r = guestfs_swapoff_device (g, device);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.swapon_file(file) -> nil
 *
 * enable swap on file
 *
 * This command enables swap to a file. See
 * "g.swapon_device" for other notes.
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_swapon_file+[http://libguestfs.org/guestfs.3.html#guestfs_swapon_file]).
 */
static VALUE
ruby_guestfs_swapon_file (VALUE gv, VALUE filev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "swapon_file");

  const char *file = StringValueCStr (filev);

  int r;

  r = guestfs_swapon_file (g, file);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.swapoff_file(file) -> nil
 *
 * disable swap on file
 *
 * This command disables the libguestfs appliance swap on
 * file.
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_swapoff_file+[http://libguestfs.org/guestfs.3.html#guestfs_swapoff_file]).
 */
static VALUE
ruby_guestfs_swapoff_file (VALUE gv, VALUE filev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "swapoff_file");

  const char *file = StringValueCStr (filev);

  int r;

  r = guestfs_swapoff_file (g, file);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.swapon_label(label) -> nil
 *
 * enable swap on labeled swap partition
 *
 * This command enables swap to a labeled swap partition.
 * See "g.swapon_device" for other notes.
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_swapon_label+[http://libguestfs.org/guestfs.3.html#guestfs_swapon_label]).
 */
static VALUE
ruby_guestfs_swapon_label (VALUE gv, VALUE labelv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "swapon_label");

  const char *label = StringValueCStr (labelv);

  int r;

  r = guestfs_swapon_label (g, label);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.swapoff_label(label) -> nil
 *
 * disable swap on labeled swap partition
 *
 * This command disables the libguestfs appliance swap on
 * labeled swap partition.
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_swapoff_label+[http://libguestfs.org/guestfs.3.html#guestfs_swapoff_label]).
 */
static VALUE
ruby_guestfs_swapoff_label (VALUE gv, VALUE labelv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "swapoff_label");

  const char *label = StringValueCStr (labelv);

  int r;

  r = guestfs_swapoff_label (g, label);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.swapon_uuid(uuid) -> nil
 *
 * enable swap on swap partition by UUID
 *
 * This command enables swap to a swap partition with the
 * given UUID. See "g.swapon_device" for other notes.
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_swapon_uuid+[http://libguestfs.org/guestfs.3.html#guestfs_swapon_uuid]).
 */
static VALUE
ruby_guestfs_swapon_uuid (VALUE gv, VALUE uuidv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "swapon_uuid");

  const char *uuid = StringValueCStr (uuidv);

  int r;

  r = guestfs_swapon_uuid (g, uuid);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.swapoff_uuid(uuid) -> nil
 *
 * disable swap on swap partition by UUID
 *
 * This command disables the libguestfs appliance swap
 * partition with the given UUID.
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_swapoff_uuid+[http://libguestfs.org/guestfs.3.html#guestfs_swapoff_uuid]).
 */
static VALUE
ruby_guestfs_swapoff_uuid (VALUE gv, VALUE uuidv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "swapoff_uuid");

  const char *uuid = StringValueCStr (uuidv);

  int r;

  r = guestfs_swapoff_uuid (g, uuid);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.mkswap_file(path) -> nil
 *
 * create a swap file
 *
 * Create a swap file.
 * 
 * This command just writes a swap file signature to an
 * existing file. To create the file itself, use something
 * like "g.fallocate".
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_mkswap_file+[http://libguestfs.org/guestfs.3.html#guestfs_mkswap_file]).
 */
static VALUE
ruby_guestfs_mkswap_file (VALUE gv, VALUE pathv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "mkswap_file");

  const char *path = StringValueCStr (pathv);

  int r;

  r = guestfs_mkswap_file (g, path);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.inotify_init(maxevents) -> nil
 *
 * create an inotify handle
 *
 * This command creates a new inotify handle. The inotify
 * subsystem can be used to notify events which happen to
 * objects in the guest filesystem.
 * 
 * "maxevents" is the maximum number of events which will
 * be queued up between calls to "g.inotify_read" or
 * "g.inotify_files". If this is passed as 0, then the
 * kernel (or previously set) default is used. For Linux
 * 2.6.29 the default was 16384 events. Beyond this limit,
 * the kernel throws away events, but records the fact that
 * it threw them away by setting a flag "IN_Q_OVERFLOW" in
 * the returned structure list (see "g.inotify_read").
 * 
 * Before any events are generated, you have to add some
 * watches to the internal watch list. See:
 * "g.inotify_add_watch", "g.inotify_rm_watch" and
 * "g.inotify_watch_all".
 * 
 * Queued up events should be read periodically by calling
 * "g.inotify_read" (or "g.inotify_files" which is just a
 * helpful wrapper around "g.inotify_read"). If you don't
 * read the events out often enough then you risk the
 * internal queue overflowing.
 * 
 * The handle should be closed after use by calling
 * "g.inotify_close". This also removes any watches
 * automatically.
 * 
 * See also inotify(7) for an overview of the inotify
 * interface as exposed by the Linux kernel, which is
 * roughly what we expose via libguestfs. Note that there
 * is one global inotify handle per libguestfs instance.
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_inotify_init+[http://libguestfs.org/guestfs.3.html#guestfs_inotify_init]).
 */
static VALUE
ruby_guestfs_inotify_init (VALUE gv, VALUE maxeventsv)
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

/*
 * call-seq:
 *   g.inotify_add_watch(path, mask) -> fixnum
 *
 * add an inotify watch
 *
 * Watch "path" for the events listed in "mask".
 * 
 * Note that if "path" is a directory then events within
 * that directory are watched, but this does *not* happen
 * recursively (in subdirectories).
 * 
 * Note for non-C or non-Linux callers: the inotify events
 * are defined by the Linux kernel ABI and are listed in
 * "/usr/include/sys/inotify.h".
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_inotify_add_watch+[http://libguestfs.org/guestfs.3.html#guestfs_inotify_add_watch]).
 */
static VALUE
ruby_guestfs_inotify_add_watch (VALUE gv, VALUE pathv, VALUE maskv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "inotify_add_watch");

  const char *path = StringValueCStr (pathv);
  int mask = NUM2INT (maskv);

  int64_t r;

  r = guestfs_inotify_add_watch (g, path, mask);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return ULL2NUM (r);
}

/*
 * call-seq:
 *   g.inotify_rm_watch(wd) -> nil
 *
 * remove an inotify watch
 *
 * Remove a previously defined inotify watch. See
 * "g.inotify_add_watch".
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_inotify_rm_watch+[http://libguestfs.org/guestfs.3.html#guestfs_inotify_rm_watch]).
 */
static VALUE
ruby_guestfs_inotify_rm_watch (VALUE gv, VALUE wdv)
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

/*
 * call-seq:
 *   g.inotify_read() -> list
 *
 * return list of inotify events
 *
 * Return the complete queue of events that have happened
 * since the previous read call.
 * 
 * If no events have happened, this returns an empty list.
 * 
 * *Note*: In order to make sure that all events have been
 * read, you must call this function repeatedly until it
 * returns an empty list. The reason is that the call will
 * read events up to the maximum appliance-to-host message
 * size and leave remaining events in the queue.
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_inotify_read+[http://libguestfs.org/guestfs.3.html#guestfs_inotify_read]).
 */
static VALUE
ruby_guestfs_inotify_read (VALUE gv)
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
  size_t i;
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

/*
 * call-seq:
 *   g.inotify_files() -> list
 *
 * return list of watched files that had events
 *
 * This function is a helpful wrapper around
 * "g.inotify_read" which just returns a list of pathnames
 * of objects that were touched. The returned pathnames are
 * sorted and deduplicated.
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_inotify_files+[http://libguestfs.org/guestfs.3.html#guestfs_inotify_files]).
 */
static VALUE
ruby_guestfs_inotify_files (VALUE gv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "inotify_files");


  char **r;

  r = guestfs_inotify_files (g);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  size_t i, len = 0;
  for (i = 0; r[i] != NULL; ++i) len++;
  VALUE rv = rb_ary_new2 (len);
  for (i = 0; r[i] != NULL; ++i) {
    rb_ary_push (rv, rb_str_new2 (r[i]));
    free (r[i]);
  }
  free (r);
  return rv;
}

/*
 * call-seq:
 *   g.inotify_close() -> nil
 *
 * close the inotify handle
 *
 * This closes the inotify handle which was previously
 * opened by inotify_init. It removes all watches, throws
 * away any pending events, and deallocates all resources.
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_inotify_close+[http://libguestfs.org/guestfs.3.html#guestfs_inotify_close]).
 */
static VALUE
ruby_guestfs_inotify_close (VALUE gv)
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

/*
 * call-seq:
 *   g.setcon(context) -> nil
 *
 * set SELinux security context
 *
 * This sets the SELinux security context of the daemon to
 * the string "context".
 * 
 * See the documentation about SELINUX in guestfs(3).
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_setcon+[http://libguestfs.org/guestfs.3.html#guestfs_setcon]).
 */
static VALUE
ruby_guestfs_setcon (VALUE gv, VALUE contextv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "setcon");

  const char *context = StringValueCStr (contextv);

  int r;

  r = guestfs_setcon (g, context);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.getcon() -> string
 *
 * get SELinux security context
 *
 * This gets the SELinux security context of the daemon.
 * 
 * See the documentation about SELINUX in guestfs(3), and
 * "g.setcon"
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_getcon+[http://libguestfs.org/guestfs.3.html#guestfs_getcon]).
 */
static VALUE
ruby_guestfs_getcon (VALUE gv)
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

/*
 * call-seq:
 *   g.mkfs_b(fstype, blocksize, device) -> nil
 *
 * make a filesystem with block size
 *
 * This call is similar to "g.mkfs", but it allows you to
 * control the block size of the resulting filesystem.
 * Supported block sizes depend on the filesystem type, but
 * typically they are 1024, 2048 or 4096 only.
 * 
 * For VFAT and NTFS the "blocksize" parameter is treated
 * as the requested cluster size.
 * 
 * *This function is deprecated.* In new code, use the
 * "mkfs_opts" call instead.
 * 
 * Deprecated functions will not be removed from the API,
 * but the fact that they are deprecated indicates that
 * there are problems with correct use of these functions.
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_mkfs_b+[http://libguestfs.org/guestfs.3.html#guestfs_mkfs_b]).
 */
static VALUE
ruby_guestfs_mkfs_b (VALUE gv, VALUE fstypev, VALUE blocksizev, VALUE devicev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "mkfs_b");

  const char *fstype = StringValueCStr (fstypev);
  int blocksize = NUM2INT (blocksizev);
  const char *device = StringValueCStr (devicev);

  int r;

  r = guestfs_mkfs_b (g, fstype, blocksize, device);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.mke2journal(blocksize, device) -> nil
 *
 * make ext2/3/4 external journal
 *
 * This creates an ext2 external journal on "device". It is
 * equivalent to the command:
 * 
 * mke2fs -O journal_dev -b blocksize device
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_mke2journal+[http://libguestfs.org/guestfs.3.html#guestfs_mke2journal]).
 */
static VALUE
ruby_guestfs_mke2journal (VALUE gv, VALUE blocksizev, VALUE devicev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "mke2journal");

  int blocksize = NUM2INT (blocksizev);
  const char *device = StringValueCStr (devicev);

  int r;

  r = guestfs_mke2journal (g, blocksize, device);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.mke2journal_L(blocksize, label, device) -> nil
 *
 * make ext2/3/4 external journal with label
 *
 * This creates an ext2 external journal on "device" with
 * label "label".
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_mke2journal_L+[http://libguestfs.org/guestfs.3.html#guestfs_mke2journal_L]).
 */
static VALUE
ruby_guestfs_mke2journal_L (VALUE gv, VALUE blocksizev, VALUE labelv, VALUE devicev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "mke2journal_L");

  int blocksize = NUM2INT (blocksizev);
  const char *label = StringValueCStr (labelv);
  const char *device = StringValueCStr (devicev);

  int r;

  r = guestfs_mke2journal_L (g, blocksize, label, device);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.mke2journal_U(blocksize, uuid, device) -> nil
 *
 * make ext2/3/4 external journal with UUID
 *
 * This creates an ext2 external journal on "device" with
 * UUID "uuid".
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_mke2journal_U+[http://libguestfs.org/guestfs.3.html#guestfs_mke2journal_U]).
 */
static VALUE
ruby_guestfs_mke2journal_U (VALUE gv, VALUE blocksizev, VALUE uuidv, VALUE devicev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "mke2journal_U");

  int blocksize = NUM2INT (blocksizev);
  const char *uuid = StringValueCStr (uuidv);
  const char *device = StringValueCStr (devicev);

  int r;

  r = guestfs_mke2journal_U (g, blocksize, uuid, device);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.mke2fs_J(fstype, blocksize, device, journal) -> nil
 *
 * make ext2/3/4 filesystem with external journal
 *
 * This creates an ext2/3/4 filesystem on "device" with an
 * external journal on "journal". It is equivalent to the
 * command:
 * 
 * mke2fs -t fstype -b blocksize -J device=<journal> <device>
 * 
 * See also "g.mke2journal".
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_mke2fs_J+[http://libguestfs.org/guestfs.3.html#guestfs_mke2fs_J]).
 */
static VALUE
ruby_guestfs_mke2fs_J (VALUE gv, VALUE fstypev, VALUE blocksizev, VALUE devicev, VALUE journalv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "mke2fs_J");

  const char *fstype = StringValueCStr (fstypev);
  int blocksize = NUM2INT (blocksizev);
  const char *device = StringValueCStr (devicev);
  const char *journal = StringValueCStr (journalv);

  int r;

  r = guestfs_mke2fs_J (g, fstype, blocksize, device, journal);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.mke2fs_JL(fstype, blocksize, device, label) -> nil
 *
 * make ext2/3/4 filesystem with external journal
 *
 * This creates an ext2/3/4 filesystem on "device" with an
 * external journal on the journal labeled "label".
 * 
 * See also "g.mke2journal_L".
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_mke2fs_JL+[http://libguestfs.org/guestfs.3.html#guestfs_mke2fs_JL]).
 */
static VALUE
ruby_guestfs_mke2fs_JL (VALUE gv, VALUE fstypev, VALUE blocksizev, VALUE devicev, VALUE labelv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "mke2fs_JL");

  const char *fstype = StringValueCStr (fstypev);
  int blocksize = NUM2INT (blocksizev);
  const char *device = StringValueCStr (devicev);
  const char *label = StringValueCStr (labelv);

  int r;

  r = guestfs_mke2fs_JL (g, fstype, blocksize, device, label);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.mke2fs_JU(fstype, blocksize, device, uuid) -> nil
 *
 * make ext2/3/4 filesystem with external journal
 *
 * This creates an ext2/3/4 filesystem on "device" with an
 * external journal on the journal with UUID "uuid".
 * 
 * See also "g.mke2journal_U".
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_mke2fs_JU+[http://libguestfs.org/guestfs.3.html#guestfs_mke2fs_JU]).
 */
static VALUE
ruby_guestfs_mke2fs_JU (VALUE gv, VALUE fstypev, VALUE blocksizev, VALUE devicev, VALUE uuidv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "mke2fs_JU");

  const char *fstype = StringValueCStr (fstypev);
  int blocksize = NUM2INT (blocksizev);
  const char *device = StringValueCStr (devicev);
  const char *uuid = StringValueCStr (uuidv);

  int r;

  r = guestfs_mke2fs_JU (g, fstype, blocksize, device, uuid);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.modprobe(modulename) -> nil
 *
 * load a kernel module
 *
 * This loads a kernel module in the appliance.
 * 
 * The kernel module must have been whitelisted when
 * libguestfs was built (see "appliance/kmod.whitelist.in"
 * in the source).
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_modprobe+[http://libguestfs.org/guestfs.3.html#guestfs_modprobe]).
 */
static VALUE
ruby_guestfs_modprobe (VALUE gv, VALUE modulenamev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "modprobe");

  const char *modulename = StringValueCStr (modulenamev);

  int r;

  r = guestfs_modprobe (g, modulename);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.echo_daemon(words) -> string
 *
 * echo arguments back to the client
 *
 * This command concatenates the list of "words" passed
 * with single spaces between them and returns the
 * resulting string.
 * 
 * You can use this command to test the connection through
 * to the daemon.
 * 
 * See also "g.ping_daemon".
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_echo_daemon+[http://libguestfs.org/guestfs.3.html#guestfs_echo_daemon]).
 */
static VALUE
ruby_guestfs_echo_daemon (VALUE gv, VALUE wordsv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "echo_daemon");

  char **words;
  Check_Type (wordsv, T_ARRAY);
  {
    size_t i, len;
    len = RARRAY_LEN (wordsv);
    words = ALLOC_N (char *, len+1);
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

/*
 * call-seq:
 *   g.find0(directory, files) -> nil
 *
 * find all files and directories, returning NUL-separated list
 *
 * This command lists out all files and directories,
 * recursively, starting at "directory", placing the
 * resulting list in the external file called "files".
 * 
 * This command works the same way as "g.find" with the
 * following exceptions:
 * 
 * *   The resulting list is written to an external file.
 * 
 * *   Items (filenames) in the result are separated by
 * "\0" characters. See find(1) option *-print0*.
 * 
 * *   This command is not limited in the number of names
 * that it can return.
 * 
 * *   The result list is not sorted.
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_find0+[http://libguestfs.org/guestfs.3.html#guestfs_find0]).
 */
static VALUE
ruby_guestfs_find0 (VALUE gv, VALUE directoryv, VALUE filesv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "find0");

  const char *directory = StringValueCStr (directoryv);
  const char *files = StringValueCStr (filesv);

  int r;

  r = guestfs_find0 (g, directory, files);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.case_sensitive_path(path) -> string
 *
 * return true path on case-insensitive filesystem
 *
 * This can be used to resolve case insensitive paths on a
 * filesystem which is case sensitive. The use case is to
 * resolve paths which you have read from Windows
 * configuration files or the Windows Registry, to the true
 * path.
 * 
 * The command handles a peculiarity of the Linux ntfs-3g
 * filesystem driver (and probably others), which is that
 * although the underlying filesystem is case-insensitive,
 * the driver exports the filesystem to Linux as
 * case-sensitive.
 * 
 * One consequence of this is that special directories such
 * as "c:\windows" may appear as "/WINDOWS" or "/windows"
 * (or other things) depending on the precise details of
 * how they were created. In Windows itself this would not
 * be a problem.
 * 
 * Bug or feature? You decide:
 * <http://www.tuxera.com/community/ntfs-3g-faq/#posixfilen
 * ames1>
 * 
 * This function resolves the true case of each element in
 * the path and returns the case-sensitive path.
 * 
 * Thus "g.case_sensitive_path" ("/Windows/System32") might
 * return "/WINDOWS/system32" (the exact return value would
 * depend on details of how the directories were originally
 * created under Windows).
 * 
 * *Note*: This function does not handle drive names,
 * backslashes etc.
 * 
 * See also "g.realpath".
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_case_sensitive_path+[http://libguestfs.org/guestfs.3.html#guestfs_case_sensitive_path]).
 */
static VALUE
ruby_guestfs_case_sensitive_path (VALUE gv, VALUE pathv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "case_sensitive_path");

  const char *path = StringValueCStr (pathv);

  char *r;

  r = guestfs_case_sensitive_path (g, path);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  VALUE rv = rb_str_new2 (r);
  free (r);
  return rv;
}

/*
 * call-seq:
 *   g.vfs_type(device) -> string
 *
 * get the Linux VFS type corresponding to a mounted device
 *
 * This command gets the filesystem type corresponding to
 * the filesystem on "device".
 * 
 * For most filesystems, the result is the name of the
 * Linux VFS module which would be used to mount this
 * filesystem if you mounted it without specifying the
 * filesystem type. For example a string such as "ext3" or
 * "ntfs".
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_vfs_type+[http://libguestfs.org/guestfs.3.html#guestfs_vfs_type]).
 */
static VALUE
ruby_guestfs_vfs_type (VALUE gv, VALUE devicev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "vfs_type");

  const char *device = StringValueCStr (devicev);

  char *r;

  r = guestfs_vfs_type (g, device);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  VALUE rv = rb_str_new2 (r);
  free (r);
  return rv;
}

/*
 * call-seq:
 *   g.truncate(path) -> nil
 *
 * truncate a file to zero size
 *
 * This command truncates "path" to a zero-length file. The
 * file must exist already.
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_truncate+[http://libguestfs.org/guestfs.3.html#guestfs_truncate]).
 */
static VALUE
ruby_guestfs_truncate (VALUE gv, VALUE pathv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "truncate");

  const char *path = StringValueCStr (pathv);

  int r;

  r = guestfs_truncate (g, path);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.truncate_size(path, size) -> nil
 *
 * truncate a file to a particular size
 *
 * This command truncates "path" to size "size" bytes. The
 * file must exist already.
 * 
 * If the current file size is less than "size" then the
 * file is extended to the required size with zero bytes.
 * This creates a sparse file (ie. disk blocks are not
 * allocated for the file until you write to it). To create
 * a non-sparse file of zeroes, use "g.fallocate64"
 * instead.
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_truncate_size+[http://libguestfs.org/guestfs.3.html#guestfs_truncate_size]).
 */
static VALUE
ruby_guestfs_truncate_size (VALUE gv, VALUE pathv, VALUE sizev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "truncate_size");

  const char *path = StringValueCStr (pathv);
  long long size = NUM2LL (sizev);

  int r;

  r = guestfs_truncate_size (g, path, size);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.utimens(path, atsecs, atnsecs, mtsecs, mtnsecs) -> nil
 *
 * set timestamp of a file with nanosecond precision
 *
 * This command sets the timestamps of a file with
 * nanosecond precision.
 * 
 * "atsecs, atnsecs" are the last access time (atime) in
 * secs and nanoseconds from the epoch.
 * 
 * "mtsecs, mtnsecs" are the last modification time (mtime)
 * in secs and nanoseconds from the epoch.
 * 
 * If the *nsecs field contains the special value -1 then
 * the corresponding timestamp is set to the current time.
 * (The *secs field is ignored in this case).
 * 
 * If the *nsecs field contains the special value -2 then
 * the corresponding timestamp is left unchanged. (The
 * *secs field is ignored in this case).
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_utimens+[http://libguestfs.org/guestfs.3.html#guestfs_utimens]).
 */
static VALUE
ruby_guestfs_utimens (VALUE gv, VALUE pathv, VALUE atsecsv, VALUE atnsecsv, VALUE mtsecsv, VALUE mtnsecsv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "utimens");

  const char *path = StringValueCStr (pathv);
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

/*
 * call-seq:
 *   g.mkdir_mode(path, mode) -> nil
 *
 * create a directory with a particular mode
 *
 * This command creates a directory, setting the initial
 * permissions of the directory to "mode".
 * 
 * For common Linux filesystems, the actual mode which is
 * set will be "mode & ~umask & 01777". Non-native-Linux
 * filesystems may interpret the mode in other ways.
 * 
 * See also "g.mkdir", "g.umask"
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_mkdir_mode+[http://libguestfs.org/guestfs.3.html#guestfs_mkdir_mode]).
 */
static VALUE
ruby_guestfs_mkdir_mode (VALUE gv, VALUE pathv, VALUE modev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "mkdir_mode");

  const char *path = StringValueCStr (pathv);
  int mode = NUM2INT (modev);

  int r;

  r = guestfs_mkdir_mode (g, path, mode);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.lchown(owner, group, path) -> nil
 *
 * change file owner and group
 *
 * Change the file owner to "owner" and group to "group".
 * This is like "g.chown" but if "path" is a symlink then
 * the link itself is changed, not the target.
 * 
 * Only numeric uid and gid are supported. If you want to
 * use names, you will need to locate and parse the
 * password file yourself (Augeas support makes this
 * relatively easy).
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_lchown+[http://libguestfs.org/guestfs.3.html#guestfs_lchown]).
 */
static VALUE
ruby_guestfs_lchown (VALUE gv, VALUE ownerv, VALUE groupv, VALUE pathv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "lchown");

  int owner = NUM2INT (ownerv);
  int group = NUM2INT (groupv);
  const char *path = StringValueCStr (pathv);

  int r;

  r = guestfs_lchown (g, owner, group, path);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.lstatlist(path, names) -> list
 *
 * lstat on multiple files
 *
 * This call allows you to perform the "g.lstat" operation
 * on multiple files, where all files are in the directory
 * "path". "names" is the list of files from this
 * directory.
 * 
 * On return you get a list of stat structs, with a
 * one-to-one correspondence to the "names" list. If any
 * name did not exist or could not be lstat'd, then the
 * "ino" field of that structure is set to -1.
 * 
 * This call is intended for programs that want to
 * efficiently list a directory contents without making
 * many round-trips. See also "g.lxattrlist" for a
 * similarly efficient call for getting extended
 * attributes. Very long directory listings might cause the
 * protocol message size to be exceeded, causing this call
 * to fail. The caller must split up such requests into
 * smaller groups of names.
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_lstatlist+[http://libguestfs.org/guestfs.3.html#guestfs_lstatlist]).
 */
static VALUE
ruby_guestfs_lstatlist (VALUE gv, VALUE pathv, VALUE namesv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "lstatlist");

  const char *path = StringValueCStr (pathv);
  char **names;
  Check_Type (namesv, T_ARRAY);
  {
    size_t i, len;
    len = RARRAY_LEN (namesv);
    names = ALLOC_N (char *, len+1);
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
  size_t i;
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

/*
 * call-seq:
 *   g.lxattrlist(path, names) -> list
 *
 * lgetxattr on multiple files
 *
 * This call allows you to get the extended attributes of
 * multiple files, where all files are in the directory
 * "path". "names" is the list of files from this
 * directory.
 * 
 * On return you get a flat list of xattr structs which
 * must be interpreted sequentially. The first xattr struct
 * always has a zero-length "attrname". "attrval" in this
 * struct is zero-length to indicate there was an error
 * doing "lgetxattr" for this file, *or* is a C string
 * which is a decimal number (the number of following
 * attributes for this file, which could be "0"). Then
 * after the first xattr struct are the zero or more
 * attributes for the first named file. This repeats for
 * the second and subsequent files.
 * 
 * This call is intended for programs that want to
 * efficiently list a directory contents without making
 * many round-trips. See also "g.lstatlist" for a similarly
 * efficient call for getting standard stats. Very long
 * directory listings might cause the protocol message size
 * to be exceeded, causing this call to fail. The caller
 * must split up such requests into smaller groups of
 * names.
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_lxattrlist+[http://libguestfs.org/guestfs.3.html#guestfs_lxattrlist]).
 */
static VALUE
ruby_guestfs_lxattrlist (VALUE gv, VALUE pathv, VALUE namesv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "lxattrlist");

  const char *path = StringValueCStr (pathv);
  char **names;
  Check_Type (namesv, T_ARRAY);
  {
    size_t i, len;
    len = RARRAY_LEN (namesv);
    names = ALLOC_N (char *, len+1);
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
  size_t i;
  for (i = 0; i < r->len; ++i) {
    VALUE hv = rb_hash_new ();
    rb_hash_aset (hv, rb_str_new2 ("attrname"), rb_str_new2 (r->val[i].attrname));
    rb_hash_aset (hv, rb_str_new2 ("attrval"), rb_str_new (r->val[i].attrval, r->val[i].attrval_len));
    rb_ary_push (rv, hv);
  }
  guestfs_free_xattr_list (r);
  return rv;
}

/*
 * call-seq:
 *   g.readlinklist(path, names) -> list
 *
 * readlink on multiple files
 *
 * This call allows you to do a "readlink" operation on
 * multiple files, where all files are in the directory
 * "path". "names" is the list of files from this
 * directory.
 * 
 * On return you get a list of strings, with a one-to-one
 * correspondence to the "names" list. Each string is the
 * value of the symbolic link.
 * 
 * If the readlink(2) operation fails on any name, then the
 * corresponding result string is the empty string "".
 * However the whole operation is completed even if there
 * were readlink(2) errors, and so you can call this
 * function with names where you don't know if they are
 * symbolic links already (albeit slightly less efficient).
 * 
 * This call is intended for programs that want to
 * efficiently list a directory contents without making
 * many round-trips. Very long directory listings might
 * cause the protocol message size to be exceeded, causing
 * this call to fail. The caller must split up such
 * requests into smaller groups of names.
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_readlinklist+[http://libguestfs.org/guestfs.3.html#guestfs_readlinklist]).
 */
static VALUE
ruby_guestfs_readlinklist (VALUE gv, VALUE pathv, VALUE namesv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "readlinklist");

  const char *path = StringValueCStr (pathv);
  char **names;
  Check_Type (namesv, T_ARRAY);
  {
    size_t i, len;
    len = RARRAY_LEN (namesv);
    names = ALLOC_N (char *, len+1);
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

  size_t i, len = 0;
  for (i = 0; r[i] != NULL; ++i) len++;
  VALUE rv = rb_ary_new2 (len);
  for (i = 0; r[i] != NULL; ++i) {
    rb_ary_push (rv, rb_str_new2 (r[i]));
    free (r[i]);
  }
  free (r);
  return rv;
}

/*
 * call-seq:
 *   g.pread(path, count, offset) -> string
 *
 * read part of a file
 *
 * This command lets you read part of a file. It reads
 * "count" bytes of the file, starting at "offset", from
 * file "path".
 * 
 * This may read fewer bytes than requested. For further
 * details see the pread(2) system call.
 * 
 * See also "g.pwrite", "g.pread_device".
 * 
 * Because of the message protocol, there is a transfer
 * limit of somewhere between 2MB and 4MB. See "PROTOCOL
 * LIMITS" in guestfs(3).
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_pread+[http://libguestfs.org/guestfs.3.html#guestfs_pread]).
 */
static VALUE
ruby_guestfs_pread (VALUE gv, VALUE pathv, VALUE countv, VALUE offsetv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "pread");

  const char *path = StringValueCStr (pathv);
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

/*
 * call-seq:
 *   g.part_init(device, parttype) -> nil
 *
 * create an empty partition table
 *
 * This creates an empty partition table on "device" of one
 * of the partition types listed below. Usually "parttype"
 * should be either "msdos" or "gpt" (for large disks).
 * 
 * Initially there are no partitions. Following this, you
 * should call "g.part_add" for each partition required.
 * 
 * Possible values for "parttype" are:
 * 
 * efi
 * gpt Intel EFI / GPT partition table.
 * 
 * This is recommended for >= 2 TB partitions that will
 * be accessed from Linux and Intel-based Mac OS X. It
 * also has limited backwards compatibility with the
 * "mbr" format.
 * 
 * mbr
 * msdos
 * The standard PC "Master Boot Record" (MBR) format
 * used by MS-DOS and Windows. This partition type will
 * only work for device sizes up to 2 TB. For large
 * disks we recommend using "gpt".
 * 
 * Other partition table types that may work but are not
 * supported include:
 * 
 * aix AIX disk labels.
 * 
 * amiga
 * rdb Amiga "Rigid Disk Block" format.
 * 
 * bsd BSD disk labels.
 * 
 * dasd
 * DASD, used on IBM mainframes.
 * 
 * dvh MIPS/SGI volumes.
 * 
 * mac Old Mac partition format. Modern Macs use "gpt".
 * 
 * pc98
 * NEC PC-98 format, common in Japan apparently.
 * 
 * sun Sun disk labels.
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_part_init+[http://libguestfs.org/guestfs.3.html#guestfs_part_init]).
 */
static VALUE
ruby_guestfs_part_init (VALUE gv, VALUE devicev, VALUE parttypev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "part_init");

  const char *device = StringValueCStr (devicev);
  const char *parttype = StringValueCStr (parttypev);

  int r;

  r = guestfs_part_init (g, device, parttype);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.part_add(device, prlogex, startsect, endsect) -> nil
 *
 * add a partition to the device
 *
 * This command adds a partition to "device". If there is
 * no partition table on the device, call "g.part_init"
 * first.
 * 
 * The "prlogex" parameter is the type of partition.
 * Normally you should pass "p" or "primary" here, but MBR
 * partition tables also support "l" (or "logical") and "e"
 * (or "extended") partition types.
 * 
 * "startsect" and "endsect" are the start and end of the
 * partition in *sectors*. "endsect" may be negative, which
 * means it counts backwards from the end of the disk (-1
 * is the last sector).
 * 
 * Creating a partition which covers the whole disk is not
 * so easy. Use "g.part_disk" to do that.
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_part_add+[http://libguestfs.org/guestfs.3.html#guestfs_part_add]).
 */
static VALUE
ruby_guestfs_part_add (VALUE gv, VALUE devicev, VALUE prlogexv, VALUE startsectv, VALUE endsectv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "part_add");

  const char *device = StringValueCStr (devicev);
  const char *prlogex = StringValueCStr (prlogexv);
  long long startsect = NUM2LL (startsectv);
  long long endsect = NUM2LL (endsectv);

  int r;

  r = guestfs_part_add (g, device, prlogex, startsect, endsect);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.part_disk(device, parttype) -> nil
 *
 * partition whole disk with a single primary partition
 *
 * This command is simply a combination of "g.part_init"
 * followed by "g.part_add" to create a single primary
 * partition covering the whole disk.
 * 
 * "parttype" is the partition table type, usually "mbr" or
 * "gpt", but other possible values are described in
 * "g.part_init".
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_part_disk+[http://libguestfs.org/guestfs.3.html#guestfs_part_disk]).
 */
static VALUE
ruby_guestfs_part_disk (VALUE gv, VALUE devicev, VALUE parttypev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "part_disk");

  const char *device = StringValueCStr (devicev);
  const char *parttype = StringValueCStr (parttypev);

  int r;

  r = guestfs_part_disk (g, device, parttype);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.part_set_bootable(device, partnum, bootable) -> nil
 *
 * make a partition bootable
 *
 * This sets the bootable flag on partition numbered
 * "partnum" on device "device". Note that partitions are
 * numbered from 1.
 * 
 * The bootable flag is used by some operating systems
 * (notably Windows) to determine which partition to boot
 * from. It is by no means universally recognized.
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_part_set_bootable+[http://libguestfs.org/guestfs.3.html#guestfs_part_set_bootable]).
 */
static VALUE
ruby_guestfs_part_set_bootable (VALUE gv, VALUE devicev, VALUE partnumv, VALUE bootablev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "part_set_bootable");

  const char *device = StringValueCStr (devicev);
  int partnum = NUM2INT (partnumv);
  int bootable = RTEST (bootablev);

  int r;

  r = guestfs_part_set_bootable (g, device, partnum, bootable);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.part_set_name(device, partnum, name) -> nil
 *
 * set partition name
 *
 * This sets the partition name on partition numbered
 * "partnum" on device "device". Note that partitions are
 * numbered from 1.
 * 
 * The partition name can only be set on certain types of
 * partition table. This works on "gpt" but not on "mbr"
 * partitions.
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_part_set_name+[http://libguestfs.org/guestfs.3.html#guestfs_part_set_name]).
 */
static VALUE
ruby_guestfs_part_set_name (VALUE gv, VALUE devicev, VALUE partnumv, VALUE namev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "part_set_name");

  const char *device = StringValueCStr (devicev);
  int partnum = NUM2INT (partnumv);
  const char *name = StringValueCStr (namev);

  int r;

  r = guestfs_part_set_name (g, device, partnum, name);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.part_list(device) -> list
 *
 * list partitions on a device
 *
 * This command parses the partition table on "device" and
 * returns the list of partitions found.
 * 
 * The fields in the returned structure are:
 * 
 * part_num
 * Partition number, counting from 1.
 * 
 * part_start
 * Start of the partition *in bytes*. To get sectors
 * you have to divide by the device's sector size, see
 * "g.blockdev_getss".
 * 
 * part_end
 * End of the partition in bytes.
 * 
 * part_size
 * Size of the partition in bytes.
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_part_list+[http://libguestfs.org/guestfs.3.html#guestfs_part_list]).
 */
static VALUE
ruby_guestfs_part_list (VALUE gv, VALUE devicev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "part_list");

  const char *device = StringValueCStr (devicev);

  struct guestfs_partition_list *r;

  r = guestfs_part_list (g, device);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  VALUE rv = rb_ary_new2 (r->len);
  size_t i;
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

/*
 * call-seq:
 *   g.part_get_parttype(device) -> string
 *
 * get the partition table type
 *
 * This command examines the partition table on "device"
 * and returns the partition table type (format) being
 * used.
 * 
 * Common return values include: "msdos" (a DOS/Windows
 * style MBR partition table), "gpt" (a GPT/EFI-style
 * partition table). Other values are possible, although
 * unusual. See "g.part_init" for a full list.
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_part_get_parttype+[http://libguestfs.org/guestfs.3.html#guestfs_part_get_parttype]).
 */
static VALUE
ruby_guestfs_part_get_parttype (VALUE gv, VALUE devicev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "part_get_parttype");

  const char *device = StringValueCStr (devicev);

  char *r;

  r = guestfs_part_get_parttype (g, device);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  VALUE rv = rb_str_new2 (r);
  free (r);
  return rv;
}

/*
 * call-seq:
 *   g.fill(c, len, path) -> nil
 *
 * fill a file with octets
 *
 * This command creates a new file called "path". The
 * initial content of the file is "len" octets of "c",
 * where "c" must be a number in the range "[0..255]".
 * 
 * To fill a file with zero bytes (sparsely), it is much
 * more efficient to use "g.truncate_size". To create a
 * file with a pattern of repeating bytes use
 * "g.fill_pattern".
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_fill+[http://libguestfs.org/guestfs.3.html#guestfs_fill]).
 */
static VALUE
ruby_guestfs_fill (VALUE gv, VALUE cv, VALUE lenv, VALUE pathv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "fill");

  int c = NUM2INT (cv);
  int len = NUM2INT (lenv);
  const char *path = StringValueCStr (pathv);

  int r;

  r = guestfs_fill (g, c, len, path);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.available(groups) -> nil
 *
 * test availability of some parts of the API
 *
 * This command is used to check the availability of some
 * groups of functionality in the appliance, which not all
 * builds of the libguestfs appliance will be able to
 * provide.
 * 
 * The libguestfs groups, and the functions that those
 * groups correspond to, are listed in "AVAILABILITY" in
 * guestfs(3). You can also fetch this list at runtime by
 * calling "g.available_all_groups".
 * 
 * The argument "groups" is a list of group names, eg:
 * "["inotify", "augeas"]" would check for the availability
 * of the Linux inotify functions and Augeas (configuration
 * file editing) functions.
 * 
 * The command returns no error if *all* requested groups
 * are available.
 * 
 * It fails with an error if one or more of the requested
 * groups is unavailable in the appliance.
 * 
 * If an unknown group name is included in the list of
 * groups then an error is always returned.
 * 
 * *Notes:*
 * 
 * *   You must call "g.launch" before calling this
 * function.
 * 
 * The reason is because we don't know what groups are
 * supported by the appliance/daemon until it is
 * running and can be queried.
 * 
 * *   If a group of functions is available, this does not
 * necessarily mean that they will work. You still have
 * to check for errors when calling individual API
 * functions even if they are available.
 * 
 * *   It is usually the job of distro packagers to build
 * complete functionality into the libguestfs
 * appliance. Upstream libguestfs, if built from source
 * with all requirements satisfied, will support
 * everything.
 * 
 * *   This call was added in version 1.0.80. In previous
 * versions of libguestfs all you could do would be to
 * speculatively execute a command to find out if the
 * daemon implemented it. See also "g.version".
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_available+[http://libguestfs.org/guestfs.3.html#guestfs_available]).
 */
static VALUE
ruby_guestfs_available (VALUE gv, VALUE groupsv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "available");

  char **groups;
  Check_Type (groupsv, T_ARRAY);
  {
    size_t i, len;
    len = RARRAY_LEN (groupsv);
    groups = ALLOC_N (char *, len+1);
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

/*
 * call-seq:
 *   g.dd(src, dest) -> nil
 *
 * copy from source to destination using dd
 *
 * This command copies from one source device or file "src"
 * to another destination device or file "dest". Normally
 * you would use this to copy to or from a device or
 * partition, for example to duplicate a filesystem.
 * 
 * If the destination is a device, it must be as large or
 * larger than the source file or device, otherwise the
 * copy will fail. This command cannot do partial copies
 * (see "g.copy_device_to_device").
 * 
 * *This function is deprecated.* In new code, use the
 * "copy_device_to_device" call instead.
 * 
 * Deprecated functions will not be removed from the API,
 * but the fact that they are deprecated indicates that
 * there are problems with correct use of these functions.
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_dd+[http://libguestfs.org/guestfs.3.html#guestfs_dd]).
 */
static VALUE
ruby_guestfs_dd (VALUE gv, VALUE srcv, VALUE destv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "dd");

  const char *src = StringValueCStr (srcv);
  const char *dest = StringValueCStr (destv);

  int r;

  r = guestfs_dd (g, src, dest);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.filesize(file) -> fixnum
 *
 * return the size of the file in bytes
 *
 * This command returns the size of "file" in bytes.
 * 
 * To get other stats about a file, use "g.stat",
 * "g.lstat", "g.is_dir", "g.is_file" etc. To get the size
 * of block devices, use "g.blockdev_getsize64".
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_filesize+[http://libguestfs.org/guestfs.3.html#guestfs_filesize]).
 */
static VALUE
ruby_guestfs_filesize (VALUE gv, VALUE filev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "filesize");

  const char *file = StringValueCStr (filev);

  int64_t r;

  r = guestfs_filesize (g, file);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return ULL2NUM (r);
}

/*
 * call-seq:
 *   g.lvrename(logvol, newlogvol) -> nil
 *
 * rename an LVM logical volume
 *
 * Rename a logical volume "logvol" with the new name
 * "newlogvol".
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_lvrename+[http://libguestfs.org/guestfs.3.html#guestfs_lvrename]).
 */
static VALUE
ruby_guestfs_lvrename (VALUE gv, VALUE logvolv, VALUE newlogvolv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "lvrename");

  const char *logvol = StringValueCStr (logvolv);
  const char *newlogvol = StringValueCStr (newlogvolv);

  int r;

  r = guestfs_lvrename (g, logvol, newlogvol);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.vgrename(volgroup, newvolgroup) -> nil
 *
 * rename an LVM volume group
 *
 * Rename a volume group "volgroup" with the new name
 * "newvolgroup".
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_vgrename+[http://libguestfs.org/guestfs.3.html#guestfs_vgrename]).
 */
static VALUE
ruby_guestfs_vgrename (VALUE gv, VALUE volgroupv, VALUE newvolgroupv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "vgrename");

  const char *volgroup = StringValueCStr (volgroupv);
  const char *newvolgroup = StringValueCStr (newvolgroupv);

  int r;

  r = guestfs_vgrename (g, volgroup, newvolgroup);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.initrd_cat(initrdpath, filename) -> string
 *
 * list the contents of a single file in an initrd
 *
 * This command unpacks the file "filename" from the initrd
 * file called "initrdpath". The filename must be given
 * *without* the initial "/" character.
 * 
 * For example, in guestfish you could use the following
 * command to examine the boot script (usually called
 * "/init") contained in a Linux initrd or initramfs image:
 * 
 * initrd-cat /boot/initrd-<version>.img init
 * 
 * See also "g.initrd_list".
 * 
 * Because of the message protocol, there is a transfer
 * limit of somewhere between 2MB and 4MB. See "PROTOCOL
 * LIMITS" in guestfs(3).
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_initrd_cat+[http://libguestfs.org/guestfs.3.html#guestfs_initrd_cat]).
 */
static VALUE
ruby_guestfs_initrd_cat (VALUE gv, VALUE initrdpathv, VALUE filenamev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "initrd_cat");

  const char *initrdpath = StringValueCStr (initrdpathv);
  const char *filename = StringValueCStr (filenamev);

  char *r;
  size_t size;

  r = guestfs_initrd_cat (g, initrdpath, filename, &size);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  VALUE rv = rb_str_new (r, size);
  free (r);
  return rv;
}

/*
 * call-seq:
 *   g.pvuuid(device) -> string
 *
 * get the UUID of a physical volume
 *
 * This command returns the UUID of the LVM PV "device".
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_pvuuid+[http://libguestfs.org/guestfs.3.html#guestfs_pvuuid]).
 */
static VALUE
ruby_guestfs_pvuuid (VALUE gv, VALUE devicev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "pvuuid");

  const char *device = StringValueCStr (devicev);

  char *r;

  r = guestfs_pvuuid (g, device);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  VALUE rv = rb_str_new2 (r);
  free (r);
  return rv;
}

/*
 * call-seq:
 *   g.vguuid(vgname) -> string
 *
 * get the UUID of a volume group
 *
 * This command returns the UUID of the LVM VG named
 * "vgname".
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_vguuid+[http://libguestfs.org/guestfs.3.html#guestfs_vguuid]).
 */
static VALUE
ruby_guestfs_vguuid (VALUE gv, VALUE vgnamev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "vguuid");

  const char *vgname = StringValueCStr (vgnamev);

  char *r;

  r = guestfs_vguuid (g, vgname);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  VALUE rv = rb_str_new2 (r);
  free (r);
  return rv;
}

/*
 * call-seq:
 *   g.lvuuid(device) -> string
 *
 * get the UUID of a logical volume
 *
 * This command returns the UUID of the LVM LV "device".
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_lvuuid+[http://libguestfs.org/guestfs.3.html#guestfs_lvuuid]).
 */
static VALUE
ruby_guestfs_lvuuid (VALUE gv, VALUE devicev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "lvuuid");

  const char *device = StringValueCStr (devicev);

  char *r;

  r = guestfs_lvuuid (g, device);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  VALUE rv = rb_str_new2 (r);
  free (r);
  return rv;
}

/*
 * call-seq:
 *   g.vgpvuuids(vgname) -> list
 *
 * get the PV UUIDs containing the volume group
 *
 * Given a VG called "vgname", this returns the UUIDs of
 * all the physical volumes that this volume group resides
 * on.
 * 
 * You can use this along with "g.pvs" and "g.pvuuid" calls
 * to associate physical volumes and volume groups.
 * 
 * See also "g.vglvuuids".
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_vgpvuuids+[http://libguestfs.org/guestfs.3.html#guestfs_vgpvuuids]).
 */
static VALUE
ruby_guestfs_vgpvuuids (VALUE gv, VALUE vgnamev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "vgpvuuids");

  const char *vgname = StringValueCStr (vgnamev);

  char **r;

  r = guestfs_vgpvuuids (g, vgname);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  size_t i, len = 0;
  for (i = 0; r[i] != NULL; ++i) len++;
  VALUE rv = rb_ary_new2 (len);
  for (i = 0; r[i] != NULL; ++i) {
    rb_ary_push (rv, rb_str_new2 (r[i]));
    free (r[i]);
  }
  free (r);
  return rv;
}

/*
 * call-seq:
 *   g.vglvuuids(vgname) -> list
 *
 * get the LV UUIDs of all LVs in the volume group
 *
 * Given a VG called "vgname", this returns the UUIDs of
 * all the logical volumes created in this volume group.
 * 
 * You can use this along with "g.lvs" and "g.lvuuid" calls
 * to associate logical volumes and volume groups.
 * 
 * See also "g.vgpvuuids".
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_vglvuuids+[http://libguestfs.org/guestfs.3.html#guestfs_vglvuuids]).
 */
static VALUE
ruby_guestfs_vglvuuids (VALUE gv, VALUE vgnamev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "vglvuuids");

  const char *vgname = StringValueCStr (vgnamev);

  char **r;

  r = guestfs_vglvuuids (g, vgname);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  size_t i, len = 0;
  for (i = 0; r[i] != NULL; ++i) len++;
  VALUE rv = rb_ary_new2 (len);
  for (i = 0; r[i] != NULL; ++i) {
    rb_ary_push (rv, rb_str_new2 (r[i]));
    free (r[i]);
  }
  free (r);
  return rv;
}

/*
 * call-seq:
 *   g.copy_size(src, dest, size) -> nil
 *
 * copy size bytes from source to destination using dd
 *
 * This command copies exactly "size" bytes from one source
 * device or file "src" to another destination device or
 * file "dest".
 * 
 * Note this will fail if the source is too short or if the
 * destination is not large enough.
 * 
 * *This function is deprecated.* In new code, use the
 * "copy_device_to_device" call instead.
 * 
 * Deprecated functions will not be removed from the API,
 * but the fact that they are deprecated indicates that
 * there are problems with correct use of these functions.
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_copy_size+[http://libguestfs.org/guestfs.3.html#guestfs_copy_size]).
 */
static VALUE
ruby_guestfs_copy_size (VALUE gv, VALUE srcv, VALUE destv, VALUE sizev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "copy_size");

  const char *src = StringValueCStr (srcv);
  const char *dest = StringValueCStr (destv);
  long long size = NUM2LL (sizev);

  int r;

  r = guestfs_copy_size (g, src, dest, size);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.zero_device(device) -> nil
 *
 * write zeroes to an entire device
 *
 * This command writes zeroes over the entire "device".
 * Compare with "g.zero" which just zeroes the first few
 * blocks of a device.
 * 
 * If blocks are already zero, then this command avoids
 * writing zeroes. This prevents the underlying device from
 * becoming non-sparse or growing unnecessarily.
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_zero_device+[http://libguestfs.org/guestfs.3.html#guestfs_zero_device]).
 */
static VALUE
ruby_guestfs_zero_device (VALUE gv, VALUE devicev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "zero_device");

  const char *device = StringValueCStr (devicev);

  int r;

  r = guestfs_zero_device (g, device);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.txz_in(tarball, directory) -> nil
 *
 * unpack compressed tarball to directory
 *
 * This command uploads and unpacks local file "tarball"
 * (an *xz compressed* tar file) into "directory".
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_txz_in+[http://libguestfs.org/guestfs.3.html#guestfs_txz_in]).
 */
static VALUE
ruby_guestfs_txz_in (VALUE gv, VALUE tarballv, VALUE directoryv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "txz_in");

  const char *tarball = StringValueCStr (tarballv);
  const char *directory = StringValueCStr (directoryv);

  int r;

  r = guestfs_txz_in (g, tarball, directory);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.txz_out(directory, tarball) -> nil
 *
 * pack directory into compressed tarball
 *
 * This command packs the contents of "directory" and
 * downloads it to local file "tarball" (as an xz
 * compressed tar archive).
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_txz_out+[http://libguestfs.org/guestfs.3.html#guestfs_txz_out]).
 */
static VALUE
ruby_guestfs_txz_out (VALUE gv, VALUE directoryv, VALUE tarballv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "txz_out");

  const char *directory = StringValueCStr (directoryv);
  const char *tarball = StringValueCStr (tarballv);

  int r;

  r = guestfs_txz_out (g, directory, tarball);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.ntfsresize(device) -> nil
 *
 * resize an NTFS filesystem
 *
 * This command resizes an NTFS filesystem, expanding or
 * shrinking it to the size of the underlying device.
 * 
 * *Note:* After the resize operation, the filesystem is
 * marked as requiring a consistency check (for safety).
 * You have to boot into Windows to perform this check and
 * clear this condition. Furthermore, ntfsresize refuses to
 * resize filesystems which have been marked in this way.
 * So in effect it is not possible to call ntfsresize
 * multiple times on a single filesystem without booting
 * into Windows between each resize.
 * 
 * See also ntfsresize(8).
 * 
 * *This function is deprecated.* In new code, use the
 * "ntfsresize_opts" call instead.
 * 
 * Deprecated functions will not be removed from the API,
 * but the fact that they are deprecated indicates that
 * there are problems with correct use of these functions.
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_ntfsresize+[http://libguestfs.org/guestfs.3.html#guestfs_ntfsresize]).
 */
static VALUE
ruby_guestfs_ntfsresize (VALUE gv, VALUE devicev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "ntfsresize");

  const char *device = StringValueCStr (devicev);

  int r;

  r = guestfs_ntfsresize (g, device);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.vgscan() -> nil
 *
 * rescan for LVM physical volumes, volume groups and logical volumes
 *
 * This rescans all block devices and rebuilds the list of
 * LVM physical volumes, volume groups and logical volumes.
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_vgscan+[http://libguestfs.org/guestfs.3.html#guestfs_vgscan]).
 */
static VALUE
ruby_guestfs_vgscan (VALUE gv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "vgscan");


  int r;

  r = guestfs_vgscan (g);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.part_del(device, partnum) -> nil
 *
 * delete a partition
 *
 * This command deletes the partition numbered "partnum" on
 * "device".
 * 
 * Note that in the case of MBR partitioning, deleting an
 * extended partition also deletes any logical partitions
 * it contains.
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_part_del+[http://libguestfs.org/guestfs.3.html#guestfs_part_del]).
 */
static VALUE
ruby_guestfs_part_del (VALUE gv, VALUE devicev, VALUE partnumv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "part_del");

  const char *device = StringValueCStr (devicev);
  int partnum = NUM2INT (partnumv);

  int r;

  r = guestfs_part_del (g, device, partnum);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.part_get_bootable(device, partnum) -> [True|False]
 *
 * return true if a partition is bootable
 *
 * This command returns true if the partition "partnum" on
 * "device" has the bootable flag set.
 * 
 * See also "g.part_set_bootable".
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_part_get_bootable+[http://libguestfs.org/guestfs.3.html#guestfs_part_get_bootable]).
 */
static VALUE
ruby_guestfs_part_get_bootable (VALUE gv, VALUE devicev, VALUE partnumv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "part_get_bootable");

  const char *device = StringValueCStr (devicev);
  int partnum = NUM2INT (partnumv);

  int r;

  r = guestfs_part_get_bootable (g, device, partnum);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return INT2NUM (r);
}

/*
 * call-seq:
 *   g.part_get_mbr_id(device, partnum) -> fixnum
 *
 * get the MBR type byte (ID byte) from a partition
 *
 * Returns the MBR type byte (also known as the ID byte)
 * from the numbered partition "partnum".
 * 
 * Note that only MBR (old DOS-style) partitions have type
 * bytes. You will get undefined results for other
 * partition table types (see "g.part_get_parttype").
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_part_get_mbr_id+[http://libguestfs.org/guestfs.3.html#guestfs_part_get_mbr_id]).
 */
static VALUE
ruby_guestfs_part_get_mbr_id (VALUE gv, VALUE devicev, VALUE partnumv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "part_get_mbr_id");

  const char *device = StringValueCStr (devicev);
  int partnum = NUM2INT (partnumv);

  int r;

  r = guestfs_part_get_mbr_id (g, device, partnum);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return INT2NUM (r);
}

/*
 * call-seq:
 *   g.part_set_mbr_id(device, partnum, idbyte) -> nil
 *
 * set the MBR type byte (ID byte) of a partition
 *
 * Sets the MBR type byte (also known as the ID byte) of
 * the numbered partition "partnum" to "idbyte". Note that
 * the type bytes quoted in most documentation are in fact
 * hexadecimal numbers, but usually documented without any
 * leading "0x" which might be confusing.
 * 
 * Note that only MBR (old DOS-style) partitions have type
 * bytes. You will get undefined results for other
 * partition table types (see "g.part_get_parttype").
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_part_set_mbr_id+[http://libguestfs.org/guestfs.3.html#guestfs_part_set_mbr_id]).
 */
static VALUE
ruby_guestfs_part_set_mbr_id (VALUE gv, VALUE devicev, VALUE partnumv, VALUE idbytev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "part_set_mbr_id");

  const char *device = StringValueCStr (devicev);
  int partnum = NUM2INT (partnumv);
  int idbyte = NUM2INT (idbytev);

  int r;

  r = guestfs_part_set_mbr_id (g, device, partnum, idbyte);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.checksum_device(csumtype, device) -> string
 *
 * compute MD5, SHAx or CRC checksum of the contents of a device
 *
 * This call computes the MD5, SHAx or CRC checksum of the
 * contents of the device named "device". For the types of
 * checksums supported see the "g.checksum" command.
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_checksum_device+[http://libguestfs.org/guestfs.3.html#guestfs_checksum_device]).
 */
static VALUE
ruby_guestfs_checksum_device (VALUE gv, VALUE csumtypev, VALUE devicev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "checksum_device");

  const char *csumtype = StringValueCStr (csumtypev);
  const char *device = StringValueCStr (devicev);

  char *r;

  r = guestfs_checksum_device (g, csumtype, device);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  VALUE rv = rb_str_new2 (r);
  free (r);
  return rv;
}

/*
 * call-seq:
 *   g.lvresize_free(lv, percent) -> nil
 *
 * expand an LV to fill free space
 *
 * This expands an existing logical volume "lv" so that it
 * fills "pc"% of the remaining free space in the volume
 * group. Commonly you would call this with pc = 100 which
 * expands the logical volume as much as possible, using
 * all remaining free space in the volume group.
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_lvresize_free+[http://libguestfs.org/guestfs.3.html#guestfs_lvresize_free]).
 */
static VALUE
ruby_guestfs_lvresize_free (VALUE gv, VALUE lvv, VALUE percentv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "lvresize_free");

  const char *lv = StringValueCStr (lvv);
  int percent = NUM2INT (percentv);

  int r;

  r = guestfs_lvresize_free (g, lv, percent);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.aug_clear(augpath) -> nil
 *
 * clear Augeas path
 *
 * Set the value associated with "path" to "NULL". This is
 * the same as the augtool(1) "clear" command.
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_aug_clear+[http://libguestfs.org/guestfs.3.html#guestfs_aug_clear]).
 */
static VALUE
ruby_guestfs_aug_clear (VALUE gv, VALUE augpathv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "aug_clear");

  const char *augpath = StringValueCStr (augpathv);

  int r;

  r = guestfs_aug_clear (g, augpath);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.get_umask() -> fixnum
 *
 * get the current umask
 *
 * Return the current umask. By default the umask is 022
 * unless it has been set by calling "g.umask".
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_get_umask+[http://libguestfs.org/guestfs.3.html#guestfs_get_umask]).
 */
static VALUE
ruby_guestfs_get_umask (VALUE gv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "get_umask");


  int r;

  r = guestfs_get_umask (g);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return INT2NUM (r);
}

static VALUE
ruby_guestfs_debug_upload (VALUE gv, VALUE filenamev, VALUE tmpnamev, VALUE modev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "debug_upload");

  const char *filename = StringValueCStr (filenamev);
  const char *tmpname = StringValueCStr (tmpnamev);
  int mode = NUM2INT (modev);

  int r;

  r = guestfs_debug_upload (g, filename, tmpname, mode);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.base64_in(base64file, filename) -> nil
 *
 * upload base64-encoded data to file
 *
 * This command uploads base64-encoded data from
 * "base64file" to "filename".
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_base64_in+[http://libguestfs.org/guestfs.3.html#guestfs_base64_in]).
 */
static VALUE
ruby_guestfs_base64_in (VALUE gv, VALUE base64filev, VALUE filenamev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "base64_in");

  const char *base64file = StringValueCStr (base64filev);
  const char *filename = StringValueCStr (filenamev);

  int r;

  r = guestfs_base64_in (g, base64file, filename);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.base64_out(filename, base64file) -> nil
 *
 * download file and encode as base64
 *
 * This command downloads the contents of "filename",
 * writing it out to local file "base64file" encoded as
 * base64.
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_base64_out+[http://libguestfs.org/guestfs.3.html#guestfs_base64_out]).
 */
static VALUE
ruby_guestfs_base64_out (VALUE gv, VALUE filenamev, VALUE base64filev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "base64_out");

  const char *filename = StringValueCStr (filenamev);
  const char *base64file = StringValueCStr (base64filev);

  int r;

  r = guestfs_base64_out (g, filename, base64file);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.checksums_out(csumtype, directory, sumsfile) -> nil
 *
 * compute MD5, SHAx or CRC checksum of files in a directory
 *
 * This command computes the checksums of all regular files
 * in "directory" and then emits a list of those checksums
 * to the local output file "sumsfile".
 * 
 * This can be used for verifying the integrity of a
 * virtual machine. However to be properly secure you
 * should pay attention to the output of the checksum
 * command (it uses the ones from GNU coreutils). In
 * particular when the filename is not printable, coreutils
 * uses a special backslash syntax. For more information,
 * see the GNU coreutils info file.
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_checksums_out+[http://libguestfs.org/guestfs.3.html#guestfs_checksums_out]).
 */
static VALUE
ruby_guestfs_checksums_out (VALUE gv, VALUE csumtypev, VALUE directoryv, VALUE sumsfilev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "checksums_out");

  const char *csumtype = StringValueCStr (csumtypev);
  const char *directory = StringValueCStr (directoryv);
  const char *sumsfile = StringValueCStr (sumsfilev);

  int r;

  r = guestfs_checksums_out (g, csumtype, directory, sumsfile);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.fill_pattern(pattern, len, path) -> nil
 *
 * fill a file with a repeating pattern of bytes
 *
 * This function is like "g.fill" except that it creates a
 * new file of length "len" containing the repeating
 * pattern of bytes in "pattern". The pattern is truncated
 * if necessary to ensure the length of the file is exactly
 * "len" bytes.
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_fill_pattern+[http://libguestfs.org/guestfs.3.html#guestfs_fill_pattern]).
 */
static VALUE
ruby_guestfs_fill_pattern (VALUE gv, VALUE patternv, VALUE lenv, VALUE pathv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "fill_pattern");

  const char *pattern = StringValueCStr (patternv);
  int len = NUM2INT (lenv);
  const char *path = StringValueCStr (pathv);

  int r;

  r = guestfs_fill_pattern (g, pattern, len, path);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.write(path, content) -> nil
 *
 * create a new file
 *
 * This call creates a file called "path". The content of
 * the file is the string "content" (which can contain any
 * 8 bit data).
 * 
 * See also "g.write_append".
 * 
 * Because of the message protocol, there is a transfer
 * limit of somewhere between 2MB and 4MB. See "PROTOCOL
 * LIMITS" in guestfs(3).
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_write+[http://libguestfs.org/guestfs.3.html#guestfs_write]).
 */
static VALUE
ruby_guestfs_write (VALUE gv, VALUE pathv, VALUE contentv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "write");

  const char *path = StringValueCStr (pathv);
  Check_Type (contentv, T_STRING);
  const char *content = RSTRING (contentv)->ptr;
  if (!content)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "content", "write");
  size_t content_size = RSTRING (contentv)->len;

  int r;

  r = guestfs_write (g, path, content, content_size);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.pwrite(path, content, offset) -> fixnum
 *
 * write to part of a file
 *
 * This command writes to part of a file. It writes the
 * data buffer "content" to the file "path" starting at
 * offset "offset".
 * 
 * This command implements the pwrite(2) system call, and
 * like that system call it may not write the full data
 * requested. The return value is the number of bytes that
 * were actually written to the file. This could even be 0,
 * although short writes are unlikely for regular files in
 * ordinary circumstances.
 * 
 * See also "g.pread", "g.pwrite_device".
 * 
 * Because of the message protocol, there is a transfer
 * limit of somewhere between 2MB and 4MB. See "PROTOCOL
 * LIMITS" in guestfs(3).
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_pwrite+[http://libguestfs.org/guestfs.3.html#guestfs_pwrite]).
 */
static VALUE
ruby_guestfs_pwrite (VALUE gv, VALUE pathv, VALUE contentv, VALUE offsetv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "pwrite");

  const char *path = StringValueCStr (pathv);
  Check_Type (contentv, T_STRING);
  const char *content = RSTRING (contentv)->ptr;
  if (!content)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "content", "pwrite");
  size_t content_size = RSTRING (contentv)->len;
  long long offset = NUM2LL (offsetv);

  int r;

  r = guestfs_pwrite (g, path, content, content_size, offset);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return INT2NUM (r);
}

/*
 * call-seq:
 *   g.resize2fs_size(device, size) -> nil
 *
 * resize an ext2, ext3 or ext4 filesystem (with size)
 *
 * This command is the same as "g.resize2fs" except that it
 * allows you to specify the new size (in bytes)
 * explicitly.
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_resize2fs_size+[http://libguestfs.org/guestfs.3.html#guestfs_resize2fs_size]).
 */
static VALUE
ruby_guestfs_resize2fs_size (VALUE gv, VALUE devicev, VALUE sizev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "resize2fs_size");

  const char *device = StringValueCStr (devicev);
  long long size = NUM2LL (sizev);

  int r;

  r = guestfs_resize2fs_size (g, device, size);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.pvresize_size(device, size) -> nil
 *
 * resize an LVM physical volume (with size)
 *
 * This command is the same as "g.pvresize" except that it
 * allows you to specify the new size (in bytes)
 * explicitly.
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_pvresize_size+[http://libguestfs.org/guestfs.3.html#guestfs_pvresize_size]).
 */
static VALUE
ruby_guestfs_pvresize_size (VALUE gv, VALUE devicev, VALUE sizev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "pvresize_size");

  const char *device = StringValueCStr (devicev);
  long long size = NUM2LL (sizev);

  int r;

  r = guestfs_pvresize_size (g, device, size);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.ntfsresize_size(device, size) -> nil
 *
 * resize an NTFS filesystem (with size)
 *
 * This command is the same as "g.ntfsresize" except that
 * it allows you to specify the new size (in bytes)
 * explicitly.
 * 
 * *This function is deprecated.* In new code, use the
 * "ntfsresize_opts" call instead.
 * 
 * Deprecated functions will not be removed from the API,
 * but the fact that they are deprecated indicates that
 * there are problems with correct use of these functions.
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_ntfsresize_size+[http://libguestfs.org/guestfs.3.html#guestfs_ntfsresize_size]).
 */
static VALUE
ruby_guestfs_ntfsresize_size (VALUE gv, VALUE devicev, VALUE sizev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "ntfsresize_size");

  const char *device = StringValueCStr (devicev);
  long long size = NUM2LL (sizev);

  int r;

  r = guestfs_ntfsresize_size (g, device, size);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.available_all_groups() -> list
 *
 * return a list of all optional groups
 *
 * This command returns a list of all optional groups that
 * this daemon knows about. Note this returns both
 * supported and unsupported groups. To find out which ones
 * the daemon can actually support you have to call
 * "g.available" on each member of the returned list.
 * 
 * See also "g.available" and "AVAILABILITY" in guestfs(3).
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_available_all_groups+[http://libguestfs.org/guestfs.3.html#guestfs_available_all_groups]).
 */
static VALUE
ruby_guestfs_available_all_groups (VALUE gv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "available_all_groups");


  char **r;

  r = guestfs_available_all_groups (g);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  size_t i, len = 0;
  for (i = 0; r[i] != NULL; ++i) len++;
  VALUE rv = rb_ary_new2 (len);
  for (i = 0; r[i] != NULL; ++i) {
    rb_ary_push (rv, rb_str_new2 (r[i]));
    free (r[i]);
  }
  free (r);
  return rv;
}

/*
 * call-seq:
 *   g.fallocate64(path, len) -> nil
 *
 * preallocate a file in the guest filesystem
 *
 * This command preallocates a file (containing zero bytes)
 * named "path" of size "len" bytes. If the file exists
 * already, it is overwritten.
 * 
 * Note that this call allocates disk blocks for the file.
 * To create a sparse file use "g.truncate_size" instead.
 * 
 * The deprecated call "g.fallocate" does the same, but
 * owing to an oversight it only allowed 30 bit lengths to
 * be specified, effectively limiting the maximum size of
 * files created through that call to 1GB.
 * 
 * Do not confuse this with the guestfish-specific "alloc"
 * and "sparse" commands which create a file in the host
 * and attach it as a device.
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_fallocate64+[http://libguestfs.org/guestfs.3.html#guestfs_fallocate64]).
 */
static VALUE
ruby_guestfs_fallocate64 (VALUE gv, VALUE pathv, VALUE lenv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "fallocate64");

  const char *path = StringValueCStr (pathv);
  long long len = NUM2LL (lenv);

  int r;

  r = guestfs_fallocate64 (g, path, len);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.vfs_label(device) -> string
 *
 * get the filesystem label
 *
 * This returns the filesystem label of the filesystem on
 * "device".
 * 
 * If the filesystem is unlabeled, this returns the empty
 * string.
 * 
 * To find a filesystem from the label, use
 * "g.findfs_label".
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_vfs_label+[http://libguestfs.org/guestfs.3.html#guestfs_vfs_label]).
 */
static VALUE
ruby_guestfs_vfs_label (VALUE gv, VALUE devicev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "vfs_label");

  const char *device = StringValueCStr (devicev);

  char *r;

  r = guestfs_vfs_label (g, device);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  VALUE rv = rb_str_new2 (r);
  free (r);
  return rv;
}

/*
 * call-seq:
 *   g.vfs_uuid(device) -> string
 *
 * get the filesystem UUID
 *
 * This returns the filesystem UUID of the filesystem on
 * "device".
 * 
 * If the filesystem does not have a UUID, this returns the
 * empty string.
 * 
 * To find a filesystem from the UUID, use "g.findfs_uuid".
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_vfs_uuid+[http://libguestfs.org/guestfs.3.html#guestfs_vfs_uuid]).
 */
static VALUE
ruby_guestfs_vfs_uuid (VALUE gv, VALUE devicev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "vfs_uuid");

  const char *device = StringValueCStr (devicev);

  char *r;

  r = guestfs_vfs_uuid (g, device);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  VALUE rv = rb_str_new2 (r);
  free (r);
  return rv;
}

/*
 * call-seq:
 *   g.lvm_set_filter(devices) -> nil
 *
 * set LVM device filter
 *
 * This sets the LVM device filter so that LVM will only be
 * able to "see" the block devices in the list "devices",
 * and will ignore all other attached block devices.
 * 
 * Where disk image(s) contain duplicate PVs or VGs, this
 * command is useful to get LVM to ignore the duplicates,
 * otherwise LVM can get confused. Note also there are two
 * types of duplication possible: either cloned PVs/VGs
 * which have identical UUIDs; or VGs that are not cloned
 * but just happen to have the same name. In normal
 * operation you cannot create this situation, but you can
 * do it outside LVM, eg. by cloning disk images or by bit
 * twiddling inside the LVM metadata.
 * 
 * This command also clears the LVM cache and performs a
 * volume group scan.
 * 
 * You can filter whole block devices or individual
 * partitions.
 * 
 * You cannot use this if any VG is currently in use (eg.
 * contains a mounted filesystem), even if you are not
 * filtering out that VG.
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_lvm_set_filter+[http://libguestfs.org/guestfs.3.html#guestfs_lvm_set_filter]).
 */
static VALUE
ruby_guestfs_lvm_set_filter (VALUE gv, VALUE devicesv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "lvm_set_filter");

  char **devices;
  Check_Type (devicesv, T_ARRAY);
  {
    size_t i, len;
    len = RARRAY_LEN (devicesv);
    devices = ALLOC_N (char *, len+1);
    for (i = 0; i < len; ++i) {
      VALUE v = rb_ary_entry (devicesv, i);
      devices[i] = StringValueCStr (v);
    }
    devices[len] = NULL;
  }

  int r;

  r = guestfs_lvm_set_filter (g, devices);
  free (devices);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.lvm_clear_filter() -> nil
 *
 * clear LVM device filter
 *
 * This undoes the effect of "g.lvm_set_filter". LVM will
 * be able to see every block device.
 * 
 * This command also clears the LVM cache and performs a
 * volume group scan.
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_lvm_clear_filter+[http://libguestfs.org/guestfs.3.html#guestfs_lvm_clear_filter]).
 */
static VALUE
ruby_guestfs_lvm_clear_filter (VALUE gv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "lvm_clear_filter");


  int r;

  r = guestfs_lvm_clear_filter (g);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.luks_open(device, key, mapname) -> nil
 *
 * open a LUKS-encrypted block device
 *
 * This command opens a block device which has been
 * encrypted according to the Linux Unified Key Setup
 * (LUKS) standard.
 * 
 * "device" is the encrypted block device or partition.
 * 
 * The caller must supply one of the keys associated with
 * the LUKS block device, in the "key" parameter.
 * 
 * This creates a new block device called
 * "/dev/mapper/mapname". Reads and writes to this block
 * device are decrypted from and encrypted to the
 * underlying "device" respectively.
 * 
 * If this block device contains LVM volume groups, then
 * calling "g.vgscan" followed by "g.vg_activate_all" will
 * make them visible.
 * 
 * Use "g.list_dm_devices" to list all device mapper
 * devices.
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_luks_open+[http://libguestfs.org/guestfs.3.html#guestfs_luks_open]).
 */
static VALUE
ruby_guestfs_luks_open (VALUE gv, VALUE devicev, VALUE keyv, VALUE mapnamev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "luks_open");

  const char *device = StringValueCStr (devicev);
  const char *key = StringValueCStr (keyv);
  const char *mapname = StringValueCStr (mapnamev);

  int r;

  r = guestfs_luks_open (g, device, key, mapname);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.luks_open_ro(device, key, mapname) -> nil
 *
 * open a LUKS-encrypted block device read-only
 *
 * This is the same as "g.luks_open" except that a
 * read-only mapping is created.
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_luks_open_ro+[http://libguestfs.org/guestfs.3.html#guestfs_luks_open_ro]).
 */
static VALUE
ruby_guestfs_luks_open_ro (VALUE gv, VALUE devicev, VALUE keyv, VALUE mapnamev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "luks_open_ro");

  const char *device = StringValueCStr (devicev);
  const char *key = StringValueCStr (keyv);
  const char *mapname = StringValueCStr (mapnamev);

  int r;

  r = guestfs_luks_open_ro (g, device, key, mapname);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.luks_close(device) -> nil
 *
 * close a LUKS device
 *
 * This closes a LUKS device that was created earlier by
 * "g.luks_open" or "g.luks_open_ro". The "device"
 * parameter must be the name of the LUKS mapping device
 * (ie. "/dev/mapper/mapname") and *not* the name of the
 * underlying block device.
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_luks_close+[http://libguestfs.org/guestfs.3.html#guestfs_luks_close]).
 */
static VALUE
ruby_guestfs_luks_close (VALUE gv, VALUE devicev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "luks_close");

  const char *device = StringValueCStr (devicev);

  int r;

  r = guestfs_luks_close (g, device);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.luks_format(device, key, keyslot) -> nil
 *
 * format a block device as a LUKS encrypted device
 *
 * This command erases existing data on "device" and
 * formats the device as a LUKS encrypted device. "key" is
 * the initial key, which is added to key slot "slot".
 * (LUKS supports 8 key slots, numbered 0-7).
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_luks_format+[http://libguestfs.org/guestfs.3.html#guestfs_luks_format]).
 */
static VALUE
ruby_guestfs_luks_format (VALUE gv, VALUE devicev, VALUE keyv, VALUE keyslotv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "luks_format");

  const char *device = StringValueCStr (devicev);
  const char *key = StringValueCStr (keyv);
  int keyslot = NUM2INT (keyslotv);

  int r;

  r = guestfs_luks_format (g, device, key, keyslot);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.luks_format_cipher(device, key, keyslot, cipher) -> nil
 *
 * format a block device as a LUKS encrypted device
 *
 * This command is the same as "g.luks_format" but it also
 * allows you to set the "cipher" used.
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_luks_format_cipher+[http://libguestfs.org/guestfs.3.html#guestfs_luks_format_cipher]).
 */
static VALUE
ruby_guestfs_luks_format_cipher (VALUE gv, VALUE devicev, VALUE keyv, VALUE keyslotv, VALUE cipherv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "luks_format_cipher");

  const char *device = StringValueCStr (devicev);
  const char *key = StringValueCStr (keyv);
  int keyslot = NUM2INT (keyslotv);
  const char *cipher = StringValueCStr (cipherv);

  int r;

  r = guestfs_luks_format_cipher (g, device, key, keyslot, cipher);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.luks_add_key(device, key, newkey, keyslot) -> nil
 *
 * add a key on a LUKS encrypted device
 *
 * This command adds a new key on LUKS device "device".
 * "key" is any existing key, and is used to access the
 * device. "newkey" is the new key to add. "keyslot" is the
 * key slot that will be replaced.
 * 
 * Note that if "keyslot" already contains a key, then this
 * command will fail. You have to use "g.luks_kill_slot"
 * first to remove that key.
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_luks_add_key+[http://libguestfs.org/guestfs.3.html#guestfs_luks_add_key]).
 */
static VALUE
ruby_guestfs_luks_add_key (VALUE gv, VALUE devicev, VALUE keyv, VALUE newkeyv, VALUE keyslotv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "luks_add_key");

  const char *device = StringValueCStr (devicev);
  const char *key = StringValueCStr (keyv);
  const char *newkey = StringValueCStr (newkeyv);
  int keyslot = NUM2INT (keyslotv);

  int r;

  r = guestfs_luks_add_key (g, device, key, newkey, keyslot);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.luks_kill_slot(device, key, keyslot) -> nil
 *
 * remove a key from a LUKS encrypted device
 *
 * This command deletes the key in key slot "keyslot" from
 * the encrypted LUKS device "device". "key" must be one of
 * the *other* keys.
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_luks_kill_slot+[http://libguestfs.org/guestfs.3.html#guestfs_luks_kill_slot]).
 */
static VALUE
ruby_guestfs_luks_kill_slot (VALUE gv, VALUE devicev, VALUE keyv, VALUE keyslotv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "luks_kill_slot");

  const char *device = StringValueCStr (devicev);
  const char *key = StringValueCStr (keyv);
  int keyslot = NUM2INT (keyslotv);

  int r;

  r = guestfs_luks_kill_slot (g, device, key, keyslot);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.is_lv(device) -> [True|False]
 *
 * test if device is a logical volume
 *
 * This command tests whether "device" is a logical volume,
 * and returns true iff this is the case.
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_is_lv+[http://libguestfs.org/guestfs.3.html#guestfs_is_lv]).
 */
static VALUE
ruby_guestfs_is_lv (VALUE gv, VALUE devicev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "is_lv");

  const char *device = StringValueCStr (devicev);

  int r;

  r = guestfs_is_lv (g, device);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return INT2NUM (r);
}

/*
 * call-seq:
 *   g.findfs_uuid(uuid) -> string
 *
 * find a filesystem by UUID
 *
 * This command searches the filesystems and returns the
 * one which has the given UUID. An error is returned if no
 * such filesystem can be found.
 * 
 * To find the UUID of a filesystem, use "g.vfs_uuid".
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_findfs_uuid+[http://libguestfs.org/guestfs.3.html#guestfs_findfs_uuid]).
 */
static VALUE
ruby_guestfs_findfs_uuid (VALUE gv, VALUE uuidv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "findfs_uuid");

  const char *uuid = StringValueCStr (uuidv);

  char *r;

  r = guestfs_findfs_uuid (g, uuid);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  VALUE rv = rb_str_new2 (r);
  free (r);
  return rv;
}

/*
 * call-seq:
 *   g.findfs_label(label) -> string
 *
 * find a filesystem by label
 *
 * This command searches the filesystems and returns the
 * one which has the given label. An error is returned if
 * no such filesystem can be found.
 * 
 * To find the label of a filesystem, use "g.vfs_label".
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_findfs_label+[http://libguestfs.org/guestfs.3.html#guestfs_findfs_label]).
 */
static VALUE
ruby_guestfs_findfs_label (VALUE gv, VALUE labelv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "findfs_label");

  const char *label = StringValueCStr (labelv);

  char *r;

  r = guestfs_findfs_label (g, label);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  VALUE rv = rb_str_new2 (r);
  free (r);
  return rv;
}

/*
 * call-seq:
 *   g.is_chardev(path) -> [True|False]
 *
 * test if character device
 *
 * This returns "true" if and only if there is a character
 * device with the given "path" name.
 * 
 * See also "g.stat".
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_is_chardev+[http://libguestfs.org/guestfs.3.html#guestfs_is_chardev]).
 */
static VALUE
ruby_guestfs_is_chardev (VALUE gv, VALUE pathv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "is_chardev");

  const char *path = StringValueCStr (pathv);

  int r;

  r = guestfs_is_chardev (g, path);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return INT2NUM (r);
}

/*
 * call-seq:
 *   g.is_blockdev(path) -> [True|False]
 *
 * test if block device
 *
 * This returns "true" if and only if there is a block
 * device with the given "path" name.
 * 
 * See also "g.stat".
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_is_blockdev+[http://libguestfs.org/guestfs.3.html#guestfs_is_blockdev]).
 */
static VALUE
ruby_guestfs_is_blockdev (VALUE gv, VALUE pathv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "is_blockdev");

  const char *path = StringValueCStr (pathv);

  int r;

  r = guestfs_is_blockdev (g, path);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return INT2NUM (r);
}

/*
 * call-seq:
 *   g.is_fifo(path) -> [True|False]
 *
 * test if FIFO (named pipe)
 *
 * This returns "true" if and only if there is a FIFO
 * (named pipe) with the given "path" name.
 * 
 * See also "g.stat".
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_is_fifo+[http://libguestfs.org/guestfs.3.html#guestfs_is_fifo]).
 */
static VALUE
ruby_guestfs_is_fifo (VALUE gv, VALUE pathv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "is_fifo");

  const char *path = StringValueCStr (pathv);

  int r;

  r = guestfs_is_fifo (g, path);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return INT2NUM (r);
}

/*
 * call-seq:
 *   g.is_symlink(path) -> [True|False]
 *
 * test if symbolic link
 *
 * This returns "true" if and only if there is a symbolic
 * link with the given "path" name.
 * 
 * See also "g.stat".
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_is_symlink+[http://libguestfs.org/guestfs.3.html#guestfs_is_symlink]).
 */
static VALUE
ruby_guestfs_is_symlink (VALUE gv, VALUE pathv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "is_symlink");

  const char *path = StringValueCStr (pathv);

  int r;

  r = guestfs_is_symlink (g, path);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return INT2NUM (r);
}

/*
 * call-seq:
 *   g.is_socket(path) -> [True|False]
 *
 * test if socket
 *
 * This returns "true" if and only if there is a Unix
 * domain socket with the given "path" name.
 * 
 * See also "g.stat".
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_is_socket+[http://libguestfs.org/guestfs.3.html#guestfs_is_socket]).
 */
static VALUE
ruby_guestfs_is_socket (VALUE gv, VALUE pathv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "is_socket");

  const char *path = StringValueCStr (pathv);

  int r;

  r = guestfs_is_socket (g, path);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return INT2NUM (r);
}

/*
 * call-seq:
 *   g.part_to_dev(partition) -> string
 *
 * convert partition name to device name
 *
 * This function takes a partition name (eg. "/dev/sdb1")
 * and removes the partition number, returning the device
 * name (eg. "/dev/sdb").
 * 
 * The named partition must exist, for example as a string
 * returned from "g.list_partitions".
 * 
 * See also "g.part_to_partnum".
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_part_to_dev+[http://libguestfs.org/guestfs.3.html#guestfs_part_to_dev]).
 */
static VALUE
ruby_guestfs_part_to_dev (VALUE gv, VALUE partitionv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "part_to_dev");

  const char *partition = StringValueCStr (partitionv);

  char *r;

  r = guestfs_part_to_dev (g, partition);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  VALUE rv = rb_str_new2 (r);
  free (r);
  return rv;
}

/*
 * call-seq:
 *   g.upload_offset(filename, remotefilename, offset) -> nil
 *
 * upload a file from the local machine with offset
 *
 * Upload local file "filename" to "remotefilename" on the
 * filesystem.
 * 
 * "remotefilename" is overwritten starting at the byte
 * "offset" specified. The intention is to overwrite parts
 * of existing files or devices, although if a non-existant
 * file is specified then it is created with a "hole"
 * before "offset". The size of the data written is
 * implicit in the size of the source "filename".
 * 
 * Note that there is no limit on the amount of data that
 * can be uploaded with this call, unlike with "g.pwrite",
 * and this call always writes the full amount unless an
 * error occurs.
 * 
 * See also "g.upload", "g.pwrite".
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_upload_offset+[http://libguestfs.org/guestfs.3.html#guestfs_upload_offset]).
 */
static VALUE
ruby_guestfs_upload_offset (VALUE gv, VALUE filenamev, VALUE remotefilenamev, VALUE offsetv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "upload_offset");

  const char *filename = StringValueCStr (filenamev);
  const char *remotefilename = StringValueCStr (remotefilenamev);
  long long offset = NUM2LL (offsetv);

  int r;

  r = guestfs_upload_offset (g, filename, remotefilename, offset);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.download_offset(remotefilename, filename, offset, size) -> nil
 *
 * download a file to the local machine with offset and size
 *
 * Download file "remotefilename" and save it as "filename"
 * on the local machine.
 * 
 * "remotefilename" is read for "size" bytes starting at
 * "offset" (this region must be within the file or
 * device).
 * 
 * Note that there is no limit on the amount of data that
 * can be downloaded with this call, unlike with "g.pread",
 * and this call always reads the full amount unless an
 * error occurs.
 * 
 * See also "g.download", "g.pread".
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_download_offset+[http://libguestfs.org/guestfs.3.html#guestfs_download_offset]).
 */
static VALUE
ruby_guestfs_download_offset (VALUE gv, VALUE remotefilenamev, VALUE filenamev, VALUE offsetv, VALUE sizev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "download_offset");

  const char *remotefilename = StringValueCStr (remotefilenamev);
  const char *filename = StringValueCStr (filenamev);
  long long offset = NUM2LL (offsetv);
  long long size = NUM2LL (sizev);

  int r;

  r = guestfs_download_offset (g, remotefilename, filename, offset, size);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.pwrite_device(device, content, offset) -> fixnum
 *
 * write to part of a device
 *
 * This command writes to part of a device. It writes the
 * data buffer "content" to "device" starting at offset
 * "offset".
 * 
 * This command implements the pwrite(2) system call, and
 * like that system call it may not write the full data
 * requested (although short writes to disk devices and
 * partitions are probably impossible with standard Linux
 * kernels).
 * 
 * See also "g.pwrite".
 * 
 * Because of the message protocol, there is a transfer
 * limit of somewhere between 2MB and 4MB. See "PROTOCOL
 * LIMITS" in guestfs(3).
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_pwrite_device+[http://libguestfs.org/guestfs.3.html#guestfs_pwrite_device]).
 */
static VALUE
ruby_guestfs_pwrite_device (VALUE gv, VALUE devicev, VALUE contentv, VALUE offsetv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "pwrite_device");

  const char *device = StringValueCStr (devicev);
  Check_Type (contentv, T_STRING);
  const char *content = RSTRING (contentv)->ptr;
  if (!content)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "content", "pwrite_device");
  size_t content_size = RSTRING (contentv)->len;
  long long offset = NUM2LL (offsetv);

  int r;

  r = guestfs_pwrite_device (g, device, content, content_size, offset);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return INT2NUM (r);
}

/*
 * call-seq:
 *   g.pread_device(device, count, offset) -> string
 *
 * read part of a device
 *
 * This command lets you read part of a file. It reads
 * "count" bytes of "device", starting at "offset".
 * 
 * This may read fewer bytes than requested. For further
 * details see the pread(2) system call.
 * 
 * See also "g.pread".
 * 
 * Because of the message protocol, there is a transfer
 * limit of somewhere between 2MB and 4MB. See "PROTOCOL
 * LIMITS" in guestfs(3).
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_pread_device+[http://libguestfs.org/guestfs.3.html#guestfs_pread_device]).
 */
static VALUE
ruby_guestfs_pread_device (VALUE gv, VALUE devicev, VALUE countv, VALUE offsetv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "pread_device");

  const char *device = StringValueCStr (devicev);
  int count = NUM2INT (countv);
  long long offset = NUM2LL (offsetv);

  char *r;
  size_t size;

  r = guestfs_pread_device (g, device, count, offset, &size);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  VALUE rv = rb_str_new (r, size);
  free (r);
  return rv;
}

/*
 * call-seq:
 *   g.lvm_canonical_lv_name(lvname) -> string
 *
 * get canonical name of an LV
 *
 * This converts alternative naming schemes for LVs that
 * you might find to the canonical name. For example,
 * "/dev/mapper/VG-LV" is converted to "/dev/VG/LV".
 * 
 * This command returns an error if the "lvname" parameter
 * does not refer to a logical volume.
 * 
 * See also "g.is_lv".
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_lvm_canonical_lv_name+[http://libguestfs.org/guestfs.3.html#guestfs_lvm_canonical_lv_name]).
 */
static VALUE
ruby_guestfs_lvm_canonical_lv_name (VALUE gv, VALUE lvnamev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "lvm_canonical_lv_name");

  const char *lvname = StringValueCStr (lvnamev);

  char *r;

  r = guestfs_lvm_canonical_lv_name (g, lvname);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  VALUE rv = rb_str_new2 (r);
  free (r);
  return rv;
}

/*
 * call-seq:
 *   g.mkfs_opts(fstype, device, {optargs...}) -> nil
 *
 * make a filesystem
 *
 * This function creates a filesystem on "device". The
 * filesystem type is "fstype", for example "ext3".
 * 
 * The optional arguments are:
 * 
 * "blocksize"
 * The filesystem block size. Supported block sizes
 * depend on the filesystem type, but typically they
 * are 1024, 2048 or 4096 for Linux ext2/3 filesystems.
 * 
 * For VFAT and NTFS the "blocksize" parameter is
 * treated as the requested cluster size.
 * 
 * For UFS block sizes, please see mkfs.ufs(8).
 * 
 * "features"
 * This passes the *-O* parameter to the external mkfs
 * program.
 * 
 * For certain filesystem types, this allows extra
 * filesystem features to be selected. See mke2fs(8)
 * and mkfs.ufs(8) for more details.
 * 
 * You cannot use this optional parameter with the
 * "gfs" or "gfs2" filesystem type.
 * 
 * "inode"
 * This passes the *-I* parameter to the external
 * mke2fs(8) program which sets the inode size (only
 * for ext2/3/4 filesystems at present).
 * 
 * "sectorsize"
 * This passes the *-S* parameter to external
 * mkfs.ufs(8) program, which sets sector size for ufs
 * filesystem.
 * 
 * Optional arguments are supplied in the final hash
 * parameter, which is a hash of the argument name to its
 * value. Pass an empty {} for no optional arguments.
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_mkfs_opts+[http://libguestfs.org/guestfs.3.html#guestfs_mkfs_opts]).
 */
static VALUE
ruby_guestfs_mkfs_opts (VALUE gv, VALUE fstypev, VALUE devicev, VALUE optargsv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "mkfs_opts");

  const char *fstype = StringValueCStr (fstypev);
  const char *device = StringValueCStr (devicev);

  Check_Type (optargsv, T_HASH);
  struct guestfs_mkfs_opts_argv optargs_s = { .bitmask = 0 };
  struct guestfs_mkfs_opts_argv *optargs = &optargs_s;
  VALUE v;
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("blocksize")));
  if (v != Qnil) {
    optargs_s.blocksize = NUM2INT (v);
    optargs_s.bitmask |= GUESTFS_MKFS_OPTS_BLOCKSIZE_BITMASK;
  }
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("features")));
  if (v != Qnil) {
    optargs_s.features = StringValueCStr (v);
    optargs_s.bitmask |= GUESTFS_MKFS_OPTS_FEATURES_BITMASK;
  }
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("inode")));
  if (v != Qnil) {
    optargs_s.inode = NUM2INT (v);
    optargs_s.bitmask |= GUESTFS_MKFS_OPTS_INODE_BITMASK;
  }
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("sectorsize")));
  if (v != Qnil) {
    optargs_s.sectorsize = NUM2INT (v);
    optargs_s.bitmask |= GUESTFS_MKFS_OPTS_SECTORSIZE_BITMASK;
  }

  int r;

  r = guestfs_mkfs_opts_argv (g, fstype, device, optargs);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.getxattr(path, name) -> string
 *
 * get a single extended attribute
 *
 * Get a single extended attribute from file "path" named
 * "name". This call follows symlinks. If you want to
 * lookup an extended attribute for the symlink itself, use
 * "g.lgetxattr".
 * 
 * Normally it is better to get all extended attributes
 * from a file in one go by calling "g.getxattrs". However
 * some Linux filesystem implementations are buggy and do
 * not provide a way to list out attributes. For these
 * filesystems (notably ntfs-3g) you have to know the names
 * of the extended attributes you want in advance and call
 * this function.
 * 
 * Extended attribute values are blobs of binary data. If
 * there is no extended attribute named "name", this
 * returns an error.
 * 
 * See also: "g.getxattrs", "g.lgetxattr", attr(5).
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_getxattr+[http://libguestfs.org/guestfs.3.html#guestfs_getxattr]).
 */
static VALUE
ruby_guestfs_getxattr (VALUE gv, VALUE pathv, VALUE namev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "getxattr");

  const char *path = StringValueCStr (pathv);
  const char *name = StringValueCStr (namev);

  char *r;
  size_t size;

  r = guestfs_getxattr (g, path, name, &size);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  VALUE rv = rb_str_new (r, size);
  free (r);
  return rv;
}

/*
 * call-seq:
 *   g.lgetxattr(path, name) -> string
 *
 * get a single extended attribute
 *
 * Get a single extended attribute from file "path" named
 * "name". If "path" is a symlink, then this call returns
 * an extended attribute from the symlink.
 * 
 * Normally it is better to get all extended attributes
 * from a file in one go by calling "g.getxattrs". However
 * some Linux filesystem implementations are buggy and do
 * not provide a way to list out attributes. For these
 * filesystems (notably ntfs-3g) you have to know the names
 * of the extended attributes you want in advance and call
 * this function.
 * 
 * Extended attribute values are blobs of binary data. If
 * there is no extended attribute named "name", this
 * returns an error.
 * 
 * See also: "g.lgetxattrs", "g.getxattr", attr(5).
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_lgetxattr+[http://libguestfs.org/guestfs.3.html#guestfs_lgetxattr]).
 */
static VALUE
ruby_guestfs_lgetxattr (VALUE gv, VALUE pathv, VALUE namev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "lgetxattr");

  const char *path = StringValueCStr (pathv);
  const char *name = StringValueCStr (namev);

  char *r;
  size_t size;

  r = guestfs_lgetxattr (g, path, name, &size);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  VALUE rv = rb_str_new (r, size);
  free (r);
  return rv;
}

/*
 * call-seq:
 *   g.resize2fs_M(device) -> nil
 *
 * resize an ext2, ext3 or ext4 filesystem to the minimum size
 *
 * This command is the same as "g.resize2fs", but the
 * filesystem is resized to its minimum size. This works
 * like the *-M* option to the "resize2fs" command.
 * 
 * To get the resulting size of the filesystem you should
 * call "g.tune2fs_l" and read the "Block size" and "Block
 * count" values. These two numbers, multiplied together,
 * give the resulting size of the minimal filesystem in
 * bytes.
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_resize2fs_M+[http://libguestfs.org/guestfs.3.html#guestfs_resize2fs_M]).
 */
static VALUE
ruby_guestfs_resize2fs_M (VALUE gv, VALUE devicev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "resize2fs_M");

  const char *device = StringValueCStr (devicev);

  int r;

  r = guestfs_resize2fs_M (g, device);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

static VALUE
ruby_guestfs_internal_autosync (VALUE gv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "internal_autosync");


  int r;

  r = guestfs_internal_autosync (g);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.is_zero(path) -> [True|False]
 *
 * test if a file contains all zero bytes
 *
 * This returns true iff the file exists and the file is
 * empty or it contains all zero bytes.
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_is_zero+[http://libguestfs.org/guestfs.3.html#guestfs_is_zero]).
 */
static VALUE
ruby_guestfs_is_zero (VALUE gv, VALUE pathv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "is_zero");

  const char *path = StringValueCStr (pathv);

  int r;

  r = guestfs_is_zero (g, path);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return INT2NUM (r);
}

/*
 * call-seq:
 *   g.is_zero_device(device) -> [True|False]
 *
 * test if a device contains all zero bytes
 *
 * This returns true iff the device exists and contains all
 * zero bytes.
 * 
 * Note that for large devices this can take a long time to
 * run.
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_is_zero_device+[http://libguestfs.org/guestfs.3.html#guestfs_is_zero_device]).
 */
static VALUE
ruby_guestfs_is_zero_device (VALUE gv, VALUE devicev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "is_zero_device");

  const char *device = StringValueCStr (devicev);

  int r;

  r = guestfs_is_zero_device (g, device);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return INT2NUM (r);
}

/*
 * call-seq:
 *   g.list_9p() -> list
 *
 * list 9p filesystems
 *
 * List all 9p filesystems attached to the guest. A list of
 * mount tags is returned.
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_list_9p+[http://libguestfs.org/guestfs.3.html#guestfs_list_9p]).
 */
static VALUE
ruby_guestfs_list_9p (VALUE gv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "list_9p");


  char **r;

  r = guestfs_list_9p (g);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  size_t i, len = 0;
  for (i = 0; r[i] != NULL; ++i) len++;
  VALUE rv = rb_ary_new2 (len);
  for (i = 0; r[i] != NULL; ++i) {
    rb_ary_push (rv, rb_str_new2 (r[i]));
    free (r[i]);
  }
  free (r);
  return rv;
}

/*
 * call-seq:
 *   g.mount_9p(mounttag, mountpoint, {optargs...}) -> nil
 *
 * mount 9p filesystem
 *
 * Mount the virtio-9p filesystem with the tag "mounttag"
 * on the directory "mountpoint".
 * 
 * If required, "trans=virtio" will be automatically added
 * to the options. Any other options required can be passed
 * in the optional "options" parameter.
 * 
 * Optional arguments are supplied in the final hash
 * parameter, which is a hash of the argument name to its
 * value. Pass an empty {} for no optional arguments.
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_mount_9p+[http://libguestfs.org/guestfs.3.html#guestfs_mount_9p]).
 */
static VALUE
ruby_guestfs_mount_9p (VALUE gv, VALUE mounttagv, VALUE mountpointv, VALUE optargsv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "mount_9p");

  const char *mounttag = StringValueCStr (mounttagv);
  const char *mountpoint = StringValueCStr (mountpointv);

  Check_Type (optargsv, T_HASH);
  struct guestfs_mount_9p_argv optargs_s = { .bitmask = 0 };
  struct guestfs_mount_9p_argv *optargs = &optargs_s;
  VALUE v;
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("options")));
  if (v != Qnil) {
    optargs_s.options = StringValueCStr (v);
    optargs_s.bitmask |= GUESTFS_MOUNT_9P_OPTIONS_BITMASK;
  }

  int r;

  r = guestfs_mount_9p_argv (g, mounttag, mountpoint, optargs);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.list_dm_devices() -> list
 *
 * list device mapper devices
 *
 * List all device mapper devices.
 * 
 * The returned list contains "/dev/mapper/*" devices, eg.
 * ones created by a previous call to "g.luks_open".
 * 
 * Device mapper devices which correspond to logical
 * volumes are *not* returned in this list. Call "g.lvs" if
 * you want to list logical volumes.
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_list_dm_devices+[http://libguestfs.org/guestfs.3.html#guestfs_list_dm_devices]).
 */
static VALUE
ruby_guestfs_list_dm_devices (VALUE gv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "list_dm_devices");


  char **r;

  r = guestfs_list_dm_devices (g);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  size_t i, len = 0;
  for (i = 0; r[i] != NULL; ++i) len++;
  VALUE rv = rb_ary_new2 (len);
  for (i = 0; r[i] != NULL; ++i) {
    rb_ary_push (rv, rb_str_new2 (r[i]));
    free (r[i]);
  }
  free (r);
  return rv;
}

/*
 * call-seq:
 *   g.ntfsresize_opts(device, {optargs...}) -> nil
 *
 * resize an NTFS filesystem
 *
 * This command resizes an NTFS filesystem, expanding or
 * shrinking it to the size of the underlying device.
 * 
 * The optional parameters are:
 * 
 * "size"
 * The new size (in bytes) of the filesystem. If
 * omitted, the filesystem is resized to fit the
 * container (eg. partition).
 * 
 * "force"
 * If this option is true, then force the resize of the
 * filesystem even if the filesystem is marked as
 * requiring a consistency check.
 * 
 * After the resize operation, the filesystem is always
 * marked as requiring a consistency check (for
 * safety). You have to boot into Windows to perform
 * this check and clear this condition. If you *don't*
 * set the "force" option then it is not possible to
 * call "g.ntfsresize_opts" multiple times on a single
 * filesystem without booting into Windows between each
 * resize.
 * 
 * See also ntfsresize(8).
 * 
 * Optional arguments are supplied in the final hash
 * parameter, which is a hash of the argument name to its
 * value. Pass an empty {} for no optional arguments.
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_ntfsresize_opts+[http://libguestfs.org/guestfs.3.html#guestfs_ntfsresize_opts]).
 */
static VALUE
ruby_guestfs_ntfsresize_opts (VALUE gv, VALUE devicev, VALUE optargsv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "ntfsresize_opts");

  const char *device = StringValueCStr (devicev);

  Check_Type (optargsv, T_HASH);
  struct guestfs_ntfsresize_opts_argv optargs_s = { .bitmask = 0 };
  struct guestfs_ntfsresize_opts_argv *optargs = &optargs_s;
  VALUE v;
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("size")));
  if (v != Qnil) {
    optargs_s.size = NUM2LL (v);
    optargs_s.bitmask |= GUESTFS_NTFSRESIZE_OPTS_SIZE_BITMASK;
  }
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("force")));
  if (v != Qnil) {
    optargs_s.force = RTEST (v);
    optargs_s.bitmask |= GUESTFS_NTFSRESIZE_OPTS_FORCE_BITMASK;
  }

  int r;

  r = guestfs_ntfsresize_opts_argv (g, device, optargs);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.btrfs_filesystem_resize(mountpoint, {optargs...}) -> nil
 *
 * resize a btrfs filesystem
 *
 * This command resizes a btrfs filesystem.
 * 
 * Note that unlike other resize calls, the filesystem has
 * to be mounted and the parameter is the mountpoint not
 * the device (this is a requirement of btrfs itself).
 * 
 * The optional parameters are:
 * 
 * "size"
 * The new size (in bytes) of the filesystem. If
 * omitted, the filesystem is resized to the maximum
 * size.
 * 
 * See also btrfs(8).
 * 
 * Optional arguments are supplied in the final hash
 * parameter, which is a hash of the argument name to its
 * value. Pass an empty {} for no optional arguments.
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_btrfs_filesystem_resize+[http://libguestfs.org/guestfs.3.html#guestfs_btrfs_filesystem_resize]).
 */
static VALUE
ruby_guestfs_btrfs_filesystem_resize (VALUE gv, VALUE mountpointv, VALUE optargsv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "btrfs_filesystem_resize");

  const char *mountpoint = StringValueCStr (mountpointv);

  Check_Type (optargsv, T_HASH);
  struct guestfs_btrfs_filesystem_resize_argv optargs_s = { .bitmask = 0 };
  struct guestfs_btrfs_filesystem_resize_argv *optargs = &optargs_s;
  VALUE v;
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("size")));
  if (v != Qnil) {
    optargs_s.size = NUM2LL (v);
    optargs_s.bitmask |= GUESTFS_BTRFS_FILESYSTEM_RESIZE_SIZE_BITMASK;
  }

  int r;

  r = guestfs_btrfs_filesystem_resize_argv (g, mountpoint, optargs);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.write_append(path, content) -> nil
 *
 * append content to end of file
 *
 * This call appends "content" to the end of file "path".
 * If "path" does not exist, then a new file is created.
 * 
 * See also "g.write".
 * 
 * Because of the message protocol, there is a transfer
 * limit of somewhere between 2MB and 4MB. See "PROTOCOL
 * LIMITS" in guestfs(3).
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_write_append+[http://libguestfs.org/guestfs.3.html#guestfs_write_append]).
 */
static VALUE
ruby_guestfs_write_append (VALUE gv, VALUE pathv, VALUE contentv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "write_append");

  const char *path = StringValueCStr (pathv);
  Check_Type (contentv, T_STRING);
  const char *content = RSTRING (contentv)->ptr;
  if (!content)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "content", "write_append");
  size_t content_size = RSTRING (contentv)->len;

  int r;

  r = guestfs_write_append (g, path, content, content_size);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.compress_out(ctype, file, zfile, {optargs...}) -> nil
 *
 * output compressed file
 *
 * This command compresses "file" and writes it out to the
 * local file "zfile".
 * 
 * The compression program used is controlled by the
 * "ctype" parameter. Currently this includes: "compress",
 * "gzip", "bzip2", "xz" or "lzop". Some compression types
 * may not be supported by particular builds of libguestfs,
 * in which case you will get an error containing the
 * substring "not supported".
 * 
 * The optional "level" parameter controls compression
 * level. The meaning and default for this parameter
 * depends on the compression program being used.
 * 
 * Optional arguments are supplied in the final hash
 * parameter, which is a hash of the argument name to its
 * value. Pass an empty {} for no optional arguments.
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_compress_out+[http://libguestfs.org/guestfs.3.html#guestfs_compress_out]).
 */
static VALUE
ruby_guestfs_compress_out (VALUE gv, VALUE ctypev, VALUE filev, VALUE zfilev, VALUE optargsv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "compress_out");

  const char *ctype = StringValueCStr (ctypev);
  const char *file = StringValueCStr (filev);
  const char *zfile = StringValueCStr (zfilev);

  Check_Type (optargsv, T_HASH);
  struct guestfs_compress_out_argv optargs_s = { .bitmask = 0 };
  struct guestfs_compress_out_argv *optargs = &optargs_s;
  VALUE v;
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("level")));
  if (v != Qnil) {
    optargs_s.level = NUM2INT (v);
    optargs_s.bitmask |= GUESTFS_COMPRESS_OUT_LEVEL_BITMASK;
  }

  int r;

  r = guestfs_compress_out_argv (g, ctype, file, zfile, optargs);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.compress_device_out(ctype, device, zdevice, {optargs...}) -> nil
 *
 * output compressed device
 *
 * This command compresses "device" and writes it out to
 * the local file "zdevice".
 * 
 * The "ctype" and optional "level" parameters have the
 * same meaning as in "g.compress_out".
 * 
 * Optional arguments are supplied in the final hash
 * parameter, which is a hash of the argument name to its
 * value. Pass an empty {} for no optional arguments.
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_compress_device_out+[http://libguestfs.org/guestfs.3.html#guestfs_compress_device_out]).
 */
static VALUE
ruby_guestfs_compress_device_out (VALUE gv, VALUE ctypev, VALUE devicev, VALUE zdevicev, VALUE optargsv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "compress_device_out");

  const char *ctype = StringValueCStr (ctypev);
  const char *device = StringValueCStr (devicev);
  const char *zdevice = StringValueCStr (zdevicev);

  Check_Type (optargsv, T_HASH);
  struct guestfs_compress_device_out_argv optargs_s = { .bitmask = 0 };
  struct guestfs_compress_device_out_argv *optargs = &optargs_s;
  VALUE v;
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("level")));
  if (v != Qnil) {
    optargs_s.level = NUM2INT (v);
    optargs_s.bitmask |= GUESTFS_COMPRESS_DEVICE_OUT_LEVEL_BITMASK;
  }

  int r;

  r = guestfs_compress_device_out_argv (g, ctype, device, zdevice, optargs);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.part_to_partnum(partition) -> fixnum
 *
 * convert partition name to partition number
 *
 * This function takes a partition name (eg. "/dev/sdb1")
 * and returns the partition number (eg. 1).
 * 
 * The named partition must exist, for example as a string
 * returned from "g.list_partitions".
 * 
 * See also "g.part_to_dev".
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_part_to_partnum+[http://libguestfs.org/guestfs.3.html#guestfs_part_to_partnum]).
 */
static VALUE
ruby_guestfs_part_to_partnum (VALUE gv, VALUE partitionv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "part_to_partnum");

  const char *partition = StringValueCStr (partitionv);

  int r;

  r = guestfs_part_to_partnum (g, partition);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return INT2NUM (r);
}

/*
 * call-seq:
 *   g.copy_device_to_device(src, dest, {optargs...}) -> nil
 *
 * copy from source device to destination device
 *
 * The four calls "g.copy_device_to_device",
 * "g.copy_device_to_file", "g.copy_file_to_device", and
 * "g.copy_file_to_file" let you copy from a source
 * (device|file) to a destination (device|file).
 * 
 * Partial copies can be made since you can specify
 * optionally the source offset, destination offset and
 * size to copy. These values are all specified in bytes.
 * If not given, the offsets both default to zero, and the
 * size defaults to copying as much as possible until we
 * hit the end of the source.
 * 
 * The source and destination may be the same object.
 * However overlapping regions may not be copied correctly.
 * 
 * If the destination is a file, it is created if required.
 * If the destination file is not large enough, it is
 * extended.
 * 
 * Optional arguments are supplied in the final hash
 * parameter, which is a hash of the argument name to its
 * value. Pass an empty {} for no optional arguments.
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_copy_device_to_device+[http://libguestfs.org/guestfs.3.html#guestfs_copy_device_to_device]).
 */
static VALUE
ruby_guestfs_copy_device_to_device (VALUE gv, VALUE srcv, VALUE destv, VALUE optargsv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "copy_device_to_device");

  const char *src = StringValueCStr (srcv);
  const char *dest = StringValueCStr (destv);

  Check_Type (optargsv, T_HASH);
  struct guestfs_copy_device_to_device_argv optargs_s = { .bitmask = 0 };
  struct guestfs_copy_device_to_device_argv *optargs = &optargs_s;
  VALUE v;
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("srcoffset")));
  if (v != Qnil) {
    optargs_s.srcoffset = NUM2LL (v);
    optargs_s.bitmask |= GUESTFS_COPY_DEVICE_TO_DEVICE_SRCOFFSET_BITMASK;
  }
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("destoffset")));
  if (v != Qnil) {
    optargs_s.destoffset = NUM2LL (v);
    optargs_s.bitmask |= GUESTFS_COPY_DEVICE_TO_DEVICE_DESTOFFSET_BITMASK;
  }
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("size")));
  if (v != Qnil) {
    optargs_s.size = NUM2LL (v);
    optargs_s.bitmask |= GUESTFS_COPY_DEVICE_TO_DEVICE_SIZE_BITMASK;
  }

  int r;

  r = guestfs_copy_device_to_device_argv (g, src, dest, optargs);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.copy_device_to_file(src, dest, {optargs...}) -> nil
 *
 * copy from source device to destination file
 *
 * See "g.copy_device_to_device" for a general overview of
 * this call.
 * 
 * Optional arguments are supplied in the final hash
 * parameter, which is a hash of the argument name to its
 * value. Pass an empty {} for no optional arguments.
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_copy_device_to_file+[http://libguestfs.org/guestfs.3.html#guestfs_copy_device_to_file]).
 */
static VALUE
ruby_guestfs_copy_device_to_file (VALUE gv, VALUE srcv, VALUE destv, VALUE optargsv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "copy_device_to_file");

  const char *src = StringValueCStr (srcv);
  const char *dest = StringValueCStr (destv);

  Check_Type (optargsv, T_HASH);
  struct guestfs_copy_device_to_file_argv optargs_s = { .bitmask = 0 };
  struct guestfs_copy_device_to_file_argv *optargs = &optargs_s;
  VALUE v;
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("srcoffset")));
  if (v != Qnil) {
    optargs_s.srcoffset = NUM2LL (v);
    optargs_s.bitmask |= GUESTFS_COPY_DEVICE_TO_FILE_SRCOFFSET_BITMASK;
  }
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("destoffset")));
  if (v != Qnil) {
    optargs_s.destoffset = NUM2LL (v);
    optargs_s.bitmask |= GUESTFS_COPY_DEVICE_TO_FILE_DESTOFFSET_BITMASK;
  }
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("size")));
  if (v != Qnil) {
    optargs_s.size = NUM2LL (v);
    optargs_s.bitmask |= GUESTFS_COPY_DEVICE_TO_FILE_SIZE_BITMASK;
  }

  int r;

  r = guestfs_copy_device_to_file_argv (g, src, dest, optargs);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.copy_file_to_device(src, dest, {optargs...}) -> nil
 *
 * copy from source file to destination device
 *
 * See "g.copy_device_to_device" for a general overview of
 * this call.
 * 
 * Optional arguments are supplied in the final hash
 * parameter, which is a hash of the argument name to its
 * value. Pass an empty {} for no optional arguments.
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_copy_file_to_device+[http://libguestfs.org/guestfs.3.html#guestfs_copy_file_to_device]).
 */
static VALUE
ruby_guestfs_copy_file_to_device (VALUE gv, VALUE srcv, VALUE destv, VALUE optargsv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "copy_file_to_device");

  const char *src = StringValueCStr (srcv);
  const char *dest = StringValueCStr (destv);

  Check_Type (optargsv, T_HASH);
  struct guestfs_copy_file_to_device_argv optargs_s = { .bitmask = 0 };
  struct guestfs_copy_file_to_device_argv *optargs = &optargs_s;
  VALUE v;
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("srcoffset")));
  if (v != Qnil) {
    optargs_s.srcoffset = NUM2LL (v);
    optargs_s.bitmask |= GUESTFS_COPY_FILE_TO_DEVICE_SRCOFFSET_BITMASK;
  }
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("destoffset")));
  if (v != Qnil) {
    optargs_s.destoffset = NUM2LL (v);
    optargs_s.bitmask |= GUESTFS_COPY_FILE_TO_DEVICE_DESTOFFSET_BITMASK;
  }
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("size")));
  if (v != Qnil) {
    optargs_s.size = NUM2LL (v);
    optargs_s.bitmask |= GUESTFS_COPY_FILE_TO_DEVICE_SIZE_BITMASK;
  }

  int r;

  r = guestfs_copy_file_to_device_argv (g, src, dest, optargs);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.copy_file_to_file(src, dest, {optargs...}) -> nil
 *
 * copy from source file to destination file
 *
 * See "g.copy_device_to_device" for a general overview of
 * this call.
 * 
 * This is not the function you want for copying files.
 * This is for copying blocks within existing files. See
 * "g.cp", "g.cp_a" and "g.mv" for general file copying and
 * moving functions.
 * 
 * Optional arguments are supplied in the final hash
 * parameter, which is a hash of the argument name to its
 * value. Pass an empty {} for no optional arguments.
 *
 *
 * (For the C API documentation for this function, see
 * +guestfs_copy_file_to_file+[http://libguestfs.org/guestfs.3.html#guestfs_copy_file_to_file]).
 */
static VALUE
ruby_guestfs_copy_file_to_file (VALUE gv, VALUE srcv, VALUE destv, VALUE optargsv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "copy_file_to_file");

  const char *src = StringValueCStr (srcv);
  const char *dest = StringValueCStr (destv);

  Check_Type (optargsv, T_HASH);
  struct guestfs_copy_file_to_file_argv optargs_s = { .bitmask = 0 };
  struct guestfs_copy_file_to_file_argv *optargs = &optargs_s;
  VALUE v;
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("srcoffset")));
  if (v != Qnil) {
    optargs_s.srcoffset = NUM2LL (v);
    optargs_s.bitmask |= GUESTFS_COPY_FILE_TO_FILE_SRCOFFSET_BITMASK;
  }
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("destoffset")));
  if (v != Qnil) {
    optargs_s.destoffset = NUM2LL (v);
    optargs_s.bitmask |= GUESTFS_COPY_FILE_TO_FILE_DESTOFFSET_BITMASK;
  }
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("size")));
  if (v != Qnil) {
    optargs_s.size = NUM2LL (v);
    optargs_s.bitmask |= GUESTFS_COPY_FILE_TO_FILE_SIZE_BITMASK;
  }

  int r;

  r = guestfs_copy_file_to_file_argv (g, src, dest, optargs);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/* Initialize the module. */
void Init__guestfs ()
{
  m_guestfs = rb_define_module ("Guestfs");
  c_guestfs = rb_define_class_under (m_guestfs, "Guestfs", rb_cObject);
  e_Error = rb_define_class_under (m_guestfs, "Error", rb_eStandardError);

#ifdef HAVE_RB_DEFINE_ALLOC_FUNC
  rb_define_alloc_func (c_guestfs, ruby_guestfs_create);
#endif

  rb_define_module_function (m_guestfs, "create", ruby_guestfs_create, 0);
  rb_define_method (c_guestfs, "close", ruby_guestfs_close, 0);
  rb_define_method (c_guestfs, "set_event_callback",
                    ruby_set_event_callback, 2);
  rb_define_method (c_guestfs, "delete_event_callback",
                    ruby_delete_event_callback, 1);
  rb_define_method (c_guestfs, "user_cancel",
                    ruby_user_cancel, 0);

  rb_define_const (m_guestfs, "EVENT_CLOSE",
                   ULL2NUM (UINT64_C (0x1)));
  rb_define_const (m_guestfs, "EVENT_SUBPROCESS_QUIT",
                   ULL2NUM (UINT64_C (0x2)));
  rb_define_const (m_guestfs, "EVENT_LAUNCH_DONE",
                   ULL2NUM (UINT64_C (0x4)));
  rb_define_const (m_guestfs, "EVENT_PROGRESS",
                   ULL2NUM (UINT64_C (0x8)));
  rb_define_const (m_guestfs, "EVENT_APPLIANCE",
                   ULL2NUM (UINT64_C (0x10)));
  rb_define_const (m_guestfs, "EVENT_LIBRARY",
                   ULL2NUM (UINT64_C (0x20)));
  rb_define_const (m_guestfs, "EVENT_TRACE",
                   ULL2NUM (UINT64_C (0x40)));
  rb_define_const (m_guestfs, "EVENT_ENTER",
                   ULL2NUM (UINT64_C (0x80)));

  rb_define_method (c_guestfs, "test0",
        ruby_guestfs_test0, 9);
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
  rb_define_method (c_guestfs, "file_architecture",
        ruby_guestfs_file_architecture, 1);
  rb_define_method (c_guestfs, "inspect_os",
        ruby_guestfs_inspect_os, 0);
  rb_define_method (c_guestfs, "inspect_get_type",
        ruby_guestfs_inspect_get_type, 1);
  rb_define_method (c_guestfs, "inspect_get_arch",
        ruby_guestfs_inspect_get_arch, 1);
  rb_define_method (c_guestfs, "inspect_get_distro",
        ruby_guestfs_inspect_get_distro, 1);
  rb_define_method (c_guestfs, "inspect_get_major_version",
        ruby_guestfs_inspect_get_major_version, 1);
  rb_define_method (c_guestfs, "inspect_get_minor_version",
        ruby_guestfs_inspect_get_minor_version, 1);
  rb_define_method (c_guestfs, "inspect_get_product_name",
        ruby_guestfs_inspect_get_product_name, 1);
  rb_define_method (c_guestfs, "inspect_get_mountpoints",
        ruby_guestfs_inspect_get_mountpoints, 1);
  rb_define_method (c_guestfs, "inspect_get_filesystems",
        ruby_guestfs_inspect_get_filesystems, 1);
  rb_define_method (c_guestfs, "set_network",
        ruby_guestfs_set_network, 1);
  rb_define_method (c_guestfs, "get_network",
        ruby_guestfs_get_network, 0);
  rb_define_method (c_guestfs, "list_filesystems",
        ruby_guestfs_list_filesystems, 0);
  rb_define_method (c_guestfs, "add_drive_opts",
        ruby_guestfs_add_drive_opts, 2);
  rb_define_method (c_guestfs, "inspect_get_windows_systemroot",
        ruby_guestfs_inspect_get_windows_systemroot, 1);
  rb_define_method (c_guestfs, "inspect_get_roots",
        ruby_guestfs_inspect_get_roots, 0);
  rb_define_method (c_guestfs, "debug_cmdline",
        ruby_guestfs_debug_cmdline, 0);
  rb_define_method (c_guestfs, "debug_drives",
        ruby_guestfs_debug_drives, 0);
  rb_define_method (c_guestfs, "add_domain",
        ruby_guestfs_add_domain, 2);
  rb_define_method (c_guestfs, "inspect_get_package_format",
        ruby_guestfs_inspect_get_package_format, 1);
  rb_define_method (c_guestfs, "inspect_get_package_management",
        ruby_guestfs_inspect_get_package_management, 1);
  rb_define_method (c_guestfs, "inspect_list_applications",
        ruby_guestfs_inspect_list_applications, 1);
  rb_define_method (c_guestfs, "inspect_get_hostname",
        ruby_guestfs_inspect_get_hostname, 1);
  rb_define_method (c_guestfs, "inspect_get_format",
        ruby_guestfs_inspect_get_format, 1);
  rb_define_method (c_guestfs, "inspect_is_live",
        ruby_guestfs_inspect_is_live, 1);
  rb_define_method (c_guestfs, "inspect_is_netinst",
        ruby_guestfs_inspect_is_netinst, 1);
  rb_define_method (c_guestfs, "inspect_is_multipart",
        ruby_guestfs_inspect_is_multipart, 1);
  rb_define_method (c_guestfs, "set_attach_method",
        ruby_guestfs_set_attach_method, 1);
  rb_define_method (c_guestfs, "get_attach_method",
        ruby_guestfs_get_attach_method, 0);
  rb_define_method (c_guestfs, "inspect_get_product_variant",
        ruby_guestfs_inspect_get_product_variant, 1);
  rb_define_method (c_guestfs, "inspect_get_windows_current_control_set",
        ruby_guestfs_inspect_get_windows_current_control_set, 1);
  rb_define_method (c_guestfs, "inspect_get_drive_mappings",
        ruby_guestfs_inspect_get_drive_mappings, 1);
  rb_define_method (c_guestfs, "inspect_get_icon",
        ruby_guestfs_inspect_get_icon, 2);
  rb_define_method (c_guestfs, "set_pgroup",
        ruby_guestfs_set_pgroup, 1);
  rb_define_method (c_guestfs, "get_pgroup",
        ruby_guestfs_get_pgroup, 0);
  rb_define_method (c_guestfs, "set_smp",
        ruby_guestfs_set_smp, 1);
  rb_define_method (c_guestfs, "get_smp",
        ruby_guestfs_get_smp, 0);
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
  rb_define_method (c_guestfs, "pvuuid",
        ruby_guestfs_pvuuid, 1);
  rb_define_method (c_guestfs, "vguuid",
        ruby_guestfs_vguuid, 1);
  rb_define_method (c_guestfs, "lvuuid",
        ruby_guestfs_lvuuid, 1);
  rb_define_method (c_guestfs, "vgpvuuids",
        ruby_guestfs_vgpvuuids, 1);
  rb_define_method (c_guestfs, "vglvuuids",
        ruby_guestfs_vglvuuids, 1);
  rb_define_method (c_guestfs, "copy_size",
        ruby_guestfs_copy_size, 3);
  rb_define_method (c_guestfs, "zero_device",
        ruby_guestfs_zero_device, 1);
  rb_define_method (c_guestfs, "txz_in",
        ruby_guestfs_txz_in, 2);
  rb_define_method (c_guestfs, "txz_out",
        ruby_guestfs_txz_out, 2);
  rb_define_method (c_guestfs, "ntfsresize",
        ruby_guestfs_ntfsresize, 1);
  rb_define_method (c_guestfs, "vgscan",
        ruby_guestfs_vgscan, 0);
  rb_define_method (c_guestfs, "part_del",
        ruby_guestfs_part_del, 2);
  rb_define_method (c_guestfs, "part_get_bootable",
        ruby_guestfs_part_get_bootable, 2);
  rb_define_method (c_guestfs, "part_get_mbr_id",
        ruby_guestfs_part_get_mbr_id, 2);
  rb_define_method (c_guestfs, "part_set_mbr_id",
        ruby_guestfs_part_set_mbr_id, 3);
  rb_define_method (c_guestfs, "checksum_device",
        ruby_guestfs_checksum_device, 2);
  rb_define_method (c_guestfs, "lvresize_free",
        ruby_guestfs_lvresize_free, 2);
  rb_define_method (c_guestfs, "aug_clear",
        ruby_guestfs_aug_clear, 1);
  rb_define_method (c_guestfs, "get_umask",
        ruby_guestfs_get_umask, 0);
  rb_define_method (c_guestfs, "debug_upload",
        ruby_guestfs_debug_upload, 3);
  rb_define_method (c_guestfs, "base64_in",
        ruby_guestfs_base64_in, 2);
  rb_define_method (c_guestfs, "base64_out",
        ruby_guestfs_base64_out, 2);
  rb_define_method (c_guestfs, "checksums_out",
        ruby_guestfs_checksums_out, 3);
  rb_define_method (c_guestfs, "fill_pattern",
        ruby_guestfs_fill_pattern, 3);
  rb_define_method (c_guestfs, "write",
        ruby_guestfs_write, 2);
  rb_define_method (c_guestfs, "pwrite",
        ruby_guestfs_pwrite, 3);
  rb_define_method (c_guestfs, "resize2fs_size",
        ruby_guestfs_resize2fs_size, 2);
  rb_define_method (c_guestfs, "pvresize_size",
        ruby_guestfs_pvresize_size, 2);
  rb_define_method (c_guestfs, "ntfsresize_size",
        ruby_guestfs_ntfsresize_size, 2);
  rb_define_method (c_guestfs, "available_all_groups",
        ruby_guestfs_available_all_groups, 0);
  rb_define_method (c_guestfs, "fallocate64",
        ruby_guestfs_fallocate64, 2);
  rb_define_method (c_guestfs, "vfs_label",
        ruby_guestfs_vfs_label, 1);
  rb_define_method (c_guestfs, "vfs_uuid",
        ruby_guestfs_vfs_uuid, 1);
  rb_define_method (c_guestfs, "lvm_set_filter",
        ruby_guestfs_lvm_set_filter, 1);
  rb_define_method (c_guestfs, "lvm_clear_filter",
        ruby_guestfs_lvm_clear_filter, 0);
  rb_define_method (c_guestfs, "luks_open",
        ruby_guestfs_luks_open, 3);
  rb_define_method (c_guestfs, "luks_open_ro",
        ruby_guestfs_luks_open_ro, 3);
  rb_define_method (c_guestfs, "luks_close",
        ruby_guestfs_luks_close, 1);
  rb_define_method (c_guestfs, "luks_format",
        ruby_guestfs_luks_format, 3);
  rb_define_method (c_guestfs, "luks_format_cipher",
        ruby_guestfs_luks_format_cipher, 4);
  rb_define_method (c_guestfs, "luks_add_key",
        ruby_guestfs_luks_add_key, 4);
  rb_define_method (c_guestfs, "luks_kill_slot",
        ruby_guestfs_luks_kill_slot, 3);
  rb_define_method (c_guestfs, "is_lv",
        ruby_guestfs_is_lv, 1);
  rb_define_method (c_guestfs, "findfs_uuid",
        ruby_guestfs_findfs_uuid, 1);
  rb_define_method (c_guestfs, "findfs_label",
        ruby_guestfs_findfs_label, 1);
  rb_define_method (c_guestfs, "is_chardev",
        ruby_guestfs_is_chardev, 1);
  rb_define_method (c_guestfs, "is_blockdev",
        ruby_guestfs_is_blockdev, 1);
  rb_define_method (c_guestfs, "is_fifo",
        ruby_guestfs_is_fifo, 1);
  rb_define_method (c_guestfs, "is_symlink",
        ruby_guestfs_is_symlink, 1);
  rb_define_method (c_guestfs, "is_socket",
        ruby_guestfs_is_socket, 1);
  rb_define_method (c_guestfs, "part_to_dev",
        ruby_guestfs_part_to_dev, 1);
  rb_define_method (c_guestfs, "upload_offset",
        ruby_guestfs_upload_offset, 3);
  rb_define_method (c_guestfs, "download_offset",
        ruby_guestfs_download_offset, 4);
  rb_define_method (c_guestfs, "pwrite_device",
        ruby_guestfs_pwrite_device, 3);
  rb_define_method (c_guestfs, "pread_device",
        ruby_guestfs_pread_device, 3);
  rb_define_method (c_guestfs, "lvm_canonical_lv_name",
        ruby_guestfs_lvm_canonical_lv_name, 1);
  rb_define_method (c_guestfs, "mkfs_opts",
        ruby_guestfs_mkfs_opts, 3);
  rb_define_method (c_guestfs, "getxattr",
        ruby_guestfs_getxattr, 2);
  rb_define_method (c_guestfs, "lgetxattr",
        ruby_guestfs_lgetxattr, 2);
  rb_define_method (c_guestfs, "resize2fs_M",
        ruby_guestfs_resize2fs_M, 1);
  rb_define_method (c_guestfs, "internal_autosync",
        ruby_guestfs_internal_autosync, 0);
  rb_define_method (c_guestfs, "is_zero",
        ruby_guestfs_is_zero, 1);
  rb_define_method (c_guestfs, "is_zero_device",
        ruby_guestfs_is_zero_device, 1);
  rb_define_method (c_guestfs, "list_9p",
        ruby_guestfs_list_9p, 0);
  rb_define_method (c_guestfs, "mount_9p",
        ruby_guestfs_mount_9p, 3);
  rb_define_method (c_guestfs, "list_dm_devices",
        ruby_guestfs_list_dm_devices, 0);
  rb_define_method (c_guestfs, "ntfsresize_opts",
        ruby_guestfs_ntfsresize_opts, 2);
  rb_define_method (c_guestfs, "btrfs_filesystem_resize",
        ruby_guestfs_btrfs_filesystem_resize, 2);
  rb_define_method (c_guestfs, "write_append",
        ruby_guestfs_write_append, 2);
  rb_define_method (c_guestfs, "compress_out",
        ruby_guestfs_compress_out, 4);
  rb_define_method (c_guestfs, "compress_device_out",
        ruby_guestfs_compress_device_out, 4);
  rb_define_method (c_guestfs, "part_to_partnum",
        ruby_guestfs_part_to_partnum, 1);
  rb_define_method (c_guestfs, "copy_device_to_device",
        ruby_guestfs_copy_device_to_device, 3);
  rb_define_method (c_guestfs, "copy_device_to_file",
        ruby_guestfs_copy_device_to_file, 3);
  rb_define_method (c_guestfs, "copy_file_to_device",
        ruby_guestfs_copy_file_to_device, 3);
  rb_define_method (c_guestfs, "copy_file_to_file",
        ruby_guestfs_copy_file_to_file, 3);
}
