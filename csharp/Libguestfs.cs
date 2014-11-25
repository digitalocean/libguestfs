// libguestfs generated file
// WARNING: THIS FILE IS GENERATED FROM:
//   generator/ *.ml
// ANY CHANGES YOU MAKE TO THIS FILE WILL BE LOST.
//
// Copyright (C) 2009-2014 Red Hat Inc.
//
// This library is free software; you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public
// License as published by the Free Software Foundation; either
// version 2 of the License, or (at your option) any later version.
//
// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public
// License along with this library; if not, write to the Free Software
// Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA

// These C# bindings are highly experimental at present.
//
// Firstly they only work on Linux (ie. Mono).  In order to get them
// to work on Windows (ie. .Net) you would need to port the library
// itself to Windows first.
//
// The second issue is that some calls are known to be incorrect and
// can cause Mono to segfault.  Particularly: calls which pass or
// return string[], or return any structure value.  This is because
// we haven't worked out the correct way to do this from C#.  Also
// we don't handle functions that take optional arguments at all.
//
// The third issue is that when compiling you get a lot of warnings.
// We are not sure whether the warnings are important or not.
//
// Fourthly we do not routinely build or test these bindings as part
// of the make && make check cycle, which means that regressions might
// go unnoticed.
//
// Suggestions and patches are welcome.

// To compile:
//
// gmcs Libguestfs.cs
// mono Libguestfs.exe
//
// (You'll probably want to add a Test class / static main function
// otherwise this won't do anything useful).

using System;
using System.IO;
using System.Runtime.InteropServices;
using System.Runtime.Serialization;
using System.Collections;

namespace Guestfs
{
  class Error : System.ApplicationException
  {
    public Error (string message) : base (message) {}
    protected Error (SerializationInfo info, StreamingContext context) {}
  }

  class Guestfs
  {
    IntPtr _handle;

    [DllImport ("libguestfs.so.0")]
    static extern IntPtr guestfs_create ();

    public Guestfs ()
    {
      _handle = guestfs_create ();
      if (_handle == IntPtr.Zero)
        throw new Error ("could not create guestfs handle");
    }

    [DllImport ("libguestfs.so.0")]
    static extern void guestfs_close (IntPtr h);

    ~Guestfs ()
    {
      guestfs_close (_handle);
    }

    [DllImport ("libguestfs.so.0")]
    static extern string guestfs_last_error (IntPtr h);

    [StructLayout (LayoutKind.Sequential)]
    public class _application {
      string app_name;
      string app_display_name;
      int app_epoch;
      string app_version;
      string app_release;
      string app_install_path;
      string app_trans_path;
      string app_publisher;
      string app_url;
      string app_source_package;
      string app_summary;
      string app_description;
    }

    [StructLayout (LayoutKind.Sequential)]
    public class _application2 {
      string app2_name;
      string app2_display_name;
      int app2_epoch;
      string app2_version;
      string app2_release;
      string app2_arch;
      string app2_install_path;
      string app2_trans_path;
      string app2_publisher;
      string app2_url;
      string app2_source_package;
      string app2_summary;
      string app2_description;
      string app2_spare1;
      string app2_spare2;
      string app2_spare3;
      string app2_spare4;
    }

    [StructLayout (LayoutKind.Sequential)]
    public class _btrfssubvolume {
      ulong btrfssubvolume_id;
      ulong btrfssubvolume_top_level_id;
      string btrfssubvolume_path;
    }

    [StructLayout (LayoutKind.Sequential)]
    public class _dirent {
      long ino;
      char ftyp;
      string name;
    }

    [StructLayout (LayoutKind.Sequential)]
    public class _hivex_node {
      long hivex_node_h;
    }

    [StructLayout (LayoutKind.Sequential)]
    public class _hivex_value {
      long hivex_value_h;
    }

    [StructLayout (LayoutKind.Sequential)]
    public class _inotify_event {
      long in_wd;
      uint in_mask;
      uint in_cookie;
      string in_name;
    }

    [StructLayout (LayoutKind.Sequential)]
    public class _int_bool {
      int i;
      int b;
    }

    [StructLayout (LayoutKind.Sequential)]
    public class _isoinfo {
      string iso_system_id;
      string iso_volume_id;
      uint iso_volume_space_size;
      uint iso_volume_set_size;
      uint iso_volume_sequence_number;
      uint iso_logical_block_size;
      string iso_volume_set_id;
      string iso_publisher_id;
      string iso_data_preparer_id;
      string iso_application_id;
      string iso_copyright_file_id;
      string iso_abstract_file_id;
      string iso_bibliographic_file_id;
      long iso_volume_creation_t;
      long iso_volume_modification_t;
      long iso_volume_expiration_t;
      long iso_volume_effective_t;
    }

    [StructLayout (LayoutKind.Sequential)]
    public class _lvm_lv {
      string lv_name;
      [MarshalAs (UnmanagedType.ByValTStr, SizeConst=16)]
      string lv_uuid;
      string lv_attr;
      long lv_major;
      long lv_minor;
      long lv_kernel_major;
      long lv_kernel_minor;
      ulong lv_size;
      long seg_count;
      string origin;
      float snap_percent; /* [0..100] or -1 */
      float copy_percent; /* [0..100] or -1 */
      string move_pv;
      string lv_tags;
      string mirror_log;
      string modules;
    }

    [StructLayout (LayoutKind.Sequential)]
    public class _lvm_pv {
      string pv_name;
      [MarshalAs (UnmanagedType.ByValTStr, SizeConst=16)]
      string pv_uuid;
      string pv_fmt;
      ulong pv_size;
      ulong dev_size;
      ulong pv_free;
      ulong pv_used;
      string pv_attr;
      long pv_pe_count;
      long pv_pe_alloc_count;
      string pv_tags;
      ulong pe_start;
      long pv_mda_count;
      ulong pv_mda_free;
    }

    [StructLayout (LayoutKind.Sequential)]
    public class _lvm_vg {
      string vg_name;
      [MarshalAs (UnmanagedType.ByValTStr, SizeConst=16)]
      string vg_uuid;
      string vg_fmt;
      string vg_attr;
      ulong vg_size;
      ulong vg_free;
      string vg_sysid;
      ulong vg_extent_size;
      long vg_extent_count;
      long vg_free_count;
      long max_lv;
      long max_pv;
      long pv_count;
      long lv_count;
      long snap_count;
      long vg_seqno;
      string vg_tags;
      long vg_mda_count;
      ulong vg_mda_free;
    }

    [StructLayout (LayoutKind.Sequential)]
    public class _mdstat {
      string mdstat_device;
      int mdstat_index;
      string mdstat_flags;
    }

    [StructLayout (LayoutKind.Sequential)]
    public class _partition {
      int part_num;
      ulong part_start;
      ulong part_end;
      ulong part_size;
    }

    [StructLayout (LayoutKind.Sequential)]
    public class _stat {
      long dev;
      long ino;
      long mode;
      long nlink;
      long uid;
      long gid;
      long rdev;
      long size;
      long blksize;
      long blocks;
      long atime;
      long mtime;
      long ctime;
    }

    [StructLayout (LayoutKind.Sequential)]
    public class _statns {
      long st_dev;
      long st_ino;
      long st_mode;
      long st_nlink;
      long st_uid;
      long st_gid;
      long st_rdev;
      long st_size;
      long st_blksize;
      long st_blocks;
      long st_atime_sec;
      long st_atime_nsec;
      long st_mtime_sec;
      long st_mtime_nsec;
      long st_ctime_sec;
      long st_ctime_nsec;
      long st_spare1;
      long st_spare2;
      long st_spare3;
      long st_spare4;
      long st_spare5;
      long st_spare6;
    }

    [StructLayout (LayoutKind.Sequential)]
    public class _statvfs {
      long bsize;
      long frsize;
      long blocks;
      long bfree;
      long bavail;
      long files;
      long ffree;
      long favail;
      long fsid;
      long flag;
      long namemax;
    }

    [StructLayout (LayoutKind.Sequential)]
    public class _utsname {
      string uts_sysname;
      string uts_release;
      string uts_version;
      string uts_machine;
    }

    [StructLayout (LayoutKind.Sequential)]
    public class _version {
      long major;
      long minor;
      long release;
      string extra;
    }

    [StructLayout (LayoutKind.Sequential)]
    public class _xattr {
      string attrname;
      uint attrval_len;
      string attrval;
    }

    [StructLayout (LayoutKind.Sequential)]
    public class _xfsinfo {
      string xfs_mntpoint;
      uint xfs_inodesize;
      uint xfs_agcount;
      uint xfs_agsize;
      uint xfs_sectsize;
      uint xfs_attr;
      uint xfs_blocksize;
      ulong xfs_datablocks;
      uint xfs_imaxpct;
      uint xfs_sunit;
      uint xfs_swidth;
      uint xfs_dirversion;
      uint xfs_dirblocksize;
      uint xfs_cimode;
      string xfs_logname;
      uint xfs_logblocksize;
      uint xfs_logblocks;
      uint xfs_logversion;
      uint xfs_logsectsize;
      uint xfs_logsunit;
      uint xfs_lazycount;
      string xfs_rtname;
      uint xfs_rtextsize;
      ulong xfs_rtblocks;
      ulong xfs_rtextents;
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_acl_delete_def_file (IntPtr h, [In] string dir);

    /// <summary>
    /// delete the default POSIX ACL of a directory
    /// </summary>
    public void acl_delete_def_file (string dir)
    {
      int r;
      r = guestfs_acl_delete_def_file (_handle, dir);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern string guestfs_acl_get_file (IntPtr h, [In] string path, [In] string acltype);

    /// <summary>
    /// get the POSIX ACL attached to a file
    /// </summary>
    public string acl_get_file (string path, string acltype)
    {
      string r;
      r = guestfs_acl_get_file (_handle, path, acltype);
      if (r == null)
        throw new Error (guestfs_last_error (_handle));
      return r;
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_acl_set_file (IntPtr h, [In] string path, [In] string acltype, [In] string acl);

    /// <summary>
    /// set the POSIX ACL attached to a file
    /// </summary>
    public void acl_set_file (string path, string acltype, string acl)
    {
      int r;
      r = guestfs_acl_set_file (_handle, path, acltype, acl);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_add_cdrom (IntPtr h, [In] string filename);

    /// <summary>
    /// add a CD-ROM disk image to examine
    /// </summary>
    public void add_cdrom (string filename)
    {
      int r;
      r = guestfs_add_cdrom (_handle, filename);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_add_domain_argv (IntPtr h, [In] string dom, void *);

    /// <summary>
    /// add the disk(s) from a named libvirt domain
    /// </summary>
    public int add_domain (string dom)
    {
      int r;
      r = guestfs_add_domain_argv (_handle, dom, NULL);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
      return r;
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_add_drive_opts_argv (IntPtr h, [In] string filename, void *);

    /// <summary>
    /// add an image to examine or modify
    /// </summary>
    public void add_drive (string filename)
    {
      int r;
      r = guestfs_add_drive_opts_argv (_handle, filename, NULL);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    public void add_drive_opts (string filename)
    {
      add_drive (filename);
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_add_drive_ro (IntPtr h, [In] string filename);

    /// <summary>
    /// add a drive in snapshot mode (read-only)
    /// </summary>
    public void add_drive_ro (string filename)
    {
      int r;
      r = guestfs_add_drive_ro (_handle, filename);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_add_drive_ro_with_if (IntPtr h, [In] string filename, [In] string iface);

    /// <summary>
    /// add a drive read-only specifying the QEMU block emulation to use
    /// </summary>
    public void add_drive_ro_with_if (string filename, string iface)
    {
      int r;
      r = guestfs_add_drive_ro_with_if (_handle, filename, iface);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_add_drive_scratch_argv (IntPtr h, long size, void *);

    /// <summary>
    /// add a temporary scratch drive
    /// </summary>
    public void add_drive_scratch (long size)
    {
      int r;
      r = guestfs_add_drive_scratch_argv (_handle, size, NULL);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_add_drive_with_if (IntPtr h, [In] string filename, [In] string iface);

    /// <summary>
    /// add a drive specifying the QEMU block emulation to use
    /// </summary>
    public void add_drive_with_if (string filename, string iface)
    {
      int r;
      r = guestfs_add_drive_with_if (_handle, filename, iface);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_aug_clear (IntPtr h, [In] string augpath);

    /// <summary>
    /// clear Augeas path
    /// </summary>
    public void aug_clear (string augpath)
    {
      int r;
      r = guestfs_aug_clear (_handle, augpath);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_aug_close (IntPtr h);

    /// <summary>
    /// close the current Augeas handle
    /// </summary>
    public void aug_close ()
    {
      int r;
      r = guestfs_aug_close (_handle);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern _int_bool guestfs_aug_defnode (IntPtr h, [In] string name, [In] string expr, [In] string val);

    /// <summary>
    /// define an Augeas node
    /// </summary>
    public _int_bool aug_defnode (string name, string expr, string val)
    {
      _int_bool r;
      r = guestfs_aug_defnode (_handle, name, expr, val);
      if (r == null)
        throw new Error (guestfs_last_error (_handle));
      return r;
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_aug_defvar (IntPtr h, [In] string name, [In] string expr);

    /// <summary>
    /// define an Augeas variable
    /// </summary>
    public int aug_defvar (string name, string expr)
    {
      int r;
      r = guestfs_aug_defvar (_handle, name, expr);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
      return r;
    }

    [DllImport ("libguestfs.so.0")]
    static extern string guestfs_aug_get (IntPtr h, [In] string augpath);

    /// <summary>
    /// look up the value of an Augeas path
    /// </summary>
    public string aug_get (string augpath)
    {
      string r;
      r = guestfs_aug_get (_handle, augpath);
      if (r == null)
        throw new Error (guestfs_last_error (_handle));
      return r;
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_aug_init (IntPtr h, [In] string root, int flags);

    /// <summary>
    /// create a new Augeas handle
    /// </summary>
    public void aug_init (string root, int flags)
    {
      int r;
      r = guestfs_aug_init (_handle, root, flags);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_aug_insert (IntPtr h, [In] string augpath, [In] string label, bool before);

    /// <summary>
    /// insert a sibling Augeas node
    /// </summary>
    public void aug_insert (string augpath, string label, bool before)
    {
      int r;
      r = guestfs_aug_insert (_handle, augpath, label, before);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern string guestfs_aug_label (IntPtr h, [In] string augpath);

    /// <summary>
    /// return the label from an Augeas path expression
    /// </summary>
    public string aug_label (string augpath)
    {
      string r;
      r = guestfs_aug_label (_handle, augpath);
      if (r == null)
        throw new Error (guestfs_last_error (_handle));
      return r;
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_aug_load (IntPtr h);

    /// <summary>
    /// load files into the tree
    /// </summary>
    public void aug_load ()
    {
      int r;
      r = guestfs_aug_load (_handle);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern string[] guestfs_aug_ls (IntPtr h, [In] string augpath);

    /// <summary>
    /// list Augeas nodes under augpath
    /// </summary>
    public string[] aug_ls (string augpath)
    {
      string[] r;
      r = guestfs_aug_ls (_handle, augpath);
      if (r == null)
        throw new Error (guestfs_last_error (_handle));
      return r;
    }

    [DllImport ("libguestfs.so.0")]
    static extern string[] guestfs_aug_match (IntPtr h, [In] string augpath);

    /// <summary>
    /// return Augeas nodes which match augpath
    /// </summary>
    public string[] aug_match (string augpath)
    {
      string[] r;
      r = guestfs_aug_match (_handle, augpath);
      if (r == null)
        throw new Error (guestfs_last_error (_handle));
      return r;
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_aug_mv (IntPtr h, [In] string src, [In] string dest);

    /// <summary>
    /// move Augeas node
    /// </summary>
    public void aug_mv (string src, string dest)
    {
      int r;
      r = guestfs_aug_mv (_handle, src, dest);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_aug_rm (IntPtr h, [In] string augpath);

    /// <summary>
    /// remove an Augeas path
    /// </summary>
    public int aug_rm (string augpath)
    {
      int r;
      r = guestfs_aug_rm (_handle, augpath);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
      return r;
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_aug_save (IntPtr h);

    /// <summary>
    /// write all pending Augeas changes to disk
    /// </summary>
    public void aug_save ()
    {
      int r;
      r = guestfs_aug_save (_handle);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_aug_set (IntPtr h, [In] string augpath, [In] string val);

    /// <summary>
    /// set Augeas path to value
    /// </summary>
    public void aug_set (string augpath, string val)
    {
      int r;
      r = guestfs_aug_set (_handle, augpath, val);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_aug_setm (IntPtr h, [In] string base, [In] string sub, [In] string val);

    /// <summary>
    /// set multiple Augeas nodes
    /// </summary>
    public int aug_setm (string base, string sub, string val)
    {
      int r;
      r = guestfs_aug_setm (_handle, base, sub, val);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
      return r;
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_available (IntPtr h, [In] string[] groups);

    /// <summary>
    /// test availability of some parts of the API
    /// </summary>
    public void available (string[] groups)
    {
      int r;
      r = guestfs_available (_handle, groups);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern string[] guestfs_available_all_groups (IntPtr h);

    /// <summary>
    /// return a list of all optional groups
    /// </summary>
    public string[] available_all_groups ()
    {
      string[] r;
      r = guestfs_available_all_groups (_handle);
      if (r == null)
        throw new Error (guestfs_last_error (_handle));
      return r;
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_base64_in (IntPtr h, [In] string base64file, [In] string filename);

    /// <summary>
    /// upload base64-encoded data to file
    /// </summary>
    public void base64_in (string base64file, string filename)
    {
      int r;
      r = guestfs_base64_in (_handle, base64file, filename);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_base64_out (IntPtr h, [In] string filename, [In] string base64file);

    /// <summary>
    /// download file and encode as base64
    /// </summary>
    public void base64_out (string filename, string base64file)
    {
      int r;
      r = guestfs_base64_out (_handle, filename, base64file);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_blkdiscard (IntPtr h, [In] string device);

    /// <summary>
    /// discard all blocks on a device
    /// </summary>
    public void blkdiscard (string device)
    {
      int r;
      r = guestfs_blkdiscard (_handle, device);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_blkdiscardzeroes (IntPtr h, [In] string device);

    /// <summary>
    /// return true if discarded blocks are read as zeroes
    /// </summary>
    public bool blkdiscardzeroes (string device)
    {
      int r;
      r = guestfs_blkdiscardzeroes (_handle, device);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
      return r != 0 ? true : false;
    }

    [DllImport ("libguestfs.so.0")]
    static extern string[] guestfs_blkid (IntPtr h, [In] string device);

    /// <summary>
    /// print block device attributes
    /// </summary>
    public Hashtable blkid (string device)
    {
      string[] r;
      r = guestfs_blkid (_handle, device);
      if (r == null)
        throw new Error (guestfs_last_error (_handle));
      Hashtable rr = new Hashtable ();
      for (size_t i = 0; i < r.Length; i += 2)
        rr.Add (r[i], r[i+1]);
      return rr;
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_blockdev_flushbufs (IntPtr h, [In] string device);

    /// <summary>
    /// flush device buffers
    /// </summary>
    public void blockdev_flushbufs (string device)
    {
      int r;
      r = guestfs_blockdev_flushbufs (_handle, device);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_blockdev_getbsz (IntPtr h, [In] string device);

    /// <summary>
    /// get blocksize of block device
    /// </summary>
    public int blockdev_getbsz (string device)
    {
      int r;
      r = guestfs_blockdev_getbsz (_handle, device);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
      return r;
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_blockdev_getro (IntPtr h, [In] string device);

    /// <summary>
    /// is block device set to read-only
    /// </summary>
    public bool blockdev_getro (string device)
    {
      int r;
      r = guestfs_blockdev_getro (_handle, device);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
      return r != 0 ? true : false;
    }

    [DllImport ("libguestfs.so.0")]
    static extern long guestfs_blockdev_getsize64 (IntPtr h, [In] string device);

    /// <summary>
    /// get total size of device in bytes
    /// </summary>
    public long blockdev_getsize64 (string device)
    {
      long r;
      r = guestfs_blockdev_getsize64 (_handle, device);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
      return r;
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_blockdev_getss (IntPtr h, [In] string device);

    /// <summary>
    /// get sectorsize of block device
    /// </summary>
    public int blockdev_getss (string device)
    {
      int r;
      r = guestfs_blockdev_getss (_handle, device);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
      return r;
    }

    [DllImport ("libguestfs.so.0")]
    static extern long guestfs_blockdev_getsz (IntPtr h, [In] string device);

    /// <summary>
    /// get total size of device in 512-byte sectors
    /// </summary>
    public long blockdev_getsz (string device)
    {
      long r;
      r = guestfs_blockdev_getsz (_handle, device);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
      return r;
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_blockdev_rereadpt (IntPtr h, [In] string device);

    /// <summary>
    /// reread partition table
    /// </summary>
    public void blockdev_rereadpt (string device)
    {
      int r;
      r = guestfs_blockdev_rereadpt (_handle, device);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_blockdev_setbsz (IntPtr h, [In] string device, int blocksize);

    /// <summary>
    /// set blocksize of block device
    /// </summary>
    public void blockdev_setbsz (string device, int blocksize)
    {
      int r;
      r = guestfs_blockdev_setbsz (_handle, device, blocksize);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_blockdev_setra (IntPtr h, [In] string device, int sectors);

    /// <summary>
    /// set readahead
    /// </summary>
    public void blockdev_setra (string device, int sectors)
    {
      int r;
      r = guestfs_blockdev_setra (_handle, device, sectors);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_blockdev_setro (IntPtr h, [In] string device);

    /// <summary>
    /// set block device to read-only
    /// </summary>
    public void blockdev_setro (string device)
    {
      int r;
      r = guestfs_blockdev_setro (_handle, device);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_blockdev_setrw (IntPtr h, [In] string device);

    /// <summary>
    /// set block device to read-write
    /// </summary>
    public void blockdev_setrw (string device)
    {
      int r;
      r = guestfs_blockdev_setrw (_handle, device);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_btrfs_device_add (IntPtr h, [In] string[] devices, [In] string fs);

    /// <summary>
    /// add devices to a btrfs filesystem
    /// </summary>
    public void btrfs_device_add (string[] devices, string fs)
    {
      int r;
      r = guestfs_btrfs_device_add (_handle, devices, fs);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_btrfs_device_delete (IntPtr h, [In] string[] devices, [In] string fs);

    /// <summary>
    /// remove devices from a btrfs filesystem
    /// </summary>
    public void btrfs_device_delete (string[] devices, string fs)
    {
      int r;
      r = guestfs_btrfs_device_delete (_handle, devices, fs);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_btrfs_filesystem_balance (IntPtr h, [In] string fs);

    /// <summary>
    /// balance a btrfs filesystem
    /// </summary>
    public void btrfs_filesystem_balance (string fs)
    {
      int r;
      r = guestfs_btrfs_filesystem_balance (_handle, fs);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_btrfs_filesystem_resize_argv (IntPtr h, [In] string mountpoint, void *);

    /// <summary>
    /// resize a btrfs filesystem
    /// </summary>
    public void btrfs_filesystem_resize (string mountpoint)
    {
      int r;
      r = guestfs_btrfs_filesystem_resize_argv (_handle, mountpoint, NULL);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_btrfs_filesystem_sync (IntPtr h, [In] string fs);

    /// <summary>
    /// sync a btrfs filesystem
    /// </summary>
    public void btrfs_filesystem_sync (string fs)
    {
      int r;
      r = guestfs_btrfs_filesystem_sync (_handle, fs);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_btrfs_fsck_argv (IntPtr h, [In] string device, void *);

    /// <summary>
    /// check a btrfs filesystem
    /// </summary>
    public void btrfs_fsck (string device)
    {
      int r;
      r = guestfs_btrfs_fsck_argv (_handle, device, NULL);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_btrfs_set_seeding (IntPtr h, [In] string device, bool seeding);

    /// <summary>
    /// enable or disable the seeding feature of device
    /// </summary>
    public void btrfs_set_seeding (string device, bool seeding)
    {
      int r;
      r = guestfs_btrfs_set_seeding (_handle, device, seeding);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_btrfs_subvolume_create (IntPtr h, [In] string dest);

    /// <summary>
    /// create a btrfs subvolume
    /// </summary>
    public void btrfs_subvolume_create (string dest)
    {
      int r;
      r = guestfs_btrfs_subvolume_create (_handle, dest);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_btrfs_subvolume_delete (IntPtr h, [In] string subvolume);

    /// <summary>
    /// delete a btrfs subvolume or snapshot
    /// </summary>
    public void btrfs_subvolume_delete (string subvolume)
    {
      int r;
      r = guestfs_btrfs_subvolume_delete (_handle, subvolume);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern _btrfssubvolume[] guestfs_btrfs_subvolume_list (IntPtr h, [In] string fs);

    /// <summary>
    /// list btrfs snapshots and subvolumes
    /// </summary>
    public _btrfssubvolume[] btrfs_subvolume_list (string fs)
    {
      _btrfssubvolume[] r;
      r = guestfs_btrfs_subvolume_list (_handle, fs);
      if (r == null)
        throw new Error (guestfs_last_error (_handle));
      return r;
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_btrfs_subvolume_set_default (IntPtr h, long id, [In] string fs);

    /// <summary>
    /// set default btrfs subvolume
    /// </summary>
    public void btrfs_subvolume_set_default (long id, string fs)
    {
      int r;
      r = guestfs_btrfs_subvolume_set_default (_handle, id, fs);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_btrfs_subvolume_snapshot (IntPtr h, [In] string source, [In] string dest);

    /// <summary>
    /// create a writable btrfs snapshot
    /// </summary>
    public void btrfs_subvolume_snapshot (string source, string dest)
    {
      int r;
      r = guestfs_btrfs_subvolume_snapshot (_handle, source, dest);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern string guestfs_canonical_device_name (IntPtr h, [In] string device);

    /// <summary>
    /// return canonical device name
    /// </summary>
    public string canonical_device_name (string device)
    {
      string r;
      r = guestfs_canonical_device_name (_handle, device);
      if (r == null)
        throw new Error (guestfs_last_error (_handle));
      return r;
    }

    [DllImport ("libguestfs.so.0")]
    static extern string guestfs_cap_get_file (IntPtr h, [In] string path);

    /// <summary>
    /// get the Linux capabilities attached to a file
    /// </summary>
    public string cap_get_file (string path)
    {
      string r;
      r = guestfs_cap_get_file (_handle, path);
      if (r == null)
        throw new Error (guestfs_last_error (_handle));
      return r;
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_cap_set_file (IntPtr h, [In] string path, [In] string cap);

    /// <summary>
    /// set the Linux capabilities attached to a file
    /// </summary>
    public void cap_set_file (string path, string cap)
    {
      int r;
      r = guestfs_cap_set_file (_handle, path, cap);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern string guestfs_case_sensitive_path (IntPtr h, [In] string path);

    /// <summary>
    /// return true path on case-insensitive filesystem
    /// </summary>
    public string case_sensitive_path (string path)
    {
      string r;
      r = guestfs_case_sensitive_path (_handle, path);
      if (r == null)
        throw new Error (guestfs_last_error (_handle));
      return r;
    }

    [DllImport ("libguestfs.so.0")]
    static extern string guestfs_cat (IntPtr h, [In] string path);

    /// <summary>
    /// list the contents of a file
    /// </summary>
    public string cat (string path)
    {
      string r;
      r = guestfs_cat (_handle, path);
      if (r == null)
        throw new Error (guestfs_last_error (_handle));
      return r;
    }

    [DllImport ("libguestfs.so.0")]
    static extern string guestfs_checksum (IntPtr h, [In] string csumtype, [In] string path);

    /// <summary>
    /// compute MD5, SHAx or CRC checksum of file
    /// </summary>
    public string checksum (string csumtype, string path)
    {
      string r;
      r = guestfs_checksum (_handle, csumtype, path);
      if (r == null)
        throw new Error (guestfs_last_error (_handle));
      return r;
    }

    [DllImport ("libguestfs.so.0")]
    static extern string guestfs_checksum_device (IntPtr h, [In] string csumtype, [In] string device);

    /// <summary>
    /// compute MD5, SHAx or CRC checksum of the contents of a device
    /// </summary>
    public string checksum_device (string csumtype, string device)
    {
      string r;
      r = guestfs_checksum_device (_handle, csumtype, device);
      if (r == null)
        throw new Error (guestfs_last_error (_handle));
      return r;
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_checksums_out (IntPtr h, [In] string csumtype, [In] string directory, [In] string sumsfile);

    /// <summary>
    /// compute MD5, SHAx or CRC checksum of files in a directory
    /// </summary>
    public void checksums_out (string csumtype, string directory, string sumsfile)
    {
      int r;
      r = guestfs_checksums_out (_handle, csumtype, directory, sumsfile);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_chmod (IntPtr h, int mode, [In] string path);

    /// <summary>
    /// change file mode
    /// </summary>
    public void chmod (int mode, string path)
    {
      int r;
      r = guestfs_chmod (_handle, mode, path);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_chown (IntPtr h, int owner, int group, [In] string path);

    /// <summary>
    /// change file owner and group
    /// </summary>
    public void chown (int owner, int group, string path)
    {
      int r;
      r = guestfs_chown (_handle, owner, group, path);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_clear_backend_setting (IntPtr h, [In] string name);

    /// <summary>
    /// remove a single per-backend settings string
    /// </summary>
    public int clear_backend_setting (string name)
    {
      int r;
      r = guestfs_clear_backend_setting (_handle, name);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
      return r;
    }

    [DllImport ("libguestfs.so.0")]
    static extern string guestfs_command (IntPtr h, [In] string[] arguments);

    /// <summary>
    /// run a command from the guest filesystem
    /// </summary>
    public string command (string[] arguments)
    {
      string r;
      r = guestfs_command (_handle, arguments);
      if (r == null)
        throw new Error (guestfs_last_error (_handle));
      return r;
    }

    [DllImport ("libguestfs.so.0")]
    static extern string[] guestfs_command_lines (IntPtr h, [In] string[] arguments);

    /// <summary>
    /// run a command, returning lines
    /// </summary>
    public string[] command_lines (string[] arguments)
    {
      string[] r;
      r = guestfs_command_lines (_handle, arguments);
      if (r == null)
        throw new Error (guestfs_last_error (_handle));
      return r;
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_compress_device_out_argv (IntPtr h, [In] string ctype, [In] string device, [In] string zdevice, void *);

    /// <summary>
    /// output compressed device
    /// </summary>
    public void compress_device_out (string ctype, string device, string zdevice)
    {
      int r;
      r = guestfs_compress_device_out_argv (_handle, ctype, device, zdevice, NULL);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_compress_out_argv (IntPtr h, [In] string ctype, [In] string file, [In] string zfile, void *);

    /// <summary>
    /// output compressed file
    /// </summary>
    public void compress_out (string ctype, string file, string zfile)
    {
      int r;
      r = guestfs_compress_out_argv (_handle, ctype, file, zfile, NULL);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_config (IntPtr h, [In] string hvparam, [In] string hvvalue);

    /// <summary>
    /// add hypervisor parameters
    /// </summary>
    public void config (string hvparam, string hvvalue)
    {
      int r;
      r = guestfs_config (_handle, hvparam, hvvalue);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_copy_attributes_argv (IntPtr h, [In] string src, [In] string dest, void *);

    /// <summary>
    /// copy the attributes of a path (file/directory) to another
    /// </summary>
    public void copy_attributes (string src, string dest)
    {
      int r;
      r = guestfs_copy_attributes_argv (_handle, src, dest, NULL);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_copy_device_to_device_argv (IntPtr h, [In] string src, [In] string dest, void *);

    /// <summary>
    /// copy from source device to destination device
    /// </summary>
    public void copy_device_to_device (string src, string dest)
    {
      int r;
      r = guestfs_copy_device_to_device_argv (_handle, src, dest, NULL);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_copy_device_to_file_argv (IntPtr h, [In] string src, [In] string dest, void *);

    /// <summary>
    /// copy from source device to destination file
    /// </summary>
    public void copy_device_to_file (string src, string dest)
    {
      int r;
      r = guestfs_copy_device_to_file_argv (_handle, src, dest, NULL);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_copy_file_to_device_argv (IntPtr h, [In] string src, [In] string dest, void *);

    /// <summary>
    /// copy from source file to destination device
    /// </summary>
    public void copy_file_to_device (string src, string dest)
    {
      int r;
      r = guestfs_copy_file_to_device_argv (_handle, src, dest, NULL);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_copy_file_to_file_argv (IntPtr h, [In] string src, [In] string dest, void *);

    /// <summary>
    /// copy from source file to destination file
    /// </summary>
    public void copy_file_to_file (string src, string dest)
    {
      int r;
      r = guestfs_copy_file_to_file_argv (_handle, src, dest, NULL);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_copy_size (IntPtr h, [In] string src, [In] string dest, long size);

    /// <summary>
    /// copy size bytes from source to destination using dd
    /// </summary>
    public void copy_size (string src, string dest, long size)
    {
      int r;
      r = guestfs_copy_size (_handle, src, dest, size);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_cp (IntPtr h, [In] string src, [In] string dest);

    /// <summary>
    /// copy a file
    /// </summary>
    public void cp (string src, string dest)
    {
      int r;
      r = guestfs_cp (_handle, src, dest);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_cp_a (IntPtr h, [In] string src, [In] string dest);

    /// <summary>
    /// copy a file or directory recursively
    /// </summary>
    public void cp_a (string src, string dest)
    {
      int r;
      r = guestfs_cp_a (_handle, src, dest);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_cp_r (IntPtr h, [In] string src, [In] string dest);

    /// <summary>
    /// copy a file or directory recursively
    /// </summary>
    public void cp_r (string src, string dest)
    {
      int r;
      r = guestfs_cp_r (_handle, src, dest);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_cpio_out_argv (IntPtr h, [In] string directory, [In] string cpiofile, void *);

    /// <summary>
    /// pack directory into cpio file
    /// </summary>
    public void cpio_out (string directory, string cpiofile)
    {
      int r;
      r = guestfs_cpio_out_argv (_handle, directory, cpiofile, NULL);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_dd (IntPtr h, [In] string src, [In] string dest);

    /// <summary>
    /// copy from source to destination using dd
    /// </summary>
    public void dd (string src, string dest)
    {
      int r;
      r = guestfs_dd (_handle, src, dest);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern string guestfs_debug (IntPtr h, [In] string subcmd, [In] string[] extraargs);

    /// <summary>
    /// debugging and internals
    /// </summary>
    public string debug (string subcmd, string[] extraargs)
    {
      string r;
      r = guestfs_debug (_handle, subcmd, extraargs);
      if (r == null)
        throw new Error (guestfs_last_error (_handle));
      return r;
    }

    [DllImport ("libguestfs.so.0")]
    static extern string[] guestfs_debug_drives (IntPtr h);

    /// <summary>
    /// debug the drives (internal use only)
    /// </summary>
    public string[] debug_drives ()
    {
      string[] r;
      r = guestfs_debug_drives (_handle);
      if (r == null)
        throw new Error (guestfs_last_error (_handle));
      return r;
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_debug_upload (IntPtr h, [In] string filename, [In] string tmpname, int mode);

    /// <summary>
    /// upload a file to the appliance (internal use only)
    /// </summary>
    public void debug_upload (string filename, string tmpname, int mode)
    {
      int r;
      r = guestfs_debug_upload (_handle, filename, tmpname, mode);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_device_index (IntPtr h, [In] string device);

    /// <summary>
    /// convert device to index
    /// </summary>
    public int device_index (string device)
    {
      int r;
      r = guestfs_device_index (_handle, device);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
      return r;
    }

    [DllImport ("libguestfs.so.0")]
    static extern string guestfs_df (IntPtr h);

    /// <summary>
    /// report file system disk space usage
    /// </summary>
    public string df ()
    {
      string r;
      r = guestfs_df (_handle);
      if (r == null)
        throw new Error (guestfs_last_error (_handle));
      return r;
    }

    [DllImport ("libguestfs.so.0")]
    static extern string guestfs_df_h (IntPtr h);

    /// <summary>
    /// report file system disk space usage (human readable)
    /// </summary>
    public string df_h ()
    {
      string r;
      r = guestfs_df_h (_handle);
      if (r == null)
        throw new Error (guestfs_last_error (_handle));
      return r;
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_disk_create_argv (IntPtr h, [In] string filename, [In] string format, long size, void *);

    /// <summary>
    /// create a blank disk image
    /// </summary>
    public void disk_create (string filename, string format, long size)
    {
      int r;
      r = guestfs_disk_create_argv (_handle, filename, format, size, NULL);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern string guestfs_disk_format (IntPtr h, [In] string filename);

    /// <summary>
    /// detect the disk format of a disk image
    /// </summary>
    public string disk_format (string filename)
    {
      string r;
      r = guestfs_disk_format (_handle, filename);
      if (r == null)
        throw new Error (guestfs_last_error (_handle));
      return r;
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_disk_has_backing_file (IntPtr h, [In] string filename);

    /// <summary>
    /// return whether disk has a backing file
    /// </summary>
    public bool disk_has_backing_file (string filename)
    {
      int r;
      r = guestfs_disk_has_backing_file (_handle, filename);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
      return r != 0 ? true : false;
    }

    [DllImport ("libguestfs.so.0")]
    static extern long guestfs_disk_virtual_size (IntPtr h, [In] string filename);

    /// <summary>
    /// return virtual size of a disk
    /// </summary>
    public long disk_virtual_size (string filename)
    {
      long r;
      r = guestfs_disk_virtual_size (_handle, filename);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
      return r;
    }

    [DllImport ("libguestfs.so.0")]
    static extern string guestfs_dmesg (IntPtr h);

    /// <summary>
    /// return kernel messages
    /// </summary>
    public string dmesg ()
    {
      string r;
      r = guestfs_dmesg (_handle);
      if (r == null)
        throw new Error (guestfs_last_error (_handle));
      return r;
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_download (IntPtr h, [In] string remotefilename, [In] string filename);

    /// <summary>
    /// download a file to the local machine
    /// </summary>
    public void download (string remotefilename, string filename)
    {
      int r;
      r = guestfs_download (_handle, remotefilename, filename);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_download_offset (IntPtr h, [In] string remotefilename, [In] string filename, long offset, long size);

    /// <summary>
    /// download a file to the local machine with offset and size
    /// </summary>
    public void download_offset (string remotefilename, string filename, long offset, long size)
    {
      int r;
      r = guestfs_download_offset (_handle, remotefilename, filename, offset, size);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_drop_caches (IntPtr h, int whattodrop);

    /// <summary>
    /// drop kernel page cache, dentries and inodes
    /// </summary>
    public void drop_caches (int whattodrop)
    {
      int r;
      r = guestfs_drop_caches (_handle, whattodrop);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern long guestfs_du (IntPtr h, [In] string path);

    /// <summary>
    /// estimate file space usage
    /// </summary>
    public long du (string path)
    {
      long r;
      r = guestfs_du (_handle, path);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
      return r;
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_e2fsck_argv (IntPtr h, [In] string device, void *);

    /// <summary>
    /// check an ext2/ext3 filesystem
    /// </summary>
    public void e2fsck (string device)
    {
      int r;
      r = guestfs_e2fsck_argv (_handle, device, NULL);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_e2fsck_f (IntPtr h, [In] string device);

    /// <summary>
    /// check an ext2/ext3 filesystem
    /// </summary>
    public void e2fsck_f (string device)
    {
      int r;
      r = guestfs_e2fsck_f (_handle, device);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern string guestfs_echo_daemon (IntPtr h, [In] string[] words);

    /// <summary>
    /// echo arguments back to the client
    /// </summary>
    public string echo_daemon (string[] words)
    {
      string r;
      r = guestfs_echo_daemon (_handle, words);
      if (r == null)
        throw new Error (guestfs_last_error (_handle));
      return r;
    }

    [DllImport ("libguestfs.so.0")]
    static extern string[] guestfs_egrep (IntPtr h, [In] string regex, [In] string path);

    /// <summary>
    /// return lines matching a pattern
    /// </summary>
    public string[] egrep (string regex, string path)
    {
      string[] r;
      r = guestfs_egrep (_handle, regex, path);
      if (r == null)
        throw new Error (guestfs_last_error (_handle));
      return r;
    }

    [DllImport ("libguestfs.so.0")]
    static extern string[] guestfs_egrepi (IntPtr h, [In] string regex, [In] string path);

    /// <summary>
    /// return lines matching a pattern
    /// </summary>
    public string[] egrepi (string regex, string path)
    {
      string[] r;
      r = guestfs_egrepi (_handle, regex, path);
      if (r == null)
        throw new Error (guestfs_last_error (_handle));
      return r;
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_equal (IntPtr h, [In] string file1, [In] string file2);

    /// <summary>
    /// test if two files have equal contents
    /// </summary>
    public bool equal (string file1, string file2)
    {
      int r;
      r = guestfs_equal (_handle, file1, file2);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
      return r != 0 ? true : false;
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_exists (IntPtr h, [In] string path);

    /// <summary>
    /// test if file or directory exists
    /// </summary>
    public bool exists (string path)
    {
      int r;
      r = guestfs_exists (_handle, path);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
      return r != 0 ? true : false;
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_extlinux (IntPtr h, [In] string directory);

    /// <summary>
    /// install the SYSLINUX bootloader on an ext2/3/4 or btrfs filesystem
    /// </summary>
    public void extlinux (string directory)
    {
      int r;
      r = guestfs_extlinux (_handle, directory);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_fallocate (IntPtr h, [In] string path, int len);

    /// <summary>
    /// preallocate a file in the guest filesystem
    /// </summary>
    public void fallocate (string path, int len)
    {
      int r;
      r = guestfs_fallocate (_handle, path, len);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_fallocate64 (IntPtr h, [In] string path, long len);

    /// <summary>
    /// preallocate a file in the guest filesystem
    /// </summary>
    public void fallocate64 (string path, long len)
    {
      int r;
      r = guestfs_fallocate64 (_handle, path, len);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_feature_available (IntPtr h, [In] string[] groups);

    /// <summary>
    /// test availability of some parts of the API
    /// </summary>
    public bool feature_available (string[] groups)
    {
      int r;
      r = guestfs_feature_available (_handle, groups);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
      return r != 0 ? true : false;
    }

    [DllImport ("libguestfs.so.0")]
    static extern string[] guestfs_fgrep (IntPtr h, [In] string pattern, [In] string path);

    /// <summary>
    /// return lines matching a pattern
    /// </summary>
    public string[] fgrep (string pattern, string path)
    {
      string[] r;
      r = guestfs_fgrep (_handle, pattern, path);
      if (r == null)
        throw new Error (guestfs_last_error (_handle));
      return r;
    }

    [DllImport ("libguestfs.so.0")]
    static extern string[] guestfs_fgrepi (IntPtr h, [In] string pattern, [In] string path);

    /// <summary>
    /// return lines matching a pattern
    /// </summary>
    public string[] fgrepi (string pattern, string path)
    {
      string[] r;
      r = guestfs_fgrepi (_handle, pattern, path);
      if (r == null)
        throw new Error (guestfs_last_error (_handle));
      return r;
    }

    [DllImport ("libguestfs.so.0")]
    static extern string guestfs_file (IntPtr h, [In] string path);

    /// <summary>
    /// determine file type
    /// </summary>
    public string file (string path)
    {
      string r;
      r = guestfs_file (_handle, path);
      if (r == null)
        throw new Error (guestfs_last_error (_handle));
      return r;
    }

    [DllImport ("libguestfs.so.0")]
    static extern string guestfs_file_architecture (IntPtr h, [In] string filename);

    /// <summary>
    /// detect the architecture of a binary file
    /// </summary>
    public string file_architecture (string filename)
    {
      string r;
      r = guestfs_file_architecture (_handle, filename);
      if (r == null)
        throw new Error (guestfs_last_error (_handle));
      return r;
    }

    [DllImport ("libguestfs.so.0")]
    static extern long guestfs_filesize (IntPtr h, [In] string file);

    /// <summary>
    /// return the size of the file in bytes
    /// </summary>
    public long filesize (string file)
    {
      long r;
      r = guestfs_filesize (_handle, file);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
      return r;
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_filesystem_available (IntPtr h, [In] string filesystem);

    /// <summary>
    /// check if filesystem is available
    /// </summary>
    public bool filesystem_available (string filesystem)
    {
      int r;
      r = guestfs_filesystem_available (_handle, filesystem);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
      return r != 0 ? true : false;
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_fill (IntPtr h, int c, int len, [In] string path);

    /// <summary>
    /// fill a file with octets
    /// </summary>
    public void fill (int c, int len, string path)
    {
      int r;
      r = guestfs_fill (_handle, c, len, path);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_fill_dir (IntPtr h, [In] string dir, int nr);

    /// <summary>
    /// fill a directory with empty files
    /// </summary>
    public void fill_dir (string dir, int nr)
    {
      int r;
      r = guestfs_fill_dir (_handle, dir, nr);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_fill_pattern (IntPtr h, [In] string pattern, int len, [In] string path);

    /// <summary>
    /// fill a file with a repeating pattern of bytes
    /// </summary>
    public void fill_pattern (string pattern, int len, string path)
    {
      int r;
      r = guestfs_fill_pattern (_handle, pattern, len, path);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern string[] guestfs_find (IntPtr h, [In] string directory);

    /// <summary>
    /// find all files and directories
    /// </summary>
    public string[] find (string directory)
    {
      string[] r;
      r = guestfs_find (_handle, directory);
      if (r == null)
        throw new Error (guestfs_last_error (_handle));
      return r;
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_find0 (IntPtr h, [In] string directory, [In] string files);

    /// <summary>
    /// find all files and directories, returning NUL-separated list
    /// </summary>
    public void find0 (string directory, string files)
    {
      int r;
      r = guestfs_find0 (_handle, directory, files);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern string guestfs_findfs_label (IntPtr h, [In] string label);

    /// <summary>
    /// find a filesystem by label
    /// </summary>
    public string findfs_label (string label)
    {
      string r;
      r = guestfs_findfs_label (_handle, label);
      if (r == null)
        throw new Error (guestfs_last_error (_handle));
      return r;
    }

    [DllImport ("libguestfs.so.0")]
    static extern string guestfs_findfs_uuid (IntPtr h, [In] string uuid);

    /// <summary>
    /// find a filesystem by UUID
    /// </summary>
    public string findfs_uuid (string uuid)
    {
      string r;
      r = guestfs_findfs_uuid (_handle, uuid);
      if (r == null)
        throw new Error (guestfs_last_error (_handle));
      return r;
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_fsck (IntPtr h, [In] string fstype, [In] string device);

    /// <summary>
    /// run the filesystem checker
    /// </summary>
    public int fsck (string fstype, string device)
    {
      int r;
      r = guestfs_fsck (_handle, fstype, device);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
      return r;
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_fstrim_argv (IntPtr h, [In] string mountpoint, void *);

    /// <summary>
    /// trim free space in a filesystem
    /// </summary>
    public void fstrim (string mountpoint)
    {
      int r;
      r = guestfs_fstrim_argv (_handle, mountpoint, NULL);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern string guestfs_get_append (IntPtr h);

    /// <summary>
    /// get the additional kernel options
    /// </summary>
    public string get_append ()
    {
      string r;
      r = guestfs_get_append (_handle);
      if (r == null)
        throw new Error (guestfs_last_error (_handle));
      return r;
    }

    [DllImport ("libguestfs.so.0")]
    static extern string guestfs_get_attach_method (IntPtr h);

    /// <summary>
    /// get the backend
    /// </summary>
    public string get_attach_method ()
    {
      string r;
      r = guestfs_get_attach_method (_handle);
      if (r == null)
        throw new Error (guestfs_last_error (_handle));
      return r;
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_get_autosync (IntPtr h);

    /// <summary>
    /// get autosync mode
    /// </summary>
    public bool get_autosync ()
    {
      int r;
      r = guestfs_get_autosync (_handle);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
      return r != 0 ? true : false;
    }

    [DllImport ("libguestfs.so.0")]
    static extern string guestfs_get_backend (IntPtr h);

    /// <summary>
    /// get the backend
    /// </summary>
    public string get_backend ()
    {
      string r;
      r = guestfs_get_backend (_handle);
      if (r == null)
        throw new Error (guestfs_last_error (_handle));
      return r;
    }

    [DllImport ("libguestfs.so.0")]
    static extern string guestfs_get_backend_setting (IntPtr h, [In] string name);

    /// <summary>
    /// get a single per-backend settings string
    /// </summary>
    public string get_backend_setting (string name)
    {
      string r;
      r = guestfs_get_backend_setting (_handle, name);
      if (r == null)
        throw new Error (guestfs_last_error (_handle));
      return r;
    }

    [DllImport ("libguestfs.so.0")]
    static extern string[] guestfs_get_backend_settings (IntPtr h);

    /// <summary>
    /// get per-backend settings
    /// </summary>
    public string[] get_backend_settings ()
    {
      string[] r;
      r = guestfs_get_backend_settings (_handle);
      if (r == null)
        throw new Error (guestfs_last_error (_handle));
      return r;
    }

    [DllImport ("libguestfs.so.0")]
    static extern string guestfs_get_cachedir (IntPtr h);

    /// <summary>
    /// get the appliance cache directory
    /// </summary>
    public string get_cachedir ()
    {
      string r;
      r = guestfs_get_cachedir (_handle);
      if (r == null)
        throw new Error (guestfs_last_error (_handle));
      return r;
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_get_direct (IntPtr h);

    /// <summary>
    /// get direct appliance mode flag
    /// </summary>
    public bool get_direct ()
    {
      int r;
      r = guestfs_get_direct (_handle);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
      return r != 0 ? true : false;
    }

    [DllImport ("libguestfs.so.0")]
    static extern string guestfs_get_e2attrs (IntPtr h, [In] string file);

    /// <summary>
    /// get ext2 file attributes of a file
    /// </summary>
    public string get_e2attrs (string file)
    {
      string r;
      r = guestfs_get_e2attrs (_handle, file);
      if (r == null)
        throw new Error (guestfs_last_error (_handle));
      return r;
    }

    [DllImport ("libguestfs.so.0")]
    static extern long guestfs_get_e2generation (IntPtr h, [In] string file);

    /// <summary>
    /// get ext2 file generation of a file
    /// </summary>
    public long get_e2generation (string file)
    {
      long r;
      r = guestfs_get_e2generation (_handle, file);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
      return r;
    }

    [DllImport ("libguestfs.so.0")]
    static extern string guestfs_get_e2label (IntPtr h, [In] string device);

    /// <summary>
    /// get the ext2/3/4 filesystem label
    /// </summary>
    public string get_e2label (string device)
    {
      string r;
      r = guestfs_get_e2label (_handle, device);
      if (r == null)
        throw new Error (guestfs_last_error (_handle));
      return r;
    }

    [DllImport ("libguestfs.so.0")]
    static extern string guestfs_get_e2uuid (IntPtr h, [In] string device);

    /// <summary>
    /// get the ext2/3/4 filesystem UUID
    /// </summary>
    public string get_e2uuid (string device)
    {
      string r;
      r = guestfs_get_e2uuid (_handle, device);
      if (r == null)
        throw new Error (guestfs_last_error (_handle));
      return r;
    }

    [DllImport ("libguestfs.so.0")]
    static extern string guestfs_get_hv (IntPtr h);

    /// <summary>
    /// get the hypervisor binary
    /// </summary>
    public string get_hv ()
    {
      string r;
      r = guestfs_get_hv (_handle);
      if (r == null)
        throw new Error (guestfs_last_error (_handle));
      return r;
    }

    [DllImport ("libguestfs.so.0")]
    static extern string guestfs_get_libvirt_requested_credential_challenge (IntPtr h, int index);

    /// <summary>
    /// challenge of i'th requested credential
    /// </summary>
    public string get_libvirt_requested_credential_challenge (int index)
    {
      string r;
      r = guestfs_get_libvirt_requested_credential_challenge (_handle, index);
      if (r == null)
        throw new Error (guestfs_last_error (_handle));
      return r;
    }

    [DllImport ("libguestfs.so.0")]
    static extern string guestfs_get_libvirt_requested_credential_defresult (IntPtr h, int index);

    /// <summary>
    /// default result of i'th requested credential
    /// </summary>
    public string get_libvirt_requested_credential_defresult (int index)
    {
      string r;
      r = guestfs_get_libvirt_requested_credential_defresult (_handle, index);
      if (r == null)
        throw new Error (guestfs_last_error (_handle));
      return r;
    }

    [DllImport ("libguestfs.so.0")]
    static extern string guestfs_get_libvirt_requested_credential_prompt (IntPtr h, int index);

    /// <summary>
    /// prompt of i'th requested credential
    /// </summary>
    public string get_libvirt_requested_credential_prompt (int index)
    {
      string r;
      r = guestfs_get_libvirt_requested_credential_prompt (_handle, index);
      if (r == null)
        throw new Error (guestfs_last_error (_handle));
      return r;
    }

    [DllImport ("libguestfs.so.0")]
    static extern string[] guestfs_get_libvirt_requested_credentials (IntPtr h);

    /// <summary>
    /// get list of credentials requested by libvirt
    /// </summary>
    public string[] get_libvirt_requested_credentials ()
    {
      string[] r;
      r = guestfs_get_libvirt_requested_credentials (_handle);
      if (r == null)
        throw new Error (guestfs_last_error (_handle));
      return r;
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_get_memsize (IntPtr h);

    /// <summary>
    /// get memory allocated to the hypervisor
    /// </summary>
    public int get_memsize ()
    {
      int r;
      r = guestfs_get_memsize (_handle);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
      return r;
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_get_network (IntPtr h);

    /// <summary>
    /// get enable network flag
    /// </summary>
    public bool get_network ()
    {
      int r;
      r = guestfs_get_network (_handle);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
      return r != 0 ? true : false;
    }

    [DllImport ("libguestfs.so.0")]
    static extern string guestfs_get_path (IntPtr h);

    /// <summary>
    /// get the search path
    /// </summary>
    public string get_path ()
    {
      string r;
      r = guestfs_get_path (_handle);
      if (r == null)
        throw new Error (guestfs_last_error (_handle));
      return r;
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_get_pgroup (IntPtr h);

    /// <summary>
    /// get process group flag
    /// </summary>
    public bool get_pgroup ()
    {
      int r;
      r = guestfs_get_pgroup (_handle);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
      return r != 0 ? true : false;
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_get_pid (IntPtr h);

    /// <summary>
    /// get PID of hypervisor
    /// </summary>
    public int get_pid ()
    {
      int r;
      r = guestfs_get_pid (_handle);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
      return r;
    }

    [DllImport ("libguestfs.so.0")]
    static extern string guestfs_get_program (IntPtr h);

    /// <summary>
    /// get the program name
    /// </summary>
    public string get_program ()
    {
      string r;
      r = guestfs_get_program (_handle);
      if (r == null)
        throw new Error (guestfs_last_error (_handle));
      return r;
    }

    [DllImport ("libguestfs.so.0")]
    static extern string guestfs_get_qemu (IntPtr h);

    /// <summary>
    /// get the hypervisor binary (usually qemu)
    /// </summary>
    public string get_qemu ()
    {
      string r;
      r = guestfs_get_qemu (_handle);
      if (r == null)
        throw new Error (guestfs_last_error (_handle));
      return r;
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_get_recovery_proc (IntPtr h);

    /// <summary>
    /// get recovery process enabled flag
    /// </summary>
    public bool get_recovery_proc ()
    {
      int r;
      r = guestfs_get_recovery_proc (_handle);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
      return r != 0 ? true : false;
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_get_selinux (IntPtr h);

    /// <summary>
    /// get SELinux enabled flag
    /// </summary>
    public bool get_selinux ()
    {
      int r;
      r = guestfs_get_selinux (_handle);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
      return r != 0 ? true : false;
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_get_smp (IntPtr h);

    /// <summary>
    /// get number of virtual CPUs in appliance
    /// </summary>
    public int get_smp ()
    {
      int r;
      r = guestfs_get_smp (_handle);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
      return r;
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_get_state (IntPtr h);

    /// <summary>
    /// get the current state
    /// </summary>
    public int get_state ()
    {
      int r;
      r = guestfs_get_state (_handle);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
      return r;
    }

    [DllImport ("libguestfs.so.0")]
    static extern string guestfs_get_tmpdir (IntPtr h);

    /// <summary>
    /// get the temporary directory
    /// </summary>
    public string get_tmpdir ()
    {
      string r;
      r = guestfs_get_tmpdir (_handle);
      if (r == null)
        throw new Error (guestfs_last_error (_handle));
      return r;
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_get_trace (IntPtr h);

    /// <summary>
    /// get command trace enabled flag
    /// </summary>
    public bool get_trace ()
    {
      int r;
      r = guestfs_get_trace (_handle);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
      return r != 0 ? true : false;
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_get_umask (IntPtr h);

    /// <summary>
    /// get the current umask
    /// </summary>
    public int get_umask ()
    {
      int r;
      r = guestfs_get_umask (_handle);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
      return r;
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_get_verbose (IntPtr h);

    /// <summary>
    /// get verbose mode
    /// </summary>
    public bool get_verbose ()
    {
      int r;
      r = guestfs_get_verbose (_handle);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
      return r != 0 ? true : false;
    }

    [DllImport ("libguestfs.so.0")]
    static extern string guestfs_getcon (IntPtr h);

    /// <summary>
    /// get SELinux security context
    /// </summary>
    public string getcon ()
    {
      string r;
      r = guestfs_getcon (_handle);
      if (r == null)
        throw new Error (guestfs_last_error (_handle));
      return r;
    }

    [DllImport ("libguestfs.so.0")]
    static extern string guestfs_getxattr (IntPtr h, [In] string path, [In] string name);

    /// <summary>
    /// get a single extended attribute
    /// </summary>
    public string getxattr (string path, string name)
    {
      string r;
      r = guestfs_getxattr (_handle, path, name);
      if (r == null)
        throw new Error (guestfs_last_error (_handle));
      return r;
    }

    [DllImport ("libguestfs.so.0")]
    static extern _xattr[] guestfs_getxattrs (IntPtr h, [In] string path);

    /// <summary>
    /// list extended attributes of a file or directory
    /// </summary>
    public _xattr[] getxattrs (string path)
    {
      _xattr[] r;
      r = guestfs_getxattrs (_handle, path);
      if (r == null)
        throw new Error (guestfs_last_error (_handle));
      return r;
    }

    [DllImport ("libguestfs.so.0")]
    static extern string[] guestfs_glob_expand (IntPtr h, [In] string pattern);

    /// <summary>
    /// expand a wildcard path
    /// </summary>
    public string[] glob_expand (string pattern)
    {
      string[] r;
      r = guestfs_glob_expand (_handle, pattern);
      if (r == null)
        throw new Error (guestfs_last_error (_handle));
      return r;
    }

    [DllImport ("libguestfs.so.0")]
    static extern string[] guestfs_grep_opts_argv (IntPtr h, [In] string regex, [In] string path, void *);

    /// <summary>
    /// return lines matching a pattern
    /// </summary>
    public string[] grep (string regex, string path)
    {
      string[] r;
      r = guestfs_grep_opts_argv (_handle, regex, path, NULL);
      if (r == null)
        throw new Error (guestfs_last_error (_handle));
      return r;
    }

    public string[] grep_opts (string regex, string path)
    {
      return grep (regex, path);
    }

    [DllImport ("libguestfs.so.0")]
    static extern string[] guestfs_grepi (IntPtr h, [In] string regex, [In] string path);

    /// <summary>
    /// return lines matching a pattern
    /// </summary>
    public string[] grepi (string regex, string path)
    {
      string[] r;
      r = guestfs_grepi (_handle, regex, path);
      if (r == null)
        throw new Error (guestfs_last_error (_handle));
      return r;
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_grub_install (IntPtr h, [In] string root, [In] string device);

    /// <summary>
    /// install GRUB 1
    /// </summary>
    public void grub_install (string root, string device)
    {
      int r;
      r = guestfs_grub_install (_handle, root, device);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern string[] guestfs_head (IntPtr h, [In] string path);

    /// <summary>
    /// return first 10 lines of a file
    /// </summary>
    public string[] head (string path)
    {
      string[] r;
      r = guestfs_head (_handle, path);
      if (r == null)
        throw new Error (guestfs_last_error (_handle));
      return r;
    }

    [DllImport ("libguestfs.so.0")]
    static extern string[] guestfs_head_n (IntPtr h, int nrlines, [In] string path);

    /// <summary>
    /// return first N lines of a file
    /// </summary>
    public string[] head_n (int nrlines, string path)
    {
      string[] r;
      r = guestfs_head_n (_handle, nrlines, path);
      if (r == null)
        throw new Error (guestfs_last_error (_handle));
      return r;
    }

    [DllImport ("libguestfs.so.0")]
    static extern string guestfs_hexdump (IntPtr h, [In] string path);

    /// <summary>
    /// dump a file in hexadecimal
    /// </summary>
    public string hexdump (string path)
    {
      string r;
      r = guestfs_hexdump (_handle, path);
      if (r == null)
        throw new Error (guestfs_last_error (_handle));
      return r;
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_hivex_close (IntPtr h);

    /// <summary>
    /// close the current hivex handle
    /// </summary>
    public void hivex_close ()
    {
      int r;
      r = guestfs_hivex_close (_handle);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_hivex_commit (IntPtr h, [In] string filename);

    /// <summary>
    /// commit (write) changes back to the hive
    /// </summary>
    public void hivex_commit (string filename)
    {
      int r;
      r = guestfs_hivex_commit (_handle, filename);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern long guestfs_hivex_node_add_child (IntPtr h, long parent, [In] string name);

    /// <summary>
    /// add a child node
    /// </summary>
    public long hivex_node_add_child (long parent, string name)
    {
      long r;
      r = guestfs_hivex_node_add_child (_handle, parent, name);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
      return r;
    }

    [DllImport ("libguestfs.so.0")]
    static extern _hivex_node[] guestfs_hivex_node_children (IntPtr h, long nodeh);

    /// <summary>
    /// return list of nodes which are subkeys of node
    /// </summary>
    public _hivex_node[] hivex_node_children (long nodeh)
    {
      _hivex_node[] r;
      r = guestfs_hivex_node_children (_handle, nodeh);
      if (r == null)
        throw new Error (guestfs_last_error (_handle));
      return r;
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_hivex_node_delete_child (IntPtr h, long nodeh);

    /// <summary>
    /// delete a node (recursively)
    /// </summary>
    public void hivex_node_delete_child (long nodeh)
    {
      int r;
      r = guestfs_hivex_node_delete_child (_handle, nodeh);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern long guestfs_hivex_node_get_child (IntPtr h, long nodeh, [In] string name);

    /// <summary>
    /// return the named child of node
    /// </summary>
    public long hivex_node_get_child (long nodeh, string name)
    {
      long r;
      r = guestfs_hivex_node_get_child (_handle, nodeh, name);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
      return r;
    }

    [DllImport ("libguestfs.so.0")]
    static extern long guestfs_hivex_node_get_value (IntPtr h, long nodeh, [In] string key);

    /// <summary>
    /// return the named value
    /// </summary>
    public long hivex_node_get_value (long nodeh, string key)
    {
      long r;
      r = guestfs_hivex_node_get_value (_handle, nodeh, key);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
      return r;
    }

    [DllImport ("libguestfs.so.0")]
    static extern string guestfs_hivex_node_name (IntPtr h, long nodeh);

    /// <summary>
    /// return the name of the node
    /// </summary>
    public string hivex_node_name (long nodeh)
    {
      string r;
      r = guestfs_hivex_node_name (_handle, nodeh);
      if (r == null)
        throw new Error (guestfs_last_error (_handle));
      return r;
    }

    [DllImport ("libguestfs.so.0")]
    static extern long guestfs_hivex_node_parent (IntPtr h, long nodeh);

    /// <summary>
    /// return the parent of node
    /// </summary>
    public long hivex_node_parent (long nodeh)
    {
      long r;
      r = guestfs_hivex_node_parent (_handle, nodeh);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
      return r;
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_hivex_node_set_value (IntPtr h, long nodeh, [In] string key, long t, [In] string val);

    /// <summary>
    /// set or replace a single value in a node
    /// </summary>
    public void hivex_node_set_value (long nodeh, string key, long t, string val)
    {
      int r;
      r = guestfs_hivex_node_set_value (_handle, nodeh, key, t, val);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern _hivex_value[] guestfs_hivex_node_values (IntPtr h, long nodeh);

    /// <summary>
    /// return list of values attached to node
    /// </summary>
    public _hivex_value[] hivex_node_values (long nodeh)
    {
      _hivex_value[] r;
      r = guestfs_hivex_node_values (_handle, nodeh);
      if (r == null)
        throw new Error (guestfs_last_error (_handle));
      return r;
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_hivex_open_argv (IntPtr h, [In] string filename, void *);

    /// <summary>
    /// open a Windows Registry hive file
    /// </summary>
    public void hivex_open (string filename)
    {
      int r;
      r = guestfs_hivex_open_argv (_handle, filename, NULL);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern long guestfs_hivex_root (IntPtr h);

    /// <summary>
    /// return the root node of the hive
    /// </summary>
    public long hivex_root ()
    {
      long r;
      r = guestfs_hivex_root (_handle);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
      return r;
    }

    [DllImport ("libguestfs.so.0")]
    static extern string guestfs_hivex_value_key (IntPtr h, long valueh);

    /// <summary>
    /// return the key field from the (key, datatype, data) tuple
    /// </summary>
    public string hivex_value_key (long valueh)
    {
      string r;
      r = guestfs_hivex_value_key (_handle, valueh);
      if (r == null)
        throw new Error (guestfs_last_error (_handle));
      return r;
    }

    [DllImport ("libguestfs.so.0")]
    static extern long guestfs_hivex_value_type (IntPtr h, long valueh);

    /// <summary>
    /// return the data type from the (key, datatype, data) tuple
    /// </summary>
    public long hivex_value_type (long valueh)
    {
      long r;
      r = guestfs_hivex_value_type (_handle, valueh);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
      return r;
    }

    [DllImport ("libguestfs.so.0")]
    static extern string guestfs_hivex_value_utf8 (IntPtr h, long valueh);

    /// <summary>
    /// return the data field from the (key, datatype, data) tuple
    /// </summary>
    public string hivex_value_utf8 (long valueh)
    {
      string r;
      r = guestfs_hivex_value_utf8 (_handle, valueh);
      if (r == null)
        throw new Error (guestfs_last_error (_handle));
      return r;
    }

    [DllImport ("libguestfs.so.0")]
    static extern string guestfs_hivex_value_value (IntPtr h, long valueh);

    /// <summary>
    /// return the data field from the (key, datatype, data) tuple
    /// </summary>
    public string hivex_value_value (long valueh)
    {
      string r;
      r = guestfs_hivex_value_value (_handle, valueh);
      if (r == null)
        throw new Error (guestfs_last_error (_handle));
      return r;
    }

    [DllImport ("libguestfs.so.0")]
    static extern string guestfs_initrd_cat (IntPtr h, [In] string initrdpath, [In] string filename);

    /// <summary>
    /// list the contents of a single file in an initrd
    /// </summary>
    public string initrd_cat (string initrdpath, string filename)
    {
      string r;
      r = guestfs_initrd_cat (_handle, initrdpath, filename);
      if (r == null)
        throw new Error (guestfs_last_error (_handle));
      return r;
    }

    [DllImport ("libguestfs.so.0")]
    static extern string[] guestfs_initrd_list (IntPtr h, [In] string path);

    /// <summary>
    /// list files in an initrd
    /// </summary>
    public string[] initrd_list (string path)
    {
      string[] r;
      r = guestfs_initrd_list (_handle, path);
      if (r == null)
        throw new Error (guestfs_last_error (_handle));
      return r;
    }

    [DllImport ("libguestfs.so.0")]
    static extern long guestfs_inotify_add_watch (IntPtr h, [In] string path, int mask);

    /// <summary>
    /// add an inotify watch
    /// </summary>
    public long inotify_add_watch (string path, int mask)
    {
      long r;
      r = guestfs_inotify_add_watch (_handle, path, mask);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
      return r;
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_inotify_close (IntPtr h);

    /// <summary>
    /// close the inotify handle
    /// </summary>
    public void inotify_close ()
    {
      int r;
      r = guestfs_inotify_close (_handle);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern string[] guestfs_inotify_files (IntPtr h);

    /// <summary>
    /// return list of watched files that had events
    /// </summary>
    public string[] inotify_files ()
    {
      string[] r;
      r = guestfs_inotify_files (_handle);
      if (r == null)
        throw new Error (guestfs_last_error (_handle));
      return r;
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_inotify_init (IntPtr h, int maxevents);

    /// <summary>
    /// create an inotify handle
    /// </summary>
    public void inotify_init (int maxevents)
    {
      int r;
      r = guestfs_inotify_init (_handle, maxevents);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern _inotify_event[] guestfs_inotify_read (IntPtr h);

    /// <summary>
    /// return list of inotify events
    /// </summary>
    public _inotify_event[] inotify_read ()
    {
      _inotify_event[] r;
      r = guestfs_inotify_read (_handle);
      if (r == null)
        throw new Error (guestfs_last_error (_handle));
      return r;
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_inotify_rm_watch (IntPtr h, int wd);

    /// <summary>
    /// remove an inotify watch
    /// </summary>
    public void inotify_rm_watch (int wd)
    {
      int r;
      r = guestfs_inotify_rm_watch (_handle, wd);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern string guestfs_inspect_get_arch (IntPtr h, [In] string root);

    /// <summary>
    /// get architecture of inspected operating system
    /// </summary>
    public string inspect_get_arch (string root)
    {
      string r;
      r = guestfs_inspect_get_arch (_handle, root);
      if (r == null)
        throw new Error (guestfs_last_error (_handle));
      return r;
    }

    [DllImport ("libguestfs.so.0")]
    static extern string guestfs_inspect_get_distro (IntPtr h, [In] string root);

    /// <summary>
    /// get distro of inspected operating system
    /// </summary>
    public string inspect_get_distro (string root)
    {
      string r;
      r = guestfs_inspect_get_distro (_handle, root);
      if (r == null)
        throw new Error (guestfs_last_error (_handle));
      return r;
    }

    [DllImport ("libguestfs.so.0")]
    static extern string[] guestfs_inspect_get_drive_mappings (IntPtr h, [In] string root);

    /// <summary>
    /// get drive letter mappings
    /// </summary>
    public Hashtable inspect_get_drive_mappings (string root)
    {
      string[] r;
      r = guestfs_inspect_get_drive_mappings (_handle, root);
      if (r == null)
        throw new Error (guestfs_last_error (_handle));
      Hashtable rr = new Hashtable ();
      for (size_t i = 0; i < r.Length; i += 2)
        rr.Add (r[i], r[i+1]);
      return rr;
    }

    [DllImport ("libguestfs.so.0")]
    static extern string[] guestfs_inspect_get_filesystems (IntPtr h, [In] string root);

    /// <summary>
    /// get filesystems associated with inspected operating system
    /// </summary>
    public string[] inspect_get_filesystems (string root)
    {
      string[] r;
      r = guestfs_inspect_get_filesystems (_handle, root);
      if (r == null)
        throw new Error (guestfs_last_error (_handle));
      return r;
    }

    [DllImport ("libguestfs.so.0")]
    static extern string guestfs_inspect_get_format (IntPtr h, [In] string root);

    /// <summary>
    /// get format of inspected operating system
    /// </summary>
    public string inspect_get_format (string root)
    {
      string r;
      r = guestfs_inspect_get_format (_handle, root);
      if (r == null)
        throw new Error (guestfs_last_error (_handle));
      return r;
    }

    [DllImport ("libguestfs.so.0")]
    static extern string guestfs_inspect_get_hostname (IntPtr h, [In] string root);

    /// <summary>
    /// get hostname of the operating system
    /// </summary>
    public string inspect_get_hostname (string root)
    {
      string r;
      r = guestfs_inspect_get_hostname (_handle, root);
      if (r == null)
        throw new Error (guestfs_last_error (_handle));
      return r;
    }

    [DllImport ("libguestfs.so.0")]
    static extern string guestfs_inspect_get_icon_argv (IntPtr h, [In] string root, void *);

    /// <summary>
    /// get the icon corresponding to this operating system
    /// </summary>
    public string inspect_get_icon (string root)
    {
      string r;
      r = guestfs_inspect_get_icon_argv (_handle, root, NULL);
      if (r == null)
        throw new Error (guestfs_last_error (_handle));
      return r;
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_inspect_get_major_version (IntPtr h, [In] string root);

    /// <summary>
    /// get major version of inspected operating system
    /// </summary>
    public int inspect_get_major_version (string root)
    {
      int r;
      r = guestfs_inspect_get_major_version (_handle, root);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
      return r;
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_inspect_get_minor_version (IntPtr h, [In] string root);

    /// <summary>
    /// get minor version of inspected operating system
    /// </summary>
    public int inspect_get_minor_version (string root)
    {
      int r;
      r = guestfs_inspect_get_minor_version (_handle, root);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
      return r;
    }

    [DllImport ("libguestfs.so.0")]
    static extern string[] guestfs_inspect_get_mountpoints (IntPtr h, [In] string root);

    /// <summary>
    /// get mountpoints of inspected operating system
    /// </summary>
    public Hashtable inspect_get_mountpoints (string root)
    {
      string[] r;
      r = guestfs_inspect_get_mountpoints (_handle, root);
      if (r == null)
        throw new Error (guestfs_last_error (_handle));
      Hashtable rr = new Hashtable ();
      for (size_t i = 0; i < r.Length; i += 2)
        rr.Add (r[i], r[i+1]);
      return rr;
    }

    [DllImport ("libguestfs.so.0")]
    static extern string guestfs_inspect_get_package_format (IntPtr h, [In] string root);

    /// <summary>
    /// get package format used by the operating system
    /// </summary>
    public string inspect_get_package_format (string root)
    {
      string r;
      r = guestfs_inspect_get_package_format (_handle, root);
      if (r == null)
        throw new Error (guestfs_last_error (_handle));
      return r;
    }

    [DllImport ("libguestfs.so.0")]
    static extern string guestfs_inspect_get_package_management (IntPtr h, [In] string root);

    /// <summary>
    /// get package management tool used by the operating system
    /// </summary>
    public string inspect_get_package_management (string root)
    {
      string r;
      r = guestfs_inspect_get_package_management (_handle, root);
      if (r == null)
        throw new Error (guestfs_last_error (_handle));
      return r;
    }

    [DllImport ("libguestfs.so.0")]
    static extern string guestfs_inspect_get_product_name (IntPtr h, [In] string root);

    /// <summary>
    /// get product name of inspected operating system
    /// </summary>
    public string inspect_get_product_name (string root)
    {
      string r;
      r = guestfs_inspect_get_product_name (_handle, root);
      if (r == null)
        throw new Error (guestfs_last_error (_handle));
      return r;
    }

    [DllImport ("libguestfs.so.0")]
    static extern string guestfs_inspect_get_product_variant (IntPtr h, [In] string root);

    /// <summary>
    /// get product variant of inspected operating system
    /// </summary>
    public string inspect_get_product_variant (string root)
    {
      string r;
      r = guestfs_inspect_get_product_variant (_handle, root);
      if (r == null)
        throw new Error (guestfs_last_error (_handle));
      return r;
    }

    [DllImport ("libguestfs.so.0")]
    static extern string[] guestfs_inspect_get_roots (IntPtr h);

    /// <summary>
    /// return list of operating systems found by last inspection
    /// </summary>
    public string[] inspect_get_roots ()
    {
      string[] r;
      r = guestfs_inspect_get_roots (_handle);
      if (r == null)
        throw new Error (guestfs_last_error (_handle));
      return r;
    }

    [DllImport ("libguestfs.so.0")]
    static extern string guestfs_inspect_get_type (IntPtr h, [In] string root);

    /// <summary>
    /// get type of inspected operating system
    /// </summary>
    public string inspect_get_type (string root)
    {
      string r;
      r = guestfs_inspect_get_type (_handle, root);
      if (r == null)
        throw new Error (guestfs_last_error (_handle));
      return r;
    }

    [DllImport ("libguestfs.so.0")]
    static extern string guestfs_inspect_get_windows_current_control_set (IntPtr h, [In] string root);

    /// <summary>
    /// get Windows CurrentControlSet of inspected operating system
    /// </summary>
    public string inspect_get_windows_current_control_set (string root)
    {
      string r;
      r = guestfs_inspect_get_windows_current_control_set (_handle, root);
      if (r == null)
        throw new Error (guestfs_last_error (_handle));
      return r;
    }

    [DllImport ("libguestfs.so.0")]
    static extern string guestfs_inspect_get_windows_systemroot (IntPtr h, [In] string root);

    /// <summary>
    /// get Windows systemroot of inspected operating system
    /// </summary>
    public string inspect_get_windows_systemroot (string root)
    {
      string r;
      r = guestfs_inspect_get_windows_systemroot (_handle, root);
      if (r == null)
        throw new Error (guestfs_last_error (_handle));
      return r;
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_inspect_is_live (IntPtr h, [In] string root);

    /// <summary>
    /// get live flag for install disk
    /// </summary>
    public bool inspect_is_live (string root)
    {
      int r;
      r = guestfs_inspect_is_live (_handle, root);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
      return r != 0 ? true : false;
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_inspect_is_multipart (IntPtr h, [In] string root);

    /// <summary>
    /// get multipart flag for install disk
    /// </summary>
    public bool inspect_is_multipart (string root)
    {
      int r;
      r = guestfs_inspect_is_multipart (_handle, root);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
      return r != 0 ? true : false;
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_inspect_is_netinst (IntPtr h, [In] string root);

    /// <summary>
    /// get netinst (network installer) flag for install disk
    /// </summary>
    public bool inspect_is_netinst (string root)
    {
      int r;
      r = guestfs_inspect_is_netinst (_handle, root);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
      return r != 0 ? true : false;
    }

    [DllImport ("libguestfs.so.0")]
    static extern _application[] guestfs_inspect_list_applications (IntPtr h, [In] string root);

    /// <summary>
    /// get list of applications installed in the operating system
    /// </summary>
    public _application[] inspect_list_applications (string root)
    {
      _application[] r;
      r = guestfs_inspect_list_applications (_handle, root);
      if (r == null)
        throw new Error (guestfs_last_error (_handle));
      return r;
    }

    [DllImport ("libguestfs.so.0")]
    static extern _application2[] guestfs_inspect_list_applications2 (IntPtr h, [In] string root);

    /// <summary>
    /// get list of applications installed in the operating system
    /// </summary>
    public _application2[] inspect_list_applications2 (string root)
    {
      _application2[] r;
      r = guestfs_inspect_list_applications2 (_handle, root);
      if (r == null)
        throw new Error (guestfs_last_error (_handle));
      return r;
    }

    [DllImport ("libguestfs.so.0")]
    static extern string[] guestfs_inspect_os (IntPtr h);

    /// <summary>
    /// inspect disk and return list of operating systems found
    /// </summary>
    public string[] inspect_os ()
    {
      string[] r;
      r = guestfs_inspect_os (_handle);
      if (r == null)
        throw new Error (guestfs_last_error (_handle));
      return r;
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_internal_test_argv (IntPtr h, [In] string str, [In] string optstr, [In] string[] strlist, bool b, int integer, long integer64, [In] string filein, [In] string fileout, [In] string bufferin, void *);

    /// <summary>
    /// internal test function - do not use
    /// </summary>
    public void internal_test (string str, string optstr, string[] strlist, bool b, int integer, long integer64, string filein, string fileout, string bufferin)
    {
      int r;
      r = guestfs_internal_test_argv (_handle, str, optstr, strlist, b, integer, integer64, filein, fileout, bufferin, NULL);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_internal_test_63_optargs_argv (IntPtr h, void *);

    /// <summary>
    /// internal test function - do not use
    /// </summary>
    public void internal_test_63_optargs ()
    {
      int r;
      r = guestfs_internal_test_63_optargs_argv (_handle, NULL);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_internal_test_close_output (IntPtr h);

    /// <summary>
    /// internal test function - do not use
    /// </summary>
    public void internal_test_close_output ()
    {
      int r;
      r = guestfs_internal_test_close_output (_handle);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_internal_test_only_optargs_argv (IntPtr h, void *);

    /// <summary>
    /// internal test function - do not use
    /// </summary>
    public void internal_test_only_optargs ()
    {
      int r;
      r = guestfs_internal_test_only_optargs_argv (_handle, NULL);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_internal_test_rbool (IntPtr h, [In] string val);

    /// <summary>
    /// internal test function - do not use
    /// </summary>
    public bool internal_test_rbool (string val)
    {
      int r;
      r = guestfs_internal_test_rbool (_handle, val);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
      return r != 0 ? true : false;
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_internal_test_rboolerr (IntPtr h);

    /// <summary>
    /// internal test function - do not use
    /// </summary>
    public bool internal_test_rboolerr ()
    {
      int r;
      r = guestfs_internal_test_rboolerr (_handle);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
      return r != 0 ? true : false;
    }

    [DllImport ("libguestfs.so.0")]
    static extern string guestfs_internal_test_rbufferout (IntPtr h, [In] string val);

    /// <summary>
    /// internal test function - do not use
    /// </summary>
    public string internal_test_rbufferout (string val)
    {
      string r;
      r = guestfs_internal_test_rbufferout (_handle, val);
      if (r == null)
        throw new Error (guestfs_last_error (_handle));
      return r;
    }

    [DllImport ("libguestfs.so.0")]
    static extern string guestfs_internal_test_rbufferouterr (IntPtr h);

    /// <summary>
    /// internal test function - do not use
    /// </summary>
    public string internal_test_rbufferouterr ()
    {
      string r;
      r = guestfs_internal_test_rbufferouterr (_handle);
      if (r == null)
        throw new Error (guestfs_last_error (_handle));
      return r;
    }

    [DllImport ("libguestfs.so.0")]
    static extern string guestfs_internal_test_rconstoptstring (IntPtr h, [In] string val);

    /// <summary>
    /// internal test function - do not use
    /// </summary>
    public string internal_test_rconstoptstring (string val)
    {
      string r;
      r = guestfs_internal_test_rconstoptstring (_handle, val);
      if (r == null)
        throw new Error (guestfs_last_error (_handle));
      return r;
    }

    [DllImport ("libguestfs.so.0")]
    static extern string guestfs_internal_test_rconstoptstringerr (IntPtr h);

    /// <summary>
    /// internal test function - do not use
    /// </summary>
    public string internal_test_rconstoptstringerr ()
    {
      string r;
      r = guestfs_internal_test_rconstoptstringerr (_handle);
      if (r == null)
        throw new Error (guestfs_last_error (_handle));
      return r;
    }

    [DllImport ("libguestfs.so.0")]
    static extern string guestfs_internal_test_rconststring (IntPtr h, [In] string val);

    /// <summary>
    /// internal test function - do not use
    /// </summary>
    public string internal_test_rconststring (string val)
    {
      string r;
      r = guestfs_internal_test_rconststring (_handle, val);
      if (r == null)
        throw new Error (guestfs_last_error (_handle));
      return r;
    }

    [DllImport ("libguestfs.so.0")]
    static extern string guestfs_internal_test_rconststringerr (IntPtr h);

    /// <summary>
    /// internal test function - do not use
    /// </summary>
    public string internal_test_rconststringerr ()
    {
      string r;
      r = guestfs_internal_test_rconststringerr (_handle);
      if (r == null)
        throw new Error (guestfs_last_error (_handle));
      return r;
    }

    [DllImport ("libguestfs.so.0")]
    static extern string[] guestfs_internal_test_rhashtable (IntPtr h, [In] string val);

    /// <summary>
    /// internal test function - do not use
    /// </summary>
    public Hashtable internal_test_rhashtable (string val)
    {
      string[] r;
      r = guestfs_internal_test_rhashtable (_handle, val);
      if (r == null)
        throw new Error (guestfs_last_error (_handle));
      Hashtable rr = new Hashtable ();
      for (size_t i = 0; i < r.Length; i += 2)
        rr.Add (r[i], r[i+1]);
      return rr;
    }

    [DllImport ("libguestfs.so.0")]
    static extern string[] guestfs_internal_test_rhashtableerr (IntPtr h);

    /// <summary>
    /// internal test function - do not use
    /// </summary>
    public Hashtable internal_test_rhashtableerr ()
    {
      string[] r;
      r = guestfs_internal_test_rhashtableerr (_handle);
      if (r == null)
        throw new Error (guestfs_last_error (_handle));
      Hashtable rr = new Hashtable ();
      for (size_t i = 0; i < r.Length; i += 2)
        rr.Add (r[i], r[i+1]);
      return rr;
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_internal_test_rint (IntPtr h, [In] string val);

    /// <summary>
    /// internal test function - do not use
    /// </summary>
    public int internal_test_rint (string val)
    {
      int r;
      r = guestfs_internal_test_rint (_handle, val);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
      return r;
    }

    [DllImport ("libguestfs.so.0")]
    static extern long guestfs_internal_test_rint64 (IntPtr h, [In] string val);

    /// <summary>
    /// internal test function - do not use
    /// </summary>
    public long internal_test_rint64 (string val)
    {
      long r;
      r = guestfs_internal_test_rint64 (_handle, val);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
      return r;
    }

    [DllImport ("libguestfs.so.0")]
    static extern long guestfs_internal_test_rint64err (IntPtr h);

    /// <summary>
    /// internal test function - do not use
    /// </summary>
    public long internal_test_rint64err ()
    {
      long r;
      r = guestfs_internal_test_rint64err (_handle);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
      return r;
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_internal_test_rinterr (IntPtr h);

    /// <summary>
    /// internal test function - do not use
    /// </summary>
    public int internal_test_rinterr ()
    {
      int r;
      r = guestfs_internal_test_rinterr (_handle);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
      return r;
    }

    [DllImport ("libguestfs.so.0")]
    static extern string guestfs_internal_test_rstring (IntPtr h, [In] string val);

    /// <summary>
    /// internal test function - do not use
    /// </summary>
    public string internal_test_rstring (string val)
    {
      string r;
      r = guestfs_internal_test_rstring (_handle, val);
      if (r == null)
        throw new Error (guestfs_last_error (_handle));
      return r;
    }

    [DllImport ("libguestfs.so.0")]
    static extern string guestfs_internal_test_rstringerr (IntPtr h);

    /// <summary>
    /// internal test function - do not use
    /// </summary>
    public string internal_test_rstringerr ()
    {
      string r;
      r = guestfs_internal_test_rstringerr (_handle);
      if (r == null)
        throw new Error (guestfs_last_error (_handle));
      return r;
    }

    [DllImport ("libguestfs.so.0")]
    static extern string[] guestfs_internal_test_rstringlist (IntPtr h, [In] string val);

    /// <summary>
    /// internal test function - do not use
    /// </summary>
    public string[] internal_test_rstringlist (string val)
    {
      string[] r;
      r = guestfs_internal_test_rstringlist (_handle, val);
      if (r == null)
        throw new Error (guestfs_last_error (_handle));
      return r;
    }

    [DllImport ("libguestfs.so.0")]
    static extern string[] guestfs_internal_test_rstringlisterr (IntPtr h);

    /// <summary>
    /// internal test function - do not use
    /// </summary>
    public string[] internal_test_rstringlisterr ()
    {
      string[] r;
      r = guestfs_internal_test_rstringlisterr (_handle);
      if (r == null)
        throw new Error (guestfs_last_error (_handle));
      return r;
    }

    [DllImport ("libguestfs.so.0")]
    static extern _lvm_pv guestfs_internal_test_rstruct (IntPtr h, [In] string val);

    /// <summary>
    /// internal test function - do not use
    /// </summary>
    public _lvm_pv internal_test_rstruct (string val)
    {
      _lvm_pv r;
      r = guestfs_internal_test_rstruct (_handle, val);
      if (r == null)
        throw new Error (guestfs_last_error (_handle));
      return r;
    }

    [DllImport ("libguestfs.so.0")]
    static extern _lvm_pv guestfs_internal_test_rstructerr (IntPtr h);

    /// <summary>
    /// internal test function - do not use
    /// </summary>
    public _lvm_pv internal_test_rstructerr ()
    {
      _lvm_pv r;
      r = guestfs_internal_test_rstructerr (_handle);
      if (r == null)
        throw new Error (guestfs_last_error (_handle));
      return r;
    }

    [DllImport ("libguestfs.so.0")]
    static extern _lvm_pv[] guestfs_internal_test_rstructlist (IntPtr h, [In] string val);

    /// <summary>
    /// internal test function - do not use
    /// </summary>
    public _lvm_pv[] internal_test_rstructlist (string val)
    {
      _lvm_pv[] r;
      r = guestfs_internal_test_rstructlist (_handle, val);
      if (r == null)
        throw new Error (guestfs_last_error (_handle));
      return r;
    }

    [DllImport ("libguestfs.so.0")]
    static extern _lvm_pv[] guestfs_internal_test_rstructlisterr (IntPtr h);

    /// <summary>
    /// internal test function - do not use
    /// </summary>
    public _lvm_pv[] internal_test_rstructlisterr ()
    {
      _lvm_pv[] r;
      r = guestfs_internal_test_rstructlisterr (_handle);
      if (r == null)
        throw new Error (guestfs_last_error (_handle));
      return r;
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_internal_test_set_output (IntPtr h, [In] string filename);

    /// <summary>
    /// internal test function - do not use
    /// </summary>
    public void internal_test_set_output (string filename)
    {
      int r;
      r = guestfs_internal_test_set_output (_handle, filename);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_is_blockdev_opts_argv (IntPtr h, [In] string path, void *);

    /// <summary>
    /// test if block device
    /// </summary>
    public bool is_blockdev (string path)
    {
      int r;
      r = guestfs_is_blockdev_opts_argv (_handle, path, NULL);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
      return r != 0 ? true : false;
    }

    public bool is_blockdev_opts (string path)
    {
      return is_blockdev (path);
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_is_busy (IntPtr h);

    /// <summary>
    /// is busy processing a command
    /// </summary>
    public bool is_busy ()
    {
      int r;
      r = guestfs_is_busy (_handle);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
      return r != 0 ? true : false;
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_is_chardev_opts_argv (IntPtr h, [In] string path, void *);

    /// <summary>
    /// test if character device
    /// </summary>
    public bool is_chardev (string path)
    {
      int r;
      r = guestfs_is_chardev_opts_argv (_handle, path, NULL);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
      return r != 0 ? true : false;
    }

    public bool is_chardev_opts (string path)
    {
      return is_chardev (path);
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_is_config (IntPtr h);

    /// <summary>
    /// is in configuration state
    /// </summary>
    public bool is_config ()
    {
      int r;
      r = guestfs_is_config (_handle);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
      return r != 0 ? true : false;
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_is_dir_opts_argv (IntPtr h, [In] string path, void *);

    /// <summary>
    /// test if a directory
    /// </summary>
    public bool is_dir (string path)
    {
      int r;
      r = guestfs_is_dir_opts_argv (_handle, path, NULL);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
      return r != 0 ? true : false;
    }

    public bool is_dir_opts (string path)
    {
      return is_dir (path);
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_is_fifo_opts_argv (IntPtr h, [In] string path, void *);

    /// <summary>
    /// test if FIFO (named pipe)
    /// </summary>
    public bool is_fifo (string path)
    {
      int r;
      r = guestfs_is_fifo_opts_argv (_handle, path, NULL);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
      return r != 0 ? true : false;
    }

    public bool is_fifo_opts (string path)
    {
      return is_fifo (path);
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_is_file_opts_argv (IntPtr h, [In] string path, void *);

    /// <summary>
    /// test if a regular file
    /// </summary>
    public bool is_file (string path)
    {
      int r;
      r = guestfs_is_file_opts_argv (_handle, path, NULL);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
      return r != 0 ? true : false;
    }

    public bool is_file_opts (string path)
    {
      return is_file (path);
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_is_launching (IntPtr h);

    /// <summary>
    /// is launching subprocess
    /// </summary>
    public bool is_launching ()
    {
      int r;
      r = guestfs_is_launching (_handle);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
      return r != 0 ? true : false;
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_is_lv (IntPtr h, [In] string device);

    /// <summary>
    /// test if device is a logical volume
    /// </summary>
    public bool is_lv (string device)
    {
      int r;
      r = guestfs_is_lv (_handle, device);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
      return r != 0 ? true : false;
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_is_ready (IntPtr h);

    /// <summary>
    /// is ready to accept commands
    /// </summary>
    public bool is_ready ()
    {
      int r;
      r = guestfs_is_ready (_handle);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
      return r != 0 ? true : false;
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_is_socket_opts_argv (IntPtr h, [In] string path, void *);

    /// <summary>
    /// test if socket
    /// </summary>
    public bool is_socket (string path)
    {
      int r;
      r = guestfs_is_socket_opts_argv (_handle, path, NULL);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
      return r != 0 ? true : false;
    }

    public bool is_socket_opts (string path)
    {
      return is_socket (path);
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_is_symlink (IntPtr h, [In] string path);

    /// <summary>
    /// test if symbolic link
    /// </summary>
    public bool is_symlink (string path)
    {
      int r;
      r = guestfs_is_symlink (_handle, path);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
      return r != 0 ? true : false;
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_is_whole_device (IntPtr h, [In] string device);

    /// <summary>
    /// test if a device is a whole device
    /// </summary>
    public bool is_whole_device (string device)
    {
      int r;
      r = guestfs_is_whole_device (_handle, device);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
      return r != 0 ? true : false;
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_is_zero (IntPtr h, [In] string path);

    /// <summary>
    /// test if a file contains all zero bytes
    /// </summary>
    public bool is_zero (string path)
    {
      int r;
      r = guestfs_is_zero (_handle, path);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
      return r != 0 ? true : false;
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_is_zero_device (IntPtr h, [In] string device);

    /// <summary>
    /// test if a device contains all zero bytes
    /// </summary>
    public bool is_zero_device (string device)
    {
      int r;
      r = guestfs_is_zero_device (_handle, device);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
      return r != 0 ? true : false;
    }

    [DllImport ("libguestfs.so.0")]
    static extern _isoinfo guestfs_isoinfo (IntPtr h, [In] string isofile);

    /// <summary>
    /// get ISO information from primary volume descriptor of ISO file
    /// </summary>
    public _isoinfo isoinfo (string isofile)
    {
      _isoinfo r;
      r = guestfs_isoinfo (_handle, isofile);
      if (r == null)
        throw new Error (guestfs_last_error (_handle));
      return r;
    }

    [DllImport ("libguestfs.so.0")]
    static extern _isoinfo guestfs_isoinfo_device (IntPtr h, [In] string device);

    /// <summary>
    /// get ISO information from primary volume descriptor of device
    /// </summary>
    public _isoinfo isoinfo_device (string device)
    {
      _isoinfo r;
      r = guestfs_isoinfo_device (_handle, device);
      if (r == null)
        throw new Error (guestfs_last_error (_handle));
      return r;
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_journal_close (IntPtr h);

    /// <summary>
    /// close the systemd journal
    /// </summary>
    public void journal_close ()
    {
      int r;
      r = guestfs_journal_close (_handle);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern _xattr[] guestfs_journal_get (IntPtr h);

    /// <summary>
    /// read the current journal entry
    /// </summary>
    public _xattr[] journal_get ()
    {
      _xattr[] r;
      r = guestfs_journal_get (_handle);
      if (r == null)
        throw new Error (guestfs_last_error (_handle));
      return r;
    }

    [DllImport ("libguestfs.so.0")]
    static extern long guestfs_journal_get_data_threshold (IntPtr h);

    /// <summary>
    /// get the data threshold for reading journal entries
    /// </summary>
    public long journal_get_data_threshold ()
    {
      long r;
      r = guestfs_journal_get_data_threshold (_handle);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
      return r;
    }

    [DllImport ("libguestfs.so.0")]
    static extern long guestfs_journal_get_realtime_usec (IntPtr h);

    /// <summary>
    /// get the timestamp of the current journal entry
    /// </summary>
    public long journal_get_realtime_usec ()
    {
      long r;
      r = guestfs_journal_get_realtime_usec (_handle);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
      return r;
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_journal_next (IntPtr h);

    /// <summary>
    /// move to the next journal entry
    /// </summary>
    public bool journal_next ()
    {
      int r;
      r = guestfs_journal_next (_handle);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
      return r != 0 ? true : false;
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_journal_open (IntPtr h, [In] string directory);

    /// <summary>
    /// open the systemd journal
    /// </summary>
    public void journal_open (string directory)
    {
      int r;
      r = guestfs_journal_open (_handle, directory);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_journal_set_data_threshold (IntPtr h, long threshold);

    /// <summary>
    /// set the data threshold for reading journal entries
    /// </summary>
    public void journal_set_data_threshold (long threshold)
    {
      int r;
      r = guestfs_journal_set_data_threshold (_handle, threshold);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern long guestfs_journal_skip (IntPtr h, long skip);

    /// <summary>
    /// skip forwards or backwards in the journal
    /// </summary>
    public long journal_skip (long skip)
    {
      long r;
      r = guestfs_journal_skip (_handle, skip);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
      return r;
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_kill_subprocess (IntPtr h);

    /// <summary>
    /// kill the hypervisor
    /// </summary>
    public void kill_subprocess ()
    {
      int r;
      r = guestfs_kill_subprocess (_handle);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_launch (IntPtr h);

    /// <summary>
    /// launch the backend
    /// </summary>
    public void launch ()
    {
      int r;
      r = guestfs_launch (_handle);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_lchown (IntPtr h, int owner, int group, [In] string path);

    /// <summary>
    /// change file owner and group
    /// </summary>
    public void lchown (int owner, int group, string path)
    {
      int r;
      r = guestfs_lchown (_handle, owner, group, path);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_ldmtool_create_all (IntPtr h);

    /// <summary>
    /// scan and create Windows dynamic disk volumes
    /// </summary>
    public void ldmtool_create_all ()
    {
      int r;
      r = guestfs_ldmtool_create_all (_handle);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern string[] guestfs_ldmtool_diskgroup_disks (IntPtr h, [In] string diskgroup);

    /// <summary>
    /// return the disks in a Windows dynamic disk group
    /// </summary>
    public string[] ldmtool_diskgroup_disks (string diskgroup)
    {
      string[] r;
      r = guestfs_ldmtool_diskgroup_disks (_handle, diskgroup);
      if (r == null)
        throw new Error (guestfs_last_error (_handle));
      return r;
    }

    [DllImport ("libguestfs.so.0")]
    static extern string guestfs_ldmtool_diskgroup_name (IntPtr h, [In] string diskgroup);

    /// <summary>
    /// return the name of a Windows dynamic disk group
    /// </summary>
    public string ldmtool_diskgroup_name (string diskgroup)
    {
      string r;
      r = guestfs_ldmtool_diskgroup_name (_handle, diskgroup);
      if (r == null)
        throw new Error (guestfs_last_error (_handle));
      return r;
    }

    [DllImport ("libguestfs.so.0")]
    static extern string[] guestfs_ldmtool_diskgroup_volumes (IntPtr h, [In] string diskgroup);

    /// <summary>
    /// return the volumes in a Windows dynamic disk group
    /// </summary>
    public string[] ldmtool_diskgroup_volumes (string diskgroup)
    {
      string[] r;
      r = guestfs_ldmtool_diskgroup_volumes (_handle, diskgroup);
      if (r == null)
        throw new Error (guestfs_last_error (_handle));
      return r;
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_ldmtool_remove_all (IntPtr h);

    /// <summary>
    /// remove all Windows dynamic disk volumes
    /// </summary>
    public void ldmtool_remove_all ()
    {
      int r;
      r = guestfs_ldmtool_remove_all (_handle);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern string[] guestfs_ldmtool_scan (IntPtr h);

    /// <summary>
    /// scan for Windows dynamic disks
    /// </summary>
    public string[] ldmtool_scan ()
    {
      string[] r;
      r = guestfs_ldmtool_scan (_handle);
      if (r == null)
        throw new Error (guestfs_last_error (_handle));
      return r;
    }

    [DllImport ("libguestfs.so.0")]
    static extern string[] guestfs_ldmtool_scan_devices (IntPtr h, [In] string[] devices);

    /// <summary>
    /// scan for Windows dynamic disks
    /// </summary>
    public string[] ldmtool_scan_devices (string[] devices)
    {
      string[] r;
      r = guestfs_ldmtool_scan_devices (_handle, devices);
      if (r == null)
        throw new Error (guestfs_last_error (_handle));
      return r;
    }

    [DllImport ("libguestfs.so.0")]
    static extern string guestfs_ldmtool_volume_hint (IntPtr h, [In] string diskgroup, [In] string volume);

    /// <summary>
    /// return the hint field of a Windows dynamic disk volume
    /// </summary>
    public string ldmtool_volume_hint (string diskgroup, string volume)
    {
      string r;
      r = guestfs_ldmtool_volume_hint (_handle, diskgroup, volume);
      if (r == null)
        throw new Error (guestfs_last_error (_handle));
      return r;
    }

    [DllImport ("libguestfs.so.0")]
    static extern string[] guestfs_ldmtool_volume_partitions (IntPtr h, [In] string diskgroup, [In] string volume);

    /// <summary>
    /// return the partitions in a Windows dynamic disk volume
    /// </summary>
    public string[] ldmtool_volume_partitions (string diskgroup, string volume)
    {
      string[] r;
      r = guestfs_ldmtool_volume_partitions (_handle, diskgroup, volume);
      if (r == null)
        throw new Error (guestfs_last_error (_handle));
      return r;
    }

    [DllImport ("libguestfs.so.0")]
    static extern string guestfs_ldmtool_volume_type (IntPtr h, [In] string diskgroup, [In] string volume);

    /// <summary>
    /// return the type of a Windows dynamic disk volume
    /// </summary>
    public string ldmtool_volume_type (string diskgroup, string volume)
    {
      string r;
      r = guestfs_ldmtool_volume_type (_handle, diskgroup, volume);
      if (r == null)
        throw new Error (guestfs_last_error (_handle));
      return r;
    }

    [DllImport ("libguestfs.so.0")]
    static extern string guestfs_lgetxattr (IntPtr h, [In] string path, [In] string name);

    /// <summary>
    /// get a single extended attribute
    /// </summary>
    public string lgetxattr (string path, string name)
    {
      string r;
      r = guestfs_lgetxattr (_handle, path, name);
      if (r == null)
        throw new Error (guestfs_last_error (_handle));
      return r;
    }

    [DllImport ("libguestfs.so.0")]
    static extern _xattr[] guestfs_lgetxattrs (IntPtr h, [In] string path);

    /// <summary>
    /// list extended attributes of a file or directory
    /// </summary>
    public _xattr[] lgetxattrs (string path)
    {
      _xattr[] r;
      r = guestfs_lgetxattrs (_handle, path);
      if (r == null)
        throw new Error (guestfs_last_error (_handle));
      return r;
    }

    [DllImport ("libguestfs.so.0")]
    static extern string[] guestfs_list_9p (IntPtr h);

    /// <summary>
    /// list 9p filesystems
    /// </summary>
    public string[] list_9p ()
    {
      string[] r;
      r = guestfs_list_9p (_handle);
      if (r == null)
        throw new Error (guestfs_last_error (_handle));
      return r;
    }

    [DllImport ("libguestfs.so.0")]
    static extern string[] guestfs_list_devices (IntPtr h);

    /// <summary>
    /// list the block devices
    /// </summary>
    public string[] list_devices ()
    {
      string[] r;
      r = guestfs_list_devices (_handle);
      if (r == null)
        throw new Error (guestfs_last_error (_handle));
      return r;
    }

    [DllImport ("libguestfs.so.0")]
    static extern string[] guestfs_list_disk_labels (IntPtr h);

    /// <summary>
    /// mapping of disk labels to devices
    /// </summary>
    public Hashtable list_disk_labels ()
    {
      string[] r;
      r = guestfs_list_disk_labels (_handle);
      if (r == null)
        throw new Error (guestfs_last_error (_handle));
      Hashtable rr = new Hashtable ();
      for (size_t i = 0; i < r.Length; i += 2)
        rr.Add (r[i], r[i+1]);
      return rr;
    }

    [DllImport ("libguestfs.so.0")]
    static extern string[] guestfs_list_dm_devices (IntPtr h);

    /// <summary>
    /// list device mapper devices
    /// </summary>
    public string[] list_dm_devices ()
    {
      string[] r;
      r = guestfs_list_dm_devices (_handle);
      if (r == null)
        throw new Error (guestfs_last_error (_handle));
      return r;
    }

    [DllImport ("libguestfs.so.0")]
    static extern string[] guestfs_list_filesystems (IntPtr h);

    /// <summary>
    /// list filesystems
    /// </summary>
    public Hashtable list_filesystems ()
    {
      string[] r;
      r = guestfs_list_filesystems (_handle);
      if (r == null)
        throw new Error (guestfs_last_error (_handle));
      Hashtable rr = new Hashtable ();
      for (size_t i = 0; i < r.Length; i += 2)
        rr.Add (r[i], r[i+1]);
      return rr;
    }

    [DllImport ("libguestfs.so.0")]
    static extern string[] guestfs_list_ldm_partitions (IntPtr h);

    /// <summary>
    /// list all Windows dynamic disk partitions
    /// </summary>
    public string[] list_ldm_partitions ()
    {
      string[] r;
      r = guestfs_list_ldm_partitions (_handle);
      if (r == null)
        throw new Error (guestfs_last_error (_handle));
      return r;
    }

    [DllImport ("libguestfs.so.0")]
    static extern string[] guestfs_list_ldm_volumes (IntPtr h);

    /// <summary>
    /// list all Windows dynamic disk volumes
    /// </summary>
    public string[] list_ldm_volumes ()
    {
      string[] r;
      r = guestfs_list_ldm_volumes (_handle);
      if (r == null)
        throw new Error (guestfs_last_error (_handle));
      return r;
    }

    [DllImport ("libguestfs.so.0")]
    static extern string[] guestfs_list_md_devices (IntPtr h);

    /// <summary>
    /// list Linux md (RAID) devices
    /// </summary>
    public string[] list_md_devices ()
    {
      string[] r;
      r = guestfs_list_md_devices (_handle);
      if (r == null)
        throw new Error (guestfs_last_error (_handle));
      return r;
    }

    [DllImport ("libguestfs.so.0")]
    static extern string[] guestfs_list_partitions (IntPtr h);

    /// <summary>
    /// list the partitions
    /// </summary>
    public string[] list_partitions ()
    {
      string[] r;
      r = guestfs_list_partitions (_handle);
      if (r == null)
        throw new Error (guestfs_last_error (_handle));
      return r;
    }

    [DllImport ("libguestfs.so.0")]
    static extern string guestfs_ll (IntPtr h, [In] string directory);

    /// <summary>
    /// list the files in a directory (long format)
    /// </summary>
    public string ll (string directory)
    {
      string r;
      r = guestfs_ll (_handle, directory);
      if (r == null)
        throw new Error (guestfs_last_error (_handle));
      return r;
    }

    [DllImport ("libguestfs.so.0")]
    static extern string guestfs_llz (IntPtr h, [In] string directory);

    /// <summary>
    /// list the files in a directory (long format with SELinux contexts)
    /// </summary>
    public string llz (string directory)
    {
      string r;
      r = guestfs_llz (_handle, directory);
      if (r == null)
        throw new Error (guestfs_last_error (_handle));
      return r;
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_ln (IntPtr h, [In] string target, [In] string linkname);

    /// <summary>
    /// create a hard link
    /// </summary>
    public void ln (string target, string linkname)
    {
      int r;
      r = guestfs_ln (_handle, target, linkname);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_ln_f (IntPtr h, [In] string target, [In] string linkname);

    /// <summary>
    /// create a hard link
    /// </summary>
    public void ln_f (string target, string linkname)
    {
      int r;
      r = guestfs_ln_f (_handle, target, linkname);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_ln_s (IntPtr h, [In] string target, [In] string linkname);

    /// <summary>
    /// create a symbolic link
    /// </summary>
    public void ln_s (string target, string linkname)
    {
      int r;
      r = guestfs_ln_s (_handle, target, linkname);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_ln_sf (IntPtr h, [In] string target, [In] string linkname);

    /// <summary>
    /// create a symbolic link
    /// </summary>
    public void ln_sf (string target, string linkname)
    {
      int r;
      r = guestfs_ln_sf (_handle, target, linkname);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_lremovexattr (IntPtr h, [In] string xattr, [In] string path);

    /// <summary>
    /// remove extended attribute of a file or directory
    /// </summary>
    public void lremovexattr (string xattr, string path)
    {
      int r;
      r = guestfs_lremovexattr (_handle, xattr, path);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern string[] guestfs_ls (IntPtr h, [In] string directory);

    /// <summary>
    /// list the files in a directory
    /// </summary>
    public string[] ls (string directory)
    {
      string[] r;
      r = guestfs_ls (_handle, directory);
      if (r == null)
        throw new Error (guestfs_last_error (_handle));
      return r;
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_ls0 (IntPtr h, [In] string dir, [In] string filenames);

    /// <summary>
    /// get list of files in a directory
    /// </summary>
    public void ls0 (string dir, string filenames)
    {
      int r;
      r = guestfs_ls0 (_handle, dir, filenames);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_lsetxattr (IntPtr h, [In] string xattr, [In] string val, int vallen, [In] string path);

    /// <summary>
    /// set extended attribute of a file or directory
    /// </summary>
    public void lsetxattr (string xattr, string val, int vallen, string path)
    {
      int r;
      r = guestfs_lsetxattr (_handle, xattr, val, vallen, path);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern _stat guestfs_lstat (IntPtr h, [In] string path);

    /// <summary>
    /// get file information for a symbolic link
    /// </summary>
    public _stat lstat (string path)
    {
      _stat r;
      r = guestfs_lstat (_handle, path);
      if (r == null)
        throw new Error (guestfs_last_error (_handle));
      return r;
    }

    [DllImport ("libguestfs.so.0")]
    static extern _stat[] guestfs_lstatlist (IntPtr h, [In] string path, [In] string[] names);

    /// <summary>
    /// lstat on multiple files
    /// </summary>
    public _stat[] lstatlist (string path, string[] names)
    {
      _stat[] r;
      r = guestfs_lstatlist (_handle, path, names);
      if (r == null)
        throw new Error (guestfs_last_error (_handle));
      return r;
    }

    [DllImport ("libguestfs.so.0")]
    static extern _statns guestfs_lstatns (IntPtr h, [In] string path);

    /// <summary>
    /// get file information for a symbolic link
    /// </summary>
    public _statns lstatns (string path)
    {
      _statns r;
      r = guestfs_lstatns (_handle, path);
      if (r == null)
        throw new Error (guestfs_last_error (_handle));
      return r;
    }

    [DllImport ("libguestfs.so.0")]
    static extern _statns[] guestfs_lstatnslist (IntPtr h, [In] string path, [In] string[] names);

    /// <summary>
    /// lstat on multiple files
    /// </summary>
    public _statns[] lstatnslist (string path, string[] names)
    {
      _statns[] r;
      r = guestfs_lstatnslist (_handle, path, names);
      if (r == null)
        throw new Error (guestfs_last_error (_handle));
      return r;
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_luks_add_key (IntPtr h, [In] string device, [In] string key, [In] string newkey, int keyslot);

    /// <summary>
    /// add a key on a LUKS encrypted device
    /// </summary>
    public void luks_add_key (string device, string key, string newkey, int keyslot)
    {
      int r;
      r = guestfs_luks_add_key (_handle, device, key, newkey, keyslot);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_luks_close (IntPtr h, [In] string device);

    /// <summary>
    /// close a LUKS device
    /// </summary>
    public void luks_close (string device)
    {
      int r;
      r = guestfs_luks_close (_handle, device);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_luks_format (IntPtr h, [In] string device, [In] string key, int keyslot);

    /// <summary>
    /// format a block device as a LUKS encrypted device
    /// </summary>
    public void luks_format (string device, string key, int keyslot)
    {
      int r;
      r = guestfs_luks_format (_handle, device, key, keyslot);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_luks_format_cipher (IntPtr h, [In] string device, [In] string key, int keyslot, [In] string cipher);

    /// <summary>
    /// format a block device as a LUKS encrypted device
    /// </summary>
    public void luks_format_cipher (string device, string key, int keyslot, string cipher)
    {
      int r;
      r = guestfs_luks_format_cipher (_handle, device, key, keyslot, cipher);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_luks_kill_slot (IntPtr h, [In] string device, [In] string key, int keyslot);

    /// <summary>
    /// remove a key from a LUKS encrypted device
    /// </summary>
    public void luks_kill_slot (string device, string key, int keyslot)
    {
      int r;
      r = guestfs_luks_kill_slot (_handle, device, key, keyslot);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_luks_open (IntPtr h, [In] string device, [In] string key, [In] string mapname);

    /// <summary>
    /// open a LUKS-encrypted block device
    /// </summary>
    public void luks_open (string device, string key, string mapname)
    {
      int r;
      r = guestfs_luks_open (_handle, device, key, mapname);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_luks_open_ro (IntPtr h, [In] string device, [In] string key, [In] string mapname);

    /// <summary>
    /// open a LUKS-encrypted block device read-only
    /// </summary>
    public void luks_open_ro (string device, string key, string mapname)
    {
      int r;
      r = guestfs_luks_open_ro (_handle, device, key, mapname);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_lvcreate (IntPtr h, [In] string logvol, [In] string volgroup, int mbytes);

    /// <summary>
    /// create an LVM logical volume
    /// </summary>
    public void lvcreate (string logvol, string volgroup, int mbytes)
    {
      int r;
      r = guestfs_lvcreate (_handle, logvol, volgroup, mbytes);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_lvcreate_free (IntPtr h, [In] string logvol, [In] string volgroup, int percent);

    /// <summary>
    /// create an LVM logical volume in % remaining free space
    /// </summary>
    public void lvcreate_free (string logvol, string volgroup, int percent)
    {
      int r;
      r = guestfs_lvcreate_free (_handle, logvol, volgroup, percent);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern string guestfs_lvm_canonical_lv_name (IntPtr h, [In] string lvname);

    /// <summary>
    /// get canonical name of an LV
    /// </summary>
    public string lvm_canonical_lv_name (string lvname)
    {
      string r;
      r = guestfs_lvm_canonical_lv_name (_handle, lvname);
      if (r == null)
        throw new Error (guestfs_last_error (_handle));
      return r;
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_lvm_clear_filter (IntPtr h);

    /// <summary>
    /// clear LVM device filter
    /// </summary>
    public void lvm_clear_filter ()
    {
      int r;
      r = guestfs_lvm_clear_filter (_handle);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_lvm_remove_all (IntPtr h);

    /// <summary>
    /// remove all LVM LVs, VGs and PVs
    /// </summary>
    public void lvm_remove_all ()
    {
      int r;
      r = guestfs_lvm_remove_all (_handle);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_lvm_set_filter (IntPtr h, [In] string[] devices);

    /// <summary>
    /// set LVM device filter
    /// </summary>
    public void lvm_set_filter (string[] devices)
    {
      int r;
      r = guestfs_lvm_set_filter (_handle, devices);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_lvremove (IntPtr h, [In] string device);

    /// <summary>
    /// remove an LVM logical volume
    /// </summary>
    public void lvremove (string device)
    {
      int r;
      r = guestfs_lvremove (_handle, device);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_lvrename (IntPtr h, [In] string logvol, [In] string newlogvol);

    /// <summary>
    /// rename an LVM logical volume
    /// </summary>
    public void lvrename (string logvol, string newlogvol)
    {
      int r;
      r = guestfs_lvrename (_handle, logvol, newlogvol);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_lvresize (IntPtr h, [In] string device, int mbytes);

    /// <summary>
    /// resize an LVM logical volume
    /// </summary>
    public void lvresize (string device, int mbytes)
    {
      int r;
      r = guestfs_lvresize (_handle, device, mbytes);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_lvresize_free (IntPtr h, [In] string lv, int percent);

    /// <summary>
    /// expand an LV to fill free space
    /// </summary>
    public void lvresize_free (string lv, int percent)
    {
      int r;
      r = guestfs_lvresize_free (_handle, lv, percent);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern string[] guestfs_lvs (IntPtr h);

    /// <summary>
    /// list the LVM logical volumes (LVs)
    /// </summary>
    public string[] lvs ()
    {
      string[] r;
      r = guestfs_lvs (_handle);
      if (r == null)
        throw new Error (guestfs_last_error (_handle));
      return r;
    }

    [DllImport ("libguestfs.so.0")]
    static extern _lvm_lv[] guestfs_lvs_full (IntPtr h);

    /// <summary>
    /// list the LVM logical volumes (LVs)
    /// </summary>
    public _lvm_lv[] lvs_full ()
    {
      _lvm_lv[] r;
      r = guestfs_lvs_full (_handle);
      if (r == null)
        throw new Error (guestfs_last_error (_handle));
      return r;
    }

    [DllImport ("libguestfs.so.0")]
    static extern string guestfs_lvuuid (IntPtr h, [In] string device);

    /// <summary>
    /// get the UUID of a logical volume
    /// </summary>
    public string lvuuid (string device)
    {
      string r;
      r = guestfs_lvuuid (_handle, device);
      if (r == null)
        throw new Error (guestfs_last_error (_handle));
      return r;
    }

    [DllImport ("libguestfs.so.0")]
    static extern _xattr[] guestfs_lxattrlist (IntPtr h, [In] string path, [In] string[] names);

    /// <summary>
    /// lgetxattr on multiple files
    /// </summary>
    public _xattr[] lxattrlist (string path, string[] names)
    {
      _xattr[] r;
      r = guestfs_lxattrlist (_handle, path, names);
      if (r == null)
        throw new Error (guestfs_last_error (_handle));
      return r;
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_max_disks (IntPtr h);

    /// <summary>
    /// maximum number of disks that may be added
    /// </summary>
    public int max_disks ()
    {
      int r;
      r = guestfs_max_disks (_handle);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
      return r;
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_md_create_argv (IntPtr h, [In] string name, [In] string[] devices, void *);

    /// <summary>
    /// create a Linux md (RAID) device
    /// </summary>
    public void md_create (string name, string[] devices)
    {
      int r;
      r = guestfs_md_create_argv (_handle, name, devices, NULL);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern string[] guestfs_md_detail (IntPtr h, [In] string md);

    /// <summary>
    /// obtain metadata for an MD device
    /// </summary>
    public Hashtable md_detail (string md)
    {
      string[] r;
      r = guestfs_md_detail (_handle, md);
      if (r == null)
        throw new Error (guestfs_last_error (_handle));
      Hashtable rr = new Hashtable ();
      for (size_t i = 0; i < r.Length; i += 2)
        rr.Add (r[i], r[i+1]);
      return rr;
    }

    [DllImport ("libguestfs.so.0")]
    static extern _mdstat[] guestfs_md_stat (IntPtr h, [In] string md);

    /// <summary>
    /// get underlying devices from an MD device
    /// </summary>
    public _mdstat[] md_stat (string md)
    {
      _mdstat[] r;
      r = guestfs_md_stat (_handle, md);
      if (r == null)
        throw new Error (guestfs_last_error (_handle));
      return r;
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_md_stop (IntPtr h, [In] string md);

    /// <summary>
    /// stop a Linux md (RAID) device
    /// </summary>
    public void md_stop (string md)
    {
      int r;
      r = guestfs_md_stop (_handle, md);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_mkdir (IntPtr h, [In] string path);

    /// <summary>
    /// create a directory
    /// </summary>
    public void mkdir (string path)
    {
      int r;
      r = guestfs_mkdir (_handle, path);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_mkdir_mode (IntPtr h, [In] string path, int mode);

    /// <summary>
    /// create a directory with a particular mode
    /// </summary>
    public void mkdir_mode (string path, int mode)
    {
      int r;
      r = guestfs_mkdir_mode (_handle, path, mode);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_mkdir_p (IntPtr h, [In] string path);

    /// <summary>
    /// create a directory and parents
    /// </summary>
    public void mkdir_p (string path)
    {
      int r;
      r = guestfs_mkdir_p (_handle, path);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern string guestfs_mkdtemp (IntPtr h, [In] string tmpl);

    /// <summary>
    /// create a temporary directory
    /// </summary>
    public string mkdtemp (string tmpl)
    {
      string r;
      r = guestfs_mkdtemp (_handle, tmpl);
      if (r == null)
        throw new Error (guestfs_last_error (_handle));
      return r;
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_mke2fs_argv (IntPtr h, [In] string device, void *);

    /// <summary>
    /// create an ext2/ext3/ext4 filesystem on device
    /// </summary>
    public void mke2fs (string device)
    {
      int r;
      r = guestfs_mke2fs_argv (_handle, device, NULL);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_mke2fs_J (IntPtr h, [In] string fstype, int blocksize, [In] string device, [In] string journal);

    /// <summary>
    /// make ext2/3/4 filesystem with external journal
    /// </summary>
    public void mke2fs_J (string fstype, int blocksize, string device, string journal)
    {
      int r;
      r = guestfs_mke2fs_J (_handle, fstype, blocksize, device, journal);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_mke2fs_JL (IntPtr h, [In] string fstype, int blocksize, [In] string device, [In] string label);

    /// <summary>
    /// make ext2/3/4 filesystem with external journal
    /// </summary>
    public void mke2fs_JL (string fstype, int blocksize, string device, string label)
    {
      int r;
      r = guestfs_mke2fs_JL (_handle, fstype, blocksize, device, label);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_mke2fs_JU (IntPtr h, [In] string fstype, int blocksize, [In] string device, [In] string uuid);

    /// <summary>
    /// make ext2/3/4 filesystem with external journal
    /// </summary>
    public void mke2fs_JU (string fstype, int blocksize, string device, string uuid)
    {
      int r;
      r = guestfs_mke2fs_JU (_handle, fstype, blocksize, device, uuid);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_mke2journal (IntPtr h, int blocksize, [In] string device);

    /// <summary>
    /// make ext2/3/4 external journal
    /// </summary>
    public void mke2journal (int blocksize, string device)
    {
      int r;
      r = guestfs_mke2journal (_handle, blocksize, device);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_mke2journal_L (IntPtr h, int blocksize, [In] string label, [In] string device);

    /// <summary>
    /// make ext2/3/4 external journal with label
    /// </summary>
    public void mke2journal_L (int blocksize, string label, string device)
    {
      int r;
      r = guestfs_mke2journal_L (_handle, blocksize, label, device);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_mke2journal_U (IntPtr h, int blocksize, [In] string uuid, [In] string device);

    /// <summary>
    /// make ext2/3/4 external journal with UUID
    /// </summary>
    public void mke2journal_U (int blocksize, string uuid, string device)
    {
      int r;
      r = guestfs_mke2journal_U (_handle, blocksize, uuid, device);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_mkfifo (IntPtr h, int mode, [In] string path);

    /// <summary>
    /// make FIFO (named pipe)
    /// </summary>
    public void mkfifo (int mode, string path)
    {
      int r;
      r = guestfs_mkfifo (_handle, mode, path);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_mkfs_opts_argv (IntPtr h, [In] string fstype, [In] string device, void *);

    /// <summary>
    /// make a filesystem
    /// </summary>
    public void mkfs (string fstype, string device)
    {
      int r;
      r = guestfs_mkfs_opts_argv (_handle, fstype, device, NULL);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    public void mkfs_opts (string fstype, string device)
    {
      mkfs (fstype, device);
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_mkfs_b (IntPtr h, [In] string fstype, int blocksize, [In] string device);

    /// <summary>
    /// make a filesystem with block size
    /// </summary>
    public void mkfs_b (string fstype, int blocksize, string device)
    {
      int r;
      r = guestfs_mkfs_b (_handle, fstype, blocksize, device);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_mkfs_btrfs_argv (IntPtr h, [In] string[] devices, void *);

    /// <summary>
    /// create a btrfs filesystem
    /// </summary>
    public void mkfs_btrfs (string[] devices)
    {
      int r;
      r = guestfs_mkfs_btrfs_argv (_handle, devices, NULL);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_mklost_and_found (IntPtr h, [In] string mountpoint);

    /// <summary>
    /// make lost+found directory on an ext2/3/4 filesystem
    /// </summary>
    public void mklost_and_found (string mountpoint)
    {
      int r;
      r = guestfs_mklost_and_found (_handle, mountpoint);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_mkmountpoint (IntPtr h, [In] string exemptpath);

    /// <summary>
    /// create a mountpoint
    /// </summary>
    public void mkmountpoint (string exemptpath)
    {
      int r;
      r = guestfs_mkmountpoint (_handle, exemptpath);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_mknod (IntPtr h, int mode, int devmajor, int devminor, [In] string path);

    /// <summary>
    /// make block, character or FIFO devices
    /// </summary>
    public void mknod (int mode, int devmajor, int devminor, string path)
    {
      int r;
      r = guestfs_mknod (_handle, mode, devmajor, devminor, path);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_mknod_b (IntPtr h, int mode, int devmajor, int devminor, [In] string path);

    /// <summary>
    /// make block device node
    /// </summary>
    public void mknod_b (int mode, int devmajor, int devminor, string path)
    {
      int r;
      r = guestfs_mknod_b (_handle, mode, devmajor, devminor, path);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_mknod_c (IntPtr h, int mode, int devmajor, int devminor, [In] string path);

    /// <summary>
    /// make char device node
    /// </summary>
    public void mknod_c (int mode, int devmajor, int devminor, string path)
    {
      int r;
      r = guestfs_mknod_c (_handle, mode, devmajor, devminor, path);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_mkswap_opts_argv (IntPtr h, [In] string device, void *);

    /// <summary>
    /// create a swap partition
    /// </summary>
    public void mkswap (string device)
    {
      int r;
      r = guestfs_mkswap_opts_argv (_handle, device, NULL);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    public void mkswap_opts (string device)
    {
      mkswap (device);
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_mkswap_L (IntPtr h, [In] string label, [In] string device);

    /// <summary>
    /// create a swap partition with a label
    /// </summary>
    public void mkswap_L (string label, string device)
    {
      int r;
      r = guestfs_mkswap_L (_handle, label, device);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_mkswap_U (IntPtr h, [In] string uuid, [In] string device);

    /// <summary>
    /// create a swap partition with an explicit UUID
    /// </summary>
    public void mkswap_U (string uuid, string device)
    {
      int r;
      r = guestfs_mkswap_U (_handle, uuid, device);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_mkswap_file (IntPtr h, [In] string path);

    /// <summary>
    /// create a swap file
    /// </summary>
    public void mkswap_file (string path)
    {
      int r;
      r = guestfs_mkswap_file (_handle, path);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern string guestfs_mktemp_argv (IntPtr h, [In] string tmpl, void *);

    /// <summary>
    /// create a temporary file
    /// </summary>
    public string mktemp (string tmpl)
    {
      string r;
      r = guestfs_mktemp_argv (_handle, tmpl, NULL);
      if (r == null)
        throw new Error (guestfs_last_error (_handle));
      return r;
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_modprobe (IntPtr h, [In] string modulename);

    /// <summary>
    /// load a kernel module
    /// </summary>
    public void modprobe (string modulename)
    {
      int r;
      r = guestfs_modprobe (_handle, modulename);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_mount (IntPtr h, [In] string mountable, [In] string mountpoint);

    /// <summary>
    /// mount a guest disk at a position in the filesystem
    /// </summary>
    public void mount (string mountable, string mountpoint)
    {
      int r;
      r = guestfs_mount (_handle, mountable, mountpoint);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_mount_9p_argv (IntPtr h, [In] string mounttag, [In] string mountpoint, void *);

    /// <summary>
    /// mount 9p filesystem
    /// </summary>
    public void mount_9p (string mounttag, string mountpoint)
    {
      int r;
      r = guestfs_mount_9p_argv (_handle, mounttag, mountpoint, NULL);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_mount_local_argv (IntPtr h, [In] string localmountpoint, void *);

    /// <summary>
    /// mount on the local filesystem
    /// </summary>
    public void mount_local (string localmountpoint)
    {
      int r;
      r = guestfs_mount_local_argv (_handle, localmountpoint, NULL);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_mount_local_run (IntPtr h);

    /// <summary>
    /// run main loop of mount on the local filesystem
    /// </summary>
    public void mount_local_run ()
    {
      int r;
      r = guestfs_mount_local_run (_handle);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_mount_loop (IntPtr h, [In] string file, [In] string mountpoint);

    /// <summary>
    /// mount a file using the loop device
    /// </summary>
    public void mount_loop (string file, string mountpoint)
    {
      int r;
      r = guestfs_mount_loop (_handle, file, mountpoint);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_mount_options (IntPtr h, [In] string options, [In] string mountable, [In] string mountpoint);

    /// <summary>
    /// mount a guest disk with mount options
    /// </summary>
    public void mount_options (string options, string mountable, string mountpoint)
    {
      int r;
      r = guestfs_mount_options (_handle, options, mountable, mountpoint);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_mount_ro (IntPtr h, [In] string mountable, [In] string mountpoint);

    /// <summary>
    /// mount a guest disk, read-only
    /// </summary>
    public void mount_ro (string mountable, string mountpoint)
    {
      int r;
      r = guestfs_mount_ro (_handle, mountable, mountpoint);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_mount_vfs (IntPtr h, [In] string options, [In] string vfstype, [In] string mountable, [In] string mountpoint);

    /// <summary>
    /// mount a guest disk with mount options and vfstype
    /// </summary>
    public void mount_vfs (string options, string vfstype, string mountable, string mountpoint)
    {
      int r;
      r = guestfs_mount_vfs (_handle, options, vfstype, mountable, mountpoint);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern string[] guestfs_mountpoints (IntPtr h);

    /// <summary>
    /// show mountpoints
    /// </summary>
    public Hashtable mountpoints ()
    {
      string[] r;
      r = guestfs_mountpoints (_handle);
      if (r == null)
        throw new Error (guestfs_last_error (_handle));
      Hashtable rr = new Hashtable ();
      for (size_t i = 0; i < r.Length; i += 2)
        rr.Add (r[i], r[i+1]);
      return rr;
    }

    [DllImport ("libguestfs.so.0")]
    static extern string[] guestfs_mounts (IntPtr h);

    /// <summary>
    /// show mounted filesystems
    /// </summary>
    public string[] mounts ()
    {
      string[] r;
      r = guestfs_mounts (_handle);
      if (r == null)
        throw new Error (guestfs_last_error (_handle));
      return r;
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_mv (IntPtr h, [In] string src, [In] string dest);

    /// <summary>
    /// move a file
    /// </summary>
    public void mv (string src, string dest)
    {
      int r;
      r = guestfs_mv (_handle, src, dest);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_nr_devices (IntPtr h);

    /// <summary>
    /// return number of whole block devices (disks) added
    /// </summary>
    public int nr_devices ()
    {
      int r;
      r = guestfs_nr_devices (_handle);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
      return r;
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_ntfs_3g_probe (IntPtr h, bool rw, [In] string device);

    /// <summary>
    /// probe NTFS volume
    /// </summary>
    public int ntfs_3g_probe (bool rw, string device)
    {
      int r;
      r = guestfs_ntfs_3g_probe (_handle, rw, device);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
      return r;
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_ntfsclone_in (IntPtr h, [In] string backupfile, [In] string device);

    /// <summary>
    /// restore NTFS from backup file
    /// </summary>
    public void ntfsclone_in (string backupfile, string device)
    {
      int r;
      r = guestfs_ntfsclone_in (_handle, backupfile, device);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_ntfsclone_out_argv (IntPtr h, [In] string device, [In] string backupfile, void *);

    /// <summary>
    /// save NTFS to backup file
    /// </summary>
    public void ntfsclone_out (string device, string backupfile)
    {
      int r;
      r = guestfs_ntfsclone_out_argv (_handle, device, backupfile, NULL);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_ntfsfix_argv (IntPtr h, [In] string device, void *);

    /// <summary>
    /// fix common errors and force Windows to check NTFS
    /// </summary>
    public void ntfsfix (string device)
    {
      int r;
      r = guestfs_ntfsfix_argv (_handle, device, NULL);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_ntfsresize_opts_argv (IntPtr h, [In] string device, void *);

    /// <summary>
    /// resize an NTFS filesystem
    /// </summary>
    public void ntfsresize (string device)
    {
      int r;
      r = guestfs_ntfsresize_opts_argv (_handle, device, NULL);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    public void ntfsresize_opts (string device)
    {
      ntfsresize (device);
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_ntfsresize_size (IntPtr h, [In] string device, long size);

    /// <summary>
    /// resize an NTFS filesystem (with size)
    /// </summary>
    public void ntfsresize_size (string device, long size)
    {
      int r;
      r = guestfs_ntfsresize_size (_handle, device, size);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_parse_environment (IntPtr h);

    /// <summary>
    /// parse the environment and set handle flags accordingly
    /// </summary>
    public void parse_environment ()
    {
      int r;
      r = guestfs_parse_environment (_handle);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_parse_environment_list (IntPtr h, [In] string[] environment);

    /// <summary>
    /// parse the environment and set handle flags accordingly
    /// </summary>
    public void parse_environment_list (string[] environment)
    {
      int r;
      r = guestfs_parse_environment_list (_handle, environment);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_part_add (IntPtr h, [In] string device, [In] string prlogex, long startsect, long endsect);

    /// <summary>
    /// add a partition to the device
    /// </summary>
    public void part_add (string device, string prlogex, long startsect, long endsect)
    {
      int r;
      r = guestfs_part_add (_handle, device, prlogex, startsect, endsect);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_part_del (IntPtr h, [In] string device, int partnum);

    /// <summary>
    /// delete a partition
    /// </summary>
    public void part_del (string device, int partnum)
    {
      int r;
      r = guestfs_part_del (_handle, device, partnum);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_part_disk (IntPtr h, [In] string device, [In] string parttype);

    /// <summary>
    /// partition whole disk with a single primary partition
    /// </summary>
    public void part_disk (string device, string parttype)
    {
      int r;
      r = guestfs_part_disk (_handle, device, parttype);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_part_get_bootable (IntPtr h, [In] string device, int partnum);

    /// <summary>
    /// return true if a partition is bootable
    /// </summary>
    public bool part_get_bootable (string device, int partnum)
    {
      int r;
      r = guestfs_part_get_bootable (_handle, device, partnum);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
      return r != 0 ? true : false;
    }

    [DllImport ("libguestfs.so.0")]
    static extern string guestfs_part_get_gpt_type (IntPtr h, [In] string device, int partnum);

    /// <summary>
    /// get the type GUID of a GPT partition
    /// </summary>
    public string part_get_gpt_type (string device, int partnum)
    {
      string r;
      r = guestfs_part_get_gpt_type (_handle, device, partnum);
      if (r == null)
        throw new Error (guestfs_last_error (_handle));
      return r;
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_part_get_mbr_id (IntPtr h, [In] string device, int partnum);

    /// <summary>
    /// get the MBR type byte (ID byte) from a partition
    /// </summary>
    public int part_get_mbr_id (string device, int partnum)
    {
      int r;
      r = guestfs_part_get_mbr_id (_handle, device, partnum);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
      return r;
    }

    [DllImport ("libguestfs.so.0")]
    static extern string guestfs_part_get_name (IntPtr h, [In] string device, int partnum);

    /// <summary>
    /// get partition name
    /// </summary>
    public string part_get_name (string device, int partnum)
    {
      string r;
      r = guestfs_part_get_name (_handle, device, partnum);
      if (r == null)
        throw new Error (guestfs_last_error (_handle));
      return r;
    }

    [DllImport ("libguestfs.so.0")]
    static extern string guestfs_part_get_parttype (IntPtr h, [In] string device);

    /// <summary>
    /// get the partition table type
    /// </summary>
    public string part_get_parttype (string device)
    {
      string r;
      r = guestfs_part_get_parttype (_handle, device);
      if (r == null)
        throw new Error (guestfs_last_error (_handle));
      return r;
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_part_init (IntPtr h, [In] string device, [In] string parttype);

    /// <summary>
    /// create an empty partition table
    /// </summary>
    public void part_init (string device, string parttype)
    {
      int r;
      r = guestfs_part_init (_handle, device, parttype);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern _partition[] guestfs_part_list (IntPtr h, [In] string device);

    /// <summary>
    /// list partitions on a device
    /// </summary>
    public _partition[] part_list (string device)
    {
      _partition[] r;
      r = guestfs_part_list (_handle, device);
      if (r == null)
        throw new Error (guestfs_last_error (_handle));
      return r;
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_part_set_bootable (IntPtr h, [In] string device, int partnum, bool bootable);

    /// <summary>
    /// make a partition bootable
    /// </summary>
    public void part_set_bootable (string device, int partnum, bool bootable)
    {
      int r;
      r = guestfs_part_set_bootable (_handle, device, partnum, bootable);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_part_set_gpt_type (IntPtr h, [In] string device, int partnum, [In] string guid);

    /// <summary>
    /// set the type GUID of a GPT partition
    /// </summary>
    public void part_set_gpt_type (string device, int partnum, string guid)
    {
      int r;
      r = guestfs_part_set_gpt_type (_handle, device, partnum, guid);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_part_set_mbr_id (IntPtr h, [In] string device, int partnum, int idbyte);

    /// <summary>
    /// set the MBR type byte (ID byte) of a partition
    /// </summary>
    public void part_set_mbr_id (string device, int partnum, int idbyte)
    {
      int r;
      r = guestfs_part_set_mbr_id (_handle, device, partnum, idbyte);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_part_set_name (IntPtr h, [In] string device, int partnum, [In] string name);

    /// <summary>
    /// set partition name
    /// </summary>
    public void part_set_name (string device, int partnum, string name)
    {
      int r;
      r = guestfs_part_set_name (_handle, device, partnum, name);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern string guestfs_part_to_dev (IntPtr h, [In] string partition);

    /// <summary>
    /// convert partition name to device name
    /// </summary>
    public string part_to_dev (string partition)
    {
      string r;
      r = guestfs_part_to_dev (_handle, partition);
      if (r == null)
        throw new Error (guestfs_last_error (_handle));
      return r;
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_part_to_partnum (IntPtr h, [In] string partition);

    /// <summary>
    /// convert partition name to partition number
    /// </summary>
    public int part_to_partnum (string partition)
    {
      int r;
      r = guestfs_part_to_partnum (_handle, partition);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
      return r;
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_ping_daemon (IntPtr h);

    /// <summary>
    /// ping the guest daemon
    /// </summary>
    public void ping_daemon ()
    {
      int r;
      r = guestfs_ping_daemon (_handle);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern string guestfs_pread (IntPtr h, [In] string path, int count, long offset);

    /// <summary>
    /// read part of a file
    /// </summary>
    public string pread (string path, int count, long offset)
    {
      string r;
      r = guestfs_pread (_handle, path, count, offset);
      if (r == null)
        throw new Error (guestfs_last_error (_handle));
      return r;
    }

    [DllImport ("libguestfs.so.0")]
    static extern string guestfs_pread_device (IntPtr h, [In] string device, int count, long offset);

    /// <summary>
    /// read part of a device
    /// </summary>
    public string pread_device (string device, int count, long offset)
    {
      string r;
      r = guestfs_pread_device (_handle, device, count, offset);
      if (r == null)
        throw new Error (guestfs_last_error (_handle));
      return r;
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_pvchange_uuid (IntPtr h, [In] string device);

    /// <summary>
    /// generate a new random UUID for a physical volume
    /// </summary>
    public void pvchange_uuid (string device)
    {
      int r;
      r = guestfs_pvchange_uuid (_handle, device);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_pvchange_uuid_all (IntPtr h);

    /// <summary>
    /// generate new random UUIDs for all physical volumes
    /// </summary>
    public void pvchange_uuid_all ()
    {
      int r;
      r = guestfs_pvchange_uuid_all (_handle);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_pvcreate (IntPtr h, [In] string device);

    /// <summary>
    /// create an LVM physical volume
    /// </summary>
    public void pvcreate (string device)
    {
      int r;
      r = guestfs_pvcreate (_handle, device);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_pvremove (IntPtr h, [In] string device);

    /// <summary>
    /// remove an LVM physical volume
    /// </summary>
    public void pvremove (string device)
    {
      int r;
      r = guestfs_pvremove (_handle, device);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_pvresize (IntPtr h, [In] string device);

    /// <summary>
    /// resize an LVM physical volume
    /// </summary>
    public void pvresize (string device)
    {
      int r;
      r = guestfs_pvresize (_handle, device);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_pvresize_size (IntPtr h, [In] string device, long size);

    /// <summary>
    /// resize an LVM physical volume (with size)
    /// </summary>
    public void pvresize_size (string device, long size)
    {
      int r;
      r = guestfs_pvresize_size (_handle, device, size);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern string[] guestfs_pvs (IntPtr h);

    /// <summary>
    /// list the LVM physical volumes (PVs)
    /// </summary>
    public string[] pvs ()
    {
      string[] r;
      r = guestfs_pvs (_handle);
      if (r == null)
        throw new Error (guestfs_last_error (_handle));
      return r;
    }

    [DllImport ("libguestfs.so.0")]
    static extern _lvm_pv[] guestfs_pvs_full (IntPtr h);

    /// <summary>
    /// list the LVM physical volumes (PVs)
    /// </summary>
    public _lvm_pv[] pvs_full ()
    {
      _lvm_pv[] r;
      r = guestfs_pvs_full (_handle);
      if (r == null)
        throw new Error (guestfs_last_error (_handle));
      return r;
    }

    [DllImport ("libguestfs.so.0")]
    static extern string guestfs_pvuuid (IntPtr h, [In] string device);

    /// <summary>
    /// get the UUID of a physical volume
    /// </summary>
    public string pvuuid (string device)
    {
      string r;
      r = guestfs_pvuuid (_handle, device);
      if (r == null)
        throw new Error (guestfs_last_error (_handle));
      return r;
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_pwrite (IntPtr h, [In] string path, [In] string content, long offset);

    /// <summary>
    /// write to part of a file
    /// </summary>
    public int pwrite (string path, string content, long offset)
    {
      int r;
      r = guestfs_pwrite (_handle, path, content, offset);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
      return r;
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_pwrite_device (IntPtr h, [In] string device, [In] string content, long offset);

    /// <summary>
    /// write to part of a device
    /// </summary>
    public int pwrite_device (string device, string content, long offset)
    {
      int r;
      r = guestfs_pwrite_device (_handle, device, content, offset);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
      return r;
    }

    [DllImport ("libguestfs.so.0")]
    static extern string guestfs_read_file (IntPtr h, [In] string path);

    /// <summary>
    /// read a file
    /// </summary>
    public string read_file (string path)
    {
      string r;
      r = guestfs_read_file (_handle, path);
      if (r == null)
        throw new Error (guestfs_last_error (_handle));
      return r;
    }

    [DllImport ("libguestfs.so.0")]
    static extern string[] guestfs_read_lines (IntPtr h, [In] string path);

    /// <summary>
    /// read file as lines
    /// </summary>
    public string[] read_lines (string path)
    {
      string[] r;
      r = guestfs_read_lines (_handle, path);
      if (r == null)
        throw new Error (guestfs_last_error (_handle));
      return r;
    }

    [DllImport ("libguestfs.so.0")]
    static extern _dirent[] guestfs_readdir (IntPtr h, [In] string dir);

    /// <summary>
    /// read directories entries
    /// </summary>
    public _dirent[] readdir (string dir)
    {
      _dirent[] r;
      r = guestfs_readdir (_handle, dir);
      if (r == null)
        throw new Error (guestfs_last_error (_handle));
      return r;
    }

    [DllImport ("libguestfs.so.0")]
    static extern string guestfs_readlink (IntPtr h, [In] string path);

    /// <summary>
    /// read the target of a symbolic link
    /// </summary>
    public string readlink (string path)
    {
      string r;
      r = guestfs_readlink (_handle, path);
      if (r == null)
        throw new Error (guestfs_last_error (_handle));
      return r;
    }

    [DllImport ("libguestfs.so.0")]
    static extern string[] guestfs_readlinklist (IntPtr h, [In] string path, [In] string[] names);

    /// <summary>
    /// readlink on multiple files
    /// </summary>
    public string[] readlinklist (string path, string[] names)
    {
      string[] r;
      r = guestfs_readlinklist (_handle, path, names);
      if (r == null)
        throw new Error (guestfs_last_error (_handle));
      return r;
    }

    [DllImport ("libguestfs.so.0")]
    static extern string guestfs_realpath (IntPtr h, [In] string path);

    /// <summary>
    /// canonicalized absolute pathname
    /// </summary>
    public string realpath (string path)
    {
      string r;
      r = guestfs_realpath (_handle, path);
      if (r == null)
        throw new Error (guestfs_last_error (_handle));
      return r;
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_remount_argv (IntPtr h, [In] string mountpoint, void *);

    /// <summary>
    /// remount a filesystem with different options
    /// </summary>
    public void remount (string mountpoint)
    {
      int r;
      r = guestfs_remount_argv (_handle, mountpoint, NULL);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_remove_drive (IntPtr h, [In] string label);

    /// <summary>
    /// remove a disk image
    /// </summary>
    public void remove_drive (string label)
    {
      int r;
      r = guestfs_remove_drive (_handle, label);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_removexattr (IntPtr h, [In] string xattr, [In] string path);

    /// <summary>
    /// remove extended attribute of a file or directory
    /// </summary>
    public void removexattr (string xattr, string path)
    {
      int r;
      r = guestfs_removexattr (_handle, xattr, path);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_rename (IntPtr h, [In] string oldpath, [In] string newpath);

    /// <summary>
    /// rename a file on the same filesystem
    /// </summary>
    public void rename (string oldpath, string newpath)
    {
      int r;
      r = guestfs_rename (_handle, oldpath, newpath);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_resize2fs (IntPtr h, [In] string device);

    /// <summary>
    /// resize an ext2, ext3 or ext4 filesystem
    /// </summary>
    public void resize2fs (string device)
    {
      int r;
      r = guestfs_resize2fs (_handle, device);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_resize2fs_M (IntPtr h, [In] string device);

    /// <summary>
    /// resize an ext2, ext3 or ext4 filesystem to the minimum size
    /// </summary>
    public void resize2fs_M (string device)
    {
      int r;
      r = guestfs_resize2fs_M (_handle, device);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_resize2fs_size (IntPtr h, [In] string device, long size);

    /// <summary>
    /// resize an ext2, ext3 or ext4 filesystem (with size)
    /// </summary>
    public void resize2fs_size (string device, long size)
    {
      int r;
      r = guestfs_resize2fs_size (_handle, device, size);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_rm (IntPtr h, [In] string path);

    /// <summary>
    /// remove a file
    /// </summary>
    public void rm (string path)
    {
      int r;
      r = guestfs_rm (_handle, path);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_rm_f (IntPtr h, [In] string path);

    /// <summary>
    /// remove a file ignoring errors
    /// </summary>
    public void rm_f (string path)
    {
      int r;
      r = guestfs_rm_f (_handle, path);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_rm_rf (IntPtr h, [In] string path);

    /// <summary>
    /// remove a file or directory recursively
    /// </summary>
    public void rm_rf (string path)
    {
      int r;
      r = guestfs_rm_rf (_handle, path);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_rmdir (IntPtr h, [In] string path);

    /// <summary>
    /// remove a directory
    /// </summary>
    public void rmdir (string path)
    {
      int r;
      r = guestfs_rmdir (_handle, path);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_rmmountpoint (IntPtr h, [In] string exemptpath);

    /// <summary>
    /// remove a mountpoint
    /// </summary>
    public void rmmountpoint (string exemptpath)
    {
      int r;
      r = guestfs_rmmountpoint (_handle, exemptpath);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_rsync_argv (IntPtr h, [In] string src, [In] string dest, void *);

    /// <summary>
    /// synchronize the contents of two directories
    /// </summary>
    public void rsync (string src, string dest)
    {
      int r;
      r = guestfs_rsync_argv (_handle, src, dest, NULL);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_rsync_in_argv (IntPtr h, [In] string remote, [In] string dest, void *);

    /// <summary>
    /// synchronize host or remote filesystem with filesystem
    /// </summary>
    public void rsync_in (string remote, string dest)
    {
      int r;
      r = guestfs_rsync_in_argv (_handle, remote, dest, NULL);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_rsync_out_argv (IntPtr h, [In] string src, [In] string remote, void *);

    /// <summary>
    /// synchronize filesystem with host or remote filesystem
    /// </summary>
    public void rsync_out (string src, string remote)
    {
      int r;
      r = guestfs_rsync_out_argv (_handle, src, remote, NULL);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_scrub_device (IntPtr h, [In] string device);

    /// <summary>
    /// scrub (securely wipe) a device
    /// </summary>
    public void scrub_device (string device)
    {
      int r;
      r = guestfs_scrub_device (_handle, device);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_scrub_file (IntPtr h, [In] string file);

    /// <summary>
    /// scrub (securely wipe) a file
    /// </summary>
    public void scrub_file (string file)
    {
      int r;
      r = guestfs_scrub_file (_handle, file);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_scrub_freespace (IntPtr h, [In] string dir);

    /// <summary>
    /// scrub (securely wipe) free space
    /// </summary>
    public void scrub_freespace (string dir)
    {
      int r;
      r = guestfs_scrub_freespace (_handle, dir);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_set_append (IntPtr h, [In] string append);

    /// <summary>
    /// add options to kernel command line
    /// </summary>
    public void set_append (string append)
    {
      int r;
      r = guestfs_set_append (_handle, append);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_set_attach_method (IntPtr h, [In] string backend);

    /// <summary>
    /// set the backend
    /// </summary>
    public void set_attach_method (string backend)
    {
      int r;
      r = guestfs_set_attach_method (_handle, backend);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_set_autosync (IntPtr h, bool autosync);

    /// <summary>
    /// set autosync mode
    /// </summary>
    public void set_autosync (bool autosync)
    {
      int r;
      r = guestfs_set_autosync (_handle, autosync);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_set_backend (IntPtr h, [In] string backend);

    /// <summary>
    /// set the backend
    /// </summary>
    public void set_backend (string backend)
    {
      int r;
      r = guestfs_set_backend (_handle, backend);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_set_backend_setting (IntPtr h, [In] string name, [In] string val);

    /// <summary>
    /// set a single per-backend settings string
    /// </summary>
    public void set_backend_setting (string name, string val)
    {
      int r;
      r = guestfs_set_backend_setting (_handle, name, val);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_set_backend_settings (IntPtr h, [In] string[] settings);

    /// <summary>
    /// replace per-backend settings strings
    /// </summary>
    public void set_backend_settings (string[] settings)
    {
      int r;
      r = guestfs_set_backend_settings (_handle, settings);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_set_cachedir (IntPtr h, [In] string cachedir);

    /// <summary>
    /// set the appliance cache directory
    /// </summary>
    public void set_cachedir (string cachedir)
    {
      int r;
      r = guestfs_set_cachedir (_handle, cachedir);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_set_direct (IntPtr h, bool direct);

    /// <summary>
    /// enable or disable direct appliance mode
    /// </summary>
    public void set_direct (bool direct)
    {
      int r;
      r = guestfs_set_direct (_handle, direct);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_set_e2attrs_argv (IntPtr h, [In] string file, [In] string attrs, void *);

    /// <summary>
    /// set ext2 file attributes of a file
    /// </summary>
    public void set_e2attrs (string file, string attrs)
    {
      int r;
      r = guestfs_set_e2attrs_argv (_handle, file, attrs, NULL);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_set_e2generation (IntPtr h, [In] string file, long generation);

    /// <summary>
    /// set ext2 file generation of a file
    /// </summary>
    public void set_e2generation (string file, long generation)
    {
      int r;
      r = guestfs_set_e2generation (_handle, file, generation);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_set_e2label (IntPtr h, [In] string device, [In] string label);

    /// <summary>
    /// set the ext2/3/4 filesystem label
    /// </summary>
    public void set_e2label (string device, string label)
    {
      int r;
      r = guestfs_set_e2label (_handle, device, label);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_set_e2uuid (IntPtr h, [In] string device, [In] string uuid);

    /// <summary>
    /// set the ext2/3/4 filesystem UUID
    /// </summary>
    public void set_e2uuid (string device, string uuid)
    {
      int r;
      r = guestfs_set_e2uuid (_handle, device, uuid);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_set_hv (IntPtr h, [In] string hv);

    /// <summary>
    /// set the hypervisor binary
    /// </summary>
    public void set_hv (string hv)
    {
      int r;
      r = guestfs_set_hv (_handle, hv);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_set_label (IntPtr h, [In] string mountable, [In] string label);

    /// <summary>
    /// set filesystem label
    /// </summary>
    public void set_label (string mountable, string label)
    {
      int r;
      r = guestfs_set_label (_handle, mountable, label);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_set_libvirt_requested_credential (IntPtr h, int index, [In] string cred);

    /// <summary>
    /// pass requested credential back to libvirt
    /// </summary>
    public void set_libvirt_requested_credential (int index, string cred)
    {
      int r;
      r = guestfs_set_libvirt_requested_credential (_handle, index, cred);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_set_libvirt_supported_credentials (IntPtr h, [In] string[] creds);

    /// <summary>
    /// set libvirt credentials supported by calling program
    /// </summary>
    public void set_libvirt_supported_credentials (string[] creds)
    {
      int r;
      r = guestfs_set_libvirt_supported_credentials (_handle, creds);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_set_memsize (IntPtr h, int memsize);

    /// <summary>
    /// set memory allocated to the hypervisor
    /// </summary>
    public void set_memsize (int memsize)
    {
      int r;
      r = guestfs_set_memsize (_handle, memsize);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_set_network (IntPtr h, bool network);

    /// <summary>
    /// set enable network flag
    /// </summary>
    public void set_network (bool network)
    {
      int r;
      r = guestfs_set_network (_handle, network);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_set_path (IntPtr h, [In] string searchpath);

    /// <summary>
    /// set the search path
    /// </summary>
    public void set_path (string searchpath)
    {
      int r;
      r = guestfs_set_path (_handle, searchpath);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_set_pgroup (IntPtr h, bool pgroup);

    /// <summary>
    /// set process group flag
    /// </summary>
    public void set_pgroup (bool pgroup)
    {
      int r;
      r = guestfs_set_pgroup (_handle, pgroup);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_set_program (IntPtr h, [In] string program);

    /// <summary>
    /// set the program name
    /// </summary>
    public void set_program (string program)
    {
      int r;
      r = guestfs_set_program (_handle, program);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_set_qemu (IntPtr h, [In] string hv);

    /// <summary>
    /// set the hypervisor binary (usually qemu)
    /// </summary>
    public void set_qemu (string hv)
    {
      int r;
      r = guestfs_set_qemu (_handle, hv);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_set_recovery_proc (IntPtr h, bool recoveryproc);

    /// <summary>
    /// enable or disable the recovery process
    /// </summary>
    public void set_recovery_proc (bool recoveryproc)
    {
      int r;
      r = guestfs_set_recovery_proc (_handle, recoveryproc);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_set_selinux (IntPtr h, bool selinux);

    /// <summary>
    /// set SELinux enabled or disabled at appliance boot
    /// </summary>
    public void set_selinux (bool selinux)
    {
      int r;
      r = guestfs_set_selinux (_handle, selinux);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_set_smp (IntPtr h, int smp);

    /// <summary>
    /// set number of virtual CPUs in appliance
    /// </summary>
    public void set_smp (int smp)
    {
      int r;
      r = guestfs_set_smp (_handle, smp);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_set_tmpdir (IntPtr h, [In] string tmpdir);

    /// <summary>
    /// set the temporary directory
    /// </summary>
    public void set_tmpdir (string tmpdir)
    {
      int r;
      r = guestfs_set_tmpdir (_handle, tmpdir);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_set_trace (IntPtr h, bool trace);

    /// <summary>
    /// enable or disable command traces
    /// </summary>
    public void set_trace (bool trace)
    {
      int r;
      r = guestfs_set_trace (_handle, trace);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_set_uuid (IntPtr h, [In] string device, [In] string uuid);

    /// <summary>
    /// set the filesystem UUID
    /// </summary>
    public void set_uuid (string device, string uuid)
    {
      int r;
      r = guestfs_set_uuid (_handle, device, uuid);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_set_verbose (IntPtr h, bool verbose);

    /// <summary>
    /// set verbose mode
    /// </summary>
    public void set_verbose (bool verbose)
    {
      int r;
      r = guestfs_set_verbose (_handle, verbose);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_setcon (IntPtr h, [In] string context);

    /// <summary>
    /// set SELinux security context
    /// </summary>
    public void setcon (string context)
    {
      int r;
      r = guestfs_setcon (_handle, context);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_setxattr (IntPtr h, [In] string xattr, [In] string val, int vallen, [In] string path);

    /// <summary>
    /// set extended attribute of a file or directory
    /// </summary>
    public void setxattr (string xattr, string val, int vallen, string path)
    {
      int r;
      r = guestfs_setxattr (_handle, xattr, val, vallen, path);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_sfdisk (IntPtr h, [In] string device, int cyls, int heads, int sectors, [In] string[] lines);

    /// <summary>
    /// create partitions on a block device
    /// </summary>
    public void sfdisk (string device, int cyls, int heads, int sectors, string[] lines)
    {
      int r;
      r = guestfs_sfdisk (_handle, device, cyls, heads, sectors, lines);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_sfdiskM (IntPtr h, [In] string device, [In] string[] lines);

    /// <summary>
    /// create partitions on a block device
    /// </summary>
    public void sfdiskM (string device, string[] lines)
    {
      int r;
      r = guestfs_sfdiskM (_handle, device, lines);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_sfdisk_N (IntPtr h, [In] string device, int partnum, int cyls, int heads, int sectors, [In] string line);

    /// <summary>
    /// modify a single partition on a block device
    /// </summary>
    public void sfdisk_N (string device, int partnum, int cyls, int heads, int sectors, string line)
    {
      int r;
      r = guestfs_sfdisk_N (_handle, device, partnum, cyls, heads, sectors, line);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern string guestfs_sfdisk_disk_geometry (IntPtr h, [In] string device);

    /// <summary>
    /// display the disk geometry from the partition table
    /// </summary>
    public string sfdisk_disk_geometry (string device)
    {
      string r;
      r = guestfs_sfdisk_disk_geometry (_handle, device);
      if (r == null)
        throw new Error (guestfs_last_error (_handle));
      return r;
    }

    [DllImport ("libguestfs.so.0")]
    static extern string guestfs_sfdisk_kernel_geometry (IntPtr h, [In] string device);

    /// <summary>
    /// display the kernel geometry
    /// </summary>
    public string sfdisk_kernel_geometry (string device)
    {
      string r;
      r = guestfs_sfdisk_kernel_geometry (_handle, device);
      if (r == null)
        throw new Error (guestfs_last_error (_handle));
      return r;
    }

    [DllImport ("libguestfs.so.0")]
    static extern string guestfs_sfdisk_l (IntPtr h, [In] string device);

    /// <summary>
    /// display the partition table
    /// </summary>
    public string sfdisk_l (string device)
    {
      string r;
      r = guestfs_sfdisk_l (_handle, device);
      if (r == null)
        throw new Error (guestfs_last_error (_handle));
      return r;
    }

    [DllImport ("libguestfs.so.0")]
    static extern string guestfs_sh (IntPtr h, [In] string command);

    /// <summary>
    /// run a command via the shell
    /// </summary>
    public string sh (string command)
    {
      string r;
      r = guestfs_sh (_handle, command);
      if (r == null)
        throw new Error (guestfs_last_error (_handle));
      return r;
    }

    [DllImport ("libguestfs.so.0")]
    static extern string[] guestfs_sh_lines (IntPtr h, [In] string command);

    /// <summary>
    /// run a command via the shell returning lines
    /// </summary>
    public string[] sh_lines (string command)
    {
      string[] r;
      r = guestfs_sh_lines (_handle, command);
      if (r == null)
        throw new Error (guestfs_last_error (_handle));
      return r;
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_shutdown (IntPtr h);

    /// <summary>
    /// shutdown the hypervisor
    /// </summary>
    public void shutdown ()
    {
      int r;
      r = guestfs_shutdown (_handle);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_sleep (IntPtr h, int secs);

    /// <summary>
    /// sleep for some seconds
    /// </summary>
    public void sleep (int secs)
    {
      int r;
      r = guestfs_sleep (_handle, secs);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern _stat guestfs_stat (IntPtr h, [In] string path);

    /// <summary>
    /// get file information
    /// </summary>
    public _stat stat (string path)
    {
      _stat r;
      r = guestfs_stat (_handle, path);
      if (r == null)
        throw new Error (guestfs_last_error (_handle));
      return r;
    }

    [DllImport ("libguestfs.so.0")]
    static extern _statns guestfs_statns (IntPtr h, [In] string path);

    /// <summary>
    /// get file information
    /// </summary>
    public _statns statns (string path)
    {
      _statns r;
      r = guestfs_statns (_handle, path);
      if (r == null)
        throw new Error (guestfs_last_error (_handle));
      return r;
    }

    [DllImport ("libguestfs.so.0")]
    static extern _statvfs guestfs_statvfs (IntPtr h, [In] string path);

    /// <summary>
    /// get file system statistics
    /// </summary>
    public _statvfs statvfs (string path)
    {
      _statvfs r;
      r = guestfs_statvfs (_handle, path);
      if (r == null)
        throw new Error (guestfs_last_error (_handle));
      return r;
    }

    [DllImport ("libguestfs.so.0")]
    static extern string[] guestfs_strings (IntPtr h, [In] string path);

    /// <summary>
    /// print the printable strings in a file
    /// </summary>
    public string[] strings (string path)
    {
      string[] r;
      r = guestfs_strings (_handle, path);
      if (r == null)
        throw new Error (guestfs_last_error (_handle));
      return r;
    }

    [DllImport ("libguestfs.so.0")]
    static extern string[] guestfs_strings_e (IntPtr h, [In] string encoding, [In] string path);

    /// <summary>
    /// print the printable strings in a file
    /// </summary>
    public string[] strings_e (string encoding, string path)
    {
      string[] r;
      r = guestfs_strings_e (_handle, encoding, path);
      if (r == null)
        throw new Error (guestfs_last_error (_handle));
      return r;
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_swapoff_device (IntPtr h, [In] string device);

    /// <summary>
    /// disable swap on device
    /// </summary>
    public void swapoff_device (string device)
    {
      int r;
      r = guestfs_swapoff_device (_handle, device);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_swapoff_file (IntPtr h, [In] string file);

    /// <summary>
    /// disable swap on file
    /// </summary>
    public void swapoff_file (string file)
    {
      int r;
      r = guestfs_swapoff_file (_handle, file);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_swapoff_label (IntPtr h, [In] string label);

    /// <summary>
    /// disable swap on labeled swap partition
    /// </summary>
    public void swapoff_label (string label)
    {
      int r;
      r = guestfs_swapoff_label (_handle, label);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_swapoff_uuid (IntPtr h, [In] string uuid);

    /// <summary>
    /// disable swap on swap partition by UUID
    /// </summary>
    public void swapoff_uuid (string uuid)
    {
      int r;
      r = guestfs_swapoff_uuid (_handle, uuid);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_swapon_device (IntPtr h, [In] string device);

    /// <summary>
    /// enable swap on device
    /// </summary>
    public void swapon_device (string device)
    {
      int r;
      r = guestfs_swapon_device (_handle, device);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_swapon_file (IntPtr h, [In] string file);

    /// <summary>
    /// enable swap on file
    /// </summary>
    public void swapon_file (string file)
    {
      int r;
      r = guestfs_swapon_file (_handle, file);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_swapon_label (IntPtr h, [In] string label);

    /// <summary>
    /// enable swap on labeled swap partition
    /// </summary>
    public void swapon_label (string label)
    {
      int r;
      r = guestfs_swapon_label (_handle, label);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_swapon_uuid (IntPtr h, [In] string uuid);

    /// <summary>
    /// enable swap on swap partition by UUID
    /// </summary>
    public void swapon_uuid (string uuid)
    {
      int r;
      r = guestfs_swapon_uuid (_handle, uuid);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_sync (IntPtr h);

    /// <summary>
    /// sync disks, writes are flushed through to the disk image
    /// </summary>
    public void sync ()
    {
      int r;
      r = guestfs_sync (_handle);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_syslinux_argv (IntPtr h, [In] string device, void *);

    /// <summary>
    /// install the SYSLINUX bootloader
    /// </summary>
    public void syslinux (string device)
    {
      int r;
      r = guestfs_syslinux_argv (_handle, device, NULL);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern string[] guestfs_tail (IntPtr h, [In] string path);

    /// <summary>
    /// return last 10 lines of a file
    /// </summary>
    public string[] tail (string path)
    {
      string[] r;
      r = guestfs_tail (_handle, path);
      if (r == null)
        throw new Error (guestfs_last_error (_handle));
      return r;
    }

    [DllImport ("libguestfs.so.0")]
    static extern string[] guestfs_tail_n (IntPtr h, int nrlines, [In] string path);

    /// <summary>
    /// return last N lines of a file
    /// </summary>
    public string[] tail_n (int nrlines, string path)
    {
      string[] r;
      r = guestfs_tail_n (_handle, nrlines, path);
      if (r == null)
        throw new Error (guestfs_last_error (_handle));
      return r;
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_tar_in_opts_argv (IntPtr h, [In] string tarfile, [In] string directory, void *);

    /// <summary>
    /// unpack tarfile to directory
    /// </summary>
    public void tar_in (string tarfile, string directory)
    {
      int r;
      r = guestfs_tar_in_opts_argv (_handle, tarfile, directory, NULL);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    public void tar_in_opts (string tarfile, string directory)
    {
      tar_in (tarfile, directory);
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_tar_out_opts_argv (IntPtr h, [In] string directory, [In] string tarfile, void *);

    /// <summary>
    /// pack directory into tarfile
    /// </summary>
    public void tar_out (string directory, string tarfile)
    {
      int r;
      r = guestfs_tar_out_opts_argv (_handle, directory, tarfile, NULL);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    public void tar_out_opts (string directory, string tarfile)
    {
      tar_out (directory, tarfile);
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_tgz_in (IntPtr h, [In] string tarball, [In] string directory);

    /// <summary>
    /// unpack compressed tarball to directory
    /// </summary>
    public void tgz_in (string tarball, string directory)
    {
      int r;
      r = guestfs_tgz_in (_handle, tarball, directory);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_tgz_out (IntPtr h, [In] string directory, [In] string tarball);

    /// <summary>
    /// pack directory into compressed tarball
    /// </summary>
    public void tgz_out (string directory, string tarball)
    {
      int r;
      r = guestfs_tgz_out (_handle, directory, tarball);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_touch (IntPtr h, [In] string path);

    /// <summary>
    /// update file timestamps or create a new file
    /// </summary>
    public void touch (string path)
    {
      int r;
      r = guestfs_touch (_handle, path);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_truncate (IntPtr h, [In] string path);

    /// <summary>
    /// truncate a file to zero size
    /// </summary>
    public void truncate (string path)
    {
      int r;
      r = guestfs_truncate (_handle, path);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_truncate_size (IntPtr h, [In] string path, long size);

    /// <summary>
    /// truncate a file to a particular size
    /// </summary>
    public void truncate_size (string path, long size)
    {
      int r;
      r = guestfs_truncate_size (_handle, path, size);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_tune2fs_argv (IntPtr h, [In] string device, void *);

    /// <summary>
    /// adjust ext2/ext3/ext4 filesystem parameters
    /// </summary>
    public void tune2fs (string device)
    {
      int r;
      r = guestfs_tune2fs_argv (_handle, device, NULL);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern string[] guestfs_tune2fs_l (IntPtr h, [In] string device);

    /// <summary>
    /// get ext2/ext3/ext4 superblock details
    /// </summary>
    public Hashtable tune2fs_l (string device)
    {
      string[] r;
      r = guestfs_tune2fs_l (_handle, device);
      if (r == null)
        throw new Error (guestfs_last_error (_handle));
      Hashtable rr = new Hashtable ();
      for (size_t i = 0; i < r.Length; i += 2)
        rr.Add (r[i], r[i+1]);
      return rr;
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_txz_in (IntPtr h, [In] string tarball, [In] string directory);

    /// <summary>
    /// unpack compressed tarball to directory
    /// </summary>
    public void txz_in (string tarball, string directory)
    {
      int r;
      r = guestfs_txz_in (_handle, tarball, directory);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_txz_out (IntPtr h, [In] string directory, [In] string tarball);

    /// <summary>
    /// pack directory into compressed tarball
    /// </summary>
    public void txz_out (string directory, string tarball)
    {
      int r;
      r = guestfs_txz_out (_handle, directory, tarball);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_umask (IntPtr h, int mask);

    /// <summary>
    /// set file mode creation mask (umask)
    /// </summary>
    public int umask (int mask)
    {
      int r;
      r = guestfs_umask (_handle, mask);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
      return r;
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_umount_opts_argv (IntPtr h, [In] string pathordevice, void *);

    /// <summary>
    /// unmount a filesystem
    /// </summary>
    public void umount (string pathordevice)
    {
      int r;
      r = guestfs_umount_opts_argv (_handle, pathordevice, NULL);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    public void umount_opts (string pathordevice)
    {
      umount (pathordevice);
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_umount_all (IntPtr h);

    /// <summary>
    /// unmount all filesystems
    /// </summary>
    public void umount_all ()
    {
      int r;
      r = guestfs_umount_all (_handle);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_umount_local_argv (IntPtr h, void *);

    /// <summary>
    /// unmount a locally mounted filesystem
    /// </summary>
    public void umount_local ()
    {
      int r;
      r = guestfs_umount_local_argv (_handle, NULL);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_upload (IntPtr h, [In] string filename, [In] string remotefilename);

    /// <summary>
    /// upload a file from the local machine
    /// </summary>
    public void upload (string filename, string remotefilename)
    {
      int r;
      r = guestfs_upload (_handle, filename, remotefilename);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_upload_offset (IntPtr h, [In] string filename, [In] string remotefilename, long offset);

    /// <summary>
    /// upload a file from the local machine with offset
    /// </summary>
    public void upload_offset (string filename, string remotefilename, long offset)
    {
      int r;
      r = guestfs_upload_offset (_handle, filename, remotefilename, offset);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_user_cancel (IntPtr h);

    /// <summary>
    /// cancel the current upload or download operation
    /// </summary>
    public void user_cancel ()
    {
      int r;
      r = guestfs_user_cancel (_handle);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_utimens (IntPtr h, [In] string path, long atsecs, long atnsecs, long mtsecs, long mtnsecs);

    /// <summary>
    /// set timestamp of a file with nanosecond precision
    /// </summary>
    public void utimens (string path, long atsecs, long atnsecs, long mtsecs, long mtnsecs)
    {
      int r;
      r = guestfs_utimens (_handle, path, atsecs, atnsecs, mtsecs, mtnsecs);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern _utsname guestfs_utsname (IntPtr h);

    /// <summary>
    /// appliance kernel version
    /// </summary>
    public _utsname utsname ()
    {
      _utsname r;
      r = guestfs_utsname (_handle);
      if (r == null)
        throw new Error (guestfs_last_error (_handle));
      return r;
    }

    [DllImport ("libguestfs.so.0")]
    static extern _version guestfs_version (IntPtr h);

    /// <summary>
    /// get the library version number
    /// </summary>
    public _version version ()
    {
      _version r;
      r = guestfs_version (_handle);
      if (r == null)
        throw new Error (guestfs_last_error (_handle));
      return r;
    }

    [DllImport ("libguestfs.so.0")]
    static extern string guestfs_vfs_label (IntPtr h, [In] string mountable);

    /// <summary>
    /// get the filesystem label
    /// </summary>
    public string vfs_label (string mountable)
    {
      string r;
      r = guestfs_vfs_label (_handle, mountable);
      if (r == null)
        throw new Error (guestfs_last_error (_handle));
      return r;
    }

    [DllImport ("libguestfs.so.0")]
    static extern string guestfs_vfs_type (IntPtr h, [In] string mountable);

    /// <summary>
    /// get the Linux VFS type corresponding to a mounted device
    /// </summary>
    public string vfs_type (string mountable)
    {
      string r;
      r = guestfs_vfs_type (_handle, mountable);
      if (r == null)
        throw new Error (guestfs_last_error (_handle));
      return r;
    }

    [DllImport ("libguestfs.so.0")]
    static extern string guestfs_vfs_uuid (IntPtr h, [In] string mountable);

    /// <summary>
    /// get the filesystem UUID
    /// </summary>
    public string vfs_uuid (string mountable)
    {
      string r;
      r = guestfs_vfs_uuid (_handle, mountable);
      if (r == null)
        throw new Error (guestfs_last_error (_handle));
      return r;
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_vg_activate (IntPtr h, bool activate, [In] string[] volgroups);

    /// <summary>
    /// activate or deactivate some volume groups
    /// </summary>
    public void vg_activate (bool activate, string[] volgroups)
    {
      int r;
      r = guestfs_vg_activate (_handle, activate, volgroups);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_vg_activate_all (IntPtr h, bool activate);

    /// <summary>
    /// activate or deactivate all volume groups
    /// </summary>
    public void vg_activate_all (bool activate)
    {
      int r;
      r = guestfs_vg_activate_all (_handle, activate);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_vgchange_uuid (IntPtr h, [In] string vg);

    /// <summary>
    /// generate a new random UUID for a volume group
    /// </summary>
    public void vgchange_uuid (string vg)
    {
      int r;
      r = guestfs_vgchange_uuid (_handle, vg);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_vgchange_uuid_all (IntPtr h);

    /// <summary>
    /// generate new random UUIDs for all volume groups
    /// </summary>
    public void vgchange_uuid_all ()
    {
      int r;
      r = guestfs_vgchange_uuid_all (_handle);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_vgcreate (IntPtr h, [In] string volgroup, [In] string[] physvols);

    /// <summary>
    /// create an LVM volume group
    /// </summary>
    public void vgcreate (string volgroup, string[] physvols)
    {
      int r;
      r = guestfs_vgcreate (_handle, volgroup, physvols);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern string[] guestfs_vglvuuids (IntPtr h, [In] string vgname);

    /// <summary>
    /// get the LV UUIDs of all LVs in the volume group
    /// </summary>
    public string[] vglvuuids (string vgname)
    {
      string[] r;
      r = guestfs_vglvuuids (_handle, vgname);
      if (r == null)
        throw new Error (guestfs_last_error (_handle));
      return r;
    }

    [DllImport ("libguestfs.so.0")]
    static extern string guestfs_vgmeta (IntPtr h, [In] string vgname);

    /// <summary>
    /// get volume group metadata
    /// </summary>
    public string vgmeta (string vgname)
    {
      string r;
      r = guestfs_vgmeta (_handle, vgname);
      if (r == null)
        throw new Error (guestfs_last_error (_handle));
      return r;
    }

    [DllImport ("libguestfs.so.0")]
    static extern string[] guestfs_vgpvuuids (IntPtr h, [In] string vgname);

    /// <summary>
    /// get the PV UUIDs containing the volume group
    /// </summary>
    public string[] vgpvuuids (string vgname)
    {
      string[] r;
      r = guestfs_vgpvuuids (_handle, vgname);
      if (r == null)
        throw new Error (guestfs_last_error (_handle));
      return r;
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_vgremove (IntPtr h, [In] string vgname);

    /// <summary>
    /// remove an LVM volume group
    /// </summary>
    public void vgremove (string vgname)
    {
      int r;
      r = guestfs_vgremove (_handle, vgname);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_vgrename (IntPtr h, [In] string volgroup, [In] string newvolgroup);

    /// <summary>
    /// rename an LVM volume group
    /// </summary>
    public void vgrename (string volgroup, string newvolgroup)
    {
      int r;
      r = guestfs_vgrename (_handle, volgroup, newvolgroup);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern string[] guestfs_vgs (IntPtr h);

    /// <summary>
    /// list the LVM volume groups (VGs)
    /// </summary>
    public string[] vgs ()
    {
      string[] r;
      r = guestfs_vgs (_handle);
      if (r == null)
        throw new Error (guestfs_last_error (_handle));
      return r;
    }

    [DllImport ("libguestfs.so.0")]
    static extern _lvm_vg[] guestfs_vgs_full (IntPtr h);

    /// <summary>
    /// list the LVM volume groups (VGs)
    /// </summary>
    public _lvm_vg[] vgs_full ()
    {
      _lvm_vg[] r;
      r = guestfs_vgs_full (_handle);
      if (r == null)
        throw new Error (guestfs_last_error (_handle));
      return r;
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_vgscan (IntPtr h);

    /// <summary>
    /// rescan for LVM physical volumes, volume groups and logical volumes
    /// </summary>
    public void vgscan ()
    {
      int r;
      r = guestfs_vgscan (_handle);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern string guestfs_vguuid (IntPtr h, [In] string vgname);

    /// <summary>
    /// get the UUID of a volume group
    /// </summary>
    public string vguuid (string vgname)
    {
      string r;
      r = guestfs_vguuid (_handle, vgname);
      if (r == null)
        throw new Error (guestfs_last_error (_handle));
      return r;
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_wait_ready (IntPtr h);

    /// <summary>
    /// wait until the hypervisor launches (no op)
    /// </summary>
    public void wait_ready ()
    {
      int r;
      r = guestfs_wait_ready (_handle);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_wc_c (IntPtr h, [In] string path);

    /// <summary>
    /// count characters in a file
    /// </summary>
    public int wc_c (string path)
    {
      int r;
      r = guestfs_wc_c (_handle, path);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
      return r;
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_wc_l (IntPtr h, [In] string path);

    /// <summary>
    /// count lines in a file
    /// </summary>
    public int wc_l (string path)
    {
      int r;
      r = guestfs_wc_l (_handle, path);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
      return r;
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_wc_w (IntPtr h, [In] string path);

    /// <summary>
    /// count words in a file
    /// </summary>
    public int wc_w (string path)
    {
      int r;
      r = guestfs_wc_w (_handle, path);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
      return r;
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_wipefs (IntPtr h, [In] string device);

    /// <summary>
    /// wipe a filesystem signature from a device
    /// </summary>
    public void wipefs (string device)
    {
      int r;
      r = guestfs_wipefs (_handle, device);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_write (IntPtr h, [In] string path, [In] string content);

    /// <summary>
    /// create a new file
    /// </summary>
    public void write (string path, string content)
    {
      int r;
      r = guestfs_write (_handle, path, content);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_write_append (IntPtr h, [In] string path, [In] string content);

    /// <summary>
    /// append content to end of file
    /// </summary>
    public void write_append (string path, string content)
    {
      int r;
      r = guestfs_write_append (_handle, path, content);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_write_file (IntPtr h, [In] string path, [In] string content, int size);

    /// <summary>
    /// create a file
    /// </summary>
    public void write_file (string path, string content, int size)
    {
      int r;
      r = guestfs_write_file (_handle, path, content, size);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_xfs_admin_argv (IntPtr h, [In] string device, void *);

    /// <summary>
    /// change parameters of an XFS filesystem
    /// </summary>
    public void xfs_admin (string device)
    {
      int r;
      r = guestfs_xfs_admin_argv (_handle, device, NULL);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_xfs_growfs_argv (IntPtr h, [In] string path, void *);

    /// <summary>
    /// expand an existing XFS filesystem
    /// </summary>
    public void xfs_growfs (string path)
    {
      int r;
      r = guestfs_xfs_growfs_argv (_handle, path, NULL);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern _xfsinfo guestfs_xfs_info (IntPtr h, [In] string pathordevice);

    /// <summary>
    /// get geometry of XFS filesystem
    /// </summary>
    public _xfsinfo xfs_info (string pathordevice)
    {
      _xfsinfo r;
      r = guestfs_xfs_info (_handle, pathordevice);
      if (r == null)
        throw new Error (guestfs_last_error (_handle));
      return r;
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_xfs_repair_argv (IntPtr h, [In] string device, void *);

    /// <summary>
    /// repair an XFS filesystem
    /// </summary>
    public int xfs_repair (string device)
    {
      int r;
      r = guestfs_xfs_repair_argv (_handle, device, NULL);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
      return r;
    }

    [DllImport ("libguestfs.so.0")]
    static extern string[] guestfs_zegrep (IntPtr h, [In] string regex, [In] string path);

    /// <summary>
    /// return lines matching a pattern
    /// </summary>
    public string[] zegrep (string regex, string path)
    {
      string[] r;
      r = guestfs_zegrep (_handle, regex, path);
      if (r == null)
        throw new Error (guestfs_last_error (_handle));
      return r;
    }

    [DllImport ("libguestfs.so.0")]
    static extern string[] guestfs_zegrepi (IntPtr h, [In] string regex, [In] string path);

    /// <summary>
    /// return lines matching a pattern
    /// </summary>
    public string[] zegrepi (string regex, string path)
    {
      string[] r;
      r = guestfs_zegrepi (_handle, regex, path);
      if (r == null)
        throw new Error (guestfs_last_error (_handle));
      return r;
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_zero (IntPtr h, [In] string device);

    /// <summary>
    /// write zeroes to the device
    /// </summary>
    public void zero (string device)
    {
      int r;
      r = guestfs_zero (_handle, device);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_zero_device (IntPtr h, [In] string device);

    /// <summary>
    /// write zeroes to an entire device
    /// </summary>
    public void zero_device (string device)
    {
      int r;
      r = guestfs_zero_device (_handle, device);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_zero_free_space (IntPtr h, [In] string directory);

    /// <summary>
    /// zero free space in a filesystem
    /// </summary>
    public void zero_free_space (string directory)
    {
      int r;
      r = guestfs_zero_free_space (_handle, directory);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern int guestfs_zerofree (IntPtr h, [In] string device);

    /// <summary>
    /// zero unused inodes and disk blocks on ext2/3 filesystem
    /// </summary>
    public void zerofree (string device)
    {
      int r;
      r = guestfs_zerofree (_handle, device);
      if (r == -1)
        throw new Error (guestfs_last_error (_handle));
    }

    [DllImport ("libguestfs.so.0")]
    static extern string[] guestfs_zfgrep (IntPtr h, [In] string pattern, [In] string path);

    /// <summary>
    /// return lines matching a pattern
    /// </summary>
    public string[] zfgrep (string pattern, string path)
    {
      string[] r;
      r = guestfs_zfgrep (_handle, pattern, path);
      if (r == null)
        throw new Error (guestfs_last_error (_handle));
      return r;
    }

    [DllImport ("libguestfs.so.0")]
    static extern string[] guestfs_zfgrepi (IntPtr h, [In] string pattern, [In] string path);

    /// <summary>
    /// return lines matching a pattern
    /// </summary>
    public string[] zfgrepi (string pattern, string path)
    {
      string[] r;
      r = guestfs_zfgrepi (_handle, pattern, path);
      if (r == null)
        throw new Error (guestfs_last_error (_handle));
      return r;
    }

    [DllImport ("libguestfs.so.0")]
    static extern string guestfs_zfile (IntPtr h, [In] string meth, [In] string path);

    /// <summary>
    /// determine file type inside a compressed file
    /// </summary>
    public string zfile (string meth, string path)
    {
      string r;
      r = guestfs_zfile (_handle, meth, path);
      if (r == null)
        throw new Error (guestfs_last_error (_handle));
      return r;
    }

    [DllImport ("libguestfs.so.0")]
    static extern string[] guestfs_zgrep (IntPtr h, [In] string regex, [In] string path);

    /// <summary>
    /// return lines matching a pattern
    /// </summary>
    public string[] zgrep (string regex, string path)
    {
      string[] r;
      r = guestfs_zgrep (_handle, regex, path);
      if (r == null)
        throw new Error (guestfs_last_error (_handle));
      return r;
    }

    [DllImport ("libguestfs.so.0")]
    static extern string[] guestfs_zgrepi (IntPtr h, [In] string regex, [In] string path);

    /// <summary>
    /// return lines matching a pattern
    /// </summary>
    public string[] zgrepi (string regex, string path)
    {
      string[] r;
      r = guestfs_zgrepi (_handle, regex, path);
      if (r == null)
        throw new Error (guestfs_last_error (_handle));
      return r;
    }

  }
}
