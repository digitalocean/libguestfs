/* libguestfs generated file
 * WARNING: THIS FILE IS GENERATED FROM:
 *   generator/ *.ml
 * ANY CHANGES YOU MAKE TO THIS FILE WILL BE LOST.
 *
 * Copyright (C) 2009-2015 Red Hat Inc.
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
#include <string.h>
#include <inttypes.h>
#include <errno.h>
#include <rpc/types.h>
#include <rpc/xdr.h>

#include "daemon.h"
#include "c-ctype.h"
#include "guestfs_protocol.h"
#include "actions.h"
#include "optgroups.h"

/* Some macros to make resolving devices easier.  These used to
 * be available in daemon.h but now they are only used by stubs.
 */

/* All functions that need an argument that is a device or partition name
 * must call this macro.  It checks that the device exists and does
 * device name translation (described in the guestfs(3) manpage).
 * Note that the "path" argument may be modified.
 *
 * NB. Cannot be used for FileIn functions.
 */
#define RESOLVE_DEVICE(path,path_out,cancel_stmt,fail_stmt)             \
  do {									\
    if (STRNEQLEN ((path), "/dev/", 5)) {				\
      cancel_stmt;                                                      \
      reply_with_error ("%s: %s: expecting a device name", __func__, (path)); \
      fail_stmt;							\
    }									\
    if (is_root_device (path)) {                                        \
      cancel_stmt;                                                      \
      reply_with_error ("%s: %s: device not found", __func__, path);    \
      fail_stmt;                                                        \
    }                                                                   \
    (path_out) = device_name_translation ((path));                      \
    if ((path_out) == NULL) {                                           \
      int err = errno;                                                  \
      cancel_stmt;                                                      \
      errno = err;                                                      \
      reply_with_perror ("%s: %s", __func__, path);                     \
      fail_stmt;							\
    }                                                                   \
  } while (0)

/* All functions that take a mountable argument must call this macro.
 * It parses the mountable into a mountable_t, ensures any
 * underlying device exists, and does device name translation
 * (described in the guestfs(3) manpage).
 *
 * Note that the "string" argument may be modified.
 */
#define RESOLVE_MOUNTABLE(string,mountable,cancel_stmt,fail_stmt)       \
  do {                                                                  \
    if (STRPREFIX ((string), "btrfsvol:")) {                            \
      if (parse_btrfsvol ((string) + strlen ("btrfsvol:"), &(mountable)) == -1)\
      {                                                                 \
        cancel_stmt;                                                    \
        reply_with_error ("%s: %s: expecting a btrfs volume",           \
                          __func__, (string));                          \
        fail_stmt;                                                      \
      }                                                                 \
    }                                                                   \
    else {                                                              \
      (mountable).type = MOUNTABLE_DEVICE;                              \
      (mountable).device = NULL;                                        \
      (mountable).volume = NULL;                                        \
      RESOLVE_DEVICE ((string), (mountable).device, cancel_stmt, fail_stmt); \
    }                                                                   \
  } while (0)

/* Helper for functions which need either an absolute path in the
 * mounted filesystem, OR a /dev/ device which exists.
 *
 * NB. Cannot be used for FileIn functions.
 *
 * NB #2: Functions which mix filenames and device paths should be
 * avoided, and existing functions should be deprecated.  This is
 * because we intend in future to make device parameters a distinct
 * type from filenames.
 */
#define REQUIRE_ROOT_OR_RESOLVE_DEVICE(path,path_out,cancel_stmt,fail_stmt) \
  do {									\
    if (STREQLEN ((path), "/dev/", 5))                                  \
      RESOLVE_DEVICE ((path), (path_out), cancel_stmt, fail_stmt);      \
    else {								\
      NEED_ROOT (cancel_stmt, fail_stmt);                               \
      ABS_PATH ((path), cancel_stmt, fail_stmt);                        \
      (path_out) = strdup ((path));                                     \
      if ((path_out) == NULL) {                                         \
        cancel_stmt;                                                    \
        reply_with_perror ("strdup");                                   \
        fail_stmt;                                                      \
      }                                                                 \
    }									\
  } while (0)

/* Helper for functions which need either an absolute path in the
 * mounted filesystem, OR a valid mountable description.
 */
#define REQUIRE_ROOT_OR_RESOLVE_MOUNTABLE(string, mountable,            \
                                          cancel_stmt, fail_stmt)       \
  do {                                                                  \
    if (STRPREFIX ((string), "/dev/") || (string)[0] != '/') {\
      RESOLVE_MOUNTABLE (string, mountable, cancel_stmt, fail_stmt);    \
    }                                                                   \
    else {                                                              \
      NEED_ROOT (cancel_stmt, fail_stmt);                               \
      /* NB: It's a path, not a device. */                              \
      (mountable).type = MOUNTABLE_PATH;                                \
      (mountable).device = strdup ((string));                           \
      (mountable).volume = NULL;                                        \
      if ((mountable).device == NULL) {                                 \
        cancel_stmt;                                                    \
        reply_with_perror ("strdup");                                   \
        fail_stmt;                                                      \
      }                                                                 \
    }                                                                   \
  } while (0)                                                           \

/* Free the mountable.device & mountable.volume fields which are
 * allocated by the above macros.
 */
#ifdef HAVE_ATTRIBUTE_CLEANUP
#define CLEANUP_FREE_MOUNTABLE __attribute__((cleanup(cleanup_free_mountable)))
#else
#define CLEANUP_FREE_MOUNTABLE
#endif

static void
cleanup_free_mountable (mountable_t *mountable)
{
  if (mountable) {
    free (mountable->device);
    free (mountable->volume);
  }
}

static void
mount_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_mount_args args;
  CLEANUP_FREE_MOUNTABLE mountable_t mountable
      = { .device = NULL, .volume = NULL };
  const char *mountpoint;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_mount_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_MOUNTABLE (args.mountable, mountable, , goto done);
  mountpoint = args.mountpoint;

  r = do_mount (&mountable, mountpoint);
  if (r == -1)
    /* do_mount has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_mount_args, (char *) &args);
done_no_free:
  return;
}

static void
sync_stub (XDR *xdr_in)
{
  int r;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  r = do_sync ();
  if (r == -1)
    /* do_sync has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
done_no_free:
  return;
}

static void
touch_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_touch_args args;
  const char *path;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_touch_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  path = args.path;
  ABS_PATH (path, , goto done);

  NEED_ROOT (, goto done);
  r = do_touch (path);
  if (r == -1)
    /* do_touch has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_touch_args, (char *) &args);
done_no_free:
  return;
}

static void
ll_stub (XDR *xdr_in)
{
  char *r;
  struct guestfs_ll_args args;
  const char *directory;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_ll_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  directory = args.directory;
  ABS_PATH (directory, , goto done);

  NEED_ROOT (, goto done);
  r = do_ll (directory);
  if (r == NULL)
    /* do_ll has already called reply_with_error */
    goto done;

  struct guestfs_ll_ret ret;
  ret.listing = r;
  reply ((xdrproc_t) &xdr_guestfs_ll_ret, (char *) &ret);
  free (r);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_ll_args, (char *) &args);
done_no_free:
  return;
}

static void
list_devices_stub (XDR *xdr_in)
{
  char **r;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  r = do_list_devices ();
  if (r == NULL)
    /* do_list_devices has already called reply_with_error */
    goto done;

  struct guestfs_list_devices_ret ret;
  ret.devices.devices_len = count_strings (r);
  ret.devices.devices_val = r;
  reply ((xdrproc_t) &xdr_guestfs_list_devices_ret, (char *) &ret);
  free_strings (r);
done:
done_no_free:
  return;
}

static void
list_partitions_stub (XDR *xdr_in)
{
  char **r;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  r = do_list_partitions ();
  if (r == NULL)
    /* do_list_partitions has already called reply_with_error */
    goto done;

  struct guestfs_list_partitions_ret ret;
  ret.partitions.partitions_len = count_strings (r);
  ret.partitions.partitions_val = r;
  reply ((xdrproc_t) &xdr_guestfs_list_partitions_ret, (char *) &ret);
  free_strings (r);
done:
done_no_free:
  return;
}

static void
pvs_stub (XDR *xdr_in)
{
  char **r;

  /* The caller should have checked before calling this. */
  if (! optgroup_lvm2_available ()) {
    reply_with_unavailable_feature ("lvm2");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  r = do_pvs ();
  if (r == NULL)
    /* do_pvs has already called reply_with_error */
    goto done;

  struct guestfs_pvs_ret ret;
  ret.physvols.physvols_len = count_strings (r);
  ret.physvols.physvols_val = r;
  reply ((xdrproc_t) &xdr_guestfs_pvs_ret, (char *) &ret);
  free_strings (r);
done:
done_no_free:
  return;
}

static void
vgs_stub (XDR *xdr_in)
{
  char **r;

  /* The caller should have checked before calling this. */
  if (! optgroup_lvm2_available ()) {
    reply_with_unavailable_feature ("lvm2");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  r = do_vgs ();
  if (r == NULL)
    /* do_vgs has already called reply_with_error */
    goto done;

  struct guestfs_vgs_ret ret;
  ret.volgroups.volgroups_len = count_strings (r);
  ret.volgroups.volgroups_val = r;
  reply ((xdrproc_t) &xdr_guestfs_vgs_ret, (char *) &ret);
  free_strings (r);
done:
done_no_free:
  return;
}

static void
lvs_stub (XDR *xdr_in)
{
  char **r;

  /* The caller should have checked before calling this. */
  if (! optgroup_lvm2_available ()) {
    reply_with_unavailable_feature ("lvm2");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  r = do_lvs ();
  if (r == NULL)
    /* do_lvs has already called reply_with_error */
    goto done;

  struct guestfs_lvs_ret ret;
  ret.logvols.logvols_len = count_strings (r);
  ret.logvols.logvols_val = r;
  reply ((xdrproc_t) &xdr_guestfs_lvs_ret, (char *) &ret);
  free_strings (r);
done:
done_no_free:
  return;
}

static void
pvs_full_stub (XDR *xdr_in)
{
  guestfs_int_lvm_pv_list *r;

  /* The caller should have checked before calling this. */
  if (! optgroup_lvm2_available ()) {
    reply_with_unavailable_feature ("lvm2");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  r = do_pvs_full ();
  if (r == NULL)
    /* do_pvs_full has already called reply_with_error */
    goto done;

  struct guestfs_pvs_full_ret ret;
  ret.physvols = *r;
  free (r);
  reply ((xdrproc_t) xdr_guestfs_pvs_full_ret, (char *) &ret);
  xdr_free ((xdrproc_t) xdr_guestfs_pvs_full_ret, (char *) &ret);
done:
done_no_free:
  return;
}

static void
vgs_full_stub (XDR *xdr_in)
{
  guestfs_int_lvm_vg_list *r;

  /* The caller should have checked before calling this. */
  if (! optgroup_lvm2_available ()) {
    reply_with_unavailable_feature ("lvm2");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  r = do_vgs_full ();
  if (r == NULL)
    /* do_vgs_full has already called reply_with_error */
    goto done;

  struct guestfs_vgs_full_ret ret;
  ret.volgroups = *r;
  free (r);
  reply ((xdrproc_t) xdr_guestfs_vgs_full_ret, (char *) &ret);
  xdr_free ((xdrproc_t) xdr_guestfs_vgs_full_ret, (char *) &ret);
done:
done_no_free:
  return;
}

static void
lvs_full_stub (XDR *xdr_in)
{
  guestfs_int_lvm_lv_list *r;

  /* The caller should have checked before calling this. */
  if (! optgroup_lvm2_available ()) {
    reply_with_unavailable_feature ("lvm2");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  r = do_lvs_full ();
  if (r == NULL)
    /* do_lvs_full has already called reply_with_error */
    goto done;

  struct guestfs_lvs_full_ret ret;
  ret.logvols = *r;
  free (r);
  reply ((xdrproc_t) xdr_guestfs_lvs_full_ret, (char *) &ret);
  xdr_free ((xdrproc_t) xdr_guestfs_lvs_full_ret, (char *) &ret);
done:
done_no_free:
  return;
}

static void
aug_init_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_aug_init_args args;
  const char *root;
  int flags;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_aug_init_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  root = args.root;
  ABS_PATH (root, , goto done);
  flags = args.flags;

  NEED_ROOT (, goto done);
  r = do_aug_init (root, flags);
  if (r == -1)
    /* do_aug_init has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_aug_init_args, (char *) &args);
done_no_free:
  return;
}

static void
aug_close_stub (XDR *xdr_in)
{
  int r;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  r = do_aug_close ();
  if (r == -1)
    /* do_aug_close has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
done_no_free:
  return;
}

static void
aug_defvar_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_aug_defvar_args args;
  const char *name;
  const char *expr;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_aug_defvar_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  name = args.name;
  expr = args.expr ? *args.expr : NULL;

  r = do_aug_defvar (name, expr);
  if (r == -1)
    /* do_aug_defvar has already called reply_with_error */
    goto done;

  struct guestfs_aug_defvar_ret ret;
  ret.nrnodes = r;
  reply ((xdrproc_t) &xdr_guestfs_aug_defvar_ret, (char *) &ret);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_aug_defvar_args, (char *) &args);
done_no_free:
  return;
}

static void
aug_defnode_stub (XDR *xdr_in)
{
  guestfs_int_int_bool *r;
  struct guestfs_aug_defnode_args args;
  const char *name;
  const char *expr;
  const char *val;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_aug_defnode_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  name = args.name;
  expr = args.expr;
  val = args.val;

  r = do_aug_defnode (name, expr, val);
  if (r == NULL)
    /* do_aug_defnode has already called reply_with_error */
    goto done;

  struct guestfs_aug_defnode_ret ret;
  ret.nrnodescreated = *r;
  free (r);
  reply ((xdrproc_t) xdr_guestfs_aug_defnode_ret, (char *) &ret);
  xdr_free ((xdrproc_t) xdr_guestfs_aug_defnode_ret, (char *) &ret);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_aug_defnode_args, (char *) &args);
done_no_free:
  return;
}

static void
aug_get_stub (XDR *xdr_in)
{
  char *r;
  struct guestfs_aug_get_args args;
  const char *augpath;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_aug_get_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  augpath = args.augpath;

  r = do_aug_get (augpath);
  if (r == NULL)
    /* do_aug_get has already called reply_with_error */
    goto done;

  struct guestfs_aug_get_ret ret;
  ret.val = r;
  reply ((xdrproc_t) &xdr_guestfs_aug_get_ret, (char *) &ret);
  free (r);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_aug_get_args, (char *) &args);
done_no_free:
  return;
}

static void
aug_set_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_aug_set_args args;
  const char *augpath;
  const char *val;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_aug_set_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  augpath = args.augpath;
  val = args.val;

  r = do_aug_set (augpath, val);
  if (r == -1)
    /* do_aug_set has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_aug_set_args, (char *) &args);
done_no_free:
  return;
}

static void
aug_insert_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_aug_insert_args args;
  const char *augpath;
  const char *label;
  int before;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_aug_insert_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  augpath = args.augpath;
  label = args.label;
  before = args.before;

  r = do_aug_insert (augpath, label, before);
  if (r == -1)
    /* do_aug_insert has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_aug_insert_args, (char *) &args);
done_no_free:
  return;
}

static void
aug_rm_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_aug_rm_args args;
  const char *augpath;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_aug_rm_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  augpath = args.augpath;

  r = do_aug_rm (augpath);
  if (r == -1)
    /* do_aug_rm has already called reply_with_error */
    goto done;

  struct guestfs_aug_rm_ret ret;
  ret.nrnodes = r;
  reply ((xdrproc_t) &xdr_guestfs_aug_rm_ret, (char *) &ret);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_aug_rm_args, (char *) &args);
done_no_free:
  return;
}

static void
aug_mv_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_aug_mv_args args;
  const char *src;
  const char *dest;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_aug_mv_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  src = args.src;
  dest = args.dest;

  r = do_aug_mv (src, dest);
  if (r == -1)
    /* do_aug_mv has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_aug_mv_args, (char *) &args);
done_no_free:
  return;
}

static void
aug_match_stub (XDR *xdr_in)
{
  char **r;
  struct guestfs_aug_match_args args;
  const char *augpath;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_aug_match_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  augpath = args.augpath;

  r = do_aug_match (augpath);
  if (r == NULL)
    /* do_aug_match has already called reply_with_error */
    goto done;

  struct guestfs_aug_match_ret ret;
  ret.matches.matches_len = count_strings (r);
  ret.matches.matches_val = r;
  reply ((xdrproc_t) &xdr_guestfs_aug_match_ret, (char *) &ret);
  free_strings (r);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_aug_match_args, (char *) &args);
done_no_free:
  return;
}

static void
aug_save_stub (XDR *xdr_in)
{
  int r;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  r = do_aug_save ();
  if (r == -1)
    /* do_aug_save has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
done_no_free:
  return;
}

static void
aug_load_stub (XDR *xdr_in)
{
  int r;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  r = do_aug_load ();
  if (r == -1)
    /* do_aug_load has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
done_no_free:
  return;
}

static void
aug_ls_stub (XDR *xdr_in)
{
  char **r;
  struct guestfs_aug_ls_args args;
  const char *augpath;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_aug_ls_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  augpath = args.augpath;

  r = do_aug_ls (augpath);
  if (r == NULL)
    /* do_aug_ls has already called reply_with_error */
    goto done;

  struct guestfs_aug_ls_ret ret;
  ret.matches.matches_len = count_strings (r);
  ret.matches.matches_val = r;
  reply ((xdrproc_t) &xdr_guestfs_aug_ls_ret, (char *) &ret);
  free_strings (r);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_aug_ls_args, (char *) &args);
done_no_free:
  return;
}

static void
rm_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_rm_args args;
  const char *path;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_rm_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  path = args.path;
  ABS_PATH (path, , goto done);

  NEED_ROOT (, goto done);
  r = do_rm (path);
  if (r == -1)
    /* do_rm has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_rm_args, (char *) &args);
done_no_free:
  return;
}

static void
rmdir_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_rmdir_args args;
  const char *path;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_rmdir_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  path = args.path;
  ABS_PATH (path, , goto done);

  NEED_ROOT (, goto done);
  r = do_rmdir (path);
  if (r == -1)
    /* do_rmdir has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_rmdir_args, (char *) &args);
done_no_free:
  return;
}

static void
rm_rf_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_rm_rf_args args;
  const char *path;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_rm_rf_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  path = args.path;
  ABS_PATH (path, , goto done);

  NEED_ROOT (, goto done);
  r = do_rm_rf (path);
  if (r == -1)
    /* do_rm_rf has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_rm_rf_args, (char *) &args);
done_no_free:
  return;
}

static void
mkdir_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_mkdir_args args;
  const char *path;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_mkdir_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  path = args.path;
  ABS_PATH (path, , goto done);

  NEED_ROOT (, goto done);
  r = do_mkdir (path);
  if (r == -1)
    /* do_mkdir has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_mkdir_args, (char *) &args);
done_no_free:
  return;
}

static void
mkdir_p_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_mkdir_p_args args;
  const char *path;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_mkdir_p_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  path = args.path;
  ABS_PATH (path, , goto done);

  NEED_ROOT (, goto done);
  r = do_mkdir_p (path);
  if (r == -1)
    /* do_mkdir_p has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_mkdir_p_args, (char *) &args);
done_no_free:
  return;
}

static void
chmod_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_chmod_args args;
  int mode;
  const char *path;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_chmod_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  mode = args.mode;
  path = args.path;
  ABS_PATH (path, , goto done);

  NEED_ROOT (, goto done);
  r = do_chmod (mode, path);
  if (r == -1)
    /* do_chmod has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_chmod_args, (char *) &args);
done_no_free:
  return;
}

static void
chown_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_chown_args args;
  int owner;
  int group;
  const char *path;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_chown_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  owner = args.owner;
  group = args.group;
  path = args.path;
  ABS_PATH (path, , goto done);

  NEED_ROOT (, goto done);
  r = do_chown (owner, group, path);
  if (r == -1)
    /* do_chown has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_chown_args, (char *) &args);
done_no_free:
  return;
}

static void
exists_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_exists_args args;
  const char *path;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_exists_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  path = args.path;
  ABS_PATH (path, , goto done);

  NEED_ROOT (, goto done);
  r = do_exists (path);
  if (r == -1)
    /* do_exists has already called reply_with_error */
    goto done;

  struct guestfs_exists_ret ret;
  ret.existsflag = r;
  reply ((xdrproc_t) &xdr_guestfs_exists_ret, (char *) &ret);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_exists_args, (char *) &args);
done_no_free:
  return;
}

static void
is_file_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_is_file_args args;
  const char *path;
  int followsymlinks;

  if (optargs_bitmask & UINT64_C(0xfffffffffffffffe)) {
    reply_with_error ("unknown option in optional arguments bitmask (this can happen if a program is compiled against a newer version of libguestfs, then run against an older version of the daemon)");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_is_file_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  path = args.path;
  ABS_PATH (path, , goto done);
  followsymlinks = args.followsymlinks;

  NEED_ROOT (, goto done);
  r = do_is_file (path, followsymlinks);
  if (r == -1)
    /* do_is_file has already called reply_with_error */
    goto done;

  struct guestfs_is_file_ret ret;
  ret.fileflag = r;
  reply ((xdrproc_t) &xdr_guestfs_is_file_ret, (char *) &ret);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_is_file_args, (char *) &args);
done_no_free:
  return;
}

static void
is_dir_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_is_dir_args args;
  const char *path;
  int followsymlinks;

  if (optargs_bitmask & UINT64_C(0xfffffffffffffffe)) {
    reply_with_error ("unknown option in optional arguments bitmask (this can happen if a program is compiled against a newer version of libguestfs, then run against an older version of the daemon)");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_is_dir_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  path = args.path;
  ABS_PATH (path, , goto done);
  followsymlinks = args.followsymlinks;

  NEED_ROOT (, goto done);
  r = do_is_dir (path, followsymlinks);
  if (r == -1)
    /* do_is_dir has already called reply_with_error */
    goto done;

  struct guestfs_is_dir_ret ret;
  ret.dirflag = r;
  reply ((xdrproc_t) &xdr_guestfs_is_dir_ret, (char *) &ret);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_is_dir_args, (char *) &args);
done_no_free:
  return;
}

static void
pvcreate_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_pvcreate_args args;
  CLEANUP_FREE char *device = NULL;

  /* The caller should have checked before calling this. */
  if (! optgroup_lvm2_available ()) {
    reply_with_unavailable_feature ("lvm2");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_pvcreate_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args.device, device, , goto done);

  r = do_pvcreate (device);
  if (r == -1)
    /* do_pvcreate has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_pvcreate_args, (char *) &args);
done_no_free:
  return;
}

static void
vgcreate_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_vgcreate_args args;
  const char *volgroup;
  CLEANUP_FREE_STRING_LIST char **physvols = NULL;

  /* The caller should have checked before calling this. */
  if (! optgroup_lvm2_available ()) {
    reply_with_unavailable_feature ("lvm2");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_vgcreate_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  volgroup = args.volgroup;
  /* Copy the string list and apply device name translation
   * to each one.
   */
  physvols = calloc (args.physvols.physvols_len+1, sizeof (char *));
  {
    size_t i;
    for (i = 0; i < args.physvols.physvols_len; ++i)
      RESOLVE_DEVICE (args.physvols.physvols_val[i], physvols[i],
                      , goto done);
    physvols[i] = NULL;
  }

  r = do_vgcreate (volgroup, physvols);
  if (r == -1)
    /* do_vgcreate has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_vgcreate_args, (char *) &args);
done_no_free:
  return;
}

static void
lvcreate_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_lvcreate_args args;
  const char *logvol;
  const char *volgroup;
  int mbytes;

  /* The caller should have checked before calling this. */
  if (! optgroup_lvm2_available ()) {
    reply_with_unavailable_feature ("lvm2");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_lvcreate_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  logvol = args.logvol;
  volgroup = args.volgroup;
  mbytes = args.mbytes;

  r = do_lvcreate (logvol, volgroup, mbytes);
  if (r == -1)
    /* do_lvcreate has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_lvcreate_args, (char *) &args);
done_no_free:
  return;
}

static void
sfdisk_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_sfdisk_args args;
  CLEANUP_FREE char *device = NULL;
  int cyls;
  int heads;
  int sectors;
  char **lines;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_sfdisk_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args.device, device, , goto done);
  cyls = args.cyls;
  heads = args.heads;
  sectors = args.sectors;
  /* Ugly, but safe and avoids copying the strings. */
  lines = realloc (args.lines.lines_val,
                sizeof (char *) * (args.lines.lines_len+1));
  if (lines == NULL) {
    reply_with_perror ("realloc");
    goto done;
  }
  lines[args.lines.lines_len] = NULL;
  args.lines.lines_val = lines;

  r = do_sfdisk (device, cyls, heads, sectors, lines);
  if (r == -1)
    /* do_sfdisk has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_sfdisk_args, (char *) &args);
done_no_free:
  return;
}

static void
write_file_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_write_file_args args;
  const char *path;
  const char *content;
  int size;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_write_file_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  path = args.path;
  ABS_PATH (path, , goto done);
  content = args.content;
  size = args.size;

  NEED_ROOT (, goto done);
  r = do_write_file (path, content, size);
  if (r == -1)
    /* do_write_file has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_write_file_args, (char *) &args);
done_no_free:
  return;
}

static void
umount_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_umount_args args;
  CLEANUP_FREE char *pathordevice = NULL;
  int force;
  int lazyunmount;

  if (optargs_bitmask & UINT64_C(0xfffffffffffffffc)) {
    reply_with_error ("unknown option in optional arguments bitmask (this can happen if a program is compiled against a newer version of libguestfs, then run against an older version of the daemon)");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_umount_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  REQUIRE_ROOT_OR_RESOLVE_DEVICE (args.pathordevice, pathordevice, , goto done);
  force = args.force;
  lazyunmount = args.lazyunmount;

  r = do_umount (pathordevice, force, lazyunmount);
  if (r == -1)
    /* do_umount has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_umount_args, (char *) &args);
done_no_free:
  return;
}

static void
mounts_stub (XDR *xdr_in)
{
  char **r;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  r = do_mounts ();
  if (r == NULL)
    /* do_mounts has already called reply_with_error */
    goto done;

  struct guestfs_mounts_ret ret;
  ret.devices.devices_len = count_strings (r);
  ret.devices.devices_val = r;
  reply ((xdrproc_t) &xdr_guestfs_mounts_ret, (char *) &ret);
  free_strings (r);
done:
done_no_free:
  return;
}

static void
umount_all_stub (XDR *xdr_in)
{
  int r;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  r = do_umount_all ();
  if (r == -1)
    /* do_umount_all has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
done_no_free:
  return;
}

static void
lvm_remove_all_stub (XDR *xdr_in)
{
  int r;

  /* The caller should have checked before calling this. */
  if (! optgroup_lvm2_available ()) {
    reply_with_unavailable_feature ("lvm2");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  r = do_lvm_remove_all ();
  if (r == -1)
    /* do_lvm_remove_all has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
done_no_free:
  return;
}

static void
file_stub (XDR *xdr_in)
{
  char *r;
  struct guestfs_file_args args;
  CLEANUP_FREE char *path = NULL;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_file_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  REQUIRE_ROOT_OR_RESOLVE_DEVICE (args.path, path, , goto done);

  r = do_file (path);
  if (r == NULL)
    /* do_file has already called reply_with_error */
    goto done;

  struct guestfs_file_ret ret;
  ret.description = r;
  reply ((xdrproc_t) &xdr_guestfs_file_ret, (char *) &ret);
  free (r);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_file_args, (char *) &args);
done_no_free:
  return;
}

static void
command_stub (XDR *xdr_in)
{
  char *r;
  struct guestfs_command_args args;
  char **arguments;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_command_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  /* Ugly, but safe and avoids copying the strings. */
  arguments = realloc (args.arguments.arguments_val,
                sizeof (char *) * (args.arguments.arguments_len+1));
  if (arguments == NULL) {
    reply_with_perror ("realloc");
    goto done;
  }
  arguments[args.arguments.arguments_len] = NULL;
  args.arguments.arguments_val = arguments;

  r = do_command (arguments);
  if (r == NULL)
    /* do_command has already called reply_with_error */
    goto done;

  struct guestfs_command_ret ret;
  ret.output = r;
  reply ((xdrproc_t) &xdr_guestfs_command_ret, (char *) &ret);
  free (r);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_command_args, (char *) &args);
done_no_free:
  return;
}

static void
command_lines_stub (XDR *xdr_in)
{
  char **r;
  struct guestfs_command_lines_args args;
  char **arguments;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_command_lines_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  /* Ugly, but safe and avoids copying the strings. */
  arguments = realloc (args.arguments.arguments_val,
                sizeof (char *) * (args.arguments.arguments_len+1));
  if (arguments == NULL) {
    reply_with_perror ("realloc");
    goto done;
  }
  arguments[args.arguments.arguments_len] = NULL;
  args.arguments.arguments_val = arguments;

  r = do_command_lines (arguments);
  if (r == NULL)
    /* do_command_lines has already called reply_with_error */
    goto done;

  struct guestfs_command_lines_ret ret;
  ret.lines.lines_len = count_strings (r);
  ret.lines.lines_val = r;
  reply ((xdrproc_t) &xdr_guestfs_command_lines_ret, (char *) &ret);
  free_strings (r);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_command_lines_args, (char *) &args);
done_no_free:
  return;
}

static void
statvfs_stub (XDR *xdr_in)
{
  guestfs_int_statvfs *r;
  struct guestfs_statvfs_args args;
  const char *path;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_statvfs_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  path = args.path;
  ABS_PATH (path, , goto done);

  NEED_ROOT (, goto done);
  r = do_statvfs (path);
  if (r == NULL)
    /* do_statvfs has already called reply_with_error */
    goto done;

  struct guestfs_statvfs_ret ret;
  ret.statbuf = *r;
  free (r);
  reply ((xdrproc_t) xdr_guestfs_statvfs_ret, (char *) &ret);
  xdr_free ((xdrproc_t) xdr_guestfs_statvfs_ret, (char *) &ret);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_statvfs_args, (char *) &args);
done_no_free:
  return;
}

static void
tune2fs_l_stub (XDR *xdr_in)
{
  char **r;
  struct guestfs_tune2fs_l_args args;
  CLEANUP_FREE char *device = NULL;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_tune2fs_l_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args.device, device, , goto done);

  r = do_tune2fs_l (device);
  if (r == NULL)
    /* do_tune2fs_l has already called reply_with_error */
    goto done;

  struct guestfs_tune2fs_l_ret ret;
  ret.superblock.superblock_len = count_strings (r);
  ret.superblock.superblock_val = r;
  reply ((xdrproc_t) &xdr_guestfs_tune2fs_l_ret, (char *) &ret);
  free_strings (r);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_tune2fs_l_args, (char *) &args);
done_no_free:
  return;
}

static void
blockdev_setro_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_blockdev_setro_args args;
  CLEANUP_FREE char *device = NULL;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_blockdev_setro_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args.device, device, , goto done);

  r = do_blockdev_setro (device);
  if (r == -1)
    /* do_blockdev_setro has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_blockdev_setro_args, (char *) &args);
done_no_free:
  return;
}

static void
blockdev_setrw_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_blockdev_setrw_args args;
  CLEANUP_FREE char *device = NULL;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_blockdev_setrw_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args.device, device, , goto done);

  r = do_blockdev_setrw (device);
  if (r == -1)
    /* do_blockdev_setrw has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_blockdev_setrw_args, (char *) &args);
done_no_free:
  return;
}

static void
blockdev_getro_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_blockdev_getro_args args;
  CLEANUP_FREE char *device = NULL;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_blockdev_getro_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args.device, device, , goto done);

  r = do_blockdev_getro (device);
  if (r == -1)
    /* do_blockdev_getro has already called reply_with_error */
    goto done;

  struct guestfs_blockdev_getro_ret ret;
  ret.ro = r;
  reply ((xdrproc_t) &xdr_guestfs_blockdev_getro_ret, (char *) &ret);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_blockdev_getro_args, (char *) &args);
done_no_free:
  return;
}

static void
blockdev_getss_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_blockdev_getss_args args;
  CLEANUP_FREE char *device = NULL;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_blockdev_getss_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args.device, device, , goto done);

  r = do_blockdev_getss (device);
  if (r == -1)
    /* do_blockdev_getss has already called reply_with_error */
    goto done;

  struct guestfs_blockdev_getss_ret ret;
  ret.sectorsize = r;
  reply ((xdrproc_t) &xdr_guestfs_blockdev_getss_ret, (char *) &ret);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_blockdev_getss_args, (char *) &args);
done_no_free:
  return;
}

static void
blockdev_getbsz_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_blockdev_getbsz_args args;
  CLEANUP_FREE char *device = NULL;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_blockdev_getbsz_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args.device, device, , goto done);

  r = do_blockdev_getbsz (device);
  if (r == -1)
    /* do_blockdev_getbsz has already called reply_with_error */
    goto done;

  struct guestfs_blockdev_getbsz_ret ret;
  ret.blocksize = r;
  reply ((xdrproc_t) &xdr_guestfs_blockdev_getbsz_ret, (char *) &ret);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_blockdev_getbsz_args, (char *) &args);
done_no_free:
  return;
}

static void
blockdev_setbsz_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_blockdev_setbsz_args args;
  CLEANUP_FREE char *device = NULL;
  int blocksize;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_blockdev_setbsz_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args.device, device, , goto done);
  blocksize = args.blocksize;

  r = do_blockdev_setbsz (device, blocksize);
  if (r == -1)
    /* do_blockdev_setbsz has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_blockdev_setbsz_args, (char *) &args);
done_no_free:
  return;
}

static void
blockdev_getsz_stub (XDR *xdr_in)
{
  int64_t r;
  struct guestfs_blockdev_getsz_args args;
  CLEANUP_FREE char *device = NULL;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_blockdev_getsz_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args.device, device, , goto done);

  r = do_blockdev_getsz (device);
  if (r == -1)
    /* do_blockdev_getsz has already called reply_with_error */
    goto done;

  struct guestfs_blockdev_getsz_ret ret;
  ret.sizeinsectors = r;
  reply ((xdrproc_t) &xdr_guestfs_blockdev_getsz_ret, (char *) &ret);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_blockdev_getsz_args, (char *) &args);
done_no_free:
  return;
}

static void
blockdev_getsize64_stub (XDR *xdr_in)
{
  int64_t r;
  struct guestfs_blockdev_getsize64_args args;
  CLEANUP_FREE char *device = NULL;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_blockdev_getsize64_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args.device, device, , goto done);

  r = do_blockdev_getsize64 (device);
  if (r == -1)
    /* do_blockdev_getsize64 has already called reply_with_error */
    goto done;

  struct guestfs_blockdev_getsize64_ret ret;
  ret.sizeinbytes = r;
  reply ((xdrproc_t) &xdr_guestfs_blockdev_getsize64_ret, (char *) &ret);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_blockdev_getsize64_args, (char *) &args);
done_no_free:
  return;
}

static void
blockdev_flushbufs_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_blockdev_flushbufs_args args;
  CLEANUP_FREE char *device = NULL;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_blockdev_flushbufs_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args.device, device, , goto done);

  r = do_blockdev_flushbufs (device);
  if (r == -1)
    /* do_blockdev_flushbufs has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_blockdev_flushbufs_args, (char *) &args);
done_no_free:
  return;
}

static void
blockdev_rereadpt_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_blockdev_rereadpt_args args;
  CLEANUP_FREE char *device = NULL;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_blockdev_rereadpt_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args.device, device, , goto done);

  r = do_blockdev_rereadpt (device);
  if (r == -1)
    /* do_blockdev_rereadpt has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_blockdev_rereadpt_args, (char *) &args);
done_no_free:
  return;
}

static void
upload_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_upload_args args;
  CLEANUP_FREE char *remotefilename = NULL;

  if (optargs_bitmask != 0) {
    cancel_receive ();
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_upload_args (xdr_in, &args)) {
    cancel_receive ();
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  REQUIRE_ROOT_OR_RESOLVE_DEVICE (args.remotefilename, remotefilename, cancel_receive (), goto done);

  r = do_upload (remotefilename);
  if (r == -1)
    /* do_upload has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_upload_args, (char *) &args);
done_no_free:
  return;
}

static void
download_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_download_args args;
  CLEANUP_FREE char *remotefilename = NULL;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_download_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  REQUIRE_ROOT_OR_RESOLVE_DEVICE (args.remotefilename, remotefilename, , goto done);

  r = do_download (remotefilename);
  if (r == -1)
    /* do_download has already called reply_with_error */
    goto done;

  /* do_download has already sent a reply */
done:
  xdr_free ((xdrproc_t) xdr_guestfs_download_args, (char *) &args);
done_no_free:
  return;
}

static void
checksum_stub (XDR *xdr_in)
{
  char *r;
  struct guestfs_checksum_args args;
  const char *csumtype;
  const char *path;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_checksum_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  csumtype = args.csumtype;
  path = args.path;
  ABS_PATH (path, , goto done);

  NEED_ROOT (, goto done);
  r = do_checksum (csumtype, path);
  if (r == NULL)
    /* do_checksum has already called reply_with_error */
    goto done;

  struct guestfs_checksum_ret ret;
  ret.checksum = r;
  reply ((xdrproc_t) &xdr_guestfs_checksum_ret, (char *) &ret);
  free (r);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_checksum_args, (char *) &args);
done_no_free:
  return;
}

static void
tar_in_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_tar_in_args args;
  const char *directory;
  const char *compress;

  if (optargs_bitmask & UINT64_C(0xfffffffffffffffe)) {
    cancel_receive ();
    reply_with_error ("unknown option in optional arguments bitmask (this can happen if a program is compiled against a newer version of libguestfs, then run against an older version of the daemon)");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_tar_in_args (xdr_in, &args)) {
    cancel_receive ();
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  directory = args.directory;
  ABS_PATH (directory, cancel_receive (), goto done);
  compress = args.compress;

  NEED_ROOT (cancel_receive (), goto done);
  r = do_tar_in (directory, compress);
  if (r == -1)
    /* do_tar_in has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_tar_in_args, (char *) &args);
done_no_free:
  return;
}

static void
tar_out_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_tar_out_args args;
  const char *directory;
  const char *compress;
  int numericowner;
  char **excludes;

  if (optargs_bitmask & UINT64_C(0xfffffffffffffff8)) {
    reply_with_error ("unknown option in optional arguments bitmask (this can happen if a program is compiled against a newer version of libguestfs, then run against an older version of the daemon)");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_tar_out_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  directory = args.directory;
  compress = args.compress;
  numericowner = args.numericowner;
  /* Ugly, but safe and avoids copying the strings. */
  excludes = realloc (args.excludes.excludes_val,
                sizeof (char *) * (args.excludes.excludes_len+1));
  if (excludes == NULL) {
    reply_with_perror ("realloc");
    goto done;
  }
  excludes[args.excludes.excludes_len] = NULL;
  args.excludes.excludes_val = excludes;

  r = do_tar_out (directory, compress, numericowner, excludes);
  if (r == -1)
    /* do_tar_out has already called reply_with_error */
    goto done;

  /* do_tar_out has already sent a reply */
done:
  xdr_free ((xdrproc_t) xdr_guestfs_tar_out_args, (char *) &args);
done_no_free:
  return;
}

static void
tgz_in_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_tgz_in_args args;
  const char *directory;

  if (optargs_bitmask != 0) {
    cancel_receive ();
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_tgz_in_args (xdr_in, &args)) {
    cancel_receive ();
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  directory = args.directory;
  ABS_PATH (directory, cancel_receive (), goto done);

  NEED_ROOT (cancel_receive (), goto done);
  r = do_tgz_in (directory);
  if (r == -1)
    /* do_tgz_in has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_tgz_in_args, (char *) &args);
done_no_free:
  return;
}

static void
tgz_out_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_tgz_out_args args;
  const char *directory;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_tgz_out_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  directory = args.directory;
  ABS_PATH (directory, , goto done);

  NEED_ROOT (, goto done);
  r = do_tgz_out (directory);
  if (r == -1)
    /* do_tgz_out has already called reply_with_error */
    goto done;

  /* do_tgz_out has already sent a reply */
done:
  xdr_free ((xdrproc_t) xdr_guestfs_tgz_out_args, (char *) &args);
done_no_free:
  return;
}

static void
mount_ro_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_mount_ro_args args;
  CLEANUP_FREE_MOUNTABLE mountable_t mountable
      = { .device = NULL, .volume = NULL };
  const char *mountpoint;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_mount_ro_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_MOUNTABLE (args.mountable, mountable, , goto done);
  mountpoint = args.mountpoint;

  r = do_mount_ro (&mountable, mountpoint);
  if (r == -1)
    /* do_mount_ro has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_mount_ro_args, (char *) &args);
done_no_free:
  return;
}

static void
mount_options_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_mount_options_args args;
  const char *options;
  CLEANUP_FREE_MOUNTABLE mountable_t mountable
      = { .device = NULL, .volume = NULL };
  const char *mountpoint;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_mount_options_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  options = args.options;
  RESOLVE_MOUNTABLE (args.mountable, mountable, , goto done);
  mountpoint = args.mountpoint;

  r = do_mount_options (options, &mountable, mountpoint);
  if (r == -1)
    /* do_mount_options has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_mount_options_args, (char *) &args);
done_no_free:
  return;
}

static void
mount_vfs_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_mount_vfs_args args;
  const char *options;
  const char *vfstype;
  CLEANUP_FREE_MOUNTABLE mountable_t mountable
      = { .device = NULL, .volume = NULL };
  const char *mountpoint;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_mount_vfs_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  options = args.options;
  vfstype = args.vfstype;
  RESOLVE_MOUNTABLE (args.mountable, mountable, , goto done);
  mountpoint = args.mountpoint;

  r = do_mount_vfs (options, vfstype, &mountable, mountpoint);
  if (r == -1)
    /* do_mount_vfs has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_mount_vfs_args, (char *) &args);
done_no_free:
  return;
}

static void
debug_stub (XDR *xdr_in)
{
  char *r;
  struct guestfs_debug_args args;
  const char *subcmd;
  char **extraargs;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_debug_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  subcmd = args.subcmd;
  /* Ugly, but safe and avoids copying the strings. */
  extraargs = realloc (args.extraargs.extraargs_val,
                sizeof (char *) * (args.extraargs.extraargs_len+1));
  if (extraargs == NULL) {
    reply_with_perror ("realloc");
    goto done;
  }
  extraargs[args.extraargs.extraargs_len] = NULL;
  args.extraargs.extraargs_val = extraargs;

  r = do_debug (subcmd, extraargs);
  if (r == NULL)
    /* do_debug has already called reply_with_error */
    goto done;

  struct guestfs_debug_ret ret;
  ret.result = r;
  reply ((xdrproc_t) &xdr_guestfs_debug_ret, (char *) &ret);
  free (r);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_debug_args, (char *) &args);
done_no_free:
  return;
}

static void
lvremove_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_lvremove_args args;
  CLEANUP_FREE char *device = NULL;

  /* The caller should have checked before calling this. */
  if (! optgroup_lvm2_available ()) {
    reply_with_unavailable_feature ("lvm2");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_lvremove_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args.device, device, , goto done);

  r = do_lvremove (device);
  if (r == -1)
    /* do_lvremove has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_lvremove_args, (char *) &args);
done_no_free:
  return;
}

static void
vgremove_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_vgremove_args args;
  const char *vgname;

  /* The caller should have checked before calling this. */
  if (! optgroup_lvm2_available ()) {
    reply_with_unavailable_feature ("lvm2");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_vgremove_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  vgname = args.vgname;

  r = do_vgremove (vgname);
  if (r == -1)
    /* do_vgremove has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_vgremove_args, (char *) &args);
done_no_free:
  return;
}

static void
pvremove_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_pvremove_args args;
  CLEANUP_FREE char *device = NULL;

  /* The caller should have checked before calling this. */
  if (! optgroup_lvm2_available ()) {
    reply_with_unavailable_feature ("lvm2");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_pvremove_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args.device, device, , goto done);

  r = do_pvremove (device);
  if (r == -1)
    /* do_pvremove has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_pvremove_args, (char *) &args);
done_no_free:
  return;
}

static void
set_e2label_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_set_e2label_args args;
  CLEANUP_FREE char *device = NULL;
  const char *label;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_set_e2label_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args.device, device, , goto done);
  label = args.label;

  r = do_set_e2label (device, label);
  if (r == -1)
    /* do_set_e2label has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_set_e2label_args, (char *) &args);
done_no_free:
  return;
}

static void
get_e2label_stub (XDR *xdr_in)
{
  char *r;
  struct guestfs_get_e2label_args args;
  CLEANUP_FREE char *device = NULL;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_get_e2label_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args.device, device, , goto done);

  r = do_get_e2label (device);
  if (r == NULL)
    /* do_get_e2label has already called reply_with_error */
    goto done;

  struct guestfs_get_e2label_ret ret;
  ret.label = r;
  reply ((xdrproc_t) &xdr_guestfs_get_e2label_ret, (char *) &ret);
  free (r);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_get_e2label_args, (char *) &args);
done_no_free:
  return;
}

static void
set_e2uuid_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_set_e2uuid_args args;
  CLEANUP_FREE char *device = NULL;
  const char *uuid;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_set_e2uuid_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args.device, device, , goto done);
  uuid = args.uuid;

  r = do_set_e2uuid (device, uuid);
  if (r == -1)
    /* do_set_e2uuid has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_set_e2uuid_args, (char *) &args);
done_no_free:
  return;
}

static void
get_e2uuid_stub (XDR *xdr_in)
{
  char *r;
  struct guestfs_get_e2uuid_args args;
  CLEANUP_FREE char *device = NULL;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_get_e2uuid_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args.device, device, , goto done);

  r = do_get_e2uuid (device);
  if (r == NULL)
    /* do_get_e2uuid has already called reply_with_error */
    goto done;

  struct guestfs_get_e2uuid_ret ret;
  ret.uuid = r;
  reply ((xdrproc_t) &xdr_guestfs_get_e2uuid_ret, (char *) &ret);
  free (r);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_get_e2uuid_args, (char *) &args);
done_no_free:
  return;
}

static void
fsck_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_fsck_args args;
  const char *fstype;
  CLEANUP_FREE char *device = NULL;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_fsck_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  fstype = args.fstype;
  RESOLVE_DEVICE (args.device, device, , goto done);

  r = do_fsck (fstype, device);
  if (r == -1)
    /* do_fsck has already called reply_with_error */
    goto done;

  struct guestfs_fsck_ret ret;
  ret.status = r;
  reply ((xdrproc_t) &xdr_guestfs_fsck_ret, (char *) &ret);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_fsck_args, (char *) &args);
done_no_free:
  return;
}

static void
zero_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_zero_args args;
  CLEANUP_FREE char *device = NULL;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_zero_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args.device, device, , goto done);

  r = do_zero (device);
  if (r == -1)
    /* do_zero has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_zero_args, (char *) &args);
done_no_free:
  return;
}

static void
grub_install_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_grub_install_args args;
  const char *root;
  CLEANUP_FREE char *device = NULL;

  /* The caller should have checked before calling this. */
  if (! optgroup_grub_available ()) {
    reply_with_unavailable_feature ("grub");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_grub_install_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  root = args.root;
  ABS_PATH (root, , goto done);
  RESOLVE_DEVICE (args.device, device, , goto done);

  NEED_ROOT (, goto done);
  r = do_grub_install (root, device);
  if (r == -1)
    /* do_grub_install has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_grub_install_args, (char *) &args);
done_no_free:
  return;
}

static void
cp_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_cp_args args;
  const char *src;
  const char *dest;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_cp_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  src = args.src;
  ABS_PATH (src, , goto done);
  dest = args.dest;
  ABS_PATH (dest, , goto done);

  NEED_ROOT (, goto done);
  r = do_cp (src, dest);
  if (r == -1)
    /* do_cp has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_cp_args, (char *) &args);
done_no_free:
  return;
}

static void
cp_a_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_cp_a_args args;
  const char *src;
  const char *dest;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_cp_a_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  src = args.src;
  ABS_PATH (src, , goto done);
  dest = args.dest;
  ABS_PATH (dest, , goto done);

  NEED_ROOT (, goto done);
  r = do_cp_a (src, dest);
  if (r == -1)
    /* do_cp_a has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_cp_a_args, (char *) &args);
done_no_free:
  return;
}

static void
mv_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_mv_args args;
  const char *src;
  const char *dest;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_mv_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  src = args.src;
  ABS_PATH (src, , goto done);
  dest = args.dest;
  ABS_PATH (dest, , goto done);

  NEED_ROOT (, goto done);
  r = do_mv (src, dest);
  if (r == -1)
    /* do_mv has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_mv_args, (char *) &args);
done_no_free:
  return;
}

static void
drop_caches_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_drop_caches_args args;
  int whattodrop;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_drop_caches_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  whattodrop = args.whattodrop;

  r = do_drop_caches (whattodrop);
  if (r == -1)
    /* do_drop_caches has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_drop_caches_args, (char *) &args);
done_no_free:
  return;
}

static void
dmesg_stub (XDR *xdr_in)
{
  char *r;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  r = do_dmesg ();
  if (r == NULL)
    /* do_dmesg has already called reply_with_error */
    goto done;

  struct guestfs_dmesg_ret ret;
  ret.kmsgs = r;
  reply ((xdrproc_t) &xdr_guestfs_dmesg_ret, (char *) &ret);
  free (r);
done:
done_no_free:
  return;
}

static void
ping_daemon_stub (XDR *xdr_in)
{
  int r;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  r = do_ping_daemon ();
  if (r == -1)
    /* do_ping_daemon has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
done_no_free:
  return;
}

static void
equal_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_equal_args args;
  const char *file1;
  const char *file2;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_equal_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  file1 = args.file1;
  ABS_PATH (file1, , goto done);
  file2 = args.file2;
  ABS_PATH (file2, , goto done);

  NEED_ROOT (, goto done);
  r = do_equal (file1, file2);
  if (r == -1)
    /* do_equal has already called reply_with_error */
    goto done;

  struct guestfs_equal_ret ret;
  ret.equality = r;
  reply ((xdrproc_t) &xdr_guestfs_equal_ret, (char *) &ret);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_equal_args, (char *) &args);
done_no_free:
  return;
}

static void
strings_stub (XDR *xdr_in)
{
  char **r;
  struct guestfs_strings_args args;
  const char *path;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_strings_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  path = args.path;
  ABS_PATH (path, , goto done);

  NEED_ROOT (, goto done);
  r = do_strings (path);
  if (r == NULL)
    /* do_strings has already called reply_with_error */
    goto done;

  struct guestfs_strings_ret ret;
  ret.stringsout.stringsout_len = count_strings (r);
  ret.stringsout.stringsout_val = r;
  reply ((xdrproc_t) &xdr_guestfs_strings_ret, (char *) &ret);
  free_strings (r);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_strings_args, (char *) &args);
done_no_free:
  return;
}

static void
strings_e_stub (XDR *xdr_in)
{
  char **r;
  struct guestfs_strings_e_args args;
  const char *encoding;
  const char *path;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_strings_e_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  encoding = args.encoding;
  path = args.path;
  ABS_PATH (path, , goto done);

  NEED_ROOT (, goto done);
  r = do_strings_e (encoding, path);
  if (r == NULL)
    /* do_strings_e has already called reply_with_error */
    goto done;

  struct guestfs_strings_e_ret ret;
  ret.stringsout.stringsout_len = count_strings (r);
  ret.stringsout.stringsout_val = r;
  reply ((xdrproc_t) &xdr_guestfs_strings_e_ret, (char *) &ret);
  free_strings (r);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_strings_e_args, (char *) &args);
done_no_free:
  return;
}

static void
hexdump_stub (XDR *xdr_in)
{
  char *r;
  struct guestfs_hexdump_args args;
  const char *path;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_hexdump_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  path = args.path;
  ABS_PATH (path, , goto done);

  NEED_ROOT (, goto done);
  r = do_hexdump (path);
  if (r == NULL)
    /* do_hexdump has already called reply_with_error */
    goto done;

  struct guestfs_hexdump_ret ret;
  ret.dump = r;
  reply ((xdrproc_t) &xdr_guestfs_hexdump_ret, (char *) &ret);
  free (r);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_hexdump_args, (char *) &args);
done_no_free:
  return;
}

static void
zerofree_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_zerofree_args args;
  CLEANUP_FREE char *device = NULL;

  /* The caller should have checked before calling this. */
  if (! optgroup_zerofree_available ()) {
    reply_with_unavailable_feature ("zerofree");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_zerofree_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args.device, device, , goto done);

  r = do_zerofree (device);
  if (r == -1)
    /* do_zerofree has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_zerofree_args, (char *) &args);
done_no_free:
  return;
}

static void
pvresize_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_pvresize_args args;
  CLEANUP_FREE char *device = NULL;

  /* The caller should have checked before calling this. */
  if (! optgroup_lvm2_available ()) {
    reply_with_unavailable_feature ("lvm2");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_pvresize_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args.device, device, , goto done);

  r = do_pvresize (device);
  if (r == -1)
    /* do_pvresize has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_pvresize_args, (char *) &args);
done_no_free:
  return;
}

static void
sfdisk_N_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_sfdisk_N_args args;
  CLEANUP_FREE char *device = NULL;
  int partnum;
  int cyls;
  int heads;
  int sectors;
  const char *line;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_sfdisk_N_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args.device, device, , goto done);
  partnum = args.partnum;
  cyls = args.cyls;
  heads = args.heads;
  sectors = args.sectors;
  line = args.line;

  r = do_sfdisk_N (device, partnum, cyls, heads, sectors, line);
  if (r == -1)
    /* do_sfdisk_N has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_sfdisk_N_args, (char *) &args);
done_no_free:
  return;
}

static void
sfdisk_l_stub (XDR *xdr_in)
{
  char *r;
  struct guestfs_sfdisk_l_args args;
  CLEANUP_FREE char *device = NULL;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_sfdisk_l_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args.device, device, , goto done);

  r = do_sfdisk_l (device);
  if (r == NULL)
    /* do_sfdisk_l has already called reply_with_error */
    goto done;

  struct guestfs_sfdisk_l_ret ret;
  ret.partitions = r;
  reply ((xdrproc_t) &xdr_guestfs_sfdisk_l_ret, (char *) &ret);
  free (r);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_sfdisk_l_args, (char *) &args);
done_no_free:
  return;
}

static void
sfdisk_kernel_geometry_stub (XDR *xdr_in)
{
  char *r;
  struct guestfs_sfdisk_kernel_geometry_args args;
  CLEANUP_FREE char *device = NULL;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_sfdisk_kernel_geometry_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args.device, device, , goto done);

  r = do_sfdisk_kernel_geometry (device);
  if (r == NULL)
    /* do_sfdisk_kernel_geometry has already called reply_with_error */
    goto done;

  struct guestfs_sfdisk_kernel_geometry_ret ret;
  ret.partitions = r;
  reply ((xdrproc_t) &xdr_guestfs_sfdisk_kernel_geometry_ret, (char *) &ret);
  free (r);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_sfdisk_kernel_geometry_args, (char *) &args);
done_no_free:
  return;
}

static void
sfdisk_disk_geometry_stub (XDR *xdr_in)
{
  char *r;
  struct guestfs_sfdisk_disk_geometry_args args;
  CLEANUP_FREE char *device = NULL;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_sfdisk_disk_geometry_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args.device, device, , goto done);

  r = do_sfdisk_disk_geometry (device);
  if (r == NULL)
    /* do_sfdisk_disk_geometry has already called reply_with_error */
    goto done;

  struct guestfs_sfdisk_disk_geometry_ret ret;
  ret.partitions = r;
  reply ((xdrproc_t) &xdr_guestfs_sfdisk_disk_geometry_ret, (char *) &ret);
  free (r);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_sfdisk_disk_geometry_args, (char *) &args);
done_no_free:
  return;
}

static void
vg_activate_all_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_vg_activate_all_args args;
  int activate;

  /* The caller should have checked before calling this. */
  if (! optgroup_lvm2_available ()) {
    reply_with_unavailable_feature ("lvm2");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_vg_activate_all_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  activate = args.activate;

  r = do_vg_activate_all (activate);
  if (r == -1)
    /* do_vg_activate_all has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_vg_activate_all_args, (char *) &args);
done_no_free:
  return;
}

static void
vg_activate_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_vg_activate_args args;
  int activate;
  char **volgroups;

  /* The caller should have checked before calling this. */
  if (! optgroup_lvm2_available ()) {
    reply_with_unavailable_feature ("lvm2");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_vg_activate_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  activate = args.activate;
  /* Ugly, but safe and avoids copying the strings. */
  volgroups = realloc (args.volgroups.volgroups_val,
                sizeof (char *) * (args.volgroups.volgroups_len+1));
  if (volgroups == NULL) {
    reply_with_perror ("realloc");
    goto done;
  }
  volgroups[args.volgroups.volgroups_len] = NULL;
  args.volgroups.volgroups_val = volgroups;

  r = do_vg_activate (activate, volgroups);
  if (r == -1)
    /* do_vg_activate has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_vg_activate_args, (char *) &args);
done_no_free:
  return;
}

static void
lvresize_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_lvresize_args args;
  CLEANUP_FREE char *device = NULL;
  int mbytes;

  /* The caller should have checked before calling this. */
  if (! optgroup_lvm2_available ()) {
    reply_with_unavailable_feature ("lvm2");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_lvresize_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args.device, device, , goto done);
  mbytes = args.mbytes;

  r = do_lvresize (device, mbytes);
  if (r == -1)
    /* do_lvresize has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_lvresize_args, (char *) &args);
done_no_free:
  return;
}

static void
resize2fs_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_resize2fs_args args;
  CLEANUP_FREE char *device = NULL;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_resize2fs_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args.device, device, , goto done);

  r = do_resize2fs (device);
  if (r == -1)
    /* do_resize2fs has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_resize2fs_args, (char *) &args);
done_no_free:
  return;
}

static void
e2fsck_f_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_e2fsck_f_args args;
  CLEANUP_FREE char *device = NULL;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_e2fsck_f_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args.device, device, , goto done);

  r = do_e2fsck_f (device);
  if (r == -1)
    /* do_e2fsck_f has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_e2fsck_f_args, (char *) &args);
done_no_free:
  return;
}

static void
sleep_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_sleep_args args;
  int secs;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_sleep_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  secs = args.secs;

  r = do_sleep (secs);
  if (r == -1)
    /* do_sleep has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_sleep_args, (char *) &args);
done_no_free:
  return;
}

static void
ntfs_3g_probe_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_ntfs_3g_probe_args args;
  int rw;
  CLEANUP_FREE char *device = NULL;

  /* The caller should have checked before calling this. */
  if (! optgroup_ntfs3g_available ()) {
    reply_with_unavailable_feature ("ntfs3g");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_ntfs_3g_probe_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  rw = args.rw;
  RESOLVE_DEVICE (args.device, device, , goto done);

  r = do_ntfs_3g_probe (rw, device);
  if (r == -1)
    /* do_ntfs_3g_probe has already called reply_with_error */
    goto done;

  struct guestfs_ntfs_3g_probe_ret ret;
  ret.status = r;
  reply ((xdrproc_t) &xdr_guestfs_ntfs_3g_probe_ret, (char *) &ret);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_ntfs_3g_probe_args, (char *) &args);
done_no_free:
  return;
}

static void
sh_stub (XDR *xdr_in)
{
  char *r;
  struct guestfs_sh_args args;
  const char *command;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_sh_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  command = args.command;

  r = do_sh (command);
  if (r == NULL)
    /* do_sh has already called reply_with_error */
    goto done;

  struct guestfs_sh_ret ret;
  ret.output = r;
  reply ((xdrproc_t) &xdr_guestfs_sh_ret, (char *) &ret);
  free (r);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_sh_args, (char *) &args);
done_no_free:
  return;
}

static void
sh_lines_stub (XDR *xdr_in)
{
  char **r;
  struct guestfs_sh_lines_args args;
  const char *command;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_sh_lines_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  command = args.command;

  r = do_sh_lines (command);
  if (r == NULL)
    /* do_sh_lines has already called reply_with_error */
    goto done;

  struct guestfs_sh_lines_ret ret;
  ret.lines.lines_len = count_strings (r);
  ret.lines.lines_val = r;
  reply ((xdrproc_t) &xdr_guestfs_sh_lines_ret, (char *) &ret);
  free_strings (r);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_sh_lines_args, (char *) &args);
done_no_free:
  return;
}

static void
glob_expand_stub (XDR *xdr_in)
{
  char **r;
  struct guestfs_glob_expand_args args;
  const char *pattern;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_glob_expand_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  pattern = args.pattern;
  ABS_PATH (pattern, , goto done);

  NEED_ROOT (, goto done);
  r = do_glob_expand (pattern);
  if (r == NULL)
    /* do_glob_expand has already called reply_with_error */
    goto done;

  struct guestfs_glob_expand_ret ret;
  ret.paths.paths_len = count_strings (r);
  ret.paths.paths_val = r;
  reply ((xdrproc_t) &xdr_guestfs_glob_expand_ret, (char *) &ret);
  free_strings (r);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_glob_expand_args, (char *) &args);
done_no_free:
  return;
}

static void
scrub_device_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_scrub_device_args args;
  CLEANUP_FREE char *device = NULL;

  /* The caller should have checked before calling this. */
  if (! optgroup_scrub_available ()) {
    reply_with_unavailable_feature ("scrub");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_scrub_device_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args.device, device, , goto done);

  r = do_scrub_device (device);
  if (r == -1)
    /* do_scrub_device has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_scrub_device_args, (char *) &args);
done_no_free:
  return;
}

static void
scrub_file_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_scrub_file_args args;
  const char *file;

  /* The caller should have checked before calling this. */
  if (! optgroup_scrub_available ()) {
    reply_with_unavailable_feature ("scrub");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_scrub_file_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  file = args.file;
  ABS_PATH (file, , goto done);

  NEED_ROOT (, goto done);
  r = do_scrub_file (file);
  if (r == -1)
    /* do_scrub_file has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_scrub_file_args, (char *) &args);
done_no_free:
  return;
}

static void
scrub_freespace_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_scrub_freespace_args args;
  const char *dir;

  /* The caller should have checked before calling this. */
  if (! optgroup_scrub_available ()) {
    reply_with_unavailable_feature ("scrub");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_scrub_freespace_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  dir = args.dir;
  ABS_PATH (dir, , goto done);

  NEED_ROOT (, goto done);
  r = do_scrub_freespace (dir);
  if (r == -1)
    /* do_scrub_freespace has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_scrub_freespace_args, (char *) &args);
done_no_free:
  return;
}

static void
mkdtemp_stub (XDR *xdr_in)
{
  char *r;
  struct guestfs_mkdtemp_args args;
  const char *tmpl;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_mkdtemp_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  tmpl = args.tmpl;
  ABS_PATH (tmpl, , goto done);

  NEED_ROOT (, goto done);
  r = do_mkdtemp (tmpl);
  if (r == NULL)
    /* do_mkdtemp has already called reply_with_error */
    goto done;

  struct guestfs_mkdtemp_ret ret;
  ret.dir = r;
  reply ((xdrproc_t) &xdr_guestfs_mkdtemp_ret, (char *) &ret);
  free (r);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_mkdtemp_args, (char *) &args);
done_no_free:
  return;
}

static void
wc_l_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_wc_l_args args;
  const char *path;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_wc_l_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  path = args.path;
  ABS_PATH (path, , goto done);

  NEED_ROOT (, goto done);
  r = do_wc_l (path);
  if (r == -1)
    /* do_wc_l has already called reply_with_error */
    goto done;

  struct guestfs_wc_l_ret ret;
  ret.lines = r;
  reply ((xdrproc_t) &xdr_guestfs_wc_l_ret, (char *) &ret);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_wc_l_args, (char *) &args);
done_no_free:
  return;
}

static void
wc_w_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_wc_w_args args;
  const char *path;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_wc_w_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  path = args.path;
  ABS_PATH (path, , goto done);

  NEED_ROOT (, goto done);
  r = do_wc_w (path);
  if (r == -1)
    /* do_wc_w has already called reply_with_error */
    goto done;

  struct guestfs_wc_w_ret ret;
  ret.words = r;
  reply ((xdrproc_t) &xdr_guestfs_wc_w_ret, (char *) &ret);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_wc_w_args, (char *) &args);
done_no_free:
  return;
}

static void
wc_c_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_wc_c_args args;
  const char *path;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_wc_c_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  path = args.path;
  ABS_PATH (path, , goto done);

  NEED_ROOT (, goto done);
  r = do_wc_c (path);
  if (r == -1)
    /* do_wc_c has already called reply_with_error */
    goto done;

  struct guestfs_wc_c_ret ret;
  ret.chars = r;
  reply ((xdrproc_t) &xdr_guestfs_wc_c_ret, (char *) &ret);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_wc_c_args, (char *) &args);
done_no_free:
  return;
}

static void
head_stub (XDR *xdr_in)
{
  char **r;
  struct guestfs_head_args args;
  const char *path;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_head_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  path = args.path;
  ABS_PATH (path, , goto done);

  NEED_ROOT (, goto done);
  r = do_head (path);
  if (r == NULL)
    /* do_head has already called reply_with_error */
    goto done;

  struct guestfs_head_ret ret;
  ret.lines.lines_len = count_strings (r);
  ret.lines.lines_val = r;
  reply ((xdrproc_t) &xdr_guestfs_head_ret, (char *) &ret);
  free_strings (r);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_head_args, (char *) &args);
done_no_free:
  return;
}

static void
head_n_stub (XDR *xdr_in)
{
  char **r;
  struct guestfs_head_n_args args;
  int nrlines;
  const char *path;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_head_n_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  nrlines = args.nrlines;
  path = args.path;
  ABS_PATH (path, , goto done);

  NEED_ROOT (, goto done);
  r = do_head_n (nrlines, path);
  if (r == NULL)
    /* do_head_n has already called reply_with_error */
    goto done;

  struct guestfs_head_n_ret ret;
  ret.lines.lines_len = count_strings (r);
  ret.lines.lines_val = r;
  reply ((xdrproc_t) &xdr_guestfs_head_n_ret, (char *) &ret);
  free_strings (r);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_head_n_args, (char *) &args);
done_no_free:
  return;
}

static void
tail_stub (XDR *xdr_in)
{
  char **r;
  struct guestfs_tail_args args;
  const char *path;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_tail_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  path = args.path;
  ABS_PATH (path, , goto done);

  NEED_ROOT (, goto done);
  r = do_tail (path);
  if (r == NULL)
    /* do_tail has already called reply_with_error */
    goto done;

  struct guestfs_tail_ret ret;
  ret.lines.lines_len = count_strings (r);
  ret.lines.lines_val = r;
  reply ((xdrproc_t) &xdr_guestfs_tail_ret, (char *) &ret);
  free_strings (r);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_tail_args, (char *) &args);
done_no_free:
  return;
}

static void
tail_n_stub (XDR *xdr_in)
{
  char **r;
  struct guestfs_tail_n_args args;
  int nrlines;
  const char *path;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_tail_n_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  nrlines = args.nrlines;
  path = args.path;
  ABS_PATH (path, , goto done);

  NEED_ROOT (, goto done);
  r = do_tail_n (nrlines, path);
  if (r == NULL)
    /* do_tail_n has already called reply_with_error */
    goto done;

  struct guestfs_tail_n_ret ret;
  ret.lines.lines_len = count_strings (r);
  ret.lines.lines_val = r;
  reply ((xdrproc_t) &xdr_guestfs_tail_n_ret, (char *) &ret);
  free_strings (r);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_tail_n_args, (char *) &args);
done_no_free:
  return;
}

static void
df_stub (XDR *xdr_in)
{
  char *r;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  r = do_df ();
  if (r == NULL)
    /* do_df has already called reply_with_error */
    goto done;

  struct guestfs_df_ret ret;
  ret.output = r;
  reply ((xdrproc_t) &xdr_guestfs_df_ret, (char *) &ret);
  free (r);
done:
done_no_free:
  return;
}

static void
df_h_stub (XDR *xdr_in)
{
  char *r;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  r = do_df_h ();
  if (r == NULL)
    /* do_df_h has already called reply_with_error */
    goto done;

  struct guestfs_df_h_ret ret;
  ret.output = r;
  reply ((xdrproc_t) &xdr_guestfs_df_h_ret, (char *) &ret);
  free (r);
done:
done_no_free:
  return;
}

static void
du_stub (XDR *xdr_in)
{
  int64_t r;
  struct guestfs_du_args args;
  const char *path;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_du_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  path = args.path;
  ABS_PATH (path, , goto done);

  NEED_ROOT (, goto done);
  r = do_du (path);
  if (r == -1)
    /* do_du has already called reply_with_error */
    goto done;

  struct guestfs_du_ret ret;
  ret.sizekb = r;
  reply ((xdrproc_t) &xdr_guestfs_du_ret, (char *) &ret);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_du_args, (char *) &args);
done_no_free:
  return;
}

static void
initrd_list_stub (XDR *xdr_in)
{
  char **r;
  struct guestfs_initrd_list_args args;
  const char *path;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_initrd_list_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  path = args.path;
  ABS_PATH (path, , goto done);

  NEED_ROOT (, goto done);
  r = do_initrd_list (path);
  if (r == NULL)
    /* do_initrd_list has already called reply_with_error */
    goto done;

  struct guestfs_initrd_list_ret ret;
  ret.filenames.filenames_len = count_strings (r);
  ret.filenames.filenames_val = r;
  reply ((xdrproc_t) &xdr_guestfs_initrd_list_ret, (char *) &ret);
  free_strings (r);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_initrd_list_args, (char *) &args);
done_no_free:
  return;
}

static void
mount_loop_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_mount_loop_args args;
  const char *file;
  const char *mountpoint;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_mount_loop_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  file = args.file;
  ABS_PATH (file, , goto done);
  mountpoint = args.mountpoint;
  ABS_PATH (mountpoint, , goto done);

  NEED_ROOT (, goto done);
  r = do_mount_loop (file, mountpoint);
  if (r == -1)
    /* do_mount_loop has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_mount_loop_args, (char *) &args);
done_no_free:
  return;
}

static void
mkswap_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_mkswap_args args;
  CLEANUP_FREE char *device = NULL;
  const char *label;
  const char *uuid;

  if (optargs_bitmask & UINT64_C(0xfffffffffffffffc)) {
    reply_with_error ("unknown option in optional arguments bitmask (this can happen if a program is compiled against a newer version of libguestfs, then run against an older version of the daemon)");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_mkswap_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args.device, device, , goto done);
  label = args.label;
  uuid = args.uuid;

  r = do_mkswap (device, label, uuid);
  if (r == -1)
    /* do_mkswap has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_mkswap_args, (char *) &args);
done_no_free:
  return;
}

static void
mkswap_L_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_mkswap_L_args args;
  const char *label;
  CLEANUP_FREE char *device = NULL;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_mkswap_L_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  label = args.label;
  RESOLVE_DEVICE (args.device, device, , goto done);

  r = do_mkswap_L (label, device);
  if (r == -1)
    /* do_mkswap_L has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_mkswap_L_args, (char *) &args);
done_no_free:
  return;
}

static void
mkswap_U_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_mkswap_U_args args;
  const char *uuid;
  CLEANUP_FREE char *device = NULL;

  /* The caller should have checked before calling this. */
  if (! optgroup_linuxfsuuid_available ()) {
    reply_with_unavailable_feature ("linuxfsuuid");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_mkswap_U_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  uuid = args.uuid;
  RESOLVE_DEVICE (args.device, device, , goto done);

  r = do_mkswap_U (uuid, device);
  if (r == -1)
    /* do_mkswap_U has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_mkswap_U_args, (char *) &args);
done_no_free:
  return;
}

static void
mknod_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_mknod_args args;
  int mode;
  int devmajor;
  int devminor;
  const char *path;

  /* The caller should have checked before calling this. */
  if (! optgroup_mknod_available ()) {
    reply_with_unavailable_feature ("mknod");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_mknod_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  mode = args.mode;
  devmajor = args.devmajor;
  devminor = args.devminor;
  path = args.path;
  ABS_PATH (path, , goto done);

  NEED_ROOT (, goto done);
  r = do_mknod (mode, devmajor, devminor, path);
  if (r == -1)
    /* do_mknod has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_mknod_args, (char *) &args);
done_no_free:
  return;
}

static void
mkfifo_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_mkfifo_args args;
  int mode;
  const char *path;

  /* The caller should have checked before calling this. */
  if (! optgroup_mknod_available ()) {
    reply_with_unavailable_feature ("mknod");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_mkfifo_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  mode = args.mode;
  path = args.path;
  ABS_PATH (path, , goto done);

  NEED_ROOT (, goto done);
  r = do_mkfifo (mode, path);
  if (r == -1)
    /* do_mkfifo has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_mkfifo_args, (char *) &args);
done_no_free:
  return;
}

static void
mknod_b_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_mknod_b_args args;
  int mode;
  int devmajor;
  int devminor;
  const char *path;

  /* The caller should have checked before calling this. */
  if (! optgroup_mknod_available ()) {
    reply_with_unavailable_feature ("mknod");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_mknod_b_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  mode = args.mode;
  devmajor = args.devmajor;
  devminor = args.devminor;
  path = args.path;
  ABS_PATH (path, , goto done);

  NEED_ROOT (, goto done);
  r = do_mknod_b (mode, devmajor, devminor, path);
  if (r == -1)
    /* do_mknod_b has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_mknod_b_args, (char *) &args);
done_no_free:
  return;
}

static void
mknod_c_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_mknod_c_args args;
  int mode;
  int devmajor;
  int devminor;
  const char *path;

  /* The caller should have checked before calling this. */
  if (! optgroup_mknod_available ()) {
    reply_with_unavailable_feature ("mknod");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_mknod_c_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  mode = args.mode;
  devmajor = args.devmajor;
  devminor = args.devminor;
  path = args.path;
  ABS_PATH (path, , goto done);

  NEED_ROOT (, goto done);
  r = do_mknod_c (mode, devmajor, devminor, path);
  if (r == -1)
    /* do_mknod_c has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_mknod_c_args, (char *) &args);
done_no_free:
  return;
}

static void
umask_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_umask_args args;
  int mask;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_umask_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  mask = args.mask;

  r = do_umask (mask);
  if (r == -1)
    /* do_umask has already called reply_with_error */
    goto done;

  struct guestfs_umask_ret ret;
  ret.oldmask = r;
  reply ((xdrproc_t) &xdr_guestfs_umask_ret, (char *) &ret);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_umask_args, (char *) &args);
done_no_free:
  return;
}

static void
readdir_stub (XDR *xdr_in)
{
  guestfs_int_dirent_list *r;
  struct guestfs_readdir_args args;
  const char *dir;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_readdir_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  dir = args.dir;
  ABS_PATH (dir, , goto done);

  NEED_ROOT (, goto done);
  r = do_readdir (dir);
  if (r == NULL)
    /* do_readdir has already called reply_with_error */
    goto done;

  struct guestfs_readdir_ret ret;
  ret.entries = *r;
  free (r);
  reply ((xdrproc_t) xdr_guestfs_readdir_ret, (char *) &ret);
  xdr_free ((xdrproc_t) xdr_guestfs_readdir_ret, (char *) &ret);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_readdir_args, (char *) &args);
done_no_free:
  return;
}

static void
sfdiskM_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_sfdiskM_args args;
  CLEANUP_FREE char *device = NULL;
  char **lines;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_sfdiskM_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args.device, device, , goto done);
  /* Ugly, but safe and avoids copying the strings. */
  lines = realloc (args.lines.lines_val,
                sizeof (char *) * (args.lines.lines_len+1));
  if (lines == NULL) {
    reply_with_perror ("realloc");
    goto done;
  }
  lines[args.lines.lines_len] = NULL;
  args.lines.lines_val = lines;

  r = do_sfdiskM (device, lines);
  if (r == -1)
    /* do_sfdiskM has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_sfdiskM_args, (char *) &args);
done_no_free:
  return;
}

static void
zfile_stub (XDR *xdr_in)
{
  char *r;
  struct guestfs_zfile_args args;
  const char *meth;
  const char *path;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_zfile_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  meth = args.meth;
  path = args.path;
  ABS_PATH (path, , goto done);

  NEED_ROOT (, goto done);
  r = do_zfile (meth, path);
  if (r == NULL)
    /* do_zfile has already called reply_with_error */
    goto done;

  struct guestfs_zfile_ret ret;
  ret.description = r;
  reply ((xdrproc_t) &xdr_guestfs_zfile_ret, (char *) &ret);
  free (r);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_zfile_args, (char *) &args);
done_no_free:
  return;
}

static void
getxattrs_stub (XDR *xdr_in)
{
  guestfs_int_xattr_list *r;
  struct guestfs_getxattrs_args args;
  const char *path;

  /* The caller should have checked before calling this. */
  if (! optgroup_linuxxattrs_available ()) {
    reply_with_unavailable_feature ("linuxxattrs");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_getxattrs_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  path = args.path;
  ABS_PATH (path, , goto done);

  NEED_ROOT (, goto done);
  r = do_getxattrs (path);
  if (r == NULL)
    /* do_getxattrs has already called reply_with_error */
    goto done;

  struct guestfs_getxattrs_ret ret;
  ret.xattrs = *r;
  free (r);
  reply ((xdrproc_t) xdr_guestfs_getxattrs_ret, (char *) &ret);
  xdr_free ((xdrproc_t) xdr_guestfs_getxattrs_ret, (char *) &ret);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_getxattrs_args, (char *) &args);
done_no_free:
  return;
}

static void
lgetxattrs_stub (XDR *xdr_in)
{
  guestfs_int_xattr_list *r;
  struct guestfs_lgetxattrs_args args;
  const char *path;

  /* The caller should have checked before calling this. */
  if (! optgroup_linuxxattrs_available ()) {
    reply_with_unavailable_feature ("linuxxattrs");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_lgetxattrs_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  path = args.path;
  ABS_PATH (path, , goto done);

  NEED_ROOT (, goto done);
  r = do_lgetxattrs (path);
  if (r == NULL)
    /* do_lgetxattrs has already called reply_with_error */
    goto done;

  struct guestfs_lgetxattrs_ret ret;
  ret.xattrs = *r;
  free (r);
  reply ((xdrproc_t) xdr_guestfs_lgetxattrs_ret, (char *) &ret);
  xdr_free ((xdrproc_t) xdr_guestfs_lgetxattrs_ret, (char *) &ret);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_lgetxattrs_args, (char *) &args);
done_no_free:
  return;
}

static void
setxattr_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_setxattr_args args;
  const char *xattr;
  const char *val;
  int vallen;
  const char *path;

  /* The caller should have checked before calling this. */
  if (! optgroup_linuxxattrs_available ()) {
    reply_with_unavailable_feature ("linuxxattrs");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_setxattr_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  xattr = args.xattr;
  val = args.val;
  vallen = args.vallen;
  path = args.path;
  ABS_PATH (path, , goto done);

  NEED_ROOT (, goto done);
  r = do_setxattr (xattr, val, vallen, path);
  if (r == -1)
    /* do_setxattr has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_setxattr_args, (char *) &args);
done_no_free:
  return;
}

static void
lsetxattr_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_lsetxattr_args args;
  const char *xattr;
  const char *val;
  int vallen;
  const char *path;

  /* The caller should have checked before calling this. */
  if (! optgroup_linuxxattrs_available ()) {
    reply_with_unavailable_feature ("linuxxattrs");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_lsetxattr_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  xattr = args.xattr;
  val = args.val;
  vallen = args.vallen;
  path = args.path;
  ABS_PATH (path, , goto done);

  NEED_ROOT (, goto done);
  r = do_lsetxattr (xattr, val, vallen, path);
  if (r == -1)
    /* do_lsetxattr has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_lsetxattr_args, (char *) &args);
done_no_free:
  return;
}

static void
removexattr_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_removexattr_args args;
  const char *xattr;
  const char *path;

  /* The caller should have checked before calling this. */
  if (! optgroup_linuxxattrs_available ()) {
    reply_with_unavailable_feature ("linuxxattrs");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_removexattr_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  xattr = args.xattr;
  path = args.path;
  ABS_PATH (path, , goto done);

  NEED_ROOT (, goto done);
  r = do_removexattr (xattr, path);
  if (r == -1)
    /* do_removexattr has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_removexattr_args, (char *) &args);
done_no_free:
  return;
}

static void
lremovexattr_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_lremovexattr_args args;
  const char *xattr;
  const char *path;

  /* The caller should have checked before calling this. */
  if (! optgroup_linuxxattrs_available ()) {
    reply_with_unavailable_feature ("linuxxattrs");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_lremovexattr_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  xattr = args.xattr;
  path = args.path;
  ABS_PATH (path, , goto done);

  NEED_ROOT (, goto done);
  r = do_lremovexattr (xattr, path);
  if (r == -1)
    /* do_lremovexattr has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_lremovexattr_args, (char *) &args);
done_no_free:
  return;
}

static void
mountpoints_stub (XDR *xdr_in)
{
  char **r;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  r = do_mountpoints ();
  if (r == NULL)
    /* do_mountpoints has already called reply_with_error */
    goto done;

  struct guestfs_mountpoints_ret ret;
  ret.mps.mps_len = count_strings (r);
  ret.mps.mps_val = r;
  reply ((xdrproc_t) &xdr_guestfs_mountpoints_ret, (char *) &ret);
  free_strings (r);
done:
done_no_free:
  return;
}

static void
mkmountpoint_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_mkmountpoint_args args;
  const char *exemptpath;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_mkmountpoint_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  exemptpath = args.exemptpath;

  r = do_mkmountpoint (exemptpath);
  if (r == -1)
    /* do_mkmountpoint has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_mkmountpoint_args, (char *) &args);
done_no_free:
  return;
}

static void
rmmountpoint_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_rmmountpoint_args args;
  const char *exemptpath;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_rmmountpoint_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  exemptpath = args.exemptpath;

  r = do_rmmountpoint (exemptpath);
  if (r == -1)
    /* do_rmmountpoint has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_rmmountpoint_args, (char *) &args);
done_no_free:
  return;
}

static void
grep_stub (XDR *xdr_in)
{
  char **r;
  struct guestfs_grep_args args;
  const char *regex;
  const char *path;
  int extended;
  int fixed;
  int insensitive;
  int compressed;

  if (optargs_bitmask & UINT64_C(0xfffffffffffffff0)) {
    reply_with_error ("unknown option in optional arguments bitmask (this can happen if a program is compiled against a newer version of libguestfs, then run against an older version of the daemon)");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_grep_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  regex = args.regex;
  path = args.path;
  ABS_PATH (path, , goto done);
  extended = args.extended;
  fixed = args.fixed;
  insensitive = args.insensitive;
  compressed = args.compressed;

  NEED_ROOT (, goto done);
  r = do_grep (regex, path, extended, fixed, insensitive, compressed);
  if (r == NULL)
    /* do_grep has already called reply_with_error */
    goto done;

  struct guestfs_grep_ret ret;
  ret.lines.lines_len = count_strings (r);
  ret.lines.lines_val = r;
  reply ((xdrproc_t) &xdr_guestfs_grep_ret, (char *) &ret);
  free_strings (r);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_grep_args, (char *) &args);
done_no_free:
  return;
}

static void
egrep_stub (XDR *xdr_in)
{
  char **r;
  struct guestfs_egrep_args args;
  const char *regex;
  const char *path;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_egrep_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  regex = args.regex;
  path = args.path;
  ABS_PATH (path, , goto done);

  NEED_ROOT (, goto done);
  r = do_egrep (regex, path);
  if (r == NULL)
    /* do_egrep has already called reply_with_error */
    goto done;

  struct guestfs_egrep_ret ret;
  ret.lines.lines_len = count_strings (r);
  ret.lines.lines_val = r;
  reply ((xdrproc_t) &xdr_guestfs_egrep_ret, (char *) &ret);
  free_strings (r);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_egrep_args, (char *) &args);
done_no_free:
  return;
}

static void
fgrep_stub (XDR *xdr_in)
{
  char **r;
  struct guestfs_fgrep_args args;
  const char *pattern;
  const char *path;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_fgrep_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  pattern = args.pattern;
  path = args.path;
  ABS_PATH (path, , goto done);

  NEED_ROOT (, goto done);
  r = do_fgrep (pattern, path);
  if (r == NULL)
    /* do_fgrep has already called reply_with_error */
    goto done;

  struct guestfs_fgrep_ret ret;
  ret.lines.lines_len = count_strings (r);
  ret.lines.lines_val = r;
  reply ((xdrproc_t) &xdr_guestfs_fgrep_ret, (char *) &ret);
  free_strings (r);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_fgrep_args, (char *) &args);
done_no_free:
  return;
}

static void
grepi_stub (XDR *xdr_in)
{
  char **r;
  struct guestfs_grepi_args args;
  const char *regex;
  const char *path;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_grepi_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  regex = args.regex;
  path = args.path;
  ABS_PATH (path, , goto done);

  NEED_ROOT (, goto done);
  r = do_grepi (regex, path);
  if (r == NULL)
    /* do_grepi has already called reply_with_error */
    goto done;

  struct guestfs_grepi_ret ret;
  ret.lines.lines_len = count_strings (r);
  ret.lines.lines_val = r;
  reply ((xdrproc_t) &xdr_guestfs_grepi_ret, (char *) &ret);
  free_strings (r);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_grepi_args, (char *) &args);
done_no_free:
  return;
}

static void
egrepi_stub (XDR *xdr_in)
{
  char **r;
  struct guestfs_egrepi_args args;
  const char *regex;
  const char *path;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_egrepi_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  regex = args.regex;
  path = args.path;
  ABS_PATH (path, , goto done);

  NEED_ROOT (, goto done);
  r = do_egrepi (regex, path);
  if (r == NULL)
    /* do_egrepi has already called reply_with_error */
    goto done;

  struct guestfs_egrepi_ret ret;
  ret.lines.lines_len = count_strings (r);
  ret.lines.lines_val = r;
  reply ((xdrproc_t) &xdr_guestfs_egrepi_ret, (char *) &ret);
  free_strings (r);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_egrepi_args, (char *) &args);
done_no_free:
  return;
}

static void
fgrepi_stub (XDR *xdr_in)
{
  char **r;
  struct guestfs_fgrepi_args args;
  const char *pattern;
  const char *path;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_fgrepi_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  pattern = args.pattern;
  path = args.path;
  ABS_PATH (path, , goto done);

  NEED_ROOT (, goto done);
  r = do_fgrepi (pattern, path);
  if (r == NULL)
    /* do_fgrepi has already called reply_with_error */
    goto done;

  struct guestfs_fgrepi_ret ret;
  ret.lines.lines_len = count_strings (r);
  ret.lines.lines_val = r;
  reply ((xdrproc_t) &xdr_guestfs_fgrepi_ret, (char *) &ret);
  free_strings (r);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_fgrepi_args, (char *) &args);
done_no_free:
  return;
}

static void
zgrep_stub (XDR *xdr_in)
{
  char **r;
  struct guestfs_zgrep_args args;
  const char *regex;
  const char *path;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_zgrep_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  regex = args.regex;
  path = args.path;
  ABS_PATH (path, , goto done);

  NEED_ROOT (, goto done);
  r = do_zgrep (regex, path);
  if (r == NULL)
    /* do_zgrep has already called reply_with_error */
    goto done;

  struct guestfs_zgrep_ret ret;
  ret.lines.lines_len = count_strings (r);
  ret.lines.lines_val = r;
  reply ((xdrproc_t) &xdr_guestfs_zgrep_ret, (char *) &ret);
  free_strings (r);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_zgrep_args, (char *) &args);
done_no_free:
  return;
}

static void
zegrep_stub (XDR *xdr_in)
{
  char **r;
  struct guestfs_zegrep_args args;
  const char *regex;
  const char *path;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_zegrep_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  regex = args.regex;
  path = args.path;
  ABS_PATH (path, , goto done);

  NEED_ROOT (, goto done);
  r = do_zegrep (regex, path);
  if (r == NULL)
    /* do_zegrep has already called reply_with_error */
    goto done;

  struct guestfs_zegrep_ret ret;
  ret.lines.lines_len = count_strings (r);
  ret.lines.lines_val = r;
  reply ((xdrproc_t) &xdr_guestfs_zegrep_ret, (char *) &ret);
  free_strings (r);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_zegrep_args, (char *) &args);
done_no_free:
  return;
}

static void
zfgrep_stub (XDR *xdr_in)
{
  char **r;
  struct guestfs_zfgrep_args args;
  const char *pattern;
  const char *path;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_zfgrep_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  pattern = args.pattern;
  path = args.path;
  ABS_PATH (path, , goto done);

  NEED_ROOT (, goto done);
  r = do_zfgrep (pattern, path);
  if (r == NULL)
    /* do_zfgrep has already called reply_with_error */
    goto done;

  struct guestfs_zfgrep_ret ret;
  ret.lines.lines_len = count_strings (r);
  ret.lines.lines_val = r;
  reply ((xdrproc_t) &xdr_guestfs_zfgrep_ret, (char *) &ret);
  free_strings (r);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_zfgrep_args, (char *) &args);
done_no_free:
  return;
}

static void
zgrepi_stub (XDR *xdr_in)
{
  char **r;
  struct guestfs_zgrepi_args args;
  const char *regex;
  const char *path;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_zgrepi_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  regex = args.regex;
  path = args.path;
  ABS_PATH (path, , goto done);

  NEED_ROOT (, goto done);
  r = do_zgrepi (regex, path);
  if (r == NULL)
    /* do_zgrepi has already called reply_with_error */
    goto done;

  struct guestfs_zgrepi_ret ret;
  ret.lines.lines_len = count_strings (r);
  ret.lines.lines_val = r;
  reply ((xdrproc_t) &xdr_guestfs_zgrepi_ret, (char *) &ret);
  free_strings (r);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_zgrepi_args, (char *) &args);
done_no_free:
  return;
}

static void
zegrepi_stub (XDR *xdr_in)
{
  char **r;
  struct guestfs_zegrepi_args args;
  const char *regex;
  const char *path;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_zegrepi_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  regex = args.regex;
  path = args.path;
  ABS_PATH (path, , goto done);

  NEED_ROOT (, goto done);
  r = do_zegrepi (regex, path);
  if (r == NULL)
    /* do_zegrepi has already called reply_with_error */
    goto done;

  struct guestfs_zegrepi_ret ret;
  ret.lines.lines_len = count_strings (r);
  ret.lines.lines_val = r;
  reply ((xdrproc_t) &xdr_guestfs_zegrepi_ret, (char *) &ret);
  free_strings (r);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_zegrepi_args, (char *) &args);
done_no_free:
  return;
}

static void
zfgrepi_stub (XDR *xdr_in)
{
  char **r;
  struct guestfs_zfgrepi_args args;
  const char *pattern;
  const char *path;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_zfgrepi_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  pattern = args.pattern;
  path = args.path;
  ABS_PATH (path, , goto done);

  NEED_ROOT (, goto done);
  r = do_zfgrepi (pattern, path);
  if (r == NULL)
    /* do_zfgrepi has already called reply_with_error */
    goto done;

  struct guestfs_zfgrepi_ret ret;
  ret.lines.lines_len = count_strings (r);
  ret.lines.lines_val = r;
  reply ((xdrproc_t) &xdr_guestfs_zfgrepi_ret, (char *) &ret);
  free_strings (r);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_zfgrepi_args, (char *) &args);
done_no_free:
  return;
}

static void
realpath_stub (XDR *xdr_in)
{
  char *r;
  struct guestfs_realpath_args args;
  const char *path;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_realpath_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  path = args.path;
  ABS_PATH (path, , goto done);

  NEED_ROOT (, goto done);
  r = do_realpath (path);
  if (r == NULL)
    /* do_realpath has already called reply_with_error */
    goto done;

  struct guestfs_realpath_ret ret;
  ret.rpath = r;
  reply ((xdrproc_t) &xdr_guestfs_realpath_ret, (char *) &ret);
  free (r);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_realpath_args, (char *) &args);
done_no_free:
  return;
}

static void
ln_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_ln_args args;
  const char *target;
  const char *linkname;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_ln_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  target = args.target;
  linkname = args.linkname;
  ABS_PATH (linkname, , goto done);

  NEED_ROOT (, goto done);
  r = do_ln (target, linkname);
  if (r == -1)
    /* do_ln has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_ln_args, (char *) &args);
done_no_free:
  return;
}

static void
ln_f_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_ln_f_args args;
  const char *target;
  const char *linkname;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_ln_f_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  target = args.target;
  linkname = args.linkname;
  ABS_PATH (linkname, , goto done);

  NEED_ROOT (, goto done);
  r = do_ln_f (target, linkname);
  if (r == -1)
    /* do_ln_f has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_ln_f_args, (char *) &args);
done_no_free:
  return;
}

static void
ln_s_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_ln_s_args args;
  const char *target;
  const char *linkname;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_ln_s_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  target = args.target;
  linkname = args.linkname;
  ABS_PATH (linkname, , goto done);

  NEED_ROOT (, goto done);
  r = do_ln_s (target, linkname);
  if (r == -1)
    /* do_ln_s has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_ln_s_args, (char *) &args);
done_no_free:
  return;
}

static void
ln_sf_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_ln_sf_args args;
  const char *target;
  const char *linkname;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_ln_sf_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  target = args.target;
  linkname = args.linkname;
  ABS_PATH (linkname, , goto done);

  NEED_ROOT (, goto done);
  r = do_ln_sf (target, linkname);
  if (r == -1)
    /* do_ln_sf has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_ln_sf_args, (char *) &args);
done_no_free:
  return;
}

static void
readlink_stub (XDR *xdr_in)
{
  char *r;
  struct guestfs_readlink_args args;
  const char *path;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_readlink_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  path = args.path;
  ABS_PATH (path, , goto done);

  NEED_ROOT (, goto done);
  r = do_readlink (path);
  if (r == NULL)
    /* do_readlink has already called reply_with_error */
    goto done;

  struct guestfs_readlink_ret ret;
  ret.link = r;
  reply ((xdrproc_t) &xdr_guestfs_readlink_ret, (char *) &ret);
  free (r);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_readlink_args, (char *) &args);
done_no_free:
  return;
}

static void
fallocate_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_fallocate_args args;
  const char *path;
  int len;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_fallocate_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  path = args.path;
  ABS_PATH (path, , goto done);
  len = args.len;

  NEED_ROOT (, goto done);
  r = do_fallocate (path, len);
  if (r == -1)
    /* do_fallocate has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_fallocate_args, (char *) &args);
done_no_free:
  return;
}

static void
swapon_device_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_swapon_device_args args;
  CLEANUP_FREE char *device = NULL;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_swapon_device_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args.device, device, , goto done);

  r = do_swapon_device (device);
  if (r == -1)
    /* do_swapon_device has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_swapon_device_args, (char *) &args);
done_no_free:
  return;
}

static void
swapoff_device_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_swapoff_device_args args;
  CLEANUP_FREE char *device = NULL;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_swapoff_device_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args.device, device, , goto done);

  r = do_swapoff_device (device);
  if (r == -1)
    /* do_swapoff_device has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_swapoff_device_args, (char *) &args);
done_no_free:
  return;
}

static void
swapon_file_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_swapon_file_args args;
  const char *file;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_swapon_file_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  file = args.file;
  ABS_PATH (file, , goto done);

  NEED_ROOT (, goto done);
  r = do_swapon_file (file);
  if (r == -1)
    /* do_swapon_file has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_swapon_file_args, (char *) &args);
done_no_free:
  return;
}

static void
swapoff_file_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_swapoff_file_args args;
  const char *file;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_swapoff_file_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  file = args.file;
  ABS_PATH (file, , goto done);

  NEED_ROOT (, goto done);
  r = do_swapoff_file (file);
  if (r == -1)
    /* do_swapoff_file has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_swapoff_file_args, (char *) &args);
done_no_free:
  return;
}

static void
swapon_label_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_swapon_label_args args;
  const char *label;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_swapon_label_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  label = args.label;

  r = do_swapon_label (label);
  if (r == -1)
    /* do_swapon_label has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_swapon_label_args, (char *) &args);
done_no_free:
  return;
}

static void
swapoff_label_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_swapoff_label_args args;
  const char *label;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_swapoff_label_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  label = args.label;

  r = do_swapoff_label (label);
  if (r == -1)
    /* do_swapoff_label has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_swapoff_label_args, (char *) &args);
done_no_free:
  return;
}

static void
swapon_uuid_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_swapon_uuid_args args;
  const char *uuid;

  /* The caller should have checked before calling this. */
  if (! optgroup_linuxfsuuid_available ()) {
    reply_with_unavailable_feature ("linuxfsuuid");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_swapon_uuid_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  uuid = args.uuid;

  r = do_swapon_uuid (uuid);
  if (r == -1)
    /* do_swapon_uuid has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_swapon_uuid_args, (char *) &args);
done_no_free:
  return;
}

static void
swapoff_uuid_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_swapoff_uuid_args args;
  const char *uuid;

  /* The caller should have checked before calling this. */
  if (! optgroup_linuxfsuuid_available ()) {
    reply_with_unavailable_feature ("linuxfsuuid");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_swapoff_uuid_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  uuid = args.uuid;

  r = do_swapoff_uuid (uuid);
  if (r == -1)
    /* do_swapoff_uuid has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_swapoff_uuid_args, (char *) &args);
done_no_free:
  return;
}

static void
mkswap_file_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_mkswap_file_args args;
  const char *path;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_mkswap_file_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  path = args.path;
  ABS_PATH (path, , goto done);

  NEED_ROOT (, goto done);
  r = do_mkswap_file (path);
  if (r == -1)
    /* do_mkswap_file has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_mkswap_file_args, (char *) &args);
done_no_free:
  return;
}

static void
inotify_init_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_inotify_init_args args;
  int maxevents;

  /* The caller should have checked before calling this. */
  if (! optgroup_inotify_available ()) {
    reply_with_unavailable_feature ("inotify");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_inotify_init_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  maxevents = args.maxevents;

  r = do_inotify_init (maxevents);
  if (r == -1)
    /* do_inotify_init has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_inotify_init_args, (char *) &args);
done_no_free:
  return;
}

static void
inotify_add_watch_stub (XDR *xdr_in)
{
  int64_t r;
  struct guestfs_inotify_add_watch_args args;
  const char *path;
  int mask;

  /* The caller should have checked before calling this. */
  if (! optgroup_inotify_available ()) {
    reply_with_unavailable_feature ("inotify");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_inotify_add_watch_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  path = args.path;
  ABS_PATH (path, , goto done);
  mask = args.mask;

  NEED_ROOT (, goto done);
  r = do_inotify_add_watch (path, mask);
  if (r == -1)
    /* do_inotify_add_watch has already called reply_with_error */
    goto done;

  struct guestfs_inotify_add_watch_ret ret;
  ret.wd = r;
  reply ((xdrproc_t) &xdr_guestfs_inotify_add_watch_ret, (char *) &ret);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_inotify_add_watch_args, (char *) &args);
done_no_free:
  return;
}

static void
inotify_rm_watch_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_inotify_rm_watch_args args;
  int wd;

  /* The caller should have checked before calling this. */
  if (! optgroup_inotify_available ()) {
    reply_with_unavailable_feature ("inotify");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_inotify_rm_watch_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  wd = args.wd;

  r = do_inotify_rm_watch (wd);
  if (r == -1)
    /* do_inotify_rm_watch has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_inotify_rm_watch_args, (char *) &args);
done_no_free:
  return;
}

static void
inotify_read_stub (XDR *xdr_in)
{
  guestfs_int_inotify_event_list *r;

  /* The caller should have checked before calling this. */
  if (! optgroup_inotify_available ()) {
    reply_with_unavailable_feature ("inotify");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  r = do_inotify_read ();
  if (r == NULL)
    /* do_inotify_read has already called reply_with_error */
    goto done;

  struct guestfs_inotify_read_ret ret;
  ret.events = *r;
  free (r);
  reply ((xdrproc_t) xdr_guestfs_inotify_read_ret, (char *) &ret);
  xdr_free ((xdrproc_t) xdr_guestfs_inotify_read_ret, (char *) &ret);
done:
done_no_free:
  return;
}

static void
inotify_files_stub (XDR *xdr_in)
{
  char **r;

  /* The caller should have checked before calling this. */
  if (! optgroup_inotify_available ()) {
    reply_with_unavailable_feature ("inotify");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  r = do_inotify_files ();
  if (r == NULL)
    /* do_inotify_files has already called reply_with_error */
    goto done;

  struct guestfs_inotify_files_ret ret;
  ret.paths.paths_len = count_strings (r);
  ret.paths.paths_val = r;
  reply ((xdrproc_t) &xdr_guestfs_inotify_files_ret, (char *) &ret);
  free_strings (r);
done:
done_no_free:
  return;
}

static void
inotify_close_stub (XDR *xdr_in)
{
  int r;

  /* The caller should have checked before calling this. */
  if (! optgroup_inotify_available ()) {
    reply_with_unavailable_feature ("inotify");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  r = do_inotify_close ();
  if (r == -1)
    /* do_inotify_close has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
done_no_free:
  return;
}

static void
setcon_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_setcon_args args;
  const char *context;

  /* The caller should have checked before calling this. */
  if (! optgroup_selinux_available ()) {
    reply_with_unavailable_feature ("selinux");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_setcon_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  context = args.context;

  r = do_setcon (context);
  if (r == -1)
    /* do_setcon has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_setcon_args, (char *) &args);
done_no_free:
  return;
}

static void
getcon_stub (XDR *xdr_in)
{
  char *r;

  /* The caller should have checked before calling this. */
  if (! optgroup_selinux_available ()) {
    reply_with_unavailable_feature ("selinux");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  r = do_getcon ();
  if (r == NULL)
    /* do_getcon has already called reply_with_error */
    goto done;

  struct guestfs_getcon_ret ret;
  ret.context = r;
  reply ((xdrproc_t) &xdr_guestfs_getcon_ret, (char *) &ret);
  free (r);
done:
done_no_free:
  return;
}

static void
mkfs_b_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_mkfs_b_args args;
  const char *fstype;
  int blocksize;
  CLEANUP_FREE char *device = NULL;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_mkfs_b_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  fstype = args.fstype;
  blocksize = args.blocksize;
  RESOLVE_DEVICE (args.device, device, , goto done);

  r = do_mkfs_b (fstype, blocksize, device);
  if (r == -1)
    /* do_mkfs_b has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_mkfs_b_args, (char *) &args);
done_no_free:
  return;
}

static void
mke2journal_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_mke2journal_args args;
  int blocksize;
  CLEANUP_FREE char *device = NULL;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_mke2journal_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  blocksize = args.blocksize;
  RESOLVE_DEVICE (args.device, device, , goto done);

  r = do_mke2journal (blocksize, device);
  if (r == -1)
    /* do_mke2journal has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_mke2journal_args, (char *) &args);
done_no_free:
  return;
}

static void
mke2journal_L_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_mke2journal_L_args args;
  int blocksize;
  const char *label;
  CLEANUP_FREE char *device = NULL;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_mke2journal_L_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  blocksize = args.blocksize;
  label = args.label;
  RESOLVE_DEVICE (args.device, device, , goto done);

  r = do_mke2journal_L (blocksize, label, device);
  if (r == -1)
    /* do_mke2journal_L has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_mke2journal_L_args, (char *) &args);
done_no_free:
  return;
}

static void
mke2journal_U_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_mke2journal_U_args args;
  int blocksize;
  const char *uuid;
  CLEANUP_FREE char *device = NULL;

  /* The caller should have checked before calling this. */
  if (! optgroup_linuxfsuuid_available ()) {
    reply_with_unavailable_feature ("linuxfsuuid");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_mke2journal_U_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  blocksize = args.blocksize;
  uuid = args.uuid;
  RESOLVE_DEVICE (args.device, device, , goto done);

  r = do_mke2journal_U (blocksize, uuid, device);
  if (r == -1)
    /* do_mke2journal_U has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_mke2journal_U_args, (char *) &args);
done_no_free:
  return;
}

static void
mke2fs_J_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_mke2fs_J_args args;
  const char *fstype;
  int blocksize;
  CLEANUP_FREE char *device = NULL;
  CLEANUP_FREE char *journal = NULL;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_mke2fs_J_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  fstype = args.fstype;
  blocksize = args.blocksize;
  RESOLVE_DEVICE (args.device, device, , goto done);
  RESOLVE_DEVICE (args.journal, journal, , goto done);

  r = do_mke2fs_J (fstype, blocksize, device, journal);
  if (r == -1)
    /* do_mke2fs_J has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_mke2fs_J_args, (char *) &args);
done_no_free:
  return;
}

static void
mke2fs_JL_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_mke2fs_JL_args args;
  const char *fstype;
  int blocksize;
  CLEANUP_FREE char *device = NULL;
  const char *label;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_mke2fs_JL_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  fstype = args.fstype;
  blocksize = args.blocksize;
  RESOLVE_DEVICE (args.device, device, , goto done);
  label = args.label;

  r = do_mke2fs_JL (fstype, blocksize, device, label);
  if (r == -1)
    /* do_mke2fs_JL has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_mke2fs_JL_args, (char *) &args);
done_no_free:
  return;
}

static void
mke2fs_JU_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_mke2fs_JU_args args;
  const char *fstype;
  int blocksize;
  CLEANUP_FREE char *device = NULL;
  const char *uuid;

  /* The caller should have checked before calling this. */
  if (! optgroup_linuxfsuuid_available ()) {
    reply_with_unavailable_feature ("linuxfsuuid");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_mke2fs_JU_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  fstype = args.fstype;
  blocksize = args.blocksize;
  RESOLVE_DEVICE (args.device, device, , goto done);
  uuid = args.uuid;

  r = do_mke2fs_JU (fstype, blocksize, device, uuid);
  if (r == -1)
    /* do_mke2fs_JU has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_mke2fs_JU_args, (char *) &args);
done_no_free:
  return;
}

static void
modprobe_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_modprobe_args args;
  const char *modulename;

  /* The caller should have checked before calling this. */
  if (! optgroup_linuxmodules_available ()) {
    reply_with_unavailable_feature ("linuxmodules");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_modprobe_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  modulename = args.modulename;

  r = do_modprobe (modulename);
  if (r == -1)
    /* do_modprobe has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_modprobe_args, (char *) &args);
done_no_free:
  return;
}

static void
echo_daemon_stub (XDR *xdr_in)
{
  char *r;
  struct guestfs_echo_daemon_args args;
  char **words;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_echo_daemon_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  /* Ugly, but safe and avoids copying the strings. */
  words = realloc (args.words.words_val,
                sizeof (char *) * (args.words.words_len+1));
  if (words == NULL) {
    reply_with_perror ("realloc");
    goto done;
  }
  words[args.words.words_len] = NULL;
  args.words.words_val = words;

  r = do_echo_daemon (words);
  if (r == NULL)
    /* do_echo_daemon has already called reply_with_error */
    goto done;

  struct guestfs_echo_daemon_ret ret;
  ret.output = r;
  reply ((xdrproc_t) &xdr_guestfs_echo_daemon_ret, (char *) &ret);
  free (r);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_echo_daemon_args, (char *) &args);
done_no_free:
  return;
}

static void
find0_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_find0_args args;
  const char *directory;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_find0_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  directory = args.directory;
  ABS_PATH (directory, , goto done);

  NEED_ROOT (, goto done);
  r = do_find0 (directory);
  if (r == -1)
    /* do_find0 has already called reply_with_error */
    goto done;

  /* do_find0 has already sent a reply */
done:
  xdr_free ((xdrproc_t) xdr_guestfs_find0_args, (char *) &args);
done_no_free:
  return;
}

static void
case_sensitive_path_stub (XDR *xdr_in)
{
  char *r;
  struct guestfs_case_sensitive_path_args args;
  const char *path;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_case_sensitive_path_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  path = args.path;
  ABS_PATH (path, , goto done);

  NEED_ROOT (, goto done);
  r = do_case_sensitive_path (path);
  if (r == NULL)
    /* do_case_sensitive_path has already called reply_with_error */
    goto done;

  struct guestfs_case_sensitive_path_ret ret;
  ret.rpath = r;
  reply ((xdrproc_t) &xdr_guestfs_case_sensitive_path_ret, (char *) &ret);
  free (r);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_case_sensitive_path_args, (char *) &args);
done_no_free:
  return;
}

static void
vfs_type_stub (XDR *xdr_in)
{
  char *r;
  struct guestfs_vfs_type_args args;
  CLEANUP_FREE_MOUNTABLE mountable_t mountable
      = { .device = NULL, .volume = NULL };

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_vfs_type_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_MOUNTABLE (args.mountable, mountable, , goto done);

  r = do_vfs_type (&mountable);
  if (r == NULL)
    /* do_vfs_type has already called reply_with_error */
    goto done;

  struct guestfs_vfs_type_ret ret;
  ret.fstype = r;
  reply ((xdrproc_t) &xdr_guestfs_vfs_type_ret, (char *) &ret);
  free (r);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_vfs_type_args, (char *) &args);
done_no_free:
  return;
}

static void
truncate_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_truncate_args args;
  const char *path;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_truncate_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  path = args.path;
  ABS_PATH (path, , goto done);

  NEED_ROOT (, goto done);
  r = do_truncate (path);
  if (r == -1)
    /* do_truncate has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_truncate_args, (char *) &args);
done_no_free:
  return;
}

static void
truncate_size_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_truncate_size_args args;
  const char *path;
  int64_t size;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_truncate_size_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  path = args.path;
  ABS_PATH (path, , goto done);
  size = args.size;

  NEED_ROOT (, goto done);
  r = do_truncate_size (path, size);
  if (r == -1)
    /* do_truncate_size has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_truncate_size_args, (char *) &args);
done_no_free:
  return;
}

static void
utimens_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_utimens_args args;
  const char *path;
  int64_t atsecs;
  int64_t atnsecs;
  int64_t mtsecs;
  int64_t mtnsecs;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_utimens_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  path = args.path;
  ABS_PATH (path, , goto done);
  atsecs = args.atsecs;
  atnsecs = args.atnsecs;
  mtsecs = args.mtsecs;
  mtnsecs = args.mtnsecs;

  NEED_ROOT (, goto done);
  r = do_utimens (path, atsecs, atnsecs, mtsecs, mtnsecs);
  if (r == -1)
    /* do_utimens has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_utimens_args, (char *) &args);
done_no_free:
  return;
}

static void
mkdir_mode_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_mkdir_mode_args args;
  const char *path;
  int mode;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_mkdir_mode_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  path = args.path;
  ABS_PATH (path, , goto done);
  mode = args.mode;

  NEED_ROOT (, goto done);
  r = do_mkdir_mode (path, mode);
  if (r == -1)
    /* do_mkdir_mode has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_mkdir_mode_args, (char *) &args);
done_no_free:
  return;
}

static void
lchown_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_lchown_args args;
  int owner;
  int group;
  const char *path;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_lchown_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  owner = args.owner;
  group = args.group;
  path = args.path;
  ABS_PATH (path, , goto done);

  NEED_ROOT (, goto done);
  r = do_lchown (owner, group, path);
  if (r == -1)
    /* do_lchown has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_lchown_args, (char *) &args);
done_no_free:
  return;
}

static void
internal_lxattrlist_stub (XDR *xdr_in)
{
  guestfs_int_xattr_list *r;
  struct guestfs_internal_lxattrlist_args args;
  const char *path;
  char **names;

  /* The caller should have checked before calling this. */
  if (! optgroup_linuxxattrs_available ()) {
    reply_with_unavailable_feature ("linuxxattrs");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_internal_lxattrlist_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  path = args.path;
  ABS_PATH (path, , goto done);
  /* Ugly, but safe and avoids copying the strings. */
  names = realloc (args.names.names_val,
                sizeof (char *) * (args.names.names_len+1));
  if (names == NULL) {
    reply_with_perror ("realloc");
    goto done;
  }
  names[args.names.names_len] = NULL;
  args.names.names_val = names;

  NEED_ROOT (, goto done);
  r = do_internal_lxattrlist (path, names);
  if (r == NULL)
    /* do_internal_lxattrlist has already called reply_with_error */
    goto done;

  struct guestfs_internal_lxattrlist_ret ret;
  ret.xattrs = *r;
  free (r);
  reply ((xdrproc_t) xdr_guestfs_internal_lxattrlist_ret, (char *) &ret);
  xdr_free ((xdrproc_t) xdr_guestfs_internal_lxattrlist_ret, (char *) &ret);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_internal_lxattrlist_args, (char *) &args);
done_no_free:
  return;
}

static void
internal_readlinklist_stub (XDR *xdr_in)
{
  char **r;
  struct guestfs_internal_readlinklist_args args;
  const char *path;
  char **names;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_internal_readlinklist_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  path = args.path;
  ABS_PATH (path, , goto done);
  /* Ugly, but safe and avoids copying the strings. */
  names = realloc (args.names.names_val,
                sizeof (char *) * (args.names.names_len+1));
  if (names == NULL) {
    reply_with_perror ("realloc");
    goto done;
  }
  names[args.names.names_len] = NULL;
  args.names.names_val = names;

  NEED_ROOT (, goto done);
  r = do_internal_readlinklist (path, names);
  if (r == NULL)
    /* do_internal_readlinklist has already called reply_with_error */
    goto done;

  struct guestfs_internal_readlinklist_ret ret;
  ret.links.links_len = count_strings (r);
  ret.links.links_val = r;
  reply ((xdrproc_t) &xdr_guestfs_internal_readlinklist_ret, (char *) &ret);
  free_strings (r);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_internal_readlinklist_args, (char *) &args);
done_no_free:
  return;
}

static void
pread_stub (XDR *xdr_in)
{
  size_t size = 1;
  char *r;
  struct guestfs_pread_args args;
  const char *path;
  int count;
  int64_t offset;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_pread_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  path = args.path;
  ABS_PATH (path, , goto done);
  count = args.count;
  offset = args.offset;

  NEED_ROOT (, goto done);
  r = do_pread (path, count, offset, &size);
  /* size == 0 && r == NULL could be a non-error case (just
   * an ordinary zero-length buffer), so be careful ...
   */
  if (size == 1 && r == NULL)
    /* do_pread has already called reply_with_error */
    goto done;

  struct guestfs_pread_ret ret;
  ret.content.content_val = r;
  ret.content.content_len = size;
  reply ((xdrproc_t) &xdr_guestfs_pread_ret, (char *) &ret);
  free (r);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_pread_args, (char *) &args);
done_no_free:
  return;
}

static void
part_init_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_part_init_args args;
  CLEANUP_FREE char *device = NULL;
  const char *parttype;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_part_init_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args.device, device, , goto done);
  parttype = args.parttype;

  r = do_part_init (device, parttype);
  if (r == -1)
    /* do_part_init has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_part_init_args, (char *) &args);
done_no_free:
  return;
}

static void
part_add_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_part_add_args args;
  CLEANUP_FREE char *device = NULL;
  const char *prlogex;
  int64_t startsect;
  int64_t endsect;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_part_add_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args.device, device, , goto done);
  prlogex = args.prlogex;
  startsect = args.startsect;
  endsect = args.endsect;

  r = do_part_add (device, prlogex, startsect, endsect);
  if (r == -1)
    /* do_part_add has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_part_add_args, (char *) &args);
done_no_free:
  return;
}

static void
part_disk_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_part_disk_args args;
  CLEANUP_FREE char *device = NULL;
  const char *parttype;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_part_disk_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args.device, device, , goto done);
  parttype = args.parttype;

  r = do_part_disk (device, parttype);
  if (r == -1)
    /* do_part_disk has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_part_disk_args, (char *) &args);
done_no_free:
  return;
}

static void
part_set_bootable_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_part_set_bootable_args args;
  CLEANUP_FREE char *device = NULL;
  int partnum;
  int bootable;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_part_set_bootable_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args.device, device, , goto done);
  partnum = args.partnum;
  bootable = args.bootable;

  r = do_part_set_bootable (device, partnum, bootable);
  if (r == -1)
    /* do_part_set_bootable has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_part_set_bootable_args, (char *) &args);
done_no_free:
  return;
}

static void
part_set_name_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_part_set_name_args args;
  CLEANUP_FREE char *device = NULL;
  int partnum;
  const char *name;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_part_set_name_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args.device, device, , goto done);
  partnum = args.partnum;
  name = args.name;

  r = do_part_set_name (device, partnum, name);
  if (r == -1)
    /* do_part_set_name has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_part_set_name_args, (char *) &args);
done_no_free:
  return;
}

static void
part_list_stub (XDR *xdr_in)
{
  guestfs_int_partition_list *r;
  struct guestfs_part_list_args args;
  CLEANUP_FREE char *device = NULL;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_part_list_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args.device, device, , goto done);

  r = do_part_list (device);
  if (r == NULL)
    /* do_part_list has already called reply_with_error */
    goto done;

  struct guestfs_part_list_ret ret;
  ret.partitions = *r;
  free (r);
  reply ((xdrproc_t) xdr_guestfs_part_list_ret, (char *) &ret);
  xdr_free ((xdrproc_t) xdr_guestfs_part_list_ret, (char *) &ret);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_part_list_args, (char *) &args);
done_no_free:
  return;
}

static void
part_get_parttype_stub (XDR *xdr_in)
{
  char *r;
  struct guestfs_part_get_parttype_args args;
  CLEANUP_FREE char *device = NULL;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_part_get_parttype_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args.device, device, , goto done);

  r = do_part_get_parttype (device);
  if (r == NULL)
    /* do_part_get_parttype has already called reply_with_error */
    goto done;

  struct guestfs_part_get_parttype_ret ret;
  ret.parttype = r;
  reply ((xdrproc_t) &xdr_guestfs_part_get_parttype_ret, (char *) &ret);
  free (r);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_part_get_parttype_args, (char *) &args);
done_no_free:
  return;
}

static void
fill_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_fill_args args;
  int c;
  int len;
  const char *path;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_fill_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  c = args.c;
  len = args.len;
  path = args.path;
  ABS_PATH (path, , goto done);

  NEED_ROOT (, goto done);
  r = do_fill (c, len, path);
  if (r == -1)
    /* do_fill has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_fill_args, (char *) &args);
done_no_free:
  return;
}

static void
available_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_available_args args;
  char **groups;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_available_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  /* Ugly, but safe and avoids copying the strings. */
  groups = realloc (args.groups.groups_val,
                sizeof (char *) * (args.groups.groups_len+1));
  if (groups == NULL) {
    reply_with_perror ("realloc");
    goto done;
  }
  groups[args.groups.groups_len] = NULL;
  args.groups.groups_val = groups;

  r = do_available (groups);
  if (r == -1)
    /* do_available has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_available_args, (char *) &args);
done_no_free:
  return;
}

static void
dd_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_dd_args args;
  CLEANUP_FREE char *src = NULL;
  CLEANUP_FREE char *dest = NULL;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_dd_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  REQUIRE_ROOT_OR_RESOLVE_DEVICE (args.src, src, , goto done);
  REQUIRE_ROOT_OR_RESOLVE_DEVICE (args.dest, dest, , goto done);

  r = do_dd (src, dest);
  if (r == -1)
    /* do_dd has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_dd_args, (char *) &args);
done_no_free:
  return;
}

static void
filesize_stub (XDR *xdr_in)
{
  int64_t r;
  struct guestfs_filesize_args args;
  const char *file;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_filesize_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  file = args.file;
  ABS_PATH (file, , goto done);

  NEED_ROOT (, goto done);
  r = do_filesize (file);
  if (r == -1)
    /* do_filesize has already called reply_with_error */
    goto done;

  struct guestfs_filesize_ret ret;
  ret.size = r;
  reply ((xdrproc_t) &xdr_guestfs_filesize_ret, (char *) &ret);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_filesize_args, (char *) &args);
done_no_free:
  return;
}

static void
lvrename_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_lvrename_args args;
  const char *logvol;
  const char *newlogvol;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_lvrename_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  logvol = args.logvol;
  newlogvol = args.newlogvol;

  r = do_lvrename (logvol, newlogvol);
  if (r == -1)
    /* do_lvrename has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_lvrename_args, (char *) &args);
done_no_free:
  return;
}

static void
vgrename_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_vgrename_args args;
  const char *volgroup;
  const char *newvolgroup;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_vgrename_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  volgroup = args.volgroup;
  newvolgroup = args.newvolgroup;

  r = do_vgrename (volgroup, newvolgroup);
  if (r == -1)
    /* do_vgrename has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_vgrename_args, (char *) &args);
done_no_free:
  return;
}

static void
initrd_cat_stub (XDR *xdr_in)
{
  size_t size = 1;
  char *r;
  struct guestfs_initrd_cat_args args;
  const char *initrdpath;
  const char *filename;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_initrd_cat_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  initrdpath = args.initrdpath;
  ABS_PATH (initrdpath, , goto done);
  filename = args.filename;

  NEED_ROOT (, goto done);
  r = do_initrd_cat (initrdpath, filename, &size);
  /* size == 0 && r == NULL could be a non-error case (just
   * an ordinary zero-length buffer), so be careful ...
   */
  if (size == 1 && r == NULL)
    /* do_initrd_cat has already called reply_with_error */
    goto done;

  struct guestfs_initrd_cat_ret ret;
  ret.content.content_val = r;
  ret.content.content_len = size;
  reply ((xdrproc_t) &xdr_guestfs_initrd_cat_ret, (char *) &ret);
  free (r);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_initrd_cat_args, (char *) &args);
done_no_free:
  return;
}

static void
pvuuid_stub (XDR *xdr_in)
{
  char *r;
  struct guestfs_pvuuid_args args;
  CLEANUP_FREE char *device = NULL;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_pvuuid_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args.device, device, , goto done);

  r = do_pvuuid (device);
  if (r == NULL)
    /* do_pvuuid has already called reply_with_error */
    goto done;

  struct guestfs_pvuuid_ret ret;
  ret.uuid = r;
  reply ((xdrproc_t) &xdr_guestfs_pvuuid_ret, (char *) &ret);
  free (r);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_pvuuid_args, (char *) &args);
done_no_free:
  return;
}

static void
vguuid_stub (XDR *xdr_in)
{
  char *r;
  struct guestfs_vguuid_args args;
  const char *vgname;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_vguuid_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  vgname = args.vgname;

  r = do_vguuid (vgname);
  if (r == NULL)
    /* do_vguuid has already called reply_with_error */
    goto done;

  struct guestfs_vguuid_ret ret;
  ret.uuid = r;
  reply ((xdrproc_t) &xdr_guestfs_vguuid_ret, (char *) &ret);
  free (r);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_vguuid_args, (char *) &args);
done_no_free:
  return;
}

static void
lvuuid_stub (XDR *xdr_in)
{
  char *r;
  struct guestfs_lvuuid_args args;
  CLEANUP_FREE char *device = NULL;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_lvuuid_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args.device, device, , goto done);

  r = do_lvuuid (device);
  if (r == NULL)
    /* do_lvuuid has already called reply_with_error */
    goto done;

  struct guestfs_lvuuid_ret ret;
  ret.uuid = r;
  reply ((xdrproc_t) &xdr_guestfs_lvuuid_ret, (char *) &ret);
  free (r);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_lvuuid_args, (char *) &args);
done_no_free:
  return;
}

static void
vgpvuuids_stub (XDR *xdr_in)
{
  char **r;
  struct guestfs_vgpvuuids_args args;
  const char *vgname;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_vgpvuuids_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  vgname = args.vgname;

  r = do_vgpvuuids (vgname);
  if (r == NULL)
    /* do_vgpvuuids has already called reply_with_error */
    goto done;

  struct guestfs_vgpvuuids_ret ret;
  ret.uuids.uuids_len = count_strings (r);
  ret.uuids.uuids_val = r;
  reply ((xdrproc_t) &xdr_guestfs_vgpvuuids_ret, (char *) &ret);
  free_strings (r);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_vgpvuuids_args, (char *) &args);
done_no_free:
  return;
}

static void
vglvuuids_stub (XDR *xdr_in)
{
  char **r;
  struct guestfs_vglvuuids_args args;
  const char *vgname;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_vglvuuids_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  vgname = args.vgname;

  r = do_vglvuuids (vgname);
  if (r == NULL)
    /* do_vglvuuids has already called reply_with_error */
    goto done;

  struct guestfs_vglvuuids_ret ret;
  ret.uuids.uuids_len = count_strings (r);
  ret.uuids.uuids_val = r;
  reply ((xdrproc_t) &xdr_guestfs_vglvuuids_ret, (char *) &ret);
  free_strings (r);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_vglvuuids_args, (char *) &args);
done_no_free:
  return;
}

static void
copy_size_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_copy_size_args args;
  CLEANUP_FREE char *src = NULL;
  CLEANUP_FREE char *dest = NULL;
  int64_t size;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_copy_size_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  REQUIRE_ROOT_OR_RESOLVE_DEVICE (args.src, src, , goto done);
  REQUIRE_ROOT_OR_RESOLVE_DEVICE (args.dest, dest, , goto done);
  size = args.size;

  r = do_copy_size (src, dest, size);
  if (r == -1)
    /* do_copy_size has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_copy_size_args, (char *) &args);
done_no_free:
  return;
}

static void
zero_device_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_zero_device_args args;
  CLEANUP_FREE char *device = NULL;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_zero_device_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args.device, device, , goto done);

  r = do_zero_device (device);
  if (r == -1)
    /* do_zero_device has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_zero_device_args, (char *) &args);
done_no_free:
  return;
}

static void
txz_in_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_txz_in_args args;
  const char *directory;

  /* The caller should have checked before calling this. */
  if (! optgroup_xz_available ()) {
    cancel_receive ();
    reply_with_unavailable_feature ("xz");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    cancel_receive ();
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_txz_in_args (xdr_in, &args)) {
    cancel_receive ();
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  directory = args.directory;
  ABS_PATH (directory, cancel_receive (), goto done);

  NEED_ROOT (cancel_receive (), goto done);
  r = do_txz_in (directory);
  if (r == -1)
    /* do_txz_in has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_txz_in_args, (char *) &args);
done_no_free:
  return;
}

static void
txz_out_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_txz_out_args args;
  const char *directory;

  /* The caller should have checked before calling this. */
  if (! optgroup_xz_available ()) {
    reply_with_unavailable_feature ("xz");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_txz_out_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  directory = args.directory;
  ABS_PATH (directory, , goto done);

  NEED_ROOT (, goto done);
  r = do_txz_out (directory);
  if (r == -1)
    /* do_txz_out has already called reply_with_error */
    goto done;

  /* do_txz_out has already sent a reply */
done:
  xdr_free ((xdrproc_t) xdr_guestfs_txz_out_args, (char *) &args);
done_no_free:
  return;
}

static void
vgscan_stub (XDR *xdr_in)
{
  int r;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  r = do_vgscan ();
  if (r == -1)
    /* do_vgscan has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
done_no_free:
  return;
}

static void
part_del_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_part_del_args args;
  CLEANUP_FREE char *device = NULL;
  int partnum;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_part_del_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args.device, device, , goto done);
  partnum = args.partnum;

  r = do_part_del (device, partnum);
  if (r == -1)
    /* do_part_del has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_part_del_args, (char *) &args);
done_no_free:
  return;
}

static void
part_get_bootable_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_part_get_bootable_args args;
  CLEANUP_FREE char *device = NULL;
  int partnum;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_part_get_bootable_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args.device, device, , goto done);
  partnum = args.partnum;

  r = do_part_get_bootable (device, partnum);
  if (r == -1)
    /* do_part_get_bootable has already called reply_with_error */
    goto done;

  struct guestfs_part_get_bootable_ret ret;
  ret.bootable = r;
  reply ((xdrproc_t) &xdr_guestfs_part_get_bootable_ret, (char *) &ret);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_part_get_bootable_args, (char *) &args);
done_no_free:
  return;
}

static void
part_get_mbr_id_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_part_get_mbr_id_args args;
  CLEANUP_FREE char *device = NULL;
  int partnum;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_part_get_mbr_id_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args.device, device, , goto done);
  partnum = args.partnum;

  r = do_part_get_mbr_id (device, partnum);
  if (r == -1)
    /* do_part_get_mbr_id has already called reply_with_error */
    goto done;

  struct guestfs_part_get_mbr_id_ret ret;
  ret.idbyte = r;
  reply ((xdrproc_t) &xdr_guestfs_part_get_mbr_id_ret, (char *) &ret);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_part_get_mbr_id_args, (char *) &args);
done_no_free:
  return;
}

static void
part_set_mbr_id_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_part_set_mbr_id_args args;
  CLEANUP_FREE char *device = NULL;
  int partnum;
  int idbyte;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_part_set_mbr_id_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args.device, device, , goto done);
  partnum = args.partnum;
  idbyte = args.idbyte;

  r = do_part_set_mbr_id (device, partnum, idbyte);
  if (r == -1)
    /* do_part_set_mbr_id has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_part_set_mbr_id_args, (char *) &args);
done_no_free:
  return;
}

static void
checksum_device_stub (XDR *xdr_in)
{
  char *r;
  struct guestfs_checksum_device_args args;
  const char *csumtype;
  CLEANUP_FREE char *device = NULL;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_checksum_device_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  csumtype = args.csumtype;
  RESOLVE_DEVICE (args.device, device, , goto done);

  r = do_checksum_device (csumtype, device);
  if (r == NULL)
    /* do_checksum_device has already called reply_with_error */
    goto done;

  struct guestfs_checksum_device_ret ret;
  ret.checksum = r;
  reply ((xdrproc_t) &xdr_guestfs_checksum_device_ret, (char *) &ret);
  free (r);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_checksum_device_args, (char *) &args);
done_no_free:
  return;
}

static void
lvresize_free_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_lvresize_free_args args;
  CLEANUP_FREE char *lv = NULL;
  int percent;

  /* The caller should have checked before calling this. */
  if (! optgroup_lvm2_available ()) {
    reply_with_unavailable_feature ("lvm2");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_lvresize_free_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args.lv, lv, , goto done);
  percent = args.percent;

  r = do_lvresize_free (lv, percent);
  if (r == -1)
    /* do_lvresize_free has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_lvresize_free_args, (char *) &args);
done_no_free:
  return;
}

static void
aug_clear_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_aug_clear_args args;
  const char *augpath;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_aug_clear_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  augpath = args.augpath;

  r = do_aug_clear (augpath);
  if (r == -1)
    /* do_aug_clear has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_aug_clear_args, (char *) &args);
done_no_free:
  return;
}

static void
get_umask_stub (XDR *xdr_in)
{
  int r;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  r = do_get_umask ();
  if (r == -1)
    /* do_get_umask has already called reply_with_error */
    goto done;

  struct guestfs_get_umask_ret ret;
  ret.mask = r;
  reply ((xdrproc_t) &xdr_guestfs_get_umask_ret, (char *) &ret);
done:
done_no_free:
  return;
}

static void
debug_upload_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_debug_upload_args args;
  const char *tmpname;
  int mode;

  if (optargs_bitmask != 0) {
    cancel_receive ();
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_debug_upload_args (xdr_in, &args)) {
    cancel_receive ();
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  tmpname = args.tmpname;
  mode = args.mode;

  r = do_debug_upload (tmpname, mode);
  if (r == -1)
    /* do_debug_upload has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_debug_upload_args, (char *) &args);
done_no_free:
  return;
}

static void
base64_in_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_base64_in_args args;
  const char *filename;

  if (optargs_bitmask != 0) {
    cancel_receive ();
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_base64_in_args (xdr_in, &args)) {
    cancel_receive ();
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  filename = args.filename;
  ABS_PATH (filename, cancel_receive (), goto done);

  NEED_ROOT (cancel_receive (), goto done);
  r = do_base64_in (filename);
  if (r == -1)
    /* do_base64_in has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_base64_in_args, (char *) &args);
done_no_free:
  return;
}

static void
base64_out_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_base64_out_args args;
  const char *filename;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_base64_out_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  filename = args.filename;
  ABS_PATH (filename, , goto done);

  NEED_ROOT (, goto done);
  r = do_base64_out (filename);
  if (r == -1)
    /* do_base64_out has already called reply_with_error */
    goto done;

  /* do_base64_out has already sent a reply */
done:
  xdr_free ((xdrproc_t) xdr_guestfs_base64_out_args, (char *) &args);
done_no_free:
  return;
}

static void
checksums_out_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_checksums_out_args args;
  const char *csumtype;
  const char *directory;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_checksums_out_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  csumtype = args.csumtype;
  directory = args.directory;
  ABS_PATH (directory, , goto done);

  NEED_ROOT (, goto done);
  r = do_checksums_out (csumtype, directory);
  if (r == -1)
    /* do_checksums_out has already called reply_with_error */
    goto done;

  /* do_checksums_out has already sent a reply */
done:
  xdr_free ((xdrproc_t) xdr_guestfs_checksums_out_args, (char *) &args);
done_no_free:
  return;
}

static void
fill_pattern_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_fill_pattern_args args;
  const char *pattern;
  int len;
  const char *path;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_fill_pattern_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  pattern = args.pattern;
  len = args.len;
  path = args.path;
  ABS_PATH (path, , goto done);

  NEED_ROOT (, goto done);
  r = do_fill_pattern (pattern, len, path);
  if (r == -1)
    /* do_fill_pattern has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_fill_pattern_args, (char *) &args);
done_no_free:
  return;
}

static void
internal_write_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_internal_write_args args;
  const char *path;
  const char *content;
  size_t content_size;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_internal_write_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  path = args.path;
  ABS_PATH (path, , goto done);
  content = args.content.content_val;
  content_size = args.content.content_len;

  NEED_ROOT (, goto done);
  r = do_internal_write (path, content, content_size);
  if (r == -1)
    /* do_internal_write has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_internal_write_args, (char *) &args);
done_no_free:
  return;
}

static void
pwrite_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_pwrite_args args;
  const char *path;
  const char *content;
  size_t content_size;
  int64_t offset;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_pwrite_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  path = args.path;
  ABS_PATH (path, , goto done);
  content = args.content.content_val;
  content_size = args.content.content_len;
  offset = args.offset;

  NEED_ROOT (, goto done);
  r = do_pwrite (path, content, content_size, offset);
  if (r == -1)
    /* do_pwrite has already called reply_with_error */
    goto done;

  struct guestfs_pwrite_ret ret;
  ret.nbytes = r;
  reply ((xdrproc_t) &xdr_guestfs_pwrite_ret, (char *) &ret);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_pwrite_args, (char *) &args);
done_no_free:
  return;
}

static void
resize2fs_size_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_resize2fs_size_args args;
  CLEANUP_FREE char *device = NULL;
  int64_t size;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_resize2fs_size_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args.device, device, , goto done);
  size = args.size;

  r = do_resize2fs_size (device, size);
  if (r == -1)
    /* do_resize2fs_size has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_resize2fs_size_args, (char *) &args);
done_no_free:
  return;
}

static void
pvresize_size_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_pvresize_size_args args;
  CLEANUP_FREE char *device = NULL;
  int64_t size;

  /* The caller should have checked before calling this. */
  if (! optgroup_lvm2_available ()) {
    reply_with_unavailable_feature ("lvm2");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_pvresize_size_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args.device, device, , goto done);
  size = args.size;

  r = do_pvresize_size (device, size);
  if (r == -1)
    /* do_pvresize_size has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_pvresize_size_args, (char *) &args);
done_no_free:
  return;
}

static void
ntfsresize_size_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_ntfsresize_size_args args;
  CLEANUP_FREE char *device = NULL;
  int64_t size;

  /* The caller should have checked before calling this. */
  if (! optgroup_ntfsprogs_available ()) {
    reply_with_unavailable_feature ("ntfsprogs");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_ntfsresize_size_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args.device, device, , goto done);
  size = args.size;

  r = do_ntfsresize_size (device, size);
  if (r == -1)
    /* do_ntfsresize_size has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_ntfsresize_size_args, (char *) &args);
done_no_free:
  return;
}

static void
available_all_groups_stub (XDR *xdr_in)
{
  char **r;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  r = do_available_all_groups ();
  if (r == NULL)
    /* do_available_all_groups has already called reply_with_error */
    goto done;

  struct guestfs_available_all_groups_ret ret;
  ret.groups.groups_len = count_strings (r);
  ret.groups.groups_val = r;
  reply ((xdrproc_t) &xdr_guestfs_available_all_groups_ret, (char *) &ret);
  free_strings (r);
done:
done_no_free:
  return;
}

static void
fallocate64_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_fallocate64_args args;
  const char *path;
  int64_t len;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_fallocate64_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  path = args.path;
  ABS_PATH (path, , goto done);
  len = args.len;

  NEED_ROOT (, goto done);
  r = do_fallocate64 (path, len);
  if (r == -1)
    /* do_fallocate64 has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_fallocate64_args, (char *) &args);
done_no_free:
  return;
}

static void
vfs_label_stub (XDR *xdr_in)
{
  char *r;
  struct guestfs_vfs_label_args args;
  CLEANUP_FREE_MOUNTABLE mountable_t mountable
      = { .device = NULL, .volume = NULL };

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_vfs_label_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_MOUNTABLE (args.mountable, mountable, , goto done);

  r = do_vfs_label (&mountable);
  if (r == NULL)
    /* do_vfs_label has already called reply_with_error */
    goto done;

  struct guestfs_vfs_label_ret ret;
  ret.label = r;
  reply ((xdrproc_t) &xdr_guestfs_vfs_label_ret, (char *) &ret);
  free (r);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_vfs_label_args, (char *) &args);
done_no_free:
  return;
}

static void
vfs_uuid_stub (XDR *xdr_in)
{
  char *r;
  struct guestfs_vfs_uuid_args args;
  CLEANUP_FREE_MOUNTABLE mountable_t mountable
      = { .device = NULL, .volume = NULL };

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_vfs_uuid_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_MOUNTABLE (args.mountable, mountable, , goto done);

  r = do_vfs_uuid (&mountable);
  if (r == NULL)
    /* do_vfs_uuid has already called reply_with_error */
    goto done;

  struct guestfs_vfs_uuid_ret ret;
  ret.uuid = r;
  reply ((xdrproc_t) &xdr_guestfs_vfs_uuid_ret, (char *) &ret);
  free (r);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_vfs_uuid_args, (char *) &args);
done_no_free:
  return;
}

static void
lvm_set_filter_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_lvm_set_filter_args args;
  CLEANUP_FREE_STRING_LIST char **devices = NULL;

  /* The caller should have checked before calling this. */
  if (! optgroup_lvm2_available ()) {
    reply_with_unavailable_feature ("lvm2");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_lvm_set_filter_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  /* Copy the string list and apply device name translation
   * to each one.
   */
  devices = calloc (args.devices.devices_len+1, sizeof (char *));
  {
    size_t i;
    for (i = 0; i < args.devices.devices_len; ++i)
      RESOLVE_DEVICE (args.devices.devices_val[i], devices[i],
                      , goto done);
    devices[i] = NULL;
  }

  r = do_lvm_set_filter (devices);
  if (r == -1)
    /* do_lvm_set_filter has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_lvm_set_filter_args, (char *) &args);
done_no_free:
  return;
}

static void
lvm_clear_filter_stub (XDR *xdr_in)
{
  int r;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  r = do_lvm_clear_filter ();
  if (r == -1)
    /* do_lvm_clear_filter has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
done_no_free:
  return;
}

static void
luks_open_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_luks_open_args args;
  CLEANUP_FREE char *device = NULL;
  const char *key;
  const char *mapname;

  /* The caller should have checked before calling this. */
  if (! optgroup_luks_available ()) {
    reply_with_unavailable_feature ("luks");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_luks_open_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args.device, device, , goto done);
  key = args.key;
  mapname = args.mapname;

  r = do_luks_open (device, key, mapname);
  if (r == -1)
    /* do_luks_open has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_luks_open_args, (char *) &args);
done_no_free:
  return;
}

static void
luks_open_ro_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_luks_open_ro_args args;
  CLEANUP_FREE char *device = NULL;
  const char *key;
  const char *mapname;

  /* The caller should have checked before calling this. */
  if (! optgroup_luks_available ()) {
    reply_with_unavailable_feature ("luks");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_luks_open_ro_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args.device, device, , goto done);
  key = args.key;
  mapname = args.mapname;

  r = do_luks_open_ro (device, key, mapname);
  if (r == -1)
    /* do_luks_open_ro has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_luks_open_ro_args, (char *) &args);
done_no_free:
  return;
}

static void
luks_close_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_luks_close_args args;
  CLEANUP_FREE char *device = NULL;

  /* The caller should have checked before calling this. */
  if (! optgroup_luks_available ()) {
    reply_with_unavailable_feature ("luks");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_luks_close_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args.device, device, , goto done);

  r = do_luks_close (device);
  if (r == -1)
    /* do_luks_close has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_luks_close_args, (char *) &args);
done_no_free:
  return;
}

static void
luks_format_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_luks_format_args args;
  CLEANUP_FREE char *device = NULL;
  const char *key;
  int keyslot;

  /* The caller should have checked before calling this. */
  if (! optgroup_luks_available ()) {
    reply_with_unavailable_feature ("luks");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_luks_format_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args.device, device, , goto done);
  key = args.key;
  keyslot = args.keyslot;

  r = do_luks_format (device, key, keyslot);
  if (r == -1)
    /* do_luks_format has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_luks_format_args, (char *) &args);
done_no_free:
  return;
}

static void
luks_format_cipher_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_luks_format_cipher_args args;
  CLEANUP_FREE char *device = NULL;
  const char *key;
  int keyslot;
  const char *cipher;

  /* The caller should have checked before calling this. */
  if (! optgroup_luks_available ()) {
    reply_with_unavailable_feature ("luks");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_luks_format_cipher_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args.device, device, , goto done);
  key = args.key;
  keyslot = args.keyslot;
  cipher = args.cipher;

  r = do_luks_format_cipher (device, key, keyslot, cipher);
  if (r == -1)
    /* do_luks_format_cipher has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_luks_format_cipher_args, (char *) &args);
done_no_free:
  return;
}

static void
luks_add_key_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_luks_add_key_args args;
  CLEANUP_FREE char *device = NULL;
  const char *key;
  const char *newkey;
  int keyslot;

  /* The caller should have checked before calling this. */
  if (! optgroup_luks_available ()) {
    reply_with_unavailable_feature ("luks");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_luks_add_key_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args.device, device, , goto done);
  key = args.key;
  newkey = args.newkey;
  keyslot = args.keyslot;

  r = do_luks_add_key (device, key, newkey, keyslot);
  if (r == -1)
    /* do_luks_add_key has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_luks_add_key_args, (char *) &args);
done_no_free:
  return;
}

static void
luks_kill_slot_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_luks_kill_slot_args args;
  CLEANUP_FREE char *device = NULL;
  const char *key;
  int keyslot;

  /* The caller should have checked before calling this. */
  if (! optgroup_luks_available ()) {
    reply_with_unavailable_feature ("luks");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_luks_kill_slot_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args.device, device, , goto done);
  key = args.key;
  keyslot = args.keyslot;

  r = do_luks_kill_slot (device, key, keyslot);
  if (r == -1)
    /* do_luks_kill_slot has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_luks_kill_slot_args, (char *) &args);
done_no_free:
  return;
}

static void
is_lv_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_is_lv_args args;
  CLEANUP_FREE char *device = NULL;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_is_lv_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args.device, device, , goto done);

  r = do_is_lv (device);
  if (r == -1)
    /* do_is_lv has already called reply_with_error */
    goto done;

  struct guestfs_is_lv_ret ret;
  ret.lvflag = r;
  reply ((xdrproc_t) &xdr_guestfs_is_lv_ret, (char *) &ret);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_is_lv_args, (char *) &args);
done_no_free:
  return;
}

static void
findfs_uuid_stub (XDR *xdr_in)
{
  char *r;
  struct guestfs_findfs_uuid_args args;
  const char *uuid;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_findfs_uuid_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  uuid = args.uuid;

  r = do_findfs_uuid (uuid);
  if (r == NULL)
    /* do_findfs_uuid has already called reply_with_error */
    goto done;

  struct guestfs_findfs_uuid_ret ret;
  ret.device = r;
  reply ((xdrproc_t) &xdr_guestfs_findfs_uuid_ret, (char *) &ret);
  free (r);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_findfs_uuid_args, (char *) &args);
done_no_free:
  return;
}

static void
findfs_label_stub (XDR *xdr_in)
{
  char *r;
  struct guestfs_findfs_label_args args;
  const char *label;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_findfs_label_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  label = args.label;

  r = do_findfs_label (label);
  if (r == NULL)
    /* do_findfs_label has already called reply_with_error */
    goto done;

  struct guestfs_findfs_label_ret ret;
  ret.device = r;
  reply ((xdrproc_t) &xdr_guestfs_findfs_label_ret, (char *) &ret);
  free (r);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_findfs_label_args, (char *) &args);
done_no_free:
  return;
}

static void
is_chardev_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_is_chardev_args args;
  const char *path;
  int followsymlinks;

  if (optargs_bitmask & UINT64_C(0xfffffffffffffffe)) {
    reply_with_error ("unknown option in optional arguments bitmask (this can happen if a program is compiled against a newer version of libguestfs, then run against an older version of the daemon)");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_is_chardev_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  path = args.path;
  ABS_PATH (path, , goto done);
  followsymlinks = args.followsymlinks;

  NEED_ROOT (, goto done);
  r = do_is_chardev (path, followsymlinks);
  if (r == -1)
    /* do_is_chardev has already called reply_with_error */
    goto done;

  struct guestfs_is_chardev_ret ret;
  ret.flag = r;
  reply ((xdrproc_t) &xdr_guestfs_is_chardev_ret, (char *) &ret);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_is_chardev_args, (char *) &args);
done_no_free:
  return;
}

static void
is_blockdev_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_is_blockdev_args args;
  const char *path;
  int followsymlinks;

  if (optargs_bitmask & UINT64_C(0xfffffffffffffffe)) {
    reply_with_error ("unknown option in optional arguments bitmask (this can happen if a program is compiled against a newer version of libguestfs, then run against an older version of the daemon)");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_is_blockdev_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  path = args.path;
  ABS_PATH (path, , goto done);
  followsymlinks = args.followsymlinks;

  NEED_ROOT (, goto done);
  r = do_is_blockdev (path, followsymlinks);
  if (r == -1)
    /* do_is_blockdev has already called reply_with_error */
    goto done;

  struct guestfs_is_blockdev_ret ret;
  ret.flag = r;
  reply ((xdrproc_t) &xdr_guestfs_is_blockdev_ret, (char *) &ret);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_is_blockdev_args, (char *) &args);
done_no_free:
  return;
}

static void
is_fifo_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_is_fifo_args args;
  const char *path;
  int followsymlinks;

  if (optargs_bitmask & UINT64_C(0xfffffffffffffffe)) {
    reply_with_error ("unknown option in optional arguments bitmask (this can happen if a program is compiled against a newer version of libguestfs, then run against an older version of the daemon)");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_is_fifo_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  path = args.path;
  ABS_PATH (path, , goto done);
  followsymlinks = args.followsymlinks;

  NEED_ROOT (, goto done);
  r = do_is_fifo (path, followsymlinks);
  if (r == -1)
    /* do_is_fifo has already called reply_with_error */
    goto done;

  struct guestfs_is_fifo_ret ret;
  ret.flag = r;
  reply ((xdrproc_t) &xdr_guestfs_is_fifo_ret, (char *) &ret);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_is_fifo_args, (char *) &args);
done_no_free:
  return;
}

static void
is_symlink_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_is_symlink_args args;
  const char *path;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_is_symlink_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  path = args.path;
  ABS_PATH (path, , goto done);

  NEED_ROOT (, goto done);
  r = do_is_symlink (path);
  if (r == -1)
    /* do_is_symlink has already called reply_with_error */
    goto done;

  struct guestfs_is_symlink_ret ret;
  ret.flag = r;
  reply ((xdrproc_t) &xdr_guestfs_is_symlink_ret, (char *) &ret);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_is_symlink_args, (char *) &args);
done_no_free:
  return;
}

static void
is_socket_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_is_socket_args args;
  const char *path;
  int followsymlinks;

  if (optargs_bitmask & UINT64_C(0xfffffffffffffffe)) {
    reply_with_error ("unknown option in optional arguments bitmask (this can happen if a program is compiled against a newer version of libguestfs, then run against an older version of the daemon)");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_is_socket_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  path = args.path;
  ABS_PATH (path, , goto done);
  followsymlinks = args.followsymlinks;

  NEED_ROOT (, goto done);
  r = do_is_socket (path, followsymlinks);
  if (r == -1)
    /* do_is_socket has already called reply_with_error */
    goto done;

  struct guestfs_is_socket_ret ret;
  ret.flag = r;
  reply ((xdrproc_t) &xdr_guestfs_is_socket_ret, (char *) &ret);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_is_socket_args, (char *) &args);
done_no_free:
  return;
}

static void
part_to_dev_stub (XDR *xdr_in)
{
  char *r;
  struct guestfs_part_to_dev_args args;
  CLEANUP_FREE char *partition = NULL;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_part_to_dev_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args.partition, partition, , goto done);

  r = do_part_to_dev (partition);
  if (r == NULL)
    /* do_part_to_dev has already called reply_with_error */
    goto done;

  struct guestfs_part_to_dev_ret ret;
  ret.device = r;
  reply ((xdrproc_t) &xdr_guestfs_part_to_dev_ret, (char *) &ret);
  free (r);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_part_to_dev_args, (char *) &args);
done_no_free:
  return;
}

static void
upload_offset_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_upload_offset_args args;
  CLEANUP_FREE char *remotefilename = NULL;
  int64_t offset;

  if (optargs_bitmask != 0) {
    cancel_receive ();
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_upload_offset_args (xdr_in, &args)) {
    cancel_receive ();
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  REQUIRE_ROOT_OR_RESOLVE_DEVICE (args.remotefilename, remotefilename, cancel_receive (), goto done);
  offset = args.offset;

  r = do_upload_offset (remotefilename, offset);
  if (r == -1)
    /* do_upload_offset has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_upload_offset_args, (char *) &args);
done_no_free:
  return;
}

static void
download_offset_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_download_offset_args args;
  CLEANUP_FREE char *remotefilename = NULL;
  int64_t offset;
  int64_t size;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_download_offset_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  REQUIRE_ROOT_OR_RESOLVE_DEVICE (args.remotefilename, remotefilename, , goto done);
  offset = args.offset;
  size = args.size;

  r = do_download_offset (remotefilename, offset, size);
  if (r == -1)
    /* do_download_offset has already called reply_with_error */
    goto done;

  /* do_download_offset has already sent a reply */
done:
  xdr_free ((xdrproc_t) xdr_guestfs_download_offset_args, (char *) &args);
done_no_free:
  return;
}

static void
pwrite_device_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_pwrite_device_args args;
  CLEANUP_FREE char *device = NULL;
  const char *content;
  size_t content_size;
  int64_t offset;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_pwrite_device_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args.device, device, , goto done);
  content = args.content.content_val;
  content_size = args.content.content_len;
  offset = args.offset;

  r = do_pwrite_device (device, content, content_size, offset);
  if (r == -1)
    /* do_pwrite_device has already called reply_with_error */
    goto done;

  struct guestfs_pwrite_device_ret ret;
  ret.nbytes = r;
  reply ((xdrproc_t) &xdr_guestfs_pwrite_device_ret, (char *) &ret);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_pwrite_device_args, (char *) &args);
done_no_free:
  return;
}

static void
pread_device_stub (XDR *xdr_in)
{
  size_t size = 1;
  char *r;
  struct guestfs_pread_device_args args;
  CLEANUP_FREE char *device = NULL;
  int count;
  int64_t offset;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_pread_device_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args.device, device, , goto done);
  count = args.count;
  offset = args.offset;

  r = do_pread_device (device, count, offset, &size);
  /* size == 0 && r == NULL could be a non-error case (just
   * an ordinary zero-length buffer), so be careful ...
   */
  if (size == 1 && r == NULL)
    /* do_pread_device has already called reply_with_error */
    goto done;

  struct guestfs_pread_device_ret ret;
  ret.content.content_val = r;
  ret.content.content_len = size;
  reply ((xdrproc_t) &xdr_guestfs_pread_device_ret, (char *) &ret);
  free (r);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_pread_device_args, (char *) &args);
done_no_free:
  return;
}

static void
lvm_canonical_lv_name_stub (XDR *xdr_in)
{
  char *r;
  struct guestfs_lvm_canonical_lv_name_args args;
  CLEANUP_FREE char *lvname = NULL;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_lvm_canonical_lv_name_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args.lvname, lvname, , goto done);

  r = do_lvm_canonical_lv_name (lvname);
  if (r == NULL)
    /* do_lvm_canonical_lv_name has already called reply_with_error */
    goto done;

  struct guestfs_lvm_canonical_lv_name_ret ret;
  ret.lv = r;
  reply ((xdrproc_t) &xdr_guestfs_lvm_canonical_lv_name_ret, (char *) &ret);
  free (r);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_lvm_canonical_lv_name_args, (char *) &args);
done_no_free:
  return;
}

static void
mkfs_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_mkfs_args args;
  const char *fstype;
  CLEANUP_FREE char *device = NULL;
  int blocksize;
  const char *features;
  int inode;
  int sectorsize;
  const char *label;

  if (optargs_bitmask & UINT64_C(0xffffffffffffffe0)) {
    reply_with_error ("unknown option in optional arguments bitmask (this can happen if a program is compiled against a newer version of libguestfs, then run against an older version of the daemon)");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_mkfs_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  fstype = args.fstype;
  RESOLVE_DEVICE (args.device, device, , goto done);
  blocksize = args.blocksize;
  features = args.features;
  inode = args.inode;
  sectorsize = args.sectorsize;
  label = args.label;

  r = do_mkfs (fstype, device, blocksize, features, inode, sectorsize, label);
  if (r == -1)
    /* do_mkfs has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_mkfs_args, (char *) &args);
done_no_free:
  return;
}

static void
getxattr_stub (XDR *xdr_in)
{
  size_t size = 1;
  char *r;
  struct guestfs_getxattr_args args;
  const char *path;
  const char *name;

  /* The caller should have checked before calling this. */
  if (! optgroup_linuxxattrs_available ()) {
    reply_with_unavailable_feature ("linuxxattrs");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_getxattr_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  path = args.path;
  ABS_PATH (path, , goto done);
  name = args.name;

  NEED_ROOT (, goto done);
  r = do_getxattr (path, name, &size);
  /* size == 0 && r == NULL could be a non-error case (just
   * an ordinary zero-length buffer), so be careful ...
   */
  if (size == 1 && r == NULL)
    /* do_getxattr has already called reply_with_error */
    goto done;

  struct guestfs_getxattr_ret ret;
  ret.xattr.xattr_val = r;
  ret.xattr.xattr_len = size;
  reply ((xdrproc_t) &xdr_guestfs_getxattr_ret, (char *) &ret);
  free (r);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_getxattr_args, (char *) &args);
done_no_free:
  return;
}

static void
lgetxattr_stub (XDR *xdr_in)
{
  size_t size = 1;
  char *r;
  struct guestfs_lgetxattr_args args;
  const char *path;
  const char *name;

  /* The caller should have checked before calling this. */
  if (! optgroup_linuxxattrs_available ()) {
    reply_with_unavailable_feature ("linuxxattrs");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_lgetxattr_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  path = args.path;
  ABS_PATH (path, , goto done);
  name = args.name;

  NEED_ROOT (, goto done);
  r = do_lgetxattr (path, name, &size);
  /* size == 0 && r == NULL could be a non-error case (just
   * an ordinary zero-length buffer), so be careful ...
   */
  if (size == 1 && r == NULL)
    /* do_lgetxattr has already called reply_with_error */
    goto done;

  struct guestfs_lgetxattr_ret ret;
  ret.xattr.xattr_val = r;
  ret.xattr.xattr_len = size;
  reply ((xdrproc_t) &xdr_guestfs_lgetxattr_ret, (char *) &ret);
  free (r);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_lgetxattr_args, (char *) &args);
done_no_free:
  return;
}

static void
resize2fs_M_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_resize2fs_M_args args;
  CLEANUP_FREE char *device = NULL;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_resize2fs_M_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args.device, device, , goto done);

  r = do_resize2fs_M (device);
  if (r == -1)
    /* do_resize2fs_M has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_resize2fs_M_args, (char *) &args);
done_no_free:
  return;
}

static void
internal_autosync_stub (XDR *xdr_in)
{
  int r;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  r = do_internal_autosync ();
  if (r == -1)
    /* do_internal_autosync has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
done_no_free:
  return;
}

static void
is_zero_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_is_zero_args args;
  const char *path;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_is_zero_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  path = args.path;
  ABS_PATH (path, , goto done);

  NEED_ROOT (, goto done);
  r = do_is_zero (path);
  if (r == -1)
    /* do_is_zero has already called reply_with_error */
    goto done;

  struct guestfs_is_zero_ret ret;
  ret.zeroflag = r;
  reply ((xdrproc_t) &xdr_guestfs_is_zero_ret, (char *) &ret);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_is_zero_args, (char *) &args);
done_no_free:
  return;
}

static void
is_zero_device_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_is_zero_device_args args;
  CLEANUP_FREE char *device = NULL;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_is_zero_device_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args.device, device, , goto done);

  r = do_is_zero_device (device);
  if (r == -1)
    /* do_is_zero_device has already called reply_with_error */
    goto done;

  struct guestfs_is_zero_device_ret ret;
  ret.zeroflag = r;
  reply ((xdrproc_t) &xdr_guestfs_is_zero_device_ret, (char *) &ret);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_is_zero_device_args, (char *) &args);
done_no_free:
  return;
}

static void
list_9p_stub (XDR *xdr_in)
{
  char **r;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  r = do_list_9p ();
  if (r == NULL)
    /* do_list_9p has already called reply_with_error */
    goto done;

  struct guestfs_list_9p_ret ret;
  ret.mounttags.mounttags_len = count_strings (r);
  ret.mounttags.mounttags_val = r;
  reply ((xdrproc_t) &xdr_guestfs_list_9p_ret, (char *) &ret);
  free_strings (r);
done:
done_no_free:
  return;
}

static void
mount_9p_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_mount_9p_args args;
  const char *mounttag;
  const char *mountpoint;
  const char *options;

  if (optargs_bitmask & UINT64_C(0xfffffffffffffffe)) {
    reply_with_error ("unknown option in optional arguments bitmask (this can happen if a program is compiled against a newer version of libguestfs, then run against an older version of the daemon)");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_mount_9p_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  mounttag = args.mounttag;
  mountpoint = args.mountpoint;
  options = args.options;

  r = do_mount_9p (mounttag, mountpoint, options);
  if (r == -1)
    /* do_mount_9p has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_mount_9p_args, (char *) &args);
done_no_free:
  return;
}

static void
list_dm_devices_stub (XDR *xdr_in)
{
  char **r;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  r = do_list_dm_devices ();
  if (r == NULL)
    /* do_list_dm_devices has already called reply_with_error */
    goto done;

  struct guestfs_list_dm_devices_ret ret;
  ret.devices.devices_len = count_strings (r);
  ret.devices.devices_val = r;
  reply ((xdrproc_t) &xdr_guestfs_list_dm_devices_ret, (char *) &ret);
  free_strings (r);
done:
done_no_free:
  return;
}

static void
ntfsresize_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_ntfsresize_args args;
  CLEANUP_FREE char *device = NULL;
  int64_t size;
  int force;

  /* The caller should have checked before calling this. */
  if (! optgroup_ntfsprogs_available ()) {
    reply_with_unavailable_feature ("ntfsprogs");
    goto done_no_free;
  }

  if (optargs_bitmask & UINT64_C(0xfffffffffffffffc)) {
    reply_with_error ("unknown option in optional arguments bitmask (this can happen if a program is compiled against a newer version of libguestfs, then run against an older version of the daemon)");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_ntfsresize_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args.device, device, , goto done);
  size = args.size;
  force = args.force;

  r = do_ntfsresize (device, size, force);
  if (r == -1)
    /* do_ntfsresize has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_ntfsresize_args, (char *) &args);
done_no_free:
  return;
}

static void
btrfs_filesystem_resize_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_btrfs_filesystem_resize_args args;
  const char *mountpoint;
  int64_t size;

  /* The caller should have checked before calling this. */
  if (! optgroup_btrfs_available ()) {
    reply_with_unavailable_feature ("btrfs");
    goto done_no_free;
  }

  if (optargs_bitmask & UINT64_C(0xfffffffffffffffe)) {
    reply_with_error ("unknown option in optional arguments bitmask (this can happen if a program is compiled against a newer version of libguestfs, then run against an older version of the daemon)");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_btrfs_filesystem_resize_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  mountpoint = args.mountpoint;
  ABS_PATH (mountpoint, , goto done);
  size = args.size;

  NEED_ROOT (, goto done);
  r = do_btrfs_filesystem_resize (mountpoint, size);
  if (r == -1)
    /* do_btrfs_filesystem_resize has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_btrfs_filesystem_resize_args, (char *) &args);
done_no_free:
  return;
}

static void
internal_write_append_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_internal_write_append_args args;
  const char *path;
  const char *content;
  size_t content_size;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_internal_write_append_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  path = args.path;
  ABS_PATH (path, , goto done);
  content = args.content.content_val;
  content_size = args.content.content_len;

  NEED_ROOT (, goto done);
  r = do_internal_write_append (path, content, content_size);
  if (r == -1)
    /* do_internal_write_append has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_internal_write_append_args, (char *) &args);
done_no_free:
  return;
}

static void
compress_out_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_compress_out_args args;
  const char *ctype;
  const char *file;
  int level;

  if (optargs_bitmask & UINT64_C(0xfffffffffffffffe)) {
    reply_with_error ("unknown option in optional arguments bitmask (this can happen if a program is compiled against a newer version of libguestfs, then run against an older version of the daemon)");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_compress_out_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  ctype = args.ctype;
  file = args.file;
  ABS_PATH (file, , goto done);
  level = args.level;

  NEED_ROOT (, goto done);
  r = do_compress_out (ctype, file, level);
  if (r == -1)
    /* do_compress_out has already called reply_with_error */
    goto done;

  /* do_compress_out has already sent a reply */
done:
  xdr_free ((xdrproc_t) xdr_guestfs_compress_out_args, (char *) &args);
done_no_free:
  return;
}

static void
compress_device_out_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_compress_device_out_args args;
  const char *ctype;
  CLEANUP_FREE char *device = NULL;
  int level;

  if (optargs_bitmask & UINT64_C(0xfffffffffffffffe)) {
    reply_with_error ("unknown option in optional arguments bitmask (this can happen if a program is compiled against a newer version of libguestfs, then run against an older version of the daemon)");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_compress_device_out_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  ctype = args.ctype;
  RESOLVE_DEVICE (args.device, device, , goto done);
  level = args.level;

  r = do_compress_device_out (ctype, device, level);
  if (r == -1)
    /* do_compress_device_out has already called reply_with_error */
    goto done;

  /* do_compress_device_out has already sent a reply */
done:
  xdr_free ((xdrproc_t) xdr_guestfs_compress_device_out_args, (char *) &args);
done_no_free:
  return;
}

static void
part_to_partnum_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_part_to_partnum_args args;
  CLEANUP_FREE char *partition = NULL;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_part_to_partnum_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args.partition, partition, , goto done);

  r = do_part_to_partnum (partition);
  if (r == -1)
    /* do_part_to_partnum has already called reply_with_error */
    goto done;

  struct guestfs_part_to_partnum_ret ret;
  ret.partnum = r;
  reply ((xdrproc_t) &xdr_guestfs_part_to_partnum_ret, (char *) &ret);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_part_to_partnum_args, (char *) &args);
done_no_free:
  return;
}

static void
copy_device_to_device_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_copy_device_to_device_args args;
  CLEANUP_FREE char *src = NULL;
  CLEANUP_FREE char *dest = NULL;
  int64_t srcoffset;
  int64_t destoffset;
  int64_t size;
  int sparse;
  int append;

  if (optargs_bitmask & UINT64_C(0xffffffffffffffe0)) {
    reply_with_error ("unknown option in optional arguments bitmask (this can happen if a program is compiled against a newer version of libguestfs, then run against an older version of the daemon)");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_copy_device_to_device_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args.src, src, , goto done);
  RESOLVE_DEVICE (args.dest, dest, , goto done);
  srcoffset = args.srcoffset;
  destoffset = args.destoffset;
  size = args.size;
  sparse = args.sparse;
  append = args.append;

  r = do_copy_device_to_device (src, dest, srcoffset, destoffset, size, sparse, append);
  if (r == -1)
    /* do_copy_device_to_device has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_copy_device_to_device_args, (char *) &args);
done_no_free:
  return;
}

static void
copy_device_to_file_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_copy_device_to_file_args args;
  CLEANUP_FREE char *src = NULL;
  const char *dest;
  int64_t srcoffset;
  int64_t destoffset;
  int64_t size;
  int sparse;
  int append;

  if (optargs_bitmask & UINT64_C(0xffffffffffffffe0)) {
    reply_with_error ("unknown option in optional arguments bitmask (this can happen if a program is compiled against a newer version of libguestfs, then run against an older version of the daemon)");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_copy_device_to_file_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args.src, src, , goto done);
  dest = args.dest;
  ABS_PATH (dest, , goto done);
  srcoffset = args.srcoffset;
  destoffset = args.destoffset;
  size = args.size;
  sparse = args.sparse;
  append = args.append;

  NEED_ROOT (, goto done);
  r = do_copy_device_to_file (src, dest, srcoffset, destoffset, size, sparse, append);
  if (r == -1)
    /* do_copy_device_to_file has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_copy_device_to_file_args, (char *) &args);
done_no_free:
  return;
}

static void
copy_file_to_device_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_copy_file_to_device_args args;
  const char *src;
  CLEANUP_FREE char *dest = NULL;
  int64_t srcoffset;
  int64_t destoffset;
  int64_t size;
  int sparse;
  int append;

  if (optargs_bitmask & UINT64_C(0xffffffffffffffe0)) {
    reply_with_error ("unknown option in optional arguments bitmask (this can happen if a program is compiled against a newer version of libguestfs, then run against an older version of the daemon)");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_copy_file_to_device_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  src = args.src;
  ABS_PATH (src, , goto done);
  RESOLVE_DEVICE (args.dest, dest, , goto done);
  srcoffset = args.srcoffset;
  destoffset = args.destoffset;
  size = args.size;
  sparse = args.sparse;
  append = args.append;

  NEED_ROOT (, goto done);
  r = do_copy_file_to_device (src, dest, srcoffset, destoffset, size, sparse, append);
  if (r == -1)
    /* do_copy_file_to_device has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_copy_file_to_device_args, (char *) &args);
done_no_free:
  return;
}

static void
copy_file_to_file_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_copy_file_to_file_args args;
  const char *src;
  const char *dest;
  int64_t srcoffset;
  int64_t destoffset;
  int64_t size;
  int sparse;
  int append;

  if (optargs_bitmask & UINT64_C(0xffffffffffffffe0)) {
    reply_with_error ("unknown option in optional arguments bitmask (this can happen if a program is compiled against a newer version of libguestfs, then run against an older version of the daemon)");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_copy_file_to_file_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  src = args.src;
  ABS_PATH (src, , goto done);
  dest = args.dest;
  ABS_PATH (dest, , goto done);
  srcoffset = args.srcoffset;
  destoffset = args.destoffset;
  size = args.size;
  sparse = args.sparse;
  append = args.append;

  NEED_ROOT (, goto done);
  r = do_copy_file_to_file (src, dest, srcoffset, destoffset, size, sparse, append);
  if (r == -1)
    /* do_copy_file_to_file has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_copy_file_to_file_args, (char *) &args);
done_no_free:
  return;
}

static void
tune2fs_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_tune2fs_args args;
  CLEANUP_FREE char *device = NULL;
  int force;
  int maxmountcount;
  int mountcount;
  const char *errorbehavior;
  int64_t group;
  int intervalbetweenchecks;
  int reservedblockspercentage;
  const char *lastmounteddirectory;
  int64_t reservedblockscount;
  int64_t user;

  if (optargs_bitmask & UINT64_C(0xfffffffffffffc00)) {
    reply_with_error ("unknown option in optional arguments bitmask (this can happen if a program is compiled against a newer version of libguestfs, then run against an older version of the daemon)");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_tune2fs_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args.device, device, , goto done);
  force = args.force;
  maxmountcount = args.maxmountcount;
  mountcount = args.mountcount;
  errorbehavior = args.errorbehavior;
  group = args.group;
  intervalbetweenchecks = args.intervalbetweenchecks;
  reservedblockspercentage = args.reservedblockspercentage;
  lastmounteddirectory = args.lastmounteddirectory;
  reservedblockscount = args.reservedblockscount;
  user = args.user;

  r = do_tune2fs (device, force, maxmountcount, mountcount, errorbehavior, group, intervalbetweenchecks, reservedblockspercentage, lastmounteddirectory, reservedblockscount, user);
  if (r == -1)
    /* do_tune2fs has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_tune2fs_args, (char *) &args);
done_no_free:
  return;
}

static void
md_create_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_md_create_args args;
  const char *name;
  CLEANUP_FREE_STRING_LIST char **devices = NULL;
  int64_t missingbitmap;
  int nrdevices;
  int spare;
  int64_t chunk;
  const char *level;

  /* The caller should have checked before calling this. */
  if (! optgroup_mdadm_available ()) {
    reply_with_unavailable_feature ("mdadm");
    goto done_no_free;
  }

  if (optargs_bitmask & UINT64_C(0xffffffffffffffe0)) {
    reply_with_error ("unknown option in optional arguments bitmask (this can happen if a program is compiled against a newer version of libguestfs, then run against an older version of the daemon)");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_md_create_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  name = args.name;
  /* Copy the string list and apply device name translation
   * to each one.
   */
  devices = calloc (args.devices.devices_len+1, sizeof (char *));
  {
    size_t i;
    for (i = 0; i < args.devices.devices_len; ++i)
      RESOLVE_DEVICE (args.devices.devices_val[i], devices[i],
                      , goto done);
    devices[i] = NULL;
  }
  missingbitmap = args.missingbitmap;
  nrdevices = args.nrdevices;
  spare = args.spare;
  chunk = args.chunk;
  level = args.level;

  r = do_md_create (name, devices, missingbitmap, nrdevices, spare, chunk, level);
  if (r == -1)
    /* do_md_create has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_md_create_args, (char *) &args);
done_no_free:
  return;
}

static void
list_md_devices_stub (XDR *xdr_in)
{
  char **r;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  r = do_list_md_devices ();
  if (r == NULL)
    /* do_list_md_devices has already called reply_with_error */
    goto done;

  struct guestfs_list_md_devices_ret ret;
  ret.devices.devices_len = count_strings (r);
  ret.devices.devices_val = r;
  reply ((xdrproc_t) &xdr_guestfs_list_md_devices_ret, (char *) &ret);
  free_strings (r);
done:
done_no_free:
  return;
}

static void
md_detail_stub (XDR *xdr_in)
{
  char **r;
  struct guestfs_md_detail_args args;
  CLEANUP_FREE char *md = NULL;

  /* The caller should have checked before calling this. */
  if (! optgroup_mdadm_available ()) {
    reply_with_unavailable_feature ("mdadm");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_md_detail_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args.md, md, , goto done);

  r = do_md_detail (md);
  if (r == NULL)
    /* do_md_detail has already called reply_with_error */
    goto done;

  struct guestfs_md_detail_ret ret;
  ret.info.info_len = count_strings (r);
  ret.info.info_val = r;
  reply ((xdrproc_t) &xdr_guestfs_md_detail_ret, (char *) &ret);
  free_strings (r);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_md_detail_args, (char *) &args);
done_no_free:
  return;
}

static void
md_stop_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_md_stop_args args;
  CLEANUP_FREE char *md = NULL;

  /* The caller should have checked before calling this. */
  if (! optgroup_mdadm_available ()) {
    reply_with_unavailable_feature ("mdadm");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_md_stop_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args.md, md, , goto done);

  r = do_md_stop (md);
  if (r == -1)
    /* do_md_stop has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_md_stop_args, (char *) &args);
done_no_free:
  return;
}

static void
blkid_stub (XDR *xdr_in)
{
  char **r;
  struct guestfs_blkid_args args;
  CLEANUP_FREE char *device = NULL;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_blkid_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args.device, device, , goto done);

  r = do_blkid (device);
  if (r == NULL)
    /* do_blkid has already called reply_with_error */
    goto done;

  struct guestfs_blkid_ret ret;
  ret.info.info_len = count_strings (r);
  ret.info.info_val = r;
  reply ((xdrproc_t) &xdr_guestfs_blkid_ret, (char *) &ret);
  free_strings (r);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_blkid_args, (char *) &args);
done_no_free:
  return;
}

static void
e2fsck_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_e2fsck_args args;
  CLEANUP_FREE char *device = NULL;
  int correct;
  int forceall;

  if (optargs_bitmask & UINT64_C(0xfffffffffffffffc)) {
    reply_with_error ("unknown option in optional arguments bitmask (this can happen if a program is compiled against a newer version of libguestfs, then run against an older version of the daemon)");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_e2fsck_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args.device, device, , goto done);
  correct = args.correct;
  forceall = args.forceall;

  r = do_e2fsck (device, correct, forceall);
  if (r == -1)
    /* do_e2fsck has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_e2fsck_args, (char *) &args);
done_no_free:
  return;
}

static void
llz_stub (XDR *xdr_in)
{
  char *r;
  struct guestfs_llz_args args;
  const char *directory;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_llz_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  directory = args.directory;
  ABS_PATH (directory, , goto done);

  NEED_ROOT (, goto done);
  r = do_llz (directory);
  if (r == NULL)
    /* do_llz has already called reply_with_error */
    goto done;

  struct guestfs_llz_ret ret;
  ret.listing = r;
  reply ((xdrproc_t) &xdr_guestfs_llz_ret, (char *) &ret);
  free (r);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_llz_args, (char *) &args);
done_no_free:
  return;
}

static void
wipefs_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_wipefs_args args;
  CLEANUP_FREE char *device = NULL;

  /* The caller should have checked before calling this. */
  if (! optgroup_wipefs_available ()) {
    reply_with_unavailable_feature ("wipefs");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_wipefs_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args.device, device, , goto done);

  r = do_wipefs (device);
  if (r == -1)
    /* do_wipefs has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_wipefs_args, (char *) &args);
done_no_free:
  return;
}

static void
ntfsfix_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_ntfsfix_args args;
  CLEANUP_FREE char *device = NULL;
  int clearbadsectors;

  /* The caller should have checked before calling this. */
  if (! optgroup_ntfs3g_available ()) {
    reply_with_unavailable_feature ("ntfs3g");
    goto done_no_free;
  }

  if (optargs_bitmask & UINT64_C(0xfffffffffffffffe)) {
    reply_with_error ("unknown option in optional arguments bitmask (this can happen if a program is compiled against a newer version of libguestfs, then run against an older version of the daemon)");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_ntfsfix_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args.device, device, , goto done);
  clearbadsectors = args.clearbadsectors;

  r = do_ntfsfix (device, clearbadsectors);
  if (r == -1)
    /* do_ntfsfix has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_ntfsfix_args, (char *) &args);
done_no_free:
  return;
}

static void
ntfsclone_out_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_ntfsclone_out_args args;
  CLEANUP_FREE char *device = NULL;
  int metadataonly;
  int rescue;
  int ignorefscheck;
  int preservetimestamps;
  int force;

  /* The caller should have checked before calling this. */
  if (! optgroup_ntfs3g_available ()) {
    reply_with_unavailable_feature ("ntfs3g");
    goto done_no_free;
  }

  if (optargs_bitmask & UINT64_C(0xffffffffffffffe0)) {
    reply_with_error ("unknown option in optional arguments bitmask (this can happen if a program is compiled against a newer version of libguestfs, then run against an older version of the daemon)");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_ntfsclone_out_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args.device, device, , goto done);
  metadataonly = args.metadataonly;
  rescue = args.rescue;
  ignorefscheck = args.ignorefscheck;
  preservetimestamps = args.preservetimestamps;
  force = args.force;

  r = do_ntfsclone_out (device, metadataonly, rescue, ignorefscheck, preservetimestamps, force);
  if (r == -1)
    /* do_ntfsclone_out has already called reply_with_error */
    goto done;

  /* do_ntfsclone_out has already sent a reply */
done:
  xdr_free ((xdrproc_t) xdr_guestfs_ntfsclone_out_args, (char *) &args);
done_no_free:
  return;
}

static void
ntfsclone_in_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_ntfsclone_in_args args;
  CLEANUP_FREE char *device = NULL;

  /* The caller should have checked before calling this. */
  if (! optgroup_ntfs3g_available ()) {
    cancel_receive ();
    reply_with_unavailable_feature ("ntfs3g");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    cancel_receive ();
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_ntfsclone_in_args (xdr_in, &args)) {
    cancel_receive ();
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args.device, device, cancel_receive (), goto done);

  r = do_ntfsclone_in (device);
  if (r == -1)
    /* do_ntfsclone_in has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_ntfsclone_in_args, (char *) &args);
done_no_free:
  return;
}

static void
set_label_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_set_label_args args;
  CLEANUP_FREE_MOUNTABLE mountable_t mountable
      = { .device = NULL, .volume = NULL };
  const char *label;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_set_label_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_MOUNTABLE (args.mountable, mountable, , goto done);
  label = args.label;

  r = do_set_label (&mountable, label);
  if (r == -1)
    /* do_set_label has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_set_label_args, (char *) &args);
done_no_free:
  return;
}

static void
zero_free_space_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_zero_free_space_args args;
  const char *directory;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_zero_free_space_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  directory = args.directory;
  ABS_PATH (directory, , goto done);

  NEED_ROOT (, goto done);
  r = do_zero_free_space (directory);
  if (r == -1)
    /* do_zero_free_space has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_zero_free_space_args, (char *) &args);
done_no_free:
  return;
}

static void
lvcreate_free_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_lvcreate_free_args args;
  const char *logvol;
  const char *volgroup;
  int percent;

  /* The caller should have checked before calling this. */
  if (! optgroup_lvm2_available ()) {
    reply_with_unavailable_feature ("lvm2");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_lvcreate_free_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  logvol = args.logvol;
  volgroup = args.volgroup;
  percent = args.percent;

  r = do_lvcreate_free (logvol, volgroup, percent);
  if (r == -1)
    /* do_lvcreate_free has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_lvcreate_free_args, (char *) &args);
done_no_free:
  return;
}

static void
isoinfo_device_stub (XDR *xdr_in)
{
  guestfs_int_isoinfo *r;
  struct guestfs_isoinfo_device_args args;
  CLEANUP_FREE char *device = NULL;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_isoinfo_device_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args.device, device, , goto done);

  r = do_isoinfo_device (device);
  if (r == NULL)
    /* do_isoinfo_device has already called reply_with_error */
    goto done;

  struct guestfs_isoinfo_device_ret ret;
  ret.isodata = *r;
  free (r);
  reply ((xdrproc_t) xdr_guestfs_isoinfo_device_ret, (char *) &ret);
  xdr_free ((xdrproc_t) xdr_guestfs_isoinfo_device_ret, (char *) &ret);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_isoinfo_device_args, (char *) &args);
done_no_free:
  return;
}

static void
isoinfo_stub (XDR *xdr_in)
{
  guestfs_int_isoinfo *r;
  struct guestfs_isoinfo_args args;
  const char *isofile;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_isoinfo_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  isofile = args.isofile;
  ABS_PATH (isofile, , goto done);

  NEED_ROOT (, goto done);
  r = do_isoinfo (isofile);
  if (r == NULL)
    /* do_isoinfo has already called reply_with_error */
    goto done;

  struct guestfs_isoinfo_ret ret;
  ret.isodata = *r;
  free (r);
  reply ((xdrproc_t) xdr_guestfs_isoinfo_ret, (char *) &ret);
  xdr_free ((xdrproc_t) xdr_guestfs_isoinfo_ret, (char *) &ret);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_isoinfo_args, (char *) &args);
done_no_free:
  return;
}

static void
vgmeta_stub (XDR *xdr_in)
{
  size_t size = 1;
  char *r;
  struct guestfs_vgmeta_args args;
  const char *vgname;

  /* The caller should have checked before calling this. */
  if (! optgroup_lvm2_available ()) {
    reply_with_unavailable_feature ("lvm2");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_vgmeta_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  vgname = args.vgname;

  r = do_vgmeta (vgname, &size);
  /* size == 0 && r == NULL could be a non-error case (just
   * an ordinary zero-length buffer), so be careful ...
   */
  if (size == 1 && r == NULL)
    /* do_vgmeta has already called reply_with_error */
    goto done;

  struct guestfs_vgmeta_ret ret;
  ret.metadata.metadata_val = r;
  ret.metadata.metadata_len = size;
  reply ((xdrproc_t) &xdr_guestfs_vgmeta_ret, (char *) &ret);
  free (r);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_vgmeta_args, (char *) &args);
done_no_free:
  return;
}

static void
md_stat_stub (XDR *xdr_in)
{
  guestfs_int_mdstat_list *r;
  struct guestfs_md_stat_args args;
  CLEANUP_FREE char *md = NULL;

  /* The caller should have checked before calling this. */
  if (! optgroup_mdadm_available ()) {
    reply_with_unavailable_feature ("mdadm");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_md_stat_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args.md, md, , goto done);

  r = do_md_stat (md);
  if (r == NULL)
    /* do_md_stat has already called reply_with_error */
    goto done;

  struct guestfs_md_stat_ret ret;
  ret.devices = *r;
  free (r);
  reply ((xdrproc_t) xdr_guestfs_md_stat_ret, (char *) &ret);
  xdr_free ((xdrproc_t) xdr_guestfs_md_stat_ret, (char *) &ret);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_md_stat_args, (char *) &args);
done_no_free:
  return;
}

static void
mkfs_btrfs_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_mkfs_btrfs_args args;
  CLEANUP_FREE_STRING_LIST char **devices = NULL;
  int64_t allocstart;
  int64_t bytecount;
  const char *datatype;
  int leafsize;
  const char *label;
  const char *metadata;
  int nodesize;
  int sectorsize;

  /* The caller should have checked before calling this. */
  if (! optgroup_btrfs_available ()) {
    reply_with_unavailable_feature ("btrfs");
    goto done_no_free;
  }

  if (optargs_bitmask & UINT64_C(0xffffffffffffff00)) {
    reply_with_error ("unknown option in optional arguments bitmask (this can happen if a program is compiled against a newer version of libguestfs, then run against an older version of the daemon)");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_mkfs_btrfs_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  /* Copy the string list and apply device name translation
   * to each one.
   */
  devices = calloc (args.devices.devices_len+1, sizeof (char *));
  {
    size_t i;
    for (i = 0; i < args.devices.devices_len; ++i)
      RESOLVE_DEVICE (args.devices.devices_val[i], devices[i],
                      , goto done);
    devices[i] = NULL;
  }
  allocstart = args.allocstart;
  bytecount = args.bytecount;
  datatype = args.datatype;
  leafsize = args.leafsize;
  label = args.label;
  metadata = args.metadata;
  nodesize = args.nodesize;
  sectorsize = args.sectorsize;

  r = do_mkfs_btrfs (devices, allocstart, bytecount, datatype, leafsize, label, metadata, nodesize, sectorsize);
  if (r == -1)
    /* do_mkfs_btrfs has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_mkfs_btrfs_args, (char *) &args);
done_no_free:
  return;
}

static void
get_e2attrs_stub (XDR *xdr_in)
{
  char *r;
  struct guestfs_get_e2attrs_args args;
  const char *file;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_get_e2attrs_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  file = args.file;
  ABS_PATH (file, , goto done);

  NEED_ROOT (, goto done);
  r = do_get_e2attrs (file);
  if (r == NULL)
    /* do_get_e2attrs has already called reply_with_error */
    goto done;

  struct guestfs_get_e2attrs_ret ret;
  ret.attrs = r;
  reply ((xdrproc_t) &xdr_guestfs_get_e2attrs_ret, (char *) &ret);
  free (r);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_get_e2attrs_args, (char *) &args);
done_no_free:
  return;
}

static void
set_e2attrs_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_set_e2attrs_args args;
  const char *file;
  const char *attrs;
  int clear;

  if (optargs_bitmask & UINT64_C(0xfffffffffffffffe)) {
    reply_with_error ("unknown option in optional arguments bitmask (this can happen if a program is compiled against a newer version of libguestfs, then run against an older version of the daemon)");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_set_e2attrs_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  file = args.file;
  ABS_PATH (file, , goto done);
  attrs = args.attrs;
  clear = args.clear;

  NEED_ROOT (, goto done);
  r = do_set_e2attrs (file, attrs, clear);
  if (r == -1)
    /* do_set_e2attrs has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_set_e2attrs_args, (char *) &args);
done_no_free:
  return;
}

static void
get_e2generation_stub (XDR *xdr_in)
{
  int64_t r;
  struct guestfs_get_e2generation_args args;
  const char *file;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_get_e2generation_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  file = args.file;
  ABS_PATH (file, , goto done);

  NEED_ROOT (, goto done);
  r = do_get_e2generation (file);
  if (r == -1)
    /* do_get_e2generation has already called reply_with_error */
    goto done;

  struct guestfs_get_e2generation_ret ret;
  ret.generation = r;
  reply ((xdrproc_t) &xdr_guestfs_get_e2generation_ret, (char *) &ret);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_get_e2generation_args, (char *) &args);
done_no_free:
  return;
}

static void
set_e2generation_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_set_e2generation_args args;
  const char *file;
  int64_t generation;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_set_e2generation_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  file = args.file;
  ABS_PATH (file, , goto done);
  generation = args.generation;

  NEED_ROOT (, goto done);
  r = do_set_e2generation (file, generation);
  if (r == -1)
    /* do_set_e2generation has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_set_e2generation_args, (char *) &args);
done_no_free:
  return;
}

static void
btrfs_subvolume_snapshot_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_btrfs_subvolume_snapshot_args args;
  const char *source;
  const char *dest;
  int ro;
  const char *qgroupid;

  /* The caller should have checked before calling this. */
  if (! optgroup_btrfs_available ()) {
    reply_with_unavailable_feature ("btrfs");
    goto done_no_free;
  }

  if (optargs_bitmask & UINT64_C(0xfffffffffffffffc)) {
    reply_with_error ("unknown option in optional arguments bitmask (this can happen if a program is compiled against a newer version of libguestfs, then run against an older version of the daemon)");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_btrfs_subvolume_snapshot_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  source = args.source;
  ABS_PATH (source, , goto done);
  dest = args.dest;
  ABS_PATH (dest, , goto done);
  ro = args.ro;
  qgroupid = args.qgroupid;

  NEED_ROOT (, goto done);
  r = do_btrfs_subvolume_snapshot (source, dest, ro, qgroupid);
  if (r == -1)
    /* do_btrfs_subvolume_snapshot has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_btrfs_subvolume_snapshot_args, (char *) &args);
done_no_free:
  return;
}

static void
btrfs_subvolume_delete_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_btrfs_subvolume_delete_args args;
  const char *subvolume;

  /* The caller should have checked before calling this. */
  if (! optgroup_btrfs_available ()) {
    reply_with_unavailable_feature ("btrfs");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_btrfs_subvolume_delete_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  subvolume = args.subvolume;
  ABS_PATH (subvolume, , goto done);

  NEED_ROOT (, goto done);
  r = do_btrfs_subvolume_delete (subvolume);
  if (r == -1)
    /* do_btrfs_subvolume_delete has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_btrfs_subvolume_delete_args, (char *) &args);
done_no_free:
  return;
}

static void
btrfs_subvolume_create_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_btrfs_subvolume_create_args args;
  const char *dest;
  const char *qgroupid;

  /* The caller should have checked before calling this. */
  if (! optgroup_btrfs_available ()) {
    reply_with_unavailable_feature ("btrfs");
    goto done_no_free;
  }

  if (optargs_bitmask & UINT64_C(0xfffffffffffffffe)) {
    reply_with_error ("unknown option in optional arguments bitmask (this can happen if a program is compiled against a newer version of libguestfs, then run against an older version of the daemon)");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_btrfs_subvolume_create_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  dest = args.dest;
  ABS_PATH (dest, , goto done);
  qgroupid = args.qgroupid;

  NEED_ROOT (, goto done);
  r = do_btrfs_subvolume_create (dest, qgroupid);
  if (r == -1)
    /* do_btrfs_subvolume_create has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_btrfs_subvolume_create_args, (char *) &args);
done_no_free:
  return;
}

static void
btrfs_subvolume_list_stub (XDR *xdr_in)
{
  guestfs_int_btrfssubvolume_list *r;
  struct guestfs_btrfs_subvolume_list_args args;
  CLEANUP_FREE_MOUNTABLE mountable_t fs
      = { .device = NULL, .volume = NULL };

  /* The caller should have checked before calling this. */
  if (! optgroup_btrfs_available ()) {
    reply_with_unavailable_feature ("btrfs");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_btrfs_subvolume_list_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  REQUIRE_ROOT_OR_RESOLVE_MOUNTABLE (args.fs, fs, , goto done);

  r = do_btrfs_subvolume_list (&fs);
  if (r == NULL)
    /* do_btrfs_subvolume_list has already called reply_with_error */
    goto done;

  struct guestfs_btrfs_subvolume_list_ret ret;
  ret.subvolumes = *r;
  free (r);
  reply ((xdrproc_t) xdr_guestfs_btrfs_subvolume_list_ret, (char *) &ret);
  xdr_free ((xdrproc_t) xdr_guestfs_btrfs_subvolume_list_ret, (char *) &ret);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_btrfs_subvolume_list_args, (char *) &args);
done_no_free:
  return;
}

static void
btrfs_subvolume_set_default_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_btrfs_subvolume_set_default_args args;
  int64_t id;
  const char *fs;

  /* The caller should have checked before calling this. */
  if (! optgroup_btrfs_available ()) {
    reply_with_unavailable_feature ("btrfs");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_btrfs_subvolume_set_default_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  id = args.id;
  fs = args.fs;
  ABS_PATH (fs, , goto done);

  NEED_ROOT (, goto done);
  r = do_btrfs_subvolume_set_default (id, fs);
  if (r == -1)
    /* do_btrfs_subvolume_set_default has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_btrfs_subvolume_set_default_args, (char *) &args);
done_no_free:
  return;
}

static void
btrfs_filesystem_sync_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_btrfs_filesystem_sync_args args;
  const char *fs;

  /* The caller should have checked before calling this. */
  if (! optgroup_btrfs_available ()) {
    reply_with_unavailable_feature ("btrfs");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_btrfs_filesystem_sync_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  fs = args.fs;
  ABS_PATH (fs, , goto done);

  NEED_ROOT (, goto done);
  r = do_btrfs_filesystem_sync (fs);
  if (r == -1)
    /* do_btrfs_filesystem_sync has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_btrfs_filesystem_sync_args, (char *) &args);
done_no_free:
  return;
}

static void
btrfs_filesystem_balance_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_btrfs_filesystem_balance_args args;
  const char *fs;

  /* The caller should have checked before calling this. */
  if (! optgroup_btrfs_available ()) {
    reply_with_unavailable_feature ("btrfs");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_btrfs_filesystem_balance_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  fs = args.fs;
  ABS_PATH (fs, , goto done);

  NEED_ROOT (, goto done);
  r = do_btrfs_filesystem_balance (fs);
  if (r == -1)
    /* do_btrfs_filesystem_balance has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_btrfs_filesystem_balance_args, (char *) &args);
done_no_free:
  return;
}

static void
btrfs_device_add_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_btrfs_device_add_args args;
  CLEANUP_FREE_STRING_LIST char **devices = NULL;
  const char *fs;

  /* The caller should have checked before calling this. */
  if (! optgroup_btrfs_available ()) {
    reply_with_unavailable_feature ("btrfs");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_btrfs_device_add_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  /* Copy the string list and apply device name translation
   * to each one.
   */
  devices = calloc (args.devices.devices_len+1, sizeof (char *));
  {
    size_t i;
    for (i = 0; i < args.devices.devices_len; ++i)
      RESOLVE_DEVICE (args.devices.devices_val[i], devices[i],
                      , goto done);
    devices[i] = NULL;
  }
  fs = args.fs;
  ABS_PATH (fs, , goto done);

  NEED_ROOT (, goto done);
  r = do_btrfs_device_add (devices, fs);
  if (r == -1)
    /* do_btrfs_device_add has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_btrfs_device_add_args, (char *) &args);
done_no_free:
  return;
}

static void
btrfs_device_delete_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_btrfs_device_delete_args args;
  CLEANUP_FREE_STRING_LIST char **devices = NULL;
  const char *fs;

  /* The caller should have checked before calling this. */
  if (! optgroup_btrfs_available ()) {
    reply_with_unavailable_feature ("btrfs");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_btrfs_device_delete_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  /* Copy the string list and apply device name translation
   * to each one.
   */
  devices = calloc (args.devices.devices_len+1, sizeof (char *));
  {
    size_t i;
    for (i = 0; i < args.devices.devices_len; ++i)
      RESOLVE_DEVICE (args.devices.devices_val[i], devices[i],
                      , goto done);
    devices[i] = NULL;
  }
  fs = args.fs;
  ABS_PATH (fs, , goto done);

  NEED_ROOT (, goto done);
  r = do_btrfs_device_delete (devices, fs);
  if (r == -1)
    /* do_btrfs_device_delete has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_btrfs_device_delete_args, (char *) &args);
done_no_free:
  return;
}

static void
btrfs_set_seeding_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_btrfs_set_seeding_args args;
  CLEANUP_FREE char *device = NULL;
  int seeding;

  /* The caller should have checked before calling this. */
  if (! optgroup_btrfs_available ()) {
    reply_with_unavailable_feature ("btrfs");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_btrfs_set_seeding_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args.device, device, , goto done);
  seeding = args.seeding;

  r = do_btrfs_set_seeding (device, seeding);
  if (r == -1)
    /* do_btrfs_set_seeding has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_btrfs_set_seeding_args, (char *) &args);
done_no_free:
  return;
}

static void
btrfs_fsck_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_btrfs_fsck_args args;
  CLEANUP_FREE char *device = NULL;
  int64_t superblock;
  int repair;

  /* The caller should have checked before calling this. */
  if (! optgroup_btrfs_available ()) {
    reply_with_unavailable_feature ("btrfs");
    goto done_no_free;
  }

  if (optargs_bitmask & UINT64_C(0xfffffffffffffffc)) {
    reply_with_error ("unknown option in optional arguments bitmask (this can happen if a program is compiled against a newer version of libguestfs, then run against an older version of the daemon)");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_btrfs_fsck_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args.device, device, , goto done);
  superblock = args.superblock;
  repair = args.repair;

  r = do_btrfs_fsck (device, superblock, repair);
  if (r == -1)
    /* do_btrfs_fsck has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_btrfs_fsck_args, (char *) &args);
done_no_free:
  return;
}

static void
filesystem_available_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_filesystem_available_args args;
  const char *filesystem;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_filesystem_available_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  filesystem = args.filesystem;

  r = do_filesystem_available (filesystem);
  if (r == -1)
    /* do_filesystem_available has already called reply_with_error */
    goto done;

  struct guestfs_filesystem_available_ret ret;
  ret.fsavail = r;
  reply ((xdrproc_t) &xdr_guestfs_filesystem_available_ret, (char *) &ret);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_filesystem_available_args, (char *) &args);
done_no_free:
  return;
}

static void
fstrim_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_fstrim_args args;
  const char *mountpoint;
  int64_t offset;
  int64_t length;
  int64_t minimumfreeextent;

  /* The caller should have checked before calling this. */
  if (! optgroup_fstrim_available ()) {
    reply_with_unavailable_feature ("fstrim");
    goto done_no_free;
  }

  if (optargs_bitmask & UINT64_C(0xfffffffffffffff8)) {
    reply_with_error ("unknown option in optional arguments bitmask (this can happen if a program is compiled against a newer version of libguestfs, then run against an older version of the daemon)");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_fstrim_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  mountpoint = args.mountpoint;
  ABS_PATH (mountpoint, , goto done);
  offset = args.offset;
  length = args.length;
  minimumfreeextent = args.minimumfreeextent;

  NEED_ROOT (, goto done);
  r = do_fstrim (mountpoint, offset, length, minimumfreeextent);
  if (r == -1)
    /* do_fstrim has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_fstrim_args, (char *) &args);
done_no_free:
  return;
}

static void
device_index_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_device_index_args args;
  CLEANUP_FREE char *device = NULL;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_device_index_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args.device, device, , goto done);

  r = do_device_index (device);
  if (r == -1)
    /* do_device_index has already called reply_with_error */
    goto done;

  struct guestfs_device_index_ret ret;
  ret.index = r;
  reply ((xdrproc_t) &xdr_guestfs_device_index_ret, (char *) &ret);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_device_index_args, (char *) &args);
done_no_free:
  return;
}

static void
nr_devices_stub (XDR *xdr_in)
{
  int r;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  r = do_nr_devices ();
  if (r == -1)
    /* do_nr_devices has already called reply_with_error */
    goto done;

  struct guestfs_nr_devices_ret ret;
  ret.nrdisks = r;
  reply ((xdrproc_t) &xdr_guestfs_nr_devices_ret, (char *) &ret);
done:
done_no_free:
  return;
}

static void
xfs_info_stub (XDR *xdr_in)
{
  guestfs_int_xfsinfo *r;
  struct guestfs_xfs_info_args args;
  CLEANUP_FREE char *pathordevice = NULL;

  /* The caller should have checked before calling this. */
  if (! optgroup_xfs_available ()) {
    reply_with_unavailable_feature ("xfs");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_xfs_info_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  REQUIRE_ROOT_OR_RESOLVE_DEVICE (args.pathordevice, pathordevice, , goto done);

  r = do_xfs_info (pathordevice);
  if (r == NULL)
    /* do_xfs_info has already called reply_with_error */
    goto done;

  struct guestfs_xfs_info_ret ret;
  ret.info = *r;
  free (r);
  reply ((xdrproc_t) xdr_guestfs_xfs_info_ret, (char *) &ret);
  xdr_free ((xdrproc_t) xdr_guestfs_xfs_info_ret, (char *) &ret);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_xfs_info_args, (char *) &args);
done_no_free:
  return;
}

static void
pvchange_uuid_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_pvchange_uuid_args args;
  CLEANUP_FREE char *device = NULL;

  /* The caller should have checked before calling this. */
  if (! optgroup_lvm2_available ()) {
    reply_with_unavailable_feature ("lvm2");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_pvchange_uuid_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args.device, device, , goto done);

  r = do_pvchange_uuid (device);
  if (r == -1)
    /* do_pvchange_uuid has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_pvchange_uuid_args, (char *) &args);
done_no_free:
  return;
}

static void
pvchange_uuid_all_stub (XDR *xdr_in)
{
  int r;

  /* The caller should have checked before calling this. */
  if (! optgroup_lvm2_available ()) {
    reply_with_unavailable_feature ("lvm2");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  r = do_pvchange_uuid_all ();
  if (r == -1)
    /* do_pvchange_uuid_all has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
done_no_free:
  return;
}

static void
vgchange_uuid_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_vgchange_uuid_args args;
  const char *vg;

  /* The caller should have checked before calling this. */
  if (! optgroup_lvm2_available ()) {
    reply_with_unavailable_feature ("lvm2");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_vgchange_uuid_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  vg = args.vg;

  r = do_vgchange_uuid (vg);
  if (r == -1)
    /* do_vgchange_uuid has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_vgchange_uuid_args, (char *) &args);
done_no_free:
  return;
}

static void
vgchange_uuid_all_stub (XDR *xdr_in)
{
  int r;

  /* The caller should have checked before calling this. */
  if (! optgroup_lvm2_available ()) {
    reply_with_unavailable_feature ("lvm2");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  r = do_vgchange_uuid_all ();
  if (r == -1)
    /* do_vgchange_uuid_all has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
done_no_free:
  return;
}

static void
utsname_stub (XDR *xdr_in)
{
  guestfs_int_utsname *r;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  r = do_utsname ();
  if (r == NULL)
    /* do_utsname has already called reply_with_error */
    goto done;

  struct guestfs_utsname_ret ret;
  ret.uts = *r;
  free (r);
  reply ((xdrproc_t) xdr_guestfs_utsname_ret, (char *) &ret);
  xdr_free ((xdrproc_t) xdr_guestfs_utsname_ret, (char *) &ret);
done:
done_no_free:
  return;
}

static void
xfs_growfs_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_xfs_growfs_args args;
  const char *path;
  int datasec;
  int logsec;
  int rtsec;
  int64_t datasize;
  int64_t logsize;
  int64_t rtsize;
  int64_t rtextsize;
  int maxpct;

  /* The caller should have checked before calling this. */
  if (! optgroup_xfs_available ()) {
    reply_with_unavailable_feature ("xfs");
    goto done_no_free;
  }

  if (optargs_bitmask & UINT64_C(0xffffffffffffff00)) {
    reply_with_error ("unknown option in optional arguments bitmask (this can happen if a program is compiled against a newer version of libguestfs, then run against an older version of the daemon)");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_xfs_growfs_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  path = args.path;
  ABS_PATH (path, , goto done);
  datasec = args.datasec;
  logsec = args.logsec;
  rtsec = args.rtsec;
  datasize = args.datasize;
  logsize = args.logsize;
  rtsize = args.rtsize;
  rtextsize = args.rtextsize;
  maxpct = args.maxpct;

  NEED_ROOT (, goto done);
  r = do_xfs_growfs (path, datasec, logsec, rtsec, datasize, logsize, rtsize, rtextsize, maxpct);
  if (r == -1)
    /* do_xfs_growfs has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_xfs_growfs_args, (char *) &args);
done_no_free:
  return;
}

static void
rsync_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_rsync_args args;
  const char *src;
  const char *dest;
  int archive;
  int deletedest;

  /* The caller should have checked before calling this. */
  if (! optgroup_rsync_available ()) {
    reply_with_unavailable_feature ("rsync");
    goto done_no_free;
  }

  if (optargs_bitmask & UINT64_C(0xfffffffffffffffc)) {
    reply_with_error ("unknown option in optional arguments bitmask (this can happen if a program is compiled against a newer version of libguestfs, then run against an older version of the daemon)");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_rsync_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  src = args.src;
  ABS_PATH (src, , goto done);
  dest = args.dest;
  ABS_PATH (dest, , goto done);
  archive = args.archive;
  deletedest = args.deletedest;

  NEED_ROOT (, goto done);
  r = do_rsync (src, dest, archive, deletedest);
  if (r == -1)
    /* do_rsync has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_rsync_args, (char *) &args);
done_no_free:
  return;
}

static void
rsync_in_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_rsync_in_args args;
  const char *remote;
  const char *dest;
  int archive;
  int deletedest;

  /* The caller should have checked before calling this. */
  if (! optgroup_rsync_available ()) {
    reply_with_unavailable_feature ("rsync");
    goto done_no_free;
  }

  if (optargs_bitmask & UINT64_C(0xfffffffffffffffc)) {
    reply_with_error ("unknown option in optional arguments bitmask (this can happen if a program is compiled against a newer version of libguestfs, then run against an older version of the daemon)");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_rsync_in_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  remote = args.remote;
  dest = args.dest;
  ABS_PATH (dest, , goto done);
  archive = args.archive;
  deletedest = args.deletedest;

  NEED_ROOT (, goto done);
  r = do_rsync_in (remote, dest, archive, deletedest);
  if (r == -1)
    /* do_rsync_in has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_rsync_in_args, (char *) &args);
done_no_free:
  return;
}

static void
rsync_out_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_rsync_out_args args;
  const char *src;
  const char *remote;
  int archive;
  int deletedest;

  /* The caller should have checked before calling this. */
  if (! optgroup_rsync_available ()) {
    reply_with_unavailable_feature ("rsync");
    goto done_no_free;
  }

  if (optargs_bitmask & UINT64_C(0xfffffffffffffffc)) {
    reply_with_error ("unknown option in optional arguments bitmask (this can happen if a program is compiled against a newer version of libguestfs, then run against an older version of the daemon)");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_rsync_out_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  src = args.src;
  ABS_PATH (src, , goto done);
  remote = args.remote;
  archive = args.archive;
  deletedest = args.deletedest;

  NEED_ROOT (, goto done);
  r = do_rsync_out (src, remote, archive, deletedest);
  if (r == -1)
    /* do_rsync_out has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_rsync_out_args, (char *) &args);
done_no_free:
  return;
}

static void
ls0_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_ls0_args args;
  const char *dir;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_ls0_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  dir = args.dir;
  ABS_PATH (dir, , goto done);

  NEED_ROOT (, goto done);
  r = do_ls0 (dir);
  if (r == -1)
    /* do_ls0 has already called reply_with_error */
    goto done;

  /* do_ls0 has already sent a reply */
done:
  xdr_free ((xdrproc_t) xdr_guestfs_ls0_args, (char *) &args);
done_no_free:
  return;
}

static void
fill_dir_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_fill_dir_args args;
  const char *dir;
  int nr;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_fill_dir_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  dir = args.dir;
  ABS_PATH (dir, , goto done);
  nr = args.nr;

  NEED_ROOT (, goto done);
  r = do_fill_dir (dir, nr);
  if (r == -1)
    /* do_fill_dir has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_fill_dir_args, (char *) &args);
done_no_free:
  return;
}

static void
xfs_admin_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_xfs_admin_args args;
  CLEANUP_FREE char *device = NULL;
  int extunwritten;
  int imgfile;
  int v2log;
  int projid32bit;
  int lazycounter;
  const char *label;
  const char *uuid;

  /* The caller should have checked before calling this. */
  if (! optgroup_xfs_available ()) {
    reply_with_unavailable_feature ("xfs");
    goto done_no_free;
  }

  if (optargs_bitmask & UINT64_C(0xffffffffffffff80)) {
    reply_with_error ("unknown option in optional arguments bitmask (this can happen if a program is compiled against a newer version of libguestfs, then run against an older version of the daemon)");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_xfs_admin_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args.device, device, , goto done);
  extunwritten = args.extunwritten;
  imgfile = args.imgfile;
  v2log = args.v2log;
  projid32bit = args.projid32bit;
  lazycounter = args.lazycounter;
  label = args.label;
  uuid = args.uuid;

  r = do_xfs_admin (device, extunwritten, imgfile, v2log, projid32bit, lazycounter, label, uuid);
  if (r == -1)
    /* do_xfs_admin has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_xfs_admin_args, (char *) &args);
done_no_free:
  return;
}

static void
hivex_open_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_hivex_open_args args;
  const char *filename;
  int verbose;
  int debug;
  int write;

  /* The caller should have checked before calling this. */
  if (! optgroup_hivex_available ()) {
    reply_with_unavailable_feature ("hivex");
    goto done_no_free;
  }

  if (optargs_bitmask & UINT64_C(0xfffffffffffffff8)) {
    reply_with_error ("unknown option in optional arguments bitmask (this can happen if a program is compiled against a newer version of libguestfs, then run against an older version of the daemon)");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_hivex_open_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  filename = args.filename;
  ABS_PATH (filename, , goto done);
  verbose = args.verbose;
  debug = args.debug;
  write = args.write;

  NEED_ROOT (, goto done);
  r = do_hivex_open (filename, verbose, debug, write);
  if (r == -1)
    /* do_hivex_open has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_hivex_open_args, (char *) &args);
done_no_free:
  return;
}

static void
hivex_close_stub (XDR *xdr_in)
{
  int r;

  /* The caller should have checked before calling this. */
  if (! optgroup_hivex_available ()) {
    reply_with_unavailable_feature ("hivex");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  r = do_hivex_close ();
  if (r == -1)
    /* do_hivex_close has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
done_no_free:
  return;
}

static void
hivex_root_stub (XDR *xdr_in)
{
  int64_t r;

  /* The caller should have checked before calling this. */
  if (! optgroup_hivex_available ()) {
    reply_with_unavailable_feature ("hivex");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  r = do_hivex_root ();
  if (r == -1)
    /* do_hivex_root has already called reply_with_error */
    goto done;

  struct guestfs_hivex_root_ret ret;
  ret.nodeh = r;
  reply ((xdrproc_t) &xdr_guestfs_hivex_root_ret, (char *) &ret);
done:
done_no_free:
  return;
}

static void
hivex_node_name_stub (XDR *xdr_in)
{
  char *r;
  struct guestfs_hivex_node_name_args args;
  int64_t nodeh;

  /* The caller should have checked before calling this. */
  if (! optgroup_hivex_available ()) {
    reply_with_unavailable_feature ("hivex");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_hivex_node_name_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  nodeh = args.nodeh;

  r = do_hivex_node_name (nodeh);
  if (r == NULL)
    /* do_hivex_node_name has already called reply_with_error */
    goto done;

  struct guestfs_hivex_node_name_ret ret;
  ret.name = r;
  reply ((xdrproc_t) &xdr_guestfs_hivex_node_name_ret, (char *) &ret);
  free (r);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_hivex_node_name_args, (char *) &args);
done_no_free:
  return;
}

static void
hivex_node_children_stub (XDR *xdr_in)
{
  guestfs_int_hivex_node_list *r;
  struct guestfs_hivex_node_children_args args;
  int64_t nodeh;

  /* The caller should have checked before calling this. */
  if (! optgroup_hivex_available ()) {
    reply_with_unavailable_feature ("hivex");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_hivex_node_children_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  nodeh = args.nodeh;

  r = do_hivex_node_children (nodeh);
  if (r == NULL)
    /* do_hivex_node_children has already called reply_with_error */
    goto done;

  struct guestfs_hivex_node_children_ret ret;
  ret.nodehs = *r;
  free (r);
  reply ((xdrproc_t) xdr_guestfs_hivex_node_children_ret, (char *) &ret);
  xdr_free ((xdrproc_t) xdr_guestfs_hivex_node_children_ret, (char *) &ret);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_hivex_node_children_args, (char *) &args);
done_no_free:
  return;
}

static void
hivex_node_get_child_stub (XDR *xdr_in)
{
  int64_t r;
  struct guestfs_hivex_node_get_child_args args;
  int64_t nodeh;
  const char *name;

  /* The caller should have checked before calling this. */
  if (! optgroup_hivex_available ()) {
    reply_with_unavailable_feature ("hivex");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_hivex_node_get_child_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  nodeh = args.nodeh;
  name = args.name;

  r = do_hivex_node_get_child (nodeh, name);
  if (r == -1)
    /* do_hivex_node_get_child has already called reply_with_error */
    goto done;

  struct guestfs_hivex_node_get_child_ret ret;
  ret.child = r;
  reply ((xdrproc_t) &xdr_guestfs_hivex_node_get_child_ret, (char *) &ret);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_hivex_node_get_child_args, (char *) &args);
done_no_free:
  return;
}

static void
hivex_node_parent_stub (XDR *xdr_in)
{
  int64_t r;
  struct guestfs_hivex_node_parent_args args;
  int64_t nodeh;

  /* The caller should have checked before calling this. */
  if (! optgroup_hivex_available ()) {
    reply_with_unavailable_feature ("hivex");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_hivex_node_parent_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  nodeh = args.nodeh;

  r = do_hivex_node_parent (nodeh);
  if (r == -1)
    /* do_hivex_node_parent has already called reply_with_error */
    goto done;

  struct guestfs_hivex_node_parent_ret ret;
  ret.parent = r;
  reply ((xdrproc_t) &xdr_guestfs_hivex_node_parent_ret, (char *) &ret);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_hivex_node_parent_args, (char *) &args);
done_no_free:
  return;
}

static void
hivex_node_values_stub (XDR *xdr_in)
{
  guestfs_int_hivex_value_list *r;
  struct guestfs_hivex_node_values_args args;
  int64_t nodeh;

  /* The caller should have checked before calling this. */
  if (! optgroup_hivex_available ()) {
    reply_with_unavailable_feature ("hivex");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_hivex_node_values_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  nodeh = args.nodeh;

  r = do_hivex_node_values (nodeh);
  if (r == NULL)
    /* do_hivex_node_values has already called reply_with_error */
    goto done;

  struct guestfs_hivex_node_values_ret ret;
  ret.valuehs = *r;
  free (r);
  reply ((xdrproc_t) xdr_guestfs_hivex_node_values_ret, (char *) &ret);
  xdr_free ((xdrproc_t) xdr_guestfs_hivex_node_values_ret, (char *) &ret);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_hivex_node_values_args, (char *) &args);
done_no_free:
  return;
}

static void
hivex_node_get_value_stub (XDR *xdr_in)
{
  int64_t r;
  struct guestfs_hivex_node_get_value_args args;
  int64_t nodeh;
  const char *key;

  /* The caller should have checked before calling this. */
  if (! optgroup_hivex_available ()) {
    reply_with_unavailable_feature ("hivex");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_hivex_node_get_value_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  nodeh = args.nodeh;
  key = args.key;

  r = do_hivex_node_get_value (nodeh, key);
  if (r == -1)
    /* do_hivex_node_get_value has already called reply_with_error */
    goto done;

  struct guestfs_hivex_node_get_value_ret ret;
  ret.valueh = r;
  reply ((xdrproc_t) &xdr_guestfs_hivex_node_get_value_ret, (char *) &ret);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_hivex_node_get_value_args, (char *) &args);
done_no_free:
  return;
}

static void
hivex_value_key_stub (XDR *xdr_in)
{
  char *r;
  struct guestfs_hivex_value_key_args args;
  int64_t valueh;

  /* The caller should have checked before calling this. */
  if (! optgroup_hivex_available ()) {
    reply_with_unavailable_feature ("hivex");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_hivex_value_key_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  valueh = args.valueh;

  r = do_hivex_value_key (valueh);
  if (r == NULL)
    /* do_hivex_value_key has already called reply_with_error */
    goto done;

  struct guestfs_hivex_value_key_ret ret;
  ret.key = r;
  reply ((xdrproc_t) &xdr_guestfs_hivex_value_key_ret, (char *) &ret);
  free (r);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_hivex_value_key_args, (char *) &args);
done_no_free:
  return;
}

static void
hivex_value_type_stub (XDR *xdr_in)
{
  int64_t r;
  struct guestfs_hivex_value_type_args args;
  int64_t valueh;

  /* The caller should have checked before calling this. */
  if (! optgroup_hivex_available ()) {
    reply_with_unavailable_feature ("hivex");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_hivex_value_type_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  valueh = args.valueh;

  r = do_hivex_value_type (valueh);
  if (r == -1)
    /* do_hivex_value_type has already called reply_with_error */
    goto done;

  struct guestfs_hivex_value_type_ret ret;
  ret.datatype = r;
  reply ((xdrproc_t) &xdr_guestfs_hivex_value_type_ret, (char *) &ret);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_hivex_value_type_args, (char *) &args);
done_no_free:
  return;
}

static void
hivex_value_value_stub (XDR *xdr_in)
{
  size_t size = 1;
  char *r;
  struct guestfs_hivex_value_value_args args;
  int64_t valueh;

  /* The caller should have checked before calling this. */
  if (! optgroup_hivex_available ()) {
    reply_with_unavailable_feature ("hivex");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_hivex_value_value_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  valueh = args.valueh;

  r = do_hivex_value_value (valueh, &size);
  /* size == 0 && r == NULL could be a non-error case (just
   * an ordinary zero-length buffer), so be careful ...
   */
  if (size == 1 && r == NULL)
    /* do_hivex_value_value has already called reply_with_error */
    goto done;

  struct guestfs_hivex_value_value_ret ret;
  ret.databuf.databuf_val = r;
  ret.databuf.databuf_len = size;
  reply ((xdrproc_t) &xdr_guestfs_hivex_value_value_ret, (char *) &ret);
  free (r);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_hivex_value_value_args, (char *) &args);
done_no_free:
  return;
}

static void
hivex_commit_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_hivex_commit_args args;
  const char *filename;

  /* The caller should have checked before calling this. */
  if (! optgroup_hivex_available ()) {
    reply_with_unavailable_feature ("hivex");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_hivex_commit_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  filename = args.filename ? *args.filename : NULL;

  r = do_hivex_commit (filename);
  if (r == -1)
    /* do_hivex_commit has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_hivex_commit_args, (char *) &args);
done_no_free:
  return;
}

static void
hivex_node_add_child_stub (XDR *xdr_in)
{
  int64_t r;
  struct guestfs_hivex_node_add_child_args args;
  int64_t parent;
  const char *name;

  /* The caller should have checked before calling this. */
  if (! optgroup_hivex_available ()) {
    reply_with_unavailable_feature ("hivex");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_hivex_node_add_child_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  parent = args.parent;
  name = args.name;

  r = do_hivex_node_add_child (parent, name);
  if (r == -1)
    /* do_hivex_node_add_child has already called reply_with_error */
    goto done;

  struct guestfs_hivex_node_add_child_ret ret;
  ret.nodeh = r;
  reply ((xdrproc_t) &xdr_guestfs_hivex_node_add_child_ret, (char *) &ret);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_hivex_node_add_child_args, (char *) &args);
done_no_free:
  return;
}

static void
hivex_node_delete_child_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_hivex_node_delete_child_args args;
  int64_t nodeh;

  /* The caller should have checked before calling this. */
  if (! optgroup_hivex_available ()) {
    reply_with_unavailable_feature ("hivex");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_hivex_node_delete_child_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  nodeh = args.nodeh;

  r = do_hivex_node_delete_child (nodeh);
  if (r == -1)
    /* do_hivex_node_delete_child has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_hivex_node_delete_child_args, (char *) &args);
done_no_free:
  return;
}

static void
hivex_node_set_value_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_hivex_node_set_value_args args;
  int64_t nodeh;
  const char *key;
  int64_t t;
  const char *val;
  size_t val_size;

  /* The caller should have checked before calling this. */
  if (! optgroup_hivex_available ()) {
    reply_with_unavailable_feature ("hivex");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_hivex_node_set_value_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  nodeh = args.nodeh;
  key = args.key;
  t = args.t;
  val = args.val.val_val;
  val_size = args.val.val_len;

  r = do_hivex_node_set_value (nodeh, key, t, val, val_size);
  if (r == -1)
    /* do_hivex_node_set_value has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_hivex_node_set_value_args, (char *) &args);
done_no_free:
  return;
}

static void
xfs_repair_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_xfs_repair_args args;
  CLEANUP_FREE char *device = NULL;
  int forcelogzero;
  int nomodify;
  int noprefetch;
  int forcegeometry;
  int64_t maxmem;
  int64_t ihashsize;
  int64_t bhashsize;
  int64_t agstride;
  const char *logdev;
  const char *rtdev;

  /* The caller should have checked before calling this. */
  if (! optgroup_xfs_available ()) {
    reply_with_unavailable_feature ("xfs");
    goto done_no_free;
  }

  if (optargs_bitmask & UINT64_C(0xfffffffffffffc00)) {
    reply_with_error ("unknown option in optional arguments bitmask (this can happen if a program is compiled against a newer version of libguestfs, then run against an older version of the daemon)");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_xfs_repair_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  REQUIRE_ROOT_OR_RESOLVE_DEVICE (args.device, device, , goto done);
  forcelogzero = args.forcelogzero;
  nomodify = args.nomodify;
  noprefetch = args.noprefetch;
  forcegeometry = args.forcegeometry;
  maxmem = args.maxmem;
  ihashsize = args.ihashsize;
  bhashsize = args.bhashsize;
  agstride = args.agstride;
  logdev = args.logdev;
  rtdev = args.rtdev;

  r = do_xfs_repair (device, forcelogzero, nomodify, noprefetch, forcegeometry, maxmem, ihashsize, bhashsize, agstride, logdev, rtdev);
  if (r == -1)
    /* do_xfs_repair has already called reply_with_error */
    goto done;

  struct guestfs_xfs_repair_ret ret;
  ret.status = r;
  reply ((xdrproc_t) &xdr_guestfs_xfs_repair_ret, (char *) &ret);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_xfs_repair_args, (char *) &args);
done_no_free:
  return;
}

static void
rm_f_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_rm_f_args args;
  const char *path;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_rm_f_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  path = args.path;
  ABS_PATH (path, , goto done);

  NEED_ROOT (, goto done);
  r = do_rm_f (path);
  if (r == -1)
    /* do_rm_f has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_rm_f_args, (char *) &args);
done_no_free:
  return;
}

static void
mke2fs_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_mke2fs_args args;
  CLEANUP_FREE char *device = NULL;
  int64_t blockscount;
  int64_t blocksize;
  int64_t fragsize;
  int64_t blockspergroup;
  int64_t numberofgroups;
  int64_t bytesperinode;
  int64_t inodesize;
  int64_t journalsize;
  int64_t numberofinodes;
  int64_t stridesize;
  int64_t stripewidth;
  int64_t maxonlineresize;
  int reservedblockspercentage;
  int mmpupdateinterval;
  const char *journaldevice;
  const char *label;
  const char *lastmounteddir;
  const char *creatoros;
  const char *fstype;
  const char *usagetype;
  const char *uuid;
  int forcecreate;
  int writesbandgrouponly;
  int lazyitableinit;
  int lazyjournalinit;
  int testfs;
  int discard;
  int quotatype;
  int extent;
  int filetype;
  int flexbg;
  int hasjournal;
  int journaldev;
  int largefile;
  int quota;
  int resizeinode;
  int sparsesuper;
  int uninitbg;

  if (optargs_bitmask & UINT64_C(0xffffffc000000000)) {
    reply_with_error ("unknown option in optional arguments bitmask (this can happen if a program is compiled against a newer version of libguestfs, then run against an older version of the daemon)");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_mke2fs_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args.device, device, , goto done);
  blockscount = args.blockscount;
  blocksize = args.blocksize;
  fragsize = args.fragsize;
  blockspergroup = args.blockspergroup;
  numberofgroups = args.numberofgroups;
  bytesperinode = args.bytesperinode;
  inodesize = args.inodesize;
  journalsize = args.journalsize;
  numberofinodes = args.numberofinodes;
  stridesize = args.stridesize;
  stripewidth = args.stripewidth;
  maxonlineresize = args.maxonlineresize;
  reservedblockspercentage = args.reservedblockspercentage;
  mmpupdateinterval = args.mmpupdateinterval;
  journaldevice = args.journaldevice;
  label = args.label;
  lastmounteddir = args.lastmounteddir;
  creatoros = args.creatoros;
  fstype = args.fstype;
  usagetype = args.usagetype;
  uuid = args.uuid;
  forcecreate = args.forcecreate;
  writesbandgrouponly = args.writesbandgrouponly;
  lazyitableinit = args.lazyitableinit;
  lazyjournalinit = args.lazyjournalinit;
  testfs = args.testfs;
  discard = args.discard;
  quotatype = args.quotatype;
  extent = args.extent;
  filetype = args.filetype;
  flexbg = args.flexbg;
  hasjournal = args.hasjournal;
  journaldev = args.journaldev;
  largefile = args.largefile;
  quota = args.quota;
  resizeinode = args.resizeinode;
  sparsesuper = args.sparsesuper;
  uninitbg = args.uninitbg;

  r = do_mke2fs (device, blockscount, blocksize, fragsize, blockspergroup, numberofgroups, bytesperinode, inodesize, journalsize, numberofinodes, stridesize, stripewidth, maxonlineresize, reservedblockspercentage, mmpupdateinterval, journaldevice, label, lastmounteddir, creatoros, fstype, usagetype, uuid, forcecreate, writesbandgrouponly, lazyitableinit, lazyjournalinit, testfs, discard, quotatype, extent, filetype, flexbg, hasjournal, journaldev, largefile, quota, resizeinode, sparsesuper, uninitbg);
  if (r == -1)
    /* do_mke2fs has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_mke2fs_args, (char *) &args);
done_no_free:
  return;
}

static void
list_disk_labels_stub (XDR *xdr_in)
{
  char **r;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  r = do_list_disk_labels ();
  if (r == NULL)
    /* do_list_disk_labels has already called reply_with_error */
    goto done;

  struct guestfs_list_disk_labels_ret ret;
  ret.labels.labels_len = count_strings (r);
  ret.labels.labels_val = r;
  reply ((xdrproc_t) &xdr_guestfs_list_disk_labels_ret, (char *) &ret);
  free_strings (r);
done:
done_no_free:
  return;
}

static void
internal_hot_add_drive_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_internal_hot_add_drive_args args;
  const char *label;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_internal_hot_add_drive_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  label = args.label;

  r = do_internal_hot_add_drive (label);
  if (r == -1)
    /* do_internal_hot_add_drive has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_internal_hot_add_drive_args, (char *) &args);
done_no_free:
  return;
}

static void
internal_hot_remove_drive_precheck_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_internal_hot_remove_drive_precheck_args args;
  const char *label;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_internal_hot_remove_drive_precheck_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  label = args.label;

  r = do_internal_hot_remove_drive_precheck (label);
  if (r == -1)
    /* do_internal_hot_remove_drive_precheck has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_internal_hot_remove_drive_precheck_args, (char *) &args);
done_no_free:
  return;
}

static void
internal_hot_remove_drive_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_internal_hot_remove_drive_args args;
  const char *label;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_internal_hot_remove_drive_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  label = args.label;

  r = do_internal_hot_remove_drive (label);
  if (r == -1)
    /* do_internal_hot_remove_drive has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_internal_hot_remove_drive_args, (char *) &args);
done_no_free:
  return;
}

static void
mktemp_stub (XDR *xdr_in)
{
  char *r;
  struct guestfs_mktemp_args args;
  const char *tmpl;
  const char *suffix;

  if (optargs_bitmask & UINT64_C(0xfffffffffffffffe)) {
    reply_with_error ("unknown option in optional arguments bitmask (this can happen if a program is compiled against a newer version of libguestfs, then run against an older version of the daemon)");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_mktemp_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  tmpl = args.tmpl;
  ABS_PATH (tmpl, , goto done);
  suffix = args.suffix;

  NEED_ROOT (, goto done);
  r = do_mktemp (tmpl, suffix);
  if (r == NULL)
    /* do_mktemp has already called reply_with_error */
    goto done;

  struct guestfs_mktemp_ret ret;
  ret.path = r;
  reply ((xdrproc_t) &xdr_guestfs_mktemp_ret, (char *) &ret);
  free (r);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_mktemp_args, (char *) &args);
done_no_free:
  return;
}

static void
mklost_and_found_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_mklost_and_found_args args;
  const char *mountpoint;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_mklost_and_found_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  mountpoint = args.mountpoint;
  ABS_PATH (mountpoint, , goto done);

  NEED_ROOT (, goto done);
  r = do_mklost_and_found (mountpoint);
  if (r == -1)
    /* do_mklost_and_found has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_mklost_and_found_args, (char *) &args);
done_no_free:
  return;
}

static void
acl_get_file_stub (XDR *xdr_in)
{
  char *r;
  struct guestfs_acl_get_file_args args;
  const char *path;
  const char *acltype;

  /* The caller should have checked before calling this. */
  if (! optgroup_acl_available ()) {
    reply_with_unavailable_feature ("acl");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_acl_get_file_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  path = args.path;
  ABS_PATH (path, , goto done);
  acltype = args.acltype;

  NEED_ROOT (, goto done);
  r = do_acl_get_file (path, acltype);
  if (r == NULL)
    /* do_acl_get_file has already called reply_with_error */
    goto done;

  struct guestfs_acl_get_file_ret ret;
  ret.acl = r;
  reply ((xdrproc_t) &xdr_guestfs_acl_get_file_ret, (char *) &ret);
  free (r);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_acl_get_file_args, (char *) &args);
done_no_free:
  return;
}

static void
acl_set_file_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_acl_set_file_args args;
  const char *path;
  const char *acltype;
  const char *acl;

  /* The caller should have checked before calling this. */
  if (! optgroup_acl_available ()) {
    reply_with_unavailable_feature ("acl");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_acl_set_file_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  path = args.path;
  ABS_PATH (path, , goto done);
  acltype = args.acltype;
  acl = args.acl;

  NEED_ROOT (, goto done);
  r = do_acl_set_file (path, acltype, acl);
  if (r == -1)
    /* do_acl_set_file has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_acl_set_file_args, (char *) &args);
done_no_free:
  return;
}

static void
acl_delete_def_file_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_acl_delete_def_file_args args;
  const char *dir;

  /* The caller should have checked before calling this. */
  if (! optgroup_acl_available ()) {
    reply_with_unavailable_feature ("acl");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_acl_delete_def_file_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  dir = args.dir;
  ABS_PATH (dir, , goto done);

  NEED_ROOT (, goto done);
  r = do_acl_delete_def_file (dir);
  if (r == -1)
    /* do_acl_delete_def_file has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_acl_delete_def_file_args, (char *) &args);
done_no_free:
  return;
}

static void
cap_get_file_stub (XDR *xdr_in)
{
  char *r;
  struct guestfs_cap_get_file_args args;
  const char *path;

  /* The caller should have checked before calling this. */
  if (! optgroup_linuxcaps_available ()) {
    reply_with_unavailable_feature ("linuxcaps");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_cap_get_file_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  path = args.path;
  ABS_PATH (path, , goto done);

  NEED_ROOT (, goto done);
  r = do_cap_get_file (path);
  if (r == NULL)
    /* do_cap_get_file has already called reply_with_error */
    goto done;

  struct guestfs_cap_get_file_ret ret;
  ret.cap = r;
  reply ((xdrproc_t) &xdr_guestfs_cap_get_file_ret, (char *) &ret);
  free (r);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_cap_get_file_args, (char *) &args);
done_no_free:
  return;
}

static void
cap_set_file_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_cap_set_file_args args;
  const char *path;
  const char *cap;

  /* The caller should have checked before calling this. */
  if (! optgroup_linuxcaps_available ()) {
    reply_with_unavailable_feature ("linuxcaps");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_cap_set_file_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  path = args.path;
  ABS_PATH (path, , goto done);
  cap = args.cap;

  NEED_ROOT (, goto done);
  r = do_cap_set_file (path, cap);
  if (r == -1)
    /* do_cap_set_file has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_cap_set_file_args, (char *) &args);
done_no_free:
  return;
}

static void
list_ldm_volumes_stub (XDR *xdr_in)
{
  char **r;

  /* The caller should have checked before calling this. */
  if (! optgroup_ldm_available ()) {
    reply_with_unavailable_feature ("ldm");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  r = do_list_ldm_volumes ();
  if (r == NULL)
    /* do_list_ldm_volumes has already called reply_with_error */
    goto done;

  struct guestfs_list_ldm_volumes_ret ret;
  ret.devices.devices_len = count_strings (r);
  ret.devices.devices_val = r;
  reply ((xdrproc_t) &xdr_guestfs_list_ldm_volumes_ret, (char *) &ret);
  free_strings (r);
done:
done_no_free:
  return;
}

static void
list_ldm_partitions_stub (XDR *xdr_in)
{
  char **r;

  /* The caller should have checked before calling this. */
  if (! optgroup_ldm_available ()) {
    reply_with_unavailable_feature ("ldm");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  r = do_list_ldm_partitions ();
  if (r == NULL)
    /* do_list_ldm_partitions has already called reply_with_error */
    goto done;

  struct guestfs_list_ldm_partitions_ret ret;
  ret.devices.devices_len = count_strings (r);
  ret.devices.devices_val = r;
  reply ((xdrproc_t) &xdr_guestfs_list_ldm_partitions_ret, (char *) &ret);
  free_strings (r);
done:
done_no_free:
  return;
}

static void
ldmtool_create_all_stub (XDR *xdr_in)
{
  int r;

  /* The caller should have checked before calling this. */
  if (! optgroup_ldm_available ()) {
    reply_with_unavailable_feature ("ldm");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  r = do_ldmtool_create_all ();
  if (r == -1)
    /* do_ldmtool_create_all has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
done_no_free:
  return;
}

static void
ldmtool_remove_all_stub (XDR *xdr_in)
{
  int r;

  /* The caller should have checked before calling this. */
  if (! optgroup_ldm_available ()) {
    reply_with_unavailable_feature ("ldm");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  r = do_ldmtool_remove_all ();
  if (r == -1)
    /* do_ldmtool_remove_all has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
done_no_free:
  return;
}

static void
ldmtool_scan_stub (XDR *xdr_in)
{
  char **r;

  /* The caller should have checked before calling this. */
  if (! optgroup_ldm_available ()) {
    reply_with_unavailable_feature ("ldm");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  r = do_ldmtool_scan ();
  if (r == NULL)
    /* do_ldmtool_scan has already called reply_with_error */
    goto done;

  struct guestfs_ldmtool_scan_ret ret;
  ret.guids.guids_len = count_strings (r);
  ret.guids.guids_val = r;
  reply ((xdrproc_t) &xdr_guestfs_ldmtool_scan_ret, (char *) &ret);
  free_strings (r);
done:
done_no_free:
  return;
}

static void
ldmtool_scan_devices_stub (XDR *xdr_in)
{
  char **r;
  struct guestfs_ldmtool_scan_devices_args args;
  CLEANUP_FREE_STRING_LIST char **devices = NULL;

  /* The caller should have checked before calling this. */
  if (! optgroup_ldm_available ()) {
    reply_with_unavailable_feature ("ldm");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_ldmtool_scan_devices_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  /* Copy the string list and apply device name translation
   * to each one.
   */
  devices = calloc (args.devices.devices_len+1, sizeof (char *));
  {
    size_t i;
    for (i = 0; i < args.devices.devices_len; ++i)
      RESOLVE_DEVICE (args.devices.devices_val[i], devices[i],
                      , goto done);
    devices[i] = NULL;
  }

  r = do_ldmtool_scan_devices (devices);
  if (r == NULL)
    /* do_ldmtool_scan_devices has already called reply_with_error */
    goto done;

  struct guestfs_ldmtool_scan_devices_ret ret;
  ret.guids.guids_len = count_strings (r);
  ret.guids.guids_val = r;
  reply ((xdrproc_t) &xdr_guestfs_ldmtool_scan_devices_ret, (char *) &ret);
  free_strings (r);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_ldmtool_scan_devices_args, (char *) &args);
done_no_free:
  return;
}

static void
ldmtool_diskgroup_name_stub (XDR *xdr_in)
{
  char *r;
  struct guestfs_ldmtool_diskgroup_name_args args;
  const char *diskgroup;

  /* The caller should have checked before calling this. */
  if (! optgroup_ldm_available ()) {
    reply_with_unavailable_feature ("ldm");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_ldmtool_diskgroup_name_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  diskgroup = args.diskgroup;

  r = do_ldmtool_diskgroup_name (diskgroup);
  if (r == NULL)
    /* do_ldmtool_diskgroup_name has already called reply_with_error */
    goto done;

  struct guestfs_ldmtool_diskgroup_name_ret ret;
  ret.name = r;
  reply ((xdrproc_t) &xdr_guestfs_ldmtool_diskgroup_name_ret, (char *) &ret);
  free (r);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_ldmtool_diskgroup_name_args, (char *) &args);
done_no_free:
  return;
}

static void
ldmtool_diskgroup_volumes_stub (XDR *xdr_in)
{
  char **r;
  struct guestfs_ldmtool_diskgroup_volumes_args args;
  const char *diskgroup;

  /* The caller should have checked before calling this. */
  if (! optgroup_ldm_available ()) {
    reply_with_unavailable_feature ("ldm");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_ldmtool_diskgroup_volumes_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  diskgroup = args.diskgroup;

  r = do_ldmtool_diskgroup_volumes (diskgroup);
  if (r == NULL)
    /* do_ldmtool_diskgroup_volumes has already called reply_with_error */
    goto done;

  struct guestfs_ldmtool_diskgroup_volumes_ret ret;
  ret.volumes.volumes_len = count_strings (r);
  ret.volumes.volumes_val = r;
  reply ((xdrproc_t) &xdr_guestfs_ldmtool_diskgroup_volumes_ret, (char *) &ret);
  free_strings (r);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_ldmtool_diskgroup_volumes_args, (char *) &args);
done_no_free:
  return;
}

static void
ldmtool_diskgroup_disks_stub (XDR *xdr_in)
{
  char **r;
  struct guestfs_ldmtool_diskgroup_disks_args args;
  const char *diskgroup;

  /* The caller should have checked before calling this. */
  if (! optgroup_ldm_available ()) {
    reply_with_unavailable_feature ("ldm");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_ldmtool_diskgroup_disks_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  diskgroup = args.diskgroup;

  r = do_ldmtool_diskgroup_disks (diskgroup);
  if (r == NULL)
    /* do_ldmtool_diskgroup_disks has already called reply_with_error */
    goto done;

  struct guestfs_ldmtool_diskgroup_disks_ret ret;
  ret.disks.disks_len = count_strings (r);
  ret.disks.disks_val = r;
  reply ((xdrproc_t) &xdr_guestfs_ldmtool_diskgroup_disks_ret, (char *) &ret);
  free_strings (r);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_ldmtool_diskgroup_disks_args, (char *) &args);
done_no_free:
  return;
}

static void
ldmtool_volume_type_stub (XDR *xdr_in)
{
  char *r;
  struct guestfs_ldmtool_volume_type_args args;
  const char *diskgroup;
  const char *volume;

  /* The caller should have checked before calling this. */
  if (! optgroup_ldm_available ()) {
    reply_with_unavailable_feature ("ldm");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_ldmtool_volume_type_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  diskgroup = args.diskgroup;
  volume = args.volume;

  r = do_ldmtool_volume_type (diskgroup, volume);
  if (r == NULL)
    /* do_ldmtool_volume_type has already called reply_with_error */
    goto done;

  struct guestfs_ldmtool_volume_type_ret ret;
  ret.voltype = r;
  reply ((xdrproc_t) &xdr_guestfs_ldmtool_volume_type_ret, (char *) &ret);
  free (r);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_ldmtool_volume_type_args, (char *) &args);
done_no_free:
  return;
}

static void
ldmtool_volume_hint_stub (XDR *xdr_in)
{
  char *r;
  struct guestfs_ldmtool_volume_hint_args args;
  const char *diskgroup;
  const char *volume;

  /* The caller should have checked before calling this. */
  if (! optgroup_ldm_available ()) {
    reply_with_unavailable_feature ("ldm");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_ldmtool_volume_hint_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  diskgroup = args.diskgroup;
  volume = args.volume;

  r = do_ldmtool_volume_hint (diskgroup, volume);
  if (r == NULL)
    /* do_ldmtool_volume_hint has already called reply_with_error */
    goto done;

  struct guestfs_ldmtool_volume_hint_ret ret;
  ret.hint = r;
  reply ((xdrproc_t) &xdr_guestfs_ldmtool_volume_hint_ret, (char *) &ret);
  free (r);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_ldmtool_volume_hint_args, (char *) &args);
done_no_free:
  return;
}

static void
ldmtool_volume_partitions_stub (XDR *xdr_in)
{
  char **r;
  struct guestfs_ldmtool_volume_partitions_args args;
  const char *diskgroup;
  const char *volume;

  /* The caller should have checked before calling this. */
  if (! optgroup_ldm_available ()) {
    reply_with_unavailable_feature ("ldm");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_ldmtool_volume_partitions_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  diskgroup = args.diskgroup;
  volume = args.volume;

  r = do_ldmtool_volume_partitions (diskgroup, volume);
  if (r == NULL)
    /* do_ldmtool_volume_partitions has already called reply_with_error */
    goto done;

  struct guestfs_ldmtool_volume_partitions_ret ret;
  ret.partitions.partitions_len = count_strings (r);
  ret.partitions.partitions_val = r;
  reply ((xdrproc_t) &xdr_guestfs_ldmtool_volume_partitions_ret, (char *) &ret);
  free_strings (r);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_ldmtool_volume_partitions_args, (char *) &args);
done_no_free:
  return;
}

static void
part_set_gpt_type_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_part_set_gpt_type_args args;
  CLEANUP_FREE char *device = NULL;
  int partnum;
  const char *guid;

  /* The caller should have checked before calling this. */
  if (! optgroup_gdisk_available ()) {
    reply_with_unavailable_feature ("gdisk");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_part_set_gpt_type_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args.device, device, , goto done);
  partnum = args.partnum;
  guid = args.guid;

  r = do_part_set_gpt_type (device, partnum, guid);
  if (r == -1)
    /* do_part_set_gpt_type has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_part_set_gpt_type_args, (char *) &args);
done_no_free:
  return;
}

static void
part_get_gpt_type_stub (XDR *xdr_in)
{
  char *r;
  struct guestfs_part_get_gpt_type_args args;
  CLEANUP_FREE char *device = NULL;
  int partnum;

  /* The caller should have checked before calling this. */
  if (! optgroup_gdisk_available ()) {
    reply_with_unavailable_feature ("gdisk");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_part_get_gpt_type_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args.device, device, , goto done);
  partnum = args.partnum;

  r = do_part_get_gpt_type (device, partnum);
  if (r == NULL)
    /* do_part_get_gpt_type has already called reply_with_error */
    goto done;

  struct guestfs_part_get_gpt_type_ret ret;
  ret.guid = r;
  reply ((xdrproc_t) &xdr_guestfs_part_get_gpt_type_ret, (char *) &ret);
  free (r);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_part_get_gpt_type_args, (char *) &args);
done_no_free:
  return;
}

static void
rename_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_rename_args args;
  const char *oldpath;
  const char *newpath;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_rename_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  oldpath = args.oldpath;
  ABS_PATH (oldpath, , goto done);
  newpath = args.newpath;
  ABS_PATH (newpath, , goto done);

  NEED_ROOT (, goto done);
  r = do_rename (oldpath, newpath);
  if (r == -1)
    /* do_rename has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_rename_args, (char *) &args);
done_no_free:
  return;
}

static void
is_whole_device_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_is_whole_device_args args;
  CLEANUP_FREE char *device = NULL;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_is_whole_device_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args.device, device, , goto done);

  r = do_is_whole_device (device);
  if (r == -1)
    /* do_is_whole_device has already called reply_with_error */
    goto done;

  struct guestfs_is_whole_device_ret ret;
  ret.flag = r;
  reply ((xdrproc_t) &xdr_guestfs_is_whole_device_ret, (char *) &ret);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_is_whole_device_args, (char *) &args);
done_no_free:
  return;
}

static void
internal_parse_mountable_stub (XDR *xdr_in)
{
  guestfs_int_internal_mountable *r;
  struct guestfs_internal_parse_mountable_args args;
  CLEANUP_FREE_MOUNTABLE mountable_t mountable
      = { .device = NULL, .volume = NULL };

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_internal_parse_mountable_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_MOUNTABLE (args.mountable, mountable, , goto done);

  r = do_internal_parse_mountable (&mountable);
  if (r == NULL)
    /* do_internal_parse_mountable has already called reply_with_error */
    goto done;

  struct guestfs_internal_parse_mountable_ret ret;
  ret.mountable = *r;
  free (r);
  reply ((xdrproc_t) xdr_guestfs_internal_parse_mountable_ret, (char *) &ret);
  xdr_free ((xdrproc_t) xdr_guestfs_internal_parse_mountable_ret, (char *) &ret);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_internal_parse_mountable_args, (char *) &args);
done_no_free:
  return;
}

static void
internal_rhbz914931_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_internal_rhbz914931_args args;
  int count;

  if (optargs_bitmask != 0) {
    cancel_receive ();
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_internal_rhbz914931_args (xdr_in, &args)) {
    cancel_receive ();
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  count = args.count;

  r = do_internal_rhbz914931 (count);
  if (r == -1)
    /* do_internal_rhbz914931 has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_internal_rhbz914931_args, (char *) &args);
done_no_free:
  return;
}

static void
feature_available_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_feature_available_args args;
  char **groups;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_feature_available_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  /* Ugly, but safe and avoids copying the strings. */
  groups = realloc (args.groups.groups_val,
                sizeof (char *) * (args.groups.groups_len+1));
  if (groups == NULL) {
    reply_with_perror ("realloc");
    goto done;
  }
  groups[args.groups.groups_len] = NULL;
  args.groups.groups_val = groups;

  r = do_feature_available (groups);
  if (r == -1)
    /* do_feature_available has already called reply_with_error */
    goto done;

  struct guestfs_feature_available_ret ret;
  ret.isavailable = r;
  reply ((xdrproc_t) &xdr_guestfs_feature_available_ret, (char *) &ret);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_feature_available_args, (char *) &args);
done_no_free:
  return;
}

static void
syslinux_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_syslinux_args args;
  CLEANUP_FREE char *device = NULL;
  const char *directory;

  /* The caller should have checked before calling this. */
  if (! optgroup_syslinux_available ()) {
    reply_with_unavailable_feature ("syslinux");
    goto done_no_free;
  }

  if (optargs_bitmask & UINT64_C(0xfffffffffffffffe)) {
    reply_with_error ("unknown option in optional arguments bitmask (this can happen if a program is compiled against a newer version of libguestfs, then run against an older version of the daemon)");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_syslinux_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args.device, device, , goto done);
  directory = args.directory;

  r = do_syslinux (device, directory);
  if (r == -1)
    /* do_syslinux has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_syslinux_args, (char *) &args);
done_no_free:
  return;
}

static void
extlinux_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_extlinux_args args;
  const char *directory;

  /* The caller should have checked before calling this. */
  if (! optgroup_extlinux_available ()) {
    reply_with_unavailable_feature ("extlinux");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_extlinux_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  directory = args.directory;
  ABS_PATH (directory, , goto done);

  NEED_ROOT (, goto done);
  r = do_extlinux (directory);
  if (r == -1)
    /* do_extlinux has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_extlinux_args, (char *) &args);
done_no_free:
  return;
}

static void
cp_r_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_cp_r_args args;
  const char *src;
  const char *dest;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_cp_r_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  src = args.src;
  ABS_PATH (src, , goto done);
  dest = args.dest;
  ABS_PATH (dest, , goto done);

  NEED_ROOT (, goto done);
  r = do_cp_r (src, dest);
  if (r == -1)
    /* do_cp_r has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_cp_r_args, (char *) &args);
done_no_free:
  return;
}

static void
remount_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_remount_args args;
  const char *mountpoint;
  int rw;

  if (optargs_bitmask & UINT64_C(0xfffffffffffffffe)) {
    reply_with_error ("unknown option in optional arguments bitmask (this can happen if a program is compiled against a newer version of libguestfs, then run against an older version of the daemon)");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_remount_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  mountpoint = args.mountpoint;
  ABS_PATH (mountpoint, , goto done);
  rw = args.rw;

  NEED_ROOT (, goto done);
  r = do_remount (mountpoint, rw);
  if (r == -1)
    /* do_remount has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_remount_args, (char *) &args);
done_no_free:
  return;
}

static void
set_uuid_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_set_uuid_args args;
  CLEANUP_FREE char *device = NULL;
  const char *uuid;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_set_uuid_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args.device, device, , goto done);
  uuid = args.uuid;

  r = do_set_uuid (device, uuid);
  if (r == -1)
    /* do_set_uuid has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_set_uuid_args, (char *) &args);
done_no_free:
  return;
}

static void
journal_open_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_journal_open_args args;
  const char *directory;

  /* The caller should have checked before calling this. */
  if (! optgroup_journal_available ()) {
    reply_with_unavailable_feature ("journal");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_journal_open_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  directory = args.directory;
  ABS_PATH (directory, , goto done);

  NEED_ROOT (, goto done);
  r = do_journal_open (directory);
  if (r == -1)
    /* do_journal_open has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_journal_open_args, (char *) &args);
done_no_free:
  return;
}

static void
journal_close_stub (XDR *xdr_in)
{
  int r;

  /* The caller should have checked before calling this. */
  if (! optgroup_journal_available ()) {
    reply_with_unavailable_feature ("journal");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  r = do_journal_close ();
  if (r == -1)
    /* do_journal_close has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
done_no_free:
  return;
}

static void
journal_next_stub (XDR *xdr_in)
{
  int r;

  /* The caller should have checked before calling this. */
  if (! optgroup_journal_available ()) {
    reply_with_unavailable_feature ("journal");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  r = do_journal_next ();
  if (r == -1)
    /* do_journal_next has already called reply_with_error */
    goto done;

  struct guestfs_journal_next_ret ret;
  ret.more = r;
  reply ((xdrproc_t) &xdr_guestfs_journal_next_ret, (char *) &ret);
done:
done_no_free:
  return;
}

static void
journal_skip_stub (XDR *xdr_in)
{
  int64_t r;
  struct guestfs_journal_skip_args args;
  int64_t skip;

  /* The caller should have checked before calling this. */
  if (! optgroup_journal_available ()) {
    reply_with_unavailable_feature ("journal");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_journal_skip_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  skip = args.skip;

  r = do_journal_skip (skip);
  if (r == -1)
    /* do_journal_skip has already called reply_with_error */
    goto done;

  struct guestfs_journal_skip_ret ret;
  ret.rskip = r;
  reply ((xdrproc_t) &xdr_guestfs_journal_skip_ret, (char *) &ret);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_journal_skip_args, (char *) &args);
done_no_free:
  return;
}

static void
internal_journal_get_stub (XDR *xdr_in)
{
  int r;

  /* The caller should have checked before calling this. */
  if (! optgroup_journal_available ()) {
    reply_with_unavailable_feature ("journal");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  r = do_internal_journal_get ();
  if (r == -1)
    /* do_internal_journal_get has already called reply_with_error */
    goto done;

  /* do_internal_journal_get has already sent a reply */
done:
done_no_free:
  return;
}

static void
journal_get_data_threshold_stub (XDR *xdr_in)
{
  int64_t r;

  /* The caller should have checked before calling this. */
  if (! optgroup_journal_available ()) {
    reply_with_unavailable_feature ("journal");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  r = do_journal_get_data_threshold ();
  if (r == -1)
    /* do_journal_get_data_threshold has already called reply_with_error */
    goto done;

  struct guestfs_journal_get_data_threshold_ret ret;
  ret.threshold = r;
  reply ((xdrproc_t) &xdr_guestfs_journal_get_data_threshold_ret, (char *) &ret);
done:
done_no_free:
  return;
}

static void
journal_set_data_threshold_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_journal_set_data_threshold_args args;
  int64_t threshold;

  /* The caller should have checked before calling this. */
  if (! optgroup_journal_available ()) {
    reply_with_unavailable_feature ("journal");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_journal_set_data_threshold_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  threshold = args.threshold;

  r = do_journal_set_data_threshold (threshold);
  if (r == -1)
    /* do_journal_set_data_threshold has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_journal_set_data_threshold_args, (char *) &args);
done_no_free:
  return;
}

static void
aug_setm_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_aug_setm_args args;
  const char *base;
  const char *sub;
  const char *val;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_aug_setm_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  base = args.base;
  sub = args.sub ? *args.sub : NULL;
  val = args.val;

  r = do_aug_setm (base, sub, val);
  if (r == -1)
    /* do_aug_setm has already called reply_with_error */
    goto done;

  struct guestfs_aug_setm_ret ret;
  ret.nodes = r;
  reply ((xdrproc_t) &xdr_guestfs_aug_setm_ret, (char *) &ret);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_aug_setm_args, (char *) &args);
done_no_free:
  return;
}

static void
aug_label_stub (XDR *xdr_in)
{
  char *r;
  struct guestfs_aug_label_args args;
  const char *augpath;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_aug_label_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  augpath = args.augpath;

  r = do_aug_label (augpath);
  if (r == NULL)
    /* do_aug_label has already called reply_with_error */
    goto done;

  struct guestfs_aug_label_ret ret;
  ret.label = r;
  reply ((xdrproc_t) &xdr_guestfs_aug_label_ret, (char *) &ret);
  free (r);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_aug_label_args, (char *) &args);
done_no_free:
  return;
}

static void
internal_upload_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_internal_upload_args args;
  const char *tmpname;
  int mode;

  if (optargs_bitmask != 0) {
    cancel_receive ();
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_internal_upload_args (xdr_in, &args)) {
    cancel_receive ();
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  tmpname = args.tmpname;
  mode = args.mode;

  r = do_internal_upload (tmpname, mode);
  if (r == -1)
    /* do_internal_upload has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_internal_upload_args, (char *) &args);
done_no_free:
  return;
}

static void
internal_exit_stub (XDR *xdr_in)
{
  int r;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  r = do_internal_exit ();
  if (r == -1)
    /* do_internal_exit has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
done_no_free:
  return;
}

static void
copy_attributes_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_copy_attributes_args args;
  const char *src;
  const char *dest;
  int all;
  int mode;
  int xattributes;
  int ownership;

  if (optargs_bitmask & UINT64_C(0xfffffffffffffff0)) {
    reply_with_error ("unknown option in optional arguments bitmask (this can happen if a program is compiled against a newer version of libguestfs, then run against an older version of the daemon)");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_copy_attributes_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  src = args.src;
  ABS_PATH (src, , goto done);
  dest = args.dest;
  ABS_PATH (dest, , goto done);
  all = args.all;
  mode = args.mode;
  xattributes = args.xattributes;
  ownership = args.ownership;

  NEED_ROOT (, goto done);
  r = do_copy_attributes (src, dest, all, mode, xattributes, ownership);
  if (r == -1)
    /* do_copy_attributes has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_copy_attributes_args, (char *) &args);
done_no_free:
  return;
}

static void
part_get_name_stub (XDR *xdr_in)
{
  char *r;
  struct guestfs_part_get_name_args args;
  CLEANUP_FREE char *device = NULL;
  int partnum;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_part_get_name_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args.device, device, , goto done);
  partnum = args.partnum;

  r = do_part_get_name (device, partnum);
  if (r == NULL)
    /* do_part_get_name has already called reply_with_error */
    goto done;

  struct guestfs_part_get_name_ret ret;
  ret.name = r;
  reply ((xdrproc_t) &xdr_guestfs_part_get_name_ret, (char *) &ret);
  free (r);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_part_get_name_args, (char *) &args);
done_no_free:
  return;
}

static void
blkdiscard_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_blkdiscard_args args;
  CLEANUP_FREE char *device = NULL;

  /* The caller should have checked before calling this. */
  if (! optgroup_blkdiscard_available ()) {
    reply_with_unavailable_feature ("blkdiscard");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_blkdiscard_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args.device, device, , goto done);

  r = do_blkdiscard (device);
  if (r == -1)
    /* do_blkdiscard has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_blkdiscard_args, (char *) &args);
done_no_free:
  return;
}

static void
blkdiscardzeroes_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_blkdiscardzeroes_args args;
  CLEANUP_FREE char *device = NULL;

  /* The caller should have checked before calling this. */
  if (! optgroup_blkdiscardzeroes_available ()) {
    reply_with_unavailable_feature ("blkdiscardzeroes");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_blkdiscardzeroes_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args.device, device, , goto done);

  r = do_blkdiscardzeroes (device);
  if (r == -1)
    /* do_blkdiscardzeroes has already called reply_with_error */
    goto done;

  struct guestfs_blkdiscardzeroes_ret ret;
  ret.zeroes = r;
  reply ((xdrproc_t) &xdr_guestfs_blkdiscardzeroes_ret, (char *) &ret);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_blkdiscardzeroes_args, (char *) &args);
done_no_free:
  return;
}

static void
cpio_out_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_cpio_out_args args;
  const char *directory;
  const char *format;

  if (optargs_bitmask & UINT64_C(0xfffffffffffffffe)) {
    reply_with_error ("unknown option in optional arguments bitmask (this can happen if a program is compiled against a newer version of libguestfs, then run against an older version of the daemon)");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_cpio_out_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  directory = args.directory;
  format = args.format;

  r = do_cpio_out (directory, format);
  if (r == -1)
    /* do_cpio_out has already called reply_with_error */
    goto done;

  /* do_cpio_out has already sent a reply */
done:
  xdr_free ((xdrproc_t) xdr_guestfs_cpio_out_args, (char *) &args);
done_no_free:
  return;
}

static void
journal_get_realtime_usec_stub (XDR *xdr_in)
{
  int64_t r;

  /* The caller should have checked before calling this. */
  if (! optgroup_journal_available ()) {
    reply_with_unavailable_feature ("journal");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  r = do_journal_get_realtime_usec ();
  if (r == -1)
    /* do_journal_get_realtime_usec has already called reply_with_error */
    goto done;

  struct guestfs_journal_get_realtime_usec_ret ret;
  ret.usec = r;
  reply ((xdrproc_t) &xdr_guestfs_journal_get_realtime_usec_ret, (char *) &ret);
done:
done_no_free:
  return;
}

static void
statns_stub (XDR *xdr_in)
{
  guestfs_int_statns *r;
  struct guestfs_statns_args args;
  const char *path;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_statns_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  path = args.path;
  ABS_PATH (path, , goto done);

  NEED_ROOT (, goto done);
  r = do_statns (path);
  if (r == NULL)
    /* do_statns has already called reply_with_error */
    goto done;

  struct guestfs_statns_ret ret;
  ret.statbuf = *r;
  free (r);
  reply ((xdrproc_t) xdr_guestfs_statns_ret, (char *) &ret);
  xdr_free ((xdrproc_t) xdr_guestfs_statns_ret, (char *) &ret);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_statns_args, (char *) &args);
done_no_free:
  return;
}

static void
lstatns_stub (XDR *xdr_in)
{
  guestfs_int_statns *r;
  struct guestfs_lstatns_args args;
  const char *path;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_lstatns_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  path = args.path;
  ABS_PATH (path, , goto done);

  NEED_ROOT (, goto done);
  r = do_lstatns (path);
  if (r == NULL)
    /* do_lstatns has already called reply_with_error */
    goto done;

  struct guestfs_lstatns_ret ret;
  ret.statbuf = *r;
  free (r);
  reply ((xdrproc_t) xdr_guestfs_lstatns_ret, (char *) &ret);
  xdr_free ((xdrproc_t) xdr_guestfs_lstatns_ret, (char *) &ret);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_lstatns_args, (char *) &args);
done_no_free:
  return;
}

static void
internal_lstatnslist_stub (XDR *xdr_in)
{
  guestfs_int_statns_list *r;
  struct guestfs_internal_lstatnslist_args args;
  const char *path;
  char **names;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_internal_lstatnslist_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  path = args.path;
  ABS_PATH (path, , goto done);
  /* Ugly, but safe and avoids copying the strings. */
  names = realloc (args.names.names_val,
                sizeof (char *) * (args.names.names_len+1));
  if (names == NULL) {
    reply_with_perror ("realloc");
    goto done;
  }
  names[args.names.names_len] = NULL;
  args.names.names_val = names;

  NEED_ROOT (, goto done);
  r = do_internal_lstatnslist (path, names);
  if (r == NULL)
    /* do_internal_lstatnslist has already called reply_with_error */
    goto done;

  struct guestfs_internal_lstatnslist_ret ret;
  ret.statbufs = *r;
  free (r);
  reply ((xdrproc_t) xdr_guestfs_internal_lstatnslist_ret, (char *) &ret);
  xdr_free ((xdrproc_t) xdr_guestfs_internal_lstatnslist_ret, (char *) &ret);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_internal_lstatnslist_args, (char *) &args);
done_no_free:
  return;
}

static void
blockdev_setra_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_blockdev_setra_args args;
  CLEANUP_FREE char *device = NULL;
  int sectors;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_blockdev_setra_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args.device, device, , goto done);
  sectors = args.sectors;

  r = do_blockdev_setra (device, sectors);
  if (r == -1)
    /* do_blockdev_setra has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_blockdev_setra_args, (char *) &args);
done_no_free:
  return;
}

static void
btrfs_subvolume_get_default_stub (XDR *xdr_in)
{
  int64_t r;
  struct guestfs_btrfs_subvolume_get_default_args args;
  CLEANUP_FREE_MOUNTABLE mountable_t fs
      = { .device = NULL, .volume = NULL };

  /* The caller should have checked before calling this. */
  if (! optgroup_btrfs_available ()) {
    reply_with_unavailable_feature ("btrfs");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_btrfs_subvolume_get_default_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  REQUIRE_ROOT_OR_RESOLVE_MOUNTABLE (args.fs, fs, , goto done);

  r = do_btrfs_subvolume_get_default (&fs);
  if (r == -1)
    /* do_btrfs_subvolume_get_default has already called reply_with_error */
    goto done;

  struct guestfs_btrfs_subvolume_get_default_ret ret;
  ret.id = r;
  reply ((xdrproc_t) &xdr_guestfs_btrfs_subvolume_get_default_ret, (char *) &ret);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_btrfs_subvolume_get_default_args, (char *) &args);
done_no_free:
  return;
}

static void
btrfs_subvolume_show_stub (XDR *xdr_in)
{
  char **r;
  struct guestfs_btrfs_subvolume_show_args args;
  const char *subvolume;

  /* The caller should have checked before calling this. */
  if (! optgroup_btrfs_available ()) {
    reply_with_unavailable_feature ("btrfs");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_btrfs_subvolume_show_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  subvolume = args.subvolume;
  ABS_PATH (subvolume, , goto done);

  NEED_ROOT (, goto done);
  r = do_btrfs_subvolume_show (subvolume);
  if (r == NULL)
    /* do_btrfs_subvolume_show has already called reply_with_error */
    goto done;

  struct guestfs_btrfs_subvolume_show_ret ret;
  ret.btrfssubvolumeinfo.btrfssubvolumeinfo_len = count_strings (r);
  ret.btrfssubvolumeinfo.btrfssubvolumeinfo_val = r;
  reply ((xdrproc_t) &xdr_guestfs_btrfs_subvolume_show_ret, (char *) &ret);
  free_strings (r);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_btrfs_subvolume_show_args, (char *) &args);
done_no_free:
  return;
}

static void
btrfs_quota_enable_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_btrfs_quota_enable_args args;
  CLEANUP_FREE_MOUNTABLE mountable_t fs
      = { .device = NULL, .volume = NULL };
  int enable;

  /* The caller should have checked before calling this. */
  if (! optgroup_btrfs_available ()) {
    reply_with_unavailable_feature ("btrfs");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_btrfs_quota_enable_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  REQUIRE_ROOT_OR_RESOLVE_MOUNTABLE (args.fs, fs, , goto done);
  enable = args.enable;

  r = do_btrfs_quota_enable (&fs, enable);
  if (r == -1)
    /* do_btrfs_quota_enable has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_btrfs_quota_enable_args, (char *) &args);
done_no_free:
  return;
}

static void
btrfs_quota_rescan_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_btrfs_quota_rescan_args args;
  CLEANUP_FREE_MOUNTABLE mountable_t fs
      = { .device = NULL, .volume = NULL };

  /* The caller should have checked before calling this. */
  if (! optgroup_btrfs_available ()) {
    reply_with_unavailable_feature ("btrfs");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_btrfs_quota_rescan_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  REQUIRE_ROOT_OR_RESOLVE_MOUNTABLE (args.fs, fs, , goto done);

  r = do_btrfs_quota_rescan (&fs);
  if (r == -1)
    /* do_btrfs_quota_rescan has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_btrfs_quota_rescan_args, (char *) &args);
done_no_free:
  return;
}

static void
btrfs_qgroup_limit_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_btrfs_qgroup_limit_args args;
  const char *subvolume;
  int64_t size;

  /* The caller should have checked before calling this. */
  if (! optgroup_btrfs_available ()) {
    reply_with_unavailable_feature ("btrfs");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_btrfs_qgroup_limit_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  subvolume = args.subvolume;
  ABS_PATH (subvolume, , goto done);
  size = args.size;

  NEED_ROOT (, goto done);
  r = do_btrfs_qgroup_limit (subvolume, size);
  if (r == -1)
    /* do_btrfs_qgroup_limit has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_btrfs_qgroup_limit_args, (char *) &args);
done_no_free:
  return;
}

static void
btrfs_qgroup_create_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_btrfs_qgroup_create_args args;
  const char *qgroupid;
  const char *subvolume;

  /* The caller should have checked before calling this. */
  if (! optgroup_btrfs_available ()) {
    reply_with_unavailable_feature ("btrfs");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_btrfs_qgroup_create_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  qgroupid = args.qgroupid;
  subvolume = args.subvolume;
  ABS_PATH (subvolume, , goto done);

  NEED_ROOT (, goto done);
  r = do_btrfs_qgroup_create (qgroupid, subvolume);
  if (r == -1)
    /* do_btrfs_qgroup_create has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_btrfs_qgroup_create_args, (char *) &args);
done_no_free:
  return;
}

static void
btrfs_qgroup_destroy_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_btrfs_qgroup_destroy_args args;
  const char *qgroupid;
  const char *subvolume;

  /* The caller should have checked before calling this. */
  if (! optgroup_btrfs_available ()) {
    reply_with_unavailable_feature ("btrfs");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_btrfs_qgroup_destroy_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  qgroupid = args.qgroupid;
  subvolume = args.subvolume;
  ABS_PATH (subvolume, , goto done);

  NEED_ROOT (, goto done);
  r = do_btrfs_qgroup_destroy (qgroupid, subvolume);
  if (r == -1)
    /* do_btrfs_qgroup_destroy has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_btrfs_qgroup_destroy_args, (char *) &args);
done_no_free:
  return;
}

static void
btrfs_qgroup_show_stub (XDR *xdr_in)
{
  guestfs_int_btrfsqgroup_list *r;
  struct guestfs_btrfs_qgroup_show_args args;
  const char *path;

  /* The caller should have checked before calling this. */
  if (! optgroup_btrfs_available ()) {
    reply_with_unavailable_feature ("btrfs");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_btrfs_qgroup_show_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  path = args.path;
  ABS_PATH (path, , goto done);

  NEED_ROOT (, goto done);
  r = do_btrfs_qgroup_show (path);
  if (r == NULL)
    /* do_btrfs_qgroup_show has already called reply_with_error */
    goto done;

  struct guestfs_btrfs_qgroup_show_ret ret;
  ret.qgroups = *r;
  free (r);
  reply ((xdrproc_t) xdr_guestfs_btrfs_qgroup_show_ret, (char *) &ret);
  xdr_free ((xdrproc_t) xdr_guestfs_btrfs_qgroup_show_ret, (char *) &ret);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_btrfs_qgroup_show_args, (char *) &args);
done_no_free:
  return;
}

static void
btrfs_qgroup_assign_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_btrfs_qgroup_assign_args args;
  const char *src;
  const char *dst;
  const char *path;

  /* The caller should have checked before calling this. */
  if (! optgroup_btrfs_available ()) {
    reply_with_unavailable_feature ("btrfs");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_btrfs_qgroup_assign_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  src = args.src;
  dst = args.dst;
  path = args.path;
  ABS_PATH (path, , goto done);

  NEED_ROOT (, goto done);
  r = do_btrfs_qgroup_assign (src, dst, path);
  if (r == -1)
    /* do_btrfs_qgroup_assign has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_btrfs_qgroup_assign_args, (char *) &args);
done_no_free:
  return;
}

static void
btrfs_qgroup_remove_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_btrfs_qgroup_remove_args args;
  const char *src;
  const char *dst;
  const char *path;

  /* The caller should have checked before calling this. */
  if (! optgroup_btrfs_available ()) {
    reply_with_unavailable_feature ("btrfs");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_btrfs_qgroup_remove_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  src = args.src;
  dst = args.dst;
  path = args.path;
  ABS_PATH (path, , goto done);

  NEED_ROOT (, goto done);
  r = do_btrfs_qgroup_remove (src, dst, path);
  if (r == -1)
    /* do_btrfs_qgroup_remove has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_btrfs_qgroup_remove_args, (char *) &args);
done_no_free:
  return;
}

static void
btrfs_scrub_start_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_btrfs_scrub_start_args args;
  const char *path;

  /* The caller should have checked before calling this. */
  if (! optgroup_btrfs_available ()) {
    reply_with_unavailable_feature ("btrfs");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_btrfs_scrub_start_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  path = args.path;
  ABS_PATH (path, , goto done);

  NEED_ROOT (, goto done);
  r = do_btrfs_scrub_start (path);
  if (r == -1)
    /* do_btrfs_scrub_start has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_btrfs_scrub_start_args, (char *) &args);
done_no_free:
  return;
}

static void
btrfs_scrub_cancel_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_btrfs_scrub_cancel_args args;
  const char *path;

  /* The caller should have checked before calling this. */
  if (! optgroup_btrfs_available ()) {
    reply_with_unavailable_feature ("btrfs");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_btrfs_scrub_cancel_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  path = args.path;
  ABS_PATH (path, , goto done);

  NEED_ROOT (, goto done);
  r = do_btrfs_scrub_cancel (path);
  if (r == -1)
    /* do_btrfs_scrub_cancel has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_btrfs_scrub_cancel_args, (char *) &args);
done_no_free:
  return;
}

static void
btrfs_scrub_resume_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_btrfs_scrub_resume_args args;
  const char *path;

  /* The caller should have checked before calling this. */
  if (! optgroup_btrfs_available ()) {
    reply_with_unavailable_feature ("btrfs");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_btrfs_scrub_resume_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  path = args.path;
  ABS_PATH (path, , goto done);

  NEED_ROOT (, goto done);
  r = do_btrfs_scrub_resume (path);
  if (r == -1)
    /* do_btrfs_scrub_resume has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_btrfs_scrub_resume_args, (char *) &args);
done_no_free:
  return;
}

static void
btrfs_balance_pause_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_btrfs_balance_pause_args args;
  const char *path;

  /* The caller should have checked before calling this. */
  if (! optgroup_btrfs_available ()) {
    reply_with_unavailable_feature ("btrfs");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_btrfs_balance_pause_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  path = args.path;
  ABS_PATH (path, , goto done);

  NEED_ROOT (, goto done);
  r = do_btrfs_balance_pause (path);
  if (r == -1)
    /* do_btrfs_balance_pause has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_btrfs_balance_pause_args, (char *) &args);
done_no_free:
  return;
}

static void
btrfs_balance_cancel_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_btrfs_balance_cancel_args args;
  const char *path;

  /* The caller should have checked before calling this. */
  if (! optgroup_btrfs_available ()) {
    reply_with_unavailable_feature ("btrfs");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_btrfs_balance_cancel_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  path = args.path;
  ABS_PATH (path, , goto done);

  NEED_ROOT (, goto done);
  r = do_btrfs_balance_cancel (path);
  if (r == -1)
    /* do_btrfs_balance_cancel has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_btrfs_balance_cancel_args, (char *) &args);
done_no_free:
  return;
}

static void
btrfs_balance_resume_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_btrfs_balance_resume_args args;
  const char *path;

  /* The caller should have checked before calling this. */
  if (! optgroup_btrfs_available ()) {
    reply_with_unavailable_feature ("btrfs");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_btrfs_balance_resume_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  path = args.path;
  ABS_PATH (path, , goto done);

  NEED_ROOT (, goto done);
  r = do_btrfs_balance_resume (path);
  if (r == -1)
    /* do_btrfs_balance_resume has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_btrfs_balance_resume_args, (char *) &args);
done_no_free:
  return;
}

static void
btrfs_filesystem_defragment_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_btrfs_filesystem_defragment_args args;
  const char *path;
  int flush;
  const char *compress;

  /* The caller should have checked before calling this. */
  if (! optgroup_btrfs_available ()) {
    reply_with_unavailable_feature ("btrfs");
    goto done_no_free;
  }

  if (optargs_bitmask & UINT64_C(0xfffffffffffffffc)) {
    reply_with_error ("unknown option in optional arguments bitmask (this can happen if a program is compiled against a newer version of libguestfs, then run against an older version of the daemon)");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_btrfs_filesystem_defragment_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  path = args.path;
  ABS_PATH (path, , goto done);
  flush = args.flush;
  compress = args.compress;

  NEED_ROOT (, goto done);
  r = do_btrfs_filesystem_defragment (path, flush, compress);
  if (r == -1)
    /* do_btrfs_filesystem_defragment has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_btrfs_filesystem_defragment_args, (char *) &args);
done_no_free:
  return;
}

static void
btrfs_rescue_chunk_recover_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_btrfs_rescue_chunk_recover_args args;
  CLEANUP_FREE char *device = NULL;

  /* The caller should have checked before calling this. */
  if (! optgroup_btrfs_available ()) {
    reply_with_unavailable_feature ("btrfs");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_btrfs_rescue_chunk_recover_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args.device, device, , goto done);

  r = do_btrfs_rescue_chunk_recover (device);
  if (r == -1)
    /* do_btrfs_rescue_chunk_recover has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_btrfs_rescue_chunk_recover_args, (char *) &args);
done_no_free:
  return;
}

static void
btrfs_rescue_super_recover_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_btrfs_rescue_super_recover_args args;
  CLEANUP_FREE char *device = NULL;

  /* The caller should have checked before calling this. */
  if (! optgroup_btrfs_available ()) {
    reply_with_unavailable_feature ("btrfs");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_btrfs_rescue_super_recover_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args.device, device, , goto done);

  r = do_btrfs_rescue_super_recover (device);
  if (r == -1)
    /* do_btrfs_rescue_super_recover has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_btrfs_rescue_super_recover_args, (char *) &args);
done_no_free:
  return;
}

static void
part_set_gpt_guid_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_part_set_gpt_guid_args args;
  CLEANUP_FREE char *device = NULL;
  int partnum;
  const char *guid;

  /* The caller should have checked before calling this. */
  if (! optgroup_gdisk_available ()) {
    reply_with_unavailable_feature ("gdisk");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_part_set_gpt_guid_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args.device, device, , goto done);
  partnum = args.partnum;
  guid = args.guid;

  r = do_part_set_gpt_guid (device, partnum, guid);
  if (r == -1)
    /* do_part_set_gpt_guid has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_part_set_gpt_guid_args, (char *) &args);
done_no_free:
  return;
}

static void
part_get_gpt_guid_stub (XDR *xdr_in)
{
  char *r;
  struct guestfs_part_get_gpt_guid_args args;
  CLEANUP_FREE char *device = NULL;
  int partnum;

  /* The caller should have checked before calling this. */
  if (! optgroup_gdisk_available ()) {
    reply_with_unavailable_feature ("gdisk");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_part_get_gpt_guid_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args.device, device, , goto done);
  partnum = args.partnum;

  r = do_part_get_gpt_guid (device, partnum);
  if (r == NULL)
    /* do_part_get_gpt_guid has already called reply_with_error */
    goto done;

  struct guestfs_part_get_gpt_guid_ret ret;
  ret.guid = r;
  reply ((xdrproc_t) &xdr_guestfs_part_get_gpt_guid_ret, (char *) &ret);
  free (r);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_part_get_gpt_guid_args, (char *) &args);
done_no_free:
  return;
}

static void
btrfs_balance_status_stub (XDR *xdr_in)
{
  guestfs_int_btrfsbalance *r;
  struct guestfs_btrfs_balance_status_args args;
  const char *path;

  /* The caller should have checked before calling this. */
  if (! optgroup_btrfs_available ()) {
    reply_with_unavailable_feature ("btrfs");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_btrfs_balance_status_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  path = args.path;
  ABS_PATH (path, , goto done);

  NEED_ROOT (, goto done);
  r = do_btrfs_balance_status (path);
  if (r == NULL)
    /* do_btrfs_balance_status has already called reply_with_error */
    goto done;

  struct guestfs_btrfs_balance_status_ret ret;
  ret.status = *r;
  free (r);
  reply ((xdrproc_t) xdr_guestfs_btrfs_balance_status_ret, (char *) &ret);
  xdr_free ((xdrproc_t) xdr_guestfs_btrfs_balance_status_ret, (char *) &ret);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_btrfs_balance_status_args, (char *) &args);
done_no_free:
  return;
}

static void
btrfs_scrub_status_stub (XDR *xdr_in)
{
  guestfs_int_btrfsscrub *r;
  struct guestfs_btrfs_scrub_status_args args;
  const char *path;

  /* The caller should have checked before calling this. */
  if (! optgroup_btrfs_available ()) {
    reply_with_unavailable_feature ("btrfs");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_btrfs_scrub_status_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  path = args.path;
  ABS_PATH (path, , goto done);

  NEED_ROOT (, goto done);
  r = do_btrfs_scrub_status (path);
  if (r == NULL)
    /* do_btrfs_scrub_status has already called reply_with_error */
    goto done;

  struct guestfs_btrfs_scrub_status_ret ret;
  ret.status = *r;
  free (r);
  reply ((xdrproc_t) xdr_guestfs_btrfs_scrub_status_ret, (char *) &ret);
  xdr_free ((xdrproc_t) xdr_guestfs_btrfs_scrub_status_ret, (char *) &ret);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_btrfs_scrub_status_args, (char *) &args);
done_no_free:
  return;
}

static void
btrfstune_seeding_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_btrfstune_seeding_args args;
  CLEANUP_FREE char *device = NULL;
  int seeding;

  /* The caller should have checked before calling this. */
  if (! optgroup_btrfs_available ()) {
    reply_with_unavailable_feature ("btrfs");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_btrfstune_seeding_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args.device, device, , goto done);
  seeding = args.seeding;

  r = do_btrfstune_seeding (device, seeding);
  if (r == -1)
    /* do_btrfstune_seeding has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_btrfstune_seeding_args, (char *) &args);
done_no_free:
  return;
}

static void
btrfstune_enable_extended_inode_refs_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_btrfstune_enable_extended_inode_refs_args args;
  CLEANUP_FREE char *device = NULL;

  /* The caller should have checked before calling this. */
  if (! optgroup_btrfs_available ()) {
    reply_with_unavailable_feature ("btrfs");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_btrfstune_enable_extended_inode_refs_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args.device, device, , goto done);

  r = do_btrfstune_enable_extended_inode_refs (device);
  if (r == -1)
    /* do_btrfstune_enable_extended_inode_refs has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_btrfstune_enable_extended_inode_refs_args, (char *) &args);
done_no_free:
  return;
}

static void
btrfstune_enable_skinny_metadata_extent_refs_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_btrfstune_enable_skinny_metadata_extent_refs_args args;
  CLEANUP_FREE char *device = NULL;

  /* The caller should have checked before calling this. */
  if (! optgroup_btrfs_available ()) {
    reply_with_unavailable_feature ("btrfs");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_btrfstune_enable_skinny_metadata_extent_refs_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args.device, device, , goto done);

  r = do_btrfstune_enable_skinny_metadata_extent_refs (device);
  if (r == -1)
    /* do_btrfstune_enable_skinny_metadata_extent_refs has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_btrfstune_enable_skinny_metadata_extent_refs_args, (char *) &args);
done_no_free:
  return;
}

static void
btrfs_image_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_btrfs_image_args args;
  CLEANUP_FREE_STRING_LIST char **source = NULL;
  const char *image;
  int compresslevel;

  /* The caller should have checked before calling this. */
  if (! optgroup_btrfs_available ()) {
    reply_with_unavailable_feature ("btrfs");
    goto done_no_free;
  }

  if (optargs_bitmask & UINT64_C(0xfffffffffffffffe)) {
    reply_with_error ("unknown option in optional arguments bitmask (this can happen if a program is compiled against a newer version of libguestfs, then run against an older version of the daemon)");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_btrfs_image_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  /* Copy the string list and apply device name translation
   * to each one.
   */
  source = calloc (args.source.source_len+1, sizeof (char *));
  {
    size_t i;
    for (i = 0; i < args.source.source_len; ++i)
      RESOLVE_DEVICE (args.source.source_val[i], source[i],
                      , goto done);
    source[i] = NULL;
  }
  image = args.image;
  ABS_PATH (image, , goto done);
  compresslevel = args.compresslevel;

  NEED_ROOT (, goto done);
  r = do_btrfs_image (source, image, compresslevel);
  if (r == -1)
    /* do_btrfs_image has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_btrfs_image_args, (char *) &args);
done_no_free:
  return;
}

static void
part_get_mbr_part_type_stub (XDR *xdr_in)
{
  char *r;
  struct guestfs_part_get_mbr_part_type_args args;
  CLEANUP_FREE char *device = NULL;
  int partnum;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_part_get_mbr_part_type_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args.device, device, , goto done);
  partnum = args.partnum;

  r = do_part_get_mbr_part_type (device, partnum);
  if (r == NULL)
    /* do_part_get_mbr_part_type has already called reply_with_error */
    goto done;

  struct guestfs_part_get_mbr_part_type_ret ret;
  ret.partitiontype = r;
  reply ((xdrproc_t) &xdr_guestfs_part_get_mbr_part_type_ret, (char *) &ret);
  free (r);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_part_get_mbr_part_type_args, (char *) &args);
done_no_free:
  return;
}

static void
btrfs_replace_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_btrfs_replace_args args;
  CLEANUP_FREE char *srcdev = NULL;
  CLEANUP_FREE char *targetdev = NULL;
  const char *mntpoint;

  /* The caller should have checked before calling this. */
  if (! optgroup_btrfs_available ()) {
    reply_with_unavailable_feature ("btrfs");
    goto done_no_free;
  }

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_btrfs_replace_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args.srcdev, srcdev, , goto done);
  RESOLVE_DEVICE (args.targetdev, targetdev, , goto done);
  mntpoint = args.mntpoint;
  ABS_PATH (mntpoint, , goto done);

  NEED_ROOT (, goto done);
  r = do_btrfs_replace (srcdev, targetdev, mntpoint);
  if (r == -1)
    /* do_btrfs_replace has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_btrfs_replace_args, (char *) &args);
done_no_free:
  return;
}

static void
set_uuid_random_stub (XDR *xdr_in)
{
  int r;
  struct guestfs_set_uuid_random_args args;
  CLEANUP_FREE char *device = NULL;

  if (optargs_bitmask != 0) {
    reply_with_error ("header optargs_bitmask field must be passed as 0 for calls that don't take optional arguments");
    goto done_no_free;
  }

  memset (&args, 0, sizeof args);

  if (!xdr_guestfs_set_uuid_random_args (xdr_in, &args)) {
    reply_with_error ("daemon failed to decode procedure arguments");
    goto done;
  }
  RESOLVE_DEVICE (args.device, device, , goto done);

  r = do_set_uuid_random (device);
  if (r == -1)
    /* do_set_uuid_random has already called reply_with_error */
    goto done;

  reply (NULL, NULL);
done:
  xdr_free ((xdrproc_t) xdr_guestfs_set_uuid_random_args, (char *) &args);
done_no_free:
  return;
}

void dispatch_incoming_message (XDR *xdr_in)
{
  switch (proc_nr) {
    case GUESTFS_PROC_MOUNT:
      mount_stub (xdr_in);
      break;
    case GUESTFS_PROC_SYNC:
      sync_stub (xdr_in);
      break;
    case GUESTFS_PROC_TOUCH:
      touch_stub (xdr_in);
      break;
    case GUESTFS_PROC_LL:
      ll_stub (xdr_in);
      break;
    case GUESTFS_PROC_LIST_DEVICES:
      list_devices_stub (xdr_in);
      break;
    case GUESTFS_PROC_LIST_PARTITIONS:
      list_partitions_stub (xdr_in);
      break;
    case GUESTFS_PROC_PVS:
      pvs_stub (xdr_in);
      break;
    case GUESTFS_PROC_VGS:
      vgs_stub (xdr_in);
      break;
    case GUESTFS_PROC_LVS:
      lvs_stub (xdr_in);
      break;
    case GUESTFS_PROC_PVS_FULL:
      pvs_full_stub (xdr_in);
      break;
    case GUESTFS_PROC_VGS_FULL:
      vgs_full_stub (xdr_in);
      break;
    case GUESTFS_PROC_LVS_FULL:
      lvs_full_stub (xdr_in);
      break;
    case GUESTFS_PROC_AUG_INIT:
      aug_init_stub (xdr_in);
      break;
    case GUESTFS_PROC_AUG_CLOSE:
      aug_close_stub (xdr_in);
      break;
    case GUESTFS_PROC_AUG_DEFVAR:
      aug_defvar_stub (xdr_in);
      break;
    case GUESTFS_PROC_AUG_DEFNODE:
      aug_defnode_stub (xdr_in);
      break;
    case GUESTFS_PROC_AUG_GET:
      aug_get_stub (xdr_in);
      break;
    case GUESTFS_PROC_AUG_SET:
      aug_set_stub (xdr_in);
      break;
    case GUESTFS_PROC_AUG_INSERT:
      aug_insert_stub (xdr_in);
      break;
    case GUESTFS_PROC_AUG_RM:
      aug_rm_stub (xdr_in);
      break;
    case GUESTFS_PROC_AUG_MV:
      aug_mv_stub (xdr_in);
      break;
    case GUESTFS_PROC_AUG_MATCH:
      aug_match_stub (xdr_in);
      break;
    case GUESTFS_PROC_AUG_SAVE:
      aug_save_stub (xdr_in);
      break;
    case GUESTFS_PROC_AUG_LOAD:
      aug_load_stub (xdr_in);
      break;
    case GUESTFS_PROC_AUG_LS:
      aug_ls_stub (xdr_in);
      break;
    case GUESTFS_PROC_RM:
      rm_stub (xdr_in);
      break;
    case GUESTFS_PROC_RMDIR:
      rmdir_stub (xdr_in);
      break;
    case GUESTFS_PROC_RM_RF:
      rm_rf_stub (xdr_in);
      break;
    case GUESTFS_PROC_MKDIR:
      mkdir_stub (xdr_in);
      break;
    case GUESTFS_PROC_MKDIR_P:
      mkdir_p_stub (xdr_in);
      break;
    case GUESTFS_PROC_CHMOD:
      chmod_stub (xdr_in);
      break;
    case GUESTFS_PROC_CHOWN:
      chown_stub (xdr_in);
      break;
    case GUESTFS_PROC_EXISTS:
      exists_stub (xdr_in);
      break;
    case GUESTFS_PROC_IS_FILE:
      is_file_stub (xdr_in);
      break;
    case GUESTFS_PROC_IS_DIR:
      is_dir_stub (xdr_in);
      break;
    case GUESTFS_PROC_PVCREATE:
      pvcreate_stub (xdr_in);
      break;
    case GUESTFS_PROC_VGCREATE:
      vgcreate_stub (xdr_in);
      break;
    case GUESTFS_PROC_LVCREATE:
      lvcreate_stub (xdr_in);
      break;
    case GUESTFS_PROC_SFDISK:
      sfdisk_stub (xdr_in);
      break;
    case GUESTFS_PROC_WRITE_FILE:
      write_file_stub (xdr_in);
      break;
    case GUESTFS_PROC_UMOUNT:
      umount_stub (xdr_in);
      break;
    case GUESTFS_PROC_MOUNTS:
      mounts_stub (xdr_in);
      break;
    case GUESTFS_PROC_UMOUNT_ALL:
      umount_all_stub (xdr_in);
      break;
    case GUESTFS_PROC_LVM_REMOVE_ALL:
      lvm_remove_all_stub (xdr_in);
      break;
    case GUESTFS_PROC_FILE:
      file_stub (xdr_in);
      break;
    case GUESTFS_PROC_COMMAND:
      command_stub (xdr_in);
      break;
    case GUESTFS_PROC_COMMAND_LINES:
      command_lines_stub (xdr_in);
      break;
    case GUESTFS_PROC_STATVFS:
      statvfs_stub (xdr_in);
      break;
    case GUESTFS_PROC_TUNE2FS_L:
      tune2fs_l_stub (xdr_in);
      break;
    case GUESTFS_PROC_BLOCKDEV_SETRO:
      blockdev_setro_stub (xdr_in);
      break;
    case GUESTFS_PROC_BLOCKDEV_SETRW:
      blockdev_setrw_stub (xdr_in);
      break;
    case GUESTFS_PROC_BLOCKDEV_GETRO:
      blockdev_getro_stub (xdr_in);
      break;
    case GUESTFS_PROC_BLOCKDEV_GETSS:
      blockdev_getss_stub (xdr_in);
      break;
    case GUESTFS_PROC_BLOCKDEV_GETBSZ:
      blockdev_getbsz_stub (xdr_in);
      break;
    case GUESTFS_PROC_BLOCKDEV_SETBSZ:
      blockdev_setbsz_stub (xdr_in);
      break;
    case GUESTFS_PROC_BLOCKDEV_GETSZ:
      blockdev_getsz_stub (xdr_in);
      break;
    case GUESTFS_PROC_BLOCKDEV_GETSIZE64:
      blockdev_getsize64_stub (xdr_in);
      break;
    case GUESTFS_PROC_BLOCKDEV_FLUSHBUFS:
      blockdev_flushbufs_stub (xdr_in);
      break;
    case GUESTFS_PROC_BLOCKDEV_REREADPT:
      blockdev_rereadpt_stub (xdr_in);
      break;
    case GUESTFS_PROC_UPLOAD:
      upload_stub (xdr_in);
      break;
    case GUESTFS_PROC_DOWNLOAD:
      download_stub (xdr_in);
      break;
    case GUESTFS_PROC_CHECKSUM:
      checksum_stub (xdr_in);
      break;
    case GUESTFS_PROC_TAR_IN:
      tar_in_stub (xdr_in);
      break;
    case GUESTFS_PROC_TAR_OUT:
      tar_out_stub (xdr_in);
      break;
    case GUESTFS_PROC_TGZ_IN:
      tgz_in_stub (xdr_in);
      break;
    case GUESTFS_PROC_TGZ_OUT:
      tgz_out_stub (xdr_in);
      break;
    case GUESTFS_PROC_MOUNT_RO:
      mount_ro_stub (xdr_in);
      break;
    case GUESTFS_PROC_MOUNT_OPTIONS:
      mount_options_stub (xdr_in);
      break;
    case GUESTFS_PROC_MOUNT_VFS:
      mount_vfs_stub (xdr_in);
      break;
    case GUESTFS_PROC_DEBUG:
      debug_stub (xdr_in);
      break;
    case GUESTFS_PROC_LVREMOVE:
      lvremove_stub (xdr_in);
      break;
    case GUESTFS_PROC_VGREMOVE:
      vgremove_stub (xdr_in);
      break;
    case GUESTFS_PROC_PVREMOVE:
      pvremove_stub (xdr_in);
      break;
    case GUESTFS_PROC_SET_E2LABEL:
      set_e2label_stub (xdr_in);
      break;
    case GUESTFS_PROC_GET_E2LABEL:
      get_e2label_stub (xdr_in);
      break;
    case GUESTFS_PROC_SET_E2UUID:
      set_e2uuid_stub (xdr_in);
      break;
    case GUESTFS_PROC_GET_E2UUID:
      get_e2uuid_stub (xdr_in);
      break;
    case GUESTFS_PROC_FSCK:
      fsck_stub (xdr_in);
      break;
    case GUESTFS_PROC_ZERO:
      zero_stub (xdr_in);
      break;
    case GUESTFS_PROC_GRUB_INSTALL:
      grub_install_stub (xdr_in);
      break;
    case GUESTFS_PROC_CP:
      cp_stub (xdr_in);
      break;
    case GUESTFS_PROC_CP_A:
      cp_a_stub (xdr_in);
      break;
    case GUESTFS_PROC_MV:
      mv_stub (xdr_in);
      break;
    case GUESTFS_PROC_DROP_CACHES:
      drop_caches_stub (xdr_in);
      break;
    case GUESTFS_PROC_DMESG:
      dmesg_stub (xdr_in);
      break;
    case GUESTFS_PROC_PING_DAEMON:
      ping_daemon_stub (xdr_in);
      break;
    case GUESTFS_PROC_EQUAL:
      equal_stub (xdr_in);
      break;
    case GUESTFS_PROC_STRINGS:
      strings_stub (xdr_in);
      break;
    case GUESTFS_PROC_STRINGS_E:
      strings_e_stub (xdr_in);
      break;
    case GUESTFS_PROC_HEXDUMP:
      hexdump_stub (xdr_in);
      break;
    case GUESTFS_PROC_ZEROFREE:
      zerofree_stub (xdr_in);
      break;
    case GUESTFS_PROC_PVRESIZE:
      pvresize_stub (xdr_in);
      break;
    case GUESTFS_PROC_SFDISK_N:
      sfdisk_N_stub (xdr_in);
      break;
    case GUESTFS_PROC_SFDISK_L:
      sfdisk_l_stub (xdr_in);
      break;
    case GUESTFS_PROC_SFDISK_KERNEL_GEOMETRY:
      sfdisk_kernel_geometry_stub (xdr_in);
      break;
    case GUESTFS_PROC_SFDISK_DISK_GEOMETRY:
      sfdisk_disk_geometry_stub (xdr_in);
      break;
    case GUESTFS_PROC_VG_ACTIVATE_ALL:
      vg_activate_all_stub (xdr_in);
      break;
    case GUESTFS_PROC_VG_ACTIVATE:
      vg_activate_stub (xdr_in);
      break;
    case GUESTFS_PROC_LVRESIZE:
      lvresize_stub (xdr_in);
      break;
    case GUESTFS_PROC_RESIZE2FS:
      resize2fs_stub (xdr_in);
      break;
    case GUESTFS_PROC_E2FSCK_F:
      e2fsck_f_stub (xdr_in);
      break;
    case GUESTFS_PROC_SLEEP:
      sleep_stub (xdr_in);
      break;
    case GUESTFS_PROC_NTFS_3G_PROBE:
      ntfs_3g_probe_stub (xdr_in);
      break;
    case GUESTFS_PROC_SH:
      sh_stub (xdr_in);
      break;
    case GUESTFS_PROC_SH_LINES:
      sh_lines_stub (xdr_in);
      break;
    case GUESTFS_PROC_GLOB_EXPAND:
      glob_expand_stub (xdr_in);
      break;
    case GUESTFS_PROC_SCRUB_DEVICE:
      scrub_device_stub (xdr_in);
      break;
    case GUESTFS_PROC_SCRUB_FILE:
      scrub_file_stub (xdr_in);
      break;
    case GUESTFS_PROC_SCRUB_FREESPACE:
      scrub_freespace_stub (xdr_in);
      break;
    case GUESTFS_PROC_MKDTEMP:
      mkdtemp_stub (xdr_in);
      break;
    case GUESTFS_PROC_WC_L:
      wc_l_stub (xdr_in);
      break;
    case GUESTFS_PROC_WC_W:
      wc_w_stub (xdr_in);
      break;
    case GUESTFS_PROC_WC_C:
      wc_c_stub (xdr_in);
      break;
    case GUESTFS_PROC_HEAD:
      head_stub (xdr_in);
      break;
    case GUESTFS_PROC_HEAD_N:
      head_n_stub (xdr_in);
      break;
    case GUESTFS_PROC_TAIL:
      tail_stub (xdr_in);
      break;
    case GUESTFS_PROC_TAIL_N:
      tail_n_stub (xdr_in);
      break;
    case GUESTFS_PROC_DF:
      df_stub (xdr_in);
      break;
    case GUESTFS_PROC_DF_H:
      df_h_stub (xdr_in);
      break;
    case GUESTFS_PROC_DU:
      du_stub (xdr_in);
      break;
    case GUESTFS_PROC_INITRD_LIST:
      initrd_list_stub (xdr_in);
      break;
    case GUESTFS_PROC_MOUNT_LOOP:
      mount_loop_stub (xdr_in);
      break;
    case GUESTFS_PROC_MKSWAP:
      mkswap_stub (xdr_in);
      break;
    case GUESTFS_PROC_MKSWAP_L:
      mkswap_L_stub (xdr_in);
      break;
    case GUESTFS_PROC_MKSWAP_U:
      mkswap_U_stub (xdr_in);
      break;
    case GUESTFS_PROC_MKNOD:
      mknod_stub (xdr_in);
      break;
    case GUESTFS_PROC_MKFIFO:
      mkfifo_stub (xdr_in);
      break;
    case GUESTFS_PROC_MKNOD_B:
      mknod_b_stub (xdr_in);
      break;
    case GUESTFS_PROC_MKNOD_C:
      mknod_c_stub (xdr_in);
      break;
    case GUESTFS_PROC_UMASK:
      umask_stub (xdr_in);
      break;
    case GUESTFS_PROC_READDIR:
      readdir_stub (xdr_in);
      break;
    case GUESTFS_PROC_SFDISKM:
      sfdiskM_stub (xdr_in);
      break;
    case GUESTFS_PROC_ZFILE:
      zfile_stub (xdr_in);
      break;
    case GUESTFS_PROC_GETXATTRS:
      getxattrs_stub (xdr_in);
      break;
    case GUESTFS_PROC_LGETXATTRS:
      lgetxattrs_stub (xdr_in);
      break;
    case GUESTFS_PROC_SETXATTR:
      setxattr_stub (xdr_in);
      break;
    case GUESTFS_PROC_LSETXATTR:
      lsetxattr_stub (xdr_in);
      break;
    case GUESTFS_PROC_REMOVEXATTR:
      removexattr_stub (xdr_in);
      break;
    case GUESTFS_PROC_LREMOVEXATTR:
      lremovexattr_stub (xdr_in);
      break;
    case GUESTFS_PROC_MOUNTPOINTS:
      mountpoints_stub (xdr_in);
      break;
    case GUESTFS_PROC_MKMOUNTPOINT:
      mkmountpoint_stub (xdr_in);
      break;
    case GUESTFS_PROC_RMMOUNTPOINT:
      rmmountpoint_stub (xdr_in);
      break;
    case GUESTFS_PROC_GREP:
      grep_stub (xdr_in);
      break;
    case GUESTFS_PROC_EGREP:
      egrep_stub (xdr_in);
      break;
    case GUESTFS_PROC_FGREP:
      fgrep_stub (xdr_in);
      break;
    case GUESTFS_PROC_GREPI:
      grepi_stub (xdr_in);
      break;
    case GUESTFS_PROC_EGREPI:
      egrepi_stub (xdr_in);
      break;
    case GUESTFS_PROC_FGREPI:
      fgrepi_stub (xdr_in);
      break;
    case GUESTFS_PROC_ZGREP:
      zgrep_stub (xdr_in);
      break;
    case GUESTFS_PROC_ZEGREP:
      zegrep_stub (xdr_in);
      break;
    case GUESTFS_PROC_ZFGREP:
      zfgrep_stub (xdr_in);
      break;
    case GUESTFS_PROC_ZGREPI:
      zgrepi_stub (xdr_in);
      break;
    case GUESTFS_PROC_ZEGREPI:
      zegrepi_stub (xdr_in);
      break;
    case GUESTFS_PROC_ZFGREPI:
      zfgrepi_stub (xdr_in);
      break;
    case GUESTFS_PROC_REALPATH:
      realpath_stub (xdr_in);
      break;
    case GUESTFS_PROC_LN:
      ln_stub (xdr_in);
      break;
    case GUESTFS_PROC_LN_F:
      ln_f_stub (xdr_in);
      break;
    case GUESTFS_PROC_LN_S:
      ln_s_stub (xdr_in);
      break;
    case GUESTFS_PROC_LN_SF:
      ln_sf_stub (xdr_in);
      break;
    case GUESTFS_PROC_READLINK:
      readlink_stub (xdr_in);
      break;
    case GUESTFS_PROC_FALLOCATE:
      fallocate_stub (xdr_in);
      break;
    case GUESTFS_PROC_SWAPON_DEVICE:
      swapon_device_stub (xdr_in);
      break;
    case GUESTFS_PROC_SWAPOFF_DEVICE:
      swapoff_device_stub (xdr_in);
      break;
    case GUESTFS_PROC_SWAPON_FILE:
      swapon_file_stub (xdr_in);
      break;
    case GUESTFS_PROC_SWAPOFF_FILE:
      swapoff_file_stub (xdr_in);
      break;
    case GUESTFS_PROC_SWAPON_LABEL:
      swapon_label_stub (xdr_in);
      break;
    case GUESTFS_PROC_SWAPOFF_LABEL:
      swapoff_label_stub (xdr_in);
      break;
    case GUESTFS_PROC_SWAPON_UUID:
      swapon_uuid_stub (xdr_in);
      break;
    case GUESTFS_PROC_SWAPOFF_UUID:
      swapoff_uuid_stub (xdr_in);
      break;
    case GUESTFS_PROC_MKSWAP_FILE:
      mkswap_file_stub (xdr_in);
      break;
    case GUESTFS_PROC_INOTIFY_INIT:
      inotify_init_stub (xdr_in);
      break;
    case GUESTFS_PROC_INOTIFY_ADD_WATCH:
      inotify_add_watch_stub (xdr_in);
      break;
    case GUESTFS_PROC_INOTIFY_RM_WATCH:
      inotify_rm_watch_stub (xdr_in);
      break;
    case GUESTFS_PROC_INOTIFY_READ:
      inotify_read_stub (xdr_in);
      break;
    case GUESTFS_PROC_INOTIFY_FILES:
      inotify_files_stub (xdr_in);
      break;
    case GUESTFS_PROC_INOTIFY_CLOSE:
      inotify_close_stub (xdr_in);
      break;
    case GUESTFS_PROC_SETCON:
      setcon_stub (xdr_in);
      break;
    case GUESTFS_PROC_GETCON:
      getcon_stub (xdr_in);
      break;
    case GUESTFS_PROC_MKFS_B:
      mkfs_b_stub (xdr_in);
      break;
    case GUESTFS_PROC_MKE2JOURNAL:
      mke2journal_stub (xdr_in);
      break;
    case GUESTFS_PROC_MKE2JOURNAL_L:
      mke2journal_L_stub (xdr_in);
      break;
    case GUESTFS_PROC_MKE2JOURNAL_U:
      mke2journal_U_stub (xdr_in);
      break;
    case GUESTFS_PROC_MKE2FS_J:
      mke2fs_J_stub (xdr_in);
      break;
    case GUESTFS_PROC_MKE2FS_JL:
      mke2fs_JL_stub (xdr_in);
      break;
    case GUESTFS_PROC_MKE2FS_JU:
      mke2fs_JU_stub (xdr_in);
      break;
    case GUESTFS_PROC_MODPROBE:
      modprobe_stub (xdr_in);
      break;
    case GUESTFS_PROC_ECHO_DAEMON:
      echo_daemon_stub (xdr_in);
      break;
    case GUESTFS_PROC_FIND0:
      find0_stub (xdr_in);
      break;
    case GUESTFS_PROC_CASE_SENSITIVE_PATH:
      case_sensitive_path_stub (xdr_in);
      break;
    case GUESTFS_PROC_VFS_TYPE:
      vfs_type_stub (xdr_in);
      break;
    case GUESTFS_PROC_TRUNCATE:
      truncate_stub (xdr_in);
      break;
    case GUESTFS_PROC_TRUNCATE_SIZE:
      truncate_size_stub (xdr_in);
      break;
    case GUESTFS_PROC_UTIMENS:
      utimens_stub (xdr_in);
      break;
    case GUESTFS_PROC_MKDIR_MODE:
      mkdir_mode_stub (xdr_in);
      break;
    case GUESTFS_PROC_LCHOWN:
      lchown_stub (xdr_in);
      break;
    case GUESTFS_PROC_INTERNAL_LXATTRLIST:
      internal_lxattrlist_stub (xdr_in);
      break;
    case GUESTFS_PROC_INTERNAL_READLINKLIST:
      internal_readlinklist_stub (xdr_in);
      break;
    case GUESTFS_PROC_PREAD:
      pread_stub (xdr_in);
      break;
    case GUESTFS_PROC_PART_INIT:
      part_init_stub (xdr_in);
      break;
    case GUESTFS_PROC_PART_ADD:
      part_add_stub (xdr_in);
      break;
    case GUESTFS_PROC_PART_DISK:
      part_disk_stub (xdr_in);
      break;
    case GUESTFS_PROC_PART_SET_BOOTABLE:
      part_set_bootable_stub (xdr_in);
      break;
    case GUESTFS_PROC_PART_SET_NAME:
      part_set_name_stub (xdr_in);
      break;
    case GUESTFS_PROC_PART_LIST:
      part_list_stub (xdr_in);
      break;
    case GUESTFS_PROC_PART_GET_PARTTYPE:
      part_get_parttype_stub (xdr_in);
      break;
    case GUESTFS_PROC_FILL:
      fill_stub (xdr_in);
      break;
    case GUESTFS_PROC_AVAILABLE:
      available_stub (xdr_in);
      break;
    case GUESTFS_PROC_DD:
      dd_stub (xdr_in);
      break;
    case GUESTFS_PROC_FILESIZE:
      filesize_stub (xdr_in);
      break;
    case GUESTFS_PROC_LVRENAME:
      lvrename_stub (xdr_in);
      break;
    case GUESTFS_PROC_VGRENAME:
      vgrename_stub (xdr_in);
      break;
    case GUESTFS_PROC_INITRD_CAT:
      initrd_cat_stub (xdr_in);
      break;
    case GUESTFS_PROC_PVUUID:
      pvuuid_stub (xdr_in);
      break;
    case GUESTFS_PROC_VGUUID:
      vguuid_stub (xdr_in);
      break;
    case GUESTFS_PROC_LVUUID:
      lvuuid_stub (xdr_in);
      break;
    case GUESTFS_PROC_VGPVUUIDS:
      vgpvuuids_stub (xdr_in);
      break;
    case GUESTFS_PROC_VGLVUUIDS:
      vglvuuids_stub (xdr_in);
      break;
    case GUESTFS_PROC_COPY_SIZE:
      copy_size_stub (xdr_in);
      break;
    case GUESTFS_PROC_ZERO_DEVICE:
      zero_device_stub (xdr_in);
      break;
    case GUESTFS_PROC_TXZ_IN:
      txz_in_stub (xdr_in);
      break;
    case GUESTFS_PROC_TXZ_OUT:
      txz_out_stub (xdr_in);
      break;
    case GUESTFS_PROC_VGSCAN:
      vgscan_stub (xdr_in);
      break;
    case GUESTFS_PROC_PART_DEL:
      part_del_stub (xdr_in);
      break;
    case GUESTFS_PROC_PART_GET_BOOTABLE:
      part_get_bootable_stub (xdr_in);
      break;
    case GUESTFS_PROC_PART_GET_MBR_ID:
      part_get_mbr_id_stub (xdr_in);
      break;
    case GUESTFS_PROC_PART_SET_MBR_ID:
      part_set_mbr_id_stub (xdr_in);
      break;
    case GUESTFS_PROC_CHECKSUM_DEVICE:
      checksum_device_stub (xdr_in);
      break;
    case GUESTFS_PROC_LVRESIZE_FREE:
      lvresize_free_stub (xdr_in);
      break;
    case GUESTFS_PROC_AUG_CLEAR:
      aug_clear_stub (xdr_in);
      break;
    case GUESTFS_PROC_GET_UMASK:
      get_umask_stub (xdr_in);
      break;
    case GUESTFS_PROC_DEBUG_UPLOAD:
      debug_upload_stub (xdr_in);
      break;
    case GUESTFS_PROC_BASE64_IN:
      base64_in_stub (xdr_in);
      break;
    case GUESTFS_PROC_BASE64_OUT:
      base64_out_stub (xdr_in);
      break;
    case GUESTFS_PROC_CHECKSUMS_OUT:
      checksums_out_stub (xdr_in);
      break;
    case GUESTFS_PROC_FILL_PATTERN:
      fill_pattern_stub (xdr_in);
      break;
    case GUESTFS_PROC_INTERNAL_WRITE:
      internal_write_stub (xdr_in);
      break;
    case GUESTFS_PROC_PWRITE:
      pwrite_stub (xdr_in);
      break;
    case GUESTFS_PROC_RESIZE2FS_SIZE:
      resize2fs_size_stub (xdr_in);
      break;
    case GUESTFS_PROC_PVRESIZE_SIZE:
      pvresize_size_stub (xdr_in);
      break;
    case GUESTFS_PROC_NTFSRESIZE_SIZE:
      ntfsresize_size_stub (xdr_in);
      break;
    case GUESTFS_PROC_AVAILABLE_ALL_GROUPS:
      available_all_groups_stub (xdr_in);
      break;
    case GUESTFS_PROC_FALLOCATE64:
      fallocate64_stub (xdr_in);
      break;
    case GUESTFS_PROC_VFS_LABEL:
      vfs_label_stub (xdr_in);
      break;
    case GUESTFS_PROC_VFS_UUID:
      vfs_uuid_stub (xdr_in);
      break;
    case GUESTFS_PROC_LVM_SET_FILTER:
      lvm_set_filter_stub (xdr_in);
      break;
    case GUESTFS_PROC_LVM_CLEAR_FILTER:
      lvm_clear_filter_stub (xdr_in);
      break;
    case GUESTFS_PROC_LUKS_OPEN:
      luks_open_stub (xdr_in);
      break;
    case GUESTFS_PROC_LUKS_OPEN_RO:
      luks_open_ro_stub (xdr_in);
      break;
    case GUESTFS_PROC_LUKS_CLOSE:
      luks_close_stub (xdr_in);
      break;
    case GUESTFS_PROC_LUKS_FORMAT:
      luks_format_stub (xdr_in);
      break;
    case GUESTFS_PROC_LUKS_FORMAT_CIPHER:
      luks_format_cipher_stub (xdr_in);
      break;
    case GUESTFS_PROC_LUKS_ADD_KEY:
      luks_add_key_stub (xdr_in);
      break;
    case GUESTFS_PROC_LUKS_KILL_SLOT:
      luks_kill_slot_stub (xdr_in);
      break;
    case GUESTFS_PROC_IS_LV:
      is_lv_stub (xdr_in);
      break;
    case GUESTFS_PROC_FINDFS_UUID:
      findfs_uuid_stub (xdr_in);
      break;
    case GUESTFS_PROC_FINDFS_LABEL:
      findfs_label_stub (xdr_in);
      break;
    case GUESTFS_PROC_IS_CHARDEV:
      is_chardev_stub (xdr_in);
      break;
    case GUESTFS_PROC_IS_BLOCKDEV:
      is_blockdev_stub (xdr_in);
      break;
    case GUESTFS_PROC_IS_FIFO:
      is_fifo_stub (xdr_in);
      break;
    case GUESTFS_PROC_IS_SYMLINK:
      is_symlink_stub (xdr_in);
      break;
    case GUESTFS_PROC_IS_SOCKET:
      is_socket_stub (xdr_in);
      break;
    case GUESTFS_PROC_PART_TO_DEV:
      part_to_dev_stub (xdr_in);
      break;
    case GUESTFS_PROC_UPLOAD_OFFSET:
      upload_offset_stub (xdr_in);
      break;
    case GUESTFS_PROC_DOWNLOAD_OFFSET:
      download_offset_stub (xdr_in);
      break;
    case GUESTFS_PROC_PWRITE_DEVICE:
      pwrite_device_stub (xdr_in);
      break;
    case GUESTFS_PROC_PREAD_DEVICE:
      pread_device_stub (xdr_in);
      break;
    case GUESTFS_PROC_LVM_CANONICAL_LV_NAME:
      lvm_canonical_lv_name_stub (xdr_in);
      break;
    case GUESTFS_PROC_MKFS:
      mkfs_stub (xdr_in);
      break;
    case GUESTFS_PROC_GETXATTR:
      getxattr_stub (xdr_in);
      break;
    case GUESTFS_PROC_LGETXATTR:
      lgetxattr_stub (xdr_in);
      break;
    case GUESTFS_PROC_RESIZE2FS_M:
      resize2fs_M_stub (xdr_in);
      break;
    case GUESTFS_PROC_INTERNAL_AUTOSYNC:
      internal_autosync_stub (xdr_in);
      break;
    case GUESTFS_PROC_IS_ZERO:
      is_zero_stub (xdr_in);
      break;
    case GUESTFS_PROC_IS_ZERO_DEVICE:
      is_zero_device_stub (xdr_in);
      break;
    case GUESTFS_PROC_LIST_9P:
      list_9p_stub (xdr_in);
      break;
    case GUESTFS_PROC_MOUNT_9P:
      mount_9p_stub (xdr_in);
      break;
    case GUESTFS_PROC_LIST_DM_DEVICES:
      list_dm_devices_stub (xdr_in);
      break;
    case GUESTFS_PROC_NTFSRESIZE:
      ntfsresize_stub (xdr_in);
      break;
    case GUESTFS_PROC_BTRFS_FILESYSTEM_RESIZE:
      btrfs_filesystem_resize_stub (xdr_in);
      break;
    case GUESTFS_PROC_INTERNAL_WRITE_APPEND:
      internal_write_append_stub (xdr_in);
      break;
    case GUESTFS_PROC_COMPRESS_OUT:
      compress_out_stub (xdr_in);
      break;
    case GUESTFS_PROC_COMPRESS_DEVICE_OUT:
      compress_device_out_stub (xdr_in);
      break;
    case GUESTFS_PROC_PART_TO_PARTNUM:
      part_to_partnum_stub (xdr_in);
      break;
    case GUESTFS_PROC_COPY_DEVICE_TO_DEVICE:
      copy_device_to_device_stub (xdr_in);
      break;
    case GUESTFS_PROC_COPY_DEVICE_TO_FILE:
      copy_device_to_file_stub (xdr_in);
      break;
    case GUESTFS_PROC_COPY_FILE_TO_DEVICE:
      copy_file_to_device_stub (xdr_in);
      break;
    case GUESTFS_PROC_COPY_FILE_TO_FILE:
      copy_file_to_file_stub (xdr_in);
      break;
    case GUESTFS_PROC_TUNE2FS:
      tune2fs_stub (xdr_in);
      break;
    case GUESTFS_PROC_MD_CREATE:
      md_create_stub (xdr_in);
      break;
    case GUESTFS_PROC_LIST_MD_DEVICES:
      list_md_devices_stub (xdr_in);
      break;
    case GUESTFS_PROC_MD_DETAIL:
      md_detail_stub (xdr_in);
      break;
    case GUESTFS_PROC_MD_STOP:
      md_stop_stub (xdr_in);
      break;
    case GUESTFS_PROC_BLKID:
      blkid_stub (xdr_in);
      break;
    case GUESTFS_PROC_E2FSCK:
      e2fsck_stub (xdr_in);
      break;
    case GUESTFS_PROC_LLZ:
      llz_stub (xdr_in);
      break;
    case GUESTFS_PROC_WIPEFS:
      wipefs_stub (xdr_in);
      break;
    case GUESTFS_PROC_NTFSFIX:
      ntfsfix_stub (xdr_in);
      break;
    case GUESTFS_PROC_NTFSCLONE_OUT:
      ntfsclone_out_stub (xdr_in);
      break;
    case GUESTFS_PROC_NTFSCLONE_IN:
      ntfsclone_in_stub (xdr_in);
      break;
    case GUESTFS_PROC_SET_LABEL:
      set_label_stub (xdr_in);
      break;
    case GUESTFS_PROC_ZERO_FREE_SPACE:
      zero_free_space_stub (xdr_in);
      break;
    case GUESTFS_PROC_LVCREATE_FREE:
      lvcreate_free_stub (xdr_in);
      break;
    case GUESTFS_PROC_ISOINFO_DEVICE:
      isoinfo_device_stub (xdr_in);
      break;
    case GUESTFS_PROC_ISOINFO:
      isoinfo_stub (xdr_in);
      break;
    case GUESTFS_PROC_VGMETA:
      vgmeta_stub (xdr_in);
      break;
    case GUESTFS_PROC_MD_STAT:
      md_stat_stub (xdr_in);
      break;
    case GUESTFS_PROC_MKFS_BTRFS:
      mkfs_btrfs_stub (xdr_in);
      break;
    case GUESTFS_PROC_GET_E2ATTRS:
      get_e2attrs_stub (xdr_in);
      break;
    case GUESTFS_PROC_SET_E2ATTRS:
      set_e2attrs_stub (xdr_in);
      break;
    case GUESTFS_PROC_GET_E2GENERATION:
      get_e2generation_stub (xdr_in);
      break;
    case GUESTFS_PROC_SET_E2GENERATION:
      set_e2generation_stub (xdr_in);
      break;
    case GUESTFS_PROC_BTRFS_SUBVOLUME_SNAPSHOT:
      btrfs_subvolume_snapshot_stub (xdr_in);
      break;
    case GUESTFS_PROC_BTRFS_SUBVOLUME_DELETE:
      btrfs_subvolume_delete_stub (xdr_in);
      break;
    case GUESTFS_PROC_BTRFS_SUBVOLUME_CREATE:
      btrfs_subvolume_create_stub (xdr_in);
      break;
    case GUESTFS_PROC_BTRFS_SUBVOLUME_LIST:
      btrfs_subvolume_list_stub (xdr_in);
      break;
    case GUESTFS_PROC_BTRFS_SUBVOLUME_SET_DEFAULT:
      btrfs_subvolume_set_default_stub (xdr_in);
      break;
    case GUESTFS_PROC_BTRFS_FILESYSTEM_SYNC:
      btrfs_filesystem_sync_stub (xdr_in);
      break;
    case GUESTFS_PROC_BTRFS_FILESYSTEM_BALANCE:
      btrfs_filesystem_balance_stub (xdr_in);
      break;
    case GUESTFS_PROC_BTRFS_DEVICE_ADD:
      btrfs_device_add_stub (xdr_in);
      break;
    case GUESTFS_PROC_BTRFS_DEVICE_DELETE:
      btrfs_device_delete_stub (xdr_in);
      break;
    case GUESTFS_PROC_BTRFS_SET_SEEDING:
      btrfs_set_seeding_stub (xdr_in);
      break;
    case GUESTFS_PROC_BTRFS_FSCK:
      btrfs_fsck_stub (xdr_in);
      break;
    case GUESTFS_PROC_FILESYSTEM_AVAILABLE:
      filesystem_available_stub (xdr_in);
      break;
    case GUESTFS_PROC_FSTRIM:
      fstrim_stub (xdr_in);
      break;
    case GUESTFS_PROC_DEVICE_INDEX:
      device_index_stub (xdr_in);
      break;
    case GUESTFS_PROC_NR_DEVICES:
      nr_devices_stub (xdr_in);
      break;
    case GUESTFS_PROC_XFS_INFO:
      xfs_info_stub (xdr_in);
      break;
    case GUESTFS_PROC_PVCHANGE_UUID:
      pvchange_uuid_stub (xdr_in);
      break;
    case GUESTFS_PROC_PVCHANGE_UUID_ALL:
      pvchange_uuid_all_stub (xdr_in);
      break;
    case GUESTFS_PROC_VGCHANGE_UUID:
      vgchange_uuid_stub (xdr_in);
      break;
    case GUESTFS_PROC_VGCHANGE_UUID_ALL:
      vgchange_uuid_all_stub (xdr_in);
      break;
    case GUESTFS_PROC_UTSNAME:
      utsname_stub (xdr_in);
      break;
    case GUESTFS_PROC_XFS_GROWFS:
      xfs_growfs_stub (xdr_in);
      break;
    case GUESTFS_PROC_RSYNC:
      rsync_stub (xdr_in);
      break;
    case GUESTFS_PROC_RSYNC_IN:
      rsync_in_stub (xdr_in);
      break;
    case GUESTFS_PROC_RSYNC_OUT:
      rsync_out_stub (xdr_in);
      break;
    case GUESTFS_PROC_LS0:
      ls0_stub (xdr_in);
      break;
    case GUESTFS_PROC_FILL_DIR:
      fill_dir_stub (xdr_in);
      break;
    case GUESTFS_PROC_XFS_ADMIN:
      xfs_admin_stub (xdr_in);
      break;
    case GUESTFS_PROC_HIVEX_OPEN:
      hivex_open_stub (xdr_in);
      break;
    case GUESTFS_PROC_HIVEX_CLOSE:
      hivex_close_stub (xdr_in);
      break;
    case GUESTFS_PROC_HIVEX_ROOT:
      hivex_root_stub (xdr_in);
      break;
    case GUESTFS_PROC_HIVEX_NODE_NAME:
      hivex_node_name_stub (xdr_in);
      break;
    case GUESTFS_PROC_HIVEX_NODE_CHILDREN:
      hivex_node_children_stub (xdr_in);
      break;
    case GUESTFS_PROC_HIVEX_NODE_GET_CHILD:
      hivex_node_get_child_stub (xdr_in);
      break;
    case GUESTFS_PROC_HIVEX_NODE_PARENT:
      hivex_node_parent_stub (xdr_in);
      break;
    case GUESTFS_PROC_HIVEX_NODE_VALUES:
      hivex_node_values_stub (xdr_in);
      break;
    case GUESTFS_PROC_HIVEX_NODE_GET_VALUE:
      hivex_node_get_value_stub (xdr_in);
      break;
    case GUESTFS_PROC_HIVEX_VALUE_KEY:
      hivex_value_key_stub (xdr_in);
      break;
    case GUESTFS_PROC_HIVEX_VALUE_TYPE:
      hivex_value_type_stub (xdr_in);
      break;
    case GUESTFS_PROC_HIVEX_VALUE_VALUE:
      hivex_value_value_stub (xdr_in);
      break;
    case GUESTFS_PROC_HIVEX_COMMIT:
      hivex_commit_stub (xdr_in);
      break;
    case GUESTFS_PROC_HIVEX_NODE_ADD_CHILD:
      hivex_node_add_child_stub (xdr_in);
      break;
    case GUESTFS_PROC_HIVEX_NODE_DELETE_CHILD:
      hivex_node_delete_child_stub (xdr_in);
      break;
    case GUESTFS_PROC_HIVEX_NODE_SET_VALUE:
      hivex_node_set_value_stub (xdr_in);
      break;
    case GUESTFS_PROC_XFS_REPAIR:
      xfs_repair_stub (xdr_in);
      break;
    case GUESTFS_PROC_RM_F:
      rm_f_stub (xdr_in);
      break;
    case GUESTFS_PROC_MKE2FS:
      mke2fs_stub (xdr_in);
      break;
    case GUESTFS_PROC_LIST_DISK_LABELS:
      list_disk_labels_stub (xdr_in);
      break;
    case GUESTFS_PROC_INTERNAL_HOT_ADD_DRIVE:
      internal_hot_add_drive_stub (xdr_in);
      break;
    case GUESTFS_PROC_INTERNAL_HOT_REMOVE_DRIVE_PRECHECK:
      internal_hot_remove_drive_precheck_stub (xdr_in);
      break;
    case GUESTFS_PROC_INTERNAL_HOT_REMOVE_DRIVE:
      internal_hot_remove_drive_stub (xdr_in);
      break;
    case GUESTFS_PROC_MKTEMP:
      mktemp_stub (xdr_in);
      break;
    case GUESTFS_PROC_MKLOST_AND_FOUND:
      mklost_and_found_stub (xdr_in);
      break;
    case GUESTFS_PROC_ACL_GET_FILE:
      acl_get_file_stub (xdr_in);
      break;
    case GUESTFS_PROC_ACL_SET_FILE:
      acl_set_file_stub (xdr_in);
      break;
    case GUESTFS_PROC_ACL_DELETE_DEF_FILE:
      acl_delete_def_file_stub (xdr_in);
      break;
    case GUESTFS_PROC_CAP_GET_FILE:
      cap_get_file_stub (xdr_in);
      break;
    case GUESTFS_PROC_CAP_SET_FILE:
      cap_set_file_stub (xdr_in);
      break;
    case GUESTFS_PROC_LIST_LDM_VOLUMES:
      list_ldm_volumes_stub (xdr_in);
      break;
    case GUESTFS_PROC_LIST_LDM_PARTITIONS:
      list_ldm_partitions_stub (xdr_in);
      break;
    case GUESTFS_PROC_LDMTOOL_CREATE_ALL:
      ldmtool_create_all_stub (xdr_in);
      break;
    case GUESTFS_PROC_LDMTOOL_REMOVE_ALL:
      ldmtool_remove_all_stub (xdr_in);
      break;
    case GUESTFS_PROC_LDMTOOL_SCAN:
      ldmtool_scan_stub (xdr_in);
      break;
    case GUESTFS_PROC_LDMTOOL_SCAN_DEVICES:
      ldmtool_scan_devices_stub (xdr_in);
      break;
    case GUESTFS_PROC_LDMTOOL_DISKGROUP_NAME:
      ldmtool_diskgroup_name_stub (xdr_in);
      break;
    case GUESTFS_PROC_LDMTOOL_DISKGROUP_VOLUMES:
      ldmtool_diskgroup_volumes_stub (xdr_in);
      break;
    case GUESTFS_PROC_LDMTOOL_DISKGROUP_DISKS:
      ldmtool_diskgroup_disks_stub (xdr_in);
      break;
    case GUESTFS_PROC_LDMTOOL_VOLUME_TYPE:
      ldmtool_volume_type_stub (xdr_in);
      break;
    case GUESTFS_PROC_LDMTOOL_VOLUME_HINT:
      ldmtool_volume_hint_stub (xdr_in);
      break;
    case GUESTFS_PROC_LDMTOOL_VOLUME_PARTITIONS:
      ldmtool_volume_partitions_stub (xdr_in);
      break;
    case GUESTFS_PROC_PART_SET_GPT_TYPE:
      part_set_gpt_type_stub (xdr_in);
      break;
    case GUESTFS_PROC_PART_GET_GPT_TYPE:
      part_get_gpt_type_stub (xdr_in);
      break;
    case GUESTFS_PROC_RENAME:
      rename_stub (xdr_in);
      break;
    case GUESTFS_PROC_IS_WHOLE_DEVICE:
      is_whole_device_stub (xdr_in);
      break;
    case GUESTFS_PROC_INTERNAL_PARSE_MOUNTABLE:
      internal_parse_mountable_stub (xdr_in);
      break;
    case GUESTFS_PROC_INTERNAL_RHBZ914931:
      internal_rhbz914931_stub (xdr_in);
      break;
    case GUESTFS_PROC_FEATURE_AVAILABLE:
      feature_available_stub (xdr_in);
      break;
    case GUESTFS_PROC_SYSLINUX:
      syslinux_stub (xdr_in);
      break;
    case GUESTFS_PROC_EXTLINUX:
      extlinux_stub (xdr_in);
      break;
    case GUESTFS_PROC_CP_R:
      cp_r_stub (xdr_in);
      break;
    case GUESTFS_PROC_REMOUNT:
      remount_stub (xdr_in);
      break;
    case GUESTFS_PROC_SET_UUID:
      set_uuid_stub (xdr_in);
      break;
    case GUESTFS_PROC_JOURNAL_OPEN:
      journal_open_stub (xdr_in);
      break;
    case GUESTFS_PROC_JOURNAL_CLOSE:
      journal_close_stub (xdr_in);
      break;
    case GUESTFS_PROC_JOURNAL_NEXT:
      journal_next_stub (xdr_in);
      break;
    case GUESTFS_PROC_JOURNAL_SKIP:
      journal_skip_stub (xdr_in);
      break;
    case GUESTFS_PROC_INTERNAL_JOURNAL_GET:
      internal_journal_get_stub (xdr_in);
      break;
    case GUESTFS_PROC_JOURNAL_GET_DATA_THRESHOLD:
      journal_get_data_threshold_stub (xdr_in);
      break;
    case GUESTFS_PROC_JOURNAL_SET_DATA_THRESHOLD:
      journal_set_data_threshold_stub (xdr_in);
      break;
    case GUESTFS_PROC_AUG_SETM:
      aug_setm_stub (xdr_in);
      break;
    case GUESTFS_PROC_AUG_LABEL:
      aug_label_stub (xdr_in);
      break;
    case GUESTFS_PROC_INTERNAL_UPLOAD:
      internal_upload_stub (xdr_in);
      break;
    case GUESTFS_PROC_INTERNAL_EXIT:
      internal_exit_stub (xdr_in);
      break;
    case GUESTFS_PROC_COPY_ATTRIBUTES:
      copy_attributes_stub (xdr_in);
      break;
    case GUESTFS_PROC_PART_GET_NAME:
      part_get_name_stub (xdr_in);
      break;
    case GUESTFS_PROC_BLKDISCARD:
      blkdiscard_stub (xdr_in);
      break;
    case GUESTFS_PROC_BLKDISCARDZEROES:
      blkdiscardzeroes_stub (xdr_in);
      break;
    case GUESTFS_PROC_CPIO_OUT:
      cpio_out_stub (xdr_in);
      break;
    case GUESTFS_PROC_JOURNAL_GET_REALTIME_USEC:
      journal_get_realtime_usec_stub (xdr_in);
      break;
    case GUESTFS_PROC_STATNS:
      statns_stub (xdr_in);
      break;
    case GUESTFS_PROC_LSTATNS:
      lstatns_stub (xdr_in);
      break;
    case GUESTFS_PROC_INTERNAL_LSTATNSLIST:
      internal_lstatnslist_stub (xdr_in);
      break;
    case GUESTFS_PROC_BLOCKDEV_SETRA:
      blockdev_setra_stub (xdr_in);
      break;
    case GUESTFS_PROC_BTRFS_SUBVOLUME_GET_DEFAULT:
      btrfs_subvolume_get_default_stub (xdr_in);
      break;
    case GUESTFS_PROC_BTRFS_SUBVOLUME_SHOW:
      btrfs_subvolume_show_stub (xdr_in);
      break;
    case GUESTFS_PROC_BTRFS_QUOTA_ENABLE:
      btrfs_quota_enable_stub (xdr_in);
      break;
    case GUESTFS_PROC_BTRFS_QUOTA_RESCAN:
      btrfs_quota_rescan_stub (xdr_in);
      break;
    case GUESTFS_PROC_BTRFS_QGROUP_LIMIT:
      btrfs_qgroup_limit_stub (xdr_in);
      break;
    case GUESTFS_PROC_BTRFS_QGROUP_CREATE:
      btrfs_qgroup_create_stub (xdr_in);
      break;
    case GUESTFS_PROC_BTRFS_QGROUP_DESTROY:
      btrfs_qgroup_destroy_stub (xdr_in);
      break;
    case GUESTFS_PROC_BTRFS_QGROUP_SHOW:
      btrfs_qgroup_show_stub (xdr_in);
      break;
    case GUESTFS_PROC_BTRFS_QGROUP_ASSIGN:
      btrfs_qgroup_assign_stub (xdr_in);
      break;
    case GUESTFS_PROC_BTRFS_QGROUP_REMOVE:
      btrfs_qgroup_remove_stub (xdr_in);
      break;
    case GUESTFS_PROC_BTRFS_SCRUB_START:
      btrfs_scrub_start_stub (xdr_in);
      break;
    case GUESTFS_PROC_BTRFS_SCRUB_CANCEL:
      btrfs_scrub_cancel_stub (xdr_in);
      break;
    case GUESTFS_PROC_BTRFS_SCRUB_RESUME:
      btrfs_scrub_resume_stub (xdr_in);
      break;
    case GUESTFS_PROC_BTRFS_BALANCE_PAUSE:
      btrfs_balance_pause_stub (xdr_in);
      break;
    case GUESTFS_PROC_BTRFS_BALANCE_CANCEL:
      btrfs_balance_cancel_stub (xdr_in);
      break;
    case GUESTFS_PROC_BTRFS_BALANCE_RESUME:
      btrfs_balance_resume_stub (xdr_in);
      break;
    case GUESTFS_PROC_BTRFS_FILESYSTEM_DEFRAGMENT:
      btrfs_filesystem_defragment_stub (xdr_in);
      break;
    case GUESTFS_PROC_BTRFS_RESCUE_CHUNK_RECOVER:
      btrfs_rescue_chunk_recover_stub (xdr_in);
      break;
    case GUESTFS_PROC_BTRFS_RESCUE_SUPER_RECOVER:
      btrfs_rescue_super_recover_stub (xdr_in);
      break;
    case GUESTFS_PROC_PART_SET_GPT_GUID:
      part_set_gpt_guid_stub (xdr_in);
      break;
    case GUESTFS_PROC_PART_GET_GPT_GUID:
      part_get_gpt_guid_stub (xdr_in);
      break;
    case GUESTFS_PROC_BTRFS_BALANCE_STATUS:
      btrfs_balance_status_stub (xdr_in);
      break;
    case GUESTFS_PROC_BTRFS_SCRUB_STATUS:
      btrfs_scrub_status_stub (xdr_in);
      break;
    case GUESTFS_PROC_BTRFSTUNE_SEEDING:
      btrfstune_seeding_stub (xdr_in);
      break;
    case GUESTFS_PROC_BTRFSTUNE_ENABLE_EXTENDED_INODE_REFS:
      btrfstune_enable_extended_inode_refs_stub (xdr_in);
      break;
    case GUESTFS_PROC_BTRFSTUNE_ENABLE_SKINNY_METADATA_EXTENT_REFS:
      btrfstune_enable_skinny_metadata_extent_refs_stub (xdr_in);
      break;
    case GUESTFS_PROC_BTRFS_IMAGE:
      btrfs_image_stub (xdr_in);
      break;
    case GUESTFS_PROC_PART_GET_MBR_PART_TYPE:
      part_get_mbr_part_type_stub (xdr_in);
      break;
    case GUESTFS_PROC_BTRFS_REPLACE:
      btrfs_replace_stub (xdr_in);
      break;
    case GUESTFS_PROC_SET_UUID_RANDOM:
      set_uuid_random_stub (xdr_in);
      break;
    default:
      reply_with_error ("dispatch_incoming_message: unknown procedure number %d, set LIBGUESTFS_PATH to point to the matching libguestfs appliance directory", proc_nr);
  }
}

static const char *lvm_pv_cols = "pv_name,pv_uuid,pv_fmt,pv_size,dev_size,pv_free,pv_used,pv_attr,pv_pe_count,pv_pe_alloc_count,pv_tags,pe_start,pv_mda_count,pv_mda_free";

static int lvm_tokenize_pv (char *str, guestfs_int_lvm_pv *r)
{
  char *tok, *p, *next;
  size_t i, j;

  if (!str) {
    fprintf (stderr, "%s: failed: passed a NULL string\n", __func__);
    return -1;
  }
  if (!*str || c_isspace (*str)) {
    fprintf (stderr, "%s: failed: passed a empty string or one beginning with whitespace\n", __func__);
    return -1;
  }
  tok = str;
  if (!tok) {
    fprintf (stderr, "%s: failed: string finished early, around token %s\n", __func__, "pv_name");
    return -1;
  }
  p = strchrnul (tok, ':');
  if (*p) next = p+1; else next = NULL;
  *p = '\0';
  r->pv_name = strdup (tok);
  if (r->pv_name == NULL) {
    perror ("strdup");
    return -1;
  }
  tok = next;
  if (!tok) {
    fprintf (stderr, "%s: failed: string finished early, around token %s\n", __func__, "pv_uuid");
    return -1;
  }
  p = strchrnul (tok, ':');
  if (*p) next = p+1; else next = NULL;
  *p = '\0';
  for (i = j = 0; i < 32; ++j) {
    if (tok[j] == '\0') {
      fprintf (stderr, "%s: failed to parse UUID from '%s'\n", __func__, tok);
      return -1;
    } else if (tok[j] != '-')
      r->pv_uuid[i++] = tok[j];
  }
  tok = next;
  if (!tok) {
    fprintf (stderr, "%s: failed: string finished early, around token %s\n", __func__, "pv_fmt");
    return -1;
  }
  p = strchrnul (tok, ':');
  if (*p) next = p+1; else next = NULL;
  *p = '\0';
  r->pv_fmt = strdup (tok);
  if (r->pv_fmt == NULL) {
    perror ("strdup");
    return -1;
  }
  tok = next;
  if (!tok) {
    fprintf (stderr, "%s: failed: string finished early, around token %s\n", __func__, "pv_size");
    return -1;
  }
  p = strchrnul (tok, ':');
  if (*p) next = p+1; else next = NULL;
  *p = '\0';
  if (sscanf (tok, "%" SCNi64, &r->pv_size) != 1) {
    fprintf (stderr, "%s: failed to parse size '%s' from token %s\n", __func__, tok, "pv_size");
    return -1;
  }
  tok = next;
  if (!tok) {
    fprintf (stderr, "%s: failed: string finished early, around token %s\n", __func__, "dev_size");
    return -1;
  }
  p = strchrnul (tok, ':');
  if (*p) next = p+1; else next = NULL;
  *p = '\0';
  if (sscanf (tok, "%" SCNi64, &r->dev_size) != 1) {
    fprintf (stderr, "%s: failed to parse size '%s' from token %s\n", __func__, tok, "dev_size");
    return -1;
  }
  tok = next;
  if (!tok) {
    fprintf (stderr, "%s: failed: string finished early, around token %s\n", __func__, "pv_free");
    return -1;
  }
  p = strchrnul (tok, ':');
  if (*p) next = p+1; else next = NULL;
  *p = '\0';
  if (sscanf (tok, "%" SCNi64, &r->pv_free) != 1) {
    fprintf (stderr, "%s: failed to parse size '%s' from token %s\n", __func__, tok, "pv_free");
    return -1;
  }
  tok = next;
  if (!tok) {
    fprintf (stderr, "%s: failed: string finished early, around token %s\n", __func__, "pv_used");
    return -1;
  }
  p = strchrnul (tok, ':');
  if (*p) next = p+1; else next = NULL;
  *p = '\0';
  if (sscanf (tok, "%" SCNi64, &r->pv_used) != 1) {
    fprintf (stderr, "%s: failed to parse size '%s' from token %s\n", __func__, tok, "pv_used");
    return -1;
  }
  tok = next;
  if (!tok) {
    fprintf (stderr, "%s: failed: string finished early, around token %s\n", __func__, "pv_attr");
    return -1;
  }
  p = strchrnul (tok, ':');
  if (*p) next = p+1; else next = NULL;
  *p = '\0';
  r->pv_attr = strdup (tok);
  if (r->pv_attr == NULL) {
    perror ("strdup");
    return -1;
  }
  tok = next;
  if (!tok) {
    fprintf (stderr, "%s: failed: string finished early, around token %s\n", __func__, "pv_pe_count");
    return -1;
  }
  p = strchrnul (tok, ':');
  if (*p) next = p+1; else next = NULL;
  *p = '\0';
  if (sscanf (tok, "%" SCNi64, &r->pv_pe_count) != 1) {
    fprintf (stderr, "%s: failed to parse int '%s' from token %s\n", __func__, tok, "pv_pe_count");
    return -1;
  }
  tok = next;
  if (!tok) {
    fprintf (stderr, "%s: failed: string finished early, around token %s\n", __func__, "pv_pe_alloc_count");
    return -1;
  }
  p = strchrnul (tok, ':');
  if (*p) next = p+1; else next = NULL;
  *p = '\0';
  if (sscanf (tok, "%" SCNi64, &r->pv_pe_alloc_count) != 1) {
    fprintf (stderr, "%s: failed to parse int '%s' from token %s\n", __func__, tok, "pv_pe_alloc_count");
    return -1;
  }
  tok = next;
  if (!tok) {
    fprintf (stderr, "%s: failed: string finished early, around token %s\n", __func__, "pv_tags");
    return -1;
  }
  p = strchrnul (tok, ':');
  if (*p) next = p+1; else next = NULL;
  *p = '\0';
  r->pv_tags = strdup (tok);
  if (r->pv_tags == NULL) {
    perror ("strdup");
    return -1;
  }
  tok = next;
  if (!tok) {
    fprintf (stderr, "%s: failed: string finished early, around token %s\n", __func__, "pe_start");
    return -1;
  }
  p = strchrnul (tok, ':');
  if (*p) next = p+1; else next = NULL;
  *p = '\0';
  if (sscanf (tok, "%" SCNi64, &r->pe_start) != 1) {
    fprintf (stderr, "%s: failed to parse size '%s' from token %s\n", __func__, tok, "pe_start");
    return -1;
  }
  tok = next;
  if (!tok) {
    fprintf (stderr, "%s: failed: string finished early, around token %s\n", __func__, "pv_mda_count");
    return -1;
  }
  p = strchrnul (tok, ':');
  if (*p) next = p+1; else next = NULL;
  *p = '\0';
  if (sscanf (tok, "%" SCNi64, &r->pv_mda_count) != 1) {
    fprintf (stderr, "%s: failed to parse int '%s' from token %s\n", __func__, tok, "pv_mda_count");
    return -1;
  }
  tok = next;
  if (!tok) {
    fprintf (stderr, "%s: failed: string finished early, around token %s\n", __func__, "pv_mda_free");
    return -1;
  }
  p = strchrnul (tok, ':');
  if (*p) next = p+1; else next = NULL;
  *p = '\0';
  if (sscanf (tok, "%" SCNi64, &r->pv_mda_free) != 1) {
    fprintf (stderr, "%s: failed to parse size '%s' from token %s\n", __func__, tok, "pv_mda_free");
    return -1;
  }
  tok = next;
  if (tok != NULL) {
    fprintf (stderr, "%s: failed: extra tokens at end of string\n", __func__);
    return -1;
  }
  return 0;
}

guestfs_int_lvm_pv_list *
parse_command_line_pvs (void)
{
  char *out, *err;
  char *p, *pend;
  int r, i;
  guestfs_int_lvm_pv_list *ret;
  void *newp;

  ret = malloc (sizeof *ret);
  if (!ret) {
    reply_with_perror ("malloc");
    return NULL;
  }

  ret->guestfs_int_lvm_pv_list_len = 0;
  ret->guestfs_int_lvm_pv_list_val = NULL;

  r = command (&out, &err,
	       "lvm", "pvs",
	       "-o", lvm_pv_cols, "--unbuffered", "--noheadings",
	       "--nosuffix", "--separator", ":", "--units", "b", NULL);
  if (r == -1) {
    reply_with_error ("%s", err);
    free (out);
    free (err);
    free (ret);
    return NULL;
  }

  free (err);

  /* Tokenize each line of the output. */
  p = out;
  i = 0;
  while (p) {
    pend = strchr (p, '\n');	/* Get the next line of output. */
    if (pend) {
      *pend = '\0';
      pend++;
    }

    while (*p && c_isspace (*p))	/* Skip any leading whitespace. */
      p++;

    if (!*p) {			/* Empty line?  Skip it. */
      p = pend;
      continue;
    }

    /* Allocate some space to store this next entry. */
    newp = realloc (ret->guestfs_int_lvm_pv_list_val,
		    sizeof (guestfs_int_lvm_pv) * (i+1));
    if (newp == NULL) {
      reply_with_perror ("realloc");
      free (ret->guestfs_int_lvm_pv_list_val);
      free (ret);
      free (out);
      return NULL;
    }
    ret->guestfs_int_lvm_pv_list_val = newp;

    /* Tokenize the next entry. */
    r = lvm_tokenize_pv (p, &ret->guestfs_int_lvm_pv_list_val[i]);
    if (r == -1) {
      reply_with_error ("failed to parse output of 'pvs' command");
      free (ret->guestfs_int_lvm_pv_list_val);
      free (ret);
      free (out);
      return NULL;
    }

    ++i;
    p = pend;
  }

  ret->guestfs_int_lvm_pv_list_len = i;

  free (out);
  return ret;
}
static const char *lvm_vg_cols = "vg_name,vg_uuid,vg_fmt,vg_attr,vg_size,vg_free,vg_sysid,vg_extent_size,vg_extent_count,vg_free_count,max_lv,max_pv,pv_count,lv_count,snap_count,vg_seqno,vg_tags,vg_mda_count,vg_mda_free";

static int lvm_tokenize_vg (char *str, guestfs_int_lvm_vg *r)
{
  char *tok, *p, *next;
  size_t i, j;

  if (!str) {
    fprintf (stderr, "%s: failed: passed a NULL string\n", __func__);
    return -1;
  }
  if (!*str || c_isspace (*str)) {
    fprintf (stderr, "%s: failed: passed a empty string or one beginning with whitespace\n", __func__);
    return -1;
  }
  tok = str;
  if (!tok) {
    fprintf (stderr, "%s: failed: string finished early, around token %s\n", __func__, "vg_name");
    return -1;
  }
  p = strchrnul (tok, ':');
  if (*p) next = p+1; else next = NULL;
  *p = '\0';
  r->vg_name = strdup (tok);
  if (r->vg_name == NULL) {
    perror ("strdup");
    return -1;
  }
  tok = next;
  if (!tok) {
    fprintf (stderr, "%s: failed: string finished early, around token %s\n", __func__, "vg_uuid");
    return -1;
  }
  p = strchrnul (tok, ':');
  if (*p) next = p+1; else next = NULL;
  *p = '\0';
  for (i = j = 0; i < 32; ++j) {
    if (tok[j] == '\0') {
      fprintf (stderr, "%s: failed to parse UUID from '%s'\n", __func__, tok);
      return -1;
    } else if (tok[j] != '-')
      r->vg_uuid[i++] = tok[j];
  }
  tok = next;
  if (!tok) {
    fprintf (stderr, "%s: failed: string finished early, around token %s\n", __func__, "vg_fmt");
    return -1;
  }
  p = strchrnul (tok, ':');
  if (*p) next = p+1; else next = NULL;
  *p = '\0';
  r->vg_fmt = strdup (tok);
  if (r->vg_fmt == NULL) {
    perror ("strdup");
    return -1;
  }
  tok = next;
  if (!tok) {
    fprintf (stderr, "%s: failed: string finished early, around token %s\n", __func__, "vg_attr");
    return -1;
  }
  p = strchrnul (tok, ':');
  if (*p) next = p+1; else next = NULL;
  *p = '\0';
  r->vg_attr = strdup (tok);
  if (r->vg_attr == NULL) {
    perror ("strdup");
    return -1;
  }
  tok = next;
  if (!tok) {
    fprintf (stderr, "%s: failed: string finished early, around token %s\n", __func__, "vg_size");
    return -1;
  }
  p = strchrnul (tok, ':');
  if (*p) next = p+1; else next = NULL;
  *p = '\0';
  if (sscanf (tok, "%" SCNi64, &r->vg_size) != 1) {
    fprintf (stderr, "%s: failed to parse size '%s' from token %s\n", __func__, tok, "vg_size");
    return -1;
  }
  tok = next;
  if (!tok) {
    fprintf (stderr, "%s: failed: string finished early, around token %s\n", __func__, "vg_free");
    return -1;
  }
  p = strchrnul (tok, ':');
  if (*p) next = p+1; else next = NULL;
  *p = '\0';
  if (sscanf (tok, "%" SCNi64, &r->vg_free) != 1) {
    fprintf (stderr, "%s: failed to parse size '%s' from token %s\n", __func__, tok, "vg_free");
    return -1;
  }
  tok = next;
  if (!tok) {
    fprintf (stderr, "%s: failed: string finished early, around token %s\n", __func__, "vg_sysid");
    return -1;
  }
  p = strchrnul (tok, ':');
  if (*p) next = p+1; else next = NULL;
  *p = '\0';
  r->vg_sysid = strdup (tok);
  if (r->vg_sysid == NULL) {
    perror ("strdup");
    return -1;
  }
  tok = next;
  if (!tok) {
    fprintf (stderr, "%s: failed: string finished early, around token %s\n", __func__, "vg_extent_size");
    return -1;
  }
  p = strchrnul (tok, ':');
  if (*p) next = p+1; else next = NULL;
  *p = '\0';
  if (sscanf (tok, "%" SCNi64, &r->vg_extent_size) != 1) {
    fprintf (stderr, "%s: failed to parse size '%s' from token %s\n", __func__, tok, "vg_extent_size");
    return -1;
  }
  tok = next;
  if (!tok) {
    fprintf (stderr, "%s: failed: string finished early, around token %s\n", __func__, "vg_extent_count");
    return -1;
  }
  p = strchrnul (tok, ':');
  if (*p) next = p+1; else next = NULL;
  *p = '\0';
  if (sscanf (tok, "%" SCNi64, &r->vg_extent_count) != 1) {
    fprintf (stderr, "%s: failed to parse int '%s' from token %s\n", __func__, tok, "vg_extent_count");
    return -1;
  }
  tok = next;
  if (!tok) {
    fprintf (stderr, "%s: failed: string finished early, around token %s\n", __func__, "vg_free_count");
    return -1;
  }
  p = strchrnul (tok, ':');
  if (*p) next = p+1; else next = NULL;
  *p = '\0';
  if (sscanf (tok, "%" SCNi64, &r->vg_free_count) != 1) {
    fprintf (stderr, "%s: failed to parse int '%s' from token %s\n", __func__, tok, "vg_free_count");
    return -1;
  }
  tok = next;
  if (!tok) {
    fprintf (stderr, "%s: failed: string finished early, around token %s\n", __func__, "max_lv");
    return -1;
  }
  p = strchrnul (tok, ':');
  if (*p) next = p+1; else next = NULL;
  *p = '\0';
  if (sscanf (tok, "%" SCNi64, &r->max_lv) != 1) {
    fprintf (stderr, "%s: failed to parse int '%s' from token %s\n", __func__, tok, "max_lv");
    return -1;
  }
  tok = next;
  if (!tok) {
    fprintf (stderr, "%s: failed: string finished early, around token %s\n", __func__, "max_pv");
    return -1;
  }
  p = strchrnul (tok, ':');
  if (*p) next = p+1; else next = NULL;
  *p = '\0';
  if (sscanf (tok, "%" SCNi64, &r->max_pv) != 1) {
    fprintf (stderr, "%s: failed to parse int '%s' from token %s\n", __func__, tok, "max_pv");
    return -1;
  }
  tok = next;
  if (!tok) {
    fprintf (stderr, "%s: failed: string finished early, around token %s\n", __func__, "pv_count");
    return -1;
  }
  p = strchrnul (tok, ':');
  if (*p) next = p+1; else next = NULL;
  *p = '\0';
  if (sscanf (tok, "%" SCNi64, &r->pv_count) != 1) {
    fprintf (stderr, "%s: failed to parse int '%s' from token %s\n", __func__, tok, "pv_count");
    return -1;
  }
  tok = next;
  if (!tok) {
    fprintf (stderr, "%s: failed: string finished early, around token %s\n", __func__, "lv_count");
    return -1;
  }
  p = strchrnul (tok, ':');
  if (*p) next = p+1; else next = NULL;
  *p = '\0';
  if (sscanf (tok, "%" SCNi64, &r->lv_count) != 1) {
    fprintf (stderr, "%s: failed to parse int '%s' from token %s\n", __func__, tok, "lv_count");
    return -1;
  }
  tok = next;
  if (!tok) {
    fprintf (stderr, "%s: failed: string finished early, around token %s\n", __func__, "snap_count");
    return -1;
  }
  p = strchrnul (tok, ':');
  if (*p) next = p+1; else next = NULL;
  *p = '\0';
  if (sscanf (tok, "%" SCNi64, &r->snap_count) != 1) {
    fprintf (stderr, "%s: failed to parse int '%s' from token %s\n", __func__, tok, "snap_count");
    return -1;
  }
  tok = next;
  if (!tok) {
    fprintf (stderr, "%s: failed: string finished early, around token %s\n", __func__, "vg_seqno");
    return -1;
  }
  p = strchrnul (tok, ':');
  if (*p) next = p+1; else next = NULL;
  *p = '\0';
  if (sscanf (tok, "%" SCNi64, &r->vg_seqno) != 1) {
    fprintf (stderr, "%s: failed to parse int '%s' from token %s\n", __func__, tok, "vg_seqno");
    return -1;
  }
  tok = next;
  if (!tok) {
    fprintf (stderr, "%s: failed: string finished early, around token %s\n", __func__, "vg_tags");
    return -1;
  }
  p = strchrnul (tok, ':');
  if (*p) next = p+1; else next = NULL;
  *p = '\0';
  r->vg_tags = strdup (tok);
  if (r->vg_tags == NULL) {
    perror ("strdup");
    return -1;
  }
  tok = next;
  if (!tok) {
    fprintf (stderr, "%s: failed: string finished early, around token %s\n", __func__, "vg_mda_count");
    return -1;
  }
  p = strchrnul (tok, ':');
  if (*p) next = p+1; else next = NULL;
  *p = '\0';
  if (sscanf (tok, "%" SCNi64, &r->vg_mda_count) != 1) {
    fprintf (stderr, "%s: failed to parse int '%s' from token %s\n", __func__, tok, "vg_mda_count");
    return -1;
  }
  tok = next;
  if (!tok) {
    fprintf (stderr, "%s: failed: string finished early, around token %s\n", __func__, "vg_mda_free");
    return -1;
  }
  p = strchrnul (tok, ':');
  if (*p) next = p+1; else next = NULL;
  *p = '\0';
  if (sscanf (tok, "%" SCNi64, &r->vg_mda_free) != 1) {
    fprintf (stderr, "%s: failed to parse size '%s' from token %s\n", __func__, tok, "vg_mda_free");
    return -1;
  }
  tok = next;
  if (tok != NULL) {
    fprintf (stderr, "%s: failed: extra tokens at end of string\n", __func__);
    return -1;
  }
  return 0;
}

guestfs_int_lvm_vg_list *
parse_command_line_vgs (void)
{
  char *out, *err;
  char *p, *pend;
  int r, i;
  guestfs_int_lvm_vg_list *ret;
  void *newp;

  ret = malloc (sizeof *ret);
  if (!ret) {
    reply_with_perror ("malloc");
    return NULL;
  }

  ret->guestfs_int_lvm_vg_list_len = 0;
  ret->guestfs_int_lvm_vg_list_val = NULL;

  r = command (&out, &err,
	       "lvm", "vgs",
	       "-o", lvm_vg_cols, "--unbuffered", "--noheadings",
	       "--nosuffix", "--separator", ":", "--units", "b", NULL);
  if (r == -1) {
    reply_with_error ("%s", err);
    free (out);
    free (err);
    free (ret);
    return NULL;
  }

  free (err);

  /* Tokenize each line of the output. */
  p = out;
  i = 0;
  while (p) {
    pend = strchr (p, '\n');	/* Get the next line of output. */
    if (pend) {
      *pend = '\0';
      pend++;
    }

    while (*p && c_isspace (*p))	/* Skip any leading whitespace. */
      p++;

    if (!*p) {			/* Empty line?  Skip it. */
      p = pend;
      continue;
    }

    /* Allocate some space to store this next entry. */
    newp = realloc (ret->guestfs_int_lvm_vg_list_val,
		    sizeof (guestfs_int_lvm_vg) * (i+1));
    if (newp == NULL) {
      reply_with_perror ("realloc");
      free (ret->guestfs_int_lvm_vg_list_val);
      free (ret);
      free (out);
      return NULL;
    }
    ret->guestfs_int_lvm_vg_list_val = newp;

    /* Tokenize the next entry. */
    r = lvm_tokenize_vg (p, &ret->guestfs_int_lvm_vg_list_val[i]);
    if (r == -1) {
      reply_with_error ("failed to parse output of 'vgs' command");
      free (ret->guestfs_int_lvm_vg_list_val);
      free (ret);
      free (out);
      return NULL;
    }

    ++i;
    p = pend;
  }

  ret->guestfs_int_lvm_vg_list_len = i;

  free (out);
  return ret;
}
static const char *lvm_lv_cols = "lv_name,lv_uuid,lv_attr,lv_major,lv_minor,lv_kernel_major,lv_kernel_minor,lv_size,seg_count,origin,snap_percent,copy_percent,move_pv,lv_tags,mirror_log,modules";

static int lvm_tokenize_lv (char *str, guestfs_int_lvm_lv *r)
{
  char *tok, *p, *next;
  size_t i, j;

  if (!str) {
    fprintf (stderr, "%s: failed: passed a NULL string\n", __func__);
    return -1;
  }
  if (!*str || c_isspace (*str)) {
    fprintf (stderr, "%s: failed: passed a empty string or one beginning with whitespace\n", __func__);
    return -1;
  }
  tok = str;
  if (!tok) {
    fprintf (stderr, "%s: failed: string finished early, around token %s\n", __func__, "lv_name");
    return -1;
  }
  p = strchrnul (tok, ':');
  if (*p) next = p+1; else next = NULL;
  *p = '\0';
  r->lv_name = strdup (tok);
  if (r->lv_name == NULL) {
    perror ("strdup");
    return -1;
  }
  tok = next;
  if (!tok) {
    fprintf (stderr, "%s: failed: string finished early, around token %s\n", __func__, "lv_uuid");
    return -1;
  }
  p = strchrnul (tok, ':');
  if (*p) next = p+1; else next = NULL;
  *p = '\0';
  for (i = j = 0; i < 32; ++j) {
    if (tok[j] == '\0') {
      fprintf (stderr, "%s: failed to parse UUID from '%s'\n", __func__, tok);
      return -1;
    } else if (tok[j] != '-')
      r->lv_uuid[i++] = tok[j];
  }
  tok = next;
  if (!tok) {
    fprintf (stderr, "%s: failed: string finished early, around token %s\n", __func__, "lv_attr");
    return -1;
  }
  p = strchrnul (tok, ':');
  if (*p) next = p+1; else next = NULL;
  *p = '\0';
  r->lv_attr = strdup (tok);
  if (r->lv_attr == NULL) {
    perror ("strdup");
    return -1;
  }
  tok = next;
  if (!tok) {
    fprintf (stderr, "%s: failed: string finished early, around token %s\n", __func__, "lv_major");
    return -1;
  }
  p = strchrnul (tok, ':');
  if (*p) next = p+1; else next = NULL;
  *p = '\0';
  if (sscanf (tok, "%" SCNi64, &r->lv_major) != 1) {
    fprintf (stderr, "%s: failed to parse int '%s' from token %s\n", __func__, tok, "lv_major");
    return -1;
  }
  tok = next;
  if (!tok) {
    fprintf (stderr, "%s: failed: string finished early, around token %s\n", __func__, "lv_minor");
    return -1;
  }
  p = strchrnul (tok, ':');
  if (*p) next = p+1; else next = NULL;
  *p = '\0';
  if (sscanf (tok, "%" SCNi64, &r->lv_minor) != 1) {
    fprintf (stderr, "%s: failed to parse int '%s' from token %s\n", __func__, tok, "lv_minor");
    return -1;
  }
  tok = next;
  if (!tok) {
    fprintf (stderr, "%s: failed: string finished early, around token %s\n", __func__, "lv_kernel_major");
    return -1;
  }
  p = strchrnul (tok, ':');
  if (*p) next = p+1; else next = NULL;
  *p = '\0';
  if (sscanf (tok, "%" SCNi64, &r->lv_kernel_major) != 1) {
    fprintf (stderr, "%s: failed to parse int '%s' from token %s\n", __func__, tok, "lv_kernel_major");
    return -1;
  }
  tok = next;
  if (!tok) {
    fprintf (stderr, "%s: failed: string finished early, around token %s\n", __func__, "lv_kernel_minor");
    return -1;
  }
  p = strchrnul (tok, ':');
  if (*p) next = p+1; else next = NULL;
  *p = '\0';
  if (sscanf (tok, "%" SCNi64, &r->lv_kernel_minor) != 1) {
    fprintf (stderr, "%s: failed to parse int '%s' from token %s\n", __func__, tok, "lv_kernel_minor");
    return -1;
  }
  tok = next;
  if (!tok) {
    fprintf (stderr, "%s: failed: string finished early, around token %s\n", __func__, "lv_size");
    return -1;
  }
  p = strchrnul (tok, ':');
  if (*p) next = p+1; else next = NULL;
  *p = '\0';
  if (sscanf (tok, "%" SCNi64, &r->lv_size) != 1) {
    fprintf (stderr, "%s: failed to parse size '%s' from token %s\n", __func__, tok, "lv_size");
    return -1;
  }
  tok = next;
  if (!tok) {
    fprintf (stderr, "%s: failed: string finished early, around token %s\n", __func__, "seg_count");
    return -1;
  }
  p = strchrnul (tok, ':');
  if (*p) next = p+1; else next = NULL;
  *p = '\0';
  if (sscanf (tok, "%" SCNi64, &r->seg_count) != 1) {
    fprintf (stderr, "%s: failed to parse int '%s' from token %s\n", __func__, tok, "seg_count");
    return -1;
  }
  tok = next;
  if (!tok) {
    fprintf (stderr, "%s: failed: string finished early, around token %s\n", __func__, "origin");
    return -1;
  }
  p = strchrnul (tok, ':');
  if (*p) next = p+1; else next = NULL;
  *p = '\0';
  r->origin = strdup (tok);
  if (r->origin == NULL) {
    perror ("strdup");
    return -1;
  }
  tok = next;
  if (!tok) {
    fprintf (stderr, "%s: failed: string finished early, around token %s\n", __func__, "snap_percent");
    return -1;
  }
  p = strchrnul (tok, ':');
  if (*p) next = p+1; else next = NULL;
  *p = '\0';
  if (tok[0] == '\0')
    r->snap_percent = -1;
  else if (sscanf (tok, "%f", &r->snap_percent) != 1) {
    fprintf (stderr, "%s: failed to parse float '%s' from token %s\n", __func__, tok, "snap_percent");
    return -1;
  }
  tok = next;
  if (!tok) {
    fprintf (stderr, "%s: failed: string finished early, around token %s\n", __func__, "copy_percent");
    return -1;
  }
  p = strchrnul (tok, ':');
  if (*p) next = p+1; else next = NULL;
  *p = '\0';
  if (tok[0] == '\0')
    r->copy_percent = -1;
  else if (sscanf (tok, "%f", &r->copy_percent) != 1) {
    fprintf (stderr, "%s: failed to parse float '%s' from token %s\n", __func__, tok, "copy_percent");
    return -1;
  }
  tok = next;
  if (!tok) {
    fprintf (stderr, "%s: failed: string finished early, around token %s\n", __func__, "move_pv");
    return -1;
  }
  p = strchrnul (tok, ':');
  if (*p) next = p+1; else next = NULL;
  *p = '\0';
  r->move_pv = strdup (tok);
  if (r->move_pv == NULL) {
    perror ("strdup");
    return -1;
  }
  tok = next;
  if (!tok) {
    fprintf (stderr, "%s: failed: string finished early, around token %s\n", __func__, "lv_tags");
    return -1;
  }
  p = strchrnul (tok, ':');
  if (*p) next = p+1; else next = NULL;
  *p = '\0';
  r->lv_tags = strdup (tok);
  if (r->lv_tags == NULL) {
    perror ("strdup");
    return -1;
  }
  tok = next;
  if (!tok) {
    fprintf (stderr, "%s: failed: string finished early, around token %s\n", __func__, "mirror_log");
    return -1;
  }
  p = strchrnul (tok, ':');
  if (*p) next = p+1; else next = NULL;
  *p = '\0';
  r->mirror_log = strdup (tok);
  if (r->mirror_log == NULL) {
    perror ("strdup");
    return -1;
  }
  tok = next;
  if (!tok) {
    fprintf (stderr, "%s: failed: string finished early, around token %s\n", __func__, "modules");
    return -1;
  }
  p = strchrnul (tok, ':');
  if (*p) next = p+1; else next = NULL;
  *p = '\0';
  r->modules = strdup (tok);
  if (r->modules == NULL) {
    perror ("strdup");
    return -1;
  }
  tok = next;
  if (tok != NULL) {
    fprintf (stderr, "%s: failed: extra tokens at end of string\n", __func__);
    return -1;
  }
  return 0;
}

guestfs_int_lvm_lv_list *
parse_command_line_lvs (void)
{
  char *out, *err;
  char *p, *pend;
  int r, i;
  guestfs_int_lvm_lv_list *ret;
  void *newp;

  ret = malloc (sizeof *ret);
  if (!ret) {
    reply_with_perror ("malloc");
    return NULL;
  }

  ret->guestfs_int_lvm_lv_list_len = 0;
  ret->guestfs_int_lvm_lv_list_val = NULL;

  r = command (&out, &err,
	       "lvm", "lvs",
	       "-o", lvm_lv_cols, "--unbuffered", "--noheadings",
	       "--nosuffix", "--separator", ":", "--units", "b", NULL);
  if (r == -1) {
    reply_with_error ("%s", err);
    free (out);
    free (err);
    free (ret);
    return NULL;
  }

  free (err);

  /* Tokenize each line of the output. */
  p = out;
  i = 0;
  while (p) {
    pend = strchr (p, '\n');	/* Get the next line of output. */
    if (pend) {
      *pend = '\0';
      pend++;
    }

    while (*p && c_isspace (*p))	/* Skip any leading whitespace. */
      p++;

    if (!*p) {			/* Empty line?  Skip it. */
      p = pend;
      continue;
    }

    /* Allocate some space to store this next entry. */
    newp = realloc (ret->guestfs_int_lvm_lv_list_val,
		    sizeof (guestfs_int_lvm_lv) * (i+1));
    if (newp == NULL) {
      reply_with_perror ("realloc");
      free (ret->guestfs_int_lvm_lv_list_val);
      free (ret);
      free (out);
      return NULL;
    }
    ret->guestfs_int_lvm_lv_list_val = newp;

    /* Tokenize the next entry. */
    r = lvm_tokenize_lv (p, &ret->guestfs_int_lvm_lv_list_val[i]);
    if (r == -1) {
      reply_with_error ("failed to parse output of 'lvs' command");
      free (ret->guestfs_int_lvm_lv_list_val);
      free (ret);
      free (out);
      return NULL;
    }

    ++i;
    p = pend;
  }

  ret->guestfs_int_lvm_lv_list_len = i;

  free (out);
  return ret;
}
