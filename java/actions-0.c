/* libguestfs generated file
 * WARNING: THIS FILE IS GENERATED FROM THE FOLLOWING FILES:
 *          generator/java.ml
 *          and from the code in the generator/ subdirectory.
 * ANY CHANGES YOU MAKE TO THIS FILE WILL BE LOST.
 *
 * Copyright (C) 2009-2016 Red Hat Inc.
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
    goto ret_error;
  }
  return;

 ret_error:
  return;
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
    goto ret_error;
  }
  return (jint) r;

 ret_error:
  return -1;
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
    goto ret_error;
  }
  return;

 ret_error:
  return;
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
    goto ret_error;
  }
  return;

 ret_error:
  return;
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
Java_com_redhat_et_libguestfs_GuestFS__1btrfs_1qgroup_1create  (JNIEnv *env, jobject obj, jlong jg, jstring jqgroupid, jstring jsubvolume)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *qgroupid;
  const char *subvolume;

  qgroupid = (*env)->GetStringUTFChars (env, jqgroupid, NULL);
  subvolume = (*env)->GetStringUTFChars (env, jsubvolume, NULL);

  r = guestfs_btrfs_qgroup_create (g, qgroupid, subvolume);

  (*env)->ReleaseStringUTFChars (env, jqgroupid, qgroupid);
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
Java_com_redhat_et_libguestfs_GuestFS__1btrfs_1rescue_1super_1recover  (JNIEnv *env, jobject obj, jlong jg, jstring jdevice)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *device;

  device = (*env)->GetStringUTFChars (env, jdevice, NULL);

  r = guestfs_btrfs_rescue_super_recover (g, device);

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
Java_com_redhat_et_libguestfs_GuestFS__1btrfstune_1enable_1extended_1inode_1refs  (JNIEnv *env, jobject obj, jlong jg, jstring jdevice)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *device;

  device = (*env)->GetStringUTFChars (env, jdevice, NULL);

  r = guestfs_btrfstune_enable_extended_inode_refs (g, device);

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

  r = guestfs_command_lines (g, arguments);

  for (i = 0; i < arguments_len; ++i) {
    jobject o = (*env)->GetObjectArrayElement (env, jarguments, i);
    (*env)->ReleaseStringUTFChars (env, o, arguments[i]);
  }
  free (arguments);

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
    goto ret_error;
  }
  return;

 ret_error:
  return;
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
    goto ret_error;
  }
  return;

 ret_error:
  return;
}


JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1copy_1in  (JNIEnv *env, jobject obj, jlong jg, jstring jlocalpath, jstring jremotedir)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *localpath;
  const char *remotedir;

  localpath = (*env)->GetStringUTFChars (env, jlocalpath, NULL);
  remotedir = (*env)->GetStringUTFChars (env, jremotedir, NULL);

  r = guestfs_copy_in (g, localpath, remotedir);

  (*env)->ReleaseStringUTFChars (env, jlocalpath, localpath);
  (*env)->ReleaseStringUTFChars (env, jremotedir, remotedir);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    goto ret_error;
  }
  return;

 ret_error:
  return;
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
    goto ret_error;
  }
  return;

 ret_error:
  return;
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
    goto ret_error;
  }
  jr = (*env)->NewStringUTF (env, r);
  free (r);
  return jr;

 ret_error:
  return NULL;
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
    goto ret_error;
  }
  return (jboolean) r;

 ret_error:
  return -1;
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
    goto ret_error;
  }
  return;

 ret_error:
  return;
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
    goto ret_error;
  }
  return;

 ret_error:
  return;
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
    goto ret_error;
  }
  return (jint) r;

 ret_error:
  return -1;
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
    goto ret_error;
  }
  jr = (*env)->NewStringUTF (env, r);
  free (r);
  return jr;

 ret_error:
  return NULL;
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
    goto ret_error;
  }
  jr = (*env)->NewStringUTF (env, r);
  free (r);
  return jr;

 ret_error:
  return NULL;
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
    goto ret_error;
  }
  jr = (*env)->NewStringUTF (env, r);
  free (r);
  return jr;

 ret_error:
  return NULL;
}


JNIEXPORT jstring JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1get_1path  (JNIEnv *env, jobject obj, jlong jg)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  const char *r;


  r = guestfs_get_path (g);


  if (r == NULL) {
    throw_exception (env, guestfs_last_error (g));
    goto ret_error;
  }
  return (*env)->NewStringUTF (env, r);

 ret_error:
  return NULL;
}


JNIEXPORT jboolean JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1get_1pgroup  (JNIEnv *env, jobject obj, jlong jg)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;


  r = guestfs_get_pgroup (g);


  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    goto ret_error;
  }
  return (jboolean) r;

 ret_error:
  return -1;
}


JNIEXPORT jint JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1get_1smp  (JNIEnv *env, jobject obj, jlong jg)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;


  r = guestfs_get_smp (g);


  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    goto ret_error;
  }
  return (jint) r;

 ret_error:
  return -1;
}


JNIEXPORT jstring JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1get_1sockdir  (JNIEnv *env, jobject obj, jlong jg)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  jstring jr;
  char *r;


  r = guestfs_get_sockdir (g);


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
Java_com_redhat_et_libguestfs_GuestFS__1get_1trace  (JNIEnv *env, jobject obj, jlong jg)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;


  r = guestfs_get_trace (g);


  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    goto ret_error;
  }
  return (jboolean) r;

 ret_error:
  return -1;
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
    goto ret_error;
  }
  return (jlong) r;

 ret_error:
  return -1;
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
    goto ret_error;
  }
  return;

 ret_error:
  return;
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
    goto ret_error;
  }
  jr = (*env)->NewStringUTF (env, r);
  free (r);
  return jr;

 ret_error:
  return NULL;
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
    goto ret_error;
  }
  return (jlong) r;

 ret_error:
  return -1;
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
    goto ret_error;
  }
  jr = (*env)->NewStringUTF (env, r);
  free (r);
  return jr;

 ret_error:
  return NULL;
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
    goto ret_error;
  }
  return (jint) r;

 ret_error:
  return -1;
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
    goto ret_error;
  }
  jr = (*env)->NewStringUTF (env, r);
  free (r);
  return jr;

 ret_error:
  return NULL;
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
    goto ret_error;
  }
  jr = (*env)->NewStringUTF (env, r);
  free (r);
  return jr;

 ret_error:
  return NULL;
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
    goto ret_error;
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

 ret_error:
  return NULL;
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
Java_com_redhat_et_libguestfs_GuestFS__1internal_1test_1rboolerr  (JNIEnv *env, jobject obj, jlong jg)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;


  r = guestfs_internal_test_rboolerr (g);


  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    goto ret_error;
  }
  return (jboolean) r;

 ret_error:
  return -1;
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
    goto ret_error;
  }
  jr = (*env)->NewStringUTF (env, r);
  free (r);
  return jr;

 ret_error:
  return NULL;
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
  free (r);
  return jr;

 ret_error:
  return NULL;
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
      CLEANUP_FREE char *s = malloc (len);
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

  guestfs_free_xattr_list (r);
  return jr;

 ret_error:
  return NULL;
}


JNIEXPORT jlong JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1journal_1get_1data_1threshold  (JNIEnv *env, jobject obj, jlong jg)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int64_t r;


  r = guestfs_journal_get_data_threshold (g);


  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    goto ret_error;
  }
  return (jlong) r;

 ret_error:
  return -1;
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
    goto ret_error;
  }
  jr = (*env)->NewStringUTF (env, r);
  free (r);
  return jr;

 ret_error:
  return NULL;
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
    goto ret_error;
  }
  jr = (*env)->NewStringUTF (env, r);
  free (r);
  return jr;

 ret_error:
  return NULL;
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
    goto ret_error;
  }
  return;

 ret_error:
  return;
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
    goto ret_error;
  }
  return;

 ret_error:
  return;
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
    goto ret_error;
  }
  return;

 ret_error:
  return;
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

  r = guestfs_lstatnslist (g, path, names);

  (*env)->ReleaseStringUTFChars (env, jpath, path);
  for (i = 0; i < names_len; ++i) {
    jobject o = (*env)->GetObjectArrayElement (env, jnames, i);
    (*env)->ReleaseStringUTFChars (env, o, names[i]);
  }
  free (names);

  if (r == NULL) {
    throw_exception (env, guestfs_last_error (g));
    goto ret_error;
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

 ret_error:
  return NULL;
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
    goto ret_error;
  }
  return;

 ret_error:
  return;
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
    goto ret_error;
  }
  return;

 ret_error:
  return;
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
    goto ret_error;
  }
  return;

 ret_error:
  return;
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
    goto ret_error;
  }
  return;

 ret_error:
  return;
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
    goto ret_error;
  }
  return;

 ret_error:
  return;
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
    goto ret_error;
  }
  return;

 ret_error:
  return;
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
    goto ret_error;
  }
  return;

 ret_error:
  return;
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
    goto ret_error;
  }
  return;

 ret_error:
  return;
}


JNIEXPORT jstring JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1mountable_1device  (JNIEnv *env, jobject obj, jlong jg, jstring jmountable)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  jstring jr;
  char *r;
  const char *mountable;

  mountable = (*env)->GetStringUTFChars (env, jmountable, NULL);

  r = guestfs_mountable_device (g, mountable);

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
    goto ret_error;
  }
  return;

 ret_error:
  return;
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
    goto ret_error;
  }
  return;

 ret_error:
  return;
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
    goto ret_error;
  }
  return;

 ret_error:
  return;
}


JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1part_1expand_1gpt  (JNIEnv *env, jobject obj, jlong jg, jstring jdevice)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *device;

  device = (*env)->GetStringUTFChars (env, jdevice, NULL);

  r = guestfs_part_expand_gpt (g, device);

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
    goto ret_error;
  }
  jr = (*env)->NewStringUTF (env, r);
  free (r);
  return jr;

 ret_error:
  return NULL;
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
    goto ret_error;
  }
  return;

 ret_error:
  return;
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
    goto ret_error;
  }
  return (jint) r;

 ret_error:
  return -1;
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
    goto ret_error;
  }
  jr = (*env)->NewStringUTF (env, r); // XXX size
  free (r);
  return jr;

 ret_error:
  return NULL;
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
    goto ret_error;
  }
  return;

 ret_error:
  return;
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
    goto ret_error;
  }
  return;

 ret_error:
  return;
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
    goto ret_error;
  }
  return;

 ret_error:
  return;
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
    goto ret_error;
  }
  return;

 ret_error:
  return;
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
    goto ret_error;
  }
  return;

 ret_error:
  return;
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
    goto ret_error;
  }
  return;

 ret_error:
  return;
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
    goto ret_error;
  }
  return;

 ret_error:
  return;
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
    goto ret_error;
  }
  return;

 ret_error:
  return;
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
    goto ret_error;
  }
  return;

 ret_error:
  return;
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
    goto ret_error;
  }
  return;

 ret_error:
  return;
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
    goto ret_error;
  }
  return;

 ret_error:
  return;
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
    goto ret_error;
  }
  jr = (*env)->NewStringUTF (env, r);
  free (r);
  return jr;

 ret_error:
  return NULL;
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
    goto ret_error;
  }
  return;

 ret_error:
  return;
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
    goto ret_error;
  }
  jr = (*env)->NewStringUTF (env, r);
  free (r);
  return jr;

 ret_error:
  return NULL;
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
    goto ret_error;
  }
  return;

 ret_error:
  return;
}


JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1vgchange_1uuid_1all  (JNIEnv *env, jobject obj, jlong jg)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;


  r = guestfs_vgchange_uuid_all (g);


  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    goto ret_error;
  }
  return;

 ret_error:
  return;
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
    goto ret_error;
  }
  jr = (*env)->NewStringUTF (env, r); // XXX size
  free (r);
  return jr;

 ret_error:
  return NULL;
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
    goto ret_error;
  }
  return;

 ret_error:
  return;
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
    goto ret_error;
  }
  jr = (*env)->NewStringUTF (env, r);
  free (r);
  return jr;

 ret_error:
  return NULL;
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
    goto ret_error;
  }
  return (jint) r;

 ret_error:
  return -1;
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
    goto ret_error;
  }
  return;

 ret_error:
  return;
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

