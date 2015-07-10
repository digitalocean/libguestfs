/* libguestfs generated file
 * WARNING: THIS FILE IS GENERATED FROM:
 *   generator/ *.ml
 * ANY CHANGES YOU MAKE TO THIS FILE WILL BE LOST.
 *
 * Copyright (C) 2009-2015 Red Hat Inc.
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
 * <p>
 * Libguestfs handle.
 * </p><p>
 * The <code>GuestFS</code> object corresponds to a libguestfs handle.
 * </p><p>
 * Note that the main documentation for the libguestfs API is in
 * the following man pages:
 * </p>
 * <ol>
 * <li> <a href="http://libguestfs.org/guestfs-java.3.html"><code>guestfs-java(3)</code></a> and </li>
 * <li> <a href="http://libguestfs.org/guestfs.3.html"><code>guestfs(3)</code></a>. </li>
 * </ol>
 * <p>
 * This javadoc is <b>not</b> a good introduction to using libguestfs.
 * </p>
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

  /* guestfs_create_flags values defined in <guestfs.h> */
  private static int CREATE_NO_ENVIRONMENT   = 1;
  private static int CREATE_NO_CLOSE_ON_EXIT = 2;

  /**
   * Create a libguestfs handle, setting flags.
   *
   * @throws LibGuestFSException
   */
  public GuestFS (Map<String, Object> optargs) throws LibGuestFSException
  {
    int flags = 0;

    /* Unpack optional args. */
    Object _optobj;
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("environment");
    if (_optobj != null && !((Boolean) _optobj).booleanValue())
      flags |= CREATE_NO_ENVIRONMENT;
    if (optargs != null)
      _optobj = optargs.get ("close_on_exit");
    if (_optobj != null && !((Boolean) _optobj).booleanValue())
      flags |= CREATE_NO_CLOSE_ON_EXIT;

    g = _create (flags);
  }

  /**
   * Create a libguestfs handle.
   *
   * @throws LibGuestFSException
   */
  public GuestFS () throws LibGuestFSException
  {
    g = _create (0);
  }

  private native long _create (int flags) throws LibGuestFSException;

  /**
   * <p>
   * Close a libguestfs handle.
   * </p><p>
   * You can also leave handles to be collected by the garbage
   * collector, but this method ensures that the resources used
   * by the handle are freed up immediately.  If you call any
   * other methods after closing the handle, you will get an
   * exception.
   * </p>
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

  // Event bitmasks.

  /**
   * Event 'close'.
   *
   * @see #set_event_callback
   */
  public static final long EVENT_CLOSE = 0x1;

  /**
   * Event 'subprocess_quit'.
   *
   * @see #set_event_callback
   */
  public static final long EVENT_SUBPROCESS_QUIT = 0x2;

  /**
   * Event 'launch_done'.
   *
   * @see #set_event_callback
   */
  public static final long EVENT_LAUNCH_DONE = 0x4;

  /**
   * Event 'progress'.
   *
   * @see #set_event_callback
   */
  public static final long EVENT_PROGRESS = 0x8;

  /**
   * Event 'appliance'.
   *
   * @see #set_event_callback
   */
  public static final long EVENT_APPLIANCE = 0x10;

  /**
   * Event 'library'.
   *
   * @see #set_event_callback
   */
  public static final long EVENT_LIBRARY = 0x20;

  /**
   * Event 'trace'.
   *
   * @see #set_event_callback
   */
  public static final long EVENT_TRACE = 0x40;

  /**
   * Event 'enter'.
   *
   * @see #set_event_callback
   */
  public static final long EVENT_ENTER = 0x80;

  /**
   * Event 'libvirt_auth'.
   *
   * @see #set_event_callback
   */
  public static final long EVENT_LIBVIRT_AUTH = 0x100;

  /**
   * Event 'warning'.
   *
   * @see #set_event_callback
   */
  public static final long EVENT_WARNING = 0x200;

  /** Bitmask of all events. */
  public static final long EVENT_ALL = 0x3ff;

/**
   * Utility function to turn an event number or bitmask into a string.
   *
   * @param events the event number to convert
   * @return text representation of event
   */
  public static String eventToString (long events)
  {
    return _event_to_string (events);
  }

  private static native String _event_to_string (long events);

  /**
   * <p>
   * Set an event handler.
   * </p><p>
   * Set an event handler (<code>callback</code>) which is called when any
   * event from the set (<code>events</code>) is raised by the API.
   * <code>events</code> is one or more <code>EVENT_*</code> constants,
   * bitwise ORed together.
   * </p><p>
   * When an event happens, the callback object's <code>event</code> method
   * is invoked like this:
   * </p>
   * <pre>
   * callback.event (event,    // the specific event which fired (long)
   *                 eh,       // the event handle (int)
   *                 buffer,   // event data (String)
   *                 array     // event data (long[])
   *                 );
   * </pre>
   * <p>
   * Note that you can pass arbitrary data from the main program to the
   * callback by putting it into your {@link EventCallback callback object},
   * then accessing it in the callback via <code>this</code>.
   * </p><p>
   * This function returns an event handle which may be used to delete
   * the event.  Note that event handlers are deleted automatically when
   * the libguestfs handle is closed.
   * </p>
   *
   * @throws LibGuestFSException
   * @see "The section &quot;EVENTS&quot; in the guestfs(3) manual"
   * @see #delete_event_callback
   * @return handle for the event
   */
  public int set_event_callback (EventCallback callback, long events)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("set_event_callback: handle is closed");

    return _set_event_callback (g, callback, events);
  }

  private native int _set_event_callback (long g, EventCallback callback,
                                          long events)
    throws LibGuestFSException;

  /**
   * <p>
   * Delete an event handler.
   * </p><p>
   * Delete a previously registered event handler.  The 'eh' parameter is
   * the event handle returned from a previous call to
   * {@link #set_event_callback set_event_callback}.
   * </p><p>
   * Note that event handlers are deleted automatically when the
   * libguestfs handle is closed.
   * </p>
   *
   * @throws LibGuestFSException
   * @see #set_event_callback
   */
  public void delete_event_callback (int eh)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("delete_event_callback: handle is closed");

    _delete_event_callback (g, eh);
  }

  private native void _delete_event_callback (long g, int eh);

  /**
   * <p>
   * delete the default POSIX ACL of a directory
   * </p><p>
   * This function deletes the default POSIX Access Control
   * List (ACL) attached to directory "dir".
   * </p><p>
   * </p>
   * @since 1.19.63
   * @throws LibGuestFSException
   */
  public void acl_delete_def_file (String dir)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("acl_delete_def_file: handle is closed");

    _acl_delete_def_file (g, dir);
  }

  private native void _acl_delete_def_file (long g, String dir)
    throws LibGuestFSException;

  /**
   * <p>
   * get the POSIX ACL attached to a file
   * </p><p>
   * This function returns the POSIX Access Control List
   * (ACL) attached to "path". The ACL is returned in "long
   * text form" (see acl(5)).
   * </p><p>
   * The "acltype" parameter may be:
   * </p><p>
   * "access"
   * Return the ordinary (access) ACL for any file,
   * directory or other filesystem object.
   * </p><p>
   * "default"
   * Return the default ACL. Normally this only makes
   * sense if "path" is a directory.
   * </p><p>
   * </p>
   * @since 1.19.63
   * @throws LibGuestFSException
   */
  public String acl_get_file (String path, String acltype)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("acl_get_file: handle is closed");

    return _acl_get_file (g, path, acltype);
  }

  private native String _acl_get_file (long g, String path, String acltype)
    throws LibGuestFSException;

  /**
   * <p>
   * set the POSIX ACL attached to a file
   * </p><p>
   * This function sets the POSIX Access Control List (ACL)
   * attached to "path".
   * </p><p>
   * The "acltype" parameter may be:
   * </p><p>
   * "access"
   * Set the ordinary (access) ACL for any file,
   * directory or other filesystem object.
   * </p><p>
   * "default"
   * Set the default ACL. Normally this only makes sense
   * if "path" is a directory.
   * </p><p>
   * The "acl" parameter is the new ACL in either "long text
   * form" or "short text form" (see acl(5)). The new ACL
   * completely replaces any previous ACL on the file. The
   * ACL must contain the full Unix permissions (eg.
   * "u::rwx,g::rx,o::rx").
   * </p><p>
   * If you are specifying individual users or groups, then
   * the mask field is also required (eg. "m::rwx"), followed
   * by the "u:*ID*:..." and/or "g:*ID*:..." field(s). A full
   * ACL string might therefore look like this:
   * </p><p>
   * u::rwx,g::rwx,o::rwx,m::rwx,u:500:rwx,g:500:rwx
   * \ Unix permissions / \mask/ \      ACL        /
   * </p><p>
   * You should use numeric UIDs and GIDs. To map usernames
   * and groupnames to the correct numeric ID in the context
   * of the guest, use the Augeas functions (see
   * "g.aug_init").
   * </p><p>
   * </p>
   * @since 1.19.63
   * @throws LibGuestFSException
   */
  public void acl_set_file (String path, String acltype, String acl)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("acl_set_file: handle is closed");

    _acl_set_file (g, path, acltype, acl);
  }

  private native void _acl_set_file (long g, String path, String acltype, String acl)
    throws LibGuestFSException;

  /**
   * <p>
   * add a CD-ROM disk image to examine
   * </p><p>
   * This function adds a virtual CD-ROM disk image to the
   * guest.
   * </p><p>
   * The image is added as read-only drive, so this function
   * is equivalent of "g.add_drive_ro".
   * </p><p>
   * </p>
   * @since 0.3
   * @deprecated In new code, use {@link #add_drive_ro} instead
   * @throws LibGuestFSException
   */
  @Deprecated public void add_cdrom (String filename)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("add_cdrom: handle is closed");

    _add_cdrom (g, filename);
  }

  private native void _add_cdrom (long g, String filename)
    throws LibGuestFSException;

  /**
   * <p>
   * add the disk(s) from a named libvirt domain
   * </p><p>
   * This function adds the disk(s) attached to the named
   * libvirt domain "dom". It works by connecting to libvirt,
   * requesting the domain and domain XML from libvirt,
   * parsing it for disks, and calling "g.add_drive_opts" on
   * each one.
   * </p><p>
   * The number of disks added is returned. This operation is
   * atomic: if an error is returned, then no disks are
   * added.
   * </p><p>
   * This function does some minimal checks to make sure the
   * libvirt domain is not running (unless "readonly" is
   * true). In a future version we will try to acquire the
   * libvirt lock on each disk.
   * </p><p>
   * Disks must be accessible locally. This often means that
   * adding disks from a remote libvirt connection (see
   * &lt;http://libvirt.org/remote.html&gt;) will fail unless those
   * disks are accessible via the same device path locally
   * too.
   * </p><p>
   * The optional "libvirturi" parameter sets the libvirt URI
   * (see &lt;http://libvirt.org/uri.html&gt;). If this is not set
   * then we connect to the default libvirt URI (or one set
   * through an environment variable, see the libvirt
   * documentation for full details).
   * </p><p>
   * The optional "live" flag controls whether this call will
   * try to connect to a running virtual machine "guestfsd"
   * process if it sees a suitable &lt;channel&gt; element in the
   * libvirt XML definition. The default (if the flag is
   * omitted) is never to try. See "ATTACHING TO RUNNING
   * DAEMONS" in guestfs(3) for more information.
   * </p><p>
   * If the "allowuuid" flag is true (default is false) then
   * a UUID *may* be passed instead of the domain name. The
   * "dom" string is treated as a UUID first and looked up,
   * and if that lookup fails then we treat "dom" as a name
   * as usual.
   * </p><p>
   * The optional "readonlydisk" parameter controls what we
   * do for disks which are marked &lt;readonly/&gt; in the libvirt
   * XML. Possible values are:
   * </p><p>
   * readonlydisk = "error"
   * If "readonly" is false:
   * </p><p>
   * The whole call is aborted with an error if any disk
   * with the &lt;readonly/&gt; flag is found.
   * </p><p>
   * If "readonly" is true:
   * </p><p>
   * Disks with the &lt;readonly/&gt; flag are added read-only.
   * </p><p>
   * readonlydisk = "read"
   * If "readonly" is false:
   * </p><p>
   * Disks with the &lt;readonly/&gt; flag are added read-only.
   * Other disks are added read/write.
   * </p><p>
   * If "readonly" is true:
   * </p><p>
   * Disks with the &lt;readonly/&gt; flag are added read-only.
   * </p><p>
   * readonlydisk = "write" (default)
   * If "readonly" is false:
   * </p><p>
   * Disks with the &lt;readonly/&gt; flag are added
   * read/write.
   * </p><p>
   * If "readonly" is true:
   * </p><p>
   * Disks with the &lt;readonly/&gt; flag are added read-only.
   * </p><p>
   * readonlydisk = "ignore"
   * If "readonly" is true or false:
   * </p><p>
   * Disks with the &lt;readonly/&gt; flag are skipped.
   * </p><p>
   * The other optional parameters are passed directly
   * through to "g.add_drive_opts".
   * </p><p>
   * Optional arguments are supplied in the final
   * Map&lt;String,Object&gt; parameter, which is a hash of the
   * argument name to its value (cast to Object). Pass an
   * empty Map or null for no optional arguments.
   * </p><p>
   * </p>
   * @since 1.7.4
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
    String cachemode = "";
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("cachemode");
    if (_optobj != null) {
      cachemode = ((String) _optobj);
      _optargs_bitmask |= 64L;
    }
    String discard = "";
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("discard");
    if (_optobj != null) {
      discard = ((String) _optobj);
      _optargs_bitmask |= 128L;
    }
    boolean copyonread = false;
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("copyonread");
    if (_optobj != null) {
      copyonread = ((Boolean) _optobj).booleanValue();
      _optargs_bitmask |= 256L;
    }

    return _add_domain (g, dom, _optargs_bitmask, libvirturi, readonly, iface, live, allowuuid, readonlydisk, cachemode, discard, copyonread);
  }

  public int add_domain (String dom)
    throws LibGuestFSException
  {
    return add_domain (dom, null);
  }

  private native int _add_domain (long g, String dom, long _optargs_bitmask, String libvirturi, boolean readonly, String iface, boolean live, boolean allowuuid, String readonlydisk, String cachemode, String discard, boolean copyonread)
    throws LibGuestFSException;

  /**
   * <p>
   * add an image to examine or modify
   * </p><p>
   * This function adds a disk image called filename to the
   * handle. filename may be a regular host file or a host
   * device.
   * </p><p>
   * When this function is called before "g.launch" (the
   * usual case) then the first time you call this function,
   * the disk appears in the API as /dev/sda, the second time
   * as /dev/sdb, and so on.
   * </p><p>
   * In libguestfs ≥ 1.20 you can also call this function
   * after launch (with some restrictions). This is called
   * "hotplugging". When hotplugging, you must specify a
   * "label" so that the new disk gets a predictable name.
   * For more information see "HOTPLUGGING" in guestfs(3).
   * </p><p>
   * You don't necessarily need to be root when using
   * libguestfs. However you obviously do need sufficient
   * permissions to access the filename for whatever
   * operations you want to perform (ie. read access if you
   * just want to read the image or write access if you want
   * to modify the image).
   * </p><p>
   * This call checks that filename exists.
   * </p><p>
   * filename may be the special string "/dev/null". See
   * "NULL DISKS" in guestfs(3).
   * </p><p>
   * The optional arguments are:
   * </p><p>
   * "readonly"
   * If true then the image is treated as read-only.
   * Writes are still allowed, but they are stored in a
   * temporary snapshot overlay which is discarded at the
   * end. The disk that you add is not modified.
   * </p><p>
   * "format"
   * This forces the image format. If you omit this (or
   * use "g.add_drive" or "g.add_drive_ro") then the
   * format is automatically detected. Possible formats
   * include "raw" and "qcow2".
   * </p><p>
   * Automatic detection of the format opens you up to a
   * potential security hole when dealing with untrusted
   * raw-format images. See CVE-2010-3851 and
   * RHBZ#642934. Specifying the format closes this
   * security hole.
   * </p><p>
   * "iface"
   * This rarely-used option lets you emulate the
   * behaviour of the deprecated "g.add_drive_with_if"
   * call (q.v.)
   * </p><p>
   * "name"
   * The name the drive had in the original guest, e.g.
   * /dev/sdb. This is used as a hint to the guest
   * inspection process if it is available.
   * </p><p>
   * "label"
   * Give the disk a label. The label should be a unique,
   * short string using *only* ASCII characters
   * "[a-zA-Z]". As well as its usual name in the API
   * (such as /dev/sda), the drive will also be named
   * /dev/disk/guestfs/*label*.
   * </p><p>
   * See "DISK LABELS" in guestfs(3).
   * </p><p>
   * "protocol"
   * The optional protocol argument can be used to select
   * an alternate source protocol.
   * </p><p>
   * See also: "REMOTE STORAGE" in guestfs(3).
   * </p><p>
   * "protocol = "file""
   * filename is interpreted as a local file or
   * device. This is the default if the optional
   * protocol parameter is omitted.
   * </p><p>
   * "protocol = "ftp"|"ftps"|"http"|"https"|"tftp""
   * Connect to a remote FTP, HTTP or TFTP server.
   * The "server" parameter must also be supplied -
   * see below.
   * </p><p>
   * See also: "FTP, HTTP AND TFTP" in guestfs(3)
   * </p><p>
   * "protocol = "gluster""
   * Connect to the GlusterFS server. The "server"
   * parameter must also be supplied - see below.
   * </p><p>
   * See also: "GLUSTER" in guestfs(3)
   * </p><p>
   * "protocol = "iscsi""
   * Connect to the iSCSI server. The "server"
   * parameter must also be supplied - see below.
   * </p><p>
   * See also: "ISCSI" in guestfs(3).
   * </p><p>
   * "protocol = "nbd""
   * Connect to the Network Block Device server. The
   * "server" parameter must also be supplied - see
   * below.
   * </p><p>
   * See also: "NETWORK BLOCK DEVICE" in guestfs(3).
   * </p><p>
   * "protocol = "rbd""
   * Connect to the Ceph (librbd/RBD) server. The
   * "server" parameter must also be supplied - see
   * below. The "username" parameter may be supplied.
   * See below. The "secret" parameter may be
   * supplied. See below.
   * </p><p>
   * See also: "CEPH" in guestfs(3).
   * </p><p>
   * "protocol = "sheepdog""
   * Connect to the Sheepdog server. The "server"
   * parameter may also be supplied - see below.
   * </p><p>
   * See also: "SHEEPDOG" in guestfs(3).
   * </p><p>
   * "protocol = "ssh""
   * Connect to the Secure Shell (ssh) server.
   * </p><p>
   * The "server" parameter must be supplied. The
   * "username" parameter may be supplied. See below.
   * </p><p>
   * See also: "SSH" in guestfs(3).
   * </p><p>
   * "server"
   * For protocols which require access to a remote
   * server, this is a list of server(s).
   * </p><p>
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
   * </p><p>
   * Each list element is a string specifying a server.
   * The string must be in one of the following formats:
   * </p><p>
   * hostname
   * hostname:port
   * tcp:hostname
   * tcp:hostname:port
   * unix:/path/to/socket
   * </p><p>
   * If the port number is omitted, then the standard
   * port number for the protocol is used (see
   * /etc/services).
   * </p><p>
   * "username"
   * For the "ftp", "ftps", "http", "https", "iscsi",
   * "rbd", "ssh" and "tftp" protocols, this specifies
   * the remote username.
   * </p><p>
   * If not given, then the local username is used for
   * "ssh", and no authentication is attempted for ceph.
   * But note this sometimes may give unexpected results,
   * for example if using the libvirt backend and if the
   * libvirt backend is configured to start the qemu
   * appliance as a special user such as "qemu.qemu". If
   * in doubt, specify the remote username you want.
   * </p><p>
   * "secret"
   * For the "rbd" protocol only, this specifies the
   * 'secret' to use when connecting to the remote
   * device. It must be base64 encoded.
   * </p><p>
   * If not given, then a secret matching the given
   * username will be looked up in the default keychain
   * locations, or if no username is given, then no
   * authentication will be used.
   * </p><p>
   * "cachemode"
   * Choose whether or not libguestfs will obey sync
   * operations (safe but slow) or not (unsafe but fast).
   * The possible values for this string are:
   * </p><p>
   * "cachemode = "writeback""
   * This is the default.
   * </p><p>
   * Write operations in the API do not return until
   * a write(2) call has completed in the host [but
   * note this does not imply that anything gets
   * written to disk].
   * </p><p>
   * Sync operations in the API, including implicit
   * syncs caused by filesystem journalling, will not
   * return until an fdatasync(2) call has completed
   * in the host, indicating that data has been
   * committed to disk.
   * </p><p>
   * "cachemode = "unsafe""
   * In this mode, there are no guarantees.
   * Libguestfs may cache anything and ignore sync
   * requests. This is suitable only for scratch or
   * temporary disks.
   * </p><p>
   * "discard"
   * Enable or disable discard (a.k.a. trim or unmap)
   * support on this drive. If enabled, operations such
   * as "g.fstrim" will be able to discard / make thin /
   * punch holes in the underlying host file or device.
   * </p><p>
   * Possible discard settings are:
   * </p><p>
   * "discard = "disable""
   * Disable discard support. This is the default.
   * </p><p>
   * "discard = "enable""
   * Enable discard support. Fail if discard is not
   * possible.
   * </p><p>
   * "discard = "besteffort""
   * Enable discard support if possible, but don't
   * fail if it is not supported.
   * </p><p>
   * Since not all backends and not all underlying
   * systems support discard, this is a good choice
   * if you want to use discard if possible, but
   * don't mind if it doesn't work.
   * </p><p>
   * "copyonread"
   * The boolean parameter "copyonread" enables
   * copy-on-read support. This only affects disk formats
   * which have backing files, and causes reads to be
   * stored in the overlay layer, speeding up multiple
   * reads of the same area of disk.
   * </p><p>
   * The default is false.
   * </p><p>
   * Optional arguments are supplied in the final
   * Map&lt;String,Object&gt; parameter, which is a hash of the
   * argument name to its value (cast to Object). Pass an
   * empty Map or null for no optional arguments.
   * </p><p>
   * </p>
   * @since 0.3
   * @throws LibGuestFSException
   */
  public void add_drive (String filename, Map<String, Object> optargs)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("add_drive: handle is closed");

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
    String label = "";
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("label");
    if (_optobj != null) {
      label = ((String) _optobj);
      _optargs_bitmask |= 16L;
    }
    String protocol = "";
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("protocol");
    if (_optobj != null) {
      protocol = ((String) _optobj);
      _optargs_bitmask |= 32L;
    }
    String[] server = new String[]{};
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("server");
    if (_optobj != null) {
      server = ((String[]) _optobj);
      _optargs_bitmask |= 64L;
    }
    String username = "";
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("username");
    if (_optobj != null) {
      username = ((String) _optobj);
      _optargs_bitmask |= 128L;
    }
    String secret = "";
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("secret");
    if (_optobj != null) {
      secret = ((String) _optobj);
      _optargs_bitmask |= 256L;
    }
    String cachemode = "";
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("cachemode");
    if (_optobj != null) {
      cachemode = ((String) _optobj);
      _optargs_bitmask |= 512L;
    }
    String discard = "";
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("discard");
    if (_optobj != null) {
      discard = ((String) _optobj);
      _optargs_bitmask |= 1024L;
    }
    boolean copyonread = false;
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("copyonread");
    if (_optobj != null) {
      copyonread = ((Boolean) _optobj).booleanValue();
      _optargs_bitmask |= 2048L;
    }

    _add_drive (g, filename, _optargs_bitmask, readonly, format, iface, name, label, protocol, server, username, secret, cachemode, discard, copyonread);
  }

  public void add_drive (String filename)
    throws LibGuestFSException
  {
    add_drive (filename, null);
  }

  public void add_drive_opts (String filename, Map<String, Object> optargs)
    throws LibGuestFSException
  {
    add_drive (filename, optargs);
  }

  public void add_drive_opts (String filename)
    throws LibGuestFSException
  {
    add_drive (filename, null);
  }

  private native void _add_drive (long g, String filename, long _optargs_bitmask, boolean readonly, String format, String iface, String name, String label, String protocol, String[] server, String username, String secret, String cachemode, String discard, boolean copyonread)
    throws LibGuestFSException;

  /**
   * <p>
   * add a drive in snapshot mode (read-only)
   * </p><p>
   * This function is the equivalent of calling
   * "g.add_drive_opts" with the optional parameter
   * "GUESTFS_ADD_DRIVE_OPTS_READONLY" set to 1, so the disk
   * is added read-only, with the format being detected
   * automatically.
   * </p><p>
   * </p>
   * @since 1.0.38
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
   * <p>
   * add a drive read-only specifying the QEMU block emulation to use
   * </p><p>
   * This is the same as "g.add_drive_ro" but it allows you
   * to specify the QEMU interface emulation to use at run
   * time.
   * </p><p>
   * </p>
   * @since 1.0.84
   * @deprecated In new code, use {@link #add_drive} instead
   * @throws LibGuestFSException
   */
  @Deprecated public void add_drive_ro_with_if (String filename, String iface)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("add_drive_ro_with_if: handle is closed");

    _add_drive_ro_with_if (g, filename, iface);
  }

  private native void _add_drive_ro_with_if (long g, String filename, String iface)
    throws LibGuestFSException;

  /**
   * <p>
   * add a temporary scratch drive
   * </p><p>
   * This command adds a temporary scratch drive to the
   * handle. The "size" parameter is the virtual size (in
   * bytes). The scratch drive is blank initially (all reads
   * return zeroes until you start writing to it). The drive
   * is deleted when the handle is closed.
   * </p><p>
   * The optional arguments "name" and "label" are passed
   * through to "g.add_drive".
   * </p><p>
   * Optional arguments are supplied in the final
   * Map&lt;String,Object&gt; parameter, which is a hash of the
   * argument name to its value (cast to Object). Pass an
   * empty Map or null for no optional arguments.
   * </p><p>
   * </p>
   * @since 1.23.10
   * @throws LibGuestFSException
   */
  public void add_drive_scratch (long size, Map<String, Object> optargs)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("add_drive_scratch: handle is closed");

    /* Unpack optional args. */
    Object _optobj;
    long _optargs_bitmask = 0;
    String name = "";
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("name");
    if (_optobj != null) {
      name = ((String) _optobj);
      _optargs_bitmask |= 1L;
    }
    String label = "";
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("label");
    if (_optobj != null) {
      label = ((String) _optobj);
      _optargs_bitmask |= 2L;
    }

    _add_drive_scratch (g, size, _optargs_bitmask, name, label);
  }

  public void add_drive_scratch (long size)
    throws LibGuestFSException
  {
    add_drive_scratch (size, null);
  }

  private native void _add_drive_scratch (long g, long size, long _optargs_bitmask, String name, String label)
    throws LibGuestFSException;

  /**
   * <p>
   * add a drive specifying the QEMU block emulation to use
   * </p><p>
   * This is the same as "g.add_drive" but it allows you to
   * specify the QEMU interface emulation to use at run time.
   * </p><p>
   * </p>
   * @since 1.0.84
   * @deprecated In new code, use {@link #add_drive} instead
   * @throws LibGuestFSException
   */
  @Deprecated public void add_drive_with_if (String filename, String iface)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("add_drive_with_if: handle is closed");

    _add_drive_with_if (g, filename, iface);
  }

  private native void _add_drive_with_if (long g, String filename, String iface)
    throws LibGuestFSException;

  /**
   * <p>
   * add the disk(s) from a libvirt domain
   * </p><p>
   * This function adds the disk(s) attached to the libvirt
   * domain "dom". It works by requesting the domain XML from
   * libvirt, parsing it for disks, and calling
   * "g.add_drive_opts" on each one.
   * </p><p>
   * In the C API we declare "void *dom", but really it has
   * type "virDomainPtr dom". This is so we don't need
   * &lt;libvirt.h&gt;.
   * </p><p>
   * The number of disks added is returned. This operation is
   * atomic: if an error is returned, then no disks are
   * added.
   * </p><p>
   * This function does some minimal checks to make sure the
   * libvirt domain is not running (unless "readonly" is
   * true). In a future version we will try to acquire the
   * libvirt lock on each disk.
   * </p><p>
   * Disks must be accessible locally. This often means that
   * adding disks from a remote libvirt connection (see
   * &lt;http://libvirt.org/remote.html&gt;) will fail unless those
   * disks are accessible via the same device path locally
   * too.
   * </p><p>
   * The optional "live" flag controls whether this call will
   * try to connect to a running virtual machine "guestfsd"
   * process if it sees a suitable &lt;channel&gt; element in the
   * libvirt XML definition. The default (if the flag is
   * omitted) is never to try. See "ATTACHING TO RUNNING
   * DAEMONS" in guestfs(3) for more information.
   * </p><p>
   * The optional "readonlydisk" parameter controls what we
   * do for disks which are marked &lt;readonly/&gt; in the libvirt
   * XML. See "g.add_domain" for possible values.
   * </p><p>
   * The other optional parameters are passed directly
   * through to "g.add_drive_opts".
   * </p><p>
   * Optional arguments are supplied in the final
   * Map&lt;String,Object&gt; parameter, which is a hash of the
   * argument name to its value (cast to Object). Pass an
   * empty Map or null for no optional arguments.
   * </p><p>
   * </p>
   * @since 1.29.14
   * @throws LibGuestFSException
   */
  public int add_libvirt_dom (long dom, Map<String, Object> optargs)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("add_libvirt_dom: handle is closed");

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
    String iface = "";
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("iface");
    if (_optobj != null) {
      iface = ((String) _optobj);
      _optargs_bitmask |= 2L;
    }
    boolean live = false;
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("live");
    if (_optobj != null) {
      live = ((Boolean) _optobj).booleanValue();
      _optargs_bitmask |= 4L;
    }
    String readonlydisk = "";
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("readonlydisk");
    if (_optobj != null) {
      readonlydisk = ((String) _optobj);
      _optargs_bitmask |= 8L;
    }
    String cachemode = "";
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("cachemode");
    if (_optobj != null) {
      cachemode = ((String) _optobj);
      _optargs_bitmask |= 16L;
    }
    String discard = "";
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("discard");
    if (_optobj != null) {
      discard = ((String) _optobj);
      _optargs_bitmask |= 32L;
    }
    boolean copyonread = false;
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("copyonread");
    if (_optobj != null) {
      copyonread = ((Boolean) _optobj).booleanValue();
      _optargs_bitmask |= 64L;
    }

    return _add_libvirt_dom (g, dom, _optargs_bitmask, readonly, iface, live, readonlydisk, cachemode, discard, copyonread);
  }

  public int add_libvirt_dom (long dom)
    throws LibGuestFSException
  {
    return add_libvirt_dom (dom, null);
  }

  private native int _add_libvirt_dom (long g, long dom, long _optargs_bitmask, boolean readonly, String iface, boolean live, String readonlydisk, String cachemode, String discard, boolean copyonread)
    throws LibGuestFSException;

  /**
   * <p>
   * clear Augeas path
   * </p><p>
   * Set the value associated with "path" to "NULL". This is
   * the same as the augtool(1) "clear" command.
   * </p><p>
   * </p>
   * @since 1.3.4
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
   * <p>
   * close the current Augeas handle
   * </p><p>
   * Close the current Augeas handle and free up any
   * resources used by it. After calling this, you have to
   * call "g.aug_init" again before you can use any other
   * Augeas functions.
   * </p><p>
   * </p>
   * @since 0.7
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
   * <p>
   * define an Augeas node
   * </p><p>
   * Defines a variable "name" whose value is the result of
   * evaluating "expr".
   * </p><p>
   * If "expr" evaluates to an empty nodeset, a node is
   * created, equivalent to calling "g.aug_set" "expr",
   * "value". "name" will be the nodeset containing that
   * single node.
   * </p><p>
   * On success this returns a pair containing the number of
   * nodes in the nodeset, and a boolean flag if a node was
   * created.
   * </p><p>
   * </p>
   * @since 0.7
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
   * <p>
   * define an Augeas variable
   * </p><p>
   * Defines an Augeas variable "name" whose value is the
   * result of evaluating "expr". If "expr" is NULL, then
   * "name" is undefined.
   * </p><p>
   * On success this returns the number of nodes in "expr",
   * or 0 if "expr" evaluates to something which is not a
   * nodeset.
   * </p><p>
   * </p>
   * @since 0.7
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
   * <p>
   * look up the value of an Augeas path
   * </p><p>
   * Look up the value associated with "path". If "path"
   * matches exactly one node, the "value" is returned.
   * </p><p>
   * </p>
   * @since 0.7
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
   * <p>
   * create a new Augeas handle
   * </p><p>
   * Create a new Augeas handle for editing configuration
   * files. If there was any previous Augeas handle
   * associated with this guestfs session, then it is closed.
   * </p><p>
   * You must call this before using any other "g.aug_*"
   * commands.
   * </p><p>
   * "root" is the filesystem root. "root" must not be NULL,
   * use / instead.
   * </p><p>
   * The flags are the same as the flags defined in
   * &lt;augeas.h&gt;, the logical *or* of the following integers:
   * </p><p>
   * "AUG_SAVE_BACKUP" = 1
   * Keep the original file with a ".augsave" extension.
   * </p><p>
   * "AUG_SAVE_NEWFILE" = 2
   * Save changes into a file with extension ".augnew",
   * and do not overwrite original. Overrides
   * "AUG_SAVE_BACKUP".
   * </p><p>
   * "AUG_TYPE_CHECK" = 4
   * Typecheck lenses.
   * </p><p>
   * This option is only useful when debugging Augeas
   * lenses. Use of this option may require additional
   * memory for the libguestfs appliance. You may need to
   * set the "LIBGUESTFS_MEMSIZE" environment variable or
   * call "g.set_memsize".
   * </p><p>
   * "AUG_NO_STDINC" = 8
   * Do not use standard load path for modules.
   * </p><p>
   * "AUG_SAVE_NOOP" = 16
   * Make save a no-op, just record what would have been
   * changed.
   * </p><p>
   * "AUG_NO_LOAD" = 32
   * Do not load the tree in "g.aug_init".
   * </p><p>
   * To close the handle, you can call "g.aug_close".
   * </p><p>
   * To find out more about Augeas, see &lt;http://augeas.net/&gt;.
   * </p><p>
   * </p>
   * @since 0.7
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
   * <p>
   * insert a sibling Augeas node
   * </p><p>
   * Create a new sibling "label" for "path", inserting it
   * into the tree before or after "path" (depending on the
   * boolean flag "before").
   * </p><p>
   * "path" must match exactly one existing node in the tree,
   * and "label" must be a label, ie. not contain /, "*" or
   * end with a bracketed index "[N]".
   * </p><p>
   * </p>
   * @since 0.7
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
   * <p>
   * return the label from an Augeas path expression
   * </p><p>
   * The label (name of the last element) of the Augeas path
   * expression "augpath" is returned. "augpath" must match
   * exactly one node, else this function returns an error.
   * </p><p>
   * </p>
   * @since 1.23.14
   * @throws LibGuestFSException
   */
  public String aug_label (String augpath)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("aug_label: handle is closed");

    return _aug_label (g, augpath);
  }

  private native String _aug_label (long g, String augpath)
    throws LibGuestFSException;

  /**
   * <p>
   * load files into the tree
   * </p><p>
   * Load files into the tree.
   * </p><p>
   * See "aug_load" in the Augeas documentation for the full
   * gory details.
   * </p><p>
   * </p>
   * @since 0.7
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
   * <p>
   * list Augeas nodes under augpath
   * </p><p>
   * This is just a shortcut for listing "g.aug_match"
   * "path/*" and sorting the resulting nodes into
   * alphabetical order.
   * </p><p>
   * </p>
   * @since 0.8
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
   * <p>
   * return Augeas nodes which match augpath
   * </p><p>
   * Returns a list of paths which match the path expression
   * "path". The returned paths are sufficiently qualified so
   * that they match exactly one node in the current tree.
   * </p><p>
   * </p>
   * @since 0.7
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
   * <p>
   * move Augeas node
   * </p><p>
   * Move the node "src" to "dest". "src" must match exactly
   * one node. "dest" is overwritten if it exists.
   * </p><p>
   * </p>
   * @since 0.7
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
   * <p>
   * remove an Augeas path
   * </p><p>
   * Remove "path" and all of its children.
   * </p><p>
   * On success this returns the number of entries which were
   * removed.
   * </p><p>
   * </p>
   * @since 0.7
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
   * <p>
   * write all pending Augeas changes to disk
   * </p><p>
   * This writes all pending changes to disk.
   * </p><p>
   * The flags which were passed to "g.aug_init" affect
   * exactly how files are saved.
   * </p><p>
   * </p>
   * @since 0.7
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
   * <p>
   * set Augeas path to value
   * </p><p>
   * Set the value associated with "path" to "val".
   * </p><p>
   * In the Augeas API, it is possible to clear a node by
   * setting the value to NULL. Due to an oversight in the
   * libguestfs API you cannot do that with this call.
   * Instead you must use the "g.aug_clear" call.
   * </p><p>
   * </p>
   * @since 0.7
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
   * <p>
   * set multiple Augeas nodes
   * </p><p>
   * Change multiple Augeas nodes in a single operation.
   * "base" is an expression matching multiple nodes. "sub"
   * is a path expression relative to "base". All nodes
   * matching "base" are found, and then for each node, "sub"
   * is changed to "val". "sub" may also be "NULL" in which
   * case the "base" nodes are modified.
   * </p><p>
   * This returns the number of nodes modified.
   * </p><p>
   * </p>
   * @since 1.23.14
   * @throws LibGuestFSException
   */
  public int aug_setm (String base, String sub, String val)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("aug_setm: handle is closed");

    return _aug_setm (g, base, sub, val);
  }

  private native int _aug_setm (long g, String base, String sub, String val)
    throws LibGuestFSException;

  /**
   * <p>
   * test availability of some parts of the API
   * </p><p>
   * This command is used to check the availability of some
   * groups of functionality in the appliance, which not all
   * builds of the libguestfs appliance will be able to
   * provide.
   * </p><p>
   * The libguestfs groups, and the functions that those
   * groups correspond to, are listed in "AVAILABILITY" in
   * guestfs(3). You can also fetch this list at runtime by
   * calling "g.available_all_groups".
   * </p><p>
   * The argument "groups" is a list of group names, eg:
   * "["inotify", "augeas"]" would check for the availability
   * of the Linux inotify functions and Augeas (configuration
   * file editing) functions.
   * </p><p>
   * The command returns no error if *all* requested groups
   * are available.
   * </p><p>
   * It fails with an error if one or more of the requested
   * groups is unavailable in the appliance.
   * </p><p>
   * If an unknown group name is included in the list of
   * groups then an error is always returned.
   * </p><p>
   * *Notes:*
   * </p><p>
   * *   "g.feature_available" is the same as this call, but
   * with a slightly simpler to use API: that call
   * returns a boolean true/false instead of throwing an
   * error.
   * </p><p>
   * *   You must call "g.launch" before calling this
   * function.
   * </p><p>
   * The reason is because we don't know what groups are
   * supported by the appliance/daemon until it is
   * running and can be queried.
   * </p><p>
   * *   If a group of functions is available, this does not
   * necessarily mean that they will work. You still have
   * to check for errors when calling individual API
   * functions even if they are available.
   * </p><p>
   * *   It is usually the job of distro packagers to build
   * complete functionality into the libguestfs
   * appliance. Upstream libguestfs, if built from source
   * with all requirements satisfied, will support
   * everything.
   * </p><p>
   * *   This call was added in version 1.0.80. In previous
   * versions of libguestfs all you could do would be to
   * speculatively execute a command to find out if the
   * daemon implemented it. See also "g.version".
   * </p><p>
   * See also "g.filesystem_available".
   * </p><p>
   * </p>
   * @since 1.0.80
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
   * <p>
   * return a list of all optional groups
   * </p><p>
   * This command returns a list of all optional groups that
   * this daemon knows about. Note this returns both
   * supported and unsupported groups. To find out which ones
   * the daemon can actually support you have to call
   * "g.available" / "g.feature_available" on each member of
   * the returned list.
   * </p><p>
   * See also "g.available", "g.feature_available" and
   * "AVAILABILITY" in guestfs(3).
   * </p><p>
   * </p>
   * @since 1.3.15
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
   * <p>
   * upload base64-encoded data to file
   * </p><p>
   * This command uploads base64-encoded data from
   * "base64file" to filename.
   * </p><p>
   * </p>
   * @since 1.3.5
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
   * <p>
   * download file and encode as base64
   * </p><p>
   * This command downloads the contents of filename, writing
   * it out to local file "base64file" encoded as base64.
   * </p><p>
   * </p>
   * @since 1.3.5
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
   * <p>
   * discard all blocks on a device
   * </p><p>
   * This discards all blocks on the block device "device",
   * giving the free space back to the host.
   * </p><p>
   * This operation requires support in libguestfs, the host
   * filesystem, qemu and the host kernel. If this support
   * isn't present it may give an error or even appear to run
   * but do nothing. You must also set the "discard"
   * attribute on the underlying drive (see
   * "g.add_drive_opts").
   * </p><p>
   * </p>
   * @since 1.25.44
   * @throws LibGuestFSException
   */
  public void blkdiscard (String device)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("blkdiscard: handle is closed");

    _blkdiscard (g, device);
  }

  private native void _blkdiscard (long g, String device)
    throws LibGuestFSException;

  /**
   * <p>
   * return true if discarded blocks are read as zeroes
   * </p><p>
   * This call returns true if blocks on "device" that have
   * been discarded by a call to "g.blkdiscard" are returned
   * as blocks of zero bytes when read the next time.
   * </p><p>
   * If it returns false, then it may be that discarded
   * blocks are read as stale or random data.
   * </p><p>
   * </p>
   * @since 1.25.44
   * @throws LibGuestFSException
   */
  public boolean blkdiscardzeroes (String device)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("blkdiscardzeroes: handle is closed");

    return _blkdiscardzeroes (g, device);
  }

  private native boolean _blkdiscardzeroes (long g, String device)
    throws LibGuestFSException;

  /**
   * <p>
   * print block device attributes
   * </p><p>
   * This command returns block device attributes for
   * "device". The following fields are usually present in
   * the returned hash. Other fields may also be present.
   * </p><p>
   * "UUID"
   * The uuid of this device.
   * </p><p>
   * "LABEL"
   * The label of this device.
   * </p><p>
   * "VERSION"
   * The version of blkid command.
   * </p><p>
   * "TYPE"
   * The filesystem type or RAID of this device.
   * </p><p>
   * "USAGE"
   * The usage of this device, for example "filesystem"
   * or "raid".
   * </p><p>
   * </p>
   * @since 1.15.9
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
   * <p>
   * flush device buffers
   * </p><p>
   * This tells the kernel to flush internal buffers
   * associated with "device".
   * </p><p>
   * This uses the blockdev(8) command.
   * </p><p>
   * </p>
   * @since 1.9.3
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
   * <p>
   * get blocksize of block device
   * </p><p>
   * This returns the block size of a device.
   * </p><p>
   * Note: this is different from both *size in blocks* and
   * *filesystem block size*. Also this setting is not really
   * used by anything. You should probably not use it for
   * anything. Filesystems have their own idea about what
   * block size to choose.
   * </p><p>
   * This uses the blockdev(8) command.
   * </p><p>
   * </p>
   * @since 1.9.3
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
   * <p>
   * is block device set to read-only
   * </p><p>
   * Returns a boolean indicating if the block device is
   * read-only (true if read-only, false if not).
   * </p><p>
   * This uses the blockdev(8) command.
   * </p><p>
   * </p>
   * @since 1.9.3
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
   * <p>
   * get total size of device in bytes
   * </p><p>
   * This returns the size of the device in bytes.
   * </p><p>
   * See also "g.blockdev_getsz".
   * </p><p>
   * This uses the blockdev(8) command.
   * </p><p>
   * </p>
   * @since 1.9.3
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
   * <p>
   * get sectorsize of block device
   * </p><p>
   * This returns the size of sectors on a block device.
   * Usually 512, but can be larger for modern devices.
   * </p><p>
   * (Note, this is not the size in sectors, use
   * "g.blockdev_getsz" for that).
   * </p><p>
   * This uses the blockdev(8) command.
   * </p><p>
   * </p>
   * @since 1.9.3
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
   * <p>
   * get total size of device in 512-byte sectors
   * </p><p>
   * This returns the size of the device in units of 512-byte
   * sectors (even if the sectorsize isn't 512 bytes ...
   * weird).
   * </p><p>
   * See also "g.blockdev_getss" for the real sector size of
   * the device, and "g.blockdev_getsize64" for the more
   * useful *size in bytes*.
   * </p><p>
   * This uses the blockdev(8) command.
   * </p><p>
   * </p>
   * @since 1.9.3
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
   * <p>
   * reread partition table
   * </p><p>
   * Reread the partition table on "device".
   * </p><p>
   * This uses the blockdev(8) command.
   * </p><p>
   * </p>
   * @since 1.9.3
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
   * <p>
   * set blocksize of block device
   * </p><p>
   * This call does nothing and has never done anything
   * because of a bug in blockdev. Do not use it.
   * </p><p>
   * If you need to set the filesystem block size, use the
   * "blocksize" option of "g.mkfs".
   * </p><p>
   * </p>
   * @since 1.9.3
   * @deprecated In new code, use {@link #mkfs} instead
   * @throws LibGuestFSException
   */
  @Deprecated public void blockdev_setbsz (String device, int blocksize)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("blockdev_setbsz: handle is closed");

    _blockdev_setbsz (g, device, blocksize);
  }

  private native void _blockdev_setbsz (long g, String device, int blocksize)
    throws LibGuestFSException;

  /**
   * <p>
   * set readahead
   * </p><p>
   * Set readahead (in 512-byte sectors) for the device.
   * </p><p>
   * This uses the blockdev(8) command.
   * </p><p>
   * </p>
   * @since 1.29.10
   * @throws LibGuestFSException
   */
  public void blockdev_setra (String device, int sectors)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("blockdev_setra: handle is closed");

    _blockdev_setra (g, device, sectors);
  }

  private native void _blockdev_setra (long g, String device, int sectors)
    throws LibGuestFSException;

  /**
   * <p>
   * set block device to read-only
   * </p><p>
   * Sets the block device named "device" to read-only.
   * </p><p>
   * This uses the blockdev(8) command.
   * </p><p>
   * </p>
   * @since 1.9.3
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
   * <p>
   * set block device to read-write
   * </p><p>
   * Sets the block device named "device" to read-write.
   * </p><p>
   * This uses the blockdev(8) command.
   * </p><p>
   * </p>
   * @since 1.9.3
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
   * <p>
   * cancel a running or paused balance
   * </p><p>
   * Cancel a running balance on a btrfs filesystem.
   * </p><p>
   * </p>
   * @since 1.29.22
   * @throws LibGuestFSException
   */
  public void btrfs_balance_cancel (String path)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("btrfs_balance_cancel: handle is closed");

    _btrfs_balance_cancel (g, path);
  }

  private native void _btrfs_balance_cancel (long g, String path)
    throws LibGuestFSException;

  /**
   * <p>
   * pause a running balance
   * </p><p>
   * Pause a running balance on a btrfs filesystem.
   * </p><p>
   * </p>
   * @since 1.29.22
   * @throws LibGuestFSException
   */
  public void btrfs_balance_pause (String path)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("btrfs_balance_pause: handle is closed");

    _btrfs_balance_pause (g, path);
  }

  private native void _btrfs_balance_pause (long g, String path)
    throws LibGuestFSException;

  /**
   * <p>
   * resume a paused balance
   * </p><p>
   * Resume a paused balance on a btrfs filesystem.
   * </p><p>
   * </p>
   * @since 1.29.22
   * @throws LibGuestFSException
   */
  public void btrfs_balance_resume (String path)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("btrfs_balance_resume: handle is closed");

    _btrfs_balance_resume (g, path);
  }

  private native void _btrfs_balance_resume (long g, String path)
    throws LibGuestFSException;

  /**
   * <p>
   * show the status of a running or paused balance
   * </p><p>
   * Show the status of a running or paused balance on a
   * btrfs filesystem.
   * </p><p>
   * </p>
   * @since 1.29.26
   * @throws LibGuestFSException
   */
  public BTRFSBalance btrfs_balance_status (String path)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("btrfs_balance_status: handle is closed");

    return _btrfs_balance_status (g, path);
  }

  private native BTRFSBalance _btrfs_balance_status (long g, String path)
    throws LibGuestFSException;

  /**
   * <p>
   * add devices to a btrfs filesystem
   * </p><p>
   * Add the list of device(s) in "devices" to the btrfs
   * filesystem mounted at "fs". If "devices" is an empty
   * list, this does nothing.
   * </p><p>
   * </p>
   * @since 1.17.35
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
   * <p>
   * remove devices from a btrfs filesystem
   * </p><p>
   * Remove the "devices" from the btrfs filesystem mounted
   * at "fs". If "devices" is an empty list, this does
   * nothing.
   * </p><p>
   * </p>
   * @since 1.17.35
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
   * <p>
   * balance a btrfs filesystem
   * </p><p>
   * Balance the chunks in the btrfs filesystem mounted at
   * "fs" across the underlying devices.
   * </p><p>
   * </p>
   * @since 1.17.35
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
   * <p>
   * defragment a file or directory
   * </p><p>
   * Defragment a file or directory on a btrfs filesystem.
   * compress is one of zlib or lzo.
   * </p><p>
   * Optional arguments are supplied in the final
   * Map&lt;String,Object&gt; parameter, which is a hash of the
   * argument name to its value (cast to Object). Pass an
   * empty Map or null for no optional arguments.
   * </p><p>
   * </p>
   * @since 1.29.22
   * @throws LibGuestFSException
   */
  public void btrfs_filesystem_defragment (String path, Map<String, Object> optargs)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("btrfs_filesystem_defragment: handle is closed");

    /* Unpack optional args. */
    Object _optobj;
    long _optargs_bitmask = 0;
    boolean flush = false;
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("flush");
    if (_optobj != null) {
      flush = ((Boolean) _optobj).booleanValue();
      _optargs_bitmask |= 1L;
    }
    String compress = "";
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("compress");
    if (_optobj != null) {
      compress = ((String) _optobj);
      _optargs_bitmask |= 2L;
    }

    _btrfs_filesystem_defragment (g, path, _optargs_bitmask, flush, compress);
  }

  public void btrfs_filesystem_defragment (String path)
    throws LibGuestFSException
  {
    btrfs_filesystem_defragment (path, null);
  }

  private native void _btrfs_filesystem_defragment (long g, String path, long _optargs_bitmask, boolean flush, String compress)
    throws LibGuestFSException;

  /**
   * <p>
   * resize a btrfs filesystem
   * </p><p>
   * This command resizes a btrfs filesystem.
   * </p><p>
   * Note that unlike other resize calls, the filesystem has
   * to be mounted and the parameter is the mountpoint not
   * the device (this is a requirement of btrfs itself).
   * </p><p>
   * The optional parameters are:
   * </p><p>
   * "size"
   * The new size (in bytes) of the filesystem. If
   * omitted, the filesystem is resized to the maximum
   * size.
   * </p><p>
   * See also btrfs(8).
   * </p><p>
   * Optional arguments are supplied in the final
   * Map&lt;String,Object&gt; parameter, which is a hash of the
   * argument name to its value (cast to Object). Pass an
   * empty Map or null for no optional arguments.
   * </p><p>
   * </p>
   * @since 1.11.17
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
   * <p>
   * sync a btrfs filesystem
   * </p><p>
   * Force sync on the btrfs filesystem mounted at "fs".
   * </p><p>
   * </p>
   * @since 1.17.35
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
   * <p>
   * check a btrfs filesystem
   * </p><p>
   * Used to check a btrfs filesystem, "device" is the device
   * file where the filesystem is stored.
   * </p><p>
   * Optional arguments are supplied in the final
   * Map&lt;String,Object&gt; parameter, which is a hash of the
   * argument name to its value (cast to Object). Pass an
   * empty Map or null for no optional arguments.
   * </p><p>
   * </p>
   * @since 1.17.43
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
   * <p>
   * create an image of a btrfs filesystem
   * </p><p>
   * This is used to create an image of a btrfs filesystem.
   * All data will be zeroed, but metadata and the like is
   * preserved.
   * </p><p>
   * Optional arguments are supplied in the final
   * Map&lt;String,Object&gt; parameter, which is a hash of the
   * argument name to its value (cast to Object). Pass an
   * empty Map or null for no optional arguments.
   * </p><p>
   * </p>
   * @since 1.29.32
   * @throws LibGuestFSException
   */
  public void btrfs_image (String[] source, String image, Map<String, Object> optargs)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("btrfs_image: handle is closed");

    /* Unpack optional args. */
    Object _optobj;
    long _optargs_bitmask = 0;
    int compresslevel = 0;
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("compresslevel");
    if (_optobj != null) {
      compresslevel = ((Integer) _optobj).intValue();
      _optargs_bitmask |= 1L;
    }

    _btrfs_image (g, source, image, _optargs_bitmask, compresslevel);
  }

  public void btrfs_image (String[] source, String image)
    throws LibGuestFSException
  {
    btrfs_image (source, image, null);
  }

  private native void _btrfs_image (long g, String[] source, String image, long _optargs_bitmask, int compresslevel)
    throws LibGuestFSException;

  /**
   * <p>
   * add a qgroup to a parent qgroup
   * </p><p>
   * Add qgroup "src" to parent qgroup "dst". This command
   * can group several qgroups into a parent qgroup to share
   * common limit.
   * </p><p>
   * </p>
   * @since 1.29.17
   * @throws LibGuestFSException
   */
  public void btrfs_qgroup_assign (String src, String dst, String path)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("btrfs_qgroup_assign: handle is closed");

    _btrfs_qgroup_assign (g, src, dst, path);
  }

  private native void _btrfs_qgroup_assign (long g, String src, String dst, String path)
    throws LibGuestFSException;

  /**
   * <p>
   * create a subvolume quota group
   * </p><p>
   * Create a quota group (qgroup) for subvolume at
   * "subvolume".
   * </p><p>
   * </p>
   * @since 1.29.17
   * @throws LibGuestFSException
   */
  public void btrfs_qgroup_create (String qgroupid, String subvolume)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("btrfs_qgroup_create: handle is closed");

    _btrfs_qgroup_create (g, qgroupid, subvolume);
  }

  private native void _btrfs_qgroup_create (long g, String qgroupid, String subvolume)
    throws LibGuestFSException;

  /**
   * <p>
   * destroy a subvolume quota group
   * </p><p>
   * Destroy a quota group.
   * </p><p>
   * </p>
   * @since 1.29.17
   * @throws LibGuestFSException
   */
  public void btrfs_qgroup_destroy (String qgroupid, String subvolume)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("btrfs_qgroup_destroy: handle is closed");

    _btrfs_qgroup_destroy (g, qgroupid, subvolume);
  }

  private native void _btrfs_qgroup_destroy (long g, String qgroupid, String subvolume)
    throws LibGuestFSException;

  /**
   * <p>
   * limit the size of a subvolume
   * </p><p>
   * Limit the size of a subvolume which's path is
   * "subvolume". "size" can have suffix of G, M, or K.
   * </p><p>
   * </p>
   * @since 1.29.17
   * @throws LibGuestFSException
   */
  public void btrfs_qgroup_limit (String subvolume, long size)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("btrfs_qgroup_limit: handle is closed");

    _btrfs_qgroup_limit (g, subvolume, size);
  }

  private native void _btrfs_qgroup_limit (long g, String subvolume, long size)
    throws LibGuestFSException;

  /**
   * <p>
   * remove a qgroup from its parent qgroup
   * </p><p>
   * Remove qgroup "src" from the parent qgroup "dst".
   * </p><p>
   * </p>
   * @since 1.29.17
   * @throws LibGuestFSException
   */
  public void btrfs_qgroup_remove (String src, String dst, String path)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("btrfs_qgroup_remove: handle is closed");

    _btrfs_qgroup_remove (g, src, dst, path);
  }

  private native void _btrfs_qgroup_remove (long g, String src, String dst, String path)
    throws LibGuestFSException;

  /**
   * <p>
   * show subvolume quota groups
   * </p><p>
   * Show all subvolume quota groups in a btrfs filesystem,
   * including their usages.
   * </p><p>
   * </p>
   * @since 1.29.17
   * @throws LibGuestFSException
   */
  public BTRFSQgroup[] btrfs_qgroup_show (String path)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("btrfs_qgroup_show: handle is closed");

    return _btrfs_qgroup_show (g, path);
  }

  private native BTRFSQgroup[] _btrfs_qgroup_show (long g, String path)
    throws LibGuestFSException;

  /**
   * <p>
   * enable or disable subvolume quota support
   * </p><p>
   * Enable or disable subvolume quota support for filesystem
   * which contains "path".
   * </p><p>
   * </p>
   * @since 1.29.17
   * @throws LibGuestFSException
   */
  public void btrfs_quota_enable (String fs, boolean enable)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("btrfs_quota_enable: handle is closed");

    _btrfs_quota_enable (g, fs, enable);
  }

  private native void _btrfs_quota_enable (long g, String fs, boolean enable)
    throws LibGuestFSException;

  /**
   * <p>
   * trash all qgroup numbers and scan the metadata again with the current config
   * </p><p>
   * Trash all qgroup numbers and scan the metadata again
   * with the current config.
   * </p><p>
   * </p>
   * @since 1.29.17
   * @throws LibGuestFSException
   */
  public void btrfs_quota_rescan (String fs)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("btrfs_quota_rescan: handle is closed");

    _btrfs_quota_rescan (g, fs);
  }

  private native void _btrfs_quota_rescan (long g, String fs)
    throws LibGuestFSException;

  /**
   * <p>
   * replace a btrfs managed device with another device
   * </p><p>
   * Replace device of a btrfs filesystem. On a live
   * filesystem, duplicate the data to the target device
   * which is currently stored on the source device. After
   * completion of the operation, the source device is wiped
   * out and removed from the filesystem.
   * </p><p>
   * The "targetdev" needs to be same size or larger than the
   * "srcdev". Devices which are currently mounted are never
   * allowed to be used as the "targetdev".
   * </p><p>
   * </p>
   * @since 1.29.48
   * @throws LibGuestFSException
   */
  public void btrfs_replace (String srcdev, String targetdev, String mntpoint)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("btrfs_replace: handle is closed");

    _btrfs_replace (g, srcdev, targetdev, mntpoint);
  }

  private native void _btrfs_replace (long g, String srcdev, String targetdev, String mntpoint)
    throws LibGuestFSException;

  /**
   * <p>
   * recover the chunk tree of btrfs filesystem
   * </p><p>
   * Recover the chunk tree of btrfs filesystem by scanning
   * the devices one by one.
   * </p><p>
   * </p>
   * @since 1.29.22
   * @throws LibGuestFSException
   */
  public void btrfs_rescue_chunk_recover (String device)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("btrfs_rescue_chunk_recover: handle is closed");

    _btrfs_rescue_chunk_recover (g, device);
  }

  private native void _btrfs_rescue_chunk_recover (long g, String device)
    throws LibGuestFSException;

  /**
   * <p>
   * recover bad superblocks from good copies
   * </p><p>
   * Recover bad superblocks from good copies.
   * </p><p>
   * </p>
   * @since 1.29.22
   * @throws LibGuestFSException
   */
  public void btrfs_rescue_super_recover (String device)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("btrfs_rescue_super_recover: handle is closed");

    _btrfs_rescue_super_recover (g, device);
  }

  private native void _btrfs_rescue_super_recover (long g, String device)
    throws LibGuestFSException;

  /**
   * <p>
   * cancel a running scrub
   * </p><p>
   * Cancel a running scrub on a btrfs filesystem.
   * </p><p>
   * </p>
   * @since 1.29.22
   * @throws LibGuestFSException
   */
  public void btrfs_scrub_cancel (String path)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("btrfs_scrub_cancel: handle is closed");

    _btrfs_scrub_cancel (g, path);
  }

  private native void _btrfs_scrub_cancel (long g, String path)
    throws LibGuestFSException;

  /**
   * <p>
   * resume a previously canceled or interrupted scrub
   * </p><p>
   * Resume a previously canceled or interrupted scrub on a
   * btrfs filesystem.
   * </p><p>
   * </p>
   * @since 1.29.22
   * @throws LibGuestFSException
   */
  public void btrfs_scrub_resume (String path)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("btrfs_scrub_resume: handle is closed");

    _btrfs_scrub_resume (g, path);
  }

  private native void _btrfs_scrub_resume (long g, String path)
    throws LibGuestFSException;

  /**
   * <p>
   * read all data from all disks and verify checksums
   * </p><p>
   * Reads all the data and metadata on the filesystem, and
   * uses checksums and the duplicate copies from RAID
   * storage to identify and repair any corrupt data.
   * </p><p>
   * </p>
   * @since 1.29.22
   * @throws LibGuestFSException
   */
  public void btrfs_scrub_start (String path)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("btrfs_scrub_start: handle is closed");

    _btrfs_scrub_start (g, path);
  }

  private native void _btrfs_scrub_start (long g, String path)
    throws LibGuestFSException;

  /**
   * <p>
   * show status of running or finished scrub
   * </p><p>
   * Show status of running or finished scrub on a btrfs
   * filesystem.
   * </p><p>
   * </p>
   * @since 1.29.26
   * @throws LibGuestFSException
   */
  public BTRFSScrub btrfs_scrub_status (String path)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("btrfs_scrub_status: handle is closed");

    return _btrfs_scrub_status (g, path);
  }

  private native BTRFSScrub _btrfs_scrub_status (long g, String path)
    throws LibGuestFSException;

  /**
   * <p>
   * enable or disable the seeding feature of device
   * </p><p>
   * Enable or disable the seeding feature of a device that
   * contains a btrfs filesystem.
   * </p><p>
   * </p>
   * @since 1.17.43
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
   * <p>
   * create a btrfs subvolume
   * </p><p>
   * Create a btrfs subvolume. The "dest" argument is the
   * destination directory and the name of the subvolume, in
   * the form /path/to/dest/name. The optional parameter
   * "qgroupid" represents the qgroup which the newly created
   * subvolume will be added to.
   * </p><p>
   * Optional arguments are supplied in the final
   * Map&lt;String,Object&gt; parameter, which is a hash of the
   * argument name to its value (cast to Object). Pass an
   * empty Map or null for no optional arguments.
   * </p><p>
   * </p>
   * @since 1.17.35
   * @throws LibGuestFSException
   */
  public void btrfs_subvolume_create (String dest, Map<String, Object> optargs)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("btrfs_subvolume_create: handle is closed");

    /* Unpack optional args. */
    Object _optobj;
    long _optargs_bitmask = 0;
    String qgroupid = "";
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("qgroupid");
    if (_optobj != null) {
      qgroupid = ((String) _optobj);
      _optargs_bitmask |= 1L;
    }

    _btrfs_subvolume_create (g, dest, _optargs_bitmask, qgroupid);
  }

  public void btrfs_subvolume_create (String dest)
    throws LibGuestFSException
  {
    btrfs_subvolume_create (dest, null);
  }

  public void btrfs_subvolume_create_opts (String dest, Map<String, Object> optargs)
    throws LibGuestFSException
  {
    btrfs_subvolume_create (dest, optargs);
  }

  public void btrfs_subvolume_create_opts (String dest)
    throws LibGuestFSException
  {
    btrfs_subvolume_create (dest, null);
  }

  private native void _btrfs_subvolume_create (long g, String dest, long _optargs_bitmask, String qgroupid)
    throws LibGuestFSException;

  /**
   * <p>
   * delete a btrfs subvolume or snapshot
   * </p><p>
   * Delete the named btrfs subvolume or snapshot.
   * </p><p>
   * </p>
   * @since 1.17.35
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
   * <p>
   * get the default subvolume or snapshot of a filesystem
   * </p><p>
   * Get the default subvolume or snapshot of a filesystem
   * mounted at "mountpoint".
   * </p><p>
   * </p>
   * @since 1.29.17
   * @throws LibGuestFSException
   */
  public long btrfs_subvolume_get_default (String fs)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("btrfs_subvolume_get_default: handle is closed");

    return _btrfs_subvolume_get_default (g, fs);
  }

  private native long _btrfs_subvolume_get_default (long g, String fs)
    throws LibGuestFSException;

  /**
   * <p>
   * list btrfs snapshots and subvolumes
   * </p><p>
   * List the btrfs snapshots and subvolumes of the btrfs
   * filesystem which is mounted at "fs".
   * </p><p>
   * </p>
   * @since 1.17.35
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
   * <p>
   * set default btrfs subvolume
   * </p><p>
   * Set the subvolume of the btrfs filesystem "fs" which
   * will be mounted by default. See "g.btrfs_subvolume_list"
   * to get a list of subvolumes.
   * </p><p>
   * </p>
   * @since 1.17.35
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
   * <p>
   * return detailed information of the subvolume
   * </p><p>
   * Return detailed information of the subvolume.
   * </p><p>
   * </p>
   * @since 1.29.17
   * @throws LibGuestFSException
   */
  public Map<String,String> btrfs_subvolume_show (String subvolume)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("btrfs_subvolume_show: handle is closed");

    String[] r = _btrfs_subvolume_show (g, subvolume);

    HashMap<String, String> rhash = new HashMap<String, String> ();
    for (int i = 0; i < r.length; i += 2)
      rhash.put (r[i], r[i+1]);
    return rhash;
  }

  private native String[] _btrfs_subvolume_show (long g, String subvolume)
    throws LibGuestFSException;

  /**
   * <p>
   * create a btrfs snapshot
   * </p><p>
   * Create a snapshot of the btrfs subvolume "source". The
   * "dest" argument is the destination directory and the
   * name of the snapshot, in the form /path/to/dest/name. By
   * default the newly created snapshot is writable, if the
   * value of optional parameter "ro" is true, then a
   * readonly snapshot is created. The optional parameter
   * "qgroupid" represents the qgroup which the newly created
   * snapshot will be added to.
   * </p><p>
   * Optional arguments are supplied in the final
   * Map&lt;String,Object&gt; parameter, which is a hash of the
   * argument name to its value (cast to Object). Pass an
   * empty Map or null for no optional arguments.
   * </p><p>
   * </p>
   * @since 1.17.35
   * @throws LibGuestFSException
   */
  public void btrfs_subvolume_snapshot (String source, String dest, Map<String, Object> optargs)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("btrfs_subvolume_snapshot: handle is closed");

    /* Unpack optional args. */
    Object _optobj;
    long _optargs_bitmask = 0;
    boolean ro = false;
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("ro");
    if (_optobj != null) {
      ro = ((Boolean) _optobj).booleanValue();
      _optargs_bitmask |= 1L;
    }
    String qgroupid = "";
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("qgroupid");
    if (_optobj != null) {
      qgroupid = ((String) _optobj);
      _optargs_bitmask |= 2L;
    }

    _btrfs_subvolume_snapshot (g, source, dest, _optargs_bitmask, ro, qgroupid);
  }

  public void btrfs_subvolume_snapshot (String source, String dest)
    throws LibGuestFSException
  {
    btrfs_subvolume_snapshot (source, dest, null);
  }

  public void btrfs_subvolume_snapshot_opts (String source, String dest, Map<String, Object> optargs)
    throws LibGuestFSException
  {
    btrfs_subvolume_snapshot (source, dest, optargs);
  }

  public void btrfs_subvolume_snapshot_opts (String source, String dest)
    throws LibGuestFSException
  {
    btrfs_subvolume_snapshot (source, dest, null);
  }

  private native void _btrfs_subvolume_snapshot (long g, String source, String dest, long _optargs_bitmask, boolean ro, String qgroupid)
    throws LibGuestFSException;

  /**
   * <p>
   * enable extended inode refs
   * </p><p>
   * This will Enable extended inode refs.
   * </p><p>
   * </p>
   * @since 1.29.29
   * @throws LibGuestFSException
   */
  public void btrfstune_enable_extended_inode_refs (String device)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("btrfstune_enable_extended_inode_refs: handle is closed");

    _btrfstune_enable_extended_inode_refs (g, device);
  }

  private native void _btrfstune_enable_extended_inode_refs (long g, String device)
    throws LibGuestFSException;

  /**
   * <p>
   * enable skinny metadata extent refs
   * </p><p>
   * This enable skinny metadata extent refs.
   * </p><p>
   * </p>
   * @since 1.29.29
   * @throws LibGuestFSException
   */
  public void btrfstune_enable_skinny_metadata_extent_refs (String device)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("btrfstune_enable_skinny_metadata_extent_refs: handle is closed");

    _btrfstune_enable_skinny_metadata_extent_refs (g, device);
  }

  private native void _btrfstune_enable_skinny_metadata_extent_refs (long g, String device)
    throws LibGuestFSException;

  /**
   * <p>
   * enable or disable seeding of a btrfs device
   * </p><p>
   * Enable seeding of a btrfs device, this will force a fs
   * readonly so that you can use it to build other
   * filesystems.
   * </p><p>
   * </p>
   * @since 1.29.29
   * @throws LibGuestFSException
   */
  public void btrfstune_seeding (String device, boolean seeding)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("btrfstune_seeding: handle is closed");

    _btrfstune_seeding (g, device, seeding);
  }

  private native void _btrfstune_seeding (long g, String device, boolean seeding)
    throws LibGuestFSException;

  /**
   * <p>
   * return the C pointer to the guestfs_h handle
   * </p><p>
   * In non-C language bindings, this allows you to retrieve
   * the underlying C pointer to the handle (ie. "g.h *").
   * The purpose of this is to allow other libraries to
   * interwork with libguestfs.
   * </p><p>
   * </p>
   * @since 1.29.17
   * @throws LibGuestFSException
   */
  public long c_pointer ()
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("c_pointer: handle is closed");

    return _c_pointer (g);
  }

  private native long _c_pointer (long g)
    throws LibGuestFSException;

  /**
   * <p>
   * return canonical device name
   * </p><p>
   * This utility function is useful when displaying device
   * names to the user. It takes a number of irregular device
   * names and returns them in a consistent format:
   * </p><p>
   * /dev/hdX
   * /dev/vdX
   * These are returned as /dev/sdX. Note this works for
   * device names and partition names. This is
   * approximately the reverse of the algorithm described
   * in "BLOCK DEVICE NAMING" in guestfs(3).
   * </p><p>
   * /dev/mapper/VG-LV
   * /dev/dm-N
   * Converted to /dev/VG/LV form using
   * "g.lvm_canonical_lv_name".
   * </p><p>
   * Other strings are returned unmodified.
   * </p><p>
   * </p>
   * @since 1.19.7
   * @throws LibGuestFSException
   */
  public String canonical_device_name (String device)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("canonical_device_name: handle is closed");

    return _canonical_device_name (g, device);
  }

  private native String _canonical_device_name (long g, String device)
    throws LibGuestFSException;

  /**
   * <p>
   * get the Linux capabilities attached to a file
   * </p><p>
   * This function returns the Linux capabilities attached to
   * "path". The capabilities set is returned in text form
   * (see cap_to_text(3)).
   * </p><p>
   * If no capabilities are attached to a file, an empty
   * string is returned.
   * </p><p>
   * </p>
   * @since 1.19.63
   * @throws LibGuestFSException
   */
  public String cap_get_file (String path)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("cap_get_file: handle is closed");

    return _cap_get_file (g, path);
  }

  private native String _cap_get_file (long g, String path)
    throws LibGuestFSException;

  /**
   * <p>
   * set the Linux capabilities attached to a file
   * </p><p>
   * This function sets the Linux capabilities attached to
   * "path". The capabilities set "cap" should be passed in
   * text form (see cap_from_text(3)).
   * </p><p>
   * </p>
   * @since 1.19.63
   * @throws LibGuestFSException
   */
  public void cap_set_file (String path, String cap)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("cap_set_file: handle is closed");

    _cap_set_file (g, path, cap);
  }

  private native void _cap_set_file (long g, String path, String cap)
    throws LibGuestFSException;

  /**
   * <p>
   * return true path on case-insensitive filesystem
   * </p><p>
   * This can be used to resolve case insensitive paths on a
   * filesystem which is case sensitive. The use case is to
   * resolve paths which you have read from Windows
   * configuration files or the Windows Registry, to the true
   * path.
   * </p><p>
   * The command handles a peculiarity of the Linux ntfs-3g
   * filesystem driver (and probably others), which is that
   * although the underlying filesystem is case-insensitive,
   * the driver exports the filesystem to Linux as
   * case-sensitive.
   * </p><p>
   * One consequence of this is that special directories such
   * as C:\windows may appear as /WINDOWS or /windows (or
   * other things) depending on the precise details of how
   * they were created. In Windows itself this would not be a
   * problem.
   * </p><p>
   * Bug or feature? You decide:
   * &lt;http://www.tuxera.com/community/ntfs-3g-faq/#posixfilen
   * ames1&gt;
   * </p><p>
   * "g.case_sensitive_path" attempts to resolve the true
   * case of each element in the path. It will return a
   * resolved path if either the full path or its parent
   * directory exists. If the parent directory exists but the
   * full path does not, the case of the parent directory
   * will be correctly resolved, and the remainder appended
   * unmodified. For example, if the file
   * "/Windows/System32/netkvm.sys" exists:
   * </p><p>
   * "g.case_sensitive_path" ("/windows/system32/netkvm.sys")
   * "Windows/System32/netkvm.sys"
   * </p><p>
   * "g.case_sensitive_path" ("/windows/system32/NoSuchFile")
   * "Windows/System32/NoSuchFile"
   * </p><p>
   * "g.case_sensitive_path" ("/windows/system33/netkvm.sys")
   * *ERROR*
   * </p><p>
   * *Note*: Because of the above behaviour,
   * "g.case_sensitive_path" cannot be used to check for the
   * existence of a file.
   * </p><p>
   * *Note*: This function does not handle drive names,
   * backslashes etc.
   * </p><p>
   * See also "g.realpath".
   * </p><p>
   * </p>
   * @since 1.0.75
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
   * <p>
   * list the contents of a file
   * </p><p>
   * Return the contents of the file named "path".
   * </p><p>
   * Because, in C, this function returns a "char *", there
   * is no way to differentiate between a "\0" character in a
   * file and end of string. To handle binary files, use the
   * "g.read_file" or "g.download" functions.
   * </p><p>
   * </p>
   * @since 0.4
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
   * <p>
   * compute MD5, SHAx or CRC checksum of file
   * </p><p>
   * This call computes the MD5, SHAx or CRC checksum of the
   * file named "path".
   * </p><p>
   * The type of checksum to compute is given by the
   * "csumtype" parameter which must have one of the
   * following values:
   * </p><p>
   * "crc"
   * Compute the cyclic redundancy check (CRC) specified
   * by POSIX for the "cksum" command.
   * </p><p>
   * "md5"
   * Compute the MD5 hash (using the "md5sum" program).
   * </p><p>
   * "sha1"
   * Compute the SHA1 hash (using the "sha1sum" program).
   * </p><p>
   * "sha224"
   * Compute the SHA224 hash (using the "sha224sum"
   * program).
   * </p><p>
   * "sha256"
   * Compute the SHA256 hash (using the "sha256sum"
   * program).
   * </p><p>
   * "sha384"
   * Compute the SHA384 hash (using the "sha384sum"
   * program).
   * </p><p>
   * "sha512"
   * Compute the SHA512 hash (using the "sha512sum"
   * program).
   * </p><p>
   * The checksum is returned as a printable string.
   * </p><p>
   * To get the checksum for a device, use
   * "g.checksum_device".
   * </p><p>
   * To get the checksums for many files, use
   * "g.checksums_out".
   * </p><p>
   * </p>
   * @since 1.0.2
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
   * <p>
   * compute MD5, SHAx or CRC checksum of the contents of a device
   * </p><p>
   * This call computes the MD5, SHAx or CRC checksum of the
   * contents of the device named "device". For the types of
   * checksums supported see the "g.checksum" command.
   * </p><p>
   * </p>
   * @since 1.3.2
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
   * <p>
   * compute MD5, SHAx or CRC checksum of files in a directory
   * </p><p>
   * This command computes the checksums of all regular files
   * in directory and then emits a list of those checksums to
   * the local output file "sumsfile".
   * </p><p>
   * This can be used for verifying the integrity of a
   * virtual machine. However to be properly secure you
   * should pay attention to the output of the checksum
   * command (it uses the ones from GNU coreutils). In
   * particular when the filename is not printable, coreutils
   * uses a special backslash syntax. For more information,
   * see the GNU coreutils info file.
   * </p><p>
   * </p>
   * @since 1.3.7
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
   * <p>
   * change file mode
   * </p><p>
   * Change the mode (permissions) of "path" to "mode". Only
   * numeric modes are supported.
   * </p><p>
   * *Note*: When using this command from guestfish, "mode"
   * by default would be decimal, unless you prefix it with 0
   * to get octal, ie. use 0700 not 700.
   * </p><p>
   * The mode actually set is affected by the umask.
   * </p><p>
   * </p>
   * @since 0.8
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
   * <p>
   * change file owner and group
   * </p><p>
   * Change the file owner to "owner" and group to "group".
   * </p><p>
   * Only numeric uid and gid are supported. If you want to
   * use names, you will need to locate and parse the
   * password file yourself (Augeas support makes this
   * relatively easy).
   * </p><p>
   * </p>
   * @since 0.8
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
   * <p>
   * remove a single per-backend settings string
   * </p><p>
   * If there is a backend setting string matching "name" or
   * beginning with "name=", then that string is removed from
   * the backend settings.
   * </p><p>
   * This call returns the number of strings which were
   * removed (which may be 0, 1 or greater than 1).
   * </p><p>
   * See "BACKEND" in guestfs(3), "BACKEND SETTINGS" in
   * guestfs(3).
   * </p><p>
   * </p>
   * @since 1.27.2
   * @throws LibGuestFSException
   */
  public int clear_backend_setting (String name)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("clear_backend_setting: handle is closed");

    return _clear_backend_setting (g, name);
  }

  private native int _clear_backend_setting (long g, String name)
    throws LibGuestFSException;

  /**
   * <p>
   * run a command from the guest filesystem
   * </p><p>
   * This call runs a command from the guest filesystem. The
   * filesystem must be mounted, and must contain a
   * compatible operating system (ie. something Linux, with
   * the same or compatible processor architecture).
   * </p><p>
   * The single parameter is an argv-style list of arguments.
   * The first element is the name of the program to run.
   * Subsequent elements are parameters. The list must be
   * non-empty (ie. must contain a program name). Note that
   * the command runs directly, and is *not* invoked via the
   * shell (see "g.sh").
   * </p><p>
   * The return value is anything printed to *stdout* by the
   * command.
   * </p><p>
   * If the command returns a non-zero exit status, then this
   * function returns an error message. The error message
   * string is the content of *stderr* from the command.
   * </p><p>
   * The $PATH environment variable will contain at least
   * /usr/bin and /bin. If you require a program from another
   * location, you should provide the full path in the first
   * parameter.
   * </p><p>
   * Shared libraries and data files required by the program
   * must be available on filesystems which are mounted in
   * the correct places. It is the caller's responsibility to
   * ensure all filesystems that are needed are mounted at
   * the right locations.
   * </p><p>
   * Because of the message protocol, there is a transfer
   * limit of somewhere between 2MB and 4MB. See "PROTOCOL
   * LIMITS" in guestfs(3).
   * </p><p>
   * </p>
   * @since 1.9.1
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
   * <p>
   * run a command, returning lines
   * </p><p>
   * This is the same as "g.command", but splits the result
   * into a list of lines.
   * </p><p>
   * See also: "g.sh_lines"
   * </p><p>
   * Because of the message protocol, there is a transfer
   * limit of somewhere between 2MB and 4MB. See "PROTOCOL
   * LIMITS" in guestfs(3).
   * </p><p>
   * </p>
   * @since 1.9.1
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
   * <p>
   * output compressed device
   * </p><p>
   * This command compresses "device" and writes it out to
   * the local file "zdevice".
   * </p><p>
   * The "ctype" and optional "level" parameters have the
   * same meaning as in "g.compress_out".
   * </p><p>
   * Optional arguments are supplied in the final
   * Map&lt;String,Object&gt; parameter, which is a hash of the
   * argument name to its value (cast to Object). Pass an
   * empty Map or null for no optional arguments.
   * </p><p>
   * </p>
   * @since 1.13.15
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
   * <p>
   * output compressed file
   * </p><p>
   * This command compresses file and writes it out to the
   * local file zfile.
   * </p><p>
   * The compression program used is controlled by the
   * "ctype" parameter. Currently this includes: "compress",
   * "gzip", "bzip2", "xz" or "lzop". Some compression types
   * may not be supported by particular builds of libguestfs,
   * in which case you will get an error containing the
   * substring "not supported".
   * </p><p>
   * The optional "level" parameter controls compression
   * level. The meaning and default for this parameter
   * depends on the compression program being used.
   * </p><p>
   * Optional arguments are supplied in the final
   * Map&lt;String,Object&gt; parameter, which is a hash of the
   * argument name to its value (cast to Object). Pass an
   * empty Map or null for no optional arguments.
   * </p><p>
   * </p>
   * @since 1.13.15
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
   * <p>
   * add hypervisor parameters
   * </p><p>
   * This can be used to add arbitrary hypervisor parameters
   * of the form *-param value*. Actually it's not quite
   * arbitrary - we prevent you from setting some parameters
   * which would interfere with parameters that we use.
   * </p><p>
   * The first character of "hvparam" string must be a "-"
   * (dash).
   * </p><p>
   * "hvvalue" can be NULL.
   * </p><p>
   * </p>
   * @since 0.3
   * @throws LibGuestFSException
   */
  public void config (String hvparam, String hvvalue)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("config: handle is closed");

    _config (g, hvparam, hvvalue);
  }

  private native void _config (long g, String hvparam, String hvvalue)
    throws LibGuestFSException;

  /**
   * <p>
   * copy the attributes of a path (file/directory) to another
   * </p><p>
   * Copy the attributes of a path (which can be a file or a
   * directory) to another path.
   * </p><p>
   * By default "no" attribute is copied, so make sure to
   * specify any (or "all" to copy everything).
   * </p><p>
   * The optional arguments specify which attributes can be
   * copied:
   * </p><p>
   * "mode"
   * Copy part of the file mode from "source" to
   * "destination". Only the UNIX permissions and the
   * sticky/setuid/setgid bits can be copied.
   * </p><p>
   * "xattributes"
   * Copy the Linux extended attributes (xattrs) from
   * "source" to "destination". This flag does nothing if
   * the *linuxxattrs* feature is not available (see
   * "g.feature_available").
   * </p><p>
   * "ownership"
   * Copy the owner uid and the group gid of "source" to
   * "destination".
   * </p><p>
   * "all"
   * Copy all the attributes from "source" to
   * "destination". Enabling it enables all the other
   * flags, if they are not specified already.
   * </p><p>
   * Optional arguments are supplied in the final
   * Map&lt;String,Object&gt; parameter, which is a hash of the
   * argument name to its value (cast to Object). Pass an
   * empty Map or null for no optional arguments.
   * </p><p>
   * </p>
   * @since 1.25.21
   * @throws LibGuestFSException
   */
  public void copy_attributes (String src, String dest, Map<String, Object> optargs)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("copy_attributes: handle is closed");

    /* Unpack optional args. */
    Object _optobj;
    long _optargs_bitmask = 0;
    boolean all = false;
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("all");
    if (_optobj != null) {
      all = ((Boolean) _optobj).booleanValue();
      _optargs_bitmask |= 1L;
    }
    boolean mode = false;
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("mode");
    if (_optobj != null) {
      mode = ((Boolean) _optobj).booleanValue();
      _optargs_bitmask |= 2L;
    }
    boolean xattributes = false;
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("xattributes");
    if (_optobj != null) {
      xattributes = ((Boolean) _optobj).booleanValue();
      _optargs_bitmask |= 4L;
    }
    boolean ownership = false;
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("ownership");
    if (_optobj != null) {
      ownership = ((Boolean) _optobj).booleanValue();
      _optargs_bitmask |= 8L;
    }

    _copy_attributes (g, src, dest, _optargs_bitmask, all, mode, xattributes, ownership);
  }

  public void copy_attributes (String src, String dest)
    throws LibGuestFSException
  {
    copy_attributes (src, dest, null);
  }

  private native void _copy_attributes (long g, String src, String dest, long _optargs_bitmask, boolean all, boolean mode, boolean xattributes, boolean ownership)
    throws LibGuestFSException;

  /**
   * <p>
   * copy from source device to destination device
   * </p><p>
   * The four calls "g.copy_device_to_device",
   * "g.copy_device_to_file", "g.copy_file_to_device", and
   * "g.copy_file_to_file" let you copy from a source
   * (device|file) to a destination (device|file).
   * </p><p>
   * Partial copies can be made since you can specify
   * optionally the source offset, destination offset and
   * size to copy. These values are all specified in bytes.
   * If not given, the offsets both default to zero, and the
   * size defaults to copying as much as possible until we
   * hit the end of the source.
   * </p><p>
   * The source and destination may be the same object.
   * However overlapping regions may not be copied correctly.
   * </p><p>
   * If the destination is a file, it is created if required.
   * If the destination file is not large enough, it is
   * extended.
   * </p><p>
   * If the destination is a file and the "append" flag is
   * not set, then the destination file is truncated. If the
   * "append" flag is set, then the copy appends to the
   * destination file. The "append" flag currently cannot be
   * set for devices.
   * </p><p>
   * If the "sparse" flag is true then the call avoids
   * writing blocks that contain only zeroes, which can help
   * in some situations where the backing disk is
   * thin-provisioned. Note that unless the target is already
   * zeroed, using this option will result in incorrect
   * copying.
   * </p><p>
   * Optional arguments are supplied in the final
   * Map&lt;String,Object&gt; parameter, which is a hash of the
   * argument name to its value (cast to Object). Pass an
   * empty Map or null for no optional arguments.
   * </p><p>
   * </p>
   * @since 1.13.25
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
    boolean sparse = false;
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("sparse");
    if (_optobj != null) {
      sparse = ((Boolean) _optobj).booleanValue();
      _optargs_bitmask |= 8L;
    }
    boolean append = false;
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("append");
    if (_optobj != null) {
      append = ((Boolean) _optobj).booleanValue();
      _optargs_bitmask |= 16L;
    }

    _copy_device_to_device (g, src, dest, _optargs_bitmask, srcoffset, destoffset, size, sparse, append);
  }

  public void copy_device_to_device (String src, String dest)
    throws LibGuestFSException
  {
    copy_device_to_device (src, dest, null);
  }

  private native void _copy_device_to_device (long g, String src, String dest, long _optargs_bitmask, long srcoffset, long destoffset, long size, boolean sparse, boolean append)
    throws LibGuestFSException;

  /**
   * <p>
   * copy from source device to destination file
   * </p><p>
   * See "g.copy_device_to_device" for a general overview of
   * this call.
   * </p><p>
   * Optional arguments are supplied in the final
   * Map&lt;String,Object&gt; parameter, which is a hash of the
   * argument name to its value (cast to Object). Pass an
   * empty Map or null for no optional arguments.
   * </p><p>
   * </p>
   * @since 1.13.25
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
    boolean sparse = false;
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("sparse");
    if (_optobj != null) {
      sparse = ((Boolean) _optobj).booleanValue();
      _optargs_bitmask |= 8L;
    }
    boolean append = false;
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("append");
    if (_optobj != null) {
      append = ((Boolean) _optobj).booleanValue();
      _optargs_bitmask |= 16L;
    }

    _copy_device_to_file (g, src, dest, _optargs_bitmask, srcoffset, destoffset, size, sparse, append);
  }

  public void copy_device_to_file (String src, String dest)
    throws LibGuestFSException
  {
    copy_device_to_file (src, dest, null);
  }

  private native void _copy_device_to_file (long g, String src, String dest, long _optargs_bitmask, long srcoffset, long destoffset, long size, boolean sparse, boolean append)
    throws LibGuestFSException;

  /**
   * <p>
   * copy from source file to destination device
   * </p><p>
   * See "g.copy_device_to_device" for a general overview of
   * this call.
   * </p><p>
   * Optional arguments are supplied in the final
   * Map&lt;String,Object&gt; parameter, which is a hash of the
   * argument name to its value (cast to Object). Pass an
   * empty Map or null for no optional arguments.
   * </p><p>
   * </p>
   * @since 1.13.25
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
    boolean sparse = false;
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("sparse");
    if (_optobj != null) {
      sparse = ((Boolean) _optobj).booleanValue();
      _optargs_bitmask |= 8L;
    }
    boolean append = false;
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("append");
    if (_optobj != null) {
      append = ((Boolean) _optobj).booleanValue();
      _optargs_bitmask |= 16L;
    }

    _copy_file_to_device (g, src, dest, _optargs_bitmask, srcoffset, destoffset, size, sparse, append);
  }

  public void copy_file_to_device (String src, String dest)
    throws LibGuestFSException
  {
    copy_file_to_device (src, dest, null);
  }

  private native void _copy_file_to_device (long g, String src, String dest, long _optargs_bitmask, long srcoffset, long destoffset, long size, boolean sparse, boolean append)
    throws LibGuestFSException;

  /**
   * <p>
   * copy from source file to destination file
   * </p><p>
   * See "g.copy_device_to_device" for a general overview of
   * this call.
   * </p><p>
   * This is not the function you want for copying files.
   * This is for copying blocks within existing files. See
   * "g.cp", "g.cp_a" and "g.mv" for general file copying and
   * moving functions.
   * </p><p>
   * Optional arguments are supplied in the final
   * Map&lt;String,Object&gt; parameter, which is a hash of the
   * argument name to its value (cast to Object). Pass an
   * empty Map or null for no optional arguments.
   * </p><p>
   * </p>
   * @since 1.13.25
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
    boolean sparse = false;
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("sparse");
    if (_optobj != null) {
      sparse = ((Boolean) _optobj).booleanValue();
      _optargs_bitmask |= 8L;
    }
    boolean append = false;
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("append");
    if (_optobj != null) {
      append = ((Boolean) _optobj).booleanValue();
      _optargs_bitmask |= 16L;
    }

    _copy_file_to_file (g, src, dest, _optargs_bitmask, srcoffset, destoffset, size, sparse, append);
  }

  public void copy_file_to_file (String src, String dest)
    throws LibGuestFSException
  {
    copy_file_to_file (src, dest, null);
  }

  private native void _copy_file_to_file (long g, String src, String dest, long _optargs_bitmask, long srcoffset, long destoffset, long size, boolean sparse, boolean append)
    throws LibGuestFSException;

  /**
   * <p>
   * copy local files or directories into an image
   * </p><p>
   * "g.copy_in" copies local files or directories
   * recursively into the disk image, placing them in the
   * directory called "remotedir" (which must exist).
   * </p><p>
   * Wildcards cannot be used.
   * </p><p>
   * </p>
   * @since 1.29.24
   * @throws LibGuestFSException
   */
  public void copy_in (String localpath, String remotedir)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("copy_in: handle is closed");

    _copy_in (g, localpath, remotedir);
  }

  private native void _copy_in (long g, String localpath, String remotedir)
    throws LibGuestFSException;

  /**
   * <p>
   * copy remote files or directories out of an image
   * </p><p>
   * "g.copy_out" copies remote files or directories
   * recursively out of the disk image, placing them on the
   * host disk in a local directory called "localdir" (which
   * must exist).
   * </p><p>
   * To download to the current directory, use "." as in:
   * </p><p>
   * C&lt;g.copy_out&gt; /home .
   * </p><p>
   * Wildcards cannot be used.
   * </p><p>
   * </p>
   * @since 1.29.24
   * @throws LibGuestFSException
   */
  public void copy_out (String remotepath, String localdir)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("copy_out: handle is closed");

    _copy_out (g, remotepath, localdir);
  }

  private native void _copy_out (long g, String remotepath, String localdir)
    throws LibGuestFSException;

  /**
   * <p>
   * copy size bytes from source to destination using dd
   * </p><p>
   * This command copies exactly "size" bytes from one source
   * device or file "src" to another destination device or
   * file "dest".
   * </p><p>
   * Note this will fail if the source is too short or if the
   * destination is not large enough.
   * </p><p>
   * </p>
   * @since 1.0.87
   * @deprecated In new code, use {@link #copy_device_to_device} instead
   * @throws LibGuestFSException
   */
  @Deprecated public void copy_size (String src, String dest, long size)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("copy_size: handle is closed");

    _copy_size (g, src, dest, size);
  }

  private native void _copy_size (long g, String src, String dest, long size)
    throws LibGuestFSException;

  /**
   * <p>
   * copy a file
   * </p><p>
   * This copies a file from "src" to "dest" where "dest" is
   * either a destination filename or destination directory.
   * </p><p>
   * </p>
   * @since 1.0.18
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
   * <p>
   * copy a file or directory recursively
   * </p><p>
   * This copies a file or directory from "src" to "dest"
   * recursively using the "cp -a" command.
   * </p><p>
   * </p>
   * @since 1.0.18
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
   * <p>
   * copy a file or directory recursively
   * </p><p>
   * This copies a file or directory from "src" to "dest"
   * recursively using the "cp -rP" command.
   * </p><p>
   * Most users should use "g.cp_a" instead. This command is
   * useful when you don't want to preserve permissions,
   * because the target filesystem does not support it
   * (primarily when writing to DOS FAT filesystems).
   * </p><p>
   * </p>
   * @since 1.21.38
   * @throws LibGuestFSException
   */
  public void cp_r (String src, String dest)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("cp_r: handle is closed");

    _cp_r (g, src, dest);
  }

  private native void _cp_r (long g, String src, String dest)
    throws LibGuestFSException;

  /**
   * <p>
   * pack directory into cpio file
   * </p><p>
   * This command packs the contents of directory and
   * downloads it to local file "cpiofile".
   * </p><p>
   * The optional "format" parameter can be used to select
   * the format. Only the following formats are currently
   * permitted:
   * </p><p>
   * "newc"
   * New (SVR4) portable format. This format happens to
   * be compatible with the cpio-like format used by the
   * Linux kernel for initramfs.
   * </p><p>
   * This is the default format.
   * </p><p>
   * "crc"
   * New (SVR4) portable format with a checksum.
   * </p><p>
   * Optional arguments are supplied in the final
   * Map&lt;String,Object&gt; parameter, which is a hash of the
   * argument name to its value (cast to Object). Pass an
   * empty Map or null for no optional arguments.
   * </p><p>
   * </p>
   * @since 1.27.9
   * @throws LibGuestFSException
   */
  public void cpio_out (String directory, String cpiofile, Map<String, Object> optargs)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("cpio_out: handle is closed");

    /* Unpack optional args. */
    Object _optobj;
    long _optargs_bitmask = 0;
    String format = "";
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("format");
    if (_optobj != null) {
      format = ((String) _optobj);
      _optargs_bitmask |= 1L;
    }

    _cpio_out (g, directory, cpiofile, _optargs_bitmask, format);
  }

  public void cpio_out (String directory, String cpiofile)
    throws LibGuestFSException
  {
    cpio_out (directory, cpiofile, null);
  }

  private native void _cpio_out (long g, String directory, String cpiofile, long _optargs_bitmask, String format)
    throws LibGuestFSException;

  /**
   * <p>
   * copy from source to destination using dd
   * </p><p>
   * This command copies from one source device or file "src"
   * to another destination device or file "dest". Normally
   * you would use this to copy to or from a device or
   * partition, for example to duplicate a filesystem.
   * </p><p>
   * If the destination is a device, it must be as large or
   * larger than the source file or device, otherwise the
   * copy will fail. This command cannot do partial copies
   * (see "g.copy_device_to_device").
   * </p><p>
   * </p>
   * @since 1.0.80
   * @deprecated In new code, use {@link #copy_device_to_device} instead
   * @throws LibGuestFSException
   */
  @Deprecated public void dd (String src, String dest)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("dd: handle is closed");

    _dd (g, src, dest);
  }

  private native void _dd (long g, String src, String dest)
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

  public String[] debug_drives ()
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("debug_drives: handle is closed");

    return _debug_drives (g);
  }

  private native String[] _debug_drives (long g)
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
   * <p>
   * convert device to index
   * </p><p>
   * This function takes a device name (eg. "/dev/sdb") and
   * returns the index of the device in the list of devices.
   * </p><p>
   * Index numbers start from 0. The named device must exist,
   * for example as a string returned from "g.list_devices".
   * </p><p>
   * See also "g.list_devices", "g.part_to_dev".
   * </p><p>
   * </p>
   * @since 1.19.7
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
   * <p>
   * report file system disk space usage
   * </p><p>
   * This command runs the "df" command to report disk space
   * used.
   * </p><p>
   * This command is mostly useful for interactive sessions.
   * It is *not* intended that you try to parse the output
   * string. Use "g.statvfs" from programs.
   * </p><p>
   * </p>
   * @since 1.0.54
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
   * <p>
   * report file system disk space usage (human readable)
   * </p><p>
   * This command runs the "df -h" command to report disk
   * space used in human-readable format.
   * </p><p>
   * This command is mostly useful for interactive sessions.
   * It is *not* intended that you try to parse the output
   * string. Use "g.statvfs" from programs.
   * </p><p>
   * </p>
   * @since 1.0.54
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
   * <p>
   * create a blank disk image
   * </p><p>
   * Create a blank disk image called filename (a host file)
   * with format "format" (usually "raw" or "qcow2"). The
   * size is "size" bytes.
   * </p><p>
   * If used with the optional "backingfile" parameter, then
   * a snapshot is created on top of the backing file. In
   * this case, "size" must be passed as -1. The size of the
   * snapshot is the same as the size of the backing file,
   * which is discovered automatically. You are encouraged to
   * also pass "backingformat" to describe the format of
   * "backingfile".
   * </p><p>
   * If filename refers to a block device, then the device is
   * formatted. The "size" is ignored since block devices
   * have an intrinsic size.
   * </p><p>
   * The other optional parameters are:
   * </p><p>
   * "preallocation"
   * If format is "raw", then this can be either "sparse"
   * or "full" to create a sparse or fully allocated file
   * respectively. The default is "sparse".
   * </p><p>
   * If format is "qcow2", then this can be either "off"
   * or "metadata". Preallocating metadata can be faster
   * when doing lots of writes, but uses more space. The
   * default is "off".
   * </p><p>
   * "compat"
   * "qcow2" only: Pass the string 1.1 to use the
   * advanced qcow2 format supported by qemu ≥ 1.1.
   * </p><p>
   * "clustersize"
   * "qcow2" only: Change the qcow2 cluster size. The
   * default is 65536 (bytes) and this setting may be any
   * power of two between 512 and 2097152.
   * </p><p>
   * Note that this call does not add the new disk to the
   * handle. You may need to call "g.add_drive_opts"
   * separately.
   * </p><p>
   * Optional arguments are supplied in the final
   * Map&lt;String,Object&gt; parameter, which is a hash of the
   * argument name to its value (cast to Object). Pass an
   * empty Map or null for no optional arguments.
   * </p><p>
   * </p>
   * @since 1.25.31
   * @throws LibGuestFSException
   */
  public void disk_create (String filename, String format, long size, Map<String, Object> optargs)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("disk_create: handle is closed");

    /* Unpack optional args. */
    Object _optobj;
    long _optargs_bitmask = 0;
    String backingfile = "";
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("backingfile");
    if (_optobj != null) {
      backingfile = ((String) _optobj);
      _optargs_bitmask |= 1L;
    }
    String backingformat = "";
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("backingformat");
    if (_optobj != null) {
      backingformat = ((String) _optobj);
      _optargs_bitmask |= 2L;
    }
    String preallocation = "";
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("preallocation");
    if (_optobj != null) {
      preallocation = ((String) _optobj);
      _optargs_bitmask |= 4L;
    }
    String compat = "";
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("compat");
    if (_optobj != null) {
      compat = ((String) _optobj);
      _optargs_bitmask |= 8L;
    }
    int clustersize = 0;
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("clustersize");
    if (_optobj != null) {
      clustersize = ((Integer) _optobj).intValue();
      _optargs_bitmask |= 16L;
    }

    _disk_create (g, filename, format, size, _optargs_bitmask, backingfile, backingformat, preallocation, compat, clustersize);
  }

  public void disk_create (String filename, String format, long size)
    throws LibGuestFSException
  {
    disk_create (filename, format, size, null);
  }

  private native void _disk_create (long g, String filename, String format, long size, long _optargs_bitmask, String backingfile, String backingformat, String preallocation, String compat, int clustersize)
    throws LibGuestFSException;

  /**
   * <p>
   * detect the disk format of a disk image
   * </p><p>
   * Detect and return the format of the disk image called
   * filename. filename can also be a host device, etc. If
   * the format of the image could not be detected, then
   * "unknown" is returned.
   * </p><p>
   * Note that detecting the disk format can be insecure
   * under some circumstances. See "CVE-2010-3851" in
   * guestfs(3).
   * </p><p>
   * See also: "DISK IMAGE FORMATS" in guestfs(3)
   * </p><p>
   * </p>
   * @since 1.19.38
   * @throws LibGuestFSException
   */
  public String disk_format (String filename)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("disk_format: handle is closed");

    return _disk_format (g, filename);
  }

  private native String _disk_format (long g, String filename)
    throws LibGuestFSException;

  /**
   * <p>
   * return whether disk has a backing file
   * </p><p>
   * Detect and return whether the disk image filename has a
   * backing file.
   * </p><p>
   * Note that detecting disk features can be insecure under
   * some circumstances. See "CVE-2010-3851" in guestfs(3).
   * </p><p>
   * </p>
   * @since 1.19.39
   * @throws LibGuestFSException
   */
  public boolean disk_has_backing_file (String filename)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("disk_has_backing_file: handle is closed");

    return _disk_has_backing_file (g, filename);
  }

  private native boolean _disk_has_backing_file (long g, String filename)
    throws LibGuestFSException;

  /**
   * <p>
   * return virtual size of a disk
   * </p><p>
   * Detect and return the virtual size in bytes of the disk
   * image called filename.
   * </p><p>
   * Note that detecting disk features can be insecure under
   * some circumstances. See "CVE-2010-3851" in guestfs(3).
   * </p><p>
   * </p>
   * @since 1.19.39
   * @throws LibGuestFSException
   */
  public long disk_virtual_size (String filename)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("disk_virtual_size: handle is closed");

    return _disk_virtual_size (g, filename);
  }

  private native long _disk_virtual_size (long g, String filename)
    throws LibGuestFSException;

  /**
   * <p>
   * return kernel messages
   * </p><p>
   * This returns the kernel messages ("dmesg" output) from
   * the guest kernel. This is sometimes useful for extended
   * debugging of problems.
   * </p><p>
   * Another way to get the same information is to enable
   * verbose messages with "g.set_verbose" or by setting the
   * environment variable "LIBGUESTFS_DEBUG=1" before running
   * the program.
   * </p><p>
   * </p>
   * @since 1.0.18
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
   * <p>
   * download a file to the local machine
   * </p><p>
   * Download file remotefilename and save it as filename on
   * the local machine.
   * </p><p>
   * filename can also be a named pipe.
   * </p><p>
   * See also "g.upload", "g.cat".
   * </p><p>
   * </p>
   * @since 1.0.2
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
   * <p>
   * download a file to the local machine with offset and size
   * </p><p>
   * Download file remotefilename and save it as filename on
   * the local machine.
   * </p><p>
   * remotefilename is read for "size" bytes starting at
   * "offset" (this region must be within the file or
   * device).
   * </p><p>
   * Note that there is no limit on the amount of data that
   * can be downloaded with this call, unlike with "g.pread",
   * and this call always reads the full amount unless an
   * error occurs.
   * </p><p>
   * See also "g.download", "g.pread".
   * </p><p>
   * </p>
   * @since 1.5.17
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
   * <p>
   * drop kernel page cache, dentries and inodes
   * </p><p>
   * This instructs the guest kernel to drop its page cache,
   * and/or dentries and inode caches. The parameter
   * "whattodrop" tells the kernel what precisely to drop,
   * see &lt;http://linux-mm.org/Drop_Caches&gt;
   * </p><p>
   * Setting "whattodrop" to 3 should drop everything.
   * </p><p>
   * This automatically calls sync(2) before the operation,
   * so that the maximum guest memory is freed.
   * </p><p>
   * </p>
   * @since 1.0.18
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
   * <p>
   * estimate file space usage
   * </p><p>
   * This command runs the "du -s" command to estimate file
   * space usage for "path".
   * </p><p>
   * "path" can be a file or a directory. If "path" is a
   * directory then the estimate includes the contents of the
   * directory and all subdirectories (recursively).
   * </p><p>
   * The result is the estimated size in *kilobytes* (ie.
   * units of 1024 bytes).
   * </p><p>
   * </p>
   * @since 1.0.54
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
   * <p>
   * check an ext2/ext3 filesystem
   * </p><p>
   * This runs the ext2/ext3 filesystem checker on "device".
   * It can take the following optional arguments:
   * </p><p>
   * "correct"
   * Automatically repair the file system. This option
   * will cause e2fsck to automatically fix any
   * filesystem problems that can be safely fixed without
   * human intervention.
   * </p><p>
   * This option may not be specified at the same time as
   * the "forceall" option.
   * </p><p>
   * "forceall"
   * Assume an answer of 'yes' to all questions; allows
   * e2fsck to be used non-interactively.
   * </p><p>
   * This option may not be specified at the same time as
   * the "correct" option.
   * </p><p>
   * Optional arguments are supplied in the final
   * Map&lt;String,Object&gt; parameter, which is a hash of the
   * argument name to its value (cast to Object). Pass an
   * empty Map or null for no optional arguments.
   * </p><p>
   * </p>
   * @since 1.15.17
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
   * <p>
   * check an ext2/ext3 filesystem
   * </p><p>
   * This runs "e2fsck -p -f device", ie. runs the ext2/ext3
   * filesystem checker on "device", noninteractively (*-p*),
   * even if the filesystem appears to be clean (*-f*).
   * </p><p>
   * </p>
   * @since 1.0.29
   * @deprecated In new code, use {@link #e2fsck} instead
   * @throws LibGuestFSException
   */
  @Deprecated public void e2fsck_f (String device)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("e2fsck_f: handle is closed");

    _e2fsck_f (g, device);
  }

  private native void _e2fsck_f (long g, String device)
    throws LibGuestFSException;

  /**
   * <p>
   * echo arguments back to the client
   * </p><p>
   * This command concatenates the list of "words" passed
   * with single spaces between them and returns the
   * resulting string.
   * </p><p>
   * You can use this command to test the connection through
   * to the daemon.
   * </p><p>
   * See also "g.ping_daemon".
   * </p><p>
   * </p>
   * @since 1.0.69
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
   * <p>
   * return lines matching a pattern
   * </p><p>
   * This calls the external "egrep" program and returns the
   * matching lines.
   * </p><p>
   * Because of the message protocol, there is a transfer
   * limit of somewhere between 2MB and 4MB. See "PROTOCOL
   * LIMITS" in guestfs(3).
   * </p><p>
   * </p>
   * @since 1.0.66
   * @deprecated In new code, use {@link #grep} instead
   * @throws LibGuestFSException
   */
  @Deprecated public String[] egrep (String regex, String path)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("egrep: handle is closed");

    return _egrep (g, regex, path);
  }

  private native String[] _egrep (long g, String regex, String path)
    throws LibGuestFSException;

  /**
   * <p>
   * return lines matching a pattern
   * </p><p>
   * This calls the external "egrep -i" program and returns
   * the matching lines.
   * </p><p>
   * Because of the message protocol, there is a transfer
   * limit of somewhere between 2MB and 4MB. See "PROTOCOL
   * LIMITS" in guestfs(3).
   * </p><p>
   * </p>
   * @since 1.0.66
   * @deprecated In new code, use {@link #grep} instead
   * @throws LibGuestFSException
   */
  @Deprecated public String[] egrepi (String regex, String path)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("egrepi: handle is closed");

    return _egrepi (g, regex, path);
  }

  private native String[] _egrepi (long g, String regex, String path)
    throws LibGuestFSException;

  /**
   * <p>
   * test if two files have equal contents
   * </p><p>
   * This compares the two files file1 and file2 and returns
   * true if their content is exactly equal, or false
   * otherwise.
   * </p><p>
   * The external cmp(1) program is used for the comparison.
   * </p><p>
   * </p>
   * @since 1.0.18
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
   * <p>
   * test if file or directory exists
   * </p><p>
   * This returns "true" if and only if there is a file,
   * directory (or anything) with the given "path" name.
   * </p><p>
   * See also "g.is_file", "g.is_dir", "g.stat".
   * </p><p>
   * </p>
   * @since 0.8
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
   * <p>
   * install the SYSLINUX bootloader on an ext2/3/4 or btrfs filesystem
   * </p><p>
   * Install the SYSLINUX bootloader on the device mounted at
   * directory. Unlike "g.syslinux" which requires a FAT
   * filesystem, this can be used on an ext2/3/4 or btrfs
   * filesystem.
   * </p><p>
   * The directory parameter can be either a mountpoint, or a
   * directory within the mountpoint.
   * </p><p>
   * You also have to mark the partition as "active"
   * ("g.part_set_bootable") and a Master Boot Record must be
   * installed (eg. using "g.pwrite_device") on the first
   * sector of the whole disk. The SYSLINUX package comes
   * with some suitable Master Boot Records. See the
   * extlinux(1) man page for further information.
   * </p><p>
   * Additional configuration can be supplied to SYSLINUX by
   * placing a file called extlinux.conf on the filesystem
   * under directory. For further information about the
   * contents of this file, see extlinux(1).
   * </p><p>
   * See also "g.syslinux".
   * </p><p>
   * </p>
   * @since 1.21.27
   * @throws LibGuestFSException
   */
  public void extlinux (String directory)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("extlinux: handle is closed");

    _extlinux (g, directory);
  }

  private native void _extlinux (long g, String directory)
    throws LibGuestFSException;

  /**
   * <p>
   * preallocate a file in the guest filesystem
   * </p><p>
   * This command preallocates a file (containing zero bytes)
   * named "path" of size "len" bytes. If the file exists
   * already, it is overwritten.
   * </p><p>
   * Do not confuse this with the guestfish-specific "alloc"
   * command which allocates a file in the host and attaches
   * it as a device.
   * </p><p>
   * </p>
   * @since 1.0.66
   * @deprecated In new code, use {@link #fallocate64} instead
   * @throws LibGuestFSException
   */
  @Deprecated public void fallocate (String path, int len)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("fallocate: handle is closed");

    _fallocate (g, path, len);
  }

  private native void _fallocate (long g, String path, int len)
    throws LibGuestFSException;

  /**
   * <p>
   * preallocate a file in the guest filesystem
   * </p><p>
   * This command preallocates a file (containing zero bytes)
   * named "path" of size "len" bytes. If the file exists
   * already, it is overwritten.
   * </p><p>
   * Note that this call allocates disk blocks for the file.
   * To create a sparse file use "g.truncate_size" instead.
   * </p><p>
   * The deprecated call "g.fallocate" does the same, but
   * owing to an oversight it only allowed 30 bit lengths to
   * be specified, effectively limiting the maximum size of
   * files created through that call to 1GB.
   * </p><p>
   * Do not confuse this with the guestfish-specific "alloc"
   * and "sparse" commands which create a file in the host
   * and attach it as a device.
   * </p><p>
   * </p>
   * @since 1.3.17
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
   * <p>
   * test availability of some parts of the API
   * </p><p>
   * This is the same as "g.available", but unlike that call
   * it returns a simple true/false boolean result, instead
   * of throwing an exception if a feature is not found. For
   * other documentation see "g.available".
   * </p><p>
   * </p>
   * @since 1.21.26
   * @throws LibGuestFSException
   */
  public boolean feature_available (String[] groups)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("feature_available: handle is closed");

    return _feature_available (g, groups);
  }

  private native boolean _feature_available (long g, String[] groups)
    throws LibGuestFSException;

  /**
   * <p>
   * return lines matching a pattern
   * </p><p>
   * This calls the external "fgrep" program and returns the
   * matching lines.
   * </p><p>
   * Because of the message protocol, there is a transfer
   * limit of somewhere between 2MB and 4MB. See "PROTOCOL
   * LIMITS" in guestfs(3).
   * </p><p>
   * </p>
   * @since 1.0.66
   * @deprecated In new code, use {@link #grep} instead
   * @throws LibGuestFSException
   */
  @Deprecated public String[] fgrep (String pattern, String path)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("fgrep: handle is closed");

    return _fgrep (g, pattern, path);
  }

  private native String[] _fgrep (long g, String pattern, String path)
    throws LibGuestFSException;

  /**
   * <p>
   * return lines matching a pattern
   * </p><p>
   * This calls the external "fgrep -i" program and returns
   * the matching lines.
   * </p><p>
   * Because of the message protocol, there is a transfer
   * limit of somewhere between 2MB and 4MB. See "PROTOCOL
   * LIMITS" in guestfs(3).
   * </p><p>
   * </p>
   * @since 1.0.66
   * @deprecated In new code, use {@link #grep} instead
   * @throws LibGuestFSException
   */
  @Deprecated public String[] fgrepi (String pattern, String path)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("fgrepi: handle is closed");

    return _fgrepi (g, pattern, path);
  }

  private native String[] _fgrepi (long g, String pattern, String path)
    throws LibGuestFSException;

  /**
   * <p>
   * determine file type
   * </p><p>
   * This call uses the standard file(1) command to determine
   * the type or contents of the file.
   * </p><p>
   * This call will also transparently look inside various
   * types of compressed file.
   * </p><p>
   * The exact command which runs is "file -zb path". Note in
   * particular that the filename is not prepended to the
   * output (the *-b* option).
   * </p><p>
   * The output depends on the output of the underlying
   * file(1) command and it can change in future in ways
   * beyond our control. In other words, the output is not
   * guaranteed by the ABI.
   * </p><p>
   * See also: file(1), "g.vfs_type", "g.lstat", "g.is_file",
   * "g.is_blockdev" (etc), "g.is_zero".
   * </p><p>
   * </p>
   * @since 1.9.1
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
   * <p>
   * detect the architecture of a binary file
   * </p><p>
   * This detects the architecture of the binary filename,
   * and returns it if known.
   * </p><p>
   * Currently defined architectures are:
   * </p><p>
   * "i386"
   * This string is returned for all 32 bit i386, i486,
   * i586, i686 binaries irrespective of the precise
   * processor requirements of the binary.
   * </p><p>
   * "x86_64"
   * 64 bit x86-64.
   * </p><p>
   * "sparc"
   * 32 bit SPARC.
   * </p><p>
   * "sparc64"
   * 64 bit SPARC V9 and above.
   * </p><p>
   * "ia64"
   * Intel Itanium.
   * </p><p>
   * "ppc"
   * 32 bit Power PC.
   * </p><p>
   * "ppc64"
   * 64 bit Power PC.
   * </p><p>
   * "arm"
   * 32 bit ARM.
   * </p><p>
   * "aarch64"
   * 64 bit ARM.
   * </p><p>
   * Libguestfs may return other architecture strings in
   * future.
   * </p><p>
   * The function works on at least the following types of
   * files:
   * </p><p>
   * *   many types of Un*x and Linux binary
   * </p><p>
   * *   many types of Un*x and Linux shared library
   * </p><p>
   * *   Windows Win32 and Win64 binaries
   * </p><p>
   * *   Windows Win32 and Win64 DLLs
   * </p><p>
   * Win32 binaries and DLLs return "i386".
   * </p><p>
   * Win64 binaries and DLLs return "x86_64".
   * </p><p>
   * *   Linux kernel modules
   * </p><p>
   * *   Linux new-style initrd images
   * </p><p>
   * *   some non-x86 Linux vmlinuz kernels
   * </p><p>
   * What it can't do currently:
   * </p><p>
   * *   static libraries (libfoo.a)
   * </p><p>
   * *   Linux old-style initrd as compressed ext2 filesystem
   * (RHEL 3)
   * </p><p>
   * *   x86 Linux vmlinuz kernels
   * </p><p>
   * x86 vmlinuz images (bzImage format) consist of a mix
   * of 16-, 32- and compressed code, and are horribly
   * hard to unpack. If you want to find the architecture
   * of a kernel, use the architecture of the associated
   * initrd or kernel module(s) instead.
   * </p><p>
   * </p>
   * @since 1.5.3
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
   * <p>
   * return the size of the file in bytes
   * </p><p>
   * This command returns the size of file in bytes.
   * </p><p>
   * To get other stats about a file, use "g.stat",
   * "g.lstat", "g.is_dir", "g.is_file" etc. To get the size
   * of block devices, use "g.blockdev_getsize64".
   * </p><p>
   * </p>
   * @since 1.0.82
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
   * <p>
   * check if filesystem is available
   * </p><p>
   * Check whether libguestfs supports the named filesystem.
   * The argument "filesystem" is a filesystem name, such as
   * "ext3".
   * </p><p>
   * You must call "g.launch" before using this command.
   * </p><p>
   * This is mainly useful as a negative test. If this
   * returns true, it doesn't mean that a particular
   * filesystem can be created or mounted, since filesystems
   * can fail for other reasons such as it being a later
   * version of the filesystem, or having incompatible
   * features, or lacking the right mkfs.&lt;*fs*&gt; tool.
   * </p><p>
   * See also "g.available", "g.feature_available",
   * "AVAILABILITY" in guestfs(3).
   * </p><p>
   * </p>
   * @since 1.19.5
   * @throws LibGuestFSException
   */
  public boolean filesystem_available (String filesystem)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("filesystem_available: handle is closed");

    return _filesystem_available (g, filesystem);
  }

  private native boolean _filesystem_available (long g, String filesystem)
    throws LibGuestFSException;

  /**
   * <p>
   * fill a file with octets
   * </p><p>
   * This command creates a new file called "path". The
   * initial content of the file is "len" octets of "c",
   * where "c" must be a number in the range "[0..255]".
   * </p><p>
   * To fill a file with zero bytes (sparsely), it is much
   * more efficient to use "g.truncate_size". To create a
   * file with a pattern of repeating bytes use
   * "g.fill_pattern".
   * </p><p>
   * </p>
   * @since 1.0.79
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
   * <p>
   * fill a directory with empty files
   * </p><p>
   * This function, useful for testing filesystems, creates
   * "nr" empty files in the directory "dir" with names
   * 00000000 through "nr-1" (ie. each file name is 8 digits
   * long padded with zeroes).
   * </p><p>
   * </p>
   * @since 1.19.32
   * @throws LibGuestFSException
   */
  public void fill_dir (String dir, int nr)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("fill_dir: handle is closed");

    _fill_dir (g, dir, nr);
  }

  private native void _fill_dir (long g, String dir, int nr)
    throws LibGuestFSException;

  /**
   * <p>
   * fill a file with a repeating pattern of bytes
   * </p><p>
   * This function is like "g.fill" except that it creates a
   * new file of length "len" containing the repeating
   * pattern of bytes in "pattern". The pattern is truncated
   * if necessary to ensure the length of the file is exactly
   * "len" bytes.
   * </p><p>
   * </p>
   * @since 1.3.12
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
   * <p>
   * find all files and directories
   * </p><p>
   * This command lists out all files and directories,
   * recursively, starting at directory. It is essentially
   * equivalent to running the shell command "find directory
   * -print" but some post-processing happens on the output,
   * described below.
   * </p><p>
   * This returns a list of strings *without any prefix*.
   * Thus if the directory structure was:
   * </p><p>
   * /tmp/a
   * /tmp/b
   * /tmp/c/d
   * </p><p>
   * then the returned list from "g.find" /tmp would be 4
   * elements:
   * </p><p>
   * a
   * b
   * c
   * c/d
   * </p><p>
   * If directory is not a directory, then this command
   * returns an error.
   * </p><p>
   * The returned list is sorted.
   * </p><p>
   * </p>
   * @since 1.0.27
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
   * <p>
   * find all files and directories, returning NUL-separated list
   * </p><p>
   * This command lists out all files and directories,
   * recursively, starting at directory, placing the
   * resulting list in the external file called files.
   * </p><p>
   * This command works the same way as "g.find" with the
   * following exceptions:
   * </p><p>
   * *   The resulting list is written to an external file.
   * </p><p>
   * *   Items (filenames) in the result are separated by
   * "\0" characters. See find(1) option *-print0*.
   * </p><p>
   * *   The result list is not sorted.
   * </p><p>
   * </p>
   * @since 1.0.74
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
   * <p>
   * find a filesystem by label
   * </p><p>
   * This command searches the filesystems and returns the
   * one which has the given label. An error is returned if
   * no such filesystem can be found.
   * </p><p>
   * To find the label of a filesystem, use "g.vfs_label".
   * </p><p>
   * </p>
   * @since 1.5.3
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
   * <p>
   * find a filesystem by UUID
   * </p><p>
   * This command searches the filesystems and returns the
   * one which has the given UUID. An error is returned if no
   * such filesystem can be found.
   * </p><p>
   * To find the UUID of a filesystem, use "g.vfs_uuid".
   * </p><p>
   * </p>
   * @since 1.5.3
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
   * <p>
   * run the filesystem checker
   * </p><p>
   * This runs the filesystem checker (fsck) on "device"
   * which should have filesystem type "fstype".
   * </p><p>
   * The returned integer is the status. See fsck(8) for the
   * list of status codes from "fsck".
   * </p><p>
   * Notes:
   * </p><p>
   * *   Multiple status codes can be summed together.
   * </p><p>
   * *   A non-zero return code can mean "success", for
   * example if errors have been corrected on the
   * filesystem.
   * </p><p>
   * *   Checking or repairing NTFS volumes is not supported
   * (by linux-ntfs).
   * </p><p>
   * This command is entirely equivalent to running "fsck -a
   * -t fstype device".
   * </p><p>
   * </p>
   * @since 1.0.16
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
   * <p>
   * trim free space in a filesystem
   * </p><p>
   * Trim the free space in the filesystem mounted on
   * "mountpoint". The filesystem must be mounted read-write.
   * </p><p>
   * The filesystem contents are not affected, but any free
   * space in the filesystem is "trimmed", that is, given
   * back to the host device, thus making disk images more
   * sparse, allowing unused space in qcow2 files to be
   * reused, etc.
   * </p><p>
   * This operation requires support in libguestfs, the
   * mounted filesystem, the host filesystem, qemu and the
   * host kernel. If this support isn't present it may give
   * an error or even appear to run but do nothing.
   * </p><p>
   * See also "g.zero_free_space". That is a slightly
   * different operation that turns free space in the
   * filesystem into zeroes. It is valid to call "g.fstrim"
   * either instead of, or after calling "g.zero_free_space".
   * </p><p>
   * Optional arguments are supplied in the final
   * Map&lt;String,Object&gt; parameter, which is a hash of the
   * argument name to its value (cast to Object). Pass an
   * empty Map or null for no optional arguments.
   * </p><p>
   * </p>
   * @since 1.19.6
   * @throws LibGuestFSException
   */
  public void fstrim (String mountpoint, Map<String, Object> optargs)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("fstrim: handle is closed");

    /* Unpack optional args. */
    Object _optobj;
    long _optargs_bitmask = 0;
    long offset = 0;
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("offset");
    if (_optobj != null) {
      offset = ((Long) _optobj).longValue();
      _optargs_bitmask |= 1L;
    }
    long length = 0;
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("length");
    if (_optobj != null) {
      length = ((Long) _optobj).longValue();
      _optargs_bitmask |= 2L;
    }
    long minimumfreeextent = 0;
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("minimumfreeextent");
    if (_optobj != null) {
      minimumfreeextent = ((Long) _optobj).longValue();
      _optargs_bitmask |= 4L;
    }

    _fstrim (g, mountpoint, _optargs_bitmask, offset, length, minimumfreeextent);
  }

  public void fstrim (String mountpoint)
    throws LibGuestFSException
  {
    fstrim (mountpoint, null);
  }

  private native void _fstrim (long g, String mountpoint, long _optargs_bitmask, long offset, long length, long minimumfreeextent)
    throws LibGuestFSException;

  /**
   * <p>
   * get the additional kernel options
   * </p><p>
   * Return the additional kernel options which are added to
   * the libguestfs appliance kernel command line.
   * </p><p>
   * If "NULL" then no options are added.
   * </p><p>
   * </p>
   * @since 1.0.26
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
   * <p>
   * get the backend
   * </p><p>
   * Return the current backend.
   * </p><p>
   * See "g.set_backend" and "BACKEND" in guestfs(3).
   * </p><p>
   * </p>
   * @since 1.9.8
   * @deprecated In new code, use {@link #get_backend} instead
   * @throws LibGuestFSException
   */
  @Deprecated public String get_attach_method ()
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("get_attach_method: handle is closed");

    return _get_attach_method (g);
  }

  private native String _get_attach_method (long g)
    throws LibGuestFSException;

  /**
   * <p>
   * get autosync mode
   * </p><p>
   * Get the autosync flag.
   * </p><p>
   * </p>
   * @since 0.3
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
   * <p>
   * get the backend
   * </p><p>
   * Return the current backend.
   * </p><p>
   * This handle property was previously called the "attach
   * method".
   * </p><p>
   * See "g.set_backend" and "BACKEND" in guestfs(3).
   * </p><p>
   * </p>
   * @since 1.21.26
   * @throws LibGuestFSException
   */
  public String get_backend ()
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("get_backend: handle is closed");

    return _get_backend (g);
  }

  private native String _get_backend (long g)
    throws LibGuestFSException;

  /**
   * <p>
   * get a single per-backend settings string
   * </p><p>
   * Find a backend setting string which is either "name" or
   * begins with "name=". If "name", this returns the string
   * "1". If "name=", this returns the part after the equals
   * sign (which may be an empty string).
   * </p><p>
   * If no such setting is found, this function throws an
   * error. The errno (see "g.last_errno") will be "ESRCH" in
   * this case.
   * </p><p>
   * See "BACKEND" in guestfs(3), "BACKEND SETTINGS" in
   * guestfs(3).
   * </p><p>
   * </p>
   * @since 1.27.2
   * @throws LibGuestFSException
   */
  public String get_backend_setting (String name)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("get_backend_setting: handle is closed");

    return _get_backend_setting (g, name);
  }

  private native String _get_backend_setting (long g, String name)
    throws LibGuestFSException;

  /**
   * <p>
   * get per-backend settings
   * </p><p>
   * Return the current backend settings.
   * </p><p>
   * This call returns all backend settings strings. If you
   * want to find a single backend setting, see
   * "g.get_backend_setting".
   * </p><p>
   * See "BACKEND" in guestfs(3), "BACKEND SETTINGS" in
   * guestfs(3).
   * </p><p>
   * </p>
   * @since 1.25.24
   * @throws LibGuestFSException
   */
  public String[] get_backend_settings ()
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("get_backend_settings: handle is closed");

    return _get_backend_settings (g);
  }

  private native String[] _get_backend_settings (long g)
    throws LibGuestFSException;

  /**
   * <p>
   * get the appliance cache directory
   * </p><p>
   * Get the directory used by the handle to store the
   * appliance cache.
   * </p><p>
   * </p>
   * @since 1.19.58
   * @throws LibGuestFSException
   */
  public String get_cachedir ()
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("get_cachedir: handle is closed");

    return _get_cachedir (g);
  }

  private native String _get_cachedir (long g)
    throws LibGuestFSException;

  /**
   * <p>
   * get direct appliance mode flag
   * </p><p>
   * Return the direct appliance mode flag.
   * </p><p>
   * </p>
   * @since 1.0.72
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
   * <p>
   * get ext2 file attributes of a file
   * </p><p>
   * This returns the file attributes associated with file.
   * </p><p>
   * The attributes are a set of bits associated with each
   * inode which affect the behaviour of the file. The
   * attributes are returned as a string of letters
   * (described below). The string may be empty, indicating
   * that no file attributes are set for this file.
   * </p><p>
   * These attributes are only present when the file is
   * located on an ext2/3/4 filesystem. Using this call on
   * other filesystem types will result in an error.
   * </p><p>
   * The characters (file attributes) in the returned string
   * are currently:
   * </p><p>
   * 'A' When the file is accessed, its atime is not
   * modified.
   * </p><p>
   * 'a' The file is append-only.
   * </p><p>
   * 'c' The file is compressed on-disk.
   * </p><p>
   * 'D' (Directories only.) Changes to this directory are
   * written synchronously to disk.
   * </p><p>
   * 'd' The file is not a candidate for backup (see
   * dump(8)).
   * </p><p>
   * 'E' The file has compression errors.
   * </p><p>
   * 'e' The file is using extents.
   * </p><p>
   * 'h' The file is storing its blocks in units of the
   * filesystem blocksize instead of sectors.
   * </p><p>
   * 'I' (Directories only.) The directory is using hashed
   * trees.
   * </p><p>
   * 'i' The file is immutable. It cannot be modified,
   * deleted or renamed. No link can be created to this
   * file.
   * </p><p>
   * 'j' The file is data-journaled.
   * </p><p>
   * 's' When the file is deleted, all its blocks will be
   * zeroed.
   * </p><p>
   * 'S' Changes to this file are written synchronously to
   * disk.
   * </p><p>
   * 'T' (Directories only.) This is a hint to the block
   * allocator that subdirectories contained in this
   * directory should be spread across blocks. If not
   * present, the block allocator will try to group
   * subdirectories together.
   * </p><p>
   * 't' For a file, this disables tail-merging. (Not used by
   * upstream implementations of ext2.)
   * </p><p>
   * 'u' When the file is deleted, its blocks will be saved,
   * allowing the file to be undeleted.
   * </p><p>
   * 'X' The raw contents of the compressed file may be
   * accessed.
   * </p><p>
   * 'Z' The compressed file is dirty.
   * </p><p>
   * More file attributes may be added to this list later.
   * Not all file attributes may be set for all kinds of
   * files. For detailed information, consult the chattr(1)
   * man page.
   * </p><p>
   * See also "g.set_e2attrs".
   * </p><p>
   * Don't confuse these attributes with extended attributes
   * (see "g.getxattr").
   * </p><p>
   * </p>
   * @since 1.17.31
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
   * <p>
   * get ext2 file generation of a file
   * </p><p>
   * This returns the ext2 file generation of a file. The
   * generation (which used to be called the "version") is a
   * number associated with an inode. This is most commonly
   * used by NFS servers.
   * </p><p>
   * The generation is only present when the file is located
   * on an ext2/3/4 filesystem. Using this call on other
   * filesystem types will result in an error.
   * </p><p>
   * See "g.set_e2generation".
   * </p><p>
   * </p>
   * @since 1.17.31
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
   * <p>
   * get the ext2/3/4 filesystem label
   * </p><p>
   * This returns the ext2/3/4 filesystem label of the
   * filesystem on "device".
   * </p><p>
   * </p>
   * @since 1.0.15
   * @deprecated In new code, use {@link #vfs_label} instead
   * @throws LibGuestFSException
   */
  @Deprecated public String get_e2label (String device)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("get_e2label: handle is closed");

    return _get_e2label (g, device);
  }

  private native String _get_e2label (long g, String device)
    throws LibGuestFSException;

  /**
   * <p>
   * get the ext2/3/4 filesystem UUID
   * </p><p>
   * This returns the ext2/3/4 filesystem UUID of the
   * filesystem on "device".
   * </p><p>
   * </p>
   * @since 1.0.15
   * @deprecated In new code, use {@link #vfs_uuid} instead
   * @throws LibGuestFSException
   */
  @Deprecated public String get_e2uuid (String device)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("get_e2uuid: handle is closed");

    return _get_e2uuid (g, device);
  }

  private native String _get_e2uuid (long g, String device)
    throws LibGuestFSException;

  /**
   * <p>
   * get the hypervisor binary
   * </p><p>
   * Return the current hypervisor binary.
   * </p><p>
   * This is always non-NULL. If it wasn't set already, then
   * this will return the default qemu binary name.
   * </p><p>
   * </p>
   * @since 1.23.17
   * @throws LibGuestFSException
   */
  public String get_hv ()
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("get_hv: handle is closed");

    return _get_hv (g);
  }

  private native String _get_hv (long g)
    throws LibGuestFSException;

  /**
   * <p>
   * challenge of i'th requested credential
   * </p><p>
   * Get the challenge (provided by libvirt) for the
   * "index"'th requested credential. If libvirt did not
   * provide a challenge, this returns the empty string "".
   * </p><p>
   * See "LIBVIRT AUTHENTICATION" in guestfs(3) for
   * documentation and example code.
   * </p><p>
   * </p>
   * @since 1.19.52
   * @throws LibGuestFSException
   */
  public String get_libvirt_requested_credential_challenge (int index)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("get_libvirt_requested_credential_challenge: handle is closed");

    return _get_libvirt_requested_credential_challenge (g, index);
  }

  private native String _get_libvirt_requested_credential_challenge (long g, int index)
    throws LibGuestFSException;

  /**
   * <p>
   * default result of i'th requested credential
   * </p><p>
   * Get the default result (provided by libvirt) for the
   * "index"'th requested credential. If libvirt did not
   * provide a default result, this returns the empty string
   * "".
   * </p><p>
   * See "LIBVIRT AUTHENTICATION" in guestfs(3) for
   * documentation and example code.
   * </p><p>
   * </p>
   * @since 1.19.52
   * @throws LibGuestFSException
   */
  public String get_libvirt_requested_credential_defresult (int index)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("get_libvirt_requested_credential_defresult: handle is closed");

    return _get_libvirt_requested_credential_defresult (g, index);
  }

  private native String _get_libvirt_requested_credential_defresult (long g, int index)
    throws LibGuestFSException;

  /**
   * <p>
   * prompt of i'th requested credential
   * </p><p>
   * Get the prompt (provided by libvirt) for the "index"'th
   * requested credential. If libvirt did not provide a
   * prompt, this returns the empty string "".
   * </p><p>
   * See "LIBVIRT AUTHENTICATION" in guestfs(3) for
   * documentation and example code.
   * </p><p>
   * </p>
   * @since 1.19.52
   * @throws LibGuestFSException
   */
  public String get_libvirt_requested_credential_prompt (int index)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("get_libvirt_requested_credential_prompt: handle is closed");

    return _get_libvirt_requested_credential_prompt (g, index);
  }

  private native String _get_libvirt_requested_credential_prompt (long g, int index)
    throws LibGuestFSException;

  /**
   * <p>
   * get list of credentials requested by libvirt
   * </p><p>
   * This should only be called during the event callback for
   * events of type "GUESTFS_EVENT_LIBVIRT_AUTH".
   * </p><p>
   * Return the list of credentials requested by libvirt.
   * Possible values are a subset of the strings provided
   * when you called "g.set_libvirt_supported_credentials".
   * </p><p>
   * See "LIBVIRT AUTHENTICATION" in guestfs(3) for
   * documentation and example code.
   * </p><p>
   * </p>
   * @since 1.19.52
   * @throws LibGuestFSException
   */
  public String[] get_libvirt_requested_credentials ()
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("get_libvirt_requested_credentials: handle is closed");

    return _get_libvirt_requested_credentials (g);
  }

  private native String[] _get_libvirt_requested_credentials (long g)
    throws LibGuestFSException;

  /**
   * <p>
   * get memory allocated to the hypervisor
   * </p><p>
   * This gets the memory size in megabytes allocated to the
   * hypervisor.
   * </p><p>
   * If "g.set_memsize" was not called on this handle, and if
   * "LIBGUESTFS_MEMSIZE" was not set, then this returns the
   * compiled-in default value for memsize.
   * </p><p>
   * For more information on the architecture of libguestfs,
   * see guestfs(3).
   * </p><p>
   * </p>
   * @since 1.0.55
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
   * <p>
   * get enable network flag
   * </p><p>
   * This returns the enable network flag.
   * </p><p>
   * </p>
   * @since 1.5.4
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
   * <p>
   * get the search path
   * </p><p>
   * Return the current search path.
   * </p><p>
   * This is always non-NULL. If it wasn't set already, then
   * this will return the default path.
   * </p><p>
   * </p>
   * @since 0.3
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
   * <p>
   * get process group flag
   * </p><p>
   * This returns the process group flag.
   * </p><p>
   * </p>
   * @since 1.11.18
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
   * <p>
   * get PID of hypervisor
   * </p><p>
   * Return the process ID of the hypervisor. If there is no
   * hypervisor running, then this will return an error.
   * </p><p>
   * This is an internal call used for debugging and testing.
   * </p><p>
   * </p>
   * @since 1.0.56
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
   * <p>
   * get the program name
   * </p><p>
   * Get the program name. See "g.set_program".
   * </p><p>
   * </p>
   * @since 1.21.29
   * @throws LibGuestFSException
   */
  public String get_program ()
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("get_program: handle is closed");

    return _get_program (g);
  }

  private native String _get_program (long g)
    throws LibGuestFSException;

  /**
   * <p>
   * get the hypervisor binary (usually qemu)
   * </p><p>
   * Return the current hypervisor binary (usually qemu).
   * </p><p>
   * This is always non-NULL. If it wasn't set already, then
   * this will return the default qemu binary name.
   * </p><p>
   * </p>
   * @since 1.0.6
   * @deprecated In new code, use {@link #get_hv} instead
   * @throws LibGuestFSException
   */
  @Deprecated public String get_qemu ()
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("get_qemu: handle is closed");

    return _get_qemu (g);
  }

  private native String _get_qemu (long g)
    throws LibGuestFSException;

  /**
   * <p>
   * get recovery process enabled flag
   * </p><p>
   * Return the recovery process enabled flag.
   * </p><p>
   * </p>
   * @since 1.0.77
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
   * <p>
   * get SELinux enabled flag
   * </p><p>
   * This returns the current setting of the selinux flag
   * which is passed to the appliance at boot time. See
   * "g.set_selinux".
   * </p><p>
   * For more information on the architecture of libguestfs,
   * see guestfs(3).
   * </p><p>
   * </p>
   * @since 1.0.67
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
   * <p>
   * get number of virtual CPUs in appliance
   * </p><p>
   * This returns the number of virtual CPUs assigned to the
   * appliance.
   * </p><p>
   * </p>
   * @since 1.13.15
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
   * <p>
   * get the current state
   * </p><p>
   * This returns the current state as an opaque integer.
   * This is only useful for printing debug and internal
   * error messages.
   * </p><p>
   * For more information on states, see guestfs(3).
   * </p><p>
   * </p>
   * @since 1.0.2
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
   * <p>
   * get the temporary directory
   * </p><p>
   * Get the directory used by the handle to store temporary
   * files.
   * </p><p>
   * </p>
   * @since 1.19.58
   * @throws LibGuestFSException
   */
  public String get_tmpdir ()
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("get_tmpdir: handle is closed");

    return _get_tmpdir (g);
  }

  private native String _get_tmpdir (long g)
    throws LibGuestFSException;

  /**
   * <p>
   * get command trace enabled flag
   * </p><p>
   * Return the command trace flag.
   * </p><p>
   * </p>
   * @since 1.0.69
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
   * <p>
   * get the current umask
   * </p><p>
   * Return the current umask. By default the umask is 022
   * unless it has been set by calling "g.umask".
   * </p><p>
   * </p>
   * @since 1.3.4
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

  /**
   * <p>
   * get verbose mode
   * </p><p>
   * This returns the verbose messages flag.
   * </p><p>
   * </p>
   * @since 0.3
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
   * <p>
   * get SELinux security context
   * </p><p>
   * This gets the SELinux security context of the daemon.
   * </p><p>
   * See the documentation about SELINUX in guestfs(3), and
   * "g.setcon"
   * </p><p>
   * </p>
   * @since 1.0.67
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
   * <p>
   * get a single extended attribute
   * </p><p>
   * Get a single extended attribute from file "path" named
   * "name". This call follows symlinks. If you want to
   * lookup an extended attribute for the symlink itself, use
   * "g.lgetxattr".
   * </p><p>
   * Normally it is better to get all extended attributes
   * from a file in one go by calling "g.getxattrs". However
   * some Linux filesystem implementations are buggy and do
   * not provide a way to list out attributes. For these
   * filesystems (notably ntfs-3g) you have to know the names
   * of the extended attributes you want in advance and call
   * this function.
   * </p><p>
   * Extended attribute values are blobs of binary data. If
   * there is no extended attribute named "name", this
   * returns an error.
   * </p><p>
   * See also: "g.getxattrs", "g.lgetxattr", attr(5).
   * </p><p>
   * </p>
   * @since 1.7.24
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
   * <p>
   * list extended attributes of a file or directory
   * </p><p>
   * This call lists the extended attributes of the file or
   * directory "path".
   * </p><p>
   * At the system call level, this is a combination of the
   * listxattr(2) and getxattr(2) calls.
   * </p><p>
   * See also: "g.lgetxattrs", attr(5).
   * </p><p>
   * </p>
   * @since 1.0.59
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
   * <p>
   * expand a wildcard path
   * </p><p>
   * This command searches for all the pathnames matching
   * "pattern" according to the wildcard expansion rules used
   * by the shell.
   * </p><p>
   * If no paths match, then this returns an empty list
   * (note: not an error).
   * </p><p>
   * It is just a wrapper around the C glob(3) function with
   * flags "GLOB_MARK|GLOB_BRACE". See that manual page for
   * more details.
   * </p><p>
   * Notice that there is no equivalent command for expanding
   * a device name (eg. /dev/sd*). Use "g.list_devices",
   * "g.list_partitions" etc functions instead.
   * </p><p>
   * </p>
   * @since 1.0.50
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
   * <p>
   * return lines matching a pattern
   * </p><p>
   * This calls the external "grep" program and returns the
   * matching lines.
   * </p><p>
   * The optional flags are:
   * </p><p>
   * "extended"
   * Use extended regular expressions. This is the same
   * as using the *-E* flag.
   * </p><p>
   * "fixed"
   * Match fixed (don't use regular expressions). This is
   * the same as using the *-F* flag.
   * </p><p>
   * "insensitive"
   * Match case-insensitive. This is the same as using
   * the *-i* flag.
   * </p><p>
   * "compressed"
   * Use "zgrep" instead of "grep". This allows the input
   * to be compress- or gzip-compressed.
   * </p><p>
   * Optional arguments are supplied in the final
   * Map&lt;String,Object&gt; parameter, which is a hash of the
   * argument name to its value (cast to Object). Pass an
   * empty Map or null for no optional arguments.
   * </p><p>
   * Because of the message protocol, there is a transfer
   * limit of somewhere between 2MB and 4MB. See "PROTOCOL
   * LIMITS" in guestfs(3).
   * </p><p>
   * </p>
   * @since 1.0.66
   * @throws LibGuestFSException
   */
  public String[] grep (String regex, String path, Map<String, Object> optargs)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("grep: handle is closed");

    /* Unpack optional args. */
    Object _optobj;
    long _optargs_bitmask = 0;
    boolean extended = false;
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("extended");
    if (_optobj != null) {
      extended = ((Boolean) _optobj).booleanValue();
      _optargs_bitmask |= 1L;
    }
    boolean fixed = false;
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("fixed");
    if (_optobj != null) {
      fixed = ((Boolean) _optobj).booleanValue();
      _optargs_bitmask |= 2L;
    }
    boolean insensitive = false;
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("insensitive");
    if (_optobj != null) {
      insensitive = ((Boolean) _optobj).booleanValue();
      _optargs_bitmask |= 4L;
    }
    boolean compressed = false;
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("compressed");
    if (_optobj != null) {
      compressed = ((Boolean) _optobj).booleanValue();
      _optargs_bitmask |= 8L;
    }

    return _grep (g, regex, path, _optargs_bitmask, extended, fixed, insensitive, compressed);
  }

  public String[] grep (String regex, String path)
    throws LibGuestFSException
  {
    return grep (regex, path, null);
  }

  public String[] grep_opts (String regex, String path, Map<String, Object> optargs)
    throws LibGuestFSException
  {
    return grep (regex, path, optargs);
  }

  public String[] grep_opts (String regex, String path)
    throws LibGuestFSException
  {
    return grep (regex, path, null);
  }

  private native String[] _grep (long g, String regex, String path, long _optargs_bitmask, boolean extended, boolean fixed, boolean insensitive, boolean compressed)
    throws LibGuestFSException;

  /**
   * <p>
   * return lines matching a pattern
   * </p><p>
   * This calls the external "grep -i" program and returns
   * the matching lines.
   * </p><p>
   * Because of the message protocol, there is a transfer
   * limit of somewhere between 2MB and 4MB. See "PROTOCOL
   * LIMITS" in guestfs(3).
   * </p><p>
   * </p>
   * @since 1.0.66
   * @deprecated In new code, use {@link #grep} instead
   * @throws LibGuestFSException
   */
  @Deprecated public String[] grepi (String regex, String path)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("grepi: handle is closed");

    return _grepi (g, regex, path);
  }

  private native String[] _grepi (long g, String regex, String path)
    throws LibGuestFSException;

  /**
   * <p>
   * install GRUB 1
   * </p><p>
   * This command installs GRUB 1 (the Grand Unified
   * Bootloader) on "device", with the root directory being
   * "root".
   * </p><p>
   * Notes:
   * </p><p>
   * *   There is currently no way in the API to install
   * grub2, which is used by most modern Linux guests. It
   * is possible to run the grub2 command from the guest,
   * although see the caveats in "RUNNING COMMANDS" in
   * guestfs(3).
   * </p><p>
   * *   This uses "grub-install" from the host.
   * Unfortunately grub is not always compatible with
   * itself, so this only works in rather narrow
   * circumstances. Careful testing with each guest
   * version is advisable.
   * </p><p>
   * *   If grub-install reports the error "No suitable drive
   * was found in the generated device map." it may be
   * that you need to create a /boot/grub/device.map file
   * first that contains the mapping between grub device
   * names and Linux device names. It is usually
   * sufficient to create a file containing:
   * </p><p>
   * (hd0) /dev/vda
   * </p><p>
   * replacing /dev/vda with the name of the installation
   * device.
   * </p><p>
   * </p>
   * @since 1.0.17
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
   * <p>
   * return first 10 lines of a file
   * </p><p>
   * This command returns up to the first 10 lines of a file
   * as a list of strings.
   * </p><p>
   * Because of the message protocol, there is a transfer
   * limit of somewhere between 2MB and 4MB. See "PROTOCOL
   * LIMITS" in guestfs(3).
   * </p><p>
   * </p>
   * @since 1.0.54
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
   * <p>
   * return first N lines of a file
   * </p><p>
   * If the parameter "nrlines" is a positive number, this
   * returns the first "nrlines" lines of the file "path".
   * </p><p>
   * If the parameter "nrlines" is a negative number, this
   * returns lines from the file "path", excluding the last
   * "nrlines" lines.
   * </p><p>
   * If the parameter "nrlines" is zero, this returns an
   * empty list.
   * </p><p>
   * Because of the message protocol, there is a transfer
   * limit of somewhere between 2MB and 4MB. See "PROTOCOL
   * LIMITS" in guestfs(3).
   * </p><p>
   * </p>
   * @since 1.0.54
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
   * <p>
   * dump a file in hexadecimal
   * </p><p>
   * This runs "hexdump -C" on the given "path". The result
   * is the human-readable, canonical hex dump of the file.
   * </p><p>
   * Because of the message protocol, there is a transfer
   * limit of somewhere between 2MB and 4MB. See "PROTOCOL
   * LIMITS" in guestfs(3).
   * </p><p>
   * </p>
   * @since 1.0.22
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
   * <p>
   * close the current hivex handle
   * </p><p>
   * Close the current hivex handle.
   * </p><p>
   * This is a wrapper around the hivex(3) call of the same
   * name.
   * </p><p>
   * </p>
   * @since 1.19.35
   * @throws LibGuestFSException
   */
  public void hivex_close ()
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("hivex_close: handle is closed");

    _hivex_close (g);
  }

  private native void _hivex_close (long g)
    throws LibGuestFSException;

  /**
   * <p>
   * commit (write) changes back to the hive
   * </p><p>
   * Commit (write) changes to the hive.
   * </p><p>
   * If the optional filename parameter is null, then the
   * changes are written back to the same hive that was
   * opened. If this is not null then they are written to the
   * alternate filename given and the original hive is left
   * untouched.
   * </p><p>
   * This is a wrapper around the hivex(3) call of the same
   * name.
   * </p><p>
   * </p>
   * @since 1.19.35
   * @throws LibGuestFSException
   */
  public void hivex_commit (String filename)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("hivex_commit: handle is closed");

    _hivex_commit (g, filename);
  }

  private native void _hivex_commit (long g, String filename)
    throws LibGuestFSException;

  /**
   * <p>
   * add a child node
   * </p><p>
   * Add a child node to "parent" named "name".
   * </p><p>
   * This is a wrapper around the hivex(3) call of the same
   * name.
   * </p><p>
   * </p>
   * @since 1.19.35
   * @throws LibGuestFSException
   */
  public long hivex_node_add_child (long parent, String name)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("hivex_node_add_child: handle is closed");

    return _hivex_node_add_child (g, parent, name);
  }

  private native long _hivex_node_add_child (long g, long parent, String name)
    throws LibGuestFSException;

  /**
   * <p>
   * return list of nodes which are subkeys of node
   * </p><p>
   * Return the list of nodes which are subkeys of "nodeh".
   * </p><p>
   * This is a wrapper around the hivex(3) call of the same
   * name.
   * </p><p>
   * </p>
   * @since 1.19.35
   * @throws LibGuestFSException
   */
  public HivexNode[] hivex_node_children (long nodeh)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("hivex_node_children: handle is closed");

    return _hivex_node_children (g, nodeh);
  }

  private native HivexNode[] _hivex_node_children (long g, long nodeh)
    throws LibGuestFSException;

  /**
   * <p>
   * delete a node (recursively)
   * </p><p>
   * Delete "nodeh", recursively if necessary.
   * </p><p>
   * This is a wrapper around the hivex(3) call of the same
   * name.
   * </p><p>
   * </p>
   * @since 1.19.35
   * @throws LibGuestFSException
   */
  public void hivex_node_delete_child (long nodeh)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("hivex_node_delete_child: handle is closed");

    _hivex_node_delete_child (g, nodeh);
  }

  private native void _hivex_node_delete_child (long g, long nodeh)
    throws LibGuestFSException;

  /**
   * <p>
   * return the named child of node
   * </p><p>
   * Return the child of "nodeh" with the name "name", if it
   * exists. This can return 0 meaning the name was not
   * found.
   * </p><p>
   * This is a wrapper around the hivex(3) call of the same
   * name.
   * </p><p>
   * </p>
   * @since 1.19.35
   * @throws LibGuestFSException
   */
  public long hivex_node_get_child (long nodeh, String name)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("hivex_node_get_child: handle is closed");

    return _hivex_node_get_child (g, nodeh, name);
  }

  private native long _hivex_node_get_child (long g, long nodeh, String name)
    throws LibGuestFSException;

  /**
   * <p>
   * return the named value
   * </p><p>
   * Return the value attached to "nodeh" which has the name
   * "key", if it exists. This can return 0 meaning the key
   * was not found.
   * </p><p>
   * This is a wrapper around the hivex(3) call of the same
   * name.
   * </p><p>
   * </p>
   * @since 1.19.35
   * @throws LibGuestFSException
   */
  public long hivex_node_get_value (long nodeh, String key)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("hivex_node_get_value: handle is closed");

    return _hivex_node_get_value (g, nodeh, key);
  }

  private native long _hivex_node_get_value (long g, long nodeh, String key)
    throws LibGuestFSException;

  /**
   * <p>
   * return the name of the node
   * </p><p>
   * Return the name of "nodeh".
   * </p><p>
   * This is a wrapper around the hivex(3) call of the same
   * name.
   * </p><p>
   * </p>
   * @since 1.19.35
   * @throws LibGuestFSException
   */
  public String hivex_node_name (long nodeh)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("hivex_node_name: handle is closed");

    return _hivex_node_name (g, nodeh);
  }

  private native String _hivex_node_name (long g, long nodeh)
    throws LibGuestFSException;

  /**
   * <p>
   * return the parent of node
   * </p><p>
   * Return the parent node of "nodeh".
   * </p><p>
   * This is a wrapper around the hivex(3) call of the same
   * name.
   * </p><p>
   * </p>
   * @since 1.19.35
   * @throws LibGuestFSException
   */
  public long hivex_node_parent (long nodeh)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("hivex_node_parent: handle is closed");

    return _hivex_node_parent (g, nodeh);
  }

  private native long _hivex_node_parent (long g, long nodeh)
    throws LibGuestFSException;

  /**
   * <p>
   * set or replace a single value in a node
   * </p><p>
   * Set or replace a single value under the node "nodeh".
   * The "key" is the name, "t" is the type, and "val" is the
   * data.
   * </p><p>
   * This is a wrapper around the hivex(3) call of the same
   * name.
   * </p><p>
   * </p>
   * @since 1.19.35
   * @throws LibGuestFSException
   */
  public void hivex_node_set_value (long nodeh, String key, long t, byte[] val)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("hivex_node_set_value: handle is closed");

    _hivex_node_set_value (g, nodeh, key, t, val);
  }

  private native void _hivex_node_set_value (long g, long nodeh, String key, long t, byte[] val)
    throws LibGuestFSException;

  /**
   * <p>
   * return list of values attached to node
   * </p><p>
   * Return the array of (key, datatype, data) tuples
   * attached to "nodeh".
   * </p><p>
   * This is a wrapper around the hivex(3) call of the same
   * name.
   * </p><p>
   * </p>
   * @since 1.19.35
   * @throws LibGuestFSException
   */
  public HivexValue[] hivex_node_values (long nodeh)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("hivex_node_values: handle is closed");

    return _hivex_node_values (g, nodeh);
  }

  private native HivexValue[] _hivex_node_values (long g, long nodeh)
    throws LibGuestFSException;

  /**
   * <p>
   * open a Windows Registry hive file
   * </p><p>
   * Open the Windows Registry hive file named filename. If
   * there was any previous hivex handle associated with this
   * guestfs session, then it is closed.
   * </p><p>
   * This is a wrapper around the hivex(3) call of the same
   * name.
   * </p><p>
   * Optional arguments are supplied in the final
   * Map&lt;String,Object&gt; parameter, which is a hash of the
   * argument name to its value (cast to Object). Pass an
   * empty Map or null for no optional arguments.
   * </p><p>
   * </p>
   * @since 1.19.35
   * @throws LibGuestFSException
   */
  public void hivex_open (String filename, Map<String, Object> optargs)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("hivex_open: handle is closed");

    /* Unpack optional args. */
    Object _optobj;
    long _optargs_bitmask = 0;
    boolean verbose = false;
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("verbose");
    if (_optobj != null) {
      verbose = ((Boolean) _optobj).booleanValue();
      _optargs_bitmask |= 1L;
    }
    boolean debug = false;
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("debug");
    if (_optobj != null) {
      debug = ((Boolean) _optobj).booleanValue();
      _optargs_bitmask |= 2L;
    }
    boolean write = false;
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("write");
    if (_optobj != null) {
      write = ((Boolean) _optobj).booleanValue();
      _optargs_bitmask |= 4L;
    }

    _hivex_open (g, filename, _optargs_bitmask, verbose, debug, write);
  }

  public void hivex_open (String filename)
    throws LibGuestFSException
  {
    hivex_open (filename, null);
  }

  private native void _hivex_open (long g, String filename, long _optargs_bitmask, boolean verbose, boolean debug, boolean write)
    throws LibGuestFSException;

  /**
   * <p>
   * return the root node of the hive
   * </p><p>
   * Return the root node of the hive.
   * </p><p>
   * This is a wrapper around the hivex(3) call of the same
   * name.
   * </p><p>
   * </p>
   * @since 1.19.35
   * @throws LibGuestFSException
   */
  public long hivex_root ()
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("hivex_root: handle is closed");

    return _hivex_root (g);
  }

  private native long _hivex_root (long g)
    throws LibGuestFSException;

  /**
   * <p>
   * return the key field from the (key, datatype, data) tuple
   * </p><p>
   * Return the key (name) field of a (key, datatype, data)
   * tuple.
   * </p><p>
   * This is a wrapper around the hivex(3) call of the same
   * name.
   * </p><p>
   * </p>
   * @since 1.19.35
   * @throws LibGuestFSException
   */
  public String hivex_value_key (long valueh)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("hivex_value_key: handle is closed");

    return _hivex_value_key (g, valueh);
  }

  private native String _hivex_value_key (long g, long valueh)
    throws LibGuestFSException;

  /**
   * <p>
   * return the data type from the (key, datatype, data) tuple
   * </p><p>
   * Return the data type field from a (key, datatype, data)
   * tuple.
   * </p><p>
   * This is a wrapper around the hivex(3) call of the same
   * name.
   * </p><p>
   * </p>
   * @since 1.19.35
   * @throws LibGuestFSException
   */
  public long hivex_value_type (long valueh)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("hivex_value_type: handle is closed");

    return _hivex_value_type (g, valueh);
  }

  private native long _hivex_value_type (long g, long valueh)
    throws LibGuestFSException;

  /**
   * <p>
   * return the data field from the (key, datatype, data) tuple
   * </p><p>
   * This calls "g.hivex_value_value" (which returns the data
   * field from a hivex value tuple). It then assumes that
   * the field is a UTF-16LE string and converts the result
   * to UTF-8 (or if this is not possible, it returns an
   * error).
   * </p><p>
   * This is useful for reading strings out of the Windows
   * registry. However it is not foolproof because the
   * registry is not strongly-typed and fields can contain
   * arbitrary or unexpected data.
   * </p><p>
   * </p>
   * @since 1.19.35
   * @throws LibGuestFSException
   */
  public String hivex_value_utf8 (long valueh)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("hivex_value_utf8: handle is closed");

    return _hivex_value_utf8 (g, valueh);
  }

  private native String _hivex_value_utf8 (long g, long valueh)
    throws LibGuestFSException;

  /**
   * <p>
   * return the data field from the (key, datatype, data) tuple
   * </p><p>
   * Return the data field of a (key, datatype, data) tuple.
   * </p><p>
   * This is a wrapper around the hivex(3) call of the same
   * name.
   * </p><p>
   * See also: "g.hivex_value_utf8".
   * </p><p>
   * </p>
   * @since 1.19.35
   * @throws LibGuestFSException
   */
  public String hivex_value_value (long valueh)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("hivex_value_value: handle is closed");

    return _hivex_value_value (g, valueh);
  }

  private native String _hivex_value_value (long g, long valueh)
    throws LibGuestFSException;

  /**
   * <p>
   * list the contents of a single file in an initrd
   * </p><p>
   * This command unpacks the file filename from the initrd
   * file called initrdpath. The filename must be given
   * *without* the initial / character.
   * </p><p>
   * For example, in guestfish you could use the following
   * command to examine the boot script (usually called
   * /init) contained in a Linux initrd or initramfs image:
   * </p><p>
   * initrd-cat /boot/initrd-&lt;version&gt;.img init
   * </p><p>
   * See also "g.initrd_list".
   * </p><p>
   * Because of the message protocol, there is a transfer
   * limit of somewhere between 2MB and 4MB. See "PROTOCOL
   * LIMITS" in guestfs(3).
   * </p><p>
   * </p>
   * @since 1.0.84
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
   * <p>
   * list files in an initrd
   * </p><p>
   * This command lists out files contained in an initrd.
   * </p><p>
   * The files are listed without any initial / character.
   * The files are listed in the order they appear (not
   * necessarily alphabetical). Directory names are listed as
   * separate items.
   * </p><p>
   * Old Linux kernels (2.4 and earlier) used a compressed
   * ext2 filesystem as initrd. We *only* support the newer
   * initramfs format (compressed cpio files).
   * </p><p>
   * </p>
   * @since 1.0.54
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
   * <p>
   * add an inotify watch
   * </p><p>
   * Watch "path" for the events listed in "mask".
   * </p><p>
   * Note that if "path" is a directory then events within
   * that directory are watched, but this does *not* happen
   * recursively (in subdirectories).
   * </p><p>
   * Note for non-C or non-Linux callers: the inotify events
   * are defined by the Linux kernel ABI and are listed in
   * /usr/include/sys/inotify.h.
   * </p><p>
   * </p>
   * @since 1.0.66
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
   * <p>
   * close the inotify handle
   * </p><p>
   * This closes the inotify handle which was previously
   * opened by inotify_init. It removes all watches, throws
   * away any pending events, and deallocates all resources.
   * </p><p>
   * </p>
   * @since 1.0.66
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
   * <p>
   * return list of watched files that had events
   * </p><p>
   * This function is a helpful wrapper around
   * "g.inotify_read" which just returns a list of pathnames
   * of objects that were touched. The returned pathnames are
   * sorted and deduplicated.
   * </p><p>
   * </p>
   * @since 1.0.66
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
   * <p>
   * create an inotify handle
   * </p><p>
   * This command creates a new inotify handle. The inotify
   * subsystem can be used to notify events which happen to
   * objects in the guest filesystem.
   * </p><p>
   * "maxevents" is the maximum number of events which will
   * be queued up between calls to "g.inotify_read" or
   * "g.inotify_files". If this is passed as 0, then the
   * kernel (or previously set) default is used. For Linux
   * 2.6.29 the default was 16384 events. Beyond this limit,
   * the kernel throws away events, but records the fact that
   * it threw them away by setting a flag "IN_Q_OVERFLOW" in
   * the returned structure list (see "g.inotify_read").
   * </p><p>
   * Before any events are generated, you have to add some
   * watches to the internal watch list. See:
   * "g.inotify_add_watch" and "g.inotify_rm_watch".
   * </p><p>
   * Queued up events should be read periodically by calling
   * "g.inotify_read" (or "g.inotify_files" which is just a
   * helpful wrapper around "g.inotify_read"). If you don't
   * read the events out often enough then you risk the
   * internal queue overflowing.
   * </p><p>
   * The handle should be closed after use by calling
   * "g.inotify_close". This also removes any watches
   * automatically.
   * </p><p>
   * See also inotify(7) for an overview of the inotify
   * interface as exposed by the Linux kernel, which is
   * roughly what we expose via libguestfs. Note that there
   * is one global inotify handle per libguestfs instance.
   * </p><p>
   * </p>
   * @since 1.0.66
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
   * <p>
   * return list of inotify events
   * </p><p>
   * Return the complete queue of events that have happened
   * since the previous read call.
   * </p><p>
   * If no events have happened, this returns an empty list.
   * </p><p>
   * *Note*: In order to make sure that all events have been
   * read, you must call this function repeatedly until it
   * returns an empty list. The reason is that the call will
   * read events up to the maximum appliance-to-host message
   * size and leave remaining events in the queue.
   * </p><p>
   * </p>
   * @since 1.0.66
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
   * <p>
   * remove an inotify watch
   * </p><p>
   * Remove a previously defined inotify watch. See
   * "g.inotify_add_watch".
   * </p><p>
   * </p>
   * @since 1.0.66
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
   * <p>
   * get architecture of inspected operating system
   * </p><p>
   * This returns the architecture of the inspected operating
   * system. The possible return values are listed under
   * "g.file_architecture".
   * </p><p>
   * If the architecture could not be determined, then the
   * string "unknown" is returned.
   * </p><p>
   * Please read "INSPECTION" in guestfs(3) for more details.
   * </p><p>
   * </p>
   * @since 1.5.3
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
   * <p>
   * get distro of inspected operating system
   * </p><p>
   * This returns the distro (distribution) of the inspected
   * operating system.
   * </p><p>
   * Currently defined distros are:
   * </p><p>
   * "archlinux"
   * Arch Linux.
   * </p><p>
   * "buildroot"
   * Buildroot-derived distro, but not one we
   * specifically recognize.
   * </p><p>
   * "centos"
   * CentOS.
   * </p><p>
   * "cirros"
   * Cirros.
   * </p><p>
   * "coreos"
   * CoreOS.
   * </p><p>
   * "debian"
   * Debian.
   * </p><p>
   * "fedora"
   * Fedora.
   * </p><p>
   * "freebsd"
   * FreeBSD.
   * </p><p>
   * "freedos"
   * FreeDOS.
   * </p><p>
   * "gentoo"
   * Gentoo.
   * </p><p>
   * "linuxmint"
   * Linux Mint.
   * </p><p>
   * "mageia"
   * Mageia.
   * </p><p>
   * "mandriva"
   * Mandriva.
   * </p><p>
   * "meego"
   * MeeGo.
   * </p><p>
   * "netbsd"
   * NetBSD.
   * </p><p>
   * "openbsd"
   * OpenBSD.
   * </p><p>
   * "opensuse"
   * OpenSUSE.
   * </p><p>
   * "oraclelinux"
   * Oracle Linux.
   * </p><p>
   * "pardus"
   * Pardus.
   * </p><p>
   * "redhat-based"
   * Some Red Hat-derived distro.
   * </p><p>
   * "rhel"
   * Red Hat Enterprise Linux.
   * </p><p>
   * "scientificlinux"
   * Scientific Linux.
   * </p><p>
   * "slackware"
   * Slackware.
   * </p><p>
   * "sles"
   * SuSE Linux Enterprise Server or Desktop.
   * </p><p>
   * "suse-based"
   * Some openSuSE-derived distro.
   * </p><p>
   * "ttylinux"
   * ttylinux.
   * </p><p>
   * "ubuntu"
   * Ubuntu.
   * </p><p>
   * "unknown"
   * The distro could not be determined.
   * </p><p>
   * "windows"
   * Windows does not have distributions. This string is
   * returned if the OS type is Windows.
   * </p><p>
   * Future versions of libguestfs may return other strings
   * here. The caller should be prepared to handle any
   * string.
   * </p><p>
   * Please read "INSPECTION" in guestfs(3) for more details.
   * </p><p>
   * </p>
   * @since 1.5.3
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
   * <p>
   * get drive letter mappings
   * </p><p>
   * This call is useful for Windows which uses a primitive
   * system of assigning drive letters (like C:\) to
   * partitions. This inspection API examines the Windows
   * Registry to find out how disks/partitions are mapped to
   * drive letters, and returns a hash table as in the
   * example below:
   * </p><p>
   * C      =&gt;     /dev/vda2
   * E      =&gt;     /dev/vdb1
   * F      =&gt;     /dev/vdc1
   * </p><p>
   * Note that keys are drive letters. For Windows, the key
   * is case insensitive and just contains the drive letter,
   * without the customary colon separator character.
   * </p><p>
   * In future we may support other operating systems that
   * also used drive letters, but the keys for those might
   * not be case insensitive and might be longer than 1
   * character. For example in OS-9, hard drives were named
   * "h0", "h1" etc.
   * </p><p>
   * For Windows guests, currently only hard drive mappings
   * are returned. Removable disks (eg. DVD-ROMs) are
   * ignored.
   * </p><p>
   * For guests that do not use drive mappings, or if the
   * drive mappings could not be determined, this returns an
   * empty hash table.
   * </p><p>
   * Please read "INSPECTION" in guestfs(3) for more details.
   * See also "g.inspect_get_mountpoints",
   * "g.inspect_get_filesystems".
   * </p><p>
   * </p>
   * @since 1.9.17
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
   * <p>
   * get filesystems associated with inspected operating system
   * </p><p>
   * This returns a list of all the filesystems that we think
   * are associated with this operating system. This includes
   * the root filesystem, other ordinary filesystems, and
   * non-mounted devices like swap partitions.
   * </p><p>
   * In the case of a multi-boot virtual machine, it is
   * possible for a filesystem to be shared between operating
   * systems.
   * </p><p>
   * Please read "INSPECTION" in guestfs(3) for more details.
   * See also "g.inspect_get_mountpoints".
   * </p><p>
   * </p>
   * @since 1.5.3
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
   * <p>
   * get format of inspected operating system
   * </p><p>
   * This returns the format of the inspected operating
   * system. You can use it to detect install images, live
   * CDs and similar.
   * </p><p>
   * Currently defined formats are:
   * </p><p>
   * "installed"
   * This is an installed operating system.
   * </p><p>
   * "installer"
   * The disk image being inspected is not an installed
   * operating system, but a *bootable* install disk,
   * live CD, or similar.
   * </p><p>
   * "unknown"
   * The format of this disk image is not known.
   * </p><p>
   * Future versions of libguestfs may return other strings
   * here. The caller should be prepared to handle any
   * string.
   * </p><p>
   * Please read "INSPECTION" in guestfs(3) for more details.
   * </p><p>
   * </p>
   * @since 1.9.4
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
   * <p>
   * get hostname of the operating system
   * </p><p>
   * This function returns the hostname of the operating
   * system as found by inspection of the guest's
   * configuration files.
   * </p><p>
   * If the hostname could not be determined, then the string
   * "unknown" is returned.
   * </p><p>
   * Please read "INSPECTION" in guestfs(3) for more details.
   * </p><p>
   * </p>
   * @since 1.7.9
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
   * <p>
   * get the icon corresponding to this operating system
   * </p><p>
   * This function returns an icon corresponding to the
   * inspected operating system. The icon is returned as a
   * buffer containing a PNG image (re-encoded to PNG if
   * necessary).
   * </p><p>
   * If it was not possible to get an icon this function
   * returns a zero-length (non-NULL) buffer. *Callers must
   * check for this case*.
   * </p><p>
   * Libguestfs will start by looking for a file called
   * /etc/favicon.png or C:\etc\favicon.png and if it has the
   * correct format, the contents of this file will be
   * returned. You can disable favicons by passing the
   * optional "favicon" boolean as false (default is true).
   * </p><p>
   * If finding the favicon fails, then we look in other
   * places in the guest for a suitable icon.
   * </p><p>
   * If the optional "highquality" boolean is true then only
   * high quality icons are returned, which means only icons
   * of high resolution with an alpha channel. The default
   * (false) is to return any icon we can, even if it is of
   * substandard quality.
   * </p><p>
   * Notes:
   * </p><p>
   * *   Unlike most other inspection API calls, the guest's
   * disks must be mounted up before you call this, since
   * it needs to read information from the guest
   * filesystem during the call.
   * </p><p>
   * *   Security: The icon data comes from the untrusted
   * guest, and should be treated with caution. PNG files
   * have been known to contain exploits. Ensure that
   * libpng (or other relevant libraries) are fully up to
   * date before trying to process or display the icon.
   * </p><p>
   * *   The PNG image returned can be any size. It might not
   * be square. Libguestfs tries to return the largest,
   * highest quality icon available. The application must
   * scale the icon to the required size.
   * </p><p>
   * *   Extracting icons from Windows guests requires the
   * external "wrestool" program from the "icoutils"
   * package, and several programs ("bmptopnm",
   * "pnmtopng", "pamcut") from the "netpbm" package.
   * These must be installed separately.
   * </p><p>
   * *   Operating system icons are usually trademarks. Seek
   * legal advice before using trademarks in
   * applications.
   * </p><p>
   * Optional arguments are supplied in the final
   * Map&lt;String,Object&gt; parameter, which is a hash of the
   * argument name to its value (cast to Object). Pass an
   * empty Map or null for no optional arguments.
   * </p><p>
   * </p>
   * @since 1.11.12
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
   * <p>
   * get major version of inspected operating system
   * </p><p>
   * This returns the major version number of the inspected
   * operating system.
   * </p><p>
   * Windows uses a consistent versioning scheme which is
   * *not* reflected in the popular public names used by the
   * operating system. Notably the operating system known as
   * "Windows 7" is really version 6.1 (ie. major = 6, minor
   * = 1). You can find out the real versions corresponding
   * to releases of Windows by consulting Wikipedia or MSDN.
   * </p><p>
   * If the version could not be determined, then 0 is
   * returned.
   * </p><p>
   * Please read "INSPECTION" in guestfs(3) for more details.
   * </p><p>
   * </p>
   * @since 1.5.3
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
   * <p>
   * get minor version of inspected operating system
   * </p><p>
   * This returns the minor version number of the inspected
   * operating system.
   * </p><p>
   * If the version could not be determined, then 0 is
   * returned.
   * </p><p>
   * Please read "INSPECTION" in guestfs(3) for more details.
   * See also "g.inspect_get_major_version".
   * </p><p>
   * </p>
   * @since 1.5.3
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
   * <p>
   * get mountpoints of inspected operating system
   * </p><p>
   * This returns a hash of where we think the filesystems
   * associated with this operating system should be mounted.
   * Callers should note that this is at best an educated
   * guess made by reading configuration files such as
   * /etc/fstab. *In particular note* that this may return
   * filesystems which are non-existent or not mountable and
   * callers should be prepared to handle or ignore failures
   * if they try to mount them.
   * </p><p>
   * Each element in the returned hashtable has a key which
   * is the path of the mountpoint (eg. /boot) and a value
   * which is the filesystem that would be mounted there (eg.
   * /dev/sda1).
   * </p><p>
   * Non-mounted devices such as swap devices are *not*
   * returned in this list.
   * </p><p>
   * For operating systems like Windows which still use drive
   * letters, this call will only return an entry for the
   * first drive "mounted on" /. For information about the
   * mapping of drive letters to partitions, see
   * "g.inspect_get_drive_mappings".
   * </p><p>
   * Please read "INSPECTION" in guestfs(3) for more details.
   * See also "g.inspect_get_filesystems".
   * </p><p>
   * </p>
   * @since 1.5.3
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
   * <p>
   * get package format used by the operating system
   * </p><p>
   * This function and "g.inspect_get_package_management"
   * return the package format and package management tool
   * used by the inspected operating system. For example for
   * Fedora these functions would return "rpm" (package
   * format), and "yum" or "dnf" (package management).
   * </p><p>
   * This returns the string "unknown" if we could not
   * determine the package format *or* if the operating
   * system does not have a real packaging system (eg.
   * Windows).
   * </p><p>
   * Possible strings include: "rpm", "deb", "ebuild",
   * "pisi", "pacman", "pkgsrc". Future versions of
   * libguestfs may return other strings.
   * </p><p>
   * Please read "INSPECTION" in guestfs(3) for more details.
   * </p><p>
   * </p>
   * @since 1.7.5
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
   * <p>
   * get package management tool used by the operating system
   * </p><p>
   * "g.inspect_get_package_format" and this function return
   * the package format and package management tool used by
   * the inspected operating system. For example for Fedora
   * these functions would return "rpm" (package format), and
   * "yum" or "dnf" (package management).
   * </p><p>
   * This returns the string "unknown" if we could not
   * determine the package management tool *or* if the
   * operating system does not have a real packaging system
   * (eg. Windows).
   * </p><p>
   * Possible strings include: "yum", "dnf", "up2date", "apt"
   * (for all Debian derivatives), "portage", "pisi",
   * "pacman", "urpmi", "zypper". Future versions of
   * libguestfs may return other strings.
   * </p><p>
   * Please read "INSPECTION" in guestfs(3) for more details.
   * </p><p>
   * </p>
   * @since 1.7.5
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
   * <p>
   * get product name of inspected operating system
   * </p><p>
   * This returns the product name of the inspected operating
   * system. The product name is generally some freeform
   * string which can be displayed to the user, but should
   * not be parsed by programs.
   * </p><p>
   * If the product name could not be determined, then the
   * string "unknown" is returned.
   * </p><p>
   * Please read "INSPECTION" in guestfs(3) for more details.
   * </p><p>
   * </p>
   * @since 1.5.3
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
   * <p>
   * get product variant of inspected operating system
   * </p><p>
   * This returns the product variant of the inspected
   * operating system.
   * </p><p>
   * For Windows guests, this returns the contents of the
   * Registry key "HKLM\Software\Microsoft\Windows
   * NT\CurrentVersion" "InstallationType" which is usually a
   * string such as "Client" or "Server" (other values are
   * possible). This can be used to distinguish consumer and
   * enterprise versions of Windows that have the same
   * version number (for example, Windows 7 and Windows 2008
   * Server are both version 6.1, but the former is "Client"
   * and the latter is "Server").
   * </p><p>
   * For enterprise Linux guests, in future we intend this to
   * return the product variant such as "Desktop", "Server"
   * and so on. But this is not implemented at present.
   * </p><p>
   * If the product variant could not be determined, then the
   * string "unknown" is returned.
   * </p><p>
   * Please read "INSPECTION" in guestfs(3) for more details.
   * See also "g.inspect_get_product_name",
   * "g.inspect_get_major_version".
   * </p><p>
   * </p>
   * @since 1.9.13
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
   * <p>
   * return list of operating systems found by last inspection
   * </p><p>
   * This function is a convenient way to get the list of
   * root devices, as returned from a previous call to
   * "g.inspect_os", but without redoing the whole inspection
   * process.
   * </p><p>
   * This returns an empty list if either no root devices
   * were found or the caller has not called "g.inspect_os".
   * </p><p>
   * Please read "INSPECTION" in guestfs(3) for more details.
   * </p><p>
   * </p>
   * @since 1.7.3
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

  /**
   * <p>
   * get type of inspected operating system
   * </p><p>
   * This returns the type of the inspected operating system.
   * Currently defined types are:
   * </p><p>
   * "linux"
   * Any Linux-based operating system.
   * </p><p>
   * "windows"
   * Any Microsoft Windows operating system.
   * </p><p>
   * "freebsd"
   * FreeBSD.
   * </p><p>
   * "netbsd"
   * NetBSD.
   * </p><p>
   * "openbsd"
   * OpenBSD.
   * </p><p>
   * "hurd"
   * GNU/Hurd.
   * </p><p>
   * "dos"
   * MS-DOS, FreeDOS and others.
   * </p><p>
   * "minix"
   * MINIX.
   * </p><p>
   * "unknown"
   * The operating system type could not be determined.
   * </p><p>
   * Future versions of libguestfs may return other strings
   * here. The caller should be prepared to handle any
   * string.
   * </p><p>
   * Please read "INSPECTION" in guestfs(3) for more details.
   * </p><p>
   * </p>
   * @since 1.5.3
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
   * <p>
   * get Windows CurrentControlSet of inspected operating system
   * </p><p>
   * This returns the Windows CurrentControlSet of the
   * inspected guest. The CurrentControlSet is a registry key
   * name such as "ControlSet001".
   * </p><p>
   * This call assumes that the guest is Windows and that the
   * Registry could be examined by inspection. If this is not
   * the case then an error is returned.
   * </p><p>
   * Please read "INSPECTION" in guestfs(3) for more details.
   * </p><p>
   * </p>
   * @since 1.9.17
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
   * <p>
   * get Windows systemroot of inspected operating system
   * </p><p>
   * This returns the Windows systemroot of the inspected
   * guest. The systemroot is a directory path such as
   * /WINDOWS.
   * </p><p>
   * This call assumes that the guest is Windows and that the
   * systemroot could be determined by inspection. If this is
   * not the case then an error is returned.
   * </p><p>
   * Please read "INSPECTION" in guestfs(3) for more details.
   * </p><p>
   * </p>
   * @since 1.5.25
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
   * <p>
   * get live flag for install disk
   * </p><p>
   * If "g.inspect_get_format" returns "installer" (this is
   * an install disk), then this returns true if a live image
   * was detected on the disk.
   * </p><p>
   * Please read "INSPECTION" in guestfs(3) for more details.
   * </p><p>
   * </p>
   * @since 1.9.4
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
   * <p>
   * get multipart flag for install disk
   * </p><p>
   * If "g.inspect_get_format" returns "installer" (this is
   * an install disk), then this returns true if the disk is
   * part of a set.
   * </p><p>
   * Please read "INSPECTION" in guestfs(3) for more details.
   * </p><p>
   * </p>
   * @since 1.9.4
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
   * <p>
   * get netinst (network installer) flag for install disk
   * </p><p>
   * If "g.inspect_get_format" returns "installer" (this is
   * an install disk), then this returns true if the disk is
   * a network installer, ie. not a self-contained install CD
   * but one which is likely to require network access to
   * complete the install.
   * </p><p>
   * Please read "INSPECTION" in guestfs(3) for more details.
   * </p><p>
   * </p>
   * @since 1.9.4
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
   * <p>
   * get list of applications installed in the operating system
   * </p><p>
   * Return the list of applications installed in the
   * operating system.
   * </p><p>
   * *Note:* This call works differently from other parts of
   * the inspection API. You have to call "g.inspect_os",
   * then "g.inspect_get_mountpoints", then mount up the
   * disks, before calling this. Listing applications is a
   * significantly more difficult operation which requires
   * access to the full filesystem. Also note that unlike the
   * other "g.inspect_get_*" calls which are just returning
   * data cached in the libguestfs handle, this call actually
   * reads parts of the mounted filesystems during the call.
   * </p><p>
   * This returns an empty list if the inspection code was
   * not able to determine the list of applications.
   * </p><p>
   * The application structure contains the following fields:
   * </p><p>
   * "app_name"
   * The name of the application. For Red Hat-derived and
   * Debian-derived Linux guests, this is the package
   * name.
   * </p><p>
   * "app_display_name"
   * The display name of the application, sometimes
   * localized to the install language of the guest
   * operating system.
   * </p><p>
   * If unavailable this is returned as an empty string
   * "". Callers needing to display something can use
   * "app_name" instead.
   * </p><p>
   * "app_epoch"
   * For package managers which use epochs, this contains
   * the epoch of the package (an integer). If
   * unavailable, this is returned as 0.
   * </p><p>
   * "app_version"
   * The version string of the application or package. If
   * unavailable this is returned as an empty string "".
   * </p><p>
   * "app_release"
   * The release string of the application or package,
   * for package managers that use this. If unavailable
   * this is returned as an empty string "".
   * </p><p>
   * "app_install_path"
   * The installation path of the application (on
   * operating systems such as Windows which use
   * installation paths). This path is in the format used
   * by the guest operating system, it is not a
   * libguestfs path.
   * </p><p>
   * If unavailable this is returned as an empty string
   * "".
   * </p><p>
   * "app_trans_path"
   * The install path translated into a libguestfs path.
   * If unavailable this is returned as an empty string
   * "".
   * </p><p>
   * "app_publisher"
   * The name of the publisher of the application, for
   * package managers that use this. If unavailable this
   * is returned as an empty string "".
   * </p><p>
   * "app_url"
   * The URL (eg. upstream URL) of the application. If
   * unavailable this is returned as an empty string "".
   * </p><p>
   * "app_source_package"
   * For packaging systems which support this, the name
   * of the source package. If unavailable this is
   * returned as an empty string "".
   * </p><p>
   * "app_summary"
   * A short (usually one line) description of the
   * application or package. If unavailable this is
   * returned as an empty string "".
   * </p><p>
   * "app_description"
   * A longer description of the application or package.
   * If unavailable this is returned as an empty string
   * "".
   * </p><p>
   * Please read "INSPECTION" in guestfs(3) for more details.
   * </p><p>
   * </p>
   * @since 1.7.8
   * @deprecated In new code, use {@link #inspect_list_applications2} instead
   * @throws LibGuestFSException
   */
  @Deprecated public Application[] inspect_list_applications (String root)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("inspect_list_applications: handle is closed");

    return _inspect_list_applications (g, root);
  }

  private native Application[] _inspect_list_applications (long g, String root)
    throws LibGuestFSException;

  /**
   * <p>
   * get list of applications installed in the operating system
   * </p><p>
   * Return the list of applications installed in the
   * operating system.
   * </p><p>
   * *Note:* This call works differently from other parts of
   * the inspection API. You have to call "g.inspect_os",
   * then "g.inspect_get_mountpoints", then mount up the
   * disks, before calling this. Listing applications is a
   * significantly more difficult operation which requires
   * access to the full filesystem. Also note that unlike the
   * other "g.inspect_get_*" calls which are just returning
   * data cached in the libguestfs handle, this call actually
   * reads parts of the mounted filesystems during the call.
   * </p><p>
   * This returns an empty list if the inspection code was
   * not able to determine the list of applications.
   * </p><p>
   * The application structure contains the following fields:
   * </p><p>
   * "app2_name"
   * The name of the application. For Red Hat-derived and
   * Debian-derived Linux guests, this is the package
   * name.
   * </p><p>
   * "app2_display_name"
   * The display name of the application, sometimes
   * localized to the install language of the guest
   * operating system.
   * </p><p>
   * If unavailable this is returned as an empty string
   * "". Callers needing to display something can use
   * "app2_name" instead.
   * </p><p>
   * "app2_epoch"
   * For package managers which use epochs, this contains
   * the epoch of the package (an integer). If
   * unavailable, this is returned as 0.
   * </p><p>
   * "app2_version"
   * The version string of the application or package. If
   * unavailable this is returned as an empty string "".
   * </p><p>
   * "app2_release"
   * The release string of the application or package,
   * for package managers that use this. If unavailable
   * this is returned as an empty string "".
   * </p><p>
   * "app2_arch"
   * The architecture string of the application or
   * package, for package managers that use this. If
   * unavailable this is returned as an empty string "".
   * </p><p>
   * "app2_install_path"
   * The installation path of the application (on
   * operating systems such as Windows which use
   * installation paths). This path is in the format used
   * by the guest operating system, it is not a
   * libguestfs path.
   * </p><p>
   * If unavailable this is returned as an empty string
   * "".
   * </p><p>
   * "app2_trans_path"
   * The install path translated into a libguestfs path.
   * If unavailable this is returned as an empty string
   * "".
   * </p><p>
   * "app2_publisher"
   * The name of the publisher of the application, for
   * package managers that use this. If unavailable this
   * is returned as an empty string "".
   * </p><p>
   * "app2_url"
   * The URL (eg. upstream URL) of the application. If
   * unavailable this is returned as an empty string "".
   * </p><p>
   * "app2_source_package"
   * For packaging systems which support this, the name
   * of the source package. If unavailable this is
   * returned as an empty string "".
   * </p><p>
   * "app2_summary"
   * A short (usually one line) description of the
   * application or package. If unavailable this is
   * returned as an empty string "".
   * </p><p>
   * "app2_description"
   * A longer description of the application or package.
   * If unavailable this is returned as an empty string
   * "".
   * </p><p>
   * Please read "INSPECTION" in guestfs(3) for more details.
   * </p><p>
   * </p>
   * @since 1.19.56
   * @throws LibGuestFSException
   */
  public Application2[] inspect_list_applications2 (String root)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("inspect_list_applications2: handle is closed");

    return _inspect_list_applications2 (g, root);
  }

  private native Application2[] _inspect_list_applications2 (long g, String root)
    throws LibGuestFSException;

  /**
   * <p>
   * inspect disk and return list of operating systems found
   * </p><p>
   * This function uses other libguestfs functions and
   * certain heuristics to inspect the disk(s) (usually disks
   * belonging to a virtual machine), looking for operating
   * systems.
   * </p><p>
   * The list returned is empty if no operating systems were
   * found.
   * </p><p>
   * If one operating system was found, then this returns a
   * list with a single element, which is the name of the
   * root filesystem of this operating system. It is also
   * possible for this function to return a list containing
   * more than one element, indicating a dual-boot or
   * multi-boot virtual machine, with each element being the
   * root filesystem of one of the operating systems.
   * </p><p>
   * You can pass the root string(s) returned to other
   * "g.inspect_get_*" functions in order to query further
   * information about each operating system, such as the
   * name and version.
   * </p><p>
   * This function uses other libguestfs features such as
   * "g.mount_ro" and "g.umount_all" in order to mount and
   * unmount filesystems and look at the contents. This
   * should be called with no disks currently mounted. The
   * function may also use Augeas, so any existing Augeas
   * handle will be closed.
   * </p><p>
   * This function cannot decrypt encrypted disks. The caller
   * must do that first (supplying the necessary keys) if the
   * disk is encrypted.
   * </p><p>
   * Please read "INSPECTION" in guestfs(3) for more details.
   * </p><p>
   * See also "g.list_filesystems".
   * </p><p>
   * </p>
   * @since 1.5.3
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

  public void internal_exit ()
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("internal_exit: handle is closed");

    _internal_exit (g);
  }

  private native void _internal_exit (long g)
    throws LibGuestFSException;

  public void internal_test (String str, String optstr, String[] strlist, boolean b, int integer, long integer64, String filein, String fileout, byte[] bufferin, Map<String, Object> optargs)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("internal_test: handle is closed");

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
    String[] ostringlist = new String[]{};
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("ostringlist");
    if (_optobj != null) {
      ostringlist = ((String[]) _optobj);
      _optargs_bitmask |= 16L;
    }

    _internal_test (g, str, optstr, strlist, b, integer, integer64, filein, fileout, bufferin, _optargs_bitmask, obool, oint, oint64, ostring, ostringlist);
  }

  public void internal_test (String str, String optstr, String[] strlist, boolean b, int integer, long integer64, String filein, String fileout, byte[] bufferin)
    throws LibGuestFSException
  {
    internal_test (str, optstr, strlist, b, integer, integer64, filein, fileout, bufferin, null);
  }

  private native void _internal_test (long g, String str, String optstr, String[] strlist, boolean b, int integer, long integer64, String filein, String fileout, byte[] bufferin, long _optargs_bitmask, boolean obool, int oint, long oint64, String ostring, String[] ostringlist)
    throws LibGuestFSException;

  public void internal_test_63_optargs (Map<String, Object> optargs)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("internal_test_63_optargs: handle is closed");

    /* Unpack optional args. */
    Object _optobj;
    long _optargs_bitmask = 0;
    int opt1 = 0;
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("opt1");
    if (_optobj != null) {
      opt1 = ((Integer) _optobj).intValue();
      _optargs_bitmask |= 1L;
    }
    int opt2 = 0;
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("opt2");
    if (_optobj != null) {
      opt2 = ((Integer) _optobj).intValue();
      _optargs_bitmask |= 2L;
    }
    int opt3 = 0;
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("opt3");
    if (_optobj != null) {
      opt3 = ((Integer) _optobj).intValue();
      _optargs_bitmask |= 4L;
    }
    int opt4 = 0;
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("opt4");
    if (_optobj != null) {
      opt4 = ((Integer) _optobj).intValue();
      _optargs_bitmask |= 8L;
    }
    int opt5 = 0;
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("opt5");
    if (_optobj != null) {
      opt5 = ((Integer) _optobj).intValue();
      _optargs_bitmask |= 16L;
    }
    int opt6 = 0;
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("opt6");
    if (_optobj != null) {
      opt6 = ((Integer) _optobj).intValue();
      _optargs_bitmask |= 32L;
    }
    int opt7 = 0;
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("opt7");
    if (_optobj != null) {
      opt7 = ((Integer) _optobj).intValue();
      _optargs_bitmask |= 64L;
    }
    int opt8 = 0;
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("opt8");
    if (_optobj != null) {
      opt8 = ((Integer) _optobj).intValue();
      _optargs_bitmask |= 128L;
    }
    int opt9 = 0;
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("opt9");
    if (_optobj != null) {
      opt9 = ((Integer) _optobj).intValue();
      _optargs_bitmask |= 256L;
    }
    int opt10 = 0;
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("opt10");
    if (_optobj != null) {
      opt10 = ((Integer) _optobj).intValue();
      _optargs_bitmask |= 512L;
    }
    int opt11 = 0;
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("opt11");
    if (_optobj != null) {
      opt11 = ((Integer) _optobj).intValue();
      _optargs_bitmask |= 1024L;
    }
    int opt12 = 0;
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("opt12");
    if (_optobj != null) {
      opt12 = ((Integer) _optobj).intValue();
      _optargs_bitmask |= 2048L;
    }
    int opt13 = 0;
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("opt13");
    if (_optobj != null) {
      opt13 = ((Integer) _optobj).intValue();
      _optargs_bitmask |= 4096L;
    }
    int opt14 = 0;
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("opt14");
    if (_optobj != null) {
      opt14 = ((Integer) _optobj).intValue();
      _optargs_bitmask |= 8192L;
    }
    int opt15 = 0;
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("opt15");
    if (_optobj != null) {
      opt15 = ((Integer) _optobj).intValue();
      _optargs_bitmask |= 16384L;
    }
    int opt16 = 0;
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("opt16");
    if (_optobj != null) {
      opt16 = ((Integer) _optobj).intValue();
      _optargs_bitmask |= 32768L;
    }
    int opt17 = 0;
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("opt17");
    if (_optobj != null) {
      opt17 = ((Integer) _optobj).intValue();
      _optargs_bitmask |= 65536L;
    }
    int opt18 = 0;
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("opt18");
    if (_optobj != null) {
      opt18 = ((Integer) _optobj).intValue();
      _optargs_bitmask |= 131072L;
    }
    int opt19 = 0;
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("opt19");
    if (_optobj != null) {
      opt19 = ((Integer) _optobj).intValue();
      _optargs_bitmask |= 262144L;
    }
    int opt20 = 0;
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("opt20");
    if (_optobj != null) {
      opt20 = ((Integer) _optobj).intValue();
      _optargs_bitmask |= 524288L;
    }
    int opt21 = 0;
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("opt21");
    if (_optobj != null) {
      opt21 = ((Integer) _optobj).intValue();
      _optargs_bitmask |= 1048576L;
    }
    int opt22 = 0;
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("opt22");
    if (_optobj != null) {
      opt22 = ((Integer) _optobj).intValue();
      _optargs_bitmask |= 2097152L;
    }
    int opt23 = 0;
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("opt23");
    if (_optobj != null) {
      opt23 = ((Integer) _optobj).intValue();
      _optargs_bitmask |= 4194304L;
    }
    int opt24 = 0;
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("opt24");
    if (_optobj != null) {
      opt24 = ((Integer) _optobj).intValue();
      _optargs_bitmask |= 8388608L;
    }
    int opt25 = 0;
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("opt25");
    if (_optobj != null) {
      opt25 = ((Integer) _optobj).intValue();
      _optargs_bitmask |= 16777216L;
    }
    int opt26 = 0;
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("opt26");
    if (_optobj != null) {
      opt26 = ((Integer) _optobj).intValue();
      _optargs_bitmask |= 33554432L;
    }
    int opt27 = 0;
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("opt27");
    if (_optobj != null) {
      opt27 = ((Integer) _optobj).intValue();
      _optargs_bitmask |= 67108864L;
    }
    int opt28 = 0;
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("opt28");
    if (_optobj != null) {
      opt28 = ((Integer) _optobj).intValue();
      _optargs_bitmask |= 134217728L;
    }
    int opt29 = 0;
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("opt29");
    if (_optobj != null) {
      opt29 = ((Integer) _optobj).intValue();
      _optargs_bitmask |= 268435456L;
    }
    int opt30 = 0;
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("opt30");
    if (_optobj != null) {
      opt30 = ((Integer) _optobj).intValue();
      _optargs_bitmask |= 536870912L;
    }
    int opt31 = 0;
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("opt31");
    if (_optobj != null) {
      opt31 = ((Integer) _optobj).intValue();
      _optargs_bitmask |= 1073741824L;
    }
    int opt32 = 0;
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("opt32");
    if (_optobj != null) {
      opt32 = ((Integer) _optobj).intValue();
      _optargs_bitmask |= 2147483648L;
    }
    int opt33 = 0;
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("opt33");
    if (_optobj != null) {
      opt33 = ((Integer) _optobj).intValue();
      _optargs_bitmask |= 4294967296L;
    }
    int opt34 = 0;
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("opt34");
    if (_optobj != null) {
      opt34 = ((Integer) _optobj).intValue();
      _optargs_bitmask |= 8589934592L;
    }
    int opt35 = 0;
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("opt35");
    if (_optobj != null) {
      opt35 = ((Integer) _optobj).intValue();
      _optargs_bitmask |= 17179869184L;
    }
    int opt36 = 0;
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("opt36");
    if (_optobj != null) {
      opt36 = ((Integer) _optobj).intValue();
      _optargs_bitmask |= 34359738368L;
    }
    int opt37 = 0;
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("opt37");
    if (_optobj != null) {
      opt37 = ((Integer) _optobj).intValue();
      _optargs_bitmask |= 68719476736L;
    }
    int opt38 = 0;
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("opt38");
    if (_optobj != null) {
      opt38 = ((Integer) _optobj).intValue();
      _optargs_bitmask |= 137438953472L;
    }
    int opt39 = 0;
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("opt39");
    if (_optobj != null) {
      opt39 = ((Integer) _optobj).intValue();
      _optargs_bitmask |= 274877906944L;
    }
    int opt40 = 0;
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("opt40");
    if (_optobj != null) {
      opt40 = ((Integer) _optobj).intValue();
      _optargs_bitmask |= 549755813888L;
    }
    int opt41 = 0;
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("opt41");
    if (_optobj != null) {
      opt41 = ((Integer) _optobj).intValue();
      _optargs_bitmask |= 1099511627776L;
    }
    int opt42 = 0;
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("opt42");
    if (_optobj != null) {
      opt42 = ((Integer) _optobj).intValue();
      _optargs_bitmask |= 2199023255552L;
    }
    int opt43 = 0;
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("opt43");
    if (_optobj != null) {
      opt43 = ((Integer) _optobj).intValue();
      _optargs_bitmask |= 4398046511104L;
    }
    int opt44 = 0;
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("opt44");
    if (_optobj != null) {
      opt44 = ((Integer) _optobj).intValue();
      _optargs_bitmask |= 8796093022208L;
    }
    int opt45 = 0;
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("opt45");
    if (_optobj != null) {
      opt45 = ((Integer) _optobj).intValue();
      _optargs_bitmask |= 17592186044416L;
    }
    int opt46 = 0;
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("opt46");
    if (_optobj != null) {
      opt46 = ((Integer) _optobj).intValue();
      _optargs_bitmask |= 35184372088832L;
    }
    int opt47 = 0;
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("opt47");
    if (_optobj != null) {
      opt47 = ((Integer) _optobj).intValue();
      _optargs_bitmask |= 70368744177664L;
    }
    int opt48 = 0;
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("opt48");
    if (_optobj != null) {
      opt48 = ((Integer) _optobj).intValue();
      _optargs_bitmask |= 140737488355328L;
    }
    int opt49 = 0;
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("opt49");
    if (_optobj != null) {
      opt49 = ((Integer) _optobj).intValue();
      _optargs_bitmask |= 281474976710656L;
    }
    int opt50 = 0;
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("opt50");
    if (_optobj != null) {
      opt50 = ((Integer) _optobj).intValue();
      _optargs_bitmask |= 562949953421312L;
    }
    int opt51 = 0;
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("opt51");
    if (_optobj != null) {
      opt51 = ((Integer) _optobj).intValue();
      _optargs_bitmask |= 1125899906842624L;
    }
    int opt52 = 0;
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("opt52");
    if (_optobj != null) {
      opt52 = ((Integer) _optobj).intValue();
      _optargs_bitmask |= 2251799813685248L;
    }
    int opt53 = 0;
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("opt53");
    if (_optobj != null) {
      opt53 = ((Integer) _optobj).intValue();
      _optargs_bitmask |= 4503599627370496L;
    }
    int opt54 = 0;
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("opt54");
    if (_optobj != null) {
      opt54 = ((Integer) _optobj).intValue();
      _optargs_bitmask |= 9007199254740992L;
    }
    int opt55 = 0;
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("opt55");
    if (_optobj != null) {
      opt55 = ((Integer) _optobj).intValue();
      _optargs_bitmask |= 18014398509481984L;
    }
    int opt56 = 0;
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("opt56");
    if (_optobj != null) {
      opt56 = ((Integer) _optobj).intValue();
      _optargs_bitmask |= 36028797018963968L;
    }
    int opt57 = 0;
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("opt57");
    if (_optobj != null) {
      opt57 = ((Integer) _optobj).intValue();
      _optargs_bitmask |= 72057594037927936L;
    }
    int opt58 = 0;
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("opt58");
    if (_optobj != null) {
      opt58 = ((Integer) _optobj).intValue();
      _optargs_bitmask |= 144115188075855872L;
    }
    int opt59 = 0;
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("opt59");
    if (_optobj != null) {
      opt59 = ((Integer) _optobj).intValue();
      _optargs_bitmask |= 288230376151711744L;
    }
    int opt60 = 0;
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("opt60");
    if (_optobj != null) {
      opt60 = ((Integer) _optobj).intValue();
      _optargs_bitmask |= 576460752303423488L;
    }
    int opt61 = 0;
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("opt61");
    if (_optobj != null) {
      opt61 = ((Integer) _optobj).intValue();
      _optargs_bitmask |= 1152921504606846976L;
    }
    int opt62 = 0;
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("opt62");
    if (_optobj != null) {
      opt62 = ((Integer) _optobj).intValue();
      _optargs_bitmask |= 2305843009213693952L;
    }
    int opt63 = 0;
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("opt63");
    if (_optobj != null) {
      opt63 = ((Integer) _optobj).intValue();
      _optargs_bitmask |= 4611686018427387904L;
    }

    _internal_test_63_optargs (g, _optargs_bitmask, opt1, opt2, opt3, opt4, opt5, opt6, opt7, opt8, opt9, opt10, opt11, opt12, opt13, opt14, opt15, opt16, opt17, opt18, opt19, opt20, opt21, opt22, opt23, opt24, opt25, opt26, opt27, opt28, opt29, opt30, opt31, opt32, opt33, opt34, opt35, opt36, opt37, opt38, opt39, opt40, opt41, opt42, opt43, opt44, opt45, opt46, opt47, opt48, opt49, opt50, opt51, opt52, opt53, opt54, opt55, opt56, opt57, opt58, opt59, opt60, opt61, opt62, opt63);
  }

  public void internal_test_63_optargs ()
    throws LibGuestFSException
  {
    internal_test_63_optargs (null);
  }

  private native void _internal_test_63_optargs (long g, long _optargs_bitmask, int opt1, int opt2, int opt3, int opt4, int opt5, int opt6, int opt7, int opt8, int opt9, int opt10, int opt11, int opt12, int opt13, int opt14, int opt15, int opt16, int opt17, int opt18, int opt19, int opt20, int opt21, int opt22, int opt23, int opt24, int opt25, int opt26, int opt27, int opt28, int opt29, int opt30, int opt31, int opt32, int opt33, int opt34, int opt35, int opt36, int opt37, int opt38, int opt39, int opt40, int opt41, int opt42, int opt43, int opt44, int opt45, int opt46, int opt47, int opt48, int opt49, int opt50, int opt51, int opt52, int opt53, int opt54, int opt55, int opt56, int opt57, int opt58, int opt59, int opt60, int opt61, int opt62, int opt63)
    throws LibGuestFSException;

  public void internal_test_close_output ()
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("internal_test_close_output: handle is closed");

    _internal_test_close_output (g);
  }

  private native void _internal_test_close_output (long g)
    throws LibGuestFSException;

  public void internal_test_only_optargs (Map<String, Object> optargs)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("internal_test_only_optargs: handle is closed");

    /* Unpack optional args. */
    Object _optobj;
    long _optargs_bitmask = 0;
    int test = 0;
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("test");
    if (_optobj != null) {
      test = ((Integer) _optobj).intValue();
      _optargs_bitmask |= 1L;
    }

    _internal_test_only_optargs (g, _optargs_bitmask, test);
  }

  public void internal_test_only_optargs ()
    throws LibGuestFSException
  {
    internal_test_only_optargs (null);
  }

  private native void _internal_test_only_optargs (long g, long _optargs_bitmask, int test)
    throws LibGuestFSException;

  public boolean internal_test_rbool (String val)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("internal_test_rbool: handle is closed");

    return _internal_test_rbool (g, val);
  }

  private native boolean _internal_test_rbool (long g, String val)
    throws LibGuestFSException;

  public boolean internal_test_rboolerr ()
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("internal_test_rboolerr: handle is closed");

    return _internal_test_rboolerr (g);
  }

  private native boolean _internal_test_rboolerr (long g)
    throws LibGuestFSException;

  public String internal_test_rbufferout (String val)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("internal_test_rbufferout: handle is closed");

    return _internal_test_rbufferout (g, val);
  }

  private native String _internal_test_rbufferout (long g, String val)
    throws LibGuestFSException;

  public String internal_test_rbufferouterr ()
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("internal_test_rbufferouterr: handle is closed");

    return _internal_test_rbufferouterr (g);
  }

  private native String _internal_test_rbufferouterr (long g)
    throws LibGuestFSException;

  public String internal_test_rconstoptstring (String val)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("internal_test_rconstoptstring: handle is closed");

    return _internal_test_rconstoptstring (g, val);
  }

  private native String _internal_test_rconstoptstring (long g, String val)
    throws LibGuestFSException;

  public String internal_test_rconstoptstringerr ()
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("internal_test_rconstoptstringerr: handle is closed");

    return _internal_test_rconstoptstringerr (g);
  }

  private native String _internal_test_rconstoptstringerr (long g)
    throws LibGuestFSException;

  public String internal_test_rconststring (String val)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("internal_test_rconststring: handle is closed");

    return _internal_test_rconststring (g, val);
  }

  private native String _internal_test_rconststring (long g, String val)
    throws LibGuestFSException;

  public String internal_test_rconststringerr ()
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("internal_test_rconststringerr: handle is closed");

    return _internal_test_rconststringerr (g);
  }

  private native String _internal_test_rconststringerr (long g)
    throws LibGuestFSException;

  public Map<String,String> internal_test_rhashtable (String val)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("internal_test_rhashtable: handle is closed");

    String[] r = _internal_test_rhashtable (g, val);

    HashMap<String, String> rhash = new HashMap<String, String> ();
    for (int i = 0; i < r.length; i += 2)
      rhash.put (r[i], r[i+1]);
    return rhash;
  }

  private native String[] _internal_test_rhashtable (long g, String val)
    throws LibGuestFSException;

  public Map<String,String> internal_test_rhashtableerr ()
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("internal_test_rhashtableerr: handle is closed");

    String[] r = _internal_test_rhashtableerr (g);

    HashMap<String, String> rhash = new HashMap<String, String> ();
    for (int i = 0; i < r.length; i += 2)
      rhash.put (r[i], r[i+1]);
    return rhash;
  }

  private native String[] _internal_test_rhashtableerr (long g)
    throws LibGuestFSException;

  public int internal_test_rint (String val)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("internal_test_rint: handle is closed");

    return _internal_test_rint (g, val);
  }

  private native int _internal_test_rint (long g, String val)
    throws LibGuestFSException;

  public long internal_test_rint64 (String val)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("internal_test_rint64: handle is closed");

    return _internal_test_rint64 (g, val);
  }

  private native long _internal_test_rint64 (long g, String val)
    throws LibGuestFSException;

  public long internal_test_rint64err ()
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("internal_test_rint64err: handle is closed");

    return _internal_test_rint64err (g);
  }

  private native long _internal_test_rint64err (long g)
    throws LibGuestFSException;

  public int internal_test_rinterr ()
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("internal_test_rinterr: handle is closed");

    return _internal_test_rinterr (g);
  }

  private native int _internal_test_rinterr (long g)
    throws LibGuestFSException;

  public String internal_test_rstring (String val)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("internal_test_rstring: handle is closed");

    return _internal_test_rstring (g, val);
  }

  private native String _internal_test_rstring (long g, String val)
    throws LibGuestFSException;

  public String internal_test_rstringerr ()
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("internal_test_rstringerr: handle is closed");

    return _internal_test_rstringerr (g);
  }

  private native String _internal_test_rstringerr (long g)
    throws LibGuestFSException;

  public String[] internal_test_rstringlist (String val)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("internal_test_rstringlist: handle is closed");

    return _internal_test_rstringlist (g, val);
  }

  private native String[] _internal_test_rstringlist (long g, String val)
    throws LibGuestFSException;

  public String[] internal_test_rstringlisterr ()
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("internal_test_rstringlisterr: handle is closed");

    return _internal_test_rstringlisterr (g);
  }

  private native String[] _internal_test_rstringlisterr (long g)
    throws LibGuestFSException;

  public PV internal_test_rstruct (String val)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("internal_test_rstruct: handle is closed");

    return _internal_test_rstruct (g, val);
  }

  private native PV _internal_test_rstruct (long g, String val)
    throws LibGuestFSException;

  public PV internal_test_rstructerr ()
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("internal_test_rstructerr: handle is closed");

    return _internal_test_rstructerr (g);
  }

  private native PV _internal_test_rstructerr (long g)
    throws LibGuestFSException;

  public PV[] internal_test_rstructlist (String val)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("internal_test_rstructlist: handle is closed");

    return _internal_test_rstructlist (g, val);
  }

  private native PV[] _internal_test_rstructlist (long g, String val)
    throws LibGuestFSException;

  public PV[] internal_test_rstructlisterr ()
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("internal_test_rstructlisterr: handle is closed");

    return _internal_test_rstructlisterr (g);
  }

  private native PV[] _internal_test_rstructlisterr (long g)
    throws LibGuestFSException;

  public void internal_test_set_output (String filename)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("internal_test_set_output: handle is closed");

    _internal_test_set_output (g, filename);
  }

  private native void _internal_test_set_output (long g, String filename)
    throws LibGuestFSException;

  /**
   * <p>
   * test if block device
   * </p><p>
   * This returns "true" if and only if there is a block
   * device with the given "path" name.
   * </p><p>
   * If the optional flag "followsymlinks" is true, then a
   * symlink (or chain of symlinks) that ends with a block
   * device also causes the function to return true.
   * </p><p>
   * This call only looks at files within the guest
   * filesystem. Libguestfs partitions and block devices (eg.
   * /dev/sda) cannot be used as the "path" parameter of this
   * call.
   * </p><p>
   * See also "g.stat".
   * </p><p>
   * Optional arguments are supplied in the final
   * Map&lt;String,Object&gt; parameter, which is a hash of the
   * argument name to its value (cast to Object). Pass an
   * empty Map or null for no optional arguments.
   * </p><p>
   * </p>
   * @since 1.5.10
   * @throws LibGuestFSException
   */
  public boolean is_blockdev (String path, Map<String, Object> optargs)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("is_blockdev: handle is closed");

    /* Unpack optional args. */
    Object _optobj;
    long _optargs_bitmask = 0;
    boolean followsymlinks = false;
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("followsymlinks");
    if (_optobj != null) {
      followsymlinks = ((Boolean) _optobj).booleanValue();
      _optargs_bitmask |= 1L;
    }

    return _is_blockdev (g, path, _optargs_bitmask, followsymlinks);
  }

  public boolean is_blockdev (String path)
    throws LibGuestFSException
  {
    return is_blockdev (path, null);
  }

  public boolean is_blockdev_opts (String path, Map<String, Object> optargs)
    throws LibGuestFSException
  {
    return is_blockdev (path, optargs);
  }

  public boolean is_blockdev_opts (String path)
    throws LibGuestFSException
  {
    return is_blockdev (path, null);
  }

  private native boolean _is_blockdev (long g, String path, long _optargs_bitmask, boolean followsymlinks)
    throws LibGuestFSException;

  /**
   * <p>
   * is busy processing a command
   * </p><p>
   * This always returns false. This function is deprecated
   * with no replacement. Do not use this function.
   * </p><p>
   * For more information on states, see guestfs(3).
   * </p><p>
   * </p>
   * @since 1.0.2
   * @throws LibGuestFSException
   */
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
   * <p>
   * test if character device
   * </p><p>
   * This returns "true" if and only if there is a character
   * device with the given "path" name.
   * </p><p>
   * If the optional flag "followsymlinks" is true, then a
   * symlink (or chain of symlinks) that ends with a chardev
   * also causes the function to return true.
   * </p><p>
   * See also "g.stat".
   * </p><p>
   * Optional arguments are supplied in the final
   * Map&lt;String,Object&gt; parameter, which is a hash of the
   * argument name to its value (cast to Object). Pass an
   * empty Map or null for no optional arguments.
   * </p><p>
   * </p>
   * @since 1.5.10
   * @throws LibGuestFSException
   */
  public boolean is_chardev (String path, Map<String, Object> optargs)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("is_chardev: handle is closed");

    /* Unpack optional args. */
    Object _optobj;
    long _optargs_bitmask = 0;
    boolean followsymlinks = false;
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("followsymlinks");
    if (_optobj != null) {
      followsymlinks = ((Boolean) _optobj).booleanValue();
      _optargs_bitmask |= 1L;
    }

    return _is_chardev (g, path, _optargs_bitmask, followsymlinks);
  }

  public boolean is_chardev (String path)
    throws LibGuestFSException
  {
    return is_chardev (path, null);
  }

  public boolean is_chardev_opts (String path, Map<String, Object> optargs)
    throws LibGuestFSException
  {
    return is_chardev (path, optargs);
  }

  public boolean is_chardev_opts (String path)
    throws LibGuestFSException
  {
    return is_chardev (path, null);
  }

  private native boolean _is_chardev (long g, String path, long _optargs_bitmask, boolean followsymlinks)
    throws LibGuestFSException;

  /**
   * <p>
   * is in configuration state
   * </p><p>
   * This returns true iff this handle is being configured
   * (in the "CONFIG" state).
   * </p><p>
   * For more information on states, see guestfs(3).
   * </p><p>
   * </p>
   * @since 1.0.2
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
   * <p>
   * test if a directory
   * </p><p>
   * This returns "true" if and only if there is a directory
   * with the given "path" name. Note that it returns false
   * for other objects like files.
   * </p><p>
   * If the optional flag "followsymlinks" is true, then a
   * symlink (or chain of symlinks) that ends with a
   * directory also causes the function to return true.
   * </p><p>
   * See also "g.stat".
   * </p><p>
   * Optional arguments are supplied in the final
   * Map&lt;String,Object&gt; parameter, which is a hash of the
   * argument name to its value (cast to Object). Pass an
   * empty Map or null for no optional arguments.
   * </p><p>
   * </p>
   * @since 0.8
   * @throws LibGuestFSException
   */
  public boolean is_dir (String path, Map<String, Object> optargs)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("is_dir: handle is closed");

    /* Unpack optional args. */
    Object _optobj;
    long _optargs_bitmask = 0;
    boolean followsymlinks = false;
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("followsymlinks");
    if (_optobj != null) {
      followsymlinks = ((Boolean) _optobj).booleanValue();
      _optargs_bitmask |= 1L;
    }

    return _is_dir (g, path, _optargs_bitmask, followsymlinks);
  }

  public boolean is_dir (String path)
    throws LibGuestFSException
  {
    return is_dir (path, null);
  }

  public boolean is_dir_opts (String path, Map<String, Object> optargs)
    throws LibGuestFSException
  {
    return is_dir (path, optargs);
  }

  public boolean is_dir_opts (String path)
    throws LibGuestFSException
  {
    return is_dir (path, null);
  }

  private native boolean _is_dir (long g, String path, long _optargs_bitmask, boolean followsymlinks)
    throws LibGuestFSException;

  /**
   * <p>
   * test if FIFO (named pipe)
   * </p><p>
   * This returns "true" if and only if there is a FIFO
   * (named pipe) with the given "path" name.
   * </p><p>
   * If the optional flag "followsymlinks" is true, then a
   * symlink (or chain of symlinks) that ends with a FIFO
   * also causes the function to return true.
   * </p><p>
   * See also "g.stat".
   * </p><p>
   * Optional arguments are supplied in the final
   * Map&lt;String,Object&gt; parameter, which is a hash of the
   * argument name to its value (cast to Object). Pass an
   * empty Map or null for no optional arguments.
   * </p><p>
   * </p>
   * @since 1.5.10
   * @throws LibGuestFSException
   */
  public boolean is_fifo (String path, Map<String, Object> optargs)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("is_fifo: handle is closed");

    /* Unpack optional args. */
    Object _optobj;
    long _optargs_bitmask = 0;
    boolean followsymlinks = false;
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("followsymlinks");
    if (_optobj != null) {
      followsymlinks = ((Boolean) _optobj).booleanValue();
      _optargs_bitmask |= 1L;
    }

    return _is_fifo (g, path, _optargs_bitmask, followsymlinks);
  }

  public boolean is_fifo (String path)
    throws LibGuestFSException
  {
    return is_fifo (path, null);
  }

  public boolean is_fifo_opts (String path, Map<String, Object> optargs)
    throws LibGuestFSException
  {
    return is_fifo (path, optargs);
  }

  public boolean is_fifo_opts (String path)
    throws LibGuestFSException
  {
    return is_fifo (path, null);
  }

  private native boolean _is_fifo (long g, String path, long _optargs_bitmask, boolean followsymlinks)
    throws LibGuestFSException;

  /**
   * <p>
   * test if a regular file
   * </p><p>
   * This returns "true" if and only if there is a regular
   * file with the given "path" name. Note that it returns
   * false for other objects like directories.
   * </p><p>
   * If the optional flag "followsymlinks" is true, then a
   * symlink (or chain of symlinks) that ends with a file
   * also causes the function to return true.
   * </p><p>
   * See also "g.stat".
   * </p><p>
   * Optional arguments are supplied in the final
   * Map&lt;String,Object&gt; parameter, which is a hash of the
   * argument name to its value (cast to Object). Pass an
   * empty Map or null for no optional arguments.
   * </p><p>
   * </p>
   * @since 0.8
   * @throws LibGuestFSException
   */
  public boolean is_file (String path, Map<String, Object> optargs)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("is_file: handle is closed");

    /* Unpack optional args. */
    Object _optobj;
    long _optargs_bitmask = 0;
    boolean followsymlinks = false;
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("followsymlinks");
    if (_optobj != null) {
      followsymlinks = ((Boolean) _optobj).booleanValue();
      _optargs_bitmask |= 1L;
    }

    return _is_file (g, path, _optargs_bitmask, followsymlinks);
  }

  public boolean is_file (String path)
    throws LibGuestFSException
  {
    return is_file (path, null);
  }

  public boolean is_file_opts (String path, Map<String, Object> optargs)
    throws LibGuestFSException
  {
    return is_file (path, optargs);
  }

  public boolean is_file_opts (String path)
    throws LibGuestFSException
  {
    return is_file (path, null);
  }

  private native boolean _is_file (long g, String path, long _optargs_bitmask, boolean followsymlinks)
    throws LibGuestFSException;

  /**
   * <p>
   * is launching subprocess
   * </p><p>
   * This returns true iff this handle is launching the
   * subprocess (in the "LAUNCHING" state).
   * </p><p>
   * For more information on states, see guestfs(3).
   * </p><p>
   * </p>
   * @since 1.0.2
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

  /**
   * <p>
   * test if device is a logical volume
   * </p><p>
   * This command tests whether "device" is a logical volume,
   * and returns true iff this is the case.
   * </p><p>
   * </p>
   * @since 1.5.3
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
   * <p>
   * is ready to accept commands
   * </p><p>
   * This returns true iff this handle is ready to accept
   * commands (in the "READY" state).
   * </p><p>
   * For more information on states, see guestfs(3).
   * </p><p>
   * </p>
   * @since 1.0.2
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
   * <p>
   * test if socket
   * </p><p>
   * This returns "true" if and only if there is a Unix
   * domain socket with the given "path" name.
   * </p><p>
   * If the optional flag "followsymlinks" is true, then a
   * symlink (or chain of symlinks) that ends with a socket
   * also causes the function to return true.
   * </p><p>
   * See also "g.stat".
   * </p><p>
   * Optional arguments are supplied in the final
   * Map&lt;String,Object&gt; parameter, which is a hash of the
   * argument name to its value (cast to Object). Pass an
   * empty Map or null for no optional arguments.
   * </p><p>
   * </p>
   * @since 1.5.10
   * @throws LibGuestFSException
   */
  public boolean is_socket (String path, Map<String, Object> optargs)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("is_socket: handle is closed");

    /* Unpack optional args. */
    Object _optobj;
    long _optargs_bitmask = 0;
    boolean followsymlinks = false;
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("followsymlinks");
    if (_optobj != null) {
      followsymlinks = ((Boolean) _optobj).booleanValue();
      _optargs_bitmask |= 1L;
    }

    return _is_socket (g, path, _optargs_bitmask, followsymlinks);
  }

  public boolean is_socket (String path)
    throws LibGuestFSException
  {
    return is_socket (path, null);
  }

  public boolean is_socket_opts (String path, Map<String, Object> optargs)
    throws LibGuestFSException
  {
    return is_socket (path, optargs);
  }

  public boolean is_socket_opts (String path)
    throws LibGuestFSException
  {
    return is_socket (path, null);
  }

  private native boolean _is_socket (long g, String path, long _optargs_bitmask, boolean followsymlinks)
    throws LibGuestFSException;

  /**
   * <p>
   * test if symbolic link
   * </p><p>
   * This returns "true" if and only if there is a symbolic
   * link with the given "path" name.
   * </p><p>
   * See also "g.stat".
   * </p><p>
   * </p>
   * @since 1.5.10
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
   * <p>
   * test if a device is a whole device
   * </p><p>
   * This returns "true" if and only if "device" refers to a
   * whole block device. That is, not a partition or a
   * logical device.
   * </p><p>
   * </p>
   * @since 1.21.9
   * @throws LibGuestFSException
   */
  public boolean is_whole_device (String device)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("is_whole_device: handle is closed");

    return _is_whole_device (g, device);
  }

  private native boolean _is_whole_device (long g, String device)
    throws LibGuestFSException;

  /**
   * <p>
   * test if a file contains all zero bytes
   * </p><p>
   * This returns true iff the file exists and the file is
   * empty or it contains all zero bytes.
   * </p><p>
   * </p>
   * @since 1.11.8
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
   * <p>
   * test if a device contains all zero bytes
   * </p><p>
   * This returns true iff the device exists and contains all
   * zero bytes.
   * </p><p>
   * Note that for large devices this can take a long time to
   * run.
   * </p><p>
   * </p>
   * @since 1.11.8
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
   * <p>
   * get ISO information from primary volume descriptor of ISO file
   * </p><p>
   * This is the same as "g.isoinfo_device" except that it
   * works for an ISO file located inside some other mounted
   * filesystem. Note that in the common case where you have
   * added an ISO file as a libguestfs device, you would
   * *not* call this. Instead you would call
   * "g.isoinfo_device".
   * </p><p>
   * </p>
   * @since 1.17.19
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
   * <p>
   * get ISO information from primary volume descriptor of device
   * </p><p>
   * "device" is an ISO device. This returns a struct of
   * information read from the primary volume descriptor (the
   * ISO equivalent of the superblock) of the device.
   * </p><p>
   * Usually it is more efficient to use the isoinfo(1)
   * command with the *-d* option on the host to analyze ISO
   * files, instead of going through libguestfs.
   * </p><p>
   * For information on the primary volume descriptor fields,
   * see
   * &lt;http://wiki.osdev.org/ISO_9660#The_Primary_Volume_Descr
   * iptor&gt;
   * </p><p>
   * </p>
   * @since 1.17.19
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
   * <p>
   * close the systemd journal
   * </p><p>
   * Close the journal handle.
   * </p><p>
   * </p>
   * @since 1.23.11
   * @throws LibGuestFSException
   */
  public void journal_close ()
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("journal_close: handle is closed");

    _journal_close (g);
  }

  private native void _journal_close (long g)
    throws LibGuestFSException;

  /**
   * <p>
   * read the current journal entry
   * </p><p>
   * Read the current journal entry. This returns all the
   * fields in the journal as a set of "(attrname, attrval)"
   * pairs. The "attrname" is the field name (a string).
   * </p><p>
   * The "attrval" is the field value (a binary blob, often
   * but not always a string). Please note that "attrval" is
   * a byte array, *not* a \0-terminated C string.
   * </p><p>
   * The length of data may be truncated to the data
   * threshold (see: "g.journal_set_data_threshold",
   * "g.journal_get_data_threshold").
   * </p><p>
   * If you set the data threshold to unlimited (0) then this
   * call can read a journal entry of any size, ie. it is not
   * limited by the libguestfs protocol.
   * </p><p>
   * </p>
   * @since 1.23.11
   * @throws LibGuestFSException
   */
  public XAttr[] journal_get ()
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("journal_get: handle is closed");

    return _journal_get (g);
  }

  private native XAttr[] _journal_get (long g)
    throws LibGuestFSException;

  /**
   * <p>
   * get the data threshold for reading journal entries
   * </p><p>
   * Get the current data threshold for reading journal
   * entries. This is a hint to the journal that it may
   * truncate data fields to this size when reading them
   * (note also that it may not truncate them). If this
   * returns 0, then the threshold is unlimited.
   * </p><p>
   * See also "g.journal_set_data_threshold".
   * </p><p>
   * </p>
   * @since 1.23.11
   * @throws LibGuestFSException
   */
  public long journal_get_data_threshold ()
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("journal_get_data_threshold: handle is closed");

    return _journal_get_data_threshold (g);
  }

  private native long _journal_get_data_threshold (long g)
    throws LibGuestFSException;

  /**
   * <p>
   * get the timestamp of the current journal entry
   * </p><p>
   * Get the realtime (wallclock) timestamp of the current
   * journal entry.
   * </p><p>
   * </p>
   * @since 1.27.18
   * @throws LibGuestFSException
   */
  public long journal_get_realtime_usec ()
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("journal_get_realtime_usec: handle is closed");

    return _journal_get_realtime_usec (g);
  }

  private native long _journal_get_realtime_usec (long g)
    throws LibGuestFSException;

  /**
   * <p>
   * move to the next journal entry
   * </p><p>
   * Move to the next journal entry. You have to call this at
   * least once after opening the handle before you are able
   * to read data.
   * </p><p>
   * The returned boolean tells you if there are any more
   * journal records to read. "true" means you can read the
   * next record (eg. using "g.journal_get"), and "false"
   * means you have reached the end of the journal.
   * </p><p>
   * </p>
   * @since 1.23.11
   * @throws LibGuestFSException
   */
  public boolean journal_next ()
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("journal_next: handle is closed");

    return _journal_next (g);
  }

  private native boolean _journal_next (long g)
    throws LibGuestFSException;

  /**
   * <p>
   * open the systemd journal
   * </p><p>
   * Open the systemd journal located in directory. Any
   * previously opened journal handle is closed.
   * </p><p>
   * The contents of the journal can be read using
   * "g.journal_next" and "g.journal_get".
   * </p><p>
   * After you have finished using the journal, you should
   * close the handle by calling "g.journal_close".
   * </p><p>
   * </p>
   * @since 1.23.11
   * @throws LibGuestFSException
   */
  public void journal_open (String directory)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("journal_open: handle is closed");

    _journal_open (g, directory);
  }

  private native void _journal_open (long g, String directory)
    throws LibGuestFSException;

  /**
   * <p>
   * set the data threshold for reading journal entries
   * </p><p>
   * Set the data threshold for reading journal entries. This
   * is a hint to the journal that it may truncate data
   * fields to this size when reading them (note also that it
   * may not truncate them). If you set this to 0, then the
   * threshold is unlimited.
   * </p><p>
   * See also "g.journal_get_data_threshold".
   * </p><p>
   * </p>
   * @since 1.23.11
   * @throws LibGuestFSException
   */
  public void journal_set_data_threshold (long threshold)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("journal_set_data_threshold: handle is closed");

    _journal_set_data_threshold (g, threshold);
  }

  private native void _journal_set_data_threshold (long g, long threshold)
    throws LibGuestFSException;

  /**
   * <p>
   * skip forwards or backwards in the journal
   * </p><p>
   * Skip forwards ("skip ≥ 0") or backwards ("skip &lt; 0") in
   * the journal.
   * </p><p>
   * The number of entries actually skipped is returned (note
   * "rskip ≥ 0"). If this is not the same as the absolute
   * value of the skip parameter ("|skip|") you passed in
   * then it means you have reached the end or the start of
   * the journal.
   * </p><p>
   * </p>
   * @since 1.23.11
   * @throws LibGuestFSException
   */
  public long journal_skip (long skip)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("journal_skip: handle is closed");

    return _journal_skip (g, skip);
  }

  private native long _journal_skip (long g, long skip)
    throws LibGuestFSException;

  /**
   * <p>
   * kill the hypervisor
   * </p><p>
   * This kills the hypervisor.
   * </p><p>
   * Do not call this. See: "g.shutdown" instead.
   * </p><p>
   * </p>
   * @since 0.3
   * @deprecated In new code, use {@link #shutdown} instead
   * @throws LibGuestFSException
   */
  @Deprecated public void kill_subprocess ()
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("kill_subprocess: handle is closed");

    _kill_subprocess (g);
  }

  private native void _kill_subprocess (long g)
    throws LibGuestFSException;

  /**
   * <p>
   * launch the backend
   * </p><p>
   * You should call this after configuring the handle (eg.
   * adding drives) but before performing any actions.
   * </p><p>
   * Do not call "g.launch" twice on the same handle.
   * Although it will not give an error (for historical
   * reasons), the precise behaviour when you do this is not
   * well defined. Handles are very cheap to create, so
   * create a new one for each launch.
   * </p><p>
   * </p>
   * @since 0.3
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
   * <p>
   * change file owner and group
   * </p><p>
   * Change the file owner to "owner" and group to "group".
   * This is like "g.chown" but if "path" is a symlink then
   * the link itself is changed, not the target.
   * </p><p>
   * Only numeric uid and gid are supported. If you want to
   * use names, you will need to locate and parse the
   * password file yourself (Augeas support makes this
   * relatively easy).
   * </p><p>
   * </p>
   * @since 1.0.77
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
   * <p>
   * scan and create Windows dynamic disk volumes
   * </p><p>
   * This function scans all block devices looking for
   * Windows dynamic disk volumes and partitions, and creates
   * devices for any that were found.
   * </p><p>
   * Call "g.list_ldm_volumes" and "g.list_ldm_partitions" to
   * return all devices.
   * </p><p>
   * Note that you don't normally need to call this
   * explicitly, since it is done automatically at "g.launch"
   * time. However you might want to call this function if
   * you have hotplugged disks or have just created a Windows
   * dynamic disk.
   * </p><p>
   * </p>
   * @since 1.20.0
   * @throws LibGuestFSException
   */
  public void ldmtool_create_all ()
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("ldmtool_create_all: handle is closed");

    _ldmtool_create_all (g);
  }

  private native void _ldmtool_create_all (long g)
    throws LibGuestFSException;

  /**
   * <p>
   * return the disks in a Windows dynamic disk group
   * </p><p>
   * Return the disks in a Windows dynamic disk group. The
   * "diskgroup" parameter should be the GUID of a disk
   * group, one element from the list returned by
   * "g.ldmtool_scan".
   * </p><p>
   * </p>
   * @since 1.20.0
   * @throws LibGuestFSException
   */
  public String[] ldmtool_diskgroup_disks (String diskgroup)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("ldmtool_diskgroup_disks: handle is closed");

    return _ldmtool_diskgroup_disks (g, diskgroup);
  }

  private native String[] _ldmtool_diskgroup_disks (long g, String diskgroup)
    throws LibGuestFSException;

  /**
   * <p>
   * return the name of a Windows dynamic disk group
   * </p><p>
   * Return the name of a Windows dynamic disk group. The
   * "diskgroup" parameter should be the GUID of a disk
   * group, one element from the list returned by
   * "g.ldmtool_scan".
   * </p><p>
   * </p>
   * @since 1.20.0
   * @throws LibGuestFSException
   */
  public String ldmtool_diskgroup_name (String diskgroup)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("ldmtool_diskgroup_name: handle is closed");

    return _ldmtool_diskgroup_name (g, diskgroup);
  }

  private native String _ldmtool_diskgroup_name (long g, String diskgroup)
    throws LibGuestFSException;

  /**
   * <p>
   * return the volumes in a Windows dynamic disk group
   * </p><p>
   * Return the volumes in a Windows dynamic disk group. The
   * "diskgroup" parameter should be the GUID of a disk
   * group, one element from the list returned by
   * "g.ldmtool_scan".
   * </p><p>
   * </p>
   * @since 1.20.0
   * @throws LibGuestFSException
   */
  public String[] ldmtool_diskgroup_volumes (String diskgroup)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("ldmtool_diskgroup_volumes: handle is closed");

    return _ldmtool_diskgroup_volumes (g, diskgroup);
  }

  private native String[] _ldmtool_diskgroup_volumes (long g, String diskgroup)
    throws LibGuestFSException;

  /**
   * <p>
   * remove all Windows dynamic disk volumes
   * </p><p>
   * This is essentially the opposite of
   * "g.ldmtool_create_all". It removes the device mapper
   * mappings for all Windows dynamic disk volumes
   * </p><p>
   * </p>
   * @since 1.20.0
   * @throws LibGuestFSException
   */
  public void ldmtool_remove_all ()
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("ldmtool_remove_all: handle is closed");

    _ldmtool_remove_all (g);
  }

  private native void _ldmtool_remove_all (long g)
    throws LibGuestFSException;

  /**
   * <p>
   * scan for Windows dynamic disks
   * </p><p>
   * This function scans for Windows dynamic disks. It
   * returns a list of identifiers (GUIDs) for all disk
   * groups that were found. These identifiers can be passed
   * to other "g.ldmtool_*" functions.
   * </p><p>
   * This function scans all block devices. To scan a subset
   * of block devices, call "g.ldmtool_scan_devices" instead.
   * </p><p>
   * </p>
   * @since 1.20.0
   * @throws LibGuestFSException
   */
  public String[] ldmtool_scan ()
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("ldmtool_scan: handle is closed");

    return _ldmtool_scan (g);
  }

  private native String[] _ldmtool_scan (long g)
    throws LibGuestFSException;

  /**
   * <p>
   * scan for Windows dynamic disks
   * </p><p>
   * This function scans for Windows dynamic disks. It
   * returns a list of identifiers (GUIDs) for all disk
   * groups that were found. These identifiers can be passed
   * to other "g.ldmtool_*" functions.
   * </p><p>
   * The parameter "devices" is a list of block devices which
   * are scanned. If this list is empty, all block devices
   * are scanned.
   * </p><p>
   * </p>
   * @since 1.20.0
   * @throws LibGuestFSException
   */
  public String[] ldmtool_scan_devices (String[] devices)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("ldmtool_scan_devices: handle is closed");

    return _ldmtool_scan_devices (g, devices);
  }

  private native String[] _ldmtool_scan_devices (long g, String[] devices)
    throws LibGuestFSException;

  /**
   * <p>
   * return the hint field of a Windows dynamic disk volume
   * </p><p>
   * Return the hint field of the volume named "volume" in
   * the disk group with GUID "diskgroup". This may not be
   * defined, in which case the empty string is returned. The
   * hint field is often, though not always, the name of a
   * Windows drive, eg. "E:".
   * </p><p>
   * </p>
   * @since 1.20.0
   * @throws LibGuestFSException
   */
  public String ldmtool_volume_hint (String diskgroup, String volume)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("ldmtool_volume_hint: handle is closed");

    return _ldmtool_volume_hint (g, diskgroup, volume);
  }

  private native String _ldmtool_volume_hint (long g, String diskgroup, String volume)
    throws LibGuestFSException;

  /**
   * <p>
   * return the partitions in a Windows dynamic disk volume
   * </p><p>
   * Return the list of partitions in the volume named
   * "volume" in the disk group with GUID "diskgroup".
   * </p><p>
   * </p>
   * @since 1.20.0
   * @throws LibGuestFSException
   */
  public String[] ldmtool_volume_partitions (String diskgroup, String volume)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("ldmtool_volume_partitions: handle is closed");

    return _ldmtool_volume_partitions (g, diskgroup, volume);
  }

  private native String[] _ldmtool_volume_partitions (long g, String diskgroup, String volume)
    throws LibGuestFSException;

  /**
   * <p>
   * return the type of a Windows dynamic disk volume
   * </p><p>
   * Return the type of the volume named "volume" in the disk
   * group with GUID "diskgroup".
   * </p><p>
   * Possible volume types that can be returned here include:
   * "simple", "spanned", "striped", "mirrored", "raid5".
   * Other types may also be returned.
   * </p><p>
   * </p>
   * @since 1.20.0
   * @throws LibGuestFSException
   */
  public String ldmtool_volume_type (String diskgroup, String volume)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("ldmtool_volume_type: handle is closed");

    return _ldmtool_volume_type (g, diskgroup, volume);
  }

  private native String _ldmtool_volume_type (long g, String diskgroup, String volume)
    throws LibGuestFSException;

  /**
   * <p>
   * get a single extended attribute
   * </p><p>
   * Get a single extended attribute from file "path" named
   * "name". If "path" is a symlink, then this call returns
   * an extended attribute from the symlink.
   * </p><p>
   * Normally it is better to get all extended attributes
   * from a file in one go by calling "g.getxattrs". However
   * some Linux filesystem implementations are buggy and do
   * not provide a way to list out attributes. For these
   * filesystems (notably ntfs-3g) you have to know the names
   * of the extended attributes you want in advance and call
   * this function.
   * </p><p>
   * Extended attribute values are blobs of binary data. If
   * there is no extended attribute named "name", this
   * returns an error.
   * </p><p>
   * See also: "g.lgetxattrs", "g.getxattr", attr(5).
   * </p><p>
   * </p>
   * @since 1.7.24
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
   * <p>
   * list extended attributes of a file or directory
   * </p><p>
   * This is the same as "g.getxattrs", but if "path" is a
   * symbolic link, then it returns the extended attributes
   * of the link itself.
   * </p><p>
   * </p>
   * @since 1.0.59
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
   * <p>
   * list 9p filesystems
   * </p><p>
   * List all 9p filesystems attached to the guest. A list of
   * mount tags is returned.
   * </p><p>
   * </p>
   * @since 1.11.12
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
   * <p>
   * list the block devices
   * </p><p>
   * List all the block devices.
   * </p><p>
   * The full block device names are returned, eg. /dev/sda.
   * </p><p>
   * See also "g.list_filesystems".
   * </p><p>
   * </p>
   * @since 0.4
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
   * <p>
   * mapping of disk labels to devices
   * </p><p>
   * If you add drives using the optional "label" parameter
   * of "g.add_drive_opts", you can use this call to map
   * between disk labels, and raw block device and partition
   * names (like /dev/sda and /dev/sda1).
   * </p><p>
   * This returns a hashtable, where keys are the disk labels
   * (*without* the /dev/disk/guestfs prefix), and the values
   * are the full raw block device and partition names (eg.
   * /dev/sda and /dev/sda1).
   * </p><p>
   * </p>
   * @since 1.19.49
   * @throws LibGuestFSException
   */
  public Map<String,String> list_disk_labels ()
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("list_disk_labels: handle is closed");

    String[] r = _list_disk_labels (g);

    HashMap<String, String> rhash = new HashMap<String, String> ();
    for (int i = 0; i < r.length; i += 2)
      rhash.put (r[i], r[i+1]);
    return rhash;
  }

  private native String[] _list_disk_labels (long g)
    throws LibGuestFSException;

  /**
   * <p>
   * list device mapper devices
   * </p><p>
   * List all device mapper devices.
   * </p><p>
   * The returned list contains /dev/mapper/* devices, eg.
   * ones created by a previous call to "g.luks_open".
   * </p><p>
   * Device mapper devices which correspond to logical
   * volumes are *not* returned in this list. Call "g.lvs" if
   * you want to list logical volumes.
   * </p><p>
   * </p>
   * @since 1.11.15
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
   * <p>
   * list filesystems
   * </p><p>
   * This inspection command looks for filesystems on
   * partitions, block devices and logical volumes, returning
   * a list of "mountables" containing filesystems and their
   * type.
   * </p><p>
   * The return value is a hash, where the keys are the
   * devices containing filesystems, and the values are the
   * filesystem types. For example:
   * </p><p>
   * "/dev/sda1" =&gt; "ntfs"
   * "/dev/sda2" =&gt; "ext2"
   * "/dev/vg_guest/lv_root" =&gt; "ext4"
   * "/dev/vg_guest/lv_swap" =&gt; "swap"
   * </p><p>
   * The key is not necessarily a block device. It may also
   * be an opaque 'mountable' string which can be passed to
   * "g.mount".
   * </p><p>
   * The value can have the special value "unknown", meaning
   * the content of the device is undetermined or empty.
   * "swap" means a Linux swap partition.
   * </p><p>
   * This command runs other libguestfs commands, which might
   * include "g.mount" and "g.umount", and therefore you
   * should use this soon after launch and only when nothing
   * is mounted.
   * </p><p>
   * Not all of the filesystems returned will be mountable.
   * In particular, swap partitions are returned in the list.
   * Also this command does not check that each filesystem
   * found is valid and mountable, and some filesystems might
   * be mountable but require special options. Filesystems
   * may not all belong to a single logical operating system
   * (use "g.inspect_os" to look for OSes).
   * </p><p>
   * </p>
   * @since 1.5.15
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
   * <p>
   * list all Windows dynamic disk partitions
   * </p><p>
   * This function returns all Windows dynamic disk
   * partitions that were found at launch time. It returns a
   * list of device names.
   * </p><p>
   * </p>
   * @since 1.20.0
   * @throws LibGuestFSException
   */
  public String[] list_ldm_partitions ()
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("list_ldm_partitions: handle is closed");

    return _list_ldm_partitions (g);
  }

  private native String[] _list_ldm_partitions (long g)
    throws LibGuestFSException;

  /**
   * <p>
   * list all Windows dynamic disk volumes
   * </p><p>
   * This function returns all Windows dynamic disk volumes
   * that were found at launch time. It returns a list of
   * device names.
   * </p><p>
   * </p>
   * @since 1.20.0
   * @throws LibGuestFSException
   */
  public String[] list_ldm_volumes ()
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("list_ldm_volumes: handle is closed");

    return _list_ldm_volumes (g);
  }

  private native String[] _list_ldm_volumes (long g)
    throws LibGuestFSException;

  /**
   * <p>
   * list Linux md (RAID) devices
   * </p><p>
   * List all Linux md devices.
   * </p><p>
   * </p>
   * @since 1.15.4
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
   * <p>
   * list the partitions
   * </p><p>
   * List all the partitions detected on all block devices.
   * </p><p>
   * The full partition device names are returned, eg.
   * /dev/sda1
   * </p><p>
   * This does not return logical volumes. For that you will
   * need to call "g.lvs".
   * </p><p>
   * See also "g.list_filesystems".
   * </p><p>
   * </p>
   * @since 0.4
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
   * <p>
   * list the files in a directory (long format)
   * </p><p>
   * List the files in directory (relative to the root
   * directory, there is no cwd) in the format of 'ls -la'.
   * </p><p>
   * This command is mostly useful for interactive sessions.
   * It is *not* intended that you try to parse the output
   * string.
   * </p><p>
   * </p>
   * @since 0.4
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
   * <p>
   * list the files in a directory (long format with SELinux contexts)
   * </p><p>
   * List the files in directory in the format of 'ls -laZ'.
   * </p><p>
   * This command is mostly useful for interactive sessions.
   * It is *not* intended that you try to parse the output
   * string.
   * </p><p>
   * </p>
   * @since 1.17.6
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
   * <p>
   * create a hard link
   * </p><p>
   * This command creates a hard link using the "ln" command.
   * </p><p>
   * </p>
   * @since 1.0.66
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
   * <p>
   * create a hard link
   * </p><p>
   * This command creates a hard link using the "ln -f"
   * command. The *-f* option removes the link ("linkname")
   * if it exists already.
   * </p><p>
   * </p>
   * @since 1.0.66
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
   * <p>
   * create a symbolic link
   * </p><p>
   * This command creates a symbolic link using the "ln -s"
   * command.
   * </p><p>
   * </p>
   * @since 1.0.66
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
   * <p>
   * create a symbolic link
   * </p><p>
   * This command creates a symbolic link using the "ln -sf"
   * command, The *-f* option removes the link ("linkname")
   * if it exists already.
   * </p><p>
   * </p>
   * @since 1.0.66
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
   * <p>
   * remove extended attribute of a file or directory
   * </p><p>
   * This is the same as "g.removexattr", but if "path" is a
   * symbolic link, then it removes an extended attribute of
   * the link itself.
   * </p><p>
   * </p>
   * @since 1.0.59
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
   * <p>
   * list the files in a directory
   * </p><p>
   * List the files in directory (relative to the root
   * directory, there is no cwd). The '.' and '..' entries
   * are not returned, but hidden files are shown.
   * </p><p>
   * </p>
   * @since 0.4
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
   * <p>
   * get list of files in a directory
   * </p><p>
   * This specialized command is used to get a listing of the
   * filenames in the directory "dir". The list of filenames
   * is written to the local file filenames (on the host).
   * </p><p>
   * In the output file, the filenames are separated by "\0"
   * characters.
   * </p><p>
   * "." and ".." are not returned. The filenames are not
   * sorted.
   * </p><p>
   * </p>
   * @since 1.19.32
   * @throws LibGuestFSException
   */
  public void ls0 (String dir, String filenames)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("ls0: handle is closed");

    _ls0 (g, dir, filenames);
  }

  private native void _ls0 (long g, String dir, String filenames)
    throws LibGuestFSException;

  /**
   * <p>
   * set extended attribute of a file or directory
   * </p><p>
   * This is the same as "g.setxattr", but if "path" is a
   * symbolic link, then it sets an extended attribute of the
   * link itself.
   * </p><p>
   * </p>
   * @since 1.0.59
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
   * <p>
   * get file information for a symbolic link
   * </p><p>
   * Returns file information for the given "path".
   * </p><p>
   * This is the same as "g.stat" except that if "path" is a
   * symbolic link, then the link is stat-ed, not the file it
   * refers to.
   * </p><p>
   * This is the same as the lstat(2) system call.
   * </p><p>
   * </p>
   * @since 1.9.2
   * @deprecated In new code, use {@link #lstatns} instead
   * @throws LibGuestFSException
   */
  @Deprecated public Stat lstat (String path)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("lstat: handle is closed");

    return _lstat (g, path);
  }

  private native Stat _lstat (long g, String path)
    throws LibGuestFSException;

  /**
   * <p>
   * lstat on multiple files
   * </p><p>
   * This call allows you to perform the "g.lstat" operation
   * on multiple files, where all files are in the directory
   * "path". "names" is the list of files from this
   * directory.
   * </p><p>
   * On return you get a list of stat structs, with a
   * one-to-one correspondence to the "names" list. If any
   * name did not exist or could not be lstat'd, then the
   * "st_ino" field of that structure is set to -1.
   * </p><p>
   * This call is intended for programs that want to
   * efficiently list a directory contents without making
   * many round-trips. See also "g.lxattrlist" for a
   * similarly efficient call for getting extended
   * attributes.
   * </p><p>
   * </p>
   * @since 1.0.77
   * @deprecated In new code, use {@link #lstatnslist} instead
   * @throws LibGuestFSException
   */
  @Deprecated public Stat[] lstatlist (String path, String[] names)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("lstatlist: handle is closed");

    return _lstatlist (g, path, names);
  }

  private native Stat[] _lstatlist (long g, String path, String[] names)
    throws LibGuestFSException;

  /**
   * <p>
   * get file information for a symbolic link
   * </p><p>
   * Returns file information for the given "path".
   * </p><p>
   * This is the same as "g.statns" except that if "path" is
   * a symbolic link, then the link is stat-ed, not the file
   * it refers to.
   * </p><p>
   * This is the same as the lstat(2) system call.
   * </p><p>
   * </p>
   * @since 1.27.53
   * @throws LibGuestFSException
   */
  public StatNS lstatns (String path)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("lstatns: handle is closed");

    return _lstatns (g, path);
  }

  private native StatNS _lstatns (long g, String path)
    throws LibGuestFSException;

  /**
   * <p>
   * lstat on multiple files
   * </p><p>
   * This call allows you to perform the "g.lstatns"
   * operation on multiple files, where all files are in the
   * directory "path". "names" is the list of files from this
   * directory.
   * </p><p>
   * On return you get a list of stat structs, with a
   * one-to-one correspondence to the "names" list. If any
   * name did not exist or could not be lstat'd, then the
   * "st_ino" field of that structure is set to -1.
   * </p><p>
   * This call is intended for programs that want to
   * efficiently list a directory contents without making
   * many round-trips. See also "g.lxattrlist" for a
   * similarly efficient call for getting extended
   * attributes.
   * </p><p>
   * </p>
   * @since 1.27.53
   * @throws LibGuestFSException
   */
  public StatNS[] lstatnslist (String path, String[] names)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("lstatnslist: handle is closed");

    return _lstatnslist (g, path, names);
  }

  private native StatNS[] _lstatnslist (long g, String path, String[] names)
    throws LibGuestFSException;

  /**
   * <p>
   * add a key on a LUKS encrypted device
   * </p><p>
   * This command adds a new key on LUKS device "device".
   * "key" is any existing key, and is used to access the
   * device. "newkey" is the new key to add. "keyslot" is the
   * key slot that will be replaced.
   * </p><p>
   * Note that if "keyslot" already contains a key, then this
   * command will fail. You have to use "g.luks_kill_slot"
   * first to remove that key.
   * </p><p>
   * </p>
   * @since 1.5.2
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
   * <p>
   * close a LUKS device
   * </p><p>
   * This closes a LUKS device that was created earlier by
   * "g.luks_open" or "g.luks_open_ro". The "device"
   * parameter must be the name of the LUKS mapping device
   * (ie. /dev/mapper/mapname) and *not* the name of the
   * underlying block device.
   * </p><p>
   * </p>
   * @since 1.5.1
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
   * <p>
   * format a block device as a LUKS encrypted device
   * </p><p>
   * This command erases existing data on "device" and
   * formats the device as a LUKS encrypted device. "key" is
   * the initial key, which is added to key slot "slot".
   * (LUKS supports 8 key slots, numbered 0-7).
   * </p><p>
   * </p>
   * @since 1.5.2
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
   * <p>
   * format a block device as a LUKS encrypted device
   * </p><p>
   * This command is the same as "g.luks_format" but it also
   * allows you to set the "cipher" used.
   * </p><p>
   * </p>
   * @since 1.5.2
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
   * <p>
   * remove a key from a LUKS encrypted device
   * </p><p>
   * This command deletes the key in key slot "keyslot" from
   * the encrypted LUKS device "device". "key" must be one of
   * the *other* keys.
   * </p><p>
   * </p>
   * @since 1.5.2
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
   * <p>
   * open a LUKS-encrypted block device
   * </p><p>
   * This command opens a block device which has been
   * encrypted according to the Linux Unified Key Setup
   * (LUKS) standard.
   * </p><p>
   * "device" is the encrypted block device or partition.
   * </p><p>
   * The caller must supply one of the keys associated with
   * the LUKS block device, in the "key" parameter.
   * </p><p>
   * This creates a new block device called
   * /dev/mapper/mapname. Reads and writes to this block
   * device are decrypted from and encrypted to the
   * underlying "device" respectively.
   * </p><p>
   * If this block device contains LVM volume groups, then
   * calling "g.vgscan" followed by "g.vg_activate_all" will
   * make them visible.
   * </p><p>
   * Use "g.list_dm_devices" to list all device mapper
   * devices.
   * </p><p>
   * </p>
   * @since 1.5.1
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
   * <p>
   * open a LUKS-encrypted block device read-only
   * </p><p>
   * This is the same as "g.luks_open" except that a
   * read-only mapping is created.
   * </p><p>
   * </p>
   * @since 1.5.1
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
   * <p>
   * create an LVM logical volume
   * </p><p>
   * This creates an LVM logical volume called "logvol" on
   * the volume group "volgroup", with "size" megabytes.
   * </p><p>
   * </p>
   * @since 0.8
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
   * <p>
   * create an LVM logical volume in % remaining free space
   * </p><p>
   * Create an LVM logical volume called
   * /dev/volgroup/logvol, using approximately "percent" % of
   * the free space remaining in the volume group. Most
   * usefully, when "percent" is 100 this will create the
   * largest possible LV.
   * </p><p>
   * </p>
   * @since 1.17.18
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
   * <p>
   * get canonical name of an LV
   * </p><p>
   * This converts alternative naming schemes for LVs that
   * you might find to the canonical name. For example,
   * /dev/mapper/VG-LV is converted to /dev/VG/LV.
   * </p><p>
   * This command returns an error if the "lvname" parameter
   * does not refer to a logical volume.
   * </p><p>
   * See also "g.is_lv", "g.canonical_device_name".
   * </p><p>
   * </p>
   * @since 1.5.24
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
   * <p>
   * clear LVM device filter
   * </p><p>
   * This undoes the effect of "g.lvm_set_filter". LVM will
   * be able to see every block device.
   * </p><p>
   * This command also clears the LVM cache and performs a
   * volume group scan.
   * </p><p>
   * </p>
   * @since 1.5.1
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
   * <p>
   * remove all LVM LVs, VGs and PVs
   * </p><p>
   * This command removes all LVM logical volumes, volume
   * groups and physical volumes.
   * </p><p>
   * </p>
   * @since 0.8
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
   * <p>
   * set LVM device filter
   * </p><p>
   * This sets the LVM device filter so that LVM will only be
   * able to "see" the block devices in the list "devices",
   * and will ignore all other attached block devices.
   * </p><p>
   * Where disk image(s) contain duplicate PVs or VGs, this
   * command is useful to get LVM to ignore the duplicates,
   * otherwise LVM can get confused. Note also there are two
   * types of duplication possible: either cloned PVs/VGs
   * which have identical UUIDs; or VGs that are not cloned
   * but just happen to have the same name. In normal
   * operation you cannot create this situation, but you can
   * do it outside LVM, eg. by cloning disk images or by bit
   * twiddling inside the LVM metadata.
   * </p><p>
   * This command also clears the LVM cache and performs a
   * volume group scan.
   * </p><p>
   * You can filter whole block devices or individual
   * partitions.
   * </p><p>
   * You cannot use this if any VG is currently in use (eg.
   * contains a mounted filesystem), even if you are not
   * filtering out that VG.
   * </p><p>
   * </p>
   * @since 1.5.1
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
   * <p>
   * remove an LVM logical volume
   * </p><p>
   * Remove an LVM logical volume "device", where "device" is
   * the path to the LV, such as /dev/VG/LV.
   * </p><p>
   * You can also remove all LVs in a volume group by
   * specifying the VG name, /dev/VG.
   * </p><p>
   * </p>
   * @since 1.0.13
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
   * <p>
   * rename an LVM logical volume
   * </p><p>
   * Rename a logical volume "logvol" with the new name
   * "newlogvol".
   * </p><p>
   * </p>
   * @since 1.0.83
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
   * <p>
   * resize an LVM logical volume
   * </p><p>
   * This resizes (expands or shrinks) an existing LVM
   * logical volume to "mbytes". When reducing, data in the
   * reduced part is lost.
   * </p><p>
   * </p>
   * @since 1.0.27
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
   * <p>
   * expand an LV to fill free space
   * </p><p>
   * This expands an existing logical volume "lv" so that it
   * fills "pc"% of the remaining free space in the volume
   * group. Commonly you would call this with pc = 100 which
   * expands the logical volume as much as possible, using
   * all remaining free space in the volume group.
   * </p><p>
   * </p>
   * @since 1.3.3
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
   * <p>
   * list the LVM logical volumes (LVs)
   * </p><p>
   * List all the logical volumes detected. This is the
   * equivalent of the lvs(8) command.
   * </p><p>
   * This returns a list of the logical volume device names
   * (eg. /dev/VolGroup00/LogVol00).
   * </p><p>
   * See also "g.lvs_full", "g.list_filesystems".
   * </p><p>
   * </p>
   * @since 0.4
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
   * <p>
   * list the LVM logical volumes (LVs)
   * </p><p>
   * List all the logical volumes detected. This is the
   * equivalent of the lvs(8) command. The "full" version
   * includes all fields.
   * </p><p>
   * </p>
   * @since 0.4
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
   * <p>
   * get the UUID of a logical volume
   * </p><p>
   * This command returns the UUID of the LVM LV "device".
   * </p><p>
   * </p>
   * @since 1.0.87
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
   * <p>
   * lgetxattr on multiple files
   * </p><p>
   * This call allows you to get the extended attributes of
   * multiple files, where all files are in the directory
   * "path". "names" is the list of files from this
   * directory.
   * </p><p>
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
   * </p><p>
   * This call is intended for programs that want to
   * efficiently list a directory contents without making
   * many round-trips. See also "g.lstatlist" for a similarly
   * efficient call for getting standard stats.
   * </p><p>
   * </p>
   * @since 1.0.77
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
   * <p>
   * maximum number of disks that may be added
   * </p><p>
   * Return the maximum number of disks that may be added to
   * a handle (eg. by "g.add_drive_opts" and similar calls).
   * </p><p>
   * This function was added in libguestfs 1.19.7. In
   * previous versions of libguestfs the limit was 25.
   * </p><p>
   * See "MAXIMUM NUMBER OF DISKS" in guestfs(3) for
   * additional information on this topic.
   * </p><p>
   * </p>
   * @since 1.19.7
   * @throws LibGuestFSException
   */
  public int max_disks ()
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("max_disks: handle is closed");

    return _max_disks (g);
  }

  private native int _max_disks (long g)
    throws LibGuestFSException;

  /**
   * <p>
   * create a Linux md (RAID) device
   * </p><p>
   * Create a Linux md (RAID) device named "name" on the
   * devices in the list "devices".
   * </p><p>
   * The optional parameters are:
   * </p><p>
   * "missingbitmap"
   * A bitmap of missing devices. If a bit is set it
   * means that a missing device is added to the array.
   * The least significant bit corresponds to the first
   * device in the array.
   * </p><p>
   * As examples:
   * </p><p>
   * If "devices = ["/dev/sda"]" and "missingbitmap =
   * 0x1" then the resulting array would be "[&lt;missing&gt;,
   * "/dev/sda"]".
   * </p><p>
   * If "devices = ["/dev/sda"]" and "missingbitmap =
   * 0x2" then the resulting array would be "["/dev/sda",
   * &lt;missing&gt;]".
   * </p><p>
   * This defaults to 0 (no missing devices).
   * </p><p>
   * The length of "devices" + the number of bits set in
   * "missingbitmap" must equal "nrdevices" + "spare".
   * </p><p>
   * "nrdevices"
   * The number of active RAID devices.
   * </p><p>
   * If not set, this defaults to the length of "devices"
   * plus the number of bits set in "missingbitmap".
   * </p><p>
   * "spare"
   * The number of spare devices.
   * </p><p>
   * If not set, this defaults to 0.
   * </p><p>
   * "chunk"
   * The chunk size in bytes.
   * </p><p>
   * "level"
   * The RAID level, which can be one of: *linear*,
   * *raid0*, *0*, *stripe*, *raid1*, *1*, *mirror*,
   * *raid4*, *4*, *raid5*, *5*, *raid6*, *6*, *raid10*,
   * *10*. Some of these are synonymous, and more levels
   * may be added in future.
   * </p><p>
   * If not set, this defaults to "raid1".
   * </p><p>
   * Optional arguments are supplied in the final
   * Map&lt;String,Object&gt; parameter, which is a hash of the
   * argument name to its value (cast to Object). Pass an
   * empty Map or null for no optional arguments.
   * </p><p>
   * </p>
   * @since 1.15.6
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
   * <p>
   * obtain metadata for an MD device
   * </p><p>
   * This command exposes the output of 'mdadm -DY &lt;md&gt;'. The
   * following fields are usually present in the returned
   * hash. Other fields may also be present.
   * </p><p>
   * "level"
   * The raid level of the MD device.
   * </p><p>
   * "devices"
   * The number of underlying devices in the MD device.
   * </p><p>
   * "metadata"
   * The metadata version used.
   * </p><p>
   * "uuid"
   * The UUID of the MD device.
   * </p><p>
   * "name"
   * The name of the MD device.
   * </p><p>
   * </p>
   * @since 1.15.6
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
   * <p>
   * get underlying devices from an MD device
   * </p><p>
   * This call returns a list of the underlying devices which
   * make up the single software RAID array device "md".
   * </p><p>
   * To get a list of software RAID devices, call
   * "g.list_md_devices".
   * </p><p>
   * Each structure returned corresponds to one device along
   * with additional status information:
   * </p><p>
   * "mdstat_device"
   * The name of the underlying device.
   * </p><p>
   * "mdstat_index"
   * The index of this device within the array.
   * </p><p>
   * "mdstat_flags"
   * Flags associated with this device. This is a string
   * containing (in no specific order) zero or more of
   * the following flags:
   * </p><p>
   * "W" write-mostly
   * </p><p>
   * "F" device is faulty
   * </p><p>
   * "S" device is a RAID spare
   * </p><p>
   * "R" replacement
   * </p><p>
   * </p>
   * @since 1.17.21
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
   * <p>
   * stop a Linux md (RAID) device
   * </p><p>
   * This command deactivates the MD array named "md". The
   * device is stopped, but it is not destroyed or zeroed.
   * </p><p>
   * </p>
   * @since 1.15.6
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
   * <p>
   * create a directory
   * </p><p>
   * Create a directory named "path".
   * </p><p>
   * </p>
   * @since 0.8
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
   * <p>
   * create a directory with a particular mode
   * </p><p>
   * This command creates a directory, setting the initial
   * permissions of the directory to "mode".
   * </p><p>
   * For common Linux filesystems, the actual mode which is
   * set will be "mode &amp; ~umask &amp; 01777". Non-native-Linux
   * filesystems may interpret the mode in other ways.
   * </p><p>
   * See also "g.mkdir", "g.umask"
   * </p><p>
   * </p>
   * @since 1.0.77
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
   * <p>
   * create a directory and parents
   * </p><p>
   * Create a directory named "path", creating any parent
   * directories as necessary. This is like the "mkdir -p"
   * shell command.
   * </p><p>
   * </p>
   * @since 0.8
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
   * <p>
   * create a temporary directory
   * </p><p>
   * This command creates a temporary directory. The "tmpl"
   * parameter should be a full pathname for the temporary
   * directory name with the final six characters being
   * "XXXXXX".
   * </p><p>
   * For example: "/tmp/myprogXXXXXX" or
   * "/Temp/myprogXXXXXX", the second one being suitable for
   * Windows filesystems.
   * </p><p>
   * The name of the temporary directory that was created is
   * returned.
   * </p><p>
   * The temporary directory is created with mode 0700 and is
   * owned by root.
   * </p><p>
   * The caller is responsible for deleting the temporary
   * directory and its contents after use.
   * </p><p>
   * See also: mkdtemp(3)
   * </p><p>
   * </p>
   * @since 1.0.54
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
   * <p>
   * create an ext2/ext3/ext4 filesystem on device
   * </p><p>
   * "mke2fs" is used to create an ext2, ext3, or ext4
   * filesystem on "device".
   * </p><p>
   * The optional "blockscount" is the size of the filesystem
   * in blocks. If omitted it defaults to the size of
   * "device". Note if the filesystem is too small to contain
   * a journal, "mke2fs" will silently create an ext2
   * filesystem instead.
   * </p><p>
   * Optional arguments are supplied in the final
   * Map&lt;String,Object&gt; parameter, which is a hash of the
   * argument name to its value (cast to Object). Pass an
   * empty Map or null for no optional arguments.
   * </p><p>
   * </p>
   * @since 1.19.44
   * @throws LibGuestFSException
   */
  public void mke2fs (String device, Map<String, Object> optargs)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("mke2fs: handle is closed");

    /* Unpack optional args. */
    Object _optobj;
    long _optargs_bitmask = 0;
    long blockscount = 0;
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("blockscount");
    if (_optobj != null) {
      blockscount = ((Long) _optobj).longValue();
      _optargs_bitmask |= 1L;
    }
    long blocksize = 0;
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("blocksize");
    if (_optobj != null) {
      blocksize = ((Long) _optobj).longValue();
      _optargs_bitmask |= 2L;
    }
    long fragsize = 0;
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("fragsize");
    if (_optobj != null) {
      fragsize = ((Long) _optobj).longValue();
      _optargs_bitmask |= 4L;
    }
    long blockspergroup = 0;
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("blockspergroup");
    if (_optobj != null) {
      blockspergroup = ((Long) _optobj).longValue();
      _optargs_bitmask |= 8L;
    }
    long numberofgroups = 0;
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("numberofgroups");
    if (_optobj != null) {
      numberofgroups = ((Long) _optobj).longValue();
      _optargs_bitmask |= 16L;
    }
    long bytesperinode = 0;
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("bytesperinode");
    if (_optobj != null) {
      bytesperinode = ((Long) _optobj).longValue();
      _optargs_bitmask |= 32L;
    }
    long inodesize = 0;
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("inodesize");
    if (_optobj != null) {
      inodesize = ((Long) _optobj).longValue();
      _optargs_bitmask |= 64L;
    }
    long journalsize = 0;
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("journalsize");
    if (_optobj != null) {
      journalsize = ((Long) _optobj).longValue();
      _optargs_bitmask |= 128L;
    }
    long numberofinodes = 0;
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("numberofinodes");
    if (_optobj != null) {
      numberofinodes = ((Long) _optobj).longValue();
      _optargs_bitmask |= 256L;
    }
    long stridesize = 0;
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("stridesize");
    if (_optobj != null) {
      stridesize = ((Long) _optobj).longValue();
      _optargs_bitmask |= 512L;
    }
    long stripewidth = 0;
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("stripewidth");
    if (_optobj != null) {
      stripewidth = ((Long) _optobj).longValue();
      _optargs_bitmask |= 1024L;
    }
    long maxonlineresize = 0;
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("maxonlineresize");
    if (_optobj != null) {
      maxonlineresize = ((Long) _optobj).longValue();
      _optargs_bitmask |= 2048L;
    }
    int reservedblockspercentage = 0;
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("reservedblockspercentage");
    if (_optobj != null) {
      reservedblockspercentage = ((Integer) _optobj).intValue();
      _optargs_bitmask |= 4096L;
    }
    int mmpupdateinterval = 0;
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("mmpupdateinterval");
    if (_optobj != null) {
      mmpupdateinterval = ((Integer) _optobj).intValue();
      _optargs_bitmask |= 8192L;
    }
    String journaldevice = "";
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("journaldevice");
    if (_optobj != null) {
      journaldevice = ((String) _optobj);
      _optargs_bitmask |= 16384L;
    }
    String label = "";
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("label");
    if (_optobj != null) {
      label = ((String) _optobj);
      _optargs_bitmask |= 32768L;
    }
    String lastmounteddir = "";
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("lastmounteddir");
    if (_optobj != null) {
      lastmounteddir = ((String) _optobj);
      _optargs_bitmask |= 65536L;
    }
    String creatoros = "";
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("creatoros");
    if (_optobj != null) {
      creatoros = ((String) _optobj);
      _optargs_bitmask |= 131072L;
    }
    String fstype = "";
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("fstype");
    if (_optobj != null) {
      fstype = ((String) _optobj);
      _optargs_bitmask |= 262144L;
    }
    String usagetype = "";
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("usagetype");
    if (_optobj != null) {
      usagetype = ((String) _optobj);
      _optargs_bitmask |= 524288L;
    }
    String uuid = "";
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("uuid");
    if (_optobj != null) {
      uuid = ((String) _optobj);
      _optargs_bitmask |= 1048576L;
    }
    boolean forcecreate = false;
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("forcecreate");
    if (_optobj != null) {
      forcecreate = ((Boolean) _optobj).booleanValue();
      _optargs_bitmask |= 2097152L;
    }
    boolean writesbandgrouponly = false;
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("writesbandgrouponly");
    if (_optobj != null) {
      writesbandgrouponly = ((Boolean) _optobj).booleanValue();
      _optargs_bitmask |= 4194304L;
    }
    boolean lazyitableinit = false;
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("lazyitableinit");
    if (_optobj != null) {
      lazyitableinit = ((Boolean) _optobj).booleanValue();
      _optargs_bitmask |= 8388608L;
    }
    boolean lazyjournalinit = false;
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("lazyjournalinit");
    if (_optobj != null) {
      lazyjournalinit = ((Boolean) _optobj).booleanValue();
      _optargs_bitmask |= 16777216L;
    }
    boolean testfs = false;
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("testfs");
    if (_optobj != null) {
      testfs = ((Boolean) _optobj).booleanValue();
      _optargs_bitmask |= 33554432L;
    }
    boolean discard = false;
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("discard");
    if (_optobj != null) {
      discard = ((Boolean) _optobj).booleanValue();
      _optargs_bitmask |= 67108864L;
    }
    boolean quotatype = false;
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("quotatype");
    if (_optobj != null) {
      quotatype = ((Boolean) _optobj).booleanValue();
      _optargs_bitmask |= 134217728L;
    }
    boolean extent = false;
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("extent");
    if (_optobj != null) {
      extent = ((Boolean) _optobj).booleanValue();
      _optargs_bitmask |= 268435456L;
    }
    boolean filetype = false;
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("filetype");
    if (_optobj != null) {
      filetype = ((Boolean) _optobj).booleanValue();
      _optargs_bitmask |= 536870912L;
    }
    boolean flexbg = false;
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("flexbg");
    if (_optobj != null) {
      flexbg = ((Boolean) _optobj).booleanValue();
      _optargs_bitmask |= 1073741824L;
    }
    boolean hasjournal = false;
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("hasjournal");
    if (_optobj != null) {
      hasjournal = ((Boolean) _optobj).booleanValue();
      _optargs_bitmask |= 2147483648L;
    }
    boolean journaldev = false;
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("journaldev");
    if (_optobj != null) {
      journaldev = ((Boolean) _optobj).booleanValue();
      _optargs_bitmask |= 4294967296L;
    }
    boolean largefile = false;
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("largefile");
    if (_optobj != null) {
      largefile = ((Boolean) _optobj).booleanValue();
      _optargs_bitmask |= 8589934592L;
    }
    boolean quota = false;
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("quota");
    if (_optobj != null) {
      quota = ((Boolean) _optobj).booleanValue();
      _optargs_bitmask |= 17179869184L;
    }
    boolean resizeinode = false;
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("resizeinode");
    if (_optobj != null) {
      resizeinode = ((Boolean) _optobj).booleanValue();
      _optargs_bitmask |= 34359738368L;
    }
    boolean sparsesuper = false;
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("sparsesuper");
    if (_optobj != null) {
      sparsesuper = ((Boolean) _optobj).booleanValue();
      _optargs_bitmask |= 68719476736L;
    }
    boolean uninitbg = false;
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("uninitbg");
    if (_optobj != null) {
      uninitbg = ((Boolean) _optobj).booleanValue();
      _optargs_bitmask |= 137438953472L;
    }

    _mke2fs (g, device, _optargs_bitmask, blockscount, blocksize, fragsize, blockspergroup, numberofgroups, bytesperinode, inodesize, journalsize, numberofinodes, stridesize, stripewidth, maxonlineresize, reservedblockspercentage, mmpupdateinterval, journaldevice, label, lastmounteddir, creatoros, fstype, usagetype, uuid, forcecreate, writesbandgrouponly, lazyitableinit, lazyjournalinit, testfs, discard, quotatype, extent, filetype, flexbg, hasjournal, journaldev, largefile, quota, resizeinode, sparsesuper, uninitbg);
  }

  public void mke2fs (String device)
    throws LibGuestFSException
  {
    mke2fs (device, null);
  }

  private native void _mke2fs (long g, String device, long _optargs_bitmask, long blockscount, long blocksize, long fragsize, long blockspergroup, long numberofgroups, long bytesperinode, long inodesize, long journalsize, long numberofinodes, long stridesize, long stripewidth, long maxonlineresize, int reservedblockspercentage, int mmpupdateinterval, String journaldevice, String label, String lastmounteddir, String creatoros, String fstype, String usagetype, String uuid, boolean forcecreate, boolean writesbandgrouponly, boolean lazyitableinit, boolean lazyjournalinit, boolean testfs, boolean discard, boolean quotatype, boolean extent, boolean filetype, boolean flexbg, boolean hasjournal, boolean journaldev, boolean largefile, boolean quota, boolean resizeinode, boolean sparsesuper, boolean uninitbg)
    throws LibGuestFSException;

  /**
   * <p>
   * make ext2/3/4 filesystem with external journal
   * </p><p>
   * This creates an ext2/3/4 filesystem on "device" with an
   * external journal on "journal". It is equivalent to the
   * command:
   * </p><p>
   * mke2fs -t fstype -b blocksize -J device=&lt;journal&gt; &lt;device&gt;
   * </p><p>
   * See also "g.mke2journal".
   * </p><p>
   * </p>
   * @since 1.0.68
   * @deprecated In new code, use {@link #mke2fs} instead
   * @throws LibGuestFSException
   */
  @Deprecated public void mke2fs_J (String fstype, int blocksize, String device, String journal)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("mke2fs_J: handle is closed");

    _mke2fs_J (g, fstype, blocksize, device, journal);
  }

  private native void _mke2fs_J (long g, String fstype, int blocksize, String device, String journal)
    throws LibGuestFSException;

  /**
   * <p>
   * make ext2/3/4 filesystem with external journal
   * </p><p>
   * This creates an ext2/3/4 filesystem on "device" with an
   * external journal on the journal labeled "label".
   * </p><p>
   * See also "g.mke2journal_L".
   * </p><p>
   * </p>
   * @since 1.0.68
   * @deprecated In new code, use {@link #mke2fs} instead
   * @throws LibGuestFSException
   */
  @Deprecated public void mke2fs_JL (String fstype, int blocksize, String device, String label)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("mke2fs_JL: handle is closed");

    _mke2fs_JL (g, fstype, blocksize, device, label);
  }

  private native void _mke2fs_JL (long g, String fstype, int blocksize, String device, String label)
    throws LibGuestFSException;

  /**
   * <p>
   * make ext2/3/4 filesystem with external journal
   * </p><p>
   * This creates an ext2/3/4 filesystem on "device" with an
   * external journal on the journal with UUID "uuid".
   * </p><p>
   * See also "g.mke2journal_U".
   * </p><p>
   * </p>
   * @since 1.0.68
   * @deprecated In new code, use {@link #mke2fs} instead
   * @throws LibGuestFSException
   */
  @Deprecated public void mke2fs_JU (String fstype, int blocksize, String device, String uuid)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("mke2fs_JU: handle is closed");

    _mke2fs_JU (g, fstype, blocksize, device, uuid);
  }

  private native void _mke2fs_JU (long g, String fstype, int blocksize, String device, String uuid)
    throws LibGuestFSException;

  /**
   * <p>
   * make ext2/3/4 external journal
   * </p><p>
   * This creates an ext2 external journal on "device". It is
   * equivalent to the command:
   * </p><p>
   * mke2fs -O journal_dev -b blocksize device
   * </p><p>
   * </p>
   * @since 1.0.68
   * @deprecated In new code, use {@link #mke2fs} instead
   * @throws LibGuestFSException
   */
  @Deprecated public void mke2journal (int blocksize, String device)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("mke2journal: handle is closed");

    _mke2journal (g, blocksize, device);
  }

  private native void _mke2journal (long g, int blocksize, String device)
    throws LibGuestFSException;

  /**
   * <p>
   * make ext2/3/4 external journal with label
   * </p><p>
   * This creates an ext2 external journal on "device" with
   * label "label".
   * </p><p>
   * </p>
   * @since 1.0.68
   * @deprecated In new code, use {@link #mke2fs} instead
   * @throws LibGuestFSException
   */
  @Deprecated public void mke2journal_L (int blocksize, String label, String device)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("mke2journal_L: handle is closed");

    _mke2journal_L (g, blocksize, label, device);
  }

  private native void _mke2journal_L (long g, int blocksize, String label, String device)
    throws LibGuestFSException;

  /**
   * <p>
   * make ext2/3/4 external journal with UUID
   * </p><p>
   * This creates an ext2 external journal on "device" with
   * UUID "uuid".
   * </p><p>
   * </p>
   * @since 1.0.68
   * @deprecated In new code, use {@link #mke2fs} instead
   * @throws LibGuestFSException
   */
  @Deprecated public void mke2journal_U (int blocksize, String uuid, String device)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("mke2journal_U: handle is closed");

    _mke2journal_U (g, blocksize, uuid, device);
  }

  private native void _mke2journal_U (long g, int blocksize, String uuid, String device)
    throws LibGuestFSException;

  /**
   * <p>
   * make FIFO (named pipe)
   * </p><p>
   * This call creates a FIFO (named pipe) called "path" with
   * mode "mode". It is just a convenient wrapper around
   * "g.mknod".
   * </p><p>
   * Unlike with "g.mknod", "mode" must contain only
   * permissions bits.
   * </p><p>
   * The mode actually set is affected by the umask.
   * </p><p>
   * </p>
   * @since 1.0.55
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
   * <p>
   * make a filesystem
   * </p><p>
   * This function creates a filesystem on "device". The
   * filesystem type is "fstype", for example "ext3".
   * </p><p>
   * The optional arguments are:
   * </p><p>
   * "blocksize"
   * The filesystem block size. Supported block sizes
   * depend on the filesystem type, but typically they
   * are 1024, 2048 or 4096 for Linux ext2/3 filesystems.
   * </p><p>
   * For VFAT and NTFS the "blocksize" parameter is
   * treated as the requested cluster size.
   * </p><p>
   * For UFS block sizes, please see mkfs.ufs(8).
   * </p><p>
   * "features"
   * This passes the *-O* parameter to the external mkfs
   * program.
   * </p><p>
   * For certain filesystem types, this allows extra
   * filesystem features to be selected. See mke2fs(8)
   * and mkfs.ufs(8) for more details.
   * </p><p>
   * You cannot use this optional parameter with the
   * "gfs" or "gfs2" filesystem type.
   * </p><p>
   * "inode"
   * This passes the *-I* parameter to the external
   * mke2fs(8) program which sets the inode size (only
   * for ext2/3/4 filesystems at present).
   * </p><p>
   * "sectorsize"
   * This passes the *-S* parameter to external
   * mkfs.ufs(8) program, which sets sector size for ufs
   * filesystem.
   * </p><p>
   * Optional arguments are supplied in the final
   * Map&lt;String,Object&gt; parameter, which is a hash of the
   * argument name to its value (cast to Object). Pass an
   * empty Map or null for no optional arguments.
   * </p><p>
   * </p>
   * @since 0.8
   * @throws LibGuestFSException
   */
  public void mkfs (String fstype, String device, Map<String, Object> optargs)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("mkfs: handle is closed");

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
    String label = "";
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("label");
    if (_optobj != null) {
      label = ((String) _optobj);
      _optargs_bitmask |= 16L;
    }

    _mkfs (g, fstype, device, _optargs_bitmask, blocksize, features, inode, sectorsize, label);
  }

  public void mkfs (String fstype, String device)
    throws LibGuestFSException
  {
    mkfs (fstype, device, null);
  }

  public void mkfs_opts (String fstype, String device, Map<String, Object> optargs)
    throws LibGuestFSException
  {
    mkfs (fstype, device, optargs);
  }

  public void mkfs_opts (String fstype, String device)
    throws LibGuestFSException
  {
    mkfs (fstype, device, null);
  }

  private native void _mkfs (long g, String fstype, String device, long _optargs_bitmask, int blocksize, String features, int inode, int sectorsize, String label)
    throws LibGuestFSException;

  /**
   * <p>
   * make a filesystem with block size
   * </p><p>
   * This call is similar to "g.mkfs", but it allows you to
   * control the block size of the resulting filesystem.
   * Supported block sizes depend on the filesystem type, but
   * typically they are 1024, 2048 or 4096 only.
   * </p><p>
   * For VFAT and NTFS the "blocksize" parameter is treated
   * as the requested cluster size.
   * </p><p>
   * </p>
   * @since 1.0.68
   * @deprecated In new code, use {@link #mkfs} instead
   * @throws LibGuestFSException
   */
  @Deprecated public void mkfs_b (String fstype, int blocksize, String device)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("mkfs_b: handle is closed");

    _mkfs_b (g, fstype, blocksize, device);
  }

  private native void _mkfs_b (long g, String fstype, int blocksize, String device)
    throws LibGuestFSException;

  /**
   * <p>
   * create a btrfs filesystem
   * </p><p>
   * Create a btrfs filesystem, allowing all configurables to
   * be set. For more information on the optional arguments,
   * see mkfs.btrfs(8).
   * </p><p>
   * Since btrfs filesystems can span multiple devices, this
   * takes a non-empty list of devices.
   * </p><p>
   * To create general filesystems, use "g.mkfs".
   * </p><p>
   * Optional arguments are supplied in the final
   * Map&lt;String,Object&gt; parameter, which is a hash of the
   * argument name to its value (cast to Object). Pass an
   * empty Map or null for no optional arguments.
   * </p><p>
   * </p>
   * @since 1.17.25
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
   * <p>
   * make lost+found directory on an ext2/3/4 filesystem
   * </p><p>
   * Make the "lost+found" directory, normally in the root
   * directory of an ext2/3/4 filesystem. "mountpoint" is the
   * directory under which we try to create the "lost+found"
   * directory.
   * </p><p>
   * </p>
   * @since 1.19.56
   * @throws LibGuestFSException
   */
  public void mklost_and_found (String mountpoint)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("mklost_and_found: handle is closed");

    _mklost_and_found (g, mountpoint);
  }

  private native void _mklost_and_found (long g, String mountpoint)
    throws LibGuestFSException;

  /**
   * <p>
   * create a mountpoint
   * </p><p>
   * "g.mkmountpoint" and "g.rmmountpoint" are specialized
   * calls that can be used to create extra mountpoints
   * before mounting the first filesystem.
   * </p><p>
   * These calls are *only* necessary in some very limited
   * circumstances, mainly the case where you want to mount a
   * mix of unrelated and/or read-only filesystems together.
   * </p><p>
   * For example, live CDs often contain a "Russian doll"
   * nest of filesystems, an ISO outer layer, with a squashfs
   * image inside, with an ext2/3 image inside that. You can
   * unpack this as follows in guestfish:
   * </p><p>
   * add-ro Fedora-11-i686-Live.iso
   * run
   * mkmountpoint /cd
   * mkmountpoint /sqsh
   * mkmountpoint /ext3fs
   * mount /dev/sda /cd
   * mount-loop /cd/LiveOS/squashfs.img /sqsh
   * mount-loop /sqsh/LiveOS/ext3fs.img /ext3fs
   * </p><p>
   * The inner filesystem is now unpacked under the /ext3fs
   * mountpoint.
   * </p><p>
   * "g.mkmountpoint" is not compatible with "g.umount_all".
   * You may get unexpected errors if you try to mix these
   * calls. It is safest to manually unmount filesystems and
   * remove mountpoints after use.
   * </p><p>
   * "g.umount_all" unmounts filesystems by sorting the paths
   * longest first, so for this to work for manual
   * mountpoints, you must ensure that the innermost
   * mountpoints have the longest pathnames, as in the
   * example code above.
   * </p><p>
   * For more details see
   * &lt;https://bugzilla.redhat.com/show_bug.cgi?id=599503&gt;
   * </p><p>
   * Autosync [see "g.set_autosync", this is set by default
   * on handles] can cause "g.umount_all" to be called when
   * the handle is closed which can also trigger these
   * issues.
   * </p><p>
   * </p>
   * @since 1.0.62
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
   * <p>
   * make block, character or FIFO devices
   * </p><p>
   * This call creates block or character special devices, or
   * named pipes (FIFOs).
   * </p><p>
   * The "mode" parameter should be the mode, using the
   * standard constants. "devmajor" and "devminor" are the
   * device major and minor numbers, only used when creating
   * block and character special devices.
   * </p><p>
   * Note that, just like mknod(2), the mode must be bitwise
   * OR'd with S_IFBLK, S_IFCHR, S_IFIFO or S_IFSOCK
   * (otherwise this call just creates a regular file). These
   * constants are available in the standard Linux header
   * files, or you can use "g.mknod_b", "g.mknod_c" or
   * "g.mkfifo" which are wrappers around this command which
   * bitwise OR in the appropriate constant for you.
   * </p><p>
   * The mode actually set is affected by the umask.
   * </p><p>
   * </p>
   * @since 1.0.55
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
   * <p>
   * make block device node
   * </p><p>
   * This call creates a block device node called "path" with
   * mode "mode" and device major/minor "devmajor" and
   * "devminor". It is just a convenient wrapper around
   * "g.mknod".
   * </p><p>
   * Unlike with "g.mknod", "mode" must contain only
   * permissions bits.
   * </p><p>
   * The mode actually set is affected by the umask.
   * </p><p>
   * </p>
   * @since 1.0.55
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
   * <p>
   * make char device node
   * </p><p>
   * This call creates a char device node called "path" with
   * mode "mode" and device major/minor "devmajor" and
   * "devminor". It is just a convenient wrapper around
   * "g.mknod".
   * </p><p>
   * Unlike with "g.mknod", "mode" must contain only
   * permissions bits.
   * </p><p>
   * The mode actually set is affected by the umask.
   * </p><p>
   * </p>
   * @since 1.0.55
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
   * <p>
   * create a swap partition
   * </p><p>
   * Create a Linux swap partition on "device".
   * </p><p>
   * The option arguments "label" and "uuid" allow you to set
   * the label and/or UUID of the new swap partition.
   * </p><p>
   * Optional arguments are supplied in the final
   * Map&lt;String,Object&gt; parameter, which is a hash of the
   * argument name to its value (cast to Object). Pass an
   * empty Map or null for no optional arguments.
   * </p><p>
   * </p>
   * @since 1.0.55
   * @throws LibGuestFSException
   */
  public void mkswap (String device, Map<String, Object> optargs)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("mkswap: handle is closed");

    /* Unpack optional args. */
    Object _optobj;
    long _optargs_bitmask = 0;
    String label = "";
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("label");
    if (_optobj != null) {
      label = ((String) _optobj);
      _optargs_bitmask |= 1L;
    }
    String uuid = "";
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("uuid");
    if (_optobj != null) {
      uuid = ((String) _optobj);
      _optargs_bitmask |= 2L;
    }

    _mkswap (g, device, _optargs_bitmask, label, uuid);
  }

  public void mkswap (String device)
    throws LibGuestFSException
  {
    mkswap (device, null);
  }

  public void mkswap_opts (String device, Map<String, Object> optargs)
    throws LibGuestFSException
  {
    mkswap (device, optargs);
  }

  public void mkswap_opts (String device)
    throws LibGuestFSException
  {
    mkswap (device, null);
  }

  private native void _mkswap (long g, String device, long _optargs_bitmask, String label, String uuid)
    throws LibGuestFSException;

  /**
   * <p>
   * create a swap partition with a label
   * </p><p>
   * Create a swap partition on "device" with label "label".
   * </p><p>
   * Note that you cannot attach a swap label to a block
   * device (eg. /dev/sda), just to a partition. This appears
   * to be a limitation of the kernel or swap tools.
   * </p><p>
   * </p>
   * @since 1.0.55
   * @deprecated In new code, use {@link #mkswap} instead
   * @throws LibGuestFSException
   */
  @Deprecated public void mkswap_L (String label, String device)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("mkswap_L: handle is closed");

    _mkswap_L (g, label, device);
  }

  private native void _mkswap_L (long g, String label, String device)
    throws LibGuestFSException;

  /**
   * <p>
   * create a swap partition with an explicit UUID
   * </p><p>
   * Create a swap partition on "device" with UUID "uuid".
   * </p><p>
   * </p>
   * @since 1.0.55
   * @deprecated In new code, use {@link #mkswap} instead
   * @throws LibGuestFSException
   */
  @Deprecated public void mkswap_U (String uuid, String device)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("mkswap_U: handle is closed");

    _mkswap_U (g, uuid, device);
  }

  private native void _mkswap_U (long g, String uuid, String device)
    throws LibGuestFSException;

  /**
   * <p>
   * create a swap file
   * </p><p>
   * Create a swap file.
   * </p><p>
   * This command just writes a swap file signature to an
   * existing file. To create the file itself, use something
   * like "g.fallocate".
   * </p><p>
   * </p>
   * @since 1.0.66
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
   * <p>
   * create a temporary file
   * </p><p>
   * This command creates a temporary file. The "tmpl"
   * parameter should be a full pathname for the temporary
   * directory name with the final six characters being
   * "XXXXXX".
   * </p><p>
   * For example: "/tmp/myprogXXXXXX" or
   * "/Temp/myprogXXXXXX", the second one being suitable for
   * Windows filesystems.
   * </p><p>
   * The name of the temporary file that was created is
   * returned.
   * </p><p>
   * The temporary file is created with mode 0600 and is
   * owned by root.
   * </p><p>
   * The caller is responsible for deleting the temporary
   * file after use.
   * </p><p>
   * If the optional "suffix" parameter is given, then the
   * suffix (eg. ".txt") is appended to the temporary name.
   * </p><p>
   * See also: "g.mkdtemp".
   * </p><p>
   * Optional arguments are supplied in the final
   * Map&lt;String,Object&gt; parameter, which is a hash of the
   * argument name to its value (cast to Object). Pass an
   * empty Map or null for no optional arguments.
   * </p><p>
   * </p>
   * @since 1.19.53
   * @throws LibGuestFSException
   */
  public String mktemp (String tmpl, Map<String, Object> optargs)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("mktemp: handle is closed");

    /* Unpack optional args. */
    Object _optobj;
    long _optargs_bitmask = 0;
    String suffix = "";
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("suffix");
    if (_optobj != null) {
      suffix = ((String) _optobj);
      _optargs_bitmask |= 1L;
    }

    return _mktemp (g, tmpl, _optargs_bitmask, suffix);
  }

  public String mktemp (String tmpl)
    throws LibGuestFSException
  {
    return mktemp (tmpl, null);
  }

  private native String _mktemp (long g, String tmpl, long _optargs_bitmask, String suffix)
    throws LibGuestFSException;

  /**
   * <p>
   * load a kernel module
   * </p><p>
   * This loads a kernel module in the appliance.
   * </p><p>
   * </p>
   * @since 1.0.68
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
   * <p>
   * mount a guest disk at a position in the filesystem
   * </p><p>
   * Mount a guest disk at a position in the filesystem.
   * Block devices are named /dev/sda, /dev/sdb and so on, as
   * they were added to the guest. If those block devices
   * contain partitions, they will have the usual names (eg.
   * /dev/sda1). Also LVM /dev/VG/LV-style names can be used,
   * or 'mountable' strings returned by "g.list_filesystems"
   * or "g.inspect_get_mountpoints".
   * </p><p>
   * The rules are the same as for mount(2): A filesystem
   * must first be mounted on / before others can be mounted.
   * Other filesystems can only be mounted on directories
   * which already exist.
   * </p><p>
   * The mounted filesystem is writable, if we have
   * sufficient permissions on the underlying device.
   * </p><p>
   * Before libguestfs 1.13.16, this call implicitly added
   * the options "sync" and "noatime". The "sync" option
   * greatly slowed writes and caused many problems for
   * users. If your program might need to work with older
   * versions of libguestfs, use "g.mount_options" instead
   * (using an empty string for the first parameter if you
   * don't want any options).
   * </p><p>
   * </p>
   * @since 0.3
   * @throws LibGuestFSException
   */
  public void mount (String mountable, String mountpoint)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("mount: handle is closed");

    _mount (g, mountable, mountpoint);
  }

  private native void _mount (long g, String mountable, String mountpoint)
    throws LibGuestFSException;

  /**
   * <p>
   * mount 9p filesystem
   * </p><p>
   * Mount the virtio-9p filesystem with the tag "mounttag"
   * on the directory "mountpoint".
   * </p><p>
   * If required, "trans=virtio" will be automatically added
   * to the options. Any other options required can be passed
   * in the optional "options" parameter.
   * </p><p>
   * Optional arguments are supplied in the final
   * Map&lt;String,Object&gt; parameter, which is a hash of the
   * argument name to its value (cast to Object). Pass an
   * empty Map or null for no optional arguments.
   * </p><p>
   * </p>
   * @since 1.11.12
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
   * <p>
   * mount on the local filesystem
   * </p><p>
   * This call exports the libguestfs-accessible filesystem
   * to a local mountpoint (directory) called
   * "localmountpoint". Ordinary reads and writes to files
   * and directories under "localmountpoint" are redirected
   * through libguestfs.
   * </p><p>
   * If the optional "readonly" flag is set to true, then
   * writes to the filesystem return error "EROFS".
   * </p><p>
   * "options" is a comma-separated list of mount options.
   * See guestmount(1) for some useful options.
   * </p><p>
   * "cachetimeout" sets the timeout (in seconds) for cached
   * directory entries. The default is 60 seconds. See
   * guestmount(1) for further information.
   * </p><p>
   * If "debugcalls" is set to true, then additional
   * debugging information is generated for every FUSE call.
   * </p><p>
   * When "g.mount_local" returns, the filesystem is ready,
   * but is not processing requests (access to it will
   * block). You have to call "g.mount_local_run" to run the
   * main loop.
   * </p><p>
   * See "MOUNT LOCAL" in guestfs(3) for full documentation.
   * </p><p>
   * Optional arguments are supplied in the final
   * Map&lt;String,Object&gt; parameter, which is a hash of the
   * argument name to its value (cast to Object). Pass an
   * empty Map or null for no optional arguments.
   * </p><p>
   * </p>
   * @since 1.17.22
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
   * <p>
   * run main loop of mount on the local filesystem
   * </p><p>
   * Run the main loop which translates kernel calls to
   * libguestfs calls.
   * </p><p>
   * This should only be called after "g.mount_local" returns
   * successfully. The call will not return until the
   * filesystem is unmounted.
   * </p><p>
   * Note you must *not* make concurrent libguestfs calls on
   * the same handle from another thread.
   * </p><p>
   * You may call this from a different thread than the one
   * which called "g.mount_local", subject to the usual rules
   * for threads and libguestfs (see "MULTIPLE HANDLES AND
   * MULTIPLE THREADS" in guestfs(3)).
   * </p><p>
   * See "MOUNT LOCAL" in guestfs(3) for full documentation.
   * </p><p>
   * </p>
   * @since 1.17.22
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
   * <p>
   * mount a file using the loop device
   * </p><p>
   * This command lets you mount file (a filesystem image in
   * a file) on a mount point. It is entirely equivalent to
   * the command "mount -o loop file mountpoint".
   * </p><p>
   * </p>
   * @since 1.0.54
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
   * <p>
   * mount a guest disk with mount options
   * </p><p>
   * This is the same as the "g.mount" command, but it allows
   * you to set the mount options as for the mount(8) *-o*
   * flag.
   * </p><p>
   * If the "options" parameter is an empty string, then no
   * options are passed (all options default to whatever the
   * filesystem uses).
   * </p><p>
   * </p>
   * @since 1.0.10
   * @throws LibGuestFSException
   */
  public void mount_options (String options, String mountable, String mountpoint)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("mount_options: handle is closed");

    _mount_options (g, options, mountable, mountpoint);
  }

  private native void _mount_options (long g, String options, String mountable, String mountpoint)
    throws LibGuestFSException;

  /**
   * <p>
   * mount a guest disk, read-only
   * </p><p>
   * This is the same as the "g.mount" command, but it mounts
   * the filesystem with the read-only (*-o ro*) flag.
   * </p><p>
   * </p>
   * @since 1.0.10
   * @throws LibGuestFSException
   */
  public void mount_ro (String mountable, String mountpoint)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("mount_ro: handle is closed");

    _mount_ro (g, mountable, mountpoint);
  }

  private native void _mount_ro (long g, String mountable, String mountpoint)
    throws LibGuestFSException;

  /**
   * <p>
   * mount a guest disk with mount options and vfstype
   * </p><p>
   * This is the same as the "g.mount" command, but it allows
   * you to set both the mount options and the vfstype as for
   * the mount(8) *-o* and *-t* flags.
   * </p><p>
   * </p>
   * @since 1.0.10
   * @throws LibGuestFSException
   */
  public void mount_vfs (String options, String vfstype, String mountable, String mountpoint)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("mount_vfs: handle is closed");

    _mount_vfs (g, options, vfstype, mountable, mountpoint);
  }

  private native void _mount_vfs (long g, String options, String vfstype, String mountable, String mountpoint)
    throws LibGuestFSException;

  /**
   * <p>
   * show mountpoints
   * </p><p>
   * This call is similar to "g.mounts". That call returns a
   * list of devices. This one returns a hash table (map) of
   * device name to directory where the device is mounted.
   * </p><p>
   * </p>
   * @since 1.0.62
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
   * <p>
   * show mounted filesystems
   * </p><p>
   * This returns the list of currently mounted filesystems.
   * It returns the list of devices (eg. /dev/sda1,
   * /dev/VG/LV).
   * </p><p>
   * Some internal mounts are not shown.
   * </p><p>
   * See also: "g.mountpoints"
   * </p><p>
   * </p>
   * @since 0.8
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
   * <p>
   * move a file
   * </p><p>
   * This moves a file from "src" to "dest" where "dest" is
   * either a destination filename or destination directory.
   * </p><p>
   * See also: "g.rename".
   * </p><p>
   * </p>
   * @since 1.0.18
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
   * <p>
   * return number of whole block devices (disks) added
   * </p><p>
   * This returns the number of whole block devices that were
   * added. This is the same as the number of devices that
   * would be returned if you called "g.list_devices".
   * </p><p>
   * To find out the maximum number of devices that could be
   * added, call "g.max_disks".
   * </p><p>
   * </p>
   * @since 1.19.15
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

  /**
   * <p>
   * probe NTFS volume
   * </p><p>
   * This command runs the ntfs-3g.probe(8) command which
   * probes an NTFS "device" for mountability. (Not all NTFS
   * volumes can be mounted read-write, and some cannot be
   * mounted at all).
   * </p><p>
   * "rw" is a boolean flag. Set it to true if you want to
   * test if the volume can be mounted read-write. Set it to
   * false if you want to test if the volume can be mounted
   * read-only.
   * </p><p>
   * The return value is an integer which 0 if the operation
   * would succeed, or some non-zero value documented in the
   * ntfs-3g.probe(8) manual page.
   * </p><p>
   * </p>
   * @since 1.0.43
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
   * <p>
   * restore NTFS from backup file
   * </p><p>
   * Restore the "backupfile" (from a previous call to
   * "g.ntfsclone_out") to "device", overwriting any existing
   * contents of this device.
   * </p><p>
   * </p>
   * @since 1.17.9
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
   * <p>
   * save NTFS to backup file
   * </p><p>
   * Stream the NTFS filesystem "device" to the local file
   * "backupfile". The format used for the backup file is a
   * special format used by the ntfsclone(8) tool.
   * </p><p>
   * If the optional "metadataonly" flag is true, then *only*
   * the metadata is saved, losing all the user data (this is
   * useful for diagnosing some filesystem problems).
   * </p><p>
   * The optional "rescue", "ignorefscheck",
   * "preservetimestamps" and "force" flags have precise
   * meanings detailed in the ntfsclone(8) man page.
   * </p><p>
   * Use "g.ntfsclone_in" to restore the file back to a
   * libguestfs device.
   * </p><p>
   * Optional arguments are supplied in the final
   * Map&lt;String,Object&gt; parameter, which is a hash of the
   * argument name to its value (cast to Object). Pass an
   * empty Map or null for no optional arguments.
   * </p><p>
   * </p>
   * @since 1.17.9
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
   * <p>
   * fix common errors and force Windows to check NTFS
   * </p><p>
   * This command repairs some fundamental NTFS
   * inconsistencies, resets the NTFS journal file, and
   * schedules an NTFS consistency check for the first boot
   * into Windows.
   * </p><p>
   * This is *not* an equivalent of Windows "chkdsk". It does
   * *not* scan the filesystem for inconsistencies.
   * </p><p>
   * The optional "clearbadsectors" flag clears the list of
   * bad sectors. This is useful after cloning a disk with
   * bad sectors to a new disk.
   * </p><p>
   * Optional arguments are supplied in the final
   * Map&lt;String,Object&gt; parameter, which is a hash of the
   * argument name to its value (cast to Object). Pass an
   * empty Map or null for no optional arguments.
   * </p><p>
   * </p>
   * @since 1.17.9
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
   * <p>
   * resize an NTFS filesystem
   * </p><p>
   * This command resizes an NTFS filesystem, expanding or
   * shrinking it to the size of the underlying device.
   * </p><p>
   * The optional parameters are:
   * </p><p>
   * "size"
   * The new size (in bytes) of the filesystem. If
   * omitted, the filesystem is resized to fit the
   * container (eg. partition).
   * </p><p>
   * "force"
   * If this option is true, then force the resize of the
   * filesystem even if the filesystem is marked as
   * requiring a consistency check.
   * </p><p>
   * After the resize operation, the filesystem is always
   * marked as requiring a consistency check (for
   * safety). You have to boot into Windows to perform
   * this check and clear this condition. If you *don't*
   * set the "force" option then it is not possible to
   * call "g.ntfsresize" multiple times on a single
   * filesystem without booting into Windows between each
   * resize.
   * </p><p>
   * See also ntfsresize(8).
   * </p><p>
   * Optional arguments are supplied in the final
   * Map&lt;String,Object&gt; parameter, which is a hash of the
   * argument name to its value (cast to Object). Pass an
   * empty Map or null for no optional arguments.
   * </p><p>
   * </p>
   * @since 1.3.2
   * @throws LibGuestFSException
   */
  public void ntfsresize (String device, Map<String, Object> optargs)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("ntfsresize: handle is closed");

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

    _ntfsresize (g, device, _optargs_bitmask, size, force);
  }

  public void ntfsresize (String device)
    throws LibGuestFSException
  {
    ntfsresize (device, null);
  }

  public void ntfsresize_opts (String device, Map<String, Object> optargs)
    throws LibGuestFSException
  {
    ntfsresize (device, optargs);
  }

  public void ntfsresize_opts (String device)
    throws LibGuestFSException
  {
    ntfsresize (device, null);
  }

  private native void _ntfsresize (long g, String device, long _optargs_bitmask, long size, boolean force)
    throws LibGuestFSException;

  /**
   * <p>
   * resize an NTFS filesystem (with size)
   * </p><p>
   * This command is the same as "g.ntfsresize" except that
   * it allows you to specify the new size (in bytes)
   * explicitly.
   * </p><p>
   * </p>
   * @since 1.3.14
   * @deprecated In new code, use {@link #ntfsresize} instead
   * @throws LibGuestFSException
   */
  @Deprecated public void ntfsresize_size (String device, long size)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("ntfsresize_size: handle is closed");

    _ntfsresize_size (g, device, size);
  }

  private native void _ntfsresize_size (long g, String device, long size)
    throws LibGuestFSException;

  /**
   * <p>
   * parse the environment and set handle flags accordingly
   * </p><p>
   * Parse the program's environment and set flags in the
   * handle accordingly. For example if "LIBGUESTFS_DEBUG=1"
   * then the 'verbose' flag is set in the handle.
   * </p><p>
   * *Most programs do not need to call this*. It is done
   * implicitly when you call "g.create".
   * </p><p>
   * See "ENVIRONMENT VARIABLES" in guestfs(3) for a list of
   * environment variables that can affect libguestfs
   * handles. See also "guestfs_create_flags" in guestfs(3),
   * and "g.parse_environment_list".
   * </p><p>
   * </p>
   * @since 1.19.53
   * @throws LibGuestFSException
   */
  public void parse_environment ()
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("parse_environment: handle is closed");

    _parse_environment (g);
  }

  private native void _parse_environment (long g)
    throws LibGuestFSException;

  /**
   * <p>
   * parse the environment and set handle flags accordingly
   * </p><p>
   * Parse the list of strings in the argument "environment"
   * and set flags in the handle accordingly. For example if
   * "LIBGUESTFS_DEBUG=1" is a string in the list, then the
   * 'verbose' flag is set in the handle.
   * </p><p>
   * This is the same as "g.parse_environment" except that it
   * parses an explicit list of strings instead of the
   * program's environment.
   * </p><p>
   * </p>
   * @since 1.19.53
   * @throws LibGuestFSException
   */
  public void parse_environment_list (String[] environment)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("parse_environment_list: handle is closed");

    _parse_environment_list (g, environment);
  }

  private native void _parse_environment_list (long g, String[] environment)
    throws LibGuestFSException;

  /**
   * <p>
   * add a partition to the device
   * </p><p>
   * This command adds a partition to "device". If there is
   * no partition table on the device, call "g.part_init"
   * first.
   * </p><p>
   * The "prlogex" parameter is the type of partition.
   * Normally you should pass "p" or "primary" here, but MBR
   * partition tables also support "l" (or "logical") and "e"
   * (or "extended") partition types.
   * </p><p>
   * "startsect" and "endsect" are the start and end of the
   * partition in *sectors*. "endsect" may be negative, which
   * means it counts backwards from the end of the disk (-1
   * is the last sector).
   * </p><p>
   * Creating a partition which covers the whole disk is not
   * so easy. Use "g.part_disk" to do that.
   * </p><p>
   * </p>
   * @since 1.0.78
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
   * <p>
   * delete a partition
   * </p><p>
   * This command deletes the partition numbered "partnum" on
   * "device".
   * </p><p>
   * Note that in the case of MBR partitioning, deleting an
   * extended partition also deletes any logical partitions
   * it contains.
   * </p><p>
   * </p>
   * @since 1.3.2
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
   * <p>
   * partition whole disk with a single primary partition
   * </p><p>
   * This command is simply a combination of "g.part_init"
   * followed by "g.part_add" to create a single primary
   * partition covering the whole disk.
   * </p><p>
   * "parttype" is the partition table type, usually "mbr" or
   * "gpt", but other possible values are described in
   * "g.part_init".
   * </p><p>
   * </p>
   * @since 1.0.78
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
   * <p>
   * return true if a partition is bootable
   * </p><p>
   * This command returns true if the partition "partnum" on
   * "device" has the bootable flag set.
   * </p><p>
   * See also "g.part_set_bootable".
   * </p><p>
   * </p>
   * @since 1.3.2
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
   * <p>
   * get the GUID of a GPT partition
   * </p><p>
   * Return the GUID of numbered GPT partition "partnum".
   * </p><p>
   * </p>
   * @since 1.29.25
   * @throws LibGuestFSException
   */
  public String part_get_gpt_guid (String device, int partnum)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("part_get_gpt_guid: handle is closed");

    return _part_get_gpt_guid (g, device, partnum);
  }

  private native String _part_get_gpt_guid (long g, String device, int partnum)
    throws LibGuestFSException;

  /**
   * <p>
   * get the type GUID of a GPT partition
   * </p><p>
   * Return the type GUID of numbered GPT partition
   * "partnum". For MBR partitions, return an appropriate
   * GUID corresponding to the MBR type. Behaviour is
   * undefined for other partition types.
   * </p><p>
   * </p>
   * @since 1.21.1
   * @throws LibGuestFSException
   */
  public String part_get_gpt_type (String device, int partnum)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("part_get_gpt_type: handle is closed");

    return _part_get_gpt_type (g, device, partnum);
  }

  private native String _part_get_gpt_type (long g, String device, int partnum)
    throws LibGuestFSException;

  /**
   * <p>
   * get the MBR type byte (ID byte) from a partition
   * </p><p>
   * Returns the MBR type byte (also known as the ID byte)
   * from the numbered partition "partnum".
   * </p><p>
   * Note that only MBR (old DOS-style) partitions have type
   * bytes. You will get undefined results for other
   * partition table types (see "g.part_get_parttype").
   * </p><p>
   * </p>
   * @since 1.3.2
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
   * <p>
   * get the MBR partition type
   * </p><p>
   * This returns the partition type of an MBR partition
   * numbered "partnum" on device "device".
   * </p><p>
   * It returns "primary", "logical", or "extended".
   * </p><p>
   * </p>
   * @since 1.29.32
   * @throws LibGuestFSException
   */
  public String part_get_mbr_part_type (String device, int partnum)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("part_get_mbr_part_type: handle is closed");

    return _part_get_mbr_part_type (g, device, partnum);
  }

  private native String _part_get_mbr_part_type (long g, String device, int partnum)
    throws LibGuestFSException;

  /**
   * <p>
   * get partition name
   * </p><p>
   * This gets the partition name on partition numbered
   * "partnum" on device "device". Note that partitions are
   * numbered from 1.
   * </p><p>
   * The partition name can only be read on certain types of
   * partition table. This works on "gpt" but not on "mbr"
   * partitions.
   * </p><p>
   * </p>
   * @since 1.25.33
   * @throws LibGuestFSException
   */
  public String part_get_name (String device, int partnum)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("part_get_name: handle is closed");

    return _part_get_name (g, device, partnum);
  }

  private native String _part_get_name (long g, String device, int partnum)
    throws LibGuestFSException;

  /**
   * <p>
   * get the partition table type
   * </p><p>
   * This command examines the partition table on "device"
   * and returns the partition table type (format) being
   * used.
   * </p><p>
   * Common return values include: "msdos" (a DOS/Windows
   * style MBR partition table), "gpt" (a GPT/EFI-style
   * partition table). Other values are possible, although
   * unusual. See "g.part_init" for a full list.
   * </p><p>
   * </p>
   * @since 1.0.78
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
   * <p>
   * create an empty partition table
   * </p><p>
   * This creates an empty partition table on "device" of one
   * of the partition types listed below. Usually "parttype"
   * should be either "msdos" or "gpt" (for large disks).
   * </p><p>
   * Initially there are no partitions. Following this, you
   * should call "g.part_add" for each partition required.
   * </p><p>
   * Possible values for "parttype" are:
   * </p><p>
   * efi
   * gpt Intel EFI / GPT partition table.
   * </p><p>
   * This is recommended for &gt;= 2 TB partitions that will
   * be accessed from Linux and Intel-based Mac OS X. It
   * also has limited backwards compatibility with the
   * "mbr" format.
   * </p><p>
   * mbr
   * msdos
   * The standard PC "Master Boot Record" (MBR) format
   * used by MS-DOS and Windows. This partition type will
   * only work for device sizes up to 2 TB. For large
   * disks we recommend using "gpt".
   * </p><p>
   * Other partition table types that may work but are not
   * supported include:
   * </p><p>
   * aix AIX disk labels.
   * </p><p>
   * amiga
   * rdb Amiga "Rigid Disk Block" format.
   * </p><p>
   * bsd BSD disk labels.
   * </p><p>
   * dasd
   * DASD, used on IBM mainframes.
   * </p><p>
   * dvh MIPS/SGI volumes.
   * </p><p>
   * mac Old Mac partition format. Modern Macs use "gpt".
   * </p><p>
   * pc98
   * NEC PC-98 format, common in Japan apparently.
   * </p><p>
   * sun Sun disk labels.
   * </p><p>
   * </p>
   * @since 1.0.78
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
   * <p>
   * list partitions on a device
   * </p><p>
   * This command parses the partition table on "device" and
   * returns the list of partitions found.
   * </p><p>
   * The fields in the returned structure are:
   * </p><p>
   * part_num
   * Partition number, counting from 1.
   * </p><p>
   * part_start
   * Start of the partition *in bytes*. To get sectors
   * you have to divide by the device's sector size, see
   * "g.blockdev_getss".
   * </p><p>
   * part_end
   * End of the partition in bytes.
   * </p><p>
   * part_size
   * Size of the partition in bytes.
   * </p><p>
   * </p>
   * @since 1.0.78
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
   * <p>
   * make a partition bootable
   * </p><p>
   * This sets the bootable flag on partition numbered
   * "partnum" on device "device". Note that partitions are
   * numbered from 1.
   * </p><p>
   * The bootable flag is used by some operating systems
   * (notably Windows) to determine which partition to boot
   * from. It is by no means universally recognized.
   * </p><p>
   * </p>
   * @since 1.0.78
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
   * <p>
   * set the GUID of a GPT partition
   * </p><p>
   * Set the GUID of numbered GPT partition "partnum" to
   * "guid". Return an error if the partition table of
   * "device" isn't GPT, or if "guid" is not a valid GUID.
   * </p><p>
   * </p>
   * @since 1.29.25
   * @throws LibGuestFSException
   */
  public void part_set_gpt_guid (String device, int partnum, String guid)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("part_set_gpt_guid: handle is closed");

    _part_set_gpt_guid (g, device, partnum, guid);
  }

  private native void _part_set_gpt_guid (long g, String device, int partnum, String guid)
    throws LibGuestFSException;

  /**
   * <p>
   * set the type GUID of a GPT partition
   * </p><p>
   * Set the type GUID of numbered GPT partition "partnum" to
   * "guid". Return an error if the partition table of
   * "device" isn't GPT, or if "guid" is not a valid GUID.
   * </p><p>
   * See
   * &lt;http://en.wikipedia.org/wiki/GUID_Partition_Table#Parti
   * tion_type_GUIDs&gt; for a useful list of type GUIDs.
   * </p><p>
   * </p>
   * @since 1.21.1
   * @throws LibGuestFSException
   */
  public void part_set_gpt_type (String device, int partnum, String guid)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("part_set_gpt_type: handle is closed");

    _part_set_gpt_type (g, device, partnum, guid);
  }

  private native void _part_set_gpt_type (long g, String device, int partnum, String guid)
    throws LibGuestFSException;

  /**
   * <p>
   * set the MBR type byte (ID byte) of a partition
   * </p><p>
   * Sets the MBR type byte (also known as the ID byte) of
   * the numbered partition "partnum" to "idbyte". Note that
   * the type bytes quoted in most documentation are in fact
   * hexadecimal numbers, but usually documented without any
   * leading "0x" which might be confusing.
   * </p><p>
   * Note that only MBR (old DOS-style) partitions have type
   * bytes. You will get undefined results for other
   * partition table types (see "g.part_get_parttype").
   * </p><p>
   * </p>
   * @since 1.3.2
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
   * <p>
   * set partition name
   * </p><p>
   * This sets the partition name on partition numbered
   * "partnum" on device "device". Note that partitions are
   * numbered from 1.
   * </p><p>
   * The partition name can only be set on certain types of
   * partition table. This works on "gpt" but not on "mbr"
   * partitions.
   * </p><p>
   * </p>
   * @since 1.0.78
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
   * <p>
   * convert partition name to device name
   * </p><p>
   * This function takes a partition name (eg. "/dev/sdb1")
   * and removes the partition number, returning the device
   * name (eg. "/dev/sdb").
   * </p><p>
   * The named partition must exist, for example as a string
   * returned from "g.list_partitions".
   * </p><p>
   * See also "g.part_to_partnum", "g.device_index".
   * </p><p>
   * </p>
   * @since 1.5.15
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
   * <p>
   * convert partition name to partition number
   * </p><p>
   * This function takes a partition name (eg. "/dev/sdb1")
   * and returns the partition number (eg. 1).
   * </p><p>
   * The named partition must exist, for example as a string
   * returned from "g.list_partitions".
   * </p><p>
   * See also "g.part_to_dev".
   * </p><p>
   * </p>
   * @since 1.13.25
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
   * <p>
   * ping the guest daemon
   * </p><p>
   * This is a test probe into the guestfs daemon running
   * inside the libguestfs appliance. Calling this function
   * checks that the daemon responds to the ping message,
   * without affecting the daemon or attached block device(s)
   * in any other way.
   * </p><p>
   * </p>
   * @since 1.0.18
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
   * <p>
   * read part of a file
   * </p><p>
   * This command lets you read part of a file. It reads
   * "count" bytes of the file, starting at "offset", from
   * file "path".
   * </p><p>
   * This may read fewer bytes than requested. For further
   * details see the pread(2) system call.
   * </p><p>
   * See also "g.pwrite", "g.pread_device".
   * </p><p>
   * Because of the message protocol, there is a transfer
   * limit of somewhere between 2MB and 4MB. See "PROTOCOL
   * LIMITS" in guestfs(3).
   * </p><p>
   * </p>
   * @since 1.0.77
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
   * <p>
   * read part of a device
   * </p><p>
   * This command lets you read part of a block device. It
   * reads "count" bytes of "device", starting at "offset".
   * </p><p>
   * This may read fewer bytes than requested. For further
   * details see the pread(2) system call.
   * </p><p>
   * See also "g.pread".
   * </p><p>
   * Because of the message protocol, there is a transfer
   * limit of somewhere between 2MB and 4MB. See "PROTOCOL
   * LIMITS" in guestfs(3).
   * </p><p>
   * </p>
   * @since 1.5.21
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
   * <p>
   * generate a new random UUID for a physical volume
   * </p><p>
   * Generate a new random UUID for the physical volume
   * "device".
   * </p><p>
   * </p>
   * @since 1.19.26
   * @throws LibGuestFSException
   */
  public void pvchange_uuid (String device)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("pvchange_uuid: handle is closed");

    _pvchange_uuid (g, device);
  }

  private native void _pvchange_uuid (long g, String device)
    throws LibGuestFSException;

  /**
   * <p>
   * generate new random UUIDs for all physical volumes
   * </p><p>
   * Generate new random UUIDs for all physical volumes.
   * </p><p>
   * </p>
   * @since 1.19.26
   * @throws LibGuestFSException
   */
  public void pvchange_uuid_all ()
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("pvchange_uuid_all: handle is closed");

    _pvchange_uuid_all (g);
  }

  private native void _pvchange_uuid_all (long g)
    throws LibGuestFSException;

  /**
   * <p>
   * create an LVM physical volume
   * </p><p>
   * This creates an LVM physical volume on the named
   * "device", where "device" should usually be a partition
   * name such as /dev/sda1.
   * </p><p>
   * </p>
   * @since 0.8
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
   * <p>
   * remove an LVM physical volume
   * </p><p>
   * This wipes a physical volume "device" so that LVM will
   * no longer recognise it.
   * </p><p>
   * The implementation uses the "pvremove" command which
   * refuses to wipe physical volumes that contain any volume
   * groups, so you have to remove those first.
   * </p><p>
   * </p>
   * @since 1.0.13
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
   * <p>
   * resize an LVM physical volume
   * </p><p>
   * This resizes (expands or shrinks) an existing LVM
   * physical volume to match the new size of the underlying
   * device.
   * </p><p>
   * </p>
   * @since 1.0.26
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
   * <p>
   * resize an LVM physical volume (with size)
   * </p><p>
   * This command is the same as "g.pvresize" except that it
   * allows you to specify the new size (in bytes)
   * explicitly.
   * </p><p>
   * </p>
   * @since 1.3.14
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
   * <p>
   * list the LVM physical volumes (PVs)
   * </p><p>
   * List all the physical volumes detected. This is the
   * equivalent of the pvs(8) command.
   * </p><p>
   * This returns a list of just the device names that
   * contain PVs (eg. /dev/sda2).
   * </p><p>
   * See also "g.pvs_full".
   * </p><p>
   * </p>
   * @since 0.4
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
   * <p>
   * list the LVM physical volumes (PVs)
   * </p><p>
   * List all the physical volumes detected. This is the
   * equivalent of the pvs(8) command. The "full" version
   * includes all fields.
   * </p><p>
   * </p>
   * @since 0.4
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
   * <p>
   * get the UUID of a physical volume
   * </p><p>
   * This command returns the UUID of the LVM PV "device".
   * </p><p>
   * </p>
   * @since 1.0.87
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
   * <p>
   * write to part of a file
   * </p><p>
   * This command writes to part of a file. It writes the
   * data buffer "content" to the file "path" starting at
   * offset "offset".
   * </p><p>
   * This command implements the pwrite(2) system call, and
   * like that system call it may not write the full data
   * requested. The return value is the number of bytes that
   * were actually written to the file. This could even be 0,
   * although short writes are unlikely for regular files in
   * ordinary circumstances.
   * </p><p>
   * See also "g.pread", "g.pwrite_device".
   * </p><p>
   * Because of the message protocol, there is a transfer
   * limit of somewhere between 2MB and 4MB. See "PROTOCOL
   * LIMITS" in guestfs(3).
   * </p><p>
   * </p>
   * @since 1.3.14
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
   * <p>
   * write to part of a device
   * </p><p>
   * This command writes to part of a device. It writes the
   * data buffer "content" to "device" starting at offset
   * "offset".
   * </p><p>
   * This command implements the pwrite(2) system call, and
   * like that system call it may not write the full data
   * requested (although short writes to disk devices and
   * partitions are probably impossible with standard Linux
   * kernels).
   * </p><p>
   * See also "g.pwrite".
   * </p><p>
   * Because of the message protocol, there is a transfer
   * limit of somewhere between 2MB and 4MB. See "PROTOCOL
   * LIMITS" in guestfs(3).
   * </p><p>
   * </p>
   * @since 1.5.20
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
   * <p>
   * read a file
   * </p><p>
   * This calls returns the contents of the file "path" as a
   * buffer.
   * </p><p>
   * Unlike "g.cat", this function can correctly handle files
   * that contain embedded ASCII NUL characters.
   * </p><p>
   * </p>
   * @since 1.0.63
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
   * <p>
   * read file as lines
   * </p><p>
   * Return the contents of the file named "path".
   * </p><p>
   * The file contents are returned as a list of lines.
   * Trailing "LF" and "CRLF" character sequences are *not*
   * returned.
   * </p><p>
   * Note that this function cannot correctly handle binary
   * files (specifically, files containing "\0" character
   * which is treated as end of string). For those you need
   * to use the "g.read_file" function and split the buffer
   * into lines yourself.
   * </p><p>
   * </p>
   * @since 0.7
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
   * <p>
   * read directories entries
   * </p><p>
   * This returns the list of directory entries in directory
   * "dir".
   * </p><p>
   * All entries in the directory are returned, including "."
   * and "..". The entries are *not* sorted, but returned in
   * the same order as the underlying filesystem.
   * </p><p>
   * Also this call returns basic file type information about
   * each file. The "ftyp" field will contain one of the
   * following characters:
   * </p><p>
   * 'b' Block special
   * </p><p>
   * 'c' Char special
   * </p><p>
   * 'd' Directory
   * </p><p>
   * 'f' FIFO (named pipe)
   * </p><p>
   * 'l' Symbolic link
   * </p><p>
   * 'r' Regular file
   * </p><p>
   * 's' Socket
   * </p><p>
   * 'u' Unknown file type
   * </p><p>
   * '?' The readdir(3) call returned a "d_type" field with
   * an unexpected value
   * </p><p>
   * This function is primarily intended for use by programs.
   * To get a simple list of names, use "g.ls". To get a
   * printable directory for human consumption, use "g.ll".
   * </p><p>
   * Because of the message protocol, there is a transfer
   * limit of somewhere between 2MB and 4MB. See "PROTOCOL
   * LIMITS" in guestfs(3).
   * </p><p>
   * </p>
   * @since 1.0.55
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
   * <p>
   * read the target of a symbolic link
   * </p><p>
   * This command reads the target of a symbolic link.
   * </p><p>
   * </p>
   * @since 1.0.66
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
   * <p>
   * readlink on multiple files
   * </p><p>
   * This call allows you to do a "readlink" operation on
   * multiple files, where all files are in the directory
   * "path". "names" is the list of files from this
   * directory.
   * </p><p>
   * On return you get a list of strings, with a one-to-one
   * correspondence to the "names" list. Each string is the
   * value of the symbolic link.
   * </p><p>
   * If the readlink(2) operation fails on any name, then the
   * corresponding result string is the empty string "".
   * However the whole operation is completed even if there
   * were readlink(2) errors, and so you can call this
   * function with names where you don't know if they are
   * symbolic links already (albeit slightly less efficient).
   * </p><p>
   * This call is intended for programs that want to
   * efficiently list a directory contents without making
   * many round-trips.
   * </p><p>
   * </p>
   * @since 1.0.77
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
   * <p>
   * canonicalized absolute pathname
   * </p><p>
   * Return the canonicalized absolute pathname of "path".
   * The returned path has no ".", ".." or symbolic link path
   * elements.
   * </p><p>
   * </p>
   * @since 1.0.66
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
   * <p>
   * remount a filesystem with different options
   * </p><p>
   * This call allows you to change the "rw"
   * (readonly/read-write) flag on an already mounted
   * filesystem at "mountpoint", converting a readonly
   * filesystem to be read-write, or vice-versa.
   * </p><p>
   * Note that at the moment you must supply the "optional"
   * "rw" parameter. In future we may allow other flags to be
   * adjusted.
   * </p><p>
   * Optional arguments are supplied in the final
   * Map&lt;String,Object&gt; parameter, which is a hash of the
   * argument name to its value (cast to Object). Pass an
   * empty Map or null for no optional arguments.
   * </p><p>
   * </p>
   * @since 1.23.2
   * @throws LibGuestFSException
   */
  public void remount (String mountpoint, Map<String, Object> optargs)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("remount: handle is closed");

    /* Unpack optional args. */
    Object _optobj;
    long _optargs_bitmask = 0;
    boolean rw = false;
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("rw");
    if (_optobj != null) {
      rw = ((Boolean) _optobj).booleanValue();
      _optargs_bitmask |= 1L;
    }

    _remount (g, mountpoint, _optargs_bitmask, rw);
  }

  public void remount (String mountpoint)
    throws LibGuestFSException
  {
    remount (mountpoint, null);
  }

  private native void _remount (long g, String mountpoint, long _optargs_bitmask, boolean rw)
    throws LibGuestFSException;

  /**
   * <p>
   * remove a disk image
   * </p><p>
   * This function is conceptually the opposite of
   * "g.add_drive_opts". It removes the drive that was
   * previously added with label "label".
   * </p><p>
   * Note that in order to remove drives, you have to add
   * them with labels (see the optional "label" argument to
   * "g.add_drive_opts"). If you didn't use a label, then
   * they cannot be removed.
   * </p><p>
   * You can call this function before or after launching the
   * handle. If called after launch, if the backend supports
   * it, we try to hot unplug the drive: see "HOTPLUGGING" in
   * guestfs(3). The disk must not be in use (eg. mounted)
   * when you do this. We try to detect if the disk is in use
   * and stop you from doing this.
   * </p><p>
   * </p>
   * @since 1.19.49
   * @throws LibGuestFSException
   */
  public void remove_drive (String label)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("remove_drive: handle is closed");

    _remove_drive (g, label);
  }

  private native void _remove_drive (long g, String label)
    throws LibGuestFSException;

  /**
   * <p>
   * remove extended attribute of a file or directory
   * </p><p>
   * This call removes the extended attribute named "xattr"
   * of the file "path".
   * </p><p>
   * See also: "g.lremovexattr", attr(5).
   * </p><p>
   * </p>
   * @since 1.0.59
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
   * <p>
   * rename a file on the same filesystem
   * </p><p>
   * Rename a file to a new place on the same filesystem.
   * This is the same as the Linux rename(2) system call. In
   * most cases you are better to use "g.mv" instead.
   * </p><p>
   * </p>
   * @since 1.21.5
   * @throws LibGuestFSException
   */
  public void rename (String oldpath, String newpath)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("rename: handle is closed");

    _rename (g, oldpath, newpath);
  }

  private native void _rename (long g, String oldpath, String newpath)
    throws LibGuestFSException;

  /**
   * <p>
   * resize an ext2, ext3 or ext4 filesystem
   * </p><p>
   * This resizes an ext2, ext3 or ext4 filesystem to match
   * the size of the underlying device.
   * </p><p>
   * See also "RESIZE2FS ERRORS" in guestfs(3).
   * </p><p>
   * </p>
   * @since 1.0.27
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
   * <p>
   * resize an ext2, ext3 or ext4 filesystem to the minimum size
   * </p><p>
   * This command is the same as "g.resize2fs", but the
   * filesystem is resized to its minimum size. This works
   * like the *-M* option to the "resize2fs" command.
   * </p><p>
   * To get the resulting size of the filesystem you should
   * call "g.tune2fs_l" and read the "Block size" and "Block
   * count" values. These two numbers, multiplied together,
   * give the resulting size of the minimal filesystem in
   * bytes.
   * </p><p>
   * See also "RESIZE2FS ERRORS" in guestfs(3).
   * </p><p>
   * </p>
   * @since 1.9.4
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

  /**
   * <p>
   * resize an ext2, ext3 or ext4 filesystem (with size)
   * </p><p>
   * This command is the same as "g.resize2fs" except that it
   * allows you to specify the new size (in bytes)
   * explicitly.
   * </p><p>
   * See also "RESIZE2FS ERRORS" in guestfs(3).
   * </p><p>
   * </p>
   * @since 1.3.14
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
   * <p>
   * remove a file
   * </p><p>
   * Remove the single file "path".
   * </p><p>
   * </p>
   * @since 0.8
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
   * <p>
   * remove a file ignoring errors
   * </p><p>
   * Remove the file "path".
   * </p><p>
   * If the file doesn't exist, that error is ignored. (Other
   * errors, eg. I/O errors or bad paths, are not ignored)
   * </p><p>
   * This call cannot remove directories. Use "g.rmdir" to
   * remove an empty directory, or "g.rm_rf" to remove
   * directories recursively.
   * </p><p>
   * </p>
   * @since 1.19.42
   * @throws LibGuestFSException
   */
  public void rm_f (String path)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("rm_f: handle is closed");

    _rm_f (g, path);
  }

  private native void _rm_f (long g, String path)
    throws LibGuestFSException;

  /**
   * <p>
   * remove a file or directory recursively
   * </p><p>
   * Remove the file or directory "path", recursively
   * removing the contents if its a directory. This is like
   * the "rm -rf" shell command.
   * </p><p>
   * </p>
   * @since 0.8
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
   * <p>
   * remove a directory
   * </p><p>
   * Remove the single directory "path".
   * </p><p>
   * </p>
   * @since 0.8
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
   * <p>
   * remove a mountpoint
   * </p><p>
   * This calls removes a mountpoint that was previously
   * created with "g.mkmountpoint". See "g.mkmountpoint" for
   * full details.
   * </p><p>
   * </p>
   * @since 1.0.62
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
   * <p>
   * synchronize the contents of two directories
   * </p><p>
   * This call may be used to copy or synchronize two
   * directories under the same libguestfs handle. This uses
   * the rsync(1) program which uses a fast algorithm that
   * avoids copying files unnecessarily.
   * </p><p>
   * "src" and "dest" are the source and destination
   * directories. Files are copied from "src" to "dest".
   * </p><p>
   * The optional arguments are:
   * </p><p>
   * "archive"
   * Turns on archive mode. This is the same as passing
   * the *--archive* flag to "rsync".
   * </p><p>
   * "deletedest"
   * Delete files at the destination that do not exist at
   * the source.
   * </p><p>
   * Optional arguments are supplied in the final
   * Map&lt;String,Object&gt; parameter, which is a hash of the
   * argument name to its value (cast to Object). Pass an
   * empty Map or null for no optional arguments.
   * </p><p>
   * </p>
   * @since 1.19.29
   * @throws LibGuestFSException
   */
  public void rsync (String src, String dest, Map<String, Object> optargs)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("rsync: handle is closed");

    /* Unpack optional args. */
    Object _optobj;
    long _optargs_bitmask = 0;
    boolean archive = false;
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("archive");
    if (_optobj != null) {
      archive = ((Boolean) _optobj).booleanValue();
      _optargs_bitmask |= 1L;
    }
    boolean deletedest = false;
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("deletedest");
    if (_optobj != null) {
      deletedest = ((Boolean) _optobj).booleanValue();
      _optargs_bitmask |= 2L;
    }

    _rsync (g, src, dest, _optargs_bitmask, archive, deletedest);
  }

  public void rsync (String src, String dest)
    throws LibGuestFSException
  {
    rsync (src, dest, null);
  }

  private native void _rsync (long g, String src, String dest, long _optargs_bitmask, boolean archive, boolean deletedest)
    throws LibGuestFSException;

  /**
   * <p>
   * synchronize host or remote filesystem with filesystem
   * </p><p>
   * This call may be used to copy or synchronize the
   * filesystem on the host or on a remote computer with the
   * filesystem within libguestfs. This uses the rsync(1)
   * program which uses a fast algorithm that avoids copying
   * files unnecessarily.
   * </p><p>
   * This call only works if the network is enabled. See
   * "g.set_network" or the *--network* option to various
   * tools like guestfish(1).
   * </p><p>
   * Files are copied from the remote server and directory
   * specified by "remote" to the destination directory
   * "dest".
   * </p><p>
   * The format of the remote server string is defined by
   * rsync(1). Note that there is no way to supply a password
   * or passphrase so the target must be set up not to
   * require one.
   * </p><p>
   * The optional arguments are the same as those of
   * "g.rsync".
   * </p><p>
   * Optional arguments are supplied in the final
   * Map&lt;String,Object&gt; parameter, which is a hash of the
   * argument name to its value (cast to Object). Pass an
   * empty Map or null for no optional arguments.
   * </p><p>
   * </p>
   * @since 1.19.29
   * @throws LibGuestFSException
   */
  public void rsync_in (String remote, String dest, Map<String, Object> optargs)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("rsync_in: handle is closed");

    /* Unpack optional args. */
    Object _optobj;
    long _optargs_bitmask = 0;
    boolean archive = false;
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("archive");
    if (_optobj != null) {
      archive = ((Boolean) _optobj).booleanValue();
      _optargs_bitmask |= 1L;
    }
    boolean deletedest = false;
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("deletedest");
    if (_optobj != null) {
      deletedest = ((Boolean) _optobj).booleanValue();
      _optargs_bitmask |= 2L;
    }

    _rsync_in (g, remote, dest, _optargs_bitmask, archive, deletedest);
  }

  public void rsync_in (String remote, String dest)
    throws LibGuestFSException
  {
    rsync_in (remote, dest, null);
  }

  private native void _rsync_in (long g, String remote, String dest, long _optargs_bitmask, boolean archive, boolean deletedest)
    throws LibGuestFSException;

  /**
   * <p>
   * synchronize filesystem with host or remote filesystem
   * </p><p>
   * This call may be used to copy or synchronize the
   * filesystem within libguestfs with a filesystem on the
   * host or on a remote computer. This uses the rsync(1)
   * program which uses a fast algorithm that avoids copying
   * files unnecessarily.
   * </p><p>
   * This call only works if the network is enabled. See
   * "g.set_network" or the *--network* option to various
   * tools like guestfish(1).
   * </p><p>
   * Files are copied from the source directory "src" to the
   * remote server and directory specified by "remote".
   * </p><p>
   * The format of the remote server string is defined by
   * rsync(1). Note that there is no way to supply a password
   * or passphrase so the target must be set up not to
   * require one.
   * </p><p>
   * The optional arguments are the same as those of
   * "g.rsync".
   * </p><p>
   * Globbing does not happen on the "src" parameter. In
   * programs which use the API directly you have to expand
   * wildcards yourself (see "g.glob_expand"). In guestfish
   * you can use the "glob" command (see "glob" in
   * guestfish(1)), for example:
   * </p><p>
   * &gt;&lt;fs&gt; glob rsync-out /* rsync://remote/
   * </p><p>
   * Optional arguments are supplied in the final
   * Map&lt;String,Object&gt; parameter, which is a hash of the
   * argument name to its value (cast to Object). Pass an
   * empty Map or null for no optional arguments.
   * </p><p>
   * </p>
   * @since 1.19.29
   * @throws LibGuestFSException
   */
  public void rsync_out (String src, String remote, Map<String, Object> optargs)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("rsync_out: handle is closed");

    /* Unpack optional args. */
    Object _optobj;
    long _optargs_bitmask = 0;
    boolean archive = false;
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("archive");
    if (_optobj != null) {
      archive = ((Boolean) _optobj).booleanValue();
      _optargs_bitmask |= 1L;
    }
    boolean deletedest = false;
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("deletedest");
    if (_optobj != null) {
      deletedest = ((Boolean) _optobj).booleanValue();
      _optargs_bitmask |= 2L;
    }

    _rsync_out (g, src, remote, _optargs_bitmask, archive, deletedest);
  }

  public void rsync_out (String src, String remote)
    throws LibGuestFSException
  {
    rsync_out (src, remote, null);
  }

  private native void _rsync_out (long g, String src, String remote, long _optargs_bitmask, boolean archive, boolean deletedest)
    throws LibGuestFSException;

  /**
   * <p>
   * scrub (securely wipe) a device
   * </p><p>
   * This command writes patterns over "device" to make data
   * retrieval more difficult.
   * </p><p>
   * It is an interface to the scrub(1) program. See that
   * manual page for more details.
   * </p><p>
   * </p>
   * @since 1.0.52
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
   * <p>
   * scrub (securely wipe) a file
   * </p><p>
   * This command writes patterns over a file to make data
   * retrieval more difficult.
   * </p><p>
   * The file is *removed* after scrubbing.
   * </p><p>
   * It is an interface to the scrub(1) program. See that
   * manual page for more details.
   * </p><p>
   * </p>
   * @since 1.0.52
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
   * <p>
   * scrub (securely wipe) free space
   * </p><p>
   * This command creates the directory "dir" and then fills
   * it with files until the filesystem is full, and scrubs
   * the files as for "g.scrub_file", and deletes them. The
   * intention is to scrub any free space on the partition
   * containing "dir".
   * </p><p>
   * It is an interface to the scrub(1) program. See that
   * manual page for more details.
   * </p><p>
   * </p>
   * @since 1.0.52
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
   * <p>
   * add options to kernel command line
   * </p><p>
   * This function is used to add additional options to the
   * libguestfs appliance kernel command line.
   * </p><p>
   * The default is "NULL" unless overridden by setting
   * "LIBGUESTFS_APPEND" environment variable.
   * </p><p>
   * Setting "append" to "NULL" means *no* additional options
   * are passed (libguestfs always adds a few of its own).
   * </p><p>
   * </p>
   * @since 1.0.26
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
   * <p>
   * set the backend
   * </p><p>
   * Set the method that libguestfs uses to connect to the
   * backend guestfsd daemon.
   * </p><p>
   * See "BACKEND" in guestfs(3).
   * </p><p>
   * </p>
   * @since 1.9.8
   * @deprecated In new code, use {@link #set_backend} instead
   * @throws LibGuestFSException
   */
  @Deprecated public void set_attach_method (String backend)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("set_attach_method: handle is closed");

    _set_attach_method (g, backend);
  }

  private native void _set_attach_method (long g, String backend)
    throws LibGuestFSException;

  /**
   * <p>
   * set autosync mode
   * </p><p>
   * If "autosync" is true, this enables autosync. Libguestfs
   * will make a best effort attempt to make filesystems
   * consistent and synchronized when the handle is closed
   * (also if the program exits without closing handles).
   * </p><p>
   * This is enabled by default (since libguestfs 1.5.24,
   * previously it was disabled by default).
   * </p><p>
   * </p>
   * @since 0.3
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
   * <p>
   * set the backend
   * </p><p>
   * Set the method that libguestfs uses to connect to the
   * backend guestfsd daemon.
   * </p><p>
   * This handle property was previously called the "attach
   * method".
   * </p><p>
   * See "BACKEND" in guestfs(3).
   * </p><p>
   * </p>
   * @since 1.21.26
   * @throws LibGuestFSException
   */
  public void set_backend (String backend)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("set_backend: handle is closed");

    _set_backend (g, backend);
  }

  private native void _set_backend (long g, String backend)
    throws LibGuestFSException;

  /**
   * <p>
   * set a single per-backend settings string
   * </p><p>
   * Append "name=value" to the backend settings string list.
   * However if a string already exists matching "name" or
   * beginning with "name=", then that setting is replaced.
   * </p><p>
   * See "BACKEND" in guestfs(3), "BACKEND SETTINGS" in
   * guestfs(3).
   * </p><p>
   * </p>
   * @since 1.27.2
   * @throws LibGuestFSException
   */
  public void set_backend_setting (String name, String val)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("set_backend_setting: handle is closed");

    _set_backend_setting (g, name, val);
  }

  private native void _set_backend_setting (long g, String name, String val)
    throws LibGuestFSException;

  /**
   * <p>
   * replace per-backend settings strings
   * </p><p>
   * Set a list of zero or more settings which are passed
   * through to the current backend. Each setting is a string
   * which is interpreted in a backend-specific way, or
   * ignored if not understood by the backend.
   * </p><p>
   * The default value is an empty list, unless the
   * environment variable "LIBGUESTFS_BACKEND_SETTINGS" was
   * set when the handle was created. This environment
   * variable contains a colon-separated list of settings.
   * </p><p>
   * This call replaces all backend settings. If you want to
   * replace a single backend setting, see
   * "g.set_backend_setting". If you want to clear a single
   * backend setting, see "g.clear_backend_setting".
   * </p><p>
   * See "BACKEND" in guestfs(3), "BACKEND SETTINGS" in
   * guestfs(3).
   * </p><p>
   * </p>
   * @since 1.25.24
   * @throws LibGuestFSException
   */
  public void set_backend_settings (String[] settings)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("set_backend_settings: handle is closed");

    _set_backend_settings (g, settings);
  }

  private native void _set_backend_settings (long g, String[] settings)
    throws LibGuestFSException;

  /**
   * <p>
   * set the appliance cache directory
   * </p><p>
   * Set the directory used by the handle to store the
   * appliance cache, when using a supermin appliance. The
   * appliance is cached and shared between all handles which
   * have the same effective user ID.
   * </p><p>
   * The environment variables "LIBGUESTFS_CACHEDIR" and
   * "TMPDIR" control the default value: If
   * "LIBGUESTFS_CACHEDIR" is set, then that is the default.
   * Else if "TMPDIR" is set, then that is the default. Else
   * /var/tmp is the default.
   * </p><p>
   * </p>
   * @since 1.19.58
   * @throws LibGuestFSException
   */
  public void set_cachedir (String cachedir)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("set_cachedir: handle is closed");

    _set_cachedir (g, cachedir);
  }

  private native void _set_cachedir (long g, String cachedir)
    throws LibGuestFSException;

  /**
   * <p>
   * enable or disable direct appliance mode
   * </p><p>
   * If the direct appliance mode flag is enabled, then stdin
   * and stdout are passed directly through to the appliance
   * once it is launched.
   * </p><p>
   * One consequence of this is that log messages aren't
   * caught by the library and handled by
   * "g.set_log_message_callback", but go straight to stdout.
   * </p><p>
   * You probably don't want to use this unless you know what
   * you are doing.
   * </p><p>
   * The default is disabled.
   * </p><p>
   * </p>
   * @since 1.0.72
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
   * <p>
   * set ext2 file attributes of a file
   * </p><p>
   * This sets or clears the file attributes "attrs"
   * associated with the inode file.
   * </p><p>
   * "attrs" is a string of characters representing file
   * attributes. See "g.get_e2attrs" for a list of possible
   * attributes. Not all attributes can be changed.
   * </p><p>
   * If optional boolean "clear" is not present or false,
   * then the "attrs" listed are set in the inode.
   * </p><p>
   * If "clear" is true, then the "attrs" listed are cleared
   * in the inode.
   * </p><p>
   * In both cases, other attributes not present in the
   * "attrs" string are left unchanged.
   * </p><p>
   * These attributes are only present when the file is
   * located on an ext2/3/4 filesystem. Using this call on
   * other filesystem types will result in an error.
   * </p><p>
   * Optional arguments are supplied in the final
   * Map&lt;String,Object&gt; parameter, which is a hash of the
   * argument name to its value (cast to Object). Pass an
   * empty Map or null for no optional arguments.
   * </p><p>
   * </p>
   * @since 1.17.31
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
   * <p>
   * set ext2 file generation of a file
   * </p><p>
   * This sets the ext2 file generation of a file.
   * </p><p>
   * See "g.get_e2generation".
   * </p><p>
   * </p>
   * @since 1.17.31
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
   * <p>
   * set the ext2/3/4 filesystem label
   * </p><p>
   * This sets the ext2/3/4 filesystem label of the
   * filesystem on "device" to "label". Filesystem labels are
   * limited to 16 characters.
   * </p><p>
   * You can use either "g.tune2fs_l" or "g.get_e2label" to
   * return the existing label on a filesystem.
   * </p><p>
   * </p>
   * @since 1.0.15
   * @deprecated In new code, use {@link #set_label} instead
   * @throws LibGuestFSException
   */
  @Deprecated public void set_e2label (String device, String label)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("set_e2label: handle is closed");

    _set_e2label (g, device, label);
  }

  private native void _set_e2label (long g, String device, String label)
    throws LibGuestFSException;

  /**
   * <p>
   * set the ext2/3/4 filesystem UUID
   * </p><p>
   * This sets the ext2/3/4 filesystem UUID of the filesystem
   * on "device" to "uuid". The format of the UUID and
   * alternatives such as "clear", "random" and "time" are
   * described in the tune2fs(8) manpage.
   * </p><p>
   * You can use "g.vfs_uuid" to return the existing UUID of
   * a filesystem.
   * </p><p>
   * </p>
   * @since 1.0.15
   * @deprecated In new code, use {@link #set_uuid} instead
   * @throws LibGuestFSException
   */
  @Deprecated public void set_e2uuid (String device, String uuid)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("set_e2uuid: handle is closed");

    _set_e2uuid (g, device, uuid);
  }

  private native void _set_e2uuid (long g, String device, String uuid)
    throws LibGuestFSException;

  /**
   * <p>
   * set the hypervisor binary
   * </p><p>
   * Set the hypervisor binary that we will use. The
   * hypervisor depends on the backend, but is usually the
   * location of the qemu/KVM hypervisor. For the uml
   * backend, it is the location of the "linux" or "vmlinux"
   * binary.
   * </p><p>
   * The default is chosen when the library was compiled by
   * the configure script.
   * </p><p>
   * You can also override this by setting the
   * "LIBGUESTFS_HV" environment variable.
   * </p><p>
   * Note that you should call this function as early as
   * possible after creating the handle. This is because some
   * pre-launch operations depend on testing qemu features
   * (by running "qemu -help"). If the qemu binary changes,
   * we don't retest features, and so you might see
   * inconsistent results. Using the environment variable
   * "LIBGUESTFS_HV" is safest of all since that picks the
   * qemu binary at the same time as the handle is created.
   * </p><p>
   * </p>
   * @since 1.23.17
   * @throws LibGuestFSException
   */
  public void set_hv (String hv)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("set_hv: handle is closed");

    _set_hv (g, hv);
  }

  private native void _set_hv (long g, String hv)
    throws LibGuestFSException;

  /**
   * <p>
   * set filesystem label
   * </p><p>
   * Set the filesystem label on "mountable" to "label".
   * </p><p>
   * Only some filesystem types support labels, and
   * libguestfs supports setting labels on only a subset of
   * these.
   * </p><p>
   * ext2, ext3, ext4
   * Labels are limited to 16 bytes.
   * </p><p>
   * NTFS
   * Labels are limited to 128 unicode characters.
   * </p><p>
   * XFS The label is limited to 12 bytes. The filesystem
   * must not be mounted when trying to set the label.
   * </p><p>
   * btrfs
   * The label is limited to 256 bytes and some
   * characters are not allowed. Setting the label on a
   * btrfs subvolume will set the label on its parent
   * filesystem. The filesystem must not be mounted when
   * trying to set the label.
   * </p><p>
   * To read the label on a filesystem, call "g.vfs_label".
   * </p><p>
   * </p>
   * @since 1.17.9
   * @throws LibGuestFSException
   */
  public void set_label (String mountable, String label)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("set_label: handle is closed");

    _set_label (g, mountable, label);
  }

  private native void _set_label (long g, String mountable, String label)
    throws LibGuestFSException;

  /**
   * <p>
   * pass requested credential back to libvirt
   * </p><p>
   * After requesting the "index"'th credential from the
   * user, call this function to pass the answer back to
   * libvirt.
   * </p><p>
   * See "LIBVIRT AUTHENTICATION" in guestfs(3) for
   * documentation and example code.
   * </p><p>
   * </p>
   * @since 1.19.52
   * @throws LibGuestFSException
   */
  public void set_libvirt_requested_credential (int index, byte[] cred)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("set_libvirt_requested_credential: handle is closed");

    _set_libvirt_requested_credential (g, index, cred);
  }

  private native void _set_libvirt_requested_credential (long g, int index, byte[] cred)
    throws LibGuestFSException;

  /**
   * <p>
   * set libvirt credentials supported by calling program
   * </p><p>
   * Call this function before setting an event handler for
   * "GUESTFS_EVENT_LIBVIRT_AUTH", to supply the list of
   * credential types that the program knows how to process.
   * </p><p>
   * The "creds" list must be a non-empty list of strings.
   * Possible strings are:
   * </p><p>
   * "username"
   * "authname"
   * "language"
   * "cnonce"
   * "passphrase"
   * "echoprompt"
   * "noechoprompt"
   * "realm"
   * "external"
   * </p><p>
   * See libvirt documentation for the meaning of these
   * credential types.
   * </p><p>
   * See "LIBVIRT AUTHENTICATION" in guestfs(3) for
   * documentation and example code.
   * </p><p>
   * </p>
   * @since 1.19.52
   * @throws LibGuestFSException
   */
  public void set_libvirt_supported_credentials (String[] creds)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("set_libvirt_supported_credentials: handle is closed");

    _set_libvirt_supported_credentials (g, creds);
  }

  private native void _set_libvirt_supported_credentials (long g, String[] creds)
    throws LibGuestFSException;

  /**
   * <p>
   * set memory allocated to the hypervisor
   * </p><p>
   * This sets the memory size in megabytes allocated to the
   * hypervisor. This only has any effect if called before
   * "g.launch".
   * </p><p>
   * You can also change this by setting the environment
   * variable "LIBGUESTFS_MEMSIZE" before the handle is
   * created.
   * </p><p>
   * For more information on the architecture of libguestfs,
   * see guestfs(3).
   * </p><p>
   * </p>
   * @since 1.0.55
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
   * <p>
   * set enable network flag
   * </p><p>
   * If "network" is true, then the network is enabled in the
   * libguestfs appliance. The default is false.
   * </p><p>
   * This affects whether commands are able to access the
   * network (see "RUNNING COMMANDS" in guestfs(3)).
   * </p><p>
   * You must call this before calling "g.launch", otherwise
   * it has no effect.
   * </p><p>
   * </p>
   * @since 1.5.4
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
   * <p>
   * set the search path
   * </p><p>
   * Set the path that libguestfs searches for kernel and
   * initrd.img.
   * </p><p>
   * The default is "$libdir/guestfs" unless overridden by
   * setting "LIBGUESTFS_PATH" environment variable.
   * </p><p>
   * Setting "path" to "NULL" restores the default path.
   * </p><p>
   * </p>
   * @since 0.3
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
   * <p>
   * set process group flag
   * </p><p>
   * If "pgroup" is true, child processes are placed into
   * their own process group.
   * </p><p>
   * The practical upshot of this is that signals like
   * "SIGINT" (from users pressing "^C") won't be received by
   * the child process.
   * </p><p>
   * The default for this flag is false, because usually you
   * want "^C" to kill the subprocess. Guestfish sets this
   * flag to true when used interactively, so that "^C" can
   * cancel long-running commands gracefully (see
   * "g.user_cancel").
   * </p><p>
   * </p>
   * @since 1.11.18
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
   * <p>
   * set the program name
   * </p><p>
   * Set the program name. This is an informative string
   * which the main program may optionally set in the handle.
   * </p><p>
   * When the handle is created, the program name in the
   * handle is set to the basename from "argv[0]". If that
   * was not possible, it is set to the empty string (but
   * never "NULL").
   * </p><p>
   * </p>
   * @since 1.21.29
   * @throws LibGuestFSException
   */
  public void set_program (String program)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("set_program: handle is closed");

    _set_program (g, program);
  }

  private native void _set_program (long g, String program)
    throws LibGuestFSException;

  /**
   * <p>
   * set the hypervisor binary (usually qemu)
   * </p><p>
   * Set the hypervisor binary (usually qemu) that we will
   * use.
   * </p><p>
   * The default is chosen when the library was compiled by
   * the configure script.
   * </p><p>
   * You can also override this by setting the
   * "LIBGUESTFS_HV" environment variable.
   * </p><p>
   * Setting "hv" to "NULL" restores the default qemu binary.
   * </p><p>
   * Note that you should call this function as early as
   * possible after creating the handle. This is because some
   * pre-launch operations depend on testing qemu features
   * (by running "qemu -help"). If the qemu binary changes,
   * we don't retest features, and so you might see
   * inconsistent results. Using the environment variable
   * "LIBGUESTFS_HV" is safest of all since that picks the
   * qemu binary at the same time as the handle is created.
   * </p><p>
   * </p>
   * @since 1.0.6
   * @deprecated In new code, use {@link #set_hv} instead
   * @throws LibGuestFSException
   */
  @Deprecated public void set_qemu (String hv)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("set_qemu: handle is closed");

    _set_qemu (g, hv);
  }

  private native void _set_qemu (long g, String hv)
    throws LibGuestFSException;

  /**
   * <p>
   * enable or disable the recovery process
   * </p><p>
   * If this is called with the parameter "false" then
   * "g.launch" does not create a recovery process. The
   * purpose of the recovery process is to stop runaway
   * hypervisor processes in the case where the main program
   * aborts abruptly.
   * </p><p>
   * This only has any effect if called before "g.launch",
   * and the default is true.
   * </p><p>
   * About the only time when you would want to disable this
   * is if the main process will fork itself into the
   * background ("daemonize" itself). In this case the
   * recovery process thinks that the main program has
   * disappeared and so kills the hypervisor, which is not
   * very helpful.
   * </p><p>
   * </p>
   * @since 1.0.77
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
   * <p>
   * set SELinux enabled or disabled at appliance boot
   * </p><p>
   * This sets the selinux flag that is passed to the
   * appliance at boot time. The default is "selinux=0"
   * (disabled).
   * </p><p>
   * Note that if SELinux is enabled, it is always in
   * Permissive mode ("enforcing=0").
   * </p><p>
   * For more information on the architecture of libguestfs,
   * see guestfs(3).
   * </p><p>
   * </p>
   * @since 1.0.67
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
   * <p>
   * set number of virtual CPUs in appliance
   * </p><p>
   * Change the number of virtual CPUs assigned to the
   * appliance. The default is 1. Increasing this may improve
   * performance, though often it has no effect.
   * </p><p>
   * This function must be called before "g.launch".
   * </p><p>
   * </p>
   * @since 1.13.15
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
   * <p>
   * set the temporary directory
   * </p><p>
   * Set the directory used by the handle to store temporary
   * files.
   * </p><p>
   * The environment variables "LIBGUESTFS_TMPDIR" and
   * "TMPDIR" control the default value: If
   * "LIBGUESTFS_TMPDIR" is set, then that is the default.
   * Else if "TMPDIR" is set, then that is the default. Else
   * /tmp is the default.
   * </p><p>
   * </p>
   * @since 1.19.58
   * @throws LibGuestFSException
   */
  public void set_tmpdir (String tmpdir)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("set_tmpdir: handle is closed");

    _set_tmpdir (g, tmpdir);
  }

  private native void _set_tmpdir (long g, String tmpdir)
    throws LibGuestFSException;

  /**
   * <p>
   * enable or disable command traces
   * </p><p>
   * If the command trace flag is set to 1, then libguestfs
   * calls, parameters and return values are traced.
   * </p><p>
   * If you want to trace C API calls into libguestfs (and
   * other libraries) then possibly a better way is to use
   * the external ltrace(1) command.
   * </p><p>
   * Command traces are disabled unless the environment
   * variable "LIBGUESTFS_TRACE" is defined and set to 1.
   * </p><p>
   * Trace messages are normally sent to "stderr", unless you
   * register a callback to send them somewhere else (see
   * "g.set_event_callback").
   * </p><p>
   * </p>
   * @since 1.0.69
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
   * <p>
   * set the filesystem UUID
   * </p><p>
   * Set the filesystem UUID on "device" to "uuid".
   * </p><p>
   * Only some filesystem types support setting UUIDs.
   * </p><p>
   * To read the UUID on a filesystem, call "g.vfs_uuid".
   * </p><p>
   * </p>
   * @since 1.23.10
   * @throws LibGuestFSException
   */
  public void set_uuid (String device, String uuid)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("set_uuid: handle is closed");

    _set_uuid (g, device, uuid);
  }

  private native void _set_uuid (long g, String device, String uuid)
    throws LibGuestFSException;

  /**
   * <p>
   * set verbose mode
   * </p><p>
   * If "verbose" is true, this turns on verbose messages.
   * </p><p>
   * Verbose messages are disabled unless the environment
   * variable "LIBGUESTFS_DEBUG" is defined and set to 1.
   * </p><p>
   * Verbose messages are normally sent to "stderr", unless
   * you register a callback to send them somewhere else (see
   * "g.set_event_callback").
   * </p><p>
   * </p>
   * @since 0.3
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
   * <p>
   * set SELinux security context
   * </p><p>
   * This sets the SELinux security context of the daemon to
   * the string "context".
   * </p><p>
   * See the documentation about SELINUX in guestfs(3).
   * </p><p>
   * </p>
   * @since 1.0.67
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
   * <p>
   * set extended attribute of a file or directory
   * </p><p>
   * This call sets the extended attribute named "xattr" of
   * the file "path" to the value "val" (of length "vallen").
   * The value is arbitrary 8 bit data.
   * </p><p>
   * See also: "g.lsetxattr", attr(5).
   * </p><p>
   * </p>
   * @since 1.0.59
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
   * <p>
   * create partitions on a block device
   * </p><p>
   * This is a direct interface to the sfdisk(8) program for
   * creating partitions on block devices.
   * </p><p>
   * "device" should be a block device, for example /dev/sda.
   * </p><p>
   * "cyls", "heads" and "sectors" are the number of
   * cylinders, heads and sectors on the device, which are
   * passed directly to sfdisk as the *-C*, *-H* and *-S*
   * parameters. If you pass 0 for any of these, then the
   * corresponding parameter is omitted. Usually for 'large'
   * disks, you can just pass 0 for these, but for small
   * (floppy-sized) disks, sfdisk (or rather, the kernel)
   * cannot work out the right geometry and you will need to
   * tell it.
   * </p><p>
   * "lines" is a list of lines that we feed to "sfdisk". For
   * more information refer to the sfdisk(8) manpage.
   * </p><p>
   * To create a single partition occupying the whole disk,
   * you would pass "lines" as a single element list, when
   * the single element being the string "," (comma).
   * </p><p>
   * See also: "g.sfdisk_l", "g.sfdisk_N", "g.part_init"
   * </p><p>
   * </p>
   * @since 0.8
   * @deprecated In new code, use {@link #part_add} instead
   * @throws LibGuestFSException
   */
  @Deprecated public void sfdisk (String device, int cyls, int heads, int sectors, String[] lines)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("sfdisk: handle is closed");

    _sfdisk (g, device, cyls, heads, sectors, lines);
  }

  private native void _sfdisk (long g, String device, int cyls, int heads, int sectors, String[] lines)
    throws LibGuestFSException;

  /**
   * <p>
   * create partitions on a block device
   * </p><p>
   * This is a simplified interface to the "g.sfdisk"
   * command, where partition sizes are specified in
   * megabytes only (rounded to the nearest cylinder) and you
   * don't need to specify the cyls, heads and sectors
   * parameters which were rarely if ever used anyway.
   * </p><p>
   * See also: "g.sfdisk", the sfdisk(8) manpage and
   * "g.part_disk"
   * </p><p>
   * </p>
   * @since 1.0.55
   * @deprecated In new code, use {@link #part_add} instead
   * @throws LibGuestFSException
   */
  @Deprecated public void sfdiskM (String device, String[] lines)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("sfdiskM: handle is closed");

    _sfdiskM (g, device, lines);
  }

  private native void _sfdiskM (long g, String device, String[] lines)
    throws LibGuestFSException;

  /**
   * <p>
   * modify a single partition on a block device
   * </p><p>
   * This runs sfdisk(8) option to modify just the single
   * partition "n" (note: "n" counts from 1).
   * </p><p>
   * For other parameters, see "g.sfdisk". You should usually
   * pass 0 for the cyls/heads/sectors parameters.
   * </p><p>
   * See also: "g.part_add"
   * </p><p>
   * </p>
   * @since 1.0.26
   * @deprecated In new code, use {@link #part_add} instead
   * @throws LibGuestFSException
   */
  @Deprecated public void sfdisk_N (String device, int partnum, int cyls, int heads, int sectors, String line)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("sfdisk_N: handle is closed");

    _sfdisk_N (g, device, partnum, cyls, heads, sectors, line);
  }

  private native void _sfdisk_N (long g, String device, int partnum, int cyls, int heads, int sectors, String line)
    throws LibGuestFSException;

  /**
   * <p>
   * display the disk geometry from the partition table
   * </p><p>
   * This displays the disk geometry of "device" read from
   * the partition table. Especially in the case where the
   * underlying block device has been resized, this can be
   * different from the kernel's idea of the geometry (see
   * "g.sfdisk_kernel_geometry").
   * </p><p>
   * The result is in human-readable format, and not designed
   * to be parsed.
   * </p><p>
   * </p>
   * @since 1.0.26
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
   * <p>
   * display the kernel geometry
   * </p><p>
   * This displays the kernel's idea of the geometry of
   * "device".
   * </p><p>
   * The result is in human-readable format, and not designed
   * to be parsed.
   * </p><p>
   * </p>
   * @since 1.0.26
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
   * <p>
   * display the partition table
   * </p><p>
   * This displays the partition table on "device", in the
   * human-readable output of the sfdisk(8) command. It is
   * not intended to be parsed.
   * </p><p>
   * See also: "g.part_list"
   * </p><p>
   * </p>
   * @since 1.0.26
   * @deprecated In new code, use {@link #part_list} instead
   * @throws LibGuestFSException
   */
  @Deprecated public String sfdisk_l (String device)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("sfdisk_l: handle is closed");

    return _sfdisk_l (g, device);
  }

  private native String _sfdisk_l (long g, String device)
    throws LibGuestFSException;

  /**
   * <p>
   * run a command via the shell
   * </p><p>
   * This call runs a command from the guest filesystem via
   * the guest's /bin/sh.
   * </p><p>
   * This is like "g.command", but passes the command to:
   * </p><p>
   * /bin/sh -c "command"
   * </p><p>
   * Depending on the guest's shell, this usually results in
   * wildcards being expanded, shell expressions being
   * interpolated and so on.
   * </p><p>
   * All the provisos about "g.command" apply to this call.
   * </p><p>
   * </p>
   * @since 1.0.50
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
   * <p>
   * run a command via the shell returning lines
   * </p><p>
   * This is the same as "g.sh", but splits the result into a
   * list of lines.
   * </p><p>
   * See also: "g.command_lines"
   * </p><p>
   * </p>
   * @since 1.0.50
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
   * <p>
   * shutdown the hypervisor
   * </p><p>
   * This is the opposite of "g.launch". It performs an
   * orderly shutdown of the backend process(es). If the
   * autosync flag is set (which is the default) then the
   * disk image is synchronized.
   * </p><p>
   * If the subprocess exits with an error then this function
   * will return an error, which should *not* be ignored (it
   * may indicate that the disk image could not be written
   * out properly).
   * </p><p>
   * It is safe to call this multiple times. Extra calls are
   * ignored.
   * </p><p>
   * This call does *not* close or free up the handle. You
   * still need to call "g.close" afterwards.
   * </p><p>
   * "g.close" will call this if you don't do it explicitly,
   * but note that any errors are ignored in that case.
   * </p><p>
   * </p>
   * @since 1.19.16
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
   * <p>
   * sleep for some seconds
   * </p><p>
   * Sleep for "secs" seconds.
   * </p><p>
   * </p>
   * @since 1.0.41
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
   * <p>
   * get file information
   * </p><p>
   * Returns file information for the given "path".
   * </p><p>
   * This is the same as the stat(2) system call.
   * </p><p>
   * </p>
   * @since 1.9.2
   * @deprecated In new code, use {@link #statns} instead
   * @throws LibGuestFSException
   */
  @Deprecated public Stat stat (String path)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("stat: handle is closed");

    return _stat (g, path);
  }

  private native Stat _stat (long g, String path)
    throws LibGuestFSException;

  /**
   * <p>
   * get file information
   * </p><p>
   * Returns file information for the given "path".
   * </p><p>
   * This is the same as the stat(2) system call.
   * </p><p>
   * </p>
   * @since 1.27.53
   * @throws LibGuestFSException
   */
  public StatNS statns (String path)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("statns: handle is closed");

    return _statns (g, path);
  }

  private native StatNS _statns (long g, String path)
    throws LibGuestFSException;

  /**
   * <p>
   * get file system statistics
   * </p><p>
   * Returns file system statistics for any mounted file
   * system. "path" should be a file or directory in the
   * mounted file system (typically it is the mount point
   * itself, but it doesn't need to be).
   * </p><p>
   * This is the same as the statvfs(2) system call.
   * </p><p>
   * </p>
   * @since 1.9.2
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
   * <p>
   * print the printable strings in a file
   * </p><p>
   * This runs the strings(1) command on a file and returns
   * the list of printable strings found.
   * </p><p>
   * The "strings" command has, in the past, had problems
   * with parsing untrusted files. These are mitigated in the
   * current version of libguestfs, but see "CVE-2014-8484"
   * in guestfs(3).
   * </p><p>
   * Because of the message protocol, there is a transfer
   * limit of somewhere between 2MB and 4MB. See "PROTOCOL
   * LIMITS" in guestfs(3).
   * </p><p>
   * </p>
   * @since 1.0.22
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
   * <p>
   * print the printable strings in a file
   * </p><p>
   * This is like the "g.strings" command, but allows you to
   * specify the encoding of strings that are looked for in
   * the source file "path".
   * </p><p>
   * Allowed encodings are:
   * </p><p>
   * s   Single 7-bit-byte characters like ASCII and the
   * ASCII-compatible parts of ISO-8859-X (this is what
   * "g.strings" uses).
   * </p><p>
   * S   Single 8-bit-byte characters.
   * </p><p>
   * b   16-bit big endian strings such as those encoded in
   * UTF-16BE or UCS-2BE.
   * </p><p>
   * l (lower case letter L)
   * 16-bit little endian such as UTF-16LE and UCS-2LE.
   * This is useful for examining binaries in Windows
   * guests.
   * </p><p>
   * B   32-bit big endian such as UCS-4BE.
   * </p><p>
   * L   32-bit little endian such as UCS-4LE.
   * </p><p>
   * The returned strings are transcoded to UTF-8.
   * </p><p>
   * The "strings" command has, in the past, had problems
   * with parsing untrusted files. These are mitigated in the
   * current version of libguestfs, but see "CVE-2014-8484"
   * in guestfs(3).
   * </p><p>
   * Because of the message protocol, there is a transfer
   * limit of somewhere between 2MB and 4MB. See "PROTOCOL
   * LIMITS" in guestfs(3).
   * </p><p>
   * </p>
   * @since 1.0.22
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
   * <p>
   * disable swap on device
   * </p><p>
   * This command disables the libguestfs appliance swap
   * device or partition named "device". See
   * "g.swapon_device".
   * </p><p>
   * </p>
   * @since 1.0.66
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
   * <p>
   * disable swap on file
   * </p><p>
   * This command disables the libguestfs appliance swap on
   * file.
   * </p><p>
   * </p>
   * @since 1.0.66
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
   * <p>
   * disable swap on labeled swap partition
   * </p><p>
   * This command disables the libguestfs appliance swap on
   * labeled swap partition.
   * </p><p>
   * </p>
   * @since 1.0.66
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
   * <p>
   * disable swap on swap partition by UUID
   * </p><p>
   * This command disables the libguestfs appliance swap
   * partition with the given UUID.
   * </p><p>
   * </p>
   * @since 1.0.66
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
   * <p>
   * enable swap on device
   * </p><p>
   * This command enables the libguestfs appliance to use the
   * swap device or partition named "device". The increased
   * memory is made available for all commands, for example
   * those run using "g.command" or "g.sh".
   * </p><p>
   * Note that you should not swap to existing guest swap
   * partitions unless you know what you are doing. They may
   * contain hibernation information, or other information
   * that the guest doesn't want you to trash. You also risk
   * leaking information about the host to the guest this
   * way. Instead, attach a new host device to the guest and
   * swap on that.
   * </p><p>
   * </p>
   * @since 1.0.66
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
   * <p>
   * enable swap on file
   * </p><p>
   * This command enables swap to a file. See
   * "g.swapon_device" for other notes.
   * </p><p>
   * </p>
   * @since 1.0.66
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
   * <p>
   * enable swap on labeled swap partition
   * </p><p>
   * This command enables swap to a labeled swap partition.
   * See "g.swapon_device" for other notes.
   * </p><p>
   * </p>
   * @since 1.0.66
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
   * <p>
   * enable swap on swap partition by UUID
   * </p><p>
   * This command enables swap to a swap partition with the
   * given UUID. See "g.swapon_device" for other notes.
   * </p><p>
   * </p>
   * @since 1.0.66
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
   * <p>
   * sync disks, writes are flushed through to the disk image
   * </p><p>
   * This syncs the disk, so that any writes are flushed
   * through to the underlying disk image.
   * </p><p>
   * You should always call this if you have modified a disk
   * image, before closing the handle.
   * </p><p>
   * </p>
   * @since 0.3
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
   * <p>
   * install the SYSLINUX bootloader
   * </p><p>
   * Install the SYSLINUX bootloader on "device".
   * </p><p>
   * The device parameter must be either a whole disk
   * formatted as a FAT filesystem, or a partition formatted
   * as a FAT filesystem. In the latter case, the partition
   * should be marked as "active" ("g.part_set_bootable") and
   * a Master Boot Record must be installed (eg. using
   * "g.pwrite_device") on the first sector of the whole
   * disk. The SYSLINUX package comes with some suitable
   * Master Boot Records. See the syslinux(1) man page for
   * further information.
   * </p><p>
   * The optional arguments are:
   * </p><p>
   * directory
   * Install SYSLINUX in the named subdirectory, instead
   * of in the root directory of the FAT filesystem.
   * </p><p>
   * Additional configuration can be supplied to SYSLINUX by
   * placing a file called syslinux.cfg on the FAT
   * filesystem, either in the root directory, or under
   * directory if that optional argument is being used. For
   * further information about the contents of this file, see
   * syslinux(1).
   * </p><p>
   * See also "g.extlinux".
   * </p><p>
   * Optional arguments are supplied in the final
   * Map&lt;String,Object&gt; parameter, which is a hash of the
   * argument name to its value (cast to Object). Pass an
   * empty Map or null for no optional arguments.
   * </p><p>
   * </p>
   * @since 1.21.27
   * @throws LibGuestFSException
   */
  public void syslinux (String device, Map<String, Object> optargs)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("syslinux: handle is closed");

    /* Unpack optional args. */
    Object _optobj;
    long _optargs_bitmask = 0;
    String directory = "";
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("directory");
    if (_optobj != null) {
      directory = ((String) _optobj);
      _optargs_bitmask |= 1L;
    }

    _syslinux (g, device, _optargs_bitmask, directory);
  }

  public void syslinux (String device)
    throws LibGuestFSException
  {
    syslinux (device, null);
  }

  private native void _syslinux (long g, String device, long _optargs_bitmask, String directory)
    throws LibGuestFSException;

  /**
   * <p>
   * return last 10 lines of a file
   * </p><p>
   * This command returns up to the last 10 lines of a file
   * as a list of strings.
   * </p><p>
   * Because of the message protocol, there is a transfer
   * limit of somewhere between 2MB and 4MB. See "PROTOCOL
   * LIMITS" in guestfs(3).
   * </p><p>
   * </p>
   * @since 1.0.54
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
   * <p>
   * return last N lines of a file
   * </p><p>
   * If the parameter "nrlines" is a positive number, this
   * returns the last "nrlines" lines of the file "path".
   * </p><p>
   * If the parameter "nrlines" is a negative number, this
   * returns lines from the file "path", starting with the
   * "-nrlines"th line.
   * </p><p>
   * If the parameter "nrlines" is zero, this returns an
   * empty list.
   * </p><p>
   * Because of the message protocol, there is a transfer
   * limit of somewhere between 2MB and 4MB. See "PROTOCOL
   * LIMITS" in guestfs(3).
   * </p><p>
   * </p>
   * @since 1.0.54
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
   * <p>
   * unpack tarfile to directory
   * </p><p>
   * This command uploads and unpacks local file "tarfile"
   * into directory.
   * </p><p>
   * The optional "compress" flag controls compression. If
   * not given, then the input should be an uncompressed tar
   * file. Otherwise one of the following strings may be
   * given to select the compression type of the input file:
   * "compress", "gzip", "bzip2", "xz", "lzop". (Note that
   * not all builds of libguestfs will support all of these
   * compression types).
   * </p><p>
   * Optional arguments are supplied in the final
   * Map&lt;String,Object&gt; parameter, which is a hash of the
   * argument name to its value (cast to Object). Pass an
   * empty Map or null for no optional arguments.
   * </p><p>
   * </p>
   * @since 1.0.3
   * @throws LibGuestFSException
   */
  public void tar_in (String tarfile, String directory, Map<String, Object> optargs)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("tar_in: handle is closed");

    /* Unpack optional args. */
    Object _optobj;
    long _optargs_bitmask = 0;
    String compress = "";
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("compress");
    if (_optobj != null) {
      compress = ((String) _optobj);
      _optargs_bitmask |= 1L;
    }

    _tar_in (g, tarfile, directory, _optargs_bitmask, compress);
  }

  public void tar_in (String tarfile, String directory)
    throws LibGuestFSException
  {
    tar_in (tarfile, directory, null);
  }

  public void tar_in_opts (String tarfile, String directory, Map<String, Object> optargs)
    throws LibGuestFSException
  {
    tar_in (tarfile, directory, optargs);
  }

  public void tar_in_opts (String tarfile, String directory)
    throws LibGuestFSException
  {
    tar_in (tarfile, directory, null);
  }

  private native void _tar_in (long g, String tarfile, String directory, long _optargs_bitmask, String compress)
    throws LibGuestFSException;

  /**
   * <p>
   * pack directory into tarfile
   * </p><p>
   * This command packs the contents of directory and
   * downloads it to local file "tarfile".
   * </p><p>
   * The optional "compress" flag controls compression. If
   * not given, then the output will be an uncompressed tar
   * file. Otherwise one of the following strings may be
   * given to select the compression type of the output file:
   * "compress", "gzip", "bzip2", "xz", "lzop". (Note that
   * not all builds of libguestfs will support all of these
   * compression types).
   * </p><p>
   * The other optional arguments are:
   * </p><p>
   * "excludes"
   * A list of wildcards. Files are excluded if they
   * match any of the wildcards.
   * </p><p>
   * "numericowner"
   * If set to true, the output tar file will contain
   * UID/GID numbers instead of user/group names.
   * </p><p>
   * Optional arguments are supplied in the final
   * Map&lt;String,Object&gt; parameter, which is a hash of the
   * argument name to its value (cast to Object). Pass an
   * empty Map or null for no optional arguments.
   * </p><p>
   * </p>
   * @since 1.0.3
   * @throws LibGuestFSException
   */
  public void tar_out (String directory, String tarfile, Map<String, Object> optargs)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("tar_out: handle is closed");

    /* Unpack optional args. */
    Object _optobj;
    long _optargs_bitmask = 0;
    String compress = "";
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("compress");
    if (_optobj != null) {
      compress = ((String) _optobj);
      _optargs_bitmask |= 1L;
    }
    boolean numericowner = false;
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("numericowner");
    if (_optobj != null) {
      numericowner = ((Boolean) _optobj).booleanValue();
      _optargs_bitmask |= 2L;
    }
    String[] excludes = new String[]{};
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("excludes");
    if (_optobj != null) {
      excludes = ((String[]) _optobj);
      _optargs_bitmask |= 4L;
    }

    _tar_out (g, directory, tarfile, _optargs_bitmask, compress, numericowner, excludes);
  }

  public void tar_out (String directory, String tarfile)
    throws LibGuestFSException
  {
    tar_out (directory, tarfile, null);
  }

  public void tar_out_opts (String directory, String tarfile, Map<String, Object> optargs)
    throws LibGuestFSException
  {
    tar_out (directory, tarfile, optargs);
  }

  public void tar_out_opts (String directory, String tarfile)
    throws LibGuestFSException
  {
    tar_out (directory, tarfile, null);
  }

  private native void _tar_out (long g, String directory, String tarfile, long _optargs_bitmask, String compress, boolean numericowner, String[] excludes)
    throws LibGuestFSException;

  /**
   * <p>
   * unpack compressed tarball to directory
   * </p><p>
   * This command uploads and unpacks local file "tarball" (a
   * *gzip compressed* tar file) into directory.
   * </p><p>
   * </p>
   * @since 1.0.3
   * @deprecated In new code, use {@link #tar_in} instead
   * @throws LibGuestFSException
   */
  @Deprecated public void tgz_in (String tarball, String directory)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("tgz_in: handle is closed");

    _tgz_in (g, tarball, directory);
  }

  private native void _tgz_in (long g, String tarball, String directory)
    throws LibGuestFSException;

  /**
   * <p>
   * pack directory into compressed tarball
   * </p><p>
   * This command packs the contents of directory and
   * downloads it to local file "tarball".
   * </p><p>
   * </p>
   * @since 1.0.3
   * @deprecated In new code, use {@link #tar_out} instead
   * @throws LibGuestFSException
   */
  @Deprecated public void tgz_out (String directory, String tarball)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("tgz_out: handle is closed");

    _tgz_out (g, directory, tarball);
  }

  private native void _tgz_out (long g, String directory, String tarball)
    throws LibGuestFSException;

  /**
   * <p>
   * update file timestamps or create a new file
   * </p><p>
   * Touch acts like the touch(1) command. It can be used to
   * update the timestamps on a file, or, if the file does
   * not exist, to create a new zero-length file.
   * </p><p>
   * This command only works on regular files, and will fail
   * on other file types such as directories, symbolic links,
   * block special etc.
   * </p><p>
   * </p>
   * @since 0.3
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
   * <p>
   * truncate a file to zero size
   * </p><p>
   * This command truncates "path" to a zero-length file. The
   * file must exist already.
   * </p><p>
   * </p>
   * @since 1.0.77
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
   * <p>
   * truncate a file to a particular size
   * </p><p>
   * This command truncates "path" to size "size" bytes. The
   * file must exist already.
   * </p><p>
   * If the current file size is less than "size" then the
   * file is extended to the required size with zero bytes.
   * This creates a sparse file (ie. disk blocks are not
   * allocated for the file until you write to it). To create
   * a non-sparse file of zeroes, use "g.fallocate64"
   * instead.
   * </p><p>
   * </p>
   * @since 1.0.77
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
   * <p>
   * adjust ext2/ext3/ext4 filesystem parameters
   * </p><p>
   * This call allows you to adjust various filesystem
   * parameters of an ext2/ext3/ext4 filesystem called
   * "device".
   * </p><p>
   * The optional parameters are:
   * </p><p>
   * "force"
   * Force tune2fs to complete the operation even in the
   * face of errors. This is the same as the tune2fs "-f"
   * option.
   * </p><p>
   * "maxmountcount"
   * Set the number of mounts after which the filesystem
   * is checked by e2fsck(8). If this is 0 then the
   * number of mounts is disregarded. This is the same as
   * the tune2fs "-c" option.
   * </p><p>
   * "mountcount"
   * Set the number of times the filesystem has been
   * mounted. This is the same as the tune2fs "-C"
   * option.
   * </p><p>
   * "errorbehavior"
   * Change the behavior of the kernel code when errors
   * are detected. Possible values currently are:
   * "continue", "remount-ro", "panic". In practice these
   * options don't really make any difference,
   * particularly for write errors.
   * </p><p>
   * This is the same as the tune2fs "-e" option.
   * </p><p>
   * "group"
   * Set the group which can use reserved filesystem
   * blocks. This is the same as the tune2fs "-g" option
   * except that it can only be specified as a number.
   * </p><p>
   * "intervalbetweenchecks"
   * Adjust the maximal time between two filesystem
   * checks (in seconds). If the option is passed as 0
   * then time-dependent checking is disabled.
   * </p><p>
   * This is the same as the tune2fs "-i" option.
   * </p><p>
   * "reservedblockspercentage"
   * Set the percentage of the filesystem which may only
   * be allocated by privileged processes. This is the
   * same as the tune2fs "-m" option.
   * </p><p>
   * "lastmounteddirectory"
   * Set the last mounted directory. This is the same as
   * the tune2fs "-M" option.
   * </p><p>
   * "reservedblockscount" Set the number of reserved
   * filesystem blocks. This is the same as the tune2fs "-r"
   * option.
   * "user"
   * Set the user who can use the reserved filesystem
   * blocks. This is the same as the tune2fs "-u" option
   * except that it can only be specified as a number.
   * </p><p>
   * To get the current values of filesystem parameters, see
   * "g.tune2fs_l". For precise details of how tune2fs works,
   * see the tune2fs(8) man page.
   * </p><p>
   * Optional arguments are supplied in the final
   * Map&lt;String,Object&gt; parameter, which is a hash of the
   * argument name to its value (cast to Object). Pass an
   * empty Map or null for no optional arguments.
   * </p><p>
   * </p>
   * @since 1.15.4
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
   * <p>
   * get ext2/ext3/ext4 superblock details
   * </p><p>
   * This returns the contents of the ext2, ext3 or ext4
   * filesystem superblock on "device".
   * </p><p>
   * It is the same as running "tune2fs -l device". See
   * tune2fs(8) manpage for more details. The list of fields
   * returned isn't clearly defined, and depends on both the
   * version of "tune2fs" that libguestfs was built against,
   * and the filesystem itself.
   * </p><p>
   * </p>
   * @since 1.9.2
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
   * <p>
   * unpack compressed tarball to directory
   * </p><p>
   * This command uploads and unpacks local file "tarball"
   * (an *xz compressed* tar file) into directory.
   * </p><p>
   * </p>
   * @since 1.3.2
   * @deprecated In new code, use {@link #tar_in} instead
   * @throws LibGuestFSException
   */
  @Deprecated public void txz_in (String tarball, String directory)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("txz_in: handle is closed");

    _txz_in (g, tarball, directory);
  }

  private native void _txz_in (long g, String tarball, String directory)
    throws LibGuestFSException;

  /**
   * <p>
   * pack directory into compressed tarball
   * </p><p>
   * This command packs the contents of directory and
   * downloads it to local file "tarball" (as an xz
   * compressed tar archive).
   * </p><p>
   * </p>
   * @since 1.3.2
   * @deprecated In new code, use {@link #tar_out} instead
   * @throws LibGuestFSException
   */
  @Deprecated public void txz_out (String directory, String tarball)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("txz_out: handle is closed");

    _txz_out (g, directory, tarball);
  }

  private native void _txz_out (long g, String directory, String tarball)
    throws LibGuestFSException;

  /**
   * <p>
   * set file mode creation mask (umask)
   * </p><p>
   * This function sets the mask used for creating new files
   * and device nodes to "mask &amp; 0777".
   * </p><p>
   * Typical umask values would be 022 which creates new
   * files with permissions like "-rw-r--r--" or
   * "-rwxr-xr-x", and 002 which creates new files with
   * permissions like "-rw-rw-r--" or "-rwxrwxr-x".
   * </p><p>
   * The default umask is 022. This is important because it
   * means that directories and device nodes will be created
   * with 0644 or 0755 mode even if you specify 0777.
   * </p><p>
   * See also "g.get_umask", umask(2), "g.mknod", "g.mkdir".
   * </p><p>
   * This call returns the previous umask.
   * </p><p>
   * </p>
   * @since 1.0.55
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
   * <p>
   * unmount a filesystem
   * </p><p>
   * This unmounts the given filesystem. The filesystem may
   * be specified either by its mountpoint (path) or the
   * device which contains the filesystem.
   * </p><p>
   * Optional arguments are supplied in the final
   * Map&lt;String,Object&gt; parameter, which is a hash of the
   * argument name to its value (cast to Object). Pass an
   * empty Map or null for no optional arguments.
   * </p><p>
   * </p>
   * @since 0.8
   * @throws LibGuestFSException
   */
  public void umount (String pathordevice, Map<String, Object> optargs)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("umount: handle is closed");

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
    boolean lazyunmount = false;
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("lazyunmount");
    if (_optobj != null) {
      lazyunmount = ((Boolean) _optobj).booleanValue();
      _optargs_bitmask |= 2L;
    }

    _umount (g, pathordevice, _optargs_bitmask, force, lazyunmount);
  }

  public void umount (String pathordevice)
    throws LibGuestFSException
  {
    umount (pathordevice, null);
  }

  public void umount_opts (String pathordevice, Map<String, Object> optargs)
    throws LibGuestFSException
  {
    umount (pathordevice, optargs);
  }

  public void umount_opts (String pathordevice)
    throws LibGuestFSException
  {
    umount (pathordevice, null);
  }

  private native void _umount (long g, String pathordevice, long _optargs_bitmask, boolean force, boolean lazyunmount)
    throws LibGuestFSException;

  /**
   * <p>
   * unmount all filesystems
   * </p><p>
   * This unmounts all mounted filesystems.
   * </p><p>
   * Some internal mounts are not unmounted by this call.
   * </p><p>
   * </p>
   * @since 0.8
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
   * <p>
   * unmount a locally mounted filesystem
   * </p><p>
   * If libguestfs is exporting the filesystem on a local
   * mountpoint, then this unmounts it.
   * </p><p>
   * See "MOUNT LOCAL" in guestfs(3) for full documentation.
   * </p><p>
   * Optional arguments are supplied in the final
   * Map&lt;String,Object&gt; parameter, which is a hash of the
   * argument name to its value (cast to Object). Pass an
   * empty Map or null for no optional arguments.
   * </p><p>
   * </p>
   * @since 1.17.22
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
   * <p>
   * upload a file from the local machine
   * </p><p>
   * Upload local file filename to remotefilename on the
   * filesystem.
   * </p><p>
   * filename can also be a named pipe.
   * </p><p>
   * See also "g.download".
   * </p><p>
   * </p>
   * @since 1.0.2
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
   * <p>
   * upload a file from the local machine with offset
   * </p><p>
   * Upload local file filename to remotefilename on the
   * filesystem.
   * </p><p>
   * remotefilename is overwritten starting at the byte
   * "offset" specified. The intention is to overwrite parts
   * of existing files or devices, although if a non-existent
   * file is specified then it is created with a "hole"
   * before "offset". The size of the data written is
   * implicit in the size of the source filename.
   * </p><p>
   * Note that there is no limit on the amount of data that
   * can be uploaded with this call, unlike with "g.pwrite",
   * and this call always writes the full amount unless an
   * error occurs.
   * </p><p>
   * See also "g.upload", "g.pwrite".
   * </p><p>
   * </p>
   * @since 1.5.17
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
   * <p>
   * cancel the current upload or download operation
   * </p><p>
   * This function cancels the current upload or download
   * operation.
   * </p><p>
   * Unlike most other libguestfs calls, this function is
   * signal safe and thread safe. You can call it from a
   * signal handler or from another thread, without needing
   * to do any locking.
   * </p><p>
   * The transfer that was in progress (if there is one) will
   * stop shortly afterwards, and will return an error. The
   * errno (see "guestfs_last_errno") is set to "EINTR", so
   * you can test for this to find out if the operation was
   * cancelled or failed because of another error.
   * </p><p>
   * No cleanup is performed: for example, if a file was
   * being uploaded then after cancellation there may be a
   * partially uploaded file. It is the caller's
   * responsibility to clean up if necessary.
   * </p><p>
   * There are two common places that you might call
   * "g.user_cancel":
   * </p><p>
   * In an interactive text-based program, you might call it
   * from a "SIGINT" signal handler so that pressing "^C"
   * cancels the current operation. (You also need to call
   * "guestfs_set_pgroup" so that child processes don't
   * receive the "^C" signal).
   * </p><p>
   * In a graphical program, when the main thread is
   * displaying a progress bar with a cancel button, wire up
   * the cancel button to call this function.
   * </p><p>
   * </p>
   * @since 1.11.18
   * @throws LibGuestFSException
   */
  public void user_cancel ()
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("user_cancel: handle is closed");

    _user_cancel (g);
  }

  private native void _user_cancel (long g)
    throws LibGuestFSException;

  /**
   * <p>
   * set timestamp of a file with nanosecond precision
   * </p><p>
   * This command sets the timestamps of a file with
   * nanosecond precision.
   * </p><p>
   * "atsecs, atnsecs" are the last access time (atime) in
   * secs and nanoseconds from the epoch.
   * </p><p>
   * "mtsecs, mtnsecs" are the last modification time (mtime)
   * in secs and nanoseconds from the epoch.
   * </p><p>
   * If the *nsecs field contains the special value -1 then
   * the corresponding timestamp is set to the current time.
   * (The *secs field is ignored in this case).
   * </p><p>
   * If the *nsecs field contains the special value -2 then
   * the corresponding timestamp is left unchanged. (The
   * *secs field is ignored in this case).
   * </p><p>
   * </p>
   * @since 1.0.77
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
   * <p>
   * appliance kernel version
   * </p><p>
   * This returns the kernel version of the appliance, where
   * this is available. This information is only useful for
   * debugging. Nothing in the returned structure is defined
   * by the API.
   * </p><p>
   * </p>
   * @since 1.19.27
   * @throws LibGuestFSException
   */
  public UTSName utsname ()
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("utsname: handle is closed");

    return _utsname (g);
  }

  private native UTSName _utsname (long g)
    throws LibGuestFSException;

  /**
   * <p>
   * get the library version number
   * </p><p>
   * Return the libguestfs version number that the program is
   * linked against.
   * </p><p>
   * Note that because of dynamic linking this is not
   * necessarily the version of libguestfs that you compiled
   * against. You can compile the program, and then at
   * runtime dynamically link against a completely different
   * libguestfs.so library.
   * </p><p>
   * This call was added in version 1.0.58. In previous
   * versions of libguestfs there was no way to get the
   * version number. From C code you can use dynamic linker
   * functions to find out if this symbol exists (if it
   * doesn't, then it's an earlier version).
   * </p><p>
   * The call returns a structure with four elements. The
   * first three ("major", "minor" and "release") are numbers
   * and correspond to the usual version triplet. The fourth
   * element ("extra") is a string and is normally empty, but
   * may be used for distro-specific information.
   * </p><p>
   * To construct the original version string:
   * "$major.$minor.$release$extra"
   * </p><p>
   * See also: "LIBGUESTFS VERSION NUMBERS" in guestfs(3).
   * </p><p>
   * *Note:* Don't use this call to test for availability of
   * features. In enterprise distributions we backport
   * features from later versions into earlier versions,
   * making this an unreliable way to test for features. Use
   * "g.available" or "g.feature_available" instead.
   * </p><p>
   * </p>
   * @since 1.0.58
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
   * <p>
   * get the filesystem label
   * </p><p>
   * This returns the label of the filesystem on "mountable".
   * </p><p>
   * If the filesystem is unlabeled, this returns the empty
   * string.
   * </p><p>
   * To find a filesystem from the label, use
   * "g.findfs_label".
   * </p><p>
   * </p>
   * @since 1.3.18
   * @throws LibGuestFSException
   */
  public String vfs_label (String mountable)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("vfs_label: handle is closed");

    return _vfs_label (g, mountable);
  }

  private native String _vfs_label (long g, String mountable)
    throws LibGuestFSException;

  /**
   * <p>
   * get the Linux VFS type corresponding to a mounted device
   * </p><p>
   * This command gets the filesystem type corresponding to
   * the filesystem on "mountable".
   * </p><p>
   * For most filesystems, the result is the name of the
   * Linux VFS module which would be used to mount this
   * filesystem if you mounted it without specifying the
   * filesystem type. For example a string such as "ext3" or
   * "ntfs".
   * </p><p>
   * </p>
   * @since 1.0.75
   * @throws LibGuestFSException
   */
  public String vfs_type (String mountable)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("vfs_type: handle is closed");

    return _vfs_type (g, mountable);
  }

  private native String _vfs_type (long g, String mountable)
    throws LibGuestFSException;

  /**
   * <p>
   * get the filesystem UUID
   * </p><p>
   * This returns the filesystem UUID of the filesystem on
   * "mountable".
   * </p><p>
   * If the filesystem does not have a UUID, this returns the
   * empty string.
   * </p><p>
   * To find a filesystem from the UUID, use "g.findfs_uuid".
   * </p><p>
   * </p>
   * @since 1.3.18
   * @throws LibGuestFSException
   */
  public String vfs_uuid (String mountable)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("vfs_uuid: handle is closed");

    return _vfs_uuid (g, mountable);
  }

  private native String _vfs_uuid (long g, String mountable)
    throws LibGuestFSException;

  /**
   * <p>
   * activate or deactivate some volume groups
   * </p><p>
   * This command activates or (if "activate" is false)
   * deactivates all logical volumes in the listed volume
   * groups "volgroups".
   * </p><p>
   * This command is the same as running "vgchange -a y|n
   * volgroups..."
   * </p><p>
   * Note that if "volgroups" is an empty list then all
   * volume groups are activated or deactivated.
   * </p><p>
   * </p>
   * @since 1.0.26
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
   * <p>
   * activate or deactivate all volume groups
   * </p><p>
   * This command activates or (if "activate" is false)
   * deactivates all logical volumes in all volume groups.
   * </p><p>
   * This command is the same as running "vgchange -a y|n"
   * </p><p>
   * </p>
   * @since 1.0.26
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
   * <p>
   * generate a new random UUID for a volume group
   * </p><p>
   * Generate a new random UUID for the volume group "vg".
   * </p><p>
   * </p>
   * @since 1.19.26
   * @throws LibGuestFSException
   */
  public void vgchange_uuid (String vg)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("vgchange_uuid: handle is closed");

    _vgchange_uuid (g, vg);
  }

  private native void _vgchange_uuid (long g, String vg)
    throws LibGuestFSException;

  /**
   * <p>
   * generate new random UUIDs for all volume groups
   * </p><p>
   * Generate new random UUIDs for all volume groups.
   * </p><p>
   * </p>
   * @since 1.19.26
   * @throws LibGuestFSException
   */
  public void vgchange_uuid_all ()
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("vgchange_uuid_all: handle is closed");

    _vgchange_uuid_all (g);
  }

  private native void _vgchange_uuid_all (long g)
    throws LibGuestFSException;

  /**
   * <p>
   * create an LVM volume group
   * </p><p>
   * This creates an LVM volume group called "volgroup" from
   * the non-empty list of physical volumes "physvols".
   * </p><p>
   * </p>
   * @since 0.8
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
   * <p>
   * get the LV UUIDs of all LVs in the volume group
   * </p><p>
   * Given a VG called "vgname", this returns the UUIDs of
   * all the logical volumes created in this volume group.
   * </p><p>
   * You can use this along with "g.lvs" and "g.lvuuid" calls
   * to associate logical volumes and volume groups.
   * </p><p>
   * See also "g.vgpvuuids".
   * </p><p>
   * </p>
   * @since 1.0.87
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
   * <p>
   * get volume group metadata
   * </p><p>
   * "vgname" is an LVM volume group. This command examines
   * the volume group and returns its metadata.
   * </p><p>
   * Note that the metadata is an internal structure used by
   * LVM, subject to change at any time, and is provided for
   * information only.
   * </p><p>
   * </p>
   * @since 1.17.20
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
   * <p>
   * get the PV UUIDs containing the volume group
   * </p><p>
   * Given a VG called "vgname", this returns the UUIDs of
   * all the physical volumes that this volume group resides
   * on.
   * </p><p>
   * You can use this along with "g.pvs" and "g.pvuuid" calls
   * to associate physical volumes and volume groups.
   * </p><p>
   * See also "g.vglvuuids".
   * </p><p>
   * </p>
   * @since 1.0.87
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
   * <p>
   * remove an LVM volume group
   * </p><p>
   * Remove an LVM volume group "vgname", (for example "VG").
   * </p><p>
   * This also forcibly removes all logical volumes in the
   * volume group (if any).
   * </p><p>
   * </p>
   * @since 1.0.13
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
   * <p>
   * rename an LVM volume group
   * </p><p>
   * Rename a volume group "volgroup" with the new name
   * "newvolgroup".
   * </p><p>
   * </p>
   * @since 1.0.83
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
   * <p>
   * list the LVM volume groups (VGs)
   * </p><p>
   * List all the volumes groups detected. This is the
   * equivalent of the vgs(8) command.
   * </p><p>
   * This returns a list of just the volume group names that
   * were detected (eg. "VolGroup00").
   * </p><p>
   * See also "g.vgs_full".
   * </p><p>
   * </p>
   * @since 0.4
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
   * <p>
   * list the LVM volume groups (VGs)
   * </p><p>
   * List all the volumes groups detected. This is the
   * equivalent of the vgs(8) command. The "full" version
   * includes all fields.
   * </p><p>
   * </p>
   * @since 0.4
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
   * <p>
   * rescan for LVM physical volumes, volume groups and logical volumes
   * </p><p>
   * This rescans all block devices and rebuilds the list of
   * LVM physical volumes, volume groups and logical volumes.
   * </p><p>
   * </p>
   * @since 1.3.2
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
   * <p>
   * get the UUID of a volume group
   * </p><p>
   * This command returns the UUID of the LVM VG named
   * "vgname".
   * </p><p>
   * </p>
   * @since 1.0.87
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
   * <p>
   * wait until the hypervisor launches (no op)
   * </p><p>
   * This function is a no op.
   * </p><p>
   * In versions of the API &lt; 1.0.71 you had to call this
   * function just after calling "g.launch" to wait for the
   * launch to complete. However this is no longer necessary
   * because "g.launch" now does the waiting.
   * </p><p>
   * If you see any calls to this function in code then you
   * can just remove them, unless you want to retain
   * compatibility with older versions of the API.
   * </p><p>
   * </p>
   * @since 0.3
   * @deprecated In new code, use {@link #launch} instead
   * @throws LibGuestFSException
   */
  @Deprecated public void wait_ready ()
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("wait_ready: handle is closed");

    _wait_ready (g);
  }

  private native void _wait_ready (long g)
    throws LibGuestFSException;

  /**
   * <p>
   * count characters in a file
   * </p><p>
   * This command counts the characters in a file, using the
   * "wc -c" external command.
   * </p><p>
   * </p>
   * @since 1.0.54
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
   * <p>
   * count lines in a file
   * </p><p>
   * This command counts the lines in a file, using the "wc
   * -l" external command.
   * </p><p>
   * </p>
   * @since 1.0.54
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
   * <p>
   * count words in a file
   * </p><p>
   * This command counts the words in a file, using the "wc
   * -w" external command.
   * </p><p>
   * </p>
   * @since 1.0.54
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
   * <p>
   * wipe a filesystem signature from a device
   * </p><p>
   * This command erases filesystem or RAID signatures from
   * the specified "device" to make the filesystem invisible
   * to libblkid.
   * </p><p>
   * This does not erase the filesystem itself nor any other
   * data from the "device".
   * </p><p>
   * Compare with "g.zero" which zeroes the first few blocks
   * of a device.
   * </p><p>
   * </p>
   * @since 1.17.6
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
   * <p>
   * create a new file
   * </p><p>
   * This call creates a file called "path". The content of
   * the file is the string "content" (which can contain any
   * 8 bit data).
   * </p><p>
   * See also "g.write_append".
   * </p><p>
   * </p>
   * @since 1.3.14
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
   * <p>
   * append content to end of file
   * </p><p>
   * This call appends "content" to the end of file "path".
   * If "path" does not exist, then a new file is created.
   * </p><p>
   * See also "g.write".
   * </p><p>
   * </p>
   * @since 1.11.18
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
   * <p>
   * create a file
   * </p><p>
   * This call creates a file called "path". The contents of
   * the file is the string "content" (which can contain any
   * 8 bit data), with length "size".
   * </p><p>
   * As a special case, if "size" is 0 then the length is
   * calculated using "strlen" (so in this case the content
   * cannot contain embedded ASCII NULs).
   * </p><p>
   * *NB.* Owing to a bug, writing content containing ASCII
   * NUL characters does *not* work, even if the length is
   * specified.
   * </p><p>
   * Because of the message protocol, there is a transfer
   * limit of somewhere between 2MB and 4MB. See "PROTOCOL
   * LIMITS" in guestfs(3).
   * </p><p>
   * </p>
   * @since 0.8
   * @deprecated In new code, use {@link #write} instead
   * @throws LibGuestFSException
   */
  @Deprecated public void write_file (String path, String content, int size)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("write_file: handle is closed");

    _write_file (g, path, content, size);
  }

  private native void _write_file (long g, String path, String content, int size)
    throws LibGuestFSException;

  /**
   * <p>
   * change parameters of an XFS filesystem
   * </p><p>
   * Change the parameters of the XFS filesystem on "device".
   * </p><p>
   * Devices that are mounted cannot be modified.
   * Administrators must unmount filesystems before this call
   * can modify parameters.
   * </p><p>
   * Some of the parameters of a mounted filesystem can be
   * examined and modified using the "g.xfs_info" and
   * "g.xfs_growfs" calls.
   * </p><p>
   * Optional arguments are supplied in the final
   * Map&lt;String,Object&gt; parameter, which is a hash of the
   * argument name to its value (cast to Object). Pass an
   * empty Map or null for no optional arguments.
   * </p><p>
   * </p>
   * @since 1.19.33
   * @throws LibGuestFSException
   */
  public void xfs_admin (String device, Map<String, Object> optargs)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("xfs_admin: handle is closed");

    /* Unpack optional args. */
    Object _optobj;
    long _optargs_bitmask = 0;
    boolean extunwritten = false;
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("extunwritten");
    if (_optobj != null) {
      extunwritten = ((Boolean) _optobj).booleanValue();
      _optargs_bitmask |= 1L;
    }
    boolean imgfile = false;
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("imgfile");
    if (_optobj != null) {
      imgfile = ((Boolean) _optobj).booleanValue();
      _optargs_bitmask |= 2L;
    }
    boolean v2log = false;
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("v2log");
    if (_optobj != null) {
      v2log = ((Boolean) _optobj).booleanValue();
      _optargs_bitmask |= 4L;
    }
    boolean projid32bit = false;
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("projid32bit");
    if (_optobj != null) {
      projid32bit = ((Boolean) _optobj).booleanValue();
      _optargs_bitmask |= 8L;
    }
    boolean lazycounter = false;
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("lazycounter");
    if (_optobj != null) {
      lazycounter = ((Boolean) _optobj).booleanValue();
      _optargs_bitmask |= 16L;
    }
    String label = "";
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("label");
    if (_optobj != null) {
      label = ((String) _optobj);
      _optargs_bitmask |= 32L;
    }
    String uuid = "";
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("uuid");
    if (_optobj != null) {
      uuid = ((String) _optobj);
      _optargs_bitmask |= 64L;
    }

    _xfs_admin (g, device, _optargs_bitmask, extunwritten, imgfile, v2log, projid32bit, lazycounter, label, uuid);
  }

  public void xfs_admin (String device)
    throws LibGuestFSException
  {
    xfs_admin (device, null);
  }

  private native void _xfs_admin (long g, String device, long _optargs_bitmask, boolean extunwritten, boolean imgfile, boolean v2log, boolean projid32bit, boolean lazycounter, String label, String uuid)
    throws LibGuestFSException;

  /**
   * <p>
   * expand an existing XFS filesystem
   * </p><p>
   * Grow the XFS filesystem mounted at "path".
   * </p><p>
   * The returned struct contains geometry information.
   * Missing fields are returned as -1 (for numeric fields)
   * or empty string.
   * </p><p>
   * Optional arguments are supplied in the final
   * Map&lt;String,Object&gt; parameter, which is a hash of the
   * argument name to its value (cast to Object). Pass an
   * empty Map or null for no optional arguments.
   * </p><p>
   * </p>
   * @since 1.19.28
   * @throws LibGuestFSException
   */
  public void xfs_growfs (String path, Map<String, Object> optargs)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("xfs_growfs: handle is closed");

    /* Unpack optional args. */
    Object _optobj;
    long _optargs_bitmask = 0;
    boolean datasec = false;
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("datasec");
    if (_optobj != null) {
      datasec = ((Boolean) _optobj).booleanValue();
      _optargs_bitmask |= 1L;
    }
    boolean logsec = false;
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("logsec");
    if (_optobj != null) {
      logsec = ((Boolean) _optobj).booleanValue();
      _optargs_bitmask |= 2L;
    }
    boolean rtsec = false;
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("rtsec");
    if (_optobj != null) {
      rtsec = ((Boolean) _optobj).booleanValue();
      _optargs_bitmask |= 4L;
    }
    long datasize = 0;
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("datasize");
    if (_optobj != null) {
      datasize = ((Long) _optobj).longValue();
      _optargs_bitmask |= 8L;
    }
    long logsize = 0;
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("logsize");
    if (_optobj != null) {
      logsize = ((Long) _optobj).longValue();
      _optargs_bitmask |= 16L;
    }
    long rtsize = 0;
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("rtsize");
    if (_optobj != null) {
      rtsize = ((Long) _optobj).longValue();
      _optargs_bitmask |= 32L;
    }
    long rtextsize = 0;
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("rtextsize");
    if (_optobj != null) {
      rtextsize = ((Long) _optobj).longValue();
      _optargs_bitmask |= 64L;
    }
    int maxpct = 0;
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("maxpct");
    if (_optobj != null) {
      maxpct = ((Integer) _optobj).intValue();
      _optargs_bitmask |= 128L;
    }

    _xfs_growfs (g, path, _optargs_bitmask, datasec, logsec, rtsec, datasize, logsize, rtsize, rtextsize, maxpct);
  }

  public void xfs_growfs (String path)
    throws LibGuestFSException
  {
    xfs_growfs (path, null);
  }

  private native void _xfs_growfs (long g, String path, long _optargs_bitmask, boolean datasec, boolean logsec, boolean rtsec, long datasize, long logsize, long rtsize, long rtextsize, int maxpct)
    throws LibGuestFSException;

  /**
   * <p>
   * get geometry of XFS filesystem
   * </p><p>
   * "pathordevice" is a mounted XFS filesystem or a device
   * containing an XFS filesystem. This command returns the
   * geometry of the filesystem.
   * </p><p>
   * The returned struct contains geometry information.
   * Missing fields are returned as -1 (for numeric fields)
   * or empty string.
   * </p><p>
   * </p>
   * @since 1.19.21
   * @throws LibGuestFSException
   */
  public XFSInfo xfs_info (String pathordevice)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("xfs_info: handle is closed");

    return _xfs_info (g, pathordevice);
  }

  private native XFSInfo _xfs_info (long g, String pathordevice)
    throws LibGuestFSException;

  /**
   * <p>
   * repair an XFS filesystem
   * </p><p>
   * Repair corrupt or damaged XFS filesystem on "device".
   * </p><p>
   * The filesystem is specified using the "device" argument
   * which should be the device name of the disk partition or
   * volume containing the filesystem. If given the name of a
   * block device, "xfs_repair" will attempt to find the raw
   * device associated with the specified block device and
   * will use the raw device instead.
   * </p><p>
   * Regardless, the filesystem to be repaired must be
   * unmounted, otherwise, the resulting filesystem may be
   * inconsistent or corrupt.
   * </p><p>
   * The returned status indicates whether filesystem
   * corruption was detected (returns 1) or was not detected
   * (returns 0).
   * </p><p>
   * Optional arguments are supplied in the final
   * Map&lt;String,Object&gt; parameter, which is a hash of the
   * argument name to its value (cast to Object). Pass an
   * empty Map or null for no optional arguments.
   * </p><p>
   * </p>
   * @since 1.19.36
   * @throws LibGuestFSException
   */
  public int xfs_repair (String device, Map<String, Object> optargs)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("xfs_repair: handle is closed");

    /* Unpack optional args. */
    Object _optobj;
    long _optargs_bitmask = 0;
    boolean forcelogzero = false;
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("forcelogzero");
    if (_optobj != null) {
      forcelogzero = ((Boolean) _optobj).booleanValue();
      _optargs_bitmask |= 1L;
    }
    boolean nomodify = false;
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("nomodify");
    if (_optobj != null) {
      nomodify = ((Boolean) _optobj).booleanValue();
      _optargs_bitmask |= 2L;
    }
    boolean noprefetch = false;
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("noprefetch");
    if (_optobj != null) {
      noprefetch = ((Boolean) _optobj).booleanValue();
      _optargs_bitmask |= 4L;
    }
    boolean forcegeometry = false;
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("forcegeometry");
    if (_optobj != null) {
      forcegeometry = ((Boolean) _optobj).booleanValue();
      _optargs_bitmask |= 8L;
    }
    long maxmem = 0;
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("maxmem");
    if (_optobj != null) {
      maxmem = ((Long) _optobj).longValue();
      _optargs_bitmask |= 16L;
    }
    long ihashsize = 0;
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("ihashsize");
    if (_optobj != null) {
      ihashsize = ((Long) _optobj).longValue();
      _optargs_bitmask |= 32L;
    }
    long bhashsize = 0;
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("bhashsize");
    if (_optobj != null) {
      bhashsize = ((Long) _optobj).longValue();
      _optargs_bitmask |= 64L;
    }
    long agstride = 0;
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("agstride");
    if (_optobj != null) {
      agstride = ((Long) _optobj).longValue();
      _optargs_bitmask |= 128L;
    }
    String logdev = "";
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("logdev");
    if (_optobj != null) {
      logdev = ((String) _optobj);
      _optargs_bitmask |= 256L;
    }
    String rtdev = "";
    _optobj = null;
    if (optargs != null)
      _optobj = optargs.get ("rtdev");
    if (_optobj != null) {
      rtdev = ((String) _optobj);
      _optargs_bitmask |= 512L;
    }

    return _xfs_repair (g, device, _optargs_bitmask, forcelogzero, nomodify, noprefetch, forcegeometry, maxmem, ihashsize, bhashsize, agstride, logdev, rtdev);
  }

  public int xfs_repair (String device)
    throws LibGuestFSException
  {
    return xfs_repair (device, null);
  }

  private native int _xfs_repair (long g, String device, long _optargs_bitmask, boolean forcelogzero, boolean nomodify, boolean noprefetch, boolean forcegeometry, long maxmem, long ihashsize, long bhashsize, long agstride, String logdev, String rtdev)
    throws LibGuestFSException;

  /**
   * <p>
   * return lines matching a pattern
   * </p><p>
   * This calls the external "zegrep" program and returns the
   * matching lines.
   * </p><p>
   * Because of the message protocol, there is a transfer
   * limit of somewhere between 2MB and 4MB. See "PROTOCOL
   * LIMITS" in guestfs(3).
   * </p><p>
   * </p>
   * @since 1.0.66
   * @deprecated In new code, use {@link #grep} instead
   * @throws LibGuestFSException
   */
  @Deprecated public String[] zegrep (String regex, String path)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("zegrep: handle is closed");

    return _zegrep (g, regex, path);
  }

  private native String[] _zegrep (long g, String regex, String path)
    throws LibGuestFSException;

  /**
   * <p>
   * return lines matching a pattern
   * </p><p>
   * This calls the external "zegrep -i" program and returns
   * the matching lines.
   * </p><p>
   * Because of the message protocol, there is a transfer
   * limit of somewhere between 2MB and 4MB. See "PROTOCOL
   * LIMITS" in guestfs(3).
   * </p><p>
   * </p>
   * @since 1.0.66
   * @deprecated In new code, use {@link #grep} instead
   * @throws LibGuestFSException
   */
  @Deprecated public String[] zegrepi (String regex, String path)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("zegrepi: handle is closed");

    return _zegrepi (g, regex, path);
  }

  private native String[] _zegrepi (long g, String regex, String path)
    throws LibGuestFSException;

  /**
   * <p>
   * write zeroes to the device
   * </p><p>
   * This command writes zeroes over the first few blocks of
   * "device".
   * </p><p>
   * How many blocks are zeroed isn't specified (but it's
   * *not* enough to securely wipe the device). It should be
   * sufficient to remove any partition tables, filesystem
   * superblocks and so on.
   * </p><p>
   * If blocks are already zero, then this command avoids
   * writing zeroes. This prevents the underlying device from
   * becoming non-sparse or growing unnecessarily.
   * </p><p>
   * See also: "g.zero_device", "g.scrub_device",
   * "g.is_zero_device"
   * </p><p>
   * </p>
   * @since 1.0.16
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
   * <p>
   * write zeroes to an entire device
   * </p><p>
   * This command writes zeroes over the entire "device".
   * Compare with "g.zero" which just zeroes the first few
   * blocks of a device.
   * </p><p>
   * If blocks are already zero, then this command avoids
   * writing zeroes. This prevents the underlying device from
   * becoming non-sparse or growing unnecessarily.
   * </p><p>
   * </p>
   * @since 1.3.1
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
   * <p>
   * zero free space in a filesystem
   * </p><p>
   * Zero the free space in the filesystem mounted on
   * directory. The filesystem must be mounted read-write.
   * </p><p>
   * The filesystem contents are not affected, but any free
   * space in the filesystem is freed.
   * </p><p>
   * Free space is not "trimmed". You may want to call
   * "g.fstrim" either as an alternative to this, or after
   * calling this, depending on your requirements.
   * </p><p>
   * </p>
   * @since 1.17.18
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
   * <p>
   * zero unused inodes and disk blocks on ext2/3 filesystem
   * </p><p>
   * This runs the *zerofree* program on "device". This
   * program claims to zero unused inodes and disk blocks on
   * an ext2/3 filesystem, thus making it possible to
   * compress the filesystem more effectively.
   * </p><p>
   * You should not run this program if the filesystem is
   * mounted.
   * </p><p>
   * It is possible that using this program can damage the
   * filesystem or data on the filesystem.
   * </p><p>
   * </p>
   * @since 1.0.26
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
   * <p>
   * return lines matching a pattern
   * </p><p>
   * This calls the external "zfgrep" program and returns the
   * matching lines.
   * </p><p>
   * Because of the message protocol, there is a transfer
   * limit of somewhere between 2MB and 4MB. See "PROTOCOL
   * LIMITS" in guestfs(3).
   * </p><p>
   * </p>
   * @since 1.0.66
   * @deprecated In new code, use {@link #grep} instead
   * @throws LibGuestFSException
   */
  @Deprecated public String[] zfgrep (String pattern, String path)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("zfgrep: handle is closed");

    return _zfgrep (g, pattern, path);
  }

  private native String[] _zfgrep (long g, String pattern, String path)
    throws LibGuestFSException;

  /**
   * <p>
   * return lines matching a pattern
   * </p><p>
   * This calls the external "zfgrep -i" program and returns
   * the matching lines.
   * </p><p>
   * Because of the message protocol, there is a transfer
   * limit of somewhere between 2MB and 4MB. See "PROTOCOL
   * LIMITS" in guestfs(3).
   * </p><p>
   * </p>
   * @since 1.0.66
   * @deprecated In new code, use {@link #grep} instead
   * @throws LibGuestFSException
   */
  @Deprecated public String[] zfgrepi (String pattern, String path)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("zfgrepi: handle is closed");

    return _zfgrepi (g, pattern, path);
  }

  private native String[] _zfgrepi (long g, String pattern, String path)
    throws LibGuestFSException;

  /**
   * <p>
   * determine file type inside a compressed file
   * </p><p>
   * This command runs file after first decompressing "path"
   * using "method".
   * </p><p>
   * "method" must be one of "gzip", "compress" or "bzip2".
   * </p><p>
   * Since 1.0.63, use "g.file" instead which can now process
   * compressed files.
   * </p><p>
   * </p>
   * @since 1.0.59
   * @deprecated In new code, use {@link #file} instead
   * @throws LibGuestFSException
   */
  @Deprecated public String zfile (String meth, String path)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("zfile: handle is closed");

    return _zfile (g, meth, path);
  }

  private native String _zfile (long g, String meth, String path)
    throws LibGuestFSException;

  /**
   * <p>
   * return lines matching a pattern
   * </p><p>
   * This calls the external "zgrep" program and returns the
   * matching lines.
   * </p><p>
   * Because of the message protocol, there is a transfer
   * limit of somewhere between 2MB and 4MB. See "PROTOCOL
   * LIMITS" in guestfs(3).
   * </p><p>
   * </p>
   * @since 1.0.66
   * @deprecated In new code, use {@link #grep} instead
   * @throws LibGuestFSException
   */
  @Deprecated public String[] zgrep (String regex, String path)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("zgrep: handle is closed");

    return _zgrep (g, regex, path);
  }

  private native String[] _zgrep (long g, String regex, String path)
    throws LibGuestFSException;

  /**
   * <p>
   * return lines matching a pattern
   * </p><p>
   * This calls the external "zgrep -i" program and returns
   * the matching lines.
   * </p><p>
   * Because of the message protocol, there is a transfer
   * limit of somewhere between 2MB and 4MB. See "PROTOCOL
   * LIMITS" in guestfs(3).
   * </p><p>
   * </p>
   * @since 1.0.66
   * @deprecated In new code, use {@link #grep} instead
   * @throws LibGuestFSException
   */
  @Deprecated public String[] zgrepi (String regex, String path)
    throws LibGuestFSException
  {
    if (g == 0)
      throw new LibGuestFSException ("zgrepi: handle is closed");

    return _zgrepi (g, regex, path);
  }

  private native String[] _zgrepi (long g, String regex, String path)
    throws LibGuestFSException;

}
