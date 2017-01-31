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
    goto ret_error;
  }
  return;

 ret_error:
  return;
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
    goto ret_error;
  }
  return (jint) r;

 ret_error:
  return -1;
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
    goto ret_error;
  }
  return (jboolean) r;

 ret_error:
  return -1;
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
    goto ret_error;
  }
  return;

 ret_error:
  return;
}


JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1btrfs_1qgroup_1remove  (JNIEnv *env, jobject obj, jlong jg, jstring jsrc, jstring jdst, jstring jpath)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *src;
  const char *dst;
  const char *path;

  src = (*env)->GetStringUTFChars (env, jsrc, NULL);
  dst = (*env)->GetStringUTFChars (env, jdst, NULL);
  path = (*env)->GetStringUTFChars (env, jpath, NULL);

  r = guestfs_btrfs_qgroup_remove (g, src, dst, path);

  (*env)->ReleaseStringUTFChars (env, jsrc, src);
  (*env)->ReleaseStringUTFChars (env, jdst, dst);
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
Java_com_redhat_et_libguestfs_GuestFS__1btrfs_1quota_1enable  (JNIEnv *env, jobject obj, jlong jg, jstring jfs, jboolean jenable)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *fs;
  int enable;

  fs = (*env)->GetStringUTFChars (env, jfs, NULL);
  enable = jenable;

  r = guestfs_btrfs_quota_enable (g, fs, enable);

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
    goto ret_error;
  }
  return;

 ret_error:
  return;
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
    goto ret_error;
  }
  return;

 ret_error:
  return;
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
    goto ret_error;
  }
  jr = (*env)->NewStringUTF (env, r);
  free (r);
  return jr;

 ret_error:
  return NULL;
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
    goto ret_error;
  }
  jr = (*env)->NewStringUTF (env, r);
  free (r);
  return jr;

 ret_error:
  return NULL;
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
    goto ret_error;
  }
  return;

 ret_error:
  return;
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
    goto ret_error;
  }
  return;

 ret_error:
  return;
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
    goto ret_error;
  }
  jr = (*env)->NewStringUTF (env, r);
  free (r);
  return jr;

 ret_error:
  return NULL;
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
    goto ret_error;
  }
  return (jlong) r;

 ret_error:
  return -1;
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
    goto ret_error;
  }
  return (jboolean) r;

 ret_error:
  return -1;
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
    goto ret_error;
  }
  return;

 ret_error:
  return;
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


JNIEXPORT jboolean JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1get_1direct  (JNIEnv *env, jobject obj, jlong jg)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;


  r = guestfs_get_direct (g);


  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    goto ret_error;
  }
  return (jboolean) r;

 ret_error:
  return -1;
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
    goto ret_error;
  }
  jr = (*env)->NewStringUTF (env, r);
  free (r);
  return jr;

 ret_error:
  return NULL;
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
    goto ret_error;
  }
  jr = (*env)->NewStringUTF (env, r);
  free (r);
  return jr;

 ret_error:
  return NULL;
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
    goto ret_error;
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

 ret_error:
  return NULL;
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
    goto ret_error;
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

 ret_error:
  return NULL;
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
    goto ret_error;
  }
  jr = (*env)->NewStringUTF (env, r);
  free (r);
  return jr;

 ret_error:
  return NULL;
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
    goto ret_error;
  }
  jr = (*env)->NewStringUTF (env, r);
  free (r);
  return jr;

 ret_error:
  return NULL;
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
    goto ret_error;
  }
  return (*env)->NewStringUTF (env, r);

 ret_error:
  return NULL;
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
    goto ret_error;
  }
  return (jint) r;

 ret_error:
  return -1;
}


JNIEXPORT jlong JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1internal_1test_1rint64err  (JNIEnv *env, jobject obj, jlong jg)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int64_t r;


  r = guestfs_internal_test_rint64err (g);


  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    goto ret_error;
  }
  return (jlong) r;

 ret_error:
  return -1;
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
    goto ret_error;
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
  guestfs_free_lvm_pv (r);
  return jr;

 ret_error:
  return NULL;
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
    goto ret_error;
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
  guestfs_free_isoinfo (r);
  return jr;

 ret_error:
  return NULL;
}


JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1journal_1close  (JNIEnv *env, jobject obj, jlong jg)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;


  r = guestfs_journal_close (g);


  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    goto ret_error;
  }
  return;

 ret_error:
  return;
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
    goto ret_error;
  }
  jr = (*env)->NewStringUTF (env, r); // XXX size
  free (r);
  return jr;

 ret_error:
  return NULL;
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
    goto ret_error;
  }
  return;

 ret_error:
  return;
}


JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1lvm_1clear_1filter  (JNIEnv *env, jobject obj, jlong jg)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;


  r = guestfs_lvm_clear_filter (g);


  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    goto ret_error;
  }
  return;

 ret_error:
  return;
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


JNIEXPORT jint JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1max_1disks  (JNIEnv *env, jobject obj, jlong jg)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;


  r = guestfs_max_disks (g);


  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    goto ret_error;
  }
  return (jint) r;

 ret_error:
  return -1;
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
    goto ret_error;
  }
  return;

 ret_error:
  return;
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
    goto ret_error;
  }
  return;

 ret_error:
  return;
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
    goto ret_error;
  }
  return;

 ret_error:
  return;
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
    goto ret_error;
  }
  jr = (*env)->NewStringUTF (env, r);
  free (r);
  return jr;

 ret_error:
  return NULL;
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
    goto ret_error;
  }
  return;

 ret_error:
  return;
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
    goto ret_error;
  }
  return;

 ret_error:
  return;
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
    goto ret_error;
  }
  return;

 ret_error:
  return;
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
    goto ret_error;
  }
  jr = (*env)->NewStringUTF (env, r); // XXX size
  free (r);
  return jr;

 ret_error:
  return NULL;
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
    goto ret_error;
  }
  return;

 ret_error:
  return;
}


JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1pvchange_1uuid_1all  (JNIEnv *env, jobject obj, jlong jg)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;


  r = guestfs_pvchange_uuid_all (g);


  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    goto ret_error;
  }
  return;

 ret_error:
  return;
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
    goto ret_error;
  }
  return;

 ret_error:
  return;
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
    goto ret_error;
  }
  return;

 ret_error:
  return;
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
    goto ret_error;
  }
  return;

 ret_error:
  return;
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
    goto ret_error;
  }
  return;

 ret_error:
  return;
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
    goto ret_error;
  }
  return;

 ret_error:
  return;
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
    goto ret_error;
  }
  return;

 ret_error:
  return;
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
    goto ret_error;
  }
  return;

 ret_error:
  return;
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
    goto ret_error;
  }
  return;

 ret_error:
  return;
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
    goto ret_error;
  }
  jr = (*env)->NewStringUTF (env, r);
  free (r);
  return jr;

 ret_error:
  return NULL;
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
    goto ret_error;
  }
  return;

 ret_error:
  return;
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
Java_com_redhat_et_libguestfs_GuestFS__1sync  (JNIEnv *env, jobject obj, jlong jg)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;


  r = guestfs_sync (g);


  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    goto ret_error;
  }
  return;

 ret_error:
  return;
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
Java_com_redhat_et_libguestfs_GuestFS__1tar_1out  (JNIEnv *env, jobject obj, jlong jg, jstring jdirectory, jstring jtarfile, jlong joptargs_bitmask, jstring jcompress, jboolean jnumericowner, jobjectArray jexcludes, jboolean jxattrs, jboolean jselinux, jboolean jacls)
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
  optargs_s.xattrs = jxattrs;
  optargs_s.selinux = jselinux;
  optargs_s.acls = jacls;
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
    goto ret_error;
  }
  return;

 ret_error:
  return;
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
    goto ret_error;
  }
  jr = (*env)->NewStringUTF (env, r);
  free (r);
  return jr;

 ret_error:
  return NULL;
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
  physvols = malloc (sizeof (char *) * (physvols_len+1));
  if (physvols == NULL) {
    throw_out_of_memory (env, "malloc");
    goto ret_error;
  }
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
    goto ret_error;
  }
  return;

 ret_error:
  return;
}


JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1wait_1ready  (JNIEnv *env, jobject obj, jlong jg)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;


  r = guestfs_wait_ready (g);


  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    goto ret_error;
  }
  return;

 ret_error:
  return;
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
    goto ret_error;
  }
  return (jint) r;

 ret_error:
  return -1;
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

