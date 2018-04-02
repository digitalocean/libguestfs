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
    goto ret_error;
  }
  return;

 ret_error:
  return;
}


JNIEXPORT jint JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1add_1libvirt_1dom  (JNIEnv *env, jobject obj, jlong jg, jlong jdom, jlong joptargs_bitmask, jboolean jreadonly, jstring jiface, jboolean jlive, jstring jreadonlydisk, jstring jcachemode, jstring jdiscard, jboolean jcopyonread)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  void * /* virDomainPtr */ dom;
  struct guestfs_add_libvirt_dom_argv optargs_s;
  const struct guestfs_add_libvirt_dom_argv *optargs = &optargs_s;

  dom = POINTER_NOT_IMPLEMENTED ("virDomainPtr");

  optargs_s.readonly = jreadonly;
  optargs_s.iface = (*env)->GetStringUTFChars (env, jiface, NULL);
  optargs_s.live = jlive;
  optargs_s.readonlydisk = (*env)->GetStringUTFChars (env, jreadonlydisk, NULL);
  optargs_s.cachemode = (*env)->GetStringUTFChars (env, jcachemode, NULL);
  optargs_s.discard = (*env)->GetStringUTFChars (env, jdiscard, NULL);
  optargs_s.copyonread = jcopyonread;
  optargs_s.bitmask = joptargs_bitmask;

  r = guestfs_add_libvirt_dom_argv (g, dom, optargs);

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
    goto ret_error;
  }
  return;

 ret_error:
  return;
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
    goto ret_error;
  }
  return;

 ret_error:
  return;
}


JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1aug_1load  (JNIEnv *env, jobject obj, jlong jg)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;


  r = guestfs_aug_load (g);


  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    goto ret_error;
  }
  return;

 ret_error:
  return;
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
    goto ret_error;
  }
  return (jint) r;

 ret_error:
  return -1;
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
    goto ret_error;
  }
  return;

 ret_error:
  return;
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
Java_com_redhat_et_libguestfs_GuestFS__1blockdev_1setra  (JNIEnv *env, jobject obj, jlong jg, jstring jdevice, jint jsectors)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *device;
  int sectors;

  device = (*env)->GetStringUTFChars (env, jdevice, NULL);
  sectors = jsectors;

  r = guestfs_blockdev_setra (g, device, sectors);

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
Java_com_redhat_et_libguestfs_GuestFS__1btrfs_1scrub_1start  (JNIEnv *env, jobject obj, jlong jg, jstring jpath)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *path;

  path = (*env)->GetStringUTFChars (env, jpath, NULL);

  r = guestfs_btrfs_scrub_start (g, path);

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
Java_com_redhat_et_libguestfs_GuestFS__1btrfs_1scrub_1status  (JNIEnv *env, jobject obj, jlong jg, jstring jpath)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  jobject jr;
  jclass cl;
  jfieldID fl;
  CLEANUP_FREE_BTRFSSCRUB struct guestfs_btrfsscrub *r = NULL;
  const char *path;

  path = (*env)->GetStringUTFChars (env, jpath, NULL);

  r = guestfs_btrfs_scrub_status (g, path);

  (*env)->ReleaseStringUTFChars (env, jpath, path);

  if (r == NULL) {
    throw_exception (env, guestfs_last_error (g));
    goto ret_error;
  }
  cl = (*env)->FindClass (env, "com/redhat/et/libguestfs/BTRFSScrub");
  jr = (*env)->AllocObject (env, cl);
  fl = (*env)->GetFieldID (env, cl, "btrfsscrub_data_extents_scrubbed", "J");
  (*env)->SetLongField (env, jr, fl, r->btrfsscrub_data_extents_scrubbed);
  fl = (*env)->GetFieldID (env, cl, "btrfsscrub_tree_extents_scrubbed", "J");
  (*env)->SetLongField (env, jr, fl, r->btrfsscrub_tree_extents_scrubbed);
  fl = (*env)->GetFieldID (env, cl, "btrfsscrub_data_bytes_scrubbed", "J");
  (*env)->SetLongField (env, jr, fl, r->btrfsscrub_data_bytes_scrubbed);
  fl = (*env)->GetFieldID (env, cl, "btrfsscrub_tree_bytes_scrubbed", "J");
  (*env)->SetLongField (env, jr, fl, r->btrfsscrub_tree_bytes_scrubbed);
  fl = (*env)->GetFieldID (env, cl, "btrfsscrub_read_errors", "J");
  (*env)->SetLongField (env, jr, fl, r->btrfsscrub_read_errors);
  fl = (*env)->GetFieldID (env, cl, "btrfsscrub_csum_errors", "J");
  (*env)->SetLongField (env, jr, fl, r->btrfsscrub_csum_errors);
  fl = (*env)->GetFieldID (env, cl, "btrfsscrub_verify_errors", "J");
  (*env)->SetLongField (env, jr, fl, r->btrfsscrub_verify_errors);
  fl = (*env)->GetFieldID (env, cl, "btrfsscrub_no_csum", "J");
  (*env)->SetLongField (env, jr, fl, r->btrfsscrub_no_csum);
  fl = (*env)->GetFieldID (env, cl, "btrfsscrub_csum_discards", "J");
  (*env)->SetLongField (env, jr, fl, r->btrfsscrub_csum_discards);
  fl = (*env)->GetFieldID (env, cl, "btrfsscrub_super_errors", "J");
  (*env)->SetLongField (env, jr, fl, r->btrfsscrub_super_errors);
  fl = (*env)->GetFieldID (env, cl, "btrfsscrub_malloc_errors", "J");
  (*env)->SetLongField (env, jr, fl, r->btrfsscrub_malloc_errors);
  fl = (*env)->GetFieldID (env, cl, "btrfsscrub_uncorrectable_errors", "J");
  (*env)->SetLongField (env, jr, fl, r->btrfsscrub_uncorrectable_errors);
  fl = (*env)->GetFieldID (env, cl, "btrfsscrub_unverified_errors", "J");
  (*env)->SetLongField (env, jr, fl, r->btrfsscrub_unverified_errors);
  fl = (*env)->GetFieldID (env, cl, "btrfsscrub_corrected_errors", "J");
  (*env)->SetLongField (env, jr, fl, r->btrfsscrub_corrected_errors);
  fl = (*env)->GetFieldID (env, cl, "btrfsscrub_last_physical", "J");
  (*env)->SetLongField (env, jr, fl, r->btrfsscrub_last_physical);
  return jr;

 ret_error:
  return NULL;
}


JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1btrfs_1subvolume_1create  (JNIEnv *env, jobject obj, jlong jg, jstring jdest, jlong joptargs_bitmask, jstring jqgroupid)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *dest;
  struct guestfs_btrfs_subvolume_create_opts_argv optargs_s;
  const struct guestfs_btrfs_subvolume_create_opts_argv *optargs = &optargs_s;

  dest = (*env)->GetStringUTFChars (env, jdest, NULL);

  optargs_s.qgroupid = (*env)->GetStringUTFChars (env, jqgroupid, NULL);
  optargs_s.bitmask = joptargs_bitmask;

  r = guestfs_btrfs_subvolume_create_opts_argv (g, dest, optargs);

  (*env)->ReleaseStringUTFChars (env, jdest, dest);
  (*env)->ReleaseStringUTFChars (env, jqgroupid, optargs_s.qgroupid);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    goto ret_error;
  }
  return;

 ret_error:
  return;
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
    goto ret_error;
  }
  return;

 ret_error:
  return;
}


JNIEXPORT void JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1btrfs_1subvolume_1snapshot  (JNIEnv *env, jobject obj, jlong jg, jstring jsource, jstring jdest, jlong joptargs_bitmask, jboolean jro, jstring jqgroupid)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;
  const char *source;
  const char *dest;
  struct guestfs_btrfs_subvolume_snapshot_opts_argv optargs_s;
  const struct guestfs_btrfs_subvolume_snapshot_opts_argv *optargs = &optargs_s;

  source = (*env)->GetStringUTFChars (env, jsource, NULL);
  dest = (*env)->GetStringUTFChars (env, jdest, NULL);

  optargs_s.ro = jro;
  optargs_s.qgroupid = (*env)->GetStringUTFChars (env, jqgroupid, NULL);
  optargs_s.bitmask = joptargs_bitmask;

  r = guestfs_btrfs_subvolume_snapshot_opts_argv (g, source, dest, optargs);

  (*env)->ReleaseStringUTFChars (env, jsource, source);
  (*env)->ReleaseStringUTFChars (env, jdest, dest);
  (*env)->ReleaseStringUTFChars (env, jqgroupid, optargs_s.qgroupid);

  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    goto ret_error;
  }
  return;

 ret_error:
  return;
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
    goto ret_error;
  }
  jr = (*env)->NewStringUTF (env, r);
  free (r);
  return jr;

 ret_error:
  return NULL;
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
    goto ret_error;
  }
  jr = (*env)->NewStringUTF (env, r);
  free (r);
  return jr;

 ret_error:
  return NULL;
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
    goto ret_error;
  }
  return;

 ret_error:
  return;
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
    goto ret_error;
  }
  return;

 ret_error:
  return;
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
    goto ret_error;
  }
  return;

 ret_error:
  return;
}


JNIEXPORT jobjectArray JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1find_1inode  (JNIEnv *env, jobject obj, jlong jg, jstring jdevice, jlong jinode)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  jobjectArray jr;
  jclass cl;
  jfieldID fl;
  jobject jfl;
  CLEANUP_FREE_TSK_DIRENT_LIST struct guestfs_tsk_dirent_list *r = NULL;
  const char *device;
  int64_t inode;
  size_t i;

  device = (*env)->GetStringUTFChars (env, jdevice, NULL);
  inode = jinode;

  r = guestfs_find_inode (g, device, inode);

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
    goto ret_error;
  }
  jr = (*env)->NewStringUTF (env, r);
  free (r);
  return jr;

 ret_error:
  return NULL;
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
    goto ret_error;
  }
  return;

 ret_error:
  return;
}


JNIEXPORT jboolean JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1get_1autosync  (JNIEnv *env, jobject obj, jlong jg)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;


  r = guestfs_get_autosync (g);


  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    goto ret_error;
  }
  return (jboolean) r;

 ret_error:
  return -1;
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
    goto ret_error;
  }
  jr = (*env)->NewStringUTF (env, r);
  free (r);
  return jr;

 ret_error:
  return NULL;
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
    goto ret_error;
  }
  jr = (*env)->NewStringUTF (env, r);
  free (r);
  return jr;

 ret_error:
  return NULL;
}


JNIEXPORT jint JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1get_1pid  (JNIEnv *env, jobject obj, jlong jg)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;


  r = guestfs_get_pid (g);


  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    goto ret_error;
  }
  return (jint) r;

 ret_error:
  return -1;
}


JNIEXPORT jboolean JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1get_1selinux  (JNIEnv *env, jobject obj, jlong jg)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;


  r = guestfs_get_selinux (g);


  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    goto ret_error;
  }
  return (jboolean) r;

 ret_error:
  return -1;
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
    goto ret_error;
  }
  jr = (*env)->NewStringUTF (env, r);
  free (r);
  return jr;

 ret_error:
  return NULL;
}


JNIEXPORT jobjectArray JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1hivex_1node_1children  (JNIEnv *env, jobject obj, jlong jg, jlong jnodeh)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  jobjectArray jr;
  jclass cl;
  jfieldID fl;
  jobject jfl;
  CLEANUP_FREE_HIVEX_NODE_LIST struct guestfs_hivex_node_list *r = NULL;
  int64_t nodeh;
  size_t i;

  nodeh = jnodeh;

  r = guestfs_hivex_node_children (g, nodeh);


  if (r == NULL) {
    throw_exception (env, guestfs_last_error (g));
    goto ret_error;
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

  return jr;

 ret_error:
  return NULL;
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
    goto ret_error;
  }
  jr = (*env)->NewStringUTF (env, r);
  free (r);
  return jr;

 ret_error:
  return NULL;
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
    goto ret_error;
  }
  jr = (*env)->NewStringUTF (env, r);
  free (r);
  return jr;

 ret_error:
  return NULL;
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
    goto ret_error;
  }
  return (jboolean) r;

 ret_error:
  return -1;
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
    goto ret_error;
  }
  return (jboolean) r;

 ret_error:
  return -1;
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
Java_com_redhat_et_libguestfs_GuestFS__1is_1busy  (JNIEnv *env, jobject obj, jlong jg)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;


  r = guestfs_is_busy (g);


  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    goto ret_error;
  }
  return (jboolean) r;

 ret_error:
  return -1;
}


JNIEXPORT jboolean JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1is_1ready  (JNIEnv *env, jobject obj, jlong jg)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;


  r = guestfs_is_ready (g);


  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    goto ret_error;
  }
  return (jboolean) r;

 ret_error:
  return -1;
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
Java_com_redhat_et_libguestfs_GuestFS__1lgetxattrs  (JNIEnv *env, jobject obj, jlong jg, jstring jpath)
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

  r = guestfs_lgetxattrs (g, path);

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
    goto ret_error;
  }
  return;

 ret_error:
  return;
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
    goto ret_error;
  }
  jr = (*env)->NewStringUTF (env, r);
  free (r);
  return jr;

 ret_error:
  return NULL;
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
    goto ret_error;
  }
  return;

 ret_error:
  return;
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
    goto ret_error;
  }
  return;

 ret_error:
  return;
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
    goto ret_error;
  }
  jr = (*env)->NewStringUTF (env, r);
  free (r);
  return jr;

 ret_error:
  return NULL;
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
    goto ret_error;
  }
  return;

 ret_error:
  return;
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
    goto ret_error;
  }
  return;

 ret_error:
  return;
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
    goto ret_error;
  }
  return;

 ret_error:
  return;
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
    goto ret_error;
  }
  return;

 ret_error:
  return;
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
    goto ret_error;
  }
  return;

 ret_error:
  return;
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
    goto ret_error;
  }
  return;

 ret_error:
  return;
}


JNIEXPORT jstring JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1part_1get_1gpt_1guid  (JNIEnv *env, jobject obj, jlong jg, jstring jdevice, jint jpartnum)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  jstring jr;
  char *r;
  const char *device;
  int partnum;

  device = (*env)->GetStringUTFChars (env, jdevice, NULL);
  partnum = jpartnum;

  r = guestfs_part_get_gpt_guid (g, device, partnum);

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
    goto ret_error;
  }
  return (jint) r;

 ret_error:
  return -1;
}


JNIEXPORT jstring JNICALL
Java_com_redhat_et_libguestfs_GuestFS__1part_1get_1mbr_1part_1type  (JNIEnv *env, jobject obj, jlong jg, jstring jdevice, jint jpartnum)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  jstring jr;
  char *r;
  const char *device;
  int partnum;

  device = (*env)->GetStringUTFChars (env, jdevice, NULL);
  partnum = jpartnum;

  r = guestfs_part_get_mbr_part_type (g, device, partnum);

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
    goto ret_error;
  }
  jr = (*env)->NewStringUTF (env, r);
  free (r);
  return jr;

 ret_error:
  return NULL;
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
    goto ret_error;
  }
  return;

 ret_error:
  return;
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
    goto ret_error;
  }
  return (jint) r;

 ret_error:
  return -1;
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
    goto ret_error;
  }
  jr = (*env)->NewStringUTF (env, r);
  free (r);
  return jr;

 ret_error:
  return NULL;
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

  r = guestfs_readlinklist (g, path, names);

  (*env)->ReleaseStringUTFChars (env, jpath, path);
  for (i = 0; i < names_len; ++i) {
    jobject o = (*env)->GetObjectArrayElement (env, jnames, i);
    (*env)->ReleaseStringUTFChars (env, o, names[i]);
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
    goto ret_error;
  }
  return;

 ret_error:
  return;
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
    goto ret_error;
  }
  return;

 ret_error:
  return;
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
    goto ret_error;
  }
  return;

 ret_error:
  return;
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
    goto ret_error;
  }
  return;

 ret_error:
  return;
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
    goto ret_error;
  }
  return;

 ret_error:
  return;
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
Java_com_redhat_et_libguestfs_GuestFS__1shutdown  (JNIEnv *env, jobject obj, jlong jg)
{
  guestfs_h *g = (guestfs_h *) (long) jg;
  int r;


  r = guestfs_shutdown (g);


  if (r == -1) {
    throw_exception (env, guestfs_last_error (g));
    goto ret_error;
  }
  return;

 ret_error:
  return;
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
    goto ret_error;
  }
  return;

 ret_error:
  return;
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
    goto ret_error;
  }
  return;

 ret_error:
  return;
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
    goto ret_error;
  }
  return (jint) r;

 ret_error:
  return -1;
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
    goto ret_error;
  }
  return;

 ret_error:
  return;
}

