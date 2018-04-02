/* libguestfs generated file
 * WARNING: THIS FILE IS GENERATED FROM THE FOLLOWING FILES:
 *          generator/ruby.ml
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
#include <stdint.h>
#include <string.h>
#include <errno.h>
#include <assert.h>

#include "actions.h"

/*
 * call-seq:
 *   g.add_drive(filename, {optargs...}) -> nil
 *
 * add an image to examine or modify
 *
 * This function adds a disk image called filename to the
 * handle. filename may be a regular host file or a host
 * device.
 * 
 * When this function is called before "g.launch" (the
 * usual case) then the first time you call this function,
 * the disk appears in the API as /dev/sda, the second time
 * as /dev/sdb, and so on.
 * 
 * In libguestfs ≥ 1.20 you can also call this function
 * after launch (with some restrictions). This is called
 * "hotplugging". When hotplugging, you must specify a
 * "label" so that the new disk gets a predictable name.
 * For more information see "HOTPLUGGING" in guestfs(3).
 * 
 * You don't necessarily need to be root when using
 * libguestfs. However you obviously do need sufficient
 * permissions to access the filename for whatever
 * operations you want to perform (ie. read access if you
 * just want to read the image or write access if you want
 * to modify the image).
 * 
 * This call checks that filename exists.
 * 
 * filename may be the special string "/dev/null". See
 * "NULL DISKS" in guestfs(3).
 * 
 * The optional arguments are:
 * 
 * "readonly"
 * If true then the image is treated as read-only.
 * Writes are still allowed, but they are stored in a
 * temporary snapshot overlay which is discarded at the
 * end. The disk that you add is not modified.
 * 
 * "format"
 * This forces the image format. If you omit this (or
 * use "g.add_drive" or "g.add_drive_ro") then the
 * format is automatically detected. Possible formats
 * include "raw" and "qcow2".
 * 
 * Automatic detection of the format opens you up to a
 * potential security hole when dealing with untrusted
 * raw-format images. See CVE-2010-3851 and
 * RHBZ#642934. Specifying the format closes this
 * security hole.
 * 
 * "iface"
 * This rarely-used option lets you emulate the
 * behaviour of the deprecated "g.add_drive_with_if"
 * call (q.v.)
 * 
 * "name"
 * The name the drive had in the original guest, e.g.
 * /dev/sdb. This is used as a hint to the guest
 * inspection process if it is available.
 * 
 * "label"
 * Give the disk a label. The label should be a unique,
 * short string using *only* ASCII characters
 * "[a-zA-Z]". As well as its usual name in the API
 * (such as /dev/sda), the drive will also be named
 * /dev/disk/guestfs/ *label*.
 * 
 * See "DISK LABELS" in guestfs(3).
 * 
 * "protocol"
 * The optional protocol argument can be used to select
 * an alternate source protocol.
 * 
 * See also: "REMOTE STORAGE" in guestfs(3).
 * 
 * "protocol = "file""
 * filename is interpreted as a local file or
 * device. This is the default if the optional
 * protocol parameter is omitted.
 * 
 * "protocol = "ftp"|"ftps"|"http"|"https"|"tftp""
 * Connect to a remote FTP, HTTP or TFTP server.
 * The "server" parameter must also be supplied -
 * see below.
 * 
 * See also: "FTP, HTTP AND TFTP" in guestfs(3)
 * 
 * "protocol = "gluster""
 * Connect to the GlusterFS server. The "server"
 * parameter must also be supplied - see below.
 * 
 * See also: "GLUSTER" in guestfs(3)
 * 
 * "protocol = "iscsi""
 * Connect to the iSCSI server. The "server"
 * parameter must also be supplied - see below. The
 * "username" parameter may be supplied. See below.
 * The "secret" parameter may be supplied. See
 * below.
 * 
 * See also: "ISCSI" in guestfs(3).
 * 
 * "protocol = "nbd""
 * Connect to the Network Block Device server. The
 * "server" parameter must also be supplied - see
 * below.
 * 
 * See also: "NETWORK BLOCK DEVICE" in guestfs(3).
 * 
 * "protocol = "rbd""
 * Connect to the Ceph (librbd/RBD) server. The
 * "server" parameter must also be supplied - see
 * below. The "username" parameter may be supplied.
 * See below. The "secret" parameter may be
 * supplied. See below.
 * 
 * See also: "CEPH" in guestfs(3).
 * 
 * "protocol = "sheepdog""
 * Connect to the Sheepdog server. The "server"
 * parameter may also be supplied - see below.
 * 
 * See also: "SHEEPDOG" in guestfs(3).
 * 
 * "protocol = "ssh""
 * Connect to the Secure Shell (ssh) server.
 * 
 * The "server" parameter must be supplied. The
 * "username" parameter may be supplied. See below.
 * 
 * See also: "SSH" in guestfs(3).
 * 
 * "server"
 * For protocols which require access to a remote
 * server, this is a list of server(s).
 * 
 * Protocol       Number of servers required
 * --------       --------------------------
 * file           List must be empty or param not used at all
 * ftp|ftps|http|https|tftp  Exactly one
 * gluster        Exactly one
 * iscsi          Exactly one
 * nbd            Exactly one
 * rbd            Zero or more
 * sheepdog       Zero or more
 * ssh            Exactly one
 * 
 * Each list element is a string specifying a server.
 * The string must be in one of the following formats:
 * 
 * hostname
 * hostname:port
 * tcp:hostname
 * tcp:hostname:port
 * unix:/path/to/socket
 * 
 * If the port number is omitted, then the standard
 * port number for the protocol is used (see
 * /etc/services).
 * 
 * "username"
 * For the "ftp", "ftps", "http", "https", "iscsi",
 * "rbd", "ssh" and "tftp" protocols, this specifies
 * the remote username.
 * 
 * If not given, then the local username is used for
 * "ssh", and no authentication is attempted for ceph.
 * But note this sometimes may give unexpected results,
 * for example if using the libvirt backend and if the
 * libvirt backend is configured to start the qemu
 * appliance as a special user such as "qemu.qemu". If
 * in doubt, specify the remote username you want.
 * 
 * "secret"
 * For the "rbd" protocol only, this specifies the
 * ‘secret’ to use when connecting to the remote
 * device. It must be base64 encoded.
 * 
 * If not given, then a secret matching the given
 * username will be looked up in the default keychain
 * locations, or if no username is given, then no
 * authentication will be used.
 * 
 * "cachemode"
 * Choose whether or not libguestfs will obey sync
 * operations (safe but slow) or not (unsafe but fast).
 * The possible values for this string are:
 * 
 * "cachemode = "writeback""
 * This is the default.
 * 
 * Write operations in the API do not return until
 * a write(2) call has completed in the host [but
 * note this does not imply that anything gets
 * written to disk].
 * 
 * Sync operations in the API, including implicit
 * syncs caused by filesystem journalling, will not
 * return until an fdatasync(2) call has completed
 * in the host, indicating that data has been
 * committed to disk.
 * 
 * "cachemode = "unsafe""
 * In this mode, there are no guarantees.
 * Libguestfs may cache anything and ignore sync
 * requests. This is suitable only for scratch or
 * temporary disks.
 * 
 * "discard"
 * Enable or disable discard (a.k.a. trim or unmap)
 * support on this drive. If enabled, operations such
 * as "g.fstrim" will be able to discard / make thin /
 * punch holes in the underlying host file or device.
 * 
 * Possible discard settings are:
 * 
 * "discard = "disable""
 * Disable discard support. This is the default.
 * 
 * "discard = "enable""
 * Enable discard support. Fail if discard is not
 * possible.
 * 
 * "discard = "besteffort""
 * Enable discard support if possible, but don't
 * fail if it is not supported.
 * 
 * Since not all backends and not all underlying
 * systems support discard, this is a good choice
 * if you want to use discard if possible, but
 * don't mind if it doesn't work.
 * 
 * "copyonread"
 * The boolean parameter "copyonread" enables
 * copy-on-read support. This only affects disk formats
 * which have backing files, and causes reads to be
 * stored in the overlay layer, speeding up multiple
 * reads of the same area of disk.
 * 
 * The default is false.
 * 
 * Optional arguments are supplied in the final hash
 * parameter, which is a hash of the argument name to its
 * value. Pass an empty {} for no optional arguments.
 *
 *
 * [Since] Added in version 0.3.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_add_drive}[http://libguestfs.org/guestfs.3.html#guestfs_add_drive].
 */
VALUE
guestfs_int_ruby_add_drive (int argc, VALUE *argv, VALUE gv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "add_drive");

  if (argc < 1 || argc > 2)
    rb_raise (rb_eArgError, "expecting 1 or 2 arguments");

  volatile VALUE filenamev = argv[0];
  volatile VALUE optargsv = argc > 1 ? argv[1] : rb_hash_new ();

  const char *filename = StringValueCStr (filenamev);

  Check_Type (optargsv, T_HASH);
  struct guestfs_add_drive_opts_argv optargs_s = { .bitmask = 0 };
  struct guestfs_add_drive_opts_argv *optargs = &optargs_s;
  volatile VALUE v;
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("readonly")));
  if (v != Qnil) {
    optargs_s.readonly = RTEST (v);
    optargs_s.bitmask |= GUESTFS_ADD_DRIVE_OPTS_READONLY_BITMASK;
  }
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("format")));
  if (v != Qnil) {
    optargs_s.format = StringValueCStr (v);
    optargs_s.bitmask |= GUESTFS_ADD_DRIVE_OPTS_FORMAT_BITMASK;
  }
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("iface")));
  if (v != Qnil) {
    optargs_s.iface = StringValueCStr (v);
    optargs_s.bitmask |= GUESTFS_ADD_DRIVE_OPTS_IFACE_BITMASK;
  }
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("name")));
  if (v != Qnil) {
    optargs_s.name = StringValueCStr (v);
    optargs_s.bitmask |= GUESTFS_ADD_DRIVE_OPTS_NAME_BITMASK;
  }
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("label")));
  if (v != Qnil) {
    optargs_s.label = StringValueCStr (v);
    optargs_s.bitmask |= GUESTFS_ADD_DRIVE_OPTS_LABEL_BITMASK;
  }
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("protocol")));
  if (v != Qnil) {
    optargs_s.protocol = StringValueCStr (v);
    optargs_s.bitmask |= GUESTFS_ADD_DRIVE_OPTS_PROTOCOL_BITMASK;
  }
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("server")));
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
    optargs_s.server = r;
  }
    optargs_s.bitmask |= GUESTFS_ADD_DRIVE_OPTS_SERVER_BITMASK;
  }
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("username")));
  if (v != Qnil) {
    optargs_s.username = StringValueCStr (v);
    optargs_s.bitmask |= GUESTFS_ADD_DRIVE_OPTS_USERNAME_BITMASK;
  }
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("secret")));
  if (v != Qnil) {
    optargs_s.secret = StringValueCStr (v);
    optargs_s.bitmask |= GUESTFS_ADD_DRIVE_OPTS_SECRET_BITMASK;
  }
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("cachemode")));
  if (v != Qnil) {
    optargs_s.cachemode = StringValueCStr (v);
    optargs_s.bitmask |= GUESTFS_ADD_DRIVE_OPTS_CACHEMODE_BITMASK;
  }
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("discard")));
  if (v != Qnil) {
    optargs_s.discard = StringValueCStr (v);
    optargs_s.bitmask |= GUESTFS_ADD_DRIVE_OPTS_DISCARD_BITMASK;
  }
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("copyonread")));
  if (v != Qnil) {
    optargs_s.copyonread = RTEST (v);
    optargs_s.bitmask |= GUESTFS_ADD_DRIVE_OPTS_COPYONREAD_BITMASK;
  }

  int r;

  r = guestfs_add_drive_opts_argv (g, filename, optargs);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.add_drive_scratch(size, {optargs...}) -> nil
 *
 * add a temporary scratch drive
 *
 * This command adds a temporary scratch drive to the
 * handle. The "size" parameter is the virtual size (in
 * bytes). The scratch drive is blank initially (all reads
 * return zeroes until you start writing to it). The drive
 * is deleted when the handle is closed.
 * 
 * The optional arguments "name" and "label" are passed
 * through to "g.add_drive".
 * 
 * Optional arguments are supplied in the final hash
 * parameter, which is a hash of the argument name to its
 * value. Pass an empty {} for no optional arguments.
 *
 *
 * [Since] Added in version 1.23.10.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_add_drive_scratch}[http://libguestfs.org/guestfs.3.html#guestfs_add_drive_scratch].
 */
VALUE
guestfs_int_ruby_add_drive_scratch (int argc, VALUE *argv, VALUE gv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "add_drive_scratch");

  if (argc < 1 || argc > 2)
    rb_raise (rb_eArgError, "expecting 1 or 2 arguments");

  volatile VALUE sizev = argv[0];
  volatile VALUE optargsv = argc > 1 ? argv[1] : rb_hash_new ();

  long long size = NUM2LL (sizev);

  Check_Type (optargsv, T_HASH);
  struct guestfs_add_drive_scratch_argv optargs_s = { .bitmask = 0 };
  struct guestfs_add_drive_scratch_argv *optargs = &optargs_s;
  volatile VALUE v;
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("name")));
  if (v != Qnil) {
    optargs_s.name = StringValueCStr (v);
    optargs_s.bitmask |= GUESTFS_ADD_DRIVE_SCRATCH_NAME_BITMASK;
  }
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("label")));
  if (v != Qnil) {
    optargs_s.label = StringValueCStr (v);
    optargs_s.bitmask |= GUESTFS_ADD_DRIVE_SCRATCH_LABEL_BITMASK;
  }

  int r;

  r = guestfs_add_drive_scratch_argv (g, size, optargs);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.aug_label(augpath) -> string
 *
 * return the label from an Augeas path expression
 *
 * The label (name of the last element) of the Augeas path
 * expression "augpath" is returned. "augpath" must match
 * exactly one node, else this function returns an error.
 *
 *
 * [Since] Added in version 1.23.14.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_aug_label}[http://libguestfs.org/guestfs.3.html#guestfs_aug_label].
 */
VALUE
guestfs_int_ruby_aug_label (VALUE gv, VALUE augpathv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "aug_label");

  const char *augpath = StringValueCStr (augpathv);

  char *r;

  r = guestfs_aug_label (g, augpath);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  volatile VALUE rv = rb_str_new2 (r);
  free (r);
  return rv;
}

/*
 * call-seq:
 *   g.blkdiscardzeroes(device) -> [True|False]
 *
 * return true if discarded blocks are read as zeroes
 *
 * This call returns true if blocks on "device" that have
 * been discarded by a call to "g.blkdiscard" are returned
 * as blocks of zero bytes when read the next time.
 * 
 * If it returns false, then it may be that discarded
 * blocks are read as stale or random data.
 *
 *
 * [Since] Added in version 1.25.44.
 *
 * [Feature] This function depends on the feature +blkdiscardzeroes+.  See also {#feature_available}[rdoc-ref:feature_available].
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_blkdiscardzeroes}[http://libguestfs.org/guestfs.3.html#guestfs_blkdiscardzeroes].
 */
VALUE
guestfs_int_ruby_blkdiscardzeroes (VALUE gv, VALUE devicev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "blkdiscardzeroes");

  const char *device = StringValueCStr (devicev);

  int r;

  r = guestfs_blkdiscardzeroes (g, device);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return INT2NUM (r);
}

/*
 * call-seq:
 *   g.blockdev_getsize64(device) -> fixnum
 *
 * get total size of device in bytes
 *
 * This returns the size of the device in bytes.
 * 
 * See also "g.blockdev_getsz".
 * 
 * This uses the blockdev(8) command.
 *
 *
 * [Since] Added in version 1.9.3.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_blockdev_getsize64}[http://libguestfs.org/guestfs.3.html#guestfs_blockdev_getsize64].
 */
VALUE
guestfs_int_ruby_blockdev_getsize64 (VALUE gv, VALUE devicev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "blockdev_getsize64");

  const char *device = StringValueCStr (devicev);

  int64_t r;

  r = guestfs_blockdev_getsize64 (g, device);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return ULL2NUM (r);
}

/*
 * call-seq:
 *   g.blockdev_getss(device) -> fixnum
 *
 * get sectorsize of block device
 *
 * This returns the size of sectors on a block device.
 * Usually 512, but can be larger for modern devices.
 * 
 * (Note, this is not the size in sectors, use
 * "g.blockdev_getsz" for that).
 * 
 * This uses the blockdev(8) command.
 *
 *
 * [Since] Added in version 1.9.3.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_blockdev_getss}[http://libguestfs.org/guestfs.3.html#guestfs_blockdev_getss].
 */
VALUE
guestfs_int_ruby_blockdev_getss (VALUE gv, VALUE devicev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "blockdev_getss");

  const char *device = StringValueCStr (devicev);

  int r;

  r = guestfs_blockdev_getss (g, device);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return INT2NUM (r);
}

/*
 * call-seq:
 *   g.blockdev_rereadpt(device) -> nil
 *
 * reread partition table
 *
 * Reread the partition table on "device".
 * 
 * This uses the blockdev(8) command.
 *
 *
 * [Since] Added in version 1.9.3.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_blockdev_rereadpt}[http://libguestfs.org/guestfs.3.html#guestfs_blockdev_rereadpt].
 */
VALUE
guestfs_int_ruby_blockdev_rereadpt (VALUE gv, VALUE devicev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "blockdev_rereadpt");

  const char *device = StringValueCStr (devicev);

  int r;

  r = guestfs_blockdev_rereadpt (g, device);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.btrfs_balance_cancel(path) -> nil
 *
 * cancel a running or paused balance
 *
 * Cancel a running balance on a btrfs filesystem.
 *
 *
 * [Since] Added in version 1.29.22.
 *
 * [Feature] This function depends on the feature +btrfs+.  See also {#feature_available}[rdoc-ref:feature_available].
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_btrfs_balance_cancel}[http://libguestfs.org/guestfs.3.html#guestfs_btrfs_balance_cancel].
 */
VALUE
guestfs_int_ruby_btrfs_balance_cancel (VALUE gv, VALUE pathv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "btrfs_balance_cancel");

  const char *path = StringValueCStr (pathv);

  int r;

  r = guestfs_btrfs_balance_cancel (g, path);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.btrfs_qgroup_limit(subvolume, size) -> nil
 *
 * limit the size of a subvolume
 *
 * Limit the size of the subvolume with path "subvolume".
 *
 *
 * [Since] Added in version 1.29.17.
 *
 * [Feature] This function depends on the feature +btrfs+.  See also {#feature_available}[rdoc-ref:feature_available].
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_btrfs_qgroup_limit}[http://libguestfs.org/guestfs.3.html#guestfs_btrfs_qgroup_limit].
 */
VALUE
guestfs_int_ruby_btrfs_qgroup_limit (VALUE gv, VALUE subvolumev, VALUE sizev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "btrfs_qgroup_limit");

  const char *subvolume = StringValueCStr (subvolumev);
  long long size = NUM2LL (sizev);

  int r;

  r = guestfs_btrfs_qgroup_limit (g, subvolume, size);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.btrfs_quota_rescan(fs) -> nil
 *
 * trash all qgroup numbers and scan the metadata again with the current config
 *
 * Trash all qgroup numbers and scan the metadata again
 * with the current config.
 *
 *
 * [Since] Added in version 1.29.17.
 *
 * [Feature] This function depends on the feature +btrfs+.  See also {#feature_available}[rdoc-ref:feature_available].
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_btrfs_quota_rescan}[http://libguestfs.org/guestfs.3.html#guestfs_btrfs_quota_rescan].
 */
VALUE
guestfs_int_ruby_btrfs_quota_rescan (VALUE gv, VALUE fsv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "btrfs_quota_rescan");

  const char *fs = StringValueCStr (fsv);

  int r;

  r = guestfs_btrfs_quota_rescan (g, fs);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.btrfs_set_seeding(device, seeding) -> nil
 *
 * enable or disable the seeding feature of device
 *
 * Enable or disable the seeding feature of a device that
 * contains a btrfs filesystem.
 *
 *
 * [Since] Added in version 1.17.43.
 *
 * [Feature] This function depends on the feature +btrfs+.  See also {#feature_available}[rdoc-ref:feature_available].
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_btrfs_set_seeding}[http://libguestfs.org/guestfs.3.html#guestfs_btrfs_set_seeding].
 */
VALUE
guestfs_int_ruby_btrfs_set_seeding (VALUE gv, VALUE devicev, VALUE seedingv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "btrfs_set_seeding");

  const char *device = StringValueCStr (devicev);
  int seeding = RTEST (seedingv);

  int r;

  r = guestfs_btrfs_set_seeding (g, device, seeding);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.btrfs_subvolume_show(subvolume) -> hash
 *
 * return detailed information of the subvolume
 *
 * Return detailed information of the subvolume.
 *
 *
 * [Since] Added in version 1.29.17.
 *
 * [Feature] This function depends on the feature +btrfs+.  See also {#feature_available}[rdoc-ref:feature_available].
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_btrfs_subvolume_show}[http://libguestfs.org/guestfs.3.html#guestfs_btrfs_subvolume_show].
 */
VALUE
guestfs_int_ruby_btrfs_subvolume_show (VALUE gv, VALUE subvolumev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "btrfs_subvolume_show");

  const char *subvolume = StringValueCStr (subvolumev);

  char **r;

  r = guestfs_btrfs_subvolume_show (g, subvolume);
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
 *   g.chown(owner, group, path) -> nil
 *
 * change file owner and group
 *
 * Change the file owner to "owner" and group to "group".
 * 
 * Only numeric uid and gid are supported. If you want to
 * use names, you will need to locate and parse the
 * password file yourself (Augeas support makes this
 * relatively easy).
 *
 *
 * [Since] Added in version 0.8.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_chown}[http://libguestfs.org/guestfs.3.html#guestfs_chown].
 */
VALUE
guestfs_int_ruby_chown (VALUE gv, VALUE ownerv, VALUE groupv, VALUE pathv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "chown");

  int owner = NUM2INT (ownerv);
  int group = NUM2INT (groupv);
  const char *path = StringValueCStr (pathv);

  int r;

  r = guestfs_chown (g, owner, group, path);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.command(arguments) -> string
 *
 * run a command from the guest filesystem
 *
 * This call runs a command from the guest filesystem. The
 * filesystem must be mounted, and must contain a
 * compatible operating system (ie. something Linux, with
 * the same or compatible processor architecture).
 * 
 * The single parameter is an argv-style list of arguments.
 * The first element is the name of the program to run.
 * Subsequent elements are parameters. The list must be
 * non-empty (ie. must contain a program name). Note that
 * the command runs directly, and is *not* invoked via the
 * shell (see "g.sh").
 * 
 * The return value is anything printed to *stdout* by the
 * command.
 * 
 * If the command returns a non-zero exit status, then this
 * function returns an error message. The error message
 * string is the content of *stderr* from the command.
 * 
 * The $PATH environment variable will contain at least
 * /usr/bin and /bin. If you require a program from another
 * location, you should provide the full path in the first
 * parameter.
 * 
 * Shared libraries and data files required by the program
 * must be available on filesystems which are mounted in
 * the correct places. It is the caller’s responsibility to
 * ensure all filesystems that are needed are mounted at
 * the right locations.
 * 
 * Because of the message protocol, there is a transfer
 * limit of somewhere between 2MB and 4MB. See "PROTOCOL
 * LIMITS" in guestfs(3).
 *
 *
 * [Since] Added in version 1.9.1.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_command}[http://libguestfs.org/guestfs.3.html#guestfs_command].
 */
VALUE
guestfs_int_ruby_command (VALUE gv, VALUE argumentsv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "command");

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

  char *r;

  r = guestfs_command (g, arguments);
  free (arguments);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  volatile VALUE rv = rb_str_new2 (r);
  free (r);
  return rv;
}

/*
 * call-seq:
 *   g.copy_device_to_file(src, dest, {optargs...}) -> nil
 *
 * copy from source device to destination file
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
 *         {guestfs_copy_device_to_file}[http://libguestfs.org/guestfs.3.html#guestfs_copy_device_to_file].
 */
VALUE
guestfs_int_ruby_copy_device_to_file (int argc, VALUE *argv, VALUE gv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "copy_device_to_file");

  if (argc < 2 || argc > 3)
    rb_raise (rb_eArgError, "expecting 2 or 3 arguments");

  volatile VALUE srcv = argv[0];
  volatile VALUE destv = argv[1];
  volatile VALUE optargsv = argc > 2 ? argv[2] : rb_hash_new ();

  const char *src = StringValueCStr (srcv);
  const char *dest = StringValueCStr (destv);

  Check_Type (optargsv, T_HASH);
  struct guestfs_copy_device_to_file_argv optargs_s = { .bitmask = 0 };
  struct guestfs_copy_device_to_file_argv *optargs = &optargs_s;
  volatile VALUE v;
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("srcoffset")));
  if (v != Qnil) {
    optargs_s.srcoffset = NUM2LL (v);
    optargs_s.bitmask |= GUESTFS_COPY_DEVICE_TO_FILE_SRCOFFSET_BITMASK;
  }
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("destoffset")));
  if (v != Qnil) {
    optargs_s.destoffset = NUM2LL (v);
    optargs_s.bitmask |= GUESTFS_COPY_DEVICE_TO_FILE_DESTOFFSET_BITMASK;
  }
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("size")));
  if (v != Qnil) {
    optargs_s.size = NUM2LL (v);
    optargs_s.bitmask |= GUESTFS_COPY_DEVICE_TO_FILE_SIZE_BITMASK;
  }
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("sparse")));
  if (v != Qnil) {
    optargs_s.sparse = RTEST (v);
    optargs_s.bitmask |= GUESTFS_COPY_DEVICE_TO_FILE_SPARSE_BITMASK;
  }
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("append")));
  if (v != Qnil) {
    optargs_s.append = RTEST (v);
    optargs_s.bitmask |= GUESTFS_COPY_DEVICE_TO_FILE_APPEND_BITMASK;
  }

  int r;

  r = guestfs_copy_device_to_file_argv (g, src, dest, optargs);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.cp_r(src, dest) -> nil
 *
 * copy a file or directory recursively
 *
 * This copies a file or directory from "src" to "dest"
 * recursively using the "cp -rP" command.
 * 
 * Most users should use "g.cp_a" instead. This command is
 * useful when you don't want to preserve permissions,
 * because the target filesystem does not support it
 * (primarily when writing to DOS FAT filesystems).
 *
 *
 * [Since] Added in version 1.21.38.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_cp_r}[http://libguestfs.org/guestfs.3.html#guestfs_cp_r].
 */
VALUE
guestfs_int_ruby_cp_r (VALUE gv, VALUE srcv, VALUE destv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "cp_r");

  const char *src = StringValueCStr (srcv);
  const char *dest = StringValueCStr (destv);

  int r;

  r = guestfs_cp_r (g, src, dest);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.debug
 *
 * :nodoc:
 */
VALUE
guestfs_int_ruby_debug (VALUE gv, VALUE subcmdv, VALUE extraargsv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "debug");

  const char *subcmd = StringValueCStr (subcmdv);
  char **extraargs;
  Check_Type (extraargsv, T_ARRAY);
  {
    size_t i, len;
    len = RARRAY_LEN (extraargsv);
    extraargs = ALLOC_N (char *, len+1);
    for (i = 0; i < len; ++i) {
      volatile VALUE v = rb_ary_entry (extraargsv, i);
      extraargs[i] = StringValueCStr (v);
    }
    extraargs[len] = NULL;
  }

  char *r;

  r = guestfs_debug (g, subcmd, extraargs);
  free (extraargs);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  volatile VALUE rv = rb_str_new2 (r);
  free (r);
  return rv;
}

/*
 * call-seq:
 *   g.drop_caches(whattodrop) -> nil
 *
 * drop kernel page cache, dentries and inodes
 *
 * This instructs the guest kernel to drop its page cache,
 * and/or dentries and inode caches. The parameter
 * "whattodrop" tells the kernel what precisely to drop,
 * see <http://linux-mm.org/Drop_Caches>
 * 
 * Setting "whattodrop" to 3 should drop everything.
 * 
 * This automatically calls sync(2) before the operation,
 * so that the maximum guest memory is freed.
 *
 *
 * [Since] Added in version 1.0.18.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_drop_caches}[http://libguestfs.org/guestfs.3.html#guestfs_drop_caches].
 */
VALUE
guestfs_int_ruby_drop_caches (VALUE gv, VALUE whattodropv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "drop_caches");

  int whattodrop = NUM2INT (whattodropv);

  int r;

  r = guestfs_drop_caches (g, whattodrop);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.egrep(regex, path) -> list
 *
 * return lines matching a pattern
 *
 * This calls the external "egrep" program and returns the
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
 *         {guestfs_egrep}[http://libguestfs.org/guestfs.3.html#guestfs_egrep].
 */
VALUE
guestfs_int_ruby_egrep (VALUE gv, VALUE regexv, VALUE pathv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "egrep");

  const char *regex = StringValueCStr (regexv);
  const char *path = StringValueCStr (pathv);

  char **r;

  r = guestfs_egrep (g, regex, path);
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
 *   g.file_architecture(filename) -> string
 *
 * detect the architecture of a binary file
 *
 * This detects the architecture of the binary filename,
 * and returns it if known.
 * 
 * Currently defined architectures are:
 * 
 * "aarch64"
 * 64 bit ARM.
 * 
 * "arm"
 * 32 bit ARM.
 * 
 * "i386"
 * This string is returned for all 32 bit i386, i486,
 * i586, i686 binaries irrespective of the precise
 * processor requirements of the binary.
 * 
 * "ia64"
 * Intel Itanium.
 * 
 * "ppc"
 * 32 bit Power PC.
 * 
 * "ppc64"
 * 64 bit Power PC (big endian).
 * 
 * "ppc64le"
 * 64 bit Power PC (little endian).
 * 
 * "riscv32"
 * "riscv64"
 * "riscv128"
 * RISC-V 32-, 64- or 128-bit variants.
 * 
 * "s390"
 * 31 bit IBM S/390.
 * 
 * "s390x"
 * 64 bit IBM S/390.
 * 
 * "sparc"
 * 32 bit SPARC.
 * 
 * "sparc64"
 * 64 bit SPARC V9 and above.
 * 
 * "x86_64"
 * 64 bit x86-64.
 * 
 * Libguestfs may return other architecture strings in
 * future.
 * 
 * The function works on at least the following types of
 * files:
 * 
 * *   many types of Un*x and Linux binary
 * 
 * *   many types of Un*x and Linux shared library
 * 
 * *   Windows Win32 and Win64 binaries
 * 
 * *   Windows Win32 and Win64 DLLs
 * 
 * Win32 binaries and DLLs return "i386".
 * 
 * Win64 binaries and DLLs return "x86_64".
 * 
 * *   Linux kernel modules
 * 
 * *   Linux new-style initrd images
 * 
 * *   some non-x86 Linux vmlinuz kernels
 * 
 * What it can't do currently:
 * 
 * *   static libraries (libfoo.a)
 * 
 * *   Linux old-style initrd as compressed ext2 filesystem
 * (RHEL 3)
 * 
 * *   x86 Linux vmlinuz kernels
 * 
 * x86 vmlinuz images (bzImage format) consist of a mix
 * of 16-, 32- and compressed code, and are horribly
 * hard to unpack. If you want to find the architecture
 * of a kernel, use the architecture of the associated
 * initrd or kernel module(s) instead.
 *
 *
 * [Since] Added in version 1.5.3.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_file_architecture}[http://libguestfs.org/guestfs.3.html#guestfs_file_architecture].
 */
VALUE
guestfs_int_ruby_file_architecture (VALUE gv, VALUE filenamev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "file_architecture");

  const char *filename = StringValueCStr (filenamev);

  char *r;

  r = guestfs_file_architecture (g, filename);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  volatile VALUE rv = rb_str_new2 (r);
  free (r);
  return rv;
}

/*
 * call-seq:
 *   g.get_backend() -> string
 *
 * get the backend
 *
 * Return the current backend.
 * 
 * This handle property was previously called the "attach
 * method".
 * 
 * See "g.set_backend" and "BACKEND" in guestfs(3).
 *
 *
 * [Since] Added in version 1.21.26.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_get_backend}[http://libguestfs.org/guestfs.3.html#guestfs_get_backend].
 */
VALUE
guestfs_int_ruby_get_backend (VALUE gv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "get_backend");


  char *r;

  r = guestfs_get_backend (g);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  volatile VALUE rv = rb_str_new2 (r);
  free (r);
  return rv;
}

/*
 * call-seq:
 *   g.get_e2attrs(file) -> string
 *
 * get ext2 file attributes of a file
 *
 * This returns the file attributes associated with file.
 * 
 * The attributes are a set of bits associated with each
 * inode which affect the behaviour of the file. The
 * attributes are returned as a string of letters
 * (described below). The string may be empty, indicating
 * that no file attributes are set for this file.
 * 
 * These attributes are only present when the file is
 * located on an ext2/3/4 filesystem. Using this call on
 * other filesystem types will result in an error.
 * 
 * The characters (file attributes) in the returned string
 * are currently:
 * 
 * 'A' When the file is accessed, its atime is not
 * modified.
 * 
 * 'a' The file is append-only.
 * 
 * 'c' The file is compressed on-disk.
 * 
 * 'D' (Directories only.) Changes to this directory are
 * written synchronously to disk.
 * 
 * 'd' The file is not a candidate for backup (see
 * dump(8)).
 * 
 * 'E' The file has compression errors.
 * 
 * 'e' The file is using extents.
 * 
 * 'h' The file is storing its blocks in units of the
 * filesystem blocksize instead of sectors.
 * 
 * 'I' (Directories only.) The directory is using hashed
 * trees.
 * 
 * 'i' The file is immutable. It cannot be modified,
 * deleted or renamed. No link can be created to this
 * file.
 * 
 * 'j' The file is data-journaled.
 * 
 * 's' When the file is deleted, all its blocks will be
 * zeroed.
 * 
 * 'S' Changes to this file are written synchronously to
 * disk.
 * 
 * 'T' (Directories only.) This is a hint to the block
 * allocator that subdirectories contained in this
 * directory should be spread across blocks. If not
 * present, the block allocator will try to group
 * subdirectories together.
 * 
 * 't' For a file, this disables tail-merging. (Not used by
 * upstream implementations of ext2.)
 * 
 * 'u' When the file is deleted, its blocks will be saved,
 * allowing the file to be undeleted.
 * 
 * 'X' The raw contents of the compressed file may be
 * accessed.
 * 
 * 'Z' The compressed file is dirty.
 * 
 * More file attributes may be added to this list later.
 * Not all file attributes may be set for all kinds of
 * files. For detailed information, consult the chattr(1)
 * man page.
 * 
 * See also "g.set_e2attrs".
 * 
 * Don't confuse these attributes with extended attributes
 * (see "g.getxattr").
 *
 *
 * [Since] Added in version 1.17.31.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_get_e2attrs}[http://libguestfs.org/guestfs.3.html#guestfs_get_e2attrs].
 */
VALUE
guestfs_int_ruby_get_e2attrs (VALUE gv, VALUE filev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "get_e2attrs");

  const char *file = StringValueCStr (filev);

  char *r;

  r = guestfs_get_e2attrs (g, file);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  volatile VALUE rv = rb_str_new2 (r);
  free (r);
  return rv;
}

/*
 * call-seq:
 *   g.get_e2generation(file) -> fixnum
 *
 * get ext2 file generation of a file
 *
 * This returns the ext2 file generation of a file. The
 * generation (which used to be called the "version") is a
 * number associated with an inode. This is most commonly
 * used by NFS servers.
 * 
 * The generation is only present when the file is located
 * on an ext2/3/4 filesystem. Using this call on other
 * filesystem types will result in an error.
 * 
 * See "g.set_e2generation".
 *
 *
 * [Since] Added in version 1.17.31.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_get_e2generation}[http://libguestfs.org/guestfs.3.html#guestfs_get_e2generation].
 */
VALUE
guestfs_int_ruby_get_e2generation (VALUE gv, VALUE filev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "get_e2generation");

  const char *file = StringValueCStr (filev);

  int64_t r;

  r = guestfs_get_e2generation (g, file);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return ULL2NUM (r);
}

/*
 * call-seq:
 *   g.glob_expand(pattern, {optargs...}) -> list
 *
 * expand a wildcard path
 *
 * This command searches for all the pathnames matching
 * "pattern" according to the wildcard expansion rules used
 * by the shell.
 * 
 * If no paths match, then this returns an empty list
 * (note: not an error).
 * 
 * It is just a wrapper around the C glob(3) function with
 * flags "GLOB_MARK|GLOB_BRACE". See that manual page for
 * more details.
 * 
 * "directoryslash" controls whether use the "GLOB_MARK"
 * flag for glob(3), and it defaults to true. It can be
 * explicitly set as off to return no trailing slashes in
 * filenames of directories.
 * 
 * Notice that there is no equivalent command for expanding
 * a device name (eg. /dev/sd*). Use "g.list_devices",
 * "g.list_partitions" etc functions instead.
 * 
 * Optional arguments are supplied in the final hash
 * parameter, which is a hash of the argument name to its
 * value. Pass an empty {} for no optional arguments.
 *
 *
 * [Since] Added in version 1.0.50.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_glob_expand}[http://libguestfs.org/guestfs.3.html#guestfs_glob_expand].
 */
VALUE
guestfs_int_ruby_glob_expand (int argc, VALUE *argv, VALUE gv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "glob_expand");

  if (argc < 1 || argc > 2)
    rb_raise (rb_eArgError, "expecting 1 or 2 arguments");

  volatile VALUE patternv = argv[0];
  volatile VALUE optargsv = argc > 1 ? argv[1] : rb_hash_new ();

  const char *pattern = StringValueCStr (patternv);

  Check_Type (optargsv, T_HASH);
  struct guestfs_glob_expand_opts_argv optargs_s = { .bitmask = 0 };
  struct guestfs_glob_expand_opts_argv *optargs = &optargs_s;
  volatile VALUE v;
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("directoryslash")));
  if (v != Qnil) {
    optargs_s.directoryslash = RTEST (v);
    optargs_s.bitmask |= GUESTFS_GLOB_EXPAND_OPTS_DIRECTORYSLASH_BITMASK;
  }

  char **r;

  r = guestfs_glob_expand_opts_argv (g, pattern, optargs);
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
 *   g.grub_install(root, device) -> nil
 *
 * install GRUB 1
 *
 * This command installs GRUB 1 (the Grand Unified
 * Bootloader) on "device", with the root directory being
 * "root".
 * 
 * Notes:
 * 
 * *   There is currently no way in the API to install
 * grub2, which is used by most modern Linux guests. It
 * is possible to run the grub2 command from the guest,
 * although see the caveats in "RUNNING COMMANDS" in
 * guestfs(3).
 * 
 * *   This uses "grub-install" from the host.
 * Unfortunately grub is not always compatible with
 * itself, so this only works in rather narrow
 * circumstances. Careful testing with each guest
 * version is advisable.
 * 
 * *   If grub-install reports the error "No suitable drive
 * was found in the generated device map." it may be
 * that you need to create a /boot/grub/device.map file
 * first that contains the mapping between grub device
 * names and Linux device names. It is usually
 * sufficient to create a file containing:
 * 
 * (hd0) /dev/vda
 * 
 * replacing /dev/vda with the name of the installation
 * device.
 *
 *
 * [Since] Added in version 1.0.17.
 *
 * [Feature] This function depends on the feature +grub+.  See also {#feature_available}[rdoc-ref:feature_available].
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_grub_install}[http://libguestfs.org/guestfs.3.html#guestfs_grub_install].
 */
VALUE
guestfs_int_ruby_grub_install (VALUE gv, VALUE rootv, VALUE devicev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "grub_install");

  const char *root = StringValueCStr (rootv);
  const char *device = StringValueCStr (devicev);

  int r;

  r = guestfs_grub_install (g, root, device);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.hivex_node_add_child(parent, name) -> fixnum
 *
 * add a child node
 *
 * Add a child node to "parent" named "name".
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
 *         {guestfs_hivex_node_add_child}[http://libguestfs.org/guestfs.3.html#guestfs_hivex_node_add_child].
 */
VALUE
guestfs_int_ruby_hivex_node_add_child (VALUE gv, VALUE parentv, VALUE namev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "hivex_node_add_child");

  long long parent = NUM2LL (parentv);
  const char *name = StringValueCStr (namev);

  int64_t r;

  r = guestfs_hivex_node_add_child (g, parent, name);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return ULL2NUM (r);
}

/*
 * call-seq:
 *   g.hivex_node_get_value(nodeh, key) -> fixnum
 *
 * return the named value
 *
 * Return the value attached to "nodeh" which has the name
 * "key", if it exists. This can return 0 meaning the key
 * was not found.
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
 *         {guestfs_hivex_node_get_value}[http://libguestfs.org/guestfs.3.html#guestfs_hivex_node_get_value].
 */
VALUE
guestfs_int_ruby_hivex_node_get_value (VALUE gv, VALUE nodehv, VALUE keyv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "hivex_node_get_value");

  long long nodeh = NUM2LL (nodehv);
  const char *key = StringValueCStr (keyv);

  int64_t r;

  r = guestfs_hivex_node_get_value (g, nodeh, key);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return ULL2NUM (r);
}

/*
 * call-seq:
 *   g.inspect_get_arch(root) -> string
 *
 * get architecture of inspected operating system
 *
 * This returns the architecture of the inspected operating
 * system. The possible return values are listed under
 * "g.file_architecture".
 * 
 * If the architecture could not be determined, then the
 * string "unknown" is returned.
 * 
 * Please read "INSPECTION" in guestfs(3) for more details.
 *
 *
 * [Since] Added in version 1.5.3.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_inspect_get_arch}[http://libguestfs.org/guestfs.3.html#guestfs_inspect_get_arch].
 */
VALUE
guestfs_int_ruby_inspect_get_arch (VALUE gv, VALUE rootv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "inspect_get_arch");

  const char *root = StringValueCStr (rootv);

  char *r;

  r = guestfs_inspect_get_arch (g, root);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  volatile VALUE rv = rb_str_new2 (r);
  free (r);
  return rv;
}

/*
 * call-seq:
 *   g.inspect_get_drive_mappings(root) -> hash
 *
 * get drive letter mappings
 *
 * This call is useful for Windows which uses a primitive
 * system of assigning drive letters (like C:\) to
 * partitions. This inspection API examines the Windows
 * Registry to find out how disks/partitions are mapped to
 * drive letters, and returns a hash table as in the
 * example below:
 * 
 * C      =>     /dev/vda2
 * E      =>     /dev/vdb1
 * F      =>     /dev/vdc1
 * 
 * Note that keys are drive letters. For Windows, the key
 * is case insensitive and just contains the drive letter,
 * without the customary colon separator character.
 * 
 * In future we may support other operating systems that
 * also used drive letters, but the keys for those might
 * not be case insensitive and might be longer than 1
 * character. For example in OS-9, hard drives were named
 * "h0", "h1" etc.
 * 
 * For Windows guests, currently only hard drive mappings
 * are returned. Removable disks (eg. DVD-ROMs) are
 * ignored.
 * 
 * For guests that do not use drive mappings, or if the
 * drive mappings could not be determined, this returns an
 * empty hash table.
 * 
 * Please read "INSPECTION" in guestfs(3) for more details.
 * See also "g.inspect_get_mountpoints",
 * "g.inspect_get_filesystems".
 *
 *
 * [Since] Added in version 1.9.17.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_inspect_get_drive_mappings}[http://libguestfs.org/guestfs.3.html#guestfs_inspect_get_drive_mappings].
 */
VALUE
guestfs_int_ruby_inspect_get_drive_mappings (VALUE gv, VALUE rootv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "inspect_get_drive_mappings");

  const char *root = StringValueCStr (rootv);

  char **r;

  r = guestfs_inspect_get_drive_mappings (g, root);
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
 *   g.inspect_get_windows_current_control_set(root) -> string
 *
 * get Windows CurrentControlSet of inspected operating system
 *
 * This returns the Windows CurrentControlSet of the
 * inspected guest. The CurrentControlSet is a registry key
 * name such as "ControlSet001".
 * 
 * This call assumes that the guest is Windows and that the
 * Registry could be examined by inspection. If this is not
 * the case then an error is returned.
 * 
 * Please read "INSPECTION" in guestfs(3) for more details.
 *
 *
 * [Since] Added in version 1.9.17.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_inspect_get_windows_current_control_set}[http://libguestfs.org/guestfs.3.html#guestfs_inspect_get_windows_current_control_set].
 */
VALUE
guestfs_int_ruby_inspect_get_windows_current_control_set (VALUE gv, VALUE rootv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "inspect_get_windows_current_control_set");

  const char *root = StringValueCStr (rootv);

  char *r;

  r = guestfs_inspect_get_windows_current_control_set (g, root);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  volatile VALUE rv = rb_str_new2 (r);
  free (r);
  return rv;
}

/*
 * call-seq:
 *   g.inspect_get_windows_systemroot(root) -> string
 *
 * get Windows systemroot of inspected operating system
 *
 * This returns the Windows systemroot of the inspected
 * guest. The systemroot is a directory path such as
 * /WINDOWS.
 * 
 * This call assumes that the guest is Windows and that the
 * systemroot could be determined by inspection. If this is
 * not the case then an error is returned.
 * 
 * Please read "INSPECTION" in guestfs(3) for more details.
 *
 *
 * [Since] Added in version 1.5.25.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_inspect_get_windows_systemroot}[http://libguestfs.org/guestfs.3.html#guestfs_inspect_get_windows_systemroot].
 */
VALUE
guestfs_int_ruby_inspect_get_windows_systemroot (VALUE gv, VALUE rootv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "inspect_get_windows_systemroot");

  const char *root = StringValueCStr (rootv);

  char *r;

  r = guestfs_inspect_get_windows_systemroot (g, root);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  volatile VALUE rv = rb_str_new2 (r);
  free (r);
  return rv;
}

/*
 * call-seq:
 *   g.internal_test_close_output
 *
 * :nodoc:
 */
VALUE
guestfs_int_ruby_internal_test_close_output (VALUE gv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "internal_test_close_output");


  int r;

  r = guestfs_internal_test_close_output (g);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.internal_test_rbufferout
 *
 * :nodoc:
 */
VALUE
guestfs_int_ruby_internal_test_rbufferout (VALUE gv, VALUE valv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "internal_test_rbufferout");

  const char *val = StringValueCStr (valv);

  char *r;
  size_t size;

  r = guestfs_internal_test_rbufferout (g, val, &size);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  volatile VALUE rv = rb_str_new (r, size);
  free (r);
  return rv;
}

/*
 * call-seq:
 *   g.internal_test_rconstoptstringerr
 *
 * :nodoc:
 */
VALUE
guestfs_int_ruby_internal_test_rconstoptstringerr (VALUE gv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "internal_test_rconstoptstringerr");


  const char *r;

  r = guestfs_internal_test_rconstoptstringerr (g);

  if (r)
    return rb_str_new2 (r);
  else
    return Qnil;
}

/*
 * call-seq:
 *   g.internal_test_rinterr
 *
 * :nodoc:
 */
VALUE
guestfs_int_ruby_internal_test_rinterr (VALUE gv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "internal_test_rinterr");


  int r;

  r = guestfs_internal_test_rinterr (g);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return INT2NUM (r);
}

/*
 * call-seq:
 *   g.internal_test_set_output
 *
 * :nodoc:
 */
VALUE
guestfs_int_ruby_internal_test_set_output (VALUE gv, VALUE filenamev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "internal_test_set_output");

  const char *filename = StringValueCStr (filenamev);

  int r;

  r = guestfs_internal_test_set_output (g, filename);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.is_chardev(path, {optargs...}) -> [True|False]
 *
 * test if character device
 *
 * This returns "true" if and only if there is a character
 * device with the given "path" name.
 * 
 * If the optional flag "followsymlinks" is true, then a
 * symlink (or chain of symlinks) that ends with a chardev
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
 *         {guestfs_is_chardev}[http://libguestfs.org/guestfs.3.html#guestfs_is_chardev].
 */
VALUE
guestfs_int_ruby_is_chardev (int argc, VALUE *argv, VALUE gv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "is_chardev");

  if (argc < 1 || argc > 2)
    rb_raise (rb_eArgError, "expecting 1 or 2 arguments");

  volatile VALUE pathv = argv[0];
  volatile VALUE optargsv = argc > 1 ? argv[1] : rb_hash_new ();

  const char *path = StringValueCStr (pathv);

  Check_Type (optargsv, T_HASH);
  struct guestfs_is_chardev_opts_argv optargs_s = { .bitmask = 0 };
  struct guestfs_is_chardev_opts_argv *optargs = &optargs_s;
  volatile VALUE v;
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("followsymlinks")));
  if (v != Qnil) {
    optargs_s.followsymlinks = RTEST (v);
    optargs_s.bitmask |= GUESTFS_IS_CHARDEV_OPTS_FOLLOWSYMLINKS_BITMASK;
  }

  int r;

  r = guestfs_is_chardev_opts_argv (g, path, optargs);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return INT2NUM (r);
}

/*
 * call-seq:
 *   g.is_launching() -> [True|False]
 *
 * is launching subprocess
 *
 * This returns true iff this handle is launching the
 * subprocess (in the "LAUNCHING" state).
 * 
 * For more information on states, see guestfs(3).
 *
 *
 * [Since] Added in version 1.0.2.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_is_launching}[http://libguestfs.org/guestfs.3.html#guestfs_is_launching].
 */
VALUE
guestfs_int_ruby_is_launching (VALUE gv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "is_launching");


  int r;

  r = guestfs_is_launching (g);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return INT2NUM (r);
}

/*
 * call-seq:
 *   g.is_lv(mountable) -> [True|False]
 *
 * test if mountable is a logical volume
 *
 * This command tests whether "mountable" is a logical
 * volume, and returns true iff this is the case.
 *
 *
 * [Since] Added in version 1.5.3.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_is_lv}[http://libguestfs.org/guestfs.3.html#guestfs_is_lv].
 */
VALUE
guestfs_int_ruby_is_lv (VALUE gv, VALUE mountablev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "is_lv");

  const char *mountable = StringValueCStr (mountablev);

  int r;

  r = guestfs_is_lv (g, mountable);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return INT2NUM (r);
}

/*
 * call-seq:
 *   g.is_socket(path, {optargs...}) -> [True|False]
 *
 * test if socket
 *
 * This returns "true" if and only if there is a Unix
 * domain socket with the given "path" name.
 * 
 * If the optional flag "followsymlinks" is true, then a
 * symlink (or chain of symlinks) that ends with a socket
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
 *         {guestfs_is_socket}[http://libguestfs.org/guestfs.3.html#guestfs_is_socket].
 */
VALUE
guestfs_int_ruby_is_socket (int argc, VALUE *argv, VALUE gv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "is_socket");

  if (argc < 1 || argc > 2)
    rb_raise (rb_eArgError, "expecting 1 or 2 arguments");

  volatile VALUE pathv = argv[0];
  volatile VALUE optargsv = argc > 1 ? argv[1] : rb_hash_new ();

  const char *path = StringValueCStr (pathv);

  Check_Type (optargsv, T_HASH);
  struct guestfs_is_socket_opts_argv optargs_s = { .bitmask = 0 };
  struct guestfs_is_socket_opts_argv *optargs = &optargs_s;
  volatile VALUE v;
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("followsymlinks")));
  if (v != Qnil) {
    optargs_s.followsymlinks = RTEST (v);
    optargs_s.bitmask |= GUESTFS_IS_SOCKET_OPTS_FOLLOWSYMLINKS_BITMASK;
  }

  int r;

  r = guestfs_is_socket_opts_argv (g, path, optargs);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return INT2NUM (r);
}

/*
 * call-seq:
 *   g.journal_open(directory) -> nil
 *
 * open the systemd journal
 *
 * Open the systemd journal located in directory. Any
 * previously opened journal handle is closed.
 * 
 * The contents of the journal can be read using
 * "g.journal_next" and "g.journal_get".
 * 
 * After you have finished using the journal, you should
 * close the handle by calling "g.journal_close".
 *
 *
 * [Since] Added in version 1.23.11.
 *
 * [Feature] This function depends on the feature +journal+.  See also {#feature_available}[rdoc-ref:feature_available].
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_journal_open}[http://libguestfs.org/guestfs.3.html#guestfs_journal_open].
 */
VALUE
guestfs_int_ruby_journal_open (VALUE gv, VALUE directoryv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "journal_open");

  const char *directory = StringValueCStr (directoryv);

  int r;

  r = guestfs_journal_open (g, directory);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.kill_subprocess() -> nil
 *
 * kill the hypervisor
 *
 * This kills the hypervisor.
 * 
 * Do not call this. See: "g.shutdown" instead.
 *
 *
 * [Since] Added in version 0.3.
 *
 * [Deprecated] In new code, use rdoc-ref:shutdown instead.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_kill_subprocess}[http://libguestfs.org/guestfs.3.html#guestfs_kill_subprocess].
 */
VALUE
guestfs_int_ruby_kill_subprocess (VALUE gv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "kill_subprocess");


  int r;

  r = guestfs_kill_subprocess (g);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.ldmtool_scan_devices(devices) -> list
 *
 * scan for Windows dynamic disks
 *
 * This function scans for Windows dynamic disks. It
 * returns a list of identifiers (GUIDs) for all disk
 * groups that were found. These identifiers can be passed
 * to other "g.ldmtool_*" functions.
 * 
 * The parameter "devices" is a list of block devices which
 * are scanned. If this list is empty, all block devices
 * are scanned.
 *
 *
 * [Since] Added in version 1.20.0.
 *
 * [Feature] This function depends on the feature +ldm+.  See also {#feature_available}[rdoc-ref:feature_available].
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_ldmtool_scan_devices}[http://libguestfs.org/guestfs.3.html#guestfs_ldmtool_scan_devices].
 */
VALUE
guestfs_int_ruby_ldmtool_scan_devices (VALUE gv, VALUE devicesv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "ldmtool_scan_devices");

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

  char **r;

  r = guestfs_ldmtool_scan_devices (g, devices);
  free (devices);
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
 *   g.lsetxattr(xattr, val, vallen, path) -> nil
 *
 * set extended attribute of a file or directory
 *
 * This is the same as "g.setxattr", but if "path" is a
 * symbolic link, then it sets an extended attribute of the
 * link itself.
 *
 *
 * [Since] Added in version 1.0.59.
 *
 * [Feature] This function depends on the feature +linuxxattrs+.  See also {#feature_available}[rdoc-ref:feature_available].
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_lsetxattr}[http://libguestfs.org/guestfs.3.html#guestfs_lsetxattr].
 */
VALUE
guestfs_int_ruby_lsetxattr (VALUE gv, VALUE xattrv, VALUE valv, VALUE vallenv, VALUE pathv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "lsetxattr");

  const char *xattr = StringValueCStr (xattrv);
  const char *val = StringValueCStr (valv);
  int vallen = NUM2INT (vallenv);
  const char *path = StringValueCStr (pathv);

  int r;

  r = guestfs_lsetxattr (g, xattr, val, vallen, path);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.luks_kill_slot(device, key, keyslot) -> nil
 *
 * remove a key from a LUKS encrypted device
 *
 * This command deletes the key in key slot "keyslot" from
 * the encrypted LUKS device "device". "key" must be one of
 * the *other* keys.
 *
 *
 * [Since] Added in version 1.5.2.
 *
 * [Feature] This function depends on the feature +luks+.  See also {#feature_available}[rdoc-ref:feature_available].
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_luks_kill_slot}[http://libguestfs.org/guestfs.3.html#guestfs_luks_kill_slot].
 */
VALUE
guestfs_int_ruby_luks_kill_slot (VALUE gv, VALUE devicev, VALUE keyv, VALUE keyslotv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "luks_kill_slot");

  const char *device = StringValueCStr (devicev);
  const char *key = StringValueCStr (keyv);
  int keyslot = NUM2INT (keyslotv);

  int r;

  r = guestfs_luks_kill_slot (g, device, key, keyslot);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.mkdir(path) -> nil
 *
 * create a directory
 *
 * Create a directory named "path".
 *
 *
 * [Since] Added in version 0.8.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_mkdir}[http://libguestfs.org/guestfs.3.html#guestfs_mkdir].
 */
VALUE
guestfs_int_ruby_mkdir (VALUE gv, VALUE pathv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "mkdir");

  const char *path = StringValueCStr (pathv);

  int r;

  r = guestfs_mkdir (g, path);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.mkfifo(mode, path) -> nil
 *
 * make FIFO (named pipe)
 *
 * This call creates a FIFO (named pipe) called "path" with
 * mode "mode". It is just a convenient wrapper around
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
 *         {guestfs_mkfifo}[http://libguestfs.org/guestfs.3.html#guestfs_mkfifo].
 */
VALUE
guestfs_int_ruby_mkfifo (VALUE gv, VALUE modev, VALUE pathv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "mkfifo");

  int mode = NUM2INT (modev);
  const char *path = StringValueCStr (pathv);

  int r;

  r = guestfs_mkfifo (g, mode, path);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.mksquashfs(path, filename, {optargs...}) -> nil
 *
 * create a squashfs filesystem
 *
 * Create a squashfs filesystem for the specified "path".
 * 
 * The optional "compress" flag controls compression. If
 * not given, then the output compressed using "gzip".
 * Otherwise one of the following strings may be given to
 * select the compression type of the squashfs: "gzip",
 * "lzma", "lzo", "lz4", "xz".
 * 
 * The other optional arguments are:
 * 
 * "excludes"
 * A list of wildcards. Files are excluded if they
 * match any of the wildcards.
 * 
 * Please note that this API may fail when used to compress
 * directories with large files, such as the resulting
 * squashfs will be over 3GB big.
 * 
 * Optional arguments are supplied in the final hash
 * parameter, which is a hash of the argument name to its
 * value. Pass an empty {} for no optional arguments.
 *
 *
 * [Since] Added in version 1.35.25.
 *
 * [Feature] This function depends on the feature +squashfs+.  See also {#feature_available}[rdoc-ref:feature_available].
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_mksquashfs}[http://libguestfs.org/guestfs.3.html#guestfs_mksquashfs].
 */
VALUE
guestfs_int_ruby_mksquashfs (int argc, VALUE *argv, VALUE gv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "mksquashfs");

  if (argc < 2 || argc > 3)
    rb_raise (rb_eArgError, "expecting 2 or 3 arguments");

  volatile VALUE pathv = argv[0];
  volatile VALUE filenamev = argv[1];
  volatile VALUE optargsv = argc > 2 ? argv[2] : rb_hash_new ();

  const char *path = StringValueCStr (pathv);
  const char *filename = StringValueCStr (filenamev);

  Check_Type (optargsv, T_HASH);
  struct guestfs_mksquashfs_argv optargs_s = { .bitmask = 0 };
  struct guestfs_mksquashfs_argv *optargs = &optargs_s;
  volatile VALUE v;
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("compress")));
  if (v != Qnil) {
    optargs_s.compress = StringValueCStr (v);
    optargs_s.bitmask |= GUESTFS_MKSQUASHFS_COMPRESS_BITMASK;
  }
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("excludes")));
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
    optargs_s.excludes = r;
  }
    optargs_s.bitmask |= GUESTFS_MKSQUASHFS_EXCLUDES_BITMASK;
  }

  int r;

  r = guestfs_mksquashfs_argv (g, path, filename, optargs);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.modprobe(modulename) -> nil
 *
 * load a kernel module
 *
 * This loads a kernel module in the appliance.
 *
 *
 * [Since] Added in version 1.0.68.
 *
 * [Feature] This function depends on the feature +linuxmodules+.  See also {#feature_available}[rdoc-ref:feature_available].
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_modprobe}[http://libguestfs.org/guestfs.3.html#guestfs_modprobe].
 */
VALUE
guestfs_int_ruby_modprobe (VALUE gv, VALUE modulenamev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "modprobe");

  const char *modulename = StringValueCStr (modulenamev);

  int r;

  r = guestfs_modprobe (g, modulename);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.ntfscat_i(device, inode, filename) -> nil
 *
 * download a file to the local machine given its inode
 *
 * Download a file given its inode from a NTFS filesystem
 * and save it as filename on the local machine.
 * 
 * This allows to download some otherwise inaccessible
 * files such as the ones within the $Extend folder.
 * 
 * The filesystem from which to extract the file must be
 * unmounted, otherwise the call will fail.
 *
 *
 * [Since] Added in version 1.33.14.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_ntfscat_i}[http://libguestfs.org/guestfs.3.html#guestfs_ntfscat_i].
 */
VALUE
guestfs_int_ruby_ntfscat_i (VALUE gv, VALUE devicev, VALUE inodev, VALUE filenamev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "ntfscat_i");

  const char *device = StringValueCStr (devicev);
  long long inode = NUM2LL (inodev);
  const char *filename = StringValueCStr (filenamev);

  int r;

  r = guestfs_ntfscat_i (g, device, inode, filename);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.parse_environment() -> nil
 *
 * parse the environment and set handle flags accordingly
 *
 * Parse the program’s environment and set flags in the
 * handle accordingly. For example if "LIBGUESTFS_DEBUG=1"
 * then the ‘verbose’ flag is set in the handle.
 * 
 * *Most programs do not need to call this*. It is done
 * implicitly when you call "g.create".
 * 
 * See "ENVIRONMENT VARIABLES" in guestfs(3) for a list of
 * environment variables that can affect libguestfs
 * handles. See also "guestfs_create_flags" in guestfs(3),
 * and "g.parse_environment_list".
 *
 *
 * [Since] Added in version 1.19.53.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_parse_environment}[http://libguestfs.org/guestfs.3.html#guestfs_parse_environment].
 */
VALUE
guestfs_int_ruby_parse_environment (VALUE gv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "parse_environment");


  int r;

  r = guestfs_parse_environment (g);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.part_get_disk_guid(device) -> string
 *
 * get the GUID of a GPT-partitioned disk
 *
 * Return the disk identifier (GUID) of a GPT-partitioned
 * "device". Behaviour is undefined for other partition
 * types.
 *
 *
 * [Since] Added in version 1.33.2.
 *
 * [Feature] This function depends on the feature +gdisk+.  See also {#feature_available}[rdoc-ref:feature_available].
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_part_get_disk_guid}[http://libguestfs.org/guestfs.3.html#guestfs_part_get_disk_guid].
 */
VALUE
guestfs_int_ruby_part_get_disk_guid (VALUE gv, VALUE devicev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "part_get_disk_guid");

  const char *device = StringValueCStr (devicev);

  char *r;

  r = guestfs_part_get_disk_guid (g, device);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  volatile VALUE rv = rb_str_new2 (r);
  free (r);
  return rv;
}

/*
 * call-seq:
 *   g.part_list(device) -> list
 *
 * list partitions on a device
 *
 * This command parses the partition table on "device" and
 * returns the list of partitions found.
 * 
 * The fields in the returned structure are:
 * 
 * part_num
 * Partition number, counting from 1.
 * 
 * part_start
 * Start of the partition *in bytes*. To get sectors
 * you have to divide by the device’s sector size, see
 * "g.blockdev_getss".
 * 
 * part_end
 * End of the partition in bytes.
 * 
 * part_size
 * Size of the partition in bytes.
 *
 *
 * [Since] Added in version 1.0.78.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_part_list}[http://libguestfs.org/guestfs.3.html#guestfs_part_list].
 */
VALUE
guestfs_int_ruby_part_list (VALUE gv, VALUE devicev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "part_list");

  const char *device = StringValueCStr (devicev);

  struct guestfs_partition_list *r;

  r = guestfs_part_list (g, device);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  volatile VALUE rv = rb_ary_new2 (r->len);
  size_t i;
  for (i = 0; i < r->len; ++i) {
    volatile VALUE hv = rb_hash_new ();
    rb_hash_aset (hv, rb_str_new2 ("part_num"), INT2NUM (r->val[i].part_num));
    rb_hash_aset (hv, rb_str_new2 ("part_start"), ULL2NUM (r->val[i].part_start));
    rb_hash_aset (hv, rb_str_new2 ("part_end"), ULL2NUM (r->val[i].part_end));
    rb_hash_aset (hv, rb_str_new2 ("part_size"), ULL2NUM (r->val[i].part_size));
    rb_ary_push (rv, hv);
  }
  guestfs_free_partition_list (r);
  return rv;
}

/*
 * call-seq:
 *   g.part_set_bootable(device, partnum, bootable) -> nil
 *
 * make a partition bootable
 *
 * This sets the bootable flag on partition numbered
 * "partnum" on device "device". Note that partitions are
 * numbered from 1.
 * 
 * The bootable flag is used by some operating systems
 * (notably Windows) to determine which partition to boot
 * from. It is by no means universally recognized.
 *
 *
 * [Since] Added in version 1.0.78.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_part_set_bootable}[http://libguestfs.org/guestfs.3.html#guestfs_part_set_bootable].
 */
VALUE
guestfs_int_ruby_part_set_bootable (VALUE gv, VALUE devicev, VALUE partnumv, VALUE bootablev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "part_set_bootable");

  const char *device = StringValueCStr (devicev);
  int partnum = NUM2INT (partnumv);
  int bootable = RTEST (bootablev);

  int r;

  r = guestfs_part_set_bootable (g, device, partnum, bootable);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.part_set_gpt_attributes(device, partnum, attributes) -> nil
 *
 * set the attribute flags of a GPT partition
 *
 * Set the attribute flags of numbered GPT partition
 * "partnum" to "attributes". Return an error if the
 * partition table of "device" isn't GPT.
 * 
 * See
 * <https://en.wikipedia.org/wiki/GUID_Partition_Table#Part
 * ition_entries> for a useful list of partition
 * attributes.
 *
 *
 * [Since] Added in version 1.21.1.
 *
 * [Feature] This function depends on the feature +gdisk+.  See also {#feature_available}[rdoc-ref:feature_available].
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_part_set_gpt_attributes}[http://libguestfs.org/guestfs.3.html#guestfs_part_set_gpt_attributes].
 */
VALUE
guestfs_int_ruby_part_set_gpt_attributes (VALUE gv, VALUE devicev, VALUE partnumv, VALUE attributesv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "part_set_gpt_attributes");

  const char *device = StringValueCStr (devicev);
  int partnum = NUM2INT (partnumv);
  long long attributes = NUM2LL (attributesv);

  int r;

  r = guestfs_part_set_gpt_attributes (g, device, partnum, attributes);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.part_set_gpt_guid(device, partnum, guid) -> nil
 *
 * set the GUID of a GPT partition
 *
 * Set the GUID of numbered GPT partition "partnum" to
 * "guid". Return an error if the partition table of
 * "device" isn't GPT, or if "guid" is not a valid GUID.
 *
 *
 * [Since] Added in version 1.29.25.
 *
 * [Feature] This function depends on the feature +gdisk+.  See also {#feature_available}[rdoc-ref:feature_available].
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_part_set_gpt_guid}[http://libguestfs.org/guestfs.3.html#guestfs_part_set_gpt_guid].
 */
VALUE
guestfs_int_ruby_part_set_gpt_guid (VALUE gv, VALUE devicev, VALUE partnumv, VALUE guidv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "part_set_gpt_guid");

  const char *device = StringValueCStr (devicev);
  int partnum = NUM2INT (partnumv);
  const char *guid = StringValueCStr (guidv);

  int r;

  r = guestfs_part_set_gpt_guid (g, device, partnum, guid);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.part_to_dev(partition) -> string
 *
 * convert partition name to device name
 *
 * This function takes a partition name (eg. "/dev/sdb1")
 * and removes the partition number, returning the device
 * name (eg. "/dev/sdb").
 * 
 * The named partition must exist, for example as a string
 * returned from "g.list_partitions".
 * 
 * See also "g.part_to_partnum", "g.device_index".
 *
 *
 * [Since] Added in version 1.5.15.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_part_to_dev}[http://libguestfs.org/guestfs.3.html#guestfs_part_to_dev].
 */
VALUE
guestfs_int_ruby_part_to_dev (VALUE gv, VALUE partitionv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "part_to_dev");

  const char *partition = StringValueCStr (partitionv);

  char *r;

  r = guestfs_part_to_dev (g, partition);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  volatile VALUE rv = rb_str_new2 (r);
  free (r);
  return rv;
}

/*
 * call-seq:
 *   g.pvresize(device) -> nil
 *
 * resize an LVM physical volume
 *
 * This resizes (expands or shrinks) an existing LVM
 * physical volume to match the new size of the underlying
 * device.
 *
 *
 * [Since] Added in version 1.0.26.
 *
 * [Feature] This function depends on the feature +lvm2+.  See also {#feature_available}[rdoc-ref:feature_available].
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_pvresize}[http://libguestfs.org/guestfs.3.html#guestfs_pvresize].
 */
VALUE
guestfs_int_ruby_pvresize (VALUE gv, VALUE devicev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "pvresize");

  const char *device = StringValueCStr (devicev);

  int r;

  r = guestfs_pvresize (g, device);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.pvs_full() -> list
 *
 * list the LVM physical volumes (PVs)
 *
 * List all the physical volumes detected. This is the
 * equivalent of the pvs(8) command. The "full" version
 * includes all fields.
 *
 *
 * [Since] Added in version 0.4.
 *
 * [Feature] This function depends on the feature +lvm2+.  See also {#feature_available}[rdoc-ref:feature_available].
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_pvs_full}[http://libguestfs.org/guestfs.3.html#guestfs_pvs_full].
 */
VALUE
guestfs_int_ruby_pvs_full (VALUE gv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "pvs_full");


  struct guestfs_lvm_pv_list *r;

  r = guestfs_pvs_full (g);
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
 *   g.pwrite_device(device, content, offset) -> fixnum
 *
 * write to part of a device
 *
 * This command writes to part of a device. It writes the
 * data buffer "content" to "device" starting at offset
 * "offset".
 * 
 * This command implements the pwrite(2) system call, and
 * like that system call it may not write the full data
 * requested (although short writes to disk devices and
 * partitions are probably impossible with standard Linux
 * kernels).
 * 
 * See also "g.pwrite".
 * 
 * Because of the message protocol, there is a transfer
 * limit of somewhere between 2MB and 4MB. See "PROTOCOL
 * LIMITS" in guestfs(3).
 *
 *
 * [Since] Added in version 1.5.20.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_pwrite_device}[http://libguestfs.org/guestfs.3.html#guestfs_pwrite_device].
 */
VALUE
guestfs_int_ruby_pwrite_device (VALUE gv, VALUE devicev, VALUE contentv, VALUE offsetv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "pwrite_device");

  const char *device = StringValueCStr (devicev);
  Check_Type (contentv, T_STRING);
  const char *content = RSTRING_PTR (contentv);
  if (!content)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "content", "pwrite_device");
  size_t content_size = RSTRING_LEN (contentv);
  long long offset = NUM2LL (offsetv);

  int r;

  r = guestfs_pwrite_device (g, device, content, content_size, offset);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return INT2NUM (r);
}

/*
 * call-seq:
 *   g.readdir(dir) -> list
 *
 * read directories entries
 *
 * This returns the list of directory entries in directory
 * "dir".
 * 
 * All entries in the directory are returned, including "."
 * and "..". The entries are *not* sorted, but returned in
 * the same order as the underlying filesystem.
 * 
 * Also this call returns basic file type information about
 * each file. The "ftyp" field will contain one of the
 * following characters:
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
 * 'u' Unknown file type
 * 
 * '?' The readdir(3) call returned a "d_type" field with
 * an unexpected value
 * 
 * This function is primarily intended for use by programs.
 * To get a simple list of names, use "g.ls". To get a
 * printable directory for human consumption, use "g.ll".
 * 
 * Because of the message protocol, there is a transfer
 * limit of somewhere between 2MB and 4MB. See "PROTOCOL
 * LIMITS" in guestfs(3).
 *
 *
 * [Since] Added in version 1.0.55.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_readdir}[http://libguestfs.org/guestfs.3.html#guestfs_readdir].
 */
VALUE
guestfs_int_ruby_readdir (VALUE gv, VALUE dirv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "readdir");

  const char *dir = StringValueCStr (dirv);

  struct guestfs_dirent_list *r;

  r = guestfs_readdir (g, dir);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  volatile VALUE rv = rb_ary_new2 (r->len);
  size_t i;
  for (i = 0; i < r->len; ++i) {
    volatile VALUE hv = rb_hash_new ();
    rb_hash_aset (hv, rb_str_new2 ("ino"), LL2NUM (r->val[i].ino));
    rb_hash_aset (hv, rb_str_new2 ("ftyp"), ULL2NUM (r->val[i].ftyp));
    rb_hash_aset (hv, rb_str_new2 ("name"), rb_str_new2 (r->val[i].name));
    rb_ary_push (rv, hv);
  }
  guestfs_free_dirent_list (r);
  return rv;
}

/*
 * call-seq:
 *   g.readlink(path) -> string
 *
 * read the target of a symbolic link
 *
 * This command reads the target of a symbolic link.
 *
 *
 * [Since] Added in version 1.0.66.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_readlink}[http://libguestfs.org/guestfs.3.html#guestfs_readlink].
 */
VALUE
guestfs_int_ruby_readlink (VALUE gv, VALUE pathv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "readlink");

  const char *path = StringValueCStr (pathv);

  char *r;

  r = guestfs_readlink (g, path);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  volatile VALUE rv = rb_str_new2 (r);
  free (r);
  return rv;
}

/*
 * call-seq:
 *   g.resize2fs(device) -> nil
 *
 * resize an ext2, ext3 or ext4 filesystem
 *
 * This resizes an ext2, ext3 or ext4 filesystem to match
 * the size of the underlying device.
 * 
 * See also "RESIZE2FS ERRORS" in guestfs(3).
 *
 *
 * [Since] Added in version 1.0.27.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_resize2fs}[http://libguestfs.org/guestfs.3.html#guestfs_resize2fs].
 */
VALUE
guestfs_int_ruby_resize2fs (VALUE gv, VALUE devicev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "resize2fs");

  const char *device = StringValueCStr (devicev);

  int r;

  r = guestfs_resize2fs (g, device);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.rsync_in(remote, dest, {optargs...}) -> nil
 *
 * synchronize host or remote filesystem with filesystem
 *
 * This call may be used to copy or synchronize the
 * filesystem on the host or on a remote computer with the
 * filesystem within libguestfs. This uses the rsync(1)
 * program which uses a fast algorithm that avoids copying
 * files unnecessarily.
 * 
 * This call only works if the network is enabled. See
 * "g.set_network" or the *--network* option to various
 * tools like guestfish(1).
 * 
 * Files are copied from the remote server and directory
 * specified by "remote" to the destination directory
 * "dest".
 * 
 * The format of the remote server string is defined by
 * rsync(1). Note that there is no way to supply a password
 * or passphrase so the target must be set up not to
 * require one.
 * 
 * The optional arguments are the same as those of
 * "g.rsync".
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
 *         {guestfs_rsync_in}[http://libguestfs.org/guestfs.3.html#guestfs_rsync_in].
 */
VALUE
guestfs_int_ruby_rsync_in (int argc, VALUE *argv, VALUE gv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "rsync_in");

  if (argc < 2 || argc > 3)
    rb_raise (rb_eArgError, "expecting 2 or 3 arguments");

  volatile VALUE remotev = argv[0];
  volatile VALUE destv = argv[1];
  volatile VALUE optargsv = argc > 2 ? argv[2] : rb_hash_new ();

  const char *remote = StringValueCStr (remotev);
  const char *dest = StringValueCStr (destv);

  Check_Type (optargsv, T_HASH);
  struct guestfs_rsync_in_argv optargs_s = { .bitmask = 0 };
  struct guestfs_rsync_in_argv *optargs = &optargs_s;
  volatile VALUE v;
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("archive")));
  if (v != Qnil) {
    optargs_s.archive = RTEST (v);
    optargs_s.bitmask |= GUESTFS_RSYNC_IN_ARCHIVE_BITMASK;
  }
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("deletedest")));
  if (v != Qnil) {
    optargs_s.deletedest = RTEST (v);
    optargs_s.bitmask |= GUESTFS_RSYNC_IN_DELETEDEST_BITMASK;
  }

  int r;

  r = guestfs_rsync_in_argv (g, remote, dest, optargs);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.set_e2uuid(device, uuid) -> nil
 *
 * set the ext2/3/4 filesystem UUID
 *
 * This sets the ext2/3/4 filesystem UUID of the filesystem
 * on "device" to "uuid". The format of the UUID and
 * alternatives such as "clear", "random" and "time" are
 * described in the tune2fs(8) manpage.
 * 
 * You can use "g.vfs_uuid" to return the existing UUID of
 * a filesystem.
 *
 *
 * [Since] Added in version 1.0.15.
 *
 * [Deprecated] In new code, use rdoc-ref:set_uuid instead.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_set_e2uuid}[http://libguestfs.org/guestfs.3.html#guestfs_set_e2uuid].
 */
VALUE
guestfs_int_ruby_set_e2uuid (VALUE gv, VALUE devicev, VALUE uuidv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "set_e2uuid");

  const char *device = StringValueCStr (devicev);
  const char *uuid = StringValueCStr (uuidv);

  int r;

  r = guestfs_set_e2uuid (g, device, uuid);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.set_libvirt_requested_credential(index, cred) -> nil
 *
 * pass requested credential back to libvirt
 *
 * After requesting the "index"'th credential from the
 * user, call this function to pass the answer back to
 * libvirt.
 * 
 * See "LIBVIRT AUTHENTICATION" in guestfs(3) for
 * documentation and example code.
 *
 *
 * [Since] Added in version 1.19.52.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_set_libvirt_requested_credential}[http://libguestfs.org/guestfs.3.html#guestfs_set_libvirt_requested_credential].
 */
VALUE
guestfs_int_ruby_set_libvirt_requested_credential (VALUE gv, VALUE indexv, VALUE credv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "set_libvirt_requested_credential");

  int index = NUM2INT (indexv);
  Check_Type (credv, T_STRING);
  const char *cred = RSTRING_PTR (credv);
  if (!cred)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "cred", "set_libvirt_requested_credential");
  size_t cred_size = RSTRING_LEN (credv);

  int r;

  r = guestfs_set_libvirt_requested_credential (g, index, cred, cred_size);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.set_libvirt_supported_credentials(creds) -> nil
 *
 * set libvirt credentials supported by calling program
 *
 * Call this function before setting an event handler for
 * "GUESTFS_EVENT_LIBVIRT_AUTH", to supply the list of
 * credential types that the program knows how to process.
 * 
 * The "creds" list must be a non-empty list of strings.
 * Possible strings are:
 * 
 * "username"
 * "authname"
 * "language"
 * "cnonce"
 * "passphrase"
 * "echoprompt"
 * "noechoprompt"
 * "realm"
 * "external"
 * 
 * See libvirt documentation for the meaning of these
 * credential types.
 * 
 * See "LIBVIRT AUTHENTICATION" in guestfs(3) for
 * documentation and example code.
 *
 *
 * [Since] Added in version 1.19.52.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_set_libvirt_supported_credentials}[http://libguestfs.org/guestfs.3.html#guestfs_set_libvirt_supported_credentials].
 */
VALUE
guestfs_int_ruby_set_libvirt_supported_credentials (VALUE gv, VALUE credsv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "set_libvirt_supported_credentials");

  char **creds;
  Check_Type (credsv, T_ARRAY);
  {
    size_t i, len;
    len = RARRAY_LEN (credsv);
    creds = ALLOC_N (char *, len+1);
    for (i = 0; i < len; ++i) {
      volatile VALUE v = rb_ary_entry (credsv, i);
      creds[i] = StringValueCStr (v);
    }
    creds[len] = NULL;
  }

  int r;

  r = guestfs_set_libvirt_supported_credentials (g, creds);
  free (creds);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.set_path(searchpath) -> nil
 *
 * set the search path
 *
 * Set the path that libguestfs searches for kernel and
 * initrd.img.
 * 
 * The default is "$libdir/guestfs" unless overridden by
 * setting "LIBGUESTFS_PATH" environment variable.
 * 
 * Setting "path" to "NULL" restores the default path.
 *
 *
 * [Since] Added in version 0.3.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_set_path}[http://libguestfs.org/guestfs.3.html#guestfs_set_path].
 */
VALUE
guestfs_int_ruby_set_path (VALUE gv, VALUE searchpathv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "set_path");

  const char *searchpath = !NIL_P (searchpathv) ? StringValueCStr (searchpathv) : NULL;

  int r;

  r = guestfs_set_path (g, searchpath);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.set_pgroup(pgroup) -> nil
 *
 * set process group flag
 *
 * If "pgroup" is true, child processes are placed into
 * their own process group.
 * 
 * The practical upshot of this is that signals like
 * "SIGINT" (from users pressing "^C") won't be received by
 * the child process.
 * 
 * The default for this flag is false, because usually you
 * want "^C" to kill the subprocess. Guestfish sets this
 * flag to true when used interactively, so that "^C" can
 * cancel long-running commands gracefully (see
 * "g.user_cancel").
 *
 *
 * [Since] Added in version 1.11.18.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_set_pgroup}[http://libguestfs.org/guestfs.3.html#guestfs_set_pgroup].
 */
VALUE
guestfs_int_ruby_set_pgroup (VALUE gv, VALUE pgroupv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "set_pgroup");

  int pgroup = RTEST (pgroupv);

  int r;

  r = guestfs_set_pgroup (g, pgroup);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.sfdisk_disk_geometry(device) -> string
 *
 * display the disk geometry from the partition table
 *
 * This displays the disk geometry of "device" read from
 * the partition table. Especially in the case where the
 * underlying block device has been resized, this can be
 * different from the kernel’s idea of the geometry (see
 * "g.sfdisk_kernel_geometry").
 * 
 * The result is in human-readable format, and not designed
 * to be parsed.
 *
 *
 * [Since] Added in version 1.0.26.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_sfdisk_disk_geometry}[http://libguestfs.org/guestfs.3.html#guestfs_sfdisk_disk_geometry].
 */
VALUE
guestfs_int_ruby_sfdisk_disk_geometry (VALUE gv, VALUE devicev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "sfdisk_disk_geometry");

  const char *device = StringValueCStr (devicev);

  char *r;

  r = guestfs_sfdisk_disk_geometry (g, device);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  volatile VALUE rv = rb_str_new2 (r);
  free (r);
  return rv;
}

/*
 * call-seq:
 *   g.sh(command) -> string
 *
 * run a command via the shell
 *
 * This call runs a command from the guest filesystem via
 * the guest’s /bin/sh.
 * 
 * This is like "g.command", but passes the command to:
 * 
 * /bin/sh -c "command"
 * 
 * Depending on the guest’s shell, this usually results in
 * wildcards being expanded, shell expressions being
 * interpolated and so on.
 * 
 * All the provisos about "g.command" apply to this call.
 *
 *
 * [Since] Added in version 1.0.50.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_sh}[http://libguestfs.org/guestfs.3.html#guestfs_sh].
 */
VALUE
guestfs_int_ruby_sh (VALUE gv, VALUE commandv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "sh");

  const char *command = StringValueCStr (commandv);

  char *r;

  r = guestfs_sh (g, command);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  volatile VALUE rv = rb_str_new2 (r);
  free (r);
  return rv;
}

/*
 * call-seq:
 *   g.statns(path) -> hash
 *
 * get file information
 *
 * Returns file information for the given "path".
 * 
 * This is the same as the stat(2) system call.
 *
 *
 * [Since] Added in version 1.27.53.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_statns}[http://libguestfs.org/guestfs.3.html#guestfs_statns].
 */
VALUE
guestfs_int_ruby_statns (VALUE gv, VALUE pathv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "statns");

  const char *path = StringValueCStr (pathv);

  struct guestfs_statns *r;

  r = guestfs_statns (g, path);
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
 *   g.swapon_label(label) -> nil
 *
 * enable swap on labeled swap partition
 *
 * This command enables swap to a labeled swap partition.
 * See "g.swapon_device" for other notes.
 *
 *
 * [Since] Added in version 1.0.66.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_swapon_label}[http://libguestfs.org/guestfs.3.html#guestfs_swapon_label].
 */
VALUE
guestfs_int_ruby_swapon_label (VALUE gv, VALUE labelv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "swapon_label");

  const char *label = StringValueCStr (labelv);

  int r;

  r = guestfs_swapon_label (g, label);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.txz_out(directory, tarball) -> nil
 *
 * pack directory into compressed tarball
 *
 * This command packs the contents of directory and
 * downloads it to local file "tarball" (as an xz
 * compressed tar archive).
 *
 *
 * [Since] Added in version 1.3.2.
 *
 * [Deprecated] In new code, use rdoc-ref:tar_out instead.
 *
 * [Feature] This function depends on the feature +xz+.  See also {#feature_available}[rdoc-ref:feature_available].
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_txz_out}[http://libguestfs.org/guestfs.3.html#guestfs_txz_out].
 */
VALUE
guestfs_int_ruby_txz_out (VALUE gv, VALUE directoryv, VALUE tarballv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "txz_out");

  const char *directory = StringValueCStr (directoryv);
  const char *tarball = StringValueCStr (tarballv);

  int r;

  r = guestfs_txz_out (g, directory, tarball);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.umount_all() -> nil
 *
 * unmount all filesystems
 *
 * This unmounts all mounted filesystems.
 * 
 * Some internal mounts are not unmounted by this call.
 *
 *
 * [Since] Added in version 0.8.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_umount_all}[http://libguestfs.org/guestfs.3.html#guestfs_umount_all].
 */
VALUE
guestfs_int_ruby_umount_all (VALUE gv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "umount_all");


  int r;

  r = guestfs_umount_all (g);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.upload_offset(filename, remotefilename, offset) -> nil
 *
 * upload a file from the local machine with offset
 *
 * Upload local file filename to remotefilename on the
 * filesystem.
 * 
 * remotefilename is overwritten starting at the byte
 * "offset" specified. The intention is to overwrite parts
 * of existing files or devices, although if a non-existent
 * file is specified then it is created with a "hole"
 * before "offset". The size of the data written is
 * implicit in the size of the source filename.
 * 
 * Note that there is no limit on the amount of data that
 * can be uploaded with this call, unlike with "g.pwrite",
 * and this call always writes the full amount unless an
 * error occurs.
 * 
 * See also "g.upload", "g.pwrite".
 *
 *
 * [Since] Added in version 1.5.17.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_upload_offset}[http://libguestfs.org/guestfs.3.html#guestfs_upload_offset].
 */
VALUE
guestfs_int_ruby_upload_offset (VALUE gv, VALUE filenamev, VALUE remotefilenamev, VALUE offsetv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "upload_offset");

  const char *filename = StringValueCStr (filenamev);
  const char *remotefilename = StringValueCStr (remotefilenamev);
  long long offset = NUM2LL (offsetv);

  int r;

  r = guestfs_upload_offset (g, filename, remotefilename, offset);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.utsname() -> hash
 *
 * appliance kernel version
 *
 * This returns the kernel version of the appliance, where
 * this is available. This information is only useful for
 * debugging. Nothing in the returned structure is defined
 * by the API.
 *
 *
 * [Since] Added in version 1.19.27.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_utsname}[http://libguestfs.org/guestfs.3.html#guestfs_utsname].
 */
VALUE
guestfs_int_ruby_utsname (VALUE gv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "utsname");


  struct guestfs_utsname *r;

  r = guestfs_utsname (g);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  volatile VALUE rv = rb_hash_new ();
  rb_hash_aset (rv, rb_str_new2 ("uts_sysname"), rb_str_new2 (r->uts_sysname));
  rb_hash_aset (rv, rb_str_new2 ("uts_release"), rb_str_new2 (r->uts_release));
  rb_hash_aset (rv, rb_str_new2 ("uts_version"), rb_str_new2 (r->uts_version));
  rb_hash_aset (rv, rb_str_new2 ("uts_machine"), rb_str_new2 (r->uts_machine));
  guestfs_free_utsname (r);
  return rv;
}

/*
 * call-seq:
 *   g.vgpvuuids(vgname) -> list
 *
 * get the PV UUIDs containing the volume group
 *
 * Given a VG called "vgname", this returns the UUIDs of
 * all the physical volumes that this volume group resides
 * on.
 * 
 * You can use this along with "g.pvs" and "g.pvuuid" calls
 * to associate physical volumes and volume groups.
 * 
 * See also "g.vglvuuids".
 *
 *
 * [Since] Added in version 1.0.87.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_vgpvuuids}[http://libguestfs.org/guestfs.3.html#guestfs_vgpvuuids].
 */
VALUE
guestfs_int_ruby_vgpvuuids (VALUE gv, VALUE vgnamev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "vgpvuuids");

  const char *vgname = StringValueCStr (vgnamev);

  char **r;

  r = guestfs_vgpvuuids (g, vgname);
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
 *   g.write_append(path, content) -> nil
 *
 * append content to end of file
 *
 * This call appends "content" to the end of file "path".
 * If "path" does not exist, then a new file is created.
 * 
 * See also "g.write".
 *
 *
 * [Since] Added in version 1.11.18.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_write_append}[http://libguestfs.org/guestfs.3.html#guestfs_write_append].
 */
VALUE
guestfs_int_ruby_write_append (VALUE gv, VALUE pathv, VALUE contentv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "write_append");

  const char *path = StringValueCStr (pathv);
  Check_Type (contentv, T_STRING);
  const char *content = RSTRING_PTR (contentv);
  if (!content)
    rb_raise (rb_eTypeError, "expected string for parameter %s of %s",
              "content", "write_append");
  size_t content_size = RSTRING_LEN (contentv);

  int r;

  r = guestfs_write_append (g, path, content, content_size);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.yara_scan(path) -> list
 *
 * scan a file with the loaded yara rules
 *
 * Scan a file with the previously loaded Yara rules.
 * 
 * For each matching rule, a "yara_detection" structure is
 * returned.
 * 
 * The "yara_detection" structure contains the following
 * fields.
 * 
 * "yara_name"
 * Path of the file matching a Yara rule.
 * 
 * "yara_rule"
 * Identifier of the Yara rule which matched against
 * the given file.
 *
 *
 * [Since] Added in version 1.37.13.
 *
 * [Feature] This function depends on the feature +libyara+.  See also {#feature_available}[rdoc-ref:feature_available].
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_yara_scan}[http://libguestfs.org/guestfs.3.html#guestfs_yara_scan].
 */
VALUE
guestfs_int_ruby_yara_scan (VALUE gv, VALUE pathv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "yara_scan");

  const char *path = StringValueCStr (pathv);

  struct guestfs_yara_detection_list *r;

  r = guestfs_yara_scan (g, path);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  volatile VALUE rv = rb_ary_new2 (r->len);
  size_t i;
  for (i = 0; i < r->len; ++i) {
    volatile VALUE hv = rb_hash_new ();
    rb_hash_aset (hv, rb_str_new2 ("yara_name"), rb_str_new2 (r->val[i].yara_name));
    rb_hash_aset (hv, rb_str_new2 ("yara_rule"), rb_str_new2 (r->val[i].yara_rule));
    rb_ary_push (rv, hv);
  }
  guestfs_free_yara_detection_list (r);
  return rv;
}

/*
 * call-seq:
 *   g.zgrep(regex, path) -> list
 *
 * return lines matching a pattern
 *
 * This calls the external "zgrep" program and returns the
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
 *         {guestfs_zgrep}[http://libguestfs.org/guestfs.3.html#guestfs_zgrep].
 */
VALUE
guestfs_int_ruby_zgrep (VALUE gv, VALUE regexv, VALUE pathv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "zgrep");

  const char *regex = StringValueCStr (regexv);
  const char *path = StringValueCStr (pathv);

  char **r;

  r = guestfs_zgrep (g, regex, path);
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

