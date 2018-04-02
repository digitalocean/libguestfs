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
 *   g.aug_mv(src, dest) -> nil
 *
 * move Augeas node
 *
 * Move the node "src" to "dest". "src" must match exactly
 * one node. "dest" is overwritten if it exists.
 *
 *
 * [Since] Added in version 0.7.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_aug_mv}[http://libguestfs.org/guestfs.3.html#guestfs_aug_mv].
 */
VALUE
guestfs_int_ruby_aug_mv (VALUE gv, VALUE srcv, VALUE destv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "aug_mv");

  const char *src = StringValueCStr (srcv);
  const char *dest = StringValueCStr (destv);

  int r;

  r = guestfs_aug_mv (g, src, dest);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.available_all_groups() -> list
 *
 * return a list of all optional groups
 *
 * This command returns a list of all optional groups that
 * this daemon knows about. Note this returns both
 * supported and unsupported groups. To find out which ones
 * the daemon can actually support you have to call
 * "g.available" / "g.feature_available" on each member of
 * the returned list.
 * 
 * See also "g.available", "g.feature_available" and
 * "AVAILABILITY" in guestfs(3).
 *
 *
 * [Since] Added in version 1.3.15.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_available_all_groups}[http://libguestfs.org/guestfs.3.html#guestfs_available_all_groups].
 */
VALUE
guestfs_int_ruby_available_all_groups (VALUE gv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "available_all_groups");


  char **r;

  r = guestfs_available_all_groups (g);
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
 *   g.blockdev_getbsz(device) -> fixnum
 *
 * get blocksize of block device
 *
 * This returns the block size of a device.
 * 
 * Note: this is different from both *size in blocks* and
 * *filesystem block size*. Also this setting is not really
 * used by anything. You should probably not use it for
 * anything. Filesystems have their own idea about what
 * block size to choose.
 * 
 * This uses the blockdev(8) command.
 *
 *
 * [Since] Added in version 1.9.3.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_blockdev_getbsz}[http://libguestfs.org/guestfs.3.html#guestfs_blockdev_getbsz].
 */
VALUE
guestfs_int_ruby_blockdev_getbsz (VALUE gv, VALUE devicev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "blockdev_getbsz");

  const char *device = StringValueCStr (devicev);

  int r;

  r = guestfs_blockdev_getbsz (g, device);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return INT2NUM (r);
}

/*
 * call-seq:
 *   g.blockdev_getro(device) -> [True|False]
 *
 * is block device set to read-only
 *
 * Returns a boolean indicating if the block device is
 * read-only (true if read-only, false if not).
 * 
 * This uses the blockdev(8) command.
 *
 *
 * [Since] Added in version 1.9.3.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_blockdev_getro}[http://libguestfs.org/guestfs.3.html#guestfs_blockdev_getro].
 */
VALUE
guestfs_int_ruby_blockdev_getro (VALUE gv, VALUE devicev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "blockdev_getro");

  const char *device = StringValueCStr (devicev);

  int r;

  r = guestfs_blockdev_getro (g, device);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return INT2NUM (r);
}

/*
 * call-seq:
 *   g.blockdev_setbsz(device, blocksize) -> nil
 *
 * set blocksize of block device
 *
 * This call does nothing and has never done anything
 * because of a bug in blockdev. Do not use it.
 * 
 * If you need to set the filesystem block size, use the
 * "blocksize" option of "g.mkfs".
 *
 *
 * [Since] Added in version 1.9.3.
 *
 * [Deprecated] There is no documented replacement
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_blockdev_setbsz}[http://libguestfs.org/guestfs.3.html#guestfs_blockdev_setbsz].
 */
VALUE
guestfs_int_ruby_blockdev_setbsz (VALUE gv, VALUE devicev, VALUE blocksizev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "blockdev_setbsz");

  const char *device = StringValueCStr (devicev);
  int blocksize = NUM2INT (blocksizev);

  int r;

  r = guestfs_blockdev_setbsz (g, device, blocksize);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.btrfs_qgroup_remove(src, dst, path) -> nil
 *
 * remove a qgroup from its parent qgroup
 *
 * Remove qgroup "src" from the parent qgroup "dst".
 *
 *
 * [Since] Added in version 1.29.17.
 *
 * [Feature] This function depends on the feature +btrfs+.  See also {#feature_available}[rdoc-ref:feature_available].
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_btrfs_qgroup_remove}[http://libguestfs.org/guestfs.3.html#guestfs_btrfs_qgroup_remove].
 */
VALUE
guestfs_int_ruby_btrfs_qgroup_remove (VALUE gv, VALUE srcv, VALUE dstv, VALUE pathv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "btrfs_qgroup_remove");

  const char *src = StringValueCStr (srcv);
  const char *dst = StringValueCStr (dstv);
  const char *path = StringValueCStr (pathv);

  int r;

  r = guestfs_btrfs_qgroup_remove (g, src, dst, path);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.btrfs_quota_enable(fs, enable) -> nil
 *
 * enable or disable subvolume quota support
 *
 * Enable or disable subvolume quota support for filesystem
 * which contains "path".
 *
 *
 * [Since] Added in version 1.29.17.
 *
 * [Feature] This function depends on the feature +btrfs+.  See also {#feature_available}[rdoc-ref:feature_available].
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_btrfs_quota_enable}[http://libguestfs.org/guestfs.3.html#guestfs_btrfs_quota_enable].
 */
VALUE
guestfs_int_ruby_btrfs_quota_enable (VALUE gv, VALUE fsv, VALUE enablev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "btrfs_quota_enable");

  const char *fs = StringValueCStr (fsv);
  int enable = RTEST (enablev);

  int r;

  r = guestfs_btrfs_quota_enable (g, fs, enable);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.checksums_out(csumtype, directory, sumsfile) -> nil
 *
 * compute MD5, SHAx or CRC checksum of files in a directory
 *
 * This command computes the checksums of all regular files
 * in directory and then emits a list of those checksums to
 * the local output file "sumsfile".
 * 
 * This can be used for verifying the integrity of a
 * virtual machine. However to be properly secure you
 * should pay attention to the output of the checksum
 * command (it uses the ones from GNU coreutils). In
 * particular when the filename is not printable, coreutils
 * uses a special backslash syntax. For more information,
 * see the GNU coreutils info file.
 *
 *
 * [Since] Added in version 1.3.7.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_checksums_out}[http://libguestfs.org/guestfs.3.html#guestfs_checksums_out].
 */
VALUE
guestfs_int_ruby_checksums_out (VALUE gv, VALUE csumtypev, VALUE directoryv, VALUE sumsfilev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "checksums_out");

  const char *csumtype = StringValueCStr (csumtypev);
  const char *directory = StringValueCStr (directoryv);
  const char *sumsfile = StringValueCStr (sumsfilev);

  int r;

  r = guestfs_checksums_out (g, csumtype, directory, sumsfile);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.cp_a(src, dest) -> nil
 *
 * copy a file or directory recursively
 *
 * This copies a file or directory from "src" to "dest"
 * recursively using the "cp -a" command.
 *
 *
 * [Since] Added in version 1.0.18.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_cp_a}[http://libguestfs.org/guestfs.3.html#guestfs_cp_a].
 */
VALUE
guestfs_int_ruby_cp_a (VALUE gv, VALUE srcv, VALUE destv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "cp_a");

  const char *src = StringValueCStr (srcv);
  const char *dest = StringValueCStr (destv);

  int r;

  r = guestfs_cp_a (g, src, dest);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.df() -> string
 *
 * report file system disk space usage
 *
 * This command runs the "df" command to report disk space
 * used.
 * 
 * This command is mostly useful for interactive sessions.
 * It is *not* intended that you try to parse the output
 * string. Use "g.statvfs" from programs.
 *
 *
 * [Since] Added in version 1.0.54.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_df}[http://libguestfs.org/guestfs.3.html#guestfs_df].
 */
VALUE
guestfs_int_ruby_df (VALUE gv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "df");


  char *r;

  r = guestfs_df (g);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  volatile VALUE rv = rb_str_new2 (r);
  free (r);
  return rv;
}

/*
 * call-seq:
 *   g.disk_format(filename) -> string
 *
 * detect the disk format of a disk image
 *
 * Detect and return the format of the disk image called
 * filename. filename can also be a host device, etc. If
 * the format of the image could not be detected, then
 * "unknown" is returned.
 * 
 * Note that detecting the disk format can be insecure
 * under some circumstances. See "CVE-2010-3851" in
 * guestfs(3).
 * 
 * See also: "DISK IMAGE FORMATS" in guestfs(3)
 *
 *
 * [Since] Added in version 1.19.38.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_disk_format}[http://libguestfs.org/guestfs.3.html#guestfs_disk_format].
 */
VALUE
guestfs_int_ruby_disk_format (VALUE gv, VALUE filenamev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "disk_format");

  const char *filename = StringValueCStr (filenamev);

  char *r;

  r = guestfs_disk_format (g, filename);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  volatile VALUE rv = rb_str_new2 (r);
  free (r);
  return rv;
}

/*
 * call-seq:
 *   g.egrepi(regex, path) -> list
 *
 * return lines matching a pattern
 *
 * This calls the external "egrep -i" program and returns
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
 *         {guestfs_egrepi}[http://libguestfs.org/guestfs.3.html#guestfs_egrepi].
 */
VALUE
guestfs_int_ruby_egrepi (VALUE gv, VALUE regexv, VALUE pathv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "egrepi");

  const char *regex = StringValueCStr (regexv);
  const char *path = StringValueCStr (pathv);

  char **r;

  r = guestfs_egrepi (g, regex, path);
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
 *   g.fallocate(path, len) -> nil
 *
 * preallocate a file in the guest filesystem
 *
 * This command preallocates a file (containing zero bytes)
 * named "path" of size "len" bytes. If the file exists
 * already, it is overwritten.
 * 
 * Do not confuse this with the guestfish-specific "alloc"
 * command which allocates a file in the host and attaches
 * it as a device.
 *
 *
 * [Since] Added in version 1.0.66.
 *
 * [Deprecated] In new code, use rdoc-ref:fallocate64 instead.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_fallocate}[http://libguestfs.org/guestfs.3.html#guestfs_fallocate].
 */
VALUE
guestfs_int_ruby_fallocate (VALUE gv, VALUE pathv, VALUE lenv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "fallocate");

  const char *path = StringValueCStr (pathv);
  int len = NUM2INT (lenv);

  int r;

  r = guestfs_fallocate (g, path, len);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.fallocate64(path, len) -> nil
 *
 * preallocate a file in the guest filesystem
 *
 * This command preallocates a file (containing zero bytes)
 * named "path" of size "len" bytes. If the file exists
 * already, it is overwritten.
 * 
 * Note that this call allocates disk blocks for the file.
 * To create a sparse file use "g.truncate_size" instead.
 * 
 * The deprecated call "g.fallocate" does the same, but
 * owing to an oversight it only allowed 30 bit lengths to
 * be specified, effectively limiting the maximum size of
 * files created through that call to 1GB.
 * 
 * Do not confuse this with the guestfish-specific "alloc"
 * and "sparse" commands which create a file in the host
 * and attach it as a device.
 *
 *
 * [Since] Added in version 1.3.17.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_fallocate64}[http://libguestfs.org/guestfs.3.html#guestfs_fallocate64].
 */
VALUE
guestfs_int_ruby_fallocate64 (VALUE gv, VALUE pathv, VALUE lenv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "fallocate64");

  const char *path = StringValueCStr (pathv);
  long long len = NUM2LL (lenv);

  int r;

  r = guestfs_fallocate64 (g, path, len);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.fgrep(pattern, path) -> list
 *
 * return lines matching a pattern
 *
 * This calls the external "fgrep" program and returns the
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
 *         {guestfs_fgrep}[http://libguestfs.org/guestfs.3.html#guestfs_fgrep].
 */
VALUE
guestfs_int_ruby_fgrep (VALUE gv, VALUE patternv, VALUE pathv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "fgrep");

  const char *pattern = StringValueCStr (patternv);
  const char *path = StringValueCStr (pathv);

  char **r;

  r = guestfs_fgrep (g, pattern, path);
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
 *   g.file(path) -> string
 *
 * determine file type
 *
 * This call uses the standard file(1) command to determine
 * the type or contents of the file.
 * 
 * This call will also transparently look inside various
 * types of compressed file.
 * 
 * The exact command which runs is "file -zb path". Note in
 * particular that the filename is not prepended to the
 * output (the *-b* option).
 * 
 * The output depends on the output of the underlying
 * file(1) command and it can change in future in ways
 * beyond our control. In other words, the output is not
 * guaranteed by the ABI.
 * 
 * See also: file(1), "g.vfs_type", "g.lstat", "g.is_file",
 * "g.is_blockdev" (etc), "g.is_zero".
 *
 *
 * [Since] Added in version 1.9.1.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_file}[http://libguestfs.org/guestfs.3.html#guestfs_file].
 */
VALUE
guestfs_int_ruby_file (VALUE gv, VALUE pathv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "file");

  const char *path = StringValueCStr (pathv);

  char *r;

  r = guestfs_file (g, path);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  volatile VALUE rv = rb_str_new2 (r);
  free (r);
  return rv;
}

/*
 * call-seq:
 *   g.filesize(file) -> fixnum
 *
 * return the size of the file in bytes
 *
 * This command returns the size of file in bytes.
 * 
 * To get other stats about a file, use "g.stat",
 * "g.lstat", "g.is_dir", "g.is_file" etc. To get the size
 * of block devices, use "g.blockdev_getsize64".
 *
 *
 * [Since] Added in version 1.0.82.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_filesize}[http://libguestfs.org/guestfs.3.html#guestfs_filesize].
 */
VALUE
guestfs_int_ruby_filesize (VALUE gv, VALUE filev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "filesize");

  const char *file = StringValueCStr (filev);

  int64_t r;

  r = guestfs_filesize (g, file);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return ULL2NUM (r);
}

/*
 * call-seq:
 *   g.filesystem_available(filesystem) -> [True|False]
 *
 * check if filesystem is available
 *
 * Check whether libguestfs supports the named filesystem.
 * The argument "filesystem" is a filesystem name, such as
 * "ext3".
 * 
 * You must call "g.launch" before using this command.
 * 
 * This is mainly useful as a negative test. If this
 * returns true, it doesn't mean that a particular
 * filesystem can be created or mounted, since filesystems
 * can fail for other reasons such as it being a later
 * version of the filesystem, or having incompatible
 * features, or lacking the right mkfs.<*fs*> tool.
 * 
 * See also "g.available", "g.feature_available",
 * "AVAILABILITY" in guestfs(3).
 *
 *
 * [Since] Added in version 1.19.5.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_filesystem_available}[http://libguestfs.org/guestfs.3.html#guestfs_filesystem_available].
 */
VALUE
guestfs_int_ruby_filesystem_available (VALUE gv, VALUE filesystemv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "filesystem_available");

  const char *filesystem = StringValueCStr (filesystemv);

  int r;

  r = guestfs_filesystem_available (g, filesystem);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return INT2NUM (r);
}

/*
 * call-seq:
 *   g.fill(c, len, path) -> nil
 *
 * fill a file with octets
 *
 * This command creates a new file called "path". The
 * initial content of the file is "len" octets of "c",
 * where "c" must be a number in the range "[0..255]".
 * 
 * To fill a file with zero bytes (sparsely), it is much
 * more efficient to use "g.truncate_size". To create a
 * file with a pattern of repeating bytes use
 * "g.fill_pattern".
 *
 *
 * [Since] Added in version 1.0.79.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_fill}[http://libguestfs.org/guestfs.3.html#guestfs_fill].
 */
VALUE
guestfs_int_ruby_fill (VALUE gv, VALUE cv, VALUE lenv, VALUE pathv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "fill");

  int c = NUM2INT (cv);
  int len = NUM2INT (lenv);
  const char *path = StringValueCStr (pathv);

  int r;

  r = guestfs_fill (g, c, len, path);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.find(directory) -> list
 *
 * find all files and directories
 *
 * This command lists out all files and directories,
 * recursively, starting at directory. It is essentially
 * equivalent to running the shell command "find directory
 * -print" but some post-processing happens on the output,
 * described below.
 * 
 * This returns a list of strings *without any prefix*.
 * Thus if the directory structure was:
 * 
 * /tmp/a
 * /tmp/b
 * /tmp/c/d
 * 
 * then the returned list from "g.find" /tmp would be 4
 * elements:
 * 
 * a
 * b
 * c
 * c/d
 * 
 * If directory is not a directory, then this command
 * returns an error.
 * 
 * The returned list is sorted.
 *
 *
 * [Since] Added in version 1.0.27.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_find}[http://libguestfs.org/guestfs.3.html#guestfs_find].
 */
VALUE
guestfs_int_ruby_find (VALUE gv, VALUE directoryv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "find");

  const char *directory = StringValueCStr (directoryv);

  char **r;

  r = guestfs_find (g, directory);
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
 *   g.get_direct() -> [True|False]
 *
 * get direct appliance mode flag
 *
 * Return the direct appliance mode flag.
 *
 *
 * [Since] Added in version 1.0.72.
 *
 * [Deprecated] In new code, use rdoc-ref:internal_get_console_socket instead.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_get_direct}[http://libguestfs.org/guestfs.3.html#guestfs_get_direct].
 */
VALUE
guestfs_int_ruby_get_direct (VALUE gv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "get_direct");


  int r;

  r = guestfs_get_direct (g);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return INT2NUM (r);
}

/*
 * call-seq:
 *   g.get_hv() -> string
 *
 * get the hypervisor binary
 *
 * Return the current hypervisor binary.
 * 
 * This is always non-NULL. If it wasn't set already, then
 * this will return the default qemu binary name.
 *
 *
 * [Since] Added in version 1.23.17.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_get_hv}[http://libguestfs.org/guestfs.3.html#guestfs_get_hv].
 */
VALUE
guestfs_int_ruby_get_hv (VALUE gv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "get_hv");


  char *r;

  r = guestfs_get_hv (g);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  volatile VALUE rv = rb_str_new2 (r);
  free (r);
  return rv;
}

/*
 * call-seq:
 *   g.get_libvirt_requested_credentials() -> list
 *
 * get list of credentials requested by libvirt
 *
 * This should only be called during the event callback for
 * events of type "GUESTFS_EVENT_LIBVIRT_AUTH".
 * 
 * Return the list of credentials requested by libvirt.
 * Possible values are a subset of the strings provided
 * when you called "g.set_libvirt_supported_credentials".
 * 
 * See "LIBVIRT AUTHENTICATION" in guestfs(3) for
 * documentation and example code.
 *
 *
 * [Since] Added in version 1.19.52.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_get_libvirt_requested_credentials}[http://libguestfs.org/guestfs.3.html#guestfs_get_libvirt_requested_credentials].
 */
VALUE
guestfs_int_ruby_get_libvirt_requested_credentials (VALUE gv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "get_libvirt_requested_credentials");


  char **r;

  r = guestfs_get_libvirt_requested_credentials (g);
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
 *   g.head(path) -> list
 *
 * return first 10 lines of a file
 *
 * This command returns up to the first 10 lines of a file
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
 *         {guestfs_head}[http://libguestfs.org/guestfs.3.html#guestfs_head].
 */
VALUE
guestfs_int_ruby_head (VALUE gv, VALUE pathv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "head");

  const char *path = StringValueCStr (pathv);

  char **r;

  r = guestfs_head (g, path);
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
 *   g.hivex_node_name(nodeh) -> string
 *
 * return the name of the node
 *
 * Return the name of "nodeh".
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
 *         {guestfs_hivex_node_name}[http://libguestfs.org/guestfs.3.html#guestfs_hivex_node_name].
 */
VALUE
guestfs_int_ruby_hivex_node_name (VALUE gv, VALUE nodehv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "hivex_node_name");

  long long nodeh = NUM2LL (nodehv);

  char *r;

  r = guestfs_hivex_node_name (g, nodeh);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  volatile VALUE rv = rb_str_new2 (r);
  free (r);
  return rv;
}

/*
 * call-seq:
 *   g.hivex_node_values(nodeh) -> list
 *
 * return list of values attached to node
 *
 * Return the array of (key, datatype, data) tuples
 * attached to "nodeh".
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
 *         {guestfs_hivex_node_values}[http://libguestfs.org/guestfs.3.html#guestfs_hivex_node_values].
 */
VALUE
guestfs_int_ruby_hivex_node_values (VALUE gv, VALUE nodehv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "hivex_node_values");

  long long nodeh = NUM2LL (nodehv);

  struct guestfs_hivex_value_list *r;

  r = guestfs_hivex_node_values (g, nodeh);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  volatile VALUE rv = rb_ary_new2 (r->len);
  size_t i;
  for (i = 0; i < r->len; ++i) {
    volatile VALUE hv = rb_hash_new ();
    rb_hash_aset (hv, rb_str_new2 ("hivex_value_h"), LL2NUM (r->val[i].hivex_value_h));
    rb_ary_push (rv, hv);
  }
  guestfs_free_hivex_value_list (r);
  return rv;
}

/*
 * call-seq:
 *   g.inotify_read() -> list
 *
 * return list of inotify events
 *
 * Return the complete queue of events that have happened
 * since the previous read call.
 * 
 * If no events have happened, this returns an empty list.
 * 
 * *Note*: In order to make sure that all events have been
 * read, you must call this function repeatedly until it
 * returns an empty list. The reason is that the call will
 * read events up to the maximum appliance-to-host message
 * size and leave remaining events in the queue.
 *
 *
 * [Since] Added in version 1.0.66.
 *
 * [Feature] This function depends on the feature +inotify+.  See also {#feature_available}[rdoc-ref:feature_available].
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_inotify_read}[http://libguestfs.org/guestfs.3.html#guestfs_inotify_read].
 */
VALUE
guestfs_int_ruby_inotify_read (VALUE gv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "inotify_read");


  struct guestfs_inotify_event_list *r;

  r = guestfs_inotify_read (g);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  volatile VALUE rv = rb_ary_new2 (r->len);
  size_t i;
  for (i = 0; i < r->len; ++i) {
    volatile VALUE hv = rb_hash_new ();
    rb_hash_aset (hv, rb_str_new2 ("in_wd"), LL2NUM (r->val[i].in_wd));
    rb_hash_aset (hv, rb_str_new2 ("in_mask"), UINT2NUM (r->val[i].in_mask));
    rb_hash_aset (hv, rb_str_new2 ("in_cookie"), UINT2NUM (r->val[i].in_cookie));
    rb_hash_aset (hv, rb_str_new2 ("in_name"), rb_str_new2 (r->val[i].in_name));
    rb_ary_push (rv, hv);
  }
  guestfs_free_inotify_event_list (r);
  return rv;
}

/*
 * call-seq:
 *   g.inspect_get_mountpoints(root) -> hash
 *
 * get mountpoints of inspected operating system
 *
 * This returns a hash of where we think the filesystems
 * associated with this operating system should be mounted.
 * Callers should note that this is at best an educated
 * guess made by reading configuration files such as
 * /etc/fstab. *In particular note* that this may return
 * filesystems which are non-existent or not mountable and
 * callers should be prepared to handle or ignore failures
 * if they try to mount them.
 * 
 * Each element in the returned hashtable has a key which
 * is the path of the mountpoint (eg. /boot) and a value
 * which is the filesystem that would be mounted there (eg.
 * /dev/sda1).
 * 
 * Non-mounted devices such as swap devices are *not*
 * returned in this list.
 * 
 * For operating systems like Windows which still use drive
 * letters, this call will only return an entry for the
 * first drive "mounted on" /. For information about the
 * mapping of drive letters to partitions, see
 * "g.inspect_get_drive_mappings".
 * 
 * Please read "INSPECTION" in guestfs(3) for more details.
 * See also "g.inspect_get_filesystems".
 *
 *
 * [Since] Added in version 1.5.3.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_inspect_get_mountpoints}[http://libguestfs.org/guestfs.3.html#guestfs_inspect_get_mountpoints].
 */
VALUE
guestfs_int_ruby_inspect_get_mountpoints (VALUE gv, VALUE rootv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "inspect_get_mountpoints");

  const char *root = StringValueCStr (rootv);

  char **r;

  r = guestfs_inspect_get_mountpoints (g, root);
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
 *   g.inspect_get_package_management(root) -> string
 *
 * get package management tool used by the operating system
 *
 * "g.inspect_get_package_format" and this function return
 * the package format and package management tool used by
 * the inspected operating system. For example for Fedora
 * these functions would return "rpm" (package format), and
 * "yum" or "dnf" (package management).
 * 
 * This returns the string "unknown" if we could not
 * determine the package management tool *or* if the
 * operating system does not have a real packaging system
 * (eg. Windows).
 * 
 * Possible strings include: "yum", "dnf", "up2date", "apt"
 * (for all Debian derivatives), "portage", "pisi",
 * "pacman", "urpmi", "zypper", "apk", "xbps". Future
 * versions of libguestfs may return other strings.
 * 
 * Please read "INSPECTION" in guestfs(3) for more details.
 *
 *
 * [Since] Added in version 1.7.5.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_inspect_get_package_management}[http://libguestfs.org/guestfs.3.html#guestfs_inspect_get_package_management].
 */
VALUE
guestfs_int_ruby_inspect_get_package_management (VALUE gv, VALUE rootv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "inspect_get_package_management");

  const char *root = StringValueCStr (rootv);

  char *r;

  r = guestfs_inspect_get_package_management (g, root);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  volatile VALUE rv = rb_str_new2 (r);
  free (r);
  return rv;
}

/*
 * call-seq:
 *   g.inspect_get_product_name(root) -> string
 *
 * get product name of inspected operating system
 *
 * This returns the product name of the inspected operating
 * system. The product name is generally some freeform
 * string which can be displayed to the user, but should
 * not be parsed by programs.
 * 
 * If the product name could not be determined, then the
 * string "unknown" is returned.
 * 
 * Please read "INSPECTION" in guestfs(3) for more details.
 *
 *
 * [Since] Added in version 1.5.3.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_inspect_get_product_name}[http://libguestfs.org/guestfs.3.html#guestfs_inspect_get_product_name].
 */
VALUE
guestfs_int_ruby_inspect_get_product_name (VALUE gv, VALUE rootv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "inspect_get_product_name");

  const char *root = StringValueCStr (rootv);

  char *r;

  r = guestfs_inspect_get_product_name (g, root);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  volatile VALUE rv = rb_str_new2 (r);
  free (r);
  return rv;
}

/*
 * call-seq:
 *   g.internal_test_rconststring
 *
 * :nodoc:
 */
VALUE
guestfs_int_ruby_internal_test_rconststring (VALUE gv, VALUE valv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "internal_test_rconststring");

  const char *val = StringValueCStr (valv);

  const char *r;

  r = guestfs_internal_test_rconststring (g, val);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return rb_str_new2 (r);
}

/*
 * call-seq:
 *   g.internal_test_rint
 *
 * :nodoc:
 */
VALUE
guestfs_int_ruby_internal_test_rint (VALUE gv, VALUE valv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "internal_test_rint");

  const char *val = StringValueCStr (valv);

  int r;

  r = guestfs_internal_test_rint (g, val);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return INT2NUM (r);
}

/*
 * call-seq:
 *   g.internal_test_rint64err
 *
 * :nodoc:
 */
VALUE
guestfs_int_ruby_internal_test_rint64err (VALUE gv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "internal_test_rint64err");


  int64_t r;

  r = guestfs_internal_test_rint64err (g);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return ULL2NUM (r);
}

/*
 * call-seq:
 *   g.internal_test_rstruct
 *
 * :nodoc:
 */
VALUE
guestfs_int_ruby_internal_test_rstruct (VALUE gv, VALUE valv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "internal_test_rstruct");

  const char *val = StringValueCStr (valv);

  struct guestfs_lvm_pv *r;

  r = guestfs_internal_test_rstruct (g, val);
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
 *   g.isoinfo(isofile) -> hash
 *
 * get ISO information from primary volume descriptor of ISO file
 *
 * This is the same as "g.isoinfo_device" except that it
 * works for an ISO file located inside some other mounted
 * filesystem. Note that in the common case where you have
 * added an ISO file as a libguestfs device, you would
 * *not* call this. Instead you would call
 * "g.isoinfo_device".
 *
 *
 * [Since] Added in version 1.17.19.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_isoinfo}[http://libguestfs.org/guestfs.3.html#guestfs_isoinfo].
 */
VALUE
guestfs_int_ruby_isoinfo (VALUE gv, VALUE isofilev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "isoinfo");

  const char *isofile = StringValueCStr (isofilev);

  struct guestfs_isoinfo *r;

  r = guestfs_isoinfo (g, isofile);
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
 *   g.journal_close() -> nil
 *
 * close the systemd journal
 *
 * Close the journal handle.
 *
 *
 * [Since] Added in version 1.23.11.
 *
 * [Feature] This function depends on the feature +journal+.  See also {#feature_available}[rdoc-ref:feature_available].
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_journal_close}[http://libguestfs.org/guestfs.3.html#guestfs_journal_close].
 */
VALUE
guestfs_int_ruby_journal_close (VALUE gv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "journal_close");


  int r;

  r = guestfs_journal_close (g);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.lgetxattr(path, name) -> string
 *
 * get a single extended attribute
 *
 * Get a single extended attribute from file "path" named
 * "name". If "path" is a symlink, then this call returns
 * an extended attribute from the symlink.
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
 * See also: "g.lgetxattrs", "g.getxattr", attr(5).
 *
 *
 * [Since] Added in version 1.7.24.
 *
 * [Feature] This function depends on the feature +linuxxattrs+.  See also {#feature_available}[rdoc-ref:feature_available].
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_lgetxattr}[http://libguestfs.org/guestfs.3.html#guestfs_lgetxattr].
 */
VALUE
guestfs_int_ruby_lgetxattr (VALUE gv, VALUE pathv, VALUE namev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "lgetxattr");

  const char *path = StringValueCStr (pathv);
  const char *name = StringValueCStr (namev);

  char *r;
  size_t size;

  r = guestfs_lgetxattr (g, path, name, &size);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  volatile VALUE rv = rb_str_new (r, size);
  free (r);
  return rv;
}

/*
 * call-seq:
 *   g.list_9p() -> list
 *
 * list 9p filesystems
 *
 * List all 9p filesystems attached to the guest. A list of
 * mount tags is returned.
 *
 *
 * [Since] Added in version 1.11.12.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_list_9p}[http://libguestfs.org/guestfs.3.html#guestfs_list_9p].
 */
VALUE
guestfs_int_ruby_list_9p (VALUE gv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "list_9p");


  char **r;

  r = guestfs_list_9p (g);
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
 *   g.list_ldm_partitions() -> list
 *
 * list all Windows dynamic disk partitions
 *
 * This function returns all Windows dynamic disk
 * partitions that were found at launch time. It returns a
 * list of device names.
 *
 *
 * [Since] Added in version 1.20.0.
 *
 * [Feature] This function depends on the feature +ldm+.  See also {#feature_available}[rdoc-ref:feature_available].
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_list_ldm_partitions}[http://libguestfs.org/guestfs.3.html#guestfs_list_ldm_partitions].
 */
VALUE
guestfs_int_ruby_list_ldm_partitions (VALUE gv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "list_ldm_partitions");


  char **r;

  r = guestfs_list_ldm_partitions (g);
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
 *   g.luks_format_cipher(device, key, keyslot, cipher) -> nil
 *
 * format a block device as a LUKS encrypted device
 *
 * This command is the same as "g.luks_format" but it also
 * allows you to set the "cipher" used.
 *
 *
 * [Since] Added in version 1.5.2.
 *
 * [Feature] This function depends on the feature +luks+.  See also {#feature_available}[rdoc-ref:feature_available].
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_luks_format_cipher}[http://libguestfs.org/guestfs.3.html#guestfs_luks_format_cipher].
 */
VALUE
guestfs_int_ruby_luks_format_cipher (VALUE gv, VALUE devicev, VALUE keyv, VALUE keyslotv, VALUE cipherv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "luks_format_cipher");

  const char *device = StringValueCStr (devicev);
  const char *key = StringValueCStr (keyv);
  int keyslot = NUM2INT (keyslotv);
  const char *cipher = StringValueCStr (cipherv);

  int r;

  r = guestfs_luks_format_cipher (g, device, key, keyslot, cipher);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.lvm_clear_filter() -> nil
 *
 * clear LVM device filter
 *
 * This undoes the effect of "g.lvm_set_filter". LVM will
 * be able to see every block device.
 * 
 * This command also clears the LVM cache and performs a
 * volume group scan.
 *
 *
 * [Since] Added in version 1.5.1.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_lvm_clear_filter}[http://libguestfs.org/guestfs.3.html#guestfs_lvm_clear_filter].
 */
VALUE
guestfs_int_ruby_lvm_clear_filter (VALUE gv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "lvm_clear_filter");


  int r;

  r = guestfs_lvm_clear_filter (g);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.lvs() -> list
 *
 * list the LVM logical volumes (LVs)
 *
 * List all the logical volumes detected. This is the
 * equivalent of the lvs(8) command.
 * 
 * This returns a list of the logical volume device names
 * (eg. /dev/VolGroup00/LogVol00).
 * 
 * See also "g.lvs_full", "g.list_filesystems".
 *
 *
 * [Since] Added in version 0.4.
 *
 * [Feature] This function depends on the feature +lvm2+.  See also {#feature_available}[rdoc-ref:feature_available].
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_lvs}[http://libguestfs.org/guestfs.3.html#guestfs_lvs].
 */
VALUE
guestfs_int_ruby_lvs (VALUE gv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "lvs");


  char **r;

  r = guestfs_lvs (g);
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
 *   g.max_disks() -> fixnum
 *
 * maximum number of disks that may be added
 *
 * Return the maximum number of disks that may be added to
 * a handle (eg. by "g.add_drive_opts" and similar calls).
 * 
 * This function was added in libguestfs 1.19.7. In
 * previous versions of libguestfs the limit was 25.
 * 
 * See "MAXIMUM NUMBER OF DISKS" in guestfs(3) for
 * additional information on this topic.
 *
 *
 * [Since] Added in version 1.19.7.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_max_disks}[http://libguestfs.org/guestfs.3.html#guestfs_max_disks].
 */
VALUE
guestfs_int_ruby_max_disks (VALUE gv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "max_disks");


  int r;

  r = guestfs_max_disks (g);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return INT2NUM (r);
}

/*
 * call-seq:
 *   g.md_detail(md) -> hash
 *
 * obtain metadata for an MD device
 *
 * This command exposes the output of 'mdadm -DY <md>'. The
 * following fields are usually present in the returned
 * hash. Other fields may also be present.
 * 
 * "level"
 * The raid level of the MD device.
 * 
 * "devices"
 * The number of underlying devices in the MD device.
 * 
 * "metadata"
 * The metadata version used.
 * 
 * "uuid"
 * The UUID of the MD device.
 * 
 * "name"
 * The name of the MD device.
 *
 *
 * [Since] Added in version 1.15.6.
 *
 * [Feature] This function depends on the feature +mdadm+.  See also {#feature_available}[rdoc-ref:feature_available].
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_md_detail}[http://libguestfs.org/guestfs.3.html#guestfs_md_detail].
 */
VALUE
guestfs_int_ruby_md_detail (VALUE gv, VALUE mdv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "md_detail");

  const char *md = StringValueCStr (mdv);

  char **r;

  r = guestfs_md_detail (g, md);
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
 *   g.mke2journal_L(blocksize, label, device) -> nil
 *
 * make ext2/3/4 external journal with label
 *
 * This creates an ext2 external journal on "device" with
 * label "label".
 *
 *
 * [Since] Added in version 1.0.68.
 *
 * [Deprecated] In new code, use rdoc-ref:mke2fs instead.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_mke2journal_L}[http://libguestfs.org/guestfs.3.html#guestfs_mke2journal_L].
 */
VALUE
guestfs_int_ruby_mke2journal_L (VALUE gv, VALUE blocksizev, VALUE labelv, VALUE devicev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "mke2journal_L");

  int blocksize = NUM2INT (blocksizev);
  const char *label = StringValueCStr (labelv);
  const char *device = StringValueCStr (devicev);

  int r;

  r = guestfs_mke2journal_L (g, blocksize, label, device);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.mkswap(device, {optargs...}) -> nil
 *
 * create a swap partition
 *
 * Create a Linux swap partition on "device".
 * 
 * The option arguments "label" and "uuid" allow you to set
 * the label and/or UUID of the new swap partition.
 * 
 * Optional arguments are supplied in the final hash
 * parameter, which is a hash of the argument name to its
 * value. Pass an empty {} for no optional arguments.
 *
 *
 * [Since] Added in version 1.0.55.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_mkswap}[http://libguestfs.org/guestfs.3.html#guestfs_mkswap].
 */
VALUE
guestfs_int_ruby_mkswap (int argc, VALUE *argv, VALUE gv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "mkswap");

  if (argc < 1 || argc > 2)
    rb_raise (rb_eArgError, "expecting 1 or 2 arguments");

  volatile VALUE devicev = argv[0];
  volatile VALUE optargsv = argc > 1 ? argv[1] : rb_hash_new ();

  const char *device = StringValueCStr (devicev);

  Check_Type (optargsv, T_HASH);
  struct guestfs_mkswap_opts_argv optargs_s = { .bitmask = 0 };
  struct guestfs_mkswap_opts_argv *optargs = &optargs_s;
  volatile VALUE v;
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("label")));
  if (v != Qnil) {
    optargs_s.label = StringValueCStr (v);
    optargs_s.bitmask |= GUESTFS_MKSWAP_OPTS_LABEL_BITMASK;
  }
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("uuid")));
  if (v != Qnil) {
    optargs_s.uuid = StringValueCStr (v);
    optargs_s.bitmask |= GUESTFS_MKSWAP_OPTS_UUID_BITMASK;
  }

  int r;

  r = guestfs_mkswap_opts_argv (g, device, optargs);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.mkswap_L(label, device) -> nil
 *
 * create a swap partition with a label
 *
 * Create a swap partition on "device" with label "label".
 * 
 * Note that you cannot attach a swap label to a block
 * device (eg. /dev/sda), just to a partition. This appears
 * to be a limitation of the kernel or swap tools.
 *
 *
 * [Since] Added in version 1.0.55.
 *
 * [Deprecated] In new code, use rdoc-ref:mkswap instead.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_mkswap_L}[http://libguestfs.org/guestfs.3.html#guestfs_mkswap_L].
 */
VALUE
guestfs_int_ruby_mkswap_L (VALUE gv, VALUE labelv, VALUE devicev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "mkswap_L");

  const char *label = StringValueCStr (labelv);
  const char *device = StringValueCStr (devicev);

  int r;

  r = guestfs_mkswap_L (g, label, device);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.mktemp(tmpl, {optargs...}) -> string
 *
 * create a temporary file
 *
 * This command creates a temporary file. The "tmpl"
 * parameter should be a full pathname for the temporary
 * directory name with the final six characters being
 * "XXXXXX".
 * 
 * For example: "/tmp/myprogXXXXXX" or
 * "/Temp/myprogXXXXXX", the second one being suitable for
 * Windows filesystems.
 * 
 * The name of the temporary file that was created is
 * returned.
 * 
 * The temporary file is created with mode 0600 and is
 * owned by root.
 * 
 * The caller is responsible for deleting the temporary
 * file after use.
 * 
 * If the optional "suffix" parameter is given, then the
 * suffix (eg. ".txt") is appended to the temporary name.
 * 
 * See also: "g.mkdtemp".
 * 
 * Optional arguments are supplied in the final hash
 * parameter, which is a hash of the argument name to its
 * value. Pass an empty {} for no optional arguments.
 *
 *
 * [Since] Added in version 1.19.53.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_mktemp}[http://libguestfs.org/guestfs.3.html#guestfs_mktemp].
 */
VALUE
guestfs_int_ruby_mktemp (int argc, VALUE *argv, VALUE gv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "mktemp");

  if (argc < 1 || argc > 2)
    rb_raise (rb_eArgError, "expecting 1 or 2 arguments");

  volatile VALUE tmplv = argv[0];
  volatile VALUE optargsv = argc > 1 ? argv[1] : rb_hash_new ();

  const char *tmpl = StringValueCStr (tmplv);

  Check_Type (optargsv, T_HASH);
  struct guestfs_mktemp_argv optargs_s = { .bitmask = 0 };
  struct guestfs_mktemp_argv *optargs = &optargs_s;
  volatile VALUE v;
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("suffix")));
  if (v != Qnil) {
    optargs_s.suffix = StringValueCStr (v);
    optargs_s.bitmask |= GUESTFS_MKTEMP_SUFFIX_BITMASK;
  }

  char *r;

  r = guestfs_mktemp_argv (g, tmpl, optargs);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  volatile VALUE rv = rb_str_new2 (r);
  free (r);
  return rv;
}

/*
 * call-seq:
 *   g.mount_loop(file, mountpoint) -> nil
 *
 * mount a file using the loop device
 *
 * This command lets you mount file (a filesystem image in
 * a file) on a mount point. It is entirely equivalent to
 * the command "mount -o loop file mountpoint".
 *
 *
 * [Since] Added in version 1.0.54.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_mount_loop}[http://libguestfs.org/guestfs.3.html#guestfs_mount_loop].
 */
VALUE
guestfs_int_ruby_mount_loop (VALUE gv, VALUE filev, VALUE mountpointv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "mount_loop");

  const char *file = StringValueCStr (filev);
  const char *mountpoint = StringValueCStr (mountpointv);

  int r;

  r = guestfs_mount_loop (g, file, mountpoint);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.mount_vfs(options, vfstype, mountable, mountpoint) -> nil
 *
 * mount a guest disk with mount options and vfstype
 *
 * This is the same as the "g.mount" command, but it allows
 * you to set both the mount options and the vfstype as for
 * the mount(8) *-o* and *-t* flags.
 *
 *
 * [Since] Added in version 1.0.10.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_mount_vfs}[http://libguestfs.org/guestfs.3.html#guestfs_mount_vfs].
 */
VALUE
guestfs_int_ruby_mount_vfs (VALUE gv, VALUE optionsv, VALUE vfstypev, VALUE mountablev, VALUE mountpointv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "mount_vfs");

  const char *options = StringValueCStr (optionsv);
  const char *vfstype = StringValueCStr (vfstypev);
  const char *mountable = StringValueCStr (mountablev);
  const char *mountpoint = StringValueCStr (mountpointv);

  int r;

  r = guestfs_mount_vfs (g, options, vfstype, mountable, mountpoint);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.part_set_mbr_id(device, partnum, idbyte) -> nil
 *
 * set the MBR type byte (ID byte) of a partition
 *
 * Sets the MBR type byte (also known as the ID byte) of
 * the numbered partition "partnum" to "idbyte". Note that
 * the type bytes quoted in most documentation are in fact
 * hexadecimal numbers, but usually documented without any
 * leading "0x" which might be confusing.
 * 
 * Note that only MBR (old DOS-style) partitions have type
 * bytes. You will get undefined results for other
 * partition table types (see "g.part_get_parttype").
 *
 *
 * [Since] Added in version 1.3.2.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_part_set_mbr_id}[http://libguestfs.org/guestfs.3.html#guestfs_part_set_mbr_id].
 */
VALUE
guestfs_int_ruby_part_set_mbr_id (VALUE gv, VALUE devicev, VALUE partnumv, VALUE idbytev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "part_set_mbr_id");

  const char *device = StringValueCStr (devicev);
  int partnum = NUM2INT (partnumv);
  int idbyte = NUM2INT (idbytev);

  int r;

  r = guestfs_part_set_mbr_id (g, device, partnum, idbyte);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.pread_device(device, count, offset) -> string
 *
 * read part of a device
 *
 * This command lets you read part of a block device. It
 * reads "count" bytes of "device", starting at "offset".
 * 
 * This may read fewer bytes than requested. For further
 * details see the pread(2) system call.
 * 
 * See also "g.pread".
 * 
 * Because of the message protocol, there is a transfer
 * limit of somewhere between 2MB and 4MB. See "PROTOCOL
 * LIMITS" in guestfs(3).
 *
 *
 * [Since] Added in version 1.5.21.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_pread_device}[http://libguestfs.org/guestfs.3.html#guestfs_pread_device].
 */
VALUE
guestfs_int_ruby_pread_device (VALUE gv, VALUE devicev, VALUE countv, VALUE offsetv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "pread_device");

  const char *device = StringValueCStr (devicev);
  int count = NUM2INT (countv);
  long long offset = NUM2LL (offsetv);

  char *r;
  size_t size;

  r = guestfs_pread_device (g, device, count, offset, &size);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  volatile VALUE rv = rb_str_new (r, size);
  free (r);
  return rv;
}

/*
 * call-seq:
 *   g.pvchange_uuid(device) -> nil
 *
 * generate a new random UUID for a physical volume
 *
 * Generate a new random UUID for the physical volume
 * "device".
 *
 *
 * [Since] Added in version 1.19.26.
 *
 * [Feature] This function depends on the feature +lvm2+.  See also {#feature_available}[rdoc-ref:feature_available].
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_pvchange_uuid}[http://libguestfs.org/guestfs.3.html#guestfs_pvchange_uuid].
 */
VALUE
guestfs_int_ruby_pvchange_uuid (VALUE gv, VALUE devicev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "pvchange_uuid");

  const char *device = StringValueCStr (devicev);

  int r;

  r = guestfs_pvchange_uuid (g, device);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.pvchange_uuid_all() -> nil
 *
 * generate new random UUIDs for all physical volumes
 *
 * Generate new random UUIDs for all physical volumes.
 *
 *
 * [Since] Added in version 1.19.26.
 *
 * [Feature] This function depends on the feature +lvm2+.  See also {#feature_available}[rdoc-ref:feature_available].
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_pvchange_uuid_all}[http://libguestfs.org/guestfs.3.html#guestfs_pvchange_uuid_all].
 */
VALUE
guestfs_int_ruby_pvchange_uuid_all (VALUE gv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "pvchange_uuid_all");


  int r;

  r = guestfs_pvchange_uuid_all (g);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.pvresize_size(device, size) -> nil
 *
 * resize an LVM physical volume (with size)
 *
 * This command is the same as "g.pvresize" except that it
 * allows you to specify the new size (in bytes)
 * explicitly.
 *
 *
 * [Since] Added in version 1.3.14.
 *
 * [Feature] This function depends on the feature +lvm2+.  See also {#feature_available}[rdoc-ref:feature_available].
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_pvresize_size}[http://libguestfs.org/guestfs.3.html#guestfs_pvresize_size].
 */
VALUE
guestfs_int_ruby_pvresize_size (VALUE gv, VALUE devicev, VALUE sizev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "pvresize_size");

  const char *device = StringValueCStr (devicev);
  long long size = NUM2LL (sizev);

  int r;

  r = guestfs_pvresize_size (g, device, size);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.read_lines(path) -> list
 *
 * read file as lines
 *
 * Return the contents of the file named "path".
 * 
 * The file contents are returned as a list of lines.
 * Trailing "LF" and "CRLF" character sequences are *not*
 * returned.
 * 
 * Note that this function cannot correctly handle binary
 * files (specifically, files containing "\0" character
 * which is treated as end of string). For those you need
 * to use the "g.read_file" function and split the buffer
 * into lines yourself.
 *
 *
 * [Since] Added in version 0.7.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_read_lines}[http://libguestfs.org/guestfs.3.html#guestfs_read_lines].
 */
VALUE
guestfs_int_ruby_read_lines (VALUE gv, VALUE pathv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "read_lines");

  const char *path = StringValueCStr (pathv);

  char **r;

  r = guestfs_read_lines (g, path);
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
 *   g.remount(mountpoint, {optargs...}) -> nil
 *
 * remount a filesystem with different options
 *
 * This call allows you to change the "rw"
 * (readonly/read-write) flag on an already mounted
 * filesystem at "mountpoint", converting a readonly
 * filesystem to be read-write, or vice-versa.
 * 
 * Note that at the moment you must supply the "optional"
 * "rw" parameter. In future we may allow other flags to be
 * adjusted.
 * 
 * Optional arguments are supplied in the final hash
 * parameter, which is a hash of the argument name to its
 * value. Pass an empty {} for no optional arguments.
 *
 *
 * [Since] Added in version 1.23.2.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_remount}[http://libguestfs.org/guestfs.3.html#guestfs_remount].
 */
VALUE
guestfs_int_ruby_remount (int argc, VALUE *argv, VALUE gv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "remount");

  if (argc < 1 || argc > 2)
    rb_raise (rb_eArgError, "expecting 1 or 2 arguments");

  volatile VALUE mountpointv = argv[0];
  volatile VALUE optargsv = argc > 1 ? argv[1] : rb_hash_new ();

  const char *mountpoint = StringValueCStr (mountpointv);

  Check_Type (optargsv, T_HASH);
  struct guestfs_remount_argv optargs_s = { .bitmask = 0 };
  struct guestfs_remount_argv *optargs = &optargs_s;
  volatile VALUE v;
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("rw")));
  if (v != Qnil) {
    optargs_s.rw = RTEST (v);
    optargs_s.bitmask |= GUESTFS_REMOUNT_RW_BITMASK;
  }

  int r;

  r = guestfs_remount_argv (g, mountpoint, optargs);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.removexattr(xattr, path) -> nil
 *
 * remove extended attribute of a file or directory
 *
 * This call removes the extended attribute named "xattr"
 * of the file "path".
 * 
 * See also: "g.lremovexattr", attr(5).
 *
 *
 * [Since] Added in version 1.0.59.
 *
 * [Feature] This function depends on the feature +linuxxattrs+.  See also {#feature_available}[rdoc-ref:feature_available].
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_removexattr}[http://libguestfs.org/guestfs.3.html#guestfs_removexattr].
 */
VALUE
guestfs_int_ruby_removexattr (VALUE gv, VALUE xattrv, VALUE pathv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "removexattr");

  const char *xattr = StringValueCStr (xattrv);
  const char *path = StringValueCStr (pathv);

  int r;

  r = guestfs_removexattr (g, xattr, path);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.resize2fs_size(device, size) -> nil
 *
 * resize an ext2, ext3 or ext4 filesystem (with size)
 *
 * This command is the same as "g.resize2fs" except that it
 * allows you to specify the new size (in bytes)
 * explicitly.
 * 
 * See also "RESIZE2FS ERRORS" in guestfs(3).
 *
 *
 * [Since] Added in version 1.3.14.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_resize2fs_size}[http://libguestfs.org/guestfs.3.html#guestfs_resize2fs_size].
 */
VALUE
guestfs_int_ruby_resize2fs_size (VALUE gv, VALUE devicev, VALUE sizev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "resize2fs_size");

  const char *device = StringValueCStr (devicev);
  long long size = NUM2LL (sizev);

  int r;

  r = guestfs_resize2fs_size (g, device, size);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.rm_f(path) -> nil
 *
 * remove a file ignoring errors
 *
 * Remove the file "path".
 * 
 * If the file doesn't exist, that error is ignored. (Other
 * errors, eg. I/O errors or bad paths, are not ignored)
 * 
 * This call cannot remove directories. Use "g.rmdir" to
 * remove an empty directory, or "g.rm_rf" to remove
 * directories recursively.
 *
 *
 * [Since] Added in version 1.19.42.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_rm_f}[http://libguestfs.org/guestfs.3.html#guestfs_rm_f].
 */
VALUE
guestfs_int_ruby_rm_f (VALUE gv, VALUE pathv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "rm_f");

  const char *path = StringValueCStr (pathv);

  int r;

  r = guestfs_rm_f (g, path);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.rsync_out(src, remote, {optargs...}) -> nil
 *
 * synchronize filesystem with host or remote filesystem
 *
 * This call may be used to copy or synchronize the
 * filesystem within libguestfs with a filesystem on the
 * host or on a remote computer. This uses the rsync(1)
 * program which uses a fast algorithm that avoids copying
 * files unnecessarily.
 * 
 * This call only works if the network is enabled. See
 * "g.set_network" or the *--network* option to various
 * tools like guestfish(1).
 * 
 * Files are copied from the source directory "src" to the
 * remote server and directory specified by "remote".
 * 
 * The format of the remote server string is defined by
 * rsync(1). Note that there is no way to supply a password
 * or passphrase so the target must be set up not to
 * require one.
 * 
 * The optional arguments are the same as those of
 * "g.rsync".
 * 
 * Globbing does not happen on the "src" parameter. In
 * programs which use the API directly you have to expand
 * wildcards yourself (see "g.glob_expand"). In guestfish
 * you can use the "glob" command (see "glob" in
 * guestfish(1)), for example:
 * 
 * ><fs> glob rsync-out / * rsync://remote/
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
 *         {guestfs_rsync_out}[http://libguestfs.org/guestfs.3.html#guestfs_rsync_out].
 */
VALUE
guestfs_int_ruby_rsync_out (int argc, VALUE *argv, VALUE gv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "rsync_out");

  if (argc < 2 || argc > 3)
    rb_raise (rb_eArgError, "expecting 2 or 3 arguments");

  volatile VALUE srcv = argv[0];
  volatile VALUE remotev = argv[1];
  volatile VALUE optargsv = argc > 2 ? argv[2] : rb_hash_new ();

  const char *src = StringValueCStr (srcv);
  const char *remote = StringValueCStr (remotev);

  Check_Type (optargsv, T_HASH);
  struct guestfs_rsync_out_argv optargs_s = { .bitmask = 0 };
  struct guestfs_rsync_out_argv *optargs = &optargs_s;
  volatile VALUE v;
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("archive")));
  if (v != Qnil) {
    optargs_s.archive = RTEST (v);
    optargs_s.bitmask |= GUESTFS_RSYNC_OUT_ARCHIVE_BITMASK;
  }
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("deletedest")));
  if (v != Qnil) {
    optargs_s.deletedest = RTEST (v);
    optargs_s.bitmask |= GUESTFS_RSYNC_OUT_DELETEDEST_BITMASK;
  }

  int r;

  r = guestfs_rsync_out_argv (g, src, remote, optargs);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.set_e2generation(file, generation) -> nil
 *
 * set ext2 file generation of a file
 *
 * This sets the ext2 file generation of a file.
 * 
 * See "g.get_e2generation".
 *
 *
 * [Since] Added in version 1.17.31.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_set_e2generation}[http://libguestfs.org/guestfs.3.html#guestfs_set_e2generation].
 */
VALUE
guestfs_int_ruby_set_e2generation (VALUE gv, VALUE filev, VALUE generationv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "set_e2generation");

  const char *file = StringValueCStr (filev);
  long long generation = NUM2LL (generationv);

  int r;

  r = guestfs_set_e2generation (g, file, generation);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.set_label(mountable, label) -> nil
 *
 * set filesystem label
 *
 * Set the filesystem label on "mountable" to "label".
 * 
 * Only some filesystem types support labels, and
 * libguestfs supports setting labels on only a subset of
 * these.
 * 
 * ext2, ext3, ext4
 * Labels are limited to 16 bytes.
 * 
 * NTFS
 * Labels are limited to 128 unicode characters.
 * 
 * XFS The label is limited to 12 bytes. The filesystem
 * must not be mounted when trying to set the label.
 * 
 * btrfs
 * The label is limited to 255 bytes and some
 * characters are not allowed. Setting the label on a
 * btrfs subvolume will set the label on its parent
 * filesystem. The filesystem must not be mounted when
 * trying to set the label.
 * 
 * fat The label is limited to 11 bytes.
 * 
 * swap
 * The label is limited to 16 bytes.
 * 
 * If there is no support for changing the label for the
 * type of the specified filesystem, set_label will fail
 * and set errno as ENOTSUP.
 * 
 * To read the label on a filesystem, call "g.vfs_label".
 *
 *
 * [Since] Added in version 1.17.9.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_set_label}[http://libguestfs.org/guestfs.3.html#guestfs_set_label].
 */
VALUE
guestfs_int_ruby_set_label (VALUE gv, VALUE mountablev, VALUE labelv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "set_label");

  const char *mountable = StringValueCStr (mountablev);
  const char *label = StringValueCStr (labelv);

  int r;

  r = guestfs_set_label (g, mountable, label);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.sfdisk_kernel_geometry(device) -> string
 *
 * display the kernel geometry
 *
 * This displays the kernel’s idea of the geometry of
 * "device".
 * 
 * The result is in human-readable format, and not designed
 * to be parsed.
 *
 *
 * [Since] Added in version 1.0.26.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_sfdisk_kernel_geometry}[http://libguestfs.org/guestfs.3.html#guestfs_sfdisk_kernel_geometry].
 */
VALUE
guestfs_int_ruby_sfdisk_kernel_geometry (VALUE gv, VALUE devicev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "sfdisk_kernel_geometry");

  const char *device = StringValueCStr (devicev);

  char *r;

  r = guestfs_sfdisk_kernel_geometry (g, device);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  volatile VALUE rv = rb_str_new2 (r);
  free (r);
  return rv;
}

/*
 * call-seq:
 *   g.sleep(secs) -> nil
 *
 * sleep for some seconds
 *
 * Sleep for "secs" seconds.
 *
 *
 * [Since] Added in version 1.0.41.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_sleep}[http://libguestfs.org/guestfs.3.html#guestfs_sleep].
 */
VALUE
guestfs_int_ruby_sleep (VALUE gv, VALUE secsv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "sleep");

  int secs = NUM2INT (secsv);

  int r;

  r = guestfs_sleep (g, secs);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.strings_e(encoding, path) -> list
 *
 * print the printable strings in a file
 *
 * This is like the "g.strings" command, but allows you to
 * specify the encoding of strings that are looked for in
 * the source file "path".
 * 
 * Allowed encodings are:
 * 
 * s   Single 7-bit-byte characters like ASCII and the
 * ASCII-compatible parts of ISO-8859-X (this is what
 * "g.strings" uses).
 * 
 * S   Single 8-bit-byte characters.
 * 
 * b   16-bit big endian strings such as those encoded in
 * UTF-16BE or UCS-2BE.
 * 
 * l (lower case letter L)
 * 16-bit little endian such as UTF-16LE and UCS-2LE.
 * This is useful for examining binaries in Windows
 * guests.
 * 
 * B   32-bit big endian such as UCS-4BE.
 * 
 * L   32-bit little endian such as UCS-4LE.
 * 
 * The returned strings are transcoded to UTF-8.
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
 *         {guestfs_strings_e}[http://libguestfs.org/guestfs.3.html#guestfs_strings_e].
 */
VALUE
guestfs_int_ruby_strings_e (VALUE gv, VALUE encodingv, VALUE pathv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "strings_e");

  const char *encoding = StringValueCStr (encodingv);
  const char *path = StringValueCStr (pathv);

  char **r;

  r = guestfs_strings_e (g, encoding, path);
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
 *   g.sync() -> nil
 *
 * sync disks, writes are flushed through to the disk image
 *
 * This syncs the disk, so that any writes are flushed
 * through to the underlying disk image.
 * 
 * You should always call this if you have modified a disk
 * image, before closing the handle.
 *
 *
 * [Since] Added in version 0.3.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_sync}[http://libguestfs.org/guestfs.3.html#guestfs_sync].
 */
VALUE
guestfs_int_ruby_sync (VALUE gv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "sync");


  int r;

  r = guestfs_sync (g);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.tail_n(nrlines, path) -> list
 *
 * return last N lines of a file
 *
 * If the parameter "nrlines" is a positive number, this
 * returns the last "nrlines" lines of the file "path".
 * 
 * If the parameter "nrlines" is a negative number, this
 * returns lines from the file "path", starting with the
 * "-nrlines"th line.
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
 *         {guestfs_tail_n}[http://libguestfs.org/guestfs.3.html#guestfs_tail_n].
 */
VALUE
guestfs_int_ruby_tail_n (VALUE gv, VALUE nrlinesv, VALUE pathv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "tail_n");

  int nrlines = NUM2INT (nrlinesv);
  const char *path = StringValueCStr (pathv);

  char **r;

  r = guestfs_tail_n (g, nrlines, path);
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
 *   g.tar_out(directory, tarfile, {optargs...}) -> nil
 *
 * pack directory into tarfile
 *
 * This command packs the contents of directory and
 * downloads it to local file "tarfile".
 * 
 * The optional "compress" flag controls compression. If
 * not given, then the output will be an uncompressed tar
 * file. Otherwise one of the following strings may be
 * given to select the compression type of the output file:
 * "compress", "gzip", "bzip2", "xz", "lzop". (Note that
 * not all builds of libguestfs will support all of these
 * compression types).
 * 
 * The other optional arguments are:
 * 
 * "excludes"
 * A list of wildcards. Files are excluded if they
 * match any of the wildcards.
 * 
 * "numericowner"
 * If set to true, the output tar file will contain
 * UID/GID numbers instead of user/group names.
 * 
 * "xattrs"
 * If set to true, extended attributes are saved in the
 * output tar.
 * 
 * "selinux"
 * If set to true, SELinux contexts are saved in the
 * output tar.
 * 
 * "acls"
 * If set to true, POSIX ACLs are saved in the output
 * tar.
 * 
 * Optional arguments are supplied in the final hash
 * parameter, which is a hash of the argument name to its
 * value. Pass an empty {} for no optional arguments.
 *
 *
 * [Since] Added in version 1.0.3.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_tar_out}[http://libguestfs.org/guestfs.3.html#guestfs_tar_out].
 */
VALUE
guestfs_int_ruby_tar_out (int argc, VALUE *argv, VALUE gv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "tar_out");

  if (argc < 2 || argc > 3)
    rb_raise (rb_eArgError, "expecting 2 or 3 arguments");

  volatile VALUE directoryv = argv[0];
  volatile VALUE tarfilev = argv[1];
  volatile VALUE optargsv = argc > 2 ? argv[2] : rb_hash_new ();

  const char *directory = StringValueCStr (directoryv);
  const char *tarfile = StringValueCStr (tarfilev);

  Check_Type (optargsv, T_HASH);
  struct guestfs_tar_out_opts_argv optargs_s = { .bitmask = 0 };
  struct guestfs_tar_out_opts_argv *optargs = &optargs_s;
  volatile VALUE v;
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("compress")));
  if (v != Qnil) {
    optargs_s.compress = StringValueCStr (v);
    optargs_s.bitmask |= GUESTFS_TAR_OUT_OPTS_COMPRESS_BITMASK;
  }
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("numericowner")));
  if (v != Qnil) {
    optargs_s.numericowner = RTEST (v);
    optargs_s.bitmask |= GUESTFS_TAR_OUT_OPTS_NUMERICOWNER_BITMASK;
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
    optargs_s.bitmask |= GUESTFS_TAR_OUT_OPTS_EXCLUDES_BITMASK;
  }
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("xattrs")));
  if (v != Qnil) {
    optargs_s.xattrs = RTEST (v);
    optargs_s.bitmask |= GUESTFS_TAR_OUT_OPTS_XATTRS_BITMASK;
  }
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("selinux")));
  if (v != Qnil) {
    optargs_s.selinux = RTEST (v);
    optargs_s.bitmask |= GUESTFS_TAR_OUT_OPTS_SELINUX_BITMASK;
  }
  v = rb_hash_lookup (optargsv, ID2SYM (rb_intern ("acls")));
  if (v != Qnil) {
    optargs_s.acls = RTEST (v);
    optargs_s.bitmask |= GUESTFS_TAR_OUT_OPTS_ACLS_BITMASK;
  }

  int r;

  r = guestfs_tar_out_opts_argv (g, directory, tarfile, optargs);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.vfs_type(mountable) -> string
 *
 * get the Linux VFS type corresponding to a mounted device
 *
 * This command gets the filesystem type corresponding to
 * the filesystem on "mountable".
 * 
 * For most filesystems, the result is the name of the
 * Linux VFS module which would be used to mount this
 * filesystem if you mounted it without specifying the
 * filesystem type. For example a string such as "ext3" or
 * "ntfs".
 *
 *
 * [Since] Added in version 1.0.75.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_vfs_type}[http://libguestfs.org/guestfs.3.html#guestfs_vfs_type].
 */
VALUE
guestfs_int_ruby_vfs_type (VALUE gv, VALUE mountablev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "vfs_type");

  const char *mountable = StringValueCStr (mountablev);

  char *r;

  r = guestfs_vfs_type (g, mountable);
  if (r == NULL)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  volatile VALUE rv = rb_str_new2 (r);
  free (r);
  return rv;
}

/*
 * call-seq:
 *   g.vgcreate(volgroup, physvols) -> nil
 *
 * create an LVM volume group
 *
 * This creates an LVM volume group called "volgroup" from
 * the non-empty list of physical volumes "physvols".
 *
 *
 * [Since] Added in version 0.8.
 *
 * [Feature] This function depends on the feature +lvm2+.  See also {#feature_available}[rdoc-ref:feature_available].
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_vgcreate}[http://libguestfs.org/guestfs.3.html#guestfs_vgcreate].
 */
VALUE
guestfs_int_ruby_vgcreate (VALUE gv, VALUE volgroupv, VALUE physvolsv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "vgcreate");

  const char *volgroup = StringValueCStr (volgroupv);
  char **physvols;
  Check_Type (physvolsv, T_ARRAY);
  {
    size_t i, len;
    len = RARRAY_LEN (physvolsv);
    physvols = ALLOC_N (char *, len+1);
    for (i = 0; i < len; ++i) {
      volatile VALUE v = rb_ary_entry (physvolsv, i);
      physvols[i] = StringValueCStr (v);
    }
    physvols[len] = NULL;
  }

  int r;

  r = guestfs_vgcreate (g, volgroup, physvols);
  free (physvols);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.wait_ready() -> nil
 *
 * wait until the hypervisor launches (no op)
 *
 * This function is a no op.
 * 
 * In versions of the API < 1.0.71 you had to call this
 * function just after calling "g.launch" to wait for the
 * launch to complete. However this is no longer necessary
 * because "g.launch" now does the waiting.
 * 
 * If you see any calls to this function in code then you
 * can just remove them, unless you want to retain
 * compatibility with older versions of the API.
 *
 *
 * [Since] Added in version 0.3.
 *
 * [Deprecated] There is no documented replacement
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_wait_ready}[http://libguestfs.org/guestfs.3.html#guestfs_wait_ready].
 */
VALUE
guestfs_int_ruby_wait_ready (VALUE gv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "wait_ready");


  int r;

  r = guestfs_wait_ready (g);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.wc_c(path) -> fixnum
 *
 * count characters in a file
 *
 * This command counts the characters in a file, using the
 * "wc -c" external command.
 *
 *
 * [Since] Added in version 1.0.54.
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_wc_c}[http://libguestfs.org/guestfs.3.html#guestfs_wc_c].
 */
VALUE
guestfs_int_ruby_wc_c (VALUE gv, VALUE pathv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "wc_c");

  const char *path = StringValueCStr (pathv);

  int r;

  r = guestfs_wc_c (g, path);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return INT2NUM (r);
}

/*
 * call-seq:
 *   g.yara_load(filename) -> nil
 *
 * load yara rules within libguestfs
 *
 * Upload a set of Yara rules from local file filename.
 * 
 * Yara rules allow to categorize files based on textual or
 * binary patterns within their content. See "g.yara_scan"
 * to see how to scan files with the loaded rules.
 * 
 * Rules can be in binary format, as when compiled with
 * yarac command, or in source code format. In the latter
 * case, the rules will be first compiled and then loaded.
 * 
 * Rules in source code format cannot include external
 * files. In such cases, it is recommended to compile them
 * first.
 * 
 * Previously loaded rules will be destroyed.
 *
 *
 * [Since] Added in version 1.37.13.
 *
 * [Feature] This function depends on the feature +libyara+.  See also {#feature_available}[rdoc-ref:feature_available].
 *
 * [C API] For the C API documentation for this function, see
 *         {guestfs_yara_load}[http://libguestfs.org/guestfs.3.html#guestfs_yara_load].
 */
VALUE
guestfs_int_ruby_yara_load (VALUE gv, VALUE filenamev)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "yara_load");

  const char *filename = StringValueCStr (filenamev);

  int r;

  r = guestfs_yara_load (g, filename);
  if (r == -1)
    rb_raise (e_Error, "%s", guestfs_last_error (g));

  return Qnil;
}

/*
 * call-seq:
 *   g.zegrep(regex, path) -> list
 *
 * return lines matching a pattern
 *
 * This calls the external "zegrep" program and returns the
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
 *         {guestfs_zegrep}[http://libguestfs.org/guestfs.3.html#guestfs_zegrep].
 */
VALUE
guestfs_int_ruby_zegrep (VALUE gv, VALUE regexv, VALUE pathv)
{
  guestfs_h *g;
  Data_Get_Struct (gv, guestfs_h, g);
  if (!g)
    rb_raise (rb_eArgError, "%s: used handle after closing it", "zegrep");

  const char *regex = StringValueCStr (regexv);
  const char *path = StringValueCStr (pathv);

  char **r;

  r = guestfs_zegrep (g, regex, path);
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

