/* libguestfs generated file
 * WARNING: THIS FILE IS GENERATED FROM THE FOLLOWING FILES:
 *          generator/daemon.ml
 *          and from the code in the generator/ subdirectory.
 * ANY CHANGES YOU MAKE TO THIS FILE WILL BE LOST.
 *
 * Copyright (C) 2009-2018 Red Hat Inc.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

#include <config.h>

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <inttypes.h>
#include <errno.h>

#include <caml/alloc.h>
#include <caml/callback.h>
#include <caml/fail.h>
#include <caml/memory.h>
#include <caml/mlvalues.h>

#include "daemon.h"
#include "actions.h"
#include "daemon-c.h"

/* Implement RStruct ("partition", _). */
static guestfs_int_partition *
return_partition (value retv)
{
  guestfs_int_partition *ret;
  value v;

  ret = malloc (sizeof (*ret));
  if (ret == NULL) {
    reply_with_perror ("malloc");
    return NULL;
  }

  v = Field (retv, 0);
  ret->part_num = Int32_val (v);
  v = Field (retv, 1);
  ret->part_start = Int64_val (v);
  v = Field (retv, 2);
  ret->part_end = Int64_val (v);
  v = Field (retv, 3);
  ret->part_size = Int64_val (v);

  return ret;
}

/* Implement RStructList ("partition", _). */
static guestfs_int_partition_list *
return_partition_list (value retv)
{
  guestfs_int_partition_list *ret;
  guestfs_int_partition *r;
  size_t i, len;
  value v, rv;

  /* Count the number of elements in the list. */
  rv = retv;
  len = 0;
  while (rv != Val_int (0)) {
    len++;
    rv = Field (rv, 1);
  }

  ret = malloc (sizeof *ret);
  if (ret == NULL) {
    reply_with_perror ("malloc");
    return NULL;
  }
  ret->guestfs_int_partition_list_len = len;
  ret->guestfs_int_partition_list_val =
    calloc (len, sizeof (guestfs_int_partition));
  if (ret->guestfs_int_partition_list_val == NULL) {
    reply_with_perror ("calloc");
    free (ret);
    return NULL;
  }

  rv = retv;
  for (i = 0; i < len; ++i) {
    v = Field (rv, 0);
    r = return_partition (v);
    if (r == NULL)
      return NULL; /* XXX leaks memory along this error path */
    memcpy (&ret->guestfs_int_partition_list_val[i], r, sizeof (*r));
    free (r);
    rv = Field (rv, 1);
  }

  return ret;
}

/* Implement RStruct ("btrfssubvolume", _). */
static guestfs_int_btrfssubvolume *
return_btrfssubvolume (value retv)
{
  guestfs_int_btrfssubvolume *ret;
  value v;

  ret = malloc (sizeof (*ret));
  if (ret == NULL) {
    reply_with_perror ("malloc");
    return NULL;
  }

  v = Field (retv, 0);
  ret->btrfssubvolume_id = Int64_val (v);
  v = Field (retv, 1);
  ret->btrfssubvolume_top_level_id = Int64_val (v);
  v = Field (retv, 2);
  ret->btrfssubvolume_path = strdup (String_val (v));
  if (ret->btrfssubvolume_path == NULL) return NULL;

  return ret;
}

/* Implement RStructList ("btrfssubvolume", _). */
static guestfs_int_btrfssubvolume_list *
return_btrfssubvolume_list (value retv)
{
  guestfs_int_btrfssubvolume_list *ret;
  guestfs_int_btrfssubvolume *r;
  size_t i, len;
  value v, rv;

  /* Count the number of elements in the list. */
  rv = retv;
  len = 0;
  while (rv != Val_int (0)) {
    len++;
    rv = Field (rv, 1);
  }

  ret = malloc (sizeof *ret);
  if (ret == NULL) {
    reply_with_perror ("malloc");
    return NULL;
  }
  ret->guestfs_int_btrfssubvolume_list_len = len;
  ret->guestfs_int_btrfssubvolume_list_val =
    calloc (len, sizeof (guestfs_int_btrfssubvolume));
  if (ret->guestfs_int_btrfssubvolume_list_val == NULL) {
    reply_with_perror ("calloc");
    free (ret);
    return NULL;
  }

  rv = retv;
  for (i = 0; i < len; ++i) {
    v = Field (rv, 0);
    r = return_btrfssubvolume (v);
    if (r == NULL)
      return NULL; /* XXX leaks memory along this error path */
    memcpy (&ret->guestfs_int_btrfssubvolume_list_val[i], r, sizeof (*r));
    free (r);
    rv = Field (rv, 1);
  }

  return ret;
}

/* Implement RStruct ("statvfs", _). */
static guestfs_int_statvfs *
return_statvfs (value retv)
{
  guestfs_int_statvfs *ret;
  value v;

  ret = malloc (sizeof (*ret));
  if (ret == NULL) {
    reply_with_perror ("malloc");
    return NULL;
  }

  v = Field (retv, 0);
  ret->bsize = Int64_val (v);
  v = Field (retv, 1);
  ret->frsize = Int64_val (v);
  v = Field (retv, 2);
  ret->blocks = Int64_val (v);
  v = Field (retv, 3);
  ret->bfree = Int64_val (v);
  v = Field (retv, 4);
  ret->bavail = Int64_val (v);
  v = Field (retv, 5);
  ret->files = Int64_val (v);
  v = Field (retv, 6);
  ret->ffree = Int64_val (v);
  v = Field (retv, 7);
  ret->favail = Int64_val (v);
  v = Field (retv, 8);
  ret->fsid = Int64_val (v);
  v = Field (retv, 9);
  ret->flag = Int64_val (v);
  v = Field (retv, 10);
  ret->namemax = Int64_val (v);

  return ret;
}

/* Wrapper for OCaml function ‘Btrfs.btrfs_subvolume_get_default’. */
int64_t
do_btrfs_subvolume_get_default (const mountable_t *fs)
{
  static value *cb = NULL;
  CAMLparam0 ();
  CAMLlocal2 (v, retv);
  CAMLlocalN (args, 1);

  if (cb == NULL)
    cb = caml_named_value ("Btrfs.btrfs_subvolume_get_default");

  args[0] = guestfs_int_daemon_copy_mountable (fs);
  retv = caml_callbackN_exn (*cb, 1, args);

  if (Is_exception_result (retv)) {
    retv = Extract_exception (retv);
    guestfs_int_daemon_exn_to_reply_with_error ("btrfs_subvolume_get_default", retv);
    CAMLreturnT (int, -1);
  }

  CAMLreturnT (int, Int64_val (retv));
}

/* Wrapper for OCaml function ‘Btrfs.btrfs_subvolume_list’. */
guestfs_int_btrfssubvolume_list *
do_btrfs_subvolume_list (const mountable_t *fs)
{
  static value *cb = NULL;
  CAMLparam0 ();
  CAMLlocal2 (v, retv);
  CAMLlocalN (args, 1);

  if (cb == NULL)
    cb = caml_named_value ("Btrfs.btrfs_subvolume_list");

  args[0] = guestfs_int_daemon_copy_mountable (fs);
  retv = caml_callbackN_exn (*cb, 1, args);

  if (Is_exception_result (retv)) {
    retv = Extract_exception (retv);
    guestfs_int_daemon_exn_to_reply_with_error ("btrfs_subvolume_list", retv);
    CAMLreturnT (void *, NULL);
  }

  guestfs_int_btrfssubvolume_list *ret =
    return_btrfssubvolume_list (retv);
  /* caller frees */
  CAMLreturnT (guestfs_int_btrfssubvolume_list *, ret);
}

/* Wrapper for OCaml function ‘Realpath.case_sensitive_path’. */
char *
do_case_sensitive_path (const char *path)
{
  static value *cb = NULL;
  CAMLparam0 ();
  CAMLlocal2 (v, retv);
  CAMLlocalN (args, 1);

  if (cb == NULL)
    cb = caml_named_value ("Realpath.case_sensitive_path");

  args[0] = caml_copy_string (path);
  retv = caml_callbackN_exn (*cb, 1, args);

  if (Is_exception_result (retv)) {
    retv = Extract_exception (retv);
    guestfs_int_daemon_exn_to_reply_with_error ("case_sensitive_path", retv);
    CAMLreturnT (void *, NULL);
  }

  char *ret = strdup (String_val (retv));
  if (ret == NULL) {
    reply_with_perror ("strdup");
    CAMLreturnT (char *, NULL);
  }
  CAMLreturnT (char *, ret); /* caller frees */
}

/* Wrapper for OCaml function ‘Devsparts.device_index’. */
int
do_device_index (const char *device)
{
  static value *cb = NULL;
  CAMLparam0 ();
  CAMLlocal2 (v, retv);
  CAMLlocalN (args, 1);

  if (cb == NULL)
    cb = caml_named_value ("Devsparts.device_index");

  args[0] = caml_copy_string (device);
  retv = caml_callbackN_exn (*cb, 1, args);

  if (Is_exception_result (retv)) {
    retv = Extract_exception (retv);
    guestfs_int_daemon_exn_to_reply_with_error ("device_index", retv);
    CAMLreturnT (int, -1);
  }

  CAMLreturnT (int, Int_val (retv));
}

/* Wrapper for OCaml function ‘File.file’. */
char *
do_file (const char *path)
{
  static value *cb = NULL;
  CAMLparam0 ();
  CAMLlocal2 (v, retv);
  CAMLlocalN (args, 1);

  if (cb == NULL)
    cb = caml_named_value ("File.file");

  args[0] = caml_copy_string (path);
  retv = caml_callbackN_exn (*cb, 1, args);

  if (Is_exception_result (retv)) {
    retv = Extract_exception (retv);
    guestfs_int_daemon_exn_to_reply_with_error ("file", retv);
    CAMLreturnT (void *, NULL);
  }

  char *ret = strdup (String_val (retv));
  if (ret == NULL) {
    reply_with_perror ("strdup");
    CAMLreturnT (char *, NULL);
  }
  CAMLreturnT (char *, ret); /* caller frees */
}

/* Wrapper for OCaml function ‘Filearch.file_architecture’. */
char *
do_file_architecture (const char *filename)
{
  static value *cb = NULL;
  CAMLparam0 ();
  CAMLlocal2 (v, retv);
  CAMLlocalN (args, 1);

  if (cb == NULL)
    cb = caml_named_value ("Filearch.file_architecture");

  args[0] = caml_copy_string (filename);
  retv = caml_callbackN_exn (*cb, 1, args);

  if (Is_exception_result (retv)) {
    retv = Extract_exception (retv);
    guestfs_int_daemon_exn_to_reply_with_error ("file_architecture", retv);
    CAMLreturnT (void *, NULL);
  }

  char *ret = strdup (String_val (retv));
  if (ret == NULL) {
    reply_with_perror ("strdup");
    CAMLreturnT (char *, NULL);
  }
  CAMLreturnT (char *, ret); /* caller frees */
}

/* Wrapper for OCaml function ‘Findfs.findfs_label’. */
char *
do_findfs_label (const char *label)
{
  static value *cb = NULL;
  CAMLparam0 ();
  CAMLlocal2 (v, retv);
  CAMLlocalN (args, 1);

  if (cb == NULL)
    cb = caml_named_value ("Findfs.findfs_label");

  args[0] = caml_copy_string (label);
  retv = caml_callbackN_exn (*cb, 1, args);

  if (Is_exception_result (retv)) {
    retv = Extract_exception (retv);
    guestfs_int_daemon_exn_to_reply_with_error ("findfs_label", retv);
    CAMLreturnT (void *, NULL);
  }

  char *ret = strdup (String_val (retv));
  if (ret == NULL) {
    reply_with_perror ("strdup");
    CAMLreturnT (char *, NULL);
  }
  CAMLreturnT (char *, ret); /* caller frees */
}

/* Wrapper for OCaml function ‘Findfs.findfs_uuid’. */
char *
do_findfs_uuid (const char *uuid)
{
  static value *cb = NULL;
  CAMLparam0 ();
  CAMLlocal2 (v, retv);
  CAMLlocalN (args, 1);

  if (cb == NULL)
    cb = caml_named_value ("Findfs.findfs_uuid");

  args[0] = caml_copy_string (uuid);
  retv = caml_callbackN_exn (*cb, 1, args);

  if (Is_exception_result (retv)) {
    retv = Extract_exception (retv);
    guestfs_int_daemon_exn_to_reply_with_error ("findfs_uuid", retv);
    CAMLreturnT (void *, NULL);
  }

  char *ret = strdup (String_val (retv));
  if (ret == NULL) {
    reply_with_perror ("strdup");
    CAMLreturnT (char *, NULL);
  }
  CAMLreturnT (char *, ret); /* caller frees */
}

/* Wrapper for OCaml function ‘Inspect.inspect_get_arch’. */
char *
do_inspect_get_arch (const mountable_t *root)
{
  static value *cb = NULL;
  CAMLparam0 ();
  CAMLlocal2 (v, retv);
  CAMLlocalN (args, 1);

  if (cb == NULL)
    cb = caml_named_value ("Inspect.inspect_get_arch");

  args[0] = guestfs_int_daemon_copy_mountable (root);
  retv = caml_callbackN_exn (*cb, 1, args);

  if (Is_exception_result (retv)) {
    retv = Extract_exception (retv);
    guestfs_int_daemon_exn_to_reply_with_error ("inspect_get_arch", retv);
    CAMLreturnT (void *, NULL);
  }

  char *ret = strdup (String_val (retv));
  if (ret == NULL) {
    reply_with_perror ("strdup");
    CAMLreturnT (char *, NULL);
  }
  CAMLreturnT (char *, ret); /* caller frees */
}

/* Wrapper for OCaml function ‘Inspect.inspect_get_distro’. */
char *
do_inspect_get_distro (const mountable_t *root)
{
  static value *cb = NULL;
  CAMLparam0 ();
  CAMLlocal2 (v, retv);
  CAMLlocalN (args, 1);

  if (cb == NULL)
    cb = caml_named_value ("Inspect.inspect_get_distro");

  args[0] = guestfs_int_daemon_copy_mountable (root);
  retv = caml_callbackN_exn (*cb, 1, args);

  if (Is_exception_result (retv)) {
    retv = Extract_exception (retv);
    guestfs_int_daemon_exn_to_reply_with_error ("inspect_get_distro", retv);
    CAMLreturnT (void *, NULL);
  }

  char *ret = strdup (String_val (retv));
  if (ret == NULL) {
    reply_with_perror ("strdup");
    CAMLreturnT (char *, NULL);
  }
  CAMLreturnT (char *, ret); /* caller frees */
}

/* Wrapper for OCaml function ‘Inspect.inspect_get_drive_mappings’. */
char **
do_inspect_get_drive_mappings (const mountable_t *root)
{
  static value *cb = NULL;
  CAMLparam0 ();
  CAMLlocal2 (v, retv);
  CAMLlocalN (args, 1);

  if (cb == NULL)
    cb = caml_named_value ("Inspect.inspect_get_drive_mappings");

  args[0] = guestfs_int_daemon_copy_mountable (root);
  retv = caml_callbackN_exn (*cb, 1, args);

  if (Is_exception_result (retv)) {
    retv = Extract_exception (retv);
    guestfs_int_daemon_exn_to_reply_with_error ("inspect_get_drive_mappings", retv);
    CAMLreturnT (void *, NULL);
  }

  char **ret =
    guestfs_int_daemon_return_hashtable_string_string (retv);
  CAMLreturnT (char **, ret); /* caller frees */
}

/* Wrapper for OCaml function ‘Inspect.inspect_get_filesystems’. */
char **
do_inspect_get_filesystems (const mountable_t *root)
{
  static value *cb = NULL;
  CAMLparam0 ();
  CAMLlocal2 (v, retv);
  CAMLlocalN (args, 1);

  if (cb == NULL)
    cb = caml_named_value ("Inspect.inspect_get_filesystems");

  args[0] = guestfs_int_daemon_copy_mountable (root);
  retv = caml_callbackN_exn (*cb, 1, args);

  if (Is_exception_result (retv)) {
    retv = Extract_exception (retv);
    guestfs_int_daemon_exn_to_reply_with_error ("inspect_get_filesystems", retv);
    CAMLreturnT (void *, NULL);
  }

  char **ret =
    guestfs_int_daemon_return_string_mountable_list (retv);
  CAMLreturnT (char **, ret); /* caller frees */
}

/* Wrapper for OCaml function ‘Inspect.inspect_get_format’. */
char *
do_inspect_get_format (const mountable_t *root)
{
  static value *cb = NULL;
  CAMLparam0 ();
  CAMLlocal2 (v, retv);
  CAMLlocalN (args, 1);

  if (cb == NULL)
    cb = caml_named_value ("Inspect.inspect_get_format");

  args[0] = guestfs_int_daemon_copy_mountable (root);
  retv = caml_callbackN_exn (*cb, 1, args);

  if (Is_exception_result (retv)) {
    retv = Extract_exception (retv);
    guestfs_int_daemon_exn_to_reply_with_error ("inspect_get_format", retv);
    CAMLreturnT (void *, NULL);
  }

  char *ret = strdup (String_val (retv));
  if (ret == NULL) {
    reply_with_perror ("strdup");
    CAMLreturnT (char *, NULL);
  }
  CAMLreturnT (char *, ret); /* caller frees */
}

/* Wrapper for OCaml function ‘Inspect.inspect_get_hostname’. */
char *
do_inspect_get_hostname (const mountable_t *root)
{
  static value *cb = NULL;
  CAMLparam0 ();
  CAMLlocal2 (v, retv);
  CAMLlocalN (args, 1);

  if (cb == NULL)
    cb = caml_named_value ("Inspect.inspect_get_hostname");

  args[0] = guestfs_int_daemon_copy_mountable (root);
  retv = caml_callbackN_exn (*cb, 1, args);

  if (Is_exception_result (retv)) {
    retv = Extract_exception (retv);
    guestfs_int_daemon_exn_to_reply_with_error ("inspect_get_hostname", retv);
    CAMLreturnT (void *, NULL);
  }

  char *ret = strdup (String_val (retv));
  if (ret == NULL) {
    reply_with_perror ("strdup");
    CAMLreturnT (char *, NULL);
  }
  CAMLreturnT (char *, ret); /* caller frees */
}

/* Wrapper for OCaml function ‘Inspect.inspect_get_major_version’. */
int
do_inspect_get_major_version (const mountable_t *root)
{
  static value *cb = NULL;
  CAMLparam0 ();
  CAMLlocal2 (v, retv);
  CAMLlocalN (args, 1);

  if (cb == NULL)
    cb = caml_named_value ("Inspect.inspect_get_major_version");

  args[0] = guestfs_int_daemon_copy_mountable (root);
  retv = caml_callbackN_exn (*cb, 1, args);

  if (Is_exception_result (retv)) {
    retv = Extract_exception (retv);
    guestfs_int_daemon_exn_to_reply_with_error ("inspect_get_major_version", retv);
    CAMLreturnT (int, -1);
  }

  CAMLreturnT (int, Int_val (retv));
}

/* Wrapper for OCaml function ‘Inspect.inspect_get_minor_version’. */
int
do_inspect_get_minor_version (const mountable_t *root)
{
  static value *cb = NULL;
  CAMLparam0 ();
  CAMLlocal2 (v, retv);
  CAMLlocalN (args, 1);

  if (cb == NULL)
    cb = caml_named_value ("Inspect.inspect_get_minor_version");

  args[0] = guestfs_int_daemon_copy_mountable (root);
  retv = caml_callbackN_exn (*cb, 1, args);

  if (Is_exception_result (retv)) {
    retv = Extract_exception (retv);
    guestfs_int_daemon_exn_to_reply_with_error ("inspect_get_minor_version", retv);
    CAMLreturnT (int, -1);
  }

  CAMLreturnT (int, Int_val (retv));
}

/* Wrapper for OCaml function ‘Inspect.inspect_get_mountpoints’. */
char **
do_inspect_get_mountpoints (const mountable_t *root)
{
  static value *cb = NULL;
  CAMLparam0 ();
  CAMLlocal2 (v, retv);
  CAMLlocalN (args, 1);

  if (cb == NULL)
    cb = caml_named_value ("Inspect.inspect_get_mountpoints");

  args[0] = guestfs_int_daemon_copy_mountable (root);
  retv = caml_callbackN_exn (*cb, 1, args);

  if (Is_exception_result (retv)) {
    retv = Extract_exception (retv);
    guestfs_int_daemon_exn_to_reply_with_error ("inspect_get_mountpoints", retv);
    CAMLreturnT (void *, NULL);
  }

  char **ret =
    guestfs_int_daemon_return_hashtable_string_mountable (retv);
  CAMLreturnT (char **, ret); /* caller frees */
}

/* Wrapper for OCaml function ‘Inspect.inspect_get_package_format’. */
char *
do_inspect_get_package_format (const mountable_t *root)
{
  static value *cb = NULL;
  CAMLparam0 ();
  CAMLlocal2 (v, retv);
  CAMLlocalN (args, 1);

  if (cb == NULL)
    cb = caml_named_value ("Inspect.inspect_get_package_format");

  args[0] = guestfs_int_daemon_copy_mountable (root);
  retv = caml_callbackN_exn (*cb, 1, args);

  if (Is_exception_result (retv)) {
    retv = Extract_exception (retv);
    guestfs_int_daemon_exn_to_reply_with_error ("inspect_get_package_format", retv);
    CAMLreturnT (void *, NULL);
  }

  char *ret = strdup (String_val (retv));
  if (ret == NULL) {
    reply_with_perror ("strdup");
    CAMLreturnT (char *, NULL);
  }
  CAMLreturnT (char *, ret); /* caller frees */
}

/* Wrapper for OCaml function ‘Inspect.inspect_get_package_management’. */
char *
do_inspect_get_package_management (const mountable_t *root)
{
  static value *cb = NULL;
  CAMLparam0 ();
  CAMLlocal2 (v, retv);
  CAMLlocalN (args, 1);

  if (cb == NULL)
    cb = caml_named_value ("Inspect.inspect_get_package_management");

  args[0] = guestfs_int_daemon_copy_mountable (root);
  retv = caml_callbackN_exn (*cb, 1, args);

  if (Is_exception_result (retv)) {
    retv = Extract_exception (retv);
    guestfs_int_daemon_exn_to_reply_with_error ("inspect_get_package_management", retv);
    CAMLreturnT (void *, NULL);
  }

  char *ret = strdup (String_val (retv));
  if (ret == NULL) {
    reply_with_perror ("strdup");
    CAMLreturnT (char *, NULL);
  }
  CAMLreturnT (char *, ret); /* caller frees */
}

/* Wrapper for OCaml function ‘Inspect.inspect_get_product_name’. */
char *
do_inspect_get_product_name (const mountable_t *root)
{
  static value *cb = NULL;
  CAMLparam0 ();
  CAMLlocal2 (v, retv);
  CAMLlocalN (args, 1);

  if (cb == NULL)
    cb = caml_named_value ("Inspect.inspect_get_product_name");

  args[0] = guestfs_int_daemon_copy_mountable (root);
  retv = caml_callbackN_exn (*cb, 1, args);

  if (Is_exception_result (retv)) {
    retv = Extract_exception (retv);
    guestfs_int_daemon_exn_to_reply_with_error ("inspect_get_product_name", retv);
    CAMLreturnT (void *, NULL);
  }

  char *ret = strdup (String_val (retv));
  if (ret == NULL) {
    reply_with_perror ("strdup");
    CAMLreturnT (char *, NULL);
  }
  CAMLreturnT (char *, ret); /* caller frees */
}

/* Wrapper for OCaml function ‘Inspect.inspect_get_product_variant’. */
char *
do_inspect_get_product_variant (const mountable_t *root)
{
  static value *cb = NULL;
  CAMLparam0 ();
  CAMLlocal2 (v, retv);
  CAMLlocalN (args, 1);

  if (cb == NULL)
    cb = caml_named_value ("Inspect.inspect_get_product_variant");

  args[0] = guestfs_int_daemon_copy_mountable (root);
  retv = caml_callbackN_exn (*cb, 1, args);

  if (Is_exception_result (retv)) {
    retv = Extract_exception (retv);
    guestfs_int_daemon_exn_to_reply_with_error ("inspect_get_product_variant", retv);
    CAMLreturnT (void *, NULL);
  }

  char *ret = strdup (String_val (retv));
  if (ret == NULL) {
    reply_with_perror ("strdup");
    CAMLreturnT (char *, NULL);
  }
  CAMLreturnT (char *, ret); /* caller frees */
}

/* Wrapper for OCaml function ‘Inspect.inspect_get_roots’. */
char **
do_inspect_get_roots (void)
{
  static value *cb = NULL;
  CAMLparam0 ();
  CAMLlocal2 (v, retv);
  CAMLlocalN (args, 1);

  if (cb == NULL)
    cb = caml_named_value ("Inspect.inspect_get_roots");

  args[0] = Val_unit;
  retv = caml_callbackN_exn (*cb, 1, args);

  if (Is_exception_result (retv)) {
    retv = Extract_exception (retv);
    guestfs_int_daemon_exn_to_reply_with_error ("inspect_get_roots", retv);
    CAMLreturnT (void *, NULL);
  }

  char **ret =
    guestfs_int_daemon_return_string_mountable_list (retv);
  CAMLreturnT (char **, ret); /* caller frees */
}

/* Wrapper for OCaml function ‘Inspect.inspect_get_type’. */
char *
do_inspect_get_type (const mountable_t *root)
{
  static value *cb = NULL;
  CAMLparam0 ();
  CAMLlocal2 (v, retv);
  CAMLlocalN (args, 1);

  if (cb == NULL)
    cb = caml_named_value ("Inspect.inspect_get_type");

  args[0] = guestfs_int_daemon_copy_mountable (root);
  retv = caml_callbackN_exn (*cb, 1, args);

  if (Is_exception_result (retv)) {
    retv = Extract_exception (retv);
    guestfs_int_daemon_exn_to_reply_with_error ("inspect_get_type", retv);
    CAMLreturnT (void *, NULL);
  }

  char *ret = strdup (String_val (retv));
  if (ret == NULL) {
    reply_with_perror ("strdup");
    CAMLreturnT (char *, NULL);
  }
  CAMLreturnT (char *, ret); /* caller frees */
}

/* Wrapper for OCaml function ‘Inspect.inspect_get_windows_current_control_set’. */
char *
do_inspect_get_windows_current_control_set (const mountable_t *root)
{
  static value *cb = NULL;
  CAMLparam0 ();
  CAMLlocal2 (v, retv);
  CAMLlocalN (args, 1);

  if (cb == NULL)
    cb = caml_named_value ("Inspect.inspect_get_windows_current_control_set");

  args[0] = guestfs_int_daemon_copy_mountable (root);
  retv = caml_callbackN_exn (*cb, 1, args);

  if (Is_exception_result (retv)) {
    retv = Extract_exception (retv);
    guestfs_int_daemon_exn_to_reply_with_error ("inspect_get_windows_current_control_set", retv);
    CAMLreturnT (void *, NULL);
  }

  char *ret = strdup (String_val (retv));
  if (ret == NULL) {
    reply_with_perror ("strdup");
    CAMLreturnT (char *, NULL);
  }
  CAMLreturnT (char *, ret); /* caller frees */
}

/* Wrapper for OCaml function ‘Inspect.inspect_get_windows_software_hive’. */
char *
do_inspect_get_windows_software_hive (const mountable_t *root)
{
  static value *cb = NULL;
  CAMLparam0 ();
  CAMLlocal2 (v, retv);
  CAMLlocalN (args, 1);

  if (cb == NULL)
    cb = caml_named_value ("Inspect.inspect_get_windows_software_hive");

  args[0] = guestfs_int_daemon_copy_mountable (root);
  retv = caml_callbackN_exn (*cb, 1, args);

  if (Is_exception_result (retv)) {
    retv = Extract_exception (retv);
    guestfs_int_daemon_exn_to_reply_with_error ("inspect_get_windows_software_hive", retv);
    CAMLreturnT (void *, NULL);
  }

  char *ret = strdup (String_val (retv));
  if (ret == NULL) {
    reply_with_perror ("strdup");
    CAMLreturnT (char *, NULL);
  }
  CAMLreturnT (char *, ret); /* caller frees */
}

/* Wrapper for OCaml function ‘Inspect.inspect_get_windows_system_hive’. */
char *
do_inspect_get_windows_system_hive (const mountable_t *root)
{
  static value *cb = NULL;
  CAMLparam0 ();
  CAMLlocal2 (v, retv);
  CAMLlocalN (args, 1);

  if (cb == NULL)
    cb = caml_named_value ("Inspect.inspect_get_windows_system_hive");

  args[0] = guestfs_int_daemon_copy_mountable (root);
  retv = caml_callbackN_exn (*cb, 1, args);

  if (Is_exception_result (retv)) {
    retv = Extract_exception (retv);
    guestfs_int_daemon_exn_to_reply_with_error ("inspect_get_windows_system_hive", retv);
    CAMLreturnT (void *, NULL);
  }

  char *ret = strdup (String_val (retv));
  if (ret == NULL) {
    reply_with_perror ("strdup");
    CAMLreturnT (char *, NULL);
  }
  CAMLreturnT (char *, ret); /* caller frees */
}

/* Wrapper for OCaml function ‘Inspect.inspect_get_windows_systemroot’. */
char *
do_inspect_get_windows_systemroot (const mountable_t *root)
{
  static value *cb = NULL;
  CAMLparam0 ();
  CAMLlocal2 (v, retv);
  CAMLlocalN (args, 1);

  if (cb == NULL)
    cb = caml_named_value ("Inspect.inspect_get_windows_systemroot");

  args[0] = guestfs_int_daemon_copy_mountable (root);
  retv = caml_callbackN_exn (*cb, 1, args);

  if (Is_exception_result (retv)) {
    retv = Extract_exception (retv);
    guestfs_int_daemon_exn_to_reply_with_error ("inspect_get_windows_systemroot", retv);
    CAMLreturnT (void *, NULL);
  }

  char *ret = strdup (String_val (retv));
  if (ret == NULL) {
    reply_with_perror ("strdup");
    CAMLreturnT (char *, NULL);
  }
  CAMLreturnT (char *, ret); /* caller frees */
}

/* Wrapper for OCaml function ‘Inspect.inspect_is_live’. */
int
do_inspect_is_live (const mountable_t *root)
{
  static value *cb = NULL;
  CAMLparam0 ();
  CAMLlocal2 (v, retv);
  CAMLlocalN (args, 1);

  if (cb == NULL)
    cb = caml_named_value ("Inspect.inspect_is_live");

  args[0] = guestfs_int_daemon_copy_mountable (root);
  retv = caml_callbackN_exn (*cb, 1, args);

  if (Is_exception_result (retv)) {
    retv = Extract_exception (retv);
    guestfs_int_daemon_exn_to_reply_with_error ("inspect_is_live", retv);
    CAMLreturnT (int, -1);
  }

  CAMLreturnT (int, Bool_val (retv));
}

/* Wrapper for OCaml function ‘Inspect.inspect_is_multipart’. */
int
do_inspect_is_multipart (const mountable_t *root)
{
  static value *cb = NULL;
  CAMLparam0 ();
  CAMLlocal2 (v, retv);
  CAMLlocalN (args, 1);

  if (cb == NULL)
    cb = caml_named_value ("Inspect.inspect_is_multipart");

  args[0] = guestfs_int_daemon_copy_mountable (root);
  retv = caml_callbackN_exn (*cb, 1, args);

  if (Is_exception_result (retv)) {
    retv = Extract_exception (retv);
    guestfs_int_daemon_exn_to_reply_with_error ("inspect_is_multipart", retv);
    CAMLreturnT (int, -1);
  }

  CAMLreturnT (int, Bool_val (retv));
}

/* Wrapper for OCaml function ‘Inspect.inspect_is_netinst’. */
int
do_inspect_is_netinst (const mountable_t *root)
{
  static value *cb = NULL;
  CAMLparam0 ();
  CAMLlocal2 (v, retv);
  CAMLlocalN (args, 1);

  if (cb == NULL)
    cb = caml_named_value ("Inspect.inspect_is_netinst");

  args[0] = guestfs_int_daemon_copy_mountable (root);
  retv = caml_callbackN_exn (*cb, 1, args);

  if (Is_exception_result (retv)) {
    retv = Extract_exception (retv);
    guestfs_int_daemon_exn_to_reply_with_error ("inspect_is_netinst", retv);
    CAMLreturnT (int, -1);
  }

  CAMLreturnT (int, Bool_val (retv));
}

/* Wrapper for OCaml function ‘Inspect.inspect_os’. */
char **
do_inspect_os (void)
{
  static value *cb = NULL;
  CAMLparam0 ();
  CAMLlocal2 (v, retv);
  CAMLlocalN (args, 1);

  if (cb == NULL)
    cb = caml_named_value ("Inspect.inspect_os");

  args[0] = Val_unit;
  retv = caml_callbackN_exn (*cb, 1, args);

  if (Is_exception_result (retv)) {
    retv = Extract_exception (retv);
    guestfs_int_daemon_exn_to_reply_with_error ("inspect_os", retv);
    CAMLreturnT (void *, NULL);
  }

  char **ret =
    guestfs_int_daemon_return_string_mountable_list (retv);
  CAMLreturnT (char **, ret); /* caller frees */
}

/* Wrapper for OCaml function ‘Is.is_dir’. */
int
do_is_dir (const char *path,
           int followsymlinks)
{
  static value *cb = NULL;
  CAMLparam0 ();
  CAMLlocal2 (v, retv);
  CAMLlocalN (args, 2);

  if (cb == NULL)
    cb = caml_named_value ("Is.is_dir");

  if ((optargs_bitmask & GUESTFS_IS_DIR_FOLLOWSYMLINKS_BITMASK) == 0)
    args[0] = Val_int (0); /* None */
  else {
    v = Val_bool (followsymlinks);
    args[0] = caml_alloc (1, 0);
    Store_field (args[0], 0, v);
  }
  args[1] = caml_copy_string (path);
  retv = caml_callbackN_exn (*cb, 2, args);

  if (Is_exception_result (retv)) {
    retv = Extract_exception (retv);
    guestfs_int_daemon_exn_to_reply_with_error ("is_dir", retv);
    CAMLreturnT (int, -1);
  }

  CAMLreturnT (int, Bool_val (retv));
}

/* Wrapper for OCaml function ‘Is.is_file’. */
int
do_is_file (const char *path,
            int followsymlinks)
{
  static value *cb = NULL;
  CAMLparam0 ();
  CAMLlocal2 (v, retv);
  CAMLlocalN (args, 2);

  if (cb == NULL)
    cb = caml_named_value ("Is.is_file");

  if ((optargs_bitmask & GUESTFS_IS_FILE_FOLLOWSYMLINKS_BITMASK) == 0)
    args[0] = Val_int (0); /* None */
  else {
    v = Val_bool (followsymlinks);
    args[0] = caml_alloc (1, 0);
    Store_field (args[0], 0, v);
  }
  args[1] = caml_copy_string (path);
  retv = caml_callbackN_exn (*cb, 2, args);

  if (Is_exception_result (retv)) {
    retv = Extract_exception (retv);
    guestfs_int_daemon_exn_to_reply_with_error ("is_file", retv);
    CAMLreturnT (int, -1);
  }

  CAMLreturnT (int, Bool_val (retv));
}

/* Wrapper for OCaml function ‘Is.is_symlink’. */
int
do_is_symlink (const char *path)
{
  static value *cb = NULL;
  CAMLparam0 ();
  CAMLlocal2 (v, retv);
  CAMLlocalN (args, 1);

  if (cb == NULL)
    cb = caml_named_value ("Is.is_symlink");

  args[0] = caml_copy_string (path);
  retv = caml_callbackN_exn (*cb, 1, args);

  if (Is_exception_result (retv)) {
    retv = Extract_exception (retv);
    guestfs_int_daemon_exn_to_reply_with_error ("is_symlink", retv);
    CAMLreturnT (int, -1);
  }

  CAMLreturnT (int, Bool_val (retv));
}

/* Wrapper for OCaml function ‘Devsparts.is_whole_device’. */
int
do_is_whole_device (const char *device)
{
  static value *cb = NULL;
  CAMLparam0 ();
  CAMLlocal2 (v, retv);
  CAMLlocalN (args, 1);

  if (cb == NULL)
    cb = caml_named_value ("Devsparts.is_whole_device");

  args[0] = caml_copy_string (device);
  retv = caml_callbackN_exn (*cb, 1, args);

  if (Is_exception_result (retv)) {
    retv = Extract_exception (retv);
    guestfs_int_daemon_exn_to_reply_with_error ("is_whole_device", retv);
    CAMLreturnT (int, -1);
  }

  CAMLreturnT (int, Bool_val (retv));
}

/* Wrapper for OCaml function ‘Devsparts.list_devices’. */
char **
do_list_devices (void)
{
  static value *cb = NULL;
  CAMLparam0 ();
  CAMLlocal2 (v, retv);
  CAMLlocalN (args, 1);

  if (cb == NULL)
    cb = caml_named_value ("Devsparts.list_devices");

  args[0] = Val_unit;
  retv = caml_callbackN_exn (*cb, 1, args);

  if (Is_exception_result (retv)) {
    retv = Extract_exception (retv);
    guestfs_int_daemon_exn_to_reply_with_error ("list_devices", retv);
    CAMLreturnT (void *, NULL);
  }

  char **ret = guestfs_int_daemon_return_string_list (retv);
  CAMLreturnT (char **, ret); /* caller frees */
}

/* Wrapper for OCaml function ‘Listfs.list_filesystems’. */
char **
do_list_filesystems (void)
{
  static value *cb = NULL;
  CAMLparam0 ();
  CAMLlocal2 (v, retv);
  CAMLlocalN (args, 1);

  if (cb == NULL)
    cb = caml_named_value ("Listfs.list_filesystems");

  args[0] = Val_unit;
  retv = caml_callbackN_exn (*cb, 1, args);

  if (Is_exception_result (retv)) {
    retv = Extract_exception (retv);
    guestfs_int_daemon_exn_to_reply_with_error ("list_filesystems", retv);
    CAMLreturnT (void *, NULL);
  }

  char **ret =
    guestfs_int_daemon_return_hashtable_mountable_string (retv);
  CAMLreturnT (char **, ret); /* caller frees */
}

/* Wrapper for OCaml function ‘Ldm.list_ldm_partitions’. */
char **
do_list_ldm_partitions (void)
{
  static value *cb = NULL;
  CAMLparam0 ();
  CAMLlocal2 (v, retv);
  CAMLlocalN (args, 1);

  if (cb == NULL)
    cb = caml_named_value ("Ldm.list_ldm_partitions");

  args[0] = Val_unit;
  retv = caml_callbackN_exn (*cb, 1, args);

  if (Is_exception_result (retv)) {
    retv = Extract_exception (retv);
    guestfs_int_daemon_exn_to_reply_with_error ("list_ldm_partitions", retv);
    CAMLreturnT (void *, NULL);
  }

  char **ret = guestfs_int_daemon_return_string_list (retv);
  CAMLreturnT (char **, ret); /* caller frees */
}

/* Wrapper for OCaml function ‘Ldm.list_ldm_volumes’. */
char **
do_list_ldm_volumes (void)
{
  static value *cb = NULL;
  CAMLparam0 ();
  CAMLlocal2 (v, retv);
  CAMLlocalN (args, 1);

  if (cb == NULL)
    cb = caml_named_value ("Ldm.list_ldm_volumes");

  args[0] = Val_unit;
  retv = caml_callbackN_exn (*cb, 1, args);

  if (Is_exception_result (retv)) {
    retv = Extract_exception (retv);
    guestfs_int_daemon_exn_to_reply_with_error ("list_ldm_volumes", retv);
    CAMLreturnT (void *, NULL);
  }

  char **ret = guestfs_int_daemon_return_string_list (retv);
  CAMLreturnT (char **, ret); /* caller frees */
}

/* Wrapper for OCaml function ‘Md.list_md_devices’. */
char **
do_list_md_devices (void)
{
  static value *cb = NULL;
  CAMLparam0 ();
  CAMLlocal2 (v, retv);
  CAMLlocalN (args, 1);

  if (cb == NULL)
    cb = caml_named_value ("Md.list_md_devices");

  args[0] = Val_unit;
  retv = caml_callbackN_exn (*cb, 1, args);

  if (Is_exception_result (retv)) {
    retv = Extract_exception (retv);
    guestfs_int_daemon_exn_to_reply_with_error ("list_md_devices", retv);
    CAMLreturnT (void *, NULL);
  }

  char **ret = guestfs_int_daemon_return_string_list (retv);
  CAMLreturnT (char **, ret); /* caller frees */
}

/* Wrapper for OCaml function ‘Devsparts.list_partitions’. */
char **
do_list_partitions (void)
{
  static value *cb = NULL;
  CAMLparam0 ();
  CAMLlocal2 (v, retv);
  CAMLlocalN (args, 1);

  if (cb == NULL)
    cb = caml_named_value ("Devsparts.list_partitions");

  args[0] = Val_unit;
  retv = caml_callbackN_exn (*cb, 1, args);

  if (Is_exception_result (retv)) {
    retv = Extract_exception (retv);
    guestfs_int_daemon_exn_to_reply_with_error ("list_partitions", retv);
    CAMLreturnT (void *, NULL);
  }

  char **ret = guestfs_int_daemon_return_string_list (retv);
  CAMLreturnT (char **, ret); /* caller frees */
}

/* Wrapper for OCaml function ‘Lvm.lvs’. */
char **
do_lvs (void)
{
  static value *cb = NULL;
  CAMLparam0 ();
  CAMLlocal2 (v, retv);
  CAMLlocalN (args, 1);

  if (cb == NULL)
    cb = caml_named_value ("Lvm.lvs");

  args[0] = Val_unit;
  retv = caml_callbackN_exn (*cb, 1, args);

  if (Is_exception_result (retv)) {
    retv = Extract_exception (retv);
    guestfs_int_daemon_exn_to_reply_with_error ("lvs", retv);
    CAMLreturnT (void *, NULL);
  }

  char **ret = guestfs_int_daemon_return_string_list (retv);
  CAMLreturnT (char **, ret); /* caller frees */
}

/* Wrapper for OCaml function ‘Md.md_detail’. */
char **
do_md_detail (const char *md)
{
  static value *cb = NULL;
  CAMLparam0 ();
  CAMLlocal2 (v, retv);
  CAMLlocalN (args, 1);

  if (cb == NULL)
    cb = caml_named_value ("Md.md_detail");

  args[0] = caml_copy_string (md);
  retv = caml_callbackN_exn (*cb, 1, args);

  if (Is_exception_result (retv)) {
    retv = Extract_exception (retv);
    guestfs_int_daemon_exn_to_reply_with_error ("md_detail", retv);
    CAMLreturnT (void *, NULL);
  }

  char **ret =
    guestfs_int_daemon_return_hashtable_string_string (retv);
  CAMLreturnT (char **, ret); /* caller frees */
}

/* Wrapper for OCaml function ‘Mount.mount’. */
int
do_mount (const mountable_t *mountable,
          const char *mountpoint)
{
  static value *cb = NULL;
  CAMLparam0 ();
  CAMLlocal2 (v, retv);
  CAMLlocalN (args, 2);

  if (cb == NULL)
    cb = caml_named_value ("Mount.mount");

  args[0] = guestfs_int_daemon_copy_mountable (mountable);
  args[1] = caml_copy_string (mountpoint);
  retv = caml_callbackN_exn (*cb, 2, args);

  if (Is_exception_result (retv)) {
    retv = Extract_exception (retv);
    guestfs_int_daemon_exn_to_reply_with_error ("mount", retv);
    CAMLreturnT (int, -1);
  }

  CAMLreturnT (int, 0);
}

/* Wrapper for OCaml function ‘Mount.mount_options’. */
int
do_mount_options (const char *options,
                  const mountable_t *mountable,
                  const char *mountpoint)
{
  static value *cb = NULL;
  CAMLparam0 ();
  CAMLlocal2 (v, retv);
  CAMLlocalN (args, 3);

  if (cb == NULL)
    cb = caml_named_value ("Mount.mount_options");

  args[0] = caml_copy_string (options);
  args[1] = guestfs_int_daemon_copy_mountable (mountable);
  args[2] = caml_copy_string (mountpoint);
  retv = caml_callbackN_exn (*cb, 3, args);

  if (Is_exception_result (retv)) {
    retv = Extract_exception (retv);
    guestfs_int_daemon_exn_to_reply_with_error ("mount_options", retv);
    CAMLreturnT (int, -1);
  }

  CAMLreturnT (int, 0);
}

/* Wrapper for OCaml function ‘Mount.mount_ro’. */
int
do_mount_ro (const mountable_t *mountable,
             const char *mountpoint)
{
  static value *cb = NULL;
  CAMLparam0 ();
  CAMLlocal2 (v, retv);
  CAMLlocalN (args, 2);

  if (cb == NULL)
    cb = caml_named_value ("Mount.mount_ro");

  args[0] = guestfs_int_daemon_copy_mountable (mountable);
  args[1] = caml_copy_string (mountpoint);
  retv = caml_callbackN_exn (*cb, 2, args);

  if (Is_exception_result (retv)) {
    retv = Extract_exception (retv);
    guestfs_int_daemon_exn_to_reply_with_error ("mount_ro", retv);
    CAMLreturnT (int, -1);
  }

  CAMLreturnT (int, 0);
}

/* Wrapper for OCaml function ‘Mount.mount_vfs’. */
int
do_mount_vfs (const char *options,
              const char *vfstype,
              const mountable_t *mountable,
              const char *mountpoint)
{
  static value *cb = NULL;
  CAMLparam0 ();
  CAMLlocal2 (v, retv);
  CAMLlocalN (args, 4);

  if (cb == NULL)
    cb = caml_named_value ("Mount.mount_vfs");

  args[0] = caml_copy_string (options);
  args[1] = caml_copy_string (vfstype);
  args[2] = guestfs_int_daemon_copy_mountable (mountable);
  args[3] = caml_copy_string (mountpoint);
  retv = caml_callbackN_exn (*cb, 4, args);

  if (Is_exception_result (retv)) {
    retv = Extract_exception (retv);
    guestfs_int_daemon_exn_to_reply_with_error ("mount_vfs", retv);
    CAMLreturnT (int, -1);
  }

  CAMLreturnT (int, 0);
}

/* Wrapper for OCaml function ‘Devsparts.nr_devices’. */
int
do_nr_devices (void)
{
  static value *cb = NULL;
  CAMLparam0 ();
  CAMLlocal2 (v, retv);
  CAMLlocalN (args, 1);

  if (cb == NULL)
    cb = caml_named_value ("Devsparts.nr_devices");

  args[0] = Val_unit;
  retv = caml_callbackN_exn (*cb, 1, args);

  if (Is_exception_result (retv)) {
    retv = Extract_exception (retv);
    guestfs_int_daemon_exn_to_reply_with_error ("nr_devices", retv);
    CAMLreturnT (int, -1);
  }

  CAMLreturnT (int, Int_val (retv));
}

/* Wrapper for OCaml function ‘Parted.part_get_gpt_attributes’. */
int64_t
do_part_get_gpt_attributes (const char *device,
                            int partnum)
{
  static value *cb = NULL;
  CAMLparam0 ();
  CAMLlocal2 (v, retv);
  CAMLlocalN (args, 2);

  if (cb == NULL)
    cb = caml_named_value ("Parted.part_get_gpt_attributes");

  args[0] = caml_copy_string (device);
  args[1] = Val_int (partnum);
  retv = caml_callbackN_exn (*cb, 2, args);

  if (Is_exception_result (retv)) {
    retv = Extract_exception (retv);
    guestfs_int_daemon_exn_to_reply_with_error ("part_get_gpt_attributes", retv);
    CAMLreturnT (int, -1);
  }

  CAMLreturnT (int, Int64_val (retv));
}

/* Wrapper for OCaml function ‘Parted.part_get_gpt_guid’. */
char *
do_part_get_gpt_guid (const char *device,
                      int partnum)
{
  static value *cb = NULL;
  CAMLparam0 ();
  CAMLlocal2 (v, retv);
  CAMLlocalN (args, 2);

  if (cb == NULL)
    cb = caml_named_value ("Parted.part_get_gpt_guid");

  args[0] = caml_copy_string (device);
  args[1] = Val_int (partnum);
  retv = caml_callbackN_exn (*cb, 2, args);

  if (Is_exception_result (retv)) {
    retv = Extract_exception (retv);
    guestfs_int_daemon_exn_to_reply_with_error ("part_get_gpt_guid", retv);
    CAMLreturnT (void *, NULL);
  }

  char *ret = strdup (String_val (retv));
  if (ret == NULL) {
    reply_with_perror ("strdup");
    CAMLreturnT (char *, NULL);
  }
  CAMLreturnT (char *, ret); /* caller frees */
}

/* Wrapper for OCaml function ‘Parted.part_get_gpt_type’. */
char *
do_part_get_gpt_type (const char *device,
                      int partnum)
{
  static value *cb = NULL;
  CAMLparam0 ();
  CAMLlocal2 (v, retv);
  CAMLlocalN (args, 2);

  if (cb == NULL)
    cb = caml_named_value ("Parted.part_get_gpt_type");

  args[0] = caml_copy_string (device);
  args[1] = Val_int (partnum);
  retv = caml_callbackN_exn (*cb, 2, args);

  if (Is_exception_result (retv)) {
    retv = Extract_exception (retv);
    guestfs_int_daemon_exn_to_reply_with_error ("part_get_gpt_type", retv);
    CAMLreturnT (void *, NULL);
  }

  char *ret = strdup (String_val (retv));
  if (ret == NULL) {
    reply_with_perror ("strdup");
    CAMLreturnT (char *, NULL);
  }
  CAMLreturnT (char *, ret); /* caller frees */
}

/* Wrapper for OCaml function ‘Parted.part_get_mbr_id’. */
int
do_part_get_mbr_id (const char *device,
                    int partnum)
{
  static value *cb = NULL;
  CAMLparam0 ();
  CAMLlocal2 (v, retv);
  CAMLlocalN (args, 2);

  if (cb == NULL)
    cb = caml_named_value ("Parted.part_get_mbr_id");

  args[0] = caml_copy_string (device);
  args[1] = Val_int (partnum);
  retv = caml_callbackN_exn (*cb, 2, args);

  if (Is_exception_result (retv)) {
    retv = Extract_exception (retv);
    guestfs_int_daemon_exn_to_reply_with_error ("part_get_mbr_id", retv);
    CAMLreturnT (int, -1);
  }

  CAMLreturnT (int, Int_val (retv));
}

/* Wrapper for OCaml function ‘Parted.part_get_parttype’. */
char *
do_part_get_parttype (const char *device)
{
  static value *cb = NULL;
  CAMLparam0 ();
  CAMLlocal2 (v, retv);
  CAMLlocalN (args, 1);

  if (cb == NULL)
    cb = caml_named_value ("Parted.part_get_parttype");

  args[0] = caml_copy_string (device);
  retv = caml_callbackN_exn (*cb, 1, args);

  if (Is_exception_result (retv)) {
    retv = Extract_exception (retv);
    guestfs_int_daemon_exn_to_reply_with_error ("part_get_parttype", retv);
    CAMLreturnT (void *, NULL);
  }

  char *ret = strdup (String_val (retv));
  if (ret == NULL) {
    reply_with_perror ("strdup");
    CAMLreturnT (char *, NULL);
  }
  CAMLreturnT (char *, ret); /* caller frees */
}

/* Wrapper for OCaml function ‘Parted.part_list’. */
guestfs_int_partition_list *
do_part_list (const char *device)
{
  static value *cb = NULL;
  CAMLparam0 ();
  CAMLlocal2 (v, retv);
  CAMLlocalN (args, 1);

  if (cb == NULL)
    cb = caml_named_value ("Parted.part_list");

  args[0] = caml_copy_string (device);
  retv = caml_callbackN_exn (*cb, 1, args);

  if (Is_exception_result (retv)) {
    retv = Extract_exception (retv);
    guestfs_int_daemon_exn_to_reply_with_error ("part_list", retv);
    CAMLreturnT (void *, NULL);
  }

  guestfs_int_partition_list *ret =
    return_partition_list (retv);
  /* caller frees */
  CAMLreturnT (guestfs_int_partition_list *, ret);
}

/* Wrapper for OCaml function ‘Parted.part_set_gpt_attributes’. */
int
do_part_set_gpt_attributes (const char *device,
                            int partnum,
                            int64_t attributes)
{
  static value *cb = NULL;
  CAMLparam0 ();
  CAMLlocal2 (v, retv);
  CAMLlocalN (args, 3);

  if (cb == NULL)
    cb = caml_named_value ("Parted.part_set_gpt_attributes");

  args[0] = caml_copy_string (device);
  args[1] = Val_int (partnum);
  args[2] = caml_copy_int64 (attributes);
  retv = caml_callbackN_exn (*cb, 3, args);

  if (Is_exception_result (retv)) {
    retv = Extract_exception (retv);
    guestfs_int_daemon_exn_to_reply_with_error ("part_set_gpt_attributes", retv);
    CAMLreturnT (int, -1);
  }

  CAMLreturnT (int, 0);
}

/* Wrapper for OCaml function ‘Devsparts.part_to_dev’. */
char *
do_part_to_dev (const char *partition)
{
  static value *cb = NULL;
  CAMLparam0 ();
  CAMLlocal2 (v, retv);
  CAMLlocalN (args, 1);

  if (cb == NULL)
    cb = caml_named_value ("Devsparts.part_to_dev");

  args[0] = caml_copy_string (partition);
  retv = caml_callbackN_exn (*cb, 1, args);

  if (Is_exception_result (retv)) {
    retv = Extract_exception (retv);
    guestfs_int_daemon_exn_to_reply_with_error ("part_to_dev", retv);
    CAMLreturnT (void *, NULL);
  }

  char *ret = strdup (String_val (retv));
  if (ret == NULL) {
    reply_with_perror ("strdup");
    CAMLreturnT (char *, NULL);
  }
  CAMLreturnT (char *, ret); /* caller frees */
}

/* Wrapper for OCaml function ‘Devsparts.part_to_partnum’. */
int
do_part_to_partnum (const char *partition)
{
  static value *cb = NULL;
  CAMLparam0 ();
  CAMLlocal2 (v, retv);
  CAMLlocalN (args, 1);

  if (cb == NULL)
    cb = caml_named_value ("Devsparts.part_to_partnum");

  args[0] = caml_copy_string (partition);
  retv = caml_callbackN_exn (*cb, 1, args);

  if (Is_exception_result (retv)) {
    retv = Extract_exception (retv);
    guestfs_int_daemon_exn_to_reply_with_error ("part_to_partnum", retv);
    CAMLreturnT (int, -1);
  }

  CAMLreturnT (int, Int_val (retv));
}

/* Wrapper for OCaml function ‘Link.readlink’. */
char *
do_readlink (const char *path)
{
  static value *cb = NULL;
  CAMLparam0 ();
  CAMLlocal2 (v, retv);
  CAMLlocalN (args, 1);

  if (cb == NULL)
    cb = caml_named_value ("Link.readlink");

  args[0] = caml_copy_string (path);
  retv = caml_callbackN_exn (*cb, 1, args);

  if (Is_exception_result (retv)) {
    retv = Extract_exception (retv);
    guestfs_int_daemon_exn_to_reply_with_error ("readlink", retv);
    CAMLreturnT (void *, NULL);
  }

  char *ret = strdup (String_val (retv));
  if (ret == NULL) {
    reply_with_perror ("strdup");
    CAMLreturnT (char *, NULL);
  }
  CAMLreturnT (char *, ret); /* caller frees */
}

/* Wrapper for OCaml function ‘Realpath.realpath’. */
char *
do_realpath (const char *path)
{
  static value *cb = NULL;
  CAMLparam0 ();
  CAMLlocal2 (v, retv);
  CAMLlocalN (args, 1);

  if (cb == NULL)
    cb = caml_named_value ("Realpath.realpath");

  args[0] = caml_copy_string (path);
  retv = caml_callbackN_exn (*cb, 1, args);

  if (Is_exception_result (retv)) {
    retv = Extract_exception (retv);
    guestfs_int_daemon_exn_to_reply_with_error ("realpath", retv);
    CAMLreturnT (void *, NULL);
  }

  char *ret = strdup (String_val (retv));
  if (ret == NULL) {
    reply_with_perror ("strdup");
    CAMLreturnT (char *, NULL);
  }
  CAMLreturnT (char *, ret); /* caller frees */
}

/* Wrapper for OCaml function ‘Statvfs.statvfs’. */
guestfs_int_statvfs *
do_statvfs (const char *path)
{
  static value *cb = NULL;
  CAMLparam0 ();
  CAMLlocal2 (v, retv);
  CAMLlocalN (args, 1);

  if (cb == NULL)
    cb = caml_named_value ("Statvfs.statvfs");

  args[0] = caml_copy_string (path);
  retv = caml_callbackN_exn (*cb, 1, args);

  if (Is_exception_result (retv)) {
    retv = Extract_exception (retv);
    guestfs_int_daemon_exn_to_reply_with_error ("statvfs", retv);
    CAMLreturnT (void *, NULL);
  }

  guestfs_int_statvfs *ret =
    return_statvfs (retv);
  /* caller frees */
  CAMLreturnT (guestfs_int_statvfs *, ret);
}

/* Wrapper for OCaml function ‘Blkid.vfs_type’. */
char *
do_vfs_type (const mountable_t *mountable)
{
  static value *cb = NULL;
  CAMLparam0 ();
  CAMLlocal2 (v, retv);
  CAMLlocalN (args, 1);

  if (cb == NULL)
    cb = caml_named_value ("Blkid.vfs_type");

  args[0] = guestfs_int_daemon_copy_mountable (mountable);
  retv = caml_callbackN_exn (*cb, 1, args);

  if (Is_exception_result (retv)) {
    retv = Extract_exception (retv);
    guestfs_int_daemon_exn_to_reply_with_error ("vfs_type", retv);
    CAMLreturnT (void *, NULL);
  }

  char *ret = strdup (String_val (retv));
  if (ret == NULL) {
    reply_with_perror ("strdup");
    CAMLreturnT (char *, NULL);
  }
  CAMLreturnT (char *, ret); /* caller frees */
}

