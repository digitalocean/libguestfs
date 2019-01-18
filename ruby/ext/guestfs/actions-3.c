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
 *   g.acl_get_file(path, acltype) -> string
 *
 * get the POSIX ACL attached to a file
 *
 * This function returns the POSIX Access Control List
 * (ACL) attached to "path". The ACL is returned in "long
 * text form" (see acl(5)).
 * 
 * The "acltype" parameter may be:
 * 
 * "access"
 * Return the ordinary (access) ACL for any file,
 * directory or other filesystem object.
 * 
 * "default"
 * Return the default ACL. Normally this only makes
 * sense if "path" is a directory.
 *
 *
 * [Since] Added in version 1.19.63.
 *
 * [Feature] This function depends on the feature +acl+.  See also {#feature_available}[rdoc-ref:feature_available].
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_acl_get_file}[http://libguestfs.org/guestfs.3.html#guestfs_acl_get_file].
 */
VALUE
guestfs_int_ruby_acl_get_file (VALUE gv, VALUE pathv, VALUE acltypev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "acl_get_file");

  const char *path = StringValueCStr (pathv);
  const char *acltype = StringValueCStr (acltypev);

  char *r;

  r = guestfs_acl_get_file (g, path, acltype);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  volatile VALUE rv = rb_str_new2 (r);
  free (r);
  return rv;
}

/*
 * call-seq:
 *   g.aug_close() -> nil
 *
 * close the current Augeas handle
 *
 * Close the current Augeas handle and free up any
 * resources used by it. After calling this, you have to
 * call "g.aug_init" again before you can use any other
 * Augeas functions.
 *
 *
 * [Since] Added in version 0.7.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_aug_close}[http://libguestfs.org/guestfs.3.html#guestfs_aug_close].
 */
VALUE
guestfs_int_ruby_aug_close (VALUE gv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "aug_close");


  int r;

  r = guestfs_aug_close (g);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.aug_defnode(name, expr, val) -> hash
 *
 * define an Augeas node
 *
 * Defines a variable "name" whose value is the result of
 * evaluating "expr".
 * 
 * If "expr" evaluates to an empty nodeset, a node is
 * created, equivalent to calling "g.aug_set" "expr",
 * "value". "name" will be the nodeset containing that
 * single node.
 * 
 * On success this returns a pair containing the number of
 * nodes in the nodeset, and a boolean flag if a node was
 * created.
 *
 *
 * [Since] Added in version 0.7.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_aug_defnode}[http://libguestfs.org/guestfs.3.html#guestfs_aug_defnode].
 */
VALUE
guestfs_int_ruby_aug_defnode (VALUE gv, VALUE namev, VALUE exprv, VALUE valv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "aug_defnode");

  const char *name = StringValueCStr (namev);
  const char *expr = StringValueCStr (exprv);
  const char *val = StringValueCStr (valv);

  struct guestfs_int_bool *r;

  r = guestfs_aug_defnode (g, name, expr, val);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  volatile VALUE rv = rb_hash_new ();
  rb_hash_aset (rv, rb_str_new2 ("i"), INT2NUM (r->i));
  rb_hash_aset (rv, rb_str_new2 ("b"), INT2NUM (r->b));
  guestfs_free_int_bool (r);
  return rv;
}

/*
 * call-seq:
 *   g.aug_get(augpath) -> string
 *
 * look up the value of an Augeas path
 *
 * Look up the value associated with "path". If "path"
 * matches exactly one node, the "value" is returned.
 *
 *
 * [Since] Added in version 0.7.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_aug_get}[http://libguestfs.org/guestfs.3.html#guestfs_aug_get].
 */
VALUE
guestfs_int_ruby_aug_get (VALUE gv, VALUE augpathv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "aug_get");

  const char *augpath = StringValueCStr (augpathv);

  char *r;

  r = guestfs_aug_get (g, augpath);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  volatile VALUE rv = rb_str_new2 (r);
  free (r);
  return rv;
}

/*
 * call-seq:
 *   g.aug_save() -> nil
 *
 * write all pending Augeas changes to disk
 *
 * This writes all pending changes to disk.
 * 
 * The flags which were passed to "g.aug_init" affect
 * exactly how files are saved.
 *
 *
 * [Since] Added in version 0.7.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_aug_save}[http://libguestfs.org/guestfs.3.html#guestfs_aug_save].
 */
VALUE
guestfs_int_ruby_aug_save (VALUE gv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "aug_save");


  int r;

  r = guestfs_aug_save (g);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.aug_setm(base, sub, val) -> fixnum
 *
 * set multiple Augeas nodes
 *
 * Change multiple Augeas nodes in a single operation.
 * "base" is an expression matching multiple nodes. "sub"
 * is a path expression relative to "base". All nodes
 * matching "base" are found, and then for each node, "sub"
 * is changed to "val". "sub" may also be "NULL" in which
 * case the "base" nodes are modified.
 * 
 * This returns the number of nodes modified.
 *
 *
 * [Since] Added in version 1.23.14.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_aug_setm}[http://libguestfs.org/guestfs.3.html#guestfs_aug_setm].
 */
VALUE
guestfs_int_ruby_aug_setm (VALUE gv, VALUE basev, VALUE subv, VALUE valv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "aug_setm");

  const char *base = StringValueCStr (basev);
  const char *sub = !NIL_P (subv) ? StringValueCStr (subv) : NULL;
  const char *val = StringValueCStr (valv);

  int r;

  r = guestfs_aug_setm (g, base, sub, val);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return INT2NUM (r);
}

/*
 * call-seq:
 *   g.available(groups) -> nil
 *
 * test availability of some parts of the API
 *
 * This command is used to check the availability of some
 * groups of functionality in the appliance, which not all
 * builds of the libguestfs appliance will be able to
 * provide.
 * 
 * The libguestfs groups, and the functions that those
 * groups correspond to, are listed in "AVAILABILITY" in
 * guestfs(3). You can also fetch this list at runtime by
 * calling "g.available_all_groups".
 * 
 * The argument "groups" is a list of group names, eg:
 * "["inotify", "augeas"]" would check for the availability
 * of the Linux inotify functions and Augeas (configuration
 * file editing) functions.
 * 
 * The command returns no error if *all* requested groups
 * are available.
 * 
 * It fails with an error if one or more of the requested
 * groups is unavailable in the appliance.
 * 
 * If an unknown group name is included in the list of
 * groups then an error is always returned.
 * 
 * *Notes:*
 * 
 * *   "g.feature_available" is the same as this call, but
 * with a slightly simpler to use API: that call
 * returns a boolean true/false instead of throwing an
 * error.
 * 
 * *   You must call "g.launch" before calling this
 * function.
 * 
 * The reason is because we don't know what groups are
 * supported by the appliance/daemon until it is
 * running and can be queried.
 * 
 * *   If a group of functions is available, this does not
 * necessarily mean that they will work. You still have
 * to check for errors when calling individual API
 * functions even if they are available.
 * 
 * *   It is usually the job of distro packagers to build
 * complete functionality into the libguestfs
 * appliance. Upstream libguestfs, if built from source
 * with all requirements satisfied, will support
 * everything.
 * 
 * *   This call was added in version 1.0.80. In previous
 * versions of libguestfs all you could do would be to
 * speculatively execute a command to find out if the
 * daemon implemented it. See also "g.version".
 * 
 * See also "g.filesystem_available".
 *
 *
 * [Since] Added in version 1.0.80.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_available}[http://libguestfs.org/guestfs.3.html#guestfs_available].
 */
VALUE
guestfs_int_ruby_available (VALUE gv, VALUE groupsv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "available");

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

  r = guestfs_available (g, groups);
  free (groups);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.blkdiscard(device) -> nil
 *
 * discard all blocks on a device
 *
 * This discards all blocks on the block device "device",
 * giving the free space back to the host.
 * 
 * This operation requires support in libguestfs, the host
 * filesystem, qemu and the host kernel. If this support
 * isn't present it may give an error or even appear to run
 * but do nothing. You must also set the "discard"
 * attribute on the underlying drive (see
 * "g.add_drive_opts").
 *
 *
 * [Since] Added in version 1.25.44.
 *
 * [Feature] This function depends on the feature +blkdiscard+.  See also {#feature_available}[rdoc-ref:feature_available].
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_blkdiscard}[http://libguestfs.org/guestfs.3.html#guestfs_blkdiscard].
 */
VALUE
guestfs_int_ruby_blkdiscard (VALUE gv, VALUE devicev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "blkdiscard");

  const char *device = StringValueCStr (devicev);

  int r;

  r = guestfs_blkdiscard (g, device);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.blockdev_getsz(device) -> fixnum
 *
 * get total size of device in 512-byte sectors
 *
 * This returns the size of the device in units of 512-byte
 * sectors (even if the sectorsize isn't 512 bytes ...
 * weird).
 * 
 * See also "g.blockdev_getss" for the real sector size of
 * the device, and "g.blockdev_getsize64" for the more
 * useful *size in bytes*.
 * 
 * This uses the blockdev(8) command.
 *
 *
 * [Since] Added in version 1.9.3.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_blockdev_getsz}[http://libguestfs.org/guestfs.3.html#guestfs_blockdev_getsz].
 */
VALUE
guestfs_int_ruby_blockdev_getsz (VALUE gv, VALUE devicev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "blockdev_getsz");

  const char *device = StringValueCStr (devicev);

  int64_t r;

  r = guestfs_blockdev_getsz (g, device);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return ULL2NUM (r);
}

/*
 * call-seq:
 *   g.blockdev_setro(device) -> nil
 *
 * set block device to read-only
 *
 * Sets the block device named "device" to read-only.
 * 
 * This uses the blockdev(8) command.
 *
 *
 * [Since] Added in version 1.9.3.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_blockdev_setro}[http://libguestfs.org/guestfs.3.html#guestfs_blockdev_setro].
 */
VALUE
guestfs_int_ruby_blockdev_setro (VALUE gv, VALUE devicev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "blockdev_setro");

  const char *device = StringValueCStr (devicev);

  int r;

  r = guestfs_blockdev_setro (g, device);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.btrfs_balance_status(path) -> hash
 *
 * show the status of a running or paused balance
 *
 * Show the status of a running or paused balance on a
 * btrfs filesystem.
 *
 *
 * [Since] Added in version 1.29.26.
 *
 * [Feature] This function depends on the feature +btrfs+.  See also {#feature_available}[rdoc-ref:feature_available].
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_btrfs_balance_status}[http://libguestfs.org/guestfs.3.html#guestfs_btrfs_balance_status].
 */
VALUE
guestfs_int_ruby_btrfs_balance_status (VALUE gv, VALUE pathv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "btrfs_balance_status");

  const char *path = StringValueCStr (pathv);

  struct guestfs_btrfsbalance *r;

  r = guestfs_btrfs_balance_status (g, path);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  volatile VALUE rv = rb_hash_new ();
  rb_hash_aset (rv, rb_str_new2 ("btrfsbalance_status"), rb_str_new2 (r->btrfsbalance_status));
  rb_hash_aset (rv, rb_str_new2 ("btrfsbalance_total"), ULL2NUM (r->btrfsbalance_total));
  rb_hash_aset (rv, rb_str_new2 ("btrfsbalance_balanced"), ULL2NUM (r->btrfsbalance_balanced));
  rb_hash_aset (rv, rb_str_new2 ("btrfsbalance_considered"), ULL2NUM (r->btrfsbalance_considered));
  rb_hash_aset (rv, rb_str_new2 ("btrfsbalance_left"), ULL2NUM (r->btrfsbalance_left));
  guestfs_free_btrfsbalance (r);
  return rv;
}

/*
 * call-seq:
 *   g.btrfs_device_delete(devices, fs) -> nil
 *
 * remove devices from a btrfs filesystem
 *
 * Remove the "devices" from the btrfs filesystem mounted
 * at "fs". If "devices" is an empty list, this does
 * nothing.
 *
 *
 * [Since] Added in version 1.17.35.
 *
 * [Feature] This function depends on the feature +btrfs+.  See also {#feature_available}[rdoc-ref:feature_available].
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_btrfs_device_delete}[http://libguestfs.org/guestfs.3.html#guestfs_btrfs_device_delete].
 */
VALUE
guestfs_int_ruby_btrfs_device_delete (VALUE gv, VALUE devicesv, VALUE fsv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "btrfs_device_delete");

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

  r = guestfs_btrfs_device_delete (g, devices, fs);
  free (devices);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.btrfs_filesystem_defragment(path, {optargs...}) -> nil
 *
 * defragment a file or directory
 *
 * Defragment a file or directory on a btrfs filesystem.
 * compress is one of zlib or lzo.
 * 
 * Optional arguments are supplied in the final hash
 * parameter, which is a hash of the argument name to its
 * value. Pass an empty {} for no optional arguments.
 *
 *
 * [Since] Added in version 1.29.22.
 *
 * [Feature] This function depends on the feature +btrfs+.  See also {#feature_available}[rdoc-ref:feature_available].
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_btrfs_filesystem_defragment}[http://libguestfs.org/guestfs.3.html#guestfs_btrfs_filesystem_defragment].
 */
VALUE
guestfs_int_ruby_btrfs_filesystem_defragment (int argc, VALUE *argv, VALUE gv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "btrfs_filesystem_defragment");

  if (argc < 1 || argc > 2)
    rb_raise (rb_eArgError, "expecting 1 or 2 arguments");

  volatile VALUE pathv = argv[0];
  volatile VALUE optargsv = argc > 1 ? argv[1] : rb_hash_new ();

  const char *path = StringValueCStr (pathv);

  Check_Type (optargsv, T_HASH);
  struct guestfs_btrfs_filesystem_defragment_argv optargs_s = { .bitmask = 0 };
  struct guestfs_btrfs_filesystem_defragment_argv *optargs = &optargs_s;
  volatile VALUE v;
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("flush")));
  if (v != Qnil) {
    optargs_s.flush = RTEST (v);
    optargs_s.bitmask |= GUESTFS_BTRFS_FILESYSTEM_DEFRAGMENT_FLUSH_BITMASK;
  }
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("compress")));
  if (v != Qnil) {
    optargs_s.compress = StringValueCStr (v);
    optargs_s.bitmask |= GUESTFS_BTRFS_FILESYSTEM_DEFRAGMENT_COMPRESS_BITMASK;
  }

  int r;

  r = guestfs_btrfs_filesystem_defragment_argv (g, path, optargs);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.btrfs_filesystem_resize(mountpoint, {optargs...}) -> nil
 *
 * resize a btrfs filesystem
 *
 * This command resizes a btrfs filesystem.
 * 
 * Note that unlike other resize calls, the filesystem has
 * to be mounted and the parameter is the mountpoint not
 * the device (this is a requirement of btrfs itself).
 * 
 * The optional parameters are:
 * 
 * "size"
 * The new size (in bytes) of the filesystem. If
 * omitted, the filesystem is resized to the maximum
 * size.
 * 
 * See also btrfs(8).
 * 
 * Optional arguments are supplied in the final hash
 * parameter, which is a hash of the argument name to its
 * value. Pass an empty {} for no optional arguments.
 *
 *
 * [Since] Added in version 1.11.17.
 *
 * [Feature] This function depends on the feature +btrfs+.  See also {#feature_available}[rdoc-ref:feature_available].
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_btrfs_filesystem_resize}[http://libguestfs.org/guestfs.3.html#guestfs_btrfs_filesystem_resize].
 */
VALUE
guestfs_int_ruby_btrfs_filesystem_resize (int argc, VALUE *argv, VALUE gv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "btrfs_filesystem_resize");

  if (argc < 1 || argc > 2)
    rb_raise (rb_eArgError, "expecting 1 or 2 arguments");

  volatile VALUE mountpointv = argv[0];
  volatile VALUE optargsv = argc > 1 ? argv[1] : rb_hash_new ();

  const char *mountpoint = StringValueCStr (mountpointv);

  Check_Type (optargsv, T_HASH);
  struct guestfs_btrfs_filesystem_resize_argv optargs_s = { .bitmask = 0 };
  struct guestfs_btrfs_filesystem_resize_argv *optargs = &optargs_s;
  volatile VALUE v;
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("size")));
  if (v != Qnil) {
    optargs_s.size = NUM2LL (v);
    optargs_s.bitmask |= GUESTFS_BTRFS_FILESYSTEM_RESIZE_SIZE_BITMASK;
  }

  int r;

  r = guestfs_btrfs_filesystem_resize_argv (g, mountpoint, optargs);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.btrfs_filesystem_sync(fs) -> nil
 *
 * sync a btrfs filesystem
 *
 * Force sync on the btrfs filesystem mounted at "fs".
 *
 *
 * [Since] Added in version 1.17.35.
 *
 * [Feature] This function depends on the feature +btrfs+.  See also {#feature_available}[rdoc-ref:feature_available].
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_btrfs_filesystem_sync}[http://libguestfs.org/guestfs.3.html#guestfs_btrfs_filesystem_sync].
 */
VALUE
guestfs_int_ruby_btrfs_filesystem_sync (VALUE gv, VALUE fsv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "btrfs_filesystem_sync");

  const char *fs = StringValueCStr (fsv);

  int r;

  r = guestfs_btrfs_filesystem_sync (g, fs);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.btrfs_image(source, image, {optargs...}) -> nil
 *
 * create an image of a btrfs filesystem
 *
 * This is used to create an image of a btrfs filesystem.
 * All data will be zeroed, but metadata and the like is
 * preserved.
 * 
 * Optional arguments are supplied in the final hash
 * parameter, which is a hash of the argument name to its
 * value. Pass an empty {} for no optional arguments.
 *
 *
 * [Since] Added in version 1.29.32.
 *
 * [Feature] This function depends on the feature +btrfs+.  See also {#feature_available}[rdoc-ref:feature_available].
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_btrfs_image}[http://libguestfs.org/guestfs.3.html#guestfs_btrfs_image].
 */
VALUE
guestfs_int_ruby_btrfs_image (int argc, VALUE *argv, VALUE gv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "btrfs_image");

  if (argc < 2 || argc > 3)
    rb_raise (rb_eArgError, "expecting 2 or 3 arguments");

  volatile VALUE sourcev = argv[0];
  volatile VALUE imagev = argv[1];
  volatile VALUE optargsv = argc > 2 ? argv[2] : rb_hash_new ();

  char **source;
  Check_Type (sourcev, T_ARRAY);
  {
    size_t i, len;
    len = RARRAY_LEN (sourcev);
    source = ALLOC_N (char *, len+1);
    for (i = 0; i < len; ++i) {
      volatile VALUE v = rb_ary_entry (sourcev, i);
      source[i] = StringValueCStr (v);
    }
    source[len] = NULL;
  }
  const char *image = StringValueCStr (imagev);

  Check_Type (optargsv, T_HASH);
  struct guestfs_btrfs_image_argv optargs_s = { .bitmask = 0 };
  struct guestfs_btrfs_image_argv *optargs = &optargs_s;
  volatile VALUE v;
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("compresslevel")));
  if (v != Qnil) {
    optargs_s.compresslevel = NUM2INT (v);
    optargs_s.bitmask |= GUESTFS_BTRFS_IMAGE_COMPRESSLEVEL_BITMASK;
  }

  int r;

  r = guestfs_btrfs_image_argv (g, source, image, optargs);
  free (source);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.btrfs_qgroup_destroy(qgroupid, subvolume) -> nil
 *
 * destroy a subvolume quota group
 *
 * Destroy a quota group.
 *
 *
 * [Since] Added in version 1.29.17.
 *
 * [Feature] This function depends on the feature +btrfs+.  See also {#feature_available}[rdoc-ref:feature_available].
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_btrfs_qgroup_destroy}[http://libguestfs.org/guestfs.3.html#guestfs_btrfs_qgroup_destroy].
 */
VALUE
guestfs_int_ruby_btrfs_qgroup_destroy (VALUE gv, VALUE qgroupidv, VALUE subvolumev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "btrfs_qgroup_destroy");

  const char *qgroupid = StringValueCStr (qgroupidv);
  const char *subvolume = StringValueCStr (subvolumev);

  int r;

  r = guestfs_btrfs_qgroup_destroy (g, qgroupid, subvolume);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.btrfs_subvolume_delete(subvolume) -> nil
 *
 * delete a btrfs subvolume or snapshot
 *
 * Delete the named btrfs subvolume or snapshot.
 *
 *
 * [Since] Added in version 1.17.35.
 *
 * [Feature] This function depends on the feature +btrfs+.  See also {#feature_available}[rdoc-ref:feature_available].
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_btrfs_subvolume_delete}[http://libguestfs.org/guestfs.3.html#guestfs_btrfs_subvolume_delete].
 */
VALUE
guestfs_int_ruby_btrfs_subvolume_delete (VALUE gv, VALUE subvolumev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "btrfs_subvolume_delete");

  const char *subvolume = StringValueCStr (subvolumev);

  int r;

  r = guestfs_btrfs_subvolume_delete (g, subvolume);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.btrfs_subvolume_list(fs) -> list
 *
 * list btrfs snapshots and subvolumes
 *
 * List the btrfs snapshots and subvolumes of the btrfs
 * filesystem which is mounted at "fs".
 *
 *
 * [Since] Added in version 1.17.35.
 *
 * [Feature] This function depends on the feature +btrfs+.  See also {#feature_available}[rdoc-ref:feature_available].
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_btrfs_subvolume_list}[http://libguestfs.org/guestfs.3.html#guestfs_btrfs_subvolume_list].
 */
VALUE
guestfs_int_ruby_btrfs_subvolume_list (VALUE gv, VALUE fsv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "btrfs_subvolume_list");

  const char *fs = StringValueCStr (fsv);

  struct guestfs_btrfssubvolume_list *r;

  r = guestfs_btrfs_subvolume_list (g, fs);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  volatile VALUE rv = rb_ary_new2 (r->len);
  size_t i;
  for (i = 0; i < r->len; ++i) {
    volatile VALUE hv = rb_hash_new ();
    rb_hash_aset (hv, rb_str_new2 ("btrfssubvolume_id"), ULL2NUM (r->val[i].btrfssubvolume_id));
    rb_hash_aset (hv, rb_str_new2 ("btrfssubvolume_top_level_id"), ULL2NUM (r->val[i].btrfssubvolume_top_level_id));
    rb_hash_aset (hv, rb_str_new2 ("btrfssubvolume_path"), rb_str_new2 (r->val[i].btrfssubvolume_path));
    rb_ary_push (rv, hv);
  }
  guestfs_free_btrfssubvolume_list (r);
  return rv;
}

/*
 * call-seq:
 *   g.btrfstune_enable_skinny_metadata_extent_refs(device) -> nil
 *
 * enable skinny metadata extent refs
 *
 * This enable skinny metadata extent refs.
 *
 *
 * [Since] Added in version 1.29.29.
 *
 * [Feature] This function depends on the feature +btrfs+.  See also {#feature_available}[rdoc-ref:feature_available].
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_btrfstune_enable_skinny_metadata_extent_refs}[http://libguestfs.org/guestfs.3.html#guestfs_btrfstune_enable_skinny_metadata_extent_refs].
 */
VALUE
guestfs_int_ruby_btrfstune_enable_skinny_metadata_extent_refs (VALUE gv, VALUE devicev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "btrfstune_enable_skinny_metadata_extent_refs");

  const char *device = StringValueCStr (devicev);

  int r;

  r = guestfs_btrfstune_enable_skinny_metadata_extent_refs (g, device);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.cap_get_file(path) -> string
 *
 * get the Linux capabilities attached to a file
 *
 * This function returns the Linux capabilities attached to
 * "path". The capabilities set is returned in text form
 * (see cap_to_text(3)).
 * 
 * If no capabilities are attached to a file, an empty
 * string is returned.
 *
 *
 * [Since] Added in version 1.19.63.
 *
 * [Feature] This function depends on the feature +linuxcaps+.  See also {#feature_available}[rdoc-ref:feature_available].
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_cap_get_file}[http://libguestfs.org/guestfs.3.html#guestfs_cap_get_file].
 */
VALUE
guestfs_int_ruby_cap_get_file (VALUE gv, VALUE pathv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "cap_get_file");

  const char *path = StringValueCStr (pathv);

  char *r;

  r = guestfs_cap_get_file (g, path);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  volatile VALUE rv = rb_str_new2 (r);
  free (r);
  return rv;
}

/*
 * call-seq:
 *   g.checksum(csumtype, path) -> string
 *
 * compute MD5, SHAx or CRC checksum of file
 *
 * This call computes the MD5, SHAx or CRC checksum of the
 * file named "path".
 * 
 * The type of checksum to compute is given by the
 * "csumtype" parameter which must have one of the
 * following values:
 * 
 * "crc"
 * Compute the cyclic redundancy check (CRC) specified
 * by POSIX for the "cksum" command.
 * 
 * "md5"
 * Compute the MD5 hash (using the "md5sum" program).
 * 
 * "sha1"
 * Compute the SHA1 hash (using the "sha1sum" program).
 * 
 * "sha224"
 * Compute the SHA224 hash (using the "sha224sum"
 * program).
 * 
 * "sha256"
 * Compute the SHA256 hash (using the "sha256sum"
 * program).
 * 
 * "sha384"
 * Compute the SHA384 hash (using the "sha384sum"
 * program).
 * 
 * "sha512"
 * Compute the SHA512 hash (using the "sha512sum"
 * program).
 * 
 * The checksum is returned as a printable string.
 * 
 * To get the checksum for a device, use
 * "g.checksum_device".
 * 
 * To get the checksums for many files, use
 * "g.checksums_out".
 *
 *
 * [Since] Added in version 1.0.2.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_checksum}[http://libguestfs.org/guestfs.3.html#guestfs_checksum].
 */
VALUE
guestfs_int_ruby_checksum (VALUE gv, VALUE csumtypev, VALUE pathv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "checksum");

  const char *csumtype = StringValueCStr (csumtypev);
  const char *path = StringValueCStr (pathv);

  char *r;

  r = guestfs_checksum (g, csumtype, path);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  volatile VALUE rv = rb_str_new2 (r);
  free (r);
  return rv;
}

/*
 * call-seq:
 *   g.chmod(mode, path) -> nil
 *
 * change file mode
 *
 * Change the mode (permissions) of "path" to "mode". Only
 * numeric modes are supported.
 * 
 * *Note*: When using this command from guestfish, "mode"
 * by default would be decimal, unless you prefix it with 0
 * to get octal, ie. use 0700 not 700.
 * 
 * The mode actually set is affected by the umask.
 *
 *
 * [Since] Added in version 0.8.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_chmod}[http://libguestfs.org/guestfs.3.html#guestfs_chmod].
 */
VALUE
guestfs_int_ruby_chmod (VALUE gv, VALUE modev, VALUE pathv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "chmod");

  int mode = NUM2INT (modev);
  const char *path = StringValueCStr (pathv);

  int r;

  r = guestfs_chmod (g, mode, path);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.copy_out(remotepath, localdir) -> nil
 *
 * copy remote files or directories out of an image
 *
 * "g.copy_out" copies remote files or directories
 * recursively out of the disk image, placing them on the
 * host disk in a local directory called "localdir" (which
 * must exist).
 * 
 * To download to the current directory, use "." as in:
 * 
 * C<g.copy_out> /home .
 * 
 * Wildcards cannot be used.
 *
 *
 * [Since] Added in version 1.29.24.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_copy_out}[http://libguestfs.org/guestfs.3.html#guestfs_copy_out].
 */
VALUE
guestfs_int_ruby_copy_out (VALUE gv, VALUE remotepathv, VALUE localdirv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "copy_out");

  const char *remotepath = StringValueCStr (remotepathv);
  const char *localdir = StringValueCStr (localdirv);

  int r;

  r = guestfs_copy_out (g, remotepath, localdir);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.disk_create(filename, format, size, {optargs...}) -> nil
 *
 * create a blank disk image
 *
 * Create a blank disk image called filename (a host file)
 * with format "format" (usually "raw" or "qcow2"). The
 * size is "size" bytes.
 * 
 * If used with the optional "backingfile" parameter, then
 * a snapshot is created on top of the backing file. In
 * this case, "size" must be passed as -1. The size of the
 * snapshot is the same as the size of the backing file,
 * which is discovered automatically. You are encouraged to
 * also pass "backingformat" to describe the format of
 * "backingfile".
 * 
 * If filename refers to a block device, then the device is
 * formatted. The "size" is ignored since block devices
 * have an intrinsic size.
 * 
 * The other optional parameters are:
 * 
 * "preallocation"
 * If format is "raw", then this can be either "off"
 * (or "sparse") or "full" to create a sparse or fully
 * allocated file respectively. The default is "off".
 * 
 * If format is "qcow2", then this can be "off" (or
 * "sparse"), "metadata" or "full". Preallocating
 * metadata can be faster when doing lots of writes,
 * but uses more space. The default is "off".
 * 
 * "compat"
 * "qcow2" only: Pass the string 1.1 to use the
 * advanced qcow2 format supported by qemu ≥ 1.1.
 * 
 * "clustersize"
 * "qcow2" only: Change the qcow2 cluster size. The
 * default is 65536 (bytes) and this setting may be any
 * power of two between 512 and 2097152.
 * 
 * Note that this call does not add the new disk to the
 * handle. You may need to call "g.add_drive_opts"
 * separately.
 * 
 * Optional arguments are supplied in the final hash
 * parameter, which is a hash of the argument name to its
 * value. Pass an empty {} for no optional arguments.
 *
 *
 * [Since] Added in version 1.25.31.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_disk_create}[http://libguestfs.org/guestfs.3.html#guestfs_disk_create].
 */
VALUE
guestfs_int_ruby_disk_create (int argc, VALUE *argv, VALUE gv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "disk_create");

  if (argc < 3 || argc > 4)
    rb_raise (rb_eArgError, "expecting 3 or 4 arguments");

  volatile VALUE filenamev = argv[0];
  volatile VALUE formatv = argv[1];
  volatile VALUE sizev = argv[2];
  volatile VALUE optargsv = argc > 3 ? argv[3] : rb_hash_new ();

  const char *filename = StringValueCStr (filenamev);
  const char *format = StringValueCStr (formatv);
  long long size = NUM2LL (sizev);

  Check_Type (optargsv, T_HASH);
  struct guestfs_disk_create_argv optargs_s = { .bitmask = 0 };
  struct guestfs_disk_create_argv *optargs = &optargs_s;
  volatile VALUE v;
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("backingfile")));
  if (v != Qnil) {
    optargs_s.backingfile = StringValueCStr (v);
    optargs_s.bitmask |= GUESTFS_DISK_CREATE_BACKINGFILE_BITMASK;
  }
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("backingformat")));
  if (v != Qnil) {
    optargs_s.backingformat = StringValueCStr (v);
    optargs_s.bitmask |= GUESTFS_DISK_CREATE_BACKINGFORMAT_BITMASK;
  }
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("preallocation")));
  if (v != Qnil) {
    optargs_s.preallocation = StringValueCStr (v);
    optargs_s.bitmask |= GUESTFS_DISK_CREATE_PREALLOCATION_BITMASK;
  }
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("compat")));
  if (v != Qnil) {
    optargs_s.compat = StringValueCStr (v);
    optargs_s.bitmask |= GUESTFS_DISK_CREATE_COMPAT_BITMASK;
  }
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("clustersize")));
  if (v != Qnil) {
    optargs_s.clustersize = NUM2INT (v);
    optargs_s.bitmask |= GUESTFS_DISK_CREATE_CLUSTERSIZE_BITMASK;
  }

  int r;

  r = guestfs_disk_create_argv (g, filename, format, size, optargs);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.dmesg() -> string
 *
 * return kernel messages
 *
 * This returns the kernel messages ("dmesg" output) from
 * the guest kernel. This is sometimes useful for extended
 * debugging of problems.
 * 
 * Another way to get the same information is to enable
 * verbose messages with "g.set_verbose" or by setting the
 * environment variable "LIBGUESTFS_DEBUG=1" before running
 * the program.
 *
 *
 * [Since] Added in version 1.0.18.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_dmesg}[http://libguestfs.org/guestfs.3.html#guestfs_dmesg].
 */
VALUE
guestfs_int_ruby_dmesg (VALUE gv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "dmesg");


  char *r;

  r = guestfs_dmesg (g);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  volatile VALUE rv = rb_str_new2 (r);
  free (r);
  return rv;
}

/*
 * call-seq:
 *   g.download_blocks(device, start, stop, filename, {optargs...}) -> nil
 *
 * download the given data units from the disk
 *
 * Download the data units from start address to stop from
 * the disk partition (eg. /dev/sda1) and save them as
 * filename on the local machine.
 * 
 * The use of this API on sparse disk image formats such as
 * QCOW, may result in large zero-filled files downloaded
 * on the host.
 * 
 * The size of a data unit varies across filesystem
 * implementations. On NTFS filesystems data units are
 * referred as clusters while on ExtX ones they are
 * referred as fragments.
 * 
 * If the optional "unallocated" flag is true (default is
 * false), only the unallocated blocks will be extracted.
 * This is useful to detect hidden data or to retrieve
 * deleted files which data units have not been overwritten
 * yet.
 * 
 * Optional arguments are supplied in the final hash
 * parameter, which is a hash of the argument name to its
 * value. Pass an empty {} for no optional arguments.
 *
 *
 * [Since] Added in version 1.33.45.
 *
 * [Feature] This function depends on the feature +sleuthkit+.  See also {#feature_available}[rdoc-ref:feature_available].
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_download_blocks}[http://libguestfs.org/guestfs.3.html#guestfs_download_blocks].
 */
VALUE
guestfs_int_ruby_download_blocks (int argc, VALUE *argv, VALUE gv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "download_blocks");

  if (argc < 4 || argc > 5)
    rb_raise (rb_eArgError, "expecting 4 or 5 arguments");

  volatile VALUE devicev = argv[0];
  volatile VALUE startv = argv[1];
  volatile VALUE stopv = argv[2];
  volatile VALUE filenamev = argv[3];
  volatile VALUE optargsv = argc > 4 ? argv[4] : rb_hash_new ();

  const char *device = StringValueCStr (devicev);
  long long start = NUM2LL (startv);
  long long stop = NUM2LL (stopv);
  const char *filename = StringValueCStr (filenamev);

  Check_Type (optargsv, T_HASH);
  struct guestfs_download_blocks_argv optargs_s = { .bitmask = 0 };
  struct guestfs_download_blocks_argv *optargs = &optargs_s;
  volatile VALUE v;
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("unallocated")));
  if (v != Qnil) {
    optargs_s.unallocated = RTEST (v);
    optargs_s.bitmask |= GUESTFS_DOWNLOAD_BLOCKS_UNALLOCATED_BITMASK;
  }

  int r;

  r = guestfs_download_blocks_argv (g, device, start, stop, filename, optargs);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.du(path) -> fixnum
 *
 * estimate file space usage
 *
 * This command runs the "du -s" command to estimate file
 * space usage for "path".
 * 
 * "path" can be a file or a directory. If "path" is a
 * directory then the estimate includes the contents of the
 * directory and all subdirectories (recursively).
 * 
 * The result is the estimated size in *kilobytes* (ie.
 * units of 1024 bytes).
 *
 *
 * [Since] Added in version 1.0.54.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_du}[http://libguestfs.org/guestfs.3.html#guestfs_du].
 */
VALUE
guestfs_int_ruby_du (VALUE gv, VALUE pathv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "du");

  const char *path = StringValueCStr (pathv);

  int64_t r;

  r = guestfs_du (g, path);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return ULL2NUM (r);
}

/*
 * call-seq:
 *   g.e2fsck_f(device) -> nil
 *
 * check an ext2/ext3 filesystem
 *
 * This runs "e2fsck -p -f device", ie. runs the ext2/ext3
 * filesystem checker on "device", noninteractively (*-p*),
 * even if the filesystem appears to be clean (*-f*).
 *
 *
 * [Since] Added in version 1.0.29.
 *
 * [Deprecated] In new code, use rdoc-ref:e2fsck instead.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_e2fsck_f}[http://libguestfs.org/guestfs.3.html#guestfs_e2fsck_f].
 */
VALUE
guestfs_int_ruby_e2fsck_f (VALUE gv, VALUE devicev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "e2fsck_f");

  const char *device = StringValueCStr (devicev);

  int r;

  r = guestfs_e2fsck_f (g, device);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.echo_daemon(words) -> string
 *
 * echo arguments back to the client
 *
 * This command concatenates the list of "words" passed
 * with single spaces between them and returns the
 * resulting string.
 * 
 * You can use this command to test the connection through
 * to the daemon.
 * 
 * See also "g.ping_daemon".
 *
 *
 * [Since] Added in version 1.0.69.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_echo_daemon}[http://libguestfs.org/guestfs.3.html#guestfs_echo_daemon].
 */
VALUE
guestfs_int_ruby_echo_daemon (VALUE gv, VALUE wordsv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "echo_daemon");

  char **words;
  Check_Type (wordsv, T_ARRAY);
  {
    size_t i, len;
    len = RARRAY_LEN (wordsv);
    words = ALLOC_N (char *, len+1);
    for (i = 0; i < len; ++i) {
      volatile VALUE v = rb_ary_entry (wordsv, i);
      words[i] = StringValueCStr (v);
    }
    words[len] = NULL;
  }

  char *r;

  r = guestfs_echo_daemon (g, words);
  free (words);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  volatile VALUE rv = rb_str_new2 (r);
  free (r);
  return rv;
}

/*
 * call-seq:
 *   g.equal(file1, file2) -> [True|False]
 *
 * test if two files have equal contents
 *
 * This compares the two files file1 and file2 and returns
 * true if their content is exactly equal, or false
 * otherwise.
 * 
 * The external cmp(1) program is used for the comparison.
 *
 *
 * [Since] Added in version 1.0.18.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_equal}[http://libguestfs.org/guestfs.3.html#guestfs_equal].
 */
VALUE
guestfs_int_ruby_equal (VALUE gv, VALUE file1v, VALUE file2v)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "equal");

  const char *file1 = StringValueCStr (file1v);
  const char *file2 = StringValueCStr (file2v);

  int r;

  r = guestfs_equal (g, file1, file2);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return INT2NUM (r);
}

/*
 * call-seq:
 *   g.fgrepi(pattern, path) -> list
 *
 * return lines matching a pattern
 *
 * This calls the external "fgrep -i" program and returns
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
 *         {guestfs_fgrepi}[http://libguestfs.org/guestfs.3.html#guestfs_fgrepi].
 */
VALUE
guestfs_int_ruby_fgrepi (VALUE gv, VALUE patternv, VALUE pathv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "fgrepi");

  const char *pattern = StringValueCStr (patternv);
  const char *path = StringValueCStr (pathv);

  char **r;

  r = guestfs_fgrepi (g, pattern, path);
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
 *   g.get_backend_setting(name) -> string
 *
 * get a single per-backend settings string
 *
 * Find a backend setting string which is either "name" or
 * begins with "name=". If "name", this returns the string
 * "1". If "name=", this returns the part after the equals
 * sign (which may be an empty string).
 * 
 * If no such setting is found, this function throws an
 * error. The errno (see "g.last_errno") will be "ESRCH" in
 * this case.
 * 
 * See "BACKEND" in guestfs(3), "BACKEND SETTINGS" in
 * guestfs(3).
 *
 *
 * [Since] Added in version 1.27.2.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_get_backend_setting}[http://libguestfs.org/guestfs.3.html#guestfs_get_backend_setting].
 */
VALUE
guestfs_int_ruby_get_backend_setting (VALUE gv, VALUE namev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "get_backend_setting");

  const char *name = StringValueCStr (namev);

  char *r;

  r = guestfs_get_backend_setting (g, name);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  volatile VALUE rv = rb_str_new2 (r);
  free (r);
  return rv;
}

/*
 * call-seq:
 *   g.get_backend_settings() -> list
 *
 * get per-backend settings
 *
 * Return the current backend settings.
 * 
 * This call returns all backend settings strings. If you
 * want to find a single backend setting, see
 * "g.get_backend_setting".
 * 
 * See "BACKEND" in guestfs(3), "BACKEND SETTINGS" in
 * guestfs(3).
 *
 *
 * [Since] Added in version 1.25.24.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_get_backend_settings}[http://libguestfs.org/guestfs.3.html#guestfs_get_backend_settings].
 */
VALUE
guestfs_int_ruby_get_backend_settings (VALUE gv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "get_backend_settings");


  char **r;

  r = guestfs_get_backend_settings (g);
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
 *   g.get_e2label(device) -> string
 *
 * get the ext2/3/4 filesystem label
 *
 * This returns the ext2/3/4 filesystem label of the
 * filesystem on "device".
 *
 *
 * [Since] Added in version 1.0.15.
 *
 * [Deprecated] In new code, use rdoc-ref:vfs_label instead.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_get_e2label}[http://libguestfs.org/guestfs.3.html#guestfs_get_e2label].
 */
VALUE
guestfs_int_ruby_get_e2label (VALUE gv, VALUE devicev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "get_e2label");

  const char *device = StringValueCStr (devicev);

  char *r;

  r = guestfs_get_e2label (g, device);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  volatile VALUE rv = rb_str_new2 (r);
  free (r);
  return rv;
}

/*
 * call-seq:
 *   g.get_recovery_proc() -> [True|False]
 *
 * get recovery process enabled flag
 *
 * Return the recovery process enabled flag.
 *
 *
 * [Since] Added in version 1.0.77.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_get_recovery_proc}[http://libguestfs.org/guestfs.3.html#guestfs_get_recovery_proc].
 */
VALUE
guestfs_int_ruby_get_recovery_proc (VALUE gv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "get_recovery_proc");


  int r;

  r = guestfs_get_recovery_proc (g);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return INT2NUM (r);
}

/*
 * call-seq:
 *   g.get_tmpdir() -> string
 *
 * get the temporary directory
 *
 * Get the directory used by the handle to store temporary
 * files.
 *
 *
 * [Since] Added in version 1.19.58.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_get_tmpdir}[http://libguestfs.org/guestfs.3.html#guestfs_get_tmpdir].
 */
VALUE
guestfs_int_ruby_get_tmpdir (VALUE gv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "get_tmpdir");


  char *r;

  r = guestfs_get_tmpdir (g);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  volatile VALUE rv = rb_str_new2 (r);
  free (r);
  return rv;
}

/*
 * call-seq:
 *   g.getcon() -> string
 *
 * get SELinux security context
 *
 * This gets the SELinux security context of the daemon.
 * 
 * See the documentation about SELINUX in guestfs(3), and
 * "g.setcon"
 *
 *
 * [Since] Added in version 1.0.67.
 *
 * [Deprecated] In new code, use rdoc-ref:selinux_relabel instead.
 *
 * [Feature] This function depends on the feature +selinux+.  See also {#feature_available}[rdoc-ref:feature_available].
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_getcon}[http://libguestfs.org/guestfs.3.html#guestfs_getcon].
 */
VALUE
guestfs_int_ruby_getcon (VALUE gv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "getcon");


  char *r;

  r = guestfs_getcon (g);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  volatile VALUE rv = rb_str_new2 (r);
  free (r);
  return rv;
}

/*
 * call-seq:
 *   g.getxattr(path, name) -> string
 *
 * get a single extended attribute
 *
 * Get a single extended attribute from file "path" named
 * "name". This call follows symlinks. If you want to
 * lookup an extended attribute for the symlink itself, use
 * "g.lgetxattr".
 * 
 * Normally it is better to get all extended attributes
 * from a file in one go by calling "g.getxattrs". However
 * some Linux filesystem implementations are buggy and do
 * not provide a way to list out attributes. For these
 * filesystems (notably ntfs-3g) you have to know the names
 * of the extended attributes you want in advance and call
 * this function.
 * 
 * Extended attribute values are blobs of binary data. If
 * there is no extended attribute named "name", this
 * returns an error.
 * 
 * See also: "g.getxattrs", "g.lgetxattr", attr(5).
 *
 *
 * [Since] Added in version 1.7.24.
 *
 * [Feature] This function depends on the feature +linuxxattrs+.  See also {#feature_available}[rdoc-ref:feature_available].
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_getxattr}[http://libguestfs.org/guestfs.3.html#guestfs_getxattr].
 */
VALUE
guestfs_int_ruby_getxattr (VALUE gv, VALUE pathv, VALUE namev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "getxattr");

  const char *path = StringValueCStr (pathv);
  const char *name = StringValueCStr (namev);

  char *r;
  size_t size;

  r = guestfs_getxattr (g, path, name, &size);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  volatile VALUE rv = rb_str_new (r, size);
  free (r);
  return rv;
}

/*
 * call-seq:
 *   g.hivex_close() -> nil
 *
 * close the current hivex handle
 *
 * Close the current hivex handle.
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
 *         {guestfs_hivex_close}[http://libguestfs.org/guestfs.3.html#guestfs_hivex_close].
 */
VALUE
guestfs_int_ruby_hivex_close (VALUE gv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "hivex_close");


  int r;

  r = guestfs_hivex_close (g);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.hivex_open(filename, {optargs...}) -> nil
 *
 * open a Windows Registry hive file
 *
 * Open the Windows Registry hive file named filename. If
 * there was any previous hivex handle associated with this
 * guestfs session, then it is closed.
 * 
 * This is a wrapper around the hivex(3) call of the same
 * name.
 * 
 * Optional arguments are supplied in the final hash
 * parameter, which is a hash of the argument name to its
 * value. Pass an empty {} for no optional arguments.
 *
 *
 * [Since] Added in version 1.19.35.
 *
 * [Feature] This function depends on the feature +hivex+.  See also {#feature_available}[rdoc-ref:feature_available].
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_hivex_open}[http://libguestfs.org/guestfs.3.html#guestfs_hivex_open].
 */
VALUE
guestfs_int_ruby_hivex_open (int argc, VALUE *argv, VALUE gv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "hivex_open");

  if (argc < 1 || argc > 2)
    rb_raise (rb_eArgError, "expecting 1 or 2 arguments");

  volatile VALUE filenamev = argv[0];
  volatile VALUE optargsv = argc > 1 ? argv[1] : rb_hash_new ();

  const char *filename = StringValueCStr (filenamev);

  Check_Type (optargsv, T_HASH);
  struct guestfs_hivex_open_argv optargs_s = { .bitmask = 0 };
  struct guestfs_hivex_open_argv *optargs = &optargs_s;
  volatile VALUE v;
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("verbose")));
  if (v != Qnil) {
    optargs_s.verbose = RTEST (v);
    optargs_s.bitmask |= GUESTFS_HIVEX_OPEN_VERBOSE_BITMASK;
  }
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("debug")));
  if (v != Qnil) {
    optargs_s.debug = RTEST (v);
    optargs_s.bitmask |= GUESTFS_HIVEX_OPEN_DEBUG_BITMASK;
  }
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("write")));
  if (v != Qnil) {
    optargs_s.write = RTEST (v);
    optargs_s.bitmask |= GUESTFS_HIVEX_OPEN_WRITE_BITMASK;
  }
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("unsafe")));
  if (v != Qnil) {
    optargs_s.unsafe = RTEST (v);
    optargs_s.bitmask |= GUESTFS_HIVEX_OPEN_UNSAFE_BITMASK;
  }

  int r;

  r = guestfs_hivex_open_argv (g, filename, optargs);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.hivex_value_utf8(valueh) -> string
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
 * [Since] Added in version 1.19.35.
 *
 * [Deprecated] In new code, use rdoc-ref:hivex_value_string instead.
 *
 * [Feature] This function depends on the feature +hivex+.  See also {#feature_available}[rdoc-ref:feature_available].
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_hivex_value_utf8}[http://libguestfs.org/guestfs.3.html#guestfs_hivex_value_utf8].
 */
VALUE
guestfs_int_ruby_hivex_value_utf8 (VALUE gv, VALUE valuehv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "hivex_value_utf8");

  long long valueh = NUM2LL (valuehv);

  char *r;

  r = guestfs_hivex_value_utf8 (g, valueh);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  volatile VALUE rv = rb_str_new2 (r);
  free (r);
  return rv;
}

/*
 * call-seq:
 *   g.inotify_add_watch(path, mask) -> fixnum
 *
 * add an inotify watch
 *
 * Watch "path" for the events listed in "mask".
 * 
 * Note that if "path" is a directory then events within
 * that directory are watched, but this does *not* happen
 * recursively (in subdirectories).
 * 
 * Note for non-C or non-Linux callers: the inotify events
 * are defined by the Linux kernel ABI and are listed in
 * /usr/include/sys/inotify.h.
 *
 *
 * [Since] Added in version 1.0.66.
 *
 * [Feature] This function depends on the feature +inotify+.  See also {#feature_available}[rdoc-ref:feature_available].
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_inotify_add_watch}[http://libguestfs.org/guestfs.3.html#guestfs_inotify_add_watch].
 */
VALUE
guestfs_int_ruby_inotify_add_watch (VALUE gv, VALUE pathv, VALUE maskv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "inotify_add_watch");

  const char *path = StringValueCStr (pathv);
  int mask = NUM2INT (maskv);

  int64_t r;

  r = guestfs_inotify_add_watch (g, path, mask);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return ULL2NUM (r);
}

/*
 * call-seq:
 *   g.inotify_init(maxevents) -> nil
 *
 * create an inotify handle
 *
 * This command creates a new inotify handle. The inotify
 * subsystem can be used to notify events which happen to
 * objects in the guest filesystem.
 * 
 * "maxevents" is the maximum number of events which will
 * be queued up between calls to "g.inotify_read" or
 * "g.inotify_files". If this is passed as 0, then the
 * kernel (or previously set) default is used. For Linux
 * 2.6.29 the default was 16384 events. Beyond this limit,
 * the kernel throws away events, but records the fact that
 * it threw them away by setting a flag "IN_Q_OVERFLOW" in
 * the returned structure list (see "g.inotify_read").
 * 
 * Before any events are generated, you have to add some
 * watches to the internal watch list. See:
 * "g.inotify_add_watch" and "g.inotify_rm_watch".
 * 
 * Queued up events should be read periodically by calling
 * "g.inotify_read" (or "g.inotify_files" which is just a
 * helpful wrapper around "g.inotify_read"). If you don't
 * read the events out often enough then you risk the
 * internal queue overflowing.
 * 
 * The handle should be closed after use by calling
 * "g.inotify_close". This also removes any watches
 * automatically.
 * 
 * See also inotify(7) for an overview of the inotify
 * interface as exposed by the Linux kernel, which is
 * roughly what we expose via libguestfs. Note that there
 * is one global inotify handle per libguestfs instance.
 *
 *
 * [Since] Added in version 1.0.66.
 *
 * [Feature] This function depends on the feature +inotify+.  See also {#feature_available}[rdoc-ref:feature_available].
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_inotify_init}[http://libguestfs.org/guestfs.3.html#guestfs_inotify_init].
 */
VALUE
guestfs_int_ruby_inotify_init (VALUE gv, VALUE maxeventsv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "inotify_init");

  int maxevents = NUM2INT (maxeventsv);

  int r;

  r = guestfs_inotify_init (g, maxevents);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.inspect_get_type(root) -> string
 *
 * get type of inspected operating system
 *
 * This returns the type of the inspected operating system.
 * Currently defined types are:
 * 
 * "linux"
 * Any Linux-based operating system.
 * 
 * "windows"
 * Any Microsoft Windows operating system.
 * 
 * "freebsd"
 * FreeBSD.
 * 
 * "netbsd"
 * NetBSD.
 * 
 * "openbsd"
 * OpenBSD.
 * 
 * "hurd"
 * GNU/Hurd.
 * 
 * "dos"
 * MS-DOS, FreeDOS and others.
 * 
 * "minix"
 * MINIX.
 * 
 * "unknown"
 * The operating system type could not be determined.
 * 
 * Future versions of libguestfs may return other strings
 * here. The caller should be prepared to handle any
 * string.
 * 
 * Please read "INSPECTION" in guestfs(3) for more details.
 *
 *
 * [Since] Added in version 1.5.3.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_inspect_get_type}[http://libguestfs.org/guestfs.3.html#guestfs_inspect_get_type].
 */
VALUE
guestfs_int_ruby_inspect_get_type (VALUE gv, VALUE rootv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "inspect_get_type");

  const char *root = StringValueCStr (rootv);

  char *r;

  r = guestfs_inspect_get_type (g, root);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  volatile VALUE rv = rb_str_new2 (r);
  free (r);
  return rv;
}

/*
 * call-seq:
 *   g.inspect_is_live(root) -> [True|False]
 *
 * get live flag for install disk
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
 *         {guestfs_inspect_is_live}[http://libguestfs.org/guestfs.3.html#guestfs_inspect_is_live].
 */
VALUE
guestfs_int_ruby_inspect_is_live (VALUE gv, VALUE rootv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "inspect_is_live");

  const char *root = StringValueCStr (rootv);

  int r;

  r = guestfs_inspect_is_live (g, root);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return INT2NUM (r);
}

/*
 * call-seq:
 *   g.internal_exit
 *
 * :nodoc:
 */
VALUE
guestfs_int_ruby_internal_exit (VALUE gv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "internal_exit");


  int r;

  r = guestfs_internal_exit (g);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.internal_test_only_optargs
 *
 * :nodoc:
 */
VALUE
guestfs_int_ruby_internal_test_only_optargs (int argc, VALUE *argv, VALUE gv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "internal_test_only_optargs");

  if (argc < 0 || argc > 1)
    rb_raise (rb_eArgError, "expecting 0 or 1 arguments");

  volatile VALUE optargsv = argc > 0 ? argv[0] : rb_hash_new ();


  Check_Type (optargsv, T_HASH);
  struct guestfs_internal_test_only_optargs_argv optargs_s = { .bitmask = 0 };
  struct guestfs_internal_test_only_optargs_argv *optargs = &optargs_s;
  volatile VALUE v;
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("test")));
  if (v != Qnil) {
    optargs_s.test = NUM2INT (v);
    optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_ONLY_OPTARGS_TEST_BITMASK;
  }

  int r;

  r = guestfs_internal_test_only_optargs_argv (g, optargs);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.internal_test_rconststringerr
 *
 * :nodoc:
 */
VALUE
guestfs_int_ruby_internal_test_rconststringerr (VALUE gv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "internal_test_rconststringerr");


  const char *r;

  r = guestfs_internal_test_rconststringerr (g);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return rb_str_new2 (r);
}

/*
 * call-seq:
 *   g.is_dir(path, {optargs...}) -> [True|False]
 *
 * test if a directory
 *
 * This returns "true" if and only if there is a directory
 * with the given "path" name. Note that it returns false
 * for other objects like files.
 * 
 * If the optional flag "followsymlinks" is true, then a
 * symlink (or chain of symlinks) that ends with a
 * directory also causes the function to return true.
 * 
 * See also "g.stat".
 * 
 * Optional arguments are supplied in the final hash
 * parameter, which is a hash of the argument name to its
 * value. Pass an empty {} for no optional arguments.
 *
 *
 * [Since] Added in version 0.8.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_is_dir}[http://libguestfs.org/guestfs.3.html#guestfs_is_dir].
 */
VALUE
guestfs_int_ruby_is_dir (int argc, VALUE *argv, VALUE gv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "is_dir");

  if (argc < 1 || argc > 2)
    rb_raise (rb_eArgError, "expecting 1 or 2 arguments");

  volatile VALUE pathv = argv[0];
  volatile VALUE optargsv = argc > 1 ? argv[1] : rb_hash_new ();

  const char *path = StringValueCStr (pathv);

  Check_Type (optargsv, T_HASH);
  struct guestfs_is_dir_opts_argv optargs_s = { .bitmask = 0 };
  struct guestfs_is_dir_opts_argv *optargs = &optargs_s;
  volatile VALUE v;
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("followsymlinks")));
  if (v != Qnil) {
    optargs_s.followsymlinks = RTEST (v);
    optargs_s.bitmask |= GUESTFS_IS_DIR_OPTS_FOLLOWSYMLINKS_BITMASK;
  }

  int r;

  r = guestfs_is_dir_opts_argv (g, path, optargs);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return INT2NUM (r);
}

/*
 * call-seq:
 *   g.is_file(path, {optargs...}) -> [True|False]
 *
 * test if a regular file
 *
 * This returns "true" if and only if there is a regular
 * file with the given "path" name. Note that it returns
 * false for other objects like directories.
 * 
 * If the optional flag "followsymlinks" is true, then a
 * symlink (or chain of symlinks) that ends with a file
 * also causes the function to return true.
 * 
 * See also "g.stat".
 * 
 * Optional arguments are supplied in the final hash
 * parameter, which is a hash of the argument name to its
 * value. Pass an empty {} for no optional arguments.
 *
 *
 * [Since] Added in version 0.8.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_is_file}[http://libguestfs.org/guestfs.3.html#guestfs_is_file].
 */
VALUE
guestfs_int_ruby_is_file (int argc, VALUE *argv, VALUE gv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "is_file");

  if (argc < 1 || argc > 2)
    rb_raise (rb_eArgError, "expecting 1 or 2 arguments");

  volatile VALUE pathv = argv[0];
  volatile VALUE optargsv = argc > 1 ? argv[1] : rb_hash_new ();

  const char *path = StringValueCStr (pathv);

  Check_Type (optargsv, T_HASH);
  struct guestfs_is_file_opts_argv optargs_s = { .bitmask = 0 };
  struct guestfs_is_file_opts_argv *optargs = &optargs_s;
  volatile VALUE v;
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("followsymlinks")));
  if (v != Qnil) {
    optargs_s.followsymlinks = RTEST (v);
    optargs_s.bitmask |= GUESTFS_IS_FILE_OPTS_FOLLOWSYMLINKS_BITMASK;
  }

  int r;

  r = guestfs_is_file_opts_argv (g, path, optargs);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return INT2NUM (r);
}

/*
 * call-seq:
 *   g.is_whole_device(device) -> [True|False]
 *
 * test if a device is a whole device
 *
 * This returns "true" if and only if "device" refers to a
 * whole block device. That is, not a partition or a
 * logical device.
 *
 *
 * [Since] Added in version 1.21.9.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_is_whole_device}[http://libguestfs.org/guestfs.3.html#guestfs_is_whole_device].
 */
VALUE
guestfs_int_ruby_is_whole_device (VALUE gv, VALUE devicev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "is_whole_device");

  const char *device = StringValueCStr (devicev);

  int r;

  r = guestfs_is_whole_device (g, device);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return INT2NUM (r);
}

/*
 * call-seq:
 *   g.is_zero_device(device) -> [True|False]
 *
 * test if a device contains all zero bytes
 *
 * This returns true iff the device exists and contains all
 * zero bytes.
 * 
 * Note that for large devices this can take a long time to
 * run.
 *
 *
 * [Since] Added in version 1.11.8.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_is_zero_device}[http://libguestfs.org/guestfs.3.html#guestfs_is_zero_device].
 */
VALUE
guestfs_int_ruby_is_zero_device (VALUE gv, VALUE devicev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "is_zero_device");

  const char *device = StringValueCStr (devicev);

  int r;

  r = guestfs_is_zero_device (g, device);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return INT2NUM (r);
}

/*
 * call-seq:
 *   g.journal_get_realtime_usec() -> fixnum
 *
 * get the timestamp of the current journal entry
 *
 * Get the realtime (wallclock) timestamp of the current
 * journal entry.
 *
 *
 * [Since] Added in version 1.27.18.
 *
 * [Feature] This function depends on the feature +journal+.  See also {#feature_available}[rdoc-ref:feature_available].
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_journal_get_realtime_usec}[http://libguestfs.org/guestfs.3.html#guestfs_journal_get_realtime_usec].
 */
VALUE
guestfs_int_ruby_journal_get_realtime_usec (VALUE gv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "journal_get_realtime_usec");


  int64_t r;

  r = guestfs_journal_get_realtime_usec (g);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return ULL2NUM (r);
}

/*
 * call-seq:
 *   g.journal_set_data_threshold(threshold) -> nil
 *
 * set the data threshold for reading journal entries
 *
 * Set the data threshold for reading journal entries. This
 * is a hint to the journal that it may truncate data
 * fields to this size when reading them (note also that it
 * may not truncate them). If you set this to 0, then the
 * threshold is unlimited.
 * 
 * See also "g.journal_get_data_threshold".
 *
 *
 * [Since] Added in version 1.23.11.
 *
 * [Feature] This function depends on the feature +journal+.  See also {#feature_available}[rdoc-ref:feature_available].
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_journal_set_data_threshold}[http://libguestfs.org/guestfs.3.html#guestfs_journal_set_data_threshold].
 */
VALUE
guestfs_int_ruby_journal_set_data_threshold (VALUE gv, VALUE thresholdv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "journal_set_data_threshold");

  long long threshold = NUM2LL (thresholdv);

  int r;

  r = guestfs_journal_set_data_threshold (g, threshold);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.launch() -> nil
 *
 * launch the backend
 *
 * You should call this after configuring the handle (eg.
 * adding drives) but before performing any actions.
 * 
 * Do not call "g.launch" twice on the same handle.
 * Although it will not give an error (for historical
 * reasons), the precise behaviour when you do this is not
 * well defined. Handles are very cheap to create, so
 * create a new one for each launch.
 *
 *
 * [Since] Added in version 0.3.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_launch}[http://libguestfs.org/guestfs.3.html#guestfs_launch].
 */
VALUE
guestfs_int_ruby_launch (VALUE gv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "launch");


  int r;

  r = guestfs_launch (g);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.ldmtool_remove_all() -> nil
 *
 * remove all Windows dynamic disk volumes
 *
 * This is essentially the opposite of
 * "g.ldmtool_create_all". It removes the device mapper
 * mappings for all Windows dynamic disk volumes
 *
 *
 * [Since] Added in version 1.20.0.
 *
 * [Feature] This function depends on the feature +ldm+.  See also {#feature_available}[rdoc-ref:feature_available].
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_ldmtool_remove_all}[http://libguestfs.org/guestfs.3.html#guestfs_ldmtool_remove_all].
 */
VALUE
guestfs_int_ruby_ldmtool_remove_all (VALUE gv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "ldmtool_remove_all");


  int r;

  r = guestfs_ldmtool_remove_all (g);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.ldmtool_volume_hint(diskgroup, volume) -> string
 *
 * return the hint field of a Windows dynamic disk volume
 *
 * Return the hint field of the volume named "volume" in
 * the disk group with GUID "diskgroup". This may not be
 * defined, in which case the empty string is returned. The
 * hint field is often, though not always, the name of a
 * Windows drive, eg. "E:".
 *
 *
 * [Since] Added in version 1.20.0.
 *
 * [Feature] This function depends on the feature +ldm+.  See also {#feature_available}[rdoc-ref:feature_available].
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_ldmtool_volume_hint}[http://libguestfs.org/guestfs.3.html#guestfs_ldmtool_volume_hint].
 */
VALUE
guestfs_int_ruby_ldmtool_volume_hint (VALUE gv, VALUE diskgroupv, VALUE volumev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "ldmtool_volume_hint");

  const char *diskgroup = StringValueCStr (diskgroupv);
  const char *volume = StringValueCStr (volumev);

  char *r;

  r = guestfs_ldmtool_volume_hint (g, diskgroup, volume);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  volatile VALUE rv = rb_str_new2 (r);
  free (r);
  return rv;
}

/*
 * call-seq:
 *   g.ldmtool_volume_type(diskgroup, volume) -> string
 *
 * return the type of a Windows dynamic disk volume
 *
 * Return the type of the volume named "volume" in the disk
 * group with GUID "diskgroup".
 * 
 * Possible volume types that can be returned here include:
 * "simple", "spanned", "striped", "mirrored", "raid5".
 * Other types may also be returned.
 *
 *
 * [Since] Added in version 1.20.0.
 *
 * [Feature] This function depends on the feature +ldm+.  See also {#feature_available}[rdoc-ref:feature_available].
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_ldmtool_volume_type}[http://libguestfs.org/guestfs.3.html#guestfs_ldmtool_volume_type].
 */
VALUE
guestfs_int_ruby_ldmtool_volume_type (VALUE gv, VALUE diskgroupv, VALUE volumev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "ldmtool_volume_type");

  const char *diskgroup = StringValueCStr (diskgroupv);
  const char *volume = StringValueCStr (volumev);

  char *r;

  r = guestfs_ldmtool_volume_type (g, diskgroup, volume);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  volatile VALUE rv = rb_str_new2 (r);
  free (r);
  return rv;
}

/*
 * call-seq:
 *   g.list_devices() -> list
 *
 * list the block devices
 *
 * List all the block devices.
 * 
 * The full block device names are returned, eg. /dev/sda.
 * 
 * See also "g.list_filesystems".
 *
 *
 * [Since] Added in version 0.4.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_list_devices}[http://libguestfs.org/guestfs.3.html#guestfs_list_devices].
 */
VALUE
guestfs_int_ruby_list_devices (VALUE gv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "list_devices");


  char **r;

  r = guestfs_list_devices (g);
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
 *   g.list_filesystems() -> hash
 *
 * list filesystems
 *
 * This inspection command looks for filesystems on
 * partitions, block devices and logical volumes, returning
 * a list of "mountables" containing filesystems and their
 * type.
 * 
 * The return value is a hash, where the keys are the
 * devices containing filesystems, and the values are the
 * filesystem types. For example:
 * 
 * "/dev/sda1" => "ntfs"
 * "/dev/sda2" => "ext2"
 * "/dev/vg_guest/lv_root" => "ext4"
 * "/dev/vg_guest/lv_swap" => "swap"
 * 
 * The key is not necessarily a block device. It may also
 * be an opaque ‘mountable’ string which can be passed to
 * "g.mount".
 * 
 * The value can have the special value "unknown", meaning
 * the content of the device is undetermined or empty.
 * "swap" means a Linux swap partition.
 * 
 * In libguestfs ≤ 1.36 this command ran other libguestfs
 * commands, which might have included "g.mount" and
 * "g.umount", and therefore you had to use this soon after
 * launch and only when nothing else was mounted. This
 * restriction is removed in libguestfs ≥ 1.38.
 * 
 * Not all of the filesystems returned will be mountable.
 * In particular, swap partitions are returned in the list.
 * Also this command does not check that each filesystem
 * found is valid and mountable, and some filesystems might
 * be mountable but require special options. Filesystems
 * may not all belong to a single logical operating system
 * (use "g.inspect_os" to look for OSes).
 *
 *
 * [Since] Added in version 1.5.15.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_list_filesystems}[http://libguestfs.org/guestfs.3.html#guestfs_list_filesystems].
 */
VALUE
guestfs_int_ruby_list_filesystems (VALUE gv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "list_filesystems");


  char **r;

  r = guestfs_list_filesystems (g);
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
 *   g.ls(directory) -> list
 *
 * list the files in a directory
 *
 * List the files in directory (relative to the root
 * directory, there is no cwd). The '.' and '..' entries
 * are not returned, but hidden files are shown.
 *
 *
 * [Since] Added in version 0.4.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_ls}[http://libguestfs.org/guestfs.3.html#guestfs_ls].
 */
VALUE
guestfs_int_ruby_ls (VALUE gv, VALUE directoryv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "ls");

  const char *directory = StringValueCStr (directoryv);

  char **r;

  r = guestfs_ls (g, directory);
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
 *   g.ls0(dir, filenames) -> nil
 *
 * get list of files in a directory
 *
 * This specialized command is used to get a listing of the
 * filenames in the directory "dir". The list of filenames
 * is written to the local file filenames (on the host).
 * 
 * In the output file, the filenames are separated by "\0"
 * characters.
 * 
 * "." and ".." are not returned. The filenames are not
 * sorted.
 *
 *
 * [Since] Added in version 1.19.32.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_ls0}[http://libguestfs.org/guestfs.3.html#guestfs_ls0].
 */
VALUE
guestfs_int_ruby_ls0 (VALUE gv, VALUE dirv, VALUE filenamesv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "ls0");

  const char *dir = StringValueCStr (dirv);
  const char *filenames = StringValueCStr (filenamesv);

  int r;

  r = guestfs_ls0 (g, dir, filenames);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.lstatns(path) -> hash
 *
 * get file information for a symbolic link
 *
 * Returns file information for the given "path".
 * 
 * This is the same as "g.statns" except that if "path" is
 * a symbolic link, then the link is stat-ed, not the file
 * it refers to.
 * 
 * This is the same as the lstat(2) system call.
 *
 *
 * [Since] Added in version 1.27.53.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_lstatns}[http://libguestfs.org/guestfs.3.html#guestfs_lstatns].
 */
VALUE
guestfs_int_ruby_lstatns (VALUE gv, VALUE pathv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "lstatns");

  const char *path = StringValueCStr (pathv);

  struct guestfs_statns *r;

  r = guestfs_lstatns (g, path);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  volatile VALUE rv = rb_hash_new ();
  rb_hash_aset (rv, rb_str_new2 ("st_dev"), LL2NUM (r->st_dev));
  rb_hash_aset (rv, rb_str_new2 ("st_ino"), LL2NUM (r->st_ino));
  rb_hash_aset (rv, rb_str_new2 ("st_mode"), LL2NUM (r->st_mode));
  rb_hash_aset (rv, rb_str_new2 ("st_nlink"), LL2NUM (r->st_nlink));
  rb_hash_aset (rv, rb_str_new2 ("st_uid"), LL2NUM (r->st_uid));
  rb_hash_aset (rv, rb_str_new2 ("st_gid"), LL2NUM (r->st_gid));
  rb_hash_aset (rv, rb_str_new2 ("st_rdev"), LL2NUM (r->st_rdev));
  rb_hash_aset (rv, rb_str_new2 ("st_size"), LL2NUM (r->st_size));
  rb_hash_aset (rv, rb_str_new2 ("st_blksize"), LL2NUM (r->st_blksize));
  rb_hash_aset (rv, rb_str_new2 ("st_blocks"), LL2NUM (r->st_blocks));
  rb_hash_aset (rv, rb_str_new2 ("st_atime_sec"), LL2NUM (r->st_atime_sec));
  rb_hash_aset (rv, rb_str_new2 ("st_atime_nsec"), LL2NUM (r->st_atime_nsec));
  rb_hash_aset (rv, rb_str_new2 ("st_mtime_sec"), LL2NUM (r->st_mtime_sec));
  rb_hash_aset (rv, rb_str_new2 ("st_mtime_nsec"), LL2NUM (r->st_mtime_nsec));
  rb_hash_aset (rv, rb_str_new2 ("st_ctime_sec"), LL2NUM (r->st_ctime_sec));
  rb_hash_aset (rv, rb_str_new2 ("st_ctime_nsec"), LL2NUM (r->st_ctime_nsec));
  rb_hash_aset (rv, rb_str_new2 ("st_spare1"), LL2NUM (r->st_spare1));
  rb_hash_aset (rv, rb_str_new2 ("st_spare2"), LL2NUM (r->st_spare2));
  rb_hash_aset (rv, rb_str_new2 ("st_spare3"), LL2NUM (r->st_spare3));
  rb_hash_aset (rv, rb_str_new2 ("st_spare4"), LL2NUM (r->st_spare4));
  rb_hash_aset (rv, rb_str_new2 ("st_spare5"), LL2NUM (r->st_spare5));
  rb_hash_aset (rv, rb_str_new2 ("st_spare6"), LL2NUM (r->st_spare6));
  guestfs_free_statns (r);
  return rv;
}

/*
 * call-seq:
 *   g.lxattrlist(path, names) -> list
 *
 * lgetxattr on multiple files
 *
 * This call allows you to get the extended attributes of
 * multiple files, where all files are in the directory
 * "path". "names" is the list of files from this
 * directory.
 * 
 * On return you get a flat list of xattr structs which
 * must be interpreted sequentially. The first xattr struct
 * always has a zero-length "attrname". "attrval" in this
 * struct is zero-length to indicate there was an error
 * doing "lgetxattr" for this file, *or* is a C string
 * which is a decimal number (the number of following
 * attributes for this file, which could be "0"). Then
 * after the first xattr struct are the zero or more
 * attributes for the first named file. This repeats for
 * the second and subsequent files.
 * 
 * This call is intended for programs that want to
 * efficiently list a directory contents without making
 * many round-trips. See also "g.lstatlist" for a similarly
 * efficient call for getting standard stats.
 *
 *
 * [Since] Added in version 1.0.77.
 *
 * [Feature] This function depends on the feature +linuxxattrs+.  See also {#feature_available}[rdoc-ref:feature_available].
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_lxattrlist}[http://libguestfs.org/guestfs.3.html#guestfs_lxattrlist].
 */
VALUE
guestfs_int_ruby_lxattrlist (VALUE gv, VALUE pathv, VALUE namesv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "lxattrlist");

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

  struct guestfs_xattr_list *r;

  r = guestfs_lxattrlist (g, path, names);
  free (names);
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
 *   g.mkdir_mode(path, mode) -> nil
 *
 * create a directory with a particular mode
 *
 * This command creates a directory, setting the initial
 * permissions of the directory to "mode".
 * 
 * For common Linux filesystems, the actual mode which is
 * set will be "mode & ~umask & 01777". Non-native-Linux
 * filesystems may interpret the mode in other ways.
 * 
 * See also "g.mkdir", "g.umask"
 *
 *
 * [Since] Added in version 1.0.77.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_mkdir_mode}[http://libguestfs.org/guestfs.3.html#guestfs_mkdir_mode].
 */
VALUE
guestfs_int_ruby_mkdir_mode (VALUE gv, VALUE pathv, VALUE modev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "mkdir_mode");

  const char *path = StringValueCStr (pathv);
  int mode = NUM2INT (modev);

  int r;

  r = guestfs_mkdir_mode (g, path, mode);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.mkdir_p(path) -> nil
 *
 * create a directory and parents
 *
 * Create a directory named "path", creating any parent
 * directories as necessary. This is like the "mkdir -p"
 * shell command.
 *
 *
 * [Since] Added in version 0.8.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_mkdir_p}[http://libguestfs.org/guestfs.3.html#guestfs_mkdir_p].
 */
VALUE
guestfs_int_ruby_mkdir_p (VALUE gv, VALUE pathv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "mkdir_p");

  const char *path = StringValueCStr (pathv);

  int r;

  r = guestfs_mkdir_p (g, path);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.mke2fs(device, {optargs...}) -> nil
 *
 * create an ext2/ext3/ext4 filesystem on device
 *
 * "mke2fs" is used to create an ext2, ext3, or ext4
 * filesystem on "device".
 * 
 * The optional "blockscount" is the size of the filesystem
 * in blocks. If omitted it defaults to the size of
 * "device". Note if the filesystem is too small to contain
 * a journal, "mke2fs" will silently create an ext2
 * filesystem instead.
 * 
 * Optional arguments are supplied in the final hash
 * parameter, which is a hash of the argument name to its
 * value. Pass an empty {} for no optional arguments.
 *
 *
 * [Since] Added in version 1.19.44.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_mke2fs}[http://libguestfs.org/guestfs.3.html#guestfs_mke2fs].
 */
VALUE
guestfs_int_ruby_mke2fs (int argc, VALUE *argv, VALUE gv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "mke2fs");

  if (argc < 1 || argc > 2)
    rb_raise (rb_eArgError, "expecting 1 or 2 arguments");

  volatile VALUE devicev = argv[0];
  volatile VALUE optargsv = argc > 1 ? argv[1] : rb_hash_new ();

  const char *device = StringValueCStr (devicev);

  Check_Type (optargsv, T_HASH);
  struct guestfs_mke2fs_argv optargs_s = { .bitmask = 0 };
  struct guestfs_mke2fs_argv *optargs = &optargs_s;
  volatile VALUE v;
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("blockscount")));
  if (v != Qnil) {
    optargs_s.blockscount = NUM2LL (v);
    optargs_s.bitmask |= GUESTFS_MKE2FS_BLOCKSCOUNT_BITMASK;
  }
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("blocksize")));
  if (v != Qnil) {
    optargs_s.blocksize = NUM2LL (v);
    optargs_s.bitmask |= GUESTFS_MKE2FS_BLOCKSIZE_BITMASK;
  }
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("fragsize")));
  if (v != Qnil) {
    optargs_s.fragsize = NUM2LL (v);
    optargs_s.bitmask |= GUESTFS_MKE2FS_FRAGSIZE_BITMASK;
  }
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("blockspergroup")));
  if (v != Qnil) {
    optargs_s.blockspergroup = NUM2LL (v);
    optargs_s.bitmask |= GUESTFS_MKE2FS_BLOCKSPERGROUP_BITMASK;
  }
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("numberofgroups")));
  if (v != Qnil) {
    optargs_s.numberofgroups = NUM2LL (v);
    optargs_s.bitmask |= GUESTFS_MKE2FS_NUMBEROFGROUPS_BITMASK;
  }
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("bytesperinode")));
  if (v != Qnil) {
    optargs_s.bytesperinode = NUM2LL (v);
    optargs_s.bitmask |= GUESTFS_MKE2FS_BYTESPERINODE_BITMASK;
  }
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("inodesize")));
  if (v != Qnil) {
    optargs_s.inodesize = NUM2LL (v);
    optargs_s.bitmask |= GUESTFS_MKE2FS_INODESIZE_BITMASK;
  }
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("journalsize")));
  if (v != Qnil) {
    optargs_s.journalsize = NUM2LL (v);
    optargs_s.bitmask |= GUESTFS_MKE2FS_JOURNALSIZE_BITMASK;
  }
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("numberofinodes")));
  if (v != Qnil) {
    optargs_s.numberofinodes = NUM2LL (v);
    optargs_s.bitmask |= GUESTFS_MKE2FS_NUMBEROFINODES_BITMASK;
  }
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("stridesize")));
  if (v != Qnil) {
    optargs_s.stridesize = NUM2LL (v);
    optargs_s.bitmask |= GUESTFS_MKE2FS_STRIDESIZE_BITMASK;
  }
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("stripewidth")));
  if (v != Qnil) {
    optargs_s.stripewidth = NUM2LL (v);
    optargs_s.bitmask |= GUESTFS_MKE2FS_STRIPEWIDTH_BITMASK;
  }
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("maxonlineresize")));
  if (v != Qnil) {
    optargs_s.maxonlineresize = NUM2LL (v);
    optargs_s.bitmask |= GUESTFS_MKE2FS_MAXONLINERESIZE_BITMASK;
  }
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("reservedblockspercentage")));
  if (v != Qnil) {
    optargs_s.reservedblockspercentage = NUM2INT (v);
    optargs_s.bitmask |= GUESTFS_MKE2FS_RESERVEDBLOCKSPERCENTAGE_BITMASK;
  }
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("mmpupdateinterval")));
  if (v != Qnil) {
    optargs_s.mmpupdateinterval = NUM2INT (v);
    optargs_s.bitmask |= GUESTFS_MKE2FS_MMPUPDATEINTERVAL_BITMASK;
  }
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("journaldevice")));
  if (v != Qnil) {
    optargs_s.journaldevice = StringValueCStr (v);
    optargs_s.bitmask |= GUESTFS_MKE2FS_JOURNALDEVICE_BITMASK;
  }
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("label")));
  if (v != Qnil) {
    optargs_s.label = StringValueCStr (v);
    optargs_s.bitmask |= GUESTFS_MKE2FS_LABEL_BITMASK;
  }
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("lastmounteddir")));
  if (v != Qnil) {
    optargs_s.lastmounteddir = StringValueCStr (v);
    optargs_s.bitmask |= GUESTFS_MKE2FS_LASTMOUNTEDDIR_BITMASK;
  }
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("creatoros")));
  if (v != Qnil) {
    optargs_s.creatoros = StringValueCStr (v);
    optargs_s.bitmask |= GUESTFS_MKE2FS_CREATOROS_BITMASK;
  }
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("fstype")));
  if (v != Qnil) {
    optargs_s.fstype = StringValueCStr (v);
    optargs_s.bitmask |= GUESTFS_MKE2FS_FSTYPE_BITMASK;
  }
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("usagetype")));
  if (v != Qnil) {
    optargs_s.usagetype = StringValueCStr (v);
    optargs_s.bitmask |= GUESTFS_MKE2FS_USAGETYPE_BITMASK;
  }
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("uuid")));
  if (v != Qnil) {
    optargs_s.uuid = StringValueCStr (v);
    optargs_s.bitmask |= GUESTFS_MKE2FS_UUID_BITMASK;
  }
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("forcecreate")));
  if (v != Qnil) {
    optargs_s.forcecreate = RTEST (v);
    optargs_s.bitmask |= GUESTFS_MKE2FS_FORCECREATE_BITMASK;
  }
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("writesbandgrouponly")));
  if (v != Qnil) {
    optargs_s.writesbandgrouponly = RTEST (v);
    optargs_s.bitmask |= GUESTFS_MKE2FS_WRITESBANDGROUPONLY_BITMASK;
  }
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("lazyitableinit")));
  if (v != Qnil) {
    optargs_s.lazyitableinit = RTEST (v);
    optargs_s.bitmask |= GUESTFS_MKE2FS_LAZYITABLEINIT_BITMASK;
  }
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("lazyjournalinit")));
  if (v != Qnil) {
    optargs_s.lazyjournalinit = RTEST (v);
    optargs_s.bitmask |= GUESTFS_MKE2FS_LAZYJOURNALINIT_BITMASK;
  }
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("testfs")));
  if (v != Qnil) {
    optargs_s.testfs = RTEST (v);
    optargs_s.bitmask |= GUESTFS_MKE2FS_TESTFS_BITMASK;
  }
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("discard")));
  if (v != Qnil) {
    optargs_s.discard = RTEST (v);
    optargs_s.bitmask |= GUESTFS_MKE2FS_DISCARD_BITMASK;
  }
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("quotatype")));
  if (v != Qnil) {
    optargs_s.quotatype = RTEST (v);
    optargs_s.bitmask |= GUESTFS_MKE2FS_QUOTATYPE_BITMASK;
  }
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("extent")));
  if (v != Qnil) {
    optargs_s.extent = RTEST (v);
    optargs_s.bitmask |= GUESTFS_MKE2FS_EXTENT_BITMASK;
  }
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("filetype")));
  if (v != Qnil) {
    optargs_s.filetype = RTEST (v);
    optargs_s.bitmask |= GUESTFS_MKE2FS_FILETYPE_BITMASK;
  }
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("flexbg")));
  if (v != Qnil) {
    optargs_s.flexbg = RTEST (v);
    optargs_s.bitmask |= GUESTFS_MKE2FS_FLEXBG_BITMASK;
  }
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("hasjournal")));
  if (v != Qnil) {
    optargs_s.hasjournal = RTEST (v);
    optargs_s.bitmask |= GUESTFS_MKE2FS_HASJOURNAL_BITMASK;
  }
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("journaldev")));
  if (v != Qnil) {
    optargs_s.journaldev = RTEST (v);
    optargs_s.bitmask |= GUESTFS_MKE2FS_JOURNALDEV_BITMASK;
  }
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("largefile")));
  if (v != Qnil) {
    optargs_s.largefile = RTEST (v);
    optargs_s.bitmask |= GUESTFS_MKE2FS_LARGEFILE_BITMASK;
  }
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("quota")));
  if (v != Qnil) {
    optargs_s.quota = RTEST (v);
    optargs_s.bitmask |= GUESTFS_MKE2FS_QUOTA_BITMASK;
  }
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("resizeinode")));
  if (v != Qnil) {
    optargs_s.resizeinode = RTEST (v);
    optargs_s.bitmask |= GUESTFS_MKE2FS_RESIZEINODE_BITMASK;
  }
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("sparsesuper")));
  if (v != Qnil) {
    optargs_s.sparsesuper = RTEST (v);
    optargs_s.bitmask |= GUESTFS_MKE2FS_SPARSESUPER_BITMASK;
  }
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("uninitbg")));
  if (v != Qnil) {
    optargs_s.uninitbg = RTEST (v);
    optargs_s.bitmask |= GUESTFS_MKE2FS_UNINITBG_BITMASK;
  }

  int r;

  r = guestfs_mke2fs_argv (g, device, optargs);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.mke2fs_JL(fstype, blocksize, device, label) -> nil
 *
 * make ext2/3/4 filesystem with external journal
 *
 * This creates an ext2/3/4 filesystem on "device" with an
 * external journal on the journal labeled "label".
 * 
 * See also "g.mke2journal_L".
 *
 *
 * [Since] Added in version 1.0.68.
 *
 * [Deprecated] In new code, use rdoc-ref:mke2fs instead.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_mke2fs_JL}[http://libguestfs.org/guestfs.3.html#guestfs_mke2fs_JL].
 */
VALUE
guestfs_int_ruby_mke2fs_JL (VALUE gv, VALUE fstypev, VALUE blocksizev, VALUE devicev, VALUE labelv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "mke2fs_JL");

  const char *fstype = StringValueCStr (fstypev);
  int blocksize = NUM2INT (blocksizev);
  const char *device = StringValueCStr (devicev);
  const char *label = StringValueCStr (labelv);

  int r;

  r = guestfs_mke2fs_JL (g, fstype, blocksize, device, label);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.mke2fs_JU(fstype, blocksize, device, uuid) -> nil
 *
 * make ext2/3/4 filesystem with external journal
 *
 * This creates an ext2/3/4 filesystem on "device" with an
 * external journal on the journal with UUID "uuid".
 * 
 * See also "g.mke2journal_U".
 *
 *
 * [Since] Added in version 1.0.68.
 *
 * [Deprecated] In new code, use rdoc-ref:mke2fs instead.
 *
 * [Feature] This function depends on the feature +linuxfsuuid+.  See also {#feature_available}[rdoc-ref:feature_available].
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_mke2fs_JU}[http://libguestfs.org/guestfs.3.html#guestfs_mke2fs_JU].
 */
VALUE
guestfs_int_ruby_mke2fs_JU (VALUE gv, VALUE fstypev, VALUE blocksizev, VALUE devicev, VALUE uuidv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "mke2fs_JU");

  const char *fstype = StringValueCStr (fstypev);
  int blocksize = NUM2INT (blocksizev);
  const char *device = StringValueCStr (devicev);
  const char *uuid = StringValueCStr (uuidv);

  int r;

  r = guestfs_mke2fs_JU (g, fstype, blocksize, device, uuid);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.mke2journal(blocksize, device) -> nil
 *
 * make ext2/3/4 external journal
 *
 * This creates an ext2 external journal on "device". It is
 * equivalent to the command:
 * 
 * mke2fs -O journal_dev -b blocksize device
 *
 *
 * [Since] Added in version 1.0.68.
 *
 * [Deprecated] In new code, use rdoc-ref:mke2fs instead.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_mke2journal}[http://libguestfs.org/guestfs.3.html#guestfs_mke2journal].
 */
VALUE
guestfs_int_ruby_mke2journal (VALUE gv, VALUE blocksizev, VALUE devicev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "mke2journal");

  int blocksize = NUM2INT (blocksizev);
  const char *device = StringValueCStr (devicev);

  int r;

  r = guestfs_mke2journal (g, blocksize, device);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.mknod_b(mode, devmajor, devminor, path) -> nil
 *
 * make block device node
 *
 * This call creates a block device node called "path" with
 * mode "mode" and device major/minor "devmajor" and
 * "devminor". It is just a convenient wrapper around
 * "g.mknod".
 * 
 * Unlike with "g.mknod", "mode" must contain only
 * permissions bits.
 * 
 * The mode actually set is affected by the umask.
 *
 *
 * [Since] Added in version 1.0.55.
 *
 * [Feature] This function depends on the feature +mknod+.  See also {#feature_available}[rdoc-ref:feature_available].
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_mknod_b}[http://libguestfs.org/guestfs.3.html#guestfs_mknod_b].
 */
VALUE
guestfs_int_ruby_mknod_b (VALUE gv, VALUE modev, VALUE devmajorv, VALUE devminorv, VALUE pathv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "mknod_b");

  int mode = NUM2INT (modev);
  int devmajor = NUM2INT (devmajorv);
  int devminor = NUM2INT (devminorv);
  const char *path = StringValueCStr (pathv);

  int r;

  r = guestfs_mknod_b (g, mode, devmajor, devminor, path);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.mount_local(localmountpoint, {optargs...}) -> nil
 *
 * mount on the local filesystem
 *
 * This call exports the libguestfs-accessible filesystem
 * to a local mountpoint (directory) called
 * "localmountpoint". Ordinary reads and writes to files
 * and directories under "localmountpoint" are redirected
 * through libguestfs.
 * 
 * If the optional "readonly" flag is set to true, then
 * writes to the filesystem return error "EROFS".
 * 
 * "options" is a comma-separated list of mount options.
 * See guestmount(1) for some useful options.
 * 
 * "cachetimeout" sets the timeout (in seconds) for cached
 * directory entries. The default is 60 seconds. See
 * guestmount(1) for further information.
 * 
 * If "debugcalls" is set to true, then additional
 * debugging information is generated for every FUSE call.
 * 
 * When "g.mount_local" returns, the filesystem is ready,
 * but is not processing requests (access to it will
 * block). You have to call "g.mount_local_run" to run the
 * main loop.
 * 
 * See "MOUNT LOCAL" in guestfs(3) for full documentation.
 * 
 * Optional arguments are supplied in the final hash
 * parameter, which is a hash of the argument name to its
 * value. Pass an empty {} for no optional arguments.
 *
 *
 * [Since] Added in version 1.17.22.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_mount_local}[http://libguestfs.org/guestfs.3.html#guestfs_mount_local].
 */
VALUE
guestfs_int_ruby_mount_local (int argc, VALUE *argv, VALUE gv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "mount_local");

  if (argc < 1 || argc > 2)
    rb_raise (rb_eArgError, "expecting 1 or 2 arguments");

  volatile VALUE localmountpointv = argv[0];
  volatile VALUE optargsv = argc > 1 ? argv[1] : rb_hash_new ();

  const char *localmountpoint = StringValueCStr (localmountpointv);

  Check_Type (optargsv, T_HASH);
  struct guestfs_mount_local_argv optargs_s = { .bitmask = 0 };
  struct guestfs_mount_local_argv *optargs = &optargs_s;
  volatile VALUE v;
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("readonly")));
  if (v != Qnil) {
    optargs_s.readonly = RTEST (v);
    optargs_s.bitmask |= GUESTFS_MOUNT_LOCAL_READONLY_BITMASK;
  }
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("options")));
  if (v != Qnil) {
    optargs_s.options = StringValueCStr (v);
    optargs_s.bitmask |= GUESTFS_MOUNT_LOCAL_OPTIONS_BITMASK;
  }
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("cachetimeout")));
  if (v != Qnil) {
    optargs_s.cachetimeout = NUM2INT (v);
    optargs_s.bitmask |= GUESTFS_MOUNT_LOCAL_CACHETIMEOUT_BITMASK;
  }
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("debugcalls")));
  if (v != Qnil) {
    optargs_s.debugcalls = RTEST (v);
    optargs_s.bitmask |= GUESTFS_MOUNT_LOCAL_DEBUGCALLS_BITMASK;
  }

  int r;

  r = guestfs_mount_local_argv (g, localmountpoint, optargs);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.ntfsresize_size(device, size) -> nil
 *
 * resize an NTFS filesystem (with size)
 *
 * This command is the same as "g.ntfsresize" except that
 * it allows you to specify the new size (in bytes)
 * explicitly.
 *
 *
 * [Since] Added in version 1.3.14.
 *
 * [Deprecated] In new code, use rdoc-ref:ntfsresize instead.
 *
 * [Feature] This function depends on the feature +ntfsprogs+.  See also {#feature_available}[rdoc-ref:feature_available].
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_ntfsresize_size}[http://libguestfs.org/guestfs.3.html#guestfs_ntfsresize_size].
 */
VALUE
guestfs_int_ruby_ntfsresize_size (VALUE gv, VALUE devicev, VALUE sizev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "ntfsresize_size");

  const char *device = StringValueCStr (devicev);
  long long size = NUM2LL (sizev);

  int r;

  r = guestfs_ntfsresize_size (g, device, size);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.part_del(device, partnum) -> nil
 *
 * delete a partition
 *
 * This command deletes the partition numbered "partnum" on
 * "device".
 * 
 * Note that in the case of MBR partitioning, deleting an
 * extended partition also deletes any logical partitions
 * it contains.
 *
 *
 * [Since] Added in version 1.3.2.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_part_del}[http://libguestfs.org/guestfs.3.html#guestfs_part_del].
 */
VALUE
guestfs_int_ruby_part_del (VALUE gv, VALUE devicev, VALUE partnumv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "part_del");

  const char *device = StringValueCStr (devicev);
  int partnum = NUM2INT (partnumv);

  int r;

  r = guestfs_part_del (g, device, partnum);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.part_get_gpt_type(device, partnum) -> string
 *
 * get the type GUID of a GPT partition
 *
 * Return the type GUID of numbered GPT partition
 * "partnum". For MBR partitions, return an appropriate
 * GUID corresponding to the MBR type. Behaviour is
 * undefined for other partition types.
 *
 *
 * [Since] Added in version 1.21.1.
 *
 * [Feature] This function depends on the feature +gdisk+.  See also {#feature_available}[rdoc-ref:feature_available].
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_part_get_gpt_type}[http://libguestfs.org/guestfs.3.html#guestfs_part_get_gpt_type].
 */
VALUE
guestfs_int_ruby_part_get_gpt_type (VALUE gv, VALUE devicev, VALUE partnumv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "part_get_gpt_type");

  const char *device = StringValueCStr (devicev);
  int partnum = NUM2INT (partnumv);

  char *r;

  r = guestfs_part_get_gpt_type (g, device, partnum);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  volatile VALUE rv = rb_str_new2 (r);
  free (r);
  return rv;
}

/*
 * call-seq:
 *   g.ping_daemon() -> nil
 *
 * ping the guest daemon
 *
 * This is a test probe into the guestfs daemon running
 * inside the libguestfs appliance. Calling this function
 * checks that the daemon responds to the ping message,
 * without affecting the daemon or attached block device(s)
 * in any other way.
 *
 *
 * [Since] Added in version 1.0.18.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_ping_daemon}[http://libguestfs.org/guestfs.3.html#guestfs_ping_daemon].
 */
VALUE
guestfs_int_ruby_ping_daemon (VALUE gv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "ping_daemon");


  int r;

  r = guestfs_ping_daemon (g);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.remove_drive(label) -> nil
 *
 * remove a disk image
 *
 * This function is conceptually the opposite of
 * "g.add_drive_opts". It removes the drive that was
 * previously added with label "label".
 * 
 * Note that in order to remove drives, you have to add
 * them with labels (see the optional "label" argument to
 * "g.add_drive_opts"). If you didn't use a label, then
 * they cannot be removed.
 * 
 * You can call this function before or after launching the
 * handle. If called after launch, if the backend supports
 * it, we try to hot unplug the drive: see "HOTPLUGGING" in
 * guestfs(3). The disk must not be in use (eg. mounted)
 * when you do this. We try to detect if the disk is in use
 * and stop you from doing this.
 *
 *
 * [Since] Added in version 1.19.49.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_remove_drive}[http://libguestfs.org/guestfs.3.html#guestfs_remove_drive].
 */
VALUE
guestfs_int_ruby_remove_drive (VALUE gv, VALUE labelv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "remove_drive");

  const char *label = StringValueCStr (labelv);

  int r;

  r = guestfs_remove_drive (g, label);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.rm(path) -> nil
 *
 * remove a file
 *
 * Remove the single file "path".
 *
 *
 * [Since] Added in version 0.8.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_rm}[http://libguestfs.org/guestfs.3.html#guestfs_rm].
 */
VALUE
guestfs_int_ruby_rm (VALUE gv, VALUE pathv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "rm");

  const char *path = StringValueCStr (pathv);

  int r;

  r = guestfs_rm (g, path);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.rmdir(path) -> nil
 *
 * remove a directory
 *
 * Remove the single directory "path".
 *
 *
 * [Since] Added in version 0.8.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_rmdir}[http://libguestfs.org/guestfs.3.html#guestfs_rmdir].
 */
VALUE
guestfs_int_ruby_rmdir (VALUE gv, VALUE pathv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "rmdir");

  const char *path = StringValueCStr (pathv);

  int r;

  r = guestfs_rmdir (g, path);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.rsync(src, dest, {optargs...}) -> nil
 *
 * synchronize the contents of two directories
 *
 * This call may be used to copy or synchronize two
 * directories under the same libguestfs handle. This uses
 * the rsync(1) program which uses a fast algorithm that
 * avoids copying files unnecessarily.
 * 
 * "src" and "dest" are the source and destination
 * directories. Files are copied from "src" to "dest".
 * 
 * The optional arguments are:
 * 
 * "archive"
 * Turns on archive mode. This is the same as passing
 * the *--archive* flag to "rsync".
 * 
 * "deletedest"
 * Delete files at the destination that do not exist at
 * the source.
 * 
 * Optional arguments are supplied in the final hash
 * parameter, which is a hash of the argument name to its
 * value. Pass an empty {} for no optional arguments.
 *
 *
 * [Since] Added in version 1.19.29.
 *
 * [Feature] This function depends on the feature +rsync+.  See also {#feature_available}[rdoc-ref:feature_available].
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_rsync}[http://libguestfs.org/guestfs.3.html#guestfs_rsync].
 */
VALUE
guestfs_int_ruby_rsync (int argc, VALUE *argv, VALUE gv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "rsync");

  if (argc < 2 || argc > 3)
    rb_raise (rb_eArgError, "expecting 2 or 3 arguments");

  volatile VALUE srcv = argv[0];
  volatile VALUE destv = argv[1];
  volatile VALUE optargsv = argc > 2 ? argv[2] : rb_hash_new ();

  const char *src = StringValueCStr (srcv);
  const char *dest = StringValueCStr (destv);

  Check_Type (optargsv, T_HASH);
  struct guestfs_rsync_argv optargs_s = { .bitmask = 0 };
  struct guestfs_rsync_argv *optargs = &optargs_s;
  volatile VALUE v;
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("archive")));
  if (v != Qnil) {
    optargs_s.archive = RTEST (v);
    optargs_s.bitmask |= GUESTFS_RSYNC_ARCHIVE_BITMASK;
  }
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("deletedest")));
  if (v != Qnil) {
    optargs_s.deletedest = RTEST (v);
    optargs_s.bitmask |= GUESTFS_RSYNC_DELETEDEST_BITMASK;
  }

  int r;

  r = guestfs_rsync_argv (g, src, dest, optargs);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.set_backend_settings(settings) -> nil
 *
 * replace per-backend settings strings
 *
 * Set a list of zero or more settings which are passed
 * through to the current backend. Each setting is a string
 * which is interpreted in a backend-specific way, or
 * ignored if not understood by the backend.
 * 
 * The default value is an empty list, unless the
 * environment variable "LIBGUESTFS_BACKEND_SETTINGS" was
 * set when the handle was created. This environment
 * variable contains a colon-separated list of settings.
 * 
 * This call replaces all backend settings. If you want to
 * replace a single backend setting, see
 * "g.set_backend_setting". If you want to clear a single
 * backend setting, see "g.clear_backend_setting".
 * 
 * See "BACKEND" in guestfs(3), "BACKEND SETTINGS" in
 * guestfs(3).
 *
 *
 * [Since] Added in version 1.25.24.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_set_backend_settings}[http://libguestfs.org/guestfs.3.html#guestfs_set_backend_settings].
 */
VALUE
guestfs_int_ruby_set_backend_settings (VALUE gv, VALUE settingsv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "set_backend_settings");

  char **settings;
  Check_Type (settingsv, T_ARRAY);
  {
    size_t i, len;
    len = RARRAY_LEN (settingsv);
    settings = ALLOC_N (char *, len+1);
    for (i = 0; i < len; ++i) {
      volatile VALUE v = rb_ary_entry (settingsv, i);
      settings[i] = StringValueCStr (v);
    }
    settings[len] = NULL;
  }

  int r;

  r = guestfs_set_backend_settings (g, settings);
  free (settings);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.set_hv(hv) -> nil
 *
 * set the hypervisor binary
 *
 * Set the hypervisor binary that we will use. The
 * hypervisor depends on the backend, but is usually the
 * location of the qemu/KVM hypervisor. For the uml
 * backend, it is the location of the "linux" or "vmlinux"
 * binary.
 * 
 * The default is chosen when the library was compiled by
 * the configure script.
 * 
 * You can also override this by setting the
 * "LIBGUESTFS_HV" environment variable.
 * 
 * Note that you should call this function as early as
 * possible after creating the handle. This is because some
 * pre-launch operations depend on testing qemu features
 * (by running "qemu -help"). If the qemu binary changes,
 * we don't retest features, and so you might see
 * inconsistent results. Using the environment variable
 * "LIBGUESTFS_HV" is safest of all since that picks the
 * qemu binary at the same time as the handle is created.
 *
 *
 * [Since] Added in version 1.23.17.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_set_hv}[http://libguestfs.org/guestfs.3.html#guestfs_set_hv].
 */
VALUE
guestfs_int_ruby_set_hv (VALUE gv, VALUE hvv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "set_hv");

  const char *hv = StringValueCStr (hvv);

  int r;

  r = guestfs_set_hv (g, hv);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.set_qemu(hv) -> nil
 *
 * set the hypervisor binary (usually qemu)
 *
 * Set the hypervisor binary (usually qemu) that we will
 * use.
 * 
 * The default is chosen when the library was compiled by
 * the configure script.
 * 
 * You can also override this by setting the
 * "LIBGUESTFS_HV" environment variable.
 * 
 * Setting "hv" to "NULL" restores the default qemu binary.
 * 
 * Note that you should call this function as early as
 * possible after creating the handle. This is because some
 * pre-launch operations depend on testing qemu features
 * (by running "qemu -help"). If the qemu binary changes,
 * we don't retest features, and so you might see
 * inconsistent results. Using the environment variable
 * "LIBGUESTFS_HV" is safest of all since that picks the
 * qemu binary at the same time as the handle is created.
 *
 *
 * [Since] Added in version 1.0.6.
 *
 * [Deprecated] In new code, use rdoc-ref:set_hv instead.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_set_qemu}[http://libguestfs.org/guestfs.3.html#guestfs_set_qemu].
 */
VALUE
guestfs_int_ruby_set_qemu (VALUE gv, VALUE hvv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "set_qemu");

  const char *hv = !NIL_P (hvv) ? StringValueCStr (hvv) : NULL;

  int r;

  r = guestfs_set_qemu (g, hv);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.set_recovery_proc(recoveryproc) -> nil
 *
 * enable or disable the recovery process
 *
 * If this is called with the parameter "false" then
 * "g.launch" does not create a recovery process. The
 * purpose of the recovery process is to stop runaway
 * hypervisor processes in the case where the main program
 * aborts abruptly.
 * 
 * This only has any effect if called before "g.launch",
 * and the default is true.
 * 
 * About the only time when you would want to disable this
 * is if the main process will fork itself into the
 * background ("daemonize" itself). In this case the
 * recovery process thinks that the main program has
 * disappeared and so kills the hypervisor, which is not
 * very helpful.
 *
 *
 * [Since] Added in version 1.0.77.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_set_recovery_proc}[http://libguestfs.org/guestfs.3.html#guestfs_set_recovery_proc].
 */
VALUE
guestfs_int_ruby_set_recovery_proc (VALUE gv, VALUE recoveryprocv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "set_recovery_proc");

  int recoveryproc = RTEST (recoveryprocv);

  int r;

  r = guestfs_set_recovery_proc (g, recoveryproc);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.set_uuid(device, uuid) -> nil
 *
 * set the filesystem UUID
 *
 * Set the filesystem UUID on "device" to "uuid". If this
 * fails and the errno is ENOTSUP, means that there is no
 * support for changing the UUID for the type of the
 * specified filesystem.
 * 
 * Only some filesystem types support setting UUIDs.
 * 
 * To read the UUID on a filesystem, call "g.vfs_uuid".
 *
 *
 * [Since] Added in version 1.23.10.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_set_uuid}[http://libguestfs.org/guestfs.3.html#guestfs_set_uuid].
 */
VALUE
guestfs_int_ruby_set_uuid (VALUE gv, VALUE devicev, VALUE uuidv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "set_uuid");

  const char *device = StringValueCStr (devicev);
  const char *uuid = StringValueCStr (uuidv);

  int r;

  r = guestfs_set_uuid (g, device, uuid);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.setcon(context) -> nil
 *
 * set SELinux security context
 *
 * This sets the SELinux security context of the daemon to
 * the string "context".
 * 
 * See the documentation about SELINUX in guestfs(3).
 *
 *
 * [Since] Added in version 1.0.67.
 *
 * [Deprecated] In new code, use rdoc-ref:selinux_relabel instead.
 *
 * [Feature] This function depends on the feature +selinux+.  See also {#feature_available}[rdoc-ref:feature_available].
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_setcon}[http://libguestfs.org/guestfs.3.html#guestfs_setcon].
 */
VALUE
guestfs_int_ruby_setcon (VALUE gv, VALUE contextv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "setcon");

  const char *context = StringValueCStr (contextv);

  int r;

  r = guestfs_setcon (g, context);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.statvfs(path) -> hash
 *
 * get file system statistics
 *
 * Returns file system statistics for any mounted file
 * system. "path" should be a file or directory in the
 * mounted file system (typically it is the mount point
 * itself, but it doesn't need to be).
 * 
 * This is the same as the statvfs(2) system call.
 *
 *
 * [Since] Added in version 1.9.2.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_statvfs}[http://libguestfs.org/guestfs.3.html#guestfs_statvfs].
 */
VALUE
guestfs_int_ruby_statvfs (VALUE gv, VALUE pathv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "statvfs");

  const char *path = StringValueCStr (pathv);

  struct guestfs_statvfs *r;

  r = guestfs_statvfs (g, path);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  volatile VALUE rv = rb_hash_new ();
  rb_hash_aset (rv, rb_str_new2 ("bsize"), LL2NUM (r->bsize));
  rb_hash_aset (rv, rb_str_new2 ("frsize"), LL2NUM (r->frsize));
  rb_hash_aset (rv, rb_str_new2 ("blocks"), LL2NUM (r->blocks));
  rb_hash_aset (rv, rb_str_new2 ("bfree"), LL2NUM (r->bfree));
  rb_hash_aset (rv, rb_str_new2 ("bavail"), LL2NUM (r->bavail));
  rb_hash_aset (rv, rb_str_new2 ("files"), LL2NUM (r->files));
  rb_hash_aset (rv, rb_str_new2 ("ffree"), LL2NUM (r->ffree));
  rb_hash_aset (rv, rb_str_new2 ("favail"), LL2NUM (r->favail));
  rb_hash_aset (rv, rb_str_new2 ("fsid"), LL2NUM (r->fsid));
  rb_hash_aset (rv, rb_str_new2 ("flag"), LL2NUM (r->flag));
  rb_hash_aset (rv, rb_str_new2 ("namemax"), LL2NUM (r->namemax));
  guestfs_free_statvfs (r);
  return rv;
}

/*
 * call-seq:
 *   g.strings(path) -> list
 *
 * print the printable strings in a file
 *
 * This runs the strings(1) command on a file and returns
 * the list of printable strings found.
 * 
 * The "strings" command has, in the past, had problems
 * with parsing untrusted files. These are mitigated in the
 * current version of libguestfs, but see "CVE-2014-8484"
 * in guestfs(3).
 * 
 * Because of the message protocol, there is a transfer
 * limit of somewhere between 2MB and 4MB. See "PROTOCOL
 * LIMITS" in guestfs(3).
 *
 *
 * [Since] Added in version 1.0.22.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_strings}[http://libguestfs.org/guestfs.3.html#guestfs_strings].
 */
VALUE
guestfs_int_ruby_strings (VALUE gv, VALUE pathv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "strings");

  const char *path = StringValueCStr (pathv);

  char **r;

  r = guestfs_strings (g, path);
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
 *   g.swapoff_label(label) -> nil
 *
 * disable swap on labeled swap partition
 *
 * This command disables the libguestfs appliance swap on
 * labeled swap partition.
 *
 *
 * [Since] Added in version 1.0.66.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_swapoff_label}[http://libguestfs.org/guestfs.3.html#guestfs_swapoff_label].
 */
VALUE
guestfs_int_ruby_swapoff_label (VALUE gv, VALUE labelv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "swapoff_label");

  const char *label = StringValueCStr (labelv);

  int r;

  r = guestfs_swapoff_label (g, label);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.swapoff_uuid(uuid) -> nil
 *
 * disable swap on swap partition by UUID
 *
 * This command disables the libguestfs appliance swap
 * partition with the given UUID.
 *
 *
 * [Since] Added in version 1.0.66.
 *
 * [Feature] This function depends on the feature +linuxfsuuid+.  See also {#feature_available}[rdoc-ref:feature_available].
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_swapoff_uuid}[http://libguestfs.org/guestfs.3.html#guestfs_swapoff_uuid].
 */
VALUE
guestfs_int_ruby_swapoff_uuid (VALUE gv, VALUE uuidv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "swapoff_uuid");

  const char *uuid = StringValueCStr (uuidv);

  int r;

  r = guestfs_swapoff_uuid (g, uuid);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.tar_in(tarfile, directory, {optargs...}) -> nil
 *
 * unpack tarfile to directory
 *
 * This command uploads and unpacks local file "tarfile"
 * into directory.
 * 
 * The optional "compress" flag controls compression. If
 * not given, then the input should be an uncompressed tar
 * file. Otherwise one of the following strings may be
 * given to select the compression type of the input file:
 * "compress", "gzip", "bzip2", "xz", "lzop". (Note that
 * not all builds of libguestfs will support all of these
 * compression types).
 * 
 * The other optional arguments are:
 * 
 * "xattrs"
 * If set to true, extended attributes are restored
 * from the tar file.
 * 
 * "selinux"
 * If set to true, SELinux contexts are restored from
 * the tar file.
 * 
 * "acls"
 * If set to true, POSIX ACLs are restored from the tar
 * file.
 * 
 * Optional arguments are supplied in the final hash
 * parameter, which is a hash of the argument name to its
 * value. Pass an empty {} for no optional arguments.
 *
 *
 * [Since] Added in version 1.0.3.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_tar_in}[http://libguestfs.org/guestfs.3.html#guestfs_tar_in].
 */
VALUE
guestfs_int_ruby_tar_in (int argc, VALUE *argv, VALUE gv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "tar_in");

  if (argc < 2 || argc > 3)
    rb_raise (rb_eArgError, "expecting 2 or 3 arguments");

  volatile VALUE tarfilev = argv[0];
  volatile VALUE directoryv = argv[1];
  volatile VALUE optargsv = argc > 2 ? argv[2] : rb_hash_new ();

  const char *tarfile = StringValueCStr (tarfilev);
  const char *directory = StringValueCStr (directoryv);

  Check_Type (optargsv, T_HASH);
  struct guestfs_tar_in_opts_argv optargs_s = { .bitmask = 0 };
  struct guestfs_tar_in_opts_argv *optargs = &optargs_s;
  volatile VALUE v;
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("compress")));
  if (v != Qnil) {
    optargs_s.compress = StringValueCStr (v);
    optargs_s.bitmask |= GUESTFS_TAR_IN_OPTS_COMPRESS_BITMASK;
  }
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("xattrs")));
  if (v != Qnil) {
    optargs_s.xattrs = RTEST (v);
    optargs_s.bitmask |= GUESTFS_TAR_IN_OPTS_XATTRS_BITMASK;
  }
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("selinux")));
  if (v != Qnil) {
    optargs_s.selinux = RTEST (v);
    optargs_s.bitmask |= GUESTFS_TAR_IN_OPTS_SELINUX_BITMASK;
  }
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("acls")));
  if (v != Qnil) {
    optargs_s.acls = RTEST (v);
    optargs_s.bitmask |= GUESTFS_TAR_IN_OPTS_ACLS_BITMASK;
  }

  int r;

  r = guestfs_tar_in_opts_argv (g, tarfile, directory, optargs);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.truncate(path) -> nil
 *
 * truncate a file to zero size
 *
 * This command truncates "path" to a zero-length file. The
 * file must exist already.
 *
 *
 * [Since] Added in version 1.0.77.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_truncate}[http://libguestfs.org/guestfs.3.html#guestfs_truncate].
 */
VALUE
guestfs_int_ruby_truncate (VALUE gv, VALUE pathv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "truncate");

  const char *path = StringValueCStr (pathv);

  int r;

  r = guestfs_truncate (g, path);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.tune2fs(device, {optargs...}) -> nil
 *
 * adjust ext2/ext3/ext4 filesystem parameters
 *
 * This call allows you to adjust various filesystem
 * parameters of an ext2/ext3/ext4 filesystem called
 * "device".
 * 
 * The optional parameters are:
 * 
 * "force"
 * Force tune2fs to complete the operation even in the
 * face of errors. This is the same as the tune2fs "-f"
 * option.
 * 
 * "maxmountcount"
 * Set the number of mounts after which the filesystem
 * is checked by e2fsck(8). If this is 0 then the
 * number of mounts is disregarded. This is the same as
 * the tune2fs "-c" option.
 * 
 * "mountcount"
 * Set the number of times the filesystem has been
 * mounted. This is the same as the tune2fs "-C"
 * option.
 * 
 * "errorbehavior"
 * Change the behavior of the kernel code when errors
 * are detected. Possible values currently are:
 * "continue", "remount-ro", "panic". In practice these
 * options don't really make any difference,
 * particularly for write errors.
 * 
 * This is the same as the tune2fs "-e" option.
 * 
 * "group"
 * Set the group which can use reserved filesystem
 * blocks. This is the same as the tune2fs "-g" option
 * except that it can only be specified as a number.
 * 
 * "intervalbetweenchecks"
 * Adjust the maximal time between two filesystem
 * checks (in seconds). If the option is passed as 0
 * then time-dependent checking is disabled.
 * 
 * This is the same as the tune2fs "-i" option.
 * 
 * "reservedblockspercentage"
 * Set the percentage of the filesystem which may only
 * be allocated by privileged processes. This is the
 * same as the tune2fs "-m" option.
 * 
 * "lastmounteddirectory"
 * Set the last mounted directory. This is the same as
 * the tune2fs "-M" option.
 * 
 * "reservedblockscount" Set the number of reserved
 * filesystem blocks. This is the same as the tune2fs "-r"
 * option.
 * "user"
 * Set the user who can use the reserved filesystem
 * blocks. This is the same as the tune2fs "-u" option
 * except that it can only be specified as a number.
 * 
 * To get the current values of filesystem parameters, see
 * "g.tune2fs_l". For precise details of how tune2fs works,
 * see the tune2fs(8) man page.
 * 
 * Optional arguments are supplied in the final hash
 * parameter, which is a hash of the argument name to its
 * value. Pass an empty {} for no optional arguments.
 *
 *
 * [Since] Added in version 1.15.4.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_tune2fs}[http://libguestfs.org/guestfs.3.html#guestfs_tune2fs].
 */
VALUE
guestfs_int_ruby_tune2fs (int argc, VALUE *argv, VALUE gv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "tune2fs");

  if (argc < 1 || argc > 2)
    rb_raise (rb_eArgError, "expecting 1 or 2 arguments");

  volatile VALUE devicev = argv[0];
  volatile VALUE optargsv = argc > 1 ? argv[1] : rb_hash_new ();

  const char *device = StringValueCStr (devicev);

  Check_Type (optargsv, T_HASH);
  struct guestfs_tune2fs_argv optargs_s = { .bitmask = 0 };
  struct guestfs_tune2fs_argv *optargs = &optargs_s;
  volatile VALUE v;
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("force")));
  if (v != Qnil) {
    optargs_s.force = RTEST (v);
    optargs_s.bitmask |= GUESTFS_TUNE2FS_FORCE_BITMASK;
  }
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("maxmountcount")));
  if (v != Qnil) {
    optargs_s.maxmountcount = NUM2INT (v);
    optargs_s.bitmask |= GUESTFS_TUNE2FS_MAXMOUNTCOUNT_BITMASK;
  }
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("mountcount")));
  if (v != Qnil) {
    optargs_s.mountcount = NUM2INT (v);
    optargs_s.bitmask |= GUESTFS_TUNE2FS_MOUNTCOUNT_BITMASK;
  }
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("errorbehavior")));
  if (v != Qnil) {
    optargs_s.errorbehavior = StringValueCStr (v);
    optargs_s.bitmask |= GUESTFS_TUNE2FS_ERRORBEHAVIOR_BITMASK;
  }
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("group")));
  if (v != Qnil) {
    optargs_s.group = NUM2LL (v);
    optargs_s.bitmask |= GUESTFS_TUNE2FS_GROUP_BITMASK;
  }
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("intervalbetweenchecks")));
  if (v != Qnil) {
    optargs_s.intervalbetweenchecks = NUM2INT (v);
    optargs_s.bitmask |= GUESTFS_TUNE2FS_INTERVALBETWEENCHECKS_BITMASK;
  }
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("reservedblockspercentage")));
  if (v != Qnil) {
    optargs_s.reservedblockspercentage = NUM2INT (v);
    optargs_s.bitmask |= GUESTFS_TUNE2FS_RESERVEDBLOCKSPERCENTAGE_BITMASK;
  }
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("lastmounteddirectory")));
  if (v != Qnil) {
    optargs_s.lastmounteddirectory = StringValueCStr (v);
    optargs_s.bitmask |= GUESTFS_TUNE2FS_LASTMOUNTEDDIRECTORY_BITMASK;
  }
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("reservedblockscount")));
  if (v != Qnil) {
    optargs_s.reservedblockscount = NUM2LL (v);
    optargs_s.bitmask |= GUESTFS_TUNE2FS_RESERVEDBLOCKSCOUNT_BITMASK;
  }
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("user")));
  if (v != Qnil) {
    optargs_s.user = NUM2LL (v);
    optargs_s.bitmask |= GUESTFS_TUNE2FS_USER_BITMASK;
  }

  int r;

  r = guestfs_tune2fs_argv (g, device, optargs);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.upload(filename, remotefilename) -> nil
 *
 * upload a file from the local machine
 *
 * Upload local file filename to remotefilename on the
 * filesystem.
 * 
 * filename can also be a named pipe.
 * 
 * See also "g.download".
 *
 *
 * [Since] Added in version 1.0.2.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_upload}[http://libguestfs.org/guestfs.3.html#guestfs_upload].
 */
VALUE
guestfs_int_ruby_upload (VALUE gv, VALUE filenamev, VALUE remotefilenamev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "upload");

  const char *filename = StringValueCStr (filenamev);
  const char *remotefilename = StringValueCStr (remotefilenamev);

  int r;

  r = guestfs_upload (g, filename, remotefilename);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.utimens(path, atsecs, atnsecs, mtsecs, mtnsecs) -> nil
 *
 * set timestamp of a file with nanosecond precision
 *
 * This command sets the timestamps of a file with
 * nanosecond precision.
 * 
 * "atsecs, atnsecs" are the last access time (atime) in
 * secs and nanoseconds from the epoch.
 * 
 * "mtsecs, mtnsecs" are the last modification time (mtime)
 * in secs and nanoseconds from the epoch.
 * 
 * If the *nsecs field contains the special value -1 then
 * the corresponding timestamp is set to the current time.
 * (The *secs field is ignored in this case).
 * 
 * If the *nsecs field contains the special value -2 then
 * the corresponding timestamp is left unchanged. (The
 * *secs field is ignored in this case).
 *
 *
 * [Since] Added in version 1.0.77.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_utimens}[http://libguestfs.org/guestfs.3.html#guestfs_utimens].
 */
VALUE
guestfs_int_ruby_utimens (VALUE gv, VALUE pathv, VALUE atsecsv, VALUE atnsecsv, VALUE mtsecsv, VALUE mtnsecsv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "utimens");

  const char *path = StringValueCStr (pathv);
  long long atsecs = NUM2LL (atsecsv);
  long long atnsecs = NUM2LL (atnsecsv);
  long long mtsecs = NUM2LL (mtsecsv);
  long long mtnsecs = NUM2LL (mtnsecsv);

  int r;

  r = guestfs_utimens (g, path, atsecs, atnsecs, mtsecs, mtnsecs);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.version() -> hash
 *
 * get the library version number
 *
 * Return the libguestfs version number that the program is
 * linked against.
 * 
 * Note that because of dynamic linking this is not
 * necessarily the version of libguestfs that you compiled
 * against. You can compile the program, and then at
 * runtime dynamically link against a completely different
 * libguestfs.so library.
 * 
 * This call was added in version 1.0.58. In previous
 * versions of libguestfs there was no way to get the
 * version number. From C code you can use dynamic linker
 * functions to find out if this symbol exists (if it
 * doesn't, then it’s an earlier version).
 * 
 * The call returns a structure with four elements. The
 * first three ("major", "minor" and "release") are numbers
 * and correspond to the usual version triplet. The fourth
 * element ("extra") is a string and is normally empty, but
 * may be used for distro-specific information.
 * 
 * To construct the original version string:
 * "$major.$minor.$release$extra"
 * 
 * See also: "LIBGUESTFS VERSION NUMBERS" in guestfs(3).
 * 
 * *Note:* Don't use this call to test for availability of
 * features. In enterprise distributions we backport
 * features from later versions into earlier versions,
 * making this an unreliable way to test for features. Use
 * "g.available" or "g.feature_available" instead.
 *
 *
 * [Since] Added in version 1.0.58.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_version}[http://libguestfs.org/guestfs.3.html#guestfs_version].
 */
VALUE
guestfs_int_ruby_version (VALUE gv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "version");


  struct guestfs_version *r;

  r = guestfs_version (g);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  volatile VALUE rv = rb_hash_new ();
  rb_hash_aset (rv, rb_str_new2 ("major"), LL2NUM (r->major));
  rb_hash_aset (rv, rb_str_new2 ("minor"), LL2NUM (r->minor));
  rb_hash_aset (rv, rb_str_new2 ("release"), LL2NUM (r->release));
  rb_hash_aset (rv, rb_str_new2 ("extra"), rb_str_new2 (r->extra));
  guestfs_free_version (r);
  return rv;
}

/*
 * call-seq:
 *   g.vfs_minimum_size(mountable) -> fixnum
 *
 * get minimum filesystem size
 *
 * Get the minimum size of filesystem in bytes. This is the
 * minimum possible size for filesystem shrinking.
 * 
 * If getting minimum size of specified filesystem is not
 * supported, this will fail and set errno as ENOTSUP.
 * 
 * See also ntfsresize(8), resize2fs(8), btrfs(8),
 * xfs_info(8).
 *
 *
 * [Since] Added in version 1.31.18.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_vfs_minimum_size}[http://libguestfs.org/guestfs.3.html#guestfs_vfs_minimum_size].
 */
VALUE
guestfs_int_ruby_vfs_minimum_size (VALUE gv, VALUE mountablev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "vfs_minimum_size");

  const char *mountable = StringValueCStr (mountablev);

  int64_t r;

  r = guestfs_vfs_minimum_size (g, mountable);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return ULL2NUM (r);
}

/*
 * call-seq:
 *   g.vfs_uuid(mountable) -> string
 *
 * get the filesystem UUID
 *
 * This returns the filesystem UUID of the filesystem on
 * "mountable".
 * 
 * If the filesystem does not have a UUID, this returns the
 * empty string.
 * 
 * To find a filesystem from the UUID, use "g.findfs_uuid".
 *
 *
 * [Since] Added in version 1.3.18.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_vfs_uuid}[http://libguestfs.org/guestfs.3.html#guestfs_vfs_uuid].
 */
VALUE
guestfs_int_ruby_vfs_uuid (VALUE gv, VALUE mountablev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "vfs_uuid");

  const char *mountable = StringValueCStr (mountablev);

  char *r;

  r = guestfs_vfs_uuid (g, mountable);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  volatile VALUE rv = rb_str_new2 (r);
  free (r);
  return rv;
}

/*
 * call-seq:
 *   g.vgs() -> list
 *
 * list the LVM volume groups (VGs)
 *
 * List all the volumes groups detected. This is the
 * equivalent of the vgs(8) command.
 * 
 * This returns a list of just the volume group names that
 * were detected (eg. "VolGroup00").
 * 
 * See also "g.vgs_full".
 *
 *
 * [Since] Added in version 0.4.
 *
 * [Feature] This function depends on the feature +lvm2+.  See also {#feature_available}[rdoc-ref:feature_available].
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_vgs}[http://libguestfs.org/guestfs.3.html#guestfs_vgs].
 */
VALUE
guestfs_int_ruby_vgs (VALUE gv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "vgs");


  char **r;

  r = guestfs_vgs (g);
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
 *   g.write_file(path, content, size) -> nil
 *
 * create a file
 *
 * This call creates a file called "path". The contents of
 * the file is the string "content" (which can contain any
 * 8 bit data), with length "size".
 * 
 * As a special case, if "size" is 0 then the length is
 * calculated using "strlen" (so in this case the content
 * cannot contain embedded ASCII NULs).
 * 
 * *NB.* Owing to a bug, writing content containing ASCII
 * NUL characters does *not* work, even if the length is
 * specified.
 * 
 * Because of the message protocol, there is a transfer
 * limit of somewhere between 2MB and 4MB. See "PROTOCOL
 * LIMITS" in guestfs(3).
 *
 *
 * [Since] Added in version 0.8.
 *
 * [Deprecated] In new code, use rdoc-ref:write instead.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_write_file}[http://libguestfs.org/guestfs.3.html#guestfs_write_file].
 */
VALUE
guestfs_int_ruby_write_file (VALUE gv, VALUE pathv, VALUE contentv, VALUE sizev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "write_file");

  const char *path = StringValueCStr (pathv);
  const char *content = StringValueCStr (contentv);
  int size = NUM2INT (sizev);

  int r;

  r = guestfs_write_file (g, path, content, size);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.zero(device) -> nil
 *
 * write zeroes to the device
 *
 * This command writes zeroes over the first few blocks of
 * "device".
 * 
 * How many blocks are zeroed isn't specified (but it’s
 * *not* enough to securely wipe the device). It should be
 * sufficient to remove any partition tables, filesystem
 * superblocks and so on.
 * 
 * If blocks are already zero, then this command avoids
 * writing zeroes. This prevents the underlying device from
 * becoming non-sparse or growing unnecessarily.
 * 
 * See also: "g.zero_device", "g.scrub_device",
 * "g.is_zero_device"
 *
 *
 * [Since] Added in version 1.0.16.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_zero}[http://libguestfs.org/guestfs.3.html#guestfs_zero].
 */
VALUE
guestfs_int_ruby_zero (VALUE gv, VALUE devicev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "zero");

  const char *device = StringValueCStr (devicev);

  int r;

  r = guestfs_zero (g, device);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.zerofree(device) -> nil
 *
 * zero unused inodes and disk blocks on ext2/3 filesystem
 *
 * This runs the *zerofree* program on "device". This
 * program claims to zero unused inodes and disk blocks on
 * an ext2/3 filesystem, thus making it possible to
 * compress the filesystem more effectively.
 * 
 * You should not run this program if the filesystem is
 * mounted.
 * 
 * It is possible that using this program can damage the
 * filesystem or data on the filesystem.
 *
 *
 * [Since] Added in version 1.0.26.
 *
 * [Feature] This function depends on the feature +zerofree+.  See also {#feature_available}[rdoc-ref:feature_available].
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_zerofree}[http://libguestfs.org/guestfs.3.html#guestfs_zerofree].
 */
VALUE
guestfs_int_ruby_zerofree (VALUE gv, VALUE devicev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "zerofree");

  const char *device = StringValueCStr (devicev);

  int r;

  r = guestfs_zerofree (g, device);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.zgrepi(regex, path) -> list
 *
 * return lines matching a pattern
 *
 * This calls the external "zgrep -i" program and returns
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
 *         {guestfs_zgrepi}[http://libguestfs.org/guestfs.3.html#guestfs_zgrepi].
 */
VALUE
guestfs_int_ruby_zgrepi (VALUE gv, VALUE regexv, VALUE pathv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "zgrepi");

  const char *regex = StringValueCStr (regexv);
  const char *path = StringValueCStr (pathv);

  char **r;

  r = guestfs_zgrepi (g, regex, path);
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

