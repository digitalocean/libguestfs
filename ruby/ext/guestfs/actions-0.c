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
 *   g.acl_delete_def_file(dir) -> nil
 *
 * delete the default POSIX ACL of a directory
 *
 * This function deletes the default POSIX Access Control
 * List (ACL) attached to directory "dir".
 *
 *
 * [Since] Added in version 1.19.63.
 *
 * [Feature] This function depends on the feature +acl+.  See also {#feature_available}[rdoc-ref:feature_available].
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_acl_delete_def_file}[http://libguestfs.org/guestfs.3.html#guestfs_acl_delete_def_file].
 */
VALUE
guestfs_int_ruby_acl_delete_def_file (VALUE gv, VALUE dirv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "acl_delete_def_file");

  const char *dir = StringValueCStr (dirv);

  int r;

  r = guestfs_acl_delete_def_file (g, dir);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.add_domain(dom, {optargs...}) -> fixnum
 *
 * add the disk(s) from a named libvirt domain
 *
 * This function adds the disk(s) attached to the named
 * libvirt domain "dom". It works by connecting to libvirt,
 * requesting the domain and domain XML from libvirt,
 * parsing it for disks, and calling "g.add_drive_opts" on
 * each one.
 * 
 * The number of disks added is returned. This operation is
 * atomic: if an error is returned, then no disks are
 * added.
 * 
 * This function does some minimal checks to make sure the
 * libvirt domain is not running (unless "readonly" is
 * true). In a future version we will try to acquire the
 * libvirt lock on each disk.
 * 
 * Disks must be accessible locally. This often means that
 * adding disks from a remote libvirt connection (see
 * <http://libvirt.org/remote.html>) will fail unless those
 * disks are accessible via the same device path locally
 * too.
 * 
 * The optional "libvirturi" parameter sets the libvirt URI
 * (see <http://libvirt.org/uri.html>). If this is not set
 * then we connect to the default libvirt URI (or one set
 * through an environment variable, see the libvirt
 * documentation for full details).
 * 
 * The optional "live" flag controls whether this call will
 * try to connect to a running virtual machine "guestfsd"
 * process if it sees a suitable <channel> element in the
 * libvirt XML definition. The default (if the flag is
 * omitted) is never to try. See "ATTACHING TO RUNNING
 * DAEMONS" in guestfs(3) for more information.
 * 
 * If the "allowuuid" flag is true (default is false) then
 * a UUID *may* be passed instead of the domain name. The
 * "dom" string is treated as a UUID first and looked up,
 * and if that lookup fails then we treat "dom" as a name
 * as usual.
 * 
 * The optional "readonlydisk" parameter controls what we
 * do for disks which are marked <readonly/> in the libvirt
 * XML. Possible values are:
 * 
 * readonlydisk = "error"
 * If "readonly" is false:
 * 
 * The whole call is aborted with an error if any disk
 * with the <readonly/> flag is found.
 * 
 * If "readonly" is true:
 * 
 * Disks with the <readonly/> flag are added read-only.
 * 
 * readonlydisk = "read"
 * If "readonly" is false:
 * 
 * Disks with the <readonly/> flag are added read-only.
 * Other disks are added read/write.
 * 
 * If "readonly" is true:
 * 
 * Disks with the <readonly/> flag are added read-only.
 * 
 * readonlydisk = "write" (default)
 * If "readonly" is false:
 * 
 * Disks with the <readonly/> flag are added
 * read/write.
 * 
 * If "readonly" is true:
 * 
 * Disks with the <readonly/> flag are added read-only.
 * 
 * readonlydisk = "ignore"
 * If "readonly" is true or false:
 * 
 * Disks with the <readonly/> flag are skipped.
 * 
 * The other optional parameters are passed directly
 * through to "g.add_drive_opts".
 * 
 * Optional arguments are supplied in the final hash
 * parameter, which is a hash of the argument name to its
 * value. Pass an empty {} for no optional arguments.
 *
 *
 * [Since] Added in version 1.7.4.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_add_domain}[http://libguestfs.org/guestfs.3.html#guestfs_add_domain].
 */
VALUE
guestfs_int_ruby_add_domain (int argc, VALUE *argv, VALUE gv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "add_domain");

  if (argc < 1 || argc > 2)
    rb_raise (rb_eArgError, "expecting 1 or 2 arguments");

  volatile VALUE domv = argv[0];
  volatile VALUE optargsv = argc > 1 ? argv[1] : rb_hash_new ();

  const char *dom = StringValueCStr (domv);

  Check_Type (optargsv, T_HASH);
  struct guestfs_add_domain_argv optargs_s = { .bitmask = 0 };
  struct guestfs_add_domain_argv *optargs = &optargs_s;
  volatile VALUE v;
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("libvirturi")));
  if (v != Qnil) {
    optargs_s.libvirturi = StringValueCStr (v);
    optargs_s.bitmask |= GUESTFS_ADD_DOMAIN_LIBVIRTURI_BITMASK;
  }
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("readonly")));
  if (v != Qnil) {
    optargs_s.readonly = RTEST (v);
    optargs_s.bitmask |= GUESTFS_ADD_DOMAIN_READONLY_BITMASK;
  }
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("iface")));
  if (v != Qnil) {
    optargs_s.iface = StringValueCStr (v);
    optargs_s.bitmask |= GUESTFS_ADD_DOMAIN_IFACE_BITMASK;
  }
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("live")));
  if (v != Qnil) {
    optargs_s.live = RTEST (v);
    optargs_s.bitmask |= GUESTFS_ADD_DOMAIN_LIVE_BITMASK;
  }
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("allowuuid")));
  if (v != Qnil) {
    optargs_s.allowuuid = RTEST (v);
    optargs_s.bitmask |= GUESTFS_ADD_DOMAIN_ALLOWUUID_BITMASK;
  }
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("readonlydisk")));
  if (v != Qnil) {
    optargs_s.readonlydisk = StringValueCStr (v);
    optargs_s.bitmask |= GUESTFS_ADD_DOMAIN_READONLYDISK_BITMASK;
  }
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("cachemode")));
  if (v != Qnil) {
    optargs_s.cachemode = StringValueCStr (v);
    optargs_s.bitmask |= GUESTFS_ADD_DOMAIN_CACHEMODE_BITMASK;
  }
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("discard")));
  if (v != Qnil) {
    optargs_s.discard = StringValueCStr (v);
    optargs_s.bitmask |= GUESTFS_ADD_DOMAIN_DISCARD_BITMASK;
  }
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("copyonread")));
  if (v != Qnil) {
    optargs_s.copyonread = RTEST (v);
    optargs_s.bitmask |= GUESTFS_ADD_DOMAIN_COPYONREAD_BITMASK;
  }

  int r;

  r = guestfs_add_domain_argv (g, dom, optargs);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return INT2NUM (r);
}

/*
 * call-seq:
 *   g.add_drive_ro(filename) -> nil
 *
 * add a drive in snapshot mode (read-only)
 *
 * This function is the equivalent of calling
 * "g.add_drive_opts" with the optional parameter
 * "GUESTFS_ADD_DRIVE_OPTS_READONLY" set to 1, so the disk
 * is added read-only, with the format being detected
 * automatically.
 *
 *
 * [Since] Added in version 1.0.38.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_add_drive_ro}[http://libguestfs.org/guestfs.3.html#guestfs_add_drive_ro].
 */
VALUE
guestfs_int_ruby_add_drive_ro (VALUE gv, VALUE filenamev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "add_drive_ro");

  const char *filename = StringValueCStr (filenamev);

  int r;

  r = guestfs_add_drive_ro (g, filename);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.add_drive_ro_with_if(filename, iface) -> nil
 *
 * add a drive read-only specifying the QEMU block emulation to use
 *
 * This is the same as "g.add_drive_ro" but it allows you
 * to specify the QEMU interface emulation to use at run
 * time.
 *
 *
 * [Since] Added in version 1.0.84.
 *
 * [Deprecated] In new code, use rdoc-ref:add_drive instead.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_add_drive_ro_with_if}[http://libguestfs.org/guestfs.3.html#guestfs_add_drive_ro_with_if].
 */
VALUE
guestfs_int_ruby_add_drive_ro_with_if (VALUE gv, VALUE filenamev, VALUE ifacev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "add_drive_ro_with_if");

  const char *filename = StringValueCStr (filenamev);
  const char *iface = StringValueCStr (ifacev);

  int r;

  r = guestfs_add_drive_ro_with_if (g, filename, iface);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.aug_ls(augpath) -> list
 *
 * list Augeas nodes under augpath
 *
 * This is just a shortcut for listing "g.aug_match"
 * "path/ *" and sorting the resulting nodes into
 * alphabetical order.
 *
 *
 * [Since] Added in version 0.8.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_aug_ls}[http://libguestfs.org/guestfs.3.html#guestfs_aug_ls].
 */
VALUE
guestfs_int_ruby_aug_ls (VALUE gv, VALUE augpathv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "aug_ls");

  const char *augpath = StringValueCStr (augpathv);

  char **r;

  r = guestfs_aug_ls (g, augpath);
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
 *   g.aug_match(augpath) -> list
 *
 * return Augeas nodes which match augpath
 *
 * Returns a list of paths which match the path expression
 * "path". The returned paths are sufficiently qualified so
 * that they match exactly one node in the current tree.
 *
 *
 * [Since] Added in version 0.7.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_aug_match}[http://libguestfs.org/guestfs.3.html#guestfs_aug_match].
 */
VALUE
guestfs_int_ruby_aug_match (VALUE gv, VALUE augpathv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "aug_match");

  const char *augpath = StringValueCStr (augpathv);

  char **r;

  r = guestfs_aug_match (g, augpath);
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
 *   g.aug_transform(lens, file, {optargs...}) -> nil
 *
 * add/remove an Augeas lens transformation
 *
 * Add an Augeas transformation for the specified "lens" so
 * it can handle "file".
 * 
 * If "remove" is true ("false" by default), then the
 * transformation is removed.
 * 
 * Optional arguments are supplied in the final hash
 * parameter, which is a hash of the argument name to its
 * value. Pass an empty {} for no optional arguments.
 *
 *
 * [Since] Added in version 1.35.2.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_aug_transform}[http://libguestfs.org/guestfs.3.html#guestfs_aug_transform].
 */
VALUE
guestfs_int_ruby_aug_transform (int argc, VALUE *argv, VALUE gv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "aug_transform");

  if (argc < 2 || argc > 3)
    rb_raise (rb_eArgError, "expecting 2 or 3 arguments");

  volatile VALUE lensv = argv[0];
  volatile VALUE filev = argv[1];
  volatile VALUE optargsv = argc > 2 ? argv[2] : rb_hash_new ();

  const char *lens = StringValueCStr (lensv);
  const char *file = StringValueCStr (filev);

  Check_Type (optargsv, T_HASH);
  struct guestfs_aug_transform_argv optargs_s = { .bitmask = 0 };
  struct guestfs_aug_transform_argv *optargs = &optargs_s;
  volatile VALUE v;
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("remove")));
  if (v != Qnil) {
    optargs_s.remove = RTEST (v);
    optargs_s.bitmask |= GUESTFS_AUG_TRANSFORM_REMOVE_BITMASK;
  }

  int r;

  r = guestfs_aug_transform_argv (g, lens, file, optargs);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.btrfs_qgroup_create(qgroupid, subvolume) -> nil
 *
 * create a subvolume quota group
 *
 * Create a quota group (qgroup) for subvolume at
 * "subvolume".
 *
 *
 * [Since] Added in version 1.29.17.
 *
 * [Feature] This function depends on the feature +btrfs+.  See also {#feature_available}[rdoc-ref:feature_available].
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_btrfs_qgroup_create}[http://libguestfs.org/guestfs.3.html#guestfs_btrfs_qgroup_create].
 */
VALUE
guestfs_int_ruby_btrfs_qgroup_create (VALUE gv, VALUE qgroupidv, VALUE subvolumev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "btrfs_qgroup_create");

  const char *qgroupid = StringValueCStr (qgroupidv);
  const char *subvolume = StringValueCStr (subvolumev);

  int r;

  r = guestfs_btrfs_qgroup_create (g, qgroupid, subvolume);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.btrfs_rescue_super_recover(device) -> nil
 *
 * recover bad superblocks from good copies
 *
 * Recover bad superblocks from good copies.
 *
 *
 * [Since] Added in version 1.29.22.
 *
 * [Feature] This function depends on the feature +btrfs+.  See also {#feature_available}[rdoc-ref:feature_available].
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_btrfs_rescue_super_recover}[http://libguestfs.org/guestfs.3.html#guestfs_btrfs_rescue_super_recover].
 */
VALUE
guestfs_int_ruby_btrfs_rescue_super_recover (VALUE gv, VALUE devicev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "btrfs_rescue_super_recover");

  const char *device = StringValueCStr (devicev);

  int r;

  r = guestfs_btrfs_rescue_super_recover (g, device);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.btrfstune_enable_extended_inode_refs(device) -> nil
 *
 * enable extended inode refs
 *
 * This will Enable extended inode refs.
 *
 *
 * [Since] Added in version 1.29.29.
 *
 * [Feature] This function depends on the feature +btrfs+.  See also {#feature_available}[rdoc-ref:feature_available].
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_btrfstune_enable_extended_inode_refs}[http://libguestfs.org/guestfs.3.html#guestfs_btrfstune_enable_extended_inode_refs].
 */
VALUE
guestfs_int_ruby_btrfstune_enable_extended_inode_refs (VALUE gv, VALUE devicev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "btrfstune_enable_extended_inode_refs");

  const char *device = StringValueCStr (devicev);

  int r;

  r = guestfs_btrfstune_enable_extended_inode_refs (g, device);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.command_lines(arguments) -> list
 *
 * run a command, returning lines
 *
 * This is the same as "g.command", but splits the result
 * into a list of lines.
 * 
 * See also: "g.sh_lines"
 * 
 * Because of the message protocol, there is a transfer
 * limit of somewhere between 2MB and 4MB. See "PROTOCOL
 * LIMITS" in guestfs(3).
 *
 *
 * [Since] Added in version 1.9.1.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_command_lines}[http://libguestfs.org/guestfs.3.html#guestfs_command_lines].
 */
VALUE
guestfs_int_ruby_command_lines (VALUE gv, VALUE argumentsv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "command_lines");

  char **arguments;
  Check_Type (argumentsv, T_ARRAY);
  {
    size_t i, len;
    len = RARRAY_LEN (argumentsv);
    arguments = ALLOC_N (char *, len+1);
    for (i = 0; i < len; ++i) {
      volatile VALUE v = rb_ary_entry (argumentsv, i);
      arguments[i] = StringValueCStr (v);
    }
    arguments[len] = NULL;
  }

  char **r;

  r = guestfs_command_lines (g, arguments);
  free (arguments);
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
 *   g.compress_device_out(ctype, device, zdevice, {optargs...}) -> nil
 *
 * output compressed device
 *
 * This command compresses "device" and writes it out to
 * the local file "zdevice".
 * 
 * The "ctype" and optional "level" parameters have the
 * same meaning as in "g.compress_out".
 * 
 * Optional arguments are supplied in the final hash
 * parameter, which is a hash of the argument name to its
 * value. Pass an empty {} for no optional arguments.
 *
 *
 * [Since] Added in version 1.13.15.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_compress_device_out}[http://libguestfs.org/guestfs.3.html#guestfs_compress_device_out].
 */
VALUE
guestfs_int_ruby_compress_device_out (int argc, VALUE *argv, VALUE gv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "compress_device_out");

  if (argc < 3 || argc > 4)
    rb_raise (rb_eArgError, "expecting 3 or 4 arguments");

  volatile VALUE ctypev = argv[0];
  volatile VALUE devicev = argv[1];
  volatile VALUE zdevicev = argv[2];
  volatile VALUE optargsv = argc > 3 ? argv[3] : rb_hash_new ();

  const char *ctype = StringValueCStr (ctypev);
  const char *device = StringValueCStr (devicev);
  const char *zdevice = StringValueCStr (zdevicev);

  Check_Type (optargsv, T_HASH);
  struct guestfs_compress_device_out_argv optargs_s = { .bitmask = 0 };
  struct guestfs_compress_device_out_argv *optargs = &optargs_s;
  volatile VALUE v;
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("level")));
  if (v != Qnil) {
    optargs_s.level = NUM2INT (v);
    optargs_s.bitmask |= GUESTFS_COMPRESS_DEVICE_OUT_LEVEL_BITMASK;
  }

  int r;

  r = guestfs_compress_device_out_argv (g, ctype, device, zdevice, optargs);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.compress_out(ctype, file, zfile, {optargs...}) -> nil
 *
 * output compressed file
 *
 * This command compresses file and writes it out to the
 * local file zfile.
 * 
 * The compression program used is controlled by the
 * "ctype" parameter. Currently this includes: "compress",
 * "gzip", "bzip2", "xz" or "lzop". Some compression types
 * may not be supported by particular builds of libguestfs,
 * in which case you will get an error containing the
 * substring "not supported".
 * 
 * The optional "level" parameter controls compression
 * level. The meaning and default for this parameter
 * depends on the compression program being used.
 * 
 * Optional arguments are supplied in the final hash
 * parameter, which is a hash of the argument name to its
 * value. Pass an empty {} for no optional arguments.
 *
 *
 * [Since] Added in version 1.13.15.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_compress_out}[http://libguestfs.org/guestfs.3.html#guestfs_compress_out].
 */
VALUE
guestfs_int_ruby_compress_out (int argc, VALUE *argv, VALUE gv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "compress_out");

  if (argc < 3 || argc > 4)
    rb_raise (rb_eArgError, "expecting 3 or 4 arguments");

  volatile VALUE ctypev = argv[0];
  volatile VALUE filev = argv[1];
  volatile VALUE zfilev = argv[2];
  volatile VALUE optargsv = argc > 3 ? argv[3] : rb_hash_new ();

  const char *ctype = StringValueCStr (ctypev);
  const char *file = StringValueCStr (filev);
  const char *zfile = StringValueCStr (zfilev);

  Check_Type (optargsv, T_HASH);
  struct guestfs_compress_out_argv optargs_s = { .bitmask = 0 };
  struct guestfs_compress_out_argv *optargs = &optargs_s;
  volatile VALUE v;
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("level")));
  if (v != Qnil) {
    optargs_s.level = NUM2INT (v);
    optargs_s.bitmask |= GUESTFS_COMPRESS_OUT_LEVEL_BITMASK;
  }

  int r;

  r = guestfs_compress_out_argv (g, ctype, file, zfile, optargs);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.copy_in(localpath, remotedir) -> nil
 *
 * copy local files or directories into an image
 *
 * "g.copy_in" copies local files or directories
 * recursively into the disk image, placing them in the
 * directory called "remotedir" (which must exist).
 * 
 * Wildcards cannot be used.
 *
 *
 * [Since] Added in version 1.29.24.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_copy_in}[http://libguestfs.org/guestfs.3.html#guestfs_copy_in].
 */
VALUE
guestfs_int_ruby_copy_in (VALUE gv, VALUE localpathv, VALUE remotedirv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "copy_in");

  const char *localpath = StringValueCStr (localpathv);
  const char *remotedir = StringValueCStr (remotedirv);

  int r;

  r = guestfs_copy_in (g, localpath, remotedir);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.cp(src, dest) -> nil
 *
 * copy a file
 *
 * This copies a file from "src" to "dest" where "dest" is
 * either a destination filename or destination directory.
 *
 *
 * [Since] Added in version 1.0.18.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_cp}[http://libguestfs.org/guestfs.3.html#guestfs_cp].
 */
VALUE
guestfs_int_ruby_cp (VALUE gv, VALUE srcv, VALUE destv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "cp");

  const char *src = StringValueCStr (srcv);
  const char *dest = StringValueCStr (destv);

  int r;

  r = guestfs_cp (g, src, dest);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.df_h() -> string
 *
 * report file system disk space usage (human readable)
 *
 * This command runs the "df -h" command to report disk
 * space used in human-readable format.
 * 
 * This command is mostly useful for interactive sessions.
 * It is *not* intended that you try to parse the output
 * string. Use "g.statvfs" from programs.
 *
 *
 * [Since] Added in version 1.0.54.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_df_h}[http://libguestfs.org/guestfs.3.html#guestfs_df_h].
 */
VALUE
guestfs_int_ruby_df_h (VALUE gv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "df_h");


  char *r;

  r = guestfs_df_h (g);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  volatile VALUE rv = rb_str_new2 (r);
  free (r);
  return rv;
}

/*
 * call-seq:
 *   g.disk_has_backing_file(filename) -> [True|False]
 *
 * return whether disk has a backing file
 *
 * Detect and return whether the disk image filename has a
 * backing file.
 * 
 * Note that detecting disk features can be insecure under
 * some circumstances. See "CVE-2010-3851" in guestfs(3).
 *
 *
 * [Since] Added in version 1.19.39.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_disk_has_backing_file}[http://libguestfs.org/guestfs.3.html#guestfs_disk_has_backing_file].
 */
VALUE
guestfs_int_ruby_disk_has_backing_file (VALUE gv, VALUE filenamev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "disk_has_backing_file");

  const char *filename = StringValueCStr (filenamev);

  int r;

  r = guestfs_disk_has_backing_file (g, filename);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return INT2NUM (r);
}

/*
 * call-seq:
 *   g.e2fsck(device, {optargs...}) -> nil
 *
 * check an ext2/ext3 filesystem
 *
 * This runs the ext2/ext3 filesystem checker on "device".
 * It can take the following optional arguments:
 * 
 * "correct"
 * Automatically repair the file system. This option
 * will cause e2fsck to automatically fix any
 * filesystem problems that can be safely fixed without
 * human intervention.
 * 
 * This option may not be specified at the same time as
 * the "forceall" option.
 * 
 * "forceall"
 * Assume an answer of 'yes' to all questions; allows
 * e2fsck to be used non-interactively.
 * 
 * This option may not be specified at the same time as
 * the "correct" option.
 * 
 * Optional arguments are supplied in the final hash
 * parameter, which is a hash of the argument name to its
 * value. Pass an empty {} for no optional arguments.
 *
 *
 * [Since] Added in version 1.15.17.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_e2fsck}[http://libguestfs.org/guestfs.3.html#guestfs_e2fsck].
 */
VALUE
guestfs_int_ruby_e2fsck (int argc, VALUE *argv, VALUE gv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "e2fsck");

  if (argc < 1 || argc > 2)
    rb_raise (rb_eArgError, "expecting 1 or 2 arguments");

  volatile VALUE devicev = argv[0];
  volatile VALUE optargsv = argc > 1 ? argv[1] : rb_hash_new ();

  const char *device = StringValueCStr (devicev);

  Check_Type (optargsv, T_HASH);
  struct guestfs_e2fsck_argv optargs_s = { .bitmask = 0 };
  struct guestfs_e2fsck_argv *optargs = &optargs_s;
  volatile VALUE v;
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("correct")));
  if (v != Qnil) {
    optargs_s.correct = RTEST (v);
    optargs_s.bitmask |= GUESTFS_E2FSCK_CORRECT_BITMASK;
  }
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("forceall")));
  if (v != Qnil) {
    optargs_s.forceall = RTEST (v);
    optargs_s.bitmask |= GUESTFS_E2FSCK_FORCEALL_BITMASK;
  }

  int r;

  r = guestfs_e2fsck_argv (g, device, optargs);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.extlinux(directory) -> nil
 *
 * install the SYSLINUX bootloader on an ext2/3/4 or btrfs filesystem
 *
 * Install the SYSLINUX bootloader on the device mounted at
 * directory. Unlike "g.syslinux" which requires a FAT
 * filesystem, this can be used on an ext2/3/4 or btrfs
 * filesystem.
 * 
 * The directory parameter can be either a mountpoint, or a
 * directory within the mountpoint.
 * 
 * You also have to mark the partition as "active"
 * ("g.part_set_bootable") and a Master Boot Record must be
 * installed (eg. using "g.pwrite_device") on the first
 * sector of the whole disk. The SYSLINUX package comes
 * with some suitable Master Boot Records. See the
 * extlinux(1) man page for further information.
 * 
 * Additional configuration can be supplied to SYSLINUX by
 * placing a file called extlinux.conf on the filesystem
 * under directory. For further information about the
 * contents of this file, see extlinux(1).
 * 
 * See also "g.syslinux".
 *
 *
 * [Since] Added in version 1.21.27.
 *
 * [Feature] This function depends on the feature +extlinux+.  See also {#feature_available}[rdoc-ref:feature_available].
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_extlinux}[http://libguestfs.org/guestfs.3.html#guestfs_extlinux].
 */
VALUE
guestfs_int_ruby_extlinux (VALUE gv, VALUE directoryv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "extlinux");

  const char *directory = StringValueCStr (directoryv);

  int r;

  r = guestfs_extlinux (g, directory);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.fsck(fstype, device) -> fixnum
 *
 * run the filesystem checker
 *
 * This runs the filesystem checker (fsck) on "device"
 * which should have filesystem type "fstype".
 * 
 * The returned integer is the status. See fsck(8) for the
 * list of status codes from "fsck".
 * 
 * Notes:
 * 
 * *   Multiple status codes can be summed together.
 * 
 * *   A non-zero return code can mean "success", for
 * example if errors have been corrected on the
 * filesystem.
 * 
 * *   Checking or repairing NTFS volumes is not supported
 * (by linux-ntfs).
 * 
 * This command is entirely equivalent to running "fsck -a
 * -t fstype device".
 *
 *
 * [Since] Added in version 1.0.16.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_fsck}[http://libguestfs.org/guestfs.3.html#guestfs_fsck].
 */
VALUE
guestfs_int_ruby_fsck (VALUE gv, VALUE fstypev, VALUE devicev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "fsck");

  const char *fstype = StringValueCStr (fstypev);
  const char *device = StringValueCStr (devicev);

  int r;

  r = guestfs_fsck (g, fstype, device);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return INT2NUM (r);
}

/*
 * call-seq:
 *   g.get_attach_method() -> string
 *
 * get the backend
 *
 * Return the current backend.
 * 
 * See "g.set_backend" and "BACKEND" in guestfs(3).
 *
 *
 * [Since] Added in version 1.9.8.
 *
 * [Deprecated] In new code, use rdoc-ref:get_backend instead.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_get_attach_method}[http://libguestfs.org/guestfs.3.html#guestfs_get_attach_method].
 */
VALUE
guestfs_int_ruby_get_attach_method (VALUE gv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "get_attach_method");


  char *r;

  r = guestfs_get_attach_method (g);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  volatile VALUE rv = rb_str_new2 (r);
  free (r);
  return rv;
}

/*
 * call-seq:
 *   g.get_cachedir() -> string
 *
 * get the appliance cache directory
 *
 * Get the directory used by the handle to store the
 * appliance cache.
 *
 *
 * [Since] Added in version 1.19.58.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_get_cachedir}[http://libguestfs.org/guestfs.3.html#guestfs_get_cachedir].
 */
VALUE
guestfs_int_ruby_get_cachedir (VALUE gv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "get_cachedir");


  char *r;

  r = guestfs_get_cachedir (g);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  volatile VALUE rv = rb_str_new2 (r);
  free (r);
  return rv;
}

/*
 * call-seq:
 *   g.get_libvirt_requested_credential_defresult(index) -> string
 *
 * default result of i'th requested credential
 *
 * Get the default result (provided by libvirt) for the
 * "index"'th requested credential. If libvirt did not
 * provide a default result, this returns the empty string
 * "".
 * 
 * See "LIBVIRT AUTHENTICATION" in guestfs(3) for
 * documentation and example code.
 *
 *
 * [Since] Added in version 1.19.52.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_get_libvirt_requested_credential_defresult}[http://libguestfs.org/guestfs.3.html#guestfs_get_libvirt_requested_credential_defresult].
 */
VALUE
guestfs_int_ruby_get_libvirt_requested_credential_defresult (VALUE gv, VALUE indexv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "get_libvirt_requested_credential_defresult");

  int index = NUM2INT (indexv);

  char *r;

  r = guestfs_get_libvirt_requested_credential_defresult (g, index);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  volatile VALUE rv = rb_str_new2 (r);
  free (r);
  return rv;
}

/*
 * call-seq:
 *   g.get_path() -> string
 *
 * get the search path
 *
 * Return the current search path.
 * 
 * This is always non-NULL. If it wasn't set already, then
 * this will return the default path.
 *
 *
 * [Since] Added in version 0.3.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_get_path}[http://libguestfs.org/guestfs.3.html#guestfs_get_path].
 */
VALUE
guestfs_int_ruby_get_path (VALUE gv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "get_path");


  const char *r;

  r = guestfs_get_path (g);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return rb_str_new2 (r);
}

/*
 * call-seq:
 *   g.get_pgroup() -> [True|False]
 *
 * get process group flag
 *
 * This returns the process group flag.
 *
 *
 * [Since] Added in version 1.11.18.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_get_pgroup}[http://libguestfs.org/guestfs.3.html#guestfs_get_pgroup].
 */
VALUE
guestfs_int_ruby_get_pgroup (VALUE gv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "get_pgroup");


  int r;

  r = guestfs_get_pgroup (g);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return INT2NUM (r);
}

/*
 * call-seq:
 *   g.get_smp() -> fixnum
 *
 * get number of virtual CPUs in appliance
 *
 * This returns the number of virtual CPUs assigned to the
 * appliance.
 *
 *
 * [Since] Added in version 1.13.15.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_get_smp}[http://libguestfs.org/guestfs.3.html#guestfs_get_smp].
 */
VALUE
guestfs_int_ruby_get_smp (VALUE gv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "get_smp");


  int r;

  r = guestfs_get_smp (g);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return INT2NUM (r);
}

/*
 * call-seq:
 *   g.get_sockdir() -> string
 *
 * get the temporary directory for sockets
 *
 * Get the directory used by the handle to store temporary
 * socket files.
 * 
 * This is different from "g.tmpdir", as we need shorter
 * paths for sockets (due to the limited buffers of
 * filenames for UNIX sockets), and "g.tmpdir" may be too
 * long for them.
 * 
 * The environment variable "XDG_RUNTIME_DIR" controls the
 * default value: If "XDG_RUNTIME_DIR" is set, then that is
 * the default. Else /tmp is the default.
 *
 *
 * [Since] Added in version 1.33.8.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_get_sockdir}[http://libguestfs.org/guestfs.3.html#guestfs_get_sockdir].
 */
VALUE
guestfs_int_ruby_get_sockdir (VALUE gv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "get_sockdir");


  char *r;

  r = guestfs_get_sockdir (g);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  volatile VALUE rv = rb_str_new2 (r);
  free (r);
  return rv;
}

/*
 * call-seq:
 *   g.get_trace() -> [True|False]
 *
 * get command trace enabled flag
 *
 * Return the command trace flag.
 *
 *
 * [Since] Added in version 1.0.69.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_get_trace}[http://libguestfs.org/guestfs.3.html#guestfs_get_trace].
 */
VALUE
guestfs_int_ruby_get_trace (VALUE gv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "get_trace");


  int r;

  r = guestfs_get_trace (g);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return INT2NUM (r);
}

/*
 * call-seq:
 *   g.hivex_node_get_child(nodeh, name) -> fixnum
 *
 * return the named child of node
 *
 * Return the child of "nodeh" with the name "name", if it
 * exists. This can return 0 meaning the name was not
 * found.
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
 *         {guestfs_hivex_node_get_child}[http://libguestfs.org/guestfs.3.html#guestfs_hivex_node_get_child].
 */
VALUE
guestfs_int_ruby_hivex_node_get_child (VALUE gv, VALUE nodehv, VALUE namev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "hivex_node_get_child");

  long long nodeh = NUM2LL (nodehv);
  const char *name = StringValueCStr (namev);

  int64_t r;

  r = guestfs_hivex_node_get_child (g, nodeh, name);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return ULL2NUM (r);
}

/*
 * call-seq:
 *   g.hivex_node_set_value(nodeh, key, t, val) -> nil
 *
 * set or replace a single value in a node
 *
 * Set or replace a single value under the node "nodeh".
 * The "key" is the name, "t" is the type, and "val" is the
 * data.
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
 *         {guestfs_hivex_node_set_value}[http://libguestfs.org/guestfs.3.html#guestfs_hivex_node_set_value].
 */
VALUE
guestfs_int_ruby_hivex_node_set_value (VALUE gv, VALUE nodehv, VALUE keyv, VALUE tv, VALUE valv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "hivex_node_set_value");

  long long nodeh = NUM2LL (nodehv);
  const char *key = StringValueCStr (keyv);
  long long t = NUM2LL (tv);
  Check_Type (valv, T_STRING);
  const char *val = RSTRING_PTR (valv);
  if (!val)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "val", "hivex_node_set_value");
  size_t val_size = RSTRING_LEN (valv);

  int r;

  r = guestfs_hivex_node_set_value (g, nodeh, key, t, val, val_size);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.hivex_value_key(valueh) -> string
 *
 * return the key field from the (key, datatype, data) tuple
 *
 * Return the key (name) field of a (key, datatype, data)
 * tuple.
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
 *         {guestfs_hivex_value_key}[http://libguestfs.org/guestfs.3.html#guestfs_hivex_value_key].
 */
VALUE
guestfs_int_ruby_hivex_value_key (VALUE gv, VALUE valuehv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "hivex_value_key");

  long long valueh = NUM2LL (valuehv);

  char *r;

  r = guestfs_hivex_value_key (g, valueh);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  volatile VALUE rv = rb_str_new2 (r);
  free (r);
  return rv;
}

/*
 * call-seq:
 *   g.hivex_value_type(valueh) -> fixnum
 *
 * return the data type from the (key, datatype, data) tuple
 *
 * Return the data type field from a (key, datatype, data)
 * tuple.
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
 *         {guestfs_hivex_value_type}[http://libguestfs.org/guestfs.3.html#guestfs_hivex_value_type].
 */
VALUE
guestfs_int_ruby_hivex_value_type (VALUE gv, VALUE valuehv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "hivex_value_type");

  long long valueh = NUM2LL (valuehv);

  int64_t r;

  r = guestfs_hivex_value_type (g, valueh);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return ULL2NUM (r);
}

/*
 * call-seq:
 *   g.inspect_get_distro(root) -> string
 *
 * get distro of inspected operating system
 *
 * This returns the distro (distribution) of the inspected
 * operating system.
 * 
 * Currently defined distros are:
 * 
 * "alpinelinux"
 * Alpine Linux.
 * 
 * "altlinux"
 * ALT Linux.
 * 
 * "archlinux"
 * Arch Linux.
 * 
 * "buildroot"
 * Buildroot-derived distro, but not one we
 * specifically recognize.
 * 
 * "centos"
 * CentOS.
 * 
 * "cirros"
 * Cirros.
 * 
 * "coreos"
 * CoreOS.
 * 
 * "debian"
 * Debian.
 * 
 * "fedora"
 * Fedora.
 * 
 * "freebsd"
 * FreeBSD.
 * 
 * "freedos"
 * FreeDOS.
 * 
 * "frugalware"
 * Frugalware.
 * 
 * "gentoo"
 * Gentoo.
 * 
 * "linuxmint"
 * Linux Mint.
 * 
 * "mageia"
 * Mageia.
 * 
 * "mandriva"
 * Mandriva.
 * 
 * "meego"
 * MeeGo.
 * 
 * "netbsd"
 * NetBSD.
 * 
 * "openbsd"
 * OpenBSD.
 * 
 * "opensuse"
 * OpenSUSE.
 * 
 * "oraclelinux"
 * Oracle Linux.
 * 
 * "pardus"
 * Pardus.
 * 
 * "pldlinux"
 * PLD Linux.
 * 
 * "redhat-based"
 * Some Red Hat-derived distro.
 * 
 * "rhel"
 * Red Hat Enterprise Linux.
 * 
 * "scientificlinux"
 * Scientific Linux.
 * 
 * "slackware"
 * Slackware.
 * 
 * "sles"
 * SuSE Linux Enterprise Server or Desktop.
 * 
 * "suse-based"
 * Some openSuSE-derived distro.
 * 
 * "ttylinux"
 * ttylinux.
 * 
 * "ubuntu"
 * Ubuntu.
 * 
 * "unknown"
 * The distro could not be determined.
 * 
 * "voidlinux"
 * Void Linux.
 * 
 * "windows"
 * Windows does not have distributions. This string is
 * returned if the OS type is Windows.
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
 *         {guestfs_inspect_get_distro}[http://libguestfs.org/guestfs.3.html#guestfs_inspect_get_distro].
 */
VALUE
guestfs_int_ruby_inspect_get_distro (VALUE gv, VALUE rootv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "inspect_get_distro");

  const char *root = StringValueCStr (rootv);

  char *r;

  r = guestfs_inspect_get_distro (g, root);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  volatile VALUE rv = rb_str_new2 (r);
  free (r);
  return rv;
}

/*
 * call-seq:
 *   g.inspect_get_filesystems(root) -> list
 *
 * get filesystems associated with inspected operating system
 *
 * This returns a list of all the filesystems that we think
 * are associated with this operating system. This includes
 * the root filesystem, other ordinary filesystems, and
 * non-mounted devices like swap partitions.
 * 
 * In the case of a multi-boot virtual machine, it is
 * possible for a filesystem to be shared between operating
 * systems.
 * 
 * Please read "INSPECTION" in guestfs(3) for more details.
 * See also "g.inspect_get_mountpoints".
 *
 *
 * [Since] Added in version 1.5.3.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_inspect_get_filesystems}[http://libguestfs.org/guestfs.3.html#guestfs_inspect_get_filesystems].
 */
VALUE
guestfs_int_ruby_inspect_get_filesystems (VALUE gv, VALUE rootv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "inspect_get_filesystems");

  const char *root = StringValueCStr (rootv);

  char **r;

  r = guestfs_inspect_get_filesystems (g, root);
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
 *   g.inspect_get_minor_version(root) -> fixnum
 *
 * get minor version of inspected operating system
 *
 * This returns the minor version number of the inspected
 * operating system.
 * 
 * If the version could not be determined, then 0 is
 * returned.
 * 
 * Please read "INSPECTION" in guestfs(3) for more details.
 * See also "g.inspect_get_major_version".
 *
 *
 * [Since] Added in version 1.5.3.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_inspect_get_minor_version}[http://libguestfs.org/guestfs.3.html#guestfs_inspect_get_minor_version].
 */
VALUE
guestfs_int_ruby_inspect_get_minor_version (VALUE gv, VALUE rootv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "inspect_get_minor_version");

  const char *root = StringValueCStr (rootv);

  int r;

  r = guestfs_inspect_get_minor_version (g, root);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return INT2NUM (r);
}

/*
 * call-seq:
 *   g.inspect_get_package_format(root) -> string
 *
 * get package format used by the operating system
 *
 * This function and "g.inspect_get_package_management"
 * return the package format and package management tool
 * used by the inspected operating system. For example for
 * Fedora these functions would return "rpm" (package
 * format), and "yum" or "dnf" (package management).
 * 
 * This returns the string "unknown" if we could not
 * determine the package format *or* if the operating
 * system does not have a real packaging system (eg.
 * Windows).
 * 
 * Possible strings include: "rpm", "deb", "ebuild",
 * "pisi", "pacman", "pkgsrc", "apk", "xbps". Future
 * versions of libguestfs may return other strings.
 * 
 * Please read "INSPECTION" in guestfs(3) for more details.
 *
 *
 * [Since] Added in version 1.7.5.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_inspect_get_package_format}[http://libguestfs.org/guestfs.3.html#guestfs_inspect_get_package_format].
 */
VALUE
guestfs_int_ruby_inspect_get_package_format (VALUE gv, VALUE rootv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "inspect_get_package_format");

  const char *root = StringValueCStr (rootv);

  char *r;

  r = guestfs_inspect_get_package_format (g, root);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  volatile VALUE rv = rb_str_new2 (r);
  free (r);
  return rv;
}

/*
 * call-seq:
 *   g.inspect_get_product_variant(root) -> string
 *
 * get product variant of inspected operating system
 *
 * This returns the product variant of the inspected
 * operating system.
 * 
 * For Windows guests, this returns the contents of the
 * Registry key "HKLM\Software\Microsoft\Windows
 * NT\CurrentVersion" "InstallationType" which is usually a
 * string such as "Client" or "Server" (other values are
 * possible). This can be used to distinguish consumer and
 * enterprise versions of Windows that have the same
 * version number (for example, Windows 7 and Windows 2008
 * Server are both version 6.1, but the former is "Client"
 * and the latter is "Server").
 * 
 * For enterprise Linux guests, in future we intend this to
 * return the product variant such as "Desktop", "Server"
 * and so on. But this is not implemented at present.
 * 
 * If the product variant could not be determined, then the
 * string "unknown" is returned.
 * 
 * Please read "INSPECTION" in guestfs(3) for more details.
 * See also "g.inspect_get_product_name",
 * "g.inspect_get_major_version".
 *
 *
 * [Since] Added in version 1.9.13.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_inspect_get_product_variant}[http://libguestfs.org/guestfs.3.html#guestfs_inspect_get_product_variant].
 */
VALUE
guestfs_int_ruby_inspect_get_product_variant (VALUE gv, VALUE rootv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "inspect_get_product_variant");

  const char *root = StringValueCStr (rootv);

  char *r;

  r = guestfs_inspect_get_product_variant (g, root);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  volatile VALUE rv = rb_str_new2 (r);
  free (r);
  return rv;
}

/*
 * call-seq:
 *   g.inspect_get_windows_software_hive(root) -> string
 *
 * get the path of the Windows software hive
 *
 * This returns the path to the hive (binary Windows
 * Registry file) corresponding to HKLM\SOFTWARE.
 * 
 * This call assumes that the guest is Windows and that the
 * guest has a software hive file with the right name. If
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
 *         {guestfs_inspect_get_windows_software_hive}[http://libguestfs.org/guestfs.3.html#guestfs_inspect_get_windows_software_hive].
 */
VALUE
guestfs_int_ruby_inspect_get_windows_software_hive (VALUE gv, VALUE rootv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "inspect_get_windows_software_hive");

  const char *root = StringValueCStr (rootv);

  char *r;

  r = guestfs_inspect_get_windows_software_hive (g, root);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  volatile VALUE rv = rb_str_new2 (r);
  free (r);
  return rv;
}

/*
 * call-seq:
 *   g.inspect_list_applications(root) -> list
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
 * "app_name"
 * The name of the application. For Red Hat-derived and
 * Debian-derived Linux guests, this is the package
 * name.
 * 
 * "app_display_name"
 * The display name of the application, sometimes
 * localized to the install language of the guest
 * operating system.
 * 
 * If unavailable this is returned as an empty string
 * "". Callers needing to display something can use
 * "app_name" instead.
 * 
 * "app_epoch"
 * For package managers which use epochs, this contains
 * the epoch of the package (an integer). If
 * unavailable, this is returned as 0.
 * 
 * "app_version"
 * The version string of the application or package. If
 * unavailable this is returned as an empty string "".
 * 
 * "app_release"
 * The release string of the application or package,
 * for package managers that use this. If unavailable
 * this is returned as an empty string "".
 * 
 * "app_install_path"
 * The installation path of the application (on
 * operating systems such as Windows which use
 * installation paths). This path is in the format used
 * by the guest operating system, it is not a
 * libguestfs path.
 * 
 * If unavailable this is returned as an empty string
 * "".
 * 
 * "app_trans_path"
 * The install path translated into a libguestfs path.
 * If unavailable this is returned as an empty string
 * "".
 * 
 * "app_publisher"
 * The name of the publisher of the application, for
 * package managers that use this. If unavailable this
 * is returned as an empty string "".
 * 
 * "app_url"
 * The URL (eg. upstream URL) of the application. If
 * unavailable this is returned as an empty string "".
 * 
 * "app_source_package"
 * For packaging systems which support this, the name
 * of the source package. If unavailable this is
 * returned as an empty string "".
 * 
 * "app_summary"
 * A short (usually one line) description of the
 * application or package. If unavailable this is
 * returned as an empty string "".
 * 
 * "app_description"
 * A longer description of the application or package.
 * If unavailable this is returned as an empty string
 * "".
 * 
 * Please read "INSPECTION" in guestfs(3) for more details.
 *
 *
 * [Since] Added in version 1.7.8.
 *
 * [Deprecated] In new code, use rdoc-ref:inspect_list_applications2 instead.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_inspect_list_applications}[http://libguestfs.org/guestfs.3.html#guestfs_inspect_list_applications].
 */
VALUE
guestfs_int_ruby_inspect_list_applications (VALUE gv, VALUE rootv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "inspect_list_applications");

  const char *root = StringValueCStr (rootv);

  struct guestfs_application_list *r;

  r = guestfs_inspect_list_applications (g, root);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  volatile VALUE rv = rb_ary_new2 (r->len);
  size_t i;
  for (i = 0; i < r->len; ++i) {
    volatile VALUE hv = rb_hash_new ();
    rb_hash_aset (hv, rb_str_new2 ("app_name"), rb_str_new2 (r->val[i].app_name));
    rb_hash_aset (hv, rb_str_new2 ("app_display_name"), rb_str_new2 (r->val[i].app_display_name));
    rb_hash_aset (hv, rb_str_new2 ("app_epoch"), INT2NUM (r->val[i].app_epoch));
    rb_hash_aset (hv, rb_str_new2 ("app_version"), rb_str_new2 (r->val[i].app_version));
    rb_hash_aset (hv, rb_str_new2 ("app_release"), rb_str_new2 (r->val[i].app_release));
    rb_hash_aset (hv, rb_str_new2 ("app_install_path"), rb_str_new2 (r->val[i].app_install_path));
    rb_hash_aset (hv, rb_str_new2 ("app_trans_path"), rb_str_new2 (r->val[i].app_trans_path));
    rb_hash_aset (hv, rb_str_new2 ("app_publisher"), rb_str_new2 (r->val[i].app_publisher));
    rb_hash_aset (hv, rb_str_new2 ("app_url"), rb_str_new2 (r->val[i].app_url));
    rb_hash_aset (hv, rb_str_new2 ("app_source_package"), rb_str_new2 (r->val[i].app_source_package));
    rb_hash_aset (hv, rb_str_new2 ("app_summary"), rb_str_new2 (r->val[i].app_summary));
    rb_hash_aset (hv, rb_str_new2 ("app_description"), rb_str_new2 (r->val[i].app_description));
    rb_ary_push (rv, hv);
  }
  guestfs_free_application_list (r);
  return rv;
}

/*
 * call-seq:
 *   g.inspect_os() -> list
 *
 * inspect disk and return list of operating systems found
 *
 * This function uses other libguestfs functions and
 * certain heuristics to inspect the disk(s) (usually disks
 * belonging to a virtual machine), looking for operating
 * systems.
 * 
 * The list returned is empty if no operating systems were
 * found.
 * 
 * If one operating system was found, then this returns a
 * list with a single element, which is the name of the
 * root filesystem of this operating system. It is also
 * possible for this function to return a list containing
 * more than one element, indicating a dual-boot or
 * multi-boot virtual machine, with each element being the
 * root filesystem of one of the operating systems.
 * 
 * You can pass the root string(s) returned to other
 * "g.inspect_get_*" functions in order to query further
 * information about each operating system, such as the
 * name and version.
 * 
 * This function uses other libguestfs features such as
 * "g.mount_ro" and "g.umount_all" in order to mount and
 * unmount filesystems and look at the contents. This
 * should be called with no disks currently mounted. The
 * function may also use Augeas, so any existing Augeas
 * handle will be closed.
 * 
 * This function cannot decrypt encrypted disks. The caller
 * must do that first (supplying the necessary keys) if the
 * disk is encrypted.
 * 
 * Please read "INSPECTION" in guestfs(3) for more details.
 * 
 * See also "g.list_filesystems".
 *
 *
 * [Since] Added in version 1.5.3.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_inspect_os}[http://libguestfs.org/guestfs.3.html#guestfs_inspect_os].
 */
VALUE
guestfs_int_ruby_inspect_os (VALUE gv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "inspect_os");


  char **r;

  r = guestfs_inspect_os (g);
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
 *   g.internal_test_rboolerr
 *
 * :nodoc:
 */
VALUE
guestfs_int_ruby_internal_test_rboolerr (VALUE gv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "internal_test_rboolerr");


  int r;

  r = guestfs_internal_test_rboolerr (g);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return INT2NUM (r);
}

/*
 * call-seq:
 *   g.internal_test_rstring
 *
 * :nodoc:
 */
VALUE
guestfs_int_ruby_internal_test_rstring (VALUE gv, VALUE valv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "internal_test_rstring");

  const char *val = StringValueCStr (valv);

  char *r;

  r = guestfs_internal_test_rstring (g, val);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  volatile VALUE rv = rb_str_new2 (r);
  free (r);
  return rv;
}

/*
 * call-seq:
 *   g.internal_test_rstructerr
 *
 * :nodoc:
 */
VALUE
guestfs_int_ruby_internal_test_rstructerr (VALUE gv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "internal_test_rstructerr");


  struct guestfs_lvm_pv *r;

  r = guestfs_internal_test_rstructerr (g);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  volatile VALUE rv = rb_hash_new ();
  rb_hash_aset (rv, rb_str_new2 ("pv_name"), rb_str_new2 (r->pv_name));
  rb_hash_aset (rv, rb_str_new2 ("pv_uuid"), rb_str_new (r->pv_uuid, 32));
  rb_hash_aset (rv, rb_str_new2 ("pv_fmt"), rb_str_new2 (r->pv_fmt));
  rb_hash_aset (rv, rb_str_new2 ("pv_size"), ULL2NUM (r->pv_size));
  rb_hash_aset (rv, rb_str_new2 ("dev_size"), ULL2NUM (r->dev_size));
  rb_hash_aset (rv, rb_str_new2 ("pv_free"), ULL2NUM (r->pv_free));
  rb_hash_aset (rv, rb_str_new2 ("pv_used"), ULL2NUM (r->pv_used));
  rb_hash_aset (rv, rb_str_new2 ("pv_attr"), rb_str_new2 (r->pv_attr));
  rb_hash_aset (rv, rb_str_new2 ("pv_pe_count"), LL2NUM (r->pv_pe_count));
  rb_hash_aset (rv, rb_str_new2 ("pv_pe_alloc_count"), LL2NUM (r->pv_pe_alloc_count));
  rb_hash_aset (rv, rb_str_new2 ("pv_tags"), rb_str_new2 (r->pv_tags));
  rb_hash_aset (rv, rb_str_new2 ("pe_start"), ULL2NUM (r->pe_start));
  rb_hash_aset (rv, rb_str_new2 ("pv_mda_count"), LL2NUM (r->pv_mda_count));
  rb_hash_aset (rv, rb_str_new2 ("pv_mda_free"), ULL2NUM (r->pv_mda_free));
  guestfs_free_lvm_pv (r);
  return rv;
}

/*
 * call-seq:
 *   g.journal_get() -> list
 *
 * read the current journal entry
 *
 * Read the current journal entry. This returns all the
 * fields in the journal as a set of "(attrname, attrval)"
 * pairs. The "attrname" is the field name (a string).
 * 
 * The "attrval" is the field value (a binary blob, often
 * but not always a string). Please note that "attrval" is
 * a byte array, *not* a \0-terminated C string.
 * 
 * The length of data may be truncated to the data
 * threshold (see: "g.journal_set_data_threshold",
 * "g.journal_get_data_threshold").
 * 
 * If you set the data threshold to unlimited (0) then this
 * call can read a journal entry of any size, ie. it is not
 * limited by the libguestfs protocol.
 *
 *
 * [Since] Added in version 1.23.11.
 *
 * [Feature] This function depends on the feature +journal+.  See also {#feature_available}[rdoc-ref:feature_available].
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_journal_get}[http://libguestfs.org/guestfs.3.html#guestfs_journal_get].
 */
VALUE
guestfs_int_ruby_journal_get (VALUE gv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "journal_get");


  struct guestfs_xattr_list *r;

  r = guestfs_journal_get (g);
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
 *   g.journal_get_data_threshold() -> fixnum
 *
 * get the data threshold for reading journal entries
 *
 * Get the current data threshold for reading journal
 * entries. This is a hint to the journal that it may
 * truncate data fields to this size when reading them
 * (note also that it may not truncate them). If this
 * returns 0, then the threshold is unlimited.
 * 
 * See also "g.journal_set_data_threshold".
 *
 *
 * [Since] Added in version 1.23.11.
 *
 * [Feature] This function depends on the feature +journal+.  See also {#feature_available}[rdoc-ref:feature_available].
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_journal_get_data_threshold}[http://libguestfs.org/guestfs.3.html#guestfs_journal_get_data_threshold].
 */
VALUE
guestfs_int_ruby_journal_get_data_threshold (VALUE gv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "journal_get_data_threshold");


  int64_t r;

  r = guestfs_journal_get_data_threshold (g);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return ULL2NUM (r);
}

/*
 * call-seq:
 *   g.ldmtool_diskgroup_name(diskgroup) -> string
 *
 * return the name of a Windows dynamic disk group
 *
 * Return the name of a Windows dynamic disk group. The
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
 *         {guestfs_ldmtool_diskgroup_name}[http://libguestfs.org/guestfs.3.html#guestfs_ldmtool_diskgroup_name].
 */
VALUE
guestfs_int_ruby_ldmtool_diskgroup_name (VALUE gv, VALUE diskgroupv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "ldmtool_diskgroup_name");

  const char *diskgroup = StringValueCStr (diskgroupv);

  char *r;

  r = guestfs_ldmtool_diskgroup_name (g, diskgroup);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  volatile VALUE rv = rb_str_new2 (r);
  free (r);
  return rv;
}

/*
 * call-seq:
 *   g.ldmtool_diskgroup_volumes(diskgroup) -> list
 *
 * return the volumes in a Windows dynamic disk group
 *
 * Return the volumes in a Windows dynamic disk group. The
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
 *         {guestfs_ldmtool_diskgroup_volumes}[http://libguestfs.org/guestfs.3.html#guestfs_ldmtool_diskgroup_volumes].
 */
VALUE
guestfs_int_ruby_ldmtool_diskgroup_volumes (VALUE gv, VALUE diskgroupv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "ldmtool_diskgroup_volumes");

  const char *diskgroup = StringValueCStr (diskgroupv);

  char **r;

  r = guestfs_ldmtool_diskgroup_volumes (g, diskgroup);
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
 *   g.ll(directory) -> string
 *
 * list the files in a directory (long format)
 *
 * List the files in directory (relative to the root
 * directory, there is no cwd) in the format of 'ls -la'.
 * 
 * This command is mostly useful for interactive sessions.
 * It is *not* intended that you try to parse the output
 * string.
 *
 *
 * [Since] Added in version 0.4.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_ll}[http://libguestfs.org/guestfs.3.html#guestfs_ll].
 */
VALUE
guestfs_int_ruby_ll (VALUE gv, VALUE directoryv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "ll");

  const char *directory = StringValueCStr (directoryv);

  char *r;

  r = guestfs_ll (g, directory);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  volatile VALUE rv = rb_str_new2 (r);
  free (r);
  return rv;
}

/*
 * call-seq:
 *   g.ln_f(target, linkname) -> nil
 *
 * create a hard link
 *
 * This command creates a hard link using the "ln -f"
 * command. The *-f* option removes the link ("linkname")
 * if it exists already.
 *
 *
 * [Since] Added in version 1.0.66.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_ln_f}[http://libguestfs.org/guestfs.3.html#guestfs_ln_f].
 */
VALUE
guestfs_int_ruby_ln_f (VALUE gv, VALUE targetv, VALUE linknamev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "ln_f");

  const char *target = StringValueCStr (targetv);
  const char *linkname = StringValueCStr (linknamev);

  int r;

  r = guestfs_ln_f (g, target, linkname);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.ln_s(target, linkname) -> nil
 *
 * create a symbolic link
 *
 * This command creates a symbolic link using the "ln -s"
 * command.
 *
 *
 * [Since] Added in version 1.0.66.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_ln_s}[http://libguestfs.org/guestfs.3.html#guestfs_ln_s].
 */
VALUE
guestfs_int_ruby_ln_s (VALUE gv, VALUE targetv, VALUE linknamev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "ln_s");

  const char *target = StringValueCStr (targetv);
  const char *linkname = StringValueCStr (linknamev);

  int r;

  r = guestfs_ln_s (g, target, linkname);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.lremovexattr(xattr, path) -> nil
 *
 * remove extended attribute of a file or directory
 *
 * This is the same as "g.removexattr", but if "path" is a
 * symbolic link, then it removes an extended attribute of
 * the link itself.
 *
 *
 * [Since] Added in version 1.0.59.
 *
 * [Feature] This function depends on the feature +linuxxattrs+.  See also {#feature_available}[rdoc-ref:feature_available].
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_lremovexattr}[http://libguestfs.org/guestfs.3.html#guestfs_lremovexattr].
 */
VALUE
guestfs_int_ruby_lremovexattr (VALUE gv, VALUE xattrv, VALUE pathv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "lremovexattr");

  const char *xattr = StringValueCStr (xattrv);
  const char *path = StringValueCStr (pathv);

  int r;

  r = guestfs_lremovexattr (g, xattr, path);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.lstatnslist(path, names) -> list
 *
 * lstat on multiple files
 *
 * This call allows you to perform the "g.lstatns"
 * operation on multiple files, where all files are in the
 * directory "path". "names" is the list of files from this
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
 * [Since] Added in version 1.27.53.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_lstatnslist}[http://libguestfs.org/guestfs.3.html#guestfs_lstatnslist].
 */
VALUE
guestfs_int_ruby_lstatnslist (VALUE gv, VALUE pathv, VALUE namesv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "lstatnslist");

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

  struct guestfs_statns_list *r;

  r = guestfs_lstatnslist (g, path, names);
  free (names);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  volatile VALUE rv = rb_ary_new2 (r->len);
  size_t i;
  for (i = 0; i < r->len; ++i) {
    volatile VALUE hv = rb_hash_new ();
    rb_hash_aset (hv, rb_str_new2 ("st_dev"), LL2NUM (r->val[i].st_dev));
    rb_hash_aset (hv, rb_str_new2 ("st_ino"), LL2NUM (r->val[i].st_ino));
    rb_hash_aset (hv, rb_str_new2 ("st_mode"), LL2NUM (r->val[i].st_mode));
    rb_hash_aset (hv, rb_str_new2 ("st_nlink"), LL2NUM (r->val[i].st_nlink));
    rb_hash_aset (hv, rb_str_new2 ("st_uid"), LL2NUM (r->val[i].st_uid));
    rb_hash_aset (hv, rb_str_new2 ("st_gid"), LL2NUM (r->val[i].st_gid));
    rb_hash_aset (hv, rb_str_new2 ("st_rdev"), LL2NUM (r->val[i].st_rdev));
    rb_hash_aset (hv, rb_str_new2 ("st_size"), LL2NUM (r->val[i].st_size));
    rb_hash_aset (hv, rb_str_new2 ("st_blksize"), LL2NUM (r->val[i].st_blksize));
    rb_hash_aset (hv, rb_str_new2 ("st_blocks"), LL2NUM (r->val[i].st_blocks));
    rb_hash_aset (hv, rb_str_new2 ("st_atime_sec"), LL2NUM (r->val[i].st_atime_sec));
    rb_hash_aset (hv, rb_str_new2 ("st_atime_nsec"), LL2NUM (r->val[i].st_atime_nsec));
    rb_hash_aset (hv, rb_str_new2 ("st_mtime_sec"), LL2NUM (r->val[i].st_mtime_sec));
    rb_hash_aset (hv, rb_str_new2 ("st_mtime_nsec"), LL2NUM (r->val[i].st_mtime_nsec));
    rb_hash_aset (hv, rb_str_new2 ("st_ctime_sec"), LL2NUM (r->val[i].st_ctime_sec));
    rb_hash_aset (hv, rb_str_new2 ("st_ctime_nsec"), LL2NUM (r->val[i].st_ctime_nsec));
    rb_hash_aset (hv, rb_str_new2 ("st_spare1"), LL2NUM (r->val[i].st_spare1));
    rb_hash_aset (hv, rb_str_new2 ("st_spare2"), LL2NUM (r->val[i].st_spare2));
    rb_hash_aset (hv, rb_str_new2 ("st_spare3"), LL2NUM (r->val[i].st_spare3));
    rb_hash_aset (hv, rb_str_new2 ("st_spare4"), LL2NUM (r->val[i].st_spare4));
    rb_hash_aset (hv, rb_str_new2 ("st_spare5"), LL2NUM (r->val[i].st_spare5));
    rb_hash_aset (hv, rb_str_new2 ("st_spare6"), LL2NUM (r->val[i].st_spare6));
    rb_ary_push (rv, hv);
  }
  guestfs_free_statns_list (r);
  return rv;
}

/*
 * call-seq:
 *   g.luks_close(device) -> nil
 *
 * close a LUKS device
 *
 * This closes a LUKS device that was created earlier by
 * "g.luks_open" or "g.luks_open_ro". The "device"
 * parameter must be the name of the LUKS mapping device
 * (ie. /dev/mapper/mapname) and *not* the name of the
 * underlying block device.
 *
 *
 * [Since] Added in version 1.5.1.
 *
 * [Feature] This function depends on the feature +luks+.  See also {#feature_available}[rdoc-ref:feature_available].
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_luks_close}[http://libguestfs.org/guestfs.3.html#guestfs_luks_close].
 */
VALUE
guestfs_int_ruby_luks_close (VALUE gv, VALUE devicev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "luks_close");

  const char *device = StringValueCStr (devicev);

  int r;

  r = guestfs_luks_close (g, device);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.lvremove(device) -> nil
 *
 * remove an LVM logical volume
 *
 * Remove an LVM logical volume "device", where "device" is
 * the path to the LV, such as /dev/VG/LV.
 * 
 * You can also remove all LVs in a volume group by
 * specifying the VG name, /dev/VG.
 *
 *
 * [Since] Added in version 1.0.13.
 *
 * [Feature] This function depends on the feature +lvm2+.  See also {#feature_available}[rdoc-ref:feature_available].
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_lvremove}[http://libguestfs.org/guestfs.3.html#guestfs_lvremove].
 */
VALUE
guestfs_int_ruby_lvremove (VALUE gv, VALUE devicev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "lvremove");

  const char *device = StringValueCStr (devicev);

  int r;

  r = guestfs_lvremove (g, device);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.md_stop(md) -> nil
 *
 * stop a Linux md (RAID) device
 *
 * This command deactivates the MD array named "md". The
 * device is stopped, but it is not destroyed or zeroed.
 *
 *
 * [Since] Added in version 1.15.6.
 *
 * [Feature] This function depends on the feature +mdadm+.  See also {#feature_available}[rdoc-ref:feature_available].
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_md_stop}[http://libguestfs.org/guestfs.3.html#guestfs_md_stop].
 */
VALUE
guestfs_int_ruby_md_stop (VALUE gv, VALUE mdv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "md_stop");

  const char *md = StringValueCStr (mdv);

  int r;

  r = guestfs_md_stop (g, md);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.mkfs_btrfs(devices, {optargs...}) -> nil
 *
 * create a btrfs filesystem
 *
 * Create a btrfs filesystem, allowing all configurables to
 * be set. For more information on the optional arguments,
 * see mkfs.btrfs(8).
 * 
 * Since btrfs filesystems can span multiple devices, this
 * takes a non-empty list of devices.
 * 
 * To create general filesystems, use "g.mkfs".
 * 
 * Optional arguments are supplied in the final hash
 * parameter, which is a hash of the argument name to its
 * value. Pass an empty {} for no optional arguments.
 *
 *
 * [Since] Added in version 1.17.25.
 *
 * [Feature] This function depends on the feature +btrfs+.  See also {#feature_available}[rdoc-ref:feature_available].
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_mkfs_btrfs}[http://libguestfs.org/guestfs.3.html#guestfs_mkfs_btrfs].
 */
VALUE
guestfs_int_ruby_mkfs_btrfs (int argc, VALUE *argv, VALUE gv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "mkfs_btrfs");

  if (argc < 1 || argc > 2)
    rb_raise (rb_eArgError, "expecting 1 or 2 arguments");

  volatile VALUE devicesv = argv[0];
  volatile VALUE optargsv = argc > 1 ? argv[1] : rb_hash_new ();

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
  struct guestfs_mkfs_btrfs_argv optargs_s = { .bitmask = 0 };
  struct guestfs_mkfs_btrfs_argv *optargs = &optargs_s;
  volatile VALUE v;
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("allocstart")));
  if (v != Qnil) {
    optargs_s.allocstart = NUM2LL (v);
    optargs_s.bitmask |= GUESTFS_MKFS_BTRFS_ALLOCSTART_BITMASK;
  }
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("bytecount")));
  if (v != Qnil) {
    optargs_s.bytecount = NUM2LL (v);
    optargs_s.bitmask |= GUESTFS_MKFS_BTRFS_BYTECOUNT_BITMASK;
  }
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("datatype")));
  if (v != Qnil) {
    optargs_s.datatype = StringValueCStr (v);
    optargs_s.bitmask |= GUESTFS_MKFS_BTRFS_DATATYPE_BITMASK;
  }
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("leafsize")));
  if (v != Qnil) {
    optargs_s.leafsize = NUM2INT (v);
    optargs_s.bitmask |= GUESTFS_MKFS_BTRFS_LEAFSIZE_BITMASK;
  }
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("label")));
  if (v != Qnil) {
    optargs_s.label = StringValueCStr (v);
    optargs_s.bitmask |= GUESTFS_MKFS_BTRFS_LABEL_BITMASK;
  }
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("metadata")));
  if (v != Qnil) {
    optargs_s.metadata = StringValueCStr (v);
    optargs_s.bitmask |= GUESTFS_MKFS_BTRFS_METADATA_BITMASK;
  }
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("nodesize")));
  if (v != Qnil) {
    optargs_s.nodesize = NUM2INT (v);
    optargs_s.bitmask |= GUESTFS_MKFS_BTRFS_NODESIZE_BITMASK;
  }
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("sectorsize")));
  if (v != Qnil) {
    optargs_s.sectorsize = NUM2INT (v);
    optargs_s.bitmask |= GUESTFS_MKFS_BTRFS_SECTORSIZE_BITMASK;
  }

  int r;

  r = guestfs_mkfs_btrfs_argv (g, devices, optargs);
  free (devices);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.mklost_and_found(mountpoint) -> nil
 *
 * make lost+found directory on an ext2/3/4 filesystem
 *
 * Make the "lost+found" directory, normally in the root
 * directory of an ext2/3/4 filesystem. "mountpoint" is the
 * directory under which we try to create the "lost+found"
 * directory.
 *
 *
 * [Since] Added in version 1.19.56.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_mklost_and_found}[http://libguestfs.org/guestfs.3.html#guestfs_mklost_and_found].
 */
VALUE
guestfs_int_ruby_mklost_and_found (VALUE gv, VALUE mountpointv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "mklost_and_found");

  const char *mountpoint = StringValueCStr (mountpointv);

  int r;

  r = guestfs_mklost_and_found (g, mountpoint);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.mkmountpoint(exemptpath) -> nil
 *
 * create a mountpoint
 *
 * "g.mkmountpoint" and "g.rmmountpoint" are specialized
 * calls that can be used to create extra mountpoints
 * before mounting the first filesystem.
 * 
 * These calls are *only* necessary in some very limited
 * circumstances, mainly the case where you want to mount a
 * mix of unrelated and/or read-only filesystems together.
 * 
 * For example, live CDs often contain a "Russian doll"
 * nest of filesystems, an ISO outer layer, with a squashfs
 * image inside, with an ext2/3 image inside that. You can
 * unpack this as follows in guestfish:
 * 
 * add-ro Fedora-11-i686-Live.iso
 * run
 * mkmountpoint /cd
 * mkmountpoint /sqsh
 * mkmountpoint /ext3fs
 * mount /dev/sda /cd
 * mount-loop /cd/LiveOS/squashfs.img /sqsh
 * mount-loop /sqsh/LiveOS/ext3fs.img /ext3fs
 * 
 * The inner filesystem is now unpacked under the /ext3fs
 * mountpoint.
 * 
 * "g.mkmountpoint" is not compatible with "g.umount_all".
 * You may get unexpected errors if you try to mix these
 * calls. It is safest to manually unmount filesystems and
 * remove mountpoints after use.
 * 
 * "g.umount_all" unmounts filesystems by sorting the paths
 * longest first, so for this to work for manual
 * mountpoints, you must ensure that the innermost
 * mountpoints have the longest pathnames, as in the
 * example code above.
 * 
 * For more details see
 * <https://bugzilla.redhat.com/show_bug.cgi?id=599503>
 * 
 * Autosync [see "g.set_autosync", this is set by default
 * on handles] can cause "g.umount_all" to be called when
 * the handle is closed which can also trigger these
 * issues.
 *
 *
 * [Since] Added in version 1.0.62.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_mkmountpoint}[http://libguestfs.org/guestfs.3.html#guestfs_mkmountpoint].
 */
VALUE
guestfs_int_ruby_mkmountpoint (VALUE gv, VALUE exemptpathv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "mkmountpoint");

  const char *exemptpath = StringValueCStr (exemptpathv);

  int r;

  r = guestfs_mkmountpoint (g, exemptpath);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.mkswap_file(path) -> nil
 *
 * create a swap file
 *
 * Create a swap file.
 * 
 * This command just writes a swap file signature to an
 * existing file. To create the file itself, use something
 * like "g.fallocate".
 *
 *
 * [Since] Added in version 1.0.66.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_mkswap_file}[http://libguestfs.org/guestfs.3.html#guestfs_mkswap_file].
 */
VALUE
guestfs_int_ruby_mkswap_file (VALUE gv, VALUE pathv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "mkswap_file");

  const char *path = StringValueCStr (pathv);

  int r;

  r = guestfs_mkswap_file (g, path);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.mount_9p(mounttag, mountpoint, {optargs...}) -> nil
 *
 * mount 9p filesystem
 *
 * Mount the virtio-9p filesystem with the tag "mounttag"
 * on the directory "mountpoint".
 * 
 * If required, "trans=virtio" will be automatically added
 * to the options. Any other options required can be passed
 * in the optional "options" parameter.
 * 
 * Optional arguments are supplied in the final hash
 * parameter, which is a hash of the argument name to its
 * value. Pass an empty {} for no optional arguments.
 *
 *
 * [Since] Added in version 1.11.12.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_mount_9p}[http://libguestfs.org/guestfs.3.html#guestfs_mount_9p].
 */
VALUE
guestfs_int_ruby_mount_9p (int argc, VALUE *argv, VALUE gv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "mount_9p");

  if (argc < 2 || argc > 3)
    rb_raise (rb_eArgError, "expecting 2 or 3 arguments");

  volatile VALUE mounttagv = argv[0];
  volatile VALUE mountpointv = argv[1];
  volatile VALUE optargsv = argc > 2 ? argv[2] : rb_hash_new ();

  const char *mounttag = StringValueCStr (mounttagv);
  const char *mountpoint = StringValueCStr (mountpointv);

  Check_Type (optargsv, T_HASH);
  struct guestfs_mount_9p_argv optargs_s = { .bitmask = 0 };
  struct guestfs_mount_9p_argv *optargs = &optargs_s;
  volatile VALUE v;
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("options")));
  if (v != Qnil) {
    optargs_s.options = StringValueCStr (v);
    optargs_s.bitmask |= GUESTFS_MOUNT_9P_OPTIONS_BITMASK;
  }

  int r;

  r = guestfs_mount_9p_argv (g, mounttag, mountpoint, optargs);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.mountable_device(mountable) -> string
 *
 * extract the device part of a mountable
 *
 * Returns the device name of a mountable. In quite a lot
 * of cases, the mountable is the device name.
 * 
 * However this doesn't apply for btrfs subvolumes, where
 * the mountable is a combination of both the device name
 * and the subvolume path (see also "g.mountable_subvolume"
 * to extract the subvolume path of the mountable if any).
 *
 *
 * [Since] Added in version 1.33.15.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_mountable_device}[http://libguestfs.org/guestfs.3.html#guestfs_mountable_device].
 */
VALUE
guestfs_int_ruby_mountable_device (VALUE gv, VALUE mountablev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "mountable_device");

  const char *mountable = StringValueCStr (mountablev);

  char *r;

  r = guestfs_mountable_device (g, mountable);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  volatile VALUE rv = rb_str_new2 (r);
  free (r);
  return rv;
}

/*
 * call-seq:
 *   g.mv(src, dest) -> nil
 *
 * move a file
 *
 * This moves a file from "src" to "dest" where "dest" is
 * either a destination filename or destination directory.
 * 
 * See also: "g.rename".
 *
 *
 * [Since] Added in version 1.0.18.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_mv}[http://libguestfs.org/guestfs.3.html#guestfs_mv].
 */
VALUE
guestfs_int_ruby_mv (VALUE gv, VALUE srcv, VALUE destv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "mv");

  const char *src = StringValueCStr (srcv);
  const char *dest = StringValueCStr (destv);

  int r;

  r = guestfs_mv (g, src, dest);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.ntfsresize(device, {optargs...}) -> nil
 *
 * resize an NTFS filesystem
 *
 * This command resizes an NTFS filesystem, expanding or
 * shrinking it to the size of the underlying device.
 * 
 * The optional parameters are:
 * 
 * "size"
 * The new size (in bytes) of the filesystem. If
 * omitted, the filesystem is resized to fit the
 * container (eg. partition).
 * 
 * "force"
 * If this option is true, then force the resize of the
 * filesystem even if the filesystem is marked as
 * requiring a consistency check.
 * 
 * After the resize operation, the filesystem is always
 * marked as requiring a consistency check (for
 * safety). You have to boot into Windows to perform
 * this check and clear this condition. If you *don't*
 * set the "force" option then it is not possible to
 * call "g.ntfsresize" multiple times on a single
 * filesystem without booting into Windows between each
 * resize.
 * 
 * See also ntfsresize(8).
 * 
 * Optional arguments are supplied in the final hash
 * parameter, which is a hash of the argument name to its
 * value. Pass an empty {} for no optional arguments.
 *
 *
 * [Since] Added in version 1.3.2.
 *
 * [Feature] This function depends on the feature +ntfsprogs+.  See also {#feature_available}[rdoc-ref:feature_available].
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_ntfsresize}[http://libguestfs.org/guestfs.3.html#guestfs_ntfsresize].
 */
VALUE
guestfs_int_ruby_ntfsresize (int argc, VALUE *argv, VALUE gv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "ntfsresize");

  if (argc < 1 || argc > 2)
    rb_raise (rb_eArgError, "expecting 1 or 2 arguments");

  volatile VALUE devicev = argv[0];
  volatile VALUE optargsv = argc > 1 ? argv[1] : rb_hash_new ();

  const char *device = StringValueCStr (devicev);

  Check_Type (optargsv, T_HASH);
  struct guestfs_ntfsresize_opts_argv optargs_s = { .bitmask = 0 };
  struct guestfs_ntfsresize_opts_argv *optargs = &optargs_s;
  volatile VALUE v;
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("size")));
  if (v != Qnil) {
    optargs_s.size = NUM2LL (v);
    optargs_s.bitmask |= GUESTFS_NTFSRESIZE_OPTS_SIZE_BITMASK;
  }
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("force")));
  if (v != Qnil) {
    optargs_s.force = RTEST (v);
    optargs_s.bitmask |= GUESTFS_NTFSRESIZE_OPTS_FORCE_BITMASK;
  }

  int r;

  r = guestfs_ntfsresize_opts_argv (g, device, optargs);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.part_disk(device, parttype) -> nil
 *
 * partition whole disk with a single primary partition
 *
 * This command is simply a combination of "g.part_init"
 * followed by "g.part_add" to create a single primary
 * partition covering the whole disk.
 * 
 * "parttype" is the partition table type, usually "mbr" or
 * "gpt", but other possible values are described in
 * "g.part_init".
 *
 *
 * [Since] Added in version 1.0.78.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_part_disk}[http://libguestfs.org/guestfs.3.html#guestfs_part_disk].
 */
VALUE
guestfs_int_ruby_part_disk (VALUE gv, VALUE devicev, VALUE parttypev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "part_disk");

  const char *device = StringValueCStr (devicev);
  const char *parttype = StringValueCStr (parttypev);

  int r;

  r = guestfs_part_disk (g, device, parttype);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.part_expand_gpt(device) -> nil
 *
 * move backup GPT header to the end of the disk
 *
 * Move backup GPT data structures to the end of the disk.
 * This is useful in case of in-place image expand since
 * disk space after backup GPT header is not usable. This
 * is equivalent to "sgdisk -e".
 * 
 * See also sgdisk(8).
 *
 *
 * [Since] Added in version 1.33.2.
 *
 * [Feature] This function depends on the feature +gdisk+.  See also {#feature_available}[rdoc-ref:feature_available].
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_part_expand_gpt}[http://libguestfs.org/guestfs.3.html#guestfs_part_expand_gpt].
 */
VALUE
guestfs_int_ruby_part_expand_gpt (VALUE gv, VALUE devicev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "part_expand_gpt");

  const char *device = StringValueCStr (devicev);

  int r;

  r = guestfs_part_expand_gpt (g, device);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.part_get_parttype(device) -> string
 *
 * get the partition table type
 *
 * This command examines the partition table on "device"
 * and returns the partition table type (format) being
 * used.
 * 
 * Common return values include: "msdos" (a DOS/Windows
 * style MBR partition table), "gpt" (a GPT/EFI-style
 * partition table). Other values are possible, although
 * unusual. See "g.part_init" for a full list.
 *
 *
 * [Since] Added in version 1.0.78.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_part_get_parttype}[http://libguestfs.org/guestfs.3.html#guestfs_part_get_parttype].
 */
VALUE
guestfs_int_ruby_part_get_parttype (VALUE gv, VALUE devicev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "part_get_parttype");

  const char *device = StringValueCStr (devicev);

  char *r;

  r = guestfs_part_get_parttype (g, device);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  volatile VALUE rv = rb_str_new2 (r);
  free (r);
  return rv;
}

/*
 * call-seq:
 *   g.pvcreate(device) -> nil
 *
 * create an LVM physical volume
 *
 * This creates an LVM physical volume on the named
 * "device", where "device" should usually be a partition
 * name such as /dev/sda1.
 *
 *
 * [Since] Added in version 0.8.
 *
 * [Feature] This function depends on the feature +lvm2+.  See also {#feature_available}[rdoc-ref:feature_available].
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_pvcreate}[http://libguestfs.org/guestfs.3.html#guestfs_pvcreate].
 */
VALUE
guestfs_int_ruby_pvcreate (VALUE gv, VALUE devicev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "pvcreate");

  const char *device = StringValueCStr (devicev);

  int r;

  r = guestfs_pvcreate (g, device);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.pvs() -> list
 *
 * list the LVM physical volumes (PVs)
 *
 * List all the physical volumes detected. This is the
 * equivalent of the pvs(8) command.
 * 
 * This returns a list of just the device names that
 * contain PVs (eg. /dev/sda2).
 * 
 * See also "g.pvs_full".
 *
 *
 * [Since] Added in version 0.4.
 *
 * [Feature] This function depends on the feature +lvm2+.  See also {#feature_available}[rdoc-ref:feature_available].
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_pvs}[http://libguestfs.org/guestfs.3.html#guestfs_pvs].
 */
VALUE
guestfs_int_ruby_pvs (VALUE gv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "pvs");


  char **r;

  r = guestfs_pvs (g);
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
 *   g.pwrite(path, content, offset) -> fixnum
 *
 * write to part of a file
 *
 * This command writes to part of a file. It writes the
 * data buffer "content" to the file "path" starting at
 * offset "offset".
 * 
 * This command implements the pwrite(2) system call, and
 * like that system call it may not write the full data
 * requested. The return value is the number of bytes that
 * were actually written to the file. This could even be 0,
 * although short writes are unlikely for regular files in
 * ordinary circumstances.
 * 
 * See also "g.pread", "g.pwrite_device".
 * 
 * Because of the message protocol, there is a transfer
 * limit of somewhere between 2MB and 4MB. See "PROTOCOL
 * LIMITS" in guestfs(3).
 *
 *
 * [Since] Added in version 1.3.14.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_pwrite}[http://libguestfs.org/guestfs.3.html#guestfs_pwrite].
 */
VALUE
guestfs_int_ruby_pwrite (VALUE gv, VALUE pathv, VALUE contentv, VALUE offsetv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "pwrite");

  const char *path = StringValueCStr (pathv);
  Check_Type (contentv, T_STRING);
  const char *content = RSTRING_PTR (contentv);
  if (!content)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "content", "pwrite");
  size_t content_size = RSTRING_LEN (contentv);
  long long offset = NUM2LL (offsetv);

  int r;

  r = guestfs_pwrite (g, path, content, content_size, offset);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return INT2NUM (r);
}

/*
 * call-seq:
 *   g.read_file(path) -> string
 *
 * read a file
 *
 * This calls returns the contents of the file "path" as a
 * buffer.
 * 
 * Unlike "g.cat", this function can correctly handle files
 * that contain embedded ASCII NUL characters.
 *
 *
 * [Since] Added in version 1.0.63.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_read_file}[http://libguestfs.org/guestfs.3.html#guestfs_read_file].
 */
VALUE
guestfs_int_ruby_read_file (VALUE gv, VALUE pathv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "read_file");

  const char *path = StringValueCStr (pathv);

  char *r;
  size_t size;

  r = guestfs_read_file (g, path, &size);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  volatile VALUE rv = rb_str_new (r, size);
  free (r);
  return rv;
}

/*
 * call-seq:
 *   g.rename(oldpath, newpath) -> nil
 *
 * rename a file on the same filesystem
 *
 * Rename a file to a new place on the same filesystem.
 * This is the same as the Linux rename(2) system call. In
 * most cases you are better to use "g.mv" instead.
 *
 *
 * [Since] Added in version 1.21.5.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_rename}[http://libguestfs.org/guestfs.3.html#guestfs_rename].
 */
VALUE
guestfs_int_ruby_rename (VALUE gv, VALUE oldpathv, VALUE newpathv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "rename");

  const char *oldpath = StringValueCStr (oldpathv);
  const char *newpath = StringValueCStr (newpathv);

  int r;

  r = guestfs_rename (g, oldpath, newpath);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.resize2fs_M(device) -> nil
 *
 * resize an ext2, ext3 or ext4 filesystem to the minimum size
 *
 * This command is the same as "g.resize2fs", but the
 * filesystem is resized to its minimum size. This works
 * like the *-M* option to the "resize2fs" command.
 * 
 * To get the resulting size of the filesystem you should
 * call "g.tune2fs_l" and read the "Block size" and "Block
 * count" values. These two numbers, multiplied together,
 * give the resulting size of the minimal filesystem in
 * bytes.
 * 
 * See also "RESIZE2FS ERRORS" in guestfs(3).
 *
 *
 * [Since] Added in version 1.9.4.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_resize2fs_M}[http://libguestfs.org/guestfs.3.html#guestfs_resize2fs_M].
 */
VALUE
guestfs_int_ruby_resize2fs_M (VALUE gv, VALUE devicev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "resize2fs_M");

  const char *device = StringValueCStr (devicev);

  int r;

  r = guestfs_resize2fs_M (g, device);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.rm_rf(path) -> nil
 *
 * remove a file or directory recursively
 *
 * Remove the file or directory "path", recursively
 * removing the contents if its a directory. This is like
 * the "rm -rf" shell command.
 *
 *
 * [Since] Added in version 0.8.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_rm_rf}[http://libguestfs.org/guestfs.3.html#guestfs_rm_rf].
 */
VALUE
guestfs_int_ruby_rm_rf (VALUE gv, VALUE pathv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "rm_rf");

  const char *path = StringValueCStr (pathv);

  int r;

  r = guestfs_rm_rf (g, path);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.scrub_file(file) -> nil
 *
 * scrub (securely wipe) a file
 *
 * This command writes patterns over a file to make data
 * retrieval more difficult.
 * 
 * The file is *removed* after scrubbing.
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
 *         {guestfs_scrub_file}[http://libguestfs.org/guestfs.3.html#guestfs_scrub_file].
 */
VALUE
guestfs_int_ruby_scrub_file (VALUE gv, VALUE filev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "scrub_file");

  const char *file = StringValueCStr (filev);

  int r;

  r = guestfs_scrub_file (g, file);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.set_append(append) -> nil
 *
 * add options to kernel command line
 *
 * This function is used to add additional options to the
 * libguestfs appliance kernel command line.
 * 
 * The default is "NULL" unless overridden by setting
 * "LIBGUESTFS_APPEND" environment variable.
 * 
 * Setting "append" to "NULL" means *no* additional options
 * are passed (libguestfs always adds a few of its own).
 *
 *
 * [Since] Added in version 1.0.26.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_set_append}[http://libguestfs.org/guestfs.3.html#guestfs_set_append].
 */
VALUE
guestfs_int_ruby_set_append (VALUE gv, VALUE appendv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "set_append");

  const char *append = !NIL_P (appendv) ? StringValueCStr (appendv) : NULL;

  int r;

  r = guestfs_set_append (g, append);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.set_backend(backend) -> nil
 *
 * set the backend
 *
 * Set the method that libguestfs uses to connect to the
 * backend guestfsd daemon.
 * 
 * This handle property was previously called the "attach
 * method".
 * 
 * See "BACKEND" in guestfs(3).
 *
 *
 * [Since] Added in version 1.21.26.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_set_backend}[http://libguestfs.org/guestfs.3.html#guestfs_set_backend].
 */
VALUE
guestfs_int_ruby_set_backend (VALUE gv, VALUE backendv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "set_backend");

  const char *backend = StringValueCStr (backendv);

  int r;

  r = guestfs_set_backend (g, backend);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.set_direct(direct) -> nil
 *
 * enable or disable direct appliance mode
 *
 * If the direct appliance mode flag is enabled, then stdin
 * and stdout are passed directly through to the appliance
 * once it is launched.
 * 
 * One consequence of this is that log messages aren't
 * caught by the library and handled by
 * "g.set_log_message_callback", but go straight to stdout.
 * 
 * You probably don't want to use this unless you know what
 * you are doing.
 * 
 * The default is disabled.
 *
 *
 * [Since] Added in version 1.0.72.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_set_direct}[http://libguestfs.org/guestfs.3.html#guestfs_set_direct].
 */
VALUE
guestfs_int_ruby_set_direct (VALUE gv, VALUE directv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "set_direct");

  int direct = RTEST (directv);

  int r;

  r = guestfs_set_direct (g, direct);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.set_memsize(memsize) -> nil
 *
 * set memory allocated to the hypervisor
 *
 * This sets the memory size in megabytes allocated to the
 * hypervisor. This only has any effect if called before
 * "g.launch".
 * 
 * You can also change this by setting the environment
 * variable "LIBGUESTFS_MEMSIZE" before the handle is
 * created.
 * 
 * For more information on the architecture of libguestfs,
 * see guestfs(3).
 *
 *
 * [Since] Added in version 1.0.55.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_set_memsize}[http://libguestfs.org/guestfs.3.html#guestfs_set_memsize].
 */
VALUE
guestfs_int_ruby_set_memsize (VALUE gv, VALUE memsizev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "set_memsize");

  int memsize = NUM2INT (memsizev);

  int r;

  r = guestfs_set_memsize (g, memsize);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.set_program(program) -> nil
 *
 * set the program name
 *
 * Set the program name. This is an informative string
 * which the main program may optionally set in the handle.
 * 
 * When the handle is created, the program name in the
 * handle is set to the basename from "argv[0]". The
 * program name can never be "NULL".
 *
 *
 * [Since] Added in version 1.21.29.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_set_program}[http://libguestfs.org/guestfs.3.html#guestfs_set_program].
 */
VALUE
guestfs_int_ruby_set_program (VALUE gv, VALUE programv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "set_program");

  const char *program = StringValueCStr (programv);

  int r;

  r = guestfs_set_program (g, program);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.set_selinux(selinux) -> nil
 *
 * set SELinux enabled or disabled at appliance boot
 *
 * This sets the selinux flag that is passed to the
 * appliance at boot time. The default is "selinux=0"
 * (disabled).
 * 
 * Note that if SELinux is enabled, it is always in
 * Permissive mode ("enforcing=0").
 * 
 * For more information on the architecture of libguestfs,
 * see guestfs(3).
 *
 *
 * [Since] Added in version 1.0.67.
 *
 * [Deprecated] In new code, use rdoc-ref:selinux_relabel instead.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_set_selinux}[http://libguestfs.org/guestfs.3.html#guestfs_set_selinux].
 */
VALUE
guestfs_int_ruby_set_selinux (VALUE gv, VALUE selinuxv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "set_selinux");

  int selinux = RTEST (selinuxv);

  int r;

  r = guestfs_set_selinux (g, selinux);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.setxattr(xattr, val, vallen, path) -> nil
 *
 * set extended attribute of a file or directory
 *
 * This call sets the extended attribute named "xattr" of
 * the file "path" to the value "val" (of length "vallen").
 * The value is arbitrary 8 bit data.
 * 
 * See also: "g.lsetxattr", attr(5).
 *
 *
 * [Since] Added in version 1.0.59.
 *
 * [Feature] This function depends on the feature +linuxxattrs+.  See also {#feature_available}[rdoc-ref:feature_available].
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_setxattr}[http://libguestfs.org/guestfs.3.html#guestfs_setxattr].
 */
VALUE
guestfs_int_ruby_setxattr (VALUE gv, VALUE xattrv, VALUE valv, VALUE vallenv, VALUE pathv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "setxattr");

  const char *xattr = StringValueCStr (xattrv);
  const char *val = StringValueCStr (valv);
  int vallen = NUM2INT (vallenv);
  const char *path = StringValueCStr (pathv);

  int r;

  r = guestfs_setxattr (g, xattr, val, vallen, path);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.sfdisk_l(device) -> string
 *
 * display the partition table
 *
 * This displays the partition table on "device", in the
 * human-readable output of the sfdisk(8) command. It is
 * not intended to be parsed.
 * 
 * See also: "g.part_list"
 *
 *
 * [Since] Added in version 1.0.26.
 *
 * [Deprecated] In new code, use rdoc-ref:part_list instead.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_sfdisk_l}[http://libguestfs.org/guestfs.3.html#guestfs_sfdisk_l].
 */
VALUE
guestfs_int_ruby_sfdisk_l (VALUE gv, VALUE devicev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "sfdisk_l");

  const char *device = StringValueCStr (devicev);

  char *r;

  r = guestfs_sfdisk_l (g, device);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  volatile VALUE rv = rb_str_new2 (r);
  free (r);
  return rv;
}

/*
 * call-seq:
 *   g.umount_local({optargs...}) -> nil
 *
 * unmount a locally mounted filesystem
 *
 * If libguestfs is exporting the filesystem on a local
 * mountpoint, then this unmounts it.
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
 *         {guestfs_umount_local}[http://libguestfs.org/guestfs.3.html#guestfs_umount_local].
 */
VALUE
guestfs_int_ruby_umount_local (int argc, VALUE *argv, VALUE gv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "umount_local");

  if (argc < 0 || argc > 1)
    rb_raise (rb_eArgError, "expecting 0 or 1 arguments");

  volatile VALUE optargsv = argc > 0 ? argv[0] : rb_hash_new ();


  Check_Type (optargsv, T_HASH);
  struct guestfs_umount_local_argv optargs_s = { .bitmask = 0 };
  struct guestfs_umount_local_argv *optargs = &optargs_s;
  volatile VALUE v;
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("retry")));
  if (v != Qnil) {
    optargs_s.retry = RTEST (v);
    optargs_s.bitmask |= GUESTFS_UMOUNT_LOCAL_RETRY_BITMASK;
  }

  int r;

  r = guestfs_umount_local_argv (g, optargs);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.vfs_label(mountable) -> string
 *
 * get the filesystem label
 *
 * This returns the label of the filesystem on "mountable".
 * 
 * If the filesystem is unlabeled, this returns the empty
 * string.
 * 
 * To find a filesystem from the label, use
 * "g.findfs_label".
 *
 *
 * [Since] Added in version 1.3.18.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_vfs_label}[http://libguestfs.org/guestfs.3.html#guestfs_vfs_label].
 */
VALUE
guestfs_int_ruby_vfs_label (VALUE gv, VALUE mountablev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "vfs_label");

  const char *mountable = StringValueCStr (mountablev);

  char *r;

  r = guestfs_vfs_label (g, mountable);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  volatile VALUE rv = rb_str_new2 (r);
  free (r);
  return rv;
}

/*
 * call-seq:
 *   g.vg_activate_all(activate) -> nil
 *
 * activate or deactivate all volume groups
 *
 * This command activates or (if "activate" is false)
 * deactivates all logical volumes in all volume groups.
 * 
 * This command is the same as running "vgchange -a y|n"
 *
 *
 * [Since] Added in version 1.0.26.
 *
 * [Feature] This function depends on the feature +lvm2+.  See also {#feature_available}[rdoc-ref:feature_available].
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_vg_activate_all}[http://libguestfs.org/guestfs.3.html#guestfs_vg_activate_all].
 */
VALUE
guestfs_int_ruby_vg_activate_all (VALUE gv, VALUE activatev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "vg_activate_all");

  int activate = RTEST (activatev);

  int r;

  r = guestfs_vg_activate_all (g, activate);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.vgchange_uuid_all() -> nil
 *
 * generate new random UUIDs for all volume groups
 *
 * Generate new random UUIDs for all volume groups.
 *
 *
 * [Since] Added in version 1.19.26.
 *
 * [Feature] This function depends on the feature +lvm2+.  See also {#feature_available}[rdoc-ref:feature_available].
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_vgchange_uuid_all}[http://libguestfs.org/guestfs.3.html#guestfs_vgchange_uuid_all].
 */
VALUE
guestfs_int_ruby_vgchange_uuid_all (VALUE gv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "vgchange_uuid_all");


  int r;

  r = guestfs_vgchange_uuid_all (g);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.vgmeta(vgname) -> string
 *
 * get volume group metadata
 *
 * "vgname" is an LVM volume group. This command examines
 * the volume group and returns its metadata.
 * 
 * Note that the metadata is an internal structure used by
 * LVM, subject to change at any time, and is provided for
 * information only.
 *
 *
 * [Since] Added in version 1.17.20.
 *
 * [Feature] This function depends on the feature +lvm2+.  See also {#feature_available}[rdoc-ref:feature_available].
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_vgmeta}[http://libguestfs.org/guestfs.3.html#guestfs_vgmeta].
 */
VALUE
guestfs_int_ruby_vgmeta (VALUE gv, VALUE vgnamev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "vgmeta");

  const char *vgname = StringValueCStr (vgnamev);

  char *r;
  size_t size;

  r = guestfs_vgmeta (g, vgname, &size);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  volatile VALUE rv = rb_str_new (r, size);
  free (r);
  return rv;
}

/*
 * call-seq:
 *   g.vgrename(volgroup, newvolgroup) -> nil
 *
 * rename an LVM volume group
 *
 * Rename a volume group "volgroup" with the new name
 * "newvolgroup".
 *
 *
 * [Since] Added in version 1.0.83.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_vgrename}[http://libguestfs.org/guestfs.3.html#guestfs_vgrename].
 */
VALUE
guestfs_int_ruby_vgrename (VALUE gv, VALUE volgroupv, VALUE newvolgroupv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "vgrename");

  const char *volgroup = StringValueCStr (volgroupv);
  const char *newvolgroup = StringValueCStr (newvolgroupv);

  int r;

  r = guestfs_vgrename (g, volgroup, newvolgroup);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.vguuid(vgname) -> string
 *
 * get the UUID of a volume group
 *
 * This command returns the UUID of the LVM VG named
 * "vgname".
 *
 *
 * [Since] Added in version 1.0.87.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_vguuid}[http://libguestfs.org/guestfs.3.html#guestfs_vguuid].
 */
VALUE
guestfs_int_ruby_vguuid (VALUE gv, VALUE vgnamev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "vguuid");

  const char *vgname = StringValueCStr (vgnamev);

  char *r;

  r = guestfs_vguuid (g, vgname);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  volatile VALUE rv = rb_str_new2 (r);
  free (r);
  return rv;
}

/*
 * call-seq:
 *   g.wc_w(path) -> fixnum
 *
 * count words in a file
 *
 * This command counts the words in a file, using the "wc
 * -w" external command.
 *
 *
 * [Since] Added in version 1.0.54.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_wc_w}[http://libguestfs.org/guestfs.3.html#guestfs_wc_w].
 */
VALUE
guestfs_int_ruby_wc_w (VALUE gv, VALUE pathv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "wc_w");

  const char *path = StringValueCStr (pathv);

  int r;

  r = guestfs_wc_w (g, path);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return INT2NUM (r);
}

/*
 * call-seq:
 *   g.write(path, content) -> nil
 *
 * create a new file
 *
 * This call creates a file called "path". The content of
 * the file is the string "content" (which can contain any
 * 8 bit data).
 * 
 * See also "g.write_append".
 *
 *
 * [Since] Added in version 1.3.14.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_write}[http://libguestfs.org/guestfs.3.html#guestfs_write].
 */
VALUE
guestfs_int_ruby_write (VALUE gv, VALUE pathv, VALUE contentv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "write");

  const char *path = StringValueCStr (pathv);
  Check_Type (contentv, T_STRING);
  const char *content = RSTRING_PTR (contentv);
  if (!content)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "content", "write");
  size_t content_size = RSTRING_LEN (contentv);

  int r;

  r = guestfs_write (g, path, content, content_size);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.zfgrepi(pattern, path) -> list
 *
 * return lines matching a pattern
 *
 * This calls the external "zfgrep -i" program and returns
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
 *         {guestfs_zfgrepi}[http://libguestfs.org/guestfs.3.html#guestfs_zfgrepi].
 */
VALUE
guestfs_int_ruby_zfgrepi (VALUE gv, VALUE patternv, VALUE pathv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "zfgrepi");

  const char *pattern = StringValueCStr (patternv);
  const char *path = StringValueCStr (pathv);

  char **r;

  r = guestfs_zfgrepi (g, pattern, path);
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

