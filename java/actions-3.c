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
    goto ret_error;
  }
  jr = (*env)->NewStringUTF (env, r);
  free (r);
  return jr;

 ret_error:
  return NULL;
}


JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1aug_1close  (JNIEnv *env, jobject obj, jlong jg)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;


  r = guestfs_aug_close (g);


  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    goto ret_error;
  }
  return;

 ret_error:
  return;
}


JNIEXPORT jobject JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1aug_1defnode  (JNIEnv *env, jobject obj, jlong jg, jstring jname, jstring jexpr, jstring jval)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  jobject jr;
  jclass cl;
  jfieldID fl;
  CLEANUP_FREE_INT_BOOL struct guestfs_int_bool *r = NULL;
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
    goto ret_error;
  }
  cl = (*env)->FindClass (env, "com/redhat/et/libguestfs/IntBool");
  jr = (*env)->AllocObject (env, cl);
  fl = (*env)->GetFieldID (env, cl, "i", "I");
  (*env)->SetIntField (env, jr, fl, r->i);
  fl = (*env)->GetFieldID (env, cl, "b", "I");
  (*env)->SetIntField (env, jr, fl, r->b);
  return jr;

 ret_error:
  return NULL;
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
    goto ret_error;
  }
  jr = (*env)->NewStringUTF (env, r);
  free (r);
  return jr;

 ret_error:
  return NULL;
}


JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1aug_1save  (JNIEnv *env, jobject obj, jlong jg)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;


  r = guestfs_aug_save (g);


  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    goto ret_error;
  }
  return;

 ret_error:
  return;
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
    goto ret_error;
  }
  return (jint) r;

 ret_error:
  return -1;
}


JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1available  (JNIEnv *env, jobject obj, jlong jg, jobjectArray jgroups)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  size_t groups_len;
  CLEANUP_FREE char **groups = NULL;
  size_t i;

  groups_len = (*env)->GetArrayLength (env, jgroups);
  groups = malloc (sizeof (char *) * (groups_len+1));
  if (groups == NULL) {
    throw_out_of_memory (env, "malloc");
    goto ret_error;
  }
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

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    goto ret_error;
  }
  return;

 ret_error:
  return;
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
    goto ret_error;
  }
  return;

 ret_error:
  return;
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
    goto ret_error;
  }
  return (jlong) r;

 ret_error:
  return -1;
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
    goto ret_error;
  }
  return;

 ret_error:
  return;
}


JNIEXPORT jobject JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1btrfs_1balance_1status  (JNIEnv *env, jobject obj, jlong jg, jstring jpath)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  jobject jr;
  jclass cl;
  jfieldID fl;
  CLEANUP_FREE_BTRFSBALANCE struct guestfs_btrfsbalance *r = NULL;
  const char *path;

  path = (*env)->GetStringUTFChars (env, jpath, NULL);

  r = guestfs_btrfs_balance_status (g, path);

  (*env)->ReleaseStringUTFChars (env, jpath, path);

  if (r == NULL) {
    throw_exception (env, guestfs_last_error (g));
    goto ret_error;
  }
  cl = (*env)->FindClass (env, "com/redhat/et/libguestfs/BTRFSBalance");
  jr = (*env)->AllocObject (env, cl);
  fl = (*env)->GetFieldID (env, cl, "btrfsbalance_status", "Ljava/lang/String;");
  (*env)->SetObjectField (env, jr, fl, (*env)->NewStringUTF (env, r->btrfsbalance_status));
  fl = (*env)->GetFieldID (env, cl, "btrfsbalance_total", "J");
  (*env)->SetLongField (env, jr, fl, r->btrfsbalance_total);
  fl = (*env)->GetFieldID (env, cl, "btrfsbalance_balanced", "J");
  (*env)->SetLongField (env, jr, fl, r->btrfsbalance_balanced);
  fl = (*env)->GetFieldID (env, cl, "btrfsbalance_considered", "J");
  (*env)->SetLongField (env, jr, fl, r->btrfsbalance_considered);
  fl = (*env)->GetFieldID (env, cl, "btrfsbalance_left", "J");
  (*env)->SetLongField (env, jr, fl, r->btrfsbalance_left);
  return jr;

 ret_error:
  return NULL;
}


JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1btrfs_1device_1delete  (JNIEnv *env, jobject obj, jlong jg, jobjectArray jdevices, jstring jfs)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  size_t devices_len;
  CLEANUP_FREE char **devices = NULL;
  const char *fs;
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
  fs = (*env)->GetStringUTFChars (env, jfs, NULL);

  r = guestfs_btrfs_device_delete (g, devices, fs);

  for (i = 0; i < devices_len; ++i) {
    jobject o = (*env)->GetObjectArrayElement (env, jdevices, i);
    (*env)->ReleaseStringUTFChars (env, o, devices[i]);
  }
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
Java_com_redhat_et_libguestfs_GuestFS__1btrfs_1filesystem_1defragment  (JNIEnv *env, jobject obj, jlong jg, jstring jpath, jlong joptargs_bitmask, jboolean jflush, jstring jcompress)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *path;
  struct guestfs_btrfs_filesystem_defragment_argv optargs_s;
  const struct guestfs_btrfs_filesystem_defragment_argv *optargs = &optargs_s;

  path = (*env)->GetStringUTFChars (env, jpath, NULL);

  optargs_s.flush = jflush;
  optargs_s.compress = (*env)->GetStringUTFChars (env, jcompress, NULL);
  optargs_s.bitmask = joptargs_bitmask;

  r = guestfs_btrfs_filesystem_defragment_argv (g, path, optargs);

  (*env)->ReleaseStringUTFChars (env, jpath, path);
  (*env)->ReleaseStringUTFChars (env, jcompress, optargs_s.compress);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    goto ret_error;
  }
  return;

 ret_error:
  return;
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
    goto ret_error;
  }
  return;

 ret_error:
  return;
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
    goto ret_error;
  }
  return;

 ret_error:
  return;
}


JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1btrfs_1image  (JNIEnv *env, jobject obj, jlong jg, jobjectArray jsource, jstring jimage, jlong joptargs_bitmask, jint jcompresslevel)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  size_t source_len;
  CLEANUP_FREE char **source = NULL;
  const char *image;
  struct guestfs_btrfs_image_argv optargs_s;
  const struct guestfs_btrfs_image_argv *optargs = &optargs_s;
  size_t i;

  source_len = (*env)->GetArrayLength (env, jsource);
  source = malloc (sizeof (char *) * (source_len+1));
  if (source == NULL) {
    throw_out_of_memory (env, "malloc");
    goto ret_error;
  }
  for (i = 0; i < source_len; ++i) {
    jobject o = (*env)->GetObjectArrayElement (env, jsource, i);
    source[i] = (char *) (*env)->GetStringUTFChars (env, o, NULL);
  }
  source[source_len] = NULL;
  image = (*env)->GetStringUTFChars (env, jimage, NULL);

  optargs_s.compresslevel = jcompresslevel;
  optargs_s.bitmask = joptargs_bitmask;

  r = guestfs_btrfs_image_argv (g, source, image, optargs);

  for (i = 0; i < source_len; ++i) {
    jobject o = (*env)->GetObjectArrayElement (env, jsource, i);
    (*env)->ReleaseStringUTFChars (env, o, source[i]);
  }
  (*env)->ReleaseStringUTFChars (env, jimage, image);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    goto ret_error;
  }
  return;

 ret_error:
  return;
}


JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1btrfs_1qgroup_1destroy  (JNIEnv *env, jobject obj, jlong jg, jstring jqgroupid, jstring jsubvolume)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *qgroupid;
  const char *subvolume;

  qgroupid = (*env)->GetStringUTFChars (env, jqgroupid, NULL);
  subvolume = (*env)->GetStringUTFChars (env, jsubvolume, NULL);

  r = guestfs_btrfs_qgroup_destroy (g, qgroupid, subvolume);

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
    goto ret_error;
  }
  return;

 ret_error:
  return;
}


JNIEXPORT jobjectArray JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1btrfs_1subvolume_1list  (JNIEnv *env, jobject obj, jlong jg, jstring jfs)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  jobjectArray jr;
  jclass cl;
  jfieldID fl;
  jobject jfl;
  CLEANUP_FREE_BTRFSSUBVOLUME_LIST struct guestfs_btrfssubvolume_list *r = NULL;
  const char *fs;
  size_t i;

  fs = (*env)->GetStringUTFChars (env, jfs, NULL);

  r = guestfs_btrfs_subvolume_list (g, fs);

  (*env)->ReleaseStringUTFChars (env, jfs, fs);

  if (r == NULL) {
    throw_exception (env, guestfs_last_error (g));
    goto ret_error;
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

  return jr;

 ret_error:
  return NULL;
}


JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1btrfstune_1enable_1skinny_1metadata_1extent_1refs  (JNIEnv *env, jobject obj, jlong jg, jstring jdevice)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *device;

  device = (*env)->GetStringUTFChars (env, jdevice, NULL);

  r = guestfs_btrfstune_enable_skinny_metadata_extent_refs (g, device);

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
    goto ret_error;
  }
  jr = (*env)->NewStringUTF (env, r);
  free (r);
  return jr;

 ret_error:
  return NULL;
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
    goto ret_error;
  }
  jr = (*env)->NewStringUTF (env, r);
  free (r);
  return jr;

 ret_error:
  return NULL;
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
    goto ret_error;
  }
  return;

 ret_error:
  return;
}


JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1copy_1out  (JNIEnv *env, jobject obj, jlong jg, jstring jremotepath, jstring jlocaldir)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *remotepath;
  const char *localdir;

  remotepath = (*env)->GetStringUTFChars (env, jremotepath, NULL);
  localdir = (*env)->GetStringUTFChars (env, jlocaldir, NULL);

  r = guestfs_copy_out (g, remotepath, localdir);

  (*env)->ReleaseStringUTFChars (env, jremotepath, remotepath);
  (*env)->ReleaseStringUTFChars (env, jlocaldir, localdir);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    goto ret_error;
  }
  return;

 ret_error:
  return;
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
    goto ret_error;
  }
  return;

 ret_error:
  return;
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
    goto ret_error;
  }
  jr = (*env)->NewStringUTF (env, r);
  free (r);
  return jr;

 ret_error:
  return NULL;
}


JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1download_1blocks  (JNIEnv *env, jobject obj, jlong jg, jstring jdevice, jlong jstart, jlong jstop, jstring jfilename, jlong joptargs_bitmask, jboolean junallocated)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *device;
  int64_t start;
  int64_t stop;
  const char *filename;
  struct guestfs_download_blocks_argv optargs_s;
  const struct guestfs_download_blocks_argv *optargs = &optargs_s;

  device = (*env)->GetStringUTFChars (env, jdevice, NULL);
  start = jstart;
  stop = jstop;
  filename = (*env)->GetStringUTFChars (env, jfilename, NULL);

  optargs_s.unallocated = junallocated;
  optargs_s.bitmask = joptargs_bitmask;

  r = guestfs_download_blocks_argv (g, device, start, stop, filename, optargs);

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
    goto ret_error;
  }
  return (jlong) r;

 ret_error:
  return -1;
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
    goto ret_error;
  }
  return;

 ret_error:
  return;
}


JNIEXPORT jstring JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1echo_1daemon  (JNIEnv *env, jobject obj, jlong jg, jobjectArray jwords)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  jstring jr;
  char *r;
  size_t words_len;
  CLEANUP_FREE char **words = NULL;
  size_t i;

  words_len = (*env)->GetArrayLength (env, jwords);
  words = malloc (sizeof (char *) * (words_len+1));
  if (words == NULL) {
    throw_out_of_memory (env, "malloc");
    goto ret_error;
  }
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
    goto ret_error;
  }
  return (jboolean) r;

 ret_error:
  return -1;
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
    goto ret_error;
  }
  jr = (*env)->NewStringUTF (env, r);
  free (r);
  return jr;

 ret_error:
  return NULL;
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
    goto ret_error;
  }
  jr = (*env)->NewStringUTF (env, r);
  free (r);
  return jr;

 ret_error:
  return NULL;
}


JNIEXPORT jboolean JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1get_1recovery_1proc  (JNIEnv *env, jobject obj, jlong jg)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;


  r = guestfs_get_recovery_proc (g);


  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    goto ret_error;
  }
  return (jboolean) r;

 ret_error:
  return -1;
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
    goto ret_error;
  }
  jr = (*env)->NewStringUTF (env, r);
  free (r);
  return jr;

 ret_error:
  return NULL;
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
    goto ret_error;
  }
  jr = (*env)->NewStringUTF (env, r);
  free (r);
  return jr;

 ret_error:
  return NULL;
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
    goto ret_error;
  }
  jr = (*env)->NewStringUTF (env, r); // XXX size
  free (r);
  return jr;

 ret_error:
  return NULL;
}


JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1hivex_1close  (JNIEnv *env, jobject obj, jlong jg)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;


  r = guestfs_hivex_close (g);


  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    goto ret_error;
  }
  return;

 ret_error:
  return;
}


JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1hivex_1open  (JNIEnv *env, jobject obj, jlong jg, jstring jfilename, jlong joptargs_bitmask, jboolean jverbose, jboolean jdebug, jboolean jwrite, jboolean junsafe)
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
  optargs_s.unsafe = junsafe;
  optargs_s.bitmask = joptargs_bitmask;

  r = guestfs_hivex_open_argv (g, filename, optargs);

  (*env)->ReleaseStringUTFChars (env, jfilename, filename);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    goto ret_error;
  }
  return;

 ret_error:
  return;
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
    goto ret_error;
  }
  jr = (*env)->NewStringUTF (env, r);
  free (r);
  return jr;

 ret_error:
  return NULL;
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
    goto ret_error;
  }
  return (jlong) r;

 ret_error:
  return -1;
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
    goto ret_error;
  }
  return;

 ret_error:
  return;
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
    goto ret_error;
  }
  jr = (*env)->NewStringUTF (env, r);
  free (r);
  return jr;

 ret_error:
  return NULL;
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
    goto ret_error;
  }
  return (jboolean) r;

 ret_error:
  return -1;
}


JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1internal_1exit  (JNIEnv *env, jobject obj, jlong jg)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;


  r = guestfs_internal_exit (g);


  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    goto ret_error;
  }
  return;

 ret_error:
  return;
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
    goto ret_error;
  }
  return;

 ret_error:
  return;
}


JNIEXPORT jstring JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1internal_1test_1rconststringerr  (JNIEnv *env, jobject obj, jlong jg)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  const char *r;


  r = guestfs_internal_test_rconststringerr (g);


  if (r == NULL) {
    throw_exception (env, guestfs_last_error (g));
    goto ret_error;
  }
  return (*env)->NewStringUTF (env, r);

 ret_error:
  return NULL;
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
    goto ret_error;
  }
  return (jboolean) r;

 ret_error:
  return -1;
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
    goto ret_error;
  }
  return (jboolean) r;

 ret_error:
  return -1;
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
    goto ret_error;
  }
  return (jboolean) r;

 ret_error:
  return -1;
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
    goto ret_error;
  }
  return (jboolean) r;

 ret_error:
  return -1;
}


JNIEXPORT jlong JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1journal_1get_1realtime_1usec  (JNIEnv *env, jobject obj, jlong jg)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int64_t r;


  r = guestfs_journal_get_realtime_usec (g);


  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    goto ret_error;
  }
  return (jlong) r;

 ret_error:
  return -1;
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
    goto ret_error;
  }
  return;

 ret_error:
  return;
}


JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1launch  (JNIEnv *env, jobject obj, jlong jg)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;


  r = guestfs_launch (g);


  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    goto ret_error;
  }
  return;

 ret_error:
  return;
}


JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1ldmtool_1remove_1all  (JNIEnv *env, jobject obj, jlong jg)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;


  r = guestfs_ldmtool_remove_all (g);


  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    goto ret_error;
  }
  return;

 ret_error:
  return;
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
    goto ret_error;
  }
  jr = (*env)->NewStringUTF (env, r);
  free (r);
  return jr;

 ret_error:
  return NULL;
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
    goto ret_error;
  }
  jr = (*env)->NewStringUTF (env, r);
  free (r);
  return jr;

 ret_error:
  return NULL;
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
    goto ret_error;
  }
  return;

 ret_error:
  return;
}


JNIEXPORT jobject JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1lstatns  (JNIEnv *env, jobject obj, jlong jg, jstring jpath)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  jobject jr;
  jclass cl;
  jfieldID fl;
  CLEANUP_FREE_STATNS struct guestfs_statns *r = NULL;
  const char *path;

  path = (*env)->GetStringUTFChars (env, jpath, NULL);

  r = guestfs_lstatns (g, path);

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


JNIEXPORT jobjectArray JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1lxattrlist  (JNIEnv *env, jobject obj, jlong jg, jstring jpath, jobjectArray jnames)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  jobjectArray jr;
  jclass cl;
  jfieldID fl;
  jobject jfl;
  CLEANUP_FREE_XATTR_LIST struct guestfs_xattr_list *r = NULL;
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

  r = guestfs_lxattrlist (g, path, names);

  (*env)->ReleaseStringUTFChars (env, jpath, path);
  for (i = 0; i < names_len; ++i) {
    jobject o = (*env)->GetObjectArrayElement (env, jnames, i);
    (*env)->ReleaseStringUTFChars (env, o, names[i]);
  }

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
    goto ret_error;
  }
  return;

 ret_error:
  return;
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
    goto ret_error;
  }
  return;

 ret_error:
  return;
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
    goto ret_error;
  }
  return;

 ret_error:
  return;
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
    goto ret_error;
  }
  return;

 ret_error:
  return;
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
    goto ret_error;
  }
  return;

 ret_error:
  return;
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
    goto ret_error;
  }
  return;

 ret_error:
  return;
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
    goto ret_error;
  }
  return;

 ret_error:
  return;
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
    goto ret_error;
  }
  return;

 ret_error:
  return;
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
    goto ret_error;
  }
  return;

 ret_error:
  return;
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
    goto ret_error;
  }
  return;

 ret_error:
  return;
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
    goto ret_error;
  }
  jr = (*env)->NewStringUTF (env, r);
  free (r);
  return jr;

 ret_error:
  return NULL;
}


JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1ping_1daemon  (JNIEnv *env, jobject obj, jlong jg)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;


  r = guestfs_ping_daemon (g);


  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    goto ret_error;
  }
  return;

 ret_error:
  return;
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
    goto ret_error;
  }
  return;

 ret_error:
  return;
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
    goto ret_error;
  }
  return;

 ret_error:
  return;
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
    goto ret_error;
  }
  return;

 ret_error:
  return;
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
    goto ret_error;
  }
  return;

 ret_error:
  return;
}


JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1set_1backend_1settings  (JNIEnv *env, jobject obj, jlong jg, jobjectArray jsettings)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  size_t settings_len;
  CLEANUP_FREE char **settings = NULL;
  size_t i;

  settings_len = (*env)->GetArrayLength (env, jsettings);
  settings = malloc (sizeof (char *) * (settings_len+1));
  if (settings == NULL) {
    throw_out_of_memory (env, "malloc");
    goto ret_error;
  }
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

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    goto ret_error;
  }
  return;

 ret_error:
  return;
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
    goto ret_error;
  }
  return;

 ret_error:
  return;
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
    goto ret_error;
  }
  return;

 ret_error:
  return;
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
    goto ret_error;
  }
  return;

 ret_error:
  return;
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
    goto ret_error;
  }
  return;

 ret_error:
  return;
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
    goto ret_error;
  }
  return;

 ret_error:
  return;
}


JNIEXPORT jobject JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1statvfs  (JNIEnv *env, jobject obj, jlong jg, jstring jpath)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  jobject jr;
  jclass cl;
  jfieldID fl;
  CLEANUP_FREE_STATVFS struct guestfs_statvfs *r = NULL;
  const char *path;

  path = (*env)->GetStringUTFChars (env, jpath, NULL);

  r = guestfs_statvfs (g, path);

  (*env)->ReleaseStringUTFChars (env, jpath, path);

  if (r == NULL) {
    throw_exception (env, guestfs_last_error (g));
    goto ret_error;
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
  return jr;

 ret_error:
  return NULL;
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
    goto ret_error;
  }
  return;

 ret_error:
  return;
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
    goto ret_error;
  }
  return;

 ret_error:
  return;
}


JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1tar_1in  (JNIEnv *env, jobject obj, jlong jg, jstring jtarfile, jstring jdirectory, jlong joptargs_bitmask, jstring jcompress, jboolean jxattrs, jboolean jselinux, jboolean jacls)
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
  optargs_s.xattrs = jxattrs;
  optargs_s.selinux = jselinux;
  optargs_s.acls = jacls;
  optargs_s.bitmask = joptargs_bitmask;

  r = guestfs_tar_in_opts_argv (g, tarfile, directory, optargs);

  (*env)->ReleaseStringUTFChars (env, jtarfile, tarfile);
  (*env)->ReleaseStringUTFChars (env, jdirectory, directory);
  (*env)->ReleaseStringUTFChars (env, jcompress, optargs_s.compress);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    goto ret_error;
  }
  return;

 ret_error:
  return;
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
    goto ret_error;
  }
  return;

 ret_error:
  return;
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
    goto ret_error;
  }
  return;

 ret_error:
  return;
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
    goto ret_error;
  }
  return;

 ret_error:
  return;
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
    goto ret_error;
  }
  return;

 ret_error:
  return;
}


JNIEXPORT jobject JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1version  (JNIEnv *env, jobject obj, jlong jg)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  jobject jr;
  jclass cl;
  jfieldID fl;
  CLEANUP_FREE_VERSION struct guestfs_version *r = NULL;


  r = guestfs_version (g);


  if (r == NULL) {
    throw_exception (env, guestfs_last_error (g));
    goto ret_error;
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
  return jr;

 ret_error:
  return NULL;
}


JNIEXPORT jlong JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1vfs_1minimum_1size  (JNIEnv *env, jobject obj, jlong jg, jstring jmountable)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int64_t r;
  const char *mountable;

  mountable = (*env)->GetStringUTFChars (env, jmountable, NULL);

  r = guestfs_vfs_minimum_size (g, mountable);

  (*env)->ReleaseStringUTFChars (env, jmountable, mountable);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    goto ret_error;
  }
  return (jlong) r;

 ret_error:
  return -1;
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
    goto ret_error;
  }
  jr = (*env)->NewStringUTF (env, r);
  free (r);
  return jr;

 ret_error:
  return NULL;
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
    goto ret_error;
  }
  return;

 ret_error:
  return;
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
    goto ret_error;
  }
  return;

 ret_error:
  return;
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
    goto ret_error;
  }
  return;

 ret_error:
  return;
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

