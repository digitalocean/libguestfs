/* libguestfs generated file
 * WARNING: THIS FILE IS GENERATED FROM THE FOLLOWING FILES:
 *          generator/ruby.ml
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
#include <stdint.h>
#include <string.h>
#include <errno.h>
#include <assert.h>

#include "actions.h"

/*
 * call-seq:
 *   g.add_cdrom(filename) -> nil
 *
 * add a CD-ROM disk image to examine
 *
 * This function adds a virtual CD-ROM disk image to the
 * guest.
 * 
 * The image is added as read-only drive, so this function
 * is equivalent of "g.add_drive_ro".
 *
 *
 * [Since] Added in version 0.3.
 *
 * [Deprecated] In new code, use rdoc-ref:add_drive_ro instead.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_add_cdrom}[http://libguestfs.org/guestfs.3.html#guestfs_add_cdrom].
 */
VALUE
guestfs_int_ruby_add_cdrom (VALUE gv, VALUE filenamev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "add_cdrom");

  const char *filename = StringValueCStr (filenamev);

  int r;

  r = guestfs_add_cdrom (g, filename);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.add_libvirt_dom(dom, {optargs...}) -> fixnum
 *
 * add the disk(s) from a libvirt domain
 *
 * This function adds the disk(s) attached to the libvirt
 * domain "dom". It works by requesting the domain XML from
 * libvirt, parsing it for disks, and calling
 * "g.add_drive_opts" on each one.
 * 
 * In the C API we declare "void *dom", but really it has
 * type "virDomainPtr dom". This is so we don't need
 * <libvirt.h>.
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
 * The optional "live" flag controls whether this call will
 * try to connect to a running virtual machine "guestfsd"
 * process if it sees a suitable <channel> element in the
 * libvirt XML definition. The default (if the flag is
 * omitted) is never to try. See "ATTACHING TO RUNNING
 * DAEMONS" in guestfs(3) for more information.
 * 
 * The optional "readonlydisk" parameter controls what we
 * do for disks which are marked <readonly/> in the libvirt
 * XML. See "g.add_domain" for possible values.
 * 
 * The other optional parameters are passed directly
 * through to "g.add_drive_opts".
 * 
 * Optional arguments are supplied in the final hash
 * parameter, which is a hash of the argument name to its
 * value. Pass an empty {} for no optional arguments.
 *
 *
 * [Since] Added in version 1.29.14.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_add_libvirt_dom}[http://libguestfs.org/guestfs.3.html#guestfs_add_libvirt_dom].
 */
VALUE
guestfs_int_ruby_add_libvirt_dom (int argc, VALUE *argv, VALUE gv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "add_libvirt_dom");

  if (argc < 1 || argc > 2)
    rb_raise (rb_eArgError, "expecting 1 or 2 arguments");

  volatile VALUE domv = argv[0];
  volatile VALUE optargsv = argc > 1 ? argv[1] : rb_hash_new ();

  (void) domv;
  void * /* virDomainPtr */ dom = POINTER_NOT_IMPLEMENTED ("virDomainPtr");

  Check_Type (optargsv, T_HASH);
  struct guestfs_add_libvirt_dom_argv optargs_s = { .bitmask = 0 };
  struct guestfs_add_libvirt_dom_argv *optargs = &optargs_s;
  volatile VALUE v;
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("readonly")));
  if (v != Qnil) {
    optargs_s.readonly = RTEST (v);
    optargs_s.bitmask |= GUESTFS_ADD_LIBVIRT_DOM_READONLY_BITMASK;
  }
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("iface")));
  if (v != Qnil) {
    optargs_s.iface = StringValueCStr (v);
    optargs_s.bitmask |= GUESTFS_ADD_LIBVIRT_DOM_IFACE_BITMASK;
  }
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("live")));
  if (v != Qnil) {
    optargs_s.live = RTEST (v);
    optargs_s.bitmask |= GUESTFS_ADD_LIBVIRT_DOM_LIVE_BITMASK;
  }
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("readonlydisk")));
  if (v != Qnil) {
    optargs_s.readonlydisk = StringValueCStr (v);
    optargs_s.bitmask |= GUESTFS_ADD_LIBVIRT_DOM_READONLYDISK_BITMASK;
  }
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("cachemode")));
  if (v != Qnil) {
    optargs_s.cachemode = StringValueCStr (v);
    optargs_s.bitmask |= GUESTFS_ADD_LIBVIRT_DOM_CACHEMODE_BITMASK;
  }
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("discard")));
  if (v != Qnil) {
    optargs_s.discard = StringValueCStr (v);
    optargs_s.bitmask |= GUESTFS_ADD_LIBVIRT_DOM_DISCARD_BITMASK;
  }
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("copyonread")));
  if (v != Qnil) {
    optargs_s.copyonread = RTEST (v);
    optargs_s.bitmask |= GUESTFS_ADD_LIBVIRT_DOM_COPYONREAD_BITMASK;
  }

  int r;

  r = guestfs_add_libvirt_dom_argv (g, dom, optargs);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return INT2NUM (r);
}

/*
 * call-seq:
 *   g.aug_init(root, flags) -> nil
 *
 * create a new Augeas handle
 *
 * Create a new Augeas handle for editing configuration
 * files. If there was any previous Augeas handle
 * associated with this guestfs session, then it is closed.
 * 
 * You must call this before using any other "g.aug_*"
 * commands.
 * 
 * "root" is the filesystem root. "root" must not be NULL,
 * use / instead.
 * 
 * The flags are the same as the flags defined in
 * <augeas.h>, the logical *or* of the following integers:
 * 
 * "AUG_SAVE_BACKUP" = 1
 * Keep the original file with a ".augsave" extension.
 * 
 * "AUG_SAVE_NEWFILE" = 2
 * Save changes into a file with extension ".augnew",
 * and do not overwrite original. Overrides
 * "AUG_SAVE_BACKUP".
 * 
 * "AUG_TYPE_CHECK" = 4
 * Typecheck lenses.
 * 
 * This option is only useful when debugging Augeas
 * lenses. Use of this option may require additional
 * memory for the libguestfs appliance. You may need to
 * set the "LIBGUESTFS_MEMSIZE" environment variable or
 * call "g.set_memsize".
 * 
 * "AUG_NO_STDINC" = 8
 * Do not use standard load path for modules.
 * 
 * "AUG_SAVE_NOOP" = 16
 * Make save a no-op, just record what would have been
 * changed.
 * 
 * "AUG_NO_LOAD" = 32
 * Do not load the tree in "g.aug_init".
 * 
 * To close the handle, you can call "g.aug_close".
 * 
 * To find out more about Augeas, see <http://augeas.net/>.
 *
 *
 * [Since] Added in version 0.7.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_aug_init}[http://libguestfs.org/guestfs.3.html#guestfs_aug_init].
 */
VALUE
guestfs_int_ruby_aug_init (VALUE gv, VALUE rootv, VALUE flagsv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "aug_init");

  const char *root = StringValueCStr (rootv);
  int flags = NUM2INT (flagsv);

  int r;

  r = guestfs_aug_init (g, root, flags);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.aug_insert(augpath, label, before) -> nil
 *
 * insert a sibling Augeas node
 *
 * Create a new sibling "label" for "path", inserting it
 * into the tree before or after "path" (depending on the
 * boolean flag "before").
 * 
 * "path" must match exactly one existing node in the tree,
 * and "label" must be a label, ie. not contain /, "*" or
 * end with a bracketed index "[N]".
 *
 *
 * [Since] Added in version 0.7.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_aug_insert}[http://libguestfs.org/guestfs.3.html#guestfs_aug_insert].
 */
VALUE
guestfs_int_ruby_aug_insert (VALUE gv, VALUE augpathv, VALUE labelv, VALUE beforev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "aug_insert");

  const char *augpath = StringValueCStr (augpathv);
  const char *label = StringValueCStr (labelv);
  int before = RTEST (beforev);

  int r;

  r = guestfs_aug_insert (g, augpath, label, before);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.aug_load() -> nil
 *
 * load files into the tree
 *
 * Load files into the tree.
 * 
 * See "aug_load" in the Augeas documentation for the full
 * gory details.
 *
 *
 * [Since] Added in version 0.7.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_aug_load}[http://libguestfs.org/guestfs.3.html#guestfs_aug_load].
 */
VALUE
guestfs_int_ruby_aug_load (VALUE gv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "aug_load");


  int r;

  r = guestfs_aug_load (g);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.aug_rm(augpath) -> fixnum
 *
 * remove an Augeas path
 *
 * Remove "path" and all of its children.
 * 
 * On success this returns the number of entries which were
 * removed.
 *
 *
 * [Since] Added in version 0.7.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_aug_rm}[http://libguestfs.org/guestfs.3.html#guestfs_aug_rm].
 */
VALUE
guestfs_int_ruby_aug_rm (VALUE gv, VALUE augpathv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "aug_rm");

  const char *augpath = StringValueCStr (augpathv);

  int r;

  r = guestfs_aug_rm (g, augpath);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return INT2NUM (r);
}

/*
 * call-seq:
 *   g.aug_set(augpath, val) -> nil
 *
 * set Augeas path to value
 *
 * Set the value associated with "path" to "val".
 * 
 * In the Augeas API, it is possible to clear a node by
 * setting the value to NULL. Due to an oversight in the
 * libguestfs API you cannot do that with this call.
 * Instead you must use the "g.aug_clear" call.
 *
 *
 * [Since] Added in version 0.7.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_aug_set}[http://libguestfs.org/guestfs.3.html#guestfs_aug_set].
 */
VALUE
guestfs_int_ruby_aug_set (VALUE gv, VALUE augpathv, VALUE valv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "aug_set");

  const char *augpath = StringValueCStr (augpathv);
  const char *val = StringValueCStr (valv);

  int r;

  r = guestfs_aug_set (g, augpath, val);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.blkid(device) -> hash
 *
 * print block device attributes
 *
 * This command returns block device attributes for
 * "device". The following fields are usually present in
 * the returned hash. Other fields may also be present.
 * 
 * "UUID"
 * The uuid of this device.
 * 
 * "LABEL"
 * The label of this device.
 * 
 * "VERSION"
 * The version of blkid command.
 * 
 * "TYPE"
 * The filesystem type or RAID of this device.
 * 
 * "USAGE"
 * The usage of this device, for example "filesystem"
 * or "raid".
 *
 *
 * [Since] Added in version 1.15.9.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_blkid}[http://libguestfs.org/guestfs.3.html#guestfs_blkid].
 */
VALUE
guestfs_int_ruby_blkid (VALUE gv, VALUE devicev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "blkid");

  const char *device = StringValueCStr (devicev);

  char **r;

  r = guestfs_blkid (g, device);
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
 *   g.blockdev_setra(device, sectors) -> nil
 *
 * set readahead
 *
 * Set readahead (in 512-byte sectors) for the device.
 * 
 * This uses the blockdev(8) command.
 *
 *
 * [Since] Added in version 1.29.10.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_blockdev_setra}[http://libguestfs.org/guestfs.3.html#guestfs_blockdev_setra].
 */
VALUE
guestfs_int_ruby_blockdev_setra (VALUE gv, VALUE devicev, VALUE sectorsv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "blockdev_setra");

  const char *device = StringValueCStr (devicev);
  int sectors = NUM2INT (sectorsv);

  int r;

  r = guestfs_blockdev_setra (g, device, sectors);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.btrfs_scrub_start(path) -> nil
 *
 * read all data from all disks and verify checksums
 *
 * Reads all the data and metadata on the filesystem, and
 * uses checksums and the duplicate copies from RAID
 * storage to identify and repair any corrupt data.
 *
 *
 * [Since] Added in version 1.29.22.
 *
 * [Feature] This function depends on the feature +btrfs+.  See also {#feature_available}[rdoc-ref:feature_available].
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_btrfs_scrub_start}[http://libguestfs.org/guestfs.3.html#guestfs_btrfs_scrub_start].
 */
VALUE
guestfs_int_ruby_btrfs_scrub_start (VALUE gv, VALUE pathv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "btrfs_scrub_start");

  const char *path = StringValueCStr (pathv);

  int r;

  r = guestfs_btrfs_scrub_start (g, path);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.btrfs_scrub_status(path) -> hash
 *
 * show status of running or finished scrub
 *
 * Show status of running or finished scrub on a btrfs
 * filesystem.
 *
 *
 * [Since] Added in version 1.29.26.
 *
 * [Feature] This function depends on the feature +btrfs+.  See also {#feature_available}[rdoc-ref:feature_available].
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_btrfs_scrub_status}[http://libguestfs.org/guestfs.3.html#guestfs_btrfs_scrub_status].
 */
VALUE
guestfs_int_ruby_btrfs_scrub_status (VALUE gv, VALUE pathv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "btrfs_scrub_status");

  const char *path = StringValueCStr (pathv);

  struct guestfs_btrfsscrub *r;

  r = guestfs_btrfs_scrub_status (g, path);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  volatile VALUE rv = rb_hash_new ();
  rb_hash_aset (rv, rb_str_new2 ("btrfsscrub_data_extents_scrubbed"), ULL2NUM (r->btrfsscrub_data_extents_scrubbed));
  rb_hash_aset (rv, rb_str_new2 ("btrfsscrub_tree_extents_scrubbed"), ULL2NUM (r->btrfsscrub_tree_extents_scrubbed));
  rb_hash_aset (rv, rb_str_new2 ("btrfsscrub_data_bytes_scrubbed"), ULL2NUM (r->btrfsscrub_data_bytes_scrubbed));
  rb_hash_aset (rv, rb_str_new2 ("btrfsscrub_tree_bytes_scrubbed"), ULL2NUM (r->btrfsscrub_tree_bytes_scrubbed));
  rb_hash_aset (rv, rb_str_new2 ("btrfsscrub_read_errors"), ULL2NUM (r->btrfsscrub_read_errors));
  rb_hash_aset (rv, rb_str_new2 ("btrfsscrub_csum_errors"), ULL2NUM (r->btrfsscrub_csum_errors));
  rb_hash_aset (rv, rb_str_new2 ("btrfsscrub_verify_errors"), ULL2NUM (r->btrfsscrub_verify_errors));
  rb_hash_aset (rv, rb_str_new2 ("btrfsscrub_no_csum"), ULL2NUM (r->btrfsscrub_no_csum));
  rb_hash_aset (rv, rb_str_new2 ("btrfsscrub_csum_discards"), ULL2NUM (r->btrfsscrub_csum_discards));
  rb_hash_aset (rv, rb_str_new2 ("btrfsscrub_super_errors"), ULL2NUM (r->btrfsscrub_super_errors));
  rb_hash_aset (rv, rb_str_new2 ("btrfsscrub_malloc_errors"), ULL2NUM (r->btrfsscrub_malloc_errors));
  rb_hash_aset (rv, rb_str_new2 ("btrfsscrub_uncorrectable_errors"), ULL2NUM (r->btrfsscrub_uncorrectable_errors));
  rb_hash_aset (rv, rb_str_new2 ("btrfsscrub_unverified_errors"), ULL2NUM (r->btrfsscrub_unverified_errors));
  rb_hash_aset (rv, rb_str_new2 ("btrfsscrub_corrected_errors"), ULL2NUM (r->btrfsscrub_corrected_errors));
  rb_hash_aset (rv, rb_str_new2 ("btrfsscrub_last_physical"), ULL2NUM (r->btrfsscrub_last_physical));
  guestfs_free_btrfsscrub (r);
  return rv;
}

/*
 * call-seq:
 *   g.btrfs_subvolume_create(dest, {optargs...}) -> nil
 *
 * create a btrfs subvolume
 *
 * Create a btrfs subvolume. The "dest" argument is the
 * destination directory and the name of the subvolume, in
 * the form /path/to/dest/name. The optional parameter
 * "qgroupid" represents the qgroup which the newly created
 * subvolume will be added to.
 * 
 * Optional arguments are supplied in the final hash
 * parameter, which is a hash of the argument name to its
 * value. Pass an empty {} for no optional arguments.
 *
 *
 * [Since] Added in version 1.17.35.
 *
 * [Feature] This function depends on the feature +btrfs+.  See also {#feature_available}[rdoc-ref:feature_available].
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_btrfs_subvolume_create}[http://libguestfs.org/guestfs.3.html#guestfs_btrfs_subvolume_create].
 */
VALUE
guestfs_int_ruby_btrfs_subvolume_create (int argc, VALUE *argv, VALUE gv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "btrfs_subvolume_create");

  if (argc < 1 || argc > 2)
    rb_raise (rb_eArgError, "expecting 1 or 2 arguments");

  volatile VALUE destv = argv[0];
  volatile VALUE optargsv = argc > 1 ? argv[1] : rb_hash_new ();

  const char *dest = StringValueCStr (destv);

  Check_Type (optargsv, T_HASH);
  struct guestfs_btrfs_subvolume_create_opts_argv optargs_s = { .bitmask = 0 };
  struct guestfs_btrfs_subvolume_create_opts_argv *optargs = &optargs_s;
  volatile VALUE v;
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("qgroupid")));
  if (v != Qnil) {
    optargs_s.qgroupid = StringValueCStr (v);
    optargs_s.bitmask |= GUESTFS_BTRFS_SUBVOLUME_CREATE_OPTS_QGROUPID_BITMASK;
  }

  int r;

  r = guestfs_btrfs_subvolume_create_opts_argv (g, dest, optargs);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.btrfs_subvolume_set_default(id, fs) -> nil
 *
 * set default btrfs subvolume
 *
 * Set the subvolume of the btrfs filesystem "fs" which
 * will be mounted by default. See "g.btrfs_subvolume_list"
 * to get a list of subvolumes.
 *
 *
 * [Since] Added in version 1.17.35.
 *
 * [Feature] This function depends on the feature +btrfs+.  See also {#feature_available}[rdoc-ref:feature_available].
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_btrfs_subvolume_set_default}[http://libguestfs.org/guestfs.3.html#guestfs_btrfs_subvolume_set_default].
 */
VALUE
guestfs_int_ruby_btrfs_subvolume_set_default (VALUE gv, VALUE idv, VALUE fsv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "btrfs_subvolume_set_default");

  long long id = NUM2LL (idv);
  const char *fs = StringValueCStr (fsv);

  int r;

  r = guestfs_btrfs_subvolume_set_default (g, id, fs);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.btrfs_subvolume_snapshot(source, dest, {optargs...}) -> nil
 *
 * create a btrfs snapshot
 *
 * Create a snapshot of the btrfs subvolume "source". The
 * "dest" argument is the destination directory and the
 * name of the snapshot, in the form /path/to/dest/name. By
 * default the newly created snapshot is writable, if the
 * value of optional parameter "ro" is true, then a
 * readonly snapshot is created. The optional parameter
 * "qgroupid" represents the qgroup which the newly created
 * snapshot will be added to.
 * 
 * Optional arguments are supplied in the final hash
 * parameter, which is a hash of the argument name to its
 * value. Pass an empty {} for no optional arguments.
 *
 *
 * [Since] Added in version 1.17.35.
 *
 * [Feature] This function depends on the feature +btrfs+.  See also {#feature_available}[rdoc-ref:feature_available].
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_btrfs_subvolume_snapshot}[http://libguestfs.org/guestfs.3.html#guestfs_btrfs_subvolume_snapshot].
 */
VALUE
guestfs_int_ruby_btrfs_subvolume_snapshot (int argc, VALUE *argv, VALUE gv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "btrfs_subvolume_snapshot");

  if (argc < 2 || argc > 3)
    rb_raise (rb_eArgError, "expecting 2 or 3 arguments");

  volatile VALUE sourcev = argv[0];
  volatile VALUE destv = argv[1];
  volatile VALUE optargsv = argc > 2 ? argv[2] : rb_hash_new ();

  const char *source = StringValueCStr (sourcev);
  const char *dest = StringValueCStr (destv);

  Check_Type (optargsv, T_HASH);
  struct guestfs_btrfs_subvolume_snapshot_opts_argv optargs_s = { .bitmask = 0 };
  struct guestfs_btrfs_subvolume_snapshot_opts_argv *optargs = &optargs_s;
  volatile VALUE v;
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("ro")));
  if (v != Qnil) {
    optargs_s.ro = RTEST (v);
    optargs_s.bitmask |= GUESTFS_BTRFS_SUBVOLUME_SNAPSHOT_OPTS_RO_BITMASK;
  }
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("qgroupid")));
  if (v != Qnil) {
    optargs_s.qgroupid = StringValueCStr (v);
    optargs_s.bitmask |= GUESTFS_BTRFS_SUBVOLUME_SNAPSHOT_OPTS_QGROUPID_BITMASK;
  }

  int r;

  r = guestfs_btrfs_subvolume_snapshot_opts_argv (g, source, dest, optargs);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.canonical_device_name(device) -> string
 *
 * return canonical device name
 *
 * This utility function is useful when displaying device
 * names to the user. It takes a number of irregular device
 * names and returns them in a consistent format:
 * 
 * /dev/hdX
 * /dev/vdX
 * These are returned as /dev/sdX. Note this works for
 * device names and partition names. This is
 * approximately the reverse of the algorithm described
 * in "BLOCK DEVICE NAMING" in guestfs(3).
 * 
 * /dev/mapper/VG-LV
 * /dev/dm-N
 * Converted to /dev/VG/LV form using
 * "g.lvm_canonical_lv_name".
 * 
 * Other strings are returned unmodified.
 *
 *
 * [Since] Added in version 1.19.7.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_canonical_device_name}[http://libguestfs.org/guestfs.3.html#guestfs_canonical_device_name].
 */
VALUE
guestfs_int_ruby_canonical_device_name (VALUE gv, VALUE devicev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "canonical_device_name");

  const char *device = StringValueCStr (devicev);

  char *r;

  r = guestfs_canonical_device_name (g, device);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  volatile VALUE rv = rb_str_new2 (r);
  free (r);
  return rv;
}

/*
 * call-seq:
 *   g.case_sensitive_path(path) -> string
 *
 * return true path on case-insensitive filesystem
 *
 * This can be used to resolve case insensitive paths on a
 * filesystem which is case sensitive. The use case is to
 * resolve paths which you have read from Windows
 * configuration files or the Windows Registry, to the true
 * path.
 * 
 * The command handles a peculiarity of the Linux ntfs-3g
 * filesystem driver (and probably others), which is that
 * although the underlying filesystem is case-insensitive,
 * the driver exports the filesystem to Linux as
 * case-sensitive.
 * 
 * One consequence of this is that special directories such
 * as C:\windows may appear as /WINDOWS or /windows (or
 * other things) depending on the precise details of how
 * they were created. In Windows itself this would not be a
 * problem.
 * 
 * Bug or feature? You decide:
 * <http://www.tuxera.com/community/ntfs-3g-faq/#posixfilen
 * ames1>
 * 
 * "g.case_sensitive_path" attempts to resolve the true
 * case of each element in the path. It will return a
 * resolved path if either the full path or its parent
 * directory exists. If the parent directory exists but the
 * full path does not, the case of the parent directory
 * will be correctly resolved, and the remainder appended
 * unmodified. For example, if the file
 * "/Windows/System32/netkvm.sys" exists:
 * 
 * "g.case_sensitive_path" ("/windows/system32/netkvm.sys")
 * "Windows/System32/netkvm.sys"
 * 
 * "g.case_sensitive_path" ("/windows/system32/NoSuchFile")
 * "Windows/System32/NoSuchFile"
 * 
 * "g.case_sensitive_path" ("/windows/system33/netkvm.sys")
 * *ERROR*
 * 
 * *Note*: Because of the above behaviour,
 * "g.case_sensitive_path" cannot be used to check for the
 * existence of a file.
 * 
 * *Note*: This function does not handle drive names,
 * backslashes etc.
 * 
 * See also "g.realpath".
 *
 *
 * [Since] Added in version 1.0.75.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_case_sensitive_path}[http://libguestfs.org/guestfs.3.html#guestfs_case_sensitive_path].
 */
VALUE
guestfs_int_ruby_case_sensitive_path (VALUE gv, VALUE pathv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "case_sensitive_path");

  const char *path = StringValueCStr (pathv);

  char *r;

  r = guestfs_case_sensitive_path (g, path);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  volatile VALUE rv = rb_str_new2 (r);
  free (r);
  return rv;
}

/*
 * call-seq:
 *   g.copy_size(src, dest, size) -> nil
 *
 * copy size bytes from source to destination using dd
 *
 * This command copies exactly "size" bytes from one source
 * device or file "src" to another destination device or
 * file "dest".
 * 
 * Note this will fail if the source is too short or if the
 * destination is not large enough.
 *
 *
 * [Since] Added in version 1.0.87.
 *
 * [Deprecated] In new code, use rdoc-ref:copy_device_to_device instead.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_copy_size}[http://libguestfs.org/guestfs.3.html#guestfs_copy_size].
 */
VALUE
guestfs_int_ruby_copy_size (VALUE gv, VALUE srcv, VALUE destv, VALUE sizev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "copy_size");

  const char *src = StringValueCStr (srcv);
  const char *dest = StringValueCStr (destv);
  long long size = NUM2LL (sizev);

  int r;

  r = guestfs_copy_size (g, src, dest, size);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.debug_upload
 *
 * :nodoc:
 */
VALUE
guestfs_int_ruby_debug_upload (VALUE gv, VALUE filenamev, VALUE tmpnamev, VALUE modev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "debug_upload");

  const char *filename = StringValueCStr (filenamev);
  const char *tmpname = StringValueCStr (tmpnamev);
  int mode = NUM2INT (modev);

  int r;

  r = guestfs_debug_upload (g, filename, tmpname, mode);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.download_offset(remotefilename, filename, offset, size) -> nil
 *
 * download a file to the local machine with offset and size
 *
 * Download file remotefilename and save it as filename on
 * the local machine.
 * 
 * remotefilename is read for "size" bytes starting at
 * "offset" (this region must be within the file or
 * device).
 * 
 * Note that there is no limit on the amount of data that
 * can be downloaded with this call, unlike with "g.pread",
 * and this call always reads the full amount unless an
 * error occurs.
 * 
 * See also "g.download", "g.pread".
 *
 *
 * [Since] Added in version 1.5.17.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_download_offset}[http://libguestfs.org/guestfs.3.html#guestfs_download_offset].
 */
VALUE
guestfs_int_ruby_download_offset (VALUE gv, VALUE remotefilenamev, VALUE filenamev, VALUE offsetv, VALUE sizev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "download_offset");

  const char *remotefilename = StringValueCStr (remotefilenamev);
  const char *filename = StringValueCStr (filenamev);
  long long offset = NUM2LL (offsetv);
  long long size = NUM2LL (sizev);

  int r;

  r = guestfs_download_offset (g, remotefilename, filename, offset, size);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.findfs_uuid(uuid) -> string
 *
 * find a filesystem by UUID
 *
 * This command searches the filesystems and returns the
 * one which has the given UUID. An error is returned if no
 * such filesystem can be found.
 * 
 * To find the UUID of a filesystem, use "g.vfs_uuid".
 *
 *
 * [Since] Added in version 1.5.3.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_findfs_uuid}[http://libguestfs.org/guestfs.3.html#guestfs_findfs_uuid].
 */
VALUE
guestfs_int_ruby_findfs_uuid (VALUE gv, VALUE uuidv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "findfs_uuid");

  const char *uuid = StringValueCStr (uuidv);

  char *r;

  r = guestfs_findfs_uuid (g, uuid);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  volatile VALUE rv = rb_str_new2 (r);
  free (r);
  return rv;
}

/*
 * call-seq:
 *   g.fstrim(mountpoint, {optargs...}) -> nil
 *
 * trim free space in a filesystem
 *
 * Trim the free space in the filesystem mounted on
 * "mountpoint". The filesystem must be mounted read-write.
 * 
 * The filesystem contents are not affected, but any free
 * space in the filesystem is "trimmed", that is, given
 * back to the host device, thus making disk images more
 * sparse, allowing unused space in qcow2 files to be
 * reused, etc.
 * 
 * This operation requires support in libguestfs, the
 * mounted filesystem, the host filesystem, qemu and the
 * host kernel. If this support isn't present it may give
 * an error or even appear to run but do nothing.
 * 
 * In the case where the kernel vfs driver does not support
 * trimming, this call will fail with errno set to
 * "ENOTSUP". Currently this happens when trying to trim
 * FAT filesystems.
 * 
 * See also "g.zero_free_space". That is a slightly
 * different operation that turns free space in the
 * filesystem into zeroes. It is valid to call "g.fstrim"
 * either instead of, or after calling "g.zero_free_space".
 * 
 * Optional arguments are supplied in the final hash
 * parameter, which is a hash of the argument name to its
 * value. Pass an empty {} for no optional arguments.
 *
 *
 * [Since] Added in version 1.19.6.
 *
 * [Feature] This function depends on the feature +fstrim+.  See also {#feature_available}[rdoc-ref:feature_available].
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_fstrim}[http://libguestfs.org/guestfs.3.html#guestfs_fstrim].
 */
VALUE
guestfs_int_ruby_fstrim (int argc, VALUE *argv, VALUE gv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "fstrim");

  if (argc < 1 || argc > 2)
    rb_raise (rb_eArgError, "expecting 1 or 2 arguments");

  volatile VALUE mountpointv = argv[0];
  volatile VALUE optargsv = argc > 1 ? argv[1] : rb_hash_new ();

  const char *mountpoint = StringValueCStr (mountpointv);

  Check_Type (optargsv, T_HASH);
  struct guestfs_fstrim_argv optargs_s = { .bitmask = 0 };
  struct guestfs_fstrim_argv *optargs = &optargs_s;
  volatile VALUE v;
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("offset")));
  if (v != Qnil) {
    optargs_s.offset = NUM2LL (v);
    optargs_s.bitmask |= GUESTFS_FSTRIM_OFFSET_BITMASK;
  }
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("length")));
  if (v != Qnil) {
    optargs_s.length = NUM2LL (v);
    optargs_s.bitmask |= GUESTFS_FSTRIM_LENGTH_BITMASK;
  }
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("minimumfreeextent")));
  if (v != Qnil) {
    optargs_s.minimumfreeextent = NUM2LL (v);
    optargs_s.bitmask |= GUESTFS_FSTRIM_MINIMUMFREEEXTENT_BITMASK;
  }

  int r;

  r = guestfs_fstrim_argv (g, mountpoint, optargs);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.get_autosync() -> [True|False]
 *
 * get autosync mode
 *
 * Get the autosync flag.
 *
 *
 * [Since] Added in version 0.3.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_get_autosync}[http://libguestfs.org/guestfs.3.html#guestfs_get_autosync].
 */
VALUE
guestfs_int_ruby_get_autosync (VALUE gv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "get_autosync");


  int r;

  r = guestfs_get_autosync (g);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return INT2NUM (r);
}

/*
 * call-seq:
 *   g.get_e2uuid(device) -> string
 *
 * get the ext2/3/4 filesystem UUID
 *
 * This returns the ext2/3/4 filesystem UUID of the
 * filesystem on "device".
 *
 *
 * [Since] Added in version 1.0.15.
 *
 * [Deprecated] In new code, use rdoc-ref:vfs_uuid instead.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_get_e2uuid}[http://libguestfs.org/guestfs.3.html#guestfs_get_e2uuid].
 */
VALUE
guestfs_int_ruby_get_e2uuid (VALUE gv, VALUE devicev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "get_e2uuid");

  const char *device = StringValueCStr (devicev);

  char *r;

  r = guestfs_get_e2uuid (g, device);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  volatile VALUE rv = rb_str_new2 (r);
  free (r);
  return rv;
}

/*
 * call-seq:
 *   g.get_libvirt_requested_credential_challenge(index) -> string
 *
 * challenge of i'th requested credential
 *
 * Get the challenge (provided by libvirt) for the
 * "index"'th requested credential. If libvirt did not
 * provide a challenge, this returns the empty string "".
 * 
 * See "LIBVIRT AUTHENTICATION" in guestfs(3) for
 * documentation and example code.
 *
 *
 * [Since] Added in version 1.19.52.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_get_libvirt_requested_credential_challenge}[http://libguestfs.org/guestfs.3.html#guestfs_get_libvirt_requested_credential_challenge].
 */
VALUE
guestfs_int_ruby_get_libvirt_requested_credential_challenge (VALUE gv, VALUE indexv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "get_libvirt_requested_credential_challenge");

  int index = NUM2INT (indexv);

  char *r;

  r = guestfs_get_libvirt_requested_credential_challenge (g, index);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  volatile VALUE rv = rb_str_new2 (r);
  free (r);
  return rv;
}

/*
 * call-seq:
 *   g.get_pid() -> fixnum
 *
 * get PID of hypervisor
 *
 * Return the process ID of the hypervisor. If there is no
 * hypervisor running, then this will return an error.
 * 
 * This is an internal call used for debugging and testing.
 *
 *
 * [Since] Added in version 1.0.56.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_get_pid}[http://libguestfs.org/guestfs.3.html#guestfs_get_pid].
 */
VALUE
guestfs_int_ruby_get_pid (VALUE gv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "get_pid");


  int r;

  r = guestfs_get_pid (g);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return INT2NUM (r);
}

/*
 * call-seq:
 *   g.get_selinux() -> [True|False]
 *
 * get SELinux enabled flag
 *
 * This returns the current setting of the selinux flag
 * which is passed to the appliance at boot time. See
 * "g.set_selinux".
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
 *         {guestfs_get_selinux}[http://libguestfs.org/guestfs.3.html#guestfs_get_selinux].
 */
VALUE
guestfs_int_ruby_get_selinux (VALUE gv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "get_selinux");


  int r;

  r = guestfs_get_selinux (g);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return INT2NUM (r);
}

/*
 * call-seq:
 *   g.grepi(regex, path) -> list
 *
 * return lines matching a pattern
 *
 * This calls the external "grep -i" program and returns
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
 *         {guestfs_grepi}[http://libguestfs.org/guestfs.3.html#guestfs_grepi].
 */
VALUE
guestfs_int_ruby_grepi (VALUE gv, VALUE regexv, VALUE pathv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "grepi");

  const char *regex = StringValueCStr (regexv);
  const char *path = StringValueCStr (pathv);

  char **r;

  r = guestfs_grepi (g, regex, path);
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
 *   g.hexdump(path) -> string
 *
 * dump a file in hexadecimal
 *
 * This runs "hexdump -C" on the given "path". The result
 * is the human-readable, canonical hex dump of the file.
 * 
 * Because of the message protocol, there is a transfer
 * limit of somewhere between 2MB and 4MB. See "PROTOCOL
 * LIMITS" in guestfs(3).
 *
 *
 * [Since] Added in version 1.0.22.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_hexdump}[http://libguestfs.org/guestfs.3.html#guestfs_hexdump].
 */
VALUE
guestfs_int_ruby_hexdump (VALUE gv, VALUE pathv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "hexdump");

  const char *path = StringValueCStr (pathv);

  char *r;

  r = guestfs_hexdump (g, path);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  volatile VALUE rv = rb_str_new2 (r);
  free (r);
  return rv;
}

/*
 * call-seq:
 *   g.hivex_node_children(nodeh) -> list
 *
 * return list of nodes which are subkeys of node
 *
 * Return the list of nodes which are subkeys of "nodeh".
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
 *         {guestfs_hivex_node_children}[http://libguestfs.org/guestfs.3.html#guestfs_hivex_node_children].
 */
VALUE
guestfs_int_ruby_hivex_node_children (VALUE gv, VALUE nodehv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "hivex_node_children");

  long long nodeh = NUM2LL (nodehv);

  struct guestfs_hivex_node_list *r;

  r = guestfs_hivex_node_children (g, nodeh);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  volatile VALUE rv = rb_ary_new2 (r->len);
  size_t i;
  for (i = 0; i < r->len; ++i) {
    volatile VALUE hv = rb_hash_new ();
    rb_hash_aset (hv, rb_str_new2 ("hivex_node_h"), LL2NUM (r->val[i].hivex_node_h));
    rb_ary_push (rv, hv);
  }
  guestfs_free_hivex_node_list (r);
  return rv;
}

/*
 * call-seq:
 *   g.inspect_get_format(root) -> string
 *
 * get format of inspected operating system
 *
 * This returns the format of the inspected operating
 * system. You can use it to detect install images, live
 * CDs and similar.
 * 
 * Currently defined formats are:
 * 
 * "installed"
 * This is an installed operating system.
 * 
 * "installer"
 * The disk image being inspected is not an installed
 * operating system, but a *bootable* install disk,
 * live CD, or similar.
 * 
 * "unknown"
 * The format of this disk image is not known.
 * 
 * Future versions of libguestfs may return other strings
 * here. The caller should be prepared to handle any
 * string.
 * 
 * Please read "INSPECTION" in guestfs(3) for more details.
 *
 *
 * [Since] Added in version 1.9.4.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_inspect_get_format}[http://libguestfs.org/guestfs.3.html#guestfs_inspect_get_format].
 */
VALUE
guestfs_int_ruby_inspect_get_format (VALUE gv, VALUE rootv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "inspect_get_format");

  const char *root = StringValueCStr (rootv);

  char *r;

  r = guestfs_inspect_get_format (g, root);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  volatile VALUE rv = rb_str_new2 (r);
  free (r);
  return rv;
}

/*
 * call-seq:
 *   g.inspect_get_hostname(root) -> string
 *
 * get hostname of the operating system
 *
 * This function returns the hostname of the operating
 * system as found by inspection of the guest's
 * configuration files.
 * 
 * If the hostname could not be determined, then the string
 * "unknown" is returned.
 * 
 * Please read "INSPECTION" in guestfs(3) for more details.
 *
 *
 * [Since] Added in version 1.7.9.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_inspect_get_hostname}[http://libguestfs.org/guestfs.3.html#guestfs_inspect_get_hostname].
 */
VALUE
guestfs_int_ruby_inspect_get_hostname (VALUE gv, VALUE rootv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "inspect_get_hostname");

  const char *root = StringValueCStr (rootv);

  char *r;

  r = guestfs_inspect_get_hostname (g, root);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  volatile VALUE rv = rb_str_new2 (r);
  free (r);
  return rv;
}

/*
 * call-seq:
 *   g.inspect_is_multipart(root) -> [True|False]
 *
 * get multipart flag for install disk
 *
 * If "g.inspect_get_format" returns "installer" (this is
 * an install disk), then this returns true if the disk is
 * part of a set.
 * 
 * Please read "INSPECTION" in guestfs(3) for more details.
 *
 *
 * [Since] Added in version 1.9.4.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_inspect_is_multipart}[http://libguestfs.org/guestfs.3.html#guestfs_inspect_is_multipart].
 */
VALUE
guestfs_int_ruby_inspect_is_multipart (VALUE gv, VALUE rootv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "inspect_is_multipart");

  const char *root = StringValueCStr (rootv);

  int r;

  r = guestfs_inspect_is_multipart (g, root);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return INT2NUM (r);
}

/*
 * call-seq:
 *   g.internal_test_rbool
 *
 * :nodoc:
 */
VALUE
guestfs_int_ruby_internal_test_rbool (VALUE gv, VALUE valv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "internal_test_rbool");

  const char *val = StringValueCStr (valv);

  int r;

  r = guestfs_internal_test_rbool (g, val);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return INT2NUM (r);
}

/*
 * call-seq:
 *   g.internal_test_rhashtable
 *
 * :nodoc:
 */
VALUE
guestfs_int_ruby_internal_test_rhashtable (VALUE gv, VALUE valv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "internal_test_rhashtable");

  const char *val = StringValueCStr (valv);

  char **r;

  r = guestfs_internal_test_rhashtable (g, val);
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
 *   g.internal_test_rstringlist
 *
 * :nodoc:
 */
VALUE
guestfs_int_ruby_internal_test_rstringlist (VALUE gv, VALUE valv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "internal_test_rstringlist");

  const char *val = StringValueCStr (valv);

  char **r;

  r = guestfs_internal_test_rstringlist (g, val);
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
 *   g.internal_test_rstringlisterr
 *
 * :nodoc:
 */
VALUE
guestfs_int_ruby_internal_test_rstringlisterr (VALUE gv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "internal_test_rstringlisterr");


  char **r;

  r = guestfs_internal_test_rstringlisterr (g);
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
 *   g.is_busy() -> [True|False]
 *
 * is busy processing a command
 *
 * This always returns false. This function is deprecated
 * with no replacement. Do not use this function.
 * 
 * For more information on states, see guestfs(3).
 *
 *
 * [Since] Added in version 1.0.2.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_is_busy}[http://libguestfs.org/guestfs.3.html#guestfs_is_busy].
 */
VALUE
guestfs_int_ruby_is_busy (VALUE gv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "is_busy");


  int r;

  r = guestfs_is_busy (g);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return INT2NUM (r);
}

/*
 * call-seq:
 *   g.is_ready() -> [True|False]
 *
 * is ready to accept commands
 *
 * This returns true iff this handle is ready to accept
 * commands (in the "READY" state).
 * 
 * For more information on states, see guestfs(3).
 *
 *
 * [Since] Added in version 1.0.2.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_is_ready}[http://libguestfs.org/guestfs.3.html#guestfs_is_ready].
 */
VALUE
guestfs_int_ruby_is_ready (VALUE gv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "is_ready");


  int r;

  r = guestfs_is_ready (g);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return INT2NUM (r);
}

/*
 * call-seq:
 *   g.ldmtool_scan() -> list
 *
 * scan for Windows dynamic disks
 *
 * This function scans for Windows dynamic disks. It
 * returns a list of identifiers (GUIDs) for all disk
 * groups that were found. These identifiers can be passed
 * to other "g.ldmtool_*" functions.
 * 
 * This function scans all block devices. To scan a subset
 * of block devices, call "g.ldmtool_scan_devices" instead.
 *
 *
 * [Since] Added in version 1.20.0.
 *
 * [Feature] This function depends on the feature +ldm+.  See also {#feature_available}[rdoc-ref:feature_available].
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_ldmtool_scan}[http://libguestfs.org/guestfs.3.html#guestfs_ldmtool_scan].
 */
VALUE
guestfs_int_ruby_ldmtool_scan (VALUE gv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "ldmtool_scan");


  char **r;

  r = guestfs_ldmtool_scan (g);
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
 *   g.lgetxattrs(path) -> list
 *
 * list extended attributes of a file or directory
 *
 * This is the same as "g.getxattrs", but if "path" is a
 * symbolic link, then it returns the extended attributes
 * of the link itself.
 *
 *
 * [Since] Added in version 1.0.59.
 *
 * [Feature] This function depends on the feature +linuxxattrs+.  See also {#feature_available}[rdoc-ref:feature_available].
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_lgetxattrs}[http://libguestfs.org/guestfs.3.html#guestfs_lgetxattrs].
 */
VALUE
guestfs_int_ruby_lgetxattrs (VALUE gv, VALUE pathv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "lgetxattrs");

  const char *path = StringValueCStr (pathv);

  struct guestfs_xattr_list *r;

  r = guestfs_lgetxattrs (g, path);
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
 *   g.list_dm_devices() -> list
 *
 * list device mapper devices
 *
 * List all device mapper devices.
 * 
 * The returned list contains /dev/mapper/ * devices, eg.
 * ones created by a previous call to "g.luks_open".
 * 
 * Device mapper devices which correspond to logical
 * volumes are *not* returned in this list. Call "g.lvs" if
 * you want to list logical volumes.
 *
 *
 * [Since] Added in version 1.11.15.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_list_dm_devices}[http://libguestfs.org/guestfs.3.html#guestfs_list_dm_devices].
 */
VALUE
guestfs_int_ruby_list_dm_devices (VALUE gv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "list_dm_devices");


  char **r;

  r = guestfs_list_dm_devices (g);
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
 *   g.list_ldm_volumes() -> list
 *
 * list all Windows dynamic disk volumes
 *
 * This function returns all Windows dynamic disk volumes
 * that were found at launch time. It returns a list of
 * device names.
 *
 *
 * [Since] Added in version 1.20.0.
 *
 * [Feature] This function depends on the feature +ldm+.  See also {#feature_available}[rdoc-ref:feature_available].
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_list_ldm_volumes}[http://libguestfs.org/guestfs.3.html#guestfs_list_ldm_volumes].
 */
VALUE
guestfs_int_ruby_list_ldm_volumes (VALUE gv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "list_ldm_volumes");


  char **r;

  r = guestfs_list_ldm_volumes (g);
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
 *   g.luks_format(device, key, keyslot) -> nil
 *
 * format a block device as a LUKS encrypted device
 *
 * This command erases existing data on "device" and
 * formats the device as a LUKS encrypted device. "key" is
 * the initial key, which is added to key slot "slot".
 * (LUKS supports 8 key slots, numbered 0-7).
 *
 *
 * [Since] Added in version 1.5.2.
 *
 * [Feature] This function depends on the feature +luks+.  See also {#feature_available}[rdoc-ref:feature_available].
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_luks_format}[http://libguestfs.org/guestfs.3.html#guestfs_luks_format].
 */
VALUE
guestfs_int_ruby_luks_format (VALUE gv, VALUE devicev, VALUE keyv, VALUE keyslotv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "luks_format");

  const char *device = StringValueCStr (devicev);
  const char *key = StringValueCStr (keyv);
  int keyslot = NUM2INT (keyslotv);

  int r;

  r = guestfs_luks_format (g, device, key, keyslot);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.lvm_canonical_lv_name(lvname) -> string
 *
 * get canonical name of an LV
 *
 * This converts alternative naming schemes for LVs that
 * you might find to the canonical name. For example,
 * /dev/mapper/VG-LV is converted to /dev/VG/LV.
 * 
 * This command returns an error if the "lvname" parameter
 * does not refer to a logical volume.
 * 
 * See also "g.is_lv", "g.canonical_device_name".
 *
 *
 * [Since] Added in version 1.5.24.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_lvm_canonical_lv_name}[http://libguestfs.org/guestfs.3.html#guestfs_lvm_canonical_lv_name].
 */
VALUE
guestfs_int_ruby_lvm_canonical_lv_name (VALUE gv, VALUE lvnamev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "lvm_canonical_lv_name");

  const char *lvname = StringValueCStr (lvnamev);

  char *r;

  r = guestfs_lvm_canonical_lv_name (g, lvname);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  volatile VALUE rv = rb_str_new2 (r);
  free (r);
  return rv;
}

/*
 * call-seq:
 *   g.lvrename(logvol, newlogvol) -> nil
 *
 * rename an LVM logical volume
 *
 * Rename a logical volume "logvol" with the new name
 * "newlogvol".
 *
 *
 * [Since] Added in version 1.0.83.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_lvrename}[http://libguestfs.org/guestfs.3.html#guestfs_lvrename].
 */
VALUE
guestfs_int_ruby_lvrename (VALUE gv, VALUE logvolv, VALUE newlogvolv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "lvrename");

  const char *logvol = StringValueCStr (logvolv);
  const char *newlogvol = StringValueCStr (newlogvolv);

  int r;

  r = guestfs_lvrename (g, logvol, newlogvol);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.lvresize(device, mbytes) -> nil
 *
 * resize an LVM logical volume
 *
 * This resizes (expands or shrinks) an existing LVM
 * logical volume to "mbytes". When reducing, data in the
 * reduced part is lost.
 *
 *
 * [Since] Added in version 1.0.27.
 *
 * [Feature] This function depends on the feature +lvm2+.  See also {#feature_available}[rdoc-ref:feature_available].
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_lvresize}[http://libguestfs.org/guestfs.3.html#guestfs_lvresize].
 */
VALUE
guestfs_int_ruby_lvresize (VALUE gv, VALUE devicev, VALUE mbytesv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "lvresize");

  const char *device = StringValueCStr (devicev);
  int mbytes = NUM2INT (mbytesv);

  int r;

  r = guestfs_lvresize (g, device, mbytes);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.lvuuid(device) -> string
 *
 * get the UUID of a logical volume
 *
 * This command returns the UUID of the LVM LV "device".
 *
 *
 * [Since] Added in version 1.0.87.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_lvuuid}[http://libguestfs.org/guestfs.3.html#guestfs_lvuuid].
 */
VALUE
guestfs_int_ruby_lvuuid (VALUE gv, VALUE devicev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "lvuuid");

  const char *device = StringValueCStr (devicev);

  char *r;

  r = guestfs_lvuuid (g, device);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  volatile VALUE rv = rb_str_new2 (r);
  free (r);
  return rv;
}

/*
 * call-seq:
 *   g.mke2fs_J(fstype, blocksize, device, journal) -> nil
 *
 * make ext2/3/4 filesystem with external journal
 *
 * This creates an ext2/3/4 filesystem on "device" with an
 * external journal on "journal". It is equivalent to the
 * command:
 * 
 * mke2fs -t fstype -b blocksize -J device=<journal> <device>
 * 
 * See also "g.mke2journal".
 *
 *
 * [Since] Added in version 1.0.68.
 *
 * [Deprecated] In new code, use rdoc-ref:mke2fs instead.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_mke2fs_J}[http://libguestfs.org/guestfs.3.html#guestfs_mke2fs_J].
 */
VALUE
guestfs_int_ruby_mke2fs_J (VALUE gv, VALUE fstypev, VALUE blocksizev, VALUE devicev, VALUE journalv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "mke2fs_J");

  const char *fstype = StringValueCStr (fstypev);
  int blocksize = NUM2INT (blocksizev);
  const char *device = StringValueCStr (devicev);
  const char *journal = StringValueCStr (journalv);

  int r;

  r = guestfs_mke2fs_J (g, fstype, blocksize, device, journal);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.mke2journal_U(blocksize, uuid, device) -> nil
 *
 * make ext2/3/4 external journal with UUID
 *
 * This creates an ext2 external journal on "device" with
 * UUID "uuid".
 *
 *
 * [Since] Added in version 1.0.68.
 *
 * [Deprecated] In new code, use rdoc-ref:mke2fs instead.
 *
 * [Feature] This function depends on the feature +linuxfsuuid+.  See also {#feature_available}[rdoc-ref:feature_available].
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_mke2journal_U}[http://libguestfs.org/guestfs.3.html#guestfs_mke2journal_U].
 */
VALUE
guestfs_int_ruby_mke2journal_U (VALUE gv, VALUE blocksizev, VALUE uuidv, VALUE devicev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "mke2journal_U");

  int blocksize = NUM2INT (blocksizev);
  const char *uuid = StringValueCStr (uuidv);
  const char *device = StringValueCStr (devicev);

  int r;

  r = guestfs_mke2journal_U (g, blocksize, uuid, device);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.mknod_c(mode, devmajor, devminor, path) -> nil
 *
 * make char device node
 *
 * This call creates a char device node called "path" with
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
 *         {guestfs_mknod_c}[http://libguestfs.org/guestfs.3.html#guestfs_mknod_c].
 */
VALUE
guestfs_int_ruby_mknod_c (VALUE gv, VALUE modev, VALUE devmajorv, VALUE devminorv, VALUE pathv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "mknod_c");

  int mode = NUM2INT (modev);
  int devmajor = NUM2INT (devmajorv);
  int devminor = NUM2INT (devminorv);
  const char *path = StringValueCStr (pathv);

  int r;

  r = guestfs_mknod_c (g, mode, devmajor, devminor, path);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.mount_options(options, mountable, mountpoint) -> nil
 *
 * mount a guest disk with mount options
 *
 * This is the same as the "g.mount" command, but it allows
 * you to set the mount options as for the mount(8) *-o*
 * flag.
 * 
 * If the "options" parameter is an empty string, then no
 * options are passed (all options default to whatever the
 * filesystem uses).
 *
 *
 * [Since] Added in version 1.0.10.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_mount_options}[http://libguestfs.org/guestfs.3.html#guestfs_mount_options].
 */
VALUE
guestfs_int_ruby_mount_options (VALUE gv, VALUE optionsv, VALUE mountablev, VALUE mountpointv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "mount_options");

  const char *options = StringValueCStr (optionsv);
  const char *mountable = StringValueCStr (mountablev);
  const char *mountpoint = StringValueCStr (mountpointv);

  int r;

  r = guestfs_mount_options (g, options, mountable, mountpoint);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.ntfsfix(device, {optargs...}) -> nil
 *
 * fix common errors and force Windows to check NTFS
 *
 * This command repairs some fundamental NTFS
 * inconsistencies, resets the NTFS journal file, and
 * schedules an NTFS consistency check for the first boot
 * into Windows.
 * 
 * This is *not* an equivalent of Windows "chkdsk". It does
 * *not* scan the filesystem for inconsistencies.
 * 
 * The optional "clearbadsectors" flag clears the list of
 * bad sectors. This is useful after cloning a disk with
 * bad sectors to a new disk.
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
 *         {guestfs_ntfsfix}[http://libguestfs.org/guestfs.3.html#guestfs_ntfsfix].
 */
VALUE
guestfs_int_ruby_ntfsfix (int argc, VALUE *argv, VALUE gv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "ntfsfix");

  if (argc < 1 || argc > 2)
    rb_raise (rb_eArgError, "expecting 1 or 2 arguments");

  volatile VALUE devicev = argv[0];
  volatile VALUE optargsv = argc > 1 ? argv[1] : rb_hash_new ();

  const char *device = StringValueCStr (devicev);

  Check_Type (optargsv, T_HASH);
  struct guestfs_ntfsfix_argv optargs_s = { .bitmask = 0 };
  struct guestfs_ntfsfix_argv *optargs = &optargs_s;
  volatile VALUE v;
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("clearbadsectors")));
  if (v != Qnil) {
    optargs_s.clearbadsectors = RTEST (v);
    optargs_s.bitmask |= GUESTFS_NTFSFIX_CLEARBADSECTORS_BITMASK;
  }

  int r;

  r = guestfs_ntfsfix_argv (g, device, optargs);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.part_add(device, prlogex, startsect, endsect) -> nil
 *
 * add a partition to the device
 *
 * This command adds a partition to "device". If there is
 * no partition table on the device, call "g.part_init"
 * first.
 * 
 * The "prlogex" parameter is the type of partition.
 * Normally you should pass "p" or "primary" here, but MBR
 * partition tables also support "l" (or "logical") and "e"
 * (or "extended") partition types.
 * 
 * "startsect" and "endsect" are the start and end of the
 * partition in *sectors*. "endsect" may be negative, which
 * means it counts backwards from the end of the disk (-1
 * is the last sector).
 * 
 * Creating a partition which covers the whole disk is not
 * so easy. Use "g.part_disk" to do that.
 *
 *
 * [Since] Added in version 1.0.78.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_part_add}[http://libguestfs.org/guestfs.3.html#guestfs_part_add].
 */
VALUE
guestfs_int_ruby_part_add (VALUE gv, VALUE devicev, VALUE prlogexv, VALUE startsectv, VALUE endsectv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "part_add");

  const char *device = StringValueCStr (devicev);
  const char *prlogex = StringValueCStr (prlogexv);
  long long startsect = NUM2LL (startsectv);
  long long endsect = NUM2LL (endsectv);

  int r;

  r = guestfs_part_add (g, device, prlogex, startsect, endsect);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.part_get_gpt_guid(device, partnum) -> string
 *
 * get the GUID of a GPT partition
 *
 * Return the GUID of numbered GPT partition "partnum".
 *
 *
 * [Since] Added in version 1.29.25.
 *
 * [Feature] This function depends on the feature +gdisk+.  See also {#feature_available}[rdoc-ref:feature_available].
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_part_get_gpt_guid}[http://libguestfs.org/guestfs.3.html#guestfs_part_get_gpt_guid].
 */
VALUE
guestfs_int_ruby_part_get_gpt_guid (VALUE gv, VALUE devicev, VALUE partnumv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "part_get_gpt_guid");

  const char *device = StringValueCStr (devicev);
  int partnum = NUM2INT (partnumv);

  char *r;

  r = guestfs_part_get_gpt_guid (g, device, partnum);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  volatile VALUE rv = rb_str_new2 (r);
  free (r);
  return rv;
}

/*
 * call-seq:
 *   g.part_get_mbr_id(device, partnum) -> fixnum
 *
 * get the MBR type byte (ID byte) from a partition
 *
 * Returns the MBR type byte (also known as the ID byte)
 * from the numbered partition "partnum".
 * 
 * Note that only MBR (old DOS-style) partitions have type
 * bytes. You will get undefined results for other
 * partition table types (see "g.part_get_parttype").
 *
 *
 * [Since] Added in version 1.3.2.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_part_get_mbr_id}[http://libguestfs.org/guestfs.3.html#guestfs_part_get_mbr_id].
 */
VALUE
guestfs_int_ruby_part_get_mbr_id (VALUE gv, VALUE devicev, VALUE partnumv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "part_get_mbr_id");

  const char *device = StringValueCStr (devicev);
  int partnum = NUM2INT (partnumv);

  int r;

  r = guestfs_part_get_mbr_id (g, device, partnum);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return INT2NUM (r);
}

/*
 * call-seq:
 *   g.part_get_mbr_part_type(device, partnum) -> string
 *
 * get the MBR partition type
 *
 * This returns the partition type of an MBR partition
 * numbered "partnum" on device "device".
 * 
 * It returns "primary", "logical", or "extended".
 *
 *
 * [Since] Added in version 1.29.32.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_part_get_mbr_part_type}[http://libguestfs.org/guestfs.3.html#guestfs_part_get_mbr_part_type].
 */
VALUE
guestfs_int_ruby_part_get_mbr_part_type (VALUE gv, VALUE devicev, VALUE partnumv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "part_get_mbr_part_type");

  const char *device = StringValueCStr (devicev);
  int partnum = NUM2INT (partnumv);

  char *r;

  r = guestfs_part_get_mbr_part_type (g, device, partnum);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  volatile VALUE rv = rb_str_new2 (r);
  free (r);
  return rv;
}

/*
 * call-seq:
 *   g.part_get_name(device, partnum) -> string
 *
 * get partition name
 *
 * This gets the partition name on partition numbered
 * "partnum" on device "device". Note that partitions are
 * numbered from 1.
 * 
 * The partition name can only be read on certain types of
 * partition table. This works on "gpt" but not on "mbr"
 * partitions.
 *
 *
 * [Since] Added in version 1.25.33.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_part_get_name}[http://libguestfs.org/guestfs.3.html#guestfs_part_get_name].
 */
VALUE
guestfs_int_ruby_part_get_name (VALUE gv, VALUE devicev, VALUE partnumv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "part_get_name");

  const char *device = StringValueCStr (devicev);
  int partnum = NUM2INT (partnumv);

  char *r;

  r = guestfs_part_get_name (g, device, partnum);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  volatile VALUE rv = rb_str_new2 (r);
  free (r);
  return rv;
}

/*
 * call-seq:
 *   g.part_init(device, parttype) -> nil
 *
 * create an empty partition table
 *
 * This creates an empty partition table on "device" of one
 * of the partition types listed below. Usually "parttype"
 * should be either "msdos" or "gpt" (for large disks).
 * 
 * Initially there are no partitions. Following this, you
 * should call "g.part_add" for each partition required.
 * 
 * Possible values for "parttype" are:
 * 
 * efi
 * gpt Intel EFI / GPT partition table.
 * 
 * This is recommended for >= 2 TB partitions that will
 * be accessed from Linux and Intel-based Mac OS X. It
 * also has limited backwards compatibility with the
 * "mbr" format.
 * 
 * mbr
 * msdos
 * The standard PC "Master Boot Record" (MBR) format
 * used by MS-DOS and Windows. This partition type will
 * only work for device sizes up to 2 TB. For large
 * disks we recommend using "gpt".
 * 
 * Other partition table types that may work but are not
 * supported include:
 * 
 * aix AIX disk labels.
 * 
 * amiga
 * rdb Amiga "Rigid Disk Block" format.
 * 
 * bsd BSD disk labels.
 * 
 * dasd
 * DASD, used on IBM mainframes.
 * 
 * dvh MIPS/SGI volumes.
 * 
 * mac Old Mac partition format. Modern Macs use "gpt".
 * 
 * pc98
 * NEC PC-98 format, common in Japan apparently.
 * 
 * sun Sun disk labels.
 *
 *
 * [Since] Added in version 1.0.78.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_part_init}[http://libguestfs.org/guestfs.3.html#guestfs_part_init].
 */
VALUE
guestfs_int_ruby_part_init (VALUE gv, VALUE devicev, VALUE parttypev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "part_init");

  const char *device = StringValueCStr (devicev);
  const char *parttype = StringValueCStr (parttypev);

  int r;

  r = guestfs_part_init (g, device, parttype);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.part_to_partnum(partition) -> fixnum
 *
 * convert partition name to partition number
 *
 * This function takes a partition name (eg. "/dev/sdb1")
 * and returns the partition number (eg. 1).
 * 
 * The named partition must exist, for example as a string
 * returned from "g.list_partitions".
 * 
 * See also "g.part_to_dev".
 *
 *
 * [Since] Added in version 1.13.25.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_part_to_partnum}[http://libguestfs.org/guestfs.3.html#guestfs_part_to_partnum].
 */
VALUE
guestfs_int_ruby_part_to_partnum (VALUE gv, VALUE partitionv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "part_to_partnum");

  const char *partition = StringValueCStr (partitionv);

  int r;

  r = guestfs_part_to_partnum (g, partition);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return INT2NUM (r);
}

/*
 * call-seq:
 *   g.pvuuid(device) -> string
 *
 * get the UUID of a physical volume
 *
 * This command returns the UUID of the LVM PV "device".
 *
 *
 * [Since] Added in version 1.0.87.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_pvuuid}[http://libguestfs.org/guestfs.3.html#guestfs_pvuuid].
 */
VALUE
guestfs_int_ruby_pvuuid (VALUE gv, VALUE devicev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "pvuuid");

  const char *device = StringValueCStr (devicev);

  char *r;

  r = guestfs_pvuuid (g, device);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  volatile VALUE rv = rb_str_new2 (r);
  free (r);
  return rv;
}

/*
 * call-seq:
 *   g.readlinklist(path, names) -> list
 *
 * readlink on multiple files
 *
 * This call allows you to do a "readlink" operation on
 * multiple files, where all files are in the directory
 * "path". "names" is the list of files from this
 * directory.
 * 
 * On return you get a list of strings, with a one-to-one
 * correspondence to the "names" list. Each string is the
 * value of the symbolic link.
 * 
 * If the readlink(2) operation fails on any name, then the
 * corresponding result string is the empty string "".
 * However the whole operation is completed even if there
 * were readlink(2) errors, and so you can call this
 * function with names where you don't know if they are
 * symbolic links already (albeit slightly less efficient).
 * 
 * This call is intended for programs that want to
 * efficiently list a directory contents without making
 * many round-trips.
 *
 *
 * [Since] Added in version 1.0.77.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_readlinklist}[http://libguestfs.org/guestfs.3.html#guestfs_readlinklist].
 */
VALUE
guestfs_int_ruby_readlinklist (VALUE gv, VALUE pathv, VALUE namesv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "readlinklist");

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

  char **r;

  r = guestfs_readlinklist (g, path, names);
  free (names);
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
 *   g.rmmountpoint(exemptpath) -> nil
 *
 * remove a mountpoint
 *
 * This calls removes a mountpoint that was previously
 * created with "g.mkmountpoint". See "g.mkmountpoint" for
 * full details.
 *
 *
 * [Since] Added in version 1.0.62.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_rmmountpoint}[http://libguestfs.org/guestfs.3.html#guestfs_rmmountpoint].
 */
VALUE
guestfs_int_ruby_rmmountpoint (VALUE gv, VALUE exemptpathv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "rmmountpoint");

  const char *exemptpath = StringValueCStr (exemptpathv);

  int r;

  r = guestfs_rmmountpoint (g, exemptpath);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.scrub_device(device) -> nil
 *
 * scrub (securely wipe) a device
 *
 * This command writes patterns over "device" to make data
 * retrieval more difficult.
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
 *         {guestfs_scrub_device}[http://libguestfs.org/guestfs.3.html#guestfs_scrub_device].
 */
VALUE
guestfs_int_ruby_scrub_device (VALUE gv, VALUE devicev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "scrub_device");

  const char *device = StringValueCStr (devicev);

  int r;

  r = guestfs_scrub_device (g, device);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.set_cachedir(cachedir) -> nil
 *
 * set the appliance cache directory
 *
 * Set the directory used by the handle to store the
 * appliance cache, when using a supermin appliance. The
 * appliance is cached and shared between all handles which
 * have the same effective user ID.
 * 
 * The environment variables "LIBGUESTFS_CACHEDIR" and
 * "TMPDIR" control the default value: If
 * "LIBGUESTFS_CACHEDIR" is set, then that is the default.
 * Else if "TMPDIR" is set, then that is the default. Else
 * /var/tmp is the default.
 *
 *
 * [Since] Added in version 1.19.58.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_set_cachedir}[http://libguestfs.org/guestfs.3.html#guestfs_set_cachedir].
 */
VALUE
guestfs_int_ruby_set_cachedir (VALUE gv, VALUE cachedirv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "set_cachedir");

  const char *cachedir = !NIL_P (cachedirv) ? StringValueCStr (cachedirv) : NULL;

  int r;

  r = guestfs_set_cachedir (g, cachedir);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.set_e2attrs(file, attrs, {optargs...}) -> nil
 *
 * set ext2 file attributes of a file
 *
 * This sets or clears the file attributes "attrs"
 * associated with the inode file.
 * 
 * "attrs" is a string of characters representing file
 * attributes. See "g.get_e2attrs" for a list of possible
 * attributes. Not all attributes can be changed.
 * 
 * If optional boolean "clear" is not present or false,
 * then the "attrs" listed are set in the inode.
 * 
 * If "clear" is true, then the "attrs" listed are cleared
 * in the inode.
 * 
 * In both cases, other attributes not present in the
 * "attrs" string are left unchanged.
 * 
 * These attributes are only present when the file is
 * located on an ext2/3/4 filesystem. Using this call on
 * other filesystem types will result in an error.
 * 
 * Optional arguments are supplied in the final hash
 * parameter, which is a hash of the argument name to its
 * value. Pass an empty {} for no optional arguments.
 *
 *
 * [Since] Added in version 1.17.31.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_set_e2attrs}[http://libguestfs.org/guestfs.3.html#guestfs_set_e2attrs].
 */
VALUE
guestfs_int_ruby_set_e2attrs (int argc, VALUE *argv, VALUE gv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "set_e2attrs");

  if (argc < 2 || argc > 3)
    rb_raise (rb_eArgError, "expecting 2 or 3 arguments");

  volatile VALUE filev = argv[0];
  volatile VALUE attrsv = argv[1];
  volatile VALUE optargsv = argc > 2 ? argv[2] : rb_hash_new ();

  const char *file = StringValueCStr (filev);
  const char *attrs = StringValueCStr (attrsv);

  Check_Type (optargsv, T_HASH);
  struct guestfs_set_e2attrs_argv optargs_s = { .bitmask = 0 };
  struct guestfs_set_e2attrs_argv *optargs = &optargs_s;
  volatile VALUE v;
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("clear")));
  if (v != Qnil) {
    optargs_s.clear = RTEST (v);
    optargs_s.bitmask |= GUESTFS_SET_E2ATTRS_CLEAR_BITMASK;
  }

  int r;

  r = guestfs_set_e2attrs_argv (g, file, attrs, optargs);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.set_e2label(device, label) -> nil
 *
 * set the ext2/3/4 filesystem label
 *
 * This sets the ext2/3/4 filesystem label of the
 * filesystem on "device" to "label". Filesystem labels are
 * limited to 16 characters.
 * 
 * You can use either "g.tune2fs_l" or "g.get_e2label" to
 * return the existing label on a filesystem.
 *
 *
 * [Since] Added in version 1.0.15.
 *
 * [Deprecated] In new code, use rdoc-ref:set_label instead.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_set_e2label}[http://libguestfs.org/guestfs.3.html#guestfs_set_e2label].
 */
VALUE
guestfs_int_ruby_set_e2label (VALUE gv, VALUE devicev, VALUE labelv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "set_e2label");

  const char *device = StringValueCStr (devicev);
  const char *label = StringValueCStr (labelv);

  int r;

  r = guestfs_set_e2label (g, device, label);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.sh_lines(command) -> list
 *
 * run a command via the shell returning lines
 *
 * This is the same as "g.sh", but splits the result into a
 * list of lines.
 * 
 * See also: "g.command_lines"
 *
 *
 * [Since] Added in version 1.0.50.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_sh_lines}[http://libguestfs.org/guestfs.3.html#guestfs_sh_lines].
 */
VALUE
guestfs_int_ruby_sh_lines (VALUE gv, VALUE commandv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "sh_lines");

  const char *command = StringValueCStr (commandv);

  char **r;

  r = guestfs_sh_lines (g, command);
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
 *   g.shutdown() -> nil
 *
 * shutdown the hypervisor
 *
 * This is the opposite of "g.launch". It performs an
 * orderly shutdown of the backend process(es). If the
 * autosync flag is set (which is the default) then the
 * disk image is synchronized.
 * 
 * If the subprocess exits with an error then this function
 * will return an error, which should *not* be ignored (it
 * may indicate that the disk image could not be written
 * out properly).
 * 
 * It is safe to call this multiple times. Extra calls are
 * ignored.
 * 
 * This call does *not* close or free up the handle. You
 * still need to call "g.close" afterwards.
 * 
 * "g.close" will call this if you don't do it explicitly,
 * but note that any errors are ignored in that case.
 *
 *
 * [Since] Added in version 1.19.16.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_shutdown}[http://libguestfs.org/guestfs.3.html#guestfs_shutdown].
 */
VALUE
guestfs_int_ruby_shutdown (VALUE gv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "shutdown");


  int r;

  r = guestfs_shutdown (g);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.swapon_file(file) -> nil
 *
 * enable swap on file
 *
 * This command enables swap to a file. See
 * "g.swapon_device" for other notes.
 *
 *
 * [Since] Added in version 1.0.66.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_swapon_file}[http://libguestfs.org/guestfs.3.html#guestfs_swapon_file].
 */
VALUE
guestfs_int_ruby_swapon_file (VALUE gv, VALUE filev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "swapon_file");

  const char *file = StringValueCStr (filev);

  int r;

  r = guestfs_swapon_file (g, file);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.tgz_out(directory, tarball) -> nil
 *
 * pack directory into compressed tarball
 *
 * This command packs the contents of directory and
 * downloads it to local file "tarball".
 *
 *
 * [Since] Added in version 1.0.3.
 *
 * [Deprecated] In new code, use rdoc-ref:tar_out instead.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_tgz_out}[http://libguestfs.org/guestfs.3.html#guestfs_tgz_out].
 */
VALUE
guestfs_int_ruby_tgz_out (VALUE gv, VALUE directoryv, VALUE tarballv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "tgz_out");

  const char *directory = StringValueCStr (directoryv);
  const char *tarball = StringValueCStr (tarballv);

  int r;

  r = guestfs_tgz_out (g, directory, tarball);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.umask(mask) -> fixnum
 *
 * set file mode creation mask (umask)
 *
 * This function sets the mask used for creating new files
 * and device nodes to "mask & 0777".
 * 
 * Typical umask values would be 022 which creates new
 * files with permissions like "-rw-r--r--" or
 * "-rwxr-xr-x", and 002 which creates new files with
 * permissions like "-rw-rw-r--" or "-rwxrwxr-x".
 * 
 * The default umask is 022. This is important because it
 * means that directories and device nodes will be created
 * with 0644 or 0755 mode even if you specify 0777.
 * 
 * See also "g.get_umask", umask(2), "g.mknod", "g.mkdir".
 * 
 * This call returns the previous umask.
 *
 *
 * [Since] Added in version 1.0.55.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_umask}[http://libguestfs.org/guestfs.3.html#guestfs_umask].
 */
VALUE
guestfs_int_ruby_umask (VALUE gv, VALUE maskv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "umask");

  int mask = NUM2INT (maskv);

  int r;

  r = guestfs_umask (g, mask);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return INT2NUM (r);
}

/*
 * call-seq:
 *   g.wipefs(device) -> nil
 *
 * wipe a filesystem signature from a device
 *
 * This command erases filesystem or RAID signatures from
 * the specified "device" to make the filesystem invisible
 * to libblkid.
 * 
 * This does not erase the filesystem itself nor any other
 * data from the "device".
 * 
 * Compare with "g.zero" which zeroes the first few blocks
 * of a device.
 *
 *
 * [Since] Added in version 1.17.6.
 *
 * [Feature] This function depends on the feature +wipefs+.  See also {#feature_available}[rdoc-ref:feature_available].
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_wipefs}[http://libguestfs.org/guestfs.3.html#guestfs_wipefs].
 */
VALUE
guestfs_int_ruby_wipefs (VALUE gv, VALUE devicev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "wipefs");

  const char *device = StringValueCStr (devicev);

  int r;

  r = guestfs_wipefs (g, device);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

