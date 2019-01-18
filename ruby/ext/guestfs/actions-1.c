/* libguestfs generated file
 * WARNING: THIS FILE IS GENERATED FROM THE FOLLOWING FILES:
 *          generator/ruby.ml
 *          and from the code in the generator/ subdirectory.
 * ANY CHANGES YOU MAKE TO THIS FILE WILL BE LOST.
 *
 * Copyright (C) 2009-2019 Red Hat Inc.
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
#include <stdint.h>
#include <string.h>
#include <errno.h>
#include <assert.h>

#include "actions.h"

/*
 * call-seq:
 *   g.aug_clear(augpath) -> nil
 *
 * clear Augeas path
 *
 * Set the value associated with "path" to "NULL". This is
 * the same as the augtool(1) "clear" command.
 *
 *
 * [Since] Added in version 1.3.4.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_aug_clear}[http://libguestfs.org/guestfs.3.html#guestfs_aug_clear].
 */
VALUE
guestfs_int_ruby_aug_clear (VALUE gv, VALUE augpathv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "aug_clear");

  const char *augpath = StringValueCStr (augpathv);

  int r;

  r = guestfs_aug_clear (g, augpath);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.aug_defvar(name, expr) -> fixnum
 *
 * define an Augeas variable
 *
 * Defines an Augeas variable "name" whose value is the
 * result of evaluating "expr". If "expr" is NULL, then
 * "name" is undefined.
 * 
 * On success this returns the number of nodes in "expr",
 * or 0 if "expr" evaluates to something which is not a
 * nodeset.
 *
 *
 * [Since] Added in version 0.7.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_aug_defvar}[http://libguestfs.org/guestfs.3.html#guestfs_aug_defvar].
 */
VALUE
guestfs_int_ruby_aug_defvar (VALUE gv, VALUE namev, VALUE exprv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "aug_defvar");

  const char *name = StringValueCStr (namev);
  const char *expr = !NIL_P (exprv) ? StringValueCStr (exprv) : NULL;

  int r;

  r = guestfs_aug_defvar (g, name, expr);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return INT2NUM (r);
}

/*
 * call-seq:
 *   g.base64_in(base64file, filename) -> nil
 *
 * upload base64-encoded data to file
 *
 * This command uploads base64-encoded data from
 * "base64file" to filename.
 *
 *
 * [Since] Added in version 1.3.5.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_base64_in}[http://libguestfs.org/guestfs.3.html#guestfs_base64_in].
 */
VALUE
guestfs_int_ruby_base64_in (VALUE gv, VALUE base64filev, VALUE filenamev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "base64_in");

  const char *base64file = StringValueCStr (base64filev);
  const char *filename = StringValueCStr (filenamev);

  int r;

  r = guestfs_base64_in (g, base64file, filename);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.base64_out(filename, base64file) -> nil
 *
 * download file and encode as base64
 *
 * This command downloads the contents of filename, writing
 * it out to local file "base64file" encoded as base64.
 *
 *
 * [Since] Added in version 1.3.5.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_base64_out}[http://libguestfs.org/guestfs.3.html#guestfs_base64_out].
 */
VALUE
guestfs_int_ruby_base64_out (VALUE gv, VALUE filenamev, VALUE base64filev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "base64_out");

  const char *filename = StringValueCStr (filenamev);
  const char *base64file = StringValueCStr (base64filev);

  int r;

  r = guestfs_base64_out (g, filename, base64file);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.btrfs_balance_resume(path) -> nil
 *
 * resume a paused balance
 *
 * Resume a paused balance on a btrfs filesystem.
 *
 *
 * [Since] Added in version 1.29.22.
 *
 * [Feature] This function depends on the feature +btrfs+.  See also {#feature_available}[rdoc-ref:feature_available].
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_btrfs_balance_resume}[http://libguestfs.org/guestfs.3.html#guestfs_btrfs_balance_resume].
 */
VALUE
guestfs_int_ruby_btrfs_balance_resume (VALUE gv, VALUE pathv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "btrfs_balance_resume");

  const char *path = StringValueCStr (pathv);

  int r;

  r = guestfs_btrfs_balance_resume (g, path);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.btrfs_fsck(device, {optargs...}) -> nil
 *
 * check a btrfs filesystem
 *
 * Used to check a btrfs filesystem, "device" is the device
 * file where the filesystem is stored.
 * 
 * Optional arguments are supplied in the final hash
 * parameter, which is a hash of the argument name to its
 * value. Pass an empty {} for no optional arguments.
 *
 *
 * [Since] Added in version 1.17.43.
 *
 * [Feature] This function depends on the feature +btrfs+.  See also {#feature_available}[rdoc-ref:feature_available].
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_btrfs_fsck}[http://libguestfs.org/guestfs.3.html#guestfs_btrfs_fsck].
 */
VALUE
guestfs_int_ruby_btrfs_fsck (int argc, VALUE *argv, VALUE gv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "btrfs_fsck");

  if (argc < 1 || argc > 2)
    rb_raise (rb_eArgError, "expecting 1 or 2 arguments");

  volatile VALUE devicev = argv[0];
  volatile VALUE optargsv = argc > 1 ? argv[1] : rb_hash_new ();

  const char *device = StringValueCStr (devicev);

  Check_Type (optargsv, T_HASH);
  struct guestfs_btrfs_fsck_argv optargs_s = { .bitmask = 0 };
  struct guestfs_btrfs_fsck_argv *optargs = &optargs_s;
  volatile VALUE v;
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("superblock")));
  if (v != Qnil) {
    optargs_s.superblock = NUM2LL (v);
    optargs_s.bitmask |= GUESTFS_BTRFS_FSCK_SUPERBLOCK_BITMASK;
  }
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("repair")));
  if (v != Qnil) {
    optargs_s.repair = RTEST (v);
    optargs_s.bitmask |= GUESTFS_BTRFS_FSCK_REPAIR_BITMASK;
  }

  int r;

  r = guestfs_btrfs_fsck_argv (g, device, optargs);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.btrfs_qgroup_show(path) -> list
 *
 * show subvolume quota groups
 *
 * Show all subvolume quota groups in a btrfs filesystem,
 * including their usages.
 *
 *
 * [Since] Added in version 1.29.17.
 *
 * [Feature] This function depends on the feature +btrfs+.  See also {#feature_available}[rdoc-ref:feature_available].
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_btrfs_qgroup_show}[http://libguestfs.org/guestfs.3.html#guestfs_btrfs_qgroup_show].
 */
VALUE
guestfs_int_ruby_btrfs_qgroup_show (VALUE gv, VALUE pathv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "btrfs_qgroup_show");

  const char *path = StringValueCStr (pathv);

  struct guestfs_btrfsqgroup_list *r;

  r = guestfs_btrfs_qgroup_show (g, path);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  volatile VALUE rv = rb_ary_new2 (r->len);
  size_t i;
  for (i = 0; i < r->len; ++i) {
    volatile VALUE hv = rb_hash_new ();
    rb_hash_aset (hv, rb_str_new2 ("btrfsqgroup_id"), rb_str_new2 (r->val[i].btrfsqgroup_id));
    rb_hash_aset (hv, rb_str_new2 ("btrfsqgroup_rfer"), ULL2NUM (r->val[i].btrfsqgroup_rfer));
    rb_hash_aset (hv, rb_str_new2 ("btrfsqgroup_excl"), ULL2NUM (r->val[i].btrfsqgroup_excl));
    rb_ary_push (rv, hv);
  }
  guestfs_free_btrfsqgroup_list (r);
  return rv;
}

/*
 * call-seq:
 *   g.btrfs_rescue_chunk_recover(device) -> nil
 *
 * recover the chunk tree of btrfs filesystem
 *
 * Recover the chunk tree of btrfs filesystem by scanning
 * the devices one by one.
 *
 *
 * [Since] Added in version 1.29.22.
 *
 * [Feature] This function depends on the feature +btrfs+.  See also {#feature_available}[rdoc-ref:feature_available].
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_btrfs_rescue_chunk_recover}[http://libguestfs.org/guestfs.3.html#guestfs_btrfs_rescue_chunk_recover].
 */
VALUE
guestfs_int_ruby_btrfs_rescue_chunk_recover (VALUE gv, VALUE devicev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "btrfs_rescue_chunk_recover");

  const char *device = StringValueCStr (devicev);

  int r;

  r = guestfs_btrfs_rescue_chunk_recover (g, device);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.btrfs_scrub_resume(path) -> nil
 *
 * resume a previously canceled or interrupted scrub
 *
 * Resume a previously canceled or interrupted scrub on a
 * btrfs filesystem.
 *
 *
 * [Since] Added in version 1.29.22.
 *
 * [Feature] This function depends on the feature +btrfs+.  See also {#feature_available}[rdoc-ref:feature_available].
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_btrfs_scrub_resume}[http://libguestfs.org/guestfs.3.html#guestfs_btrfs_scrub_resume].
 */
VALUE
guestfs_int_ruby_btrfs_scrub_resume (VALUE gv, VALUE pathv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "btrfs_scrub_resume");

  const char *path = StringValueCStr (pathv);

  int r;

  r = guestfs_btrfs_scrub_resume (g, path);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.cat(path) -> string
 *
 * list the contents of a file
 *
 * Return the contents of the file named "path".
 * 
 * Because, in C, this function returns a "char *", there
 * is no way to differentiate between a "\0" character in a
 * file and end of string. To handle binary files, use the
 * "g.read_file" or "g.download" functions.
 *
 *
 * [Since] Added in version 0.4.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_cat}[http://libguestfs.org/guestfs.3.html#guestfs_cat].
 */
VALUE
guestfs_int_ruby_cat (VALUE gv, VALUE pathv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "cat");

  const char *path = StringValueCStr (pathv);

  char *r;

  r = guestfs_cat (g, path);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  volatile VALUE rv = rb_str_new2 (r);
  free (r);
  return rv;
}

/*
 * call-seq:
 *   g.checksum_device(csumtype, device) -> string
 *
 * compute MD5, SHAx or CRC checksum of the contents of a device
 *
 * This call computes the MD5, SHAx or CRC checksum of the
 * contents of the device named "device". For the types of
 * checksums supported see the "g.checksum" command.
 *
 *
 * [Since] Added in version 1.3.2.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_checksum_device}[http://libguestfs.org/guestfs.3.html#guestfs_checksum_device].
 */
VALUE
guestfs_int_ruby_checksum_device (VALUE gv, VALUE csumtypev, VALUE devicev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "checksum_device");

  const char *csumtype = StringValueCStr (csumtypev);
  const char *device = StringValueCStr (devicev);

  char *r;

  r = guestfs_checksum_device (g, csumtype, device);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  volatile VALUE rv = rb_str_new2 (r);
  free (r);
  return rv;
}

/*
 * call-seq:
 *   g.clear_backend_setting(name) -> fixnum
 *
 * remove a single per-backend settings string
 *
 * If there is a backend setting string matching "name" or
 * beginning with "name=", then that string is removed from
 * the backend settings.
 * 
 * This call returns the number of strings which were
 * removed (which may be 0, 1 or greater than 1).
 * 
 * See "BACKEND" in guestfs(3), "BACKEND SETTINGS" in
 * guestfs(3).
 *
 *
 * [Since] Added in version 1.27.2.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_clear_backend_setting}[http://libguestfs.org/guestfs.3.html#guestfs_clear_backend_setting].
 */
VALUE
guestfs_int_ruby_clear_backend_setting (VALUE gv, VALUE namev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "clear_backend_setting");

  const char *name = StringValueCStr (namev);

  int r;

  r = guestfs_clear_backend_setting (g, name);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return INT2NUM (r);
}

/*
 * call-seq:
 *   g.config(hvparam, hvvalue) -> nil
 *
 * add hypervisor parameters
 *
 * This can be used to add arbitrary hypervisor parameters
 * of the form *-param value*. Actually it’s not quite
 * arbitrary - we prevent you from setting some parameters
 * which would interfere with parameters that we use.
 * 
 * The first character of "hvparam" string must be a "-"
 * (dash).
 * 
 * "hvvalue" can be NULL.
 *
 *
 * [Since] Added in version 0.3.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_config}[http://libguestfs.org/guestfs.3.html#guestfs_config].
 */
VALUE
guestfs_int_ruby_config (VALUE gv, VALUE hvparamv, VALUE hvvaluev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "config");

  const char *hvparam = StringValueCStr (hvparamv);
  const char *hvvalue = !NIL_P (hvvaluev) ? StringValueCStr (hvvaluev) : NULL;

  int r;

  r = guestfs_config (g, hvparam, hvvalue);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.copy_attributes(src, dest, {optargs...}) -> nil
 *
 * copy the attributes of a path (file/directory) to another
 *
 * Copy the attributes of a path (which can be a file or a
 * directory) to another path.
 * 
 * By default "no" attribute is copied, so make sure to
 * specify any (or "all" to copy everything).
 * 
 * The optional arguments specify which attributes can be
 * copied:
 * 
 * "mode"
 * Copy part of the file mode from "source" to
 * "destination". Only the UNIX permissions and the
 * sticky/setuid/setgid bits can be copied.
 * 
 * "xattributes"
 * Copy the Linux extended attributes (xattrs) from
 * "source" to "destination". This flag does nothing if
 * the *linuxxattrs* feature is not available (see
 * "g.feature_available").
 * 
 * "ownership"
 * Copy the owner uid and the group gid of "source" to
 * "destination".
 * 
 * "all"
 * Copy all the attributes from "source" to
 * "destination". Enabling it enables all the other
 * flags, if they are not specified already.
 * 
 * Optional arguments are supplied in the final hash
 * parameter, which is a hash of the argument name to its
 * value. Pass an empty {} for no optional arguments.
 *
 *
 * [Since] Added in version 1.25.21.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_copy_attributes}[http://libguestfs.org/guestfs.3.html#guestfs_copy_attributes].
 */
VALUE
guestfs_int_ruby_copy_attributes (int argc, VALUE *argv, VALUE gv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "copy_attributes");

  if (argc < 2 || argc > 3)
    rb_raise (rb_eArgError, "expecting 2 or 3 arguments");

  volatile VALUE srcv = argv[0];
  volatile VALUE destv = argv[1];
  volatile VALUE optargsv = argc > 2 ? argv[2] : rb_hash_new ();

  const char *src = StringValueCStr (srcv);
  const char *dest = StringValueCStr (destv);

  Check_Type (optargsv, T_HASH);
  struct guestfs_copy_attributes_argv optargs_s = { .bitmask = 0 };
  struct guestfs_copy_attributes_argv *optargs = &optargs_s;
  volatile VALUE v;
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("all")));
  if (v != Qnil) {
    optargs_s.all = RTEST (v);
    optargs_s.bitmask |= GUESTFS_COPY_ATTRIBUTES_ALL_BITMASK;
  }
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("mode")));
  if (v != Qnil) {
    optargs_s.mode = RTEST (v);
    optargs_s.bitmask |= GUESTFS_COPY_ATTRIBUTES_MODE_BITMASK;
  }
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("xattributes")));
  if (v != Qnil) {
    optargs_s.xattributes = RTEST (v);
    optargs_s.bitmask |= GUESTFS_COPY_ATTRIBUTES_XATTRIBUTES_BITMASK;
  }
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("ownership")));
  if (v != Qnil) {
    optargs_s.ownership = RTEST (v);
    optargs_s.bitmask |= GUESTFS_COPY_ATTRIBUTES_OWNERSHIP_BITMASK;
  }

  int r;

  r = guestfs_copy_attributes_argv (g, src, dest, optargs);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.copy_device_to_device(src, dest, {optargs...}) -> nil
 *
 * copy from source device to destination device
 *
 * The four calls "g.copy_device_to_device",
 * "g.copy_device_to_file", "g.copy_file_to_device", and
 * "g.copy_file_to_file" let you copy from a source
 * (device|file) to a destination (device|file).
 * 
 * Partial copies can be made since you can specify
 * optionally the source offset, destination offset and
 * size to copy. These values are all specified in bytes.
 * If not given, the offsets both default to zero, and the
 * size defaults to copying as much as possible until we
 * hit the end of the source.
 * 
 * The source and destination may be the same object.
 * However overlapping regions may not be copied correctly.
 * 
 * If the destination is a file, it is created if required.
 * If the destination file is not large enough, it is
 * extended.
 * 
 * If the destination is a file and the "append" flag is
 * not set, then the destination file is truncated. If the
 * "append" flag is set, then the copy appends to the
 * destination file. The "append" flag currently cannot be
 * set for devices.
 * 
 * If the "sparse" flag is true then the call avoids
 * writing blocks that contain only zeroes, which can help
 * in some situations where the backing disk is
 * thin-provisioned. Note that unless the target is already
 * zeroed, using this option will result in incorrect
 * copying.
 * 
 * Optional arguments are supplied in the final hash
 * parameter, which is a hash of the argument name to its
 * value. Pass an empty {} for no optional arguments.
 *
 *
 * [Since] Added in version 1.13.25.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_copy_device_to_device}[http://libguestfs.org/guestfs.3.html#guestfs_copy_device_to_device].
 */
VALUE
guestfs_int_ruby_copy_device_to_device (int argc, VALUE *argv, VALUE gv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "copy_device_to_device");

  if (argc < 2 || argc > 3)
    rb_raise (rb_eArgError, "expecting 2 or 3 arguments");

  volatile VALUE srcv = argv[0];
  volatile VALUE destv = argv[1];
  volatile VALUE optargsv = argc > 2 ? argv[2] : rb_hash_new ();

  const char *src = StringValueCStr (srcv);
  const char *dest = StringValueCStr (destv);

  Check_Type (optargsv, T_HASH);
  struct guestfs_copy_device_to_device_argv optargs_s = { .bitmask = 0 };
  struct guestfs_copy_device_to_device_argv *optargs = &optargs_s;
  volatile VALUE v;
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("srcoffset")));
  if (v != Qnil) {
    optargs_s.srcoffset = NUM2LL (v);
    optargs_s.bitmask |= GUESTFS_COPY_DEVICE_TO_DEVICE_SRCOFFSET_BITMASK;
  }
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("destoffset")));
  if (v != Qnil) {
    optargs_s.destoffset = NUM2LL (v);
    optargs_s.bitmask |= GUESTFS_COPY_DEVICE_TO_DEVICE_DESTOFFSET_BITMASK;
  }
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("size")));
  if (v != Qnil) {
    optargs_s.size = NUM2LL (v);
    optargs_s.bitmask |= GUESTFS_COPY_DEVICE_TO_DEVICE_SIZE_BITMASK;
  }
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("sparse")));
  if (v != Qnil) {
    optargs_s.sparse = RTEST (v);
    optargs_s.bitmask |= GUESTFS_COPY_DEVICE_TO_DEVICE_SPARSE_BITMASK;
  }
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("append")));
  if (v != Qnil) {
    optargs_s.append = RTEST (v);
    optargs_s.bitmask |= GUESTFS_COPY_DEVICE_TO_DEVICE_APPEND_BITMASK;
  }

  int r;

  r = guestfs_copy_device_to_device_argv (g, src, dest, optargs);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.dd(src, dest) -> nil
 *
 * copy from source to destination using dd
 *
 * This command copies from one source device or file "src"
 * to another destination device or file "dest". Normally
 * you would use this to copy to or from a device or
 * partition, for example to duplicate a filesystem.
 * 
 * If the destination is a device, it must be as large or
 * larger than the source file or device, otherwise the
 * copy will fail. This command cannot do partial copies
 * (see "g.copy_device_to_device").
 *
 *
 * [Since] Added in version 1.0.80.
 *
 * [Deprecated] In new code, use rdoc-ref:copy_device_to_device instead.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_dd}[http://libguestfs.org/guestfs.3.html#guestfs_dd].
 */
VALUE
guestfs_int_ruby_dd (VALUE gv, VALUE srcv, VALUE destv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "dd");

  const char *src = StringValueCStr (srcv);
  const char *dest = StringValueCStr (destv);

  int r;

  r = guestfs_dd (g, src, dest);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.debug_drives
 *
 * :nodoc:
 */
VALUE
guestfs_int_ruby_debug_drives (VALUE gv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "debug_drives");


  char **r;

  r = guestfs_debug_drives (g);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  size_t i, len = 0;
  for (i = 0; r[i] != NULL; ++i) len++;
  volatile VALUE rv = rb_ary_new2 (len);
  for (i = 0; r[i] != NULL; ++i) {
    rb_ary_push (rv, rb_str_new2 (r[i]));
    free (r[i]);
  }
  free (r);
  return rv;
}

/*
 * call-seq:
 *   g.device_index(device) -> fixnum
 *
 * convert device to index
 *
 * This function takes a device name (eg. "/dev/sdb") and
 * returns the index of the device in the list of devices.
 * 
 * Index numbers start from 0. The named device must exist,
 * for example as a string returned from "g.list_devices".
 * 
 * See also "g.list_devices", "g.part_to_dev".
 *
 *
 * [Since] Added in version 1.19.7.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_device_index}[http://libguestfs.org/guestfs.3.html#guestfs_device_index].
 */
VALUE
guestfs_int_ruby_device_index (VALUE gv, VALUE devicev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "device_index");

  const char *device = StringValueCStr (devicev);

  int r;

  r = guestfs_device_index (g, device);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return INT2NUM (r);
}

/*
 * call-seq:
 *   g.download_inode(device, inode, filename) -> nil
 *
 * download a file to the local machine given its inode
 *
 * Download a file given its inode from the disk partition
 * (eg. /dev/sda1) and save it as filename on the local
 * machine.
 * 
 * It is not required to mount the disk to run this
 * command.
 * 
 * The command is capable of downloading deleted or
 * inaccessible files.
 *
 *
 * [Since] Added in version 1.33.14.
 *
 * [Feature] This function depends on the feature +sleuthkit+.  See also {#feature_available}[rdoc-ref:feature_available].
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_download_inode}[http://libguestfs.org/guestfs.3.html#guestfs_download_inode].
 */
VALUE
guestfs_int_ruby_download_inode (VALUE gv, VALUE devicev, VALUE inodev, VALUE filenamev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "download_inode");

  const char *device = StringValueCStr (devicev);
  long long inode = NUM2LL (inodev);
  const char *filename = StringValueCStr (filenamev);

  int r;

  r = guestfs_download_inode (g, device, inode, filename);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.exists(path) -> [True|False]
 *
 * test if file or directory exists
 *
 * This returns "true" if and only if there is a file,
 * directory (or anything) with the given "path" name.
 * 
 * See also "g.is_file", "g.is_dir", "g.stat".
 *
 *
 * [Since] Added in version 0.8.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_exists}[http://libguestfs.org/guestfs.3.html#guestfs_exists].
 */
VALUE
guestfs_int_ruby_exists (VALUE gv, VALUE pathv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "exists");

  const char *path = StringValueCStr (pathv);

  int r;

  r = guestfs_exists (g, path);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return INT2NUM (r);
}

/*
 * call-seq:
 *   g.f2fs_expand(device) -> nil
 *
 * expand a f2fs filesystem
 *
 * This expands a f2fs filesystem to match the size of the
 * underlying device.
 *
 *
 * [Since] Added in version 1.39.3.
 *
 * [Feature] This function depends on the feature +f2fs+.  See also {#feature_available}[rdoc-ref:feature_available].
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_f2fs_expand}[http://libguestfs.org/guestfs.3.html#guestfs_f2fs_expand].
 */
VALUE
guestfs_int_ruby_f2fs_expand (VALUE gv, VALUE devicev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "f2fs_expand");

  const char *device = StringValueCStr (devicev);

  int r;

  r = guestfs_f2fs_expand (g, device);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.filesystem_walk(device) -> list
 *
 * walk through the filesystem content
 *
 * Walk through the internal structures of a disk partition
 * (eg. /dev/sda1) in order to return a list of all the
 * files and directories stored within.
 * 
 * It is not necessary to mount the disk partition to run
 * this command.
 * 
 * All entries in the filesystem are returned. This
 * function can list deleted or unaccessible files. The
 * entries are *not* sorted.
 * 
 * The "tsk_dirent" structure contains the following
 * fields.
 * 
 * "tsk_inode"
 * Filesystem reference number of the node. It might be
 * 0 if the node has been deleted.
 * 
 * "tsk_type"
 * Basic file type information. See below for a
 * detailed list of values.
 * 
 * "tsk_size"
 * File size in bytes. It might be -1 if the node has
 * been deleted.
 * 
 * "tsk_name"
 * The file path relative to its directory.
 * 
 * "tsk_flags"
 * Bitfield containing extra information regarding the
 * entry. It contains the logical OR of the following
 * values:
 * 
 * 0x0001
 * If set to 1, the file is allocated and visible
 * within the filesystem. Otherwise, the file has
 * been deleted. Under certain circumstances, the
 * function "download_inode" can be used to recover
 * deleted files.
 * 
 * 0x0002
 * Filesystem such as NTFS and Ext2 or greater,
 * separate the file name from the metadata
 * structure. The bit is set to 1 when the file
 * name is in an unallocated state and the metadata
 * structure is in an allocated one. This generally
 * implies the metadata has been reallocated to a
 * new file. Therefore, information such as file
 * type, file size, timestamps, number of links and
 * symlink target might not correspond with the
 * ones of the original deleted entry.
 * 
 * 0x0004
 * The bit is set to 1 when the file is compressed
 * using filesystem native compression support
 * (NTFS). The API is not able to detect
 * application level compression.
 * 
 * "tsk_atime_sec"
 * "tsk_atime_nsec"
 * "tsk_mtime_sec"
 * "tsk_mtime_nsec"
 * "tsk_ctime_sec"
 * "tsk_ctime_nsec"
 * "tsk_crtime_sec"
 * "tsk_crtime_nsec"
 * Respectively, access, modification, last status
 * change and creation time in Unix format in seconds
 * and nanoseconds.
 * 
 * "tsk_nlink"
 * Number of file names pointing to this entry.
 * 
 * "tsk_link"
 * If the entry is a symbolic link, this field will
 * contain the path to the target file.
 * 
 * The "tsk_type" field will contain one of the following
 * characters:
 * 
 * 'b' Block special
 * 
 * 'c' Char special
 * 
 * 'd' Directory
 * 
 * 'f' FIFO (named pipe)
 * 
 * 'l' Symbolic link
 * 
 * 'r' Regular file
 * 
 * 's' Socket
 * 
 * 'h' Shadow inode (Solaris)
 * 
 * 'w' Whiteout inode (BSD)
 * 
 * 'u' Unknown file type
 *
 *
 * [Since] Added in version 1.33.39.
 *
 * [Feature] This function depends on the feature +libtsk+.  See also {#feature_available}[rdoc-ref:feature_available].
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_filesystem_walk}[http://libguestfs.org/guestfs.3.html#guestfs_filesystem_walk].
 */
VALUE
guestfs_int_ruby_filesystem_walk (VALUE gv, VALUE devicev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "filesystem_walk");

  const char *device = StringValueCStr (devicev);

  struct guestfs_tsk_dirent_list *r;

  r = guestfs_filesystem_walk (g, device);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  volatile VALUE rv = rb_ary_new2 (r->len);
  size_t i;
  for (i = 0; i < r->len; ++i) {
    volatile VALUE hv = rb_hash_new ();
    rb_hash_aset (hv, rb_str_new2 ("tsk_inode"), ULL2NUM (r->val[i].tsk_inode));
    rb_hash_aset (hv, rb_str_new2 ("tsk_type"), ULL2NUM (r->val[i].tsk_type));
    rb_hash_aset (hv, rb_str_new2 ("tsk_size"), LL2NUM (r->val[i].tsk_size));
    rb_hash_aset (hv, rb_str_new2 ("tsk_name"), rb_str_new2 (r->val[i].tsk_name));
    rb_hash_aset (hv, rb_str_new2 ("tsk_flags"), UINT2NUM (r->val[i].tsk_flags));
    rb_hash_aset (hv, rb_str_new2 ("tsk_atime_sec"), LL2NUM (r->val[i].tsk_atime_sec));
    rb_hash_aset (hv, rb_str_new2 ("tsk_atime_nsec"), LL2NUM (r->val[i].tsk_atime_nsec));
    rb_hash_aset (hv, rb_str_new2 ("tsk_mtime_sec"), LL2NUM (r->val[i].tsk_mtime_sec));
    rb_hash_aset (hv, rb_str_new2 ("tsk_mtime_nsec"), LL2NUM (r->val[i].tsk_mtime_nsec));
    rb_hash_aset (hv, rb_str_new2 ("tsk_ctime_sec"), LL2NUM (r->val[i].tsk_ctime_sec));
    rb_hash_aset (hv, rb_str_new2 ("tsk_ctime_nsec"), LL2NUM (r->val[i].tsk_ctime_nsec));
    rb_hash_aset (hv, rb_str_new2 ("tsk_crtime_sec"), LL2NUM (r->val[i].tsk_crtime_sec));
    rb_hash_aset (hv, rb_str_new2 ("tsk_crtime_nsec"), LL2NUM (r->val[i].tsk_crtime_nsec));
    rb_hash_aset (hv, rb_str_new2 ("tsk_nlink"), LL2NUM (r->val[i].tsk_nlink));
    rb_hash_aset (hv, rb_str_new2 ("tsk_link"), rb_str_new2 (r->val[i].tsk_link));
    rb_hash_aset (hv, rb_str_new2 ("tsk_spare1"), LL2NUM (r->val[i].tsk_spare1));
    rb_ary_push (rv, hv);
  }
  guestfs_free_tsk_dirent_list (r);
  return rv;
}

/*
 * call-seq:
 *   g.fill_dir(dir, nr) -> nil
 *
 * fill a directory with empty files
 *
 * This function, useful for testing filesystems, creates
 * "nr" empty files in the directory "dir" with names
 * 00000000 through "nr-1" (ie. each file name is 8 digits
 * long padded with zeroes).
 *
 *
 * [Since] Added in version 1.19.32.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_fill_dir}[http://libguestfs.org/guestfs.3.html#guestfs_fill_dir].
 */
VALUE
guestfs_int_ruby_fill_dir (VALUE gv, VALUE dirv, VALUE nrv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "fill_dir");

  const char *dir = StringValueCStr (dirv);
  int nr = NUM2INT (nrv);

  int r;

  r = guestfs_fill_dir (g, dir, nr);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.findfs_label(label) -> string
 *
 * find a filesystem by label
 *
 * This command searches the filesystems and returns the
 * one which has the given label. An error is returned if
 * no such filesystem can be found.
 * 
 * To find the label of a filesystem, use "g.vfs_label".
 *
 *
 * [Since] Added in version 1.5.3.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_findfs_label}[http://libguestfs.org/guestfs.3.html#guestfs_findfs_label].
 */
VALUE
guestfs_int_ruby_findfs_label (VALUE gv, VALUE labelv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "findfs_label");

  const char *label = StringValueCStr (labelv);

  char *r;

  r = guestfs_findfs_label (g, label);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  volatile VALUE rv = rb_str_new2 (r);
  free (r);
  return rv;
}

/*
 * call-seq:
 *   g.get_identifier() -> string
 *
 * get the handle identifier
 *
 * Get the handle identifier. See "g.set_identifier".
 *
 *
 * [Since] Added in version 1.31.14.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_get_identifier}[http://libguestfs.org/guestfs.3.html#guestfs_get_identifier].
 */
VALUE
guestfs_int_ruby_get_identifier (VALUE gv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "get_identifier");


  const char *r;

  r = guestfs_get_identifier (g);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return rb_str_new2 (r);
}

/*
 * call-seq:
 *   g.get_libvirt_requested_credential_prompt(index) -> string
 *
 * prompt of i'th requested credential
 *
 * Get the prompt (provided by libvirt) for the "index"'th
 * requested credential. If libvirt did not provide a
 * prompt, this returns the empty string "".
 * 
 * See "LIBVIRT AUTHENTICATION" in guestfs(3) for
 * documentation and example code.
 *
 *
 * [Since] Added in version 1.19.52.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_get_libvirt_requested_credential_prompt}[http://libguestfs.org/guestfs.3.html#guestfs_get_libvirt_requested_credential_prompt].
 */
VALUE
guestfs_int_ruby_get_libvirt_requested_credential_prompt (VALUE gv, VALUE indexv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "get_libvirt_requested_credential_prompt");

  int index = NUM2INT (indexv);

  char *r;

  r = guestfs_get_libvirt_requested_credential_prompt (g, index);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  volatile VALUE rv = rb_str_new2 (r);
  free (r);
  return rv;
}

/*
 * call-seq:
 *   g.get_network() -> [True|False]
 *
 * get enable network flag
 *
 * This returns the enable network flag.
 *
 *
 * [Since] Added in version 1.5.4.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_get_network}[http://libguestfs.org/guestfs.3.html#guestfs_get_network].
 */
VALUE
guestfs_int_ruby_get_network (VALUE gv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "get_network");


  int r;

  r = guestfs_get_network (g);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return INT2NUM (r);
}

/*
 * call-seq:
 *   g.get_qemu() -> string
 *
 * get the hypervisor binary (usually qemu)
 *
 * Return the current hypervisor binary (usually qemu).
 * 
 * This is always non-NULL. If it wasn't set already, then
 * this will return the default qemu binary name.
 *
 *
 * [Since] Added in version 1.0.6.
 *
 * [Deprecated] In new code, use rdoc-ref:get_hv instead.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_get_qemu}[http://libguestfs.org/guestfs.3.html#guestfs_get_qemu].
 */
VALUE
guestfs_int_ruby_get_qemu (VALUE gv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "get_qemu");


  const char *r;

  r = guestfs_get_qemu (g);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return rb_str_new2 (r);
}

/*
 * call-seq:
 *   g.get_state() -> fixnum
 *
 * get the current state
 *
 * This returns the current state as an opaque integer.
 * This is only useful for printing debug and internal
 * error messages.
 * 
 * For more information on states, see guestfs(3).
 *
 *
 * [Since] Added in version 1.0.2.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_get_state}[http://libguestfs.org/guestfs.3.html#guestfs_get_state].
 */
VALUE
guestfs_int_ruby_get_state (VALUE gv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "get_state");


  int r;

  r = guestfs_get_state (g);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return INT2NUM (r);
}

/*
 * call-seq:
 *   g.get_umask() -> fixnum
 *
 * get the current umask
 *
 * Return the current umask. By default the umask is 022
 * unless it has been set by calling "g.umask".
 *
 *
 * [Since] Added in version 1.3.4.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_get_umask}[http://libguestfs.org/guestfs.3.html#guestfs_get_umask].
 */
VALUE
guestfs_int_ruby_get_umask (VALUE gv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "get_umask");


  int r;

  r = guestfs_get_umask (g);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return INT2NUM (r);
}

/*
 * call-seq:
 *   g.get_verbose() -> [True|False]
 *
 * get verbose mode
 *
 * This returns the verbose messages flag.
 *
 *
 * [Since] Added in version 0.3.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_get_verbose}[http://libguestfs.org/guestfs.3.html#guestfs_get_verbose].
 */
VALUE
guestfs_int_ruby_get_verbose (VALUE gv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "get_verbose");


  int r;

  r = guestfs_get_verbose (g);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return INT2NUM (r);
}

/*
 * call-seq:
 *   g.getxattrs(path) -> list
 *
 * list extended attributes of a file or directory
 *
 * This call lists the extended attributes of the file or
 * directory "path".
 * 
 * At the system call level, this is a combination of the
 * listxattr(2) and getxattr(2) calls.
 * 
 * See also: "g.lgetxattrs", attr(5).
 *
 *
 * [Since] Added in version 1.0.59.
 *
 * [Feature] This function depends on the feature +linuxxattrs+.  See also {#feature_available}[rdoc-ref:feature_available].
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_getxattrs}[http://libguestfs.org/guestfs.3.html#guestfs_getxattrs].
 */
VALUE
guestfs_int_ruby_getxattrs (VALUE gv, VALUE pathv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "getxattrs");

  const char *path = StringValueCStr (pathv);

  struct guestfs_xattr_list *r;

  r = guestfs_getxattrs (g, path);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  volatile VALUE rv = rb_ary_new2 (r->len);
  size_t i;
  for (i = 0; i < r->len; ++i) {
    volatile VALUE hv = rb_hash_new ();
    rb_hash_aset (hv, rb_str_new2 ("attrname"), rb_str_new2 (r->val[i].attrname));
    rb_hash_aset (hv, rb_str_new2 ("attrval"), rb_str_new (r->val[i].attrval, r->val[i].attrval_len));
    rb_ary_push (rv, hv);
  }
  guestfs_free_xattr_list (r);
  return rv;
}

/*
 * call-seq:
 *   g.grep(regex, path, {optargs...}) -> list
 *
 * return lines matching a pattern
 *
 * This calls the external "grep" program and returns the
 * matching lines.
 * 
 * The optional flags are:
 * 
 * "extended"
 * Use extended regular expressions. This is the same
 * as using the *-E* flag.
 * 
 * "fixed"
 * Match fixed (don't use regular expressions). This is
 * the same as using the *-F* flag.
 * 
 * "insensitive"
 * Match case-insensitive. This is the same as using
 * the *-i* flag.
 * 
 * "compressed"
 * Use "zgrep" instead of "grep". This allows the input
 * to be compress- or gzip-compressed.
 * 
 * Optional arguments are supplied in the final hash
 * parameter, which is a hash of the argument name to its
 * value. Pass an empty {} for no optional arguments.
 * 
 * Because of the message protocol, there is a transfer
 * limit of somewhere between 2MB and 4MB. See "PROTOCOL
 * LIMITS" in guestfs(3).
 *
 *
 * [Since] Added in version 1.0.66.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_grep}[http://libguestfs.org/guestfs.3.html#guestfs_grep].
 */
VALUE
guestfs_int_ruby_grep (int argc, VALUE *argv, VALUE gv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "grep");

  if (argc < 2 || argc > 3)
    rb_raise (rb_eArgError, "expecting 2 or 3 arguments");

  volatile VALUE regexv = argv[0];
  volatile VALUE pathv = argv[1];
  volatile VALUE optargsv = argc > 2 ? argv[2] : rb_hash_new ();

  const char *regex = StringValueCStr (regexv);
  const char *path = StringValueCStr (pathv);

  Check_Type (optargsv, T_HASH);
  struct guestfs_grep_opts_argv optargs_s = { .bitmask = 0 };
  struct guestfs_grep_opts_argv *optargs = &optargs_s;
  volatile VALUE v;
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("extended")));
  if (v != Qnil) {
    optargs_s.extended = RTEST (v);
    optargs_s.bitmask |= GUESTFS_GREP_OPTS_EXTENDED_BITMASK;
  }
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("fixed")));
  if (v != Qnil) {
    optargs_s.fixed = RTEST (v);
    optargs_s.bitmask |= GUESTFS_GREP_OPTS_FIXED_BITMASK;
  }
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("insensitive")));
  if (v != Qnil) {
    optargs_s.insensitive = RTEST (v);
    optargs_s.bitmask |= GUESTFS_GREP_OPTS_INSENSITIVE_BITMASK;
  }
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("compressed")));
  if (v != Qnil) {
    optargs_s.compressed = RTEST (v);
    optargs_s.bitmask |= GUESTFS_GREP_OPTS_COMPRESSED_BITMASK;
  }

  char **r;

  r = guestfs_grep_opts_argv (g, regex, path, optargs);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  size_t i, len = 0;
  for (i = 0; r[i] != NULL; ++i) len++;
  volatile VALUE rv = rb_ary_new2 (len);
  for (i = 0; r[i] != NULL; ++i) {
    rb_ary_push (rv, rb_str_new2 (r[i]));
    free (r[i]);
  }
  free (r);
  return rv;
}

/*
 * call-seq:
 *   g.hivex_node_parent(nodeh) -> fixnum
 *
 * return the parent of node
 *
 * Return the parent node of "nodeh".
 * 
 * This is a wrapper around the hivex(3) call of the same
 * name.
 *
 *
 * [Since] Added in version 1.19.35.
 *
 * [Feature] This function depends on the feature +hivex+.  See also {#feature_available}[rdoc-ref:feature_available].
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_hivex_node_parent}[http://libguestfs.org/guestfs.3.html#guestfs_hivex_node_parent].
 */
VALUE
guestfs_int_ruby_hivex_node_parent (VALUE gv, VALUE nodehv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "hivex_node_parent");

  long long nodeh = NUM2LL (nodehv);

  int64_t r;

  r = guestfs_hivex_node_parent (g, nodeh);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return ULL2NUM (r);
}

/*
 * call-seq:
 *   g.hivex_root() -> fixnum
 *
 * return the root node of the hive
 *
 * Return the root node of the hive.
 * 
 * This is a wrapper around the hivex(3) call of the same
 * name.
 *
 *
 * [Since] Added in version 1.19.35.
 *
 * [Feature] This function depends on the feature +hivex+.  See also {#feature_available}[rdoc-ref:feature_available].
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_hivex_root}[http://libguestfs.org/guestfs.3.html#guestfs_hivex_root].
 */
VALUE
guestfs_int_ruby_hivex_root (VALUE gv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "hivex_root");


  int64_t r;

  r = guestfs_hivex_root (g);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return ULL2NUM (r);
}

/*
 * call-seq:
 *   g.hivex_value_string(valueh) -> string
 *
 * return the data field as a UTF-8 string
 *
 * This calls "g.hivex_value_value" (which returns the data
 * field from a hivex value tuple). It then assumes that
 * the field is a UTF-16LE string and converts the result
 * to UTF-8 (or if this is not possible, it returns an
 * error).
 * 
 * This is useful for reading strings out of the Windows
 * registry. However it is not foolproof because the
 * registry is not strongly-typed and fields can contain
 * arbitrary or unexpected data.
 *
 *
 * [Since] Added in version 1.37.22.
 *
 * [Feature] This function depends on the feature +hivex+.  See also {#feature_available}[rdoc-ref:feature_available].
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_hivex_value_string}[http://libguestfs.org/guestfs.3.html#guestfs_hivex_value_string].
 */
VALUE
guestfs_int_ruby_hivex_value_string (VALUE gv, VALUE valuehv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "hivex_value_string");

  long long valueh = NUM2LL (valuehv);

  char *r;

  r = guestfs_hivex_value_string (g, valueh);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  volatile VALUE rv = rb_str_new2 (r);
  free (r);
  return rv;
}

/*
 * call-seq:
 *   g.hivex_value_value(valueh) -> string
 *
 * return the data field from the (key, datatype, data) tuple
 *
 * Return the data field of a (key, datatype, data) tuple.
 * 
 * This is a wrapper around the hivex(3) call of the same
 * name.
 * 
 * See also: "g.hivex_value_utf8".
 *
 *
 * [Since] Added in version 1.19.35.
 *
 * [Feature] This function depends on the feature +hivex+.  See also {#feature_available}[rdoc-ref:feature_available].
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_hivex_value_value}[http://libguestfs.org/guestfs.3.html#guestfs_hivex_value_value].
 */
VALUE
guestfs_int_ruby_hivex_value_value (VALUE gv, VALUE valuehv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "hivex_value_value");

  long long valueh = NUM2LL (valuehv);

  char *r;
  size_t size;

  r = guestfs_hivex_value_value (g, valueh, &size);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  volatile VALUE rv = rb_str_new (r, size);
  free (r);
  return rv;
}

/*
 * call-seq:
 *   g.initrd_list(path) -> list
 *
 * list files in an initrd
 *
 * This command lists out files contained in an initrd.
 * 
 * The files are listed without any initial / character.
 * The files are listed in the order they appear (not
 * necessarily alphabetical). Directory names are listed as
 * separate items.
 * 
 * Old Linux kernels (2.4 and earlier) used a compressed
 * ext2 filesystem as initrd. We *only* support the newer
 * initramfs format (compressed cpio files).
 *
 *
 * [Since] Added in version 1.0.54.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_initrd_list}[http://libguestfs.org/guestfs.3.html#guestfs_initrd_list].
 */
VALUE
guestfs_int_ruby_initrd_list (VALUE gv, VALUE pathv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "initrd_list");

  const char *path = StringValueCStr (pathv);

  char **r;

  r = guestfs_initrd_list (g, path);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  size_t i, len = 0;
  for (i = 0; r[i] != NULL; ++i) len++;
  volatile VALUE rv = rb_ary_new2 (len);
  for (i = 0; r[i] != NULL; ++i) {
    rb_ary_push (rv, rb_str_new2 (r[i]));
    free (r[i]);
  }
  free (r);
  return rv;
}

/*
 * call-seq:
 *   g.inotify_files() -> list
 *
 * return list of watched files that had events
 *
 * This function is a helpful wrapper around
 * "g.inotify_read" which just returns a list of pathnames
 * of objects that were touched. The returned pathnames are
 * sorted and deduplicated.
 *
 *
 * [Since] Added in version 1.0.66.
 *
 * [Feature] This function depends on the feature +inotify+.  See also {#feature_available}[rdoc-ref:feature_available].
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_inotify_files}[http://libguestfs.org/guestfs.3.html#guestfs_inotify_files].
 */
VALUE
guestfs_int_ruby_inotify_files (VALUE gv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "inotify_files");


  char **r;

  r = guestfs_inotify_files (g);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  size_t i, len = 0;
  for (i = 0; r[i] != NULL; ++i) len++;
  volatile VALUE rv = rb_ary_new2 (len);
  for (i = 0; r[i] != NULL; ++i) {
    rb_ary_push (rv, rb_str_new2 (r[i]));
    free (r[i]);
  }
  free (r);
  return rv;
}

/*
 * call-seq:
 *   g.inotify_rm_watch(wd) -> nil
 *
 * remove an inotify watch
 *
 * Remove a previously defined inotify watch. See
 * "g.inotify_add_watch".
 *
 *
 * [Since] Added in version 1.0.66.
 *
 * [Feature] This function depends on the feature +inotify+.  See also {#feature_available}[rdoc-ref:feature_available].
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_inotify_rm_watch}[http://libguestfs.org/guestfs.3.html#guestfs_inotify_rm_watch].
 */
VALUE
guestfs_int_ruby_inotify_rm_watch (VALUE gv, VALUE wdv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "inotify_rm_watch");

  int wd = NUM2INT (wdv);

  int r;

  r = guestfs_inotify_rm_watch (g, wd);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.inspect_get_icon(root, {optargs...}) -> string
 *
 * get the icon corresponding to this operating system
 *
 * This function returns an icon corresponding to the
 * inspected operating system. The icon is returned as a
 * buffer containing a PNG image (re-encoded to PNG if
 * necessary).
 * 
 * If it was not possible to get an icon this function
 * returns a zero-length (non-NULL) buffer. *Callers must
 * check for this case*.
 * 
 * Libguestfs will start by looking for a file called
 * /etc/favicon.png or C:\etc\favicon.png and if it has the
 * correct format, the contents of this file will be
 * returned. You can disable favicons by passing the
 * optional "favicon" boolean as false (default is true).
 * 
 * If finding the favicon fails, then we look in other
 * places in the guest for a suitable icon.
 * 
 * If the optional "highquality" boolean is true then only
 * high quality icons are returned, which means only icons
 * of high resolution with an alpha channel. The default
 * (false) is to return any icon we can, even if it is of
 * substandard quality.
 * 
 * Notes:
 * 
 * *   Unlike most other inspection API calls, the guest’s
 * disks must be mounted up before you call this, since
 * it needs to read information from the guest
 * filesystem during the call.
 * 
 * *   Security: The icon data comes from the untrusted
 * guest, and should be treated with caution. PNG files
 * have been known to contain exploits. Ensure that
 * libpng (or other relevant libraries) are fully up to
 * date before trying to process or display the icon.
 * 
 * *   The PNG image returned can be any size. It might not
 * be square. Libguestfs tries to return the largest,
 * highest quality icon available. The application must
 * scale the icon to the required size.
 * 
 * *   Extracting icons from Windows guests requires the
 * external "wrestool" program from the "icoutils"
 * package, and several programs ("bmptopnm",
 * "pnmtopng", "pamcut") from the "netpbm" package.
 * These must be installed separately.
 * 
 * *   Operating system icons are usually trademarks. Seek
 * legal advice before using trademarks in
 * applications.
 * 
 * Optional arguments are supplied in the final hash
 * parameter, which is a hash of the argument name to its
 * value. Pass an empty {} for no optional arguments.
 *
 *
 * [Since] Added in version 1.11.12.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_inspect_get_icon}[http://libguestfs.org/guestfs.3.html#guestfs_inspect_get_icon].
 */
VALUE
guestfs_int_ruby_inspect_get_icon (int argc, VALUE *argv, VALUE gv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "inspect_get_icon");

  if (argc < 1 || argc > 2)
    rb_raise (rb_eArgError, "expecting 1 or 2 arguments");

  volatile VALUE rootv = argv[0];
  volatile VALUE optargsv = argc > 1 ? argv[1] : rb_hash_new ();

  const char *root = StringValueCStr (rootv);

  Check_Type (optargsv, T_HASH);
  struct guestfs_inspect_get_icon_argv optargs_s = { .bitmask = 0 };
  struct guestfs_inspect_get_icon_argv *optargs = &optargs_s;
  volatile VALUE v;
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("favicon")));
  if (v != Qnil) {
    optargs_s.favicon = RTEST (v);
    optargs_s.bitmask |= GUESTFS_INSPECT_GET_ICON_FAVICON_BITMASK;
  }
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("highquality")));
  if (v != Qnil) {
    optargs_s.highquality = RTEST (v);
    optargs_s.bitmask |= GUESTFS_INSPECT_GET_ICON_HIGHQUALITY_BITMASK;
  }

  char *r;
  size_t size;

  r = guestfs_inspect_get_icon_argv (g, root, &size, optargs);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  volatile VALUE rv = rb_str_new (r, size);
  free (r);
  return rv;
}

/*
 * call-seq:
 *   g.inspect_get_windows_system_hive(root) -> string
 *
 * get the path of the Windows system hive
 *
 * This returns the path to the hive (binary Windows
 * Registry file) corresponding to HKLM\SYSTEM.
 * 
 * This call assumes that the guest is Windows and that the
 * guest has a system hive file with the right name. If
 * this is not the case then an error is returned. This
 * call does not check that the hive is a valid Windows
 * Registry hive.
 * 
 * You can use "g.hivex_open" to read or write to the hive.
 * 
 * Please read "INSPECTION" in guestfs(3) for more details.
 *
 *
 * [Since] Added in version 1.35.26.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_inspect_get_windows_system_hive}[http://libguestfs.org/guestfs.3.html#guestfs_inspect_get_windows_system_hive].
 */
VALUE
guestfs_int_ruby_inspect_get_windows_system_hive (VALUE gv, VALUE rootv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "inspect_get_windows_system_hive");

  const char *root = StringValueCStr (rootv);

  char *r;

  r = guestfs_inspect_get_windows_system_hive (g, root);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  volatile VALUE rv = rb_str_new2 (r);
  free (r);
  return rv;
}

/*
 * call-seq:
 *   g.inspect_is_netinst(root) -> [True|False]
 *
 * get netinst (network installer) flag for install disk
 *
 * This is deprecated and always returns "false".
 * 
 * Please read "INSPECTION" in guestfs(3) for more details.
 *
 *
 * [Since] Added in version 1.9.4.
 *
 * [Deprecated] There is no documented replacement
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_inspect_is_netinst}[http://libguestfs.org/guestfs.3.html#guestfs_inspect_is_netinst].
 */
VALUE
guestfs_int_ruby_inspect_is_netinst (VALUE gv, VALUE rootv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "inspect_is_netinst");

  const char *root = StringValueCStr (rootv);

  int r;

  r = guestfs_inspect_is_netinst (g, root);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return INT2NUM (r);
}

/*
 * call-seq:
 *   g.inspect_list_applications2(root) -> list
 *
 * get list of applications installed in the operating system
 *
 * Return the list of applications installed in the
 * operating system.
 * 
 * *Note:* This call works differently from other parts of
 * the inspection API. You have to call "g.inspect_os",
 * then "g.inspect_get_mountpoints", then mount up the
 * disks, before calling this. Listing applications is a
 * significantly more difficult operation which requires
 * access to the full filesystem. Also note that unlike the
 * other "g.inspect_get_*" calls which are just returning
 * data cached in the libguestfs handle, this call actually
 * reads parts of the mounted filesystems during the call.
 * 
 * This returns an empty list if the inspection code was
 * not able to determine the list of applications.
 * 
 * The application structure contains the following fields:
 * 
 * "app2_name"
 * The name of the application. For Red Hat-derived and
 * Debian-derived Linux guests, this is the package
 * name.
 * 
 * "app2_display_name"
 * The display name of the application, sometimes
 * localized to the install language of the guest
 * operating system.
 * 
 * If unavailable this is returned as an empty string
 * "". Callers needing to display something can use
 * "app2_name" instead.
 * 
 * "app2_epoch"
 * For package managers which use epochs, this contains
 * the epoch of the package (an integer). If
 * unavailable, this is returned as 0.
 * 
 * "app2_version"
 * The version string of the application or package. If
 * unavailable this is returned as an empty string "".
 * 
 * "app2_release"
 * The release string of the application or package,
 * for package managers that use this. If unavailable
 * this is returned as an empty string "".
 * 
 * "app2_arch"
 * The architecture string of the application or
 * package, for package managers that use this. If
 * unavailable this is returned as an empty string "".
 * 
 * "app2_install_path"
 * The installation path of the application (on
 * operating systems such as Windows which use
 * installation paths). This path is in the format used
 * by the guest operating system, it is not a
 * libguestfs path.
 * 
 * If unavailable this is returned as an empty string
 * "".
 * 
 * "app2_trans_path"
 * The install path translated into a libguestfs path.
 * If unavailable this is returned as an empty string
 * "".
 * 
 * "app2_publisher"
 * The name of the publisher of the application, for
 * package managers that use this. If unavailable this
 * is returned as an empty string "".
 * 
 * "app2_url"
 * The URL (eg. upstream URL) of the application. If
 * unavailable this is returned as an empty string "".
 * 
 * "app2_source_package"
 * For packaging systems which support this, the name
 * of the source package. If unavailable this is
 * returned as an empty string "".
 * 
 * "app2_summary"
 * A short (usually one line) description of the
 * application or package. If unavailable this is
 * returned as an empty string "".
 * 
 * "app2_description"
 * A longer description of the application or package.
 * If unavailable this is returned as an empty string
 * "".
 * 
 * Please read "INSPECTION" in guestfs(3) for more details.
 *
 *
 * [Since] Added in version 1.19.56.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_inspect_list_applications2}[http://libguestfs.org/guestfs.3.html#guestfs_inspect_list_applications2].
 */
VALUE
guestfs_int_ruby_inspect_list_applications2 (VALUE gv, VALUE rootv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "inspect_list_applications2");

  const char *root = StringValueCStr (rootv);

  struct guestfs_application2_list *r;

  r = guestfs_inspect_list_applications2 (g, root);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  volatile VALUE rv = rb_ary_new2 (r->len);
  size_t i;
  for (i = 0; i < r->len; ++i) {
    volatile VALUE hv = rb_hash_new ();
    rb_hash_aset (hv, rb_str_new2 ("app2_name"), rb_str_new2 (r->val[i].app2_name));
    rb_hash_aset (hv, rb_str_new2 ("app2_display_name"), rb_str_new2 (r->val[i].app2_display_name));
    rb_hash_aset (hv, rb_str_new2 ("app2_epoch"), INT2NUM (r->val[i].app2_epoch));
    rb_hash_aset (hv, rb_str_new2 ("app2_version"), rb_str_new2 (r->val[i].app2_version));
    rb_hash_aset (hv, rb_str_new2 ("app2_release"), rb_str_new2 (r->val[i].app2_release));
    rb_hash_aset (hv, rb_str_new2 ("app2_arch"), rb_str_new2 (r->val[i].app2_arch));
    rb_hash_aset (hv, rb_str_new2 ("app2_install_path"), rb_str_new2 (r->val[i].app2_install_path));
    rb_hash_aset (hv, rb_str_new2 ("app2_trans_path"), rb_str_new2 (r->val[i].app2_trans_path));
    rb_hash_aset (hv, rb_str_new2 ("app2_publisher"), rb_str_new2 (r->val[i].app2_publisher));
    rb_hash_aset (hv, rb_str_new2 ("app2_url"), rb_str_new2 (r->val[i].app2_url));
    rb_hash_aset (hv, rb_str_new2 ("app2_source_package"), rb_str_new2 (r->val[i].app2_source_package));
    rb_hash_aset (hv, rb_str_new2 ("app2_summary"), rb_str_new2 (r->val[i].app2_summary));
    rb_hash_aset (hv, rb_str_new2 ("app2_description"), rb_str_new2 (r->val[i].app2_description));
    rb_hash_aset (hv, rb_str_new2 ("app2_spare1"), rb_str_new2 (r->val[i].app2_spare1));
    rb_hash_aset (hv, rb_str_new2 ("app2_spare2"), rb_str_new2 (r->val[i].app2_spare2));
    rb_hash_aset (hv, rb_str_new2 ("app2_spare3"), rb_str_new2 (r->val[i].app2_spare3));
    rb_hash_aset (hv, rb_str_new2 ("app2_spare4"), rb_str_new2 (r->val[i].app2_spare4));
    rb_ary_push (rv, hv);
  }
  guestfs_free_application2_list (r);
  return rv;
}

/*
 * call-seq:
 *   g.internal_test_rbufferouterr
 *
 * :nodoc:
 */
VALUE
guestfs_int_ruby_internal_test_rbufferouterr (VALUE gv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "internal_test_rbufferouterr");


  char *r;
  size_t size;

  r = guestfs_internal_test_rbufferouterr (g, &size);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  volatile VALUE rv = rb_str_new (r, size);
  free (r);
  return rv;
}

/*
 * call-seq:
 *   g.internal_test_rconstoptstring
 *
 * :nodoc:
 */
VALUE
guestfs_int_ruby_internal_test_rconstoptstring (VALUE gv, VALUE valv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "internal_test_rconstoptstring");

  const char *val = StringValueCStr (valv);

  const char *r;

  r = guestfs_internal_test_rconstoptstring (g, val);

  if (r)
    return rb_str_new2 (r);
  else
    return Qnil;
}

/*
 * call-seq:
 *   g.internal_test_rint64
 *
 * :nodoc:
 */
VALUE
guestfs_int_ruby_internal_test_rint64 (VALUE gv, VALUE valv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "internal_test_rint64");

  const char *val = StringValueCStr (valv);

  int64_t r;

  r = guestfs_internal_test_rint64 (g, val);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return ULL2NUM (r);
}

/*
 * call-seq:
 *   g.internal_test_rstringerr
 *
 * :nodoc:
 */
VALUE
guestfs_int_ruby_internal_test_rstringerr (VALUE gv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "internal_test_rstringerr");


  char *r;

  r = guestfs_internal_test_rstringerr (g);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  volatile VALUE rv = rb_str_new2 (r);
  free (r);
  return rv;
}

/*
 * call-seq:
 *   g.internal_test_rstructlist
 *
 * :nodoc:
 */
VALUE
guestfs_int_ruby_internal_test_rstructlist (VALUE gv, VALUE valv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "internal_test_rstructlist");

  const char *val = StringValueCStr (valv);

  struct guestfs_lvm_pv_list *r;

  r = guestfs_internal_test_rstructlist (g, val);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  volatile VALUE rv = rb_ary_new2 (r->len);
  size_t i;
  for (i = 0; i < r->len; ++i) {
    volatile VALUE hv = rb_hash_new ();
    rb_hash_aset (hv, rb_str_new2 ("pv_name"), rb_str_new2 (r->val[i].pv_name));
    rb_hash_aset (hv, rb_str_new2 ("pv_uuid"), rb_str_new (r->val[i].pv_uuid, 32));
    rb_hash_aset (hv, rb_str_new2 ("pv_fmt"), rb_str_new2 (r->val[i].pv_fmt));
    rb_hash_aset (hv, rb_str_new2 ("pv_size"), ULL2NUM (r->val[i].pv_size));
    rb_hash_aset (hv, rb_str_new2 ("dev_size"), ULL2NUM (r->val[i].dev_size));
    rb_hash_aset (hv, rb_str_new2 ("pv_free"), ULL2NUM (r->val[i].pv_free));
    rb_hash_aset (hv, rb_str_new2 ("pv_used"), ULL2NUM (r->val[i].pv_used));
    rb_hash_aset (hv, rb_str_new2 ("pv_attr"), rb_str_new2 (r->val[i].pv_attr));
    rb_hash_aset (hv, rb_str_new2 ("pv_pe_count"), LL2NUM (r->val[i].pv_pe_count));
    rb_hash_aset (hv, rb_str_new2 ("pv_pe_alloc_count"), LL2NUM (r->val[i].pv_pe_alloc_count));
    rb_hash_aset (hv, rb_str_new2 ("pv_tags"), rb_str_new2 (r->val[i].pv_tags));
    rb_hash_aset (hv, rb_str_new2 ("pe_start"), ULL2NUM (r->val[i].pe_start));
    rb_hash_aset (hv, rb_str_new2 ("pv_mda_count"), LL2NUM (r->val[i].pv_mda_count));
    rb_hash_aset (hv, rb_str_new2 ("pv_mda_free"), ULL2NUM (r->val[i].pv_mda_free));
    rb_ary_push (rv, hv);
  }
  guestfs_free_lvm_pv_list (r);
  return rv;
}

/*
 * call-seq:
 *   g.internal_test_rstructlisterr
 *
 * :nodoc:
 */
VALUE
guestfs_int_ruby_internal_test_rstructlisterr (VALUE gv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "internal_test_rstructlisterr");


  struct guestfs_lvm_pv_list *r;

  r = guestfs_internal_test_rstructlisterr (g);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  volatile VALUE rv = rb_ary_new2 (r->len);
  size_t i;
  for (i = 0; i < r->len; ++i) {
    volatile VALUE hv = rb_hash_new ();
    rb_hash_aset (hv, rb_str_new2 ("pv_name"), rb_str_new2 (r->val[i].pv_name));
    rb_hash_aset (hv, rb_str_new2 ("pv_uuid"), rb_str_new (r->val[i].pv_uuid, 32));
    rb_hash_aset (hv, rb_str_new2 ("pv_fmt"), rb_str_new2 (r->val[i].pv_fmt));
    rb_hash_aset (hv, rb_str_new2 ("pv_size"), ULL2NUM (r->val[i].pv_size));
    rb_hash_aset (hv, rb_str_new2 ("dev_size"), ULL2NUM (r->val[i].dev_size));
    rb_hash_aset (hv, rb_str_new2 ("pv_free"), ULL2NUM (r->val[i].pv_free));
    rb_hash_aset (hv, rb_str_new2 ("pv_used"), ULL2NUM (r->val[i].pv_used));
    rb_hash_aset (hv, rb_str_new2 ("pv_attr"), rb_str_new2 (r->val[i].pv_attr));
    rb_hash_aset (hv, rb_str_new2 ("pv_pe_count"), LL2NUM (r->val[i].pv_pe_count));
    rb_hash_aset (hv, rb_str_new2 ("pv_pe_alloc_count"), LL2NUM (r->val[i].pv_pe_alloc_count));
    rb_hash_aset (hv, rb_str_new2 ("pv_tags"), rb_str_new2 (r->val[i].pv_tags));
    rb_hash_aset (hv, rb_str_new2 ("pe_start"), ULL2NUM (r->val[i].pe_start));
    rb_hash_aset (hv, rb_str_new2 ("pv_mda_count"), LL2NUM (r->val[i].pv_mda_count));
    rb_hash_aset (hv, rb_str_new2 ("pv_mda_free"), ULL2NUM (r->val[i].pv_mda_free));
    rb_ary_push (rv, hv);
  }
  guestfs_free_lvm_pv_list (r);
  return rv;
}

/*
 * call-seq:
 *   g.is_symlink(path) -> [True|False]
 *
 * test if symbolic link
 *
 * This returns "true" if and only if there is a symbolic
 * link with the given "path" name.
 * 
 * See also "g.stat".
 *
 *
 * [Since] Added in version 1.5.10.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_is_symlink}[http://libguestfs.org/guestfs.3.html#guestfs_is_symlink].
 */
VALUE
guestfs_int_ruby_is_symlink (VALUE gv, VALUE pathv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "is_symlink");

  const char *path = StringValueCStr (pathv);

  int r;

  r = guestfs_is_symlink (g, path);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return INT2NUM (r);
}

/*
 * call-seq:
 *   g.is_zero(path) -> [True|False]
 *
 * test if a file contains all zero bytes
 *
 * This returns true iff the file exists and the file is
 * empty or it contains all zero bytes.
 *
 *
 * [Since] Added in version 1.11.8.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_is_zero}[http://libguestfs.org/guestfs.3.html#guestfs_is_zero].
 */
VALUE
guestfs_int_ruby_is_zero (VALUE gv, VALUE pathv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "is_zero");

  const char *path = StringValueCStr (pathv);

  int r;

  r = guestfs_is_zero (g, path);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return INT2NUM (r);
}

/*
 * call-seq:
 *   g.lchown(owner, group, path) -> nil
 *
 * change file owner and group
 *
 * Change the file owner to "owner" and group to "group".
 * This is like "g.chown" but if "path" is a symlink then
 * the link itself is changed, not the target.
 * 
 * Only numeric uid and gid are supported. If you want to
 * use names, you will need to locate and parse the
 * password file yourself (Augeas support makes this
 * relatively easy).
 *
 *
 * [Since] Added in version 1.0.77.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_lchown}[http://libguestfs.org/guestfs.3.html#guestfs_lchown].
 */
VALUE
guestfs_int_ruby_lchown (VALUE gv, VALUE ownerv, VALUE groupv, VALUE pathv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "lchown");

  int owner = NUM2INT (ownerv);
  int group = NUM2INT (groupv);
  const char *path = StringValueCStr (pathv);

  int r;

  r = guestfs_lchown (g, owner, group, path);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.ldmtool_create_all() -> nil
 *
 * scan and create Windows dynamic disk volumes
 *
 * This function scans all block devices looking for
 * Windows dynamic disk volumes and partitions, and creates
 * devices for any that were found.
 * 
 * Call "g.list_ldm_volumes" and "g.list_ldm_partitions" to
 * return all devices.
 * 
 * Note that you don't normally need to call this
 * explicitly, since it is done automatically at "g.launch"
 * time. However you might want to call this function if
 * you have hotplugged disks or have just created a Windows
 * dynamic disk.
 *
 *
 * [Since] Added in version 1.20.0.
 *
 * [Feature] This function depends on the feature +ldm+.  See also {#feature_available}[rdoc-ref:feature_available].
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_ldmtool_create_all}[http://libguestfs.org/guestfs.3.html#guestfs_ldmtool_create_all].
 */
VALUE
guestfs_int_ruby_ldmtool_create_all (VALUE gv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "ldmtool_create_all");


  int r;

  r = guestfs_ldmtool_create_all (g);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.ldmtool_diskgroup_disks(diskgroup) -> list
 *
 * return the disks in a Windows dynamic disk group
 *
 * Return the disks in a Windows dynamic disk group. The
 * "diskgroup" parameter should be the GUID of a disk
 * group, one element from the list returned by
 * "g.ldmtool_scan".
 *
 *
 * [Since] Added in version 1.20.0.
 *
 * [Feature] This function depends on the feature +ldm+.  See also {#feature_available}[rdoc-ref:feature_available].
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_ldmtool_diskgroup_disks}[http://libguestfs.org/guestfs.3.html#guestfs_ldmtool_diskgroup_disks].
 */
VALUE
guestfs_int_ruby_ldmtool_diskgroup_disks (VALUE gv, VALUE diskgroupv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "ldmtool_diskgroup_disks");

  const char *diskgroup = StringValueCStr (diskgroupv);

  char **r;

  r = guestfs_ldmtool_diskgroup_disks (g, diskgroup);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  size_t i, len = 0;
  for (i = 0; r[i] != NULL; ++i) len++;
  volatile VALUE rv = rb_ary_new2 (len);
  for (i = 0; r[i] != NULL; ++i) {
    rb_ary_push (rv, rb_str_new2 (r[i]));
    free (r[i]);
  }
  free (r);
  return rv;
}

/*
 * call-seq:
 *   g.list_partitions() -> list
 *
 * list the partitions
 *
 * List all the partitions detected on all block devices.
 * 
 * The full partition device names are returned, eg.
 * /dev/sda1
 * 
 * This does not return logical volumes. For that you will
 * need to call "g.lvs".
 * 
 * See also "g.list_filesystems".
 *
 *
 * [Since] Added in version 0.4.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_list_partitions}[http://libguestfs.org/guestfs.3.html#guestfs_list_partitions].
 */
VALUE
guestfs_int_ruby_list_partitions (VALUE gv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "list_partitions");


  char **r;

  r = guestfs_list_partitions (g);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  size_t i, len = 0;
  for (i = 0; r[i] != NULL; ++i) len++;
  volatile VALUE rv = rb_ary_new2 (len);
  for (i = 0; r[i] != NULL; ++i) {
    rb_ary_push (rv, rb_str_new2 (r[i]));
    free (r[i]);
  }
  free (r);
  return rv;
}

/*
 * call-seq:
 *   g.llz(directory) -> string
 *
 * list the files in a directory (long format with SELinux contexts)
 *
 * List the files in directory in the format of 'ls -laZ'.
 * 
 * This command is mostly useful for interactive sessions.
 * It is *not* intended that you try to parse the output
 * string.
 *
 *
 * [Since] Added in version 1.17.6.
 *
 * [Deprecated] In new code, use rdoc-ref:lgetxattrs instead.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_llz}[http://libguestfs.org/guestfs.3.html#guestfs_llz].
 */
VALUE
guestfs_int_ruby_llz (VALUE gv, VALUE directoryv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "llz");

  const char *directory = StringValueCStr (directoryv);

  char *r;

  r = guestfs_llz (g, directory);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  volatile VALUE rv = rb_str_new2 (r);
  free (r);
  return rv;
}

/*
 * call-seq:
 *   g.lstat(path) -> hash
 *
 * get file information for a symbolic link
 *
 * Returns file information for the given "path".
 * 
 * This is the same as "g.stat" except that if "path" is a
 * symbolic link, then the link is stat-ed, not the file it
 * refers to.
 * 
 * This is the same as the lstat(2) system call.
 *
 *
 * [Since] Added in version 1.9.2.
 *
 * [Deprecated] In new code, use rdoc-ref:lstatns instead.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_lstat}[http://libguestfs.org/guestfs.3.html#guestfs_lstat].
 */
VALUE
guestfs_int_ruby_lstat (VALUE gv, VALUE pathv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "lstat");

  const char *path = StringValueCStr (pathv);

  struct guestfs_stat *r;

  r = guestfs_lstat (g, path);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  volatile VALUE rv = rb_hash_new ();
  rb_hash_aset (rv, rb_str_new2 ("dev"), LL2NUM (r->dev));
  rb_hash_aset (rv, rb_str_new2 ("ino"), LL2NUM (r->ino));
  rb_hash_aset (rv, rb_str_new2 ("mode"), LL2NUM (r->mode));
  rb_hash_aset (rv, rb_str_new2 ("nlink"), LL2NUM (r->nlink));
  rb_hash_aset (rv, rb_str_new2 ("uid"), LL2NUM (r->uid));
  rb_hash_aset (rv, rb_str_new2 ("gid"), LL2NUM (r->gid));
  rb_hash_aset (rv, rb_str_new2 ("rdev"), LL2NUM (r->rdev));
  rb_hash_aset (rv, rb_str_new2 ("size"), LL2NUM (r->size));
  rb_hash_aset (rv, rb_str_new2 ("blksize"), LL2NUM (r->blksize));
  rb_hash_aset (rv, rb_str_new2 ("blocks"), LL2NUM (r->blocks));
  rb_hash_aset (rv, rb_str_new2 ("atime"), LL2NUM (r->atime));
  rb_hash_aset (rv, rb_str_new2 ("mtime"), LL2NUM (r->mtime));
  rb_hash_aset (rv, rb_str_new2 ("ctime"), LL2NUM (r->ctime));
  guestfs_free_stat (r);
  return rv;
}

/*
 * call-seq:
 *   g.lstatlist(path, names) -> list
 *
 * lstat on multiple files
 *
 * This call allows you to perform the "g.lstat" operation
 * on multiple files, where all files are in the directory
 * "path". "names" is the list of files from this
 * directory.
 * 
 * On return you get a list of stat structs, with a
 * one-to-one correspondence to the "names" list. If any
 * name did not exist or could not be lstat'd, then the
 * "st_ino" field of that structure is set to -1.
 * 
 * This call is intended for programs that want to
 * efficiently list a directory contents without making
 * many round-trips. See also "g.lxattrlist" for a
 * similarly efficient call for getting extended
 * attributes.
 *
 *
 * [Since] Added in version 1.0.77.
 *
 * [Deprecated] In new code, use rdoc-ref:lstatnslist instead.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_lstatlist}[http://libguestfs.org/guestfs.3.html#guestfs_lstatlist].
 */
VALUE
guestfs_int_ruby_lstatlist (VALUE gv, VALUE pathv, VALUE namesv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "lstatlist");

  const char *path = StringValueCStr (pathv);
  char **names;
  Check_Type (namesv, T_ARRAY);
  {
    size_t i, len;
    len = RARRAY_LEN (namesv);
    names = ALLOC_N (char *, len+1);
    for (i = 0; i < len; ++i) {
      volatile VALUE v = rb_ary_entry (namesv, i);
      names[i] = StringValueCStr (v);
    }
    names[len] = NULL;
  }

  struct guestfs_stat_list *r;

  r = guestfs_lstatlist (g, path, names);
  free (names);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  volatile VALUE rv = rb_ary_new2 (r->len);
  size_t i;
  for (i = 0; i < r->len; ++i) {
    volatile VALUE hv = rb_hash_new ();
    rb_hash_aset (hv, rb_str_new2 ("dev"), LL2NUM (r->val[i].dev));
    rb_hash_aset (hv, rb_str_new2 ("ino"), LL2NUM (r->val[i].ino));
    rb_hash_aset (hv, rb_str_new2 ("mode"), LL2NUM (r->val[i].mode));
    rb_hash_aset (hv, rb_str_new2 ("nlink"), LL2NUM (r->val[i].nlink));
    rb_hash_aset (hv, rb_str_new2 ("uid"), LL2NUM (r->val[i].uid));
    rb_hash_aset (hv, rb_str_new2 ("gid"), LL2NUM (r->val[i].gid));
    rb_hash_aset (hv, rb_str_new2 ("rdev"), LL2NUM (r->val[i].rdev));
    rb_hash_aset (hv, rb_str_new2 ("size"), LL2NUM (r->val[i].size));
    rb_hash_aset (hv, rb_str_new2 ("blksize"), LL2NUM (r->val[i].blksize));
    rb_hash_aset (hv, rb_str_new2 ("blocks"), LL2NUM (r->val[i].blocks));
    rb_hash_aset (hv, rb_str_new2 ("atime"), LL2NUM (r->val[i].atime));
    rb_hash_aset (hv, rb_str_new2 ("mtime"), LL2NUM (r->val[i].mtime));
    rb_hash_aset (hv, rb_str_new2 ("ctime"), LL2NUM (r->val[i].ctime));
    rb_ary_push (rv, hv);
  }
  guestfs_free_stat_list (r);
  return rv;
}

/*
 * call-seq:
 *   g.luks_open(device, key, mapname) -> nil
 *
 * open a LUKS-encrypted block device
 *
 * This command opens a block device which has been
 * encrypted according to the Linux Unified Key Setup
 * (LUKS) standard.
 * 
 * "device" is the encrypted block device or partition.
 * 
 * The caller must supply one of the keys associated with
 * the LUKS block device, in the "key" parameter.
 * 
 * This creates a new block device called
 * /dev/mapper/mapname. Reads and writes to this block
 * device are decrypted from and encrypted to the
 * underlying "device" respectively.
 * 
 * If this block device contains LVM volume groups, then
 * calling "g.lvm_scan" with the "activate" parameter
 * "true" will make them visible.
 * 
 * Use "g.list_dm_devices" to list all device mapper
 * devices.
 *
 *
 * [Since] Added in version 1.5.1.
 *
 * [Feature] This function depends on the feature +luks+.  See also {#feature_available}[rdoc-ref:feature_available].
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_luks_open}[http://libguestfs.org/guestfs.3.html#guestfs_luks_open].
 */
VALUE
guestfs_int_ruby_luks_open (VALUE gv, VALUE devicev, VALUE keyv, VALUE mapnamev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "luks_open");

  const char *device = StringValueCStr (devicev);
  const char *key = StringValueCStr (keyv);
  const char *mapname = StringValueCStr (mapnamev);

  int r;

  r = guestfs_luks_open (g, device, key, mapname);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.luks_open_ro(device, key, mapname) -> nil
 *
 * open a LUKS-encrypted block device read-only
 *
 * This is the same as "g.luks_open" except that a
 * read-only mapping is created.
 *
 *
 * [Since] Added in version 1.5.1.
 *
 * [Feature] This function depends on the feature +luks+.  See also {#feature_available}[rdoc-ref:feature_available].
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_luks_open_ro}[http://libguestfs.org/guestfs.3.html#guestfs_luks_open_ro].
 */
VALUE
guestfs_int_ruby_luks_open_ro (VALUE gv, VALUE devicev, VALUE keyv, VALUE mapnamev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "luks_open_ro");

  const char *device = StringValueCStr (devicev);
  const char *key = StringValueCStr (keyv);
  const char *mapname = StringValueCStr (mapnamev);

  int r;

  r = guestfs_luks_open_ro (g, device, key, mapname);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.lvm_remove_all() -> nil
 *
 * remove all LVM LVs, VGs and PVs
 *
 * This command removes all LVM logical volumes, volume
 * groups and physical volumes.
 *
 *
 * [Since] Added in version 0.8.
 *
 * [Feature] This function depends on the feature +lvm2+.  See also {#feature_available}[rdoc-ref:feature_available].
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_lvm_remove_all}[http://libguestfs.org/guestfs.3.html#guestfs_lvm_remove_all].
 */
VALUE
guestfs_int_ruby_lvm_remove_all (VALUE gv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "lvm_remove_all");


  int r;

  r = guestfs_lvm_remove_all (g);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.lvresize_free(lv, percent) -> nil
 *
 * expand an LV to fill free space
 *
 * This expands an existing logical volume "lv" so that it
 * fills "pc"% of the remaining free space in the volume
 * group. Commonly you would call this with pc = 100 which
 * expands the logical volume as much as possible, using
 * all remaining free space in the volume group.
 *
 *
 * [Since] Added in version 1.3.3.
 *
 * [Feature] This function depends on the feature +lvm2+.  See also {#feature_available}[rdoc-ref:feature_available].
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_lvresize_free}[http://libguestfs.org/guestfs.3.html#guestfs_lvresize_free].
 */
VALUE
guestfs_int_ruby_lvresize_free (VALUE gv, VALUE lvv, VALUE percentv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "lvresize_free");

  const char *lv = StringValueCStr (lvv);
  int percent = NUM2INT (percentv);

  int r;

  r = guestfs_lvresize_free (g, lv, percent);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.md_create(name, devices, {optargs...}) -> nil
 *
 * create a Linux md (RAID) device
 *
 * Create a Linux md (RAID) device named "name" on the
 * devices in the list "devices".
 * 
 * The optional parameters are:
 * 
 * "missingbitmap"
 * A bitmap of missing devices. If a bit is set it
 * means that a missing device is added to the array.
 * The least significant bit corresponds to the first
 * device in the array.
 * 
 * As examples:
 * 
 * If "devices = ["/dev/sda"]" and "missingbitmap =
 * 0x1" then the resulting array would be "[<missing>,
 * "/dev/sda"]".
 * 
 * If "devices = ["/dev/sda"]" and "missingbitmap =
 * 0x2" then the resulting array would be "["/dev/sda",
 * <missing>]".
 * 
 * This defaults to 0 (no missing devices).
 * 
 * The length of "devices" + the number of bits set in
 * "missingbitmap" must equal "nrdevices" + "spare".
 * 
 * "nrdevices"
 * The number of active RAID devices.
 * 
 * If not set, this defaults to the length of "devices"
 * plus the number of bits set in "missingbitmap".
 * 
 * "spare"
 * The number of spare devices.
 * 
 * If not set, this defaults to 0.
 * 
 * "chunk"
 * The chunk size in bytes.
 * 
 * "level"
 * The RAID level, which can be one of: *linear*,
 * *raid0*, *0*, *stripe*, *raid1*, *1*, *mirror*,
 * *raid4*, *4*, *raid5*, *5*, *raid6*, *6*, *raid10*,
 * *10*. Some of these are synonymous, and more levels
 * may be added in future.
 * 
 * If not set, this defaults to "raid1".
 * 
 * Optional arguments are supplied in the final hash
 * parameter, which is a hash of the argument name to its
 * value. Pass an empty {} for no optional arguments.
 *
 *
 * [Since] Added in version 1.15.6.
 *
 * [Feature] This function depends on the feature +mdadm+.  See also {#feature_available}[rdoc-ref:feature_available].
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_md_create}[http://libguestfs.org/guestfs.3.html#guestfs_md_create].
 */
VALUE
guestfs_int_ruby_md_create (int argc, VALUE *argv, VALUE gv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "md_create");

  if (argc < 2 || argc > 3)
    rb_raise (rb_eArgError, "expecting 2 or 3 arguments");

  volatile VALUE namev = argv[0];
  volatile VALUE devicesv = argv[1];
  volatile VALUE optargsv = argc > 2 ? argv[2] : rb_hash_new ();

  const char *name = StringValueCStr (namev);
  char **devices;
  Check_Type (devicesv, T_ARRAY);
  {
    size_t i, len;
    len = RARRAY_LEN (devicesv);
    devices = ALLOC_N (char *, len+1);
    for (i = 0; i < len; ++i) {
      volatile VALUE v = rb_ary_entry (devicesv, i);
      devices[i] = StringValueCStr (v);
    }
    devices[len] = NULL;
  }

  Check_Type (optargsv, T_HASH);
  struct guestfs_md_create_argv optargs_s = { .bitmask = 0 };
  struct guestfs_md_create_argv *optargs = &optargs_s;
  volatile VALUE v;
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("missingbitmap")));
  if (v != Qnil) {
    optargs_s.missingbitmap = NUM2LL (v);
    optargs_s.bitmask |= GUESTFS_MD_CREATE_MISSINGBITMAP_BITMASK;
  }
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("nrdevices")));
  if (v != Qnil) {
    optargs_s.nrdevices = NUM2INT (v);
    optargs_s.bitmask |= GUESTFS_MD_CREATE_NRDEVICES_BITMASK;
  }
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("spare")));
  if (v != Qnil) {
    optargs_s.spare = NUM2INT (v);
    optargs_s.bitmask |= GUESTFS_MD_CREATE_SPARE_BITMASK;
  }
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("chunk")));
  if (v != Qnil) {
    optargs_s.chunk = NUM2LL (v);
    optargs_s.bitmask |= GUESTFS_MD_CREATE_CHUNK_BITMASK;
  }
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("level")));
  if (v != Qnil) {
    optargs_s.level = StringValueCStr (v);
    optargs_s.bitmask |= GUESTFS_MD_CREATE_LEVEL_BITMASK;
  }

  int r;

  r = guestfs_md_create_argv (g, name, devices, optargs);
  free (devices);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.mkdtemp(tmpl) -> string
 *
 * create a temporary directory
 *
 * This command creates a temporary directory. The "tmpl"
 * parameter should be a full pathname for the temporary
 * directory name with the final six characters being
 * "XXXXXX".
 * 
 * For example: "/tmp/myprogXXXXXX" or
 * "/Temp/myprogXXXXXX", the second one being suitable for
 * Windows filesystems.
 * 
 * The name of the temporary directory that was created is
 * returned.
 * 
 * The temporary directory is created with mode 0700 and is
 * owned by root.
 * 
 * The caller is responsible for deleting the temporary
 * directory and its contents after use.
 * 
 * See also: mkdtemp(3)
 *
 *
 * [Since] Added in version 1.0.54.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_mkdtemp}[http://libguestfs.org/guestfs.3.html#guestfs_mkdtemp].
 */
VALUE
guestfs_int_ruby_mkdtemp (VALUE gv, VALUE tmplv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "mkdtemp");

  const char *tmpl = StringValueCStr (tmplv);

  char *r;

  r = guestfs_mkdtemp (g, tmpl);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  volatile VALUE rv = rb_str_new2 (r);
  free (r);
  return rv;
}

/*
 * call-seq:
 *   g.mknod(mode, devmajor, devminor, path) -> nil
 *
 * make block, character or FIFO devices
 *
 * This call creates block or character special devices, or
 * named pipes (FIFOs).
 * 
 * The "mode" parameter should be the mode, using the
 * standard constants. "devmajor" and "devminor" are the
 * device major and minor numbers, only used when creating
 * block and character special devices.
 * 
 * Note that, just like mknod(2), the mode must be bitwise
 * OR'd with S_IFBLK, S_IFCHR, S_IFIFO or S_IFSOCK
 * (otherwise this call just creates a regular file). These
 * constants are available in the standard Linux header
 * files, or you can use "g.mknod_b", "g.mknod_c" or
 * "g.mkfifo" which are wrappers around this command which
 * bitwise OR in the appropriate constant for you.
 * 
 * The mode actually set is affected by the umask.
 *
 *
 * [Since] Added in version 1.0.55.
 *
 * [Feature] This function depends on the feature +mknod+.  See also {#feature_available}[rdoc-ref:feature_available].
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_mknod}[http://libguestfs.org/guestfs.3.html#guestfs_mknod].
 */
VALUE
guestfs_int_ruby_mknod (VALUE gv, VALUE modev, VALUE devmajorv, VALUE devminorv, VALUE pathv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "mknod");

  int mode = NUM2INT (modev);
  int devmajor = NUM2INT (devmajorv);
  int devminor = NUM2INT (devminorv);
  const char *path = StringValueCStr (pathv);

  int r;

  r = guestfs_mknod (g, mode, devmajor, devminor, path);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.mount(mountable, mountpoint) -> nil
 *
 * mount a guest disk at a position in the filesystem
 *
 * Mount a guest disk at a position in the filesystem.
 * Block devices are named /dev/sda, /dev/sdb and so on, as
 * they were added to the guest. If those block devices
 * contain partitions, they will have the usual names (eg.
 * /dev/sda1). Also LVM /dev/VG/LV-style names can be used,
 * or ‘mountable’ strings returned by "g.list_filesystems"
 * or "g.inspect_get_mountpoints".
 * 
 * The rules are the same as for mount(2): A filesystem
 * must first be mounted on / before others can be mounted.
 * Other filesystems can only be mounted on directories
 * which already exist.
 * 
 * The mounted filesystem is writable, if we have
 * sufficient permissions on the underlying device.
 * 
 * Before libguestfs 1.13.16, this call implicitly added
 * the options "sync" and "noatime". The "sync" option
 * greatly slowed writes and caused many problems for
 * users. If your program might need to work with older
 * versions of libguestfs, use "g.mount_options" instead
 * (using an empty string for the first parameter if you
 * don't want any options).
 *
 *
 * [Since] Added in version 0.3.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_mount}[http://libguestfs.org/guestfs.3.html#guestfs_mount].
 */
VALUE
guestfs_int_ruby_mount (VALUE gv, VALUE mountablev, VALUE mountpointv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "mount");

  const char *mountable = StringValueCStr (mountablev);
  const char *mountpoint = StringValueCStr (mountpointv);

  int r;

  r = guestfs_mount (g, mountable, mountpoint);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.mount_local_run() -> nil
 *
 * run main loop of mount on the local filesystem
 *
 * Run the main loop which translates kernel calls to
 * libguestfs calls.
 * 
 * This should only be called after "g.mount_local" returns
 * successfully. The call will not return until the
 * filesystem is unmounted.
 * 
 * Note you must *not* make concurrent libguestfs calls on
 * the same handle from another thread.
 * 
 * You may call this from a different thread than the one
 * which called "g.mount_local", subject to the usual rules
 * for threads and libguestfs (see "MULTIPLE HANDLES AND
 * MULTIPLE THREADS" in guestfs(3)).
 * 
 * See "MOUNT LOCAL" in guestfs(3) for full documentation.
 *
 *
 * [Since] Added in version 1.17.22.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_mount_local_run}[http://libguestfs.org/guestfs.3.html#guestfs_mount_local_run].
 */
VALUE
guestfs_int_ruby_mount_local_run (VALUE gv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "mount_local_run");


  int r;

  r = guestfs_mount_local_run (g);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.mount_ro(mountable, mountpoint) -> nil
 *
 * mount a guest disk, read-only
 *
 * This is the same as the "g.mount" command, but it mounts
 * the filesystem with the read-only (*-o ro*) flag.
 *
 *
 * [Since] Added in version 1.0.10.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_mount_ro}[http://libguestfs.org/guestfs.3.html#guestfs_mount_ro].
 */
VALUE
guestfs_int_ruby_mount_ro (VALUE gv, VALUE mountablev, VALUE mountpointv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "mount_ro");

  const char *mountable = StringValueCStr (mountablev);
  const char *mountpoint = StringValueCStr (mountpointv);

  int r;

  r = guestfs_mount_ro (g, mountable, mountpoint);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.mountable_subvolume(mountable) -> string
 *
 * extract the subvolume part of a mountable
 *
 * Returns the subvolume path of a mountable. Btrfs
 * subvolumes mountables are a combination of both the
 * device name and the subvolume path (see also
 * "g.mountable_device" to extract the device of the
 * mountable).
 * 
 * If the mountable does not represent a btrfs subvolume,
 * then this function fails and the "errno" is set to
 * "EINVAL".
 *
 *
 * [Since] Added in version 1.33.15.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_mountable_subvolume}[http://libguestfs.org/guestfs.3.html#guestfs_mountable_subvolume].
 */
VALUE
guestfs_int_ruby_mountable_subvolume (VALUE gv, VALUE mountablev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "mountable_subvolume");

  const char *mountable = StringValueCStr (mountablev);

  char *r;

  r = guestfs_mountable_subvolume (g, mountable);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  volatile VALUE rv = rb_str_new2 (r);
  free (r);
  return rv;
}

/*
 * call-seq:
 *   g.mounts() -> list
 *
 * show mounted filesystems
 *
 * This returns the list of currently mounted filesystems.
 * It returns the list of devices (eg. /dev/sda1,
 * /dev/VG/LV).
 * 
 * Some internal mounts are not shown.
 * 
 * See also: "g.mountpoints"
 *
 *
 * [Since] Added in version 0.8.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_mounts}[http://libguestfs.org/guestfs.3.html#guestfs_mounts].
 */
VALUE
guestfs_int_ruby_mounts (VALUE gv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "mounts");


  char **r;

  r = guestfs_mounts (g);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  size_t i, len = 0;
  for (i = 0; r[i] != NULL; ++i) len++;
  volatile VALUE rv = rb_ary_new2 (len);
  for (i = 0; r[i] != NULL; ++i) {
    rb_ary_push (rv, rb_str_new2 (r[i]));
    free (r[i]);
  }
  free (r);
  return rv;
}

/*
 * call-seq:
 *   g.ntfs_3g_probe(rw, device) -> fixnum
 *
 * probe NTFS volume
 *
 * This command runs the ntfs-3g.probe(8) command which
 * probes an NTFS "device" for mountability. (Not all NTFS
 * volumes can be mounted read-write, and some cannot be
 * mounted at all).
 * 
 * "rw" is a boolean flag. Set it to true if you want to
 * test if the volume can be mounted read-write. Set it to
 * false if you want to test if the volume can be mounted
 * read-only.
 * 
 * The return value is an integer which 0 if the operation
 * would succeed, or some non-zero value documented in the
 * ntfs-3g.probe(8) manual page.
 *
 *
 * [Since] Added in version 1.0.43.
 *
 * [Feature] This function depends on the feature +ntfs3g+.  See also {#feature_available}[rdoc-ref:feature_available].
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_ntfs_3g_probe}[http://libguestfs.org/guestfs.3.html#guestfs_ntfs_3g_probe].
 */
VALUE
guestfs_int_ruby_ntfs_3g_probe (VALUE gv, VALUE rwv, VALUE devicev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "ntfs_3g_probe");

  int rw = RTEST (rwv);
  const char *device = StringValueCStr (devicev);

  int r;

  r = guestfs_ntfs_3g_probe (g, rw, device);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return INT2NUM (r);
}

/*
 * call-seq:
 *   g.ntfsclone_out(device, backupfile, {optargs...}) -> nil
 *
 * save NTFS to backup file
 *
 * Stream the NTFS filesystem "device" to the local file
 * "backupfile". The format used for the backup file is a
 * special format used by the ntfsclone(8) tool.
 * 
 * If the optional "metadataonly" flag is true, then *only*
 * the metadata is saved, losing all the user data (this is
 * useful for diagnosing some filesystem problems).
 * 
 * The optional "rescue", "ignorefscheck",
 * "preservetimestamps" and "force" flags have precise
 * meanings detailed in the ntfsclone(8) man page.
 * 
 * Use "g.ntfsclone_in" to restore the file back to a
 * libguestfs device.
 * 
 * Optional arguments are supplied in the final hash
 * parameter, which is a hash of the argument name to its
 * value. Pass an empty {} for no optional arguments.
 *
 *
 * [Since] Added in version 1.17.9.
 *
 * [Feature] This function depends on the feature +ntfs3g+.  See also {#feature_available}[rdoc-ref:feature_available].
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_ntfsclone_out}[http://libguestfs.org/guestfs.3.html#guestfs_ntfsclone_out].
 */
VALUE
guestfs_int_ruby_ntfsclone_out (int argc, VALUE *argv, VALUE gv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "ntfsclone_out");

  if (argc < 2 || argc > 3)
    rb_raise (rb_eArgError, "expecting 2 or 3 arguments");

  volatile VALUE devicev = argv[0];
  volatile VALUE backupfilev = argv[1];
  volatile VALUE optargsv = argc > 2 ? argv[2] : rb_hash_new ();

  const char *device = StringValueCStr (devicev);
  const char *backupfile = StringValueCStr (backupfilev);

  Check_Type (optargsv, T_HASH);
  struct guestfs_ntfsclone_out_argv optargs_s = { .bitmask = 0 };
  struct guestfs_ntfsclone_out_argv *optargs = &optargs_s;
  volatile VALUE v;
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("metadataonly")));
  if (v != Qnil) {
    optargs_s.metadataonly = RTEST (v);
    optargs_s.bitmask |= GUESTFS_NTFSCLONE_OUT_METADATAONLY_BITMASK;
  }
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("rescue")));
  if (v != Qnil) {
    optargs_s.rescue = RTEST (v);
    optargs_s.bitmask |= GUESTFS_NTFSCLONE_OUT_RESCUE_BITMASK;
  }
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("ignorefscheck")));
  if (v != Qnil) {
    optargs_s.ignorefscheck = RTEST (v);
    optargs_s.bitmask |= GUESTFS_NTFSCLONE_OUT_IGNOREFSCHECK_BITMASK;
  }
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("preservetimestamps")));
  if (v != Qnil) {
    optargs_s.preservetimestamps = RTEST (v);
    optargs_s.bitmask |= GUESTFS_NTFSCLONE_OUT_PRESERVETIMESTAMPS_BITMASK;
  }
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("force")));
  if (v != Qnil) {
    optargs_s.force = RTEST (v);
    optargs_s.bitmask |= GUESTFS_NTFSCLONE_OUT_FORCE_BITMASK;
  }

  int r;

  r = guestfs_ntfsclone_out_argv (g, device, backupfile, optargs);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.part_resize(device, partnum, endsect) -> nil
 *
 * resize a partition
 *
 * This command resizes the partition numbered "partnum" on
 * "device" by moving the end position.
 * 
 * Note that this does not modify any filesystem present in
 * the partition. If you wish to do this, you will need to
 * use filesystem resizing commands like "g.resize2fs".
 * 
 * When growing a partition you will want to grow the
 * filesystem afterwards, but when shrinking, you need to
 * shrink the filesystem before the partition.
 *
 *
 * [Since] Added in version 1.37.20.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_part_resize}[http://libguestfs.org/guestfs.3.html#guestfs_part_resize].
 */
VALUE
guestfs_int_ruby_part_resize (VALUE gv, VALUE devicev, VALUE partnumv, VALUE endsectv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "part_resize");

  const char *device = StringValueCStr (devicev);
  int partnum = NUM2INT (partnumv);
  long long endsect = NUM2LL (endsectv);

  int r;

  r = guestfs_part_resize (g, device, partnum, endsect);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.part_set_disk_guid(device, guid) -> nil
 *
 * set the GUID of a GPT-partitioned disk
 *
 * Set the disk identifier (GUID) of a GPT-partitioned
 * "device" to "guid". Return an error if the partition
 * table of "device" isn't GPT, or if "guid" is not a valid
 * GUID.
 *
 *
 * [Since] Added in version 1.33.2.
 *
 * [Feature] This function depends on the feature +gdisk+.  See also {#feature_available}[rdoc-ref:feature_available].
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_part_set_disk_guid}[http://libguestfs.org/guestfs.3.html#guestfs_part_set_disk_guid].
 */
VALUE
guestfs_int_ruby_part_set_disk_guid (VALUE gv, VALUE devicev, VALUE guidv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "part_set_disk_guid");

  const char *device = StringValueCStr (devicev);
  const char *guid = StringValueCStr (guidv);

  int r;

  r = guestfs_part_set_disk_guid (g, device, guid);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.part_set_disk_guid_random(device) -> nil
 *
 * set the GUID of a GPT-partitioned disk to random value
 *
 * Set the disk identifier (GUID) of a GPT-partitioned
 * "device" to a randomly generated value. Return an error
 * if the partition table of "device" isn't GPT.
 *
 *
 * [Since] Added in version 1.33.2.
 *
 * [Feature] This function depends on the feature +gdisk+.  See also {#feature_available}[rdoc-ref:feature_available].
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_part_set_disk_guid_random}[http://libguestfs.org/guestfs.3.html#guestfs_part_set_disk_guid_random].
 */
VALUE
guestfs_int_ruby_part_set_disk_guid_random (VALUE gv, VALUE devicev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "part_set_disk_guid_random");

  const char *device = StringValueCStr (devicev);

  int r;

  r = guestfs_part_set_disk_guid_random (g, device);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.pread(path, count, offset) -> string
 *
 * read part of a file
 *
 * This command lets you read part of a file. It reads
 * "count" bytes of the file, starting at "offset", from
 * file "path".
 * 
 * This may read fewer bytes than requested. For further
 * details see the pread(2) system call.
 * 
 * See also "g.pwrite", "g.pread_device".
 * 
 * Because of the message protocol, there is a transfer
 * limit of somewhere between 2MB and 4MB. See "PROTOCOL
 * LIMITS" in guestfs(3).
 *
 *
 * [Since] Added in version 1.0.77.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_pread}[http://libguestfs.org/guestfs.3.html#guestfs_pread].
 */
VALUE
guestfs_int_ruby_pread (VALUE gv, VALUE pathv, VALUE countv, VALUE offsetv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "pread");

  const char *path = StringValueCStr (pathv);
  int count = NUM2INT (countv);
  long long offset = NUM2LL (offsetv);

  char *r;
  size_t size;

  r = guestfs_pread (g, path, count, offset, &size);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  volatile VALUE rv = rb_str_new (r, size);
  free (r);
  return rv;
}

/*
 * call-seq:
 *   g.realpath(path) -> string
 *
 * canonicalized absolute pathname
 *
 * Return the canonicalized absolute pathname of "path".
 * The returned path has no ".", ".." or symbolic link path
 * elements.
 *
 *
 * [Since] Added in version 1.0.66.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_realpath}[http://libguestfs.org/guestfs.3.html#guestfs_realpath].
 */
VALUE
guestfs_int_ruby_realpath (VALUE gv, VALUE pathv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "realpath");

  const char *path = StringValueCStr (pathv);

  char *r;

  r = guestfs_realpath (g, path);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  volatile VALUE rv = rb_str_new2 (r);
  free (r);
  return rv;
}

/*
 * call-seq:
 *   g.selinux_relabel(specfile, path, {optargs...}) -> nil
 *
 * relabel parts of the filesystem
 *
 * SELinux relabel parts of the filesystem.
 * 
 * The "specfile" parameter controls the policy spec file
 * used. You have to parse "/etc/selinux/config" to find
 * the correct SELinux policy and then pass the spec file,
 * usually: "/etc/selinux/" + *selinuxtype* +
 * "/contexts/files/file_contexts".
 * 
 * The required "path" parameter is the top level directory
 * where relabelling starts. Normally you should pass
 * "path" as "/" to relabel the whole guest filesystem.
 * 
 * The optional "force" boolean controls whether the
 * context is reset for customizable files, and also
 * whether the user, role and range parts of the file
 * context is changed.
 * 
 * Optional arguments are supplied in the final hash
 * parameter, which is a hash of the argument name to its
 * value. Pass an empty {} for no optional arguments.
 *
 *
 * [Since] Added in version 1.33.43.
 *
 * [Feature] This function depends on the feature +selinuxrelabel+.  See also {#feature_available}[rdoc-ref:feature_available].
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_selinux_relabel}[http://libguestfs.org/guestfs.3.html#guestfs_selinux_relabel].
 */
VALUE
guestfs_int_ruby_selinux_relabel (int argc, VALUE *argv, VALUE gv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "selinux_relabel");

  if (argc < 2 || argc > 3)
    rb_raise (rb_eArgError, "expecting 2 or 3 arguments");

  volatile VALUE specfilev = argv[0];
  volatile VALUE pathv = argv[1];
  volatile VALUE optargsv = argc > 2 ? argv[2] : rb_hash_new ();

  const char *specfile = StringValueCStr (specfilev);
  const char *path = StringValueCStr (pathv);

  Check_Type (optargsv, T_HASH);
  struct guestfs_selinux_relabel_argv optargs_s = { .bitmask = 0 };
  struct guestfs_selinux_relabel_argv *optargs = &optargs_s;
  volatile VALUE v;
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("force")));
  if (v != Qnil) {
    optargs_s.force = RTEST (v);
    optargs_s.bitmask |= GUESTFS_SELINUX_RELABEL_FORCE_BITMASK;
  }

  int r;

  r = guestfs_selinux_relabel_argv (g, specfile, path, optargs);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.set_autosync(autosync) -> nil
 *
 * set autosync mode
 *
 * If "autosync" is true, this enables autosync. Libguestfs
 * will make a best effort attempt to make filesystems
 * consistent and synchronized when the handle is closed
 * (also if the program exits without closing handles).
 * 
 * This is enabled by default (since libguestfs 1.5.24,
 * previously it was disabled by default).
 *
 *
 * [Since] Added in version 0.3.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_set_autosync}[http://libguestfs.org/guestfs.3.html#guestfs_set_autosync].
 */
VALUE
guestfs_int_ruby_set_autosync (VALUE gv, VALUE autosyncv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "set_autosync");

  int autosync = RTEST (autosyncv);

  int r;

  r = guestfs_set_autosync (g, autosync);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.set_backend_setting(name, val) -> nil
 *
 * set a single per-backend settings string
 *
 * Append "name=value" to the backend settings string list.
 * However if a string already exists matching "name" or
 * beginning with "name=", then that setting is replaced.
 * 
 * See "BACKEND" in guestfs(3), "BACKEND SETTINGS" in
 * guestfs(3).
 *
 *
 * [Since] Added in version 1.27.2.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_set_backend_setting}[http://libguestfs.org/guestfs.3.html#guestfs_set_backend_setting].
 */
VALUE
guestfs_int_ruby_set_backend_setting (VALUE gv, VALUE namev, VALUE valv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "set_backend_setting");

  const char *name = StringValueCStr (namev);
  const char *val = StringValueCStr (valv);

  int r;

  r = guestfs_set_backend_setting (g, name, val);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.set_identifier(identifier) -> nil
 *
 * set the handle identifier
 *
 * This is an informative string which the caller may
 * optionally set in the handle. It is printed in various
 * places, allowing the current handle to be identified in
 * debugging output.
 * 
 * One important place is when tracing is enabled. If the
 * identifier string is not an empty string, then trace
 * messages change from this:
 * 
 * libguestfs: trace: get_tmpdir
 * libguestfs: trace: get_tmpdir = "/tmp"
 * 
 * to this:
 * 
 * libguestfs: trace: ID: get_tmpdir
 * libguestfs: trace: ID: get_tmpdir = "/tmp"
 * 
 * where "ID" is the identifier string set by this call.
 * 
 * The identifier must only contain alphanumeric ASCII
 * characters, underscore and minus sign. The default is
 * the empty string.
 * 
 * See also "g.set_program", "g.set_trace",
 * "g.get_identifier".
 *
 *
 * [Since] Added in version 1.31.14.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_set_identifier}[http://libguestfs.org/guestfs.3.html#guestfs_set_identifier].
 */
VALUE
guestfs_int_ruby_set_identifier (VALUE gv, VALUE identifierv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "set_identifier");

  const char *identifier = StringValueCStr (identifierv);

  int r;

  r = guestfs_set_identifier (g, identifier);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.set_verbose(verbose) -> nil
 *
 * set verbose mode
 *
 * If "verbose" is true, this turns on verbose messages.
 * 
 * Verbose messages are disabled unless the environment
 * variable "LIBGUESTFS_DEBUG" is defined and set to 1.
 * 
 * Verbose messages are normally sent to "stderr", unless
 * you register a callback to send them somewhere else (see
 * "g.set_event_callback").
 *
 *
 * [Since] Added in version 0.3.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_set_verbose}[http://libguestfs.org/guestfs.3.html#guestfs_set_verbose].
 */
VALUE
guestfs_int_ruby_set_verbose (VALUE gv, VALUE verbosev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "set_verbose");

  int verbose = RTEST (verbosev);

  int r;

  r = guestfs_set_verbose (g, verbose);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.swapoff_file(file) -> nil
 *
 * disable swap on file
 *
 * This command disables the libguestfs appliance swap on
 * file.
 *
 *
 * [Since] Added in version 1.0.66.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_swapoff_file}[http://libguestfs.org/guestfs.3.html#guestfs_swapoff_file].
 */
VALUE
guestfs_int_ruby_swapoff_file (VALUE gv, VALUE filev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "swapoff_file");

  const char *file = StringValueCStr (filev);

  int r;

  r = guestfs_swapoff_file (g, file);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.syslinux(device, {optargs...}) -> nil
 *
 * install the SYSLINUX bootloader
 *
 * Install the SYSLINUX bootloader on "device".
 * 
 * The device parameter must be either a whole disk
 * formatted as a FAT filesystem, or a partition formatted
 * as a FAT filesystem. In the latter case, the partition
 * should be marked as "active" ("g.part_set_bootable") and
 * a Master Boot Record must be installed (eg. using
 * "g.pwrite_device") on the first sector of the whole
 * disk. The SYSLINUX package comes with some suitable
 * Master Boot Records. See the syslinux(1) man page for
 * further information.
 * 
 * The optional arguments are:
 * 
 * directory
 * Install SYSLINUX in the named subdirectory, instead
 * of in the root directory of the FAT filesystem.
 * 
 * Additional configuration can be supplied to SYSLINUX by
 * placing a file called syslinux.cfg on the FAT
 * filesystem, either in the root directory, or under
 * directory if that optional argument is being used. For
 * further information about the contents of this file, see
 * syslinux(1).
 * 
 * See also "g.extlinux".
 * 
 * Optional arguments are supplied in the final hash
 * parameter, which is a hash of the argument name to its
 * value. Pass an empty {} for no optional arguments.
 *
 *
 * [Since] Added in version 1.21.27.
 *
 * [Feature] This function depends on the feature +syslinux+.  See also {#feature_available}[rdoc-ref:feature_available].
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_syslinux}[http://libguestfs.org/guestfs.3.html#guestfs_syslinux].
 */
VALUE
guestfs_int_ruby_syslinux (int argc, VALUE *argv, VALUE gv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "syslinux");

  if (argc < 1 || argc > 2)
    rb_raise (rb_eArgError, "expecting 1 or 2 arguments");

  volatile VALUE devicev = argv[0];
  volatile VALUE optargsv = argc > 1 ? argv[1] : rb_hash_new ();

  const char *device = StringValueCStr (devicev);

  Check_Type (optargsv, T_HASH);
  struct guestfs_syslinux_argv optargs_s = { .bitmask = 0 };
  struct guestfs_syslinux_argv *optargs = &optargs_s;
  volatile VALUE v;
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("directory")));
  if (v != Qnil) {
    optargs_s.directory = StringValueCStr (v);
    optargs_s.bitmask |= GUESTFS_SYSLINUX_DIRECTORY_BITMASK;
  }

  int r;

  r = guestfs_syslinux_argv (g, device, optargs);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.tail(path) -> list
 *
 * return last 10 lines of a file
 *
 * This command returns up to the last 10 lines of a file
 * as a list of strings.
 * 
 * Because of the message protocol, there is a transfer
 * limit of somewhere between 2MB and 4MB. See "PROTOCOL
 * LIMITS" in guestfs(3).
 *
 *
 * [Since] Added in version 1.0.54.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_tail}[http://libguestfs.org/guestfs.3.html#guestfs_tail].
 */
VALUE
guestfs_int_ruby_tail (VALUE gv, VALUE pathv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "tail");

  const char *path = StringValueCStr (pathv);

  char **r;

  r = guestfs_tail (g, path);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  size_t i, len = 0;
  for (i = 0; r[i] != NULL; ++i) len++;
  volatile VALUE rv = rb_ary_new2 (len);
  for (i = 0; r[i] != NULL; ++i) {
    rb_ary_push (rv, rb_str_new2 (r[i]));
    free (r[i]);
  }
  free (r);
  return rv;
}

/*
 * call-seq:
 *   g.touch(path) -> nil
 *
 * update file timestamps or create a new file
 *
 * Touch acts like the touch(1) command. It can be used to
 * update the timestamps on a file, or, if the file does
 * not exist, to create a new zero-length file.
 * 
 * This command only works on regular files, and will fail
 * on other file types such as directories, symbolic links,
 * block special etc.
 *
 *
 * [Since] Added in version 0.3.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_touch}[http://libguestfs.org/guestfs.3.html#guestfs_touch].
 */
VALUE
guestfs_int_ruby_touch (VALUE gv, VALUE pathv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "touch");

  const char *path = StringValueCStr (pathv);

  int r;

  r = guestfs_touch (g, path);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.tune2fs_l(device) -> hash
 *
 * get ext2/ext3/ext4 superblock details
 *
 * This returns the contents of the ext2, ext3 or ext4
 * filesystem superblock on "device".
 * 
 * It is the same as running "tune2fs -l device". See
 * tune2fs(8) manpage for more details. The list of fields
 * returned isn't clearly defined, and depends on both the
 * version of "tune2fs" that libguestfs was built against,
 * and the filesystem itself.
 *
 *
 * [Since] Added in version 1.9.2.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_tune2fs_l}[http://libguestfs.org/guestfs.3.html#guestfs_tune2fs_l].
 */
VALUE
guestfs_int_ruby_tune2fs_l (VALUE gv, VALUE devicev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "tune2fs_l");

  const char *device = StringValueCStr (devicev);

  char **r;

  r = guestfs_tune2fs_l (g, device);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  volatile VALUE rv = rb_hash_new ();
  size_t i;
  for (i = 0; r[i] != NULL; i+=2) {
    rb_hash_aset (rv, rb_str_new2 (r[i]), rb_str_new2 (r[i+1]));
    free (r[i]);
    free (r[i+1]);
  }
  free (r);
  return rv;
}

/*
 * call-seq:
 *   g.umount(pathordevice, {optargs...}) -> nil
 *
 * unmount a filesystem
 *
 * This unmounts the given filesystem. The filesystem may
 * be specified either by its mountpoint (path) or the
 * device which contains the filesystem.
 * 
 * Optional arguments are supplied in the final hash
 * parameter, which is a hash of the argument name to its
 * value. Pass an empty {} for no optional arguments.
 *
 *
 * [Since] Added in version 0.8.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_umount}[http://libguestfs.org/guestfs.3.html#guestfs_umount].
 */
VALUE
guestfs_int_ruby_umount (int argc, VALUE *argv, VALUE gv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "umount");

  if (argc < 1 || argc > 2)
    rb_raise (rb_eArgError, "expecting 1 or 2 arguments");

  volatile VALUE pathordevicev = argv[0];
  volatile VALUE optargsv = argc > 1 ? argv[1] : rb_hash_new ();

  const char *pathordevice = StringValueCStr (pathordevicev);

  Check_Type (optargsv, T_HASH);
  struct guestfs_umount_opts_argv optargs_s = { .bitmask = 0 };
  struct guestfs_umount_opts_argv *optargs = &optargs_s;
  volatile VALUE v;
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("force")));
  if (v != Qnil) {
    optargs_s.force = RTEST (v);
    optargs_s.bitmask |= GUESTFS_UMOUNT_OPTS_FORCE_BITMASK;
  }
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("lazyunmount")));
  if (v != Qnil) {
    optargs_s.lazyunmount = RTEST (v);
    optargs_s.bitmask |= GUESTFS_UMOUNT_OPTS_LAZYUNMOUNT_BITMASK;
  }

  int r;

  r = guestfs_umount_opts_argv (g, pathordevice, optargs);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.vg_activate(activate, volgroups) -> nil
 *
 * activate or deactivate some volume groups
 *
 * This command activates or (if "activate" is false)
 * deactivates all logical volumes in the listed volume
 * groups "volgroups".
 * 
 * This command is the same as running "vgchange -a y|n
 * volgroups..."
 * 
 * Note that if "volgroups" is an empty list then all
 * volume groups are activated or deactivated.
 *
 *
 * [Since] Added in version 1.0.26.
 *
 * [Feature] This function depends on the feature +lvm2+.  See also {#feature_available}[rdoc-ref:feature_available].
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_vg_activate}[http://libguestfs.org/guestfs.3.html#guestfs_vg_activate].
 */
VALUE
guestfs_int_ruby_vg_activate (VALUE gv, VALUE activatev, VALUE volgroupsv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "vg_activate");

  int activate = RTEST (activatev);
  char **volgroups;
  Check_Type (volgroupsv, T_ARRAY);
  {
    size_t i, len;
    len = RARRAY_LEN (volgroupsv);
    volgroups = ALLOC_N (char *, len+1);
    for (i = 0; i < len; ++i) {
      volatile VALUE v = rb_ary_entry (volgroupsv, i);
      volgroups[i] = StringValueCStr (v);
    }
    volgroups[len] = NULL;
  }

  int r;

  r = guestfs_vg_activate (g, activate, volgroups);
  free (volgroups);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.vgs_full() -> list
 *
 * list the LVM volume groups (VGs)
 *
 * List all the volumes groups detected. This is the
 * equivalent of the vgs(8) command. The "full" version
 * includes all fields.
 *
 *
 * [Since] Added in version 0.4.
 *
 * [Feature] This function depends on the feature +lvm2+.  See also {#feature_available}[rdoc-ref:feature_available].
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_vgs_full}[http://libguestfs.org/guestfs.3.html#guestfs_vgs_full].
 */
VALUE
guestfs_int_ruby_vgs_full (VALUE gv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "vgs_full");


  struct guestfs_lvm_vg_list *r;

  r = guestfs_vgs_full (g);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  volatile VALUE rv = rb_ary_new2 (r->len);
  size_t i;
  for (i = 0; i < r->len; ++i) {
    volatile VALUE hv = rb_hash_new ();
    rb_hash_aset (hv, rb_str_new2 ("vg_name"), rb_str_new2 (r->val[i].vg_name));
    rb_hash_aset (hv, rb_str_new2 ("vg_uuid"), rb_str_new (r->val[i].vg_uuid, 32));
    rb_hash_aset (hv, rb_str_new2 ("vg_fmt"), rb_str_new2 (r->val[i].vg_fmt));
    rb_hash_aset (hv, rb_str_new2 ("vg_attr"), rb_str_new2 (r->val[i].vg_attr));
    rb_hash_aset (hv, rb_str_new2 ("vg_size"), ULL2NUM (r->val[i].vg_size));
    rb_hash_aset (hv, rb_str_new2 ("vg_free"), ULL2NUM (r->val[i].vg_free));
    rb_hash_aset (hv, rb_str_new2 ("vg_sysid"), rb_str_new2 (r->val[i].vg_sysid));
    rb_hash_aset (hv, rb_str_new2 ("vg_extent_size"), ULL2NUM (r->val[i].vg_extent_size));
    rb_hash_aset (hv, rb_str_new2 ("vg_extent_count"), LL2NUM (r->val[i].vg_extent_count));
    rb_hash_aset (hv, rb_str_new2 ("vg_free_count"), LL2NUM (r->val[i].vg_free_count));
    rb_hash_aset (hv, rb_str_new2 ("max_lv"), LL2NUM (r->val[i].max_lv));
    rb_hash_aset (hv, rb_str_new2 ("max_pv"), LL2NUM (r->val[i].max_pv));
    rb_hash_aset (hv, rb_str_new2 ("pv_count"), LL2NUM (r->val[i].pv_count));
    rb_hash_aset (hv, rb_str_new2 ("lv_count"), LL2NUM (r->val[i].lv_count));
    rb_hash_aset (hv, rb_str_new2 ("snap_count"), LL2NUM (r->val[i].snap_count));
    rb_hash_aset (hv, rb_str_new2 ("vg_seqno"), LL2NUM (r->val[i].vg_seqno));
    rb_hash_aset (hv, rb_str_new2 ("vg_tags"), rb_str_new2 (r->val[i].vg_tags));
    rb_hash_aset (hv, rb_str_new2 ("vg_mda_count"), LL2NUM (r->val[i].vg_mda_count));
    rb_hash_aset (hv, rb_str_new2 ("vg_mda_free"), ULL2NUM (r->val[i].vg_mda_free));
    rb_ary_push (rv, hv);
  }
  guestfs_free_lvm_vg_list (r);
  return rv;
}

/*
 * call-seq:
 *   g.vgscan() -> nil
 *
 * rescan for LVM physical volumes, volume groups and logical volumes
 *
 * This rescans all block devices and rebuilds the list of
 * LVM physical volumes, volume groups and logical volumes.
 *
 *
 * [Since] Added in version 1.3.2.
 *
 * [Deprecated] In new code, use rdoc-ref:lvm_scan instead.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_vgscan}[http://libguestfs.org/guestfs.3.html#guestfs_vgscan].
 */
VALUE
guestfs_int_ruby_vgscan (VALUE gv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "vgscan");


  int r;

  r = guestfs_vgscan (g);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.xfs_admin(device, {optargs...}) -> nil
 *
 * change parameters of an XFS filesystem
 *
 * Change the parameters of the XFS filesystem on "device".
 * 
 * Devices that are mounted cannot be modified.
 * Administrators must unmount filesystems before this call
 * can modify parameters.
 * 
 * Some of the parameters of a mounted filesystem can be
 * examined and modified using the "g.xfs_info" and
 * "g.xfs_growfs" calls.
 * 
 * Optional arguments are supplied in the final hash
 * parameter, which is a hash of the argument name to its
 * value. Pass an empty {} for no optional arguments.
 *
 *
 * [Since] Added in version 1.19.33.
 *
 * [Feature] This function depends on the feature +xfs+.  See also {#feature_available}[rdoc-ref:feature_available].
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_xfs_admin}[http://libguestfs.org/guestfs.3.html#guestfs_xfs_admin].
 */
VALUE
guestfs_int_ruby_xfs_admin (int argc, VALUE *argv, VALUE gv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "xfs_admin");

  if (argc < 1 || argc > 2)
    rb_raise (rb_eArgError, "expecting 1 or 2 arguments");

  volatile VALUE devicev = argv[0];
  volatile VALUE optargsv = argc > 1 ? argv[1] : rb_hash_new ();

  const char *device = StringValueCStr (devicev);

  Check_Type (optargsv, T_HASH);
  struct guestfs_xfs_admin_argv optargs_s = { .bitmask = 0 };
  struct guestfs_xfs_admin_argv *optargs = &optargs_s;
  volatile VALUE v;
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("extunwritten")));
  if (v != Qnil) {
    optargs_s.extunwritten = RTEST (v);
    optargs_s.bitmask |= GUESTFS_XFS_ADMIN_EXTUNWRITTEN_BITMASK;
  }
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("imgfile")));
  if (v != Qnil) {
    optargs_s.imgfile = RTEST (v);
    optargs_s.bitmask |= GUESTFS_XFS_ADMIN_IMGFILE_BITMASK;
  }
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("v2log")));
  if (v != Qnil) {
    optargs_s.v2log = RTEST (v);
    optargs_s.bitmask |= GUESTFS_XFS_ADMIN_V2LOG_BITMASK;
  }
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("projid32bit")));
  if (v != Qnil) {
    optargs_s.projid32bit = RTEST (v);
    optargs_s.bitmask |= GUESTFS_XFS_ADMIN_PROJID32BIT_BITMASK;
  }
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("lazycounter")));
  if (v != Qnil) {
    optargs_s.lazycounter = RTEST (v);
    optargs_s.bitmask |= GUESTFS_XFS_ADMIN_LAZYCOUNTER_BITMASK;
  }
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("label")));
  if (v != Qnil) {
    optargs_s.label = StringValueCStr (v);
    optargs_s.bitmask |= GUESTFS_XFS_ADMIN_LABEL_BITMASK;
  }
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("uuid")));
  if (v != Qnil) {
    optargs_s.uuid = StringValueCStr (v);
    optargs_s.bitmask |= GUESTFS_XFS_ADMIN_UUID_BITMASK;
  }

  int r;

  r = guestfs_xfs_admin_argv (g, device, optargs);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.yara_destroy() -> nil
 *
 * destroy previously loaded yara rules
 *
 * Destroy previously loaded Yara rules in order to free
 * libguestfs resources.
 *
 *
 * [Since] Added in version 1.37.13.
 *
 * [Feature] This function depends on the feature +libyara+.  See also {#feature_available}[rdoc-ref:feature_available].
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_yara_destroy}[http://libguestfs.org/guestfs.3.html#guestfs_yara_destroy].
 */
VALUE
guestfs_int_ruby_yara_destroy (VALUE gv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "yara_destroy");


  int r;

  r = guestfs_yara_destroy (g);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.zegrepi(regex, path) -> list
 *
 * return lines matching a pattern
 *
 * This calls the external "zegrep -i" program and returns
 * the matching lines.
 * 
 * Because of the message protocol, there is a transfer
 * limit of somewhere between 2MB and 4MB. See "PROTOCOL
 * LIMITS" in guestfs(3).
 *
 *
 * [Since] Added in version 1.0.66.
 *
 * [Deprecated] In new code, use rdoc-ref:grep instead.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_zegrepi}[http://libguestfs.org/guestfs.3.html#guestfs_zegrepi].
 */
VALUE
guestfs_int_ruby_zegrepi (VALUE gv, VALUE regexv, VALUE pathv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "zegrepi");

  const char *regex = StringValueCStr (regexv);
  const char *path = StringValueCStr (pathv);

  char **r;

  r = guestfs_zegrepi (g, regex, path);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  size_t i, len = 0;
  for (i = 0; r[i] != NULL; ++i) len++;
  volatile VALUE rv = rb_ary_new2 (len);
  for (i = 0; r[i] != NULL; ++i) {
    rb_ary_push (rv, rb_str_new2 (r[i]));
    free (r[i]);
  }
  free (r);
  return rv;
}

/*
 * call-seq:
 *   g.zfgrep(pattern, path) -> list
 *
 * return lines matching a pattern
 *
 * This calls the external "zfgrep" program and returns the
 * matching lines.
 * 
 * Because of the message protocol, there is a transfer
 * limit of somewhere between 2MB and 4MB. See "PROTOCOL
 * LIMITS" in guestfs(3).
 *
 *
 * [Since] Added in version 1.0.66.
 *
 * [Deprecated] In new code, use rdoc-ref:grep instead.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_zfgrep}[http://libguestfs.org/guestfs.3.html#guestfs_zfgrep].
 */
VALUE
guestfs_int_ruby_zfgrep (VALUE gv, VALUE patternv, VALUE pathv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "zfgrep");

  const char *pattern = StringValueCStr (patternv);
  const char *path = StringValueCStr (pathv);

  char **r;

  r = guestfs_zfgrep (g, pattern, path);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  size_t i, len = 0;
  for (i = 0; r[i] != NULL; ++i) len++;
  volatile VALUE rv = rb_ary_new2 (len);
  for (i = 0; r[i] != NULL; ++i) {
    rb_ary_push (rv, rb_str_new2 (r[i]));
    free (r[i]);
  }
  free (r);
  return rv;
}

/*
 * call-seq:
 *   g.zfile(meth, path) -> string
 *
 * determine file type inside a compressed file
 *
 * This command runs file after first decompressing "path"
 * using "method".
 * 
 * "method" must be one of "gzip", "compress" or "bzip2".
 * 
 * Since 1.0.63, use "g.file" instead which can now process
 * compressed files.
 *
 *
 * [Since] Added in version 1.0.59.
 *
 * [Deprecated] In new code, use rdoc-ref:file instead.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_zfile}[http://libguestfs.org/guestfs.3.html#guestfs_zfile].
 */
VALUE
guestfs_int_ruby_zfile (VALUE gv, VALUE methv, VALUE pathv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "zfile");

  const char *meth = StringValueCStr (methv);
  const char *path = StringValueCStr (pathv);

  char *r;

  r = guestfs_zfile (g, meth, path);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  volatile VALUE rv = rb_str_new2 (r);
  free (r);
  return rv;
}

