/* libguestfs generated file
 * WARNING: THIS FILE IS GENERATED FROM THE FOLLOWING FILES:
 *          generator/java.ml
 *          and from the code in the generator/ subdirectory.
 * ANY CHANGES YOU MAKE TO THIS FILE WILL BE LOST.
 *
 * Copyright (C) 2009-2018 Red Hat Inc.
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
#include "guestfs-utils.h"
#include "structs-cleanups.h"

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
    goto ret_error;
  }
  return;

 ret_error:
  return;
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
    goto ret_error;
  }
  return (jint) r;

 ret_error:
  return -1;
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
    goto ret_error;
  }
  return;

 ret_error:
  return;
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
    goto ret_error;
  }
  return;

 ret_error:
  return;
}


JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1btrfs_1balance_1resume  (JNIEnv *env, jobject obj, jlong jg, jstring jpath)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *path;

  path = (*env)->GetStringUTFChars (env, jpath, NULL);

  r = guestfs_btrfs_balance_resume (g, path);

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
    goto ret_error;
  }
  return;

 ret_error:
  return;
}


JNIEXPORT jobjectArray JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1btrfs_1qgroup_1show  (JNIEnv *env, jobject obj, jlong jg, jstring jpath)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  jobjectArray jr;
  jclass cl;
  jfieldID fl;
  jobject jfl;
  CLEANUP_FREE_BTRFSQGROUP_LIST struct guestfs_btrfsqgroup_list *r = NULL;
  const char *path;
  size_t i;

  path = (*env)->GetStringUTFChars (env, jpath, NULL);

  r = guestfs_btrfs_qgroup_show (g, path);

  (*env)->ReleaseStringUTFChars (env, jpath, path);

  if (r == NULL) {
    throw_exception (env, guestfs_last_error (g));
    goto ret_error;
  }
  cl = (*env)->FindClass (env, "com/redhat/et/libguestfs/BTRFSQgroup");
  jr = (*env)->NewObjectArray (env, r->len, cl, NULL);

  for (i = 0; i < r->len; ++i) {
    jfl = (*env)->AllocObject (env, cl);

    fl = (*env)->GetFieldID (env, cl, "btrfsqgroup_id",
                             "Ljava/lang/String;");
    (*env)->SetObjectField (env, jfl, fl,
                            (*env)->NewStringUTF (env, r->val[i].btrfsqgroup_id));
    fl = (*env)->GetFieldID (env, cl, "btrfsqgroup_rfer",
                             "J");
    (*env)->SetLongField (env, jfl, fl, r->val[i].btrfsqgroup_rfer);
    fl = (*env)->GetFieldID (env, cl, "btrfsqgroup_excl",
                             "J");
    (*env)->SetLongField (env, jfl, fl, r->val[i].btrfsqgroup_excl);

    (*env)->SetObjectArrayElement (env, jr, i, jfl);
  }

  return jr;

 ret_error:
  return NULL;
}


JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1btrfs_1rescue_1chunk_1recover  (JNIEnv *env, jobject obj, jlong jg, jstring jdevice)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *device;

  device = (*env)->GetStringUTFChars (env, jdevice, NULL);

  r = guestfs_btrfs_rescue_chunk_recover (g, device);

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
Java_com_redhat_et_libguestfs_GuestFS__1btrfs_1scrub_1resume  (JNIEnv *env, jobject obj, jlong jg, jstring jpath)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *path;

  path = (*env)->GetStringUTFChars (env, jpath, NULL);

  r = guestfs_btrfs_scrub_resume (g, path);

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
    goto ret_error;
  }
  jr = (*env)->NewStringUTF (env, r);
  free (r);
  return jr;

 ret_error:
  return NULL;
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
    goto ret_error;
  }
  jr = (*env)->NewStringUTF (env, r);
  free (r);
  return jr;

 ret_error:
  return NULL;
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
    goto ret_error;
  }
  return (jint) r;

 ret_error:
  return -1;
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
    goto ret_error;
  }
  return;

 ret_error:
  return;
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
    goto ret_error;
  }
  return;

 ret_error:
  return;
}


JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1copy_1device_1to_1device  (JNIEnv *env, jobject obj, jlong jg, jstring jsrc, jstring jdest, jlong joptargs_bitmask, jlong jsrcoffset, jlong jdestoffset, jlong jsize, jboolean jsparse, jboolean jappend)
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
  optargs_s.append = jappend;
  optargs_s.bitmask = joptargs_bitmask;

  r = guestfs_copy_device_to_device_argv (g, src, dest, optargs);

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
    goto ret_error;
  }
  return;

 ret_error:
  return;
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
    goto ret_error;
  }
  return (jint) r;

 ret_error:
  return -1;
}


JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1download_1inode  (JNIEnv *env, jobject obj, jlong jg, jstring jdevice, jlong jinode, jstring jfilename)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *device;
  int64_t inode;
  const char *filename;

  device = (*env)->GetStringUTFChars (env, jdevice, NULL);
  inode = jinode;
  filename = (*env)->GetStringUTFChars (env, jfilename, NULL);

  r = guestfs_download_inode (g, device, inode, filename);

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
    goto ret_error;
  }
  return (jboolean) r;

 ret_error:
  return -1;
}


JNIEXPORT jobjectArray JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1filesystem_1walk  (JNIEnv *env, jobject obj, jlong jg, jstring jdevice)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  jobjectArray jr;
  jclass cl;
  jfieldID fl;
  jobject jfl;
  CLEANUP_FREE_TSK_DIRENT_LIST struct guestfs_tsk_dirent_list *r = NULL;
  const char *device;
  size_t i;

  device = (*env)->GetStringUTFChars (env, jdevice, NULL);

  r = guestfs_filesystem_walk (g, device);

  (*env)->ReleaseStringUTFChars (env, jdevice, device);

  if (r == NULL) {
    throw_exception (env, guestfs_last_error (g));
    goto ret_error;
  }
  cl = (*env)->FindClass (env, "com/redhat/et/libguestfs/TSKDirent");
  jr = (*env)->NewObjectArray (env, r->len, cl, NULL);

  for (i = 0; i < r->len; ++i) {
    jfl = (*env)->AllocObject (env, cl);

    fl = (*env)->GetFieldID (env, cl, "tsk_inode",
                             "J");
    (*env)->SetLongField (env, jfl, fl, r->val[i].tsk_inode);
    fl = (*env)->GetFieldID (env, cl, "tsk_type",
                             "C");
    (*env)->SetCharField (env, jfl, fl, r->val[i].tsk_type);
    fl = (*env)->GetFieldID (env, cl, "tsk_size",
                             "J");
    (*env)->SetLongField (env, jfl, fl, r->val[i].tsk_size);
    fl = (*env)->GetFieldID (env, cl, "tsk_name",
                             "Ljava/lang/String;");
    (*env)->SetObjectField (env, jfl, fl,
                            (*env)->NewStringUTF (env, r->val[i].tsk_name));
    fl = (*env)->GetFieldID (env, cl, "tsk_flags",
                             "I");
    (*env)->SetIntField (env, jfl, fl, r->val[i].tsk_flags);
    fl = (*env)->GetFieldID (env, cl, "tsk_atime_sec",
                             "J");
    (*env)->SetLongField (env, jfl, fl, r->val[i].tsk_atime_sec);
    fl = (*env)->GetFieldID (env, cl, "tsk_atime_nsec",
                             "J");
    (*env)->SetLongField (env, jfl, fl, r->val[i].tsk_atime_nsec);
    fl = (*env)->GetFieldID (env, cl, "tsk_mtime_sec",
                             "J");
    (*env)->SetLongField (env, jfl, fl, r->val[i].tsk_mtime_sec);
    fl = (*env)->GetFieldID (env, cl, "tsk_mtime_nsec",
                             "J");
    (*env)->SetLongField (env, jfl, fl, r->val[i].tsk_mtime_nsec);
    fl = (*env)->GetFieldID (env, cl, "tsk_ctime_sec",
                             "J");
    (*env)->SetLongField (env, jfl, fl, r->val[i].tsk_ctime_sec);
    fl = (*env)->GetFieldID (env, cl, "tsk_ctime_nsec",
                             "J");
    (*env)->SetLongField (env, jfl, fl, r->val[i].tsk_ctime_nsec);
    fl = (*env)->GetFieldID (env, cl, "tsk_crtime_sec",
                             "J");
    (*env)->SetLongField (env, jfl, fl, r->val[i].tsk_crtime_sec);
    fl = (*env)->GetFieldID (env, cl, "tsk_crtime_nsec",
                             "J");
    (*env)->SetLongField (env, jfl, fl, r->val[i].tsk_crtime_nsec);
    fl = (*env)->GetFieldID (env, cl, "tsk_nlink",
                             "J");
    (*env)->SetLongField (env, jfl, fl, r->val[i].tsk_nlink);
    fl = (*env)->GetFieldID (env, cl, "tsk_link",
                             "Ljava/lang/String;");
    (*env)->SetObjectField (env, jfl, fl,
                            (*env)->NewStringUTF (env, r->val[i].tsk_link));
    fl = (*env)->GetFieldID (env, cl, "tsk_spare1",
                             "J");
    (*env)->SetLongField (env, jfl, fl, r->val[i].tsk_spare1);

    (*env)->SetObjectArrayElement (env, jr, i, jfl);
  }

  return jr;

 ret_error:
  return NULL;
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
    goto ret_error;
  }
  return;

 ret_error:
  return;
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
    goto ret_error;
  }
  jr = (*env)->NewStringUTF (env, r);
  free (r);
  return jr;

 ret_error:
  return NULL;
}


JNIEXPORT jstring JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1get_1identifier  (JNIEnv *env, jobject obj, jlong jg)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  const char *r;


  r = guestfs_get_identifier (g);


  if (r == NULL) {
    throw_exception (env, guestfs_last_error (g));
    goto ret_error;
  }
  return (*env)->NewStringUTF (env, r);

 ret_error:
  return NULL;
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
    goto ret_error;
  }
  jr = (*env)->NewStringUTF (env, r);
  free (r);
  return jr;

 ret_error:
  return NULL;
}


JNIEXPORT jboolean JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1get_1network  (JNIEnv *env, jobject obj, jlong jg)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;


  r = guestfs_get_network (g);


  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    goto ret_error;
  }
  return (jboolean) r;

 ret_error:
  return -1;
}


JNIEXPORT jstring JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1get_1qemu  (JNIEnv *env, jobject obj, jlong jg)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  const char *r;


  r = guestfs_get_qemu (g);


  if (r == NULL) {
    throw_exception (env, guestfs_last_error (g));
    goto ret_error;
  }
  return (*env)->NewStringUTF (env, r);

 ret_error:
  return NULL;
}


JNIEXPORT jint JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1get_1state  (JNIEnv *env, jobject obj, jlong jg)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;


  r = guestfs_get_state (g);


  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    goto ret_error;
  }
  return (jint) r;

 ret_error:
  return -1;
}


JNIEXPORT jint JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1get_1umask  (JNIEnv *env, jobject obj, jlong jg)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;


  r = guestfs_get_umask (g);


  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    goto ret_error;
  }
  return (jint) r;

 ret_error:
  return -1;
}


JNIEXPORT jboolean JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1get_1verbose  (JNIEnv *env, jobject obj, jlong jg)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;


  r = guestfs_get_verbose (g);


  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    goto ret_error;
  }
  return (jboolean) r;

 ret_error:
  return -1;
}


JNIEXPORT jobjectArray JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1getxattrs  (JNIEnv *env, jobject obj, jlong jg, jstring jpath)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  jobjectArray jr;
  jclass cl;
  jfieldID fl;
  jobject jfl;
  CLEANUP_FREE_XATTR_LIST struct guestfs_xattr_list *r = NULL;
  const char *path;
  size_t i;

  path = (*env)->GetStringUTFChars (env, jpath, NULL);

  r = guestfs_getxattrs (g, path);

  (*env)->ReleaseStringUTFChars (env, jpath, path);

  if (r == NULL) {
    throw_exception (env, guestfs_last_error (g));
    goto ret_error;
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
      CLEANUP_FREE char *s = malloc (len + 1);
      if (s == NULL) {
        throw_out_of_memory (env, "malloc");
        goto ret_error;
      }
      memcpy (s, r->val[i].attrval, len);
      s[len] = 0;
      (*env)->SetObjectField (env, jfl, fl,
                              (*env)->NewStringUTF (env, s));
    }

    (*env)->SetObjectArrayElement (env, jr, i, jfl);
  }

  return jr;

 ret_error:
  return NULL;
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
    goto ret_error;
  }
  return (jlong) r;

 ret_error:
  return -1;
}


JNIEXPORT jlong JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1hivex_1root  (JNIEnv *env, jobject obj, jlong jg)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int64_t r;


  r = guestfs_hivex_root (g);


  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    goto ret_error;
  }
  return (jlong) r;

 ret_error:
  return -1;
}


JNIEXPORT jstring JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1hivex_1value_1string  (JNIEnv *env, jobject obj, jlong jg, jlong jvalueh)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  jstring jr;
  char *r;
  int64_t valueh;

  valueh = jvalueh;

  r = guestfs_hivex_value_string (g, valueh);


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
    goto ret_error;
  }
  jr = (*env)->NewStringUTF (env, r); // XXX size
  free (r);
  return jr;

 ret_error:
  return NULL;
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
Java_com_redhat_et_libguestfs_GuestFS__1inotify_1rm_1watch  (JNIEnv *env, jobject obj, jlong jg, jint jwd)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  int wd;

  wd = jwd;

  r = guestfs_inotify_rm_watch (g, wd);


  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    goto ret_error;
  }
  return;

 ret_error:
  return;
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
    goto ret_error;
  }
  jr = (*env)->NewStringUTF (env, r); // XXX size
  free (r);
  return jr;

 ret_error:
  return NULL;
}


JNIEXPORT jstring JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1inspect_1get_1windows_1system_1hive  (JNIEnv *env, jobject obj, jlong jg, jstring jroot)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  jstring jr;
  char *r;
  const char *root;

  root = (*env)->GetStringUTFChars (env, jroot, NULL);

  r = guestfs_inspect_get_windows_system_hive (g, root);

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
    goto ret_error;
  }
  return (jboolean) r;

 ret_error:
  return -1;
}


JNIEXPORT jobjectArray JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1inspect_1list_1applications2  (JNIEnv *env, jobject obj, jlong jg, jstring jroot)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  jobjectArray jr;
  jclass cl;
  jfieldID fl;
  jobject jfl;
  CLEANUP_FREE_APPLICATION2_LIST struct guestfs_application2_list *r = NULL;
  const char *root;
  size_t i;

  root = (*env)->GetStringUTFChars (env, jroot, NULL);

  r = guestfs_inspect_list_applications2 (g, root);

  (*env)->ReleaseStringUTFChars (env, jroot, root);

  if (r == NULL) {
    throw_exception (env, guestfs_last_error (g));
    goto ret_error;
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

  return jr;

 ret_error:
  return NULL;
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
    goto ret_error;
  }
  jr = (*env)->NewStringUTF (env, r); // XXX size
  free (r);
  return jr;

 ret_error:
  return NULL;
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
    goto ret_error;
  }
  return (jlong) r;

 ret_error:
  return -1;
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
    goto ret_error;
  }
  jr = (*env)->NewStringUTF (env, r);
  free (r);
  return jr;

 ret_error:
  return NULL;
}


JNIEXPORT jobjectArray JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1internal_1test_1rstructlist  (JNIEnv *env, jobject obj, jlong jg, jstring jval)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  jobjectArray jr;
  jclass cl;
  jfieldID fl;
  jobject jfl;
  CLEANUP_FREE_LVM_PV_LIST struct guestfs_lvm_pv_list *r = NULL;
  const char *val;
  size_t i;

  val = (*env)->GetStringUTFChars (env, jval, NULL);

  r = guestfs_internal_test_rstructlist (g, val);

  (*env)->ReleaseStringUTFChars (env, jval, val);

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


JNIEXPORT jobjectArray JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1internal_1test_1rstructlisterr  (JNIEnv *env, jobject obj, jlong jg)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  jobjectArray jr;
  jclass cl;
  jfieldID fl;
  jobject jfl;
  CLEANUP_FREE_LVM_PV_LIST struct guestfs_lvm_pv_list *r = NULL;
  size_t i;


  r = guestfs_internal_test_rstructlisterr (g);


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
    goto ret_error;
  }
  return (jboolean) r;

 ret_error:
  return -1;
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
    goto ret_error;
  }
  return (jboolean) r;

 ret_error:
  return -1;
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
    goto ret_error;
  }
  return;

 ret_error:
  return;
}


JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1ldmtool_1create_1all  (JNIEnv *env, jobject obj, jlong jg)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;


  r = guestfs_ldmtool_create_all (g);


  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    goto ret_error;
  }
  return;

 ret_error:
  return;
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
    goto ret_error;
  }
  jr = (*env)->NewStringUTF (env, r);
  free (r);
  return jr;

 ret_error:
  return NULL;
}


JNIEXPORT jobject JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1lstat  (JNIEnv *env, jobject obj, jlong jg, jstring jpath)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  jobject jr;
  jclass cl;
  jfieldID fl;
  CLEANUP_FREE_STAT struct guestfs_stat *r = NULL;
  const char *path;

  path = (*env)->GetStringUTFChars (env, jpath, NULL);

  r = guestfs_lstat (g, path);

  (*env)->ReleaseStringUTFChars (env, jpath, path);

  if (r == NULL) {
    throw_exception (env, guestfs_last_error (g));
    goto ret_error;
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
  return jr;

 ret_error:
  return NULL;
}


JNIEXPORT jobjectArray JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1lstatlist  (JNIEnv *env, jobject obj, jlong jg, jstring jpath, jobjectArray jnames)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  jobjectArray jr;
  jclass cl;
  jfieldID fl;
  jobject jfl;
  CLEANUP_FREE_STAT_LIST struct guestfs_stat_list *r = NULL;
  const char *path;
  size_t names_len;
  CLEANUP_FREE char **names = NULL;
  size_t i;

  path = (*env)->GetStringUTFChars (env, jpath, NULL);
  names_len = (*env)->GetArrayLength (env, jnames);
  names = malloc (sizeof (char *) * (names_len+1));
  if (names == NULL) {
    throw_out_of_memory (env, "malloc");
    goto ret_error;
  }
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

  if (r == NULL) {
    throw_exception (env, guestfs_last_error (g));
    goto ret_error;
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

  return jr;

 ret_error:
  return NULL;
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
    goto ret_error;
  }
  return;

 ret_error:
  return;
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
    goto ret_error;
  }
  return;

 ret_error:
  return;
}


JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1lvm_1remove_1all  (JNIEnv *env, jobject obj, jlong jg)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;


  r = guestfs_lvm_remove_all (g);


  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    goto ret_error;
  }
  return;

 ret_error:
  return;
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
    goto ret_error;
  }
  return;

 ret_error:
  return;
}


JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1md_1create  (JNIEnv *env, jobject obj, jlong jg, jstring jname, jobjectArray jdevices, jlong joptargs_bitmask, jlong jmissingbitmap, jint jnrdevices, jint jspare, jlong jchunk, jstring jlevel)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *name;
  size_t devices_len;
  CLEANUP_FREE char **devices = NULL;
  struct guestfs_md_create_argv optargs_s;
  const struct guestfs_md_create_argv *optargs = &optargs_s;
  size_t i;

  name = (*env)->GetStringUTFChars (env, jname, NULL);
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
  (*env)->ReleaseStringUTFChars (env, jlevel, optargs_s.level);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    goto ret_error;
  }
  return;

 ret_error:
  return;
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
    goto ret_error;
  }
  jr = (*env)->NewStringUTF (env, r);
  free (r);
  return jr;

 ret_error:
  return NULL;
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
    goto ret_error;
  }
  return;

 ret_error:
  return;
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
    goto ret_error;
  }
  return;

 ret_error:
  return;
}


JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1mount_1local_1run  (JNIEnv *env, jobject obj, jlong jg)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;


  r = guestfs_mount_local_run (g);


  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    goto ret_error;
  }
  return;

 ret_error:
  return;
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
    goto ret_error;
  }
  return;

 ret_error:
  return;
}


JNIEXPORT jstring JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1mountable_1subvolume  (JNIEnv *env, jobject obj, jlong jg, jstring jmountable)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  jstring jr;
  char *r;
  const char *mountable;

  mountable = (*env)->GetStringUTFChars (env, jmountable, NULL);

  r = guestfs_mountable_subvolume (g, mountable);

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
    goto ret_error;
  }
  return (jint) r;

 ret_error:
  return -1;
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
    goto ret_error;
  }
  return;

 ret_error:
  return;
}


JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1part_1resize  (JNIEnv *env, jobject obj, jlong jg, jstring jdevice, jint jpartnum, jlong jendsect)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *device;
  int partnum;
  int64_t endsect;

  device = (*env)->GetStringUTFChars (env, jdevice, NULL);
  partnum = jpartnum;
  endsect = jendsect;

  r = guestfs_part_resize (g, device, partnum, endsect);

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
Java_com_redhat_et_libguestfs_GuestFS__1part_1set_1disk_1guid  (JNIEnv *env, jobject obj, jlong jg, jstring jdevice, jstring jguid)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *device;
  const char *guid;

  device = (*env)->GetStringUTFChars (env, jdevice, NULL);
  guid = (*env)->GetStringUTFChars (env, jguid, NULL);

  r = guestfs_part_set_disk_guid (g, device, guid);

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


JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1part_1set_1disk_1guid_1random  (JNIEnv *env, jobject obj, jlong jg, jstring jdevice)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *device;

  device = (*env)->GetStringUTFChars (env, jdevice, NULL);

  r = guestfs_part_set_disk_guid_random (g, device);

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
    goto ret_error;
  }
  jr = (*env)->NewStringUTF (env, r); // XXX size
  free (r);
  return jr;

 ret_error:
  return NULL;
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
    goto ret_error;
  }
  jr = (*env)->NewStringUTF (env, r);
  free (r);
  return jr;

 ret_error:
  return NULL;
}


JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1selinux_1relabel  (JNIEnv *env, jobject obj, jlong jg, jstring jspecfile, jstring jpath, jlong joptargs_bitmask, jboolean jforce)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *specfile;
  const char *path;
  struct guestfs_selinux_relabel_argv optargs_s;
  const struct guestfs_selinux_relabel_argv *optargs = &optargs_s;

  specfile = (*env)->GetStringUTFChars (env, jspecfile, NULL);
  path = (*env)->GetStringUTFChars (env, jpath, NULL);

  optargs_s.force = jforce;
  optargs_s.bitmask = joptargs_bitmask;

  r = guestfs_selinux_relabel_argv (g, specfile, path, optargs);

  (*env)->ReleaseStringUTFChars (env, jspecfile, specfile);
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
Java_com_redhat_et_libguestfs_GuestFS__1set_1autosync  (JNIEnv *env, jobject obj, jlong jg, jboolean jautosync)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  int autosync;

  autosync = jautosync;

  r = guestfs_set_autosync (g, autosync);


  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    goto ret_error;
  }
  return;

 ret_error:
  return;
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
    goto ret_error;
  }
  return;

 ret_error:
  return;
}


JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1set_1identifier  (JNIEnv *env, jobject obj, jlong jg, jstring jidentifier)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *identifier;

  identifier = (*env)->GetStringUTFChars (env, jidentifier, NULL);

  r = guestfs_set_identifier (g, identifier);

  (*env)->ReleaseStringUTFChars (env, jidentifier, identifier);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    goto ret_error;
  }
  return;

 ret_error:
  return;
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
    goto ret_error;
  }
  return;

 ret_error:
  return;
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
    goto ret_error;
  }
  return;

 ret_error:
  return;
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
    goto ret_error;
  }
  return;

 ret_error:
  return;
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
    goto ret_error;
  }
  return;

 ret_error:
  return;
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
    goto ret_error;
  }
  return;

 ret_error:
  return;
}


JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1vg_1activate  (JNIEnv *env, jobject obj, jlong jg, jboolean jactivate, jobjectArray jvolgroups)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  int activate;
  size_t volgroups_len;
  CLEANUP_FREE char **volgroups = NULL;
  size_t i;

  activate = jactivate;
  volgroups_len = (*env)->GetArrayLength (env, jvolgroups);
  volgroups = malloc (sizeof (char *) * (volgroups_len+1));
  if (volgroups == NULL) {
    throw_out_of_memory (env, "malloc");
    goto ret_error;
  }
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

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    goto ret_error;
  }
  return;

 ret_error:
  return;
}


JNIEXPORT jobjectArray JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1vgs_1full  (JNIEnv *env, jobject obj, jlong jg)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  jobjectArray jr;
  jclass cl;
  jfieldID fl;
  jobject jfl;
  CLEANUP_FREE_LVM_VG_LIST struct guestfs_lvm_vg_list *r = NULL;
  size_t i;


  r = guestfs_vgs_full (g);


  if (r == NULL) {
    throw_exception (env, guestfs_last_error (g));
    goto ret_error;
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

  return jr;

 ret_error:
  return NULL;
}


JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1vgscan  (JNIEnv *env, jobject obj, jlong jg)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;


  r = guestfs_vgscan (g);


  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    goto ret_error;
  }
  return;

 ret_error:
  return;
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
    goto ret_error;
  }
  return;

 ret_error:
  return;
}


JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1yara_1destroy  (JNIEnv *env, jobject obj, jlong jg)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;


  r = guestfs_yara_destroy (g);


  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    goto ret_error;
  }
  return;

 ret_error:
  return;
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
    goto ret_error;
  }
  jr = (*env)->NewStringUTF (env, r);
  free (r);
  return jr;

 ret_error:
  return NULL;
}

