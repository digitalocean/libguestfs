/* libguestfs generated file
 * WARNING: THIS FILE IS GENERATED FROM:
 *   generator/generator_*.ml
 * ANY CHANGES YOU MAKE TO THIS FILE WILL BE LOST.
 *
 * Copyright (C) 2009-2012 Red Hat Inc.
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

package com.redhat.et.libguestfs;

import java.util.HashMap;
import java.util.Map;

/**
 * The GuestFS object is a libguestfs handle.
 *
 * @author rjones
 */
public class GuestFS {
  // Load the native code.
  static {
    System.loadLibrary ("guestfs_jni");
  }

  /**
   * The native guestfs_h pointer.
   */
  long g;

  /**
   * Create a libguestfs handle.
   *
   * @throws LibGuestFSException
   */
  public GuestFS () throws LibGuestFSException
  {
    g = _create ();
  }
  private native long _create () throws LibGuestFSException;

  /**
   * Close a libguestfs handle.
   *
   * You can also leave handles to be collected by the garbage
   * collector, but this method ensures that the resources used
   * by the handle are freed up immediately.  If you call any
   * other methods after closing the handle, you will get an
   * exception.
   *
   * @throws LibGuestFSException
   */
  public void close () throws LibGuestFSException
  {
    if (g != 0)
      _close (g);
    g = 0;
  }
  private native void _close (long g) throws LibGuestFSException;

  public void finalize () throws LibGuestFSException
  {
    close ();
  }

  public void test0 (String str, String optstr, String[] strlist, boolean b, int integer, long integer64, String filein, String fileout, byte[] bufferin, Map<String, Object> optargs)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("test0: handle is closed");

    /* Unpack optional args. */
    Object _optobj;
    long _optargs_bitmask = 0;
    boolean obool = false;
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("obool");
    if (_optobj != null) {
      obool = ((Boolean) _optobj).booleanValue();
      _optargs_bitmask |= 1L;
    }
    int oint = 0;
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("oint");
    if (_optobj != null) {
      oint = ((Integer) _optobj).intValue();
      _optargs_bitmask |= 2L;
    }
    long oint64 = 0;
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("oint64");
    if (_optobj != null) {
      oint64 = ((Long) _optobj).longValue();
      _optargs_bitmask |= 4L;
    }
    String ostring = "";
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("ostring");
    if (_optobj != null) {
      ostring = ((String) _optobj);
      _optargs_bitmask |= 8L;
    }

    _test0 (g, str, optstr, strlist, b, integer, integer64, filein, fileout, bufferin, _optargs_bitmask, obool, oint, oint64, ostring);
  }

  public void test0 (String str, String optstr, String[] strlist, boolean b, int integer, long integer64, String filein, String fileout, byte[] bufferin)
    throws LibGuestFSException
  {
    test0 (str, optstr, strlist, b, integer, integer64, filein, fileout, bufferin, null);
  }

  private native void _test0 (long g, String str, String optstr, String[] strlist, boolean b, int integer, long integer64, String filein, String fileout, byte[] bufferin, long _optargs_bitmask, boolean obool, int oint, long oint64, String ostring)
    throws LibGuestFSException;

  public int test0rint (String val)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("test0rint: handle is closed");

    return _test0rint (g, val);
  }

  private native int _test0rint (long g, String val)
    throws LibGuestFSException;

  public int test0rinterr ()
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("test0rinterr: handle is closed");

    return _test0rinterr (g);
  }

  private native int _test0rinterr (long g)
    throws LibGuestFSException;

  public long test0rint64 (String val)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("test0rint64: handle is closed");

    return _test0rint64 (g, val);
  }

  private native long _test0rint64 (long g, String val)
    throws LibGuestFSException;

  public long test0rint64err ()
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("test0rint64err: handle is closed");

    return _test0rint64err (g);
  }

  private native long _test0rint64err (long g)
    throws LibGuestFSException;

  public boolean test0rbool (String val)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("test0rbool: handle is closed");

    return _test0rbool (g, val);
  }

  private native boolean _test0rbool (long g, String val)
    throws LibGuestFSException;

  public boolean test0rboolerr ()
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("test0rboolerr: handle is closed");

    return _test0rboolerr (g);
  }

  private native boolean _test0rboolerr (long g)
    throws LibGuestFSException;

  public String test0rconststring (String val)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("test0rconststring: handle is closed");

    return _test0rconststring (g, val);
  }

  private native String _test0rconststring (long g, String val)
    throws LibGuestFSException;

  public String test0rconststringerr ()
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("test0rconststringerr: handle is closed");

    return _test0rconststringerr (g);
  }

  private native String _test0rconststringerr (long g)
    throws LibGuestFSException;

  public String test0rconstoptstring (String val)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("test0rconstoptstring: handle is closed");

    return _test0rconstoptstring (g, val);
  }

  private native String _test0rconstoptstring (long g, String val)
    throws LibGuestFSException;

  public String test0rconstoptstringerr ()
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("test0rconstoptstringerr: handle is closed");

    return _test0rconstoptstringerr (g);
  }

  private native String _test0rconstoptstringerr (long g)
    throws LibGuestFSException;

  public String test0rstring (String val)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("test0rstring: handle is closed");

    return _test0rstring (g, val);
  }

  private native String _test0rstring (long g, String val)
    throws LibGuestFSException;

  public String test0rstringerr ()
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("test0rstringerr: handle is closed");

    return _test0rstringerr (g);
  }

  private native String _test0rstringerr (long g)
    throws LibGuestFSException;

  public String[] test0rstringlist (String val)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("test0rstringlist: handle is closed");

    return _test0rstringlist (g, val);
  }

  private native String[] _test0rstringlist (long g, String val)
    throws LibGuestFSException;

  public String[] test0rstringlisterr ()
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("test0rstringlisterr: handle is closed");

    return _test0rstringlisterr (g);
  }

  private native String[] _test0rstringlisterr (long g)
    throws LibGuestFSException;

  public PV test0rstruct (String val)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("test0rstruct: handle is closed");

    return _test0rstruct (g, val);
  }

  private native PV _test0rstruct (long g, String val)
    throws LibGuestFSException;

  public PV test0rstructerr ()
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("test0rstructerr: handle is closed");

    return _test0rstructerr (g);
  }

  private native PV _test0rstructerr (long g)
    throws LibGuestFSException;

  public PV[] test0rstructlist (String val)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("test0rstructlist: handle is closed");

    return _test0rstructlist (g, val);
  }

  private native PV[] _test0rstructlist (long g, String val)
    throws LibGuestFSException;

  public PV[] test0rstructlisterr ()
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("test0rstructlisterr: handle is closed");

    return _test0rstructlisterr (g);
  }

  private native PV[] _test0rstructlisterr (long g)
    throws LibGuestFSException;

  public Map<String,String> test0rhashtable (String val)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("test0rhashtable: handle is closed");

    String[] r = _test0rhashtable (g, val);

    HashMap<String, String> rhash = new HashMap<String, String> ();
    for (int i = 0; i < r.length; i += 2)
      rhash.put (r[i], r[i+1]);
    return rhash;
  }

  private native String[] _test0rhashtable (long g, String val)
    throws LibGuestFSException;

  public Map<String,String> test0rhashtableerr ()
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("test0rhashtableerr: handle is closed");

    String[] r = _test0rhashtableerr (g);

    HashMap<String, String> rhash = new HashMap<String, String> ();
    for (int i = 0; i < r.length; i += 2)
      rhash.put (r[i], r[i+1]);
    return rhash;
  }

  private native String[] _test0rhashtableerr (long g)
    throws LibGuestFSException;

  public String test0rbufferout (String val)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("test0rbufferout: handle is closed");

    return _test0rbufferout (g, val);
  }

  private native String _test0rbufferout (long g, String val)
    throws LibGuestFSException;

  public String test0rbufferouterr ()
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("test0rbufferouterr: handle is closed");

    return _test0rbufferouterr (g);
  }

  private native String _test0rbufferouterr (long g)
    throws LibGuestFSException;

  /**
   * launch the qemu subprocess
   * <p>
   * Internally libguestfs is implemented by running a
   * virtual machine using qemu(1).
   * <p>
   * You should call this after configuring the handle (eg.
   * adding drives) but before performing any actions.
   * <p>
   * Do not call "g.launch" twice on the same handle.
   * Although it will not give an error (for historical
   * reasons), the precise behaviour when you do this is not
   * well defined. Handles are very cheap to create, so
   * create a new one for each launch.
   * <p>
   * @throws LibGuestFSException
   */
  public void launch ()
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("launch: handle is closed");

    _launch (g);
  }

  private native void _launch (long g)
    throws LibGuestFSException;

  /**
   * wait until the qemu subprocess launches (no op)
   * <p>
   * This function is a no op.
   * <p>
   * In versions of the API < 1.0.71 you had to call this
   * function just after calling "g.launch" to wait for the
   * launch to complete. However this is no longer necessary
   * because "g.launch" now does the waiting.
   * <p>
   * If you see any calls to this function in code then you
   * can just remove them, unless you want to retain
   * compatibility with older versions of the API.
   * <p>
   * *This function is deprecated.* In new code, use the
   * "launch" call instead.
   * <p>
   * Deprecated functions will not be removed from the API,
   * but the fact that they are deprecated indicates that
   * there are problems with correct use of these functions.
   * <p>
   * @throws LibGuestFSException
   */
  public void wait_ready ()
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("wait_ready: handle is closed");

    _wait_ready (g);
  }

  private native void _wait_ready (long g)
    throws LibGuestFSException;

  /**
   * kill the qemu subprocess
   * <p>
   * This kills the qemu subprocess.
   * <p>
   * Do not call this. See: "g.shutdown" instead.
   * <p>
   * *This function is deprecated.* In new code, use the
   * "shutdown" call instead.
   * <p>
   * Deprecated functions will not be removed from the API,
   * but the fact that they are deprecated indicates that
   * there are problems with correct use of these functions.
   * <p>
   * @throws LibGuestFSException
   */
  public void kill_subprocess ()
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("kill_subprocess: handle is closed");

    _kill_subprocess (g);
  }

  private native void _kill_subprocess (long g)
    throws LibGuestFSException;

  /**
   * add an image to examine or modify
   * <p>
   * This function is the equivalent of calling
   * "g.add_drive_opts" with no optional parameters, so the
   * disk is added writable, with the format being detected
   * automatically.
   * <p>
   * Automatic detection of the format opens you up to a
   * potential security hole when dealing with untrusted
   * raw-format images. See CVE-2010-3851 and RHBZ#642934.
   * Specifying the format closes this security hole.
   * Therefore you should think about replacing calls to this
   * function with calls to "g.add_drive_opts", and
   * specifying the format.
   * <p>
   * @throws LibGuestFSException
   */
  public void add_drive (String filename)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("add_drive: handle is closed");

    _add_drive (g, filename);
  }

  private native void _add_drive (long g, String filename)
    throws LibGuestFSException;

  /**
   * add a CD-ROM disk image to examine
   * <p>
   * This function adds a virtual CD-ROM disk image to the
   * guest.
   * <p>
   * This is equivalent to the qemu parameter *-cdrom
   * filename*.
   * <p>
   * Notes:
   * <p>
   * *   This call checks for the existence of "filename".
   * This stops you from specifying other types of drive
   * which are supported by qemu such as "nbd:" and
   * "http:" URLs. To specify those, use the general
   * "g.config" call instead.
   * <p>
   * *   If you just want to add an ISO file (often you use
   * this as an efficient way to transfer large files
   * into the guest), then you should probably use
   * "g.add_drive_ro" instead.
   * <p>
   * *This function is deprecated.* In new code, use the
   * "add_drive_opts" call instead.
   * <p>
   * Deprecated functions will not be removed from the API,
   * but the fact that they are deprecated indicates that
   * there are problems with correct use of these functions.
   * <p>
   * @throws LibGuestFSException
   */
  public void add_cdrom (String filename)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("add_cdrom: handle is closed");

    _add_cdrom (g, filename);
  }

  private native void _add_cdrom (long g, String filename)
    throws LibGuestFSException;

  /**
   * add a drive in snapshot mode (read-only)
   * <p>
   * This function is the equivalent of calling
   * "g.add_drive_opts" with the optional parameter
   * "GUESTFS_ADD_DRIVE_OPTS_READONLY" set to 1, so the disk
   * is added read-only, with the format being detected
   * automatically.
   * <p>
   * @throws LibGuestFSException
   */
  public void add_drive_ro (String filename)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("add_drive_ro: handle is closed");

    _add_drive_ro (g, filename);
  }

  private native void _add_drive_ro (long g, String filename)
    throws LibGuestFSException;

  /**
   * add qemu parameters
   * <p>
   * This can be used to add arbitrary qemu command line
   * parameters of the form *-param value*. Actually it's not
   * quite arbitrary - we prevent you from setting some
   * parameters which would interfere with parameters that we
   * use.
   * <p>
   * The first character of "param" string must be a "-"
   * (dash).
   * <p>
   * "value" can be NULL.
   * <p>
   * @throws LibGuestFSException
   */
  public void config (String qemuparam, String qemuvalue)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("config: handle is closed");

    _config (g, qemuparam, qemuvalue);
  }

  private native void _config (long g, String qemuparam, String qemuvalue)
    throws LibGuestFSException;

  /**
   * set the qemu binary
   * <p>
   * Set the qemu binary that we will use.
   * <p>
   * The default is chosen when the library was compiled by
   * the configure script.
   * <p>
   * You can also override this by setting the
   * "LIBGUESTFS_QEMU" environment variable.
   * <p>
   * Setting "qemu" to "NULL" restores the default qemu
   * binary.
   * <p>
   * Note that you should call this function as early as
   * possible after creating the handle. This is because some
   * pre-launch operations depend on testing qemu features
   * (by running "qemu -help"). If the qemu binary changes,
   * we don't retest features, and so you might see
   * inconsistent results. Using the environment variable
   * "LIBGUESTFS_QEMU" is safest of all since that picks the
   * qemu binary at the same time as the handle is created.
   * <p>
   * @throws LibGuestFSException
   */
  public void set_qemu (String qemu)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("set_qemu: handle is closed");

    _set_qemu (g, qemu);
  }

  private native void _set_qemu (long g, String qemu)
    throws LibGuestFSException;

  /**
   * get the qemu binary
   * <p>
   * Return the current qemu binary.
   * <p>
   * This is always non-NULL. If it wasn't set already, then
   * this will return the default qemu binary name.
   * <p>
   * @throws LibGuestFSException
   */
  public String get_qemu ()
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("get_qemu: handle is closed");

    return _get_qemu (g);
  }

  private native String _get_qemu (long g)
    throws LibGuestFSException;

  /**
   * set the search path
   * <p>
   * Set the path that libguestfs searches for kernel and
   * initrd.img.
   * <p>
   * The default is "$libdir/guestfs" unless overridden by
   * setting "LIBGUESTFS_PATH" environment variable.
   * <p>
   * Setting "path" to "NULL" restores the default path.
   * <p>
   * @throws LibGuestFSException
   */
  public void set_path (String searchpath)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("set_path: handle is closed");

    _set_path (g, searchpath);
  }

  private native void _set_path (long g, String searchpath)
    throws LibGuestFSException;

  /**
   * get the search path
   * <p>
   * Return the current search path.
   * <p>
   * This is always non-NULL. If it wasn't set already, then
   * this will return the default path.
   * <p>
   * @throws LibGuestFSException
   */
  public String get_path ()
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("get_path: handle is closed");

    return _get_path (g);
  }

  private native String _get_path (long g)
    throws LibGuestFSException;

  /**
   * add options to kernel command line
   * <p>
   * This function is used to add additional options to the
   * guest kernel command line.
   * <p>
   * The default is "NULL" unless overridden by setting
   * "LIBGUESTFS_APPEND" environment variable.
   * <p>
   * Setting "append" to "NULL" means *no* additional options
   * are passed (libguestfs always adds a few of its own).
   * <p>
   * @throws LibGuestFSException
   */
  public void set_append (String append)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("set_append: handle is closed");

    _set_append (g, append);
  }

  private native void _set_append (long g, String append)
    throws LibGuestFSException;

  /**
   * get the additional kernel options
   * <p>
   * Return the additional kernel options which are added to
   * the guest kernel command line.
   * <p>
   * If "NULL" then no options are added.
   * <p>
   * @throws LibGuestFSException
   */
  public String get_append ()
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("get_append: handle is closed");

    return _get_append (g);
  }

  private native String _get_append (long g)
    throws LibGuestFSException;

  /**
   * set autosync mode
   * <p>
   * If "autosync" is true, this enables autosync. Libguestfs
   * will make a best effort attempt to make filesystems
   * consistent and synchronized when the handle is closed
   * (also if the program exits without closing handles).
   * <p>
   * This is enabled by default (since libguestfs 1.5.24,
   * previously it was disabled by default).
   * <p>
   * @throws LibGuestFSException
   */
  public void set_autosync (boolean autosync)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("set_autosync: handle is closed");

    _set_autosync (g, autosync);
  }

  private native void _set_autosync (long g, boolean autosync)
    throws LibGuestFSException;

  /**
   * get autosync mode
   * <p>
   * Get the autosync flag.
   * <p>
   * @throws LibGuestFSException
   */
  public boolean get_autosync ()
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("get_autosync: handle is closed");

    return _get_autosync (g);
  }

  private native boolean _get_autosync (long g)
    throws LibGuestFSException;

  /**
   * set verbose mode
   * <p>
   * If "verbose" is true, this turns on verbose messages.
   * <p>
   * Verbose messages are disabled unless the environment
   * variable "LIBGUESTFS_DEBUG" is defined and set to 1.
   * <p>
   * Verbose messages are normally sent to "stderr", unless
   * you register a callback to send them somewhere else (see
   * "g.set_event_callback").
   * <p>
   * @throws LibGuestFSException
   */
  public void set_verbose (boolean verbose)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("set_verbose: handle is closed");

    _set_verbose (g, verbose);
  }

  private native void _set_verbose (long g, boolean verbose)
    throws LibGuestFSException;

  /**
   * get verbose mode
   * <p>
   * This returns the verbose messages flag.
   * <p>
   * @throws LibGuestFSException
   */
  public boolean get_verbose ()
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("get_verbose: handle is closed");

    return _get_verbose (g);
  }

  private native boolean _get_verbose (long g)
    throws LibGuestFSException;

  /**
   * is ready to accept commands
   * <p>
   * This returns true iff this handle is ready to accept
   * commands (in the "READY" state).
   * <p>
   * For more information on states, see guestfs(3).
   * <p>
   * @throws LibGuestFSException
   */
  public boolean is_ready ()
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("is_ready: handle is closed");

    return _is_ready (g);
  }

  private native boolean _is_ready (long g)
    throws LibGuestFSException;

  /**
   * is in configuration state
   * <p>
   * This returns true iff this handle is being configured
   * (in the "CONFIG" state).
   * <p>
   * For more information on states, see guestfs(3).
   * <p>
   * @throws LibGuestFSException
   */
  public boolean is_config ()
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("is_config: handle is closed");

    return _is_config (g);
  }

  private native boolean _is_config (long g)
    throws LibGuestFSException;

  /**
   * is launching subprocess
   * <p>
   * This returns true iff this handle is launching the
   * subprocess (in the "LAUNCHING" state).
   * <p>
   * For more information on states, see guestfs(3).
   * <p>
   * @throws LibGuestFSException
   */
  public boolean is_launching ()
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("is_launching: handle is closed");

    return _is_launching (g);
  }

  private native boolean _is_launching (long g)
    throws LibGuestFSException;

  public boolean is_busy ()
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("is_busy: handle is closed");

    return _is_busy (g);
  }

  private native boolean _is_busy (long g)
    throws LibGuestFSException;

  /**
   * get the current state
   * <p>
   * This returns the current state as an opaque integer.
   * This is only useful for printing debug and internal
   * error messages.
   * <p>
   * For more information on states, see guestfs(3).
   * <p>
   * @throws LibGuestFSException
   */
  public int get_state ()
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("get_state: handle is closed");

    return _get_state (g);
  }

  private native int _get_state (long g)
    throws LibGuestFSException;

  /**
   * set memory allocated to the qemu subprocess
   * <p>
   * This sets the memory size in megabytes allocated to the
   * qemu subprocess. This only has any effect if called
   * before "g.launch".
   * <p>
   * You can also change this by setting the environment
   * variable "LIBGUESTFS_MEMSIZE" before the handle is
   * created.
   * <p>
   * For more information on the architecture of libguestfs,
   * see guestfs(3).
   * <p>
   * @throws LibGuestFSException
   */
  public void set_memsize (int memsize)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("set_memsize: handle is closed");

    _set_memsize (g, memsize);
  }

  private native void _set_memsize (long g, int memsize)
    throws LibGuestFSException;

  /**
   * get memory allocated to the qemu subprocess
   * <p>
   * This gets the memory size in megabytes allocated to the
   * qemu subprocess.
   * <p>
   * If "g.set_memsize" was not called on this handle, and if
   * "LIBGUESTFS_MEMSIZE" was not set, then this returns the
   * compiled-in default value for memsize.
   * <p>
   * For more information on the architecture of libguestfs,
   * see guestfs(3).
   * <p>
   * @throws LibGuestFSException
   */
  public int get_memsize ()
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("get_memsize: handle is closed");

    return _get_memsize (g);
  }

  private native int _get_memsize (long g)
    throws LibGuestFSException;

  /**
   * get PID of qemu subprocess
   * <p>
   * Return the process ID of the qemu subprocess. If there
   * is no qemu subprocess, then this will return an error.
   * <p>
   * This is an internal call used for debugging and testing.
   * <p>
   * @throws LibGuestFSException
   */
  public int get_pid ()
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("get_pid: handle is closed");

    return _get_pid (g);
  }

  private native int _get_pid (long g)
    throws LibGuestFSException;

  /**
   * get the library version number
   * <p>
   * Return the libguestfs version number that the program is
   * linked against.
   * <p>
   * Note that because of dynamic linking this is not
   * necessarily the version of libguestfs that you compiled
   * against. You can compile the program, and then at
   * runtime dynamically link against a completely different
   * "libguestfs.so" library.
   * <p>
   * This call was added in version 1.0.58. In previous
   * versions of libguestfs there was no way to get the
   * version number. From C code you can use dynamic linker
   * functions to find out if this symbol exists (if it
   * doesn't, then it's an earlier version).
   * <p>
   * The call returns a structure with four elements. The
   * first three ("major", "minor" and "release") are numbers
   * and correspond to the usual version triplet. The fourth
   * element ("extra") is a string and is normally empty, but
   * may be used for distro-specific information.
   * <p>
   * To construct the original version string:
   * "$major.$minor.$release$extra"
   * <p>
   * See also: "LIBGUESTFS VERSION NUMBERS" in guestfs(3).
   * <p>
   * *Note:* Don't use this call to test for availability of
   * features. In enterprise distributions we backport
   * features from later versions into earlier versions,
   * making this an unreliable way to test for features. Use
   * "g.available" instead.
   * <p>
   * @throws LibGuestFSException
   */
  public Version version ()
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("version: handle is closed");

    return _version (g);
  }

  private native Version _version (long g)
    throws LibGuestFSException;

  /**
   * set SELinux enabled or disabled at appliance boot
   * <p>
   * This sets the selinux flag that is passed to the
   * appliance at boot time. The default is "selinux=0"
   * (disabled).
   * <p>
   * Note that if SELinux is enabled, it is always in
   * Permissive mode ("enforcing=0").
   * <p>
   * For more information on the architecture of libguestfs,
   * see guestfs(3).
   * <p>
   * @throws LibGuestFSException
   */
  public void set_selinux (boolean selinux)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("set_selinux: handle is closed");

    _set_selinux (g, selinux);
  }

  private native void _set_selinux (long g, boolean selinux)
    throws LibGuestFSException;

  /**
   * get SELinux enabled flag
   * <p>
   * This returns the current setting of the selinux flag
   * which is passed to the appliance at boot time. See
   * "g.set_selinux".
   * <p>
   * For more information on the architecture of libguestfs,
   * see guestfs(3).
   * <p>
   * @throws LibGuestFSException
   */
  public boolean get_selinux ()
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("get_selinux: handle is closed");

    return _get_selinux (g);
  }

  private native boolean _get_selinux (long g)
    throws LibGuestFSException;

  /**
   * enable or disable command traces
   * <p>
   * If the command trace flag is set to 1, then libguestfs
   * calls, parameters and return values are traced.
   * <p>
   * If you want to trace C API calls into libguestfs (and
   * other libraries) then possibly a better way is to use
   * the external ltrace(1) command.
   * <p>
   * Command traces are disabled unless the environment
   * variable "LIBGUESTFS_TRACE" is defined and set to 1.
   * <p>
   * Trace messages are normally sent to "stderr", unless you
   * register a callback to send them somewhere else (see
   * "g.set_event_callback").
   * <p>
   * @throws LibGuestFSException
   */
  public void set_trace (boolean trace)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("set_trace: handle is closed");

    _set_trace (g, trace);
  }

  private native void _set_trace (long g, boolean trace)
    throws LibGuestFSException;

  /**
   * get command trace enabled flag
   * <p>
   * Return the command trace flag.
   * <p>
   * @throws LibGuestFSException
   */
  public boolean get_trace ()
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("get_trace: handle is closed");

    return _get_trace (g);
  }

  private native boolean _get_trace (long g)
    throws LibGuestFSException;

  /**
   * enable or disable direct appliance mode
   * <p>
   * If the direct appliance mode flag is enabled, then stdin
   * and stdout are passed directly through to the appliance
   * once it is launched.
   * <p>
   * One consequence of this is that log messages aren't
   * caught by the library and handled by
   * "g.set_log_message_callback", but go straight to stdout.
   * <p>
   * You probably don't want to use this unless you know what
   * you are doing.
   * <p>
   * The default is disabled.
   * <p>
   * @throws LibGuestFSException
   */
  public void set_direct (boolean direct)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("set_direct: handle is closed");

    _set_direct (g, direct);
  }

  private native void _set_direct (long g, boolean direct)
    throws LibGuestFSException;

  /**
   * get direct appliance mode flag
   * <p>
   * Return the direct appliance mode flag.
   * <p>
   * @throws LibGuestFSException
   */
  public boolean get_direct ()
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("get_direct: handle is closed");

    return _get_direct (g);
  }

  private native boolean _get_direct (long g)
    throws LibGuestFSException;

  /**
   * enable or disable the recovery process
   * <p>
   * If this is called with the parameter "false" then
   * "g.launch" does not create a recovery process. The
   * purpose of the recovery process is to stop runaway qemu
   * processes in the case where the main program aborts
   * abruptly.
   * <p>
   * This only has any effect if called before "g.launch",
   * and the default is true.
   * <p>
   * About the only time when you would want to disable this
   * is if the main process will fork itself into the
   * background ("daemonize" itself). In this case the
   * recovery process thinks that the main program has
   * disappeared and so kills qemu, which is not very
   * helpful.
   * <p>
   * @throws LibGuestFSException
   */
  public void set_recovery_proc (boolean recoveryproc)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("set_recovery_proc: handle is closed");

    _set_recovery_proc (g, recoveryproc);
  }

  private native void _set_recovery_proc (long g, boolean recoveryproc)
    throws LibGuestFSException;

  /**
   * get recovery process enabled flag
   * <p>
   * Return the recovery process enabled flag.
   * <p>
   * @throws LibGuestFSException
   */
  public boolean get_recovery_proc ()
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("get_recovery_proc: handle is closed");

    return _get_recovery_proc (g);
  }

  private native boolean _get_recovery_proc (long g)
    throws LibGuestFSException;

  /**
   * add a drive specifying the QEMU block emulation to use
   * <p>
   * This is the same as "g.add_drive" but it allows you to
   * specify the QEMU interface emulation to use at run time.
   * <p>
   * *This function is deprecated.* In new code, use the
   * "add_drive_opts" call instead.
   * <p>
   * Deprecated functions will not be removed from the API,
   * but the fact that they are deprecated indicates that
   * there are problems with correct use of these functions.
   * <p>
   * @throws LibGuestFSException
   */
  public void add_drive_with_if (String filename, String iface)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("add_drive_with_if: handle is closed");

    _add_drive_with_if (g, filename, iface);
  }

  private native void _add_drive_with_if (long g, String filename, String iface)
    throws LibGuestFSException;

  /**
   * add a drive read-only specifying the QEMU block emulation to use
   * <p>
   * This is the same as "g.add_drive_ro" but it allows you
   * to specify the QEMU interface emulation to use at run
   * time.
   * <p>
   * *This function is deprecated.* In new code, use the
   * "add_drive_opts" call instead.
   * <p>
   * Deprecated functions will not be removed from the API,
   * but the fact that they are deprecated indicates that
   * there are problems with correct use of these functions.
   * <p>
   * @throws LibGuestFSException
   */
  public void add_drive_ro_with_if (String filename, String iface)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("add_drive_ro_with_if: handle is closed");

    _add_drive_ro_with_if (g, filename, iface);
  }

  private native void _add_drive_ro_with_if (long g, String filename, String iface)
    throws LibGuestFSException;

  /**
   * detect the architecture of a binary file
   * <p>
   * This detects the architecture of the binary "filename",
   * and returns it if known.
   * <p>
   * Currently defined architectures are:
   * <p>
   * "i386"
   * This string is returned for all 32 bit i386, i486,
   * i586, i686 binaries irrespective of the precise
   * processor requirements of the binary.
   * <p>
   * "x86_64"
   * 64 bit x86-64.
   * <p>
   * "sparc"
   * 32 bit SPARC.
   * <p>
   * "sparc64"
   * 64 bit SPARC V9 and above.
   * <p>
   * "ia64"
   * Intel Itanium.
   * <p>
   * "ppc"
   * 32 bit Power PC.
   * <p>
   * "ppc64"
   * 64 bit Power PC.
   * <p>
   * Libguestfs may return other architecture strings in
   * future.
   * <p>
   * The function works on at least the following types of
   * files:
   * <p>
   * *   many types of Un*x and Linux binary
   * <p>
   * *   many types of Un*x and Linux shared library
   * <p>
   * *   Windows Win32 and Win64 binaries
   * <p>
   * *   Windows Win32 and Win64 DLLs
   * <p>
   * Win32 binaries and DLLs return "i386".
   * <p>
   * Win64 binaries and DLLs return "x86_64".
   * <p>
   * *   Linux kernel modules
   * <p>
   * *   Linux new-style initrd images
   * <p>
   * *   some non-x86 Linux vmlinuz kernels
   * <p>
   * What it can't do currently:
   * <p>
   * *   static libraries (libfoo.a)
   * <p>
   * *   Linux old-style initrd as compressed ext2 filesystem
   * (RHEL 3)
   * <p>
   * *   x86 Linux vmlinuz kernels
   * <p>
   * x86 vmlinuz images (bzImage format) consist of a mix
   * of 16-, 32- and compressed code, and are horribly
   * hard to unpack. If you want to find the architecture
   * of a kernel, use the architecture of the associated
   * initrd or kernel module(s) instead.
   * <p>
   * @throws LibGuestFSException
   */
  public String file_architecture (String filename)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("file_architecture: handle is closed");

    return _file_architecture (g, filename);
  }

  private native String _file_architecture (long g, String filename)
    throws LibGuestFSException;

  /**
   * inspect disk and return list of operating systems found
   * <p>
   * This function uses other libguestfs functions and
   * certain heuristics to inspect the disk(s) (usually disks
   * belonging to a virtual machine), looking for operating
   * systems.
   * <p>
   * The list returned is empty if no operating systems were
   * found.
   * <p>
   * If one operating system was found, then this returns a
   * list with a single element, which is the name of the
   * root filesystem of this operating system. It is also
   * possible for this function to return a list containing
   * more than one element, indicating a dual-boot or
   * multi-boot virtual machine, with each element being the
   * root filesystem of one of the operating systems.
   * <p>
   * You can pass the root string(s) returned to other
   * "g.inspect_get_*" functions in order to query further
   * information about each operating system, such as the
   * name and version.
   * <p>
   * This function uses other libguestfs features such as
   * "g.mount_ro" and "g.umount_all" in order to mount and
   * unmount filesystems and look at the contents. This
   * should be called with no disks currently mounted. The
   * function may also use Augeas, so any existing Augeas
   * handle will be closed.
   * <p>
   * This function cannot decrypt encrypted disks. The caller
   * must do that first (supplying the necessary keys) if the
   * disk is encrypted.
   * <p>
   * Please read "INSPECTION" in guestfs(3) for more details.
   * <p>
   * See also "g.list_filesystems".
   * <p>
   * @throws LibGuestFSException
   */
  public String[] inspect_os ()
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("inspect_os: handle is closed");

    return _inspect_os (g);
  }

  private native String[] _inspect_os (long g)
    throws LibGuestFSException;

  /**
   * get type of inspected operating system
   * <p>
   * This returns the type of the inspected operating system.
   * Currently defined types are:
   * <p>
   * "linux"
   * Any Linux-based operating system.
   * <p>
   * "windows"
   * Any Microsoft Windows operating system.
   * <p>
   * "freebsd"
   * FreeBSD.
   * <p>
   * "netbsd"
   * NetBSD.
   * <p>
   * "hurd"
   * GNU/Hurd.
   * <p>
   * "dos"
   * MS-DOS, FreeDOS and others.
   * <p>
   * "unknown"
   * The operating system type could not be determined.
   * <p>
   * Future versions of libguestfs may return other strings
   * here. The caller should be prepared to handle any
   * string.
   * <p>
   * Please read "INSPECTION" in guestfs(3) for more details.
   * <p>
   * @throws LibGuestFSException
   */
  public String inspect_get_type (String root)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("inspect_get_type: handle is closed");

    return _inspect_get_type (g, root);
  }

  private native String _inspect_get_type (long g, String root)
    throws LibGuestFSException;

  /**
   * get architecture of inspected operating system
   * <p>
   * This returns the architecture of the inspected operating
   * system. The possible return values are listed under
   * "g.file_architecture".
   * <p>
   * If the architecture could not be determined, then the
   * string "unknown" is returned.
   * <p>
   * Please read "INSPECTION" in guestfs(3) for more details.
   * <p>
   * @throws LibGuestFSException
   */
  public String inspect_get_arch (String root)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("inspect_get_arch: handle is closed");

    return _inspect_get_arch (g, root);
  }

  private native String _inspect_get_arch (long g, String root)
    throws LibGuestFSException;

  /**
   * get distro of inspected operating system
   * <p>
   * This returns the distro (distribution) of the inspected
   * operating system.
   * <p>
   * Currently defined distros are:
   * <p>
   * "archlinux"
   * Arch Linux.
   * <p>
   * "buildroot"
   * Buildroot-derived distro, but not one we
   * specifically recognize.
   * <p>
   * "centos"
   * CentOS.
   * <p>
   * "cirros"
   * Cirros.
   * <p>
   * "debian"
   * Debian.
   * <p>
   * "fedora"
   * Fedora.
   * <p>
   * "freedos"
   * FreeDOS.
   * <p>
   * "gentoo"
   * Gentoo.
   * <p>
   * "linuxmint"
   * Linux Mint.
   * <p>
   * "mageia"
   * Mageia.
   * <p>
   * "mandriva"
   * Mandriva.
   * <p>
   * "meego"
   * MeeGo.
   * <p>
   * "opensuse"
   * OpenSUSE.
   * <p>
   * "pardus"
   * Pardus.
   * <p>
   * "redhat-based"
   * Some Red Hat-derived distro.
   * <p>
   * "rhel"
   * Red Hat Enterprise Linux.
   * <p>
   * "scientificlinux"
   * Scientific Linux.
   * <p>
   * "slackware"
   * Slackware.
   * <p>
   * "ttylinux"
   * ttylinux.
   * <p>
   * "ubuntu"
   * Ubuntu.
   * <p>
   * "unknown"
   * The distro could not be determined.
   * <p>
   * "windows"
   * Windows does not have distributions. This string is
   * returned if the OS type is Windows.
   * <p>
   * Future versions of libguestfs may return other strings
   * here. The caller should be prepared to handle any
   * string.
   * <p>
   * Please read "INSPECTION" in guestfs(3) for more details.
   * <p>
   * @throws LibGuestFSException
   */
  public String inspect_get_distro (String root)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("inspect_get_distro: handle is closed");

    return _inspect_get_distro (g, root);
  }

  private native String _inspect_get_distro (long g, String root)
    throws LibGuestFSException;

  /**
   * get major version of inspected operating system
   * <p>
   * This returns the major version number of the inspected
   * operating system.
   * <p>
   * Windows uses a consistent versioning scheme which is
   * *not* reflected in the popular public names used by the
   * operating system. Notably the operating system known as
   * "Windows 7" is really version 6.1 (ie. major = 6, minor
   * = 1). You can find out the real versions corresponding
   * to releases of Windows by consulting Wikipedia or MSDN.
   * <p>
   * If the version could not be determined, then 0 is
   * returned.
   * <p>
   * Please read "INSPECTION" in guestfs(3) for more details.
   * <p>
   * @throws LibGuestFSException
   */
  public int inspect_get_major_version (String root)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("inspect_get_major_version: handle is closed");

    return _inspect_get_major_version (g, root);
  }

  private native int _inspect_get_major_version (long g, String root)
    throws LibGuestFSException;

  /**
   * get minor version of inspected operating system
   * <p>
   * This returns the minor version number of the inspected
   * operating system.
   * <p>
   * If the version could not be determined, then 0 is
   * returned.
   * <p>
   * Please read "INSPECTION" in guestfs(3) for more details.
   * See also "g.inspect_get_major_version".
   * <p>
   * @throws LibGuestFSException
   */
  public int inspect_get_minor_version (String root)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("inspect_get_minor_version: handle is closed");

    return _inspect_get_minor_version (g, root);
  }

  private native int _inspect_get_minor_version (long g, String root)
    throws LibGuestFSException;

  /**
   * get product name of inspected operating system
   * <p>
   * This returns the product name of the inspected operating
   * system. The product name is generally some freeform
   * string which can be displayed to the user, but should
   * not be parsed by programs.
   * <p>
   * If the product name could not be determined, then the
   * string "unknown" is returned.
   * <p>
   * Please read "INSPECTION" in guestfs(3) for more details.
   * <p>
   * @throws LibGuestFSException
   */
  public String inspect_get_product_name (String root)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("inspect_get_product_name: handle is closed");

    return _inspect_get_product_name (g, root);
  }

  private native String _inspect_get_product_name (long g, String root)
    throws LibGuestFSException;

  /**
   * get mountpoints of inspected operating system
   * <p>
   * This returns a hash of where we think the filesystems
   * associated with this operating system should be mounted.
   * Callers should note that this is at best an educated
   * guess made by reading configuration files such as
   * "/etc/fstab". *In particular note* that this may return
   * filesystems which are non-existent or not mountable and
   * callers should be prepared to handle or ignore failures
   * if they try to mount them.
   * <p>
   * Each element in the returned hashtable has a key which
   * is the path of the mountpoint (eg. "/boot") and a value
   * which is the filesystem that would be mounted there (eg.
   * "/dev/sda1").
   * <p>
   * Non-mounted devices such as swap devices are *not*
   * returned in this list.
   * <p>
   * For operating systems like Windows which still use drive
   * letters, this call will only return an entry for the
   * first drive "mounted on" "/". For information about the
   * mapping of drive letters to partitions, see
   * "g.inspect_get_drive_mappings".
   * <p>
   * Please read "INSPECTION" in guestfs(3) for more details.
   * See also "g.inspect_get_filesystems".
   * <p>
   * @throws LibGuestFSException
   */
  public Map<String,String> inspect_get_mountpoints (String root)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("inspect_get_mountpoints: handle is closed");

    String[] r = _inspect_get_mountpoints (g, root);

    HashMap<String, String> rhash = new HashMap<String, String> ();
    for (int i = 0; i < r.length; i += 2)
      rhash.put (r[i], r[i+1]);
    return rhash;
  }

  private native String[] _inspect_get_mountpoints (long g, String root)
    throws LibGuestFSException;

  /**
   * get filesystems associated with inspected operating system
   * <p>
   * This returns a list of all the filesystems that we think
   * are associated with this operating system. This includes
   * the root filesystem, other ordinary filesystems, and
   * non-mounted devices like swap partitions.
   * <p>
   * In the case of a multi-boot virtual machine, it is
   * possible for a filesystem to be shared between operating
   * systems.
   * <p>
   * Please read "INSPECTION" in guestfs(3) for more details.
   * See also "g.inspect_get_mountpoints".
   * <p>
   * @throws LibGuestFSException
   */
  public String[] inspect_get_filesystems (String root)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("inspect_get_filesystems: handle is closed");

    return _inspect_get_filesystems (g, root);
  }

  private native String[] _inspect_get_filesystems (long g, String root)
    throws LibGuestFSException;

  /**
   * set enable network flag
   * <p>
   * If "network" is true, then the network is enabled in the
   * libguestfs appliance. The default is false.
   * <p>
   * This affects whether commands are able to access the
   * network (see "RUNNING COMMANDS" in guestfs(3)).
   * <p>
   * You must call this before calling "g.launch", otherwise
   * it has no effect.
   * <p>
   * @throws LibGuestFSException
   */
  public void set_network (boolean network)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("set_network: handle is closed");

    _set_network (g, network);
  }

  private native void _set_network (long g, boolean network)
    throws LibGuestFSException;

  /**
   * get enable network flag
   * <p>
   * This returns the enable network flag.
   * <p>
   * @throws LibGuestFSException
   */
  public boolean get_network ()
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("get_network: handle is closed");

    return _get_network (g);
  }

  private native boolean _get_network (long g)
    throws LibGuestFSException;

  /**
   * list filesystems
   * <p>
   * This inspection command looks for filesystems on
   * partitions, block devices and logical volumes, returning
   * a list of devices containing filesystems and their type.
   * <p>
   * The return value is a hash, where the keys are the
   * devices containing filesystems, and the values are the
   * filesystem types. For example:
   * <p>
   * "/dev/sda1" => "ntfs"
   * "/dev/sda2" => "ext2"
   * "/dev/vg_guest/lv_root" => "ext4"
   * "/dev/vg_guest/lv_swap" => "swap"
   * <p>
   * The value can have the special value "unknown", meaning
   * the content of the device is undetermined or empty.
   * "swap" means a Linux swap partition.
   * <p>
   * This command runs other libguestfs commands, which might
   * include "g.mount" and "g.umount", and therefore you
   * should use this soon after launch and only when nothing
   * is mounted.
   * <p>
   * Not all of the filesystems returned will be mountable.
   * In particular, swap partitions are returned in the list.
   * Also this command does not check that each filesystem
   * found is valid and mountable, and some filesystems might
   * be mountable but require special options. Filesystems
   * may not all belong to a single logical operating system
   * (use "g.inspect_os" to look for OSes).
   * <p>
   * @throws LibGuestFSException
   */
  public Map<String,String> list_filesystems ()
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("list_filesystems: handle is closed");

    String[] r = _list_filesystems (g);

    HashMap<String, String> rhash = new HashMap<String, String> ();
    for (int i = 0; i < r.length; i += 2)
      rhash.put (r[i], r[i+1]);
    return rhash;
  }

  private native String[] _list_filesystems (long g)
    throws LibGuestFSException;

  /**
   * add an image to examine or modify
   * <p>
   * This function adds a disk image called "filename" to the
   * handle. "filename" may be a regular host file or a host
   * device.
   * <p>
   * The first time you call this function, the disk appears
   * as "/dev/sda", the second time as "/dev/sdb", and so on.
   * <p>
   * You don't necessarily need to be root when using
   * libguestfs. However you obviously do need sufficient
   * permissions to access the filename for whatever
   * operations you want to perform (ie. read access if you
   * just want to read the image or write access if you want
   * to modify the image).
   * <p>
   * This call checks that "filename" exists.
   * <p>
   * "filename" may be the special string "/dev/null". See
   * "NULL DISKS" in guestfs(3).
   * <p>
   * The optional arguments are:
   * <p>
   * "readonly"
   * If true then the image is treated as read-only.
   * Writes are still allowed, but they are stored in a
   * temporary snapshot overlay which is discarded at the
   * end. The disk that you add is not modified.
   * <p>
   * "format"
   * This forces the image format. If you omit this (or
   * use "g.add_drive" or "g.add_drive_ro") then the
   * format is automatically detected. Possible formats
   * include "raw" and "qcow2".
   * <p>
   * Automatic detection of the format opens you up to a
   * potential security hole when dealing with untrusted
   * raw-format images. See CVE-2010-3851 and
   * RHBZ#642934. Specifying the format closes this
   * security hole.
   * <p>
   * "iface"
   * This rarely-used option lets you emulate the
   * behaviour of the deprecated "g.add_drive_with_if"
   * call (q.v.)
   * <p>
   * "name"
   * The name the drive had in the original guest, e.g.
   * "/dev/sdb". This is used as a hint to the guest
   * inspection process if it is available.
   * <p>
   * Optional arguments are supplied in the final
   * Map<String,Object> parameter, which is a hash of the
   * argument name to its value (cast to Object). Pass an
   * empty Map or null for no optional arguments.
   * <p>
   * @throws LibGuestFSException
   */
  public void add_drive_opts (String filename, Map<String, Object> optargs)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("add_drive_opts: handle is closed");

    /* Unpack optional args. */
    Object _optobj;
    long _optargs_bitmask = 0;
    boolean readonly = false;
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("readonly");
    if (_optobj != null) {
      readonly = ((Boolean) _optobj).booleanValue();
      _optargs_bitmask |= 1L;
    }
    String format = "";
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("format");
    if (_optobj != null) {
      format = ((String) _optobj);
      _optargs_bitmask |= 2L;
    }
    String iface = "";
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("iface");
    if (_optobj != null) {
      iface = ((String) _optobj);
      _optargs_bitmask |= 4L;
    }
    String name = "";
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("name");
    if (_optobj != null) {
      name = ((String) _optobj);
      _optargs_bitmask |= 8L;
    }

    _add_drive_opts (g, filename, _optargs_bitmask, readonly, format, iface, name);
  }

  public void add_drive_opts (String filename)
    throws LibGuestFSException
  {
    add_drive_opts (filename, null);
  }

  private native void _add_drive_opts (long g, String filename, long _optargs_bitmask, boolean readonly, String format, String iface, String name)
    throws LibGuestFSException;

  /**
   * get Windows systemroot of inspected operating system
   * <p>
   * This returns the Windows systemroot of the inspected
   * guest. The systemroot is a directory path such as
   * "/WINDOWS".
   * <p>
   * This call assumes that the guest is Windows and that the
   * systemroot could be determined by inspection. If this is
   * not the case then an error is returned.
   * <p>
   * Please read "INSPECTION" in guestfs(3) for more details.
   * <p>
   * @throws LibGuestFSException
   */
  public String inspect_get_windows_systemroot (String root)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("inspect_get_windows_systemroot: handle is closed");

    return _inspect_get_windows_systemroot (g, root);
  }

  private native String _inspect_get_windows_systemroot (long g, String root)
    throws LibGuestFSException;

  /**
   * return list of operating systems found by last inspection
   * <p>
   * This function is a convenient way to get the list of
   * root devices, as returned from a previous call to
   * "g.inspect_os", but without redoing the whole inspection
   * process.
   * <p>
   * This returns an empty list if either no root devices
   * were found or the caller has not called "g.inspect_os".
   * <p>
   * Please read "INSPECTION" in guestfs(3) for more details.
   * <p>
   * @throws LibGuestFSException
   */
  public String[] inspect_get_roots ()
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("inspect_get_roots: handle is closed");

    return _inspect_get_roots (g);
  }

  private native String[] _inspect_get_roots (long g)
    throws LibGuestFSException;

  public String[] debug_cmdline ()
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("debug_cmdline: handle is closed");

    return _debug_cmdline (g);
  }

  private native String[] _debug_cmdline (long g)
    throws LibGuestFSException;

  public String[] debug_drives ()
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("debug_drives: handle is closed");

    return _debug_drives (g);
  }

  private native String[] _debug_drives (long g)
    throws LibGuestFSException;

  /**
   * add the disk(s) from a named libvirt domain
   * <p>
   * This function adds the disk(s) attached to the named
   * libvirt domain "dom". It works by connecting to libvirt,
   * requesting the domain and domain XML from libvirt,
   * parsing it for disks, and calling "g.add_drive_opts" on
   * each one.
   * <p>
   * The number of disks added is returned. This operation is
   * atomic: if an error is returned, then no disks are
   * added.
   * <p>
   * This function does some minimal checks to make sure the
   * libvirt domain is not running (unless "readonly" is
   * true). In a future version we will try to acquire the
   * libvirt lock on each disk.
   * <p>
   * Disks must be accessible locally. This often means that
   * adding disks from a remote libvirt connection (see
   * <http://libvirt.org/remote.html>) will fail unless those
   * disks are accessible via the same device path locally
   * too.
   * <p>
   * The optional "libvirturi" parameter sets the libvirt URI
   * (see <http://libvirt.org/uri.html>). If this is not set
   * then we connect to the default libvirt URI (or one set
   * through an environment variable, see the libvirt
   * documentation for full details).
   * <p>
   * The optional "live" flag controls whether this call will
   * try to connect to a running virtual machine "guestfsd"
   * process if it sees a suitable <channel> element in the
   * libvirt XML definition. The default (if the flag is
   * omitted) is never to try. See "ATTACHING TO RUNNING
   * DAEMONS" in guestfs(3) for more information.
   * <p>
   * If the "allowuuid" flag is true (default is false) then
   * a UUID *may* be passed instead of the domain name. The
   * "dom" string is treated as a UUID first and looked up,
   * and if that lookup fails then we treat "dom" as a name
   * as usual.
   * <p>
   * The optional "readonlydisk" parameter controls what we
   * do for disks which are marked <readonly/> in the libvirt
   * XML. Possible values are:
   * <p>
   * readonlydisk = "error"
   * If "readonly" is false:
   * <p>
   * The whole call is aborted with an error if any disk
   * with the <readonly/> flag is found.
   * <p>
   * If "readonly" is true:
   * <p>
   * Disks with the <readonly/> flag are added read-only.
   * <p>
   * readonlydisk = "read"
   * If "readonly" is false:
   * <p>
   * Disks with the <readonly/> flag are added read-only.
   * Other disks are added read/write.
   * <p>
   * If "readonly" is true:
   * <p>
   * Disks with the <readonly/> flag are added read-only.
   * <p>
   * readonlydisk = "write" (default)
   * If "readonly" is false:
   * <p>
   * Disks with the <readonly/> flag are added
   * read/write.
   * <p>
   * If "readonly" is true:
   * <p>
   * Disks with the <readonly/> flag are added read-only.
   * <p>
   * readonlydisk = "ignore"
   * If "readonly" is true or false:
   * <p>
   * Disks with the <readonly/> flag are skipped.
   * <p>
   * The other optional parameters are passed directly
   * through to "g.add_drive_opts".
   * <p>
   * Optional arguments are supplied in the final
   * Map<String,Object> parameter, which is a hash of the
   * argument name to its value (cast to Object). Pass an
   * empty Map or null for no optional arguments.
   * <p>
   * @throws LibGuestFSException
   */
  public int add_domain (String dom, Map<String, Object> optargs)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("add_domain: handle is closed");

    /* Unpack optional args. */
    Object _optobj;
    long _optargs_bitmask = 0;
    String libvirturi = "";
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("libvirturi");
    if (_optobj != null) {
      libvirturi = ((String) _optobj);
      _optargs_bitmask |= 1L;
    }
    boolean readonly = false;
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("readonly");
    if (_optobj != null) {
      readonly = ((Boolean) _optobj).booleanValue();
      _optargs_bitmask |= 2L;
    }
    String iface = "";
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("iface");
    if (_optobj != null) {
      iface = ((String) _optobj);
      _optargs_bitmask |= 4L;
    }
    boolean live = false;
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("live");
    if (_optobj != null) {
      live = ((Boolean) _optobj).booleanValue();
      _optargs_bitmask |= 8L;
    }
    boolean allowuuid = false;
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("allowuuid");
    if (_optobj != null) {
      allowuuid = ((Boolean) _optobj).booleanValue();
      _optargs_bitmask |= 16L;
    }
    String readonlydisk = "";
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("readonlydisk");
    if (_optobj != null) {
      readonlydisk = ((String) _optobj);
      _optargs_bitmask |= 32L;
    }

    return _add_domain (g, dom, _optargs_bitmask, libvirturi, readonly, iface, live, allowuuid, readonlydisk);
  }

  public int add_domain (String dom)
    throws LibGuestFSException
  {
    return add_domain (dom, null);
  }

  private native int _add_domain (long g, String dom, long _optargs_bitmask, String libvirturi, boolean readonly, String iface, boolean live, boolean allowuuid, String readonlydisk)
    throws LibGuestFSException;

  /**
   * get package format used by the operating system
   * <p>
   * This function and "g.inspect_get_package_management"
   * return the package format and package management tool
   * used by the inspected operating system. For example for
   * Fedora these functions would return "rpm" (package
   * format) and "yum" (package management).
   * <p>
   * This returns the string "unknown" if we could not
   * determine the package format *or* if the operating
   * system does not have a real packaging system (eg.
   * Windows).
   * <p>
   * Possible strings include: "rpm", "deb", "ebuild",
   * "pisi", "pacman", "pkgsrc". Future versions of
   * libguestfs may return other strings.
   * <p>
   * Please read "INSPECTION" in guestfs(3) for more details.
   * <p>
   * @throws LibGuestFSException
   */
  public String inspect_get_package_format (String root)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("inspect_get_package_format: handle is closed");

    return _inspect_get_package_format (g, root);
  }

  private native String _inspect_get_package_format (long g, String root)
    throws LibGuestFSException;

  /**
   * get package management tool used by the operating system
   * <p>
   * "g.inspect_get_package_format" and this function return
   * the package format and package management tool used by
   * the inspected operating system. For example for Fedora
   * these functions would return "rpm" (package format) and
   * "yum" (package management).
   * <p>
   * This returns the string "unknown" if we could not
   * determine the package management tool *or* if the
   * operating system does not have a real packaging system
   * (eg. Windows).
   * <p>
   * Possible strings include: "yum", "up2date", "apt" (for
   * all Debian derivatives), "portage", "pisi", "pacman",
   * "urpmi", "zypper". Future versions of libguestfs may
   * return other strings.
   * <p>
   * Please read "INSPECTION" in guestfs(3) for more details.
   * <p>
   * @throws LibGuestFSException
   */
  public String inspect_get_package_management (String root)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("inspect_get_package_management: handle is closed");

    return _inspect_get_package_management (g, root);
  }

  private native String _inspect_get_package_management (long g, String root)
    throws LibGuestFSException;

  /**
   * get list of applications installed in the operating system
   * <p>
   * Return the list of applications installed in the
   * operating system.
   * <p>
   * *Note:* This call works differently from other parts of
   * the inspection API. You have to call "g.inspect_os",
   * then "g.inspect_get_mountpoints", then mount up the
   * disks, before calling this. Listing applications is a
   * significantly more difficult operation which requires
   * access to the full filesystem. Also note that unlike the
   * other "g.inspect_get_*" calls which are just returning
   * data cached in the libguestfs handle, this call actually
   * reads parts of the mounted filesystems during the call.
   * <p>
   * This returns an empty list if the inspection code was
   * not able to determine the list of applications.
   * <p>
   * The application structure contains the following fields:
   * <p>
   * "app_name"
   * The name of the application. For Red Hat-derived and
   * Debian-derived Linux guests, this is the package
   * name.
   * <p>
   * "app_display_name"
   * The display name of the application, sometimes
   * localized to the install language of the guest
   * operating system.
   * <p>
   * If unavailable this is returned as an empty string
   * "". Callers needing to display something can use
   * "app_name" instead.
   * <p>
   * "app_epoch"
   * For package managers which use epochs, this contains
   * the epoch of the package (an integer). If
   * unavailable, this is returned as 0.
   * <p>
   * "app_version"
   * The version string of the application or package. If
   * unavailable this is returned as an empty string "".
   * <p>
   * "app_release"
   * The release string of the application or package,
   * for package managers that use this. If unavailable
   * this is returned as an empty string "".
   * <p>
   * "app_install_path"
   * The installation path of the application (on
   * operating systems such as Windows which use
   * installation paths). This path is in the format used
   * by the guest operating system, it is not a
   * libguestfs path.
   * <p>
   * If unavailable this is returned as an empty string
   * "".
   * <p>
   * "app_trans_path"
   * The install path translated into a libguestfs path.
   * If unavailable this is returned as an empty string
   * "".
   * <p>
   * "app_publisher"
   * The name of the publisher of the application, for
   * package managers that use this. If unavailable this
   * is returned as an empty string "".
   * <p>
   * "app_url"
   * The URL (eg. upstream URL) of the application. If
   * unavailable this is returned as an empty string "".
   * <p>
   * "app_source_package"
   * For packaging systems which support this, the name
   * of the source package. If unavailable this is
   * returned as an empty string "".
   * <p>
   * "app_summary"
   * A short (usually one line) description of the
   * application or package. If unavailable this is
   * returned as an empty string "".
   * <p>
   * "app_description"
   * A longer description of the application or package.
   * If unavailable this is returned as an empty string
   * "".
   * <p>
   * Please read "INSPECTION" in guestfs(3) for more details.
   * <p>
   * @throws LibGuestFSException
   */
  public Application[] inspect_list_applications (String root)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("inspect_list_applications: handle is closed");

    return _inspect_list_applications (g, root);
  }

  private native Application[] _inspect_list_applications (long g, String root)
    throws LibGuestFSException;

  /**
   * get hostname of the operating system
   * <p>
   * This function returns the hostname of the operating
   * system as found by inspection of the guest's
   * configuration files.
   * <p>
   * If the hostname could not be determined, then the string
   * "unknown" is returned.
   * <p>
   * Please read "INSPECTION" in guestfs(3) for more details.
   * <p>
   * @throws LibGuestFSException
   */
  public String inspect_get_hostname (String root)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("inspect_get_hostname: handle is closed");

    return _inspect_get_hostname (g, root);
  }

  private native String _inspect_get_hostname (long g, String root)
    throws LibGuestFSException;

  /**
   * get format of inspected operating system
   * <p>
   * This returns the format of the inspected operating
   * system. You can use it to detect install images, live
   * CDs and similar.
   * <p>
   * Currently defined formats are:
   * <p>
   * "installed"
   * This is an installed operating system.
   * <p>
   * "installer"
   * The disk image being inspected is not an installed
   * operating system, but a *bootable* install disk,
   * live CD, or similar.
   * <p>
   * "unknown"
   * The format of this disk image is not known.
   * <p>
   * Future versions of libguestfs may return other strings
   * here. The caller should be prepared to handle any
   * string.
   * <p>
   * Please read "INSPECTION" in guestfs(3) for more details.
   * <p>
   * @throws LibGuestFSException
   */
  public String inspect_get_format (String root)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("inspect_get_format: handle is closed");

    return _inspect_get_format (g, root);
  }

  private native String _inspect_get_format (long g, String root)
    throws LibGuestFSException;

  /**
   * get live flag for install disk
   * <p>
   * If "g.inspect_get_format" returns "installer" (this is
   * an install disk), then this returns true if a live image
   * was detected on the disk.
   * <p>
   * Please read "INSPECTION" in guestfs(3) for more details.
   * <p>
   * @throws LibGuestFSException
   */
  public boolean inspect_is_live (String root)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("inspect_is_live: handle is closed");

    return _inspect_is_live (g, root);
  }

  private native boolean _inspect_is_live (long g, String root)
    throws LibGuestFSException;

  /**
   * get netinst (network installer) flag for install disk
   * <p>
   * If "g.inspect_get_format" returns "installer" (this is
   * an install disk), then this returns true if the disk is
   * a network installer, ie. not a self-contained install CD
   * but one which is likely to require network access to
   * complete the install.
   * <p>
   * Please read "INSPECTION" in guestfs(3) for more details.
   * <p>
   * @throws LibGuestFSException
   */
  public boolean inspect_is_netinst (String root)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("inspect_is_netinst: handle is closed");

    return _inspect_is_netinst (g, root);
  }

  private native boolean _inspect_is_netinst (long g, String root)
    throws LibGuestFSException;

  /**
   * get multipart flag for install disk
   * <p>
   * If "g.inspect_get_format" returns "installer" (this is
   * an install disk), then this returns true if the disk is
   * part of a set.
   * <p>
   * Please read "INSPECTION" in guestfs(3) for more details.
   * <p>
   * @throws LibGuestFSException
   */
  public boolean inspect_is_multipart (String root)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("inspect_is_multipart: handle is closed");

    return _inspect_is_multipart (g, root);
  }

  private native boolean _inspect_is_multipart (long g, String root)
    throws LibGuestFSException;

  /**
   * set the attach method
   * <p>
   * Set the method that libguestfs uses to connect to the
   * back end guestfsd daemon. Possible methods are:
   * <p>
   * "appliance"
   * Launch an appliance and connect to it. This is the
   * ordinary method and the default.
   * <p>
   * "unix:*path*"
   * Connect to the Unix domain socket *path*.
   * <p>
   * This method lets you connect to an existing daemon
   * or (using virtio-serial) to a live guest. For more
   * information, see "ATTACHING TO RUNNING DAEMONS" in
   * guestfs(3).
   * <p>
   * @throws LibGuestFSException
   */
  public void set_attach_method (String attachmethod)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("set_attach_method: handle is closed");

    _set_attach_method (g, attachmethod);
  }

  private native void _set_attach_method (long g, String attachmethod)
    throws LibGuestFSException;

  /**
   * get the attach method
   * <p>
   * Return the current attach method. See
   * "g.set_attach_method".
   * <p>
   * @throws LibGuestFSException
   */
  public String get_attach_method ()
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("get_attach_method: handle is closed");

    return _get_attach_method (g);
  }

  private native String _get_attach_method (long g)
    throws LibGuestFSException;

  /**
   * get product variant of inspected operating system
   * <p>
   * This returns the product variant of the inspected
   * operating system.
   * <p>
   * For Windows guests, this returns the contents of the
   * Registry key "HKLM\Software\Microsoft\Windows
   * NT\CurrentVersion" "InstallationType" which is usually a
   * string such as "Client" or "Server" (other values are
   * possible). This can be used to distinguish consumer and
   * enterprise versions of Windows that have the same
   * version number (for example, Windows 7 and Windows 2008
   * Server are both version 6.1, but the former is "Client"
   * and the latter is "Server").
   * <p>
   * For enterprise Linux guests, in future we intend this to
   * return the product variant such as "Desktop", "Server"
   * and so on. But this is not implemented at present.
   * <p>
   * If the product variant could not be determined, then the
   * string "unknown" is returned.
   * <p>
   * Please read "INSPECTION" in guestfs(3) for more details.
   * See also "g.inspect_get_product_name",
   * "g.inspect_get_major_version".
   * <p>
   * @throws LibGuestFSException
   */
  public String inspect_get_product_variant (String root)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("inspect_get_product_variant: handle is closed");

    return _inspect_get_product_variant (g, root);
  }

  private native String _inspect_get_product_variant (long g, String root)
    throws LibGuestFSException;

  /**
   * get Windows CurrentControlSet of inspected operating system
   * <p>
   * This returns the Windows CurrentControlSet of the
   * inspected guest. The CurrentControlSet is a registry key
   * name such as "ControlSet001".
   * <p>
   * This call assumes that the guest is Windows and that the
   * Registry could be examined by inspection. If this is not
   * the case then an error is returned.
   * <p>
   * Please read "INSPECTION" in guestfs(3) for more details.
   * <p>
   * @throws LibGuestFSException
   */
  public String inspect_get_windows_current_control_set (String root)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("inspect_get_windows_current_control_set: handle is closed");

    return _inspect_get_windows_current_control_set (g, root);
  }

  private native String _inspect_get_windows_current_control_set (long g, String root)
    throws LibGuestFSException;

  /**
   * get drive letter mappings
   * <p>
   * This call is useful for Windows which uses a primitive
   * system of assigning drive letters (like "C:") to
   * partitions. This inspection API examines the Windows
   * Registry to find out how disks/partitions are mapped to
   * drive letters, and returns a hash table as in the
   * example below:
   * <p>
   * C      =>     /dev/vda2
   * E      =>     /dev/vdb1
   * F      =>     /dev/vdc1
   * <p>
   * Note that keys are drive letters. For Windows, the key
   * is case insensitive and just contains the drive letter,
   * without the customary colon separator character.
   * <p>
   * In future we may support other operating systems that
   * also used drive letters, but the keys for those might
   * not be case insensitive and might be longer than 1
   * character. For example in OS-9, hard drives were named
   * "h0", "h1" etc.
   * <p>
   * For Windows guests, currently only hard drive mappings
   * are returned. Removable disks (eg. DVD-ROMs) are
   * ignored.
   * <p>
   * For guests that do not use drive mappings, or if the
   * drive mappings could not be determined, this returns an
   * empty hash table.
   * <p>
   * Please read "INSPECTION" in guestfs(3) for more details.
   * See also "g.inspect_get_mountpoints",
   * "g.inspect_get_filesystems".
   * <p>
   * @throws LibGuestFSException
   */
  public Map<String,String> inspect_get_drive_mappings (String root)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("inspect_get_drive_mappings: handle is closed");

    String[] r = _inspect_get_drive_mappings (g, root);

    HashMap<String, String> rhash = new HashMap<String, String> ();
    for (int i = 0; i < r.length; i += 2)
      rhash.put (r[i], r[i+1]);
    return rhash;
  }

  private native String[] _inspect_get_drive_mappings (long g, String root)
    throws LibGuestFSException;

  /**
   * get the icon corresponding to this operating system
   * <p>
   * This function returns an icon corresponding to the
   * inspected operating system. The icon is returned as a
   * buffer containing a PNG image (re-encoded to PNG if
   * necessary).
   * <p>
   * If it was not possible to get an icon this function
   * returns a zero-length (non-NULL) buffer. *Callers must
   * check for this case*.
   * <p>
   * Libguestfs will start by looking for a file called
   * "/etc/favicon.png" or "C:\etc\favicon.png" and if it has
   * the correct format, the contents of this file will be
   * returned. You can disable favicons by passing the
   * optional "favicon" boolean as false (default is true).
   * <p>
   * If finding the favicon fails, then we look in other
   * places in the guest for a suitable icon.
   * <p>
   * If the optional "highquality" boolean is true then only
   * high quality icons are returned, which means only icons
   * of high resolution with an alpha channel. The default
   * (false) is to return any icon we can, even if it is of
   * substandard quality.
   * <p>
   * Notes:
   * <p>
   * *   Unlike most other inspection API calls, the guest's
   * disks must be mounted up before you call this, since
   * it needs to read information from the guest
   * filesystem during the call.
   * <p>
   * *   Security: The icon data comes from the untrusted
   * guest, and should be treated with caution. PNG files
   * have been known to contain exploits. Ensure that
   * libpng (or other relevant libraries) are fully up to
   * date before trying to process or display the icon.
   * <p>
   * *   The PNG image returned can be any size. It might not
   * be square. Libguestfs tries to return the largest,
   * highest quality icon available. The application must
   * scale the icon to the required size.
   * <p>
   * *   Extracting icons from Windows guests requires the
   * external "wrestool" program from the "icoutils"
   * package, and several programs ("bmptopnm",
   * "pnmtopng", "pamcut") from the "netpbm" package.
   * These must be installed separately.
   * <p>
   * *   Operating system icons are usually trademarks. Seek
   * legal advice before using trademarks in
   * applications.
   * <p>
   * Optional arguments are supplied in the final
   * Map<String,Object> parameter, which is a hash of the
   * argument name to its value (cast to Object). Pass an
   * empty Map or null for no optional arguments.
   * <p>
   * @throws LibGuestFSException
   */
  public String inspect_get_icon (String root, Map<String, Object> optargs)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("inspect_get_icon: handle is closed");

    /* Unpack optional args. */
    Object _optobj;
    long _optargs_bitmask = 0;
    boolean favicon = false;
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("favicon");
    if (_optobj != null) {
      favicon = ((Boolean) _optobj).booleanValue();
      _optargs_bitmask |= 1L;
    }
    boolean highquality = false;
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("highquality");
    if (_optobj != null) {
      highquality = ((Boolean) _optobj).booleanValue();
      _optargs_bitmask |= 2L;
    }

    return _inspect_get_icon (g, root, _optargs_bitmask, favicon, highquality);
  }

  public String inspect_get_icon (String root)
    throws LibGuestFSException
  {
    return inspect_get_icon (root, null);
  }

  private native String _inspect_get_icon (long g, String root, long _optargs_bitmask, boolean favicon, boolean highquality)
    throws LibGuestFSException;

  /**
   * set process group flag
   * <p>
   * If "pgroup" is true, child processes are placed into
   * their own process group.
   * <p>
   * The practical upshot of this is that signals like
   * "SIGINT" (from users pressing "^C") won't be received by
   * the child process.
   * <p>
   * The default for this flag is false, because usually you
   * want "^C" to kill the subprocess. Guestfish sets this
   * flag to true when used interactively, so that "^C" can
   * cancel long-running commands gracefully (see
   * "g.user_cancel").
   * <p>
   * @throws LibGuestFSException
   */
  public void set_pgroup (boolean pgroup)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("set_pgroup: handle is closed");

    _set_pgroup (g, pgroup);
  }

  private native void _set_pgroup (long g, boolean pgroup)
    throws LibGuestFSException;

  /**
   * get process group flag
   * <p>
   * This returns the process group flag.
   * <p>
   * @throws LibGuestFSException
   */
  public boolean get_pgroup ()
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("get_pgroup: handle is closed");

    return _get_pgroup (g);
  }

  private native boolean _get_pgroup (long g)
    throws LibGuestFSException;

  /**
   * set number of virtual CPUs in appliance
   * <p>
   * Change the number of virtual CPUs assigned to the
   * appliance. The default is 1. Increasing this may improve
   * performance, though often it has no effect.
   * <p>
   * This function must be called before "g.launch".
   * <p>
   * @throws LibGuestFSException
   */
  public void set_smp (int smp)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("set_smp: handle is closed");

    _set_smp (g, smp);
  }

  private native void _set_smp (long g, int smp)
    throws LibGuestFSException;

  /**
   * get number of virtual CPUs in appliance
   * <p>
   * This returns the number of virtual CPUs assigned to the
   * appliance.
   * <p>
   * @throws LibGuestFSException
   */
  public int get_smp ()
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("get_smp: handle is closed");

    return _get_smp (g);
  }

  private native int _get_smp (long g)
    throws LibGuestFSException;

  /**
   * mount on the local filesystem
   * <p>
   * This call exports the libguestfs-accessible filesystem
   * to a local mountpoint (directory) called
   * "localmountpoint". Ordinary reads and writes to files
   * and directories under "localmountpoint" are redirected
   * through libguestfs.
   * <p>
   * If the optional "readonly" flag is set to true, then
   * writes to the filesystem return error "EROFS".
   * <p>
   * "options" is a comma-separated list of mount options.
   * See guestmount(1) for some useful options.
   * <p>
   * "cachetimeout" sets the timeout (in seconds) for cached
   * directory entries. The default is 60 seconds. See
   * guestmount(1) for further information.
   * <p>
   * If "debugcalls" is set to true, then additional
   * debugging information is generated for every FUSE call.
   * <p>
   * When "g.mount_local" returns, the filesystem is ready,
   * but is not processing requests (access to it will
   * block). You have to call "g.mount_local_run" to run the
   * main loop.
   * <p>
   * See "MOUNT LOCAL" in guestfs(3) for full documentation.
   * <p>
   * Optional arguments are supplied in the final
   * Map<String,Object> parameter, which is a hash of the
   * argument name to its value (cast to Object). Pass an
   * empty Map or null for no optional arguments.
   * <p>
   * @throws LibGuestFSException
   */
  public void mount_local (String localmountpoint, Map<String, Object> optargs)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("mount_local: handle is closed");

    /* Unpack optional args. */
    Object _optobj;
    long _optargs_bitmask = 0;
    boolean readonly = false;
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("readonly");
    if (_optobj != null) {
      readonly = ((Boolean) _optobj).booleanValue();
      _optargs_bitmask |= 1L;
    }
    String options = "";
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("options");
    if (_optobj != null) {
      options = ((String) _optobj);
      _optargs_bitmask |= 2L;
    }
    int cachetimeout = 0;
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("cachetimeout");
    if (_optobj != null) {
      cachetimeout = ((Integer) _optobj).intValue();
      _optargs_bitmask |= 4L;
    }
    boolean debugcalls = false;
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("debugcalls");
    if (_optobj != null) {
      debugcalls = ((Boolean) _optobj).booleanValue();
      _optargs_bitmask |= 8L;
    }

    _mount_local (g, localmountpoint, _optargs_bitmask, readonly, options, cachetimeout, debugcalls);
  }

  public void mount_local (String localmountpoint)
    throws LibGuestFSException
  {
    mount_local (localmountpoint, null);
  }

  private native void _mount_local (long g, String localmountpoint, long _optargs_bitmask, boolean readonly, String options, int cachetimeout, boolean debugcalls)
    throws LibGuestFSException;

  /**
   * run main loop of mount on the local filesystem
   * <p>
   * Run the main loop which translates kernel calls to
   * libguestfs calls.
   * <p>
   * This should only be called after "g.mount_local" returns
   * successfully. The call will not return until the
   * filesystem is unmounted.
   * <p>
   * Note you must *not* make concurrent libguestfs calls on
   * the same handle from another thread, with the exception
   * of "g.umount_local".
   * <p>
   * You may call this from a different thread than the one
   * which called "g.mount_local", subject to the usual rules
   * for threads and libguestfs (see "MULTIPLE HANDLES AND
   * MULTIPLE THREADS" in guestfs(3)).
   * <p>
   * See "MOUNT LOCAL" in guestfs(3) for full documentation.
   * <p>
   * @throws LibGuestFSException
   */
  public void mount_local_run ()
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("mount_local_run: handle is closed");

    _mount_local_run (g);
  }

  private native void _mount_local_run (long g)
    throws LibGuestFSException;

  /**
   * unmount a locally mounted filesystem
   * <p>
   * If libguestfs is exporting the filesystem on a local
   * mountpoint, then this unmounts it.
   * <p>
   * See "MOUNT LOCAL" in guestfs(3) for full documentation.
   * <p>
   * Optional arguments are supplied in the final
   * Map<String,Object> parameter, which is a hash of the
   * argument name to its value (cast to Object). Pass an
   * empty Map or null for no optional arguments.
   * <p>
   * @throws LibGuestFSException
   */
  public void umount_local (Map<String, Object> optargs)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("umount_local: handle is closed");

    /* Unpack optional args. */
    Object _optobj;
    long _optargs_bitmask = 0;
    boolean retry = false;
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("retry");
    if (_optobj != null) {
      retry = ((Boolean) _optobj).booleanValue();
      _optargs_bitmask |= 1L;
    }

    _umount_local (g, _optargs_bitmask, retry);
  }

  public void umount_local ()
    throws LibGuestFSException
  {
    umount_local (null);
  }

  private native void _umount_local (long g, long _optargs_bitmask, boolean retry)
    throws LibGuestFSException;

  /**
   * shutdown the qemu subprocess
   * <p>
   * This is the opposite of "g.launch". It performs an
   * orderly shutdown of the backend process(es). If the
   * autosync flag is set (which is the default) then the
   * disk image is synchronized.
   * <p>
   * If the subprocess exits with an error then this function
   * will return an error, which should *not* be ignored (it
   * may indicate that the disk image could not be written
   * out properly).
   * <p>
   * It is safe to call this multiple times. Extra calls are
   * ignored.
   * <p>
   * This call does *not* close or free up the handle. You
   * still need to call "g.close" afterwards.
   * <p>
   * "g.close" will call this if you don't do it explicitly,
   * but note that any errors are ignored in that case.
   * <p>
   * @throws LibGuestFSException
   */
  public void shutdown ()
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("shutdown: handle is closed");

    _shutdown (g);
  }

  private native void _shutdown (long g)
    throws LibGuestFSException;

  /**
   * mount a guest disk at a position in the filesystem
   * <p>
   * Mount a guest disk at a position in the filesystem.
   * Block devices are named "/dev/sda", "/dev/sdb" and so
   * on, as they were added to the guest. If those block
   * devices contain partitions, they will have the usual
   * names (eg. "/dev/sda1"). Also LVM "/dev/VG/LV"-style
   * names can be used.
   * <p>
   * The rules are the same as for mount(2): A filesystem
   * must first be mounted on "/" before others can be
   * mounted. Other filesystems can only be mounted on
   * directories which already exist.
   * <p>
   * The mounted filesystem is writable, if we have
   * sufficient permissions on the underlying device.
   * <p>
   * Before libguestfs 1.13.16, this call implicitly added
   * the options "sync" and "noatime". The "sync" option
   * greatly slowed writes and caused many problems for
   * users. If your program might need to work with older
   * versions of libguestfs, use "g.mount_options" instead
   * (using an empty string for the first parameter if you
   * don't want any options).
   * <p>
   * @throws LibGuestFSException
   */
  public void mount (String device, String mountpoint)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("mount: handle is closed");

    _mount (g, device, mountpoint);
  }

  private native void _mount (long g, String device, String mountpoint)
    throws LibGuestFSException;

  /**
   * sync disks, writes are flushed through to the disk image
   * <p>
   * This syncs the disk, so that any writes are flushed
   * through to the underlying disk image.
   * <p>
   * You should always call this if you have modified a disk
   * image, before closing the handle.
   * <p>
   * @throws LibGuestFSException
   */
  public void sync ()
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("sync: handle is closed");

    _sync (g);
  }

  private native void _sync (long g)
    throws LibGuestFSException;

  /**
   * update file timestamps or create a new file
   * <p>
   * Touch acts like the touch(1) command. It can be used to
   * update the timestamps on a file, or, if the file does
   * not exist, to create a new zero-length file.
   * <p>
   * This command only works on regular files, and will fail
   * on other file types such as directories, symbolic links,
   * block special etc.
   * <p>
   * @throws LibGuestFSException
   */
  public void touch (String path)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("touch: handle is closed");

    _touch (g, path);
  }

  private native void _touch (long g, String path)
    throws LibGuestFSException;

  /**
   * list the contents of a file
   * <p>
   * Return the contents of the file named "path".
   * <p>
   * Note that this function cannot correctly handle binary
   * files (specifically, files containing "\0" character
   * which is treated as end of string). For those you need
   * to use the "g.read_file" or "g.download" functions which
   * have a more complex interface.
   * <p>
   * Because of the message protocol, there is a transfer
   * limit of somewhere between 2MB and 4MB. See "PROTOCOL
   * LIMITS" in guestfs(3).
   * <p>
   * @throws LibGuestFSException
   */
  public String cat (String path)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("cat: handle is closed");

    return _cat (g, path);
  }

  private native String _cat (long g, String path)
    throws LibGuestFSException;

  /**
   * list the files in a directory (long format)
   * <p>
   * List the files in "directory" (relative to the root
   * directory, there is no cwd) in the format of 'ls -la'.
   * <p>
   * This command is mostly useful for interactive sessions.
   * It is *not* intended that you try to parse the output
   * string.
   * <p>
   * @throws LibGuestFSException
   */
  public String ll (String directory)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("ll: handle is closed");

    return _ll (g, directory);
  }

  private native String _ll (long g, String directory)
    throws LibGuestFSException;

  /**
   * list the files in a directory
   * <p>
   * List the files in "directory" (relative to the root
   * directory, there is no cwd). The '.' and '..' entries
   * are not returned, but hidden files are shown.
   * <p>
   * This command is mostly useful for interactive sessions.
   * Programs should probably use "g.readdir" instead.
   * <p>
   * @throws LibGuestFSException
   */
  public String[] ls (String directory)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("ls: handle is closed");

    return _ls (g, directory);
  }

  private native String[] _ls (long g, String directory)
    throws LibGuestFSException;

  /**
   * list the block devices
   * <p>
   * List all the block devices.
   * <p>
   * The full block device names are returned, eg.
   * "/dev/sda".
   * <p>
   * See also "g.list_filesystems".
   * <p>
   * @throws LibGuestFSException
   */
  public String[] list_devices ()
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("list_devices: handle is closed");

    return _list_devices (g);
  }

  private native String[] _list_devices (long g)
    throws LibGuestFSException;

  /**
   * list the partitions
   * <p>
   * List all the partitions detected on all block devices.
   * <p>
   * The full partition device names are returned, eg.
   * "/dev/sda1"
   * <p>
   * This does not return logical volumes. For that you will
   * need to call "g.lvs".
   * <p>
   * See also "g.list_filesystems".
   * <p>
   * @throws LibGuestFSException
   */
  public String[] list_partitions ()
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("list_partitions: handle is closed");

    return _list_partitions (g);
  }

  private native String[] _list_partitions (long g)
    throws LibGuestFSException;

  /**
   * list the LVM physical volumes (PVs)
   * <p>
   * List all the physical volumes detected. This is the
   * equivalent of the pvs(8) command.
   * <p>
   * This returns a list of just the device names that
   * contain PVs (eg. "/dev/sda2").
   * <p>
   * See also "g.pvs_full".
   * <p>
   * @throws LibGuestFSException
   */
  public String[] pvs ()
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("pvs: handle is closed");

    return _pvs (g);
  }

  private native String[] _pvs (long g)
    throws LibGuestFSException;

  /**
   * list the LVM volume groups (VGs)
   * <p>
   * List all the volumes groups detected. This is the
   * equivalent of the vgs(8) command.
   * <p>
   * This returns a list of just the volume group names that
   * were detected (eg. "VolGroup00").
   * <p>
   * See also "g.vgs_full".
   * <p>
   * @throws LibGuestFSException
   */
  public String[] vgs ()
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("vgs: handle is closed");

    return _vgs (g);
  }

  private native String[] _vgs (long g)
    throws LibGuestFSException;

  /**
   * list the LVM logical volumes (LVs)
   * <p>
   * List all the logical volumes detected. This is the
   * equivalent of the lvs(8) command.
   * <p>
   * This returns a list of the logical volume device names
   * (eg. "/dev/VolGroup00/LogVol00").
   * <p>
   * See also "g.lvs_full", "g.list_filesystems".
   * <p>
   * @throws LibGuestFSException
   */
  public String[] lvs ()
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("lvs: handle is closed");

    return _lvs (g);
  }

  private native String[] _lvs (long g)
    throws LibGuestFSException;

  /**
   * list the LVM physical volumes (PVs)
   * <p>
   * List all the physical volumes detected. This is the
   * equivalent of the pvs(8) command. The "full" version
   * includes all fields.
   * <p>
   * @throws LibGuestFSException
   */
  public PV[] pvs_full ()
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("pvs_full: handle is closed");

    return _pvs_full (g);
  }

  private native PV[] _pvs_full (long g)
    throws LibGuestFSException;

  /**
   * list the LVM volume groups (VGs)
   * <p>
   * List all the volumes groups detected. This is the
   * equivalent of the vgs(8) command. The "full" version
   * includes all fields.
   * <p>
   * @throws LibGuestFSException
   */
  public VG[] vgs_full ()
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("vgs_full: handle is closed");

    return _vgs_full (g);
  }

  private native VG[] _vgs_full (long g)
    throws LibGuestFSException;

  /**
   * list the LVM logical volumes (LVs)
   * <p>
   * List all the logical volumes detected. This is the
   * equivalent of the lvs(8) command. The "full" version
   * includes all fields.
   * <p>
   * @throws LibGuestFSException
   */
  public LV[] lvs_full ()
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("lvs_full: handle is closed");

    return _lvs_full (g);
  }

  private native LV[] _lvs_full (long g)
    throws LibGuestFSException;

  /**
   * read file as lines
   * <p>
   * Return the contents of the file named "path".
   * <p>
   * The file contents are returned as a list of lines.
   * Trailing "LF" and "CRLF" character sequences are *not*
   * returned.
   * <p>
   * Note that this function cannot correctly handle binary
   * files (specifically, files containing "\0" character
   * which is treated as end of line). For those you need to
   * use the "g.read_file" function which has a more complex
   * interface.
   * <p>
   * @throws LibGuestFSException
   */
  public String[] read_lines (String path)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("read_lines: handle is closed");

    return _read_lines (g, path);
  }

  private native String[] _read_lines (long g, String path)
    throws LibGuestFSException;

  /**
   * create a new Augeas handle
   * <p>
   * Create a new Augeas handle for editing configuration
   * files. If there was any previous Augeas handle
   * associated with this guestfs session, then it is closed.
   * <p>
   * You must call this before using any other "g.aug_*"
   * commands.
   * <p>
   * "root" is the filesystem root. "root" must not be NULL,
   * use "/" instead.
   * <p>
   * The flags are the same as the flags defined in
   * <augeas.h>, the logical *or* of the following integers:
   * <p>
   * "AUG_SAVE_BACKUP" = 1
   * Keep the original file with a ".augsave" extension.
   * <p>
   * "AUG_SAVE_NEWFILE" = 2
   * Save changes into a file with extension ".augnew",
   * and do not overwrite original. Overrides
   * "AUG_SAVE_BACKUP".
   * <p>
   * "AUG_TYPE_CHECK" = 4
   * Typecheck lenses.
   * <p>
   * This option is only useful when debugging Augeas
   * lenses. Use of this option may require additional
   * memory for the libguestfs appliance. You may need to
   * set the "LIBGUESTFS_MEMSIZE" environment variable or
   * call "g.set_memsize".
   * <p>
   * "AUG_NO_STDINC" = 8
   * Do not use standard load path for modules.
   * <p>
   * "AUG_SAVE_NOOP" = 16
   * Make save a no-op, just record what would have been
   * changed.
   * <p>
   * "AUG_NO_LOAD" = 32
   * Do not load the tree in "g.aug_init".
   * <p>
   * To close the handle, you can call "g.aug_close".
   * <p>
   * To find out more about Augeas, see <http://augeas.net/>.
   * <p>
   * @throws LibGuestFSException
   */
  public void aug_init (String root, int flags)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("aug_init: handle is closed");

    _aug_init (g, root, flags);
  }

  private native void _aug_init (long g, String root, int flags)
    throws LibGuestFSException;

  /**
   * close the current Augeas handle
   * <p>
   * Close the current Augeas handle and free up any
   * resources used by it. After calling this, you have to
   * call "g.aug_init" again before you can use any other
   * Augeas functions.
   * <p>
   * @throws LibGuestFSException
   */
  public void aug_close ()
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("aug_close: handle is closed");

    _aug_close (g);
  }

  private native void _aug_close (long g)
    throws LibGuestFSException;

  /**
   * define an Augeas variable
   * <p>
   * Defines an Augeas variable "name" whose value is the
   * result of evaluating "expr". If "expr" is NULL, then
   * "name" is undefined.
   * <p>
   * On success this returns the number of nodes in "expr",
   * or 0 if "expr" evaluates to something which is not a
   * nodeset.
   * <p>
   * @throws LibGuestFSException
   */
  public int aug_defvar (String name, String expr)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("aug_defvar: handle is closed");

    return _aug_defvar (g, name, expr);
  }

  private native int _aug_defvar (long g, String name, String expr)
    throws LibGuestFSException;

  /**
   * define an Augeas node
   * <p>
   * Defines a variable "name" whose value is the result of
   * evaluating "expr".
   * <p>
   * If "expr" evaluates to an empty nodeset, a node is
   * created, equivalent to calling "g.aug_set" "expr",
   * "value". "name" will be the nodeset containing that
   * single node.
   * <p>
   * On success this returns a pair containing the number of
   * nodes in the nodeset, and a boolean flag if a node was
   * created.
   * <p>
   * @throws LibGuestFSException
   */
  public IntBool aug_defnode (String name, String expr, String val)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("aug_defnode: handle is closed");

    return _aug_defnode (g, name, expr, val);
  }

  private native IntBool _aug_defnode (long g, String name, String expr, String val)
    throws LibGuestFSException;

  /**
   * look up the value of an Augeas path
   * <p>
   * Look up the value associated with "path". If "path"
   * matches exactly one node, the "value" is returned.
   * <p>
   * @throws LibGuestFSException
   */
  public String aug_get (String augpath)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("aug_get: handle is closed");

    return _aug_get (g, augpath);
  }

  private native String _aug_get (long g, String augpath)
    throws LibGuestFSException;

  /**
   * set Augeas path to value
   * <p>
   * Set the value associated with "path" to "val".
   * <p>
   * In the Augeas API, it is possible to clear a node by
   * setting the value to NULL. Due to an oversight in the
   * libguestfs API you cannot do that with this call.
   * Instead you must use the "g.aug_clear" call.
   * <p>
   * @throws LibGuestFSException
   */
  public void aug_set (String augpath, String val)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("aug_set: handle is closed");

    _aug_set (g, augpath, val);
  }

  private native void _aug_set (long g, String augpath, String val)
    throws LibGuestFSException;

  /**
   * insert a sibling Augeas node
   * <p>
   * Create a new sibling "label" for "path", inserting it
   * into the tree before or after "path" (depending on the
   * boolean flag "before").
   * <p>
   * "path" must match exactly one existing node in the tree,
   * and "label" must be a label, ie. not contain "/", "*" or
   * end with a bracketed index "[N]".
   * <p>
   * @throws LibGuestFSException
   */
  public void aug_insert (String augpath, String label, boolean before)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("aug_insert: handle is closed");

    _aug_insert (g, augpath, label, before);
  }

  private native void _aug_insert (long g, String augpath, String label, boolean before)
    throws LibGuestFSException;

  /**
   * remove an Augeas path
   * <p>
   * Remove "path" and all of its children.
   * <p>
   * On success this returns the number of entries which were
   * removed.
   * <p>
   * @throws LibGuestFSException
   */
  public int aug_rm (String augpath)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("aug_rm: handle is closed");

    return _aug_rm (g, augpath);
  }

  private native int _aug_rm (long g, String augpath)
    throws LibGuestFSException;

  /**
   * move Augeas node
   * <p>
   * Move the node "src" to "dest". "src" must match exactly
   * one node. "dest" is overwritten if it exists.
   * <p>
   * @throws LibGuestFSException
   */
  public void aug_mv (String src, String dest)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("aug_mv: handle is closed");

    _aug_mv (g, src, dest);
  }

  private native void _aug_mv (long g, String src, String dest)
    throws LibGuestFSException;

  /**
   * return Augeas nodes which match augpath
   * <p>
   * Returns a list of paths which match the path expression
   * "path". The returned paths are sufficiently qualified so
   * that they match exactly one node in the current tree.
   * <p>
   * @throws LibGuestFSException
   */
  public String[] aug_match (String augpath)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("aug_match: handle is closed");

    return _aug_match (g, augpath);
  }

  private native String[] _aug_match (long g, String augpath)
    throws LibGuestFSException;

  /**
   * write all pending Augeas changes to disk
   * <p>
   * This writes all pending changes to disk.
   * <p>
   * The flags which were passed to "g.aug_init" affect
   * exactly how files are saved.
   * <p>
   * @throws LibGuestFSException
   */
  public void aug_save ()
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("aug_save: handle is closed");

    _aug_save (g);
  }

  private native void _aug_save (long g)
    throws LibGuestFSException;

  /**
   * load files into the tree
   * <p>
   * Load files into the tree.
   * <p>
   * See "aug_load" in the Augeas documentation for the full
   * gory details.
   * <p>
   * @throws LibGuestFSException
   */
  public void aug_load ()
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("aug_load: handle is closed");

    _aug_load (g);
  }

  private native void _aug_load (long g)
    throws LibGuestFSException;

  /**
   * list Augeas nodes under augpath
   * <p>
   * This is just a shortcut for listing "g.aug_match"
   * "path/*" and sorting the resulting nodes into
   * alphabetical order.
   * <p>
   * @throws LibGuestFSException
   */
  public String[] aug_ls (String augpath)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("aug_ls: handle is closed");

    return _aug_ls (g, augpath);
  }

  private native String[] _aug_ls (long g, String augpath)
    throws LibGuestFSException;

  /**
   * remove a file
   * <p>
   * Remove the single file "path".
   * <p>
   * @throws LibGuestFSException
   */
  public void rm (String path)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("rm: handle is closed");

    _rm (g, path);
  }

  private native void _rm (long g, String path)
    throws LibGuestFSException;

  /**
   * remove a directory
   * <p>
   * Remove the single directory "path".
   * <p>
   * @throws LibGuestFSException
   */
  public void rmdir (String path)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("rmdir: handle is closed");

    _rmdir (g, path);
  }

  private native void _rmdir (long g, String path)
    throws LibGuestFSException;

  /**
   * remove a file or directory recursively
   * <p>
   * Remove the file or directory "path", recursively
   * removing the contents if its a directory. This is like
   * the "rm -rf" shell command.
   * <p>
   * @throws LibGuestFSException
   */
  public void rm_rf (String path)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("rm_rf: handle is closed");

    _rm_rf (g, path);
  }

  private native void _rm_rf (long g, String path)
    throws LibGuestFSException;

  /**
   * create a directory
   * <p>
   * Create a directory named "path".
   * <p>
   * @throws LibGuestFSException
   */
  public void mkdir (String path)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("mkdir: handle is closed");

    _mkdir (g, path);
  }

  private native void _mkdir (long g, String path)
    throws LibGuestFSException;

  /**
   * create a directory and parents
   * <p>
   * Create a directory named "path", creating any parent
   * directories as necessary. This is like the "mkdir -p"
   * shell command.
   * <p>
   * @throws LibGuestFSException
   */
  public void mkdir_p (String path)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("mkdir_p: handle is closed");

    _mkdir_p (g, path);
  }

  private native void _mkdir_p (long g, String path)
    throws LibGuestFSException;

  /**
   * change file mode
   * <p>
   * Change the mode (permissions) of "path" to "mode". Only
   * numeric modes are supported.
   * <p>
   * *Note*: When using this command from guestfish, "mode"
   * by default would be decimal, unless you prefix it with 0
   * to get octal, ie. use 0700 not 700.
   * <p>
   * The mode actually set is affected by the umask.
   * <p>
   * @throws LibGuestFSException
   */
  public void chmod (int mode, String path)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("chmod: handle is closed");

    _chmod (g, mode, path);
  }

  private native void _chmod (long g, int mode, String path)
    throws LibGuestFSException;

  /**
   * change file owner and group
   * <p>
   * Change the file owner to "owner" and group to "group".
   * <p>
   * Only numeric uid and gid are supported. If you want to
   * use names, you will need to locate and parse the
   * password file yourself (Augeas support makes this
   * relatively easy).
   * <p>
   * @throws LibGuestFSException
   */
  public void chown (int owner, int group, String path)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("chown: handle is closed");

    _chown (g, owner, group, path);
  }

  private native void _chown (long g, int owner, int group, String path)
    throws LibGuestFSException;

  /**
   * test if file or directory exists
   * <p>
   * This returns "true" if and only if there is a file,
   * directory (or anything) with the given "path" name.
   * <p>
   * See also "g.is_file", "g.is_dir", "g.stat".
   * <p>
   * @throws LibGuestFSException
   */
  public boolean exists (String path)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("exists: handle is closed");

    return _exists (g, path);
  }

  private native boolean _exists (long g, String path)
    throws LibGuestFSException;

  /**
   * test if a regular file
   * <p>
   * This returns "true" if and only if there is a regular
   * file with the given "path" name. Note that it returns
   * false for other objects like directories.
   * <p>
   * See also "g.stat".
   * <p>
   * @throws LibGuestFSException
   */
  public boolean is_file (String path)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("is_file: handle is closed");

    return _is_file (g, path);
  }

  private native boolean _is_file (long g, String path)
    throws LibGuestFSException;

  /**
   * test if a directory
   * <p>
   * This returns "true" if and only if there is a directory
   * with the given "path" name. Note that it returns false
   * for other objects like files.
   * <p>
   * See also "g.stat".
   * <p>
   * @throws LibGuestFSException
   */
  public boolean is_dir (String path)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("is_dir: handle is closed");

    return _is_dir (g, path);
  }

  private native boolean _is_dir (long g, String path)
    throws LibGuestFSException;

  /**
   * create an LVM physical volume
   * <p>
   * This creates an LVM physical volume on the named
   * "device", where "device" should usually be a partition
   * name such as "/dev/sda1".
   * <p>
   * @throws LibGuestFSException
   */
  public void pvcreate (String device)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("pvcreate: handle is closed");

    _pvcreate (g, device);
  }

  private native void _pvcreate (long g, String device)
    throws LibGuestFSException;

  /**
   * create an LVM volume group
   * <p>
   * This creates an LVM volume group called "volgroup" from
   * the non-empty list of physical volumes "physvols".
   * <p>
   * @throws LibGuestFSException
   */
  public void vgcreate (String volgroup, String[] physvols)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("vgcreate: handle is closed");

    _vgcreate (g, volgroup, physvols);
  }

  private native void _vgcreate (long g, String volgroup, String[] physvols)
    throws LibGuestFSException;

  /**
   * create an LVM logical volume
   * <p>
   * This creates an LVM logical volume called "logvol" on
   * the volume group "volgroup", with "size" megabytes.
   * <p>
   * @throws LibGuestFSException
   */
  public void lvcreate (String logvol, String volgroup, int mbytes)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("lvcreate: handle is closed");

    _lvcreate (g, logvol, volgroup, mbytes);
  }

  private native void _lvcreate (long g, String logvol, String volgroup, int mbytes)
    throws LibGuestFSException;

  /**
   * make a filesystem
   * <p>
   * This creates a filesystem on "device" (usually a
   * partition or LVM logical volume). The filesystem type is
   * "fstype", for example "ext3".
   * <p>
   * @throws LibGuestFSException
   */
  public void mkfs (String fstype, String device)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("mkfs: handle is closed");

    _mkfs (g, fstype, device);
  }

  private native void _mkfs (long g, String fstype, String device)
    throws LibGuestFSException;

  /**
   * create partitions on a block device
   * <p>
   * This is a direct interface to the sfdisk(8) program for
   * creating partitions on block devices.
   * <p>
   * "device" should be a block device, for example
   * "/dev/sda".
   * <p>
   * "cyls", "heads" and "sectors" are the number of
   * cylinders, heads and sectors on the device, which are
   * passed directly to sfdisk as the *-C*, *-H* and *-S*
   * parameters. If you pass 0 for any of these, then the
   * corresponding parameter is omitted. Usually for 'large'
   * disks, you can just pass 0 for these, but for small
   * (floppy-sized) disks, sfdisk (or rather, the kernel)
   * cannot work out the right geometry and you will need to
   * tell it.
   * <p>
   * "lines" is a list of lines that we feed to "sfdisk". For
   * more information refer to the sfdisk(8) manpage.
   * <p>
   * To create a single partition occupying the whole disk,
   * you would pass "lines" as a single element list, when
   * the single element being the string "," (comma).
   * <p>
   * See also: "g.sfdisk_l", "g.sfdisk_N", "g.part_init"
   * <p>
   * *This function is deprecated.* In new code, use the
   * "part_add" call instead.
   * <p>
   * Deprecated functions will not be removed from the API,
   * but the fact that they are deprecated indicates that
   * there are problems with correct use of these functions.
   * <p>
   * @throws LibGuestFSException
   */
  public void sfdisk (String device, int cyls, int heads, int sectors, String[] lines)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("sfdisk: handle is closed");

    _sfdisk (g, device, cyls, heads, sectors, lines);
  }

  private native void _sfdisk (long g, String device, int cyls, int heads, int sectors, String[] lines)
    throws LibGuestFSException;

  /**
   * create a file
   * <p>
   * This call creates a file called "path". The contents of
   * the file is the string "content" (which can contain any
   * 8 bit data), with length "size".
   * <p>
   * As a special case, if "size" is 0 then the length is
   * calculated using "strlen" (so in this case the content
   * cannot contain embedded ASCII NULs).
   * <p>
   * *NB.* Owing to a bug, writing content containing ASCII
   * NUL characters does *not* work, even if the length is
   * specified.
   * <p>
   * Because of the message protocol, there is a transfer
   * limit of somewhere between 2MB and 4MB. See "PROTOCOL
   * LIMITS" in guestfs(3).
   * <p>
   * *This function is deprecated.* In new code, use the
   * "write" call instead.
   * <p>
   * Deprecated functions will not be removed from the API,
   * but the fact that they are deprecated indicates that
   * there are problems with correct use of these functions.
   * <p>
   * @throws LibGuestFSException
   */
  public void write_file (String path, String content, int size)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("write_file: handle is closed");

    _write_file (g, path, content, size);
  }

  private native void _write_file (long g, String path, String content, int size)
    throws LibGuestFSException;

  /**
   * unmount a filesystem
   * <p>
   * This unmounts the given filesystem. The filesystem may
   * be specified either by its mountpoint (path) or the
   * device which contains the filesystem.
   * <p>
   * @throws LibGuestFSException
   */
  public void umount (String pathordevice)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("umount: handle is closed");

    _umount (g, pathordevice);
  }

  private native void _umount (long g, String pathordevice)
    throws LibGuestFSException;

  /**
   * show mounted filesystems
   * <p>
   * This returns the list of currently mounted filesystems.
   * It returns the list of devices (eg. "/dev/sda1",
   * "/dev/VG/LV").
   * <p>
   * Some internal mounts are not shown.
   * <p>
   * See also: "g.mountpoints"
   * <p>
   * @throws LibGuestFSException
   */
  public String[] mounts ()
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("mounts: handle is closed");

    return _mounts (g);
  }

  private native String[] _mounts (long g)
    throws LibGuestFSException;

  /**
   * unmount all filesystems
   * <p>
   * This unmounts all mounted filesystems.
   * <p>
   * Some internal mounts are not unmounted by this call.
   * <p>
   * @throws LibGuestFSException
   */
  public void umount_all ()
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("umount_all: handle is closed");

    _umount_all (g);
  }

  private native void _umount_all (long g)
    throws LibGuestFSException;

  /**
   * remove all LVM LVs, VGs and PVs
   * <p>
   * This command removes all LVM logical volumes, volume
   * groups and physical volumes.
   * <p>
   * @throws LibGuestFSException
   */
  public void lvm_remove_all ()
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("lvm_remove_all: handle is closed");

    _lvm_remove_all (g);
  }

  private native void _lvm_remove_all (long g)
    throws LibGuestFSException;

  /**
   * determine file type
   * <p>
   * This call uses the standard file(1) command to determine
   * the type or contents of the file.
   * <p>
   * This call will also transparently look inside various
   * types of compressed file.
   * <p>
   * The exact command which runs is "file -zb path". Note in
   * particular that the filename is not prepended to the
   * output (the *-b* option).
   * <p>
   * The output depends on the output of the underlying
   * file(1) command and it can change in future in ways
   * beyond our control. In other words, the output is not
   * guaranteed by the ABI.
   * <p>
   * See also: file(1), "g.vfs_type", "g.lstat", "g.is_file",
   * "g.is_blockdev" (etc), "g.is_zero".
   * <p>
   * @throws LibGuestFSException
   */
  public String file (String path)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("file: handle is closed");

    return _file (g, path);
  }

  private native String _file (long g, String path)
    throws LibGuestFSException;

  /**
   * run a command from the guest filesystem
   * <p>
   * This call runs a command from the guest filesystem. The
   * filesystem must be mounted, and must contain a
   * compatible operating system (ie. something Linux, with
   * the same or compatible processor architecture).
   * <p>
   * The single parameter is an argv-style list of arguments.
   * The first element is the name of the program to run.
   * Subsequent elements are parameters. The list must be
   * non-empty (ie. must contain a program name). Note that
   * the command runs directly, and is *not* invoked via the
   * shell (see "g.sh").
   * <p>
   * The return value is anything printed to *stdout* by the
   * command.
   * <p>
   * If the command returns a non-zero exit status, then this
   * function returns an error message. The error message
   * string is the content of *stderr* from the command.
   * <p>
   * The $PATH environment variable will contain at least
   * "/usr/bin" and "/bin". If you require a program from
   * another location, you should provide the full path in
   * the first parameter.
   * <p>
   * Shared libraries and data files required by the program
   * must be available on filesystems which are mounted in
   * the correct places. It is the caller's responsibility to
   * ensure all filesystems that are needed are mounted at
   * the right locations.
   * <p>
   * Because of the message protocol, there is a transfer
   * limit of somewhere between 2MB and 4MB. See "PROTOCOL
   * LIMITS" in guestfs(3).
   * <p>
   * @throws LibGuestFSException
   */
  public String command (String[] arguments)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("command: handle is closed");

    return _command (g, arguments);
  }

  private native String _command (long g, String[] arguments)
    throws LibGuestFSException;

  /**
   * run a command, returning lines
   * <p>
   * This is the same as "g.command", but splits the result
   * into a list of lines.
   * <p>
   * See also: "g.sh_lines"
   * <p>
   * Because of the message protocol, there is a transfer
   * limit of somewhere between 2MB and 4MB. See "PROTOCOL
   * LIMITS" in guestfs(3).
   * <p>
   * @throws LibGuestFSException
   */
  public String[] command_lines (String[] arguments)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("command_lines: handle is closed");

    return _command_lines (g, arguments);
  }

  private native String[] _command_lines (long g, String[] arguments)
    throws LibGuestFSException;

  /**
   * get file information
   * <p>
   * Returns file information for the given "path".
   * <p>
   * This is the same as the stat(2) system call.
   * <p>
   * @throws LibGuestFSException
   */
  public Stat stat (String path)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("stat: handle is closed");

    return _stat (g, path);
  }

  private native Stat _stat (long g, String path)
    throws LibGuestFSException;

  /**
   * get file information for a symbolic link
   * <p>
   * Returns file information for the given "path".
   * <p>
   * This is the same as "g.stat" except that if "path" is a
   * symbolic link, then the link is stat-ed, not the file it
   * refers to.
   * <p>
   * This is the same as the lstat(2) system call.
   * <p>
   * @throws LibGuestFSException
   */
  public Stat lstat (String path)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("lstat: handle is closed");

    return _lstat (g, path);
  }

  private native Stat _lstat (long g, String path)
    throws LibGuestFSException;

  /**
   * get file system statistics
   * <p>
   * Returns file system statistics for any mounted file
   * system. "path" should be a file or directory in the
   * mounted file system (typically it is the mount point
   * itself, but it doesn't need to be).
   * <p>
   * This is the same as the statvfs(2) system call.
   * <p>
   * @throws LibGuestFSException
   */
  public StatVFS statvfs (String path)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("statvfs: handle is closed");

    return _statvfs (g, path);
  }

  private native StatVFS _statvfs (long g, String path)
    throws LibGuestFSException;

  /**
   * get ext2/ext3/ext4 superblock details
   * <p>
   * This returns the contents of the ext2, ext3 or ext4
   * filesystem superblock on "device".
   * <p>
   * It is the same as running "tune2fs -l device". See
   * tune2fs(8) manpage for more details. The list of fields
   * returned isn't clearly defined, and depends on both the
   * version of "tune2fs" that libguestfs was built against,
   * and the filesystem itself.
   * <p>
   * @throws LibGuestFSException
   */
  public Map<String,String> tune2fs_l (String device)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("tune2fs_l: handle is closed");

    String[] r = _tune2fs_l (g, device);

    HashMap<String, String> rhash = new HashMap<String, String> ();
    for (int i = 0; i < r.length; i += 2)
      rhash.put (r[i], r[i+1]);
    return rhash;
  }

  private native String[] _tune2fs_l (long g, String device)
    throws LibGuestFSException;

  /**
   * set block device to read-only
   * <p>
   * Sets the block device named "device" to read-only.
   * <p>
   * This uses the blockdev(8) command.
   * <p>
   * @throws LibGuestFSException
   */
  public void blockdev_setro (String device)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("blockdev_setro: handle is closed");

    _blockdev_setro (g, device);
  }

  private native void _blockdev_setro (long g, String device)
    throws LibGuestFSException;

  /**
   * set block device to read-write
   * <p>
   * Sets the block device named "device" to read-write.
   * <p>
   * This uses the blockdev(8) command.
   * <p>
   * @throws LibGuestFSException
   */
  public void blockdev_setrw (String device)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("blockdev_setrw: handle is closed");

    _blockdev_setrw (g, device);
  }

  private native void _blockdev_setrw (long g, String device)
    throws LibGuestFSException;

  /**
   * is block device set to read-only
   * <p>
   * Returns a boolean indicating if the block device is
   * read-only (true if read-only, false if not).
   * <p>
   * This uses the blockdev(8) command.
   * <p>
   * @throws LibGuestFSException
   */
  public boolean blockdev_getro (String device)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("blockdev_getro: handle is closed");

    return _blockdev_getro (g, device);
  }

  private native boolean _blockdev_getro (long g, String device)
    throws LibGuestFSException;

  /**
   * get sectorsize of block device
   * <p>
   * This returns the size of sectors on a block device.
   * Usually 512, but can be larger for modern devices.
   * <p>
   * (Note, this is not the size in sectors, use
   * "g.blockdev_getsz" for that).
   * <p>
   * This uses the blockdev(8) command.
   * <p>
   * @throws LibGuestFSException
   */
  public int blockdev_getss (String device)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("blockdev_getss: handle is closed");

    return _blockdev_getss (g, device);
  }

  private native int _blockdev_getss (long g, String device)
    throws LibGuestFSException;

  /**
   * get blocksize of block device
   * <p>
   * This returns the block size of a device.
   * <p>
   * (Note this is different from both *size in blocks* and
   * *filesystem block size*).
   * <p>
   * This uses the blockdev(8) command.
   * <p>
   * @throws LibGuestFSException
   */
  public int blockdev_getbsz (String device)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("blockdev_getbsz: handle is closed");

    return _blockdev_getbsz (g, device);
  }

  private native int _blockdev_getbsz (long g, String device)
    throws LibGuestFSException;

  /**
   * set blocksize of block device
   * <p>
   * This sets the block size of a device.
   * <p>
   * (Note this is different from both *size in blocks* and
   * *filesystem block size*).
   * <p>
   * This uses the blockdev(8) command.
   * <p>
   * @throws LibGuestFSException
   */
  public void blockdev_setbsz (String device, int blocksize)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("blockdev_setbsz: handle is closed");

    _blockdev_setbsz (g, device, blocksize);
  }

  private native void _blockdev_setbsz (long g, String device, int blocksize)
    throws LibGuestFSException;

  /**
   * get total size of device in 512-byte sectors
   * <p>
   * This returns the size of the device in units of 512-byte
   * sectors (even if the sectorsize isn't 512 bytes ...
   * weird).
   * <p>
   * See also "g.blockdev_getss" for the real sector size of
   * the device, and "g.blockdev_getsize64" for the more
   * useful *size in bytes*.
   * <p>
   * This uses the blockdev(8) command.
   * <p>
   * @throws LibGuestFSException
   */
  public long blockdev_getsz (String device)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("blockdev_getsz: handle is closed");

    return _blockdev_getsz (g, device);
  }

  private native long _blockdev_getsz (long g, String device)
    throws LibGuestFSException;

  /**
   * get total size of device in bytes
   * <p>
   * This returns the size of the device in bytes.
   * <p>
   * See also "g.blockdev_getsz".
   * <p>
   * This uses the blockdev(8) command.
   * <p>
   * @throws LibGuestFSException
   */
  public long blockdev_getsize64 (String device)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("blockdev_getsize64: handle is closed");

    return _blockdev_getsize64 (g, device);
  }

  private native long _blockdev_getsize64 (long g, String device)
    throws LibGuestFSException;

  /**
   * flush device buffers
   * <p>
   * This tells the kernel to flush internal buffers
   * associated with "device".
   * <p>
   * This uses the blockdev(8) command.
   * <p>
   * @throws LibGuestFSException
   */
  public void blockdev_flushbufs (String device)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("blockdev_flushbufs: handle is closed");

    _blockdev_flushbufs (g, device);
  }

  private native void _blockdev_flushbufs (long g, String device)
    throws LibGuestFSException;

  /**
   * reread partition table
   * <p>
   * Reread the partition table on "device".
   * <p>
   * This uses the blockdev(8) command.
   * <p>
   * @throws LibGuestFSException
   */
  public void blockdev_rereadpt (String device)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("blockdev_rereadpt: handle is closed");

    _blockdev_rereadpt (g, device);
  }

  private native void _blockdev_rereadpt (long g, String device)
    throws LibGuestFSException;

  /**
   * upload a file from the local machine
   * <p>
   * Upload local file "filename" to "remotefilename" on the
   * filesystem.
   * <p>
   * "filename" can also be a named pipe.
   * <p>
   * See also "g.download".
   * <p>
   * @throws LibGuestFSException
   */
  public void upload (String filename, String remotefilename)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("upload: handle is closed");

    _upload (g, filename, remotefilename);
  }

  private native void _upload (long g, String filename, String remotefilename)
    throws LibGuestFSException;

  /**
   * download a file to the local machine
   * <p>
   * Download file "remotefilename" and save it as "filename"
   * on the local machine.
   * <p>
   * "filename" can also be a named pipe.
   * <p>
   * See also "g.upload", "g.cat".
   * <p>
   * @throws LibGuestFSException
   */
  public void download (String remotefilename, String filename)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("download: handle is closed");

    _download (g, remotefilename, filename);
  }

  private native void _download (long g, String remotefilename, String filename)
    throws LibGuestFSException;

  /**
   * compute MD5, SHAx or CRC checksum of file
   * <p>
   * This call computes the MD5, SHAx or CRC checksum of the
   * file named "path".
   * <p>
   * The type of checksum to compute is given by the
   * "csumtype" parameter which must have one of the
   * following values:
   * <p>
   * "crc"
   * Compute the cyclic redundancy check (CRC) specified
   * by POSIX for the "cksum" command.
   * <p>
   * "md5"
   * Compute the MD5 hash (using the "md5sum" program).
   * <p>
   * "sha1"
   * Compute the SHA1 hash (using the "sha1sum" program).
   * <p>
   * "sha224"
   * Compute the SHA224 hash (using the "sha224sum"
   * program).
   * <p>
   * "sha256"
   * Compute the SHA256 hash (using the "sha256sum"
   * program).
   * <p>
   * "sha384"
   * Compute the SHA384 hash (using the "sha384sum"
   * program).
   * <p>
   * "sha512"
   * Compute the SHA512 hash (using the "sha512sum"
   * program).
   * <p>
   * The checksum is returned as a printable string.
   * <p>
   * To get the checksum for a device, use
   * "g.checksum_device".
   * <p>
   * To get the checksums for many files, use
   * "g.checksums_out".
   * <p>
   * @throws LibGuestFSException
   */
  public String checksum (String csumtype, String path)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("checksum: handle is closed");

    return _checksum (g, csumtype, path);
  }

  private native String _checksum (long g, String csumtype, String path)
    throws LibGuestFSException;

  /**
   * unpack tarfile to directory
   * <p>
   * This command uploads and unpacks local file "tarfile"
   * (an *uncompressed* tar file) into "directory".
   * <p>
   * To upload a compressed tarball, use "g.tgz_in" or
   * "g.txz_in".
   * <p>
   * @throws LibGuestFSException
   */
  public void tar_in (String tarfile, String directory)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("tar_in: handle is closed");

    _tar_in (g, tarfile, directory);
  }

  private native void _tar_in (long g, String tarfile, String directory)
    throws LibGuestFSException;

  /**
   * pack directory into tarfile
   * <p>
   * This command packs the contents of "directory" and
   * downloads it to local file "tarfile".
   * <p>
   * To download a compressed tarball, use "g.tgz_out" or
   * "g.txz_out".
   * <p>
   * @throws LibGuestFSException
   */
  public void tar_out (String directory, String tarfile)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("tar_out: handle is closed");

    _tar_out (g, directory, tarfile);
  }

  private native void _tar_out (long g, String directory, String tarfile)
    throws LibGuestFSException;

  /**
   * unpack compressed tarball to directory
   * <p>
   * This command uploads and unpacks local file "tarball" (a
   * *gzip compressed* tar file) into "directory".
   * <p>
   * To upload an uncompressed tarball, use "g.tar_in".
   * <p>
   * @throws LibGuestFSException
   */
  public void tgz_in (String tarball, String directory)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("tgz_in: handle is closed");

    _tgz_in (g, tarball, directory);
  }

  private native void _tgz_in (long g, String tarball, String directory)
    throws LibGuestFSException;

  /**
   * pack directory into compressed tarball
   * <p>
   * This command packs the contents of "directory" and
   * downloads it to local file "tarball".
   * <p>
   * To download an uncompressed tarball, use "g.tar_out".
   * <p>
   * @throws LibGuestFSException
   */
  public void tgz_out (String directory, String tarball)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("tgz_out: handle is closed");

    _tgz_out (g, directory, tarball);
  }

  private native void _tgz_out (long g, String directory, String tarball)
    throws LibGuestFSException;

  /**
   * mount a guest disk, read-only
   * <p>
   * This is the same as the "g.mount" command, but it mounts
   * the filesystem with the read-only (*-o ro*) flag.
   * <p>
   * @throws LibGuestFSException
   */
  public void mount_ro (String device, String mountpoint)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("mount_ro: handle is closed");

    _mount_ro (g, device, mountpoint);
  }

  private native void _mount_ro (long g, String device, String mountpoint)
    throws LibGuestFSException;

  /**
   * mount a guest disk with mount options
   * <p>
   * This is the same as the "g.mount" command, but it allows
   * you to set the mount options as for the mount(8) *-o*
   * flag.
   * <p>
   * If the "options" parameter is an empty string, then no
   * options are passed (all options default to whatever the
   * filesystem uses).
   * <p>
   * @throws LibGuestFSException
   */
  public void mount_options (String options, String device, String mountpoint)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("mount_options: handle is closed");

    _mount_options (g, options, device, mountpoint);
  }

  private native void _mount_options (long g, String options, String device, String mountpoint)
    throws LibGuestFSException;

  /**
   * mount a guest disk with mount options and vfstype
   * <p>
   * This is the same as the "g.mount" command, but it allows
   * you to set both the mount options and the vfstype as for
   * the mount(8) *-o* and *-t* flags.
   * <p>
   * @throws LibGuestFSException
   */
  public void mount_vfs (String options, String vfstype, String device, String mountpoint)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("mount_vfs: handle is closed");

    _mount_vfs (g, options, vfstype, device, mountpoint);
  }

  private native void _mount_vfs (long g, String options, String vfstype, String device, String mountpoint)
    throws LibGuestFSException;

  public String debug (String subcmd, String[] extraargs)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("debug: handle is closed");

    return _debug (g, subcmd, extraargs);
  }

  private native String _debug (long g, String subcmd, String[] extraargs)
    throws LibGuestFSException;

  /**
   * remove an LVM logical volume
   * <p>
   * Remove an LVM logical volume "device", where "device" is
   * the path to the LV, such as "/dev/VG/LV".
   * <p>
   * You can also remove all LVs in a volume group by
   * specifying the VG name, "/dev/VG".
   * <p>
   * @throws LibGuestFSException
   */
  public void lvremove (String device)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("lvremove: handle is closed");

    _lvremove (g, device);
  }

  private native void _lvremove (long g, String device)
    throws LibGuestFSException;

  /**
   * remove an LVM volume group
   * <p>
   * Remove an LVM volume group "vgname", (for example "VG").
   * <p>
   * This also forcibly removes all logical volumes in the
   * volume group (if any).
   * <p>
   * @throws LibGuestFSException
   */
  public void vgremove (String vgname)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("vgremove: handle is closed");

    _vgremove (g, vgname);
  }

  private native void _vgremove (long g, String vgname)
    throws LibGuestFSException;

  /**
   * remove an LVM physical volume
   * <p>
   * This wipes a physical volume "device" so that LVM will
   * no longer recognise it.
   * <p>
   * The implementation uses the "pvremove" command which
   * refuses to wipe physical volumes that contain any volume
   * groups, so you have to remove those first.
   * <p>
   * @throws LibGuestFSException
   */
  public void pvremove (String device)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("pvremove: handle is closed");

    _pvremove (g, device);
  }

  private native void _pvremove (long g, String device)
    throws LibGuestFSException;

  /**
   * set the ext2/3/4 filesystem label
   * <p>
   * This sets the ext2/3/4 filesystem label of the
   * filesystem on "device" to "label". Filesystem labels are
   * limited to 16 characters.
   * <p>
   * You can use either "g.tune2fs_l" or "g.get_e2label" to
   * return the existing label on a filesystem.
   * <p>
   * *This function is deprecated.* In new code, use the
   * "set_label" call instead.
   * <p>
   * Deprecated functions will not be removed from the API,
   * but the fact that they are deprecated indicates that
   * there are problems with correct use of these functions.
   * <p>
   * @throws LibGuestFSException
   */
  public void set_e2label (String device, String label)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("set_e2label: handle is closed");

    _set_e2label (g, device, label);
  }

  private native void _set_e2label (long g, String device, String label)
    throws LibGuestFSException;

  /**
   * get the ext2/3/4 filesystem label
   * <p>
   * This returns the ext2/3/4 filesystem label of the
   * filesystem on "device".
   * <p>
   * *This function is deprecated.* In new code, use the
   * "vfs_label" call instead.
   * <p>
   * Deprecated functions will not be removed from the API,
   * but the fact that they are deprecated indicates that
   * there are problems with correct use of these functions.
   * <p>
   * @throws LibGuestFSException
   */
  public String get_e2label (String device)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("get_e2label: handle is closed");

    return _get_e2label (g, device);
  }

  private native String _get_e2label (long g, String device)
    throws LibGuestFSException;

  /**
   * set the ext2/3/4 filesystem UUID
   * <p>
   * This sets the ext2/3/4 filesystem UUID of the filesystem
   * on "device" to "uuid". The format of the UUID and
   * alternatives such as "clear", "random" and "time" are
   * described in the tune2fs(8) manpage.
   * <p>
   * You can use either "g.tune2fs_l" or "g.get_e2uuid" to
   * return the existing UUID of a filesystem.
   * <p>
   * @throws LibGuestFSException
   */
  public void set_e2uuid (String device, String uuid)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("set_e2uuid: handle is closed");

    _set_e2uuid (g, device, uuid);
  }

  private native void _set_e2uuid (long g, String device, String uuid)
    throws LibGuestFSException;

  /**
   * get the ext2/3/4 filesystem UUID
   * <p>
   * This returns the ext2/3/4 filesystem UUID of the
   * filesystem on "device".
   * <p>
   * *This function is deprecated.* In new code, use the
   * "vfs_uuid" call instead.
   * <p>
   * Deprecated functions will not be removed from the API,
   * but the fact that they are deprecated indicates that
   * there are problems with correct use of these functions.
   * <p>
   * @throws LibGuestFSException
   */
  public String get_e2uuid (String device)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("get_e2uuid: handle is closed");

    return _get_e2uuid (g, device);
  }

  private native String _get_e2uuid (long g, String device)
    throws LibGuestFSException;

  /**
   * run the filesystem checker
   * <p>
   * This runs the filesystem checker (fsck) on "device"
   * which should have filesystem type "fstype".
   * <p>
   * The returned integer is the status. See fsck(8) for the
   * list of status codes from "fsck".
   * <p>
   * Notes:
   * <p>
   * *   Multiple status codes can be summed together.
   * <p>
   * *   A non-zero return code can mean "success", for
   * example if errors have been corrected on the
   * filesystem.
   * <p>
   * *   Checking or repairing NTFS volumes is not supported
   * (by linux-ntfs).
   * <p>
   * This command is entirely equivalent to running "fsck -a
   * -t fstype device".
   * <p>
   * @throws LibGuestFSException
   */
  public int fsck (String fstype, String device)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("fsck: handle is closed");

    return _fsck (g, fstype, device);
  }

  private native int _fsck (long g, String fstype, String device)
    throws LibGuestFSException;

  /**
   * write zeroes to the device
   * <p>
   * This command writes zeroes over the first few blocks of
   * "device".
   * <p>
   * How many blocks are zeroed isn't specified (but it's
   * *not* enough to securely wipe the device). It should be
   * sufficient to remove any partition tables, filesystem
   * superblocks and so on.
   * <p>
   * If blocks are already zero, then this command avoids
   * writing zeroes. This prevents the underlying device from
   * becoming non-sparse or growing unnecessarily.
   * <p>
   * See also: "g.zero_device", "g.scrub_device",
   * "g.is_zero_device"
   * <p>
   * @throws LibGuestFSException
   */
  public void zero (String device)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("zero: handle is closed");

    _zero (g, device);
  }

  private native void _zero (long g, String device)
    throws LibGuestFSException;

  /**
   * install GRUB 1
   * <p>
   * This command installs GRUB 1 (the Grand Unified
   * Bootloader) on "device", with the root directory being
   * "root".
   * <p>
   * Notes:
   * <p>
   * *   There is currently no way in the API to install
   * grub2, which is used by most modern Linux guests. It
   * is possible to run the grub2 command from the guest,
   * although see the caveats in "RUNNING COMMANDS" in
   * guestfs(3).
   * <p>
   * *   This uses "grub-install" from the host.
   * Unfortunately grub is not always compatible with
   * itself, so this only works in rather narrow
   * circumstances. Careful testing with each guest
   * version is advisable.
   * <p>
   * *   If grub-install reports the error "No suitable drive
   * was found in the generated device map." it may be
   * that you need to create a "/boot/grub/device.map"
   * file first that contains the mapping between grub
   * device names and Linux device names. It is usually
   * sufficient to create a file containing:
   * <p>
   * (hd0) /dev/vda
   * <p>
   * replacing "/dev/vda" with the name of the
   * installation device.
   * <p>
   * @throws LibGuestFSException
   */
  public void grub_install (String root, String device)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("grub_install: handle is closed");

    _grub_install (g, root, device);
  }

  private native void _grub_install (long g, String root, String device)
    throws LibGuestFSException;

  /**
   * copy a file
   * <p>
   * This copies a file from "src" to "dest" where "dest" is
   * either a destination filename or destination directory.
   * <p>
   * @throws LibGuestFSException
   */
  public void cp (String src, String dest)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("cp: handle is closed");

    _cp (g, src, dest);
  }

  private native void _cp (long g, String src, String dest)
    throws LibGuestFSException;

  /**
   * copy a file or directory recursively
   * <p>
   * This copies a file or directory from "src" to "dest"
   * recursively using the "cp -a" command.
   * <p>
   * @throws LibGuestFSException
   */
  public void cp_a (String src, String dest)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("cp_a: handle is closed");

    _cp_a (g, src, dest);
  }

  private native void _cp_a (long g, String src, String dest)
    throws LibGuestFSException;

  /**
   * move a file
   * <p>
   * This moves a file from "src" to "dest" where "dest" is
   * either a destination filename or destination directory.
   * <p>
   * @throws LibGuestFSException
   */
  public void mv (String src, String dest)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("mv: handle is closed");

    _mv (g, src, dest);
  }

  private native void _mv (long g, String src, String dest)
    throws LibGuestFSException;

  /**
   * drop kernel page cache, dentries and inodes
   * <p>
   * This instructs the guest kernel to drop its page cache,
   * and/or dentries and inode caches. The parameter
   * "whattodrop" tells the kernel what precisely to drop,
   * see <http://linux-mm.org/Drop_Caches>
   * <p>
   * Setting "whattodrop" to 3 should drop everything.
   * <p>
   * This automatically calls sync(2) before the operation,
   * so that the maximum guest memory is freed.
   * <p>
   * @throws LibGuestFSException
   */
  public void drop_caches (int whattodrop)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("drop_caches: handle is closed");

    _drop_caches (g, whattodrop);
  }

  private native void _drop_caches (long g, int whattodrop)
    throws LibGuestFSException;

  /**
   * return kernel messages
   * <p>
   * This returns the kernel messages ("dmesg" output) from
   * the guest kernel. This is sometimes useful for extended
   * debugging of problems.
   * <p>
   * Another way to get the same information is to enable
   * verbose messages with "g.set_verbose" or by setting the
   * environment variable "LIBGUESTFS_DEBUG=1" before running
   * the program.
   * <p>
   * @throws LibGuestFSException
   */
  public String dmesg ()
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("dmesg: handle is closed");

    return _dmesg (g);
  }

  private native String _dmesg (long g)
    throws LibGuestFSException;

  /**
   * ping the guest daemon
   * <p>
   * This is a test probe into the guestfs daemon running
   * inside the qemu subprocess. Calling this function checks
   * that the daemon responds to the ping message, without
   * affecting the daemon or attached block device(s) in any
   * other way.
   * <p>
   * @throws LibGuestFSException
   */
  public void ping_daemon ()
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("ping_daemon: handle is closed");

    _ping_daemon (g);
  }

  private native void _ping_daemon (long g)
    throws LibGuestFSException;

  /**
   * test if two files have equal contents
   * <p>
   * This compares the two files "file1" and "file2" and
   * returns true if their content is exactly equal, or false
   * otherwise.
   * <p>
   * The external cmp(1) program is used for the comparison.
   * <p>
   * @throws LibGuestFSException
   */
  public boolean equal (String file1, String file2)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("equal: handle is closed");

    return _equal (g, file1, file2);
  }

  private native boolean _equal (long g, String file1, String file2)
    throws LibGuestFSException;

  /**
   * print the printable strings in a file
   * <p>
   * This runs the strings(1) command on a file and returns
   * the list of printable strings found.
   * <p>
   * Because of the message protocol, there is a transfer
   * limit of somewhere between 2MB and 4MB. See "PROTOCOL
   * LIMITS" in guestfs(3).
   * <p>
   * @throws LibGuestFSException
   */
  public String[] strings (String path)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("strings: handle is closed");

    return _strings (g, path);
  }

  private native String[] _strings (long g, String path)
    throws LibGuestFSException;

  /**
   * print the printable strings in a file
   * <p>
   * This is like the "g.strings" command, but allows you to
   * specify the encoding of strings that are looked for in
   * the source file "path".
   * <p>
   * Allowed encodings are:
   * <p>
   * s   Single 7-bit-byte characters like ASCII and the
   * ASCII-compatible parts of ISO-8859-X (this is what
   * "g.strings" uses).
   * <p>
   * S   Single 8-bit-byte characters.
   * <p>
   * b   16-bit big endian strings such as those encoded in
   * UTF-16BE or UCS-2BE.
   * <p>
   * l (lower case letter L)
   * 16-bit little endian such as UTF-16LE and UCS-2LE.
   * This is useful for examining binaries in Windows
   * guests.
   * <p>
   * B   32-bit big endian such as UCS-4BE.
   * <p>
   * L   32-bit little endian such as UCS-4LE.
   * <p>
   * The returned strings are transcoded to UTF-8.
   * <p>
   * Because of the message protocol, there is a transfer
   * limit of somewhere between 2MB and 4MB. See "PROTOCOL
   * LIMITS" in guestfs(3).
   * <p>
   * @throws LibGuestFSException
   */
  public String[] strings_e (String encoding, String path)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("strings_e: handle is closed");

    return _strings_e (g, encoding, path);
  }

  private native String[] _strings_e (long g, String encoding, String path)
    throws LibGuestFSException;

  /**
   * dump a file in hexadecimal
   * <p>
   * This runs "hexdump -C" on the given "path". The result
   * is the human-readable, canonical hex dump of the file.
   * <p>
   * Because of the message protocol, there is a transfer
   * limit of somewhere between 2MB and 4MB. See "PROTOCOL
   * LIMITS" in guestfs(3).
   * <p>
   * @throws LibGuestFSException
   */
  public String hexdump (String path)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("hexdump: handle is closed");

    return _hexdump (g, path);
  }

  private native String _hexdump (long g, String path)
    throws LibGuestFSException;

  /**
   * zero unused inodes and disk blocks on ext2/3 filesystem
   * <p>
   * This runs the *zerofree* program on "device". This
   * program claims to zero unused inodes and disk blocks on
   * an ext2/3 filesystem, thus making it possible to
   * compress the filesystem more effectively.
   * <p>
   * You should not run this program if the filesystem is
   * mounted.
   * <p>
   * It is possible that using this program can damage the
   * filesystem or data on the filesystem.
   * <p>
   * @throws LibGuestFSException
   */
  public void zerofree (String device)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("zerofree: handle is closed");

    _zerofree (g, device);
  }

  private native void _zerofree (long g, String device)
    throws LibGuestFSException;

  /**
   * resize an LVM physical volume
   * <p>
   * This resizes (expands or shrinks) an existing LVM
   * physical volume to match the new size of the underlying
   * device.
   * <p>
   * @throws LibGuestFSException
   */
  public void pvresize (String device)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("pvresize: handle is closed");

    _pvresize (g, device);
  }

  private native void _pvresize (long g, String device)
    throws LibGuestFSException;

  /**
   * modify a single partition on a block device
   * <p>
   * This runs sfdisk(8) option to modify just the single
   * partition "n" (note: "n" counts from 1).
   * <p>
   * For other parameters, see "g.sfdisk". You should usually
   * pass 0 for the cyls/heads/sectors parameters.
   * <p>
   * See also: "g.part_add"
   * <p>
   * *This function is deprecated.* In new code, use the
   * "part_add" call instead.
   * <p>
   * Deprecated functions will not be removed from the API,
   * but the fact that they are deprecated indicates that
   * there are problems with correct use of these functions.
   * <p>
   * @throws LibGuestFSException
   */
  public void sfdisk_N (String device, int partnum, int cyls, int heads, int sectors, String line)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("sfdisk_N: handle is closed");

    _sfdisk_N (g, device, partnum, cyls, heads, sectors, line);
  }

  private native void _sfdisk_N (long g, String device, int partnum, int cyls, int heads, int sectors, String line)
    throws LibGuestFSException;

  /**
   * display the partition table
   * <p>
   * This displays the partition table on "device", in the
   * human-readable output of the sfdisk(8) command. It is
   * not intended to be parsed.
   * <p>
   * See also: "g.part_list"
   * <p>
   * *This function is deprecated.* In new code, use the
   * "part_list" call instead.
   * <p>
   * Deprecated functions will not be removed from the API,
   * but the fact that they are deprecated indicates that
   * there are problems with correct use of these functions.
   * <p>
   * @throws LibGuestFSException
   */
  public String sfdisk_l (String device)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("sfdisk_l: handle is closed");

    return _sfdisk_l (g, device);
  }

  private native String _sfdisk_l (long g, String device)
    throws LibGuestFSException;

  /**
   * display the kernel geometry
   * <p>
   * This displays the kernel's idea of the geometry of
   * "device".
   * <p>
   * The result is in human-readable format, and not designed
   * to be parsed.
   * <p>
   * @throws LibGuestFSException
   */
  public String sfdisk_kernel_geometry (String device)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("sfdisk_kernel_geometry: handle is closed");

    return _sfdisk_kernel_geometry (g, device);
  }

  private native String _sfdisk_kernel_geometry (long g, String device)
    throws LibGuestFSException;

  /**
   * display the disk geometry from the partition table
   * <p>
   * This displays the disk geometry of "device" read from
   * the partition table. Especially in the case where the
   * underlying block device has been resized, this can be
   * different from the kernel's idea of the geometry (see
   * "g.sfdisk_kernel_geometry").
   * <p>
   * The result is in human-readable format, and not designed
   * to be parsed.
   * <p>
   * @throws LibGuestFSException
   */
  public String sfdisk_disk_geometry (String device)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("sfdisk_disk_geometry: handle is closed");

    return _sfdisk_disk_geometry (g, device);
  }

  private native String _sfdisk_disk_geometry (long g, String device)
    throws LibGuestFSException;

  /**
   * activate or deactivate all volume groups
   * <p>
   * This command activates or (if "activate" is false)
   * deactivates all logical volumes in all volume groups.
   * <p>
   * This command is the same as running "vgchange -a y|n"
   * <p>
   * @throws LibGuestFSException
   */
  public void vg_activate_all (boolean activate)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("vg_activate_all: handle is closed");

    _vg_activate_all (g, activate);
  }

  private native void _vg_activate_all (long g, boolean activate)
    throws LibGuestFSException;

  /**
   * activate or deactivate some volume groups
   * <p>
   * This command activates or (if "activate" is false)
   * deactivates all logical volumes in the listed volume
   * groups "volgroups".
   * <p>
   * This command is the same as running "vgchange -a y|n
   * volgroups..."
   * <p>
   * Note that if "volgroups" is an empty list then all
   * volume groups are activated or deactivated.
   * <p>
   * @throws LibGuestFSException
   */
  public void vg_activate (boolean activate, String[] volgroups)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("vg_activate: handle is closed");

    _vg_activate (g, activate, volgroups);
  }

  private native void _vg_activate (long g, boolean activate, String[] volgroups)
    throws LibGuestFSException;

  /**
   * resize an LVM logical volume
   * <p>
   * This resizes (expands or shrinks) an existing LVM
   * logical volume to "mbytes". When reducing, data in the
   * reduced part is lost.
   * <p>
   * @throws LibGuestFSException
   */
  public void lvresize (String device, int mbytes)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("lvresize: handle is closed");

    _lvresize (g, device, mbytes);
  }

  private native void _lvresize (long g, String device, int mbytes)
    throws LibGuestFSException;

  /**
   * resize an ext2, ext3 or ext4 filesystem
   * <p>
   * This resizes an ext2, ext3 or ext4 filesystem to match
   * the size of the underlying device.
   * <p>
   * See also "RESIZE2FS ERRORS" in guestfs(3).
   * <p>
   * @throws LibGuestFSException
   */
  public void resize2fs (String device)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("resize2fs: handle is closed");

    _resize2fs (g, device);
  }

  private native void _resize2fs (long g, String device)
    throws LibGuestFSException;

  /**
   * find all files and directories
   * <p>
   * This command lists out all files and directories,
   * recursively, starting at "directory". It is essentially
   * equivalent to running the shell command "find directory
   * -print" but some post-processing happens on the output,
   * described below.
   * <p>
   * This returns a list of strings *without any prefix*.
   * Thus if the directory structure was:
   * <p>
   * /tmp/a
   * /tmp/b
   * /tmp/c/d
   * <p>
   * then the returned list from "g.find" "/tmp" would be 4
   * elements:
   * <p>
   * a
   * b
   * c
   * c/d
   * <p>
   * If "directory" is not a directory, then this command
   * returns an error.
   * <p>
   * The returned list is sorted.
   * <p>
   * See also "g.find0".
   * <p>
   * Because of the message protocol, there is a transfer
   * limit of somewhere between 2MB and 4MB. See "PROTOCOL
   * LIMITS" in guestfs(3).
   * <p>
   * @throws LibGuestFSException
   */
  public String[] find (String directory)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("find: handle is closed");

    return _find (g, directory);
  }

  private native String[] _find (long g, String directory)
    throws LibGuestFSException;

  /**
   * check an ext2/ext3 filesystem
   * <p>
   * This runs "e2fsck -p -f device", ie. runs the ext2/ext3
   * filesystem checker on "device", noninteractively (*-p*),
   * even if the filesystem appears to be clean (*-f*).
   * <p>
   * *This function is deprecated.* In new code, use the
   * "e2fsck" call instead.
   * <p>
   * Deprecated functions will not be removed from the API,
   * but the fact that they are deprecated indicates that
   * there are problems with correct use of these functions.
   * <p>
   * @throws LibGuestFSException
   */
  public void e2fsck_f (String device)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("e2fsck_f: handle is closed");

    _e2fsck_f (g, device);
  }

  private native void _e2fsck_f (long g, String device)
    throws LibGuestFSException;

  /**
   * sleep for some seconds
   * <p>
   * Sleep for "secs" seconds.
   * <p>
   * @throws LibGuestFSException
   */
  public void sleep (int secs)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("sleep: handle is closed");

    _sleep (g, secs);
  }

  private native void _sleep (long g, int secs)
    throws LibGuestFSException;

  /**
   * probe NTFS volume
   * <p>
   * This command runs the ntfs-3g.probe(8) command which
   * probes an NTFS "device" for mountability. (Not all NTFS
   * volumes can be mounted read-write, and some cannot be
   * mounted at all).
   * <p>
   * "rw" is a boolean flag. Set it to true if you want to
   * test if the volume can be mounted read-write. Set it to
   * false if you want to test if the volume can be mounted
   * read-only.
   * <p>
   * The return value is an integer which 0 if the operation
   * would succeed, or some non-zero value documented in the
   * ntfs-3g.probe(8) manual page.
   * <p>
   * @throws LibGuestFSException
   */
  public int ntfs_3g_probe (boolean rw, String device)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("ntfs_3g_probe: handle is closed");

    return _ntfs_3g_probe (g, rw, device);
  }

  private native int _ntfs_3g_probe (long g, boolean rw, String device)
    throws LibGuestFSException;

  /**
   * run a command via the shell
   * <p>
   * This call runs a command from the guest filesystem via
   * the guest's "/bin/sh".
   * <p>
   * This is like "g.command", but passes the command to:
   * <p>
   * /bin/sh -c "command"
   * <p>
   * Depending on the guest's shell, this usually results in
   * wildcards being expanded, shell expressions being
   * interpolated and so on.
   * <p>
   * All the provisos about "g.command" apply to this call.
   * <p>
   * @throws LibGuestFSException
   */
  public String sh (String command)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("sh: handle is closed");

    return _sh (g, command);
  }

  private native String _sh (long g, String command)
    throws LibGuestFSException;

  /**
   * run a command via the shell returning lines
   * <p>
   * This is the same as "g.sh", but splits the result into a
   * list of lines.
   * <p>
   * See also: "g.command_lines"
   * <p>
   * @throws LibGuestFSException
   */
  public String[] sh_lines (String command)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("sh_lines: handle is closed");

    return _sh_lines (g, command);
  }

  private native String[] _sh_lines (long g, String command)
    throws LibGuestFSException;

  /**
   * expand a wildcard path
   * <p>
   * This command searches for all the pathnames matching
   * "pattern" according to the wildcard expansion rules used
   * by the shell.
   * <p>
   * If no paths match, then this returns an empty list
   * (note: not an error).
   * <p>
   * It is just a wrapper around the C glob(3) function with
   * flags "GLOB_MARK|GLOB_BRACE". See that manual page for
   * more details.
   * <p>
   * Notice that there is no equivalent command for expanding
   * a device name (eg. "/dev/sd*"). Use "g.list_devices",
   * "g.list_partitions" etc functions instead.
   * <p>
   * @throws LibGuestFSException
   */
  public String[] glob_expand (String pattern)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("glob_expand: handle is closed");

    return _glob_expand (g, pattern);
  }

  private native String[] _glob_expand (long g, String pattern)
    throws LibGuestFSException;

  /**
   * scrub (securely wipe) a device
   * <p>
   * This command writes patterns over "device" to make data
   * retrieval more difficult.
   * <p>
   * It is an interface to the scrub(1) program. See that
   * manual page for more details.
   * <p>
   * @throws LibGuestFSException
   */
  public void scrub_device (String device)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("scrub_device: handle is closed");

    _scrub_device (g, device);
  }

  private native void _scrub_device (long g, String device)
    throws LibGuestFSException;

  /**
   * scrub (securely wipe) a file
   * <p>
   * This command writes patterns over a file to make data
   * retrieval more difficult.
   * <p>
   * The file is *removed* after scrubbing.
   * <p>
   * It is an interface to the scrub(1) program. See that
   * manual page for more details.
   * <p>
   * @throws LibGuestFSException
   */
  public void scrub_file (String file)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("scrub_file: handle is closed");

    _scrub_file (g, file);
  }

  private native void _scrub_file (long g, String file)
    throws LibGuestFSException;

  /**
   * scrub (securely wipe) free space
   * <p>
   * This command creates the directory "dir" and then fills
   * it with files until the filesystem is full, and scrubs
   * the files as for "g.scrub_file", and deletes them. The
   * intention is to scrub any free space on the partition
   * containing "dir".
   * <p>
   * It is an interface to the scrub(1) program. See that
   * manual page for more details.
   * <p>
   * @throws LibGuestFSException
   */
  public void scrub_freespace (String dir)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("scrub_freespace: handle is closed");

    _scrub_freespace (g, dir);
  }

  private native void _scrub_freespace (long g, String dir)
    throws LibGuestFSException;

  /**
   * create a temporary directory
   * <p>
   * This command creates a temporary directory. The "tmpl"
   * parameter should be a full pathname for the temporary
   * directory name with the final six characters being
   * "XXXXXX".
   * <p>
   * For example: "/tmp/myprogXXXXXX" or
   * "/Temp/myprogXXXXXX", the second one being suitable for
   * Windows filesystems.
   * <p>
   * The name of the temporary directory that was created is
   * returned.
   * <p>
   * The temporary directory is created with mode 0700 and is
   * owned by root.
   * <p>
   * The caller is responsible for deleting the temporary
   * directory and its contents after use.
   * <p>
   * See also: mkdtemp(3)
   * <p>
   * @throws LibGuestFSException
   */
  public String mkdtemp (String tmpl)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("mkdtemp: handle is closed");

    return _mkdtemp (g, tmpl);
  }

  private native String _mkdtemp (long g, String tmpl)
    throws LibGuestFSException;

  /**
   * count lines in a file
   * <p>
   * This command counts the lines in a file, using the "wc
   * -l" external command.
   * <p>
   * @throws LibGuestFSException
   */
  public int wc_l (String path)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("wc_l: handle is closed");

    return _wc_l (g, path);
  }

  private native int _wc_l (long g, String path)
    throws LibGuestFSException;

  /**
   * count words in a file
   * <p>
   * This command counts the words in a file, using the "wc
   * -w" external command.
   * <p>
   * @throws LibGuestFSException
   */
  public int wc_w (String path)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("wc_w: handle is closed");

    return _wc_w (g, path);
  }

  private native int _wc_w (long g, String path)
    throws LibGuestFSException;

  /**
   * count characters in a file
   * <p>
   * This command counts the characters in a file, using the
   * "wc -c" external command.
   * <p>
   * @throws LibGuestFSException
   */
  public int wc_c (String path)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("wc_c: handle is closed");

    return _wc_c (g, path);
  }

  private native int _wc_c (long g, String path)
    throws LibGuestFSException;

  /**
   * return first 10 lines of a file
   * <p>
   * This command returns up to the first 10 lines of a file
   * as a list of strings.
   * <p>
   * Because of the message protocol, there is a transfer
   * limit of somewhere between 2MB and 4MB. See "PROTOCOL
   * LIMITS" in guestfs(3).
   * <p>
   * @throws LibGuestFSException
   */
  public String[] head (String path)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("head: handle is closed");

    return _head (g, path);
  }

  private native String[] _head (long g, String path)
    throws LibGuestFSException;

  /**
   * return first N lines of a file
   * <p>
   * If the parameter "nrlines" is a positive number, this
   * returns the first "nrlines" lines of the file "path".
   * <p>
   * If the parameter "nrlines" is a negative number, this
   * returns lines from the file "path", excluding the last
   * "nrlines" lines.
   * <p>
   * If the parameter "nrlines" is zero, this returns an
   * empty list.
   * <p>
   * Because of the message protocol, there is a transfer
   * limit of somewhere between 2MB and 4MB. See "PROTOCOL
   * LIMITS" in guestfs(3).
   * <p>
   * @throws LibGuestFSException
   */
  public String[] head_n (int nrlines, String path)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("head_n: handle is closed");

    return _head_n (g, nrlines, path);
  }

  private native String[] _head_n (long g, int nrlines, String path)
    throws LibGuestFSException;

  /**
   * return last 10 lines of a file
   * <p>
   * This command returns up to the last 10 lines of a file
   * as a list of strings.
   * <p>
   * Because of the message protocol, there is a transfer
   * limit of somewhere between 2MB and 4MB. See "PROTOCOL
   * LIMITS" in guestfs(3).
   * <p>
   * @throws LibGuestFSException
   */
  public String[] tail (String path)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("tail: handle is closed");

    return _tail (g, path);
  }

  private native String[] _tail (long g, String path)
    throws LibGuestFSException;

  /**
   * return last N lines of a file
   * <p>
   * If the parameter "nrlines" is a positive number, this
   * returns the last "nrlines" lines of the file "path".
   * <p>
   * If the parameter "nrlines" is a negative number, this
   * returns lines from the file "path", starting with the
   * "-nrlines"th line.
   * <p>
   * If the parameter "nrlines" is zero, this returns an
   * empty list.
   * <p>
   * Because of the message protocol, there is a transfer
   * limit of somewhere between 2MB and 4MB. See "PROTOCOL
   * LIMITS" in guestfs(3).
   * <p>
   * @throws LibGuestFSException
   */
  public String[] tail_n (int nrlines, String path)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("tail_n: handle is closed");

    return _tail_n (g, nrlines, path);
  }

  private native String[] _tail_n (long g, int nrlines, String path)
    throws LibGuestFSException;

  /**
   * report file system disk space usage
   * <p>
   * This command runs the "df" command to report disk space
   * used.
   * <p>
   * This command is mostly useful for interactive sessions.
   * It is *not* intended that you try to parse the output
   * string. Use "g.statvfs" from programs.
   * <p>
   * @throws LibGuestFSException
   */
  public String df ()
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("df: handle is closed");

    return _df (g);
  }

  private native String _df (long g)
    throws LibGuestFSException;

  /**
   * report file system disk space usage (human readable)
   * <p>
   * This command runs the "df -h" command to report disk
   * space used in human-readable format.
   * <p>
   * This command is mostly useful for interactive sessions.
   * It is *not* intended that you try to parse the output
   * string. Use "g.statvfs" from programs.
   * <p>
   * @throws LibGuestFSException
   */
  public String df_h ()
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("df_h: handle is closed");

    return _df_h (g);
  }

  private native String _df_h (long g)
    throws LibGuestFSException;

  /**
   * estimate file space usage
   * <p>
   * This command runs the "du -s" command to estimate file
   * space usage for "path".
   * <p>
   * "path" can be a file or a directory. If "path" is a
   * directory then the estimate includes the contents of the
   * directory and all subdirectories (recursively).
   * <p>
   * The result is the estimated size in *kilobytes* (ie.
   * units of 1024 bytes).
   * <p>
   * @throws LibGuestFSException
   */
  public long du (String path)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("du: handle is closed");

    return _du (g, path);
  }

  private native long _du (long g, String path)
    throws LibGuestFSException;

  /**
   * list files in an initrd
   * <p>
   * This command lists out files contained in an initrd.
   * <p>
   * The files are listed without any initial "/" character.
   * The files are listed in the order they appear (not
   * necessarily alphabetical). Directory names are listed as
   * separate items.
   * <p>
   * Old Linux kernels (2.4 and earlier) used a compressed
   * ext2 filesystem as initrd. We *only* support the newer
   * initramfs format (compressed cpio files).
   * <p>
   * @throws LibGuestFSException
   */
  public String[] initrd_list (String path)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("initrd_list: handle is closed");

    return _initrd_list (g, path);
  }

  private native String[] _initrd_list (long g, String path)
    throws LibGuestFSException;

  /**
   * mount a file using the loop device
   * <p>
   * This command lets you mount "file" (a filesystem image
   * in a file) on a mount point. It is entirely equivalent
   * to the command "mount -o loop file mountpoint".
   * <p>
   * @throws LibGuestFSException
   */
  public void mount_loop (String file, String mountpoint)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("mount_loop: handle is closed");

    _mount_loop (g, file, mountpoint);
  }

  private native void _mount_loop (long g, String file, String mountpoint)
    throws LibGuestFSException;

  /**
   * create a swap partition
   * <p>
   * Create a swap partition on "device".
   * <p>
   * @throws LibGuestFSException
   */
  public void mkswap (String device)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("mkswap: handle is closed");

    _mkswap (g, device);
  }

  private native void _mkswap (long g, String device)
    throws LibGuestFSException;

  /**
   * create a swap partition with a label
   * <p>
   * Create a swap partition on "device" with label "label".
   * <p>
   * Note that you cannot attach a swap label to a block
   * device (eg. "/dev/sda"), just to a partition. This
   * appears to be a limitation of the kernel or swap tools.
   * <p>
   * @throws LibGuestFSException
   */
  public void mkswap_L (String label, String device)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("mkswap_L: handle is closed");

    _mkswap_L (g, label, device);
  }

  private native void _mkswap_L (long g, String label, String device)
    throws LibGuestFSException;

  /**
   * create a swap partition with an explicit UUID
   * <p>
   * Create a swap partition on "device" with UUID "uuid".
   * <p>
   * @throws LibGuestFSException
   */
  public void mkswap_U (String uuid, String device)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("mkswap_U: handle is closed");

    _mkswap_U (g, uuid, device);
  }

  private native void _mkswap_U (long g, String uuid, String device)
    throws LibGuestFSException;

  /**
   * make block, character or FIFO devices
   * <p>
   * This call creates block or character special devices, or
   * named pipes (FIFOs).
   * <p>
   * The "mode" parameter should be the mode, using the
   * standard constants. "devmajor" and "devminor" are the
   * device major and minor numbers, only used when creating
   * block and character special devices.
   * <p>
   * Note that, just like mknod(2), the mode must be bitwise
   * OR'd with S_IFBLK, S_IFCHR, S_IFIFO or S_IFSOCK
   * (otherwise this call just creates a regular file). These
   * constants are available in the standard Linux header
   * files, or you can use "g.mknod_b", "g.mknod_c" or
   * "g.mkfifo" which are wrappers around this command which
   * bitwise OR in the appropriate constant for you.
   * <p>
   * The mode actually set is affected by the umask.
   * <p>
   * @throws LibGuestFSException
   */
  public void mknod (int mode, int devmajor, int devminor, String path)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("mknod: handle is closed");

    _mknod (g, mode, devmajor, devminor, path);
  }

  private native void _mknod (long g, int mode, int devmajor, int devminor, String path)
    throws LibGuestFSException;

  /**
   * make FIFO (named pipe)
   * <p>
   * This call creates a FIFO (named pipe) called "path" with
   * mode "mode". It is just a convenient wrapper around
   * "g.mknod".
   * <p>
   * The mode actually set is affected by the umask.
   * <p>
   * @throws LibGuestFSException
   */
  public void mkfifo (int mode, String path)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("mkfifo: handle is closed");

    _mkfifo (g, mode, path);
  }

  private native void _mkfifo (long g, int mode, String path)
    throws LibGuestFSException;

  /**
   * make block device node
   * <p>
   * This call creates a block device node called "path" with
   * mode "mode" and device major/minor "devmajor" and
   * "devminor". It is just a convenient wrapper around
   * "g.mknod".
   * <p>
   * The mode actually set is affected by the umask.
   * <p>
   * @throws LibGuestFSException
   */
  public void mknod_b (int mode, int devmajor, int devminor, String path)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("mknod_b: handle is closed");

    _mknod_b (g, mode, devmajor, devminor, path);
  }

  private native void _mknod_b (long g, int mode, int devmajor, int devminor, String path)
    throws LibGuestFSException;

  /**
   * make char device node
   * <p>
   * This call creates a char device node called "path" with
   * mode "mode" and device major/minor "devmajor" and
   * "devminor". It is just a convenient wrapper around
   * "g.mknod".
   * <p>
   * The mode actually set is affected by the umask.
   * <p>
   * @throws LibGuestFSException
   */
  public void mknod_c (int mode, int devmajor, int devminor, String path)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("mknod_c: handle is closed");

    _mknod_c (g, mode, devmajor, devminor, path);
  }

  private native void _mknod_c (long g, int mode, int devmajor, int devminor, String path)
    throws LibGuestFSException;

  /**
   * set file mode creation mask (umask)
   * <p>
   * This function sets the mask used for creating new files
   * and device nodes to "mask & 0777".
   * <p>
   * Typical umask values would be 022 which creates new
   * files with permissions like "-rw-r--r--" or
   * "-rwxr-xr-x", and 002 which creates new files with
   * permissions like "-rw-rw-r--" or "-rwxrwxr-x".
   * <p>
   * The default umask is 022. This is important because it
   * means that directories and device nodes will be created
   * with 0644 or 0755 mode even if you specify 0777.
   * <p>
   * See also "g.get_umask", umask(2), "g.mknod", "g.mkdir".
   * <p>
   * This call returns the previous umask.
   * <p>
   * @throws LibGuestFSException
   */
  public int umask (int mask)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("umask: handle is closed");

    return _umask (g, mask);
  }

  private native int _umask (long g, int mask)
    throws LibGuestFSException;

  /**
   * read directories entries
   * <p>
   * This returns the list of directory entries in directory
   * "dir".
   * <p>
   * All entries in the directory are returned, including "."
   * and "..". The entries are *not* sorted, but returned in
   * the same order as the underlying filesystem.
   * <p>
   * Also this call returns basic file type information about
   * each file. The "ftyp" field will contain one of the
   * following characters:
   * <p>
   * 'b' Block special
   * <p>
   * 'c' Char special
   * <p>
   * 'd' Directory
   * <p>
   * 'f' FIFO (named pipe)
   * <p>
   * 'l' Symbolic link
   * <p>
   * 'r' Regular file
   * <p>
   * 's' Socket
   * <p>
   * 'u' Unknown file type
   * <p>
   * '?' The readdir(3) call returned a "d_type" field with
   * an unexpected value
   * <p>
   * This function is primarily intended for use by programs.
   * To get a simple list of names, use "g.ls". To get a
   * printable directory for human consumption, use "g.ll".
   * <p>
   * @throws LibGuestFSException
   */
  public Dirent[] readdir (String dir)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("readdir: handle is closed");

    return _readdir (g, dir);
  }

  private native Dirent[] _readdir (long g, String dir)
    throws LibGuestFSException;

  /**
   * create partitions on a block device
   * <p>
   * This is a simplified interface to the "g.sfdisk"
   * command, where partition sizes are specified in
   * megabytes only (rounded to the nearest cylinder) and you
   * don't need to specify the cyls, heads and sectors
   * parameters which were rarely if ever used anyway.
   * <p>
   * See also: "g.sfdisk", the sfdisk(8) manpage and
   * "g.part_disk"
   * <p>
   * *This function is deprecated.* In new code, use the
   * "part_add" call instead.
   * <p>
   * Deprecated functions will not be removed from the API,
   * but the fact that they are deprecated indicates that
   * there are problems with correct use of these functions.
   * <p>
   * @throws LibGuestFSException
   */
  public void sfdiskM (String device, String[] lines)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("sfdiskM: handle is closed");

    _sfdiskM (g, device, lines);
  }

  private native void _sfdiskM (long g, String device, String[] lines)
    throws LibGuestFSException;

  /**
   * determine file type inside a compressed file
   * <p>
   * This command runs "file" after first decompressing
   * "path" using "method".
   * <p>
   * "method" must be one of "gzip", "compress" or "bzip2".
   * <p>
   * Since 1.0.63, use "g.file" instead which can now process
   * compressed files.
   * <p>
   * *This function is deprecated.* In new code, use the
   * "file" call instead.
   * <p>
   * Deprecated functions will not be removed from the API,
   * but the fact that they are deprecated indicates that
   * there are problems with correct use of these functions.
   * <p>
   * @throws LibGuestFSException
   */
  public String zfile (String meth, String path)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("zfile: handle is closed");

    return _zfile (g, meth, path);
  }

  private native String _zfile (long g, String meth, String path)
    throws LibGuestFSException;

  /**
   * list extended attributes of a file or directory
   * <p>
   * This call lists the extended attributes of the file or
   * directory "path".
   * <p>
   * At the system call level, this is a combination of the
   * listxattr(2) and getxattr(2) calls.
   * <p>
   * See also: "g.lgetxattrs", attr(5).
   * <p>
   * @throws LibGuestFSException
   */
  public XAttr[] getxattrs (String path)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("getxattrs: handle is closed");

    return _getxattrs (g, path);
  }

  private native XAttr[] _getxattrs (long g, String path)
    throws LibGuestFSException;

  /**
   * list extended attributes of a file or directory
   * <p>
   * This is the same as "g.getxattrs", but if "path" is a
   * symbolic link, then it returns the extended attributes
   * of the link itself.
   * <p>
   * @throws LibGuestFSException
   */
  public XAttr[] lgetxattrs (String path)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("lgetxattrs: handle is closed");

    return _lgetxattrs (g, path);
  }

  private native XAttr[] _lgetxattrs (long g, String path)
    throws LibGuestFSException;

  /**
   * set extended attribute of a file or directory
   * <p>
   * This call sets the extended attribute named "xattr" of
   * the file "path" to the value "val" (of length "vallen").
   * The value is arbitrary 8 bit data.
   * <p>
   * See also: "g.lsetxattr", attr(5).
   * <p>
   * @throws LibGuestFSException
   */
  public void setxattr (String xattr, String val, int vallen, String path)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("setxattr: handle is closed");

    _setxattr (g, xattr, val, vallen, path);
  }

  private native void _setxattr (long g, String xattr, String val, int vallen, String path)
    throws LibGuestFSException;

  /**
   * set extended attribute of a file or directory
   * <p>
   * This is the same as "g.setxattr", but if "path" is a
   * symbolic link, then it sets an extended attribute of the
   * link itself.
   * <p>
   * @throws LibGuestFSException
   */
  public void lsetxattr (String xattr, String val, int vallen, String path)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("lsetxattr: handle is closed");

    _lsetxattr (g, xattr, val, vallen, path);
  }

  private native void _lsetxattr (long g, String xattr, String val, int vallen, String path)
    throws LibGuestFSException;

  /**
   * remove extended attribute of a file or directory
   * <p>
   * This call removes the extended attribute named "xattr"
   * of the file "path".
   * <p>
   * See also: "g.lremovexattr", attr(5).
   * <p>
   * @throws LibGuestFSException
   */
  public void removexattr (String xattr, String path)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("removexattr: handle is closed");

    _removexattr (g, xattr, path);
  }

  private native void _removexattr (long g, String xattr, String path)
    throws LibGuestFSException;

  /**
   * remove extended attribute of a file or directory
   * <p>
   * This is the same as "g.removexattr", but if "path" is a
   * symbolic link, then it removes an extended attribute of
   * the link itself.
   * <p>
   * @throws LibGuestFSException
   */
  public void lremovexattr (String xattr, String path)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("lremovexattr: handle is closed");

    _lremovexattr (g, xattr, path);
  }

  private native void _lremovexattr (long g, String xattr, String path)
    throws LibGuestFSException;

  /**
   * show mountpoints
   * <p>
   * This call is similar to "g.mounts". That call returns a
   * list of devices. This one returns a hash table (map) of
   * device name to directory where the device is mounted.
   * <p>
   * @throws LibGuestFSException
   */
  public Map<String,String> mountpoints ()
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("mountpoints: handle is closed");

    String[] r = _mountpoints (g);

    HashMap<String, String> rhash = new HashMap<String, String> ();
    for (int i = 0; i < r.length; i += 2)
      rhash.put (r[i], r[i+1]);
    return rhash;
  }

  private native String[] _mountpoints (long g)
    throws LibGuestFSException;

  /**
   * create a mountpoint
   * <p>
   * "g.mkmountpoint" and "g.rmmountpoint" are specialized
   * calls that can be used to create extra mountpoints
   * before mounting the first filesystem.
   * <p>
   * These calls are *only* necessary in some very limited
   * circumstances, mainly the case where you want to mount a
   * mix of unrelated and/or read-only filesystems together.
   * <p>
   * For example, live CDs often contain a "Russian doll"
   * nest of filesystems, an ISO outer layer, with a squashfs
   * image inside, with an ext2/3 image inside that. You can
   * unpack this as follows in guestfish:
   * <p>
   * add-ro Fedora-11-i686-Live.iso
   * run
   * mkmountpoint /cd
   * mkmountpoint /sqsh
   * mkmountpoint /ext3fs
   * mount /dev/sda /cd
   * mount-loop /cd/LiveOS/squashfs.img /sqsh
   * mount-loop /sqsh/LiveOS/ext3fs.img /ext3fs
   * <p>
   * The inner filesystem is now unpacked under the /ext3fs
   * mountpoint.
   * <p>
   * "g.mkmountpoint" is not compatible with "g.umount_all".
   * You may get unexpected errors if you try to mix these
   * calls. It is safest to manually unmount filesystems and
   * remove mountpoints after use.
   * <p>
   * "g.umount_all" unmounts filesystems by sorting the paths
   * longest first, so for this to work for manual
   * mountpoints, you must ensure that the innermost
   * mountpoints have the longest pathnames, as in the
   * example code above.
   * <p>
   * For more details see
   * <https://bugzilla.redhat.com/show_bug.cgi?id=599503>
   * <p>
   * Autosync [see "g.set_autosync", this is set by default
   * on handles] can cause "g.umount_all" to be called when
   * the handle is closed which can also trigger these
   * issues.
   * <p>
   * @throws LibGuestFSException
   */
  public void mkmountpoint (String exemptpath)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("mkmountpoint: handle is closed");

    _mkmountpoint (g, exemptpath);
  }

  private native void _mkmountpoint (long g, String exemptpath)
    throws LibGuestFSException;

  /**
   * remove a mountpoint
   * <p>
   * This calls removes a mountpoint that was previously
   * created with "g.mkmountpoint". See "g.mkmountpoint" for
   * full details.
   * <p>
   * @throws LibGuestFSException
   */
  public void rmmountpoint (String exemptpath)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("rmmountpoint: handle is closed");

    _rmmountpoint (g, exemptpath);
  }

  private native void _rmmountpoint (long g, String exemptpath)
    throws LibGuestFSException;

  /**
   * read a file
   * <p>
   * This calls returns the contents of the file "path" as a
   * buffer.
   * <p>
   * Unlike "g.cat", this function can correctly handle files
   * that contain embedded ASCII NUL characters. However
   * unlike "g.download", this function is limited in the
   * total size of file that can be handled.
   * <p>
   * Because of the message protocol, there is a transfer
   * limit of somewhere between 2MB and 4MB. See "PROTOCOL
   * LIMITS" in guestfs(3).
   * <p>
   * @throws LibGuestFSException
   */
  public String read_file (String path)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("read_file: handle is closed");

    return _read_file (g, path);
  }

  private native String _read_file (long g, String path)
    throws LibGuestFSException;

  /**
   * return lines matching a pattern
   * <p>
   * This calls the external "grep" program and returns the
   * matching lines.
   * <p>
   * Because of the message protocol, there is a transfer
   * limit of somewhere between 2MB and 4MB. See "PROTOCOL
   * LIMITS" in guestfs(3).
   * <p>
   * @throws LibGuestFSException
   */
  public String[] grep (String regex, String path)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("grep: handle is closed");

    return _grep (g, regex, path);
  }

  private native String[] _grep (long g, String regex, String path)
    throws LibGuestFSException;

  /**
   * return lines matching a pattern
   * <p>
   * This calls the external "egrep" program and returns the
   * matching lines.
   * <p>
   * Because of the message protocol, there is a transfer
   * limit of somewhere between 2MB and 4MB. See "PROTOCOL
   * LIMITS" in guestfs(3).
   * <p>
   * @throws LibGuestFSException
   */
  public String[] egrep (String regex, String path)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("egrep: handle is closed");

    return _egrep (g, regex, path);
  }

  private native String[] _egrep (long g, String regex, String path)
    throws LibGuestFSException;

  /**
   * return lines matching a pattern
   * <p>
   * This calls the external "fgrep" program and returns the
   * matching lines.
   * <p>
   * Because of the message protocol, there is a transfer
   * limit of somewhere between 2MB and 4MB. See "PROTOCOL
   * LIMITS" in guestfs(3).
   * <p>
   * @throws LibGuestFSException
   */
  public String[] fgrep (String pattern, String path)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("fgrep: handle is closed");

    return _fgrep (g, pattern, path);
  }

  private native String[] _fgrep (long g, String pattern, String path)
    throws LibGuestFSException;

  /**
   * return lines matching a pattern
   * <p>
   * This calls the external "grep -i" program and returns
   * the matching lines.
   * <p>
   * Because of the message protocol, there is a transfer
   * limit of somewhere between 2MB and 4MB. See "PROTOCOL
   * LIMITS" in guestfs(3).
   * <p>
   * @throws LibGuestFSException
   */
  public String[] grepi (String regex, String path)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("grepi: handle is closed");

    return _grepi (g, regex, path);
  }

  private native String[] _grepi (long g, String regex, String path)
    throws LibGuestFSException;

  /**
   * return lines matching a pattern
   * <p>
   * This calls the external "egrep -i" program and returns
   * the matching lines.
   * <p>
   * Because of the message protocol, there is a transfer
   * limit of somewhere between 2MB and 4MB. See "PROTOCOL
   * LIMITS" in guestfs(3).
   * <p>
   * @throws LibGuestFSException
   */
  public String[] egrepi (String regex, String path)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("egrepi: handle is closed");

    return _egrepi (g, regex, path);
  }

  private native String[] _egrepi (long g, String regex, String path)
    throws LibGuestFSException;

  /**
   * return lines matching a pattern
   * <p>
   * This calls the external "fgrep -i" program and returns
   * the matching lines.
   * <p>
   * Because of the message protocol, there is a transfer
   * limit of somewhere between 2MB and 4MB. See "PROTOCOL
   * LIMITS" in guestfs(3).
   * <p>
   * @throws LibGuestFSException
   */
  public String[] fgrepi (String pattern, String path)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("fgrepi: handle is closed");

    return _fgrepi (g, pattern, path);
  }

  private native String[] _fgrepi (long g, String pattern, String path)
    throws LibGuestFSException;

  /**
   * return lines matching a pattern
   * <p>
   * This calls the external "zgrep" program and returns the
   * matching lines.
   * <p>
   * Because of the message protocol, there is a transfer
   * limit of somewhere between 2MB and 4MB. See "PROTOCOL
   * LIMITS" in guestfs(3).
   * <p>
   * @throws LibGuestFSException
   */
  public String[] zgrep (String regex, String path)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("zgrep: handle is closed");

    return _zgrep (g, regex, path);
  }

  private native String[] _zgrep (long g, String regex, String path)
    throws LibGuestFSException;

  /**
   * return lines matching a pattern
   * <p>
   * This calls the external "zegrep" program and returns the
   * matching lines.
   * <p>
   * Because of the message protocol, there is a transfer
   * limit of somewhere between 2MB and 4MB. See "PROTOCOL
   * LIMITS" in guestfs(3).
   * <p>
   * @throws LibGuestFSException
   */
  public String[] zegrep (String regex, String path)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("zegrep: handle is closed");

    return _zegrep (g, regex, path);
  }

  private native String[] _zegrep (long g, String regex, String path)
    throws LibGuestFSException;

  /**
   * return lines matching a pattern
   * <p>
   * This calls the external "zfgrep" program and returns the
   * matching lines.
   * <p>
   * Because of the message protocol, there is a transfer
   * limit of somewhere between 2MB and 4MB. See "PROTOCOL
   * LIMITS" in guestfs(3).
   * <p>
   * @throws LibGuestFSException
   */
  public String[] zfgrep (String pattern, String path)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("zfgrep: handle is closed");

    return _zfgrep (g, pattern, path);
  }

  private native String[] _zfgrep (long g, String pattern, String path)
    throws LibGuestFSException;

  /**
   * return lines matching a pattern
   * <p>
   * This calls the external "zgrep -i" program and returns
   * the matching lines.
   * <p>
   * Because of the message protocol, there is a transfer
   * limit of somewhere between 2MB and 4MB. See "PROTOCOL
   * LIMITS" in guestfs(3).
   * <p>
   * @throws LibGuestFSException
   */
  public String[] zgrepi (String regex, String path)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("zgrepi: handle is closed");

    return _zgrepi (g, regex, path);
  }

  private native String[] _zgrepi (long g, String regex, String path)
    throws LibGuestFSException;

  /**
   * return lines matching a pattern
   * <p>
   * This calls the external "zegrep -i" program and returns
   * the matching lines.
   * <p>
   * Because of the message protocol, there is a transfer
   * limit of somewhere between 2MB and 4MB. See "PROTOCOL
   * LIMITS" in guestfs(3).
   * <p>
   * @throws LibGuestFSException
   */
  public String[] zegrepi (String regex, String path)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("zegrepi: handle is closed");

    return _zegrepi (g, regex, path);
  }

  private native String[] _zegrepi (long g, String regex, String path)
    throws LibGuestFSException;

  /**
   * return lines matching a pattern
   * <p>
   * This calls the external "zfgrep -i" program and returns
   * the matching lines.
   * <p>
   * Because of the message protocol, there is a transfer
   * limit of somewhere between 2MB and 4MB. See "PROTOCOL
   * LIMITS" in guestfs(3).
   * <p>
   * @throws LibGuestFSException
   */
  public String[] zfgrepi (String pattern, String path)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("zfgrepi: handle is closed");

    return _zfgrepi (g, pattern, path);
  }

  private native String[] _zfgrepi (long g, String pattern, String path)
    throws LibGuestFSException;

  /**
   * canonicalized absolute pathname
   * <p>
   * Return the canonicalized absolute pathname of "path".
   * The returned path has no ".", ".." or symbolic link path
   * elements.
   * <p>
   * @throws LibGuestFSException
   */
  public String realpath (String path)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("realpath: handle is closed");

    return _realpath (g, path);
  }

  private native String _realpath (long g, String path)
    throws LibGuestFSException;

  /**
   * create a hard link
   * <p>
   * This command creates a hard link using the "ln" command.
   * <p>
   * @throws LibGuestFSException
   */
  public void ln (String target, String linkname)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("ln: handle is closed");

    _ln (g, target, linkname);
  }

  private native void _ln (long g, String target, String linkname)
    throws LibGuestFSException;

  /**
   * create a hard link
   * <p>
   * This command creates a hard link using the "ln -f"
   * command. The *-f* option removes the link ("linkname")
   * if it exists already.
   * <p>
   * @throws LibGuestFSException
   */
  public void ln_f (String target, String linkname)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("ln_f: handle is closed");

    _ln_f (g, target, linkname);
  }

  private native void _ln_f (long g, String target, String linkname)
    throws LibGuestFSException;

  /**
   * create a symbolic link
   * <p>
   * This command creates a symbolic link using the "ln -s"
   * command.
   * <p>
   * @throws LibGuestFSException
   */
  public void ln_s (String target, String linkname)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("ln_s: handle is closed");

    _ln_s (g, target, linkname);
  }

  private native void _ln_s (long g, String target, String linkname)
    throws LibGuestFSException;

  /**
   * create a symbolic link
   * <p>
   * This command creates a symbolic link using the "ln -sf"
   * command, The *-f* option removes the link ("linkname")
   * if it exists already.
   * <p>
   * @throws LibGuestFSException
   */
  public void ln_sf (String target, String linkname)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("ln_sf: handle is closed");

    _ln_sf (g, target, linkname);
  }

  private native void _ln_sf (long g, String target, String linkname)
    throws LibGuestFSException;

  /**
   * read the target of a symbolic link
   * <p>
   * This command reads the target of a symbolic link.
   * <p>
   * @throws LibGuestFSException
   */
  public String readlink (String path)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("readlink: handle is closed");

    return _readlink (g, path);
  }

  private native String _readlink (long g, String path)
    throws LibGuestFSException;

  /**
   * preallocate a file in the guest filesystem
   * <p>
   * This command preallocates a file (containing zero bytes)
   * named "path" of size "len" bytes. If the file exists
   * already, it is overwritten.
   * <p>
   * Do not confuse this with the guestfish-specific "alloc"
   * command which allocates a file in the host and attaches
   * it as a device.
   * <p>
   * *This function is deprecated.* In new code, use the
   * "fallocate64" call instead.
   * <p>
   * Deprecated functions will not be removed from the API,
   * but the fact that they are deprecated indicates that
   * there are problems with correct use of these functions.
   * <p>
   * @throws LibGuestFSException
   */
  public void fallocate (String path, int len)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("fallocate: handle is closed");

    _fallocate (g, path, len);
  }

  private native void _fallocate (long g, String path, int len)
    throws LibGuestFSException;

  /**
   * enable swap on device
   * <p>
   * This command enables the libguestfs appliance to use the
   * swap device or partition named "device". The increased
   * memory is made available for all commands, for example
   * those run using "g.command" or "g.sh".
   * <p>
   * Note that you should not swap to existing guest swap
   * partitions unless you know what you are doing. They may
   * contain hibernation information, or other information
   * that the guest doesn't want you to trash. You also risk
   * leaking information about the host to the guest this
   * way. Instead, attach a new host device to the guest and
   * swap on that.
   * <p>
   * @throws LibGuestFSException
   */
  public void swapon_device (String device)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("swapon_device: handle is closed");

    _swapon_device (g, device);
  }

  private native void _swapon_device (long g, String device)
    throws LibGuestFSException;

  /**
   * disable swap on device
   * <p>
   * This command disables the libguestfs appliance swap
   * device or partition named "device". See
   * "g.swapon_device".
   * <p>
   * @throws LibGuestFSException
   */
  public void swapoff_device (String device)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("swapoff_device: handle is closed");

    _swapoff_device (g, device);
  }

  private native void _swapoff_device (long g, String device)
    throws LibGuestFSException;

  /**
   * enable swap on file
   * <p>
   * This command enables swap to a file. See
   * "g.swapon_device" for other notes.
   * <p>
   * @throws LibGuestFSException
   */
  public void swapon_file (String file)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("swapon_file: handle is closed");

    _swapon_file (g, file);
  }

  private native void _swapon_file (long g, String file)
    throws LibGuestFSException;

  /**
   * disable swap on file
   * <p>
   * This command disables the libguestfs appliance swap on
   * file.
   * <p>
   * @throws LibGuestFSException
   */
  public void swapoff_file (String file)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("swapoff_file: handle is closed");

    _swapoff_file (g, file);
  }

  private native void _swapoff_file (long g, String file)
    throws LibGuestFSException;

  /**
   * enable swap on labeled swap partition
   * <p>
   * This command enables swap to a labeled swap partition.
   * See "g.swapon_device" for other notes.
   * <p>
   * @throws LibGuestFSException
   */
  public void swapon_label (String label)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("swapon_label: handle is closed");

    _swapon_label (g, label);
  }

  private native void _swapon_label (long g, String label)
    throws LibGuestFSException;

  /**
   * disable swap on labeled swap partition
   * <p>
   * This command disables the libguestfs appliance swap on
   * labeled swap partition.
   * <p>
   * @throws LibGuestFSException
   */
  public void swapoff_label (String label)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("swapoff_label: handle is closed");

    _swapoff_label (g, label);
  }

  private native void _swapoff_label (long g, String label)
    throws LibGuestFSException;

  /**
   * enable swap on swap partition by UUID
   * <p>
   * This command enables swap to a swap partition with the
   * given UUID. See "g.swapon_device" for other notes.
   * <p>
   * @throws LibGuestFSException
   */
  public void swapon_uuid (String uuid)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("swapon_uuid: handle is closed");

    _swapon_uuid (g, uuid);
  }

  private native void _swapon_uuid (long g, String uuid)
    throws LibGuestFSException;

  /**
   * disable swap on swap partition by UUID
   * <p>
   * This command disables the libguestfs appliance swap
   * partition with the given UUID.
   * <p>
   * @throws LibGuestFSException
   */
  public void swapoff_uuid (String uuid)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("swapoff_uuid: handle is closed");

    _swapoff_uuid (g, uuid);
  }

  private native void _swapoff_uuid (long g, String uuid)
    throws LibGuestFSException;

  /**
   * create a swap file
   * <p>
   * Create a swap file.
   * <p>
   * This command just writes a swap file signature to an
   * existing file. To create the file itself, use something
   * like "g.fallocate".
   * <p>
   * @throws LibGuestFSException
   */
  public void mkswap_file (String path)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("mkswap_file: handle is closed");

    _mkswap_file (g, path);
  }

  private native void _mkswap_file (long g, String path)
    throws LibGuestFSException;

  /**
   * create an inotify handle
   * <p>
   * This command creates a new inotify handle. The inotify
   * subsystem can be used to notify events which happen to
   * objects in the guest filesystem.
   * <p>
   * "maxevents" is the maximum number of events which will
   * be queued up between calls to "g.inotify_read" or
   * "g.inotify_files". If this is passed as 0, then the
   * kernel (or previously set) default is used. For Linux
   * 2.6.29 the default was 16384 events. Beyond this limit,
   * the kernel throws away events, but records the fact that
   * it threw them away by setting a flag "IN_Q_OVERFLOW" in
   * the returned structure list (see "g.inotify_read").
   * <p>
   * Before any events are generated, you have to add some
   * watches to the internal watch list. See:
   * "g.inotify_add_watch" and "g.inotify_rm_watch".
   * <p>
   * Queued up events should be read periodically by calling
   * "g.inotify_read" (or "g.inotify_files" which is just a
   * helpful wrapper around "g.inotify_read"). If you don't
   * read the events out often enough then you risk the
   * internal queue overflowing.
   * <p>
   * The handle should be closed after use by calling
   * "g.inotify_close". This also removes any watches
   * automatically.
   * <p>
   * See also inotify(7) for an overview of the inotify
   * interface as exposed by the Linux kernel, which is
   * roughly what we expose via libguestfs. Note that there
   * is one global inotify handle per libguestfs instance.
   * <p>
   * @throws LibGuestFSException
   */
  public void inotify_init (int maxevents)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("inotify_init: handle is closed");

    _inotify_init (g, maxevents);
  }

  private native void _inotify_init (long g, int maxevents)
    throws LibGuestFSException;

  /**
   * add an inotify watch
   * <p>
   * Watch "path" for the events listed in "mask".
   * <p>
   * Note that if "path" is a directory then events within
   * that directory are watched, but this does *not* happen
   * recursively (in subdirectories).
   * <p>
   * Note for non-C or non-Linux callers: the inotify events
   * are defined by the Linux kernel ABI and are listed in
   * "/usr/include/sys/inotify.h".
   * <p>
   * @throws LibGuestFSException
   */
  public long inotify_add_watch (String path, int mask)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("inotify_add_watch: handle is closed");

    return _inotify_add_watch (g, path, mask);
  }

  private native long _inotify_add_watch (long g, String path, int mask)
    throws LibGuestFSException;

  /**
   * remove an inotify watch
   * <p>
   * Remove a previously defined inotify watch. See
   * "g.inotify_add_watch".
   * <p>
   * @throws LibGuestFSException
   */
  public void inotify_rm_watch (int wd)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("inotify_rm_watch: handle is closed");

    _inotify_rm_watch (g, wd);
  }

  private native void _inotify_rm_watch (long g, int wd)
    throws LibGuestFSException;

  /**
   * return list of inotify events
   * <p>
   * Return the complete queue of events that have happened
   * since the previous read call.
   * <p>
   * If no events have happened, this returns an empty list.
   * <p>
   * *Note*: In order to make sure that all events have been
   * read, you must call this function repeatedly until it
   * returns an empty list. The reason is that the call will
   * read events up to the maximum appliance-to-host message
   * size and leave remaining events in the queue.
   * <p>
   * @throws LibGuestFSException
   */
  public INotifyEvent[] inotify_read ()
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("inotify_read: handle is closed");

    return _inotify_read (g);
  }

  private native INotifyEvent[] _inotify_read (long g)
    throws LibGuestFSException;

  /**
   * return list of watched files that had events
   * <p>
   * This function is a helpful wrapper around
   * "g.inotify_read" which just returns a list of pathnames
   * of objects that were touched. The returned pathnames are
   * sorted and deduplicated.
   * <p>
   * @throws LibGuestFSException
   */
  public String[] inotify_files ()
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("inotify_files: handle is closed");

    return _inotify_files (g);
  }

  private native String[] _inotify_files (long g)
    throws LibGuestFSException;

  /**
   * close the inotify handle
   * <p>
   * This closes the inotify handle which was previously
   * opened by inotify_init. It removes all watches, throws
   * away any pending events, and deallocates all resources.
   * <p>
   * @throws LibGuestFSException
   */
  public void inotify_close ()
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("inotify_close: handle is closed");

    _inotify_close (g);
  }

  private native void _inotify_close (long g)
    throws LibGuestFSException;

  /**
   * set SELinux security context
   * <p>
   * This sets the SELinux security context of the daemon to
   * the string "context".
   * <p>
   * See the documentation about SELINUX in guestfs(3).
   * <p>
   * @throws LibGuestFSException
   */
  public void setcon (String context)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("setcon: handle is closed");

    _setcon (g, context);
  }

  private native void _setcon (long g, String context)
    throws LibGuestFSException;

  /**
   * get SELinux security context
   * <p>
   * This gets the SELinux security context of the daemon.
   * <p>
   * See the documentation about SELINUX in guestfs(3), and
   * "g.setcon"
   * <p>
   * @throws LibGuestFSException
   */
  public String getcon ()
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("getcon: handle is closed");

    return _getcon (g);
  }

  private native String _getcon (long g)
    throws LibGuestFSException;

  /**
   * make a filesystem with block size
   * <p>
   * This call is similar to "g.mkfs", but it allows you to
   * control the block size of the resulting filesystem.
   * Supported block sizes depend on the filesystem type, but
   * typically they are 1024, 2048 or 4096 only.
   * <p>
   * For VFAT and NTFS the "blocksize" parameter is treated
   * as the requested cluster size.
   * <p>
   * *This function is deprecated.* In new code, use the
   * "mkfs_opts" call instead.
   * <p>
   * Deprecated functions will not be removed from the API,
   * but the fact that they are deprecated indicates that
   * there are problems with correct use of these functions.
   * <p>
   * @throws LibGuestFSException
   */
  public void mkfs_b (String fstype, int blocksize, String device)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("mkfs_b: handle is closed");

    _mkfs_b (g, fstype, blocksize, device);
  }

  private native void _mkfs_b (long g, String fstype, int blocksize, String device)
    throws LibGuestFSException;

  /**
   * make ext2/3/4 external journal
   * <p>
   * This creates an ext2 external journal on "device". It is
   * equivalent to the command:
   * <p>
   * mke2fs -O journal_dev -b blocksize device
   * <p>
   * @throws LibGuestFSException
   */
  public void mke2journal (int blocksize, String device)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("mke2journal: handle is closed");

    _mke2journal (g, blocksize, device);
  }

  private native void _mke2journal (long g, int blocksize, String device)
    throws LibGuestFSException;

  /**
   * make ext2/3/4 external journal with label
   * <p>
   * This creates an ext2 external journal on "device" with
   * label "label".
   * <p>
   * @throws LibGuestFSException
   */
  public void mke2journal_L (int blocksize, String label, String device)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("mke2journal_L: handle is closed");

    _mke2journal_L (g, blocksize, label, device);
  }

  private native void _mke2journal_L (long g, int blocksize, String label, String device)
    throws LibGuestFSException;

  /**
   * make ext2/3/4 external journal with UUID
   * <p>
   * This creates an ext2 external journal on "device" with
   * UUID "uuid".
   * <p>
   * @throws LibGuestFSException
   */
  public void mke2journal_U (int blocksize, String uuid, String device)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("mke2journal_U: handle is closed");

    _mke2journal_U (g, blocksize, uuid, device);
  }

  private native void _mke2journal_U (long g, int blocksize, String uuid, String device)
    throws LibGuestFSException;

  /**
   * make ext2/3/4 filesystem with external journal
   * <p>
   * This creates an ext2/3/4 filesystem on "device" with an
   * external journal on "journal". It is equivalent to the
   * command:
   * <p>
   * mke2fs -t fstype -b blocksize -J device=<journal> <device>
   * <p>
   * See also "g.mke2journal".
   * <p>
   * @throws LibGuestFSException
   */
  public void mke2fs_J (String fstype, int blocksize, String device, String journal)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("mke2fs_J: handle is closed");

    _mke2fs_J (g, fstype, blocksize, device, journal);
  }

  private native void _mke2fs_J (long g, String fstype, int blocksize, String device, String journal)
    throws LibGuestFSException;

  /**
   * make ext2/3/4 filesystem with external journal
   * <p>
   * This creates an ext2/3/4 filesystem on "device" with an
   * external journal on the journal labeled "label".
   * <p>
   * See also "g.mke2journal_L".
   * <p>
   * @throws LibGuestFSException
   */
  public void mke2fs_JL (String fstype, int blocksize, String device, String label)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("mke2fs_JL: handle is closed");

    _mke2fs_JL (g, fstype, blocksize, device, label);
  }

  private native void _mke2fs_JL (long g, String fstype, int blocksize, String device, String label)
    throws LibGuestFSException;

  /**
   * make ext2/3/4 filesystem with external journal
   * <p>
   * This creates an ext2/3/4 filesystem on "device" with an
   * external journal on the journal with UUID "uuid".
   * <p>
   * See also "g.mke2journal_U".
   * <p>
   * @throws LibGuestFSException
   */
  public void mke2fs_JU (String fstype, int blocksize, String device, String uuid)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("mke2fs_JU: handle is closed");

    _mke2fs_JU (g, fstype, blocksize, device, uuid);
  }

  private native void _mke2fs_JU (long g, String fstype, int blocksize, String device, String uuid)
    throws LibGuestFSException;

  /**
   * load a kernel module
   * <p>
   * This loads a kernel module in the appliance.
   * <p>
   * The kernel module must have been whitelisted when
   * libguestfs was built (see "appliance/kmod.whitelist.in"
   * in the source).
   * <p>
   * @throws LibGuestFSException
   */
  public void modprobe (String modulename)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("modprobe: handle is closed");

    _modprobe (g, modulename);
  }

  private native void _modprobe (long g, String modulename)
    throws LibGuestFSException;

  /**
   * echo arguments back to the client
   * <p>
   * This command concatenates the list of "words" passed
   * with single spaces between them and returns the
   * resulting string.
   * <p>
   * You can use this command to test the connection through
   * to the daemon.
   * <p>
   * See also "g.ping_daemon".
   * <p>
   * @throws LibGuestFSException
   */
  public String echo_daemon (String[] words)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("echo_daemon: handle is closed");

    return _echo_daemon (g, words);
  }

  private native String _echo_daemon (long g, String[] words)
    throws LibGuestFSException;

  /**
   * find all files and directories, returning NUL-separated list
   * <p>
   * This command lists out all files and directories,
   * recursively, starting at "directory", placing the
   * resulting list in the external file called "files".
   * <p>
   * This command works the same way as "g.find" with the
   * following exceptions:
   * <p>
   * *   The resulting list is written to an external file.
   * <p>
   * *   Items (filenames) in the result are separated by
   * "\0" characters. See find(1) option *-print0*.
   * <p>
   * *   This command is not limited in the number of names
   * that it can return.
   * <p>
   * *   The result list is not sorted.
   * <p>
   * @throws LibGuestFSException
   */
  public void find0 (String directory, String files)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("find0: handle is closed");

    _find0 (g, directory, files);
  }

  private native void _find0 (long g, String directory, String files)
    throws LibGuestFSException;

  /**
   * return true path on case-insensitive filesystem
   * <p>
   * This can be used to resolve case insensitive paths on a
   * filesystem which is case sensitive. The use case is to
   * resolve paths which you have read from Windows
   * configuration files or the Windows Registry, to the true
   * path.
   * <p>
   * The command handles a peculiarity of the Linux ntfs-3g
   * filesystem driver (and probably others), which is that
   * although the underlying filesystem is case-insensitive,
   * the driver exports the filesystem to Linux as
   * case-sensitive.
   * <p>
   * One consequence of this is that special directories such
   * as "c:\windows" may appear as "/WINDOWS" or "/windows"
   * (or other things) depending on the precise details of
   * how they were created. In Windows itself this would not
   * be a problem.
   * <p>
   * Bug or feature? You decide:
   * <http://www.tuxera.com/community/ntfs-3g-faq/#posixfilen
   * ames1>
   * <p>
   * This function resolves the true case of each element in
   * the path and returns the case-sensitive path.
   * <p>
   * Thus "g.case_sensitive_path" ("/Windows/System32") might
   * return "/WINDOWS/system32" (the exact return value would
   * depend on details of how the directories were originally
   * created under Windows).
   * <p>
   * *Note*: This function does not handle drive names,
   * backslashes etc.
   * <p>
   * See also "g.realpath".
   * <p>
   * @throws LibGuestFSException
   */
  public String case_sensitive_path (String path)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("case_sensitive_path: handle is closed");

    return _case_sensitive_path (g, path);
  }

  private native String _case_sensitive_path (long g, String path)
    throws LibGuestFSException;

  /**
   * get the Linux VFS type corresponding to a mounted device
   * <p>
   * This command gets the filesystem type corresponding to
   * the filesystem on "device".
   * <p>
   * For most filesystems, the result is the name of the
   * Linux VFS module which would be used to mount this
   * filesystem if you mounted it without specifying the
   * filesystem type. For example a string such as "ext3" or
   * "ntfs".
   * <p>
   * @throws LibGuestFSException
   */
  public String vfs_type (String device)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("vfs_type: handle is closed");

    return _vfs_type (g, device);
  }

  private native String _vfs_type (long g, String device)
    throws LibGuestFSException;

  /**
   * truncate a file to zero size
   * <p>
   * This command truncates "path" to a zero-length file. The
   * file must exist already.
   * <p>
   * @throws LibGuestFSException
   */
  public void truncate (String path)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("truncate: handle is closed");

    _truncate (g, path);
  }

  private native void _truncate (long g, String path)
    throws LibGuestFSException;

  /**
   * truncate a file to a particular size
   * <p>
   * This command truncates "path" to size "size" bytes. The
   * file must exist already.
   * <p>
   * If the current file size is less than "size" then the
   * file is extended to the required size with zero bytes.
   * This creates a sparse file (ie. disk blocks are not
   * allocated for the file until you write to it). To create
   * a non-sparse file of zeroes, use "g.fallocate64"
   * instead.
   * <p>
   * @throws LibGuestFSException
   */
  public void truncate_size (String path, long size)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("truncate_size: handle is closed");

    _truncate_size (g, path, size);
  }

  private native void _truncate_size (long g, String path, long size)
    throws LibGuestFSException;

  /**
   * set timestamp of a file with nanosecond precision
   * <p>
   * This command sets the timestamps of a file with
   * nanosecond precision.
   * <p>
   * "atsecs, atnsecs" are the last access time (atime) in
   * secs and nanoseconds from the epoch.
   * <p>
   * "mtsecs, mtnsecs" are the last modification time (mtime)
   * in secs and nanoseconds from the epoch.
   * <p>
   * If the *nsecs field contains the special value -1 then
   * the corresponding timestamp is set to the current time.
   * (The *secs field is ignored in this case).
   * <p>
   * If the *nsecs field contains the special value -2 then
   * the corresponding timestamp is left unchanged. (The
   * *secs field is ignored in this case).
   * <p>
   * @throws LibGuestFSException
   */
  public void utimens (String path, long atsecs, long atnsecs, long mtsecs, long mtnsecs)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("utimens: handle is closed");

    _utimens (g, path, atsecs, atnsecs, mtsecs, mtnsecs);
  }

  private native void _utimens (long g, String path, long atsecs, long atnsecs, long mtsecs, long mtnsecs)
    throws LibGuestFSException;

  /**
   * create a directory with a particular mode
   * <p>
   * This command creates a directory, setting the initial
   * permissions of the directory to "mode".
   * <p>
   * For common Linux filesystems, the actual mode which is
   * set will be "mode & ~umask & 01777". Non-native-Linux
   * filesystems may interpret the mode in other ways.
   * <p>
   * See also "g.mkdir", "g.umask"
   * <p>
   * @throws LibGuestFSException
   */
  public void mkdir_mode (String path, int mode)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("mkdir_mode: handle is closed");

    _mkdir_mode (g, path, mode);
  }

  private native void _mkdir_mode (long g, String path, int mode)
    throws LibGuestFSException;

  /**
   * change file owner and group
   * <p>
   * Change the file owner to "owner" and group to "group".
   * This is like "g.chown" but if "path" is a symlink then
   * the link itself is changed, not the target.
   * <p>
   * Only numeric uid and gid are supported. If you want to
   * use names, you will need to locate and parse the
   * password file yourself (Augeas support makes this
   * relatively easy).
   * <p>
   * @throws LibGuestFSException
   */
  public void lchown (int owner, int group, String path)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("lchown: handle is closed");

    _lchown (g, owner, group, path);
  }

  private native void _lchown (long g, int owner, int group, String path)
    throws LibGuestFSException;

  /**
   * lstat on multiple files
   * <p>
   * This call allows you to perform the "g.lstat" operation
   * on multiple files, where all files are in the directory
   * "path". "names" is the list of files from this
   * directory.
   * <p>
   * On return you get a list of stat structs, with a
   * one-to-one correspondence to the "names" list. If any
   * name did not exist or could not be lstat'd, then the
   * "ino" field of that structure is set to -1.
   * <p>
   * This call is intended for programs that want to
   * efficiently list a directory contents without making
   * many round-trips. See also "g.lxattrlist" for a
   * similarly efficient call for getting extended
   * attributes. Very long directory listings might cause the
   * protocol message size to be exceeded, causing this call
   * to fail. The caller must split up such requests into
   * smaller groups of names.
   * <p>
   * @throws LibGuestFSException
   */
  public Stat[] lstatlist (String path, String[] names)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("lstatlist: handle is closed");

    return _lstatlist (g, path, names);
  }

  private native Stat[] _lstatlist (long g, String path, String[] names)
    throws LibGuestFSException;

  /**
   * lgetxattr on multiple files
   * <p>
   * This call allows you to get the extended attributes of
   * multiple files, where all files are in the directory
   * "path". "names" is the list of files from this
   * directory.
   * <p>
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
   * <p>
   * This call is intended for programs that want to
   * efficiently list a directory contents without making
   * many round-trips. See also "g.lstatlist" for a similarly
   * efficient call for getting standard stats. Very long
   * directory listings might cause the protocol message size
   * to be exceeded, causing this call to fail. The caller
   * must split up such requests into smaller groups of
   * names.
   * <p>
   * @throws LibGuestFSException
   */
  public XAttr[] lxattrlist (String path, String[] names)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("lxattrlist: handle is closed");

    return _lxattrlist (g, path, names);
  }

  private native XAttr[] _lxattrlist (long g, String path, String[] names)
    throws LibGuestFSException;

  /**
   * readlink on multiple files
   * <p>
   * This call allows you to do a "readlink" operation on
   * multiple files, where all files are in the directory
   * "path". "names" is the list of files from this
   * directory.
   * <p>
   * On return you get a list of strings, with a one-to-one
   * correspondence to the "names" list. Each string is the
   * value of the symbolic link.
   * <p>
   * If the readlink(2) operation fails on any name, then the
   * corresponding result string is the empty string "".
   * However the whole operation is completed even if there
   * were readlink(2) errors, and so you can call this
   * function with names where you don't know if they are
   * symbolic links already (albeit slightly less efficient).
   * <p>
   * This call is intended for programs that want to
   * efficiently list a directory contents without making
   * many round-trips. Very long directory listings might
   * cause the protocol message size to be exceeded, causing
   * this call to fail. The caller must split up such
   * requests into smaller groups of names.
   * <p>
   * @throws LibGuestFSException
   */
  public String[] readlinklist (String path, String[] names)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("readlinklist: handle is closed");

    return _readlinklist (g, path, names);
  }

  private native String[] _readlinklist (long g, String path, String[] names)
    throws LibGuestFSException;

  /**
   * read part of a file
   * <p>
   * This command lets you read part of a file. It reads
   * "count" bytes of the file, starting at "offset", from
   * file "path".
   * <p>
   * This may read fewer bytes than requested. For further
   * details see the pread(2) system call.
   * <p>
   * See also "g.pwrite", "g.pread_device".
   * <p>
   * Because of the message protocol, there is a transfer
   * limit of somewhere between 2MB and 4MB. See "PROTOCOL
   * LIMITS" in guestfs(3).
   * <p>
   * @throws LibGuestFSException
   */
  public String pread (String path, int count, long offset)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("pread: handle is closed");

    return _pread (g, path, count, offset);
  }

  private native String _pread (long g, String path, int count, long offset)
    throws LibGuestFSException;

  /**
   * create an empty partition table
   * <p>
   * This creates an empty partition table on "device" of one
   * of the partition types listed below. Usually "parttype"
   * should be either "msdos" or "gpt" (for large disks).
   * <p>
   * Initially there are no partitions. Following this, you
   * should call "g.part_add" for each partition required.
   * <p>
   * Possible values for "parttype" are:
   * <p>
   * efi
   * gpt Intel EFI / GPT partition table.
   * <p>
   * This is recommended for >= 2 TB partitions that will
   * be accessed from Linux and Intel-based Mac OS X. It
   * also has limited backwards compatibility with the
   * "mbr" format.
   * <p>
   * mbr
   * msdos
   * The standard PC "Master Boot Record" (MBR) format
   * used by MS-DOS and Windows. This partition type will
   * only work for device sizes up to 2 TB. For large
   * disks we recommend using "gpt".
   * <p>
   * Other partition table types that may work but are not
   * supported include:
   * <p>
   * aix AIX disk labels.
   * <p>
   * amiga
   * rdb Amiga "Rigid Disk Block" format.
   * <p>
   * bsd BSD disk labels.
   * <p>
   * dasd
   * DASD, used on IBM mainframes.
   * <p>
   * dvh MIPS/SGI volumes.
   * <p>
   * mac Old Mac partition format. Modern Macs use "gpt".
   * <p>
   * pc98
   * NEC PC-98 format, common in Japan apparently.
   * <p>
   * sun Sun disk labels.
   * <p>
   * @throws LibGuestFSException
   */
  public void part_init (String device, String parttype)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("part_init: handle is closed");

    _part_init (g, device, parttype);
  }

  private native void _part_init (long g, String device, String parttype)
    throws LibGuestFSException;

  /**
   * add a partition to the device
   * <p>
   * This command adds a partition to "device". If there is
   * no partition table on the device, call "g.part_init"
   * first.
   * <p>
   * The "prlogex" parameter is the type of partition.
   * Normally you should pass "p" or "primary" here, but MBR
   * partition tables also support "l" (or "logical") and "e"
   * (or "extended") partition types.
   * <p>
   * "startsect" and "endsect" are the start and end of the
   * partition in *sectors*. "endsect" may be negative, which
   * means it counts backwards from the end of the disk (-1
   * is the last sector).
   * <p>
   * Creating a partition which covers the whole disk is not
   * so easy. Use "g.part_disk" to do that.
   * <p>
   * @throws LibGuestFSException
   */
  public void part_add (String device, String prlogex, long startsect, long endsect)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("part_add: handle is closed");

    _part_add (g, device, prlogex, startsect, endsect);
  }

  private native void _part_add (long g, String device, String prlogex, long startsect, long endsect)
    throws LibGuestFSException;

  /**
   * partition whole disk with a single primary partition
   * <p>
   * This command is simply a combination of "g.part_init"
   * followed by "g.part_add" to create a single primary
   * partition covering the whole disk.
   * <p>
   * "parttype" is the partition table type, usually "mbr" or
   * "gpt", but other possible values are described in
   * "g.part_init".
   * <p>
   * @throws LibGuestFSException
   */
  public void part_disk (String device, String parttype)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("part_disk: handle is closed");

    _part_disk (g, device, parttype);
  }

  private native void _part_disk (long g, String device, String parttype)
    throws LibGuestFSException;

  /**
   * make a partition bootable
   * <p>
   * This sets the bootable flag on partition numbered
   * "partnum" on device "device". Note that partitions are
   * numbered from 1.
   * <p>
   * The bootable flag is used by some operating systems
   * (notably Windows) to determine which partition to boot
   * from. It is by no means universally recognized.
   * <p>
   * @throws LibGuestFSException
   */
  public void part_set_bootable (String device, int partnum, boolean bootable)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("part_set_bootable: handle is closed");

    _part_set_bootable (g, device, partnum, bootable);
  }

  private native void _part_set_bootable (long g, String device, int partnum, boolean bootable)
    throws LibGuestFSException;

  /**
   * set partition name
   * <p>
   * This sets the partition name on partition numbered
   * "partnum" on device "device". Note that partitions are
   * numbered from 1.
   * <p>
   * The partition name can only be set on certain types of
   * partition table. This works on "gpt" but not on "mbr"
   * partitions.
   * <p>
   * @throws LibGuestFSException
   */
  public void part_set_name (String device, int partnum, String name)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("part_set_name: handle is closed");

    _part_set_name (g, device, partnum, name);
  }

  private native void _part_set_name (long g, String device, int partnum, String name)
    throws LibGuestFSException;

  /**
   * list partitions on a device
   * <p>
   * This command parses the partition table on "device" and
   * returns the list of partitions found.
   * <p>
   * The fields in the returned structure are:
   * <p>
   * part_num
   * Partition number, counting from 1.
   * <p>
   * part_start
   * Start of the partition *in bytes*. To get sectors
   * you have to divide by the device's sector size, see
   * "g.blockdev_getss".
   * <p>
   * part_end
   * End of the partition in bytes.
   * <p>
   * part_size
   * Size of the partition in bytes.
   * <p>
   * @throws LibGuestFSException
   */
  public Partition[] part_list (String device)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("part_list: handle is closed");

    return _part_list (g, device);
  }

  private native Partition[] _part_list (long g, String device)
    throws LibGuestFSException;

  /**
   * get the partition table type
   * <p>
   * This command examines the partition table on "device"
   * and returns the partition table type (format) being
   * used.
   * <p>
   * Common return values include: "msdos" (a DOS/Windows
   * style MBR partition table), "gpt" (a GPT/EFI-style
   * partition table). Other values are possible, although
   * unusual. See "g.part_init" for a full list.
   * <p>
   * @throws LibGuestFSException
   */
  public String part_get_parttype (String device)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("part_get_parttype: handle is closed");

    return _part_get_parttype (g, device);
  }

  private native String _part_get_parttype (long g, String device)
    throws LibGuestFSException;

  /**
   * fill a file with octets
   * <p>
   * This command creates a new file called "path". The
   * initial content of the file is "len" octets of "c",
   * where "c" must be a number in the range "[0..255]".
   * <p>
   * To fill a file with zero bytes (sparsely), it is much
   * more efficient to use "g.truncate_size". To create a
   * file with a pattern of repeating bytes use
   * "g.fill_pattern".
   * <p>
   * @throws LibGuestFSException
   */
  public void fill (int c, int len, String path)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("fill: handle is closed");

    _fill (g, c, len, path);
  }

  private native void _fill (long g, int c, int len, String path)
    throws LibGuestFSException;

  /**
   * test availability of some parts of the API
   * <p>
   * This command is used to check the availability of some
   * groups of functionality in the appliance, which not all
   * builds of the libguestfs appliance will be able to
   * provide.
   * <p>
   * The libguestfs groups, and the functions that those
   * groups correspond to, are listed in "AVAILABILITY" in
   * guestfs(3). You can also fetch this list at runtime by
   * calling "g.available_all_groups".
   * <p>
   * The argument "groups" is a list of group names, eg:
   * "["inotify", "augeas"]" would check for the availability
   * of the Linux inotify functions and Augeas (configuration
   * file editing) functions.
   * <p>
   * The command returns no error if *all* requested groups
   * are available.
   * <p>
   * It fails with an error if one or more of the requested
   * groups is unavailable in the appliance.
   * <p>
   * If an unknown group name is included in the list of
   * groups then an error is always returned.
   * <p>
   * *Notes:*
   * <p>
   * *   You must call "g.launch" before calling this
   * function.
   * <p>
   * The reason is because we don't know what groups are
   * supported by the appliance/daemon until it is
   * running and can be queried.
   * <p>
   * *   If a group of functions is available, this does not
   * necessarily mean that they will work. You still have
   * to check for errors when calling individual API
   * functions even if they are available.
   * <p>
   * *   It is usually the job of distro packagers to build
   * complete functionality into the libguestfs
   * appliance. Upstream libguestfs, if built from source
   * with all requirements satisfied, will support
   * everything.
   * <p>
   * *   This call was added in version 1.0.80. In previous
   * versions of libguestfs all you could do would be to
   * speculatively execute a command to find out if the
   * daemon implemented it. See also "g.version".
   * <p>
   * @throws LibGuestFSException
   */
  public void available (String[] groups)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("available: handle is closed");

    _available (g, groups);
  }

  private native void _available (long g, String[] groups)
    throws LibGuestFSException;

  /**
   * copy from source to destination using dd
   * <p>
   * This command copies from one source device or file "src"
   * to another destination device or file "dest". Normally
   * you would use this to copy to or from a device or
   * partition, for example to duplicate a filesystem.
   * <p>
   * If the destination is a device, it must be as large or
   * larger than the source file or device, otherwise the
   * copy will fail. This command cannot do partial copies
   * (see "g.copy_device_to_device").
   * <p>
   * *This function is deprecated.* In new code, use the
   * "copy_device_to_device" call instead.
   * <p>
   * Deprecated functions will not be removed from the API,
   * but the fact that they are deprecated indicates that
   * there are problems with correct use of these functions.
   * <p>
   * @throws LibGuestFSException
   */
  public void dd (String src, String dest)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("dd: handle is closed");

    _dd (g, src, dest);
  }

  private native void _dd (long g, String src, String dest)
    throws LibGuestFSException;

  /**
   * return the size of the file in bytes
   * <p>
   * This command returns the size of "file" in bytes.
   * <p>
   * To get other stats about a file, use "g.stat",
   * "g.lstat", "g.is_dir", "g.is_file" etc. To get the size
   * of block devices, use "g.blockdev_getsize64".
   * <p>
   * @throws LibGuestFSException
   */
  public long filesize (String file)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("filesize: handle is closed");

    return _filesize (g, file);
  }

  private native long _filesize (long g, String file)
    throws LibGuestFSException;

  /**
   * rename an LVM logical volume
   * <p>
   * Rename a logical volume "logvol" with the new name
   * "newlogvol".
   * <p>
   * @throws LibGuestFSException
   */
  public void lvrename (String logvol, String newlogvol)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("lvrename: handle is closed");

    _lvrename (g, logvol, newlogvol);
  }

  private native void _lvrename (long g, String logvol, String newlogvol)
    throws LibGuestFSException;

  /**
   * rename an LVM volume group
   * <p>
   * Rename a volume group "volgroup" with the new name
   * "newvolgroup".
   * <p>
   * @throws LibGuestFSException
   */
  public void vgrename (String volgroup, String newvolgroup)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("vgrename: handle is closed");

    _vgrename (g, volgroup, newvolgroup);
  }

  private native void _vgrename (long g, String volgroup, String newvolgroup)
    throws LibGuestFSException;

  /**
   * list the contents of a single file in an initrd
   * <p>
   * This command unpacks the file "filename" from the initrd
   * file called "initrdpath". The filename must be given
   * *without* the initial "/" character.
   * <p>
   * For example, in guestfish you could use the following
   * command to examine the boot script (usually called
   * "/init") contained in a Linux initrd or initramfs image:
   * <p>
   * initrd-cat /boot/initrd-<version>.img init
   * <p>
   * See also "g.initrd_list".
   * <p>
   * Because of the message protocol, there is a transfer
   * limit of somewhere between 2MB and 4MB. See "PROTOCOL
   * LIMITS" in guestfs(3).
   * <p>
   * @throws LibGuestFSException
   */
  public String initrd_cat (String initrdpath, String filename)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("initrd_cat: handle is closed");

    return _initrd_cat (g, initrdpath, filename);
  }

  private native String _initrd_cat (long g, String initrdpath, String filename)
    throws LibGuestFSException;

  /**
   * get the UUID of a physical volume
   * <p>
   * This command returns the UUID of the LVM PV "device".
   * <p>
   * @throws LibGuestFSException
   */
  public String pvuuid (String device)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("pvuuid: handle is closed");

    return _pvuuid (g, device);
  }

  private native String _pvuuid (long g, String device)
    throws LibGuestFSException;

  /**
   * get the UUID of a volume group
   * <p>
   * This command returns the UUID of the LVM VG named
   * "vgname".
   * <p>
   * @throws LibGuestFSException
   */
  public String vguuid (String vgname)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("vguuid: handle is closed");

    return _vguuid (g, vgname);
  }

  private native String _vguuid (long g, String vgname)
    throws LibGuestFSException;

  /**
   * get the UUID of a logical volume
   * <p>
   * This command returns the UUID of the LVM LV "device".
   * <p>
   * @throws LibGuestFSException
   */
  public String lvuuid (String device)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("lvuuid: handle is closed");

    return _lvuuid (g, device);
  }

  private native String _lvuuid (long g, String device)
    throws LibGuestFSException;

  /**
   * get the PV UUIDs containing the volume group
   * <p>
   * Given a VG called "vgname", this returns the UUIDs of
   * all the physical volumes that this volume group resides
   * on.
   * <p>
   * You can use this along with "g.pvs" and "g.pvuuid" calls
   * to associate physical volumes and volume groups.
   * <p>
   * See also "g.vglvuuids".
   * <p>
   * @throws LibGuestFSException
   */
  public String[] vgpvuuids (String vgname)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("vgpvuuids: handle is closed");

    return _vgpvuuids (g, vgname);
  }

  private native String[] _vgpvuuids (long g, String vgname)
    throws LibGuestFSException;

  /**
   * get the LV UUIDs of all LVs in the volume group
   * <p>
   * Given a VG called "vgname", this returns the UUIDs of
   * all the logical volumes created in this volume group.
   * <p>
   * You can use this along with "g.lvs" and "g.lvuuid" calls
   * to associate logical volumes and volume groups.
   * <p>
   * See also "g.vgpvuuids".
   * <p>
   * @throws LibGuestFSException
   */
  public String[] vglvuuids (String vgname)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("vglvuuids: handle is closed");

    return _vglvuuids (g, vgname);
  }

  private native String[] _vglvuuids (long g, String vgname)
    throws LibGuestFSException;

  /**
   * copy size bytes from source to destination using dd
   * <p>
   * This command copies exactly "size" bytes from one source
   * device or file "src" to another destination device or
   * file "dest".
   * <p>
   * Note this will fail if the source is too short or if the
   * destination is not large enough.
   * <p>
   * *This function is deprecated.* In new code, use the
   * "copy_device_to_device" call instead.
   * <p>
   * Deprecated functions will not be removed from the API,
   * but the fact that they are deprecated indicates that
   * there are problems with correct use of these functions.
   * <p>
   * @throws LibGuestFSException
   */
  public void copy_size (String src, String dest, long size)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("copy_size: handle is closed");

    _copy_size (g, src, dest, size);
  }

  private native void _copy_size (long g, String src, String dest, long size)
    throws LibGuestFSException;

  /**
   * write zeroes to an entire device
   * <p>
   * This command writes zeroes over the entire "device".
   * Compare with "g.zero" which just zeroes the first few
   * blocks of a device.
   * <p>
   * If blocks are already zero, then this command avoids
   * writing zeroes. This prevents the underlying device from
   * becoming non-sparse or growing unnecessarily.
   * <p>
   * @throws LibGuestFSException
   */
  public void zero_device (String device)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("zero_device: handle is closed");

    _zero_device (g, device);
  }

  private native void _zero_device (long g, String device)
    throws LibGuestFSException;

  /**
   * unpack compressed tarball to directory
   * <p>
   * This command uploads and unpacks local file "tarball"
   * (an *xz compressed* tar file) into "directory".
   * <p>
   * @throws LibGuestFSException
   */
  public void txz_in (String tarball, String directory)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("txz_in: handle is closed");

    _txz_in (g, tarball, directory);
  }

  private native void _txz_in (long g, String tarball, String directory)
    throws LibGuestFSException;

  /**
   * pack directory into compressed tarball
   * <p>
   * This command packs the contents of "directory" and
   * downloads it to local file "tarball" (as an xz
   * compressed tar archive).
   * <p>
   * @throws LibGuestFSException
   */
  public void txz_out (String directory, String tarball)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("txz_out: handle is closed");

    _txz_out (g, directory, tarball);
  }

  private native void _txz_out (long g, String directory, String tarball)
    throws LibGuestFSException;

  /**
   * resize an NTFS filesystem
   * <p>
   * This command resizes an NTFS filesystem, expanding or
   * shrinking it to the size of the underlying device.
   * <p>
   * *Note:* After the resize operation, the filesystem is
   * marked as requiring a consistency check (for safety).
   * You have to boot into Windows to perform this check and
   * clear this condition. Furthermore, ntfsresize refuses to
   * resize filesystems which have been marked in this way.
   * So in effect it is not possible to call ntfsresize
   * multiple times on a single filesystem without booting
   * into Windows between each resize.
   * <p>
   * See also ntfsresize(8).
   * <p>
   * *This function is deprecated.* In new code, use the
   * "ntfsresize_opts" call instead.
   * <p>
   * Deprecated functions will not be removed from the API,
   * but the fact that they are deprecated indicates that
   * there are problems with correct use of these functions.
   * <p>
   * @throws LibGuestFSException
   */
  public void ntfsresize (String device)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("ntfsresize: handle is closed");

    _ntfsresize (g, device);
  }

  private native void _ntfsresize (long g, String device)
    throws LibGuestFSException;

  /**
   * rescan for LVM physical volumes, volume groups and logical volumes
   * <p>
   * This rescans all block devices and rebuilds the list of
   * LVM physical volumes, volume groups and logical volumes.
   * <p>
   * @throws LibGuestFSException
   */
  public void vgscan ()
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("vgscan: handle is closed");

    _vgscan (g);
  }

  private native void _vgscan (long g)
    throws LibGuestFSException;

  /**
   * delete a partition
   * <p>
   * This command deletes the partition numbered "partnum" on
   * "device".
   * <p>
   * Note that in the case of MBR partitioning, deleting an
   * extended partition also deletes any logical partitions
   * it contains.
   * <p>
   * @throws LibGuestFSException
   */
  public void part_del (String device, int partnum)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("part_del: handle is closed");

    _part_del (g, device, partnum);
  }

  private native void _part_del (long g, String device, int partnum)
    throws LibGuestFSException;

  /**
   * return true if a partition is bootable
   * <p>
   * This command returns true if the partition "partnum" on
   * "device" has the bootable flag set.
   * <p>
   * See also "g.part_set_bootable".
   * <p>
   * @throws LibGuestFSException
   */
  public boolean part_get_bootable (String device, int partnum)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("part_get_bootable: handle is closed");

    return _part_get_bootable (g, device, partnum);
  }

  private native boolean _part_get_bootable (long g, String device, int partnum)
    throws LibGuestFSException;

  /**
   * get the MBR type byte (ID byte) from a partition
   * <p>
   * Returns the MBR type byte (also known as the ID byte)
   * from the numbered partition "partnum".
   * <p>
   * Note that only MBR (old DOS-style) partitions have type
   * bytes. You will get undefined results for other
   * partition table types (see "g.part_get_parttype").
   * <p>
   * @throws LibGuestFSException
   */
  public int part_get_mbr_id (String device, int partnum)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("part_get_mbr_id: handle is closed");

    return _part_get_mbr_id (g, device, partnum);
  }

  private native int _part_get_mbr_id (long g, String device, int partnum)
    throws LibGuestFSException;

  /**
   * set the MBR type byte (ID byte) of a partition
   * <p>
   * Sets the MBR type byte (also known as the ID byte) of
   * the numbered partition "partnum" to "idbyte". Note that
   * the type bytes quoted in most documentation are in fact
   * hexadecimal numbers, but usually documented without any
   * leading "0x" which might be confusing.
   * <p>
   * Note that only MBR (old DOS-style) partitions have type
   * bytes. You will get undefined results for other
   * partition table types (see "g.part_get_parttype").
   * <p>
   * @throws LibGuestFSException
   */
  public void part_set_mbr_id (String device, int partnum, int idbyte)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("part_set_mbr_id: handle is closed");

    _part_set_mbr_id (g, device, partnum, idbyte);
  }

  private native void _part_set_mbr_id (long g, String device, int partnum, int idbyte)
    throws LibGuestFSException;

  /**
   * compute MD5, SHAx or CRC checksum of the contents of a device
   * <p>
   * This call computes the MD5, SHAx or CRC checksum of the
   * contents of the device named "device". For the types of
   * checksums supported see the "g.checksum" command.
   * <p>
   * @throws LibGuestFSException
   */
  public String checksum_device (String csumtype, String device)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("checksum_device: handle is closed");

    return _checksum_device (g, csumtype, device);
  }

  private native String _checksum_device (long g, String csumtype, String device)
    throws LibGuestFSException;

  /**
   * expand an LV to fill free space
   * <p>
   * This expands an existing logical volume "lv" so that it
   * fills "pc"% of the remaining free space in the volume
   * group. Commonly you would call this with pc = 100 which
   * expands the logical volume as much as possible, using
   * all remaining free space in the volume group.
   * <p>
   * @throws LibGuestFSException
   */
  public void lvresize_free (String lv, int percent)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("lvresize_free: handle is closed");

    _lvresize_free (g, lv, percent);
  }

  private native void _lvresize_free (long g, String lv, int percent)
    throws LibGuestFSException;

  /**
   * clear Augeas path
   * <p>
   * Set the value associated with "path" to "NULL". This is
   * the same as the augtool(1) "clear" command.
   * <p>
   * @throws LibGuestFSException
   */
  public void aug_clear (String augpath)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("aug_clear: handle is closed");

    _aug_clear (g, augpath);
  }

  private native void _aug_clear (long g, String augpath)
    throws LibGuestFSException;

  /**
   * get the current umask
   * <p>
   * Return the current umask. By default the umask is 022
   * unless it has been set by calling "g.umask".
   * <p>
   * @throws LibGuestFSException
   */
  public int get_umask ()
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("get_umask: handle is closed");

    return _get_umask (g);
  }

  private native int _get_umask (long g)
    throws LibGuestFSException;

  public void debug_upload (String filename, String tmpname, int mode)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("debug_upload: handle is closed");

    _debug_upload (g, filename, tmpname, mode);
  }

  private native void _debug_upload (long g, String filename, String tmpname, int mode)
    throws LibGuestFSException;

  /**
   * upload base64-encoded data to file
   * <p>
   * This command uploads base64-encoded data from
   * "base64file" to "filename".
   * <p>
   * @throws LibGuestFSException
   */
  public void base64_in (String base64file, String filename)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("base64_in: handle is closed");

    _base64_in (g, base64file, filename);
  }

  private native void _base64_in (long g, String base64file, String filename)
    throws LibGuestFSException;

  /**
   * download file and encode as base64
   * <p>
   * This command downloads the contents of "filename",
   * writing it out to local file "base64file" encoded as
   * base64.
   * <p>
   * @throws LibGuestFSException
   */
  public void base64_out (String filename, String base64file)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("base64_out: handle is closed");

    _base64_out (g, filename, base64file);
  }

  private native void _base64_out (long g, String filename, String base64file)
    throws LibGuestFSException;

  /**
   * compute MD5, SHAx or CRC checksum of files in a directory
   * <p>
   * This command computes the checksums of all regular files
   * in "directory" and then emits a list of those checksums
   * to the local output file "sumsfile".
   * <p>
   * This can be used for verifying the integrity of a
   * virtual machine. However to be properly secure you
   * should pay attention to the output of the checksum
   * command (it uses the ones from GNU coreutils). In
   * particular when the filename is not printable, coreutils
   * uses a special backslash syntax. For more information,
   * see the GNU coreutils info file.
   * <p>
   * @throws LibGuestFSException
   */
  public void checksums_out (String csumtype, String directory, String sumsfile)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("checksums_out: handle is closed");

    _checksums_out (g, csumtype, directory, sumsfile);
  }

  private native void _checksums_out (long g, String csumtype, String directory, String sumsfile)
    throws LibGuestFSException;

  /**
   * fill a file with a repeating pattern of bytes
   * <p>
   * This function is like "g.fill" except that it creates a
   * new file of length "len" containing the repeating
   * pattern of bytes in "pattern". The pattern is truncated
   * if necessary to ensure the length of the file is exactly
   * "len" bytes.
   * <p>
   * @throws LibGuestFSException
   */
  public void fill_pattern (String pattern, int len, String path)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("fill_pattern: handle is closed");

    _fill_pattern (g, pattern, len, path);
  }

  private native void _fill_pattern (long g, String pattern, int len, String path)
    throws LibGuestFSException;

  /**
   * create a new file
   * <p>
   * This call creates a file called "path". The content of
   * the file is the string "content" (which can contain any
   * 8 bit data).
   * <p>
   * See also "g.write_append".
   * <p>
   * Because of the message protocol, there is a transfer
   * limit of somewhere between 2MB and 4MB. See "PROTOCOL
   * LIMITS" in guestfs(3).
   * <p>
   * @throws LibGuestFSException
   */
  public void write (String path, byte[] content)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("write: handle is closed");

    _write (g, path, content);
  }

  private native void _write (long g, String path, byte[] content)
    throws LibGuestFSException;

  /**
   * write to part of a file
   * <p>
   * This command writes to part of a file. It writes the
   * data buffer "content" to the file "path" starting at
   * offset "offset".
   * <p>
   * This command implements the pwrite(2) system call, and
   * like that system call it may not write the full data
   * requested. The return value is the number of bytes that
   * were actually written to the file. This could even be 0,
   * although short writes are unlikely for regular files in
   * ordinary circumstances.
   * <p>
   * See also "g.pread", "g.pwrite_device".
   * <p>
   * Because of the message protocol, there is a transfer
   * limit of somewhere between 2MB and 4MB. See "PROTOCOL
   * LIMITS" in guestfs(3).
   * <p>
   * @throws LibGuestFSException
   */
  public int pwrite (String path, byte[] content, long offset)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("pwrite: handle is closed");

    return _pwrite (g, path, content, offset);
  }

  private native int _pwrite (long g, String path, byte[] content, long offset)
    throws LibGuestFSException;

  /**
   * resize an ext2, ext3 or ext4 filesystem (with size)
   * <p>
   * This command is the same as "g.resize2fs" except that it
   * allows you to specify the new size (in bytes)
   * explicitly.
   * <p>
   * See also "RESIZE2FS ERRORS" in guestfs(3).
   * <p>
   * @throws LibGuestFSException
   */
  public void resize2fs_size (String device, long size)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("resize2fs_size: handle is closed");

    _resize2fs_size (g, device, size);
  }

  private native void _resize2fs_size (long g, String device, long size)
    throws LibGuestFSException;

  /**
   * resize an LVM physical volume (with size)
   * <p>
   * This command is the same as "g.pvresize" except that it
   * allows you to specify the new size (in bytes)
   * explicitly.
   * <p>
   * @throws LibGuestFSException
   */
  public void pvresize_size (String device, long size)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("pvresize_size: handle is closed");

    _pvresize_size (g, device, size);
  }

  private native void _pvresize_size (long g, String device, long size)
    throws LibGuestFSException;

  /**
   * resize an NTFS filesystem (with size)
   * <p>
   * This command is the same as "g.ntfsresize" except that
   * it allows you to specify the new size (in bytes)
   * explicitly.
   * <p>
   * *This function is deprecated.* In new code, use the
   * "ntfsresize_opts" call instead.
   * <p>
   * Deprecated functions will not be removed from the API,
   * but the fact that they are deprecated indicates that
   * there are problems with correct use of these functions.
   * <p>
   * @throws LibGuestFSException
   */
  public void ntfsresize_size (String device, long size)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("ntfsresize_size: handle is closed");

    _ntfsresize_size (g, device, size);
  }

  private native void _ntfsresize_size (long g, String device, long size)
    throws LibGuestFSException;

  /**
   * return a list of all optional groups
   * <p>
   * This command returns a list of all optional groups that
   * this daemon knows about. Note this returns both
   * supported and unsupported groups. To find out which ones
   * the daemon can actually support you have to call
   * "g.available" on each member of the returned list.
   * <p>
   * See also "g.available" and "AVAILABILITY" in guestfs(3).
   * <p>
   * @throws LibGuestFSException
   */
  public String[] available_all_groups ()
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("available_all_groups: handle is closed");

    return _available_all_groups (g);
  }

  private native String[] _available_all_groups (long g)
    throws LibGuestFSException;

  /**
   * preallocate a file in the guest filesystem
   * <p>
   * This command preallocates a file (containing zero bytes)
   * named "path" of size "len" bytes. If the file exists
   * already, it is overwritten.
   * <p>
   * Note that this call allocates disk blocks for the file.
   * To create a sparse file use "g.truncate_size" instead.
   * <p>
   * The deprecated call "g.fallocate" does the same, but
   * owing to an oversight it only allowed 30 bit lengths to
   * be specified, effectively limiting the maximum size of
   * files created through that call to 1GB.
   * <p>
   * Do not confuse this with the guestfish-specific "alloc"
   * and "sparse" commands which create a file in the host
   * and attach it as a device.
   * <p>
   * @throws LibGuestFSException
   */
  public void fallocate64 (String path, long len)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("fallocate64: handle is closed");

    _fallocate64 (g, path, len);
  }

  private native void _fallocate64 (long g, String path, long len)
    throws LibGuestFSException;

  /**
   * get the filesystem label
   * <p>
   * This returns the filesystem label of the filesystem on
   * "device".
   * <p>
   * If the filesystem is unlabeled, this returns the empty
   * string.
   * <p>
   * To find a filesystem from the label, use
   * "g.findfs_label".
   * <p>
   * @throws LibGuestFSException
   */
  public String vfs_label (String device)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("vfs_label: handle is closed");

    return _vfs_label (g, device);
  }

  private native String _vfs_label (long g, String device)
    throws LibGuestFSException;

  /**
   * get the filesystem UUID
   * <p>
   * This returns the filesystem UUID of the filesystem on
   * "device".
   * <p>
   * If the filesystem does not have a UUID, this returns the
   * empty string.
   * <p>
   * To find a filesystem from the UUID, use "g.findfs_uuid".
   * <p>
   * @throws LibGuestFSException
   */
  public String vfs_uuid (String device)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("vfs_uuid: handle is closed");

    return _vfs_uuid (g, device);
  }

  private native String _vfs_uuid (long g, String device)
    throws LibGuestFSException;

  /**
   * set LVM device filter
   * <p>
   * This sets the LVM device filter so that LVM will only be
   * able to "see" the block devices in the list "devices",
   * and will ignore all other attached block devices.
   * <p>
   * Where disk image(s) contain duplicate PVs or VGs, this
   * command is useful to get LVM to ignore the duplicates,
   * otherwise LVM can get confused. Note also there are two
   * types of duplication possible: either cloned PVs/VGs
   * which have identical UUIDs; or VGs that are not cloned
   * but just happen to have the same name. In normal
   * operation you cannot create this situation, but you can
   * do it outside LVM, eg. by cloning disk images or by bit
   * twiddling inside the LVM metadata.
   * <p>
   * This command also clears the LVM cache and performs a
   * volume group scan.
   * <p>
   * You can filter whole block devices or individual
   * partitions.
   * <p>
   * You cannot use this if any VG is currently in use (eg.
   * contains a mounted filesystem), even if you are not
   * filtering out that VG.
   * <p>
   * @throws LibGuestFSException
   */
  public void lvm_set_filter (String[] devices)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("lvm_set_filter: handle is closed");

    _lvm_set_filter (g, devices);
  }

  private native void _lvm_set_filter (long g, String[] devices)
    throws LibGuestFSException;

  /**
   * clear LVM device filter
   * <p>
   * This undoes the effect of "g.lvm_set_filter". LVM will
   * be able to see every block device.
   * <p>
   * This command also clears the LVM cache and performs a
   * volume group scan.
   * <p>
   * @throws LibGuestFSException
   */
  public void lvm_clear_filter ()
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("lvm_clear_filter: handle is closed");

    _lvm_clear_filter (g);
  }

  private native void _lvm_clear_filter (long g)
    throws LibGuestFSException;

  /**
   * open a LUKS-encrypted block device
   * <p>
   * This command opens a block device which has been
   * encrypted according to the Linux Unified Key Setup
   * (LUKS) standard.
   * <p>
   * "device" is the encrypted block device or partition.
   * <p>
   * The caller must supply one of the keys associated with
   * the LUKS block device, in the "key" parameter.
   * <p>
   * This creates a new block device called
   * "/dev/mapper/mapname". Reads and writes to this block
   * device are decrypted from and encrypted to the
   * underlying "device" respectively.
   * <p>
   * If this block device contains LVM volume groups, then
   * calling "g.vgscan" followed by "g.vg_activate_all" will
   * make them visible.
   * <p>
   * Use "g.list_dm_devices" to list all device mapper
   * devices.
   * <p>
   * @throws LibGuestFSException
   */
  public void luks_open (String device, String key, String mapname)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("luks_open: handle is closed");

    _luks_open (g, device, key, mapname);
  }

  private native void _luks_open (long g, String device, String key, String mapname)
    throws LibGuestFSException;

  /**
   * open a LUKS-encrypted block device read-only
   * <p>
   * This is the same as "g.luks_open" except that a
   * read-only mapping is created.
   * <p>
   * @throws LibGuestFSException
   */
  public void luks_open_ro (String device, String key, String mapname)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("luks_open_ro: handle is closed");

    _luks_open_ro (g, device, key, mapname);
  }

  private native void _luks_open_ro (long g, String device, String key, String mapname)
    throws LibGuestFSException;

  /**
   * close a LUKS device
   * <p>
   * This closes a LUKS device that was created earlier by
   * "g.luks_open" or "g.luks_open_ro". The "device"
   * parameter must be the name of the LUKS mapping device
   * (ie. "/dev/mapper/mapname") and *not* the name of the
   * underlying block device.
   * <p>
   * @throws LibGuestFSException
   */
  public void luks_close (String device)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("luks_close: handle is closed");

    _luks_close (g, device);
  }

  private native void _luks_close (long g, String device)
    throws LibGuestFSException;

  /**
   * format a block device as a LUKS encrypted device
   * <p>
   * This command erases existing data on "device" and
   * formats the device as a LUKS encrypted device. "key" is
   * the initial key, which is added to key slot "slot".
   * (LUKS supports 8 key slots, numbered 0-7).
   * <p>
   * @throws LibGuestFSException
   */
  public void luks_format (String device, String key, int keyslot)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("luks_format: handle is closed");

    _luks_format (g, device, key, keyslot);
  }

  private native void _luks_format (long g, String device, String key, int keyslot)
    throws LibGuestFSException;

  /**
   * format a block device as a LUKS encrypted device
   * <p>
   * This command is the same as "g.luks_format" but it also
   * allows you to set the "cipher" used.
   * <p>
   * @throws LibGuestFSException
   */
  public void luks_format_cipher (String device, String key, int keyslot, String cipher)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("luks_format_cipher: handle is closed");

    _luks_format_cipher (g, device, key, keyslot, cipher);
  }

  private native void _luks_format_cipher (long g, String device, String key, int keyslot, String cipher)
    throws LibGuestFSException;

  /**
   * add a key on a LUKS encrypted device
   * <p>
   * This command adds a new key on LUKS device "device".
   * "key" is any existing key, and is used to access the
   * device. "newkey" is the new key to add. "keyslot" is the
   * key slot that will be replaced.
   * <p>
   * Note that if "keyslot" already contains a key, then this
   * command will fail. You have to use "g.luks_kill_slot"
   * first to remove that key.
   * <p>
   * @throws LibGuestFSException
   */
  public void luks_add_key (String device, String key, String newkey, int keyslot)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("luks_add_key: handle is closed");

    _luks_add_key (g, device, key, newkey, keyslot);
  }

  private native void _luks_add_key (long g, String device, String key, String newkey, int keyslot)
    throws LibGuestFSException;

  /**
   * remove a key from a LUKS encrypted device
   * <p>
   * This command deletes the key in key slot "keyslot" from
   * the encrypted LUKS device "device". "key" must be one of
   * the *other* keys.
   * <p>
   * @throws LibGuestFSException
   */
  public void luks_kill_slot (String device, String key, int keyslot)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("luks_kill_slot: handle is closed");

    _luks_kill_slot (g, device, key, keyslot);
  }

  private native void _luks_kill_slot (long g, String device, String key, int keyslot)
    throws LibGuestFSException;

  /**
   * test if device is a logical volume
   * <p>
   * This command tests whether "device" is a logical volume,
   * and returns true iff this is the case.
   * <p>
   * @throws LibGuestFSException
   */
  public boolean is_lv (String device)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("is_lv: handle is closed");

    return _is_lv (g, device);
  }

  private native boolean _is_lv (long g, String device)
    throws LibGuestFSException;

  /**
   * find a filesystem by UUID
   * <p>
   * This command searches the filesystems and returns the
   * one which has the given UUID. An error is returned if no
   * such filesystem can be found.
   * <p>
   * To find the UUID of a filesystem, use "g.vfs_uuid".
   * <p>
   * @throws LibGuestFSException
   */
  public String findfs_uuid (String uuid)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("findfs_uuid: handle is closed");

    return _findfs_uuid (g, uuid);
  }

  private native String _findfs_uuid (long g, String uuid)
    throws LibGuestFSException;

  /**
   * find a filesystem by label
   * <p>
   * This command searches the filesystems and returns the
   * one which has the given label. An error is returned if
   * no such filesystem can be found.
   * <p>
   * To find the label of a filesystem, use "g.vfs_label".
   * <p>
   * @throws LibGuestFSException
   */
  public String findfs_label (String label)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("findfs_label: handle is closed");

    return _findfs_label (g, label);
  }

  private native String _findfs_label (long g, String label)
    throws LibGuestFSException;

  /**
   * test if character device
   * <p>
   * This returns "true" if and only if there is a character
   * device with the given "path" name.
   * <p>
   * See also "g.stat".
   * <p>
   * @throws LibGuestFSException
   */
  public boolean is_chardev (String path)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("is_chardev: handle is closed");

    return _is_chardev (g, path);
  }

  private native boolean _is_chardev (long g, String path)
    throws LibGuestFSException;

  /**
   * test if block device
   * <p>
   * This returns "true" if and only if there is a block
   * device with the given "path" name.
   * <p>
   * See also "g.stat".
   * <p>
   * @throws LibGuestFSException
   */
  public boolean is_blockdev (String path)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("is_blockdev: handle is closed");

    return _is_blockdev (g, path);
  }

  private native boolean _is_blockdev (long g, String path)
    throws LibGuestFSException;

  /**
   * test if FIFO (named pipe)
   * <p>
   * This returns "true" if and only if there is a FIFO
   * (named pipe) with the given "path" name.
   * <p>
   * See also "g.stat".
   * <p>
   * @throws LibGuestFSException
   */
  public boolean is_fifo (String path)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("is_fifo: handle is closed");

    return _is_fifo (g, path);
  }

  private native boolean _is_fifo (long g, String path)
    throws LibGuestFSException;

  /**
   * test if symbolic link
   * <p>
   * This returns "true" if and only if there is a symbolic
   * link with the given "path" name.
   * <p>
   * See also "g.stat".
   * <p>
   * @throws LibGuestFSException
   */
  public boolean is_symlink (String path)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("is_symlink: handle is closed");

    return _is_symlink (g, path);
  }

  private native boolean _is_symlink (long g, String path)
    throws LibGuestFSException;

  /**
   * test if socket
   * <p>
   * This returns "true" if and only if there is a Unix
   * domain socket with the given "path" name.
   * <p>
   * See also "g.stat".
   * <p>
   * @throws LibGuestFSException
   */
  public boolean is_socket (String path)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("is_socket: handle is closed");

    return _is_socket (g, path);
  }

  private native boolean _is_socket (long g, String path)
    throws LibGuestFSException;

  /**
   * convert partition name to device name
   * <p>
   * This function takes a partition name (eg. "/dev/sdb1")
   * and removes the partition number, returning the device
   * name (eg. "/dev/sdb").
   * <p>
   * The named partition must exist, for example as a string
   * returned from "g.list_partitions".
   * <p>
   * See also "g.part_to_partnum", "g.device_index".
   * <p>
   * @throws LibGuestFSException
   */
  public String part_to_dev (String partition)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("part_to_dev: handle is closed");

    return _part_to_dev (g, partition);
  }

  private native String _part_to_dev (long g, String partition)
    throws LibGuestFSException;

  /**
   * upload a file from the local machine with offset
   * <p>
   * Upload local file "filename" to "remotefilename" on the
   * filesystem.
   * <p>
   * "remotefilename" is overwritten starting at the byte
   * "offset" specified. The intention is to overwrite parts
   * of existing files or devices, although if a non-existant
   * file is specified then it is created with a "hole"
   * before "offset". The size of the data written is
   * implicit in the size of the source "filename".
   * <p>
   * Note that there is no limit on the amount of data that
   * can be uploaded with this call, unlike with "g.pwrite",
   * and this call always writes the full amount unless an
   * error occurs.
   * <p>
   * See also "g.upload", "g.pwrite".
   * <p>
   * @throws LibGuestFSException
   */
  public void upload_offset (String filename, String remotefilename, long offset)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("upload_offset: handle is closed");

    _upload_offset (g, filename, remotefilename, offset);
  }

  private native void _upload_offset (long g, String filename, String remotefilename, long offset)
    throws LibGuestFSException;

  /**
   * download a file to the local machine with offset and size
   * <p>
   * Download file "remotefilename" and save it as "filename"
   * on the local machine.
   * <p>
   * "remotefilename" is read for "size" bytes starting at
   * "offset" (this region must be within the file or
   * device).
   * <p>
   * Note that there is no limit on the amount of data that
   * can be downloaded with this call, unlike with "g.pread",
   * and this call always reads the full amount unless an
   * error occurs.
   * <p>
   * See also "g.download", "g.pread".
   * <p>
   * @throws LibGuestFSException
   */
  public void download_offset (String remotefilename, String filename, long offset, long size)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("download_offset: handle is closed");

    _download_offset (g, remotefilename, filename, offset, size);
  }

  private native void _download_offset (long g, String remotefilename, String filename, long offset, long size)
    throws LibGuestFSException;

  /**
   * write to part of a device
   * <p>
   * This command writes to part of a device. It writes the
   * data buffer "content" to "device" starting at offset
   * "offset".
   * <p>
   * This command implements the pwrite(2) system call, and
   * like that system call it may not write the full data
   * requested (although short writes to disk devices and
   * partitions are probably impossible with standard Linux
   * kernels).
   * <p>
   * See also "g.pwrite".
   * <p>
   * Because of the message protocol, there is a transfer
   * limit of somewhere between 2MB and 4MB. See "PROTOCOL
   * LIMITS" in guestfs(3).
   * <p>
   * @throws LibGuestFSException
   */
  public int pwrite_device (String device, byte[] content, long offset)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("pwrite_device: handle is closed");

    return _pwrite_device (g, device, content, offset);
  }

  private native int _pwrite_device (long g, String device, byte[] content, long offset)
    throws LibGuestFSException;

  /**
   * read part of a device
   * <p>
   * This command lets you read part of a file. It reads
   * "count" bytes of "device", starting at "offset".
   * <p>
   * This may read fewer bytes than requested. For further
   * details see the pread(2) system call.
   * <p>
   * See also "g.pread".
   * <p>
   * Because of the message protocol, there is a transfer
   * limit of somewhere between 2MB and 4MB. See "PROTOCOL
   * LIMITS" in guestfs(3).
   * <p>
   * @throws LibGuestFSException
   */
  public String pread_device (String device, int count, long offset)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("pread_device: handle is closed");

    return _pread_device (g, device, count, offset);
  }

  private native String _pread_device (long g, String device, int count, long offset)
    throws LibGuestFSException;

  /**
   * get canonical name of an LV
   * <p>
   * This converts alternative naming schemes for LVs that
   * you might find to the canonical name. For example,
   * "/dev/mapper/VG-LV" is converted to "/dev/VG/LV".
   * <p>
   * This command returns an error if the "lvname" parameter
   * does not refer to a logical volume.
   * <p>
   * See also "g.is_lv".
   * <p>
   * @throws LibGuestFSException
   */
  public String lvm_canonical_lv_name (String lvname)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("lvm_canonical_lv_name: handle is closed");

    return _lvm_canonical_lv_name (g, lvname);
  }

  private native String _lvm_canonical_lv_name (long g, String lvname)
    throws LibGuestFSException;

  /**
   * make a filesystem
   * <p>
   * This function creates a filesystem on "device". The
   * filesystem type is "fstype", for example "ext3".
   * <p>
   * The optional arguments are:
   * <p>
   * "blocksize"
   * The filesystem block size. Supported block sizes
   * depend on the filesystem type, but typically they
   * are 1024, 2048 or 4096 for Linux ext2/3 filesystems.
   * <p>
   * For VFAT and NTFS the "blocksize" parameter is
   * treated as the requested cluster size.
   * <p>
   * For UFS block sizes, please see mkfs.ufs(8).
   * <p>
   * "features"
   * This passes the *-O* parameter to the external mkfs
   * program.
   * <p>
   * For certain filesystem types, this allows extra
   * filesystem features to be selected. See mke2fs(8)
   * and mkfs.ufs(8) for more details.
   * <p>
   * You cannot use this optional parameter with the
   * "gfs" or "gfs2" filesystem type.
   * <p>
   * "inode"
   * This passes the *-I* parameter to the external
   * mke2fs(8) program which sets the inode size (only
   * for ext2/3/4 filesystems at present).
   * <p>
   * "sectorsize"
   * This passes the *-S* parameter to external
   * mkfs.ufs(8) program, which sets sector size for ufs
   * filesystem.
   * <p>
   * Optional arguments are supplied in the final
   * Map<String,Object> parameter, which is a hash of the
   * argument name to its value (cast to Object). Pass an
   * empty Map or null for no optional arguments.
   * <p>
   * @throws LibGuestFSException
   */
  public void mkfs_opts (String fstype, String device, Map<String, Object> optargs)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("mkfs_opts: handle is closed");

    /* Unpack optional args. */
    Object _optobj;
    long _optargs_bitmask = 0;
    int blocksize = 0;
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("blocksize");
    if (_optobj != null) {
      blocksize = ((Integer) _optobj).intValue();
      _optargs_bitmask |= 1L;
    }
    String features = "";
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("features");
    if (_optobj != null) {
      features = ((String) _optobj);
      _optargs_bitmask |= 2L;
    }
    int inode = 0;
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("inode");
    if (_optobj != null) {
      inode = ((Integer) _optobj).intValue();
      _optargs_bitmask |= 4L;
    }
    int sectorsize = 0;
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("sectorsize");
    if (_optobj != null) {
      sectorsize = ((Integer) _optobj).intValue();
      _optargs_bitmask |= 8L;
    }

    _mkfs_opts (g, fstype, device, _optargs_bitmask, blocksize, features, inode, sectorsize);
  }

  public void mkfs_opts (String fstype, String device)
    throws LibGuestFSException
  {
    mkfs_opts (fstype, device, null);
  }

  private native void _mkfs_opts (long g, String fstype, String device, long _optargs_bitmask, int blocksize, String features, int inode, int sectorsize)
    throws LibGuestFSException;

  /**
   * get a single extended attribute
   * <p>
   * Get a single extended attribute from file "path" named
   * "name". This call follows symlinks. If you want to
   * lookup an extended attribute for the symlink itself, use
   * "g.lgetxattr".
   * <p>
   * Normally it is better to get all extended attributes
   * from a file in one go by calling "g.getxattrs". However
   * some Linux filesystem implementations are buggy and do
   * not provide a way to list out attributes. For these
   * filesystems (notably ntfs-3g) you have to know the names
   * of the extended attributes you want in advance and call
   * this function.
   * <p>
   * Extended attribute values are blobs of binary data. If
   * there is no extended attribute named "name", this
   * returns an error.
   * <p>
   * See also: "g.getxattrs", "g.lgetxattr", attr(5).
   * <p>
   * @throws LibGuestFSException
   */
  public String getxattr (String path, String name)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("getxattr: handle is closed");

    return _getxattr (g, path, name);
  }

  private native String _getxattr (long g, String path, String name)
    throws LibGuestFSException;

  /**
   * get a single extended attribute
   * <p>
   * Get a single extended attribute from file "path" named
   * "name". If "path" is a symlink, then this call returns
   * an extended attribute from the symlink.
   * <p>
   * Normally it is better to get all extended attributes
   * from a file in one go by calling "g.getxattrs". However
   * some Linux filesystem implementations are buggy and do
   * not provide a way to list out attributes. For these
   * filesystems (notably ntfs-3g) you have to know the names
   * of the extended attributes you want in advance and call
   * this function.
   * <p>
   * Extended attribute values are blobs of binary data. If
   * there is no extended attribute named "name", this
   * returns an error.
   * <p>
   * See also: "g.lgetxattrs", "g.getxattr", attr(5).
   * <p>
   * @throws LibGuestFSException
   */
  public String lgetxattr (String path, String name)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("lgetxattr: handle is closed");

    return _lgetxattr (g, path, name);
  }

  private native String _lgetxattr (long g, String path, String name)
    throws LibGuestFSException;

  /**
   * resize an ext2, ext3 or ext4 filesystem to the minimum size
   * <p>
   * This command is the same as "g.resize2fs", but the
   * filesystem is resized to its minimum size. This works
   * like the *-M* option to the "resize2fs" command.
   * <p>
   * To get the resulting size of the filesystem you should
   * call "g.tune2fs_l" and read the "Block size" and "Block
   * count" values. These two numbers, multiplied together,
   * give the resulting size of the minimal filesystem in
   * bytes.
   * <p>
   * See also "RESIZE2FS ERRORS" in guestfs(3).
   * <p>
   * @throws LibGuestFSException
   */
  public void resize2fs_M (String device)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("resize2fs_M: handle is closed");

    _resize2fs_M (g, device);
  }

  private native void _resize2fs_M (long g, String device)
    throws LibGuestFSException;

  public void internal_autosync ()
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("internal_autosync: handle is closed");

    _internal_autosync (g);
  }

  private native void _internal_autosync (long g)
    throws LibGuestFSException;

  /**
   * test if a file contains all zero bytes
   * <p>
   * This returns true iff the file exists and the file is
   * empty or it contains all zero bytes.
   * <p>
   * @throws LibGuestFSException
   */
  public boolean is_zero (String path)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("is_zero: handle is closed");

    return _is_zero (g, path);
  }

  private native boolean _is_zero (long g, String path)
    throws LibGuestFSException;

  /**
   * test if a device contains all zero bytes
   * <p>
   * This returns true iff the device exists and contains all
   * zero bytes.
   * <p>
   * Note that for large devices this can take a long time to
   * run.
   * <p>
   * @throws LibGuestFSException
   */
  public boolean is_zero_device (String device)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("is_zero_device: handle is closed");

    return _is_zero_device (g, device);
  }

  private native boolean _is_zero_device (long g, String device)
    throws LibGuestFSException;

  /**
   * list 9p filesystems
   * <p>
   * List all 9p filesystems attached to the guest. A list of
   * mount tags is returned.
   * <p>
   * @throws LibGuestFSException
   */
  public String[] list_9p ()
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("list_9p: handle is closed");

    return _list_9p (g);
  }

  private native String[] _list_9p (long g)
    throws LibGuestFSException;

  /**
   * mount 9p filesystem
   * <p>
   * Mount the virtio-9p filesystem with the tag "mounttag"
   * on the directory "mountpoint".
   * <p>
   * If required, "trans=virtio" will be automatically added
   * to the options. Any other options required can be passed
   * in the optional "options" parameter.
   * <p>
   * Optional arguments are supplied in the final
   * Map<String,Object> parameter, which is a hash of the
   * argument name to its value (cast to Object). Pass an
   * empty Map or null for no optional arguments.
   * <p>
   * @throws LibGuestFSException
   */
  public void mount_9p (String mounttag, String mountpoint, Map<String, Object> optargs)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("mount_9p: handle is closed");

    /* Unpack optional args. */
    Object _optobj;
    long _optargs_bitmask = 0;
    String options = "";
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("options");
    if (_optobj != null) {
      options = ((String) _optobj);
      _optargs_bitmask |= 1L;
    }

    _mount_9p (g, mounttag, mountpoint, _optargs_bitmask, options);
  }

  public void mount_9p (String mounttag, String mountpoint)
    throws LibGuestFSException
  {
    mount_9p (mounttag, mountpoint, null);
  }

  private native void _mount_9p (long g, String mounttag, String mountpoint, long _optargs_bitmask, String options)
    throws LibGuestFSException;

  /**
   * list device mapper devices
   * <p>
   * List all device mapper devices.
   * <p>
   * The returned list contains "/dev/mapper/*" devices, eg.
   * ones created by a previous call to "g.luks_open".
   * <p>
   * Device mapper devices which correspond to logical
   * volumes are *not* returned in this list. Call "g.lvs" if
   * you want to list logical volumes.
   * <p>
   * @throws LibGuestFSException
   */
  public String[] list_dm_devices ()
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("list_dm_devices: handle is closed");

    return _list_dm_devices (g);
  }

  private native String[] _list_dm_devices (long g)
    throws LibGuestFSException;

  /**
   * resize an NTFS filesystem
   * <p>
   * This command resizes an NTFS filesystem, expanding or
   * shrinking it to the size of the underlying device.
   * <p>
   * The optional parameters are:
   * <p>
   * "size"
   * The new size (in bytes) of the filesystem. If
   * omitted, the filesystem is resized to fit the
   * container (eg. partition).
   * <p>
   * "force"
   * If this option is true, then force the resize of the
   * filesystem even if the filesystem is marked as
   * requiring a consistency check.
   * <p>
   * After the resize operation, the filesystem is always
   * marked as requiring a consistency check (for
   * safety). You have to boot into Windows to perform
   * this check and clear this condition. If you *don't*
   * set the "force" option then it is not possible to
   * call "g.ntfsresize_opts" multiple times on a single
   * filesystem without booting into Windows between each
   * resize.
   * <p>
   * See also ntfsresize(8).
   * <p>
   * Optional arguments are supplied in the final
   * Map<String,Object> parameter, which is a hash of the
   * argument name to its value (cast to Object). Pass an
   * empty Map or null for no optional arguments.
   * <p>
   * @throws LibGuestFSException
   */
  public void ntfsresize_opts (String device, Map<String, Object> optargs)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("ntfsresize_opts: handle is closed");

    /* Unpack optional args. */
    Object _optobj;
    long _optargs_bitmask = 0;
    long size = 0;
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("size");
    if (_optobj != null) {
      size = ((Long) _optobj).longValue();
      _optargs_bitmask |= 1L;
    }
    boolean force = false;
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("force");
    if (_optobj != null) {
      force = ((Boolean) _optobj).booleanValue();
      _optargs_bitmask |= 2L;
    }

    _ntfsresize_opts (g, device, _optargs_bitmask, size, force);
  }

  public void ntfsresize_opts (String device)
    throws LibGuestFSException
  {
    ntfsresize_opts (device, null);
  }

  private native void _ntfsresize_opts (long g, String device, long _optargs_bitmask, long size, boolean force)
    throws LibGuestFSException;

  /**
   * resize a btrfs filesystem
   * <p>
   * This command resizes a btrfs filesystem.
   * <p>
   * Note that unlike other resize calls, the filesystem has
   * to be mounted and the parameter is the mountpoint not
   * the device (this is a requirement of btrfs itself).
   * <p>
   * The optional parameters are:
   * <p>
   * "size"
   * The new size (in bytes) of the filesystem. If
   * omitted, the filesystem is resized to the maximum
   * size.
   * <p>
   * See also btrfs(8).
   * <p>
   * Optional arguments are supplied in the final
   * Map<String,Object> parameter, which is a hash of the
   * argument name to its value (cast to Object). Pass an
   * empty Map or null for no optional arguments.
   * <p>
   * @throws LibGuestFSException
   */
  public void btrfs_filesystem_resize (String mountpoint, Map<String, Object> optargs)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("btrfs_filesystem_resize: handle is closed");

    /* Unpack optional args. */
    Object _optobj;
    long _optargs_bitmask = 0;
    long size = 0;
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("size");
    if (_optobj != null) {
      size = ((Long) _optobj).longValue();
      _optargs_bitmask |= 1L;
    }

    _btrfs_filesystem_resize (g, mountpoint, _optargs_bitmask, size);
  }

  public void btrfs_filesystem_resize (String mountpoint)
    throws LibGuestFSException
  {
    btrfs_filesystem_resize (mountpoint, null);
  }

  private native void _btrfs_filesystem_resize (long g, String mountpoint, long _optargs_bitmask, long size)
    throws LibGuestFSException;

  /**
   * append content to end of file
   * <p>
   * This call appends "content" to the end of file "path".
   * If "path" does not exist, then a new file is created.
   * <p>
   * See also "g.write".
   * <p>
   * Because of the message protocol, there is a transfer
   * limit of somewhere between 2MB and 4MB. See "PROTOCOL
   * LIMITS" in guestfs(3).
   * <p>
   * @throws LibGuestFSException
   */
  public void write_append (String path, byte[] content)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("write_append: handle is closed");

    _write_append (g, path, content);
  }

  private native void _write_append (long g, String path, byte[] content)
    throws LibGuestFSException;

  /**
   * output compressed file
   * <p>
   * This command compresses "file" and writes it out to the
   * local file "zfile".
   * <p>
   * The compression program used is controlled by the
   * "ctype" parameter. Currently this includes: "compress",
   * "gzip", "bzip2", "xz" or "lzop". Some compression types
   * may not be supported by particular builds of libguestfs,
   * in which case you will get an error containing the
   * substring "not supported".
   * <p>
   * The optional "level" parameter controls compression
   * level. The meaning and default for this parameter
   * depends on the compression program being used.
   * <p>
   * Optional arguments are supplied in the final
   * Map<String,Object> parameter, which is a hash of the
   * argument name to its value (cast to Object). Pass an
   * empty Map or null for no optional arguments.
   * <p>
   * @throws LibGuestFSException
   */
  public void compress_out (String ctype, String file, String zfile, Map<String, Object> optargs)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("compress_out: handle is closed");

    /* Unpack optional args. */
    Object _optobj;
    long _optargs_bitmask = 0;
    int level = 0;
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("level");
    if (_optobj != null) {
      level = ((Integer) _optobj).intValue();
      _optargs_bitmask |= 1L;
    }

    _compress_out (g, ctype, file, zfile, _optargs_bitmask, level);
  }

  public void compress_out (String ctype, String file, String zfile)
    throws LibGuestFSException
  {
    compress_out (ctype, file, zfile, null);
  }

  private native void _compress_out (long g, String ctype, String file, String zfile, long _optargs_bitmask, int level)
    throws LibGuestFSException;

  /**
   * output compressed device
   * <p>
   * This command compresses "device" and writes it out to
   * the local file "zdevice".
   * <p>
   * The "ctype" and optional "level" parameters have the
   * same meaning as in "g.compress_out".
   * <p>
   * Optional arguments are supplied in the final
   * Map<String,Object> parameter, which is a hash of the
   * argument name to its value (cast to Object). Pass an
   * empty Map or null for no optional arguments.
   * <p>
   * @throws LibGuestFSException
   */
  public void compress_device_out (String ctype, String device, String zdevice, Map<String, Object> optargs)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("compress_device_out: handle is closed");

    /* Unpack optional args. */
    Object _optobj;
    long _optargs_bitmask = 0;
    int level = 0;
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("level");
    if (_optobj != null) {
      level = ((Integer) _optobj).intValue();
      _optargs_bitmask |= 1L;
    }

    _compress_device_out (g, ctype, device, zdevice, _optargs_bitmask, level);
  }

  public void compress_device_out (String ctype, String device, String zdevice)
    throws LibGuestFSException
  {
    compress_device_out (ctype, device, zdevice, null);
  }

  private native void _compress_device_out (long g, String ctype, String device, String zdevice, long _optargs_bitmask, int level)
    throws LibGuestFSException;

  /**
   * convert partition name to partition number
   * <p>
   * This function takes a partition name (eg. "/dev/sdb1")
   * and returns the partition number (eg. 1).
   * <p>
   * The named partition must exist, for example as a string
   * returned from "g.list_partitions".
   * <p>
   * See also "g.part_to_dev".
   * <p>
   * @throws LibGuestFSException
   */
  public int part_to_partnum (String partition)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("part_to_partnum: handle is closed");

    return _part_to_partnum (g, partition);
  }

  private native int _part_to_partnum (long g, String partition)
    throws LibGuestFSException;

  /**
   * copy from source device to destination device
   * <p>
   * The four calls "g.copy_device_to_device",
   * "g.copy_device_to_file", "g.copy_file_to_device", and
   * "g.copy_file_to_file" let you copy from a source
   * (device|file) to a destination (device|file).
   * <p>
   * Partial copies can be made since you can specify
   * optionally the source offset, destination offset and
   * size to copy. These values are all specified in bytes.
   * If not given, the offsets both default to zero, and the
   * size defaults to copying as much as possible until we
   * hit the end of the source.
   * <p>
   * The source and destination may be the same object.
   * However overlapping regions may not be copied correctly.
   * <p>
   * If the destination is a file, it is created if required.
   * If the destination file is not large enough, it is
   * extended.
   * <p>
   * Optional arguments are supplied in the final
   * Map<String,Object> parameter, which is a hash of the
   * argument name to its value (cast to Object). Pass an
   * empty Map or null for no optional arguments.
   * <p>
   * @throws LibGuestFSException
   */
  public void copy_device_to_device (String src, String dest, Map<String, Object> optargs)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("copy_device_to_device: handle is closed");

    /* Unpack optional args. */
    Object _optobj;
    long _optargs_bitmask = 0;
    long srcoffset = 0;
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("srcoffset");
    if (_optobj != null) {
      srcoffset = ((Long) _optobj).longValue();
      _optargs_bitmask |= 1L;
    }
    long destoffset = 0;
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("destoffset");
    if (_optobj != null) {
      destoffset = ((Long) _optobj).longValue();
      _optargs_bitmask |= 2L;
    }
    long size = 0;
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("size");
    if (_optobj != null) {
      size = ((Long) _optobj).longValue();
      _optargs_bitmask |= 4L;
    }

    _copy_device_to_device (g, src, dest, _optargs_bitmask, srcoffset, destoffset, size);
  }

  public void copy_device_to_device (String src, String dest)
    throws LibGuestFSException
  {
    copy_device_to_device (src, dest, null);
  }

  private native void _copy_device_to_device (long g, String src, String dest, long _optargs_bitmask, long srcoffset, long destoffset, long size)
    throws LibGuestFSException;

  /**
   * copy from source device to destination file
   * <p>
   * See "g.copy_device_to_device" for a general overview of
   * this call.
   * <p>
   * Optional arguments are supplied in the final
   * Map<String,Object> parameter, which is a hash of the
   * argument name to its value (cast to Object). Pass an
   * empty Map or null for no optional arguments.
   * <p>
   * @throws LibGuestFSException
   */
  public void copy_device_to_file (String src, String dest, Map<String, Object> optargs)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("copy_device_to_file: handle is closed");

    /* Unpack optional args. */
    Object _optobj;
    long _optargs_bitmask = 0;
    long srcoffset = 0;
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("srcoffset");
    if (_optobj != null) {
      srcoffset = ((Long) _optobj).longValue();
      _optargs_bitmask |= 1L;
    }
    long destoffset = 0;
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("destoffset");
    if (_optobj != null) {
      destoffset = ((Long) _optobj).longValue();
      _optargs_bitmask |= 2L;
    }
    long size = 0;
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("size");
    if (_optobj != null) {
      size = ((Long) _optobj).longValue();
      _optargs_bitmask |= 4L;
    }

    _copy_device_to_file (g, src, dest, _optargs_bitmask, srcoffset, destoffset, size);
  }

  public void copy_device_to_file (String src, String dest)
    throws LibGuestFSException
  {
    copy_device_to_file (src, dest, null);
  }

  private native void _copy_device_to_file (long g, String src, String dest, long _optargs_bitmask, long srcoffset, long destoffset, long size)
    throws LibGuestFSException;

  /**
   * copy from source file to destination device
   * <p>
   * See "g.copy_device_to_device" for a general overview of
   * this call.
   * <p>
   * Optional arguments are supplied in the final
   * Map<String,Object> parameter, which is a hash of the
   * argument name to its value (cast to Object). Pass an
   * empty Map or null for no optional arguments.
   * <p>
   * @throws LibGuestFSException
   */
  public void copy_file_to_device (String src, String dest, Map<String, Object> optargs)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("copy_file_to_device: handle is closed");

    /* Unpack optional args. */
    Object _optobj;
    long _optargs_bitmask = 0;
    long srcoffset = 0;
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("srcoffset");
    if (_optobj != null) {
      srcoffset = ((Long) _optobj).longValue();
      _optargs_bitmask |= 1L;
    }
    long destoffset = 0;
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("destoffset");
    if (_optobj != null) {
      destoffset = ((Long) _optobj).longValue();
      _optargs_bitmask |= 2L;
    }
    long size = 0;
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("size");
    if (_optobj != null) {
      size = ((Long) _optobj).longValue();
      _optargs_bitmask |= 4L;
    }

    _copy_file_to_device (g, src, dest, _optargs_bitmask, srcoffset, destoffset, size);
  }

  public void copy_file_to_device (String src, String dest)
    throws LibGuestFSException
  {
    copy_file_to_device (src, dest, null);
  }

  private native void _copy_file_to_device (long g, String src, String dest, long _optargs_bitmask, long srcoffset, long destoffset, long size)
    throws LibGuestFSException;

  /**
   * copy from source file to destination file
   * <p>
   * See "g.copy_device_to_device" for a general overview of
   * this call.
   * <p>
   * This is not the function you want for copying files.
   * This is for copying blocks within existing files. See
   * "g.cp", "g.cp_a" and "g.mv" for general file copying and
   * moving functions.
   * <p>
   * Optional arguments are supplied in the final
   * Map<String,Object> parameter, which is a hash of the
   * argument name to its value (cast to Object). Pass an
   * empty Map or null for no optional arguments.
   * <p>
   * @throws LibGuestFSException
   */
  public void copy_file_to_file (String src, String dest, Map<String, Object> optargs)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("copy_file_to_file: handle is closed");

    /* Unpack optional args. */
    Object _optobj;
    long _optargs_bitmask = 0;
    long srcoffset = 0;
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("srcoffset");
    if (_optobj != null) {
      srcoffset = ((Long) _optobj).longValue();
      _optargs_bitmask |= 1L;
    }
    long destoffset = 0;
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("destoffset");
    if (_optobj != null) {
      destoffset = ((Long) _optobj).longValue();
      _optargs_bitmask |= 2L;
    }
    long size = 0;
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("size");
    if (_optobj != null) {
      size = ((Long) _optobj).longValue();
      _optargs_bitmask |= 4L;
    }

    _copy_file_to_file (g, src, dest, _optargs_bitmask, srcoffset, destoffset, size);
  }

  public void copy_file_to_file (String src, String dest)
    throws LibGuestFSException
  {
    copy_file_to_file (src, dest, null);
  }

  private native void _copy_file_to_file (long g, String src, String dest, long _optargs_bitmask, long srcoffset, long destoffset, long size)
    throws LibGuestFSException;

  /**
   * adjust ext2/ext3/ext4 filesystem parameters
   * <p>
   * This call allows you to adjust various filesystem
   * parameters of an ext2/ext3/ext4 filesystem called
   * "device".
   * <p>
   * The optional parameters are:
   * <p>
   * "force"
   * Force tune2fs to complete the operation even in the
   * face of errors. This is the same as the tune2fs "-f"
   * option.
   * <p>
   * "maxmountcount"
   * Set the number of mounts after which the filesystem
   * is checked by e2fsck(8). If this is 0 then the
   * number of mounts is disregarded. This is the same as
   * the tune2fs "-c" option.
   * <p>
   * "mountcount"
   * Set the number of times the filesystem has been
   * mounted. This is the same as the tune2fs "-C"
   * option.
   * <p>
   * "errorbehavior"
   * Change the behavior of the kernel code when errors
   * are detected. Possible values currently are:
   * "continue", "remount-ro", "panic". In practice these
   * options don't really make any difference,
   * particularly for write errors.
   * <p>
   * This is the same as the tune2fs "-e" option.
   * <p>
   * "group"
   * Set the group which can use reserved filesystem
   * blocks. This is the same as the tune2fs "-g" option
   * except that it can only be specified as a number.
   * <p>
   * "intervalbetweenchecks"
   * Adjust the maximal time between two filesystem
   * checks (in seconds). If the option is passed as 0
   * then time-dependent checking is disabled.
   * <p>
   * This is the same as the tune2fs "-i" option.
   * <p>
   * "reservedblockspercentage"
   * Set the percentage of the filesystem which may only
   * be allocated by privileged processes. This is the
   * same as the tune2fs "-m" option.
   * <p>
   * "lastmounteddirectory"
   * Set the last mounted directory. This is the same as
   * the tune2fs "-M" option.
   * <p>
   * "reservedblockscount" Set the number of reserved
   * filesystem blocks. This is the same as the tune2fs "-r"
   * option.
   * "user"
   * Set the user who can use the reserved filesystem
   * blocks. This is the same as the tune2fs "-u" option
   * except that it can only be specified as a number.
   * <p>
   * To get the current values of filesystem parameters, see
   * "g.tune2fs_l". For precise details of how tune2fs works,
   * see the tune2fs(8) man page.
   * <p>
   * Optional arguments are supplied in the final
   * Map<String,Object> parameter, which is a hash of the
   * argument name to its value (cast to Object). Pass an
   * empty Map or null for no optional arguments.
   * <p>
   * @throws LibGuestFSException
   */
  public void tune2fs (String device, Map<String, Object> optargs)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("tune2fs: handle is closed");

    /* Unpack optional args. */
    Object _optobj;
    long _optargs_bitmask = 0;
    boolean force = false;
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("force");
    if (_optobj != null) {
      force = ((Boolean) _optobj).booleanValue();
      _optargs_bitmask |= 1L;
    }
    int maxmountcount = 0;
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("maxmountcount");
    if (_optobj != null) {
      maxmountcount = ((Integer) _optobj).intValue();
      _optargs_bitmask |= 2L;
    }
    int mountcount = 0;
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("mountcount");
    if (_optobj != null) {
      mountcount = ((Integer) _optobj).intValue();
      _optargs_bitmask |= 4L;
    }
    String errorbehavior = "";
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("errorbehavior");
    if (_optobj != null) {
      errorbehavior = ((String) _optobj);
      _optargs_bitmask |= 8L;
    }
    long group = 0;
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("group");
    if (_optobj != null) {
      group = ((Long) _optobj).longValue();
      _optargs_bitmask |= 16L;
    }
    int intervalbetweenchecks = 0;
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("intervalbetweenchecks");
    if (_optobj != null) {
      intervalbetweenchecks = ((Integer) _optobj).intValue();
      _optargs_bitmask |= 32L;
    }
    int reservedblockspercentage = 0;
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("reservedblockspercentage");
    if (_optobj != null) {
      reservedblockspercentage = ((Integer) _optobj).intValue();
      _optargs_bitmask |= 64L;
    }
    String lastmounteddirectory = "";
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("lastmounteddirectory");
    if (_optobj != null) {
      lastmounteddirectory = ((String) _optobj);
      _optargs_bitmask |= 128L;
    }
    long reservedblockscount = 0;
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("reservedblockscount");
    if (_optobj != null) {
      reservedblockscount = ((Long) _optobj).longValue();
      _optargs_bitmask |= 256L;
    }
    long user = 0;
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("user");
    if (_optobj != null) {
      user = ((Long) _optobj).longValue();
      _optargs_bitmask |= 512L;
    }

    _tune2fs (g, device, _optargs_bitmask, force, maxmountcount, mountcount, errorbehavior, group, intervalbetweenchecks, reservedblockspercentage, lastmounteddirectory, reservedblockscount, user);
  }

  public void tune2fs (String device)
    throws LibGuestFSException
  {
    tune2fs (device, null);
  }

  private native void _tune2fs (long g, String device, long _optargs_bitmask, boolean force, int maxmountcount, int mountcount, String errorbehavior, long group, int intervalbetweenchecks, int reservedblockspercentage, String lastmounteddirectory, long reservedblockscount, long user)
    throws LibGuestFSException;

  /**
   * create a Linux md (RAID) device
   * <p>
   * Create a Linux md (RAID) device named "name" on the
   * devices in the list "devices".
   * <p>
   * The optional parameters are:
   * <p>
   * "missingbitmap"
   * A bitmap of missing devices. If a bit is set it
   * means that a missing device is added to the array.
   * The least significant bit corresponds to the first
   * device in the array.
   * <p>
   * As examples:
   * <p>
   * If "devices = ["/dev/sda"]" and "missingbitmap =
   * 0x1" then the resulting array would be "[<missing>,
   * "/dev/sda"]".
   * <p>
   * If "devices = ["/dev/sda"]" and "missingbitmap =
   * 0x2" then the resulting array would be "["/dev/sda",
   * <missing>]".
   * <p>
   * This defaults to 0 (no missing devices).
   * <p>
   * The length of "devices" + the number of bits set in
   * "missingbitmap" must equal "nrdevices" + "spare".
   * <p>
   * "nrdevices"
   * The number of active RAID devices.
   * <p>
   * If not set, this defaults to the length of "devices"
   * plus the number of bits set in "missingbitmap".
   * <p>
   * "spare"
   * The number of spare devices.
   * <p>
   * If not set, this defaults to 0.
   * <p>
   * "chunk"
   * The chunk size in bytes.
   * <p>
   * "level"
   * The RAID level, which can be one of: *linear*,
   * *raid0*, *0*, *stripe*, *raid1*, *1*, *mirror*,
   * *raid4*, *4*, *raid5*, *5*, *raid6*, *6*, *raid10*,
   * *10*. Some of these are synonymous, and more levels
   * may be added in future.
   * <p>
   * If not set, this defaults to "raid1".
   * <p>
   * Optional arguments are supplied in the final
   * Map<String,Object> parameter, which is a hash of the
   * argument name to its value (cast to Object). Pass an
   * empty Map or null for no optional arguments.
   * <p>
   * @throws LibGuestFSException
   */
  public void md_create (String name, String[] devices, Map<String, Object> optargs)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("md_create: handle is closed");

    /* Unpack optional args. */
    Object _optobj;
    long _optargs_bitmask = 0;
    long missingbitmap = 0;
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("missingbitmap");
    if (_optobj != null) {
      missingbitmap = ((Long) _optobj).longValue();
      _optargs_bitmask |= 1L;
    }
    int nrdevices = 0;
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("nrdevices");
    if (_optobj != null) {
      nrdevices = ((Integer) _optobj).intValue();
      _optargs_bitmask |= 2L;
    }
    int spare = 0;
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("spare");
    if (_optobj != null) {
      spare = ((Integer) _optobj).intValue();
      _optargs_bitmask |= 4L;
    }
    long chunk = 0;
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("chunk");
    if (_optobj != null) {
      chunk = ((Long) _optobj).longValue();
      _optargs_bitmask |= 8L;
    }
    String level = "";
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("level");
    if (_optobj != null) {
      level = ((String) _optobj);
      _optargs_bitmask |= 16L;
    }

    _md_create (g, name, devices, _optargs_bitmask, missingbitmap, nrdevices, spare, chunk, level);
  }

  public void md_create (String name, String[] devices)
    throws LibGuestFSException
  {
    md_create (name, devices, null);
  }

  private native void _md_create (long g, String name, String[] devices, long _optargs_bitmask, long missingbitmap, int nrdevices, int spare, long chunk, String level)
    throws LibGuestFSException;

  /**
   * list Linux md (RAID) devices
   * <p>
   * List all Linux md devices.
   * <p>
   * @throws LibGuestFSException
   */
  public String[] list_md_devices ()
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("list_md_devices: handle is closed");

    return _list_md_devices (g);
  }

  private native String[] _list_md_devices (long g)
    throws LibGuestFSException;

  /**
   * obtain metadata for an MD device
   * <p>
   * This command exposes the output of 'mdadm -DY <md>'. The
   * following fields are usually present in the returned
   * hash. Other fields may also be present.
   * <p>
   * "level"
   * The raid level of the MD device.
   * <p>
   * "devices"
   * The number of underlying devices in the MD device.
   * <p>
   * "metadata"
   * The metadata version used.
   * <p>
   * "uuid"
   * The UUID of the MD device.
   * <p>
   * "name"
   * The name of the MD device.
   * <p>
   * @throws LibGuestFSException
   */
  public Map<String,String> md_detail (String md)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("md_detail: handle is closed");

    String[] r = _md_detail (g, md);

    HashMap<String, String> rhash = new HashMap<String, String> ();
    for (int i = 0; i < r.length; i += 2)
      rhash.put (r[i], r[i+1]);
    return rhash;
  }

  private native String[] _md_detail (long g, String md)
    throws LibGuestFSException;

  /**
   * stop a Linux md (RAID) device
   * <p>
   * This command deactivates the MD array named "md". The
   * device is stopped, but it is not destroyed or zeroed.
   * <p>
   * @throws LibGuestFSException
   */
  public void md_stop (String md)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("md_stop: handle is closed");

    _md_stop (g, md);
  }

  private native void _md_stop (long g, String md)
    throws LibGuestFSException;

  /**
   * print block device attributes
   * <p>
   * This command returns block device attributes for
   * "device". The following fields are usually present in
   * the returned hash. Other fields may also be present.
   * <p>
   * "UUID"
   * The uuid of this device.
   * <p>
   * "LABEL"
   * The label of this device.
   * <p>
   * "VERSION"
   * The version of blkid command.
   * <p>
   * "TYPE"
   * The filesystem type or RAID of this device.
   * <p>
   * "USAGE"
   * The usage of this device, for example "filesystem"
   * or "raid".
   * <p>
   * @throws LibGuestFSException
   */
  public Map<String,String> blkid (String device)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("blkid: handle is closed");

    String[] r = _blkid (g, device);

    HashMap<String, String> rhash = new HashMap<String, String> ();
    for (int i = 0; i < r.length; i += 2)
      rhash.put (r[i], r[i+1]);
    return rhash;
  }

  private native String[] _blkid (long g, String device)
    throws LibGuestFSException;

  /**
   * check an ext2/ext3 filesystem
   * <p>
   * This runs the ext2/ext3 filesystem checker on "device".
   * It can take the following optional arguments:
   * <p>
   * "correct"
   * Automatically repair the file system. This option
   * will cause e2fsck to automatically fix any
   * filesystem problems that can be safely fixed without
   * human intervention.
   * <p>
   * This option may not be specified at the same time as
   * the "forceall" option.
   * <p>
   * "forceall"
   * Assume an answer of 'yes' to all questions; allows
   * e2fsck to be used non-interactively.
   * <p>
   * This option may not be specified at the same time as
   * the "correct" option.
   * <p>
   * Optional arguments are supplied in the final
   * Map<String,Object> parameter, which is a hash of the
   * argument name to its value (cast to Object). Pass an
   * empty Map or null for no optional arguments.
   * <p>
   * @throws LibGuestFSException
   */
  public void e2fsck (String device, Map<String, Object> optargs)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("e2fsck: handle is closed");

    /* Unpack optional args. */
    Object _optobj;
    long _optargs_bitmask = 0;
    boolean correct = false;
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("correct");
    if (_optobj != null) {
      correct = ((Boolean) _optobj).booleanValue();
      _optargs_bitmask |= 1L;
    }
    boolean forceall = false;
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("forceall");
    if (_optobj != null) {
      forceall = ((Boolean) _optobj).booleanValue();
      _optargs_bitmask |= 2L;
    }

    _e2fsck (g, device, _optargs_bitmask, correct, forceall);
  }

  public void e2fsck (String device)
    throws LibGuestFSException
  {
    e2fsck (device, null);
  }

  private native void _e2fsck (long g, String device, long _optargs_bitmask, boolean correct, boolean forceall)
    throws LibGuestFSException;

  /**
   * list the files in a directory (long format with SELinux contexts)
   * <p>
   * List the files in "directory" in the format of 'ls
   * -laZ'.
   * <p>
   * This command is mostly useful for interactive sessions.
   * It is *not* intended that you try to parse the output
   * string.
   * <p>
   * @throws LibGuestFSException
   */
  public String llz (String directory)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("llz: handle is closed");

    return _llz (g, directory);
  }

  private native String _llz (long g, String directory)
    throws LibGuestFSException;

  /**
   * wipe a filesystem signature from a device
   * <p>
   * This command erases filesystem or RAID signatures from
   * the specified "device" to make the filesystem invisible
   * to libblkid.
   * <p>
   * This does not erase the filesystem itself nor any other
   * data from the "device".
   * <p>
   * Compare with "g.zero" which zeroes the first few blocks
   * of a device.
   * <p>
   * @throws LibGuestFSException
   */
  public void wipefs (String device)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("wipefs: handle is closed");

    _wipefs (g, device);
  }

  private native void _wipefs (long g, String device)
    throws LibGuestFSException;

  /**
   * fix common errors and force Windows to check NTFS
   * <p>
   * This command repairs some fundamental NTFS
   * inconsistencies, resets the NTFS journal file, and
   * schedules an NTFS consistency check for the first boot
   * into Windows.
   * <p>
   * This is *not* an equivalent of Windows "chkdsk". It does
   * *not* scan the filesystem for inconsistencies.
   * <p>
   * The optional "clearbadsectors" flag clears the list of
   * bad sectors. This is useful after cloning a disk with
   * bad sectors to a new disk.
   * <p>
   * Optional arguments are supplied in the final
   * Map<String,Object> parameter, which is a hash of the
   * argument name to its value (cast to Object). Pass an
   * empty Map or null for no optional arguments.
   * <p>
   * @throws LibGuestFSException
   */
  public void ntfsfix (String device, Map<String, Object> optargs)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("ntfsfix: handle is closed");

    /* Unpack optional args. */
    Object _optobj;
    long _optargs_bitmask = 0;
    boolean clearbadsectors = false;
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("clearbadsectors");
    if (_optobj != null) {
      clearbadsectors = ((Boolean) _optobj).booleanValue();
      _optargs_bitmask |= 1L;
    }

    _ntfsfix (g, device, _optargs_bitmask, clearbadsectors);
  }

  public void ntfsfix (String device)
    throws LibGuestFSException
  {
    ntfsfix (device, null);
  }

  private native void _ntfsfix (long g, String device, long _optargs_bitmask, boolean clearbadsectors)
    throws LibGuestFSException;

  /**
   * save NTFS to backup file
   * <p>
   * Stream the NTFS filesystem "device" to the local file
   * "backupfile". The format used for the backup file is a
   * special format used by the ntfsclone(8) tool.
   * <p>
   * If the optional "metadataonly" flag is true, then *only*
   * the metadata is saved, losing all the user data (this is
   * useful for diagnosing some filesystem problems).
   * <p>
   * The optional "rescue", "ignorefscheck",
   * "preservetimestamps" and "force" flags have precise
   * meanings detailed in the ntfsclone(8) man page.
   * <p>
   * Use "g.ntfsclone_in" to restore the file back to a
   * libguestfs device.
   * <p>
   * Optional arguments are supplied in the final
   * Map<String,Object> parameter, which is a hash of the
   * argument name to its value (cast to Object). Pass an
   * empty Map or null for no optional arguments.
   * <p>
   * @throws LibGuestFSException
   */
  public void ntfsclone_out (String device, String backupfile, Map<String, Object> optargs)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("ntfsclone_out: handle is closed");

    /* Unpack optional args. */
    Object _optobj;
    long _optargs_bitmask = 0;
    boolean metadataonly = false;
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("metadataonly");
    if (_optobj != null) {
      metadataonly = ((Boolean) _optobj).booleanValue();
      _optargs_bitmask |= 1L;
    }
    boolean rescue = false;
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("rescue");
    if (_optobj != null) {
      rescue = ((Boolean) _optobj).booleanValue();
      _optargs_bitmask |= 2L;
    }
    boolean ignorefscheck = false;
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("ignorefscheck");
    if (_optobj != null) {
      ignorefscheck = ((Boolean) _optobj).booleanValue();
      _optargs_bitmask |= 4L;
    }
    boolean preservetimestamps = false;
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("preservetimestamps");
    if (_optobj != null) {
      preservetimestamps = ((Boolean) _optobj).booleanValue();
      _optargs_bitmask |= 8L;
    }
    boolean force = false;
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("force");
    if (_optobj != null) {
      force = ((Boolean) _optobj).booleanValue();
      _optargs_bitmask |= 16L;
    }

    _ntfsclone_out (g, device, backupfile, _optargs_bitmask, metadataonly, rescue, ignorefscheck, preservetimestamps, force);
  }

  public void ntfsclone_out (String device, String backupfile)
    throws LibGuestFSException
  {
    ntfsclone_out (device, backupfile, null);
  }

  private native void _ntfsclone_out (long g, String device, String backupfile, long _optargs_bitmask, boolean metadataonly, boolean rescue, boolean ignorefscheck, boolean preservetimestamps, boolean force)
    throws LibGuestFSException;

  /**
   * restore NTFS from backup file
   * <p>
   * Restore the "backupfile" (from a previous call to
   * "g.ntfsclone_out") to "device", overwriting any existing
   * contents of this device.
   * <p>
   * @throws LibGuestFSException
   */
  public void ntfsclone_in (String backupfile, String device)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("ntfsclone_in: handle is closed");

    _ntfsclone_in (g, backupfile, device);
  }

  private native void _ntfsclone_in (long g, String backupfile, String device)
    throws LibGuestFSException;

  /**
   * set filesystem label
   * <p>
   * Set the filesystem label on "device" to "label".
   * <p>
   * Only some filesystem types support labels, and
   * libguestfs supports setting labels on only a subset of
   * these.
   * <p>
   * On ext2/3/4 filesystems, labels are limited to 16 bytes.
   * <p>
   * On NTFS filesystems, labels are limited to 128 unicode
   * characters.
   * <p>
   * To read the label on a filesystem, call "g.vfs_label".
   * <p>
   * @throws LibGuestFSException
   */
  public void set_label (String device, String label)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("set_label: handle is closed");

    _set_label (g, device, label);
  }

  private native void _set_label (long g, String device, String label)
    throws LibGuestFSException;

  /**
   * zero free space in a filesystem
   * <p>
   * Zero the free space in the filesystem mounted on
   * "directory". The filesystem must be mounted read-write.
   * <p>
   * The filesystem contents are not affected, but any free
   * space in the filesystem is freed.
   * <p>
   * In future (but not currently) these zeroed blocks will
   * be "sparsified" - that is, given back to the host.
   * <p>
   * @throws LibGuestFSException
   */
  public void zero_free_space (String directory)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("zero_free_space: handle is closed");

    _zero_free_space (g, directory);
  }

  private native void _zero_free_space (long g, String directory)
    throws LibGuestFSException;

  /**
   * create an LVM logical volume in % remaining free space
   * <p>
   * Create an LVM logical volume called
   * "/dev/volgroup/logvol", using approximately "percent" %
   * of the free space remaining in the volume group. Most
   * usefully, when "percent" is 100 this will create the
   * largest possible LV.
   * <p>
   * @throws LibGuestFSException
   */
  public void lvcreate_free (String logvol, String volgroup, int percent)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("lvcreate_free: handle is closed");

    _lvcreate_free (g, logvol, volgroup, percent);
  }

  private native void _lvcreate_free (long g, String logvol, String volgroup, int percent)
    throws LibGuestFSException;

  /**
   * get ISO information from primary volume descriptor of device
   * <p>
   * "device" is an ISO device. This returns a struct of
   * information read from the primary volume descriptor (the
   * ISO equivalent of the superblock) of the device.
   * <p>
   * Usually it is more efficient to use the isoinfo(1)
   * command with the *-d* option on the host to analyze ISO
   * files, instead of going through libguestfs.
   * <p>
   * For information on the primary volume descriptor fields,
   * see
   * <http://wiki.osdev.org/ISO_9660#The_Primary_Volume_Descr
   * iptor>
   * <p>
   * @throws LibGuestFSException
   */
  public ISOInfo isoinfo_device (String device)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("isoinfo_device: handle is closed");

    return _isoinfo_device (g, device);
  }

  private native ISOInfo _isoinfo_device (long g, String device)
    throws LibGuestFSException;

  /**
   * get ISO information from primary volume descriptor of ISO file
   * <p>
   * This is the same as "g.isoinfo_device" except that it
   * works for an ISO file located inside some other mounted
   * filesystem. Note that in the common case where you have
   * added an ISO file as a libguestfs device, you would
   * *not* call this. Instead you would call
   * "g.isoinfo_device".
   * <p>
   * @throws LibGuestFSException
   */
  public ISOInfo isoinfo (String isofile)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("isoinfo: handle is closed");

    return _isoinfo (g, isofile);
  }

  private native ISOInfo _isoinfo (long g, String isofile)
    throws LibGuestFSException;

  /**
   * get volume group metadata
   * <p>
   * "vgname" is an LVM volume group. This command examines
   * the volume group and returns its metadata.
   * <p>
   * Note that the metadata is an internal structure used by
   * LVM, subject to change at any time, and is provided for
   * information only.
   * <p>
   * @throws LibGuestFSException
   */
  public String vgmeta (String vgname)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("vgmeta: handle is closed");

    return _vgmeta (g, vgname);
  }

  private native String _vgmeta (long g, String vgname)
    throws LibGuestFSException;

  /**
   * get underlying devices from an MD device
   * <p>
   * This call returns a list of the underlying devices which
   * make up the single software RAID array device "md".
   * <p>
   * To get a list of software RAID devices, call
   * "g.list_md_devices".
   * <p>
   * Each structure returned corresponds to one device along
   * with additional status information:
   * <p>
   * "mdstat_device"
   * The name of the underlying device.
   * <p>
   * "mdstat_index"
   * The index of this device within the array.
   * <p>
   * "mdstat_flags"
   * Flags associated with this device. This is a string
   * containing (in no specific order) zero or more of
   * the following flags:
   * <p>
   * "W" write-mostly
   * <p>
   * "F" device is faulty
   * <p>
   * "S" device is a RAID spare
   * <p>
   * "R" replacement
   * <p>
   * @throws LibGuestFSException
   */
  public MDStat[] md_stat (String md)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("md_stat: handle is closed");

    return _md_stat (g, md);
  }

  private native MDStat[] _md_stat (long g, String md)
    throws LibGuestFSException;

  /**
   * create a btrfs filesystem
   * <p>
   * Create a btrfs filesystem, allowing all configurables to
   * be set. For more information on the optional arguments,
   * see mkfs.btrfs(8).
   * <p>
   * Since btrfs filesystems can span multiple devices, this
   * takes a non-empty list of devices.
   * <p>
   * To create general filesystems, use "g.mkfs_opts".
   * <p>
   * Optional arguments are supplied in the final
   * Map<String,Object> parameter, which is a hash of the
   * argument name to its value (cast to Object). Pass an
   * empty Map or null for no optional arguments.
   * <p>
   * @throws LibGuestFSException
   */
  public void mkfs_btrfs (String[] devices, Map<String, Object> optargs)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("mkfs_btrfs: handle is closed");

    /* Unpack optional args. */
    Object _optobj;
    long _optargs_bitmask = 0;
    long allocstart = 0;
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("allocstart");
    if (_optobj != null) {
      allocstart = ((Long) _optobj).longValue();
      _optargs_bitmask |= 1L;
    }
    long bytecount = 0;
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("bytecount");
    if (_optobj != null) {
      bytecount = ((Long) _optobj).longValue();
      _optargs_bitmask |= 2L;
    }
    String datatype = "";
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("datatype");
    if (_optobj != null) {
      datatype = ((String) _optobj);
      _optargs_bitmask |= 4L;
    }
    int leafsize = 0;
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("leafsize");
    if (_optobj != null) {
      leafsize = ((Integer) _optobj).intValue();
      _optargs_bitmask |= 8L;
    }
    String label = "";
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("label");
    if (_optobj != null) {
      label = ((String) _optobj);
      _optargs_bitmask |= 16L;
    }
    String metadata = "";
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("metadata");
    if (_optobj != null) {
      metadata = ((String) _optobj);
      _optargs_bitmask |= 32L;
    }
    int nodesize = 0;
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("nodesize");
    if (_optobj != null) {
      nodesize = ((Integer) _optobj).intValue();
      _optargs_bitmask |= 64L;
    }
    int sectorsize = 0;
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("sectorsize");
    if (_optobj != null) {
      sectorsize = ((Integer) _optobj).intValue();
      _optargs_bitmask |= 128L;
    }

    _mkfs_btrfs (g, devices, _optargs_bitmask, allocstart, bytecount, datatype, leafsize, label, metadata, nodesize, sectorsize);
  }

  public void mkfs_btrfs (String[] devices)
    throws LibGuestFSException
  {
    mkfs_btrfs (devices, null);
  }

  private native void _mkfs_btrfs (long g, String[] devices, long _optargs_bitmask, long allocstart, long bytecount, String datatype, int leafsize, String label, String metadata, int nodesize, int sectorsize)
    throws LibGuestFSException;

  /**
   * get ext2 file attributes of a file
   * <p>
   * This returns the file attributes associated with "file".
   * <p>
   * The attributes are a set of bits associated with each
   * inode which affect the behaviour of the file. The
   * attributes are returned as a string of letters
   * (described below). The string may be empty, indicating
   * that no file attributes are set for this file.
   * <p>
   * These attributes are only present when the file is
   * located on an ext2/3/4 filesystem. Using this call on
   * other filesystem types will result in an error.
   * <p>
   * The characters (file attributes) in the returned string
   * are currently:
   * <p>
   * 'A' When the file is accessed, its atime is not
   * modified.
   * <p>
   * 'a' The file is append-only.
   * <p>
   * 'c' The file is compressed on-disk.
   * <p>
   * 'D' (Directories only.) Changes to this directory are
   * written synchronously to disk.
   * <p>
   * 'd' The file is not a candidate for backup (see
   * dump(8)).
   * <p>
   * 'E' The file has compression errors.
   * <p>
   * 'e' The file is using extents.
   * <p>
   * 'h' The file is storing its blocks in units of the
   * filesystem blocksize instead of sectors.
   * <p>
   * 'I' (Directories only.) The directory is using hashed
   * trees.
   * <p>
   * 'i' The file is immutable. It cannot be modified,
   * deleted or renamed. No link can be created to this
   * file.
   * <p>
   * 'j' The file is data-journaled.
   * <p>
   * 's' When the file is deleted, all its blocks will be
   * zeroed.
   * <p>
   * 'S' Changes to this file are written synchronously to
   * disk.
   * <p>
   * 'T' (Directories only.) This is a hint to the block
   * allocator that subdirectories contained in this
   * directory should be spread across blocks. If not
   * present, the block allocator will try to group
   * subdirectories together.
   * <p>
   * 't' For a file, this disables tail-merging. (Not used by
   * upstream implementations of ext2.)
   * <p>
   * 'u' When the file is deleted, its blocks will be saved,
   * allowing the file to be undeleted.
   * <p>
   * 'X' The raw contents of the compressed file may be
   * accessed.
   * <p>
   * 'Z' The compressed file is dirty.
   * <p>
   * More file attributes may be added to this list later.
   * Not all file attributes may be set for all kinds of
   * files. For detailed information, consult the chattr(1)
   * man page.
   * <p>
   * See also "g.set_e2attrs".
   * <p>
   * Don't confuse these attributes with extended attributes
   * (see "g.getxattr").
   * <p>
   * @throws LibGuestFSException
   */
  public String get_e2attrs (String file)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("get_e2attrs: handle is closed");

    return _get_e2attrs (g, file);
  }

  private native String _get_e2attrs (long g, String file)
    throws LibGuestFSException;

  /**
   * set ext2 file attributes of a file
   * <p>
   * This sets or clears the file attributes "attrs"
   * associated with the inode "file".
   * <p>
   * "attrs" is a string of characters representing file
   * attributes. See "g.get_e2attrs" for a list of possible
   * attributes. Not all attributes can be changed.
   * <p>
   * If optional boolean "clear" is not present or false,
   * then the "attrs" listed are set in the inode.
   * <p>
   * If "clear" is true, then the "attrs" listed are cleared
   * in the inode.
   * <p>
   * In both cases, other attributes not present in the
   * "attrs" string are left unchanged.
   * <p>
   * These attributes are only present when the file is
   * located on an ext2/3/4 filesystem. Using this call on
   * other filesystem types will result in an error.
   * <p>
   * Optional arguments are supplied in the final
   * Map<String,Object> parameter, which is a hash of the
   * argument name to its value (cast to Object). Pass an
   * empty Map or null for no optional arguments.
   * <p>
   * @throws LibGuestFSException
   */
  public void set_e2attrs (String file, String attrs, Map<String, Object> optargs)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("set_e2attrs: handle is closed");

    /* Unpack optional args. */
    Object _optobj;
    long _optargs_bitmask = 0;
    boolean clear = false;
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("clear");
    if (_optobj != null) {
      clear = ((Boolean) _optobj).booleanValue();
      _optargs_bitmask |= 1L;
    }

    _set_e2attrs (g, file, attrs, _optargs_bitmask, clear);
  }

  public void set_e2attrs (String file, String attrs)
    throws LibGuestFSException
  {
    set_e2attrs (file, attrs, null);
  }

  private native void _set_e2attrs (long g, String file, String attrs, long _optargs_bitmask, boolean clear)
    throws LibGuestFSException;

  /**
   * get ext2 file generation of a file
   * <p>
   * This returns the ext2 file generation of a file. The
   * generation (which used to be called the "version") is a
   * number associated with an inode. This is most commonly
   * used by NFS servers.
   * <p>
   * The generation is only present when the file is located
   * on an ext2/3/4 filesystem. Using this call on other
   * filesystem types will result in an error.
   * <p>
   * See "g.set_e2generation".
   * <p>
   * @throws LibGuestFSException
   */
  public long get_e2generation (String file)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("get_e2generation: handle is closed");

    return _get_e2generation (g, file);
  }

  private native long _get_e2generation (long g, String file)
    throws LibGuestFSException;

  /**
   * set ext2 file generation of a file
   * <p>
   * This sets the ext2 file generation of a file.
   * <p>
   * See "g.get_e2generation".
   * <p>
   * @throws LibGuestFSException
   */
  public void set_e2generation (String file, long generation)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("set_e2generation: handle is closed");

    _set_e2generation (g, file, generation);
  }

  private native void _set_e2generation (long g, String file, long generation)
    throws LibGuestFSException;

  /**
   * create a writable btrfs snapshot
   * <p>
   * Create a writable snapshot of the btrfs subvolume
   * "source". The "dest" argument is the destination
   * directory and the name of the snapshot, in the form
   * "/path/to/dest/name".
   * <p>
   * @throws LibGuestFSException
   */
  public void btrfs_subvolume_snapshot (String source, String dest)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("btrfs_subvolume_snapshot: handle is closed");

    _btrfs_subvolume_snapshot (g, source, dest);
  }

  private native void _btrfs_subvolume_snapshot (long g, String source, String dest)
    throws LibGuestFSException;

  /**
   * delete a btrfs snapshot
   * <p>
   * Delete the named btrfs subvolume.
   * <p>
   * @throws LibGuestFSException
   */
  public void btrfs_subvolume_delete (String subvolume)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("btrfs_subvolume_delete: handle is closed");

    _btrfs_subvolume_delete (g, subvolume);
  }

  private native void _btrfs_subvolume_delete (long g, String subvolume)
    throws LibGuestFSException;

  /**
   * create a btrfs snapshot
   * <p>
   * Create a btrfs subvolume. The "dest" argument is the
   * destination directory and the name of the snapshot, in
   * the form "/path/to/dest/name".
   * <p>
   * @throws LibGuestFSException
   */
  public void btrfs_subvolume_create (String dest)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("btrfs_subvolume_create: handle is closed");

    _btrfs_subvolume_create (g, dest);
  }

  private native void _btrfs_subvolume_create (long g, String dest)
    throws LibGuestFSException;

  /**
   * list btrfs snapshots and subvolumes
   * <p>
   * List the btrfs snapshots and subvolumes of the btrfs
   * filesystem which is mounted at "fs".
   * <p>
   * @throws LibGuestFSException
   */
  public BTRFSSubvolume[] btrfs_subvolume_list (String fs)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("btrfs_subvolume_list: handle is closed");

    return _btrfs_subvolume_list (g, fs);
  }

  private native BTRFSSubvolume[] _btrfs_subvolume_list (long g, String fs)
    throws LibGuestFSException;

  /**
   * set default btrfs subvolume
   * <p>
   * Set the subvolume of the btrfs filesystem "fs" which
   * will be mounted by default. See "g.btrfs_subvolume_list"
   * to get a list of subvolumes.
   * <p>
   * @throws LibGuestFSException
   */
  public void btrfs_subvolume_set_default (long id, String fs)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("btrfs_subvolume_set_default: handle is closed");

    _btrfs_subvolume_set_default (g, id, fs);
  }

  private native void _btrfs_subvolume_set_default (long g, long id, String fs)
    throws LibGuestFSException;

  /**
   * sync a btrfs filesystem
   * <p>
   * Force sync on the btrfs filesystem mounted at "fs".
   * <p>
   * @throws LibGuestFSException
   */
  public void btrfs_filesystem_sync (String fs)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("btrfs_filesystem_sync: handle is closed");

    _btrfs_filesystem_sync (g, fs);
  }

  private native void _btrfs_filesystem_sync (long g, String fs)
    throws LibGuestFSException;

  /**
   * balance a btrfs filesystem
   * <p>
   * Balance the chunks in the btrfs filesystem mounted at
   * "fs" across the underlying devices.
   * <p>
   * @throws LibGuestFSException
   */
  public void btrfs_filesystem_balance (String fs)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("btrfs_filesystem_balance: handle is closed");

    _btrfs_filesystem_balance (g, fs);
  }

  private native void _btrfs_filesystem_balance (long g, String fs)
    throws LibGuestFSException;

  /**
   * add devices to a btrfs filesystem
   * <p>
   * Add the list of device(s) in "devices" to the btrfs
   * filesystem mounted at "fs". If "devices" is an empty
   * list, this does nothing.
   * <p>
   * @throws LibGuestFSException
   */
  public void btrfs_device_add (String[] devices, String fs)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("btrfs_device_add: handle is closed");

    _btrfs_device_add (g, devices, fs);
  }

  private native void _btrfs_device_add (long g, String[] devices, String fs)
    throws LibGuestFSException;

  /**
   * remove devices from a btrfs filesystem
   * <p>
   * Remove the "devices" from the btrfs filesystem mounted
   * at "fs". If "devices" is an empty list, this does
   * nothing.
   * <p>
   * @throws LibGuestFSException
   */
  public void btrfs_device_delete (String[] devices, String fs)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("btrfs_device_delete: handle is closed");

    _btrfs_device_delete (g, devices, fs);
  }

  private native void _btrfs_device_delete (long g, String[] devices, String fs)
    throws LibGuestFSException;

  /**
   * enable or disable the seeding feature of device
   * <p>
   * Enable or disable the seeding feature of a device that
   * contains a btrfs filesystem.
   * <p>
   * @throws LibGuestFSException
   */
  public void btrfs_set_seeding (String device, boolean seeding)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("btrfs_set_seeding: handle is closed");

    _btrfs_set_seeding (g, device, seeding);
  }

  private native void _btrfs_set_seeding (long g, String device, boolean seeding)
    throws LibGuestFSException;

  /**
   * check a btrfs filesystem
   * <p>
   * Used to check a btrfs filesystem, "device" is the device
   * file where the filesystem is stored.
   * <p>
   * Optional arguments are supplied in the final
   * Map<String,Object> parameter, which is a hash of the
   * argument name to its value (cast to Object). Pass an
   * empty Map or null for no optional arguments.
   * <p>
   * @throws LibGuestFSException
   */
  public void btrfs_fsck (String device, Map<String, Object> optargs)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("btrfs_fsck: handle is closed");

    /* Unpack optional args. */
    Object _optobj;
    long _optargs_bitmask = 0;
    long superblock = 0;
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("superblock");
    if (_optobj != null) {
      superblock = ((Long) _optobj).longValue();
      _optargs_bitmask |= 1L;
    }
    boolean repair = false;
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("repair");
    if (_optobj != null) {
      repair = ((Boolean) _optobj).booleanValue();
      _optargs_bitmask |= 2L;
    }

    _btrfs_fsck (g, device, _optargs_bitmask, superblock, repair);
  }

  public void btrfs_fsck (String device)
    throws LibGuestFSException
  {
    btrfs_fsck (device, null);
  }

  private native void _btrfs_fsck (long g, String device, long _optargs_bitmask, long superblock, boolean repair)
    throws LibGuestFSException;

  /**
   * convert device to index
   * <p>
   * This function takes a device name (eg. "/dev/sdb") and
   * returns the index of the device in the list of devices.
   * <p>
   * Index numbers start from 0. The named device must exist,
   * for example as a string returned from "g.list_devices".
   * <p>
   * See also "g.list_devices", "g.part_to_dev".
   * <p>
   * @throws LibGuestFSException
   */
  public int device_index (String device)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("device_index: handle is closed");

    return _device_index (g, device);
  }

  private native int _device_index (long g, String device)
    throws LibGuestFSException;

  /**
   * return number of whole block devices (disks) added
   * <p>
   * This returns the number of whole block devices that were
   * added. This is the same as the number of devices that
   * would be returned if you called "g.list_devices".
   * <p>
   * To find out the maximum number of devices that could be
   * added, call "g.max_disks".
   * <p>
   * @throws LibGuestFSException
   */
  public int nr_devices ()
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("nr_devices: handle is closed");

    return _nr_devices (g);
  }

  private native int _nr_devices (long g)
    throws LibGuestFSException;

}
