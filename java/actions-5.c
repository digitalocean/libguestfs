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
    goto ret_error;
  }
  return;

 ret_error:
  return;
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
    goto ret_error;
  }
  return;

 ret_error:
  return;
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
    goto ret_error;
  }
  return;

 ret_error:
  return;
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
    goto ret_error;
  }
  return;

 ret_error:
  return;
}


JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1btrfs_1balance_1pause  (JNIEnv *env, jobject obj, jlong jg, jstring jpath)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *path;

  path = (*env)->GetStringUTFChars (env, jpath, NULL);

  r = guestfs_btrfs_balance_pause (g, path);

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
Java_com_redhat_et_libguestfs_GuestFS__1btrfs_1device_1add  (JNIEnv *env, jobject obj, jlong jg, jobjectArray jdevices, jstring jfs)
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

  r = guestfs_btrfs_device_add (g, devices, fs);

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
    goto ret_error;
  }
  return;

 ret_error:
  return;
}


JNIEXPORT jobjectArray JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1btrfs_1filesystem_1show  (JNIEnv *env, jobject obj, jlong jg, jstring jdevice)
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

  r = guestfs_btrfs_filesystem_show (g, device);

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
Java_com_redhat_et_libguestfs_GuestFS__1btrfs_1qgroup_1assign  (JNIEnv *env, jobject obj, jlong jg, jstring jsrc, jstring jdst, jstring jpath)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *src;
  const char *dst;
  const char *path;

  src = (*env)->GetStringUTFChars (env, jsrc, NULL);
  dst = (*env)->GetStringUTFChars (env, jdst, NULL);
  path = (*env)->GetStringUTFChars (env, jpath, NULL);

  r = guestfs_btrfs_qgroup_assign (g, src, dst, path);

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
Java_com_redhat_et_libguestfs_GuestFS__1btrfs_1replace  (JNIEnv *env, jobject obj, jlong jg, jstring jsrcdev, jstring jtargetdev, jstring jmntpoint)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *srcdev;
  const char *targetdev;
  const char *mntpoint;

  srcdev = (*env)->GetStringUTFChars (env, jsrcdev, NULL);
  targetdev = (*env)->GetStringUTFChars (env, jtargetdev, NULL);
  mntpoint = (*env)->GetStringUTFChars (env, jmntpoint, NULL);

  r = guestfs_btrfs_replace (g, srcdev, targetdev, mntpoint);

  (*env)->ReleaseStringUTFChars (env, jsrcdev, srcdev);
  (*env)->ReleaseStringUTFChars (env, jtargetdev, targetdev);
  (*env)->ReleaseStringUTFChars (env, jmntpoint, mntpoint);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    goto ret_error;
  }
  return;

 ret_error:
  return;
}


JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1btrfs_1scrub_1cancel  (JNIEnv *env, jobject obj, jlong jg, jstring jpath)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *path;

  path = (*env)->GetStringUTFChars (env, jpath, NULL);

  r = guestfs_btrfs_scrub_cancel (g, path);

  (*env)->ReleaseStringUTFChars (env, jpath, path);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    goto ret_error;
  }
  return;

 ret_error:
  return;
}


JNIEXPORT jlong JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1btrfs_1subvolume_1get_1default  (JNIEnv *env, jobject obj, jlong jg, jstring jfs)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int64_t r;
  const char *fs;

  fs = (*env)->GetStringUTFChars (env, jfs, NULL);

  r = guestfs_btrfs_subvolume_get_default (g, fs);

  (*env)->ReleaseStringUTFChars (env, jfs, fs);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    goto ret_error;
  }
  return (jlong) r;

 ret_error:
  return -1;
}


JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1btrfstune_1seeding  (JNIEnv *env, jobject obj, jlong jg, jstring jdevice, jboolean jseeding)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *device;
  int seeding;

  device = (*env)->GetStringUTFChars (env, jdevice, NULL);
  seeding = jseeding;

  r = guestfs_btrfstune_seeding (g, device, seeding);

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
Java_com_redhat_et_libguestfs_GuestFS__1c_1pointer  (JNIEnv *env, jobject obj, jlong jg)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int64_t r;


  r = guestfs_c_pointer (g);


  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    goto ret_error;
  }
  return (jlong) r;

 ret_error:
  return -1;
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
    goto ret_error;
  }
  return;

 ret_error:
  return;
}


JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1copy_1file_1to_1device  (JNIEnv *env, jobject obj, jlong jg, jstring jsrc, jstring jdest, jlong joptargs_bitmask, jlong jsrcoffset, jlong jdestoffset, jlong jsize, jboolean jsparse, jboolean jappend)
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
  optargs_s.append = jappend;
  optargs_s.bitmask = joptargs_bitmask;

  r = guestfs_copy_file_to_device_argv (g, src, dest, optargs);

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
Java_com_redhat_et_libguestfs_GuestFS__1copy_1file_1to_1file  (JNIEnv *env, jobject obj, jlong jg, jstring jsrc, jstring jdest, jlong joptargs_bitmask, jlong jsrcoffset, jlong jdestoffset, jlong jsize, jboolean jsparse, jboolean jappend)
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
  optargs_s.append = jappend;
  optargs_s.bitmask = joptargs_bitmask;

  r = guestfs_copy_file_to_file_argv (g, src, dest, optargs);

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
    goto ret_error;
  }
  return;

 ret_error:
  return;
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
    goto ret_error;
  }
  return (jlong) r;

 ret_error:
  return -1;
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
    goto ret_error;
  }
  return;

 ret_error:
  return;
}


JNIEXPORT jboolean JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1feature_1available  (JNIEnv *env, jobject obj, jlong jg, jobjectArray jgroups)
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

  r = guestfs_feature_available (g, groups);

  for (i = 0; i < groups_len; ++i) {
    jobject o = (*env)->GetObjectArrayElement (env, jgroups, i);
    (*env)->ReleaseStringUTFChars (env, o, groups[i]);
  }

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    goto ret_error;
  }
  return (jboolean) r;

 ret_error:
  return -1;
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
    goto ret_error;
  }
  return;

 ret_error:
  return;
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
    goto ret_error;
  }
  return;

 ret_error:
  return;
}


JNIEXPORT jstring JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1get_1append  (JNIEnv *env, jobject obj, jlong jg)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  const char *r;


  r = guestfs_get_append (g);


  return (*env)->NewStringUTF (env, r); /* XXX r NULL? */
}


JNIEXPORT jint JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1get_1memsize  (JNIEnv *env, jobject obj, jlong jg)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;


  r = guestfs_get_memsize (g);


  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    goto ret_error;
  }
  return (jint) r;

 ret_error:
  return -1;
}


JNIEXPORT jstring JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1get_1program  (JNIEnv *env, jobject obj, jlong jg)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  const char *r;


  r = guestfs_get_program (g);


  if (r == NULL) {
    throw_exception (env, guestfs_last_error (g));
    goto ret_error;
  }
  return (*env)->NewStringUTF (env, r);

 ret_error:
  return NULL;
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
    goto ret_error;
  }
  return;

 ret_error:
  return;
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
    goto ret_error;
  }
  return;

 ret_error:
  return;
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
    goto ret_error;
  }
  jr = (*env)->NewStringUTF (env, r); // XXX size
  free (r);
  return jr;

 ret_error:
  return NULL;
}


JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1inotify_1close  (JNIEnv *env, jobject obj, jlong jg)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;


  r = guestfs_inotify_close (g);


  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    goto ret_error;
  }
  return;

 ret_error:
  return;
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
    goto ret_error;
  }
  return (jint) r;

 ret_error:
  return -1;
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
Java_com_redhat_et_libguestfs_GuestFS__1internal_1test  (JNIEnv *env, jobject obj, jlong jg, jstring jstr, jstring joptstr, jobjectArray jstrlist, jboolean jb, jint jinteger, jlong jinteger64, jstring jfilein, jstring jfileout, jbyteArray jbufferin, jlong joptargs_bitmask, jboolean jobool, jint joint, jlong joint64, jstring jostring, jobjectArray jostringlist)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *str;
  const char *optstr;
  size_t strlist_len;
  CLEANUP_FREE char **strlist = NULL;
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
  CLEANUP_FREE char **ostringlist = NULL;
  size_t i;

  str = (*env)->GetStringUTFChars (env, jstr, NULL);
  optstr = joptstr ? (*env)->GetStringUTFChars (env, joptstr, NULL) : NULL;
  strlist_len = (*env)->GetArrayLength (env, jstrlist);
  strlist = malloc (sizeof (char *) * (strlist_len+1));
  if (strlist == NULL) {
    throw_out_of_memory (env, "malloc");
    goto ret_error;
  }
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
  ostringlist = malloc (sizeof (char *) * (ostringlist_len+1));
  if (ostringlist == NULL) {
    throw_out_of_memory (env, "malloc");
    goto ret_error;
  }
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
  (*env)->ReleaseStringUTFChars (env, jfilein, filein);
  (*env)->ReleaseStringUTFChars (env, jfileout, fileout);
  (*env)->ReleaseByteArrayElements (env, jbufferin, (jbyte *) bufferin, 0);
  (*env)->ReleaseStringUTFChars (env, jostring, optargs_s.ostring);
  for (i = 0; i < ostringlist_len; ++i) {
    jobject o = (*env)->GetObjectArrayElement (env, jostringlist, i);
    (*env)->ReleaseStringUTFChars (env, o, optargs_s.ostringlist[i]);
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
    goto ret_error;
  }
  return;

 ret_error:
  return;
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
    goto ret_error;
  }
  return (jboolean) r;

 ret_error:
  return -1;
}


JNIEXPORT jboolean JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1is_1config  (JNIEnv *env, jobject obj, jlong jg)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;


  r = guestfs_is_config (g);


  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    goto ret_error;
  }
  return (jboolean) r;

 ret_error:
  return -1;
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
    goto ret_error;
  }
  return (jboolean) r;

 ret_error:
  return -1;
}


JNIEXPORT jobject JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1isoinfo_1device  (JNIEnv *env, jobject obj, jlong jg, jstring jdevice)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  jobject jr;
  jclass cl;
  jfieldID fl;
  CLEANUP_FREE_ISOINFO struct guestfs_isoinfo *r = NULL;
  const char *device;

  device = (*env)->GetStringUTFChars (env, jdevice, NULL);

  r = guestfs_isoinfo_device (g, device);

  (*env)->ReleaseStringUTFChars (env, jdevice, device);

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
  return jr;

 ret_error:
  return NULL;
}


JNIEXPORT jboolean JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1journal_1next  (JNIEnv *env, jobject obj, jlong jg)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;


  r = guestfs_journal_next (g);


  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    goto ret_error;
  }
  return (jboolean) r;

 ret_error:
  return -1;
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
    goto ret_error;
  }
  return (jlong) r;

 ret_error:
  return -1;
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
    goto ret_error;
  }
  return;

 ret_error:
  return;
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
    goto ret_error;
  }
  return;

 ret_error:
  return;
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
    goto ret_error;
  }
  return;

 ret_error:
  return;
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
    goto ret_error;
  }
  return;

 ret_error:
  return;
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
    goto ret_error;
  }
  return;

 ret_error:
  return;
}


JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1lvm_1set_1filter  (JNIEnv *env, jobject obj, jlong jg, jobjectArray jdevices)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
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

  r = guestfs_lvm_set_filter (g, devices);

  for (i = 0; i < devices_len; ++i) {
    jobject o = (*env)->GetObjectArrayElement (env, jdevices, i);
    (*env)->ReleaseStringUTFChars (env, o, devices[i]);
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
Java_com_redhat_et_libguestfs_GuestFS__1lvs_1full  (JNIEnv *env, jobject obj, jlong jg)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  jobjectArray jr;
  jclass cl;
  jfieldID fl;
  jobject jfl;
  CLEANUP_FREE_LVM_LV_LIST struct guestfs_lvm_lv_list *r = NULL;
  size_t i;


  r = guestfs_lvs_full (g);


  if (r == NULL) {
    throw_exception (env, guestfs_last_error (g));
    goto ret_error;
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

  return jr;

 ret_error:
  return NULL;
}


JNIEXPORT jobjectArray JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1md_1stat  (JNIEnv *env, jobject obj, jlong jg, jstring jmd)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  jobjectArray jr;
  jclass cl;
  jfieldID fl;
  jobject jfl;
  CLEANUP_FREE_MDSTAT_LIST struct guestfs_mdstat_list *r = NULL;
  const char *md;
  size_t i;

  md = (*env)->GetStringUTFChars (env, jmd, NULL);

  r = guestfs_md_stat (g, md);

  (*env)->ReleaseStringUTFChars (env, jmd, md);

  if (r == NULL) {
    throw_exception (env, guestfs_last_error (g));
    goto ret_error;
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

  return jr;

 ret_error:
  return NULL;
}


JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1mkfs  (JNIEnv *env, jobject obj, jlong jg, jstring jfstype, jstring jdevice, jlong joptargs_bitmask, jint jblocksize, jstring jfeatures, jint jinode, jint jsectorsize, jstring jlabel)
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
  optargs_s.label = (*env)->GetStringUTFChars (env, jlabel, NULL);
  optargs_s.bitmask = joptargs_bitmask;

  r = guestfs_mkfs_opts_argv (g, fstype, device, optargs);

  (*env)->ReleaseStringUTFChars (env, jfstype, fstype);
  (*env)->ReleaseStringUTFChars (env, jdevice, device);
  (*env)->ReleaseStringUTFChars (env, jfeatures, optargs_s.features);
  (*env)->ReleaseStringUTFChars (env, jlabel, optargs_s.label);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    goto ret_error;
  }
  return;

 ret_error:
  return;
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
    goto ret_error;
  }
  return;

 ret_error:
  return;
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
    goto ret_error;
  }
  return;

 ret_error:
  return;
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
Java_com_redhat_et_libguestfs_GuestFS__1nr_1devices  (JNIEnv *env, jobject obj, jlong jg)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;


  r = guestfs_nr_devices (g);


  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    goto ret_error;
  }
  return (jint) r;

 ret_error:
  return -1;
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
    goto ret_error;
  }
  return;

 ret_error:
  return;
}


JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1parse_1environment_1list  (JNIEnv *env, jobject obj, jlong jg, jobjectArray jenvironment)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  size_t environment_len;
  CLEANUP_FREE char **environment = NULL;
  size_t i;

  environment_len = (*env)->GetArrayLength (env, jenvironment);
  environment = malloc (sizeof (char *) * (environment_len+1));
  if (environment == NULL) {
    throw_out_of_memory (env, "malloc");
    goto ret_error;
  }
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

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    goto ret_error;
  }
  return;

 ret_error:
  return;
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
    goto ret_error;
  }
  return (jboolean) r;

 ret_error:
  return -1;
}


JNIEXPORT jlong JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1part_1get_1gpt_1attributes  (JNIEnv *env, jobject obj, jlong jg, jstring jdevice, jint jpartnum)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int64_t r;
  const char *device;
  int partnum;

  device = (*env)->GetStringUTFChars (env, jdevice, NULL);
  partnum = jpartnum;

  r = guestfs_part_get_gpt_attributes (g, device, partnum);

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
    goto ret_error;
  }
  return;

 ret_error:
  return;
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
    goto ret_error;
  }
  return;

 ret_error:
  return;
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
    goto ret_error;
  }
  return;

 ret_error:
  return;
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
    goto ret_error;
  }
  return;

 ret_error:
  return;
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
    goto ret_error;
  }
  return;

 ret_error:
  return;
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
    goto ret_error;
  }
  return;

 ret_error:
  return;
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
    goto ret_error;
  }
  return;

 ret_error:
  return;
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
    goto ret_error;
  }
  return;

 ret_error:
  return;
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
    goto ret_error;
  }
  return;

 ret_error:
  return;
}


JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1set_1uuid_1random  (JNIEnv *env, jobject obj, jlong jg, jstring jdevice)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *device;

  device = (*env)->GetStringUTFChars (env, jdevice, NULL);

  r = guestfs_set_uuid_random (g, device);

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
Java_com_redhat_et_libguestfs_GuestFS__1sfdisk  (JNIEnv *env, jobject obj, jlong jg, jstring jdevice, jint jcyls, jint jheads, jint jsectors, jobjectArray jlines)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *device;
  int cyls;
  int heads;
  int sectors;
  size_t lines_len;
  CLEANUP_FREE char **lines = NULL;
  size_t i;

  device = (*env)->GetStringUTFChars (env, jdevice, NULL);
  cyls = jcyls;
  heads = jheads;
  sectors = jsectors;
  lines_len = (*env)->GetArrayLength (env, jlines);
  lines = malloc (sizeof (char *) * (lines_len+1));
  if (lines == NULL) {
    throw_out_of_memory (env, "malloc");
    goto ret_error;
  }
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

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    goto ret_error;
  }
  return;

 ret_error:
  return;
}


JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1sfdiskM  (JNIEnv *env, jobject obj, jlong jg, jstring jdevice, jobjectArray jlines)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *device;
  size_t lines_len;
  CLEANUP_FREE char **lines = NULL;
  size_t i;

  device = (*env)->GetStringUTFChars (env, jdevice, NULL);
  lines_len = (*env)->GetArrayLength (env, jlines);
  lines = malloc (sizeof (char *) * (lines_len+1));
  if (lines == NULL) {
    throw_out_of_memory (env, "malloc");
    goto ret_error;
  }
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

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    goto ret_error;
  }
  return;

 ret_error:
  return;
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
    goto ret_error;
  }
  return;

 ret_error:
  return;
}


JNIEXPORT jobject JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1stat  (JNIEnv *env, jobject obj, jlong jg, jstring jpath)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  jobject jr;
  jclass cl;
  jfieldID fl;
  CLEANUP_FREE_STAT struct guestfs_stat *r = NULL;
  const char *path;

  path = (*env)->GetStringUTFChars (env, jpath, NULL);

  r = guestfs_stat (g, path);

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
    goto ret_error;
  }
  return;

 ret_error:
  return;
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
    goto ret_error;
  }
  return;

 ret_error:
  return;
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
    goto ret_error;
  }
  return;

 ret_error:
  return;
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
    goto ret_error;
  }
  return;

 ret_error:
  return;
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
    goto ret_error;
  }
  return;

 ret_error:
  return;
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
    goto ret_error;
  }
  return;

 ret_error:
  return;
}


JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1user_1cancel  (JNIEnv *env, jobject obj, jlong jg)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;


  r = guestfs_user_cancel (g);


  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    goto ret_error;
  }
  return;

 ret_error:
  return;
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
    goto ret_error;
  }
  return;

 ret_error:
  return;
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
    goto ret_error;
  }
  return;

 ret_error:
  return;
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
    goto ret_error;
  }
  return (jint) r;

 ret_error:
  return -1;
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
    goto ret_error;
  }
  return;

 ret_error:
  return;
}


JNIEXPORT jobject JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1xfs_1info  (JNIEnv *env, jobject obj, jlong jg, jstring jpathordevice)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  jobject jr;
  jclass cl;
  jfieldID fl;
  CLEANUP_FREE_XFSINFO struct guestfs_xfsinfo *r = NULL;
  const char *pathordevice;

  pathordevice = (*env)->GetStringUTFChars (env, jpathordevice, NULL);

  r = guestfs_xfs_info (g, pathordevice);

  (*env)->ReleaseStringUTFChars (env, jpathordevice, pathordevice);

  if (r == NULL) {
    throw_exception (env, guestfs_last_error (g));
    goto ret_error;
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
  return jr;

 ret_error:
  return NULL;
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
    goto ret_error;
  }
  return (jint) r;

 ret_error:
  return -1;
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
    goto ret_error;
  }
  return;

 ret_error:
  return;
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
    goto ret_error;
  }
  return;

 ret_error:
  return;
}

