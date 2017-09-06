/* libguestfs generated file
 * WARNING: THIS FILE IS GENERATED FROM THE FOLLOWING FILES:
 *          generator/java.ml
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
#include <string.h>
#include <inttypes.h>

#include "com_redhat_et_libguestfs_GuestFS.h"
#include "guestfs.h"
#include "guestfs-internal-frontend.h"

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

/* Note that this function returns.  The exception is not thrown
 * until after the wrapper function returns.
 */
static void
throw_out_of_memory (JNIEnv *env, const char *msg)
{
  jclass cl;
  cl = (*env)->FindClass (env,
                          "com/redhat/et/libguestfs/LibGuestFSOutOfMemory");
  (*env)->ThrowNew (env, cl, msg);
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
  CLEANUP_FREE char **server = NULL;
  size_t i;

  filename = (*env)->GetStringUTFChars (env, jfilename, NULL);

  optargs_s.readonly = jreadonly;
  optargs_s.format = (*env)->GetStringUTFChars (env, jformat, NULL);
  optargs_s.iface = (*env)->GetStringUTFChars (env, jiface, NULL);
  optargs_s.name = (*env)->GetStringUTFChars (env, jname, NULL);
  optargs_s.label = (*env)->GetStringUTFChars (env, jlabel, NULL);
  optargs_s.protocol = (*env)->GetStringUTFChars (env, jprotocol, NULL);
  server_len = (*env)->GetArrayLength (env, jserver);
  server = malloc (sizeof (char *) * (server_len+1));
  if (server == NULL) {
    throw_out_of_memory (env, "malloc");
    goto ret_error;
  }
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
  (*env)->ReleaseStringUTFChars (env, jusername, optargs_s.username);
  (*env)->ReleaseStringUTFChars (env, jsecret, optargs_s.secret);
  (*env)->ReleaseStringUTFChars (env, jcachemode, optargs_s.cachemode);
  (*env)->ReleaseStringUTFChars (env, jdiscard, optargs_s.discard);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    goto ret_error;
  }
  return;

 ret_error:
  return;
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
    goto ret_error;
  }
  return;

 ret_error:
  return;
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
    goto ret_error;
  }
  jr = (*env)->NewStringUTF (env, r);
  free (r);
  return jr;

 ret_error:
  return NULL;
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
    goto ret_error;
  }
  return (jboolean) r;

 ret_error:
  return -1;
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
    goto ret_error;
  }
  return (jlong) r;

 ret_error:
  return -1;
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
    goto ret_error;
  }
  return (jint) r;

 ret_error:
  return -1;
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
    goto ret_error;
  }
  return;

 ret_error:
  return;
}


JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1btrfs_1balance_1cancel  (JNIEnv *env, jobject obj, jlong jg, jstring jpath)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *path;

  path = (*env)->GetStringUTFChars (env, jpath, NULL);

  r = guestfs_btrfs_balance_cancel (g, path);

  (*env)->ReleaseStringUTFChars (env, jpath, path);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    goto ret_error;
  }
  return;

 ret_error:
  return;
}


JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1btrfs_1qgroup_1limit  (JNIEnv *env, jobject obj, jlong jg, jstring jsubvolume, jlong jsize)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *subvolume;
  int64_t size;

  subvolume = (*env)->GetStringUTFChars (env, jsubvolume, NULL);
  size = jsize;

  r = guestfs_btrfs_qgroup_limit (g, subvolume, size);

  (*env)->ReleaseStringUTFChars (env, jsubvolume, subvolume);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    goto ret_error;
  }
  return;

 ret_error:
  return;
}


JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1btrfs_1quota_1rescan  (JNIEnv *env, jobject obj, jlong jg, jstring jfs)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *fs;

  fs = (*env)->GetStringUTFChars (env, jfs, NULL);

  r = guestfs_btrfs_quota_rescan (g, fs);

  (*env)->ReleaseStringUTFChars (env, jfs, fs);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    goto ret_error;
  }
  return;

 ret_error:
  return;
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
    goto ret_error;
  }
  return;

 ret_error:
  return;
}


JNIEXPORT jobject JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1btrfs_1subvolume_1show  (JNIEnv *env, jobject obj, jlong jg, jstring jsubvolume)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  jobjectArray jr;
  size_t r_len;
  jclass cl;
  jstring jstr;
  char **r;
  const char *subvolume;
  size_t i;

  subvolume = (*env)->GetStringUTFChars (env, jsubvolume, NULL);

  r = guestfs_btrfs_subvolume_show (g, subvolume);

  (*env)->ReleaseStringUTFChars (env, jsubvolume, subvolume);

  if (r == NULL) {
    throw_exception (env, guestfs_last_error (g));
    goto ret_error;
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

 ret_error:
  return NULL;
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
    goto ret_error;
  }
  return;

 ret_error:
  return;
}


JNIEXPORT jstring JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1command  (JNIEnv *env, jobject obj, jlong jg, jobjectArray jarguments)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  jstring jr;
  char *r;
  size_t arguments_len;
  CLEANUP_FREE char **arguments = NULL;
  size_t i;

  arguments_len = (*env)->GetArrayLength (env, jarguments);
  arguments = malloc (sizeof (char *) * (arguments_len+1));
  if (arguments == NULL) {
    throw_out_of_memory (env, "malloc");
    goto ret_error;
  }
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

  if (r == NULL) {
    throw_exception (env, guestfs_last_error (g));
    goto ret_error;
  }
  jr = (*env)->NewStringUTF (env, r);
  free (r);
  return jr;

 ret_error:
  return NULL;
}


JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1copy_1device_1to_1file  (JNIEnv *env, jobject obj, jlong jg, jstring jsrc, jstring jdest, jlong joptargs_bitmask, jlong jsrcoffset, jlong jdestoffset, jlong jsize, jboolean jsparse, jboolean jappend)
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
  optargs_s.append = jappend;
  optargs_s.bitmask = joptargs_bitmask;

  r = guestfs_copy_device_to_file_argv (g, src, dest, optargs);

  (*env)->ReleaseStringUTFChars (env, jsrc, src);
  (*env)->ReleaseStringUTFChars (env, jdest, dest);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    goto ret_error;
  }
  return;

 ret_error:
  return;
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
    goto ret_error;
  }
  return;

 ret_error:
  return;
}


JNIEXPORT jstring JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1debug  (JNIEnv *env, jobject obj, jlong jg, jstring jsubcmd, jobjectArray jextraargs)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  jstring jr;
  char *r;
  const char *subcmd;
  size_t extraargs_len;
  CLEANUP_FREE char **extraargs = NULL;
  size_t i;

  subcmd = (*env)->GetStringUTFChars (env, jsubcmd, NULL);
  extraargs_len = (*env)->GetArrayLength (env, jextraargs);
  extraargs = malloc (sizeof (char *) * (extraargs_len+1));
  if (extraargs == NULL) {
    throw_out_of_memory (env, "malloc");
    goto ret_error;
  }
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

  if (r == NULL) {
    throw_exception (env, guestfs_last_error (g));
    goto ret_error;
  }
  jr = (*env)->NewStringUTF (env, r);
  free (r);
  return jr;

 ret_error:
  return NULL;
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
    goto ret_error;
  }
  return;

 ret_error:
  return;
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
    goto ret_error;
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

 ret_error:
  return NULL;
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
    goto ret_error;
  }
  jr = (*env)->NewStringUTF (env, r);
  free (r);
  return jr;

 ret_error:
  return NULL;
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
    goto ret_error;
  }
  jr = (*env)->NewStringUTF (env, r);
  free (r);
  return jr;

 ret_error:
  return NULL;
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
    goto ret_error;
  }
  jr = (*env)->NewStringUTF (env, r);
  free (r);
  return jr;

 ret_error:
  return NULL;
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
    goto ret_error;
  }
  return (jlong) r;

 ret_error:
  return -1;
}


JNIEXPORT jobjectArray JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1glob_1expand  (JNIEnv *env, jobject obj, jlong jg, jstring jpattern, jlong joptargs_bitmask, jboolean jdirectoryslash)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  jobjectArray jr;
  size_t r_len;
  jclass cl;
  jstring jstr;
  char **r;
  const char *pattern;
  struct guestfs_glob_expand_opts_argv optargs_s;
  const struct guestfs_glob_expand_opts_argv *optargs = &optargs_s;
  size_t i;

  pattern = (*env)->GetStringUTFChars (env, jpattern, NULL);

  optargs_s.directoryslash = jdirectoryslash;
  optargs_s.bitmask = joptargs_bitmask;

  r = guestfs_glob_expand_opts_argv (g, pattern, optargs);

  (*env)->ReleaseStringUTFChars (env, jpattern, pattern);

  if (r == NULL) {
    throw_exception (env, guestfs_last_error (g));
    goto ret_error;
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

 ret_error:
  return NULL;
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
    goto ret_error;
  }
  return;

 ret_error:
  return;
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
    goto ret_error;
  }
  return (jlong) r;

 ret_error:
  return -1;
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
    goto ret_error;
  }
  return (jlong) r;

 ret_error:
  return -1;
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
    goto ret_error;
  }
  jr = (*env)->NewStringUTF (env, r);
  free (r);
  return jr;

 ret_error:
  return NULL;
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
    goto ret_error;
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

 ret_error:
  return NULL;
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
    goto ret_error;
  }
  jr = (*env)->NewStringUTF (env, r);
  free (r);
  return jr;

 ret_error:
  return NULL;
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
    goto ret_error;
  }
  jr = (*env)->NewStringUTF (env, r);
  free (r);
  return jr;

 ret_error:
  return NULL;
}


JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1internal_1test_1close_1output  (JNIEnv *env, jobject obj, jlong jg)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;


  r = guestfs_internal_test_close_output (g);


  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    goto ret_error;
  }
  return;

 ret_error:
  return;
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
    goto ret_error;
  }
  jr = (*env)->NewStringUTF (env, r); // XXX size
  free (r);
  return jr;

 ret_error:
  return NULL;
}


JNIEXPORT jstring JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1internal_1test_1rconstoptstringerr  (JNIEnv *env, jobject obj, jlong jg)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  const char *r;


  r = guestfs_internal_test_rconstoptstringerr (g);


  return (*env)->NewStringUTF (env, r); /* XXX r NULL? */
}


JNIEXPORT jint JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1internal_1test_1rinterr  (JNIEnv *env, jobject obj, jlong jg)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;


  r = guestfs_internal_test_rinterr (g);


  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    goto ret_error;
  }
  return (jint) r;

 ret_error:
  return -1;
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
    goto ret_error;
  }
  return;

 ret_error:
  return;
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
    goto ret_error;
  }
  return (jboolean) r;

 ret_error:
  return -1;
}


JNIEXPORT jboolean JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1is_1launching  (JNIEnv *env, jobject obj, jlong jg)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;


  r = guestfs_is_launching (g);


  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    goto ret_error;
  }
  return (jboolean) r;

 ret_error:
  return -1;
}


JNIEXPORT jboolean JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1is_1lv  (JNIEnv *env, jobject obj, jlong jg, jstring jmountable)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *mountable;

  mountable = (*env)->GetStringUTFChars (env, jmountable, NULL);

  r = guestfs_is_lv (g, mountable);

  (*env)->ReleaseStringUTFChars (env, jmountable, mountable);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    goto ret_error;
  }
  return (jboolean) r;

 ret_error:
  return -1;
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
    goto ret_error;
  }
  return (jboolean) r;

 ret_error:
  return -1;
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
    goto ret_error;
  }
  return;

 ret_error:
  return;
}


JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1kill_1subprocess  (JNIEnv *env, jobject obj, jlong jg)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;


  r = guestfs_kill_subprocess (g);


  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    goto ret_error;
  }
  return;

 ret_error:
  return;
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
  CLEANUP_FREE char **devices = NULL;
  size_t i;

  devices_len = (*env)->GetArrayLength (env, jdevices);
  devices = malloc (sizeof (char *) * (devices_len+1));
  if (devices == NULL) {
    throw_out_of_memory (env, "malloc");
    goto ret_error;
  }
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

  if (r == NULL) {
    throw_exception (env, guestfs_last_error (g));
    goto ret_error;
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

 ret_error:
  return NULL;
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
    goto ret_error;
  }
  return;

 ret_error:
  return;
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
    goto ret_error;
  }
  return;

 ret_error:
  return;
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
    goto ret_error;
  }
  return;

 ret_error:
  return;
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
    goto ret_error;
  }
  return;

 ret_error:
  return;
}


JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1mksquashfs  (JNIEnv *env, jobject obj, jlong jg, jstring jpath, jstring jfilename, jlong joptargs_bitmask, jstring jcompress, jobjectArray jexcludes)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *path;
  const char *filename;
  struct guestfs_mksquashfs_argv optargs_s;
  const struct guestfs_mksquashfs_argv *optargs = &optargs_s;
  size_t excludes_len;
  CLEANUP_FREE char **excludes = NULL;
  size_t i;

  path = (*env)->GetStringUTFChars (env, jpath, NULL);
  filename = (*env)->GetStringUTFChars (env, jfilename, NULL);

  optargs_s.compress = (*env)->GetStringUTFChars (env, jcompress, NULL);
  excludes_len = (*env)->GetArrayLength (env, jexcludes);
  excludes = malloc (sizeof (char *) * (excludes_len+1));
  if (excludes == NULL) {
    throw_out_of_memory (env, "malloc");
    goto ret_error;
  }
  for (i = 0; i < excludes_len; ++i) {
    jobject o = (*env)->GetObjectArrayElement (env, jexcludes, i);
    excludes[i] = (char *) (*env)->GetStringUTFChars (env, o, NULL);
  }
  excludes[excludes_len] = NULL;
  optargs_s.excludes = excludes;
  optargs_s.bitmask = joptargs_bitmask;

  r = guestfs_mksquashfs_argv (g, path, filename, optargs);

  (*env)->ReleaseStringUTFChars (env, jpath, path);
  (*env)->ReleaseStringUTFChars (env, jfilename, filename);
  (*env)->ReleaseStringUTFChars (env, jcompress, optargs_s.compress);
  for (i = 0; i < excludes_len; ++i) {
    jobject o = (*env)->GetObjectArrayElement (env, jexcludes, i);
    (*env)->ReleaseStringUTFChars (env, o, optargs_s.excludes[i]);
  }

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    goto ret_error;
  }
  return;

 ret_error:
  return;
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
    goto ret_error;
  }
  return;

 ret_error:
  return;
}


JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1ntfscat_1i  (JNIEnv *env, jobject obj, jlong jg, jstring jdevice, jlong jinode, jstring jfilename)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *device;
  int64_t inode;
  const char *filename;

  device = (*env)->GetStringUTFChars (env, jdevice, NULL);
  inode = jinode;
  filename = (*env)->GetStringUTFChars (env, jfilename, NULL);

  r = guestfs_ntfscat_i (g, device, inode, filename);

  (*env)->ReleaseStringUTFChars (env, jdevice, device);
  (*env)->ReleaseStringUTFChars (env, jfilename, filename);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    goto ret_error;
  }
  return;

 ret_error:
  return;
}


JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1parse_1environment  (JNIEnv *env, jobject obj, jlong jg)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;


  r = guestfs_parse_environment (g);


  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    goto ret_error;
  }
  return;

 ret_error:
  return;
}


JNIEXPORT jstring JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1part_1get_1disk_1guid  (JNIEnv *env, jobject obj, jlong jg, jstring jdevice)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  jstring jr;
  char *r;
  const char *device;

  device = (*env)->GetStringUTFChars (env, jdevice, NULL);

  r = guestfs_part_get_disk_guid (g, device);

  (*env)->ReleaseStringUTFChars (env, jdevice, device);

  if (r == NULL) {
    throw_exception (env, guestfs_last_error (g));
    goto ret_error;
  }
  jr = (*env)->NewStringUTF (env, r);
  free (r);
  return jr;

 ret_error:
  return NULL;
}


JNIEXPORT jobjectArray JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1part_1list  (JNIEnv *env, jobject obj, jlong jg, jstring jdevice)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  jobjectArray jr;
  jclass cl;
  jfieldID fl;
  jobject jfl;
  CLEANUP_FREE_PARTITION_LIST struct guestfs_partition_list *r = NULL;
  const char *device;
  size_t i;

  device = (*env)->GetStringUTFChars (env, jdevice, NULL);

  r = guestfs_part_list (g, device);

  (*env)->ReleaseStringUTFChars (env, jdevice, device);

  if (r == NULL) {
    throw_exception (env, guestfs_last_error (g));
    goto ret_error;
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

  return jr;

 ret_error:
  return NULL;
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
    goto ret_error;
  }
  return;

 ret_error:
  return;
}


JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1part_1set_1gpt_1guid  (JNIEnv *env, jobject obj, jlong jg, jstring jdevice, jint jpartnum, jstring jguid)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *device;
  int partnum;
  const char *guid;

  device = (*env)->GetStringUTFChars (env, jdevice, NULL);
  partnum = jpartnum;
  guid = (*env)->GetStringUTFChars (env, jguid, NULL);

  r = guestfs_part_set_gpt_guid (g, device, partnum, guid);

  (*env)->ReleaseStringUTFChars (env, jdevice, device);
  (*env)->ReleaseStringUTFChars (env, jguid, guid);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    goto ret_error;
  }
  return;

 ret_error:
  return;
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
    goto ret_error;
  }
  jr = (*env)->NewStringUTF (env, r);
  free (r);
  return jr;

 ret_error:
  return NULL;
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
    goto ret_error;
  }
  return;

 ret_error:
  return;
}


JNIEXPORT jobjectArray JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1pvs_1full  (JNIEnv *env, jobject obj, jlong jg)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  jobjectArray jr;
  jclass cl;
  jfieldID fl;
  jobject jfl;
  CLEANUP_FREE_LVM_PV_LIST struct guestfs_lvm_pv_list *r = NULL;
  size_t i;


  r = guestfs_pvs_full (g);


  if (r == NULL) {
    throw_exception (env, guestfs_last_error (g));
    goto ret_error;
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

  return jr;

 ret_error:
  return NULL;
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
    goto ret_error;
  }
  return (jint) r;

 ret_error:
  return -1;
}


JNIEXPORT jobjectArray JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1readdir  (JNIEnv *env, jobject obj, jlong jg, jstring jdir)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  jobjectArray jr;
  jclass cl;
  jfieldID fl;
  jobject jfl;
  CLEANUP_FREE_DIRENT_LIST struct guestfs_dirent_list *r = NULL;
  const char *dir;
  size_t i;

  dir = (*env)->GetStringUTFChars (env, jdir, NULL);

  r = guestfs_readdir (g, dir);

  (*env)->ReleaseStringUTFChars (env, jdir, dir);

  if (r == NULL) {
    throw_exception (env, guestfs_last_error (g));
    goto ret_error;
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

  return jr;

 ret_error:
  return NULL;
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
    goto ret_error;
  }
  jr = (*env)->NewStringUTF (env, r);
  free (r);
  return jr;

 ret_error:
  return NULL;
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
    goto ret_error;
  }
  return;

 ret_error:
  return;
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
    goto ret_error;
  }
  return;

 ret_error:
  return;
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
    goto ret_error;
  }
  return;

 ret_error:
  return;
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
    goto ret_error;
  }
  return;

 ret_error:
  return;
}


JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1set_1libvirt_1supported_1credentials  (JNIEnv *env, jobject obj, jlong jg, jobjectArray jcreds)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  size_t creds_len;
  CLEANUP_FREE char **creds = NULL;
  size_t i;

  creds_len = (*env)->GetArrayLength (env, jcreds);
  creds = malloc (sizeof (char *) * (creds_len+1));
  if (creds == NULL) {
    throw_out_of_memory (env, "malloc");
    goto ret_error;
  }
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

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    goto ret_error;
  }
  return;

 ret_error:
  return;
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
    goto ret_error;
  }
  return;

 ret_error:
  return;
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
    goto ret_error;
  }
  return;

 ret_error:
  return;
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
    goto ret_error;
  }
  jr = (*env)->NewStringUTF (env, r);
  free (r);
  return jr;

 ret_error:
  return NULL;
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
    goto ret_error;
  }
  jr = (*env)->NewStringUTF (env, r);
  free (r);
  return jr;

 ret_error:
  return NULL;
}


JNIEXPORT jobject JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1statns  (JNIEnv *env, jobject obj, jlong jg, jstring jpath)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  jobject jr;
  jclass cl;
  jfieldID fl;
  CLEANUP_FREE_STATNS struct guestfs_statns *r = NULL;
  const char *path;

  path = (*env)->GetStringUTFChars (env, jpath, NULL);

  r = guestfs_statns (g, path);

  (*env)->ReleaseStringUTFChars (env, jpath, path);

  if (r == NULL) {
    throw_exception (env, guestfs_last_error (g));
    goto ret_error;
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
  return jr;

 ret_error:
  return NULL;
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
    goto ret_error;
  }
  return;

 ret_error:
  return;
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
    goto ret_error;
  }
  return;

 ret_error:
  return;
}


JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1umount_1all  (JNIEnv *env, jobject obj, jlong jg)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;


  r = guestfs_umount_all (g);


  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    goto ret_error;
  }
  return;

 ret_error:
  return;
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
    goto ret_error;
  }
  return;

 ret_error:
  return;
}


JNIEXPORT jobject JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1utsname  (JNIEnv *env, jobject obj, jlong jg)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  jobject jr;
  jclass cl;
  jfieldID fl;
  CLEANUP_FREE_UTSNAME struct guestfs_utsname *r = NULL;


  r = guestfs_utsname (g);


  if (r == NULL) {
    throw_exception (env, guestfs_last_error (g));
    goto ret_error;
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
  return jr;

 ret_error:
  return NULL;
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
    goto ret_error;
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

 ret_error:
  return NULL;
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
    goto ret_error;
  }
  return;

 ret_error:
  return;
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
    goto ret_error;
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

 ret_error:
  return NULL;
}

