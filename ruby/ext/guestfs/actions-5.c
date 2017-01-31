/* libguestfs generated file
 * WARNING: THIS FILE IS GENERATED FROM THE FOLLOWING FILES:
 *          generator/ruby.ml
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
#include <stdint.h>
#include <string.h>
#include <errno.h>
#include <assert.h>

#include "actions.h"

/*
 * call-seq:
 *   g.acl_set_file(path, acltype, acl) -> nil
 *
 * set the POSIX ACL attached to a file
 *
 * This function sets the POSIX Access Control List (ACL)
 * attached to "path".
 * 
 * The "acltype" parameter may be:
 * 
 * "access"
 * Set the ordinary (access) ACL for any file,
 * directory or other filesystem object.
 * 
 * "default"
 * Set the default ACL. Normally this only makes sense
 * if "path" is a directory.
 * 
 * The "acl" parameter is the new ACL in either "long text
 * form" or "short text form" (see acl(5)). The new ACL
 * completely replaces any previous ACL on the file. The
 * ACL must contain the full Unix permissions (eg.
 * "u::rwx,g::rx,o::rx").
 * 
 * If you are specifying individual users or groups, then
 * the mask field is also required (eg. "m::rwx"), followed
 * by the "u:*ID*:..." and/or "g:*ID*:..." field(s). A full
 * ACL string might therefore look like this:
 * 
 * u::rwx,g::rwx,o::rwx,m::rwx,u:500:rwx,g:500:rwx
 * \ Unix permissions / \mask/ \      ACL        /
 * 
 * You should use numeric UIDs and GIDs. To map usernames
 * and groupnames to the correct numeric ID in the context
 * of the guest, use the Augeas functions (see
 * "g.aug_init").
 *
 *
 * [Since] Added in version 1.19.63.
 *
 * [Feature] This function depends on the feature +acl+.  See also {#feature_available}[rdoc-ref:feature_available].
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_acl_set_file}[http://libguestfs.org/guestfs.3.html#guestfs_acl_set_file].
 */
VALUE
guestfs_int_ruby_acl_set_file (VALUE gv, VALUE pathv, VALUE acltypev, VALUE aclv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "acl_set_file");

  const char *path = StringValueCStr (pathv);
  const char *acltype = StringValueCStr (acltypev);
  const char *acl = StringValueCStr (aclv);

  int r;

  r = guestfs_acl_set_file (g, path, acltype, acl);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.add_drive_with_if(filename, iface) -> nil
 *
 * add a drive specifying the QEMU block emulation to use
 *
 * This is the same as "g.add_drive" but it allows you to
 * specify the QEMU interface emulation to use at run time.
 *
 *
 * [Since] Added in version 1.0.84.
 *
 * [Deprecated] In new code, use rdoc-ref:add_drive instead.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_add_drive_with_if}[http://libguestfs.org/guestfs.3.html#guestfs_add_drive_with_if].
 */
VALUE
guestfs_int_ruby_add_drive_with_if (VALUE gv, VALUE filenamev, VALUE ifacev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "add_drive_with_if");

  const char *filename = StringValueCStr (filenamev);
  const char *iface = StringValueCStr (ifacev);

  int r;

  r = guestfs_add_drive_with_if (g, filename, iface);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.blockdev_flushbufs(device) -> nil
 *
 * flush device buffers
 *
 * This tells the kernel to flush internal buffers
 * associated with "device".
 * 
 * This uses the blockdev(8) command.
 *
 *
 * [Since] Added in version 1.9.3.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_blockdev_flushbufs}[http://libguestfs.org/guestfs.3.html#guestfs_blockdev_flushbufs].
 */
VALUE
guestfs_int_ruby_blockdev_flushbufs (VALUE gv, VALUE devicev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "blockdev_flushbufs");

  const char *device = StringValueCStr (devicev);

  int r;

  r = guestfs_blockdev_flushbufs (g, device);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.blockdev_setrw(device) -> nil
 *
 * set block device to read-write
 *
 * Sets the block device named "device" to read-write.
 * 
 * This uses the blockdev(8) command.
 *
 *
 * [Since] Added in version 1.9.3.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_blockdev_setrw}[http://libguestfs.org/guestfs.3.html#guestfs_blockdev_setrw].
 */
VALUE
guestfs_int_ruby_blockdev_setrw (VALUE gv, VALUE devicev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "blockdev_setrw");

  const char *device = StringValueCStr (devicev);

  int r;

  r = guestfs_blockdev_setrw (g, device);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.btrfs_balance_pause(path) -> nil
 *
 * pause a running balance
 *
 * Pause a running balance on a btrfs filesystem.
 *
 *
 * [Since] Added in version 1.29.22.
 *
 * [Feature] This function depends on the feature +btrfs+.  See also {#feature_available}[rdoc-ref:feature_available].
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_btrfs_balance_pause}[http://libguestfs.org/guestfs.3.html#guestfs_btrfs_balance_pause].
 */
VALUE
guestfs_int_ruby_btrfs_balance_pause (VALUE gv, VALUE pathv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "btrfs_balance_pause");

  const char *path = StringValueCStr (pathv);

  int r;

  r = guestfs_btrfs_balance_pause (g, path);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.btrfs_device_add(devices, fs) -> nil
 *
 * add devices to a btrfs filesystem
 *
 * Add the list of device(s) in "devices" to the btrfs
 * filesystem mounted at "fs". If "devices" is an empty
 * list, this does nothing.
 *
 *
 * [Since] Added in version 1.17.35.
 *
 * [Feature] This function depends on the feature +btrfs+.  See also {#feature_available}[rdoc-ref:feature_available].
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_btrfs_device_add}[http://libguestfs.org/guestfs.3.html#guestfs_btrfs_device_add].
 */
VALUE
guestfs_int_ruby_btrfs_device_add (VALUE gv, VALUE devicesv, VALUE fsv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "btrfs_device_add");

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
  const char *fs = StringValueCStr (fsv);

  int r;

  r = guestfs_btrfs_device_add (g, devices, fs);
  free (devices);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.btrfs_filesystem_balance(fs) -> nil
 *
 * balance a btrfs filesystem
 *
 * Balance the chunks in the btrfs filesystem mounted at
 * "fs" across the underlying devices.
 *
 *
 * [Since] Added in version 1.17.35.
 *
 * [Feature] This function depends on the feature +btrfs+.  See also {#feature_available}[rdoc-ref:feature_available].
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_btrfs_filesystem_balance}[http://libguestfs.org/guestfs.3.html#guestfs_btrfs_filesystem_balance].
 */
VALUE
guestfs_int_ruby_btrfs_filesystem_balance (VALUE gv, VALUE fsv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "btrfs_filesystem_balance");

  const char *fs = StringValueCStr (fsv);

  int r;

  r = guestfs_btrfs_filesystem_balance (g, fs);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.btrfs_filesystem_show(device) -> list
 *
 * list devices for btrfs filesystem
 *
 * Show all the devices where the filesystems in "device"
 * is spanned over.
 * 
 * If not all the devices for the filesystems are present,
 * then this function fails and the "errno" is set to
 * "ENODEV".
 *
 *
 * [Since] Added in version 1.33.29.
 *
 * [Feature] This function depends on the feature +btrfs+.  See also {#feature_available}[rdoc-ref:feature_available].
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_btrfs_filesystem_show}[http://libguestfs.org/guestfs.3.html#guestfs_btrfs_filesystem_show].
 */
VALUE
guestfs_int_ruby_btrfs_filesystem_show (VALUE gv, VALUE devicev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "btrfs_filesystem_show");

  const char *device = StringValueCStr (devicev);

  char **r;

  r = guestfs_btrfs_filesystem_show (g, device);
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
 *   g.btrfs_qgroup_assign(src, dst, path) -> nil
 *
 * add a qgroup to a parent qgroup
 *
 * Add qgroup "src" to parent qgroup "dst". This command
 * can group several qgroups into a parent qgroup to share
 * common limit.
 *
 *
 * [Since] Added in version 1.29.17.
 *
 * [Feature] This function depends on the feature +btrfs+.  See also {#feature_available}[rdoc-ref:feature_available].
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_btrfs_qgroup_assign}[http://libguestfs.org/guestfs.3.html#guestfs_btrfs_qgroup_assign].
 */
VALUE
guestfs_int_ruby_btrfs_qgroup_assign (VALUE gv, VALUE srcv, VALUE dstv, VALUE pathv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "btrfs_qgroup_assign");

  const char *src = StringValueCStr (srcv);
  const char *dst = StringValueCStr (dstv);
  const char *path = StringValueCStr (pathv);

  int r;

  r = guestfs_btrfs_qgroup_assign (g, src, dst, path);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.btrfs_replace(srcdev, targetdev, mntpoint) -> nil
 *
 * replace a btrfs managed device with another device
 *
 * Replace device of a btrfs filesystem. On a live
 * filesystem, duplicate the data to the target device
 * which is currently stored on the source device. After
 * completion of the operation, the source device is wiped
 * out and removed from the filesystem.
 * 
 * The "targetdev" needs to be same size or larger than the
 * "srcdev". Devices which are currently mounted are never
 * allowed to be used as the "targetdev".
 *
 *
 * [Since] Added in version 1.29.48.
 *
 * [Feature] This function depends on the feature +btrfs+.  See also {#feature_available}[rdoc-ref:feature_available].
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_btrfs_replace}[http://libguestfs.org/guestfs.3.html#guestfs_btrfs_replace].
 */
VALUE
guestfs_int_ruby_btrfs_replace (VALUE gv, VALUE srcdevv, VALUE targetdevv, VALUE mntpointv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "btrfs_replace");

  const char *srcdev = StringValueCStr (srcdevv);
  const char *targetdev = StringValueCStr (targetdevv);
  const char *mntpoint = StringValueCStr (mntpointv);

  int r;

  r = guestfs_btrfs_replace (g, srcdev, targetdev, mntpoint);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.btrfs_scrub_cancel(path) -> nil
 *
 * cancel a running scrub
 *
 * Cancel a running scrub on a btrfs filesystem.
 *
 *
 * [Since] Added in version 1.29.22.
 *
 * [Feature] This function depends on the feature +btrfs+.  See also {#feature_available}[rdoc-ref:feature_available].
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_btrfs_scrub_cancel}[http://libguestfs.org/guestfs.3.html#guestfs_btrfs_scrub_cancel].
 */
VALUE
guestfs_int_ruby_btrfs_scrub_cancel (VALUE gv, VALUE pathv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "btrfs_scrub_cancel");

  const char *path = StringValueCStr (pathv);

  int r;

  r = guestfs_btrfs_scrub_cancel (g, path);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.btrfs_subvolume_get_default(fs) -> fixnum
 *
 * get the default subvolume or snapshot of a filesystem
 *
 * Get the default subvolume or snapshot of a filesystem
 * mounted at "mountpoint".
 *
 *
 * [Since] Added in version 1.29.17.
 *
 * [Feature] This function depends on the feature +btrfs+.  See also {#feature_available}[rdoc-ref:feature_available].
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_btrfs_subvolume_get_default}[http://libguestfs.org/guestfs.3.html#guestfs_btrfs_subvolume_get_default].
 */
VALUE
guestfs_int_ruby_btrfs_subvolume_get_default (VALUE gv, VALUE fsv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "btrfs_subvolume_get_default");

  const char *fs = StringValueCStr (fsv);

  int64_t r;

  r = guestfs_btrfs_subvolume_get_default (g, fs);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return ULL2NUM (r);
}

/*
 * call-seq:
 *   g.btrfstune_seeding(device, seeding) -> nil
 *
 * enable or disable seeding of a btrfs device
 *
 * Enable seeding of a btrfs device, this will force a fs
 * readonly so that you can use it to build other
 * filesystems.
 *
 *
 * [Since] Added in version 1.29.29.
 *
 * [Feature] This function depends on the feature +btrfs+.  See also {#feature_available}[rdoc-ref:feature_available].
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_btrfstune_seeding}[http://libguestfs.org/guestfs.3.html#guestfs_btrfstune_seeding].
 */
VALUE
guestfs_int_ruby_btrfstune_seeding (VALUE gv, VALUE devicev, VALUE seedingv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "btrfstune_seeding");

  const char *device = StringValueCStr (devicev);
  int seeding = RTEST (seedingv);

  int r;

  r = guestfs_btrfstune_seeding (g, device, seeding);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.c_pointer() -> fixnum
 *
 * return the C pointer to the guestfs_h handle
 *
 * In non-C language bindings, this allows you to retrieve
 * the underlying C pointer to the handle (ie. "g.h *").
 * The purpose of this is to allow other libraries to
 * interwork with libguestfs.
 *
 *
 * [Since] Added in version 1.29.17.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_c_pointer}[http://libguestfs.org/guestfs.3.html#guestfs_c_pointer].
 */
VALUE
guestfs_int_ruby_c_pointer (VALUE gv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "c_pointer");


  int64_t r;

  r = guestfs_c_pointer (g);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return ULL2NUM (r);
}

/*
 * call-seq:
 *   g.cap_set_file(path, cap) -> nil
 *
 * set the Linux capabilities attached to a file
 *
 * This function sets the Linux capabilities attached to
 * "path". The capabilities set "cap" should be passed in
 * text form (see cap_from_text(3)).
 *
 *
 * [Since] Added in version 1.19.63.
 *
 * [Feature] This function depends on the feature +linuxcaps+.  See also {#feature_available}[rdoc-ref:feature_available].
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_cap_set_file}[http://libguestfs.org/guestfs.3.html#guestfs_cap_set_file].
 */
VALUE
guestfs_int_ruby_cap_set_file (VALUE gv, VALUE pathv, VALUE capv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "cap_set_file");

  const char *path = StringValueCStr (pathv);
  const char *cap = StringValueCStr (capv);

  int r;

  r = guestfs_cap_set_file (g, path, cap);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.copy_file_to_device(src, dest, {optargs...}) -> nil
 *
 * copy from source file to destination device
 *
 * See "g.copy_device_to_device" for a general overview of
 * this call.
 * 
 * Optional arguments are supplied in the final hash
 * parameter, which is a hash of the argument name to its
 * value. Pass an empty {} for no optional arguments.
 *
 *
 * [Since] Added in version 1.13.25.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_copy_file_to_device}[http://libguestfs.org/guestfs.3.html#guestfs_copy_file_to_device].
 */
VALUE
guestfs_int_ruby_copy_file_to_device (int argc, VALUE *argv, VALUE gv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "copy_file_to_device");

  if (argc < 2 || argc > 3)
    rb_raise (rb_eArgError, "expecting 2 or 3 arguments");

  volatile VALUE srcv = argv[0];
  volatile VALUE destv = argv[1];
  volatile VALUE optargsv = argc > 2 ? argv[2] : rb_hash_new ();

  const char *src = StringValueCStr (srcv);
  const char *dest = StringValueCStr (destv);

  Check_Type (optargsv, T_HASH);
  struct guestfs_copy_file_to_device_argv optargs_s = { .bitmask = 0 };
  struct guestfs_copy_file_to_device_argv *optargs = &optargs_s;
  volatile VALUE v;
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("srcoffset")));
  if (v != Qnil) {
    optargs_s.srcoffset = NUM2LL (v);
    optargs_s.bitmask |= GUESTFS_COPY_FILE_TO_DEVICE_SRCOFFSET_BITMASK;
  }
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("destoffset")));
  if (v != Qnil) {
    optargs_s.destoffset = NUM2LL (v);
    optargs_s.bitmask |= GUESTFS_COPY_FILE_TO_DEVICE_DESTOFFSET_BITMASK;
  }
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("size")));
  if (v != Qnil) {
    optargs_s.size = NUM2LL (v);
    optargs_s.bitmask |= GUESTFS_COPY_FILE_TO_DEVICE_SIZE_BITMASK;
  }
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("sparse")));
  if (v != Qnil) {
    optargs_s.sparse = RTEST (v);
    optargs_s.bitmask |= GUESTFS_COPY_FILE_TO_DEVICE_SPARSE_BITMASK;
  }
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("append")));
  if (v != Qnil) {
    optargs_s.append = RTEST (v);
    optargs_s.bitmask |= GUESTFS_COPY_FILE_TO_DEVICE_APPEND_BITMASK;
  }

  int r;

  r = guestfs_copy_file_to_device_argv (g, src, dest, optargs);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.copy_file_to_file(src, dest, {optargs...}) -> nil
 *
 * copy from source file to destination file
 *
 * See "g.copy_device_to_device" for a general overview of
 * this call.
 * 
 * This is not the function you want for copying files.
 * This is for copying blocks within existing files. See
 * "g.cp", "g.cp_a" and "g.mv" for general file copying and
 * moving functions.
 * 
 * Optional arguments are supplied in the final hash
 * parameter, which is a hash of the argument name to its
 * value. Pass an empty {} for no optional arguments.
 *
 *
 * [Since] Added in version 1.13.25.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_copy_file_to_file}[http://libguestfs.org/guestfs.3.html#guestfs_copy_file_to_file].
 */
VALUE
guestfs_int_ruby_copy_file_to_file (int argc, VALUE *argv, VALUE gv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "copy_file_to_file");

  if (argc < 2 || argc > 3)
    rb_raise (rb_eArgError, "expecting 2 or 3 arguments");

  volatile VALUE srcv = argv[0];
  volatile VALUE destv = argv[1];
  volatile VALUE optargsv = argc > 2 ? argv[2] : rb_hash_new ();

  const char *src = StringValueCStr (srcv);
  const char *dest = StringValueCStr (destv);

  Check_Type (optargsv, T_HASH);
  struct guestfs_copy_file_to_file_argv optargs_s = { .bitmask = 0 };
  struct guestfs_copy_file_to_file_argv *optargs = &optargs_s;
  volatile VALUE v;
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("srcoffset")));
  if (v != Qnil) {
    optargs_s.srcoffset = NUM2LL (v);
    optargs_s.bitmask |= GUESTFS_COPY_FILE_TO_FILE_SRCOFFSET_BITMASK;
  }
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("destoffset")));
  if (v != Qnil) {
    optargs_s.destoffset = NUM2LL (v);
    optargs_s.bitmask |= GUESTFS_COPY_FILE_TO_FILE_DESTOFFSET_BITMASK;
  }
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("size")));
  if (v != Qnil) {
    optargs_s.size = NUM2LL (v);
    optargs_s.bitmask |= GUESTFS_COPY_FILE_TO_FILE_SIZE_BITMASK;
  }
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("sparse")));
  if (v != Qnil) {
    optargs_s.sparse = RTEST (v);
    optargs_s.bitmask |= GUESTFS_COPY_FILE_TO_FILE_SPARSE_BITMASK;
  }
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("append")));
  if (v != Qnil) {
    optargs_s.append = RTEST (v);
    optargs_s.bitmask |= GUESTFS_COPY_FILE_TO_FILE_APPEND_BITMASK;
  }

  int r;

  r = guestfs_copy_file_to_file_argv (g, src, dest, optargs);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.cpio_out(directory, cpiofile, {optargs...}) -> nil
 *
 * pack directory into cpio file
 *
 * This command packs the contents of directory and
 * downloads it to local file "cpiofile".
 * 
 * The optional "format" parameter can be used to select
 * the format. Only the following formats are currently
 * permitted:
 * 
 * "newc"
 * New (SVR4) portable format. This format happens to
 * be compatible with the cpio-like format used by the
 * Linux kernel for initramfs.
 * 
 * This is the default format.
 * 
 * "crc"
 * New (SVR4) portable format with a checksum.
 * 
 * Optional arguments are supplied in the final hash
 * parameter, which is a hash of the argument name to its
 * value. Pass an empty {} for no optional arguments.
 *
 *
 * [Since] Added in version 1.27.9.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_cpio_out}[http://libguestfs.org/guestfs.3.html#guestfs_cpio_out].
 */
VALUE
guestfs_int_ruby_cpio_out (int argc, VALUE *argv, VALUE gv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "cpio_out");

  if (argc < 2 || argc > 3)
    rb_raise (rb_eArgError, "expecting 2 or 3 arguments");

  volatile VALUE directoryv = argv[0];
  volatile VALUE cpiofilev = argv[1];
  volatile VALUE optargsv = argc > 2 ? argv[2] : rb_hash_new ();

  const char *directory = StringValueCStr (directoryv);
  const char *cpiofile = StringValueCStr (cpiofilev);

  Check_Type (optargsv, T_HASH);
  struct guestfs_cpio_out_argv optargs_s = { .bitmask = 0 };
  struct guestfs_cpio_out_argv *optargs = &optargs_s;
  volatile VALUE v;
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("format")));
  if (v != Qnil) {
    optargs_s.format = StringValueCStr (v);
    optargs_s.bitmask |= GUESTFS_CPIO_OUT_FORMAT_BITMASK;
  }

  int r;

  r = guestfs_cpio_out_argv (g, directory, cpiofile, optargs);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.disk_virtual_size(filename) -> fixnum
 *
 * return virtual size of a disk
 *
 * Detect and return the virtual size in bytes of the disk
 * image called filename.
 * 
 * Note that detecting disk features can be insecure under
 * some circumstances. See "CVE-2010-3851" in guestfs(3).
 *
 *
 * [Since] Added in version 1.19.39.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_disk_virtual_size}[http://libguestfs.org/guestfs.3.html#guestfs_disk_virtual_size].
 */
VALUE
guestfs_int_ruby_disk_virtual_size (VALUE gv, VALUE filenamev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "disk_virtual_size");

  const char *filename = StringValueCStr (filenamev);

  int64_t r;

  r = guestfs_disk_virtual_size (g, filename);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return ULL2NUM (r);
}

/*
 * call-seq:
 *   g.download(remotefilename, filename) -> nil
 *
 * download a file to the local machine
 *
 * Download file remotefilename and save it as filename on
 * the local machine.
 * 
 * filename can also be a named pipe.
 * 
 * See also "g.upload", "g.cat".
 *
 *
 * [Since] Added in version 1.0.2.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_download}[http://libguestfs.org/guestfs.3.html#guestfs_download].
 */
VALUE
guestfs_int_ruby_download (VALUE gv, VALUE remotefilenamev, VALUE filenamev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "download");

  const char *remotefilename = StringValueCStr (remotefilenamev);
  const char *filename = StringValueCStr (filenamev);

  int r;

  r = guestfs_download (g, remotefilename, filename);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.feature_available(groups) -> [True|False]
 *
 * test availability of some parts of the API
 *
 * This is the same as "g.available", but unlike that call
 * it returns a simple true/false boolean result, instead
 * of throwing an exception if a feature is not found. For
 * other documentation see "g.available".
 *
 *
 * [Since] Added in version 1.21.26.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_feature_available}[http://libguestfs.org/guestfs.3.html#guestfs_feature_available].
 */
VALUE
guestfs_int_ruby_feature_available (VALUE gv, VALUE groupsv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "feature_available");

  char **groups;
  Check_Type (groupsv, T_ARRAY);
  {
    size_t i, len;
    len = RARRAY_LEN (groupsv);
    groups = ALLOC_N (char *, len+1);
    for (i = 0; i < len; ++i) {
      volatile VALUE v = rb_ary_entry (groupsv, i);
      groups[i] = StringValueCStr (v);
    }
    groups[len] = NULL;
  }

  int r;

  r = guestfs_feature_available (g, groups);
  free (groups);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return INT2NUM (r);
}

/*
 * call-seq:
 *   g.fill_pattern(pattern, len, path) -> nil
 *
 * fill a file with a repeating pattern of bytes
 *
 * This function is like "g.fill" except that it creates a
 * new file of length "len" containing the repeating
 * pattern of bytes in "pattern". The pattern is truncated
 * if necessary to ensure the length of the file is exactly
 * "len" bytes.
 *
 *
 * [Since] Added in version 1.3.12.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_fill_pattern}[http://libguestfs.org/guestfs.3.html#guestfs_fill_pattern].
 */
VALUE
guestfs_int_ruby_fill_pattern (VALUE gv, VALUE patternv, VALUE lenv, VALUE pathv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "fill_pattern");

  const char *pattern = StringValueCStr (patternv);
  int len = NUM2INT (lenv);
  const char *path = StringValueCStr (pathv);

  int r;

  r = guestfs_fill_pattern (g, pattern, len, path);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.find0(directory, files) -> nil
 *
 * find all files and directories, returning NUL-separated list
 *
 * This command lists out all files and directories,
 * recursively, starting at directory, placing the
 * resulting list in the external file called files.
 * 
 * This command works the same way as "g.find" with the
 * following exceptions:
 * 
 * *   The resulting list is written to an external file.
 * 
 * *   Items (filenames) in the result are separated by
 * "\0" characters. See find(1) option *-print0*.
 * 
 * *   The result list is not sorted.
 *
 *
 * [Since] Added in version 1.0.74.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_find0}[http://libguestfs.org/guestfs.3.html#guestfs_find0].
 */
VALUE
guestfs_int_ruby_find0 (VALUE gv, VALUE directoryv, VALUE filesv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "find0");

  const char *directory = StringValueCStr (directoryv);
  const char *files = StringValueCStr (filesv);

  int r;

  r = guestfs_find0 (g, directory, files);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.get_append() -> string
 *
 * get the additional kernel options
 *
 * Return the additional kernel options which are added to
 * the libguestfs appliance kernel command line.
 * 
 * If "NULL" then no options are added.
 *
 *
 * [Since] Added in version 1.0.26.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_get_append}[http://libguestfs.org/guestfs.3.html#guestfs_get_append].
 */
VALUE
guestfs_int_ruby_get_append (VALUE gv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "get_append");


  const char *r;

  r = guestfs_get_append (g);

  if (r)
    return rb_str_new2 (r);
  else
    return Qnil;
}

/*
 * call-seq:
 *   g.get_memsize() -> fixnum
 *
 * get memory allocated to the hypervisor
 *
 * This gets the memory size in megabytes allocated to the
 * hypervisor.
 * 
 * If "g.set_memsize" was not called on this handle, and if
 * "LIBGUESTFS_MEMSIZE" was not set, then this returns the
 * compiled-in default value for memsize.
 * 
 * For more information on the architecture of libguestfs,
 * see guestfs(3).
 *
 *
 * [Since] Added in version 1.0.55.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_get_memsize}[http://libguestfs.org/guestfs.3.html#guestfs_get_memsize].
 */
VALUE
guestfs_int_ruby_get_memsize (VALUE gv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "get_memsize");


  int r;

  r = guestfs_get_memsize (g);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return INT2NUM (r);
}

/*
 * call-seq:
 *   g.get_program() -> string
 *
 * get the program name
 *
 * Get the program name. See "g.set_program".
 *
 *
 * [Since] Added in version 1.21.29.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_get_program}[http://libguestfs.org/guestfs.3.html#guestfs_get_program].
 */
VALUE
guestfs_int_ruby_get_program (VALUE gv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "get_program");


  const char *r;

  r = guestfs_get_program (g);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return rb_str_new2 (r);
}

/*
 * call-seq:
 *   g.head_n(nrlines, path) -> list
 *
 * return first N lines of a file
 *
 * If the parameter "nrlines" is a positive number, this
 * returns the first "nrlines" lines of the file "path".
 * 
 * If the parameter "nrlines" is a negative number, this
 * returns lines from the file "path", excluding the last
 * "nrlines" lines.
 * 
 * If the parameter "nrlines" is zero, this returns an
 * empty list.
 * 
 * Because of the message protocol, there is a transfer
 * limit of somewhere between 2MB and 4MB. See "PROTOCOL
 * LIMITS" in guestfs(3).
 *
 *
 * [Since] Added in version 1.0.54.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_head_n}[http://libguestfs.org/guestfs.3.html#guestfs_head_n].
 */
VALUE
guestfs_int_ruby_head_n (VALUE gv, VALUE nrlinesv, VALUE pathv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "head_n");

  int nrlines = NUM2INT (nrlinesv);
  const char *path = StringValueCStr (pathv);

  char **r;

  r = guestfs_head_n (g, nrlines, path);
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
 *   g.hivex_commit(filename) -> nil
 *
 * commit (write) changes back to the hive
 *
 * Commit (write) changes to the hive.
 * 
 * If the optional filename parameter is null, then the
 * changes are written back to the same hive that was
 * opened. If this is not null then they are written to the
 * alternate filename given and the original hive is left
 * untouched.
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
 *         {guestfs_hivex_commit}[http://libguestfs.org/guestfs.3.html#guestfs_hivex_commit].
 */
VALUE
guestfs_int_ruby_hivex_commit (VALUE gv, VALUE filenamev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "hivex_commit");

  const char *filename = !NIL_P (filenamev) ? StringValueCStr (filenamev) : NULL;

  int r;

  r = guestfs_hivex_commit (g, filename);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.hivex_node_delete_child(nodeh) -> nil
 *
 * delete a node (recursively)
 *
 * Delete "nodeh", recursively if necessary.
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
 *         {guestfs_hivex_node_delete_child}[http://libguestfs.org/guestfs.3.html#guestfs_hivex_node_delete_child].
 */
VALUE
guestfs_int_ruby_hivex_node_delete_child (VALUE gv, VALUE nodehv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "hivex_node_delete_child");

  long long nodeh = NUM2LL (nodehv);

  int r;

  r = guestfs_hivex_node_delete_child (g, nodeh);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.initrd_cat(initrdpath, filename) -> string
 *
 * list the contents of a single file in an initrd
 *
 * This command unpacks the file filename from the initrd
 * file called initrdpath. The filename must be given
 * *without* the initial / character.
 * 
 * For example, in guestfish you could use the following
 * command to examine the boot script (usually called
 * /init) contained in a Linux initrd or initramfs image:
 * 
 * initrd-cat /boot/initrd-<version>.img init
 * 
 * See also "g.initrd_list".
 * 
 * Because of the message protocol, there is a transfer
 * limit of somewhere between 2MB and 4MB. See "PROTOCOL
 * LIMITS" in guestfs(3).
 *
 *
 * [Since] Added in version 1.0.84.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_initrd_cat}[http://libguestfs.org/guestfs.3.html#guestfs_initrd_cat].
 */
VALUE
guestfs_int_ruby_initrd_cat (VALUE gv, VALUE initrdpathv, VALUE filenamev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "initrd_cat");

  const char *initrdpath = StringValueCStr (initrdpathv);
  const char *filename = StringValueCStr (filenamev);

  char *r;
  size_t size;

  r = guestfs_initrd_cat (g, initrdpath, filename, &size);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  volatile VALUE rv = rb_str_new (r, size);
  free (r);
  return rv;
}

/*
 * call-seq:
 *   g.inotify_close() -> nil
 *
 * close the inotify handle
 *
 * This closes the inotify handle which was previously
 * opened by inotify_init. It removes all watches, throws
 * away any pending events, and deallocates all resources.
 *
 *
 * [Since] Added in version 1.0.66.
 *
 * [Feature] This function depends on the feature +inotify+.  See also {#feature_available}[rdoc-ref:feature_available].
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_inotify_close}[http://libguestfs.org/guestfs.3.html#guestfs_inotify_close].
 */
VALUE
guestfs_int_ruby_inotify_close (VALUE gv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "inotify_close");


  int r;

  r = guestfs_inotify_close (g);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.inspect_get_major_version(root) -> fixnum
 *
 * get major version of inspected operating system
 *
 * This returns the major version number of the inspected
 * operating system.
 * 
 * Windows uses a consistent versioning scheme which is
 * *not* reflected in the popular public names used by the
 * operating system. Notably the operating system known as
 * "Windows 7" is really version 6.1 (ie. major = 6, minor
 * = 1). You can find out the real versions corresponding
 * to releases of Windows by consulting Wikipedia or MSDN.
 * 
 * If the version could not be determined, then 0 is
 * returned.
 * 
 * Please read "INSPECTION" in guestfs(3) for more details.
 *
 *
 * [Since] Added in version 1.5.3.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_inspect_get_major_version}[http://libguestfs.org/guestfs.3.html#guestfs_inspect_get_major_version].
 */
VALUE
guestfs_int_ruby_inspect_get_major_version (VALUE gv, VALUE rootv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "inspect_get_major_version");

  const char *root = StringValueCStr (rootv);

  int r;

  r = guestfs_inspect_get_major_version (g, root);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return INT2NUM (r);
}

/*
 * call-seq:
 *   g.inspect_get_roots() -> list
 *
 * return list of operating systems found by last inspection
 *
 * This function is a convenient way to get the list of
 * root devices, as returned from a previous call to
 * "g.inspect_os", but without redoing the whole inspection
 * process.
 * 
 * This returns an empty list if either no root devices
 * were found or the caller has not called "g.inspect_os".
 * 
 * Please read "INSPECTION" in guestfs(3) for more details.
 *
 *
 * [Since] Added in version 1.7.3.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_inspect_get_roots}[http://libguestfs.org/guestfs.3.html#guestfs_inspect_get_roots].
 */
VALUE
guestfs_int_ruby_inspect_get_roots (VALUE gv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "inspect_get_roots");


  char **r;

  r = guestfs_inspect_get_roots (g);
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
 *   g.internal_test
 *
 * :nodoc:
 */
VALUE
guestfs_int_ruby_internal_test (int argc, VALUE *argv, VALUE gv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "internal_test");

  if (argc < 9 || argc > 10)
    rb_raise (rb_eArgError, "expecting 9 or 10 arguments");

  volatile VALUE strv = argv[0];
  volatile VALUE optstrv = argv[1];
  volatile VALUE strlistv = argv[2];
  volatile VALUE bv = argv[3];
  volatile VALUE integerv = argv[4];
  volatile VALUE integer64v = argv[5];
  volatile VALUE fileinv = argv[6];
  volatile VALUE fileoutv = argv[7];
  volatile VALUE bufferinv = argv[8];
  volatile VALUE optargsv = argc > 9 ? argv[9] : rb_hash_new ();

  const char *str = StringValueCStr (strv);
  const char *optstr = !NIL_P (optstrv) ? StringValueCStr (optstrv) : NULL;
  char **strlist;
  Check_Type (strlistv, T_ARRAY);
  {
    size_t i, len;
    len = RARRAY_LEN (strlistv);
    strlist = ALLOC_N (char *, len+1);
    for (i = 0; i < len; ++i) {
      volatile VALUE v = rb_ary_entry (strlistv, i);
      strlist[i] = StringValueCStr (v);
    }
    strlist[len] = NULL;
  }
  int b = RTEST (bv);
  int integer = NUM2INT (integerv);
  long long integer64 = NUM2LL (integer64v);
  const char *filein = StringValueCStr (fileinv);
  const char *fileout = StringValueCStr (fileoutv);
  Check_Type (bufferinv, T_STRING);
  const char *bufferin = RSTRING_PTR (bufferinv);
  if (!bufferin)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "bufferin", "internal_test");
  size_t bufferin_size = RSTRING_LEN (bufferinv);

  Check_Type (optargsv, T_HASH);
  struct guestfs_internal_test_argv optargs_s = { .bitmask = 0 };
  struct guestfs_internal_test_argv *optargs = &optargs_s;
  volatile VALUE v;
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("obool")));
  if (v != Qnil) {
    optargs_s.obool = RTEST (v);
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_OBOOL_BITMASK;
  }
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("oint")));
  if (v != Qnil) {
    optargs_s.oint = NUM2INT (v);
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_OINT_BITMASK;
  }
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("oint64")));
  if (v != Qnil) {
    optargs_s.oint64 = NUM2LL (v);
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_OINT64_BITMASK;
  }
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("ostring")));
  if (v != Qnil) {
    optargs_s.ostring = StringValueCStr (v);
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_OSTRING_BITMASK;
  }
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("ostringlist")));
  if (v != Qnil) {
  Check_Type (v, T_ARRAY);
  {
    size_t i, len;
    char **r;

    len = RARRAY_LEN (v);
    r = ALLOC_N (char *, len+1);
    for (i = 0; i < len; ++i) {
      volatile VALUE sv = rb_ary_entry (v, i);
      r[i] = StringValueCStr (sv);
    }
    r[len] = NULL;
    optargs_s.ostringlist = r;
  }
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_OSTRINGLIST_BITMASK;
  }

  int r;

  r = guestfs_internal_test_argv (g, str, optstr, strlist, b, integer, integer64, filein, fileout, bufferin, bufferin_size, optargs);
  free (strlist);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.internal_test_63_optargs
 *
 * :nodoc:
 */
VALUE
guestfs_int_ruby_internal_test_63_optargs (int argc, VALUE *argv, VALUE gv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "internal_test_63_optargs");

  if (argc < 0 || argc > 1)
    rb_raise (rb_eArgError, "expecting 0 or 1 arguments");

  volatile VALUE optargsv = argc > 0 ? argv[0] : rb_hash_new ();


  Check_Type (optargsv, T_HASH);
  struct guestfs_internal_test_63_optargs_argv optargs_s = { .bitmask = 0 };
  struct guestfs_internal_test_63_optargs_argv *optargs = &optargs_s;
  volatile VALUE v;
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("opt1")));
  if (v != Qnil) {
    optargs_s.opt1 = NUM2INT (v);
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT1_BITMASK;
  }
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("opt2")));
  if (v != Qnil) {
    optargs_s.opt2 = NUM2INT (v);
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT2_BITMASK;
  }
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("opt3")));
  if (v != Qnil) {
    optargs_s.opt3 = NUM2INT (v);
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT3_BITMASK;
  }
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("opt4")));
  if (v != Qnil) {
    optargs_s.opt4 = NUM2INT (v);
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT4_BITMASK;
  }
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("opt5")));
  if (v != Qnil) {
    optargs_s.opt5 = NUM2INT (v);
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT5_BITMASK;
  }
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("opt6")));
  if (v != Qnil) {
    optargs_s.opt6 = NUM2INT (v);
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT6_BITMASK;
  }
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("opt7")));
  if (v != Qnil) {
    optargs_s.opt7 = NUM2INT (v);
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT7_BITMASK;
  }
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("opt8")));
  if (v != Qnil) {
    optargs_s.opt8 = NUM2INT (v);
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT8_BITMASK;
  }
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("opt9")));
  if (v != Qnil) {
    optargs_s.opt9 = NUM2INT (v);
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT9_BITMASK;
  }
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("opt10")));
  if (v != Qnil) {
    optargs_s.opt10 = NUM2INT (v);
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT10_BITMASK;
  }
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("opt11")));
  if (v != Qnil) {
    optargs_s.opt11 = NUM2INT (v);
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT11_BITMASK;
  }
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("opt12")));
  if (v != Qnil) {
    optargs_s.opt12 = NUM2INT (v);
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT12_BITMASK;
  }
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("opt13")));
  if (v != Qnil) {
    optargs_s.opt13 = NUM2INT (v);
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT13_BITMASK;
  }
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("opt14")));
  if (v != Qnil) {
    optargs_s.opt14 = NUM2INT (v);
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT14_BITMASK;
  }
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("opt15")));
  if (v != Qnil) {
    optargs_s.opt15 = NUM2INT (v);
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT15_BITMASK;
  }
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("opt16")));
  if (v != Qnil) {
    optargs_s.opt16 = NUM2INT (v);
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT16_BITMASK;
  }
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("opt17")));
  if (v != Qnil) {
    optargs_s.opt17 = NUM2INT (v);
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT17_BITMASK;
  }
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("opt18")));
  if (v != Qnil) {
    optargs_s.opt18 = NUM2INT (v);
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT18_BITMASK;
  }
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("opt19")));
  if (v != Qnil) {
    optargs_s.opt19 = NUM2INT (v);
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT19_BITMASK;
  }
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("opt20")));
  if (v != Qnil) {
    optargs_s.opt20 = NUM2INT (v);
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT20_BITMASK;
  }
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("opt21")));
  if (v != Qnil) {
    optargs_s.opt21 = NUM2INT (v);
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT21_BITMASK;
  }
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("opt22")));
  if (v != Qnil) {
    optargs_s.opt22 = NUM2INT (v);
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT22_BITMASK;
  }
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("opt23")));
  if (v != Qnil) {
    optargs_s.opt23 = NUM2INT (v);
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT23_BITMASK;
  }
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("opt24")));
  if (v != Qnil) {
    optargs_s.opt24 = NUM2INT (v);
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT24_BITMASK;
  }
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("opt25")));
  if (v != Qnil) {
    optargs_s.opt25 = NUM2INT (v);
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT25_BITMASK;
  }
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("opt26")));
  if (v != Qnil) {
    optargs_s.opt26 = NUM2INT (v);
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT26_BITMASK;
  }
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("opt27")));
  if (v != Qnil) {
    optargs_s.opt27 = NUM2INT (v);
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT27_BITMASK;
  }
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("opt28")));
  if (v != Qnil) {
    optargs_s.opt28 = NUM2INT (v);
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT28_BITMASK;
  }
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("opt29")));
  if (v != Qnil) {
    optargs_s.opt29 = NUM2INT (v);
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT29_BITMASK;
  }
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("opt30")));
  if (v != Qnil) {
    optargs_s.opt30 = NUM2INT (v);
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT30_BITMASK;
  }
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("opt31")));
  if (v != Qnil) {
    optargs_s.opt31 = NUM2INT (v);
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT31_BITMASK;
  }
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("opt32")));
  if (v != Qnil) {
    optargs_s.opt32 = NUM2INT (v);
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT32_BITMASK;
  }
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("opt33")));
  if (v != Qnil) {
    optargs_s.opt33 = NUM2INT (v);
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT33_BITMASK;
  }
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("opt34")));
  if (v != Qnil) {
    optargs_s.opt34 = NUM2INT (v);
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT34_BITMASK;
  }
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("opt35")));
  if (v != Qnil) {
    optargs_s.opt35 = NUM2INT (v);
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT35_BITMASK;
  }
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("opt36")));
  if (v != Qnil) {
    optargs_s.opt36 = NUM2INT (v);
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT36_BITMASK;
  }
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("opt37")));
  if (v != Qnil) {
    optargs_s.opt37 = NUM2INT (v);
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT37_BITMASK;
  }
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("opt38")));
  if (v != Qnil) {
    optargs_s.opt38 = NUM2INT (v);
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT38_BITMASK;
  }
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("opt39")));
  if (v != Qnil) {
    optargs_s.opt39 = NUM2INT (v);
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT39_BITMASK;
  }
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("opt40")));
  if (v != Qnil) {
    optargs_s.opt40 = NUM2INT (v);
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT40_BITMASK;
  }
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("opt41")));
  if (v != Qnil) {
    optargs_s.opt41 = NUM2INT (v);
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT41_BITMASK;
  }
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("opt42")));
  if (v != Qnil) {
    optargs_s.opt42 = NUM2INT (v);
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT42_BITMASK;
  }
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("opt43")));
  if (v != Qnil) {
    optargs_s.opt43 = NUM2INT (v);
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT43_BITMASK;
  }
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("opt44")));
  if (v != Qnil) {
    optargs_s.opt44 = NUM2INT (v);
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT44_BITMASK;
  }
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("opt45")));
  if (v != Qnil) {
    optargs_s.opt45 = NUM2INT (v);
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT45_BITMASK;
  }
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("opt46")));
  if (v != Qnil) {
    optargs_s.opt46 = NUM2INT (v);
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT46_BITMASK;
  }
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("opt47")));
  if (v != Qnil) {
    optargs_s.opt47 = NUM2INT (v);
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT47_BITMASK;
  }
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("opt48")));
  if (v != Qnil) {
    optargs_s.opt48 = NUM2INT (v);
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT48_BITMASK;
  }
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("opt49")));
  if (v != Qnil) {
    optargs_s.opt49 = NUM2INT (v);
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT49_BITMASK;
  }
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("opt50")));
  if (v != Qnil) {
    optargs_s.opt50 = NUM2INT (v);
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT50_BITMASK;
  }
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("opt51")));
  if (v != Qnil) {
    optargs_s.opt51 = NUM2INT (v);
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT51_BITMASK;
  }
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("opt52")));
  if (v != Qnil) {
    optargs_s.opt52 = NUM2INT (v);
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT52_BITMASK;
  }
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("opt53")));
  if (v != Qnil) {
    optargs_s.opt53 = NUM2INT (v);
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT53_BITMASK;
  }
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("opt54")));
  if (v != Qnil) {
    optargs_s.opt54 = NUM2INT (v);
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT54_BITMASK;
  }
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("opt55")));
  if (v != Qnil) {
    optargs_s.opt55 = NUM2INT (v);
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT55_BITMASK;
  }
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("opt56")));
  if (v != Qnil) {
    optargs_s.opt56 = NUM2INT (v);
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT56_BITMASK;
  }
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("opt57")));
  if (v != Qnil) {
    optargs_s.opt57 = NUM2INT (v);
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT57_BITMASK;
  }
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("opt58")));
  if (v != Qnil) {
    optargs_s.opt58 = NUM2INT (v);
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT58_BITMASK;
  }
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("opt59")));
  if (v != Qnil) {
    optargs_s.opt59 = NUM2INT (v);
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT59_BITMASK;
  }
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("opt60")));
  if (v != Qnil) {
    optargs_s.opt60 = NUM2INT (v);
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT60_BITMASK;
  }
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("opt61")));
  if (v != Qnil) {
    optargs_s.opt61 = NUM2INT (v);
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT61_BITMASK;
  }
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("opt62")));
  if (v != Qnil) {
    optargs_s.opt62 = NUM2INT (v);
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT62_BITMASK;
  }
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("opt63")));
  if (v != Qnil) {
    optargs_s.opt63 = NUM2INT (v);
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT63_BITMASK;
  }

  int r;

  r = guestfs_internal_test_63_optargs_argv (g, optargs);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.internal_test_rhashtableerr
 *
 * :nodoc:
 */
VALUE
guestfs_int_ruby_internal_test_rhashtableerr (VALUE gv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "internal_test_rhashtableerr");


  char **r;

  r = guestfs_internal_test_rhashtableerr (g);
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
 *   g.is_blockdev(path, {optargs...}) -> [True|False]
 *
 * test if block device
 *
 * This returns "true" if and only if there is a block
 * device with the given "path" name.
 * 
 * If the optional flag "followsymlinks" is true, then a
 * symlink (or chain of symlinks) that ends with a block
 * device also causes the function to return true.
 * 
 * This call only looks at files within the guest
 * filesystem. Libguestfs partitions and block devices (eg.
 * /dev/sda) cannot be used as the "path" parameter of this
 * call.
 * 
 * See also "g.stat".
 * 
 * Optional arguments are supplied in the final hash
 * parameter, which is a hash of the argument name to its
 * value. Pass an empty {} for no optional arguments.
 *
 *
 * [Since] Added in version 1.5.10.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_is_blockdev}[http://libguestfs.org/guestfs.3.html#guestfs_is_blockdev].
 */
VALUE
guestfs_int_ruby_is_blockdev (int argc, VALUE *argv, VALUE gv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "is_blockdev");

  if (argc < 1 || argc > 2)
    rb_raise (rb_eArgError, "expecting 1 or 2 arguments");

  volatile VALUE pathv = argv[0];
  volatile VALUE optargsv = argc > 1 ? argv[1] : rb_hash_new ();

  const char *path = StringValueCStr (pathv);

  Check_Type (optargsv, T_HASH);
  struct guestfs_is_blockdev_opts_argv optargs_s = { .bitmask = 0 };
  struct guestfs_is_blockdev_opts_argv *optargs = &optargs_s;
  volatile VALUE v;
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("followsymlinks")));
  if (v != Qnil) {
    optargs_s.followsymlinks = RTEST (v);
    optargs_s.bitmask |= GUESTFS_IS_BLOCKDEV_OPTS_FOLLOWSYMLINKS_BITMASK;
  }

  int r;

  r = guestfs_is_blockdev_opts_argv (g, path, optargs);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return INT2NUM (r);
}

/*
 * call-seq:
 *   g.is_config() -> [True|False]
 *
 * is in configuration state
 *
 * This returns true iff this handle is being configured
 * (in the "CONFIG" state).
 * 
 * For more information on states, see guestfs(3).
 *
 *
 * [Since] Added in version 1.0.2.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_is_config}[http://libguestfs.org/guestfs.3.html#guestfs_is_config].
 */
VALUE
guestfs_int_ruby_is_config (VALUE gv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "is_config");


  int r;

  r = guestfs_is_config (g);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return INT2NUM (r);
}

/*
 * call-seq:
 *   g.is_fifo(path, {optargs...}) -> [True|False]
 *
 * test if FIFO (named pipe)
 *
 * This returns "true" if and only if there is a FIFO
 * (named pipe) with the given "path" name.
 * 
 * If the optional flag "followsymlinks" is true, then a
 * symlink (or chain of symlinks) that ends with a FIFO
 * also causes the function to return true.
 * 
 * See also "g.stat".
 * 
 * Optional arguments are supplied in the final hash
 * parameter, which is a hash of the argument name to its
 * value. Pass an empty {} for no optional arguments.
 *
 *
 * [Since] Added in version 1.5.10.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_is_fifo}[http://libguestfs.org/guestfs.3.html#guestfs_is_fifo].
 */
VALUE
guestfs_int_ruby_is_fifo (int argc, VALUE *argv, VALUE gv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "is_fifo");

  if (argc < 1 || argc > 2)
    rb_raise (rb_eArgError, "expecting 1 or 2 arguments");

  volatile VALUE pathv = argv[0];
  volatile VALUE optargsv = argc > 1 ? argv[1] : rb_hash_new ();

  const char *path = StringValueCStr (pathv);

  Check_Type (optargsv, T_HASH);
  struct guestfs_is_fifo_opts_argv optargs_s = { .bitmask = 0 };
  struct guestfs_is_fifo_opts_argv *optargs = &optargs_s;
  volatile VALUE v;
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("followsymlinks")));
  if (v != Qnil) {
    optargs_s.followsymlinks = RTEST (v);
    optargs_s.bitmask |= GUESTFS_IS_FIFO_OPTS_FOLLOWSYMLINKS_BITMASK;
  }

  int r;

  r = guestfs_is_fifo_opts_argv (g, path, optargs);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return INT2NUM (r);
}

/*
 * call-seq:
 *   g.isoinfo_device(device) -> hash
 *
 * get ISO information from primary volume descriptor of device
 *
 * "device" is an ISO device. This returns a struct of
 * information read from the primary volume descriptor (the
 * ISO equivalent of the superblock) of the device.
 * 
 * Usually it is more efficient to use the isoinfo(1)
 * command with the *-d* option on the host to analyze ISO
 * files, instead of going through libguestfs.
 * 
 * For information on the primary volume descriptor fields,
 * see
 * <http://wiki.osdev.org/ISO_9660#The_Primary_Volume_Descr
 * iptor>
 *
 *
 * [Since] Added in version 1.17.19.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_isoinfo_device}[http://libguestfs.org/guestfs.3.html#guestfs_isoinfo_device].
 */
VALUE
guestfs_int_ruby_isoinfo_device (VALUE gv, VALUE devicev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "isoinfo_device");

  const char *device = StringValueCStr (devicev);

  struct guestfs_isoinfo *r;

  r = guestfs_isoinfo_device (g, device);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  volatile VALUE rv = rb_hash_new ();
  rb_hash_aset (rv, rb_str_new2 ("iso_system_id"), rb_str_new2 (r->iso_system_id));
  rb_hash_aset (rv, rb_str_new2 ("iso_volume_id"), rb_str_new2 (r->iso_volume_id));
  rb_hash_aset (rv, rb_str_new2 ("iso_volume_space_size"), UINT2NUM (r->iso_volume_space_size));
  rb_hash_aset (rv, rb_str_new2 ("iso_volume_set_size"), UINT2NUM (r->iso_volume_set_size));
  rb_hash_aset (rv, rb_str_new2 ("iso_volume_sequence_number"), UINT2NUM (r->iso_volume_sequence_number));
  rb_hash_aset (rv, rb_str_new2 ("iso_logical_block_size"), UINT2NUM (r->iso_logical_block_size));
  rb_hash_aset (rv, rb_str_new2 ("iso_volume_set_id"), rb_str_new2 (r->iso_volume_set_id));
  rb_hash_aset (rv, rb_str_new2 ("iso_publisher_id"), rb_str_new2 (r->iso_publisher_id));
  rb_hash_aset (rv, rb_str_new2 ("iso_data_preparer_id"), rb_str_new2 (r->iso_data_preparer_id));
  rb_hash_aset (rv, rb_str_new2 ("iso_application_id"), rb_str_new2 (r->iso_application_id));
  rb_hash_aset (rv, rb_str_new2 ("iso_copyright_file_id"), rb_str_new2 (r->iso_copyright_file_id));
  rb_hash_aset (rv, rb_str_new2 ("iso_abstract_file_id"), rb_str_new2 (r->iso_abstract_file_id));
  rb_hash_aset (rv, rb_str_new2 ("iso_bibliographic_file_id"), rb_str_new2 (r->iso_bibliographic_file_id));
  rb_hash_aset (rv, rb_str_new2 ("iso_volume_creation_t"), LL2NUM (r->iso_volume_creation_t));
  rb_hash_aset (rv, rb_str_new2 ("iso_volume_modification_t"), LL2NUM (r->iso_volume_modification_t));
  rb_hash_aset (rv, rb_str_new2 ("iso_volume_expiration_t"), LL2NUM (r->iso_volume_expiration_t));
  rb_hash_aset (rv, rb_str_new2 ("iso_volume_effective_t"), LL2NUM (r->iso_volume_effective_t));
  guestfs_free_isoinfo (r);
  return rv;
}

/*
 * call-seq:
 *   g.journal_next() -> [True|False]
 *
 * move to the next journal entry
 *
 * Move to the next journal entry. You have to call this at
 * least once after opening the handle before you are able
 * to read data.
 * 
 * The returned boolean tells you if there are any more
 * journal records to read. "true" means you can read the
 * next record (eg. using "g.journal_get"), and "false"
 * means you have reached the end of the journal.
 *
 *
 * [Since] Added in version 1.23.11.
 *
 * [Feature] This function depends on the feature +journal+.  See also {#feature_available}[rdoc-ref:feature_available].
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_journal_next}[http://libguestfs.org/guestfs.3.html#guestfs_journal_next].
 */
VALUE
guestfs_int_ruby_journal_next (VALUE gv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "journal_next");


  int r;

  r = guestfs_journal_next (g);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return INT2NUM (r);
}

/*
 * call-seq:
 *   g.journal_skip(skip) -> fixnum
 *
 * skip forwards or backwards in the journal
 *
 * Skip forwards ("skip ≥ 0") or backwards ("skip < 0") in
 * the journal.
 * 
 * The number of entries actually skipped is returned (note
 * "rskip ≥ 0"). If this is not the same as the absolute
 * value of the skip parameter ("|skip|") you passed in
 * then it means you have reached the end or the start of
 * the journal.
 *
 *
 * [Since] Added in version 1.23.11.
 *
 * [Feature] This function depends on the feature +journal+.  See also {#feature_available}[rdoc-ref:feature_available].
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_journal_skip}[http://libguestfs.org/guestfs.3.html#guestfs_journal_skip].
 */
VALUE
guestfs_int_ruby_journal_skip (VALUE gv, VALUE skipv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "journal_skip");

  long long skip = NUM2LL (skipv);

  int64_t r;

  r = guestfs_journal_skip (g, skip);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return ULL2NUM (r);
}

/*
 * call-seq:
 *   g.ldmtool_volume_partitions(diskgroup, volume) -> list
 *
 * return the partitions in a Windows dynamic disk volume
 *
 * Return the list of partitions in the volume named
 * "volume" in the disk group with GUID "diskgroup".
 *
 *
 * [Since] Added in version 1.20.0.
 *
 * [Feature] This function depends on the feature +ldm+.  See also {#feature_available}[rdoc-ref:feature_available].
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_ldmtool_volume_partitions}[http://libguestfs.org/guestfs.3.html#guestfs_ldmtool_volume_partitions].
 */
VALUE
guestfs_int_ruby_ldmtool_volume_partitions (VALUE gv, VALUE diskgroupv, VALUE volumev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "ldmtool_volume_partitions");

  const char *diskgroup = StringValueCStr (diskgroupv);
  const char *volume = StringValueCStr (volumev);

  char **r;

  r = guestfs_ldmtool_volume_partitions (g, diskgroup, volume);
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
 *   g.list_disk_labels() -> hash
 *
 * mapping of disk labels to devices
 *
 * If you add drives using the optional "label" parameter
 * of "g.add_drive_opts", you can use this call to map
 * between disk labels, and raw block device and partition
 * names (like /dev/sda and /dev/sda1).
 * 
 * This returns a hashtable, where keys are the disk labels
 * (*without* the /dev/disk/guestfs prefix), and the values
 * are the full raw block device and partition names (eg.
 * /dev/sda and /dev/sda1).
 *
 *
 * [Since] Added in version 1.19.49.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_list_disk_labels}[http://libguestfs.org/guestfs.3.html#guestfs_list_disk_labels].
 */
VALUE
guestfs_int_ruby_list_disk_labels (VALUE gv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "list_disk_labels");


  char **r;

  r = guestfs_list_disk_labels (g);
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
 *   g.list_md_devices() -> list
 *
 * list Linux md (RAID) devices
 *
 * List all Linux md devices.
 *
 *
 * [Since] Added in version 1.15.4.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_list_md_devices}[http://libguestfs.org/guestfs.3.html#guestfs_list_md_devices].
 */
VALUE
guestfs_int_ruby_list_md_devices (VALUE gv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "list_md_devices");


  char **r;

  r = guestfs_list_md_devices (g);
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
 *   g.ln(target, linkname) -> nil
 *
 * create a hard link
 *
 * This command creates a hard link using the "ln" command.
 *
 *
 * [Since] Added in version 1.0.66.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_ln}[http://libguestfs.org/guestfs.3.html#guestfs_ln].
 */
VALUE
guestfs_int_ruby_ln (VALUE gv, VALUE targetv, VALUE linknamev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "ln");

  const char *target = StringValueCStr (targetv);
  const char *linkname = StringValueCStr (linknamev);

  int r;

  r = guestfs_ln (g, target, linkname);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.ln_sf(target, linkname) -> nil
 *
 * create a symbolic link
 *
 * This command creates a symbolic link using the "ln -sf"
 * command, The *-f* option removes the link ("linkname")
 * if it exists already.
 *
 *
 * [Since] Added in version 1.0.66.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_ln_sf}[http://libguestfs.org/guestfs.3.html#guestfs_ln_sf].
 */
VALUE
guestfs_int_ruby_ln_sf (VALUE gv, VALUE targetv, VALUE linknamev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "ln_sf");

  const char *target = StringValueCStr (targetv);
  const char *linkname = StringValueCStr (linknamev);

  int r;

  r = guestfs_ln_sf (g, target, linkname);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.luks_add_key(device, key, newkey, keyslot) -> nil
 *
 * add a key on a LUKS encrypted device
 *
 * This command adds a new key on LUKS device "device".
 * "key" is any existing key, and is used to access the
 * device. "newkey" is the new key to add. "keyslot" is the
 * key slot that will be replaced.
 * 
 * Note that if "keyslot" already contains a key, then this
 * command will fail. You have to use "g.luks_kill_slot"
 * first to remove that key.
 *
 *
 * [Since] Added in version 1.5.2.
 *
 * [Feature] This function depends on the feature +luks+.  See also {#feature_available}[rdoc-ref:feature_available].
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_luks_add_key}[http://libguestfs.org/guestfs.3.html#guestfs_luks_add_key].
 */
VALUE
guestfs_int_ruby_luks_add_key (VALUE gv, VALUE devicev, VALUE keyv, VALUE newkeyv, VALUE keyslotv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "luks_add_key");

  const char *device = StringValueCStr (devicev);
  const char *key = StringValueCStr (keyv);
  const char *newkey = StringValueCStr (newkeyv);
  int keyslot = NUM2INT (keyslotv);

  int r;

  r = guestfs_luks_add_key (g, device, key, newkey, keyslot);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.lvcreate(logvol, volgroup, mbytes) -> nil
 *
 * create an LVM logical volume
 *
 * This creates an LVM logical volume called "logvol" on
 * the volume group "volgroup", with "size" megabytes.
 *
 *
 * [Since] Added in version 0.8.
 *
 * [Feature] This function depends on the feature +lvm2+.  See also {#feature_available}[rdoc-ref:feature_available].
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_lvcreate}[http://libguestfs.org/guestfs.3.html#guestfs_lvcreate].
 */
VALUE
guestfs_int_ruby_lvcreate (VALUE gv, VALUE logvolv, VALUE volgroupv, VALUE mbytesv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "lvcreate");

  const char *logvol = StringValueCStr (logvolv);
  const char *volgroup = StringValueCStr (volgroupv);
  int mbytes = NUM2INT (mbytesv);

  int r;

  r = guestfs_lvcreate (g, logvol, volgroup, mbytes);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.lvcreate_free(logvol, volgroup, percent) -> nil
 *
 * create an LVM logical volume in % remaining free space
 *
 * Create an LVM logical volume called
 * /dev/volgroup/logvol, using approximately "percent" % of
 * the free space remaining in the volume group. Most
 * usefully, when "percent" is 100 this will create the
 * largest possible LV.
 *
 *
 * [Since] Added in version 1.17.18.
 *
 * [Feature] This function depends on the feature +lvm2+.  See also {#feature_available}[rdoc-ref:feature_available].
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_lvcreate_free}[http://libguestfs.org/guestfs.3.html#guestfs_lvcreate_free].
 */
VALUE
guestfs_int_ruby_lvcreate_free (VALUE gv, VALUE logvolv, VALUE volgroupv, VALUE percentv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "lvcreate_free");

  const char *logvol = StringValueCStr (logvolv);
  const char *volgroup = StringValueCStr (volgroupv);
  int percent = NUM2INT (percentv);

  int r;

  r = guestfs_lvcreate_free (g, logvol, volgroup, percent);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.lvm_set_filter(devices) -> nil
 *
 * set LVM device filter
 *
 * This sets the LVM device filter so that LVM will only be
 * able to "see" the block devices in the list "devices",
 * and will ignore all other attached block devices.
 * 
 * Where disk image(s) contain duplicate PVs or VGs, this
 * command is useful to get LVM to ignore the duplicates,
 * otherwise LVM can get confused. Note also there are two
 * types of duplication possible: either cloned PVs/VGs
 * which have identical UUIDs; or VGs that are not cloned
 * but just happen to have the same name. In normal
 * operation you cannot create this situation, but you can
 * do it outside LVM, eg. by cloning disk images or by bit
 * twiddling inside the LVM metadata.
 * 
 * This command also clears the LVM cache and performs a
 * volume group scan.
 * 
 * You can filter whole block devices or individual
 * partitions.
 * 
 * You cannot use this if any VG is currently in use (eg.
 * contains a mounted filesystem), even if you are not
 * filtering out that VG.
 *
 *
 * [Since] Added in version 1.5.1.
 *
 * [Feature] This function depends on the feature +lvm2+.  See also {#feature_available}[rdoc-ref:feature_available].
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_lvm_set_filter}[http://libguestfs.org/guestfs.3.html#guestfs_lvm_set_filter].
 */
VALUE
guestfs_int_ruby_lvm_set_filter (VALUE gv, VALUE devicesv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "lvm_set_filter");

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

  int r;

  r = guestfs_lvm_set_filter (g, devices);
  free (devices);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.lvs_full() -> list
 *
 * list the LVM logical volumes (LVs)
 *
 * List all the logical volumes detected. This is the
 * equivalent of the lvs(8) command. The "full" version
 * includes all fields.
 *
 *
 * [Since] Added in version 0.4.
 *
 * [Feature] This function depends on the feature +lvm2+.  See also {#feature_available}[rdoc-ref:feature_available].
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_lvs_full}[http://libguestfs.org/guestfs.3.html#guestfs_lvs_full].
 */
VALUE
guestfs_int_ruby_lvs_full (VALUE gv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "lvs_full");


  struct guestfs_lvm_lv_list *r;

  r = guestfs_lvs_full (g);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  volatile VALUE rv = rb_ary_new2 (r->len);
  size_t i;
  for (i = 0; i < r->len; ++i) {
    volatile VALUE hv = rb_hash_new ();
    rb_hash_aset (hv, rb_str_new2 ("lv_name"), rb_str_new2 (r->val[i].lv_name));
    rb_hash_aset (hv, rb_str_new2 ("lv_uuid"), rb_str_new (r->val[i].lv_uuid, 32));
    rb_hash_aset (hv, rb_str_new2 ("lv_attr"), rb_str_new2 (r->val[i].lv_attr));
    rb_hash_aset (hv, rb_str_new2 ("lv_major"), LL2NUM (r->val[i].lv_major));
    rb_hash_aset (hv, rb_str_new2 ("lv_minor"), LL2NUM (r->val[i].lv_minor));
    rb_hash_aset (hv, rb_str_new2 ("lv_kernel_major"), LL2NUM (r->val[i].lv_kernel_major));
    rb_hash_aset (hv, rb_str_new2 ("lv_kernel_minor"), LL2NUM (r->val[i].lv_kernel_minor));
    rb_hash_aset (hv, rb_str_new2 ("lv_size"), ULL2NUM (r->val[i].lv_size));
    rb_hash_aset (hv, rb_str_new2 ("seg_count"), LL2NUM (r->val[i].seg_count));
    rb_hash_aset (hv, rb_str_new2 ("origin"), rb_str_new2 (r->val[i].origin));
    rb_hash_aset (hv, rb_str_new2 ("snap_percent"), rb_dbl2big (r->val[i].snap_percent));
    rb_hash_aset (hv, rb_str_new2 ("copy_percent"), rb_dbl2big (r->val[i].copy_percent));
    rb_hash_aset (hv, rb_str_new2 ("move_pv"), rb_str_new2 (r->val[i].move_pv));
    rb_hash_aset (hv, rb_str_new2 ("lv_tags"), rb_str_new2 (r->val[i].lv_tags));
    rb_hash_aset (hv, rb_str_new2 ("mirror_log"), rb_str_new2 (r->val[i].mirror_log));
    rb_hash_aset (hv, rb_str_new2 ("modules"), rb_str_new2 (r->val[i].modules));
    rb_ary_push (rv, hv);
  }
  guestfs_free_lvm_lv_list (r);
  return rv;
}

/*
 * call-seq:
 *   g.md_stat(md) -> list
 *
 * get underlying devices from an MD device
 *
 * This call returns a list of the underlying devices which
 * make up the single software RAID array device "md".
 * 
 * To get a list of software RAID devices, call
 * "g.list_md_devices".
 * 
 * Each structure returned corresponds to one device along
 * with additional status information:
 * 
 * "mdstat_device"
 * The name of the underlying device.
 * 
 * "mdstat_index"
 * The index of this device within the array.
 * 
 * "mdstat_flags"
 * Flags associated with this device. This is a string
 * containing (in no specific order) zero or more of
 * the following flags:
 * 
 * "W" write-mostly
 * 
 * "F" device is faulty
 * 
 * "S" device is a RAID spare
 * 
 * "R" replacement
 *
 *
 * [Since] Added in version 1.17.21.
 *
 * [Feature] This function depends on the feature +mdadm+.  See also {#feature_available}[rdoc-ref:feature_available].
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_md_stat}[http://libguestfs.org/guestfs.3.html#guestfs_md_stat].
 */
VALUE
guestfs_int_ruby_md_stat (VALUE gv, VALUE mdv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "md_stat");

  const char *md = StringValueCStr (mdv);

  struct guestfs_mdstat_list *r;

  r = guestfs_md_stat (g, md);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  volatile VALUE rv = rb_ary_new2 (r->len);
  size_t i;
  for (i = 0; i < r->len; ++i) {
    volatile VALUE hv = rb_hash_new ();
    rb_hash_aset (hv, rb_str_new2 ("mdstat_device"), rb_str_new2 (r->val[i].mdstat_device));
    rb_hash_aset (hv, rb_str_new2 ("mdstat_index"), INT2NUM (r->val[i].mdstat_index));
    rb_hash_aset (hv, rb_str_new2 ("mdstat_flags"), rb_str_new2 (r->val[i].mdstat_flags));
    rb_ary_push (rv, hv);
  }
  guestfs_free_mdstat_list (r);
  return rv;
}

/*
 * call-seq:
 *   g.mkfs(fstype, device, {optargs...}) -> nil
 *
 * make a filesystem
 *
 * This function creates a filesystem on "device". The
 * filesystem type is "fstype", for example "ext3".
 * 
 * The optional arguments are:
 * 
 * "blocksize"
 * The filesystem block size. Supported block sizes
 * depend on the filesystem type, but typically they
 * are 1024, 2048 or 4096 for Linux ext2/3 filesystems.
 * 
 * For VFAT and NTFS the "blocksize" parameter is
 * treated as the requested cluster size.
 * 
 * For UFS block sizes, please see mkfs.ufs(8).
 * 
 * "features"
 * This passes the *-O* parameter to the external mkfs
 * program.
 * 
 * For certain filesystem types, this allows extra
 * filesystem features to be selected. See mke2fs(8)
 * and mkfs.ufs(8) for more details.
 * 
 * You cannot use this optional parameter with the
 * "gfs" or "gfs2" filesystem type.
 * 
 * "inode"
 * This passes the *-I* parameter to the external
 * mke2fs(8) program which sets the inode size (only
 * for ext2/3/4 filesystems at present).
 * 
 * "sectorsize"
 * This passes the *-S* parameter to external
 * mkfs.ufs(8) program, which sets sector size for ufs
 * filesystem.
 * 
 * Optional arguments are supplied in the final hash
 * parameter, which is a hash of the argument name to its
 * value. Pass an empty {} for no optional arguments.
 *
 *
 * [Since] Added in version 0.8.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_mkfs}[http://libguestfs.org/guestfs.3.html#guestfs_mkfs].
 */
VALUE
guestfs_int_ruby_mkfs (int argc, VALUE *argv, VALUE gv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "mkfs");

  if (argc < 2 || argc > 3)
    rb_raise (rb_eArgError, "expecting 2 or 3 arguments");

  volatile VALUE fstypev = argv[0];
  volatile VALUE devicev = argv[1];
  volatile VALUE optargsv = argc > 2 ? argv[2] : rb_hash_new ();

  const char *fstype = StringValueCStr (fstypev);
  const char *device = StringValueCStr (devicev);

  Check_Type (optargsv, T_HASH);
  struct guestfs_mkfs_opts_argv optargs_s = { .bitmask = 0 };
  struct guestfs_mkfs_opts_argv *optargs = &optargs_s;
  volatile VALUE v;
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("blocksize")));
  if (v != Qnil) {
    optargs_s.blocksize = NUM2INT (v);
    optargs_s.bitmask |= GUESTFS_MKFS_OPTS_BLOCKSIZE_BITMASK;
  }
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("features")));
  if (v != Qnil) {
    optargs_s.features = StringValueCStr (v);
    optargs_s.bitmask |= GUESTFS_MKFS_OPTS_FEATURES_BITMASK;
  }
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("inode")));
  if (v != Qnil) {
    optargs_s.inode = NUM2INT (v);
    optargs_s.bitmask |= GUESTFS_MKFS_OPTS_INODE_BITMASK;
  }
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("sectorsize")));
  if (v != Qnil) {
    optargs_s.sectorsize = NUM2INT (v);
    optargs_s.bitmask |= GUESTFS_MKFS_OPTS_SECTORSIZE_BITMASK;
  }
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("label")));
  if (v != Qnil) {
    optargs_s.label = StringValueCStr (v);
    optargs_s.bitmask |= GUESTFS_MKFS_OPTS_LABEL_BITMASK;
  }

  int r;

  r = guestfs_mkfs_opts_argv (g, fstype, device, optargs);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.mkfs_b(fstype, blocksize, device) -> nil
 *
 * make a filesystem with block size
 *
 * This call is similar to "g.mkfs", but it allows you to
 * control the block size of the resulting filesystem.
 * Supported block sizes depend on the filesystem type, but
 * typically they are 1024, 2048 or 4096 only.
 * 
 * For VFAT and NTFS the "blocksize" parameter is treated
 * as the requested cluster size.
 *
 *
 * [Since] Added in version 1.0.68.
 *
 * [Deprecated] In new code, use rdoc-ref:mkfs instead.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_mkfs_b}[http://libguestfs.org/guestfs.3.html#guestfs_mkfs_b].
 */
VALUE
guestfs_int_ruby_mkfs_b (VALUE gv, VALUE fstypev, VALUE blocksizev, VALUE devicev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "mkfs_b");

  const char *fstype = StringValueCStr (fstypev);
  int blocksize = NUM2INT (blocksizev);
  const char *device = StringValueCStr (devicev);

  int r;

  r = guestfs_mkfs_b (g, fstype, blocksize, device);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.mkswap_U(uuid, device) -> nil
 *
 * create a swap partition with an explicit UUID
 *
 * Create a swap partition on "device" with UUID "uuid".
 *
 *
 * [Since] Added in version 1.0.55.
 *
 * [Deprecated] In new code, use rdoc-ref:mkswap instead.
 *
 * [Feature] This function depends on the feature +linuxfsuuid+.  See also {#feature_available}[rdoc-ref:feature_available].
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_mkswap_U}[http://libguestfs.org/guestfs.3.html#guestfs_mkswap_U].
 */
VALUE
guestfs_int_ruby_mkswap_U (VALUE gv, VALUE uuidv, VALUE devicev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "mkswap_U");

  const char *uuid = StringValueCStr (uuidv);
  const char *device = StringValueCStr (devicev);

  int r;

  r = guestfs_mkswap_U (g, uuid, device);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.mountpoints() -> hash
 *
 * show mountpoints
 *
 * This call is similar to "g.mounts". That call returns a
 * list of devices. This one returns a hash table (map) of
 * device name to directory where the device is mounted.
 *
 *
 * [Since] Added in version 1.0.62.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_mountpoints}[http://libguestfs.org/guestfs.3.html#guestfs_mountpoints].
 */
VALUE
guestfs_int_ruby_mountpoints (VALUE gv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "mountpoints");


  char **r;

  r = guestfs_mountpoints (g);
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
 *   g.nr_devices() -> fixnum
 *
 * return number of whole block devices (disks) added
 *
 * This returns the number of whole block devices that were
 * added. This is the same as the number of devices that
 * would be returned if you called "g.list_devices".
 * 
 * To find out the maximum number of devices that could be
 * added, call "g.max_disks".
 *
 *
 * [Since] Added in version 1.19.15.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_nr_devices}[http://libguestfs.org/guestfs.3.html#guestfs_nr_devices].
 */
VALUE
guestfs_int_ruby_nr_devices (VALUE gv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "nr_devices");


  int r;

  r = guestfs_nr_devices (g);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return INT2NUM (r);
}

/*
 * call-seq:
 *   g.ntfsclone_in(backupfile, device) -> nil
 *
 * restore NTFS from backup file
 *
 * Restore the "backupfile" (from a previous call to
 * "g.ntfsclone_out") to "device", overwriting any existing
 * contents of this device.
 *
 *
 * [Since] Added in version 1.17.9.
 *
 * [Feature] This function depends on the feature +ntfs3g+.  See also {#feature_available}[rdoc-ref:feature_available].
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_ntfsclone_in}[http://libguestfs.org/guestfs.3.html#guestfs_ntfsclone_in].
 */
VALUE
guestfs_int_ruby_ntfsclone_in (VALUE gv, VALUE backupfilev, VALUE devicev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "ntfsclone_in");

  const char *backupfile = StringValueCStr (backupfilev);
  const char *device = StringValueCStr (devicev);

  int r;

  r = guestfs_ntfsclone_in (g, backupfile, device);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.parse_environment_list(environment) -> nil
 *
 * parse the environment and set handle flags accordingly
 *
 * Parse the list of strings in the argument "environment"
 * and set flags in the handle accordingly. For example if
 * "LIBGUESTFS_DEBUG=1" is a string in the list, then the
 * 'verbose' flag is set in the handle.
 * 
 * This is the same as "g.parse_environment" except that it
 * parses an explicit list of strings instead of the
 * program's environment.
 *
 *
 * [Since] Added in version 1.19.53.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_parse_environment_list}[http://libguestfs.org/guestfs.3.html#guestfs_parse_environment_list].
 */
VALUE
guestfs_int_ruby_parse_environment_list (VALUE gv, VALUE environmentv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "parse_environment_list");

  char **environment;
  Check_Type (environmentv, T_ARRAY);
  {
    size_t i, len;
    len = RARRAY_LEN (environmentv);
    environment = ALLOC_N (char *, len+1);
    for (i = 0; i < len; ++i) {
      volatile VALUE v = rb_ary_entry (environmentv, i);
      environment[i] = StringValueCStr (v);
    }
    environment[len] = NULL;
  }

  int r;

  r = guestfs_parse_environment_list (g, environment);
  free (environment);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.part_get_bootable(device, partnum) -> [True|False]
 *
 * return true if a partition is bootable
 *
 * This command returns true if the partition "partnum" on
 * "device" has the bootable flag set.
 * 
 * See also "g.part_set_bootable".
 *
 *
 * [Since] Added in version 1.3.2.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_part_get_bootable}[http://libguestfs.org/guestfs.3.html#guestfs_part_get_bootable].
 */
VALUE
guestfs_int_ruby_part_get_bootable (VALUE gv, VALUE devicev, VALUE partnumv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "part_get_bootable");

  const char *device = StringValueCStr (devicev);
  int partnum = NUM2INT (partnumv);

  int r;

  r = guestfs_part_get_bootable (g, device, partnum);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return INT2NUM (r);
}

/*
 * call-seq:
 *   g.part_set_gpt_type(device, partnum, guid) -> nil
 *
 * set the type GUID of a GPT partition
 *
 * Set the type GUID of numbered GPT partition "partnum" to
 * "guid". Return an error if the partition table of
 * "device" isn't GPT, or if "guid" is not a valid GUID.
 * 
 * See
 * <http://en.wikipedia.org/wiki/GUID_Partition_Table#Parti
 * tion_type_GUIDs> for a useful list of type GUIDs.
 *
 *
 * [Since] Added in version 1.21.1.
 *
 * [Feature] This function depends on the feature +gdisk+.  See also {#feature_available}[rdoc-ref:feature_available].
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_part_set_gpt_type}[http://libguestfs.org/guestfs.3.html#guestfs_part_set_gpt_type].
 */
VALUE
guestfs_int_ruby_part_set_gpt_type (VALUE gv, VALUE devicev, VALUE partnumv, VALUE guidv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "part_set_gpt_type");

  const char *device = StringValueCStr (devicev);
  int partnum = NUM2INT (partnumv);
  const char *guid = StringValueCStr (guidv);

  int r;

  r = guestfs_part_set_gpt_type (g, device, partnum, guid);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.part_set_name(device, partnum, name) -> nil
 *
 * set partition name
 *
 * This sets the partition name on partition numbered
 * "partnum" on device "device". Note that partitions are
 * numbered from 1.
 * 
 * The partition name can only be set on certain types of
 * partition table. This works on "gpt" but not on "mbr"
 * partitions.
 *
 *
 * [Since] Added in version 1.0.78.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_part_set_name}[http://libguestfs.org/guestfs.3.html#guestfs_part_set_name].
 */
VALUE
guestfs_int_ruby_part_set_name (VALUE gv, VALUE devicev, VALUE partnumv, VALUE namev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "part_set_name");

  const char *device = StringValueCStr (devicev);
  int partnum = NUM2INT (partnumv);
  const char *name = StringValueCStr (namev);

  int r;

  r = guestfs_part_set_name (g, device, partnum, name);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.pvremove(device) -> nil
 *
 * remove an LVM physical volume
 *
 * This wipes a physical volume "device" so that LVM will
 * no longer recognise it.
 * 
 * The implementation uses the "pvremove" command which
 * refuses to wipe physical volumes that contain any volume
 * groups, so you have to remove those first.
 *
 *
 * [Since] Added in version 1.0.13.
 *
 * [Feature] This function depends on the feature +lvm2+.  See also {#feature_available}[rdoc-ref:feature_available].
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_pvremove}[http://libguestfs.org/guestfs.3.html#guestfs_pvremove].
 */
VALUE
guestfs_int_ruby_pvremove (VALUE gv, VALUE devicev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "pvremove");

  const char *device = StringValueCStr (devicev);

  int r;

  r = guestfs_pvremove (g, device);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.scrub_freespace(dir) -> nil
 *
 * scrub (securely wipe) free space
 *
 * This command creates the directory "dir" and then fills
 * it with files until the filesystem is full, and scrubs
 * the files as for "g.scrub_file", and deletes them. The
 * intention is to scrub any free space on the partition
 * containing "dir".
 * 
 * It is an interface to the scrub(1) program. See that
 * manual page for more details.
 *
 *
 * [Since] Added in version 1.0.52.
 *
 * [Feature] This function depends on the feature +scrub+.  See also {#feature_available}[rdoc-ref:feature_available].
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_scrub_freespace}[http://libguestfs.org/guestfs.3.html#guestfs_scrub_freespace].
 */
VALUE
guestfs_int_ruby_scrub_freespace (VALUE gv, VALUE dirv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "scrub_freespace");

  const char *dir = StringValueCStr (dirv);

  int r;

  r = guestfs_scrub_freespace (g, dir);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.set_attach_method(backend) -> nil
 *
 * set the backend
 *
 * Set the method that libguestfs uses to connect to the
 * backend guestfsd daemon.
 * 
 * See "BACKEND" in guestfs(3).
 *
 *
 * [Since] Added in version 1.9.8.
 *
 * [Deprecated] In new code, use rdoc-ref:set_backend instead.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_set_attach_method}[http://libguestfs.org/guestfs.3.html#guestfs_set_attach_method].
 */
VALUE
guestfs_int_ruby_set_attach_method (VALUE gv, VALUE backendv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "set_attach_method");

  const char *backend = StringValueCStr (backendv);

  int r;

  r = guestfs_set_attach_method (g, backend);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.set_network(network) -> nil
 *
 * set enable network flag
 *
 * If "network" is true, then the network is enabled in the
 * libguestfs appliance. The default is false.
 * 
 * This affects whether commands are able to access the
 * network (see "RUNNING COMMANDS" in guestfs(3)).
 * 
 * You must call this before calling "g.launch", otherwise
 * it has no effect.
 *
 *
 * [Since] Added in version 1.5.4.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_set_network}[http://libguestfs.org/guestfs.3.html#guestfs_set_network].
 */
VALUE
guestfs_int_ruby_set_network (VALUE gv, VALUE networkv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "set_network");

  int network = RTEST (networkv);

  int r;

  r = guestfs_set_network (g, network);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.set_smp(smp) -> nil
 *
 * set number of virtual CPUs in appliance
 *
 * Change the number of virtual CPUs assigned to the
 * appliance. The default is 1. Increasing this may improve
 * performance, though often it has no effect.
 * 
 * This function must be called before "g.launch".
 *
 *
 * [Since] Added in version 1.13.15.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_set_smp}[http://libguestfs.org/guestfs.3.html#guestfs_set_smp].
 */
VALUE
guestfs_int_ruby_set_smp (VALUE gv, VALUE smpv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "set_smp");

  int smp = NUM2INT (smpv);

  int r;

  r = guestfs_set_smp (g, smp);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.set_tmpdir(tmpdir) -> nil
 *
 * set the temporary directory
 *
 * Set the directory used by the handle to store temporary
 * files.
 * 
 * The environment variables "LIBGUESTFS_TMPDIR" and
 * "TMPDIR" control the default value: If
 * "LIBGUESTFS_TMPDIR" is set, then that is the default.
 * Else if "TMPDIR" is set, then that is the default. Else
 * /tmp is the default.
 *
 *
 * [Since] Added in version 1.19.58.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_set_tmpdir}[http://libguestfs.org/guestfs.3.html#guestfs_set_tmpdir].
 */
VALUE
guestfs_int_ruby_set_tmpdir (VALUE gv, VALUE tmpdirv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "set_tmpdir");

  const char *tmpdir = !NIL_P (tmpdirv) ? StringValueCStr (tmpdirv) : NULL;

  int r;

  r = guestfs_set_tmpdir (g, tmpdir);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.set_trace(trace) -> nil
 *
 * enable or disable command traces
 *
 * If the command trace flag is set to 1, then libguestfs
 * calls, parameters and return values are traced.
 * 
 * If you want to trace C API calls into libguestfs (and
 * other libraries) then possibly a better way is to use
 * the external ltrace(1) command.
 * 
 * Command traces are disabled unless the environment
 * variable "LIBGUESTFS_TRACE" is defined and set to 1.
 * 
 * Trace messages are normally sent to "stderr", unless you
 * register a callback to send them somewhere else (see
 * "g.set_event_callback").
 *
 *
 * [Since] Added in version 1.0.69.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_set_trace}[http://libguestfs.org/guestfs.3.html#guestfs_set_trace].
 */
VALUE
guestfs_int_ruby_set_trace (VALUE gv, VALUE tracev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "set_trace");

  int trace = RTEST (tracev);

  int r;

  r = guestfs_set_trace (g, trace);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.set_uuid_random(device) -> nil
 *
 * set a random UUID for the filesystem
 *
 * Set the filesystem UUID on "device" to a random UUID. If
 * this fails and the errno is ENOTSUP, means that there is
 * no support for changing the UUID for the type of the
 * specified filesystem.
 * 
 * Only some filesystem types support setting UUIDs.
 * 
 * To read the UUID on a filesystem, call "g.vfs_uuid".
 *
 *
 * [Since] Added in version 1.29.50.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_set_uuid_random}[http://libguestfs.org/guestfs.3.html#guestfs_set_uuid_random].
 */
VALUE
guestfs_int_ruby_set_uuid_random (VALUE gv, VALUE devicev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "set_uuid_random");

  const char *device = StringValueCStr (devicev);

  int r;

  r = guestfs_set_uuid_random (g, device);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.sfdisk(device, cyls, heads, sectors, lines) -> nil
 *
 * create partitions on a block device
 *
 * This is a direct interface to the sfdisk(8) program for
 * creating partitions on block devices.
 * 
 * "device" should be a block device, for example /dev/sda.
 * 
 * "cyls", "heads" and "sectors" are the number of
 * cylinders, heads and sectors on the device, which are
 * passed directly to sfdisk as the *-C*, *-H* and *-S*
 * parameters. If you pass 0 for any of these, then the
 * corresponding parameter is omitted. Usually for 'large'
 * disks, you can just pass 0 for these, but for small
 * (floppy-sized) disks, sfdisk (or rather, the kernel)
 * cannot work out the right geometry and you will need to
 * tell it.
 * 
 * "lines" is a list of lines that we feed to "sfdisk". For
 * more information refer to the sfdisk(8) manpage.
 * 
 * To create a single partition occupying the whole disk,
 * you would pass "lines" as a single element list, when
 * the single element being the string "," (comma).
 * 
 * See also: "g.sfdisk_l", "g.sfdisk_N", "g.part_init"
 *
 *
 * [Since] Added in version 0.8.
 *
 * [Deprecated] In new code, use rdoc-ref:part_add instead.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_sfdisk}[http://libguestfs.org/guestfs.3.html#guestfs_sfdisk].
 */
VALUE
guestfs_int_ruby_sfdisk (VALUE gv, VALUE devicev, VALUE cylsv, VALUE headsv, VALUE sectorsv, VALUE linesv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "sfdisk");

  const char *device = StringValueCStr (devicev);
  int cyls = NUM2INT (cylsv);
  int heads = NUM2INT (headsv);
  int sectors = NUM2INT (sectorsv);
  char **lines;
  Check_Type (linesv, T_ARRAY);
  {
    size_t i, len;
    len = RARRAY_LEN (linesv);
    lines = ALLOC_N (char *, len+1);
    for (i = 0; i < len; ++i) {
      volatile VALUE v = rb_ary_entry (linesv, i);
      lines[i] = StringValueCStr (v);
    }
    lines[len] = NULL;
  }

  int r;

  r = guestfs_sfdisk (g, device, cyls, heads, sectors, lines);
  free (lines);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.sfdiskM(device, lines) -> nil
 *
 * create partitions on a block device
 *
 * This is a simplified interface to the "g.sfdisk"
 * command, where partition sizes are specified in
 * megabytes only (rounded to the nearest cylinder) and you
 * don't need to specify the cyls, heads and sectors
 * parameters which were rarely if ever used anyway.
 * 
 * See also: "g.sfdisk", the sfdisk(8) manpage and
 * "g.part_disk"
 *
 *
 * [Since] Added in version 1.0.55.
 *
 * [Deprecated] In new code, use rdoc-ref:part_add instead.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_sfdiskM}[http://libguestfs.org/guestfs.3.html#guestfs_sfdiskM].
 */
VALUE
guestfs_int_ruby_sfdiskM (VALUE gv, VALUE devicev, VALUE linesv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "sfdiskM");

  const char *device = StringValueCStr (devicev);
  char **lines;
  Check_Type (linesv, T_ARRAY);
  {
    size_t i, len;
    len = RARRAY_LEN (linesv);
    lines = ALLOC_N (char *, len+1);
    for (i = 0; i < len; ++i) {
      volatile VALUE v = rb_ary_entry (linesv, i);
      lines[i] = StringValueCStr (v);
    }
    lines[len] = NULL;
  }

  int r;

  r = guestfs_sfdiskM (g, device, lines);
  free (lines);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.sfdisk_N(device, partnum, cyls, heads, sectors, line) -> nil
 *
 * modify a single partition on a block device
 *
 * This runs sfdisk(8) option to modify just the single
 * partition "n" (note: "n" counts from 1).
 * 
 * For other parameters, see "g.sfdisk". You should usually
 * pass 0 for the cyls/heads/sectors parameters.
 * 
 * See also: "g.part_add"
 *
 *
 * [Since] Added in version 1.0.26.
 *
 * [Deprecated] In new code, use rdoc-ref:part_add instead.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_sfdisk_N}[http://libguestfs.org/guestfs.3.html#guestfs_sfdisk_N].
 */
VALUE
guestfs_int_ruby_sfdisk_N (VALUE gv, VALUE devicev, VALUE partnumv, VALUE cylsv, VALUE headsv, VALUE sectorsv, VALUE linev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "sfdisk_N");

  const char *device = StringValueCStr (devicev);
  int partnum = NUM2INT (partnumv);
  int cyls = NUM2INT (cylsv);
  int heads = NUM2INT (headsv);
  int sectors = NUM2INT (sectorsv);
  const char *line = StringValueCStr (linev);

  int r;

  r = guestfs_sfdisk_N (g, device, partnum, cyls, heads, sectors, line);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.stat(path) -> hash
 *
 * get file information
 *
 * Returns file information for the given "path".
 * 
 * This is the same as the stat(2) system call.
 *
 *
 * [Since] Added in version 1.9.2.
 *
 * [Deprecated] In new code, use rdoc-ref:statns instead.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_stat}[http://libguestfs.org/guestfs.3.html#guestfs_stat].
 */
VALUE
guestfs_int_ruby_stat (VALUE gv, VALUE pathv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "stat");

  const char *path = StringValueCStr (pathv);

  struct guestfs_stat *r;

  r = guestfs_stat (g, path);
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
 *   g.swapoff_device(device) -> nil
 *
 * disable swap on device
 *
 * This command disables the libguestfs appliance swap
 * device or partition named "device". See
 * "g.swapon_device".
 *
 *
 * [Since] Added in version 1.0.66.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_swapoff_device}[http://libguestfs.org/guestfs.3.html#guestfs_swapoff_device].
 */
VALUE
guestfs_int_ruby_swapoff_device (VALUE gv, VALUE devicev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "swapoff_device");

  const char *device = StringValueCStr (devicev);

  int r;

  r = guestfs_swapoff_device (g, device);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.swapon_device(device) -> nil
 *
 * enable swap on device
 *
 * This command enables the libguestfs appliance to use the
 * swap device or partition named "device". The increased
 * memory is made available for all commands, for example
 * those run using "g.command" or "g.sh".
 * 
 * Note that you should not swap to existing guest swap
 * partitions unless you know what you are doing. They may
 * contain hibernation information, or other information
 * that the guest doesn't want you to trash. You also risk
 * leaking information about the host to the guest this
 * way. Instead, attach a new host device to the guest and
 * swap on that.
 *
 *
 * [Since] Added in version 1.0.66.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_swapon_device}[http://libguestfs.org/guestfs.3.html#guestfs_swapon_device].
 */
VALUE
guestfs_int_ruby_swapon_device (VALUE gv, VALUE devicev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "swapon_device");

  const char *device = StringValueCStr (devicev);

  int r;

  r = guestfs_swapon_device (g, device);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.swapon_uuid(uuid) -> nil
 *
 * enable swap on swap partition by UUID
 *
 * This command enables swap to a swap partition with the
 * given UUID. See "g.swapon_device" for other notes.
 *
 *
 * [Since] Added in version 1.0.66.
 *
 * [Feature] This function depends on the feature +linuxfsuuid+.  See also {#feature_available}[rdoc-ref:feature_available].
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_swapon_uuid}[http://libguestfs.org/guestfs.3.html#guestfs_swapon_uuid].
 */
VALUE
guestfs_int_ruby_swapon_uuid (VALUE gv, VALUE uuidv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "swapon_uuid");

  const char *uuid = StringValueCStr (uuidv);

  int r;

  r = guestfs_swapon_uuid (g, uuid);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.tgz_in(tarball, directory) -> nil
 *
 * unpack compressed tarball to directory
 *
 * This command uploads and unpacks local file "tarball" (a
 * *gzip compressed* tar file) into directory.
 *
 *
 * [Since] Added in version 1.0.3.
 *
 * [Deprecated] In new code, use rdoc-ref:tar_in instead.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_tgz_in}[http://libguestfs.org/guestfs.3.html#guestfs_tgz_in].
 */
VALUE
guestfs_int_ruby_tgz_in (VALUE gv, VALUE tarballv, VALUE directoryv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "tgz_in");

  const char *tarball = StringValueCStr (tarballv);
  const char *directory = StringValueCStr (directoryv);

  int r;

  r = guestfs_tgz_in (g, tarball, directory);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.truncate_size(path, size) -> nil
 *
 * truncate a file to a particular size
 *
 * This command truncates "path" to size "size" bytes. The
 * file must exist already.
 * 
 * If the current file size is less than "size" then the
 * file is extended to the required size with zero bytes.
 * This creates a sparse file (ie. disk blocks are not
 * allocated for the file until you write to it). To create
 * a non-sparse file of zeroes, use "g.fallocate64"
 * instead.
 *
 *
 * [Since] Added in version 1.0.77.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_truncate_size}[http://libguestfs.org/guestfs.3.html#guestfs_truncate_size].
 */
VALUE
guestfs_int_ruby_truncate_size (VALUE gv, VALUE pathv, VALUE sizev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "truncate_size");

  const char *path = StringValueCStr (pathv);
  long long size = NUM2LL (sizev);

  int r;

  r = guestfs_truncate_size (g, path, size);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.txz_in(tarball, directory) -> nil
 *
 * unpack compressed tarball to directory
 *
 * This command uploads and unpacks local file "tarball"
 * (an *xz compressed* tar file) into directory.
 *
 *
 * [Since] Added in version 1.3.2.
 *
 * [Deprecated] In new code, use rdoc-ref:tar_in instead.
 *
 * [Feature] This function depends on the feature +xz+.  See also {#feature_available}[rdoc-ref:feature_available].
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_txz_in}[http://libguestfs.org/guestfs.3.html#guestfs_txz_in].
 */
VALUE
guestfs_int_ruby_txz_in (VALUE gv, VALUE tarballv, VALUE directoryv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "txz_in");

  const char *tarball = StringValueCStr (tarballv);
  const char *directory = StringValueCStr (directoryv);

  int r;

  r = guestfs_txz_in (g, tarball, directory);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.user_cancel() -> nil
 *
 * cancel the current upload or download operation
 *
 * This function cancels the current upload or download
 * operation.
 * 
 * Unlike most other libguestfs calls, this function is
 * signal safe and thread safe. You can call it from a
 * signal handler or from another thread, without needing
 * to do any locking.
 * 
 * The transfer that was in progress (if there is one) will
 * stop shortly afterwards, and will return an error. The
 * errno (see "guestfs_last_errno") is set to "EINTR", so
 * you can test for this to find out if the operation was
 * cancelled or failed because of another error.
 * 
 * No cleanup is performed: for example, if a file was
 * being uploaded then after cancellation there may be a
 * partially uploaded file. It is the caller's
 * responsibility to clean up if necessary.
 * 
 * There are two common places that you might call
 * "g.user_cancel":
 * 
 * In an interactive text-based program, you might call it
 * from a "SIGINT" signal handler so that pressing "^C"
 * cancels the current operation. (You also need to call
 * "guestfs_set_pgroup" so that child processes don't
 * receive the "^C" signal).
 * 
 * In a graphical program, when the main thread is
 * displaying a progress bar with a cancel button, wire up
 * the cancel button to call this function.
 *
 *
 * [Since] Added in version 1.11.18.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_user_cancel}[http://libguestfs.org/guestfs.3.html#guestfs_user_cancel].
 */
VALUE
guestfs_int_ruby_user_cancel (VALUE gv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "user_cancel");


  int r;

  r = guestfs_user_cancel (g);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.vgchange_uuid(vg) -> nil
 *
 * generate a new random UUID for a volume group
 *
 * Generate a new random UUID for the volume group "vg".
 *
 *
 * [Since] Added in version 1.19.26.
 *
 * [Feature] This function depends on the feature +lvm2+.  See also {#feature_available}[rdoc-ref:feature_available].
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_vgchange_uuid}[http://libguestfs.org/guestfs.3.html#guestfs_vgchange_uuid].
 */
VALUE
guestfs_int_ruby_vgchange_uuid (VALUE gv, VALUE vgv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "vgchange_uuid");

  const char *vg = StringValueCStr (vgv);

  int r;

  r = guestfs_vgchange_uuid (g, vg);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.vglvuuids(vgname) -> list
 *
 * get the LV UUIDs of all LVs in the volume group
 *
 * Given a VG called "vgname", this returns the UUIDs of
 * all the logical volumes created in this volume group.
 * 
 * You can use this along with "g.lvs" and "g.lvuuid" calls
 * to associate logical volumes and volume groups.
 * 
 * See also "g.vgpvuuids".
 *
 *
 * [Since] Added in version 1.0.87.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_vglvuuids}[http://libguestfs.org/guestfs.3.html#guestfs_vglvuuids].
 */
VALUE
guestfs_int_ruby_vglvuuids (VALUE gv, VALUE vgnamev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "vglvuuids");

  const char *vgname = StringValueCStr (vgnamev);

  char **r;

  r = guestfs_vglvuuids (g, vgname);
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
 *   g.vgremove(vgname) -> nil
 *
 * remove an LVM volume group
 *
 * Remove an LVM volume group "vgname", (for example "VG").
 * 
 * This also forcibly removes all logical volumes in the
 * volume group (if any).
 *
 *
 * [Since] Added in version 1.0.13.
 *
 * [Feature] This function depends on the feature +lvm2+.  See also {#feature_available}[rdoc-ref:feature_available].
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_vgremove}[http://libguestfs.org/guestfs.3.html#guestfs_vgremove].
 */
VALUE
guestfs_int_ruby_vgremove (VALUE gv, VALUE vgnamev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "vgremove");

  const char *vgname = StringValueCStr (vgnamev);

  int r;

  r = guestfs_vgremove (g, vgname);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.wc_l(path) -> fixnum
 *
 * count lines in a file
 *
 * This command counts the lines in a file, using the "wc
 * -l" external command.
 *
 *
 * [Since] Added in version 1.0.54.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_wc_l}[http://libguestfs.org/guestfs.3.html#guestfs_wc_l].
 */
VALUE
guestfs_int_ruby_wc_l (VALUE gv, VALUE pathv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "wc_l");

  const char *path = StringValueCStr (pathv);

  int r;

  r = guestfs_wc_l (g, path);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return INT2NUM (r);
}

/*
 * call-seq:
 *   g.xfs_growfs(path, {optargs...}) -> nil
 *
 * expand an existing XFS filesystem
 *
 * Grow the XFS filesystem mounted at "path".
 * 
 * The returned struct contains geometry information.
 * Missing fields are returned as -1 (for numeric fields)
 * or empty string.
 * 
 * Optional arguments are supplied in the final hash
 * parameter, which is a hash of the argument name to its
 * value. Pass an empty {} for no optional arguments.
 *
 *
 * [Since] Added in version 1.19.28.
 *
 * [Feature] This function depends on the feature +xfs+.  See also {#feature_available}[rdoc-ref:feature_available].
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_xfs_growfs}[http://libguestfs.org/guestfs.3.html#guestfs_xfs_growfs].
 */
VALUE
guestfs_int_ruby_xfs_growfs (int argc, VALUE *argv, VALUE gv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "xfs_growfs");

  if (argc < 1 || argc > 2)
    rb_raise (rb_eArgError, "expecting 1 or 2 arguments");

  volatile VALUE pathv = argv[0];
  volatile VALUE optargsv = argc > 1 ? argv[1] : rb_hash_new ();

  const char *path = StringValueCStr (pathv);

  Check_Type (optargsv, T_HASH);
  struct guestfs_xfs_growfs_argv optargs_s = { .bitmask = 0 };
  struct guestfs_xfs_growfs_argv *optargs = &optargs_s;
  volatile VALUE v;
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("datasec")));
  if (v != Qnil) {
    optargs_s.datasec = RTEST (v);
    optargs_s.bitmask |= GUESTFS_XFS_GROWFS_DATASEC_BITMASK;
  }
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("logsec")));
  if (v != Qnil) {
    optargs_s.logsec = RTEST (v);
    optargs_s.bitmask |= GUESTFS_XFS_GROWFS_LOGSEC_BITMASK;
  }
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("rtsec")));
  if (v != Qnil) {
    optargs_s.rtsec = RTEST (v);
    optargs_s.bitmask |= GUESTFS_XFS_GROWFS_RTSEC_BITMASK;
  }
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("datasize")));
  if (v != Qnil) {
    optargs_s.datasize = NUM2LL (v);
    optargs_s.bitmask |= GUESTFS_XFS_GROWFS_DATASIZE_BITMASK;
  }
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("logsize")));
  if (v != Qnil) {
    optargs_s.logsize = NUM2LL (v);
    optargs_s.bitmask |= GUESTFS_XFS_GROWFS_LOGSIZE_BITMASK;
  }
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("rtsize")));
  if (v != Qnil) {
    optargs_s.rtsize = NUM2LL (v);
    optargs_s.bitmask |= GUESTFS_XFS_GROWFS_RTSIZE_BITMASK;
  }
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("rtextsize")));
  if (v != Qnil) {
    optargs_s.rtextsize = NUM2LL (v);
    optargs_s.bitmask |= GUESTFS_XFS_GROWFS_RTEXTSIZE_BITMASK;
  }
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("maxpct")));
  if (v != Qnil) {
    optargs_s.maxpct = NUM2INT (v);
    optargs_s.bitmask |= GUESTFS_XFS_GROWFS_MAXPCT_BITMASK;
  }

  int r;

  r = guestfs_xfs_growfs_argv (g, path, optargs);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.xfs_info(pathordevice) -> hash
 *
 * get geometry of XFS filesystem
 *
 * "pathordevice" is a mounted XFS filesystem or a device
 * containing an XFS filesystem. This command returns the
 * geometry of the filesystem.
 * 
 * The returned struct contains geometry information.
 * Missing fields are returned as -1 (for numeric fields)
 * or empty string.
 *
 *
 * [Since] Added in version 1.19.21.
 *
 * [Feature] This function depends on the feature +xfs+.  See also {#feature_available}[rdoc-ref:feature_available].
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_xfs_info}[http://libguestfs.org/guestfs.3.html#guestfs_xfs_info].
 */
VALUE
guestfs_int_ruby_xfs_info (VALUE gv, VALUE pathordevicev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "xfs_info");

  const char *pathordevice = StringValueCStr (pathordevicev);

  struct guestfs_xfsinfo *r;

  r = guestfs_xfs_info (g, pathordevice);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  volatile VALUE rv = rb_hash_new ();
  rb_hash_aset (rv, rb_str_new2 ("xfs_mntpoint"), rb_str_new2 (r->xfs_mntpoint));
  rb_hash_aset (rv, rb_str_new2 ("xfs_inodesize"), UINT2NUM (r->xfs_inodesize));
  rb_hash_aset (rv, rb_str_new2 ("xfs_agcount"), UINT2NUM (r->xfs_agcount));
  rb_hash_aset (rv, rb_str_new2 ("xfs_agsize"), UINT2NUM (r->xfs_agsize));
  rb_hash_aset (rv, rb_str_new2 ("xfs_sectsize"), UINT2NUM (r->xfs_sectsize));
  rb_hash_aset (rv, rb_str_new2 ("xfs_attr"), UINT2NUM (r->xfs_attr));
  rb_hash_aset (rv, rb_str_new2 ("xfs_blocksize"), UINT2NUM (r->xfs_blocksize));
  rb_hash_aset (rv, rb_str_new2 ("xfs_datablocks"), ULL2NUM (r->xfs_datablocks));
  rb_hash_aset (rv, rb_str_new2 ("xfs_imaxpct"), UINT2NUM (r->xfs_imaxpct));
  rb_hash_aset (rv, rb_str_new2 ("xfs_sunit"), UINT2NUM (r->xfs_sunit));
  rb_hash_aset (rv, rb_str_new2 ("xfs_swidth"), UINT2NUM (r->xfs_swidth));
  rb_hash_aset (rv, rb_str_new2 ("xfs_dirversion"), UINT2NUM (r->xfs_dirversion));
  rb_hash_aset (rv, rb_str_new2 ("xfs_dirblocksize"), UINT2NUM (r->xfs_dirblocksize));
  rb_hash_aset (rv, rb_str_new2 ("xfs_cimode"), UINT2NUM (r->xfs_cimode));
  rb_hash_aset (rv, rb_str_new2 ("xfs_logname"), rb_str_new2 (r->xfs_logname));
  rb_hash_aset (rv, rb_str_new2 ("xfs_logblocksize"), UINT2NUM (r->xfs_logblocksize));
  rb_hash_aset (rv, rb_str_new2 ("xfs_logblocks"), UINT2NUM (r->xfs_logblocks));
  rb_hash_aset (rv, rb_str_new2 ("xfs_logversion"), UINT2NUM (r->xfs_logversion));
  rb_hash_aset (rv, rb_str_new2 ("xfs_logsectsize"), UINT2NUM (r->xfs_logsectsize));
  rb_hash_aset (rv, rb_str_new2 ("xfs_logsunit"), UINT2NUM (r->xfs_logsunit));
  rb_hash_aset (rv, rb_str_new2 ("xfs_lazycount"), UINT2NUM (r->xfs_lazycount));
  rb_hash_aset (rv, rb_str_new2 ("xfs_rtname"), rb_str_new2 (r->xfs_rtname));
  rb_hash_aset (rv, rb_str_new2 ("xfs_rtextsize"), UINT2NUM (r->xfs_rtextsize));
  rb_hash_aset (rv, rb_str_new2 ("xfs_rtblocks"), ULL2NUM (r->xfs_rtblocks));
  rb_hash_aset (rv, rb_str_new2 ("xfs_rtextents"), ULL2NUM (r->xfs_rtextents));
  guestfs_free_xfsinfo (r);
  return rv;
}

/*
 * call-seq:
 *   g.xfs_repair(device, {optargs...}) -> fixnum
 *
 * repair an XFS filesystem
 *
 * Repair corrupt or damaged XFS filesystem on "device".
 * 
 * The filesystem is specified using the "device" argument
 * which should be the device name of the disk partition or
 * volume containing the filesystem. If given the name of a
 * block device, "xfs_repair" will attempt to find the raw
 * device associated with the specified block device and
 * will use the raw device instead.
 * 
 * Regardless, the filesystem to be repaired must be
 * unmounted, otherwise, the resulting filesystem may be
 * inconsistent or corrupt.
 * 
 * The returned status indicates whether filesystem
 * corruption was detected (returns 1) or was not detected
 * (returns 0).
 * 
 * Optional arguments are supplied in the final hash
 * parameter, which is a hash of the argument name to its
 * value. Pass an empty {} for no optional arguments.
 *
 *
 * [Since] Added in version 1.19.36.
 *
 * [Feature] This function depends on the feature +xfs+.  See also {#feature_available}[rdoc-ref:feature_available].
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_xfs_repair}[http://libguestfs.org/guestfs.3.html#guestfs_xfs_repair].
 */
VALUE
guestfs_int_ruby_xfs_repair (int argc, VALUE *argv, VALUE gv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "xfs_repair");

  if (argc < 1 || argc > 2)
    rb_raise (rb_eArgError, "expecting 1 or 2 arguments");

  volatile VALUE devicev = argv[0];
  volatile VALUE optargsv = argc > 1 ? argv[1] : rb_hash_new ();

  const char *device = StringValueCStr (devicev);

  Check_Type (optargsv, T_HASH);
  struct guestfs_xfs_repair_argv optargs_s = { .bitmask = 0 };
  struct guestfs_xfs_repair_argv *optargs = &optargs_s;
  volatile VALUE v;
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("forcelogzero")));
  if (v != Qnil) {
    optargs_s.forcelogzero = RTEST (v);
    optargs_s.bitmask |= GUESTFS_XFS_REPAIR_FORCELOGZERO_BITMASK;
  }
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("nomodify")));
  if (v != Qnil) {
    optargs_s.nomodify = RTEST (v);
    optargs_s.bitmask |= GUESTFS_XFS_REPAIR_NOMODIFY_BITMASK;
  }
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("noprefetch")));
  if (v != Qnil) {
    optargs_s.noprefetch = RTEST (v);
    optargs_s.bitmask |= GUESTFS_XFS_REPAIR_NOPREFETCH_BITMASK;
  }
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("forcegeometry")));
  if (v != Qnil) {
    optargs_s.forcegeometry = RTEST (v);
    optargs_s.bitmask |= GUESTFS_XFS_REPAIR_FORCEGEOMETRY_BITMASK;
  }
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("maxmem")));
  if (v != Qnil) {
    optargs_s.maxmem = NUM2LL (v);
    optargs_s.bitmask |= GUESTFS_XFS_REPAIR_MAXMEM_BITMASK;
  }
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("ihashsize")));
  if (v != Qnil) {
    optargs_s.ihashsize = NUM2LL (v);
    optargs_s.bitmask |= GUESTFS_XFS_REPAIR_IHASHSIZE_BITMASK;
  }
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("bhashsize")));
  if (v != Qnil) {
    optargs_s.bhashsize = NUM2LL (v);
    optargs_s.bitmask |= GUESTFS_XFS_REPAIR_BHASHSIZE_BITMASK;
  }
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("agstride")));
  if (v != Qnil) {
    optargs_s.agstride = NUM2LL (v);
    optargs_s.bitmask |= GUESTFS_XFS_REPAIR_AGSTRIDE_BITMASK;
  }
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("logdev")));
  if (v != Qnil) {
    optargs_s.logdev = StringValueCStr (v);
    optargs_s.bitmask |= GUESTFS_XFS_REPAIR_LOGDEV_BITMASK;
  }
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("rtdev")));
  if (v != Qnil) {
    optargs_s.rtdev = StringValueCStr (v);
    optargs_s.bitmask |= GUESTFS_XFS_REPAIR_RTDEV_BITMASK;
  }

  int r;

  r = guestfs_xfs_repair_argv (g, device, optargs);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return INT2NUM (r);
}

/*
 * call-seq:
 *   g.zero_device(device) -> nil
 *
 * write zeroes to an entire device
 *
 * This command writes zeroes over the entire "device".
 * Compare with "g.zero" which just zeroes the first few
 * blocks of a device.
 * 
 * If blocks are already zero, then this command avoids
 * writing zeroes. This prevents the underlying device from
 * becoming non-sparse or growing unnecessarily.
 *
 *
 * [Since] Added in version 1.3.1.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_zero_device}[http://libguestfs.org/guestfs.3.html#guestfs_zero_device].
 */
VALUE
guestfs_int_ruby_zero_device (VALUE gv, VALUE devicev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "zero_device");

  const char *device = StringValueCStr (devicev);

  int r;

  r = guestfs_zero_device (g, device);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.zero_free_space(directory) -> nil
 *
 * zero free space in a filesystem
 *
 * Zero the free space in the filesystem mounted on
 * directory. The filesystem must be mounted read-write.
 * 
 * The filesystem contents are not affected, but any free
 * space in the filesystem is freed.
 * 
 * Free space is not "trimmed". You may want to call
 * "g.fstrim" either as an alternative to this, or after
 * calling this, depending on your requirements.
 *
 *
 * [Since] Added in version 1.17.18.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_zero_free_space}[http://libguestfs.org/guestfs.3.html#guestfs_zero_free_space].
 */
VALUE
guestfs_int_ruby_zero_free_space (VALUE gv, VALUE directoryv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "zero_free_space");

  const char *directory = StringValueCStr (directoryv);

  int r;

  r = guestfs_zero_free_space (g, directory);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

