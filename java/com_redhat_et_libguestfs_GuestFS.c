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

#include "com_redhat_et_libguestfs_GuestFS.h"
#include "guestfs.h"
#include "guestfs-internal-frontend.h"

/* This is the opaque data passed between _set_event_callback and
 * the C wrapper which calls the Java event callback.
 *
 * NB: The 'callback' in the following struct is registered as a global
 * reference.  It must be freed along with the struct.
 */
struct callback_data {
  JavaVM *jvm;           // JVM
  jobject callback;      // object supporting EventCallback interface
  jmethodID method;      // callback.event method
};

static struct callback_data **get_all_event_callbacks (guestfs_h *g, size_t *len_rtn);

/* Note that this function returns.  The exception is not thrown
 * until after the wrapper function returns.
 */
static void
throw_exception (JNIEnv *env, const char *msg)
{
  jclass cl;
  cl = (*env)->FindClass (env,
                          "com/redhat/et/libguestfs/LibGuestFSException");
  (*env)->ThrowNew (env, cl, msg);
}

JNIEXPORT jlong JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1create (JNIEnv *env,
                                                jobject obj_unused, jint flags)
{
  guestfs_h *g;

  g = guestfs_create_flags ((int) flags);
  if (g == NULL) {
    throw_exception (env, "GuestFS.create: failed to allocate handle");
    return 0;
  }
  guestfs_set_error_handler (g, NULL, NULL);
  return (jlong) (long) g;
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1close
  (JNIEnv *env, jobject obj, jlong jg)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  size_t len, i;
  struct callback_data **data;

  /* There is a nasty, difficult to solve case here where the
   * user deletes events in one of the callbacks that we are
   * about to invoke, resulting in a double-free.  XXX
   */
  data = get_all_event_callbacks (g, &len);

  guestfs_close (g);

  for (i = 0; i < len; ++i) {
    (*env)->DeleteGlobalRef (env, data[i]->callback);
    free (data[i]);
  }
  free (data);
}

/* See EventCallback interface. */
#define METHOD_NAME "event"
#define METHOD_SIGNATURE "(JILjava/lang/String;[J)V"

static void
guestfs_java_callback (guestfs_h *g,
                       void *opaque,
                       uint64_t event,
                       int event_handle,
                       int flags,
                       const char *buf, size_t buf_len,
                       const uint64_t *array, size_t array_len)
{
  struct callback_data *data = opaque;
  JavaVM *jvm = data->jvm;
  JNIEnv *env;
  int r;
  jstring jbuf;
  jlongArray jarray;
  size_t i;
  jlong jl;

  /* Get the Java environment.  See:
   * http://stackoverflow.com/questions/12900695/how-to-obtain-jni-interface-pointer-jnienv-for-asynchronous-calls
   */
  r = (*jvm)->GetEnv (jvm, (void **) &env, JNI_VERSION_1_6);
  if (r != JNI_OK) {
    switch (r) {
    case JNI_EDETACHED:
      /* This can happen when the close event is generated during an atexit
       * cleanup.  The JVM has probably been destroyed so I doubt it is
       * safe to run Java code at this point.
       */
      fprintf (stderr, "%s: event %" PRIu64 " (eh %d) ignored because the thread is not attached to the JVM.  This can happen when libguestfs handles are cleaned up at program exit after the JVM has been destroyed.\n",
               __func__, event, event_handle);
      return;

    case JNI_EVERSION:
      fprintf (stderr, "%s: event %" PRIu64 " (eh %d) failed because the JVM version is too old.  JVM >= 1.6 is required.\n",
               __func__, event, event_handle);
      return;

    default:
      fprintf (stderr, "%s: jvm->GetEnv failed! (JNI_* error code = %d)\n",
               __func__, r);
      return;
    }
  }

  /* Convert the buffer and array to Java objects. */
  jbuf = (*env)->NewStringUTF (env, buf); // XXX size

  jarray = (*env)->NewLongArray (env, array_len);
  for (i = 0; i < array_len; ++i) {
    jl = array[i];
    (*env)->SetLongArrayRegion (env, jarray, i, 1, &jl);
  }

  /* Call the event method.  If it throws an exception, all we can do is
   * print it on stderr.
   */
  (*env)->ExceptionClear (env);
  (*env)->CallVoidMethod (env, data->callback, data->method,
                          (jlong) event, (jint) event_handle,
                          jbuf, jarray);
  if ((*env)->ExceptionOccurred (env)) {
    (*env)->ExceptionDescribe (env);
    (*env)->ExceptionClear (env);
  }
}

JNIEXPORT jint JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1set_1event_1callback
  (JNIEnv *env, jobject obj, jlong jg, jobject jcallback, jlong jevents)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  struct callback_data *data;
  jclass callback_class;
  jmethodID method;
  char key[64];

  callback_class = (*env)->GetObjectClass (env, jcallback);
  method = (*env)->GetMethodID (env, callback_class, METHOD_NAME, METHOD_SIGNATURE);
  if (method == 0) {
    throw_exception (env, "GuestFS.set_event_callback: callback class does not implement the EventCallback interface");
    return -1;
  }

  data = guestfs___safe_malloc (g, sizeof *data);
  (*env)->GetJavaVM (env, &data->jvm);
  data->method = method;

  r = guestfs_set_event_callback (g, guestfs_java_callback,
                                  (uint64_t) jevents, 0, data);
  if (r == -1) {
    free (data);
    throw_exception (env, guestfs_last_error (g));
    return -1;
  }

  /* Register jcallback as a global reference so the GC won't free it. */
  data->callback = (*env)->NewGlobalRef (env, jcallback);

  /* Store 'data' in the handle, so we can free it at some point. */
  snprintf (key, sizeof key, "_java_event_%d", r);
  guestfs_set_private (g, key, data);

  return (jint) r;
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1delete_1event_1callback
  (JNIEnv *env, jobject obj, jlong jg, jint eh)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  char key[64];
  struct callback_data *data;

  snprintf (key, sizeof key, "_java_event_%d", eh);

  data = guestfs_get_private (g, key);
  if (data) {
    (*env)->DeleteGlobalRef (env, data->callback);
    free (data);
    guestfs_set_private (g, key, NULL);
    guestfs_delete_event_callback (g, eh);
  }
}

JNIEXPORT jstring JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1event_1to_1string
  (JNIEnv *env, jclass cl, jlong jevents)
{
  uint64_t events = (uint64_t) jevents;
  char *str;
  jstring jr;

  str = guestfs_event_to_string (events);
  if (str == NULL) {
    perror ("guestfs_event_to_string");
    return NULL;
  }

  jr = (*env)->NewStringUTF (env, str);
  free (str);

  return jr;
}

static struct callback_data **
get_all_event_callbacks (guestfs_h *g, size_t *len_rtn)
{
  struct callback_data **r;
  size_t i;
  const char *key;
  struct callback_data *data;

  /* Count the length of the array that will be needed. */
  *len_rtn = 0;
  data = guestfs_first_private (g, &key);
  while (data != NULL) {
    if (strncmp (key, "_java_event_", strlen ("_java_event_")) == 0)
      (*len_rtn)++;
    data = guestfs_next_private (g, &key);
  }

  /* Copy them into the return array. */
  r = guestfs___safe_malloc (g, sizeof (struct callback_data *) * (*len_rtn));

  i = 0;
  data = guestfs_first_private (g, &key);
  while (data != NULL) {
    if (strncmp (key, "_java_event_", strlen ("_java_event_")) == 0) {
      r[i] = data;
      i++;
    }
    data = guestfs_next_private (g, &key);
  }

  return r;
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1acl_1delete_1def_1file  (JNIEnv *env, jobject obj, jlong jg, jstring jdir)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *dir;

  dir = (*env)->GetStringUTFChars (env, jdir, NULL);

  r = guestfs_acl_delete_def_file (g, dir);

  (*env)->ReleaseStringUTFChars (env, jdir, dir);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT jstring JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1acl_1get_1file  (JNIEnv *env, jobject obj, jlong jg, jstring jpath, jstring jacltype)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  jstring jr;
  char *r;
  const char *path;
  const char *acltype;

  path = (*env)->GetStringUTFChars (env, jpath, NULL);
  acltype = (*env)->GetStringUTFChars (env, jacltype, NULL);

  r = guestfs_acl_get_file (g, path, acltype);

  (*env)->ReleaseStringUTFChars (env, jpath, path);
  (*env)->ReleaseStringUTFChars (env, jacltype, acltype);

  if (r == NULL) {
    throw_exception (env, guestfs_last_error (g));
    return NULL;
  }
  jr = (*env)->NewStringUTF (env, r);
  free (r);
  return jr;
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1acl_1set_1file  (JNIEnv *env, jobject obj, jlong jg, jstring jpath, jstring jacltype, jstring jacl)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *path;
  const char *acltype;
  const char *acl;

  path = (*env)->GetStringUTFChars (env, jpath, NULL);
  acltype = (*env)->GetStringUTFChars (env, jacltype, NULL);
  acl = (*env)->GetStringUTFChars (env, jacl, NULL);

  r = guestfs_acl_set_file (g, path, acltype, acl);

  (*env)->ReleaseStringUTFChars (env, jpath, path);
  (*env)->ReleaseStringUTFChars (env, jacltype, acltype);
  (*env)->ReleaseStringUTFChars (env, jacl, acl);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1add_1cdrom  (JNIEnv *env, jobject obj, jlong jg, jstring jfilename)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *filename;

  filename = (*env)->GetStringUTFChars (env, jfilename, NULL);

  r = guestfs_add_cdrom (g, filename);

  (*env)->ReleaseStringUTFChars (env, jfilename, filename);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT jint JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1add_1domain  (JNIEnv *env, jobject obj, jlong jg, jstring jdom, jlong joptargs_bitmask, jstring jlibvirturi, jboolean jreadonly, jstring jiface, jboolean jlive, jboolean jallowuuid, jstring jreadonlydisk, jstring jcachemode, jstring jdiscard, jboolean jcopyonread)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *dom;
  struct guestfs_add_domain_argv optargs_s;
  const struct guestfs_add_domain_argv *optargs = &optargs_s;

  dom = (*env)->GetStringUTFChars (env, jdom, NULL);

  optargs_s.libvirturi = (*env)->GetStringUTFChars (env, jlibvirturi, NULL);
  optargs_s.readonly = jreadonly;
  optargs_s.iface = (*env)->GetStringUTFChars (env, jiface, NULL);
  optargs_s.live = jlive;
  optargs_s.allowuuid = jallowuuid;
  optargs_s.readonlydisk = (*env)->GetStringUTFChars (env, jreadonlydisk, NULL);
  optargs_s.cachemode = (*env)->GetStringUTFChars (env, jcachemode, NULL);
  optargs_s.discard = (*env)->GetStringUTFChars (env, jdiscard, NULL);
  optargs_s.copyonread = jcopyonread;
  optargs_s.bitmask = joptargs_bitmask;

  r = guestfs_add_domain_argv (g, dom, optargs);

  (*env)->ReleaseStringUTFChars (env, jdom, dom);
  (*env)->ReleaseStringUTFChars (env, jlibvirturi, optargs_s.libvirturi);
  (*env)->ReleaseStringUTFChars (env, jiface, optargs_s.iface);
  (*env)->ReleaseStringUTFChars (env, jreadonlydisk, optargs_s.readonlydisk);
  (*env)->ReleaseStringUTFChars (env, jcachemode, optargs_s.cachemode);
  (*env)->ReleaseStringUTFChars (env, jdiscard, optargs_s.discard);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return -1;
  }
  return (jint) r;
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1add_1drive  (JNIEnv *env, jobject obj, jlong jg, jstring jfilename, jlong joptargs_bitmask, jboolean jreadonly, jstring jformat, jstring jiface, jstring jname, jstring jlabel, jstring jprotocol, jobjectArray jserver, jstring jusername, jstring jsecret, jstring jcachemode, jstring jdiscard, jboolean jcopyonread)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *filename;
  struct guestfs_add_drive_opts_argv optargs_s;
  const struct guestfs_add_drive_opts_argv *optargs = &optargs_s;
  size_t server_len;
  char **server;
  size_t i;

  filename = (*env)->GetStringUTFChars (env, jfilename, NULL);

  optargs_s.readonly = jreadonly;
  optargs_s.format = (*env)->GetStringUTFChars (env, jformat, NULL);
  optargs_s.iface = (*env)->GetStringUTFChars (env, jiface, NULL);
  optargs_s.name = (*env)->GetStringUTFChars (env, jname, NULL);
  optargs_s.label = (*env)->GetStringUTFChars (env, jlabel, NULL);
  optargs_s.protocol = (*env)->GetStringUTFChars (env, jprotocol, NULL);
  server_len = (*env)->GetArrayLength (env, jserver);
  server = guestfs___safe_malloc (g, sizeof (char *) * (server_len+1));
  for (i = 0; i < server_len; ++i) {
    jobject o = (*env)->GetObjectArrayElement (env, jserver, i);
    server[i] = (char *) (*env)->GetStringUTFChars (env, o, NULL);
  }
  server[server_len] = NULL;
  optargs_s.server = server;
  optargs_s.username = (*env)->GetStringUTFChars (env, jusername, NULL);
  optargs_s.secret = (*env)->GetStringUTFChars (env, jsecret, NULL);
  optargs_s.cachemode = (*env)->GetStringUTFChars (env, jcachemode, NULL);
  optargs_s.discard = (*env)->GetStringUTFChars (env, jdiscard, NULL);
  optargs_s.copyonread = jcopyonread;
  optargs_s.bitmask = joptargs_bitmask;

  r = guestfs_add_drive_opts_argv (g, filename, optargs);

  (*env)->ReleaseStringUTFChars (env, jfilename, filename);
  (*env)->ReleaseStringUTFChars (env, jformat, optargs_s.format);
  (*env)->ReleaseStringUTFChars (env, jiface, optargs_s.iface);
  (*env)->ReleaseStringUTFChars (env, jname, optargs_s.name);
  (*env)->ReleaseStringUTFChars (env, jlabel, optargs_s.label);
  (*env)->ReleaseStringUTFChars (env, jprotocol, optargs_s.protocol);
  for (i = 0; i < server_len; ++i) {
    jobject o = (*env)->GetObjectArrayElement (env, jserver, i);
    (*env)->ReleaseStringUTFChars (env, o, optargs_s.server[i]);
  }
  free (server);
  (*env)->ReleaseStringUTFChars (env, jusername, optargs_s.username);
  (*env)->ReleaseStringUTFChars (env, jsecret, optargs_s.secret);
  (*env)->ReleaseStringUTFChars (env, jcachemode, optargs_s.cachemode);
  (*env)->ReleaseStringUTFChars (env, jdiscard, optargs_s.discard);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1add_1drive_1ro  (JNIEnv *env, jobject obj, jlong jg, jstring jfilename)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *filename;

  filename = (*env)->GetStringUTFChars (env, jfilename, NULL);

  r = guestfs_add_drive_ro (g, filename);

  (*env)->ReleaseStringUTFChars (env, jfilename, filename);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1add_1drive_1ro_1with_1if  (JNIEnv *env, jobject obj, jlong jg, jstring jfilename, jstring jiface)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *filename;
  const char *iface;

  filename = (*env)->GetStringUTFChars (env, jfilename, NULL);
  iface = (*env)->GetStringUTFChars (env, jiface, NULL);

  r = guestfs_add_drive_ro_with_if (g, filename, iface);

  (*env)->ReleaseStringUTFChars (env, jfilename, filename);
  (*env)->ReleaseStringUTFChars (env, jiface, iface);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1add_1drive_1scratch  (JNIEnv *env, jobject obj, jlong jg, jlong jsize, jlong joptargs_bitmask, jstring jname, jstring jlabel)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  int64_t size;
  struct guestfs_add_drive_scratch_argv optargs_s;
  const struct guestfs_add_drive_scratch_argv *optargs = &optargs_s;

  size = jsize;

  optargs_s.name = (*env)->GetStringUTFChars (env, jname, NULL);
  optargs_s.label = (*env)->GetStringUTFChars (env, jlabel, NULL);
  optargs_s.bitmask = joptargs_bitmask;

  r = guestfs_add_drive_scratch_argv (g, size, optargs);

  (*env)->ReleaseStringUTFChars (env, jname, optargs_s.name);
  (*env)->ReleaseStringUTFChars (env, jlabel, optargs_s.label);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1add_1drive_1with_1if  (JNIEnv *env, jobject obj, jlong jg, jstring jfilename, jstring jiface)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *filename;
  const char *iface;

  filename = (*env)->GetStringUTFChars (env, jfilename, NULL);
  iface = (*env)->GetStringUTFChars (env, jiface, NULL);

  r = guestfs_add_drive_with_if (g, filename, iface);

  (*env)->ReleaseStringUTFChars (env, jfilename, filename);
  (*env)->ReleaseStringUTFChars (env, jiface, iface);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1aug_1clear  (JNIEnv *env, jobject obj, jlong jg, jstring jaugpath)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *augpath;

  augpath = (*env)->GetStringUTFChars (env, jaugpath, NULL);

  r = guestfs_aug_clear (g, augpath);

  (*env)->ReleaseStringUTFChars (env, jaugpath, augpath);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1aug_1close  (JNIEnv *env, jobject obj, jlong jg)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;


  r = guestfs_aug_close (g);


  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT jobject JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1aug_1defnode  (JNIEnv *env, jobject obj, jlong jg, jstring jname, jstring jexpr, jstring jval)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  jobject jr;
  jclass cl;
  jfieldID fl;
  struct guestfs_int_bool *r;
  const char *name;
  const char *expr;
  const char *val;

  name = (*env)->GetStringUTFChars (env, jname, NULL);
  expr = (*env)->GetStringUTFChars (env, jexpr, NULL);
  val = (*env)->GetStringUTFChars (env, jval, NULL);

  r = guestfs_aug_defnode (g, name, expr, val);

  (*env)->ReleaseStringUTFChars (env, jname, name);
  (*env)->ReleaseStringUTFChars (env, jexpr, expr);
  (*env)->ReleaseStringUTFChars (env, jval, val);

  if (r == NULL) {
    throw_exception (env, guestfs_last_error (g));
    return NULL;
  }
  cl = (*env)->FindClass (env, "com/redhat/et/libguestfs/IntBool");
  jr = (*env)->AllocObject (env, cl);
  fl = (*env)->GetFieldID (env, cl, "i", "I");
  (*env)->SetIntField (env, jr, fl, r->i);
  fl = (*env)->GetFieldID (env, cl, "b", "I");
  (*env)->SetIntField (env, jr, fl, r->b);
  free (r);
  return jr;
}

JNIEXPORT jint JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1aug_1defvar  (JNIEnv *env, jobject obj, jlong jg, jstring jname, jstring jexpr)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *name;
  const char *expr;

  name = (*env)->GetStringUTFChars (env, jname, NULL);
  expr = jexpr ? (*env)->GetStringUTFChars (env, jexpr, NULL) : NULL;

  r = guestfs_aug_defvar (g, name, expr);

  (*env)->ReleaseStringUTFChars (env, jname, name);
  if (jexpr)
    (*env)->ReleaseStringUTFChars (env, jexpr, expr);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return -1;
  }
  return (jint) r;
}

JNIEXPORT jstring JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1aug_1get  (JNIEnv *env, jobject obj, jlong jg, jstring jaugpath)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  jstring jr;
  char *r;
  const char *augpath;

  augpath = (*env)->GetStringUTFChars (env, jaugpath, NULL);

  r = guestfs_aug_get (g, augpath);

  (*env)->ReleaseStringUTFChars (env, jaugpath, augpath);

  if (r == NULL) {
    throw_exception (env, guestfs_last_error (g));
    return NULL;
  }
  jr = (*env)->NewStringUTF (env, r);
  free (r);
  return jr;
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1aug_1init  (JNIEnv *env, jobject obj, jlong jg, jstring jroot, jint jflags)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *root;
  int flags;

  root = (*env)->GetStringUTFChars (env, jroot, NULL);
  flags = jflags;

  r = guestfs_aug_init (g, root, flags);

  (*env)->ReleaseStringUTFChars (env, jroot, root);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1aug_1insert  (JNIEnv *env, jobject obj, jlong jg, jstring jaugpath, jstring jlabel, jboolean jbefore)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *augpath;
  const char *label;
  int before;

  augpath = (*env)->GetStringUTFChars (env, jaugpath, NULL);
  label = (*env)->GetStringUTFChars (env, jlabel, NULL);
  before = jbefore;

  r = guestfs_aug_insert (g, augpath, label, before);

  (*env)->ReleaseStringUTFChars (env, jaugpath, augpath);
  (*env)->ReleaseStringUTFChars (env, jlabel, label);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT jstring JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1aug_1label  (JNIEnv *env, jobject obj, jlong jg, jstring jaugpath)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  jstring jr;
  char *r;
  const char *augpath;

  augpath = (*env)->GetStringUTFChars (env, jaugpath, NULL);

  r = guestfs_aug_label (g, augpath);

  (*env)->ReleaseStringUTFChars (env, jaugpath, augpath);

  if (r == NULL) {
    throw_exception (env, guestfs_last_error (g));
    return NULL;
  }
  jr = (*env)->NewStringUTF (env, r);
  free (r);
  return jr;
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1aug_1load  (JNIEnv *env, jobject obj, jlong jg)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;


  r = guestfs_aug_load (g);


  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT jobjectArray JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1aug_1ls  (JNIEnv *env, jobject obj, jlong jg, jstring jaugpath)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  jobjectArray jr;
  size_t r_len;
  jclass cl;
  jstring jstr;
  char **r;
  const char *augpath;
  size_t i;

  augpath = (*env)->GetStringUTFChars (env, jaugpath, NULL);

  r = guestfs_aug_ls (g, augpath);

  (*env)->ReleaseStringUTFChars (env, jaugpath, augpath);

  if (r == NULL) {
    throw_exception (env, guestfs_last_error (g));
    return NULL;
  }
  for (r_len = 0; r[r_len] != NULL; ++r_len) ;
  cl = (*env)->FindClass (env, "java/lang/String");
  jstr = (*env)->NewStringUTF (env, "");
  jr = (*env)->NewObjectArray (env, r_len, cl, jstr);
  for (i = 0; i < r_len; ++i) {
    jstr = (*env)->NewStringUTF (env, r[i]);
    (*env)->SetObjectArrayElement (env, jr, i, jstr);
    free (r[i]);
  }
  free (r);
  return jr;
}

JNIEXPORT jobjectArray JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1aug_1match  (JNIEnv *env, jobject obj, jlong jg, jstring jaugpath)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  jobjectArray jr;
  size_t r_len;
  jclass cl;
  jstring jstr;
  char **r;
  const char *augpath;
  size_t i;

  augpath = (*env)->GetStringUTFChars (env, jaugpath, NULL);

  r = guestfs_aug_match (g, augpath);

  (*env)->ReleaseStringUTFChars (env, jaugpath, augpath);

  if (r == NULL) {
    throw_exception (env, guestfs_last_error (g));
    return NULL;
  }
  for (r_len = 0; r[r_len] != NULL; ++r_len) ;
  cl = (*env)->FindClass (env, "java/lang/String");
  jstr = (*env)->NewStringUTF (env, "");
  jr = (*env)->NewObjectArray (env, r_len, cl, jstr);
  for (i = 0; i < r_len; ++i) {
    jstr = (*env)->NewStringUTF (env, r[i]);
    (*env)->SetObjectArrayElement (env, jr, i, jstr);
    free (r[i]);
  }
  free (r);
  return jr;
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1aug_1mv  (JNIEnv *env, jobject obj, jlong jg, jstring jsrc, jstring jdest)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *src;
  const char *dest;

  src = (*env)->GetStringUTFChars (env, jsrc, NULL);
  dest = (*env)->GetStringUTFChars (env, jdest, NULL);

  r = guestfs_aug_mv (g, src, dest);

  (*env)->ReleaseStringUTFChars (env, jsrc, src);
  (*env)->ReleaseStringUTFChars (env, jdest, dest);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT jint JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1aug_1rm  (JNIEnv *env, jobject obj, jlong jg, jstring jaugpath)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *augpath;

  augpath = (*env)->GetStringUTFChars (env, jaugpath, NULL);

  r = guestfs_aug_rm (g, augpath);

  (*env)->ReleaseStringUTFChars (env, jaugpath, augpath);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return -1;
  }
  return (jint) r;
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1aug_1save  (JNIEnv *env, jobject obj, jlong jg)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;


  r = guestfs_aug_save (g);


  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1aug_1set  (JNIEnv *env, jobject obj, jlong jg, jstring jaugpath, jstring jval)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *augpath;
  const char *val;

  augpath = (*env)->GetStringUTFChars (env, jaugpath, NULL);
  val = (*env)->GetStringUTFChars (env, jval, NULL);

  r = guestfs_aug_set (g, augpath, val);

  (*env)->ReleaseStringUTFChars (env, jaugpath, augpath);
  (*env)->ReleaseStringUTFChars (env, jval, val);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT jint JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1aug_1setm  (JNIEnv *env, jobject obj, jlong jg, jstring jbase, jstring jsub, jstring jval)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *base;
  const char *sub;
  const char *val;

  base = (*env)->GetStringUTFChars (env, jbase, NULL);
  sub = jsub ? (*env)->GetStringUTFChars (env, jsub, NULL) : NULL;
  val = (*env)->GetStringUTFChars (env, jval, NULL);

  r = guestfs_aug_setm (g, base, sub, val);

  (*env)->ReleaseStringUTFChars (env, jbase, base);
  if (jsub)
    (*env)->ReleaseStringUTFChars (env, jsub, sub);
  (*env)->ReleaseStringUTFChars (env, jval, val);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return -1;
  }
  return (jint) r;
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1available  (JNIEnv *env, jobject obj, jlong jg, jobjectArray jgroups)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  size_t groups_len;
  char **groups;
  size_t i;

  groups_len = (*env)->GetArrayLength (env, jgroups);
  groups = guestfs___safe_malloc (g, sizeof (char *) * (groups_len+1));
  for (i = 0; i < groups_len; ++i) {
    jobject o = (*env)->GetObjectArrayElement (env, jgroups, i);
    groups[i] = (char *) (*env)->GetStringUTFChars (env, o, NULL);
  }
  groups[groups_len] = NULL;

  r = guestfs_available (g, groups);

  for (i = 0; i < groups_len; ++i) {
    jobject o = (*env)->GetObjectArrayElement (env, jgroups, i);
    (*env)->ReleaseStringUTFChars (env, o, groups[i]);
  }
  free (groups);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT jobjectArray JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1available_1all_1groups  (JNIEnv *env, jobject obj, jlong jg)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  jobjectArray jr;
  size_t r_len;
  jclass cl;
  jstring jstr;
  char **r;
  size_t i;


  r = guestfs_available_all_groups (g);


  if (r == NULL) {
    throw_exception (env, guestfs_last_error (g));
    return NULL;
  }
  for (r_len = 0; r[r_len] != NULL; ++r_len) ;
  cl = (*env)->FindClass (env, "java/lang/String");
  jstr = (*env)->NewStringUTF (env, "");
  jr = (*env)->NewObjectArray (env, r_len, cl, jstr);
  for (i = 0; i < r_len; ++i) {
    jstr = (*env)->NewStringUTF (env, r[i]);
    (*env)->SetObjectArrayElement (env, jr, i, jstr);
    free (r[i]);
  }
  free (r);
  return jr;
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1base64_1in  (JNIEnv *env, jobject obj, jlong jg, jstring jbase64file, jstring jfilename)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *base64file;
  const char *filename;

  base64file = (*env)->GetStringUTFChars (env, jbase64file, NULL);
  filename = (*env)->GetStringUTFChars (env, jfilename, NULL);

  r = guestfs_base64_in (g, base64file, filename);

  (*env)->ReleaseStringUTFChars (env, jbase64file, base64file);
  (*env)->ReleaseStringUTFChars (env, jfilename, filename);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1base64_1out  (JNIEnv *env, jobject obj, jlong jg, jstring jfilename, jstring jbase64file)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *filename;
  const char *base64file;

  filename = (*env)->GetStringUTFChars (env, jfilename, NULL);
  base64file = (*env)->GetStringUTFChars (env, jbase64file, NULL);

  r = guestfs_base64_out (g, filename, base64file);

  (*env)->ReleaseStringUTFChars (env, jfilename, filename);
  (*env)->ReleaseStringUTFChars (env, jbase64file, base64file);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1blkdiscard  (JNIEnv *env, jobject obj, jlong jg, jstring jdevice)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *device;

  device = (*env)->GetStringUTFChars (env, jdevice, NULL);

  r = guestfs_blkdiscard (g, device);

  (*env)->ReleaseStringUTFChars (env, jdevice, device);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT jboolean JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1blkdiscardzeroes  (JNIEnv *env, jobject obj, jlong jg, jstring jdevice)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *device;

  device = (*env)->GetStringUTFChars (env, jdevice, NULL);

  r = guestfs_blkdiscardzeroes (g, device);

  (*env)->ReleaseStringUTFChars (env, jdevice, device);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return -1;
  }
  return (jboolean) r;
}

JNIEXPORT jobject JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1blkid  (JNIEnv *env, jobject obj, jlong jg, jstring jdevice)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  jobjectArray jr;
  size_t r_len;
  jclass cl;
  jstring jstr;
  char **r;
  const char *device;
  size_t i;

  device = (*env)->GetStringUTFChars (env, jdevice, NULL);

  r = guestfs_blkid (g, device);

  (*env)->ReleaseStringUTFChars (env, jdevice, device);

  if (r == NULL) {
    throw_exception (env, guestfs_last_error (g));
    return NULL;
  }
  for (r_len = 0; r[r_len] != NULL; ++r_len) ;
  cl = (*env)->FindClass (env, "java/lang/String");
  jstr = (*env)->NewStringUTF (env, "");
  jr = (*env)->NewObjectArray (env, r_len, cl, jstr);
  for (i = 0; i < r_len; ++i) {
    jstr = (*env)->NewStringUTF (env, r[i]);
    (*env)->SetObjectArrayElement (env, jr, i, jstr);
    free (r[i]);
  }
  free (r);
  return jr;
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1blockdev_1flushbufs  (JNIEnv *env, jobject obj, jlong jg, jstring jdevice)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *device;

  device = (*env)->GetStringUTFChars (env, jdevice, NULL);

  r = guestfs_blockdev_flushbufs (g, device);

  (*env)->ReleaseStringUTFChars (env, jdevice, device);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT jint JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1blockdev_1getbsz  (JNIEnv *env, jobject obj, jlong jg, jstring jdevice)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *device;

  device = (*env)->GetStringUTFChars (env, jdevice, NULL);

  r = guestfs_blockdev_getbsz (g, device);

  (*env)->ReleaseStringUTFChars (env, jdevice, device);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return -1;
  }
  return (jint) r;
}

JNIEXPORT jboolean JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1blockdev_1getro  (JNIEnv *env, jobject obj, jlong jg, jstring jdevice)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *device;

  device = (*env)->GetStringUTFChars (env, jdevice, NULL);

  r = guestfs_blockdev_getro (g, device);

  (*env)->ReleaseStringUTFChars (env, jdevice, device);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return -1;
  }
  return (jboolean) r;
}

JNIEXPORT jlong JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1blockdev_1getsize64  (JNIEnv *env, jobject obj, jlong jg, jstring jdevice)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int64_t r;
  const char *device;

  device = (*env)->GetStringUTFChars (env, jdevice, NULL);

  r = guestfs_blockdev_getsize64 (g, device);

  (*env)->ReleaseStringUTFChars (env, jdevice, device);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return -1;
  }
  return (jlong) r;
}

JNIEXPORT jint JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1blockdev_1getss  (JNIEnv *env, jobject obj, jlong jg, jstring jdevice)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *device;

  device = (*env)->GetStringUTFChars (env, jdevice, NULL);

  r = guestfs_blockdev_getss (g, device);

  (*env)->ReleaseStringUTFChars (env, jdevice, device);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return -1;
  }
  return (jint) r;
}

JNIEXPORT jlong JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1blockdev_1getsz  (JNIEnv *env, jobject obj, jlong jg, jstring jdevice)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int64_t r;
  const char *device;

  device = (*env)->GetStringUTFChars (env, jdevice, NULL);

  r = guestfs_blockdev_getsz (g, device);

  (*env)->ReleaseStringUTFChars (env, jdevice, device);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return -1;
  }
  return (jlong) r;
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1blockdev_1rereadpt  (JNIEnv *env, jobject obj, jlong jg, jstring jdevice)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *device;

  device = (*env)->GetStringUTFChars (env, jdevice, NULL);

  r = guestfs_blockdev_rereadpt (g, device);

  (*env)->ReleaseStringUTFChars (env, jdevice, device);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1blockdev_1setbsz  (JNIEnv *env, jobject obj, jlong jg, jstring jdevice, jint jblocksize)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *device;
  int blocksize;

  device = (*env)->GetStringUTFChars (env, jdevice, NULL);
  blocksize = jblocksize;

  r = guestfs_blockdev_setbsz (g, device, blocksize);

  (*env)->ReleaseStringUTFChars (env, jdevice, device);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1blockdev_1setro  (JNIEnv *env, jobject obj, jlong jg, jstring jdevice)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *device;

  device = (*env)->GetStringUTFChars (env, jdevice, NULL);

  r = guestfs_blockdev_setro (g, device);

  (*env)->ReleaseStringUTFChars (env, jdevice, device);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1blockdev_1setrw  (JNIEnv *env, jobject obj, jlong jg, jstring jdevice)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *device;

  device = (*env)->GetStringUTFChars (env, jdevice, NULL);

  r = guestfs_blockdev_setrw (g, device);

  (*env)->ReleaseStringUTFChars (env, jdevice, device);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1btrfs_1device_1add  (JNIEnv *env, jobject obj, jlong jg, jobjectArray jdevices, jstring jfs)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  size_t devices_len;
  char **devices;
  const char *fs;
  size_t i;

  devices_len = (*env)->GetArrayLength (env, jdevices);
  devices = guestfs___safe_malloc (g, sizeof (char *) * (devices_len+1));
  for (i = 0; i < devices_len; ++i) {
    jobject o = (*env)->GetObjectArrayElement (env, jdevices, i);
    devices[i] = (char *) (*env)->GetStringUTFChars (env, o, NULL);
  }
  devices[devices_len] = NULL;
  fs = (*env)->GetStringUTFChars (env, jfs, NULL);

  r = guestfs_btrfs_device_add (g, devices, fs);

  for (i = 0; i < devices_len; ++i) {
    jobject o = (*env)->GetObjectArrayElement (env, jdevices, i);
    (*env)->ReleaseStringUTFChars (env, o, devices[i]);
  }
  free (devices);
  (*env)->ReleaseStringUTFChars (env, jfs, fs);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1btrfs_1device_1delete  (JNIEnv *env, jobject obj, jlong jg, jobjectArray jdevices, jstring jfs)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  size_t devices_len;
  char **devices;
  const char *fs;
  size_t i;

  devices_len = (*env)->GetArrayLength (env, jdevices);
  devices = guestfs___safe_malloc (g, sizeof (char *) * (devices_len+1));
  for (i = 0; i < devices_len; ++i) {
    jobject o = (*env)->GetObjectArrayElement (env, jdevices, i);
    devices[i] = (char *) (*env)->GetStringUTFChars (env, o, NULL);
  }
  devices[devices_len] = NULL;
  fs = (*env)->GetStringUTFChars (env, jfs, NULL);

  r = guestfs_btrfs_device_delete (g, devices, fs);

  for (i = 0; i < devices_len; ++i) {
    jobject o = (*env)->GetObjectArrayElement (env, jdevices, i);
    (*env)->ReleaseStringUTFChars (env, o, devices[i]);
  }
  free (devices);
  (*env)->ReleaseStringUTFChars (env, jfs, fs);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1btrfs_1filesystem_1balance  (JNIEnv *env, jobject obj, jlong jg, jstring jfs)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *fs;

  fs = (*env)->GetStringUTFChars (env, jfs, NULL);

  r = guestfs_btrfs_filesystem_balance (g, fs);

  (*env)->ReleaseStringUTFChars (env, jfs, fs);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1btrfs_1filesystem_1resize  (JNIEnv *env, jobject obj, jlong jg, jstring jmountpoint, jlong joptargs_bitmask, jlong jsize)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *mountpoint;
  struct guestfs_btrfs_filesystem_resize_argv optargs_s;
  const struct guestfs_btrfs_filesystem_resize_argv *optargs = &optargs_s;

  mountpoint = (*env)->GetStringUTFChars (env, jmountpoint, NULL);

  optargs_s.size = jsize;
  optargs_s.bitmask = joptargs_bitmask;

  r = guestfs_btrfs_filesystem_resize_argv (g, mountpoint, optargs);

  (*env)->ReleaseStringUTFChars (env, jmountpoint, mountpoint);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1btrfs_1filesystem_1sync  (JNIEnv *env, jobject obj, jlong jg, jstring jfs)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *fs;

  fs = (*env)->GetStringUTFChars (env, jfs, NULL);

  r = guestfs_btrfs_filesystem_sync (g, fs);

  (*env)->ReleaseStringUTFChars (env, jfs, fs);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1btrfs_1fsck  (JNIEnv *env, jobject obj, jlong jg, jstring jdevice, jlong joptargs_bitmask, jlong jsuperblock, jboolean jrepair)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *device;
  struct guestfs_btrfs_fsck_argv optargs_s;
  const struct guestfs_btrfs_fsck_argv *optargs = &optargs_s;

  device = (*env)->GetStringUTFChars (env, jdevice, NULL);

  optargs_s.superblock = jsuperblock;
  optargs_s.repair = jrepair;
  optargs_s.bitmask = joptargs_bitmask;

  r = guestfs_btrfs_fsck_argv (g, device, optargs);

  (*env)->ReleaseStringUTFChars (env, jdevice, device);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1btrfs_1set_1seeding  (JNIEnv *env, jobject obj, jlong jg, jstring jdevice, jboolean jseeding)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *device;
  int seeding;

  device = (*env)->GetStringUTFChars (env, jdevice, NULL);
  seeding = jseeding;

  r = guestfs_btrfs_set_seeding (g, device, seeding);

  (*env)->ReleaseStringUTFChars (env, jdevice, device);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1btrfs_1subvolume_1create  (JNIEnv *env, jobject obj, jlong jg, jstring jdest)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *dest;

  dest = (*env)->GetStringUTFChars (env, jdest, NULL);

  r = guestfs_btrfs_subvolume_create (g, dest);

  (*env)->ReleaseStringUTFChars (env, jdest, dest);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1btrfs_1subvolume_1delete  (JNIEnv *env, jobject obj, jlong jg, jstring jsubvolume)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *subvolume;

  subvolume = (*env)->GetStringUTFChars (env, jsubvolume, NULL);

  r = guestfs_btrfs_subvolume_delete (g, subvolume);

  (*env)->ReleaseStringUTFChars (env, jsubvolume, subvolume);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT jobjectArray JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1btrfs_1subvolume_1list  (JNIEnv *env, jobject obj, jlong jg, jstring jfs)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  jobjectArray jr;
  jclass cl;
  jfieldID fl;
  jobject jfl;
  struct guestfs_btrfssubvolume_list *r;
  const char *fs;
  size_t i;

  fs = (*env)->GetStringUTFChars (env, jfs, NULL);

  r = guestfs_btrfs_subvolume_list (g, fs);

  (*env)->ReleaseStringUTFChars (env, jfs, fs);

  if (r == NULL) {
    throw_exception (env, guestfs_last_error (g));
    return NULL;
  }
  cl = (*env)->FindClass (env, "com/redhat/et/libguestfs/BTRFSSubvolume");
  jr = (*env)->NewObjectArray (env, r->len, cl, NULL);

  for (i = 0; i < r->len; ++i) {
    jfl = (*env)->AllocObject (env, cl);

    fl = (*env)->GetFieldID (env, cl, "btrfssubvolume_id",
                             "J");
    (*env)->SetLongField (env, jfl, fl, r->val[i].btrfssubvolume_id);
    fl = (*env)->GetFieldID (env, cl, "btrfssubvolume_top_level_id",
                             "J");
    (*env)->SetLongField (env, jfl, fl, r->val[i].btrfssubvolume_top_level_id);
    fl = (*env)->GetFieldID (env, cl, "btrfssubvolume_path",
                             "Ljava/lang/String;");
    (*env)->SetObjectField (env, jfl, fl,
                            (*env)->NewStringUTF (env, r->val[i].btrfssubvolume_path));

    (*env)->SetObjectArrayElement (env, jr, i, jfl);
  }

  guestfs_free_btrfssubvolume_list (r);
  return jr;
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1btrfs_1subvolume_1set_1default  (JNIEnv *env, jobject obj, jlong jg, jlong jid, jstring jfs)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  int64_t id;
  const char *fs;

  id = jid;
  fs = (*env)->GetStringUTFChars (env, jfs, NULL);

  r = guestfs_btrfs_subvolume_set_default (g, id, fs);

  (*env)->ReleaseStringUTFChars (env, jfs, fs);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1btrfs_1subvolume_1snapshot  (JNIEnv *env, jobject obj, jlong jg, jstring jsource, jstring jdest)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *source;
  const char *dest;

  source = (*env)->GetStringUTFChars (env, jsource, NULL);
  dest = (*env)->GetStringUTFChars (env, jdest, NULL);

  r = guestfs_btrfs_subvolume_snapshot (g, source, dest);

  (*env)->ReleaseStringUTFChars (env, jsource, source);
  (*env)->ReleaseStringUTFChars (env, jdest, dest);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT jstring JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1canonical_1device_1name  (JNIEnv *env, jobject obj, jlong jg, jstring jdevice)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  jstring jr;
  char *r;
  const char *device;

  device = (*env)->GetStringUTFChars (env, jdevice, NULL);

  r = guestfs_canonical_device_name (g, device);

  (*env)->ReleaseStringUTFChars (env, jdevice, device);

  if (r == NULL) {
    throw_exception (env, guestfs_last_error (g));
    return NULL;
  }
  jr = (*env)->NewStringUTF (env, r);
  free (r);
  return jr;
}

JNIEXPORT jstring JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1cap_1get_1file  (JNIEnv *env, jobject obj, jlong jg, jstring jpath)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  jstring jr;
  char *r;
  const char *path;

  path = (*env)->GetStringUTFChars (env, jpath, NULL);

  r = guestfs_cap_get_file (g, path);

  (*env)->ReleaseStringUTFChars (env, jpath, path);

  if (r == NULL) {
    throw_exception (env, guestfs_last_error (g));
    return NULL;
  }
  jr = (*env)->NewStringUTF (env, r);
  free (r);
  return jr;
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1cap_1set_1file  (JNIEnv *env, jobject obj, jlong jg, jstring jpath, jstring jcap)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *path;
  const char *cap;

  path = (*env)->GetStringUTFChars (env, jpath, NULL);
  cap = (*env)->GetStringUTFChars (env, jcap, NULL);

  r = guestfs_cap_set_file (g, path, cap);

  (*env)->ReleaseStringUTFChars (env, jpath, path);
  (*env)->ReleaseStringUTFChars (env, jcap, cap);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT jstring JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1case_1sensitive_1path  (JNIEnv *env, jobject obj, jlong jg, jstring jpath)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  jstring jr;
  char *r;
  const char *path;

  path = (*env)->GetStringUTFChars (env, jpath, NULL);

  r = guestfs_case_sensitive_path (g, path);

  (*env)->ReleaseStringUTFChars (env, jpath, path);

  if (r == NULL) {
    throw_exception (env, guestfs_last_error (g));
    return NULL;
  }
  jr = (*env)->NewStringUTF (env, r);
  free (r);
  return jr;
}

JNIEXPORT jstring JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1cat  (JNIEnv *env, jobject obj, jlong jg, jstring jpath)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  jstring jr;
  char *r;
  const char *path;

  path = (*env)->GetStringUTFChars (env, jpath, NULL);

  r = guestfs_cat (g, path);

  (*env)->ReleaseStringUTFChars (env, jpath, path);

  if (r == NULL) {
    throw_exception (env, guestfs_last_error (g));
    return NULL;
  }
  jr = (*env)->NewStringUTF (env, r);
  free (r);
  return jr;
}

JNIEXPORT jstring JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1checksum  (JNIEnv *env, jobject obj, jlong jg, jstring jcsumtype, jstring jpath)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  jstring jr;
  char *r;
  const char *csumtype;
  const char *path;

  csumtype = (*env)->GetStringUTFChars (env, jcsumtype, NULL);
  path = (*env)->GetStringUTFChars (env, jpath, NULL);

  r = guestfs_checksum (g, csumtype, path);

  (*env)->ReleaseStringUTFChars (env, jcsumtype, csumtype);
  (*env)->ReleaseStringUTFChars (env, jpath, path);

  if (r == NULL) {
    throw_exception (env, guestfs_last_error (g));
    return NULL;
  }
  jr = (*env)->NewStringUTF (env, r);
  free (r);
  return jr;
}

JNIEXPORT jstring JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1checksum_1device  (JNIEnv *env, jobject obj, jlong jg, jstring jcsumtype, jstring jdevice)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  jstring jr;
  char *r;
  const char *csumtype;
  const char *device;

  csumtype = (*env)->GetStringUTFChars (env, jcsumtype, NULL);
  device = (*env)->GetStringUTFChars (env, jdevice, NULL);

  r = guestfs_checksum_device (g, csumtype, device);

  (*env)->ReleaseStringUTFChars (env, jcsumtype, csumtype);
  (*env)->ReleaseStringUTFChars (env, jdevice, device);

  if (r == NULL) {
    throw_exception (env, guestfs_last_error (g));
    return NULL;
  }
  jr = (*env)->NewStringUTF (env, r);
  free (r);
  return jr;
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1checksums_1out  (JNIEnv *env, jobject obj, jlong jg, jstring jcsumtype, jstring jdirectory, jstring jsumsfile)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *csumtype;
  const char *directory;
  const char *sumsfile;

  csumtype = (*env)->GetStringUTFChars (env, jcsumtype, NULL);
  directory = (*env)->GetStringUTFChars (env, jdirectory, NULL);
  sumsfile = (*env)->GetStringUTFChars (env, jsumsfile, NULL);

  r = guestfs_checksums_out (g, csumtype, directory, sumsfile);

  (*env)->ReleaseStringUTFChars (env, jcsumtype, csumtype);
  (*env)->ReleaseStringUTFChars (env, jdirectory, directory);
  (*env)->ReleaseStringUTFChars (env, jsumsfile, sumsfile);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1chmod  (JNIEnv *env, jobject obj, jlong jg, jint jmode, jstring jpath)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  int mode;
  const char *path;

  mode = jmode;
  path = (*env)->GetStringUTFChars (env, jpath, NULL);

  r = guestfs_chmod (g, mode, path);

  (*env)->ReleaseStringUTFChars (env, jpath, path);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1chown  (JNIEnv *env, jobject obj, jlong jg, jint jowner, jint jgroup, jstring jpath)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  int owner;
  int group;
  const char *path;

  owner = jowner;
  group = jgroup;
  path = (*env)->GetStringUTFChars (env, jpath, NULL);

  r = guestfs_chown (g, owner, group, path);

  (*env)->ReleaseStringUTFChars (env, jpath, path);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT jint JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1clear_1backend_1setting  (JNIEnv *env, jobject obj, jlong jg, jstring jname)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *name;

  name = (*env)->GetStringUTFChars (env, jname, NULL);

  r = guestfs_clear_backend_setting (g, name);

  (*env)->ReleaseStringUTFChars (env, jname, name);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return -1;
  }
  return (jint) r;
}

JNIEXPORT jstring JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1command  (JNIEnv *env, jobject obj, jlong jg, jobjectArray jarguments)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  jstring jr;
  char *r;
  size_t arguments_len;
  char **arguments;
  size_t i;

  arguments_len = (*env)->GetArrayLength (env, jarguments);
  arguments = guestfs___safe_malloc (g, sizeof (char *) * (arguments_len+1));
  for (i = 0; i < arguments_len; ++i) {
    jobject o = (*env)->GetObjectArrayElement (env, jarguments, i);
    arguments[i] = (char *) (*env)->GetStringUTFChars (env, o, NULL);
  }
  arguments[arguments_len] = NULL;

  r = guestfs_command (g, arguments);

  for (i = 0; i < arguments_len; ++i) {
    jobject o = (*env)->GetObjectArrayElement (env, jarguments, i);
    (*env)->ReleaseStringUTFChars (env, o, arguments[i]);
  }
  free (arguments);

  if (r == NULL) {
    throw_exception (env, guestfs_last_error (g));
    return NULL;
  }
  jr = (*env)->NewStringUTF (env, r);
  free (r);
  return jr;
}

JNIEXPORT jobjectArray JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1command_1lines  (JNIEnv *env, jobject obj, jlong jg, jobjectArray jarguments)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  jobjectArray jr;
  size_t r_len;
  jclass cl;
  jstring jstr;
  char **r;
  size_t arguments_len;
  char **arguments;
  size_t i;

  arguments_len = (*env)->GetArrayLength (env, jarguments);
  arguments = guestfs___safe_malloc (g, sizeof (char *) * (arguments_len+1));
  for (i = 0; i < arguments_len; ++i) {
    jobject o = (*env)->GetObjectArrayElement (env, jarguments, i);
    arguments[i] = (char *) (*env)->GetStringUTFChars (env, o, NULL);
  }
  arguments[arguments_len] = NULL;

  r = guestfs_command_lines (g, arguments);

  for (i = 0; i < arguments_len; ++i) {
    jobject o = (*env)->GetObjectArrayElement (env, jarguments, i);
    (*env)->ReleaseStringUTFChars (env, o, arguments[i]);
  }
  free (arguments);

  if (r == NULL) {
    throw_exception (env, guestfs_last_error (g));
    return NULL;
  }
  for (r_len = 0; r[r_len] != NULL; ++r_len) ;
  cl = (*env)->FindClass (env, "java/lang/String");
  jstr = (*env)->NewStringUTF (env, "");
  jr = (*env)->NewObjectArray (env, r_len, cl, jstr);
  for (i = 0; i < r_len; ++i) {
    jstr = (*env)->NewStringUTF (env, r[i]);
    (*env)->SetObjectArrayElement (env, jr, i, jstr);
    free (r[i]);
  }
  free (r);
  return jr;
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1compress_1device_1out  (JNIEnv *env, jobject obj, jlong jg, jstring jctype, jstring jdevice, jstring jzdevice, jlong joptargs_bitmask, jint jlevel)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *ctype;
  const char *device;
  const char *zdevice;
  struct guestfs_compress_device_out_argv optargs_s;
  const struct guestfs_compress_device_out_argv *optargs = &optargs_s;

  ctype = (*env)->GetStringUTFChars (env, jctype, NULL);
  device = (*env)->GetStringUTFChars (env, jdevice, NULL);
  zdevice = (*env)->GetStringUTFChars (env, jzdevice, NULL);

  optargs_s.level = jlevel;
  optargs_s.bitmask = joptargs_bitmask;

  r = guestfs_compress_device_out_argv (g, ctype, device, zdevice, optargs);

  (*env)->ReleaseStringUTFChars (env, jctype, ctype);
  (*env)->ReleaseStringUTFChars (env, jdevice, device);
  (*env)->ReleaseStringUTFChars (env, jzdevice, zdevice);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1compress_1out  (JNIEnv *env, jobject obj, jlong jg, jstring jctype, jstring jfile, jstring jzfile, jlong joptargs_bitmask, jint jlevel)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *ctype;
  const char *file;
  const char *zfile;
  struct guestfs_compress_out_argv optargs_s;
  const struct guestfs_compress_out_argv *optargs = &optargs_s;

  ctype = (*env)->GetStringUTFChars (env, jctype, NULL);
  file = (*env)->GetStringUTFChars (env, jfile, NULL);
  zfile = (*env)->GetStringUTFChars (env, jzfile, NULL);

  optargs_s.level = jlevel;
  optargs_s.bitmask = joptargs_bitmask;

  r = guestfs_compress_out_argv (g, ctype, file, zfile, optargs);

  (*env)->ReleaseStringUTFChars (env, jctype, ctype);
  (*env)->ReleaseStringUTFChars (env, jfile, file);
  (*env)->ReleaseStringUTFChars (env, jzfile, zfile);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1config  (JNIEnv *env, jobject obj, jlong jg, jstring jhvparam, jstring jhvvalue)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *hvparam;
  const char *hvvalue;

  hvparam = (*env)->GetStringUTFChars (env, jhvparam, NULL);
  hvvalue = jhvvalue ? (*env)->GetStringUTFChars (env, jhvvalue, NULL) : NULL;

  r = guestfs_config (g, hvparam, hvvalue);

  (*env)->ReleaseStringUTFChars (env, jhvparam, hvparam);
  if (jhvvalue)
    (*env)->ReleaseStringUTFChars (env, jhvvalue, hvvalue);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1copy_1attributes  (JNIEnv *env, jobject obj, jlong jg, jstring jsrc, jstring jdest, jlong joptargs_bitmask, jboolean jall, jboolean jmode, jboolean jxattributes, jboolean jownership)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *src;
  const char *dest;
  struct guestfs_copy_attributes_argv optargs_s;
  const struct guestfs_copy_attributes_argv *optargs = &optargs_s;

  src = (*env)->GetStringUTFChars (env, jsrc, NULL);
  dest = (*env)->GetStringUTFChars (env, jdest, NULL);

  optargs_s.all = jall;
  optargs_s.mode = jmode;
  optargs_s.xattributes = jxattributes;
  optargs_s.ownership = jownership;
  optargs_s.bitmask = joptargs_bitmask;

  r = guestfs_copy_attributes_argv (g, src, dest, optargs);

  (*env)->ReleaseStringUTFChars (env, jsrc, src);
  (*env)->ReleaseStringUTFChars (env, jdest, dest);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1copy_1device_1to_1device  (JNIEnv *env, jobject obj, jlong jg, jstring jsrc, jstring jdest, jlong joptargs_bitmask, jlong jsrcoffset, jlong jdestoffset, jlong jsize, jboolean jsparse)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *src;
  const char *dest;
  struct guestfs_copy_device_to_device_argv optargs_s;
  const struct guestfs_copy_device_to_device_argv *optargs = &optargs_s;

  src = (*env)->GetStringUTFChars (env, jsrc, NULL);
  dest = (*env)->GetStringUTFChars (env, jdest, NULL);

  optargs_s.srcoffset = jsrcoffset;
  optargs_s.destoffset = jdestoffset;
  optargs_s.size = jsize;
  optargs_s.sparse = jsparse;
  optargs_s.bitmask = joptargs_bitmask;

  r = guestfs_copy_device_to_device_argv (g, src, dest, optargs);

  (*env)->ReleaseStringUTFChars (env, jsrc, src);
  (*env)->ReleaseStringUTFChars (env, jdest, dest);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1copy_1device_1to_1file  (JNIEnv *env, jobject obj, jlong jg, jstring jsrc, jstring jdest, jlong joptargs_bitmask, jlong jsrcoffset, jlong jdestoffset, jlong jsize, jboolean jsparse)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *src;
  const char *dest;
  struct guestfs_copy_device_to_file_argv optargs_s;
  const struct guestfs_copy_device_to_file_argv *optargs = &optargs_s;

  src = (*env)->GetStringUTFChars (env, jsrc, NULL);
  dest = (*env)->GetStringUTFChars (env, jdest, NULL);

  optargs_s.srcoffset = jsrcoffset;
  optargs_s.destoffset = jdestoffset;
  optargs_s.size = jsize;
  optargs_s.sparse = jsparse;
  optargs_s.bitmask = joptargs_bitmask;

  r = guestfs_copy_device_to_file_argv (g, src, dest, optargs);

  (*env)->ReleaseStringUTFChars (env, jsrc, src);
  (*env)->ReleaseStringUTFChars (env, jdest, dest);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1copy_1file_1to_1device  (JNIEnv *env, jobject obj, jlong jg, jstring jsrc, jstring jdest, jlong joptargs_bitmask, jlong jsrcoffset, jlong jdestoffset, jlong jsize, jboolean jsparse)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *src;
  const char *dest;
  struct guestfs_copy_file_to_device_argv optargs_s;
  const struct guestfs_copy_file_to_device_argv *optargs = &optargs_s;

  src = (*env)->GetStringUTFChars (env, jsrc, NULL);
  dest = (*env)->GetStringUTFChars (env, jdest, NULL);

  optargs_s.srcoffset = jsrcoffset;
  optargs_s.destoffset = jdestoffset;
  optargs_s.size = jsize;
  optargs_s.sparse = jsparse;
  optargs_s.bitmask = joptargs_bitmask;

  r = guestfs_copy_file_to_device_argv (g, src, dest, optargs);

  (*env)->ReleaseStringUTFChars (env, jsrc, src);
  (*env)->ReleaseStringUTFChars (env, jdest, dest);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1copy_1file_1to_1file  (JNIEnv *env, jobject obj, jlong jg, jstring jsrc, jstring jdest, jlong joptargs_bitmask, jlong jsrcoffset, jlong jdestoffset, jlong jsize, jboolean jsparse)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *src;
  const char *dest;
  struct guestfs_copy_file_to_file_argv optargs_s;
  const struct guestfs_copy_file_to_file_argv *optargs = &optargs_s;

  src = (*env)->GetStringUTFChars (env, jsrc, NULL);
  dest = (*env)->GetStringUTFChars (env, jdest, NULL);

  optargs_s.srcoffset = jsrcoffset;
  optargs_s.destoffset = jdestoffset;
  optargs_s.size = jsize;
  optargs_s.sparse = jsparse;
  optargs_s.bitmask = joptargs_bitmask;

  r = guestfs_copy_file_to_file_argv (g, src, dest, optargs);

  (*env)->ReleaseStringUTFChars (env, jsrc, src);
  (*env)->ReleaseStringUTFChars (env, jdest, dest);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1copy_1size  (JNIEnv *env, jobject obj, jlong jg, jstring jsrc, jstring jdest, jlong jsize)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *src;
  const char *dest;
  int64_t size;

  src = (*env)->GetStringUTFChars (env, jsrc, NULL);
  dest = (*env)->GetStringUTFChars (env, jdest, NULL);
  size = jsize;

  r = guestfs_copy_size (g, src, dest, size);

  (*env)->ReleaseStringUTFChars (env, jsrc, src);
  (*env)->ReleaseStringUTFChars (env, jdest, dest);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1cp  (JNIEnv *env, jobject obj, jlong jg, jstring jsrc, jstring jdest)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *src;
  const char *dest;

  src = (*env)->GetStringUTFChars (env, jsrc, NULL);
  dest = (*env)->GetStringUTFChars (env, jdest, NULL);

  r = guestfs_cp (g, src, dest);

  (*env)->ReleaseStringUTFChars (env, jsrc, src);
  (*env)->ReleaseStringUTFChars (env, jdest, dest);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1cp_1a  (JNIEnv *env, jobject obj, jlong jg, jstring jsrc, jstring jdest)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *src;
  const char *dest;

  src = (*env)->GetStringUTFChars (env, jsrc, NULL);
  dest = (*env)->GetStringUTFChars (env, jdest, NULL);

  r = guestfs_cp_a (g, src, dest);

  (*env)->ReleaseStringUTFChars (env, jsrc, src);
  (*env)->ReleaseStringUTFChars (env, jdest, dest);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1cp_1r  (JNIEnv *env, jobject obj, jlong jg, jstring jsrc, jstring jdest)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *src;
  const char *dest;

  src = (*env)->GetStringUTFChars (env, jsrc, NULL);
  dest = (*env)->GetStringUTFChars (env, jdest, NULL);

  r = guestfs_cp_r (g, src, dest);

  (*env)->ReleaseStringUTFChars (env, jsrc, src);
  (*env)->ReleaseStringUTFChars (env, jdest, dest);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1cpio_1out  (JNIEnv *env, jobject obj, jlong jg, jstring jdirectory, jstring jcpiofile, jlong joptargs_bitmask, jstring jformat)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *directory;
  const char *cpiofile;
  struct guestfs_cpio_out_argv optargs_s;
  const struct guestfs_cpio_out_argv *optargs = &optargs_s;

  directory = (*env)->GetStringUTFChars (env, jdirectory, NULL);
  cpiofile = (*env)->GetStringUTFChars (env, jcpiofile, NULL);

  optargs_s.format = (*env)->GetStringUTFChars (env, jformat, NULL);
  optargs_s.bitmask = joptargs_bitmask;

  r = guestfs_cpio_out_argv (g, directory, cpiofile, optargs);

  (*env)->ReleaseStringUTFChars (env, jdirectory, directory);
  (*env)->ReleaseStringUTFChars (env, jcpiofile, cpiofile);
  (*env)->ReleaseStringUTFChars (env, jformat, optargs_s.format);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1dd  (JNIEnv *env, jobject obj, jlong jg, jstring jsrc, jstring jdest)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *src;
  const char *dest;

  src = (*env)->GetStringUTFChars (env, jsrc, NULL);
  dest = (*env)->GetStringUTFChars (env, jdest, NULL);

  r = guestfs_dd (g, src, dest);

  (*env)->ReleaseStringUTFChars (env, jsrc, src);
  (*env)->ReleaseStringUTFChars (env, jdest, dest);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT jstring JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1debug  (JNIEnv *env, jobject obj, jlong jg, jstring jsubcmd, jobjectArray jextraargs)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  jstring jr;
  char *r;
  const char *subcmd;
  size_t extraargs_len;
  char **extraargs;
  size_t i;

  subcmd = (*env)->GetStringUTFChars (env, jsubcmd, NULL);
  extraargs_len = (*env)->GetArrayLength (env, jextraargs);
  extraargs = guestfs___safe_malloc (g, sizeof (char *) * (extraargs_len+1));
  for (i = 0; i < extraargs_len; ++i) {
    jobject o = (*env)->GetObjectArrayElement (env, jextraargs, i);
    extraargs[i] = (char *) (*env)->GetStringUTFChars (env, o, NULL);
  }
  extraargs[extraargs_len] = NULL;

  r = guestfs_debug (g, subcmd, extraargs);

  (*env)->ReleaseStringUTFChars (env, jsubcmd, subcmd);
  for (i = 0; i < extraargs_len; ++i) {
    jobject o = (*env)->GetObjectArrayElement (env, jextraargs, i);
    (*env)->ReleaseStringUTFChars (env, o, extraargs[i]);
  }
  free (extraargs);

  if (r == NULL) {
    throw_exception (env, guestfs_last_error (g));
    return NULL;
  }
  jr = (*env)->NewStringUTF (env, r);
  free (r);
  return jr;
}

JNIEXPORT jobjectArray JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1debug_1drives  (JNIEnv *env, jobject obj, jlong jg)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  jobjectArray jr;
  size_t r_len;
  jclass cl;
  jstring jstr;
  char **r;
  size_t i;


  r = guestfs_debug_drives (g);


  if (r == NULL) {
    throw_exception (env, guestfs_last_error (g));
    return NULL;
  }
  for (r_len = 0; r[r_len] != NULL; ++r_len) ;
  cl = (*env)->FindClass (env, "java/lang/String");
  jstr = (*env)->NewStringUTF (env, "");
  jr = (*env)->NewObjectArray (env, r_len, cl, jstr);
  for (i = 0; i < r_len; ++i) {
    jstr = (*env)->NewStringUTF (env, r[i]);
    (*env)->SetObjectArrayElement (env, jr, i, jstr);
    free (r[i]);
  }
  free (r);
  return jr;
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1debug_1upload  (JNIEnv *env, jobject obj, jlong jg, jstring jfilename, jstring jtmpname, jint jmode)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *filename;
  const char *tmpname;
  int mode;

  filename = (*env)->GetStringUTFChars (env, jfilename, NULL);
  tmpname = (*env)->GetStringUTFChars (env, jtmpname, NULL);
  mode = jmode;

  r = guestfs_debug_upload (g, filename, tmpname, mode);

  (*env)->ReleaseStringUTFChars (env, jfilename, filename);
  (*env)->ReleaseStringUTFChars (env, jtmpname, tmpname);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT jint JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1device_1index  (JNIEnv *env, jobject obj, jlong jg, jstring jdevice)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *device;

  device = (*env)->GetStringUTFChars (env, jdevice, NULL);

  r = guestfs_device_index (g, device);

  (*env)->ReleaseStringUTFChars (env, jdevice, device);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return -1;
  }
  return (jint) r;
}

JNIEXPORT jstring JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1df  (JNIEnv *env, jobject obj, jlong jg)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  jstring jr;
  char *r;


  r = guestfs_df (g);


  if (r == NULL) {
    throw_exception (env, guestfs_last_error (g));
    return NULL;
  }
  jr = (*env)->NewStringUTF (env, r);
  free (r);
  return jr;
}

JNIEXPORT jstring JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1df_1h  (JNIEnv *env, jobject obj, jlong jg)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  jstring jr;
  char *r;


  r = guestfs_df_h (g);


  if (r == NULL) {
    throw_exception (env, guestfs_last_error (g));
    return NULL;
  }
  jr = (*env)->NewStringUTF (env, r);
  free (r);
  return jr;
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1disk_1create  (JNIEnv *env, jobject obj, jlong jg, jstring jfilename, jstring jformat, jlong jsize, jlong joptargs_bitmask, jstring jbackingfile, jstring jbackingformat, jstring jpreallocation, jstring jcompat, jint jclustersize)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *filename;
  const char *format;
  int64_t size;
  struct guestfs_disk_create_argv optargs_s;
  const struct guestfs_disk_create_argv *optargs = &optargs_s;

  filename = (*env)->GetStringUTFChars (env, jfilename, NULL);
  format = (*env)->GetStringUTFChars (env, jformat, NULL);
  size = jsize;

  optargs_s.backingfile = (*env)->GetStringUTFChars (env, jbackingfile, NULL);
  optargs_s.backingformat = (*env)->GetStringUTFChars (env, jbackingformat, NULL);
  optargs_s.preallocation = (*env)->GetStringUTFChars (env, jpreallocation, NULL);
  optargs_s.compat = (*env)->GetStringUTFChars (env, jcompat, NULL);
  optargs_s.clustersize = jclustersize;
  optargs_s.bitmask = joptargs_bitmask;

  r = guestfs_disk_create_argv (g, filename, format, size, optargs);

  (*env)->ReleaseStringUTFChars (env, jfilename, filename);
  (*env)->ReleaseStringUTFChars (env, jformat, format);
  (*env)->ReleaseStringUTFChars (env, jbackingfile, optargs_s.backingfile);
  (*env)->ReleaseStringUTFChars (env, jbackingformat, optargs_s.backingformat);
  (*env)->ReleaseStringUTFChars (env, jpreallocation, optargs_s.preallocation);
  (*env)->ReleaseStringUTFChars (env, jcompat, optargs_s.compat);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT jstring JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1disk_1format  (JNIEnv *env, jobject obj, jlong jg, jstring jfilename)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  jstring jr;
  char *r;
  const char *filename;

  filename = (*env)->GetStringUTFChars (env, jfilename, NULL);

  r = guestfs_disk_format (g, filename);

  (*env)->ReleaseStringUTFChars (env, jfilename, filename);

  if (r == NULL) {
    throw_exception (env, guestfs_last_error (g));
    return NULL;
  }
  jr = (*env)->NewStringUTF (env, r);
  free (r);
  return jr;
}

JNIEXPORT jboolean JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1disk_1has_1backing_1file  (JNIEnv *env, jobject obj, jlong jg, jstring jfilename)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *filename;

  filename = (*env)->GetStringUTFChars (env, jfilename, NULL);

  r = guestfs_disk_has_backing_file (g, filename);

  (*env)->ReleaseStringUTFChars (env, jfilename, filename);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return -1;
  }
  return (jboolean) r;
}

JNIEXPORT jlong JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1disk_1virtual_1size  (JNIEnv *env, jobject obj, jlong jg, jstring jfilename)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int64_t r;
  const char *filename;

  filename = (*env)->GetStringUTFChars (env, jfilename, NULL);

  r = guestfs_disk_virtual_size (g, filename);

  (*env)->ReleaseStringUTFChars (env, jfilename, filename);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return -1;
  }
  return (jlong) r;
}

JNIEXPORT jstring JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1dmesg  (JNIEnv *env, jobject obj, jlong jg)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  jstring jr;
  char *r;


  r = guestfs_dmesg (g);


  if (r == NULL) {
    throw_exception (env, guestfs_last_error (g));
    return NULL;
  }
  jr = (*env)->NewStringUTF (env, r);
  free (r);
  return jr;
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1download  (JNIEnv *env, jobject obj, jlong jg, jstring jremotefilename, jstring jfilename)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *remotefilename;
  const char *filename;

  remotefilename = (*env)->GetStringUTFChars (env, jremotefilename, NULL);
  filename = (*env)->GetStringUTFChars (env, jfilename, NULL);

  r = guestfs_download (g, remotefilename, filename);

  (*env)->ReleaseStringUTFChars (env, jremotefilename, remotefilename);
  (*env)->ReleaseStringUTFChars (env, jfilename, filename);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1download_1offset  (JNIEnv *env, jobject obj, jlong jg, jstring jremotefilename, jstring jfilename, jlong joffset, jlong jsize)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *remotefilename;
  const char *filename;
  int64_t offset;
  int64_t size;

  remotefilename = (*env)->GetStringUTFChars (env, jremotefilename, NULL);
  filename = (*env)->GetStringUTFChars (env, jfilename, NULL);
  offset = joffset;
  size = jsize;

  r = guestfs_download_offset (g, remotefilename, filename, offset, size);

  (*env)->ReleaseStringUTFChars (env, jremotefilename, remotefilename);
  (*env)->ReleaseStringUTFChars (env, jfilename, filename);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1drop_1caches  (JNIEnv *env, jobject obj, jlong jg, jint jwhattodrop)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  int whattodrop;

  whattodrop = jwhattodrop;

  r = guestfs_drop_caches (g, whattodrop);


  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT jlong JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1du  (JNIEnv *env, jobject obj, jlong jg, jstring jpath)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int64_t r;
  const char *path;

  path = (*env)->GetStringUTFChars (env, jpath, NULL);

  r = guestfs_du (g, path);

  (*env)->ReleaseStringUTFChars (env, jpath, path);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return -1;
  }
  return (jlong) r;
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1e2fsck  (JNIEnv *env, jobject obj, jlong jg, jstring jdevice, jlong joptargs_bitmask, jboolean jcorrect, jboolean jforceall)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *device;
  struct guestfs_e2fsck_argv optargs_s;
  const struct guestfs_e2fsck_argv *optargs = &optargs_s;

  device = (*env)->GetStringUTFChars (env, jdevice, NULL);

  optargs_s.correct = jcorrect;
  optargs_s.forceall = jforceall;
  optargs_s.bitmask = joptargs_bitmask;

  r = guestfs_e2fsck_argv (g, device, optargs);

  (*env)->ReleaseStringUTFChars (env, jdevice, device);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1e2fsck_1f  (JNIEnv *env, jobject obj, jlong jg, jstring jdevice)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *device;

  device = (*env)->GetStringUTFChars (env, jdevice, NULL);

  r = guestfs_e2fsck_f (g, device);

  (*env)->ReleaseStringUTFChars (env, jdevice, device);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT jstring JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1echo_1daemon  (JNIEnv *env, jobject obj, jlong jg, jobjectArray jwords)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  jstring jr;
  char *r;
  size_t words_len;
  char **words;
  size_t i;

  words_len = (*env)->GetArrayLength (env, jwords);
  words = guestfs___safe_malloc (g, sizeof (char *) * (words_len+1));
  for (i = 0; i < words_len; ++i) {
    jobject o = (*env)->GetObjectArrayElement (env, jwords, i);
    words[i] = (char *) (*env)->GetStringUTFChars (env, o, NULL);
  }
  words[words_len] = NULL;

  r = guestfs_echo_daemon (g, words);

  for (i = 0; i < words_len; ++i) {
    jobject o = (*env)->GetObjectArrayElement (env, jwords, i);
    (*env)->ReleaseStringUTFChars (env, o, words[i]);
  }
  free (words);

  if (r == NULL) {
    throw_exception (env, guestfs_last_error (g));
    return NULL;
  }
  jr = (*env)->NewStringUTF (env, r);
  free (r);
  return jr;
}

JNIEXPORT jobjectArray JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1egrep  (JNIEnv *env, jobject obj, jlong jg, jstring jregex, jstring jpath)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  jobjectArray jr;
  size_t r_len;
  jclass cl;
  jstring jstr;
  char **r;
  const char *regex;
  const char *path;
  size_t i;

  regex = (*env)->GetStringUTFChars (env, jregex, NULL);
  path = (*env)->GetStringUTFChars (env, jpath, NULL);

  r = guestfs_egrep (g, regex, path);

  (*env)->ReleaseStringUTFChars (env, jregex, regex);
  (*env)->ReleaseStringUTFChars (env, jpath, path);

  if (r == NULL) {
    throw_exception (env, guestfs_last_error (g));
    return NULL;
  }
  for (r_len = 0; r[r_len] != NULL; ++r_len) ;
  cl = (*env)->FindClass (env, "java/lang/String");
  jstr = (*env)->NewStringUTF (env, "");
  jr = (*env)->NewObjectArray (env, r_len, cl, jstr);
  for (i = 0; i < r_len; ++i) {
    jstr = (*env)->NewStringUTF (env, r[i]);
    (*env)->SetObjectArrayElement (env, jr, i, jstr);
    free (r[i]);
  }
  free (r);
  return jr;
}

JNIEXPORT jobjectArray JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1egrepi  (JNIEnv *env, jobject obj, jlong jg, jstring jregex, jstring jpath)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  jobjectArray jr;
  size_t r_len;
  jclass cl;
  jstring jstr;
  char **r;
  const char *regex;
  const char *path;
  size_t i;

  regex = (*env)->GetStringUTFChars (env, jregex, NULL);
  path = (*env)->GetStringUTFChars (env, jpath, NULL);

  r = guestfs_egrepi (g, regex, path);

  (*env)->ReleaseStringUTFChars (env, jregex, regex);
  (*env)->ReleaseStringUTFChars (env, jpath, path);

  if (r == NULL) {
    throw_exception (env, guestfs_last_error (g));
    return NULL;
  }
  for (r_len = 0; r[r_len] != NULL; ++r_len) ;
  cl = (*env)->FindClass (env, "java/lang/String");
  jstr = (*env)->NewStringUTF (env, "");
  jr = (*env)->NewObjectArray (env, r_len, cl, jstr);
  for (i = 0; i < r_len; ++i) {
    jstr = (*env)->NewStringUTF (env, r[i]);
    (*env)->SetObjectArrayElement (env, jr, i, jstr);
    free (r[i]);
  }
  free (r);
  return jr;
}

JNIEXPORT jboolean JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1equal  (JNIEnv *env, jobject obj, jlong jg, jstring jfile1, jstring jfile2)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *file1;
  const char *file2;

  file1 = (*env)->GetStringUTFChars (env, jfile1, NULL);
  file2 = (*env)->GetStringUTFChars (env, jfile2, NULL);

  r = guestfs_equal (g, file1, file2);

  (*env)->ReleaseStringUTFChars (env, jfile1, file1);
  (*env)->ReleaseStringUTFChars (env, jfile2, file2);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return -1;
  }
  return (jboolean) r;
}

JNIEXPORT jboolean JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1exists  (JNIEnv *env, jobject obj, jlong jg, jstring jpath)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *path;

  path = (*env)->GetStringUTFChars (env, jpath, NULL);

  r = guestfs_exists (g, path);

  (*env)->ReleaseStringUTFChars (env, jpath, path);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return -1;
  }
  return (jboolean) r;
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1extlinux  (JNIEnv *env, jobject obj, jlong jg, jstring jdirectory)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *directory;

  directory = (*env)->GetStringUTFChars (env, jdirectory, NULL);

  r = guestfs_extlinux (g, directory);

  (*env)->ReleaseStringUTFChars (env, jdirectory, directory);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1fallocate  (JNIEnv *env, jobject obj, jlong jg, jstring jpath, jint jlen)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *path;
  int len;

  path = (*env)->GetStringUTFChars (env, jpath, NULL);
  len = jlen;

  r = guestfs_fallocate (g, path, len);

  (*env)->ReleaseStringUTFChars (env, jpath, path);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1fallocate64  (JNIEnv *env, jobject obj, jlong jg, jstring jpath, jlong jlen)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *path;
  int64_t len;

  path = (*env)->GetStringUTFChars (env, jpath, NULL);
  len = jlen;

  r = guestfs_fallocate64 (g, path, len);

  (*env)->ReleaseStringUTFChars (env, jpath, path);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT jboolean JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1feature_1available  (JNIEnv *env, jobject obj, jlong jg, jobjectArray jgroups)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  size_t groups_len;
  char **groups;
  size_t i;

  groups_len = (*env)->GetArrayLength (env, jgroups);
  groups = guestfs___safe_malloc (g, sizeof (char *) * (groups_len+1));
  for (i = 0; i < groups_len; ++i) {
    jobject o = (*env)->GetObjectArrayElement (env, jgroups, i);
    groups[i] = (char *) (*env)->GetStringUTFChars (env, o, NULL);
  }
  groups[groups_len] = NULL;

  r = guestfs_feature_available (g, groups);

  for (i = 0; i < groups_len; ++i) {
    jobject o = (*env)->GetObjectArrayElement (env, jgroups, i);
    (*env)->ReleaseStringUTFChars (env, o, groups[i]);
  }
  free (groups);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return -1;
  }
  return (jboolean) r;
}

JNIEXPORT jobjectArray JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1fgrep  (JNIEnv *env, jobject obj, jlong jg, jstring jpattern, jstring jpath)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  jobjectArray jr;
  size_t r_len;
  jclass cl;
  jstring jstr;
  char **r;
  const char *pattern;
  const char *path;
  size_t i;

  pattern = (*env)->GetStringUTFChars (env, jpattern, NULL);
  path = (*env)->GetStringUTFChars (env, jpath, NULL);

  r = guestfs_fgrep (g, pattern, path);

  (*env)->ReleaseStringUTFChars (env, jpattern, pattern);
  (*env)->ReleaseStringUTFChars (env, jpath, path);

  if (r == NULL) {
    throw_exception (env, guestfs_last_error (g));
    return NULL;
  }
  for (r_len = 0; r[r_len] != NULL; ++r_len) ;
  cl = (*env)->FindClass (env, "java/lang/String");
  jstr = (*env)->NewStringUTF (env, "");
  jr = (*env)->NewObjectArray (env, r_len, cl, jstr);
  for (i = 0; i < r_len; ++i) {
    jstr = (*env)->NewStringUTF (env, r[i]);
    (*env)->SetObjectArrayElement (env, jr, i, jstr);
    free (r[i]);
  }
  free (r);
  return jr;
}

JNIEXPORT jobjectArray JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1fgrepi  (JNIEnv *env, jobject obj, jlong jg, jstring jpattern, jstring jpath)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  jobjectArray jr;
  size_t r_len;
  jclass cl;
  jstring jstr;
  char **r;
  const char *pattern;
  const char *path;
  size_t i;

  pattern = (*env)->GetStringUTFChars (env, jpattern, NULL);
  path = (*env)->GetStringUTFChars (env, jpath, NULL);

  r = guestfs_fgrepi (g, pattern, path);

  (*env)->ReleaseStringUTFChars (env, jpattern, pattern);
  (*env)->ReleaseStringUTFChars (env, jpath, path);

  if (r == NULL) {
    throw_exception (env, guestfs_last_error (g));
    return NULL;
  }
  for (r_len = 0; r[r_len] != NULL; ++r_len) ;
  cl = (*env)->FindClass (env, "java/lang/String");
  jstr = (*env)->NewStringUTF (env, "");
  jr = (*env)->NewObjectArray (env, r_len, cl, jstr);
  for (i = 0; i < r_len; ++i) {
    jstr = (*env)->NewStringUTF (env, r[i]);
    (*env)->SetObjectArrayElement (env, jr, i, jstr);
    free (r[i]);
  }
  free (r);
  return jr;
}

JNIEXPORT jstring JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1file  (JNIEnv *env, jobject obj, jlong jg, jstring jpath)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  jstring jr;
  char *r;
  const char *path;

  path = (*env)->GetStringUTFChars (env, jpath, NULL);

  r = guestfs_file (g, path);

  (*env)->ReleaseStringUTFChars (env, jpath, path);

  if (r == NULL) {
    throw_exception (env, guestfs_last_error (g));
    return NULL;
  }
  jr = (*env)->NewStringUTF (env, r);
  free (r);
  return jr;
}

JNIEXPORT jstring JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1file_1architecture  (JNIEnv *env, jobject obj, jlong jg, jstring jfilename)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  jstring jr;
  char *r;
  const char *filename;

  filename = (*env)->GetStringUTFChars (env, jfilename, NULL);

  r = guestfs_file_architecture (g, filename);

  (*env)->ReleaseStringUTFChars (env, jfilename, filename);

  if (r == NULL) {
    throw_exception (env, guestfs_last_error (g));
    return NULL;
  }
  jr = (*env)->NewStringUTF (env, r);
  free (r);
  return jr;
}

JNIEXPORT jlong JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1filesize  (JNIEnv *env, jobject obj, jlong jg, jstring jfile)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int64_t r;
  const char *file;

  file = (*env)->GetStringUTFChars (env, jfile, NULL);

  r = guestfs_filesize (g, file);

  (*env)->ReleaseStringUTFChars (env, jfile, file);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return -1;
  }
  return (jlong) r;
}

JNIEXPORT jboolean JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1filesystem_1available  (JNIEnv *env, jobject obj, jlong jg, jstring jfilesystem)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *filesystem;

  filesystem = (*env)->GetStringUTFChars (env, jfilesystem, NULL);

  r = guestfs_filesystem_available (g, filesystem);

  (*env)->ReleaseStringUTFChars (env, jfilesystem, filesystem);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return -1;
  }
  return (jboolean) r;
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1fill  (JNIEnv *env, jobject obj, jlong jg, jint jc, jint jlen, jstring jpath)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  int c;
  int len;
  const char *path;

  c = jc;
  len = jlen;
  path = (*env)->GetStringUTFChars (env, jpath, NULL);

  r = guestfs_fill (g, c, len, path);

  (*env)->ReleaseStringUTFChars (env, jpath, path);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1fill_1dir  (JNIEnv *env, jobject obj, jlong jg, jstring jdir, jint jnr)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *dir;
  int nr;

  dir = (*env)->GetStringUTFChars (env, jdir, NULL);
  nr = jnr;

  r = guestfs_fill_dir (g, dir, nr);

  (*env)->ReleaseStringUTFChars (env, jdir, dir);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1fill_1pattern  (JNIEnv *env, jobject obj, jlong jg, jstring jpattern, jint jlen, jstring jpath)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *pattern;
  int len;
  const char *path;

  pattern = (*env)->GetStringUTFChars (env, jpattern, NULL);
  len = jlen;
  path = (*env)->GetStringUTFChars (env, jpath, NULL);

  r = guestfs_fill_pattern (g, pattern, len, path);

  (*env)->ReleaseStringUTFChars (env, jpattern, pattern);
  (*env)->ReleaseStringUTFChars (env, jpath, path);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT jobjectArray JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1find  (JNIEnv *env, jobject obj, jlong jg, jstring jdirectory)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  jobjectArray jr;
  size_t r_len;
  jclass cl;
  jstring jstr;
  char **r;
  const char *directory;
  size_t i;

  directory = (*env)->GetStringUTFChars (env, jdirectory, NULL);

  r = guestfs_find (g, directory);

  (*env)->ReleaseStringUTFChars (env, jdirectory, directory);

  if (r == NULL) {
    throw_exception (env, guestfs_last_error (g));
    return NULL;
  }
  for (r_len = 0; r[r_len] != NULL; ++r_len) ;
  cl = (*env)->FindClass (env, "java/lang/String");
  jstr = (*env)->NewStringUTF (env, "");
  jr = (*env)->NewObjectArray (env, r_len, cl, jstr);
  for (i = 0; i < r_len; ++i) {
    jstr = (*env)->NewStringUTF (env, r[i]);
    (*env)->SetObjectArrayElement (env, jr, i, jstr);
    free (r[i]);
  }
  free (r);
  return jr;
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1find0  (JNIEnv *env, jobject obj, jlong jg, jstring jdirectory, jstring jfiles)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *directory;
  const char *files;

  directory = (*env)->GetStringUTFChars (env, jdirectory, NULL);
  files = (*env)->GetStringUTFChars (env, jfiles, NULL);

  r = guestfs_find0 (g, directory, files);

  (*env)->ReleaseStringUTFChars (env, jdirectory, directory);
  (*env)->ReleaseStringUTFChars (env, jfiles, files);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT jstring JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1findfs_1label  (JNIEnv *env, jobject obj, jlong jg, jstring jlabel)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  jstring jr;
  char *r;
  const char *label;

  label = (*env)->GetStringUTFChars (env, jlabel, NULL);

  r = guestfs_findfs_label (g, label);

  (*env)->ReleaseStringUTFChars (env, jlabel, label);

  if (r == NULL) {
    throw_exception (env, guestfs_last_error (g));
    return NULL;
  }
  jr = (*env)->NewStringUTF (env, r);
  free (r);
  return jr;
}

JNIEXPORT jstring JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1findfs_1uuid  (JNIEnv *env, jobject obj, jlong jg, jstring juuid)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  jstring jr;
  char *r;
  const char *uuid;

  uuid = (*env)->GetStringUTFChars (env, juuid, NULL);

  r = guestfs_findfs_uuid (g, uuid);

  (*env)->ReleaseStringUTFChars (env, juuid, uuid);

  if (r == NULL) {
    throw_exception (env, guestfs_last_error (g));
    return NULL;
  }
  jr = (*env)->NewStringUTF (env, r);
  free (r);
  return jr;
}

JNIEXPORT jint JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1fsck  (JNIEnv *env, jobject obj, jlong jg, jstring jfstype, jstring jdevice)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *fstype;
  const char *device;

  fstype = (*env)->GetStringUTFChars (env, jfstype, NULL);
  device = (*env)->GetStringUTFChars (env, jdevice, NULL);

  r = guestfs_fsck (g, fstype, device);

  (*env)->ReleaseStringUTFChars (env, jfstype, fstype);
  (*env)->ReleaseStringUTFChars (env, jdevice, device);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return -1;
  }
  return (jint) r;
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1fstrim  (JNIEnv *env, jobject obj, jlong jg, jstring jmountpoint, jlong joptargs_bitmask, jlong joffset, jlong jlength, jlong jminimumfreeextent)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *mountpoint;
  struct guestfs_fstrim_argv optargs_s;
  const struct guestfs_fstrim_argv *optargs = &optargs_s;

  mountpoint = (*env)->GetStringUTFChars (env, jmountpoint, NULL);

  optargs_s.offset = joffset;
  optargs_s.length = jlength;
  optargs_s.minimumfreeextent = jminimumfreeextent;
  optargs_s.bitmask = joptargs_bitmask;

  r = guestfs_fstrim_argv (g, mountpoint, optargs);

  (*env)->ReleaseStringUTFChars (env, jmountpoint, mountpoint);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT jstring JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1get_1append  (JNIEnv *env, jobject obj, jlong jg)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  const char *r;


  r = guestfs_get_append (g);


  return (*env)->NewStringUTF (env, r); /* XXX r NULL? */
}

JNIEXPORT jstring JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1get_1attach_1method  (JNIEnv *env, jobject obj, jlong jg)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  jstring jr;
  char *r;


  r = guestfs_get_attach_method (g);


  if (r == NULL) {
    throw_exception (env, guestfs_last_error (g));
    return NULL;
  }
  jr = (*env)->NewStringUTF (env, r);
  free (r);
  return jr;
}

JNIEXPORT jboolean JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1get_1autosync  (JNIEnv *env, jobject obj, jlong jg)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;


  r = guestfs_get_autosync (g);


  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return -1;
  }
  return (jboolean) r;
}

JNIEXPORT jstring JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1get_1backend  (JNIEnv *env, jobject obj, jlong jg)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  jstring jr;
  char *r;


  r = guestfs_get_backend (g);


  if (r == NULL) {
    throw_exception (env, guestfs_last_error (g));
    return NULL;
  }
  jr = (*env)->NewStringUTF (env, r);
  free (r);
  return jr;
}

JNIEXPORT jstring JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1get_1backend_1setting  (JNIEnv *env, jobject obj, jlong jg, jstring jname)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  jstring jr;
  char *r;
  const char *name;

  name = (*env)->GetStringUTFChars (env, jname, NULL);

  r = guestfs_get_backend_setting (g, name);

  (*env)->ReleaseStringUTFChars (env, jname, name);

  if (r == NULL) {
    throw_exception (env, guestfs_last_error (g));
    return NULL;
  }
  jr = (*env)->NewStringUTF (env, r);
  free (r);
  return jr;
}

JNIEXPORT jobjectArray JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1get_1backend_1settings  (JNIEnv *env, jobject obj, jlong jg)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  jobjectArray jr;
  size_t r_len;
  jclass cl;
  jstring jstr;
  char **r;
  size_t i;


  r = guestfs_get_backend_settings (g);


  if (r == NULL) {
    throw_exception (env, guestfs_last_error (g));
    return NULL;
  }
  for (r_len = 0; r[r_len] != NULL; ++r_len) ;
  cl = (*env)->FindClass (env, "java/lang/String");
  jstr = (*env)->NewStringUTF (env, "");
  jr = (*env)->NewObjectArray (env, r_len, cl, jstr);
  for (i = 0; i < r_len; ++i) {
    jstr = (*env)->NewStringUTF (env, r[i]);
    (*env)->SetObjectArrayElement (env, jr, i, jstr);
    free (r[i]);
  }
  free (r);
  return jr;
}

JNIEXPORT jstring JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1get_1cachedir  (JNIEnv *env, jobject obj, jlong jg)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  jstring jr;
  char *r;


  r = guestfs_get_cachedir (g);


  if (r == NULL) {
    throw_exception (env, guestfs_last_error (g));
    return NULL;
  }
  jr = (*env)->NewStringUTF (env, r);
  free (r);
  return jr;
}

JNIEXPORT jboolean JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1get_1direct  (JNIEnv *env, jobject obj, jlong jg)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;


  r = guestfs_get_direct (g);


  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return -1;
  }
  return (jboolean) r;
}

JNIEXPORT jstring JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1get_1e2attrs  (JNIEnv *env, jobject obj, jlong jg, jstring jfile)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  jstring jr;
  char *r;
  const char *file;

  file = (*env)->GetStringUTFChars (env, jfile, NULL);

  r = guestfs_get_e2attrs (g, file);

  (*env)->ReleaseStringUTFChars (env, jfile, file);

  if (r == NULL) {
    throw_exception (env, guestfs_last_error (g));
    return NULL;
  }
  jr = (*env)->NewStringUTF (env, r);
  free (r);
  return jr;
}

JNIEXPORT jlong JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1get_1e2generation  (JNIEnv *env, jobject obj, jlong jg, jstring jfile)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int64_t r;
  const char *file;

  file = (*env)->GetStringUTFChars (env, jfile, NULL);

  r = guestfs_get_e2generation (g, file);

  (*env)->ReleaseStringUTFChars (env, jfile, file);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return -1;
  }
  return (jlong) r;
}

JNIEXPORT jstring JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1get_1e2label  (JNIEnv *env, jobject obj, jlong jg, jstring jdevice)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  jstring jr;
  char *r;
  const char *device;

  device = (*env)->GetStringUTFChars (env, jdevice, NULL);

  r = guestfs_get_e2label (g, device);

  (*env)->ReleaseStringUTFChars (env, jdevice, device);

  if (r == NULL) {
    throw_exception (env, guestfs_last_error (g));
    return NULL;
  }
  jr = (*env)->NewStringUTF (env, r);
  free (r);
  return jr;
}

JNIEXPORT jstring JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1get_1e2uuid  (JNIEnv *env, jobject obj, jlong jg, jstring jdevice)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  jstring jr;
  char *r;
  const char *device;

  device = (*env)->GetStringUTFChars (env, jdevice, NULL);

  r = guestfs_get_e2uuid (g, device);

  (*env)->ReleaseStringUTFChars (env, jdevice, device);

  if (r == NULL) {
    throw_exception (env, guestfs_last_error (g));
    return NULL;
  }
  jr = (*env)->NewStringUTF (env, r);
  free (r);
  return jr;
}

JNIEXPORT jstring JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1get_1hv  (JNIEnv *env, jobject obj, jlong jg)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  jstring jr;
  char *r;


  r = guestfs_get_hv (g);


  if (r == NULL) {
    throw_exception (env, guestfs_last_error (g));
    return NULL;
  }
  jr = (*env)->NewStringUTF (env, r);
  free (r);
  return jr;
}

JNIEXPORT jstring JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1get_1libvirt_1requested_1credential_1challenge  (JNIEnv *env, jobject obj, jlong jg, jint jindex)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  jstring jr;
  char *r;
  int index;

  index = jindex;

  r = guestfs_get_libvirt_requested_credential_challenge (g, index);


  if (r == NULL) {
    throw_exception (env, guestfs_last_error (g));
    return NULL;
  }
  jr = (*env)->NewStringUTF (env, r);
  free (r);
  return jr;
}

JNIEXPORT jstring JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1get_1libvirt_1requested_1credential_1defresult  (JNIEnv *env, jobject obj, jlong jg, jint jindex)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  jstring jr;
  char *r;
  int index;

  index = jindex;

  r = guestfs_get_libvirt_requested_credential_defresult (g, index);


  if (r == NULL) {
    throw_exception (env, guestfs_last_error (g));
    return NULL;
  }
  jr = (*env)->NewStringUTF (env, r);
  free (r);
  return jr;
}

JNIEXPORT jstring JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1get_1libvirt_1requested_1credential_1prompt  (JNIEnv *env, jobject obj, jlong jg, jint jindex)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  jstring jr;
  char *r;
  int index;

  index = jindex;

  r = guestfs_get_libvirt_requested_credential_prompt (g, index);


  if (r == NULL) {
    throw_exception (env, guestfs_last_error (g));
    return NULL;
  }
  jr = (*env)->NewStringUTF (env, r);
  free (r);
  return jr;
}

JNIEXPORT jobjectArray JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1get_1libvirt_1requested_1credentials  (JNIEnv *env, jobject obj, jlong jg)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  jobjectArray jr;
  size_t r_len;
  jclass cl;
  jstring jstr;
  char **r;
  size_t i;


  r = guestfs_get_libvirt_requested_credentials (g);


  if (r == NULL) {
    throw_exception (env, guestfs_last_error (g));
    return NULL;
  }
  for (r_len = 0; r[r_len] != NULL; ++r_len) ;
  cl = (*env)->FindClass (env, "java/lang/String");
  jstr = (*env)->NewStringUTF (env, "");
  jr = (*env)->NewObjectArray (env, r_len, cl, jstr);
  for (i = 0; i < r_len; ++i) {
    jstr = (*env)->NewStringUTF (env, r[i]);
    (*env)->SetObjectArrayElement (env, jr, i, jstr);
    free (r[i]);
  }
  free (r);
  return jr;
}

JNIEXPORT jint JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1get_1memsize  (JNIEnv *env, jobject obj, jlong jg)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;


  r = guestfs_get_memsize (g);


  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return -1;
  }
  return (jint) r;
}

JNIEXPORT jboolean JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1get_1network  (JNIEnv *env, jobject obj, jlong jg)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;


  r = guestfs_get_network (g);


  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return -1;
  }
  return (jboolean) r;
}

JNIEXPORT jstring JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1get_1path  (JNIEnv *env, jobject obj, jlong jg)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  const char *r;


  r = guestfs_get_path (g);


  if (r == NULL) {
    throw_exception (env, guestfs_last_error (g));
    return NULL;
  }
  return (*env)->NewStringUTF (env, r);
}

JNIEXPORT jboolean JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1get_1pgroup  (JNIEnv *env, jobject obj, jlong jg)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;


  r = guestfs_get_pgroup (g);


  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return -1;
  }
  return (jboolean) r;
}

JNIEXPORT jint JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1get_1pid  (JNIEnv *env, jobject obj, jlong jg)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;


  r = guestfs_get_pid (g);


  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return -1;
  }
  return (jint) r;
}

JNIEXPORT jstring JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1get_1program  (JNIEnv *env, jobject obj, jlong jg)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  const char *r;


  r = guestfs_get_program (g);


  if (r == NULL) {
    throw_exception (env, guestfs_last_error (g));
    return NULL;
  }
  return (*env)->NewStringUTF (env, r);
}

JNIEXPORT jstring JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1get_1qemu  (JNIEnv *env, jobject obj, jlong jg)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  const char *r;


  r = guestfs_get_qemu (g);


  if (r == NULL) {
    throw_exception (env, guestfs_last_error (g));
    return NULL;
  }
  return (*env)->NewStringUTF (env, r);
}

JNIEXPORT jboolean JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1get_1recovery_1proc  (JNIEnv *env, jobject obj, jlong jg)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;


  r = guestfs_get_recovery_proc (g);


  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return -1;
  }
  return (jboolean) r;
}

JNIEXPORT jboolean JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1get_1selinux  (JNIEnv *env, jobject obj, jlong jg)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;


  r = guestfs_get_selinux (g);


  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return -1;
  }
  return (jboolean) r;
}

JNIEXPORT jint JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1get_1smp  (JNIEnv *env, jobject obj, jlong jg)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;


  r = guestfs_get_smp (g);


  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return -1;
  }
  return (jint) r;
}

JNIEXPORT jint JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1get_1state  (JNIEnv *env, jobject obj, jlong jg)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;


  r = guestfs_get_state (g);


  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return -1;
  }
  return (jint) r;
}

JNIEXPORT jstring JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1get_1tmpdir  (JNIEnv *env, jobject obj, jlong jg)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  jstring jr;
  char *r;


  r = guestfs_get_tmpdir (g);


  if (r == NULL) {
    throw_exception (env, guestfs_last_error (g));
    return NULL;
  }
  jr = (*env)->NewStringUTF (env, r);
  free (r);
  return jr;
}

JNIEXPORT jboolean JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1get_1trace  (JNIEnv *env, jobject obj, jlong jg)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;


  r = guestfs_get_trace (g);


  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return -1;
  }
  return (jboolean) r;
}

JNIEXPORT jint JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1get_1umask  (JNIEnv *env, jobject obj, jlong jg)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;


  r = guestfs_get_umask (g);


  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return -1;
  }
  return (jint) r;
}

JNIEXPORT jboolean JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1get_1verbose  (JNIEnv *env, jobject obj, jlong jg)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;


  r = guestfs_get_verbose (g);


  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return -1;
  }
  return (jboolean) r;
}

JNIEXPORT jstring JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1getcon  (JNIEnv *env, jobject obj, jlong jg)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  jstring jr;
  char *r;


  r = guestfs_getcon (g);


  if (r == NULL) {
    throw_exception (env, guestfs_last_error (g));
    return NULL;
  }
  jr = (*env)->NewStringUTF (env, r);
  free (r);
  return jr;
}

JNIEXPORT jstring JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1getxattr  (JNIEnv *env, jobject obj, jlong jg, jstring jpath, jstring jname)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  jstring jr;
  char *r;
  size_t size;
  const char *path;
  const char *name;

  path = (*env)->GetStringUTFChars (env, jpath, NULL);
  name = (*env)->GetStringUTFChars (env, jname, NULL);

  r = guestfs_getxattr (g, path, name, &size);

  (*env)->ReleaseStringUTFChars (env, jpath, path);
  (*env)->ReleaseStringUTFChars (env, jname, name);

  if (r == NULL) {
    throw_exception (env, guestfs_last_error (g));
    return NULL;
  }
  jr = (*env)->NewStringUTF (env, r); // XXX size
  free (r);
  return jr;
}

JNIEXPORT jobjectArray JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1getxattrs  (JNIEnv *env, jobject obj, jlong jg, jstring jpath)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  jobjectArray jr;
  jclass cl;
  jfieldID fl;
  jobject jfl;
  struct guestfs_xattr_list *r;
  const char *path;
  size_t i;

  path = (*env)->GetStringUTFChars (env, jpath, NULL);

  r = guestfs_getxattrs (g, path);

  (*env)->ReleaseStringUTFChars (env, jpath, path);

  if (r == NULL) {
    throw_exception (env, guestfs_last_error (g));
    return NULL;
  }
  cl = (*env)->FindClass (env, "com/redhat/et/libguestfs/XAttr");
  jr = (*env)->NewObjectArray (env, r->len, cl, NULL);

  for (i = 0; i < r->len; ++i) {
    jfl = (*env)->AllocObject (env, cl);

    fl = (*env)->GetFieldID (env, cl, "attrname",
                             "Ljava/lang/String;");
    (*env)->SetObjectField (env, jfl, fl,
                            (*env)->NewStringUTF (env, r->val[i].attrname));
    fl = (*env)->GetFieldID (env, cl, "attrval",
                             "Ljava/lang/String;");
    {
      size_t len = r->val[i].attrval_len;
      char s[len+1];
      memcpy (s, r->val[i].attrval, len);
      s[len] = 0;
      (*env)->SetObjectField (env, jfl, fl,
                              (*env)->NewStringUTF (env, s));
    }

    (*env)->SetObjectArrayElement (env, jr, i, jfl);
  }

  guestfs_free_xattr_list (r);
  return jr;
}

JNIEXPORT jobjectArray JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1glob_1expand  (JNIEnv *env, jobject obj, jlong jg, jstring jpattern)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  jobjectArray jr;
  size_t r_len;
  jclass cl;
  jstring jstr;
  char **r;
  const char *pattern;
  size_t i;

  pattern = (*env)->GetStringUTFChars (env, jpattern, NULL);

  r = guestfs_glob_expand (g, pattern);

  (*env)->ReleaseStringUTFChars (env, jpattern, pattern);

  if (r == NULL) {
    throw_exception (env, guestfs_last_error (g));
    return NULL;
  }
  for (r_len = 0; r[r_len] != NULL; ++r_len) ;
  cl = (*env)->FindClass (env, "java/lang/String");
  jstr = (*env)->NewStringUTF (env, "");
  jr = (*env)->NewObjectArray (env, r_len, cl, jstr);
  for (i = 0; i < r_len; ++i) {
    jstr = (*env)->NewStringUTF (env, r[i]);
    (*env)->SetObjectArrayElement (env, jr, i, jstr);
    free (r[i]);
  }
  free (r);
  return jr;
}

JNIEXPORT jobjectArray JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1grep  (JNIEnv *env, jobject obj, jlong jg, jstring jregex, jstring jpath, jlong joptargs_bitmask, jboolean jextended, jboolean jfixed, jboolean jinsensitive, jboolean jcompressed)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  jobjectArray jr;
  size_t r_len;
  jclass cl;
  jstring jstr;
  char **r;
  const char *regex;
  const char *path;
  struct guestfs_grep_opts_argv optargs_s;
  const struct guestfs_grep_opts_argv *optargs = &optargs_s;
  size_t i;

  regex = (*env)->GetStringUTFChars (env, jregex, NULL);
  path = (*env)->GetStringUTFChars (env, jpath, NULL);

  optargs_s.extended = jextended;
  optargs_s.fixed = jfixed;
  optargs_s.insensitive = jinsensitive;
  optargs_s.compressed = jcompressed;
  optargs_s.bitmask = joptargs_bitmask;

  r = guestfs_grep_opts_argv (g, regex, path, optargs);

  (*env)->ReleaseStringUTFChars (env, jregex, regex);
  (*env)->ReleaseStringUTFChars (env, jpath, path);

  if (r == NULL) {
    throw_exception (env, guestfs_last_error (g));
    return NULL;
  }
  for (r_len = 0; r[r_len] != NULL; ++r_len) ;
  cl = (*env)->FindClass (env, "java/lang/String");
  jstr = (*env)->NewStringUTF (env, "");
  jr = (*env)->NewObjectArray (env, r_len, cl, jstr);
  for (i = 0; i < r_len; ++i) {
    jstr = (*env)->NewStringUTF (env, r[i]);
    (*env)->SetObjectArrayElement (env, jr, i, jstr);
    free (r[i]);
  }
  free (r);
  return jr;
}

JNIEXPORT jobjectArray JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1grepi  (JNIEnv *env, jobject obj, jlong jg, jstring jregex, jstring jpath)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  jobjectArray jr;
  size_t r_len;
  jclass cl;
  jstring jstr;
  char **r;
  const char *regex;
  const char *path;
  size_t i;

  regex = (*env)->GetStringUTFChars (env, jregex, NULL);
  path = (*env)->GetStringUTFChars (env, jpath, NULL);

  r = guestfs_grepi (g, regex, path);

  (*env)->ReleaseStringUTFChars (env, jregex, regex);
  (*env)->ReleaseStringUTFChars (env, jpath, path);

  if (r == NULL) {
    throw_exception (env, guestfs_last_error (g));
    return NULL;
  }
  for (r_len = 0; r[r_len] != NULL; ++r_len) ;
  cl = (*env)->FindClass (env, "java/lang/String");
  jstr = (*env)->NewStringUTF (env, "");
  jr = (*env)->NewObjectArray (env, r_len, cl, jstr);
  for (i = 0; i < r_len; ++i) {
    jstr = (*env)->NewStringUTF (env, r[i]);
    (*env)->SetObjectArrayElement (env, jr, i, jstr);
    free (r[i]);
  }
  free (r);
  return jr;
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1grub_1install  (JNIEnv *env, jobject obj, jlong jg, jstring jroot, jstring jdevice)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *root;
  const char *device;

  root = (*env)->GetStringUTFChars (env, jroot, NULL);
  device = (*env)->GetStringUTFChars (env, jdevice, NULL);

  r = guestfs_grub_install (g, root, device);

  (*env)->ReleaseStringUTFChars (env, jroot, root);
  (*env)->ReleaseStringUTFChars (env, jdevice, device);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT jobjectArray JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1head  (JNIEnv *env, jobject obj, jlong jg, jstring jpath)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  jobjectArray jr;
  size_t r_len;
  jclass cl;
  jstring jstr;
  char **r;
  const char *path;
  size_t i;

  path = (*env)->GetStringUTFChars (env, jpath, NULL);

  r = guestfs_head (g, path);

  (*env)->ReleaseStringUTFChars (env, jpath, path);

  if (r == NULL) {
    throw_exception (env, guestfs_last_error (g));
    return NULL;
  }
  for (r_len = 0; r[r_len] != NULL; ++r_len) ;
  cl = (*env)->FindClass (env, "java/lang/String");
  jstr = (*env)->NewStringUTF (env, "");
  jr = (*env)->NewObjectArray (env, r_len, cl, jstr);
  for (i = 0; i < r_len; ++i) {
    jstr = (*env)->NewStringUTF (env, r[i]);
    (*env)->SetObjectArrayElement (env, jr, i, jstr);
    free (r[i]);
  }
  free (r);
  return jr;
}

JNIEXPORT jobjectArray JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1head_1n  (JNIEnv *env, jobject obj, jlong jg, jint jnrlines, jstring jpath)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  jobjectArray jr;
  size_t r_len;
  jclass cl;
  jstring jstr;
  char **r;
  int nrlines;
  const char *path;
  size_t i;

  nrlines = jnrlines;
  path = (*env)->GetStringUTFChars (env, jpath, NULL);

  r = guestfs_head_n (g, nrlines, path);

  (*env)->ReleaseStringUTFChars (env, jpath, path);

  if (r == NULL) {
    throw_exception (env, guestfs_last_error (g));
    return NULL;
  }
  for (r_len = 0; r[r_len] != NULL; ++r_len) ;
  cl = (*env)->FindClass (env, "java/lang/String");
  jstr = (*env)->NewStringUTF (env, "");
  jr = (*env)->NewObjectArray (env, r_len, cl, jstr);
  for (i = 0; i < r_len; ++i) {
    jstr = (*env)->NewStringUTF (env, r[i]);
    (*env)->SetObjectArrayElement (env, jr, i, jstr);
    free (r[i]);
  }
  free (r);
  return jr;
}

JNIEXPORT jstring JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1hexdump  (JNIEnv *env, jobject obj, jlong jg, jstring jpath)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  jstring jr;
  char *r;
  const char *path;

  path = (*env)->GetStringUTFChars (env, jpath, NULL);

  r = guestfs_hexdump (g, path);

  (*env)->ReleaseStringUTFChars (env, jpath, path);

  if (r == NULL) {
    throw_exception (env, guestfs_last_error (g));
    return NULL;
  }
  jr = (*env)->NewStringUTF (env, r);
  free (r);
  return jr;
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1hivex_1close  (JNIEnv *env, jobject obj, jlong jg)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;


  r = guestfs_hivex_close (g);


  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1hivex_1commit  (JNIEnv *env, jobject obj, jlong jg, jstring jfilename)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *filename;

  filename = jfilename ? (*env)->GetStringUTFChars (env, jfilename, NULL) : NULL;

  r = guestfs_hivex_commit (g, filename);

  if (jfilename)
    (*env)->ReleaseStringUTFChars (env, jfilename, filename);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT jlong JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1hivex_1node_1add_1child  (JNIEnv *env, jobject obj, jlong jg, jlong jparent, jstring jname)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int64_t r;
  int64_t parent;
  const char *name;

  parent = jparent;
  name = (*env)->GetStringUTFChars (env, jname, NULL);

  r = guestfs_hivex_node_add_child (g, parent, name);

  (*env)->ReleaseStringUTFChars (env, jname, name);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return -1;
  }
  return (jlong) r;
}

JNIEXPORT jobjectArray JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1hivex_1node_1children  (JNIEnv *env, jobject obj, jlong jg, jlong jnodeh)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  jobjectArray jr;
  jclass cl;
  jfieldID fl;
  jobject jfl;
  struct guestfs_hivex_node_list *r;
  int64_t nodeh;
  size_t i;

  nodeh = jnodeh;

  r = guestfs_hivex_node_children (g, nodeh);


  if (r == NULL) {
    throw_exception (env, guestfs_last_error (g));
    return NULL;
  }
  cl = (*env)->FindClass (env, "com/redhat/et/libguestfs/HivexNode");
  jr = (*env)->NewObjectArray (env, r->len, cl, NULL);

  for (i = 0; i < r->len; ++i) {
    jfl = (*env)->AllocObject (env, cl);

    fl = (*env)->GetFieldID (env, cl, "hivex_node_h",
                             "J");
    (*env)->SetLongField (env, jfl, fl, r->val[i].hivex_node_h);

    (*env)->SetObjectArrayElement (env, jr, i, jfl);
  }

  guestfs_free_hivex_node_list (r);
  return jr;
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1hivex_1node_1delete_1child  (JNIEnv *env, jobject obj, jlong jg, jlong jnodeh)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  int64_t nodeh;

  nodeh = jnodeh;

  r = guestfs_hivex_node_delete_child (g, nodeh);


  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT jlong JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1hivex_1node_1get_1child  (JNIEnv *env, jobject obj, jlong jg, jlong jnodeh, jstring jname)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int64_t r;
  int64_t nodeh;
  const char *name;

  nodeh = jnodeh;
  name = (*env)->GetStringUTFChars (env, jname, NULL);

  r = guestfs_hivex_node_get_child (g, nodeh, name);

  (*env)->ReleaseStringUTFChars (env, jname, name);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return -1;
  }
  return (jlong) r;
}

JNIEXPORT jlong JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1hivex_1node_1get_1value  (JNIEnv *env, jobject obj, jlong jg, jlong jnodeh, jstring jkey)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int64_t r;
  int64_t nodeh;
  const char *key;

  nodeh = jnodeh;
  key = (*env)->GetStringUTFChars (env, jkey, NULL);

  r = guestfs_hivex_node_get_value (g, nodeh, key);

  (*env)->ReleaseStringUTFChars (env, jkey, key);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return -1;
  }
  return (jlong) r;
}

JNIEXPORT jstring JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1hivex_1node_1name  (JNIEnv *env, jobject obj, jlong jg, jlong jnodeh)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  jstring jr;
  char *r;
  int64_t nodeh;

  nodeh = jnodeh;

  r = guestfs_hivex_node_name (g, nodeh);


  if (r == NULL) {
    throw_exception (env, guestfs_last_error (g));
    return NULL;
  }
  jr = (*env)->NewStringUTF (env, r);
  free (r);
  return jr;
}

JNIEXPORT jlong JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1hivex_1node_1parent  (JNIEnv *env, jobject obj, jlong jg, jlong jnodeh)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int64_t r;
  int64_t nodeh;

  nodeh = jnodeh;

  r = guestfs_hivex_node_parent (g, nodeh);


  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return -1;
  }
  return (jlong) r;
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1hivex_1node_1set_1value  (JNIEnv *env, jobject obj, jlong jg, jlong jnodeh, jstring jkey, jlong jt, jbyteArray jval)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  int64_t nodeh;
  const char *key;
  int64_t t;
  char *val;
  size_t val_size;

  nodeh = jnodeh;
  key = (*env)->GetStringUTFChars (env, jkey, NULL);
  t = jt;
  val = (char *) (*env)->GetByteArrayElements (env, jval, NULL);
  val_size = (*env)->GetArrayLength (env, jval);

  r = guestfs_hivex_node_set_value (g, nodeh, key, t, val, val_size);

  (*env)->ReleaseStringUTFChars (env, jkey, key);
  (*env)->ReleaseByteArrayElements (env, jval, (jbyte *) val, 0);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT jobjectArray JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1hivex_1node_1values  (JNIEnv *env, jobject obj, jlong jg, jlong jnodeh)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  jobjectArray jr;
  jclass cl;
  jfieldID fl;
  jobject jfl;
  struct guestfs_hivex_value_list *r;
  int64_t nodeh;
  size_t i;

  nodeh = jnodeh;

  r = guestfs_hivex_node_values (g, nodeh);


  if (r == NULL) {
    throw_exception (env, guestfs_last_error (g));
    return NULL;
  }
  cl = (*env)->FindClass (env, "com/redhat/et/libguestfs/HivexValue");
  jr = (*env)->NewObjectArray (env, r->len, cl, NULL);

  for (i = 0; i < r->len; ++i) {
    jfl = (*env)->AllocObject (env, cl);

    fl = (*env)->GetFieldID (env, cl, "hivex_value_h",
                             "J");
    (*env)->SetLongField (env, jfl, fl, r->val[i].hivex_value_h);

    (*env)->SetObjectArrayElement (env, jr, i, jfl);
  }

  guestfs_free_hivex_value_list (r);
  return jr;
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1hivex_1open  (JNIEnv *env, jobject obj, jlong jg, jstring jfilename, jlong joptargs_bitmask, jboolean jverbose, jboolean jdebug, jboolean jwrite)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *filename;
  struct guestfs_hivex_open_argv optargs_s;
  const struct guestfs_hivex_open_argv *optargs = &optargs_s;

  filename = (*env)->GetStringUTFChars (env, jfilename, NULL);

  optargs_s.verbose = jverbose;
  optargs_s.debug = jdebug;
  optargs_s.write = jwrite;
  optargs_s.bitmask = joptargs_bitmask;

  r = guestfs_hivex_open_argv (g, filename, optargs);

  (*env)->ReleaseStringUTFChars (env, jfilename, filename);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT jlong JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1hivex_1root  (JNIEnv *env, jobject obj, jlong jg)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int64_t r;


  r = guestfs_hivex_root (g);


  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return -1;
  }
  return (jlong) r;
}

JNIEXPORT jstring JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1hivex_1value_1key  (JNIEnv *env, jobject obj, jlong jg, jlong jvalueh)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  jstring jr;
  char *r;
  int64_t valueh;

  valueh = jvalueh;

  r = guestfs_hivex_value_key (g, valueh);


  if (r == NULL) {
    throw_exception (env, guestfs_last_error (g));
    return NULL;
  }
  jr = (*env)->NewStringUTF (env, r);
  free (r);
  return jr;
}

JNIEXPORT jlong JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1hivex_1value_1type  (JNIEnv *env, jobject obj, jlong jg, jlong jvalueh)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int64_t r;
  int64_t valueh;

  valueh = jvalueh;

  r = guestfs_hivex_value_type (g, valueh);


  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return -1;
  }
  return (jlong) r;
}

JNIEXPORT jstring JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1hivex_1value_1utf8  (JNIEnv *env, jobject obj, jlong jg, jlong jvalueh)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  jstring jr;
  char *r;
  int64_t valueh;

  valueh = jvalueh;

  r = guestfs_hivex_value_utf8 (g, valueh);


  if (r == NULL) {
    throw_exception (env, guestfs_last_error (g));
    return NULL;
  }
  jr = (*env)->NewStringUTF (env, r);
  free (r);
  return jr;
}

JNIEXPORT jstring JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1hivex_1value_1value  (JNIEnv *env, jobject obj, jlong jg, jlong jvalueh)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  jstring jr;
  char *r;
  size_t size;
  int64_t valueh;

  valueh = jvalueh;

  r = guestfs_hivex_value_value (g, valueh, &size);


  if (r == NULL) {
    throw_exception (env, guestfs_last_error (g));
    return NULL;
  }
  jr = (*env)->NewStringUTF (env, r); // XXX size
  free (r);
  return jr;
}

JNIEXPORT jstring JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1initrd_1cat  (JNIEnv *env, jobject obj, jlong jg, jstring jinitrdpath, jstring jfilename)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  jstring jr;
  char *r;
  size_t size;
  const char *initrdpath;
  const char *filename;

  initrdpath = (*env)->GetStringUTFChars (env, jinitrdpath, NULL);
  filename = (*env)->GetStringUTFChars (env, jfilename, NULL);

  r = guestfs_initrd_cat (g, initrdpath, filename, &size);

  (*env)->ReleaseStringUTFChars (env, jinitrdpath, initrdpath);
  (*env)->ReleaseStringUTFChars (env, jfilename, filename);

  if (r == NULL) {
    throw_exception (env, guestfs_last_error (g));
    return NULL;
  }
  jr = (*env)->NewStringUTF (env, r); // XXX size
  free (r);
  return jr;
}

JNIEXPORT jobjectArray JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1initrd_1list  (JNIEnv *env, jobject obj, jlong jg, jstring jpath)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  jobjectArray jr;
  size_t r_len;
  jclass cl;
  jstring jstr;
  char **r;
  const char *path;
  size_t i;

  path = (*env)->GetStringUTFChars (env, jpath, NULL);

  r = guestfs_initrd_list (g, path);

  (*env)->ReleaseStringUTFChars (env, jpath, path);

  if (r == NULL) {
    throw_exception (env, guestfs_last_error (g));
    return NULL;
  }
  for (r_len = 0; r[r_len] != NULL; ++r_len) ;
  cl = (*env)->FindClass (env, "java/lang/String");
  jstr = (*env)->NewStringUTF (env, "");
  jr = (*env)->NewObjectArray (env, r_len, cl, jstr);
  for (i = 0; i < r_len; ++i) {
    jstr = (*env)->NewStringUTF (env, r[i]);
    (*env)->SetObjectArrayElement (env, jr, i, jstr);
    free (r[i]);
  }
  free (r);
  return jr;
}

JNIEXPORT jlong JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1inotify_1add_1watch  (JNIEnv *env, jobject obj, jlong jg, jstring jpath, jint jmask)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int64_t r;
  const char *path;
  int mask;

  path = (*env)->GetStringUTFChars (env, jpath, NULL);
  mask = jmask;

  r = guestfs_inotify_add_watch (g, path, mask);

  (*env)->ReleaseStringUTFChars (env, jpath, path);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return -1;
  }
  return (jlong) r;
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1inotify_1close  (JNIEnv *env, jobject obj, jlong jg)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;


  r = guestfs_inotify_close (g);


  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT jobjectArray JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1inotify_1files  (JNIEnv *env, jobject obj, jlong jg)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  jobjectArray jr;
  size_t r_len;
  jclass cl;
  jstring jstr;
  char **r;
  size_t i;


  r = guestfs_inotify_files (g);


  if (r == NULL) {
    throw_exception (env, guestfs_last_error (g));
    return NULL;
  }
  for (r_len = 0; r[r_len] != NULL; ++r_len) ;
  cl = (*env)->FindClass (env, "java/lang/String");
  jstr = (*env)->NewStringUTF (env, "");
  jr = (*env)->NewObjectArray (env, r_len, cl, jstr);
  for (i = 0; i < r_len; ++i) {
    jstr = (*env)->NewStringUTF (env, r[i]);
    (*env)->SetObjectArrayElement (env, jr, i, jstr);
    free (r[i]);
  }
  free (r);
  return jr;
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1inotify_1init  (JNIEnv *env, jobject obj, jlong jg, jint jmaxevents)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  int maxevents;

  maxevents = jmaxevents;

  r = guestfs_inotify_init (g, maxevents);


  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT jobjectArray JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1inotify_1read  (JNIEnv *env, jobject obj, jlong jg)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  jobjectArray jr;
  jclass cl;
  jfieldID fl;
  jobject jfl;
  struct guestfs_inotify_event_list *r;
  size_t i;


  r = guestfs_inotify_read (g);


  if (r == NULL) {
    throw_exception (env, guestfs_last_error (g));
    return NULL;
  }
  cl = (*env)->FindClass (env, "com/redhat/et/libguestfs/INotifyEvent");
  jr = (*env)->NewObjectArray (env, r->len, cl, NULL);

  for (i = 0; i < r->len; ++i) {
    jfl = (*env)->AllocObject (env, cl);

    fl = (*env)->GetFieldID (env, cl, "in_wd",
                             "J");
    (*env)->SetLongField (env, jfl, fl, r->val[i].in_wd);
    fl = (*env)->GetFieldID (env, cl, "in_mask",
                             "I");
    (*env)->SetIntField (env, jfl, fl, r->val[i].in_mask);
    fl = (*env)->GetFieldID (env, cl, "in_cookie",
                             "I");
    (*env)->SetIntField (env, jfl, fl, r->val[i].in_cookie);
    fl = (*env)->GetFieldID (env, cl, "in_name",
                             "Ljava/lang/String;");
    (*env)->SetObjectField (env, jfl, fl,
                            (*env)->NewStringUTF (env, r->val[i].in_name));

    (*env)->SetObjectArrayElement (env, jr, i, jfl);
  }

  guestfs_free_inotify_event_list (r);
  return jr;
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1inotify_1rm_1watch  (JNIEnv *env, jobject obj, jlong jg, jint jwd)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  int wd;

  wd = jwd;

  r = guestfs_inotify_rm_watch (g, wd);


  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT jstring JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1inspect_1get_1arch  (JNIEnv *env, jobject obj, jlong jg, jstring jroot)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  jstring jr;
  char *r;
  const char *root;

  root = (*env)->GetStringUTFChars (env, jroot, NULL);

  r = guestfs_inspect_get_arch (g, root);

  (*env)->ReleaseStringUTFChars (env, jroot, root);

  if (r == NULL) {
    throw_exception (env, guestfs_last_error (g));
    return NULL;
  }
  jr = (*env)->NewStringUTF (env, r);
  free (r);
  return jr;
}

JNIEXPORT jstring JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1inspect_1get_1distro  (JNIEnv *env, jobject obj, jlong jg, jstring jroot)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  jstring jr;
  char *r;
  const char *root;

  root = (*env)->GetStringUTFChars (env, jroot, NULL);

  r = guestfs_inspect_get_distro (g, root);

  (*env)->ReleaseStringUTFChars (env, jroot, root);

  if (r == NULL) {
    throw_exception (env, guestfs_last_error (g));
    return NULL;
  }
  jr = (*env)->NewStringUTF (env, r);
  free (r);
  return jr;
}

JNIEXPORT jobject JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1inspect_1get_1drive_1mappings  (JNIEnv *env, jobject obj, jlong jg, jstring jroot)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  jobjectArray jr;
  size_t r_len;
  jclass cl;
  jstring jstr;
  char **r;
  const char *root;
  size_t i;

  root = (*env)->GetStringUTFChars (env, jroot, NULL);

  r = guestfs_inspect_get_drive_mappings (g, root);

  (*env)->ReleaseStringUTFChars (env, jroot, root);

  if (r == NULL) {
    throw_exception (env, guestfs_last_error (g));
    return NULL;
  }
  for (r_len = 0; r[r_len] != NULL; ++r_len) ;
  cl = (*env)->FindClass (env, "java/lang/String");
  jstr = (*env)->NewStringUTF (env, "");
  jr = (*env)->NewObjectArray (env, r_len, cl, jstr);
  for (i = 0; i < r_len; ++i) {
    jstr = (*env)->NewStringUTF (env, r[i]);
    (*env)->SetObjectArrayElement (env, jr, i, jstr);
    free (r[i]);
  }
  free (r);
  return jr;
}

JNIEXPORT jobjectArray JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1inspect_1get_1filesystems  (JNIEnv *env, jobject obj, jlong jg, jstring jroot)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  jobjectArray jr;
  size_t r_len;
  jclass cl;
  jstring jstr;
  char **r;
  const char *root;
  size_t i;

  root = (*env)->GetStringUTFChars (env, jroot, NULL);

  r = guestfs_inspect_get_filesystems (g, root);

  (*env)->ReleaseStringUTFChars (env, jroot, root);

  if (r == NULL) {
    throw_exception (env, guestfs_last_error (g));
    return NULL;
  }
  for (r_len = 0; r[r_len] != NULL; ++r_len) ;
  cl = (*env)->FindClass (env, "java/lang/String");
  jstr = (*env)->NewStringUTF (env, "");
  jr = (*env)->NewObjectArray (env, r_len, cl, jstr);
  for (i = 0; i < r_len; ++i) {
    jstr = (*env)->NewStringUTF (env, r[i]);
    (*env)->SetObjectArrayElement (env, jr, i, jstr);
    free (r[i]);
  }
  free (r);
  return jr;
}

JNIEXPORT jstring JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1inspect_1get_1format  (JNIEnv *env, jobject obj, jlong jg, jstring jroot)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  jstring jr;
  char *r;
  const char *root;

  root = (*env)->GetStringUTFChars (env, jroot, NULL);

  r = guestfs_inspect_get_format (g, root);

  (*env)->ReleaseStringUTFChars (env, jroot, root);

  if (r == NULL) {
    throw_exception (env, guestfs_last_error (g));
    return NULL;
  }
  jr = (*env)->NewStringUTF (env, r);
  free (r);
  return jr;
}

JNIEXPORT jstring JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1inspect_1get_1hostname  (JNIEnv *env, jobject obj, jlong jg, jstring jroot)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  jstring jr;
  char *r;
  const char *root;

  root = (*env)->GetStringUTFChars (env, jroot, NULL);

  r = guestfs_inspect_get_hostname (g, root);

  (*env)->ReleaseStringUTFChars (env, jroot, root);

  if (r == NULL) {
    throw_exception (env, guestfs_last_error (g));
    return NULL;
  }
  jr = (*env)->NewStringUTF (env, r);
  free (r);
  return jr;
}

JNIEXPORT jstring JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1inspect_1get_1icon  (JNIEnv *env, jobject obj, jlong jg, jstring jroot, jlong joptargs_bitmask, jboolean jfavicon, jboolean jhighquality)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  jstring jr;
  char *r;
  size_t size;
  const char *root;
  struct guestfs_inspect_get_icon_argv optargs_s;
  const struct guestfs_inspect_get_icon_argv *optargs = &optargs_s;

  root = (*env)->GetStringUTFChars (env, jroot, NULL);

  optargs_s.favicon = jfavicon;
  optargs_s.highquality = jhighquality;
  optargs_s.bitmask = joptargs_bitmask;

  r = guestfs_inspect_get_icon_argv (g, root, &size, optargs);

  (*env)->ReleaseStringUTFChars (env, jroot, root);

  if (r == NULL) {
    throw_exception (env, guestfs_last_error (g));
    return NULL;
  }
  jr = (*env)->NewStringUTF (env, r); // XXX size
  free (r);
  return jr;
}

JNIEXPORT jint JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1inspect_1get_1major_1version  (JNIEnv *env, jobject obj, jlong jg, jstring jroot)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *root;

  root = (*env)->GetStringUTFChars (env, jroot, NULL);

  r = guestfs_inspect_get_major_version (g, root);

  (*env)->ReleaseStringUTFChars (env, jroot, root);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return -1;
  }
  return (jint) r;
}

JNIEXPORT jint JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1inspect_1get_1minor_1version  (JNIEnv *env, jobject obj, jlong jg, jstring jroot)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *root;

  root = (*env)->GetStringUTFChars (env, jroot, NULL);

  r = guestfs_inspect_get_minor_version (g, root);

  (*env)->ReleaseStringUTFChars (env, jroot, root);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return -1;
  }
  return (jint) r;
}

JNIEXPORT jobject JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1inspect_1get_1mountpoints  (JNIEnv *env, jobject obj, jlong jg, jstring jroot)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  jobjectArray jr;
  size_t r_len;
  jclass cl;
  jstring jstr;
  char **r;
  const char *root;
  size_t i;

  root = (*env)->GetStringUTFChars (env, jroot, NULL);

  r = guestfs_inspect_get_mountpoints (g, root);

  (*env)->ReleaseStringUTFChars (env, jroot, root);

  if (r == NULL) {
    throw_exception (env, guestfs_last_error (g));
    return NULL;
  }
  for (r_len = 0; r[r_len] != NULL; ++r_len) ;
  cl = (*env)->FindClass (env, "java/lang/String");
  jstr = (*env)->NewStringUTF (env, "");
  jr = (*env)->NewObjectArray (env, r_len, cl, jstr);
  for (i = 0; i < r_len; ++i) {
    jstr = (*env)->NewStringUTF (env, r[i]);
    (*env)->SetObjectArrayElement (env, jr, i, jstr);
    free (r[i]);
  }
  free (r);
  return jr;
}

JNIEXPORT jstring JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1inspect_1get_1package_1format  (JNIEnv *env, jobject obj, jlong jg, jstring jroot)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  jstring jr;
  char *r;
  const char *root;

  root = (*env)->GetStringUTFChars (env, jroot, NULL);

  r = guestfs_inspect_get_package_format (g, root);

  (*env)->ReleaseStringUTFChars (env, jroot, root);

  if (r == NULL) {
    throw_exception (env, guestfs_last_error (g));
    return NULL;
  }
  jr = (*env)->NewStringUTF (env, r);
  free (r);
  return jr;
}

JNIEXPORT jstring JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1inspect_1get_1package_1management  (JNIEnv *env, jobject obj, jlong jg, jstring jroot)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  jstring jr;
  char *r;
  const char *root;

  root = (*env)->GetStringUTFChars (env, jroot, NULL);

  r = guestfs_inspect_get_package_management (g, root);

  (*env)->ReleaseStringUTFChars (env, jroot, root);

  if (r == NULL) {
    throw_exception (env, guestfs_last_error (g));
    return NULL;
  }
  jr = (*env)->NewStringUTF (env, r);
  free (r);
  return jr;
}

JNIEXPORT jstring JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1inspect_1get_1product_1name  (JNIEnv *env, jobject obj, jlong jg, jstring jroot)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  jstring jr;
  char *r;
  const char *root;

  root = (*env)->GetStringUTFChars (env, jroot, NULL);

  r = guestfs_inspect_get_product_name (g, root);

  (*env)->ReleaseStringUTFChars (env, jroot, root);

  if (r == NULL) {
    throw_exception (env, guestfs_last_error (g));
    return NULL;
  }
  jr = (*env)->NewStringUTF (env, r);
  free (r);
  return jr;
}

JNIEXPORT jstring JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1inspect_1get_1product_1variant  (JNIEnv *env, jobject obj, jlong jg, jstring jroot)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  jstring jr;
  char *r;
  const char *root;

  root = (*env)->GetStringUTFChars (env, jroot, NULL);

  r = guestfs_inspect_get_product_variant (g, root);

  (*env)->ReleaseStringUTFChars (env, jroot, root);

  if (r == NULL) {
    throw_exception (env, guestfs_last_error (g));
    return NULL;
  }
  jr = (*env)->NewStringUTF (env, r);
  free (r);
  return jr;
}

JNIEXPORT jobjectArray JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1inspect_1get_1roots  (JNIEnv *env, jobject obj, jlong jg)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  jobjectArray jr;
  size_t r_len;
  jclass cl;
  jstring jstr;
  char **r;
  size_t i;


  r = guestfs_inspect_get_roots (g);


  if (r == NULL) {
    throw_exception (env, guestfs_last_error (g));
    return NULL;
  }
  for (r_len = 0; r[r_len] != NULL; ++r_len) ;
  cl = (*env)->FindClass (env, "java/lang/String");
  jstr = (*env)->NewStringUTF (env, "");
  jr = (*env)->NewObjectArray (env, r_len, cl, jstr);
  for (i = 0; i < r_len; ++i) {
    jstr = (*env)->NewStringUTF (env, r[i]);
    (*env)->SetObjectArrayElement (env, jr, i, jstr);
    free (r[i]);
  }
  free (r);
  return jr;
}

JNIEXPORT jstring JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1inspect_1get_1type  (JNIEnv *env, jobject obj, jlong jg, jstring jroot)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  jstring jr;
  char *r;
  const char *root;

  root = (*env)->GetStringUTFChars (env, jroot, NULL);

  r = guestfs_inspect_get_type (g, root);

  (*env)->ReleaseStringUTFChars (env, jroot, root);

  if (r == NULL) {
    throw_exception (env, guestfs_last_error (g));
    return NULL;
  }
  jr = (*env)->NewStringUTF (env, r);
  free (r);
  return jr;
}

JNIEXPORT jstring JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1inspect_1get_1windows_1current_1control_1set  (JNIEnv *env, jobject obj, jlong jg, jstring jroot)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  jstring jr;
  char *r;
  const char *root;

  root = (*env)->GetStringUTFChars (env, jroot, NULL);

  r = guestfs_inspect_get_windows_current_control_set (g, root);

  (*env)->ReleaseStringUTFChars (env, jroot, root);

  if (r == NULL) {
    throw_exception (env, guestfs_last_error (g));
    return NULL;
  }
  jr = (*env)->NewStringUTF (env, r);
  free (r);
  return jr;
}

JNIEXPORT jstring JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1inspect_1get_1windows_1systemroot  (JNIEnv *env, jobject obj, jlong jg, jstring jroot)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  jstring jr;
  char *r;
  const char *root;

  root = (*env)->GetStringUTFChars (env, jroot, NULL);

  r = guestfs_inspect_get_windows_systemroot (g, root);

  (*env)->ReleaseStringUTFChars (env, jroot, root);

  if (r == NULL) {
    throw_exception (env, guestfs_last_error (g));
    return NULL;
  }
  jr = (*env)->NewStringUTF (env, r);
  free (r);
  return jr;
}

JNIEXPORT jboolean JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1inspect_1is_1live  (JNIEnv *env, jobject obj, jlong jg, jstring jroot)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *root;

  root = (*env)->GetStringUTFChars (env, jroot, NULL);

  r = guestfs_inspect_is_live (g, root);

  (*env)->ReleaseStringUTFChars (env, jroot, root);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return -1;
  }
  return (jboolean) r;
}

JNIEXPORT jboolean JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1inspect_1is_1multipart  (JNIEnv *env, jobject obj, jlong jg, jstring jroot)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *root;

  root = (*env)->GetStringUTFChars (env, jroot, NULL);

  r = guestfs_inspect_is_multipart (g, root);

  (*env)->ReleaseStringUTFChars (env, jroot, root);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return -1;
  }
  return (jboolean) r;
}

JNIEXPORT jboolean JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1inspect_1is_1netinst  (JNIEnv *env, jobject obj, jlong jg, jstring jroot)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *root;

  root = (*env)->GetStringUTFChars (env, jroot, NULL);

  r = guestfs_inspect_is_netinst (g, root);

  (*env)->ReleaseStringUTFChars (env, jroot, root);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return -1;
  }
  return (jboolean) r;
}

JNIEXPORT jobjectArray JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1inspect_1list_1applications  (JNIEnv *env, jobject obj, jlong jg, jstring jroot)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  jobjectArray jr;
  jclass cl;
  jfieldID fl;
  jobject jfl;
  struct guestfs_application_list *r;
  const char *root;
  size_t i;

  root = (*env)->GetStringUTFChars (env, jroot, NULL);

  r = guestfs_inspect_list_applications (g, root);

  (*env)->ReleaseStringUTFChars (env, jroot, root);

  if (r == NULL) {
    throw_exception (env, guestfs_last_error (g));
    return NULL;
  }
  cl = (*env)->FindClass (env, "com/redhat/et/libguestfs/Application");
  jr = (*env)->NewObjectArray (env, r->len, cl, NULL);

  for (i = 0; i < r->len; ++i) {
    jfl = (*env)->AllocObject (env, cl);

    fl = (*env)->GetFieldID (env, cl, "app_name",
                             "Ljava/lang/String;");
    (*env)->SetObjectField (env, jfl, fl,
                            (*env)->NewStringUTF (env, r->val[i].app_name));
    fl = (*env)->GetFieldID (env, cl, "app_display_name",
                             "Ljava/lang/String;");
    (*env)->SetObjectField (env, jfl, fl,
                            (*env)->NewStringUTF (env, r->val[i].app_display_name));
    fl = (*env)->GetFieldID (env, cl, "app_epoch",
                             "I");
    (*env)->SetIntField (env, jfl, fl, r->val[i].app_epoch);
    fl = (*env)->GetFieldID (env, cl, "app_version",
                             "Ljava/lang/String;");
    (*env)->SetObjectField (env, jfl, fl,
                            (*env)->NewStringUTF (env, r->val[i].app_version));
    fl = (*env)->GetFieldID (env, cl, "app_release",
                             "Ljava/lang/String;");
    (*env)->SetObjectField (env, jfl, fl,
                            (*env)->NewStringUTF (env, r->val[i].app_release));
    fl = (*env)->GetFieldID (env, cl, "app_install_path",
                             "Ljava/lang/String;");
    (*env)->SetObjectField (env, jfl, fl,
                            (*env)->NewStringUTF (env, r->val[i].app_install_path));
    fl = (*env)->GetFieldID (env, cl, "app_trans_path",
                             "Ljava/lang/String;");
    (*env)->SetObjectField (env, jfl, fl,
                            (*env)->NewStringUTF (env, r->val[i].app_trans_path));
    fl = (*env)->GetFieldID (env, cl, "app_publisher",
                             "Ljava/lang/String;");
    (*env)->SetObjectField (env, jfl, fl,
                            (*env)->NewStringUTF (env, r->val[i].app_publisher));
    fl = (*env)->GetFieldID (env, cl, "app_url",
                             "Ljava/lang/String;");
    (*env)->SetObjectField (env, jfl, fl,
                            (*env)->NewStringUTF (env, r->val[i].app_url));
    fl = (*env)->GetFieldID (env, cl, "app_source_package",
                             "Ljava/lang/String;");
    (*env)->SetObjectField (env, jfl, fl,
                            (*env)->NewStringUTF (env, r->val[i].app_source_package));
    fl = (*env)->GetFieldID (env, cl, "app_summary",
                             "Ljava/lang/String;");
    (*env)->SetObjectField (env, jfl, fl,
                            (*env)->NewStringUTF (env, r->val[i].app_summary));
    fl = (*env)->GetFieldID (env, cl, "app_description",
                             "Ljava/lang/String;");
    (*env)->SetObjectField (env, jfl, fl,
                            (*env)->NewStringUTF (env, r->val[i].app_description));

    (*env)->SetObjectArrayElement (env, jr, i, jfl);
  }

  guestfs_free_application_list (r);
  return jr;
}

JNIEXPORT jobjectArray JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1inspect_1list_1applications2  (JNIEnv *env, jobject obj, jlong jg, jstring jroot)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  jobjectArray jr;
  jclass cl;
  jfieldID fl;
  jobject jfl;
  struct guestfs_application2_list *r;
  const char *root;
  size_t i;

  root = (*env)->GetStringUTFChars (env, jroot, NULL);

  r = guestfs_inspect_list_applications2 (g, root);

  (*env)->ReleaseStringUTFChars (env, jroot, root);

  if (r == NULL) {
    throw_exception (env, guestfs_last_error (g));
    return NULL;
  }
  cl = (*env)->FindClass (env, "com/redhat/et/libguestfs/Application2");
  jr = (*env)->NewObjectArray (env, r->len, cl, NULL);

  for (i = 0; i < r->len; ++i) {
    jfl = (*env)->AllocObject (env, cl);

    fl = (*env)->GetFieldID (env, cl, "app2_name",
                             "Ljava/lang/String;");
    (*env)->SetObjectField (env, jfl, fl,
                            (*env)->NewStringUTF (env, r->val[i].app2_name));
    fl = (*env)->GetFieldID (env, cl, "app2_display_name",
                             "Ljava/lang/String;");
    (*env)->SetObjectField (env, jfl, fl,
                            (*env)->NewStringUTF (env, r->val[i].app2_display_name));
    fl = (*env)->GetFieldID (env, cl, "app2_epoch",
                             "I");
    (*env)->SetIntField (env, jfl, fl, r->val[i].app2_epoch);
    fl = (*env)->GetFieldID (env, cl, "app2_version",
                             "Ljava/lang/String;");
    (*env)->SetObjectField (env, jfl, fl,
                            (*env)->NewStringUTF (env, r->val[i].app2_version));
    fl = (*env)->GetFieldID (env, cl, "app2_release",
                             "Ljava/lang/String;");
    (*env)->SetObjectField (env, jfl, fl,
                            (*env)->NewStringUTF (env, r->val[i].app2_release));
    fl = (*env)->GetFieldID (env, cl, "app2_arch",
                             "Ljava/lang/String;");
    (*env)->SetObjectField (env, jfl, fl,
                            (*env)->NewStringUTF (env, r->val[i].app2_arch));
    fl = (*env)->GetFieldID (env, cl, "app2_install_path",
                             "Ljava/lang/String;");
    (*env)->SetObjectField (env, jfl, fl,
                            (*env)->NewStringUTF (env, r->val[i].app2_install_path));
    fl = (*env)->GetFieldID (env, cl, "app2_trans_path",
                             "Ljava/lang/String;");
    (*env)->SetObjectField (env, jfl, fl,
                            (*env)->NewStringUTF (env, r->val[i].app2_trans_path));
    fl = (*env)->GetFieldID (env, cl, "app2_publisher",
                             "Ljava/lang/String;");
    (*env)->SetObjectField (env, jfl, fl,
                            (*env)->NewStringUTF (env, r->val[i].app2_publisher));
    fl = (*env)->GetFieldID (env, cl, "app2_url",
                             "Ljava/lang/String;");
    (*env)->SetObjectField (env, jfl, fl,
                            (*env)->NewStringUTF (env, r->val[i].app2_url));
    fl = (*env)->GetFieldID (env, cl, "app2_source_package",
                             "Ljava/lang/String;");
    (*env)->SetObjectField (env, jfl, fl,
                            (*env)->NewStringUTF (env, r->val[i].app2_source_package));
    fl = (*env)->GetFieldID (env, cl, "app2_summary",
                             "Ljava/lang/String;");
    (*env)->SetObjectField (env, jfl, fl,
                            (*env)->NewStringUTF (env, r->val[i].app2_summary));
    fl = (*env)->GetFieldID (env, cl, "app2_description",
                             "Ljava/lang/String;");
    (*env)->SetObjectField (env, jfl, fl,
                            (*env)->NewStringUTF (env, r->val[i].app2_description));
    fl = (*env)->GetFieldID (env, cl, "app2_spare1",
                             "Ljava/lang/String;");
    (*env)->SetObjectField (env, jfl, fl,
                            (*env)->NewStringUTF (env, r->val[i].app2_spare1));
    fl = (*env)->GetFieldID (env, cl, "app2_spare2",
                             "Ljava/lang/String;");
    (*env)->SetObjectField (env, jfl, fl,
                            (*env)->NewStringUTF (env, r->val[i].app2_spare2));
    fl = (*env)->GetFieldID (env, cl, "app2_spare3",
                             "Ljava/lang/String;");
    (*env)->SetObjectField (env, jfl, fl,
                            (*env)->NewStringUTF (env, r->val[i].app2_spare3));
    fl = (*env)->GetFieldID (env, cl, "app2_spare4",
                             "Ljava/lang/String;");
    (*env)->SetObjectField (env, jfl, fl,
                            (*env)->NewStringUTF (env, r->val[i].app2_spare4));

    (*env)->SetObjectArrayElement (env, jr, i, jfl);
  }

  guestfs_free_application2_list (r);
  return jr;
}

JNIEXPORT jobjectArray JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1inspect_1os  (JNIEnv *env, jobject obj, jlong jg)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  jobjectArray jr;
  size_t r_len;
  jclass cl;
  jstring jstr;
  char **r;
  size_t i;


  r = guestfs_inspect_os (g);


  if (r == NULL) {
    throw_exception (env, guestfs_last_error (g));
    return NULL;
  }
  for (r_len = 0; r[r_len] != NULL; ++r_len) ;
  cl = (*env)->FindClass (env, "java/lang/String");
  jstr = (*env)->NewStringUTF (env, "");
  jr = (*env)->NewObjectArray (env, r_len, cl, jstr);
  for (i = 0; i < r_len; ++i) {
    jstr = (*env)->NewStringUTF (env, r[i]);
    (*env)->SetObjectArrayElement (env, jr, i, jstr);
    free (r[i]);
  }
  free (r);
  return jr;
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1internal_1test  (JNIEnv *env, jobject obj, jlong jg, jstring jstr, jstring joptstr, jobjectArray jstrlist, jboolean jb, jint jinteger, jlong jinteger64, jstring jfilein, jstring jfileout, jbyteArray jbufferin, jlong joptargs_bitmask, jboolean jobool, jint joint, jlong joint64, jstring jostring, jobjectArray jostringlist)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *str;
  const char *optstr;
  size_t strlist_len;
  char **strlist;
  int b;
  int integer;
  int64_t integer64;
  const char *filein;
  const char *fileout;
  char *bufferin;
  size_t bufferin_size;
  struct guestfs_internal_test_argv optargs_s;
  const struct guestfs_internal_test_argv *optargs = &optargs_s;
  size_t ostringlist_len;
  char **ostringlist;
  size_t i;

  str = (*env)->GetStringUTFChars (env, jstr, NULL);
  optstr = joptstr ? (*env)->GetStringUTFChars (env, joptstr, NULL) : NULL;
  strlist_len = (*env)->GetArrayLength (env, jstrlist);
  strlist = guestfs___safe_malloc (g, sizeof (char *) * (strlist_len+1));
  for (i = 0; i < strlist_len; ++i) {
    jobject o = (*env)->GetObjectArrayElement (env, jstrlist, i);
    strlist[i] = (char *) (*env)->GetStringUTFChars (env, o, NULL);
  }
  strlist[strlist_len] = NULL;
  b = jb;
  integer = jinteger;
  integer64 = jinteger64;
  filein = (*env)->GetStringUTFChars (env, jfilein, NULL);
  fileout = (*env)->GetStringUTFChars (env, jfileout, NULL);
  bufferin = (char *) (*env)->GetByteArrayElements (env, jbufferin, NULL);
  bufferin_size = (*env)->GetArrayLength (env, jbufferin);

  optargs_s.obool = jobool;
  optargs_s.oint = joint;
  optargs_s.oint64 = joint64;
  optargs_s.ostring = (*env)->GetStringUTFChars (env, jostring, NULL);
  ostringlist_len = (*env)->GetArrayLength (env, jostringlist);
  ostringlist = guestfs___safe_malloc (g, sizeof (char *) * (ostringlist_len+1));
  for (i = 0; i < ostringlist_len; ++i) {
    jobject o = (*env)->GetObjectArrayElement (env, jostringlist, i);
    ostringlist[i] = (char *) (*env)->GetStringUTFChars (env, o, NULL);
  }
  ostringlist[ostringlist_len] = NULL;
  optargs_s.ostringlist = ostringlist;
  optargs_s.bitmask = joptargs_bitmask;

  r = guestfs_internal_test_argv (g, str, optstr, strlist, b, integer, integer64, filein, fileout, bufferin, bufferin_size, optargs);

  (*env)->ReleaseStringUTFChars (env, jstr, str);
  if (joptstr)
    (*env)->ReleaseStringUTFChars (env, joptstr, optstr);
  for (i = 0; i < strlist_len; ++i) {
    jobject o = (*env)->GetObjectArrayElement (env, jstrlist, i);
    (*env)->ReleaseStringUTFChars (env, o, strlist[i]);
  }
  free (strlist);
  (*env)->ReleaseStringUTFChars (env, jfilein, filein);
  (*env)->ReleaseStringUTFChars (env, jfileout, fileout);
  (*env)->ReleaseByteArrayElements (env, jbufferin, (jbyte *) bufferin, 0);
  (*env)->ReleaseStringUTFChars (env, jostring, optargs_s.ostring);
  for (i = 0; i < ostringlist_len; ++i) {
    jobject o = (*env)->GetObjectArrayElement (env, jostringlist, i);
    (*env)->ReleaseStringUTFChars (env, o, optargs_s.ostringlist[i]);
  }
  free (ostringlist);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1internal_1test_163_1optargs  (JNIEnv *env, jobject obj, jlong jg, jlong joptargs_bitmask, jint jopt1, jint jopt2, jint jopt3, jint jopt4, jint jopt5, jint jopt6, jint jopt7, jint jopt8, jint jopt9, jint jopt10, jint jopt11, jint jopt12, jint jopt13, jint jopt14, jint jopt15, jint jopt16, jint jopt17, jint jopt18, jint jopt19, jint jopt20, jint jopt21, jint jopt22, jint jopt23, jint jopt24, jint jopt25, jint jopt26, jint jopt27, jint jopt28, jint jopt29, jint jopt30, jint jopt31, jint jopt32, jint jopt33, jint jopt34, jint jopt35, jint jopt36, jint jopt37, jint jopt38, jint jopt39, jint jopt40, jint jopt41, jint jopt42, jint jopt43, jint jopt44, jint jopt45, jint jopt46, jint jopt47, jint jopt48, jint jopt49, jint jopt50, jint jopt51, jint jopt52, jint jopt53, jint jopt54, jint jopt55, jint jopt56, jint jopt57, jint jopt58, jint jopt59, jint jopt60, jint jopt61, jint jopt62, jint jopt63)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  struct guestfs_internal_test_63_optargs_argv optargs_s;
  const struct guestfs_internal_test_63_optargs_argv *optargs = &optargs_s;


  optargs_s.opt1 = jopt1;
  optargs_s.opt2 = jopt2;
  optargs_s.opt3 = jopt3;
  optargs_s.opt4 = jopt4;
  optargs_s.opt5 = jopt5;
  optargs_s.opt6 = jopt6;
  optargs_s.opt7 = jopt7;
  optargs_s.opt8 = jopt8;
  optargs_s.opt9 = jopt9;
  optargs_s.opt10 = jopt10;
  optargs_s.opt11 = jopt11;
  optargs_s.opt12 = jopt12;
  optargs_s.opt13 = jopt13;
  optargs_s.opt14 = jopt14;
  optargs_s.opt15 = jopt15;
  optargs_s.opt16 = jopt16;
  optargs_s.opt17 = jopt17;
  optargs_s.opt18 = jopt18;
  optargs_s.opt19 = jopt19;
  optargs_s.opt20 = jopt20;
  optargs_s.opt21 = jopt21;
  optargs_s.opt22 = jopt22;
  optargs_s.opt23 = jopt23;
  optargs_s.opt24 = jopt24;
  optargs_s.opt25 = jopt25;
  optargs_s.opt26 = jopt26;
  optargs_s.opt27 = jopt27;
  optargs_s.opt28 = jopt28;
  optargs_s.opt29 = jopt29;
  optargs_s.opt30 = jopt30;
  optargs_s.opt31 = jopt31;
  optargs_s.opt32 = jopt32;
  optargs_s.opt33 = jopt33;
  optargs_s.opt34 = jopt34;
  optargs_s.opt35 = jopt35;
  optargs_s.opt36 = jopt36;
  optargs_s.opt37 = jopt37;
  optargs_s.opt38 = jopt38;
  optargs_s.opt39 = jopt39;
  optargs_s.opt40 = jopt40;
  optargs_s.opt41 = jopt41;
  optargs_s.opt42 = jopt42;
  optargs_s.opt43 = jopt43;
  optargs_s.opt44 = jopt44;
  optargs_s.opt45 = jopt45;
  optargs_s.opt46 = jopt46;
  optargs_s.opt47 = jopt47;
  optargs_s.opt48 = jopt48;
  optargs_s.opt49 = jopt49;
  optargs_s.opt50 = jopt50;
  optargs_s.opt51 = jopt51;
  optargs_s.opt52 = jopt52;
  optargs_s.opt53 = jopt53;
  optargs_s.opt54 = jopt54;
  optargs_s.opt55 = jopt55;
  optargs_s.opt56 = jopt56;
  optargs_s.opt57 = jopt57;
  optargs_s.opt58 = jopt58;
  optargs_s.opt59 = jopt59;
  optargs_s.opt60 = jopt60;
  optargs_s.opt61 = jopt61;
  optargs_s.opt62 = jopt62;
  optargs_s.opt63 = jopt63;
  optargs_s.bitmask = joptargs_bitmask;

  r = guestfs_internal_test_63_optargs_argv (g, optargs);


  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1internal_1test_1close_1output  (JNIEnv *env, jobject obj, jlong jg)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;


  r = guestfs_internal_test_close_output (g);


  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1internal_1test_1only_1optargs  (JNIEnv *env, jobject obj, jlong jg, jlong joptargs_bitmask, jint jtest)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  struct guestfs_internal_test_only_optargs_argv optargs_s;
  const struct guestfs_internal_test_only_optargs_argv *optargs = &optargs_s;


  optargs_s.test = jtest;
  optargs_s.bitmask = joptargs_bitmask;

  r = guestfs_internal_test_only_optargs_argv (g, optargs);


  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT jboolean JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1internal_1test_1rbool  (JNIEnv *env, jobject obj, jlong jg, jstring jval)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *val;

  val = (*env)->GetStringUTFChars (env, jval, NULL);

  r = guestfs_internal_test_rbool (g, val);

  (*env)->ReleaseStringUTFChars (env, jval, val);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return -1;
  }
  return (jboolean) r;
}

JNIEXPORT jboolean JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1internal_1test_1rboolerr  (JNIEnv *env, jobject obj, jlong jg)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;


  r = guestfs_internal_test_rboolerr (g);


  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return -1;
  }
  return (jboolean) r;
}

JNIEXPORT jstring JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1internal_1test_1rbufferout  (JNIEnv *env, jobject obj, jlong jg, jstring jval)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  jstring jr;
  char *r;
  size_t size;
  const char *val;

  val = (*env)->GetStringUTFChars (env, jval, NULL);

  r = guestfs_internal_test_rbufferout (g, val, &size);

  (*env)->ReleaseStringUTFChars (env, jval, val);

  if (r == NULL) {
    throw_exception (env, guestfs_last_error (g));
    return NULL;
  }
  jr = (*env)->NewStringUTF (env, r); // XXX size
  free (r);
  return jr;
}

JNIEXPORT jstring JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1internal_1test_1rbufferouterr  (JNIEnv *env, jobject obj, jlong jg)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  jstring jr;
  char *r;
  size_t size;


  r = guestfs_internal_test_rbufferouterr (g, &size);


  if (r == NULL) {
    throw_exception (env, guestfs_last_error (g));
    return NULL;
  }
  jr = (*env)->NewStringUTF (env, r); // XXX size
  free (r);
  return jr;
}

JNIEXPORT jstring JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1internal_1test_1rconstoptstring  (JNIEnv *env, jobject obj, jlong jg, jstring jval)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  const char *r;
  const char *val;

  val = (*env)->GetStringUTFChars (env, jval, NULL);

  r = guestfs_internal_test_rconstoptstring (g, val);

  (*env)->ReleaseStringUTFChars (env, jval, val);

  return (*env)->NewStringUTF (env, r); /* XXX r NULL? */
}

JNIEXPORT jstring JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1internal_1test_1rconstoptstringerr  (JNIEnv *env, jobject obj, jlong jg)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  const char *r;


  r = guestfs_internal_test_rconstoptstringerr (g);


  return (*env)->NewStringUTF (env, r); /* XXX r NULL? */
}

JNIEXPORT jstring JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1internal_1test_1rconststring  (JNIEnv *env, jobject obj, jlong jg, jstring jval)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  const char *r;
  const char *val;

  val = (*env)->GetStringUTFChars (env, jval, NULL);

  r = guestfs_internal_test_rconststring (g, val);

  (*env)->ReleaseStringUTFChars (env, jval, val);

  if (r == NULL) {
    throw_exception (env, guestfs_last_error (g));
    return NULL;
  }
  return (*env)->NewStringUTF (env, r);
}

JNIEXPORT jstring JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1internal_1test_1rconststringerr  (JNIEnv *env, jobject obj, jlong jg)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  const char *r;


  r = guestfs_internal_test_rconststringerr (g);


  if (r == NULL) {
    throw_exception (env, guestfs_last_error (g));
    return NULL;
  }
  return (*env)->NewStringUTF (env, r);
}

JNIEXPORT jobject JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1internal_1test_1rhashtable  (JNIEnv *env, jobject obj, jlong jg, jstring jval)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  jobjectArray jr;
  size_t r_len;
  jclass cl;
  jstring jstr;
  char **r;
  const char *val;
  size_t i;

  val = (*env)->GetStringUTFChars (env, jval, NULL);

  r = guestfs_internal_test_rhashtable (g, val);

  (*env)->ReleaseStringUTFChars (env, jval, val);

  if (r == NULL) {
    throw_exception (env, guestfs_last_error (g));
    return NULL;
  }
  for (r_len = 0; r[r_len] != NULL; ++r_len) ;
  cl = (*env)->FindClass (env, "java/lang/String");
  jstr = (*env)->NewStringUTF (env, "");
  jr = (*env)->NewObjectArray (env, r_len, cl, jstr);
  for (i = 0; i < r_len; ++i) {
    jstr = (*env)->NewStringUTF (env, r[i]);
    (*env)->SetObjectArrayElement (env, jr, i, jstr);
    free (r[i]);
  }
  free (r);
  return jr;
}

JNIEXPORT jobject JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1internal_1test_1rhashtableerr  (JNIEnv *env, jobject obj, jlong jg)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  jobjectArray jr;
  size_t r_len;
  jclass cl;
  jstring jstr;
  char **r;
  size_t i;


  r = guestfs_internal_test_rhashtableerr (g);


  if (r == NULL) {
    throw_exception (env, guestfs_last_error (g));
    return NULL;
  }
  for (r_len = 0; r[r_len] != NULL; ++r_len) ;
  cl = (*env)->FindClass (env, "java/lang/String");
  jstr = (*env)->NewStringUTF (env, "");
  jr = (*env)->NewObjectArray (env, r_len, cl, jstr);
  for (i = 0; i < r_len; ++i) {
    jstr = (*env)->NewStringUTF (env, r[i]);
    (*env)->SetObjectArrayElement (env, jr, i, jstr);
    free (r[i]);
  }
  free (r);
  return jr;
}

JNIEXPORT jint JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1internal_1test_1rint  (JNIEnv *env, jobject obj, jlong jg, jstring jval)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *val;

  val = (*env)->GetStringUTFChars (env, jval, NULL);

  r = guestfs_internal_test_rint (g, val);

  (*env)->ReleaseStringUTFChars (env, jval, val);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return -1;
  }
  return (jint) r;
}

JNIEXPORT jlong JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1internal_1test_1rint64  (JNIEnv *env, jobject obj, jlong jg, jstring jval)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int64_t r;
  const char *val;

  val = (*env)->GetStringUTFChars (env, jval, NULL);

  r = guestfs_internal_test_rint64 (g, val);

  (*env)->ReleaseStringUTFChars (env, jval, val);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return -1;
  }
  return (jlong) r;
}

JNIEXPORT jlong JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1internal_1test_1rint64err  (JNIEnv *env, jobject obj, jlong jg)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int64_t r;


  r = guestfs_internal_test_rint64err (g);


  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return -1;
  }
  return (jlong) r;
}

JNIEXPORT jint JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1internal_1test_1rinterr  (JNIEnv *env, jobject obj, jlong jg)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;


  r = guestfs_internal_test_rinterr (g);


  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return -1;
  }
  return (jint) r;
}

JNIEXPORT jstring JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1internal_1test_1rstring  (JNIEnv *env, jobject obj, jlong jg, jstring jval)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  jstring jr;
  char *r;
  const char *val;

  val = (*env)->GetStringUTFChars (env, jval, NULL);

  r = guestfs_internal_test_rstring (g, val);

  (*env)->ReleaseStringUTFChars (env, jval, val);

  if (r == NULL) {
    throw_exception (env, guestfs_last_error (g));
    return NULL;
  }
  jr = (*env)->NewStringUTF (env, r);
  free (r);
  return jr;
}

JNIEXPORT jstring JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1internal_1test_1rstringerr  (JNIEnv *env, jobject obj, jlong jg)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  jstring jr;
  char *r;


  r = guestfs_internal_test_rstringerr (g);


  if (r == NULL) {
    throw_exception (env, guestfs_last_error (g));
    return NULL;
  }
  jr = (*env)->NewStringUTF (env, r);
  free (r);
  return jr;
}

JNIEXPORT jobjectArray JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1internal_1test_1rstringlist  (JNIEnv *env, jobject obj, jlong jg, jstring jval)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  jobjectArray jr;
  size_t r_len;
  jclass cl;
  jstring jstr;
  char **r;
  const char *val;
  size_t i;

  val = (*env)->GetStringUTFChars (env, jval, NULL);

  r = guestfs_internal_test_rstringlist (g, val);

  (*env)->ReleaseStringUTFChars (env, jval, val);

  if (r == NULL) {
    throw_exception (env, guestfs_last_error (g));
    return NULL;
  }
  for (r_len = 0; r[r_len] != NULL; ++r_len) ;
  cl = (*env)->FindClass (env, "java/lang/String");
  jstr = (*env)->NewStringUTF (env, "");
  jr = (*env)->NewObjectArray (env, r_len, cl, jstr);
  for (i = 0; i < r_len; ++i) {
    jstr = (*env)->NewStringUTF (env, r[i]);
    (*env)->SetObjectArrayElement (env, jr, i, jstr);
    free (r[i]);
  }
  free (r);
  return jr;
}

JNIEXPORT jobjectArray JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1internal_1test_1rstringlisterr  (JNIEnv *env, jobject obj, jlong jg)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  jobjectArray jr;
  size_t r_len;
  jclass cl;
  jstring jstr;
  char **r;
  size_t i;


  r = guestfs_internal_test_rstringlisterr (g);


  if (r == NULL) {
    throw_exception (env, guestfs_last_error (g));
    return NULL;
  }
  for (r_len = 0; r[r_len] != NULL; ++r_len) ;
  cl = (*env)->FindClass (env, "java/lang/String");
  jstr = (*env)->NewStringUTF (env, "");
  jr = (*env)->NewObjectArray (env, r_len, cl, jstr);
  for (i = 0; i < r_len; ++i) {
    jstr = (*env)->NewStringUTF (env, r[i]);
    (*env)->SetObjectArrayElement (env, jr, i, jstr);
    free (r[i]);
  }
  free (r);
  return jr;
}

JNIEXPORT jobject JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1internal_1test_1rstruct  (JNIEnv *env, jobject obj, jlong jg, jstring jval)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  jobject jr;
  jclass cl;
  jfieldID fl;
  struct guestfs_lvm_pv *r;
  const char *val;

  val = (*env)->GetStringUTFChars (env, jval, NULL);

  r = guestfs_internal_test_rstruct (g, val);

  (*env)->ReleaseStringUTFChars (env, jval, val);

  if (r == NULL) {
    throw_exception (env, guestfs_last_error (g));
    return NULL;
  }
  cl = (*env)->FindClass (env, "com/redhat/et/libguestfs/PV");
  jr = (*env)->AllocObject (env, cl);
  fl = (*env)->GetFieldID (env, cl, "pv_name", "Ljava/lang/String;");
  (*env)->SetObjectField (env, jr, fl, (*env)->NewStringUTF (env, r->pv_name));
  {
    char s[33];
    memcpy (s, r->pv_uuid, 32);
    s[32] = 0;
    fl = (*env)->GetFieldID (env, cl, "pv_uuid", "Ljava/lang/String;");
    (*env)->SetObjectField (env, jr, fl, (*env)->NewStringUTF (env, s));
  }
  fl = (*env)->GetFieldID (env, cl, "pv_fmt", "Ljava/lang/String;");
  (*env)->SetObjectField (env, jr, fl, (*env)->NewStringUTF (env, r->pv_fmt));
  fl = (*env)->GetFieldID (env, cl, "pv_size", "J");
  (*env)->SetLongField (env, jr, fl, r->pv_size);
  fl = (*env)->GetFieldID (env, cl, "dev_size", "J");
  (*env)->SetLongField (env, jr, fl, r->dev_size);
  fl = (*env)->GetFieldID (env, cl, "pv_free", "J");
  (*env)->SetLongField (env, jr, fl, r->pv_free);
  fl = (*env)->GetFieldID (env, cl, "pv_used", "J");
  (*env)->SetLongField (env, jr, fl, r->pv_used);
  fl = (*env)->GetFieldID (env, cl, "pv_attr", "Ljava/lang/String;");
  (*env)->SetObjectField (env, jr, fl, (*env)->NewStringUTF (env, r->pv_attr));
  fl = (*env)->GetFieldID (env, cl, "pv_pe_count", "J");
  (*env)->SetLongField (env, jr, fl, r->pv_pe_count);
  fl = (*env)->GetFieldID (env, cl, "pv_pe_alloc_count", "J");
  (*env)->SetLongField (env, jr, fl, r->pv_pe_alloc_count);
  fl = (*env)->GetFieldID (env, cl, "pv_tags", "Ljava/lang/String;");
  (*env)->SetObjectField (env, jr, fl, (*env)->NewStringUTF (env, r->pv_tags));
  fl = (*env)->GetFieldID (env, cl, "pe_start", "J");
  (*env)->SetLongField (env, jr, fl, r->pe_start);
  fl = (*env)->GetFieldID (env, cl, "pv_mda_count", "J");
  (*env)->SetLongField (env, jr, fl, r->pv_mda_count);
  fl = (*env)->GetFieldID (env, cl, "pv_mda_free", "J");
  (*env)->SetLongField (env, jr, fl, r->pv_mda_free);
  free (r);
  return jr;
}

JNIEXPORT jobject JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1internal_1test_1rstructerr  (JNIEnv *env, jobject obj, jlong jg)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  jobject jr;
  jclass cl;
  jfieldID fl;
  struct guestfs_lvm_pv *r;


  r = guestfs_internal_test_rstructerr (g);


  if (r == NULL) {
    throw_exception (env, guestfs_last_error (g));
    return NULL;
  }
  cl = (*env)->FindClass (env, "com/redhat/et/libguestfs/PV");
  jr = (*env)->AllocObject (env, cl);
  fl = (*env)->GetFieldID (env, cl, "pv_name", "Ljava/lang/String;");
  (*env)->SetObjectField (env, jr, fl, (*env)->NewStringUTF (env, r->pv_name));
  {
    char s[33];
    memcpy (s, r->pv_uuid, 32);
    s[32] = 0;
    fl = (*env)->GetFieldID (env, cl, "pv_uuid", "Ljava/lang/String;");
    (*env)->SetObjectField (env, jr, fl, (*env)->NewStringUTF (env, s));
  }
  fl = (*env)->GetFieldID (env, cl, "pv_fmt", "Ljava/lang/String;");
  (*env)->SetObjectField (env, jr, fl, (*env)->NewStringUTF (env, r->pv_fmt));
  fl = (*env)->GetFieldID (env, cl, "pv_size", "J");
  (*env)->SetLongField (env, jr, fl, r->pv_size);
  fl = (*env)->GetFieldID (env, cl, "dev_size", "J");
  (*env)->SetLongField (env, jr, fl, r->dev_size);
  fl = (*env)->GetFieldID (env, cl, "pv_free", "J");
  (*env)->SetLongField (env, jr, fl, r->pv_free);
  fl = (*env)->GetFieldID (env, cl, "pv_used", "J");
  (*env)->SetLongField (env, jr, fl, r->pv_used);
  fl = (*env)->GetFieldID (env, cl, "pv_attr", "Ljava/lang/String;");
  (*env)->SetObjectField (env, jr, fl, (*env)->NewStringUTF (env, r->pv_attr));
  fl = (*env)->GetFieldID (env, cl, "pv_pe_count", "J");
  (*env)->SetLongField (env, jr, fl, r->pv_pe_count);
  fl = (*env)->GetFieldID (env, cl, "pv_pe_alloc_count", "J");
  (*env)->SetLongField (env, jr, fl, r->pv_pe_alloc_count);
  fl = (*env)->GetFieldID (env, cl, "pv_tags", "Ljava/lang/String;");
  (*env)->SetObjectField (env, jr, fl, (*env)->NewStringUTF (env, r->pv_tags));
  fl = (*env)->GetFieldID (env, cl, "pe_start", "J");
  (*env)->SetLongField (env, jr, fl, r->pe_start);
  fl = (*env)->GetFieldID (env, cl, "pv_mda_count", "J");
  (*env)->SetLongField (env, jr, fl, r->pv_mda_count);
  fl = (*env)->GetFieldID (env, cl, "pv_mda_free", "J");
  (*env)->SetLongField (env, jr, fl, r->pv_mda_free);
  free (r);
  return jr;
}

JNIEXPORT jobjectArray JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1internal_1test_1rstructlist  (JNIEnv *env, jobject obj, jlong jg, jstring jval)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  jobjectArray jr;
  jclass cl;
  jfieldID fl;
  jobject jfl;
  struct guestfs_lvm_pv_list *r;
  const char *val;
  size_t i;

  val = (*env)->GetStringUTFChars (env, jval, NULL);

  r = guestfs_internal_test_rstructlist (g, val);

  (*env)->ReleaseStringUTFChars (env, jval, val);

  if (r == NULL) {
    throw_exception (env, guestfs_last_error (g));
    return NULL;
  }
  cl = (*env)->FindClass (env, "com/redhat/et/libguestfs/PV");
  jr = (*env)->NewObjectArray (env, r->len, cl, NULL);

  for (i = 0; i < r->len; ++i) {
    jfl = (*env)->AllocObject (env, cl);

    fl = (*env)->GetFieldID (env, cl, "pv_name",
                             "Ljava/lang/String;");
    (*env)->SetObjectField (env, jfl, fl,
                            (*env)->NewStringUTF (env, r->val[i].pv_name));
    fl = (*env)->GetFieldID (env, cl, "pv_uuid",
                             "Ljava/lang/String;");
    {
      char s[33];
      memcpy (s, r->val[i].pv_uuid, 32);
      s[32] = 0;
      (*env)->SetObjectField (env, jfl, fl,
                              (*env)->NewStringUTF (env, s));
    }
    fl = (*env)->GetFieldID (env, cl, "pv_fmt",
                             "Ljava/lang/String;");
    (*env)->SetObjectField (env, jfl, fl,
                            (*env)->NewStringUTF (env, r->val[i].pv_fmt));
    fl = (*env)->GetFieldID (env, cl, "pv_size",
                             "J");
    (*env)->SetLongField (env, jfl, fl, r->val[i].pv_size);
    fl = (*env)->GetFieldID (env, cl, "dev_size",
                             "J");
    (*env)->SetLongField (env, jfl, fl, r->val[i].dev_size);
    fl = (*env)->GetFieldID (env, cl, "pv_free",
                             "J");
    (*env)->SetLongField (env, jfl, fl, r->val[i].pv_free);
    fl = (*env)->GetFieldID (env, cl, "pv_used",
                             "J");
    (*env)->SetLongField (env, jfl, fl, r->val[i].pv_used);
    fl = (*env)->GetFieldID (env, cl, "pv_attr",
                             "Ljava/lang/String;");
    (*env)->SetObjectField (env, jfl, fl,
                            (*env)->NewStringUTF (env, r->val[i].pv_attr));
    fl = (*env)->GetFieldID (env, cl, "pv_pe_count",
                             "J");
    (*env)->SetLongField (env, jfl, fl, r->val[i].pv_pe_count);
    fl = (*env)->GetFieldID (env, cl, "pv_pe_alloc_count",
                             "J");
    (*env)->SetLongField (env, jfl, fl, r->val[i].pv_pe_alloc_count);
    fl = (*env)->GetFieldID (env, cl, "pv_tags",
                             "Ljava/lang/String;");
    (*env)->SetObjectField (env, jfl, fl,
                            (*env)->NewStringUTF (env, r->val[i].pv_tags));
    fl = (*env)->GetFieldID (env, cl, "pe_start",
                             "J");
    (*env)->SetLongField (env, jfl, fl, r->val[i].pe_start);
    fl = (*env)->GetFieldID (env, cl, "pv_mda_count",
                             "J");
    (*env)->SetLongField (env, jfl, fl, r->val[i].pv_mda_count);
    fl = (*env)->GetFieldID (env, cl, "pv_mda_free",
                             "J");
    (*env)->SetLongField (env, jfl, fl, r->val[i].pv_mda_free);

    (*env)->SetObjectArrayElement (env, jr, i, jfl);
  }

  guestfs_free_lvm_pv_list (r);
  return jr;
}

JNIEXPORT jobjectArray JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1internal_1test_1rstructlisterr  (JNIEnv *env, jobject obj, jlong jg)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  jobjectArray jr;
  jclass cl;
  jfieldID fl;
  jobject jfl;
  struct guestfs_lvm_pv_list *r;
  size_t i;


  r = guestfs_internal_test_rstructlisterr (g);


  if (r == NULL) {
    throw_exception (env, guestfs_last_error (g));
    return NULL;
  }
  cl = (*env)->FindClass (env, "com/redhat/et/libguestfs/PV");
  jr = (*env)->NewObjectArray (env, r->len, cl, NULL);

  for (i = 0; i < r->len; ++i) {
    jfl = (*env)->AllocObject (env, cl);

    fl = (*env)->GetFieldID (env, cl, "pv_name",
                             "Ljava/lang/String;");
    (*env)->SetObjectField (env, jfl, fl,
                            (*env)->NewStringUTF (env, r->val[i].pv_name));
    fl = (*env)->GetFieldID (env, cl, "pv_uuid",
                             "Ljava/lang/String;");
    {
      char s[33];
      memcpy (s, r->val[i].pv_uuid, 32);
      s[32] = 0;
      (*env)->SetObjectField (env, jfl, fl,
                              (*env)->NewStringUTF (env, s));
    }
    fl = (*env)->GetFieldID (env, cl, "pv_fmt",
                             "Ljava/lang/String;");
    (*env)->SetObjectField (env, jfl, fl,
                            (*env)->NewStringUTF (env, r->val[i].pv_fmt));
    fl = (*env)->GetFieldID (env, cl, "pv_size",
                             "J");
    (*env)->SetLongField (env, jfl, fl, r->val[i].pv_size);
    fl = (*env)->GetFieldID (env, cl, "dev_size",
                             "J");
    (*env)->SetLongField (env, jfl, fl, r->val[i].dev_size);
    fl = (*env)->GetFieldID (env, cl, "pv_free",
                             "J");
    (*env)->SetLongField (env, jfl, fl, r->val[i].pv_free);
    fl = (*env)->GetFieldID (env, cl, "pv_used",
                             "J");
    (*env)->SetLongField (env, jfl, fl, r->val[i].pv_used);
    fl = (*env)->GetFieldID (env, cl, "pv_attr",
                             "Ljava/lang/String;");
    (*env)->SetObjectField (env, jfl, fl,
                            (*env)->NewStringUTF (env, r->val[i].pv_attr));
    fl = (*env)->GetFieldID (env, cl, "pv_pe_count",
                             "J");
    (*env)->SetLongField (env, jfl, fl, r->val[i].pv_pe_count);
    fl = (*env)->GetFieldID (env, cl, "pv_pe_alloc_count",
                             "J");
    (*env)->SetLongField (env, jfl, fl, r->val[i].pv_pe_alloc_count);
    fl = (*env)->GetFieldID (env, cl, "pv_tags",
                             "Ljava/lang/String;");
    (*env)->SetObjectField (env, jfl, fl,
                            (*env)->NewStringUTF (env, r->val[i].pv_tags));
    fl = (*env)->GetFieldID (env, cl, "pe_start",
                             "J");
    (*env)->SetLongField (env, jfl, fl, r->val[i].pe_start);
    fl = (*env)->GetFieldID (env, cl, "pv_mda_count",
                             "J");
    (*env)->SetLongField (env, jfl, fl, r->val[i].pv_mda_count);
    fl = (*env)->GetFieldID (env, cl, "pv_mda_free",
                             "J");
    (*env)->SetLongField (env, jfl, fl, r->val[i].pv_mda_free);

    (*env)->SetObjectArrayElement (env, jr, i, jfl);
  }

  guestfs_free_lvm_pv_list (r);
  return jr;
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1internal_1test_1set_1output  (JNIEnv *env, jobject obj, jlong jg, jstring jfilename)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *filename;

  filename = (*env)->GetStringUTFChars (env, jfilename, NULL);

  r = guestfs_internal_test_set_output (g, filename);

  (*env)->ReleaseStringUTFChars (env, jfilename, filename);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT jboolean JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1is_1blockdev  (JNIEnv *env, jobject obj, jlong jg, jstring jpath, jlong joptargs_bitmask, jboolean jfollowsymlinks)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *path;
  struct guestfs_is_blockdev_opts_argv optargs_s;
  const struct guestfs_is_blockdev_opts_argv *optargs = &optargs_s;

  path = (*env)->GetStringUTFChars (env, jpath, NULL);

  optargs_s.followsymlinks = jfollowsymlinks;
  optargs_s.bitmask = joptargs_bitmask;

  r = guestfs_is_blockdev_opts_argv (g, path, optargs);

  (*env)->ReleaseStringUTFChars (env, jpath, path);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return -1;
  }
  return (jboolean) r;
}

JNIEXPORT jboolean JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1is_1busy  (JNIEnv *env, jobject obj, jlong jg)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;


  r = guestfs_is_busy (g);


  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return -1;
  }
  return (jboolean) r;
}

JNIEXPORT jboolean JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1is_1chardev  (JNIEnv *env, jobject obj, jlong jg, jstring jpath, jlong joptargs_bitmask, jboolean jfollowsymlinks)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *path;
  struct guestfs_is_chardev_opts_argv optargs_s;
  const struct guestfs_is_chardev_opts_argv *optargs = &optargs_s;

  path = (*env)->GetStringUTFChars (env, jpath, NULL);

  optargs_s.followsymlinks = jfollowsymlinks;
  optargs_s.bitmask = joptargs_bitmask;

  r = guestfs_is_chardev_opts_argv (g, path, optargs);

  (*env)->ReleaseStringUTFChars (env, jpath, path);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return -1;
  }
  return (jboolean) r;
}

JNIEXPORT jboolean JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1is_1config  (JNIEnv *env, jobject obj, jlong jg)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;


  r = guestfs_is_config (g);


  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return -1;
  }
  return (jboolean) r;
}

JNIEXPORT jboolean JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1is_1dir  (JNIEnv *env, jobject obj, jlong jg, jstring jpath, jlong joptargs_bitmask, jboolean jfollowsymlinks)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *path;
  struct guestfs_is_dir_opts_argv optargs_s;
  const struct guestfs_is_dir_opts_argv *optargs = &optargs_s;

  path = (*env)->GetStringUTFChars (env, jpath, NULL);

  optargs_s.followsymlinks = jfollowsymlinks;
  optargs_s.bitmask = joptargs_bitmask;

  r = guestfs_is_dir_opts_argv (g, path, optargs);

  (*env)->ReleaseStringUTFChars (env, jpath, path);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return -1;
  }
  return (jboolean) r;
}

JNIEXPORT jboolean JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1is_1fifo  (JNIEnv *env, jobject obj, jlong jg, jstring jpath, jlong joptargs_bitmask, jboolean jfollowsymlinks)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *path;
  struct guestfs_is_fifo_opts_argv optargs_s;
  const struct guestfs_is_fifo_opts_argv *optargs = &optargs_s;

  path = (*env)->GetStringUTFChars (env, jpath, NULL);

  optargs_s.followsymlinks = jfollowsymlinks;
  optargs_s.bitmask = joptargs_bitmask;

  r = guestfs_is_fifo_opts_argv (g, path, optargs);

  (*env)->ReleaseStringUTFChars (env, jpath, path);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return -1;
  }
  return (jboolean) r;
}

JNIEXPORT jboolean JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1is_1file  (JNIEnv *env, jobject obj, jlong jg, jstring jpath, jlong joptargs_bitmask, jboolean jfollowsymlinks)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *path;
  struct guestfs_is_file_opts_argv optargs_s;
  const struct guestfs_is_file_opts_argv *optargs = &optargs_s;

  path = (*env)->GetStringUTFChars (env, jpath, NULL);

  optargs_s.followsymlinks = jfollowsymlinks;
  optargs_s.bitmask = joptargs_bitmask;

  r = guestfs_is_file_opts_argv (g, path, optargs);

  (*env)->ReleaseStringUTFChars (env, jpath, path);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return -1;
  }
  return (jboolean) r;
}

JNIEXPORT jboolean JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1is_1launching  (JNIEnv *env, jobject obj, jlong jg)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;


  r = guestfs_is_launching (g);


  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return -1;
  }
  return (jboolean) r;
}

JNIEXPORT jboolean JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1is_1lv  (JNIEnv *env, jobject obj, jlong jg, jstring jdevice)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *device;

  device = (*env)->GetStringUTFChars (env, jdevice, NULL);

  r = guestfs_is_lv (g, device);

  (*env)->ReleaseStringUTFChars (env, jdevice, device);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return -1;
  }
  return (jboolean) r;
}

JNIEXPORT jboolean JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1is_1ready  (JNIEnv *env, jobject obj, jlong jg)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;


  r = guestfs_is_ready (g);


  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return -1;
  }
  return (jboolean) r;
}

JNIEXPORT jboolean JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1is_1socket  (JNIEnv *env, jobject obj, jlong jg, jstring jpath, jlong joptargs_bitmask, jboolean jfollowsymlinks)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *path;
  struct guestfs_is_socket_opts_argv optargs_s;
  const struct guestfs_is_socket_opts_argv *optargs = &optargs_s;

  path = (*env)->GetStringUTFChars (env, jpath, NULL);

  optargs_s.followsymlinks = jfollowsymlinks;
  optargs_s.bitmask = joptargs_bitmask;

  r = guestfs_is_socket_opts_argv (g, path, optargs);

  (*env)->ReleaseStringUTFChars (env, jpath, path);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return -1;
  }
  return (jboolean) r;
}

JNIEXPORT jboolean JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1is_1symlink  (JNIEnv *env, jobject obj, jlong jg, jstring jpath)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *path;

  path = (*env)->GetStringUTFChars (env, jpath, NULL);

  r = guestfs_is_symlink (g, path);

  (*env)->ReleaseStringUTFChars (env, jpath, path);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return -1;
  }
  return (jboolean) r;
}

JNIEXPORT jboolean JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1is_1whole_1device  (JNIEnv *env, jobject obj, jlong jg, jstring jdevice)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *device;

  device = (*env)->GetStringUTFChars (env, jdevice, NULL);

  r = guestfs_is_whole_device (g, device);

  (*env)->ReleaseStringUTFChars (env, jdevice, device);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return -1;
  }
  return (jboolean) r;
}

JNIEXPORT jboolean JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1is_1zero  (JNIEnv *env, jobject obj, jlong jg, jstring jpath)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *path;

  path = (*env)->GetStringUTFChars (env, jpath, NULL);

  r = guestfs_is_zero (g, path);

  (*env)->ReleaseStringUTFChars (env, jpath, path);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return -1;
  }
  return (jboolean) r;
}

JNIEXPORT jboolean JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1is_1zero_1device  (JNIEnv *env, jobject obj, jlong jg, jstring jdevice)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *device;

  device = (*env)->GetStringUTFChars (env, jdevice, NULL);

  r = guestfs_is_zero_device (g, device);

  (*env)->ReleaseStringUTFChars (env, jdevice, device);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return -1;
  }
  return (jboolean) r;
}

JNIEXPORT jobject JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1isoinfo  (JNIEnv *env, jobject obj, jlong jg, jstring jisofile)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  jobject jr;
  jclass cl;
  jfieldID fl;
  struct guestfs_isoinfo *r;
  const char *isofile;

  isofile = (*env)->GetStringUTFChars (env, jisofile, NULL);

  r = guestfs_isoinfo (g, isofile);

  (*env)->ReleaseStringUTFChars (env, jisofile, isofile);

  if (r == NULL) {
    throw_exception (env, guestfs_last_error (g));
    return NULL;
  }
  cl = (*env)->FindClass (env, "com/redhat/et/libguestfs/ISOInfo");
  jr = (*env)->AllocObject (env, cl);
  fl = (*env)->GetFieldID (env, cl, "iso_system_id", "Ljava/lang/String;");
  (*env)->SetObjectField (env, jr, fl, (*env)->NewStringUTF (env, r->iso_system_id));
  fl = (*env)->GetFieldID (env, cl, "iso_volume_id", "Ljava/lang/String;");
  (*env)->SetObjectField (env, jr, fl, (*env)->NewStringUTF (env, r->iso_volume_id));
  fl = (*env)->GetFieldID (env, cl, "iso_volume_space_size", "I");
  (*env)->SetIntField (env, jr, fl, r->iso_volume_space_size);
  fl = (*env)->GetFieldID (env, cl, "iso_volume_set_size", "I");
  (*env)->SetIntField (env, jr, fl, r->iso_volume_set_size);
  fl = (*env)->GetFieldID (env, cl, "iso_volume_sequence_number", "I");
  (*env)->SetIntField (env, jr, fl, r->iso_volume_sequence_number);
  fl = (*env)->GetFieldID (env, cl, "iso_logical_block_size", "I");
  (*env)->SetIntField (env, jr, fl, r->iso_logical_block_size);
  fl = (*env)->GetFieldID (env, cl, "iso_volume_set_id", "Ljava/lang/String;");
  (*env)->SetObjectField (env, jr, fl, (*env)->NewStringUTF (env, r->iso_volume_set_id));
  fl = (*env)->GetFieldID (env, cl, "iso_publisher_id", "Ljava/lang/String;");
  (*env)->SetObjectField (env, jr, fl, (*env)->NewStringUTF (env, r->iso_publisher_id));
  fl = (*env)->GetFieldID (env, cl, "iso_data_preparer_id", "Ljava/lang/String;");
  (*env)->SetObjectField (env, jr, fl, (*env)->NewStringUTF (env, r->iso_data_preparer_id));
  fl = (*env)->GetFieldID (env, cl, "iso_application_id", "Ljava/lang/String;");
  (*env)->SetObjectField (env, jr, fl, (*env)->NewStringUTF (env, r->iso_application_id));
  fl = (*env)->GetFieldID (env, cl, "iso_copyright_file_id", "Ljava/lang/String;");
  (*env)->SetObjectField (env, jr, fl, (*env)->NewStringUTF (env, r->iso_copyright_file_id));
  fl = (*env)->GetFieldID (env, cl, "iso_abstract_file_id", "Ljava/lang/String;");
  (*env)->SetObjectField (env, jr, fl, (*env)->NewStringUTF (env, r->iso_abstract_file_id));
  fl = (*env)->GetFieldID (env, cl, "iso_bibliographic_file_id", "Ljava/lang/String;");
  (*env)->SetObjectField (env, jr, fl, (*env)->NewStringUTF (env, r->iso_bibliographic_file_id));
  fl = (*env)->GetFieldID (env, cl, "iso_volume_creation_t", "J");
  (*env)->SetLongField (env, jr, fl, r->iso_volume_creation_t);
  fl = (*env)->GetFieldID (env, cl, "iso_volume_modification_t", "J");
  (*env)->SetLongField (env, jr, fl, r->iso_volume_modification_t);
  fl = (*env)->GetFieldID (env, cl, "iso_volume_expiration_t", "J");
  (*env)->SetLongField (env, jr, fl, r->iso_volume_expiration_t);
  fl = (*env)->GetFieldID (env, cl, "iso_volume_effective_t", "J");
  (*env)->SetLongField (env, jr, fl, r->iso_volume_effective_t);
  free (r);
  return jr;
}

JNIEXPORT jobject JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1isoinfo_1device  (JNIEnv *env, jobject obj, jlong jg, jstring jdevice)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  jobject jr;
  jclass cl;
  jfieldID fl;
  struct guestfs_isoinfo *r;
  const char *device;

  device = (*env)->GetStringUTFChars (env, jdevice, NULL);

  r = guestfs_isoinfo_device (g, device);

  (*env)->ReleaseStringUTFChars (env, jdevice, device);

  if (r == NULL) {
    throw_exception (env, guestfs_last_error (g));
    return NULL;
  }
  cl = (*env)->FindClass (env, "com/redhat/et/libguestfs/ISOInfo");
  jr = (*env)->AllocObject (env, cl);
  fl = (*env)->GetFieldID (env, cl, "iso_system_id", "Ljava/lang/String;");
  (*env)->SetObjectField (env, jr, fl, (*env)->NewStringUTF (env, r->iso_system_id));
  fl = (*env)->GetFieldID (env, cl, "iso_volume_id", "Ljava/lang/String;");
  (*env)->SetObjectField (env, jr, fl, (*env)->NewStringUTF (env, r->iso_volume_id));
  fl = (*env)->GetFieldID (env, cl, "iso_volume_space_size", "I");
  (*env)->SetIntField (env, jr, fl, r->iso_volume_space_size);
  fl = (*env)->GetFieldID (env, cl, "iso_volume_set_size", "I");
  (*env)->SetIntField (env, jr, fl, r->iso_volume_set_size);
  fl = (*env)->GetFieldID (env, cl, "iso_volume_sequence_number", "I");
  (*env)->SetIntField (env, jr, fl, r->iso_volume_sequence_number);
  fl = (*env)->GetFieldID (env, cl, "iso_logical_block_size", "I");
  (*env)->SetIntField (env, jr, fl, r->iso_logical_block_size);
  fl = (*env)->GetFieldID (env, cl, "iso_volume_set_id", "Ljava/lang/String;");
  (*env)->SetObjectField (env, jr, fl, (*env)->NewStringUTF (env, r->iso_volume_set_id));
  fl = (*env)->GetFieldID (env, cl, "iso_publisher_id", "Ljava/lang/String;");
  (*env)->SetObjectField (env, jr, fl, (*env)->NewStringUTF (env, r->iso_publisher_id));
  fl = (*env)->GetFieldID (env, cl, "iso_data_preparer_id", "Ljava/lang/String;");
  (*env)->SetObjectField (env, jr, fl, (*env)->NewStringUTF (env, r->iso_data_preparer_id));
  fl = (*env)->GetFieldID (env, cl, "iso_application_id", "Ljava/lang/String;");
  (*env)->SetObjectField (env, jr, fl, (*env)->NewStringUTF (env, r->iso_application_id));
  fl = (*env)->GetFieldID (env, cl, "iso_copyright_file_id", "Ljava/lang/String;");
  (*env)->SetObjectField (env, jr, fl, (*env)->NewStringUTF (env, r->iso_copyright_file_id));
  fl = (*env)->GetFieldID (env, cl, "iso_abstract_file_id", "Ljava/lang/String;");
  (*env)->SetObjectField (env, jr, fl, (*env)->NewStringUTF (env, r->iso_abstract_file_id));
  fl = (*env)->GetFieldID (env, cl, "iso_bibliographic_file_id", "Ljava/lang/String;");
  (*env)->SetObjectField (env, jr, fl, (*env)->NewStringUTF (env, r->iso_bibliographic_file_id));
  fl = (*env)->GetFieldID (env, cl, "iso_volume_creation_t", "J");
  (*env)->SetLongField (env, jr, fl, r->iso_volume_creation_t);
  fl = (*env)->GetFieldID (env, cl, "iso_volume_modification_t", "J");
  (*env)->SetLongField (env, jr, fl, r->iso_volume_modification_t);
  fl = (*env)->GetFieldID (env, cl, "iso_volume_expiration_t", "J");
  (*env)->SetLongField (env, jr, fl, r->iso_volume_expiration_t);
  fl = (*env)->GetFieldID (env, cl, "iso_volume_effective_t", "J");
  (*env)->SetLongField (env, jr, fl, r->iso_volume_effective_t);
  free (r);
  return jr;
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1journal_1close  (JNIEnv *env, jobject obj, jlong jg)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;


  r = guestfs_journal_close (g);


  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT jobjectArray JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1journal_1get  (JNIEnv *env, jobject obj, jlong jg)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  jobjectArray jr;
  jclass cl;
  jfieldID fl;
  jobject jfl;
  struct guestfs_xattr_list *r;
  size_t i;


  r = guestfs_journal_get (g);


  if (r == NULL) {
    throw_exception (env, guestfs_last_error (g));
    return NULL;
  }
  cl = (*env)->FindClass (env, "com/redhat/et/libguestfs/XAttr");
  jr = (*env)->NewObjectArray (env, r->len, cl, NULL);

  for (i = 0; i < r->len; ++i) {
    jfl = (*env)->AllocObject (env, cl);

    fl = (*env)->GetFieldID (env, cl, "attrname",
                             "Ljava/lang/String;");
    (*env)->SetObjectField (env, jfl, fl,
                            (*env)->NewStringUTF (env, r->val[i].attrname));
    fl = (*env)->GetFieldID (env, cl, "attrval",
                             "Ljava/lang/String;");
    {
      size_t len = r->val[i].attrval_len;
      char s[len+1];
      memcpy (s, r->val[i].attrval, len);
      s[len] = 0;
      (*env)->SetObjectField (env, jfl, fl,
                              (*env)->NewStringUTF (env, s));
    }

    (*env)->SetObjectArrayElement (env, jr, i, jfl);
  }

  guestfs_free_xattr_list (r);
  return jr;
}

JNIEXPORT jlong JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1journal_1get_1data_1threshold  (JNIEnv *env, jobject obj, jlong jg)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int64_t r;


  r = guestfs_journal_get_data_threshold (g);


  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return -1;
  }
  return (jlong) r;
}

JNIEXPORT jlong JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1journal_1get_1realtime_1usec  (JNIEnv *env, jobject obj, jlong jg)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int64_t r;


  r = guestfs_journal_get_realtime_usec (g);


  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return -1;
  }
  return (jlong) r;
}

JNIEXPORT jboolean JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1journal_1next  (JNIEnv *env, jobject obj, jlong jg)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;


  r = guestfs_journal_next (g);


  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return -1;
  }
  return (jboolean) r;
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1journal_1open  (JNIEnv *env, jobject obj, jlong jg, jstring jdirectory)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *directory;

  directory = (*env)->GetStringUTFChars (env, jdirectory, NULL);

  r = guestfs_journal_open (g, directory);

  (*env)->ReleaseStringUTFChars (env, jdirectory, directory);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1journal_1set_1data_1threshold  (JNIEnv *env, jobject obj, jlong jg, jlong jthreshold)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  int64_t threshold;

  threshold = jthreshold;

  r = guestfs_journal_set_data_threshold (g, threshold);


  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT jlong JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1journal_1skip  (JNIEnv *env, jobject obj, jlong jg, jlong jskip)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int64_t r;
  int64_t skip;

  skip = jskip;

  r = guestfs_journal_skip (g, skip);


  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return -1;
  }
  return (jlong) r;
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1kill_1subprocess  (JNIEnv *env, jobject obj, jlong jg)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;


  r = guestfs_kill_subprocess (g);


  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1launch  (JNIEnv *env, jobject obj, jlong jg)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;


  r = guestfs_launch (g);


  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1lchown  (JNIEnv *env, jobject obj, jlong jg, jint jowner, jint jgroup, jstring jpath)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  int owner;
  int group;
  const char *path;

  owner = jowner;
  group = jgroup;
  path = (*env)->GetStringUTFChars (env, jpath, NULL);

  r = guestfs_lchown (g, owner, group, path);

  (*env)->ReleaseStringUTFChars (env, jpath, path);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1ldmtool_1create_1all  (JNIEnv *env, jobject obj, jlong jg)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;


  r = guestfs_ldmtool_create_all (g);


  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT jobjectArray JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1ldmtool_1diskgroup_1disks  (JNIEnv *env, jobject obj, jlong jg, jstring jdiskgroup)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  jobjectArray jr;
  size_t r_len;
  jclass cl;
  jstring jstr;
  char **r;
  const char *diskgroup;
  size_t i;

  diskgroup = (*env)->GetStringUTFChars (env, jdiskgroup, NULL);

  r = guestfs_ldmtool_diskgroup_disks (g, diskgroup);

  (*env)->ReleaseStringUTFChars (env, jdiskgroup, diskgroup);

  if (r == NULL) {
    throw_exception (env, guestfs_last_error (g));
    return NULL;
  }
  for (r_len = 0; r[r_len] != NULL; ++r_len) ;
  cl = (*env)->FindClass (env, "java/lang/String");
  jstr = (*env)->NewStringUTF (env, "");
  jr = (*env)->NewObjectArray (env, r_len, cl, jstr);
  for (i = 0; i < r_len; ++i) {
    jstr = (*env)->NewStringUTF (env, r[i]);
    (*env)->SetObjectArrayElement (env, jr, i, jstr);
    free (r[i]);
  }
  free (r);
  return jr;
}

JNIEXPORT jstring JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1ldmtool_1diskgroup_1name  (JNIEnv *env, jobject obj, jlong jg, jstring jdiskgroup)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  jstring jr;
  char *r;
  const char *diskgroup;

  diskgroup = (*env)->GetStringUTFChars (env, jdiskgroup, NULL);

  r = guestfs_ldmtool_diskgroup_name (g, diskgroup);

  (*env)->ReleaseStringUTFChars (env, jdiskgroup, diskgroup);

  if (r == NULL) {
    throw_exception (env, guestfs_last_error (g));
    return NULL;
  }
  jr = (*env)->NewStringUTF (env, r);
  free (r);
  return jr;
}

JNIEXPORT jobjectArray JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1ldmtool_1diskgroup_1volumes  (JNIEnv *env, jobject obj, jlong jg, jstring jdiskgroup)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  jobjectArray jr;
  size_t r_len;
  jclass cl;
  jstring jstr;
  char **r;
  const char *diskgroup;
  size_t i;

  diskgroup = (*env)->GetStringUTFChars (env, jdiskgroup, NULL);

  r = guestfs_ldmtool_diskgroup_volumes (g, diskgroup);

  (*env)->ReleaseStringUTFChars (env, jdiskgroup, diskgroup);

  if (r == NULL) {
    throw_exception (env, guestfs_last_error (g));
    return NULL;
  }
  for (r_len = 0; r[r_len] != NULL; ++r_len) ;
  cl = (*env)->FindClass (env, "java/lang/String");
  jstr = (*env)->NewStringUTF (env, "");
  jr = (*env)->NewObjectArray (env, r_len, cl, jstr);
  for (i = 0; i < r_len; ++i) {
    jstr = (*env)->NewStringUTF (env, r[i]);
    (*env)->SetObjectArrayElement (env, jr, i, jstr);
    free (r[i]);
  }
  free (r);
  return jr;
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1ldmtool_1remove_1all  (JNIEnv *env, jobject obj, jlong jg)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;


  r = guestfs_ldmtool_remove_all (g);


  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT jobjectArray JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1ldmtool_1scan  (JNIEnv *env, jobject obj, jlong jg)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  jobjectArray jr;
  size_t r_len;
  jclass cl;
  jstring jstr;
  char **r;
  size_t i;


  r = guestfs_ldmtool_scan (g);


  if (r == NULL) {
    throw_exception (env, guestfs_last_error (g));
    return NULL;
  }
  for (r_len = 0; r[r_len] != NULL; ++r_len) ;
  cl = (*env)->FindClass (env, "java/lang/String");
  jstr = (*env)->NewStringUTF (env, "");
  jr = (*env)->NewObjectArray (env, r_len, cl, jstr);
  for (i = 0; i < r_len; ++i) {
    jstr = (*env)->NewStringUTF (env, r[i]);
    (*env)->SetObjectArrayElement (env, jr, i, jstr);
    free (r[i]);
  }
  free (r);
  return jr;
}

JNIEXPORT jobjectArray JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1ldmtool_1scan_1devices  (JNIEnv *env, jobject obj, jlong jg, jobjectArray jdevices)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  jobjectArray jr;
  size_t r_len;
  jclass cl;
  jstring jstr;
  char **r;
  size_t devices_len;
  char **devices;
  size_t i;

  devices_len = (*env)->GetArrayLength (env, jdevices);
  devices = guestfs___safe_malloc (g, sizeof (char *) * (devices_len+1));
  for (i = 0; i < devices_len; ++i) {
    jobject o = (*env)->GetObjectArrayElement (env, jdevices, i);
    devices[i] = (char *) (*env)->GetStringUTFChars (env, o, NULL);
  }
  devices[devices_len] = NULL;

  r = guestfs_ldmtool_scan_devices (g, devices);

  for (i = 0; i < devices_len; ++i) {
    jobject o = (*env)->GetObjectArrayElement (env, jdevices, i);
    (*env)->ReleaseStringUTFChars (env, o, devices[i]);
  }
  free (devices);

  if (r == NULL) {
    throw_exception (env, guestfs_last_error (g));
    return NULL;
  }
  for (r_len = 0; r[r_len] != NULL; ++r_len) ;
  cl = (*env)->FindClass (env, "java/lang/String");
  jstr = (*env)->NewStringUTF (env, "");
  jr = (*env)->NewObjectArray (env, r_len, cl, jstr);
  for (i = 0; i < r_len; ++i) {
    jstr = (*env)->NewStringUTF (env, r[i]);
    (*env)->SetObjectArrayElement (env, jr, i, jstr);
    free (r[i]);
  }
  free (r);
  return jr;
}

JNIEXPORT jstring JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1ldmtool_1volume_1hint  (JNIEnv *env, jobject obj, jlong jg, jstring jdiskgroup, jstring jvolume)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  jstring jr;
  char *r;
  const char *diskgroup;
  const char *volume;

  diskgroup = (*env)->GetStringUTFChars (env, jdiskgroup, NULL);
  volume = (*env)->GetStringUTFChars (env, jvolume, NULL);

  r = guestfs_ldmtool_volume_hint (g, diskgroup, volume);

  (*env)->ReleaseStringUTFChars (env, jdiskgroup, diskgroup);
  (*env)->ReleaseStringUTFChars (env, jvolume, volume);

  if (r == NULL) {
    throw_exception (env, guestfs_last_error (g));
    return NULL;
  }
  jr = (*env)->NewStringUTF (env, r);
  free (r);
  return jr;
}

JNIEXPORT jobjectArray JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1ldmtool_1volume_1partitions  (JNIEnv *env, jobject obj, jlong jg, jstring jdiskgroup, jstring jvolume)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  jobjectArray jr;
  size_t r_len;
  jclass cl;
  jstring jstr;
  char **r;
  const char *diskgroup;
  const char *volume;
  size_t i;

  diskgroup = (*env)->GetStringUTFChars (env, jdiskgroup, NULL);
  volume = (*env)->GetStringUTFChars (env, jvolume, NULL);

  r = guestfs_ldmtool_volume_partitions (g, diskgroup, volume);

  (*env)->ReleaseStringUTFChars (env, jdiskgroup, diskgroup);
  (*env)->ReleaseStringUTFChars (env, jvolume, volume);

  if (r == NULL) {
    throw_exception (env, guestfs_last_error (g));
    return NULL;
  }
  for (r_len = 0; r[r_len] != NULL; ++r_len) ;
  cl = (*env)->FindClass (env, "java/lang/String");
  jstr = (*env)->NewStringUTF (env, "");
  jr = (*env)->NewObjectArray (env, r_len, cl, jstr);
  for (i = 0; i < r_len; ++i) {
    jstr = (*env)->NewStringUTF (env, r[i]);
    (*env)->SetObjectArrayElement (env, jr, i, jstr);
    free (r[i]);
  }
  free (r);
  return jr;
}

JNIEXPORT jstring JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1ldmtool_1volume_1type  (JNIEnv *env, jobject obj, jlong jg, jstring jdiskgroup, jstring jvolume)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  jstring jr;
  char *r;
  const char *diskgroup;
  const char *volume;

  diskgroup = (*env)->GetStringUTFChars (env, jdiskgroup, NULL);
  volume = (*env)->GetStringUTFChars (env, jvolume, NULL);

  r = guestfs_ldmtool_volume_type (g, diskgroup, volume);

  (*env)->ReleaseStringUTFChars (env, jdiskgroup, diskgroup);
  (*env)->ReleaseStringUTFChars (env, jvolume, volume);

  if (r == NULL) {
    throw_exception (env, guestfs_last_error (g));
    return NULL;
  }
  jr = (*env)->NewStringUTF (env, r);
  free (r);
  return jr;
}

JNIEXPORT jstring JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1lgetxattr  (JNIEnv *env, jobject obj, jlong jg, jstring jpath, jstring jname)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  jstring jr;
  char *r;
  size_t size;
  const char *path;
  const char *name;

  path = (*env)->GetStringUTFChars (env, jpath, NULL);
  name = (*env)->GetStringUTFChars (env, jname, NULL);

  r = guestfs_lgetxattr (g, path, name, &size);

  (*env)->ReleaseStringUTFChars (env, jpath, path);
  (*env)->ReleaseStringUTFChars (env, jname, name);

  if (r == NULL) {
    throw_exception (env, guestfs_last_error (g));
    return NULL;
  }
  jr = (*env)->NewStringUTF (env, r); // XXX size
  free (r);
  return jr;
}

JNIEXPORT jobjectArray JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1lgetxattrs  (JNIEnv *env, jobject obj, jlong jg, jstring jpath)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  jobjectArray jr;
  jclass cl;
  jfieldID fl;
  jobject jfl;
  struct guestfs_xattr_list *r;
  const char *path;
  size_t i;

  path = (*env)->GetStringUTFChars (env, jpath, NULL);

  r = guestfs_lgetxattrs (g, path);

  (*env)->ReleaseStringUTFChars (env, jpath, path);

  if (r == NULL) {
    throw_exception (env, guestfs_last_error (g));
    return NULL;
  }
  cl = (*env)->FindClass (env, "com/redhat/et/libguestfs/XAttr");
  jr = (*env)->NewObjectArray (env, r->len, cl, NULL);

  for (i = 0; i < r->len; ++i) {
    jfl = (*env)->AllocObject (env, cl);

    fl = (*env)->GetFieldID (env, cl, "attrname",
                             "Ljava/lang/String;");
    (*env)->SetObjectField (env, jfl, fl,
                            (*env)->NewStringUTF (env, r->val[i].attrname));
    fl = (*env)->GetFieldID (env, cl, "attrval",
                             "Ljava/lang/String;");
    {
      size_t len = r->val[i].attrval_len;
      char s[len+1];
      memcpy (s, r->val[i].attrval, len);
      s[len] = 0;
      (*env)->SetObjectField (env, jfl, fl,
                              (*env)->NewStringUTF (env, s));
    }

    (*env)->SetObjectArrayElement (env, jr, i, jfl);
  }

  guestfs_free_xattr_list (r);
  return jr;
}

JNIEXPORT jobjectArray JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1list_19p  (JNIEnv *env, jobject obj, jlong jg)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  jobjectArray jr;
  size_t r_len;
  jclass cl;
  jstring jstr;
  char **r;
  size_t i;


  r = guestfs_list_9p (g);


  if (r == NULL) {
    throw_exception (env, guestfs_last_error (g));
    return NULL;
  }
  for (r_len = 0; r[r_len] != NULL; ++r_len) ;
  cl = (*env)->FindClass (env, "java/lang/String");
  jstr = (*env)->NewStringUTF (env, "");
  jr = (*env)->NewObjectArray (env, r_len, cl, jstr);
  for (i = 0; i < r_len; ++i) {
    jstr = (*env)->NewStringUTF (env, r[i]);
    (*env)->SetObjectArrayElement (env, jr, i, jstr);
    free (r[i]);
  }
  free (r);
  return jr;
}

JNIEXPORT jobjectArray JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1list_1devices  (JNIEnv *env, jobject obj, jlong jg)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  jobjectArray jr;
  size_t r_len;
  jclass cl;
  jstring jstr;
  char **r;
  size_t i;


  r = guestfs_list_devices (g);


  if (r == NULL) {
    throw_exception (env, guestfs_last_error (g));
    return NULL;
  }
  for (r_len = 0; r[r_len] != NULL; ++r_len) ;
  cl = (*env)->FindClass (env, "java/lang/String");
  jstr = (*env)->NewStringUTF (env, "");
  jr = (*env)->NewObjectArray (env, r_len, cl, jstr);
  for (i = 0; i < r_len; ++i) {
    jstr = (*env)->NewStringUTF (env, r[i]);
    (*env)->SetObjectArrayElement (env, jr, i, jstr);
    free (r[i]);
  }
  free (r);
  return jr;
}

JNIEXPORT jobject JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1list_1disk_1labels  (JNIEnv *env, jobject obj, jlong jg)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  jobjectArray jr;
  size_t r_len;
  jclass cl;
  jstring jstr;
  char **r;
  size_t i;


  r = guestfs_list_disk_labels (g);


  if (r == NULL) {
    throw_exception (env, guestfs_last_error (g));
    return NULL;
  }
  for (r_len = 0; r[r_len] != NULL; ++r_len) ;
  cl = (*env)->FindClass (env, "java/lang/String");
  jstr = (*env)->NewStringUTF (env, "");
  jr = (*env)->NewObjectArray (env, r_len, cl, jstr);
  for (i = 0; i < r_len; ++i) {
    jstr = (*env)->NewStringUTF (env, r[i]);
    (*env)->SetObjectArrayElement (env, jr, i, jstr);
    free (r[i]);
  }
  free (r);
  return jr;
}

JNIEXPORT jobjectArray JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1list_1dm_1devices  (JNIEnv *env, jobject obj, jlong jg)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  jobjectArray jr;
  size_t r_len;
  jclass cl;
  jstring jstr;
  char **r;
  size_t i;


  r = guestfs_list_dm_devices (g);


  if (r == NULL) {
    throw_exception (env, guestfs_last_error (g));
    return NULL;
  }
  for (r_len = 0; r[r_len] != NULL; ++r_len) ;
  cl = (*env)->FindClass (env, "java/lang/String");
  jstr = (*env)->NewStringUTF (env, "");
  jr = (*env)->NewObjectArray (env, r_len, cl, jstr);
  for (i = 0; i < r_len; ++i) {
    jstr = (*env)->NewStringUTF (env, r[i]);
    (*env)->SetObjectArrayElement (env, jr, i, jstr);
    free (r[i]);
  }
  free (r);
  return jr;
}

JNIEXPORT jobject JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1list_1filesystems  (JNIEnv *env, jobject obj, jlong jg)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  jobjectArray jr;
  size_t r_len;
  jclass cl;
  jstring jstr;
  char **r;
  size_t i;


  r = guestfs_list_filesystems (g);


  if (r == NULL) {
    throw_exception (env, guestfs_last_error (g));
    return NULL;
  }
  for (r_len = 0; r[r_len] != NULL; ++r_len) ;
  cl = (*env)->FindClass (env, "java/lang/String");
  jstr = (*env)->NewStringUTF (env, "");
  jr = (*env)->NewObjectArray (env, r_len, cl, jstr);
  for (i = 0; i < r_len; ++i) {
    jstr = (*env)->NewStringUTF (env, r[i]);
    (*env)->SetObjectArrayElement (env, jr, i, jstr);
    free (r[i]);
  }
  free (r);
  return jr;
}

JNIEXPORT jobjectArray JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1list_1ldm_1partitions  (JNIEnv *env, jobject obj, jlong jg)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  jobjectArray jr;
  size_t r_len;
  jclass cl;
  jstring jstr;
  char **r;
  size_t i;


  r = guestfs_list_ldm_partitions (g);


  if (r == NULL) {
    throw_exception (env, guestfs_last_error (g));
    return NULL;
  }
  for (r_len = 0; r[r_len] != NULL; ++r_len) ;
  cl = (*env)->FindClass (env, "java/lang/String");
  jstr = (*env)->NewStringUTF (env, "");
  jr = (*env)->NewObjectArray (env, r_len, cl, jstr);
  for (i = 0; i < r_len; ++i) {
    jstr = (*env)->NewStringUTF (env, r[i]);
    (*env)->SetObjectArrayElement (env, jr, i, jstr);
    free (r[i]);
  }
  free (r);
  return jr;
}

JNIEXPORT jobjectArray JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1list_1ldm_1volumes  (JNIEnv *env, jobject obj, jlong jg)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  jobjectArray jr;
  size_t r_len;
  jclass cl;
  jstring jstr;
  char **r;
  size_t i;


  r = guestfs_list_ldm_volumes (g);


  if (r == NULL) {
    throw_exception (env, guestfs_last_error (g));
    return NULL;
  }
  for (r_len = 0; r[r_len] != NULL; ++r_len) ;
  cl = (*env)->FindClass (env, "java/lang/String");
  jstr = (*env)->NewStringUTF (env, "");
  jr = (*env)->NewObjectArray (env, r_len, cl, jstr);
  for (i = 0; i < r_len; ++i) {
    jstr = (*env)->NewStringUTF (env, r[i]);
    (*env)->SetObjectArrayElement (env, jr, i, jstr);
    free (r[i]);
  }
  free (r);
  return jr;
}

JNIEXPORT jobjectArray JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1list_1md_1devices  (JNIEnv *env, jobject obj, jlong jg)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  jobjectArray jr;
  size_t r_len;
  jclass cl;
  jstring jstr;
  char **r;
  size_t i;


  r = guestfs_list_md_devices (g);


  if (r == NULL) {
    throw_exception (env, guestfs_last_error (g));
    return NULL;
  }
  for (r_len = 0; r[r_len] != NULL; ++r_len) ;
  cl = (*env)->FindClass (env, "java/lang/String");
  jstr = (*env)->NewStringUTF (env, "");
  jr = (*env)->NewObjectArray (env, r_len, cl, jstr);
  for (i = 0; i < r_len; ++i) {
    jstr = (*env)->NewStringUTF (env, r[i]);
    (*env)->SetObjectArrayElement (env, jr, i, jstr);
    free (r[i]);
  }
  free (r);
  return jr;
}

JNIEXPORT jobjectArray JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1list_1partitions  (JNIEnv *env, jobject obj, jlong jg)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  jobjectArray jr;
  size_t r_len;
  jclass cl;
  jstring jstr;
  char **r;
  size_t i;


  r = guestfs_list_partitions (g);


  if (r == NULL) {
    throw_exception (env, guestfs_last_error (g));
    return NULL;
  }
  for (r_len = 0; r[r_len] != NULL; ++r_len) ;
  cl = (*env)->FindClass (env, "java/lang/String");
  jstr = (*env)->NewStringUTF (env, "");
  jr = (*env)->NewObjectArray (env, r_len, cl, jstr);
  for (i = 0; i < r_len; ++i) {
    jstr = (*env)->NewStringUTF (env, r[i]);
    (*env)->SetObjectArrayElement (env, jr, i, jstr);
    free (r[i]);
  }
  free (r);
  return jr;
}

JNIEXPORT jstring JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1ll  (JNIEnv *env, jobject obj, jlong jg, jstring jdirectory)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  jstring jr;
  char *r;
  const char *directory;

  directory = (*env)->GetStringUTFChars (env, jdirectory, NULL);

  r = guestfs_ll (g, directory);

  (*env)->ReleaseStringUTFChars (env, jdirectory, directory);

  if (r == NULL) {
    throw_exception (env, guestfs_last_error (g));
    return NULL;
  }
  jr = (*env)->NewStringUTF (env, r);
  free (r);
  return jr;
}

JNIEXPORT jstring JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1llz  (JNIEnv *env, jobject obj, jlong jg, jstring jdirectory)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  jstring jr;
  char *r;
  const char *directory;

  directory = (*env)->GetStringUTFChars (env, jdirectory, NULL);

  r = guestfs_llz (g, directory);

  (*env)->ReleaseStringUTFChars (env, jdirectory, directory);

  if (r == NULL) {
    throw_exception (env, guestfs_last_error (g));
    return NULL;
  }
  jr = (*env)->NewStringUTF (env, r);
  free (r);
  return jr;
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1ln  (JNIEnv *env, jobject obj, jlong jg, jstring jtarget, jstring jlinkname)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *target;
  const char *linkname;

  target = (*env)->GetStringUTFChars (env, jtarget, NULL);
  linkname = (*env)->GetStringUTFChars (env, jlinkname, NULL);

  r = guestfs_ln (g, target, linkname);

  (*env)->ReleaseStringUTFChars (env, jtarget, target);
  (*env)->ReleaseStringUTFChars (env, jlinkname, linkname);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1ln_1f  (JNIEnv *env, jobject obj, jlong jg, jstring jtarget, jstring jlinkname)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *target;
  const char *linkname;

  target = (*env)->GetStringUTFChars (env, jtarget, NULL);
  linkname = (*env)->GetStringUTFChars (env, jlinkname, NULL);

  r = guestfs_ln_f (g, target, linkname);

  (*env)->ReleaseStringUTFChars (env, jtarget, target);
  (*env)->ReleaseStringUTFChars (env, jlinkname, linkname);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1ln_1s  (JNIEnv *env, jobject obj, jlong jg, jstring jtarget, jstring jlinkname)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *target;
  const char *linkname;

  target = (*env)->GetStringUTFChars (env, jtarget, NULL);
  linkname = (*env)->GetStringUTFChars (env, jlinkname, NULL);

  r = guestfs_ln_s (g, target, linkname);

  (*env)->ReleaseStringUTFChars (env, jtarget, target);
  (*env)->ReleaseStringUTFChars (env, jlinkname, linkname);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1ln_1sf  (JNIEnv *env, jobject obj, jlong jg, jstring jtarget, jstring jlinkname)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *target;
  const char *linkname;

  target = (*env)->GetStringUTFChars (env, jtarget, NULL);
  linkname = (*env)->GetStringUTFChars (env, jlinkname, NULL);

  r = guestfs_ln_sf (g, target, linkname);

  (*env)->ReleaseStringUTFChars (env, jtarget, target);
  (*env)->ReleaseStringUTFChars (env, jlinkname, linkname);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1lremovexattr  (JNIEnv *env, jobject obj, jlong jg, jstring jxattr, jstring jpath)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *xattr;
  const char *path;

  xattr = (*env)->GetStringUTFChars (env, jxattr, NULL);
  path = (*env)->GetStringUTFChars (env, jpath, NULL);

  r = guestfs_lremovexattr (g, xattr, path);

  (*env)->ReleaseStringUTFChars (env, jxattr, xattr);
  (*env)->ReleaseStringUTFChars (env, jpath, path);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT jobjectArray JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1ls  (JNIEnv *env, jobject obj, jlong jg, jstring jdirectory)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  jobjectArray jr;
  size_t r_len;
  jclass cl;
  jstring jstr;
  char **r;
  const char *directory;
  size_t i;

  directory = (*env)->GetStringUTFChars (env, jdirectory, NULL);

  r = guestfs_ls (g, directory);

  (*env)->ReleaseStringUTFChars (env, jdirectory, directory);

  if (r == NULL) {
    throw_exception (env, guestfs_last_error (g));
    return NULL;
  }
  for (r_len = 0; r[r_len] != NULL; ++r_len) ;
  cl = (*env)->FindClass (env, "java/lang/String");
  jstr = (*env)->NewStringUTF (env, "");
  jr = (*env)->NewObjectArray (env, r_len, cl, jstr);
  for (i = 0; i < r_len; ++i) {
    jstr = (*env)->NewStringUTF (env, r[i]);
    (*env)->SetObjectArrayElement (env, jr, i, jstr);
    free (r[i]);
  }
  free (r);
  return jr;
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1ls0  (JNIEnv *env, jobject obj, jlong jg, jstring jdir, jstring jfilenames)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *dir;
  const char *filenames;

  dir = (*env)->GetStringUTFChars (env, jdir, NULL);
  filenames = (*env)->GetStringUTFChars (env, jfilenames, NULL);

  r = guestfs_ls0 (g, dir, filenames);

  (*env)->ReleaseStringUTFChars (env, jdir, dir);
  (*env)->ReleaseStringUTFChars (env, jfilenames, filenames);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1lsetxattr  (JNIEnv *env, jobject obj, jlong jg, jstring jxattr, jstring jval, jint jvallen, jstring jpath)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *xattr;
  const char *val;
  int vallen;
  const char *path;

  xattr = (*env)->GetStringUTFChars (env, jxattr, NULL);
  val = (*env)->GetStringUTFChars (env, jval, NULL);
  vallen = jvallen;
  path = (*env)->GetStringUTFChars (env, jpath, NULL);

  r = guestfs_lsetxattr (g, xattr, val, vallen, path);

  (*env)->ReleaseStringUTFChars (env, jxattr, xattr);
  (*env)->ReleaseStringUTFChars (env, jval, val);
  (*env)->ReleaseStringUTFChars (env, jpath, path);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT jobject JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1lstat  (JNIEnv *env, jobject obj, jlong jg, jstring jpath)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  jobject jr;
  jclass cl;
  jfieldID fl;
  struct guestfs_stat *r;
  const char *path;

  path = (*env)->GetStringUTFChars (env, jpath, NULL);

  r = guestfs_lstat (g, path);

  (*env)->ReleaseStringUTFChars (env, jpath, path);

  if (r == NULL) {
    throw_exception (env, guestfs_last_error (g));
    return NULL;
  }
  cl = (*env)->FindClass (env, "com/redhat/et/libguestfs/Stat");
  jr = (*env)->AllocObject (env, cl);
  fl = (*env)->GetFieldID (env, cl, "dev", "J");
  (*env)->SetLongField (env, jr, fl, r->dev);
  fl = (*env)->GetFieldID (env, cl, "ino", "J");
  (*env)->SetLongField (env, jr, fl, r->ino);
  fl = (*env)->GetFieldID (env, cl, "mode", "J");
  (*env)->SetLongField (env, jr, fl, r->mode);
  fl = (*env)->GetFieldID (env, cl, "nlink", "J");
  (*env)->SetLongField (env, jr, fl, r->nlink);
  fl = (*env)->GetFieldID (env, cl, "uid", "J");
  (*env)->SetLongField (env, jr, fl, r->uid);
  fl = (*env)->GetFieldID (env, cl, "gid", "J");
  (*env)->SetLongField (env, jr, fl, r->gid);
  fl = (*env)->GetFieldID (env, cl, "rdev", "J");
  (*env)->SetLongField (env, jr, fl, r->rdev);
  fl = (*env)->GetFieldID (env, cl, "size", "J");
  (*env)->SetLongField (env, jr, fl, r->size);
  fl = (*env)->GetFieldID (env, cl, "blksize", "J");
  (*env)->SetLongField (env, jr, fl, r->blksize);
  fl = (*env)->GetFieldID (env, cl, "blocks", "J");
  (*env)->SetLongField (env, jr, fl, r->blocks);
  fl = (*env)->GetFieldID (env, cl, "atime", "J");
  (*env)->SetLongField (env, jr, fl, r->atime);
  fl = (*env)->GetFieldID (env, cl, "mtime", "J");
  (*env)->SetLongField (env, jr, fl, r->mtime);
  fl = (*env)->GetFieldID (env, cl, "ctime", "J");
  (*env)->SetLongField (env, jr, fl, r->ctime);
  free (r);
  return jr;
}

JNIEXPORT jobjectArray JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1lstatlist  (JNIEnv *env, jobject obj, jlong jg, jstring jpath, jobjectArray jnames)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  jobjectArray jr;
  jclass cl;
  jfieldID fl;
  jobject jfl;
  struct guestfs_stat_list *r;
  const char *path;
  size_t names_len;
  char **names;
  size_t i;

  path = (*env)->GetStringUTFChars (env, jpath, NULL);
  names_len = (*env)->GetArrayLength (env, jnames);
  names = guestfs___safe_malloc (g, sizeof (char *) * (names_len+1));
  for (i = 0; i < names_len; ++i) {
    jobject o = (*env)->GetObjectArrayElement (env, jnames, i);
    names[i] = (char *) (*env)->GetStringUTFChars (env, o, NULL);
  }
  names[names_len] = NULL;

  r = guestfs_lstatlist (g, path, names);

  (*env)->ReleaseStringUTFChars (env, jpath, path);
  for (i = 0; i < names_len; ++i) {
    jobject o = (*env)->GetObjectArrayElement (env, jnames, i);
    (*env)->ReleaseStringUTFChars (env, o, names[i]);
  }
  free (names);

  if (r == NULL) {
    throw_exception (env, guestfs_last_error (g));
    return NULL;
  }
  cl = (*env)->FindClass (env, "com/redhat/et/libguestfs/Stat");
  jr = (*env)->NewObjectArray (env, r->len, cl, NULL);

  for (i = 0; i < r->len; ++i) {
    jfl = (*env)->AllocObject (env, cl);

    fl = (*env)->GetFieldID (env, cl, "dev",
                             "J");
    (*env)->SetLongField (env, jfl, fl, r->val[i].dev);
    fl = (*env)->GetFieldID (env, cl, "ino",
                             "J");
    (*env)->SetLongField (env, jfl, fl, r->val[i].ino);
    fl = (*env)->GetFieldID (env, cl, "mode",
                             "J");
    (*env)->SetLongField (env, jfl, fl, r->val[i].mode);
    fl = (*env)->GetFieldID (env, cl, "nlink",
                             "J");
    (*env)->SetLongField (env, jfl, fl, r->val[i].nlink);
    fl = (*env)->GetFieldID (env, cl, "uid",
                             "J");
    (*env)->SetLongField (env, jfl, fl, r->val[i].uid);
    fl = (*env)->GetFieldID (env, cl, "gid",
                             "J");
    (*env)->SetLongField (env, jfl, fl, r->val[i].gid);
    fl = (*env)->GetFieldID (env, cl, "rdev",
                             "J");
    (*env)->SetLongField (env, jfl, fl, r->val[i].rdev);
    fl = (*env)->GetFieldID (env, cl, "size",
                             "J");
    (*env)->SetLongField (env, jfl, fl, r->val[i].size);
    fl = (*env)->GetFieldID (env, cl, "blksize",
                             "J");
    (*env)->SetLongField (env, jfl, fl, r->val[i].blksize);
    fl = (*env)->GetFieldID (env, cl, "blocks",
                             "J");
    (*env)->SetLongField (env, jfl, fl, r->val[i].blocks);
    fl = (*env)->GetFieldID (env, cl, "atime",
                             "J");
    (*env)->SetLongField (env, jfl, fl, r->val[i].atime);
    fl = (*env)->GetFieldID (env, cl, "mtime",
                             "J");
    (*env)->SetLongField (env, jfl, fl, r->val[i].mtime);
    fl = (*env)->GetFieldID (env, cl, "ctime",
                             "J");
    (*env)->SetLongField (env, jfl, fl, r->val[i].ctime);

    (*env)->SetObjectArrayElement (env, jr, i, jfl);
  }

  guestfs_free_stat_list (r);
  return jr;
}

JNIEXPORT jobject JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1lstatns  (JNIEnv *env, jobject obj, jlong jg, jstring jpath)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  jobject jr;
  jclass cl;
  jfieldID fl;
  struct guestfs_statns *r;
  const char *path;

  path = (*env)->GetStringUTFChars (env, jpath, NULL);

  r = guestfs_lstatns (g, path);

  (*env)->ReleaseStringUTFChars (env, jpath, path);

  if (r == NULL) {
    throw_exception (env, guestfs_last_error (g));
    return NULL;
  }
  cl = (*env)->FindClass (env, "com/redhat/et/libguestfs/StatNS");
  jr = (*env)->AllocObject (env, cl);
  fl = (*env)->GetFieldID (env, cl, "st_dev", "J");
  (*env)->SetLongField (env, jr, fl, r->st_dev);
  fl = (*env)->GetFieldID (env, cl, "st_ino", "J");
  (*env)->SetLongField (env, jr, fl, r->st_ino);
  fl = (*env)->GetFieldID (env, cl, "st_mode", "J");
  (*env)->SetLongField (env, jr, fl, r->st_mode);
  fl = (*env)->GetFieldID (env, cl, "st_nlink", "J");
  (*env)->SetLongField (env, jr, fl, r->st_nlink);
  fl = (*env)->GetFieldID (env, cl, "st_uid", "J");
  (*env)->SetLongField (env, jr, fl, r->st_uid);
  fl = (*env)->GetFieldID (env, cl, "st_gid", "J");
  (*env)->SetLongField (env, jr, fl, r->st_gid);
  fl = (*env)->GetFieldID (env, cl, "st_rdev", "J");
  (*env)->SetLongField (env, jr, fl, r->st_rdev);
  fl = (*env)->GetFieldID (env, cl, "st_size", "J");
  (*env)->SetLongField (env, jr, fl, r->st_size);
  fl = (*env)->GetFieldID (env, cl, "st_blksize", "J");
  (*env)->SetLongField (env, jr, fl, r->st_blksize);
  fl = (*env)->GetFieldID (env, cl, "st_blocks", "J");
  (*env)->SetLongField (env, jr, fl, r->st_blocks);
  fl = (*env)->GetFieldID (env, cl, "st_atime_sec", "J");
  (*env)->SetLongField (env, jr, fl, r->st_atime_sec);
  fl = (*env)->GetFieldID (env, cl, "st_atime_nsec", "J");
  (*env)->SetLongField (env, jr, fl, r->st_atime_nsec);
  fl = (*env)->GetFieldID (env, cl, "st_mtime_sec", "J");
  (*env)->SetLongField (env, jr, fl, r->st_mtime_sec);
  fl = (*env)->GetFieldID (env, cl, "st_mtime_nsec", "J");
  (*env)->SetLongField (env, jr, fl, r->st_mtime_nsec);
  fl = (*env)->GetFieldID (env, cl, "st_ctime_sec", "J");
  (*env)->SetLongField (env, jr, fl, r->st_ctime_sec);
  fl = (*env)->GetFieldID (env, cl, "st_ctime_nsec", "J");
  (*env)->SetLongField (env, jr, fl, r->st_ctime_nsec);
  fl = (*env)->GetFieldID (env, cl, "st_spare1", "J");
  (*env)->SetLongField (env, jr, fl, r->st_spare1);
  fl = (*env)->GetFieldID (env, cl, "st_spare2", "J");
  (*env)->SetLongField (env, jr, fl, r->st_spare2);
  fl = (*env)->GetFieldID (env, cl, "st_spare3", "J");
  (*env)->SetLongField (env, jr, fl, r->st_spare3);
  fl = (*env)->GetFieldID (env, cl, "st_spare4", "J");
  (*env)->SetLongField (env, jr, fl, r->st_spare4);
  fl = (*env)->GetFieldID (env, cl, "st_spare5", "J");
  (*env)->SetLongField (env, jr, fl, r->st_spare5);
  fl = (*env)->GetFieldID (env, cl, "st_spare6", "J");
  (*env)->SetLongField (env, jr, fl, r->st_spare6);
  free (r);
  return jr;
}

JNIEXPORT jobjectArray JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1lstatnslist  (JNIEnv *env, jobject obj, jlong jg, jstring jpath, jobjectArray jnames)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  jobjectArray jr;
  jclass cl;
  jfieldID fl;
  jobject jfl;
  struct guestfs_statns_list *r;
  const char *path;
  size_t names_len;
  char **names;
  size_t i;

  path = (*env)->GetStringUTFChars (env, jpath, NULL);
  names_len = (*env)->GetArrayLength (env, jnames);
  names = guestfs___safe_malloc (g, sizeof (char *) * (names_len+1));
  for (i = 0; i < names_len; ++i) {
    jobject o = (*env)->GetObjectArrayElement (env, jnames, i);
    names[i] = (char *) (*env)->GetStringUTFChars (env, o, NULL);
  }
  names[names_len] = NULL;

  r = guestfs_lstatnslist (g, path, names);

  (*env)->ReleaseStringUTFChars (env, jpath, path);
  for (i = 0; i < names_len; ++i) {
    jobject o = (*env)->GetObjectArrayElement (env, jnames, i);
    (*env)->ReleaseStringUTFChars (env, o, names[i]);
  }
  free (names);

  if (r == NULL) {
    throw_exception (env, guestfs_last_error (g));
    return NULL;
  }
  cl = (*env)->FindClass (env, "com/redhat/et/libguestfs/StatNS");
  jr = (*env)->NewObjectArray (env, r->len, cl, NULL);

  for (i = 0; i < r->len; ++i) {
    jfl = (*env)->AllocObject (env, cl);

    fl = (*env)->GetFieldID (env, cl, "st_dev",
                             "J");
    (*env)->SetLongField (env, jfl, fl, r->val[i].st_dev);
    fl = (*env)->GetFieldID (env, cl, "st_ino",
                             "J");
    (*env)->SetLongField (env, jfl, fl, r->val[i].st_ino);
    fl = (*env)->GetFieldID (env, cl, "st_mode",
                             "J");
    (*env)->SetLongField (env, jfl, fl, r->val[i].st_mode);
    fl = (*env)->GetFieldID (env, cl, "st_nlink",
                             "J");
    (*env)->SetLongField (env, jfl, fl, r->val[i].st_nlink);
    fl = (*env)->GetFieldID (env, cl, "st_uid",
                             "J");
    (*env)->SetLongField (env, jfl, fl, r->val[i].st_uid);
    fl = (*env)->GetFieldID (env, cl, "st_gid",
                             "J");
    (*env)->SetLongField (env, jfl, fl, r->val[i].st_gid);
    fl = (*env)->GetFieldID (env, cl, "st_rdev",
                             "J");
    (*env)->SetLongField (env, jfl, fl, r->val[i].st_rdev);
    fl = (*env)->GetFieldID (env, cl, "st_size",
                             "J");
    (*env)->SetLongField (env, jfl, fl, r->val[i].st_size);
    fl = (*env)->GetFieldID (env, cl, "st_blksize",
                             "J");
    (*env)->SetLongField (env, jfl, fl, r->val[i].st_blksize);
    fl = (*env)->GetFieldID (env, cl, "st_blocks",
                             "J");
    (*env)->SetLongField (env, jfl, fl, r->val[i].st_blocks);
    fl = (*env)->GetFieldID (env, cl, "st_atime_sec",
                             "J");
    (*env)->SetLongField (env, jfl, fl, r->val[i].st_atime_sec);
    fl = (*env)->GetFieldID (env, cl, "st_atime_nsec",
                             "J");
    (*env)->SetLongField (env, jfl, fl, r->val[i].st_atime_nsec);
    fl = (*env)->GetFieldID (env, cl, "st_mtime_sec",
                             "J");
    (*env)->SetLongField (env, jfl, fl, r->val[i].st_mtime_sec);
    fl = (*env)->GetFieldID (env, cl, "st_mtime_nsec",
                             "J");
    (*env)->SetLongField (env, jfl, fl, r->val[i].st_mtime_nsec);
    fl = (*env)->GetFieldID (env, cl, "st_ctime_sec",
                             "J");
    (*env)->SetLongField (env, jfl, fl, r->val[i].st_ctime_sec);
    fl = (*env)->GetFieldID (env, cl, "st_ctime_nsec",
                             "J");
    (*env)->SetLongField (env, jfl, fl, r->val[i].st_ctime_nsec);
    fl = (*env)->GetFieldID (env, cl, "st_spare1",
                             "J");
    (*env)->SetLongField (env, jfl, fl, r->val[i].st_spare1);
    fl = (*env)->GetFieldID (env, cl, "st_spare2",
                             "J");
    (*env)->SetLongField (env, jfl, fl, r->val[i].st_spare2);
    fl = (*env)->GetFieldID (env, cl, "st_spare3",
                             "J");
    (*env)->SetLongField (env, jfl, fl, r->val[i].st_spare3);
    fl = (*env)->GetFieldID (env, cl, "st_spare4",
                             "J");
    (*env)->SetLongField (env, jfl, fl, r->val[i].st_spare4);
    fl = (*env)->GetFieldID (env, cl, "st_spare5",
                             "J");
    (*env)->SetLongField (env, jfl, fl, r->val[i].st_spare5);
    fl = (*env)->GetFieldID (env, cl, "st_spare6",
                             "J");
    (*env)->SetLongField (env, jfl, fl, r->val[i].st_spare6);

    (*env)->SetObjectArrayElement (env, jr, i, jfl);
  }

  guestfs_free_statns_list (r);
  return jr;
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1luks_1add_1key  (JNIEnv *env, jobject obj, jlong jg, jstring jdevice, jstring jkey, jstring jnewkey, jint jkeyslot)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *device;
  const char *key;
  const char *newkey;
  int keyslot;

  device = (*env)->GetStringUTFChars (env, jdevice, NULL);
  key = (*env)->GetStringUTFChars (env, jkey, NULL);
  newkey = (*env)->GetStringUTFChars (env, jnewkey, NULL);
  keyslot = jkeyslot;

  r = guestfs_luks_add_key (g, device, key, newkey, keyslot);

  (*env)->ReleaseStringUTFChars (env, jdevice, device);
  (*env)->ReleaseStringUTFChars (env, jkey, key);
  (*env)->ReleaseStringUTFChars (env, jnewkey, newkey);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1luks_1close  (JNIEnv *env, jobject obj, jlong jg, jstring jdevice)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *device;

  device = (*env)->GetStringUTFChars (env, jdevice, NULL);

  r = guestfs_luks_close (g, device);

  (*env)->ReleaseStringUTFChars (env, jdevice, device);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1luks_1format  (JNIEnv *env, jobject obj, jlong jg, jstring jdevice, jstring jkey, jint jkeyslot)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *device;
  const char *key;
  int keyslot;

  device = (*env)->GetStringUTFChars (env, jdevice, NULL);
  key = (*env)->GetStringUTFChars (env, jkey, NULL);
  keyslot = jkeyslot;

  r = guestfs_luks_format (g, device, key, keyslot);

  (*env)->ReleaseStringUTFChars (env, jdevice, device);
  (*env)->ReleaseStringUTFChars (env, jkey, key);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1luks_1format_1cipher  (JNIEnv *env, jobject obj, jlong jg, jstring jdevice, jstring jkey, jint jkeyslot, jstring jcipher)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *device;
  const char *key;
  int keyslot;
  const char *cipher;

  device = (*env)->GetStringUTFChars (env, jdevice, NULL);
  key = (*env)->GetStringUTFChars (env, jkey, NULL);
  keyslot = jkeyslot;
  cipher = (*env)->GetStringUTFChars (env, jcipher, NULL);

  r = guestfs_luks_format_cipher (g, device, key, keyslot, cipher);

  (*env)->ReleaseStringUTFChars (env, jdevice, device);
  (*env)->ReleaseStringUTFChars (env, jkey, key);
  (*env)->ReleaseStringUTFChars (env, jcipher, cipher);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1luks_1kill_1slot  (JNIEnv *env, jobject obj, jlong jg, jstring jdevice, jstring jkey, jint jkeyslot)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *device;
  const char *key;
  int keyslot;

  device = (*env)->GetStringUTFChars (env, jdevice, NULL);
  key = (*env)->GetStringUTFChars (env, jkey, NULL);
  keyslot = jkeyslot;

  r = guestfs_luks_kill_slot (g, device, key, keyslot);

  (*env)->ReleaseStringUTFChars (env, jdevice, device);
  (*env)->ReleaseStringUTFChars (env, jkey, key);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1luks_1open  (JNIEnv *env, jobject obj, jlong jg, jstring jdevice, jstring jkey, jstring jmapname)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *device;
  const char *key;
  const char *mapname;

  device = (*env)->GetStringUTFChars (env, jdevice, NULL);
  key = (*env)->GetStringUTFChars (env, jkey, NULL);
  mapname = (*env)->GetStringUTFChars (env, jmapname, NULL);

  r = guestfs_luks_open (g, device, key, mapname);

  (*env)->ReleaseStringUTFChars (env, jdevice, device);
  (*env)->ReleaseStringUTFChars (env, jkey, key);
  (*env)->ReleaseStringUTFChars (env, jmapname, mapname);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1luks_1open_1ro  (JNIEnv *env, jobject obj, jlong jg, jstring jdevice, jstring jkey, jstring jmapname)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *device;
  const char *key;
  const char *mapname;

  device = (*env)->GetStringUTFChars (env, jdevice, NULL);
  key = (*env)->GetStringUTFChars (env, jkey, NULL);
  mapname = (*env)->GetStringUTFChars (env, jmapname, NULL);

  r = guestfs_luks_open_ro (g, device, key, mapname);

  (*env)->ReleaseStringUTFChars (env, jdevice, device);
  (*env)->ReleaseStringUTFChars (env, jkey, key);
  (*env)->ReleaseStringUTFChars (env, jmapname, mapname);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1lvcreate  (JNIEnv *env, jobject obj, jlong jg, jstring jlogvol, jstring jvolgroup, jint jmbytes)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *logvol;
  const char *volgroup;
  int mbytes;

  logvol = (*env)->GetStringUTFChars (env, jlogvol, NULL);
  volgroup = (*env)->GetStringUTFChars (env, jvolgroup, NULL);
  mbytes = jmbytes;

  r = guestfs_lvcreate (g, logvol, volgroup, mbytes);

  (*env)->ReleaseStringUTFChars (env, jlogvol, logvol);
  (*env)->ReleaseStringUTFChars (env, jvolgroup, volgroup);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1lvcreate_1free  (JNIEnv *env, jobject obj, jlong jg, jstring jlogvol, jstring jvolgroup, jint jpercent)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *logvol;
  const char *volgroup;
  int percent;

  logvol = (*env)->GetStringUTFChars (env, jlogvol, NULL);
  volgroup = (*env)->GetStringUTFChars (env, jvolgroup, NULL);
  percent = jpercent;

  r = guestfs_lvcreate_free (g, logvol, volgroup, percent);

  (*env)->ReleaseStringUTFChars (env, jlogvol, logvol);
  (*env)->ReleaseStringUTFChars (env, jvolgroup, volgroup);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT jstring JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1lvm_1canonical_1lv_1name  (JNIEnv *env, jobject obj, jlong jg, jstring jlvname)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  jstring jr;
  char *r;
  const char *lvname;

  lvname = (*env)->GetStringUTFChars (env, jlvname, NULL);

  r = guestfs_lvm_canonical_lv_name (g, lvname);

  (*env)->ReleaseStringUTFChars (env, jlvname, lvname);

  if (r == NULL) {
    throw_exception (env, guestfs_last_error (g));
    return NULL;
  }
  jr = (*env)->NewStringUTF (env, r);
  free (r);
  return jr;
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1lvm_1clear_1filter  (JNIEnv *env, jobject obj, jlong jg)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;


  r = guestfs_lvm_clear_filter (g);


  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1lvm_1remove_1all  (JNIEnv *env, jobject obj, jlong jg)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;


  r = guestfs_lvm_remove_all (g);


  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1lvm_1set_1filter  (JNIEnv *env, jobject obj, jlong jg, jobjectArray jdevices)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  size_t devices_len;
  char **devices;
  size_t i;

  devices_len = (*env)->GetArrayLength (env, jdevices);
  devices = guestfs___safe_malloc (g, sizeof (char *) * (devices_len+1));
  for (i = 0; i < devices_len; ++i) {
    jobject o = (*env)->GetObjectArrayElement (env, jdevices, i);
    devices[i] = (char *) (*env)->GetStringUTFChars (env, o, NULL);
  }
  devices[devices_len] = NULL;

  r = guestfs_lvm_set_filter (g, devices);

  for (i = 0; i < devices_len; ++i) {
    jobject o = (*env)->GetObjectArrayElement (env, jdevices, i);
    (*env)->ReleaseStringUTFChars (env, o, devices[i]);
  }
  free (devices);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1lvremove  (JNIEnv *env, jobject obj, jlong jg, jstring jdevice)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *device;

  device = (*env)->GetStringUTFChars (env, jdevice, NULL);

  r = guestfs_lvremove (g, device);

  (*env)->ReleaseStringUTFChars (env, jdevice, device);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1lvrename  (JNIEnv *env, jobject obj, jlong jg, jstring jlogvol, jstring jnewlogvol)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *logvol;
  const char *newlogvol;

  logvol = (*env)->GetStringUTFChars (env, jlogvol, NULL);
  newlogvol = (*env)->GetStringUTFChars (env, jnewlogvol, NULL);

  r = guestfs_lvrename (g, logvol, newlogvol);

  (*env)->ReleaseStringUTFChars (env, jlogvol, logvol);
  (*env)->ReleaseStringUTFChars (env, jnewlogvol, newlogvol);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1lvresize  (JNIEnv *env, jobject obj, jlong jg, jstring jdevice, jint jmbytes)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *device;
  int mbytes;

  device = (*env)->GetStringUTFChars (env, jdevice, NULL);
  mbytes = jmbytes;

  r = guestfs_lvresize (g, device, mbytes);

  (*env)->ReleaseStringUTFChars (env, jdevice, device);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1lvresize_1free  (JNIEnv *env, jobject obj, jlong jg, jstring jlv, jint jpercent)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *lv;
  int percent;

  lv = (*env)->GetStringUTFChars (env, jlv, NULL);
  percent = jpercent;

  r = guestfs_lvresize_free (g, lv, percent);

  (*env)->ReleaseStringUTFChars (env, jlv, lv);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT jobjectArray JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1lvs  (JNIEnv *env, jobject obj, jlong jg)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  jobjectArray jr;
  size_t r_len;
  jclass cl;
  jstring jstr;
  char **r;
  size_t i;


  r = guestfs_lvs (g);


  if (r == NULL) {
    throw_exception (env, guestfs_last_error (g));
    return NULL;
  }
  for (r_len = 0; r[r_len] != NULL; ++r_len) ;
  cl = (*env)->FindClass (env, "java/lang/String");
  jstr = (*env)->NewStringUTF (env, "");
  jr = (*env)->NewObjectArray (env, r_len, cl, jstr);
  for (i = 0; i < r_len; ++i) {
    jstr = (*env)->NewStringUTF (env, r[i]);
    (*env)->SetObjectArrayElement (env, jr, i, jstr);
    free (r[i]);
  }
  free (r);
  return jr;
}

JNIEXPORT jobjectArray JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1lvs_1full  (JNIEnv *env, jobject obj, jlong jg)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  jobjectArray jr;
  jclass cl;
  jfieldID fl;
  jobject jfl;
  struct guestfs_lvm_lv_list *r;
  size_t i;


  r = guestfs_lvs_full (g);


  if (r == NULL) {
    throw_exception (env, guestfs_last_error (g));
    return NULL;
  }
  cl = (*env)->FindClass (env, "com/redhat/et/libguestfs/LV");
  jr = (*env)->NewObjectArray (env, r->len, cl, NULL);

  for (i = 0; i < r->len; ++i) {
    jfl = (*env)->AllocObject (env, cl);

    fl = (*env)->GetFieldID (env, cl, "lv_name",
                             "Ljava/lang/String;");
    (*env)->SetObjectField (env, jfl, fl,
                            (*env)->NewStringUTF (env, r->val[i].lv_name));
    fl = (*env)->GetFieldID (env, cl, "lv_uuid",
                             "Ljava/lang/String;");
    {
      char s[33];
      memcpy (s, r->val[i].lv_uuid, 32);
      s[32] = 0;
      (*env)->SetObjectField (env, jfl, fl,
                              (*env)->NewStringUTF (env, s));
    }
    fl = (*env)->GetFieldID (env, cl, "lv_attr",
                             "Ljava/lang/String;");
    (*env)->SetObjectField (env, jfl, fl,
                            (*env)->NewStringUTF (env, r->val[i].lv_attr));
    fl = (*env)->GetFieldID (env, cl, "lv_major",
                             "J");
    (*env)->SetLongField (env, jfl, fl, r->val[i].lv_major);
    fl = (*env)->GetFieldID (env, cl, "lv_minor",
                             "J");
    (*env)->SetLongField (env, jfl, fl, r->val[i].lv_minor);
    fl = (*env)->GetFieldID (env, cl, "lv_kernel_major",
                             "J");
    (*env)->SetLongField (env, jfl, fl, r->val[i].lv_kernel_major);
    fl = (*env)->GetFieldID (env, cl, "lv_kernel_minor",
                             "J");
    (*env)->SetLongField (env, jfl, fl, r->val[i].lv_kernel_minor);
    fl = (*env)->GetFieldID (env, cl, "lv_size",
                             "J");
    (*env)->SetLongField (env, jfl, fl, r->val[i].lv_size);
    fl = (*env)->GetFieldID (env, cl, "seg_count",
                             "J");
    (*env)->SetLongField (env, jfl, fl, r->val[i].seg_count);
    fl = (*env)->GetFieldID (env, cl, "origin",
                             "Ljava/lang/String;");
    (*env)->SetObjectField (env, jfl, fl,
                            (*env)->NewStringUTF (env, r->val[i].origin));
    fl = (*env)->GetFieldID (env, cl, "snap_percent",
                             "F");
    (*env)->SetFloatField (env, jfl, fl, r->val[i].snap_percent);
    fl = (*env)->GetFieldID (env, cl, "copy_percent",
                             "F");
    (*env)->SetFloatField (env, jfl, fl, r->val[i].copy_percent);
    fl = (*env)->GetFieldID (env, cl, "move_pv",
                             "Ljava/lang/String;");
    (*env)->SetObjectField (env, jfl, fl,
                            (*env)->NewStringUTF (env, r->val[i].move_pv));
    fl = (*env)->GetFieldID (env, cl, "lv_tags",
                             "Ljava/lang/String;");
    (*env)->SetObjectField (env, jfl, fl,
                            (*env)->NewStringUTF (env, r->val[i].lv_tags));
    fl = (*env)->GetFieldID (env, cl, "mirror_log",
                             "Ljava/lang/String;");
    (*env)->SetObjectField (env, jfl, fl,
                            (*env)->NewStringUTF (env, r->val[i].mirror_log));
    fl = (*env)->GetFieldID (env, cl, "modules",
                             "Ljava/lang/String;");
    (*env)->SetObjectField (env, jfl, fl,
                            (*env)->NewStringUTF (env, r->val[i].modules));

    (*env)->SetObjectArrayElement (env, jr, i, jfl);
  }

  guestfs_free_lvm_lv_list (r);
  return jr;
}

JNIEXPORT jstring JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1lvuuid  (JNIEnv *env, jobject obj, jlong jg, jstring jdevice)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  jstring jr;
  char *r;
  const char *device;

  device = (*env)->GetStringUTFChars (env, jdevice, NULL);

  r = guestfs_lvuuid (g, device);

  (*env)->ReleaseStringUTFChars (env, jdevice, device);

  if (r == NULL) {
    throw_exception (env, guestfs_last_error (g));
    return NULL;
  }
  jr = (*env)->NewStringUTF (env, r);
  free (r);
  return jr;
}

JNIEXPORT jobjectArray JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1lxattrlist  (JNIEnv *env, jobject obj, jlong jg, jstring jpath, jobjectArray jnames)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  jobjectArray jr;
  jclass cl;
  jfieldID fl;
  jobject jfl;
  struct guestfs_xattr_list *r;
  const char *path;
  size_t names_len;
  char **names;
  size_t i;

  path = (*env)->GetStringUTFChars (env, jpath, NULL);
  names_len = (*env)->GetArrayLength (env, jnames);
  names = guestfs___safe_malloc (g, sizeof (char *) * (names_len+1));
  for (i = 0; i < names_len; ++i) {
    jobject o = (*env)->GetObjectArrayElement (env, jnames, i);
    names[i] = (char *) (*env)->GetStringUTFChars (env, o, NULL);
  }
  names[names_len] = NULL;

  r = guestfs_lxattrlist (g, path, names);

  (*env)->ReleaseStringUTFChars (env, jpath, path);
  for (i = 0; i < names_len; ++i) {
    jobject o = (*env)->GetObjectArrayElement (env, jnames, i);
    (*env)->ReleaseStringUTFChars (env, o, names[i]);
  }
  free (names);

  if (r == NULL) {
    throw_exception (env, guestfs_last_error (g));
    return NULL;
  }
  cl = (*env)->FindClass (env, "com/redhat/et/libguestfs/XAttr");
  jr = (*env)->NewObjectArray (env, r->len, cl, NULL);

  for (i = 0; i < r->len; ++i) {
    jfl = (*env)->AllocObject (env, cl);

    fl = (*env)->GetFieldID (env, cl, "attrname",
                             "Ljava/lang/String;");
    (*env)->SetObjectField (env, jfl, fl,
                            (*env)->NewStringUTF (env, r->val[i].attrname));
    fl = (*env)->GetFieldID (env, cl, "attrval",
                             "Ljava/lang/String;");
    {
      size_t len = r->val[i].attrval_len;
      char s[len+1];
      memcpy (s, r->val[i].attrval, len);
      s[len] = 0;
      (*env)->SetObjectField (env, jfl, fl,
                              (*env)->NewStringUTF (env, s));
    }

    (*env)->SetObjectArrayElement (env, jr, i, jfl);
  }

  guestfs_free_xattr_list (r);
  return jr;
}

JNIEXPORT jint JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1max_1disks  (JNIEnv *env, jobject obj, jlong jg)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;


  r = guestfs_max_disks (g);


  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return -1;
  }
  return (jint) r;
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1md_1create  (JNIEnv *env, jobject obj, jlong jg, jstring jname, jobjectArray jdevices, jlong joptargs_bitmask, jlong jmissingbitmap, jint jnrdevices, jint jspare, jlong jchunk, jstring jlevel)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *name;
  size_t devices_len;
  char **devices;
  struct guestfs_md_create_argv optargs_s;
  const struct guestfs_md_create_argv *optargs = &optargs_s;
  size_t i;

  name = (*env)->GetStringUTFChars (env, jname, NULL);
  devices_len = (*env)->GetArrayLength (env, jdevices);
  devices = guestfs___safe_malloc (g, sizeof (char *) * (devices_len+1));
  for (i = 0; i < devices_len; ++i) {
    jobject o = (*env)->GetObjectArrayElement (env, jdevices, i);
    devices[i] = (char *) (*env)->GetStringUTFChars (env, o, NULL);
  }
  devices[devices_len] = NULL;

  optargs_s.missingbitmap = jmissingbitmap;
  optargs_s.nrdevices = jnrdevices;
  optargs_s.spare = jspare;
  optargs_s.chunk = jchunk;
  optargs_s.level = (*env)->GetStringUTFChars (env, jlevel, NULL);
  optargs_s.bitmask = joptargs_bitmask;

  r = guestfs_md_create_argv (g, name, devices, optargs);

  (*env)->ReleaseStringUTFChars (env, jname, name);
  for (i = 0; i < devices_len; ++i) {
    jobject o = (*env)->GetObjectArrayElement (env, jdevices, i);
    (*env)->ReleaseStringUTFChars (env, o, devices[i]);
  }
  free (devices);
  (*env)->ReleaseStringUTFChars (env, jlevel, optargs_s.level);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT jobject JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1md_1detail  (JNIEnv *env, jobject obj, jlong jg, jstring jmd)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  jobjectArray jr;
  size_t r_len;
  jclass cl;
  jstring jstr;
  char **r;
  const char *md;
  size_t i;

  md = (*env)->GetStringUTFChars (env, jmd, NULL);

  r = guestfs_md_detail (g, md);

  (*env)->ReleaseStringUTFChars (env, jmd, md);

  if (r == NULL) {
    throw_exception (env, guestfs_last_error (g));
    return NULL;
  }
  for (r_len = 0; r[r_len] != NULL; ++r_len) ;
  cl = (*env)->FindClass (env, "java/lang/String");
  jstr = (*env)->NewStringUTF (env, "");
  jr = (*env)->NewObjectArray (env, r_len, cl, jstr);
  for (i = 0; i < r_len; ++i) {
    jstr = (*env)->NewStringUTF (env, r[i]);
    (*env)->SetObjectArrayElement (env, jr, i, jstr);
    free (r[i]);
  }
  free (r);
  return jr;
}

JNIEXPORT jobjectArray JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1md_1stat  (JNIEnv *env, jobject obj, jlong jg, jstring jmd)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  jobjectArray jr;
  jclass cl;
  jfieldID fl;
  jobject jfl;
  struct guestfs_mdstat_list *r;
  const char *md;
  size_t i;

  md = (*env)->GetStringUTFChars (env, jmd, NULL);

  r = guestfs_md_stat (g, md);

  (*env)->ReleaseStringUTFChars (env, jmd, md);

  if (r == NULL) {
    throw_exception (env, guestfs_last_error (g));
    return NULL;
  }
  cl = (*env)->FindClass (env, "com/redhat/et/libguestfs/MDStat");
  jr = (*env)->NewObjectArray (env, r->len, cl, NULL);

  for (i = 0; i < r->len; ++i) {
    jfl = (*env)->AllocObject (env, cl);

    fl = (*env)->GetFieldID (env, cl, "mdstat_device",
                             "Ljava/lang/String;");
    (*env)->SetObjectField (env, jfl, fl,
                            (*env)->NewStringUTF (env, r->val[i].mdstat_device));
    fl = (*env)->GetFieldID (env, cl, "mdstat_index",
                             "I");
    (*env)->SetIntField (env, jfl, fl, r->val[i].mdstat_index);
    fl = (*env)->GetFieldID (env, cl, "mdstat_flags",
                             "Ljava/lang/String;");
    (*env)->SetObjectField (env, jfl, fl,
                            (*env)->NewStringUTF (env, r->val[i].mdstat_flags));

    (*env)->SetObjectArrayElement (env, jr, i, jfl);
  }

  guestfs_free_mdstat_list (r);
  return jr;
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1md_1stop  (JNIEnv *env, jobject obj, jlong jg, jstring jmd)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *md;

  md = (*env)->GetStringUTFChars (env, jmd, NULL);

  r = guestfs_md_stop (g, md);

  (*env)->ReleaseStringUTFChars (env, jmd, md);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1mkdir  (JNIEnv *env, jobject obj, jlong jg, jstring jpath)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *path;

  path = (*env)->GetStringUTFChars (env, jpath, NULL);

  r = guestfs_mkdir (g, path);

  (*env)->ReleaseStringUTFChars (env, jpath, path);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1mkdir_1mode  (JNIEnv *env, jobject obj, jlong jg, jstring jpath, jint jmode)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *path;
  int mode;

  path = (*env)->GetStringUTFChars (env, jpath, NULL);
  mode = jmode;

  r = guestfs_mkdir_mode (g, path, mode);

  (*env)->ReleaseStringUTFChars (env, jpath, path);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1mkdir_1p  (JNIEnv *env, jobject obj, jlong jg, jstring jpath)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *path;

  path = (*env)->GetStringUTFChars (env, jpath, NULL);

  r = guestfs_mkdir_p (g, path);

  (*env)->ReleaseStringUTFChars (env, jpath, path);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT jstring JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1mkdtemp  (JNIEnv *env, jobject obj, jlong jg, jstring jtmpl)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  jstring jr;
  char *r;
  const char *tmpl;

  tmpl = (*env)->GetStringUTFChars (env, jtmpl, NULL);

  r = guestfs_mkdtemp (g, tmpl);

  (*env)->ReleaseStringUTFChars (env, jtmpl, tmpl);

  if (r == NULL) {
    throw_exception (env, guestfs_last_error (g));
    return NULL;
  }
  jr = (*env)->NewStringUTF (env, r);
  free (r);
  return jr;
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1mke2fs  (JNIEnv *env, jobject obj, jlong jg, jstring jdevice, jlong joptargs_bitmask, jlong jblockscount, jlong jblocksize, jlong jfragsize, jlong jblockspergroup, jlong jnumberofgroups, jlong jbytesperinode, jlong jinodesize, jlong jjournalsize, jlong jnumberofinodes, jlong jstridesize, jlong jstripewidth, jlong jmaxonlineresize, jint jreservedblockspercentage, jint jmmpupdateinterval, jstring jjournaldevice, jstring jlabel, jstring jlastmounteddir, jstring jcreatoros, jstring jfstype, jstring jusagetype, jstring juuid, jboolean jforcecreate, jboolean jwritesbandgrouponly, jboolean jlazyitableinit, jboolean jlazyjournalinit, jboolean jtestfs, jboolean jdiscard, jboolean jquotatype, jboolean jextent, jboolean jfiletype, jboolean jflexbg, jboolean jhasjournal, jboolean jjournaldev, jboolean jlargefile, jboolean jquota, jboolean jresizeinode, jboolean jsparsesuper, jboolean juninitbg)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *device;
  struct guestfs_mke2fs_argv optargs_s;
  const struct guestfs_mke2fs_argv *optargs = &optargs_s;

  device = (*env)->GetStringUTFChars (env, jdevice, NULL);

  optargs_s.blockscount = jblockscount;
  optargs_s.blocksize = jblocksize;
  optargs_s.fragsize = jfragsize;
  optargs_s.blockspergroup = jblockspergroup;
  optargs_s.numberofgroups = jnumberofgroups;
  optargs_s.bytesperinode = jbytesperinode;
  optargs_s.inodesize = jinodesize;
  optargs_s.journalsize = jjournalsize;
  optargs_s.numberofinodes = jnumberofinodes;
  optargs_s.stridesize = jstridesize;
  optargs_s.stripewidth = jstripewidth;
  optargs_s.maxonlineresize = jmaxonlineresize;
  optargs_s.reservedblockspercentage = jreservedblockspercentage;
  optargs_s.mmpupdateinterval = jmmpupdateinterval;
  optargs_s.journaldevice = (*env)->GetStringUTFChars (env, jjournaldevice, NULL);
  optargs_s.label = (*env)->GetStringUTFChars (env, jlabel, NULL);
  optargs_s.lastmounteddir = (*env)->GetStringUTFChars (env, jlastmounteddir, NULL);
  optargs_s.creatoros = (*env)->GetStringUTFChars (env, jcreatoros, NULL);
  optargs_s.fstype = (*env)->GetStringUTFChars (env, jfstype, NULL);
  optargs_s.usagetype = (*env)->GetStringUTFChars (env, jusagetype, NULL);
  optargs_s.uuid = (*env)->GetStringUTFChars (env, juuid, NULL);
  optargs_s.forcecreate = jforcecreate;
  optargs_s.writesbandgrouponly = jwritesbandgrouponly;
  optargs_s.lazyitableinit = jlazyitableinit;
  optargs_s.lazyjournalinit = jlazyjournalinit;
  optargs_s.testfs = jtestfs;
  optargs_s.discard = jdiscard;
  optargs_s.quotatype = jquotatype;
  optargs_s.extent = jextent;
  optargs_s.filetype = jfiletype;
  optargs_s.flexbg = jflexbg;
  optargs_s.hasjournal = jhasjournal;
  optargs_s.journaldev = jjournaldev;
  optargs_s.largefile = jlargefile;
  optargs_s.quota = jquota;
  optargs_s.resizeinode = jresizeinode;
  optargs_s.sparsesuper = jsparsesuper;
  optargs_s.uninitbg = juninitbg;
  optargs_s.bitmask = joptargs_bitmask;

  r = guestfs_mke2fs_argv (g, device, optargs);

  (*env)->ReleaseStringUTFChars (env, jdevice, device);
  (*env)->ReleaseStringUTFChars (env, jjournaldevice, optargs_s.journaldevice);
  (*env)->ReleaseStringUTFChars (env, jlabel, optargs_s.label);
  (*env)->ReleaseStringUTFChars (env, jlastmounteddir, optargs_s.lastmounteddir);
  (*env)->ReleaseStringUTFChars (env, jcreatoros, optargs_s.creatoros);
  (*env)->ReleaseStringUTFChars (env, jfstype, optargs_s.fstype);
  (*env)->ReleaseStringUTFChars (env, jusagetype, optargs_s.usagetype);
  (*env)->ReleaseStringUTFChars (env, juuid, optargs_s.uuid);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1mke2fs_1J  (JNIEnv *env, jobject obj, jlong jg, jstring jfstype, jint jblocksize, jstring jdevice, jstring jjournal)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *fstype;
  int blocksize;
  const char *device;
  const char *journal;

  fstype = (*env)->GetStringUTFChars (env, jfstype, NULL);
  blocksize = jblocksize;
  device = (*env)->GetStringUTFChars (env, jdevice, NULL);
  journal = (*env)->GetStringUTFChars (env, jjournal, NULL);

  r = guestfs_mke2fs_J (g, fstype, blocksize, device, journal);

  (*env)->ReleaseStringUTFChars (env, jfstype, fstype);
  (*env)->ReleaseStringUTFChars (env, jdevice, device);
  (*env)->ReleaseStringUTFChars (env, jjournal, journal);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1mke2fs_1JL  (JNIEnv *env, jobject obj, jlong jg, jstring jfstype, jint jblocksize, jstring jdevice, jstring jlabel)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *fstype;
  int blocksize;
  const char *device;
  const char *label;

  fstype = (*env)->GetStringUTFChars (env, jfstype, NULL);
  blocksize = jblocksize;
  device = (*env)->GetStringUTFChars (env, jdevice, NULL);
  label = (*env)->GetStringUTFChars (env, jlabel, NULL);

  r = guestfs_mke2fs_JL (g, fstype, blocksize, device, label);

  (*env)->ReleaseStringUTFChars (env, jfstype, fstype);
  (*env)->ReleaseStringUTFChars (env, jdevice, device);
  (*env)->ReleaseStringUTFChars (env, jlabel, label);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1mke2fs_1JU  (JNIEnv *env, jobject obj, jlong jg, jstring jfstype, jint jblocksize, jstring jdevice, jstring juuid)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *fstype;
  int blocksize;
  const char *device;
  const char *uuid;

  fstype = (*env)->GetStringUTFChars (env, jfstype, NULL);
  blocksize = jblocksize;
  device = (*env)->GetStringUTFChars (env, jdevice, NULL);
  uuid = (*env)->GetStringUTFChars (env, juuid, NULL);

  r = guestfs_mke2fs_JU (g, fstype, blocksize, device, uuid);

  (*env)->ReleaseStringUTFChars (env, jfstype, fstype);
  (*env)->ReleaseStringUTFChars (env, jdevice, device);
  (*env)->ReleaseStringUTFChars (env, juuid, uuid);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1mke2journal  (JNIEnv *env, jobject obj, jlong jg, jint jblocksize, jstring jdevice)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  int blocksize;
  const char *device;

  blocksize = jblocksize;
  device = (*env)->GetStringUTFChars (env, jdevice, NULL);

  r = guestfs_mke2journal (g, blocksize, device);

  (*env)->ReleaseStringUTFChars (env, jdevice, device);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1mke2journal_1L  (JNIEnv *env, jobject obj, jlong jg, jint jblocksize, jstring jlabel, jstring jdevice)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  int blocksize;
  const char *label;
  const char *device;

  blocksize = jblocksize;
  label = (*env)->GetStringUTFChars (env, jlabel, NULL);
  device = (*env)->GetStringUTFChars (env, jdevice, NULL);

  r = guestfs_mke2journal_L (g, blocksize, label, device);

  (*env)->ReleaseStringUTFChars (env, jlabel, label);
  (*env)->ReleaseStringUTFChars (env, jdevice, device);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1mke2journal_1U  (JNIEnv *env, jobject obj, jlong jg, jint jblocksize, jstring juuid, jstring jdevice)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  int blocksize;
  const char *uuid;
  const char *device;

  blocksize = jblocksize;
  uuid = (*env)->GetStringUTFChars (env, juuid, NULL);
  device = (*env)->GetStringUTFChars (env, jdevice, NULL);

  r = guestfs_mke2journal_U (g, blocksize, uuid, device);

  (*env)->ReleaseStringUTFChars (env, juuid, uuid);
  (*env)->ReleaseStringUTFChars (env, jdevice, device);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1mkfifo  (JNIEnv *env, jobject obj, jlong jg, jint jmode, jstring jpath)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  int mode;
  const char *path;

  mode = jmode;
  path = (*env)->GetStringUTFChars (env, jpath, NULL);

  r = guestfs_mkfifo (g, mode, path);

  (*env)->ReleaseStringUTFChars (env, jpath, path);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1mkfs  (JNIEnv *env, jobject obj, jlong jg, jstring jfstype, jstring jdevice, jlong joptargs_bitmask, jint jblocksize, jstring jfeatures, jint jinode, jint jsectorsize)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *fstype;
  const char *device;
  struct guestfs_mkfs_opts_argv optargs_s;
  const struct guestfs_mkfs_opts_argv *optargs = &optargs_s;

  fstype = (*env)->GetStringUTFChars (env, jfstype, NULL);
  device = (*env)->GetStringUTFChars (env, jdevice, NULL);

  optargs_s.blocksize = jblocksize;
  optargs_s.features = (*env)->GetStringUTFChars (env, jfeatures, NULL);
  optargs_s.inode = jinode;
  optargs_s.sectorsize = jsectorsize;
  optargs_s.bitmask = joptargs_bitmask;

  r = guestfs_mkfs_opts_argv (g, fstype, device, optargs);

  (*env)->ReleaseStringUTFChars (env, jfstype, fstype);
  (*env)->ReleaseStringUTFChars (env, jdevice, device);
  (*env)->ReleaseStringUTFChars (env, jfeatures, optargs_s.features);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1mkfs_1b  (JNIEnv *env, jobject obj, jlong jg, jstring jfstype, jint jblocksize, jstring jdevice)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *fstype;
  int blocksize;
  const char *device;

  fstype = (*env)->GetStringUTFChars (env, jfstype, NULL);
  blocksize = jblocksize;
  device = (*env)->GetStringUTFChars (env, jdevice, NULL);

  r = guestfs_mkfs_b (g, fstype, blocksize, device);

  (*env)->ReleaseStringUTFChars (env, jfstype, fstype);
  (*env)->ReleaseStringUTFChars (env, jdevice, device);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1mkfs_1btrfs  (JNIEnv *env, jobject obj, jlong jg, jobjectArray jdevices, jlong joptargs_bitmask, jlong jallocstart, jlong jbytecount, jstring jdatatype, jint jleafsize, jstring jlabel, jstring jmetadata, jint jnodesize, jint jsectorsize)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  size_t devices_len;
  char **devices;
  struct guestfs_mkfs_btrfs_argv optargs_s;
  const struct guestfs_mkfs_btrfs_argv *optargs = &optargs_s;
  size_t i;

  devices_len = (*env)->GetArrayLength (env, jdevices);
  devices = guestfs___safe_malloc (g, sizeof (char *) * (devices_len+1));
  for (i = 0; i < devices_len; ++i) {
    jobject o = (*env)->GetObjectArrayElement (env, jdevices, i);
    devices[i] = (char *) (*env)->GetStringUTFChars (env, o, NULL);
  }
  devices[devices_len] = NULL;

  optargs_s.allocstart = jallocstart;
  optargs_s.bytecount = jbytecount;
  optargs_s.datatype = (*env)->GetStringUTFChars (env, jdatatype, NULL);
  optargs_s.leafsize = jleafsize;
  optargs_s.label = (*env)->GetStringUTFChars (env, jlabel, NULL);
  optargs_s.metadata = (*env)->GetStringUTFChars (env, jmetadata, NULL);
  optargs_s.nodesize = jnodesize;
  optargs_s.sectorsize = jsectorsize;
  optargs_s.bitmask = joptargs_bitmask;

  r = guestfs_mkfs_btrfs_argv (g, devices, optargs);

  for (i = 0; i < devices_len; ++i) {
    jobject o = (*env)->GetObjectArrayElement (env, jdevices, i);
    (*env)->ReleaseStringUTFChars (env, o, devices[i]);
  }
  free (devices);
  (*env)->ReleaseStringUTFChars (env, jdatatype, optargs_s.datatype);
  (*env)->ReleaseStringUTFChars (env, jlabel, optargs_s.label);
  (*env)->ReleaseStringUTFChars (env, jmetadata, optargs_s.metadata);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1mklost_1and_1found  (JNIEnv *env, jobject obj, jlong jg, jstring jmountpoint)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *mountpoint;

  mountpoint = (*env)->GetStringUTFChars (env, jmountpoint, NULL);

  r = guestfs_mklost_and_found (g, mountpoint);

  (*env)->ReleaseStringUTFChars (env, jmountpoint, mountpoint);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1mkmountpoint  (JNIEnv *env, jobject obj, jlong jg, jstring jexemptpath)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *exemptpath;

  exemptpath = (*env)->GetStringUTFChars (env, jexemptpath, NULL);

  r = guestfs_mkmountpoint (g, exemptpath);

  (*env)->ReleaseStringUTFChars (env, jexemptpath, exemptpath);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1mknod  (JNIEnv *env, jobject obj, jlong jg, jint jmode, jint jdevmajor, jint jdevminor, jstring jpath)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  int mode;
  int devmajor;
  int devminor;
  const char *path;

  mode = jmode;
  devmajor = jdevmajor;
  devminor = jdevminor;
  path = (*env)->GetStringUTFChars (env, jpath, NULL);

  r = guestfs_mknod (g, mode, devmajor, devminor, path);

  (*env)->ReleaseStringUTFChars (env, jpath, path);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1mknod_1b  (JNIEnv *env, jobject obj, jlong jg, jint jmode, jint jdevmajor, jint jdevminor, jstring jpath)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  int mode;
  int devmajor;
  int devminor;
  const char *path;

  mode = jmode;
  devmajor = jdevmajor;
  devminor = jdevminor;
  path = (*env)->GetStringUTFChars (env, jpath, NULL);

  r = guestfs_mknod_b (g, mode, devmajor, devminor, path);

  (*env)->ReleaseStringUTFChars (env, jpath, path);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1mknod_1c  (JNIEnv *env, jobject obj, jlong jg, jint jmode, jint jdevmajor, jint jdevminor, jstring jpath)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  int mode;
  int devmajor;
  int devminor;
  const char *path;

  mode = jmode;
  devmajor = jdevmajor;
  devminor = jdevminor;
  path = (*env)->GetStringUTFChars (env, jpath, NULL);

  r = guestfs_mknod_c (g, mode, devmajor, devminor, path);

  (*env)->ReleaseStringUTFChars (env, jpath, path);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1mkswap  (JNIEnv *env, jobject obj, jlong jg, jstring jdevice, jlong joptargs_bitmask, jstring jlabel, jstring juuid)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *device;
  struct guestfs_mkswap_opts_argv optargs_s;
  const struct guestfs_mkswap_opts_argv *optargs = &optargs_s;

  device = (*env)->GetStringUTFChars (env, jdevice, NULL);

  optargs_s.label = (*env)->GetStringUTFChars (env, jlabel, NULL);
  optargs_s.uuid = (*env)->GetStringUTFChars (env, juuid, NULL);
  optargs_s.bitmask = joptargs_bitmask;

  r = guestfs_mkswap_opts_argv (g, device, optargs);

  (*env)->ReleaseStringUTFChars (env, jdevice, device);
  (*env)->ReleaseStringUTFChars (env, jlabel, optargs_s.label);
  (*env)->ReleaseStringUTFChars (env, juuid, optargs_s.uuid);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1mkswap_1L  (JNIEnv *env, jobject obj, jlong jg, jstring jlabel, jstring jdevice)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *label;
  const char *device;

  label = (*env)->GetStringUTFChars (env, jlabel, NULL);
  device = (*env)->GetStringUTFChars (env, jdevice, NULL);

  r = guestfs_mkswap_L (g, label, device);

  (*env)->ReleaseStringUTFChars (env, jlabel, label);
  (*env)->ReleaseStringUTFChars (env, jdevice, device);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1mkswap_1U  (JNIEnv *env, jobject obj, jlong jg, jstring juuid, jstring jdevice)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *uuid;
  const char *device;

  uuid = (*env)->GetStringUTFChars (env, juuid, NULL);
  device = (*env)->GetStringUTFChars (env, jdevice, NULL);

  r = guestfs_mkswap_U (g, uuid, device);

  (*env)->ReleaseStringUTFChars (env, juuid, uuid);
  (*env)->ReleaseStringUTFChars (env, jdevice, device);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1mkswap_1file  (JNIEnv *env, jobject obj, jlong jg, jstring jpath)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *path;

  path = (*env)->GetStringUTFChars (env, jpath, NULL);

  r = guestfs_mkswap_file (g, path);

  (*env)->ReleaseStringUTFChars (env, jpath, path);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT jstring JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1mktemp  (JNIEnv *env, jobject obj, jlong jg, jstring jtmpl, jlong joptargs_bitmask, jstring jsuffix)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  jstring jr;
  char *r;
  const char *tmpl;
  struct guestfs_mktemp_argv optargs_s;
  const struct guestfs_mktemp_argv *optargs = &optargs_s;

  tmpl = (*env)->GetStringUTFChars (env, jtmpl, NULL);

  optargs_s.suffix = (*env)->GetStringUTFChars (env, jsuffix, NULL);
  optargs_s.bitmask = joptargs_bitmask;

  r = guestfs_mktemp_argv (g, tmpl, optargs);

  (*env)->ReleaseStringUTFChars (env, jtmpl, tmpl);
  (*env)->ReleaseStringUTFChars (env, jsuffix, optargs_s.suffix);

  if (r == NULL) {
    throw_exception (env, guestfs_last_error (g));
    return NULL;
  }
  jr = (*env)->NewStringUTF (env, r);
  free (r);
  return jr;
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1modprobe  (JNIEnv *env, jobject obj, jlong jg, jstring jmodulename)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *modulename;

  modulename = (*env)->GetStringUTFChars (env, jmodulename, NULL);

  r = guestfs_modprobe (g, modulename);

  (*env)->ReleaseStringUTFChars (env, jmodulename, modulename);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1mount  (JNIEnv *env, jobject obj, jlong jg, jstring jmountable, jstring jmountpoint)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *mountable;
  const char *mountpoint;

  mountable = (*env)->GetStringUTFChars (env, jmountable, NULL);
  mountpoint = (*env)->GetStringUTFChars (env, jmountpoint, NULL);

  r = guestfs_mount (g, mountable, mountpoint);

  (*env)->ReleaseStringUTFChars (env, jmountable, mountable);
  (*env)->ReleaseStringUTFChars (env, jmountpoint, mountpoint);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1mount_19p  (JNIEnv *env, jobject obj, jlong jg, jstring jmounttag, jstring jmountpoint, jlong joptargs_bitmask, jstring joptions)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *mounttag;
  const char *mountpoint;
  struct guestfs_mount_9p_argv optargs_s;
  const struct guestfs_mount_9p_argv *optargs = &optargs_s;

  mounttag = (*env)->GetStringUTFChars (env, jmounttag, NULL);
  mountpoint = (*env)->GetStringUTFChars (env, jmountpoint, NULL);

  optargs_s.options = (*env)->GetStringUTFChars (env, joptions, NULL);
  optargs_s.bitmask = joptargs_bitmask;

  r = guestfs_mount_9p_argv (g, mounttag, mountpoint, optargs);

  (*env)->ReleaseStringUTFChars (env, jmounttag, mounttag);
  (*env)->ReleaseStringUTFChars (env, jmountpoint, mountpoint);
  (*env)->ReleaseStringUTFChars (env, joptions, optargs_s.options);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1mount_1local  (JNIEnv *env, jobject obj, jlong jg, jstring jlocalmountpoint, jlong joptargs_bitmask, jboolean jreadonly, jstring joptions, jint jcachetimeout, jboolean jdebugcalls)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *localmountpoint;
  struct guestfs_mount_local_argv optargs_s;
  const struct guestfs_mount_local_argv *optargs = &optargs_s;

  localmountpoint = (*env)->GetStringUTFChars (env, jlocalmountpoint, NULL);

  optargs_s.readonly = jreadonly;
  optargs_s.options = (*env)->GetStringUTFChars (env, joptions, NULL);
  optargs_s.cachetimeout = jcachetimeout;
  optargs_s.debugcalls = jdebugcalls;
  optargs_s.bitmask = joptargs_bitmask;

  r = guestfs_mount_local_argv (g, localmountpoint, optargs);

  (*env)->ReleaseStringUTFChars (env, jlocalmountpoint, localmountpoint);
  (*env)->ReleaseStringUTFChars (env, joptions, optargs_s.options);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1mount_1local_1run  (JNIEnv *env, jobject obj, jlong jg)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;


  r = guestfs_mount_local_run (g);


  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1mount_1loop  (JNIEnv *env, jobject obj, jlong jg, jstring jfile, jstring jmountpoint)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *file;
  const char *mountpoint;

  file = (*env)->GetStringUTFChars (env, jfile, NULL);
  mountpoint = (*env)->GetStringUTFChars (env, jmountpoint, NULL);

  r = guestfs_mount_loop (g, file, mountpoint);

  (*env)->ReleaseStringUTFChars (env, jfile, file);
  (*env)->ReleaseStringUTFChars (env, jmountpoint, mountpoint);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1mount_1options  (JNIEnv *env, jobject obj, jlong jg, jstring joptions, jstring jmountable, jstring jmountpoint)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *options;
  const char *mountable;
  const char *mountpoint;

  options = (*env)->GetStringUTFChars (env, joptions, NULL);
  mountable = (*env)->GetStringUTFChars (env, jmountable, NULL);
  mountpoint = (*env)->GetStringUTFChars (env, jmountpoint, NULL);

  r = guestfs_mount_options (g, options, mountable, mountpoint);

  (*env)->ReleaseStringUTFChars (env, joptions, options);
  (*env)->ReleaseStringUTFChars (env, jmountable, mountable);
  (*env)->ReleaseStringUTFChars (env, jmountpoint, mountpoint);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1mount_1ro  (JNIEnv *env, jobject obj, jlong jg, jstring jmountable, jstring jmountpoint)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *mountable;
  const char *mountpoint;

  mountable = (*env)->GetStringUTFChars (env, jmountable, NULL);
  mountpoint = (*env)->GetStringUTFChars (env, jmountpoint, NULL);

  r = guestfs_mount_ro (g, mountable, mountpoint);

  (*env)->ReleaseStringUTFChars (env, jmountable, mountable);
  (*env)->ReleaseStringUTFChars (env, jmountpoint, mountpoint);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1mount_1vfs  (JNIEnv *env, jobject obj, jlong jg, jstring joptions, jstring jvfstype, jstring jmountable, jstring jmountpoint)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *options;
  const char *vfstype;
  const char *mountable;
  const char *mountpoint;

  options = (*env)->GetStringUTFChars (env, joptions, NULL);
  vfstype = (*env)->GetStringUTFChars (env, jvfstype, NULL);
  mountable = (*env)->GetStringUTFChars (env, jmountable, NULL);
  mountpoint = (*env)->GetStringUTFChars (env, jmountpoint, NULL);

  r = guestfs_mount_vfs (g, options, vfstype, mountable, mountpoint);

  (*env)->ReleaseStringUTFChars (env, joptions, options);
  (*env)->ReleaseStringUTFChars (env, jvfstype, vfstype);
  (*env)->ReleaseStringUTFChars (env, jmountable, mountable);
  (*env)->ReleaseStringUTFChars (env, jmountpoint, mountpoint);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT jobject JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1mountpoints  (JNIEnv *env, jobject obj, jlong jg)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  jobjectArray jr;
  size_t r_len;
  jclass cl;
  jstring jstr;
  char **r;
  size_t i;


  r = guestfs_mountpoints (g);


  if (r == NULL) {
    throw_exception (env, guestfs_last_error (g));
    return NULL;
  }
  for (r_len = 0; r[r_len] != NULL; ++r_len) ;
  cl = (*env)->FindClass (env, "java/lang/String");
  jstr = (*env)->NewStringUTF (env, "");
  jr = (*env)->NewObjectArray (env, r_len, cl, jstr);
  for (i = 0; i < r_len; ++i) {
    jstr = (*env)->NewStringUTF (env, r[i]);
    (*env)->SetObjectArrayElement (env, jr, i, jstr);
    free (r[i]);
  }
  free (r);
  return jr;
}

JNIEXPORT jobjectArray JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1mounts  (JNIEnv *env, jobject obj, jlong jg)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  jobjectArray jr;
  size_t r_len;
  jclass cl;
  jstring jstr;
  char **r;
  size_t i;


  r = guestfs_mounts (g);


  if (r == NULL) {
    throw_exception (env, guestfs_last_error (g));
    return NULL;
  }
  for (r_len = 0; r[r_len] != NULL; ++r_len) ;
  cl = (*env)->FindClass (env, "java/lang/String");
  jstr = (*env)->NewStringUTF (env, "");
  jr = (*env)->NewObjectArray (env, r_len, cl, jstr);
  for (i = 0; i < r_len; ++i) {
    jstr = (*env)->NewStringUTF (env, r[i]);
    (*env)->SetObjectArrayElement (env, jr, i, jstr);
    free (r[i]);
  }
  free (r);
  return jr;
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1mv  (JNIEnv *env, jobject obj, jlong jg, jstring jsrc, jstring jdest)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *src;
  const char *dest;

  src = (*env)->GetStringUTFChars (env, jsrc, NULL);
  dest = (*env)->GetStringUTFChars (env, jdest, NULL);

  r = guestfs_mv (g, src, dest);

  (*env)->ReleaseStringUTFChars (env, jsrc, src);
  (*env)->ReleaseStringUTFChars (env, jdest, dest);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT jint JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1nr_1devices  (JNIEnv *env, jobject obj, jlong jg)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;


  r = guestfs_nr_devices (g);


  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return -1;
  }
  return (jint) r;
}

JNIEXPORT jint JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1ntfs_13g_1probe  (JNIEnv *env, jobject obj, jlong jg, jboolean jrw, jstring jdevice)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  int rw;
  const char *device;

  rw = jrw;
  device = (*env)->GetStringUTFChars (env, jdevice, NULL);

  r = guestfs_ntfs_3g_probe (g, rw, device);

  (*env)->ReleaseStringUTFChars (env, jdevice, device);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return -1;
  }
  return (jint) r;
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1ntfsclone_1in  (JNIEnv *env, jobject obj, jlong jg, jstring jbackupfile, jstring jdevice)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *backupfile;
  const char *device;

  backupfile = (*env)->GetStringUTFChars (env, jbackupfile, NULL);
  device = (*env)->GetStringUTFChars (env, jdevice, NULL);

  r = guestfs_ntfsclone_in (g, backupfile, device);

  (*env)->ReleaseStringUTFChars (env, jbackupfile, backupfile);
  (*env)->ReleaseStringUTFChars (env, jdevice, device);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1ntfsclone_1out  (JNIEnv *env, jobject obj, jlong jg, jstring jdevice, jstring jbackupfile, jlong joptargs_bitmask, jboolean jmetadataonly, jboolean jrescue, jboolean jignorefscheck, jboolean jpreservetimestamps, jboolean jforce)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *device;
  const char *backupfile;
  struct guestfs_ntfsclone_out_argv optargs_s;
  const struct guestfs_ntfsclone_out_argv *optargs = &optargs_s;

  device = (*env)->GetStringUTFChars (env, jdevice, NULL);
  backupfile = (*env)->GetStringUTFChars (env, jbackupfile, NULL);

  optargs_s.metadataonly = jmetadataonly;
  optargs_s.rescue = jrescue;
  optargs_s.ignorefscheck = jignorefscheck;
  optargs_s.preservetimestamps = jpreservetimestamps;
  optargs_s.force = jforce;
  optargs_s.bitmask = joptargs_bitmask;

  r = guestfs_ntfsclone_out_argv (g, device, backupfile, optargs);

  (*env)->ReleaseStringUTFChars (env, jdevice, device);
  (*env)->ReleaseStringUTFChars (env, jbackupfile, backupfile);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1ntfsfix  (JNIEnv *env, jobject obj, jlong jg, jstring jdevice, jlong joptargs_bitmask, jboolean jclearbadsectors)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *device;
  struct guestfs_ntfsfix_argv optargs_s;
  const struct guestfs_ntfsfix_argv *optargs = &optargs_s;

  device = (*env)->GetStringUTFChars (env, jdevice, NULL);

  optargs_s.clearbadsectors = jclearbadsectors;
  optargs_s.bitmask = joptargs_bitmask;

  r = guestfs_ntfsfix_argv (g, device, optargs);

  (*env)->ReleaseStringUTFChars (env, jdevice, device);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1ntfsresize  (JNIEnv *env, jobject obj, jlong jg, jstring jdevice, jlong joptargs_bitmask, jlong jsize, jboolean jforce)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *device;
  struct guestfs_ntfsresize_opts_argv optargs_s;
  const struct guestfs_ntfsresize_opts_argv *optargs = &optargs_s;

  device = (*env)->GetStringUTFChars (env, jdevice, NULL);

  optargs_s.size = jsize;
  optargs_s.force = jforce;
  optargs_s.bitmask = joptargs_bitmask;

  r = guestfs_ntfsresize_opts_argv (g, device, optargs);

  (*env)->ReleaseStringUTFChars (env, jdevice, device);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1ntfsresize_1size  (JNIEnv *env, jobject obj, jlong jg, jstring jdevice, jlong jsize)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *device;
  int64_t size;

  device = (*env)->GetStringUTFChars (env, jdevice, NULL);
  size = jsize;

  r = guestfs_ntfsresize_size (g, device, size);

  (*env)->ReleaseStringUTFChars (env, jdevice, device);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1parse_1environment  (JNIEnv *env, jobject obj, jlong jg)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;


  r = guestfs_parse_environment (g);


  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1parse_1environment_1list  (JNIEnv *env, jobject obj, jlong jg, jobjectArray jenvironment)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  size_t environment_len;
  char **environment;
  size_t i;

  environment_len = (*env)->GetArrayLength (env, jenvironment);
  environment = guestfs___safe_malloc (g, sizeof (char *) * (environment_len+1));
  for (i = 0; i < environment_len; ++i) {
    jobject o = (*env)->GetObjectArrayElement (env, jenvironment, i);
    environment[i] = (char *) (*env)->GetStringUTFChars (env, o, NULL);
  }
  environment[environment_len] = NULL;

  r = guestfs_parse_environment_list (g, environment);

  for (i = 0; i < environment_len; ++i) {
    jobject o = (*env)->GetObjectArrayElement (env, jenvironment, i);
    (*env)->ReleaseStringUTFChars (env, o, environment[i]);
  }
  free (environment);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1part_1add  (JNIEnv *env, jobject obj, jlong jg, jstring jdevice, jstring jprlogex, jlong jstartsect, jlong jendsect)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *device;
  const char *prlogex;
  int64_t startsect;
  int64_t endsect;

  device = (*env)->GetStringUTFChars (env, jdevice, NULL);
  prlogex = (*env)->GetStringUTFChars (env, jprlogex, NULL);
  startsect = jstartsect;
  endsect = jendsect;

  r = guestfs_part_add (g, device, prlogex, startsect, endsect);

  (*env)->ReleaseStringUTFChars (env, jdevice, device);
  (*env)->ReleaseStringUTFChars (env, jprlogex, prlogex);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1part_1del  (JNIEnv *env, jobject obj, jlong jg, jstring jdevice, jint jpartnum)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *device;
  int partnum;

  device = (*env)->GetStringUTFChars (env, jdevice, NULL);
  partnum = jpartnum;

  r = guestfs_part_del (g, device, partnum);

  (*env)->ReleaseStringUTFChars (env, jdevice, device);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1part_1disk  (JNIEnv *env, jobject obj, jlong jg, jstring jdevice, jstring jparttype)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *device;
  const char *parttype;

  device = (*env)->GetStringUTFChars (env, jdevice, NULL);
  parttype = (*env)->GetStringUTFChars (env, jparttype, NULL);

  r = guestfs_part_disk (g, device, parttype);

  (*env)->ReleaseStringUTFChars (env, jdevice, device);
  (*env)->ReleaseStringUTFChars (env, jparttype, parttype);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT jboolean JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1part_1get_1bootable  (JNIEnv *env, jobject obj, jlong jg, jstring jdevice, jint jpartnum)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *device;
  int partnum;

  device = (*env)->GetStringUTFChars (env, jdevice, NULL);
  partnum = jpartnum;

  r = guestfs_part_get_bootable (g, device, partnum);

  (*env)->ReleaseStringUTFChars (env, jdevice, device);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return -1;
  }
  return (jboolean) r;
}

JNIEXPORT jstring JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1part_1get_1gpt_1type  (JNIEnv *env, jobject obj, jlong jg, jstring jdevice, jint jpartnum)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  jstring jr;
  char *r;
  const char *device;
  int partnum;

  device = (*env)->GetStringUTFChars (env, jdevice, NULL);
  partnum = jpartnum;

  r = guestfs_part_get_gpt_type (g, device, partnum);

  (*env)->ReleaseStringUTFChars (env, jdevice, device);

  if (r == NULL) {
    throw_exception (env, guestfs_last_error (g));
    return NULL;
  }
  jr = (*env)->NewStringUTF (env, r);
  free (r);
  return jr;
}

JNIEXPORT jint JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1part_1get_1mbr_1id  (JNIEnv *env, jobject obj, jlong jg, jstring jdevice, jint jpartnum)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *device;
  int partnum;

  device = (*env)->GetStringUTFChars (env, jdevice, NULL);
  partnum = jpartnum;

  r = guestfs_part_get_mbr_id (g, device, partnum);

  (*env)->ReleaseStringUTFChars (env, jdevice, device);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return -1;
  }
  return (jint) r;
}

JNIEXPORT jstring JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1part_1get_1name  (JNIEnv *env, jobject obj, jlong jg, jstring jdevice, jint jpartnum)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  jstring jr;
  char *r;
  const char *device;
  int partnum;

  device = (*env)->GetStringUTFChars (env, jdevice, NULL);
  partnum = jpartnum;

  r = guestfs_part_get_name (g, device, partnum);

  (*env)->ReleaseStringUTFChars (env, jdevice, device);

  if (r == NULL) {
    throw_exception (env, guestfs_last_error (g));
    return NULL;
  }
  jr = (*env)->NewStringUTF (env, r);
  free (r);
  return jr;
}

JNIEXPORT jstring JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1part_1get_1parttype  (JNIEnv *env, jobject obj, jlong jg, jstring jdevice)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  jstring jr;
  char *r;
  const char *device;

  device = (*env)->GetStringUTFChars (env, jdevice, NULL);

  r = guestfs_part_get_parttype (g, device);

  (*env)->ReleaseStringUTFChars (env, jdevice, device);

  if (r == NULL) {
    throw_exception (env, guestfs_last_error (g));
    return NULL;
  }
  jr = (*env)->NewStringUTF (env, r);
  free (r);
  return jr;
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1part_1init  (JNIEnv *env, jobject obj, jlong jg, jstring jdevice, jstring jparttype)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *device;
  const char *parttype;

  device = (*env)->GetStringUTFChars (env, jdevice, NULL);
  parttype = (*env)->GetStringUTFChars (env, jparttype, NULL);

  r = guestfs_part_init (g, device, parttype);

  (*env)->ReleaseStringUTFChars (env, jdevice, device);
  (*env)->ReleaseStringUTFChars (env, jparttype, parttype);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT jobjectArray JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1part_1list  (JNIEnv *env, jobject obj, jlong jg, jstring jdevice)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  jobjectArray jr;
  jclass cl;
  jfieldID fl;
  jobject jfl;
  struct guestfs_partition_list *r;
  const char *device;
  size_t i;

  device = (*env)->GetStringUTFChars (env, jdevice, NULL);

  r = guestfs_part_list (g, device);

  (*env)->ReleaseStringUTFChars (env, jdevice, device);

  if (r == NULL) {
    throw_exception (env, guestfs_last_error (g));
    return NULL;
  }
  cl = (*env)->FindClass (env, "com/redhat/et/libguestfs/Partition");
  jr = (*env)->NewObjectArray (env, r->len, cl, NULL);

  for (i = 0; i < r->len; ++i) {
    jfl = (*env)->AllocObject (env, cl);

    fl = (*env)->GetFieldID (env, cl, "part_num",
                             "I");
    (*env)->SetIntField (env, jfl, fl, r->val[i].part_num);
    fl = (*env)->GetFieldID (env, cl, "part_start",
                             "J");
    (*env)->SetLongField (env, jfl, fl, r->val[i].part_start);
    fl = (*env)->GetFieldID (env, cl, "part_end",
                             "J");
    (*env)->SetLongField (env, jfl, fl, r->val[i].part_end);
    fl = (*env)->GetFieldID (env, cl, "part_size",
                             "J");
    (*env)->SetLongField (env, jfl, fl, r->val[i].part_size);

    (*env)->SetObjectArrayElement (env, jr, i, jfl);
  }

  guestfs_free_partition_list (r);
  return jr;
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1part_1set_1bootable  (JNIEnv *env, jobject obj, jlong jg, jstring jdevice, jint jpartnum, jboolean jbootable)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *device;
  int partnum;
  int bootable;

  device = (*env)->GetStringUTFChars (env, jdevice, NULL);
  partnum = jpartnum;
  bootable = jbootable;

  r = guestfs_part_set_bootable (g, device, partnum, bootable);

  (*env)->ReleaseStringUTFChars (env, jdevice, device);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1part_1set_1gpt_1type  (JNIEnv *env, jobject obj, jlong jg, jstring jdevice, jint jpartnum, jstring jguid)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *device;
  int partnum;
  const char *guid;

  device = (*env)->GetStringUTFChars (env, jdevice, NULL);
  partnum = jpartnum;
  guid = (*env)->GetStringUTFChars (env, jguid, NULL);

  r = guestfs_part_set_gpt_type (g, device, partnum, guid);

  (*env)->ReleaseStringUTFChars (env, jdevice, device);
  (*env)->ReleaseStringUTFChars (env, jguid, guid);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1part_1set_1mbr_1id  (JNIEnv *env, jobject obj, jlong jg, jstring jdevice, jint jpartnum, jint jidbyte)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *device;
  int partnum;
  int idbyte;

  device = (*env)->GetStringUTFChars (env, jdevice, NULL);
  partnum = jpartnum;
  idbyte = jidbyte;

  r = guestfs_part_set_mbr_id (g, device, partnum, idbyte);

  (*env)->ReleaseStringUTFChars (env, jdevice, device);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1part_1set_1name  (JNIEnv *env, jobject obj, jlong jg, jstring jdevice, jint jpartnum, jstring jname)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *device;
  int partnum;
  const char *name;

  device = (*env)->GetStringUTFChars (env, jdevice, NULL);
  partnum = jpartnum;
  name = (*env)->GetStringUTFChars (env, jname, NULL);

  r = guestfs_part_set_name (g, device, partnum, name);

  (*env)->ReleaseStringUTFChars (env, jdevice, device);
  (*env)->ReleaseStringUTFChars (env, jname, name);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT jstring JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1part_1to_1dev  (JNIEnv *env, jobject obj, jlong jg, jstring jpartition)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  jstring jr;
  char *r;
  const char *partition;

  partition = (*env)->GetStringUTFChars (env, jpartition, NULL);

  r = guestfs_part_to_dev (g, partition);

  (*env)->ReleaseStringUTFChars (env, jpartition, partition);

  if (r == NULL) {
    throw_exception (env, guestfs_last_error (g));
    return NULL;
  }
  jr = (*env)->NewStringUTF (env, r);
  free (r);
  return jr;
}

JNIEXPORT jint JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1part_1to_1partnum  (JNIEnv *env, jobject obj, jlong jg, jstring jpartition)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *partition;

  partition = (*env)->GetStringUTFChars (env, jpartition, NULL);

  r = guestfs_part_to_partnum (g, partition);

  (*env)->ReleaseStringUTFChars (env, jpartition, partition);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return -1;
  }
  return (jint) r;
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1ping_1daemon  (JNIEnv *env, jobject obj, jlong jg)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;


  r = guestfs_ping_daemon (g);


  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT jstring JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1pread  (JNIEnv *env, jobject obj, jlong jg, jstring jpath, jint jcount, jlong joffset)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  jstring jr;
  char *r;
  size_t size;
  const char *path;
  int count;
  int64_t offset;

  path = (*env)->GetStringUTFChars (env, jpath, NULL);
  count = jcount;
  offset = joffset;

  r = guestfs_pread (g, path, count, offset, &size);

  (*env)->ReleaseStringUTFChars (env, jpath, path);

  if (r == NULL) {
    throw_exception (env, guestfs_last_error (g));
    return NULL;
  }
  jr = (*env)->NewStringUTF (env, r); // XXX size
  free (r);
  return jr;
}

JNIEXPORT jstring JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1pread_1device  (JNIEnv *env, jobject obj, jlong jg, jstring jdevice, jint jcount, jlong joffset)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  jstring jr;
  char *r;
  size_t size;
  const char *device;
  int count;
  int64_t offset;

  device = (*env)->GetStringUTFChars (env, jdevice, NULL);
  count = jcount;
  offset = joffset;

  r = guestfs_pread_device (g, device, count, offset, &size);

  (*env)->ReleaseStringUTFChars (env, jdevice, device);

  if (r == NULL) {
    throw_exception (env, guestfs_last_error (g));
    return NULL;
  }
  jr = (*env)->NewStringUTF (env, r); // XXX size
  free (r);
  return jr;
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1pvchange_1uuid  (JNIEnv *env, jobject obj, jlong jg, jstring jdevice)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *device;

  device = (*env)->GetStringUTFChars (env, jdevice, NULL);

  r = guestfs_pvchange_uuid (g, device);

  (*env)->ReleaseStringUTFChars (env, jdevice, device);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1pvchange_1uuid_1all  (JNIEnv *env, jobject obj, jlong jg)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;


  r = guestfs_pvchange_uuid_all (g);


  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1pvcreate  (JNIEnv *env, jobject obj, jlong jg, jstring jdevice)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *device;

  device = (*env)->GetStringUTFChars (env, jdevice, NULL);

  r = guestfs_pvcreate (g, device);

  (*env)->ReleaseStringUTFChars (env, jdevice, device);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1pvremove  (JNIEnv *env, jobject obj, jlong jg, jstring jdevice)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *device;

  device = (*env)->GetStringUTFChars (env, jdevice, NULL);

  r = guestfs_pvremove (g, device);

  (*env)->ReleaseStringUTFChars (env, jdevice, device);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1pvresize  (JNIEnv *env, jobject obj, jlong jg, jstring jdevice)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *device;

  device = (*env)->GetStringUTFChars (env, jdevice, NULL);

  r = guestfs_pvresize (g, device);

  (*env)->ReleaseStringUTFChars (env, jdevice, device);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1pvresize_1size  (JNIEnv *env, jobject obj, jlong jg, jstring jdevice, jlong jsize)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *device;
  int64_t size;

  device = (*env)->GetStringUTFChars (env, jdevice, NULL);
  size = jsize;

  r = guestfs_pvresize_size (g, device, size);

  (*env)->ReleaseStringUTFChars (env, jdevice, device);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT jobjectArray JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1pvs  (JNIEnv *env, jobject obj, jlong jg)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  jobjectArray jr;
  size_t r_len;
  jclass cl;
  jstring jstr;
  char **r;
  size_t i;


  r = guestfs_pvs (g);


  if (r == NULL) {
    throw_exception (env, guestfs_last_error (g));
    return NULL;
  }
  for (r_len = 0; r[r_len] != NULL; ++r_len) ;
  cl = (*env)->FindClass (env, "java/lang/String");
  jstr = (*env)->NewStringUTF (env, "");
  jr = (*env)->NewObjectArray (env, r_len, cl, jstr);
  for (i = 0; i < r_len; ++i) {
    jstr = (*env)->NewStringUTF (env, r[i]);
    (*env)->SetObjectArrayElement (env, jr, i, jstr);
    free (r[i]);
  }
  free (r);
  return jr;
}

JNIEXPORT jobjectArray JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1pvs_1full  (JNIEnv *env, jobject obj, jlong jg)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  jobjectArray jr;
  jclass cl;
  jfieldID fl;
  jobject jfl;
  struct guestfs_lvm_pv_list *r;
  size_t i;


  r = guestfs_pvs_full (g);


  if (r == NULL) {
    throw_exception (env, guestfs_last_error (g));
    return NULL;
  }
  cl = (*env)->FindClass (env, "com/redhat/et/libguestfs/PV");
  jr = (*env)->NewObjectArray (env, r->len, cl, NULL);

  for (i = 0; i < r->len; ++i) {
    jfl = (*env)->AllocObject (env, cl);

    fl = (*env)->GetFieldID (env, cl, "pv_name",
                             "Ljava/lang/String;");
    (*env)->SetObjectField (env, jfl, fl,
                            (*env)->NewStringUTF (env, r->val[i].pv_name));
    fl = (*env)->GetFieldID (env, cl, "pv_uuid",
                             "Ljava/lang/String;");
    {
      char s[33];
      memcpy (s, r->val[i].pv_uuid, 32);
      s[32] = 0;
      (*env)->SetObjectField (env, jfl, fl,
                              (*env)->NewStringUTF (env, s));
    }
    fl = (*env)->GetFieldID (env, cl, "pv_fmt",
                             "Ljava/lang/String;");
    (*env)->SetObjectField (env, jfl, fl,
                            (*env)->NewStringUTF (env, r->val[i].pv_fmt));
    fl = (*env)->GetFieldID (env, cl, "pv_size",
                             "J");
    (*env)->SetLongField (env, jfl, fl, r->val[i].pv_size);
    fl = (*env)->GetFieldID (env, cl, "dev_size",
                             "J");
    (*env)->SetLongField (env, jfl, fl, r->val[i].dev_size);
    fl = (*env)->GetFieldID (env, cl, "pv_free",
                             "J");
    (*env)->SetLongField (env, jfl, fl, r->val[i].pv_free);
    fl = (*env)->GetFieldID (env, cl, "pv_used",
                             "J");
    (*env)->SetLongField (env, jfl, fl, r->val[i].pv_used);
    fl = (*env)->GetFieldID (env, cl, "pv_attr",
                             "Ljava/lang/String;");
    (*env)->SetObjectField (env, jfl, fl,
                            (*env)->NewStringUTF (env, r->val[i].pv_attr));
    fl = (*env)->GetFieldID (env, cl, "pv_pe_count",
                             "J");
    (*env)->SetLongField (env, jfl, fl, r->val[i].pv_pe_count);
    fl = (*env)->GetFieldID (env, cl, "pv_pe_alloc_count",
                             "J");
    (*env)->SetLongField (env, jfl, fl, r->val[i].pv_pe_alloc_count);
    fl = (*env)->GetFieldID (env, cl, "pv_tags",
                             "Ljava/lang/String;");
    (*env)->SetObjectField (env, jfl, fl,
                            (*env)->NewStringUTF (env, r->val[i].pv_tags));
    fl = (*env)->GetFieldID (env, cl, "pe_start",
                             "J");
    (*env)->SetLongField (env, jfl, fl, r->val[i].pe_start);
    fl = (*env)->GetFieldID (env, cl, "pv_mda_count",
                             "J");
    (*env)->SetLongField (env, jfl, fl, r->val[i].pv_mda_count);
    fl = (*env)->GetFieldID (env, cl, "pv_mda_free",
                             "J");
    (*env)->SetLongField (env, jfl, fl, r->val[i].pv_mda_free);

    (*env)->SetObjectArrayElement (env, jr, i, jfl);
  }

  guestfs_free_lvm_pv_list (r);
  return jr;
}

JNIEXPORT jstring JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1pvuuid  (JNIEnv *env, jobject obj, jlong jg, jstring jdevice)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  jstring jr;
  char *r;
  const char *device;

  device = (*env)->GetStringUTFChars (env, jdevice, NULL);

  r = guestfs_pvuuid (g, device);

  (*env)->ReleaseStringUTFChars (env, jdevice, device);

  if (r == NULL) {
    throw_exception (env, guestfs_last_error (g));
    return NULL;
  }
  jr = (*env)->NewStringUTF (env, r);
  free (r);
  return jr;
}

JNIEXPORT jint JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1pwrite  (JNIEnv *env, jobject obj, jlong jg, jstring jpath, jbyteArray jcontent, jlong joffset)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *path;
  char *content;
  size_t content_size;
  int64_t offset;

  path = (*env)->GetStringUTFChars (env, jpath, NULL);
  content = (char *) (*env)->GetByteArrayElements (env, jcontent, NULL);
  content_size = (*env)->GetArrayLength (env, jcontent);
  offset = joffset;

  r = guestfs_pwrite (g, path, content, content_size, offset);

  (*env)->ReleaseStringUTFChars (env, jpath, path);
  (*env)->ReleaseByteArrayElements (env, jcontent, (jbyte *) content, 0);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return -1;
  }
  return (jint) r;
}

JNIEXPORT jint JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1pwrite_1device  (JNIEnv *env, jobject obj, jlong jg, jstring jdevice, jbyteArray jcontent, jlong joffset)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *device;
  char *content;
  size_t content_size;
  int64_t offset;

  device = (*env)->GetStringUTFChars (env, jdevice, NULL);
  content = (char *) (*env)->GetByteArrayElements (env, jcontent, NULL);
  content_size = (*env)->GetArrayLength (env, jcontent);
  offset = joffset;

  r = guestfs_pwrite_device (g, device, content, content_size, offset);

  (*env)->ReleaseStringUTFChars (env, jdevice, device);
  (*env)->ReleaseByteArrayElements (env, jcontent, (jbyte *) content, 0);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return -1;
  }
  return (jint) r;
}

JNIEXPORT jstring JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1read_1file  (JNIEnv *env, jobject obj, jlong jg, jstring jpath)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  jstring jr;
  char *r;
  size_t size;
  const char *path;

  path = (*env)->GetStringUTFChars (env, jpath, NULL);

  r = guestfs_read_file (g, path, &size);

  (*env)->ReleaseStringUTFChars (env, jpath, path);

  if (r == NULL) {
    throw_exception (env, guestfs_last_error (g));
    return NULL;
  }
  jr = (*env)->NewStringUTF (env, r); // XXX size
  free (r);
  return jr;
}

JNIEXPORT jobjectArray JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1read_1lines  (JNIEnv *env, jobject obj, jlong jg, jstring jpath)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  jobjectArray jr;
  size_t r_len;
  jclass cl;
  jstring jstr;
  char **r;
  const char *path;
  size_t i;

  path = (*env)->GetStringUTFChars (env, jpath, NULL);

  r = guestfs_read_lines (g, path);

  (*env)->ReleaseStringUTFChars (env, jpath, path);

  if (r == NULL) {
    throw_exception (env, guestfs_last_error (g));
    return NULL;
  }
  for (r_len = 0; r[r_len] != NULL; ++r_len) ;
  cl = (*env)->FindClass (env, "java/lang/String");
  jstr = (*env)->NewStringUTF (env, "");
  jr = (*env)->NewObjectArray (env, r_len, cl, jstr);
  for (i = 0; i < r_len; ++i) {
    jstr = (*env)->NewStringUTF (env, r[i]);
    (*env)->SetObjectArrayElement (env, jr, i, jstr);
    free (r[i]);
  }
  free (r);
  return jr;
}

JNIEXPORT jobjectArray JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1readdir  (JNIEnv *env, jobject obj, jlong jg, jstring jdir)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  jobjectArray jr;
  jclass cl;
  jfieldID fl;
  jobject jfl;
  struct guestfs_dirent_list *r;
  const char *dir;
  size_t i;

  dir = (*env)->GetStringUTFChars (env, jdir, NULL);

  r = guestfs_readdir (g, dir);

  (*env)->ReleaseStringUTFChars (env, jdir, dir);

  if (r == NULL) {
    throw_exception (env, guestfs_last_error (g));
    return NULL;
  }
  cl = (*env)->FindClass (env, "com/redhat/et/libguestfs/Dirent");
  jr = (*env)->NewObjectArray (env, r->len, cl, NULL);

  for (i = 0; i < r->len; ++i) {
    jfl = (*env)->AllocObject (env, cl);

    fl = (*env)->GetFieldID (env, cl, "ino",
                             "J");
    (*env)->SetLongField (env, jfl, fl, r->val[i].ino);
    fl = (*env)->GetFieldID (env, cl, "ftyp",
                             "C");
    (*env)->SetCharField (env, jfl, fl, r->val[i].ftyp);
    fl = (*env)->GetFieldID (env, cl, "name",
                             "Ljava/lang/String;");
    (*env)->SetObjectField (env, jfl, fl,
                            (*env)->NewStringUTF (env, r->val[i].name));

    (*env)->SetObjectArrayElement (env, jr, i, jfl);
  }

  guestfs_free_dirent_list (r);
  return jr;
}

JNIEXPORT jstring JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1readlink  (JNIEnv *env, jobject obj, jlong jg, jstring jpath)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  jstring jr;
  char *r;
  const char *path;

  path = (*env)->GetStringUTFChars (env, jpath, NULL);

  r = guestfs_readlink (g, path);

  (*env)->ReleaseStringUTFChars (env, jpath, path);

  if (r == NULL) {
    throw_exception (env, guestfs_last_error (g));
    return NULL;
  }
  jr = (*env)->NewStringUTF (env, r);
  free (r);
  return jr;
}

JNIEXPORT jobjectArray JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1readlinklist  (JNIEnv *env, jobject obj, jlong jg, jstring jpath, jobjectArray jnames)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  jobjectArray jr;
  size_t r_len;
  jclass cl;
  jstring jstr;
  char **r;
  const char *path;
  size_t names_len;
  char **names;
  size_t i;

  path = (*env)->GetStringUTFChars (env, jpath, NULL);
  names_len = (*env)->GetArrayLength (env, jnames);
  names = guestfs___safe_malloc (g, sizeof (char *) * (names_len+1));
  for (i = 0; i < names_len; ++i) {
    jobject o = (*env)->GetObjectArrayElement (env, jnames, i);
    names[i] = (char *) (*env)->GetStringUTFChars (env, o, NULL);
  }
  names[names_len] = NULL;

  r = guestfs_readlinklist (g, path, names);

  (*env)->ReleaseStringUTFChars (env, jpath, path);
  for (i = 0; i < names_len; ++i) {
    jobject o = (*env)->GetObjectArrayElement (env, jnames, i);
    (*env)->ReleaseStringUTFChars (env, o, names[i]);
  }
  free (names);

  if (r == NULL) {
    throw_exception (env, guestfs_last_error (g));
    return NULL;
  }
  for (r_len = 0; r[r_len] != NULL; ++r_len) ;
  cl = (*env)->FindClass (env, "java/lang/String");
  jstr = (*env)->NewStringUTF (env, "");
  jr = (*env)->NewObjectArray (env, r_len, cl, jstr);
  for (i = 0; i < r_len; ++i) {
    jstr = (*env)->NewStringUTF (env, r[i]);
    (*env)->SetObjectArrayElement (env, jr, i, jstr);
    free (r[i]);
  }
  free (r);
  return jr;
}

JNIEXPORT jstring JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1realpath  (JNIEnv *env, jobject obj, jlong jg, jstring jpath)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  jstring jr;
  char *r;
  const char *path;

  path = (*env)->GetStringUTFChars (env, jpath, NULL);

  r = guestfs_realpath (g, path);

  (*env)->ReleaseStringUTFChars (env, jpath, path);

  if (r == NULL) {
    throw_exception (env, guestfs_last_error (g));
    return NULL;
  }
  jr = (*env)->NewStringUTF (env, r);
  free (r);
  return jr;
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1remount  (JNIEnv *env, jobject obj, jlong jg, jstring jmountpoint, jlong joptargs_bitmask, jboolean jrw)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *mountpoint;
  struct guestfs_remount_argv optargs_s;
  const struct guestfs_remount_argv *optargs = &optargs_s;

  mountpoint = (*env)->GetStringUTFChars (env, jmountpoint, NULL);

  optargs_s.rw = jrw;
  optargs_s.bitmask = joptargs_bitmask;

  r = guestfs_remount_argv (g, mountpoint, optargs);

  (*env)->ReleaseStringUTFChars (env, jmountpoint, mountpoint);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1remove_1drive  (JNIEnv *env, jobject obj, jlong jg, jstring jlabel)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *label;

  label = (*env)->GetStringUTFChars (env, jlabel, NULL);

  r = guestfs_remove_drive (g, label);

  (*env)->ReleaseStringUTFChars (env, jlabel, label);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1removexattr  (JNIEnv *env, jobject obj, jlong jg, jstring jxattr, jstring jpath)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *xattr;
  const char *path;

  xattr = (*env)->GetStringUTFChars (env, jxattr, NULL);
  path = (*env)->GetStringUTFChars (env, jpath, NULL);

  r = guestfs_removexattr (g, xattr, path);

  (*env)->ReleaseStringUTFChars (env, jxattr, xattr);
  (*env)->ReleaseStringUTFChars (env, jpath, path);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1rename  (JNIEnv *env, jobject obj, jlong jg, jstring joldpath, jstring jnewpath)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *oldpath;
  const char *newpath;

  oldpath = (*env)->GetStringUTFChars (env, joldpath, NULL);
  newpath = (*env)->GetStringUTFChars (env, jnewpath, NULL);

  r = guestfs_rename (g, oldpath, newpath);

  (*env)->ReleaseStringUTFChars (env, joldpath, oldpath);
  (*env)->ReleaseStringUTFChars (env, jnewpath, newpath);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1resize2fs  (JNIEnv *env, jobject obj, jlong jg, jstring jdevice)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *device;

  device = (*env)->GetStringUTFChars (env, jdevice, NULL);

  r = guestfs_resize2fs (g, device);

  (*env)->ReleaseStringUTFChars (env, jdevice, device);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1resize2fs_1M  (JNIEnv *env, jobject obj, jlong jg, jstring jdevice)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *device;

  device = (*env)->GetStringUTFChars (env, jdevice, NULL);

  r = guestfs_resize2fs_M (g, device);

  (*env)->ReleaseStringUTFChars (env, jdevice, device);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1resize2fs_1size  (JNIEnv *env, jobject obj, jlong jg, jstring jdevice, jlong jsize)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *device;
  int64_t size;

  device = (*env)->GetStringUTFChars (env, jdevice, NULL);
  size = jsize;

  r = guestfs_resize2fs_size (g, device, size);

  (*env)->ReleaseStringUTFChars (env, jdevice, device);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1rm  (JNIEnv *env, jobject obj, jlong jg, jstring jpath)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *path;

  path = (*env)->GetStringUTFChars (env, jpath, NULL);

  r = guestfs_rm (g, path);

  (*env)->ReleaseStringUTFChars (env, jpath, path);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1rm_1f  (JNIEnv *env, jobject obj, jlong jg, jstring jpath)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *path;

  path = (*env)->GetStringUTFChars (env, jpath, NULL);

  r = guestfs_rm_f (g, path);

  (*env)->ReleaseStringUTFChars (env, jpath, path);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1rm_1rf  (JNIEnv *env, jobject obj, jlong jg, jstring jpath)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *path;

  path = (*env)->GetStringUTFChars (env, jpath, NULL);

  r = guestfs_rm_rf (g, path);

  (*env)->ReleaseStringUTFChars (env, jpath, path);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1rmdir  (JNIEnv *env, jobject obj, jlong jg, jstring jpath)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *path;

  path = (*env)->GetStringUTFChars (env, jpath, NULL);

  r = guestfs_rmdir (g, path);

  (*env)->ReleaseStringUTFChars (env, jpath, path);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1rmmountpoint  (JNIEnv *env, jobject obj, jlong jg, jstring jexemptpath)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *exemptpath;

  exemptpath = (*env)->GetStringUTFChars (env, jexemptpath, NULL);

  r = guestfs_rmmountpoint (g, exemptpath);

  (*env)->ReleaseStringUTFChars (env, jexemptpath, exemptpath);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1rsync  (JNIEnv *env, jobject obj, jlong jg, jstring jsrc, jstring jdest, jlong joptargs_bitmask, jboolean jarchive, jboolean jdeletedest)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *src;
  const char *dest;
  struct guestfs_rsync_argv optargs_s;
  const struct guestfs_rsync_argv *optargs = &optargs_s;

  src = (*env)->GetStringUTFChars (env, jsrc, NULL);
  dest = (*env)->GetStringUTFChars (env, jdest, NULL);

  optargs_s.archive = jarchive;
  optargs_s.deletedest = jdeletedest;
  optargs_s.bitmask = joptargs_bitmask;

  r = guestfs_rsync_argv (g, src, dest, optargs);

  (*env)->ReleaseStringUTFChars (env, jsrc, src);
  (*env)->ReleaseStringUTFChars (env, jdest, dest);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1rsync_1in  (JNIEnv *env, jobject obj, jlong jg, jstring jremote, jstring jdest, jlong joptargs_bitmask, jboolean jarchive, jboolean jdeletedest)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *remote;
  const char *dest;
  struct guestfs_rsync_in_argv optargs_s;
  const struct guestfs_rsync_in_argv *optargs = &optargs_s;

  remote = (*env)->GetStringUTFChars (env, jremote, NULL);
  dest = (*env)->GetStringUTFChars (env, jdest, NULL);

  optargs_s.archive = jarchive;
  optargs_s.deletedest = jdeletedest;
  optargs_s.bitmask = joptargs_bitmask;

  r = guestfs_rsync_in_argv (g, remote, dest, optargs);

  (*env)->ReleaseStringUTFChars (env, jremote, remote);
  (*env)->ReleaseStringUTFChars (env, jdest, dest);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1rsync_1out  (JNIEnv *env, jobject obj, jlong jg, jstring jsrc, jstring jremote, jlong joptargs_bitmask, jboolean jarchive, jboolean jdeletedest)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *src;
  const char *remote;
  struct guestfs_rsync_out_argv optargs_s;
  const struct guestfs_rsync_out_argv *optargs = &optargs_s;

  src = (*env)->GetStringUTFChars (env, jsrc, NULL);
  remote = (*env)->GetStringUTFChars (env, jremote, NULL);

  optargs_s.archive = jarchive;
  optargs_s.deletedest = jdeletedest;
  optargs_s.bitmask = joptargs_bitmask;

  r = guestfs_rsync_out_argv (g, src, remote, optargs);

  (*env)->ReleaseStringUTFChars (env, jsrc, src);
  (*env)->ReleaseStringUTFChars (env, jremote, remote);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1scrub_1device  (JNIEnv *env, jobject obj, jlong jg, jstring jdevice)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *device;

  device = (*env)->GetStringUTFChars (env, jdevice, NULL);

  r = guestfs_scrub_device (g, device);

  (*env)->ReleaseStringUTFChars (env, jdevice, device);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1scrub_1file  (JNIEnv *env, jobject obj, jlong jg, jstring jfile)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *file;

  file = (*env)->GetStringUTFChars (env, jfile, NULL);

  r = guestfs_scrub_file (g, file);

  (*env)->ReleaseStringUTFChars (env, jfile, file);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1scrub_1freespace  (JNIEnv *env, jobject obj, jlong jg, jstring jdir)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *dir;

  dir = (*env)->GetStringUTFChars (env, jdir, NULL);

  r = guestfs_scrub_freespace (g, dir);

  (*env)->ReleaseStringUTFChars (env, jdir, dir);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1set_1append  (JNIEnv *env, jobject obj, jlong jg, jstring jappend)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *append;

  append = jappend ? (*env)->GetStringUTFChars (env, jappend, NULL) : NULL;

  r = guestfs_set_append (g, append);

  if (jappend)
    (*env)->ReleaseStringUTFChars (env, jappend, append);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1set_1attach_1method  (JNIEnv *env, jobject obj, jlong jg, jstring jbackend)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *backend;

  backend = (*env)->GetStringUTFChars (env, jbackend, NULL);

  r = guestfs_set_attach_method (g, backend);

  (*env)->ReleaseStringUTFChars (env, jbackend, backend);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1set_1autosync  (JNIEnv *env, jobject obj, jlong jg, jboolean jautosync)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  int autosync;

  autosync = jautosync;

  r = guestfs_set_autosync (g, autosync);


  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1set_1backend  (JNIEnv *env, jobject obj, jlong jg, jstring jbackend)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *backend;

  backend = (*env)->GetStringUTFChars (env, jbackend, NULL);

  r = guestfs_set_backend (g, backend);

  (*env)->ReleaseStringUTFChars (env, jbackend, backend);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1set_1backend_1setting  (JNIEnv *env, jobject obj, jlong jg, jstring jname, jstring jval)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *name;
  const char *val;

  name = (*env)->GetStringUTFChars (env, jname, NULL);
  val = (*env)->GetStringUTFChars (env, jval, NULL);

  r = guestfs_set_backend_setting (g, name, val);

  (*env)->ReleaseStringUTFChars (env, jname, name);
  (*env)->ReleaseStringUTFChars (env, jval, val);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1set_1backend_1settings  (JNIEnv *env, jobject obj, jlong jg, jobjectArray jsettings)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  size_t settings_len;
  char **settings;
  size_t i;

  settings_len = (*env)->GetArrayLength (env, jsettings);
  settings = guestfs___safe_malloc (g, sizeof (char *) * (settings_len+1));
  for (i = 0; i < settings_len; ++i) {
    jobject o = (*env)->GetObjectArrayElement (env, jsettings, i);
    settings[i] = (char *) (*env)->GetStringUTFChars (env, o, NULL);
  }
  settings[settings_len] = NULL;

  r = guestfs_set_backend_settings (g, settings);

  for (i = 0; i < settings_len; ++i) {
    jobject o = (*env)->GetObjectArrayElement (env, jsettings, i);
    (*env)->ReleaseStringUTFChars (env, o, settings[i]);
  }
  free (settings);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1set_1cachedir  (JNIEnv *env, jobject obj, jlong jg, jstring jcachedir)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *cachedir;

  cachedir = jcachedir ? (*env)->GetStringUTFChars (env, jcachedir, NULL) : NULL;

  r = guestfs_set_cachedir (g, cachedir);

  if (jcachedir)
    (*env)->ReleaseStringUTFChars (env, jcachedir, cachedir);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1set_1direct  (JNIEnv *env, jobject obj, jlong jg, jboolean jdirect)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  int direct;

  direct = jdirect;

  r = guestfs_set_direct (g, direct);


  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1set_1e2attrs  (JNIEnv *env, jobject obj, jlong jg, jstring jfile, jstring jattrs, jlong joptargs_bitmask, jboolean jclear)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *file;
  const char *attrs;
  struct guestfs_set_e2attrs_argv optargs_s;
  const struct guestfs_set_e2attrs_argv *optargs = &optargs_s;

  file = (*env)->GetStringUTFChars (env, jfile, NULL);
  attrs = (*env)->GetStringUTFChars (env, jattrs, NULL);

  optargs_s.clear = jclear;
  optargs_s.bitmask = joptargs_bitmask;

  r = guestfs_set_e2attrs_argv (g, file, attrs, optargs);

  (*env)->ReleaseStringUTFChars (env, jfile, file);
  (*env)->ReleaseStringUTFChars (env, jattrs, attrs);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1set_1e2generation  (JNIEnv *env, jobject obj, jlong jg, jstring jfile, jlong jgeneration)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *file;
  int64_t generation;

  file = (*env)->GetStringUTFChars (env, jfile, NULL);
  generation = jgeneration;

  r = guestfs_set_e2generation (g, file, generation);

  (*env)->ReleaseStringUTFChars (env, jfile, file);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1set_1e2label  (JNIEnv *env, jobject obj, jlong jg, jstring jdevice, jstring jlabel)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *device;
  const char *label;

  device = (*env)->GetStringUTFChars (env, jdevice, NULL);
  label = (*env)->GetStringUTFChars (env, jlabel, NULL);

  r = guestfs_set_e2label (g, device, label);

  (*env)->ReleaseStringUTFChars (env, jdevice, device);
  (*env)->ReleaseStringUTFChars (env, jlabel, label);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1set_1e2uuid  (JNIEnv *env, jobject obj, jlong jg, jstring jdevice, jstring juuid)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *device;
  const char *uuid;

  device = (*env)->GetStringUTFChars (env, jdevice, NULL);
  uuid = (*env)->GetStringUTFChars (env, juuid, NULL);

  r = guestfs_set_e2uuid (g, device, uuid);

  (*env)->ReleaseStringUTFChars (env, jdevice, device);
  (*env)->ReleaseStringUTFChars (env, juuid, uuid);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1set_1hv  (JNIEnv *env, jobject obj, jlong jg, jstring jhv)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *hv;

  hv = (*env)->GetStringUTFChars (env, jhv, NULL);

  r = guestfs_set_hv (g, hv);

  (*env)->ReleaseStringUTFChars (env, jhv, hv);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1set_1label  (JNIEnv *env, jobject obj, jlong jg, jstring jmountable, jstring jlabel)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *mountable;
  const char *label;

  mountable = (*env)->GetStringUTFChars (env, jmountable, NULL);
  label = (*env)->GetStringUTFChars (env, jlabel, NULL);

  r = guestfs_set_label (g, mountable, label);

  (*env)->ReleaseStringUTFChars (env, jmountable, mountable);
  (*env)->ReleaseStringUTFChars (env, jlabel, label);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1set_1libvirt_1requested_1credential  (JNIEnv *env, jobject obj, jlong jg, jint jindex, jbyteArray jcred)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  int index;
  char *cred;
  size_t cred_size;

  index = jindex;
  cred = (char *) (*env)->GetByteArrayElements (env, jcred, NULL);
  cred_size = (*env)->GetArrayLength (env, jcred);

  r = guestfs_set_libvirt_requested_credential (g, index, cred, cred_size);

  (*env)->ReleaseByteArrayElements (env, jcred, (jbyte *) cred, 0);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1set_1libvirt_1supported_1credentials  (JNIEnv *env, jobject obj, jlong jg, jobjectArray jcreds)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  size_t creds_len;
  char **creds;
  size_t i;

  creds_len = (*env)->GetArrayLength (env, jcreds);
  creds = guestfs___safe_malloc (g, sizeof (char *) * (creds_len+1));
  for (i = 0; i < creds_len; ++i) {
    jobject o = (*env)->GetObjectArrayElement (env, jcreds, i);
    creds[i] = (char *) (*env)->GetStringUTFChars (env, o, NULL);
  }
  creds[creds_len] = NULL;

  r = guestfs_set_libvirt_supported_credentials (g, creds);

  for (i = 0; i < creds_len; ++i) {
    jobject o = (*env)->GetObjectArrayElement (env, jcreds, i);
    (*env)->ReleaseStringUTFChars (env, o, creds[i]);
  }
  free (creds);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1set_1memsize  (JNIEnv *env, jobject obj, jlong jg, jint jmemsize)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  int memsize;

  memsize = jmemsize;

  r = guestfs_set_memsize (g, memsize);


  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1set_1network  (JNIEnv *env, jobject obj, jlong jg, jboolean jnetwork)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  int network;

  network = jnetwork;

  r = guestfs_set_network (g, network);


  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1set_1path  (JNIEnv *env, jobject obj, jlong jg, jstring jsearchpath)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *searchpath;

  searchpath = jsearchpath ? (*env)->GetStringUTFChars (env, jsearchpath, NULL) : NULL;

  r = guestfs_set_path (g, searchpath);

  if (jsearchpath)
    (*env)->ReleaseStringUTFChars (env, jsearchpath, searchpath);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1set_1pgroup  (JNIEnv *env, jobject obj, jlong jg, jboolean jpgroup)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  int pgroup;

  pgroup = jpgroup;

  r = guestfs_set_pgroup (g, pgroup);


  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1set_1program  (JNIEnv *env, jobject obj, jlong jg, jstring jprogram)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *program;

  program = (*env)->GetStringUTFChars (env, jprogram, NULL);

  r = guestfs_set_program (g, program);

  (*env)->ReleaseStringUTFChars (env, jprogram, program);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1set_1qemu  (JNIEnv *env, jobject obj, jlong jg, jstring jhv)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *hv;

  hv = jhv ? (*env)->GetStringUTFChars (env, jhv, NULL) : NULL;

  r = guestfs_set_qemu (g, hv);

  if (jhv)
    (*env)->ReleaseStringUTFChars (env, jhv, hv);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1set_1recovery_1proc  (JNIEnv *env, jobject obj, jlong jg, jboolean jrecoveryproc)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  int recoveryproc;

  recoveryproc = jrecoveryproc;

  r = guestfs_set_recovery_proc (g, recoveryproc);


  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1set_1selinux  (JNIEnv *env, jobject obj, jlong jg, jboolean jselinux)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  int selinux;

  selinux = jselinux;

  r = guestfs_set_selinux (g, selinux);


  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1set_1smp  (JNIEnv *env, jobject obj, jlong jg, jint jsmp)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  int smp;

  smp = jsmp;

  r = guestfs_set_smp (g, smp);


  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1set_1tmpdir  (JNIEnv *env, jobject obj, jlong jg, jstring jtmpdir)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *tmpdir;

  tmpdir = jtmpdir ? (*env)->GetStringUTFChars (env, jtmpdir, NULL) : NULL;

  r = guestfs_set_tmpdir (g, tmpdir);

  if (jtmpdir)
    (*env)->ReleaseStringUTFChars (env, jtmpdir, tmpdir);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1set_1trace  (JNIEnv *env, jobject obj, jlong jg, jboolean jtrace)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  int trace;

  trace = jtrace;

  r = guestfs_set_trace (g, trace);


  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1set_1uuid  (JNIEnv *env, jobject obj, jlong jg, jstring jdevice, jstring juuid)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *device;
  const char *uuid;

  device = (*env)->GetStringUTFChars (env, jdevice, NULL);
  uuid = (*env)->GetStringUTFChars (env, juuid, NULL);

  r = guestfs_set_uuid (g, device, uuid);

  (*env)->ReleaseStringUTFChars (env, jdevice, device);
  (*env)->ReleaseStringUTFChars (env, juuid, uuid);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1set_1verbose  (JNIEnv *env, jobject obj, jlong jg, jboolean jverbose)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  int verbose;

  verbose = jverbose;

  r = guestfs_set_verbose (g, verbose);


  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1setcon  (JNIEnv *env, jobject obj, jlong jg, jstring jcontext)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *context;

  context = (*env)->GetStringUTFChars (env, jcontext, NULL);

  r = guestfs_setcon (g, context);

  (*env)->ReleaseStringUTFChars (env, jcontext, context);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1setxattr  (JNIEnv *env, jobject obj, jlong jg, jstring jxattr, jstring jval, jint jvallen, jstring jpath)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *xattr;
  const char *val;
  int vallen;
  const char *path;

  xattr = (*env)->GetStringUTFChars (env, jxattr, NULL);
  val = (*env)->GetStringUTFChars (env, jval, NULL);
  vallen = jvallen;
  path = (*env)->GetStringUTFChars (env, jpath, NULL);

  r = guestfs_setxattr (g, xattr, val, vallen, path);

  (*env)->ReleaseStringUTFChars (env, jxattr, xattr);
  (*env)->ReleaseStringUTFChars (env, jval, val);
  (*env)->ReleaseStringUTFChars (env, jpath, path);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1sfdisk  (JNIEnv *env, jobject obj, jlong jg, jstring jdevice, jint jcyls, jint jheads, jint jsectors, jobjectArray jlines)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *device;
  int cyls;
  int heads;
  int sectors;
  size_t lines_len;
  char **lines;
  size_t i;

  device = (*env)->GetStringUTFChars (env, jdevice, NULL);
  cyls = jcyls;
  heads = jheads;
  sectors = jsectors;
  lines_len = (*env)->GetArrayLength (env, jlines);
  lines = guestfs___safe_malloc (g, sizeof (char *) * (lines_len+1));
  for (i = 0; i < lines_len; ++i) {
    jobject o = (*env)->GetObjectArrayElement (env, jlines, i);
    lines[i] = (char *) (*env)->GetStringUTFChars (env, o, NULL);
  }
  lines[lines_len] = NULL;

  r = guestfs_sfdisk (g, device, cyls, heads, sectors, lines);

  (*env)->ReleaseStringUTFChars (env, jdevice, device);
  for (i = 0; i < lines_len; ++i) {
    jobject o = (*env)->GetObjectArrayElement (env, jlines, i);
    (*env)->ReleaseStringUTFChars (env, o, lines[i]);
  }
  free (lines);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1sfdiskM  (JNIEnv *env, jobject obj, jlong jg, jstring jdevice, jobjectArray jlines)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *device;
  size_t lines_len;
  char **lines;
  size_t i;

  device = (*env)->GetStringUTFChars (env, jdevice, NULL);
  lines_len = (*env)->GetArrayLength (env, jlines);
  lines = guestfs___safe_malloc (g, sizeof (char *) * (lines_len+1));
  for (i = 0; i < lines_len; ++i) {
    jobject o = (*env)->GetObjectArrayElement (env, jlines, i);
    lines[i] = (char *) (*env)->GetStringUTFChars (env, o, NULL);
  }
  lines[lines_len] = NULL;

  r = guestfs_sfdiskM (g, device, lines);

  (*env)->ReleaseStringUTFChars (env, jdevice, device);
  for (i = 0; i < lines_len; ++i) {
    jobject o = (*env)->GetObjectArrayElement (env, jlines, i);
    (*env)->ReleaseStringUTFChars (env, o, lines[i]);
  }
  free (lines);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1sfdisk_1N  (JNIEnv *env, jobject obj, jlong jg, jstring jdevice, jint jpartnum, jint jcyls, jint jheads, jint jsectors, jstring jline)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *device;
  int partnum;
  int cyls;
  int heads;
  int sectors;
  const char *line;

  device = (*env)->GetStringUTFChars (env, jdevice, NULL);
  partnum = jpartnum;
  cyls = jcyls;
  heads = jheads;
  sectors = jsectors;
  line = (*env)->GetStringUTFChars (env, jline, NULL);

  r = guestfs_sfdisk_N (g, device, partnum, cyls, heads, sectors, line);

  (*env)->ReleaseStringUTFChars (env, jdevice, device);
  (*env)->ReleaseStringUTFChars (env, jline, line);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT jstring JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1sfdisk_1disk_1geometry  (JNIEnv *env, jobject obj, jlong jg, jstring jdevice)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  jstring jr;
  char *r;
  const char *device;

  device = (*env)->GetStringUTFChars (env, jdevice, NULL);

  r = guestfs_sfdisk_disk_geometry (g, device);

  (*env)->ReleaseStringUTFChars (env, jdevice, device);

  if (r == NULL) {
    throw_exception (env, guestfs_last_error (g));
    return NULL;
  }
  jr = (*env)->NewStringUTF (env, r);
  free (r);
  return jr;
}

JNIEXPORT jstring JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1sfdisk_1kernel_1geometry  (JNIEnv *env, jobject obj, jlong jg, jstring jdevice)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  jstring jr;
  char *r;
  const char *device;

  device = (*env)->GetStringUTFChars (env, jdevice, NULL);

  r = guestfs_sfdisk_kernel_geometry (g, device);

  (*env)->ReleaseStringUTFChars (env, jdevice, device);

  if (r == NULL) {
    throw_exception (env, guestfs_last_error (g));
    return NULL;
  }
  jr = (*env)->NewStringUTF (env, r);
  free (r);
  return jr;
}

JNIEXPORT jstring JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1sfdisk_1l  (JNIEnv *env, jobject obj, jlong jg, jstring jdevice)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  jstring jr;
  char *r;
  const char *device;

  device = (*env)->GetStringUTFChars (env, jdevice, NULL);

  r = guestfs_sfdisk_l (g, device);

  (*env)->ReleaseStringUTFChars (env, jdevice, device);

  if (r == NULL) {
    throw_exception (env, guestfs_last_error (g));
    return NULL;
  }
  jr = (*env)->NewStringUTF (env, r);
  free (r);
  return jr;
}

JNIEXPORT jstring JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1sh  (JNIEnv *env, jobject obj, jlong jg, jstring jcommand)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  jstring jr;
  char *r;
  const char *command;

  command = (*env)->GetStringUTFChars (env, jcommand, NULL);

  r = guestfs_sh (g, command);

  (*env)->ReleaseStringUTFChars (env, jcommand, command);

  if (r == NULL) {
    throw_exception (env, guestfs_last_error (g));
    return NULL;
  }
  jr = (*env)->NewStringUTF (env, r);
  free (r);
  return jr;
}

JNIEXPORT jobjectArray JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1sh_1lines  (JNIEnv *env, jobject obj, jlong jg, jstring jcommand)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  jobjectArray jr;
  size_t r_len;
  jclass cl;
  jstring jstr;
  char **r;
  const char *command;
  size_t i;

  command = (*env)->GetStringUTFChars (env, jcommand, NULL);

  r = guestfs_sh_lines (g, command);

  (*env)->ReleaseStringUTFChars (env, jcommand, command);

  if (r == NULL) {
    throw_exception (env, guestfs_last_error (g));
    return NULL;
  }
  for (r_len = 0; r[r_len] != NULL; ++r_len) ;
  cl = (*env)->FindClass (env, "java/lang/String");
  jstr = (*env)->NewStringUTF (env, "");
  jr = (*env)->NewObjectArray (env, r_len, cl, jstr);
  for (i = 0; i < r_len; ++i) {
    jstr = (*env)->NewStringUTF (env, r[i]);
    (*env)->SetObjectArrayElement (env, jr, i, jstr);
    free (r[i]);
  }
  free (r);
  return jr;
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1shutdown  (JNIEnv *env, jobject obj, jlong jg)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;


  r = guestfs_shutdown (g);


  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1sleep  (JNIEnv *env, jobject obj, jlong jg, jint jsecs)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  int secs;

  secs = jsecs;

  r = guestfs_sleep (g, secs);


  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT jobject JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1stat  (JNIEnv *env, jobject obj, jlong jg, jstring jpath)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  jobject jr;
  jclass cl;
  jfieldID fl;
  struct guestfs_stat *r;
  const char *path;

  path = (*env)->GetStringUTFChars (env, jpath, NULL);

  r = guestfs_stat (g, path);

  (*env)->ReleaseStringUTFChars (env, jpath, path);

  if (r == NULL) {
    throw_exception (env, guestfs_last_error (g));
    return NULL;
  }
  cl = (*env)->FindClass (env, "com/redhat/et/libguestfs/Stat");
  jr = (*env)->AllocObject (env, cl);
  fl = (*env)->GetFieldID (env, cl, "dev", "J");
  (*env)->SetLongField (env, jr, fl, r->dev);
  fl = (*env)->GetFieldID (env, cl, "ino", "J");
  (*env)->SetLongField (env, jr, fl, r->ino);
  fl = (*env)->GetFieldID (env, cl, "mode", "J");
  (*env)->SetLongField (env, jr, fl, r->mode);
  fl = (*env)->GetFieldID (env, cl, "nlink", "J");
  (*env)->SetLongField (env, jr, fl, r->nlink);
  fl = (*env)->GetFieldID (env, cl, "uid", "J");
  (*env)->SetLongField (env, jr, fl, r->uid);
  fl = (*env)->GetFieldID (env, cl, "gid", "J");
  (*env)->SetLongField (env, jr, fl, r->gid);
  fl = (*env)->GetFieldID (env, cl, "rdev", "J");
  (*env)->SetLongField (env, jr, fl, r->rdev);
  fl = (*env)->GetFieldID (env, cl, "size", "J");
  (*env)->SetLongField (env, jr, fl, r->size);
  fl = (*env)->GetFieldID (env, cl, "blksize", "J");
  (*env)->SetLongField (env, jr, fl, r->blksize);
  fl = (*env)->GetFieldID (env, cl, "blocks", "J");
  (*env)->SetLongField (env, jr, fl, r->blocks);
  fl = (*env)->GetFieldID (env, cl, "atime", "J");
  (*env)->SetLongField (env, jr, fl, r->atime);
  fl = (*env)->GetFieldID (env, cl, "mtime", "J");
  (*env)->SetLongField (env, jr, fl, r->mtime);
  fl = (*env)->GetFieldID (env, cl, "ctime", "J");
  (*env)->SetLongField (env, jr, fl, r->ctime);
  free (r);
  return jr;
}

JNIEXPORT jobject JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1statns  (JNIEnv *env, jobject obj, jlong jg, jstring jpath)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  jobject jr;
  jclass cl;
  jfieldID fl;
  struct guestfs_statns *r;
  const char *path;

  path = (*env)->GetStringUTFChars (env, jpath, NULL);

  r = guestfs_statns (g, path);

  (*env)->ReleaseStringUTFChars (env, jpath, path);

  if (r == NULL) {
    throw_exception (env, guestfs_last_error (g));
    return NULL;
  }
  cl = (*env)->FindClass (env, "com/redhat/et/libguestfs/StatNS");
  jr = (*env)->AllocObject (env, cl);
  fl = (*env)->GetFieldID (env, cl, "st_dev", "J");
  (*env)->SetLongField (env, jr, fl, r->st_dev);
  fl = (*env)->GetFieldID (env, cl, "st_ino", "J");
  (*env)->SetLongField (env, jr, fl, r->st_ino);
  fl = (*env)->GetFieldID (env, cl, "st_mode", "J");
  (*env)->SetLongField (env, jr, fl, r->st_mode);
  fl = (*env)->GetFieldID (env, cl, "st_nlink", "J");
  (*env)->SetLongField (env, jr, fl, r->st_nlink);
  fl = (*env)->GetFieldID (env, cl, "st_uid", "J");
  (*env)->SetLongField (env, jr, fl, r->st_uid);
  fl = (*env)->GetFieldID (env, cl, "st_gid", "J");
  (*env)->SetLongField (env, jr, fl, r->st_gid);
  fl = (*env)->GetFieldID (env, cl, "st_rdev", "J");
  (*env)->SetLongField (env, jr, fl, r->st_rdev);
  fl = (*env)->GetFieldID (env, cl, "st_size", "J");
  (*env)->SetLongField (env, jr, fl, r->st_size);
  fl = (*env)->GetFieldID (env, cl, "st_blksize", "J");
  (*env)->SetLongField (env, jr, fl, r->st_blksize);
  fl = (*env)->GetFieldID (env, cl, "st_blocks", "J");
  (*env)->SetLongField (env, jr, fl, r->st_blocks);
  fl = (*env)->GetFieldID (env, cl, "st_atime_sec", "J");
  (*env)->SetLongField (env, jr, fl, r->st_atime_sec);
  fl = (*env)->GetFieldID (env, cl, "st_atime_nsec", "J");
  (*env)->SetLongField (env, jr, fl, r->st_atime_nsec);
  fl = (*env)->GetFieldID (env, cl, "st_mtime_sec", "J");
  (*env)->SetLongField (env, jr, fl, r->st_mtime_sec);
  fl = (*env)->GetFieldID (env, cl, "st_mtime_nsec", "J");
  (*env)->SetLongField (env, jr, fl, r->st_mtime_nsec);
  fl = (*env)->GetFieldID (env, cl, "st_ctime_sec", "J");
  (*env)->SetLongField (env, jr, fl, r->st_ctime_sec);
  fl = (*env)->GetFieldID (env, cl, "st_ctime_nsec", "J");
  (*env)->SetLongField (env, jr, fl, r->st_ctime_nsec);
  fl = (*env)->GetFieldID (env, cl, "st_spare1", "J");
  (*env)->SetLongField (env, jr, fl, r->st_spare1);
  fl = (*env)->GetFieldID (env, cl, "st_spare2", "J");
  (*env)->SetLongField (env, jr, fl, r->st_spare2);
  fl = (*env)->GetFieldID (env, cl, "st_spare3", "J");
  (*env)->SetLongField (env, jr, fl, r->st_spare3);
  fl = (*env)->GetFieldID (env, cl, "st_spare4", "J");
  (*env)->SetLongField (env, jr, fl, r->st_spare4);
  fl = (*env)->GetFieldID (env, cl, "st_spare5", "J");
  (*env)->SetLongField (env, jr, fl, r->st_spare5);
  fl = (*env)->GetFieldID (env, cl, "st_spare6", "J");
  (*env)->SetLongField (env, jr, fl, r->st_spare6);
  free (r);
  return jr;
}

JNIEXPORT jobject JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1statvfs  (JNIEnv *env, jobject obj, jlong jg, jstring jpath)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  jobject jr;
  jclass cl;
  jfieldID fl;
  struct guestfs_statvfs *r;
  const char *path;

  path = (*env)->GetStringUTFChars (env, jpath, NULL);

  r = guestfs_statvfs (g, path);

  (*env)->ReleaseStringUTFChars (env, jpath, path);

  if (r == NULL) {
    throw_exception (env, guestfs_last_error (g));
    return NULL;
  }
  cl = (*env)->FindClass (env, "com/redhat/et/libguestfs/StatVFS");
  jr = (*env)->AllocObject (env, cl);
  fl = (*env)->GetFieldID (env, cl, "bsize", "J");
  (*env)->SetLongField (env, jr, fl, r->bsize);
  fl = (*env)->GetFieldID (env, cl, "frsize", "J");
  (*env)->SetLongField (env, jr, fl, r->frsize);
  fl = (*env)->GetFieldID (env, cl, "blocks", "J");
  (*env)->SetLongField (env, jr, fl, r->blocks);
  fl = (*env)->GetFieldID (env, cl, "bfree", "J");
  (*env)->SetLongField (env, jr, fl, r->bfree);
  fl = (*env)->GetFieldID (env, cl, "bavail", "J");
  (*env)->SetLongField (env, jr, fl, r->bavail);
  fl = (*env)->GetFieldID (env, cl, "files", "J");
  (*env)->SetLongField (env, jr, fl, r->files);
  fl = (*env)->GetFieldID (env, cl, "ffree", "J");
  (*env)->SetLongField (env, jr, fl, r->ffree);
  fl = (*env)->GetFieldID (env, cl, "favail", "J");
  (*env)->SetLongField (env, jr, fl, r->favail);
  fl = (*env)->GetFieldID (env, cl, "fsid", "J");
  (*env)->SetLongField (env, jr, fl, r->fsid);
  fl = (*env)->GetFieldID (env, cl, "flag", "J");
  (*env)->SetLongField (env, jr, fl, r->flag);
  fl = (*env)->GetFieldID (env, cl, "namemax", "J");
  (*env)->SetLongField (env, jr, fl, r->namemax);
  free (r);
  return jr;
}

JNIEXPORT jobjectArray JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1strings  (JNIEnv *env, jobject obj, jlong jg, jstring jpath)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  jobjectArray jr;
  size_t r_len;
  jclass cl;
  jstring jstr;
  char **r;
  const char *path;
  size_t i;

  path = (*env)->GetStringUTFChars (env, jpath, NULL);

  r = guestfs_strings (g, path);

  (*env)->ReleaseStringUTFChars (env, jpath, path);

  if (r == NULL) {
    throw_exception (env, guestfs_last_error (g));
    return NULL;
  }
  for (r_len = 0; r[r_len] != NULL; ++r_len) ;
  cl = (*env)->FindClass (env, "java/lang/String");
  jstr = (*env)->NewStringUTF (env, "");
  jr = (*env)->NewObjectArray (env, r_len, cl, jstr);
  for (i = 0; i < r_len; ++i) {
    jstr = (*env)->NewStringUTF (env, r[i]);
    (*env)->SetObjectArrayElement (env, jr, i, jstr);
    free (r[i]);
  }
  free (r);
  return jr;
}

JNIEXPORT jobjectArray JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1strings_1e  (JNIEnv *env, jobject obj, jlong jg, jstring jencoding, jstring jpath)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  jobjectArray jr;
  size_t r_len;
  jclass cl;
  jstring jstr;
  char **r;
  const char *encoding;
  const char *path;
  size_t i;

  encoding = (*env)->GetStringUTFChars (env, jencoding, NULL);
  path = (*env)->GetStringUTFChars (env, jpath, NULL);

  r = guestfs_strings_e (g, encoding, path);

  (*env)->ReleaseStringUTFChars (env, jencoding, encoding);
  (*env)->ReleaseStringUTFChars (env, jpath, path);

  if (r == NULL) {
    throw_exception (env, guestfs_last_error (g));
    return NULL;
  }
  for (r_len = 0; r[r_len] != NULL; ++r_len) ;
  cl = (*env)->FindClass (env, "java/lang/String");
  jstr = (*env)->NewStringUTF (env, "");
  jr = (*env)->NewObjectArray (env, r_len, cl, jstr);
  for (i = 0; i < r_len; ++i) {
    jstr = (*env)->NewStringUTF (env, r[i]);
    (*env)->SetObjectArrayElement (env, jr, i, jstr);
    free (r[i]);
  }
  free (r);
  return jr;
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1swapoff_1device  (JNIEnv *env, jobject obj, jlong jg, jstring jdevice)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *device;

  device = (*env)->GetStringUTFChars (env, jdevice, NULL);

  r = guestfs_swapoff_device (g, device);

  (*env)->ReleaseStringUTFChars (env, jdevice, device);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1swapoff_1file  (JNIEnv *env, jobject obj, jlong jg, jstring jfile)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *file;

  file = (*env)->GetStringUTFChars (env, jfile, NULL);

  r = guestfs_swapoff_file (g, file);

  (*env)->ReleaseStringUTFChars (env, jfile, file);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1swapoff_1label  (JNIEnv *env, jobject obj, jlong jg, jstring jlabel)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *label;

  label = (*env)->GetStringUTFChars (env, jlabel, NULL);

  r = guestfs_swapoff_label (g, label);

  (*env)->ReleaseStringUTFChars (env, jlabel, label);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1swapoff_1uuid  (JNIEnv *env, jobject obj, jlong jg, jstring juuid)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *uuid;

  uuid = (*env)->GetStringUTFChars (env, juuid, NULL);

  r = guestfs_swapoff_uuid (g, uuid);

  (*env)->ReleaseStringUTFChars (env, juuid, uuid);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1swapon_1device  (JNIEnv *env, jobject obj, jlong jg, jstring jdevice)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *device;

  device = (*env)->GetStringUTFChars (env, jdevice, NULL);

  r = guestfs_swapon_device (g, device);

  (*env)->ReleaseStringUTFChars (env, jdevice, device);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1swapon_1file  (JNIEnv *env, jobject obj, jlong jg, jstring jfile)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *file;

  file = (*env)->GetStringUTFChars (env, jfile, NULL);

  r = guestfs_swapon_file (g, file);

  (*env)->ReleaseStringUTFChars (env, jfile, file);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1swapon_1label  (JNIEnv *env, jobject obj, jlong jg, jstring jlabel)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *label;

  label = (*env)->GetStringUTFChars (env, jlabel, NULL);

  r = guestfs_swapon_label (g, label);

  (*env)->ReleaseStringUTFChars (env, jlabel, label);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1swapon_1uuid  (JNIEnv *env, jobject obj, jlong jg, jstring juuid)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *uuid;

  uuid = (*env)->GetStringUTFChars (env, juuid, NULL);

  r = guestfs_swapon_uuid (g, uuid);

  (*env)->ReleaseStringUTFChars (env, juuid, uuid);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1sync  (JNIEnv *env, jobject obj, jlong jg)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;


  r = guestfs_sync (g);


  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1syslinux  (JNIEnv *env, jobject obj, jlong jg, jstring jdevice, jlong joptargs_bitmask, jstring jdirectory)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *device;
  struct guestfs_syslinux_argv optargs_s;
  const struct guestfs_syslinux_argv *optargs = &optargs_s;

  device = (*env)->GetStringUTFChars (env, jdevice, NULL);

  optargs_s.directory = (*env)->GetStringUTFChars (env, jdirectory, NULL);
  optargs_s.bitmask = joptargs_bitmask;

  r = guestfs_syslinux_argv (g, device, optargs);

  (*env)->ReleaseStringUTFChars (env, jdevice, device);
  (*env)->ReleaseStringUTFChars (env, jdirectory, optargs_s.directory);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT jobjectArray JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1tail  (JNIEnv *env, jobject obj, jlong jg, jstring jpath)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  jobjectArray jr;
  size_t r_len;
  jclass cl;
  jstring jstr;
  char **r;
  const char *path;
  size_t i;

  path = (*env)->GetStringUTFChars (env, jpath, NULL);

  r = guestfs_tail (g, path);

  (*env)->ReleaseStringUTFChars (env, jpath, path);

  if (r == NULL) {
    throw_exception (env, guestfs_last_error (g));
    return NULL;
  }
  for (r_len = 0; r[r_len] != NULL; ++r_len) ;
  cl = (*env)->FindClass (env, "java/lang/String");
  jstr = (*env)->NewStringUTF (env, "");
  jr = (*env)->NewObjectArray (env, r_len, cl, jstr);
  for (i = 0; i < r_len; ++i) {
    jstr = (*env)->NewStringUTF (env, r[i]);
    (*env)->SetObjectArrayElement (env, jr, i, jstr);
    free (r[i]);
  }
  free (r);
  return jr;
}

JNIEXPORT jobjectArray JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1tail_1n  (JNIEnv *env, jobject obj, jlong jg, jint jnrlines, jstring jpath)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  jobjectArray jr;
  size_t r_len;
  jclass cl;
  jstring jstr;
  char **r;
  int nrlines;
  const char *path;
  size_t i;

  nrlines = jnrlines;
  path = (*env)->GetStringUTFChars (env, jpath, NULL);

  r = guestfs_tail_n (g, nrlines, path);

  (*env)->ReleaseStringUTFChars (env, jpath, path);

  if (r == NULL) {
    throw_exception (env, guestfs_last_error (g));
    return NULL;
  }
  for (r_len = 0; r[r_len] != NULL; ++r_len) ;
  cl = (*env)->FindClass (env, "java/lang/String");
  jstr = (*env)->NewStringUTF (env, "");
  jr = (*env)->NewObjectArray (env, r_len, cl, jstr);
  for (i = 0; i < r_len; ++i) {
    jstr = (*env)->NewStringUTF (env, r[i]);
    (*env)->SetObjectArrayElement (env, jr, i, jstr);
    free (r[i]);
  }
  free (r);
  return jr;
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1tar_1in  (JNIEnv *env, jobject obj, jlong jg, jstring jtarfile, jstring jdirectory, jlong joptargs_bitmask, jstring jcompress)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *tarfile;
  const char *directory;
  struct guestfs_tar_in_opts_argv optargs_s;
  const struct guestfs_tar_in_opts_argv *optargs = &optargs_s;

  tarfile = (*env)->GetStringUTFChars (env, jtarfile, NULL);
  directory = (*env)->GetStringUTFChars (env, jdirectory, NULL);

  optargs_s.compress = (*env)->GetStringUTFChars (env, jcompress, NULL);
  optargs_s.bitmask = joptargs_bitmask;

  r = guestfs_tar_in_opts_argv (g, tarfile, directory, optargs);

  (*env)->ReleaseStringUTFChars (env, jtarfile, tarfile);
  (*env)->ReleaseStringUTFChars (env, jdirectory, directory);
  (*env)->ReleaseStringUTFChars (env, jcompress, optargs_s.compress);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1tar_1out  (JNIEnv *env, jobject obj, jlong jg, jstring jdirectory, jstring jtarfile, jlong joptargs_bitmask, jstring jcompress, jboolean jnumericowner, jobjectArray jexcludes)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *directory;
  const char *tarfile;
  struct guestfs_tar_out_opts_argv optargs_s;
  const struct guestfs_tar_out_opts_argv *optargs = &optargs_s;
  size_t excludes_len;
  char **excludes;
  size_t i;

  directory = (*env)->GetStringUTFChars (env, jdirectory, NULL);
  tarfile = (*env)->GetStringUTFChars (env, jtarfile, NULL);

  optargs_s.compress = (*env)->GetStringUTFChars (env, jcompress, NULL);
  optargs_s.numericowner = jnumericowner;
  excludes_len = (*env)->GetArrayLength (env, jexcludes);
  excludes = guestfs___safe_malloc (g, sizeof (char *) * (excludes_len+1));
  for (i = 0; i < excludes_len; ++i) {
    jobject o = (*env)->GetObjectArrayElement (env, jexcludes, i);
    excludes[i] = (char *) (*env)->GetStringUTFChars (env, o, NULL);
  }
  excludes[excludes_len] = NULL;
  optargs_s.excludes = excludes;
  optargs_s.bitmask = joptargs_bitmask;

  r = guestfs_tar_out_opts_argv (g, directory, tarfile, optargs);

  (*env)->ReleaseStringUTFChars (env, jdirectory, directory);
  (*env)->ReleaseStringUTFChars (env, jtarfile, tarfile);
  (*env)->ReleaseStringUTFChars (env, jcompress, optargs_s.compress);
  for (i = 0; i < excludes_len; ++i) {
    jobject o = (*env)->GetObjectArrayElement (env, jexcludes, i);
    (*env)->ReleaseStringUTFChars (env, o, optargs_s.excludes[i]);
  }
  free (excludes);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1tgz_1in  (JNIEnv *env, jobject obj, jlong jg, jstring jtarball, jstring jdirectory)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *tarball;
  const char *directory;

  tarball = (*env)->GetStringUTFChars (env, jtarball, NULL);
  directory = (*env)->GetStringUTFChars (env, jdirectory, NULL);

  r = guestfs_tgz_in (g, tarball, directory);

  (*env)->ReleaseStringUTFChars (env, jtarball, tarball);
  (*env)->ReleaseStringUTFChars (env, jdirectory, directory);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1tgz_1out  (JNIEnv *env, jobject obj, jlong jg, jstring jdirectory, jstring jtarball)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *directory;
  const char *tarball;

  directory = (*env)->GetStringUTFChars (env, jdirectory, NULL);
  tarball = (*env)->GetStringUTFChars (env, jtarball, NULL);

  r = guestfs_tgz_out (g, directory, tarball);

  (*env)->ReleaseStringUTFChars (env, jdirectory, directory);
  (*env)->ReleaseStringUTFChars (env, jtarball, tarball);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1touch  (JNIEnv *env, jobject obj, jlong jg, jstring jpath)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *path;

  path = (*env)->GetStringUTFChars (env, jpath, NULL);

  r = guestfs_touch (g, path);

  (*env)->ReleaseStringUTFChars (env, jpath, path);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1truncate  (JNIEnv *env, jobject obj, jlong jg, jstring jpath)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *path;

  path = (*env)->GetStringUTFChars (env, jpath, NULL);

  r = guestfs_truncate (g, path);

  (*env)->ReleaseStringUTFChars (env, jpath, path);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1truncate_1size  (JNIEnv *env, jobject obj, jlong jg, jstring jpath, jlong jsize)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *path;
  int64_t size;

  path = (*env)->GetStringUTFChars (env, jpath, NULL);
  size = jsize;

  r = guestfs_truncate_size (g, path, size);

  (*env)->ReleaseStringUTFChars (env, jpath, path);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1tune2fs  (JNIEnv *env, jobject obj, jlong jg, jstring jdevice, jlong joptargs_bitmask, jboolean jforce, jint jmaxmountcount, jint jmountcount, jstring jerrorbehavior, jlong jgroup, jint jintervalbetweenchecks, jint jreservedblockspercentage, jstring jlastmounteddirectory, jlong jreservedblockscount, jlong juser)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *device;
  struct guestfs_tune2fs_argv optargs_s;
  const struct guestfs_tune2fs_argv *optargs = &optargs_s;

  device = (*env)->GetStringUTFChars (env, jdevice, NULL);

  optargs_s.force = jforce;
  optargs_s.maxmountcount = jmaxmountcount;
  optargs_s.mountcount = jmountcount;
  optargs_s.errorbehavior = (*env)->GetStringUTFChars (env, jerrorbehavior, NULL);
  optargs_s.group = jgroup;
  optargs_s.intervalbetweenchecks = jintervalbetweenchecks;
  optargs_s.reservedblockspercentage = jreservedblockspercentage;
  optargs_s.lastmounteddirectory = (*env)->GetStringUTFChars (env, jlastmounteddirectory, NULL);
  optargs_s.reservedblockscount = jreservedblockscount;
  optargs_s.user = juser;
  optargs_s.bitmask = joptargs_bitmask;

  r = guestfs_tune2fs_argv (g, device, optargs);

  (*env)->ReleaseStringUTFChars (env, jdevice, device);
  (*env)->ReleaseStringUTFChars (env, jerrorbehavior, optargs_s.errorbehavior);
  (*env)->ReleaseStringUTFChars (env, jlastmounteddirectory, optargs_s.lastmounteddirectory);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT jobject JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1tune2fs_1l  (JNIEnv *env, jobject obj, jlong jg, jstring jdevice)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  jobjectArray jr;
  size_t r_len;
  jclass cl;
  jstring jstr;
  char **r;
  const char *device;
  size_t i;

  device = (*env)->GetStringUTFChars (env, jdevice, NULL);

  r = guestfs_tune2fs_l (g, device);

  (*env)->ReleaseStringUTFChars (env, jdevice, device);

  if (r == NULL) {
    throw_exception (env, guestfs_last_error (g));
    return NULL;
  }
  for (r_len = 0; r[r_len] != NULL; ++r_len) ;
  cl = (*env)->FindClass (env, "java/lang/String");
  jstr = (*env)->NewStringUTF (env, "");
  jr = (*env)->NewObjectArray (env, r_len, cl, jstr);
  for (i = 0; i < r_len; ++i) {
    jstr = (*env)->NewStringUTF (env, r[i]);
    (*env)->SetObjectArrayElement (env, jr, i, jstr);
    free (r[i]);
  }
  free (r);
  return jr;
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1txz_1in  (JNIEnv *env, jobject obj, jlong jg, jstring jtarball, jstring jdirectory)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *tarball;
  const char *directory;

  tarball = (*env)->GetStringUTFChars (env, jtarball, NULL);
  directory = (*env)->GetStringUTFChars (env, jdirectory, NULL);

  r = guestfs_txz_in (g, tarball, directory);

  (*env)->ReleaseStringUTFChars (env, jtarball, tarball);
  (*env)->ReleaseStringUTFChars (env, jdirectory, directory);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1txz_1out  (JNIEnv *env, jobject obj, jlong jg, jstring jdirectory, jstring jtarball)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *directory;
  const char *tarball;

  directory = (*env)->GetStringUTFChars (env, jdirectory, NULL);
  tarball = (*env)->GetStringUTFChars (env, jtarball, NULL);

  r = guestfs_txz_out (g, directory, tarball);

  (*env)->ReleaseStringUTFChars (env, jdirectory, directory);
  (*env)->ReleaseStringUTFChars (env, jtarball, tarball);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT jint JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1umask  (JNIEnv *env, jobject obj, jlong jg, jint jmask)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  int mask;

  mask = jmask;

  r = guestfs_umask (g, mask);


  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return -1;
  }
  return (jint) r;
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1umount  (JNIEnv *env, jobject obj, jlong jg, jstring jpathordevice, jlong joptargs_bitmask, jboolean jforce, jboolean jlazyunmount)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *pathordevice;
  struct guestfs_umount_opts_argv optargs_s;
  const struct guestfs_umount_opts_argv *optargs = &optargs_s;

  pathordevice = (*env)->GetStringUTFChars (env, jpathordevice, NULL);

  optargs_s.force = jforce;
  optargs_s.lazyunmount = jlazyunmount;
  optargs_s.bitmask = joptargs_bitmask;

  r = guestfs_umount_opts_argv (g, pathordevice, optargs);

  (*env)->ReleaseStringUTFChars (env, jpathordevice, pathordevice);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1umount_1all  (JNIEnv *env, jobject obj, jlong jg)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;


  r = guestfs_umount_all (g);


  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1umount_1local  (JNIEnv *env, jobject obj, jlong jg, jlong joptargs_bitmask, jboolean jretry)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  struct guestfs_umount_local_argv optargs_s;
  const struct guestfs_umount_local_argv *optargs = &optargs_s;


  optargs_s.retry = jretry;
  optargs_s.bitmask = joptargs_bitmask;

  r = guestfs_umount_local_argv (g, optargs);


  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1upload  (JNIEnv *env, jobject obj, jlong jg, jstring jfilename, jstring jremotefilename)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *filename;
  const char *remotefilename;

  filename = (*env)->GetStringUTFChars (env, jfilename, NULL);
  remotefilename = (*env)->GetStringUTFChars (env, jremotefilename, NULL);

  r = guestfs_upload (g, filename, remotefilename);

  (*env)->ReleaseStringUTFChars (env, jfilename, filename);
  (*env)->ReleaseStringUTFChars (env, jremotefilename, remotefilename);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1upload_1offset  (JNIEnv *env, jobject obj, jlong jg, jstring jfilename, jstring jremotefilename, jlong joffset)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *filename;
  const char *remotefilename;
  int64_t offset;

  filename = (*env)->GetStringUTFChars (env, jfilename, NULL);
  remotefilename = (*env)->GetStringUTFChars (env, jremotefilename, NULL);
  offset = joffset;

  r = guestfs_upload_offset (g, filename, remotefilename, offset);

  (*env)->ReleaseStringUTFChars (env, jfilename, filename);
  (*env)->ReleaseStringUTFChars (env, jremotefilename, remotefilename);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1user_1cancel  (JNIEnv *env, jobject obj, jlong jg)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;


  r = guestfs_user_cancel (g);


  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1utimens  (JNIEnv *env, jobject obj, jlong jg, jstring jpath, jlong jatsecs, jlong jatnsecs, jlong jmtsecs, jlong jmtnsecs)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *path;
  int64_t atsecs;
  int64_t atnsecs;
  int64_t mtsecs;
  int64_t mtnsecs;

  path = (*env)->GetStringUTFChars (env, jpath, NULL);
  atsecs = jatsecs;
  atnsecs = jatnsecs;
  mtsecs = jmtsecs;
  mtnsecs = jmtnsecs;

  r = guestfs_utimens (g, path, atsecs, atnsecs, mtsecs, mtnsecs);

  (*env)->ReleaseStringUTFChars (env, jpath, path);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT jobject JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1utsname  (JNIEnv *env, jobject obj, jlong jg)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  jobject jr;
  jclass cl;
  jfieldID fl;
  struct guestfs_utsname *r;


  r = guestfs_utsname (g);


  if (r == NULL) {
    throw_exception (env, guestfs_last_error (g));
    return NULL;
  }
  cl = (*env)->FindClass (env, "com/redhat/et/libguestfs/UTSName");
  jr = (*env)->AllocObject (env, cl);
  fl = (*env)->GetFieldID (env, cl, "uts_sysname", "Ljava/lang/String;");
  (*env)->SetObjectField (env, jr, fl, (*env)->NewStringUTF (env, r->uts_sysname));
  fl = (*env)->GetFieldID (env, cl, "uts_release", "Ljava/lang/String;");
  (*env)->SetObjectField (env, jr, fl, (*env)->NewStringUTF (env, r->uts_release));
  fl = (*env)->GetFieldID (env, cl, "uts_version", "Ljava/lang/String;");
  (*env)->SetObjectField (env, jr, fl, (*env)->NewStringUTF (env, r->uts_version));
  fl = (*env)->GetFieldID (env, cl, "uts_machine", "Ljava/lang/String;");
  (*env)->SetObjectField (env, jr, fl, (*env)->NewStringUTF (env, r->uts_machine));
  free (r);
  return jr;
}

JNIEXPORT jobject JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1version  (JNIEnv *env, jobject obj, jlong jg)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  jobject jr;
  jclass cl;
  jfieldID fl;
  struct guestfs_version *r;


  r = guestfs_version (g);


  if (r == NULL) {
    throw_exception (env, guestfs_last_error (g));
    return NULL;
  }
  cl = (*env)->FindClass (env, "com/redhat/et/libguestfs/Version");
  jr = (*env)->AllocObject (env, cl);
  fl = (*env)->GetFieldID (env, cl, "major", "J");
  (*env)->SetLongField (env, jr, fl, r->major);
  fl = (*env)->GetFieldID (env, cl, "minor", "J");
  (*env)->SetLongField (env, jr, fl, r->minor);
  fl = (*env)->GetFieldID (env, cl, "release", "J");
  (*env)->SetLongField (env, jr, fl, r->release);
  fl = (*env)->GetFieldID (env, cl, "extra", "Ljava/lang/String;");
  (*env)->SetObjectField (env, jr, fl, (*env)->NewStringUTF (env, r->extra));
  free (r);
  return jr;
}

JNIEXPORT jstring JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1vfs_1label  (JNIEnv *env, jobject obj, jlong jg, jstring jmountable)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  jstring jr;
  char *r;
  const char *mountable;

  mountable = (*env)->GetStringUTFChars (env, jmountable, NULL);

  r = guestfs_vfs_label (g, mountable);

  (*env)->ReleaseStringUTFChars (env, jmountable, mountable);

  if (r == NULL) {
    throw_exception (env, guestfs_last_error (g));
    return NULL;
  }
  jr = (*env)->NewStringUTF (env, r);
  free (r);
  return jr;
}

JNIEXPORT jstring JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1vfs_1type  (JNIEnv *env, jobject obj, jlong jg, jstring jmountable)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  jstring jr;
  char *r;
  const char *mountable;

  mountable = (*env)->GetStringUTFChars (env, jmountable, NULL);

  r = guestfs_vfs_type (g, mountable);

  (*env)->ReleaseStringUTFChars (env, jmountable, mountable);

  if (r == NULL) {
    throw_exception (env, guestfs_last_error (g));
    return NULL;
  }
  jr = (*env)->NewStringUTF (env, r);
  free (r);
  return jr;
}

JNIEXPORT jstring JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1vfs_1uuid  (JNIEnv *env, jobject obj, jlong jg, jstring jmountable)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  jstring jr;
  char *r;
  const char *mountable;

  mountable = (*env)->GetStringUTFChars (env, jmountable, NULL);

  r = guestfs_vfs_uuid (g, mountable);

  (*env)->ReleaseStringUTFChars (env, jmountable, mountable);

  if (r == NULL) {
    throw_exception (env, guestfs_last_error (g));
    return NULL;
  }
  jr = (*env)->NewStringUTF (env, r);
  free (r);
  return jr;
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1vg_1activate  (JNIEnv *env, jobject obj, jlong jg, jboolean jactivate, jobjectArray jvolgroups)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  int activate;
  size_t volgroups_len;
  char **volgroups;
  size_t i;

  activate = jactivate;
  volgroups_len = (*env)->GetArrayLength (env, jvolgroups);
  volgroups = guestfs___safe_malloc (g, sizeof (char *) * (volgroups_len+1));
  for (i = 0; i < volgroups_len; ++i) {
    jobject o = (*env)->GetObjectArrayElement (env, jvolgroups, i);
    volgroups[i] = (char *) (*env)->GetStringUTFChars (env, o, NULL);
  }
  volgroups[volgroups_len] = NULL;

  r = guestfs_vg_activate (g, activate, volgroups);

  for (i = 0; i < volgroups_len; ++i) {
    jobject o = (*env)->GetObjectArrayElement (env, jvolgroups, i);
    (*env)->ReleaseStringUTFChars (env, o, volgroups[i]);
  }
  free (volgroups);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1vg_1activate_1all  (JNIEnv *env, jobject obj, jlong jg, jboolean jactivate)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  int activate;

  activate = jactivate;

  r = guestfs_vg_activate_all (g, activate);


  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1vgchange_1uuid  (JNIEnv *env, jobject obj, jlong jg, jstring jvg)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *vg;

  vg = (*env)->GetStringUTFChars (env, jvg, NULL);

  r = guestfs_vgchange_uuid (g, vg);

  (*env)->ReleaseStringUTFChars (env, jvg, vg);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1vgchange_1uuid_1all  (JNIEnv *env, jobject obj, jlong jg)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;


  r = guestfs_vgchange_uuid_all (g);


  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1vgcreate  (JNIEnv *env, jobject obj, jlong jg, jstring jvolgroup, jobjectArray jphysvols)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *volgroup;
  size_t physvols_len;
  char **physvols;
  size_t i;

  volgroup = (*env)->GetStringUTFChars (env, jvolgroup, NULL);
  physvols_len = (*env)->GetArrayLength (env, jphysvols);
  physvols = guestfs___safe_malloc (g, sizeof (char *) * (physvols_len+1));
  for (i = 0; i < physvols_len; ++i) {
    jobject o = (*env)->GetObjectArrayElement (env, jphysvols, i);
    physvols[i] = (char *) (*env)->GetStringUTFChars (env, o, NULL);
  }
  physvols[physvols_len] = NULL;

  r = guestfs_vgcreate (g, volgroup, physvols);

  (*env)->ReleaseStringUTFChars (env, jvolgroup, volgroup);
  for (i = 0; i < physvols_len; ++i) {
    jobject o = (*env)->GetObjectArrayElement (env, jphysvols, i);
    (*env)->ReleaseStringUTFChars (env, o, physvols[i]);
  }
  free (physvols);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT jobjectArray JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1vglvuuids  (JNIEnv *env, jobject obj, jlong jg, jstring jvgname)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  jobjectArray jr;
  size_t r_len;
  jclass cl;
  jstring jstr;
  char **r;
  const char *vgname;
  size_t i;

  vgname = (*env)->GetStringUTFChars (env, jvgname, NULL);

  r = guestfs_vglvuuids (g, vgname);

  (*env)->ReleaseStringUTFChars (env, jvgname, vgname);

  if (r == NULL) {
    throw_exception (env, guestfs_last_error (g));
    return NULL;
  }
  for (r_len = 0; r[r_len] != NULL; ++r_len) ;
  cl = (*env)->FindClass (env, "java/lang/String");
  jstr = (*env)->NewStringUTF (env, "");
  jr = (*env)->NewObjectArray (env, r_len, cl, jstr);
  for (i = 0; i < r_len; ++i) {
    jstr = (*env)->NewStringUTF (env, r[i]);
    (*env)->SetObjectArrayElement (env, jr, i, jstr);
    free (r[i]);
  }
  free (r);
  return jr;
}

JNIEXPORT jstring JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1vgmeta  (JNIEnv *env, jobject obj, jlong jg, jstring jvgname)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  jstring jr;
  char *r;
  size_t size;
  const char *vgname;

  vgname = (*env)->GetStringUTFChars (env, jvgname, NULL);

  r = guestfs_vgmeta (g, vgname, &size);

  (*env)->ReleaseStringUTFChars (env, jvgname, vgname);

  if (r == NULL) {
    throw_exception (env, guestfs_last_error (g));
    return NULL;
  }
  jr = (*env)->NewStringUTF (env, r); // XXX size
  free (r);
  return jr;
}

JNIEXPORT jobjectArray JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1vgpvuuids  (JNIEnv *env, jobject obj, jlong jg, jstring jvgname)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  jobjectArray jr;
  size_t r_len;
  jclass cl;
  jstring jstr;
  char **r;
  const char *vgname;
  size_t i;

  vgname = (*env)->GetStringUTFChars (env, jvgname, NULL);

  r = guestfs_vgpvuuids (g, vgname);

  (*env)->ReleaseStringUTFChars (env, jvgname, vgname);

  if (r == NULL) {
    throw_exception (env, guestfs_last_error (g));
    return NULL;
  }
  for (r_len = 0; r[r_len] != NULL; ++r_len) ;
  cl = (*env)->FindClass (env, "java/lang/String");
  jstr = (*env)->NewStringUTF (env, "");
  jr = (*env)->NewObjectArray (env, r_len, cl, jstr);
  for (i = 0; i < r_len; ++i) {
    jstr = (*env)->NewStringUTF (env, r[i]);
    (*env)->SetObjectArrayElement (env, jr, i, jstr);
    free (r[i]);
  }
  free (r);
  return jr;
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1vgremove  (JNIEnv *env, jobject obj, jlong jg, jstring jvgname)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *vgname;

  vgname = (*env)->GetStringUTFChars (env, jvgname, NULL);

  r = guestfs_vgremove (g, vgname);

  (*env)->ReleaseStringUTFChars (env, jvgname, vgname);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1vgrename  (JNIEnv *env, jobject obj, jlong jg, jstring jvolgroup, jstring jnewvolgroup)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *volgroup;
  const char *newvolgroup;

  volgroup = (*env)->GetStringUTFChars (env, jvolgroup, NULL);
  newvolgroup = (*env)->GetStringUTFChars (env, jnewvolgroup, NULL);

  r = guestfs_vgrename (g, volgroup, newvolgroup);

  (*env)->ReleaseStringUTFChars (env, jvolgroup, volgroup);
  (*env)->ReleaseStringUTFChars (env, jnewvolgroup, newvolgroup);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT jobjectArray JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1vgs  (JNIEnv *env, jobject obj, jlong jg)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  jobjectArray jr;
  size_t r_len;
  jclass cl;
  jstring jstr;
  char **r;
  size_t i;


  r = guestfs_vgs (g);


  if (r == NULL) {
    throw_exception (env, guestfs_last_error (g));
    return NULL;
  }
  for (r_len = 0; r[r_len] != NULL; ++r_len) ;
  cl = (*env)->FindClass (env, "java/lang/String");
  jstr = (*env)->NewStringUTF (env, "");
  jr = (*env)->NewObjectArray (env, r_len, cl, jstr);
  for (i = 0; i < r_len; ++i) {
    jstr = (*env)->NewStringUTF (env, r[i]);
    (*env)->SetObjectArrayElement (env, jr, i, jstr);
    free (r[i]);
  }
  free (r);
  return jr;
}

JNIEXPORT jobjectArray JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1vgs_1full  (JNIEnv *env, jobject obj, jlong jg)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  jobjectArray jr;
  jclass cl;
  jfieldID fl;
  jobject jfl;
  struct guestfs_lvm_vg_list *r;
  size_t i;


  r = guestfs_vgs_full (g);


  if (r == NULL) {
    throw_exception (env, guestfs_last_error (g));
    return NULL;
  }
  cl = (*env)->FindClass (env, "com/redhat/et/libguestfs/VG");
  jr = (*env)->NewObjectArray (env, r->len, cl, NULL);

  for (i = 0; i < r->len; ++i) {
    jfl = (*env)->AllocObject (env, cl);

    fl = (*env)->GetFieldID (env, cl, "vg_name",
                             "Ljava/lang/String;");
    (*env)->SetObjectField (env, jfl, fl,
                            (*env)->NewStringUTF (env, r->val[i].vg_name));
    fl = (*env)->GetFieldID (env, cl, "vg_uuid",
                             "Ljava/lang/String;");
    {
      char s[33];
      memcpy (s, r->val[i].vg_uuid, 32);
      s[32] = 0;
      (*env)->SetObjectField (env, jfl, fl,
                              (*env)->NewStringUTF (env, s));
    }
    fl = (*env)->GetFieldID (env, cl, "vg_fmt",
                             "Ljava/lang/String;");
    (*env)->SetObjectField (env, jfl, fl,
                            (*env)->NewStringUTF (env, r->val[i].vg_fmt));
    fl = (*env)->GetFieldID (env, cl, "vg_attr",
                             "Ljava/lang/String;");
    (*env)->SetObjectField (env, jfl, fl,
                            (*env)->NewStringUTF (env, r->val[i].vg_attr));
    fl = (*env)->GetFieldID (env, cl, "vg_size",
                             "J");
    (*env)->SetLongField (env, jfl, fl, r->val[i].vg_size);
    fl = (*env)->GetFieldID (env, cl, "vg_free",
                             "J");
    (*env)->SetLongField (env, jfl, fl, r->val[i].vg_free);
    fl = (*env)->GetFieldID (env, cl, "vg_sysid",
                             "Ljava/lang/String;");
    (*env)->SetObjectField (env, jfl, fl,
                            (*env)->NewStringUTF (env, r->val[i].vg_sysid));
    fl = (*env)->GetFieldID (env, cl, "vg_extent_size",
                             "J");
    (*env)->SetLongField (env, jfl, fl, r->val[i].vg_extent_size);
    fl = (*env)->GetFieldID (env, cl, "vg_extent_count",
                             "J");
    (*env)->SetLongField (env, jfl, fl, r->val[i].vg_extent_count);
    fl = (*env)->GetFieldID (env, cl, "vg_free_count",
                             "J");
    (*env)->SetLongField (env, jfl, fl, r->val[i].vg_free_count);
    fl = (*env)->GetFieldID (env, cl, "max_lv",
                             "J");
    (*env)->SetLongField (env, jfl, fl, r->val[i].max_lv);
    fl = (*env)->GetFieldID (env, cl, "max_pv",
                             "J");
    (*env)->SetLongField (env, jfl, fl, r->val[i].max_pv);
    fl = (*env)->GetFieldID (env, cl, "pv_count",
                             "J");
    (*env)->SetLongField (env, jfl, fl, r->val[i].pv_count);
    fl = (*env)->GetFieldID (env, cl, "lv_count",
                             "J");
    (*env)->SetLongField (env, jfl, fl, r->val[i].lv_count);
    fl = (*env)->GetFieldID (env, cl, "snap_count",
                             "J");
    (*env)->SetLongField (env, jfl, fl, r->val[i].snap_count);
    fl = (*env)->GetFieldID (env, cl, "vg_seqno",
                             "J");
    (*env)->SetLongField (env, jfl, fl, r->val[i].vg_seqno);
    fl = (*env)->GetFieldID (env, cl, "vg_tags",
                             "Ljava/lang/String;");
    (*env)->SetObjectField (env, jfl, fl,
                            (*env)->NewStringUTF (env, r->val[i].vg_tags));
    fl = (*env)->GetFieldID (env, cl, "vg_mda_count",
                             "J");
    (*env)->SetLongField (env, jfl, fl, r->val[i].vg_mda_count);
    fl = (*env)->GetFieldID (env, cl, "vg_mda_free",
                             "J");
    (*env)->SetLongField (env, jfl, fl, r->val[i].vg_mda_free);

    (*env)->SetObjectArrayElement (env, jr, i, jfl);
  }

  guestfs_free_lvm_vg_list (r);
  return jr;
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1vgscan  (JNIEnv *env, jobject obj, jlong jg)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;


  r = guestfs_vgscan (g);


  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT jstring JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1vguuid  (JNIEnv *env, jobject obj, jlong jg, jstring jvgname)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  jstring jr;
  char *r;
  const char *vgname;

  vgname = (*env)->GetStringUTFChars (env, jvgname, NULL);

  r = guestfs_vguuid (g, vgname);

  (*env)->ReleaseStringUTFChars (env, jvgname, vgname);

  if (r == NULL) {
    throw_exception (env, guestfs_last_error (g));
    return NULL;
  }
  jr = (*env)->NewStringUTF (env, r);
  free (r);
  return jr;
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1wait_1ready  (JNIEnv *env, jobject obj, jlong jg)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;


  r = guestfs_wait_ready (g);


  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT jint JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1wc_1c  (JNIEnv *env, jobject obj, jlong jg, jstring jpath)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *path;

  path = (*env)->GetStringUTFChars (env, jpath, NULL);

  r = guestfs_wc_c (g, path);

  (*env)->ReleaseStringUTFChars (env, jpath, path);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return -1;
  }
  return (jint) r;
}

JNIEXPORT jint JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1wc_1l  (JNIEnv *env, jobject obj, jlong jg, jstring jpath)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *path;

  path = (*env)->GetStringUTFChars (env, jpath, NULL);

  r = guestfs_wc_l (g, path);

  (*env)->ReleaseStringUTFChars (env, jpath, path);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return -1;
  }
  return (jint) r;
}

JNIEXPORT jint JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1wc_1w  (JNIEnv *env, jobject obj, jlong jg, jstring jpath)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *path;

  path = (*env)->GetStringUTFChars (env, jpath, NULL);

  r = guestfs_wc_w (g, path);

  (*env)->ReleaseStringUTFChars (env, jpath, path);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return -1;
  }
  return (jint) r;
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1wipefs  (JNIEnv *env, jobject obj, jlong jg, jstring jdevice)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *device;

  device = (*env)->GetStringUTFChars (env, jdevice, NULL);

  r = guestfs_wipefs (g, device);

  (*env)->ReleaseStringUTFChars (env, jdevice, device);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1write  (JNIEnv *env, jobject obj, jlong jg, jstring jpath, jbyteArray jcontent)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *path;
  char *content;
  size_t content_size;

  path = (*env)->GetStringUTFChars (env, jpath, NULL);
  content = (char *) (*env)->GetByteArrayElements (env, jcontent, NULL);
  content_size = (*env)->GetArrayLength (env, jcontent);

  r = guestfs_write (g, path, content, content_size);

  (*env)->ReleaseStringUTFChars (env, jpath, path);
  (*env)->ReleaseByteArrayElements (env, jcontent, (jbyte *) content, 0);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1write_1append  (JNIEnv *env, jobject obj, jlong jg, jstring jpath, jbyteArray jcontent)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *path;
  char *content;
  size_t content_size;

  path = (*env)->GetStringUTFChars (env, jpath, NULL);
  content = (char *) (*env)->GetByteArrayElements (env, jcontent, NULL);
  content_size = (*env)->GetArrayLength (env, jcontent);

  r = guestfs_write_append (g, path, content, content_size);

  (*env)->ReleaseStringUTFChars (env, jpath, path);
  (*env)->ReleaseByteArrayElements (env, jcontent, (jbyte *) content, 0);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1write_1file  (JNIEnv *env, jobject obj, jlong jg, jstring jpath, jstring jcontent, jint jsize)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *path;
  const char *content;
  int size;

  path = (*env)->GetStringUTFChars (env, jpath, NULL);
  content = (*env)->GetStringUTFChars (env, jcontent, NULL);
  size = jsize;

  r = guestfs_write_file (g, path, content, size);

  (*env)->ReleaseStringUTFChars (env, jpath, path);
  (*env)->ReleaseStringUTFChars (env, jcontent, content);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1xfs_1admin  (JNIEnv *env, jobject obj, jlong jg, jstring jdevice, jlong joptargs_bitmask, jboolean jextunwritten, jboolean jimgfile, jboolean jv2log, jboolean jprojid32bit, jboolean jlazycounter, jstring jlabel, jstring juuid)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *device;
  struct guestfs_xfs_admin_argv optargs_s;
  const struct guestfs_xfs_admin_argv *optargs = &optargs_s;

  device = (*env)->GetStringUTFChars (env, jdevice, NULL);

  optargs_s.extunwritten = jextunwritten;
  optargs_s.imgfile = jimgfile;
  optargs_s.v2log = jv2log;
  optargs_s.projid32bit = jprojid32bit;
  optargs_s.lazycounter = jlazycounter;
  optargs_s.label = (*env)->GetStringUTFChars (env, jlabel, NULL);
  optargs_s.uuid = (*env)->GetStringUTFChars (env, juuid, NULL);
  optargs_s.bitmask = joptargs_bitmask;

  r = guestfs_xfs_admin_argv (g, device, optargs);

  (*env)->ReleaseStringUTFChars (env, jdevice, device);
  (*env)->ReleaseStringUTFChars (env, jlabel, optargs_s.label);
  (*env)->ReleaseStringUTFChars (env, juuid, optargs_s.uuid);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1xfs_1growfs  (JNIEnv *env, jobject obj, jlong jg, jstring jpath, jlong joptargs_bitmask, jboolean jdatasec, jboolean jlogsec, jboolean jrtsec, jlong jdatasize, jlong jlogsize, jlong jrtsize, jlong jrtextsize, jint jmaxpct)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *path;
  struct guestfs_xfs_growfs_argv optargs_s;
  const struct guestfs_xfs_growfs_argv *optargs = &optargs_s;

  path = (*env)->GetStringUTFChars (env, jpath, NULL);

  optargs_s.datasec = jdatasec;
  optargs_s.logsec = jlogsec;
  optargs_s.rtsec = jrtsec;
  optargs_s.datasize = jdatasize;
  optargs_s.logsize = jlogsize;
  optargs_s.rtsize = jrtsize;
  optargs_s.rtextsize = jrtextsize;
  optargs_s.maxpct = jmaxpct;
  optargs_s.bitmask = joptargs_bitmask;

  r = guestfs_xfs_growfs_argv (g, path, optargs);

  (*env)->ReleaseStringUTFChars (env, jpath, path);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT jobject JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1xfs_1info  (JNIEnv *env, jobject obj, jlong jg, jstring jpathordevice)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  jobject jr;
  jclass cl;
  jfieldID fl;
  struct guestfs_xfsinfo *r;
  const char *pathordevice;

  pathordevice = (*env)->GetStringUTFChars (env, jpathordevice, NULL);

  r = guestfs_xfs_info (g, pathordevice);

  (*env)->ReleaseStringUTFChars (env, jpathordevice, pathordevice);

  if (r == NULL) {
    throw_exception (env, guestfs_last_error (g));
    return NULL;
  }
  cl = (*env)->FindClass (env, "com/redhat/et/libguestfs/XFSInfo");
  jr = (*env)->AllocObject (env, cl);
  fl = (*env)->GetFieldID (env, cl, "xfs_mntpoint", "Ljava/lang/String;");
  (*env)->SetObjectField (env, jr, fl, (*env)->NewStringUTF (env, r->xfs_mntpoint));
  fl = (*env)->GetFieldID (env, cl, "xfs_inodesize", "I");
  (*env)->SetIntField (env, jr, fl, r->xfs_inodesize);
  fl = (*env)->GetFieldID (env, cl, "xfs_agcount", "I");
  (*env)->SetIntField (env, jr, fl, r->xfs_agcount);
  fl = (*env)->GetFieldID (env, cl, "xfs_agsize", "I");
  (*env)->SetIntField (env, jr, fl, r->xfs_agsize);
  fl = (*env)->GetFieldID (env, cl, "xfs_sectsize", "I");
  (*env)->SetIntField (env, jr, fl, r->xfs_sectsize);
  fl = (*env)->GetFieldID (env, cl, "xfs_attr", "I");
  (*env)->SetIntField (env, jr, fl, r->xfs_attr);
  fl = (*env)->GetFieldID (env, cl, "xfs_blocksize", "I");
  (*env)->SetIntField (env, jr, fl, r->xfs_blocksize);
  fl = (*env)->GetFieldID (env, cl, "xfs_datablocks", "J");
  (*env)->SetLongField (env, jr, fl, r->xfs_datablocks);
  fl = (*env)->GetFieldID (env, cl, "xfs_imaxpct", "I");
  (*env)->SetIntField (env, jr, fl, r->xfs_imaxpct);
  fl = (*env)->GetFieldID (env, cl, "xfs_sunit", "I");
  (*env)->SetIntField (env, jr, fl, r->xfs_sunit);
  fl = (*env)->GetFieldID (env, cl, "xfs_swidth", "I");
  (*env)->SetIntField (env, jr, fl, r->xfs_swidth);
  fl = (*env)->GetFieldID (env, cl, "xfs_dirversion", "I");
  (*env)->SetIntField (env, jr, fl, r->xfs_dirversion);
  fl = (*env)->GetFieldID (env, cl, "xfs_dirblocksize", "I");
  (*env)->SetIntField (env, jr, fl, r->xfs_dirblocksize);
  fl = (*env)->GetFieldID (env, cl, "xfs_cimode", "I");
  (*env)->SetIntField (env, jr, fl, r->xfs_cimode);
  fl = (*env)->GetFieldID (env, cl, "xfs_logname", "Ljava/lang/String;");
  (*env)->SetObjectField (env, jr, fl, (*env)->NewStringUTF (env, r->xfs_logname));
  fl = (*env)->GetFieldID (env, cl, "xfs_logblocksize", "I");
  (*env)->SetIntField (env, jr, fl, r->xfs_logblocksize);
  fl = (*env)->GetFieldID (env, cl, "xfs_logblocks", "I");
  (*env)->SetIntField (env, jr, fl, r->xfs_logblocks);
  fl = (*env)->GetFieldID (env, cl, "xfs_logversion", "I");
  (*env)->SetIntField (env, jr, fl, r->xfs_logversion);
  fl = (*env)->GetFieldID (env, cl, "xfs_logsectsize", "I");
  (*env)->SetIntField (env, jr, fl, r->xfs_logsectsize);
  fl = (*env)->GetFieldID (env, cl, "xfs_logsunit", "I");
  (*env)->SetIntField (env, jr, fl, r->xfs_logsunit);
  fl = (*env)->GetFieldID (env, cl, "xfs_lazycount", "I");
  (*env)->SetIntField (env, jr, fl, r->xfs_lazycount);
  fl = (*env)->GetFieldID (env, cl, "xfs_rtname", "Ljava/lang/String;");
  (*env)->SetObjectField (env, jr, fl, (*env)->NewStringUTF (env, r->xfs_rtname));
  fl = (*env)->GetFieldID (env, cl, "xfs_rtextsize", "I");
  (*env)->SetIntField (env, jr, fl, r->xfs_rtextsize);
  fl = (*env)->GetFieldID (env, cl, "xfs_rtblocks", "J");
  (*env)->SetLongField (env, jr, fl, r->xfs_rtblocks);
  fl = (*env)->GetFieldID (env, cl, "xfs_rtextents", "J");
  (*env)->SetLongField (env, jr, fl, r->xfs_rtextents);
  free (r);
  return jr;
}

JNIEXPORT jint JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1xfs_1repair  (JNIEnv *env, jobject obj, jlong jg, jstring jdevice, jlong joptargs_bitmask, jboolean jforcelogzero, jboolean jnomodify, jboolean jnoprefetch, jboolean jforcegeometry, jlong jmaxmem, jlong jihashsize, jlong jbhashsize, jlong jagstride, jstring jlogdev, jstring jrtdev)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *device;
  struct guestfs_xfs_repair_argv optargs_s;
  const struct guestfs_xfs_repair_argv *optargs = &optargs_s;

  device = (*env)->GetStringUTFChars (env, jdevice, NULL);

  optargs_s.forcelogzero = jforcelogzero;
  optargs_s.nomodify = jnomodify;
  optargs_s.noprefetch = jnoprefetch;
  optargs_s.forcegeometry = jforcegeometry;
  optargs_s.maxmem = jmaxmem;
  optargs_s.ihashsize = jihashsize;
  optargs_s.bhashsize = jbhashsize;
  optargs_s.agstride = jagstride;
  optargs_s.logdev = (*env)->GetStringUTFChars (env, jlogdev, NULL);
  optargs_s.rtdev = (*env)->GetStringUTFChars (env, jrtdev, NULL);
  optargs_s.bitmask = joptargs_bitmask;

  r = guestfs_xfs_repair_argv (g, device, optargs);

  (*env)->ReleaseStringUTFChars (env, jdevice, device);
  (*env)->ReleaseStringUTFChars (env, jlogdev, optargs_s.logdev);
  (*env)->ReleaseStringUTFChars (env, jrtdev, optargs_s.rtdev);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return -1;
  }
  return (jint) r;
}

JNIEXPORT jobjectArray JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1zegrep  (JNIEnv *env, jobject obj, jlong jg, jstring jregex, jstring jpath)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  jobjectArray jr;
  size_t r_len;
  jclass cl;
  jstring jstr;
  char **r;
  const char *regex;
  const char *path;
  size_t i;

  regex = (*env)->GetStringUTFChars (env, jregex, NULL);
  path = (*env)->GetStringUTFChars (env, jpath, NULL);

  r = guestfs_zegrep (g, regex, path);

  (*env)->ReleaseStringUTFChars (env, jregex, regex);
  (*env)->ReleaseStringUTFChars (env, jpath, path);

  if (r == NULL) {
    throw_exception (env, guestfs_last_error (g));
    return NULL;
  }
  for (r_len = 0; r[r_len] != NULL; ++r_len) ;
  cl = (*env)->FindClass (env, "java/lang/String");
  jstr = (*env)->NewStringUTF (env, "");
  jr = (*env)->NewObjectArray (env, r_len, cl, jstr);
  for (i = 0; i < r_len; ++i) {
    jstr = (*env)->NewStringUTF (env, r[i]);
    (*env)->SetObjectArrayElement (env, jr, i, jstr);
    free (r[i]);
  }
  free (r);
  return jr;
}

JNIEXPORT jobjectArray JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1zegrepi  (JNIEnv *env, jobject obj, jlong jg, jstring jregex, jstring jpath)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  jobjectArray jr;
  size_t r_len;
  jclass cl;
  jstring jstr;
  char **r;
  const char *regex;
  const char *path;
  size_t i;

  regex = (*env)->GetStringUTFChars (env, jregex, NULL);
  path = (*env)->GetStringUTFChars (env, jpath, NULL);

  r = guestfs_zegrepi (g, regex, path);

  (*env)->ReleaseStringUTFChars (env, jregex, regex);
  (*env)->ReleaseStringUTFChars (env, jpath, path);

  if (r == NULL) {
    throw_exception (env, guestfs_last_error (g));
    return NULL;
  }
  for (r_len = 0; r[r_len] != NULL; ++r_len) ;
  cl = (*env)->FindClass (env, "java/lang/String");
  jstr = (*env)->NewStringUTF (env, "");
  jr = (*env)->NewObjectArray (env, r_len, cl, jstr);
  for (i = 0; i < r_len; ++i) {
    jstr = (*env)->NewStringUTF (env, r[i]);
    (*env)->SetObjectArrayElement (env, jr, i, jstr);
    free (r[i]);
  }
  free (r);
  return jr;
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1zero  (JNIEnv *env, jobject obj, jlong jg, jstring jdevice)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *device;

  device = (*env)->GetStringUTFChars (env, jdevice, NULL);

  r = guestfs_zero (g, device);

  (*env)->ReleaseStringUTFChars (env, jdevice, device);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1zero_1device  (JNIEnv *env, jobject obj, jlong jg, jstring jdevice)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *device;

  device = (*env)->GetStringUTFChars (env, jdevice, NULL);

  r = guestfs_zero_device (g, device);

  (*env)->ReleaseStringUTFChars (env, jdevice, device);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1zero_1free_1space  (JNIEnv *env, jobject obj, jlong jg, jstring jdirectory)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *directory;

  directory = (*env)->GetStringUTFChars (env, jdirectory, NULL);

  r = guestfs_zero_free_space (g, directory);

  (*env)->ReleaseStringUTFChars (env, jdirectory, directory);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1zerofree  (JNIEnv *env, jobject obj, jlong jg, jstring jdevice)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *device;

  device = (*env)->GetStringUTFChars (env, jdevice, NULL);

  r = guestfs_zerofree (g, device);

  (*env)->ReleaseStringUTFChars (env, jdevice, device);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    return;
  }
}

JNIEXPORT jobjectArray JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1zfgrep  (JNIEnv *env, jobject obj, jlong jg, jstring jpattern, jstring jpath)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  jobjectArray jr;
  size_t r_len;
  jclass cl;
  jstring jstr;
  char **r;
  const char *pattern;
  const char *path;
  size_t i;

  pattern = (*env)->GetStringUTFChars (env, jpattern, NULL);
  path = (*env)->GetStringUTFChars (env, jpath, NULL);

  r = guestfs_zfgrep (g, pattern, path);

  (*env)->ReleaseStringUTFChars (env, jpattern, pattern);
  (*env)->ReleaseStringUTFChars (env, jpath, path);

  if (r == NULL) {
    throw_exception (env, guestfs_last_error (g));
    return NULL;
  }
  for (r_len = 0; r[r_len] != NULL; ++r_len) ;
  cl = (*env)->FindClass (env, "java/lang/String");
  jstr = (*env)->NewStringUTF (env, "");
  jr = (*env)->NewObjectArray (env, r_len, cl, jstr);
  for (i = 0; i < r_len; ++i) {
    jstr = (*env)->NewStringUTF (env, r[i]);
    (*env)->SetObjectArrayElement (env, jr, i, jstr);
    free (r[i]);
  }
  free (r);
  return jr;
}

JNIEXPORT jobjectArray JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1zfgrepi  (JNIEnv *env, jobject obj, jlong jg, jstring jpattern, jstring jpath)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  jobjectArray jr;
  size_t r_len;
  jclass cl;
  jstring jstr;
  char **r;
  const char *pattern;
  const char *path;
  size_t i;

  pattern = (*env)->GetStringUTFChars (env, jpattern, NULL);
  path = (*env)->GetStringUTFChars (env, jpath, NULL);

  r = guestfs_zfgrepi (g, pattern, path);

  (*env)->ReleaseStringUTFChars (env, jpattern, pattern);
  (*env)->ReleaseStringUTFChars (env, jpath, path);

  if (r == NULL) {
    throw_exception (env, guestfs_last_error (g));
    return NULL;
  }
  for (r_len = 0; r[r_len] != NULL; ++r_len) ;
  cl = (*env)->FindClass (env, "java/lang/String");
  jstr = (*env)->NewStringUTF (env, "");
  jr = (*env)->NewObjectArray (env, r_len, cl, jstr);
  for (i = 0; i < r_len; ++i) {
    jstr = (*env)->NewStringUTF (env, r[i]);
    (*env)->SetObjectArrayElement (env, jr, i, jstr);
    free (r[i]);
  }
  free (r);
  return jr;
}

JNIEXPORT jstring JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1zfile  (JNIEnv *env, jobject obj, jlong jg, jstring jmeth, jstring jpath)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  jstring jr;
  char *r;
  const char *meth;
  const char *path;

  meth = (*env)->GetStringUTFChars (env, jmeth, NULL);
  path = (*env)->GetStringUTFChars (env, jpath, NULL);

  r = guestfs_zfile (g, meth, path);

  (*env)->ReleaseStringUTFChars (env, jmeth, meth);
  (*env)->ReleaseStringUTFChars (env, jpath, path);

  if (r == NULL) {
    throw_exception (env, guestfs_last_error (g));
    return NULL;
  }
  jr = (*env)->NewStringUTF (env, r);
  free (r);
  return jr;
}

JNIEXPORT jobjectArray JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1zgrep  (JNIEnv *env, jobject obj, jlong jg, jstring jregex, jstring jpath)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  jobjectArray jr;
  size_t r_len;
  jclass cl;
  jstring jstr;
  char **r;
  const char *regex;
  const char *path;
  size_t i;

  regex = (*env)->GetStringUTFChars (env, jregex, NULL);
  path = (*env)->GetStringUTFChars (env, jpath, NULL);

  r = guestfs_zgrep (g, regex, path);

  (*env)->ReleaseStringUTFChars (env, jregex, regex);
  (*env)->ReleaseStringUTFChars (env, jpath, path);

  if (r == NULL) {
    throw_exception (env, guestfs_last_error (g));
    return NULL;
  }
  for (r_len = 0; r[r_len] != NULL; ++r_len) ;
  cl = (*env)->FindClass (env, "java/lang/String");
  jstr = (*env)->NewStringUTF (env, "");
  jr = (*env)->NewObjectArray (env, r_len, cl, jstr);
  for (i = 0; i < r_len; ++i) {
    jstr = (*env)->NewStringUTF (env, r[i]);
    (*env)->SetObjectArrayElement (env, jr, i, jstr);
    free (r[i]);
  }
  free (r);
  return jr;
}

JNIEXPORT jobjectArray JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1zgrepi  (JNIEnv *env, jobject obj, jlong jg, jstring jregex, jstring jpath)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  jobjectArray jr;
  size_t r_len;
  jclass cl;
  jstring jstr;
  char **r;
  const char *regex;
  const char *path;
  size_t i;

  regex = (*env)->GetStringUTFChars (env, jregex, NULL);
  path = (*env)->GetStringUTFChars (env, jpath, NULL);

  r = guestfs_zgrepi (g, regex, path);

  (*env)->ReleaseStringUTFChars (env, jregex, regex);
  (*env)->ReleaseStringUTFChars (env, jpath, path);

  if (r == NULL) {
    throw_exception (env, guestfs_last_error (g));
    return NULL;
  }
  for (r_len = 0; r[r_len] != NULL; ++r_len) ;
  cl = (*env)->FindClass (env, "java/lang/String");
  jstr = (*env)->NewStringUTF (env, "");
  jr = (*env)->NewObjectArray (env, r_len, cl, jstr);
  for (i = 0; i < r_len; ++i) {
    jstr = (*env)->NewStringUTF (env, r[i]);
    (*env)->SetObjectArrayElement (env, jr, i, jstr);
    free (r[i]);
  }
  free (r);
  return jr;
}

